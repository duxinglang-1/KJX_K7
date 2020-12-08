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
 *  MMSBGSRSrvMsg.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contans the message Handlings.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_MMS_BGSR_SUPPORT__) && !defined(__MMI_MMS_LOW_TIER_BGSR_SUPPORT__)

#include "MMSBGSRSrvProt.h"
#if defined(__MMI_USB_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__)
#include "USBSrvGProt.h"
#endif 
#ifdef __DM_LAWMO_SUPPORT__
#include "dmuigprot.h"
#endif 
//#ifdef __MMI_MMS_FALLBACK__
//#include "CbmCuiGprot.h"
//#endif /* __MMI_MMS_FALLBACK__ */
#include "CbmSrvGprot.h"
#include "UcmSrvGprot.h"
#include "MmsSrvGprot.h"
#include "MMIDataType.h"
#include "mma_struct.h"
#include "MMI_inet_app_trc.h"
#include "mma_api.h"
#include "kal_general_types.h"
#include "mms_sap_struct.h"
#include "kal_public_defs.h" 
#include "mms_adp.h"
#include "Unicodexdcl.h"
#include "kal_public_api.h"
#include "string.h"
#include "stack_ltlcom.h"
#include "WAPProfileSrvType.h"
#include "ModeSwitchSrvGprot.h"
#ifdef __MMI_UMMS_JSR205__
#include "MMSJSRSrvProts.h"
#endif 
/* TRACE */

/*******************************************************************************
 * Static Declaration
 *******************************************************************************/
/*******************************************************************************
 * Global Variable
 *******************************************************************************/
extern srv_mms_bgsr_callback_struct srv_mms_bgsr_callback_table
    [SRV_MMS_BGSR_TOTAL_SOLUTION_NUM][SRV_MMS_BGSR_CALLBACK_NUM];

/*******************************************************************************
 * Local Function
 *******************************************************************************/

/*******************************************************************************
 * Global Function
 *******************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_sync
 * DESCRIPTION
 *  To check whether the message is valid
 * PARAMETERS
 *  storage_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_sync(U8 storage_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */
    int i, j = 0;
    wap_mma_msg_is_valid_req_struct *msg_req;
    U32 request_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init */

    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_SYNC, __LINE__);
    if (!srv_mms_bgsr_is_mma_ready())
    {
        return;
    }
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    if (storage_type == MMA_MSG_STORAGE_CARD1)
    {
        if (g_srv_mms_bgsr_context.sync_flag & SRV_MMS_BGSR_SYNC_REQ_PH_MEM)
        {
            g_srv_mms_bgsr_context.sync_flag |= SRV_MMS_BGSR_SYNC_REQ_MEM_CARD_PENDING;
            return;
        }
        else
        {
            g_srv_mms_bgsr_context.sync_flag |= SRV_MMS_BGSR_SYNC_REQ_MEM_CARD;
        }

    }
    else
    {
        if (g_srv_mms_bgsr_context.sync_flag & SRV_MMS_BGSR_SYNC_REQ_MEM_CARD)
        {
            g_srv_mms_bgsr_context.sync_flag |= SRV_MMS_BGSR_SYNC_REQ_PH_MEM_PENDING;
            return;
        }
        else
        {
            g_srv_mms_bgsr_context.sync_flag |= SRV_MMS_BGSR_SYNC_REQ_PH_MEM;
        }
    }
#else /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    g_srv_mms_bgsr_context.sync_flag |= SRV_MMS_BGSR_SYNC_REQ_PH_MEM;
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    request_id = srv_mms_bgsr_get_request_id();
    msg_req =
        (wap_mma_msg_is_valid_req_struct*) construct_local_para(
                                            sizeof(wap_mma_msg_is_valid_req_struct),
                                            TD_CTRL | TD_RESET);
    msg_req->app_id = MMA_APP_ID_BGSR;
    msg_req->req_id = request_id;

    for (i = 0; i < SRV_MMS_BGSR_MAX_MSG_NUM; i++)
    {
    #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
        if (storage_type == MMA_MSG_STORAGE_CARD1)
        {
            if (mem_card_msg_array[i].msg_id != 0)
            {
                msg_req->msg_id_list[j++] = mem_card_msg_array[i].msg_id;
            }
        }
        else
    #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ /* #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
        {
            if (ph_mem_msg_array[i].msg_id != 0)
            {
                msg_req->msg_id_list[j++] = ph_mem_msg_array[i].msg_id;
            }
        }
    }
    if (j < SRV_MMS_BGSR_MAX_MSG_NUM)
    {
        msg_req->msg_id_list[j] = 0;
    }

    srv_mms_bgsr_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_MSG_IS_VALID_REQ),
        0,
        MSG_ID_WAP_MMA_MSG_IS_VALID_REQ,
        (oslParaType*) msg_req,
        NULL);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_send_mms_req
 * DESCRIPTION
 *  Send MMS msg request
 * PARAMETERS
 *  msg     [IN]        The message to send
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL srv_mms_bgsr_send_mms_req(U8 msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_send_req_struct *msg_req;
    U32 request_id;
    srv_mms_bgsr_msg_struct *curr_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_TRY_TO_SEND, __LINE__);

    if (!srv_mms_bgsr_is_mma_ready()
#if defined(__MMI_USB_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__)
        || srv_usb_is_in_mass_storage_mode() || srv_mms_bgsr_mms_is_exported()
#endif 
        )
    {
        return FALSE;
    }

    /* sanity check */
    if (msg == 0)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MSG_NOT_FOUND, __LINE__);
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_SEND_MMS_REQ, 0, __LINE__);
        srv_mms_bgsr_echo_current_info();
        return FALSE;
    }

    curr_node = srv_mms_bgsr_get_msg_array(msg);

#ifndef __UMTS_RAT__
    if ((srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0) ||
        (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0))
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_SEND_MMS_REQ, 0, __LINE__);
        return FALSE;
    }
