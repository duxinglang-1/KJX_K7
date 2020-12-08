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

/*******************************************************************************
 * Filename:
 * ---------
 * vmappcomm.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   MRE application communication mechanism, ie. MRE message queue
 *
 * Author:
 * -------
 *  
 *
*==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
#include "vmswitch.h"
#ifdef __MRE_CORE_APP_COMMUNICATION__

#include "vmsys.h"
#include "vmappcomm.h"
#include "vmpromng.h"
#include "vmpromnginner.h"

extern VMINT mre_running;

static vm_message_queue_struct vm_message_queue;
static vm_message_queue_struct* vm_message_queue_p = &vm_message_queue;
static vm_message_proc_mapping_struct vm_message_mapping_table[VM_APPCOMM_MAPPING_TABLE_SIZE];
static VMINT vm_appcomm_add_msg(vm_message_struct msg);


/*****************************************************************************
 * FUNCTION
 *  vm_appcomm_init
 * DESCRIPTION
 *  initialize MRE message queue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vm_appcomm_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    memset(vm_message_queue_p,0,sizeof(vm_message_queue));
    memset(vm_message_mapping_table,0,sizeof(vm_message_mapping_table));
}


/*****************************************************************************
* FUNCTION
 *    vm_send_msg
 * DESCRIPTION
 *  send message to MRE app or native app, will invoke message procedure directly.
 * PARAMETERS
 *  phandle : [IN] receiver process handle, if receiver is native application, this value should be zero.
 *  msg_id : [IN] user defined message ID, should larger than VM_MESSAGE_ID_BASE.
 *  wparam : [IN] wparam of message.
 *  lparam : [IN] lparam of message.
 * RETURNS
 *  message procedure return value.
*****************************************************************************/
VMINT vm_send_msg(VM_P_HANDLE phandle, VMUINT msg_id, VMINT wparam, VMINT lparam)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VM_P_HANDLE sender = vm_pmng_get_current_handle();
    VMINT i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    {
        if (phandle == 0)
        {
            /* receiver is native application */
            for (i=0; i<VM_APPCOMM_MAPPING_TABLE_SIZE; i++)
            {
                if ((vm_message_mapping_table[i].proc != NULL)&&(vm_message_mapping_table[i].sender == sender||
                    vm_message_mapping_table[i].sender == 0))
                {
                    vm_message_mapping_table[i].proc(sender, msg_id, wparam, lparam);
                }
            }

            return 1;
        }

        else
        {
            /* invoke receiver's message proc directly */
            return vm_pmng_exec_msg_proc(sender, phandle, msg_id, wparam, lparam);
        }
    }
}


/*****************************************************************************
* FUNCTION
 *    vm_post_msg
 * DESCRIPTION
 *  post message to MRE app or native app, will put this message to the end of MRE message queue. 
 *  when this function call finish, MMI task will dispatch MRE message and invoke message procedure. 
 * PARAMETERS
 *  phandle : [IN] receiver process handle, if receiver is native application, this value should be zero.
 *  msg_id : [IN] user defined message ID, should larger than VM_MESSAGE_ID_BASE.
 *  wparam : [IN] wparam of message.
 *  lparam : [IN] lparam of message.
 * RETURNS
 *  message procedure return value.
*****************************************************************************/
VMINT vm_post_msg(VM_P_HANDLE phandle, VMUINT msg_id, VMINT wparam, VMINT lparam)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_message_struct msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_id == VM_MESSAGE_INVALID_ID)
    {
        return 0;
    }

    msg.sender = vm_pmng_get_current_handle();
    msg.receiver = phandle;
    msg.msg_id = msg_id;
    msg.wparam = wparam;
    msg.lparam = lparam;
    
    return vm_appcomm_add_msg(msg);
}


/*****************************************************************************
* FUNCTION
 *    vm_appcomm_queue_is_full
 * DESCRIPTION
 *  check the message queue is full or not.
 * RETURNS
 *  0 not full.
 *  1 full
*****************************************************************************/
VMINT vm_appcomm_queue_is_full(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((vm_message_queue_p->head == vm_message_queue_p->tail) 
        && (vm_message_queue_p->message[vm_message_queue_p->head].msg_id != VM_MESSAGE_INVALID_ID))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}





