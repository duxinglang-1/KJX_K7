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
 *  Queue.c
 *
 * Project:
 * --------
 *  MAUI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : Queue.c

   PURPOSE     : Task queue implementation functions 

   REMARKS     : nil

   AUTHOR      : Neeraj Sharma

   DATE     : Dec' 28, 2002

**************************************************************/

/*****************************************************************************
* Include                                                                     
*****************************************************************************/
#include "MMI_features.h"
//#include "mmi_frm_gprot.h"
#include "mmi_frm_prot.h"

//RHR Add
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "MMIDataType.h"
#include "kal_public_api.h"
#include "stack_ltlcom.h"
#include "string.h"
#include "stack_config.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "MMI_fw_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_fw_trc.h"
#include "kal_general_types.h"
/*****************************************************************************
* Define                                                                      
*****************************************************************************/
#ifndef __MTK_TARGET__
#define __align(x)
#endif 


/* 
 * Because MMI task will receive extQ message into circular queue,
 * we increase the circular queue size from 30 to 50
 */

/*****************************************************************************
* Typedef                                                                     
*****************************************************************************/

/*****************************************************************************
* Local Variable                                                              
*****************************************************************************/

/*****************************************************************************
* Extern Global Variable                                                      
*****************************************************************************/

__align(4)
MYQUEUE circq_array[CIRCQ_NO_OF_NODES];
U8 circq_read = 0, circq_write = 0, circq_messages = 0, max_circq_messages = 0;


/*****************************************************************************
* Local Function                                                              
*****************************************************************************/

/*****************************************************************************
* Extern Global Function                                                      
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_send_ext_queue
 * DESCRIPTION
 *  sned message to the task external queue
 * PARAMETERS
 *  message         [IN]    MYQUEUE message pointer 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_send_ext_queue(MYQUEUE *message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;
    U8 ref_count;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* check ref_count of local para */
    if (message->local_para_ptr != NULL)
    {
        ref_count = message->local_para_ptr->ref_count;              
        EXT_ASSERT(ref_count != 0, (int)message->src_mod_id, 
                    (int)message->dest_mod_id, (int)message->msg_id);

    }
        
    ilm_ptr = message;
    if (ilm_ptr->oslSrcId == MOD_MMI &&
        ilm_ptr->oslDestId == MOD_L4C)
    {
        ilm_ptr->sap_id = MMI_L4C_SAP;
    }
    else if (ilm_ptr->oslSrcId == MOD_MMI &&
             ilm_ptr->oslDestId == MOD_MMI)
    {
        ilm_ptr->sap_id = MMI_MMI_SAP;
    }
#ifdef __MMI_FILE_MANAGER__    
    else if (ilm_ptr->oslSrcId == MOD_MMI &&
             ilm_ptr->oslDestId == MOD_FMT)
    {
        ilm_ptr->sap_id = MMI_FMT_SAP;
    }
#endif
    else if (ilm_ptr->oslSrcId == MOD_MMI &&
             ilm_ptr->oslDestId == MOD_ABM)
    {
        ilm_ptr->sap_id = MMI_ABM_SAP;
    }
    else if (ilm_ptr->oslSrcId == MOD_MMI &&
             ilm_ptr->oslDestId == MOD_J2ME)
    {
        ilm_ptr->sap_id = MMI_J2ME_SAP;
    }
    else if (ilm_ptr->oslSrcId == MOD_MMI &&
             ilm_ptr->oslDestId == MOD_JASYN)
    {
        ilm_ptr->sap_id = MMI_JASYN_SAP;
    }
    else if (ilm_ptr->oslSrcId == MOD_MMI &&
             ilm_ptr->oslDestId == MOD_SYNCML)
    {
        ilm_ptr->sap_id = MMI_SYNCML_SAP;
    }
    else if (ilm_ptr->oslSrcId == MOD_MMI &&
             ilm_ptr->oslDestId == MOD_WAP)
    {
        ilm_ptr->sap_id = MMI_WAP_SAP;
    }
    else if (ilm_ptr->oslSrcId == MOD_WAP &&
             ilm_ptr->oslDestId == MOD_MMI)
    {
        ilm_ptr->sap_id = WAP_MMI_SAP;
    }
    else
    {
        ilm_ptr->sap_id = INVALID_SAP;
    }
    msg_send(ilm_ptr);
}


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
void mmi_frm_send_ilm(oslModuleType dest_mod_id, oslMsgType msg_id, 
                        oslParaType *local_para, oslPeerBuffType *peer_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE ilm;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm.oslSrcId = MOD_MMI;
    ilm.oslDestId = dest_mod_id;
    ilm.oslMsgId = msg_id;
    ilm.oslDataPtr = local_para;
    ilm.oslPeerBuffPtr = peer_buff;
    OslMsgSendExtQueue(&ilm);
}


