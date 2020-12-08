/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 * MmsMsgParseSrv.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

// #include "MMI_include.h"
#include "MMI_features.h"
#ifdef __MMI_MMS_2__
#include "MMIDataType.h"
#include "wgui_categories_MMS_viewer.h"
#include "string.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_rp_srv_mms_def.h"
#include "mmi_frm_timer_gprot.h"
#include "MMI_inet_app_trc.h"

#include "kal_trace.h"
#include "kal_general_types.h"
#include "Unicodexdcl.h"
#include "stdlib.h"
#include "fs_errcode.h"
#include "fs_type.h"
#include "FileMgrSrvGProt.h"
#include "fs_func.h"
#include "stdio.h"

#include "kal_public_defs.h" 
#include "mmi_frm_history_gprot.h"
#include "app_mem.h"
#include "UcSrvGprot.h"
#include "mms_sap_struct.h"

#ifdef __DRM_SUPPORT__
#include "Drm_def.h"
#include "Drm_gprot.h"
#endif /* __DRM_SUPPORT__ */ 
#include "app_str.h"
#include "App_mine.h"
#include "app_base64.h"
#include "Conversions.h"
// #include "mdi_datatype.h"

#ifdef __MMI_MMS_POSTCARD__
#include "app_oppostcard.h"

static void *srv_mms_mem_mgr_viewer_asm_alloc_postcard(U32 size, void *user_data);
static void srv_mms_mem_mgr_viewer_asm_free_postcard(void *mem, void *user_data);
#endif /* __MMI_MMS_POSTCARD__ */ 
#include "MmsSrvGprot.h"
#include "MmsSrvProt.h"
#include "MmsXMLTagsSrv.h"
#include "MMSMemoryManagerSrv.h"
#include "MmsMsgParseSrv.h"
#include "PhbSrvGprot.h"
#include "USBSrvGProt.h"
#include "MmsUseDetailSrv.h"
// #include "MMSAppSrvHdlr.h"
#include "MmsXMLDefSrv.h"

#include "app_usedetails.h"

#include "xml_def.h"
// #include "app_buff_alloc.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "gui_inputs.h"
#include "lcd_sw_inc.h"
#include "Gui_Setting.h"
#include "mma_api.h"

#include "drm_errcode.h"
#include "gui_switch.h"
#include "wgui.h"
#include "custom_phb_config.h"
#include "wap_adp.h"
#include "customer_email_num.h"
#include "mmi_frm_queue_gprot.h"
#include "stack_ltlcom.h" 
#include "string.h"
#include "MmsContextSrvLE.h"

#define SRV_MMS_DRM_PROCESS 0x11
#define SRV_MMS_XML_PARSE_PROCESS 0x12
#define SRV_MMS_USE_DETAIL_PROCESS 0x13
#define SRV_MMS_VIEWER_MAX_USE_DETAILS_WHOLE_SLIDE (20)

static srv_mms_xml_parser_context_struct *g_srv_mms_parser_cntx;

/* static srv_mms_xml_msg_viewer_data_struct *g_srv_mms_viewer_cntx; */
extern srv_mms_cntx_struct *g_srv_mms_cntx;

/* static p_srv_mms_viewer_object **srv_mms_viewer_object = NULL; */

/* DRM Process Context */
static srv_mms_drm_process_cntx_struct *g_srv_mms_drm_process_cntx;

/* Pointer to Ref Ids */
/* mma_mms_description_struct* srv_mms_get_desc_pointer(void); */

static void srv_mms_viewer_insert_object_to_attachment(
                mma_mms_object_struct *object,
                mma_mms_attachment_info_struct *attachment);
static mma_mms_attachment_info_struct *srv_mms_viewer_insert_attachment(mma_mms_attachment_info_struct **attachment);

#ifdef __MMI_MV_SUPPORT_REF_ID__
static MMI_BOOL srv_mms_check_ref_id_present(U16 id);
#endif 

static void srv_mms_viewer_insert_object_to_slide(mma_mms_object_struct *object, mma_mms_slide_struct *slide, srv_mms_viewer_object_type_enum object_type);   /* this function is used after match object is done */
void srv_mms_viewer_remove_inlined_attachments(mma_mms_description_body_struct *body);
void srv_mms_viewer_add_ref_ids_to_slide(mma_mms_slide_struct *cur_slide);
static MMI_BOOL srv_mms_xml_parse_match_object_id(mma_mms_description_body_struct *body);
void srv_mms_viewer_region_area_sanity_check(mma_mms_slide_struct *slide, srv_mms_viewer_slide_layout_enum layout);
U32 srv_mms_get_attachment_no(void);
MMI_BOOL srv_mms_viewer_check_for_ref_object(mma_mms_description_body_struct *body, mma_mms_object_struct *object);

BOOL srv_mms_compare_string_ignore_case(U16 *addr_1, U16 *addr_2);

static srv_mms_viewer_result_enum srv_mms_process_data(mma_mms_description_struct *description);

/* static mma_mms_object_struct * srv_mms_viewer_find_objects_from_id(U32 id); */

/**DRM RELATED**/
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
static void srv_mms_image_expired_callback(S32 result, S32 id);
static MMI_BOOL srv_mms_start_consume_rights_from_file(mma_mms_slide_object_struct *media, PU16 file_path);
static void srv_mms_update_rights_from_file(mma_mms_slide_object_struct *media);

#ifdef __MMI_MMS_WRAP_DRM_FL_CD__
static void srv_mms_video_expired_callback(S32 result, S32 id);
static void srv_mms_audio_expired_callback(S32 result, S32 id);
static MMI_BOOL srv_mms_start_consume_rights_from_cid(mma_mms_slide_object_struct *media);
static void srv_mms_update_rights_from_cid(mma_mms_slide_object_struct *media);
#endif /* __MMI_MMS_WRAP_DRM_FL_CD__ */ 

#endif
/**USE DETAIL RELATED**/
#ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
static srv_mms_viewer_result_enum srv_mms_viewer_generate_file_path(S32 *fs_ret, PU16 *file_path);
static void srv_mms_viewer_rsp_for_use_details_for_category_int(void);
static void srv_mms_viewer_sort_use_detail_list_for_category_int(void);
static void srv_mms_viewer_start_compute_use_details_int(void);
#endif /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
#ifdef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__
#ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
static void srv_mms_viewer_get_list_for_category(void);
static S32 srv_mms_viewer_fill_slide_data(S32 file_handle, applib_addr_type_enum detail_type, S32 size);
#endif /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
#ifndef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
static void srv_mms_viewer_mark_duplicate_address(applib_address_node_struct *addr_list);
#endif 
static MMI_BOOL srv_mms_viewer_sort_use_detail_list_for_category(void);
#else /* __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__ */ 
static void srv_mms_viewer_end_compute_use_details(void);
#endif /* __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__ */ 
static void srv_mms_free_use_details_lists(void);
#ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__

static srv_mms_viewer_result_enum srv_mms_calculate_use_details(void);
static void srv_mms_viewer_take_break(void);
static void srv_mms_get_new_offset_on_slide(
                S16 *size_num,
                S16 *size_email,
                S16 *size_url,
                applib_addr_type_enum type,
                S32 *curr_offset,
                mma_mms_slide_struct **current_slide);
static MMI_BOOL srv_mms_load_use_details(
                    applib_addr_type_enum type,
                    S32 curr_index,
                    S32 *start_index,
                    S32 *end_index);
static MMI_BOOL srv_mms_get_offset_on_next_slide(
                    S32 file_handle,
                    S16 *size_num,
                    S16 *size_email,
                    S16 *size_url,
                    applib_addr_type_enum type,
                    S32 *curr_offset,
                    mma_mms_slide_struct **current_slide);
static U8 srv_mms_get_use_details_ready(void);
#endif /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
#ifndef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
#ifndef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__
static void srv_mms_viewer_get_urls_on_slide(void);
static void srv_mms_viewer_get_emails_on_slide(void);
static void srv_mms_viewer_get_numbers_on_slide(void);
static MMI_BOOL srv_mms_viewer_start_compute_use_details(U32 index);
#endif /* __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__ */ 
#endif /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
static void srv_mms_get_use_details_deinit(void);
#ifndef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__
static void srv_mms_send_get_use_details_rsp(void);
#endif
static srv_mms_container_struct *srv_mms_search_instance(U32 uid);
MMI_BOOL srv_mms_reset_instance(U32 uid);
static srv_mms_container_struct g_srv_mms_instances_container[SRV_MMS_VIEWER_MAX_CONTAINER_SIZE];

static srv_mms_use_details_struct *g_srv_mms_use_details_cntx;

static kal_uint8 g_srv_curr_msg_type;

#ifdef __MMI_MMS_MV_SUPPORT_PARAM_OF_REGION__
static void srv_mms_viewer_free_region_data(void);
#endif 



#ifdef __DRM_SUPPORT__
static MMI_BOOL g_srv_drm_with_nr;
#endif 
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
static srv_mms_rights_expiry_notify_cb g_expiry_cb;
static void *g_drm_user_data;
#endif
mma_mms_description_struct *g_desc = NULL;
srv_mms_viewer_obj_container_struct **g_mms_obj_container;
static MMI_BOOL srv_mms_is_valid_phoneno_wchar_int(U16 ch, MMI_BOOL is_written_char_valid);
static void srv_mms_viewer_free_slide_data(mma_mms_slide_struct *slide);
static void srv_mms_viewer_free_attachment_data(mma_mms_attachment_info_struct *attachment);

#ifdef __MMI_MV_SUPPORT_REF_ID__
void srv_mms_viewer_free_ref_data(mma_mms_slide_ref_object_struct *list);
#endif 
void srv_mms_viewer_free_object_data(mma_mms_object_struct *obj);

static U32 srv_mms_viewer_get_txt_utf_len(void);

static U32 srv_mms_viewer_get_txt_ucs_len(void);




/*****************************************************************************
 * FUNCTION
 *  srv_mms_search_instance
 * DESCRIPTION
 *  
 * PARAMETERS
 *  uid     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_mms_container_struct *srv_mms_search_instance(U32 uid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_container_struct *instance;
    srv_mms_instance_context_struct *inst = srv_mms_get_instance(uid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(inst);
    instance = &inst->view_container;
    return instance;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_reset_instance
 * DESCRIPTION
 *  
 * PARAMETERS
 *  uid     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_reset_instance(U32 uid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < SRV_MMS_VIEWER_MAX_CONTAINER_SIZE; index++)
    {
        if (g_srv_mms_instances_container[index].uid == uid)
        {
            memset(&g_srv_mms_instances_container[index], 0, sizeof(srv_mms_container_struct));
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_initialize_with_instance
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_mms_container_struct *srv_mms_initialize_with_instance(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_container_struct *instance;
    srv_mms_instance_context_struct *inst = srv_mms_get_instance(index);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(inst);
    instance = &inst->view_container;
    if (instance == NULL)
    {
        return instance;
    }
    g_srv_mms_parser_cntx = &instance->data;
    g_desc = &instance->description;
    g_srv_mms_drm_process_cntx = &instance->drm_cntx;
    g_srv_mms_use_details_cntx = &instance->use_detail_data;
    
    
    
    g_mms_obj_container = &instance->obj_contaner;
    return instance;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_process_data_init
 * DESCRIPTION
 *  start xml file parsing
 * PARAMETERS
 *  description     [?]     
 *  req             [?]     [?]
 *  process     [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
srv_mms_viewer_result_enum srv_mms_process_data_init(
                            mma_mms_description_struct *description,
                            srv_mms_xml_parse_req_struct *req)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_viewer_result_enum result = SRV_MMS_VIEWER_OK;
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    MMI_BOOL copy_result = MMI_FALSE;
	U16 id = APPLIB_MEM_AP_ID_MMS_VIEWER;
#endif
    /* flags currently unused */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    

    if (req->index == 0)
    {
        req->index = SRV_MMS_INSTANCE_DEFAULT_INDEX;
    }
    srv_mms_mem_mgr_copy_pools(req->index, APPLIB_MEM_AP_ID_MMS_VIEWER);
    srv_mms_initialize_with_instance(req->index);
    memset(g_srv_mms_parser_cntx, 0, sizeof(srv_mms_xml_parser_context_struct));
	g_srv_mms_parser_cntx->slide_txt_buffer = srv_mms_mem_mgr_viewer_asm_alloc(srv_mms_viewer_get_txt_ucs_len() + 1 * ENCODING_LENGTH);
    g_srv_mms_parser_cntx->src_buffer = srv_mms_mem_mgr_viewer_asm_alloc(srv_mms_viewer_get_txt_utf_len() + 1);
    g_srv_mms_parser_cntx->inputbox_buffer = srv_mms_mem_mgr_viewer_asm_alloc(SRV_MMS_VIEWER_MAIN_TXT_BUFFER_SIZE * ENCODING_LENGTH);
#ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
    g_srv_mms_parser_cntx->use_detail_buffer = srv_mms_mem_mgr_viewer_asm_alloc(SRV_MMS_TXT_BUF_UCS2_SIZE + 1 * ENCODING_LENGTH);
#endif 
    /* Should ASSERT here instead? */
    if (g_srv_mms_parser_cntx->slide_txt_buffer == NULL
        || g_srv_mms_parser_cntx->src_buffer == NULL || g_srv_mms_parser_cntx->inputbox_buffer == NULL
#ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
        || g_srv_mms_parser_cntx->use_detail_buffer == NULL
#endif 
        )
    {
        result = SRV_MMS_VIEWER_OUT_OF_MEM;
        return result;
    }

    memset(g_desc, 0, sizeof(mma_mms_description_struct));
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    g_desc->body =
        (mma_mms_description_body_struct*) srv_mms_mem_mgr_viewer_asm_alloc(sizeof(mma_mms_description_body_struct));
    if (g_desc->body == NULL)
    {
        result = SRV_MMS_VIEWER_OUT_OF_MEM;
        return result;
    }
    memset(g_desc->body, 0, sizeof(mma_mms_description_body_struct));
    id = APPLIB_MEM_AP_ID_MMS_VIEWER;
    copy_result = srv_mms_container_copy_body(
                    (mma_mms_description_body_struct*) description->body,
                    g_desc->body,
                    srv_mms_mem_mgr_viewer_asm_alloc_ext,
                    srv_mms_mem_mgr_viewer_asm_free_ext,
                    (void*)&id);
    if (copy_result == MMI_FALSE)
    {
        result = SRV_MMS_VIEWER_OUT_OF_MEM;
        return result;
    }
#else /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    g_desc->body = description->body;
    g_desc->header = description->header;
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 

    g_srv_mms_parser_cntx->ptxtbuffersize = srv_mms_viewer_get_txt_ucs_len();
    memset(g_srv_mms_parser_cntx->slide_txt_buffer, 0, srv_mms_viewer_get_txt_ucs_len() + 1 * ENCODING_LENGTH);
    memset(g_srv_mms_parser_cntx->src_buffer, 0, srv_mms_viewer_get_txt_utf_len()+ 1);
    memset(g_srv_mms_parser_cntx->inputbox_buffer, 0, SRV_MMS_VIEWER_MAIN_TXT_BUFFER_SIZE * ENCODING_LENGTH);
#ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
    memset(g_srv_mms_parser_cntx->use_detail_buffer, 0, SRV_MMS_TXT_BUF_UCS2_SIZE + 1 * ENCODING_LENGTH);
#endif 
    result = srv_mms_process_data(g_desc);
    if (result == SRV_MMS_VIEWER_OK)
    {
        srv_mms_xml_parse_match_object_id(g_desc->body);
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_slide_txt_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
PU8 srv_mms_get_slide_txt_buffer()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_srv_mms_parser_cntx->slide_txt_buffer, 0, srv_mms_viewer_get_txt_ucs_len() + 1 * ENCODING_LENGTH);
    return g_srv_mms_parser_cntx->slide_txt_buffer;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_ptxt_buffer_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_mms_get_ptxt_buffer_size()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_mms_parser_cntx->ptxtbuffersize;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_pinputbox_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
PU8 srv_mms_get_pinputbox_buffer()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_mms_parser_cntx->inputbox_buffer;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_is_attachment_in_mms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_viewer_is_attachment_in_mms()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_desc->body->attachment)
    {
        return MMI_TRUE;
    }
    else
        return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_fill_data_from_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  rsp         [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_viewer_fill_data_from_index(U32 index, srv_mms_xml_parse_rsp_struct *rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_container_struct *instance = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_initialize_with_instance(index);
    instance = srv_mms_search_instance(index);
    g_srv_mms_parser_cntx = &instance->data;
	if(g_desc->body)
	{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
    srv_mms_mem_mgr_copy_pools(index, APPLIB_MEM_AP_ID_MMS_VIEWER);
	srv_mms_mem_mgr_copy_pools(index, APPLIB_MEM_AP_ID_UMMS);
	}
	else
	{
		srv_mms_delete_instance(index);
	}

}

/* Attachment Related */


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_insert_object_to_attachment
 * DESCRIPTION
 *  inserts object to attachment
 * PARAMETERS
 *  object          [IN]        
 *  attachment      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mms_viewer_insert_object_to_attachment(
                mma_mms_object_struct *object,
                mma_mms_attachment_info_struct *attachment)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    attachment->object = object;
    object->reference_count++;

    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_insert_attachment
 * DESCRIPTION
 *  create & insert attachment object
 * PARAMETERS
 *  attachment      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mma_mms_attachment_info_struct *srv_mms_viewer_insert_attachment(mma_mms_attachment_info_struct **attachment)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_attachment_info_struct *new_attach = NULL;
    U32 attach_size;
    U32 i = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    attach_size = sizeof(mma_mms_attachment_info_struct);
    new_attach = srv_mms_mem_mgr_viewer_asm_alloc(attach_size);

    if (!new_attach)
    {
        return NULL;
    }

    memset(new_attach, 0, attach_size);
    if (!(*attachment))
    {
        *attachment = new_attach;
        new_attach->next = NULL;
    }
    else
    {
        mma_mms_attachment_info_struct *cur_attach = *attachment;

        ASSERT(cur_attach);
        for (; cur_attach->next != NULL; cur_attach = cur_attach->next)
        {
            i++;
        }
        cur_attach->next = new_attach;
        new_attach->next = NULL;
        new_attach->prev = cur_attach;
    }
    return new_attach;
}

/* Attachment Related End */

/* Slide Related */


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_convert_mms_layout_type
 * DESCRIPTION
 *  convert mms layout from MMA to WGUI format
 * PARAMETERS
 *  layout_type     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_mms_viewer_slide_layout_enum srv_mms_viewer_convert_mms_layout_type(U8 layout_type)
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
        case MMA_LAYOUT_IMAGE_ON_TOP:
            return SRV_MMS_VIEWER_DRAWABLE_MEDIA_ON_TOP;
        case MMA_LAYOUT_TEXT_ON_TOP:
            return SRV_MMS_VIEWER_DRAWABLE_MEDIA_ON_BOTTOM;
        case MMA_LAYOUT_IMAGE_AT_LEFT:
            return SRV_MMS_VIEWER_DRAWABLE_MEDIA_ON_LEFT;
        case MMA_LAYOUT_TEXT_AT_LEFT:
            return SRV_MMS_VIEWER_DRAWABLE_MEDIA_ON_RIGHT;
        default:
            return SRV_MMS_VIEWER_DRAWABLE_MEDIA_ON_TOP;
    }
#else /* __MMI_MV_SUPPORT_LANDSCAPE_MODE__ */ 
    switch (layout_type)
    {
        case MMA_LAYOUT_IMAGE_ON_TOP:
            return SRV_MMS_VIEWER_DRAWABLE_MEDIA_ON_TOP;
        case MMA_LAYOUT_TEXT_ON_TOP:
            return SRV_MMS_VIEWER_DRAWABLE_MEDIA_ON_BOTTOM;
        case MMA_LAYOUT_IMAGE_AT_LEFT:
            return SRV_MMS_VIEWER_DRAWABLE_MEDIA_ON_TOP;
        case MMA_LAYOUT_TEXT_AT_LEFT:
            return SRV_MMS_VIEWER_DRAWABLE_MEDIA_ON_BOTTOM;
        default:
            return SRV_MMS_VIEWER_DRAWABLE_MEDIA_ON_TOP;
    }
#endif /* __MMI_MV_SUPPORT_LANDSCAPE_MODE__ */ 
}

/* Slide Related End */

/* Object Related */


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_insert_object_to_slide
 * DESCRIPTION
 *  insert object to slide
 * PARAMETERS
 *  object          [IN]        
 *  slide           [IN]        
 *  object_type     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mms_viewer_insert_object_to_slide(
                mma_mms_object_struct *object,
                mma_mms_slide_struct *slide,
                srv_mms_viewer_object_type_enum object_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (object_type)
    {
        case MMA_MMS_OBJECT_TYPE_IMAGE:
            object->reference_count++;
            break;
        case MMA_MMS_OBJECT_TYPE_AUDIO:
            object->reference_count++;
            break;
        case MMA_MMS_OBJECT_TYPE_VIDEO:
            object->reference_count++;
            break;
        case MMA_MMS_OBJECT_TYPE_TEXT:
            object->reference_count++;
            break;
        default:
            ASSERT(0);
    }
}

