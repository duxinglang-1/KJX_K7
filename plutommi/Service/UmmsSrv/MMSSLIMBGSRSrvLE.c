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
 *  MMSBGSRSrvMain.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contans the Event Handlers and Main flow of the MMS BGSR Application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_MMS_BGSR_SUPPORT__) && defined(__MMI_MMS_LOW_TIER_BGSR_SUPPORT__)
#include "CommonScreens.h"
#include "time.h"
#if defined(__MMI_USB_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__)
#include "USBSrvGProt.h"
#endif /*__MMI_USB_SUPPORT__ && __USB_IN_NORMAL_MODE__*/
#include "MMSAppCommonGprot.h"
#include "MmsSrvGprot.h"
#include "MmsSrvProt.h"
#include "kal_general_types.h"
#include "MMI_inet_app_trc.h"
#include "SimCtrlSrvGprot.h"    /*required for sim_is_blocked*/
#include "GlobalResDef.h"

#include "MMS_sap_struct.h"
#include "MMA_api.h"
#include "Mms_adp.h"
#include "MMSMemoryManagerSrv.h"

/* TRACE */

	//******chhota bgsr start***************
S32 g_sending_msg_id = 0;
S32 g_downloading_msg_id = 0;
S32 g_sending_sim_id = 0;
S32 g_downloading_sim_id = 0;
S32 g_immd_retr_sim_id = 0;
U8 g_is_read_report = 0;
typedef enum
{
    SRV_MMS_BGSR_INDICATOR_BUSY,
    SRV_MMS_BGSR_INDICATOR_IDLE,
    SRV_MMS_BGSR_INDICATOR_TOTAL_NUM
} srv_mms_bgsr_indicator_type_enum;

typedef enum
{
    SRV_MMS_BGSR_INDICATOR_NONE_OP,
    SRV_MMS_BGSR_INDICATOR_SEND_OP,
    SRV_MMS_BGSR_INDICATOR_DOWNLOAD_OP,
    SRV_MMS_BGSR_INDICATOR_IMMD_DOWNLOAD_OP,
    SRV_MMS_BGSR_INDICATOR_TOTAL_OP_NUM
} srv_mms_bgsr_indicator_op_enum;

typedef struct	__srv_mms_slim_bgsr_struct
{
	U32 msg_id;
	U32 sim_id;
	U8 is_read_report;
	struct __srv_mms_slim_bgsr_struct *next;
}srv_mms_slim_bgsr_struct;



srv_mms_slim_bgsr_struct *g_slim_bgsr_send_queue;
srv_mms_slim_bgsr_struct *g_slim_bgsr_download_queue;
srv_mms_slim_bgsr_struct *g_slim_bgsr_cancel_queue;

extern U32 srv_mms_check_next_msg(srv_mms_slim_bgsr_struct **queue, U8 (*srv_mms_slim_bgsr_req)(kal_uint8 sim_id, U32 msg_id, U8 storage_type,BOOL un_used), U32 msg_id);
extern U8 srv_mms_slim_bgsr_locate_msg_id(U32 msg_id, srv_mms_slim_bgsr_struct *queue);
extern srv_mms_slim_bgsr_struct* srv_mms_slim_bgsr_get_node_by_msgid(U32 msg_id, srv_mms_slim_bgsr_struct *queue);
extern U32 srv_mms_bgsr_get_msg_status(U32 msg_id);
extern U32 srv_mms_bgsr_update_msg_status_info(U32 msg_id, U8* ntt, kal_uint8* quota);
extern void srv_mms_bgsr_show_mms_status_icon(const srv_mms_bgsr_indicator_type_enum status,
                                       srv_mms_bgsr_indicator_op_enum op_type);

	/*  sending */
extern U8 srv_mms_slim_bgsr_send_mms_req( U8 sim_id, U32 msg_id, U8 storage_id, BOOL is_read_report);
extern  U8 srv_mms_slim_bgsr_send_mms( U8 sim_id, U32 msg_id, U8 storage_id,BOOL is_read_report);
extern U8 srv_mms_slim_bgsr_send_mms_ind_hdlr(void *in_msg);
extern U8 srv_mms_slim_bgsr_send_mms_rsp(void *in_msg);
extern U8 srv_mms_bgsr_save_mms_rsp(void *in_msg);
extern U32 srv_mms_slim_bgsr_get_msg_status(U32 msg_id);

   /* downloading */
extern U8 srv_mms_slim_bgsr_download_req(kal_uint8 sim_id, U32 msg_id, U8 storage_type,BOOL un_used);
extern U8 srv_mms_slim_bgsr_download_mms(kal_uint8 sim_id, U32 msg_id, U8 storage_type,BOOL un_used);
extern U8 srv_mms_slim_bgsr_download_mms_ind_hdlr(void *in_msg);
extern U8 srv_mms_slim_bgsr_download_mms_rsp(void *in_msg);
extern U8 srv_mms_slim_bgsr_stop_immd_retr_ind(void *in_msg);
extern U8 srv_mms_slim_bgsr_start_immd_retr_ind(void *in_msg);
extern U8 srv_mms_bgsr_abort_download_mms_rsp(void *in_msg);
extern U8 srv_mms_bgsr_abort_send_mms_rsp(void *in_msg);

