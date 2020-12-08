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
 * MmsMainSrv.c
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
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_public_defs.h" 
#include "string.h"

#include "kal_trace.h"
#include "mmi_inet_app_trc.h"
#include "fs_type.h"
#include "fs_func.h"
#include "gui_data_types.h"
#include "FileMgrSrvGProt.h"
#include "stdio.h"
#include "fs_errcode.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_rp_srv_mms_def.h"

// #include "mmsadp.h"
#ifndef __COSMOS_MMI_PACKAGE__
#include "mmi_rp_app_sms_def.h"
#include "UMGProt.h"
#endif /* __COSMOS_MMI_PACKAGE__ */ 

#include "mmi_rp_srv_mms_def.h"

#include "MMSBGSRSrvProt.h"
#include "MmsSrvGprot.h"
#include "MmsSrvProt.h"
// #include "MmsMsgParseSrv.h"
#include "MMSMemoryManagerSrv.h"
#include "ProfilesSrvGprot.h"
// #include "Custom_events_notify.h"
#include "IdleNotificationManagerGprot.h"
// #include "SmsGuiInterfaceProt.h"

//#include "SimDetectionGprot.h"
//#include "MMSAppUtil.h"
//#include "UmSrvGProt.h"
//#include "MMSJsrProts.h"
#include "MMSJSRSrvProts.h"
#include "UcSrvGprot.h"
#include "MmsSrvExt.h"
#include "phbsrvgprot.h"
#include "ModeSwitchSrvGprot.h"
#include "UriAgentSrvGprot.h"
#include "MmsSrvSendRcv.h"
#include "mmi_frm_events_gprot.h"
#include "mma_struct.h"
#include "Unicodexdcl.h"
#include "mms_sap_struct.h"
#include "UmSrvStruct.h"
#include "UmSrvDefs.h"
#include "mma_api.h"
// #include "SimDetectionStruct.h"
#include "stack_ltlcom.h" 

#include "mmi_frm_queue_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "NotificationGprot.h"
#include "CustDataRes.h"
#include "custom_wap_config.h"
#include "UcSrvGprot.h"

#include "gui.h"
#include "mmi_cb_mgr_gprot.h"
#include "MmsXMLDefSrv.h"
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
#include "MMSTemplateGenSrv.h"
#endif
extern U8 AlmIsTonePlaying(void);
extern kal_uint64 mma_get_mms_avaliable_file_space(kal_uint32 *usedBytes, U8 storage);
extern void srv_mms_slim_bgsr_init(void);
extern U8 srv_mms_entry_send_msg(const U32 msg_id, kal_uint8 sim_id, U8 storage_type, U8 app_id);

/* RAJKAMAL */
#ifdef __USB_IN_NORMAL_MODE__
extern void mms_on_exit_usb_mode(void);
extern void mms_on_enter_usb_mode(void);
#endif /* __USB_IN_NORMAL_MODE__ */ 
srv_mms_cntx_struct srv_mms_cntx;
srv_mms_cntx_struct *g_srv_mms_cntx = &srv_mms_cntx;

/* rajbir  */
srv_mms_new_message_cntx_struct srv_new_message_cntx;
srv_mms_new_message_cntx_struct *g_srv_new_msg_cntx = &srv_new_message_cntx;

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
srv_mms_mark_several_struct srv_mms_mark_several;
srv_mms_mark_several_struct *g_srv_mark_several_cntx = &srv_mms_mark_several;
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */ 
srv_mms_message_number_struct srv_mms_number;
srv_mms_message_number_struct *g_srv_msg_num_cntx = &srv_mms_number;

#ifdef __MMI_MMS_ROAMING_NO_ACCEPT_SUPPORT__
srv_mms_roaming_no_dowload_struct srv_mms_roaming;
srv_mms_roaming_no_dowload_struct *g_srv_roaming_cntx = &srv_mms_roaming;
#endif /* __MMI_MMS_ROAMING_NO_ACCEPT_SUPPORT__ */ 

#ifdef __MMI_MMS_REPORT_STATUS_SUPPORT__
extern mma_result_enum mma_mms_get_report_status_and_address(
                        kal_uint32 report_id,
                        mma_mms_msg_report_info_struct *data);
#endif /* __MMI_MMS_REPORT_STATUS_SUPPORT__ */ 

srv_mms_dual_sim_struct dual_sim_cntx;
srv_mms_dual_sim_struct *g_srv_dual_sim_cntx = &dual_sim_cntx;

extern BOOL g_is_wap_ready;
BOOL g_srv_is_usb_mode = FALSE;

const U32 num_query_array[SRV_MMS_MAX_MSG_NUM_QUERY_NUM] = 
{
    UMMS_QUERY_OPTION_NUM_UNREAD_INBOX_MSG_SIM1,        /*  Number of unread Msg in Inbox for SIM1 */
#if(MMI_MAX_SIM_NUM >= 2)
    UMMS_QUERY_OPTION_NUM_UNREAD_INBOX_MSG_SIM2,        /*  Number of unread Msg in Inbox for SIM2 */
#endif 
#if(MMI_MAX_SIM_NUM >= 3)
    UMMS_QUERY_OPTION_NUM_UNREAD_INBOX_MSG_SIM3,        /*  Number of unread Msg in Inbox for SIM3 */
#endif 
#if(MMI_MAX_SIM_NUM >= 4)
    UMMS_QUERY_OPTION_NUM_UNREAD_INBOX_MSG_SIM4,        /*  Number of unread Msg in Inbox for SIM4 */
#endif 
    UMMS_QUERY_OPTION_NUM_TOTAL_INBOX_MSG,              /*  total Number of Msg in  Inbox */
    UMMS_QUERY_OPTION_NUM_TOTAL_OUTBOX_MSG,             /*  total Number of Msg in Outbox */
    UMMS_QUERY_OPTION_NUM_TOTAL_SENT_MSG,               /*  total Number of Msg in Sent  */
    UMMS_QUERY_OPTION_NUM_TOTAL_DRAFT_MSG,              /*  total Number of Msg in Drafts */
    UMMS_QUERY_OPTION_NUM_TOTAL_ARCHIVE_MSG,            /*  Number of Msg in Archive  */
    UMMS_QUERY_OPTION_NUM_TOTAL_USER_DEF_TEMPLATE_MSG,  /*  Number of Msg in user defined template  */
    UMMS_QUERY_OPTION_NUM_TOTAL_PRE_DEF_TEMPLATE_MSG,   /*  Number of Msg in Pr defined template  */
    UMMS_QUERY_OPTION_NUM_TOTAL_UNREAD_MSG,             /*  Number of Unread Msg in All folders */
    UMMS_QUERY_OPTION_NUM_TOTAL_PHONE,
    UMMS_QUERY_OPTION_NUM_TOTAL_CARD
};

extern BOOL srv_mms_compare_string_ignore_case(U16 *addr_1, U16 *addr_2);

#ifdef __MMI_MMS_REPORT_BOX_SUPPORT__
extern void mma_mms_reset_unread_report_status(void);
#endif 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_init
 * DESCRIPTION
 *  Init mms service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_init(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_URI_AGENT__
    srv_uriagent_err_enum err;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_init_app_adm();
    srv_mms_init_use_details();

#ifdef __MMI_MMS_URI_AGENT__
#if (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__))
    err = srv_uriagent_register_hdlr_by_scheme((const char*)MMI_UMMS_MMS_TO_URI, srv_mms_uri_insert_hdlr, MMI_FALSE);
    MMI_ASSERT(err == SRV_URIAGENT_ERR_OK);
    err = srv_uriagent_register_hdlr_by_scheme((const char*)MMI_TO_UMMS_MMS_TO_URI, srv_mms_uri_insert_hdlr, MMI_FALSE);
    MMI_ASSERT(err == SRV_URIAGENT_ERR_OK);
#endif /* (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__)) */ 
#endif /* __MMI_MMS_URI_AGENT__ */ 

#ifdef __MMI_MMS_MMA_MMS_OBJECT_IND__
    srv_mms_init_object_ind_data();
#endif 
#ifdef __MMI_MMS_ROAMING_NO_ACCEPT_SUPPORT__
    srv_mms_init_notify_roaming_download_data();
#endif 

    srv_mms_signature_data_init();
    srv_mms_send_events(EVT_ID_SRV_BOOTUP_INIT, NULL);
    srv_mms_set_protocol_event_handler();

#if defined(__MMI_MMS_BGSR_SUPPORT__) && defined(__MMI_MMS_LOW_TIER_BGSR_SUPPORT__)
    srv_mms_slim_bgsr_init();
#endif

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_protocol_event_handler
 * DESCRIPTION
 *  sets the protocol handlers for primitives
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_protocol_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_GET_MSG_INFO_RSP,
        (PsIntFuncPtr) srv_mms_mma_get_msg_info_rsp,
        MMI_TRUE);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_GET_CONTENT_RSP,
        (PsIntFuncPtr) srv_mms_get_content_rsp,
        MMI_TRUE);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_GET_MSG_NUM_RSP,
        (PsIntFuncPtr) srv_mms_get_msg_num_rsp,
        MMI_TRUE);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_SET_READMARK_RSP,
        (PsIntFuncPtr) srv_mms_set_readmark_rsp,
        MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WAP_MMA_SAVE_RSP, (PsIntFuncPtr) srv_mms_save_rsp, MMI_TRUE);
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
    mmi_frm_set_protocol_event_handler(MSG_ID_WAP_MMA_DELETE_RSP, (PsIntFuncPtr) srv_mms_delete_rsp, MMI_TRUE);
#endif
    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_GET_UNREAD_MSG_LIST_RSP,
        (PsIntFuncPtr) srv_mms_get_unread_msg_list_rsp,
        MMI_TRUE);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_GET_MSG_PROPERTY_RSP,
        (PsIntFuncPtr) srv_mms_get_msg_property_list_rsp,
        MMI_TRUE);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_GET_RECENT_EVT_LIST_RSP,
        (PsIntFuncPtr) srv_mms_get_recent_evt_list_rsp,
        MMI_TRUE);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_DELETE_RECENT_EVT_RSP,
        (PsIntFuncPtr) srv_mms_delete_recent_event_rsp,
        MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WAP_MMA_MMS_OBJ_RES, (PsIntFuncPtr) srv_mms_recv_obj_ind_rsp, MMI_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WAP_MMA_CREATE_RSP, (PsIntFuncPtr) srv_mms_create_rsp, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_DELETE_ALL_RES, (PsIntFuncPtr) srv_mms_delete_all_rsp, MMI_TRUE);
#ifdef __MMI_VCARD__
    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_UMMS_GET_VCARD_VERSION_REQ,
        (PsIntFuncPtr) srv_mms_vcard_version_req_hdlr,
        MMI_TRUE);
#endif /* __MMI_VCARD__ */ 
    mmi_frm_set_protocol_event_handler(MSG_ID_WAP_MMA_VIEW_MSG_IND, (PsIntFuncPtr) srv_mms_view_msg_ind_hdlr, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_STORAGE_FULL_IND,
        (PsIntFuncPtr) srv_mms_storage_full_ind_hdlr,
        MMI_TRUE);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_TERMINATE_IND,
        (PsIntFuncPtr) srv_mms_terminate_ind_hdlr,
        MMI_TRUE);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_START_IMMED_RETRIEVAL_IND,
        (PsIntFuncPtr) srv_mms_start_immed_retrieval_ind_hdlr,
        MMI_TRUE);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_STOP_IMMED_RETRIEVAL_IND,
        (PsIntFuncPtr) srv_mms_stop_immed_retrieval_ind_hdlr,
        MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_READY_IND, (PsIntFuncPtr) srv_mms_um_ready_ind_hdlr, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_READY_IND,
        (PsIntFuncPtr) srv_mms_wap_mma_ready_ind_hdlr,
        MMI_TRUE);

    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_SET_APP_DATA_RSP,
        (PsIntFuncPtr) srv_mms_set_app_data_rsp,
        MMI_TRUE);
    /* amit added for template list */
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_UM_GET_MSG_LIST_RSP,
        (PsIntFuncPtr) srv_mms_um_get_msg_list_rsp,
        MMI_TRUE);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_UM_GET_MSG_INFO_RSP,
        (PsIntFuncPtr) srv_mms_um_get_msg_info_rsp,
        MMI_TRUE);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_CHECK_TEMPLATE_REQ,
        (PsIntFuncPtr) srv_mms_default_template_check_template_req,
        MMI_TRUE);
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 
#if 0
#ifdef __MMI_MMS_DUAL_SIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_MMS_DUAL_SIM__ */ 
#endif /* 0 */ 
    /* Rajbir */
    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_NOTIFY_EVENT_IND,
        (PsIntFuncPtr) srv_mms_notify_event_ind,
        MMI_TRUE);
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_UM_ENTRY_MARK_SEVERAL_RSP,
        (PsIntFuncPtr) srv_mms_entry_mark_several_rsp,
        MMI_TRUE);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_UM_MARK_SEVERAL_OP_REQ,
        (PsIntFuncPtr) srv_mms_multi_op_req_hdlr,
        MMI_TRUE);
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */ 
#ifdef __MMI_MMS_USE_ASM__
    SetProtocolEventHandler(srv_mms_mem_mgr_get_asm_pool_for_service_req_hdlr, MSG_ID_MMI_MMS_GET_ASM_MEM_PTR_REQ);
    SetProtocolEventHandler(srv_mms_free_asm_pool_for_service_req, MSG_ID_MMI_MMS_FREE_ASM_MEM_PTR_REQ);
    SetProtocolEventHandler(srv_mms_deinit_asm_pool_for_service_rsp, MSG_ID_MMI_MMS_GET_DEINIT_SERVICE_ASM_RSP);
#endif /* __MMI_MMS_USE_ASM__ */ 
    /* amit added for set settings_rsp */
    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_SET_SETTING_RSP,
        (PsIntFuncPtr) srv_mms_mma_set_settings_rsp,
        MMI_TRUE);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_SET_PROFILE_RSP,
        (PsIntFuncPtr) srv_mms_get_set_profile_rsp,
        MMI_TRUE);

    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_UM_DELETE_FOLDER_RSP,
        (PsIntFuncPtr) srv_mms_delete_folder_rsp,
        MMI_TRUE);
    /* amit added for set settings_rsp */
    /* mmi_frm_set_protocol_event_handler(MSG_ID_WAP_MMA_SET_SETTING_RSP, (PsIntFuncPtr)srv_mms_mma_set_settings_rsp, MMI_FALSE); */
    /* memory card */
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_CHG_MSG_STORAGE_RSP,
        (PsIntFuncPtr) srv_mms_get_msg_change_storage_rsp,
        MMI_TRUE);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_MMS_CARD_PLUG_IN_RES,
        (PsIntFuncPtr) srv_mms_get_memory_card_pug_in_response,
        MMI_TRUE);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_MMS_CARD_PLUG_OUT_RES,
        (PsIntFuncPtr) srv_mms_get_memory_card_pug_out_response,
        MMI_TRUE);
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 

#ifdef __USB_IN_NORMAL_MODE__
    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMS_EXIT_USB_MODE_RSP,
        (PsIntFuncPtr) srv_mms_exit_usb_rsp_hdlr,
        MMI_TRUE);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMS_ENTER_USB_MODE_RSP,
        (PsIntFuncPtr) srv_mms_entry_usb_rsp_hdlr,
        MMI_TRUE);
#endif /* __USB_IN_NORMAL_MODE__ */ 
#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
    SetProtocolEventHandler(srv_mms_vendor_create_req_hdlr, MSG_ID_MMI_MMS_VENDOR_CREATE_REQ);
    SetProtocolEventHandler(srv_mms_vendor_send_req_hdlr, MSG_ID_MMI_MMS_VENDOR_SEND_REQ);
    SetProtocolEventHandler(srv_mms_vendor_delete_req_hdlr, MSG_ID_MMI_MMS_VENDOR_DELETE_REQ);
    SetProtocolEventHandler(srv_mms_vendor_cancel_send_req_hdlr, MSG_ID_MMI_MMS_VENDOR_CANCEL_SEND_REQ);
#endif /* __MMI_MMS_VENDOR_APP_SUPPORT__ */ 
    /*  memory card */
    SetProtocolEventHandler(srv_mms_mma_insuf_mem_req_hdlr, MSG_ID_WAP_MMA_INSUFFICIENT_MEMORY_IND);
#ifdef __MMI_MMS_COPY_TO_ARCHIVE_SUPPORT__
    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_MMS_CPY_TO_ARCHIVE_RSP,
        (PsIntFuncPtr) srv_mms_copy_to_archive_rsp,
        MMI_TRUE);
#endif
    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_GET_MSG_ATTR_AND_THUMBNAIL_RSP,
        (PsIntFuncPtr)srv_mms_get_lite_viewer_data_rsp ,
        MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_process_slot
 * DESCRIPTION
 *  Get empty process index
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 * RETURN VALUE
 *  srv_mms_process_data_struct pointer
 *****************************************************************************/
srv_mms_process_data_struct *srv_mms_get_process_slot(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_process_data_struct *process = NULL;
    srv_mms_process_data_struct *temp_node = NULL;
    U8 count = 0;

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
#endif /* 0 */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set the 4N MAUI_02142001    */

    process = (srv_mms_process_data_struct*) srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_process_data_struct));
    if (process == NULL)
    {
        return process;
    }
    memset(process, 0, sizeof(srv_mms_process_data_struct));

    temp_node = g_srv_mms_cntx->mms_process_tbl;

    if (temp_node == NULL)
    {
        g_srv_mms_cntx->mms_process_tbl = process;
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            TRC_SRV_MMS_GET_PROCESS_SLOT,
            count,
            process->req_id,
            process->app_id,
            process->user_data,
            process->call_back,
            process->result,
            process->cntx);
    }
    else
    {
        while (temp_node->next != NULL)
        {
            MMI_TRACE(
                MMI_INET_TRC_G6_MMS,
                TRC_SRV_MMS_GET_PROCESS_SLOT,
                count++,
                temp_node->req_id,
                temp_node->app_id,
                temp_node->user_data,
                temp_node->call_back,
                temp_node->result,
                temp_node->cntx);
            temp_node = temp_node->next;
        }
        temp_node->next = process;
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            TRC_SRV_MMS_GET_PROCESS_SLOT,
            count,
            process->req_id,
            process->app_id,
            process->user_data,
            process->call_back,
            process->result,
            process->cntx);
    }

    return process;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_process_by_req_id
 * DESCRIPTION
 *  Looks for process with given req_id and returns if found
 * PARAMETERS
 *  req_id      [IN]        
 * RETURNS
 *  srv_mms_process_data_struct
 *****************************************************************************/
