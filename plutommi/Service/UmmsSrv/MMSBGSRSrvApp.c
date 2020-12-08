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
 *  MMSBGSRSrvApp.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contans the Utilities API of the MMS BGSR Application.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "FileMgrSrvGProt.h"
#if defined(__MMI_USB_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__)
#include "USBSrvGProt.h"
#endif 
#include "WAPProfileSrvGProt.h"

#ifndef __MMI_BGSR_PROT_H_
#include "MMSBGSRSrvProt.h"
#endif 

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
#include "UmSrvDefs.h"  /* For SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP */
#endif 
#ifdef __MMI_UMMS_JSR205__
#include "MMSJSRSrvProts.h"
#endif 
//#ifdef __MMI_MMS_FALLBACK__
//#include "CbmCuiGprot.h"
//#endif /* __MMI_MMS_FALLBACK__ */
#include "UcmSrvGprot.h"
#include "MmsSrvGprot.h"
#include "MMIDataType.h"
#include "MMI_inet_app_trc.h"
#include "kal_general_types.h"
#include "mms_sap_struct.h"
#include "mma_api.h"
#include "string.h"
#include "WAPProfileSrvType.h"
#include "mmi_rp_srv_mms_def.h"
#include "mmi_frm_timer_gprot.h"        /* StartTimer is also declared in MMITimer_Int.h */
#include "kal_public_api.h"     /* Assert and kal_assert_fail_line not using directly */
#include "gui_typedef.h"
#include "mma_struct.h"
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "mms_adp.h"
#include "stack_ltlcom.h"
#include "kal_public_defs.h" 
#include "SimCtrlSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "NwInfoSrvGprot.h"
#include "MMSAppCommonGprot.h"
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
 *  srv_mms_bgsr_extract_q
 * DESCRIPTION
 *  extract the message from the queue
 * CALLS
 *  
 * PARAMETERS
 *  msg_id      [IN]        Message id
 *  queue       [IN]        The queue
 * RETURNS
 *  srv_mms_bgsr_msg_struct*    the message element of the message id
 *****************************************************************************/