//******************queue********
extern void srv_mms_free_slim_bgsr_queue_slot(srv_mms_slim_bgsr_struct *slot, srv_mms_slim_bgsr_struct **queue);
extern srv_mms_slim_bgsr_struct *srv_mms_get_slim_bgsr_queue_slot(srv_mms_slim_bgsr_struct ** queue);
extern BOOL srv_mms_slim_bgsr_pre_check(srv_mms_slim_bgsr_struct **queue, U32 msg_id, U32 sim_id, U8 is_read_report);

static srv_mms_bgsr_result_enum srv_mms_bgsr_translate_result(mma_result_enum mma_result);

void srv_mms_slim_bgsr_init(void)
{
	mmi_frm_set_protocol_event_handler(MSG_ID_WAP_MMA_SEND_IND,  (PsIntFuncPtr) srv_mms_slim_bgsr_send_mms_ind_hdlr, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WAP_MMA_SEND_RSP,  (PsIntFuncPtr) srv_mms_slim_bgsr_send_mms_rsp, MMI_TRUE);
	mmi_frm_set_protocol_event_handler(MSG_ID_WAP_MMA_DOWNLOAD_RSP,  (PsIntFuncPtr) srv_mms_slim_bgsr_download_mms_rsp, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WAP_MMA_DOWNLOAD_IND,  (PsIntFuncPtr) srv_mms_slim_bgsr_download_mms_ind_hdlr, MMI_TRUE);
	 mmi_frm_set_protocol_event_handler(MSG_ID_WAP_MMA_START_IMMED_RETRIEVAL_IND,  (PsIntFuncPtr) srv_mms_slim_bgsr_start_immd_retr_ind, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WAP_MMA_STOP_IMMED_RETRIEVAL_IND,  (PsIntFuncPtr) srv_mms_slim_bgsr_stop_immd_retr_ind, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WAP_MMA_SAVE_RSP, (PsIntFuncPtr) srv_mms_bgsr_save_mms_rsp, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WAP_MMA_CANCEL_DOWNLOAD_RSP, (PsIntFuncPtr) srv_mms_bgsr_abort_download_mms_rsp, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WAP_MMA_CANCEL_SEND_RSP, (PsIntFuncPtr) srv_mms_bgsr_abort_send_mms_rsp, MMI_TRUE);
   
}

