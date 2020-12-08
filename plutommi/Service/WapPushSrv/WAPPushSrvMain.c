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
 * PushMsgMain.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains the function defination for logical handling of Service indication/Service loading.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include"dcl.h"
#include "MMI_features.h"

#include "time.h"
//#include "SimDetectionGprot.h"
#ifdef __MMI_EMAIL__
#include "EmailAppGProt.h"
#endif
//#ifdef MMS_SUPPORT
//#include "mmsadp.h"
//#endif /* MMS_SUPPORT */
//#include "wapadp.h"
//#include "app_url.h"
#ifdef __MMI_PUSH_IN_UM__
#include "UMSrvDefs.h"
#include "UMSrvStruct.h"
#endif /* __MMI_PUSH_IN_UM__ */
//#if defined(__MMI_WLAN_FEATURES__)
//#include "NetworkSetupDefs.h"
//#endif
#include "WapPushSrvProts.h"
#include "ModeSwitchSrvGProt.h"
#include "SimCtrlSrvGprot.h"

    #include "WAPPushSrvTypes.h"
    #include "kal_public_defs.h"
    #include "MMIDataType.h"
    #include "WAPPushUITypes.h"
    #include "app_ltlcom.h"
    #include "stack_config.h"
    #include "stack_ltlcom.h"
    #include "task_config.h"
    #include "mmi_frm_queue_gprot.h"
    #include "string.h"
    #include "stdlib.h"
    #include "kal_public_api.h"
    #include "kal_general_types.h"
  //  #include "rtc_sw.h"
    #include "mmiapi_dm_struct.h"
    #include "dmuigprot.h"
#ifdef __DM_LAWMO_SUPPORT__
    #include "DmSrvGprot.h"
#endif /*__DM_LAWMO_SUPPORT__*/
    #include "DebugInitDef_Int.h"
    #include "kal_trace.h"
    #include "mmi_inet_app_trc.h"
    #include "MMI_inet_app_trc.h"
    #include "UcmSrvGprot.h"
    #include "pmg_struct.h"
    #include "custom_phb_config.h"
    #include "common_nvram_editor_data_item.h"
 //  #if defined(__VODAFONE_R12_LIVE__)  
  //  #include "op_custom_wap_config.h"
// #endif /* defined(__VODAFONE_R12_LIVE__) */

    #include "WAPPushSrvGprots.h"
    #include "mmi_frm_events_gprot.h"
    #include "mmi_cb_mgr_gprot.h"
    #include "GlobalResDef.h"
    #include "browser_api.h"
    #include "gui_typedef.h"
    #include "wgui_categories_util.h"
    #include "mmi_frm_scenario_gprot.h"
   
    #include "WAPPushResDef.h"
    #include "CustDataRes.h"
    #include "Unicodexdcl.h"
    #include "mms_api.h"
  //  #include "SimDetectionStruct.h"
    #include "WAPProfileSrvType.h"
    #include "WAPProfileSrvGProt.h"
    #include "mmi_frm_mem_gprot.h"
    #include "stack_msgs.h"
    #include "UmSrvDefs.h"
    #include "UmSrvStruct.h"
    #include "NotificationSettingSrvGprot.h" //for NSS
#ifdef __WAP_PUSH_SUPPORT__
  #ifndef __COSMOS_MMI_PACKAGE__
    #include "mmi_rp_app_mmi_wap_push_def.h"
    #endif

#ifndef __MMI_PUSH_IN_UM__
U64 g_nmgr_handle_unread=0;
#endif 
srv_wap_push_cntxt_struct *g_srv_wap_push_cntxt;
KAL_ADM_ID g_push_adm_id;
U8 g_push_mem_pool[SRV_WAP_PUSH_MAX_MEM_SIZE]; 
srv_wap_push_msg_inbox_struct  *g_push_inbox_ctxt;
static MMI_BOOL readstatus;

/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_msg_read_status_base_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  read_status         [IN]
 * RETURNS
 *  void.
 *****************************************************************************/
void srv_wap_push_msg_read_status_base_func(MMI_BOOL read_status)
{
readstatus = read_status;
}

/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_send_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  message_id        [IN]
 *  msg_data          [IN]
 * RETURNS
 *  void.
 *****************************************************************************/
void srv_wap_push_send_msg (U16 message_id, void *msg_data, U16 destination, U16 sap_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_data;
    ilm_ptr->msg_id = (msg_type) message_id;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_MMI,(module_type)destination,(sap_type)sap_id, ilm_ptr);
}

/*****************************************************************************
 * FUNCTION
 * srv_get_push_unread_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *   void   [IN]
 * RETURNS
 * U32
 *****************************************************************************/

U32 srv_get_push_unread_count (void) 
{
	return g_srv_wap_push_cntxt->unread_msgs_count;
}



/* SKS */