U8 srv_mms_bgsr_extract_q(U32 msg_id, U8 *queue)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    U8 message = 0;
    U8 pre = 0;
    int find_flag = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    MMI_TRACE(MMI_TRACE_G6_SMS, SRV_MMS_BGSR_EXTRACT_Q);

    message = *queue;
    while (message != 0)
    {
        if ((srv_mms_bgsr_get_msg_array(message))->msg_id == msg_id)
        {
            find_flag = TRUE;
            break;
        }
        pre = message;
        message = *(srv_mms_bgsr_get_next_array(message));
    }

    if (find_flag == TRUE)
    {
        if (pre == 0)
        {
            *queue = *(srv_mms_bgsr_get_next_array(message));
        }
        else
        {
            *(srv_mms_bgsr_get_next_array(pre)) = *(srv_mms_bgsr_get_next_array(message));
        }

        *(srv_mms_bgsr_get_next_array(message)) = 0;
        return message;
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_get_q
 * DESCRIPTION
 *  get the message from the queue
 * CALLS
 *  
 * PARAMETERS
 *  msg_id      [IN]        Message id
 *  queue       [IN]        The queue
 * RETURNS
 *  srv_mms_bgsr_msg_struct*    the message element of the message id
 *****************************************************************************/
U8 srv_mms_bgsr_get_q(U32 msg_id, U8 queue)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    U8 message = 0;
    int find_flag = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    MMI_TRACE(MMI_TRACE_G6_SMS, SRV_MMS_BGSR_GET_Q);

    message = queue;
    while (message != 0)
    {
        if (srv_mms_bgsr_get_msg_array(message)->msg_id == msg_id)
        {
            find_flag = TRUE;
            break;
        }
        message = *(srv_mms_bgsr_get_next_array(message));
    }

    if (find_flag == TRUE)
    {
        return message;
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_find_q
 * DESCRIPTION
 *  find the corresponding message from the queue
 * CALLS
 *  
 * PARAMETERS
 *  msg_id      [IN]        Message id
 *  queue       [IN]        SendQ or DownloadQ
 *  fail_q      [IN]        SendFailQ or DownloadFailQ
 * RETURNS
 *  BOOL                whether the message is in the queue
 *****************************************************************************/
BOOL srv_mms_bgsr_find_q(U32 msg_id, U8 queue, U8 fail_q)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    U8 check = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    MMI_TRACE(MMI_TRACE_G6_SMS, SRV_MMS_BGSR_FIND_Q);

    check = queue;

    while (check != 0)
    {
        if (srv_mms_bgsr_get_msg_array(check)->msg_id == msg_id)
        {
            return TRUE;
        }
        check = *(srv_mms_bgsr_get_next_array(check));
    }

    check = fail_q;

    while (check != 0)
    {
        if (srv_mms_bgsr_get_msg_array(check)->msg_id == msg_id)
        {
            return TRUE;
        }
        check = *(srv_mms_bgsr_get_next_array(check));
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_enqueue
 * DESCRIPTION
 *  put the message into the SendQ or DownloadQ
 * CALLS
 *  
 * PARAMETERS
 *  msg         [IN]        Message
 *  queue       [IN]        SendQ or DownloadQ
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_enqueue(U8 msg, U8 *queue)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    U8 insert = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    MMI_TRACE(MMI_TRACE_G6_SMS, SRV_MMS_BGSR_ENQUEUE);

    if (msg == 0)
    {
        return;
    }

    if (*queue == 0)
    {
        *queue = msg;
        return;
    }

    insert = *queue;
    while (*(srv_mms_bgsr_get_next_array(insert)) != 0)
    {
        insert = *(srv_mms_bgsr_get_next_array(insert));
    }
    *(srv_mms_bgsr_get_next_array(insert)) = msg;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_delete_queue
 * DESCRIPTION
 *  delete the whole queue, except the certain message
 * CALLS
 *  
 * PARAMETERS
 *  queue               [IN]        The queue
 *  except_msg_id       [IN]        Except the message
 * RETURNS
 *  srv_mms_bgsr_msg_struct
 *****************************************************************************/
U8 srv_mms_bgsr_delete_queue(U8 *queue, U32 except_msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    U8 this_msg = 0;
    U8 except_msg = 0;
    U8 next_msg = 0;
    srv_mms_bgsr_msg_struct *curr_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */
    MMI_TRACE(MMI_TRACE_G6_SMS, SRV_MMS_BGSR_DELETE_Q);

    this_msg = *queue;
    while (this_msg != 0 && (curr_node = srv_mms_bgsr_get_msg_array(this_msg))->msg_id != 0)
    {
        if (curr_node->msg_id == except_msg_id)
        {
            except_msg = this_msg;
            this_msg = *(srv_mms_bgsr_get_next_array(this_msg));
            *(srv_mms_bgsr_get_next_array(except_msg)) = 0;
        }
        else
        {
            next_msg = *(srv_mms_bgsr_get_next_array(this_msg));
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
    }
    /* file operation code */
    srv_mms_bgsr_write_into_ph_mem_file();
    return except_msg;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_send_req
 * DESCRIPTION
 *  handle the send request, move a message to send q
 * CALLS
 *  
 * PARAMETERS
 *  sim_id              [IN]        
 *  msg_id              [IN]        Message id
 *  send_setting        [IN]        Send setting
 *  storage_type        [IN]        
 *  app_id              [IN]        
 *  is_rr(?)            [IN]        Is read report or not
 * RETURNS
 *  result           srv_mms_bgsr_result_enum
 *****************************************************************************/
U8 srv_mms_bgsr_send_req(
    kal_uint8 sim_id,
    kal_uint32 msg_id,
    srv_mms_bgsr_send_setting_enum send_setting,
    kal_uint8 storage_type,
    kal_uint16 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    U8 send_msg = 0;
    U8 result = SRV_MMS_BGSR_RESULT_FAIL;
    srv_mms_bgsr_msg_struct *curr_node;
    U8 update = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_SEND_REQ, msg_id, sim_id, storage_type, __LINE__);
    /* if it's not a read report, move it to OUTBOX first */

    if (!srv_mms_bgsr_is_ready())
    {
        return SRV_MMS_BGSR_RESULT_FAIL_NOT_READY;
    }

    if (app_id == MMA_APP_ID_MMS_APP)
    {
        send_msg = srv_mms_bgsr_extract_q(msg_id, &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q));
        if (send_msg != 0)
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_SEND_PREVIOUS_MSG, __LINE__);
            MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_SEND_PREVIOUS_FAIL_MSG, __LINE__);
            curr_node = srv_mms_bgsr_get_msg_array(send_msg);
            curr_node->status = SRV_MMS_BGSR_STATUS_WAITING_FOR_SEND;
            curr_node->ntt = 0;
            srv_mms_bgsr_set_no_of_tries(send_msg, (U8) (srv_mms_bgsr_get_no_of_tries(send_msg) - 1));
            curr_node->result = SRV_MMS_BGSR_RESULT_FAIL;
            srv_mms_bgsr_enqueue(send_msg, &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_q));
            update |= SRV_MMS_BGSR_UPDATE_NTT;
            curr_node->sim_id = sim_id;
        }
        else if ((send_msg = srv_mms_bgsr_get_q(msg_id, g_srv_mms_bgsr_context.srv_mms_bgsr_send_q)) != 0)
        {
            srv_mms_bgsr_get_msg_array(send_msg)->sim_id = sim_id;
        }
    }
    if (send_msg == 0)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_SEND_NEW_MSG, __LINE__);
        srv_mms_bgsr_save_mms_req(msg_id, MMA_FOLDER_OUTBOX);

        /* code for checking storage id */
    #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
        if (storage_type == MMA_MSG_STORAGE_CARD1)
        {
            send_msg = srv_mms_bgsr_extract_q(0, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_mem_q));
        }
        else
    #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ /* #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
        {
            send_msg = srv_mms_bgsr_extract_q(0, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_q));
        }

        if (send_msg != 0)
        {
            curr_node = srv_mms_bgsr_get_msg_array(send_msg);
            memset(curr_node, 0, sizeof(srv_mms_bgsr_msg_struct));

            /* INIT */
            curr_node->msg_id = msg_id;
            curr_node->result = SRV_MMS_BGSR_RESULT_NOT_USED;
            curr_node->status = SRV_MMS_BGSR_STATUS_WAITING_FOR_SEND;
            update |= (SRV_MMS_BGSR_UPDATE_NTT | SRV_MMS_BGSR_UPDATE_QUOTA);
            curr_node->sim_id = sim_id;
            if (send_setting)
            {
                curr_node->msg_info |= SRV_MMS_BGSR_SEND_AND_SAVE_INFO;
            }

            *(srv_mms_bgsr_get_next_array(send_msg)) = 0;
            srv_mms_bgsr_enqueue(send_msg, &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_q));
        }
        else
        {
            result = SRV_MMS_BGSR_RESULT_QUEUE_FULL;
            MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MEMORY_NOT_ALLOCATED, __LINE__);
        }
    }
    if (send_msg != 0)
    {
        result = SRV_MMS_BGSR_RESULT_OK;

        /* file operation */
    #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
        if (storage_type == MMA_MSG_STORAGE_CARD1)
        {

            srv_mms_bgsr_write_into_mem_card_file();
        }
        else
    #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ /* #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */

            srv_mms_bgsr_write_into_ph_mem_file();
    }

    if (g_srv_mms_bgsr_context.send_msg_id == 0)
    {
        send_msg = srv_mms_bgsr_get_next_sending_node();
        if (send_msg != 0)
        {
            if (!srv_mms_bgsr_send_mms_req(send_msg))
            {
                update |= SRV_MMS_BGSR_UPDATE_STATUS;
            }
        }
        else
        {
            if (update)
            {
                update |= SRV_MMS_BGSR_UPDATE_STATUS;
            }
            MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_CLEAR_SEND_ID);
        }
    }
    else
    {
        if (update) /* no update in case msg found in sendQ */
        {
            update |= SRV_MMS_BGSR_UPDATE_STATUS;
        }
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            SRV_MMS_BGSR_ALREADY_A_SENDING_MSG,
            g_srv_mms_bgsr_context.send_msg_id,
            __LINE__);
    }
    if (update != 0)
    {
        (srv_mms_bgsr_callback_table[0][0].update_menu_item_callback) (msg_id, update);
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_cancel_send_req
 * DESCRIPTION
 *  handle cancelling the sending message
 * CALLS
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  result           srv_mms_bgsr_result_enum
 *****************************************************************************/
U8 srv_mms_bgsr_cancel_send_req(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    U8 msg = 0;
    U8 result = SRV_MMS_BGSR_RESULT_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_CANCEL_SEND_REQ, msg_id, __LINE__);
#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
    if (g_srv_mms_bgsr_context.vendor_send_msg_id == msg_id)
    {
        if (msg_id == g_srv_mms_bgsr_context.send_msg_id)
        {
            if (msg_id == g_srv_mms_bgsr_context.cancel_send_msg_id)
            {
                /* Request for this msg_id is already sent */
                return result;
            }
            else
            {
                g_srv_mms_bgsr_context.cancel_send_msg_id = msg_id;
                srv_mms_bgsr_abort_send_mms_req(msg_id);
            }
        }
        else
        {
            g_srv_mms_bgsr_context.vendor_send_msg_id = 0;
            g_srv_mms_bgsr_context.vendor_sim_id = 0;
            srv_mms_vendor_send_rsp_callback(msg_id, SRV_MMS_BGSR_RESULT_FAIL_USER_CANCEL);
        }
        return result;
    }
#endif /* __MMI_MMS_VENDOR_APP_SUPPORT__ */ 
    if (!srv_mms_bgsr_is_ready())
    {

        return SRV_MMS_BGSR_RESULT_FAIL_NOT_READY;
    }

    if (msg_id == g_srv_mms_bgsr_context.send_msg_id)
    {
        if (msg_id == g_srv_mms_bgsr_context.cancel_send_msg_id)
        {
            /* Request for this msg_id is already sent */
            return result;
        }
        else
        {
            /* if the message is in sending, keep the sending state, enqueue it back to send queue
               wait for the reply to change the status */

            result = SRV_MMS_BGSR_RESULT_OK;
            g_srv_mms_bgsr_context.cancel_send_msg_id = msg_id;
            srv_mms_bgsr_abort_send_mms_req(msg_id);
        }
    }
    else
    {
    #ifdef __MMI_MMS_FALLBACK__
        if (msg_id == g_srv_mms_bgsr_context.fallback_send_id)
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_DELETE_FALLBACK_SCREEN, msg_id, __LINE__);

            srv_mms_bgsr_send_events(EVT_ID_SRV_BGSR_FALLBACK_CUI_CLOSE, g_srv_mms_bgsr_context.acct_id);
            /* cui_cbm_bearer_fallback_close(g_srv_mms_bgsr_context.cbm_cui_id); */
            if (g_srv_mms_bgsr_context.fallback_sim_id != 0)
            {
                srv_mms_refresh_profile_settings(g_srv_mms_bgsr_context.fallback_sim_id);
                g_srv_mms_bgsr_context.fallback_sim_id = 0;
            }
        }
    #endif /* __MMI_MMS_FALLBACK__ */ 

        /* if the message is not in sending, change the status, enqueue it to send fail queue */

        msg = srv_mms_bgsr_extract_q(msg_id, &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_q));
        if (msg == 0)
        {
            msg = srv_mms_bgsr_extract_q(msg_id, &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q));
        }
        if (msg != 0)
        {
            /* If send is cancelled just after sending for first time */
            if (srv_mms_bgsr_get_no_of_tries(msg) == 0)
            {
                srv_mms_bgsr_set_no_of_tries(msg, (U8) (srv_mms_bgsr_get_no_of_tries(msg) + 1));
            }
            srv_mms_bgsr_get_msg_array(msg)->status = SRV_MMS_BGSR_STATUS_DEFERRED_FOR_SEND;
            srv_mms_bgsr_enqueue(msg, &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q));

            result = SRV_MMS_BGSR_RESULT_CANCELLED;
            (srv_mms_bgsr_callback_table[0][0].update_menu_item_callback) (msg_id, SRV_MMS_BGSR_UPDATE_STATUS);

        #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
            if (msg & (SRV_MMS_BGSR_MEM_CARD_BIT))
            {
                srv_mms_bgsr_write_into_mem_card_file();

            }
            else
        #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ /* #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
            {
                srv_mms_bgsr_write_into_ph_mem_file();
            }
        }
        else
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MSG_NOT_FOUND, __LINE__);
            srv_mms_bgsr_echo_current_info();
            return SRV_MMS_BGSR_RESULT_FAIL;
        }
    }
    return result;
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
    srv_mms_bgsr_set_rr_flag_req(msg_id, TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_send_rr_req
 * DESCRIPTION
 *  handle the send request for a read report,
 * CALLS
 *  
 * PARAMETERS
 *  sim_id              [IN]        Sim id
 *  msg_id              [IN]        Message id
 *  storage_type        [IN]        
 *  msg_folder(?)       [IN]        Folder type
 * RETURNS
 *  result           srv_mms_bgsr_result_enum
 *****************************************************************************/
U8 srv_mms_bgsr_send_rr_req(kal_uint8 sim_id, U32 msg_id, kal_uint8 storage_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    U8 send_msg = 0;
    U8 result = SRV_MMS_BGSR_RESULT_FAIL;
    srv_mms_bgsr_msg_struct *curr_node;
    U8 update = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */
    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_SEND_RR, __LINE__);
    if (!srv_mms_bgsr_is_ready())
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_NOT_READY, __LINE__);
        return SRV_MMS_BGSR_RESULT_FAIL_NOT_READY;
    }

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    if (storage_type == MMA_MSG_STORAGE_CARD1)
    {
        send_msg = srv_mms_bgsr_extract_q(0, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_mem_q));
    }
    else
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ /* #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
    {
        send_msg = srv_mms_bgsr_extract_q(0, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_q));
    }

    if (send_msg != 0)
    {
        curr_node = srv_mms_bgsr_get_msg_array(send_msg);
        memset(curr_node, 0, sizeof(srv_mms_bgsr_msg_struct));
        curr_node->msg_info |= SRV_MMS_BGSR_IS_RR_INFO;
        curr_node->msg_id = msg_id;
        curr_node->ntt = 0;
        curr_node->result = SRV_MMS_BGSR_RESULT_NOT_USED;
        curr_node->status = SRV_MMS_BGSR_STATUS_WAITING_FOR_SEND;
        update |= (SRV_MMS_BGSR_UPDATE_NTT | SRV_MMS_BGSR_UPDATE_QUOTA);
        curr_node->sim_id = sim_id;
        srv_mms_bgsr_enqueue(send_msg, &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_q));
    }
    else
    {
        result = SRV_MMS_BGSR_RESULT_QUEUE_FULL;
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MEMORY_NOT_ALLOCATED, __LINE__);
    }

    if (send_msg != 0)
    {

        /* file operationm */
    #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
        if (storage_type == MMA_MSG_STORAGE_CARD1)
        {
            srv_mms_bgsr_write_into_mem_card_file();
        }
        else
    #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
        {
            srv_mms_bgsr_write_into_ph_mem_file();
        }
    }

    if (g_srv_mms_bgsr_context.send_msg_id == 0)
    {
        send_msg = srv_mms_bgsr_get_next_sending_node();
        if (send_msg != 0)
        {
            if (!srv_mms_bgsr_send_mms_req(send_msg))
            {
                update |= SRV_MMS_BGSR_UPDATE_STATUS;
            }
            result = SRV_MMS_BGSR_RESULT_OK;
        }
        else
        {
            if (update)
            {
                update |= SRV_MMS_BGSR_UPDATE_STATUS;
            }
            MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_CLEAR_SEND_ID);
        }
    }
    else
    {
        if (update)
        {
            update |= SRV_MMS_BGSR_UPDATE_STATUS;
        }
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            SRV_MMS_BGSR_ALREADY_A_SENDING_MSG,
            g_srv_mms_bgsr_context.send_msg_id,
            __LINE__);
    }
    if (update != 0)
    {
        (srv_mms_bgsr_callback_table[0][0].update_menu_item_callback) (msg_id, update);
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_is_rr_pending
 * DESCRIPTION
 *  (U32 msg_id)
 *  Checks if read report is in send queue
 * CALLS
 *  
 * PARAMETERS
 *  msg_id      [IN]        Message id
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool srv_mms_bgsr_is_rr_pending(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_mms_bgsr_get_q(msg_id, g_srv_mms_bgsr_context.srv_mms_bgsr_send_q))
    {
        return KAL_TRUE;
    }
    else if (srv_mms_bgsr_get_q(msg_id, g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q))
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

#ifdef __MMI_UMMS_JSR205__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_send_java_msg_req
 * DESCRIPTION
 *  (U32 msg_id, U8 sim_id)
 *  This function is used to send a java message
 * CALLS
 *  
 * PARAMETERS
 *  msg_id      [IN]        Message id
 *  sim_id      [IN]        Sim id
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_send_java_msg_req(U32 msg_id, U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 request_id;
    wap_mma_send_req_struct *msg_req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_SENDING_JAVA_MSG, msg_id, __LINE__);

    if (!srv_mms_bgsr_is_mma_ready()
#if defined(__MMI_USB_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__)
        || srv_usb_is_in_mass_storage_mode() || srv_mms_bgsr_mms_is_exported()
#endif 
        )
    {
        srv_mms_jsr_send_msg_rsp((U16) msg_id, SRV_MMS_BGSR_RESULT_FAIL_NOT_READY);
        return;
    }
#ifndef __UMTS_RAT__
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0 ||
        (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0))
    {
        srv_mms_jsr_send_msg_rsp((U16) msg_id, SRV_MMS_BGSR_RESULT_FAIL_INCALL);
        return;
    }
