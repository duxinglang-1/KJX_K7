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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * BrowserSrvMsgHdlr.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
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
*------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#ifndef MMI_BROWSERSRVMSGHDLR_C
#define MMI_BROWSERSRVMSGHDLR_C

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__
#include "app_ltlcom.h"
#include "BrowserSrvMsgHdlr.h"
#include "BrowserSrvProts.h"
#include "BrowserSrvBookmarks.h"
#include "BrowserSrvGprot.h"
#include "BrowserSrvInterface.h"
#include "WAPProfileSrvGProt.h"
#include "BrowserSrvMain.h"
#include "Sat_def.h" // For SAT related enum values
#include "DataAccountGprot.h" // for DATA_ACT_TYPE enum values
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "BrowserSrvConfig.h"
#include "mmi_frm_queue_gprot.h"
#include "stack_config.h"
#include "stack_common.h"
#include "bam_struct.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "string.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "app_buff_alloc.h"
#include "app_datetime.h"
#include "smu_common_enums.h"
#include "WAPProfileSrvType.h"
#include "bam_api.h"
#include "common_nvram_editor_data_item.h"
#include "mmi_frm_nvram_gprot.h"
#include "nvram_common_defs.h"
#include "Conversions.h"
#include "wps_struct.h"
#include "DLAgentSrvDef.h"
#include "browser_struct.h"
#include "DtcntSrvGprot.h"
#include "Unicodexdcl.h"
#include "ua_struct.h"
#include "stack_ltlcom.h"
//#include "SimDetectionStruct.h"
#include "MMI_inet_app_trc.h"
#include "kal_trace.h"
#include "wap_adp_struct.h"
#include "PhbSrvGprot.h"
#include "app_ua.h"

#ifdef __COSMOS_MMI_PACKAGE__
#include "DtcntSrvGprot.h"
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_brw_register_all_ilm_handlers
 * DESCRIPTION
 *  This function is used to register to receive ILM's from various tasks' 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_register_all_ilm_handlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* BAM SAPs */
    SetProtocolEventHandler(srv_brw_create_instance_cnf, MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF);
    SetProtocolEventHandler(srv_brw_delete_instance_cnf, MSG_ID_WAP_BAM_DELETE_INSTANCE_CNF);
#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
    SetProtocolEventHandler((PsFuncPtr) srv_brw_save_as_stored_page_cnf, MSG_ID_WAP_BAM_SAVE_PAGE_CNF);
    SetProtocolEventHandler(
        srv_brw_get_stored_pages_list_start_cnf,
        MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_START_CNF);
    SetProtocolEventHandler(
        (PsFuncPtr) srv_brw_get_stored_pages_list_continue_cnf,
        MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_CONTINUE_CNF);
#endif /* #ifdef __MMI_BRW_STORED_PAGES_SUPPORT__ */
    SetProtocolEventHandler(srv_brw_get_resource_list_start_cnf, MSG_ID_WAP_BAM_GET_RESOURCES_LIST_START_CNF);
    SetProtocolEventHandler(
        (PsFuncPtr) srv_brw_get_resource_list_continue_cnf,
        MSG_ID_WAP_BAM_GET_RESOURCES_LIST_CONTINUE_CNF);
#ifdef OBIGO_Q05A
    SetProtocolEventHandler((PsFuncPtr) srv_brw_get_resource_cnf, MSG_ID_WAP_BAM_GET_RESOURCE_CNF);
#endif /* #ifdef OBIGO_Q05A */
    SetProtocolEventHandler(srv_brw_settings_set_profile_cnf, MSG_ID_WAP_BAM_SET_PROFILE_CNF);

#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
    SetProtocolEventHandler(
        srv_brw_get_recent_pages_list_start_cnf,
        MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_START_CNF);
    SetProtocolEventHandler(
        (PsFuncPtr) srv_brw_get_recent_pages_list_continue_cnf,
        MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_CONTINUE_CNF);
    SetProtocolEventHandler((PsFuncPtr) srv_brw_get_recent_page_cnf, MSG_ID_WAP_BAM_RECENT_PAGE_CNF);
#endif
    SetProtocolEventHandler(srv_brw_status_ind, MSG_ID_WAP_BAM_STATUS_IND);
    SetProtocolEventHandler(srv_brw_error_ind, MSG_ID_WAP_BAM_ERROR_IND);
    SetProtocolEventHandler(srv_brw_document_info_ind, MSG_ID_WAP_BAM_DOCUMENT_INFO_IND);
	/* for title of a rendered page */
    SetProtocolEventHandler(srv_brw_notify_app_ind, MSG_ID_WAP_BAM_NOTIFY_APP_IND);
#ifndef SLIM_WAP_MMS
    SetProtocolEventHandler((PsFuncPtr) srv_brw_ren_page_do_element_ind, MSG_ID_WAP_BAM_DO_ELEMENTS_IND);
#endif
    SetProtocolEventHandler(srv_brw_page_element_focused_ind, MSG_ID_WAP_BAM_ELEMENT_FOCUSED_IND);
    
    /* This handler function can be used to show different security icons depending on the different
       security classes received in this function */

/*#ifdef WAP_SEC_SUPPORT
    
    SetProtocolEventHandler(srv_brw_set_security_class_ind, MSG_ID_WAP_BAM_SET_SEC_CLASS_IND);
#endif */
#ifdef OBIGO_Q05A 
    SetProtocolEventHandler(srv_brw_wtai_tel_ind, MSG_ID_WAP_BAM_WTAI_TEL_IND);
    SetProtocolEventHandler(srv_brw_wtai_pb_ind, MSG_ID_WAP_BAM_WTAI_PB_IND);
#endif /* OBIGO_Q05A */
    SetProtocolEventHandler(srv_brw_uri_request_ind, MSG_ID_WAP_BAM_URI_REQUEST_IND);
    SetProtocolEventHandler(srv_brw_wait_user_action_ind, MSG_ID_WAP_BAM_WAIT_USER_ACTION_IND);
    SetProtocolEventHandler(srv_brw_ren_page_show_auth_dialog_ind, MSG_ID_WAP_BAM_SHOW_AUTH_DIALOG_IND);
    SetProtocolEventHandler(srv_brw_bam_ready_ind, MSG_ID_WAP_BAM_READY_IND);
    /* BAM SAPs */

    /* BROWSER SECURITY SAPs */
#ifdef WAP_SEC_SUPPORT
#ifdef OBIGO_Q05A
    SetProtocolEventHandler(srv_brw_get_session_info_rsp, MSG_ID_WPS_SEC_GET_SESSION_INFO_RSP);
	SetProtocolEventHandler(srv_brw_get_current_certificate_rsp, MSG_ID_WPS_SEC_GET_CURRENT_CERT_RSP);
#endif /* OBIGO_Q05A */
    SetProtocolEventHandler(srv_brw_get_trusted_certificate_ids_rsp, MSG_ID_WPS_SEC_GET_CERT_IDS_RSP);
    SetProtocolEventHandler(srv_brw_get_trusted_certificate_rsp, MSG_ID_WPS_SEC_GET_CERT_RSP);
    SetProtocolEventHandler(srv_brw_trusted_certificates_delete_rsp, MSG_ID_WPS_SEC_DELETE_CA_CERT_RSP);
    SetProtocolEventHandler(srv_brw_sec_confirm_dialog_ind, MSG_ID_WPS_SEC_SHOW_CONFIRM_DIALOG_IND);
#endif /* WAP_SEC_SUPPORT */ 
    SetProtocolEventHandler(srv_brw_settings_clear_data_rsp, MSG_ID_WPS_CLEAR_RSP);
    /* BROWSER SECURITY SAPs */

    /* OTHER SAPs */
#if 0
#ifdef __MMI_VBOOKMARK__
/* under construction !*/
#endif
#endif //0
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    SetProtocolEventHandler(srv_brw_bkgrd_downloads_ind, MSG_ID_MMI_DA_DOWNLOAD_INFO_IND);
#endif 
    SetProtocolEventHandler(srv_brw_wap_browser_startup_req, MSG_ID_WAP_BROWSER_STARTUP_REQ);
#ifdef __SAT__
    SetProtocolEventHandler(srv_brw_sat_launch_browser_req, MSG_ID_WAP_MMI_LAUNCH_BROWSER_REQ);
#endif 
    SetProtocolEventHandler((PsFuncPtr) srv_brw_jam_get_user_agent_req, MSG_ID_WAP_GET_USER_AGENT_REQ);
    /* OTHER SAPs */
    /* File Upload */
#ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
    SetProtocolEventHandler(srv_brw_select_file_ind, MSG_ID_WAP_BAM_SELECT_FILE_IND);
#endif /* #ifdef OBIGO_Q05A */
#ifdef __COSMOS_MMI_PACKAGE__
    SetProtocolEventHandler(srv_brw_wmls_dialog_req, MSG_ID_WAP_BAM_WMLS_CREATE_DIALOGUE_REQ);
    SetProtocolEventHandler(srv_brw_bookmark_export_ind_hdlr, MSG_ID_SRV_BRW_BOOKMARK_EXPORT_IND);
#endif
#ifdef MMI_BRW_BEARER_SWITCH_SUPPORT
    SetProtocolEventHandler(srv_brw_release_sockets_rsp, MSG_ID_WAP_BAM_CONN_CLOSED_BY_NET_ACC_ID_RSP);
