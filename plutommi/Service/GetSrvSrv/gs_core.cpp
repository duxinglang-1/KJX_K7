
#include "gs_id.h"
#include "gs_base.h"
#include "vmlog.h"
#include "MMI_features.h"

static U32 gs_service_handle =1;
typedef  GS_IBase* (* new_service_type) (U32 hd); 
typedef struct
{
   U32 sid;
   new_service_type new_service_func; 
}service_reg;

#define GS_SERVICE_TABLE_BEGIN                   const service_reg service_reg_array[] = {
#define GS_SERVICE_DEFINE(_sid, _create_func)    { _sid, _create_func },
#define GS_SERVICE_TABLE_END                    { 0, NULL } };


GS_IBase* CreateEbookService(U32 hd);
GS_IBase* CreateProfileService(U32 hd);
GS_IBase* CreateIdleScreenService(U32 hd);
GS_IBase* CreateMMVideoService(U32 hd);
GS_IBase* CreateImageviewerService(U32 hd);
GS_IBase* CreateBitstreamAudioService(U32 hd);
GS_IBase* CreateBitstreamRecordService(U32 hd);
GS_IBase* CreateVideoPDLService(U32 hd);
GS_IBase* CreateVideoStreamService(U32 hd);
GS_IBase* CreateVideoRecordService(U32 hd);
GS_IBase *CreateUcmService(U32 hd);
GS_IBase *CreateUmService(U32 hd);
GS_IBase *CreateMmsService(U32 hd);
GS_IBase *CreateEmailService(U32 hd);

GS_IBase* createVrtService(U32 hd);
GS_IBase* CreateFontEngineService(U32 hd);
GS_IBase* createImeService(U32 hd);
GS_IBase* createVfxService(U32 hd);
#ifdef __NCENTER20__
GS_IBase* CreateNcenterService(U32 hd);
#endif
GS_IBase* CreateAppmgrService(U32 hd);
GS_SERVICE_TABLE_BEGIN

   GS_SERVICE_DEFINE(SID_MYSERVICE, CreateEbookService)
       
   GS_SERVICE_DEFINE(SID_PROFILESERVICE, CreateProfileService)
   GS_SERVICE_DEFINE(SID_IDLESCREENSERVICE, CreateIdleScreenService)
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
   GS_SERVICE_DEFINE(SID_MMVIDEOSERVICE, CreateMMVideoService)
#endif
#if defined(__MMI_IMAGE_VIEWER__)
   GS_SERVICE_DEFINE(SID_IMAGEVIEWERSERVICE, CreateImageviewerService)
#endif
#if defined(__BITSTREAM_API_SUPPORT__)
   GS_SERVICE_DEFINE(SID_BISTREAMAUDIOSERVICE, CreateBitstreamAudioService)
   GS_SERVICE_DEFINE(SID_BISTREAMRECORDSERVICE, CreateBitstreamRecordService)
#endif
#ifdef __MMI_VIDEO_PDL__
   GS_SERVICE_DEFINE(SID_VIDEOPDLSERVICE, CreateVideoPDLService)
#endif
#ifdef __MMI_VIDEO_STREAM__
   GS_SERVICE_DEFINE(SID_VIDEOSTREAMSERVICE, CreateVideoStreamService)
#endif

#if defined (__MMI_VIDEO_RECORDER__) || defined(__MMI_CAMCORDER__)
   GS_SERVICE_DEFINE(SID_VIDEORECORDSERVICE, CreateVideoRecordService)
#endif
#ifdef __MMI_UCM__
   GS_SERVICE_DEFINE(SID_UCMSERVICE, CreateUcmService)
#endif
   GS_SERVICE_DEFINE(SID_UMSERVICE, CreateUmService) 
   GS_SERVICE_DEFINE(SID_MMSSERVICE, CreateMmsService)
#ifdef __MMI_EMAIL__   
   GS_SERVICE_DEFINE(SID_EMAILSERVICE,CreateEmailService)
#endif
    GS_SERVICE_DEFINE(SID_APPMGRSERVICE,CreateAppmgrService)
#ifdef __NCENTER20__    
    GS_SERVICE_DEFINE(SID_NCENTERSERVICE,CreateNcenterService)
#endif    
GS_SERVICE_TABLE_END



#define SERVICE_REG_ARRAY_SIZE (sizeof(service_reg_array)/sizeof(service_reg))

extern "C"
S32 srv_create_service(S32 clsid, GS_IBase** pptr, const gs_mem_manage* mem)
{

    S32 i=0;
    service_reg cur_data;

    //MMI_TRACE(MMI_MRE_TRC_G6, TRC_MMI_GETSRV_ENTRY, clsid,iid);
    gs_service_handle++;
    srv_service_mem_init(mem,gs_service_handle);
    
    // Please notes: pptr may be a proxy, your call should not use it directly.
    
    if (pptr == NULL) 
    {
        //MMI_TRACE(MMI_MRE_TRC_G6, TRC_MMI_GETSRV_POINTER_NULL);
        return 0;
    }
    for(i=0;i<SERVICE_REG_ARRAY_SIZE;i++)
    {
        if(clsid == service_reg_array[i].sid)
        {
            cur_data = service_reg_array[i];
            break;
        }
    }
    if(i >= SERVICE_REG_ARRAY_SIZE)
    {
        //MMI_TRACE(MMI_MRE_TRC_G6, TRC_MMI_GETSRV_NOT_FIND_SRV); 
        return -1;
    }
    
    GS_IBase* obj = NULL;
    obj =  cur_data.new_service_func(gs_service_handle);
    //MMI_TRACE(MMI_MRE_TRC_G6, TRC_MMI_GETSRV_GET_SRV_POINTER,obj); 
    if (!obj)
    {
        return -1;
    }
    
    *pptr = obj;

    return 0;
}