#endif /* __UMTS_RAT__ */ 
    g_srv_mms_bgsr_context.java_send_msg_id = msg_id;
    g_srv_mms_bgsr_context.java_sim_id = sim_id;

    if (g_srv_mms_bgsr_context.send_msg_id == 0)
    {
        g_srv_mms_bgsr_context.send_msg_id = msg_id;
        g_srv_mms_bgsr_context.send_sim_id = sim_id;
        srv_mms_bgsr_show_mms_status_icon(SRV_MMS_BGSR_INDICATOR_BUSY, SRV_MMS_BGSR_INDICATOR_SEND_OP);
        request_id = srv_mms_bgsr_get_request_id();
        msg_req = (wap_mma_send_req_struct*) construct_local_para(sizeof(wap_mma_send_req_struct), TD_CTRL | TD_RESET);
        msg_req->app_id = MMA_APP_ID_BGSR;
        msg_req->req_id = request_id;
        msg_req->msg_id = msg_id;
        msg_req->is_read_report = KAL_FALSE;
        msg_req->sim_id = sim_id;
        msg_req->send_and_save = KAL_FALSE;
        msg_req->box = 0;
        srv_mms_jsr_update_send_msg_icon(msg_id, SRV_MMS_BGSR_STATUS_SENDING);
        srv_mms_bgsr_send_message(
            MOD_MMI,
            mms_get_service_module(MSG_ID_WAP_MMA_SEND_REQ),
            0,
            MSG_ID_WAP_MMA_SEND_REQ,
            (oslParaType*) msg_req,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_cancel_send_java_msg_req
 * DESCRIPTION
 *  (U32 msg_id)
 *  This function is used to cancel the sending of a java message.
 * CALLS
 *  
 * PARAMETERS
 *  msg_id      [IN]        Message id
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_cancel_send_java_msg_req(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_CANCELLING_JAVA_MSG, msg_id, __LINE__);
    if (msg_id == g_srv_mms_bgsr_context.send_msg_id)
    {
        if (msg_id == g_srv_mms_bgsr_context.cancel_send_msg_id)
        {
            /* Request for this msg_id is already sent */
            return;
        }
        else
        {
            g_srv_mms_bgsr_context.cancel_send_msg_id = msg_id;
            srv_mms_bgsr_abort_send_mms_req(msg_id);
        }
    }
    else
    {
        g_srv_mms_bgsr_context.java_send_msg_id = 0;
        g_srv_mms_bgsr_context.java_sim_id = 0;
        srv_mms_jsr_cancel_send_msg_rsp(SRV_MMS_BGSR_RESULT_OK);
        srv_mms_jsr_send_msg_rsp((U16) msg_id, SRV_MMS_BGSR_RESULT_FAIL_USER_CANCEL);
    }
    return;
}
#endif /* __MMI_UMMS_JSR205__ */ 

#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_vendor_send_msg_req
 * DESCRIPTION
 *  (U32 msg_id, U8 sim_id)
 *  send vendor msg
 * CALLS
 *  
 * PARAMETERS
 *  msg_id      [IN]        Message id
 *  sim_id      [IN]        Sim_id
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_vendor_send_msg_req(U32 msg_id, U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 request_id;
    wap_mma_send_req_struct *msg_req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_mms_bgsr_is_mma_ready()
#if defined(__MMI_USB_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__)
        || srv_usb_is_in_mass_storage_mode() || srv_mms_bgsr_mms_is_exported()
#endif 
        )
    {
        srv_mms_vendor_send_rsp_callback(msg_id, MMA_RESULT_FAIL);
        return;
    }
#ifndef __UMTS_RAT__
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0 ||
        (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0))
    {
        srv_mms_vendor_send_rsp_callback(msg_id, MMA_RESULT_FAIL);
        return;
    }
#endif /* __UMTS_RAT__ */ 
    g_srv_mms_bgsr_context.vendor_send_msg_id = msg_id;
    g_srv_mms_bgsr_context.vendor_sim_id = sim_id;

    if (g_srv_mms_bgsr_context.send_msg_id == 0)
    {
        g_srv_mms_bgsr_context.send_msg_id = msg_id;
        g_srv_mms_bgsr_context.send_sim_id = sim_id;
        srv_mms_bgsr_show_mms_status_icon(SRV_MMS_BGSR_INDICATOR_BUSY, SRV_MMS_BGSR_INDICATOR_SEND_OP);
        request_id = srv_mms_bgsr_get_request_id();
        msg_req = (wap_mma_send_req_struct*) construct_local_para(sizeof(wap_mma_send_req_struct), TD_CTRL | TD_RESET);
        msg_req->app_id = MMA_APP_ID_BGSR;
        msg_req->req_id = request_id;
        msg_req->msg_id = msg_id;
        msg_req->is_read_report = KAL_FALSE;
        msg_req->sim_id = sim_id;
        msg_req->send_and_save = KAL_FALSE;
        msg_req->box = 0;

        srv_mms_bgsr_send_message(
            MOD_MMI,
            mms_get_service_module(MSG_ID_WAP_MMA_SEND_REQ),
            0,
            MSG_ID_WAP_MMA_SEND_REQ,
            (oslParaType*) msg_req,
            NULL);
    }
}
#endif /* __MMI_MMS_VENDOR_APP_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_download_req
 * DESCRIPTION
 *  handle the download request, move a message to download q
 * CALLS
 *  
 * PARAMETERS
 *  sim_id              [IN]        
 *  msg_id              [IN]        Message id
 *  storage_type        [IN]        
 *  expire_time(?)      [IN]        Expire time
 *  size(?)             [IN]        Size
 * RETURNS
 *  result           srv_mms_bgsr_result_enum
 *****************************************************************************/
U8 srv_mms_bgsr_download_req(kal_uint8 sim_id, U32 msg_id, U8 storage_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    U8 dl_msg = 0;
    U8 result = SRV_MMS_BGSR_RESULT_FAIL;
    srv_mms_bgsr_msg_struct *curr_node;
    U8 update = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_DOWNLOAD_REQ, msg_id, sim_id, storage_type, __LINE__);

    if (!srv_mms_bgsr_is_ready())
    {
        return SRV_MMS_BGSR_RESULT_FAIL_NOT_READY;
    }
    dl_msg = srv_mms_bgsr_extract_q(msg_id, &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q));
    if (dl_msg != 0)
    {
        curr_node = srv_mms_bgsr_get_msg_array(dl_msg);
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_DOWNLOAD_PREVIOUS_FAIL_MSG, __LINE__);
        curr_node->status = SRV_MMS_BGSR_STATUS_WAITING_FOR_DOWNLOAD;
        curr_node->result = SRV_MMS_BGSR_RESULT_FAIL;
        srv_mms_bgsr_set_no_of_tries(dl_msg, (U8) (srv_mms_bgsr_get_no_of_tries(dl_msg) - 1));
        curr_node->ntt = 0;
        update |= SRV_MMS_BGSR_UPDATE_NTT;
        srv_mms_bgsr_enqueue(dl_msg, &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_q));
        curr_node->sim_id = sim_id;
    }

    else if ((dl_msg = srv_mms_bgsr_get_q(msg_id, g_srv_mms_bgsr_context.srv_mms_bgsr_download_q)) != 0)
    {
        srv_mms_bgsr_get_msg_array(dl_msg)->sim_id = sim_id;
    }
    else
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_DOWNLOAD_NEW_MSG, __LINE__);
    #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
        if (storage_type == MMA_MSG_STORAGE_CARD1)
        {
            dl_msg = srv_mms_bgsr_extract_q(0, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_mem_q));
        }
        else
    #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ /* #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
        {
            dl_msg = srv_mms_bgsr_extract_q(0, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_q));
        }
        if (dl_msg != 0)
        {
            curr_node = srv_mms_bgsr_get_msg_array(dl_msg);
            memset(curr_node, 0, sizeof(srv_mms_bgsr_msg_struct));
            curr_node->sim_id = sim_id;
            curr_node->msg_id = msg_id;
            curr_node->ntt = 0;
            curr_node->msg_info |= 0;
            curr_node->result = SRV_MMS_BGSR_RESULT_NOT_USED;
            curr_node->status = SRV_MMS_BGSR_STATUS_WAITING_FOR_DOWNLOAD;
            srv_mms_bgsr_set_no_of_tries(dl_msg, 0);
            update |= (SRV_MMS_BGSR_UPDATE_NTT | SRV_MMS_BGSR_UPDATE_QUOTA);
            srv_mms_bgsr_enqueue(dl_msg, &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_q));
        }
        else
        {
            result = SRV_MMS_BGSR_RESULT_QUEUE_FULL;
            MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MEMORY_NOT_ALLOCATED, __LINE__);
        }
    }

    if (dl_msg != 0)
    {
        result = SRV_MMS_BGSR_RESULT_OK;
    #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
        if (storage_type == MMA_MSG_STORAGE_CARD1)
        {
            srv_mms_bgsr_write_into_mem_card_file();
        }
        else
    #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
        {
            srv_mms_bgsr_write_into_ph_mem_file();
        }
    }

    if (g_srv_mms_bgsr_context.download_msg_id == 0 && g_srv_mms_bgsr_context.immd_retr_sim_id == 0)
    {
        dl_msg = srv_mms_bgsr_get_next_downloading_node();
        if (dl_msg)
        {
            if (!srv_mms_bgsr_download_mms_req(dl_msg))
            {
                update |= SRV_MMS_BGSR_UPDATE_STATUS;
            }
        }
        else
        {
            if (update)
            {
                update |= SRV_MMS_BGSR_UPDATE_STATUS;
            }
            MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_CLEAR_DOWNLOAD_ID);
        }
    }
    else
    {
        if (update)
        {
            update |= SRV_MMS_BGSR_UPDATE_STATUS;
        }
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            SRV_MMS_BGSR_ALREADY_A_DOWNLOAD_MSG,
            g_srv_mms_bgsr_context.download_msg_id,
            __LINE__);
    }
    if (update != 0)
    {
        (srv_mms_bgsr_callback_table[0][0].update_menu_item_callback) (msg_id, update);
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_download_req_no_progressing
 * DESCRIPTION
 *  handle the download request, move a message to download q
 * CALLS
 *  
 * PARAMETERS
 *  sim_id              [IN]        
 *  msg_id              [IN]        Message id
 *  storage_type        [IN]        
 *  expire_time(?)      [IN]        Expire time
 *  size(?)             [IN]        Size
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_download_req_no_progressing(kal_uint8 sim_id, U32 msg_id, U8 storage_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    U8 dl_msg = 0;
    srv_mms_bgsr_msg_struct *curr_node;
    U8 update = 0;

    U8 bgsr_sim_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_DOWNLOAD_REQ_NO_PROGRESS, msg_id, sim_id, storage_type, __LINE__);

    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_DOWNLOAD_NEW_MSG, __LINE__);

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    if (storage_type == MMA_MSG_STORAGE_CARD1)
    {
        dl_msg = srv_mms_bgsr_extract_q(0, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_mem_q));
    }
    else
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ /* #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
    {
        dl_msg = srv_mms_bgsr_extract_q(0, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_q));
    }
    if (dl_msg != 0)
    {
        curr_node = srv_mms_bgsr_get_msg_array(dl_msg);
        memset(curr_node, 0, sizeof(srv_mms_bgsr_msg_struct));

        /* INIT */

        curr_node->sim_id = sim_id;
        curr_node->msg_id = msg_id;
        curr_node->ntt = 2;
        curr_node->msg_info |= SRV_MMS_BGSR_CFG_RETRY_QUOTA;
        curr_node->result = SRV_MMS_BGSR_RESULT_FAIL;
        curr_node->status = SRV_MMS_BGSR_STATUS_POSTPONE_FOR_DOWNLOAD;
        srv_mms_bgsr_set_no_of_tries(dl_msg, 1);
        update |= (SRV_MMS_BGSR_UPDATE_STATUS | SRV_MMS_BGSR_UPDATE_NTT | SRV_MMS_BGSR_UPDATE_QUOTA);
        srv_mms_bgsr_enqueue(dl_msg, &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q));
    }
    else
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MEMORY_NOT_ALLOCATED, __LINE__);
    }

    if (dl_msg != 0)
    {
        /* file operation */
    #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
        if (storage_type == MMA_MSG_STORAGE_CARD1)
        {
            srv_mms_bgsr_write_into_mem_card_file();
        }
        else
    #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
        {
            srv_mms_bgsr_write_into_ph_mem_file();
        }
    }

    bgsr_sim_id = srv_mms_bgsr_convert_mma_sim_id_to_bgsr_sim_id(sim_id);
    if (!srv_wap_prof_is_dtcnt_valid(
            srv_mms_bgsr_convert_bgsr_sim_id_to_wap_prof(bgsr_sim_id),
            SRV_WAP_PROF_APPID_MMS,
            (U8) - 1))
    {
        srv_mms_bgsr_get_msg_array(dl_msg)->status = SRV_MMS_BGSR_STATUS_DOWNLOAD_FAILED_INVALID_DATA_ACCOUNT;
        update |= SRV_MMS_BGSR_UPDATE_STATUS;
    }
    if (update != 0)
    {
        (srv_mms_bgsr_callback_table[0][0].update_menu_item_callback) (msg_id, update);
    }
