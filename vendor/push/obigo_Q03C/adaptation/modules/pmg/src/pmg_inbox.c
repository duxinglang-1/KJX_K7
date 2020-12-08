/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   pmg_inbox.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains functions for Push Inbox AP request handling
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "msf_cfg.h"
//#include "msf_core.h"
#include "msf_int.h"
#include "msf_mem.h"
//#include "msf_dcvt.h"
#include "msf_log.h"
//#include "msf_pipe.h"
//#include "msf_file.h"
//#include "msf_chrs.h"
//#include "msf_errc.h"

//#include "kal_release.h"
//#include "stack_common.h"
#include "stack_msgs.h"
//#include "stack_types.h"
#include "app_ltlcom.h" /* Task message communiction */
//#include "task_config.h"        /* Task creation */

#include "Conversions.h"
#include "app_datetime.h"

#include "pmg_struct.h"
#include "pmg_main.h"
#include "pmg_env.h"
#include "pmg_if.h"
#include "pmg_phs.h"
#include "pmg_msg.h"
//#include "pmg_inbox.h"
//#include "phs_msg.h"
#include "phs_dlg.h"
#include "phs_cfg.h"
#include "cbm_api.h"
//#include "MMI_include.h"
//#include "WAPPushResDef.h"
#include "custom_data_account.h"
#include "GlobalResDef.h"

//suggested add
    #include "kal_general_types.h"

#ifndef __COSMOS_MMI_PACKAGE__
    #include "mmi_rp_app_mmi_wap_push_def.h"
#endif /*__COSMOS_MMI_PACKAGE__*/

    #include "wgui_categories_util.h"
    #include "GlobalMenuItems.h"
    #include "cbm_consts.h"
    #include "kal_public_api.h"
    #include "string.h"
    #include "pmg_fs.h"
    #include "msf_def.h"
    #include "stack_config.h"
    #include "kal_trace.h"
    #include "wps_trc.h"
    #include "MMIDataType.h"

#define PMG_QUEUE_STATE_IDLE    0
#define PMG_QUEUE_STATE_WAIT    1

typedef struct pmg_msg_id_queue_elem_st
{
    struct pmg_msg_id_queue_elem_st *next;
    int id;
} pmg_msg_id_queue_elem_t;

typedef struct pmg_inbox_context_st
{
    kal_uint8 pmg_app_id;
    int pmg_new_msg_queue_state;
    pmg_msg_id_queue_elem_t *pmg_new_msg_queue_first;
    pmg_dlg_display_req_t *pmg_lst_dlg_requests;
	
#ifdef __MMI_PUSH_TURN_ON_OFF_SWITCH__
     MSF_UINT8 push_turn_on_switch;
#endif/*__MMI_PUSH_TURN_ON_OFF_SWITCH__*/

} pmg_inbox_context_t;

static pmg_inbox_context_t g_pmg_inbox_cntx_t = {0,0,NULL,NULL
#ifdef __MMI_PUSH_TURN_ON_OFF_SWITCH__
,TRUE
#endif/*__MMI_PUSH_TURN_ON_OFF_SWITCH__*/
};




kal_uint8 g_pmg_app_id = 0;

/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_init
 * DESCRIPTION
 *  initialise PMG's inbox component
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	cbm_app_info_struct info;
	kal_uint8 app_id = -1;
	kal_uint8 result = -1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_pmg_inbox_cntx_t.pmg_new_msg_queue_first = 0;
    g_pmg_inbox_cntx_t.pmg_new_msg_queue_state = PMG_QUEUE_STATE_IDLE;
    g_pmg_inbox_cntx_t.pmg_lst_dlg_requests = 0;
/* cbm_register_app_id is changed with the newer one cbm_register_app_id_with_app_info */
	#ifdef 	__COSMOS_MMI_PACKAGE__
	info.app_str_id = STR_GLOBAL_ERROR;
	#else
	info.app_str_id = STR_ID_PUSH_INBOX;
	#endif /*__COSMOS_MMI_PACKAGE__ */
	info.app_icon_id = GetRootTitleIcon(SERVICES_WAP_MENU_ID);
#ifdef WAP2
	info.app_type = DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_BRW_WAP; 
#else
	info.app_type = DTCNT_APPTYPE_BRW_WAP;
#endif /* WAP2 */
    result = cbm_register_app_id_with_app_info (&info, &app_id);
	if (result == CBM_OK)
		g_pmg_inbox_cntx_t.pmg_app_id = app_id;
	else
		ASSERT(0);

/* end */	
	g_pmg_app_id = g_pmg_inbox_cntx_t.pmg_app_id;
    pmg_init_done(PMG_INIT_INBOX);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_terminate
 * DESCRIPTION
 *  PMG inbox termination handler
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_terminate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef MTK_TMP_PATCH
    cbm_deregister_app_id(g_pmg_inbox_cntx_t.pmg_app_id);
	g_pmg_app_id = 0;
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  pmg_add_id_to_queue
 * DESCRIPTION
 *  add a new message ID to queue
 * PARAMETERS
 *  queue               [in]
 *  id                  [in]
 * RETURNS
 *  void
 *****************************************************************************/
static void pmg_add_id_to_queue(pmg_msg_id_queue_elem_t **queue, int id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_msg_id_queue_elem_t *qe;
    pmg_msg_id_queue_elem_t *tmp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    qe = pmg_mem_alloc(sizeof(pmg_msg_id_queue_elem_t));
    memset(qe, 0, sizeof(pmg_msg_id_queue_elem_t));
    qe->next = 0;
    qe->id = id;

    if (!(*queue))
    {
        *queue = qe;
        return;
    }
    tmp = *queue;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = qe;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_pop_id_from_queue
 * DESCRIPTION
 *  pop first message ID from queue
 * PARAMETERS
 *  queue               [in]
 * RETURNS
 *  message ID
 *****************************************************************************/
static int pmg_pop_id_from_queue(pmg_msg_id_queue_elem_t **queue)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_msg_id_queue_elem_t *tmp;
    int id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(*queue))
        return -1;

    tmp = *queue;
    *queue = (*queue)->next;

    id = tmp->id;
    PMG_MEM_FREE(tmp);

    return id;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_convert_msg_to_local_param_msg
 * DESCRIPTION
 *  convert PMG message to local parameter
 *  [pre] destination buffer must aleady be set to 0
 * PARAMETERS
 *  msg              [in]
 *  lp_msg           [out]
 * RETURNS
 *  void
 *****************************************************************************/
