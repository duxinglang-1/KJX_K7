
#include"MMI_features.h"

#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
#include "MMSSrvGprot.h"
#include "mma_struct.h"
#include "mma_sap.h"
#include "MMS_sap_struct.h"
#include "MMS_api.h"
#include "mmi_rp_srv_mms_def.h"
#include "MMSTemplateGenSrv.h"
#include "Wgui_categories_util.h" //for get_audio

#include "Med_global.h" //for AUD_MELODY_BUFFER_LEN
#include "BootupSrvGprot.h"

/***************************** GLOBAL VARIABLES ********************************/
static U8 g_default_template_count = 0;

static mma_mms_description_body_struct *g_mms_template_body_struct = NULL;
static mma_mms_description_header_struct *g_mms_template_header_struct = NULL;
static mma_mms_description_struct *g_mms_template_content_info = NULL;

const srv_mms_default_template_info_struct mms_templates[] = 
{
#if MAX_TEMPLATES_NUM >= 1
    {STR_ID_UMMS_TEMPLATES_TITLE_01, IMG_ID_UMMS_TEMPLATES_01, AUDIO_ID_UMMS_TEMPLATES_01},     /* MMS Template 1 */
#endif
#if MAX_TEMPLATES_NUM >= 2
    {STR_ID_UMMS_TEMPLATES_TITLE_02, IMG_ID_UMMS_TEMPLATES_02, AUDIO_ID_UMMS_TEMPLATES_02},     /* MMS Template 2 */
#endif
#if MAX_TEMPLATES_NUM >= 3
    {STR_ID_UMMS_TEMPLATES_TITLE_03, IMG_ID_UMMS_TEMPLATES_03, AUDIO_ID_UMMS_TEMPLATES_03},     /* MMS Template 3 */
#endif
#if MAX_TEMPLATES_NUM >= 4
    {STR_ID_UMMS_TEMPLATES_TITLE_04, IMG_ID_UMMS_TEMPLATES_04, AUDIO_ID_UMMS_TEMPLATES_04},     /* MMS Template 4 */
#endif
#if MAX_TEMPLATES_NUM >= 5
    {STR_ID_UMMS_TEMPLATES_TITLE_05, IMG_ID_UMMS_TEMPLATES_05, AUDIO_ID_UMMS_TEMPLATES_05},     /* MMS Template 5 */
#endif
};