#ifdef __MMI_MMS_FALLBACK__
    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_FALLBACK_MASK, sim_id, g_srv_mms_bgsr_context.fallback_mask, __LINE__);

    if ((g_srv_mms_bgsr_context.fallback_mask & SRV_MMS_BGSR_FALLBACK_MASK_NEED_FALLBACK) ==
        SRV_MMS_BGSR_FALLBACK_MASK_NEED_FALLBACK)
    {
        if (g_srv_mms_bgsr_context.fallback_download_id == 0 && g_srv_mms_bgsr_context.immd_retr_sim_id == 0)
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_SET_IMM_DOWNLOAD_ID, __LINE__);
            g_srv_mms_bgsr_context.fallback_download_id = msg_id;
        }
    }
#endif /* __MMI_MMS_FALLBACK__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_cancel_download_req
 * DESCRIPTION
 *  handle cancelling the sending message
 * CALLS
 *  
 * PARAMETERS
 *  msg_id      [IN]        Message id
 * RETURNS
 *  result           srv_mms_bgsr_result_enum
 *****************************************************************************/
U8 srv_mms_bgsr_cancel_download_req(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    U8 msg = 0;
    U8 result = SRV_MMS_BGSR_RESULT_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_CANCEL_DOWNLOAD_REQ, msg_id, __LINE__);

    if (!srv_mms_bgsr_is_ready())
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_NOT_READY, __LINE__);
        return SRV_MMS_BGSR_RESULT_FAIL_NOT_READY;
    }
    if (msg_id == g_srv_mms_bgsr_context.download_msg_id)
    {
        if (msg_id == g_srv_mms_bgsr_context.cancel_download_msg_id)
        {
            /* Request for this msg_id is already sent */
            return result;
        }
        else
        {
            result = SRV_MMS_BGSR_RESULT_OK;
            g_srv_mms_bgsr_context.cancel_download_msg_id = msg_id;
            /* if the message is in downloading, keep the state, enqueue it back to send queue
               wait for the reply to change the status */
            srv_mms_bgsr_abort_download_mms_req(msg_id);
        }
    }
    else
    {
    #ifdef __MMI_MMS_FALLBACK__
        if (msg_id == g_srv_mms_bgsr_context.fallback_download_id)
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_DELETE_FALLBACK_SCREEN, msg_id, __LINE__);
            srv_mms_bgsr_send_events(EVT_ID_SRV_BGSR_FALLBACK_CUI_CLOSE, g_srv_mms_bgsr_context.acct_id);
            /* cui_cbm_bearer_fallback_close(g_srv_mms_bgsr_context.cbm_cui_id); */
            if (g_srv_mms_bgsr_context.fallback_sim_id != 0)
            {
                srv_mms_refresh_profile_settings(g_srv_mms_bgsr_context.fallback_sim_id);
                g_srv_mms_bgsr_context.fallback_sim_id = 0;
            }
        }
    #endif /* __MMI_MMS_FALLBACK__ */ 

        /* if the message is not in downloading, change the status, enqueue it to download fail queue */

        msg = srv_mms_bgsr_extract_q(msg_id, &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_q));
        if (msg == 0)
        {
            msg = srv_mms_bgsr_extract_q(msg_id, &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q));
        }
        if (msg != 0)
        {
            /* If download is cancelled just after downloading for first time */
            if (srv_mms_bgsr_get_no_of_tries(msg) == 0)
            {
                srv_mms_bgsr_set_no_of_tries(msg, (U8) (srv_mms_bgsr_get_no_of_tries(msg) + 1));
            }
            srv_mms_bgsr_get_msg_array(msg)->status = SRV_MMS_BGSR_STATUS_DEFERRED_FOR_DOWNLOAD;
            srv_mms_bgsr_enqueue(msg, &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q));
            result = SRV_MMS_BGSR_RESULT_CANCELLED;
            (srv_mms_bgsr_callback_table[0][0].update_menu_item_callback) (msg_id, SRV_MMS_BGSR_UPDATE_STATUS);

        #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
            if (msg & (SRV_MMS_BGSR_MEM_CARD_BIT))
            {
                srv_mms_bgsr_write_into_mem_card_file();
            }
            else
        #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ /* #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
            {
                srv_mms_bgsr_write_into_ph_mem_file();
            }
        }
        else
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MSG_NOT_FOUND, __LINE__);
            srv_mms_bgsr_echo_current_info();
            return SRV_MMS_BGSR_RESULT_FAIL;
        }
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_get_msg_info
 * DESCRIPTION
 *  get the message information
 * CALLS
 *  
 * PARAMETERS
 *  msg_id                      [IN]        The message id
 *  msg_info                    [IN]        The memory block for the message info
 *  get_msg_info_callback       [IN]        The callback function
 *  storage_type                [IN]        
 *  msg_type                    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_get_msg_info(
        U32 msg_id,
        srv_mms_bgsr_msg_info_struct *msg_info,
        srv_mms_bgsr_msg_funcptr_type get_msg_info_callback,
        kal_uint8 storage_type,
        mma_msg_type_enum msg_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    U8 local_msg = 0;
    srv_mms_bgsr_msg_struct *curr_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */
    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_GET_MSG_INFO, msg_id, __LINE__);

    local_msg = srv_mms_bgsr_find_msg(msg_id);

    if (local_msg == 0)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MSG_NOT_FOUND, __LINE__);
        srv_mms_bgsr_echo_current_info();
        msg_info->result = SRV_MMS_BGSR_RESULT_FAIL_FILE_NOT_FOUND;
        if (get_msg_info_callback != NULL)
        {
            get_msg_info_callback(msg_id, msg_info);
        }
    }
    else
    {
        curr_node = srv_mms_bgsr_get_msg_array(local_msg);
        msg_info->msg_id = curr_node->msg_id;
        msg_info->ntt = curr_node->ntt;
        msg_info->quota = curr_node->msg_info & SRV_MMS_BGSR_QUOTA_INFO;
        msg_info->result = curr_node->result;
        msg_info->status = srv_mms_bgsr_update_status(local_msg, curr_node->status);

        if (get_msg_info_callback != NULL)
        {
            get_msg_info_callback(msg_id, msg_info);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_get_msg_status
 * DESCRIPTION
 *  get the message status
 * CALLS
 *  
 * PARAMETERS
 *  msg_id      [IN]        The message id
 * RETURNS
 *  U32
 *****************************************************************************/
U32 srv_mms_bgsr_get_msg_status(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    U8 local_msg = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    local_msg = srv_mms_bgsr_find_msg(msg_id);

    if (local_msg == 0)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MSG_NOT_FOUND, __LINE__);
        srv_mms_bgsr_echo_current_info();
        return SRV_MMS_BGSR_STATUS_NONE;
    }
    else
    {
        return srv_mms_bgsr_update_status(local_msg, srv_mms_bgsr_get_msg_array(local_msg)->status);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_update_msg_status_info
 * DESCRIPTION
 *  update the message status
 * CALLS
 *  
 * PARAMETERS
 *  msg_id      [IN]        The message id
 *  ntt         [?]         
 *  quota       [?]         
 * RETURNS
 *  U32
 *****************************************************************************/
U32 srv_mms_bgsr_update_msg_status_info(U32 msg_id, U8 *ntt, kal_uint8 *quota)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    U8 local_msg = 0;
    srv_mms_bgsr_msg_struct *curr_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    local_msg = srv_mms_bgsr_find_msg(msg_id);

    if (local_msg == 0)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MSG_NOT_FOUND, __LINE__);
        srv_mms_bgsr_echo_current_info();
        return SRV_MMS_BGSR_STATUS_NONE;
    }
    else
    {
        curr_node = srv_mms_bgsr_get_msg_array(local_msg);
        *ntt = curr_node->ntt;
        *quota = curr_node->msg_info & SRV_MMS_BGSR_QUOTA_INFO;
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            SRV_MMS_BGSR_ALREADY_UPDATE_STATUS,
            msg_id,
            curr_node->status,
            *ntt,
            *quota,
            __LINE__);
        return srv_mms_bgsr_update_status(local_msg, curr_node->status);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_find_msg
 * DESCRIPTION
 *  find msg from all queue
 * CALLS
 *  
 * PARAMETERS
 *  msg_id      [IN]        The message id
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_mms_bgsr_find_msg(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    U8 local_msg = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */
    if (msg_id == 0)
    {
        return 0;
    }
    local_msg = srv_mms_bgsr_get_q(msg_id, g_srv_mms_bgsr_context.srv_mms_bgsr_send_q);
    if (local_msg == 0)
    {
        local_msg = srv_mms_bgsr_get_q(msg_id, g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q);
    }
    if (local_msg == 0)
    {
        local_msg = srv_mms_bgsr_get_q(msg_id, g_srv_mms_bgsr_context.srv_mms_bgsr_download_q);
    }
    if (local_msg == 0)
    {
        local_msg = srv_mms_bgsr_get_q(msg_id, g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q);
    }
    return local_msg;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_get_sending_msg_id
 * DESCRIPTION
 *  ;
 *  return the sending message id
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U32 send_msg_id
 *****************************************************************************/
U32 srv_mms_bgsr_get_sending_msg_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */
    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_ALREADY_A_SENDING_MSG, g_srv_mms_bgsr_context.send_msg_id, __LINE__);
    return g_srv_mms_bgsr_context.send_msg_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_get_downloading_msg_id
 * DESCRIPTION
 *  return the downloading message id
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U32 download_msg_id
 *****************************************************************************/
U32 srv_mms_bgsr_get_downloading_msg_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */
    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        SRV_MMS_BGSR_ALREADY_A_DOWNLOAD_MSG,
        g_srv_mms_bgsr_context.download_msg_id,
        __LINE__);
    return g_srv_mms_bgsr_context.download_msg_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_get_fail_msg_count
 * DESCRIPTION
 *  return no. of fail messages
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8 fail count
 *****************************************************************************/