#ifdef __MMI_MV_SUPPORT_REF_ID__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_remove_inlined_attachments
 * DESCRIPTION
 *  
 * PARAMETERS
 *  body        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_viewer_remove_inlined_attachments(mma_mms_description_body_struct *body)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_attachment_info_struct *first = body->attachment, *temp = NULL;
    mma_mms_attachment_info_struct *second;
    MMI_BOOL flag = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* We leak memory in this function, we'll delete the whole pool later */

    /* find first valid attachment & reset head pointer */
    while (first)
    {
        if (first->object->type == MMA_MMS_OBJECT_TYPE_ATTACHMENT)
        {

            body->attachment = first;
            body->attachment->prev = NULL;
            flag = MMI_TRUE;
            break;
        }
        temp = first;
        first = first->next;
        srv_mms_mem_mgr_viewer_asm_free(temp);
        temp = NULL;
    }

    if (flag == MMI_FALSE)
    {
        /* We checked all items but didn't find an attachment */
        MMI_ASSERT(first == NULL);
        body->attachment = NULL;
        return;
    }

    /* first is already a valid attachment */
    while (first)
    {
        second = first->next;

        while (second)
        {
            if (second->object->type == MMA_MMS_OBJECT_TYPE_ATTACHMENT)
            {
                first->next = second;
                break;
            }
            else
            {
                first->next = NULL;
                temp = second;
                second = second->next;
                srv_mms_mem_mgr_viewer_asm_free(temp);
                temp = NULL;
            }
        }

        first = first->next;
    }
    first = body->attachment;
    first->prev = NULL;
    second = first->next;
    /* correct prv pointers */
    while (second)
    {
        second->prev = first;
        if (first->next == NULL)
        {
            break;
        }
        first = first->next;
        second = second->next;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_add_ref_ids_to_slide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cur_slide       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_viewer_add_ref_ids_to_slide(mma_mms_slide_struct *cur_slide)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_slide_ref_object_struct *list_ref_id_tags;
    S8 ext[4] = { 't', 'x', 't', '\0' };
    applib_mime_type_enum mime_type = MIME_TYPE_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ASSERT(srv_mms_viewer_ref_id_table[slide_num]); */
    /* List of ref ids on slide is ready */

    list_ref_id_tags = cur_slide->ref_items;

    /* iterate ref ids list and try to insert any */
    while (list_ref_id_tags)
    {
        /* find file's mime type */
        mma_mms_object_struct *object = list_ref_id_tags->object;
        applib_mime_type_struct *type;

        type = applib_mime_get_file_type((U16*) (object->file_name_ucs));
        /* don't go down if we don't have the MIME type or object is DRM, attachments are not DRM processed */
        if (!type /* || object->drm_type != 0 */ )
        {
            list_ref_id_tags = list_ref_id_tags->next;
            continue;
        }
    #ifdef __DRM_SUPPORT__
        if (object->drm_type != 0)
        {
            mime_type = object->mime_type;
        }
        else
    #endif /* __DRM_SUPPORT__ */ 
        {
            mime_type = type->mime_type;
        }
        switch (mime_type)
        {
            case MIME_TYPE_TEXT:
                if (strncmp(ext, type->file_ext, 4) == 0)
                {
                    if (cur_slide->txt.id == 0 && object->size < srv_mms_viewer_get_txt_utf_len())
                    {
                    #ifdef __MMI_MMS_MV_SUPPORT_PARAM_OF_REGION__
                        if (list_ref_id_tags->region_area != NULL &&
                            (list_ref_id_tags->region_area->w.value == 0 ||
                             list_ref_id_tags->region_area->h.value == 0))
                        {
                            break;
                        }
                    #endif /* __MMI_MMS_MV_SUPPORT_PARAM_OF_REGION__ */ 
                        cur_slide->txt.id = list_ref_id_tags->id;
                        cur_slide->txt.begin = list_ref_id_tags->begin;
                        cur_slide->txt.end = list_ref_id_tags->end;
                        if (list_ref_id_tags->bg_color != 0 || list_ref_id_tags->fg_color != 0)
                        {
                            cur_slide->txt.bg_color = list_ref_id_tags->bg_color;
                            cur_slide->txt.fg_color = list_ref_id_tags->fg_color;
                        }
                        else
                        {
                            cur_slide->txt.bg_color = SRV_MMS_VIEWER_DEFAULT_BG_COLOR;  // TODO: check if other default color
                            cur_slide->txt.fg_color = SRV_MMS_VIEWER_DEFAULT_FG_COLOR;  // TODO: check if other default color
                        }

                        cur_slide->txt.text_style = list_ref_id_tags->text_style;

                        if (list_ref_id_tags->text_size)
                        {
                            cur_slide->txt.text_size = list_ref_id_tags->text_size - 1;
                        }
                        else
                        {
                            cur_slide->txt.text_size = 1;
                        }
                        if (list_ref_id_tags->alt)
                        {
                            mmi_ucs2ncpy(
                                (S8*) cur_slide->txt.alt,
                                (S8*) list_ref_id_tags->alt,
                                SRV_MMS_VIEWER_MAX_ALT_STR_LEN * ENCODING_LENGTH);
                        }
                        object->type = MMA_MMS_OBJECT_TYPE_TEXT;
                        (*g_mms_obj_container)[cur_slide->slide_num - 1].obj_count++;
                        cur_slide->txt.object = list_ref_id_tags->object;

                    }
                }
                break;
            case MIME_TYPE_IMAGE:
                if (cur_slide->img.id == 0 && cur_slide->vid.id == 0)
                {
                #ifdef __MMI_MMS_MV_SUPPORT_PARAM_OF_REGION__
                    if (list_ref_id_tags->region_area != NULL &&
                        (list_ref_id_tags->region_area->w.value == 0 || list_ref_id_tags->region_area->h.value == 0))
                    {
                        break;
                    }
                #endif /* __MMI_MMS_MV_SUPPORT_PARAM_OF_REGION__ */ 
                    cur_slide->img.id = list_ref_id_tags->id;
                    cur_slide->img.begin = list_ref_id_tags->begin;
                    cur_slide->img.end = list_ref_id_tags->end;
                    if (list_ref_id_tags->alt)
                    {

                        mmi_ucs2ncpy(
                            (S8*) cur_slide->img.alt,
                            (S8*) list_ref_id_tags->alt,
                            SRV_MMS_VIEWER_MAX_ALT_STR_LEN * ENCODING_LENGTH);
                    }
                    object->type = MMA_MMS_OBJECT_TYPE_IMAGE;
                    (*g_mms_obj_container)[cur_slide->slide_num - 1].obj_count++;
                    cur_slide->img.object = list_ref_id_tags->object;

                }
                break;
            case MIME_TYPE_AUDIO:
                if (cur_slide->aud.id == 0 && cur_slide->vid.id == 0)
                {
                    cur_slide->aud.id = list_ref_id_tags->id;
                    cur_slide->aud.begin = list_ref_id_tags->begin;
                    cur_slide->aud.end = list_ref_id_tags->end;
                    object->type = MMA_MMS_OBJECT_TYPE_AUDIO;
                    (*g_mms_obj_container)[cur_slide->slide_num - 1].obj_count++;
                    cur_slide->aud.object = list_ref_id_tags->object;
                }
                break;
            case MIME_TYPE_VIDEO:
                /* vid shouldn't be played if inline aud */
                if (cur_slide->vid.id == 0 && cur_slide->aud.id == 0 && cur_slide->img.id == 0)
                {
                #ifdef __MMI_MMS_MV_SUPPORT_PARAM_OF_REGION__
                    if (list_ref_id_tags->region_area != NULL &&
                        (list_ref_id_tags->region_area->w.value == 0 || list_ref_id_tags->region_area->h.value == 0))
                    {
                        break;
                    }
                #endif /* __MMI_MMS_MV_SUPPORT_PARAM_OF_REGION__ */ 
                    cur_slide->vid.id = list_ref_id_tags->id;
                    cur_slide->vid.begin = list_ref_id_tags->begin;
                    cur_slide->vid.end = list_ref_id_tags->end;
                    if (list_ref_id_tags->alt)
                    {

                        mmi_ucs2ncpy(
                            (S8*) cur_slide->vid.alt,
                            (S8*) list_ref_id_tags->alt,
                            SRV_MMS_VIEWER_MAX_ALT_STR_LEN * ENCODING_LENGTH);
                    }
                    object->type = MMA_MMS_OBJECT_TYPE_VIDEO;
                    cur_slide->vid.object = list_ref_id_tags->object;
                    (*g_mms_obj_container)[cur_slide->slide_num - 1].obj_count++;

                }
                break;
            default:
                break;
        }
        list_ref_id_tags->object = NULL;
        list_ref_id_tags = list_ref_id_tags->next;
    }
}

#endif /* __MMI_MV_SUPPORT_REF_ID__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_xml_parse_match_object_id
 * DESCRIPTION
 *  match objects with slide object ids
 * PARAMETERS
 *  body        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_mms_xml_parse_match_object_id(mma_mms_description_body_struct *body)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_slide_struct *cur_slide = body->slides;
    U32 slide_num = 0;
    mma_mms_object_struct *cur_object = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; cur_slide != NULL; cur_slide = cur_slide->next, slide_num++)
    {
        if (cur_slide->txt.id)
        {
            cur_object = cur_slide->txt.object;
            ASSERT(cur_object);
            /* if size is too large don't insert */
            if (cur_object->size > srv_mms_viewer_get_txt_utf_len())
            {
				#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
                    srv_mms_base_data_struct *b_data = (srv_mms_base_data_struct *)srv_mms_get_mms_info_data();
                      if(b_data->open_mode == MMA_MODE_VIEW)
                 #endif
					  {
                MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_SLIDE_HAS_LARGE_TEXT);
                cur_slide->txt.str_id = STR_ID_MMS_VIEWER_TEXT_STRIPPED ;
                /* Text To Large To Display: To Use First Save From 'Save Object' */
            }
            }
        #ifdef __MMI_MMS_MV_SUPPORT_PARAM_OF_REGION__
            if (cur_slide->txt.region_area &&
                (cur_slide->txt.region_area->w.value == 0 || cur_slide->txt.region_area->h.value == 0))
            {
                mma_mms_attachment_info_struct *att;

                cur_slide->txt.id = 0;
                cur_object->type = MMA_MMS_OBJECT_TYPE_ATTACHMENT;
                att = srv_mms_viewer_insert_attachment(&(body->attachment));
                srv_mms_viewer_insert_object_to_attachment(cur_object, att);
            }
            else
        #endif /* __MMI_MMS_MV_SUPPORT_PARAM_OF_REGION__ */ 
            {
                srv_mms_viewer_insert_object_to_slide(cur_object, cur_slide, SRV_MMS_OBJECT_TYPE_TEXT);
                cur_object->type = MMA_MMS_OBJECT_TYPE_TEXT;
                (*g_mms_obj_container)[cur_slide->slide_num - 1].obj_count++;
            }
        }

        if (cur_slide->img.id)
        {
            cur_object = cur_slide->img.object;
            ASSERT(cur_object);
        #ifdef __MMI_MMS_MV_SUPPORT_PARAM_OF_REGION__
            if (cur_slide->img.region_area &&
                (cur_slide->img.region_area->w.value == 0 || cur_slide->img.region_area->h.value == 0))
            {
                mma_mms_attachment_info_struct *att;

                cur_slide->img.id = 0;
                cur_object->type = MMA_MMS_OBJECT_TYPE_ATTACHMENT;
                att = srv_mms_viewer_insert_attachment(&(body->attachment));
                srv_mms_viewer_insert_object_to_attachment(cur_object, att);
            }
            else
        #endif /* __MMI_MMS_MV_SUPPORT_PARAM_OF_REGION__ */ 
            {
                cur_object->type = MMA_MMS_OBJECT_TYPE_IMAGE;
                srv_mms_viewer_insert_object_to_slide(cur_object, cur_slide, SRV_MMS_OBJECT_TYPE_IMAGE);
                (*g_mms_obj_container)[cur_slide->slide_num - 1].obj_count++;
            }
        }

        if (cur_slide->aud.id)
        {
            cur_object = cur_slide->aud.object;
            ASSERT(cur_object);
            cur_object->type = MMA_MMS_OBJECT_TYPE_AUDIO;
            srv_mms_viewer_insert_object_to_slide(cur_object, cur_slide, SRV_MMS_OBJECT_TYPE_AUDIO);
            (*g_mms_obj_container)[cur_slide->slide_num - 1].obj_count++;
        }

        if (cur_slide->vid.id)
        {
            cur_object = cur_slide->vid.object;
            ASSERT(cur_object);
        #ifdef __MMI_MMS_MV_SUPPORT_PARAM_OF_REGION__
            if (cur_slide->vid.region_area &&
                (cur_slide->vid.region_area->w.value == 0 || cur_slide->vid.region_area->h.value == 0))
            {
                mma_mms_attachment_info_struct *att;

                cur_slide->vid.id = 0;
                cur_object->type = MMA_MMS_OBJECT_TYPE_ATTACHMENT;
                att = srv_mms_viewer_insert_attachment(&(body->attachment));
                srv_mms_viewer_insert_object_to_attachment(cur_object, att);
            }
            else
        #endif /* __MMI_MMS_MV_SUPPORT_PARAM_OF_REGION__ */ 
            {
                cur_object->type = MMA_MMS_OBJECT_TYPE_VIDEO;
                srv_mms_viewer_insert_object_to_slide(cur_object, cur_slide, SRV_MMS_OBJECT_TYPE_VIDEO);
                (*g_mms_obj_container)[cur_slide->slide_num - 1].obj_count++;
            }

        }
    #ifdef __MMI_MV_SUPPORT_REF_ID__
        srv_mms_viewer_add_ref_ids_to_slide(cur_slide);
    #endif 
    }
#ifdef __MMI_MV_SUPPORT_REF_ID__
    srv_mms_viewer_remove_inlined_attachments(body);
#endif 
#ifdef __MMI_MMS_MV_SUPPORT_PARAM_OF_REGION__
    srv_mms_viewer_region_area_sanity_check(body->slides, body->layout);
#endif 
    return MMI_TRUE;
}

#ifdef __MMI_MMS_MV_SUPPORT_PARAM_OF_REGION__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_region_area_sanity_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  slide       [?]         
 *  layout      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_viewer_region_area_sanity_check(mma_mms_slide_struct *slide, srv_mms_viewer_slide_layout_enum layout)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_area_struct *region[2] = {0, };
    mma_mms_slide_struct *cur_slide = slide;
    U32 area = 0;
    S32 cat_x = 0;
    S32 cat_y = 0;
    S32 cat_w = 0;
    S32 cat_h = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* srv_mms_viewer_slide_layout_enum layout =srv_mms_viewer_convert_mms_layout_type(temp); */
    wgui_cat630_get_viewer_area_info(&cat_x, &cat_y, &cat_w, &cat_h, TRUE);
    for (; cur_slide != NULL; cur_slide = cur_slide->next)
    {
        region[0] = NULL;
        region[1] = NULL;
        area = 0;
        if (cur_slide->txt.id && cur_slide->txt.region_area)
        {
            region[area++] = cur_slide->txt.region_area;
        }
        if (cur_slide->img.id && cur_slide->img.region_area)
        {
            region[area++] = cur_slide->img.region_area;
        }
        if (cur_slide->vid.id && cur_slide->vid.region_area)
        {
            region[area++] = cur_slide->vid.region_area;
        }

        /* commom sanity for portrait and landscape  */

        if (region[0])
        {
            /* if no width reported or width is greater then screen size */
            if (region[0]->w.value == 0xFFFF || region[0]->w.value > cat_w)
            {
                region[0]->w.value = cat_w;
            }
            /* if no height reported or height is greater then screen size */
            if (region[0]->h.value == 0xFFFF || region[0]->h.value > cat_h)
            {
                region[0]->h.value = cat_h;
            }
            if (region[0]->x.value > cat_w)
            {
                region[0]->x.value = cat_w;
            }
            if (region[0]->y.value > cat_h)
            {
                region[0]->y.value = cat_h;
            }
        }

        if (region[1])
        {
            /* if no width reported or width is greater then screen size */
            if (region[1]->w.value == 0xFFFF || region[1]->w.value > cat_w)
            {
                region[1]->w.value = cat_w;
            }
            /* if no height reported or height is greater then screen size */
            if (region[1]->h.value == 0xFFFF || region[1]->h.value > cat_h)
            {
                region[1]->h.value = cat_h;
            }

            if (region[1]->x.value > cat_w)
            {
                region[1]->x.value = cat_w;
            }

            if (region[1]->y.value > cat_h)
            {
                region[1]->y.value = cat_h;
            }
        }
        if (region[0] == NULL || region[1] == NULL)
        {
            /* The other region will be taken into account, sanity already done */
            continue;
        }
        /* if width or height of a region is 0. It should not be shown */
        if (region[0]->w.value == 0 || region[0]->h.value == 0 || region[1]->w.value == 0 || region[1]->h.value == 0)
        {
            /* already moved to attachment */
            /* If any of the two region's width or height is 0, the other region's will be taken into consideration  */
            /* Sanity for greater then screen size already done for both region */
            /*  "top"(y) and "left"(x) checked for sanity for screen size. */
            continue;
        }
        /* Landscape specific sanity check  */
        if (layout == SRV_MMS_VIEWER_DRAWABLE_MEDIA_ON_LEFT || layout == SRV_MMS_VIEWER_DRAWABLE_MEDIA_ON_RIGHT)
        {
            if (((region[0]->w.value + region[0]->x.value) > cat_w) ||
                ((region[0]->w.value + region[1]->w.value) > cat_w) ||
                ((region[1]->w.value + region[1]->x.value) > cat_w))
            {
                /* Region overlap, make width 50-50 */
                /* top and left  checked for screen size. sanity for screen size done for height */
                region[0]->w.value = region[1]->w.value = cat_w / 2;
                region[0]->h.value = region[1]->h.value = cat_h;
                region[0]->y.value = region[1]->y.value = 0;
                if (region[0]->x.value > region[1]->x.value)
                {
                    region[0]->x.value = cat_w / 2;
                    region[1]->x.value = 0;
                }
                else
                {
                    region[1]->x.value = cat_w / 2;
                    region[0]->x.value = 0;
                }
                continue;
            }

            /* Take left into consideration for check overlapping */
            /* Assumption : In landscape x0 and x1 can not be equal  */
            if (region[0]->x.value < region[1]->x.value)
            {
                if (region[0]->x.value + region[0]->w.value > region[1]->x.value)
                {
                    /* region overlap */
                    /* top checked for screen size. Sanity for height done for screen size */
                    region[0]->w.value = region[1]->w.value = cat_w / 2;
                    region[0]->w.value = region[1]->w.value = cat_w / 2;
                    region[0]->h.value = region[1]->h.value = cat_h;
                    region[0]->y.value = region[1]->y.value = 0;
                    if (region[0]->x.value > region[1]->x.value)
                    {
                        region[0]->x.value = cat_w / 2;
                        region[1]->x.value = 0;
                    }
                    else
                    {
                        region[1]->x.value = cat_w / 2;
                        region[0]->x.value = 0;
                    }
                    continue;
                }
            }

            if (region[1]->x.value < region[0]->x.value)
            {
                if (region[1]->x.value + region[1]->w.value > region[0]->x.value)
                {
                    /* region overlap */
                    /* top checked for screen size. Sanity for height done for screen size */
                    region[0]->w.value = region[1]->w.value = cat_w / 2;
                    region[0]->w.value = region[1]->w.value = cat_w / 2;
                    region[0]->h.value = region[1]->h.value = cat_h;
                    region[0]->y.value = region[1]->y.value = 0;
                    if (region[0]->x.value > region[1]->x.value)
                    {
                        region[0]->x.value = cat_w / 2;
                        region[1]->x.value = 0;
                    }
                    else
                    {
                        region[1]->x.value = cat_w / 2;
                        region[0]->x.value = 0;
                    }
                    continue;
                }
            }
            continue;
        }
        /* Portrait specific sanity check */
        if ((layout == SRV_MMS_VIEWER_DRAWABLE_MEDIA_ON_TOP) || (layout == SRV_MMS_VIEWER_DRAWABLE_MEDIA_ON_BOTTOM))
        {
            if (((region[0]->h.value + region[0]->y.value) > cat_h) ||
                ((region[0]->h.value + region[1]->h.value) > cat_h) ||
                ((region[1]->h.value + region[1]->y.value) > cat_h))
            {
                /* Region overlap, make height 50-50 */
                /* top and left checked for screen size. sanity for screen size done for width */
                region[0]->h.value = region[1]->h.value = cat_h / 2;
                region[0]->w.value = region[1]->w.value = cat_w;
                region[0]->x.value = region[1]->x.value = 0;
                if (region[0]->y.value > region[1]->y.value)
                {
                    region[0]->y.value = cat_h / 2;
                    region[1]->y.value = 0;
                }
                else
                {
                    region[1]->y.value = cat_h / 2;
                    region[0]->y.value = 0;
                }
                continue;
            }

            /* Take top into consideration for check overlapping */
            /* Assumption : In portrait y0 and y1 can not be equal  */
            if (region[0]->y.value < region[1]->y.value)
            {
                if (region[0]->y.value + region[0]->h.value > region[1]->y.value)
                {
                    /* region overlap */
                    /* left checked for screen size. Sanity for width done for screen size */
                    region[0]->h.value = region[1]->h.value = cat_h / 2;
                    region[0]->w.value = region[1]->w.value = cat_w;
                    region[0]->x.value = region[1]->x.value = 0;
                    if (region[0]->y.value > region[1]->y.value)
                    {
                        region[0]->y.value = cat_h / 2;
                        region[1]->y.value = 0;
                    }
                    else
                    {
                        region[1]->y.value = cat_h / 2;
                        region[0]->y.value = 0;
                    }
                    continue;
                }
            }

            if (region[1]->y.value < region[0]->y.value)
            {
                if (region[1]->y.value + region[1]->h.value > region[0]->y.value)
                {
                    /* region overlap */
                    /* left checked for screen size. Sanity for width done for screen size */
                    region[0]->h.value = region[1]->h.value = cat_h / 2;
                    region[0]->w.value = region[1]->w.value = cat_w;
                    region[0]->x.value = region[1]->x.value = 0;
                    if (region[0]->y.value > region[1]->y.value)
                    {
                        region[0]->y.value = cat_h / 2;
                        region[1]->y.value = 0;
                    }
                    else
                    {
                        region[1]->y.value = cat_h / 2;
                        region[0]->y.value = 0;
                    }
                    continue;
                }
            }
            continue;
        }
        continue;
    }

}
#endif /* __MMI_MMS_MV_SUPPORT_PARAM_OF_REGION__ */ 
/* Object Related End */


