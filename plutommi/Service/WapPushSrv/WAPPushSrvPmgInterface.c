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
 * PushMsgServiceInterface.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains the function defination for interaction functions of Service layer.
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//#include "MMI_include.h"

#include "WAPPushSrvProts.h"
    #include "MMIDataType.h"
    #include "pmg_struct.h"
    #include "DebugInitDef_Int.h"
    #include "WAPPushSrvTypes.h"
    #include "kal_trace.h"
    #include "mmi_inet_app_trc.h"
    #include "MMI_inet_app_trc.h"
    #include "mmi_frm_queue_gprot.h"
    #include "app_ltlcom.h"
    #include "WAPPushSrvGprots.h"
    #include "mmi_frm_events_gprot.h"
    #include "string.h"
    #include "mmi_cb_mgr_gprot.h"
    #include "MMI_features.h"
    #include "kal_general_types.h"
    #include "common_nvram_editor_data_item.h"
    #include "stack_config.h"
    #include "stack_msgs.h"
    #include "stack_common.h"
    #include "mmi_frm_mem_gprot.h"
    #include "kal_public_api.h"
    #include "mmi_frm_scenario_gprot.h"
    #include "MMI_features.h"


#ifdef __WAP_PUSH_SUPPORT__

#ifdef __MMI_PUSH_IN_UM__
#include "UMSrvDefs.h"
#endif /* __MMI_PUSH_IN_UM__ */

