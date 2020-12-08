/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  MmsContextSrvLE.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contains the code to Encode MMS data into XML
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

// #include "MMI_include.h"
#include "MMI_features.h"
#ifndef __MMI_MMSCONTEXTSRV_C
#define __MMI_MMSCONTEXTSRV_C

#if defined(__MMI_MMS_2__) && defined (__MMI_MMS_SIMPLIFIED_UI_SUPPORT__)

#include "MmsSrvGprot.h"
#include "MmsSrvProt.h"
#include "mma_struct.h"
#include "mma_api.h"
#include "mms_api.h"
#include "mms_sap_struct.h"
#include "MmsContextSrvLE.h"
#include "MmsMemoryManagerSrv.h"
#include "MmsXMLDefSrv.h"
#include "MmsMsgParseSrv.h"
#include "Device.h"
#include "mdi_datatype.h"
#include "Mdi_video.h"
#include "Mdi_audio.h"
#include "Conversions.h"
/* Variables */
static srv_mms_base_data_struct g_base_context;

static mma_mms_description_struct g_mms_message_data;

static mma_sync_msg_attribute_struct *g_mms_msg_info;

srv_mms_uc_main_struct g_srv_mms_uc_supp;

static srv_mms_settings_info_struct g_srv_mms_uc_settings;
#if defined(__MMI_FTE_SUPPORT__)
MMI_BOOL g_umms_srv_app_preview_cui_flag = MMI_FALSE;
#endif
/* Functions */
static void srv_mms_get_address(void);

static MMI_BOOL srv_mms_uc_reset_mms_signature(void);

static mma_insert_check_struct srv_mms_uc_handle_object_insert_if_file_path_exist(void);

static void srv_mms_preprocess_data_internal(mma_mms_description_struct *data);

static mma_mms_viewer_object_type_enum srv_mms_convert_mma_enum_to_mms(mma_insert_type_enum type);
static mma_mms_state_enum srv_mms_convert_mms_state_to_mma_state(srv_mms_state_enum mms_state);
static mma_slide_layout_enum srv_mms_slim_convert_mms_layout_type(U8 layout_type);
static srv_mms_state_enum srv_mms_get_state_from_mode(U8 mode);

extern mma_result_enum mma_mms_get_msg_attribute(kal_uint32 msg_id, mma_sync_msg_attribute_struct *msg_attribute);
extern kal_uint32 applib_get_file_size(kal_wchar *filename);
extern kal_uint32 mma_mms_calc_slim_msg_size(const void *input, mma_mms_type_enum mms_type);

/* Definitions */


