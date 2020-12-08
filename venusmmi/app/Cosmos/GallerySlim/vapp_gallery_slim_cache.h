#ifndef __VAPP_GALLERY_MAP_H__
#define __VAPP_GALLERY_MAP_H__

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include <memory>
#include "vfx_cpp_base.h"
#include "vapp_gallery_slim_util.h"

//////////////////////////////////////////////////////
//  Cache free index
//////////////////////////////////////////////////////
class VappGalleryCacheFreeIndexItem : public VfxObject
{
public:
    VfxId m_freeIndex;
};

//////////////////////////////////////////////////////
//  class VappGalleryCacheIndex
//////////////////////////////////////////////////////
class VappGalleryCacheIndex : public VfxObject
{
public:
    VappGalleryCacheIndex();
    virtual ~VappGalleryCacheIndex();
    virtual void onInit();
    virtual void onDeinit();
    
public:
    // map key to item, may insert new key
    void setItem(
        VfxId key,                      // [IN] The key to add
        void* item // [IN] The image source to add
    );
    
    // get key mapped item
    void* getItem(VfxId key) const;

    // Get an item by index.
    // index ranges from 0 ~ < getCount()
    void* getItemWithIndex(VfxU32 index) const;
    
    // remove key mapping,
    // note: the associated item is NOT de-allocated
    void removeItem(
        VfxId key                       // [IN] The key to remove
    );

    // Insert a key into free list;
    // The key will be removed
    // when it is popped or removed.
    void pushFreeElement(VfxId freeId);

    // Pop a key from head of free list
    VfxId popFreeElement();

    // remove a freeId from the free list
    void removeFreeElement(VfxId freeId);

    // Return number of image source in the cache
    //
    // RETURNS: Number of image source in the cache
    VfxU32 getCount() const
    {
        return m_cacheDescCount;
    }

    // Check if the cache is empty.
    //
    // RETURNS: Return VFX_TRUE if this is an empty cache.
    VfxBool isEmpty() const
    {
        return m_cacheDescArray == NULL;
    }

// Implementation
private:
    //////////////////////////////////////////////
    //     Index / Mapping 
    //////////////////////////////////////////////
    enum
    {
        MIN_CACHE_DESC_ARRAY_SIZE = 4
    };

    class CacheIndexArrayElement : public VfxBase
    {
    public:
        VfxId   key;
        void* item;
    };

    typedef CacheIndexArrayElement *CacheIndexArrayElementPtr;

    VfxU32 needArraySize(VfxU32 count)
    {
        return (count + MIN_CACHE_DESC_ARRAY_SIZE - 1) / MIN_CACHE_DESC_ARRAY_SIZE * MIN_CACHE_DESC_ARRAY_SIZE;
    }

    void prepareArray(VfxU32 arraySize);
    void createElement(VfxU32 index, VfxId key, void* item);
    void assignElement(VfxU32 index, VfxId key, void* item);
    void copyElements(CacheIndexArrayElementPtr *to, const CacheIndexArrayElementPtr *from, VfxU32 count);

    void cloneWithOtherArray(const CacheIndexArrayElementPtr *m_cacheDescArray, VfxU32 count);
    void assignWithOtherArray(const CacheIndexArrayElementPtr *m_cacheDescArray, VfxU32 count);
        
    void clear();
    
    
    VfxU32 findElement(VfxId key) const;
    void addElement(VfxId key, void* item);
    void removeElement(VfxU32 index);

private:
    // fro key to item
    CacheIndexArrayElementPtr *m_cacheDescArray;
    VfxU32 m_cacheDescCount;

    // Free list management
    VfxObjList m_freeList;
};


//////////////////////////////////////////////////////
//  class VappGalleryCache
//////////////////////////////////////////////////////
template <class CachedType>
class VappGalleryCache : public VfxObject
{
public:
    static const VfxS32 DEFAULT_CACHE_ITEM_NUM = 20;
    static const VfxS32 DEFAULT_HEAP_SIZE = DEFAULT_CACHE_ITEM_NUM * sizeof(CachedType);

private:
	
	//////////////////////////////////////////////
	//	   Item heap management
	//////////////////////////////////////////////
	
	// this class manages wrapped cache items
	// on a ADM heap.
	// They can never be allocated on stack.
	// Cached Items are passed as template parameters
	// since they are of various sizes
	template <class InterCachedType>
	class CacheHeapItem
	{
	private:
		InterCachedType *cacheData;	 // the cache data, must be placed first to ensure alignment
		VfxBool locked; 		// 0 if unlocked, > 0 if locked. unlocked items are stored in free queue.
	
	public:
		CacheHeapItem() :
		  cacheData(NULL), 
		  locked(VFX_FALSE)
		{
			
		}
	
		~CacheHeapItem()
		{
			reset();
			if (cacheData)
			{
			    cacheData->~InterCachedType();
				kal_adm_free(m_heapId, cacheData);
				cacheData = NULL;
			}
		}
		
