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
 * UMSrvMsgHandler.c
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
/**********  KAL Layer Header **************/
#include "string.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "stack_common.h"
#include "stack_msgs.h"

/**********  MMI Layer Header **************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "mmi_cb_mgr_gprot.h"
#include "customer_email_num.h"
#include "Unicodexdcl.h"
#include "mms_adp.h"    /* mms_get_service_module */
#include "PhbSrvGprot.h"

#include "UmSrvGprot.h"
#include "UmSrvprot.h"
//#include "UmSrvStruct.h"
//#include "SimDetectionGprot.h"
#include "mmi_rp_srv_unifiedmessage_def.h"

srv_um_msg_enum um_msg_type; 
S32 um_msg_id; 
void *um_local_para_ptr; 
void *um_peer_buff_ptr;
static S32 um_counter = 0;

/*****************************************************************************
 * FUNCTION
 *  srv_um_send_message
 * DESCRIPTION
 *  Send message
 * PARAMETERS
 *  msg_type            [IN]    message type
 *  msg_id              [IN]    message id
 *  local_para_ptr      [IN]    local parameter
 *  peer_buff_ptr       [IN]    peer buffer
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
void srv_um_send_message_ext(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    srv_um_msg_enum msg_type_ex =  um_msg_type;
    S32 msg_id = um_msg_id; 
    void *local_para_ptr = um_local_para_ptr; 
    void *peer_buff_ptr = um_peer_buff_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(SRV_UM_SEND_MSG_TIMER_ID);

    Message.oslSrcId = stack_get_active_module_id();

    switch (msg_type_ex)
    {
        case SRV_UM_MSG_SMS:
            Message.oslDestId = MOD_MMI;
            break;

    #ifdef __MMI_PROV_IN_UM__
        case SRV_UM_MSG_PROV:
            Message.oslDestId = MOD_MMI;
            break;
    #endif

    #ifdef __MMI_MMS_IN_UM__
        case SRV_UM_MSG_MMS:
            Message.oslDestId = mms_get_service_module(msg_id);
            break;
    #endif

    #ifdef __MMI_PUSH_IN_UM__
        case SRV_UM_MSG_WAP_PUSH:
            Message.oslDestId = MOD_WPS;
            break;
    #endif

    #ifdef __SRV_UM_UT__
        case SRV_UM_MSG_UT:
            Message.oslDestId = MOD_MMI;
            break;
    #endif

        default:
            ASSERT(0);
            break;
    }

    Message.oslMsgId = (msg_type)msg_id;
    Message.oslDataPtr = (local_para_struct*) local_para_ptr;
    Message.oslPeerBuffPtr = (peer_buff_struct*) peer_buff_ptr;

    switch (Message.oslDestId)
    {
        case MOD_WPS:
            Message.oslSapId = WPS_APP_SAP;
            break;
        case MOD_WAP:
        case MOD_MMS:
            Message.oslSapId = MMI_WAP_SAP;
            break;
        case MOD_MMI:
            Message.oslSapId = MMI_MMI_SAP;
            break;
        default:
            Message.oslSapId = INVALID_SAP;
            break;
    }

    OslMsgSendExtQueue(&Message);
}


void srv_um_send_message(srv_um_msg_enum msg_type, S32 msg_id, void *local_para_ptr, void *peer_buff_ptr)
{
    um_msg_type =  msg_type;
    um_msg_id = msg_id; 
    um_local_para_ptr = local_para_ptr; 
    um_peer_buff_ptr = peer_buff_ptr;

    um_counter++;
    if (um_counter >= 10)
    {
        um_counter = 0;
        StartTimer(SRV_UM_SEND_MSG_TIMER_ID, 10, srv_um_send_message_ext);
    }
    else
    {
        StartTimer(SRV_UM_SEND_MSG_TIMER_ID, 0, srv_um_send_message_ext);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_recv_delete_all_ind
 * DESCRIPTION
 *  handler of MSG_ID_MMI_UM_DELETE_ALL_IND
 * PARAMETERS
 *  inMsg       [IN]    message
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
void srv_um_send_delete_all_res(srv_um_msg_enum msg_type, MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_delete_all_res_struct *msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    msg = (srv_um_delete_all_res_struct*) construct_local_para(sizeof(srv_um_delete_all_res_struct), TD_CTRL | TD_RESET);
    msg->result = result;
    msg->msg_type = msg_type;

    srv_um_send_message(msg_type, MSG_ID_MMI_UM_DELETE_ALL_RES, msg, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  srv_um_recv_ready_ind
 * DESCRIPTION
 *  handler of MSG_ID_MMI_UM_READY_IND
 * PARAMETERS
 *  inMsg       [IN]    message
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
MMI_BOOL srv_um_recv_ready_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_ready_ind_struct *msg = (srv_um_ready_ind_struct*) inMsg;

    srv_um_notify_ready_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_um_ready_ind(msg->result, msg->msg_type);

    // new solution for callback manager.
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_UM_NOTIFY_READY);
    evt.result = msg->result;
    evt.msg_type = msg->msg_type;
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);

	return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_um_recv_highlight_msg_ind
 * DESCRIPTION
 *  handler of MSG_ID_MMI_UM_HIGHLIGHT_MSG_IND
 * PARAMETERS
 *  inMsg       [IN]    message
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
void srv_um_recv_highlight_msg_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_highlight_msg_ind_struct *msg = (srv_um_highlight_msg_ind_struct*) inMsg;

    srv_um_notify_highlight_msg_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    // new solution for callback manager.
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_UM_NOTIFY_HIGHLIGHT_MSG);
    evt.msg_box_type = msg->msg_box_type;
    evt.msg_type = msg->msg_type;
    evt.msg_id = msg->msg_id;
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}


#if defined(__MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) && defined(__MMI_MMS_IN_UM__)
mmi_ret mmi_um_sd_card_plug_in_out_hdlr()
{
    srv_um_notify_refresh_evt_struct evt;
    srv_um_msg_enum msg_type = SRV_UM_MSG_MMS;
    srv_um_msg_box_enum msg_box_type = SRV_UM_MSG_BOX_ALL;

    srv_um_refresh_ind_interanl(SRV_UM_REFRESH_NONE, msg_type, msg_box_type);

    memset((CHAR*)&evt, 0, sizeof(srv_um_notify_refresh_evt_struct));
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_UM_NOTIFY_REFRESH);
    evt.msg_box_type = msg_box_type;
    evt.msg_type = msg_type;
    evt.refresh_type = SRV_UM_REFRESH_NONE;
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);

    return MMI_RET_OK;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  srv_um_recv_refresh_ind
 * DESCRIPTION
 *  handler of MSG_ID_MMI_UM_REFRESH_IND
 * PARAMETERS
 *  inMsg       [IN]    message
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
void srv_um_recv_refresh_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_refresh_ind_struct *ind = (srv_um_refresh_ind_struct*) inMsg;
    srv_um_notify_refresh_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_um_refresh_ind(ind);

    // new solution for callback manager.
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_UM_NOTIFY_REFRESH);
    evt.msg_box_type = ind->msg_box_type;
    evt.msg_type = ind->msg_type;
    evt.msg_id = ind->msg_id;
    evt.refresh_type = ind->refresh_type;
    evt.addr_type = ind->addr_type;
    mmi_ucs2ncpy((CHAR*)evt.address, (CHAR*)ind->address, SRV_UM_MAX_ADDR_LEN);
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);

}

#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_um_recv_get_thread_id_req
 * DESCRIPTION
 *  handler of MSG_ID_MMI_GET_THREAD_ID_REQ
 * PARAMETERS
 *  inMsg       [IN]    message
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
void srv_um_recv_get_thread_id_req(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_get_thread_id_req_struct *req = (srv_um_get_thread_id_req_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_um_tsfr_address_to_thread_id(req->type, req->number, req->sim_id, req->thread_id);

    kal_set_eg_events(g_ums_p->event_group, SRV_UM_EG_GET_THREAD_ID, KAL_OR);
}

/*****************************************************************************
 * FUNCTION
 *  srv_um_recv_lookup_number_req
 * DESCRIPTION
 *  handler of MSG_ID_MMI_LOOKUP_NUMBER_REQ
 * PARAMETERS
 *  inMsg       [IN]    message
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
void srv_um_recv_lookup_number_req(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_lookup_number_req_struct *req = (srv_um_lookup_number_req_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_phb_get_name_by_number((U16*)req->number, (U16*)req->name, req->len);

    kal_set_eg_events(g_ums_p->event_group, SRV_UM_EG_LOOKUP_NUMBER, KAL_OR);
}
#endif

/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
#undef PROCESS_TYPE_BASIC_DEF
#define PROCESS_TYPE_BASIC_DEF(type, tag)           \
    MMI_BOOL srv_um_recv_##tag##_rsp(void *inMsg)   \
    {                                               \
        RSP_STRUCT(tag) *rsp = inMsg;               \
        if (rsp->app_id != 0)                       \
        {                                           \
            return MMI_FALSE;                       \
        }                                           \
        srv_um_response_handler(type, inMsg);       \
        return MMI_TRUE;                            \
    }

ALL_PROCESS_TYPE_DEF


/*****************************************************************************
 * FUNCTION
 *  srv_um_set_protocol_event_handler
 * DESCRIPTION
 *  Set all the protocol event handler in UM Service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
void srv_um_set_protocol_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_GET_MSG_NUM_RSP, (PsIntFuncPtr)srv_um_recv_get_msg_num_rsp, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_GET_MSG_LIST_RSP, (PsIntFuncPtr)srv_um_recv_get_msg_list_rsp, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_GET_MSG_INFO_RSP, (PsIntFuncPtr)srv_um_recv_get_msg_info_rsp, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_DELETE_FOLDER_RSP, (PsIntFuncPtr)srv_um_recv_delete_folder_rsp, MMI_TRUE);
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_MARK_SEVERAL_OP_RSP, (PsIntFuncPtr)srv_um_recv_mark_several_op_rsp, MMI_TRUE);
#endif

#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_TRAVERSE_MSG_RSP, (PsIntFuncPtr)srv_um_recv_traverse_msg_rsp, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_GET_THREAD_ID_REQ, (PsIntFuncPtr)srv_um_recv_get_thread_id_req, MMI_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_LOOKUP_NUMBER_REQ, (PsIntFuncPtr)srv_um_recv_lookup_number_req, MMI_FALSE);
#endif

    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_READY_IND, (PsIntFuncPtr)srv_um_recv_ready_ind, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_HIGHLIGHT_MSG_IND, (PsIntFuncPtr)srv_um_recv_highlight_msg_ind, MMI_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_REFRESH_IND, (PsIntFuncPtr)srv_um_recv_refresh_ind, MMI_FALSE);


    #ifdef __SRV_UM_UT__
    srv_um_ut_set_protocol_event_handler();
    #endif
}

/*************************************************************
  * FUNCTION
  *   srv_um_add_address
  * Description
  *   Step1. Allocate memory for srv_um_addr_struct
  *   Step2. Assign the value of addr, type and group in srv_um_addr_struct
  *   Step3. Find the last address in detail and append the new addr struct on it.
  *
  *   In this function, it would not allocate another memory to save
  *   parameter "addr", therefore, please do not free the addr until invoke
  *   traverse function.
  *
  * Parameters
  *   detail    :  [IN] the destination
  *   addr      :  [IN] address
  *   type      :  [IN] type of address
  *   group     :  [IN] group of address
  *   mem_alloc_fn  : [IN] alloc memory function
  * Returns
  *   srv_um_result_enum
  *************************************************************/