/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_msg_read_status
 * DESCRIPTION
 *  send primitive MSG_ID_WPS_PMG_MSG_READ_STATUS_REQ to WPS 
 * PARAMETERS
 *  message_id        [IN]
 *  statusFunc         [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/


MMI_BOOL srv_wap_push_msg_read_status (U32 msg_id)
{
	
	 wps_pmg_msg_read_status_req_struct* local_data = NULL;
	 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	local_data = (wps_pmg_msg_read_status_req_struct*) construct_local_para(sizeof(wps_pmg_msg_read_status_req_struct), TD_CTRL);
		local_data->msg_id = msg_id;
		local_data->status_func= (srv_wap_push_msg_read_status_func) srv_wap_push_msg_read_status_base_func;
		readstatus = MMI_FALSE;
		srv_wap_push_send_msg (MSG_ID_WPS_PMG_MSG_READ_STATUS_REQ, (void*)local_data, MOD_WPS, WPS_APP_SAP);
return readstatus;
}



/* SKS */

/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_send_msg_to_mmi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  message_id        [IN]
 *  msg_data          [IN]
 * RETURNS
 *  void.
 *****************************************************************************/
void srv_wap_push_send_msg_to_mmi (U16 message_id, void *msg_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 //   MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /* Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = message_id;
    Message.oslDataPtr = (oslParaType*) msg_data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
   */
    mmi_frm_send_ilm(MOD_MMI,(msg_type)message_id,(oslParaType *)msg_data,NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_check_ip
 * DESCRIPTION
 *  Function to validate the IP
 * PARAMETERS
 *  ip      [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 srv_wap_push_check_ip(S8 *ip)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 seps[] = ".";
    S8 *token;
    S32 ip_sec = 0;
    U16 ip_sum = 0;
    char *last_ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1st char of ip or hostname can't be '.' */
    if (ip[0] == '.' || ip[strlen(ip) - 1] == '.')
    {
        goto err;
    }

    token = strtok_r(ip, seps, &last_ptr);
    while (token)
    {
        U16 i;

        for (i = 0; i < strlen(token); i++)
        {
            if (i >= 3)
            {
                goto err;
            }

            if (token[i] < '0' || token[i] > '9')
            {
                goto err;
            }
        }

        /* this segement is ip format */
        ip_sec++;

        ip_sum += atoi (token);
        token = strtok_r(NULL, seps, &last_ptr);
    }

    if (ip_sec != 4)
    {
        goto err;
    }
    if (ip_sum == 0)
    {
        goto err;
    }
    return 1;

  err:
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_convert_proxy_ipstring_to_array
 * DESCRIPTION
 *  This converts an IP string into an array
 * PARAMETERS
 *  parm_element_p      [IN]        
 *  proxy_ip_p          [IN]        
 * RETURNS
 *  U8               [OUT]
 *****************************************************************************/
srv_wap_push_ret_code_enum srv_wap_push_convert_proxy_ipstring_to_array(U8 *parm_element_p, U8 *proxy_ip_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 proxy[SRV_WAP_PUSH_MAX_PART_IP_ADDRESS];
    U32 i, j;
    U32 ip_part;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_wap_push_check_ip((S8*) parm_element_p))
    {
        return SRV_WAP_PUSH_ERR;
    }
    if ((*parm_element_p) < '0' || (*parm_element_p) > '9')
    {
        return SRV_WAP_PUSH_ERR;
    }

    for (j = 0; j < SRV_WAP_PUSH_MAX_PART_IP_ADDRESS; ++j)
    {
        for (i = 0; (i < SRV_WAP_PUSH_MAX_PART_IP_ADDRESS - 1) && (strlen((S8*) parm_element_p));)
        {
            if (*parm_element_p == '.')
            {
                break;
            }
            if ((*parm_element_p) >= '0' && (*parm_element_p) <= '9')
            {
                proxy[i] = *parm_element_p++;
                i++;
            }
            else
            {
                return SRV_WAP_PUSH_ERR;
            }
        }
        proxy[i] = '\0';
        ip_part = (U32) atoi(proxy);
        if (ip_part > SRV_WAP_PUSH_IP_PART_MAX_VALUE)
        {
            return SRV_WAP_PUSH_ERR;
        }
        proxy_ip_p[j] = (U8) ip_part;
        ++parm_element_p;
    }
    return SRV_WAP_PUSH_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_malloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *srv_wap_push_malloc(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = kal_adm_alloc(g_push_adm_id, (kal_uint32) size);
    return ptr;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_mfree
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptr     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_mfree(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_adm_free(g_push_adm_id, ptr);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_get_current_utc_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void.
 * RETURNS
 *  Return the current UTC time.
 *****************************************************************************/
U32 srv_wap_push_get_current_utc_time (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 timeSecs;
#ifndef __MTK_TARGET__
    time_t ltime;
#else
  //  t_rtc rtc;
	 DCL_HANDLE rtc_handler;
     RTC_CTRL_GET_TIME_T rtc_cmd_data3;
    struct tm when;
#endif /* __MTK_TARGET__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MTK_TARGET__
    timeSecs = (U32) time(&ltime);
	timeSecs = applib_dt_sec_utc_to_local(timeSecs);
#else /* __MTK_TARGET__ */ 
   /* RTC_GetTime(&rtc);
    when.tm_sec = rtc.rtc_sec;
    when.tm_min = rtc.rtc_min;
    when.tm_hour = rtc.rtc_hour;
    when.tm_mday = rtc.rtc_day;
    when.tm_mon = rtc.rtc_mon - 1;
    when.tm_year = rtc.rtc_year + 100;
    when.tm_isdst = 0;
	*/
    rtc_handler = DclRTC_Open(DCL_RTC, FLAGS_NONE);
    DclRTC_Control(rtc_handler, RTC_CMD_GET_TIME, (DCL_CTRL_DATA_T *)&rtc_cmd_data3); // New API with CMD & DATA 
  
    when.tm_sec = rtc_cmd_data3.u1Sec;
    when.tm_min = rtc_cmd_data3.u1Min;
    when.tm_hour = rtc_cmd_data3.u1Hour;
    when.tm_mday = rtc_cmd_data3.u1Day;
    when.tm_mon =rtc_cmd_data3.u1Mon-1;
    when.tm_year = rtc_cmd_data3.u1Year+100;
    when.tm_isdst = 0;
    timeSecs = (U32) mktime(&when);
#endif /* __MTK_TARGET__ */ 
    return timeSecs;
}


#ifdef __DM_LAWMO_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_handle_del_all_rsp_for_lawmo
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result         [IN]
 * RETURNS
 *  void.
 *****************************************************************************/
void srv_wap_push_handle_del_all_rsp_for_lawmo (MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_MSG_SEND_LAWMO_RSP, (U16) result);
	if(result == MMI_TRUE)
	{
        (*g_srv_wap_push_cntxt->lawmo_cb)(MMI_TRUE,"PUSH");
    }
    else
    {
        (*g_srv_wap_push_cntxt->lawmo_cb)(MMI_FALSE,"PUSH");
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_handle_lawmo_request
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id         [IN]
 *  cmd            [IN]
 * RETURNS
 *  void.
 *****************************************************************************/


mmi_ret  srv_wap_push_handle_lawmo_request (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	srv_dm_lawmo_wipe_ind_evt_struct *lawmo_wipe_ind  = (srv_dm_lawmo_wipe_ind_evt_struct*)evt;

	switch(lawmo_wipe_ind->cmd)
    {
		
			
		case SRV_DM_LAWMO_WIPE_CMD_APP_WIPE:
        {

                srv_wap_push_delete_all_msg_req(PUSH_DELETE_ALL_FOR_LAWMO);

				g_srv_wap_push_cntxt->lawmo_cb = lawmo_wipe_ind->cb;

                break;
            }
        default:
            break;
        }
	
return MMI_RET_OK;
    }

#endif /* __DM_LAWMO_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_enque_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  message_id         [IN]
 *  type               [IN]
 * RETURNS
 *  TRUE if success otherwise false.
 *****************************************************************************/
MMI_BOOL srv_wap_push_enque_msg (U32 message_id, U16 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_idle_messge_queue_struct  *node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return srv_wap_push_enque_msg_ex(message_id, type, NULL);

	/*

    node = (srv_wap_push_idle_messge_queue_struct*) srv_wap_push_malloc (sizeof (srv_wap_push_idle_messge_queue_struct));
    if (node == NULL)
    {
        MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_MSG_QUEUEING_FAILED_MEMORY_NOT_ENOGH, message_id, type);
        return MMI_FALSE;
    }
    else
    {
        node->message_id = message_id;
        node->msg_type = type;
        node->next = NULL;
        if (g_srv_wap_push_cntxt->message_queue_front == NULL)
        {
            g_srv_wap_push_cntxt->message_queue_front = node;
            g_srv_wap_push_cntxt->message_queue_rear = node;
        }
        else
        {
            g_srv_wap_push_cntxt->message_queue_rear->next = node;
            g_srv_wap_push_cntxt->message_queue_rear = g_srv_wap_push_cntxt->message_queue_rear->next;
        }
        MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_MSG_QUEUED_FOR_IDLE_PROCESS, message_id, type);
        return MMI_TRUE;
    }*/
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_enque_msg_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  message_id         [IN]
 *  type               [IN]
 * RETURNS
 *  TRUE if success otherwise false.
 *****************************************************************************/
MMI_BOOL srv_wap_push_enque_msg_ex (U32 message_id, U16 type, S8 *info_char)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_idle_messge_queue_struct  *node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node = (srv_wap_push_idle_messge_queue_struct*) srv_wap_push_malloc (sizeof (srv_wap_push_idle_messge_queue_struct));
    if (node == NULL)
    {
        MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_MSG_QUEUEING_FAILED_MEMORY_NOT_ENOGH, message_id, type);
        return MMI_FALSE;
    }
    else
    {
        node->message_id = message_id;
        node->msg_type = type;
		if(info_char)
		{
			memset(node->msg_info,0,sizeof(node->msg_info));
			mmi_asc_n_to_ucs2((S8*)node->msg_info,(S8*)info_char,MAX_NOTIFICATION_INFO_LEN);

		}
        node->next = NULL;
        if (g_srv_wap_push_cntxt->message_queue_front == NULL)
        {
            g_srv_wap_push_cntxt->message_queue_front = node;
            g_srv_wap_push_cntxt->message_queue_rear = node;
        }
        else
        {
            g_srv_wap_push_cntxt->message_queue_rear->next = node;
            g_srv_wap_push_cntxt->message_queue_rear = g_srv_wap_push_cntxt->message_queue_rear->next;
        }
        MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_MSG_QUEUED_FOR_IDLE_PROCESS, message_id, type);
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_get_first_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void.
 * RETURNS
 *  the first message of the message queue.
 *****************************************************************************/
srv_wap_push_idle_messge_queue_struct* srv_wap_push_get_first_msg (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_wap_push_cntxt->message_queue_front;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_delete_from_msg_queue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  message_id          [IN]
 * RETURNS
 *  void.
 *****************************************************************************/
void srv_wap_push_delete_from_msg_queue (U32 message_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_idle_messge_queue_struct  *node = NULL;
    srv_wap_push_idle_messge_queue_struct  *prev = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_MSG_DEL_FROM_QUEUE, message_id);
    if (g_srv_wap_push_cntxt->message_queue_front == NULL)
    {
        return;
    }
    /* Deleting the first node */
    if (message_id == g_srv_wap_push_cntxt->message_queue_front->message_id)
    {
        node = g_srv_wap_push_cntxt->message_queue_front;
        g_srv_wap_push_cntxt->message_queue_front = g_srv_wap_push_cntxt->message_queue_front->next;
        srv_wap_push_mfree (node);
        MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_MSG_DEL_FROM_QUEUE_MSG_DELETED);
    }
    else
    {
        node = g_srv_wap_push_cntxt->message_queue_front->next;
        prev = g_srv_wap_push_cntxt->message_queue_front;
        while (node)
        {
            if (message_id == node->message_id)
            {
                prev->next = node->next;
                if (node == g_srv_wap_push_cntxt->message_queue_rear)
                {
                    g_srv_wap_push_cntxt->message_queue_rear = prev;
                }
                srv_wap_push_mfree (node);
                MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_MSG_DEL_FROM_QUEUE_MSG_DELETED);
                return;
            }

            prev = node;
            node = node->next;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_delete_all_queue_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void.
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_delete_all_queue_entry (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_idle_messge_queue_struct  *node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_MSG_DEL_ALL_MESSAGES_FROM_QUEUE);
    while (g_srv_wap_push_cntxt->message_queue_front)
    {
        node = g_srv_wap_push_cntxt->message_queue_front;
        g_srv_wap_push_cntxt->message_queue_front = g_srv_wap_push_cntxt->message_queue_front->next;
        srv_wap_push_mfree (node);
    }
    g_srv_wap_push_cntxt->message_queue_front = NULL;
    g_srv_wap_push_cntxt->message_queue_rear = NULL;
}


#ifndef __MMI_BACKGROUND_CALL__
/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_check_is_call_screen_active
 * DESCRIPTION
 *  Checks if the active screen is a call screen, this is for popup only.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_wap_push_check_is_call_screen_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}
#endif /* __MMI_BACKGROUND_CALL__ */ 



/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_is_active_call
 * DESCRIPTION
 *  This function can be used to determine whether or not an Active MMI call is present.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if MMI call present.
 *****************************************************************************/
MMI_BOOL srv_wap_push_is_active_call (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
	{
		if(((srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)==1) && 
            (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CSD_CALL_TYPE_ALL, NULL) > 0))
		{
			return MMI_FALSE ;
		}
		return MMI_TRUE;
	}
	else
	{
		return MMI_FALSE;
	}
}


#ifdef __MMI_WAP_PUSH_WHITE_LIST__
/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_prepare_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ascii_addr     [OUT]
 *  sender         [IN]
 *  smsc           [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_prepare_address(S8 *ascii_addr, pmg_addr_struct *sender, pmg_addr_struct *smsc)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 sep[2] = {WAP_PMG_ADDR_PHONE_SEP,'\0'};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if((sender->addr_type == WAP_PMG_ADDR_PHONE) || (smsc->addr_type == WAP_PMG_ADDR_PHONE))
	{
		if(sender->addr && sender->addr[0] != '\0')
		{
			strcpy((S8*) ascii_addr, (S8*) sender->addr);
		}
		if(ascii_addr[0] == '\0')
		{
			strcpy((S8*) ascii_addr, (S8*) sep);
		}
		else
		{
			strcat((S8*) ascii_addr, (S8*) sep);
		}
		if(smsc->addr && smsc->addr[0] != '\0')
		{
			strcat((S8*) ascii_addr, (S8*) smsc->addr);
		}
		strcat((S8*) ascii_addr, (S8*) sep);
	}
	else
	{
		if(sender->addr && sender->addr[0] != '\0')
		{
			strcpy((S8*) ascii_addr, (S8*) sender->addr);
		}
		else
		{
			strcpy((S8*) ascii_addr, (S8*) smsc->addr);
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_add_unknwn_addr_to_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void.
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_add_unknwn_addr_to_list(U16 list_type)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 ascii_addr[NVRAM_PUSH_SENDER_ADDR_LEN_MAX] = {'\0',};
	U16 max = 0;
	U16 total = 0;
	srv_wap_push_add_list_error_enum  add_error = SRV_WAP_PUSH_ERROR_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_ADD_UNKNWN_ADDR_IN_LIST, list_type);
	if(list_type == SRV_WAP_PUSH_WHITE_LIST)
	{
		total = g_push_set_p->total_wl_entry;
		max = NVRAM_PUSH_MAX_NUM_WHITE_LIST;
	}
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
	else
	{
		total = g_push_set_p->total_bl_entry;
		max = NVRAM_PUSH_MAX_NUM_BLACK_LIST;
	}
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
	if(total >= max)
	{
		return;
	}
	srv_wap_push_prepare_address(
		ascii_addr, 
		&g_srv_wap_push_cntxt->curr_dlg->dlg_data.msg.from,
		&g_srv_wap_push_cntxt->curr_dlg->dlg_data.msg.smsc);

	add_error = srv_wap_push_add_modify_list(ascii_addr, 
		g_srv_wap_push_cntxt->curr_dlg->dlg_data.msg.from.addr_type, 
		list_type, 
		total);
	if(add_error == SRV_WAP_PUSH_ERROR_SUCCESS)
	{
		if(list_type == SRV_WAP_PUSH_WHITE_LIST)
		{
			g_push_set_p->total_wl_entry++;
			srv_wap_send_white_list_to_service_layer();
		}
    #ifdef __MMI_WAP_PUSH_BLACK_LIST__
		else
		{
			g_push_set_p->total_bl_entry++;
			srv_wap_send_black_list_to_service_layer();
		}
    #endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
	}
}
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_delete_message_generic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_delete_message_generic (U32 msg_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_progress_event_struct evt_progress;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_GENERIC_DELETE, msg_id);
    MMI_FRM_INIT_EVENT(&evt_progress, EVT_ID_SRV_PUSH_SHOW_PROGRESS);
	srv_wap_push_delete_from_msg_queue (msg_id);
	srv_wap_push_send_del_req_to_pmg (msg_id, PUSH_DEL_MESSAGE_GENERIC_TRANS_ID);
    mmi_frm_cb_emit_event((mmi_event_struct*)&evt_progress);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_check_browser_load_in_call
 * DESCRIPTION
 *  helper function to show a pop-up by callback manager
 * PARAMETERS
 *  evt_notify  [IN]
 *  str_id      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_event_based_display_popup(srv_wap_push_event_notify_enum evt_notify, U16 str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_popup_event_struct evt_popup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt_popup, EVT_ID_SRV_PUSH_SHOW_POPUP);
    evt_popup.evt_notify = evt_notify;
    evt_popup.str_notify = str_id;
    mmi_frm_cb_emit_event((mmi_event_struct*)&evt_popup);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_check_browser_load_in_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_wap_push_check_browser_load_in_call (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        if(!srv_ucm_is_background_call())
        {
            srv_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_FAILURE, STR_GLOBAL_NOT_AVAILABLE_DURING_VIDEO_CALL);
            return MMI_TRUE;
        }
    }
#else
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        if ((srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0) ||
            (srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0))
        {
            srv_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_FAILURE, STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL);
            return MMI_TRUE;
        }
    }
#endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_handle_msg_deleted_by_server_ind
 * DESCRIPTION
 *  Handle the auto message deletion either by delete indication or replace indication
 * PARAMETERS
 *  msg         [IN]
 *  replaced    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_handle_msg_deleted_by_server_ind (wps_pmg_delete_ind_struct* msg, MMI_BOOL replaced)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_msg_deleted_by_server_ind_struct evt_msg_del;
    S16 count;
    wps_pmg_delete_ind_struct *delete_msg_ind = (wps_pmg_delete_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	g_srv_wap_push_cntxt->unread_msgs_count = delete_msg_ind->msg_count;

    for (count = 0; count < (S16)delete_msg_ind->size; count++)
    {
        srv_wap_push_delete_from_msg_queue(delete_msg_ind->msgs->msg_id);
    }
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_DELETE_INDICATION_FOR_N_MESSAGES, count);
    MMI_FRM_INIT_EVENT(&evt_msg_del, EVT_ID_SRV_PUSH_MSG_DELETED_BY_SERVER_IND);
    evt_msg_del.count = count;
    evt_msg_del.msg_id = delete_msg_ind->msgs->msg_id;
	
    mmi_frm_cb_emit_event((mmi_event_struct*)&evt_msg_del);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_get_push_app_sim_id_from_pmg_sim_id
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_wap_push_get_push_app_sim_id_from_pmg_sim_id (U16 pmg_sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (pmg_sim_id)
    {
    case WAP_PMG_SIM1:
        return SRV_WAP_PUSH_ACTIVE_SIM_SIM1;
        
    case WAP_PMG_SIM2:
        return SRV_WAP_PUSH_ACTIVE_SIM_SIM2;
        
    default:
        return SRV_WAP_PUSH_ACTIVE_SIM_SIM1;
        
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_handle_new_service_msg
 * DESCRIPTION
 *  This function handles the different behaviour of new service message
 * PARAMETERS
 *  new_msg        [IN]
 *  url            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_handle_new_service_msg (pmg_detailed_msg_struct *new_msg, S8 *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_handle_new_service_msg_struct evt_new_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt_new_msg, EVT_ID_SRV_PUSH_HANDLE_NEW_SERVICE_MSG);
    evt_new_msg.new_msg = new_msg;
    evt_new_msg.url = url;
    evt_new_msg.enable_push = g_push_set_p->general_set.enable_push;
    mmi_frm_cb_emit_event((mmi_event_struct*)&evt_new_msg);    
}

/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_update_status_icon_default_sim
 * DESCRIPTION
 *  This API show or hide the status icon based on the parameter passed.
 * PARAMETERS
 *  show_icon      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_update_status_icon_default_sim (U32 show_icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 status_icon;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (show_icon != 0)
    {
		if (srv_sim_ctrl_get_one_available_sim()
          #if defined (__FLIGHT_MODE_SUPPORT__)

      &&  (srv_mode_switch_is_network_service_available()) 
        #endif 
		)
        {
		 #ifndef __MMI_PUSH_IN_UM__
		//	ShowStatusIcon(STATUS_ICON_WAP);
			  mmi_frm_nmgr_alert_struct alert_info;
			  memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct));   
				/*fill in app id for NSS query*/
               #ifdef __PLUTO_MMI_PACKAGE__
               alert_info.app_id = APP_MMI_WAP_PUSH; //your app id
               #endif 
                /*fill in the basic info*/
			 alert_info.event_type = MMI_EVENT_MMS;
             alert_info.scen_id = MMI_SCENARIO_ID_WAP_PUSH; // your scenario ID
             alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_ICON_MASK;
             alert_info.status_bar_icon_para.icon_id = STATUS_ICON_WAP;
             alert_info.behavior_mask = FORCE_ICON_ONLY;
             alert_info.alert_option = MMI_FRM_NMGR_DISABLE_TONE| MMI_FRM_NMGR_DISABLE_VIB;
             g_nmgr_handle_unread=mmi_frm_nmgr_alert(&alert_info); 
         #endif
        }
        else
        {
		 //	HideStatusIcon(STATUS_ICON_WAP);
			#ifndef __MMI_PUSH_IN_UM__
			if(g_nmgr_handle_unread)
              mmi_frm_nmgr_alert_cancel (g_nmgr_handle_unread);
            #endif
            // Need to send refresh to remove UM status icon
            #ifdef __MMI_PUSH_IN_UM__
            srv_wap_push_send_um_refresh_ind(0,SRV_UM_REFRESH_MSG_DELETED ,NULL);
            #endif
        }
    }
    else
    {
		//	HideStatusIcon(STATUS_ICON_WAP);
		#ifndef __MMI_PUSH_IN_UM__
        if(g_nmgr_handle_unread)
              mmi_frm_nmgr_alert_cancel (g_nmgr_handle_unread);
        #endif
        // Need to send refresh to remove UM status icon
         #ifdef __MMI_PUSH_IN_UM__
           srv_wap_push_send_um_refresh_ind(0,SRV_UM_REFRESH_MSG_DELETED ,NULL);
         #endif
    }
 //   UpdateStatusIcons();
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_check_pendig_event_on_idle
 * DESCRIPTION
 *  IDLE screen callback function to check whether any Pending event exists to the application.
 * PARAMETERS
 *  void
 * RETURNS
 *  return 1 if any pending event otherwise 0.
 *****************************************************************************/
U8 srv_wap_push_check_pendig_event_on_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_push_inbox_ctxt->title_icon_id = 0; /* When user move to IDLE */
     #ifndef __MMI_NCENTER_SUPPORT__
    g_srv_wap_push_cntxt->read_from_um = MMI_FALSE;
    if ((g_srv_wap_push_cntxt->message_queue_front != NULL) )
    {
        return 1;
    }
    else
     #endif
    {
        return 0;
    }
}

//extern MMI_ID mmi_wap_push_create_idle_callback_group(void);
/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_handle_pendig_event_on_idle
 * DESCRIPTION
 *  Callback function to process the pending events on IDLE.
 * PARAMETERS
 *  void
 * RETURNS
 *  void.
 *****************************************************************************/
void srv_wap_push_handle_pendig_event_on_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_handle_pendig_event_on_idle_struct evt_pendig;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt_pendig, EVT_ID_SRV_PUSH_HANDLE_PENDIG_EVENT_ON_IDLE);
    mmi_frm_cb_emit_event((mmi_event_struct*)&evt_pendig);
}