U8 srv_mms_bgsr_get_fail_msg_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    U8 fail_count = 0;
    U8 message = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */
    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_GET_FAIL_MSG_COUNT, __LINE__);
    message = g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q;
    while (message)
    {
        if (srv_mms_bgsr_get_msg_array(message)->status == SRV_MMS_BGSR_STATUS_SEND_FAIL)
        {
            fail_count++;
        }
        message = *(srv_mms_bgsr_get_next_array(message));
    }
    return fail_count;
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
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    U8 status = 0;
    U8 message = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */
    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_GET_FAIL_MSG_COUNT, __LINE__);
    message = g_srv_mms_bgsr_context.srv_mms_bgsr_send_q;
    while (message)
    {
        status = srv_mms_bgsr_get_msg_array(message)->status;
        if (status == SRV_MMS_BGSR_STATUS_WAITING_FOR_SEND || status == SRV_MMS_BGSR_STATUS_POSTPONE_FOR_SEND)
        {
            return MMI_TRUE;
        }
        message = *(srv_mms_bgsr_get_next_array(message));
    }
    message = g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q;
    while (message)
    {
        status = srv_mms_bgsr_get_msg_array(message)->status;
        if (status == SRV_MMS_BGSR_STATUS_WAITING_FOR_SEND || status == SRV_MMS_BGSR_STATUS_POSTPONE_FOR_SEND)
        {
            return MMI_TRUE;
        }
        message = *(srv_mms_bgsr_get_next_array(message));
    }
    return MMI_FALSE;
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
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    U8 status = 0;
    U8 message = 0;
    U16 wait_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */
    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_GET_FAIL_MSG_COUNT, __LINE__);
    message = g_srv_mms_bgsr_context.srv_mms_bgsr_send_q;
    while (message)
    {
        status = srv_mms_bgsr_get_msg_array(message)->status;
        if (status == SRV_MMS_BGSR_STATUS_WAITING_FOR_SEND || status == SRV_MMS_BGSR_STATUS_POSTPONE_FOR_SEND)
        {
            wait_count++;
        }
        message = *(srv_mms_bgsr_get_next_array(message));
    }
    message = g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q;
    while (message)
    {
        status = srv_mms_bgsr_get_msg_array(message)->status;
        if (status == SRV_MMS_BGSR_STATUS_WAITING_FOR_SEND || status == SRV_MMS_BGSR_STATUS_POSTPONE_FOR_SEND)
        {
            wait_count++;
        }
        message = *(srv_mms_bgsr_get_next_array(message));
    }
    return wait_count;
}

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_multi_change_msg_notify
 * DESCRIPTION
 *  handle the multiple operation notify
 * CALLS
 *  
 * PARAMETERS
 *  msg_id                          [IN]        Message id
 *  msg_count                       [IN]        No. of messages
 *  msg_operation_notify            [IN]        Operation
 *  msg_folder                      [IN]        The message folder
 *  change_msg_notify_callback      [IN]        The callback function
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_multi_change_msg_notify(
        U32 msg_id[],
        kal_uint32 msg_count,
        srv_mms_bgsr_msg_operation_notify_enum msg_operation_notify,
        srv_mms_bgsr_msg_box_enum msg_folder,
        srv_mms_bgsr_multi_funcptr_type change_msg_notify_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result[SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP] = {MMI_TRUE, };
    U32 i = 0;
    U8 local_msg = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        SRV_MMS_BGSR_MULTI_CHANGE_MSG_NOTIFY,
        msg_operation_notify,
        msg_count,
        msg_folder,
        __LINE__);

    switch (msg_operation_notify)
    {
        case SRV_MMS_BGSR_OP_MULTI_DELETE:
        {
            for (i = 0; i < msg_count; i++)
            {
            #ifdef __MMI_MMS_FALLBACK__
                if (msg_id[i] != 0 && (msg_id[i] == g_srv_mms_bgsr_context.fallback_send_id ||
                                       msg_id[i] == g_srv_mms_bgsr_context.fallback_download_id))
                {
                    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_DELETE_FALLBACK_SCREEN, msg_id[i], __LINE__);
                    srv_mms_bgsr_send_events(EVT_ID_SRV_BGSR_FALLBACK_CUI_CLOSE, g_srv_mms_bgsr_context.acct_id);
                    /* cui_cbm_bearer_fallback_close(g_srv_mms_bgsr_context.cbm_cui_id); */
                    if (g_srv_mms_bgsr_context.fallback_sim_id != 0)
                    {
                        srv_mms_refresh_profile_settings(g_srv_mms_bgsr_context.fallback_sim_id);
                        g_srv_mms_bgsr_context.fallback_sim_id = 0;
                    }
                }
            #endif /* __MMI_MMS_FALLBACK__ */ 

                result[i] = MMI_TRUE;
                if (msg_id[i] == g_srv_mms_bgsr_context.send_msg_id ||
                    msg_id[i] == g_srv_mms_bgsr_context.download_msg_id)
                {
                    MMI_TRACE(
                        MMI_INET_TRC_G6_MMS,
                        SRV_MMS_BGSR_ALREADY_A_DOWNLOAD_MSG,
                        g_srv_mms_bgsr_context.download_msg_id,
                        __LINE__);
                    MMI_TRACE(
                        MMI_INET_TRC_G6_MMS,
                        SRV_MMS_BGSR_ALREADY_A_SENDING_MSG,
                        g_srv_mms_bgsr_context.send_msg_id,
                        __LINE__);
                    result[i] = MMI_FALSE;
                }
                else
                {
                    local_msg = 0;
                    local_msg = srv_mms_bgsr_extract_q(msg_id[i], &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_q));

                    if (local_msg == 0)
                    {
                        local_msg = srv_mms_bgsr_extract_q(
                                        msg_id[i],
                                        &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q));

                        if (local_msg == 0)
                        {
                            local_msg = srv_mms_bgsr_get_q(msg_id[i], g_srv_mms_bgsr_context.srv_mms_bgsr_send_q);
                            if (local_msg)
                            {
                                if (!(srv_mms_bgsr_get_msg_array(local_msg)->msg_info & SRV_MMS_BGSR_IS_RR_INFO))
                                {
                                    local_msg = srv_mms_bgsr_extract_q(
                                                    msg_id[i],
                                                    &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_q));
                                }
                                else
                                {
                                    result[i] = MMI_FALSE;
                                    local_msg = 0;
                                }
                            }

                            if (local_msg == 0)
                            {
                                local_msg = srv_mms_bgsr_extract_q(
                                                msg_id[i],
                                                &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q));
                            }
                        }
                    }

                    if (local_msg != 0)
                    {
                        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MSG_FOUND_IN_Q, msg_id[i], __LINE__);

                        srv_mms_bgsr_get_msg_array(local_msg)->msg_id = 0;
                    #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
                        if (local_msg & SRV_MMS_BGSR_MEM_CARD_BIT)
                        {
                            srv_mms_bgsr_enqueue(local_msg, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_mem_q));
                        }
                        else
                    #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ /* #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
                            srv_mms_bgsr_enqueue(local_msg, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_q));
                    }
                }
            }
            srv_mms_bgsr_write_into_ph_mem_file();
        #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
            srv_mms_bgsr_write_into_mem_card_file();
        #endif /* #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
            if (change_msg_notify_callback)
            {
                change_msg_notify_callback(result);
            }

            break;
        }
        case SRV_MMS_BGSR_OP_MULTI_MOVE:
        {
            for (i = 0; i < msg_count; i++)
            {
            #ifdef __MMI_MMS_FALLBACK__
                if (msg_id[i] != 0 && (msg_id[i] == g_srv_mms_bgsr_context.fallback_send_id ||
                                       msg_id[i] == g_srv_mms_bgsr_context.fallback_download_id))
                {
                    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_DELETE_FALLBACK_SCREEN, msg_id[i], __LINE__);
                    srv_mms_bgsr_send_events(EVT_ID_SRV_BGSR_FALLBACK_CUI_CLOSE, g_srv_mms_bgsr_context.acct_id);
                    /* cui_cbm_bearer_fallback_close(g_srv_mms_bgsr_context.cbm_cui_id); */
                    if (g_srv_mms_bgsr_context.fallback_sim_id != 0)
                    {
                        srv_mms_refresh_profile_settings(g_srv_mms_bgsr_context.fallback_sim_id);
                        g_srv_mms_bgsr_context.fallback_sim_id = 0;
                    }
                }
            #endif /* __MMI_MMS_FALLBACK__ */ 

                result[i] = MMI_TRUE;
                if (msg_id[i] == g_srv_mms_bgsr_context.send_msg_id ||
                    msg_id[i] == g_srv_mms_bgsr_context.download_msg_id)
                {
                    MMI_TRACE(
                        MMI_INET_TRC_G6_MMS,
                        SRV_MMS_BGSR_ALREADY_A_DOWNLOAD_MSG,
                        g_srv_mms_bgsr_context.download_msg_id,
                        __LINE__);
                    MMI_TRACE(
                        MMI_INET_TRC_G6_MMS,
                        SRV_MMS_BGSR_ALREADY_A_SENDING_MSG,
                        g_srv_mms_bgsr_context.send_msg_id,
                        __LINE__);
                    result[i] = MMI_FALSE;
                }
                else
                {
                    local_msg = 0;
                    local_msg = srv_mms_bgsr_extract_q(msg_id[i], &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_q));

                    if (local_msg == 0)
                    {
                        local_msg = srv_mms_bgsr_extract_q(
                                        msg_id[i],
                                        &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q));
                    }
                    if (local_msg == 0)
                    {
                        local_msg = srv_mms_bgsr_get_q(msg_id[i], g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q);
                        if (local_msg != 0)
                        {

                            if (srv_mms_bgsr_get_msg_array(local_msg)->status != SRV_MMS_BGSR_STATUS_POSTPONE_FOR_SEND)
                            {
                                local_msg = srv_mms_bgsr_extract_q(
                                                msg_id[i],
                                                &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q));
                            }
                            local_msg = 0;
                        }
                    }
                }

                if (local_msg != 0)
                {
                    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MSG_FOUND_IN_Q, msg_id[i], __LINE__);
                    srv_mms_bgsr_get_msg_array(local_msg)->msg_id = 0;
                #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
                    if (local_msg & SRV_MMS_BGSR_MEM_CARD_BIT)
                    {
                        srv_mms_bgsr_enqueue(local_msg, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_mem_q));
                    }
                    else
                #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ /* #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
                        srv_mms_bgsr_enqueue(local_msg, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_q));

                }
            }
            srv_mms_bgsr_write_into_ph_mem_file();
        #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
            srv_mms_bgsr_write_into_mem_card_file();
        #endif /* #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */

            if (change_msg_notify_callback)
            {
                change_msg_notify_callback(result);
            }
            break;
        }

        default:
            break;
    }
}
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_change_msg_notify
 * DESCRIPTION
 *  handle the operation on the message
 * CALLS
 *  
 * PARAMETERS
 *  msg_id                          [IN]        Message id
 *  msg_operation_notify            [IN]        Operation
 *  msg_folder                      [IN]        The message folder
 *  change_msg_notify_callback      [IN]        The callback function
 *  storage_type                    [IN]        
 * RETURNS
 *  Result
 *****************************************************************************/
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
    /* Write your code here */

    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_CHANGE_MSG_NOTIFY, msg_operation_notify, __LINE__);

    switch (msg_operation_notify)
    {
        case SRV_MMS_BGSR_OP_DELETE:
        {
            U8 local_msg = 0;

        #ifdef __MMI_MMS_FALLBACK__
            if (msg_id == g_srv_mms_bgsr_context.fallback_send_id ||
                msg_id == g_srv_mms_bgsr_context.fallback_download_id)
            {
                MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_DELETE_FALLBACK_SCREEN, msg_id, __LINE__);
                srv_mms_bgsr_send_events(EVT_ID_SRV_BGSR_FALLBACK_CUI_CLOSE, g_srv_mms_bgsr_context.acct_id);
                /* cui_cbm_bearer_fallback_close(g_srv_mms_bgsr_context.cbm_cui_id); */
                if (g_srv_mms_bgsr_context.fallback_sim_id != 0)
                {
                    srv_mms_refresh_profile_settings(g_srv_mms_bgsr_context.fallback_sim_id);
                    g_srv_mms_bgsr_context.fallback_sim_id = 0;
                }
            }
        #endif /* __MMI_MMS_FALLBACK__ */ 

            if (msg_id == g_srv_mms_bgsr_context.send_msg_id || msg_id == g_srv_mms_bgsr_context.download_msg_id)
            {
                MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_THE_MSG_IS_TRANSMITTING, msg_id, __LINE__);
                if (change_msg_notify_callback != NULL)
                {
                    change_msg_notify_callback(msg_id, SRV_MMS_BGSR_RESULT_FAIL_FILE_IN_USE);
                }

                return SRV_MMS_BGSR_RESULT_FAIL_FILE_IN_USE;
            }

            switch (msg_folder)
            {
                case SRV_MMS_BGSR_FOLDER_INBOX:
                {
                    local_msg = srv_mms_bgsr_extract_q(msg_id, &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_q));

                    if (local_msg == 0)
                    {
                        local_msg = srv_mms_bgsr_extract_q(
                                        msg_id,
                                        &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q));
                        if (local_msg == 0)
                        {
                            local_msg = srv_mms_bgsr_extract_q(
                                            msg_id,
                                            &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q));

                            if (local_msg == 0)
                            {
                                local_msg = srv_mms_bgsr_extract_q(
                                                msg_id,
                                                &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_q));
                            }
                        }
                    }
                    break;
                }

                case SRV_MMS_BGSR_FOLDER_OUTBOX:
                case SRV_MMS_BGSR_FOLDER_ARCHIVE:
                {
                    local_msg = srv_mms_bgsr_extract_q(msg_id, &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_q));
                    if (local_msg == 0)
                    {
                        local_msg = srv_mms_bgsr_extract_q(msg_id, &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q));
                    }
                    break;
                }
            }

            if (local_msg == 0)
            {
                MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MSG_NOT_FOUND, __LINE__);
                srv_mms_bgsr_echo_current_info();
                if (change_msg_notify_callback != NULL)
                {
                    change_msg_notify_callback(msg_id, SRV_MMS_BGSR_RESULT_FAIL_FILE_NOT_FOUND);
                }
                res = SRV_MMS_BGSR_RESULT_FAIL_FILE_NOT_FOUND;
            }
            else
            {
                srv_mms_bgsr_get_msg_array(local_msg)->msg_id = 0;
            #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
                if (local_msg & SRV_MMS_BGSR_MEM_CARD_BIT)
                {
                    srv_mms_bgsr_enqueue(local_msg, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_mem_q));
                }
                else
            #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ /* #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
                    srv_mms_bgsr_enqueue(local_msg, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_q));
                /* send req to reset flag in case of read report */
                if (srv_mms_bgsr_get_msg_array(local_msg)->msg_info & SRV_MMS_BGSR_IS_RR_INFO)
                {
                    srv_mms_bgsr_set_rr_flag_req(msg_id, FALSE);
                }
                if (change_msg_notify_callback != NULL)
                {
                    change_msg_notify_callback(msg_id, SRV_MMS_BGSR_RESULT_OK);
                }
                res = SRV_MMS_BGSR_RESULT_OK;
            }
            break;
        }

        case SRV_MMS_BGSR_OP_MOVE_TO_FOLDER:
        {
            U8 local_msg = 0;

        #ifdef __MMI_MMS_FALLBACK__
            if (msg_id == g_srv_mms_bgsr_context.fallback_send_id ||
                msg_id == g_srv_mms_bgsr_context.fallback_download_id)
            {
                MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_DELETE_FALLBACK_SCREEN, msg_id, __LINE__);
                srv_mms_bgsr_send_events(EVT_ID_SRV_BGSR_FALLBACK_CUI_CLOSE, g_srv_mms_bgsr_context.acct_id);
                /* cui_cbm_bearer_fallback_close(g_srv_mms_bgsr_context.cbm_cui_id); */
                if (g_srv_mms_bgsr_context.fallback_sim_id != 0)
                {
                    srv_mms_refresh_profile_settings(g_srv_mms_bgsr_context.fallback_sim_id);
                    g_srv_mms_bgsr_context.fallback_sim_id = 0;
                }
            }
        #endif /* __MMI_MMS_FALLBACK__ */ 

            if (msg_id == g_srv_mms_bgsr_context.send_msg_id || msg_id == g_srv_mms_bgsr_context.download_msg_id)
            {
                MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_THE_MSG_IS_TRANSMITTING, msg_id, __LINE__);
                if (change_msg_notify_callback != NULL)
                {
                    change_msg_notify_callback(msg_id, SRV_MMS_BGSR_RESULT_FAIL_FILE_IN_USE);
                }

                return SRV_MMS_BGSR_RESULT_FAIL_FILE_IN_USE;
            }

            switch (msg_folder)
            {
                case SRV_MMS_BGSR_FOLDER_INBOX:
                {
                    local_msg = srv_mms_bgsr_extract_q(msg_id, &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_q));

                    if (local_msg == 0)
                    {
                        local_msg = srv_mms_bgsr_extract_q(
                                        msg_id,
                                        &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q));

                        if (local_msg == 0)
                        {
                            local_msg = srv_mms_bgsr_get_q(msg_id, g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q);
                            if (local_msg != 0)
                            {

                                if (srv_mms_bgsr_get_msg_array(local_msg)->status !=
                                    SRV_MMS_BGSR_STATUS_POSTPONE_FOR_SEND)
                                {
                                    local_msg = srv_mms_bgsr_extract_q(
                                                    msg_id,
                                                    &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q));
                                }
                                else
                                {
                                    local_msg = 0;
                                }
                            }
                        }
                    }
                    break;
                }
                case SRV_MMS_BGSR_FOLDER_OUTBOX:
                {
                    local_msg = srv_mms_bgsr_extract_q(msg_id, &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_q));
                    if (local_msg == 0)
                    {
                        local_msg = srv_mms_bgsr_extract_q(msg_id, &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q));
                    }
                    break;
                }
            }

            if (local_msg == 0)
            {
                MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MSG_NOT_FOUND, __LINE__);
                srv_mms_bgsr_echo_current_info();
                if (change_msg_notify_callback != NULL)
                {
                    change_msg_notify_callback(msg_id, SRV_MMS_BGSR_RESULT_FAIL_FILE_NOT_FOUND);
                }
                res = SRV_MMS_BGSR_RESULT_FAIL_FILE_NOT_FOUND;
            }
            else
            {

                srv_mms_bgsr_get_msg_array(local_msg)->msg_id = 0;
            #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
                if (local_msg & SRV_MMS_BGSR_MEM_CARD_BIT)
                {
                    srv_mms_bgsr_enqueue(local_msg, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_mem_q));
                }
                else
            #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ /* #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
                    srv_mms_bgsr_enqueue(local_msg, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_q));
                if (change_msg_notify_callback != NULL)
                {
                    change_msg_notify_callback(msg_id, SRV_MMS_BGSR_RESULT_OK);
                }
                /* file operation */
                res = SRV_MMS_BGSR_RESULT_OK;
            }

            break;
        }
        case SRV_MMS_BGSR_OP_FORMAT:
        {
        #ifdef MMS_IN_LARGE_STORAGE     /* To check if System Drive is used for MMS Storage (PISCES23 phone) */
            g_srv_mms_bgsr_context.srv_mms_bgsr_send_q
                = srv_mms_bgsr_delete_queue(&(g_srv_mms_bgsr_context.srv_mms_bgsr_send_q), 0);

            g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q
                = srv_mms_bgsr_delete_queue(&(g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q), 0);

            g_srv_mms_bgsr_context.srv_mms_bgsr_download_q
                = srv_mms_bgsr_delete_queue(&(g_srv_mms_bgsr_context.srv_mms_bgsr_download_q), 0);

            g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q
                = srv_mms_bgsr_delete_queue(&(g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q), 0);
            if (g_srv_mms_bgsr_context.download_msg_id != 0)
            {
                g_srv_mms_bgsr_context.download_msg_id = 0;
                MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_CLEAR_DOWNLOAD_ID);
            }

            if (g_srv_mms_bgsr_context.send_msg_id != 0)
            {
                g_srv_mms_bgsr_context.send_msg_id = 0;
                MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_CLEAR_SEND_ID);
            }

            g_srv_mms_bgsr_context.sync_flag = FALSE;

            srv_mms_bgsr_show_mms_status_icon(SRV_MMS_BGSR_INDICATOR_IDLE, SRV_MMS_BGSR_INDICATOR_NONE_OP);
            g_srv_mms_bgsr_context.send_sim_id = 0;
            g_srv_mms_bgsr_context.download_sim_id = 0;

            StartTimer(SRV_MMS_BGSR_TIMER, SRV_MMS_BGSR_FAST_TIMEOUT_TIMER, srv_mms_bgsr_timeout_procedure);

            if (change_msg_notify_callback != NULL)
            {
                change_msg_notify_callback(msg_id, SRV_MMS_BGSR_RESULT_OK);
            }
            res = SRV_MMS_BGSR_RESULT_OK;
        #endif /* MMS_IN_LARGE_STORAGE */ 
            break;
        }
        case SRV_MMS_BGSR_OP_DELETE_ALL_INBOX:
        {
        #ifdef __MMI_MMS_FALLBACK__
            if (g_srv_mms_bgsr_context.fallback_download_id != 0)
            {
                MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_DELETE_FALLBACK_SCREEN, 0, __LINE__);
                srv_mms_bgsr_send_events(EVT_ID_SRV_BGSR_FALLBACK_CUI_CLOSE, g_srv_mms_bgsr_context.acct_id);
                /* cui_cbm_bearer_fallback_close(g_srv_mms_bgsr_context.cbm_cui_id); */
                if (g_srv_mms_bgsr_context.fallback_sim_id != 0)
                {
                    srv_mms_refresh_profile_settings(g_srv_mms_bgsr_context.fallback_sim_id);
                    g_srv_mms_bgsr_context.fallback_sim_id = 0;
                }
            }
        #endif /* __MMI_MMS_FALLBACK__ */ 

            g_srv_mms_bgsr_context.srv_mms_bgsr_download_q
                = srv_mms_bgsr_delete_queue(
                    &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_q),
                    g_srv_mms_bgsr_context.download_msg_id);

            g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q
                = srv_mms_bgsr_delete_queue(
                    &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q),
                    g_srv_mms_bgsr_context.download_msg_id);

            if (change_msg_notify_callback != NULL)
            {
                change_msg_notify_callback(msg_id, SRV_MMS_BGSR_RESULT_OK);
            }
            res = SRV_MMS_BGSR_RESULT_OK;

            break;
        }
        case SRV_MMS_BGSR_OP_DELETE_ALL_OUTBOX:
        {

            U8 this_msg = 0;
            U8 next_msg = 0;
            srv_mms_bgsr_msg_struct *curr_node;

        #ifdef __MMI_MMS_FALLBACK__
            if (g_srv_mms_bgsr_context.fallback_send_id != 0)
            {
                MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_DELETE_FALLBACK_SCREEN, 0, __LINE__);
                srv_mms_bgsr_send_events(EVT_ID_SRV_BGSR_FALLBACK_CUI_CLOSE, g_srv_mms_bgsr_context.acct_id);
                /* cui_cbm_bearer_fallback_close(g_srv_mms_bgsr_context.cbm_cui_id); */
                if (g_srv_mms_bgsr_context.fallback_sim_id != 0)
                {
                    srv_mms_refresh_profile_settings(g_srv_mms_bgsr_context.fallback_sim_id);
                    g_srv_mms_bgsr_context.fallback_sim_id = 0;
                }
            }
        #endif /* __MMI_MMS_FALLBACK__ */ 
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
                {
                    srv_mms_bgsr_enqueue(this_msg, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_q));
                }
                this_msg = next_msg;

            }

            g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q
                = srv_mms_bgsr_delete_queue(
                    &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q),
                    g_srv_mms_bgsr_context.send_msg_id);
            if (change_msg_notify_callback != NULL)
            {
                change_msg_notify_callback(msg_id, SRV_MMS_BGSR_RESULT_OK);
            }
            res = SRV_MMS_BGSR_RESULT_OK;
            break;
        }
        case SRV_MMS_BGSR_OP_DELETE_ALL_ARCHIVE:
        {
            if (change_msg_notify_callback != NULL)
            {
                change_msg_notify_callback(msg_id, SRV_MMS_BGSR_RESULT_OK);
            }
            res = SRV_MMS_BGSR_RESULT_OK;

            break;
        }
        case SRV_MMS_BGSR_OP_CANCEL_ALL_INBOX:
        {
            if (g_srv_mms_bgsr_context.download_msg_id != 0)
            {
                U8 local_msg = 0;

                local_msg = srv_mms_bgsr_get_q(
                                g_srv_mms_bgsr_context.download_msg_id,
                                g_srv_mms_bgsr_context.srv_mms_bgsr_download_q);
                if (local_msg)
                {
                    srv_mms_bgsr_get_msg_array(local_msg)->msg_info |= SRV_MMS_BGSR_FAIL_FLAG_INFO;
                }
            }

            g_srv_mms_bgsr_context.srv_mms_bgsr_download_q
                = srv_mms_bgsr_delete_queue(
                    &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_q),
                    g_srv_mms_bgsr_context.download_msg_id);

            g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q
                = srv_mms_bgsr_delete_queue(&(g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q), 0);

            if (change_msg_notify_callback != NULL)
            {
                change_msg_notify_callback(msg_id, SRV_MMS_BGSR_RESULT_OK);
            }
            res = SRV_MMS_BGSR_RESULT_OK;
            break;
        }
        case SRV_MMS_BGSR_OP_CANCEL_ALL_OUTBOX:
        {
            g_srv_mms_bgsr_context.srv_mms_bgsr_send_q
                = srv_mms_bgsr_delete_queue(&(g_srv_mms_bgsr_context.srv_mms_bgsr_send_q), 0);

            g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q
                = srv_mms_bgsr_delete_queue(&(g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q), 0);

            if (change_msg_notify_callback != NULL)
            {
                change_msg_notify_callback(msg_id, SRV_MMS_BGSR_RESULT_OK);
            }
            res = SRV_MMS_BGSR_RESULT_OK;
            break;
        }

        default:
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_UNKNOWN_OPERATION, __LINE__);
            MMI_ASSERT(0);
            break;
        }
    }
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    if (storage_type == MMA_MSG_STORAGE_CARD1)
    {

        srv_mms_bgsr_write_into_mem_card_file();
    }
    else
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ /* #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
    {

        srv_mms_bgsr_write_into_ph_mem_file();
    }
    return res;
}

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_mem_card_plug_in_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_mem_card_plug_in_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_bgsr_mem_card_plug_in_hdlr();
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_mem_card_plug_out_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_mem_card_plug_out_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_bgsr_mem_card_plug_out_hdlr();

}
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ /* #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_show_mms_status_icon
 * DESCRIPTION
 *  To show MMS indicator icon
 * PARAMETERS
 *  status      [IN]        
 *  op_type     [IN]        
 * STATUS
 * RETURNS
 *  void
 *****************************************************************************/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