BOOL srv_mms_slim_bgsr_pre_check(srv_mms_slim_bgsr_struct **queue, U32 msg_id, U32 sim_id, U8 is_read_report)
{
	srv_mms_slim_bgsr_struct *slot = NULL;
#if 0
/* under construction !*/
#if defined(__MMI_USB_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__)
/* under construction !*/
/* under construction !*/
#endif  /*__MMI_USB_SUPPORT__ && __USB_IN_NORMAL_MODE__*/
#ifndef __UMTS_RAT__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_FIND_Q);
	slot = srv_mms_get_slim_bgsr_queue_slot(queue);
	if(slot)
	{
	slot->msg_id = msg_id;
	slot->sim_id = sim_id;
    slot->is_read_report = is_read_report;

	return TRUE;
		
	}

	return FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_is_any_waiting_msg
 * DESCRIPTION
 *  Tells only if there is any msg in waiting state or not
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  Bool
 *****************************************************************************/
MMI_BOOL srv_mms_bgsr_is_any_waiting_msg(void)
{
    if(g_slim_bgsr_send_queue || g_slim_bgsr_download_queue)
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
 *  srv_mms_bgsr_waiting_msg_count
 * DESCRIPTION
 *  It gives the total count of Waiting/Postpone messages
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  Bool
 *****************************************************************************/
U16 srv_mms_bgsr_waiting_msg_count(void)
{
    if(srv_mms_bgsr_is_any_waiting_msg())
        return 1;
    else
        return 0;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_set_rr_flag
 * DESCRIPTION
 *  (U32 msg_id)
 *  handle the send request for a read report,
 * CALLS
 *  
 * PARAMETERS
 *  msg_id      [IN]        Message id
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_set_rr_flag(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
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
        return;
    }
    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_SAVE_MMS_REQ, msg_id, __LINE__);

    request_id = mma_get_request_id();

    msg_req = (wap_mma_save_req_struct*) construct_local_para(sizeof(wap_mma_save_req_struct), TD_CTRL | TD_RESET);
    msg_req->app_id = MMA_APP_ID_BGSR;
    msg_req->req_id = request_id;
    msg_req->msg_id[0] = msg_id;
    msg_req->no_of_msg = 1;
    msg_req->box = folder;

    srv_mms_send_message(
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
 *  srv_mms_send_mms_req
 * DESCRIPTION
 *  Send MMS msg request
 * PARAMETERS
 *  msg     [IN]    the message to send
 * RETURNS
 *  BOOL
 *****************************************************************************/
U8 srv_mms_slim_bgsr_send_mms_req( U8 sim_id, U32 msg_id, U8 storage_id, BOOL is_read_report)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(srv_mms_slim_bgsr_get_msg_status(msg_id) == SRV_MMS_BGSR_STATUS_NONE)
    {
        if(is_read_report)
        {
            if(g_sending_msg_id == 0)
	        {
                srv_mms_slim_bgsr_send_mms(sim_id, msg_id, storage_id, is_read_report);
	        }
            else
            {
                MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_ENQUEUE);
                if(!srv_mms_slim_bgsr_pre_check(&g_slim_bgsr_send_queue, msg_id, sim_id, is_read_report))
                {
                    return FALSE;
                }
            }
        }
        else
        {
	    srv_mms_bgsr_save_mms_req(msg_id, MMA_FOLDER_OUTBOX);
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_ENQUEUE);
            if(!srv_mms_slim_bgsr_pre_check(&g_slim_bgsr_send_queue, msg_id, sim_id, is_read_report))
        {
            return FALSE;
        }
    }
    }
     return FALSE;

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
    srv_mms_update_folder_callback();
    if (in_msg == NULL)
    {
        return FALSE;
    }
    if (msg_rsp->app_id == MMA_APP_ID_BGSR)
    {
            if(g_sending_msg_id == 0)
	        {
                 MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_EXTRACT_Q);
		       
			            g_sending_msg_id = srv_mms_check_next_msg(&g_slim_bgsr_send_queue, srv_mms_slim_bgsr_send_mms, msg_rsp->msg_id[0]);
	        }else
            {
                return FALSE;
            }

	        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

U8 srv_mms_slim_bgsr_send_mms( U8 sim_id, U32 msg_id, U8 storage_id, BOOL is_read_report)
{
   wap_mma_send_req_struct *msg_req;
    msg_req = (wap_mma_send_req_struct*) construct_local_para(
                            sizeof(wap_mma_send_req_struct), TD_CTRL | TD_RESET);
    msg_req->app_id = 0;
    msg_req->req_id = mma_get_request_id();
    msg_req->msg_id = msg_id;
    msg_req->sim_id = sim_id;
    if(is_read_report)
    {
        msg_req->is_read_report =  KAL_TRUE;
    }
    else
    {
        msg_req->is_read_report =  KAL_FALSE;
    }

	g_sending_msg_id = msg_id;
    g_is_read_report = is_read_report;

    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_SEND_MMS_REQ, msg_id, __LINE__);

	srv_mms_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_SEND_REQ),
        0,
        MSG_ID_WAP_MMA_SEND_REQ,
        (oslParaType*) msg_req,
        NULL);
	g_sending_sim_id = sim_id;
	srv_mms_bgsr_show_mms_status_icon(SRV_MMS_BGSR_INDICATOR_BUSY, SRV_MMS_BGSR_INDICATOR_SEND_OP); 

	return TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mms_slim_bgsr_send_mms_ind_hdlr
 * DESCRIPTION
 *  Send MMS message indication handler
 * PARAMETERS
 *  in_msg       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_mms_slim_bgsr_send_mms_ind_hdlr(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

        return 1;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mms_slim_bgsr_send_mms_rsp
 * DESCRIPTION
 *  Send MMS msg response
 * PARAMETERS
 *  in_msg       [IN]
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_mms_slim_bgsr_send_mms_rsp(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_send_rsp_struct *msg_rsp = (wap_mma_send_rsp_struct*) in_msg;
	U16 *text = NULL;
	U32 msg_id;
	U8 result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_SEND_MMS_RSP, msg_rsp->msg_id, __LINE__);

	g_sending_msg_id = 0;
	g_sending_sim_id = 0;
    
	if(msg_rsp->result != 0)
	{
		text = (U16*)GetString(STR_GLOBAL_NOT_AVAILABLE);
	}
	else
	{
        if(!g_is_read_report)
        {
		if(srv_mms_sending_settings_send_and_save())
		{		
			srv_mms_save_msg(msg_rsp->msg_id, MMA_FOLDER_SENT, &result);
		}
		else
		{
			srv_mms_delete_msg(msg_rsp->msg_id, &result);
		}
        }
        else
        {
            g_is_read_report = 0;
        }
		

		text = (U16*)GetString(STR_GLOBAL_SEND_MESSAGE);
	}
	srv_mms_send_rsp(msg_rsp->msg_id,  SRV_MMS_BGSR_RESULT_OK, text, 0, 0); 
	srv_mms_update_menu_callback(msg_rsp->msg_id, SRV_MMS_BGSR_UPDATE_STATUS);
	 srv_mms_bgsr_show_mms_status_icon(SRV_MMS_BGSR_INDICATOR_IDLE, SRV_MMS_BGSR_INDICATOR_SEND_OP);


	/* send next message  */
	 msg_id = srv_mms_check_next_msg(&g_slim_bgsr_send_queue, srv_mms_slim_bgsr_send_mms, msg_rsp->msg_id);
	if(msg_id)
	{
			g_sending_msg_id = msg_id;	/*srv_mms_slim_bgsr_req(sim_id, msgId, 0,is_read_report);  */
	}
        return TRUE;
}
/*****************************************************************************
 * FUNCTION
 *  srv_mms_slim_bgsr_get_msg_status
 * DESCRIPTION
 *  get the message status
 * CALLS
 *  
 * PARAMETERS
 *  msg_id                  [IN]    the message id
 * RETURNS
 *  U32
 *****************************************************************************/
U32 srv_mms_slim_bgsr_get_msg_status(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	if(msg_id == g_sending_msg_id)
	{
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_ALREADY_A_SENDING_MSG, g_sending_msg_id, __LINE__);
		return SRV_MMS_BGSR_STATUS_SENDING;
	}

	if(msg_id == g_downloading_msg_id)
	{
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_OK);
		return SRV_MMS_BGSR_STATUS_DOWNLOADING;
	}

	if(srv_mms_slim_bgsr_locate_msg_id(msg_id, g_slim_bgsr_send_queue))
	{
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_TRY_TO_SEND);
		return SRV_MMS_BGSR_STATUS_WAITING_FOR_SEND;
	}

	if(srv_mms_slim_bgsr_locate_msg_id(msg_id, g_slim_bgsr_download_queue))
	{
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_TRY_TO_DOWNLOAD);
		return SRV_MMS_BGSR_STATUS_WAITING_FOR_DOWNLOAD;
	}

    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MSG_NOT_FOUND);
	return SRV_MMS_BGSR_STATUS_NONE;
}