/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_print_full_message_detail_received_from_service
 * DESCRIPTION
 * 
 * PARAMETERS
 *  message     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_print_full_message_detail_received_from_service (pmg_detailed_msg_struct *message, S8 *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_FULL_MSG_COMMON, 
        message->msg_id,
        message->msg_type,
        message->created,
        message->expired,
        message->priority,
        message->text_type,
        message->read,
        message->has_info,
        __LINE__);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_handle_full_msg
 * DESCRIPTION
 *  Received push msg content response from service layer.
 * PARAMETERS
 *  local_param     [IN]         
 *  mod_id          [IN]        
 *  ilm             [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_handle_full_msg (void *local_param, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *ilm_info = (MYQUEUE*) ilm;
    U16 pdu_length = 0;
    wps_pmg_get_msg_cnf_struct *local_data = NULL;
    srv_wap_push_idle_messge_queue_struct *message = NULL;
    S8 *local_href = NULL;
    srv_wap_push_handle_msg_struct evt_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_data = (wps_pmg_get_msg_cnf_struct*) local_param;
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_HDL_PMG_MSG_RSP, local_data->trans_id, local_data->status);
    /* Extract URL of the message */
    if (ilm_info->peer_buff_ptr != NULL)
    {
        local_href = get_pdu_ptr(ilm_info->peer_buff_ptr, &pdu_length);
    }
	if(local_data->trans_id == PUSH_GET_MSG_CONTENT_TRANS_ID)
	{
		if(g_srv_wap_push_cntxt->msg_content_callback)
		g_srv_wap_push_cntxt->msg_content_callback(&(local_data->msg_data),(kal_int8*)local_href, g_srv_wap_push_cntxt->msg_content_user_data);
		return;
	}
    srv_wap_push_print_full_message_detail_received_from_service ((pmg_detailed_msg_struct *)(&local_data->msg_data), local_href);
    MMI_FRM_INIT_EVENT(&evt_msg, EVT_ID_SRV_PUSH_HANDLE_FULL_MSG);
    evt_msg.status = (wps_pmg_status_enum)local_data->status;
    evt_msg.trans_id = (srv_wap_push_trans_id_enum)local_data->trans_id;
    evt_msg.new_msg = &(local_data->msg_data);
    evt_msg.url = local_href;
    mmi_frm_cb_emit_event((mmi_event_struct*)&evt_msg);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_msg_list_reply
 * DESCRIPTION
 * Push message list response from service layer. 
 * PARAMETERS
 *  msg     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_msg_list_reply(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_pmg_msg_list_cnf_struct *msg_list = (wps_pmg_msg_list_cnf_struct*) msg;
    srv_wap_push_msg_list_reply_struct evt_msg_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_HDL_PMG_MSG_LIST_RSP, msg_list->trans_id, msg_list->size);
    if (msg_list->size != 0)
    {
        MMI_FRM_INIT_EVENT(&evt_msg_list, EVT_ID_SRV_PUSH_MSG_LIST_REPLY);
        evt_msg_list.trans_id =(srv_wap_push_trans_id_enum) msg_list->trans_id;
        evt_msg_list.msg_list = msg_list;
        mmi_frm_cb_emit_event((mmi_event_struct*)&evt_msg_list);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_handle_msg_count_rsp
 * DESCRIPTION
 *  Handle message count response from service layer
 * PARAMETERS
 *  msg          [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_handle_msg_count_rsp (void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_pmg_msg_count_cnf_struct *msg_rsp = NULL;
    U16 total_message = 0;
    srv_wap_push_msg_count_rsp_struct evt_msg_cnt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_rsp = (wps_pmg_msg_count_cnf_struct*) msg;
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_RECV_MSG_CNT_SIM1, (U16)msg_rsp->msg_count_sim1);
    total_message = msg_rsp->msg_count_sim1;
#if (MMI_MAX_SIM_NUM >= 2)
    total_message += msg_rsp->msg_count_sim2;
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_RECV_MSG_CNT_SIM2, (U16)msg_rsp->msg_count_sim2);
#endif /* __MMI_WAP_DUAL_SIM__ */
//#if (defined(GEMINI_PLUS) && (GEMINI_PLUS >= 3))
#if (MMI_MAX_SIM_NUM >= 3)
   total_message += msg_rsp->msg_count_sim3;
   // MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_RECV_MSG_CNT_SIM3, (U16)msg_rsp->msg_count_sim3);
#endif
//#if (defined(GEMINI_PLUS) && (GEMINI_PLUS >= 4))
#if (MMI_MAX_SIM_NUM >= 4)
   total_message += msg_rsp->msg_count_sim4;
   // MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_RECV_MSG_CNT_SIM4, (U16)msg_rsp->msg_count_sim4);
#endif
   if((msg_rsp->trans_id==PUSH_UPDATE_ICON_TRANS_ID) || (msg_rsp->trans_id==PUSH_UPDATE_ICON_AND_TB_STATUS_AT_BOOT_TRANS_ID))
    g_srv_wap_push_cntxt->unread_msgs_count = total_message;
    MMI_FRM_INIT_EVENT(&evt_msg_cnt, EVT_ID_SRV_PUSH_MSG_COUNT_RSP);
    evt_msg_cnt.trans_id = (srv_wap_push_trans_id_enum)msg_rsp->trans_id;
    evt_msg_cnt.msg_rsp = msg_rsp;
    mmi_frm_cb_emit_event((mmi_event_struct*)&evt_msg_cnt);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_config_msg_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_config_msg_cnf(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	srv_wap_push_get_msg_count(WAP_PMG_PARAM_NO, PUSH_UPDATE_ICON_AND_TB_STATUS_AT_BOOT_TRANS_ID);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_replace_msg_ind
 * DESCRIPTION
 *  replace indication sent by service layer.
 * PARAMETERS
 *  local_param     [IN]         
 *  mod_id          [IN]        
 *  ilm             [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_replace_msg_ind(void *local_param, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL replace_flag = MMI_TRUE;
    MMI_BOOL need_reset_highlighted_flag = MMI_FALSE;
    U16 pdu_length = 0;
    U16 active_screen = 0;
    S8 *href = NULL;
    MYQUEUE *ilm_info = (MYQUEUE*) ilm;
    wps_pmg_replace_ind_struct *replace_msg_ind = (wps_pmg_replace_ind_struct*) local_param;

    wps_pmg_delete_ind_struct delete_ind_data = {0,};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_HDL_PMG_REPLCE_IND, replace_msg_ind->msg_id);
    if (ilm_info->peer_buff_ptr != NULL)
    {
        href = get_pdu_ptr(ilm_info->peer_buff_ptr, &pdu_length);
    }
    else
    {
        href = NULL;
    }
    if (g_push_set_p->general_set.enable_push != WAP_PMG_RETR_DISABLED)
    {
        delete_ind_data.size = 1;
        delete_ind_data.msgs[0].msg_id = replace_msg_ind->msg_id;
        delete_ind_data.msgs[0].msg_type =  replace_msg_ind->msg_type;

        if ((replace_msg_ind->msg_data.msg_type == WAP_PMG_MSGTYPE_SI) && (replace_msg_ind->msg_data.priority == WAP_PMG_MSGPRIO_LOW))
        {
            replace_flag = MMI_FALSE;
        }
        if (g_push_inbox_ctxt->sel_idx == 0)
        {
            /* Dirty patch to make highlighter consistant*/
            need_reset_highlighted_flag = MMI_TRUE;
        }
        g_push_inbox_ctxt->num_of_messages += 1;
        srv_wap_push_handle_msg_deleted_by_server_ind(&delete_ind_data, replace_flag);
        g_push_inbox_ctxt->num_of_messages -= 1;

/*        active_screen = mmi_frm_scrn_get_active_id();
        if ((active_screen == SCR_ID_BRW_READ_SERVICE_MESSAGE)
            || (active_screen == SCR_ID_BRW_READ_SERVICE_MESSAGE_OPTIONS)
            || (active_screen == SCR_ID_BRW_SEND_BY_OPTIONS))
        {
            ClearExitHandler();
        }
*/
		g_srv_wap_push_cntxt->unread_msgs_count++;
		srv_wap_push_get_msg_count(WAP_PMG_PARAM_NO, PUSH_UPDATE_ICON_TRANS_ID);
		#ifdef __MMI_PUSH_IN_UM__
			if(srv_wap_push_send_new_msg_um_refresh_ind(&(replace_msg_ind->msg_data)))
				srv_wap_push_send_um_refresh_ind(replace_msg_ind->msg_data.msg_id,SRV_UM_REFRESH_NEW_INCOMING_MSG,&(replace_msg_ind->msg_data.from));
			else
				srv_wap_push_send_um_refresh_ind(replace_msg_ind->msg_data.msg_id,SRV_UM_REFRESH_NONE,NULL);
		#endif

        srv_wap_push_handle_new_service_msg (&(replace_msg_ind->msg_data), href);

        if (need_reset_highlighted_flag)
        {
            /* Dirty patch to make highlighter consistant*/
            g_push_inbox_ctxt->sel_idx--;
        }
    }
    //srv_wap_push_get_msg_count(WAP_PMG_PARAM_NO, PUSH_UPDATE_ICON_TRANS_ID);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_msg_delete_ind
 * DESCRIPTION
 *  Delete Ind sent by service layer.
 * PARAMETERS
 *  msg     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_msg_delete_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_wap_push_get_msg_count(WAP_PMG_PARAM_NO, PUSH_UPDATE_ICON_TRANS_ID);
    if (g_push_set_p->general_set.enable_push != WAP_PMG_RETR_DISABLED)
    {
        srv_wap_push_handle_msg_deleted_by_server_ind((wps_pmg_delete_ind_struct*)msg, MMI_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_send_new_msg_response
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void.
 * RETURNS
 *  void.
 *****************************************************************************/
void srv_wap_push_send_new_msg_response (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_wap_push_send_msg (MSG_ID_WPS_PMG_NEW_MSG_RSP, NULL, MOD_WPS, WPS_APP_SAP);
}

MMI_BOOL srv_wap_push_send_new_msg_um_refresh_ind(pmg_detailed_msg_struct *msg_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_push_set_p->general_set.enable_push != WAP_PMG_RETR_DISABLED)    {

        switch(msg_data->msg_type)
        {
			case WAP_PMG_MSGTYPE_SL:
				switch (msg_data->priority)
				{
					case WAP_PMG_MSGPRIO_HIGH:
						if (g_push_set_p->general_set.sl_setting == SRV_WAP_PUSH_SL_SETTING_PROMPT)
							return MMI_TRUE;
						else
							return MMI_FALSE;
					
					
 					case WAP_PMG_MSGPRIO_LOW:
						return MMI_TRUE;
						
				}
            break;
			case WAP_PMG_MSGTYPE_SI:
				switch (msg_data->priority)
				{
				case WAP_PMG_MSGPRIO_HIGH:
						return MMI_FALSE;
					
				case WAP_PMG_MSGPRIO_MEDIUM: 
				case WAP_PMG_MSGPRIO_LOW:
						return MMI_TRUE;
					
				}
            break;
        }
    }
   
    return MMI_FALSE;
}



/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_handle_new_msg_ind
 * DESCRIPTION
 *  Handle the new message indication from service latyer
 * PARAMETERS
 *  local_param     [IN]         
 *  mod_id          [IN]        
 *  ilm             [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_handle_new_msg_ind(void *local_param, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *local_href = NULL;
    U16 pdu_length = 0;
    wps_pmg_new_msg_ind_struct *new_msg = (wps_pmg_new_msg_ind_struct*) local_param;
    MYQUEUE *ilm_info = (MYQUEUE*) ilm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ilm_info->peer_buff_ptr != NULL)
    {
        local_href = get_pdu_ptr(ilm_info->peer_buff_ptr, &pdu_length);
    }
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_NEW_MSG_RCVD, new_msg->msg_data.msg_id);
    srv_wap_push_print_full_message_detail_received_from_service(&(new_msg->msg_data), local_href);
    g_srv_wap_push_cntxt->unread_msgs_count++;
     srv_wap_push_get_msg_count(WAP_PMG_PARAM_NO, PUSH_UPDATE_ICON_TRANS_ID);
    srv_wap_push_handle_new_service_msg(&new_msg->msg_data, local_href);
    srv_wap_push_send_new_msg_response();
	
    #ifdef __MMI_PUSH_IN_UM__
		if(srv_wap_push_send_new_msg_um_refresh_ind(&(new_msg->msg_data)))
        srv_wap_push_send_um_refresh_ind(new_msg->msg_data.msg_id,SRV_UM_REFRESH_NEW_INCOMING_MSG,&(new_msg->msg_data.from));
		else
			srv_wap_push_send_um_refresh_ind(new_msg->msg_data.msg_id,SRV_UM_REFRESH_NONE,NULL);
    #endif
    //srv_wap_push_get_msg_count(WAP_PMG_PARAM_NO, PUSH_UPDATE_ICON_TRANS_ID);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_handle_pmg_ready_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_handle_pmg_ready_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_wap_push_cntxt->is_service_ready = MMI_TRUE;
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    srv_wap_send_white_list_to_service_layer();
#endif
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    srv_wap_send_black_list_to_service_layer();
#endif
    srv_wap_push_send_config_ind();
    srv_wap_push_init_profile_content();
}

#if !defined(__MMI_WAP_PUSH_SIA_SLIM__) || defined(__MMI_WAP_PUSH_WHITE_LIST__) 
/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_get_dlg_data_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  trans_id       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_get_dlg_data_req(U32 trans_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_pmg_dlg_query_req_struct *local_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_SEND_DLG_DATA_REQUEST, trans_id);
	local_data = (wps_pmg_dlg_query_req_struct*) construct_local_para(sizeof(wps_pmg_dlg_query_req_struct), TD_CTRL);
    local_data->trans_id = 0;
    local_data->dlg_trans_id = trans_id;
    srv_wap_push_send_msg (MSG_ID_WPS_PMG_DLG_QUERY_REQ, (void*)local_data, MOD_WPS, WPS_APP_SAP);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_send_sia_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_send_sia_cnf(pBOOL result, U32 trans_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_pmg_dlg_sia_confirm_cnf_struct *local_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	local_data = (wps_pmg_dlg_sia_confirm_cnf_struct*) construct_local_para(sizeof(wps_pmg_dlg_sia_confirm_cnf_struct), TD_CTRL);
    local_data->trans_id = trans_id;
    local_data->result = (U8) result;
    srv_wap_push_send_msg (MSG_ID_WPS_PMG_DLG_SIA_CONFIRM_CNF, (void*)local_data, MOD_WPS, WPS_APP_SAP);
	MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_SEND_SIA_CNF, trans_id, result);
}
#endif

#ifdef __MMI_WAP_PUSH_WHITE_LIST__
/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_send_unknwn_addr_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_send_unknwn_addr_cnf(pBOOL result, U32 trans_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_pmg_dlg_unknown_addr_cnf_struct *local_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	local_data = (wps_pmg_dlg_unknown_addr_cnf_struct*) construct_local_para(sizeof(wps_pmg_dlg_unknown_addr_cnf_struct), TD_CTRL);
    local_data->trans_id = trans_id;
    local_data->result = (U8) result;
    srv_wap_push_send_msg (MSG_ID_WPS_PMG_DLG_UNKNOWN_ADDR_CNF, (void*)local_data, MOD_WPS, WPS_APP_SAP);
	MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_SEND_UNKNWN_ADDR_CNF, trans_id, result);
}
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_get_full_message
 * DESCRIPTION
 *  Use to get message details for given message ID.
 * PARAMETERS
 *  msg_id            [IN]
 *  trans_id          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_get_full_message (U32 msg_id, U16 trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_pmg_get_msg_req_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_SEND_FULL_MSG_REQ, msg_id, trans_id);
    local_data = (wps_pmg_get_msg_req_struct*) construct_local_para(sizeof(wps_pmg_get_msg_req_struct), TD_CTRL);
    local_data->trans_id = trans_id;
    local_data->msg_id = msg_id;
    srv_wap_push_send_msg (MSG_ID_WPS_PMG_GET_MSG_REQ, (void*)local_data, MOD_WPS, WPS_APP_SAP);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_get_msg_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  read         [IN]
 *  trans_id     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_get_msg_count(U16 read, U16 trans_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	wps_pmg_msg_count_req_struct *local_data = NULL;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_SEND_COUNT_REQ, read, trans_id);
	local_data = (wps_pmg_msg_count_req_struct*) construct_local_para(sizeof(wps_pmg_msg_count_req_struct), TD_CTRL);
	local_data->trans_id = trans_id;
    local_data->is_read = (U8) read;

    local_data->msg_type = WAP_PMG_PARAM_NOT_SPECIFIED;
    local_data->is_expired = WAP_PMG_PARAM_NOT_SPECIFIED;
    local_data->has_info = WAP_PMG_PARAM_NOT_SPECIFIED;

    srv_wap_push_send_msg (MSG_ID_WPS_PMG_MSG_COUNT_REQ, (void*)local_data, MOD_WPS, WPS_APP_SAP);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_send_del_req_to_pmg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id         [IN]
 *  trans_id       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_send_del_req_to_pmg (U32 msg_id, U16 trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_pmg_delete_msg_req_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_SEND_DEL_REQ, msg_id, trans_id);
    local_data = (wps_pmg_delete_msg_req_struct*) construct_local_para(sizeof(wps_pmg_delete_msg_req_struct), TD_CTRL);
    local_data->trans_id = trans_id;
    local_data->msg_id = msg_id;

    srv_wap_push_send_msg (MSG_ID_WPS_PMG_DELETE_MSG_REQ, (void*)local_data, MOD_WPS, WPS_APP_SAP);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_update_service_msg_req
 * DESCRIPTION
 *  Request for updation of read flag to service layer for the selected message or message being displayed directly.
 * PARAMETERS
 *  msg_id         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_update_service_msg_req(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_pmg_update_msg_req_struct *local_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_SEND_UPDATE_REQ, msg_id);
    local_data = (wps_pmg_update_msg_req_struct*) construct_local_para(sizeof(wps_pmg_update_msg_req_struct), TD_CTRL);
	local_data->trans_id = 0;
	local_data->msg_id = msg_id;
	local_data->read = WAP_PMG_PARAM_YES;

    srv_wap_push_send_msg (MSG_ID_WPS_PMG_UPDATE_MSG_REQ, (void*)local_data, MOD_WPS, WPS_APP_SAP);
}

/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_update_all_service_msg_req
 * DESCRIPTION
 *  Request for updation of read flag to service layer for the all unread messages or message being displayed directly.
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_update_all_service_msg_req(srv_wap_push_update_all_read_callback_func callback_func, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_pmg_update_all_msg_req_struct *local_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_SEND_UPDATE_REQ);
	g_srv_wap_push_cntxt->callback_func = callback_func;
	g_srv_wap_push_cntxt->readstatue_user_data = user_data;

    local_data = (wps_pmg_update_all_msg_req_struct*) construct_local_para(sizeof(wps_pmg_update_all_msg_req_struct), TD_CTRL);
	local_data->read = WAP_PMG_PARAM_YES;

    srv_wap_push_send_msg (MSG_ID_WPS_PMG_UPDATE_ALL_MSG_REQ, (void*)local_data, MOD_WPS, WPS_APP_SAP);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_update_service_msg_cnf
 * DESCRIPTION
 *  confirmation for updation of read flag to service layer for the selected message or message being displayed directly.
 * PARAMETERS
 *  msg_id         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_handle_update_service_msg_cnf(void* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_pmg_update_msg_cnf_struct *local_data =  (wps_pmg_update_msg_cnf_struct *) data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	srv_wap_push_get_msg_count(WAP_PMG_PARAM_NO, PUSH_UPDATE_ICON_TRANS_ID);
        #ifdef __MMI_PUSH_IN_UM__  
    if (MMI_TRUE != g_srv_wap_push_cntxt->read_from_um)
	srv_wap_push_send_um_refresh_ind(local_data->msg_id,SRV_UM_REFRESH_MSG_STATUS_CHANGED,NULL);
        #endif

}

/********    *********************************************************************
 * FUNCTION
 *  srv_wap_push_update_service_msg_cnf
 * DESCRIPTION
 *  confirmation for updation of read flag to service layer for all messages .
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_handle_update_all_service_msg_cnf(void* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	wps_pmg_update_all_msg_cnf_struct *local_data =  (wps_pmg_update_all_msg_cnf_struct *) data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	 g_srv_wap_push_cntxt->unread_msgs_count = 0;
	 g_srv_wap_push_cntxt->callback_func((srv_wap_push_msg_read_status_enum)local_data->status_result, g_srv_wap_push_cntxt->readstatue_user_data);
    #ifdef __MMI_PUSH_IN_UM__  
	srv_wap_push_send_um_refresh_ind(0,SRV_UM_REFRESH_NONE,NULL);
     #endif

}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_get_list_from_service_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start_index     [IN]
 *  num_item        [IN]
 *  trans_id        [IN]
 *  is_read         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_get_list_from_service_layer(S32 start_index, S32 num_item, U16 trans_id, U8 is_read)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_pmg_msg_list_req_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_SEND_MSG_LIST_REQ, start_index, num_item, trans_id, is_read);
    local_data = (wps_pmg_msg_list_req_struct*) construct_local_para(sizeof(wps_pmg_msg_list_req_struct), TD_CTRL);
    local_data->trans_id = trans_id;
    local_data->msg_type = WAP_PMG_PARAM_NOT_SPECIFIED;
    local_data->is_read = is_read;
    local_data->is_expired = WAP_PMG_PARAM_NOT_SPECIFIED;
    local_data->has_info = WAP_PMG_PARAM_NOT_SPECIFIED;
    local_data->start_from = start_index;
    local_data->size = num_item;
    srv_wap_push_send_msg (MSG_ID_WPS_PMG_MSG_LIST_REQ, (void*)local_data, MOD_WPS, WPS_APP_SAP);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_delete_all_msg_req
 * DESCRIPTION
 *  Delete All request to service layer.
 * PARAMETERS
 *  trans_id      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_delete_all_msg_req (U16 trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_pmg_delete_all_req_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_SEND_DEL_ALL_REQ);
    local_data = (wps_pmg_delete_all_req_struct*) construct_local_para(sizeof(wps_pmg_delete_all_req_struct), TD_CTRL);
    local_data->trans_id = trans_id;
    local_data->msg_type = WAP_PMG_PARAM_NOT_SPECIFIED;

    srv_wap_push_send_msg (MSG_ID_WPS_PMG_DELETE_ALL_REQ, (void*)local_data, MOD_WPS, WPS_APP_SAP);
}
#if !defined(__MMI_WAP_PUSH_SIA_SLIM__) || defined(__MMI_WAP_PUSH_WHITE_LIST__) 
/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_get_dialogue_date
 * DESCRIPTION
 *  
 * PARAMETERS
 *  message_id         [IN]
 *  type               [IN]
 * RETURNS
 *  TRUE if success otherwise false.
 *****************************************************************************/
srv_wap_push_dlg_queue_struct* srv_wap_push_get_dialogue_date (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	return g_srv_wap_push_cntxt->dlg_front;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_enque_dialogue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  message_id         [IN]
 *  type               [IN]
 * RETURNS
 *  TRUE if success otherwise false.
 *****************************************************************************/
MMI_BOOL srv_wap_push_enque_dialogue (U32 trans_id, U16 dlg_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_dlg_queue_struct  *node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_ENQUEUE_DLG);

	return srv_wap_push_enque_dialogue_ex(trans_id, dlg_type, NULL);

	/*
    node = (srv_wap_push_dlg_queue_struct*) srv_wap_push_malloc (sizeof (srv_wap_push_dlg_queue_struct));
    if (node == NULL)
    {
        return MMI_FALSE;
    }
    else
    {
        node->trans_id = trans_id;
        node->dlg_type = dlg_type;
        node->next = NULL;
        if (g_srv_wap_push_cntxt->dlg_front == NULL)
        {
            g_srv_wap_push_cntxt->dlg_front = node;
            g_srv_wap_push_cntxt->dlg_rear = node;
        }
        else
        {
            g_srv_wap_push_cntxt->dlg_rear->next = node;
            g_srv_wap_push_cntxt->dlg_rear = g_srv_wap_push_cntxt->dlg_rear->next;
        }
        return MMI_TRUE;
    }*/
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_enque_dialogue_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  message_id         [IN]
 *  type               [IN]
 * RETURNS
 *  TRUE if success otherwise false.
 *****************************************************************************/
MMI_BOOL srv_wap_push_enque_dialogue_ex (U32 trans_id, U16 dlg_type, S8 *info_char)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_dlg_queue_struct  *node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_ENQUEUE_DLG);
    node = (srv_wap_push_dlg_queue_struct*) srv_wap_push_malloc (sizeof (srv_wap_push_dlg_queue_struct));
    if (node == NULL)
    {
        return MMI_FALSE;
    }
    else
    {
        node->trans_id = trans_id;
        node->dlg_type = dlg_type;
		if(info_char)
		{
			memset(node->dl_info,0,sizeof(node->dl_info));
			mmi_asc_n_to_ucs2((S8*)node->dl_info,(S8*)info_char,MAX_NOTIFICATION_INFO_LEN);

		}
        node->next = NULL;
        if (g_srv_wap_push_cntxt->dlg_front == NULL)
        {
            g_srv_wap_push_cntxt->dlg_front = node;
            g_srv_wap_push_cntxt->dlg_rear = node;
        }
        else
        {
            g_srv_wap_push_cntxt->dlg_rear->next = node;
            g_srv_wap_push_cntxt->dlg_rear = g_srv_wap_push_cntxt->dlg_rear->next;
        }
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_delete_from_dlg_queue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  message_id          [IN]
 * RETURNS
 *  void.
 *****************************************************************************/
void srv_wap_push_delete_from_dlg_queue (U32 trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_dlg_queue_struct  *node = NULL;
    srv_wap_push_dlg_queue_struct  *prev = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_wap_push_cntxt->dlg_front == NULL)
    {
        return;
    }
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_DEQUEUE_DLG);
    /* Deleting the first node */
    if (trans_id == g_srv_wap_push_cntxt->dlg_front->trans_id)
    {
        node = g_srv_wap_push_cntxt->dlg_front;
        g_srv_wap_push_cntxt->dlg_front = g_srv_wap_push_cntxt->dlg_front->next;
        srv_wap_push_mfree (node);
    }
    else
    {
        node = g_srv_wap_push_cntxt->dlg_front->next;
        prev = g_srv_wap_push_cntxt->dlg_front;
        while (node)
        {
            if (trans_id == node->trans_id)
            {
                prev->next = node->next;
                if (node == g_srv_wap_push_cntxt->dlg_rear)
                {
                    g_srv_wap_push_cntxt->dlg_rear = prev;
                }
                srv_wap_push_mfree (node);
                return;
            }

            prev = node;
            node = node->next;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_initialize_curr_dlg_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sia                 [IN]
 *  unknown_dlg         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_delete_curr_dlg_data (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if(g_srv_wap_push_cntxt->curr_dlg)
	{
		OslMfree(g_srv_wap_push_cntxt->curr_dlg);
		g_srv_wap_push_cntxt->curr_dlg = NULL;
	}

}




/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_initialize_curr_dlg_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sia                 [IN]
 *  unknown_dlg         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_initialize_curr_dlg_data (void *dlg, wps_pmg_dlg_type_enum dlg_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_INITIALIZING_CURRENT_DLG_DATA, dlg_type, (U32)dlg);
	if (dlg == NULL)
	{
        if (g_srv_wap_push_cntxt->curr_dlg)
        {
            OslMfree(g_srv_wap_push_cntxt->curr_dlg);
        }
		g_srv_wap_push_cntxt->curr_dlg = NULL;
		return;
	}
	else
	{
		if (g_srv_wap_push_cntxt->curr_dlg == NULL) /* Extra check to avaid any memory leak by mistake */
		{
			g_srv_wap_push_cntxt->curr_dlg = (srv_wap_push_curr_dlg_struct*) OslMalloc (sizeof (srv_wap_push_curr_dlg_struct));
            memset (g_srv_wap_push_cntxt->curr_dlg, '\0', sizeof (srv_wap_push_curr_dlg_struct));
		}
		if (g_srv_wap_push_cntxt->curr_dlg == NULL)
		{
            /* Condition should not arises as Toolbar need data only after Push message queue got processed */
			/* Memory not enough for UI display, so it should assert */
			ASSERT(0);
		}
		g_srv_wap_push_cntxt->curr_dlg->dlg_type = dlg_type;
	}
	switch (dlg_type)
	{
	case WAP_PMG_DLG_SIA_CONFIRM:
		memcpy (&(g_srv_wap_push_cntxt->curr_dlg->dlg_data.sia), dlg, sizeof (wps_pmg_dlg_sia_confirm_req_struct));
		break;
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
	case WAP_PMG_DLG_UNKOWN_ADDR_CONFIRM:
		memcpy (&(g_srv_wap_push_cntxt->curr_dlg->dlg_data.msg), dlg, sizeof (wps_pmg_dlg_unknown_addr_req_struct));
		break;
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
	}
}



MMI_BOOL srv_wap_push_draw_unknown_scren (mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_draw_unknown_struct evt_draw_unknown;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_FRM_INIT_EVENT(&evt_draw_unknown, EVT_ID_SRV_PUSH_DRAW_UNKNOWN);
    mmi_frm_cb_emit_event((mmi_event_struct*)&evt_draw_unknown);
    return MMI_TRUE;
}



/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_service_initiation_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_service_initiation_req(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	wps_pmg_dlg_sia_confirm_req_struct *data = (wps_pmg_dlg_sia_confirm_req_struct*) msg;
    srv_wap_push_service_init_struct evt_init;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt_init, EVT_ID_SRV_PUSH_SERVICE_INIT);
    evt_init.msg = (wps_pmg_dlg_sia_confirm_req_struct*) msg;
    mmi_frm_cb_emit_event((mmi_event_struct*)&evt_init);
}


#ifdef __MMI_WAP_PUSH_WHITE_LIST__
/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_service_unknown_addr_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_service_unknown_addr_req(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//	wps_pmg_dlg_unknown_addr_req_struct *data = (wps_pmg_dlg_unknown_addr_req_struct*) msg;
    srv_wap_push_service_unknown_addr_req_struct evt_unknown_addr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt_unknown_addr, EVT_ID_SRV_PUSH_UNKNOWN_ADDR_REQ);
    evt_unknown_addr.msg = (wps_pmg_dlg_unknown_addr_req_struct*) msg;
    mmi_frm_cb_emit_event((mmi_event_struct*)&evt_unknown_addr); 
}
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_handle_dlg_data_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_handle_dlg_data_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	wps_pmg_dlg_query_cnf_struct *data = (wps_pmg_dlg_query_cnf_struct*) msg;
    srv_wap_push_handle_dlg_data_rsp_struct evt_dlg_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt_dlg_data, EVT_ID_SRV_PUSH_HANDLE_DLG_DATA_RSP);
    evt_dlg_data.msg = (wps_pmg_dlg_query_cnf_struct*) msg;
    mmi_frm_cb_emit_event((mmi_event_struct*)&evt_dlg_data);
}

