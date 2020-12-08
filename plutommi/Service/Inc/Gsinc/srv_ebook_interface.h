

#include "gs_id.h"
#include "gs_base.h"

#define GS_C_INTERFACE
#include "gs_srv_ebook_interface_def.h"

///////////////////////////////////////////////////////////////////////////
//
// IA
//
///////////////////////////////////////////////////////////////////////////

int __inline IA_f1(IA* obj, int i)
{
    return obj->vt->f1(obj, i);
}

int __inline IA_addRef(IA* obj)
{
    return obj->vt->addRef(obj);
}

int __inline IA_release(IA* obj)
{
    return obj->vt->release(obj);
}

int __inline IA_queryInterface(IA* obj, int iid, GS_IBase** pptr)
{
    return obj->vt->queryInterface(obj, iid, pptr);
}

///////////////////////////////////////////////////////////////////////////
//
// IB
//
///////////////////////////////////////////////////////////////////////////

int __inline IB_f2(IB* obj, int i)
{
    return obj->vt->f2(obj, i);
}

int __inline IB_addRef(IB* obj)
{
    return obj->vt->addRef(obj);
}

int __inline IB_release(IB* obj)
{
    return obj->vt->release(obj);
}

int __inline IB_queryInterface(IB* obj, int iid, GS_IBase** pptr)
{
    return obj->vt->queryInterface(obj, iid, pptr);
}

