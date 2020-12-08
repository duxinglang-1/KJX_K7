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
 * mmi_frm_queue_gprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for message queue handle.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef MMI_FRM_QUEUE_GPROT_H
#define MMI_FRM_QUEUE_GPROT_H
#ifndef _QUEUE_GPROT_INT_H


//RHR Add

#include "app_ltlcom.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "DebugInitDef_Int.h"
#include "stack_ltlcom.h"
//#include "kal_active_module.h"
#include "MMIDataType.h"

#ifdef _QUEUE_GPROT_INT_H
#error should include mmi_frm_queue_gprot.h to substitute QueueGprot_Int.h
#endif

#define _QUEUE_GPROT_H
#define _QUEUE_GPROT_INT_H

/***************************************************************************** 
* Define
*****************************************************************************/

/* Define Message struct. */
#define MYQUEUE         ilm_struct

/* Define Message queue id type. */
#define oslMsgqid       kal_msgqid

/* Define module type. */
#define oslModuleType   module_type

/* Define Message type. */
#define oslMsgType      msg_type

/* Define local parameter type. */
#define oslParaType     local_para_struct

/* Define peer buff type. */
#define oslPeerBuffType peer_buff_struct

/* Define Message source module ID. */
#define oslSrcId        src_mod_id

/* Define Message destination module ID. */
#define oslDestId       dest_mod_id

/* Define Message ID. */
#define oslMsgId        msg_id

/* Define sap ID. */
#define oslSapId        sap_id

/* Define local parameter pointer. */
#define oslDataPtr      local_para_ptr

/* Define peerbuffer pointer. */
#define oslPeerBuffPtr  peer_buff_ptr

/* DOM-NOT_FOR_SDK-BEGIN */
/*
 * This is deprecated API: OslMsgSendExtQueue; 
 * Please use mmi_msg_send_ext_queue to send the message to external queue.
 */
#define OslMsgSendExtQueue      mmi_msg_send_ext_queue
#define OslIntMsgSendExtQueue   mmi_msg_send_ext_queue

/*
 * This is deprecated API: OslConstructDataPtr; 
 * Please use mmi_construct_msg_local_para to construct the local parameter of the message. 
 */
#define OslConstructDataPtr     mmi_construct_msg_local_para
#define OslIntConstructDataPtr  mmi_construct_msg_local_para

/*
 * construct the local parameter of the message through the data type
 */
#define OslAllocDataPtr(type)   ((type*)mmi_construct_msg_local_para(sizeof(type)))

/*
 * This is deprecated API: OslFreeDataPtr; 
 * Please use mmi_free_msg_local_para to free the local parameter of the message. 
 */
#define OslFreeDataPtr          mmi_free_msg_local_para
#define OslIntFreeDataPtr       mmi_free_msg_local_para

/*
 * This is deprecated API: OslFreeInterTaskMsg; 
 * Please use mmi_free_msg to free the message.
 */
#define OslFreeInterTaskMsg     mmi_free_msg
/* DOM-NOT_FOR_SDK-END */

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef enum
{
    MMI_FRM_EXT_QUEUE,
    MMI_FRM_CIRCULAR_QUEUE,
    MMI_FRM_ALL_QUEUE,
    
    MMI_FRM_QUEUE_MAX
} mmi_frm_queue_type_enum;

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/


/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_send_ext_queue
 * DESCRIPTION
 *  The function is to send message to the task external queue
 * PARAMETERS
 *  message    : [IN]    MYQUEUE message pointer. 
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_msg_send_ext_queue(MYQUEUE *message);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_send_ilm
 * DESCRIPTION
 *  The function is to send message to the task external queue
 * PARAMETERS
 *  dest_mod_id    : [IN] Destination module ID of the message.
 *  msg_id         : [IN] The inter layer message type exchanged between the modules.
 *  local_para     : [IN] Pointer to the memory location that contains the local parameters of the ILM.
 *  peer_buff      : [IN] Pointer to the buffer that contains the peer message.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_send_ilm(oslModuleType dest_mod_id, oslMsgType msg_id, 
                        oslParaType *local_para, oslPeerBuffType *peer_buff);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mmi_construct_msg_local_para
 * DESCRIPTION
 *  Construct the local parameter of the message
 * PARAMETERS
 *  size   : [IN]   The size of local parameter of MYQUEUE
 * RETURNS
 *  The local parameter pointer
 *****************************************************************************/