#endif
/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_handle_storage_full_ind
 * DESCRIPTION
 *  PUSH STORAGE FULL POPUP DISPLAY.
 * PARAMETERS
 *  msgID       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_handle_storage_full_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//	wps_pmg_dlg_query_cnf_struct *data = (wps_pmg_dlg_query_cnf_struct*) msg;
    srv_wap_push_handle_storage_full_ind_struct evt_storage_full;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt_storage_full, EVT_ID_SRV_PUSH_HANDLE_STORAGE_FULL_IND);
    evt_storage_full.msg = (wps_pmg_delete_ind_struct*) msg;
    mmi_frm_cb_emit_event((mmi_event_struct*)&evt_storage_full);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_handle_delete_folder_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_handle_delete_folder_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_delete_folder_ind_struct evt_delete_folder;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt_delete_folder, EVT_ID_SRV_PUSH_HANDLE_DELETE_FOLDER_IND);
    evt_delete_folder.msg = (wps_pmg_delete_folder_ind_struct*) msg;
    mmi_frm_cb_emit_event((mmi_event_struct*)&evt_delete_folder);
}
/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_display_error_dlg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_display_error_dlg(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_error_dlg_struct evt_error_dlg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt_error_dlg, EVT_ID_SRV_PUSH_DISPLAY_ERROR_DLG);
    evt_error_dlg.msg = (wps_pmg_error_dlg_struct*) msg;
    mmi_frm_cb_emit_event((mmi_event_struct*)&evt_error_dlg);
}