/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_service_dlg_idle_scr_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  return 1 if any pending dialogue otherwise 0.
 *****************************************************************************/
U8 srv_wap_push_service_dlg_idle_scr_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if !defined(__MMI_WAP_PUSH_SIA_SLIM__) || defined(__MMI_WAP_PUSH_WHITE_LIST__) 
	 #ifndef __MMI_NCENTER_SUPPORT__
	if ((g_srv_wap_push_cntxt->dlg_front))
	{
		return 1;
	}
     #endif
     #endif
	return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_fetch_dlg_from_queue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void.
 * RETURNS
 *  void.
 *****************************************************************************/
void srv_wap_push_fetch_dlg_from_queue(void)
{
   #if !defined(__MMI_WAP_PUSH_SIA_SLIM__) || defined(__MMI_WAP_PUSH_WHITE_LIST__) 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_fetch_dlg_from_queue_struct evt_fetch_dlg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt_fetch_dlg, EVT_ID_SRV_PUSH_FETCH_DLG_QUEUE);
    mmi_frm_cb_emit_event((mmi_event_struct*)&evt_fetch_dlg);
    #endif
}


#ifndef __MMI_WAP_PUSH_ADVANCED_FEATURE_SLIM__
/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_construct_send_by_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer          [IN/OUT]
 * RETURNS
 *  void.
 *****************************************************************************/
