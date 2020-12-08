#include "vapp_gallery_slim_cache.h"

extern "C"
{
#include "MMI_media_app_trc.h"
}

//////////////////////////////////////////////
// VappGalleryListAllocator global
//////////////////////////////////////////////
VfxObject *g_pVappGalleryListAllocatorParentObject = NULL;

//////////////////////////////////////////////
// VappGalleryCacheIndex Implementation
//////////////////////////////////////////////
VappGalleryCacheIndex::VappGalleryCacheIndex() :
    m_cacheDescArray(NULL),
    m_cacheDescCount(0)
{
}

VappGalleryCacheIndex::~VappGalleryCacheIndex()
{
}

void VappGalleryCacheIndex::onInit()
{

}

void VappGalleryCacheIndex::onDeinit()
{
    // empty the index array
    clear();
}

void VappGalleryCacheIndex::setItem(VfxId key, void* item)
{
    // If the key is exist
    VfxU32 index = findElement(key);

    // If the value is null, remove the item
    if (NULL == item)
    {
        removeElement(index);
        return;
    }

    // If the key is exist, assigned with the new value
    if (index < m_cacheDescCount)
    {
        VFX_ASSERT(NULL == m_cacheDescArray[index]->item);
        m_cacheDescArray[index]->item = item;
        return;
    }

    // Add a new element
    addElement(key, item);
}

void* VappGalleryCacheIndex::getItem(VfxId key) const
{
    return getItemWithIndex(findElement(key));
}

void VappGalleryCacheIndex::removeItem(VfxId key)
{
    removeElement(findElement(key));
    // also remove from free list
    removeFreeElement(key);
}

void VappGalleryCacheIndex::pushFreeElement(VfxId freeId)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_CACHE_PUSH_FREE_ELEMENT_D, freeId);

    // check if freeId already exists.
    // if so, do nothing
    for(VfxObjListEntry *e = m_freeList.getHead(); e != NULL; e = e->getNext())
    {
        VappGalleryCacheFreeIndexItem *freeIndexObj = (VappGalleryCacheFreeIndexItem*)e->get();
        if(freeIndexObj && freeIndexObj->m_freeIndex == freeId)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_CACHE_PUSH_FREE_ELEMENT_ALREADY_HAVE_D_DO_NOTHING, freeId);
            return;
        }
    }

    VappGalleryCacheFreeIndexItem *freeIndexObj = NULL;
    VFX_OBJ_CREATE(freeIndexObj, VappGalleryCacheFreeIndexItem, this);
    freeIndexObj->m_freeIndex = freeId;
    m_freeList.append(freeIndexObj);
}

VfxId VappGalleryCacheIndex::popFreeElement()
{
    if(m_freeList.isEmpty())
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_CACHE_POP_FREE_ELEMENT_WHILE_LIST_IS_EMPTY);
        //VFX_ASSERT(0);
		return ~0x0;
    }

    VappGalleryCacheFreeIndexItem *freeIndexObj = (VappGalleryCacheFreeIndexItem*)m_freeList.getFirst();
    if(NULL == freeIndexObj)
    {
        return ~0x0;
    }
    const VfxId ret = freeIndexObj->m_freeIndex;
    m_freeList.removePos(m_freeList.getHead());
    VFX_OBJ_CLOSE(freeIndexObj);
    return ret;
}

void VappGalleryCacheIndex::removeFreeElement(VfxId freeId)
{
    for(VfxObjListEntry *e = m_freeList.getHead(); e != NULL; e = e->getNext())
    {
        VappGalleryCacheFreeIndexItem *freeIndexObj = (VappGalleryCacheFreeIndexItem*)e->get();
        if(freeIndexObj && freeIndexObj->m_freeIndex == freeId)
        {
            m_freeList.removePos(e);
            VFX_OBJ_CLOSE(freeIndexObj);
            return;
        }
    }
}

void VappGalleryCacheIndex::prepareArray(VfxU32 arraySize)
{
    VFX_DEV_ASSERT(m_cacheDescArray == NULL);

    if (arraySize == 0)
    {
        // Do nothing
        return;
    }

    VFX_ALLOC_MEM(m_cacheDescArray, sizeof(CacheIndexArrayElementPtr) * arraySize, this);
    memset(m_cacheDescArray, 0, sizeof(CacheIndexArrayElementPtr) * arraySize);
}

void VappGalleryCacheIndex::createElement(VfxU32 index, VfxId key, void* item)
{
    VFX_DEV_ASSERT(m_cacheDescArray != NULL);

    VFX_ALLOC_NEW(m_cacheDescArray[index], CacheIndexArrayElement, this);
    m_cacheDescArray[index]->key = key;
    m_cacheDescArray[index]->item = item;
}


void VappGalleryCacheIndex::assignElement(VfxU32 index, VfxId key, void* item)
{
    VFX_DEV_ASSERT(m_cacheDescArray != NULL);
    VFX_DEV_ASSERT(m_cacheDescArray[index] != NULL);

    m_cacheDescArray[index]->key = key;
    m_cacheDescArray[index]->item = item;
}