void srv_mms_bgsr_show_mms_status_icon(
        const srv_mms_bgsr_indicator_type_enum status,
        srv_mms_bgsr_indicator_op_enum op_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_SHOW_MMS_STATUS_ICON, status, op_type, __LINE__);
    switch (status)
    {
        case SRV_MMS_BGSR_INDICATOR_IDLE:
        {
            switch (op_type)
            {
                case SRV_MMS_BGSR_INDICATOR_NONE_OP:
                {
                    if (g_srv_mms_bgsr_context.immd_retr_sim_id != g_srv_mms_bgsr_context.send_sim_id &&
                        g_srv_mms_bgsr_context.send_sim_id != 0)
                    {
                        srv_mms_update_ui_status_icons(
                            g_srv_mms_bgsr_context.send_sim_id,
                            SRV_MMS_ICON_STATE_ACTION_HIDE);
                    }
                    if (g_srv_mms_bgsr_context.immd_retr_sim_id != g_srv_mms_bgsr_context.download_sim_id &&
                        g_srv_mms_bgsr_context.download_sim_id != 0)
                    {
                        srv_mms_update_ui_status_icons(
                            g_srv_mms_bgsr_context.download_sim_id,
                            SRV_MMS_ICON_STATE_ACTION_HIDE);
                    }
                    /* srv_mms_update_ui_status_icons(g_srv_mms_bgsr_context.immd_retr_sim_id,SRV_MMS_ICON_STATE_ACTION_HIDE); */
                    break;
                }
                case SRV_MMS_BGSR_INDICATOR_SEND_OP:
                {
                    if (g_srv_mms_bgsr_context.download_sim_id == 0 && g_srv_mms_bgsr_context.immd_retr_sim_id == 0)
                    {
                        srv_mms_update_ui_status_icons(
                            g_srv_mms_bgsr_context.send_sim_id,
                            SRV_MMS_ICON_STATE_ACTION_HIDE);
                    }
                    break;
                }
                case SRV_MMS_BGSR_INDICATOR_DOWNLOAD_OP:
                {
                    if (g_srv_mms_bgsr_context.send_sim_id == 0 && g_srv_mms_bgsr_context.immd_retr_sim_id == 0)
                    {
                        srv_mms_update_ui_status_icons(
                            g_srv_mms_bgsr_context.download_sim_id,
                            SRV_MMS_ICON_STATE_ACTION_HIDE);
                    }
                    break;
                }
                case SRV_MMS_BGSR_INDICATOR_IMMD_DOWNLOAD_OP:
                {
                    if (g_srv_mms_bgsr_context.send_sim_id == 0 && g_srv_mms_bgsr_context.download_sim_id == 0)
                    {
                        srv_mms_update_ui_status_icons(
                            g_srv_mms_bgsr_context.immd_retr_sim_id,
                            SRV_MMS_ICON_STATE_ACTION_HIDE);
                    }
                    break;
                }
                default:
                    break;
            }
            break;
        }
        case SRV_MMS_BGSR_INDICATOR_BUSY:
        {
            switch (op_type)
            {
                case SRV_MMS_BGSR_INDICATOR_SEND_OP:
                {
                    if (g_srv_mms_bgsr_context.download_sim_id == 0 && g_srv_mms_bgsr_context.immd_retr_sim_id == 0)
                    {
                        srv_mms_update_ui_status_icons(
                            g_srv_mms_bgsr_context.send_sim_id,
                            SRV_MMS_ICON_STATE_ACTION_BLINK);
                    }
                    break;
                }
                case SRV_MMS_BGSR_INDICATOR_DOWNLOAD_OP:
                {
                    if (g_srv_mms_bgsr_context.send_sim_id == 0 && g_srv_mms_bgsr_context.immd_retr_sim_id == 0)
                    {
                        srv_mms_update_ui_status_icons(
                            g_srv_mms_bgsr_context.download_sim_id,
                            SRV_MMS_ICON_STATE_ACTION_BLINK);
                    }
                    break;
                }
                case SRV_MMS_BGSR_INDICATOR_IMMD_DOWNLOAD_OP:
                {
                    if (g_srv_mms_bgsr_context.send_sim_id == 0 && g_srv_mms_bgsr_context.download_sim_id == 0)
                    {
                        srv_mms_update_ui_status_icons(
                            g_srv_mms_bgsr_context.immd_retr_sim_id,
                            SRV_MMS_ICON_STATE_ACTION_BLINK);
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
 *  srv_mms_bgsr_usb_start_cb
 * DESCRIPTION
 *  To handle interrupt end to retry to send and receive
 * PARAMETERS
 *  para            [?]         
 *  status(?)       [IN]        
 * STATUS
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_mms_bgsr_usb_start_cb(mmi_event_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_USB_START_CB, __LINE__);

    g_srv_mms_bgsr_context.storage_exported = 1;
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_usb_end_cb
 * DESCRIPTION
 *  To handle interrupt end to retry to send and receive
 * PARAMETERS
 *  para            [?]         
 *  status(?)       [IN]        
 * STATUS
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_mms_bgsr_usb_end_cb(mmi_event_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_mms_bgsr_context.storage_exported = 0;

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    if (g_srv_mms_bgsr_context.mem_card_state == SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_IN_PENDING)
    {
        if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) == FS_NO_ERROR)
        {
            srv_mms_bgsr_init_mem_card_file_system();
            srv_mms_bgsr_init_mem_card_msg_array();
            g_srv_mms_bgsr_context.mem_card_state = SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_IN;
        }
        else
        {
            g_srv_mms_bgsr_context.mem_card_state = SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_OUT;
        }
    }
    else
    {
        if (g_srv_mms_bgsr_context.bgsr_state & SRV_MMS_BGSR_STATE_MEM_CARD_FILE_OP_PENDING)
        {
            srv_mms_bgsr_write_into_mem_card_file();
        }
    }
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_drive_format_hdlr
 * DESCRIPTION
 *  To display the popup
 * PARAMETERS
 *  param       [?]     
 * STATUS
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_mms_bgsr_drive_format_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 drv_enum;
    srv_fmgr_notification_format_event_struct *format_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT:
            format_evt = (srv_fmgr_notification_format_event_struct*) param;
            if (format_evt->state == SRV_FMGR_NOTIFICATION_STATE_AFTER)
            {
                drv_enum = srv_fmgr_drv_get_type((U8) format_evt->drv_letter);
                srv_mms_bgsr_fmgr_format_notify(drv_enum);

            }
            break;
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_fmgr_format_notify
 * DESCRIPTION
 *  (U16 drive);
 *  echo current infomation
 * PARAMETERS
 *  drive       [IN]        
 * STATUS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_fmgr_format_notify(U16 drive)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (drive)
    {
        case SRV_FMGR_DRV_PHONE_TYPE:
        case SRV_FMGR_DRV_PHONE_2_TYPE:
        {
        #ifdef MMS_IN_LARGE_STORAGE
            srv_mms_bgsr_ph_mem_format_hdlr();
        #endif 
            break;
        }

    #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
        case SRV_FMGR_DRV_CARD_TYPE:
        {
            srv_mms_bgsr_mem_card_format_hdlr();
            break;
        }
    #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    }
}



/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_is_in_use
 * DESCRIPTION
 *  (kal_uint8 simId)
 *  echo current infomation
 * PARAMETERS
 *  simId       [IN]        
 * STATUS
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool srv_mms_bgsr_is_in_use(kal_uint8 simId)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 mma_sim_id = srv_mms_bgsr_convert_wap_sim_to_mma(simId);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_srv_mms_bgsr_context.send_msg_id != 0
         && g_srv_mms_bgsr_context.send_sim_id == mma_sim_id)
        || (g_srv_mms_bgsr_context.download_msg_id != 0 && g_srv_mms_bgsr_context.download_sim_id == mma_sim_id)
#ifdef __MMI_MMS_2__
#ifdef __MMI_UMMS_JSR205__
        || srv_mms_jsr_check_jsr_in_sending_state(mma_sim_id)
#endif 
#endif /* __MMI_MMS_2__ */ 
        || g_srv_mms_bgsr_context.immd_retr_sim_id == mma_sim_id)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_echo_current_info
 * DESCRIPTION
 *  echo current infomation
 * PARAMETERS
 *  void
 * STATUS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_echo_current_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msg;
    srv_mms_bgsr_msg_struct *curr_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        SRV_MMS_BGSR_ECHO_CURRENT_INFO_ID,
        g_srv_mms_bgsr_context.send_msg_id,
        g_srv_mms_bgsr_context.download_msg_id);
    msg = g_srv_mms_bgsr_context.srv_mms_bgsr_send_q;
    while (msg != 0)
    {
        curr_node = srv_mms_bgsr_get_msg_array(msg);
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_ECHO_CURRENT_INFO_SEND_Q);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            SRV_MMS_BGSR_ECHO_CURRENT_INFO_Q,
            curr_node->msg_id,
            curr_node->ntt,
            0,
            curr_node->status,
            curr_node->msg_info & SRV_MMS_BGSR_QUOTA_INFO,
            0,
            curr_node->msg_info & SRV_MMS_BGSR_SEND_AND_SAVE_INFO,
            curr_node->result,
            curr_node->msg_info & SRV_MMS_BGSR_FAIL_FLAG_INFO,
            0,
            curr_node->msg_info & SRV_MMS_BGSR_IS_RR_INFO,
            (curr_node->msg_info & SRV_MMS_BGSR_NO_OF_TRIES_INFO) >> 2);
        msg = *(srv_mms_bgsr_get_next_array(msg));
    }
    msg = g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q;
    while (msg != 0)
    {
        curr_node = srv_mms_bgsr_get_msg_array(msg);
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_ECHO_CURRENT_INFO_SEND_FAIL_Q);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            SRV_MMS_BGSR_ECHO_CURRENT_INFO_Q,
            curr_node->msg_id,
            curr_node->ntt,
            0,
            curr_node->status,
            curr_node->msg_info & SRV_MMS_BGSR_QUOTA_INFO,
            0,
            curr_node->msg_info & SRV_MMS_BGSR_SEND_AND_SAVE_INFO,
            curr_node->result,
            curr_node->msg_info & SRV_MMS_BGSR_FAIL_FLAG_INFO,
            0,
            curr_node->msg_info & SRV_MMS_BGSR_IS_RR_INFO,
            (curr_node->msg_info & SRV_MMS_BGSR_NO_OF_TRIES_INFO) >> 2);
        msg = *(srv_mms_bgsr_get_next_array(msg));
    }
    msg = g_srv_mms_bgsr_context.srv_mms_bgsr_download_q;
    while (msg != 0)
    {
        curr_node = srv_mms_bgsr_get_msg_array(msg);
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_ECHO_CURRENT_INFO_DL_Q);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            SRV_MMS_BGSR_ECHO_CURRENT_INFO_Q,
            curr_node->msg_id,
            curr_node->ntt,
            0,
            curr_node->status,
            curr_node->msg_info & SRV_MMS_BGSR_QUOTA_INFO,
            0,
            curr_node->msg_info & SRV_MMS_BGSR_SEND_AND_SAVE_INFO,
            curr_node->result,
            curr_node->msg_info & SRV_MMS_BGSR_FAIL_FLAG_INFO,
            0,
            curr_node->msg_info & SRV_MMS_BGSR_IS_RR_INFO,
            (curr_node->msg_info & SRV_MMS_BGSR_NO_OF_TRIES_INFO) >> 2);
        msg = *(srv_mms_bgsr_get_next_array(msg));
    }
    msg = g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q;
    while (msg != 0)
    {
        curr_node = srv_mms_bgsr_get_msg_array(msg);
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_ECHO_CURRENT_INFO_DL_FAIL_Q);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            SRV_MMS_BGSR_ECHO_CURRENT_INFO_Q,
            curr_node->msg_id,
            curr_node->ntt,
            0,
            curr_node->status,
            curr_node->msg_info & SRV_MMS_BGSR_QUOTA_INFO,
            0,
            curr_node->msg_info & SRV_MMS_BGSR_SEND_AND_SAVE_INFO,
            curr_node->result,
            curr_node->msg_info & SRV_MMS_BGSR_FAIL_FLAG_INFO,
            0,
            curr_node->msg_info & SRV_MMS_BGSR_IS_RR_INFO,
            (curr_node->msg_info & SRV_MMS_BGSR_NO_OF_TRIES_INFO) >> 2);
        msg = *(srv_mms_bgsr_get_next_array(msg));
    }