void srv_wap_push_construct_send_by_data (S8 *buffer)
{
#ifndef __COSMOS_MMI_PACKAGE__   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL href_copied = MMI_FALSE;
    S8 ucs2_str[20];
    S8 ucs2_temp[(WAP_PMG_MAX_MSG_HREF_CHARS + 1) * ENCODING_LENGTH] = {'\0',};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_START_SEND_BY_CONSTRUCT_DATA);
    MMI_ASSERT (buffer);
    if (g_srv_wap_push_cntxt->selected_message.url[0] != '\0')
    {
        mmi_ucs2cpy((S8*) buffer, GetString(STR_ID_BRW_PUSH_URL_TITLE));
        mmi_asc_to_ucs2((S8*) ucs2_str, "\n");
        mmi_ucs2cat(buffer, ucs2_str);
        mmi_asc_to_ucs2((S8*) ucs2_temp, (S8*) g_srv_wap_push_cntxt->selected_message.url);
        mmi_ucs2cat((S8*) buffer, ucs2_temp);
        href_copied = MMI_TRUE;
    }
    if (g_srv_wap_push_cntxt->selected_message.text[0] != '\0')
    {
        if (href_copied)
        {
            mmi_ucs2cat(buffer, ucs2_str);
            mmi_ucs2cat((S8*) buffer, GetString(STR_ID_BRW_PUSH_MESSAGE_TITLE));
        }
        else
        {
            mmi_ucs2cpy((S8*) buffer, GetString(STR_ID_BRW_PUSH_MESSAGE_TITLE));
        }
        mmi_asc_to_ucs2((S8*) ucs2_str, "\n");
        mmi_ucs2cat(buffer, ucs2_str);
        
        if (g_srv_wap_push_cntxt->selected_message.text_type == WAP_PMG_STRTYPE_UCS2)
        {
            mmi_ucs2cat((S8*) buffer, (S8*) g_srv_wap_push_cntxt->selected_message.text);
        }
        else
        {
            memset (ucs2_temp, 0, ((WAP_PMG_MAX_MSG_HREF_CHARS + 1) * ENCODING_LENGTH));
            mmi_asc_n_to_ucs2((S8*) ucs2_temp, (S8*) g_srv_wap_push_cntxt->selected_message.text, WAP_PMG_MAX_MSG_HREF_CHARS);
            mmi_ucs2cat((S8*) buffer, ucs2_temp);
        }
    }
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_END_SEND_BY_CONSTRUCT_DATA);
#endif /*__COSMOS_MMI_PACKAGE__*/
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_calculate_send_by_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  return size of the data to be sent.
 *****************************************************************************/