/*****************************************************************************
 * FUNCTION
 *  srv_mms_compare_string_ignore_case
 * DESCRIPTION
 *  compare two strings
 * PARAMETERS
 *  addr_1      [IN]        
 *  addr_2      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL srv_mms_compare_string_ignore_case(U16 *addr_1, U16 *addr_2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 addr_index = 0;
    U16 char_A = 0x0041;
    U16 char_Z = 0x005A;
    U16 char_a = 0x0061;
    U16 addr_1_len = mmi_ucs2strlen((S8*) addr_1);
    U16 addr_2_len = mmi_ucs2strlen((S8*) addr_2);
    U16 addr_1_char = 0;
    U16 addr_2_char = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (addr_1_len != addr_2_len)
    {
        return MMI_FALSE;
    }

    while (addr_index < addr_1_len)
    {
        if (addr_1[addr_index] >= char_A && addr_1[addr_index] <= char_Z)
        {
            addr_1_char = char_a + addr_1[addr_index] - char_A;
        }
        else
        {
            addr_1_char = addr_1[addr_index];
        }

        if (addr_2[addr_index] >= char_A && addr_2[addr_index] <= char_Z)
        {
            addr_2_char = char_a + addr_2[addr_index] - char_A;
        }
        else
        {
            addr_2_char = addr_2[addr_index];
        }

        if (addr_1_char != addr_2_char)
        {
            return MMI_FALSE;
        }

        addr_index++;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_desc_pointer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mma_mms_description_struct *srv_mms_get_desc_pointer()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_desc != NULL)
    {
        return g_desc;
    }
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    return srv_mms_container_get_content();
#else
	return NULL;
#endif 

}

#ifdef __MMI_MMS_MV_SUPPORT_PARAM_OF_REGION__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_region_area
 * DESCRIPTION
 *  
 * PARAMETERS
 *  region      [?]         
 *  cat_w       [IN]        
 *  cat_h       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_region_area(mma_mms_object_area_struct *region, S32 cat_w, S32 cat_h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (region)
    {
        if (region->x.type == MMA_MMS_TIME_RELATIVE)
        {
            region->x.type = MMA_MMS_TIME_ABSOLUTE;
            region->x.value = (kal_uint32) (((DOUBLE) region->x.value / 100) * (cat_w));
        }
        if (region->y.type == MMA_MMS_TIME_RELATIVE)
        {
            region->y.type = MMA_MMS_TIME_ABSOLUTE;
            region->y.value = (kal_uint32) (((DOUBLE) region->y.value / 100) * (cat_h));
        }
        if (region->w.type == MMA_MMS_TIME_RELATIVE)
        {
            region->w.type = MMA_MMS_TIME_ABSOLUTE;
            region->w.value = (kal_uint32) (((DOUBLE) region->w.value / 100) * (cat_w));
        }
        if (region->h.type == MMA_MMS_TIME_RELATIVE)
        {
            region->h.type = MMA_MMS_TIME_ABSOLUTE;
            region->h.value = (kal_uint32) (((DOUBLE) region->h.value / 100) * (cat_h));
        }
    }
}
#endif /* __MMI_MMS_MV_SUPPORT_PARAM_OF_REGION__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_process_data
 * DESCRIPTION
 *  start handler for xml parser
 * PARAMETERS
 *  description     [?]         
 *  error(?)        [IN]        
 *  el(?)           [IN]        
 *  data(?)         [IN]        
 *  attr(?)         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static srv_mms_viewer_result_enum srv_mms_process_data(mma_mms_description_struct *description)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mma_mms_description_body_struct *body = NULL;
    mma_mms_slide_struct *slide;
    
    mma_mms_attachment_info_struct *att;
#if defined(__MMI_MV_SUPPORT_REF_ID__) || defined(__MMI_MMS_MV_SUPPORT_PARAM_OF_REGION__)
    mma_mms_slide_ref_object_struct *ref_items;
#endif    
#ifdef __MMI_MMS_MV_SUPPORT_PARAM_OF_REGION__
	S32 cat_x, cat_y, cat_w, cat_h;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    body = (description->body);
    body->layout = srv_mms_viewer_convert_mms_layout_type(body->layout);
    g_desc = description;

#ifdef __MMI_MMS_MV_SUPPORT_PARAM_OF_REGION__
    cat_x = 0;
    cat_y = 0;
    cat_w = 0;
    cat_h = 0;

    wgui_cat630_get_viewer_area_info(&cat_x, &cat_y, &cat_w, &cat_h, TRUE);
    slide = body->slides;
    ref_items = slide->ref_items;
    while (slide)
    {
        if (slide->txt.id)
        {
            srv_mms_set_region_area(slide->txt.region_area, cat_w, cat_h);
        }
        if (slide->img.id)
        {
            srv_mms_set_region_area(slide->img.region_area, cat_w, cat_h);
        }
        if (slide->vid.id)
        {
            srv_mms_set_region_area(slide->vid.region_area, cat_w, cat_h);
        }
        while (ref_items)
        {
            srv_mms_set_region_area(ref_items->region_area, cat_w, cat_h);
            ref_items = ref_items->next;
        }
        slide = slide->next;
    }
#endif /* __MMI_MMS_MV_SUPPORT_PARAM_OF_REGION__ */ 
    (*g_mms_obj_container) =
        (srv_mms_viewer_obj_container_struct*) srv_mms_mem_mgr_viewer_asm_alloc(body->slide_no *
                                                                                 sizeof
                                                                                 (srv_mms_viewer_obj_container_struct));
    if (!*g_mms_obj_container)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_PARSE_OUT_OF_MEM);
        return SRV_MMS_VIEWER_OUT_OF_MEM;
    }
    memset(*g_mms_obj_container, 0, body->slide_no * sizeof(srv_mms_viewer_obj_container_struct));
    body = description->body;
    slide = body->slides;
    while (slide)
    {
    #ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__

        if ((slide->img.object) && (slide->img.object->drm_type != 0))
        {
            slide->img.object->type = MMA_MMS_OBJECT_TYPE_ATTACHMENT;
            att = srv_mms_viewer_insert_attachment(&(body->attachment));
            if (att == NULL)
            {
                return SRV_MMS_VIEWER_OUT_OF_MEM;
            }
            srv_mms_viewer_insert_object_to_attachment(slide->img.object, att);
            memset(&(slide->img), 0, sizeof(slide->img));

        }
        if ((slide->vid.object) && (slide->vid.object->drm_type != 0))
        {
            slide->vid.object->type = MMA_MMS_OBJECT_TYPE_ATTACHMENT;
            att = srv_mms_viewer_insert_attachment(&(body->attachment));
            if (att == NULL)
            {
                return SRV_MMS_VIEWER_OUT_OF_MEM;
            }
            srv_mms_viewer_insert_object_to_attachment(slide->vid.object, att);
            memset(&(slide->vid), 0, sizeof(slide->vid));
        }
        if ((slide->aud.object) && (slide->aud.object->drm_type != 0))
        {
            slide->aud.object->type = MMA_MMS_OBJECT_TYPE_ATTACHMENT;
            att = srv_mms_viewer_insert_attachment(&(body->attachment));
            if (att == NULL)
            {
                return SRV_MMS_VIEWER_OUT_OF_MEM;
            }
            srv_mms_viewer_insert_object_to_attachment(slide->aud.object, att);
            memset(&(slide->aud), 0, sizeof(slide->aud));
        }

    #endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    #ifdef __MMI_MV_SUPPORT_REF_ID__
        ref_items = slide->ref_items;
        while (ref_items)
        {
			MMI_BOOL is_present = MMI_FALSE;
            is_present = srv_mms_check_ref_id_present(ref_items->id);
            if (!is_present)
            {
                ref_items->object->type = SRV_MMS_OBJECT_TYPE_ATTACHMENT;
                att = srv_mms_viewer_insert_attachment(&(body->attachment));
                if (att == NULL)
                {
                    /* error handling */
                    return SRV_MMS_VIEWER_OUT_OF_MEM;
                }
                srv_mms_viewer_insert_object_to_attachment(ref_items->object, att);
            }
            ref_items = ref_items->next;
        }
    #endif /* __MMI_MV_SUPPORT_REF_ID__ */ 
        (*g_mms_obj_container)[slide->slide_num - 1].slide = slide;
        slide = slide->next;
    }
    return SRV_MMS_VIEWER_OK;

}

#ifdef __MMI_MV_SUPPORT_REF_ID__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_check_ref_id_present
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_check_ref_id_present(U16 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mma_mms_attachment_info_struct *att = g_desc->body->attachment;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (att)
    {
        if (att->object->id == id)
            return MMI_TRUE;

        att = att->next;
    }
    return MMI_FALSE;
}
#endif /* __MMI_MV_SUPPORT_REF_ID__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_filepath_from_decoder
 * DESCRIPTION
 *  Give file path to application in case of message type is postcard
 * PARAMETERS
 *  file_path       [IN]        [out]
 *  offset          [?]         [?]         [?]
 *  size            [?]         [?]         [?]
 *  mem_alloc_fn(?)     [IN](?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_MMS_POSTCARD__
void srv_mms_get_filepath_from_decoder(U16 **file_path, S32 *offset, S32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
    mma_mms_description_struct *desc;
    mma_mms_object_struct *objects;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    desc = srv_mms_get_desc_pointer();
    objects = desc->body->objects;
    while (objects)
    {
        if (objects->type == SRV_MMS_OBJECT_TYPE_TEXT)
        {
            *offset = objects->offset;
            *size = objects->size;
            mmi_ucs2cpy((S8*) * file_path, (S8*) objects->file_path_ucs);
        }
        objects = objects->next;
    }
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_TRACE_GET_FILE_PATH_EXIT);
}
#endif /* __MMI_MMS_POSTCARD__ */ 

/****************************************************************************/
/***************************DRM PROCESSING RELATED***************************/
/****************************************************************************/

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_image_expired_callback
 * DESCRIPTION
 *  callback from DRM about img expiry
 * PARAMETERS
 *  result      [IN]        
 *  id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mms_image_expired_callback(S32 result, S32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *obj;
    mma_mms_slide_struct *current_slide;
    mma_mms_description_struct *desc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    desc = srv_mms_get_desc_pointer();
    current_slide = desc->body->curr_slide;
    if (current_slide->img.id)
    {
        /* We have a valid img on slide */
        obj = current_slide->img.object;
        MMI_ASSERT(obj);

        if (obj->consume_id == id)
        {
            /* The object on current slide seems to have expired */
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_IMAGE_RO_EXPIRED);
            obj->rights_expired = MMI_TRUE;
            g_expiry_cb(g_drm_user_data);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_video_expired_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 *  id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mms_video_expired_callback(S32 result, S32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *obj;

    mma_mms_description_struct *desc;
    mma_mms_slide_struct *current_slide = desc->body->curr_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    desc = srv_mms_get_desc_pointer();
    if (current_slide->vid.id)
    {
        /* We have a valid vid on slide */
        obj = current_slide->vid.object;
        MMI_ASSERT(obj);

        if (obj->consume_id == id)
        {
            /* The object on current slide seems to have expired */
            obj->rights_expired = MMI_TRUE;
            g_expiry_cb(g_drm_user_data);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_audio_expired_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 *  id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mms_audio_expired_callback(S32 result, S32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *obj;
    mma_mms_description_struct *desc;

    mma_mms_slide_struct *current_slide = desc->body->curr_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    desc = srv_mms_get_desc_pointer();
    if (current_slide->aud.id)
    {
        /* We have a valid aud on slide */
        obj = current_slide->aud.object;
        MMI_ASSERT(obj);

        if (obj->consume_id == id)
        {
            /* The object on current slide seems to have expired */
            obj->rights_expired = MMI_TRUE;
            g_expiry_cb(g_drm_user_data);
        }
    }
}

#ifdef __DRM_SUPPORT__
typedef void (*srv_mms_drm_consume_cb) (kal_int32 result, kal_int32 id);

#ifdef __MMI_MMS_WRAP_DRM_FL_CD__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_start_consume_rights_from_cid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  media               [?]         
 *  object_id(?)        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_mms_start_consume_rights_from_cid(mma_mms_slide_object_struct *media)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *obj = media->object; /* srv_mms_viewer_find_objects_from_id(object_id); */
    U8 permissions = DRM_PERMISSION_PLAY;
    srv_mms_drm_consume_cb callback = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Consuming rights for a null object? */
    ASSERT(obj);

    switch (obj->type)
    {
        case MMA_MMS_OBJECT_TYPE_AUDIO:
            callback = srv_mms_audio_expired_callback;
            break;
        case MMA_MMS_OBJECT_TYPE_VIDEO:
            callback = srv_mms_video_expired_callback;
            break;
        case MMA_MMS_OBJECT_TYPE_IMAGE:
            permissions = DRM_PERMISSION_DISPLAY;
            callback = srv_mms_image_expired_callback;
            break;
        default:
            ASSERT(0);
    }

    if (MMI_FALSE == obj->consume_only_timed)
    {
        obj->consume_id = DRM_consume_rights_by_cid(obj->cid, permissions, (srv_mms_drm_consume_cb) callback);
        /* MAUI_00472074: even back from popup we want to consume another count! */
    #ifdef MMI_Q05_MMSVIEWER_CONSUME_COUNT_ONCE
        obj->consume_only_timed = MMI_TRUE;
    #endif 
    }
    else
    {
        obj->consume_id = DRM_consume_timed_rights_by_cid(obj->cid, permissions, (srv_mms_drm_consume_cb) callback);
    }

    return MMI_TRUE;
}
#endif /* __MMI_MMS_WRAP_DRM_FL_CD__ */ /* #ifdef __MMI_MMS_WRAP_DRM_FL_CD__ */
#endif /* __DRM_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_start_consume_rights_from_file
 * DESCRIPTION
 *  start to consume img rights
 * PARAMETERS
 *  media               [?]         
 *  file_path           [IN]        
 *  object_id(?)        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_mms_start_consume_rights_from_file(mma_mms_slide_object_struct *media, PU16 file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 drm_fh;
    MMI_BOOL ret_val = MMI_TRUE;
    mma_mms_object_struct *obj = media->object; /* srv_mms_viewer_find_objects_from_id(object_id); */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Consuming rights for a null object? */
    ASSERT(obj);

#ifdef __DRM_SUPPORT__
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #ifdef MMI_Q05_MMSVIEWER_CONSUME_COUNT_ONCE
/* under construction !*/
            #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #ifdef MMI_Q05_MMSVIEWER_CONSUME_COUNT_ONCE
/* under construction !*/
            #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

    if ((drm_fh = DRM_open_file((U16*) file_path, FS_READ_ONLY, DRM_PERMISSION_DISPLAY)) >= FS_NO_ERROR)
    {
        if (MMI_FALSE == obj->consume_only_timed)
        {
            /* Consume count and time */
            obj->consume_id = DRM_consume_rights(drm_fh, DRM_PERMISSION_DISPLAY, srv_mms_image_expired_callback);
            /* MAUI_00472074: even back from popup we want to consume another count! */
        #ifdef MMI_Q05_MMSVIEWER_CONSUME_COUNT_ONCE
            obj->consume_only_timed = MMI_TRUE;
        #endif 
        }
        else
        {
            /* Consume time only */
            obj->consume_id = DRM_consume_timed_rights(drm_fh, DRM_PERMISSION_DISPLAY, srv_mms_image_expired_callback);
        }

        if (obj->consume_id < 1)
        {
            obj->rights_expired = MMI_TRUE;
            ret_val = MMI_FALSE;
        }
        else
        {
            ret_val = MMI_TRUE;
        }

        DRM_close_file(drm_fh);
    }
    else
    {
        /* Couldn't open file for some reasons: effectively blocked! */
        obj->rights_expired = MMI_TRUE;
        ret_val = MMI_FALSE;
    }
#endif /* __DRM_SUPPORT__ */ 

    return ret_val;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_start_consume_rights
 * DESCRIPTION
 *  start to consume media (img/aud/vid) rights
 * PARAMETERS
 *  media               [?]         
 *  file_path           [IN]        
 *  expiry_func         [IN]        
 *  user_data           [?]         
 *  object_id(?)        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_start_consume_rights(
            mma_mms_slide_object_struct *media,
            PU16 file_path,
            srv_mms_rights_expiry_notify_cb expiry_func,
            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *obj = media->object; /* srv_mms_viewer_find_objects_from_id(object_id); */
    MMI_BOOL ret_val = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Consuming rights for a null object? */
    ASSERT(obj);
    g_expiry_cb = expiry_func;
    g_drm_user_data = user_data;
    if (obj->drm_type == 0 || obj->consume_id != 0)
    {
        /* Non DRM object || already consuming */
        return ret_val;
    }

    if (obj->rights_expired == MMI_TRUE)
    {
        /* Don't have valid permissions! */
        return MMI_FALSE;
    }
#ifdef __DRM_SUPPORT__
    switch (obj->drm_type)
    {
        case MMA_DRM_FL_CD:
    #ifdef __MMI_MMS_WRAP_DRM_FL_CD__
            ret_val = srv_mms_start_consume_rights_from_cid(media);
    #else 
            ret_val = MMI_FALSE;
    #endif 
            break;

        case MMA_DRM_SD:
        case MMA_DRM_SD_NO_RIGHT:
        case MMA_DRM_PDCF_V2:
        case MMA_DRM_PDCF_V2_NO_RIGHT:
            if (obj->type == MMA_MMS_OBJECT_TYPE_IMAGE)
            {
                /* For SD Objects we consume only for img */
                ret_val = srv_mms_start_consume_rights_from_file(media, file_path);
            }
            else
            {
                ret_val = MMI_TRUE;
            }
            break;
        default:
            ASSERT(0);
    }
#endif /* __DRM_SUPPORT__ */ 
    /* MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_START_CONSUME, object_id, ret_val); */

    return ret_val;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_stop_consume_rights
 * DESCRIPTION
 *  stop consume rights
 * PARAMETERS
 *  media               [?]         
 *  object_id(?)        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_stop_consume_rights(mma_mms_slide_object_struct *media)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *obj = media->object; /* srv_mms_viewer_find_objects_from_id(object_id); */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DRM_SUPPORT__

    /* Stop consuming rights for a null object? */
    ASSERT(obj);

    if (obj->consume_id == 0)
    {
        /* Consume didn't start for this id */
        return;
    }

    DRM_stop_consume(obj->consume_id);
    obj->consume_id = 0;
    /* MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_STOP_CONSUME, object_id); */
#endif /* __DRM_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_update_rights_from_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  media       [?]         
 *  id(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mms_update_rights_from_file(mma_mms_slide_object_struct *media)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 id = 0;

#ifdef __DRM_SUPPORT__
    U16 vfname[SRV_MMS_VIEWER_VFN_NUM_OF_WCHAR];
    PU16 drm_file;
    S32 parent_fh;
    S32 drm_fh;
    U8 permissions;

    mma_mms_object_struct *obj = media->object; /* srv_mms_viewer_find_objects_from_id(id); */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* updating rights for a null object? */
#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR*) L"root"))
        {
            srv_mms_viewer_send_event_to_exit(SRV_MMS_VIEWER_FILE_ERROR, g_srv_mms_use_details_cntx->fail_reason);
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
    ASSERT(obj);

    if (obj->type == MMA_MMS_OBJECT_TYPE_IMAGE)
    {
        permissions = DRM_PERMISSION_DISPLAY;
    }
    else
    {
        permissions = DRM_PERMISSION_PLAY;
    }

    srv_mms_get_filename_by_id(media, vfname, &drm_file, &parent_fh);
    drm_fh = DRM_open_file((PU16) drm_file, FS_READ_ONLY, permissions);

    if (drm_fh >= FS_NO_ERROR)
    {
        if (MMI_FALSE == DRM_validate_permission(drm_fh, NULL, permissions))
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_VALIDATE_PERMISSION_FALSE);
            obj->rights_expired = MMI_TRUE;
        }
        else
        {
            obj->rights_expired = MMI_FALSE;
        }

        DRM_close_file(drm_fh);
    }
    else
    {
        /* As good as rights expired */
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_UPDATE_RIGHTS_FILE_OPEN_ERROR);
        obj->rights_expired = MMI_TRUE;
    }

    if (parent_fh)
    {
        FS_Close(parent_fh);
    }
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_UPDATE_RIGHTS_FROM_FILE, permissions, obj->rights_expired);
#else /* __DRM_SUPPORT__ */ 
    /* just to remove warning : variable not used */
    id = 0;
#endif /* __DRM_SUPPORT__ */ 
}

#ifdef __DRM_SUPPORT__

#ifdef __MMI_MMS_WRAP_DRM_FL_CD__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_update_rights_from_cid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  media       [?]         
 *  id(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mms_update_rights_from_cid(mma_mms_slide_object_struct *media)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *obj = media->object; /* srv_mms_viewer_find_objects_from_id(id); */
    U8 permissions;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* updating rights for a null object? */
    ASSERT(obj);

    if (obj->type == MMA_MMS_OBJECT_TYPE_IMAGE)
    {
        permissions = DRM_PERMISSION_DISPLAY;
    }
    else
    {
        permissions = DRM_PERMISSION_PLAY;
    }

    if (MMI_FALSE == DRM_validate_permission_by_cid(obj->cid, permissions))
    {
        obj->rights_expired = MMI_TRUE;
    }
    else
    {
        obj->rights_expired = MMI_FALSE;
    }
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_UPDATE_RIGHTS_FROM_CID, permissions, obj->rights_expired);

}
#endif /* __MMI_MMS_WRAP_DRM_FL_CD__ */ /* #ifdef __MMI_MMS_WRAP_DRM_FL_CD__ */
#endif /* __DRM_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_update_rights_by_id
 * DESCRIPTION
 *  update rights for a particular id
 *  The sequence of calling this function is
 *  init_slide() --> update_rights() :: display functions() -->
 *  check_rights() :: consume_rights()
 * PARAMETERS
 *  media               [?]         
 *  rights_expired      [IN]        
 *  id(?)               [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_update_rights_by_id(mma_mms_slide_object_struct *media, MMI_BOOL rights_expired)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *obj = media->object; /* srv_mms_viewer_find_objects_from_id(id); */

    /* UNUSED right_expired */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* updating rights for a null object? */
    ASSERT(obj);
#ifdef __DRM_SUPPORT__
    if (obj->drm_type != 0 && obj->is_drm_processed == MMI_FALSE)
    {
        obj->rights_expired = MMI_TRUE;
        return;
    }
    if (obj->drm_type == 0 || obj->consume_id != 0)
    {
        /* Non DRM object || already consuming */
        return;
    }

    switch (obj->drm_type)
    {
        case MMA_DRM_NONE:
            obj->rights_expired = MMI_FALSE;
            break;
        case MMA_DRM_FL_CD:
    #ifdef __MMI_MMS_WRAP_DRM_FL_CD__
            srv_mms_update_rights_from_cid(media);
    #else 
            obj->rights_expired = MMI_FALSE;
    #endif 
            break;
        case MMA_DRM_SD_NO_RIGHT:
        case MMA_DRM_SD:
        case MMA_DRM_PDCF_V2:
        case MMA_DRM_PDCF_V2_NO_RIGHT:
            srv_mms_update_rights_from_file(media);
            break;
        default:
            obj->rights_expired = MMI_TRUE;
    }

#else /* __DRM_SUPPORT__ */ 
    obj->rights_expired = MMI_FALSE;
#endif /* __DRM_SUPPORT__ */ 
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_UPDATE_DRM_RIGHTS, obj->drm_type, obj->is_drm_processed);
}

/* Return True if we don't have rights */


/*****************************************************************************
 * FUNCTION
 *  srv_mms_check_rights_by_id
 * DESCRIPTION
 *  check rights for a object id
 * PARAMETERS
 *  media       [?]         
 *  id(?)       [IN]        
 * RETURNS
 *  TRUE if DRM locked
 *****************************************************************************/
MMI_BOOL srv_mms_check_rights_by_id(mma_mms_slide_object_struct *media)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *obj = media->object; /* srv_mms_viewer_find_objects_from_id(id); */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* checking rights for a null object? */
    ASSERT(obj);
    /* MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_CHECK_RO, id, obj->rights_expired); */

    return (obj->rights_expired);
}

#else /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_move_to_attachment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  media       [?]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_move_to_attachment(mma_mms_slide_object_struct *media)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mma_mms_attachment_info_struct *att;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_desc->body->total_attach_no >= SRV_MMS_UC_MAX_ATTACHMENT_NUM)
        return MMI_FALSE;
    att = g_desc->body->attachment;
    att = srv_mms_insert_attachment(
            g_desc->body,
            srv_mms_mem_mgr_viewer_asm_alloc_userdata,
            srv_mms_mem_mgr_viewer_asm_free_userdata,
            NULL);
    att->object = media->object;
    att->object->type = MMA_MMS_OBJECT_TYPE_ATTACHMENT;
    if (g_desc->body->slides->img.alt)
    {
        srv_mms_mem_mgr_viewer_asm_free(g_desc->body->slides->img.alt);
        g_desc->body->slides->img.alt = NULL;
    }
    if (g_desc->body->slides->img.region_area)
    {
        srv_mms_mem_mgr_viewer_asm_free(g_desc->body->slides->img.region_area);
        g_desc->body->slides->img.region_area = NULL;
    }

    g_desc->body->slides->img.object = NULL;
    g_desc->body->slides->img.id = 0;
    return MMI_TRUE;

}

#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
/* keep this in service of viewer */


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_filename_by_id
 * DESCRIPTION
 *  Get filename by id
 * PARAMETERS
 *  media                       [?]         
 *  vf                          [IN]        
 *  file_path                   [OUT]       
 *  vf_parent_file_handle       [IN]        
 *  id(?)                       [IN]        
 * RETURNS
 *  success or not
 *****************************************************************************/