#ifdef __MMI_MMS_FALLBACK__
    if ((g_srv_mms_bgsr_context.fallback_mask & SRV_MMS_BGSR_FALLBACK_MASK_NEED_FALLBACK) ==
        SRV_MMS_BGSR_FALLBACK_MASK_NEED_FALLBACK)
    {
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            SRV_MMS_BGSR_ECHO_FALLBACK_INFO,
            g_srv_mms_bgsr_context.fallback_send_id,
            g_srv_mms_bgsr_context.fallback_download_id,
            g_srv_mms_bgsr_context.acct_id,
            g_srv_mms_bgsr_context.immd_retr_sim_id,
            g_srv_mms_bgsr_context.fallback_mask,
            __LINE__);
    }
#endif /* __MMI_MMS_FALLBACK__ */ 

}

#ifdef __DM_LAWMO_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_law_mo_wipe_notify
 * DESCRIPTION
 *  Deletes the bearer fallback screen from the history
 * PARAMETERS
 *  void
 * STATUS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_law_mo_wipe_notify(void)
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
    msg_req->msg_id = 0;
    msg_req->app_id = MMA_APP_ID_BGSR;
    msg_req->req_id = request_id;
    msg_req->rr_mark = 0;
    msg_req->rr_reset_all = KAL_TRUE;
    srv_mms_bgsr_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_RR_MARK_REQ),
        0,
        MSG_ID_WAP_MMA_RR_MARK_REQ,
        (oslParaType*) msg_req,
        NULL);

    g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q
        = srv_mms_bgsr_delete_queue(&(g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q), 0);
    g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q
        = srv_mms_bgsr_delete_queue(&(g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q), 0);
    g_srv_mms_bgsr_context.srv_mms_bgsr_send_q
        = srv_mms_bgsr_delete_queue(&(g_srv_mms_bgsr_context.srv_mms_bgsr_send_q), 0);
    g_srv_mms_bgsr_context.srv_mms_bgsr_download_q
        = srv_mms_bgsr_delete_queue(&(g_srv_mms_bgsr_context.srv_mms_bgsr_download_q), 0);

    if (g_srv_mms_bgsr_context.send_msg_id)
    {
        g_srv_mms_bgsr_context.lawmo_scomo_flag |= SRV_MMS_BGSR_LAWMO_SEND_MASK;
        srv_mms_bgsr_abort_send_mms_req(g_srv_mms_bgsr_context.send_msg_id);
    }

    if (g_srv_mms_bgsr_context.download_msg_id)
    {
        g_srv_mms_bgsr_context.lawmo_scomo_flag |= SRV_MMS_BGSR_LAWMO_DOWNLOAD_MASK;
        srv_mms_bgsr_abort_download_mms_req(g_srv_mms_bgsr_context.download_msg_id);
    }

    if (g_srv_mms_bgsr_context.lawmo_scomo_flag == 0)
    {
        mmi_umms_app_core_bgsr_free_mms_data_for_wipe_callback(MMA_RESULT_OK);
    }
}
#endif /* __DM_LAWMO_SUPPORT__ */ 