U16 srv_wap_push_calculate_send_by_size (void)
{
  #ifndef __COSMOS_MMI_PACKAGE__ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_wap_push_cntxt->selected_message.text[0] != '\0')
    {
        if (g_srv_wap_push_cntxt->selected_message.text_type == WAP_PMG_STRTYPE_UCS2)
        {
            size = mmi_ucs2strlen((S8*)g_srv_wap_push_cntxt->selected_message.text);
        }
        else
        {
            size = strlen((S8*)g_srv_wap_push_cntxt->selected_message.text);
        }
    }
    if (g_srv_wap_push_cntxt->selected_message.url[0] != '\0')
    {
        size += strlen((S8*)g_srv_wap_push_cntxt->selected_message.url);
    }
    size += mmi_ucs2strlen((S8*) GetString (STR_ID_BRW_PUSH_URL_TITLE));
    size += mmi_ucs2strlen((S8*) GetString (STR_ID_BRW_PUSH_MESSAGE_TITLE));
    size += 4; /* For "\n" */
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_SEND_BY_SIZE, size);
    return (size * ENCODING_LENGTH);
#else
return 0;
#endif /*__COSMOS_MMI_PACKAGE__*/ 
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_construct_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  return data.
 *****************************************************************************/
S8* srv_wap_push_construct_data (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 *ucs2_data = NULL;
    U16 size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    size = srv_wap_push_calculate_send_by_size();
    ucs2_data = (S8*) srv_wap_push_malloc(size + 2);
    if (ucs2_data == NULL)
    {
        return NULL;
    }
    memset (ucs2_data, 0, (size+ 2));
    srv_wap_push_construct_send_by_data(ucs2_data);
    return ucs2_data;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_send_by_mms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_send_by_mms (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 *ucs2_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifndef __COSMOS_MMI_PACKAGE__
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_ENTER_SEND_BY_MMS);
    ucs2_data = srv_wap_push_construct_data();
    if (!ucs2_data)
    {
        srv_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_PROPLEM, STR_GLOBAL_MEMORY_FULL);
        return;
    }

#ifdef MMS_SUPPORT
    mms_text_insert_hdlr (NULL, 0, ucs2_data, mmi_ucs2strlen(ucs2_data));
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_MMS_ACTIVATED);
#endif
    srv_wap_push_mfree (ucs2_data);
#endif /*__COSMOS_MMI_PACKAGE__*/
}

#ifndef __MMI_WAP_PUSH_ADVANCED_FEATURE_SLIM__
/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_send_by_email
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_send_by_email (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 *ucs2_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_ENTER_SEND_BY_EMAIL);
    ucs2_data = srv_wap_push_construct_data();
    if (!ucs2_data)
    {
        srv_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_PROPLEM, STR_GLOBAL_MEMORY_FULL);
        return;
    }

#ifdef __MMI_EMAIL__
    mmi_email_app_send_cont(ucs2_data);
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_EMAIL_ACTIVATED);
#endif
    srv_wap_push_mfree (ucs2_data);
}

#endif
#endif
/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_delete_all_messages
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_delete_all_messages (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_progress_event_struct event;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_wap_push_delete_all_msg_req(PUSH_DELETE_ALL_FROM_MESSAGE_OPTIONS);
    MMI_FRM_INIT_EVENT(&event, EVT_ID_SRV_PUSH_SHOW_PROGRESS);
    mmi_frm_cb_emit_event((mmi_event_struct*)&event);
}