	public:
		VfxBool isLocked(){
			return locked;
		}
	
		void lock(){
			locked = VFX_TRUE;
		}
	
		void unlock(){
			locked = VFX_FALSE;
		}
	
		void reset(){
			// must unlock before destroy
			VFX_ASSERT(!locked);
			locked = VFX_FALSE;
			if(cacheData)
			{
				memset(cacheData, 0, sizeof(InterCachedType));
			}
		}
	
		InterCachedType* getCacheDataPtr(){
			return cacheData;
		}

		VfxBool allocCacheItem()
		{
			// Must allocate on ADM heap
			void *buf = kal_adm_alloc_noncacheable(m_heapId, sizeof(InterCachedType), NULL);
			cacheData = (InterCachedType*) new (buf) InterCachedType;
			return cacheData != NULL;
		}
	};
	
public:
    typedef CacheHeapItem<CachedType> CacheInfoItemImpl;

// Constructor / Destructor
public:
    VappGalleryCache();
    VappGalleryCache(const VfxU32 heapSize);
    virtual ~VappGalleryCache();
    
// Override
public:
    virtual void onInit();
    virtual void onDeinit();  

// Method
public:

    // Check if an item is cached
    //
    // RETURNS: VFX_TRUE if there is such cache item
    VfxBool hasCache(
        VfxId key                       // [IN] The key to check
    );

    // Retrieves a cache item. Since it is not locked,
    // WARNING: user should DISCARD the returned pointer immediately
    // before exiting local scope. This is because an
    // unlocked cache may be released in subsequent operations.
    //
    // RETURNS: Cache if there is such cache. NULL is returned if not found.
    CachedType* getCacheIfPresent(
        VfxId key                       // [IN] The key to retrieve
    );

    // Lock and retrieve an cache item by key. Does not create new cache if there is 
    // no such cache.
    //
    // RETURNS: cache item of the key. if the cache item does not exist before,
    //          NULL is returned
    CachedType* lockCacheIfPresent(
        VfxId key                      // [IN] The key to lock
    );

    // Lock and retrieve an cache item by key. May create new cache
    //
    // RETURNS: cache item of the key. if the cache item does not exist before,
    //          it is created if possible.
    //          NULL is returned when there is no sufficient
    //          space and cannot free other cache items.
    CachedType* lockCache(
        VfxId key                      // [IN] The key to lock
    );
    
    // Unlocks an cache item. It will remain in the cache,
    // until explicitly deleted or other lock request requires
    // more space.
    //
    // RETURNS: VFX_TRUE if the item is unlocked
    //          VFX_FALSE if the item is already unlocked or does not exist.
    VfxBool unlockCache(
        VfxId key                       // [IN] The key to unlock
    );

    VfxBool releaseCache(
        VfxId key
    );
    
    CacheInfoItemImpl* allocCacheItem()
    {
        CacheInfoItemImpl* newItem = NULL;
        void *itemBuffer = kal_adm_alloc_noncacheable(m_heapId, sizeof(CacheInfoItemImpl), NULL);
        if(NULL != itemBuffer)
        {
            newItem = new (itemBuffer) CacheInfoItemImpl();
        }
        if(newItem && newItem->allocCacheItem())
        {
            return newItem;
        }
    	else if(newItem)
    	{
    	    newItem->~CacheInfoItemImpl();
    		kal_adm_free(m_heapId, newItem);
    		newItem = NULL;
    	}
    	return NULL;
    }

    void deallocCacheItem(CacheInfoItemImpl *item)
    {
        if (item)
        {
            item->~CacheInfoItemImpl();
    		kal_adm_free(m_heapId, item);
    		item = NULL;
    	}
    }
    
    void unlockAll();

private:
    // cache item heap
    static KAL_ADM_ID m_heapId;
    void *m_heapPtr;
    const VfxU32 m_heapSize;
    mmi_id m_appId;
    VappGalleryCacheIndex *m_cacheIndex;
};

template<class CachedType>
KAL_ADM_ID VappGalleryCache<CachedType>::m_heapId = 0;

template<class CachedType>
VappGalleryCache<CachedType>::VappGalleryCache() : 
	m_heapPtr(NULL)
	,m_heapSize(DEFAULT_HEAP_SIZE)
	,m_appId(NULL)
	,m_cacheIndex(NULL)
{
}

template<class CachedType>
VappGalleryCache<CachedType>::VappGalleryCache(const VfxU32 heapSize) : 
	m_heapPtr(NULL)
	,m_heapSize(heapSize)
	,m_appId(NULL)
	,m_cacheIndex(NULL)
{
}

template<class CachedType>
VappGalleryCache<CachedType>::~VappGalleryCache()
{

}