#endif /* __UMTS_RAT__ */ 
    if (srv_cbm_is_sim_nwk_srv_disallowed(srv_mms_bgsr_convert_mma_sim_id_to_cbm_sim_id(curr_node->sim_id),SRV_CBM_BEARER_PS | SRV_CBM_BEARER_CSD) == MMI_TRUE)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_SEND_MMS_REQ, -1, __LINE__);
        return FALSE;
    }
    if (!srv_mode_switch_is_network_service_available())
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_SEND_MMS_REQ, -2, __LINE__);
        return FALSE;
    }
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    if (msg & SRV_MMS_BGSR_MEM_CARD_BIT)
    {
        if (!srv_mms_bgsr_is_mem_card_sync())
        {
            return FALSE;
        }
    }
    else
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    {
        if (!srv_mms_bgsr_is_ph_sync())
        {
            return FALSE;
        }
    }
    
#ifdef __MMI_MMS_FALLBACK__
    if (g_srv_mms_bgsr_context.fallback_send_id != 0)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_NEED_FALLBACK, curr_node->msg_id, __LINE__);
        return FALSE;
    }
#endif /* __MMI_MMS_FALLBACK__ */ 

    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_SEND_MMS_REQ, curr_node->msg_id, __LINE__);

    /* init */
    curr_node->status = SRV_MMS_BGSR_STATUS_SENDING;
    g_srv_mms_bgsr_context.send_msg_id = curr_node->msg_id;
    request_id = srv_mms_bgsr_get_request_id();

    msg_req = (wap_mma_send_req_struct*) construct_local_para(sizeof(wap_mma_send_req_struct), TD_CTRL | TD_RESET);
    msg_req->app_id = MMA_APP_ID_BGSR;
    msg_req->req_id = request_id;
    msg_req->msg_id = curr_node->msg_id;
    if (curr_node->msg_info & SRV_MMS_BGSR_IS_RR_INFO)
    {
        msg_req->is_read_report = KAL_TRUE;
    }
    else
    {
        msg_req->is_read_report = KAL_FALSE;
    }
    msg_req->sim_id = curr_node->sim_id;

    srv_mms_bgsr_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_SEND_REQ),
        0,
        MSG_ID_WAP_MMA_SEND_REQ,
        (oslParaType*) msg_req,
        NULL);

#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
    if (curr_node->msg_id == g_srv_mms_bgsr_context.vendor_send_msg_id)
    {
        return FALSE;
    }
    else
