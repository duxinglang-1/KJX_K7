

#ifndef _EBOOK_INTERFACE_
#define _EBOOK_INTERFACE_

#include "gs_id.h"
#include "gs_base.h"
#include "gs_cbase.h"

#define GS_GEN_INTERFACE
#include "gs_srv_ebook_interface_def.h"

class EbookService : public GS_CBase, public IA, public IB
{

public:
    EbookService(U32 handle):GS_CBase(handle),m_fd(-1){}

	virtual ~EbookService();
	GS_CBASE_IMPLEMENT

    virtual S32 CALLCC f1(S32 i);
    virtual S32 CALLCC f2(S32 i);
	virtual S32 CALLCC queryInterface(S32 iid, GS_IBase** pptr);
private: 
	FS_HANDLE m_fd;

};

#endif