#endif
    SetProtocolEventHandler(srv_brw_open_bearer_ind_hdlr, MSG_ID_WAP_BAM_BEARER_OPEN_IND);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_event_hdlr_send_ilm
 * DESCRIPTION
 *  This function is used to compose ILM to be sent to BAM
 * PARAMETERS
 *  msg_id              [IN]        
 *  local_param_ptr     [IN]        
 *  peer_buf_ptr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_event_hdlr_send_ilm(kal_uint16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_send_ilm((oslModuleType)MOD_WAP, (oslMsgType)msg_id, (oslParaType*)local_param_ptr, (oslPeerBuffType*)peer_buf_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_event_hdlr_send_ilm_to_wps
 * DESCRIPTION
 *  This function is used to send ILM to WPS
 * PARAMETERS
 *  msg_id              [IN]        
 *  local_param_ptr     [IN]        
 *  peer_buf_ptr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_event_hdlr_send_ilm_to_wps(kal_uint16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_send_ilm((oslModuleType)MOD_WPS, (oslMsgType)msg_id, (oslParaType*)local_param_ptr, (oslPeerBuffType*)peer_buf_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_event_hdlr_send_ilm_to_mmi
 * DESCRIPTION
 *  This function is used to send ILM to MMI
 * PARAMETERS
 *  msg_id              [IN]        
 *  local_param_ptr     [IN]        
 *  peer_buf_ptr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_event_hdlr_send_ilm_to_mmi(kal_uint16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_send_ilm((oslModuleType)MOD_MMI, (oslMsgType)msg_id, (oslParaType*)local_param_ptr, (oslPeerBuffType*)peer_buf_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_notify_app_ind
 * DESCRIPTION
 *  Indication for updating the rendered page title.
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_notify_app_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_notify_app_ind_struct *localBuff_p = (wap_bam_notify_app_ind_struct*) msg;
	mmi_event_struct evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(localBuff_p);
	MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_BRW_UPDATE_TITLE);
    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p)
    {
        switch(localBuff_p->type)
        {
            case wap_bam_notify_app_set_title_string:
				strcpy((S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->title, (S8*) localBuff_p->title);	
                break;
            default:
                return;
        }
	MMI_FRM_CB_EMIT_EVENT((mmi_event_struct *)&evt);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_ren_page_show_auth_dialog_ind
 * DESCRIPTION
 *  API to handle Display Authentication dialog request
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_ren_page_show_auth_dialog_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_show_auth_dialog_ind_struct *localBuff_p = (wap_bam_show_auth_dialog_ind_struct*) msg;
	mmi_event_struct evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(localBuff_p);
	MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_BRW_SHOW_AUTH_DLG);
    if (g_srv_brw_cntx.http_auth_info_p == NULL)
    {
        g_srv_brw_cntx.http_auth_info_p = (srv_brw_show_auth_dialog_ind_struct*)
            OslMalloc(sizeof(srv_brw_show_auth_dialog_ind_struct));
    }
    g_srv_brw_cntx.http_auth_info_p->instance_id = localBuff_p->instance_id;
    g_srv_brw_cntx.http_auth_info_p->request_id = localBuff_p->request_id;
    g_srv_brw_cntx.http_auth_info_p->auth_type = localBuff_p->auth_type;
    strcpy((S8*) g_srv_brw_cntx.http_auth_info_p->username, (S8*) localBuff_p->username);
    strcpy((S8*) g_srv_brw_cntx.http_auth_info_p->password, (S8*) localBuff_p->password);
    MMI_FRM_CB_EMIT_EVENT((mmi_event_struct *)&evt);
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_create_instance_cnf
 * DESCRIPTION
 *  Call back for Handling create instance response
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_create_instance_cnf(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_create_instance_cnf_struct *localBuff_p = (wap_bam_create_instance_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(localBuff_p);
	  
    if (localBuff_p->error_code <= 0)
    {
		/* store instance_id, call for ADM to manage mem, init_app & 
		set_prof_req(send ILM to BAM) passing current settings */
        g_srv_brw_cntx.brw_instance_id = localBuff_p->instance_id;
        g_srv_brw_cntx.brw_adm_id = kal_adm_create(
                                    (char*)g_srv_brw_memory_pool,
                                    SRV_BRW_APP_POOL_SIZE ,
                                    NULL,
                                    KAL_FALSE);
        MMI_ASSERT(g_srv_brw_cntx.brw_adm_id);
		srv_brw_create_dynamic_service();
    #ifdef BRW_MEM_LEAK_DEBUG_MODE
        g_brw_mem_alloc_cntx = kal_adm_alloc(g_srv_brw_cntx.brw_adm_id, BRW_MEM_ALLOC_MAX_LIST_SIZE * sizeof(brw_mem_alloc_struct));
        memset(g_brw_mem_alloc_cntx, 0, BRW_MEM_ALLOC_MAX_LIST_SIZE * sizeof(brw_mem_alloc_struct));
    #endif /* BRW_MEM_LEAK_DEBUG_MODE */ 
    }
    g_srv_brw_cntx.is_create_instance_processing = MMI_FALSE;
    srv_brw_call_user_app_req_data(MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF, (U16)(localBuff_p->error_code), NULL);
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_delete_instance_cnf
 * DESCRIPTION
 *  Call back for Handling Delete instance response
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_delete_instance_cnf(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __SUPPORT_INFUSIO__
    S8 java_param[WAP_BAM_MAX_URL_LEN + 1];
#endif 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_srv_brw_cntx.brw_instance_id > 0)
    {
    #ifdef __COSMOS_MMI_PACKAGE__
        srv_brw_dynamic_context_deinit();
        if (g_srv_brw_memory_pool)
        {
        #ifdef OBIGO_Q03C_BROWSER
            wapadp_set_wap_app_mem(NULL,KAL_TRUE);
        #endif /* OBIGO_Q03C_BROWSER */
        }

    #ifdef OBIGO_Q03C_BROWSER
        wapadp_set_wap_app_mem(NULL,KAL_FALSE);
    #elif OBIGO_Q05A
        resetAppMemPool();
    #endif /* OBIGO_Q03C_BROWSER */
    #endif
        /* reset browser instance status */
        g_srv_brw_cntx.brw_instance_id = 0;
    #ifndef __COSMOS_MMI_PACKAGE__
        g_srv_brw_memory_pool = NULL;
    #endif /* #ifdef __COSMOS_MMI_PACKAGE__ */
    }
    srv_brw_call_user_app_req_data(MSG_ID_WAP_BAM_DELETE_INSTANCE_CNF, (U16)(SRV_BRW_ERROR_OK), NULL);
}

#ifndef SLIM_WAP_MMS
/*****************************************************************************
 * FUNCTION
 *  srv_brw_ren_page_do_element_ind
 * DESCRIPTION
 *  Handler for Do - Elements Indication from BAM
 * PARAMETERS
 *  msg         [IN]        
 *  mod_src     [IN]        
 *  ilm_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_ren_page_do_element_ind(void *msg, int mod_src, void *ilm_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;
    U16 peerBuffLen;
    wap_bam_do_elements_ind_struct *localBuff_p = (wap_bam_do_elements_ind_struct*) msg;
    wap_bam_do_elements_struct *peerBuff_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(localBuff_p);
    MMI_ASSERT(ilm_p);
    MMI_ASSERT(((ilm_struct*) ilm_p)->peer_buff_ptr);

    peerBuff_p = (wap_bam_do_elements_struct*) get_pdu_ptr(((ilm_struct*) ilm_p)->peer_buff_ptr, &peerBuffLen);

    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->do_element_count = peerBuff_p->num_elements;


    srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->do_element_list));

    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->do_element_list = (srv_brw_do_element_struct*)
        srv_brw_malloc(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->do_element_count * sizeof(srv_brw_do_element_struct));

    for (index = 0; index < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->do_element_count; index++)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->do_element_list[index].element_id = peerBuff_p->elements[index].element_id;
        strcpy(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->do_element_list[index].label, peerBuff_p->elements[index].label);
        strcpy(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->do_element_list[index].event_type, peerBuff_p->elements[index].event_type);
    }
}
#endif

#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_brw_save_as_stored_page_cnf
 * DESCRIPTION
 *  This func is used for handling save as stored page confirmation
 * PARAMETERS
 *  msg         [IN]        
 *  mod_src     [IN]        
 *  ilm_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_save_as_stored_page_cnf(void *msg, int mod_src, void *ilm_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 peerBuffLen;
    wap_bam_save_page_cnf_struct *localBuff_p = (wap_bam_save_page_cnf_struct*) msg;
    wap_bam_saved_page_struct *peerBuff_p = NULL;
	U16 error = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(localBuff_p);
    MMI_ASSERT(ilm_p);

    if (((ilm_struct*) ilm_p)->peer_buff_ptr)
    {
        peerBuff_p = (wap_bam_saved_page_struct*) get_pdu_ptr(((ilm_struct*) ilm_p)->peer_buff_ptr, &peerBuffLen);
    }
	if ((localBuff_p->error_code) <= 0)
	{
		switch (g_srv_brw_cntx.sap_msg_id)
		{
			case MSG_ID_WAP_BAM_GET_SAVED_PAGE_REQ:
			{
				if (!peerBuff_p)
				{
					error = WAP_BAM_ERROR_SAVED_PAGES_FAILED;
				}
				else
				{
					if (!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_properties_p)
					{
						g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_properties_p =
							(srv_brw_saved_page_struct*) srv_brw_malloc(sizeof(srv_brw_saved_page_struct));
					}
					g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_properties_p->date = peerBuff_p->date;
					g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_properties_p->data_size = peerBuff_p->data_size;
					strcpy((S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_properties_p->label, (S8*) peerBuff_p->label);
					strcpy((S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_properties_p->url, (S8*) peerBuff_p->url);
				}
				break;
			}
			default:
			{
				break;
			}
		}
    }
    if (g_srv_brw_cntx.sap_msg_id != MSG_ID_WAP_BAM_LOAD_SAVED_PAGE_REQ)
    {
        if(error)
        {
            srv_brw_call_user_app_req_data(MSG_ID_WAP_BAM_SAVE_PAGE_CNF, (U16)error, NULL);
        }
        else
        {
            srv_brw_call_user_app_req_data(MSG_ID_WAP_BAM_SAVE_PAGE_CNF, (U16)(localBuff_p->error_code), NULL);
        }
    }
}
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */
/*****************************************************************************
 * FUNCTION
 *  srv_brw_status_ind
 * DESCRIPTION
 *  This func is used for handling rendering status update indication
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_status_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_status_ind_struct *localBuff_p = (wap_bam_status_ind_struct*) msg;
    U16 status;
	srv_brw_rendering_status_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(localBuff_p);
    if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isDeleteInsReqPending)
    {
        return;
    }

    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p == NULL)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p = (srv_brw_status_ind_struct*) srv_brw_malloc(sizeof(srv_brw_status_ind_struct));
		memset(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p,0,sizeof(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p));
    }
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p->upload_bytes_sent = localBuff_p->upload_bytes_sent;
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p->upload_bytes_total = localBuff_p->upload_bytes_total;
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p->document_bytes_total = localBuff_p->document_bytes_total;
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p->resources_number_of_downloaded = localBuff_p->resources_number_of_downloaded;
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p->resources_number_of_failed = localBuff_p->resources_number_of_failed;
	status = localBuff_p->status;
#ifdef __MMI_BRW_POST_SESSION_INFO__
    if (localBuff_p->resources_number_of_downloaded &&
        (localBuff_p->resources_number_of_downloaded > g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p->resources_number_of_downloaded))
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_bytes_downloaded += localBuff_p->resources_bytes;
    }
#endif /* __MMI_BRW_POST_SESSION_INFO__ */ 
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p->resources_number_of_downloaded = localBuff_p->resources_number_of_downloaded;
/********************************EMIT EVENT TO APP******************************/
    switch (localBuff_p->status)
    {
        case WAP_BAM_STATUS_START_TRANSACTION:
        {
			MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_BRW_RENDERING_STATUS_START_IND);
            if (!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isBrowserFetching)
            {
                g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isBrowserFetching = MMI_TRUE;
                /* holding the bearer while starting the transaction */
                if (!srv_brw_is_holding_bearer())
                {
                    srv_brw_set_bearer(MMI_TRUE);
                }
            #ifdef __MMI_BRW_POST_SESSION_INFO__
                if (!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p)
                {
                    if (!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->start_session_data_time)
                    {
                        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->start_session_data_time = srv_brw_malloc(sizeof(applib_time_struct));
                    }
                    applib_dt_get_rtc_time(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->start_session_data_time);
                }
            #endif /* __MMI_BRW_POST_SESSION_INFO__ */ 
            }
			evt.status = (U16)WAP_BAM_STATUS_START_TRANSACTION;
			evt.ptr = NULL;
			MMI_FRM_CB_EMIT_EVENT((mmi_event_struct *)&evt);
            break;
        }
        case WAP_BAM_STATUS_END_TRANSACTION:
        {
            MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_BRW_RENDERING_STATUS_END_IND);
            #ifdef __COSMOS_MMI_PACKAGE__
                g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcut_item_flag = MMI_FALSE;
            #endif
            if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isBrowserFetching && !g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isDeleteInsReqPending)
            {
				g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isBrowserFetching = MMI_FALSE;
                /* releasing the bearer if no page is being rendered or it is in release waiting state */
                if (srv_brw_is_holding_bearer() &&
                    (!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p || g_srv_brw_cntx.srv_brw_dynamic_cntx_p->need_bearer_release == MMI_TRUE))
                {
                    /* Release bearer only for following two cases: */
                    /* (1) if no external object transaction is active, or */
                    /* (2) if external object transaction is active && stop fetching is requested by the application itself */
                #ifndef __COSMOS_MMI_PACKAGE__
                    if (!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->ext_obj_trans_status ||
                        (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->ext_obj_trans_status &&
                         g_srv_brw_cntx.srv_brw_dynamic_cntx_p->need_bearer_release == MMI_TRUE))
                    {
                    #ifdef MMI_BRW_BEARER_SWITCH_SUPPORT
                        if(!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.is_switching_bearer)
                    #endif
                        {
                            srv_brw_set_bearer(MMI_FALSE);
                        }
                    }
                #endif
                    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->need_bearer_release == MMI_TRUE)
                    {
                        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->need_bearer_release = MMI_FALSE;
                    }
                }
            }
        #ifdef __MMI_BRW_POST_SESSION_INFO__
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_bytes_downloaded += localBuff_p->document_bytes_read;
            if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p->upload_bytes_total > 0)
            {
                g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_bytes_uploaded += g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p->upload_bytes_sent;
            }
        #endif /* __MMI_BRW_POST_SESSION_INFO__ */
			evt.status = (U16)WAP_BAM_STATUS_END_TRANSACTION;
			evt.ptr = NULL;
			MMI_FRM_CB_EMIT_EVENT((mmi_event_struct *)&evt);
            break;
        }
        case WAP_BAM_STATUS_TRANSACTION_STATUS:
        {
			MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_BRW_RENDERING_STATUS_CONTINUE_IND);
			evt.status = (U16)WAP_BAM_STATUS_TRANSACTION_STATUS;
			evt.ptr = (srv_brw_rendering_status_struct*)OslMalloc(sizeof(srv_brw_rendering_status_struct));
            memset(evt.ptr, 0, sizeof(srv_brw_rendering_status_struct));
			((srv_brw_rendering_status_struct*)evt.ptr)->document_bytes_read = localBuff_p->document_bytes_read;
			((srv_brw_rendering_status_struct*)evt.ptr)->document_number_of_requested = localBuff_p->document_number_of_requested;
			((srv_brw_rendering_status_struct*)evt.ptr)->document_number_of_downloaded = localBuff_p->document_number_of_downloaded;
			((srv_brw_rendering_status_struct*)evt.ptr)->document_number_of_failed = localBuff_p->document_number_of_failed;
			((srv_brw_rendering_status_struct*)evt.ptr)->resources_bytes = localBuff_p->resources_bytes;
			((srv_brw_rendering_status_struct*)evt.ptr)->resources_number_of_requested = localBuff_p->resources_number_of_requested;
			MMI_FRM_CB_EMIT_EVENT((mmi_event_struct *)&evt);
			OslMfree(evt.ptr);
            break;
        }
        case WAP_BAM_STATUS_EXTERNAL_OBJECT_START_TRANSACTION:
        {
            /* setting external object transaction status to true */
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->ext_obj_trans_status = MMI_TRUE;

            /* holding the bearer while starting the transaction */
            if (!srv_brw_is_holding_bearer())
            {
                srv_brw_set_bearer(MMI_TRUE);
            }
            break;
        }
        case WAP_BAM_STATUS_EXTERNAL_OBJECT_END_TRANSACTION:
        {
            /* setting external object transaction status to false */
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->ext_obj_trans_status = MMI_FALSE;
            break;
        }
        default:
        {
            break;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_settings_set_profile_cnf
 * DESCRIPTION
 *  This func is used for handling set profile confirmation
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_settings_set_profile_cnf(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_set_profile_cnf_struct *localBuff_p = (wap_bam_set_profile_cnf_struct*) msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(localBuff_p);

    if((localBuff_p->error_code) <= 0)
    {
    #ifdef __MMI_OP12_BRW_CLEAR_DATA_ON_SIM_CHANGE__
        if (g_srv_brw_cntx.clear_brw_data_flag)
        {
            g_srv_brw_cntx.clear_brw_data_flag = MMI_FALSE;
        }
    #endif /* __MMI_OP12_BRW_CLEAR_DATA_ON_SIM_CHANGE__ */
    }
    srv_brw_call_user_app_req_data(MSG_ID_WAP_BAM_SET_PROFILE_CNF, (U16)(localBuff_p->error_code), NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_bam_ready_ind_handler
 * DESCRIPTION
 *  This func is used for handling set profile confirmation
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_bam_ready_ind_handler(S32 user_data, U32 result, void *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_brw_cntx.sap_msg_id = 0;
#if (MMI_MAX_SIM_NUM >= 2)
    g_srv_brw_cntx.session_sim_id = SRV_BRW_ACTIVE_SIM_SETTING_TOTAL;
#endif
    if(result <= 0)
    {
		if (!g_srv_brw_cntx.isWapReady)
		{
			g_srv_brw_cntx.isWapReady = MMI_TRUE;
		#ifdef __MMI_OP12_BRW_CLEAR_DATA_ON_SIM_CHANGE__
			if (check_sim_status() == SMU_SIM_REPLACED)
			{
				g_srv_brw_cntx.clear_brw_data_flag = MMI_TRUE;
			}
			else
			{
				g_srv_brw_cntx.clear_brw_data_flag = MMI_FALSE;
			}
		#endif /* __MMI_OP12_BRW_CLEAR_DATA_ON_SIM_CHANGE__ */ 
			return;
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_active_profile_change_handler
 * DESCRIPTION
 *  This func is the callback function passed to the service while calling the
 * set profile req function so that the tasks that need to be performed when
 * the set profile confirmation is received (like calling the callback function
 * of the profile)
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_active_profile_change_handler(S32 user_data, U32 result, void *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(result > 0)
    {
        g_srv_brw_cntx.actv_prof_changed_cb(SRV_WAP_PROF_ERR);
        return;
    }
    if (srv_brw_is_holding_bearer())
    {
        srv_brw_set_bearer(MMI_FALSE);
    }
    g_srv_brw_cntx.actv_prof_changed_cb(SRV_WAP_PROF_SUCCESS);
}


#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_stored_pages_list_start_cnf
 * DESCRIPTION
 *  This func is used for handling response corresponding to Stored pages list
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_get_stored_pages_list_start_cnf(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_saved_pages_list_start_cnf_struct *localBuff_p = (wap_bam_get_saved_pages_list_start_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(localBuff_p);
	
	if (localBuff_p->error_code > 0)
    {
        srv_brw_call_user_app_req_data(MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_CONTINUE_CNF, (U16)(localBuff_p->error_code), NULL);
    }
	else
	{
		if(localBuff_p->num_items > 0)
		{
			g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_list_item_count = (U8) localBuff_p->num_items;
			g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_pages_list_p = srv_brw_malloc(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_list_item_count * sizeof(srv_brw_saved_page_list_struct));
			srv_brw_get_stored_pages_list_continue_req(0);
		}
		else
		{
			srv_brw_list_rsp_struct *rsp_data = (srv_brw_list_rsp_struct*) 
								OslMalloc(sizeof(srv_brw_list_rsp_struct));
			rsp_data->num_count = (U16)localBuff_p->num_items;
			srv_brw_call_user_app_req_data(MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_CONTINUE_CNF, (U16)(localBuff_p->error_code), (void*) rsp_data);
			OslMfree(rsp_data);
			rsp_data = NULL;
		}
	}
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_stored_pages_get_saved_pages_list_continue_cnf
 * DESCRIPTION
 *  This func is used to receive the response corresponding to save pages list
 * PARAMETERS
 *  msg         [IN]        
 *  mod_src     [IN]        
 *  ilm_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_get_stored_pages_list_continue_cnf(void *msg, int mod_src, void *ilm_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;

    U32 titleLen;
    S8 *peerBuff_p;
    U16 peerBuffLen;
    wap_bam_get_saved_pages_list_continue_cnf_struct *localBuff_p =
        (wap_bam_get_saved_pages_list_continue_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(localBuff_p);
    MMI_ASSERT(ilm_p);
    MMI_ASSERT(((ilm_struct*) ilm_p)->peer_buff_ptr);

    if (localBuff_p->error_code > 0)
    {
        srv_brw_call_user_app_req_data(MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_CONTINUE_CNF, (U16)(localBuff_p->error_code), NULL);
    }
	else
	{
		peerBuff_p = (S8*) get_pdu_ptr(((ilm_struct*) ilm_p)->peer_buff_ptr, &peerBuffLen);

		for (index = localBuff_p->start_index; index < localBuff_p->num_items + localBuff_p->start_index; index++)
		{
			titleLen = bam_get_bits((char*)peerBuff_p, sizeof(U32) * 8);
			g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_pages_list_p[index].name = srv_brw_malloc((titleLen + 1) * sizeof(U8));
			strncpy(
				(S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_pages_list_p[index].name,
				(S8*) peerBuff_p + SRV_BRW_PEER_BUFF_TITLE_LEN_BYTES_COUNT,
				titleLen);
			g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_pages_list_p[index].name[titleLen] = '\0';
			peerBuff_p += titleLen + SRV_BRW_PEER_BUFF_TITLE_LEN_BYTES_COUNT;
		}
		if (index < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_list_item_count)
		{
			srv_brw_get_stored_pages_list_continue_req(index);
		}
		else
		{
			srv_brw_list_rsp_struct *rsp_data = (srv_brw_list_rsp_struct*) 
							OslMalloc(sizeof(srv_brw_list_rsp_struct));
			rsp_data->num_count = (U16)g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_list_item_count;
			srv_brw_call_user_app_req_data(MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_CONTINUE_CNF, (U16)(localBuff_p->error_code), rsp_data);
			OslMfree(rsp_data);
			rsp_data = NULL;
		}
	}
}
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_resource_list_start_cnf
 * DESCRIPTION
 *  This func is used for handling resource list start confirmation
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_get_resource_list_start_cnf(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_resources_list_start_cnf_struct *localBuff_p = (wap_bam_get_resources_list_start_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(localBuff_p);

    if (localBuff_p->error_code > 0)
    {
        srv_brw_call_user_app_req_data(MSG_ID_WAP_BAM_GET_RESOURCES_LIST_CONTINUE_CNF, (U16)(localBuff_p->error_code), NULL);
    }
	else
	{
		if (localBuff_p->num_res > 0)
		{
			g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list_count = localBuff_p->num_res;
			g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list = srv_brw_malloc(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list_count * sizeof(srv_brw_dynamic_list_struct));
			srv_brw_get_resource_list_continue_req(0);
		}
		else
		{
			srv_brw_list_rsp_struct *rsp_data = (srv_brw_list_rsp_struct*) 
								OslMalloc(sizeof(srv_brw_list_rsp_struct));
			rsp_data->num_count = (U16)localBuff_p->num_res;
			srv_brw_call_user_app_req_data(MSG_ID_WAP_BAM_GET_RESOURCES_LIST_CONTINUE_CNF, (U16)(localBuff_p->error_code), rsp_data);
			OslMfree(rsp_data);
			rsp_data = NULL;
		}
	}
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_resource_list_continue_cnf
 * DESCRIPTION
 *  This func is used for handling resource list continue confirmation
 * PARAMETERS
 *  msg         [IN]        
 *  mod_src     [IN]        
 *  ilm_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_get_resource_list_continue_cnf(void *msg, int mod_src, void *ilm_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    U32 titleLen;
    U16 peerBuffLen;
    S8 *peerBuff_p;
    wap_bam_get_resources_list_continue_cnf_struct *localBuff_p =
        (wap_bam_get_resources_list_continue_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(localBuff_p);
    MMI_ASSERT(ilm_p);
    MMI_ASSERT(((ilm_struct*) ilm_p)->peer_buff_ptr);

    if (localBuff_p->error_code > 0)
    {
        srv_brw_call_user_app_req_data(MSG_ID_WAP_BAM_GET_RESOURCES_LIST_CONTINUE_CNF, (U16)(localBuff_p->error_code), NULL);
    }
	else
	{
		peerBuff_p = (S8*) get_pdu_ptr(((ilm_struct*) ilm_p)->peer_buff_ptr, &peerBuffLen);

		for (index = localBuff_p->start_index; index < localBuff_p->num_res + localBuff_p->start_index; index++)
		{
			g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].type = bam_get_bits((char*)peerBuff_p, sizeof(U32) * 8);
			peerBuff_p += SRV_BRW_PEER_BUFF_OBJ_TYPE_LEN_BYTES_COUNT;
			titleLen = bam_get_bits((char*)peerBuff_p, sizeof(U32) * 8);
			g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].name = srv_brw_malloc((titleLen + 1) * sizeof(U8));
			strncpy(
				(S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].name,
				(S8*) peerBuff_p + SRV_BRW_PEER_BUFF_TITLE_LEN_BYTES_COUNT,
				titleLen);
			g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].name[titleLen] = '\0';
			peerBuff_p += titleLen + SRV_BRW_PEER_BUFF_TITLE_LEN_BYTES_COUNT;
			g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].host = NULL;
		}
		if (index < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list_count)
		{
			srv_brw_get_resource_list_continue_req(index);
		}
		else
		{
			srv_brw_list_rsp_struct *rsp_data = (srv_brw_list_rsp_struct*) 
							OslMalloc(sizeof(srv_brw_list_rsp_struct));
			rsp_data->num_count = (U16)g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list_count;
			srv_brw_call_user_app_req_data(MSG_ID_WAP_BAM_GET_RESOURCES_LIST_CONTINUE_CNF, (U16)(localBuff_p->error_code), rsp_data);
			OslMfree(rsp_data);
			rsp_data = NULL;
		}
	}
}
#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_resource_cnf
 * DESCRIPTION
 *  This func is used for handling resource info confirmation
 * PARAMETERS
 *  msg         [IN]        
 *  mod_src     [IN]        
 *  ilm_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_get_resource_cnf(void *msg, int mod_src, void *ilm_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 peerBuffLen;
    wap_bam_get_resource_cnf_struct *localBuff_p = (wap_bam_get_resource_cnf_struct*) msg;
    wap_bam_resource_item_struct *peerBuff_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(localBuff_p);
    MMI_ASSERT(ilm_p);
    MMI_ASSERT(((ilm_struct*) ilm_p)->peer_buff_ptr);

    if ((localBuff_p->error_code) <= 0)
    {
		peerBuff_p = (wap_bam_resource_item_struct*) get_pdu_ptr(((ilm_struct*) ilm_p)->peer_buff_ptr, &peerBuffLen);

		if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_res_item_info_p == NULL)
		{
			g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_res_item_info_p =
				(srv_brw_resource_item_struct*) srv_brw_malloc(sizeof(srv_brw_resource_item_struct));
		}

		g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_res_item_info_p->size = peerBuff_p->size;
		strcpy((S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_res_item_info_p->title, (S8*) peerBuff_p->title);
		strcpy((S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_res_item_info_p->cache_file, (S8*) peerBuff_p->cache_file);
    }
    srv_brw_call_user_app_req_data(MSG_ID_WAP_BAM_GET_RESOURCE_CNF, (U16)(localBuff_p->error_code), NULL);
                                                   
}
#endif /* #ifdef OBIGO_Q05A */                                                  
 /*****************************************************************************
 * FUNCTION
 *  srv_brw_document_info_ind
 * DESCRIPTION
 *  This func is used for handling document info ind while page rendering
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_document_info_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_document_info_ind_struct *localBuff_p = (wap_bam_document_info_ind_struct*) msg;
    U8 title_temp[NVRAM_BRW_ADDRESS_HISTORY_MAX_TITLE_LENGTH * ENCODING_LENGTH];
    S16 error;
	mmi_event_struct evt;
#ifdef __COSMOS_MMI_PACKAGE__
#ifndef __MMI_BRW_SLIM__
    nvram_brw_local_shortcuts_item_struct *local_shortcut_item = NULL;
#endif
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(localBuff_p);
	MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_BRW_DOC_INFO_IND);
    if (!(localBuff_p->flags & WAP_BAM_INFO_FLAG_MAIN_WINDOW) && (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p != NULL))
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->flags = localBuff_p->flags;
        return;
    }
    if (!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p =
            (srv_brw_document_info_ind_struct*) srv_brw_malloc(sizeof(srv_brw_document_info_ind_struct));
    }

    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->flags = localBuff_p->flags;
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->protocol = localBuff_p->protocol;
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->size = localBuff_p->size;
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->security_id = localBuff_p->security_id;
    strcpy((S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->url, (S8*) localBuff_p->url);
    strcpy((S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->title, (S8*) localBuff_p->title);


#ifndef SLIM_WAP_MMS
    srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->do_element_list));
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->do_element_count = 0;
#endif
#ifdef OBIGO_Q03C
    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p)
    {
        memset(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p, 0, sizeof(srv_brw_element_focused_ind_struct));
    }
#endif /* OBIGO_Q03C */
#ifdef __MMI_BRW_ADVANCED_APP_FEATURES__
    /* Writing into NMRAM the last web address */
    WriteRecord(
        NVRAM_EF_BRW_LAST_WEB_ADDR_LID,
        1,
        &localBuff_p->url,
        NVRAM_EF_BRW_LAST_WEB_ADDR_SIZE,
        &error);
#endif /* __MMI_BRW_ADVANCED_APP_FEATURES__ */
    /* Update Address list title */
#ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__
    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_flag)
    {
        mmi_chset_utf8_to_ucs2_string(
            (U8*) title_temp,
            NVRAM_BRW_ADDRESS_HISTORY_MAX_TITLE_LENGTH * ENCODING_LENGTH,
            (U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->title);
        srv_brw_address_list_update_data(SRV_BRW_LIST_ACTION_UPDATE_TITLE_ONLY ,title_temp);
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_flag = MMI_FALSE;
    }
#endif /* __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__ */
#ifdef __COSMOS_MMI_PACKAGE__
    mmi_chset_utf8_to_ucs2_string(
        (U8*) title_temp,
        NVRAM_BRW_ADDRESS_HISTORY_MAX_TITLE_LENGTH * ENCODING_LENGTH,
        (U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->title);

    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcut_item_flag)
    {
        if(srv_phb_check_ucs2_character((U16*) title_temp))
        {
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[g_srv_brw_cntx.srv_brw_dynamic_cntx_p->launched_global_shortcut_index].title.dcs = SRV_BRW_DCS_UCS;
			memset(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[g_srv_brw_cntx.srv_brw_dynamic_cntx_p->launched_global_shortcut_index].title.title, 0, NVRAM_BRW_ADDRESS_HISTORY_MAX_TITLE_LENGTH);
			mmi_ucs2ncpy(
				(S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[g_srv_brw_cntx.srv_brw_dynamic_cntx_p->launched_global_shortcut_index].title.title,
				(S8*) title_temp,
				NVRAM_BRW_ADDRESS_HISTORY_MAX_TITLE_LENGTH / ENCODING_LENGTH);

        }
        else
        {
			g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[g_srv_brw_cntx.srv_brw_dynamic_cntx_p->launched_global_shortcut_index].title.dcs = SRV_BRW_DCS_ASCII;
			memset(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[g_srv_brw_cntx.srv_brw_dynamic_cntx_p->launched_global_shortcut_index].title.title, 0, NVRAM_BRW_ADDRESS_HISTORY_MAX_TITLE_LENGTH);
			mmi_ucs2_n_to_asc(
				(S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[g_srv_brw_cntx.srv_brw_dynamic_cntx_p->launched_global_shortcut_index].title.title,
				(S8*) title_temp,
				mmi_ucs2strlen((S8*) title_temp) * ENCODING_LENGTH);
        }
        strncpy((S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[g_srv_brw_cntx.srv_brw_dynamic_cntx_p->launched_global_shortcut_index].url, (S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->url, NVRAM_BRW_ADDRESS_HISTORY_MAX_URL_LENGTH);
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[g_srv_brw_cntx.srv_brw_dynamic_cntx_p->launched_global_shortcut_index].time = srv_brw_get_current_utc_time();
        srv_brw_global_shortcuts_list_update_data();
    }
#ifndef __MMI_BRW_SLIM__
    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcut_item_flag)
    {
        local_shortcut_item = (nvram_brw_local_shortcuts_item_struct*) srv_brw_malloc(sizeof(nvram_brw_local_shortcuts_item_struct));
        memset(local_shortcut_item, 0, sizeof(nvram_brw_local_shortcuts_item_struct));
        strncpy((S8*) local_shortcut_item->url, (S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->url, NVRAM_BRW_ADDRESS_HISTORY_MAX_URL_LENGTH);
        if(srv_phb_check_ucs2_character((U16*) title_temp))
        {
            local_shortcut_item->title.dcs = SRV_BRW_DCS_UCS;
			mmi_ucs2ncpy(
				(S8*) local_shortcut_item->title.title,
				(S8*) title_temp,
				NVRAM_BRW_ADDRESS_HISTORY_MAX_TITLE_LENGTH / ENCODING_LENGTH);
        }
        else
        {
			local_shortcut_item->title.dcs = SRV_BRW_DCS_ASCII;
			mmi_ucs2_n_to_asc(
				(S8*) local_shortcut_item->title.title,
				(S8*) title_temp,
				mmi_ucs2strlen((S8*) title_temp) * ENCODING_LENGTH);
        }
        local_shortcut_item->points = 1;
        local_shortcut_item->time = srv_brw_get_current_utc_time();
        srv_brw_local_shortcuts_list_add_item(local_shortcut_item);
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcut_item_flag = MMI_FALSE;
        srv_brw_free(local_shortcut_item);
    }
#endif /* #ifndef __MMI_BRW_SLIM__ */
#endif
   MMI_FRM_CB_EMIT_EVENT((mmi_event_struct *)&evt);
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_page_element_focused_ind
 * DESCRIPTION
 *  This func is used for handling element focus event on a rendered page
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_page_element_focused_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_element_focused_ind_struct *localBuff_p = (wap_bam_element_focused_ind_struct*) msg;
#ifdef __COSMOS_MMI_PACKAGE__
    mmi_event_struct evt;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(localBuff_p);

    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p == NULL)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p =
            (srv_brw_element_focused_ind_struct*) srv_brw_malloc(sizeof(srv_brw_element_focused_ind_struct));
    }

    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p->type = localBuff_p->type;
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p->size = localBuff_p->size;
    strcpy((S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p->title, (S8*) localBuff_p->title);
    strcpy((S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p->url, (S8*) localBuff_p->url);
    strcpy((S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p->object_filePath, (S8*) localBuff_p->object_filePath);

#ifdef __COSMOS_MMI_PACKAGE__
    if(localBuff_p->type == WAP_BAM_FOCUSED_ELEMENT_IMAGE_LONG_TAP)
    {
        strcpy((S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p->url, (S8*) localBuff_p->object_url);
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_BRW_ELEMENT_FOCUSSED_IND);
        MMI_FRM_CB_EMIT_EVENT((mmi_event_struct *)&evt);
    }
#endif
}

#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_recent_pages_list_start_cnf
 * DESCRIPTION
 *  This func is used for handling recent pages list start confirmation
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_get_recent_pages_list_start_cnf(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_recent_pages_list_start_cnf_struct *localBuff_p =
        (wap_bam_get_recent_pages_list_start_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(localBuff_p);

    if (localBuff_p->error_code > 0)
    {
        srv_brw_call_user_app_req_data(MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_CONTINUE_CNF, (U16)(localBuff_p->error_code), NULL);
    }
    else
    {
        if (localBuff_p->num_item > 0)
        {
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list_count = localBuff_p->num_item;
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list = srv_brw_malloc(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list_count * sizeof(srv_brw_dynamic_list_struct));
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_list = srv_brw_malloc(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list_count * sizeof(srv_brw_recent_page_list_struct));
            srv_brw_get_recent_pages_list_continue_req(0);
        }
        else
        {
			srv_brw_list_rsp_struct *rsp_data = (srv_brw_list_rsp_struct*) 
								OslMalloc(sizeof(srv_brw_list_rsp_struct));
			rsp_data->num_count = (U16)localBuff_p->num_item;
			srv_brw_call_user_app_req_data(MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_CONTINUE_CNF, (U16)(localBuff_p->error_code), rsp_data);
			OslMfree(rsp_data);
			rsp_data = NULL;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_recent_pages_list_continue_cnf
 * DESCRIPTION
 *  This func is used for handling recent page list continue confirmation
 * PARAMETERS
 *  msg         [IN]        
 *  mod_src     [IN]        
 *  ilm_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_get_recent_pages_list_continue_cnf(void *msg, int mod_src, void *ilm_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    U32 titleLen;
    U16 peerBuffLen;
    S8 *peerBuff_p;
    wap_bam_get_recent_pages_list_continue_cnf_struct *localBuff_p =
        (wap_bam_get_recent_pages_list_continue_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(localBuff_p);
    MMI_ASSERT(ilm_p);
    MMI_ASSERT(((ilm_struct*) ilm_p)->peer_buff_ptr);

    if (localBuff_p->error_code > 0)
    {
        srv_brw_call_user_app_req_data(MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_CONTINUE_CNF, (U16)(localBuff_p->error_code), NULL);
    }
	else
	{
		peerBuff_p = (S8*) get_pdu_ptr(((ilm_struct*) ilm_p)->peer_buff_ptr, &peerBuffLen);
		for (index = localBuff_p->start_index; (index < localBuff_p->num_items + localBuff_p->start_index) &&
            (index < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list_count); index++)
		{
			titleLen = bam_get_bits((char*)peerBuff_p, sizeof(U32) * 8);
			g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].name = srv_brw_malloc((titleLen + 1) * sizeof(U8));
			strncpy(
				(S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].name,
				(S8*) peerBuff_p + SRV_BRW_PEER_BUFF_TITLE_LEN_BYTES_COUNT,
				titleLen);
			g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].name[titleLen] = '\0';
			peerBuff_p += (titleLen + SRV_BRW_PEER_BUFF_TITLE_LEN_BYTES_COUNT);
#ifdef __COSMOS_MMI_PACKAGE__
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].type = bam_get_bits((char*)peerBuff_p, sizeof(U32) * 8);
            peerBuff_p += SRV_BRW_PEER_BUFF_TITLE_LEN_BYTES_COUNT;
#endif /* __COSMOS_MMI_PACKAGE__ */

#ifdef OBIGO_Q05A
			if (g_srv_brw_cntx.sorting_method == WAP_BAM_RECENT_PAGE_SORT_OPTION_HOST)
			{
				titleLen = bam_get_bits(peerBuff_p, sizeof(U32) * 8);
				g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].host = srv_brw_malloc((titleLen + 1) * sizeof(U8));
				strncpy(
					(S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].host,
					(S8*) peerBuff_p + SRV_BRW_PEER_BUFF_TITLE_LEN_BYTES_COUNT,
					titleLen);
				g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].host[titleLen] = '\0';
				peerBuff_p += titleLen + SRV_BRW_PEER_BUFF_TITLE_LEN_BYTES_COUNT;
			}
			else
#endif /* #ifdef OBIGO_Q05A */ 
			{
				g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].host = NULL;
			}
		}
		if (index < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list_count)
		{
			srv_brw_get_recent_pages_list_continue_req(index);
		}
		else
		{
			srv_brw_list_rsp_struct *rsp_data = (srv_brw_list_rsp_struct*) 
							OslMalloc(sizeof(srv_brw_list_rsp_struct));
			rsp_data->num_count = (U16)g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list_count;
			srv_brw_call_user_app_req_data(MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_CONTINUE_CNF, (U16)(localBuff_p->error_code), rsp_data);
			OslMfree(rsp_data);
			rsp_data = NULL;
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_recent_page_cnf
 * DESCRIPTION
 *  This func is used for handling recent page info response
 * PARAMETERS
 *  msg         [IN]        
 *  mod_src     [IN]        
 *  ilm_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_get_recent_page_cnf(void *msg, int mod_src, void *ilm_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 peerBuffLen;
    wap_bam_recent_page_cnf_struct *localBuff_p = (wap_bam_recent_page_cnf_struct*) msg;
    wap_bam_recent_page_struct *peerBuff_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(localBuff_p);
    MMI_ASSERT(ilm_p);

#ifdef __MMI_OP12_BRW_CLEAR_DATA_ON_SIM_CHANGE__
    if (g_srv_brw_cntx.clear_brw_data_flag && g_srv_brw_cntx.sap_msg_id == MSG_ID_WAP_BAM_DELETE_ALL_RECENT_PAGES_REQ)
    {
        return;
    }
#endif /* __MMI_OP12_BRW_CLEAR_DATA_ON_SIM_CHANGE__ */ 
	if ((localBuff_p->error_code) <= 0)
	{
		switch (g_srv_brw_cntx.sap_msg_id)
		{
			case MSG_ID_WAP_BAM_DELETE_ALL_RECENT_PAGES_REQ:
			{
			 /********************************APP CALLBACK***********************************/    
				break;
			}
			case MSG_ID_WAP_BAM_GET_RECENT_PAGE_REQ:
			{
				MMI_ASSERT(((ilm_struct*) ilm_p)->peer_buff_ptr);
				peerBuff_p =
					(wap_bam_recent_page_struct*) get_pdu_ptr(((ilm_struct*) ilm_p)->peer_buff_ptr, &peerBuffLen);
				if (!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_info_p)
				{
					g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_info_p =
						(srv_brw_recent_page_struct*) srv_brw_malloc(sizeof(srv_brw_recent_page_struct));
				}
				strcpy((S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_info_p->title, (S8*) peerBuff_p->title);
				strcpy((S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_info_p->url, (S8*) peerBuff_p->url);
				break;
			}
			default:
			{
				break;
			}
		}
	}
	if(g_srv_brw_cntx.sap_msg_id != MSG_ID_WAP_BAM_LOAD_RECENT_PAGE_REQ)
	{
		srv_brw_call_user_app_req_data(MSG_ID_WAP_BAM_RECENT_PAGE_CNF, (U16)(localBuff_p->error_code), NULL);
	}
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_recent_pages_list_continue_req
 * DESCRIPTION
 *  API to send recent page list continue request.
 * PARAMETERS
 *  start_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_get_recent_pages_list_continue_req(U32 start_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_recent_pages_list_continue_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr =
        (wap_bam_get_recent_pages_list_continue_req_struct*)
        OslConstructDataPtr(sizeof(wap_bam_get_recent_pages_list_continue_req_struct));

    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;
    myMsgPtr->start_index = start_index;

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_CONTINUE_REQ, myMsgPtr, NULL);
}

#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  srv_brw_recent_page_host_delete_callback
 * DESCRIPTION
 *  This is the callback function send to the service for the recent page 
 * deletion when the Application had called to delete a selected host so that
 * other recent pages under that host could be deleted before calling the 
 * callback of the Browser Application
 * PARAMETERS
 *  user_data   [IN]
 *  result      [IN]
 *  obj         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_recent_page_host_delete_callback(S32 user_data, U32 result, void *obj)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_act_req_struct delete_obj = {0};
	srv_brw_list_element_req_struct data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_host_delete_callback);
    if (result > 0)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_host_delete_callback(0, result, obj);
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_host_delete_callback = NULL;
    }

    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_host_delete_count > 0)
    {
        delete_obj.rsp_callback = srv_brw_recent_page_host_delete_callback;
        data.index = srv_brw_recent_page_get_actual_index(--g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_host_delete_count);
        delete_obj.req_data = (void*)&data;
        srv_brw_delete_recent_page_req(&delete_obj);
    }
    /* if recent page list is empty then delete the selected host(called from 'Delete All') */
    else if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_host_delete_count == 0)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_host_delete_callback(0, result, obj);
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_host_delete_callback = NULL;
    }
}
#endif /* OBIGO_Q05A */

#endif


#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  srv_brw_wtai_tel_ind
 * DESCRIPTION
 *  This func is used for handling WTAI req
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_wtai_tel_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_wtai_tel_ind_struct *localBuff_p = (wap_bam_wtai_tel_ind_struct*) msg;

#if defined(__MMI_URI_AGENT__) && defined(__MMI_UCM__)
    S8 url[SRV_BRW_MAX_URL_LEN + 1];
#endif /* defined(__MMI_URI_AGENT__) && defined(__MMI_UCM__) */ 
	srv_brw_uri_req_event_struct evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(localBuff_p);
	MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_BRW_URI_REQ_IND);
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->sap_request_id = localBuff_p->request_id;
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->wtai_tel_operation = localBuff_p->operation;
/********************************EMIT EVENT TO APP******************************/
#if defined(__MMI_URI_AGENT__) && defined(__MMI_UCM__)
    if (localBuff_p->operation == WAP_BAM_WTAI_TEL_MAKE_CALL)
    {
        strcpy((S8*) url, SRV_BRW_WTAI_MAKE_CALL_PREFIX);
    }
    else if (localBuff_p->operation == WAP_BAM_WTAI_TEL_SEND_DTMF)
    {
        strcpy((S8*) url, SRV_BRW_WTAI_SEND_DTMF_PREFIX);
    }
    strcat((S8*) url, localBuff_p->param);
	evt.url_string = (U8*) OslMalloc(SRV_BRW_MAX_URL_LEN + 1);
    memset(evt.url_string, 0, SRV_BRW_MAX_URL_LEN + 1);
	memcpy((U8*)evt.url_string, (U8*)url, SRV_BRW_MAX_URL_LEN + 1);
    MMI_FRM_CB_EMIT_EVENT((mmi_event_struct *)&evt);
	OslMfree(evt.url_string);
	evt.url_string = NULL;
#endif /* defined(__MMI_URI_AGENT__) && defined(__MMI_UCM__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_wtai_pb_ind
 * DESCRIPTION
 *  This func is used for handling the request for URI agent
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_wtai_pb_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_wtai_pb_ind_struct *localBuff_p = (wap_bam_wtai_pb_ind_struct*) msg;
	
#ifdef __MMI_URI_AGENT__
    S8 url[SRV_BRW_MAX_URL_LEN + 1];
#endif /* __MMI_URI_AGENT__ */ 
	srv_brw_uri_req_event_struct evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(localBuff_p);
	MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_BRW_URI_REQ_IND);
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->sap_request_id = localBuff_p->request_id;
/********************************EMIT EVENT TO APP******************************/
#ifdef __MMI_URI_AGENT__
    strcpy((S8*) url, SRV_BRW_WTAI_ADD_TO_PHONEBOOK_PREFIX);
    strcat((S8*) url, localBuff_p->number);
    strcat((S8*) url, ";");
    strcat((S8*) url, localBuff_p->name);
	evt.url_string = (U8*) OslMalloc(SRV_BRW_MAX_URL_LEN + 1);
    memset(evt.url_string, 0, SRV_BRW_MAX_URL_LEN + 1);
	memcpy((U8*)evt.url_string, (U8*)url, SRV_BRW_MAX_URL_LEN + 1);
    MMI_FRM_CB_EMIT_EVENT((mmi_event_struct *)&evt);
	OslMfree(evt.url_string);
	evt.url_string = NULL;
#endif /* __MMI_URI_AGENT__ */ 
}
#endif /* OBIGO_Q05A */


/*****************************************************************************
 * FUNCTION
 *  srv_brw_uri_request_ind
 * DESCRIPTION
 *  This func is used for handling URI request
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_uri_request_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_uri_request_ind_struct *localBuff_p = (wap_bam_uri_request_ind_struct*) msg;

#ifdef __MMI_URI_AGENT__
    S8 *url;
#endif /* __MMI_URI_AGENT__ */ 
	srv_brw_uri_req_event_struct evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(localBuff_p);
#ifdef __MMI_URI_AGENT__
    url = (S8*) srv_brw_malloc(WAP_BAM_MAX_URL_LEN + WAP_BAM_MAX_SCHEME_LENGTH + 4);
    memset(url, 0, WAP_BAM_MAX_URL_LEN + WAP_BAM_MAX_SCHEME_LENGTH + 4);
#endif /* __MMI_URI_AGENT__ */ 

    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->sap_request_id = localBuff_p->request_id;
/********************************EMIT EVENT TO APP******************************/
#ifdef __MMI_URI_AGENT__
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_BRW_URI_REQ_IND);
    strcpy((S8*) url, localBuff_p->scheme);
    strcat((S8*) url, ":");
    strcat((S8*) url, localBuff_p->param);
	evt.url_string = url;
	MMI_FRM_CB_EMIT_EVENT((mmi_event_struct *)&evt);
	srv_brw_free(evt.url_string);
	evt.url_string = NULL;
#endif /* __MMI_URI_AGENT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_settings_clear_data_rsp
 * DESCRIPTION
 *  Handler for clear data response sent by WPS
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_settings_clear_data_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_clear_rsp_struct *localBuff_p = (wps_clear_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(localBuff_p);
   srv_brw_call_user_app_req_data(MSG_ID_WPS_CLEAR_RSP, (U16)(localBuff_p->result), NULL);
}

/* Dihrin Input Integration begin */
#include "wap.h"
/* Dihrin Input Integration end */

/* this api is called directly, so execute in app */
/*****************************************************************************
 * FUNCTION
 *  srv_brw_wait_user_action_ind
 * DESCRIPTION
 *  This func is used for handling wait user action ind sent by BAM
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_wait_user_action_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_wait_user_action_ind_struct *localBuff_p = (wap_bam_wait_user_action_ind_struct*) msg;
	srv_brw_confirm_action_event_struct evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_bam_ready_ind
 * DESCRIPTION
 *  This func is used for handling BAM ready indication
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_bam_ready_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_ready_ind_struct *localBuff_p = (wap_bam_ready_ind_struct*) msg;
    srv_dtcnt_sim_type_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(localBuff_p);
    g_srv_brw_cntx.isWapReady = MMI_FALSE;
#if (MMI_MAX_SIM_NUM >= 2)
    srv_dtcnt_get_sim_preference(&sim_id);
    g_srv_brw_cntx.session_sim_id = srv_brw_convert_dtcnt_sim_id_to_sim_setting(sim_id);
#else
    g_srv_brw_cntx.session_sim_id = SRV_BRW_ACTIVE_SIM_SETTING_SIM1;
#endif
    srv_brw_set_profile_content();
}

#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__


/*****************************************************************************
 * FUNCTION
 *  srv_brw_bkgrd_downloads_ind
 * DESCRIPTION
 *  This function is indication for multiple downloads
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_bkgrd_downloads_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_download_info_ind_struct *localBuff_p = (mmi_da_download_info_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(localBuff_p);

    if (!g_srv_brw_cntx.download_info_p)
    {
        g_srv_brw_cntx.download_info_p =
            (mmi_da_download_info_ind_struct*) OslMalloc(sizeof(mmi_da_download_info_ind_struct));
    }

    g_srv_brw_cntx.download_info_p->job_count = localBuff_p->job_count;
    g_srv_brw_cntx.download_info_p->active_job_count = localBuff_p->active_job_count;
    if(g_srv_brw_cntx.download_info_p->job_count == 0)
    {
         OslMfree(g_srv_brw_cntx.download_info_p);
         g_srv_brw_cntx.download_info_p = NULL;
    }
}
#endif /* __MMI_DOWNLOAD_AGENT_MULTI_DL__ */ 

#ifdef WAP_SEC_SUPPORT


/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_trusted_certificate_ids_rsp
 * DESCRIPTION
 *  This func is used for handling trusted certificates ID's response
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_get_trusted_certificate_ids_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_cert_ids_rsp_struct *localBuff_p = (wps_sec_get_cert_ids_rsp_struct*) msg;
    int i;
    srv_brw_act_req_struct ptr = {0};
	srv_brw_list_element_req_struct	data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(localBuff_p);
	
	if (localBuff_p->result > 0)
    {
        srv_brw_call_user_app_req_data(MSG_ID_WPS_SEC_GET_CERT_IDS_RSP, (U16)(localBuff_p->result), NULL);
    }
	else
	{
		if(localBuff_p->total > 0)
		{
            
			if (localBuff_p->total > SRV_BRW_MAX_TRUSTED_CERTIFICATES)
			{
				g_srv_brw_cntx.srv_brw_dynamic_cntx_p->trusted_cert_ids.total = (U8) SRV_BRW_MAX_TRUSTED_CERTIFICATES;
			}
			else
			{
				g_srv_brw_cntx.srv_brw_dynamic_cntx_p->trusted_cert_ids.total = localBuff_p->total;
			}
			for (i = 0; i < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->trusted_cert_ids.total; i++)
			{
				g_srv_brw_cntx.srv_brw_dynamic_cntx_p->trusted_cert_ids.cert_ids[i] = localBuff_p->cert_ids[i];
			}
			g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list_count = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->trusted_cert_ids.total;
			g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list = srv_brw_malloc(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list_count * sizeof(srv_brw_dynamic_list_struct));
			memset(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list, 0, (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list_count * sizeof(srv_brw_dynamic_list_struct)));
            srv_brw_get_user_app_req_data(MSG_ID_WPS_SEC_GET_CERT_IDS_RSP, &ptr);
			data.index = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->trusted_cert_ids.cert_ids[0];
			ptr.req_data = (void*)&data;
			srv_brw_get_trusted_certificate_req((srv_brw_act_req_struct*)&ptr);
		}
		else
		{
			srv_brw_list_rsp_struct *rsp_data = (srv_brw_list_rsp_struct*) 
								OslMalloc(sizeof(srv_brw_list_rsp_struct));
			rsp_data->num_count = (U16)localBuff_p->total;
			g_srv_brw_cntx.srv_brw_dynamic_cntx_p->trusted_cert_ids.total = 0;
			srv_brw_call_user_app_req_data(MSG_ID_WPS_SEC_GET_CERT_IDS_RSP, (U16)(localBuff_p->result), rsp_data);
			OslMfree(rsp_data);
			rsp_data = NULL;
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_trusted_certificate_rsp
 * DESCRIPTION
 *  Receiver API to handle trusted certificate req.
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_get_trusted_certificate_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_cert_rsp_struct *localBuff_p = (wps_sec_get_cert_rsp_struct*) msg;
    U32 index;
    U32 index1;
    U32 index2;
    U8 cert_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(localBuff_p);
	
    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->view_cert_flag)
    {
        srv_brw_view_trusted_certificate_handler(msg);
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->view_cert_flag = MMI_FALSE;
        return;
    }

    /* handling the case for corrupted certificate */
    if (localBuff_p->result)
    {
        /* find & remove the corrupted certificate ID from the certificate ID list */
        for (index1 = 0; index1 < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->trusted_cert_ids.total; index1++)
        {
            if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->trusted_cert_ids.cert_ids[index1] == g_srv_brw_cntx.srv_brw_dynamic_cntx_p->req_cert_id)
            {
                for (index2 = index1; index2 < (U32)(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->trusted_cert_ids.total - 1); index2++)
                {
                    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->trusted_cert_ids.cert_ids[index2] = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->trusted_cert_ids.cert_ids[index2 + 1];
                }
                --g_srv_brw_cntx.srv_brw_dynamic_cntx_p->trusted_cert_ids.total;
                break;
            }
        }

        /* send request for the next certificate if its ID exists in the list */
        if ((g_srv_brw_cntx.srv_brw_dynamic_cntx_p->trusted_cert_ids.total > 0) && (index1 < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->trusted_cert_ids.total))
        {
			srv_brw_list_element_req_struct	ptr;
			srv_brw_act_req_struct *app_data = (srv_brw_act_req_struct*) 
										OslMalloc(sizeof(srv_brw_act_req_struct));
            srv_brw_get_user_app_req_data(MSG_ID_WPS_SEC_GET_CERT_RSP, app_data);
			ptr.index = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->trusted_cert_ids.cert_ids[index1];
			app_data->req_data = (srv_brw_list_element_req_struct*)(&ptr);
            srv_brw_get_trusted_certificate_req((srv_brw_act_req_struct *)app_data);
			OslMfree(app_data);
            return;
        }
		
        /* if no valid certificate exists then show the "Request Fail" popup and return */
        if (!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->trusted_cert_ids.total)
        {
            srv_brw_list_rsp_struct *rsp_data = (srv_brw_list_rsp_struct*) 
										OslMalloc(sizeof(srv_brw_list_rsp_struct));
			rsp_data->num_count = (U16)g_srv_brw_cntx.srv_brw_dynamic_cntx_p->trusted_cert_ids.total;
			srv_brw_call_user_app_req_data(MSG_ID_WPS_SEC_GET_CERT_RSP, (U16)(SRV_BRW_ERROR_TRUSTED_CERT_FAIL), rsp_data);
			OslMfree(rsp_data);
			rsp_data = NULL;
            return;
        }

        /* if this is the last certificate in the list then display the certificate list */
        if (index1 >= g_srv_brw_cntx.srv_brw_dynamic_cntx_p->trusted_cert_ids.total)
        {
            srv_brw_list_rsp_struct *rsp_data = (srv_brw_list_rsp_struct*) 
										OslMalloc(sizeof(srv_brw_list_rsp_struct));
			rsp_data->num_count = (U16)g_srv_brw_cntx.srv_brw_dynamic_cntx_p->trusted_cert_ids.total;
			srv_brw_call_user_app_req_data(MSG_ID_WPS_SEC_GET_CERT_RSP, (U16)(localBuff_p->result), rsp_data);
			OslMfree(rsp_data);
			rsp_data = NULL;
            return;
        }
    }   /* if(localBuff_p->result) */

    cert_id = localBuff_p->cert_id;

    /* Assuming that cert id can be any number from (0 - BRW_MAX_TRUSTED_CERTIFICATES-1) in any order */
    for (index = 0; index < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->trusted_cert_ids.total; index++)
    {
        if (cert_id == g_srv_brw_cntx.srv_brw_dynamic_cntx_p->trusted_cert_ids.cert_ids[index])
        {
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].name = (U8*)srv_brw_malloc(localBuff_p->cert.issuer_len + 1);
			memcpy((U8*)g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].name, localBuff_p->cert.issuer,
							localBuff_p->cert.issuer_len + 1);
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].host = NULL;
             g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].type = localBuff_p->cert.cert_attribute;
            if (index == (U32)(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->trusted_cert_ids.total - 1))
            {
                srv_brw_list_rsp_struct *rsp_data = (srv_brw_list_rsp_struct*) 
										OslMalloc(sizeof(srv_brw_list_rsp_struct));
				rsp_data->num_count = (U16)g_srv_brw_cntx.srv_brw_dynamic_cntx_p->trusted_cert_ids.total;
				srv_brw_call_user_app_req_data(MSG_ID_WPS_SEC_GET_CERT_RSP, (U16)(localBuff_p->result), rsp_data);
				OslMfree(rsp_data);
				rsp_data = NULL;
            }
            else
            {
				srv_brw_act_req_struct ptr;
				srv_brw_list_element_req_struct data;
                srv_brw_get_user_app_req_data(MSG_ID_WPS_SEC_GET_CERT_RSP, &ptr);
				data.index = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->trusted_cert_ids.cert_ids[index + 1];
				ptr.req_data = (void*)&data;
                srv_brw_get_trusted_certificate_req((srv_brw_act_req_struct*)&ptr);
            }
            break;
        }
    }

    if (index == g_srv_brw_cntx.srv_brw_dynamic_cntx_p->trusted_cert_ids.total)
    {
        srv_brw_list_rsp_struct *rsp_data = (srv_brw_list_rsp_struct*) 
										OslMalloc(sizeof(srv_brw_list_rsp_struct));
		rsp_data->num_count = (U16) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->trusted_cert_ids.total; // to ensure request failed is shown
		srv_brw_call_user_app_req_data(MSG_ID_WPS_SEC_GET_CERT_RSP, (U16)(SRV_BRW_ERROR_TRUSTED_CERT_FAIL), rsp_data);
		OslMfree(rsp_data);
		rsp_data = NULL;
    }

    /* de-allocating STK control buffers for rsa_modulus & rsa_exponent */
    srv_brw_free_OSL_memory((void**)&(localBuff_p->rsa_public_key.rsa_modulus));
    srv_brw_free_OSL_memory((void**)&(localBuff_p->rsa_public_key.rsa_exponent));
}
	

#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  srv_brw_security_settings_get_session_info_rsp
 * DESCRIPTION
 *  This func is used for handling session info response
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_get_session_info_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_session_info_rsp_struct *localBuff_p = (wps_sec_get_session_info_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(localBuff_p);
    srv_brw_call_user_app_req_data(MSG_ID_WPS_SEC_GET_SESSION_INFO_RSP, (U16)(localBuff_p->result), localBuff_p);
}
#endif /* OBIGO_Q05A */

/*****************************************************************************
 * FUNCTION
 *  srv_brw_trusted_certificates_delete_rsp
 * DESCRIPTION
 *  This func is used for handle delete response for trusted certificates
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_trusted_certificates_delete_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_delete_ca_cert_rsp_struct *localBuff_p = (wps_sec_delete_ca_cert_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(localBuff_p);
	if (localBuff_p->result == WPS_OK)
    {
		srv_brw_call_user_app_req_data(MSG_ID_WPS_SEC_DELETE_CA_CERT_RSP, (U16)(localBuff_p->result), NULL);
    }
	else
	{
		srv_brw_call_user_app_req_data(MSG_ID_WPS_SEC_DELETE_CA_CERT_RSP, (U16)(SRV_BRW_ERROR_TRUSTED_CERT_FAIL), NULL);
	}  
}


#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_current_certificate_rsp
 * DESCRIPTION
 *  This func is used for handling the current certificate info
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_get_current_certificate_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_current_cert_rsp_struct *localBuff_p = (wps_sec_get_current_cert_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(localBuff_p);

    srv_brw_call_user_app_req_data(MSG_ID_WPS_SEC_GET_CURRENT_CERT_RSP, (U16)(localBuff_p->result), (void*) localBuff_p);
}
#endif /* OBIGO_Q05A */


/*****************************************************************************
 * FUNCTION
 *  srv_brw_view_trusted_certificate_handler
 * DESCRIPTION
 *  Handler for View operation on a trusted certificate
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_view_trusted_certificate_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_cert_rsp_struct *localBuff_p = (wps_sec_get_cert_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(localBuff_p);

    srv_brw_call_user_app_req_data(MSG_ID_WPS_SEC_GET_CERT_RSP, (U16)(localBuff_p->result), (void*)localBuff_p);

	srv_brw_free_OSL_memory((void**)&(localBuff_p->rsa_public_key.rsa_modulus));
	srv_brw_free_OSL_memory((void**)&(localBuff_p->rsa_public_key.rsa_exponent));
	
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_sec_confirm_dialog_ind
 * DESCRIPTION
 *  Call back for showing sec confirm dialog(sent by WPS)
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_sec_confirm_dialog_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_show_confirm_dialog_ind_struct *localBuff_p = (wps_show_confirm_dialog_ind_struct*) msg;
	srv_brw_confirm_action_event_struct evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(localBuff_p);
	MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_BRW_SHOW_SEC_CNF_DLG);
	evt.data_ptr = OslMalloc(sizeof(wps_show_confirm_dialog_ind_struct));
    memset(evt.data_ptr, 0, sizeof(wps_show_confirm_dialog_ind_struct));
	((wps_show_confirm_dialog_ind_struct*)evt.data_ptr)->dialog_type = localBuff_p->dialog_type;
	((wps_show_confirm_dialog_ind_struct*)evt.data_ptr)->buttons = localBuff_p->buttons;
	((wps_show_confirm_dialog_ind_struct*)evt.data_ptr)->title_id = localBuff_p->title_id;
	((wps_show_confirm_dialog_ind_struct*)evt.data_ptr)->text_id = localBuff_p->text_id;
	MMI_FRM_CB_EMIT_EVENT((mmi_event_struct *)&evt);
	OslMfree(evt.data_ptr);
	evt.data_ptr = NULL;
}	
 
#endif /* WAP_SEC_SUPPORT */
#ifdef __SAT__
/* SAT launch req handled by Msg hdlr, can respond directly */
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_sat_launch_browser_req
 * DESCRIPTION
 *  Request handler for MSG_ID_WAP_MMI_LAUNCH_BROWSER_REQ
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_sat_launch_browser_req(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmi_lauch_browser_req_struct *localBuff_p = (wap_mmi_lauch_browser_req_struct*) msg;
	srv_brw_sat_launch_req_struct evt;
    srv_wap_prof_profile_content_struct *profile_content_p;
    S8 bearer = 0;
    S8 index;
    srv_brw_active_sim_setting_enum previous_sim_setting = g_srv_brw_cntx.session_sim_id;
#if (MMI_MAX_SIM_NUM >= 2)
    srv_brw_active_sim_setting_enum sat_sim_setting;
#endif /* (MMI_MAX_SIM_NUM >= 2) */
    mmi_brw_sim_id_enum used_sim = (mmi_brw_sim_id_enum)localBuff_p->sim_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(localBuff_p);
    if (!g_srv_brw_cntx.isWapReady)
    {
		srv_brw_show_popup_event_struct event;
		event.error_code = SRV_BRW_WAP_NOT_READY;
    	MMI_FRM_INIT_EVENT(&event, EVT_ID_SRV_BRW_SHOW_POPUP);
		MMI_FRM_CB_EMIT_EVENT((mmi_event_struct *)&event);
        srv_brw_sat_launch_browser_res(SRV_BRW_SAT_BROWSER_BUSY, used_sim);
        return;
    }
#if (MMI_MAX_SIM_NUM >= 2)
    switch(localBuff_p->sim_id)
    {
#if (MMI_MAX_SIM_NUM >= 4)
        case MMI_SIM4:
        {
            g_srv_brw_cntx.session_sim_id = SRV_BRW_ACTIVE_SIM_SETTING_SIM4;
            break;
        }
#endif
#if (MMI_MAX_SIM_NUM >= 3)
        case MMI_SIM3:
        {
            g_srv_brw_cntx.session_sim_id = SRV_BRW_ACTIVE_SIM_SETTING_SIM3;
            break;
        }
#endif
        case MMI_SIM2:
        {
            g_srv_brw_cntx.session_sim_id = SRV_BRW_ACTIVE_SIM_SETTING_SIM2;
            break;
        }
        default:
        {
            g_srv_brw_cntx.session_sim_id = SRV_BRW_ACTIVE_SIM_SETTING_SIM1;
            break;
        }
    }
#endif /* (MMI_MAX_SIM_NUM >= 2) */
    srv_brw_get_profile_content((void **)&profile_content_p);

    if (localBuff_p->noBearer > 0)
    {
        for (index = 0; index < localBuff_p->noBearer; index++)
        {
            if (localBuff_p->bearer[index] == DATA_ACCOUNT_BEARER_GPRS)
            {
                bearer = DATA_ACCOUNT_BEARER_GPRS;
                break;
            }
        #ifdef __TCPIP_OVER_CSD__
            else if (localBuff_p->bearer[index] == DATA_ACCOUNT_BEARER_CSD)
            {
                bearer = DATA_ACCOUNT_BEARER_CSD;
                break;
            }
        #endif /* #ifdef __TCPIP_OVER_CSD__ */
            else if (localBuff_p->bearer[index] == DATA_ACCOUNT_BEARER_WIFI)
            {
                bearer = DATA_ACCOUNT_BEARER_WIFI;
                break;
            }
        }

        if (srv_dtcnt_get_bearer_type(profile_content_p->data_account_primary_id, SRV_DTCNT_ACCOUNT_PRIMARY) != bearer)
        {
            srv_brw_sat_launch_browser_res(SRV_BRW_SAT_BEARER_UNAVAIL, used_sim);
            OslMfree(profile_content_p);
            g_srv_brw_cntx.session_sim_id = previous_sim_setting;
            return;
        }
    }
	MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_BRW_SAT_LAUNCH_REQ);

    if (localBuff_p->browserMode == 0x00 || localBuff_p->browserMode == 0x02 || localBuff_p->browserMode == 0x03 || localBuff_p->browserMode == 0x01)
    {
        if (localBuff_p->noUrl > 0)
        {
            srv_brw_trim_left_white_spaces((S8*) localBuff_p->url);
            srv_brw_trim_right_white_spaces((S8*) localBuff_p->url);
            if ((srv_brw_validate_url(localBuff_p->url, SRV_BRW_MAX_URL_LENGTH - 1) < 0) ||
                (mmi_ucs2strlen((S8*) localBuff_p->url) > SRV_BRW_MAX_URL_LENGTH))
            {
                srv_brw_sat_launch_browser_res(SRV_BRW_SAT_PARAM_URL_ERR, used_sim);
                OslMfree(profile_content_p);
                g_srv_brw_cntx.session_sim_id = previous_sim_setting;
                return;
            }
            else
            {
			    evt.url = (S8*)OslMalloc((mmi_ucs2strlen((CHAR*) localBuff_p->url) + 1) * ENCODING_LENGTH);
                mmi_ucs2cpy((S8*) evt.url, (S8*) localBuff_p->url);
            }
        }
        else
        {
		    evt.url = (S8*)OslMalloc((strlen((S8*)profile_content_p->url) + 1) * ENCODING_LENGTH);
            mmi_asc_to_ucs2((S8*) evt.url, (S8*) profile_content_p->url);
        }

        if (localBuff_p->noGateway > 0)
        {
            if (!g_srv_brw_cntx.sat_gateway_ascii)
            {
                g_srv_brw_cntx.sat_gateway_ascii = (U8*) OslMalloc(SRV_BRW_PROXY_GATEWAY_STR_LEN);
            }
            mmi_ucs2_to_asc((S8*) g_srv_brw_cntx.sat_gateway_ascii, (S8*) localBuff_p->gateway);
        }
        else
        {
            srv_brw_free_OSL_memory((void**)&(g_srv_brw_cntx.sat_gateway_ascii));
        }

        if(localBuff_p->browserMode == 0x00 || localBuff_p->browserMode == 0x02 || localBuff_p->browserMode == 0x01)
        {
            evt.sim_setting = g_srv_brw_cntx.session_sim_id;
            g_srv_brw_cntx.session_sim_id = previous_sim_setting;
        }

		evt.browserMode = localBuff_p->browserMode;
		MMI_FRM_CB_EMIT_EVENT((mmi_event_struct *)&evt);
        OslMfree(evt.url);
        evt.url = NULL;
    }
    else
    {
        srv_brw_sat_launch_browser_res(SRV_BRW_SAT_UNKNOWN_ERR, used_sim);
        OslMfree(profile_content_p);
        g_srv_brw_cntx.session_sim_id = previous_sim_setting;
        return;
    }
    g_srv_brw_cntx.srv_brw_profile_type = SRV_BRW_PROFILE_TYPE_SAT;
    srv_brw_sat_launch_browser_res(SRV_BRW_SAT_LAUNCH_SUCCESS, used_sim);
    OslMfree(profile_content_p);
    return;
}
#endif /* __SAT__ */ 


/******************removed *************************/
/*****************************************************************************
 * FUNCTION
 *  srv_brw_jam_get_user_agent_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg         [?]         [?]
 *  mod_id      [IN]        
 *  ilm         [?]         [?]
 *  void       [?](?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_jam_get_user_agent_req(void *msg, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_get_user_agent_rsp_struct *myMsgPtr = NULL;
    ilm_struct *ilm_ptr = NULL;
    ilm_struct *srcilm_ptr = (ilm_struct*) ilm;
    const char *url_str = (const char*)applib_inet_get_user_agent_string();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_get_user_agent_rsp_struct*) OslConstructDataPtr(sizeof(wap_get_user_agent_rsp_struct));
    memset(myMsgPtr->user_agent, 0x00, sizeof(myMsgPtr->user_agent));
    myMsgPtr->user_agent_len = strlen(url_str);
    memset(myMsgPtr->user_agent, 0, myMsgPtr->user_agent_len);
    memcpy(myMsgPtr->user_agent, url_str, myMsgPtr->user_agent_len);

    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->src_mod_id = MOD_WAP;
    ilm_ptr->sap_id = WAP_MMI_SAP;
    ilm_ptr->dest_mod_id = srcilm_ptr->src_mod_id;
    ilm_ptr->local_para_ptr = (local_para_struct*) myMsgPtr;
    ilm_ptr->msg_id = MSG_ID_WAP_GET_USER_AGENT_RSP;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);
}

#ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_brw_select_file_ind
 * DESCRIPTION
 *  Handle select file ind sent by BAM
 * PARAMETERS
 *  msg     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_select_file_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_select_file_ind_struct *localBuff_p = (wap_bam_select_file_ind_struct*) msg;
	mmi_event_struct evt;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(localBuff_p);
	MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_BRW_SELECT_FILE_IND);
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->sap_request_id = localBuff_p->request_id;
	MMI_FRM_CB_EMIT_EVENT((mmi_event_struct *)&evt);
/********************************EMIT EVENT TO APP******************************/
}
#endif /* OBIGO_Q05A */


/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_active_profile_content_callback
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  sim_id                  [IN]        
 *  profile_content_p       [?]         
 *  msg(?)                  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_get_active_profile_content_callback(
        srv_wap_prof_sim_id_enum sim_id,
        srv_wap_prof_profile_content_struct *profile_content_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_act_req_struct obj = {0};
    srv_brw_set_profile_req_struct prof = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(profile_content_p);
        obj.rsp_callback = srv_brw_bam_ready_ind_handler;
        prof.currprof = profile_content_p;
           prof.setting_id = wap_bam_setting_type_both;
           obj.req_data = (void*)&prof;

    srv_brw_set_profile_req_by_data(&obj);
    OslMfree(profile_content_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_set_profile_content
 * DESCRIPTION
 *  This function is to get the profile content from the profile and then set
 * the profile to BAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_set_profile_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_prof_profile_content_struct *profile_content_p = NULL;
    srv_brw_act_req_struct obj = {0};
    srv_brw_set_profile_req_struct prof = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    profile_content_p =
        (srv_wap_prof_profile_content_struct*) srv_wap_prof_get_profile_content(
                                                srv_brw_convert_sim_setting_to_profile_sim_id(g_srv_brw_cntx.session_sim_id),
                                                SRV_WAP_PROF_APPID_BRW,
                                                (U8) - 1,
                                                (srv_wap_prof_dtcnt_count_enum)SRV_DTCNT_ACCOUNT_PRIMARY,
                                                srv_brw_get_active_profile_content_callback);
    if (profile_content_p)
    {
        obj.rsp_callback = srv_brw_bam_ready_ind_handler;
        prof.currprof = profile_content_p;
        prof.setting_id = wap_bam_setting_type_both;
        obj.req_data = (void*)&prof;
        srv_brw_set_profile_req_by_data(&obj);
        OslMfree(profile_content_p);
    }
    g_srv_brw_cntx.sap_msg_id = MSG_ID_WAP_BAM_SET_PROFILE_REQ;
}



#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_wtai_tel_rsp
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  error_code      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_wtai_tel_rsp(U16 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_wtai_tel_rsp_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_wtai_tel_rsp_struct*) OslConstructDataPtr(sizeof(wap_bam_wtai_tel_rsp_struct));

    myMsgPtr->request_id = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->sap_request_id;
    myMsgPtr->operation = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->wtai_tel_operation;
    myMsgPtr->error_code = error_code;

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_WTAI_TEL_RSP, myMsgPtr, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_wtai_pb_rsp
 * DESCRIPTION
 *  This func is used for sending the response to URI AGent
 * PARAMETERS
 *  error_code      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_wtai_pb_rsp(U16 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_wtai_pb_rsp_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_wtai_pb_rsp_struct*) OslConstructDataPtr(sizeof(wap_bam_wtai_pb_rsp_struct));

    myMsgPtr->request_id = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->sap_request_id;
    myMsgPtr->error_code = error_code;

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_WTAI_PB_RSP, myMsgPtr, NULL);
}
#endif /* #ifdef OBIGO_Q05A */

#ifdef OBIGO_Q03C
/*****************************************************************************
 * FUNCTION
 *  srv_brw_uri_req_rsp
 * DESCRIPTION
 *  This func is used for sending the response of the URI request to Q03C BAM
 * PARAMETERS
 *  error_code      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_uri_req_rsp(U16 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_uri_request_rsp_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_srv_brw_cntx.brw_instance_id > 0 && !g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isDeleteInsReqPending)
    {
        myMsgPtr = (wap_bam_uri_request_rsp_struct*) OslConstructDataPtr(sizeof(wap_bam_uri_request_rsp_struct));

        myMsgPtr->request_id = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->sap_request_id;
        myMsgPtr->error_code = error_code;

        srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_URI_REQUEST_RSP, myMsgPtr, NULL);
    }
}
#endif /* OBIGO_Q03C */


#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_wait_user_action_rsp
 * DESCRIPTION
 *  This func is used for sending wait user action response to BAM
 * PARAMETERS
 *  positive_key_state      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_wait_user_action_rsp(MMI_BOOL positive_key_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_wait_user_action_rsp_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_wait_user_action_rsp_struct*) OslConstructDataPtr(sizeof(wap_bam_wait_user_action_rsp_struct));

    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;
    myMsgPtr->press_positive_sk = positive_key_state;

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_WAIT_USER_ACTION_RSP, myMsgPtr, NULL);

}
#endif /* OBIGO_Q05A */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_show_auth_dialog_res
 * DESCRIPTION
 *  Response function for the authentication dialog
 * PARAMETERS
 *  options     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_ren_page_show_auth_dialog_res(U16 options, U8* username, U8* pswd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_show_auth_dialog_rsp_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_srv_brw_cntx.http_auth_info_p);

    myMsgPtr = (wap_bam_show_auth_dialog_rsp_struct*) OslConstructDataPtr(sizeof(wap_bam_show_auth_dialog_rsp_struct));

    myMsgPtr->instance_id = g_srv_brw_cntx.http_auth_info_p->instance_id;
    myMsgPtr->request_id = g_srv_brw_cntx.http_auth_info_p->request_id;
    myMsgPtr->options = options;
    if(username)
    mmi_chset_ucs2_to_utf8_string(
        (U8*) myMsgPtr->username,
        WAP_BAM_MAX_USER_PASSWD_LENGTH + 1,
        (U8*) username);
    if(pswd)
    mmi_chset_ucs2_to_utf8_string(
        (U8*) myMsgPtr->password,
        WAP_BAM_MAX_USER_PASSWD_LENGTH + 1,
        (U8*) pswd);

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_SHOW_AUTH_DIALOG_RSP, myMsgPtr, NULL);

    srv_brw_free_OSL_memory((void**)&(g_srv_brw_cntx.http_auth_info_p));
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_resource_list_continue_req
 * DESCRIPTION
 *  Request function for getting the resource names starting from a particular index
 * PARAMETERS
 *  start_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_get_resource_list_continue_req(U32 start_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_resources_list_continue_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr =
        (wap_bam_get_resources_list_continue_req_struct*)
        OslConstructDataPtr(sizeof(wap_bam_get_resources_list_continue_req_struct));

    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;
    myMsgPtr->start_index = start_index;

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_GET_RESOURCES_LIST_CONTINUE_REQ, myMsgPtr, NULL);
}

