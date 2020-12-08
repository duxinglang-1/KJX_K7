
#include "gs_cbase.h"

GS_CBase::~GS_CBase()
{
    gs_destroy_service_callback(this);
}


GS_CBase::GS_CBase(U32 handle)
{
    m_handle = handle;
    refCount = 0;
    gs_create_service_callback(this);
}


S32 CALLCC GS_CBase::addRef()
{
    refCount ++;
    return refCount;
}

S32 CALLCC GS_CBase::release()
{
    //MMI_TRACE(MMI_MRE_TRC_G6, TRC_MMI_GETSRV_CBASE_RELEASE); 
    gs_memory_set_handle(m_handle);
    
    if(refCount == 0) return 0;
    refCount--;
    if (refCount == 0)
    {
        const GS_CBase* _this = this;
        GS_DEL(_this);
        return 0;
    }
    return refCount;
}

S32 CALLCC GS_CBase::queryInterface(S32 iid, GS_IBase** pptr)
{
    if (pptr == NULL) return 0;
    if (iid == IID_GS_IBASE)
    {
        addRef();
        *pptr = BIND_PROXY(GS_IBase, this);
        return 1;
    }
    return 0;
}

void* GS_CBase::operator new (unsigned int size)
{
    gs_assert(0); // should not call this
    return NULL;
}

void* GS_CBase::operator new (unsigned int size, void *buf)
{
    return buf;
}

void GS_CBase::operator delete (void* ptr)
{
    gs_free(ptr);
}