static void pmg_inbox_convert_msg_to_local_param_msg(pmg_full_msg_t *msg, pmg_detailed_msg_struct *lp_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lp_msg->msg_id = msg->msgID;
    lp_msg->msg_type = msg->msgType;
    if (msg->created)
        lp_msg->created = applib_dt_sec_utc_to_local(msg->created);
    if (msg->expired)
        lp_msg->expired = applib_dt_sec_utc_to_local(msg->expired);
    lp_msg->priority = msg->priority;
    lp_msg->read = msg->read;
    lp_msg->has_info = msg->numInfoItems;

    if (msg->text)
    {
        if (pmg_check_is_ascii_string(msg->text))
        {
            lp_msg->text_type = PMG_STRTYPE_ASCII;
            strncpy((char*)lp_msg->text, (char*)msg->text, PMG_MAX_MSG_TEXT_CHARS);
        }
        else
        {
            lp_msg->text_type = PMG_STRTYPE_UCS2;
            mmi_chset_utf8_to_ucs2_string(
                (kal_uint8*) (lp_msg->text),
                (kal_int32) (PMG_MAX_MSG_TEXT_CHARS + 2),
                (kal_uint8*) (msg->text));
        }
    }

    lp_msg->smsc.addr_type = msg->smscType;
    lp_msg->from.addr_type = msg->fromType;
    if (msg->smsc)
        strncpy((char*)lp_msg->smsc.addr, (char*)msg->smsc, PMG_MAX_ADDR_CHARS);
    if (msg->from)
        strncpy((char*)lp_msg->from.addr, (char*)msg->from, PMG_MAX_ADDR_CHARS);
    lp_msg->sim_id = msg->sim_id;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_convert_href_to_peerbuff
 * DESCRIPTION
 *  convert message's href to peer buffer
 * PARAMETERS
 *  href                [in]
 * RETURNS
 *  peer buffer
 *****************************************************************************/
static peer_buff_struct *pmg_inbox_convert_href_to_peerbuff(const char *href)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT16 pdu_len;
    peer_buff_struct *peer_buff;
    char *pdu_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(href))
        return 0;

    pdu_len = strlen(href) + 1;
    peer_buff = construct_peer_buff(pdu_len, 0, 0, TD_CTRL);
    pdu_ptr = (char*)get_pdu_ptr(peer_buff, (kal_uint16*) & pdu_len);
    memset(pdu_ptr, 0, pdu_len);
    strncpy(pdu_ptr, href, pdu_len - 1);

    return peer_buff;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_convert_msg_elem_to_lplist_elem
 * DESCRIPTION
 *  convert PMG's message list element to a list element in local parameter
 *  [pre] destination buffer must aleady be set to 0
 * PARAMETERS
 *  msg_elem             [in]
 *  lp_elem              [out]
 * RETURNS
 *  void
 *****************************************************************************/