/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_process_delete_msg_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_process_delete_msg_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_delete_msg_cnf_struct evt_delete_msg_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt_delete_msg_cnf, EVT_ID_SRV_PUSH_PROCESS_DELETE_MSG_RSP);
    evt_delete_msg_cnf.msg = (wps_pmg_delete_msg_cnf_struct*) msg;
    mmi_frm_cb_emit_event((mmi_event_struct*)&evt_delete_msg_cnf);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_process_delete_all_msg_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_process_delete_all_msg_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_delete_all_cnf_struct evt_delete_all_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt_delete_all_cnf, EVT_ID_SRV_PUSH_PROCESS_DELETE_ALL_MSG_RSP);
    evt_delete_all_cnf.msg = (wps_pmg_delete_all_cnf_struct*) msg;
    mmi_frm_cb_emit_event((mmi_event_struct*)&evt_delete_all_cnf);

	#ifdef __DM_LAWMO_SUPPORT__
	(*g_srv_wap_push_cntxt->lawmo_cb)(MMI_TRUE,"PUSH");
	#endif /*__DM_LAWMO_SUPPORT__*/
}

#ifdef __MMI_PUSH_IN_UM__

/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_handle_delete_all_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_handle_delete_all_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   srv_wap_delete_all_res_struct evt_msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt_msgRsp,EVT_ID_MMI_UM_DELETE_ALL_RES);
    evt_msgRsp.msg = (srv_um_delete_all_res_struct*) msg;
    mmi_frm_cb_emit_event((mmi_event_struct*)&evt_msgRsp);
}