U8	srv_mms_slim_bgsr_locate_msg_id(U32 msg_id, srv_mms_slim_bgsr_struct *queue)
{
   
			srv_mms_slim_bgsr_struct *temp_node =  queue;

            MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_FIND_Q);
			for (; temp_node != NULL; temp_node = temp_node->next)
			{
				if (msg_id == temp_node->msg_id)
				{
                    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_OK);
					return TRUE;
				}
			}
            MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_FAIL);
			return FALSE;
}


srv_mms_slim_bgsr_struct*	srv_mms_slim_bgsr_get_node_by_msgid(U32 msg_id, srv_mms_slim_bgsr_struct *queue)
{
    
			srv_mms_slim_bgsr_struct *temp_node =  queue;

            MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_EXTRACT_Q);
			for (; temp_node != NULL; temp_node = temp_node->next)
			{
				if (msg_id == temp_node->msg_id)
				{
                    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_OK);
					break;
				}
			}
            MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_FAIL);
			return temp_node;
}

// *******Handle sending queue***************
srv_mms_slim_bgsr_struct *srv_mms_get_slim_bgsr_queue_slot(srv_mms_slim_bgsr_struct ** queue)
{
	srv_mms_slim_bgsr_struct *slot = NULL;
	srv_mms_slim_bgsr_struct *temp_node = NULL;

    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_GET_Q);
	slot =
        (srv_mms_slim_bgsr_struct*) srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_slim_bgsr_struct));
	if(slot == NULL)
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_FAIL);
             return slot;
        }
	memset(slot, 0, sizeof(srv_mms_slim_bgsr_struct));

	temp_node = *queue;


    if (temp_node == NULL)
    {
        *queue = slot;
    }
    else
    {
        while (temp_node->next != NULL)
        {
            temp_node = temp_node->next;
        }
        temp_node->next = slot;
    }
    
    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_OK);
    return slot;
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
#endif

//**************Download related code*************

/*****************************************************************************
 * FUNCTION
 *  srv_mms_slim_bgsr_download_req
 * DESCRIPTION
 *  handle the download request, move a message to download q
 * CALLS
 *  
 * PARAMETERS

 * RETURNS
 *  result				srv_mms_bgsr_result_enum
 *****************************************************************************/
U8 srv_mms_slim_bgsr_download_req(kal_uint8 sim_id, U32 msg_id, U8 storage_type,BOOL un_used)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_bgsr_show_mms_status_icon(SRV_MMS_BGSR_INDICATOR_BUSY, SRV_MMS_BGSR_INDICATOR_DOWNLOAD_OP);    

    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_DOWNLOAD_MMS_REQ, msg_id, __LINE__);

	if(g_downloading_msg_id == 0)
	{
		srv_mms_slim_bgsr_download_mms( sim_id, msg_id, 0,0);
		return TRUE;
	}
	else if(!srv_mms_slim_bgsr_pre_check(&g_slim_bgsr_download_queue, msg_id, sim_id, 0))
    {
        return FALSE;
    }

	return TRUE;
}