#ifdef __MMI_WAP_PUSH_WHITE_LIST__
/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_add_to_validation_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_add_to_validation_list (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 ascii_addr[NVRAM_PUSH_SENDER_ADDR_LEN_MAX] = {'\0',};
	S8 sep[2] = {WAP_PMG_ADDR_PHONE_SEP,'\0'};
    U16 *total_entry = NULL;
    void (*commit_func)(void)=NULL;
    
	srv_wap_push_add_list_error_enum  add_error = SRV_WAP_PUSH_ERROR_SUCCESS;
    srv_wap_push_selected_msg_struct *temp = &(g_srv_wap_push_cntxt->selected_message);

    srv_wap_push_delete_setting_struct evt_del_setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_FRM_INIT_EVENT(&evt_del_setting, EVT_ID_SRV_PUSH_DELETE_PUSH_SETTING);
    mmi_frm_cb_emit_event((mmi_event_struct*)&evt_del_setting);
    //    mmi_wap_push_delete_previous_push_setting_instance_if_present();
    if (g_srv_wap_push_cntxt->add_list_type == SRV_WAP_PUSH_WHITE_LIST)
    {
        total_entry = &(g_push_set_p->total_wl_entry);
        commit_func = &srv_wap_send_white_list_to_service_layer;
    }
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    else
    {
        total_entry = &(g_push_set_p->total_bl_entry);
        commit_func = &srv_wap_send_black_list_to_service_layer;
    }
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
	switch (temp->from.addr_type)
	{
	case WAP_PMG_ADDR_PHONE:
		strcpy((S8*) ascii_addr, (S8*) temp->from.addr);
		strcat((S8*)ascii_addr,(S8*)sep);
		strcat((S8*) ascii_addr, (S8*) temp->smsc.addr);
		strcat((S8*)ascii_addr,(S8*)sep);
		break;
	case WAP_PMG_ADDR_IP:
		strcat((S8*) ascii_addr, (S8*) temp->from.addr);
		break;
	default:
		break;
	}

	add_error = srv_wap_push_add_modify_list(ascii_addr, 
		temp->from.addr_type, 
		(U16)g_srv_wap_push_cntxt->add_list_type, 
		*total_entry);
	if(add_error == SRV_WAP_PUSH_ERROR_SUCCESS)
	{
        *total_entry = *total_entry + 1;
        if(commit_func!=NULL)
		commit_func();
		srv_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_EXPLICITLY_SAVED, STR_GLOBAL_SAVED);
	}
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_ADD_TO_WHITE_LIST_ERROR, add_error);
}
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */



/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_active_profile_changed_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  profile_content_p             [IN]         
 *  sim_id						         [IN]        
 *  callback					        [IN]         
 * RETURNS
 *  0.
 *****************************************************************************/

void srv_wap_push_active_profile_changed_hdlr(
        srv_wap_prof_profile_content_struct *profile_content_p,
        srv_wap_prof_sim_id_enum sim_id,
        srv_wap_prof_response_funcptr_type callback)
        /*TODO: To ask from Vikas */
{
    switch (sim_id)
    {
    case SRV_WAP_PROF_SIMID_SIM1:
        memcpy (&(g_srv_wap_push_cntxt->sim1_profile), profile_content_p, sizeof (srv_wap_prof_profile_content_struct));
        break;
#if (MMI_MAX_SIM_NUM >= 2)
    case SRV_WAP_PROF_SIMID_SIM2:
        memcpy (&(g_srv_wap_push_cntxt->sim2_profile), profile_content_p, sizeof (srv_wap_prof_profile_content_struct));
        break;
#endif /* __MMI_WAP_DUAL_SIM__ */

  //#if (defined(GEMINI_PLUS) && (GEMINI_PLUS >= 3))
  #if (MMI_MAX_SIM_NUM >= 3)
	case SRV_WAP_PROF_SIMID_SIM3:
		memcpy (&(g_srv_wap_push_cntxt->sim3_profile), profile_content_p, sizeof (srv_wap_prof_profile_content_struct));
		 break;
  #endif
  //#if (defined(GEMINI_PLUS) && (GEMINI_PLUS >= 4))
  #if (MMI_MAX_SIM_NUM >= 4)
	case SRV_WAP_PROF_SIMID_SIM4:
		memcpy (&(g_srv_wap_push_cntxt->sim4_profile), profile_content_p, sizeof (srv_wap_prof_profile_content_struct));
		break;
  #endif

    }
    /* Need not to free profile data as browser use same data */
    //OslMfree(profile_content_p);
}

void srv_wap_push_init_profile_content (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_prof_profile_content_struct *profile_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    profile_info = srv_wap_prof_get_profile_content( 
        SRV_WAP_PROF_SIMID_SIM1, 
        SRV_WAP_PROF_APPID_BRW, 
        (U8) -1, 
        SRV_WAP_PROF_DTCNT_PRIMARY, 
        NULL);
    memcpy (&(g_srv_wap_push_cntxt->sim1_profile), profile_info, sizeof (srv_wap_prof_profile_content_struct));
    OslMfree(profile_info);
    profile_info = NULL;
#if (MMI_MAX_SIM_NUM >= 2)
    profile_info = srv_wap_prof_get_profile_content( 
        SRV_WAP_PROF_SIMID_SIM2, 
        SRV_WAP_PROF_APPID_BRW, 
        (U8) -1, 
        SRV_WAP_PROF_DTCNT_PRIMARY, 
        NULL);
    memcpy (&(g_srv_wap_push_cntxt->sim2_profile), profile_info, sizeof (srv_wap_prof_profile_content_struct));
    OslMfree(profile_info);
    profile_info = NULL;
#endif /* __MMI_WAP_DUAL_SIM__ */
 //#if (defined(GEMINI_PLUS) && (GEMINI_PLUS >= 3))
 #if (MMI_MAX_SIM_NUM >= 3)
      profile_info = srv_wap_prof_get_profile_content( 
        SRV_WAP_PROF_SIMID_SIM3, 
        SRV_WAP_PROF_APPID_BRW, 
        (U8) -1, 
        SRV_WAP_PROF_DTCNT_PRIMARY, 
        NULL);
    memcpy (&(g_srv_wap_push_cntxt->sim3_profile), profile_info, sizeof (srv_wap_prof_profile_content_struct));
    OslMfree(profile_info);
    profile_info = NULL;
#endif
//#if (defined(GEMINI_PLUS) && (GEMINI_PLUS >= 4))
#if (MMI_MAX_SIM_NUM >= 4)
	profile_info = srv_wap_prof_get_profile_content( 
        SRV_WAP_PROF_SIMID_SIM4, 
        SRV_WAP_PROF_APPID_BRW, 
        (U8) -1, 
        SRV_WAP_PROF_DTCNT_PRIMARY, 
        NULL);
     memcpy (&(g_srv_wap_push_cntxt->sim4_profile), profile_info, sizeof (srv_wap_prof_profile_content_struct));
     OslMfree(profile_info);
     profile_info = NULL;

 #endif

}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_inbox_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_inbox_init(void)
    /*TODO: change name, Make it to service side */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_inbox_init_event_struct event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_push_adm_id = kal_adm_create((void*)g_push_mem_pool, (kal_uint32) SRV_WAP_PUSH_MAX_MEM_SIZE, NULL, (kal_bool) KAL_FALSE);
    g_srv_wap_push_cntxt = (srv_wap_push_cntxt_struct*) srv_wap_push_malloc(sizeof(srv_wap_push_cntxt_struct));
    if (g_srv_wap_push_cntxt == NULL)
    {
        ASSERT(0);
    }
    
    memset (g_srv_wap_push_cntxt, 0, sizeof(srv_wap_push_cntxt_struct));

    MMI_FRM_INIT_EVENT(&event, EVT_ID_SRV_PUSH_INBOX_INIT);
    mmi_frm_cb_emit_event((mmi_event_struct*)&event);
}