#if 0
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
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
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
#endif /* 0*/
#endif /* __MMI_PUSH_IN_UM__ */

/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_init_service_interface
 * DESCRIPTION
 *  Intialize the service layer interface functions
 * PARAMETERS
 *  void.
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_init_service_interface(void )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler((PsFuncPtr) srv_wap_push_handle_new_msg_ind, MSG_ID_WPS_PMG_NEW_MSG_IND);
    SetProtocolEventHandler(srv_wap_push_msg_delete_ind, MSG_ID_WPS_PMG_DELETE_IND);
    SetProtocolEventHandler((PsFuncPtr) srv_wap_push_replace_msg_ind, MSG_ID_WPS_PMG_REPLACE_IND);
    SetProtocolEventHandler(srv_wap_push_handle_storage_full_ind,MSG_ID_WPS_PMG_DLG_PUSH_STORAGE_FULL_IND);
    SetProtocolEventHandler(srv_wap_push_handle_pmg_ready_ind, MSG_ID_WPS_PMG_READY_IND);
    SetProtocolEventHandler(srv_wap_push_handle_msg_count_rsp, MSG_ID_WPS_PMG_MSG_COUNT_CNF);
    SetProtocolEventHandler((PsFuncPtr) srv_wap_push_handle_full_msg, MSG_ID_WPS_PMG_GET_MSG_CNF);
    SetProtocolEventHandler(srv_wap_push_msg_list_reply, MSG_ID_WPS_PMG_MSG_LIST_CNF);