U8 srv_mms_slim_bgsr_download_mms(kal_uint8 sim_id, U32 msg_id, U8 storage_type, BOOL unused)
{
	wap_mma_download_req_struct *msg_req;
    msg_req = (wap_mma_download_req_struct*) construct_local_para(
                        sizeof(wap_mma_download_req_struct), TD_CTRL | TD_RESET);

    msg_req->app_id = 0;    
    msg_req->req_id = mma_get_request_id();
    msg_req->msg_id = msg_id;
    msg_req->sim_id = sim_id;

    if(!srv_mms_is_sim_valid((mmi_sim_enum)sim_id))
    {
        return FALSE;
    }
	g_downloading_msg_id = msg_id;

    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_DOWNLOAD_MMS_REQ, msg_id, __LINE__);

    srv_mms_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_DOWNLOAD_REQ),
        0,
        MSG_ID_WAP_MMA_DOWNLOAD_REQ,
        (oslParaType*) msg_req,
        NULL);


	g_downloading_sim_id = sim_id;
	srv_mms_update_menu_callback(msg_id, SRV_MMS_BGSR_UPDATE_STATUS);
	return TRUE;
}
/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_download_mms_ind_hdlr
 * DESCRIPTION
 *  Download MMS message indication handler
 * PARAMETERS
 *  in_msg           [IN]
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_mms_slim_bgsr_download_mms_ind_hdlr(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_download_ind_struct *msg_ind = (wap_mma_download_ind_struct*) in_msg;;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(in_msg == NULL)
    {
        return FALSE;
    }
    if(msg_ind->app_id == 0)
    {
        
        if (g_downloading_msg_id != msg_ind->msg_id )
        {
            return TRUE;
        }
        else
        {
            wap_mma_download_res_struct *msg_res;
            
            msg_res = (wap_mma_download_res_struct*) construct_local_para(
                sizeof(wap_mma_download_res_struct), TD_CTRL | TD_RESET);
            msg_res->app_id = 0;
            msg_res->result = MMA_RESULT_OK;
            msg_res->req_id = msg_ind->req_id;
            
            srv_mms_send_message(
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
 *  srv_mms_slim_bgsr_download_mms_rsp
 * DESCRIPTION
 *  Download MMS msg response
 * PARAMETERS
 *  in_msg           [IN]
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_mms_slim_bgsr_download_mms_rsp(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16* text = NULL;
	U32 msg_id;
    wap_mma_download_rsp_struct *msg_rsp = (wap_mma_download_rsp_struct*) in_msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(msg_rsp->app_id == 0)
    {        
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_DOWNLOAD_MMS_RSP, msg_rsp->msg_id, __LINE__);

				g_downloading_msg_id = 0;
				g_downloading_sim_id = 0;
				srv_mms_bgsr_show_mms_status_icon(SRV_MMS_BGSR_INDICATOR_IDLE, SRV_MMS_BGSR_INDICATOR_DOWNLOAD_OP);    
				if (msg_rsp->result == MMA_RESULT_OK)
				{
						srv_mms_update_menu_callback(msg_rsp->msg_id, SRV_MMS_BGSR_UPDATE_STATUS);
						text = (U16*)GetString(STR_GLOBAL_SEND_MESSAGE);
				}
				else
				{
						text = (U16*)GetString(STR_GLOBAL_NOT_AVAILABLE);
				}
				
			srv_mms_download_rsp(msg_rsp->msg_id, msg_rsp->new_msg_id, srv_mms_bgsr_translate_result((mma_result_enum)msg_rsp->result), text, 0, 1, 0);     


            /*  check next message to be sent  */
			msg_id = srv_mms_check_next_msg(&g_slim_bgsr_download_queue, srv_mms_slim_bgsr_download_req,msg_rsp->msg_id);
	        if(msg_id)
	        {
			        g_downloading_msg_id = msg_id;
	        }
 
	}
	

return 0;
 
}

U32 srv_mms_check_next_msg(srv_mms_slim_bgsr_struct **queue, U8 (*srv_mms_slim_bgsr_req)(kal_uint8 sim_id, U32 msg_id, U8 storage_type,BOOL is_read_report), U32 msg_id)
{
	srv_mms_slim_bgsr_struct *temp_node = NULL;
	U32 msgId;
	U32 sim_id;
	BOOL is_read_report = FALSE;

	temp_node =  *queue;
	if(temp_node != NULL)
	{
		msgId = temp_node->msg_id;
		sim_id = temp_node->sim_id;
		is_read_report = temp_node->is_read_report;
		//srv_mms_free_slim_bgsr_queue_slot(temp_node,queue);
        *queue = temp_node->next;
        srv_mms_mem_mgr_app_adm_free(temp_node);
        if(msgId && srv_mms_is_sim_valid((mmi_sim_enum)sim_id))
        {
		    srv_mms_slim_bgsr_req(sim_id, msgId, 0,is_read_report);
		    return msgId;
        }
        else
        {
            return srv_mms_check_next_msg(queue, srv_mms_slim_bgsr_req,msgId);
        }
	}

	return 0;
}

U8 srv_mms_slim_bgsr_start_immd_retr_ind(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_start_immed_retrieval_ind_struct *ind = (wap_mma_start_immed_retrieval_ind_struct*) in_msg;
    U8 sim_id = ind->sim_id;
	g_downloading_msg_id = ind->msg_id;
	g_immd_retr_sim_id = sim_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   srv_mms_bgsr_show_mms_status_icon(SRV_MMS_BGSR_INDICATOR_BUSY, SRV_MMS_BGSR_INDICATOR_IMMD_DOWNLOAD_OP);
    return FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_stop_immd_retr_ind
 * DESCRIPTION
 *  Received STOP_IMMD_RETR_IND from MMA
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_mms_slim_bgsr_stop_immd_retr_ind(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_stop_immed_retrieval_ind_struct *ind = (wap_mma_stop_immed_retrieval_ind_struct*) in_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	srv_mms_bgsr_show_mms_status_icon(SRV_MMS_BGSR_INDICATOR_IDLE, SRV_MMS_BGSR_INDICATOR_IMMD_DOWNLOAD_OP);

	g_immd_retr_sim_id = 0;
    if(ind->msg_id == g_downloading_msg_id)
    {
        g_downloading_msg_id = 0;
        g_downloading_msg_id = srv_mms_check_next_msg(&g_slim_bgsr_download_queue, srv_mms_slim_bgsr_download_req,ind->msg_id);
        return FALSE;
    }
	
    return FALSE;
}



/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_get_msg_status
 * DESCRIPTION
 *  get the message status
 * CALLS
 *  
 * PARAMETERS
 *  msg_id                  [IN]    the message id
 * RETURNS
 *  U32
 *****************************************************************************/
U32 srv_mms_bgsr_get_msg_status(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	return srv_mms_slim_bgsr_get_msg_status(msg_id);

}

/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_update_msg_status_info
 * DESCRIPTION
 *  update the message status
 * CALLS
 *  
 * PARAMETERS
 *  msg_id                  [IN]    the message id
 * RETURNS
 *  U32
 *****************************************************************************/
U32 srv_mms_bgsr_update_msg_status_info(U32 msg_id, U8* ntt, kal_uint8* quota)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */
	
    return srv_mms_slim_bgsr_get_msg_status(msg_id);

}

//********extra function exported by BGSR***********
U8 srv_mms_bgsr_change_msg_notify(
                                    U32 msg_id, 
                                    srv_mms_bgsr_msg_operation_notify_enum msg_operation_notify,
                                    srv_mms_bgsr_msg_box_enum msg_folder,
                                    srv_mms_bgsr_funcptr_type change_msg_notify_callback,
                                    kal_uint8 storage_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 res = SRV_MMS_BGSR_RESULT_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	switch( msg_operation_notify )
	{
		case    SRV_MMS_BGSR_OP_DELETE:
		case    SRV_MMS_BGSR_OP_MOVE_TO_FOLDER:
		case    SRV_MMS_BGSR_OP_FORMAT:
		case    SRV_MMS_BGSR_OP_DELETE_ALL_INBOX:
		case    SRV_MMS_BGSR_OP_DELETE_ALL_OUTBOX:
		case    SRV_MMS_BGSR_OP_DELETE_ALL_ARCHIVE:
		case    SRV_MMS_BGSR_OP_CANCEL_ALL_INBOX:
		case    SRV_MMS_BGSR_OP_CANCEL_ALL_OUTBOX:
			res = srv_mms_slim_bgsr_get_msg_status(msg_id);
			if(change_msg_notify_callback != NULL)
			{
				if(res == SRV_MMS_BGSR_STATUS_SENDING || res == SRV_MMS_BGSR_STATUS_DOWNLOADING)
				{
						change_msg_notify_callback(
							msg_id,
							SRV_MMS_BGSR_RESULT_FAIL_FILE_IN_USE);	                
						return SRV_MMS_BGSR_RESULT_FAIL_FILE_IN_USE;
				}
				if(res == SRV_MMS_BGSR_STATUS_NONE)
				{
                    change_msg_notify_callback(
                        msg_id,
                        SRV_MMS_BGSR_RESULT_FAIL_FILE_NOT_FOUND );
						 return  SRV_MMS_BGSR_RESULT_FAIL_FILE_NOT_FOUND;
				}
				else
				{
					change_msg_notify_callback( msg_id, SRV_MMS_BGSR_RESULT_OK );
					return  SRV_MMS_BGSR_RESULT_FAIL_FILE_NOT_FOUND;
				}
			}

	}

	return SRV_MMS_BGSR_RESULT_FAIL;

}

mmi_ret srv_mms_bgsr_sim_status_info_hdlr(mmi_event_struct *evt)
{
	 return MMI_RET_OK;
}

mmi_ret srv_mms_bgsr_drive_format_hdlr(mmi_event_struct *param)
{
	 return MMI_RET_OK;
}

mmi_ret srv_mms_bgsr_usb_end_cb(mmi_event_struct* para)
{
	return MMI_RET_OK;
}
mmi_ret srv_mms_bgsr_usb_start_cb(mmi_event_struct* para)
{
return MMI_RET_OK;
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
        return;
    }
    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_ABORT_DOWNLOAD_MMS_REQ, msg_id, __LINE__);

    request_id = mma_get_request_id();

    msg_req =
        (wap_mma_cancel_download_req_struct*) construct_local_para(
                                                sizeof(wap_mma_cancel_download_req_struct),
                                                TD_CTRL | TD_RESET);
    msg_req->app_id = MMA_APP_ID_BGSR;
    msg_req->req_id = request_id;
    msg_req->msg_id = msg_id;

    srv_mms_send_message(
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
        return FALSE;
    }
    
        /*Handle abort response*/
    if(msg_rsp->msg_id == g_downloading_msg_id)
    {
        g_downloading_msg_id = 0;
        g_downloading_msg_id = srv_mms_check_next_msg(&g_slim_bgsr_download_queue, srv_mms_slim_bgsr_download_req,msg_rsp->msg_id);
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
        return;
    }
    request_id = mma_get_request_id();

    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_ABORT_SEND_MMS_REQ, msg_id, __LINE__);

    msg_req =
        (wap_mma_cancel_send_req_struct*) construct_local_para(
                                            sizeof(wap_mma_cancel_send_req_struct),
                                            TD_CTRL | TD_RESET);
    msg_req->app_id = MMA_APP_ID_BGSR;
    msg_req->req_id = request_id;
    msg_req->msg_id = msg_id;

    srv_mms_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_CANCEL_SEND_REQ),
        0,
        MSG_ID_WAP_MMA_CANCEL_SEND_REQ,
        (oslParaType*) msg_req,
        NULL);

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
    if (in_msg == NULL)
    {
        return FALSE;
    }
    
        /*Handle abort response*/
    if(msg_rsp->msg_id == g_sending_msg_id)
    {
        g_sending_msg_id = 0;
        g_is_read_report = 0;
        g_sending_msg_id = srv_mms_check_next_msg(&g_slim_bgsr_send_queue, srv_mms_slim_bgsr_send_mms, msg_rsp->msg_id);
        return TRUE;
    }   
    else
    {
        return FALSE;
    }
}