/*****************************************************************************
* FUNCTION
 *    vm_appcomm_add_msg
 * DESCRIPTION
 *  add a message to MRE message queue.
 * PARAMETERS
 *  sender : [IN] sender process handle, if sender is native application or MRE framework, this value should be zero.
 *  receiver : [IN] receiver process handle, if receiver is native application, this value should be zero.
 *  msg_id : [IN] user defined message ID, should larger than VM_MESSAGE_ID_BASE.
 *  wparam : [IN] wparam of message.
 *  lparam : [IN] lparam of message.
 * RETURNS
 *  0 message queue full.
 *  1 add successfully
*****************************************************************************/
static VMINT vm_appcomm_add_msg(vm_message_struct msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (!vm_appcomm_queue_is_full())
    {
        vm_message_queue_p->message[vm_message_queue_p->tail] = msg;
        
        vm_message_queue_p->tail ++;
        if (vm_message_queue_p->tail == VM_APPCOMM_MESSAGE_QUEUE_SIZE)
        {
            vm_message_queue_p->tail = 0;
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

#endif /* __MRE_CORE_APP_COMMUNICATION__ */


/*****************************************************************************
* FUNCTION
 *    vm_appcomm_dispatch_msg
 * DESCRIPTION
 *  dispatch MRE message in MMI task.
*****************************************************************************/
void vm_appcomm_dispatch_msg(void)
{
#if defined(__MRE_CORE_APP_COMMUNICATION__) && !defined(__MMI_MRE_DISABLE_APPCOMM__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT sender;
    VMINT receiver;
    VMUINT msg_id;
    VMINT wparam;
    VMINT lparam;
    VMINT i;
    VMINT queue_number = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    {
        if (vm_appcomm_queue_is_full())
        {
            queue_number = VM_APPCOMM_MESSAGE_QUEUE_SIZE;
        }
        else
        {
            queue_number = vm_message_queue_p->tail - vm_message_queue_p->head;
            if (queue_number < 0)
            {
                queue_number = VM_APPCOMM_MESSAGE_QUEUE_SIZE + queue_number;
            }
        }

        while ((!vm_appcomm_queue_is_empty()) && (queue_number != 0))
        {
            /* We only handle QUEUE_SIZE msgs one time, avoid always loop here */
            queue_number--;

            sender = vm_message_queue_p->message[vm_message_queue_p->head].sender;
            receiver = vm_message_queue_p->message[vm_message_queue_p->head].receiver;
            msg_id = vm_message_queue_p->message[vm_message_queue_p->head].msg_id;
            wparam = vm_message_queue_p->message[vm_message_queue_p->head].wparam;
            lparam = vm_message_queue_p->message[vm_message_queue_p->head].lparam;
            
            if (msg_id != VM_MESSAGE_INVALID_ID)
            {
                /* set msg_id as invalid id after get message */
                vm_message_queue_p->message[vm_message_queue_p->head].msg_id = VM_MESSAGE_INVALID_ID;

                if (receiver == 0)
                {
                    /* receiver is native application */
                    for (i=0; i<VM_APPCOMM_MAPPING_TABLE_SIZE; i++)
                    {
                        /* sender == 0 means handling all messages */
                        if ((vm_message_mapping_table[i].proc != NULL)&&(vm_message_mapping_table[i].sender == sender||
                            vm_message_mapping_table[i].sender == 0))
                        {
                            vm_message_mapping_table[i].proc(sender, msg_id, wparam, lparam);
                        }
                    }
                }
                else
                {
                    /* invoke message proc */
                    if (msg_id < VM_MESSAGE_ID_BASE)
                    {
                        vm_pmng_exec_sysevent_handler(receiver, msg_id, wparam);
                    }
                    else
                    {
                        vm_pmng_exec_msg_proc(sender, receiver, msg_id, wparam, lparam);
                    }
                }
            }
            
            vm_message_queue_p->head ++;
			if (vm_message_queue_p->head == VM_APPCOMM_MESSAGE_QUEUE_SIZE)
			{
				vm_message_queue_p->head = 0;
			}

        }
        mmi_frm_invoke_post_event();
    }
#else /* __MRE_CORE_APP_COMMUNICATION__ */
    return ;
#endif /* __MRE_CORE_APP_COMMUNICATION__ */
}


/*****************************************************************************
 * FUNCTION
 *  vm_appcomm_reg_msg_proc
 * DESCRIPTION
 *  register MRE message proc
 * PARAMETERS
 *  handle : [IN] message sender handle, if despite of sender, this parameter should be set to zero.
 *  proc : [IN] message proc
 * RETURNS
 *  1 if register successfully
 *  0 if register failed
 *****************************************************************************/
VMINT vm_appcomm_reg_msg_proc(VMINT handle, VM_MESSAGE_PROC proc)
{
#ifdef __MRE_CORE_APP_COMMUNICATION__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* if message proc is NULL, resigster failed. */
    if (proc == NULL)
    {
        return 0;
    }

    /* search for a empty cell for keep native application message proc.  */
    for (i=0; i<VM_APPCOMM_MAPPING_TABLE_SIZE; i++)
    {
        if (vm_message_mapping_table[i].proc == NULL)
        {
            break;
        }
    }
    if (i == VM_APPCOMM_MAPPING_TABLE_SIZE)
    {   
        /* mapping table full */
        return 0;
    }
    else
    {
        vm_message_mapping_table[i].sender = handle;
        vm_message_mapping_table[i].proc  = proc;
        return 1;
    }

    
#else /* __MRE_CORE_APP_COMMUNICATION__ */
        return 0;
#endif /* __MRE_CORE_APP_COMMUNICATION__ */
}


/*****************************************************************************
 * FUNCTION
 *  vm_appcomm_dereg_msg_proc
 * DESCRIPTION
 *  deregister MRE message proc
 * PARAMETERS
 *  handle : [IN] message sender handle, if despite of sender, this parameter should be set to zero.
 *  proc : [IN] message proc
 * RETURNS
 *  1 if deregister successfully
 *  0 if deregister failed
 *****************************************************************************/
VMINT vm_appcomm_dereg_msg_proc(VMINT handle, VM_MESSAGE_PROC proc)
{
#ifdef __MRE_CORE_APP_COMMUNICATION__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* search for a empty cell for keep native application message proc.  */
    for (i=0; i<VM_APPCOMM_MAPPING_TABLE_SIZE; i++)
    {
        if (vm_message_mapping_table[i].proc == proc)
        {
            break;
        }
    }
    if (i == VM_APPCOMM_MAPPING_TABLE_SIZE)
    {   
        /* not found the proc */
        return 0;
    }
    else
    {
        vm_message_mapping_table[i].sender = 0;
        vm_message_mapping_table[i].proc  = NULL;
        return 1;
    }


    
#else /* __MRE_CORE_APP_COMMUNICATION__ */
        return 0;
#endif /* __MRE_CORE_APP_COMMUNICATION__ */
}


/*****************************************************************************
 * FUNCTION
 *  vm_appcomm_send_msg
 * DESCRIPTION
 *  send message to MRE app or native app, will invoke message procedure directly.
 * PARAMETERS
 *  phandle : [IN] receiver process handle, if receiver is native application, this value should be zero.
 *  msg_id : [IN] user defined message ID, should larger than VM_MESSAGE_ID_BASE.
 *  wparam : [IN] wparam of message.
 *  lparam : [IN] lparam of message.
 * RETURNS
 *  message procedure return value.
 *****************************************************************************/
VMINT vm_appcomm_send_msg(VMINT handle, VMUINT msg_id, VMINT wparam, VMINT lparam)
{
#ifdef __MRE_CORE_APP_COMMUNICATION__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    vm_send_msg(handle, msg_id, wparam, lparam);

    
#else /* __MRE_CORE_APP_COMMUNICATION__ */
        return 0;
#endif /* __MRE_CORE_APP_COMMUNICATION__ */
}



/*****************************************************************************
 * FUNCTION
  *    vm_appcomm_post_msg
  * DESCRIPTION
  *  post message to MRE app or native app, will put this message to the end of MRE message queue. 
  *  when this function call finish, MMI task will dispatch MRE message and invoke message procedure. 
  * PARAMETERS
  *  phandle : [IN] receiver process handle, if receiver is native application, this value should be zero.
  *  msg_id : [IN] user defined message ID, should larger than VM_MESSAGE_ID_BASE.
  *  wparam : [IN] wparam of message.
  *  lparam : [IN] lparam of message.
  * RETURNS
  *  message procedure return value.
 *****************************************************************************/
VMINT vm_appcomm_post_msg(VMINT handle, VMUINT msg_id, VMINT wparam, VMINT lparam)
{
#ifdef __MRE_CORE_APP_COMMUNICATION__
        /*----------------------------------------------------------------*/
        /* Local Variables                                                */
        /*----------------------------------------------------------------*/
    
        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
    
        vm_post_msg(handle, msg_id, wparam, lparam);
    
        
#else /* __MRE_CORE_APP_COMMUNICATION__ */
            return 0;
#endif /* __MRE_CORE_APP_COMMUNICATION__ */
}

/*****************************************************************************
* FUNCTION
 *    vm_appcomm_queue_is_empty
 * DESCRIPTION
 *  check the message queue is empty or not.
 * RETURNS
 *  0 not empty.
 *  1 empty
*****************************************************************************/
VMINT vm_appcomm_queue_is_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MRE_CORE_APP_COMMUNICATION__
    if ((vm_message_queue_p->head == vm_message_queue_p->tail) 
        && (vm_message_queue_p->message[vm_message_queue_p->head].msg_id == VM_MESSAGE_INVALID_ID))
    {
        return 1;
    }
    else
    {
        return 0;
    }
#endif
    return 1;
}


