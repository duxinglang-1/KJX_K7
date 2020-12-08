
#include "gs_srv_ebook_impl.h"



GS_IBase* CreateEbookService(U32 hd)
{
    //MMI_TRACE(MMI_MRE_TRC_G6, TRC_MMI_GETSRV_TEST_NEW_SERVICE); 
    EbookService* service = NULL;
    GS_NEW_EX(service, EbookService,(hd));
    return (GS_IBase*)(GS_CBase*)service;
}

EbookService ::~EbookService()
{
    S32 i=-1; 
    if(m_fd >0)
    {
        i = FS_Close(m_fd);
        MMI_ASSERT(i>=0);
        m_fd = -1;
    }

}

S32 CALLCC EbookService :: f1(S32 i)
{
    //MMI_TRACE(MMI_MRE_TRC_G6, TRC_MMI_GETSRV_TEST_FUNC1); 
   
   CHAR buf[6];
   S32 ret_drv;
   U16 newname[10];

	ret_drv = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
    if (ret_drv >= 0)
    {
        sprintf(buf, "%c:\\", (U8) ret_drv);
        mmi_asc_to_wcs((PU16) newname, buf);
    }
    mmi_wcscat(newname, (const WCHAR *)L"test");
    m_fd= FS_Open(newname,FS_READ_WRITE);
    MMI_ASSERT(m_fd >0);
    return i;
}

S32 CALLCC EbookService :: f2(S32 i)
{
	 //MMI_TRACE(MMI_MRE_TRC_G6, TRC_MMI_GETSRV_TEST_FUNC2); 
    S32 ret =-1; 
    if(m_fd >0)
    {
       ret = FS_Close(m_fd);
       MMI_ASSERT(ret>=0);
       m_fd = -1;
    }
    return i * 2;
}


S32 CALLCC EbookService ::queryInterface(S32 iid, GS_IBase** pptr)
{
    // Please notes: pptr may be a proxy, your call should not use it directly.
  //MMI_TRACE(MMI_MRE_TRC_G6, TRC_MMI_GETSRV_TEST_QUERTY); 
	if (pptr == NULL) return 0;
	if (iid == IID_IA)
	{
			//MMI_TRACE(MMI_MRE_TRC_G6, TRC_MMI_GETSRV_TEST_QUERTY_FUNC1); 
		addRef();
		*pptr = BIND_PROXY(IA, this);
		return 1;
	}
	if (iid == IID_IB)
	{
			//MMI_TRACE(MMI_MRE_TRC_G6, TRC_MMI_GETSRV_TEST_QUERTY_FUNC2); 
		addRef();
		*pptr = BIND_PROXY(IB, this);
		return 1;
	}        
	return GS_CBase::queryInterface(iid, pptr);	

}