U8 srv_mms_bgsr_cancel_send_req( U32 msg_id )
{
	U32 status;
    srv_mms_slim_bgsr_struct* temp_node; 

    status = srv_mms_slim_bgsr_get_msg_status(msg_id);

    if(status == SRV_MMS_BGSR_STATUS_SENDING)
    {
        srv_mms_bgsr_abort_send_mms_req(msg_id);
		return 0;
    }
    else if(status == SRV_MMS_BGSR_STATUS_WAITING_FOR_SEND)
    {
        temp_node = srv_mms_slim_bgsr_get_node_by_msgid(msg_id, g_slim_bgsr_send_queue);
        temp_node->msg_id = 0;
        temp_node->sim_id = 0;

		return 0;
    }
    else
    {
        return 0;
    }
}

U8 srv_mms_bgsr_cancel_download_req( U32 msg_id)
{
	U32 status;
    srv_mms_slim_bgsr_struct* temp_node; 

    status = srv_mms_slim_bgsr_get_msg_status(msg_id);

    if(status == SRV_MMS_BGSR_STATUS_DOWNLOADING)
    {
        srv_mms_bgsr_abort_download_mms_req(msg_id);

		return 0;
    }
    else if(status == SRV_MMS_BGSR_STATUS_WAITING_FOR_DOWNLOAD)
    {
        temp_node = srv_mms_slim_bgsr_get_node_by_msgid(msg_id, g_slim_bgsr_download_queue);
        temp_node->msg_id = 0;
        temp_node->sim_id = 0;

		return 0;
    }
    else
    {
        return 0;
    }
}