#ifdef __MMI_PUSH_IN_UM__
//#if(defined(__GEMINI__)) || (defined(GEMINI_PLUS) && (GEMINI_PLUS >= 2))
#if (MMI_MAX_SIM_NUM >= 2)
/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_map_sim_id_to_um_sim_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
srv_um_sim_enum srv_wap_push_map_sim_id_to_um_sim_id (U16 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(sim_id)
    {
    case WAP_PMG_SIM1:
        return SRV_UM_SIM_GSM_SIM1;
       
    case WAP_PMG_SIM2:
        return SRV_UM_SIM_GSM_SIM2;
       
	
//#if (defined(GEMINI_PLUS) && (GEMINI_PLUS >= 3))
#if (MMI_MAX_SIM_NUM >= 3)
	case WAP_PMG_SIM3:
		 return SRV_UM_SIM_GSM_SIM3;
		 break;
#endif
//#if (defined(GEMINI_PLUS) && (GEMINI_PLUS >= 4))
#if (MMI_MAX_SIM_NUM >= 4)
	 case WAP_PMG_SIM4:
		 return SRV_UM_SIM_GSM_SIM4;
		
#endif
    default:
        ASSERT(0);
		return SRV_UM_SIM_GSM_SIM1;
    }
}
//#endif /* __MMI_DUAL_SIM_MASTER__ */
#endif  /* defined(__GEMINI__)) || (defined(GEMINI_PLUS) && (GEMINI_PLUS >= 2) */


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_send_um_new_msg_ind
 * DESCRIPTION
 *  Notify UM about new service message indication.
 * PARAMETERS
 *  msg_id         [IN]
 *  timestamp      [IN]
 *  sim_id         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_send_um_new_msg_ind (U32 msg_id, U32 timestamp, U16 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_new_msg_ind_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_data = (srv_um_new_msg_ind_struct*) OslConstructDataPtr(sizeof(srv_um_new_msg_ind_struct));

	local_data->msg_type = SRV_UM_MSG_WAP_PUSH;
	local_data->msg_id = msg_id;
	local_data->timestamp = timestamp;
    local_data->msg_box_type = SRV_UM_MSG_BOX_INBOX;
    local_data->tone_id = 0;
#if (MMI_MAX_SIM_NUM >= 2)
    local_data->sim_id = srv_wap_push_map_sim_id_to_um_sim_id(sim_id);
#endif /* __MMI_WAP_DUAL_SIM__ */

    srv_wap_push_send_msg_to_mmi (MSG_ID_MMI_UM_NEW_MSG_IND, (void*)local_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_send_um_refresh_ind
 * DESCRIPTION
 *  Refresh UM indication.
 * PARAMETERS
 * msg_id, refresh_type
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_send_um_refresh_ind (kal_int32 msg_id, kal_uint16 refresh_type,pmg_addr_struct *address)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_refresh_ind_struct *local_data;
    pmg_addr_struct *addr ;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_data = (srv_um_refresh_ind_struct*) OslConstructDataPtr(sizeof(srv_um_refresh_ind_struct));
    local_data->msg_type = SRV_UM_MSG_WAP_PUSH;
	local_data->refresh_type =(srv_um_refresh_enum) refresh_type;
	local_data->msg_id =(kal_uint32) msg_id;
    local_data->msg_box_type = SRV_UM_MSG_BOX_INBOX;
	if(refresh_type == SRV_UM_REFRESH_NEW_INCOMING_MSG)
		{
		addr = (pmg_addr_struct*)address;
		memset(local_data->address,0,sizeof(local_data->address));
		mmi_asc_n_to_ucs2((S8*)local_data->address,(S8*)addr->addr,SRV_UM_MAX_ADDR_LEN);
		local_data->addr_number = 1;
		local_data->addr_type = (srv_um_addr_enum)addr->addr_type;
		}
    srv_wap_push_send_msg_to_mmi (MSG_ID_MMI_UM_REFRESH_IND, (void*)local_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_send_um_delete_all_ind
 * DESCRIPTION
 *  Delete All indication to UM module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_send_um_delete_all_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_delete_all_ind_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_data = (srv_um_delete_all_ind_struct*) OslConstructDataPtr(sizeof(srv_um_delete_all_ind_struct));

    local_data->msg_type = SRV_UM_MSG_WAP_PUSH;
    local_data->msg_box_type = SRV_UM_MSG_BOX_INBOX;
    srv_wap_push_send_msg_to_mmi (MSG_ID_MMI_UM_DELETE_ALL_IND, (void*)local_data);
}
#endif /* __MMI_PUSH_IN_UM__ */

/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_copy_data_to_selected_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  new_msg        [IN]
 *  url            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_push_copy_data_to_selected_message (pmg_detailed_msg_struct *new_msg, S8 *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset (&(g_srv_wap_push_cntxt->selected_message), 0, sizeof (srv_wap_push_selected_msg_struct));

    /* Copying data into the selected message buffer */
    g_srv_wap_push_cntxt->selected_message.msg_type = new_msg->msg_type;
    g_srv_wap_push_cntxt->selected_message.priority = new_msg->priority;
    g_srv_wap_push_cntxt->selected_message.text_type = new_msg->text_type;
    g_srv_wap_push_cntxt->selected_message.read = new_msg->read;
    g_srv_wap_push_cntxt->selected_message.has_info = new_msg->has_info;
    g_srv_wap_push_cntxt->selected_message.msg_id = new_msg->msg_id;
    g_srv_wap_push_cntxt->selected_message.expired = new_msg->expired;
    g_srv_wap_push_cntxt->selected_message.created = new_msg->created;
    g_srv_wap_push_cntxt->selected_message.sim_id = new_msg->sim_id;
    if (g_srv_wap_push_cntxt->selected_message.text_type == WAP_PMG_STRTYPE_ASCII)
    {
        strncpy ((S8*)g_srv_wap_push_cntxt->selected_message.text, (S8*)new_msg->text, WAP_PMG_MAX_MSG_TEXT_CHARS);
    }
    else if (g_srv_wap_push_cntxt->selected_message.text_type == WAP_PMG_STRTYPE_UCS2)
    {
        mmi_ucs2ncpy((S8*) g_srv_wap_push_cntxt->selected_message.text, (S8*) new_msg->text, WAP_PMG_MAX_MSG_TEXT_CHARS);
    }
    memcpy (&(g_srv_wap_push_cntxt->selected_message.from), &(new_msg->from), sizeof (pmg_addr_struct));
    memcpy (&(g_srv_wap_push_cntxt->selected_message.smsc), &(new_msg->smsc), sizeof (pmg_addr_struct));
    strncpy (g_srv_wap_push_cntxt->selected_message.url, url, WAP_PMG_MAX_MSG_HREF_CHARS);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_set_nmgr_answer_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 *  is_high     [IN]        
 * RETURNS
 *  void.
 *****************************************************************************/
void srv_wap_push_set_nmgr_answer_flag(S16 sim_id, MMI_BOOL is_high)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!is_high)
    {
		switch(sim_id)
        {
		case WAP_PMG_SIM1:
            g_srv_wap_push_cntxt->notify_nmgr = SRV_WAP_PUSH_NOTIFY_NMGR_SIM1;
			            break;
        
        case WAP_PMG_SIM2:
            g_srv_wap_push_cntxt->notify_nmgr = SRV_WAP_PUSH_NOTIFY_NMGR_SIM2;
			            break;
		case WAP_PMG_SIM3:
						g_srv_wap_push_cntxt->notify_nmgr = SRV_WAP_PUSH_NOTIFY_NMGR_SIM3;
			            break;
		case WAP_PMG_SIM4:
						g_srv_wap_push_cntxt->notify_nmgr = SRV_WAP_PUSH_NOTIFY_NMGR_SIM4;
			            break;
        }
    }
    else
    {
	
		if (
			(g_srv_wap_push_cntxt->notify_nmgr != SRV_WAP_PUSH_NOTIFY_NMGR_SIM1)
			&& (g_srv_wap_push_cntxt->notify_nmgr != SRV_WAP_PUSH_NOTIFY_NMGR_SIM2)
			&& (g_srv_wap_push_cntxt->notify_nmgr != SRV_WAP_PUSH_NOTIFY_NMGR_SIM3)
			&& (g_srv_wap_push_cntxt->notify_nmgr != SRV_WAP_PUSH_NOTIFY_NMGR_SIM4)
			)
        {
			switch(sim_id)
            {
			case WAP_PMG_SIM1:
                g_srv_wap_push_cntxt->notify_nmgr = SRV_WAP_PUSH_NOTIFY_NMGR_HIGH_SIM1;
							break;
	        
			case WAP_PMG_SIM2:
                g_srv_wap_push_cntxt->notify_nmgr = SRV_WAP_PUSH_NOTIFY_NMGR_HIGH_SIM2;
							break;
			case WAP_PMG_SIM3:
							g_srv_wap_push_cntxt->notify_nmgr = SRV_WAP_PUSH_NOTIFY_NMGR_HIGH_SIM3;
							break;
			case WAP_PMG_SIM4:
							g_srv_wap_push_cntxt->notify_nmgr = SRV_WAP_PUSH_NOTIFY_NMGR_HIGH_SIM4;
							break;
            }
        }
    }
}

#ifndef __COSMOS_MMI_PACKAGE__
/*****************************************************************************
 * FUNCTION
 *  srv_push_entry_folder_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para     [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret srv_push_entry_folder_hdlr(mmi_event_struct *para)
{
#ifdef __MMI_PUSH_IN_UM__
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_entry_folder_evt_struct *info = (mmi_um_entry_folder_evt_struct*)para;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	if((info->msg_box == SRV_UM_MSG_BOX_INBOX) && (info->is_entry == MMI_TRUE))
	{
        g_srv_wap_push_cntxt->notify_nmgr = SRV_WAP_PUSH_NOTIFY_NMGR_NOT_NOTIFY;
	}
    
#endif /* __MMI_PUSH_IN_UM__ */
    return MMI_RET_OK;
}
#endif
/*****************************************************************************
 * FUNCTION
 *  srv_push_nmgr_if_new_msg_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_push_nmgr_if_new_msg_event(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if ((g_srv_wap_push_cntxt->notify_nmgr != SRV_WAP_PUSH_NOTIFY_NMGR_NOT_NOTIFY) &&
        (g_srv_wap_push_cntxt->notify_nmgr != SRV_WAP_PUSH_NOTIFY_NMGR_HIGH_SIM1) &&
        (g_srv_wap_push_cntxt->notify_nmgr != SRV_WAP_PUSH_NOTIFY_NMGR_HIGH_SIM2) &&
		(g_srv_wap_push_cntxt->notify_nmgr != SRV_WAP_PUSH_NOTIFY_NMGR_HIGH_SIM3) &&
		(g_srv_wap_push_cntxt->notify_nmgr != SRV_WAP_PUSH_NOTIFY_NMGR_HIGH_SIM4) 
		)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

/*
U8 srv_wap_push_is_keypad_locked_state (void)
{
    return IsKeyPadLockState();
}
*/