#define mmi_construct_msg_local_para(size)  construct_local_para((kal_uint16)(size), (TD_CTRL | TD_RESET))

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  OslHoldDataPtr
 * DESCRIPTION
 *  Hold data buffer (local parameter buffer)
 * PARAMETERS
 *  ptr       : [IN]        Pointer to data buffer
 * RETURNS
 *  none
 *****************************************************************************/
#define OslHoldDataPtr(ptr)                                         \
    do {                                                            \
        MMI_ASSERT(((local_para_struct*)(ptr))->ref_count != 0);    \
        hold_local_para((local_para_struct*)(ptr));                 \
    } while(0)
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mmi_free_msg_local_para
 * DESCRIPTION
 *  Free local parameter of MYQUEUE
 * PARAMETERS
 *  ptr     : [IN]    Local parameter pointer of MYQUEUE
 * RETURNS
 *  void
 *****************************************************************************/
#define mmi_free_msg_local_para(ptr)  free_local_para((local_para_struct *)(ptr))

/*****************************************************************************
 * FUNCTION
 *  mmi_free_msg
 * DESCRIPTION
 *  Free task message
 * PARAMETERS
 *  message   : [IN]    MYQUEUE message pointer
 * RETURNS
 *  void
 *****************************************************************************/
#define mmi_free_msg(message)   destroy_ilm((ilm_struct *)(message))

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  OslReceiveMsgExtQ
 * DESCRIPTION
 *  Receive message from external queue
 * PARAMETERS
 *  msgqid      [IN]    message queue id to read (type: oslMsgqid)
 *  Message     [OUT]   pointer to message structure (type: MYQUEUE *)
 * RETURNS
 *  success (0) or not (non zero)
 *****************************************************************************/
#define OslReceiveMsgExtQ(msgqid, Message)  \
            receive_msg_ext_q(msgqid, Message)


/*****************************************************************************
 * FUNCTION
 *  OslGetMyTaskIndex
 * DESCRIPTION
 *  Get task index
 * PARAMETERS
 *  index   : [OUT]     Pointer to task index data buffer(type: U32 *).
 * RETURNS
 *  void
 *****************************************************************************/
#define OslGetMyTaskIndex(index)    \
            kal_get_my_task_index(index)


/*****************************************************************************
 * FUNCTION
 *  OslStackSetActiveModuleID
 * DESCRIPTION
 *  Set active module id
 * PARAMETERS
 *  task_index     : [IN]   Task index to set (type: U32).
 *  module_id      : [IN]   Active module id (type: oslModuleType).
 * RETURNS
 *  void
 *****************************************************************************/
#define OslStackSetActiveModuleID(task_index, module_id)    \
            stack_set_active_module_id(task_index, module_id)


/*****************************************************************************
 * FUNCTION
 *  OslCreateMsgQ
 * DESCRIPTION
 *  Creates Message Queue
 * PARAMETERS
 *  queue_name        :[IN]     Queue name.(type: PS8)   
 *  max_msg_size      :[IN]     The max message size.(type: U32)   
 *  max_msgs          :[IN]     The max number of messages.(type: U32)   
 * RETURNS
 *  The message queue id (type: oslMsgqid)
 *****************************************************************************/
#define OslCreateMsgQ(queue_name, max_msg_size, max_msgs)   \
            kal_create_msg_q(queue_name, max_msg_size, max_msgs)


/*****************************************************************************
 * FUNCTION
 *  OslDeleteMsgQ
 * DESCRIPTION
 *  Deletes Message Queue
 * PARAMETERS
 *  msgqid     :[IN]   Message queue id(type: oslMsgqid)  
 * RETURNS
 *  void
 *****************************************************************************/