MMI_BOOL srv_mms_get_filename_by_id(
            mma_mms_slide_object_struct *media,
            PU16 vf,
            PU16 *file_path,
            PS32 vf_parent_file_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *temp = media->object;    /* srv_mms_viewer_find_objects_from_id(id); */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (temp == NULL)
    {
        return MMI_FALSE;
    }

    if (temp->is_virtual_file == MMI_TRUE)
    {
        S32 file_handle;
        S32 result;
        U32 offset;
        U32 size;

        if (temp->drm_type == MMA_DRM_FL_CD)
        {
            offset = temp->drm_offset;
            size = temp->drm_size;
        }
        else
        {
            offset = temp->offset;
            size = temp->size;
        }

        /* Open Parent File Handle */
        file_handle = FS_Open((U16*) (temp->file_path_ucs), FS_READ_ONLY | FS_OPEN_SHARED);

        if (file_handle <= 0)
        {
            /* Return because can't get parent file handle */
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_PARENT_FILE_ERROR);
            *vf_parent_file_handle = 0;
            return MMI_FALSE;
        }

        result = FS_GenVirtualFileName(file_handle, (U16*) vf, (unsigned int)FS_GenVFN_SIZE, offset, size);

        if (result < 0)
        {
            /* Can't create VF, close parent file handle */
            FS_Close(file_handle);
            *vf_parent_file_handle = 0;
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_VF_FILE_ERROR);
            return MMI_FALSE;
        }

        mmi_ucs2cat((PS8) vf, (PS8) ".");
        if (temp->drm_type != 0)
        {
            /* postfix drm extension */
            mmi_ucs2ncat((PS8) vf, (PS8) temp->drm_ext, SRV_FMGR_PATH_MAX_FILE_EXT_LEN);
        }
        else
        {
            PS8 temp_str = (S8*) srv_fmgr_path_get_extension_ptr((WCHAR*) temp->file_name_ucs);

            ASSERT(temp_str);
            mmi_ucs2ncat((PS8) vf, temp_str, SRV_FMGR_PATH_MAX_FILE_EXT_LEN);
        }

        /* Parent File handle & VF is valid */
        *vf_parent_file_handle = file_handle;
        *file_path = vf;
    }
    else
    {
        *file_path = (U16*) (temp->file_path_ucs);
    }

    return MMI_TRUE;
}

/****************************************************************************/
/***************************DRM PROCESSING RELATED***************************/
/****************************************************************************/

/***************BEST PAGE DURATION******************************************/


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_best_page_duration
 * DESCRIPTION
 *  Callback to category
 * PARAMETERS
 *  playing_time        [IN]            
 *  slide_duration      [IN/OUT]        
 *  obj_start_time      [IN/OUT]        
 *  obj_end_time        [IN/OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_viewer_best_page_duration(
        U64 playing_time,
        kal_uint32 *slide_duration,
        kal_uint32 *obj_start_time,
        kal_uint32 *obj_end_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_BEST_PAGE_SUPPORT__
    *obj_start_time = 0;
    *obj_end_time = 65535;
   
    if (g_desc->body->curr_slide->txt.id)
    {
        g_desc->body->curr_slide->txt.begin = 0;
        g_desc->body->curr_slide->txt.end = 65535;
    }
    if (g_desc->body->curr_slide->img.id)
    {
        g_desc->body->curr_slide->img.begin = 0;
        g_desc->body->curr_slide->img.end = 65535;
    }
    return;
#endif /* __MMI_MMS_BEST_PAGE_SUPPORT__ */ 
    if (!srv_mms_compose_settings_best_page_duration())
    {
        return;
    }

    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_BEST_PAGE, playing_time, obj_start_time, obj_end_time);

    if (playing_time > 0 && playing_time < 1000)
    {
        /* set minimum one second playing time MAUI_00275779 */
        playing_time = 1;
    }
    else
    {
        playing_time = playing_time / 1000;
    }

    // if (*slide_duration == 0)
    // {

    if ((*slide_duration < playing_time) || (*obj_end_time < (*obj_start_time + playing_time)))
    {
        if (g_desc->body->curr_slide->txt.id)
        {
            g_desc->body->curr_slide->txt.begin = 0;
        }
        if (g_desc->body->curr_slide->img.id)
        {
            g_desc->body->curr_slide->img.begin = 0;
        }
        if (*slide_duration < playing_time)
        {
            if (g_desc->body->curr_slide->txt.id /* && g_srv_mms_parser_cntx->msg_cntx->current_slide->txt.end == 0 */ )
            {
                g_desc->body->curr_slide->txt.end = *obj_start_time + playing_time;
            }
            if (g_desc->body->curr_slide->img.id /* && g_srv_mms_parser_cntx->msg_cntx->current_slide->img.end == 0 */ )
            {
                g_desc->body->curr_slide->img.end = *obj_start_time + playing_time;
            }
        }
        else
        {
            /* UC will set end time to slide duration! */
            if (g_desc->body->curr_slide->txt.id)
            {
                g_desc->body->curr_slide->txt.end = g_desc->body->curr_slide->txt.begin + playing_time;
            }
            if (g_desc->body->curr_slide->img.id)
            {
                g_desc->body->curr_slide->img.end = g_desc->body->curr_slide->img.begin + playing_time;
            }
        }
    }
    /* } */

    /* Behaviour Synced With UC UnifiedComposerMiscell.c */
    if ((*slide_duration < playing_time) || (*obj_end_time < (*obj_start_time + playing_time)))
    {
        *obj_start_time = 0;

        if (*slide_duration < playing_time)
        {
            *slide_duration = *obj_start_time + playing_time;
            *obj_end_time = *slide_duration;
        }
        else
        {
            /* UC will set end time to slide duration! */
            *obj_end_time = *obj_start_time + playing_time;
        }

    }

}

/****************LOAD TEXT FOR CATEGORY*************************/


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_load_ucs2_txt_to_buffer
 * DESCRIPTION
 *  load ucs2 txt to buffer
 * PARAMETERS
 *  dest_buffer             [IN]        
 *  dest_buffer_size        [IN]        
 *  media                   [?]         
 *  object_id(?)            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_mms_viewer_load_ucs2_txt_to_buffer(
            PU8 dest_buffer,
            U32 dest_buffer_size,
            mma_mms_slide_text_object_struct *media)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 file_handle = 0;
    S32 parent_file_handle = 0;
    PU16 file_path;
    S32 result = 0;
    mma_mms_object_struct *temp = media->object;    /* srv_mms_viewer_find_objects_from_id(object_id); */
    U16 txt_vf[FS_GenVFN_SIZE];
    U32 len = 0;

#ifdef __MMI_MMS_POSTCARD__
    MMI_UMMS_ERROR decoded = MMI_UMMS_FALSE;
    /* postcard_recipient_struct */ srv_postcard_recipient_struct *recipient_head = NULL;
    kal_char *greeting = NULL;
    applib_oppostcard_mem_func_struct mem_funct;

    mem_funct.alloc_fn = srv_mms_mem_mgr_viewer_asm_alloc_postcard;
    mem_funct.free_fn = srv_mms_mem_mgr_viewer_asm_free_postcard;
#endif /* __MMI_MMS_POSTCARD__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR*) L"root"))
        {
            srv_mms_viewer_send_event_to_exit(SRV_MMS_VIEWER_FILE_ERROR, g_srv_mms_use_details_cntx->fail_reason);
            return MMI_FALSE;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
    if (temp == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_NO_OBJ);
        return MMI_FALSE;
    }

    if (temp->is_virtual_file == MMI_TRUE)
    {
        /* Open Parent File Handle */
        parent_file_handle = FS_Open((WCHAR*) (temp->file_path_ucs), FS_READ_ONLY | FS_OPEN_SHARED);

        if (parent_file_handle <= 0)
        {
            /* Return because can't get parent file handle */
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_LOAD_UCS2_NO_PARENT_HANDLE);
            return MMI_FALSE;
        }

        result = FS_GenVirtualFileName(
                    parent_file_handle,
                    (U16*) txt_vf,
                    (unsigned int)FS_GenVFN_SIZE,
                    temp->offset,
                    temp->size);

        if (result < 0)
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_LOAD_UCS2_NO_VF);
            /* Can't create VF, close parent file handle */
            FS_Close(parent_file_handle);
            return MMI_FALSE;
        }

        file_path = txt_vf;
    }
    else
    {
        file_path = (U16*) (temp->file_path_ucs);
    }

    memset(dest_buffer, 0, dest_buffer_size + 1 * ENCODING_LENGTH);
    memset(g_srv_mms_parser_cntx->src_buffer, 0, srv_mms_viewer_get_txt_utf_len() + 1);

#ifdef __MMI_MMS_POSTCARD__
    if (srv_mms_get_message_type() == MMA_MSG_TYPE_POSTCARD)
    {
        decoded = applib_oppostcard_decode_text_content(&mem_funct, file_path, &greeting, (void*)&recipient_head);
        if (decoded == MMI_UMMS_FALSE)
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_DECODE_ERR);
            return MMI_FALSE;
        }
        if (greeting != NULL)
        {
            mmi_ucs2ncpy((S8*) dest_buffer, (S8*) greeting, SRV_POSTCARD_MAX_GREETING);
        }
        applib_oppostcard_free_memory(&mem_funct, greeting, recipient_head);
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_POSTCRD_EXIT);
    }
    else
#endif /* __MMI_MMS_POSTCARD__ */ 
    {
        /* Read Src Txt into src buffer */
        //*********************************************************
        //*******************************************************
        file_handle = FS_Open(file_path, FS_READ_ONLY | FS_OPEN_SHARED);
        if (file_handle <= 0)
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_TXT_FILE_ERR);
            FS_Close(parent_file_handle);
            return MMI_FALSE;
        }

        result = FS_Read(file_handle, g_srv_mms_parser_cntx->src_buffer, srv_mms_viewer_get_txt_utf_len(), &len);
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_READ_FILE, len);

        FS_Close(file_handle);
        if (result == FS_NO_ERROR)
        {
            srv_mms_viewer_change_encoding(g_srv_mms_parser_cntx->src_buffer, dest_buffer_size, dest_buffer, temp->charset);
			MMI_TRACE(
                MMI_INET_TRC_G6_MMS,
                MMI_SRV_VIEWER_CONVERTED_TO_UCS2_LEN,
                mmi_ucs2strlen((PS8) g_srv_mms_parser_cntx->slide_txt_buffer));
        }
    }
    if (parent_file_handle != 0)
    {
        FS_Close(parent_file_handle);
    }

    if (result >= 0)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}

void srv_mms_viewer_change_encoding(U8 *src_buffer, U32 size, U8 *dest_buffer, U16 encoding)
{
	U8 encoding_type;
	switch (encoding)
            {
                default:
                    mmi_chset_utf8_to_ucs2_string(
                        dest_buffer,
                        size + 1 * ENCODING_LENGTH,
                        src_buffer);
                    break;
                case MMA_CHARSET_UTF16:
                    encoding_type = mmi_chset_get_utf_byte_order((kal_int8*) g_srv_mms_parser_cntx->src_buffer);
                    if (0xFF == encoding_type)
                    {
                        /* There is no BOM but the PDU says it's UTF16    *
                           lets try with LE since the uC is running in LE */
                        encoding_type = MMI_CHSET_UTF16LE;
                    }
                    mmi_chset_convert(
                        (mmi_chset_enum)encoding_type,
                        CHSET_UCS2,
                        (PS8) src_buffer,
                        (PS8) dest_buffer,
                        size);
                    break;
                case MMA_CHARSET_UTF16BE:
                    mmi_chset_convert(
                        MMI_CHSET_UTF16BE,
                        CHSET_UCS2,
                        (PS8) src_buffer,
                        (PS8) dest_buffer,
                        size);
                    break;
                case MMA_CHARSET_UTF16LE:
                    mmi_chset_convert(
                        MMI_CHSET_UTF16LE,
                        CHSET_UCS2,
                        (PS8) src_buffer,
                        (PS8) dest_buffer,
                        size);
                    break;
                case MMA_CHARSET_UCS2:
                    mmi_ucs2ncpy((PS8) dest_buffer, (PS8) src_buffer, size);
                    break;
                case MMA_CHARSET_GB2312:
                    mmi_chset_convert(
                        MMI_CHSET_GB2312,
                        CHSET_UCS2,
                        (PS8) src_buffer,
                        (PS8) dest_buffer,
                        size);
                    break;
                case MMA_CHARSET_BIG5:
                    mmi_chset_convert(
                        MMI_CHSET_BIG5,
                        CHSET_UCS2,
                        (PS8) src_buffer,
                        (PS8) dest_buffer,
                        size);
                    break;
                case MMA_CHARSET_ISO_8859_1:
                    mmi_chset_convert(
                        MMI_CHSET_WESTERN_ISO,
                        CHSET_UCS2,
                        (PS8) src_buffer,
                        (PS8) dest_buffer,
                        size);

                    break;
            }
    }

/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_message_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_message_type(kal_uint8 msg_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_curr_msg_type = msg_type;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_message_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 srv_mms_get_message_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_curr_msg_type;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_get_attachment_list
 * DESCRIPTION
 *  returns the attachment list
 * PARAMETERS
 *  attachment_list         [IN]        
 *  num_of_attachments      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_viewer_get_attachment_list(mma_mms_attachment_info_struct **attachment_list, PU32 num_of_attachments)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_desc->body != NULL)
	{
		ASSERT(*attachment_list == NULL);
		*attachment_list = g_desc->body->attachment;
		*num_of_attachments = srv_mms_get_attachment_no();
	}

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_attachment_no
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_mms_get_attachment_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_desc->body != NULL)
	{
		mma_mms_attachment_info_struct *att = g_desc->body->attachment;
		while (att)
		{
			att = att->next;
			i++;
		}
    return i;
	}

	return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_get_objects_from_current_slide
 * DESCRIPTION
 *  returns objects from current slide
 * PARAMETERS
 *  img         [IN]        
 *  vid         [IN]        
 *  aud         [IN]        
 *  text        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_viewer_get_objects_from_current_slide(
        mma_mms_object_struct **img,
        mma_mms_object_struct **vid,
        mma_mms_object_struct **aud,
        mma_mms_object_struct **text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(*img == NULL && *vid == NULL && *aud == NULL && *text == NULL);
	if(g_desc->body != NULL)
	{
		*text = g_desc->body->curr_slide->txt.object;
		*img = g_desc->body->curr_slide->img.object;

		*vid = g_desc->body->curr_slide->vid.object;

		*aud = g_desc->body->curr_slide->aud.object;
	}

}

/****************USE DETAIL RELATED****************************************/


/*****************************************************************************
 * FUNCTION
 *  srv_mms_init_use_details
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_init_use_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
    S32 fs_ret = 0;
    PU16 file_path;
    S32 file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* create directory for use detail: Amitesh */

    srv_mms_viewer_generate_file_path(&fs_ret, &file_path);
    file_handle = FS_Open(file_path, FS_READ_ONLY);
    if (file_handle > 0)
    {
        /* put traces */
        FS_Close(file_handle);
    }
    else
    {
        FS_CreateDir(file_path);
        FS_SetAttributes(file_path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
    }
    srv_mms_mem_mgr_app_adm_free(file_path);
#endif /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
}

#ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_generate_file_path
 * DESCRIPTION
 *  generate path for use detail
 * PARAMETERS
 *  fs_ret          [?]     
 *  file_path       [?]     
 * RETURNS
 *  srv_mms_viewer_result_enum
 *****************************************************************************/