#ifdef __MMI_MMS_FALLBACK__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_discard_bearer_fallback
 * DESCRIPTION
 *  Deletes the bearer fallback screen from the history
 * PARAMETERS
 *  wap_prof_sim_id     [IN]        
 * STATUS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_discard_bearer_fallback(U8 wap_prof_sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_srv_mms_bgsr_context.fallback_mask & SRV_MMS_BGSR_FALLBACK_MASK_NEED_FALLBACK) ==
        SRV_MMS_BGSR_FALLBACK_MASK_NEED_FALLBACK)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_DELETE_FALLBACK_SCREEN, wap_prof_sim_id, __LINE__);
        srv_mms_bgsr_send_events(EVT_ID_SRV_BGSR_FALLBACK_CUI_CLOSE, g_srv_mms_bgsr_context.acct_id);
        /* cui_cbm_bearer_fallback_close(g_srv_mms_bgsr_context.cbm_cui_id); */
        if (g_srv_mms_bgsr_context.fallback_sim_id != 0)
        {
            srv_mms_refresh_profile_settings(g_srv_mms_bgsr_context.fallback_sim_id);
            g_srv_mms_bgsr_context.fallback_sim_id = 0;
        }
    }
}
#endif /* __MMI_MMS_FALLBACK__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_sim_status_info_hdlr
 * DESCRIPTION
 *  ;
 *  Handles Sim Status Info
 * CALLS
 *  
 * PARAMETERS
 *  evt     [?]     
 *  void *(?)
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_mms_bgsr_sim_status_info_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_availability_changed_evt_struct *sim_status;
    srv_mode_switch_notify_struct *mode_status;
    U8 bgsr_sim_id = 0;
    U8 i = 0;
    mmi_sim_enum mmi_sim_id = MMI_SIM_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt);

    switch (evt->evt_id)
    {
        case EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED:
        {
            sim_status = (srv_sim_ctrl_availability_changed_evt_struct*) evt;
            bgsr_sim_id = srv_mms_bgsr_convert_mmi_sim_id_to_bgsr_sim_id(sim_status->sim);
            if (bgsr_sim_id)
            {
                if (bgsr_sim_id & srv_mode_switch_get_current_mode())
                {
                    if (srv_sim_ctrl_is_available(sim_status->sim) ||
                        (srv_sim_ctrl_is_inserted(sim_status->sim) && !srv_sim_ctrl_chv1_is_blocked(sim_status->sim) &&
                         !srv_nw_info_sim_is_rejected(sim_status->sim)))
                    {
                        g_srv_mms_bgsr_context.is_sim_valid |= bgsr_sim_id;
                    }

                }
            }
            MMI_TRACE(
                MMI_INET_TRC_G6_MMS,
                SRV_MMS_BGSR_SIM_CTRL_AVAILABILITY_CHANGED,
                bgsr_sim_id,
                g_srv_mms_bgsr_context.is_sim_valid,
                __LINE__);
            break;
        }

        case EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY:
        {
            g_srv_mms_bgsr_context.is_sim_valid = 0;
            mode_status = (srv_mode_switch_notify_struct*) evt;
            for (i = 1; i <= MMA_MAX_SIM_COUNT; i++)
            {
                bgsr_sim_id = srv_mms_bgsr_convert_index(i);
                mmi_sim_id = srv_mms_bgsr_convert_bgsr_sim_id_to_mmi_sim_id(bgsr_sim_id);
                if (bgsr_sim_id & mode_status->gsm_select_mode)
                {
                    if (srv_sim_ctrl_is_available(mmi_sim_id) ||
                        (srv_sim_ctrl_is_inserted(mmi_sim_id) && !srv_sim_ctrl_chv1_is_blocked(mmi_sim_id) &&
                         !srv_nw_info_sim_is_rejected(mmi_sim_id)))
                    {
                        g_srv_mms_bgsr_context.is_sim_valid |= bgsr_sim_id;
                    }

                }
            }
            MMI_TRACE(
                MMI_INET_TRC_G6_MMS,
                SRV_MMS_BGSR_MODE_SWITCH_FINISH_NOTIFY,
                mode_status->gsm_select_mode,
                g_srv_mms_bgsr_context.is_sim_valid,
                __LINE__);
            break;
        }
        default:
            break;
    }
    return MMI_RET_OK;
}

#endif /* __MMI_MMS_BGSR_SUPPORT__ */ 

