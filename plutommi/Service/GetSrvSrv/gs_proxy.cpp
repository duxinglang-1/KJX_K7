
#include "gs_id.h"
#include "gs_base.h"

// We only gen proxy when GS_USE_PROXY is enabled
#ifdef GS_USE_PROXY

struct GS_IBaseProxy;
struct GS_IBaseVT
{
    int (CALLCC *addRef)(GS_IBaseProxy* self);
    int (CALLCC *release)(GS_IBaseProxy* self);
    int (CALLCC *queryInterface)(GS_IBaseProxy* self, int iid, GS_IBase** pptr);
};


struct GS_IBaseProxyBase
{
    static void* operator new (unsigned int size, void *buf)
    {
        return buf;
    }

    void* operator new (unsigned int size)
    {
        gs_assert(0);
        return NULL;
    }

    void operator delete (void* ptr)
    {
        gs_free_proxy(ptr);
    }
};

struct GS_IBaseProxy : public GS_IBaseProxyBase
{
    const GS_IBaseVT*      vt;
    GS_IBase*              obj;
    int                 refCount;

    GS_IBaseProxy(GS_IBase* ptr);
};

int CALLCC GS_IBaseProxy_addRef(GS_IBaseProxy* self)
{
    self->refCount++;
    return self->obj->addRef();
}

int CALLCC GS_IBaseProxy_release(GS_IBaseProxy* self)
{
    GS_IBase* obj= self->obj;
    self->refCount--;
    obj->addRef();
    obj->release();
    if (self->refCount == 0)
    {
        GS_DEL(self);
    }
    int r = obj->release();
    return r;
}

int CALLCC GS_IBaseProxy_queryInterface(GS_IBaseProxy* self, int iid, GS_IBase** pptr)
{
    return self->obj->queryInterface(iid, pptr);
}

const GS_IBaseVT g_GS_IBaseVT = {
    &GS_IBaseProxy_addRef,
    &GS_IBaseProxy_release,
    &GS_IBaseProxy_queryInterface
};

GS_IBaseProxy::GS_IBaseProxy(GS_IBase* ptr)
{
    vt = &g_GS_IBaseVT;
    obj = ptr;
    refCount = 1;
}

GS_IBase* GS_IBaseProxy_bind(GS_IBase* ptr)
{
    GS_IBaseProxy* p = NULL;
    GS_NEW_EX(p, GS_IBaseProxy, (ptr));
    return (GS_IBase*)p;
}


#define GS_GEN_INTERFACE
#include "gs_all_interface_def.h"
#undef GS_GEN_INTERFACE


#define GS_GEN_PROXY_HEADER
#include "gs_all_interface_def.h"
#undef GS_GEN_PROXY_HEADER


#define GS_GEN_PROXY_IMPL
#include "gs_all_interface_def.h"
#undef GS_GEN_PROXY_IMPL


#define GS_GEN_PROXY_VT
#include "gs_all_interface_def.h"
#undef GS_GEN_PROXY_VT

#endif // GS_USE_PROXY