static void pmg_inbox_convert_msg_elem_to_lplist_elem(pmg_msg_elem_t *msg_elem, pmg_msg_list_struct *lp_elem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lp_elem->msg_id = msg_elem->msgID;
    lp_elem->msg_type = msg_elem->type;
    if (msg_elem->created)
        lp_elem->created = applib_dt_sec_utc_to_local(msg_elem->created);
    if (msg_elem->expired)
        lp_elem->expired = applib_dt_sec_utc_to_local(msg_elem->expired);
    lp_elem->priority = msg_elem->priority;
    lp_elem->read = msg_elem->read;

    if (msg_elem->partialHref)
        strncpy((char*)lp_elem->href, (char*)msg_elem->partialHref, PMG_MAX_MSG_LIST_HREF_CHARS);

    if (msg_elem->partialText)
    {
        if (pmg_check_is_ascii_string(msg_elem->partialText))
        {
            lp_elem->text_type = PMG_STRTYPE_ASCII;
            strncpy((char*)lp_elem->text, (char*)msg_elem->partialText, PMG_MAX_MSG_LIST_TEXT_CHARS);
        }
        else
        {
            lp_elem->text_type = PMG_STRTYPE_UCS2;
            mmi_chset_utf8_to_ucs2_string(
                (kal_uint8*) (lp_elem->text),
                (kal_int32) (PMG_MAX_MSG_LIST_TEXT_CHARS + 2),
                (kal_uint8*) (msg_elem->partialText));
        }
    }

    lp_elem->sim_id = msg_elem->sim_id;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_convert_infoitem_to_lp_infoitem
 * DESCRIPTION
 *  convert PMG's info item to local parameter
 *  [pre] destination buffer must aleady be set to 0
 * PARAMETERS
 *  infoitem             [in]
 *  lp_infoitem          [out]
 * RETURNS
 *  void
 *****************************************************************************/
static void
pmg_inbox_convert_infoitem_to_lp_infoitem(pmg_msg_infoitem_t *infoitem, pmg_msg_infoitem_struct *lp_infoitem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (infoitem->infoClass)
    {
        if (pmg_check_is_ascii_string(infoitem->infoClass))
        {
            lp_infoitem->class_type = PMG_STRTYPE_ASCII;
            strncpy((char*)lp_infoitem->info_class, (char*)infoitem->infoClass, PMG_MAX_INFOITEM_CLASS_CHARS);
        }
        else
        {
            lp_infoitem->class_type = PMG_STRTYPE_UCS2;
            mmi_chset_utf8_to_ucs2_string(
                (kal_uint8*) (lp_infoitem->info_class),
                (kal_int32) (PMG_MAX_INFOITEM_CLASS_CHARS + 2),
                (kal_uint8*) (infoitem->infoClass));
        }
    }

    if (infoitem->infoText)
    {
        if (pmg_check_is_ascii_string(infoitem->infoText))
        {
            lp_infoitem->text_type = PMG_STRTYPE_ASCII;
            strncpy((char*)lp_infoitem->info_text, (char*)infoitem->infoText, PMG_MAX_INFOITEM_TEXT_CHARS);
        }
        else
        {
            lp_infoitem->text_type = PMG_STRTYPE_UCS2;
            mmi_chset_utf8_to_ucs2_string(
                (kal_uint8*) (lp_infoitem->info_text),
                (kal_int32) (PMG_MAX_INFOITEM_TEXT_CHARS + 2),
                (kal_uint8*) (infoitem->infoText));
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_send_wps_pmg_ready_ind
 * DESCRIPTION
 *  send MSG_ID_WPS_PMG_READY_IND to push inbox app
 * PARAMETERS
 *  param            [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_send_wps_pmg_ready_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pmg_send_primitive(MOD_MMI, MSG_ID_WPS_PMG_READY_IND, (void*)0, (void*)0);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_send_wps_pmg_config_cnf
 * DESCRIPTION
 *  send MSG_ID_WPS_PMG_CONFIG_CNF to push inbox app
 * PARAMETERS
 *  param            [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_send_wps_pmg_config_cnf(wps_pmg_config_cnf_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pmg_send_primitive(MOD_MMI, MSG_ID_WPS_PMG_CONFIG_CNF, (void*)param, (void*)0);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_send_new_msg
 * DESCRIPTION
 *  send MSG_ID_WPS_PMG_NEW_MSG_IND to push inbox app
 * PARAMETERS
 *  msg          [in]
 * RETURNS
 *  void
 *****************************************************************************/
static void pmg_send_new_msg(pmg_full_msg_t *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_pmg_new_msg_ind_struct *local_param;
    peer_buff_struct *peer_buff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param =
        (wps_pmg_new_msg_ind_struct*) construct_local_para((kal_uint16) sizeof(wps_pmg_new_msg_ind_struct), TD_RESET);

    pmg_inbox_convert_msg_to_local_param_msg(msg, &(local_param->msg_data));
    peer_buff = pmg_inbox_convert_href_to_peerbuff(msg->href);

    g_pmg_inbox_cntx_t.pmg_new_msg_queue_state = PMG_QUEUE_STATE_WAIT;
	MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_INBOX_NEW_MSG_SIM_ID,
                     "PMG: NEW MSG SIM ID: %d", (int) msg->sim_id));
    pmg_send_primitive(MOD_MMI, MSG_ID_WPS_PMG_NEW_MSG_IND, (void*)local_param, (void*)peer_buff);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_send_wps_pmg_new_msg_ind
 * DESCRIPTION
 *  register the new message to send to push inbox app
 * PARAMETERS
 *  pmsg             [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_send_wps_pmg_new_msg_ind(void *pmsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pmg_inbox_cntx_t.pmg_new_msg_queue_state == PMG_QUEUE_STATE_IDLE)
        pmg_send_new_msg((pmg_full_msg_t*) pmsg);
    else
        pmg_add_id_to_queue(&g_pmg_inbox_cntx_t.pmg_new_msg_queue_first, ((pmg_full_msg_t*) pmsg)->msgID);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_send_wps_pmg_delete_ind
 * DESCRIPTION
 *  send MSG_ID_WPS_PMG_DELETE_IND to push inbox app
 * PARAMETERS
 *  msgID               [in]
 *  msgType             [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_send_wps_pmg_delete_ind(int msgID, MSF_UINT8 msgType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_pmg_delete_ind_struct *param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param =
        (wps_pmg_delete_ind_struct*) construct_local_para((kal_uint16) sizeof(wps_pmg_delete_ind_struct), TD_RESET);
	
#if(MMI_MAX_SIM_NUM >= 2)
	
	   param->msg_count = pmg_msg_count_messages(WAP_PMG_PARAM_NOT_SPECIFIED, WAP_PMG_PARAM_NO, PMG_PARAM_NOT_SPECIFIED, PMG_PARAM_NOT_SPECIFIED, WAP_PMG_SIM1);
	   param->msg_count += pmg_msg_count_messages(WAP_PMG_PARAM_NOT_SPECIFIED, WAP_PMG_PARAM_NO, PMG_PARAM_NOT_SPECIFIED, PMG_PARAM_NOT_SPECIFIED, WAP_PMG_SIM2);
	
	#if (MMI_MAX_SIM_NUM >= 3)
	   param->msg_count += pmg_msg_count_messages(WAP_PMG_PARAM_NOT_SPECIFIED, WAP_PMG_PARAM_NO, PMG_PARAM_NOT_SPECIFIED, PMG_PARAM_NOT_SPECIFIED, WAP_PMG_SIM3);
	#endif
	#if (MMI_MAX_SIM_NUM >= 4)
	  param->msg_count +=  pmg_msg_count_messages(WAP_PMG_PARAM_NOT_SPECIFIED, WAP_PMG_PARAM_NO, PMG_PARAM_NOT_SPECIFIED, PMG_PARAM_NOT_SPECIFIED, WAP_PMG_SIM4);
	#endif
#else
		param->msg_count = pmg_msg_count_messages(WAP_PMG_PARAM_NOT_SPECIFIED, WAP_PMG_PARAM_NO, PMG_PARAM_NOT_SPECIFIED, PMG_PARAM_NOT_SPECIFIED, WAP_PMG_SIM_DEFAULT);
#endif/*(MMI_MAX_SIM_NUM >= 2)*/

    param->size = 1;
    param->msgs[0].msg_id = (kal_int32) msgID;
    param->msgs[0].msg_type = (kal_uint8) msgType;

    pmg_send_primitive(MOD_MMI, MSG_ID_WPS_PMG_DELETE_IND, (void*)param, (void*)0);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_send_wps_pmg_delete_ind_ext
 * DESCRIPTION
 *  send MSG_ID_WPS_PMG_DELETE_IND to push inbox app
 * PARAMETERS
 *  msgID               [in]
 *  msgType             [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_send_wps_pmg_delete_ind_ext(kal_uint32 size, pmg_msg_id_struct msgs[PMG_MAX_DELETED_MSG_LIST_SIZE])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_pmg_delete_ind_struct *param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param =
        (wps_pmg_delete_ind_struct*) construct_local_para((kal_uint16) sizeof(wps_pmg_delete_ind_struct), TD_RESET);

    param->size = size;
    memcpy(param->msgs, msgs, PMG_MAX_DELETED_MSG_LIST_SIZE * sizeof(pmg_msg_id_struct));

    pmg_send_primitive(MOD_MMI, MSG_ID_WPS_PMG_DELETE_IND, (void*)param, (void*)0);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_send_wps_pmg_replace_ind
 * DESCRIPTION
 *  send MSG_ID_WPS_PMG_REPLACE_IND to push inbox app
 * PARAMETERS
 *  pmsg             [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_send_wps_pmg_replace_ind(void *pmsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_pmg_replace_ind_struct *param;
    peer_buff_struct *peer_buff;
    pmg_full_msg_t *msg = (pmg_full_msg_t*) pmsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param =
        (wps_pmg_replace_ind_struct*) construct_local_para((kal_uint16) sizeof(wps_pmg_replace_ind_struct), TD_RESET);
    memset(&(param->msg_data), 0, sizeof(pmg_detailed_msg_struct));

    param->msg_id = (kal_int32) (msg->msgID);
    param->msg_type = (kal_uint8) (msg->msgType);
    pmg_inbox_convert_msg_to_local_param_msg(msg, &(param->msg_data));

    peer_buff = pmg_inbox_convert_href_to_peerbuff(msg->href);
	MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_INBOX_REPLACED_MSG_SIM_ID,
                     "PMG: REPLACED MSG SIM ID: %d", (int) msg->sim_id));
    pmg_send_primitive(MOD_MMI, MSG_ID_WPS_PMG_REPLACE_IND, (void*)param, (void*)peer_buff);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_send_wps_pmg_msg_count_cnf
 * DESCRIPTION
 *  send MSG_ID_WPS_PMG_MSG_COUNT_CNF to push inbox app
 * PARAMETERS
 *  param            [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_send_wps_pmg_msg_count_cnf(wps_pmg_msg_count_cnf_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pmg_send_primitive(MOD_MMI, MSG_ID_WPS_PMG_MSG_COUNT_CNF, (void*)param, (void*)0);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_send_wps_pmg_msg_list_cnf
 * DESCRIPTION
 *  send MSG_ID_WPS_PMG_MSG_LIST_CNF to push inbox app
 * PARAMETERS
 *  param            [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_send_wps_pmg_msg_list_cnf(wps_pmg_msg_list_cnf_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pmg_send_primitive(MOD_MMI, MSG_ID_WPS_PMG_MSG_LIST_CNF, (void*)param, (void*)0);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_send_wps_pmg_get_msg_cnf
 * DESCRIPTION
 *  send MSG_ID_WPS_PMG_GET_MSG_CNF to push inbox app
 * PARAMETERS
 *  param                [in]
 *  peer_buff            
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_send_wps_pmg_get_msg_cnf(wps_pmg_get_msg_cnf_struct *param, peer_buff_struct *peer_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pmg_send_primitive(MOD_MMI, MSG_ID_WPS_PMG_GET_MSG_CNF, (void*)param, (void*)peer_buff);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_send_wps_pmg_get_msg_infotag_cnf
 * DESCRIPTION
 *  send MSG_ID_WPS_PMG_GET_MSG_INFOTAG_CNF to push inbox app
 * PARAMETERS
 *  param            [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_send_wps_pmg_get_msg_infotag_cnf(wps_pmg_get_msg_infotag_cnf_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pmg_send_primitive(MOD_MMI, MSG_ID_WPS_PMG_GET_MSG_INFOTAG_CNF, (void*)param, (void*)0);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_send_wps_pmg_delete_msg_cnf
 * DESCRIPTION
 *  send MSG_ID_WPS_PMG_DELETE_MSG_CNF to push inbox app
 * PARAMETERS
 *  param            [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_send_wps_pmg_delete_msg_cnf(wps_pmg_delete_msg_cnf_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pmg_send_primitive(MOD_MMI, MSG_ID_WPS_PMG_DELETE_MSG_CNF, (void*)param, (void*)0);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_send_wps_pmg_delete_all_cnf
 * DESCRIPTION
 *  send MSG_ID_WPS_PMG_DELETE_ALL_CNF to push inbox app
 * PARAMETERS
 *  param            [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_send_wps_pmg_delete_all_cnf(wps_pmg_delete_all_cnf_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pmg_send_primitive(MOD_MMI, MSG_ID_WPS_PMG_DELETE_ALL_CNF, (void*)param, (void*)0);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_send_wps_pmg_update_msg_cnf
 * DESCRIPTION
 *  send MSG_ID_WPS_PMG_UPDATE_MSG_CNF to push inbox app
 * PARAMETERS
 *  param            [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_send_wps_pmg_update_msg_cnf(wps_pmg_update_msg_cnf_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pmg_send_primitive(MOD_MMI, MSG_ID_WPS_PMG_UPDATE_MSG_CNF, (void*)param, (void*)0);
}
#ifdef PHS_CFG_PUSH_SLIM_SUPPORT  
/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_send_wps_pmg_update_all_msg_cnf
 * DESCRIPTION
 *  send MSG_ID_WPS_PMG_UPDATE_ALL_MSG_CNF to push inbox app
 * PARAMETERS
 *  param            [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_send_wps_pmg_update_all_msg_cnf(wps_pmg_update_all_msg_cnf_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pmg_send_primitive(MOD_MMI, MSG_ID_WPS_PMG_UPDATE_ALL_MSG_CNF, (void*)param, (void*)0);
}
#endif
#ifdef PHS_CFG_PUSH_WHITELIST_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_send_wps_pmg_trust_addr_list_cnf
 * DESCRIPTION
 *  send MSG_ID_WPS_PMG_TRUST_ADDR_LIST_CNF to push inbox app
 * PARAMETERS
 *  param            [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_send_wps_pmg_trust_addr_list_cnf(wps_pmg_trust_addr_list_cnf_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pmg_send_primitive(MOD_MMI, MSG_ID_WPS_PMG_TRUST_ADDR_LIST_CNF, (void*)param, (void*)0);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_send_wps_pmg_black_addr_list_cnf
 * DESCRIPTION
 *  send MSG_ID_WPS_PMG_BLACK_ADDR_LIST_CNF to push inbox app
 * PARAMETERS
 *  param            [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_send_wps_pmg_black_addr_list_cnf(wps_pmg_black_addr_list_cnf_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pmg_send_primitive(MOD_MMI, MSG_ID_WPS_PMG_BLACK_ADDR_LIST_CNF, (void*)param, (void*)0);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_handle_config_req
 * DESCRIPTION
 *  handle MSG_ID_WPS_PMG_CONFIG_REQ from push inbox app
 * PARAMETERS
 *  p            [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_handle_config_req(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_inbox_config_req_t *data = (pmg_inbox_config_req_t*) p;
    wps_pmg_config_cnf_struct *local_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pmg_phs_config(data->wapPushEnabled, 
      data->slEnabled, 
      data->trustEnabled, 
      data->blackListEnabled,
      data->maxTrustAddrNo,
      data->maxBlackAddrNo);

    local_param =
        (wps_pmg_config_cnf_struct*) construct_local_para((kal_uint16) sizeof(wps_pmg_config_cnf_struct), TD_RESET);
    local_param->status = PMG_STATUS_OK;

    pmg_inbox_send_wps_pmg_config_cnf(local_param);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_handle_msg_count_req
 * DESCRIPTION
 *  handle MSG_ID_WPS_PMG_MSG_COUNT_REQ from push inbox app
 * PARAMETERS
 *  p            [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_handle_msg_count_req(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_inbox_msg_count_req_t *data = (pmg_inbox_msg_count_req_t*) p;
    wps_pmg_msg_count_cnf_struct *local_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param =
        (wps_pmg_msg_count_cnf_struct*) construct_local_para(
                                            (kal_uint16) sizeof(wps_pmg_msg_count_cnf_struct),
                                            TD_RESET);
    local_param->trans_id = data->transID;
#if(MMI_MAX_SIM_NUM >= 2)

   local_param->msg_count_sim1 = pmg_msg_count_messages(data->msgType, data->isRead, data->isExpired, data->hasInfo, WAP_PMG_SIM1);
   local_param->msg_count_sim2 = pmg_msg_count_messages(data->msgType, data->isRead, data->isExpired, data->hasInfo, WAP_PMG_SIM2);

	#if (MMI_MAX_SIM_NUM >= 3)
   local_param->msg_count_sim3 = pmg_msg_count_messages(data->msgType, data->isRead, data->isExpired, data->hasInfo, WAP_PMG_SIM3);
	#endif
	#if (MMI_MAX_SIM_NUM >= 4)
   local_param->msg_count_sim4 = pmg_msg_count_messages(data->msgType, data->isRead, data->isExpired, data->hasInfo, WAP_PMG_SIM4);
	#endif
#else
    local_param->msg_count_sim1 = pmg_msg_count_messages(data->msgType, data->isRead, data->isExpired, data->hasInfo, WAP_PMG_SIM_DEFAULT);
#endif/*(MMI_MAX_SIM_NUM >= 2)*/


    pmg_inbox_send_wps_pmg_msg_count_cnf(local_param);
}

/* SKS */
/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_handle_msg_read_status_req
 * DESCRIPTION
 *  handle MSG_ID_WPS_PMG_MSG_READ_STATUS_REQ from push inbox app
 * PARAMETERS
 *  p            [in]
 * RETURNS
 *  void
 *****************************************************************************/

void pmg_inbox_handle_msg_read_status_req(void * p)
{
pmg_inbox_msg_read_status_req_t *data = (pmg_inbox_msg_read_status_req_t*) p;

pmg_msg_elem_t *elem;
kal_bool readstatus;

 if ((elem = pmg_msg_find_elem_by_id(data->msg_id)) == 0)
 	{    
	 //error message
 	}
else
	{
	readstatus = elem->read? KAL_TRUE : KAL_FALSE;
	data->status_func(readstatus);
	}
}

/* SKS */

/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_handle_msg_list_req
 * DESCRIPTION
 *  handle MSG_ID_WPS_PMG_MSG_LIST_REQ from push inbox app
 * PARAMETERS
 *  p            [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_handle_msg_list_req(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_inbox_msg_list_req_t *data = (pmg_inbox_msg_list_req_t*) p;
    wps_pmg_msg_list_cnf_struct *local_param;
    pmg_msg_list_t *msg_list;
    pmg_msg_elem_t *msg_elem;
    int index;
	MSF_UINT32 sim_id = WAP_PMG_SIM_ALL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_list = pmg_msg_retrieve_list(
                data->msgType,
                data->isRead,
                data->isExpired,
                data->hasInfo,
                data->startFrom,
                data->size,
                PMG_MAX_MSG_LIST_SIZE,
				sim_id);
	if (msg_list != NULL)
	{
    local_param =
        (wps_pmg_msg_list_cnf_struct*) construct_local_para(
                                        (kal_uint16) sizeof(wps_pmg_msg_list_cnf_struct),
                                        TD_RESET);
    local_param->trans_id = data->transID;
    local_param->size = msg_list->size;
    local_param->size_remain = msg_list->remain_size;
    if (msg_list->remain_size)
        local_param->more = msg_list->size + data->startFrom;
    else
        local_param->more = 0;

    memset(local_param->msg_list_data, 0, sizeof(pmg_msg_list_struct) * PMG_MAX_MSG_LIST_SIZE);
    msg_elem = msg_list->head;
    index = 0;
    while (msg_elem)
    {
        ASSERT(index < PMG_MAX_MSG_LIST_SIZE);
        pmg_inbox_convert_msg_elem_to_lplist_elem(msg_elem, local_param->msg_list_data + index);
        msg_elem = msg_elem->next;
        index++;
    }

    pmg_msg_release_list(msg_list);
    pmg_inbox_send_wps_pmg_msg_list_cnf(local_param);
}
	else
	{
		/* msg_list is empty. put a log */
	}
}


/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_handle_get_msg_req
 * DESCRIPTION
 *  handle MSG_ID_WPS_PMG_GET_MSG_REQ from push inbox app
 * PARAMETERS
 *  p            [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_handle_get_msg_req(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_inbox_get_msg_req_t *data = (pmg_inbox_get_msg_req_t*) p;
    wps_pmg_get_msg_cnf_struct *local_param;
    peer_buff_struct *peer_buff = 0;
    pmg_full_msg_t *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = pmg_msg_retrieve_full_message(data->msgID);

    local_param =
        (wps_pmg_get_msg_cnf_struct*) construct_local_para((kal_uint16) sizeof(wps_pmg_get_msg_cnf_struct), TD_RESET);
    local_param->trans_id = data->transID;
    local_param->status = (msg ? PMG_STATUS_OK : PMG_STATUS_NOT_FOUND);

    memset(&(local_param->msg_data), 0, sizeof(pmg_detailed_msg_struct));
    if (msg)
    {
        pmg_inbox_convert_msg_to_local_param_msg(msg, &(local_param->msg_data));
        peer_buff = pmg_inbox_convert_href_to_peerbuff(msg->href);
	MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_INBOX_GET_MSG_SIM_ID,
                     "PMG: REQUESTED MSG SIM ID: %d", (int) msg->sim_id));
        pmg_lib_release_msg(msg);
    }
	
    pmg_inbox_send_wps_pmg_get_msg_cnf(local_param, peer_buff);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_handle_get_msg_infotag_req
 * DESCRIPTION
 *  handle MSG_ID_WPS_PMG_GET_MSG_INFOTAG_REQ from push inbox app
 * PARAMETERS
 *  p            [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_handle_get_msg_infotag_req(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_inbox_get_msg_infotag_req_t *data = (pmg_inbox_get_msg_infotag_req_t*) p;
    wps_pmg_get_msg_infotag_cnf_struct *local_param;
    pmg_msg_infoitem_list_t *infoitem_list;
    pmg_msg_infoitem_t *infoitem_elem;
    int index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    infoitem_list = pmg_msg_retrieve_msg_infoitems(data->msgID, data->startFrom, PMG_MAX_MSG_INFOITEM_LIST_SIZE);

    local_param =
        (wps_pmg_get_msg_infotag_cnf_struct*) construct_local_para(
                                                (kal_uint16) sizeof(wps_pmg_get_msg_infotag_cnf_struct),
                                                TD_RESET);
    local_param->trans_id = data->transID;
    if (!infoitem_list)
    {
        local_param->size = 0;
        local_param->more = 0;
        local_param->status = PMG_STATUS_NOT_FOUND;
    }
    else
    {
        local_param->size = infoitem_list->size;
        local_param->more = data->startFrom + infoitem_list->size;
        local_param->status = PMG_STATUS_OK;

        index = 0;
        infoitem_elem = infoitem_list->head;
        while (infoitem_elem)
        {
            ASSERT(index < PMG_MAX_MSG_INFOITEM_LIST_SIZE);
            pmg_inbox_convert_infoitem_to_lp_infoitem(infoitem_elem, local_param->info_item_list_data + index);
            infoitem_elem = infoitem_elem->next;
        }
        pmg_msg_release_infoitem_list(infoitem_list);
    }

    pmg_inbox_send_wps_pmg_get_msg_infotag_cnf(local_param);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_handle_delete_msg_req
 * DESCRIPTION
 *  handle MSG_ID_WPS_PMG_DELETE_MSG_REQ from push inbox app
 * PARAMETERS
 *  p            [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_handle_delete_msg_req(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_inbox_delete_msg_req_t *data = (pmg_inbox_delete_msg_req_t*) p;
    wps_pmg_delete_msg_cnf_struct *local_param;
    int result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = pmg_msg_delete_message(data->msgID);

    local_param =
        (wps_pmg_delete_msg_cnf_struct*) construct_local_para(
                                            (kal_uint16) sizeof(wps_pmg_delete_msg_cnf_struct),
                                            TD_RESET);
    local_param->trans_id = data->transID;
    local_param->status = (result ? PMG_STATUS_OK : PMG_STATUS_NOT_FOUND);
    local_param->msg_id = data->msgID;
    pmg_inbox_send_wps_pmg_delete_msg_cnf(local_param);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_handle_delete_all_req
 * DESCRIPTION
 *  handle MSG_ID_WPS_PMG_DELETE_ALL_REQ from push inbox app
 * PARAMETERS
 *  p            [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_handle_delete_all_req(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_inbox_delete_all_req_t *data = (pmg_inbox_delete_all_req_t*) p;
    wps_pmg_delete_all_cnf_struct *local_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pmg_msg_delete_all_messages(data->msgType);

    local_param =
        (wps_pmg_delete_all_cnf_struct*) construct_local_para(
                                            (kal_uint16) sizeof(wps_pmg_delete_all_cnf_struct),
                                            TD_RESET);
    local_param->trans_id = data->transID;
    local_param->status = PMG_STATUS_OK;

    pmg_inbox_send_wps_pmg_delete_all_cnf(local_param);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_handle_update_msg_req
 * DESCRIPTION
 *  handle MSG_ID_WPS_PMG_UPDATE_MSG_REQ from push inbox app
 * PARAMETERS
 *  p            [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_handle_update_msg_req(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_inbox_update_msg_req_t *data = (pmg_inbox_update_msg_req_t*) p;
    wps_pmg_update_msg_cnf_struct *local_param;
    int result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = pmg_msg_update_message(data->msgID, data->read);

    local_param =
        (wps_pmg_update_msg_cnf_struct*) construct_local_para(
                                            (kal_uint16) sizeof(wps_pmg_update_msg_cnf_struct),
                                            TD_RESET);
    local_param->trans_id = data->transID;
	local_param->msg_id = data->msgID;
    local_param->status = (result ? PMG_STATUS_OK : PMG_STATUS_NOT_FOUND);

    pmg_inbox_send_wps_pmg_update_msg_cnf(local_param);
}

#ifdef PHS_CFG_PUSH_SLIM_SUPPORT  
/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_handle_update_all_msg_req
 * DESCRIPTION
 *  handle MSG_ID_WPS_PMG_UPDATE_ALL_MSG_REQ from push inbox app
 * PARAMETERS
 *  p            [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_handle_update_all_msg_req(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_inbox_update_all_msg_req_t *data = (pmg_inbox_update_all_msg_req_t*) p;
	
    wps_pmg_update_all_msg_cnf_struct *local_param;
     wps_pmg_status_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    result = pmg_msg_update_all_message(data->read);

	local_param =
			(wps_pmg_update_all_msg_cnf_struct*) construct_local_para(
												(kal_uint16) sizeof(wps_pmg_update_all_msg_cnf_struct),
												TD_RESET);
	local_param->status_result = result;
	pmg_inbox_send_wps_pmg_update_all_msg_cnf(local_param);

}
#endif
/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_handle_new_msg_rsp
 * DESCRIPTION
 *  handle MSG_ID_WPS_PMG_NEW_MSG_RSP from push inbox app
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_handle_new_msg_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_full_msg_t *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_pmg_inbox_cntx_t.pmg_new_msg_queue_state == PMG_QUEUE_STATE_WAIT);
    g_pmg_inbox_cntx_t.pmg_new_msg_queue_state = PMG_QUEUE_STATE_IDLE;

    if (g_pmg_inbox_cntx_t.pmg_new_msg_queue_first)
    {
        msg = pmg_msg_retrieve_full_message(pmg_pop_id_from_queue(&g_pmg_inbox_cntx_t.pmg_new_msg_queue_first));
        ASSERT(msg);
        pmg_send_new_msg(msg);
        pmg_lib_release_msg(msg);
    }
}

#ifdef PHS_CFG_PUSH_WHITELIST_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_handle_auth_addr_list_req
 * DESCRIPTION
 *  handle MSG_ID_WPS_PMG_TRUST_ADDR_LIST_REQ from push inbox app
 * PARAMETERS
 *  p            [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_handle_auth_addr_list_req(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_inbox_auth_addr_list_req_t *data = (pmg_inbox_auth_addr_list_req_t*) p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pmg_phs_config_auth_addrs(data->type, (pmg_addr_t*) (data->addrs), data->segment, data->size, data->total_segment);

    if (data->type == PMG_AUTH_LIST_TYPE_WHITE)
    {
        wps_pmg_trust_addr_list_cnf_struct *local_param =
            (wps_pmg_trust_addr_list_cnf_struct*) construct_local_para(
                                                    (kal_uint16) sizeof(wps_pmg_trust_addr_list_cnf_struct),
                                                    TD_RESET);
        local_param->trans_id = data->transID;
    
        pmg_inbox_send_wps_pmg_trust_addr_list_cnf(local_param);
    }
    else if (data->type == PMG_AUTH_LIST_TYPE_BLACK)
    {
        wps_pmg_black_addr_list_cnf_struct *local_param =
            (wps_pmg_black_addr_list_cnf_struct*) construct_local_para(
                                                    (kal_uint16) sizeof(wps_pmg_black_addr_list_cnf_struct),
                                                    TD_RESET);
        local_param->trans_id = data->transID;
    
        pmg_inbox_send_wps_pmg_black_addr_list_cnf(local_param);
    }
}
#endif 
/*****************************************************************************
 ************************** Dialog Display Requests **************************
 *****************************************************************************/

#ifdef PHS_CFG_PUSH_SLIM_SUPPORT    
/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_new_dlg_display_req
 * DESCRIPTION
 *  create a new dialog display request object
 * PARAMETERS
 *  void
 * RETURNS
 *  dialog display request object pointer
 *****************************************************************************/
pmg_dlg_display_req_t *pmg_inbox_new_dlg_display_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_dlg_display_req_t *dlgreq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dlgreq = pmg_mem_alloc(sizeof(pmg_dlg_display_req_t));
    memset(dlgreq, 0, sizeof(pmg_dlg_display_req_t));

    return dlgreq;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_release_dlg_display_req
 * DESCRIPTION
 *  release dialog display request object
 * PARAMETERS
 *  dlgreq           [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_release_dlg_display_req(pmg_dlg_display_req_t *dlgreq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!dlgreq)
        return;

    if (dlgreq->dlgType == PMG_DLG_SIA_CONFIRM)
    {
        PMG_MEM_FREE(dlgreq->dlgInfo.siaInfo.host);
    }
    else if (dlgreq->dlgType == PMG_DLG_UNKNOWN_ADDR)
    {
        PMG_MEM_FREE(dlgreq->dlgInfo.msgInfo.text);
        PMG_MEM_FREE(dlgreq->dlgInfo.msgInfo.href);
        PMG_MEM_FREE(dlgreq->dlgInfo.msgInfo.smsc);
        PMG_MEM_FREE(dlgreq->dlgInfo.msgInfo.from);
   }

    PMG_MEM_FREE(dlgreq);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_register_dlg
 * DESCRIPTION
 *  append dialog display request to queue
 * PARAMETERS
 *  dlgRequest           [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_register_dlg(pmg_dlg_display_req_t *dlgRequest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_dlg_display_req_t *dlgreq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dlgRequest->next = 0;

    if (!g_pmg_inbox_cntx_t.pmg_lst_dlg_requests)
        g_pmg_inbox_cntx_t.pmg_lst_dlg_requests = dlgRequest;
    else
    {
        dlgreq = g_pmg_inbox_cntx_t.pmg_lst_dlg_requests;
        while (dlgreq->next)
            dlgreq = dlgreq->next;
        dlgreq->next = dlgRequest;
    }
}


/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_pop_dlg_display_request
 * DESCRIPTION
 *  pop first dialog display request from queue
 * PARAMETERS
 *  void
 * RETURNS
 *  dialog display request object
 *****************************************************************************/
static pmg_dlg_display_req_t *pmg_inbox_pop_dlg_display_request(MSF_UINT32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_dlg_display_req_t *dlgreq, *prev = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_pmg_inbox_cntx_t.pmg_lst_dlg_requests);
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG,
                PMG_POP_DLG_DISP_REQ_TEST, "PMG:pop_dlg_display_request (MSF_UINT32)app dlg id (%d)", (MSF_UINT32)id));

    dlgreq = g_pmg_inbox_cntx_t.pmg_lst_dlg_requests;
    while (dlgreq)
    {
       MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG,
                PMG_POP_DLG_DISP_REQ, "PMG:pop_dlg_display_request service dlg id (%d), app dlg id (%d)", (kal_uint32)dlgreq,(kal_uint32)id));
        
        if ((MSF_UINT32)dlgreq == id)
        {
            break;
        }
        prev = dlgreq;
        dlgreq = dlgreq->next;
    }

    ASSERT(dlgreq);
    if (g_pmg_inbox_cntx_t.pmg_lst_dlg_requests == dlgreq)
    {
        g_pmg_inbox_cntx_t.pmg_lst_dlg_requests = g_pmg_inbox_cntx_t.pmg_lst_dlg_requests->next;
    }
    else
    {
        prev->next = dlgreq->next;
    }
    return dlgreq;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_send_wps_pmg_dlg_sia_confirm_req
 * DESCRIPTION
 *  send MSG_ID_WPS_PMG_DLG_SIA_CONFIRM_REQ to push inbox app
 * PARAMETERS
 *  dlgreq           [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_send_wps_pmg_dlg_sia_confirm_req(pmg_dlg_display_req_t *dlgreq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_pmg_dlg_sia_confirm_req_struct *param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param =
        (wps_pmg_dlg_sia_confirm_req_struct*) construct_local_para(
                                                (kal_uint16) sizeof(wps_pmg_dlg_sia_confirm_req_struct),
                                                TD_RESET);

    param->trans_id = (kal_uint32)dlgreq;
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG,
                PMG_PUSH_SIA_DLG_ID_REQ, "PMG:wps_pmg_dlg_sia_confirm_req service dlg id (%d), assign app dlg id (%d)", (kal_uint32)dlgreq,(kal_uint32)param->trans_id));
    
    param->host_port = dlgreq->dlgInfo.siaInfo.port;
    param->host_addr.addr_type = WAP_PMG_ADDR_IP;
    strncpy((char *)param->host_addr.addr, dlgreq->dlgInfo.siaInfo.host, WAP_PMG_MAX_ADDR_CHARS);

    pmg_send_primitive(MOD_MMI, MSG_ID_WPS_PMG_DLG_SIA_CONFIRM_REQ, (void*)param, (void*)0);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_send_wps_pmg_dlg_unknown_addr_req
 * DESCRIPTION
 *  send MSG_ID_WPS_PMG_DLG_UNKNOWN_ADDR_REQ to push inbox app
 * PARAMETERS
 *  dlgreq           [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_send_wps_pmg_dlg_unknown_addr_req(pmg_dlg_display_req_t *dlgreq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_pmg_dlg_unknown_addr_req_struct *param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param =
        (wps_pmg_dlg_unknown_addr_req_struct*) construct_local_para(
                                                (kal_uint16) sizeof(wps_pmg_dlg_unknown_addr_req_struct),
                                                TD_RESET);

    param->trans_id = (kal_uint32)dlgreq;

    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG,
                PMG_PUSH_UNKNOWN_DLG_ID_REQ, "PMG:wps_pmg_dlg_unknown_addr_req service dlg id (%d), assign app dlg id (%d)", (kal_uint32)dlgreq,(kal_uint32)param->trans_id));
       
    param->msg_type = dlgreq->dlgInfo.msgInfo.msgType;
    if (dlgreq->dlgInfo.msgInfo.text)
    {
        if (pmg_check_is_ascii_string(dlgreq->dlgInfo.msgInfo.text))
        {
            param->text_type = PMG_STRTYPE_ASCII;
            strncpy((char*)param->text, dlgreq->dlgInfo.msgInfo.text, WAP_PMG_MAX_MSG_TEXT_CHARS);
        }
        else
        {
            param->text_type = PMG_STRTYPE_UCS2;
            mmi_chset_utf8_to_ucs2_string(
                (kal_uint8*) (param->text),
                (kal_int32) (WAP_PMG_MAX_MSG_TEXT_CHARS + 2),
                (kal_uint8*) (dlgreq->dlgInfo.msgInfo.text));
        }
    }

    if (dlgreq->dlgInfo.msgInfo.href)
    {
        strncpy((char *)param->href, dlgreq->dlgInfo.msgInfo.href, WAP_PMG_MAX_MSG_HREF_CHARS);
    }
    if (dlgreq->dlgInfo.msgInfo.smsc)
    {
        param->smsc.addr_type = dlgreq->dlgInfo.msgInfo.smscType;
        strncpy((char *)param->smsc.addr, dlgreq->dlgInfo.msgInfo.smsc, WAP_PMG_MAX_ADDR_CHARS);
    }
    if (dlgreq->dlgInfo.msgInfo.from)
    {
        param->from.addr_type = dlgreq->dlgInfo.msgInfo.fromType;
        strncpy((char *)param->from.addr, dlgreq->dlgInfo.msgInfo.from, WAP_PMG_MAX_ADDR_CHARS);
    }
    pmg_send_primitive(MOD_MMI, MSG_ID_WPS_PMG_DLG_UNKNOWN_ADDR_REQ, (void*)param, (void*)0);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_send_wps_pmg_dlg_query_cnf
 * DESCRIPTION
 *  send MSG_ID_WPS_PMG_DLG_QUERY_CNF to push inbox app
 * PARAMETERS
 *  param            [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_send_wps_pmg_dlg_query_cnf(wps_pmg_dlg_query_cnf_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pmg_send_primitive(MOD_MMI, MSG_ID_WPS_PMG_DLG_QUERY_CNF, (void*)param, (void*)0);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_handle_display_dialog_req
 * DESCRIPTION
 *  handle PMG_SIG_DISPLAY_DIALOG_REQ signal to PMG
 * PARAMETERS
 *  p              [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_handle_display_dialog_req(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_display_dialog_req_t *data = (pmg_display_dialog_req_t*) p;
    pmg_dlg_display_req_t *dlg_request = (pmg_dlg_display_req_t *)data->dlg_request;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pmg_inbox_register_dlg(dlg_request);

    switch (dlg_request->dlgType)
    {
        case PMG_DLG_SIA_CONFIRM:
            pmg_inbox_send_wps_pmg_dlg_sia_confirm_req(dlg_request);
            break;

        case PMG_DLG_UNKNOWN_ADDR:
            pmg_inbox_send_wps_pmg_dlg_unknown_addr_req(dlg_request);
            break;

        default:
            ASSERT(0);
    }
}
    
/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_handle_dlg_sia_confirm
 * DESCRIPTION
 *  handle MSG_ID_WPS_PMG_DLG_SIA_CONFIRM_CNF from push inbox app
 * PARAMETERS
 *  keyPressed              [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_handle_dlg_sia_confirm(MSF_UINT32 id, MSF_BOOL accept)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    pmg_dlg_display_req_t *dlgreq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dlgreq = pmg_inbox_pop_dlg_display_request(id);
    ASSERT(dlgreq->dlgType == PMG_DLG_SIA_CONFIRM);

    if (accept == TRUE)
    {
       
      //  phs_dlg_accept((void*)PMG_DLG_SIA_CONFIRM);
	 phs_dlg_response ((void*)PMG_DLG_SIA_CONFIRM, PHS_DLG_RESPONSE_POSITIVE);
    }
    else
//        phs_dlg_deny((void*)PMG_DLG_SIA_CONFIRM);
	 phs_dlg_response ((void*)PMG_DLG_SIA_CONFIRM, PHS_DLG_RESPONSE_NEGATIVE);

    pmg_inbox_release_dlg_display_req(dlgreq);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_handle_dlg_unknown_addr
 * DESCRIPTION
 *  handle MSG_ID_WPS_PMG_DLG_UNKNOWN_ADDR_CNF from push inbox app
 * PARAMETERS
 *  keyPressed                  [in]
 *  selectedIndex               [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_handle_dlg_unknown_addr(MSF_UINT32 id, MSF_BOOL accept)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_dlg_display_req_t *dlgreq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dlgreq = pmg_inbox_pop_dlg_display_request(id);
    ASSERT(dlgreq->dlgType == PMG_DLG_UNKNOWN_ADDR);

    if (accept == TRUE)
//		phs_dlg_select((void*)PMG_DLG_UNKNOWN_ADDR);
       	phs_dlg_response ((void*)PMG_DLG_UNKNOWN_ADDR, PHS_DLG_RESPONSE_UAF_ACCEPT);
    else
		//phs_dlg_cancel((void*)PMG_DLG_UNKNOWN_ADDR);
   	       phs_dlg_response ((void*)PMG_DLG_UNKNOWN_ADDR, PHS_DLG_RESPONSE_UAF_DECLINE);
    pmg_inbox_release_dlg_display_req(dlgreq);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_handle_dlg_query_req
 * DESCRIPTION
 *  handle MSG_ID_WPS_PMG_DLG_QUERY_REQ from push inbox app
 * PARAMETERS
 *  id                  [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_handle_dlg_query_req(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_inbox_dlg_query_req_t *data = (pmg_inbox_dlg_query_req_t*) p;
    pmg_dlg_display_req_t *dlgreq, *prev = NULL;
    wps_pmg_dlg_query_cnf_struct *local_param =
        (wps_pmg_dlg_query_cnf_struct*) construct_local_para(
                                                (kal_uint16) sizeof(wps_pmg_dlg_query_cnf_struct),
                                                TD_RESET);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dlgreq = g_pmg_inbox_cntx_t.pmg_lst_dlg_requests;
    while (dlgreq)
    {
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG,
                PMG_DLG_QUERY_REQ, "PMG:handle_dlg_query_req service dlg id (%d), app dlg id (%d)", (kal_uint32)dlgreq,(MSF_INT32)data->dlgID));
            
        if ((MSF_UINT32)dlgreq == data->dlgID)
        {
            break;
        }
        prev = dlgreq;
        dlgreq = dlgreq->next;
    }

    local_param->trans_id = data->transID;
    local_param->dlg_trans_id = data->dlgID;
    if (dlgreq)
    {
        local_param->result = TRUE;
        local_param->dlg_type = dlgreq->dlgType;
        if (local_param->dlg_type == WAP_PMG_DLG_SIA_CONFIRM)
        {
            wps_pmg_dlg_sia_confirm_req_struct *data = &local_param->dlg_data_union.sia;
            data->trans_id = (kal_uint32)dlgreq;
            data->host_port = dlgreq->dlgInfo.siaInfo.port;
            data->host_addr.addr_type = WAP_PMG_ADDR_IP;
            strncpy((char *)data->host_addr.addr, dlgreq->dlgInfo.siaInfo.host, WAP_PMG_MAX_ADDR_CHARS);
        }
        else if (local_param->dlg_type == WAP_PMG_DLG_UNKOWN_ADDR_CONFIRM)
        {
            wps_pmg_dlg_unknown_addr_req_struct *data = &local_param->dlg_data_union.msg;
            data->trans_id = (kal_uint32)dlgreq;
            data->msg_type = dlgreq->dlgInfo.msgInfo.msgType;
            if (dlgreq->dlgInfo.msgInfo.text)
            {
                if (pmg_check_is_ascii_string(dlgreq->dlgInfo.msgInfo.text))
                {
                    data->text_type = PMG_STRTYPE_ASCII;
                    strncpy((char*)data->text, dlgreq->dlgInfo.msgInfo.text, WAP_PMG_MAX_MSG_TEXT_CHARS);
                }
                else
                {
                    data->text_type = PMG_STRTYPE_UCS2;
                    mmi_chset_utf8_to_ucs2_string(
                        (kal_uint8*) (data->text),
                        (kal_int32) (WAP_PMG_MAX_MSG_TEXT_CHARS + 2),
                        (kal_uint8*) (dlgreq->dlgInfo.msgInfo.text));
                }
            }
        
            if (dlgreq->dlgInfo.msgInfo.href)
            {
                strncpy((char *)data->href, dlgreq->dlgInfo.msgInfo.href, WAP_PMG_MAX_MSG_HREF_CHARS);
            }
            if (dlgreq->dlgInfo.msgInfo.smsc)
            {
                data->smsc.addr_type = dlgreq->dlgInfo.msgInfo.smscType;
                strncpy((char *)data->smsc.addr, dlgreq->dlgInfo.msgInfo.smsc, WAP_PMG_MAX_ADDR_CHARS);
            }
            if (dlgreq->dlgInfo.msgInfo.from)
            {
                data->from.addr_type = dlgreq->dlgInfo.msgInfo.fromType;
                strncpy((char *)data->from.addr, dlgreq->dlgInfo.msgInfo.from, WAP_PMG_MAX_ADDR_CHARS);
            }
        }
        pmg_inbox_send_wps_pmg_dlg_query_cnf(local_param);
    }
	else
	{
        local_param->result = FALSE;
        pmg_inbox_send_wps_pmg_dlg_query_cnf(local_param);
	}
}
#endif 
#ifdef __MMI_BRW_PUSH_DELETE_LAST_ITEM_WHEN_STORAGE_FULL__
/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_send_wps_pmg_dlg_push_storage_full_ind
 * DESCRIPTION
 *  send MSG_ID_WPS_PMG_DLG_PUSH_STORAGE_FULL_IND to push inbox app
 * PARAMETERS
 *  msgID    [in]
 *  msgType  [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_send_wps_pmg_dlg_push_storage_full_ind(int msgID, MSF_UINT8 msgType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_pmg_delete_ind_struct *param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param =
        (wps_pmg_delete_ind_struct*) construct_local_para((kal_uint16) sizeof(wps_pmg_delete_ind_struct), TD_RESET);
    param->msgs[0].msg_id = (kal_int32) msgID;
    param->msgs[0].msg_type = (kal_uint8) msgType;

    pmg_send_primitive(MOD_MMI, MSG_ID_WPS_PMG_DLG_PUSH_STORAGE_FULL_IND, (void*)param, (void*)0);
}

#else
/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_send_wps_pmg_dlg_push_storage_full_ind
 * DESCRIPTION
 *  send MSG_ID_WPS_PMG_DLG_PUSH_STORAGE_FULL_IND to push inbox app
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_inbox_send_wps_pmg_dlg_push_storage_full_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pmg_send_primitive(MOD_MMI, MSG_ID_WPS_PMG_DLG_PUSH_STORAGE_FULL_IND, (void*)0, (void*)0);
}
#endif /*__MMI_BRW_PUSH_DELETE_LAST_ITEM_WHEN_STORAGE_FULL__*/


#ifdef __MMI_PUSH_TURN_ON_OFF_SWITCH__
/*****************************************************************************
 * FUNCTION
 *  pmg_inbox_push_turn_on_off_check
 * DESCRIPTION
 *  check turn on/ off variable
 * PARAMETERS
 *  void
 * RETURNS
 * int
 *****************************************************************************/

int pmg_inbox_push_turn_on_off_check(void)
{
	if(g_pmg_inbox_cntx_t.push_turn_on_switch) 
		return TRUE;
	else 
		return FALSE;
}


void pmg_inbox_set_push_turn_on_switch(MSF_UINT8 push_turn_on_switch)
{
	g_pmg_inbox_cntx_t.push_turn_on_switch = push_turn_on_switch;
}
#endif /* __MMI_PUSH_TURN_ON_OFF_SWITCH__ */