/*****************************************************************************
 * FUNCTION
 *  srv_mms_container_reset_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_container_reset_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_base_context.bgsr_msg_info)
    {
        srv_mms_mem_mgr_app_adm_free(g_base_context.bgsr_msg_info);
        g_base_context.bgsr_msg_info = NULL;
    }
    /* As in SLIM memory will be of app, we need not to do all this just deinit asm is ok */
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    if (g_mms_message_data.header)
    {
        if (g_mms_message_data.header->header)
        {
            srv_mms_mem_mgr_viewer_asm_free(g_mms_message_data.header->header);
            g_mms_message_data.header->header = NULL;
        }
        srv_mms_mem_mgr_viewer_asm_free(g_mms_message_data.header);
        g_mms_message_data.header = NULL;
    }
    if (g_mms_message_data.body)
    {
        srv_mms_mem_mgr_viewer_asm_free(g_mms_message_data.body);
        g_mms_message_data.body = NULL;
    }
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    if (g_mms_msg_info)
    {
        srv_mms_mem_mgr_app_adm_free(g_mms_msg_info);
        g_mms_msg_info = NULL;
    }
    /* delete all text file created for slide text */
    if (g_base_context.open_mode != MMA_MODE_VIEW)
    {
        srv_mms_delete_all_slide_text_file();
    }
    srv_mms_mem_mgr_asm_deinit_memory(APPLIB_MEM_AP_ID_UMMS, SRV_MMS_INSTANCE_DEFAULT_INDEX);
    srv_mms_mem_mgr_asm_deinit_memory(APPLIB_MEM_AP_ID_MMS_VIEWER, SRV_MMS_INSTANCE_DEFAULT_INDEX);
    srv_mms_delete_instance(SRV_MMS_INSTANCE_DEFAULT_INDEX);
    memset(&g_base_context, 0, sizeof(srv_mms_base_data_struct));
    memset(&g_mms_message_data, 0, sizeof(mma_mms_description_struct));
    memset(&g_srv_mms_uc_supp, 0, sizeof(srv_mms_uc_main_struct));
    memset(&g_srv_mms_uc_settings, 0, sizeof(srv_mms_settings_info_struct));
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_container_set_message_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_result_enum srv_mms_container_set_message_id(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_result_enum result = MMA_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_base_context.msg_id = msg_id;
    g_base_context.folder_id = mma_get_box(msg_id);

    /* Allocate Memory Start */
    g_mms_msg_info =
        (mma_sync_msg_attribute_struct*) srv_mms_mem_mgr_app_adm_alloc(sizeof(mma_sync_msg_attribute_struct));
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    {
        ASSERT(g_mms_msg_info);
    }
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    memset(g_mms_msg_info, 0, sizeof(mma_sync_msg_attribute_struct));
    /* Allocate Memory End */
    if (msg_id == 0)
    {
        return MMA_RESULT_OK;
    }
    result = mma_mms_get_msg_attribute(msg_id, g_mms_msg_info);
    g_mms_msg_info->expiry_date = g_mms_msg_info->expiry_date + g_mms_msg_info->date;
    g_base_context.msg_info = g_mms_msg_info;
    if (g_base_context.folder_id == MMA_FOLDER_OUTBOX || g_mms_msg_info->msg_type == MMA_MSG_TYPE_NOTIFICATION)
    {
        srv_mms_container_set_bgsr_info();
    }
    g_base_context.set_read_mark = (g_mms_msg_info->is_read == 0) ? 1 : 0;
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_msg_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mma_sync_msg_attribute_struct *srv_mms_get_msg_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mms_msg_info;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_container_get_message_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_mms_container_get_message_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_base_context.msg_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_mms_info_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void *srv_mms_get_mms_info_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (void*)&g_base_context;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_container_set_is_preview
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_preview      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_container_set_is_preview(MMI_BOOL is_preview)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_base_context.is_preview = is_preview;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_open_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  open_mode       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_open_mode(U8 open_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_base_context.open_mode = open_mode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_container_get_is_preview
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_container_get_is_preview(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL)g_base_context.is_preview;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_container_set_is_viewed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_viewed       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_container_set_is_viewed(MMI_BOOL is_viewed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_base_context.is_already_viewed = is_viewed;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_container_get_is_viewed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_container_get_is_viewed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_base_context.is_already_viewed;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_container_get_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_mms_container_get_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_base_context.folder_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_data_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_get_data_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_base_context.data_ready;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_container_prepare_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req     [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_mms_container_prepare_context(srv_mms_xml_parse_req_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_description_struct *mma_rsp = (mma_mms_description_struct*) req->mma_rsp;
    U16 id = APPLIB_MEM_AP_ID_MMS_VIEWER;
    srv_mms_viewer_result_enum result;
    mma_mms_state_enum msg_state;
    MMI_BOOL copy_result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * g_mms_message_data.header = mma_rsp->header;
     * g_mms_message_data.body = mma_rsp->body;
     */
    if (g_base_context.open_mode != MMA_MODE_VIEW)
    {
        id = 0;
    }
    srv_mms_container_dummy_initializer();
        g_srv_mms_uc_supp.srv_msg.msg_state = srv_mms_get_state_from_mode(g_base_context.open_mode);
        msg_state = srv_mms_convert_mms_state_to_mma_state(g_srv_mms_uc_supp.srv_msg.msg_state);
        copy_result = srv_mms_container_copy_header(
                        mma_rsp->header,
                        g_mms_message_data.header,
                        srv_mms_mem_mgr_viewer_asm_alloc_userdata,
                        srv_mms_mem_mgr_viewer_asm_free_userdata,
                        msg_state,
                        0,
                        (mma_app_mode_enum)g_base_context.open_mode,
                        NULL);
        if (copy_result == MMI_FALSE)
        {
            return SRV_MMS_RESULT_INSUFFICIENT_MEMORY;
        }
    
    if (mma_rsp->body == NULL)
    {
        srv_mms_insert_slide();
        g_mms_message_data.body->bgColor = mma_get_default_smil_bg_color() ;
        g_mms_message_data.body->fgColor = mma_get_default_smil_fg_color() ;

    }
    else
    {
        copy_result = srv_mms_container_copy_body(
                        mma_rsp->body,
                        g_mms_message_data.body,
                        srv_mms_mem_mgr_viewer_asm_alloc_userdata,
                        srv_mms_mem_mgr_viewer_asm_free_userdata,
                        (void*)&id);
    }
    if (copy_result == MMI_FALSE)
    {
        return SRV_MMS_RESULT_INSUFFICIENT_MEMORY;
    }
    g_mms_message_data.body->curr_slide = g_mms_message_data.body->slides;
    g_base_context.header_info = g_mms_message_data.header->header;
    srv_mms_preprocess_data_internal(&g_mms_message_data);
    srv_mms_get_address();
    result = srv_mms_process_data_init(&g_mms_message_data, req);
    if (result == SRV_MMS_VIEWER_OUT_OF_MEM)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_ERROR_FRM_SERVICE, result);
        srv_mms_viewer_send_event_to_exit(SRV_MMS_VIEWER_OUT_OF_MEM, 0);
        return SRV_MMS_VIEWER_OUT_OF_MEM;
    }
    g_base_context.data_ready = MMI_TRUE;
    return SRV_MMS_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_convert_mms_state_to_mma_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mms_state       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_mms_state_enum srv_mms_convert_mms_state_to_mma_state(srv_mms_state_enum mms_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mms_state)
    {
        case SRV_MMS_STATE_WRITE_NEW_MSG:
            return MMA_MMS_STATE_WRITE_NEW_MSG;
        case SRV_MMS_STATE_EDIT_EXISTED_MSG:
            return MMA_MMS_STATE_EDIT_EXISTED_MSG;
        case SRV_MMS_STATE_FORWARD:
            return MMA_MMS_STATE_FORWARD;
        case SRV_MMS_STATE_SEND:
            return MMA_MMS_STATE_SEND;
        case SRV_MMS_STATE_REPLY:
            return MMA_MMS_STATE_REPLY;
        case SRV_MMS_STATE_REPLY_ALL:
            return MMA_MMS_STATE_REPLY_ALL;
        case SRV_MMS_STATE_TOTAL_NUM:
            return MMA_MMS_STATE_TOTAL_NUM;
        default:
            MMI_ASSERT(0);
			return MMA_MMS_STATE_TOTAL_NUM;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_state_from_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_mms_state_enum srv_mms_get_state_from_mode(U8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mode)
    {
        case MMA_MODE_REPLY:
            return SRV_MMS_STATE_REPLY;
        case MMA_MODE_REPLY_ALL:
            return SRV_MMS_STATE_REPLY_ALL;
        case MMA_MODE_FORWARD:
            return SRV_MMS_STATE_FORWARD;
        case MMA_MODE_SEND:
            return SRV_MMS_STATE_SEND;
        case MMA_MODE_EDIT:
            return SRV_MMS_STATE_EDIT_EXISTED_MSG;
        default:
            return SRV_MMS_STATE_WRITE_NEW_MSG;

    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_container_set_bgsr_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_mms_container_set_bgsr_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_base_context.bgsr_msg_info)
    {
        /* Already Allocated it in set_message_id */
        return SRV_MMS_RESULT_OK;
    }
    g_base_context.bgsr_msg_info =
        (srv_mms_bgsr_msg_info_struct*) srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_bgsr_msg_info_struct));
    ASSERT(g_base_context.bgsr_msg_info);
    memset(g_base_context.bgsr_msg_info, 0, sizeof(srv_mms_bgsr_msg_info_struct));
    srv_mms_bgsr_get_msg_info(
        g_base_context.msg_id,
        g_base_context.bgsr_msg_info,
        NULL,
        g_mms_msg_info->msg_storage,
        (mma_msg_type_enum)g_mms_msg_info->msg_type);
    if (g_base_context.bgsr_msg_info->result == SRV_MMS_BGSR_RESULT_FAIL_NOT_READY)
    {
        return SRV_MMS_RESULT_NOT_READY;
    }
    return SRV_MMS_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_container_get_bgsr_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
srv_mms_bgsr_msg_info_struct *srv_mms_container_get_bgsr_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_base_context.bgsr_msg_info;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_preprocess_data_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_preprocess_data_internal(mma_mms_description_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_description_body_struct *body = data->body;
    mma_mms_slide_struct *slides = body->slides;
    mma_mms_attachment_info_struct *attachment = body->attachment;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (slides != NULL)
    {
        if (slides->txt.object)
        {
            slides->txt.object->type = MMA_MMS_OBJECT_TYPE_TEXT;
        }
        if (slides->img.object)
        {
            slides->img.object->type = MMA_MMS_OBJECT_TYPE_IMAGE;
        }
        if (slides->vid.object)
        {
            slides->vid.object->type = MMA_MMS_OBJECT_TYPE_VIDEO;
        }
        if (slides->aud.object)
        {
            slides->aud.object->type = MMA_MMS_OBJECT_TYPE_AUDIO;
        }
        slides = slides->next;
    }
    while (attachment != NULL)
    {
        attachment->object->type = MMA_MMS_OBJECT_TYPE_ATTACHMENT;
        attachment = attachment->next;
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_container_get_subject
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
char *srv_mms_container_get_subject(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mms_message_data.header->header->subject.text;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_container_get_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mma_mms_description_struct *srv_mms_container_get_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_mms_message_data;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_container_get_header
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mma_mms_header_struct *srv_mms_container_get_header(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mms_message_data.header->header;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_initialize_header_for_special_mms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_initialize_header_for_special_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mms_message_data.header =
        (mma_mms_description_header_struct*)
        srv_mms_mem_mgr_viewer_asm_alloc(sizeof(mma_mms_description_header_struct));
#ifdef __MMI_MMS_SLIM_IT1__
    {
        ASSERT(g_mms_message_data.header);
    }
#endif /* __MMI_MMS_SLIM_IT1__ */ 
    memset(g_mms_message_data.header, 0, sizeof(mma_mms_description_header_struct));
    g_mms_message_data.header->header =
        (mma_mms_header_struct*) srv_mms_mem_mgr_viewer_asm_alloc(sizeof(mma_mms_header_struct));
#ifdef __MMI_MMS_SLIM_IT1__
    {
        ASSERT(g_mms_message_data.header->header);
    }
#endif /* __MMI_MMS_SLIM_IT1__ */ 
    memset(g_mms_message_data.header->header, 0, sizeof(mma_mms_header_struct));
    {
        g_mms_message_data.header->header->date = g_mms_msg_info->date;
        g_mms_message_data.header->header->expiry_time = g_mms_msg_info->expiry_date;
        g_mms_message_data.header->header->status = g_mms_msg_info->msg_report_status;
    }
    g_base_context.header_info = g_mms_message_data.header->header;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_get_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_addr_list_struct *current_addr = NULL;
    mma_mms_header_struct *header = NULL;
    mma_mms_addr_list_struct *to_head = NULL;
    mma_mms_addr_list_struct *cc_head = NULL;
    mma_mms_addr_list_struct *bcc_head = NULL;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    header = srv_mms_container_get_header();
    to_head = current_addr = header->to;
    cc_head = header->cc;
    bcc_head = header->bcc;
    while (current_addr)
    {
        switch (current_addr->group)
        {
            case MMA_ADDRESS_GROUP_TYPE_TO:
                break;
            case MMA_ADDRESS_GROUP_TYPE_CC:
                (header->cc_num)++;
                if (!cc_head)
                {
                    cc_head = current_addr;
                    cc_head->prev = NULL;
                    cc_head->next = NULL;
                }
                else
                {
                    cc_head->next = current_addr;
                    current_addr->prev = cc_head;
                    cc_head = current_addr;
                }
                (header->to_num)--;
                to_head->next = to_head->next->next;
                break;
            case MMA_ADDRESS_GROUP_TYPE_BCC:

                (header->bcc_num)++;
                if (!bcc_head)
                {
                    bcc_head = current_addr;
                    bcc_head->prev = NULL;
                    bcc_head->next = NULL;
                }
                else
                {
                    bcc_head->next = current_addr;
                    current_addr->prev = bcc_head;
                    bcc_head = current_addr;
                }
                (header->to_num)--;
                to_head->next = to_head->next->next;
                break;
            default:
                ASSERT(FALSE);

        }
        to_head = to_head->next;
        current_addr = current_addr->next;
    }
    /* free to list */
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_address_from_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index               [IN]        
 *  address_group       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_mms_addr_list_struct *srv_mms_get_address_from_index(U16 index, mma_mms_address_group_type_enum address_group)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
    mma_mms_addr_list_struct *addr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (address_group)
    {
        case MMA_MMS_ADDRESS_GROUP_TYPE_TO:
        {
            addr = g_mms_message_data.header->header->to;
            break;
        }
        case MMA_MMS_ADDRESS_GROUP_TYPE_CC:
        {
            addr = g_mms_message_data.header->header->cc;
            break;
        }
        case MMA_MMS_ADDRESS_GROUP_TYPE_BCC:
        {
            addr = g_mms_message_data.header->header->bcc;
            break;
        }
        default:
            break;
    }

    for (; i < index; i++)
    {
        MMI_ASSERT(addr->next);
        addr = addr->next;
    }
    return addr;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_insert_slide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mma_mms_slide_struct *srv_mms_insert_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_slide_struct *new_slide;
    U32 slide_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    slide_size = sizeof(mma_mms_slide_struct);
    new_slide = srv_mms_mem_mgr_viewer_asm_alloc(slide_size);
    MMI_ASSERT(new_slide);
    memset(new_slide, 0, slide_size);
    new_slide->txt.bg_color = SRV_MMS_UC_DEFAULT_BG_COLOR;
    new_slide->txt.fg_color = SRV_MMS_UC_DEFAULT_FG_COLOR;

    g_mms_message_data.body->slide_no++;
    new_slide->duration = g_srv_mms_uc_settings.sliding_time.value;

    /* MMI_ASSERT(g_srv_uc_p[instance]->msg.msg_body.slide_no <= SRV_UC_MAX_MMS_SLIDE_NUM); */

    /* First slide */
    if (g_mms_message_data.body->slide_no == 1)
    {
        /* MMI_ASSERT( g_srv_uc_p[instance]->msg.total_slide_num == 1 ); */
        new_slide->next = NULL;
        new_slide->prev = NULL;

        g_mms_message_data.body->slides = new_slide;
        g_mms_message_data.body->curr_slide = new_slide;
        new_slide->slide_num = g_mms_message_data.body->slide_no;

    }
    else
    {
        /* temp code added to get the current_slide after which new slide will be added
           currenty not getting correct current_slide */
        /* begin */
        while (g_mms_message_data.body->curr_slide->next)
        {
            g_mms_message_data.body->curr_slide = g_mms_message_data.body->curr_slide->next;
        }
        /* end */
        new_slide->slide_num = g_mms_message_data.body->slide_no;

        new_slide->next = NULL;
        new_slide->prev = g_mms_message_data.body->curr_slide;

        g_mms_message_data.body->curr_slide->next = new_slide;
    }

    return new_slide;
}



/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_mms_setting
 * DESCRIPTION
 *  Get MMS setting response
 * PARAMETERS
 *  void
 *  inMsg       [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
mma_insert_check_struct srv_mms_get_mms_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* mmi_uc_insert_sig_result_enum pass_sig_check = MMI_UC_INSERT_SIG_RESULT_PASS; */
    mma_insert_info_struct insert_info;
    mma_mms_description_struct *description = srv_mms_container_get_content();
    mma_mms_header_struct *header_info = description->header->header;
    mma_mms_description_body_struct *body = description->body;
    
    
    mma_insert_check_struct check_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_mms_uc_settings.creation_mode = srv_mms_compose_settings_creation_mode();
    g_srv_mms_uc_settings.priority = srv_mms_sending_settings_priority();
    g_srv_mms_uc_settings.validity_period = srv_mms_sending_settings_validity_period();
    g_srv_mms_uc_settings.delivery_time = srv_mms_sending_settings_delivery_time();
    g_srv_mms_uc_settings.delivery_report = srv_mms_sending_settings_delivery_report();
    g_srv_mms_uc_settings.read_report = srv_mms_sending_settings_read_report();
    g_srv_mms_uc_settings.max_mms_size = wap_custom_get_max_mms_msg_size();
    g_srv_mms_uc_settings.best_page_duration = srv_mms_compose_settings_best_page_duration();   /* E_OFF=0/E_ON=1 */
    srv_mms_compose_setting_image_resize_info(&g_srv_mms_uc_settings.image_resize);
    srv_mms_compose_settings_default_slide_time(&g_srv_mms_uc_settings.sliding_time);
    g_srv_mms_uc_settings.hide_sender = srv_mms_sending_settings_hide_sender(); /* __MMI_MMS_HIDE_SENDER_SUPPORT__   */
    srv_mms_uc_reset_mms_signature();
    /* Here we should use MMS Context */
    /* new structure for XML removal */
    header_info->read_reply = srv_mms_convert_mms_rr_to_mma_rr(g_srv_mms_uc_settings.read_report);
    header_info->delivery_report = srv_mms_convert_mms_dr_to_mma_dr(g_srv_mms_uc_settings.delivery_report);
    header_info->priority = g_srv_mms_uc_settings.priority;
    header_info->expiry_time = (mma_mms_time_sec) g_srv_mms_uc_settings.validity_period;
    header_info->delivery_time = (mma_mms_time_sec) g_srv_mms_uc_settings.delivery_time;
    header_info->visibility = srv_mms_convert_mms_vis_to_mma_vis(g_srv_mms_uc_settings.hide_sender);

    /* Should Use MMS Body Conext Here */
    /* If enter from mmi_uc_entry_write_msg_with_content, the first slide is ready. */
    if (body->slide_no == 0)
    {
        body->curr_slide = srv_mms_insert_slide();
        (body->slide_no)++;
        /* Set duration of current slide as the value of MMS slide setting */
        body->curr_slide->duration = g_srv_mms_uc_settings.sliding_time.value;
    }
    else
    {
        /* Set duration of current slide as the value of MMS slide setting */
        /* srv_uc_insert_object_to_slide below will use g_uc_p->srv_msg->msg_body.curr_slide->duration, and also maybe change this value */
        body->curr_slide->duration = g_srv_mms_uc_settings.sliding_time.value;

        if (g_srv_mms_uc_supp.file_path)
        {
            mma_insert_check_struct check_result;
            

            memset(&check_result, 0, sizeof(check_result));

            insert_info.creation_mode = g_srv_mms_uc_settings.creation_mode;
            insert_info.current_msg_size = g_srv_mms_uc_supp.srv_msg.total_msg_size;
            insert_info.max_msg_size = g_srv_mms_uc_settings.max_mms_size;
            insert_info.insert_type = MMA_INSERT_UNKNOWN;
            insert_info.filepath = (kal_wchar*) g_srv_mms_uc_supp.file_path;
            insert_info.mms_type = MMA_MMS_TYPE_SMIL_MMS;

            mma_uc_insert_object_check(&insert_info, &check_result);

            /* the file maybe be deleted before UC is triggered */
            /* might be corrupted */
            /* might be high resolution */
            if (!(check_result.result) &&
                ((MMA_RESULT_FAIL_FILE_IO == check_result.detail_result) ||
                 (MMA_RESULT_FAIL_FILE_CORRUPTED == check_result.detail_result) ||
                 (MMA_RESULT_FAIL_FILE_NOT_FOUND == check_result.detail_result) ||
                 (MMA_RESULT_FAIL_FILE_EMPTY == check_result.detail_result) ||
                 (MMA_RESULT_FAIL_IMAGE_TOO_LARGE == check_result.detail_result)))
            {
                //Kuldeep will write mapping in another file
                //result = srv_uc_convert_mms_check_result(&check_result);
                //mmi_uc_display_popup(result);
                //app should show popup
                if (check_result.result != MMA_RESULT_OK)
                {
                    srv_mms_mem_mgr_app_adm_free(g_srv_mms_uc_supp.file_path);  /* kuldeep */
                    g_srv_mms_uc_supp.file_path = NULL;
                    srv_mms_container_reset_context();
                    return check_result;
                }
            }

            check_result = srv_mms_uc_handle_object_insert_if_file_path_exist();
            if (check_result.detail_result != MMA_RESULT_OK)
            {
                return check_result;
            }
            /* moved to mmi_uc_process_state_write_new_msg_in_mms_setting_rsp */
        }
    }
    srv_mms_update_msg_size();
    check_result.detail_result = MMA_RESULT_OK;
    return check_result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_uc_handle_object_insert_if_file_path_exist
 * DESCRIPTION
 *  Handle object insertion (obj -- the file-- g_uc_p->srv_main->file_path)
 *  when call this API, g_uc_p->srv_main->file_path should not = NULL
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL  -- if encounter error, should indicate caller, caller maybe stop to do the following flow
 *****************************************************************************/
mma_insert_check_struct srv_mms_uc_handle_object_insert_if_file_path_exist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 mmi_uc_image_path[SRV_MMS_MAX_TEMP_FILE_LEN];
    U16 *filePath = (U16*) g_srv_mms_uc_supp.file_path;
    mma_insert_check_struct check_result;
    mma_insert_info_struct insert_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_mms_uc_supp.file_path == NULL)
    {
        MMI_ASSERT(0);
    }

    memset(&check_result, 0, sizeof(check_result));

    insert_info.creation_mode = g_srv_mms_uc_supp.srv_msg.creation_mode;
    insert_info.current_msg_size = g_srv_mms_uc_supp.srv_msg.total_msg_size;
    insert_info.max_msg_size = g_srv_mms_uc_supp.srv_msg.max_mms_size;
    insert_info.insert_type = MMA_INSERT_UNKNOWN;
    insert_info.filepath = (kal_wchar*) g_srv_mms_uc_supp.file_path;
    insert_info.mms_type = MMA_MMS_TYPE_MIXED_MMS;

    mma_uc_insert_object_check(&insert_info, &check_result);
    memset(mmi_uc_image_path, 0x00, SRV_MMS_MAX_TEMP_FILE_LEN);

    /* Treat .txt files as attachments */
    if (check_result.insert_type == MMA_INSERT_TEXT)
    {

        /* MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_GET_MMS_SETTING_RSP_TO_ATT); */
        check_result.insert_type = MMA_INSERT_ATTACHMENT;
    }

    /* MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_GET_MMS_SETTING_RSP_INSERT_OBJ_CHECK_ERR); */
    if (check_result.result != MMA_RESULT_OK)
    {
        srv_mms_mem_mgr_app_adm_free(g_srv_mms_uc_supp.file_path);
        g_srv_mms_uc_supp.file_path = NULL;
        srv_mms_container_reset_context();
        return check_result;
    }
    return srv_mms_post_handler_select_object_from_fm_to_insert(check_result.insert_type, mmi_uc_image_path, filePath);

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_uc_reset_mms_signature
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  instance(?)     [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_uc_reset_mms_signature(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_mms_uc_settings.signature.text_file)
    {
        srv_mms_mem_mgr_app_adm_free(g_srv_mms_uc_settings.signature.text_file);
        g_srv_mms_uc_settings.signature.text_file = NULL;
    }
    if (g_srv_mms_uc_settings.signature.img_file)
    {
        srv_mms_mem_mgr_app_adm_free(g_srv_mms_uc_settings.signature.img_file);
        g_srv_mms_uc_settings.signature.img_file = NULL;
    }
    if (g_srv_mms_uc_settings.signature.audio_file)
    {
        srv_mms_mem_mgr_app_adm_free(g_srv_mms_uc_settings.signature.audio_file);
        g_srv_mms_uc_settings.signature.audio_file = NULL;
    }
    if (g_srv_mms_uc_settings.signature.video_file)
    {
        srv_mms_mem_mgr_app_adm_free(g_srv_mms_uc_settings.signature.video_file);
        g_srv_mms_uc_settings.signature.video_file = NULL;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_select_object_response_from_fm_to_insert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filePath        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_insert_check_struct srv_mms_select_object_response_from_fm_to_insert(PU16 filePath, S32 is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_insert_check_struct check_result;
    U32 flie_path_len = 0;
    mma_insert_info_struct insert_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&check_result, 0, sizeof(mma_insert_check_struct));
    if (filePath == NULL)
    {
        check_result.detail_result = MMA_RESULT_FAIL;
        return check_result;
    }
    /* use self parameter to save file name info */
    if (g_srv_mms_uc_supp.srv_msg.temp_file_path)
    {
        srv_mms_mem_mgr_viewer_asm_free(g_srv_mms_uc_supp.srv_msg.temp_file_path);
        g_srv_mms_uc_supp.srv_msg.temp_file_path = NULL;
    }

    flie_path_len = mmi_ucs2strlen((S8*) filePath);
    g_srv_mms_uc_supp.srv_msg.temp_file_path = srv_mms_mem_mgr_viewer_asm_alloc((flie_path_len + 1) * ENCODING_LENGTH);
    mmi_ucs2ncpy((S8*) g_srv_mms_uc_supp.srv_msg.temp_file_path, (S8*) filePath, flie_path_len);

    /* g_uc_p->main.is_short = is_short; */

    insert_info.creation_mode = srv_mms_compose_settings_creation_mode();
    insert_info.current_msg_size = 0;   /* becasue only check warning mode, no need curr size */
    insert_info.max_msg_size = /* g_srv_mms_uc_supp.srv_msg.max_mms_size300*1024 */ g_srv_mms_uc_settings.max_mms_size;
    insert_info.insert_type = g_srv_mms_uc_supp.highlighted_object_type;
    insert_info.filepath = (kal_wchar*) filePath;
    insert_info.mms_type = MMA_MMS_TYPE_SMIL_MMS;

    mma_uc_insert_object_check(&insert_info, &check_result);

    /* Main use is in Image case to show error popup before resize test. */
    if (!(check_result.result) &&
        ((MMA_RESULT_FAIL_FILE_IO == check_result.detail_result) ||
         (MMA_RESULT_FAIL_FILE_CORRUPTED == check_result.detail_result) ||
         (MMA_RESULT_FAIL_FILE_EMPTY == check_result.detail_result) ||
         (MMA_RESULT_FAIL_IMAGE_TOO_LARGE == check_result.detail_result)))
    {
        srv_mms_mem_mgr_viewer_asm_free(g_srv_mms_uc_supp.srv_msg.temp_file_path);
        g_srv_mms_uc_supp.srv_msg.temp_file_path = NULL;
        return check_result;
    }
    return srv_mms_post_handler_select_object_from_fm_to_insert(
            g_srv_mms_uc_supp.highlighted_object_type,
            (PU8) g_srv_mms_uc_supp.srv_msg.temp_file_path,
            (PU16) g_srv_mms_uc_supp.srv_msg.temp_file_path);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_post_handler_select_object_from_fm_to_insert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mms_type                [IN]        
 *  srv_mms_image_path      [?]         
 *  filePath                [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_insert_check_struct srv_mms_post_handler_select_object_from_fm_to_insert(
                            mma_insert_type_enum mms_type,
                            U8 *srv_mms_image_path,
                            PU16 filePath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U32 new_slide_size = 0;
    mma_mms_slide_struct *slide = g_mms_message_data.body->curr_slide;
    mma_insert_check_struct check_result;
    mma_mms_object_struct *object;
    mma_insert_info_struct insert_info;
    U32 obj_smil_size;
    U32 new_slide_size_tmp;
    MMI_BOOL fail_in_restricted_size_check;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&check_result, 0, sizeof(mma_insert_check_struct));
    /* 3. calculate new_slide_size */
    switch (mms_type)
    {
        case MMA_INSERT_IMAGE:
        {
            if (g_mms_message_data.body->curr_slide->img.object != NULL ||
                g_mms_message_data.body->curr_slide->vid.object != NULL)
            {
                new_slide_size = mma_uc_calc_slide_smil_size(5);
            }
        }
            break;

        case MMA_INSERT_AUDIO:
        {
            if (g_mms_message_data.body->curr_slide->aud.object != NULL ||
                g_mms_message_data.body->curr_slide->vid.object != NULL)
            {
                new_slide_size = mma_uc_calc_slide_smil_size(5);
            }
        }
            break;

        case MMA_INSERT_VIDEO:
        {
            if (g_mms_message_data.body->curr_slide->vid.object != NULL ||
                g_mms_message_data.body->curr_slide->img.object != NULL ||
                g_mms_message_data.body->curr_slide->aud.object != NULL)
            {
                new_slide_size = mma_uc_calc_slide_smil_size(5);
            }
        }
            break;

        default:
        {
            break;
        }
    }

    object = srv_mms_check_duplicate_object(filePath);

    /* kuldeep_attachment */
    if (mms_type != MMA_INSERT_ATTACHMENT &&
        object && object->type != MMA_MMS_OBJECT_TYPE_ATTACHMENT)
    {
        obj_smil_size = mma_uc_calc_object_smil_size(mms_type, filePath);
        new_slide_size_tmp = new_slide_size;
        fail_in_restricted_size_check = MMI_FALSE;

        /* only affect size check, still insert slide as usual */
        if (!srv_mms_check_if_exceed_MMS_size_limitation
            (NULL, obj_smil_size + new_slide_size_tmp + g_srv_mms_uc_supp.srv_msg.total_msg_size,
             &fail_in_restricted_size_check))
        {
            if (new_slide_size > 0)
            {
                slide = srv_mms_insert_slide();
                g_mms_message_data.body->curr_slide = slide;
                g_srv_mms_uc_supp.srv_msg.current_slide_num = slide->slide_num;
            }

            srv_mms_insert_object_to_slide(object, slide, mms_type, 0);
            check_result.detail_result = MMA_RESULT_OK;
            check_result.result = KAL_TRUE;
        }
        else
        {
            srv_mms_mem_mgr_viewer_asm_free(g_srv_mms_uc_supp.srv_msg.temp_file_path);
            g_srv_mms_uc_supp.srv_msg.temp_file_path = NULL;
			check_result.detail_result =  MMA_RESULT_FAIL_MAX_MSG_SIZE_REACHED;
			check_result.result = KAL_FALSE ;
			check_result.oversize = KAL_TRUE ;
            return check_result;
        }
    }
    else
    {

        insert_info.creation_mode = srv_mms_compose_settings_creation_mode();
        insert_info.current_msg_size = g_srv_mms_uc_supp.srv_msg.total_msg_size + new_slide_size;

        insert_info.max_msg_size = g_srv_mms_uc_settings.max_mms_size;
        insert_info.insert_type = mms_type;
        insert_info.filepath = (kal_wchar*) filePath;
        insert_info.mms_type = MMA_MMS_TYPE_SMIL_MMS;

        mma_uc_insert_object_check(&insert_info, &check_result);

        if (!(check_result.result))
        {
            srv_mms_mem_mgr_viewer_asm_free(g_srv_mms_uc_supp.srv_msg.temp_file_path);
            g_srv_mms_uc_supp.srv_msg.temp_file_path = NULL;
            return check_result;
        }

        if (new_slide_size > 0)
        {
            slide = srv_mms_insert_slide();
            g_mms_message_data.body->curr_slide = slide;
            g_srv_mms_uc_supp.srv_msg.current_slide_num = slide->slide_num;
        }

        object = srv_mms_insert_object((S8*) filePath, mms_type);
        object->drm_type = check_result.drm_type;
        g_srv_mms_uc_supp.highlighted_object_type = check_result.insert_type;
        /* kuldeep_attach */
        if (g_srv_mms_uc_supp.highlighted_object_type == MMA_INSERT_ATTACHMENT)
        {
            mma_mms_attachment_info_struct *attach = NULL;

            attach = srv_mms_insert_attachment(
                        g_mms_message_data.body,
                        srv_mms_mem_mgr_viewer_asm_alloc_userdata,
                        srv_mms_mem_mgr_viewer_asm_free_userdata,
                        NULL);
            srv_mms_insert_object_to_attachment(object, attach);
        }
        else
        {
            srv_mms_insert_object_to_slide(object, slide, g_srv_mms_uc_supp.highlighted_object_type, 0);
        }

    }

    /* 5. Determine layout */
    if (mms_type == MMA_INSERT_IMAGE ||
        mms_type == MMA_INSERT_VIDEO)
    {
        // if (g_mms_message_data.body->layout == MMA_LAYOUT_NONE)
        // {
        if (g_mms_message_data.body->curr_slide->txt.char_count)
        {
            g_mms_message_data.body->layout = SRV_MMS_VIEWER_DRAWABLE_MEDIA_ON_TOP;
        }
        else
        {
            g_mms_message_data.body->layout = SRV_MMS_VIEWER_DRAWABLE_MEDIA_ON_TOP;
        }
        /* } */
    }

    /* update the msg size after media insertion */
    srv_mms_update_msg_size();

    if (g_srv_mms_uc_supp.srv_msg.temp_file_path)
    {
        srv_mms_mem_mgr_viewer_asm_free(g_srv_mms_uc_supp.srv_msg.temp_file_path);
        g_srv_mms_uc_supp.srv_msg.temp_file_path = NULL;
    }
    if (g_srv_mms_uc_supp.srv_msg.msg_edit_mode == SRV_MMS_FORWARD_WITHOUT_EDIT_MODE)
    {
        g_srv_mms_uc_supp.srv_msg.msg_edit_mode = SRV_MMS_FORWARD_WITH_EDIT_MODE;
    }
    check_result.detail_result = MMA_RESULT_OK;
    return check_result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_insert_object_to_attachment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  object          [?]     
 *  attachment      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_insert_object_to_attachment(mma_mms_object_struct *object, mma_mms_attachment_info_struct *attachment)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    attachment->object = object;
    object->reference_count++;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_delete_object_of_slide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  slide       [?]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_delete_object_of_slide(mma_mms_slide_struct *slide)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (slide->img.object)
    {
        slide->img.object->reference_count--;
        /* might be possible that image is inserted multiple times so need to keep
           that image in the object list same for audio and video */

        if (slide->img.object->reference_count == 0)
        {
            srv_mms_delete_object_from_list(slide->img.object);
        }
    }

    if (slide->aud.object)
    {
        slide->aud.object->reference_count--;

        if (slide->aud.object->reference_count == 0)
        {
            srv_mms_delete_object_from_list(slide->aud.object);
        }
    }

    if (slide->vid.object)
    {
        slide->vid.object->reference_count--;

        if (slide->vid.object->reference_count == 0)
        {
            srv_mms_delete_object_from_list(slide->vid.object);
        }
    }

    if (slide->txt.object)
    {
        if (slide->txt.object->is_virtual_file == MMI_FALSE)
        {
            S32 result = FS_Delete((U16*) slide->txt.object->file_path_ucs);
        }
        else
        {
            slide->txt.object->reference_count--;
        }
        if (slide->txt.object->reference_count == 0)
        {
            srv_mms_delete_object_from_list(slide->txt.object);
        }

    }
    srv_mms_delete_slide(slide);
    srv_mms_reset_layout_if_needed();
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_delete_object_from_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  object      [?]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_delete_object_from_list(mma_mms_object_struct *object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (object == g_mms_message_data.body->objects)
    {
        g_mms_message_data.body->objects = object->next;

        if (object->next)
        {
            object->next->prev = NULL;
        }
    }
    else
    {
        object->prev->next = object->next;

        if (object->next)
        {
            object->next->prev = object->prev;
        }
    }
    g_mms_message_data.body->obj_no--;

    if (object->file_name_ucs)
    {
        srv_mms_mem_mgr_viewer_asm_free(object->file_name_ucs);
    }

    if (object->file_path_ucs)
    {
        srv_mms_mem_mgr_viewer_asm_free(object->file_path_ucs);
    }
	if (object->file_name)
    {
        srv_mms_mem_mgr_viewer_asm_free(object->file_name);
		object->file_name = NULL;
    }

    if (object->file_path)
    {
        srv_mms_mem_mgr_viewer_asm_free(object->file_path);
		object->file_path = NULL;
    }

    srv_mms_mem_mgr_viewer_asm_free(object);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_entry_delete_slide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_entry_delete_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_slide_struct *slide = g_mms_message_data.body->curr_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (slide->next)
    {
        g_mms_message_data.body->curr_slide = slide->next;
    }
    else if (slide->prev)
    {
        g_mms_message_data.body->curr_slide = slide->prev;
        g_srv_mms_uc_supp.srv_msg.signature_in_last_slide = MMI_FALSE;
    }
    else
    {
        g_mms_message_data.body->curr_slide = NULL;
        g_srv_mms_uc_supp.srv_msg.signature_in_last_slide = MMI_FALSE;
    }

    srv_mms_delete_object_of_slide(slide);
    if (g_mms_message_data.body->curr_slide != NULL)
    {
        g_srv_mms_uc_supp.srv_msg.current_slide_num = g_mms_message_data.body->curr_slide->slide_num;
    }

    /* mmi_uc_switch_slide(g_uc_p->srv_msg->msg_body.curr_slide); */

    srv_mms_update_msg_size();
    if (g_srv_mms_uc_supp.srv_msg.msg_edit_mode == SRV_MMS_FORWARD_WITHOUT_EDIT_MODE)
    {
        g_srv_mms_uc_supp.srv_msg.msg_edit_mode = SRV_MMS_FORWARD_WITH_EDIT_MODE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_delete_slide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  slide       [?]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_delete_slide(mma_mms_slide_struct *slide)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (slide == g_mms_message_data.body->slides)
    {
        g_mms_message_data.body->slides = slide->next;

        if (slide->next)
        {
            slide->next->prev = NULL;
        }
    }
    else
    {
        slide->prev->next = slide->next;

        if (slide->next)
        {
            slide->next->prev = slide->prev;
        }
    }
    g_mms_message_data.body->slide_no--;

    if (slide->next)
    {
        mma_mms_slide_struct *update_slide = slide->next;

        while (update_slide)
        {
            update_slide->slide_num--;
            srv_mms_update_text_object_path(update_slide);
            update_slide = update_slide->next;
        }
    }

    srv_mms_mem_mgr_viewer_asm_free(slide);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_update_text_object_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  slide       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_update_text_object_path(mma_mms_slide_struct *slide)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 srv_mms_text_path[SRV_MMS_MAX_TEMP_FILE_LEN];
    mma_mms_object_struct *object = NULL;
    U16 *file_name;
    U16 file_path_len = 0;
    U16 file_name_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(srv_mms_text_path, 0, SRV_MMS_MAX_TEMP_FILE_LEN);
    SRV_MMS_MAKE_TEXT_FILE_PATH(srv_mms_text_path, slide->slide_num, NULL);
    file_path_len = mmi_ucs2strlen((S8*) srv_mms_text_path);

    if ((object = slide->txt.object) != NULL && slide->txt.object->is_virtual_file == MMI_FALSE)
    {
        if (FS_Rename((U16*) object->file_path_ucs, (U16*) srv_mms_text_path) != FS_NO_ERROR)
        {
            return;
        }
        /* file path */
        if (object->file_path_ucs != NULL)
        {
            srv_mms_mem_mgr_viewer_asm_free(object->file_path_ucs);
            object->file_path_ucs = NULL;
        }
		if (object->file_path != NULL)
        {
            srv_mms_mem_mgr_viewer_asm_free(object->file_path);
            object->file_path = NULL;
        }
        object->file_path_ucs = srv_mms_mem_mgr_viewer_asm_alloc((file_path_len + 1) * 2);
        memset(object->file_path_ucs, 0, (file_path_len + 1) * 2);
        mmi_ucs2ncpy((S8*) object->file_path_ucs, (S8*) srv_mms_text_path, file_path_len);

        /* file name */
        if (object->file_name_ucs != NULL)
        {
            srv_mms_mem_mgr_viewer_asm_free(object->file_name_ucs);
            object->file_name_ucs = NULL;
        }
		if (object->file_name != NULL)
        {
            srv_mms_mem_mgr_viewer_asm_free(object->file_name);
            object->file_name = NULL;
        }
        file_name = srv_mms_get_file_name((U16*) srv_mms_text_path);
        file_name_len = mmi_ucs2strlen((S8*) file_name);
        object->file_name_ucs = srv_mms_mem_mgr_viewer_asm_alloc((file_name_len + 1) * 2);
        memset(object->file_name_ucs, 0, (file_name_len + 1) * 2);
        mmi_ucs2ncpy((S8*) object->file_name_ucs, (S8*) file_name, file_name_len);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filePath        [?]     
 * RETURNS
 *  
 *****************************************************************************/
U16 *srv_mms_get_file_name(U16 *filePath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 file_path_len = mmi_ucs2strlen((S8*) filePath);
    U16 *cur_position;
    U16 *pre_position;
    S32 i = file_path_len - 1;
    U8 pattern[3 * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(pattern, 0, sizeof(pattern));
    mmi_asc_n_to_ucs2((S8*) pattern, "\\", 1);

    for (; i >= 0; i--)
    {
        cur_position = &(filePath[i]);
        pre_position = cur_position - 1;
        if (mmi_ucs2ncmp((S8*) pre_position, (S8*) pattern, 1) == 0)
        {
            return cur_position;
        }
    }
    return filePath;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_reset_layout_if_needed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_reset_layout_if_needed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *object = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (object = g_mms_message_data.body->objects; object != NULL; object = object->next)
    {
        if (object->type == MMA_INSERT_IMAGE || object->type == MMA_INSERT_VIDEO)
        {
            break;
        }
    }

    if (object == NULL)
    {
        /* g_mms_message_data.body->layout =  MMA_LAYOUT_NONE; */
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_insert_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filePath        [?]         
 *  object_type     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_mms_object_struct *srv_mms_insert_object(S8 *filePath, mma_insert_type_enum object_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *new_object;
    U16 *file_name;
    U32 object_size;
    U16 file_path_len = mmi_ucs2strlen(filePath);
    U16 file_name_len = 0;
    mma_mms_object_struct *curr_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    object_size = sizeof(mma_mms_object_struct);
    new_object = srv_mms_mem_mgr_viewer_asm_alloc(object_size);
    memset(new_object, 0, object_size);

    /* file path */
    new_object->file_path_ucs = (kal_wchar*) srv_mms_mem_mgr_viewer_asm_alloc((file_path_len + 1) * 2);
    memset(new_object->file_path_ucs, 0, (file_path_len + 1) * 2);
    mmi_ucs2ncpy((S8*) new_object->file_path_ucs, (S8*) filePath, file_path_len);

    /* file name */
    file_name = srv_mms_get_file_name((U16*) filePath);
    file_name_len = mmi_ucs2strlen((S8*) file_name);
    new_object->file_name_ucs = (kal_wchar*) srv_mms_mem_mgr_viewer_asm_alloc((file_name_len + 1) * 2);
    memset(new_object->file_name_ucs, 0, (file_name_len + 1) * 2);
    mmi_ucs2ncpy((S8*) new_object->file_name_ucs, (S8*) file_name, file_name_len);

    /* type */
    new_object->type = srv_mms_convert_mma_enum_to_mms(object_type);
    /* size */
    new_object->size = applib_get_file_size((kal_wchar*) filePath);

    /* Default value! caller should update these value if necessary. */
    new_object->offset = 0;
    new_object->drm_type = MMA_DRM_NONE;
    new_object->is_virtual_file = MMI_FALSE;

    g_mms_message_data.body->obj_no++;

    /* First object */
    if (g_mms_message_data.body->objects == NULL)
    {
        g_mms_message_data.body->objects = new_object;
        new_object->next = NULL;
        new_object->prev = NULL;
        new_object->id = g_mms_message_data.body->obj_no;
    }
    else
    {
        /* Insert new object in the list head */
        curr_object = g_mms_message_data.body->objects;
        new_object->prev = NULL;
        for (; curr_object->next != NULL; curr_object = curr_object->next)
        {
        }
        curr_object->next = new_object;
        new_object->next = NULL;
        new_object->prev = curr_object;
        new_object->id = g_mms_message_data.body->obj_no;
    }
    return new_object;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_convert_mma_enum_to_mms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_mms_viewer_object_type_enum srv_mms_convert_mma_enum_to_mms(mma_insert_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case MMA_INSERT_UNKNOWN:
            return MMA_MMS_OBJECT_TYPE_UNKNOWN;
        case MMA_INSERT_TEXT:
            return MMA_MMS_OBJECT_TYPE_TEXT;
        case MMA_INSERT_IMAGE:
            return MMA_MMS_OBJECT_TYPE_IMAGE;
        case MMA_INSERT_AUDIO:
            return MMA_MMS_OBJECT_TYPE_AUDIO;
        case MMA_INSERT_VIDEO:
            return MMA_MMS_OBJECT_TYPE_VIDEO;
        case MMA_INSERT_REF:
            return MMA_MMS_OBJECT_TYPE_REF;
        case MMA_INSERT_ATTACHMENT:
            return MMA_MMS_OBJECT_TYPE_ATTACHMENT;
        default:
            ASSERT(0);
			return MMA_MMS_OBJECT_TYPE_MAX;

    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_insert_object_to_slide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  object              [?]         
 *  slide               [?]         
 *  object_type         [IN]        
 *  char_len_text       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_insert_object_to_slide(
            mma_mms_object_struct *object,
            mma_mms_slide_struct *slide,
            mma_insert_type_enum object_type,
            U16 char_len_text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (object_type)
    {
        case MMA_INSERT_IMAGE:
        {
            slide->img.object = object;
            slide->img.begin = 0;
            slide->img.end = slide->duration;
            slide->img.id = object->id;
            object->reference_count++;
        }
            break;

        case MMA_INSERT_AUDIO:
        {
            U32 file_duration = 0;
            U16 *extension = srv_mms_get_file_extension((U16*) object->file_path_ucs);

            slide->aud.object = object;
            slide->aud.begin = 0;
            /* New code for best page duration set the slide time as media duration */
            if (mdi_audio_get_duration(slide->aud.object->file_path_ucs, &(file_duration)) != MDI_AUDIO_SUCCESS)
            {
                file_duration = 0;
            }
            else
            {
                if (file_duration > 0 && file_duration < 1000)
                {
                    /* set minimum one second playing time MAUI_00275779 */
                    file_duration = 1;
                }
                else
                {
                    file_duration = file_duration / 1000;
                }
                slide->duration = slide->aud.begin + file_duration;
            }

            slide->aud.end = slide->duration;
            slide->aud.id = object->id;
            /* 3. increase ref count */
            object->reference_count++;
        }
            break;

        case MMA_INSERT_VIDEO:
        {
        #ifdef __MMI_VIDEO_PLAY_SUPPORT__
            mdi_video_info_struct vdo_info;
            MDI_RESULT result;
        #endif /* __MMI_VIDEO_PLAY_SUPPORT__ */ 
            U32 file_duration = 0;

            slide->vid.object = object;

            /* 1. check media file duration */
            slide->vid.begin = 0;

        #ifdef __MMI_VIDEO_PLAY_SUPPORT__
            result = mdi_video_ply_open_clip_file(0, (PS8) slide->vid.object->file_path_ucs, &vdo_info);
            if (result < 0)
            {
                file_duration = 0;
            }
            else
            {
                mdi_video_ply_close_clip_file();
                if (vdo_info.total_time_duration > 0 && vdo_info.total_time_duration < 1000)
                {
                    /* set minimum one second playing time MAUI_00275779 */
                    file_duration = 1;
                }
                else
                {
                    file_duration = (S32) (vdo_info.total_time_duration / 1000);
                }
                slide->duration = slide->vid.begin + file_duration;
            }
        #endif /* __MMI_VIDEO_PLAY_SUPPORT__ */ 

            slide->vid.end = slide->duration;
            slide->vid.id = object->id;
            object->reference_count++;
        }
            break;

        case MMA_INSERT_TEXT:
        {
            slide->txt.object = object;
            slide->txt.begin = 0;
            slide->txt.end = slide->duration;
            slide->txt.id = object->id;
            slide->txt.utf8_msg_len = char_len_text;
            slide->txt.bg_color = g_mms_message_data.body->bgColor;
            slide->txt.fg_color = g_mms_message_data.body->fgColor;
            slide->txt.text_style = 0;
            slide->txt.text_size = (slide->txt.text_size) - 1;
            object->reference_count++;
        }
            break;

        default:
        {
            break;
        }

    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_file_extension
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filePath        [?]     
 * RETURNS
 *  
 *****************************************************************************/
U16 *srv_mms_get_file_extension(U16 *filePath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 file_path_len = mmi_ucs2strlen((S8*) filePath);
    U16 *cur_position;
    U16 *pre_position;
    S32 i = file_path_len - 1;
    U8 pattern[3 * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(pattern, 0, sizeof(pattern));
    mmi_asc_n_to_ucs2((S8*) pattern, ".", 1);

    for (; i > 0; i--)
    {
        cur_position = &(filePath[i]);
        pre_position = cur_position - 1;
        if (mmi_ucs2ncmp((S8*) pre_position, (S8*) pattern, 1) == 0)
        {
            return cur_position;
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_check_duplicate_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filePath        [?]     
 * RETURNS
 *  
 *****************************************************************************/
mma_mms_object_struct *srv_mms_check_duplicate_object(U16 *filePath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *obj = g_mms_message_data.body->objects;
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mms_message_data.body->obj_no == 0)
    {
        return obj;
    }
    else
    {
        for (; i < g_mms_message_data.body->obj_no; i++)
        {
            if (mmi_ucs2cmp((S8*) obj->file_path_ucs, (S8*) filePath) == 0)
            {
                return obj;
            }
            else
            {
                obj = obj->next;
            }
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_update_filepath_with_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_mms_new_path        [?]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_update_filepath_with_string(S8 *srv_mms_new_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 flie_path_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* use self parameter to save file name info */
    if (g_srv_mms_uc_supp.srv_msg.temp_file_path)
    {
        srv_mms_mem_mgr_viewer_asm_free(g_srv_mms_uc_supp.srv_msg.temp_file_path);
        g_srv_mms_uc_supp.srv_msg.temp_file_path = NULL;
    }
    flie_path_len = mmi_ucs2strlen((S8*) srv_mms_new_path);

    g_srv_mms_uc_supp.srv_msg.temp_file_path = srv_mms_mem_mgr_viewer_asm_alloc((flie_path_len + 1) * ENCODING_LENGTH);

    mmi_ucs2ncpy((S8*) g_srv_mms_uc_supp.srv_msg.temp_file_path, (S8*) srv_mms_new_path, flie_path_len);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_is_valid_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_path       [?]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_is_valid_image(U16 *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT gdi_ret = GDI_FAILED;
    S32 width = 0, height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_ret = gdi_image_get_dimension_file((PS8) file_path, (S32*) & width, (S32*) & height);

#if(0)/*Fix Build Error*/
    mmi_camera_get_max_capture_resolution(&width_max, &height_max);
    if (gdi_ret < 0 || width <= 0 || height <= 0 || width > width_max || height > height_max)
#else /* __MMI_CAMERA__ */ 
    if (gdi_ret < 0 || width <= 0 || height <= 0 || width > SRV_MMS_UC_MAX_IMAGE_WIDTH || height > SRV_MMS_UC_MAX_IMAGE_HEIGHT)
#endif /* __MMI_CAMERA__ */ 
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_make_image_file_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_mms_image_path      [?]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_make_image_file_path(U8 *srv_mms_image_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct time;
    U32 time_value = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_dt_get_secure_time(&time);
    time_value = applib_dt_mytime_2_utc_sec(&time, KAL_TRUE);
    kal_wsprintf(
        (kal_uint16*) srv_mms_image_path,
        "%c:\\%s%03d\\%s%d.%s",
        SRV_MMS_UC_FOLDER_DRV,
        SRV_MMS_UC_FOLDER_NAME,
        0,
        SRV_MMS_UC_IMAGE_FILENAME,
        time_value,
        SRV_MMS_UC_IMAGE_FILEEXT);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_save_buffer_to_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_path       [?]         
 *  buffer          [?]         
 *  char_num        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_mms_save_buffer_to_file(U8 *file_path, U8 *buffer, U16 char_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    S32 result = FS_NO_ERROR;
    U32 write_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Open the file to write, overwrite if already exists. */

    file_handle = FS_Open((U16*) file_path, FS_CREATE_ALWAYS | FS_READ_WRITE);

    if (file_handle > 0)
    {

        U32 utf8_buffer_size = char_num;
        U8 *utf8_buffer = (U8*) srv_mms_mem_mgr_viewer_asm_alloc(utf8_buffer_size);
        U32 utf8_len = 0;

        /* MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_SAVE_BUFF_TO_FILE_P1, char_num); */

        /* MMI_ASSERT(utf8_buffer_size <= SRV_UC_UTF8_TEXT_BUFFER_SIZE); */

        memset(utf8_buffer, 0, utf8_buffer_size);
        utf8_len = mmi_chset_ucs2_to_utf8_string(utf8_buffer, utf8_buffer_size, buffer);

        result = FS_Write(
                    file_handle,
                    utf8_buffer,
                    utf8_len - 1,   /* null terminator */
                    &write_len);

        srv_mms_mem_mgr_viewer_asm_free(utf8_buffer);
        FS_Close(file_handle);
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_SAVE_BUFF_TO_FILE_FAIL_P1, file_handle);
        return FS_INVALID_FILE_HANDLE;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_hanlde_text_buffer_of_current_slide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  char_len        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_mms_uc_error_type_enum srv_mms_hanlde_text_buffer_of_current_slide(S32 char_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 text_file_path[SRV_MMS_MAX_TEMP_FILE_LEN];
    mma_mms_object_struct *object = NULL;
    S32 result = FS_NO_ERROR;
    U16 file_path_len;
    U16 file_name_len;
    U16 *file_name;
	U32 text_obj_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(text_file_path, 0, SRV_MMS_MAX_TEMP_FILE_LEN);
    SRV_MMS_MAKE_TEXT_FILE_PATH(text_file_path, g_mms_message_data.body->curr_slide->slide_num, NULL);
    srv_mms_update_msg_size();
    /* Add text object with empty content to the slide */
    if (char_len > 0)
    {   /* check here what will be msg_size after adding text [may exceed the msg_size] */

		if (g_mms_message_data.body->curr_slide->txt.object == NULL)
		{
			text_obj_size = mma_uc_calc_object_smil_size(MMA_INSERT_TEXT, (U16*) text_file_path);
			text_obj_size += mma_uc_calc_object_multipart_size((U16*) text_file_path);
			if ((g_srv_mms_uc_supp.srv_msg.total_msg_size + text_obj_size + char_len) > (300*1024))
                {
                   return SRV_MMS_UC_MESSAGE_SIZE_EXCEED_ERROR ;
                }

		}
		
		
		if((g_srv_mms_uc_supp.srv_msg.msg_size_without_text_buffer + char_len +
            mma_uc_calc_text_uintvar_overhead_size(char_len)) < (300*1024))
		{
			
		
        result = srv_mms_save_buffer_to_file(text_file_path, (U8*) g_srv_mms_uc_supp.srv_msg.fseditor_buffer, char_len);

        if (result == FS_NO_ERROR)
        {

            if (g_mms_message_data.body->curr_slide->txt.object == NULL)
            {

                object = srv_mms_insert_object((S8*) text_file_path, MMA_INSERT_TEXT);
                if (object)

                    srv_mms_insert_object_to_slide(
                        object,
                        g_mms_message_data.body->curr_slide,
                        MMA_INSERT_TEXT,
                        char_len);
                
                if (g_mms_message_data.body->curr_slide->img.object || g_mms_message_data.body->curr_slide->vid.object)
                {
                    g_mms_message_data.body->layout = SRV_MMS_VIEWER_DRAWABLE_MEDIA_ON_TOP;
                }
            }
            else
            {
                g_mms_message_data.body->curr_slide->txt.object->size = applib_get_file_size((kal_wchar*) text_file_path);
                g_mms_message_data.body->curr_slide->txt.utf8_msg_len = char_len;
                /* update the text object name and file path to new file name and path */
                if (g_mms_message_data.body->curr_slide->txt.object->is_virtual_file)
                {
                    /* free file_path and file_name */
                    srv_mms_mem_mgr_viewer_asm_free(g_mms_message_data.body->curr_slide->txt.object->file_path_ucs);
                    srv_mms_mem_mgr_viewer_asm_free(g_mms_message_data.body->curr_slide->txt.object->file_name_ucs);
					if(g_mms_message_data.body->curr_slide->txt.object->file_path)
					{
						srv_mms_mem_mgr_viewer_asm_free(g_mms_message_data.body->curr_slide->txt.object->file_path);
						g_mms_message_data.body->curr_slide->txt.object->file_path = NULL;
					}
                    if(g_mms_message_data.body->curr_slide->txt.object->file_name)
					{
						srv_mms_mem_mgr_viewer_asm_free(g_mms_message_data.body->curr_slide->txt.object->file_name);
						g_mms_message_data.body->curr_slide->txt.object->file_name = NULL;
					}

                    file_path_len = mmi_ucs2strlen((CHAR*)text_file_path);
                    g_mms_message_data.body->curr_slide->txt.object->file_path_ucs =
                        (kal_wchar*) srv_mms_mem_mgr_viewer_asm_alloc((file_path_len + 1) * ENCODING_LENGTH);
                    memset(
                        g_mms_message_data.body->curr_slide->txt.object->file_path_ucs,
                        0,
                        (file_path_len + 1) * ENCODING_LENGTH);
                    mmi_ucs2ncpy(
                        (S8*) g_mms_message_data.body->curr_slide->txt.object->file_path_ucs,
                        (S8*) text_file_path,
                        file_path_len);

                    file_name = srv_mms_get_file_name((U16*) text_file_path);
                    file_name_len = mmi_ucs2strlen((S8*) file_name);
                    g_mms_message_data.body->curr_slide->txt.object->file_name_ucs =
                        (kal_wchar*) srv_mms_mem_mgr_viewer_asm_alloc((file_name_len + 1) * ENCODING_LENGTH);
                    memset(
                        g_mms_message_data.body->curr_slide->txt.object->file_name_ucs,
                        0,
                        (file_name_len + 1) * ENCODING_LENGTH);
                    mmi_ucs2ncpy(
                        (S8*) g_mms_message_data.body->curr_slide->txt.object->file_name_ucs,
                        (S8*) file_name,
                        file_name_len);
                }

            }
            g_mms_message_data.body->curr_slide->txt.object->encoding = MMA_CHARSET_UTF8;
            g_mms_message_data.body->curr_slide->txt.object->is_virtual_file = MMI_FALSE;
            /* vaibhav changes */
            /*
             * if (g_mms_message_data.body->curr_slide->img.object || g_mms_message_data.body->curr_slide->vid.object )
             * {
             * g_mms_message_data.body->layout = SRV_MMS_VIEWER_DRAWABLE_MEDIA_ON_TOP;
             * }
             */
            /* vaibhav changes */
            srv_mms_update_msg_size();
        }
        else
        {

            FS_Delete((U16*) text_file_path);
            return SRV_MMS_UC_INVALID_HANDLE_ERROR;

        }

        return SRV_MMS_UC_NO_ERROR;
		}
		else
		{
           return SRV_MMS_UC_MESSAGE_SIZE_EXCEED_ERROR;
		}

    }
    /* Delete the text object */
    else if (char_len == 0)
    {
        if (g_mms_message_data.body->curr_slide->txt.object)
        {
            if (FS_Delete((U16*) text_file_path) != FS_NO_ERROR)
            {
                /* MMI_ASSERT(0); */
            }
            srv_mms_delete_object_from_list(g_mms_message_data.body->curr_slide->txt.object);
            memset(&(g_mms_message_data.body->curr_slide->txt), 0, sizeof(mma_mms_slide_text_object_struct));
            srv_mms_update_msg_size();
        }
        return SRV_MMS_UC_NO_ERROR;
    }
    else
    {

        return SRV_MMS_UC_MESSAGE_SIZE_EXCEED_ERROR;
        /* MMI_ASSERT(0); */
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_uc_is_phone_number_valid
 * DESCRIPTION
 *  return T if the phone number is valid
 * PARAMETERS
 *  strNumber       [IN]        
 * RETURNS
 *  pBOOL
 *****************************************************************************/
BOOL srv_mms_uc_is_phone_number_valid(S8 *strNumber)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen(strNumber) == 0)
    {
        return MMI_FALSE;
    }
    if (applib_is_valid_number_unicode((kal_wchar*) strNumber) != APPLIB_INVALID_NUMBER)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_update_msg_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_update_msg_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* need to be discussed with chetan */
    g_srv_mms_uc_supp.srv_msg.total_msg_size = mma_mms_calc_slim_msg_size(&g_mms_message_data, MMA_MMS_TYPE_SMIL_MMS);

    if (g_mms_message_data.body->curr_slide)
    {
		if(g_mms_message_data.body->curr_slide->txt.object)
		{
        g_srv_mms_uc_supp.srv_msg.msg_size_without_text_buffer =
            g_srv_mms_uc_supp.srv_msg.total_msg_size - g_mms_message_data.body->curr_slide->txt.object->size;
		}
		else
		{
           g_srv_mms_uc_supp.srv_msg.msg_size_without_text_buffer = g_srv_mms_uc_supp.srv_msg.total_msg_size ; 
            
		}
    }
    else
    {
        g_srv_mms_uc_supp.srv_msg.msg_size_without_text_buffer = g_srv_mms_uc_supp.srv_msg.total_msg_size;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_uc_is_email_addr_valid
 * DESCRIPTION
 *  Return if email address valid
 * PARAMETERS
 *  addr        [?]     [?]
 *  screen_id(?)        [IN](?)
 * RETURNS
 *  kal_bool
 *****************************************************************************/
BOOL srv_mms_uc_is_email_addr_valid(U8 *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 email_addr_len = mmi_ucs2strlen((S8*) addr);
    U16 i = 0;
    U16 *email_addr = (U16*) addr;
    U16 j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; i < email_addr_len; i++)
    {
        if (mmi_ucs2ncmp((S8*) & email_addr[i], (S8*) L"@", 1) == 0)
        {
            if (i == 0 || i == (email_addr_len - 1))
            {
                return FALSE;
            }
            else
            {
                U8 *ascii_addr = NULL;

                for (; j < email_addr_len; j++)
                {
                    U16 ucs2_char = email_addr[j];

                    /* non-ascii char */
                    if ((ucs2_char & 0xFF00) > 0)
                    {
                        return FALSE;
                    }
                }

                ascii_addr = srv_mms_mem_mgr_app_adm_alloc(email_addr_len + 1);
                memset(ascii_addr, 0, (email_addr_len + 1));

                mmi_ucs2_n_to_asc((S8*) ascii_addr, (S8*) addr, email_addr_len * ENCODING_LENGTH);

                if (applib_is_valid_email_address((char*)ascii_addr) == KAL_TRUE)
                {
                    srv_mms_mem_mgr_app_adm_free(ascii_addr);
                    return TRUE;
                }

                srv_mms_mem_mgr_app_adm_free(ascii_addr);
                return FALSE;
            }
        }
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_uc_check_uc_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_mms_uc_check_uc_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 srv_uc_folder_path[SRV_UC_MAX_TEMP_FILE_LEN];
    S32 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(srv_uc_folder_path, 0, SRV_MMS_MAX_TEMP_FILE_LEN);
    SRV_MMS_UC_MAKE_FOLDER_PATH(srv_uc_folder_path, 0);

    /* Check if the UC folder is created successfully. */
    /* user FS_GetAttributes, not use fs_open to check, because need to check if the it's a folder or not */
    result = FS_GetAttributes((WCHAR*) srv_uc_folder_path);

    if (result < 0)
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_CHECK_UC_FOLDER_NOT_EXIST);

        /* Try to create folder again besides srv_uc_init_uc_folder. */
        result = FS_CreateDir((WCHAR*) srv_uc_folder_path);

        /* Disallow to enter UC if UC folder cannot be created. */
        if (result < 0)
        {
            /* MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_CHECK_UC_FOLDER_CREATE_FAIL_P1, result); */
        }
        else
        {
            FS_SetAttributes((unsigned short*)srv_uc_folder_path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
        }
        return result;
    }
    else if ((result & FS_ATTR_DIR) == 0x0)
    {
        /* Not directory, just a same path and name non-folder file , do error handling Here */
        FS_Delete((WCHAR*) srv_uc_folder_path);

        result = FS_CreateDir((WCHAR*) srv_uc_folder_path);

        /* Disallow to enter UC if UC folder cannot be created. */
        if (result < 0)
        {
            /* MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_CHECK_UC_FOLDER_CREATE_FAIL_P1, result); */

        }
        else
        {
            FS_SetAttributes((unsigned short*)srv_uc_folder_path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
        }

        return result;
    }
    else
    {
        /* file exist */
        return result;

    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_container_dummy_initializer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_container_dummy_initializer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mms_message_data.header =
        (mma_mms_description_header_struct*)
        srv_mms_mem_mgr_viewer_asm_alloc(sizeof(mma_mms_description_header_struct));
#ifdef __MMI_MMS_SLIM_IT1__
    {
        ASSERT(g_mms_message_data.header);
    }
#endif /* __MMI_MMS_SLIM_IT1__ */ 
    memset(g_mms_message_data.header, 0, sizeof(mma_mms_description_header_struct));
    g_mms_message_data.header->header =
        (mma_mms_header_struct*) srv_mms_mem_mgr_viewer_asm_alloc(sizeof(mma_mms_header_struct));
#ifdef __MMI_MMS_SLIM_IT1__
    {
        ASSERT(g_mms_message_data.header->header);
    }
#endif /* __MMI_MMS_SLIM_IT1__ */ 
    memset(g_mms_message_data.header->header, 0, sizeof(mma_mms_header_struct));
    g_mms_message_data.body =
        (mma_mms_description_body_struct*) srv_mms_mem_mgr_viewer_asm_alloc(sizeof(mma_mms_description_body_struct));
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    {
        ASSERT(g_mms_message_data.body);
    }
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    memset(g_mms_message_data.body, 0, sizeof(mma_mms_description_body_struct));
    g_base_context.data_ready = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_container_change_struct_for_mma
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_container_change_struct_for_mma(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *obj = g_mms_message_data.body->objects;
    
    U16 id = APPLIB_MEM_AP_ID_MMS_VIEWER;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (obj != NULL)
    {
        if(obj->file_name)
		{
			srv_mms_mem_mgr_viewer_asm_free(obj->file_name);
            obj->file_name = NULL;
		}
		if(obj->file_path)
		{
			srv_mms_mem_mgr_viewer_asm_free(obj->file_path);
            obj->file_path = NULL;
		}
		if (obj->file_name_ucs)
        {
            U16 slen = (mmi_ucs2strlen((S8*) obj->file_name_ucs) + 1 ) * 3 ;

            obj->file_name = (S8*) srv_mms_mem_mgr_viewer_asm_alloc(slen);
            memset(obj->file_name, 0, slen);
            mmi_chset_ucs2_to_utf8_string(
                (kal_uint8*) obj->file_name,
                slen,
                (kal_uint8*) obj->file_name_ucs);
            srv_mms_convert_file_name_to_ascii(
                obj,
                srv_mms_mem_mgr_viewer_asm_alloc_ext,
                srv_mms_mem_mgr_viewer_asm_free_ext,
                (void*)&id);
        }
        if (obj->file_path_ucs && !obj->file_path)
        {
            U16 slen = (mmi_ucs2strlen((S8*) obj->file_path_ucs) + 1) * 3 ;

            obj->file_path = (S8*) srv_mms_mem_mgr_viewer_asm_alloc(slen);
            memset(obj->file_path, 0, slen);
            mmi_chset_ucs2_to_utf8_string(
                (kal_uint8*) obj->file_path,
                slen,
                (kal_uint8*) obj->file_path_ucs);
        }
        obj = obj->next;
    }
    g_mms_message_data.body->layout = srv_mms_slim_convert_mms_layout_type(g_mms_message_data.body->layout);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_slim_convert_mms_layout_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  layout_type     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mma_slide_layout_enum srv_mms_slim_convert_mms_layout_type(U8 layout_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MV_SUPPORT_LANDSCAPE_MODE__
    switch (layout_type)
    {
        case SRV_MMS_VIEWER_DRAWABLE_MEDIA_ON_TOP:
            return MMA_LAYOUT_IMAGE_ON_TOP;
        case SRV_MMS_VIEWER_DRAWABLE_MEDIA_ON_BOTTOM:
            return MMA_LAYOUT_TEXT_ON_TOP;
        case SRV_MMS_VIEWER_DRAWABLE_MEDIA_ON_LEFT:
            return MMA_LAYOUT_IMAGE_AT_LEFT;
        case SRV_MMS_VIEWER_DRAWABLE_MEDIA_ON_RIGHT:
            return MMA_LAYOUT_TEXT_AT_LEFT;
        default:
            return MMA_LAYOUT_IMAGE_ON_TOP;
    }
#else /* __MMI_MV_SUPPORT_LANDSCAPE_MODE__ */ 
    switch (layout_type)
    {
        case SRV_MMS_VIEWER_DRAWABLE_MEDIA_ON_TOP:
            return MMA_LAYOUT_IMAGE_ON_TOP;
        case SRV_MMS_VIEWER_DRAWABLE_MEDIA_ON_BOTTOM:
            return MMA_LAYOUT_TEXT_ON_TOP;
        case SRV_MMS_VIEWER_DRAWABLE_MEDIA_ON_LEFT:
            return MMA_LAYOUT_IMAGE_AT_LEFT;
        case SRV_MMS_VIEWER_DRAWABLE_MEDIA_ON_RIGHT:
            return MMA_LAYOUT_TEXT_AT_LEFT;
        default:
            return MMA_LAYOUT_IMAGE_ON_TOP;
    }
#endif /* __MMI_MV_SUPPORT_LANDSCAPE_MODE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_convert_mms_rr_to_mma_rr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  read_report     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_mms_read_reply_enum srv_mms_convert_mms_rr_to_mma_rr(BOOL read_report)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (read_report)
    {
        case 0:
            return MMA_MMS_READ_REPLY_NO;
        case 1:
            return MMA_MMS_READ_REPLY_YES;
        default:
            return MMA_MMS_READ_REPLY_NOT_SET;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_convert_mms_dr_to_mma_dr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  delivery_report     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_mms_delivery_report_enum srv_mms_convert_mms_dr_to_mma_dr(BOOL delivery_report)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (delivery_report)
    {
        case 0:
            return MMA_MMS_DELIVERY_REPORT_NO;
        case 1:
            return MMA_MMS_DELIVERY_REPORT_YES;
        default:
            return MMA_MMS_DELIVERY_REPORT_NOT_SET;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_convert_mms_vis_to_mma_vis
 * DESCRIPTION
 *  
 * PARAMETERS
 *  visibility      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_mms_sender_visibility_enum srv_mms_convert_mms_vis_to_mma_vis(BOOL visibility)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (visibility)
    {
        case 0:
            return MMA_MMS_SENDER_SHOW;
        case 1:
            return MMA_MMS_SENDER_HIDE;
        default:
            return MMA_MMS_SENDER_VISIBILITY_NOT_SET;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_check_if_exceed_MMS_size_limitation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance                            [IN]        
 *  size                                [IN]        
 *  fail_in_restricted_size_check       [?]         
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_check_if_exceed_MMS_size_limitation(U32 instance, U32 size, MMI_BOOL *fail_in_restricted_size_check)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MMI_BOOL flag_for_restricted_popup = (g_srv_mms_uc_supp.srv_msg.creation_mode == MMA_CREATION_MODE_RESTRICTED
                                          && mms_get_max_msg_size_in_restricted_mode() <=
                                          /* g_srv_mms_uc_supp.srv_msg.max_mms_size300*1024 */
                                          g_srv_mms_uc_settings.max_mms_size) ? MMI_TRUE : MMI_FALSE;
    U32 max_mms_size =
        (flag_for_restricted_popup) ? mms_get_max_msg_size_in_restricted_mode() :
        /* g_srv_mms_uc_supp.srv_msg.max_mms_size300*1024 */ g_srv_mms_uc_settings.max_mms_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (size <= max_mms_size)
    {
        *fail_in_restricted_size_check = MMI_FALSE;
        return MMI_FALSE;
    }
    else
    {
        *fail_in_restricted_size_check = flag_for_restricted_popup;
        return MMI_TRUE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_delete_all_slide_text_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_delete_all_slide_text_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *current_object = NULL;
    U32 file_path_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mms_message_data.body && g_mms_message_data.body->objects)
    {
        current_object = g_mms_message_data.body->objects;
        while (current_object)
        {
            if (current_object->type == MMA_MMS_OBJECT_TYPE_TEXT && current_object->is_virtual_file == MMI_FALSE)
            {
                if (current_object->file_path_ucs)
                {
                    FS_Delete((U16*) current_object->file_path_ucs);
                }
                else if (!current_object->file_path_ucs && current_object->file_path)
                {
                    file_path_len = strlen(current_object->file_path);
                    current_object->file_path_ucs =
                        (kal_wchar*) srv_mms_mem_mgr_viewer_asm_alloc((file_path_len + 1) * ENCODING_LENGTH);
                    memset(current_object->file_path_ucs, 0, (file_path_len + 1) * ENCODING_LENGTH);
                    mmi_chset_utf8_to_ucs2_string(
                        (kal_uint8*) current_object->file_path_ucs,
                        (kal_int32) ((file_path_len + 1) * ENCODING_LENGTH),
                        (kal_uint8*) current_object->file_path);
                    FS_Delete((U16*) current_object->file_path_ucs);
                    srv_mms_mem_mgr_viewer_asm_free(current_object->file_path_ucs);
					if(current_object->file_path)
					{
						srv_mms_mem_mgr_viewer_asm_free(current_object->file_path);
						current_object->file_path = NULL;
					}
                }
                else
                {
                    ASSERT(0);
                }

            }
            current_object = current_object->next;
        }
    }
}

//TODO : SD card handling

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_sd_plug_out_hdlr
 * DESCRIPTION
 *  Handler when memory card is removed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_composer_sd_plug_out_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	mma_mms_description_struct *des = srv_mms_container_get_content();
	mma_mms_slide_struct *slide = NULL;
    mma_mms_object_struct *object = NULL;
#ifndef __MMI_MMS_LT_NO_ATTACHMENT_SUPPORT__
	mma_mms_attachment_info_struct *att = NULL;
	mma_mms_attachment_info_struct *temp = NULL;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	if(des && des->body)
	{
		slide = des->body->slides;
#ifndef __MMI_MMS_LT_NO_ATTACHMENT_SUPPORT__
		att = des->body->attachment;
#endif

	}
	else
	{
		return;
	}
    

	if (g_base_context.open_mode != MMA_MODE_VIEW)
	{
	    
		while(slide)
		{
			/*********************** Image object in Memory card ******************/
			if (slide->img.object)
			{
				object = slide->img.object;

				if (!(object->is_virtual_file))
				{
					if (FS_GetAttributes((const WCHAR *)object->file_path_ucs) < 0)
					{
						if (slide->img.object->reference_count > 1)
						{
							slide->img.object->reference_count--;
						}
						else
						{
							srv_mms_delete_object_from_list(slide->img.object);
						}
						memset(&(slide->img), 0, sizeof(mma_mms_slide_object_struct));
					}
				}
			}

			/*********************** Audio object in Memory card ******************/

#ifndef __MMI_MMS_LT_NO_AUDIO_SUPPORT__
			if (slide->aud.object)
			{
				object = slide->aud.object;

				if (!(object->is_virtual_file))
				{
					if (FS_GetAttributes((const WCHAR *)object->file_path_ucs) < 0)
					{
						if (slide->aud.object->reference_count > 1)
						{
							slide->aud.object->reference_count--;
						}
						else
						{
							srv_mms_delete_object_from_list(slide->aud.object);
						}
						memset(&(slide->aud), 0, sizeof(mma_mms_slide_object_struct));
					}
				}
			}
#endif

			/*********************** Video object in Memory card ******************/

			if (slide->vid.object)
			{
				object = slide->vid.object;

				if (!(object->is_virtual_file))
				{
					if (FS_GetAttributes((const WCHAR *)object->file_path_ucs) < 0)
					{
						if (slide->vid.object->reference_count > 1)
						{
							slide->vid.object->reference_count--;
						}
						else
						{
							srv_mms_delete_object_from_list(slide->vid.object);
						}
						memset(&(slide->vid), 0, sizeof(mma_mms_slide_object_struct));
					}
				}
			}

		// Scan Next Slide for objects
		slide = slide->next;	
			
		}
			
	}
	else
	{
		return;
	}

/*********************** attachments Memory card ******************/
#ifndef __MMI_MMS_LT_NO_ATTACHMENT_SUPPORT__
	while(att)
	{
		object = att->object;
		if (!(object->is_virtual_file))
		{
			if (FS_GetAttributes((const WCHAR *)object->file_path_ucs) < 0)
			{
				temp = att;

				//Rearrange the attachment linked list;
				if (att->prev != NULL)
				{
					att->prev->next = att->next;
				}
				else
				{
					desc->body->attachment = att->next;
				}
				if (att->next != NULL)
				{
					att->next->prev = att->prev;
				}

				//Move to next attachment
				att = att->next;
				
				//Free the current attachment
				srv_mms_delete_object_from_list(temp->object);
				srv_mms_mem_mgr_viewer_asm_free(temp);
				temp = NULL;
			}
			else
			{
				//Move to next attachment
				att = att->next;
			}
		}
		else
		{
			//Move to next attachment
			att = att->next;
		}

	}
#endif

	srv_mms_update_msg_size();
	srv_mms_reset_layout_if_needed();
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_delete_all_slide_text_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_container_invert_layput(void)
{
	g_mms_message_data.body->layout = srv_mms_viewer_convert_mms_layout_type(g_mms_message_data.body->layout);
}
#if defined(__MMI_FTE_SUPPORT__)
void srv_mms_set_is_preview_from_cui(MMI_BOOL flag)
{
  g_umms_srv_app_preview_cui_flag = flag ;   

}
MMI_BOOL srv_mms_get_is_preview_from_cui()
{
  return g_umms_srv_app_preview_cui_flag;
}
#endif
#endif /* defined(__MMI_MMS_2__) && defined (__MMI_MMS_SIMPLIFIED_UI_SUPPORT__) */ 
#endif /* __MMI_MMSCONTEXTSRV_C */ 