static srv_mms_viewer_result_enum srv_mms_viewer_generate_file_path(S32 *fs_ret, PU16 *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 file_name[SRV_MMS_USE_DETAIL_FILE_PATH];
    FS_DiskInfo disk_info;
    kal_uint64 free_space;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(file_name, 0, SRV_MMS_USE_DETAIL_FILE_PATH);
    *file_path = (PU16) srv_mms_mem_mgr_app_adm_alloc(SRV_MMS_USE_DETAIL_FILE_PATH * ENCODING_LENGTH);
#ifdef MMS_IN_LARGE_STORAGE
    sprintf(file_name, "%c", UMMS_MMS_DEFAULT_PUBLIC_DRIVE);
#else 
    sprintf(file_name, "%c", UMMS_MMS_DEFAULT_SYS_DRIVE);
#endif 
    mmi_asc_to_ucs2((PS8) * file_path, file_name);
    mmi_ucs2cat((S8*) * file_path, (S8*) L":\\");
    *fs_ret = FS_GetDiskInfo((PU16) * file_path, &disk_info, FS_DI_FREE_SPACE);
    if (*fs_ret >= 0)
    {
        free_space = (kal_uint64) disk_info.FreeClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;
    }
    else
    {
        return SRV_MMS_VIEWER_OK;
    }
    if (free_space > 0)
    {
        goto End;
    }
    else
    {
        if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) == FS_NO_ERROR)
        {
            free_space = 0;
            memset(file_name, 0, SRV_MMS_USE_DETAIL_FILE_PATH);
            sprintf(file_name, "%c", SRV_FMGR_CARD_DRV);
            mmi_asc_to_ucs2((PS8) * file_path, file_name);
            mmi_ucs2cat((S8*) * file_path, (S8*) L":\\");
            *fs_ret = FS_GetDiskInfo((PU16) * file_path, &disk_info, FS_DI_FREE_SPACE);
            if (*fs_ret >= 0)
            {
                free_space =
                    (kal_uint64) disk_info.FreeClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;
            }
            else
            {

                return SRV_MMS_VIEWER_OK;
            }
            if (free_space > 0)
            {
                goto End;
            }
            else
            {
                return SRV_MMS_VIEWER_NOT_ENOUGH_MEMORY;
            }
        }
        else
        {
            return SRV_MMS_VIEWER_NOT_ENOUGH_MEMORY;
        }
    }
  End:
    mmi_ucs2cat((S8*) * file_path, (S8*) SRV_MMS_USE_DETAIL_FOLDER);
    return SRV_MMS_VIEWER_OK;
}
#endif /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_use_details_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static U8 srv_mms_get_use_details_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
    S32 fs_ret = 0;
    U32 bytes_written = 0;
    srv_mms_viewer_result_enum gen_err = SRV_MMS_VIEWER_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Amitesh Starts use Detail Related */
    if (!g_srv_mms_use_details_cntx->first_slide)
    {
        /* Creating Actual File */

        gen_err = srv_mms_viewer_generate_file_path(&fs_ret, &g_srv_mms_use_details_cntx->file_path);
        if (gen_err != SRV_MMS_VIEWER_OK)
        {
            srv_mms_viewer_send_event_to_exit(gen_err, 0);
            return MMI_UMMS_FALSE;
        }
        if (fs_ret < 0)
        {
            srv_mms_viewer_send_event_to_exit(0, fs_ret);
            return MMI_UMMS_FALSE;
        }
        g_srv_mms_use_details_cntx->file_handle = FS_Open(g_srv_mms_use_details_cntx->file_path, FS_READ_ONLY);
        if (g_srv_mms_use_details_cntx->file_handle < 0)
        {
            fs_ret = FS_CreateDir(g_srv_mms_use_details_cntx->file_path);
            if (fs_ret < 0)
            {
                g_srv_mms_use_details_cntx->fail_reason = fs_ret;
                srv_mms_viewer_send_event_to_exit(0, g_srv_mms_use_details_cntx->fail_reason);
                return MMI_UMMS_FALSE;
            }
            fs_ret = FS_SetAttributes(g_srv_mms_use_details_cntx->file_path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
            if (fs_ret < FS_NO_ERROR)
            {
                g_srv_mms_use_details_cntx->fail_reason = fs_ret;
                srv_mms_viewer_send_event_to_exit(0, g_srv_mms_use_details_cntx->fail_reason);
                return MMI_UMMS_FALSE;
            }
        }
        if (g_srv_mms_use_details_cntx->file_handle)
        {
            FS_Close(g_srv_mms_use_details_cntx->file_handle);
        }
        mmi_ucs2cat((S8*) g_srv_mms_use_details_cntx->file_path, (S8*) SRV_MMS_USE_DETAIL_FILE_NAME);
        /* Creating Actual File */

        g_srv_mms_use_details_cntx->parsed_slide = g_desc->body->curr_slide;
        g_srv_mms_use_details_cntx->first_slide = g_desc->body->curr_slide;
        g_srv_mms_use_details_cntx->header =
            (S16*) srv_mms_mem_mgr_viewer_asm_alloc(sizeof(S16) * 3 * g_desc->body->slide_no);
        ASSERT(g_srv_mms_use_details_cntx->header);
        memset(g_srv_mms_use_details_cntx->header, 0, sizeof(S16) * 3 * g_desc->body->slide_no);
        g_srv_mms_use_details_cntx->file_handle = FS_Open((PU16) g_srv_mms_use_details_cntx->file_path, FS_READ_WRITE | FS_CREATE_ALWAYS);
        if (g_srv_mms_use_details_cntx->file_handle < 0)
        {
            g_srv_mms_use_details_cntx->fail_reason = g_srv_mms_use_details_cntx->file_handle;
            srv_mms_viewer_send_event_to_exit(0, g_srv_mms_use_details_cntx->fail_reason);
            return MMI_UMMS_FALSE;
        }
        fs_ret = FS_Write(
                    g_srv_mms_use_details_cntx->file_handle,
                    g_srv_mms_use_details_cntx->header,
                    sizeof(S16) * 3 * g_desc->body->slide_no,
                    &bytes_written);
        FS_Close(g_srv_mms_use_details_cntx->file_handle);
    }
    /* Amitesh Ends */
#ifndef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__
    if (g_srv_mms_use_details_cntx->msg_cntx->current_slide->txt.id != 0
        && g_srv_mms_use_details_cntx->msg_cntx->current_slide->txt.str_id == 0
        && g_srv_mms_use_details_cntx->parsed_slide != NULL)
    {
        StartTimer(MMS_VIEWER_TIMER, SRV_MMS_VIEWER_UNBLOCK_TIME, srv_mms_compute_rest_use_details);
    }
#endif /* __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__ */ 
#endif /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
    return MMI_UMMS_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_use_details_for_slide_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  process     [?]     [?]
 *  req         [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_mms_get_use_details_for_slide_ext(
            srv_mms_process_data_struct *process,
            srv_mms_get_use_details_viewer_req_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_process_data_struct *ex_process = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Reset prv process as response not sent due to some interrupts */
    if (g_srv_mms_use_details_cntx->process_id)
    {
        #ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
    if (g_srv_mms_use_details_cntx->file_handle)
    {
       
	FS_Close(g_srv_mms_use_details_cntx->file_handle);
        g_srv_mms_use_details_cntx->file_handle = 0;
    }
  
#endif /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
        ex_process = srv_mms_get_process_by_req_id(g_srv_mms_use_details_cntx->process_id);
        if (ex_process)
        {
            srv_mms_reset_process_data(ex_process);
        }
    }
    g_srv_mms_use_details_cntx->process_id = process->req_id = mma_get_request_id();
    if (!srv_mms_get_use_details_ready())
    {
        return MMI_FALSE;
    }
    if (g_desc->body->curr_slide->txt.id == 0 || g_desc->body->curr_slide->txt.str_id != 0)
    {
        /* Is it possible that exit the screen and the timer expiry is still in queue? Yes so call a safety catch */
        srv_mms_free_use_details_lists();
    #ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
        /* g_srv_mms_use_details_cntx->current_slide_shown = data->cat_info->msg_cntx->current_slide; */
        if (g_srv_mms_use_details_cntx->parsed_slide)
        {
            if (g_srv_mms_use_details_cntx->parsed_slide->txt.id == 0 ||
                g_srv_mms_use_details_cntx->parsed_slide->txt.str_id != 0)
            {
                g_srv_mms_use_details_cntx->parsed_slide = g_srv_mms_use_details_cntx->parsed_slide->next;
            }
        }
        StartTimer(
            MMS_VIEWER_TIMER,
            SRV_MMS_VIEWER_UNBLOCK_TIME,
            srv_mms_viewer_rsp_for_use_details_for_category_int);
        return MMI_FALSE;
    #endif /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
        return MMI_FALSE;
    }
    else
    {
        srv_mms_free_use_details_lists();
    #ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
        if (g_srv_mms_use_details_cntx->parsed_slide != NULL
            && (g_srv_mms_use_details_cntx->parsed_slide == g_desc->body->curr_slide)
            && (g_srv_mms_use_details_cntx->slide_not_parsed == MMI_FALSE))
        {
            g_srv_mms_use_details_cntx->count = 0;
            g_srv_mms_use_details_cntx->file_handle = FS_Open((PU16) g_srv_mms_use_details_cntx->file_path, FS_READ_WRITE);
            if (g_srv_mms_use_details_cntx->file_handle < 0)
            {
                g_srv_mms_use_details_cntx->fail_reason = g_srv_mms_use_details_cntx->file_handle;
                srv_mms_viewer_send_event_to_exit(0, g_srv_mms_use_details_cntx->fail_reason);
                return MMI_FALSE;
            }
            StartTimer(MMS_VIEWER_TIMER, SRV_MMS_VIEWER_UNBLOCK_TIME, srv_mms_viewer_start_compute_use_details_int);
        }
        else if (g_srv_mms_use_details_cntx->parsed_slide != NULL
                 && g_srv_mms_use_details_cntx->parsed_slide <= g_desc->body->curr_slide)
        {
            StartTimer(MMS_VIEWER_TIMER, SRV_MMS_VIEWER_UNBLOCK_TIME, srv_mms_compute_rest_use_details);
        }
        else
        {
            /* g_mv_cntx.app_state = MMI_MV_MID_SLIDE_CB_FINISHED; */
            StartTimer(MMS_VIEWER_TIMER, SRV_MMS_VIEWER_UNBLOCK_TIME, srv_mms_viewer_get_list_for_category);
            return MMI_FALSE;
        }
    #else /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
        /* StartTimer(MMS_VIEWER_TIMER, SRV_MMS_VIEWER_UNBLOCK_TIME, srv_mms_viewer_start_compute_use_details); */
        return MMI_TRUE;
    #endif /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_start_compute_use_details
 * DESCRIPTION
 *  start use detail parsing
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_mms_viewer_start_compute_use_details(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
    srv_mms_viewer_result_enum ret = SRV_MMS_VIEWER_PARSE_FAIL;
#endif 
    mma_mms_slide_struct *current_slide = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_copy_pools(index, APPLIB_MEM_AP_ID_MMS_VIEWER);
    if (index == 0)
    {
        if (srv_mms_initialize_with_instance(SRV_MMS_INSTANCE_DEFAULT_INDEX) == NULL)
        {
            return MMI_FALSE;
        }
    }
    else
    {
        if (srv_mms_initialize_with_instance(index) == NULL)
        {
            return MMI_FALSE;
        }
    }
    /* StopTimer(MMS_VIEWER_TIMER); */
#ifdef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__
    if (!g_srv_mms_cntx->is_srv_ready)
    {
        return MMI_FALSE;
    }
    g_srv_mms_use_details_cntx->current_slide = g_desc->body->curr_slide;
#else /* __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__ */ 
    /* There is no text object available for this slide. */
    if (g_srv_mms_use_details_cntx->current_slide->txt.id == 0 ||
        g_srv_mms_use_details_cntx->current_slide->txt.str_id != 0)
    {
        srv_mms_viewer_end_compute_use_details();
        return MMI_FALSE;
    }
#endif /* __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__ */ 
    /* We can't assume that the current slide text is in buffer already */
#ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
    g_srv_mms_use_details_cntx->p_ucs2_buffer = g_srv_mms_parser_cntx->use_detail_buffer;
    current_slide = g_srv_mms_use_details_cntx->parsed_slide;
#else /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
    g_srv_mms_use_details_cntx->p_ucs2_buffer = g_srv_mms_parser_cntx->slide_txt_buffer;
    current_slide = g_desc->body->curr_slide;
#endif /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
    if (current_slide->txt.id)
    {
        MMI_BOOL result;

        /* Following API opens/closes file Handle(s) */
        result = srv_mms_viewer_load_ucs2_txt_to_buffer(
                    g_srv_mms_use_details_cntx->p_ucs2_buffer,
                    SRV_MMS_TXT_BUF_UCS2_SIZE,
                    &current_slide->txt);
        if (result == MMI_FALSE)
        {
        #ifdef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__
            // TODO: handle error
            // TODO: put logs here
            g_srv_mms_use_details_cntx->slide_not_parsed = MMI_FALSE;
            FS_Close(g_srv_mms_use_details_cntx->file_handle);
            srv_mms_viewer_send_event_to_exit(SRV_MMS_VIEWER_FILE_ERROR, 0);
        #else /* __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__ */ 
            srv_mms_viewer_end_compute_use_details();
        #endif /* __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__ */ 
            return MMI_FALSE;
        }
    }
    g_srv_mms_use_details_cntx->ucs2_buffer_len =
        ENCODING_LENGTH * mmi_ucs2strlen((PS8) g_srv_mms_use_details_cntx->p_ucs2_buffer);
#ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__

    ret = srv_mms_calculate_use_details();
    switch (ret)
    {
        case SRV_MMS_VIEWER_PARSE_FAIL:
        case SRV_MMS_VIEWER_OUT_OF_MEM:
            g_srv_mms_use_details_cntx->slide_not_parsed = MMI_FALSE;
            FS_Close(g_srv_mms_use_details_cntx->file_handle);
            srv_mms_viewer_send_event_to_exit(ret, g_srv_mms_use_details_cntx->fail_reason);
            return;
        case SRV_MMS_VIEWER_PARSE_BLOCK:
            g_srv_mms_use_details_cntx->slide_not_parsed = MMI_TRUE;
            FS_Close(g_srv_mms_use_details_cntx->file_handle);
            StartTimer(MMS_VIEWER_TIMER, SRV_MMS_VIEWER_UNBLOCK_TIME, srv_mms_compute_rest_use_details);
            break;
        case SRV_MMS_VIEWER_PARSE_SUCCESS:
            g_srv_mms_use_details_cntx->slide_not_parsed = MMI_FALSE;
            g_srv_mms_use_details_cntx->parsed_slide = g_srv_mms_use_details_cntx->parsed_slide->next;
            FS_Close(g_srv_mms_use_details_cntx->file_handle);
            StartTimer(MMS_VIEWER_TIMER, SRV_MMS_VIEWER_UNBLOCK_TIME, srv_mms_viewer_get_list_for_category);
            break;
    }
#else /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
    /* StartTimer(MMS_VIEWER_TIMER, SRV_MMS_VIEWER_UNBLOCK_TIME, srv_mms_viewer_get_numbers_on_slide); */
    return MMI_TRUE;
#endif /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 

}

#ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_calculate_use_details
 * DESCRIPTION
 *  get numbers on slide
 * PARAMETERS
 *  void
 *  for_list [In](?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
static srv_mms_viewer_result_enum srv_mms_calculate_use_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_viewer_result_enum result = MMI_FALSE;
    srv_mms_use_detail_req_context_struct req_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_srv_mms_cntx->is_srv_ready)
    {
        /* We haven't already deinit the APP */
        return SRV_MMS_VIEWER_PARSE_FAIL;
    }
    /* Prepare Use Detail Parser Data */
    memset(&req_data, 0, sizeof(srv_mms_use_detail_req_context_struct));
    req_data.mem_alloc_fn = srv_mms_mem_mgr_viewer_asm_alloc;
    req_data.mem_free_fn = srv_mms_mem_mgr_viewer_asm_free;
    req_data.input_data = (PU16) g_srv_mms_use_details_cntx->p_ucs2_buffer;
    req_data.total_slides = g_desc->body->slide_no;
    req_data.slide_num = g_srv_mms_use_details_cntx->parsed_slide->slide_num;
    req_data.number_count = &g_srv_mms_use_details_cntx->number_count;
    req_data.email_count = &g_srv_mms_use_details_cntx->email_count;
    req_data.url_count = &g_srv_mms_use_details_cntx->url_count;
    req_data.header = g_srv_mms_use_details_cntx->header;
    req_data.fail_reason = &g_srv_mms_use_details_cntx->fail_reason;
    req_data.dataLen = g_srv_mms_use_details_cntx->ucs2_buffer_len;
    req_data.file_handle = g_srv_mms_use_details_cntx->file_handle;
    req_data.slide_not_parsed = g_srv_mms_use_details_cntx->slide_not_parsed;
    g_srv_mms_use_details_cntx->count = 0;

    result = srv_mms_common_parse(&req_data);
    return result;

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_compute_rest_use_details
 * DESCRIPTION
 *  computes use details of slides not openned yet
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_compute_rest_use_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_viewer_result_enum ret = SRV_MMS_VIEWER_PARSE_FAIL;
    MMI_BOOL slide_not_shown = MMI_FALSE;
    mmi_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(MMS_VIEWER_TIMER);
    if (!g_srv_mms_cntx->is_srv_ready)
    {
        return;
    }
    if (g_srv_mms_use_details_cntx->parsed_slide)
    {
        g_srv_mms_use_details_cntx->file_handle = FS_Open((PU16) g_srv_mms_use_details_cntx->file_path, FS_READ_WRITE | FS_OPEN_NO_DIR);
        if (g_srv_mms_use_details_cntx->file_handle < 0)
        {
            g_srv_mms_use_details_cntx->fail_reason = g_srv_mms_use_details_cntx->file_handle;
            srv_mms_viewer_send_event_to_exit(ret, g_srv_mms_use_details_cntx->fail_reason);
            return;
        }
        /* We can't assume that the current slide text is in buffer already */
        g_srv_mms_use_details_cntx->p_ucs2_buffer = g_srv_mms_parser_cntx->use_detail_buffer;
        if (g_srv_mms_use_details_cntx->parsed_slide->txt.id &&
            g_srv_mms_use_details_cntx->parsed_slide->txt.str_id == 0)
        {
            MMI_BOOL result;

            /* Following API opens/closes file Handle(s) */
            result = srv_mms_viewer_load_ucs2_txt_to_buffer(
                        g_srv_mms_use_details_cntx->p_ucs2_buffer,
                        SRV_MMS_TXT_BUF_UCS2_SIZE,
                        &g_srv_mms_use_details_cntx->parsed_slide->txt);
            if (result == MMI_FALSE)
            {
                return;
            }
            g_srv_mms_use_details_cntx->ucs2_buffer_len =
                ENCODING_LENGTH * mmi_ucs2strlen((PS8) g_srv_mms_use_details_cntx->p_ucs2_buffer);
            ret = srv_mms_calculate_use_details();
            switch (ret)
            {
                case SRV_MMS_VIEWER_PARSE_FAIL:
                case SRV_MMS_VIEWER_OUT_OF_MEM:
                    g_srv_mms_use_details_cntx->slide_not_parsed = MMI_FALSE;
                    FS_Close(g_srv_mms_use_details_cntx->file_handle);
                    srv_mms_viewer_send_event_to_exit(ret, g_srv_mms_use_details_cntx->fail_reason);
                    return;
                case SRV_MMS_VIEWER_PARSE_BLOCK:
                    g_srv_mms_use_details_cntx->slide_not_parsed = MMI_TRUE;
                    FS_Close(g_srv_mms_use_details_cntx->file_handle);
                    break;
                case SRV_MMS_VIEWER_PARSE_SUCCESS:
                    g_srv_mms_use_details_cntx->slide_not_parsed = MMI_FALSE;
                    if (g_srv_mms_use_details_cntx->parsed_slide == g_desc->body->curr_slide)
                    {
                        slide_not_shown = MMI_TRUE;
                    }
                    g_srv_mms_use_details_cntx->parsed_slide = g_srv_mms_use_details_cntx->parsed_slide->next;
                    FS_Close(g_srv_mms_use_details_cntx->file_handle);
                    break;
            }
        }
        else
        {
            g_srv_mms_use_details_cntx->parsed_slide = g_srv_mms_use_details_cntx->parsed_slide->next;
            FS_Close(g_srv_mms_use_details_cntx->file_handle);
        }

    }
    if (slide_not_shown)
    {
        slide_not_shown = MMI_FALSE;
        /* g_mv_cntx.app_state = MMI_MV_MID_SLIDE_CB_FINISHED; */
        StartTimer(MMS_VIEWER_TIMER, SRV_MMS_VIEWER_UNBLOCK_TIME, srv_mms_viewer_get_list_for_category);
        if (!g_srv_mms_use_details_cntx->parsed_slide && g_srv_mms_parser_cntx->use_detail_buffer)
        {
            srv_mms_mem_mgr_viewer_asm_free(g_srv_mms_parser_cntx->use_detail_buffer);
            g_srv_mms_parser_cntx->use_detail_buffer = NULL;
        }
    }
    else if (g_srv_mms_use_details_cntx->parsed_slide)
    {
        StartTimer(MMS_VIEWER_TIMER, SRV_MMS_USE_DETAILS_UNBLOCK_TIME, srv_mms_viewer_take_break);
    }
    else
    {
        g_srv_mms_use_details_cntx->number_total_count = g_srv_mms_use_details_cntx->number_count;
        g_srv_mms_use_details_cntx->email_total_count = g_srv_mms_use_details_cntx->email_count;
        g_srv_mms_use_details_cntx->url_total_count = g_srv_mms_use_details_cntx->url_count;
        
        if (g_srv_mms_parser_cntx->use_detail_buffer)
        {
            srv_mms_mem_mgr_viewer_asm_free(g_srv_mms_parser_cntx->use_detail_buffer);
            g_srv_mms_parser_cntx->use_detail_buffer = NULL;
        }
        srv_mms_send_events(EVT_ID_SRV_UPDATE_USE_DETAILS_LIST, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_take_break
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mms_viewer_take_break(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(MMS_VIEWER_TIMER);
    if (g_srv_mms_use_details_cntx->parsed_slide)
    {
        srv_mms_compute_rest_use_details();
    }
}

/* Amitesh Added */


/*****************************************************************************
 * FUNCTION
 *  srv_mms_load_use_details
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type            [IN]        
 *  curr_index      [IN]        
 *  start_index     [?]         [?]
 *  end_index       [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_load_use_details(applib_addr_type_enum type, S32 curr_index, S32 *start_index, S32 *end_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_ret = 0, len = 0, last_count = 0;
    S32 count_total = 0, count_data = 0, size_read = 0, curr_count = 0, curr_offset = 0;
    S16 *size_num = NULL, *size_email = NULL, *size_url = NULL, *size = NULL, *buffer = NULL;
    S32 count = 0, count_detail = 0;
    U32 read_bytes = 0;
    applib_address_node_struct *node, *temp_node = NULL;
    MMI_BOOL result = MMI_FALSE, is_more_required = MMI_FALSE;
    mma_mms_slide_struct *current_slide = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_get_use_details_deinit();
    g_srv_mms_use_details_cntx->file_handle = FS_Open((PU16) g_srv_mms_use_details_cntx->file_path, FS_READ_ONLY | FS_OPEN_NO_DIR);
    if (g_srv_mms_use_details_cntx->file_handle < 0)
    {
        return MMI_FALSE;
    }
    size_num = (S16*) srv_mms_mem_mgr_viewer_asm_alloc(sizeof(S16) * g_desc->body->slide_no);
    ASSERT(size_num);
    memset(size_num, 0, sizeof(S16) * g_desc->body->slide_no);
    size_email = (S16*) srv_mms_mem_mgr_viewer_asm_alloc(sizeof(S16) * g_desc->body->slide_no);
    ASSERT(size_email);
    memset(size_email, 0, sizeof(S16) * g_desc->body->slide_no);
    size_url = (S16*) srv_mms_mem_mgr_viewer_asm_alloc(sizeof(S16) * g_desc->body->slide_no);
    ASSERT(size_url);
    memset(size_url, 0, sizeof(S16) * g_desc->body->slide_no);
    fs_ret = FS_Read(
                g_srv_mms_use_details_cntx->file_handle,
                size_num,
                g_desc->body->slide_no * sizeof(S16),
                &read_bytes);
    fs_ret = FS_Read(
                g_srv_mms_use_details_cntx->file_handle,
                size_email,
                g_desc->body->slide_no * sizeof(S16),
                &read_bytes);
    fs_ret = FS_Read(
                g_srv_mms_use_details_cntx->file_handle,
                size_url,
                g_desc->body->slide_no * sizeof(S16),
                &read_bytes);
    if (type == APPLIB_ADDR_TYPE_PHONENUMBER)
    {
        size = size_num;
    }
    else if (type == APPLIB_ADDR_TYPE_EMAIL)
    {
        size = size_email;
    }
    else
    {
        size = size_url;
    }
    if (curr_index == 0)
    {
        curr_offset = 0;
        current_slide = g_srv_mms_use_details_cntx->first_slide;
        curr_count = 0;
    }
    if (curr_index != 0)
    {
        S32 temp_count = SRV_MMS_MAX_USE_DETAILS_WHOLE_SLIDE;

        count_detail = 0;
        {
            current_slide = g_srv_mms_use_details_cntx->first_slide;
            while (current_slide != NULL)
            {
                count_detail += size[current_slide->slide_num - 1];
                if (count_detail >= curr_index)
                {
                    curr_count = size[current_slide->slide_num - 1] - count_detail + curr_index;
                    break;
                }
                current_slide = current_slide->next;
            }
            for (count = 0; current_slide != NULL && count < current_slide->slide_num - 1; count++)
            {
                count_data += size_num[count] + size_email[count] + size_url[count];
            }
            curr_offset = FS_Seek(g_srv_mms_use_details_cntx->file_handle, 0, FS_FILE_CURRENT);
            ASSERT(current_slide);
            switch (type)
            {
                case APPLIB_ADDR_TYPE_PHONENUMBER:
                    break;
                case APPLIB_ADDR_TYPE_EMAIL:
                    curr_offset += 2 * (size_num[current_slide->slide_num - 1]) * sizeof(S16);
                    break;
                case APPLIB_ADDR_TYPE_URL:
                    curr_offset +=
                        2 * (size_num[current_slide->slide_num - 1] +
                             size_email[current_slide->slide_num - 1]) * sizeof(S16);
                    break;
            }
            curr_offset += (2 * (count_data + curr_count)) * sizeof(S16);
        }
        count_detail = 0;
        while (current_slide)
        {
            if (curr_count > 0)
            {
                count_detail += curr_count;
            }
            else
            {
                count_detail += size[current_slide->slide_num - 1];
            }
            if (count_detail >= SRV_MMS_MAX_USE_DETAILS_WHOLE_SLIDE)
            {
                curr_offset = curr_offset - (temp_count * 2 * sizeof(S16));
                if (count_detail >= SRV_MMS_MAX_USE_DETAILS_WHOLE_SLIDE)
                {
                    if (curr_count == 0)
                    {
                        curr_count = size[current_slide->slide_num - 1] - temp_count;
                    }
                    else
                    {
                        curr_count -= (S32) temp_count;
                    }
                }
                break;
            }
            if (count_detail >= size[current_slide->slide_num - 1])
            {
                curr_offset = curr_offset - (size[current_slide->slide_num - 1] * 2 * sizeof(S16));
            }
            else
            {
                curr_offset = curr_offset - (count_detail * 2 * sizeof(S16));
            }
            srv_mms_get_new_offset_on_slide(size_num, size_email, size_url, type, &curr_offset, &current_slide);
            curr_count = 0;
            temp_count = SRV_MMS_MAX_USE_DETAILS_WHOLE_SLIDE - count_detail;
        }
        if (count_detail > SRV_MMS_MAX_USE_DETAILS_WHOLE_SLIDE)
        {
            count_detail = SRV_MMS_MAX_USE_DETAILS_WHOLE_SLIDE;
        }
        *(start_index) = curr_index - count_detail;
        if (!current_slide)
        {
            current_slide = g_srv_mms_use_details_cntx->first_slide;
        }
    }
    if (!curr_offset)
    {
        switch (type)
        {
            case APPLIB_ADDR_TYPE_PHONENUMBER:
                if (g_srv_mms_use_details_cntx->number_count == 0)
                {
                    result = MMI_TRUE;
                    break;
                }
                size = size_num;
                break;
            case APPLIB_ADDR_TYPE_EMAIL:
                if (g_srv_mms_use_details_cntx->email_count == 0)
                {
                    result = MMI_TRUE;
                    break;
                }
                fs_ret = FS_Seek(
                            g_srv_mms_use_details_cntx->file_handle,
                            (2 * size_num[current_slide->slide_num - 1]) * sizeof(S16),
                            FS_FILE_CURRENT);
                if (fs_ret < 0)
                {
                    result = MMI_TRUE;
                    break;
                }
                size = size_email;
                break;
            case APPLIB_ADDR_TYPE_URL:
                if (g_srv_mms_use_details_cntx->url_count == 0)
                {
                    result = MMI_TRUE;
                    break;
                }
                fs_ret = FS_Seek(
                            g_srv_mms_use_details_cntx->file_handle,
                            (2 * (size_num[current_slide->slide_num - 1] + size_email[current_slide->slide_num - 1])) * sizeof(S16),
                            FS_FILE_CURRENT);
                if (fs_ret < 0)
                {
                    result = MMI_TRUE;
                    break;
                }
                size = size_url;
                break;
        }
        if (result == MMI_TRUE)
        {
            FS_Close(g_srv_mms_use_details_cntx->file_handle);
            srv_mms_mem_mgr_viewer_asm_free(size_num);
            srv_mms_mem_mgr_viewer_asm_free(size_email);
            srv_mms_mem_mgr_viewer_asm_free(size_url);
            return MMI_TRUE;
        }
    }
    else
    {
        fs_ret = FS_Seek(g_srv_mms_use_details_cntx->file_handle, curr_offset, FS_FILE_BEGIN);
    }
    while (current_slide != NULL)
    {
        if (size[current_slide->slide_num - 1])
        {
            g_srv_mms_use_details_cntx->p_ucs2_buffer = g_srv_mms_parser_cntx->slide_txt_buffer;
            result = srv_mms_viewer_load_ucs2_txt_to_buffer(
                        g_srv_mms_use_details_cntx->p_ucs2_buffer,
                        SRV_MMS_TXT_BUF_UCS2_SIZE,
                        &current_slide->txt);
            if (result == MMI_FALSE)
            {
                return MMI_FALSE;
            }
            size_read = SRV_MMS_VIEWER_MAX_USE_DETAILS_WHOLE_SLIDE - last_count;
            if (curr_index != 0)
            {
                size_read = size_read + SRV_MMS_MAX_USE_DETAILS_WHOLE_SLIDE;
            }
            if (size_read > size[current_slide->slide_num - 1] - curr_count)
            {
                size_read = size[current_slide->slide_num - 1] - curr_count;
                is_more_required = MMI_TRUE;
            }
            buffer = (S16*) srv_mms_mem_mgr_viewer_asm_alloc((2 * size_read) * sizeof(S16));
            ASSERT(buffer);
            memset(buffer, 0, (2 * size_read) * sizeof(S16));
            fs_ret = FS_Read(g_srv_mms_use_details_cntx->file_handle, buffer, (2 * size_read) * sizeof(S16), &read_bytes);
            for (count = 0; count < size_read; count++)
            {
                node =
                    (applib_address_node_struct*) srv_mms_mem_mgr_viewer_asm_alloc(sizeof(applib_address_node_struct));
                ASSERT(node);
                memset(node, 0, sizeof(applib_address_node_struct));
                node->pos = buffer[count_total] * ENCODING_LENGTH;
                node->length = buffer[count_total + 1];
                if (type == APPLIB_ADDR_TYPE_PHONENUMBER)
                {
                    if (node->length > SRV_UC_MAX_PHONE_NUMBER_LEN)
                    {
                        node->length = SRV_UC_MAX_PHONE_NUMBER_LEN + 1;
                    }
                }
                else if (type == APPLIB_ADDR_TYPE_URL)
                {
                    if (node->length > SRV_MMS_MAX_URL_LENGTH)
                    {
                        node->length = SRV_MMS_MAX_URL_LENGTH + 1;
                    }
                }
                else
                {
                    if (node->length > MMI_EMAIL_MAX_ADDR_LEN)
                    {
                        node->length = MMI_EMAIL_MAX_ADDR_LEN + 1;
                    }
                }
                len = node->length * ENCODING_LENGTH + 2;
                node->data = (kal_wchar*) srv_mms_mem_mgr_viewer_asm_alloc(len);
                ASSERT(node->data);
                memset(node->data, 0, len);
                mmi_ucs2ncpy(
                    (PS8) node->data,
                    (PS8) g_srv_mms_use_details_cntx->p_ucs2_buffer + node->pos,
                    node->length);
                node->data2 = NULL;
                if (type == APPLIB_ADDR_TYPE_PHONENUMBER)
                {
                    node->data2 =
                        (kal_wchar*) srv_mms_duplicate_phoneno_no_written_sep(
                                        srv_mms_mem_mgr_viewer_asm_alloc,
                                        (PU16) node->data);
                }
                node->dataType = type;
                node->next = NULL;
                if (temp_node)
                {
                    applib_address_node_struct *itr = NULL;

                    itr = temp_node;
                    while (itr->next)
                    {
                        itr = itr->next;
                    }
                    itr->next = node;
                }
                else
                {
                    temp_node = node;
                }
                count_total = count_total + 2;
                g_srv_mms_use_details_cntx->current_count++;
            }
            if (is_more_required)
            {
                is_more_required = MMI_FALSE;
                last_count = g_srv_mms_use_details_cntx->current_count;
                curr_count = 0;
                count_total = 0;
                if (srv_mms_get_offset_on_next_slide
                    (g_srv_mms_use_details_cntx->file_handle, size_num, size_email, size_url, type, &curr_offset,
                     &current_slide) == MMI_FALSE)
                {
                    curr_offset = 0;
                    break;
                }
                if (g_srv_mms_use_details_cntx->parsed_slide && current_slide &&
                    current_slide->slide_num >= g_srv_mms_use_details_cntx->parsed_slide->slide_num)
                {
                    current_slide = g_srv_mms_use_details_cntx->parsed_slide->prev;
                    if (!current_slide)
                    {
                        current_slide = g_srv_mms_use_details_cntx->first_slide;
                    }
                    curr_offset = FS_Seek(g_srv_mms_use_details_cntx->file_handle, 0, FS_FILE_CURRENT);
                    curr_count = size_read;
                    break;
                }
            }
            else
            {
                curr_offset = FS_Seek(g_srv_mms_use_details_cntx->file_handle, 0, FS_FILE_CURRENT);
                curr_count += size_read;
                break;
            }
            if (buffer)
            {
                srv_mms_mem_mgr_viewer_asm_free(buffer);
                buffer = NULL;
            }
        }
        else
        {
            if (srv_mms_get_offset_on_next_slide
                (g_srv_mms_use_details_cntx->file_handle, size_num, size_email, size_url, type, &curr_offset,
                 &current_slide) == MMI_FALSE)
            {
                curr_offset = 0;
                break;
            }
        }

    }
    FS_Close(g_srv_mms_use_details_cntx->file_handle);
    if (buffer)
    {
        srv_mms_mem_mgr_viewer_asm_free(buffer);
        buffer = NULL;
    }
    *end_index = *start_index + g_srv_mms_use_details_cntx->current_count - 1;
    srv_mms_mem_mgr_viewer_asm_free(size_num);
    srv_mms_mem_mgr_viewer_asm_free(size_email);
    srv_mms_mem_mgr_viewer_asm_free(size_url);
    switch (type)
    {
        case APPLIB_ADDR_TYPE_PHONENUMBER:
            g_srv_mms_use_details_cntx->applib_phnum_list = temp_node;
            break;
        case APPLIB_ADDR_TYPE_EMAIL:
            g_srv_mms_use_details_cntx->applib_email_list = temp_node;
            break;
        case APPLIB_ADDR_TYPE_URL:
            g_srv_mms_use_details_cntx->applib_url_list = temp_node;
            break;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_total_use_detail_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_mms_get_total_use_detail_count(applib_addr_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case APPLIB_ADDR_TYPE_PHONENUMBER:
            ret_count = g_srv_mms_use_details_cntx->number_total_count;
            break;
        case APPLIB_ADDR_TYPE_EMAIL:
            ret_count = g_srv_mms_use_details_cntx->email_total_count;
            break;
        case APPLIB_ADDR_TYPE_URL:
            ret_count = g_srv_mms_use_details_cntx->url_total_count;
            break;
        default:
            MMI_ASSERT(0);
            break;
    }
    return ret_count;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_close_use_detail_file_hdl
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_close_use_detail_file_hdl(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_mms_use_details_cntx->file_handle)
    {
        FS_Close(g_srv_mms_use_details_cntx->file_handle);
        g_srv_mms_use_details_cntx->file_handle = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_is_use_detail_parsing_going_on
 * DESCRIPTION
 *  Checks whether more use details are parsed
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE:IF moe details parsed
 *  FLASE:IF moe details parsed
 *****************************************************************************/
MMI_BOOL srv_mms_is_use_detail_parsing_going_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_mms_use_details_cntx->parsed_slide)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_offset_on_next_slide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_handle         [IN]        
 *  size_num            [?]         [?]
 *  size_email          [?]         [?]
 *  size_url            [?]         [?]
 *  type                [IN]        
 *  curr_offset         [?]         [?]
 *  current_slide       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_get_offset_on_next_slide(
            S32 file_handle,
            S16 *size_num,
            S16 *size_email,
            S16 *size_url,
            applib_addr_type_enum type,
            S32 *curr_offset,
            mma_mms_slide_struct **current_slide)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 fs_ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((*current_slide)->next == NULL)
    {
        (*current_slide) = g_srv_mms_use_details_cntx->first_slide;
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_USE_DETAIL_LST_SLIDE_REACHED);
        return MMI_FALSE;
    }
    if ((*current_slide)->next == g_srv_mms_use_details_cntx->parsed_slide)
    {
        (*current_slide) = (*current_slide)->next;
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_USE_DETAIL_LST_PARSED_SLIDE_REACHED);
        return MMI_TRUE;
    }
    switch (type)
    {
        case APPLIB_ADDR_TYPE_PHONENUMBER:
            fs_ret = FS_Seek(
                        file_handle,
                        (2 * (size_email[(*current_slide)->slide_num - 1] + size_url[(*current_slide)->slide_num - 1])) * sizeof(S16),
                        FS_FILE_CURRENT);
            (*current_slide) = (*current_slide)->next;
            break;
        case APPLIB_ADDR_TYPE_EMAIL:
            fs_ret = FS_Seek(
                        file_handle,
                        (2 * size_url[(*current_slide)->slide_num - 1]) * sizeof(S16),
                        FS_FILE_CURRENT);
            (*current_slide) = (*current_slide)->next;
            fs_ret = FS_Seek(
                        file_handle,
                        (2 * size_num[(*current_slide)->slide_num - 1]) * sizeof(S16),
                        FS_FILE_CURRENT);
            break;
        case APPLIB_ADDR_TYPE_URL:
            (*current_slide) = (*current_slide)->next;
            fs_ret = FS_Seek(
                        file_handle,
                        (2 * (size_num[(*current_slide)->slide_num - 1] + size_email[(*current_slide)->slide_num - 1])) * sizeof(S16),
                        FS_FILE_CURRENT);
            break;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_new_offset_on_slide
 * DESCRIPTION
 *  Show JAVA MMS PopUp.
 * PARAMETERS
 *  size_num            [?]         [?]
 *  size_email          [?]         [?]
 *  size_url            [?]         [?]
 *  type                [IN]        
 *  curr_offset         [?]         [?]
 *  current_slide       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_get_new_offset_on_slide(
        S16 *size_num,
        S16 *size_email,
        S16 *size_url,
        applib_addr_type_enum type,
        S32 *curr_offset,
        mma_mms_slide_struct **current_slide)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(*current_slide)->prev)
    {
        (*current_slide) = (*current_slide)->prev;
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_USE_DETAIL_FIRST_SLIDE_REACHED);
        return;
    }
    switch (type)
    {
        case APPLIB_ADDR_TYPE_PHONENUMBER:
            (*current_slide) = (*current_slide)->prev;
            *curr_offset -=
                (2 * (size_email[(*current_slide)->slide_num - 1] + size_url[(*current_slide)->slide_num - 1])) *
                sizeof(S16);
            break;
        case APPLIB_ADDR_TYPE_EMAIL:
            *curr_offset -= (2 * size_num[(*current_slide)->slide_num - 1]) * sizeof(S16);
            (*current_slide) = (*current_slide)->prev;
            *curr_offset -= (2 * size_url[(*current_slide)->slide_num - 1]) * sizeof(S16);
            break;
        case APPLIB_ADDR_TYPE_URL:
            *curr_offset -=
                (2 * (size_num[(*current_slide)->slide_num - 1] + size_email[(*current_slide)->slide_num - 1])) *
                sizeof(S16);
            (*current_slide) = (*current_slide)->prev;
            break;
    }
}
#endif /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
#if defined (__MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__) && defined (__MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__)


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_get_list_for_category
 * DESCRIPTION
 *  Reads from file and makes ready list for category
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE: If list loaded successfully(?)(?)
 *  FALSE:Otherwise(?)(?)
 *****************************************************************************/
static void srv_mms_viewer_get_list_for_category(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_ret = 0, count_data = 0, count_detail[3] = {0, 0, 0};
    S16 *size_num = NULL, *size_email = NULL, *size_url = NULL, count = 0, last_count = 0;
    U32 read_bytes = 0;
    applib_addr_type_enum detail_type[3];
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_mms_use_details_cntx->file_handle = FS_Open(g_srv_mms_use_details_cntx->file_path, FS_READ_ONLY | FS_OPEN_NO_DIR);
    if (g_srv_mms_use_details_cntx->file_handle < 0)
    {
        g_srv_mms_use_details_cntx->fail_reason = g_srv_mms_use_details_cntx->file_handle;
        srv_mms_viewer_send_event_to_exit(0, g_srv_mms_use_details_cntx->fail_reason);
        return;
    }
    g_srv_mms_use_details_cntx->p_ucs2_buffer = g_srv_mms_parser_cntx->slide_txt_buffer;
    result = srv_mms_viewer_load_ucs2_txt_to_buffer(
                g_srv_mms_use_details_cntx->p_ucs2_buffer,
                SRV_MMS_TXT_BUF_UCS2_SIZE,
                &g_desc->body->curr_slide->txt);
    if (result == MMI_FALSE)
    {
        return;
    }
    size_num = (S16*) srv_mms_mem_mgr_viewer_asm_alloc(sizeof(S16) * (g_desc->body)->curr_slide->slide_num);
    ASSERT(size_num);
    memset(size_num, 0, sizeof(S16) * (g_desc->body)->curr_slide->slide_num);
    size_email = (S16*) srv_mms_mem_mgr_viewer_asm_alloc(sizeof(S16) * (g_desc->body)->curr_slide->slide_num);
    ASSERT(size_email);
    memset(size_email, 0, sizeof(S16) * (g_desc->body)->curr_slide->slide_num);
    size_url = (S16*) srv_mms_mem_mgr_viewer_asm_alloc(sizeof(S16) * (g_desc->body)->curr_slide->slide_num);
    memset(size_url, 0, sizeof(S16) * (g_desc->body)->curr_slide->slide_num);
    ASSERT(size_url);
    fs_ret = FS_Read(
                g_srv_mms_use_details_cntx->file_handle,
                size_num,
                g_desc->body->curr_slide->slide_num * sizeof(S16),
                &read_bytes);
    fs_ret = FS_Seek(
                g_srv_mms_use_details_cntx->file_handle,
                (g_desc->body->slide_no - g_desc->body->curr_slide->slide_num) * sizeof(S16),
                FS_FILE_CURRENT);
    fs_ret = FS_Read(
                g_srv_mms_use_details_cntx->file_handle,
                size_email,
                ((g_desc->body)->curr_slide->slide_num) * sizeof(S16),
                &read_bytes);
    fs_ret = FS_Seek(
                g_srv_mms_use_details_cntx->file_handle,
                (g_desc->body->slide_no - g_desc->body->curr_slide->slide_num) * sizeof(S16),
                FS_FILE_CURRENT);
    fs_ret = FS_Read(
                g_srv_mms_use_details_cntx->file_handle,
                size_url,
                ((g_desc->body)->curr_slide->slide_num) * sizeof(S16),
                &read_bytes);
    fs_ret = FS_Seek(
                g_srv_mms_use_details_cntx->file_handle,
                ((g_desc->body)->slide_no - (g_desc->body)->curr_slide->slide_num) * sizeof(S16),
                FS_FILE_CURRENT);
    for (count = 0; count < (g_desc->body)->curr_slide->slide_num - 1; count++)
    {
        count_data += size_num[count] + size_email[count] + size_url[count];
    }

    count_detail[0] = size_num[(g_desc->body)->curr_slide->slide_num - 1];
    count_detail[1] = size_email[(g_desc->body)->curr_slide->slide_num - 1];
    count_detail[2] = size_url[(g_desc->body)->curr_slide->slide_num - 1];
    detail_type[0] = APPLIB_ADDR_TYPE_PHONENUMBER;
    detail_type[1] = APPLIB_ADDR_TYPE_EMAIL;
    detail_type[2] = APPLIB_ADDR_TYPE_URL;

    srv_mms_mem_mgr_viewer_asm_free(size_num);
    srv_mms_mem_mgr_viewer_asm_free(size_email);
    srv_mms_mem_mgr_viewer_asm_free(size_url);
    fs_ret = FS_Seek(g_srv_mms_use_details_cntx->file_handle, (2 * count_data) * sizeof(S16), FS_FILE_CURRENT);
    for (count = 0; count < 3; count++)
    {
        if (count == 1)
        {
            fs_ret = FS_Seek(
                        g_srv_mms_use_details_cntx->file_handle,
                        ((count_detail[0] - last_count) * 2) * sizeof(S16),
                        FS_FILE_CURRENT);
            if (!count_detail[count])
            {
                last_count = 0;
                continue;
            }
        }
        else if (count == 2 && count_detail[count])
        {
            fs_ret = FS_Seek(
                        g_srv_mms_use_details_cntx->file_handle,
                        ((count_detail[1] - last_count) * 2) * sizeof(S16),
                        FS_FILE_CURRENT);
            if (!count_detail[count])
            {
                last_count = 0;
                continue;
            }
        }
        else
        {
            if (!count_detail[count])
            {
                last_count = 0;
                continue;
            }
        }
        last_count = srv_mms_viewer_fill_slide_data(
                        g_srv_mms_use_details_cntx->file_handle,
                        detail_type[count],
                        count_detail[count]);
        if (last_count == -1)
        {
            return;
            /* show error popup */
        }
    }
    FS_Close(g_srv_mms_use_details_cntx->file_handle);
    StartTimer(MMS_VIEWER_TIMER, SRV_MMS_VIEWER_UNBLOCK_TIME, srv_mms_viewer_sort_use_detail_list_for_category_int);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_rsp_for_use_details_for_category_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_viewer_rsp_for_use_details_for_category_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_viewer_rsp_for_use_details_for_category(SRV_MMS_INSTANCE_DEFAULT_INDEX);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_sort_use_detail_list_for_category_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_viewer_sort_use_detail_list_for_category_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_viewer_sort_use_detail_list_for_category();
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_start_compute_use_details_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_viewer_start_compute_use_details_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_viewer_start_compute_use_details(SRV_MMS_INSTANCE_DEFAULT_INDEX);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_fill_slide_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_handle     [IN]        
 *  detail_type     [IN]        
 *  size            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_mms_viewer_fill_slide_data(S32 file_handle, applib_addr_type_enum detail_type, S32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 *buffer = NULL, count = 0;
    S32 fs_ret = 0;
    srv_mms_viewer_use_details_list *t = NULL;
    applib_address_node_struct *node = NULL;
    U32 read_bytes = 0;
    MMI_BOOL add_url = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef BROWSER_SUPPORT
    if (detail_type == APPLIB_ADDR_TYPE_URL)
    {
        add_url = MMI_FALSE;
    }
#endif /* BROWSER_SUPPORT */ 
    if (size > SRV_MMS_MAX_USE_DETAILS_PER_SLIDE)
    {
        size = SRV_MMS_MAX_USE_DETAILS_PER_SLIDE;
    }
    if (file_handle)
    {
        buffer = (S16*) srv_mms_mem_mgr_viewer_asm_alloc((size * 2) * sizeof(S16));
        ASSERT(buffer);
        memset(buffer, 0, (size * 2) * sizeof(S16));
        fs_ret = FS_Read(file_handle, buffer, (size * 2) * sizeof(S16), &read_bytes);
    }
    ASSERT(buffer);
    if (add_url == MMI_TRUE)
    {
        for (count = 0; count < (size * 2); count = count + 2)
        {
            g_srv_mms_use_details_cntx->count += 1;
            t = srv_mms_mem_mgr_viewer_asm_alloc(sizeof(srv_mms_viewer_use_details_list));
            ASSERT(t);
            memset(t, 0, sizeof(srv_mms_viewer_use_details_list));
            if (t == NULL)
            {
                srv_mms_viewer_send_event_to_exit(SRV_MMS_VIEWER_OUT_OF_MEM, g_srv_mms_use_details_cntx->fail_reason);
                return -1;
            }
            t->offset = buffer[count];
            t->len = buffer[count + 1];
            node = (applib_address_node_struct*) srv_mms_mem_mgr_viewer_asm_alloc(sizeof(applib_address_node_struct));
            ASSERT(node);
            memset(node, 0, sizeof(applib_address_node_struct));
            node->data = (kal_wchar*) srv_mms_mem_mgr_viewer_asm_alloc((t->len * ENCODING_LENGTH + 2));
            ASSERT(node->data);
            memset(node->data, 0, (t->len * ENCODING_LENGTH + 2));
            mmi_ucs2ncpy(
                (PS8) node->data,
                (PS8) g_srv_mms_use_details_cntx->p_ucs2_buffer + (t->offset * ENCODING_LENGTH),
                t->len);
            if (detail_type == APPLIB_ADDR_TYPE_PHONENUMBER)
            {
                node->data2 =
                    (kal_wchar*) srv_mms_duplicate_phoneno_no_written_sep(
                                    srv_mms_mem_mgr_viewer_asm_alloc,
                                    (PU16) node->data);
            }
            /* node->data2 = NULL; */
            node->pos = t->offset;
            node->length = t->len;
            node->dataType = detail_type;
            node->next = NULL;
            t->item = node;
            if (g_srv_mms_use_details_cntx->flat_details_list)
            {
                srv_mms_viewer_use_details_list *iterator = g_srv_mms_use_details_cntx->flat_details_list;

                while (iterator->next)
                {
                    iterator = iterator->next;
                }
                iterator->next = t;
                t->next = NULL;
                t->prev = iterator;
            }
            else
            {
                t->next = NULL;
                t->prev = NULL;
                g_srv_mms_use_details_cntx->flat_details_list = t;
            }
        }
    }
    if (file_handle)
    {
        srv_mms_mem_mgr_viewer_asm_free(buffer);
    }
    return (count / 2);
}

#endif /* defined (__MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__) && defined (__MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__) */ 



/*****************************************************************************
 * FUNCTION
 *  srv_mms_free_use_details_lists
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mms_free_use_details_lists(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL free_mem;
#ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
    applib_address_node_struct *node;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //g_srv_mms_use_details_cntx->current_highlighted = NULL;
    //g_srv_mms_use_details_cntx->current_use_detail = NULL;

    if (g_srv_mms_use_details_cntx->flat_details_list)
    {
        srv_mms_viewer_use_details_list *i = g_srv_mms_use_details_cntx->flat_details_list;

        while (i)
        {
            srv_mms_viewer_use_details_list *t = i;

            i = i->next;
        #ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
            node = (applib_address_node_struct*) t->item;
            srv_mms_mem_mgr_viewer_asm_free(node->data);
            srv_mms_mem_mgr_viewer_asm_free(node->data2);
            srv_mms_mem_mgr_viewer_asm_free(node);
        #endif /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
            srv_mms_mem_mgr_viewer_asm_free(t);
        }

        g_srv_mms_use_details_cntx->flat_details_list = NULL;
    }

    if (g_srv_mms_use_details_cntx->applib_phnum_list)
    {
        free_mem = applib_free_address_list(&g_srv_mms_use_details_cntx->applib_phnum_list, srv_mms_mem_mgr_viewer_asm_free);
        g_srv_mms_use_details_cntx->applib_phnum_list = NULL;
        MMI_ASSERT(free_mem);
    }

    if (g_srv_mms_use_details_cntx->applib_email_list)
    {
        free_mem = applib_free_address_list(&g_srv_mms_use_details_cntx->applib_email_list, srv_mms_mem_mgr_viewer_asm_free);
        g_srv_mms_use_details_cntx->applib_email_list = NULL;
        MMI_ASSERT(free_mem);
    }

    if (g_srv_mms_use_details_cntx->applib_url_list)
    {
        free_mem = applib_free_address_list(&g_srv_mms_use_details_cntx->applib_url_list, srv_mms_mem_mgr_viewer_asm_free);
        g_srv_mms_use_details_cntx->applib_url_list = NULL;
        MMI_ASSERT(free_mem);
    }
    memset(&g_srv_mms_use_details_cntx->use_detail_rsp, 0, sizeof(srv_mms_get_use_details_rsp_struct));
}

#ifdef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__
/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_rsp_for_use_details_for_category
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_viewer_rsp_for_use_details_for_category(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_process_data_struct *process = srv_mms_get_process_by_req_id(g_srv_mms_use_details_cntx->process_id);
    srv_mms_get_use_details_viewer_rsp_struct *result = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_copy_pools(index, APPLIB_MEM_AP_ID_MMS_VIEWER);
    if (index == 0)
    {
        if (srv_mms_initialize_with_instance(SRV_MMS_INSTANCE_DEFAULT_INDEX) == NULL)
        {
            return;
        }
    }
    else
    {
        if (srv_mms_initialize_with_instance(index) == NULL)
        {
            return;
        }
    }
    if (!process)
    {
        return;
    }
    result = process->result;
    /* memset(&result, 0,sizeof(srv_mms_get_use_details_viewer_rsp_struct)); */
    result->list_head = g_srv_mms_use_details_cntx->flat_details_list;
    process->call_back(SRV_MMS_RESULT_OK, process->result, process->user_data);
    srv_mms_reset_process_data(process);
#ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
    StartTimer(MMS_VIEWER_TIMER, SRV_MMS_VIEWER_UNBLOCK_TIME, srv_mms_compute_rest_use_details);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_sort_use_detail_list_for_category
 * DESCRIPTION
 *  End handler for use details flow
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_mms_viewer_sort_use_detail_list_for_category(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(MMS_VIEWER_TIMER);
    //if (g_mv_cntx.msg_id == 0)
    //{
    /* We haven't already deinit the APP */
    //  return;
    //}

    if (g_srv_mms_use_details_cntx->flat_details_list != NULL &&
        g_srv_mms_use_details_cntx->flat_details_list->next != NULL)
    {
        srv_mms_viewer_use_details_list *ptr1 = g_srv_mms_use_details_cntx->flat_details_list->next;
        srv_mms_viewer_use_details_list *ptr1_prev = g_srv_mms_use_details_cntx->flat_details_list;

        while (ptr1)
        {
            srv_mms_viewer_use_details_list *ptr2 = g_srv_mms_use_details_cntx->flat_details_list;
            srv_mms_viewer_use_details_list *ptr2_prev = NULL;
            kal_bool move = KAL_FALSE;

            while (ptr2 && ptr1 != ptr2)
            {
                if (ptr1->offset < ptr2->offset)    /* insert before */
                {
                    if (ptr2_prev == NULL)
                    {
                        ptr1_prev->next = ptr1->next;
                        ptr1->next = ptr2;
                        g_srv_mms_use_details_cntx->flat_details_list = ptr1;
                    }
                    else
                    {
                        ptr1_prev->next = ptr1->next;
                        ptr1->next = ptr2;
                        ptr2_prev->next = ptr1;
                    }
                    move = KAL_TRUE;
                    break;
                }

                ptr2_prev = ptr2;
                ptr2 = ptr2->next;
            }

            if (move != KAL_TRUE)
            {
                ptr1_prev = ptr1;
                ptr1 = ptr1->next;
            }
            else
            {
                ptr1 = ptr1_prev->next;
            }
        }

        /* correct prv pointers */
        ptr1_prev = g_srv_mms_use_details_cntx->flat_details_list;
        ptr1_prev->prev = NULL;

        ptr1 = ptr1_prev->next;

        while (1)
        {
            ptr1->prev = ptr1_prev;
            if (ptr1->next == NULL)
            {
                break;
            }
            ptr1_prev = ptr1_prev->next;
            ptr1 = ptr1->next;
        }
    }
#ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
    StartTimer(MMS_VIEWER_TIMER, SRV_MMS_VIEWER_UNBLOCK_TIME, srv_mms_viewer_rsp_for_use_details_for_category_int);
    return MMI_FALSE;
#else /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
    return MMI_TRUE;
#endif /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
}

#ifndef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_use_details_check_stop_cb
 * DESCRIPTION
 *  Use Detail check stop callback
 * PARAMETERS
 *  type        [IN]        
 *  node        [IN]        
 *  num         [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool srv_mms_viewer_use_details_check_stop_cb(
            applib_addr_type_enum type,
            applib_address_node_struct *node,
            kal_uint32 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_viewer_use_details_list *t = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_mms_use_details_cntx->count += 1;
    t = srv_mms_mem_mgr_viewer_asm_alloc(sizeof(srv_mms_viewer_use_details_list));
    if (t == NULL)
    {
        // TODO: out of memory we need to exit the APP!
        // TODO: put log here
        return KAL_TRUE;
    }

    t->item = node;
    t->offset = ((node->pos) - (U32) g_srv_mms_use_details_cntx->p_ucs2_buffer) / ENCODING_LENGTH;
    t->len = (node->length) / ENCODING_LENGTH;

    if (g_srv_mms_use_details_cntx->flat_details_list)
    {
        srv_mms_viewer_use_details_list *iterator = g_srv_mms_use_details_cntx->flat_details_list;

        while (iterator->next)
        {
            iterator = iterator->next;
        }
        iterator->next = t;
        t->next = NULL;
        t->prev = iterator;
    }
    else
    {
        t->next = NULL;
        t->prev = NULL;
        g_srv_mms_use_details_cntx->flat_details_list = t;
    }

    if (g_srv_mms_use_details_cntx->count >= SRV_MMS_MAX_USE_DETAILS_PER_SLIDE)
    {
        return KAL_TRUE;
    }

    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_get_urls_on_slide
 * DESCRIPTION
 *  gets urls on slide
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_mms_viewer_get_urls_on_slide(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_address_node_struct *temp;
    kal_bool is_stopped = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_copy_pools(index, APPLIB_MEM_AP_ID_MMS_VIEWER);
    /* StopTimer(MMS_VIEWER_TIMER); */
    if (index == 0)
    {
        if (srv_mms_initialize_with_instance(SRV_MMS_INSTANCE_DEFAULT_INDEX) == NULL)
        {
            return MMI_FALSE;
        }
    }
    else
    {
        if (srv_mms_initialize_with_instance(index) == NULL)
        {
            return MMI_FALSE;
        }
    }
    if (!g_srv_mms_cntx->is_srv_ready)
    {
        return MMI_FALSE;
    }
    g_srv_mms_use_details_cntx->count = 0;

    temp = applib_get_address_list_from_text_ext(
            APPLIB_ADDR_TYPE_URL,
            srv_mms_mem_mgr_viewer_asm_alloc,
            srv_mms_mem_mgr_viewer_asm_free,
            srv_mms_viewer_use_details_check_stop_cb,
            APPLIB_INPUT_DATA_TYPE_UNICODE,
            (PS8) g_srv_mms_use_details_cntx->p_ucs2_buffer,
            g_srv_mms_use_details_cntx->ucs2_buffer_len,
            &is_stopped);

    g_srv_mms_use_details_cntx->applib_url_list = applib_concatenate_address_list(g_srv_mms_use_details_cntx->applib_url_list, temp);

    return srv_mms_viewer_sort_use_detail_list_for_category();
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_get_emails_on_slide
 * DESCRIPTION
 *  get emails on slide
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_mms_viewer_get_emails_on_slide(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_address_node_struct *temp;
    kal_bool is_stopped = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_copy_pools(index, APPLIB_MEM_AP_ID_MMS_VIEWER);

    /* StopTimer(MMS_VIEWER_TIMER); */
    if (index == 0)
    {
        if (srv_mms_initialize_with_instance(SRV_MMS_INSTANCE_DEFAULT_INDEX) == NULL)
        {
            return MMI_FALSE;
        }
    }
    else
    {
        if (srv_mms_initialize_with_instance(index) == NULL)
        {
            return MMI_FALSE;
        }
    }
    if (!g_srv_mms_cntx->is_srv_ready)
    {
        return MMI_FALSE;
    }
    g_srv_mms_use_details_cntx->count = 0;

    temp = applib_get_address_list_from_text_ext(
            APPLIB_ADDR_TYPE_EMAIL,
            srv_mms_mem_mgr_viewer_asm_alloc,
            srv_mms_mem_mgr_viewer_asm_free,
            srv_mms_viewer_use_details_check_stop_cb,
            APPLIB_INPUT_DATA_TYPE_UNICODE,
            (PS8) g_srv_mms_use_details_cntx->p_ucs2_buffer,
            g_srv_mms_use_details_cntx->ucs2_buffer_len,
            &is_stopped);
    g_srv_mms_use_details_cntx->applib_email_list = applib_concatenate_address_list(g_srv_mms_use_details_cntx->applib_email_list, temp);

    /* StartTimer(MMS_VIEWER_TIMER, SRV_MMS_VIEWER_UNBLOCK_TIME, srv_mms_viewer_get_urls_on_slide); */
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_get_numbers_on_slide
 * DESCRIPTION
 *  get numbers on slide
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_mms_viewer_get_numbers_on_slide(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_address_node_struct *temp;
    kal_bool is_stopped = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_copy_pools(index, APPLIB_MEM_AP_ID_MMS_VIEWER);
    /* StopTimer(MMS_VIEWER_TIMER); */
    if (index == 0)
    {
        if (srv_mms_initialize_with_instance(SRV_MMS_INSTANCE_DEFAULT_INDEX) == NULL)
        {
            return MMI_FALSE;
        }
    }
    else
    {
        if (srv_mms_initialize_with_instance(index) == NULL)
        {
            return MMI_FALSE;
        }
    }
    if (!g_srv_mms_cntx->is_srv_ready)
    {
        return MMI_FALSE;
    }
    g_srv_mms_use_details_cntx->count = 0;

    temp = applib_get_address_list_from_text_ext(
            APPLIB_ADDR_TYPE_PHONENUMBER,
            srv_mms_mem_mgr_viewer_asm_alloc,
            srv_mms_mem_mgr_viewer_asm_free,
            srv_mms_viewer_use_details_check_stop_cb,
            APPLIB_INPUT_DATA_TYPE_UNICODE,
            (PS8) g_srv_mms_use_details_cntx->p_ucs2_buffer,
            g_srv_mms_use_details_cntx->ucs2_buffer_len,
            &is_stopped);

    g_srv_mms_use_details_cntx->applib_phnum_list = applib_concatenate_address_list(g_srv_mms_use_details_cntx->applib_phnum_list, temp);

    /* StartTimer(MMS_VIEWER_TIMER, SRV_MMS_VIEWER_UNBLOCK_TIME, srv_mms_viewer_get_emails_on_slide); */
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_mark_duplicate_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *  addr_list       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_viewer_mark_duplicate_address(applib_address_node_struct *addr_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_address_node_struct *addr_list_tp1 = addr_list;
    applib_address_node_struct *addr_list_tp2 = addr_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (addr_list == NULL)
    {
        return;
    }
    while (addr_list_tp1 != NULL)
    {
        addr_list_tp2 = addr_list_tp1;
        while (addr_list_tp2 != NULL)
        {
            if (addr_list_tp1 == addr_list_tp2)
            {
                /* first iteration: comparing a node with itself */
            }
            else if (addr_list_tp1->dataType == addr_list_tp2->dataType)
            {
                /* For the same link type, remove duplicated links */
                if (app_ucs2_wcsicmp((kal_wchar*) addr_list_tp1->data, (kal_wchar*) addr_list_tp2->data) == 0)
                {
                    /* if pos & length is zero that means it's a duplicate */
                    addr_list_tp2->pos = 0;
                    addr_list_tp2->length = 0;
                }
            }
            addr_list_tp2 = addr_list_tp2->next;
        }
        addr_list_tp1 = addr_list_tp1->next;
    }
}
#endif /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
#else /* __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_use_details_check_stop_cb
 * DESCRIPTION
 *  Use Detail check stop callback
 * PARAMETERS
 *  type        [IN]        
 *  node        [IN]        
 *  num         [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool srv_mms_viewer_use_details_check_stop_cb(
            applib_addr_type_enum type,
            applib_address_node_struct *node,
            kal_uint32 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_mms_use_details_cntx->count += 1;
    g_srv_mms_use_details_cntx->total_count += 1;

    if (g_srv_mms_use_details_cntx->total_count >= MMI_MV_MAX_USE_DETAILS
        || g_srv_mms_use_details_cntx->count >= SRV_MMS_MAX_USE_DETAILS_PER_SLIDE)
    {
        return KAL_TRUE;
    }

    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_end_compute_use_details
 * DESCRIPTION
 *  End handler for use details flow
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mms_viewer_end_compute_use_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(MMS_VIEWER_TIMER);
    g_srv_mms_use_details_cntx->use_detail_rsp.result = SRV_MMS_GET_USE_DETAILS_RESULT_SUCCESS;
    srv_mms_send_get_use_details_rsp();
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_get_urls_on_slide
 * DESCRIPTION
 *  gets urls on slide
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mms_viewer_get_urls_on_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_address_node_struct *temp;
    kal_bool is_stopped = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(MMS_VIEWER_TIMER);

    if (MMI_MV_MAX_USE_DETAILS > g_srv_mms_use_details_cntx->total_count)
    {
        temp = applib_get_address_list_from_text_ext(
                APPLIB_ADDR_TYPE_URL,
                srv_mms_mem_mgr_viewer_asm_alloc,
                srv_mms_mem_mgr_viewer_asm_free,
                srv_mms_viewer_use_details_check_stop_cb,
                APPLIB_INPUT_DATA_TYPE_UNICODE,
                (PS8) g_srv_mms_use_details_cntx->p_ucs2_buffer,
                g_srv_mms_use_details_cntx->ucs2_buffer_len,
                &is_stopped);

        g_srv_mms_use_details_cntx->use_detail_rsp.url_list = applib_concatenate_address_list(g_srv_mms_use_details_cntx->use_detail_rsp.url_list, temp);
    }

    StartTimer(MMS_VIEWER_TIMER, SRV_MMS_VIEWER_UNBLOCK_TIME, srv_mms_viewer_end_compute_use_details);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_get_emails_on_slide
 * DESCRIPTION
 *  get emails on slide
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mms_viewer_get_emails_on_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_address_node_struct *temp;
    kal_bool is_stopped = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(MMS_VIEWER_TIMER);

    if (MMI_MV_MAX_USE_DETAILS > g_srv_mms_use_details_cntx->total_count)
    {
        temp = applib_get_address_list_from_text_ext(
                APPLIB_ADDR_TYPE_EMAIL,
                srv_mms_mem_mgr_viewer_asm_alloc,
                srv_mms_mem_mgr_viewer_asm_free,
                srv_mms_viewer_use_details_check_stop_cb,
                APPLIB_INPUT_DATA_TYPE_UNICODE,
                (PS8) g_srv_mms_use_details_cntx->p_ucs2_buffer,
                g_srv_mms_use_details_cntx->ucs2_buffer_len,
                &is_stopped);
        g_srv_mms_use_details_cntx->use_detail_rsp.email_list = applib_concatenate_address_list(g_srv_mms_use_details_cntx->use_detail_rsp.email_list, temp);
    }
    else
    {
        is_stopped = KAL_TRUE;
    }

    if (is_stopped == TRUE)
    {
        StartTimer(MMS_VIEWER_TIMER, SRV_MMS_VIEWER_UNBLOCK_TIME, srv_mms_viewer_end_compute_use_details);
    }
    else
    {
        StartTimer(MMS_VIEWER_TIMER, SRV_MMS_VIEWER_UNBLOCK_TIME, srv_mms_viewer_get_urls_on_slide);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_get_numbers_on_slide
 * DESCRIPTION
 *  get numbers on slide
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mms_viewer_get_numbers_on_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_address_node_struct *temp;
    kal_bool is_stopped = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(MMS_VIEWER_TIMER);

    if (MMI_MV_MAX_USE_DETAILS > g_srv_mms_use_details_cntx->total_count)
    {
        temp = applib_get_address_list_from_text_ext(
                APPLIB_ADDR_TYPE_PHONENUMBER,
                srv_mms_mem_mgr_viewer_asm_alloc,
                srv_mms_mem_mgr_viewer_asm_free,
                srv_mms_viewer_use_details_check_stop_cb,
                APPLIB_INPUT_DATA_TYPE_UNICODE,
                (PS8) g_srv_mms_use_details_cntx->p_ucs2_buffer,
                g_srv_mms_use_details_cntx->ucs2_buffer_len,
                &is_stopped);

        g_srv_mms_use_details_cntx->use_detail_rsp.num_list = applib_concatenate_address_list(g_srv_mms_use_details_cntx->use_detail_rsp.num_list, temp);
    }
    else
    {
        is_stopped = KAL_TRUE;
    }

    if (is_stopped == TRUE)
    {
        StartTimer(MMS_VIEWER_TIMER, SRV_MMS_VIEWER_UNBLOCK_TIME, srv_mms_viewer_end_compute_use_details);
    }
    else
    {
        StartTimer(MMS_VIEWER_TIMER, SRV_MMS_VIEWER_UNBLOCK_TIME, srv_mms_viewer_get_emails_on_slide);
    }
}
#endif /* __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__ */ 

/* Amitesh Added */


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_use_details_deinit
 * DESCRIPTION
 *  get use details functionality deinit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mms_get_use_details_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL free_mem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_mms_use_details_cntx->use_detail_rsp.num_list != NULL)
    {
        free_mem = applib_free_address_list(
                    &g_srv_mms_use_details_cntx->use_detail_rsp.num_list,
                    srv_mms_mem_mgr_viewer_asm_free);
        g_srv_mms_use_details_cntx->use_detail_rsp.num_list = NULL;
        g_srv_mms_use_details_cntx->applib_phnum_list = NULL;
        ASSERT(free_mem);

    }
    if (g_srv_mms_use_details_cntx->use_detail_rsp.email_list != NULL)
    {
        free_mem = applib_free_address_list(
                    &g_srv_mms_use_details_cntx->use_detail_rsp.email_list,
                    srv_mms_mem_mgr_viewer_asm_free);
        g_srv_mms_use_details_cntx->use_detail_rsp.email_list = NULL;
        g_srv_mms_use_details_cntx->applib_email_list = NULL;
        ASSERT(free_mem);
    }
    if (g_srv_mms_use_details_cntx->use_detail_rsp.url_list != NULL)
    {
        free_mem = applib_free_address_list(
                    &g_srv_mms_use_details_cntx->use_detail_rsp.url_list,
                    srv_mms_mem_mgr_viewer_asm_free);
        g_srv_mms_use_details_cntx->use_detail_rsp.url_list = NULL;
        g_srv_mms_use_details_cntx->applib_url_list = NULL;
        ASSERT(free_mem);
    }
#ifndef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
    memset(g_srv_mms_use_details_cntx, 0, sizeof(srv_mms_use_details_struct));
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_use_details_req_hdlr
 * DESCRIPTION
 *  get use details req hldr
 * PARAMETERS
 *  msgPtr      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *srv_mms_get_use_details_req_hdlr(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    srv_mms_get_use_details_req_struct *use_detail_req = (srv_mms_get_use_details_req_struct*) msgPtr;
#ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
    MMI_BOOL ret = MMI_FALSE;
    S32 start_index = 0, end_index = 0;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_desc->body)->slides == NULL &&
        use_detail_req->request_type != SRV_MMS_GET_USE_DETAILS_SENDER &&
        use_detail_req->request_type != SRV_MMS_GET_USE_DETAILS_RECIPIENT)
    {
        g_srv_mms_use_details_cntx->use_detail_rsp.result = SRV_MMS_GET_USE_DETAILS_RESULT_FAILED;
    }
    if ((use_detail_req->request_type == SRV_MMS_GET_USE_DETAILS_NUMBER) ||
        (use_detail_req->request_type == SRV_MMS_GET_USE_DETAILS_EMAIL) ||
        (use_detail_req->request_type == SRV_MMS_GET_USE_DETAILS_URL))
    {
        // TODO: how to avoid re-duplicate checking effort

    #ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__

        if (use_detail_req->is_more)
        {
            g_srv_mms_use_details_cntx->use_detail_rsp.total_count = 0;
            g_srv_mms_use_details_cntx->current_count = 0;
        }
        else
        {
            g_srv_mms_use_details_cntx->use_detail_rsp.start_index = 0;
            g_srv_mms_use_details_cntx->use_detail_rsp.end_index = 0;
            g_srv_mms_use_details_cntx->current_count = 0;
            g_srv_mms_use_details_cntx->use_detail_rsp.total_count = 0;
        }
        ret = srv_mms_load_use_details(use_detail_req->data_type, use_detail_req->curr_index, &start_index, &end_index);
        if (ret == MMI_TRUE)
        {
            if (!use_detail_req->is_more)
            {
                switch (use_detail_req->data_type)
                {
                    case APPLIB_ADDR_TYPE_PHONENUMBER:
                        g_srv_mms_use_details_cntx->number_total_count = g_srv_mms_use_details_cntx->number_count;
                        break;
                    case APPLIB_ADDR_TYPE_EMAIL:
                        g_srv_mms_use_details_cntx->email_total_count = g_srv_mms_use_details_cntx->email_count;
                        break;
                    case APPLIB_ADDR_TYPE_URL:
                        g_srv_mms_use_details_cntx->url_total_count = g_srv_mms_use_details_cntx->url_count;
                        break;
                }
                
            }
            memset(&g_srv_mms_use_details_cntx->use_detail_rsp, 0, sizeof(srv_mms_get_use_details_rsp_struct));
            switch (use_detail_req->data_type)
            {
                case APPLIB_ADDR_TYPE_PHONENUMBER:
                    g_srv_mms_use_details_cntx->use_detail_rsp.total_count =
                        g_srv_mms_use_details_cntx->number_total_count;
                    g_srv_mms_use_details_cntx->use_detail_rsp.num_list = g_srv_mms_use_details_cntx->applib_phnum_list;
                    break;
                case APPLIB_ADDR_TYPE_EMAIL:
                    g_srv_mms_use_details_cntx->use_detail_rsp.total_count =
                        g_srv_mms_use_details_cntx->email_total_count;
                    g_srv_mms_use_details_cntx->use_detail_rsp.email_list =
                        g_srv_mms_use_details_cntx->applib_email_list;
                    break;
                case APPLIB_ADDR_TYPE_URL:
                    g_srv_mms_use_details_cntx->use_detail_rsp.total_count =
                        g_srv_mms_use_details_cntx->url_total_count;
                    g_srv_mms_use_details_cntx->use_detail_rsp.url_list = g_srv_mms_use_details_cntx->applib_url_list;
                    break;
            }
            g_srv_mms_use_details_cntx->use_detail_rsp.start_index = start_index;
            g_srv_mms_use_details_cntx->use_detail_rsp.end_index = end_index;
        }
        if (ret == MMI_TRUE)
        {
            g_srv_mms_use_details_cntx->use_detail_rsp.result = SRV_MMS_GET_USE_DETAILS_RESULT_SUCCESS;
        }
        else
        {
            g_srv_mms_use_details_cntx->use_detail_rsp.result = SRV_MMS_GET_USE_DETAILS_RESULT_FAILED;
        }
        goto End;
    #elif defined (__MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__)
        // TODO: how to avoid re-duplicate checking effort
        switch (use_detail_req->data_type)
        {
            case APPLIB_ADDR_TYPE_PHONENUMBER:
                srv_mms_viewer_mark_duplicate_address(g_srv_mms_use_details_cntx->applib_phnum_list);
                g_srv_mms_use_details_cntx->use_detail_rsp.num_list = g_srv_mms_use_details_cntx->applib_phnum_list;
                break;
            case APPLIB_ADDR_TYPE_EMAIL:
                srv_mms_viewer_mark_duplicate_address(g_srv_mms_use_details_cntx->applib_email_list);
                g_srv_mms_use_details_cntx->use_detail_rsp.email_list = g_srv_mms_use_details_cntx->applib_email_list;
                break;
            case APPLIB_ADDR_TYPE_URL:
                srv_mms_viewer_mark_duplicate_address(g_srv_mms_use_details_cntx->applib_url_list);
                g_srv_mms_use_details_cntx->use_detail_rsp.url_list = g_srv_mms_use_details_cntx->applib_url_list;
        }
        g_srv_mms_use_details_cntx->use_detail_rsp.result = SRV_MMS_GET_USE_DETAILS_RESULT_SUCCESS;
        /* srv_mms_send_get_use_details_rsp(); */
    #else /* __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__ */
        g_srv_mms_use_details_cntx->current_slide = (g_desc->body)->curr_slide;
        srv_mms_viewer_start_compute_use_details(SRV_MMS_INSTANCE_DEFAULT_INDEX);

    #endif 
    }
    else
    {
        ASSERT(0);
    }
#ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
  End:
#endif
    return &g_srv_mms_use_details_cntx->use_detail_rsp;
}

#ifndef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__
/*****************************************************************************
 * FUNCTION
 *  srv_mms_send_get_use_details_rsp
 * DESCRIPTION
 *  send use detail rsp
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mms_send_get_use_details_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* MYQUEUE Message; */
    srv_mms_get_use_details_rsp_struct *use_detail_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    use_detail_rsp =
        (srv_mms_get_use_details_rsp_struct*) OslConstructDataPtr(sizeof(srv_mms_get_use_details_rsp_struct));
    /* g_srv_mms_use_details_cntx->use_detail_rsp.returned_type = g_srv_mms_use_details_cntx->state; */
    //g_srv_mms_use_details_cntx->use_detail_rsp.ref_count = use_detail_rsp->ref_count;
    //g_srv_mms_use_details_cntx->use_detail_rsp.msg_len = use_detail_rsp->msg_len;
    memcpy(use_detail_rsp, &g_srv_mms_use_details_cntx->use_detail_rsp, sizeof(srv_mms_get_use_details_rsp_struct));
    /* use_detail_rsp->req_id = SRV_MMS_USE_DETAILS_REQ_ID; */
    /*
     * Message.oslSrcId = MOD_MMI;
     * Message.oslDestId = MOD_MMI;
     * Message.oslMsgId = MSG_ID_MMI_MV_GET_USE_DETAILS_RSP;
     * Message.oslDataPtr = (oslParaType*) use_detail_rsp;
     * Message.oslPeerBuffPtr = NULL;
     * OslMsgSendExtQueue(&Message);
     */
    /* mmi_frm_send_ilm(MOD_MMI, MSG_ID_MMI_MV_GET_USE_DETAILS_RSP, (oslParaType *) use_detail_rsp,NULL); */
}
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_mms_deinit_viewer
 * DESCRIPTION
 *  deinit viewer destory ADM pool. called from Idle screen, before entering a MMS etc
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_deinit_viewer(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* keep in sync with mmi_mv_delete_screen_cb */
     srv_mms_process_data_struct *process = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_VIEWER_DEINIT);
    /* StopTimer(MMS_VIEWER_TIMER); */
    if (index == 0)
    {
        index = SRV_MMS_INSTANCE_DEFAULT_INDEX;
    }
    if (srv_mms_initialize_with_instance(index) == NULL)
    {
        return;
    }
    process = srv_mms_get_process_by_req_id(g_srv_mms_drm_process_cntx->req_id);
    if (process)
    {
        srv_mms_reset_process_data(process);
    }
    process = srv_mms_get_process_by_req_id(g_srv_mms_use_details_cntx->process_id);
    if (process)
    {
        srv_mms_reset_process_data(process);
    }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
    if (g_srv_mms_use_details_cntx && g_srv_mms_use_details_cntx->file_path != NULL)
    {
        srv_mms_mem_mgr_app_adm_free(g_srv_mms_use_details_cntx->file_path);
        g_srv_mms_use_details_cntx->file_path = NULL;
    }
    srv_mms_free_use_details_lists();
    srv_mms_get_use_details_deinit();
    /* g_mv_is_mms_previewed = MMI_FALSE; */
    memset(g_srv_mms_use_details_cntx, 0, sizeof(srv_mms_use_details_struct));
    if (g_srv_mms_drm_process_cntx->vf_handle != 0)
    {
        FS_Close(g_srv_mms_drm_process_cntx->vf_handle);
    }
#ifdef __DRM_SUPPORT__
    g_srv_drm_with_nr = MMI_FALSE;
#endif 
    if (g_desc)
    {
        if (g_desc->body)
        {
            srv_mms_viewer_free_object_data(g_desc->body->objects);
            g_desc->body->objects = NULL;
            srv_mms_viewer_free_slide_data(g_desc->body->slides);
            g_desc->body->slides = NULL;
            g_desc->body->curr_slide = NULL;
            if (g_desc->body->attachment)
            {
                srv_mms_viewer_free_attachment_data(g_desc->body->attachment);
            }
            srv_mms_mem_mgr_viewer_asm_free(g_desc->body);
            g_desc->body = NULL;
        }
    }
    if (g_srv_mms_parser_cntx->slide_txt_buffer)
    {
        srv_mms_mem_mgr_viewer_asm_free(g_srv_mms_parser_cntx->slide_txt_buffer);
        g_srv_mms_parser_cntx->slide_txt_buffer = NULL;
    }
    if (g_srv_mms_parser_cntx->src_buffer)
    {
        srv_mms_mem_mgr_viewer_asm_free(g_srv_mms_parser_cntx->src_buffer);
        g_srv_mms_parser_cntx->src_buffer = NULL;
    }
    if (g_srv_mms_parser_cntx->inputbox_buffer)
    {
        srv_mms_mem_mgr_viewer_asm_free(g_srv_mms_parser_cntx->inputbox_buffer);
    }
    srv_mms_mem_mgr_asm_deinit_memory(APPLIB_MEM_AP_ID_MMS_VIEWER, index);
    if (index)
    {
        srv_mms_delete_instance(index);
    }
    /* Do this at last */
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_delete_viewer_services
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_delete_viewer_services(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_process_data_struct *process = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_DELETE_SCR_CB);

    StopTimer(MMS_VIEWER_TIMER);
    /* Reset all processes occupied by Viewer */
    process = srv_mms_get_process_by_req_id(g_srv_mms_drm_process_cntx->req_id);
    if (process)
    {
        srv_mms_reset_process_data(process);
    }
    process = srv_mms_get_process_by_req_id(g_srv_mms_use_details_cntx->process_id);
    if (process)
    {
        srv_mms_reset_process_data(process);
    }
#ifdef __DRM_SUPPORT__
    g_srv_drm_with_nr = MMI_FALSE;
#endif 
    /* If Viewer active progress & confirm already deleted */
    /* If confirm active progress already deleted & viewer not yet entered */
    /* If progress active confirm & viewer not yet entered */
    /* Therefore, no need to delete screens! */
    /*
     * if (g_srv_mms_parser_cntx->xml_parser)
     * {
     * xml_stop_parse(g_srv_mms_parser_cntx->xml_parser);
     * xml_close_parser(g_srv_mms_parser_cntx->xml_parser);
     * memset(g_srv_mms_parser_cntx, 0, sizeof(srv_mms_xml_parser_context_struct));
     * }
     * memset(g_srv_mms_parser_cntx, 0, sizeof(srv_mms_xml_parser_context_struct));
     */
#ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
    if (g_srv_mms_use_details_cntx->file_handle)
    {
        FS_Close(g_srv_mms_use_details_cntx->file_handle);
        g_srv_mms_use_details_cntx->file_handle = 0;
    }
    if (g_srv_mms_use_details_cntx->file_path != NULL)
    {
        FS_Delete(g_srv_mms_use_details_cntx->file_path);
        srv_mms_mem_mgr_app_adm_free(g_srv_mms_use_details_cntx->file_path);
        g_srv_mms_use_details_cntx->file_path = NULL;
    }
    if (g_srv_mms_use_details_cntx->header)
    {
        srv_mms_mem_mgr_viewer_asm_free(g_srv_mms_use_details_cntx->header);
        g_srv_mms_use_details_cntx->header = NULL;
    }
    if (g_srv_mms_parser_cntx->use_detail_buffer)
    {
        srv_mms_mem_mgr_viewer_asm_free(g_srv_mms_parser_cntx->use_detail_buffer);
        g_srv_mms_parser_cntx->use_detail_buffer = NULL;
    }
#endif /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
    srv_mms_get_use_details_deinit();
    /* g_mv_is_mms_previewed = MMI_FALSE; */
    memset(g_srv_mms_use_details_cntx, 0, sizeof(srv_mms_use_details_struct));
    if (g_srv_mms_drm_process_cntx->vf_handle != 0)
    {
        FS_Close(g_srv_mms_drm_process_cntx->vf_handle);
    }
    /* srv_mms_mem_mgr_asm_deinit_memory(APPLIB_MEM_AP_ID_MMS_VIEWER); */

    /* Do this at last */
    memset(g_srv_mms_drm_process_cntx, 0, sizeof(srv_mms_drm_process_cntx_struct));
    /* memset(g_srv_mms_viewer_cntx, 0, sizeof(srv_mms_xml_msg_viewer_data_struct)); */
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_get_total_slide_num
 * DESCRIPTION
 *  returns number of total slides
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_mms_viewer_get_total_slide_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_description_struct *desc = srv_mms_get_desc_pointer();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (desc && desc->body && desc->body->curr_slide)
    {
        return desc->body->slide_no;
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_get_current_slide
 * DESCRIPTION
 *  returns the slide num of current slide
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
srv_mms_viewer_slide_struct *srv_mms_viewer_get_current_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_description_struct *desc = srv_mms_get_desc_pointer();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (desc && desc->body && desc->body->curr_slide)
    {
        return desc->body->curr_slide;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_get_current_slide_num
 * DESCRIPTION
 *  returns the slide num of current slide
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_mms_viewer_get_current_slide_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_description_struct *desc = srv_mms_get_desc_pointer();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (desc && desc->body && desc->body->curr_slide)
    {
        return desc->body->curr_slide->slide_num;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_get_slide_obj_count
 * DESCRIPTION
 *  returns the slide num of current slide
 * PARAMETERS
 *  slide_num       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_mms_viewer_get_slide_obj_count(U32 slide_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*g_mms_obj_container != NULL)
    {
        return (*g_mms_obj_container)[slide_num].obj_count;
    }

	return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_get_slide_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_mms_slide_struct *srv_mms_viewer_get_slide_by_index(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*g_mms_obj_container != NULL)
    {
        return (*g_mms_obj_container)[index].slide;
    }

	return NULL;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_send_event_to_exit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result              [IN]        
 *  file_error_type     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_viewer_send_event_to_exit(srv_mms_viewer_result_enum result, S32 file_error_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_viewer_event_data_struct view_error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&view_error, 0, sizeof(srv_mms_viewer_event_data_struct));
    view_error.result = result;
    view_error.file_error_type = file_error_type;
    srv_mms_send_events(EVT_ID_SRV_EXIT_VIEWER_APP, (void*)(&view_error));
}

#ifdef __DRM_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_is_media_with_no_rights
 * DESCRIPTION
 *  returns
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE : if drm media with no rights is present
 *  FALSE :o/w
 *****************************************************************************/
MMI_BOOL srv_mms_viewer_is_media_with_no_rights(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_drm_with_nr;
}
#endif /* __DRM_SUPPORT__ */ 

#ifdef __MMI_MMS_POSTCARD__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_viewer_asm_alloc_postcard
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size            [IN]        
 *  user_data       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void *srv_mms_mem_mgr_viewer_asm_alloc_postcard(U32 size, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_mms_mem_mgr_viewer_asm_alloc(size);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_viewer_asm_free_postcard
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mem             [?]     
 *  user_data       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_mem_mgr_viewer_asm_free_postcard(void *mem, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_viewer_asm_free(mem);
}
#endif /* __MMI_MMS_POSTCARD__ */ 
#ifndef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_duplicate_phoneno_no_written_sep
 * DESCRIPTION
 *  This function is used to duplicate a phone number.
 *  The duplicate contains only digit and '+', 'w', 'p' characters, that is, skipping '(', ')', '-', '.', etc.
 * PARAMETERS
 *  mem_alloc_fn        [IN]        Memory allication function
 *  str                 [IN]        Input phone number string
 * RETURNS
 *  phone number string
 *****************************************************************************/
U16 *srv_mms_duplicate_phoneno_no_written_sep(srv_mms_alloc_mem mem_alloc_fn, U16 *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *number = NULL;
    U16 *ptr = NULL;
    S32 dest_len = 0;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (str == NULL)
    {
        return NULL;
    }

    number = mem_alloc_fn(mmi_ucs2strlen((S8*) str) * 2 + 2);
    if (!number)
    {
        return NULL;    /* SRV_MMS_VIEWER_OUT_OF_MEM; */
    }
    memset(number, 0, mmi_ucs2strlen((S8*) str) * 2 + 2);
    ptr = str;
    while (*ptr != L'\0')
    {
        result = srv_mms_is_valid_phoneno_wchar_int(*ptr, MMI_FALSE);
        if (result == MMI_TRUE)
        {
            number[dest_len++] = *ptr;
        }
        ptr++;
    }
    number[dest_len] = L'\0';
    return number;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_is_valid_phoneno_wchar_int
 * DESCRIPTION
 *  This internal function is used to check if input char is valid phone number character
 * PARAMETERS
 *  ch                          [IN]        Character being checked
 *  is_written_char_valid       [IN]        Count written char,ex. '-','(',')', as valid char
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static MMI_BOOL srv_mms_is_valid_phoneno_wchar_int(U16 ch, MMI_BOOL is_written_char_valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 phoneno_special_chars[] = {L'+', L'w', L'p', L'W', L'P' };
    S8 phoneno_written_chars[] = {L'-', L'(', L')' };

    S32 num_phoneno_special_chars = (sizeof(phoneno_special_chars) / 2);
    S32 num_phoneno_written_chars = (sizeof(phoneno_written_chars) / 2);
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch != 0)
    {
        if (ch >= L'0' && ch <= L'9')
        {
            return MMI_TRUE;
        }

        for (i = 0; i < num_phoneno_special_chars; i++)
        {
            if (ch == phoneno_special_chars[i])
            {
                return MMI_TRUE;
            }
        }

        if (is_written_char_valid == MMI_TRUE)
        {
            for (i = 0; i < num_phoneno_written_chars; i++)
            {
                if (ch == phoneno_written_chars[i])
                {
                    return MMI_TRUE;
                }
            }
        }

        return MMI_FALSE;
    }
    else
    {
        return MMI_FALSE;
    }
}
#endif /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_free_slide_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  slide       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_viewer_free_slide_data(mma_mms_slide_struct *slide)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_slide_struct *slide_int = slide;

#ifdef __MMI_MV_SUPPORT_REF_ID__
    mma_mms_slide_ref_object_struct *list = NULL;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (slide)
    {
        slide_int = slide;

    #ifdef __MMI_MV_SUPPORT_REF_ID__
        if (slide_int->ref_items)
        {
            list = slide_int->ref_items;
            if (list)
            {
                srv_mms_viewer_free_ref_data(list);
                list = NULL;
            }
        }
    #endif /* __MMI_MV_SUPPORT_REF_ID__ */ 

        if (slide_int->txt.id)
        {
            if (slide_int->txt.alt)
            {
                srv_mms_mem_mgr_viewer_asm_free(slide_int->txt.alt);
                slide_int->txt.alt = NULL;
            }
            if (slide_int->txt.region_area)
            {
                srv_mms_mem_mgr_viewer_asm_free(slide_int->txt.region_area);
                slide_int->txt.region_area = NULL;
            }

            slide_int->txt.object = NULL;

        }
        if (slide_int->img.id)
        {
            if (slide_int->img.alt)
            {
                srv_mms_mem_mgr_viewer_asm_free(slide_int->img.alt);
                slide_int->img.alt = NULL;
            }
            if (slide_int->img.region_area)
            {
                srv_mms_mem_mgr_viewer_asm_free(slide_int->img.region_area);
                slide_int->img.region_area = NULL;
            }

            slide_int->img.object = NULL;

        }
        if (slide_int->vid.id)
        {
            if (slide_int->vid.alt)
            {
                srv_mms_mem_mgr_viewer_asm_free(slide_int->vid.alt);
                slide_int->vid.alt = NULL;
            }
            if (slide_int->vid.region_area)
            {
                srv_mms_mem_mgr_viewer_asm_free(slide_int->vid.region_area);
                slide_int->vid.region_area = NULL;
            }

            slide_int->vid.object = NULL;

        }
        if (slide_int->aud.id)
        {
            if (slide_int->aud.alt)
            {
                srv_mms_mem_mgr_viewer_asm_free(slide_int->aud.alt);
                slide_int->aud.alt = NULL;
            }
            if (slide_int->aud.region_area)
            {
                srv_mms_mem_mgr_viewer_asm_free(slide_int->aud.region_area);
                slide_int->aud.region_area = NULL;
            }

            slide_int->aud.object = NULL;

        }
        slide = slide->next;
        srv_mms_mem_mgr_viewer_asm_free(slide_int);
        slide_int = NULL;
    }
    if (*g_mms_obj_container)
    {
        srv_mms_mem_mgr_viewer_asm_free(*g_mms_obj_container);
        *g_mms_obj_container = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_free_attachment_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  attachment      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_viewer_free_attachment_data(mma_mms_attachment_info_struct *attachment)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (attachment)
    {
        mma_mms_attachment_info_struct *list = attachment;

	attachment=attachment->next;
	list->object=NULL;
	list->next=NULL;
        list->prev=NULL;
	srv_mms_mem_mgr_viewer_asm_free((list));
	list = NULL;
    }
}

#ifdef __MMI_MV_SUPPORT_REF_ID__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_free_ref_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  list        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_viewer_free_ref_data(mma_mms_slide_ref_object_struct *list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_slide_ref_object_struct *temp = NULL;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (list)
    {
        temp = list;
        list = list->next;
        if (temp->alt)
        {
            srv_mms_mem_mgr_viewer_asm_free(temp->alt);
        }
        if (temp->region_area)
        {
            srv_mms_mem_mgr_viewer_asm_free(temp->region_area);
        }

        temp->object = NULL;

        srv_mms_mem_mgr_viewer_asm_free(temp);
        temp = NULL;
    }
}
#endif /* __MMI_MV_SUPPORT_REF_ID__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_free_object_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_viewer_free_object_data(mma_mms_object_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *tmp_obj = obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (tmp_obj)
    {
        obj = tmp_obj;
	tmp_obj = tmp_obj->next;
        if ((obj)->file_name_ucs)
        {
            srv_mms_mem_mgr_viewer_asm_free((obj)->file_name_ucs);
            (obj)->file_name_ucs = NULL;
        }
        if ((obj)->file_path_ucs)
        {
            srv_mms_mem_mgr_viewer_asm_free((obj)->file_path_ucs);
            (obj)->file_path_ucs = NULL;
        }
        if ((obj)->file_name)
        {
            srv_mms_mem_mgr_viewer_asm_free((obj)->file_name);
            (obj)->file_name = NULL;
        }
        if ((obj)->file_path)
        {
            srv_mms_mem_mgr_viewer_asm_free((obj)->file_path);
            (obj)->file_path = NULL;
        }
        if ((obj)->mime_type_ext)
        {
            srv_mms_mem_mgr_viewer_asm_free((obj)->mime_type_ext);
            (obj)->mime_type_ext = NULL;
        }
        if ((obj)->mime_str)
        {
            srv_mms_mem_mgr_viewer_asm_free((obj)->mime_str);
            (obj)->mime_str = NULL;
        }
    #ifdef __DRM_SUPPORT__
        if ((obj)->cid)
        {
            srv_mms_mem_mgr_viewer_asm_free((obj)->cid);
            (obj)->cid = NULL;
        }
        if ((obj)->drm_mime_type)
        {
            srv_mms_mem_mgr_viewer_asm_free((obj)->drm_mime_type);
            (obj)->drm_mime_type = NULL;
        }

    #endif /* __DRM_SUPPORT__ */ 
        srv_mms_mem_mgr_viewer_asm_free(obj);
        obj = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_get_total_obj_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_mms_viewer_get_total_obj_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_desc->body->obj_no;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_get_med_object_from_current_slide
 * DESCRIPTION
 *  returns media object from current slide
 * PARAMETERS
 *  media       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_viewer_get_med_object_from_current_slide(mma_mms_object_struct **media)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(*media == NULL);

    if ((g_desc->body)->curr_slide->img.id)
    {
        *media = (g_desc->body)->curr_slide->img.object;
    }
    else if ((g_desc->body)->curr_slide->vid.id)
    {
        *media = (g_desc->body)->curr_slide->vid.object;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_get_txt_ucs_len
 * DESCRIPTION
 *  returns media object from current slide
 * PARAMETERS
 *  media       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U32 srv_mms_viewer_get_txt_ucs_len(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
		srv_mms_base_data_struct *b_data = (srv_mms_base_data_struct *)srv_mms_get_mms_info_data();
		if(b_data->open_mode != MMA_MODE_VIEW || (b_data->is_preview))
		{
			return SRV_MMS_TXT_COMPOSE_BUF_UCS2_SIZE;
		}
		else
	#endif /*__MMI_MMS_SIMPLIFIED_UI_SUPPORT__*/
		{
			return SRV_MMS_VIEWER_TXT_BUF_UCS2_SIZE;
		}    
}

/*****************************************************************************
 * FUNCTION
 *  srv_mms_viewer_get_txt_utf_len
 * DESCRIPTION
 *  returns utf text length
 * PARAMETERS
 *  media       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U32 srv_mms_viewer_get_txt_utf_len(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
		srv_mms_base_data_struct *b_data = (srv_mms_base_data_struct *)srv_mms_get_mms_info_data();
		if(b_data->open_mode != MMA_MODE_VIEW || (b_data->is_preview))
		{
			return SRV_MMS_MAX_COMPOSE_UTF8_TXT_SLIDE_LEN;
		}
		else
	#endif /*__MMI_MMS_SIMPLIFIED_UI_SUPPORT__*/
		{
			return SRV_MMS_VIEWER_MAX_UTF8_TXT_SLIDE_LEN;
		}   
}
/*****************************************************************************
 * FUNCTION
 *  srv_mms_deinit_lite_viewer
 * DESCRIPTION
 *  returns utf text length
 * PARAMETERS
 *  file_handle       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/

S32 srv_mms_deinit_lite_viewer(srv_mms_lite_viewer_handle_data *file_handle)
 { 

   MMI_ASSERT(file_handle);
   if(file_handle->file_handle)
   	{
   		FS_Close(file_handle->file_handle);
		file_handle->file_handle = 0;
   	}
          
   return 0;
          
 }
#endif /* __MMI_MMS_2__ */ 