MMI_BOOL srv_wap_push_is_service_ready()
{
    return g_srv_wap_push_cntxt->is_service_ready;
}


srv_wap_push_notify_nmgr_sim_enum srv_wap_push_get_notify_nmgr_flag()
{
    return g_srv_wap_push_cntxt->notify_nmgr;
}

void srv_wap_push_set_notify_nmgr_flag(srv_wap_push_notify_nmgr_sim_enum nmgr_flag)
{
    g_srv_wap_push_cntxt->notify_nmgr = nmgr_flag;
}



void srv_wap_push_ui_init (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_push_inbox_ctxt = (srv_wap_push_msg_inbox_struct*) srv_wap_push_malloc(sizeof(srv_wap_push_msg_inbox_struct));
    if (g_push_inbox_ctxt == NULL)
    {
        ASSERT(0);
    }
    memset (g_push_inbox_ctxt, 0, sizeof(srv_wap_push_msg_inbox_struct));
    g_push_inbox_ctxt->title_icon_id = 0;
#ifdef __COSMOS_MMI_PACKAGE__
    SetProtocolEventHandler(srv_wap_push_display_error_dlg, MSG_ID_WPS_PMG_ERROR_DLG_IND);
    SetProtocolEventHandler(srv_wap_push_process_delete_msg_rsp, MSG_ID_WPS_PMG_DELETE_MSG_CNF);
    SetProtocolEventHandler(srv_wap_push_process_delete_all_msg_rsp, MSG_ID_WPS_PMG_DELETE_ALL_CNF);
#endif /* __COSMOS_MMI_PACKAGE__ */
}

void srv_wap_push_create_ucs2_time_format_string(U32 time_value, S8 *ucs2_time_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME time = {0};
    UI_character_type temp_time_buffer[20] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __COSMOS_MMI_PACKAGE__
    mmi_dt_utc_sec_2_mytime((U32) time_value, &time, MMI_TRUE);
    #else
    mmi_dt_utc_sec_2_mytime((U32) time_value, &time, MMI_FALSE);
    #endif
    date_string(&time, temp_time_buffer, DT_IDLE_SCREEN);
    mmi_ucs2ncpy((S8*) ucs2_time_string, (S8*) temp_time_buffer, mmi_ucs2strlen((const S8*)temp_time_buffer));
    mmi_ucs2ncat((S8*) ucs2_time_string, (S8*) " ", 1);
    time_string(&time, temp_time_buffer, DT_IDLE_SCREEN);
    mmi_ucs2ncat((S8*) ucs2_time_string, (S8*) temp_time_buffer, mmi_ucs2strlen((const S8*)temp_time_buffer));
    mmi_ucs2ncat((S8*) ucs2_time_string, (S8*) "\0", 1);
}

#ifdef __MMI_WAP_PUSH_WHITE_LIST__ 
MMI_BOOL srv_wap_push_check_trustlist_full()

    {
   
      if(g_push_set_p->total_wl_entry >= NVRAM_PUSH_MAX_NUM_WHITE_LIST)
          return MMI_TRUE;
      else 
          return
                MMI_FALSE;
   

    }
 #endif

#ifdef __MMI_WAP_PUSH_BLACK_LIST__
MMI_BOOL srv_wap_push_check_blacklist_full()

    {
      
      if(g_push_set_p->total_bl_entry >= NVRAM_PUSH_MAX_NUM_BLACK_LIST)
          return MMI_TRUE;
      else 
          return
                MMI_FALSE;
    
    }
 #endif

#ifndef __MMI_PUSH_IN_UM__
void srv_wap_push_set_nmgr_unread_handler(U32 handler)
{
   g_nmgr_handle_unread=handler;
}

U32 srv_wap_push_get_nmgr_unread_handler()
{
	return  g_nmgr_handle_unread;
}
#endif
#endif /* WAP_SUPPORT */