#if 0
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_mms_default_template_dummy_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  rsp_data        [?]         
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_default_template_dummy_cb(srv_mms_result_enum result, void *rsp_data, S32 user_data)
{
    return;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mms_default_template_fill_image_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image_obj       [?]         [?]
 *  image_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL srv_mms_default_template_fill_image_data(mma_mms_object_struct *image_obj, U16 image_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_length = 0;
    S8 file_name[MMA_MAX_INTERNAL_FILENAME_LENGTH];
    S8 file_ext[12] = {0, };
    FS_HANDLE file_handle;
    U32 write_len = 0;
    U8 *image_buff = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strcpy(file_name, "image0");
    image_buff = gdi_image_get_buf_ptr_from_id(image_id);   /* GH */
    image_length = gdi_image_get_buf_len_from_id(image_id); /* GH */

    if (image_buff == NULL || image_length == 0)
    {
        MMI_ASSERT(0);
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_TRC_MMS_DTMGR_CRITICAL_ERROR, __LINE__);
    }

    switch (gdi_image_get_type_from_id(image_id))
    {
        case GDI_IMAGE_TYPE_GIF:
            strcpy(file_ext, ".gif");
            break;
        case GDI_IMAGE_TYPE_JPG_SEQUENCE:
            strcpy(file_ext, ".jpg");
            break;
        case GDI_IMAGE_TYPE_PNG_SEQUENCE:
            strcpy(file_ext, ".png");
            break;
        case GDI_IMAGE_TYPE_BMP_SEQUENCE:
            strcpy(file_ext, ".bmp");
            break;
        case GDI_IMAGE_TYPE_BMP:
            strcpy(file_ext, ".bmp");
            break;
        case GDI_IMAGE_TYPE_JPG:
            strcpy(file_ext, ".jpg");
            break;
    }

    strcat(file_name, file_ext);
    mmi_asc_to_ucs2((S8*) image_obj->file_name_ucs, (S8*) file_name);
    /* mmi_asc_to_ucs2((S8*)image_obj->file_path,(S8*)"D:\\_UC\\"); */
    UMMS_MMI_MAKE_IMAGE_FILE_PATH(image_obj->file_path_ucs, 0);
    mmi_ucs2cat((S8*) image_obj->file_path_ucs, (S8*) image_obj->file_name_ucs);

    file_handle = FS_Open((U16*) image_obj->file_path_ucs, FS_CREATE_ALWAYS | FS_READ_WRITE);
    if (file_handle < 0)
    {
        srv_mms_default_template_emit_result(MMA_RESULT_FAIL_FILE_IO);
        return FALSE;
    }

    FS_Write(file_handle, image_buff, image_length, &write_len);
    FS_Close(file_handle);
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_default_template_fill_text_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_path       [IN]        
 *  subject         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL srv_mms_default_template_fill_text_data(const kal_wchar *file_path, const U8 *subject)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    U32 write_len = 0;
    U32 utf8_buffer_size = (mmi_ucs2strlen((S8*) subject) * 3 + ENCODING_LENGTH);
    U8 *utf8_buffer = NULL;
    U32 utf8_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mms_template_header_struct->header->subject.text = (char*)srv_mms_mem_mgr_app_adm_alloc(utf8_buffer_size);

    MMI_ASSERT(g_mms_template_header_struct->header->subject.text != NULL);

    memset(g_mms_template_header_struct->header->subject.text, 0, utf8_buffer_size);
    utf8_len = mmi_chset_ucs2_to_utf8_string(
                (U8*) (g_mms_template_header_struct->header->subject.text),
                utf8_buffer_size,
                (U8*) subject);

    file_handle = FS_Open((U16*) file_path, FS_CREATE_ALWAYS | FS_READ_WRITE);
    if (file_handle < 0)
    {
        srv_mms_mem_mgr_app_adm_free(utf8_buffer);
        srv_mms_default_template_emit_result(MMA_RESULT_FAIL_FILE_IO);
        return FALSE;

    }

    FS_Write(
        file_handle,
        (U8*) (g_mms_template_header_struct->header->subject.text),
        utf8_len - 1,   /* null terminator */
        &write_len);

    FS_Close(file_handle);

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_default_template_fill_audio_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audio_obj       [?]         [?]
 *  audio_buff      [IN]        
 *  audio_len       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL srv_mms_default_template_fill_audio_data(
        mma_mms_object_struct *audio_obj,
        const U8 *audio_buff,
        const U32 audio_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    FS_HANDLE file_handle;
    U32 write_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((S8*) audio_obj->file_name_ucs, (S8*) UMMS_TEMPLATE_AUDIO_FILE);
    UMMS_MMI_MAKE_AUDIO_FILE_PATH(audio_obj->file_path_ucs, 0)
        file_handle = FS_Open((U16*) audio_obj->file_path_ucs, FS_CREATE_ALWAYS | FS_READ_WRITE);

    if (file_handle < 0)
    {
        srv_mms_default_template_emit_result(MMA_RESULT_FAIL_FILE_IO);
        return FALSE;
    }

    FS_Write(file_handle, (U8*) audio_buff, audio_len, &write_len);
    FS_Close(file_handle);
    return TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mms_default_template_reset_template_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_default_template_reset_template_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* S32 result = 0; */
    mma_mms_slide_struct *slide = NULL;
    mma_mms_slide_struct *curr_slide = NULL;
    mma_mms_object_struct *object = NULL;
    mma_mms_object_struct *temp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_mms_template_body_struct)
    {
            slide = g_mms_template_body_struct->slides;
            object = g_mms_template_body_struct->objects;
            ASSERT(object);
            while (slide)
            {

                while (object)
                {
                    temp = object->next;
                    if (object->file_path_ucs)
                    {
                        FS_Delete((U16*) (object->file_path_ucs));
                        srv_mms_mem_mgr_app_adm_free(object->file_path_ucs);
                        object->file_path_ucs = NULL;
                    }
                    if (object->file_name_ucs)
                    {
                        srv_mms_mem_mgr_app_adm_free(object->file_name_ucs);
                        object->file_name_ucs = NULL;
                    }
                    if (object->file_path)
                    {
                        srv_mms_mem_mgr_app_adm_free(object->file_path);
                        object->file_path = NULL;
                    }
                    if (object->file_name)
                    {
                        srv_mms_mem_mgr_app_adm_free(object->file_name);
                        object->file_name = NULL;
                    }
                    srv_mms_mem_mgr_app_adm_free(object);
                    object = NULL;
                    object = temp;

                }
                curr_slide = slide;
                slide = slide->next;
                srv_mms_mem_mgr_app_adm_free(curr_slide);
                /* srv_mms_mem_mgr_app_adm_free(object); */
                object = NULL;
                curr_slide = NULL;

            }
    
        srv_mms_mem_mgr_app_adm_free(g_mms_template_body_struct);
        g_mms_template_body_struct = NULL;
    }

    if(g_mms_template_header_struct)
    {
        srv_mms_mem_mgr_app_adm_free(g_mms_template_header_struct->header->subject.text);
        g_mms_template_header_struct->header->subject.text = NULL;
        srv_mms_mem_mgr_app_adm_free(g_mms_template_header_struct->header);
        g_mms_template_header_struct->header = NULL;
        srv_mms_mem_mgr_app_adm_free(g_mms_template_header_struct);
        g_mms_template_header_struct = NULL;
    }

    if(g_mms_template_content_info)
    {
        srv_mms_mem_mgr_app_adm_free(g_mms_template_content_info);
        g_mms_template_content_info = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_default_template_check_template_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_mms_default_template_check_template_req(void *msg)
{		
	return srv_mms_default_template_is_ready();
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_default_template_delete_all_default_templates
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_default_template_delete_all_default_templates(srv_mms_funcptr_type call_back)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_delete_folder_req_struct template_del_all_req;
    S16 error;
    U8 state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_UMMS_DEF_TMPLT_GEN_STATE, &state, DS_BYTE, &error);

    if(state == SRV_MMS_TMPLT_GENERATING)
    {
        return;
    }

    template_del_all_req.user_data = NULL;
    template_del_all_req.msg_type = SRV_UM_MSG_MMS;
    template_del_all_req.msg_box_type = SRV_UM_MSG_BOX_PREDEF_TEMPLATES;
    template_del_all_req.app_id = MMA_APP_ID_TEMPLATE;
    if(call_back)
    {
        template_del_all_req.call_back = call_back;
        state = SRV_MMS_TMPLT_GENERATING;
        WriteValue(NVRAM_UMMS_DEF_TMPLT_GEN_STATE, &state, DS_BYTE, &error);
    }
    else
    {
        template_del_all_req.call_back = srv_mms_default_template_dummy_cb;
    }
    srv_mms_delete_folder(&template_del_all_req);
}

/*****************  GENERATE TEMPLATE XML  ****************/

/*****************************************************************************
 * FUNCTION
 *  srv_mms_default_template_generate_template_xml
 * DESCRIPTION
 *  
 * PARAMETERS
 *  subject         [IN]        
 *  image_id        [IN]        
 *  audio_buff      [IN]        
 *  audio_len       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_mms_default_template_generate_template_xml(
    const S8 *subject,
    const U16 image_id,
    const U8 *audio_buff,
    const U32 audio_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_slide_struct *temp_slide_head = NULL;
    mma_mms_object_struct *obj_head = NULL, *image_obj = NULL, *text_obj = NULL, *audio_obj = NULL;
    U16 array_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // memset(g_dtmgr_default_mms_creation.file_path, 0, MMA_MAX_INTERNAL_FILENAME_LENGTH);
    //UMMS_MMI_MAKE_MMS_TEMPLATE_XML_FILE_PATH(g_dtmgr_default_mms_creation.file_path, MMI_UMMS_DEFAULT_TYPE);
    g_mms_template_header_struct =
        (mma_mms_description_header_struct*) srv_mms_mem_mgr_app_adm_alloc(sizeof(mma_mms_description_header_struct));

    g_mms_template_body_struct =
        (mma_mms_description_body_struct*) srv_mms_mem_mgr_app_adm_alloc(sizeof(mma_mms_description_body_struct));
    g_mms_template_content_info =
        (mma_mms_description_struct*) srv_mms_mem_mgr_app_adm_alloc(sizeof(mma_mms_description_struct));

    MMI_ASSERT(g_mms_template_body_struct != NULL);
    MMI_ASSERT(g_mms_template_header_struct != NULL);
    MMI_ASSERT(g_mms_template_content_info != NULL);
    memset(g_mms_template_header_struct, 0, sizeof(mma_mms_description_header_struct));
    memset(g_mms_template_body_struct, 0, sizeof(mma_mms_description_body_struct));
    memset(g_mms_template_content_info, 0, sizeof(mma_mms_description_struct));
    /* memset(g_mms_template_header_struct->header, 0, sizeof(mma_mms_header_struct)); */
    g_mms_template_header_struct->header =
        (mma_mms_header_struct*) srv_mms_mem_mgr_app_adm_alloc(sizeof(mma_mms_header_struct));
    memset(g_mms_template_header_struct->header, 0, sizeof(mma_mms_header_struct));

    g_mms_template_body_struct->bgColor = UMMS_MMI_DEFAULT_BG_COLOR;
    g_mms_template_body_struct->fgColor = UMMS_MMI_DEFAULT_FG_COLOR;
    g_mms_template_header_struct->header->to = NULL;
    g_mms_template_header_struct->header->cc = NULL;
    g_mms_template_header_struct->header->bcc = NULL;

    g_mms_template_header_struct->header->read_reply = MMA_MMS_READ_REPLY_NO;
    g_mms_template_header_struct->header->delivery_report = MMA_MMS_DELIVERY_REPORT_NO;
    g_mms_template_header_struct->header->priority = MMA_PRIORITY_MEDIUM;
    g_mms_template_header_struct->header->expiry_time = UMMS_DEFAULT_EXPIRY_TIME;
    /* g_mms_template_header_struct->sender_visibility = UMMS_DEFAULT_SENDER_VISIBILTY; */
    g_mms_template_header_struct->header->delivery_time = UMMS_DEFAULT_DELIVERY_TIME;

    g_mms_template_body_struct->slides =
        (mma_mms_slide_struct*) srv_mms_mem_mgr_app_adm_alloc(sizeof(mma_mms_slide_struct));
    MMI_ASSERT(g_mms_template_body_struct->slides != NULL);
    memset(g_mms_template_body_struct->slides, 0, sizeof(mma_mms_slide_struct));

    temp_slide_head = g_mms_template_body_struct->slides;
    g_mms_template_body_struct->slides->next = NULL;
    g_mms_template_body_struct->slides->prev = NULL;
    g_mms_template_body_struct->slides->duration = (U8) (UMMS_DEFAULT_SLIDE_DURATION / 1000);
    g_mms_template_body_struct->slides->slide_num = 1;

    g_mms_template_content_info->body = g_mms_template_body_struct;
    g_mms_template_content_info->header = g_mms_template_header_struct;

    image_obj = (mma_mms_object_struct*) srv_mms_mem_mgr_app_adm_alloc(sizeof(mma_mms_object_struct));
    MMI_ASSERT(image_obj != NULL);
    memset(image_obj, 0, sizeof(mma_mms_object_struct));

    // 
    // image_obj->previous = NULL;
    //image_obj = obj_head[0];
    /* making image_object */
    image_obj->file_path = (kal_char*) srv_mms_mem_mgr_app_adm_alloc( /* MMA_MAX_INTERNAL_FILENAME_LENGTH */ 100);
    MMI_ASSERT(image_obj->file_path != NULL);
    image_obj->file_name = (kal_char*) srv_mms_mem_mgr_app_adm_alloc( /* MMA_MAX_INTERNAL_FILENAME_LENGTH */ 100);
    MMI_ASSERT(image_obj->file_name != NULL);
    image_obj->file_path_ucs = (kal_wchar*) srv_mms_mem_mgr_app_adm_alloc( /* MMA_MAX_INTERNAL_FILENAME_LENGTH */ 100);
    MMI_ASSERT(image_obj->file_path_ucs != NULL);
    image_obj->file_name_ucs = (kal_wchar*) srv_mms_mem_mgr_app_adm_alloc( /* MMA_MAX_INTERNAL_FILENAME_LENGTH */ 100);
    MMI_ASSERT(image_obj->file_name_ucs != NULL);

    obj_head = image_obj;
    g_mms_template_body_struct->objects = obj_head;
    /* fill image_data */
    if (srv_mms_default_template_fill_image_data(image_obj, image_id) == FALSE)
    {
        return MMI_FALSE;
    }
    mmi_chset_ucs2_to_utf8_string(
        (kal_uint8*) image_obj->file_path,
        100 * ENCODING_LENGTH,
        (kal_uint8*) image_obj->file_path_ucs);
    mmi_chset_ucs2_to_utf8_string(
        (kal_uint8*) image_obj->file_name,
        100 * ENCODING_LENGTH,
        (kal_uint8*) image_obj->file_name_ucs);
    image_obj->size = applib_get_file_size((kal_wchar*) image_obj->file_path_ucs);
    image_obj->id = 1;
    image_obj->reference_count = 1;
    image_obj->type = MMA_MMS_OBJECT_TYPE_IMAGE;
    image_obj->drm_type = MMA_DRM_NONE;
    image_obj->is_virtual_file = 0;
    /* make_text_object */

    text_obj = (mma_mms_object_struct*) srv_mms_mem_mgr_app_adm_alloc(sizeof(mma_mms_object_struct));
    MMI_ASSERT(text_obj != NULL);
    memset(text_obj, 0, sizeof(mma_mms_object_struct));

    text_obj->file_path = (kal_char*) srv_mms_mem_mgr_app_adm_alloc( /* MMA_MAX_INTERNAL_FILENAME_LENGTH */ 100);
    MMI_ASSERT(text_obj->file_path != NULL);
    text_obj->file_name = (kal_char*) srv_mms_mem_mgr_app_adm_alloc( /* MMA_MAX_INTERNAL_FILENAME_LENGTH */ 100);
    MMI_ASSERT(text_obj->file_name != NULL);
    text_obj->file_path_ucs =
        (kal_wchar*) srv_mms_mem_mgr_app_adm_alloc( /* MMA_MAX_INTERNAL_FILENAME_LENGTH */ 100 * ENCODING_LENGTH);
    MMI_ASSERT(text_obj->file_path_ucs != NULL);

    UMMS_MMI_MAKE_TEMPLATE_TEXT_FILE_PATH(text_obj->file_path_ucs, 0);
    text_obj->file_name_ucs =
        (kal_wchar*) srv_mms_mem_mgr_app_adm_alloc( /* MMA_MAX_INTERNAL_FILENAME_LENGTH */ 100 * ENCODING_LENGTH);
    MMI_ASSERT(text_obj->file_name_ucs != NULL);

    obj_head->next = text_obj;
    text_obj->prev = obj_head;

    mmi_asc_to_ucs2((S8*) text_obj->file_name_ucs, (S8*) UMMS_TEMPLATE_TEXT_FILE);

    if (srv_mms_default_template_fill_text_data(text_obj->file_path_ucs, subject) == FALSE)
    {
        return FALSE;
    }
    mmi_chset_ucs2_to_utf8_string(
        (kal_uint8*) text_obj->file_path,
        100 * ENCODING_LENGTH,
        (kal_uint8*) text_obj->file_path_ucs);
    mmi_chset_ucs2_to_utf8_string(
        (kal_uint8*) text_obj->file_name,
        100 * ENCODING_LENGTH,
        (kal_uint8*) text_obj->file_name_ucs);
    text_obj->size = applib_get_file_size((kal_wchar*) text_obj->file_path_ucs);

    text_obj->id = 2;
    text_obj->reference_count = 1;
    text_obj->type = MMA_MMS_OBJECT_TYPE_TEXT;
    text_obj->drm_type = MMA_DRM_NONE;
    text_obj->is_virtual_file = 0;
    
    /* make audio objetcs */
    if (audio_buff != NULL)
    {
        audio_obj = (mma_mms_object_struct*) srv_mms_mem_mgr_app_adm_alloc(sizeof(mma_mms_object_struct));
        MMI_ASSERT(audio_obj != NULL);
        memset(audio_obj, 0, sizeof(mma_mms_object_struct));
        audio_obj->file_path = (kal_char*) srv_mms_mem_mgr_app_adm_alloc( /* MMA_MAX_INTERNAL_FILENAME_LENGTH */ 100);

        MMI_ASSERT(audio_obj->file_path != NULL);

        audio_obj->file_name =
            (kal_char*) srv_mms_mem_mgr_app_adm_alloc( /* MMA_MAX_INTERNAL_FILENAME_LENGTH * */ 100);
        MMI_ASSERT(audio_obj->file_name != NULL);
        audio_obj->file_path_ucs =
            (kal_wchar*) srv_mms_mem_mgr_app_adm_alloc( /* MMA_MAX_INTERNAL_FILENAME_LENGTH */ 100 * ENCODING_LENGTH);

        MMI_ASSERT(audio_obj->file_path_ucs != NULL);

        audio_obj->file_name_ucs =
            (kal_wchar*) srv_mms_mem_mgr_app_adm_alloc( /* MMA_MAX_INTERNAL_FILENAME_LENGTH * */ 100 *
                                                        ENCODING_LENGTH);
        MMI_ASSERT(audio_obj->file_name_ucs != NULL);

        (obj_head->next)->next = audio_obj;
        audio_obj->prev = (obj_head->next);

        if (srv_mms_default_template_fill_audio_data(audio_obj, audio_buff, audio_len) == FALSE)
        {
            return FALSE;
        }
        mmi_chset_ucs2_to_utf8_string(
            (kal_uint8*) audio_obj->file_path,
            100 * ENCODING_LENGTH,
            (kal_uint8*) audio_obj->file_path_ucs);
        mmi_chset_ucs2_to_utf8_string(
            (kal_uint8*) audio_obj->file_name,
            100 * ENCODING_LENGTH,
            (kal_uint8*) audio_obj->file_name_ucs);

        audio_obj->size = applib_get_file_size((kal_wchar*) audio_obj->file_path_ucs);
        audio_obj->id = 3;
        audio_obj->reference_count = 1;
        audio_obj->type = MMA_MMS_OBJECT_TYPE_AUDIO;
        audio_obj->drm_type = MMA_DRM_NONE;
        audio_obj->is_virtual_file = 0;
        
    }
    else
    {
        (obj_head->next)->next = NULL;
    }

    /* add text data to slide */
    memset(&g_mms_template_body_struct->slides->txt, 0, sizeof(mma_mms_slide_text_object_struct));
    g_mms_template_body_struct->slides->txt.bg_color = UMMS_MMI_DEFAULT_BG_COLOR;
    g_mms_template_body_struct->slides->txt.fg_color = UMMS_MMI_DEFAULT_FG_COLOR;
    g_mms_template_body_struct->slides->txt.id = text_obj->id;
    g_mms_template_body_struct->slides->txt.object = text_obj;
    g_mms_template_body_struct->slides->txt.begin = 0;
    g_mms_template_body_struct->slides->txt.end = (U8) (UMMS_DEFAULT_SLIDE_DURATION / 1000);

    memset(&g_mms_template_body_struct->slides->img, 0, sizeof(mma_mms_slide_object_struct));
    g_mms_template_body_struct->slides->img.id = image_obj->id;

    g_mms_template_body_struct->slides->img.begin = 0;
    g_mms_template_body_struct->slides->img.end = (U8) (UMMS_DEFAULT_SLIDE_DURATION / 1000);
    g_mms_template_body_struct->slides->img.object = image_obj;
    /* add audio object in slide */

    if (audio_buff != NULL)
    {
        memset(&g_mms_template_body_struct->slides->aud, 0, sizeof(mma_mms_slide_object_struct));
        g_mms_template_body_struct->slides->aud.id = audio_obj->id;

        g_mms_template_body_struct->slides->aud.begin = 0;
        g_mms_template_body_struct->slides->aud.end = (U8) (UMMS_DEFAULT_SLIDE_DURATION / 1000);
        g_mms_template_body_struct->slides->aud.object = audio_obj;
        g_mms_template_body_struct->obj_no = 3;
    }
    else
    {
        g_mms_template_body_struct->obj_no = 2;
    }
    
    g_mms_template_body_struct->attachment = NULL;
    g_mms_template_body_struct->slides->duration = (U8) (UMMS_DEFAULT_SLIDE_DURATION / 1000);
    g_mms_template_body_struct->slide_no = 1;
    g_mms_template_body_struct->slides->slide_num = 1;
    g_mms_template_body_struct->layout = MMA_LAYOUT_TEXT_ON_TOP;
    
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_default_template_get_template_resource
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_default_template_get_template_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = FS_NO_ERROR;
    PU8 img_buff_p = NULL;
    S8 *title = NULL;

    U8 *audio_buff = NULL;
    U16 *audio_file_path;

    U32 write_len = 0;

    U32 audio_len = 0;
    U32 audio_size = 0;

    FS_HANDLE file_handle;
    mms_content_class_enum content_class = mms_get_content_class();
    U8 audio_type = 0;
    U8 *audio_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    audio_file_path = (U16*) srv_mms_mem_mgr_app_adm_alloc(MMA_MAX_INTERNAL_FILENAME_LENGTH * ENCODING_LENGTH);
    MMI_ASSERT(audio_file_path != NULL);
    /* memset here */
    memset(audio_file_path, 0, MMA_MAX_INTERNAL_FILENAME_LENGTH * ENCODING_LENGTH);
    mmi_asc_to_ucs2((S8*) audio_file_path, (S8*) UMMS_TEMPLATE_AUDIO_FILE);
    UMMS_MMI_MAKE_AUDIO_FILE_PATH(audio_file_path, 0)
        title = (S8*) GetString(mms_templates[g_default_template_count].strId);
    img_buff_p = (PU8) GetImage((U16) (mms_templates[g_default_template_count].imageId));

    audio_data = get_audio((U16) (mms_templates[g_default_template_count].audioId), &audio_type, &audio_len);

    audio_buff = (U8*) (audio_data);

    file_handle = FS_Open((U16*) audio_file_path, FS_CREATE_ALWAYS | FS_READ_WRITE);

    if (file_handle < 0)
    {
        srv_mms_default_template_emit_result(MMA_RESULT_FAIL_FILE_IO);
        srv_mms_mem_mgr_app_adm_free(audio_file_path);
        return;

    }

    FS_Write(file_handle, (U8*) audio_buff, audio_len, &write_len);
    FS_Close(file_handle);
    audio_size = applib_get_file_size((kal_wchar*) audio_file_path);
    srv_mms_mem_mgr_app_adm_free(audio_file_path);
    audio_file_path = NULL;

    if ((content_class <= MMS_CONTENT_CLASS_IMAGE_BASIC) || (audio_size > AUD_MELODY_BUFFER_LEN))
    {
        audio_buff = NULL;
        audio_len = 0;
    }
    if(srv_mms_default_template_generate_template_xml(
        title,
        (U16) (mms_templates[g_default_template_count].imageId),
        audio_buff,
        audio_len))
    {
        //Create Req
        srv_mms_default_template_send_create_template_req();
    }
    else
    {
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_default_template_start_gen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  rsp_data        [?]         
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_default_template_start_gen(srv_mms_result_enum result, void *rsp_data, S32 user_data)
{
    

    if(srv_mms_default_template_generation_state() == SRV_MMS_TMPLT_GENERATING)
    {
        /*Already Generating*/
        srv_mms_init_default_templates();
        srv_mms_default_template_get_template_resource();
    }
    
}

/*****************************************************************************
 * FUNCTION
 *  srv_mms_default_template_save_template_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  rsp_data        [?]         
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_default_template_save_template_cb(srv_mms_result_enum result, void *rsp_data, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_save_rsp_struct *template_save_rsp;
    U8 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    template_save_rsp = (srv_mms_save_rsp_struct*) rsp_data;
    if (template_save_rsp->result[0] == MMA_RESULT_OK)
    {
        /* srv_mms_get_number_status_icon(); */
        srv_mms_msg_update_count_and_status_icon();
        g_default_template_count++;

        if (g_default_template_count < MAX_TEMPLATES_NUM /* MAX_PREDEFINED_TEMPLATE */ )
        {
            srv_mms_default_template_reset_template_msg();
            srv_mms_default_template_get_template_resource();
            return;
        }
        else
        {
            srv_mms_default_template_emit_result(MMA_RESULT_OK);
        }
    }
    else
    {
        
        srv_mms_default_template_emit_result(template_save_rsp->result[0]);
        srv_mms_default_template_delete_all_default_templates(NULL);
        srv_mms_delete_msg(template_save_rsp->msg_id[0], &error);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_mms_default_template_create_template_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  rsp_data        [?]         
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_default_template_create_template_cb(srv_mms_result_enum result, void *rsp_data, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_create_rsp_struct *create_rsp_data;
    srv_mms_save_req_struct template_save_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    create_rsp_data = (srv_mms_create_rsp_struct*) rsp_data;
    if (create_rsp_data->result == MMA_RESULT_OK)
    {
        template_save_req.user_data = NULL;
        template_save_req.no_of_msg = 1;
        template_save_req.msg_id[0] = create_rsp_data->msg_id;
        template_save_req.box = MMA_FOLDER_TEMPLATE;
        template_save_req.app_id = MMA_APP_ID_TEMPLATE;
        template_save_req.call_back = (srv_mms_funcptr_type) srv_mms_default_template_save_template_cb;
        srv_mms_save(&template_save_req);     
    }
    else    /* create rsp is not Ok so delete all the default template messages */
    {
            
            srv_mms_default_template_emit_result(create_rsp_data->result);
            srv_mms_default_template_delete_all_default_templates(NULL);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_mms_default_template_send_create_template_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_default_template_send_create_template_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    srv_mms_create_req_struct template_create_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&template_create_req, 0, sizeof(srv_mms_create_req_struct));

    template_create_req.user_data = NULL;
    template_create_req.content_info = g_mms_template_content_info;
    template_create_req.app_id = MMA_APP_ID_TEMPLATE;
    template_create_req.mode = MMA_MODE_EDIT;
    template_create_req.sim_id = 0;
    template_create_req.call_back = srv_mms_default_template_create_template_cb;
    srv_mms_create(&template_create_req);

}

/*****************************************************************************
 * FUNCTION
 *  srv_mms_default_template_emit_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  rsp_data        [?]         
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_default_template_emit_result(mma_result_enum result)
{
    S16 error;
    U8 state;
    wap_mma_check_template_rsp_struct *rsp;


    g_default_template_count = 0;
    srv_mms_default_template_reset_template_msg();


    if(result == MMA_RESULT_OK)
    {
        state = SRV_MMS_TMPLT_READY;
    }
    else if((result == MMA_RESULT_FAIL_INSUFFICIENT_MEMORY) ||
            (result == MMA_RESULT_FAIL_MAX_MSG_NUM_REACHED) ||
            (result == MMA_RESULT_FAIL_INSUFFICIENT_STORAGE) ||
            (result == MMA_RESULT_FAIL_BUSY) ||
            (result == MMA_RESULT_FAIL_SUSPENDED_MODE) ||
            (result == MMA_RESULT_FAIL_ROOT_DIR_FULL))
    {
        state = SRV_MMS_TMPLT_FAIL_AND_STOP;
    }
    else
    {
        state = SRV_MMS_TMPLT_FAIL;
    }
     
    WriteValue(NVRAM_UMMS_DEF_TMPLT_GEN_STATE, &state, DS_BYTE, &error);

    srv_mms_send_events_ex(EVT_ID_SRV_MMS_TEMPLATE_GEN_RESULT, (void*)&result);

    rsp = (wap_mma_check_template_rsp_struct*) OslConstructDataPtr(sizeof(wap_mma_check_template_rsp_struct));

    rsp->result = result;
    rsp->app_id = MMA_APP_ID_TEMPLATE;


if(srv_mms_is_ready())
{
    srv_mms_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_DEF_TMPLT_GEN_DONE_IND),
        0,
        MSG_ID_WAP_MMA_DEF_TMPLT_GEN_DONE_IND,
        (oslParaType*) rsp,
        NULL);
}
}

/*****************************************************************************
 * FUNCTION
 *  srv_mms_default_template_generation_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  srv_mms_default_template_states
 *****************************************************************************/
srv_mms_default_template_states srv_mms_default_template_generation_state(void)
{
    S16 error;
    U8 state;

    ReadValue(NVRAM_UMMS_DEF_TMPLT_GEN_STATE, &state, DS_BYTE, &error);

    return (srv_mms_default_template_states)state;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mms_default_template_is_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_default_template_is_ready(void)
{
    S16 error;
    U8 state;

    ReadValue(NVRAM_UMMS_DEF_TMPLT_GEN_STATE, &state, DS_BYTE, &error);

    if(state == SRV_MMS_TMPLT_READY)
    {
        return MMI_TRUE;
    }
    else if(state == SRV_MMS_TMPLT_FAIL)
    {
        srv_mms_default_template_delete_all_default_templates(srv_mms_default_template_start_gen);
        return MMI_FALSE;
    }
    else if(state == SRV_MMS_TMPLT_FAIL_AND_STOP)
    {
        srv_mms_default_template_delete_all_default_templates(NULL);
        return MMI_TRUE;
    }
    else if(state == SRV_MMS_TMPLT_GENERATING)
    {
        return MMI_FALSE;
    }
    else
    {
        MMI_ASSERT(0);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_mms_init_default_templates
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void srv_mms_init_default_templates(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    S32 result = FS_NO_ERROR;
    U8 folder_path[MMA_MAX_INTERNAL_FILENAME_LENGTH];

    S16 error;
    U8 state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(folder_path, 0, MMA_MAX_INTERNAL_FILENAME_LENGTH);
    MMI_UMMS_MAKE_TEMPLATE_FOLDER_PATH(folder_path);

    /* if the dir exists, delete it */
    file_handle = FS_Open((WCHAR*) folder_path, FS_OPEN_DIR | FS_READ_ONLY);
    if (file_handle >= 0)
    {
        FS_Close(file_handle);

        FS_XDelete((WCHAR*) folder_path, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
    }

    result = FS_CreateDir((WCHAR*) folder_path);
   
    FS_SetAttributes((unsigned short*)folder_path, FS_ATTR_DIR | FS_ATTR_HIDDEN);

    /*Check for Generation*/

    ReadValue(NVRAM_UMMS_DEF_TMPLT_GEN_STATE, &state, DS_BYTE, &error);

    if(state == SRV_MMS_TMPLT_READY)
    {
        return;
    }
    else
    {
        srv_mms_default_template_delete_all_default_templates(srv_mms_default_template_start_gen);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_mms_default_template_lang_changed_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_event_struct      [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret srv_mms_default_template_lang_changed_hdlr(mmi_event_struct* evt)
{
    S16 error;
    U8 state = SRV_MMS_TMPLT_FAIL;

    if(srv_bootup_is_completed())
    {
    if (srv_mms_is_ready())
    {
        srv_mms_default_template_delete_all_default_templates(srv_mms_default_template_start_gen);
    }
    else
    {
         WriteValue(NVRAM_UMMS_DEF_TMPLT_GEN_STATE, &state, DS_BYTE, &error);
    }
    }
    return MMI_RET_OK;

}
#endif