void srv_mms_bgsr_mem_card_plug_out_notify(void)
{

}

U32 srv_mms_bgsr_get_sending_msg_id(void)
{
	return g_sending_msg_id ;
}

U32 srv_mms_bgsr_get_downloading_msg_id(void)
{
	return g_downloading_msg_id  ;
}
U8 srv_mms_bgsr_get_fail_msg_count(void)
{
	return 0;
}

void srv_mms_bgsr_cancel_send_java_msg_req(U32 msg_id)
{

}

kal_bool srv_mms_bgsr_is_in_use(kal_uint8 simId)
{
	return KAL_TRUE;
}

void srv_mms_bgsr_get_msg_info( 
                               U32 msg_id,
                               srv_mms_bgsr_msg_info_struct *msg_info,
                               srv_mms_bgsr_msg_funcptr_type get_msg_info_callback,
                               kal_uint8 storage_type,
                               mma_msg_type_enum msg_type)
{
		U8 res;
		res = srv_mms_slim_bgsr_get_msg_status(msg_id);
		if(res != SRV_MMS_BGSR_STATUS_NONE)
		{
			msg_info->msg_id    = msg_id;
			msg_info->ntt       = 0;
			msg_info->quota     = 0;
			msg_info->result    = SRV_MMS_BGSR_RESULT_OK;
			msg_info->status = res;
	        
			if(get_msg_info_callback != NULL)
			{
				get_msg_info_callback(msg_id, msg_info);
			}
		}
		else
		{
			msg_info->result = SRV_MMS_BGSR_RESULT_FAIL_FILE_NOT_FOUND;
			if(get_msg_info_callback != NULL)
			{
				get_msg_info_callback(msg_id, msg_info);
			}
		}
}
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
void srv_mms_bgsr_multi_change_msg_notify(U32 msg_id[], 
		kal_uint32 msg_count,
        srv_mms_bgsr_msg_operation_notify_enum msg_operation_notify,
		srv_mms_bgsr_msg_box_enum msg_folder,
		srv_mms_bgsr_multi_funcptr_type change_msg_notify_callback)
{
	MMI_BOOL result[SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP] = {TRUE,};
    U32 i = 0;
	U8 res;
	 switch (msg_operation_notify)
    {
        case SRV_MMS_BGSR_OP_MULTI_DELETE:
		case SRV_MMS_BGSR_OP_MULTI_MOVE:
        {
			 for (i = 0; i < msg_count; i++)
            {
				res = srv_mms_slim_bgsr_get_msg_status(msg_id[i]);
				result[i] = TRUE;
                if (res == SRV_MMS_BGSR_STATUS_SENDING || res == SRV_MMS_BGSR_STATUS_DOWNLOADING)
                {                   
                    result[i] = FALSE;
                }
			}
			if (change_msg_notify_callback)
            {
                change_msg_notify_callback(result);
            }
		}

	 }
}
#endif
kal_bool srv_mms_bgsr_is_rr_pending(U32 msg_id)
{
		U8 res;
		res = srv_mms_slim_bgsr_get_msg_status(msg_id);
		if(res == SRV_MMS_BGSR_STATUS_SENDING || res == SRV_MMS_BGSR_STATUS_WAITING_FOR_SEND)
		{
			return KAL_TRUE;
		}
		else
		{
			return KAL_FALSE;
		}
}

void srv_mms_bgsr_mem_card_plug_in_notify(void)
{

}

void srv_mms_bgsr_vendor_send_msg_req (U32 msg_id, U8 sim_id)
{

}
void srv_mms_bgsr_send_java_msg_req (U32 msg_id, U8 sim_id)     
{

}

void srv_mms_bgsr_init(void)
{

}

void srv_mms_bgsr_show_mms_status_icon(const srv_mms_bgsr_indicator_type_enum status,
                                       srv_mms_bgsr_indicator_op_enum op_type)
{
   
    switch (status)
    {
    case SRV_MMS_BGSR_INDICATOR_IDLE:
        {
            
            srv_mms_update_ui_status_icons(g_immd_retr_sim_id,SRV_MMS_ICON_STATE_ACTION_HIDE);
            break;
        }
    case SRV_MMS_BGSR_INDICATOR_BUSY:
        {
            switch (op_type)
            {
            case SRV_MMS_BGSR_INDICATOR_SEND_OP:
        {
                    if (g_downloading_sim_id == 0 &&
                        g_immd_retr_sim_id == 0)
            {
                        srv_mms_update_ui_status_icons(g_sending_sim_id,SRV_MMS_ICON_STATE_ACTION_BLINK);
            }              
            break;
        }
            case SRV_MMS_BGSR_INDICATOR_DOWNLOAD_OP:
                {
                    if (g_sending_sim_id == 0 &&
                        g_immd_retr_sim_id == 0)
                    {
                        srv_mms_update_ui_status_icons(g_downloading_sim_id,SRV_MMS_ICON_STATE_ACTION_BLINK);
                    }
                    break;
                }
            case SRV_MMS_BGSR_INDICATOR_IMMD_DOWNLOAD_OP:
        {
                    if (g_sending_sim_id == 0 &&
                        g_downloading_sim_id == 0)
            {
                        srv_mms_update_ui_status_icons(g_immd_retr_sim_id,SRV_MMS_ICON_STATE_ACTION_BLINK);
                    }
                    break;
                }
            default:
                break;
            }
            break;
        }
    default:
        break;
    }
      
}