#endif /* __MMI_MMS_VENDOR_APP_SUPPORT__ */ 
    {
        g_srv_mms_bgsr_context.send_sim_id = curr_node->sim_id;
        srv_mms_bgsr_show_mms_status_icon(SRV_MMS_BGSR_INDICATOR_BUSY, SRV_MMS_BGSR_INDICATOR_SEND_OP);
        (srv_mms_bgsr_callback_table[0][0].update_menu_item_callback) (curr_node->msg_id, SRV_MMS_BGSR_UPDATE_STATUS);
        return TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_send_mms_ind_hdlr
 * DESCRIPTION
 *  Send MMS message indication handler
 * PARAMETERS
 *  in_msg      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_mms_bgsr_send_mms_ind_hdlr(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_send_ind_struct *msg_ind = (wap_mma_send_ind_struct*) in_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* sanity check */
    if (in_msg == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MSG_NOT_FOUND, __LINE__);
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_SEND_MMS_IND_HDLR, 0, __LINE__);
        srv_mms_bgsr_echo_current_info();
        return FALSE;
    }
    if (msg_ind->app_id == MMA_APP_ID_BGSR)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_SEND_MMS_IND_HDLR, msg_ind->msg_id, __LINE__);

        if (g_srv_mms_bgsr_context.send_msg_id != msg_ind->msg_id)
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MSG_NOT_FOUND, __LINE__);
            srv_mms_bgsr_echo_current_info();
        }
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_send_mms_rsp
 * DESCRIPTION
 *  Send MMS msg response
 * PARAMETERS
 *  in_msg      [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_mms_bgsr_send_mms_rsp(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_send_rsp_struct *msg_rsp = (wap_mma_send_rsp_struct*) in_msg;

#ifdef __MMI_MMS_FALLBACK__
    U8 sim_id = MMA_SIM_ID_SIM1;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* sanity check */
    if (in_msg == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MSG_NOT_FOUND, __LINE__);
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_SEND_MMS_RSP, 0, __LINE__);
        srv_mms_bgsr_echo_current_info();
        return FALSE;
    }
    if (msg_rsp->app_id == MMA_APP_ID_BGSR)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_SEND_MMS_RSP, msg_rsp->msg_id, __LINE__);
        /* if the message id is not consistent, ignore it */

        if (g_srv_mms_bgsr_context.send_msg_id != msg_rsp->msg_id)
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MSG_NOT_FOUND, __LINE__);
            srv_mms_bgsr_echo_current_info();
            return TRUE;
        }

    #ifdef __MMI_MMS_FALLBACK__
        sim_id = g_srv_mms_bgsr_context.send_sim_id;
    #endif 
        srv_mms_bgsr_action_send_rsp(msg_rsp);

    #ifdef __MMI_MMS_FALLBACK__
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            SRV_MMS_BGSR_FALLBACK_MASK,
            sim_id,
            g_srv_mms_bgsr_context.fallback_mask,
            __LINE__);
        g_srv_mms_bgsr_context.fallback_mask &= ~SRV_MMS_BGSR_FALLBACK_MASK_SENDING;
        srv_mms_bgsr_send_select_rsp_handler(sim_id);
    #endif /* __MMI_MMS_FALLBACK__ */ 
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_abort_send_mms_req
 * DESCRIPTION
 *  Abort sending MMS msg request
 * PARAMETERS
 *  msg_id      [IN]        The message id
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_abort_send_mms_req(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_cancel_send_req_struct *msg_req;
    U32 request_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* sanity check */
    if (msg_id == 0)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MSG_NOT_FOUND, __LINE__);
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_ABORT_SEND_MMS_REQ, 0, __LINE__);
        srv_mms_bgsr_echo_current_info();
        return;
    }

    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_ABORT_SEND_MMS_REQ, msg_id, __LINE__);

    request_id = srv_mms_bgsr_get_request_id();

    msg_req =
        (wap_mma_cancel_send_req_struct*) construct_local_para(
                                            sizeof(wap_mma_cancel_send_req_struct),
                                            TD_CTRL | TD_RESET);
    msg_req->app_id = MMA_APP_ID_BGSR;
    msg_req->req_id = request_id;
    msg_req->msg_id = msg_id;

    srv_mms_bgsr_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_CANCEL_SEND_REQ),
        0,
        MSG_ID_WAP_MMA_CANCEL_SEND_REQ,
        (oslParaType*) msg_req,
        NULL);

    if (1
#ifdef __MMI_UMMS_JSR205__
        && msg_id != g_srv_mms_bgsr_context.java_send_msg_id
#endif 
#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
        && msg_id != g_srv_mms_bgsr_context.vendor_send_msg_id
#endif 
        )
    {
        (srv_mms_bgsr_callback_table[0][0].update_menu_item_callback) (msg_id, SRV_MMS_BGSR_UPDATE_STATUS);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_abort_send_mms_rsp
 * DESCRIPTION
 *  Abort MMS msg response
 * PARAMETERS
 *  in_msg      [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_mms_bgsr_abort_send_mms_rsp(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_rsp_struct *msg_rsp = (wap_mma_rsp_struct*) in_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* sanity check */
    if (in_msg == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MSG_NOT_FOUND, __LINE__);
        srv_mms_bgsr_echo_current_info();
        return FALSE;
    }
    if (msg_rsp->app_id == MMA_APP_ID_BGSR)
    {
        srv_mms_bgsr_action_cancel_send_rsp(msg_rsp);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_delete_mms_req
 * DESCRIPTION
 *  Delete MMS msg request
 * PARAMETERS
 *  msg_id      [IN]        Message id
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_delete_mms_req(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_delete_req_struct *msg_req;
    U32 request_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    request_id = srv_mms_bgsr_get_request_id();

    if (msg_id == 0)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MSG_NOT_FOUND, __LINE__);
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_DELETE_MMS_REQ, 0, __LINE__);
        srv_mms_bgsr_echo_current_info();
        return;
    }

    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_DELETE_MMS_REQ, msg_id, __LINE__);

    msg_req = (wap_mma_delete_req_struct*) construct_local_para(sizeof(wap_mma_delete_req_struct), TD_CTRL | TD_RESET);
    msg_req->app_id = MMA_APP_ID_BGSR;
    msg_req->req_id = request_id;
    msg_req->msg_id[0] = msg_id;
    msg_req->no_of_msg = 1;

    srv_mms_bgsr_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_DELETE_REQ),
        0,
        MSG_ID_WAP_MMA_DELETE_REQ,
        (oslParaType*) msg_req,
        NULL);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_delete_mms_rsp
 * DESCRIPTION
 *  Delete MMS msg response
 * PARAMETERS
 *  in_msg      [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_mms_bgsr_delete_mms_rsp(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_delete_rsp_struct *msg_rsp = (wap_mma_delete_rsp_struct*) in_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* sanity check */
    if (in_msg == NULL)
    {
        return FALSE;
    }
    if (msg_rsp->app_id == MMA_APP_ID_BGSR)
    {
        srv_mms_bgsr_action_delete_rsp(msg_rsp);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_save_mms_req
 * DESCRIPTION
 *  Save MMS msg request
 * PARAMETERS
 *  msg_id          [IN]        Message id
 *  folder          [IN]        
 *  msg_box(?)      [IN]        Message box
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_save_mms_req(U32 msg_id, U16 folder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_save_req_struct *msg_req;
    U32 request_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_id == 0)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MSG_NOT_FOUND, __LINE__);
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_SAVE_MMS_REQ, 0, __LINE__);
        srv_mms_bgsr_echo_current_info();
        return;
    }
    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_SAVE_MMS_REQ, msg_id, __LINE__);

    request_id = srv_mms_bgsr_get_request_id();

    msg_req = (wap_mma_save_req_struct*) construct_local_para(sizeof(wap_mma_save_req_struct), TD_CTRL | TD_RESET);
    msg_req->app_id = MMA_APP_ID_BGSR;
    msg_req->req_id = request_id;
    msg_req->msg_id[0] = msg_id;
    msg_req->no_of_msg = 1;
    msg_req->box = folder;

    srv_mms_bgsr_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_SAVE_REQ),
        0,
        MSG_ID_WAP_MMA_SAVE_REQ,
        (oslParaType*) msg_req,
        NULL);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_save_mms_rsp
 * DESCRIPTION
 *  Save MMS msg response
 * PARAMETERS
 *  in_msg      [?]     
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_mms_bgsr_save_mms_rsp(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_save_rsp_struct *msg_rsp = (wap_mma_save_rsp_struct*) in_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (in_msg == NULL)
    {
        return FALSE;
    }
    if (msg_rsp->app_id == MMA_APP_ID_BGSR)
    {
        srv_mms_bgsr_action_save_rsp(msg_rsp);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_set_rr_flag_req
 * DESCRIPTION
 *  Set rr flag
 * PARAMETERS
 *  msg_id      [IN]        The message to send
 *  flag        [IN]        Flag
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_set_rr_flag_req(U32 msg_id, U8 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_rr_mark_req_struct *msg_req;
    U32 request_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_mms_bgsr_is_mma_ready())
    {
        return;
    }
    request_id = srv_mms_bgsr_get_request_id();
    msg_req =
        (wap_mma_rr_mark_req_struct*) construct_local_para(sizeof(wap_mma_rr_mark_req_struct), TD_CTRL | TD_RESET);
    msg_req->msg_id = msg_id;
    msg_req->app_id = MMA_APP_ID_BGSR;
    msg_req->req_id = request_id;
    msg_req->rr_mark = flag;
    msg_req->rr_reset_all = KAL_FALSE;

    srv_mms_bgsr_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_RR_MARK_REQ),
        0,
        MSG_ID_WAP_MMA_RR_MARK_REQ,
        (oslParaType*) msg_req,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_set_rr_rsp
 * DESCRIPTION
 *  Download MMS msg request
 * PARAMETERS
 *  in_msg      [?]         
 *  msg(?)      [IN]        The message to send
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_set_rr_rsp(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_download_mms_req
 * DESCRIPTION
 *  Download MMS msg request
 * PARAMETERS
 *  msg     [IN]        The message to send
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL srv_mms_bgsr_download_mms_req(U8 msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_download_req_struct *msg_req;
    U32 request_id;
    srv_mms_bgsr_msg_struct *curr_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_mms_bgsr_is_mma_ready()
#if defined(__MMI_USB_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__)
        || srv_usb_is_in_mass_storage_mode() || srv_mms_bgsr_mms_is_exported()
#endif 
        )
    {
        return FALSE;
    }
    curr_node = srv_mms_bgsr_get_msg_array(msg);
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    if ((curr_node->msg_id & SRV_MMS_BGSR_MEM_CARD_BIT))
    {
        if (!srv_mms_bgsr_is_mem_card_sync())
        {
            return FALSE;
        }
    }
    else
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    {
        if (!srv_mms_bgsr_is_ph_sync())
        {
            return FALSE;
        }
    }
    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_TRY_TO_DOWNLOAD, __LINE__);
#ifndef __UMTS_RAT__
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0 ||
        (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0))
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_DOWNLOAD_MMS_REQ, 0, __LINE__);
        return FALSE;
    }