srv_mms_process_data_struct *srv_mms_get_process_by_req_id(U32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
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
#endif /* 0 */ 
    
    
    srv_mms_process_data_struct *temp_node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_node = g_srv_mms_cntx->mms_process_tbl;

    for (; temp_node != NULL; temp_node = temp_node->next)
    {
        if (req_id == temp_node->req_id)
        {
            return temp_node;
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_process_by_app_id
 * DESCRIPTION
 *  Looks for process with given app and returns if found
 * PARAMETERS
 *  app_id      [IN]        
 * RETURNS
 *  srv_mms_process_data_struct
 *****************************************************************************/
srv_mms_process_data_struct *srv_mms_get_process_by_app_id(U8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
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
#endif /* 0 */ 

  
    
    srv_mms_process_data_struct *temp_node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_node = g_srv_mms_cntx->mms_process_tbl;

    for (; temp_node != NULL; temp_node = temp_node->next)
    {
        if (app_id == temp_node->app_id)
        {
            return temp_node;
        }
    }

    return NULL;

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_is_ready
 * DESCRIPTION
 *  To check if service is ready or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL (TRUE if service ready, FALSE: If service not ready)
 *****************************************************************************/
MMI_BOOL srv_mms_is_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_mms_cntx->is_srv_ready;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_reset_process_data
 * DESCRIPTION
 *  Reset process struct
 * PARAMETERS
 *  process     [?]     [?]
 *  req_id(?)(?)
 * RETURNS
 *  srv_mms_process_data_struct(?)(?)
 *****************************************************************************/
void srv_mms_reset_process_data(srv_mms_process_data_struct *process)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
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
#endif /* 0 */ 

    
    srv_mms_process_data_struct *temp_node, *prev = NULL;

    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        TRC_SRV_MMS_RESET_PROCESS_SLOT,
        process->req_id,
        process->app_id,
        process->user_data,
        process->call_back,
        process->result,
        process->cntx);

    temp_node = g_srv_mms_cntx->mms_process_tbl;

    if (temp_node == NULL)
    {
        // ASSERT(0);   /*Removed assert because some times it is possible that whole table may deinit*/
        /* and some service try to access process data when some cb is called */
        return;
    }

    while (temp_node != process && temp_node != NULL)
    {
        prev = temp_node;
        temp_node = temp_node->next;
    }
    if (temp_node == NULL)
    {
        return;
    }
    if (prev == NULL)
    {
        /* first node, but not only node  || first and last node */
        g_srv_mms_cntx->mms_process_tbl = temp_node->next;
    }
    else
    {
        /* last node || in-between node */
        prev->next = temp_node->next;
    }

    if (temp_node->result)
    {
        srv_mms_mem_mgr_app_adm_free(temp_node->result);
    }
    if (temp_node->cntx)
    {
        srv_mms_mem_mgr_app_adm_free(temp_node->cntx);
    }
    srv_mms_mem_mgr_app_adm_free(temp_node);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mma_get_msg_info_data_hdlr
 * DESCRIPTION
 *  Fills the data from MMA to result struct srv_mms_mma_get_msg_info_rsp_struct
 * PARAMETERS
 *  process     [?]     [?]     [IN]Process struct
 *  msg         [?]     [?]     [IN]Response from MMA
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_mma_get_msg_info_data_hdlr(srv_mms_process_data_struct *process, void *msg)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_msg_info_rsp_struct *rsp = (wap_mma_get_msg_info_rsp_struct*) msg;
    srv_mms_mma_get_msg_info_rsp_struct *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = process->result;

    result->result = rsp->result;
    result->msg_id = rsp->msg_id;
    result->app_id = rsp->app_id;
    result->msg_media_type = rsp->msg_media_type;
    result->from_address_type = rsp->from_address_type;
    result->msg_class = rsp->msg_class;
    result->priority = rsp->priority;
    /* result->msg_status = rsp->msg_status; */
    result->msg_size = rsp->msg_size;
    result->date = rsp->date;
    result->received_date = rsp->received_date;
    result->expiry_date = rsp->expiry_date; /* Change from earlier App + rsp->received_date; */
    result->isRead = rsp->isRead;
    result->need_read_report = rsp->need_read_report;
    result->isForwardLock = rsp->isForwardlock;
    result->isDRM = rsp->isDRM;
    result->isFollowPhoneMMSContentClass = rsp->isFollowPhoneMMSContentClass;
    result->hasAttachment = rsp->hasAttachment;
    result->msg_type = rsp->msg_type;
    result->sim_id = rsp->sim_id;
    result->user_elements_size = rsp->user_elements_size;
    result->storage_type = rsp->storage_type;
    mmi_ucs2ncpy((PS8) result->from_address, (PS8) rsp->from_address, MMA_MAX_ADDR_LEN);
    mmi_ucs2ncpy((PS8) result->subject, (PS8) rsp->subject, MMA_MAX_SUBJECT_LEN);
    memcpy((PS8) result->app_data, (PS8) rsp->app_data, MMA_MAX_APP_DATA_LENGTH);
    mmi_ucs2ncpy((PS8) result->java_app_id, (PS8) rsp->java_app_id, SRV_MMS_MAX_COMM_STRING_LENGTH);
    mmi_ucs2ncpy((PS8) result->java_reply_app_id, (PS8) rsp->java_reply_app_id, SRV_MMS_MAX_COMM_STRING_LENGTH);

    process->call_back(SRV_MMS_RESULT_OK, process->result, process->user_data);

    srv_mms_reset_process_data(process);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_content_data_hdlr
 * DESCRIPTION
 *  Fills the data from MMA to result struct srv_mms_get_content_rsp_struct
 * PARAMETERS
 *  process     [?]     [?]     [IN]Process struct
 *  msg         [?]     [?]     [IN]Response from MMA
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_get_content_data_hdlr(srv_mms_process_data_struct *process, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_content_rsp_struct *rsp = (wap_mma_get_content_rsp_struct*) msg;
    srv_mms_get_content_rsp_struct *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = process->result;

    result->msg_id = rsp->msg_id;
    result->mms_header_size = rsp->mms_header_size;
    result->mms_body_size = rsp->mms_body_size;
    /* result->xml_size = rsp->xml_size; */
    result->isFollowPhoneMMSContentClass = rsp->isFollowPhoneMMSContentClass;
    result->app_id = rsp->app_id;
    result->result = rsp->result;
    result->content_info = rsp->content_info;
    result->content_truncate_info = rsp->content_truncate_info;
    result->req_id = rsp->req_id;
    /* mmi_ucs2ncpy((PS8) result->xml_filepath, (PS8) rsp->xml_filepath, MMA_MAX_INTERNAL_FILENAME_LENGTH); */

    process->call_back(SRV_MMS_RESULT_OK, process->result, process->user_data);
#if defined (__MMI_MMS_USE_ASM__) && defined (__COSMOS_MMI_PACKAGE__)
    if(!srv_mms_check_asm_memory_is_int())
	{
		srv_mms_send_events_ex(EVT_ID_SRV_MMS_SERVICE_MEM_FREE_DONE, NULL);
	}
#endif
    srv_mms_reset_process_data(process);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_msg_num_data_hdlr
 * DESCRIPTION
 *  Fills the data from MMA to result struct  srv_mms_get_msg_num_rsp_struct
 * PARAMETERS
 *  process     [?]     [?]     [IN]Process struct
 *  msg         [?]     [?]     [IN]Response from MMA
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_get_msg_num_data_hdlr(srv_mms_process_data_struct *process, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_msg_num_rsp_struct *rsp = (wap_mma_get_msg_num_rsp_struct*) msg;
    srv_mms_get_msg_num_rsp_struct *result;
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = process->result;

    result->app_id = rsp->app_id;
    result->result = rsp->result;

    for (count = 0; count < MMA_MAX_MSG_NUM_QUERY_NUM; count++)
    {
        result->rsp_tb[count] = rsp->rsp_tb[count];
    }

    process->call_back(SRV_MMS_RESULT_OK, process->result, process->user_data);

    srv_mms_reset_process_data(process);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_readmark_data_hdlr
 * DESCRIPTION
 *  Fills the data from MMA to result struct srv_mms_set_readmark_rsp_struct
 * PARAMETERS
 *  process     [?]     [?]     [IN]Process struct
 *  msg         [?]     [?]     [IN]Response from MMA
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_readmark_data_hdlr(srv_mms_process_data_struct *process, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_set_readmark_rsp_struct *rsp = (wap_mma_set_readmark_rsp_struct*) msg;
    srv_mms_set_readmark_rsp_struct *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = process->result;

    result->app_id = rsp->app_id;
    result->result = rsp->result;

    process->call_back(SRV_MMS_RESULT_OK, process->result, process->user_data);

    srv_mms_reset_process_data(process);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_save_data_hdlr
 * DESCRIPTION
 *  Fills the data from MMA to result struct srv_mms_save_rsp_struct
 * PARAMETERS
 *  process     [?]     [?]     [IN]Process struct
 *  msg         [?]     [?]     [IN]Response from MMA
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_save_data_hdlr(srv_mms_process_data_struct *process, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_save_rsp_struct *rsp = (wap_mma_save_rsp_struct*) msg;
    srv_mms_save_rsp_struct *result;
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = process->result;

    result->app_id = rsp->app_id;
    result->no_of_msg = rsp->no_of_msg;

    for (count = 0; count < rsp->no_of_msg; count++)
    {
        result->msg_id[count] = rsp->msg_id[count];
    }
    for (count = 0; count < rsp->no_of_msg; count++)
    {
        result->result[count] = rsp->result[count];
    }

    process->call_back(SRV_MMS_RESULT_OK, process->result, process->user_data);
    /* amit added for template list data delete */
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
    if (rsp->app_id == MMA_APP_ID_UC)
    {
        srv_mms_send_events(EVT_ID_SRV_SAVE_RSP_FROM_UC, NULL);
    }
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 
    srv_mms_reset_process_data(process);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_delete_data_hdlr
 * DESCRIPTION
 *  Fills the data from MMA to result struct srv_mms_delete_rsp_struct
 * PARAMETERS
 *  process     [?]     [?]     [IN]Process struct
 *  msg         [?]     [?]     [IN]Response from MMA
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_delete_data_hdlr(srv_mms_process_data_struct *process, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_delete_rsp_struct *rsp = (wap_mma_delete_rsp_struct*) msg;
    srv_mms_delete_rsp_struct *result;
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = process->result;

    result->app_id = rsp->app_id;
    result->no_of_msg = rsp->no_of_msg;

    for (count = 0; count < rsp->no_of_msg; count++)
    {
        result->msg_id[count] = rsp->msg_id[count];
    }
    for (count = 0; count < rsp->no_of_msg; count++)
    {
        result->result[count] = rsp->result[count];
    }

    process->call_back(SRV_MMS_RESULT_OK, process->result, process->user_data);

    srv_mms_reset_process_data(process);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_unread_msg_list_data_hdlr
 * DESCRIPTION
 *  Fills the data from MMA to result struct srv_mms_get_unread_msg_list_rsp_struct
 * PARAMETERS
 *  process     [?]     [?]     [IN]Process struct
 *  msg         [?]     [?]     [IN]Response from MMA
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_get_unread_msg_list_data_hdlr(srv_mms_process_data_struct *process, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_unread_msg_list_rsp_struct *rsp = (wap_mma_get_unread_msg_list_rsp_struct*) msg;
    srv_mms_get_unread_msg_list_rsp_struct *result;
#if defined (__MMI_OP11_HOMESCREEN__) || defined (__MMI_OP12_TOOLBAR__) || defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    U8 count;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = process->result;

    result->app_id = rsp->app_id;
    result->result = rsp->result;
    result->total_num_of_unread_msg = rsp->total_num_of_unread_msg;
    result->num_of_unread_msg = rsp->num_of_unread_msg;
    result->more = rsp->more;
#if defined (__MMI_OP11_HOMESCREEN__) || defined (__MMI_OP12_TOOLBAR__) || defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    for (count = 0; count < MMA_MAX_UNREAD_MSG_NUM; count++)
    {
        result->unread_msg_list[count] = rsp->unread_msg_list[count];
    }
#endif /* defined (__MMI_OP11_HOMESCREEN__) || defined (__MMI_OP12_TOOLBAR__) || defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */ 
    process->call_back(SRV_MMS_RESULT_OK, process->result, process->user_data);

    srv_mms_reset_process_data(process);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_msg_property_list_data_hdlr
 * DESCRIPTION
 *  Fills the data from MMA to result struct srv_mms_property_rsp_struct
 * PARAMETERS
 *  process     [?]     [?]     [IN]Process struct
 *  msg         [?]     [?]     [IN]Response from MMA
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_get_msg_property_list_data_hdlr(srv_mms_process_data_struct *process, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_msg_property_rsp_struct *rsp = (wap_mma_get_msg_property_rsp_struct*) msg;
    srv_mms_property_rsp_struct *result;
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = process->result;

    result->app_id = rsp->app_id;
    result->result = rsp->result;
    result->num_of_msg = rsp->num_of_msg;

    for (count = 0; count < rsp->num_of_msg; count++)
    {
        result->msg_property[count] = rsp->msg_property[count];
    }

    process->call_back(SRV_MMS_RESULT_OK, process->result, process->user_data);

    srv_mms_reset_process_data(process);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_recent_evt_list_data_hdlr
 * DESCRIPTION
 *  Fills the data from MMA to result struct srv_mms_recent_evt_list_rsp_struct
 * PARAMETERS
 *  process     [?]     [?]     [IN]Process struct
 *  msg         [?]     [?]     [IN]Response from MMA
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_get_recent_evt_list_data_hdlr(srv_mms_process_data_struct *process, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_recent_evt_list_rsp_struct *rsp = (wap_mma_get_recent_evt_list_rsp_struct*) msg;
    srv_mms_recent_evt_list_rsp_struct *result;
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = process->result;

    result->app_id = rsp->app_id;
    result->result = rsp->result;
    result->total_num_of_evt = rsp->total_num_of_evt;
    result->num_of_evt = rsp->num_of_evt;
    result->more = rsp->more;
    for (count = 0; count < rsp->num_of_evt; count++)
    {
        result->event_list[count] = rsp->event_list[count];
    }

    process->call_back(SRV_MMS_RESULT_OK, process->result, process->user_data);

    srv_mms_reset_process_data(process);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_delete_recent_event_data_hdlr
 * DESCRIPTION
 *  Fills the data from MMA to result struct srv_mms_delete_recent_evt_rsp_struct
 * PARAMETERS
 *  process     [?]     [?]     [IN]Process struct
 *  msg         [?]     [?]     [IN]Response from MMA
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_delete_recent_event_data_hdlr(srv_mms_process_data_struct *process, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_delete_recent_evt_rsp_struct *rsp = (wap_mma_delete_recent_evt_rsp_struct*) msg;
    srv_mms_delete_recent_evt_rsp_struct *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = process->result;

    result->app_id = rsp->app_id;
    result->result = rsp->result;
    result->msg_id = rsp->msg_id;

    process->call_back(SRV_MMS_RESULT_OK, process->result, process->user_data);

    srv_mms_reset_process_data(process);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_obj_ind_rsp_data_hdlr
 * DESCRIPTION
 *  Fills the data from MMA to result struct srv_mms_obj_ind_struct
 * PARAMETERS
 *  process     [?]     [?]     [IN]Process struct
 *  msg         [?]     [?]     [IN]Response from MMA
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_obj_ind_rsp_data_hdlr(srv_mms_process_data_struct *process, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_mms_obj_res_struct *rsp = (wap_mma_mms_obj_res_struct*) msg;
    srv_mms_obj_res_struct *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = process->result;

    result->app_id = rsp->app_id;
    result->result = rsp->result;

    process->call_back(SRV_MMS_RESULT_OK, process->result, process->user_data);

    srv_mms_reset_process_data(process);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_create_data_hdlr
 * DESCRIPTION
 *  Fills the data from MMA to result struct srv_mms_create_rsp_struct
 * PARAMETERS
 *  process     [?]     [?]     [IN]Process struct
 *  msg         [?]     [?]     [IN]Response from MMA
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_create_data_hdlr(srv_mms_process_data_struct *process, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_create_rsp_struct *rsp = (wap_mma_create_rsp_struct*) msg;
    srv_mms_create_cntx_struct *cntx = process->cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx->op_type == SRV_MMS_CREATE_MMS)
    {
        srv_mms_create_rsp_struct *result;

        result = process->result;

        result->app_id = rsp->app_id;
        result->result = rsp->result;
        result->min_fs_space_required = rsp->min_fs_space_required;
        result->storage = rsp->storage;
        result->msg_id = rsp->msg_id;

        process->call_back(SRV_MMS_RESULT_OK, process->result, process->user_data);
    }
    else if ((cntx->op_type == SRV_MMS_CREATE_SAVE_MMS) || (cntx->op_type == SRV_MMS_CREATE_SAVE_TEMPLATE_MMS))
    {
        if (rsp->result != MMA_RESULT_OK)
        {
            srv_mms_save_rsp_struct *result;

            result = process->result;

            result->app_id = rsp->app_id;
            result->no_of_msg = 1;
            result->msg_id[0] = rsp->msg_id;
            result->result[0] = rsp->result;
            process->call_back(SRV_MMS_RESULT_OK, process->result, process->user_data);
        }
        else
        {
            srv_mms_save_req_struct save;

            memset(&save, 0, sizeof(srv_mms_save_req_struct));
            save.user_data = process->user_data;
            save.call_back = process->call_back;
            save.no_of_msg = 1;
            if (cntx->op_type == SRV_MMS_CREATE_SAVE_TEMPLATE_MMS)
            {
                save.box = MMA_FOLDER_USRDEF_TEMPLATE;
            }
            else
            {
                save.box = MMA_FOLDER_DRAFT;
            }
            save.app_id = rsp->app_id;
            save.msg_id[0] = rsp->msg_id;
            srv_mms_save(&save);
        }
    }
    else if (cntx->op_type == SRV_MMS_CREATE_SEND_MMS)
    {
        srv_mms_create_rsp_struct *result;

        result = process->result;

        result->app_id = rsp->app_id;
        result->result = rsp->result;
        result->min_fs_space_required = rsp->min_fs_space_required;
        result->storage = rsp->storage;
        result->msg_id = rsp->msg_id;
        process->call_back(SRV_MMS_RESULT_OK, process->result, process->user_data);
        if (rsp->result == MMA_RESULT_OK)
        {
            srv_mms_entry_send_msg(rsp->msg_id, (kal_uint8) cntx->sim_id, rsp->storage, (kal_uint8) rsp->app_id);
        }

    }
    else
    {
        ASSERT(0);
    }

    srv_mms_reset_process_data(process);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_power_off_data_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  process     [?]     [?]     [IN]Process struct
 *  msg         [?]     [?]     [IN]Response from MMA
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_power_off_data_hdlr(srv_mms_process_data_struct *process, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_power_off_rsp_struct *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = process->result;
    result->result = MMI_TRUE;

    process->call_back(SRV_MMS_RESULT_OK, process->result, process->user_data);

    srv_mms_reset_process_data(process);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_delete_all_data_hdlr
 * DESCRIPTION
 *  Fills the data from MMA to result struct srv_mms_delete_all_res_struct
 * PARAMETERS
 *  process     [?]     [?]     [IN]Process struct
 *  msg         [?]     [?]     [IN]Response from MMA
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_delete_all_data_hdlr(srv_mms_process_data_struct *process, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_delete_all_res_struct *rsp = (srv_um_delete_all_res_struct*) msg;
    srv_mms_delete_all_res_struct *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = process->result;

    result->msg_type = rsp->msg_type;
    result->result = rsp->result;

    process->call_back(SRV_MMS_RESULT_OK, process->result, process->user_data);

    srv_mms_reset_process_data(process);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_delete_folder_data_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  process     [?]     [?]
 *  msg         [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_delete_folder_data_hdlr(srv_mms_process_data_struct *process, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_delete_folder_rsp_struct *rsp = (srv_um_delete_folder_rsp_struct*) msg;
    srv_mms_delete_folder_rsp_struct *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = process->result;

    result->msg_type = rsp->msg_type;
    result->result = rsp->result;

    process->call_back(SRV_MMS_RESULT_OK, process->result, process->user_data);

    srv_mms_reset_process_data(process);
    return;
}

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_entry_mark_several_screen_data_hdlr
 * DESCRIPTION
 *  Fills the data from MMA to result struct srv_mms_entry_mark_several_rsp_struct
 * PARAMETERS
 *  process     [?]     [?]     [IN]Process struct
 *  msg         [?]     [?]     [IN]Response from MMA
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_entry_mark_several_screen_data_hdlr(srv_mms_process_data_struct *process, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    // srv_um_entry_mark_several_rsp_struct *rsp = (srv_um_entry_mark_several_rsp_struct *)msg;
    // srv_mms_entry_mark_several_rsp_struct *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* result = process->result; */

    // result->app_id = rsp->app_id;
    //  result->result = rsp->result;
    //  result->msg_type = rsp->msg_type;
    //  result->msg_box_type = rsp->msg_box_type;

    /* process->call_back(SRV_MMS_RESULT_OK,  process->result, process->user_data); */
    /* srv_mms_reset_process_data(process); */
    return;
}
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */ 

/* Rajbir  */
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mark_several_list_procress
 * DESCRIPTION
 *  
 * PARAMETERS
 *  multi_op        [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_mark_several_list_procress(void *multi_op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_multi_op_recv_req_struct *recv = (srv_mms_multi_op_recv_req_struct*) multi_op;
    srv_mms_property_req_struct req;
    U16 count = 0;
    U16 index = 0;
    
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (recv->msg_box_type == SRV_UM_MSG_BOX_UNSENT)
    {
        if (recv->action_type == SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_ARCHIVE)
        {
            srv_mms_send_multi_move_rsp_to_um();
            return MMI_FALSE;
        }
    }

    if ((recv->action_type == SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_SIM) ||
        (recv->action_type == SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_SIM) ||
        (recv->action_type == SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_SIM1) ||
        (recv->action_type == SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_SIM2) ||
        (recv->action_type == SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_SIM3) ||
        (recv->action_type == SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_SIM4))
    {
        for (count = 0; count < g_srv_mark_several_cntx->msg_number; count++)
        {
            g_srv_mark_several_cntx->updated_msg_id[count] = g_srv_mark_several_cntx->msg_id[count];
            g_srv_mark_several_cntx->action_result[count] = KAL_FALSE;
        }
        srv_mms_send_multi_move_rsp_to_um();
        return MMI_FALSE;
    }

    g_srv_mark_several_cntx->msg_number = recv->msg_number;
    g_srv_mark_several_cntx->msg_box_type = (mma_folder_enum)srv_mms_convert_umbox_type_to_mma_folder(recv->msg_box_type);
    g_srv_mark_several_cntx->action_type = recv->action_type;
    g_srv_mark_several_cntx->curr_index = 0;

    for (count = 0; count < g_srv_mark_several_cntx->msg_number; count++)
    {
        g_srv_mark_several_cntx->msg_id[count] = recv->msg_id[count];
    }
#ifdef __MMI_MMS_REPORT_BOX_SUPPORT__
    if (SRV_UM_MSG_BOX_REPORT == recv->msg_box_type)
    {
        if (SRV_UM_MARK_SEVERAL_OP_ACTION_DELETE == recv->action_type)
        {
			U8 result = 0;
			S32 srv_result = 0;

            if (1 == recv->msg_number)
            {
                srv_result = srv_mms_delete_report_msg(recv->msg_id[0], &result);

                if (srv_result == SRV_MMS_RESULT_OK)
                {
                    U32 i = 0, j = 0;

                    srv_mms_show_status_icon();

                    g_srv_mark_several_cntx->updated_msg_id[i] = recv->msg_id[i];
                    g_srv_mark_several_cntx->action_result[i] = result;
                    i++;

                    /* Send this structure to UM */
                    srv_mms_send_multi_delete_rsp_to_um();
                }
            }
            else
            {
                srv_mms_delete_req_struct req;
                U16 index = 0;

                req.user_data = 0;
                req.call_back = srv_mms_mark_several_delete_rsp;
                req.no_of_msg = g_srv_mark_several_cntx->msg_number;
                req.box = g_srv_mark_several_cntx->msg_box_type;
                req.app_id = MMA_APP_ID_MMS_APP_MARK_SEVERAL;

                for (index = 0; index < g_srv_mark_several_cntx->msg_number; index++)
                {
                    req.msg_id[index] = g_srv_mark_several_cntx->msg_id[index];
                }
                srv_mms_delete(&req);
            }

        }
        return MMI_FALSE;

    }
    else
#endif /* __MMI_MMS_REPORT_BOX_SUPPORT__ */ 
    {
        req.user_data = 0;
        req.app_id = MMA_APP_ID_MMS_APP_MARK_SEVERAL;
        req.no_of_msg = recv->msg_number;
        req.call_back = srv_mms_umms_mark_several_property_rsp;
        for (index = 0; index < recv->msg_number; index++)
        {
            req.msg_id[index] = g_srv_mark_several_cntx->msg_id[index];
        }

        srv_mms_get_msg_property_list(&req);
    }
    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_umms_mark_several_property_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  msgrsp          [?]         [?]
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_umms_mark_several_property_rsp(srv_mms_result_enum result, void *msgrsp, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U32 count = 0;
    U32 num = 0;
    U8 bgsr_folder_id = 0;
    srv_mms_property_rsp_struct *msg_rsp = (srv_mms_property_rsp_struct*) msgrsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bgsr_folder_id = srv_mms_convert_mma_folder_to_bgsr_folder(g_srv_mark_several_cntx->msg_box_type);

    for (i = 0; i < g_srv_mark_several_cntx->msg_number; i++)
    {
        g_srv_mark_several_cntx->msg_type[i] = msg_rsp->msg_property[i].msg_type;
        g_srv_mark_several_cntx->msg_read_status[i] = msg_rsp->msg_property[i].is_read;
    }

    switch (g_srv_mark_several_cntx->action_type)
    {
        case SRV_UM_MARK_SEVERAL_OP_ACTION_DELETE:
            if (((g_srv_mark_several_cntx->msg_box_type & MMA_FOLDER_INBOX) == MMA_FOLDER_INBOX) ||
                ((g_srv_mark_several_cntx->msg_box_type & MMA_FOLDER_OUTBOX) == MMA_FOLDER_OUTBOX) ||
                (g_srv_mark_several_cntx->msg_box_type == MMA_FOLDER_ARCHIVE))

            {
                /* Call BGSR to Inform that the following messages needs to be deleted */
                MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_MARK_SEVERAL_READ_MSG_PROPERTY_ACTION_DELETE, bgsr_folder_id);
                srv_mms_bgsr_multi_change_msg_notify(
                    g_srv_mark_several_cntx->msg_id,
                    g_srv_mark_several_cntx->msg_number,
                    SRV_MMS_BGSR_OP_MULTI_DELETE,
                    (srv_mms_bgsr_msg_box_enum)bgsr_folder_id,
                    srv_mms_bgsr_multi_delete_msg_notify_callback);
            }
            else
            {

                if (1 == g_srv_mark_several_cntx->msg_number)
                {
                    U8 error = 0;
                    U8 srv_result = 0;

                    srv_result = srv_mms_delete_msg(g_srv_mark_several_cntx->msg_id[0], &error);

                    if (srv_result == SRV_MMS_RESULT_OK)
                    {
                        U32 i = 0, j = 0;

                        srv_mms_show_status_icon();
                        memset(g_srv_mark_several_cntx->updated_msg_id, 0, SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP);

                        g_srv_mark_several_cntx->updated_msg_id[i] = g_srv_mark_several_cntx->msg_id[0];
                        g_srv_mark_several_cntx->action_result[i] = (kal_bool)error;
                        i++;

                        /* Append the not added list with value as FALSE */
                        for (j = 0; j < g_srv_mark_several_cntx->not_added_count; j++)
                        {
                            g_srv_mark_several_cntx->updated_msg_id[i] = g_srv_mark_several_cntx->not_added_msg_id[j];
                            g_srv_mark_several_cntx->action_result[i] = KAL_FALSE;
                            i++;
                        }

                        /* Send this structure to UM */
                        srv_mms_send_multi_delete_rsp_to_um();
                    }

                }
                else
                {
                    srv_mms_delete_req_struct req;
                    U16 index = 0;

                    req.user_data = 0;
                    req.call_back = srv_mms_mark_several_delete_rsp;
                    req.no_of_msg = g_srv_mark_several_cntx->msg_number;
                    req.box = g_srv_mark_several_cntx->msg_box_type;
                    req.app_id = MMA_APP_ID_MMS_APP_MARK_SEVERAL;

                    for (index = 0; index < g_srv_mark_several_cntx->msg_number; index++)
                    {
                        req.msg_id[index] = g_srv_mark_several_cntx->msg_id[index];
                    }

                    srv_mms_delete(&req);
                }
            }
            break;
        case SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_ARCHIVE:
            /* Call BGSR to Inform that the following messages needs to be Moved to Archive */
            if ((g_srv_mark_several_cntx->msg_box_type & MMA_FOLDER_INBOX == MMA_FOLDER_INBOX) ||
                (g_srv_mark_several_cntx->msg_box_type & MMA_FOLDER_OUTBOX == MMA_FOLDER_OUTBOX))
            {

                for (i = 0; i < g_srv_mark_several_cntx->msg_number; i++)
                {
                    if ((g_srv_mark_several_cntx->msg_type[i] == MMA_MSG_TYPE_MMS) &&
                        (mma_get_box(g_srv_mark_several_cntx->msg_id[i]) != MMA_FOLDER_OUTBOX))
                    {
                        g_srv_mark_several_cntx->updated_msg_id[count] = g_srv_mark_several_cntx->msg_id[i];
                        count++;
                    }
                    else
                    {
                        g_srv_mark_several_cntx->not_added_msg_id[g_srv_mark_several_cntx->not_added_count] =
                            g_srv_mark_several_cntx->msg_id[i];
                        g_srv_mark_several_cntx->not_added_count++;

                    }
                }

                num = g_srv_mark_several_cntx->msg_number - g_srv_mark_several_cntx->not_added_count;
                if (num == 0)
                {
                    srv_mms_send_multi_move_rsp_to_um();
                    return;
                }
                srv_mms_bgsr_multi_change_msg_notify(
                    g_srv_mark_several_cntx->updated_msg_id,
                    num,
                    SRV_MMS_BGSR_OP_MULTI_MOVE,
                    (srv_mms_bgsr_msg_box_enum)bgsr_folder_id,
                    srv_mms_bgsr_multi_move_msg_notify_callback);
            }
            else
            {
                if (1 == g_srv_mark_several_cntx->msg_number)
                {
                    U8 error = 0;
                    U8 srv_result = 0;
                    U16 index1 = 0;
                    U16 index2 = 0;

                    srv_result = srv_mms_save_msg(g_srv_mark_several_cntx->msg_id[0], MMA_FOLDER_ARCHIVE, &error);

                    if (srv_result == SRV_MMS_RESULT_OK)
                    {
                        srv_mms_show_status_icon();

                        memset(g_srv_mark_several_cntx->updated_msg_id, 0, SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP);

                        g_srv_mark_several_cntx->updated_msg_id[0] = g_srv_mark_several_cntx->msg_id[0];
                        g_srv_mark_several_cntx->action_result[0] = (kal_bool)error;

                        index1 = 1;
                        /* Append the not added list with value as FALSE */
                        for (index2 = 0; index2 < g_srv_mark_several_cntx->not_added_count; index2++)
                        {
                            g_srv_mark_several_cntx->updated_msg_id[index1] =
                                g_srv_mark_several_cntx->not_added_msg_id[index2];
                            g_srv_mark_several_cntx->action_result[index1] = KAL_FALSE;
                            index1++;
                        }
                        srv_mms_send_multi_move_rsp_to_um();
                    }
                }
                else
                {
                    srv_mms_save_req_struct save;
                    U16 index = 0;

                    save.user_data = 0;
                    save.call_back = srv_mms_mark_several_multi_move_rsp;
                    save.no_of_msg = g_srv_mark_several_cntx->msg_number;
                    save.box = MMA_FOLDER_ARCHIVE;
                    save.app_id = MMA_APP_ID_MMS_APP_MARK_SEVERAL;
                    for (index = 0; index < g_srv_mark_several_cntx->msg_number; index++)
                    {
                        save.msg_id[index] = g_srv_mark_several_cntx->msg_id[index];
                    }
                    srv_mms_save(&save);
                }
            }
            break;
        #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
        case SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_PHONE:
            while (g_srv_mark_several_cntx->curr_index < g_srv_mark_several_cntx->msg_number)
            {
                if (g_srv_mark_several_cntx->msg_type[g_srv_mark_several_cntx->curr_index] == MMA_MSG_TYPE_MMS)
                {
                    srv_mms_change_msg_storage(
                        MMA_MMS_STORAGE_ACTION_COPY_MMS,
                        MMA_MSG_STORAGE_CARD1,
                        g_srv_mark_several_cntx->msg_id[g_srv_mark_several_cntx->curr_index]);
                    break;
                }
                else
                {
                    g_srv_mark_several_cntx->action_result[g_srv_mark_several_cntx->curr_index] = KAL_FALSE;
                    g_srv_mark_several_cntx->curr_index++;
                }
            }
            if (g_srv_mark_several_cntx->msg_number == g_srv_mark_several_cntx->curr_index)
            {
                srv_mms_get_msg_change_storage_rsp_send_to_um();
            }
            break;
        case SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_MEMORY_CARD:
            while (g_srv_mark_several_cntx->curr_index < g_srv_mark_several_cntx->msg_number)
            {
                if (g_srv_mark_several_cntx->msg_type[g_srv_mark_several_cntx->curr_index] == MMA_MSG_TYPE_MMS)
                {
                    srv_mms_change_msg_storage(
                        MMA_MMS_STORAGE_ACTION_COPY_MMS,
                        MMA_MSG_STORAGE_PHONE,
                        g_srv_mark_several_cntx->msg_id[g_srv_mark_several_cntx->curr_index]);
                    break;
                }
                else
                {
                    g_srv_mark_several_cntx->action_result[g_srv_mark_several_cntx->curr_index] = KAL_FALSE;
                    g_srv_mark_several_cntx->curr_index++;
                }
            }
            if (g_srv_mark_several_cntx->msg_number == g_srv_mark_several_cntx->curr_index)
            {
                srv_mms_get_msg_change_storage_rsp_send_to_um();
            }
            break;

        #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
#ifdef __MMI_MMS_COPY_TO_ARCHIVE_SUPPORT__
        case SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_ARCHIVE:
        {
            srv_mms_copy_to_archive_req_struct req;

            while (g_srv_mark_several_cntx->curr_index < g_srv_mark_several_cntx->msg_number)
            {
                mma_folder_enum folder_id = mma_get_box(g_srv_mark_several_cntx->msg_id[g_srv_mark_several_cntx->curr_index]);
                if ((g_srv_mark_several_cntx->msg_type[g_srv_mark_several_cntx->curr_index] == MMA_MSG_TYPE_MMS) &&
                    ((folder_id == MMA_FOLDER_INBOX) || (folder_id == MMA_FOLDER_SENT)))
                {
                    memset(&req, 0, sizeof(srv_mms_copy_to_archive_req_struct));
                    req.user_data = 0;
                    req.call_back = srv_mms_multi_copy_to_archive_rsp_hdlr;
                    req.msg_id = g_srv_mark_several_cntx->msg_id[g_srv_mark_several_cntx->curr_index];
                    req.app_id = MMA_APP_ID_MMS_APP;
                    srv_mms_copy_to_archive(&req);
                    break;
                }
                else
                {
                    g_srv_mark_several_cntx->action_result[g_srv_mark_several_cntx->curr_index] = MMA_RESULT_FAIL;
                    g_srv_mark_several_cntx->curr_index++;
                }
            }
            if (g_srv_mark_several_cntx->msg_number == g_srv_mark_several_cntx->curr_index)
            {
                srv_mms_get_msg_change_storage_rsp_send_to_um();
            }
        }
            break;
#endif
    }
}

#ifdef __MMI_MMS_COPY_TO_ARCHIVE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_mms_multi_copy_to_archive_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  rsp_data        [?]         
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_multi_copy_to_archive_rsp_hdlr(srv_mms_result_enum result, void *rsp_data, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_copy_to_archive_rsp_struct *msgrsp = (srv_mms_copy_to_archive_rsp_struct*) rsp_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_mark_several_cntx->action_result[g_srv_mark_several_cntx->curr_index] = msgrsp->result;

    if ((g_srv_mark_several_cntx->msg_number - 1) <= g_srv_mark_several_cntx->curr_index)
    {
        srv_mms_get_msg_change_storage_rsp_send_to_um();
    }
    else
    {

        srv_mms_copy_to_archive_req_struct req;

        g_srv_mark_several_cntx->curr_index++;

        while (g_srv_mark_several_cntx->curr_index < g_srv_mark_several_cntx->msg_number)
        {
            mma_folder_enum folder_id = mma_get_box(g_srv_mark_several_cntx->msg_id[g_srv_mark_several_cntx->curr_index]);
            if ((g_srv_mark_several_cntx->msg_type[g_srv_mark_several_cntx->curr_index] == MMA_MSG_TYPE_MMS) &&
                ((folder_id == MMA_FOLDER_INBOX) || (folder_id == MMA_FOLDER_SENT)))
            {
                memset(&req, 0, sizeof(srv_mms_copy_to_archive_req_struct));
                req.user_data = 0;
                req.call_back = srv_mms_multi_copy_to_archive_rsp_hdlr;
                req.msg_id = g_srv_mark_several_cntx->msg_id[g_srv_mark_several_cntx->curr_index];
                req.app_id = MMA_APP_ID_MMS_APP;
                srv_mms_copy_to_archive(&req);
                break;
            }
            else
            {
                g_srv_mark_several_cntx->action_result[g_srv_mark_several_cntx->curr_index] = MMA_RESULT_FAIL;
                g_srv_mark_several_cntx->curr_index++;
            }

        }
        if (g_srv_mark_several_cntx->msg_number == g_srv_mark_several_cntx->curr_index)
        {
            srv_mms_get_msg_change_storage_rsp_send_to_um();
        }

    }
}
#endif
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_msg_change_storage_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgrsp      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_get_msg_change_storage_rsp_hdlr(wap_mma_change_msg_storage_rsp_struct *msgrsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_mark_several_cntx->action_result[g_srv_mark_several_cntx->curr_index] = (kal_bool)msgrsp->result;
    if ((g_srv_mark_several_cntx->msg_number - 1) <= g_srv_mark_several_cntx->curr_index)
    {
        srv_mms_get_msg_change_storage_rsp_send_to_um();
    }
    else
    {
        g_srv_mark_several_cntx->curr_index++;
        while (g_srv_mark_several_cntx->curr_index < g_srv_mark_several_cntx->msg_number)
        {
            if (g_srv_mark_several_cntx->msg_type[g_srv_mark_several_cntx->curr_index] == MMA_MSG_TYPE_MMS)
            {
                if (g_srv_mark_several_cntx->action_type == SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_PHONE)
                {
                    srv_mms_change_msg_storage(
                        MMA_MMS_STORAGE_ACTION_COPY_MMS,
                        MMA_MSG_STORAGE_CARD1,
                        g_srv_mark_several_cntx->msg_id[g_srv_mark_several_cntx->curr_index]);
                }
                else if (g_srv_mark_several_cntx->action_type == SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_MEMORY_CARD)
                {
                    srv_mms_change_msg_storage(
                        MMA_MMS_STORAGE_ACTION_COPY_MMS,
                        MMA_MSG_STORAGE_PHONE,
                        g_srv_mark_several_cntx->msg_id[g_srv_mark_several_cntx->curr_index]);
                }
                break;
            }
            else
            {
                g_srv_mark_several_cntx->action_result[g_srv_mark_several_cntx->curr_index] = KAL_FALSE;
                g_srv_mark_several_cntx->curr_index++;
            }
        }
        if (g_srv_mark_several_cntx->msg_number == g_srv_mark_several_cntx->curr_index)
        {
            srv_mms_get_msg_change_storage_rsp_send_to_um();
        }

    }

}

#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 

 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_msg_change_storage_rsp_send_to_um
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  void          [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_get_msg_change_storage_rsp_send_to_um(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_multi_op_send_rsp_struct msg_rsp;
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_show_status_icon();

    msg_rsp.msg_type = SRV_UM_MSG_MMS;
    msg_rsp.app_id = MMA_APP_ID_UM;
    msg_rsp.msg_box_type = srv_mms_convert_mma_folder_to_umbox_type(g_srv_mark_several_cntx->msg_box_type);
    msg_rsp.action_type = g_srv_mark_several_cntx->action_type;
    msg_rsp.msg_number = g_srv_mark_several_cntx->msg_number;
    for (i = 0; i < g_srv_mark_several_cntx->msg_number; i++)
    {
        msg_rsp.msg_id[i] = g_srv_mark_several_cntx->msg_id[i];
        if (g_srv_mark_several_cntx->action_result[i] == MMA_RESULT_OK)
        {
            msg_rsp.action_result[i] = MMI_TRUE;
        }
        else
        {
            msg_rsp.action_result[i] = MMI_FALSE;
        }
    }
    srv_mms_multi_op_send_rsp((void*)&msg_rsp);
    memset(g_srv_mark_several_cntx, 0, sizeof(srv_mms_mark_several_struct));
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mark_several_multi_move_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  msgrsp          [?]         [?]
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_mark_several_multi_move_rsp(srv_mms_result_enum result, void *msgrsp, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_save_rsp_struct *msg_rsp = (srv_mms_save_rsp_struct*) msgrsp;

    /* srv_um_mark_several_op_rsp_struct *multi_msg_rsp = NULL; */
    U16 index1 = 0;
    U16 index2 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_show_status_icon();

    memset(g_srv_mark_several_cntx->updated_msg_id, 0, SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP);
    for (index1 = 0; index1 < msg_rsp->no_of_msg; index1++)
    {
        g_srv_mark_several_cntx->updated_msg_id[index1] = msg_rsp->msg_id[index1];
        g_srv_mark_several_cntx->action_result[index1] = (kal_bool)msg_rsp->result[index1];

    }
    /* Append the not added list with value as FALSE */
    for (index2 = 0; index2 < g_srv_mark_several_cntx->not_added_count; index2++)
    {
        g_srv_mark_several_cntx->updated_msg_id[index1] = g_srv_mark_several_cntx->not_added_msg_id[index2];
        g_srv_mark_several_cntx->action_result[index1] = KAL_FALSE;
        index1++;
    }

    srv_mms_send_multi_move_rsp_to_um();
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mark_several_delete_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  msgrsp          [?]         [?]
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_mark_several_delete_rsp(srv_mms_result_enum result, void *msgrsp, void *user_data)
{
    srv_mms_delete_rsp_struct *msg_rsp = (srv_mms_delete_rsp_struct*) msgrsp;

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_show_status_icon();
    memset(g_srv_mark_several_cntx->updated_msg_id, 0, SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP);
    for (i = 0; i < msg_rsp->no_of_msg; i++)
    {
        g_srv_mark_several_cntx->updated_msg_id[i] = msg_rsp->msg_id[i];
        g_srv_mark_several_cntx->action_result[i] = (kal_bool)msg_rsp->result[i];
    }
    /* Append the not added list with value as FALSE */
    for (j = 0; j < g_srv_mark_several_cntx->not_added_count; j++)
    {
        g_srv_mark_several_cntx->updated_msg_id[i] = g_srv_mark_several_cntx->not_added_msg_id[j];
        g_srv_mark_several_cntx->action_result[i] = KAL_FALSE;
        i++;
    }

    /* Send this structure to UM */
    srv_mms_send_multi_delete_rsp_to_um();
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_send_multi_delete_rsp_to_um
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_send_multi_delete_rsp_to_um(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_multi_op_send_rsp_struct send_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_set_values_for_multi_delete_to_um(&send_rsp);
    srv_mms_multi_op_send_rsp((void*)&send_rsp);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_send_multi_move_rsp_to_um
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_send_multi_move_rsp_to_um(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_multi_op_send_rsp_struct send_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_set_values_for_multi_move_to_um(&send_rsp);
    srv_mms_multi_op_send_rsp((void*)&send_rsp);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_values_for_multi_delete_to_um
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_rsp     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_values_for_multi_delete_to_um(srv_mms_multi_op_send_rsp_struct *msg_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_MARK_SEVERAL_DELETE_RSP_TO_UM, msg_rsp->msg_box_type);
    msg_rsp->msg_type = SRV_UM_MSG_MMS;
    msg_rsp->app_id = MMA_APP_ID_UM;
    msg_rsp->msg_box_type = srv_mms_convert_mma_folder_to_umbox_type(g_srv_mark_several_cntx->msg_box_type);
    msg_rsp->action_type = g_srv_mark_several_cntx->action_type;
    msg_rsp->msg_number = g_srv_mark_several_cntx->msg_number;
    for (i = 0; i < g_srv_mark_several_cntx->msg_number; i++)
    {
        msg_rsp->msg_id[i] = g_srv_mark_several_cntx->updated_msg_id[i];
        if (g_srv_mark_several_cntx->action_result[i] == MMA_RESULT_OK)
        {
            msg_rsp->action_result[i] = MMI_TRUE;
        }
        else
        {
            if (g_srv_mark_several_cntx->action_result[i] == MMA_RESULT_FAIL_INVALID_MSGID)
            {
                msg_rsp->action_result[i] = MMI_TRUE;
            }
            else
            {
                msg_rsp->action_result[i] = MMI_FALSE;
            }

        }
    }
    memset(g_srv_mark_several_cntx, 0, sizeof(srv_mms_mark_several_struct));
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_values_for_multi_move_to_um
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_rsp     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_values_for_multi_move_to_um(srv_mms_multi_op_send_rsp_struct *msg_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_rsp->msg_type = SRV_UM_MSG_MMS;
    msg_rsp->app_id = MMA_APP_ID_UM;
    msg_rsp->msg_box_type = srv_mms_convert_mma_folder_to_umbox_type(g_srv_mark_several_cntx->msg_box_type);
    msg_rsp->action_type = g_srv_mark_several_cntx->action_type;
    msg_rsp->msg_number = g_srv_mark_several_cntx->msg_number;
    if ((g_srv_mark_several_cntx->msg_box_type == MMA_FOLDER_OUTBOX)
        || (g_srv_mark_several_cntx->msg_number == g_srv_mark_several_cntx->not_added_count))
    {
        for (i = 0; i < g_srv_mark_several_cntx->msg_number; i++)
        {
            msg_rsp->msg_id[i] = g_srv_mark_several_cntx->msg_id[i];
            msg_rsp->action_result[i] = MMI_FALSE;
        }
    }
    else
    {
        for (i = 0; i < g_srv_mark_several_cntx->msg_number; i++)
        {
            msg_rsp->msg_id[i] = g_srv_mark_several_cntx->updated_msg_id[i];
            if (g_srv_mark_several_cntx->action_result[i] == MMA_RESULT_OK)
            {
                msg_rsp->action_result[i] = MMI_TRUE;
            }
            else
            {
                msg_rsp->action_result[i] = MMI_FALSE;
            }
        }
    }
    memset(g_srv_mark_several_cntx, 0, sizeof(srv_mms_mark_several_struct));
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_multi_delete_msg_notify_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result_array        [?]     [?]
 *  result_array[](?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_multi_delete_msg_notify_callback(MMI_BOOL result_array[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0, k = 0, j = 0;
    U32 count = 0;
    srv_mms_delete_req_struct req;
    U16 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_srv_mark_several_cntx->msg_number; i++)
    {
        if (result_array[i] == MMI_TRUE)
        {
            g_srv_mark_several_cntx->updated_msg_id[count] = g_srv_mark_several_cntx->msg_id[i];
            count++;
        }
        else
        {
            g_srv_mark_several_cntx->not_added_count++;
            g_srv_mark_several_cntx->not_added_msg_id[k] = g_srv_mark_several_cntx->msg_id[i];
            k++;
        }

    }
    if (count == 0)
    {
        for (j = 0; j < k; j++)
        {
            g_srv_mark_several_cntx->updated_msg_id[j] = g_srv_mark_several_cntx->not_added_msg_id[j];
            g_srv_mark_several_cntx->action_result[j] = KAL_FALSE;
        }
        srv_mms_send_multi_delete_rsp_to_um();
        return;
    }
    /* After the updated list is prepared send this to MMA for Delete Operation */
    if (1 == count)
    {
        U8 error = 0;
        U8 srv_result = 0;
        U32 msg_id = g_srv_mark_several_cntx->updated_msg_id[0];

        srv_result = srv_mms_delete_msg(msg_id, &error);

        if (srv_result == SRV_MMS_RESULT_OK)
        {
            U32 i = 0, j = 0;

            srv_mms_show_status_icon();
            memset(g_srv_mark_several_cntx->updated_msg_id, 0, SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP);

            g_srv_mark_several_cntx->updated_msg_id[i] = msg_id;
            g_srv_mark_several_cntx->action_result[i] = (kal_bool)error;
            i++;

            /* Append the not added list with value as FALSE */
            for (j = 0; j < g_srv_mark_several_cntx->not_added_count; j++)
            {
                g_srv_mark_several_cntx->updated_msg_id[i] = g_srv_mark_several_cntx->not_added_msg_id[j];
                g_srv_mark_several_cntx->action_result[i] = KAL_FALSE;
                i++;
            }

            /* Send this structure to UM */
            srv_mms_send_multi_delete_rsp_to_um();
        }

    }
    else
    {
        req.user_data = 0;
        req.call_back = srv_mms_mark_several_delete_rsp;
        req.no_of_msg = count;
        req.box = g_srv_mark_several_cntx->msg_box_type;
        req.app_id = MMA_APP_ID_MMS_APP_MARK_SEVERAL;

        for (index = 0; index < count; index++)
        {
            req.msg_id[index] = g_srv_mark_several_cntx->updated_msg_id[index];
        }

        srv_mms_delete(&req);
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_multi_move_msg_notify_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result_array        [?]     [?]
 *  result_array[](?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_multi_move_msg_notify_callback(MMI_BOOL result_array[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U32 count = 0;
    U32 temp_msg_id[SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP];
    U32 num = 0;
    srv_mms_save_req_struct save;
    U16 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    num = g_srv_mark_several_cntx->msg_number - g_srv_mark_several_cntx->not_added_count;

    for (i = 0; i < num; i++)
    {
        temp_msg_id[i] = g_srv_mark_several_cntx->updated_msg_id[i];
        g_srv_mark_several_cntx->updated_msg_id[i] = 0;
    }
    /* Remove the MSg_id whose result is False as returned from BGSR and whose Msg_type is Notification, Read/Delivery Report and which is not Read */
    for (i = 0; i < num; i++)
    {
        if (result_array[i] == MMI_TRUE)
        {
            g_srv_mark_several_cntx->updated_msg_id[count] = temp_msg_id[i];
            count++;
        }
        else
        {
            g_srv_mark_several_cntx->not_added_msg_id[g_srv_mark_several_cntx->not_added_count] = temp_msg_id[i];
            g_srv_mark_several_cntx->not_added_count++;
        }
    }
    /* After the updated list is prepared send this to MMA for Delete Operation */
    if (count == 0)
    {
        srv_mms_send_multi_move_rsp_to_um();
        return;
    }
    if (1 == count)
    {
        U8 error = 0;
        U8 srv_result = 0;
        U16 index1 = 0;
        U16 index2 = 0;
        U32 msg_id = g_srv_mark_several_cntx->updated_msg_id[0];

        srv_result = srv_mms_save_msg(msg_id, MMA_FOLDER_ARCHIVE, &error);

        if (srv_result == SRV_MMS_RESULT_OK)
        {
            srv_mms_show_status_icon();

            memset(g_srv_mark_several_cntx->updated_msg_id, 0, SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP);

            g_srv_mark_several_cntx->updated_msg_id[0] = msg_id;
            g_srv_mark_several_cntx->action_result[0] = (kal_bool)error;

            index1 = 1;
            /* Append the not added list with value as FALSE */
            for (index2 = 0; index2 < g_srv_mark_several_cntx->not_added_count; index2++)
            {
                g_srv_mark_several_cntx->updated_msg_id[index1] = g_srv_mark_several_cntx->not_added_msg_id[index2];
                g_srv_mark_several_cntx->action_result[index1] = KAL_FALSE;
                index1++;
            }
            srv_mms_send_multi_move_rsp_to_um();
        }
    }
    else
    {
        save.user_data = 0;
        save.call_back = srv_mms_mark_several_multi_move_rsp;
        save.no_of_msg = count;
        save.box = MMA_FOLDER_ARCHIVE;
        save.app_id = MMA_APP_ID_MMS_APP_MARK_SEVERAL;
        for (index = 0; index < count; index++)
        {
            save.msg_id[index] = g_srv_mark_several_cntx->updated_msg_id[index];
        }
        srv_mms_save(&save);
    }
}

#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */ /* mark several */


/*****************************************************************************
 * FUNCTION
 *  srv_mms_entry_new_mms_hndlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id              [IN]        
 *  folder_id           [IN]        
 *  msg_media_type      [IN]        
 *  sim_id              [IN]        
 *  tone_id(?)          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_entry_new_mms_hndlr(
        const U32 msg_id,
        const kal_uint16 folder_id,
        kal_uint8 msg_media_type,
        kal_uint8 sim_id)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_mma_get_msg_info_req_struct msg_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(MMI_MAX_SIM_NUM >= 2)
    if ((U8) MMA_SIM_ID_SIM2 == sim_id)
    {
        g_srv_new_msg_cntx->tone_id = SRV_PROF_TONE_MMS_CARD2;
    }
    else
#endif /* (MMI_MAX_SIM_NUM >= 2) */ /* MMI_MAX_SIM_NUM == 2 */
#if(MMI_MAX_SIM_NUM >= 3)
    if ((U8) MMA_SIM_ID_SIM3 == sim_id)
    {
        g_srv_new_msg_cntx->tone_id = SRV_PROF_TONE_MMS_CARD3;
    }
    else
#endif /* (MMI_MAX_SIM_NUM >= 3) */ /* MMI_MAX_SIM_NUM == 3 */
#if(MMI_MAX_SIM_NUM >= 4)
    if ((U8) MMA_SIM_ID_SIM4 == sim_id)
    {
        g_srv_new_msg_cntx->tone_id = SRV_PROF_TONE_MMS_CARD4;
    }
    else
#endif /* (MMI_MAX_SIM_NUM >= 4) */ /* MMI_MAX_SIM_NUM == 4 */

    {
        g_srv_new_msg_cntx->tone_id = MMS_TONE;
    }
#ifdef __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__ */ 

    //srv_mms_update_status_icon_indicator();
    // update home screen data from below data

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    if (mmi_umms_app_core_get_hs32_active() == MMI_TRUE)
    {
        mmi_umms_app_core_set_hs32_new_mms_arrived(MMI_TRUE);
    }
#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */ /* defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__) */

#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
    if ((srv_mms_get_hs_event() == MMI_TRUE) || (srv_mms_get_hs_active() == MMI_TRUE))
    {
        MMI_BOOL result = MMI_TRUE;

        srv_mms_send_events(EVT_ID_SRV_NEW_MMS, (void*)&result);
    }
#endif /* defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__) */ 

    memset(&msg_req, 0, sizeof(srv_mms_mma_get_msg_info_req_struct));
    msg_req.msg_id = msg_id;
    msg_req.user_data = 0;
    msg_req.call_back = (srv_mms_funcptr_type) srv_mms_new_msg_info_cb;
    msg_req.app_id = MMA_APP_ID_MMS_APP_NMGR;
    srv_mms_mma_get_msg_info(&msg_req);

    return;
}

#if defined(__MMI_MMS_REPORT_BOX_SUPPORT__) || defined(__MMI_MMS_REPORT_STATUS_SUPPORT__)


/*****************************************************************************
 * FUNCTION
 *  srv_mms_entry_new_report_hndlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  notify_event        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_entry_new_report_hndlr(wap_mma_event_new_msg_struct *notify_event)
{
#ifndef __COSMOS_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_event_notify_enum evt_type;

    srv_um_refresh_ind_struct *um_refresh_ind = NULL;

    srv_um_msg_box_enum curr_msg_box = SRV_UM_MSG_BOX_NONE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_new_msg_cntx->msg_type = notify_event->msg_type;

#if(MMI_MAX_SIM_NUM >= 2)
    if ((U8) MMA_SIM_ID_SIM2 == notify_event->sim_id)
    {
        g_srv_new_msg_cntx->tone_id_for_report = SRV_PROF_TONE_MMS_CARD2;
    }
    else
#endif /* (MMI_MAX_SIM_NUM >= 2) */ /* MMI_MAX_SIM_NUM == 2 */
#if(MMI_MAX_SIM_NUM >= 3)
    if ((U8) MMA_SIM_ID_SIM3 == notify_event->sim_id)
    {
        g_srv_new_msg_cntx->tone_id_for_report = SRV_PROF_TONE_MMS_CARD3;
    }
    else
#endif /* (MMI_MAX_SIM_NUM >= 3) */ /* MMI_MAX_SIM_NUM == 3 */
#if(MMI_MAX_SIM_NUM >= 4)
    if ((U8) MMA_SIM_ID_SIM4 == notify_event->sim_id)
    {
        g_srv_new_msg_cntx->tone_id_for_report = SRV_PROF_TONE_MMS_CARD4;
    }
    else
#endif /* (MMI_MAX_SIM_NUM >= 4) */ /* MMI_MAX_SIM_NUM ==4 */

    {
        g_srv_new_msg_cntx->tone_id_for_report = MMS_TONE;
    }

    srv_mms_inform_um_about_new_msg_ind(notify_event->msg_id, notify_event->date, 0, notify_event->sim_id);

    /* srv_mms_um_refresh_ind(MMA_FOLDER_REPORT_BOX); */

    um_refresh_ind =
        (srv_um_refresh_ind_struct*) construct_local_para((kal_uint16) sizeof(srv_um_refresh_ind_struct), 0);
    um_refresh_ind->msg_type = SRV_UM_MSG_MMS;
    um_refresh_ind->msg_box_type = SRV_UM_MSG_BOX_REPORT;

    srv_mms_send_message(MOD_MMI, MOD_MMI, 0, MSG_ID_MMI_UM_REFRESH_IND, (oslParaType*) um_refresh_ind, NULL);

    g_srv_new_msg_cntx->sim_id_for_new_report = notify_event->sim_id;
    g_srv_new_msg_cntx->from_address_type = notify_event->from_address_type;
    memset(g_srv_new_msg_cntx->from_address, 0, MMA_MAX_ADDR_LEN * 2);
    mmi_ucs2ncpy((S8*) g_srv_new_msg_cntx->from_address, (S8*) notify_event->from_address, MMA_MAX_ADDR_LEN);

    /* Please review event type carefully! Since it determine the tone id configured in custom_events_notify.c! */
    switch (notify_event->sim_id)
    {
        case MMI_SIM1:
            evt_type = MMI_EVENT_SIM1_MMS;
            break;
        case MMI_SIM2:
            evt_type = MMI_EVENT_SIM2_MMS;
            break;
        case MMI_SIM3:
            evt_type = MMI_EVENT_SIM3_MMS;
            break;
        case MMI_SIM4:
            evt_type = MMI_EVENT_SIM4_MMS;
            break;
        default:
            evt_type = MMI_EVENT_MMS;
            break;
    }
#ifdef __PLUTO_MMI_PACKAGE__
    mmi_frm_nmgr_notify_by_idle(MMI_SCENARIO_ID_NEW_MMS_REPORT, evt_type, NULL);
#endif 

    srv_mms_send_events_ex(EVT_ID_SRV_MMS_GET_CURR_MSG_BOX, (void *)&curr_msg_box);

    if (SRV_UM_MSG_BOX_REPORT == (SRV_UM_MSG_BOX_REPORT & curr_msg_box))
    {
        g_srv_new_msg_cntx->is_new_report = MMI_FALSE;
    }
    else
    {
        g_srv_new_msg_cntx->is_new_report = MMI_TRUE;
    }
#else /* __COSMOS_MMI_PACKAGE__ */ 

    S16 temp[60];
    S8 name[MMA_MAX_ADDR_LEN + 40];
    S8 buffer2[MMA_MAX_ADDR_LEN + 40];
    mmi_frm_notification_para_struct noti;
    MMI_BOOL show_preview = MMI_FALSE;

    U8 result = MMA_RESULT_OK;

    memset(temp, 0, 60 * 2);
    memset(name, 0, (MMA_MAX_ADDR_LEN + 40));
    memset(buffer2, 0, (MMA_MAX_ADDR_LEN + 40));
    noti.option = 0;
    noti.text = temp;

    if (notify_event->msg_type == MMA_MSG_TYPE_READ_REPORT)
    {
        switch (notify_event->report_status)
        {
            case MMA_RR_STATUS_READ:
                mmi_ucs2cpy((S8*) temp, (S8*) GetString(STR_ID_UMMS_STATUS_READ_BY));
                mmi_ucs2cat((S8*) temp, (S8*) (const S8*)L" ");
                show_preview = MMI_TRUE;
                break;
            case MMA_RR_STATUS_DELETED_NO_READ:
                break;
        }
    }
    else if (notify_event->msg_type == MMA_MSG_TYPE_DELIVERY_REPORT)
    {
        switch (notify_event->report_status)
        {
            case MMA_DR_STATUS_RETRIEVED:
                mmi_ucs2cpy((S8*) temp, (S8*) GetString(STR_ID_UMMS_STATUS_DELIVERED_TO));
                mmi_ucs2cat((S8*) temp, (S8*) (const S8*)L" ");
                show_preview = MMI_TRUE;
                break;
            case MMA_DR_STATUS_FORWARDED:
                mmi_ucs2cpy((S8*) temp, (S8*) GetString(STR_ID_UMMS_STATUS_DELIVERED_TO));
                mmi_ucs2cat((S8*) temp, (S8*) (const S8*)L" ");
                show_preview = MMI_TRUE;
                break;
            case MMA_DR_STATUS_DEFERRED:
                break;
            case MMA_DR_STATUS_EXPIRED:
                mmi_ucs2cpy((S8*) temp, (S8*) GetString(STR_ID_UMMS_STATUS_FAILED_TO_DELIVER_TO));
                mmi_ucs2cat((S8*) temp, (S8*) (const S8*)L" ");
                show_preview = MMI_TRUE;
                break;
            case MMA_DR_STATUS_REJECTED:
                mmi_ucs2cpy((S8*) temp, (S8*) GetString(STR_ID_UMMS_STATUS_FAILED_TO_DELIVER_TO));
                mmi_ucs2cat((S8*) temp, (S8*) (const S8*)L" ");
                show_preview = MMI_TRUE;
                break;
            case MMA_DR_STATUS_UNRECOGNISED:
                mmi_ucs2cpy((S8*) temp, (S8*) GetString(STR_ID_UMMS_STATUS_DELIVERED_TO));
                mmi_ucs2cat((S8*) temp, (S8*) (const S8*)L" ");
                show_preview = MMI_TRUE;
                break;
            case MMA_DR_STATUS_UNREACHABLE:
                mmi_ucs2cpy((S8*) temp, (S8*) GetString(STR_ID_UMMS_STATUS_FAILED_TO_DELIVER_TO));
                mmi_ucs2cat((S8*) temp, (S8*) (const S8*)L" ");
                show_preview = MMI_TRUE;
                break;
            case MMA_DR_STATUS_INDETERMINATE:
                break;
        }
    }

    if (MMI_TRUE == show_preview)
    {

        if (notify_event->from_address_type == MMA_ADDR_TYPE_PHONE_NUMBER)
        {
            MMI_BOOL is_found = srv_phb_get_name_by_number(notify_event->from_address, (U16*) name, (MMA_MAX_ADDR_LEN + 40) / 2 - 1);
            if (is_found == MMI_FALSE)
            {
                mmi_ucs2ncpy((S8*) buffer2, (S8*) notify_event->from_address, (MMA_MAX_ADDR_LEN + 40) / 2 - 1);
            }
            else
            {
                mmi_ucs2ncpy((S8*) buffer2, (S8*) name, (MMA_MAX_ADDR_LEN + 40) / 2 - 1);
            }
        }
        else
        {
            mmi_ucs2ncpy((S8*) buffer2, (S8*) notify_event->from_address, (MMA_MAX_ADDR_LEN + 40) / 2 - 1);
        }

        mmi_ucs2ncat((S8*) temp, (S8*) buffer2, 40);

        /* We will copy the string and do truncate if the string is longer than internal buffer length. */
        mmi_frm_nmgr_notify(MMI_SCENARIO_ID_NEW_MMS_REPORT, MMI_EVENT_MMS_REPORTS, &noti);

    }

#endif /* __COSMOS_MMI_PACKAGE__ */ 

}
#endif /* defined(__MMI_MMS_REPORT_BOX_SUPPORT__) || defined(__MMI_MMS_REPORT_STATUS_SUPPORT__) */ 



/*****************************************************************************
 * FUNCTION
 *  srv_mms_show_new_mms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  msgrsp          [?]         [?]
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_mms_show_new_mms(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_base_event_struct* param =  (srv_mms_base_event_struct*) evt;
    srv_mms_mma_get_msg_info_rsp_struct *msgRsp = (srv_mms_mma_get_msg_info_rsp_struct*) param->sender_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_handle_new_mms(msgRsp, msgRsp->msg_id);

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mms_new_msg_info_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  msgrsp          [?]         [?]
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_new_msg_info_cb(srv_mms_result_enum result, void *msgrsp, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_mma_get_msg_info_rsp_struct *msgRsp = (srv_mms_mma_get_msg_info_rsp_struct*) msgrsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_frm_cb_reg_event(EVT_ID_SRV_NEW_MMS_MSG,srv_mms_show_new_mms,NULL);

    srv_mms_send_events_ex(EVT_ID_SRV_NEW_MMS_MSG, (void*)msgRsp);

    mmi_frm_cb_dereg_event(EVT_ID_SRV_NEW_MMS_MSG,srv_mms_show_new_mms,NULL);

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_handle_new_mms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgRsp      [IN]        
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_handle_new_mms(const srv_mms_mma_get_msg_info_rsp_struct *msgRsp, const U32 msg_id)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_AUTO_DWNLD_IMMED_NOTI_AFTER_INTERRUPT__
    U32 current_secs_since_1970 = 0;
    U32 time = 0;
#endif /* __MMI_MMS_AUTO_DWNLD_IMMED_NOTI_AFTER_INTERRUPT__ */ 
    
    U16 from_address[MMA_MAX_ADDR_LEN];
    srv_mms_um_refresh_ind_struct refresh_data;

     srv_um_msg_box_enum curr_msg_box = SRV_UM_MSG_BOX_NONE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_inform_um_about_new_msg_ind(msgRsp->msg_id, msgRsp->received_date, msgRsp->date, msgRsp->sim_id);

    if ((msgRsp->msg_type != MMA_MSG_TYPE_READ_REPORT) && (msgRsp->msg_type != MMA_MSG_TYPE_DELIVERY_REPORT))
    {
        refresh_data.msg_box_type = MMA_FOLDER_INBOX;
        refresh_data.refresh_type = SRV_UM_REFRESH_NEW_INCOMING_MSG;
        refresh_data.msg_id = msg_id;
        refresh_data.addr_number = 1;
        refresh_data.addr_type = msgRsp->from_address_type;
        memset(refresh_data.address, 0, (SRV_UM_MAX_ADDR_LEN + 1) * 2);
        mmi_ucs2ncpy((PS8) refresh_data.address, (PS8) msgRsp->from_address, SRV_UM_MAX_ADDR_LEN);

        srv_mms_um_refresh_msg_ind(&refresh_data);
    }
    else
    {
        srv_mms_um_refresh_ind(MMA_FOLDER_INBOX);
    }

    g_srv_new_msg_cntx->sim_id_for_new_msg = msgRsp->sim_id;

    if (msgRsp->msg_type == MMA_MSG_TYPE_JAVA)
    {
    #ifdef __MMI_UMMS_JSR205__
        srv_mms_jsr_add_recv_java_mms_content(msgRsp->msg_id, (U8*) msgRsp->java_app_id);
    #endif 
    }

    memset(from_address, 0, MMA_MAX_ADDR_LEN);
    mmi_ucs2ncpy((PS8)from_address, (PS8)msgRsp->from_address, MMA_MAX_ADDR_LEN);

    srv_mms_send_events_ex(EVT_ID_SRV_MMS_NMGR_ALERT, (void *)from_address);


    srv_mms_send_events_ex(EVT_ID_SRV_MMS_GET_CURR_MSG_BOX, (void *)&curr_msg_box);
    if (SRV_UM_MSG_BOX_INBOX == (SRV_UM_MSG_BOX_INBOX & curr_msg_box))
    {
        g_srv_new_msg_cntx->is_new_msg = MMI_FALSE;
    }
    else
    {
        g_srv_new_msg_cntx->is_new_msg = MMI_TRUE;
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
#ifdef __MMI_MMS_AUTO_DWNLD_IMMED_NOTI_AFTER_INTERRUPT__
    if (msgRsp->msg_type == MMA_MSG_TYPE_NOTIFICATION)
    {
        if (srv_nw_info_is_roaming(MMI_SIM1) == FALSE)
        {
            if (MMA_RETRIEVAL_MODE_IMMED == srv_mms_retrieval_settings_home_network_retrieval_mode())
            {
                current_secs_since_1970 = umms_get_current_utc_time();
                time = msgRsp->expiry_date + msgRsp->received_date - current_secs_since_1970;
            #ifndef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
                srv_mms_bgsr_download_req_no_progressing(
                    (U8) msgRsp->sim_id,
                    (U32) msgRsp->msg_id,
                    msgRsp->storage_type);
            #else /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 
                srv_mms_bgsr_download_req_no_progressing(
                    (U8) msgRsp->sim_id,
                    (U32) msgRsp->msg_id,
                    msgRsp->storage_type);
            #endif /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 
            }
        }
    }
#endif /* __MMI_MMS_AUTO_DWNLD_IMMED_NOTI_AFTER_INTERRUPT__ */ 
#ifdef __MMI_MMS_ROAMING_NO_ACCEPT_SUPPORT__
    if (msgRsp->msg_type == MMA_MSG_TYPE_NOTIFICATION)
    {
        if (srv_nw_info_is_roaming(MMI_SIM1) == TRUE)
        {
            if ((MMA_RETRIEVAL_MODE_IMMED == srv_mms_retrieval_settings_home_network_retrieval_mode()) &&
                (MMA_RETRIEVAL_MODE_DEFERRED == srv_mms_retrieval_settings_roaming_retrieval_mode()))
            {
                srv_mms_add_to_notification_list(msgRsp);
            }
        }
    }
#endif /* __MMI_MMS_ROAMING_NO_ACCEPT_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_um_refresh_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  folder_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_um_refresh_ind(mma_folder_enum folder_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_refresh_ind_struct *um_refresh_ind = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    um_refresh_ind =
        (srv_um_refresh_ind_struct*) construct_local_para((kal_uint16) sizeof(srv_um_refresh_ind_struct), 0);
    um_refresh_ind->msg_type = SRV_UM_MSG_MMS;
    um_refresh_ind->msg_box_type = srv_mms_convert_mma_folder_to_umbox_type(folder_id);
    um_refresh_ind->refresh_type = SRV_UM_REFRESH_NONE;

    srv_mms_send_message(MOD_MMI, MOD_MMI, 0, MSG_ID_MMI_UM_REFRESH_IND, (oslParaType*) um_refresh_ind, NULL);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_inform_um_about_new_msg_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id              [IN]        
 *  received_date       [IN]        
 *  Date                [IN]        
 *  sim_id              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_inform_um_about_new_msg_ind(U32 msg_id, U32 received_date, U32 Date, U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_new_msg_ind_struct *new_msg_ind = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    new_msg_ind = (srv_um_new_msg_ind_struct*) OslConstructDataPtr(sizeof(srv_um_new_msg_ind_struct));
    new_msg_ind->msg_id = msg_id;
    if (Date == 0)
    {
        new_msg_ind->timestamp = received_date;
    }
    else
    {
        new_msg_ind->timestamp = Date;
    }

#if(MMI_MAX_SIM_NUM >= 2)
    new_msg_ind->sim_id = srv_mms_translate_mma_simid_to_um_simid(sim_id);
#endif 

    new_msg_ind->msg_type = SRV_UM_MSG_MMS;
    new_msg_ind->msg_box_type = SRV_UM_MSG_BOX_INBOX;

    if (g_srv_new_msg_cntx->tone_id)
    {
        new_msg_ind->tone_id = g_srv_new_msg_cntx->tone_id;
    }
    else
    {
    #if(MMI_MAX_SIM_NUM == 2)
        if ((U8) MMI_SIM2 == sim_id)
        {
            new_msg_ind->tone_id = CARD2_MESSAGE_TONE;
        }
        else
    #endif /* (MMI_MAX_SIM_NUM == 2) */ /* (defined(__MMI_MMS_DUAL_SIM__) || defined(__GEMINI__) || (GEMINI_PLUS > 2)) */
        {
            new_msg_ind->tone_id = MMS_TONE;
        }

    }

    srv_mms_send_message(MOD_MMI, MOD_MMI, 0, MSG_ID_MMI_UM_NEW_MSG_IND, (oslParaType*) new_msg_ind, NULL);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_get_total_number_of_messages
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_get_total_number_of_messages(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 total_num_messages = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    total_num_messages =
        g_srv_msg_num_cntx->msg_number_inbox + g_srv_msg_num_cntx->msg_number_outbox +
        g_srv_msg_num_cntx->msg_number_sent + g_srv_msg_num_cntx->msg_number_drafts +
        g_srv_msg_num_cntx->userdefined_template_msg_number + g_srv_msg_num_cntx->predefined_template_msg_number;
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    total_num_messages = total_num_messages + g_srv_msg_num_cntx->archive_msg_number;
#endif 
    return total_num_messages;
}


/*****************************************************************************
 * FUNCTION
 *  srv_get_tone_id_for_new_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_get_tone_id_for_new_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_new_msg_cntx->tone_id;
}

#ifdef __MMI_MMS_TEMPLATE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_userdef_template_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_mms_get_userdef_template_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_msg_num_cntx->userdefined_template_msg_number;
}
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_number_of_unread_messages_in_inbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_mms_get_number_of_unread_messages_in_inbox(U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 total_num_unread_messages = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(MMI_MAX_SIM_NUM >= 2)
    switch (sim_id)
    {
        case MMI_SIM1:
            total_num_unread_messages = g_srv_msg_num_cntx->total_unread_msgs_sim1;
            break;
        case MMI_SIM2:
            total_num_unread_messages = g_srv_msg_num_cntx->total_unread_msgs_sim2;
            break;
        case MMI_SIM3:
            total_num_unread_messages = g_srv_msg_num_cntx->total_unread_msgs_sim3;
            break;
        case MMI_SIM4:
            total_num_unread_messages = g_srv_msg_num_cntx->total_unread_msgs_sim4;
            break;
        default:
            MMI_ASSERT(0);
    }
#else /* (MMI_MAX_SIM_NUM >= 2) */ /* __MMI_MMS_DUAL_SIM__ */
    total_num_unread_messages = g_srv_msg_num_cntx->total_unread_msgs_sim1;
#endif /* (MMI_MAX_SIM_NUM >= 2) */ /* __MMI_MMS_DUAL_SIM__ */
    return total_num_unread_messages;
}


/*****************************************************************************
 * FUNCTION
 *  srv_update_total_number_of_messages
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_update_total_number_of_messages(const srv_mms_get_msg_num_rsp_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 loop_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    for (loop_count = 0; loop_count < MMA_MAX_MSG_NUM_QUERY_NUM; loop_count++)
    {
        switch (num_query_array[loop_count])
        {
            case UMMS_QUERY_OPTION_NUM_UNREAD_INBOX_MSG_SIM1:
                g_srv_msg_num_cntx->total_unread_msgs_sim1 = msg->rsp_tb[loop_count];
                break;
            case UMMS_QUERY_OPTION_NUM_UNREAD_INBOX_MSG_SIM2:
                g_srv_msg_num_cntx->total_unread_msgs_sim2 = msg->rsp_tb[loop_count];
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_INBOX_MSG:
                g_srv_msg_num_cntx->msg_number_inbox = msg->rsp_tb[loop_count];
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_OUTBOX_MSG:
                g_srv_msg_num_cntx->msg_number_outbox = msg->rsp_tb[loop_count];
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_SENT_MSG:
                g_srv_msg_num_cntx->msg_number_sent = msg->rsp_tb[loop_count];
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_DRAFT_MSG:
                g_srv_msg_num_cntx->msg_number_drafts = msg->rsp_tb[loop_count];
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_ARCHIVE_MSG:
        #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
                g_srv_msg_num_cntx->archive_msg_number = msg->rsp_tb[loop_count];
        #endif 
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_USER_DEF_TEMPLATE_MSG:
                g_srv_msg_num_cntx->userdefined_template_msg_number = msg->rsp_tb[loop_count];
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_PRE_DEF_TEMPLATE_MSG:
                g_srv_msg_num_cntx->predefined_template_msg_number = msg->rsp_tb[loop_count];
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_UNREAD_MSG:
                g_srv_msg_num_cntx->total_number_of_unread_msgs = msg->rsp_tb[loop_count];
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_PHONE:
                g_srv_msg_num_cntx->total_phone_msg_number = msg->rsp_tb[loop_count];
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_CARD:
                g_srv_msg_num_cntx->total_card_msg_number = msg->rsp_tb[loop_count];
                break;
            default:
                break;
        }
    }
}

/*******************amit added for  templates*******************************************/

#ifdef __MMI_MMS_TEMPLATE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_default_template_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_mms_get_default_template_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_msg_num_cntx->predefined_template_msg_number;
}
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_phone_mem_total_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_mms_get_phone_mem_total_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_msg_num_cntx->total_phone_msg_number;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_mem_card_total_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_mms_get_mem_card_total_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_msg_num_cntx->total_card_msg_number;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_reset_mem_card_total_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_reset_mem_card_total_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_msg_num_cntx->total_card_msg_number = 0;
}

/*********************amit ends for template here**********************************/


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_number_status_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_get_number_status_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_get_msg_num_req_struct req;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&req, 0, sizeof(srv_mms_get_msg_num_req_struct));

    srv_mms_fill_get_msg_num_req_struct(&req);

    req.call_back = srv_mms_status_icon_unread_rsp_hdlr;
    req.app_id = MMA_APP_ID_MMS_APP;
    srv_mms_get_msg_num(&req);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_fill_get_msg_num_req_struct
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgReq      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_fill_get_msg_num_req_struct(srv_mms_get_msg_num_req_struct *msgReq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U32 loop_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_UMMS_FILL_MSG_NUM);

    for (loop_count = 0; loop_count < MMA_MAX_MSG_NUM_QUERY_NUM; loop_count++)
    {
        switch (num_query_array[loop_count])
        {
            case UMMS_QUERY_OPTION_NUM_UNREAD_INBOX_MSG_SIM1:
                msgReq->req_tb[loop_count] = MMA_QUERY_OPTION_NUM_UNREAD_INBOX_MSG_SIM1;
                break;
        #if(MMI_MAX_SIM_NUM >= 2)
            case UMMS_QUERY_OPTION_NUM_UNREAD_INBOX_MSG_SIM2:
                msgReq->req_tb[loop_count] = MMA_QUERY_OPTION_NUM_UNREAD_INBOX_MSG_SIM2;
                break;
        #endif /* (MMI_MAX_SIM_NUM >= 2) */ 
        #if(MMI_MAX_SIM_NUM >= 3)
            case UMMS_QUERY_OPTION_NUM_UNREAD_INBOX_MSG_SIM3:
                msgReq->req_tb[loop_count] = MMA_QUERY_OPTION_NUM_UNREAD_INBOX_MSG_SIM3;
                break;
        #endif /* (MMI_MAX_SIM_NUM >= 3) */ 
        #if(MMI_MAX_SIM_NUM >= 4)
            case UMMS_QUERY_OPTION_NUM_UNREAD_INBOX_MSG_SIM4:
                msgReq->req_tb[loop_count] = MMA_QUERY_OPTION_NUM_UNREAD_INBOX_MSG_SIM4;
                break;
        #endif /* (MMI_MAX_SIM_NUM >= 4) */ 
            case UMMS_QUERY_OPTION_NUM_TOTAL_INBOX_MSG:
                msgReq->req_tb[loop_count] = MMA_QUERY_OPTION_NUM_TOTAL_INBOX_MSG;
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_OUTBOX_MSG:
                msgReq->req_tb[loop_count] = MMA_QUERY_OPTION_NUM_TOTAL_OUTBOX_MSG;
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_SENT_MSG:
                msgReq->req_tb[loop_count] = MMA_QUERY_OPTION_NUM_TOTAL_SENT_MSG;
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_DRAFT_MSG:
                msgReq->req_tb[loop_count] = MMA_QUERY_OPTION_NUM_TOTAL_DRAFT_MSG;
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_ARCHIVE_MSG:
                msgReq->req_tb[loop_count] = MMA_QUERY_OPTION_NUM_TOTAL_ARCHIVE_MSG;
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_USER_DEF_TEMPLATE_MSG:
                msgReq->req_tb[loop_count] = MMA_QUERY_OPTION_NUM_TOTAL_USER_DEF_TEMPLATE_MSG;
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_PRE_DEF_TEMPLATE_MSG:
                msgReq->req_tb[loop_count] = MMA_QUERY_OPTION_NUM_TOTAL_PRE_DEF_TEMPLATE_MSG;
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_UNREAD_MSG:
                msgReq->req_tb[loop_count] = MMA_QUERY_OPTION_NUM_TOTAL_UNREAD_MSG;
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_PHONE:
                msgReq->req_tb[loop_count] = MMA_QUERY_OPTION_NUM_TOTAL_PHONE_MSG;
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_CARD:
                msgReq->req_tb[loop_count] = MMA_QUERY_OPTION_NUM_TOTAL_CARD_MSG;
                break;
            default:
                break;
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_update_status_icon_on_number_rsp
 * DESCRIPTION
 *  Update Icon on Get number Response.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_update_status_icon_on_number_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 unread_msgs = 0;

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    U8 prefer_storage_value = 0;
#else 
    U32 total_num_messages = 0;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    prefer_storage_value = srv_mms_get_mms_prefer_storage();
    if ((prefer_storage_value == MMA_MSG_STORAGE_PHONE) &&
        (srv_mms_get_phone_mem_total_msg() >= (MAX_POSSIBLE_MESSAGES_THRESHOLD)))
    {
        srv_mms_status_icon_type_enum result = UMMS_STATUS_FULL;

        srv_mms_send_events(EVT_ID_SRV_SHOW_STATUS, (void*)&result);
    }
    else if ((prefer_storage_value == MMA_MSG_STORAGE_CARD1) &&
             (srv_mms_get_mem_card_total_msg() >= (MAX_POSSIBLE_MESSAGES_THRESHOLD)))
    {
        srv_mms_status_icon_type_enum result = UMMS_STATUS_FULL;

        srv_mms_send_events(EVT_ID_SRV_SHOW_STATUS, (void*)&result);
    }
    else
    {
#else /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    total_num_messages = srv_get_total_number_of_messages();

    if (total_num_messages >= (MAX_POSSIBLE_MESSAGES_THRESHOLD))
    {
        srv_mms_status_icon_type_enum result = UMMS_STATUS_FULL;

        srv_mms_send_events(EVT_ID_SRV_SHOW_STATUS, (void*)&result);
    }
    else
    {
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 

        unread_msgs = srv_mms_get_number_of_unread_messages_in_inbox((U8) MMI_SIM1) +
            srv_mms_get_number_of_unread_messages_in_inbox((U8) MMI_SIM2) +
            srv_mms_get_number_of_unread_messages_in_inbox((U8) MMI_SIM3) +
            srv_mms_get_number_of_unread_messages_in_inbox((U8) MMI_SIM4);

        if (unread_msgs > 0)
        {
            srv_mms_status_icon_type_enum result = UMMS_STATUS_NEW_MESSAGE;

            srv_mms_send_events(EVT_ID_SRV_SHOW_STATUS, (void*)&result);
        }
        else
        {
            srv_mms_status_icon_type_enum result = UMMS_STATUS_OFF;

            srv_mms_send_events(EVT_ID_SRV_SHOW_STATUS, (void*)&result);
        }

    }
}

#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__

/*****************************************************************************
 * FUNCTION
 *  srv_mms_nmgr_get_unread_msg_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_nmgr_get_unread_msg_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_nmgr_answer(
        MMI_NMGR_APP_MMS,           /* menu data type */
        MMI_NMGR_RESULT_NOT_READY,  /* result ok */
        NULL,                       /* array of unread SMS events */
        NULL);

    if (srv_mms_is_ready() == MMI_TRUE)
    {
        srv_mms_get_unread_msg_list_req_struct req;
        S32 result;

        memset(&req, 0, sizeof(srv_mms_get_unread_msg_list_req_struct));

        req.call_back = srv_mms_nmgr_get_unread_msg_number_rsp_for_nmgr;
        req.start_index = 0;
        req.num_of_msg_requested = 1;
        req.app_id = MMA_APP_ID_MMS_APP;
        result = srv_mms_get_unread_msg_list(&req);

        if (result != SRV_MMS_RESULT_OK)
        {
            ASSERT(0);
        }
        g_srv_new_msg_cntx->nmgr_informed = MMI_TRUE;
    }
    else
    {
        g_srv_new_msg_cntx->nmgr_informed = MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_nmgr_get_unread_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_nmgr_get_unread_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_get_unread_msg_list_req_struct req;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&req, 0, sizeof(srv_mms_get_unread_msg_list_req_struct));

    req.call_back = srv_mms_nmgr_get_unread_msg_number_rsp_for_nmgr;
    req.start_index = 0;
    req.num_of_msg_requested = 1;
    req.app_id = MMA_APP_ID_MMS_APP;
    result = srv_mms_get_unread_msg_list(&req);

    if (result != SRV_MMS_RESULT_OK)
    {
        ASSERT(0);
    }
}
#endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/


/*****************************************************************************
 * FUNCTION
 *  srv_mms_nmgr_cancel_unread_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_nmgr_cancel_unread_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_new_msg_cntx->nmgr_informed = MMI_FALSE;
    g_srv_new_msg_cntx->is_new_msg = MMI_FALSE;
}

#ifdef __MMI_MMS_ROAMING_NO_ACCEPT_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_init_notify_roaming_download_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_init_notify_roaming_download_data(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle = 0;
    FS_HANDLE file_handle1 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Read the Files from the System Folder and Create the Link List */
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_INIT_NOTIFY_DATA);
    srv_mms_generate_file_path_for_notify();
    file_handle = FS_Open((UI_string_type) g_srv_roaming_cntx->default_sys_folder_path_for_notify_path, FS_READ_ONLY);
    /* MMI_TRACE(
       MMI_INET_TRC_G6_MMS,
       MMI_UMMS_NOTIFY_DEFAULT_FOLDER_PATH,
       default_sys_folder_path_for_notify_path); */
    if (file_handle > 0)
    {
        /* FS_Open notify_list.ntf */
        mmi_ucs2cat((S8*) g_srv_roaming_cntx->default_sys_folder_path_for_notify_path, (S8*) L"\\");
        mmi_ucs2cat(
            (S8*) g_srv_roaming_cntx->default_sys_folder_path_for_notify_path,
            (S8*) SRV_MMS_FILE_NOTIFY_NAME);
        file_handle1 = FS_Open((UI_string_type) g_srv_roaming_cntx->default_sys_folder_path_for_notify_path, FS_READ_ONLY);

        if (file_handle1 > 0)
        {
            /* Read from file and Update link List */
            MMI_TRACE(
                MMI_INET_TRC_G6_MMS,
                MMI_UMMS_NOTIFY_DEFAULT_FILE_PATH,
                g_srv_roaming_cntx->default_sys_folder_path_for_notify_path);
            srv_mms_read_notify_struct_from_file(file_handle1);
            FS_Close(file_handle1);
        }
        else
        {
            /* create the file if not present */
            file_handle1 = FS_Open((UI_string_type) g_srv_roaming_cntx->default_sys_folder_path_for_notify_path, FS_CREATE);
            FS_Close(file_handle1);
        }
        FS_Close(file_handle);
    }
    else
    {
        /* create the folder if not present */
        FS_CreateDir((PU16) g_srv_roaming_cntx->default_sys_folder_path_for_notify_path);
        mmi_ucs2cat((S8*) g_srv_roaming_cntx->default_sys_folder_path_for_notify_path, (S8*) L"\\");
        mmi_ucs2cat(
            (S8*) g_srv_roaming_cntx->default_sys_folder_path_for_notify_path,
            (S8*) SRV_MMS_FILE_NOTIFY_NAME);
        file_handle1 = FS_Open((UI_string_type) g_srv_roaming_cntx->default_sys_folder_path_for_notify_path, FS_CREATE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_generate_file_path_for_notify
 * DESCRIPTION
 *  generate the folder path for notification message.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_generate_file_path_for_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 def_drive_str[SRV_MMS_DRIVE_NAME_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_GENERATE_FILE_PATH_FOR_NOTIFY);
    sprintf((S8*) def_drive_str, "%c", UMMS_MMS_DEFAULT_SYS_DRIVE);
    mmi_asc_to_ucs2((S8*) g_srv_roaming_cntx->default_sys_folder_path_for_notify_path, (S8*) def_drive_str);
    mmi_ucs2cat((S8*) g_srv_roaming_cntx->default_sys_folder_path_for_notify_path, (S8*) L":\\");
    mmi_ucs2cat(
        (S8*) g_srv_roaming_cntx->default_sys_folder_path_for_notify_path,
        (S8*) SRV_MMS_DEFAULT_NOTIFY_FOLDER_NAME);

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_read_notify_struct_from_file
 * DESCRIPTION
 *  read the notification structure
 * PARAMETERS
 *  file_handle     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_read_notify_struct_from_file(FS_HANDLE file_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 curr_pos = 0;
    U32 size = 1;
    srv_mms_roaming_notification_list *single_notify_struct = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_READ_NOTIFY_STRUCT_FROM_LIST);
    single_notify_struct =
        (srv_mms_roaming_notification_list*) srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_roaming_notification_list));
    MMI_ASSERT(single_notify_struct != NULL);
    memset(single_notify_struct, 0, sizeof(srv_mms_roaming_notification_list));
    FS_Seek(file_handle, curr_pos, FS_FILE_BEGIN);
    while (FS_Read(file_handle, single_notify_struct, sizeof(srv_mms_roaming_notification_list), &size) == FS_NO_ERROR)
    {
        if (size != 0)
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_READ_NOTIFY_STRUCT_FROM_FILE, size);
            srv_mms_add_to_list_from_file_for_roaming_notify(single_notify_struct);
        }
        else
        {
            break;
        }
        memset(single_notify_struct, 0, sizeof(srv_mms_roaming_notification_list));
    }
    srv_mms_mem_mgr_app_adm_free(single_notify_struct);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_add_to_list_from_file_for_roaming_notify
 * DESCRIPTION
 *  maintain a list for notification message after reading from file.
 * PARAMETERS
 *  inMsg       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_add_to_list_from_file_for_roaming_notify(srv_mms_roaming_notification_list *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    srv_mms_roaming_notification_list *temp1;
    srv_mms_roaming_notification_list *temp2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_ADD_TO_LIST_FROM_FILE);
    temp2 = srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_roaming_notification_list));
    MMI_ASSERT(temp2 != NULL);
    temp2->msg_id = inMsg->msg_id;
    temp2->next = NULL;

    if (NULL == g_srv_roaming_cntx->notify_list_start)
    {
        g_srv_roaming_cntx->notify_list_start = temp2;

    }
    else
    {
        temp1 = g_srv_roaming_cntx->notify_list_start;
        while (temp1->next != NULL)
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, NODES_PRESENT_IN_LIST, temp1->msg_id);
            temp1 = temp1->next;
        }
        temp1->next = temp2;
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_roaming_info_check
 * DESCRIPTION
 *  as user come back to home zone according to homezone retrieval setting performs operation.
 * PARAMETERS
 *  roaming_status      [IN]        
 *  sim_id              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_roaming_info_check(U32 roaming_status, int sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_ROAMING_INFO_CHECK);

    if (srv_mms_is_ready())
    {
        if (roaming_status == 0)
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_ROAMING_INFO_STATUS, roaming_status);
            if (MMA_RETRIEVAL_MODE_IMMED == srv_mms_retrieval_settings_home_network_retrieval_mode())
            {
                /* Send Download Req for Notification in the list */
                srv_mms_roaming_notification_list *temp = NULL;

                if (g_srv_roaming_cntx->notify_list_start)
                {
                    temp = g_srv_roaming_cntx->notify_list_start;
                    g_srv_roaming_cntx->notify_list_start = g_srv_roaming_cntx->notify_list_start->next;
                    temp->next = NULL;
                    srv_mms_get_header_request_for_notification(temp->msg_id);
                    if (temp != NULL)
                    {
                        srv_mms_mem_mgr_app_adm_free(temp);
                        temp = NULL;
                    }

                }

            }
            else
            {
                srv_mms_notification_list_delete_all(); /* delete all node from show notification list and file */
            }
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_notification_list_delete_all
 * DESCRIPTION
 *  delete all notification from list and empty the notification file.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_notification_list_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    srv_mms_roaming_notification_list *temp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp = g_srv_roaming_cntx->notify_list_start;

    while (g_srv_roaming_cntx->notify_list_start)
    {
        temp = g_srv_roaming_cntx->notify_list_start;
        g_srv_roaming_cntx->notify_list_start = temp->next;
        srv_mms_mem_mgr_app_adm_free(temp);
        /* g_srv_roaming_cntx->notify_list_start = NULL; */

    }
    file_handle = FS_Open((const WCHAR*)g_srv_roaming_cntx->default_sys_folder_path_for_notify_path, FS_CREATE_ALWAYS);
    FS_Close(file_handle);

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_header_request_for_notification
 * DESCRIPTION
 *  Get Header Info Request.
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_get_header_request_for_notification(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_mma_get_msg_info_req_struct msg_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&msg_req, 0, sizeof(srv_mms_mma_get_msg_info_req_struct));
    msg_req.msg_id = msg_id;
    msg_req.user_data = (void*)&msg_id;
    msg_req.call_back = (srv_mms_funcptr_type) srv_mms_notification_get_header_rsp;
    msg_req.app_id = MMA_APP_ID_MMS_NOTIFICATION_EVENT;
    srv_mms_mma_get_msg_info(&msg_req);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_notification_get_header_rsp
 * DESCRIPTION
 *  Get Header Info Request.
 * PARAMETERS
 *  result          [IN]        
 *  msgrsp          [?]         [?]
 *  user_data       [IN]        
 *  inMsg(?)(?)
 *  msg_id(?)       [IN](?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_notification_get_header_rsp(srv_mms_result_enum result, void *msgrsp, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_msg_info_rsp_struct *msgInfo = (wap_mma_get_msg_info_rsp_struct*) msgrsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_download_request(msgInfo);
    srv_mms_get_next_msg_id_from_notify_list();

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_download_request
 * DESCRIPTION
 *  thsi function write the current list information to file.
 * PARAMETERS
 *  curr_msg        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_download_request(wap_mma_get_msg_info_rsp_struct *curr_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U32 current_secs_since_1970 = 0;
    U64 size_available = 0;
    U32 used_bytes = 0;
    U32 time = 0;
    U8 storage_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    storage_type = curr_msg->storage_type;  /* mms option screen data for storage info *//* mmi_umms_app_dtmgr_get_prefered_storage(); //mma enum not mms enum careful */
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DOWNLOAD_REQUEST);
    current_secs_since_1970 = umms_get_current_utc_time();
    if (current_secs_since_1970 > (curr_msg->expiry_date + curr_msg->received_date))
    {
        return;
    }
    if (srv_mms_bgsr_get_msg_status(curr_msg->msg_id) != SRV_MMS_BGSR_STATUS_DOWNLOADING)
    {
    #ifndef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
    #ifdef __MMI_WAP_MMS_NO_REJECT_NOTIFICATION_BY_SIZE__
        if (curr_msg->user_elements_size > wap_custom_get_max_mms_msg_size())
        {
            return;
        }
    #else /* __MMI_WAP_MMS_NO_REJECT_NOTIFICATION_BY_SIZE__ */ 
        if (curr_msg->user_elements_size > wap_custom_get_max_mms_msg_size())
        {
            return;
        }
    #endif /* __MMI_WAP_MMS_NO_REJECT_NOTIFICATION_BY_SIZE__ */ 
    #endif /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ /* __MMI_WAP_MMS_NO_REJECT_NOTIFICATION_BY_SIZE__ */

        size_available = mma_get_mms_avaliable_file_space(NULL, storage_type);
        if (size_available < curr_msg->msg_size)
        {
            return;
        }
    }
    time = (curr_msg->expiry_date) - (current_secs_since_1970 - curr_msg->received_date);

#ifndef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
    srv_mms_bgsr_download_req_no_progressing((U8) curr_msg->sim_id, (U32) curr_msg->msg_id, curr_msg->storage_type);
#else 
    srv_mms_bgsr_download_req_no_progressing((U8) curr_msg->sim_id, (U32) curr_msg->msg_id, curr_msg->storage_type);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_next_msg_id_from_notify_list
 * DESCRIPTION
 *  this function retrieve next message id from notification list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_get_next_msg_id_from_notify_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    srv_mms_roaming_notification_list *temp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_roaming_cntx->notify_list_start != NULL)
    {
        temp = g_srv_roaming_cntx->notify_list_start;
        g_srv_roaming_cntx->notify_list_start = g_srv_roaming_cntx->notify_list_start->next;
        temp->next = NULL;
        srv_mms_get_header_request_for_notification(temp->msg_id);
        if (temp != NULL)
        {
            srv_mms_mem_mgr_app_adm_free(temp);
            temp = NULL;
        }

    }
    else
    {
        file_handle = FS_Open((const WCHAR*)g_srv_roaming_cntx->default_sys_folder_path_for_notify_path, FS_CREATE_ALWAYS);
        FS_Close(file_handle);
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_add_to_notification_list
 * DESCRIPTION
 *  notification messages are added in a list while user is in roaming area..
 * PARAMETERS
 *  inMsg       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_add_to_notification_list(const srv_mms_mma_get_msg_info_rsp_struct *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_roaming_notification_list *temp1;
    srv_mms_roaming_notification_list *temp2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_ADD_TO_LIST_FROM_FILE);
    if (NULL == g_srv_roaming_cntx->notify_list_start)
    {
        temp2 = srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_roaming_notification_list));
        MMI_ASSERT(temp2 != NULL);
        temp2->msg_id = inMsg->msg_id;
        temp2->next = NULL;
        g_srv_roaming_cntx->notify_list_start = temp2;
    }
    else
    {
        temp1 = g_srv_roaming_cntx->notify_list_start;
        while (temp1->next != NULL)
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, NODES_PRESENT_IN_LIST, temp1->msg_id);
            temp1 = temp1->next;
        }
        temp2 = srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_roaming_notification_list));
        MMI_ASSERT(temp2 != NULL);
        temp2->msg_id = inMsg->msg_id;
        temp2->next = NULL;
        temp1->next = temp2;
    }

    srv_mms_write_data_to_notify_file(temp2);   /* write to file  */

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_write_data_to_notify_file
 * DESCRIPTION
 *  write the list to notification file structure by structure.
 * PARAMETERS
 *  notify_struct       [IN]        
 *  count(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_write_data_to_notify_file(srv_mms_roaming_notification_list *notify_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    U32 size = 0;
    S32 retval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_WRITE_DATA_TO_NOTIFY_FILE);
    file_handle = FS_Open((const WCHAR*)g_srv_roaming_cntx->default_sys_folder_path_for_notify_path, FS_READ_WRITE);
    if (file_handle > 0)
    {
        FS_Seek(file_handle, 0, FS_FILE_END);
        retval = FS_Write(file_handle, notify_struct, sizeof(srv_mms_roaming_notification_list), &size);
        FS_Close(file_handle);

    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_start_notification_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_start_notification_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StartTimer(UMMS_NOTIFY_TIMER, UMMS_NOTIFY_TIMER_DUR, srv_mms_notification_timer_expire);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_notification_timer_expire
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_notification_timer_expire(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_mms_bgsr_is_ready())
    {
        StopTimer(UMMS_NOTIFY_TIMER);
        srv_mms_notify_download_request_in_home();

    }
    else
    {
        StopTimer(UMMS_NOTIFY_TIMER);
        srv_mms_start_notification_timer();
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_notify_download_request_in_home
 * DESCRIPTION
 *  at the time of boot up if there is home zone and immediate setting for MMS retrieval then send
 *  the download request otherwiase delete all notification
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_notify_download_request_in_home(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_nw_info_is_roaming(MMI_SIM1) == FALSE)
    {
        if (MMA_RETRIEVAL_MODE_IMMED == srv_mms_retrieval_settings_home_network_retrieval_mode())
        {
            srv_mms_get_next_msg_id_from_notify_list();
        }
        else
        {
            srv_mms_notification_list_delete_all();
        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_delete_single_msg_from_notify_list
 * DESCRIPTION
 *  if a message is deleted from INBOX then this should be deleted from show notification list.
 * PARAMETERS
 *  msg_id      [IN]        
 *  inMsg(?)        [IN](?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_delete_single_msg_from_notify_list(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_roaming_notification_list *temp1 = NULL;
    srv_mms_roaming_notification_list *temp2 = NULL;
    U16 count = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DELETE_MSG_FROM_SHOW_NOTIFICATION_LIST);
    temp1 = g_srv_roaming_cntx->notify_list_start;
    temp2 = temp1;

    while (temp1)
    {
        if (temp1->msg_id == msg_id)
        {

            if ((count == 1) && (temp1->next == NULL))
            {
                srv_mms_mem_mgr_app_adm_free(temp1);
                temp2 = NULL;
                temp1 = NULL;
                g_srv_roaming_cntx->notify_list_start = NULL;
                break;
            }
            else if ((count == 1) && (temp1->next != NULL))
            {
                temp1 = temp1->next;
                g_srv_roaming_cntx->notify_list_start = temp1;
                temp2->next = NULL;
                srv_mms_mem_mgr_app_adm_free(temp2);
                break;
            }
            else
            {
                temp2->next = temp1->next;
                srv_mms_mem_mgr_app_adm_free(temp1);
                break;
            }
        }
        else
        {
            temp2 = temp1;
            temp1 = temp1->next;
            count++;
        }
    }

    srv_mms_write_current_notify_list_to_file();

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_write_current_notify_list_to_file
 * DESCRIPTION
 *  thsi function write the current list information to file.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_write_current_notify_list_to_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    U32 size;
    S32 retval;
    srv_mms_roaming_notification_list *temp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_WRITE_CURRENT_LIST_TO_FILE);
    temp = g_srv_roaming_cntx->notify_list_start;

    //file_handle = FS_Delete(default_sys_folder_path_for_notify_path);
    //FS_Close(file_handle);
    /* FS_CREATE_ALWAYS create a fresh file */
    file_handle = FS_Open((const WCHAR*)g_srv_roaming_cntx->default_sys_folder_path_for_notify_path, FS_CREATE_ALWAYS);
    FS_Close(file_handle);
    file_handle = FS_Open((const WCHAR*)g_srv_roaming_cntx->default_sys_folder_path_for_notify_path, FS_READ_WRITE);
    if (file_handle > 0)
    {
        while (temp)
        {

            FS_Seek(file_handle, 0, FS_FILE_END);
            retval = FS_Write(file_handle, temp, sizeof(srv_mms_roaming_notification_list), &size);

            temp = temp->next;
        }
    }

    FS_Close(file_handle);

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_delete_msg_from_show_notification_list
 * DESCRIPTION
 *  if a message is deleted from INBOX then this should be deleted from show notification list.
 * PARAMETERS
 *  inMsg       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_delete_msg_from_show_notification_list(wap_mma_delete_rsp_struct *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_roaming_notification_list *temp1 = NULL;
    srv_mms_roaming_notification_list *temp2 = NULL;
    U16 count = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DELETE_MSG_FROM_SHOW_NOTIFICATION_LIST);
    temp1 = g_srv_roaming_cntx->notify_list_start;
    temp2 = temp1;

    while (temp1)
    {
        if (temp1->msg_id == inMsg->msg_id[0])
        {

            if ((count == 1) && (temp1->next == NULL))
            {
                srv_mms_mem_mgr_app_adm_free(temp1);
                temp2 = NULL;
                temp1 = NULL;
                g_srv_roaming_cntx->notify_list_start = NULL;
                break;
            }
            else if ((count == 1) && (temp1->next != NULL))
            {
                temp1 = temp1->next;
                g_srv_roaming_cntx->notify_list_start = temp1;
                temp2->next = NULL;
                srv_mms_mem_mgr_app_adm_free(temp2);
                break;
            }
            else
            {
                temp2->next = temp1->next;
                srv_mms_mem_mgr_app_adm_free(temp1);
                break;
            }
        }
        else
        {
            temp2 = temp1;
            temp1 = temp1->next;
            count++;
        }
    }

    srv_mms_write_current_notify_list_to_file();

}

#endif /* __MMI_MMS_ROAMING_NO_ACCEPT_SUPPORT__ */ 

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
#ifdef __MMI_MMS_DUAL_SIM__
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
#else
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
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

#if(MMI_MAX_SIM_NUM >= 2)

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_convert_to_uc_sim_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_mms_convert_to_uc_sim_id(U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sim_id)
    {

        case MMI_SIM1:
            return SRV_UC_SIM_ID_GSM_SIM1;
            
        case MMI_SIM2:
            return SRV_UC_SIM_ID_GSM_SIM2;
            
        default:
            return SRV_UC_SIM_ID_UNCLASSIFIED;
            
    }
}
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_dual_sim_set_download_msg_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_dual_sim_set_download_msg_id(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_dual_sim_cntx->download_msg_id = msg_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_dual_sim_get_download_msg_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_mms_dual_sim_get_download_msg_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_dual_sim_cntx->download_msg_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_dual_sim_set_download_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  time        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_dual_sim_set_download_time(U32 time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_dual_sim_cntx->download_time = time;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_dual_sim_set_download_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_dual_sim_set_download_size(U8 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_dual_sim_cntx->download_size = size;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_sim_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_get_sim_status(U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_SIM1 == sim_id)
    {
        return g_srv_dual_sim_cntx->sim1_on;
    }
    else if (MMI_SIM2 == sim_id)
    {
        return g_srv_dual_sim_cntx->sim2_on;
    }
    else
    {
        MMI_ASSERT(0);
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_selected_sim_id
 * DESCRIPTION
 *  Set the sim id for send MMS.
 * PARAMETERS
 *  sim_id      [IN]        
 *  current_state(?)        [IN](?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_selected_sim_id(const U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_dual_sim_cntx->sim_select_id = sim_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_selected_sim_id
 * DESCRIPTION
 *  Get the sim id for mms send
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_mms_get_selected_sim_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_dual_sim_cntx->sim_select_id;
}

#endif /* (MMI_MAX_SIM_NUM >= 2) */ /* __MMI_MMS_DUAL_SIM__ */

#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_buffer_for_nmgr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_rsp     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_buffer_for_nmgr(srv_mms_get_unread_msg_list_rsp_struct *msg_rsp)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nmgr_info_struct info = {0};
    S8 idle_buffer[MMA_MAX_ADDR_LEN + 40];
    S8 tmp_str[SRV_MMS_CONVERT_INDEX] = {0, };
    /* S8 str_cmp_temp[MMA_MAX_ADDR_LEN] = {0x00, }; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_rsp->result == MMA_RESULT_OK)
    {
        info.total_num = msg_rsp->total_num_of_unread_msg;
    #ifndef __COSMOS_MMI_PACKAGE__
        info.image = IMG_NEW_MESSAGE_NOTIFICATION_MSG;
    #else 
        info.image = 0;
    #endif 

        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_SET_NMGR_SIM, g_srv_new_msg_cntx->sim_id_for_new_msg);
        g_srv_new_msg_cntx->sim_id_for_new_msg = 1;

        gui_itoa(msg_rsp->total_num_of_unread_msg, (UI_string_type) tmp_str, SRV_MMS_CONVERT_INDEX);
        mmi_ucs2cpy((S8*) idle_buffer, (S8*) tmp_str);
        mmi_ucs2cat((S8*) idle_buffer, (S8*) L" ");
        mmi_ucs2cat((S8*) idle_buffer, (S8*) GetString(STR_ID_UMMS_NEW_MMS));

        info.idle_text1 = idle_buffer;
        info.idle_text2 = NULL;
    #ifndef __COSMOS_MMI_PACKAGE__
        info.image = IMG_NEW_MESSAGE_NOTIFICATION_MSG;
    #else 
        info.image = 0;
    #endif 
        mmi_nmgr_answer(
            MMI_NMGR_APP_MMS,       /* menu data type */
            MMI_NMGR_RESULT_UPDATE, /* result ok */
            &info,                  /* array of unread SMS events */
            srv_mms_new_mms_handle_notification);
        g_srv_new_msg_cntx->nmgr_informed = MMI_TRUE;
    }
    else
    {
        mmi_nmgr_answer(
            MMI_NMGR_APP_MMS,           /* menu data type */
            MMI_NMGR_RESULT_NOT_READY,  /* result ok */
            NULL,                       /* array of unread SMS events */
            NULL);

    }

}
#endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/

/*****************************************************************************
 * FUNCTION
 *  srv_mms_new_mms_handle_notification
 * DESCRIPTION
 *  
 * PARAMETERS
 *  user_data       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_new_mms_handle_notification(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return;
}

/******************amit added for settings************************/


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_settings_rsp_data_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  process     [?]     [?]
 *  msg         [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_settings_rsp_data_hdlr(srv_mms_process_data_struct *process, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_set_setting_rsp_struct *rsp = (wap_mma_set_setting_rsp_struct*) msg;
    srv_mms_mma_set_settings_rsp_struct *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = process->result;

    result->app_id = rsp->app_id;
    result->result = rsp->result;
    process->call_back(SRV_MMS_RESULT_OK, process->result, process->user_data);

    srv_mms_reset_process_data(process);
    return;

}

#ifdef __MMI_MMS_TEMPLATE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_um_list_info_rsp_data_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  process     [?]     [?]
 *  msg         [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_get_um_list_info_rsp_data_hdlr(srv_mms_process_data_struct *process, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;
    srv_um_get_msg_list_rsp_struct *list_rsp = (srv_um_get_msg_list_rsp_struct*) msg;
    srv_mms_get_list_info_rsp_struct *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = process->result;
    result->app_id = list_rsp->app_id;
    result->result = list_rsp->result;
    result->msg_type = list_rsp->msg_type;
    result->msg_box_type = list_rsp->msg_box_type;
    result->start_entry = list_rsp->start_entry;
    result->msg_number = list_rsp->msg_number;

    for (index = 0; index < list_rsp->msg_number; index++)
    {
        result->list_info[index].msg_id = list_rsp->list_info[index].msg_id;
        result->list_info[index].timestamp = list_rsp->list_info[index].timestamp;
    }
    process->call_back(SRV_MMS_RESULT_OK, process->result, process->user_data);

    srv_mms_reset_process_data(process);
    return;

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_um_msg_info_rsp_data_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  process     [?]     [?]
 *  msg         [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_get_um_msg_info_rsp_data_hdlr(srv_mms_process_data_struct *process, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;
    srv_um_get_msg_info_rsp_struct *msg_info_rsp = (srv_um_get_msg_info_rsp_struct*) msg;
    srv_mms_get_msg_info_rsp_struct *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = process->result;
    result->app_id = msg_info_rsp->app_id;
    for (index = 0; index < msg_info_rsp->msg_number; index++)
    {
        result->result[index] = msg_info_rsp->result[index];
    }
    result->msg_type = msg_info_rsp->msg_type;
    result->msg_box_type = msg_info_rsp->msg_box_type;
    result->msg_number = msg_info_rsp->msg_number;
    memcpy(result->msg_info, msg_info_rsp->msg_info, sizeof(srv_um_msg_info_struct) * SRV_UM_MAX_GET_MSG_INFO_NUMBER);
    process->call_back(SRV_MMS_RESULT_OK, process->result, process->user_data);

    srv_mms_reset_process_data(process);
    return;
}
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 
/* USB Handling needed for Sending */

#ifdef __USB_IN_NORMAL_MODE__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_entry_usb_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_mms_entry_usb_rsp_hdlr(void)
{
    /* If USB is Plugged in Send a Cancel Send request for all MMS and change the state to E_STATE_USB_PLUG_IN */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_refresh_ind_struct *um_refresh_ind = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_USB_MODE_ON); */
    if (srv_mms_is_ready())
    {
        srv_mms_show_status_icon();

        um_refresh_ind =
            (srv_um_refresh_ind_struct*) construct_local_para(
                                            (kal_uint16) sizeof(srv_um_refresh_ind_struct),
                                            TD_CTRL | TD_RESET);
        um_refresh_ind->msg_type = SRV_UM_MSG_MMS;
        um_refresh_ind->msg_box_type = SRV_UM_MSG_BOX_ALL;

        srv_mms_send_message(MOD_MMI, MOD_MMI, 0, MSG_ID_MMI_UM_REFRESH_IND, (oslParaType*) um_refresh_ind, NULL);

    }
}

#endif /* __USB_IN_NORMAL_MODE__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_usb_mode_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_mms_usb_mode_on(mmi_event_struct *para)
{
    /* If USB is Plugged in Send a Cancel Send request for all MMS and change the state to E_STATE_USB_PLUG_IN */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_is_usb_mode = TRUE;
    if (srv_mms_is_ready())
    {
    #ifdef __MMI_MMS_MMA_MMS_OBJECT_IND__
        srv_mms_stop_object_indication_timer();
    #endif 
        srv_mms_nmgr_cancel_unread_msg();
    #ifdef __USB_IN_NORMAL_MODE__
        mms_on_enter_usb_mode();
    #endif 
    }
    return MMI_RET_OK;
}

#ifdef __USB_IN_NORMAL_MODE__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_exit_usb_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_exit_usb_rsp_hdlr(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    srv_um_refresh_ind_struct *um_refresh_ind = NULL;

    g_srv_is_usb_mode = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_USB_MODE_OFF);
    if (srv_mms_is_ready())
    {

        srv_mms_show_status_icon();

    #ifdef __MMI_MMS_MMA_MMS_OBJECT_IND__
        srv_mms_start_object_indication_timer();
    #endif /* __MMI_MMS_MMA_MMS_OBJECT_IND__ */ 
        um_refresh_ind =
            (srv_um_refresh_ind_struct*) construct_local_para(
                                            (kal_uint16) sizeof(srv_um_refresh_ind_struct),
                                            TD_CTRL | TD_RESET);
        um_refresh_ind->msg_type = SRV_UM_MSG_MMS;
        um_refresh_ind->msg_box_type = SRV_UM_MSG_BOX_ALL;

        srv_mms_send_message(MOD_MMI, MOD_MMI, 0, MSG_ID_MMI_UM_REFRESH_IND, (oslParaType*) um_refresh_ind, NULL);
    }

}

#endif /* __USB_IN_NORMAL_MODE__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_usb_mode_off
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_mms_usb_mode_off(mmi_event_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    mms_on_exit_usb_mode();
#endif 

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_is_usb_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
BOOL srv_mms_is_usb_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_is_usb_mode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_app_data_rsp_hdlr
 * DESCRIPTION
 *  Fills the data from MMA to result struct srv_mms_set_app_data_rsp_struct
 * PARAMETERS
 *  process     [?]     [?]     [IN]Process struct
 *  msg         [?]     [?]     [IN]Response from MMA
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_app_data_rsp_hdlr(srv_mms_process_data_struct *process, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_set_app_data_rsp_struct *rsp = (wap_mma_set_app_data_rsp_struct*) msg;
    srv_mms_set_app_data_rsp_struct *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = process->result;

    result->app_id = rsp->app_id;
    result->result = rsp->result;
    result->msg_id = rsp->msg_id;

    process->call_back(SRV_MMS_RESULT_OK, process->result, process->user_data);

    srv_mms_reset_process_data(process);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_emit_ready_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mms_ready       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_emit_ready_event(MMI_BOOL mms_ready)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_event_struct event_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI_TRACE */

    MMI_FRM_INIT_EVENT(&event_data, EVT_ID_SRV_MMS_READY);
    event_data.mms_ready = mms_ready;
    MMI_FRM_CB_EMIT_EVENT(&event_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_convert_mma_addr_type_to_srv_addr_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_mms_convert_mma_addr_type_to_srv_addr_type(mma_addr_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case MMA_ADDR_TYPE_PHONE_NUMBER:
            return SRV_MMS_ADDRESS_TYPE_PHONE_NUMBER;
            

        case MMA_ADDR_TYPE_EMAIL:
            return SRV_MMS_ADDRESS_TYPE_EMAIL;
            

        default:
            return SRV_MMS_ADDRESS_TYPE_TOTAL_NUM;
            
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_convert_mma_addr_group_to_srv_addr_group
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_mms_convert_mma_addr_group_to_srv_addr_group(mma_address_group_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case MMA_ADDRESS_GROUP_TYPE_TO:
            return SRV_MMS_ADDRESS_GROUP_TYPE_TO;
            

        case MMA_ADDRESS_GROUP_TYPE_CC:
            return SRV_MMS_ADDRESS_GROUP_TYPE_CC;
            

        case MMA_ADDRESS_GROUP_TYPE_BCC:
            return SRV_MMS_ADDRESS_GROUP_TYPE_BCC;
            
        case MMA_ADDRESS_GROUP_TYPE_FROM:
            return SRV_MMS_ADDRESS_GROUP_TYPE_FROM;
            
        default:
            return SRV_MMS_ADDRESS_GROUP_TYPE_TOTAL_NUM;
            
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_fill_msg_num_req_struct
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgReq      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_fill_msg_num_req_struct(srv_mms_get_msg_count_struct *msgReq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U32 loop_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_UMMS_FILL_MSG_NUM);
    msgReq->count = SRV_MMS_MAX_MSG_NUM_QUERY_NUM;
    for (loop_count = 0; loop_count < msgReq->count; loop_count++)
    {
        switch (num_query_array[loop_count])
        {
            case UMMS_QUERY_OPTION_NUM_UNREAD_INBOX_MSG_SIM1:
                msgReq->req_tb[loop_count] = SRV_MMS_QUERY_UNREAD_INBOX_MSG_SIM1;
                break;
        #if(MMI_MAX_SIM_NUM >=2)
            case UMMS_QUERY_OPTION_NUM_UNREAD_INBOX_MSG_SIM2:
                msgReq->req_tb[loop_count] = SRV_MMS_QUERY_UNREAD_INBOX_MSG_SIM2;
                break;
        #endif /* (MMI_MAX_SIM_NUM >=2) */ 
        #if(MMI_MAX_SIM_NUM >= 3)
            case UMMS_QUERY_OPTION_NUM_UNREAD_INBOX_MSG_SIM3:
                msgReq->req_tb[loop_count] = SRV_MMS_QUERY_UNREAD_INBOX_MSG_SIM3;
                break;
        #endif /* (MMI_MAX_SIM_NUM >= 3) */ 
        #if(MMI_MAX_SIM_NUM >= 4)
            case UMMS_QUERY_OPTION_NUM_UNREAD_INBOX_MSG_SIM4:
                msgReq->req_tb[loop_count] = SRV_MMS_QUERY_UNREAD_INBOX_MSG_SIM4;
                break;
        #endif /* (MMI_MAX_SIM_NUM >= 4) */ 
            case UMMS_QUERY_OPTION_NUM_TOTAL_INBOX_MSG:
                msgReq->req_tb[loop_count] = SRV_MMS_QUERY_TOTAL_INBOX_MSG;
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_OUTBOX_MSG:
                msgReq->req_tb[loop_count] = SRV_MMS_QUERY_TOTAL_OUTBOX_MSG;
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_SENT_MSG:
                msgReq->req_tb[loop_count] = SRV_MMS_QUERY_TOTAL_SENT_MSG;
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_DRAFT_MSG:
                msgReq->req_tb[loop_count] = SRV_MMS_QUERY_TOTAL_DRAFT_MSG;
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_ARCHIVE_MSG:
                msgReq->req_tb[loop_count] = SRV_MMS_QUERY_TOTAL_ARCHIVE_MSG;
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_USER_DEF_TEMPLATE_MSG:
                msgReq->req_tb[loop_count] = SRV_MMS_QUERY_TOTAL_USER_DEF_TEMPLATE_MSG;
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_PRE_DEF_TEMPLATE_MSG:
                msgReq->req_tb[loop_count] = SRV_MMS_QUERY_TOTAL_PRE_DEF_TEMPLATE_MSG;
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_UNREAD_MSG:
                msgReq->req_tb[loop_count] = SRV_MMS_QUERY_TOTAL_UNREAD_INBOX_MSG;
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_PHONE:
                msgReq->req_tb[loop_count] = SRV_MMS_QUERY_TOTAL_PHONE_MSG;
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_CARD:
                msgReq->req_tb[loop_count] = SRV_MMS_QUERY_TOTAL_CARD_MSG;
                break;
            default:
                break;
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_update_folder_msg_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_update_folder_msg_num(const srv_mms_get_msg_count_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 loop_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (loop_count = 0; loop_count < msg->count; loop_count++)
    {
        switch (num_query_array[loop_count])
        {
            case UMMS_QUERY_OPTION_NUM_UNREAD_INBOX_MSG_SIM1:
                g_srv_msg_num_cntx->total_unread_msgs_sim1 = msg->rsp_tb[loop_count];
                break;
        #if(MMI_MAX_SIM_NUM >= 2)
            case UMMS_QUERY_OPTION_NUM_UNREAD_INBOX_MSG_SIM2:
                g_srv_msg_num_cntx->total_unread_msgs_sim2 = msg->rsp_tb[loop_count];
                break;
        #endif /* (MMI_MAX_SIM_NUM >= 2) */ 
        #if(MMI_MAX_SIM_NUM >= 3)
            case UMMS_QUERY_OPTION_NUM_UNREAD_INBOX_MSG_SIM3:
                g_srv_msg_num_cntx->total_unread_msgs_sim3 = msg->rsp_tb[loop_count];
                break;
        #endif /* (MMI_MAX_SIM_NUM >= 3) */ 
        #if(MMI_MAX_SIM_NUM >= 4)
            case UMMS_QUERY_OPTION_NUM_UNREAD_INBOX_MSG_SIM4:
                g_srv_msg_num_cntx->total_unread_msgs_sim4 = msg->rsp_tb[loop_count];
                break;
        #endif /* (MMI_MAX_SIM_NUM >= 4) */ 
            case UMMS_QUERY_OPTION_NUM_TOTAL_INBOX_MSG:
                g_srv_msg_num_cntx->msg_number_inbox = msg->rsp_tb[loop_count];
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_OUTBOX_MSG:
                g_srv_msg_num_cntx->msg_number_outbox = msg->rsp_tb[loop_count];
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_SENT_MSG:
                g_srv_msg_num_cntx->msg_number_sent = msg->rsp_tb[loop_count];
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_DRAFT_MSG:
                g_srv_msg_num_cntx->msg_number_drafts = msg->rsp_tb[loop_count];
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_ARCHIVE_MSG:
        #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
                g_srv_msg_num_cntx->archive_msg_number = msg->rsp_tb[loop_count];
        #endif 
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_USER_DEF_TEMPLATE_MSG:
                g_srv_msg_num_cntx->userdefined_template_msg_number = msg->rsp_tb[loop_count];
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_PRE_DEF_TEMPLATE_MSG:
                g_srv_msg_num_cntx->predefined_template_msg_number = msg->rsp_tb[loop_count];
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_UNREAD_MSG:
                g_srv_msg_num_cntx->total_number_of_unread_msgs = msg->rsp_tb[loop_count];
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_PHONE:
                g_srv_msg_num_cntx->total_phone_msg_number = msg->rsp_tb[loop_count];
                break;
            case UMMS_QUERY_OPTION_NUM_TOTAL_CARD:
                g_srv_msg_num_cntx->total_card_msg_number = msg->rsp_tb[loop_count];
                break;
            default:
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_is_duplicate_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ucs2_addr       [?]         
 *  type            [IN]        
 *  list1           [?]         
 *  list2           [?]         
 *  list3           [?]         
 *  msg(?)          [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_is_duplicate_address(
            U8 *ucs2_addr,
            srv_mms_address_type_enum type,
            srv_mms_addr_struct *list1,
            srv_mms_addr_struct *list2,
            srv_mms_addr_struct *list3)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_addr_struct *list = NULL;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(ucs2_addr && (list1 || list2 || list3)))
    {
        ASSERT(0);
    }

    if (type == SRV_MMS_ADDRESS_TYPE_PHONE_NUMBER)
    {
        S8 ucs2_temp_addr[(SRV_MMS_XML_MAX_ADDR_LEN + 1) * ENCODING_LENGTH];

        memset(ucs2_temp_addr, 0, sizeof(ucs2_temp_addr));

        count = 3;
        while (count > 0)
        {
            if (count == 3)
            {
                list = list1;
            }
            else if (count == 2)
            {
                list = list2;
            }
            else if (count == 1)
            {
                list = list3;
            }
            else
            {
                break;
            }

            for (; list != NULL; list = list->next)
            {
                if (list->type != SRV_MMS_ADDRESS_TYPE_PHONE_NUMBER)
                {
                    continue;
                }

                /* Compare number will compare only 40 digits! */
                mmi_asc_n_to_ucs2((S8*) ucs2_temp_addr, (S8*) list->addr, SRV_MMS_XML_MAX_ADDR_LEN);
                if (srv_phb_compare_number((U16*) ucs2_addr, (U16*) ucs2_temp_addr) == MMI_TRUE)
                {
                    return MMI_TRUE;
                }
            }
            --count;
        }

    }
    else if (type == SRV_MMS_ADDRESS_TYPE_EMAIL)
    {
        count = 3;
        while (count > 0)
        {
            if (count == 3)
            {
                list = list1;
            }
            else if (count == 2)
            {
                list = list2;
            }
            else if (count == 1)
            {
                list = list3;
            }
            else
            {
                break;
            }
            for (; list != NULL; list = list->next)
            {
                if (list->type != SRV_MMS_ADDRESS_TYPE_EMAIL)
                {
                    continue;
                }

                if (srv_mms_compare_string_ignore_case((U16*) ucs2_addr, (U16*) list->addr) == MMI_TRUE)
                {
                    return MMI_TRUE;
                }
            }
            --count;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_entry_folder_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [?]     
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret srv_mms_entry_folder_hdlr(mmi_event_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __COSMOS_MMI_PACKAGE__
    mmi_um_entry_folder_evt_struct *info = (mmi_um_entry_folder_evt_struct*) para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((info->msg_box & SRV_UM_MSG_BOX_INBOX) == SRV_UM_MSG_BOX_INBOX) && (info->is_entry == MMI_TRUE))
    {
        g_srv_new_msg_cntx->is_new_msg = MMI_FALSE;
    }
#ifdef __MMI_MMS_REPORT_BOX_SUPPORT__
    if (((info->msg_box & SRV_UM_MSG_BOX_REPORT) == SRV_UM_MSG_BOX_REPORT) && (info->is_entry == MMI_TRUE))
    {
        g_srv_new_msg_cntx->is_new_report = MMI_FALSE;
        mma_mms_reset_unread_report_status();
    }
#endif /* __MMI_MMS_REPORT_BOX_SUPPORT__ */ 
#endif /* __COSMOS_MMI_PACKAGE__ */ 
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mms_nmgr_if_new_msg_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
U8 srv_mms_nmgr_sim_id_for_new_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_new_msg_cntx->sim_id_for_new_msg;
}

#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__

/*****************************************************************************
 * FUNCTION
 *  srv_mms_nmgr_if_new_msg_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_nmgr_if_new_msg_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL)g_srv_new_msg_cntx->is_new_msg;
}
#endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/

#ifdef __MMI_MMS_REPORT_BOX_SUPPORT__

#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
/*****************************************************************************
 * FUNCTION
 *  srv_mms_nmgr_if_new_report_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_nmgr_if_new_report_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL)g_srv_new_msg_cntx->is_new_report;
}
#endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/

#endif /* __MMI_MMS_REPORT_BOX_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mma_folder_to_bgsr_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  folderID        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_mms_mma_folder_to_bgsr_folder(mma_folder_enum folderID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_UMMS_MMA_TO_BGSR_FOLDER, folderID); */

    switch (folderID)
    {
        case MMA_FOLDER_INBOX:
            return SRV_MMS_BGSR_FOLDER_INBOX;
            
        case MMA_FOLDER_OUTBOX:
            return SRV_MMS_BGSR_FOLDER_OUTBOX;
            
        case MMA_FOLDER_ARCHIVE:
            return SRV_MMS_BGSR_FOLDER_ARCHIVE;
            
        default:
            return SRV_MMS_BGSR_FOLDER_NONE;
            
    }
}

#ifdef __MMI_MMS_COPY_TO_ARCHIVE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_mms_copy_to_archive_rsp_hdlr
 * DESCRIPTION
 *  Fills the data from MMA to result struct srv_mms_copy_to_archive_req_struct
 * PARAMETERS
 *  process     [?]     [IN]Process struct
 *  msg         [?]     [IN]Response from MMA
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_copy_to_archive_rsp_hdlr(srv_mms_process_data_struct *process, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_cpy_msg_to_archive_folder_rsp_struct *rsp = (wap_mma_cpy_msg_to_archive_folder_rsp_struct*) msg;
    srv_mms_copy_to_archive_rsp_struct *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = process->result;

    result->app_id = rsp->app_id;
    result->result = rsp->result;

    result->msg_id = rsp->msg_id;

    process->call_back(SRV_MMS_RESULT_OK, process->result, process->user_data);

    srv_mms_reset_process_data(process);
    return;
}
#endif
#ifdef __COSMOS_MMI_PACKAGE__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_send_mem_full
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_send_mem_full(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U8 flag = 0;
    srv_mms_mem_status_event_struct event_data;
    U8 booted = 0x01;
    U8 phone_max_reached = 0x02;

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    U8 mem_card_max_reached = 0x04;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if its not first call after boot */
    if (flag & booted)
    {
        if (flag & phone_max_reached)
        {
            if (srv_mms_get_phone_mem_total_msg() < srv_mms_get_max_mms_num_on_phone())
            {
                MMI_FRM_INIT_EVENT(&event_data, EVT_ID_SRV_MMS_MEM_FULL);
                event_data.mms_mem_status = SRV_MMS_MEM_STATUS_PHONE_COUNT_NOT_MAX;
                MMI_FRM_CB_EMIT_EVENT(&event_data);

                flag &= !phone_max_reached;
            }
        }
        else
        {
            if (srv_mms_get_phone_mem_total_msg() == srv_mms_get_max_mms_num_on_phone())
            {
                MMI_FRM_INIT_EVENT(&event_data, EVT_ID_SRV_MMS_MEM_FULL);
                event_data.mms_mem_status = SRV_MMS_MEM_STATUS_PHONE_COUNT_MAX_REACH;
                MMI_FRM_CB_EMIT_EVENT(&event_data);

                flag |= phone_max_reached;
            }
        }
    #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
        if (flag & mem_card_max_reached)
        {
            if (srv_mms_get_mem_card_total_msg() < srv_mms_get_max_mms_num_on_card())
            {
                MMI_FRM_INIT_EVENT(&event_data, EVT_ID_SRV_MMS_MEM_FULL);
                event_data.mms_mem_status = SRV_MMS_MEM_STATUS_CARD_COUNT_NOT_MAX;
                MMI_FRM_CB_EMIT_EVENT(&event_data);

                flag &= !mem_card_max_reached;
            }
        }
        else
        {

            if (srv_mms_get_mem_card_total_msg() == srv_mms_get_max_mms_num_on_card())
            {
                MMI_FRM_INIT_EVENT(&event_data, EVT_ID_SRV_MMS_MEM_FULL);
                event_data.mms_mem_status = SRV_MMS_MEM_STATUS_CARD_COUNT_MAX_REACH;
                MMI_FRM_CB_EMIT_EVENT(&event_data);

                flag |= mem_card_max_reached;
            }
        }
    #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 

    }
    else
    {
        if (srv_mms_get_phone_mem_total_msg() == srv_mms_get_max_mms_num_on_phone())
        {
            MMI_FRM_INIT_EVENT(&event_data, EVT_ID_SRV_MMS_MEM_FULL);
            event_data.mms_mem_status = SRV_MMS_MEM_STATUS_PHONE_COUNT_MAX_REACH;
            MMI_FRM_CB_EMIT_EVENT(&event_data);

            flag |= phone_max_reached;
        }
        else
        {
            MMI_FRM_INIT_EVENT(&event_data, EVT_ID_SRV_MMS_MEM_FULL);
            event_data.mms_mem_status = SRV_MMS_MEM_STATUS_PHONE_COUNT_NOT_MAX;
            MMI_FRM_CB_EMIT_EVENT(&event_data);
        }
    #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
        if (srv_mms_get_mem_card_total_msg() == srv_mms_get_max_mms_num_on_card())
        {
            MMI_FRM_INIT_EVENT(&event_data, EVT_ID_SRV_MMS_MEM_FULL);
            event_data.mms_mem_status = SRV_MMS_MEM_STATUS_CARD_COUNT_MAX_REACH;
            MMI_FRM_CB_EMIT_EVENT(&event_data);
            flag |= mem_card_max_reached;
        }
        else
        {
            MMI_FRM_INIT_EVENT(&event_data, EVT_ID_SRV_MMS_MEM_FULL);
            event_data.mms_mem_status = SRV_MMS_MEM_STATUS_CARD_COUNT_NOT_MAX;
            MMI_FRM_CB_EMIT_EVENT(&event_data);
        }
    #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
        flag |= booted;
    }

    return;
}
#endif /* __COSMOS_MMI_PACKAGE__ */ 



/*****************************************************************************
 * FUNCTION
 * srv_mms_get_lite_viewer_data_rsp_hdlr
 * DESCRIPTION
 *  Fills the data from MMA to result struct srv_mms_get_lite_viewer_data_rsp_struct
 * PARAMETERS
 *  process   [IN]Process struct
 *  msg       [IN]Response from MMA
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_get_lite_viewer_data_rsp_hdlr(srv_mms_process_data_struct *process, void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_mms_thumbnail_and_attr_info_rsp_struct *rsp = (wap_mma_get_mms_thumbnail_and_attr_info_rsp_struct *)msg;
    srv_mms_get_lite_viewer_data_rsp_struct *result;
	U16 msg_file_path[(MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH];
	U16 msg_path[(MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = process->result;
    

    result->result = rsp->result;
    result->msg_id = rsp->msg_id;
    result->timestamp = rsp->attr_tbm_info.timestamp;
    result->msg_size = rsp->attr_tbm_info.msg_size;
    result->msg_type = rsp->attr_tbm_info.msg_type;
    result->storage_type = rsp->attr_tbm_info.storage_type;
    result->msg_sim_id = rsp->attr_tbm_info.msg_sim_id;

    result->thumbnail_info.body_size = rsp->attr_tbm_info.body_header_data.thumbnail_info.body_size;
    result->thumbnail_info.body_offset = rsp->attr_tbm_info.body_header_data.thumbnail_info.body_offset;
    result->thumbnail_info.body_name_len = rsp->attr_tbm_info.body_header_data.thumbnail_info.body_name_len;
    result->thumbnail_info.body_type = rsp->attr_tbm_info.body_header_data.thumbnail_info.body_type;
    result->thumbnail_info.is_drm = rsp->attr_tbm_info.body_header_data.thumbnail_info.is_drm;
    result->thumbnail_info.msg_download_size = rsp->attr_tbm_info.body_header_data.msg_download_size;
	/*extension for app who wants text*/
	result->thumbnail_info_txt.body_size = rsp->attr_tbm_info.body_header_data.thumbnail_info_txt.body_size;
    result->thumbnail_info_txt.body_offset = rsp->attr_tbm_info.body_header_data.thumbnail_info_txt.body_offset;
    result->thumbnail_info_txt.body_name_len = rsp->attr_tbm_info.body_header_data.thumbnail_info_txt.body_name_len;
    result->thumbnail_info_txt.body_type = rsp->attr_tbm_info.body_header_data.thumbnail_info_txt.body_type;
    result->thumbnail_info_txt.is_drm = rsp->attr_tbm_info.body_header_data.thumbnail_info_txt.is_drm;
    result->thumbnail_info_txt.msg_download_size = rsp->attr_tbm_info.body_header_data.msg_download_size;
	result->thumbnail_info_txt.txt_encoding_scheme = rsp->attr_tbm_info.body_header_data.thumbnail_info_txt.txt_encoding_scheme;
	mmi_ucs2ncpy(
            (PS8) result->thumbnail_info_txt.body_name,
            (PS8) rsp->attr_tbm_info.body_header_data.thumbnail_info_txt.body_name,
            MMA_MAX_MMS_BODY_FILE_NAME_LEN);
    mmi_ucs2ncpy((PS8) result->thumbnail_info.subject, (PS8) rsp->attr_tbm_info.body_header_data.subject, MMA_MAX_SUBJECT_LEN);
    mmi_ucs2ncpy(
            (PS8) result->thumbnail_info.body_name,
            (PS8) rsp->attr_tbm_info.body_header_data.thumbnail_info.body_name,
            MMA_MAX_MMS_BODY_FILE_NAME_LEN);
	if((MMA_MSG_TYPE_MMS  == result->msg_type) || (MMA_MSG_TYPE_JAVA == result->msg_type))
	{
		memset(msg_path, 0, (MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH);
        memset(msg_file_path, 0, (MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH);            
        mma_get_home_directory(
                      (kal_wchar*) msg_path,
                      MMA_MAX_INTERNAL_FILENAME_LENGTH,
                      result->storage_type);
		mma_get_msg_file_name(result->msg_id, (kal_wchar*) msg_file_path, MMA_MAX_INTERNAL_FILENAME_LENGTH);
		mmi_ucs2cat((CHAR*) msg_path, (CHAR*) "\\");
       mmi_ucs2cat((CHAR*) msg_path, (CHAR*) msg_file_path);
    }
	result->thumbnail_path = msg_path;
	if((result->thumbnail_info_txt.body_size) > 0)
	{
	    result->cb_text_function = srv_mms_get_text_buffer;
	}
	else
	{
		result->cb_text_function = NULL;
	}
	if((result->thumbnail_info.body_size) > 0) 
	{
    	result->cb_image_function = srv_mms_get_image_buffer ;
		
	}
	else
	{
		result->cb_image_function = NULL ;
		result->cb_deinit_function = NULL;
	}
	if(result->thumbnail_info.body_type == MMA_MEDIA_MSG_PHOTO)
	{
		result->cb_deinit_function = srv_mms_deinit_lite_viewer ;
	}
	else
	{
        result->cb_deinit_function = NULL ;
	}


    process->call_back(SRV_MMS_RESULT_OK,  process->result, process->user_data);
    
    srv_mms_reset_process_data(process);
    return;
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

#endif /* __MMI_MMS_2__ */ 