void VappGalleryCacheIndex::copyElements(CacheIndexArrayElementPtr *to, const CacheIndexArrayElementPtr *from, VfxU32 count)
{
    if (count == 0)
    {
        // Do nothing
        return;
    }

    VFX_DEV_ASSERT(to != NULL && from != NULL);
    memcpy(to, from, sizeof(CacheIndexArrayElementPtr) * count);
}


void VappGalleryCacheIndex::cloneWithOtherArray(const CacheIndexArrayElementPtr *imgDescArray, VfxU32 count)
{
    VfxU32 i;
    for (i = 0; i < count; i++)
    {
        const CacheIndexArrayElement *otherElement = imgDescArray[i];
        VFX_DEV_ASSERT(otherElement != NULL);
        createElement(i, otherElement->key, otherElement->item);
    }
}

void VappGalleryCacheIndex::assignWithOtherArray(const CacheIndexArrayElementPtr *imgDescArray, VfxU32 count)
{
    VfxU32 i;
    for (i = 0; i < vfxMin(count, m_cacheDescCount); i++)
    {
        const CacheIndexArrayElement *otherElement = imgDescArray[i];
        VFX_DEV_ASSERT(otherElement != NULL);
        assignElement(i, otherElement->key, otherElement->item);
    }
    for (;i < count; i++)
    {
        const CacheIndexArrayElement *otherElement = imgDescArray[i];
        VFX_DEV_ASSERT(otherElement != NULL);
        createElement(i, otherElement->key, otherElement->item);
    }
    for (;i < m_cacheDescCount; i++)
    {
        VFX_DELETE(m_cacheDescArray[i]);
    }
}

void VappGalleryCacheIndex::clear()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_CACHE_INDEX_CLEAR);

    VfxU32 i;
    for (i = 0; i < m_cacheDescCount; i++)
    {
        // release the index element
        VFX_DELETE(m_cacheDescArray[i]);
    }
    VFX_FREE_MEM(m_cacheDescArray);
    m_cacheDescArray = NULL;
    m_cacheDescCount = 0;
}

VfxU32 VappGalleryCacheIndex::findElement(VfxId key) const
{
    VfxU32 i;
    for (i = 0; i < m_cacheDescCount; i++)
    {
        VFX_DEV_ASSERT(m_cacheDescArray[i] != NULL);
        if (m_cacheDescArray[i]->key == key)
        {
            break;
        }
    }
    return i;
}

void VappGalleryCacheIndex::addElement(VfxId key, void* item)
{
    VfxU32 newIndex = m_cacheDescCount;
    VfxU32 currentArraySize = needArraySize(m_cacheDescCount);
    VfxU32 addedArraySize = needArraySize(m_cacheDescCount + 1);
    VFX_DEV_ASSERT(addedArraySize >= currentArraySize);

    if (addedArraySize != currentArraySize)
    {
        // Backup old array
        CacheIndexArrayElementPtr *oldArray = m_cacheDescArray;

        // Clone array with bigger size
        m_cacheDescArray = NULL;
        prepareArray(addedArraySize);
        copyElements(m_cacheDescArray, oldArray, m_cacheDescCount);

        // Delete old array
        VFX_FREE_MEM(oldArray);
    }

    // Create a new element and assign the
    createElement(newIndex, key, item);

    // Update the data count
    m_cacheDescCount++;
}

void VappGalleryCacheIndex::removeElement(VfxU32 index)
{
    if (index >= m_cacheDescCount)
    {
        // Do nothing
        return;
    }

    // itemPos is must in the range of array
    VFX_DEV_ASSERT(m_cacheDescArray != NULL && m_cacheDescCount != 0);
    VFX_DEV_ASSERT(index < m_cacheDescCount);
    VFX_DEV_ASSERT(m_cacheDescArray[index] != NULL);

    // free the element
    VFX_DELETE(m_cacheDescArray[index]);
    m_cacheDescArray[index] = NULL;

    VfxU32 currentNeedSize = needArraySize(m_cacheDescCount);
    VfxU32 removedNeedSize = needArraySize(m_cacheDescCount - 1);
    VFX_DEV_ASSERT(removedNeedSize <= currentNeedSize);

    // Backup the current array
    CacheIndexArrayElementPtr *oldArray = m_cacheDescArray;

    // Check if need to reduce the array size
    if (currentNeedSize != removedNeedSize)
    {
        m_cacheDescArray = NULL;
        prepareArray(removedNeedSize);
        copyElements(m_cacheDescArray, oldArray, index);
    }

    // Copy elements after index
    if (removedNeedSize - index != 0)
    {
        copyElements(
            m_cacheDescArray + index,
            oldArray + index + 1,
            removedNeedSize - index);
    }

    // Update the data count
    m_cacheDescCount--;

    // Free old array if needed
    if (currentNeedSize != removedNeedSize)
    {
        VFX_FREE_MEM(oldArray);
    }
}

void* VappGalleryCacheIndex::getItemWithIndex(VfxU32 index) const
{
    // The key is not found
    if (index >= m_cacheDescCount)
    {
        return NULL;
    }

    VFX_DEV_ASSERT(m_cacheDescArray != NULL);
    return m_cacheDescArray[index]->item;
}