#ifndef __MMI_WAP_PUSH_SIA_SLIM__
    SetProtocolEventHandler(srv_wap_push_service_initiation_req, MSG_ID_WPS_PMG_DLG_SIA_CONFIRM_REQ);
#endif
    SetProtocolEventHandler(srv_wap_push_handle_update_service_msg_cnf, MSG_ID_WPS_PMG_UPDATE_MSG_CNF);
    SetProtocolEventHandler(srv_wap_push_handle_update_all_service_msg_cnf, MSG_ID_WPS_PMG_UPDATE_ALL_MSG_CNF);
	
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    SetProtocolEventHandler(srv_wap_push_service_unknown_addr_req, MSG_ID_WPS_PMG_DLG_UNKNOWN_ADDR_REQ);
#endif
#if !defined(__MMI_WAP_PUSH_SIA_SLIM__) || defined(__MMI_WAP_PUSH_WHITE_LIST__) 
    SetProtocolEventHandler(srv_wap_push_handle_dlg_data_rsp, MSG_ID_WPS_PMG_DLG_QUERY_CNF);
#endif
    SetProtocolEventHandler(srv_wap_push_config_msg_cnf, MSG_ID_WPS_PMG_CONFIG_CNF);

#ifdef __MMI_PUSH_IN_UM__
	SetProtocolEventHandler(srv_wap_push_handle_delete_folder_ind, MSG_ID_WPS_PMG_DELETE_FOLDER_IND);