template<class CachedType>
void VappGalleryCache<CachedType>::onInit()
{
    VfxObject::onInit();
    // create index
    VFX_OBJ_CREATE(m_cacheIndex, VappGalleryCacheIndex, this);

    // reserve the heap
    m_appId = findRootAppId(this);
    m_heapPtr = applib_asm_alloc_nc_r(m_appId, m_heapSize);
    VFX_ASSERT(m_heapPtr);
    m_heapId = kal_adm_create(m_heapPtr, m_heapSize, NULL, KAL_TRUE);
}

template<class CachedType>
void VappGalleryCache<CachedType>::onDeinit()
{
    // release all cache items
    // and close index.
    if(m_cacheIndex)
    {
        for(VfxU32 i = 0; i < m_cacheIndex->getCount(); ++i)
        {
            CacheInfoItemImpl *item = (CacheInfoItemImpl*)m_cacheIndex->getItemWithIndex(i);
            VFX_ASSERT(!item->isLocked());
            deallocCacheItem(item);
        }
        VFX_OBJ_CLOSE(m_cacheIndex);
        m_cacheIndex = NULL;
    }
        
    // destroy cache item heap
    if(m_heapId)
    {
        kal_adm_delete(m_heapId);
    }
    m_heapId = NULL;
    applib_asm_free_r(m_appId, m_heapPtr);

    VfxObject::onDeinit();
}

template<class CachedType>
VfxBool VappGalleryCache<CachedType>::hasCache(VfxId key)
{
    CacheInfoItemImpl* existingItem = (CacheInfoItemImpl*)m_cacheIndex->getItem(key);
    if(existingItem)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}

template<class CachedType>
CachedType* VappGalleryCache<CachedType>::getCacheIfPresent(VfxId key)
{
    CacheInfoItemImpl* existingItem = (CacheInfoItemImpl*)m_cacheIndex->getItem(key);
    if(NULL == existingItem)
    {
        return NULL;
    }
    // no locking
    return existingItem->getCacheDataPtr();
}

template<class CachedType>
CachedType* VappGalleryCache<CachedType>::lockCacheIfPresent(VfxId key)
{
    CacheInfoItemImpl* existingItem = (CacheInfoItemImpl*)m_cacheIndex->getItem(key);
    if(NULL == existingItem)
    {
        return NULL;
    }

    if(!existingItem->isLocked())
    {
        // ensure it's not in free list
        m_cacheIndex->removeFreeElement(key);
        // increase lock count
        existingItem->lock();
    }
    return existingItem->getCacheDataPtr();
}

template<class CachedType>
CachedType* VappGalleryCache<CachedType>::lockCache(VfxId key)
{
    // If the key is exist, lock & return it.
    CachedType* cache = lockCacheIfPresent(key);
    if(cache)
    {
        return cache;
    }

    // Allocate a new item and insert index element
    CacheInfoItemImpl* newItem = allocCacheItem();
    if(newItem)
    {
        m_cacheIndex->setItem(key, newItem);
        // lock item
        newItem->lock();
        return newItem->getCacheDataPtr();
    }
    
    // allocation failed, check free list
    VfxId freeId = m_cacheIndex->popFreeElement();
	if(freeId == ~0x00)
	{
		return NULL;
	}

    CacheInfoItemImpl *freeItem = (CacheInfoItemImpl*)m_cacheIndex->getItem(freeId);
    if(freeItem)
    {
        // reset the free item
        freeItem->reset();

        // update index 
        m_cacheIndex->removeItem(freeId);
        m_cacheIndex->setItem(key, freeItem);

        // lock item
        freeItem->lock();
        return freeItem->getCacheDataPtr();
    }
        
    // no free list, failed to lock
    return NULL;
}

template<class CachedType>
VfxBool VappGalleryCache<CachedType>::unlockCache(VfxId key)
{
    CacheInfoItemImpl *item = (CacheInfoItemImpl*)m_cacheIndex->getItem(key);
    if(NULL == item)
    {
        return VFX_FALSE;
    }

    // found, unlock the item
    item->unlock();

    // push into free list if there is
    // no locking
    if(!item->isLocked())
    {
        m_cacheIndex->pushFreeElement(key);
    }
    return VFX_TRUE;
}

template<class CachedType>
VfxBool VappGalleryCache<CachedType>::releaseCache(VfxId key)
{
    CacheInfoItemImpl *item = (CacheInfoItemImpl*)m_cacheIndex->getItem(key);
    if(NULL == item)
    {
        return VFX_FALSE;
    }

    // release cache item
    // and remove from index table
    VFX_ASSERT(!item->isLocked());
    // remove cache item from index
    m_cacheIndex->removeItem(key);
	deallocCacheItem(item);
    return VFX_TRUE;
}

template<typename CachedType>
void VappGalleryCache<CachedType>::unlockAll()
{
    // release all cache items
    // and close index.
    if(m_cacheIndex)
    {
        for(VfxU32 i = 0; i < m_cacheIndex->getCount(); ++i)
        {
            CacheInfoItemImpl *item = (CacheInfoItemImpl*)m_cacheIndex->getItemWithIndex(i);
            item->unlock();
        }
    }
}
#endif