#ifdef WAP_SEC_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_sec_confirm_dialog_res
 * DESCRIPTION
 *  Response function for the security confirmation dialog
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_ren_page_sec_confirm_dialog_res(U8 request_id, S8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_show_confirm_dialog_res_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wps_show_confirm_dialog_res_struct*) OslConstructDataPtr(sizeof(wps_show_confirm_dialog_res_struct));

    myMsgPtr->request_id = request_id;
    myMsgPtr->result = result;

    srv_brw_event_hdlr_send_ilm_to_wps(MSG_ID_WPS_SEC_SHOW_CONFIRM_DIALOG_RES, myMsgPtr, NULL);

}

#endif /* WAP_SEC_SUPPORT */

/*****************************************************************************
 * FUNCTION
 *  srv_brw_error_ind
 * DESCRIPTION
 *  This func is used for Handling error indication from BAM
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_error_ind(void *msg)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_error_ind_struct *localBuff_p = (wap_bam_error_ind_struct*) msg;

    srv_wap_prof_profile_content_struct *profile_content_p;
	srv_brw_rendering_error_event_struct evt;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(localBuff_p);

    MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_ERROR_IND, localBuff_p->error_code, GetActiveScreenId());
    if (localBuff_p->error_code)
    {
		switch (localBuff_p->error_code)
        {    
			/* Only Q05A */
        #ifdef OBIGO_Q05A
                /* Do nothing, simply return back for Java Script errors */
            case WAP_BAM_ERR_JSCRIPT_NONE:
            case WAP_BAM_ERR_JSCRIPT_ERR:
            case WAP_BAM_ERR_JSCRIPT_INTERNALERR:
            case WAP_BAM_ERR_JSCRIPT_EVALERR:
            case WAP_BAM_ERR_JSCRIPT_RANGEERR:
            case WAP_BAM_ERR_JSCRIPT_REFERENCEERR:
            case WAP_BAM_ERR_JSCRIPT_SYNTAXERR:
            case WAP_BAM_ERR_JSCRIPT_TYPEERR:
            case WAP_BAM_ERR_JSCRIPT_URIERR:
            {
                return;
            }
			/* Show the warnings pop-up and return back */
            case WAP_BAM_ERROR_LOW_MEMORY:
            case WAP_BAM_ERROR_EXCEED_MAX_NUM_OF_INLINE_VDO:
            case WAP_BAM_ERROR_CANNOT_PLAY_INLINE_VDO_IN_CALL:
            {
                break;
            }
        #endif /* OBIGO_Q05A */
		#ifdef OBIGO_Q03C
            case WAP_BAM_ERROR_OUT_OF_MEM_WAP_RESET:
            {
                break;
            }
        #endif /* OBIGO_Q03C */
			case WAP_BAM_ERROR_OUT_OF_MEMORY:
            {
                g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isBrowserFetching = MMI_FALSE;
                break;
            }
			default:
			{
                break;
			}
		}
    	MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_BRW_ERROR_IND);
		evt.error_code = (U16)localBuff_p->error_code;
		MMI_FRM_CB_EMIT_EVENT((mmi_event_struct *)&evt);
	}
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_wap_browser_startup_req
 * DESCRIPTION
 *  Request handler for MSG_ID_WAP_BROWSER_STARTUP_REQ
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_wap_browser_startup_req(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_browser_startup_req_struct *localBuff_p = (wap_browser_startup_req_struct*) msg;
	srv_brw_startup_req_event_struct evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(localBuff_p);
	MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_START_BROWSER_ACTION_IND);
	evt.url_ucs2 = (U8*)OslMalloc((SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH);
    evt.req_type = localBuff_p->type;
    mmi_chset_utf8_to_ucs2_string(
        (U8*) evt.url_ucs2,
        (SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH,
        (U8*) localBuff_p->url);
    MMI_FRM_CB_EMIT_EVENT((mmi_event_struct *)&evt);
	OslMfree(evt.url_ucs2);
	evt.url_ucs2 = NULL;
}


#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_stored_pages_list_continue_req
 * DESCRIPTION
 *  API to signal continuation of stored pages list req to BAM
 * PARAMETERS
 *  start_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_get_stored_pages_list_continue_req(U32 start_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_saved_pages_list_continue_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr =
        (wap_bam_get_saved_pages_list_continue_req_struct*)
        OslConstructDataPtr(sizeof(wap_bam_get_saved_pages_list_continue_req_struct));

    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;
    myMsgPtr->start_index = start_index;

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_CONTINUE_REQ, myMsgPtr, NULL);
}
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */


#ifdef __SAT__


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_sat_launch_browser_res
 * DESCRIPTION
 *  Response MSG_ID_WAP_MMI_LAUNCH_BROWSER_RSP
 * PARAMETERS
 *  res     [IN]        Type of response.
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_sat_launch_browser_res(U8 res, U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmi_lauch_browser_rsp_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_mmi_lauch_browser_rsp_struct*) OslConstructDataPtr(sizeof(wap_mmi_lauch_browser_rsp_struct));

    switch (res)
    {
        case SRV_BRW_SAT_LAUNCH_SUCCESS:
            myMsgPtr->res = SAT_CMD_PERFORMED_SUCCESSFULLY;
            myMsgPtr->additionalInfo = SAT_LAUNCH_BROWSER_NO_SPECIFIC_CAUSE;
            break;

        case SRV_BRW_SAT_BROWSER_BUSY:
            myMsgPtr->res = SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD;
            myMsgPtr->additionalInfo = SAT_LAUNCH_BROWSER_BROWSER_UNAVALIABLE;
            break;

        case SRV_BRW_SAT_BEARER_UNAVAIL:
            myMsgPtr->res = SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD;
            myMsgPtr->additionalInfo = SAT_LAUNCH_BROWSER_BEARER_UNAVALIABLE;
            break;

        case SRV_BRW_SAT_PARAM_GATEWAY_ERR:
        case SRV_BRW_SAT_PARAM_URL_ERR:
            myMsgPtr->res = SAT_LAUNCH_BROWER_GENERIC_ERROR_CODE;
            myMsgPtr->additionalInfo = SAT_LAUNCH_BROWSER_NO_SPECIFIC_CAUSE;
            break;

        case SRV_BRW_SAT_PROV_DATA_ERR:
            myMsgPtr->res = SAT_LAUNCH_BROWER_GENERIC_ERROR_CODE;
            myMsgPtr->additionalInfo = SAT_LAUNCH_BROWSER_ME_UNABLE_TO_READ_PROVISION_DATA;
            break;

        default:
            myMsgPtr->res = SAT_LAUNCH_BROWER_GENERIC_ERROR_CODE;
            myMsgPtr->additionalInfo = SAT_LAUNCH_BROWSER_NO_SPECIFIC_CAUSE;
            break;
    }
    myMsgPtr->sim_id = sim_id;
    srv_brw_event_hdlr_send_ilm_to_mmi(MSG_ID_WAP_MMI_LAUNCH_BROWSER_RSP, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_sat_send_termination_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cause       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_sat_send_termination_ind(U8 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmi_browser_termination_ind_struct *browser_term_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    browser_term_p = (wap_mmi_browser_termination_ind_struct*) construct_local_para
        ((U16) sizeof(wap_mmi_browser_termination_ind_struct), TD_CTRL);

    if (cause == SRV_BRW_SAT_USER_TERMINATION)
    {
        browser_term_p->cause = SAT_BROWSER_USER_TERMINATION;
    }
    else
    {
        browser_term_p->cause = SAT_BROWSER_ERROR_TERMINATION;
    }
    mmi_frm_send_ilm(MOD_MMI, MSG_ID_WAP_MMI_BROWSER_TERMINATION_IND, (oslParaType*)browser_term_p, NULL);
}
#endif /* __SAT__ */

#ifdef __COSMOS_MMI_PACKAGE__
/*****************************************************************************
 * FUNCTION
 *  srv_brw_select_file_ind
 * DESCRIPTION
 *  Handle wmls dialog request sent by BAM
 * PARAMETERS
 *  msg     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_wmls_dialog_req(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_event_struct evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_BRW_WMLS_DLG_IND);
    evt.user_data = msg;
    MMI_FRM_CB_EMIT_EVENT((mmi_event_struct *)&evt);
}
#endif


#ifdef MMI_BRW_BEARER_SWITCH_SUPPORT

/*****************************************************************************
 * FUNCTION
 *  srv_brw_select_file_ind
 * DESCRIPTION
 *  Handle wmls dialog request sent by BAM
 * PARAMETERS
 *  msg     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_release_sockets_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->is_closing_sockets = MMI_FALSE;
    srv_brw_call_user_app_req_data(MSG_ID_WAP_BAM_CONN_CLOSED_BY_NET_ACC_ID_RSP, (U16) 0, NULL);
}

#endif

/*****************************************************************************
 * FUNCTION
 *  srv_brw_open_bearer_ind_hdlr
 * DESCRIPTION
 *  This function is indication for opening the bearer
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_open_bearer_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_struct evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_BRW_OPEN_BEARER_IND);
    MMI_FRM_CB_EMIT_EVENT((mmi_event_struct *)&evt);
}

/********************************EMIT EVENT TO APP******************************/

/********************************APP CALLBACK***********************************/
#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERSRVMSGHDLR_C */