#endif /* __MMI_PUSH_IN_UM__ */ 

#ifdef __COSMOS_MMI_PACKAGE__
#ifdef __MMI_PUSH_IN_UM__
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_DELETE_ALL_RES, (PsIntFuncPtr) srv_wap_push_handle_delete_all_rsp, MMI_TRUE);
#if 0
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
/* under construction !*/
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
#endif /*0 */
#endif /* __MMI_PUSH_IN_UM__ */
#endif /*  __COSMOS_MMI_PACKAGE__ */

}

/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_get_profile_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  netAccId        [OUT]
 * RETURNS
 *  NetAccId.
 *****************************************************************************/
void srv_wap_push_get_profile_info (U16 sim_id, wps_pmg_channel_struct *ch_info)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

  srv_wap_prof_profile_content_struct *profile_content = NULL;
	int loop_count;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == WAP_PMG_SIM2)
    {
    #if (MMI_MAX_SIM_NUM >= 2)
        profile_content = &(g_srv_wap_push_cntxt->sim2_profile);
    #else
        ASSERT (0);
    #endif /* __MMI_WAP_DUAL_SIM__ */
    }
	else if (sim_id == WAP_PMG_SIM3)
    {
    #if (MMI_MAX_SIM_NUM >= 3)
  //  #if (defined(GEMINI_PLUS) && (GEMINI_PLUS == 3))
        profile_content = &(g_srv_wap_push_cntxt->sim3_profile);
    #endif /* __MMI_WAP_DUAL_SIM__ */
	}
	else if (sim_id == WAP_PMG_SIM4)
		    {
		           #if (MMI_MAX_SIM_NUM >= 4)
               // #if (defined(GEMINI_PLUS) && (GEMINI_PLUS == 4))
               profile_content = &(g_srv_wap_push_cntxt->sim4_profile);
                 #endif /* __MMI_WAP_DUAL_SIM__ */
	        }
  

    else
    {
        profile_content = &(g_srv_wap_push_cntxt->sim1_profile);
    }

    if (profile_content)
	{

		switch(profile_content->conn_type)
		{
		case SRV_WAP_PROF_CONN_TYPE_HTTP:
			ch_info->connection_type = WAP_PMG_CONNECTION_TYPE_HTTP;
			break;
		case SRV_WAP_PROF_CONN_TYPE_CONNECTION_OREINTED:
		case SRV_WAP_PROF_CONN_TYPE_CONNECTION_OREINTED_SECURE:
			ch_info->connection_type = WAP_PMG_CONNECTION_TYPE_WSP_CO;
			break;
		default:
			ASSERT(0);
			break;
		}

		for (loop_count = 0; loop_count < 4; loop_count++) {
			ch_info->proxy_ip[loop_count] = profile_content->proxy_ip[loop_count];
		}
		ch_info->proxy_port = profile_content->proxy_port;
		ch_info->network_account_id = profile_content->data_account_primary_id;

        memset((S8*) ch_info->username, '\0', WAP_PMG_USERNAME_PASSWORD_LEN);
        memset((S8*) ch_info->password, '\0', WAP_PMG_USERNAME_PASSWORD_LEN);

        strncpy((S8*) ch_info->username, (S8*) profile_content->username, WAP_PMG_USERNAME_PASSWORD_LEN - 1);
        strncpy((S8*) ch_info->password, (S8*) profile_content->password, WAP_PMG_USERNAME_PASSWORD_LEN - 1);
	}





}

/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_get_msg_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id        [OUT]
 *  call_back      [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_get_msg_content(U32 msg_id, srv_wap_push_get_msg_content_callback_func callback, void* user_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_pmg_get_msg_req_struct *local_data;
	U16 trans_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	trans_id = PUSH_GET_MSG_CONTENT_TRANS_ID;
	g_srv_wap_push_cntxt->msg_content_callback = callback;
	g_srv_wap_push_cntxt->msg_content_user_data = user_data;
    srv_wap_push_get_full_message(msg_id,trans_id);
}

#endif /* WAP_SUPPORT */