kal_int32 srv_um_add_address(
    srv_um_msg_detail_struct* detail,
    kal_wchar* addr,
    srv_um_addr_enum type,
    srv_um_addr_group_enum group,
    srv_um_mem_alloc_fn mem_alloc_fn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (detail->address.addr == NULL)
    {
        detail->address.addr = addr;
        detail->address.next = detail->address.previous = NULL;
        detail->address.type = type;
        detail->address.group = group;
    }
    else
    {
        srv_um_addr_struct *last_address = &detail->address;

        while (last_address->next != NULL)
        {
            last_address = last_address->next;
        }

        last_address->next = (srv_um_addr_struct*) mem_alloc_fn(sizeof(srv_um_addr_struct));

        last_address->next->previous = last_address;
        last_address->next->next = NULL;
        last_address->next->type = type;
        last_address->next->group = group;
        last_address->next->addr = addr;
    }
    return SRV_UM_RESULT_OK;
}

/*************************************************************
  * FUNCTION
  *   srv_um_free_address_list
  * Description
  *   Step1. Find the last address, and free the srv_um_addr_struct memory
  *   Step2. Set the next pointer as NULL
  *   Step3. Repeat Step1 and Setp2 until all extended address are freed.
  *
  *   In default, it would not use the free function to free addr in
  *   srv_um_addr_struct. Therefore, if application also need to
  *   free the addr, please set the paramter free_addr as KAL_TRUE.
  * Parameters
  *   detail              : [IN] the destination
  *   applib_mem_free_fn  : [IN] free memory function
  *   free_addr           : [IN] also free the addr in srv_um_addr_struct
  * Returns
  *   srv_um_result_enum
  *************************************************************/
kal_int32 srv_um_free_address_list(
    srv_um_msg_detail_struct* detail,
    srv_um_mem_free_fn mem_free_fn,
    kal_bool free_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_addr_struct *curr_address, *next_address;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (detail->address.addr == NULL)
    {
        return SRV_UM_RESULT_OK;
    }

    if (free_addr)
    {
        mem_free_fn(detail->address.addr);
    }

    curr_address = detail->address.next;

    if (curr_address)
    {
        do {
            next_address = curr_address->next;

            if (free_addr)
            {
                mem_free_fn(curr_address->addr);
            }

            mem_free_fn(curr_address);

            curr_address = next_address;

        } while(curr_address != NULL);
    }

    return SRV_UM_RESULT_OK;
}


#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
mmi_ret srv_um_on_time_change_event(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
    srv_um_refresh_ind_struct refresh_ind;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
    memset(&refresh_ind, 0x00,sizeof(srv_um_refresh_ind_struct));
    refresh_ind.msg_type = SRV_UM_MSG_ALL;
    refresh_ind.msg_box_type = SRV_UM_MSG_BOX_ALL;

    srv_um_recv_refresh_ind(&refresh_ind);

	return MMI_OK;
}
#endif

