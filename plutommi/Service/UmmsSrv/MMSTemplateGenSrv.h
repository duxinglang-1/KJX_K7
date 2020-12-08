#ifndef MMS_SRV_TMPLT_GEN_H
#define MMS_SRV_TMPLT_GEN_H

#include "MMI_features.h"
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
#include "MMIDataType.h"
#include "mma_api.h"

#ifdef __MMI_MMS_TEMPLATES_NUM__
#define MAX_TEMPLATES_NUM __MMI_MMS_TEMPLATES_NUM__
#endif

#define UMMS_MMI_DEFAULT_BG_COLOR (mma_get_default_smil_bg_color())
#define UMMS_MMI_DEFAULT_FG_COLOR (mma_get_default_smil_fg_color())

#define UMMS_TEMPLATE_TEXT_FILE  "text0.txt"
#define UMMS_TEMPLATE_AUDIO_FILE "audio.mid"

#ifdef MMS_IN_LARGE_STORAGE
#define UMMS_MMI_MAKE_TEMPLATE_TEXT_FILE_PATH(x, d)   \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\Template\\text0.txt",/* SRV_FMGR_PUBLIC_DRV */SRV_FMGR_PUBLIC_DRV);
#else /* MMS_IN_LARGE_STORAGE */ 
#define UMMS_MMI_MAKE_TEMPLATE_TEXT_FILE_PATH(x, d)   \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\Template\\text0.txt",/* SRV_FMGR_SYSTEM_DRV */SRV_FMGR_SYSTEM_DRV);
#endif /* MMS_IN_LARGE_STORAGE */ 

#ifdef MMS_IN_LARGE_STORAGE
#define UMMS_MMI_MAKE_IMAGE_FILE_PATH(x, d)   \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\Template\\",/* SRV_FMGR_PUBLIC_DRV */SRV_FMGR_PUBLIC_DRV);
#else /* MMS_IN_LARGE_STORAGE */ 
#define UMMS_MMI_MAKE_IMAGE_FILE_PATH(x, d)   \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\Template\\",/* SRV_FMGR_SYSTEM_DRV */SRV_FMGR_SYSTEM_DRV);
#endif /* MMS_IN_LARGE_STORAGE */ 

#ifdef MMS_IN_LARGE_STORAGE
#define UMMS_MMI_MAKE_AUDIO_FILE_PATH(x, d)   \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\Template\\%s",/* SRV_FMGR_PUBLIC_DRV */SRV_FMGR_PUBLIC_DRV, UMMS_TEMPLATE_AUDIO_FILE);
#else /* MMS_IN_LARGE_STORAGE */ 
#define UMMS_MMI_MAKE_AUDIO_FILE_PATH(x, d)   \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\Template\\%s",/* SRV_FMGR_SYSTEM_DRV */SRV_FMGR_SYSTEM_DRV, UMMS_TEMPLATE_AUDIO_FILE);
#endif /* MMS_IN_LARGE_STORAGE */ 


#ifdef MMS_IN_LARGE_STORAGE
#define MMI_UMMS_MAKE_TEMPLATE_FOLDER_PATH(x)      \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\Template", \
      SRV_FMGR_PUBLIC_DRV/* , MMI_UC_FOLDER_NAME */);
#else /* MMS_IN_LARGE_STORAGE */ 
#define MMI_UMMS_MAKE_TEMPLATE_FOLDER_PATH(x)      \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\Template", \
      SRV_FMGR_SYSTEM_DRV/* , MMI_UC_FOLDER_NAME */);
#endif /* MMS_IN_LARGE_STORAGE */ 

typedef enum
{
  SRV_MMS_TMPLT_READY = 0x00,
  SRV_MMS_TMPLT_GENERATING = 0x01,
  SRV_MMS_TMPLT_FAIL_AND_STOP = 0x02,
  SRV_MMS_TMPLT_FAIL = 0xFF
}srv_mms_default_template_states;

typedef struct
{
    U16 strId;
    U16 imageId;
    U16 audioId;
} srv_mms_default_template_info_struct;

extern BOOL srv_mms_default_template_fill_image_data(mma_mms_object_struct *image_obj, U16 image_id);
extern BOOL srv_mms_default_template_fill_text_data(const kal_wchar *file_path, const U8 *subject);
extern BOOL srv_mms_default_template_fill_audio_data(
        mma_mms_object_struct *audio_obj,
        const U8 *audio_buff,
        const U32 audio_len);

extern void srv_mms_default_template_reset_template_msg(void);
extern MMI_BOOL srv_mms_default_template_check_template_req(void *msg);
extern void srv_mms_default_template_delete_all_default_templates(srv_mms_funcptr_type call_back);
extern U8 srv_mms_default_template_generate_template_xml(
    const S8 *subject,
    const U16 image_id,
    const U8 *audio_buff,
    const U32 audio_len);
extern void srv_mms_default_template_get_template_resource(void);
extern void srv_mms_default_template_start_gen(srv_mms_result_enum result, void *rsp_data, S32 user_data);
extern void srv_mms_default_template_save_template_cb(srv_mms_result_enum result, void *rsp_data, S32 user_data);
extern void srv_mms_default_template_create_template_cb(srv_mms_result_enum result, void *rsp_data, S32 user_data);
extern void srv_mms_default_template_send_create_template_req(void);
extern void srv_mms_default_template_emit_result(mma_result_enum result);
extern srv_mms_default_template_states srv_mms_default_template_generation_state(void);
extern MMI_BOOL srv_mms_default_template_is_ready(void);
extern void srv_mms_init_default_templates(void);
#endif
#endif