#define OslDeleteMsgQ(msgqid)   \
            kal_delete_msg_q(msgqid)


/*****************************************************************************
 * FUNCTION
 *  OslWriteMsgQ
 * DESCRIPTION
 *  Writes to Message Queue
 * PARAMETERS
 *  msgqid          :[IN]   Message queue id(type: oslMsgqid)
 *  msgPtr          :[IN]   Pointer to message(type: void *)  
 *  msgSize         :[IN]   Message size(type: U32)
 *  wait_mode       :[IN]   OSL_NO_WAIT or OSL_INFINITE_WAIT (type: OSLWAITMODE)
 *  message_to_head :[IN]   Write to queue head or not (type: MMI_BOOL)
 * RETURNS
 *  status (type: OSLSTATUS)
 *****************************************************************************/
#define OslWriteMsgQ(msgqid, msgPtr, msgSize, wait_mode, message_to_head)   \
            kal_enque_msg(msgqid, msgPtr, msgSize, wait_mode, message_to_head)


/*****************************************************************************
 * FUNCTION
 *  OslReadMsgQ
 * DESCRIPTION
 *  Reades from Message Queue
 * PARAMETERS
 *  msgqid          [IN]        message queue id (type: oslMsgqid)  
 *  msgPtr          [OUT]       pointer to message (type: void *) 
 *  msgSize         [OUT]       pointer to message size (type: U16 *)  
 *  wait_mode       [IN]        OSL_NO_WAIT or OSL_INFINITE_WAIT (type: OSLWAITMODE)
 * RETURNS
 *  status (type: OSLSTATUS)
 *****************************************************************************/
#define OslReadMsgQ(msgqid, msgPtr, msgSize, wait_mode)     \
            kal_deque_msg(msgqid, msgPtr, msgSize, wait_mode)


/* internal (circular) queue */

/*****************************************************************************
 * FUNCTION
 *  OslReadCircularQ
 * DESCRIPTION
 *  Reads from Circ Queue
 *  Not used now
 * PARAMETERS
 *  msgPtr:      [OUT]       pointer to message   
 * RETURNS
 *  success (1) or not (0)
 *****************************************************************************/
extern U8 OslReadCircularQ(void *msgPtr);


/*****************************************************************************
 * FUNCTION
 *  OslLookUpLastCircularQMsg
 * DESCRIPTION
 *  Look up the last message in Circular Queue
 * PARAMETERS
 *  msgPtr:      [IN]        pointer to message     
 * RETURNS
 *  success (1) or not (0)
 *****************************************************************************/
extern U8 OslLookUpLastCircularQMsg(void *msgPtr);


/*****************************************************************************
 * FUNCTION
 *  OslWriteCircularQ
 * DESCRIPTION
 *  Writes to Circ Queue
 * PARAMETERS
 *  msgPtr:      [IN]        pointer to message     
 * RETURNS
 *  success (1) or not (0)
 *****************************************************************************/
extern U8 OslWriteCircularQ(void *msgPtr);


/*****************************************************************************
 * FUNCTION
 *  OslNumOfCircularQMsgs
 * DESCRIPTION
 *  Get the message number
 * PARAMETERS
 *  void
 * RETURNS
 *  no. of messages in circular queue
 *****************************************************************************/
extern U8 OslNumOfCircularQMsgs(void);


/*****************************************************************************
 * FUNCTION
 *  OslIsCircularQFull
 * DESCRIPTION
 *  Check if Circular Queue is full.
 * PARAMETERS
 *  void
 * RETURNS
 *  full (TRUE) or empty (FALSE)
 *****************************************************************************/
extern U8 OslIsCircularQFull(void);

U32 mmi_frm_queue_get_number(mmi_frm_queue_type_enum type);
/* DOM-NOT_FOR_SDK-END */

#endif /* _QUEUE_GPROT_INT_H */ 
#endif /* MMI_FRM_QUEUE_GPROT_H */ 