/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_translate_result
 * DESCRIPTION
 *  translate mms result into mms bgsr result
 * PARAMETERS
 *  mma_result      [IN]        
 * RETURNS
 *  srv_mms_bgsr_result_enum
 *****************************************************************************/
srv_mms_bgsr_result_enum srv_mms_bgsr_translate_result(mma_result_enum mma_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_TRANSLATE_RESULT, mma_result, __LINE__);

    switch (mma_result)
    {
        case MMA_RESULT_OK:
            return SRV_MMS_BGSR_RESULT_OK;
        case MMA_RESULT_FAIL_IN_CALL:
            return SRV_MMS_BGSR_RESULT_FAIL_INCALL;
        case MMA_RESULT_FAIL_NOT_READY:
            return SRV_MMS_BGSR_RESULT_FAIL_NOT_READY;
        case MMA_RESULT_FAIL_BUSY:
            return SRV_MMS_BGSR_RESULT_FAIL_BUSY;
        case MMA_RESULT_FAIL_INSUFFICIENT_MEMORY:
            return SRV_MMS_BGSR_RESULT_FAIL_INSUFFICIENT_MEMORY;
        case MMA_RESULT_FAIL_INSUFFICIENT_STORAGE:
            return SRV_MMS_BGSR_RESULT_FAIL_INSUFFICIENT_STORAGE;
        case MMA_RESULT_FAIL_FILE_NOT_FOUND:
            return SRV_MMS_BGSR_RESULT_FAIL_FILE_NOT_FOUND;
        case MMA_RESULT_FAIL_FILE_CORRUPTED:
            return SRV_MMS_BGSR_RESULT_FAIL_FILE_CORRUPTED;
        case MMA_RESULT_FAIL_FILE_IN_USE:
            return SRV_MMS_BGSR_RESULT_FAIL_FILE_IN_USE;
        case MMA_RESULT_FAIL_FILE_IO:
            return SRV_MMS_BGSR_RESULT_FAIL_FILE_IO;
        case MMA_RESULT_FAIL_UNSUPPORT_CONTENT:
            return SRV_MMS_BGSR_RESULT_FAIL_UNSUPPORT_CONTENT;
        case MMA_RESULT_FAIL_COMM_UNSUPPORT_CONTENT:
            return SRV_MMS_BGSR_RESULT_FAIL_COMM_UNSUPPORT_CONTENT;
        case MMA_RESULT_FAIL_COMM_CONFIG_ERROR:
            return SRV_MMS_BGSR_RESULT_FAIL_COMM_CONFIG_ERROR;
        case MMA_RESULT_FAIL_COMM_CONNECT_ERROR:
            return SRV_MMS_BGSR_RESULT_FAIL_COMM_CONNECT_ERROR;
        case MMA_RESULT_FAIL_COMM_SERVER_ERROR:
            return SRV_MMS_BGSR_RESULT_FAIL_COMM_SERVER_ERROR;
        case MMA_RESULT_FAIL_COMM_SERVER_TIMEOUT:
            return SRV_MMS_BGSR_RESULT_FAIL_COMM_SERVER_TIMEOUT;
        case MMA_RESULT_FAIL_COMM_SERVICE_DENIED:
            return SRV_MMS_BGSR_RESULT_FAIL_COMM_SERVICE_DENIED;
        case MMA_RESULT_FAIL_COMM_UNAUTHORIZED:
            return SRV_MMS_BGSR_RESULT_FAIL_COMM_UNAUTHORIZED;
        case MMA_RESULT_FAIL_USER_CANCEL:
            return SRV_MMS_BGSR_RESULT_FAIL_USER_CANCEL;
        case MMA_RESULT_FAIL_INVALID_MSGID:
            return SRV_MMS_BGSR_RESULT_FAIL_INVALID_MSGID;
        case MMA_RESULT_FAIL_MSGID_IS_USING:
            return SRV_MMS_BGSR_RESULT_FAIL_MSGID_IS_USING;
        case MMA_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE:
            return SRV_MMS_BGSR_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE;
        case MMA_RESULT_FAIL_MAX_MSG_SIZE_REACHED:
            return SRV_MMS_BGSR_RESULT_FAIL_MAX_MSG_SIZE_REACHED;
        case MMA_RESULT_FAIL:
        default:
            return SRV_MMS_BGSR_RESULT_FAIL;
    }
}


#ifdef __MMI_MMS_FALLBACK__
/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_discard_bearer_fallback
 * DESCRIPTION
 *  Deletes the bearer fallback screen from the history
 * PARAMETERS
 *  void
 * STATUS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_discard_bearer_fallback(U8 wap_prof_sim_id)
{
}
#endif

// ****chhota bgsr ends**************

#endif /*__MMI_MMS_BGSR_SUPPORT__*/