#endif /* __UMTS_RAT__ */ 
    if (srv_cbm_is_sim_nwk_srv_disallowed(srv_mms_bgsr_convert_mma_sim_id_to_cbm_sim_id(curr_node->sim_id),SRV_CBM_BEARER_PS | SRV_CBM_BEARER_CSD) == MMI_TRUE)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_DOWNLOAD_MMS_REQ, -1, __LINE__);
        return FALSE;
    }
    if (!srv_mode_switch_is_network_service_available())
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_DOWNLOAD_MMS_REQ, -2, __LINE__);
        return FALSE;
    }
    /* sanity check */
    if (msg == 0)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MSG_NOT_FOUND, __LINE__);
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_DOWNLOAD_MMS_REQ, 0, __LINE__);
        srv_mms_bgsr_echo_current_info();
        return FALSE;
    }
#ifdef __MMI_MMS_FALLBACK__
    if (g_srv_mms_bgsr_context.fallback_download_id != 0)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_NEED_FALLBACK, curr_node->msg_id, __LINE__);
        return FALSE;
    }
#endif /* __MMI_MMS_FALLBACK__ */ 
    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_DOWNLOAD_MMS_REQ, curr_node->msg_id, __LINE__);

    curr_node->status = SRV_MMS_BGSR_STATUS_DOWNLOADING;
    g_srv_mms_bgsr_context.download_msg_id = curr_node->msg_id;
    g_srv_mms_bgsr_context.download_sim_id = curr_node->sim_id;
    srv_mms_bgsr_show_mms_status_icon(SRV_MMS_BGSR_INDICATOR_BUSY, SRV_MMS_BGSR_INDICATOR_DOWNLOAD_OP);
    request_id = srv_mms_bgsr_get_request_id();

    msg_req =
        (wap_mma_download_req_struct*) construct_local_para(sizeof(wap_mma_download_req_struct), TD_CTRL | TD_RESET);
    msg_req->app_id = MMA_APP_ID_BGSR;
    msg_req->req_id = request_id;
    msg_req->msg_id = curr_node->msg_id;
    msg_req->sim_id = curr_node->sim_id;
    srv_mms_bgsr_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_DOWNLOAD_REQ),
        0,
        MSG_ID_WAP_MMA_DOWNLOAD_REQ,
        (oslParaType*) msg_req,
        NULL);

    (srv_mms_bgsr_callback_table[0][0].update_menu_item_callback) (curr_node->msg_id, SRV_MMS_BGSR_UPDATE_STATUS);
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_download_mms_ind_hdlr
 * DESCRIPTION
 *  Download MMS message indication handler
 * PARAMETERS
 *  in_msg      [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_mms_bgsr_download_mms_ind_hdlr(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_download_ind_struct *msg_ind = (wap_mma_download_ind_struct*) in_msg;;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* sanity check */
    if (in_msg == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MSG_NOT_FOUND, __LINE__);
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_DOWNLOAD_MMS_IND_HDLR, 0, __LINE__);
        srv_mms_bgsr_echo_current_info();
        return FALSE;
    }
    if (msg_ind->app_id == MMA_APP_ID_BGSR)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_DOWNLOAD_MMS_IND_HDLR, msg_ind->msg_id, __LINE__);

        if (g_srv_mms_bgsr_context.download_msg_id != msg_ind->msg_id)
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MSG_NOT_FOUND, __LINE__);
            srv_mms_bgsr_echo_current_info();
            return TRUE;
        }
        else
        {
            wap_mma_download_res_struct *msg_res;

            msg_res =
                (wap_mma_download_res_struct*) construct_local_para(
                                                sizeof(wap_mma_download_res_struct),
                                                TD_CTRL | TD_RESET);
            msg_res->app_id = MMA_APP_ID_BGSR;
            msg_res->result = MMA_RESULT_OK;
            msg_res->req_id = msg_ind->req_id;

            srv_mms_bgsr_send_message(
                MOD_MMI,
                mms_get_service_module(MSG_ID_WAP_MMA_DOWNLOAD_RES),
                0,
                MSG_ID_WAP_MMA_DOWNLOAD_RES,
                (oslParaType*) msg_res,
                NULL);
        }
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_download_mms_rsp
 * DESCRIPTION
 *  Download MMS msg response
 * PARAMETERS
 *  in_msg      [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_mms_bgsr_download_mms_rsp(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_download_rsp_struct *msg_rsp = (wap_mma_download_rsp_struct*) in_msg;

#ifdef __MMI_MMS_FALLBACK__
    U8 sim_id = MMA_SIM_ID_SIM1;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (in_msg == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MSG_NOT_FOUND, __LINE__);
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_DOWNLOAD_MMS_RSP, 0, __LINE__);
        srv_mms_bgsr_echo_current_info();
        return FALSE;
    }
    if (msg_rsp->app_id == MMA_APP_ID_BGSR)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_DOWNLOAD_MMS_RSP, msg_rsp->msg_id, __LINE__);

    #ifdef __MMI_MMS_FALLBACK__
        sim_id = g_srv_mms_bgsr_context.download_sim_id;
    #endif 

        srv_mms_bgsr_action_download_rsp(msg_rsp);

    #ifdef __MMI_MMS_FALLBACK__
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            SRV_MMS_BGSR_FALLBACK_MASK,
            sim_id,
            g_srv_mms_bgsr_context.fallback_mask,
            __LINE__);

        g_srv_mms_bgsr_context.fallback_mask &= ~SRV_MMS_BGSR_FALLBACK_MASK_DOWNLOADING;
        srv_mms_bgsr_send_select_rsp_handler(sim_id);
    #endif /* __MMI_MMS_FALLBACK__ */ 
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_abort_download_mms_req
 * DESCRIPTION
 *  Abort sending MMS msg request
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_abort_download_mms_req(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_cancel_download_req_struct *msg_req;
    U32 request_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_id == 0)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MSG_NOT_FOUND, __LINE__);
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_ABORT_DOWNLOAD_MMS_REQ, 0, __LINE__);
        srv_mms_bgsr_echo_current_info();
        return;
    }
    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_ABORT_DOWNLOAD_MMS_REQ, msg_id, __LINE__);

    request_id = srv_mms_bgsr_get_request_id();

    msg_req =
        (wap_mma_cancel_download_req_struct*) construct_local_para(
                                                sizeof(wap_mma_cancel_download_req_struct),
                                                TD_CTRL | TD_RESET);
    msg_req->app_id = MMA_APP_ID_BGSR;
    msg_req->req_id = request_id;
    msg_req->msg_id = msg_id;

    srv_mms_bgsr_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_CANCEL_DOWNLOAD_REQ),
        0,
        MSG_ID_WAP_MMA_CANCEL_DOWNLOAD_REQ,
        (oslParaType*) msg_req,
        NULL);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_abort_download_mms_rsp
 * DESCRIPTION
 *  Abort MMS msg response
 * PARAMETERS
 *  in_msg      [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_mms_bgsr_abort_download_mms_rsp(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_rsp_struct *msg_rsp = (wap_mma_rsp_struct*) in_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (in_msg == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MSG_NOT_FOUND, __LINE__);
        srv_mms_bgsr_echo_current_info();
        return FALSE;
    }
    if (msg_rsp->app_id == MMA_APP_ID_BGSR)
    {
        srv_mms_bgsr_action_cancel_download_rsp(msg_rsp);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_msg_is_valid_rsp
 * DESCRIPTION
 *  Sync MMS msg response
 * PARAMETERS
 *  in_msg      [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_mms_bgsr_msg_is_valid_rsp(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_msg_is_valid_rsp_struct *msg_rsp = (wap_mma_msg_is_valid_rsp_struct*) in_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (in_msg == NULL)
    {
        return FALSE;
    }
    if (msg_rsp->app_id == MMA_APP_ID_BGSR)
    {
        srv_mms_bgsr_action_sync_rsp(msg_rsp);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_set_fail_cause
 * DESCRIPTION
 *  To ge the fail cuse of a request
 * PARAMETERS
 *  rsp                 [?]         
 *  message_type        [IN]        
 *  in_msg(?)           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 *srv_mms_bgsr_set_fail_cause(void *rsp, srv_mms_bgsr_message_type_enum message_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *fail_cause = NULL;
    wap_mma_send_rsp_struct *send_rsp;
    wap_mma_download_rsp_struct *dl_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (message_type)
    {
        case SRV_MMS_BGSR_MESSAGE_TYPE_SEND:
        {
            send_rsp = (wap_mma_send_rsp_struct*) rsp;
            if (send_rsp->result != MMA_RESULT_OK && mmi_ucs2strlen((S8*) (send_rsp->response_text)))
            {
                U32 str_len = mmi_ucs2strlen((S8*) (send_rsp->response_text));

                fail_cause = kal_adm_alloc(g_srv_mms_bgsr_context.mem_pool_id, (str_len + 1) * ENCODING_LENGTH);
                if (fail_cause != NULL)
                {
                    memset(fail_cause, 0, (str_len + 1) * ENCODING_LENGTH);
                    mmi_ucs2ncpy((S8*) fail_cause, (S8*) (send_rsp->response_text), str_len);
                }
                else
                {
                    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MEMORY_NOT_ALLOCATED, __LINE__);
                }
            }
            return fail_cause;
        }
        case SRV_MMS_BGSR_MESSAGE_TYPE_DOWNLOAD:
        {
            dl_rsp = (wap_mma_download_rsp_struct*) rsp;
            if (dl_rsp->result != MMA_RESULT_OK && mmi_ucs2strlen((S8*) (dl_rsp->response_text)))
            {
                U32 str_len = mmi_ucs2strlen((S8*) (dl_rsp->response_text));

                fail_cause = kal_adm_alloc(g_srv_mms_bgsr_context.mem_pool_id, (str_len + 1) * ENCODING_LENGTH);
                if (fail_cause != NULL)
                {
                    memset(fail_cause, 0, (str_len + 1) * ENCODING_LENGTH);
                    mmi_ucs2ncpy((S8*) fail_cause, (S8*) (dl_rsp->response_text), str_len);
                }
                else
                {
                    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MEMORY_NOT_ALLOCATED, __LINE__);
                }
            }
            return fail_cause;
        }
        default:
        {
            return NULL;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_delete_folder_ind_hdlr
 * DESCRIPTION
 *  (void *in_msg)
 *  Sync MMS msg response
 * PARAMETERS
 *  in_msg      [IN]        
 *  mod_src     [IN]        
 *  ilm_p       [?]         
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_mms_bgsr_delete_folder_ind_hdlr(void *in_msg, int mod_src, void *ilm_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_notify_event_ind_struct *notify_event_ind;
    kal_uint16 length;
    wap_mma_event_delete_folder_struct *data;
    U8 this_msg = 0;
    U8 next_msg = 0;
    srv_mms_bgsr_msg_struct *curr_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (in_msg == NULL)
    {
        return FALSE;
    }
#ifdef __DM_LAWMO_SUPPORT__
    if (g_srv_mms_bgsr_context.lawmo_scomo_flag)
    {
        return TRUE;
    }
#endif /* __DM_LAWMO_SUPPORT__ */ /* __DM_MO_SUPPORT__ */
    notify_event_ind = (wap_mma_notify_event_ind_struct*) in_msg;
    if (notify_event_ind->event_id == MMA_EVENT_DELETE_FOLDER && notify_event_ind->app_id == MMA_APP_ID_BGSR)
    {
        data = (wap_mma_event_delete_folder_struct*) get_peer_buff_pdu(((ilm_struct*) ilm_p)->peer_buff_ptr, &length);
        if (data->folder == MMA_FOLDER_INBOX)
        {
            srv_mms_bgsr_change_msg_notify(
                0,
                SRV_MMS_BGSR_OP_DELETE_ALL_INBOX,
                SRV_MMS_BGSR_FOLDER_INBOX,
                NULL,
                MMA_MSG_STORAGE_NONE);
        }
        else if (data->folder == MMA_FOLDER_OUTBOX)
        {

            this_msg = g_srv_mms_bgsr_context.srv_mms_bgsr_send_q;
            while (this_msg != 0 && (curr_node = srv_mms_bgsr_get_msg_array(this_msg))->msg_id != 0)
            {
                /* do nothing if the message is in sending or it's a read report */
                if ((curr_node->msg_info & SRV_MMS_BGSR_IS_RR_INFO)
                    || curr_node->msg_id == g_srv_mms_bgsr_context.send_msg_id)
                {
                    this_msg = *(srv_mms_bgsr_get_next_array(this_msg));
                    continue;
                }

                /* remove the message if it's a message and it's not in sending */
                next_msg = *(srv_mms_bgsr_get_next_array(this_msg));
                this_msg = srv_mms_bgsr_extract_q(curr_node->msg_id, &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_q));

                curr_node->msg_id = 0;
                *(srv_mms_bgsr_get_next_array(this_msg)) = 0;
            #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
                if (this_msg & SRV_MMS_BGSR_MEM_CARD_BIT)
                {
                    srv_mms_bgsr_enqueue(this_msg, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_mem_q));
                }
                else
            #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ /* #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
                    srv_mms_bgsr_enqueue(this_msg, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_q));
                this_msg = next_msg;
            }

            this_msg = g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q;
            while (this_msg != 0 && (curr_node = srv_mms_bgsr_get_msg_array(this_msg))->msg_id != 0)
            {
                /* remove the message if it's a message */
                next_msg = *(srv_mms_bgsr_get_next_array(this_msg));
                this_msg = srv_mms_bgsr_extract_q(curr_node->msg_id, &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q));
                curr_node->msg_id = 0;
                *(srv_mms_bgsr_get_next_array(this_msg)) = 0;
            #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
                if (this_msg & SRV_MMS_BGSR_MEM_CARD_BIT)
                {
                    srv_mms_bgsr_enqueue(this_msg, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_mem_q));
                }
                else
            #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ /* #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
                    srv_mms_bgsr_enqueue(this_msg, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_q));
                this_msg = next_msg;

            }

        #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
            if (g_srv_mms_bgsr_context.mem_card_state == SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_IN)
            {
                srv_mms_bgsr_write_into_mem_card_file();
            }
        #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
            srv_mms_bgsr_write_into_ph_mem_file();
        }
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_send_message
 * DESCRIPTION
 *  Common function for sending message
 * PARAMETERS
 *  MOD_SRC         [IN]        Source module
 *  MOD_DEST        [IN]        Destination module
 *  MSG_SAP         [IN]        Message SAP
 *  MSG_ID          [IN]        Message ID
 *  LOCAL           [IN]        Local parameter
 *  PEER            [IN]        Peer buffer
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_send_message(
        module_type MOD_SRC,
        module_type MOD_DEST,
        U8 MSG_SAP,
        const U16 MSG_ID,
        void *LOCAL,
        void *PEER)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_send_ilm(MOD_DEST, (msg_type) MSG_ID, (oslParaType*) LOCAL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_get_request_id
 * DESCRIPTION
 *  Get non-zero request id for issuing a request.
 * PARAMETERS
 *  void
 *  result(?)       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 srv_mms_bgsr_get_request_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mma_get_request_id();
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_mma_ready_ind_hdlr
 * DESCRIPTION
 *  Handles the MMA Ready indication
 * PARAMETERS
 *  in_msg      [?]     
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_mms_bgsr_mma_ready_ind_hdlr(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_mms_bgsr_context.mma_ready_flag = TRUE;
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    srv_mms_bgsr_init_mem_card_state_hdlr();
    g_srv_mms_bgsr_context.send_receive_flag = 0;
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_mma_terminate_ind_hdlr
 * DESCRIPTION
 *  Handles the MMA Terminate indication
 * PARAMETERS
 *  in_msg      [?]     
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_mms_bgsr_mma_terminate_ind_hdlr(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 local_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_mms_bgsr_context.send_msg_id != 0)
    {
        srv_mms_bgsr_show_mms_status_icon(SRV_MMS_BGSR_INDICATOR_IDLE, SRV_MMS_BGSR_INDICATOR_SEND_OP);
        g_srv_mms_bgsr_context.send_sim_id = 0;
        local_msg = srv_mms_bgsr_get_q(g_srv_mms_bgsr_context.send_msg_id, g_srv_mms_bgsr_context.srv_mms_bgsr_send_q);
        (srv_mms_bgsr_get_msg_array(local_msg))->status = SRV_MMS_BGSR_STATUS_WAITING_FOR_SEND;
        (srv_mms_bgsr_callback_table[0][0].update_menu_item_callback)
            (g_srv_mms_bgsr_context.send_msg_id, SRV_MMS_BGSR_UPDATE_STATUS);
        g_srv_mms_bgsr_context.send_msg_id = 0;
        g_srv_mms_bgsr_context.cancel_send_msg_id = 0;
    }
    if (g_srv_mms_bgsr_context.download_msg_id != 0)
    {
        srv_mms_bgsr_show_mms_status_icon(SRV_MMS_BGSR_INDICATOR_IDLE, SRV_MMS_BGSR_INDICATOR_DOWNLOAD_OP);
        g_srv_mms_bgsr_context.download_sim_id = 0;
        local_msg = srv_mms_bgsr_get_q(
                        g_srv_mms_bgsr_context.download_msg_id,
                        g_srv_mms_bgsr_context.srv_mms_bgsr_download_q);
        (srv_mms_bgsr_get_msg_array(local_msg))->status = SRV_MMS_BGSR_STATUS_WAITING_FOR_DOWNLOAD;
        (srv_mms_bgsr_callback_table[0][0].update_menu_item_callback)
            (g_srv_mms_bgsr_context.download_msg_id, SRV_MMS_BGSR_UPDATE_STATUS);
        g_srv_mms_bgsr_context.download_msg_id = 0;
        g_srv_mms_bgsr_context.cancel_download_msg_id = 0;
    }
#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
    if (g_srv_mms_bgsr_context.vendor_send_msg_id != 0)
    {
        srv_mms_vendor_send_rsp_callback(g_srv_mms_bgsr_context.vendor_send_msg_id, SRV_MMS_BGSR_RESULT_FAIL_NOT_READY);
        g_srv_mms_bgsr_context.vendor_send_msg_id = 0;
    }
#endif /* __MMI_MMS_VENDOR_APP_SUPPORT__ */ 
#ifdef __MMI_UMMS_JSR205__
    if (g_srv_mms_bgsr_context.java_send_msg_id != 0)
    {
        srv_mms_bgsr_delete_mms_req(g_srv_mms_bgsr_context.java_send_msg_id);
        srv_mms_jsr_update_send_msg_icon(g_srv_mms_bgsr_context.java_send_msg_id, SRV_MMS_BGSR_STATUS_SEND_FAIL);
        srv_mms_jsr_send_msg_rsp((U16) g_srv_mms_bgsr_context.java_send_msg_id, SRV_MMS_BGSR_RESULT_FAIL_NOT_READY);
        g_srv_mms_bgsr_context.java_send_msg_id = 0;
    }
#endif /* __MMI_UMMS_JSR205__ */ 
    g_srv_mms_bgsr_context.mma_ready_flag = FALSE;
    return FALSE;
}

#ifdef __MMI_MMS_FALLBACK__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_suspend_mms_service_req
 * DESCRIPTION
 *  Send SUSPEND_MMS_SERVICE_REQ to MMA
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_suspend_mms_service_req()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_suspend_mms_service_req_struct *msg_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_SUSPEND_MMS_SERVICE_REQ, __LINE__);

    msg_req =
        (wap_mma_suspend_mms_service_req_struct*) construct_local_para(
                                                    sizeof(wap_mma_suspend_mms_service_req_struct),
                                                    TD_CTRL | TD_RESET);
    msg_req->app_id = MMA_APP_ID_BGSR;
    msg_req->req_id = srv_mms_bgsr_get_request_id();
    srv_mms_bgsr_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_SUSPEND_MMS_SERVICE_REQ),
        0,
        MSG_ID_WAP_MMA_SUSPEND_MMS_SERVICE_REQ,
        (oslParaType*) msg_req,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_suspend_mms_service_rsp
 * DESCRIPTION
 *  Received SUSPEND_MMS_SERVICE_RSP from MMA
 * PARAMETERS
 *  in_msg      [?]     
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_mms_bgsr_suspend_mms_service_rsp(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_suspend_mms_service_rsp_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (wap_mma_suspend_mms_service_rsp_struct*) in_msg;
    if (msg->app_id == MMA_APP_ID_BGSR)
    {
        if (msg->result != MMA_RESULT_OK)
        {
            MMI_ASSERT(0);
        }
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_SUSPEND_MMS_SERVICE_RSP, __LINE__);
        if (g_srv_mms_bgsr_context.fallback_mask == SRV_MMS_BGSR_FALLBACK_MASK_NEED_FALLBACK
            && g_srv_mms_bgsr_context.fallback_sim_id == 0)
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_RESUME_MMS_SERVICE_REQ, __LINE__);
            srv_mms_bgsr_resume_mms_service_req();
        }
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_resume_mms_service_req
 * DESCRIPTION
 *  Send RESUME_MMS_SERVICE_REQ to MMA
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_resume_mms_service_req()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_resume_mms_service_req_struct *msg_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_RESUME_MMS_SERVICE_REQ, __LINE__);

    msg_req =
        (wap_mma_resume_mms_service_req_struct*) construct_local_para(
                                                    sizeof(wap_mma_resume_mms_service_req_struct),
                                                    TD_CTRL | TD_RESET);
    msg_req->app_id = MMA_APP_ID_BGSR;
    msg_req->req_id = srv_mms_bgsr_get_request_id();
    srv_mms_bgsr_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_RESUME_MMS_SERVICE_REQ),
        0,
        MSG_ID_WAP_MMA_RESUME_MMS_SERVICE_REQ,
        (oslParaType*) msg_req,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_resume_mms_service_rsp
 * DESCRIPTION
 *  Received RESUME_MMS_SERVICE_RSP from MMA
 * PARAMETERS
 *  in_msg      [?]     
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_mms_bgsr_resume_mms_service_rsp(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_resume_mms_service_rsp_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (wap_mma_resume_mms_service_rsp_struct*) in_msg;
    if (msg->app_id == MMA_APP_ID_BGSR)
    {
        if (msg->result != MMA_RESULT_OK)
        {
            MMI_ASSERT(0);
        }
        else
        {
            /* disconnect the current used bearer and create a new connection */
            MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_RESUME_MMS_SERVICE_RSP, __LINE__);

            g_srv_mms_bgsr_context.fallback_mask &= ~SRV_MMS_BGSR_FALLBACK_MASK_NEED_FALLBACK;

            if (g_srv_mms_bgsr_context.fallback_send_id != 0)
            {
                U8 message = srv_mms_bgsr_extract_q(
                                g_srv_mms_bgsr_context.fallback_send_id,
                                &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q));

                if (message == 0)
                {
                    message = srv_mms_bgsr_extract_q(
                                g_srv_mms_bgsr_context.fallback_send_id,
                                &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_q));
                    if (message == 0)
                    {
                    #ifdef __MMI_UMMS_JSR205__
                        if (g_srv_mms_bgsr_context.fallback_send_id == g_srv_mms_bgsr_context.java_send_msg_id)
                        {
                            g_srv_mms_bgsr_context.fallback_send_id = 0;
                            srv_mms_bgsr_send_java_msg_req(
                                g_srv_mms_bgsr_context.java_send_msg_id,
                                g_srv_mms_bgsr_context.java_sim_id);
                            return TRUE;
                        }
                    #endif /* __MMI_UMMS_JSR205__ */ 
                    #ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
                        if (g_srv_mms_bgsr_context.fallback_send_id == g_srv_mms_bgsr_context.vendor_send_msg_id)
                        {
                            g_srv_mms_bgsr_context.fallback_send_id = 0;
                            srv_mms_bgsr_vendor_send_msg_req(
                                g_srv_mms_bgsr_context.vendor_send_msg_id,
                                g_srv_mms_bgsr_context.vendor_sim_id);
                            return TRUE;
                        }
                    #endif /* __MMI_MMS_VENDOR_APP_SUPPORT__ */ 
                        MMI_ASSERT(0);
                    }
                }

                if (g_srv_mms_bgsr_context.fallback_send_id == srv_mms_bgsr_get_msg_array(message)->msg_id)
                {
                    g_srv_mms_bgsr_context.fallback_send_id = 0;
                    srv_mms_bgsr_enqueue(message, &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_q));
                    srv_mms_bgsr_send_mms_req(message);
                }
                else
                {
                    srv_mms_bgsr_enqueue(message, &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q));
                }
            }
            if (g_srv_mms_bgsr_context.fallback_download_id != 0)
            {
                U8 message = srv_mms_bgsr_extract_q(
                                g_srv_mms_bgsr_context.fallback_download_id,
                                &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q));

                if (message == 0)
                {
                    message = srv_mms_bgsr_extract_q(
                                g_srv_mms_bgsr_context.fallback_download_id,
                                &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_q));
                    if (message == 0)
                        MMI_ASSERT(0);
                }
                if (g_srv_mms_bgsr_context.fallback_download_id == srv_mms_bgsr_get_msg_array(message)->msg_id)
                {
                    g_srv_mms_bgsr_context.fallback_download_id = 0;
                    srv_mms_bgsr_enqueue(message, &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_q));
                    srv_mms_bgsr_download_mms_req(message);
                }
                else
                {
                    srv_mms_bgsr_enqueue(message, &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q));
                }
            }
        }
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_set_profile_req
 * DESCRIPTION
 *  Seed MSG_ID_WAP_MMA_SET_PROFILE_REQ to MMA
 * PARAMETERS
 *  profile_struct      [?]         
 *  mma_sim_id          [IN]        
 *  srv_wap_prof_profile_content_struct(?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_set_profile_req(srv_wap_prof_profile_content_struct *profile_struct, U8 mma_sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_set_profile_req_struct *msg_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_req =
        (wap_mma_set_profile_req_struct*) construct_local_para(
                                            sizeof(wap_mma_set_profile_req_struct),
                                            TD_CTRL | TD_RESET);
    msg_req->app_id = MMA_APP_ID_BGSR;
    msg_req->req_id = srv_mms_bgsr_get_request_id();
    msg_req->proxy_port = profile_struct->proxy_port;
    msg_req->sim_id = mma_sim_id;

    switch (profile_struct->conn_type)
    {
        case SRV_WAP_PROF_CONN_TYPE_HTTP:
        {
            msg_req->connection_type = MMA_CONN_TYPE_HTTP_PROXY;
            break;
        }
        case SRV_WAP_PROF_CONN_TYPE_CONNECTION_OREINTED:
        {
            /* if(9200) MMA_CONN_TYPE_WSP_CL; else if(9201) */
            msg_req->connection_type = MMA_CONN_TYPE_WSP_CO;
            break;
        }
        case SRV_WAP_PROF_CONN_TYPE_CONNECTION_OREINTED_SECURE:
        {
            /* if(9202) MMA_CONN_TYPE_WSP_SEC_CL: else if(9203) */
            msg_req->connection_type = MMA_CONN_TYPE_WSP_SEC_CO;
            break;
        }

    }
/*Assuming srv_wap_prof_profile_content_struct will have the proxy URL in the ascii format
otherwise here need to convert that into ascii first then copy because structure wap_mma_set_profile_req_struct will keep the URL string in ascii*/

    strcpy(msg_req->proxy_addr, profile_struct->proxy_ip);

    mmi_asc_to_ucs2((S8*) msg_req->homepage_url, (S8*) profile_struct->url);
    mmi_asc_to_ucs2((S8*) msg_req->username, (S8*) profile_struct->username);
    mmi_asc_to_ucs2((S8*) msg_req->password, (S8*) profile_struct->password);

    msg_req->data_account = profile_struct->data_account_primary_id;
    srv_mms_bgsr_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_SET_PROFILE_REQ),
        0,
        MSG_ID_WAP_MMA_SET_PROFILE_REQ,
        (oslParaType*) msg_req,
        NULL);
}
#endif /* __MMI_MMS_FALLBACK__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_start_immd_retr_ind
 * DESCRIPTION
 *  Received START_IMMD_RETR_IND from MMA
 * PARAMETERS
 *  in_msg      [?]     
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_mms_bgsr_start_immd_retr_ind(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_start_immed_retrieval_ind_struct *ind = (wap_mma_start_immed_retrieval_ind_struct*) in_msg;
    U8 sim_id = ind->sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_START_IMM_RETR_IND, ind->msg_id, sim_id, __LINE__);
    g_srv_mms_bgsr_context.immd_retr_sim_id = sim_id;
    srv_mms_bgsr_show_mms_status_icon(SRV_MMS_BGSR_INDICATOR_BUSY, SRV_MMS_BGSR_INDICATOR_IMMD_DOWNLOAD_OP);
    return FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_stop_immd_retr_ind
 * DESCRIPTION
 *  Received STOP_IMMD_RETR_IND from MMA
 * PARAMETERS
 *  in_msg      [?]     
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_mms_bgsr_stop_immd_retr_ind(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_stop_immed_retrieval_ind_struct *ind = (wap_mma_stop_immed_retrieval_ind_struct*) in_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        SRV_MMS_BGSR_STOP_IMM_RETR_IND,
        ind->msg_id,
        ind->sim_id,
        ind->result,
        ind->error_cause,
        __LINE__);

    srv_mms_bgsr_show_mms_status_icon(SRV_MMS_BGSR_INDICATOR_IDLE, SRV_MMS_BGSR_INDICATOR_IMMD_DOWNLOAD_OP);
    g_srv_mms_bgsr_context.immd_retr_sim_id = 0;
#ifdef __MMI_MMS_AUTO_DWNLD_IMMED_NOTI_AFTER_INTERRUPT__
#ifdef __MMI_MMS_FALLBACK__
    g_srv_mms_bgsr_context.fallback_mask &= ~SRV_MMS_BGSR_FALLBACK_MASK_IMME_RETR;
    srv_mms_bgsr_send_select_rsp_handler(ind->sim_id);
#endif /* __MMI_MMS_FALLBACK__ */ 
#endif /* __MMI_MMS_AUTO_DWNLD_IMMED_NOTI_AFTER_INTERRUPT__ */ 
    return FALSE;
}

#endif /* __MMI_MMS_BGSR_SUPPORT__ */ 