/*****************************************************************************
 * FUNCTION
 *  OslReadCircularQ
 * DESCRIPTION
 *  Reads from Circ Queue
 *  
 *  Not used now
 * PARAMETERS
 *  msgPtr      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 OslReadCircularQ(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_QUEUE_READ_CQ, circq_messages);
    if (circq_messages == 0)
    {
        return 0;
    }
    memcpy(msgPtr, circq_array + circq_read, sizeof(MYQUEUE));
    if (++circq_read == CIRCQ_NO_OF_NODES)
    {
        circq_read = 0;
    }
    --circq_messages;
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  OslLookUpLastCircularQMsg
 * DESCRIPTION
 *  Look up the last message in Circ Queue
 *  
 *  Not used now
 * PARAMETERS
 *  msgPtr      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 OslLookUpLastCircularQMsg(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 last_read_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == msgPtr)
        return 0;
    
    if (circq_messages > 0)
    {
        if (circq_write == 0)
        {
            last_read_index = CIRCQ_NO_OF_NODES - 1;
        }
        else
        {
            last_read_index = circq_write - 1;
        }
        memcpy(msgPtr, circq_array + last_read_index, sizeof(MYQUEUE));
        return 1;
    }
    else
    {
        memset(msgPtr, 0, sizeof(MYQUEUE));
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  OslWriteCircularQ
 * DESCRIPTION
 *  Writes to Circ Queue
 *  
 *  Not used now
 * PARAMETERS
 *  msgPtr      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 OslWriteCircularQ(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_QUEUE_WRITE_CQ, circq_messages, ((MYQUEUE *)msgPtr)->msg_id);
    if (circq_messages == CIRCQ_NO_OF_NODES)
    {
        MMI_ASSERT(0);
        return 0;
    }
    memcpy(circq_array + circq_write, msgPtr, sizeof(MYQUEUE));
    if (++circq_write == CIRCQ_NO_OF_NODES)
    {
        circq_write = 0;
    }
    ++circq_messages;
    if (max_circq_messages < circq_messages)
    {
        max_circq_messages = circq_messages;
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  OslNumOfCircularQMsgs
 * DESCRIPTION
 *  Get the message number
 *  
 *  Not used now
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 OslNumOfCircularQMsgs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return circq_messages;
}


/*****************************************************************************
 * FUNCTION
 *  OslIsCircularQFull
 * DESCRIPTION
 *  Check if Circ Queue is full
 *  
 *  Not used now
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 OslIsCircularQFull(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (circq_messages == CIRCQ_NO_OF_NODES);
}



MYQUEUE* OslGetCircularArray(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return circq_array;
}


U32 mmi_frm_queue_get_number(mmi_frm_queue_type_enum type)
{
    U32 ext_queue_num = 0;
    U32 circular_queue_num = 0;
    ext_queue_num = msg_get_extq_messages();
    circular_queue_num = OslNumOfCircularQMsgs();
    
    if (type == MMI_FRM_EXT_QUEUE)
    {
        return ext_queue_num;
    }
    else if (type == MMI_FRM_CIRCULAR_QUEUE)
    {
        return circular_queue_num;
    }
    else if (type == MMI_FRM_ALL_QUEUE)
    {
        return ext_queue_num + circular_queue_num;
    }
    else
    {
        MMI_ASSERT(0);
        return 0;
    }    
}
