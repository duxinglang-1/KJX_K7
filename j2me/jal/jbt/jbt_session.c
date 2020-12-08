/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 * jbt_l2cap.c
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
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _JBT_L2CAP_C
#define _JBT_L2CAP_C
#endif 

#ifdef __SUPPORT_JBT__

/***************************************************************************** 
* Include
*****************************************************************************/
/* basic system service headers */
#include "kal_release.h"        /* Basic data type */
#include "stack_common.h"       /* message and module IDs */
#include "stack_msgs.h" /* enum for message IDs */
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"     /* type of system module components */
#include "task_config.h"        /* Task creation */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */
#include "uart_sw.h"
#include "bluetooth_struct.h"
#include "bluetooth_bm_struct.h"
#include "mmiapi_bt_struct.h"
#include "j2me_trace.h"
#include "jvm_interface.h"
#include "jam_internal.h"
#include "jbt_interface.h"
#include "jbt_internal.h"

#define JBT_SESSION_INITIATOR_FALSE (0x00)
#define JBT_SESSION_INITIATOR_TRUE (0x01)

extern JBT_L2CAP_CNTX jbt_l2cap_context;
extern JBT_SPP_CNTX jbt_spp_context;
extern void bt_jsr82_SessionApTxReadyInd(U8 session_inx, U16 l2cap_id);
extern void bt_jsr82_SessionApRxReadyInd(U8 session_inx, U16 l2cap_id, U16 length);
extern kal_uint16 bt_jsr82_getCurrentCredit(kal_uint32 session_inx);
extern void jbt_spp_getData(kal_uint32 session_inx);

void jbt_reset_session_entry(kal_uint8 list_type, jbt_list *existing_entry, jbt_subsession *subsession_entry);
void jbt_reset_subsession_entry_except_used(jbt_subsession *subsession_entry);
void jbt_reset_subsession_entry(jbt_subsession *subsession_entry);
kal_int8 jbt_session_allocate_RWRingBuf(kal_uint8 session_type, jbt_subsession *subsession_entry);
kal_uint8 jbt_session_free_RWRingBuf(jbt_subsession *subsession_entry);
kal_int16 jbt_session_BufFreeSpace(
            kal_uint8 session_type,
            kal_uint32 session_inx,
            kal_uint8 subsession_id,
            kal_uint8 buf_type);
kal_int16 jbt_session_BufAvailableDataLen(
            kal_uint8 session_type,
            kal_uint32 session_inx,
            kal_uint8 subsession_id,
            kal_uint8 buf_type);
kal_int16 jbt_session_BufSize(kal_uint8 session_type);
void jbt_session_sendData(kal_uint32 session_inx, kal_uint16 l2cap_id);


/*****************************************************************************
 * FUNCTION
 *  insert_node_to_targetList_tail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  target_list     [IN]        
 *  node            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void insert_node_to_targetList_tail(jbt_list *target_list, jbt_list *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jbt_list *tail = target_list->Blink;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_INSERT_NODE_TO_TARGETLIST_TAIL);
    target_list->Blink = node;
    node->Flink = target_list;
    node->Blink = tail;
    tail->Flink = node;

}


/*****************************************************************************
 * FUNCTION
 *  remove_node_from_targetList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  target_list     [IN]        
 *  node            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void remove_node_from_targetList(jbt_list *target_list, jbt_list *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Remove node from target_list */
    jbt_list *previous_entry = NULL, *next_entry = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_REMOVE_NODE_FROM_TARGETLIST);

    previous_entry = node->Blink;
    next_entry = node->Flink;
    previous_entry->Flink = next_entry;
    next_entry->Blink = previous_entry;
}

#ifdef __JBT_SESSION_LINK_LIST__


/*****************************************************************************
 * FUNCTION
 *  jbt_free_one_existing_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  list_type       [IN]        
 *  node            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_free_one_existing_entry(kal_uint8 list_type, jbt_list *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list_type == JBT_LIST_TYPE_L2CAP_SESSION)
    {
        /* Remove this entry from activeList */
        remove_node_from_targetList(&jbt_l2cap_context.activeList, node);
        /* Insert this entry to freeList */
        insert_node_to_targetList_tail(&jbt_l2cap_context.freeList, node);
    }
    else if (list_type == JBT_LIST_TYPE_SPP_SESSION)
    {
        /* Remove this entry from activeList */
        remove_node_from_targetList(&jbt_spp_context.activeList, node);
        /* Insert this entry to freeList */
        insert_node_to_targetList_tail(&jbt_spp_context.freeList, node);
    }
}
#else /* __JBT_SESSION_LINK_LIST__ */ 


/*****************************************************************************
 * FUNCTION
 *  jbt_free_one_existing_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  list_type       [IN]        
 *  node            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_free_one_existing_entry(kal_uint8 list_type, jbt_list *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;
    int max_session_no = 0;
    jbt_session_info *session_entry = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list_type == JBT_LIST_TYPE_L2CAP_SESSION)
    {
        max_session_no = JBT_MAX_L2CAP_NO;
        session_entry = (jbt_session_info*) jbt_l2cap_context.l2cap;
    }
    else if (list_type == JBT_LIST_TYPE_SPP_SESSION)
    {
        max_session_no = JBT_MAX_L2CAP_NO;
        session_entry = (jbt_session_info*) jbt_spp_context.spp;
    }

    for (i = 0; i < max_session_no; i++)
    {
        if ((session_entry->used == 1) && (session_entry == (jbt_session_info*) node))
        {
            /* Find this entry which will be freed, reset its used and initiator fileds */
            session_entry->used = 0;
            session_entry->initiator = JBT_SESSION_INITIATOR_FALSE;
        }
        else
        {
            session_entry += 1;
        }
    }
}
#endif /* __JBT_SESSION_LINK_LIST__ */ 

#ifdef __JBT_SESSION_LINK_LIST__


/*****************************************************************************
 * FUNCTION
 *  jbt_allocate_one_available_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  freeList        [IN]        
 *  activeList      [IN]        
 *  list_type       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
jbt_list *jbt_allocate_one_available_entry(jbt_list *freeList, jbt_list *activeList, kal_uint8 list_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jbt_list *current_entry = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_entry = freeList->Flink;
    kal_trace(TRACE_FUNC, JBT_JBT_ALLOCATE_ONE_AVAILABLE_ENTRY);

    while (current_entry != freeList)
    {
        if (((jbt_session_info*) current_entry)->used == 0)
        {
            ((jbt_session_info*) current_entry)->used = 1;
            ((jbt_session_info*) current_entry)->subsession_count = 0;
            /* Remove current_entry from freeList */
            remove_node_from_targetList(freeList, current_entry);
            /* Insert current_entry to activeList */
            insert_node_to_targetList_tail(activeList, current_entry);
            ((jbt_session_info*) current_entry)->initiator = JBT_SESSION_INITIATOR_FALSE;
            kal_trace(TRACE_JBT_GROUP, JBT_JBT_ALLOCATE_ONE_AVAILABLE_ENTRY_FIND_ONE);
            return current_entry;
        }
        else
        {
            current_entry = current_entry->Flink;
        }
    }
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_ALLOCATE_ONE_AVAILABLE_ENTRY_FIND_NONE);
    return NULL;

}
#else /* __JBT_SESSION_LINK_LIST__ */ 


/*****************************************************************************
 * FUNCTION
 *  jbt_allocate_one_available_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  freeList        [IN]        
 *  activeList      [IN]        
 *  list_type       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
jbt_list *jbt_allocate_one_available_entry(jbt_list *freeList, jbt_list *activeList, kal_uint8 list_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    int i = 0;
    int max_session_no = 0;
    jbt_session_info *session_entry = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list_type == JBT_LIST_TYPE_L2CAP_SESSION)
    {
        max_session_no = JBT_MAX_L2CAP_NO;
        session_entry = (jbt_session_info*) jbt_l2cap_context.l2cap;
    }
    else if (list_type == JBT_LIST_TYPE_SPP_SESSION)
    {
        max_session_no = JBT_MAX_SPP_NO;
        session_entry = (jbt_session_info*) jbt_spp_context.spp;
    }

    for (i = 0; i < max_session_no; i++)
    {
        if (session_entry->used == 0)
        {
            session_entry->used = 1;
            session_entry->subsession_count = 0;
            session_entry->initiator = JBT_SESSION_INITIATOR_FALSE;
            return (jbt_list*) session_entry;
        }
        else
        {
            session_entry += 1;
        }
    }
    return NULL;
}
#endif /* __JBT_SESSION_LINK_LIST__ */ 


/*****************************************************************************
 * FUNCTION
 *  jbt_check_already_connect_chnl_and_addr
 * DESCRIPTION
 *  This function is used to avoid duplicated session with same bd_addr, ps_type and psm_chnl_num
 * PARAMETERS
 *  bd_addr         [IN]        
 *  list_type       [IN]        
 *  ps_chnl_num     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jbt_check_already_connect_chnl_and_addr(kal_uint8 *bd_addr, kal_uint8 list_type, kal_uint16 ps_chnl_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;
    int max_session_no = 0;
    jbt_session_info *session_entry = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list_type == JBT_LIST_TYPE_L2CAP_SESSION)
    {
        max_session_no = JBT_MAX_L2CAP_NO;
        session_entry = (jbt_session_info*) jbt_l2cap_context.l2cap;
    }
    else if (list_type == JBT_LIST_TYPE_SPP_SESSION)
    {
        max_session_no = JBT_MAX_L2CAP_NO;
        session_entry = (jbt_session_info*) jbt_spp_context.spp;
    }

    for (i = 0; i < max_session_no; i++)
    {
        if (session_entry->used == 1)
        {
            kal_trace(
                TRACE_JBT_GROUP,
                JBT_ADDRx02Xx02Xx02Xx02Xx02Xx02X,
                session_entry->bd_addr[0],
                session_entry->bd_addr[1],
                session_entry->bd_addr[2],
                session_entry->bd_addr[3],
                session_entry->bd_addr[4],
                session_entry->bd_addr[5]);
            if ((memcmp(session_entry->bd_addr, bd_addr, 6) == 0) && session_entry->psm_channel == ps_chnl_num)
            {
                return KAL_TRUE;
            }
        }
        session_entry += 1;
    }
    return KAL_FALSE;
}

#ifdef __JBT_SESSION_LINK_LIST__


/*****************************************************************************
 * FUNCTION
 *  jbt_search_an_existing_entry
 * DESCRIPTION
 *  If the session is connected, the session_inx (i.e., con_id) is used to search an existing entry.
 *  (1) server side: turn on service, disable service, read/write operation, disc_request  (session_inx is obtained after receiveing enable service cfn)
 *  (2) client side : read/write operation, disc_request
 *  After 3rd party Java obtaining the session_inx (ie., con_id), it will passed this session_inx to do any operations of this session (e.g, read,write, disc_req)
 *  For Btstack, it will use this session_inx to determine this operation request from JBT is belonged to which session.
 *  Besides, the identify in operation request is used for 3rd party Java solution to do its callback
 * PARAMETERS
 *  targetList      [IN]        
 *  search_type     [IN]        
 *  value           [IN]        
 *  list_type       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
jbt_list *jbt_search_an_existing_entry(
            jbt_list *targetList,
            kal_uint8 search_type,
            kal_uint32 value,
            kal_uint8 list_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jbt_list *current_entry = targetList->Flink;
    kal_uint32 existed_value = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_JBT_SEARCH_AN_EXISTING_ENTRY);
    kal_trace(TRACE_JBT_GROUP, JBT_SEARCH_TYPEx02X, search_type);
    kal_trace(TRACE_JBT_GROUP, JBT_VALUEx08X, value);

    while (current_entry != targetList)
    {
        jbt_session_info *session_entry = (jbt_session_info*) (current_entry);

        if (search_type == JBT_LIST_SEARCH_TYPE_BY_INX)
        {
            existed_value = session_entry->index;
        }
        else if (search_type == JBT_LIST_SEARCH_TYPE_BY_TRANSACTION_ID)
        {
            existed_value = session_entry->transaction_id;
        }
        else if (search_type == JBT_LIST_SEARCH_TYPE_BY_CHNL_NUM)
        {
            existed_value = session_entry->psm_channel;
        }
    #if 0
/* under construction !*/
    #endif /* 0 */ 

        if ((existed_value == value) && (session_entry->used == 1))
        {
            return current_entry;
        }
        else
        {
            current_entry = current_entry->Flink;
        }
    }
    return NULL;
}
#else /* __JBT_SESSION_LINK_LIST__ */ 


/*****************************************************************************
 * FUNCTION
 *  jbt_search_an_existing_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  targetList      [IN]        
 *  search_type     [IN]        
 *  value           [IN]        
 *  list_type       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
jbt_list *jbt_search_an_existing_entry(
            jbt_list *targetList,
            kal_uint8 search_type,
            kal_uint32 value,
            kal_uint8 list_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 existed_value = 0;
    int i = 0;
    int max_session_no = 0;
    jbt_session_info *session_entry = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list_type == JBT_LIST_TYPE_L2CAP_SESSION)
    {
        max_session_no = JBT_MAX_L2CAP_NO;
        session_entry = (jbt_session_info*) jbt_l2cap_context.l2cap;
    }
    else if (list_type == JBT_LIST_TYPE_SPP_SESSION)
    {
        max_session_no = JBT_MAX_L2CAP_NO;
        session_entry = (jbt_session_info*) jbt_spp_context.spp;
    }

    for (i = 0; i < max_session_no; i++)
    {
        if (search_type == JBT_LIST_SEARCH_TYPE_BY_INX)
        {
            existed_value = session_entry->index;
        }
        else if (search_type == JBT_LIST_SEARCH_TYPE_BY_TRANSACTION_ID)
        {
            existed_value = session_entry->transaction_id;
        }
        else if (search_type == JBT_LIST_SEARCH_TYPE_BY_CHNL_NUM)
        {
            existed_value = session_entry->psm_channel;
        }
    #if 1
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_SEARCH_EACH_ENTRY, existed_value, session_entry->used);
    #endif 

        if ((existed_value == value) && (session_entry->used == 1))
        {
            return (jbt_list*) session_entry;
        }
        else
        {
            session_entry += 1;
        }
    }
    return NULL;
}
#endif /* __JBT_SESSION_LINK_LIST__ */ 

#ifdef __JBT_SESSION_LINK_LIST__
/* Add by mtk01411: 2007-1103 */


/*****************************************************************************
 * FUNCTION
 *  jbt_search_existing_entry_with_psm_chnl_bdaddr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  targetList      [IN]        
 *  psm_channel     [IN]        
 *  bd_addr         [IN]        
 *  list_type       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
jbt_session_info *jbt_search_existing_entry_with_psm_chnl_bdaddr(
                    jbt_list *targetList,
                    kal_uint16 psm_channel,
                    kal_uint8 *bd_addr,
                    kal_uint8 list_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jbt_list *current_entry = targetList->Flink;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (current_entry != targetList)
    {
        jbt_session_info *session_entry = (jbt_session_info*) (current_entry);

        if ((session_entry->psm_channel == psm_channel) && (memcpy(session_entry->bd_addr, bd_addr, 6) == 0))
        {
            return session_entry;
        }
        else
        {
            current_entry = current_entry->Flink;
        }
    }
    return NULL;
}
#else /* __JBT_SESSION_LINK_LIST__ */ 


/*****************************************************************************
 * FUNCTION
 *  jbt_search_existing_entry_with_psm_chnl_bdaddr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  targetList      [IN]        
 *  psm_channel     [IN]        
 *  bd_addr         [IN]        
 *  list_type       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
jbt_session_info *jbt_search_existing_entry_with_psm_chnl_bdaddr(
                    jbt_list *targetList,
                    kal_uint16 psm_channel,
                    kal_uint8 *bd_addr,
                    kal_uint8 list_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    int i = 0;
    int max_session_no = 0;
    jbt_session_info *session_entry = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list_type == JBT_LIST_TYPE_L2CAP_SESSION)
    {
        max_session_no = JBT_MAX_L2CAP_NO;
        session_entry = (jbt_session_info*) jbt_l2cap_context.l2cap;
    }
    else if (list_type == JBT_LIST_TYPE_SPP_SESSION)
    {
        max_session_no = JBT_MAX_L2CAP_NO;
        session_entry = (jbt_session_info*) jbt_spp_context.spp;
    }

    for (i = 0; i < max_session_no; i++)
    {
        if ((session_entry->psm_channel == psm_channel) && (memcpy(session_entry->bd_addr, bd_addr, 6) == 0) &&
            (session_entry->used == 1))
        {
            return session_entry;
        }
        else
        {
            session_entry += 1;
        }
    }
    return NULL;
}
#endif /* __JBT_SESSION_LINK_LIST__ */ 


/*****************************************************************************
 * FUNCTION
 *  jbt_allocate_one_available_subsession_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  session_entry       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
jbt_subsession *jbt_allocate_one_available_subsession_entry(jbt_session_info *session_entry)
{
#if (JBT_MAX_SUBSESSION_NO > 1)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 i = 0;
#else /* (JBT_MAX_SUBSESSION_NO > 1) */
    jbt_subsession *subsession_entry = NULL;
#endif /* (JBT_MAX_SUBSESSION_NO > 1) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (JBT_MAX_SUBSESSION_NO > 1)
    for (i = 0; i < JBT_MAX_SUBSESSION_NO; i++)
    {
        if (session_entry->subsession[i].used == 0)
        {
            session_entry->subsession[i].used = 1;
            session_entry->subsession[i].subsession_id = 0;
            session_entry->subsession_count++;
            return &(session_entry->subsession[i]);
        }
    }
    return NULL;
#else /* (JBT_MAX_SUBSESSION_NO > 1) */
    if (session_entry->subsession_count != 0)
    {
        ASSERT(0);
    }
    subsession_entry = &(session_entry->subsession[0]);
    subsession_entry->used = 1;
    subsession_entry->subsession_id = 0;
    session_entry->subsession_count++;
    return subsession_entry;
#endif /* (JBT_MAX_SUBSESSION_NO > 1) */

}


/*****************************************************************************
 * FUNCTION
 *  jbt_search_existing_subsession_entry
 * DESCRIPTION
 *  For searching an already connected or connect_request cases
 * PARAMETERS
 *  session_entry       [IN]       
 *  search_type         [IN]        
 *  value               [IN]        
 * RETURNS
 *  
 *****************************************************************************/
jbt_subsession *jbt_search_existing_subsession_entry(
                    jbt_session_info *session_entry,
                    kal_uint8 search_type,
                    kal_uint32 value)
{
#if (JBT_MAX_SUBSESSION_NO > 1)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 i = 0;
    kal_uint32 existed_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < JBT_MAX_SUBSESSION_NO; i++)
    {
        if (session_entry->subsession[i].used == 1)
        {
            if (search_type == JBT_LIST_SEARCH_TYPE_BY_INX)
            {
                existed_value = session_entry->subsession[i].subsession_id;
            }
            else if (search_type == JBT_LIST_SEARCH_TYPE_BY_TRANSACTION_ID)
            {
                existed_value = session_entry->subsession[i].transaction_id;
            }

            if (existed_value == value)
            {
                if (search_type == JBT_LIST_SEARCH_TYPE_BY_INX)
                {
                    if (session_entry->subsession[i].subsession_state != JBT_SESSION_STATE_CONNECTED)
                    {
                        ASSERT(0);
                    }
                }
                return &(session_entry->subsession[i]);
            }
        }
    }
    return NULL;
#else /* (JBT_MAX_SUBSESSION_NO > 1) */
    return (&session_entry->subsession[0]);
#endif /* (JBT_MAX_SUBSESSION_NO > 1) */
}


/*****************************************************************************
 * FUNCTION
 *  jbt_server_find_one_subsession_entry
 * DESCRIPTION
 *  This function is only invoked in server side
 * PARAMETERS
 *  session_entry       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
jbt_subsession *jbt_server_find_one_subsession_entry(jbt_session_info *session_entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Find one subsession_entry and its used =1 (means allocates RXTX buf ) and subsession_state = IDLE */
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < JBT_MAX_SUBSESSION_NO; i++)
    {
        if (session_entry->subsession[i].used == 1 &&
            session_entry->subsession[i].subsession_state == JBT_SESSION_STATE_IDLE)
        {
            return &(session_entry->subsession[i]);
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_session_check_this_psm_chnl_nun_existed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ps_type                 [IN]        
 *  existing_chnl_num       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jbt_session_check_this_psm_chnl_nun_existed(kal_uint8 ps_type, kal_uint16 existing_chnl_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jbt_list *existing_entry = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (existing_chnl_num == 0)
    {
        return KAL_FALSE;
    }
    else if (ps_type == JSR82_SESSION_PS_L2CAP)
    {
        return KAL_FALSE;
    }

    if (ps_type == JSR82_SESSION_PS_RFCOMM)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_spp_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_CHNL_NUM,
                            existing_chnl_num,
                            JBT_LIST_TYPE_SPP_SESSION);
    }
    else if (ps_type == JSR82_SESSION_PS_L2CAP)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_l2cap_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_CHNL_NUM,
                            existing_chnl_num,
                            JBT_LIST_TYPE_L2CAP_SESSION);
    }
    else
    {
        ASSERT(0);
    }

    if (existing_entry == NULL)
    {
        kal_trace(
            TRACE_JBT_GROUP,
            FUNC_JBT_CAN_NOT_FIND_EXISTING_ENTRY,
            JBT_LIST_SEARCH_TYPE_BY_CHNL_NUM,
            existing_chnl_num);
        return KAL_FALSE;
    }
    else
    {
        return KAL_TRUE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  jbt_session_general_service_registration
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ps_type                 [IN]        
 *  mtu                     [IN]        
 *  security                [IN]        
 *  transaction_id          [IN]        
 *  list_entry              [IN]        
 *  subsession_entry        [IN]        
 *  list_type               [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jbt_session_general_service_registration(
            kal_uint8 ps_type,
            kal_uint16 mtu,
            kal_uint8 security,
            kal_uint32 transaction_id,
            jbt_list *list_entry,
            jbt_subsession *subsession_entry,
            kal_uint8 list_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_jsr82_enable_service_req_struct *parms;

    /* max_mtu: depends on L2CAP or RFCOMM */
    kal_int8 rc = 0;
    kal_uint8 block_inx = 0;
    jbt_session_info *session_entry = (jbt_session_info*) list_entry;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jbt_general_non_poweron_reject())
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_REJCT_DUE_TO_POWEROFF_ONGOING);
        return KAL_FALSE;
    }

    kal_trace(TRACE_JBT_GROUP, FUNC_JBT_REG_SERVICE_ALLOCATE_CHNL_BUF);
    block_inx = jbt_malloc_block(JBT_MAX_BTSTACK_USED_BUFFER_SIZE);
#ifndef JBT_SUPPORT_ADM_MEM
    session_entry->channel_buffer = (kal_uint8*) jvm_malloc(JBT_MAX_BTSTACK_USED_BUFFER_SIZE);
#else
    session_entry->channel_buffer = (kal_uint8*) kal_adm_alloc(jbt_get_mem_pool_id(),JBT_MAX_BTSTACK_USED_BUFFER_SIZE);
#endif

    if (session_entry->channel_buffer == NULL)
    {
        /* Failed of jvm_malloc() */
        jbt_free_block(block_inx);
        jbt_reset_subsession_entry(subsession_entry);
        /* Release session_entry from activeList to freeList */
        jbt_free_one_existing_entry(list_type, list_entry);
        session_entry->used = 0;
        return KAL_FALSE;
    }
    else
    {
        jbt_malloc_record(block_inx, session_entry->channel_buffer, JBT_MAX_BTSTACK_USED_BUFFER_SIZE);
    }

    /* Read and Write RingBuf are also allocated during this stage: 2007-10-25 */
    kal_trace(TRACE_JBT_GROUP, FUNC_JBT_REG_SERVICE_ALLOCATE_RWRING_BUF);
    /* TODO We should add a if to seperate the manupulate of SPP/L2CAP */
    rc = jbt_session_allocate_RWRingBuf(JBT_SESSION_TYPE_SPP, subsession_entry);
    if (rc < 0)
    {
        /* Release the channel_buf already allocated */
        jbt_free_record(session_entry->channel_buffer);
#ifndef JBT_SUPPORT_ADM_MEM
        jvm_free(session_entry->channel_buffer);
#else
        kal_adm_free(jbt_get_mem_pool_id(),session_entry->channel_buffer);
#endif
        jbt_reset_subsession_entry(subsession_entry);
        /* Release session_entry from activeList to freeList */
        jbt_free_one_existing_entry(list_type, list_entry);
        session_entry->used = 0;
        return KAL_FALSE;
    }

    session_entry->transaction_id = transaction_id;
    session_entry->ps_type = ps_type;
    session_entry->initiator = JBT_SESSION_INITIATOR_FALSE;
    parms = (bt_jsr82_enable_service_req_struct*)
        construct_local_para(sizeof(bt_jsr82_enable_service_req_struct), TD_UL);

    parms->channel_context = session_entry->channel_buffer;
    parms->identify = transaction_id;

    parms->mtu = mtu;

    parms->ps_type = ps_type;
    parms->security_value = security;
    /* Add by mtk01411: 2007-1106 */
    parms->existing_psm_chnl_num = session_entry->psm_channel;
    jbt_send_msg(MSG_ID_BT_JSR82_ENABLE_SERVICE_REQ, MOD_JASYN, MOD_BT, BT_APP_SAP, (local_para_struct*) parms, NULL);

    return KAL_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  jbt_session_service_registration
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ps_type             [IN]        
 *  mtu                 [IN]        
 *  security            [IN]        
 *  transaction_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jbt_session_service_registration(
            kal_uint8 ps_type,
            kal_uint16 mtu,
            kal_uint8 security,
            kal_uint32 transaction_id,
            kal_uint8* status_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    jbt_list *free_entry = NULL;
    jbt_session_info *session_entry = NULL;
    kal_uint16 max_mtu = JSR82_SESSION_PS_RFCOMM_MTU;
    jbt_subsession *subsession_entry = NULL;
    kal_uint8 list_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_JBT_SESSION_SERVICE_REGISTRATION);
    kal_trace(TRACE_JBT_GROUP, JBT_PS_TYPEx02X, ps_type);
    kal_trace(TRACE_JBT_GROUP, JBT_MTUx04X, mtu);
    kal_trace(TRACE_JBT_GROUP, JBT_SECURITYx02X, security);
    kal_trace(TRACE_JBT_GROUP, JBT_TRANSACTION_IDx08X, transaction_id);
#ifndef __MVM__
    if (jam_is_minimize_mode())
    {   
        *status_result = JBT_CMD_REJECT_DUE_TO_VM_MINIMIZE;
        return KAL_FALSE;
    }
#endif
    if (jbt_general_non_poweron_reject())
    {
        kal_trace(TRACE_JBT_GROUP, JBT_COMMAND_REJECT_A);
        return KAL_FALSE;
    }
    /* Modify from or to and condition: 2007-1102 */
    if ((security != 0) && ((security != 1)))
    {
        kal_trace(TRACE_JBT_GROUP, JBT_COMMAND_REJECT_B);
        return KAL_FALSE;
    }
    if (ps_type == JSR82_SESSION_PS_RFCOMM)
    {
        free_entry = jbt_allocate_one_available_entry(
                        &jbt_spp_context.freeList,
                        &jbt_spp_context.activeList,
                        JBT_LIST_TYPE_SPP_SESSION);
        max_mtu = JSR82_SESSION_PS_RFCOMM_MTU;
        list_type = JBT_LIST_TYPE_SPP_SESSION;
    }
    else if (ps_type == JSR82_SESSION_PS_L2CAP)
    {
        free_entry = jbt_allocate_one_available_entry(
                        &jbt_l2cap_context.freeList,
                        &jbt_l2cap_context.activeList,
                        JBT_LIST_TYPE_L2CAP_SESSION);
        max_mtu = JSR82_SESSION_PS_L2CAP_MTU;
        list_type = JBT_LIST_TYPE_L2CAP_SESSION;
    }
    else
    {
        ASSERT(0);
    }

    if (free_entry == NULL)
    {
        kal_trace(TRACE_JBT_GROUP, JBT_COMMAND_REJECT_C_DUE_TO_NO_ENTRY);
        return KAL_FALSE;
    }

    session_entry = (jbt_session_info*) free_entry;
    /* The actual service channel registered by this service is dependend on Stack's cureent channel number usage: 2007-1107 */
    session_entry->psm_channel = 0;

    /* Find a free subsession_entry: Because it supports at least one client and allocates RXTXRingBuf in advance  2007-1103 */
    subsession_entry = jbt_allocate_one_available_subsession_entry(session_entry);
#if (JBT_MAX_SUBSESSION_NO > 1)
    if (subsession_entry == NULL)
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_CAN_NOT_GET_ONE_FREE_SUBENTRY);
        /* Release session_entry from activeList to freeList */
        jbt_free_one_existing_entry(list_type, free_entry);
        session_entry->used = 0;
        return KAL_FALSE;
    }
#endif /* (JBT_MAX_SUBSESSION_NO > 1) */

    if (mtu > max_mtu)
    {
        mtu = max_mtu;
    }

    return jbt_session_general_service_registration(
            ps_type,
            mtu,
            security,
            transaction_id,
            free_entry,
            subsession_entry,
            list_type);

}


/*****************************************************************************
 * FUNCTION
 *  jbt_session_service_registration_use_existing_chnl_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ps_type                 [IN]        
 *  mtu                     [IN]        
 *  security                [IN]        
 *  transaction_id          [IN]        
 *  existing_chnl_num       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jbt_session_service_registration_use_existing_chnl_num(
            kal_uint8 ps_type,
            kal_uint16 mtu,
            kal_uint8 security,
            kal_uint32 transaction_id,
            kal_uint8 existing_chnl_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    jbt_list *free_entry = NULL;
    jbt_session_info *session_entry = NULL;
    kal_uint16 max_mtu = JSR82_SESSION_PS_RFCOMM_MTU;
    jbt_subsession *subsession_entry = NULL;
    kal_uint8 list_type = 0;
    kal_bool check_existed_this_chnl_num = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jbt_general_non_poweron_reject())
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_REJCT_DUE_TO_POWEROFF_ONGOING);
        return KAL_FALSE;
    }

    check_existed_this_chnl_num = jbt_session_check_this_psm_chnl_nun_existed(ps_type, existing_chnl_num);

    if (check_existed_this_chnl_num == KAL_FALSE)
    {
        return KAL_FALSE;
    }

    if (ps_type == JSR82_SESSION_PS_RFCOMM)
    {
        /* The actual service channel registered by this service is dependend on Stack's cureent channel number usage: 2007-1107 */
        free_entry = jbt_allocate_one_available_entry(
                        &jbt_spp_context.freeList,
                        &jbt_spp_context.activeList,
                        JBT_LIST_TYPE_SPP_SESSION);
        max_mtu = JSR82_SESSION_PS_RFCOMM_MTU;
        list_type = JBT_LIST_TYPE_SPP_SESSION;
    }
    else
    {
        return KAL_FALSE;
    }

    if (free_entry == NULL)
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_CAN_NOT_GET_ONE_FREE_ENTRY);
        return KAL_FALSE;
    }
    else
    {
        session_entry = (jbt_session_info*) free_entry;
    }

    /* Find a free subsession_entry: 2007-1103 */
    subsession_entry = jbt_allocate_one_available_subsession_entry(session_entry);
#if (JBT_MAX_SUBSESSION_NO > 1)
    if (subsession_entry == NULL)
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_CAN_NOT_GET_ONE_FREE_SUBENTRY);
        /* Release session_entry from activeList to freeList */
        jbt_free_one_existing_entry(list_type, existing_entry);
        session_entry->used = 0;
        return KAL_FALSE;
    }
#endif /* (JBT_MAX_SUBSESSION_NO > 1) */
    session_entry->psm_channel = existing_chnl_num;
    if (mtu > max_mtu)
    {
        mtu = max_mtu;
    }

    return jbt_session_general_service_registration(
            ps_type,
            mtu,
            security,
            transaction_id,
            free_entry,
            subsession_entry,
            list_type);

}


/*****************************************************************************
 * FUNCTION
 *  jbt_session_service_turn_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ps_type             [IN]        
 *  con_id              [IN]        
 *  transaction_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jbt_session_service_turn_on(kal_uint8 ps_type, kal_uint8 con_id, kal_uint32 transaction_id, kal_uint8* status_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_jsr82_turnon_service_req_struct *parms;
    jbt_list *existing_entry = NULL;
    jbt_session_info *session_entry = NULL;
    kal_uint8 list_type = 0;
    kal_int32 vm_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_JBT_SESSION_SERVICE_TURN_ON);
    kal_trace(TRACE_JBT_GROUP, JBT_PS_TYPEx02X, ps_type);
    kal_trace(TRACE_JBT_GROUP, JBT_CON_IDx02X, con_id);
    kal_trace(TRACE_JBT_GROUP, JBT_TRANSACTION_IDx08X, transaction_id);
#ifndef __MVM__
    if (jam_is_minimize_mode())
    {   
        *status_result = JBT_CMD_REJECT_DUE_TO_VM_MINIMIZE;
        return KAL_FALSE;
    }
#endif /*__MVM__*/
    if (jbt_general_non_poweron_reject())
    {
        kal_trace(TRACE_JBT_GROUP, JBT_COMMAND_REJECT_A);
        return KAL_FALSE;
    }

    if (ps_type == JSR82_SESSION_PS_RFCOMM)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_spp_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            con_id,
                            JBT_LIST_TYPE_SPP_SESSION);
        list_type = JBT_LIST_TYPE_SPP_SESSION;
    }
    else if (ps_type == JSR82_SESSION_PS_L2CAP)
    {
        /*
         * Note by mtk01411 2007-1103: Because for L2CAP server, it only has con_id after enable service: 
         * The l2cap_id is set 0 to find the L2CAP server's registration entry!
         */
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_l2cap_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            con_id,
                            JBT_LIST_TYPE_L2CAP_SESSION);
        list_type = JBT_LIST_TYPE_L2CAP_SESSION;
    }
    else
    {
        ASSERT(0);
    }

    if (existing_entry == NULL)
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_CAN_NOT_FIND_EXISTING_ENTRY, JBT_LIST_SEARCH_TYPE_BY_INX, con_id);
        return KAL_FALSE;
    }
    session_entry = (jbt_session_info*) existing_entry;
    kal_trace(
        TRACE_JBT_GROUP,
        JBT_SESSION_ENTRYTURN_ON_OPOPERATION_STATEx02X,
        session_entry->turn_on_op.operation_state);
    if (session_entry->turn_on_op.operation_state != JBT_OPERATION_STATE_NONE)
    {
        return KAL_FALSE;
    }
    else
    {
        session_entry->turn_on_op.operation_state = JBT_OPERATION_STATE_ONGOING;
        session_entry->transaction_id = transaction_id;
    }
    parms = (bt_jsr82_turnon_service_req_struct*)
        construct_local_para(sizeof(bt_jsr82_turnon_service_req_struct), TD_UL);

    /* parms->ps_type = jbt_l2cap_context.l2cap[i].ps_type; */
    parms->ps_type = session_entry->ps_type;

    parms->index = con_id;
    parms->identify = transaction_id;
    jbt_send_msg(MSG_ID_BT_JSR82_TURNON_SERVICE_REQ, MOD_JASYN, MOD_BT, BT_APP_SAP, (local_para_struct*) parms, NULL);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_session_service_turn_off
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ps_type             [IN]        
 *  con_id              [IN]        
 *  transaction_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jbt_session_service_turn_off(kal_uint8 ps_type, kal_uint8 con_id, kal_uint32 transaction_id, kal_uint8* status_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_jsr82_turnoff_service_req_struct *parms;
    jbt_list *existing_entry = NULL;
    jbt_session_info *session_entry = NULL;
    kal_int32 vm_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_JBT_SESSION_SERVICE_TURN_OFF);
    kal_trace(TRACE_JBT_GROUP, JBT_PS_TYPEx02X, ps_type);
    kal_trace(TRACE_JBT_GROUP, JBT_CON_IDx02X, con_id);
    kal_trace(TRACE_JBT_GROUP, JBT_TRANSACTION_IDx08X, transaction_id);


#ifndef __MVM__
    if (jam_is_minimize_mode())
    {   
        *status_result = JBT_CMD_REJECT_DUE_TO_VM_MINIMIZE;
        return KAL_FALSE;
    }
#endif /*__MVM__*/

    if (jbt_general_non_poweron_reject())
    {
        kal_trace(TRACE_JBT_GROUP, JBT_COMMAND_REJECT_A);
        return KAL_FALSE;
    }

    if (ps_type == JSR82_SESSION_PS_RFCOMM)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_spp_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            con_id,
                            JBT_LIST_TYPE_SPP_SESSION);
    }
    else if (ps_type == JSR82_SESSION_PS_L2CAP)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_l2cap_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            con_id,
                            JBT_LIST_TYPE_L2CAP_SESSION);
    }
    else
    {
        ASSERT(0);
    }
    if (existing_entry == NULL)
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_CAN_NOT_FIND_EXISTING_ENTRY, JBT_LIST_SEARCH_TYPE_BY_INX, con_id);
        return KAL_FALSE;
    }
    session_entry = (jbt_session_info*) existing_entry;

    if (session_entry->turn_on_op.operation_state != JBT_OPERATION_STATE_NONE)
    {
        return KAL_FALSE;
    }
    else
    {
        session_entry->turn_on_op.operation_state = JBT_OPERATION_STATE_ONGOING;
        session_entry->transaction_id = transaction_id;
    }
    parms = (bt_jsr82_turnoff_service_req_struct*)
        construct_local_para(sizeof(bt_jsr82_turnoff_service_req_struct), TD_UL);

    /* parms->ps_type = jbt_l2cap_context.l2cap[i].ps_type; */
    parms->ps_type = session_entry->ps_type;

    parms->index = con_id;
    parms->identify = transaction_id;
    jbt_send_msg(MSG_ID_BT_JSR82_TURNOFF_SERVICE_REQ, MOD_JASYN, MOD_BT, BT_APP_SAP, (local_para_struct*) parms, NULL);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_session_service_deregistration
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ps_type             [IN]        
 *  transaction_id      [IN]        
 *  con_id              [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jbt_session_service_deregistration(kal_uint8 ps_type, kal_uint32 transaction_id, kal_uint8 con_id, kal_uint8* status_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_jsr82_disable_service_req_struct *parms;
    jbt_list *existing_entry = NULL;
    jbt_session_info *session_entry = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_JBT_SESSION_SERVICE_DEREGISTRATION);
    kal_trace(TRACE_JBT_GROUP, JBT_PS_TYPEx02X, ps_type);
    kal_trace(TRACE_JBT_GROUP, JBT_CON_IDx02X, con_id);
    kal_trace(TRACE_JBT_GROUP, JBT_TRANSACTION_IDx08X, transaction_id);
#ifndef __MVM__
    if (jam_is_minimize_mode())
    {   
        *status_result = JBT_CMD_REJECT_DUE_TO_VM_MINIMIZE;
        return KAL_FALSE;
    }
#endif

    if (jbt_general_non_poweron_reject())
    {
        kal_trace(TRACE_JBT_GROUP, JBT_COMMAND_REJECT_A);
        return KAL_FALSE;
    }

    if (ps_type == JSR82_SESSION_PS_RFCOMM)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_spp_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            con_id,
                            JBT_LIST_TYPE_SPP_SESSION);
    }
    else if (ps_type == JSR82_SESSION_PS_L2CAP)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_l2cap_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            con_id,
                            JBT_LIST_TYPE_L2CAP_SESSION);
    }
    else
    {
        ASSERT(0);
    }

    if (existing_entry == NULL)
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_CAN_NOT_FIND_EXISTING_ENTRY, JBT_LIST_SEARCH_TYPE_BY_INX, con_id);
        return KAL_FALSE;
    }
    session_entry = (jbt_session_info*) existing_entry;

    session_entry->transaction_id = transaction_id;
    session_entry->index = con_id;

    parms = (bt_jsr82_disable_service_req_struct*)
        construct_local_para(sizeof(bt_jsr82_disable_service_req_struct), TD_UL);
    parms->index = con_id;
    parms->identify = transaction_id;

    jbt_send_msg(MSG_ID_BT_JSR82_DISABLE_SERVICE_REQ, MOD_JASYN, MOD_BT, BT_APP_SAP, (local_para_struct*) parms, NULL);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_session_connect_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  transaction_id      [IN]        
 *  bd_addr             [IN]        
 *  ps_type             [IN]        
 *  psm_channel         [IN]        
 *  mtu                 [IN]        
 *  security_value      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jbt_session_connect_req(
            kal_uint32 transaction_id,
            kal_uint8 *bd_addr,
            kal_uint8 ps_type,
            kal_uint16 psm_channel,
            kal_uint16 mtu,
            kal_uint8 security_value,
            kal_uint8* status_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 rc = 0;    /* 0: means successful */
    bt_jsr82_connect_req_struct *parms;
    jbt_list *free_entry = NULL;
    jbt_session_info *session_entry = NULL;
    jbt_subsession *subsession_entry = NULL;
    kal_uint8 list_type = 0;
    kal_uint8 block_inx = 0;
    kal_int32 vm_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_JBT_SESSION_CONNECT_REQ);
    kal_trace(
        TRACE_JBT_GROUP,
        JBT_ADDRx02Xx02Xx02Xx02Xx02Xx02X,
        bd_addr[0],
        bd_addr[1],
        bd_addr[2],
        bd_addr[3],
        bd_addr[4],
        bd_addr[5]);
    kal_trace(TRACE_JBT_GROUP, JBT_PS_TYPEx02X, ps_type);
    kal_trace(TRACE_JBT_GROUP, JBT_PSM_CHANNELx04X, psm_channel);
    kal_trace(TRACE_JBT_GROUP, JBT_TRANSACTION_IDx08X, transaction_id);
    kal_trace(TRACE_JBT_GROUP, JBT_MTUx04X, mtu);
    kal_trace(TRACE_JBT_GROUP, JBT_SECURITY_VALUEx02X, security_value);
#ifndef __MVM__
    if (jam_is_minimize_mode())
    {   
        *status_result = JBT_CMD_REJECT_DUE_TO_VM_MINIMIZE;
        return KAL_FALSE;
    }
#endif /*__MVM__*/
    if (jbt_general_non_poweron_reject())
    {
        kal_trace(TRACE_JBT_GROUP, JBT_COMMAND_REJECT_A);
        *status_result = JBT_CMD_REJECT_DUE_TO_POWEROFF;
        return KAL_FALSE;
    }

    if (jbt_check_inquiry_operation_ongoing())
    {
        *status_result = JBT_CMD_REJECT_DUE_TO_INQUIRY;
        return KAL_FALSE;
    }


    ASSERT((ps_type == JSR82_SESSION_PS_RFCOMM) || (ps_type == JSR82_SESSION_PS_L2CAP));

    /* Check if this bd_address and its channel is in activeList or not: 2007-1213 */
    if (jbt_check_already_connect_chnl_and_addr(bd_addr, ps_type, psm_channel))
    {
        *status_result = JBT_CMD_REJECT_CON_REQ_ALREADY_EXISTED;    
        return KAL_FALSE;
    }

    if (ps_type == JSR82_SESSION_PS_RFCOMM)
    {
        free_entry = jbt_allocate_one_available_entry(
                        &jbt_spp_context.freeList,
                        &jbt_spp_context.activeList,
                        JBT_LIST_TYPE_SPP_SESSION);
        list_type = JBT_LIST_TYPE_SPP_SESSION;
    }
    else if (ps_type == JSR82_SESSION_PS_L2CAP)
    {
        free_entry = jbt_allocate_one_available_entry(
                        &jbt_l2cap_context.freeList,
                        &jbt_l2cap_context.activeList,
                        JBT_LIST_TYPE_L2CAP_SESSION);
        list_type = JBT_LIST_TYPE_L2CAP_SESSION;
    }
    else
    {
        ASSERT(0);
    }

    if (free_entry == NULL)
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_CAN_NOT_GET_ONE_FREE_ENTRY);
        *status_result = JBT_CMD_REJECT_NO_RESOURCE;
        return KAL_FALSE;
    }

    session_entry = (jbt_session_info*) free_entry;

    subsession_entry = jbt_allocate_one_available_subsession_entry(session_entry);
    if (subsession_entry != NULL)
    {
        if (subsession_entry->subsession_state == JBT_SESSION_STATE_IDLE)
        {
            subsession_entry->subsession_state = JBT_SESSION_STATE_CONNECTING;
            subsession_entry->transaction_id = transaction_id;
        }
        else
        {
            /* session_state is in an error state */
            *status_result = JBT_CMD_REJECT_WRONG_STATE;
            return KAL_FALSE;
        }
    }
    /* If JBT_MAX_SUBSESSION_NO == 1: then subsession_entry must not be NULL */

#if (JBT_MAX_SUBSESSION_NO > 1)
    else
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_CAN_NOT_GET_ONE_FREE_SUBENTRY);
        /* Because subsession_entry is NULL, it is not necessary to reset subsession_entry */
        /* jbt_reset_subsession_entry(subsession_entry); */
        /* Release session_entry from activeList to freeList */
        jbt_free_one_existing_entry(list_type, free_entry);
        session_entry->used = 0;
        *status_result = JBT_CMD_REJECT_NO_RESOURCE;
        return KAL_FALSE;
    }
#endif /* (JBT_MAX_SUBSESSION_NO > 1) */

    block_inx = jbt_malloc_block(JBT_MAX_BTSTACK_USED_BUFFER_SIZE);
#ifndef JBT_SUPPORT_ADM_MEM
    session_entry->channel_buffer = (kal_uint8*) jvm_malloc(JBT_MAX_BTSTACK_USED_BUFFER_SIZE);
#else
    session_entry->channel_buffer = (kal_uint8*) kal_adm_alloc(jbt_get_mem_pool_id(),JBT_MAX_BTSTACK_USED_BUFFER_SIZE);
#endif
    if (session_entry->channel_buffer == NULL)
    {
        /* Failed of jvm_malloc() */
        jbt_free_block(block_inx);

        /* Reset subsession_entry field */
        jbt_reset_subsession_entry(subsession_entry);
        /* Release this session_entry from activeList to freeList */
        jbt_free_one_existing_entry(list_type, free_entry);
        session_entry->used = 0;
        *status_result = JBT_CMD_REJECT_NO_RESOURCE;
        return KAL_FALSE;
    }
    else
    {
        jbt_malloc_record(block_inx, session_entry->channel_buffer, JBT_MAX_BTSTACK_USED_BUFFER_SIZE);
    }
    
    /* Allocate RingBuf memory space for SPP Client first: Add by mtk01411:2007-1024 */
    kal_trace(TRACE_JBT_GROUP, FUNC_JBT_CON_REQ_ALLOCATE_RING_BUF);

    if (ps_type == JSR82_SESSION_PS_RFCOMM)
    {
        rc = jbt_session_allocate_RWRingBuf(JBT_SESSION_TYPE_SPP, subsession_entry);
    }
    else
    {
        rc = jbt_session_allocate_RWRingBuf(JBT_SESSION_TYPE_L2CAP, subsession_entry);
    }

    /* Because alloation memory space for RingBuf is failure, return FALSE: Add by mtk01411: 2007-1024 */
    if (rc < 0)
    {
        /* Before returning, release the channel buffer first */
        jbt_free_record(session_entry->channel_buffer);
#ifndef JBT_SUPPORT_ADM_MEM
        jvm_free(session_entry->channel_buffer);
#else
        kal_adm_free(jbt_get_mem_pool_id(),session_entry->channel_buffer);
#endif
        
        jbt_reset_subsession_entry(subsession_entry);
        /* Release session_entry from activeList to freeList */
        jbt_free_one_existing_entry(list_type, free_entry);
        session_entry->used = 0;
        *status_result = JBT_CMD_REJECT_NO_RESOURCE;
        return KAL_FALSE;
    }

    /* Added 2007-1024: In JBT layer, bd_addr[] array is from high byte to low byte ([0] to [5]) */
    memcpy(session_entry->bd_addr, bd_addr, 6);
    session_entry->transaction_id = transaction_id;
    session_entry->ps_type = ps_type;
    /* Add 2007-1213 */
    session_entry->psm_channel = psm_channel;
    session_entry->initiator = JBT_SESSION_INITIATOR_TRUE;
    session_entry->con_req_op.operation_state = JBT_OPERATION_STATE_ONGOING;
    session_entry->transaction_id = transaction_id;

    /* After all necessary entries and memory are allocated, it is time to construct local para to avoid memory leak */
    parms = (bt_jsr82_connect_req_struct*) construct_local_para(sizeof(bt_jsr82_connect_req_struct), TD_UL);
    parms->ps_type = session_entry->ps_type;
    parms->mtu = mtu;
    parms->channel = psm_channel;
    parms->identify = transaction_id;
    parms->security_value = security_value;
    /*
     * Modify: if the bd_addr is sent to btstack via array format, it must be from low byte to high byte [0] to [5] 
     * This function invoked by JVM passes the addr format from high to low ([0] to [6])
     * The bd_addr array returned to JVM is also fro, high to low ([0] to [6]) 
     */
    jbt_ConvertBdAddrOrder(parms->bd_addr, bd_addr);
    parms->channel_context = session_entry->channel_buffer;

    jbt_send_msg(MSG_ID_BT_JSR82_CONNECT_REQ, MOD_JASYN, MOD_BT, BT_APP_SAP, (local_para_struct*) parms, NULL);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_session_disconnect_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  transaction_id      [IN]        
 *  ps_type             [IN]        
 *  con_id              [IN]        
 *  l2cap_id            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jbt_session_disconnect_req(kal_uint32 transaction_id, kal_uint8 ps_type, kal_uint8 con_id, kal_uint16 l2cap_id, kal_uint8* status_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_jsr82_disconnect_req_struct *parms;
    jbt_list *existing_entry = NULL;
    jbt_session_info *session_entry = NULL;
    jbt_subsession *subsession_entry = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_JBT_SESSION_DISCONNECT_REQ);
    kal_trace(TRACE_JBT_GROUP, JBT_PS_TYPEx02X, ps_type);
    kal_trace(TRACE_JBT_GROUP, JBT_L2CAP_IDx04X, l2cap_id);
    kal_trace(TRACE_JBT_GROUP, JBT_TRANSACTION_IDx08X, transaction_id);
#ifndef __MVM__
    if (jam_is_minimize_mode())
    {   
        *status_result = JBT_CMD_REJECT_DUE_TO_VM_MINIMIZE;
        return KAL_FALSE;
    }
#endif /*__MVM__*/
    if (jbt_general_non_poweron_reject())
    {
        kal_trace(TRACE_JBT_GROUP, JBT_COMMAND_REJECT_A);
        return KAL_FALSE;
    }

    if (ps_type == JSR82_SESSION_PS_RFCOMM)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_spp_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            con_id,
                            JBT_LIST_TYPE_SPP_SESSION);
    }
    else if (ps_type == JSR82_SESSION_PS_L2CAP)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_l2cap_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            con_id,
                            JBT_LIST_TYPE_L2CAP_SESSION);
    }
    else
    {
        ASSERT(0);
    }

    if (existing_entry == NULL)
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_CAN_NOT_FIND_EXISTING_ENTRY);
        return KAL_FALSE;
    }

    session_entry = (jbt_session_info*) existing_entry;

    subsession_entry = jbt_search_existing_subsession_entry(session_entry, JBT_LIST_SEARCH_TYPE_BY_INX, l2cap_id);

#if (JBT_MAX_SUBSESSION_NO > 1)
    if (subsession_entry == NULL)
    {
        ASSERT(0);
    }
#endif /* (JBT_MAX_SUBSESSION_NO > 1) */

    session_entry->transaction_id = transaction_id;
    session_entry->ps_type = ps_type;

    if (subsession_entry->subsession_state == JBT_SESSION_STATE_CONNECTED)
    {
        subsession_entry->subsession_state = JBT_SESSION_STATE_DISCONNECTING;
    }
    else
    {
        /* return FALSE: due to error session state */
        return KAL_FALSE;
    }

    parms = (bt_jsr82_disconnect_req_struct*) construct_local_para(sizeof(bt_jsr82_disconnect_req_struct), TD_UL);

    parms->identify = transaction_id;
    parms->index = con_id;
    parms->l2cap_id = l2cap_id;
    parms->ps_type = ps_type;
    jbt_send_msg(MSG_ID_BT_JSR82_DISCONNECT_REQ, MOD_JASYN, MOD_BT, BT_APP_SAP, (local_para_struct*) parms, NULL);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_handle_session_enabled_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_handle_session_enabled_result(bt_jsr82_enable_service_cnf_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 transaction_id;
    jbt_session_registration_result parms;
    jbt_list *existing_entry = NULL;
    jbt_session_info *session_entry = NULL;
    kal_uint8 list_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_JBT_HANDLE_SESSION_ENABLED_RESULT);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_SESSION_ENABLED_RESULT_MSGPS_TYPEx02X, msg->ps_type);

    /*
     * When enabling service, only transaction_id is valid! 2007-1103
     * It must use transaction_id to search the active list instead of sesion_inx !
     */
    if (msg->ps_type == JSR82_SESSION_PS_L2CAP)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_l2cap_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_TRANSACTION_ID,
                            msg->identify,
                            JBT_LIST_TYPE_L2CAP_SESSION);
        list_type = JBT_LIST_TYPE_L2CAP_SESSION;
    }
    else if (msg->ps_type == JSR82_SESSION_PS_RFCOMM)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_spp_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_TRANSACTION_ID,
                            msg->identify,
                            JBT_LIST_TYPE_SPP_SESSION);
        list_type = JBT_LIST_TYPE_SPP_SESSION;
    }
    else
    {
        ASSERT(0);
    }

    if (existing_entry == NULL)
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_CAN_NOT_FIND_EXISTING_ENTRY, JBT_LIST_SEARCH_TYPE_BY_INX, msg->index);
        parms.result = 0x01;
        goto report_it;
    }
    session_entry = (jbt_session_info*) existing_entry;

    /* Check result */
    kal_trace(TRACE_JBT_GROUP, JBT_MSGRESULTx02X, msg->result);

    if (msg->result != JSR82_SESSION_REGISTRARION_SUCCESS)
    {
        /* If enable service failed, reset entry to registration again */
        /* free channel_buf and RXTX RingBuf allocated for subsession */
        int i = 0;

        for (i = 0; i < JBT_MAX_SUBSESSION_NO; i++)
        {
            jbt_session_free_RWRingBuf(&session_entry->subsession[i]);
            jbt_reset_subsession_entry(&session_entry->subsession[i]);
        }
        /* Release channel buffer */
        if (session_entry->channel_buffer != NULL)
        {
            jbt_free_record(session_entry->channel_buffer);
#ifndef JBT_SUPPORT_ADM_MEM
            jvm_free(session_entry->channel_buffer);
#else
            kal_adm_free(jbt_get_mem_pool_id(),session_entry->channel_buffer);
#endif
            session_entry->channel_buffer = NULL;
        }

        /* Release ReadRingBuf and WriteRingBuf */
        jbt_free_one_existing_entry(list_type, existing_entry);
        session_entry->initiator = JBT_SESSION_INITIATOR_FALSE;
        session_entry->used = 0;
        parms.result = JBT_CMD_FAILED;
    }
    else
    {
        parms.result = JBT_CMD_SUCCESS;
        /* Keep the session_inx for this server session:2007-1103 */
        session_entry->index = msg->index;
        /* Kepp the channel number registered by this serice: 2007-1107 */
        session_entry->psm_channel = msg->channel;
    }
  report_it:

    parms.psm_channel = msg->channel;
    parms.ps_type = msg->ps_type;
    transaction_id = msg->identify;
    parms.transaction_id = msg->identify;
    parms.con_id = msg->index;

    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_SESSION_ENABLED_RESULT_PARMSPSM_CHANNELx04X, parms.psm_channel);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_SESSION_ENABLED_RESULT_PARMSPS_TYPEx02X, parms.ps_type);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_SESSION_ENABLED_RESULT_PARMSTRANSACTION_IDx08X, parms.transaction_id);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_SESSION_ENABLED_RESULT_PARMSCON_IDx02X, parms.con_id);

    jbt_event_callback(JBT_OPCODE_SESSION_REGISTRATION_RESULT, transaction_id, &parms);

}


/*****************************************************************************
 * FUNCTION
 *  jbt_handle_session_deregistration_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_handle_session_deregistration_result(bt_jsr82_disable_service_cnf_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 transaction_id;
    jbt_session_deregistration_result parms;
    jbt_list *existing_entry = NULL;
    jbt_session_info *session_entry = NULL;
    jbt_subsession *subsession_entry = NULL;
    kal_uint8 list_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_JBT_HANDLE_SESSION_DEREGISTRATION_RESULT);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_SESSION_DEREGISTRATION_RESULT_MSGPS_TYPEx02X, msg->ps_type);

    if (msg->ps_type == 0x00)
    {
        parms.result = JBT_CMD_FAILED;
        goto report_it;
    }
    if (msg->ps_type == JSR82_SESSION_PS_L2CAP)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_l2cap_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            msg->index,
                            JBT_LIST_TYPE_L2CAP_SESSION);
        list_type = JBT_LIST_TYPE_L2CAP_SESSION;
    }
    else if (msg->ps_type == JSR82_SESSION_PS_RFCOMM)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_spp_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            msg->index,
                            JBT_LIST_TYPE_SPP_SESSION);
        list_type = JBT_LIST_TYPE_SPP_SESSION;
    }
    else
    {
        ASSERT(0);
    }

    if (existing_entry == NULL)
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_CAN_NOT_FIND_EXISTING_ENTRY, JBT_LIST_SEARCH_TYPE_BY_INX, msg->index);
        parms.result = 0x01;
        goto report_it;
    }
    session_entry = (jbt_session_info*) existing_entry;
    /* Check result */
    if (msg->result == BT_JSR82_SESSION_DISABLED_SUCCESS)
    {
        int i = 0;

        kal_trace(TRACE_JBT_GROUP, JBT_SESSION_ENTRYINITIATORxD, session_entry->initiator);

        if (session_entry->initiator != JBT_SESSION_INITIATOR_FALSE)
        {
            ASSERT(0);
        }

        for (i = 0; i < JBT_MAX_SUBSESSION_NO; i++)
        {
            subsession_entry = &session_entry->subsession[i];
            if (subsession_entry->used == 1 && subsession_entry->subsession_state == JBT_SESSION_STATE_IDLE)
            {
                kal_trace(TRACE_JBT_GROUP, FUNC_JBT_DEREG_SERVICE_SUCCESS_FREE_RING_BUF);
                jbt_session_free_RWRingBuf(subsession_entry);
                jbt_reset_subsession_entry(subsession_entry);
            }
        }

        if (session_entry->channel_buffer != NULL)
        {
            kal_trace(TRACE_JBT_GROUP, FUNC_JBT_DEREG_SERVICE_SUCCESS_FREE_CHNL_BUF);
            jbt_free_record((kal_uint8*) session_entry->channel_buffer);
#ifndef JBT_SUPPORT_ADM_MEM
            jvm_free((kal_uint8*) session_entry->channel_buffer);
#else
            kal_adm_free(jbt_get_mem_pool_id(),(kal_uint8*) session_entry->channel_buffer);
#endif
            session_entry->channel_buffer = 0;
        }
        jbt_free_one_existing_entry(list_type, existing_entry);
        session_entry->initiator = JBT_SESSION_INITIATOR_FALSE;
        session_entry->used = 0;
        session_entry->psm_channel = 0;
        session_entry->subsession_count = 0;

        parms.result = JBT_CMD_SUCCESS;
    }
    else
    {
        parms.result = JBT_CMD_FAILED;

    }
  report_it:
    parms.ps_type = msg->ps_type;
    transaction_id = msg->identify;
    parms.transaction_id = msg->identify;
    parms.con_id = msg->index;
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_SESSION_DEREGISTRATION_RESULT_PARMSPS_TYPEx02X, parms.ps_type);
    kal_trace(
        TRACE_JBT_GROUP,
        JBT_JBT_HANDLE_SESSION_DEREGISTRATION_RESULT_PARMSTRANSACTION_IDx08X,
        parms.transaction_id);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_SESSION_DEREGISTRATION_RESULT_PARMSCON_IDx02X, parms.con_id);

    jbt_event_callback(JBT_OPCODE_SESSION_DEREGISTRATION_RESULT, transaction_id, &parms);

}


/*****************************************************************************
 * FUNCTION
 *  jbt_handle_session_turnon_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_handle_session_turnon_result(bt_jsr82_turnon_service_cnf_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jbt_session_turnon_result parms;
    jbt_list *existing_entry = NULL;
    jbt_session_info *session_entry = NULL;
    kal_uint8 list_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_JBT_HANDLE_SESSION_TURNON_RESULT);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_SESSION_TURNON_RESULT_MSGPS_TYPEx02X, msg->ps_type);

    if (msg->ps_type == JSR82_SESSION_PS_L2CAP)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_l2cap_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            msg->index,
                            JBT_LIST_TYPE_L2CAP_SESSION);
        list_type = JBT_LIST_TYPE_L2CAP_SESSION;
    }
    else if (msg->ps_type == JSR82_SESSION_PS_RFCOMM)
    {
        /* Because there is no client's con_ind reported, l2cap_id is zero here: 2007-1103 */
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_spp_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            msg->index,
                            JBT_LIST_TYPE_SPP_SESSION);
        list_type = JBT_LIST_TYPE_SPP_SESSION;
    }
    else
    {
        ASSERT(0);
    }

    if (existing_entry == NULL)
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_CAN_NOT_FIND_EXISTING_ENTRY, JBT_LIST_SEARCH_TYPE_BY_INX, msg->index);
        parms.result = 0x01;
        goto report_it;
    }
    session_entry = (jbt_session_info*) existing_entry;
    session_entry->turn_on_op.operation_state = JBT_OPERATION_STATE_NONE;
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_SESSION_TURNON_RESULT_MSGRESULTx02X, msg->result);

    /* Check result */
    if (msg->result != JSR82_SESSION_TURNON_SUCCESS)
    {
    #if 0
/* under construction !*/
    #endif /* 0 */ 
        parms.result = 0x01;
    }
    else
    {
        parms.result = 0x00;
    }
  report_it:
    parms.transaction_id = msg->identify;
    parms.con_id = msg->index;
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_SESSION_TURNON_RESULT_PARMSTRANSACTION_IDx08X, parms.transaction_id);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_SESSION_TURNON_RESULT_PARMSCON_IDx02X, parms.con_id);

    jbt_event_callback(JBT_OPCODE_SESSION_TURN_ON_RESULT, parms.transaction_id, &parms);

}


/*****************************************************************************
 * FUNCTION
 *  jbt_handle_session_turnoff_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_handle_session_turnoff_result(bt_jsr82_turnoff_service_cnf_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jbt_session_turnon_result parms;
    jbt_list *existing_entry = NULL;
    jbt_session_info *session_entry = NULL;
    kal_uint8 list_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_JBT_HANDLE_SESSION_TURNOFF_RESULT);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_SESSION_TURNOFF_RESULT_MSGPS_TYPEx02X, msg->ps_type);

    if (msg->ps_type == JSR82_SESSION_PS_RFCOMM)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_spp_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            msg->index,
                            JBT_LIST_TYPE_SPP_SESSION);
        list_type = JBT_LIST_TYPE_SPP_SESSION;
    }
    else if (msg->ps_type == JSR82_SESSION_PS_L2CAP)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_l2cap_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            msg->index,
                            JBT_LIST_TYPE_L2CAP_SESSION);
        list_type = JBT_LIST_TYPE_L2CAP_SESSION;
    }
    else
    {
        ASSERT(0);
    }

    if (existing_entry == NULL)
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_CAN_NOT_FIND_EXISTING_ENTRY, JBT_LIST_SEARCH_TYPE_BY_INX, msg->index);
        parms.result = 0x01;
        goto report_it;
    }

    session_entry = (jbt_session_info*) existing_entry;
    session_entry->turn_on_op.operation_state = JBT_OPERATION_STATE_NONE;
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_SESSION_TURNOFF_RESULT_MSGRESULTx02X, msg->result);

    /* Check result */
    if (msg->result != JSR82_SESSION_TURNOFF_SUCCESS)
    {
    #if 0
/* under construction !*/
/* under construction !*/
    #endif /* 0 */ 
        parms.result = 0x01;
    }
    else
    {
        parms.result = 0x00;
    }
  report_it:
    parms.transaction_id = msg->identify;
    parms.con_id = msg->index;
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_SESSION_TURNOFF_RESULT_PARMSTRANSACTION_IDx08X, parms.transaction_id);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_SESSION_TURNOFF_RESULT_PARMSCON_IDx02X, parms.con_id);

    jbt_event_callback(JBT_OPCODE_SESSION_TURN_OFF_RESULT, parms.transaction_id, &parms);

}



/*****************************************************************************
 * FUNCTION
 *  jbt_handle_session_connect_ind
 * DESCRIPTION
 *  For Server side: It will receive connect_ind
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_handle_session_connect_ind(bt_jsr82_connect_ind_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jbt_session_connect_ind parms;
    jbt_list *existing_entry = NULL;
    jbt_session_info *session_entry = NULL;
    jbt_subsession *subsession_entry = NULL;
    kal_uint8 list_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg->ps_type == JSR82_SESSION_PS_L2CAP)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_l2cap_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            msg->index,
                            JBT_LIST_TYPE_L2CAP_SESSION);
        list_type = JBT_LIST_TYPE_L2CAP_SESSION;
    }
    else if (msg->ps_type == JSR82_SESSION_PS_RFCOMM)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_spp_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            msg->index,
                            JBT_LIST_TYPE_SPP_SESSION);
        list_type = JBT_LIST_TYPE_SPP_SESSION;
    }
    else
    {
        ASSERT(0);
    }

    if (existing_entry == NULL)
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_CAN_NOT_FIND_EXISTING_ENTRY, JBT_LIST_SEARCH_TYPE_BY_INX, msg->index);
        parms.result = JBT_CMD_FAILED;
        /*
         * [Question]: 2007-1103 
         * If the buffer is allocated when sending connection request, but due to fail to find its corresponding entry 
         * This will cause memory leak problem!
         */

        goto report_it;
    }
    else
    {
        session_entry = (jbt_session_info*) existing_entry;
    }

    /* Search will find a subsession_entry which already allocates RX/TX RingBuf and sets used as 1: 2007-1113 */
    subsession_entry = jbt_server_find_one_subsession_entry(session_entry);

#if (JBT_MAX_SUBSESSION_NO > 1)
    if (subsession_entry == NULL)
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_CAN_NOT_FIND_EXISTING_SUBENTRY, JBT_LIST_SEARCH_TYPE_BY_INX, msg->index);
        parms.result = JBT_CMD_FAILED;
        /*
         * [Question]: 2007-1103 
         * If the buffer is allocated when sending connection request, but due to fail to find its corresponding entry 
         * This will cause memory leak problem!
         */

        goto report_it;
    }
#else /* (JBT_MAX_SUBSESSION_NO > 1) */
    if (subsession_entry == NULL)
    {
        ASSERT(0);
    }
#endif /* (JBT_MAX_SUBSESSION_NO > 1) */

    if (msg->rsp_result == JSR82_SESSION_CONNECT_IND_CONNECTED)
    {
        parms.result = JBT_CMD_SUCCESS;
        session_entry->active_count++;
    #if (JBT_MAX_SUBSESSION_NO == 1)
        ASSERT(session_entry->active_count == 1);
    #endif 
        subsession_entry->subsession_state = JBT_SESSION_STATE_CONNECTED;
        subsession_entry->subsession_id = msg->l2cap_id;
    }
    else
    {
        parms.result = JBT_CMD_FAILED;
    }

  report_it:
    parms.con_id = msg->index;
    parms.transaction_id = msg->identify;
    /* Modify 2007-1215: report to VM, bd_addr[] from high byte to low byte */
    jbt_ConvertBdAddrOrder(parms.bd_addr, msg->bd_addr);
    parms.ps_type = msg->ps_type;
    parms.mtu = msg->mtu;
    parms.channel = msg->channel;
    parms.l2cap_id = msg->l2cap_id;
    kal_trace(TRACE_FUNC, JBT_BT_HANDLE_SESSION_CONNECT_IND);
    kal_trace(
        TRACE_JBT_GROUP,
        JBT_BT_HANDLE_SESSION_CONNECT_IND_ADDRx02Xx02Xx02Xx02Xx02Xx02X,
        parms.bd_addr[0],
        parms.bd_addr[1],
        parms.bd_addr[2],
        parms.bd_addr[3],
        parms.bd_addr[4],
        parms.bd_addr[5]);
    kal_trace(TRACE_JBT_GROUP, JBT_BT_HANDLE_SESSION_CONNECT_IND_PARMSRESULTx02X, parms.result);
    kal_trace(TRACE_JBT_GROUP, JBT_BT_HANDLE_SESSION_CONNECT_IND_PARMSTRANSACTION_IDx08X, parms.transaction_id);
    kal_trace(TRACE_JBT_GROUP, JBT_BT_HANDLE_SESSION_CONNECT_IND_PARMSCON_IDx02X, parms.con_id);
    kal_trace(TRACE_JBT_GROUP, JBT_BT_HANDLE_SESSION_CONNECT_IND_PARMSL2CAP_IDx04X, parms.l2cap_id);
    kal_trace(TRACE_JBT_GROUP, JBT_BT_HANDLE_SESSION_CONNECT_IND_PARMSMTUx04X, parms.mtu);
    kal_trace(TRACE_JBT_GROUP, JBT_BT_HANDLE_SESSION_CONNECT_IND_PARMSPS_TYPEx02X, parms.ps_type);

    jbt_event_callback(JBT_OPCODE_SESSION_CON_IND, parms.transaction_id, &parms);
}


/*****************************************************************************
 * FUNCTION
 *  jbt_handle_session_disconnect_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_handle_session_disconnect_ind(bt_jsr82_disconnect_ind_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jbt_session_disconnect_ind parms;
    jbt_list *existing_entry = NULL;
    jbt_session_info *session_entry = NULL;
    jbt_subsession *subsession_entry = NULL;
    kal_uint8 list_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_BT_HANDLE_SESSION_DISCONNECT_IND);
    kal_trace(TRACE_JBT_GROUP, JBT_BT_HANDLE_SESSION_DISCONNECT_IND_PARMSPS_TYPEx02X, msg->ps_type);

    if (msg->ps_type == JSR82_SESSION_PS_L2CAP)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_l2cap_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            msg->index,
                            JBT_LIST_TYPE_L2CAP_SESSION);
        list_type = JBT_LIST_TYPE_L2CAP_SESSION;
    }
    else
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_spp_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            msg->index,
                            JBT_LIST_TYPE_SPP_SESSION);
        list_type = JBT_LIST_TYPE_SPP_SESSION;
    }
    if (existing_entry == NULL)
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_CAN_NOT_FIND_EXISTING_ENTRY, JBT_LIST_SEARCH_TYPE_BY_INX, msg->index);
        parms.result = JBT_CMD_FAILED;
        return;
    }
    session_entry = (jbt_session_info*) existing_entry;

    subsession_entry = jbt_search_existing_subsession_entry(session_entry, JBT_LIST_SEARCH_TYPE_BY_INX, msg->l2cap_id);
#if (JBT_MAX_SUBSESSION_NO > 1)
    if (subsession_entry == NULL)
    {
        ASSERT(0);
    }
#endif /* (JBT_MAX_SUBSESSION_NO > 1) */

    /* Add by mtk01411: Simulate a RX_READY_IND to let VM read all left data in RX Buffer: 2008-0105 */
    {
        jbt_session_rx_ready_ind parms;

        /* msg->identify: It must be session_inx. ie. con_id for application */
        parms.con_id = msg->index;
        parms.l2cap_id = msg->l2cap_id;
        parms.length = 65535;   /* length=65535 is used to indicate this RX_READY_IND is triggered by JASYNC processing DISCONNECT_IND */
        jbt_event_callback(JBT_OPCODE_SESSION_RX_READY_IND, parms.con_id, &parms);
    }

    session_entry->active_count--;
#if (JBT_MAX_SUBSESSION_NO == 1)
    ASSERT(session_entry->active_count == 0);
#endif 

    if (session_entry->initiator == JBT_SESSION_INITIATOR_TRUE)
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_DISC_IND_CLIENT_FREE_RINGBUF);
        jbt_reset_subsession_entry(subsession_entry);
        jbt_session_free_RWRingBuf(subsession_entry);
    #ifdef __USE_BT_RING_BUF_API__
        RING_BufFlush(&(subsession_entry->ReadRingBuf));
        RING_BufFlush(&(subsession_entry->WriteRingBuf));
    #else /* __USE_BT_RING_BUF_API__ */ 
        JBTRING_BufFlush(&(subsession_entry->ReadRingBuf));
        JBTRING_BufFlush(&(subsession_entry->WriteRingBuf));
    #endif /* __USE_BT_RING_BUF_API__ */ 
        if (session_entry->channel_buffer != NULL)
        {
            jbt_free_record(session_entry->channel_buffer);
#ifndef JBT_SUPPORT_ADM_MEM
            jvm_free(session_entry->channel_buffer);
#else
            kal_adm_free(jbt_get_mem_pool_id(),session_entry->channel_buffer);
#endif
            session_entry->channel_buffer = NULL;
        }
        jbt_free_one_existing_entry(list_type, existing_entry);
        session_entry->initiator = JBT_SESSION_INITIATOR_FALSE;
        session_entry->used = 0;
    }
    else
    {

        if (session_entry->subsession_count == 1)
        {
            /* For Session Server: Only reset pRead and pEnd pointer: Session Server's Read and Write RingBuf will be released when service deregistration */
        #ifdef __USE_BT_RING_BUF_API__
            RING_BufFlush(&(subsession_entry->ReadRingBuf));
            RING_BufFlush(&(subsession_entry->WriteRingBuf));
        #else /* __USE_BT_RING_BUF_API__ */ 
            JBTRING_BufFlush(&(subsession_entry->ReadRingBuf));
            JBTRING_BufFlush(&(subsession_entry->WriteRingBuf));
        #endif /* __USE_BT_RING_BUF_API__ */ 
            kal_trace(TRACE_JBT_GROUP, FUNC_JBT_DISC_IND_SRV_RESET_RW_PTR);
            /*
             * Because this is the only one subsession_entry for Session Server
             * Thus, is is allocated when registration service, it can not be freed in this case
             * Can not set subsession_entry->used as zero!
             */
            /* For Server's provided service: at least one subsesion_entry is supported */
            jbt_reset_subsession_entry_except_used(subsession_entry);
        }
    #if (JBT_MAX_SUBSESSION_NO == 1)
        else
        {
            ASSERT(0);
        }
    #else /* (JBT_MAX_SUBSESSION_NO == 1) */
        else if (session_entry->subsession_count > 1)
        {
            kal_trace(TRACE_JBT_GROUP, FUNC_JBT_DISC_IND_SUBSESSION_COUNT, session_entry->subsession_count);
            session_entry->subsession_count--;
            jbt_reset_subsession_entry(subsession_entry);
            jbt_session_free_RWRingBuf(subsession_entry);
        #ifdef __USE_BT_RING_BUF_API__
            RING_BufFlush(&(subsession_entry->ReadRingBuf));
            RING_BufFlush(&(subsession_entry->WriteRingBuf));
        #else /* __USE_BT_RING_BUF_API__ */ 
            JBTRING_BufFlush(&(subsession_entry->ReadRingBuf));
            JBTRING_BufFlush(&(subsession_entry->WriteRingBuf));
        #endif /* __USE_BT_RING_BUF_API__ */ 
        }
        else
        {
            ASSERT(0);
        }
    #endif /* (JBT_MAX_SUBSESSION_NO == 1) */
    }

    parms.con_id = msg->index;
    parms.l2cap_id = msg->l2cap_id;
    parms.result = JBT_CMD_SUCCESS;
    kal_trace(TRACE_JBT_GROUP, JBT_BT_HANDLE_SESSION_DISCONNECT_IND_PARMSCON_IDx02X, parms.con_id);
    kal_trace(TRACE_JBT_GROUP, JBT_BT_HANDLE_SESSION_DISCONNECT_IND_PARMSL2CAP_IDx04X, parms.l2cap_id);
    jbt_event_callback(JBT_OPCODE_SESSION_DISCONNECT_IND, parms.con_id, &parms);

}


/*****************************************************************************
 * FUNCTION
 *  jbt_handle_session_connect_req_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_handle_session_connect_req_cnf(bt_jsr82_connect_cnf_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jbt_session_connect_cnf parms;
    jbt_list *existing_entry = NULL;
    jbt_session_info *session_entry = NULL;
    jbt_subsession *subsession_entry = NULL;
    kal_uint8 list_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* For connect_req_result: An existing entry allocated for connect_req has no index information only transaction_id */
    kal_trace(TRACE_FUNC, JBT_BT_HANDLE_SESSION_CONNECT_REQ_CNF);
    kal_trace(TRACE_JBT_GROUP, JBT_BT_HANDLE_SESSION_CONNECT_REQ_CNF_PARMSPS_TYPEx02X, msg->ps_type);

    /* Modify by mtk01411: jbt_search_an_existing_entry()'s 3rd parameter: from msg->index to msg->identify */
    if (msg->ps_type == JSR82_SESSION_PS_L2CAP)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_l2cap_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_TRANSACTION_ID,
                            msg->identify,
                            JBT_LIST_TYPE_L2CAP_SESSION);
        list_type = JBT_LIST_TYPE_L2CAP_SESSION;
    }
    else if (msg->ps_type == JSR82_SESSION_PS_RFCOMM)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_spp_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_TRANSACTION_ID,
                            msg->identify,
                            JBT_LIST_TYPE_SPP_SESSION);
        list_type = JBT_LIST_TYPE_SPP_SESSION;
    }
    else
    {
        ASSERT(0);
    }

    if (existing_entry == NULL)
    {
        kal_trace(
            TRACE_JBT_GROUP,
            FUNC_JBT_CAN_NOT_FIND_EXISTING_ENTRY,
            JBT_LIST_SEARCH_TYPE_BY_TRANSACTION_ID,
            msg->identify);
        parms.result = 0x01;
        /*
         * [Question]: 2007-1103 
         * If the buffer is allocated when sending connection request, but due to fail to find its corresponding entry 
         * This will cause memory leak problem!
         */

        goto report_it;
    }
    session_entry = (jbt_session_info*) existing_entry;
    /* Check result */
    session_entry->con_req_op.operation_state = JBT_OPERATION_STATE_NONE;
    kal_trace(TRACE_JBT_GROUP, JBT_BT_HANDLE_SESSION_CONNECT_REQ_CNF_MSGRESULTx02X, msg->result);
    /* Search the actual subsession_entry for this connection_request_cnf:2007-1103 */
    subsession_entry = jbt_search_existing_subsession_entry(session_entry, JBT_LIST_SEARCH_TYPE_BY_TRANSACTION_ID, msg->identify);

#if (JBT_MAX_SUBSESSION_NO > 1)
    if (subsession_entry == NULL)
    {
        kal_trace(
            TRACE_JBT_GROUP,
            FUNC_JBT_CAN_NOT_FIND_EXISTING_SUBENTRY,
            JBT_LIST_SEARCH_TYPE_BY_TRANSACTION_ID,
            msg->identify);
        parms.result = 0x01;
        /*
         * [Question]: 2007-1103 
         * If the buffer is allocated when sending connection request, but due to fail to find its corresponding entry 
         * This will cause memory leak problem!
         */

        goto report_it;
    }
#endif /* (JBT_MAX_SUBSESSION_NO > 1) */

    if (msg->result != JSR82_SESSION_CONNECT_CLIENT_SUCCESS)
    {
        /* Free the memory space allocated for RingBuf previously: Add by mtk01411: 2007-1024 */
        jbt_reset_session_entry(list_type, existing_entry, subsession_entry);
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
    #endif /* 0 */ 
        parms.result = JBT_CMD_FAILED;
    }
    else
    {
        parms.result = JBT_CMD_SUCCESS;
        /* Because the connect_request's result is suceesful, now keeps its session_index for this spp session entry:2007-1024 */
        session_entry->index = msg->index;
        session_entry->active_count++;
    #if (JBT_MAX_SUBSESSION_NO == 1)
        ASSERT(session_entry->active_count == 1);
    #endif 
        /* Keep the l2cap_id value, if the l2cap_id is 0: it is a spp session; otherwise, it is a l2cap session: Add 2007-1103 */
        subsession_entry->subsession_id = msg->l2cap_id;
        subsession_entry->subsession_state = JBT_SESSION_STATE_CONNECTED;

    }
  report_it:
    parms.transaction_id = msg->identify;
    parms.con_id = msg->index;  /* This value is used as identifier for this SPP connection */
    parms.l2cap_id = msg->l2cap_id;
    kal_trace(TRACE_JBT_GROUP, JBT_BT_HANDLE_SESSION_CONNECT_REQ_CNF_PARMSTRANSACTION_IDx08X, parms.transaction_id);
    kal_trace(TRACE_JBT_GROUP, JBT_BT_HANDLE_SESSION_CONNECT_REQ_CNF_PARMSCON_IDx02X, parms.con_id);
    kal_trace(TRACE_JBT_GROUP, JBT_BT_HANDLE_SESSION_CONNECT_REQ_CNF_PARMSL2CAP_IDx04X, parms.l2cap_id);

    jbt_event_callback(JBT_OPCODE_SESSION_CON_CNF, parms.transaction_id, &parms);
}



/*****************************************************************************
 * FUNCTION
 *  jbt_handle_session_rx_ready_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_handle_session_rx_ready_ind(bt_jsr82_rx_ready_ind_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jbt_session_rx_ready_ind parms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* msg->identify: It must be session_inx. ie. con_id for application */
    parms.con_id = msg->index;
    parms.l2cap_id = msg->l2cap_id;
    parms.length = msg->length;
    jbt_event_callback(JBT_OPCODE_SESSION_RX_READY_IND, parms.con_id, &parms);
}



/*****************************************************************************
 * FUNCTION
 *  jbt_handle_session_tx_ready_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_handle_session_tx_ready_ind(bt_jsr82_tx_ready_ind_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jbt_session_tx_ready_ind parms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* msg->identify: It must be session_inx. ie. con_id for application */
    parms.con_id = msg->index;
    parms.l2cap_id = msg->l2cap_id;
    jbt_event_callback(JBT_OPCODE_SESSION_TX_READY_IND, parms.con_id, &parms);
}


/*****************************************************************************
 * FUNCTION
 *  jbt_reset_subsession_entry_except_used
 * DESCRIPTION
 *  
 * PARAMETERS
 *  subsession_entry        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_reset_subsession_entry_except_used(jbt_subsession *subsession_entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    subsession_entry->transaction_id = 0;
    subsession_entry->subsession_id = 0;
    subsession_entry->is_tx_empty = KAL_TRUE;
    subsession_entry->notifyReadyToWrite = KAL_FALSE;
    subsession_entry->readyToRead = KAL_TRUE;
    subsession_entry->subsession_state = JBT_SESSION_STATE_IDLE;

}


/*****************************************************************************
 * FUNCTION
 *  jbt_reset_subsession_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  subsession_entry        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_reset_subsession_entry(jbt_subsession *subsession_entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    subsession_entry->used = 0;
    jbt_reset_subsession_entry_except_used(subsession_entry);
}


/*****************************************************************************
 * FUNCTION
 *  jbt_session_RxBytes
 * DESCRIPTION
 *  This function is called to calculate credits information
 * PARAMETERS
 *  session_type        [IN]        
 *  session_inx         [IN]        
 *  subsession_id       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int16 jbt_session_RxBytes(kal_uint8 session_type, kal_uint32 session_inx, kal_uint16 subsession_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jbt_list *existing_entry = NULL;
    jbt_session_info *session_entry = NULL;
    jbt_subsession *subsession_entry = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jbt_general_non_poweron_reject())
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_REJCT_DUE_TO_POWEROFF_ONGOING);
        return JBT_SESSION_NOT_POWERON;
    }

    if (session_type == JBT_SESSION_TYPE_SPP)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_spp_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            session_inx,
                            JBT_LIST_TYPE_SPP_SESSION);
    }
    else if (session_type == JBT_SESSION_TYPE_L2CAP)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_l2cap_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            session_inx,
                            JBT_LIST_TYPE_L2CAP_SESSION);
    }

    if (existing_entry == NULL)
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_CAN_NOT_FIND_EXISTING_ENTRY, JBT_LIST_SEARCH_TYPE_BY_INX, session_inx);
        ASSERT(0);
    }
    session_entry = (jbt_session_info*) existing_entry;
    subsession_entry = jbt_search_existing_subsession_entry(session_entry, JBT_LIST_SEARCH_TYPE_BY_INX, subsession_id);
#if (JBT_MAX_SUBSESSION_NO > 1)
    if (subsession_entry == NULL)
    {
        ASSERT(0);
    }
#endif /* (JBT_MAX_SUBSESSION_NO > 1) */
#ifdef __USE_BT_RING_BUF_API__
    return RING_DataLen(&(subsession_entry->ReadRingBuf));
#else 
    return JBTRING_DataLen(&(subsession_entry->ReadRingBuf));
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  jbt_session_RxFree
 * DESCRIPTION
 *  
 * PARAMETERS
 *  search_type         [IN]        
 *  session_type        [IN]        
 *  subsession_id       [IN]        
 *  value               [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int16 jbt_session_RxFree(kal_uint8 search_type, kal_uint8 session_type, kal_uint16 subsession_id, kal_uint32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    jbt_list *existing_entry = NULL;
    jbt_session_info *session_entry = NULL;
    jbt_subsession *subsession_entry = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jbt_general_non_poweron_reject())
    {
        kal_trace(TRACE_INFO, FUNC_JBT_REJCT_DUE_TO_POWEROFF_ONGOING);
        return JBT_SESSION_NOT_POWERON;
    }

    if (session_type == JBT_SESSION_TYPE_SPP)
    {
        existing_entry = jbt_search_an_existing_entry(&jbt_spp_context.activeList, search_type, value, JBT_LIST_TYPE_SPP_SESSION);
    }
    else if (session_type == JBT_SESSION_TYPE_L2CAP)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_l2cap_context.activeList,
                            search_type,
                            value,
                            JBT_LIST_TYPE_L2CAP_SESSION);
    }

    if (existing_entry == NULL)
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_CAN_NOT_FIND_EXISTING_ENTRY, search_type, value);
        ASSERT(0);
    }
    session_entry = (jbt_session_info*) existing_entry;

    subsession_entry = jbt_search_existing_subsession_entry(session_entry, JBT_LIST_SEARCH_TYPE_BY_INX, subsession_id);
#if (JBT_MAX_SUBSESSION_NO > 1)
    if (subsession_entry == NULL)
    {
        ASSERT(0);
    }
#endif /* (JBT_MAX_SUBSESSION_NO > 1) */

#ifdef __USE_BT_RING_BUF_API__
    return RING_FreeSpace(&(subsession_entry->ReadRingBuf));
#else 
    return JBTRING_FreeSpace(&(subsession_entry->ReadRingBuf));
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  jbt_session_DevRX
 * DESCRIPTION
 *  
 * PARAMETERS
 *  session_type        [IN]        
 *  session_inx         [IN]        
 *  subsession_id       [IN]        
 *  buf                 [IN]        
 *  len                 [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
kal_int8 jbt_session_DevRX(
            kal_uint8 session_type,
            kal_uint32 session_inx,
            kal_uint16 subsession_id,
            char buf[],
            U16 *len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 rc = 0;    /* 0: Means succseesful */
    jbt_list *existing_entry = NULL;
    jbt_session_info *session_entry = NULL;
    kal_int16 actual_write_len = 0, wanted_to_write_len = *len;
    jbt_subsession *subsession_entry = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jbt_general_non_poweron_reject())
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_REJCT_DUE_TO_POWEROFF_ONGOING);
        return JBT_SESSION_NOT_POWERON;
    }

    if (session_type == JBT_SESSION_TYPE_SPP)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_spp_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            session_inx,
                            JBT_LIST_TYPE_SPP_SESSION);
    }
    else if (session_type == JBT_SESSION_TYPE_L2CAP)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_l2cap_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            session_inx,
                            JBT_LIST_TYPE_L2CAP_SESSION);
    }

    if (existing_entry == NULL)
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_CAN_NOT_FIND_EXISTING_ENTRY, JBT_LIST_SEARCH_TYPE_BY_INX, session_inx);
        ASSERT(0);
    }
    session_entry = (jbt_session_info*) existing_entry;

    subsession_entry = jbt_search_existing_subsession_entry(session_entry, JBT_LIST_SEARCH_TYPE_BY_INX, subsession_id);
#if (JBT_MAX_SUBSESSION_NO)
    if (subsession_entry == NULL)
    {
        ASSERT(0);
    }
#endif /* (JBT_MAX_SUBSESSION_NO) */ 

    /* Check if this session_entry is in CONNECTED state */
    if (subsession_entry->subsession_state != JBT_SESSION_STATE_CONNECTED)
    {
        return JBT_SESSION_ERR_STATE;
    }

#ifdef __USE_BT_RING_BUF_API__
    actual_write_len = RING_WriteData(&(subsession_entry->ReadRingBuf), buf, *len);
#else 
    actual_write_len = JBTRING_WriteData(&(subsession_entry->ReadRingBuf), buf, *len);
#endif 

    /*
     * Add by mtk01411: 2007-1015 
     * Because the creadit is computed as Ring's size - total_data_len:
     * If this RFCOMM's pkt is received, it means that the data contained in this pkt can be put to Ring Buf!
     * It is necessary to check if there is still free space: If it has, it means the pWrite pointer is wrapped to start position
     * It must copy the left data in the pkt to Ring Buf continusly
     */
#ifdef __USE_BT_RING_BUF_API__
    if (RING_FreeSpace(&(subsession_entry->ReadRingBuf)))
#else 
    if (JBTRING_FreeSpace(&(subsession_entry->ReadRingBuf)))
#endif 
    {
        /*
         * In this case, because pWrite pointer is wrapped to start poisiton of buffer at last RING_WirteData()
         * So if there is still free space and the wanted_to_write_len is larger than actual_write_len of last RING_WirteData(): 
         */
        if (actual_write_len < wanted_to_write_len)
    #ifdef __USE_BT_RING_BUF_API__
            RING_WriteData(
                &(subsession_entry->ReadRingBuf),
                buf + actual_write_len,
                wanted_to_write_len - actual_write_len);
    #else /* __USE_BT_RING_BUF_API__ */ 
            JBTRING_WriteData(
                &(subsession_entry->ReadRingBuf),
                buf + actual_write_len,
                wanted_to_write_len - actual_write_len);
    #endif /* __USE_BT_RING_BUF_API__ */ 
    }

    if (subsession_entry->readyToRead == KAL_TRUE)
    {
        kal_int16 total_data_len = 0;

        /* Report(("In jbt_spp_DevRx(): Set readyToRead FALSE")); */
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_SET_READY_TO_READ_AS_FALSE);
    #ifdef __USE_BT_RING_BUF_API__
        total_data_len = RING_DataLen(&(subsession_entry->ReadRingBuf));
    #else 
        total_data_len = JBTRING_DataLen(&(subsession_entry->ReadRingBuf));
    #endif 
        subsession_entry->readyToRead = KAL_FALSE;
        /* BT stack must notify the JBT that the event READY_TO_READ_IND */
        bt_jsr82_SessionApRxReadyInd(session_inx, subsession_id, total_data_len);
    }
    return rc;

}


/*****************************************************************************
 * FUNCTION
 *  jbt_session_CheckReadyToWrite
 * DESCRIPTION
 *  
 * PARAMETERS
 *  session_type        [IN]        
 *  session_inx         [IN]        
 *  subsession_id       [IN]        
 *  one_session         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_session_CheckReadyToWrite(U8 session_type, U8 session_inx, kal_uint16 subsession_id, void *one_session)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jbt_list *existing_entry = NULL;
    jbt_session_info *session = NULL;
    jbt_session_info *session_entry = NULL;
    jbt_subsession *subsession_entry = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    session = (jbt_session_info*) one_session;

    if (jbt_general_non_poweron_reject())
    {
        kal_trace(TRACE_INFO, FUNC_JBT_REJCT_DUE_TO_POWEROFF_ONGOING);
        return;
    }

    if (session == NULL)
    {
        if (session_type == JBT_SESSION_TYPE_SPP)
        {
            existing_entry = jbt_search_an_existing_entry(
                                &jbt_spp_context.activeList,
                                JBT_LIST_SEARCH_TYPE_BY_INX,
                                session_inx,
                                JBT_LIST_TYPE_SPP_SESSION);
        }
        else if (session_type == JBT_SESSION_TYPE_L2CAP)
        {
            existing_entry = jbt_search_an_existing_entry(
                                &jbt_l2cap_context.activeList,
                                JBT_LIST_SEARCH_TYPE_BY_INX,
                                session_inx,
                                JBT_LIST_TYPE_L2CAP_SESSION);
        }

        if (existing_entry == NULL)
        {
            kal_trace(TRACE_JBT_GROUP, FUNC_JBT_CAN_NOT_FIND_EXISTING_ENTRY, JBT_LIST_SEARCH_TYPE_BY_INX, session_inx);
            return;
        }
        session_entry = (jbt_session_info*) existing_entry;
    }
    else
    {
        session_entry = session;
    }

    subsession_entry = jbt_search_existing_subsession_entry(session_entry, JBT_LIST_SEARCH_TYPE_BY_INX, subsession_id);
#if (JBT_MAX_SUBSESSION_NO > 1)
    if (subsession_entry == NULL)
    {
        ASSERT(0);
    }
#endif /* (JBT_MAX_SUBSESSION_NO > 1) */
    if (subsession_entry->notifyReadyToWrite)
    {
        subsession_entry->notifyReadyToWrite = KAL_FALSE;
        /* BT stack must notify JBT that it's time to write data continusly: READY_TO_WRITE_IND */
        bt_jsr82_SessionApTxReadyInd(session_inx, subsession_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jbt_session_ReturnBuf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  session_type        [IN]        
 *  session_inx         [IN]        
 *  subsession_id       [IN]        
 *  buf                 [IN]        
 *  len                 [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_session_ReturnBuf(kal_uint8 session_type, kal_uint32 session_inx, kal_uint16 subsession_id, char *buf, U16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    jbt_list *existing_entry = NULL;
    jbt_session_info *session_entry = NULL;
    jbt_subsession *subsession_entry = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jbt_general_non_poweron_reject())
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_REJCT_DUE_TO_POWEROFF_ONGOING);
        return;
    }

    if (session_type == JBT_SESSION_TYPE_SPP)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_spp_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            session_inx,
                            JBT_LIST_TYPE_SPP_SESSION);
    }
    else if (session_type == JBT_SESSION_TYPE_L2CAP)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_l2cap_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            session_inx,
                            JBT_LIST_TYPE_L2CAP_SESSION);
    }

    if (existing_entry == NULL)
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_CAN_NOT_FIND_EXISTING_ENTRY, JBT_LIST_SEARCH_TYPE_BY_INX, session_inx);
        return;
    }
    session_entry = (jbt_session_info*) existing_entry;

    subsession_entry = jbt_search_existing_subsession_entry(session_entry, JBT_LIST_SEARCH_TYPE_BY_INX, subsession_id);
#if (JBT_MAX_SUBSESSION_NO > 1)
    if (subsession_entry == NULL)
    {
        ASSERT(0);
    }
#endif /* (JBT_MAX_SUBSESSION_NO > 1) */

#ifdef __USE_BT_RING_BUF_API__
    RING_BufDelete(&(subsession_entry->WriteRingBuf), len);
#else 
    JBTRING_BufDelete(&(subsession_entry->WriteRingBuf), len);
#endif 

    if (subsession_entry->WriteRingBuf.pRead == subsession_entry->WriteRingBuf.pWrite)
    {
        subsession_entry->is_tx_empty = KAL_TRUE;
    }

    /* Check this add by mtk01411: 2007-1109 */
    if (jbt_session_BufFreeSpace(session_type, session_inx, subsession_id, JBT_SESSION_TX_BUF_TYPE) == 0)
    {
        subsession_entry->notifyReadyToWrite = KAL_TRUE;
    }

    jbt_session_CheckReadyToWrite(session_type, session_inx, subsession_id, session_entry);

}


/*****************************************************************************
 * FUNCTION
 *  jbt_session_DevTX
 * DESCRIPTION
 *  
 * PARAMETERS
 *  session_type        [IN]        
 *  session_inx         [IN]        
 *  subsession_id       [IN]        
 *  buf                 [IN]        
 *  len                 [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int8 jbt_session_DevTX(
            kal_uint8 session_type,
            kal_uint32 session_inx,
            kal_uint16 subsession_id,
            char **buf,
            U16 *len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 rc = 0;    /* Means successful */

    jbt_list *existing_entry = NULL;
    jbt_session_info *session_entry = NULL;
    jbt_subsession *subsession_entry = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jbt_general_non_poweron_reject())
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_REJCT_DUE_TO_POWEROFF_ONGOING);
        return JBT_SESSION_NOT_POWERON;
    }

    if (session_type == JBT_SESSION_TYPE_SPP)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_spp_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            session_inx,
                            JBT_LIST_TYPE_SPP_SESSION);
    }
    else if (session_type == JBT_SESSION_TYPE_L2CAP)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_l2cap_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            session_inx,
                            JBT_LIST_TYPE_L2CAP_SESSION);
    }

    if (existing_entry == NULL)
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_CAN_NOT_FIND_EXISTING_ENTRY, JBT_LIST_SEARCH_TYPE_BY_INX, session_inx);
        ASSERT(0);
    }
    session_entry = (jbt_session_info*) existing_entry;

    subsession_entry = jbt_search_existing_subsession_entry(session_entry, JBT_LIST_SEARCH_TYPE_BY_INX, subsession_id);
#if (JBT_MAX_SUBSESSION_NO > 1)
    if (subsession_entry == NULL)
    {
        ASSERT(0);
    }
#endif /* (JBT_MAX_SUBSESSION_NO > 1) */

    /* Check if this session_entry is in CONNECTED state */
    if (subsession_entry->subsession_state != JBT_SESSION_STATE_CONNECTED)
    {
        return JBT_SESSION_ERR_STATE;
    }
#ifdef __USE_BT_RING_BUF_API__
    RING_GetDataPtr(&(subsession_entry->WriteRingBuf), buf, (kal_int16*) len);
#else 
    JBTRING_GetDataPtr(&(subsession_entry->WriteRingBuf), buf, (kal_int16*) len);
#endif 
    return rc;

}


/*****************************************************************************
 * FUNCTION
 *  jbt_session_DevTxEmpty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  session_type        [IN]        
 *  session_inx         [IN]        
 *  subsession_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_session_DevTxEmpty(kal_uint8 session_type, kal_uint8 session_inx, kal_uint16 subsession_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jbt_list *existing_entry = NULL;
    jbt_session_info *session_entry = NULL;
    jbt_subsession *subsession_entry = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jbt_general_non_poweron_reject())
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_REJCT_DUE_TO_POWEROFF_ONGOING);
        return;
    }

    if (session_type == JBT_SESSION_TYPE_SPP)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_spp_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            session_inx,
                            JBT_LIST_TYPE_SPP_SESSION);
    }
    else if (session_type == JBT_SESSION_TYPE_L2CAP)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_l2cap_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            session_inx,
                            JBT_LIST_TYPE_L2CAP_SESSION);
    }

    if (existing_entry == NULL)
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_CAN_NOT_FIND_EXISTING_ENTRY, JBT_LIST_SEARCH_TYPE_BY_INX, session_inx);
        return;
    }
    session_entry = (jbt_session_info*) existing_entry;

    subsession_entry = jbt_search_existing_subsession_entry(session_entry, JBT_LIST_SEARCH_TYPE_BY_INX, subsession_id);
#if (JBT_MAX_SUBSESSION_NO > 1)
    if (subsession_entry == NULL)
    {
        ASSERT(0);
    }
#endif /* (JBT_MAX_SUBSESSION_NO > 1) */
    subsession_entry->is_tx_empty = KAL_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  jbt_session_allocate_RWRingBuf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  session_type            [IN]        
 *  subsession_entry        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int8 jbt_session_allocate_RWRingBuf(kal_uint8 session_type, jbt_subsession *subsession_entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 rc = 0;    /* rc=0 : Means successful */
    kal_uint16 rx_size = 0, tx_size = 0;
    kal_uint8 rx_block_inx = 0, tx_block_inx = 0; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jbt_general_non_poweron_reject())
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_REJCT_DUE_TO_POWEROFF_ONGOING);
        return JBT_SESSION_NOT_POWERON;
    }

    if (session_type == JBT_SESSION_TYPE_SPP)
    {
        rx_size = JBT_SESSION_SPP_RX_BUFSIZE;
        tx_size = JBT_SESSION_SPP_TX_BUFSIZE;
    }
    else if (session_type == JBT_SESSION_TYPE_L2CAP)
    {
        rx_size = JBT_SESSION_L2CAP_TX_BUFSIZE;
        tx_size = JBT_SESSION_L2CAP_RX_BUFSIZE;
    }

    rx_block_inx = jbt_malloc_block(rx_size);
#ifndef JBT_SUPPORT_ADM_MEM
    subsession_entry->ReadRingBuf.pStart = (kal_uint8*) jvm_malloc(rx_size);
#else
    subsession_entry->ReadRingBuf.pStart = (kal_uint8*) kal_adm_alloc(jbt_get_mem_pool_id(),rx_size);
#endif
    
    if (subsession_entry->ReadRingBuf.pStart == NULL)
    {
        /* Failed of jvm_malloc() */
        jbt_free_block(rx_block_inx);
        rc = JBT_SESSION_FAILED_ALLOCATE_RINGBUF;   /* Failed to allocate memory space */
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_ALLOCATE_READRINGBUF_FAILED, rx_size);
        return rc;
    }
    else
    {
        jbt_malloc_record(rx_block_inx, subsession_entry->ReadRingBuf.pStart, rx_size);
        /* Allocate memory space successfully, assign pEnd and init pRead and pWrite */
        subsession_entry->ReadRingBuf.pEnd = subsession_entry->ReadRingBuf.pStart + rx_size;
    #ifdef __USE_BT_RING_BUF_API__
        RING_BufFlush(&(subsession_entry->ReadRingBuf));
    #else 
        JBTRING_BufFlush(&(subsession_entry->ReadRingBuf));
    #endif 
    }

    tx_block_inx = jbt_malloc_block(tx_size);
#ifndef JBT_SUPPORT_ADM_MEM
    subsession_entry->WriteRingBuf.pStart = (kal_uint8*) jvm_malloc(tx_size);
#else
    subsession_entry->WriteRingBuf.pStart = (kal_uint8*) kal_adm_alloc(jbt_get_mem_pool_id(),tx_size);
#endif
    
    if (subsession_entry->WriteRingBuf.pStart == NULL)
    {
        /* Failed of jvm_malloc() */
        jbt_free_block(tx_block_inx);
        rc = JBT_SESSION_FAILED_ALLOCATE_RINGBUF;   /* Failed to allocate memory space */
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_ALLOCATE_WRITERINGBUF_FAILED, tx_size);
        return rc;
    }
    else
    {
        jbt_malloc_record(tx_block_inx, subsession_entry->WriteRingBuf.pStart, tx_size);
        /* Allocate memory space successfully, assign pEnd and init pRead and pWrite */
        subsession_entry->WriteRingBuf.pEnd = subsession_entry->WriteRingBuf.pStart + tx_size;
    #ifdef __USE_BT_RING_BUF_API__
        RING_BufFlush(&(subsession_entry->WriteRingBuf));
    #else 
        JBTRING_BufFlush(&(subsession_entry->WriteRingBuf));
    #endif 
    }
    return rc;

}


/*****************************************************************************
 * FUNCTION
 *  jbt_session_free_RWRingBuf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  subsession_entry        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 jbt_session_free_RWRingBuf(jbt_subsession *subsession_entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 rc = 0x00;    /* 0x00: means successful */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (subsession_entry->ReadRingBuf.pStart != NULL)
    {
        jbt_free_record(subsession_entry->ReadRingBuf.pStart);
#ifndef JBT_SUPPORT_ADM_MEM
        jvm_free(subsession_entry->ReadRingBuf.pStart);
#else
        kal_adm_free(jbt_get_mem_pool_id(),subsession_entry->ReadRingBuf.pStart);
#endif
        subsession_entry->ReadRingBuf.pStart = NULL;
    }
    if (subsession_entry->WriteRingBuf.pStart != NULL)
    {
        jbt_free_record(subsession_entry->WriteRingBuf.pStart);
#ifndef JBT_SUPPORT_ADM_MEM
        jvm_free(subsession_entry->WriteRingBuf.pStart);
#else
        kal_adm_free(jbt_get_mem_pool_id(),subsession_entry->WriteRingBuf.pStart);
#endif
        subsession_entry->WriteRingBuf.pStart = NULL;
    }
    return rc;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_reset_session_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  list_type               [IN]        
 *  existing_entry          [IN]        
 *  subsession_entry        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_reset_session_entry(kal_uint8 list_type, jbt_list *existing_entry, jbt_subsession *subsession_entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jbt_session_info *session_entry = (jbt_session_info*) existing_entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_JBT_REQ_CMD_FAILED_FREE_BUF_AND_RESET_ENTRY);
    jbt_session_free_RWRingBuf(subsession_entry);
    jbt_reset_subsession_entry(subsession_entry);

    /* Release channel buffer */
    if (session_entry->channel_buffer != NULL)
    {
        jbt_free_record(session_entry->channel_buffer);
#ifndef JBT_SUPPORT_ADM_MEM
        jvm_free(session_entry->channel_buffer);
#else
        kal_adm_free(jbt_get_mem_pool_id(),session_entry->channel_buffer);
#endif
        session_entry->channel_buffer = NULL;
    }

    /* Release ReadRingBuf and WriteRingBuf */
    jbt_free_one_existing_entry(list_type, existing_entry);
    session_entry->initiator = JBT_SESSION_INITIATOR_FALSE;
    session_entry->used = 0;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_session_free_RWRingBuf_with_inx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  session_type        [IN]        
 *  session_inx         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int8 jbt_session_free_RWRingBuf_with_inx(kal_uint8 session_type, kal_uint8 session_inx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jbt_list *existing_entry = NULL;
    jbt_session_info *session_entry = NULL;
    kal_uint8 rc = 0x00;
    jbt_subsession *subsession_entry = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (session_type == JBT_SESSION_TYPE_SPP)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_spp_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            session_inx,
                            JBT_LIST_TYPE_SPP_SESSION);
    }
    else if (session_type == JBT_SESSION_TYPE_L2CAP)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_l2cap_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            session_inx,
                            JBT_LIST_TYPE_L2CAP_SESSION);
    }

    if (existing_entry == NULL)
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_CAN_NOT_FIND_EXISTING_ENTRY, JBT_LIST_SEARCH_TYPE_BY_INX, session_inx);
        return JBT_SESSION_FIND_NO_ENTRY;
    }
    session_entry = (jbt_session_info*) existing_entry;

    /* Find the corresponding subsession_entry via trasnaction_id */
    subsession_entry = jbt_search_existing_subsession_entry(session_entry, JBT_LIST_SEARCH_TYPE_BY_INX, session_inx);
#if (JBT_MAX_SUBSESSION_NO > 1)
    if (subsession_entry == NULL)
    {
        ASSERT(0);
    }
#endif /* (JBT_MAX_SUBSESSION_NO > 1) */

    rc = jbt_session_free_RWRingBuf(subsession_entry);
    return rc;

}


/*****************************************************************************
 * FUNCTION
 *  jbt_session_PutBytes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  session_type        [IN]        
 *  session_inx         [IN]        
 *  subsession_id       [IN]        
 *  Buffaddr            [IN]        
 *  Length              [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int16 jbt_session_PutBytes(
            kal_uint8 session_type,
            kal_uint32 session_inx,
            kal_uint16 subsession_id,
            kal_uint8 *Buffaddr,
            kal_int16 Length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 writeLength = 0;
    jbt_list *existing_entry = NULL;
    jbt_session_info *session_entry = NULL;
    jbt_subsession *subsession_entry = NULL;
    U8 *pPrevWrite = NULL;
    kal_bool app_regards_buf_empty = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jbt_general_non_poweron_reject())
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_REJCT_DUE_TO_POWEROFF_ONGOING);
        return JBT_SESSION_NOT_POWERON;
    }

    /* Check this SPP connection is open */
    if (session_type == JBT_SESSION_TYPE_SPP){
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_spp_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            session_inx,
                            JBT_LIST_TYPE_SPP_SESSION);
    }
    else if (session_type == JBT_SESSION_TYPE_L2CAP)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_l2cap_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            session_inx,
                            JBT_LIST_TYPE_L2CAP_SESSION);
    }
    else
    {
        return JBT_SESSION_INVALID_SESSION_TYPE;
    }
    if (existing_entry == NULL)
    {
        kal_trace(TRACE_INFO, FUNC_JBT_CAN_NOT_FIND_EXISTING_ENTRY, JBT_LIST_SEARCH_TYPE_BY_INX, session_inx);
        /* ErrorCode= -1: Can not find correct session entry */
        return JBT_SESSION_FIND_NO_ENTRY;
    }
    session_entry = (jbt_session_info*) existing_entry;

    subsession_entry = jbt_search_existing_subsession_entry(session_entry, JBT_LIST_SEARCH_TYPE_BY_INX, subsession_id);
#if (JBT_MAX_SUBSESSION_NO > 1)
    if (subsession_entry == NULL)
    {
        ASSERT(0);
    }
#endif /* (JBT_MAX_SUBSESSION_NO > 1) */

    /* Check the sesssion state is in CONNECTED state */
    if (subsession_entry->subsession_state != JBT_SESSION_STATE_CONNECTED)
    {
        return JBT_SESSION_ERR_STATE;
    }

    /* Buffer is empty, sets app_regards_buf_empty to trigger to send data request to BT task:2007-1015 */
    if (subsession_entry->WriteRingBuf.pRead == subsession_entry->WriteRingBuf.pWrite)
    {
        app_regards_buf_empty = KAL_TRUE;
    }

    pPrevWrite = subsession_entry->WriteRingBuf.pWrite;

#ifdef __USE_BT_RING_BUF_API__
    writeLength = RING_WriteData(&(subsession_entry->WriteRingBuf), (char*)Buffaddr, Length);
#else 
    writeLength = JBTRING_WriteData(&(subsession_entry->WriteRingBuf), (char*)Buffaddr, Length);
#endif 

    if (writeLength < Length)
    {
        subsession_entry->notifyReadyToWrite = KAL_TRUE;
    }
    else
    {
        kal_int16 freespace_dataLen_in_TXBuf = jbt_session_BufFreeSpace(session_type, session_inx, subsession_id, JBT_SESSION_TX_BUF_TYPE);
        if (freespace_dataLen_in_TXBuf == 0)
        {
            subsession_entry->notifyReadyToWrite = KAL_TRUE;
        }
    }

    /*
     * Because is_tx_empty is TRUE, JBT can receive READY_TO_WRITE_IND 
     * Application can write data to buffer again
     * Because it is not possible to transmit data rely on receiving PKT_Handled event, it must send SEND_DATA_REQ to trigger transmissino action 
     */
    if (app_regards_buf_empty || (pPrevWrite == subsession_entry->WriteRingBuf.pRead) || subsession_entry->is_tx_empty)
    {
        subsession_entry->is_tx_empty = FALSE;
        /* For SPP and L2CAP session, using the same function to send data */
        jbt_session_sendData(session_inx, subsession_id);

    }
    return writeLength;

}


/*****************************************************************************
 * FUNCTION
 *  jbt_session_GetBytes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  session_type        [IN]        
 *  session_inx         [IN]        
 *  subsession_id       [IN]        
 *  Buffaddr            [IN]        
 *  Length              [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int16 jbt_session_GetBytes(
            kal_uint8 session_type,
            kal_uint32 session_inx,
            kal_uint16 subsession_id,
            kal_uint8 *Buffaddr,
            kal_int16 Length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 DataRead = 0;
    jbt_list *existing_entry = NULL;
    jbt_session_info *session_entry = NULL;
    jbt_subsession *subsession_entry = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jbt_general_non_poweron_reject())
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_REJCT_DUE_TO_POWEROFF_ONGOING);
        return JBT_SESSION_NOT_POWERON;
    }

    /* Check spp connection is open or not: Need to add codes to check: 2007-0902 */
    if (session_type == JBT_SESSION_TYPE_SPP)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_spp_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            session_inx,
                            JBT_LIST_TYPE_SPP_SESSION);
    }
    else if (session_type == JBT_SESSION_TYPE_L2CAP)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_l2cap_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            session_inx,
                            JBT_LIST_TYPE_L2CAP_SESSION);
    }
    else
    {
        return JBT_SESSION_INVALID_SESSION_TYPE;
    }

    if (existing_entry == NULL)
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_CAN_NOT_FIND_EXISTING_ENTRY, JBT_LIST_SEARCH_TYPE_BY_INX, session_inx);
        /* ErrorCode= -1: Can not find correct session entry */
        return JBT_SESSION_FIND_NO_ENTRY;
    }
    session_entry = (jbt_session_info*) existing_entry;

    subsession_entry = jbt_search_existing_subsession_entry(session_entry, JBT_LIST_SEARCH_TYPE_BY_INX, subsession_id);
#if (JBT_MAX_SUBSESSION_NO > 1)
    if (subsession_entry == NULL)
    {
        ASSERT(0);
    }
#endif /* (JBT_MAX_SUBSESSION_NO > 1) */

    /* Check the sesssion state is in CONNECTED state */
    if (subsession_entry->subsession_state != JBT_SESSION_STATE_CONNECTED)
    {
        return JBT_SESSION_ERR_STATE;
    }

    /* Note: Using session_inx to find its corresponding SPP entry index */
    /* Get data from ReadRingBuf */

#ifdef __USE_BT_RING_BUF_API__
    DataRead = RING_ReadData(&(subsession_entry->ReadRingBuf), (char*)Buffaddr, Length);
#else 
    DataRead = JBTRING_ReadData(&(subsession_entry->ReadRingBuf), (char*)Buffaddr, Length);
#endif 

    /*
     * Because it may context switch to BT task to put more incoming data into ReadRingBuf,
     * It will check the data length to determine if it is necessary to read 
     */

    /* Report(("In jbt_spp_read(): DataRead=%d,Length=%d",DataRead,Length)); */
    kal_trace(TRACE_INFO, FUNC_JBT_READ, DataRead, Length);

    if (DataRead < Length)
    {
        kal_int16 ReadMore;

        subsession_entry->readyToRead = KAL_TRUE;
    #ifdef __USE_BT_RING_BUF_API__
        ReadMore = RING_DataLen(&(subsession_entry->ReadRingBuf));
    #else 
        ReadMore = JBTRING_DataLen(&(subsession_entry->ReadRingBuf));
    #endif 

        /* Report(("In jbt_spp_read():case1 Set readyToRead to TRUE and ReadMore=%d",ReadMore)); */
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_READ_01, ReadMore);
        if (ReadMore > 0)
        {
            if ((DataRead + ReadMore) < Length)
            {

            #ifdef __USE_BT_RING_BUF_API__
                RING_ReadData(&(subsession_entry->ReadRingBuf), (char*)(Buffaddr + DataRead), ReadMore);
            #else 
                JBTRING_ReadData(&(subsession_entry->ReadRingBuf), (char*)(Buffaddr + DataRead), ReadMore);
            #endif 
                DataRead += ReadMore;
            }
            else
            {

                kal_int16 left_dataLen_in_RxBuf = 0;

            #ifdef __USE_BT_RING_BUF_API__
                RING_ReadData(&(subsession_entry->ReadRingBuf), (char*)(Buffaddr + DataRead), Length - DataRead);
            #else 
                JBTRING_ReadData(&(subsession_entry->ReadRingBuf), (char*)(Buffaddr + DataRead), Length - DataRead);
            #endif 
                DataRead = Length;
                subsession_entry->readyToRead = KAL_FALSE;
                /* Report(("In jbt_spp_read():case2 Set readyToRead to FALSE")); */
                kal_trace(TRACE_JBT_GROUP, FUNC_JBT_READ_02);

                /* Check the RXRingBuf's readable_len */
                left_dataLen_in_RxBuf = jbt_session_BufAvailableDataLen(session_type, session_inx, subsession_id, JBT_SESSION_RX_BUF_TYPE);
                if (left_dataLen_in_RxBuf == 0)
                {
                    subsession_entry->readyToRead = KAL_TRUE;
                }
            }
        }
    }
    else
    {
        /* Check the RXRingBuf's readable_len */
        kal_int16 left_dataLen_in_RxBuf = jbt_session_BufAvailableDataLen(session_type, session_inx, subsession_id, JBT_SESSION_RX_BUF_TYPE);
        if (left_dataLen_in_RxBuf == 0)
        {
            subsession_entry->readyToRead = KAL_TRUE;
        }
    }

    if (session_type == JBT_SESSION_TYPE_SPP)
    {
        /*
         * Because the data stored in ReadRingBuf is read from the upper application, it's time to update credit information
         * It will send MSG_ID_BT_JSR_SPP_GET_DATA_REQ to ask BT stack to check credit's information (compute credit value)
         */
        kal_uint8 devCredit = bt_jsr82_getCurrentCredit(session_inx);

        if (devCredit < JBT_SPP_RX_CREDIT / 2)
        {
            jbt_spp_getData(session_inx);
        }
    }
    else if (session_type == JBT_SESSION_TYPE_L2CAP)
    {
        /* No flow control in L2CAP, it is not like RFCOMM to update credit's information: 2007-1108 */
    }
    return DataRead;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_session_BufFreeSpace
 * DESCRIPTION
 *  
 * PARAMETERS
 *  session_type        [IN]        
 *  session_inx         [IN]        
 *  subsession_id       [IN]        
 *  buf_type            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int16 jbt_session_BufFreeSpace(
            kal_uint8 session_type,
            kal_uint32 session_inx,
            kal_uint8 subsession_id,
            kal_uint8 buf_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jbt_list *existing_entry = NULL;
    jbt_session_info *session_entry = NULL;
    jbt_subsession *subsession_entry = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check spp connection is open or not: Need to add codes to check: 2007-0902 */

    if (session_type == JBT_SESSION_TYPE_SPP)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_spp_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            session_inx,
                            JBT_LIST_TYPE_SPP_SESSION);
    }
    else if (session_type == JBT_SESSION_TYPE_L2CAP)
    {
        /* Search the existing entry list */
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_l2cap_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            session_inx,
                            JBT_LIST_TYPE_L2CAP_SESSION);
    }
    else
    {
        return JBT_SESSION_INVALID_SESSION_TYPE;
    }

    if (existing_entry == NULL)
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_CAN_NOT_FIND_EXISTING_ENTRY, JBT_LIST_SEARCH_TYPE_BY_INX, session_inx);
        /* ErrorCode= -1: Can not find correct session entry */
        return JBT_SESSION_FIND_NO_ENTRY;
    }
    session_entry = (jbt_session_info*) existing_entry;

    subsession_entry = jbt_search_existing_subsession_entry(session_entry, JBT_LIST_SEARCH_TYPE_BY_INX, subsession_id);
#if (JBT_MAX_SUBSESSION_NO > 1)
    if (subsession_entry == NULL)
    {
        ASSERT(0);
    }
#endif /* (JBT_MAX_SUBSESSION_NO > 1) */
    if (buf_type == JBT_SESSION_RX_BUF_TYPE)
    {
        /* RX Buffer */
    #ifdef __USE_BT_RING_BUF_API__
        return RING_FreeSpace(&subsession_entry->ReadRingBuf);
    #else 
        return JBTRING_FreeSpace(&subsession_entry->ReadRingBuf);
    #endif 
    }
    else if (buf_type == JBT_SESSION_TX_BUF_TYPE)
    {
        /* TX Buffer */
    #ifdef __USE_BT_RING_BUF_API__
        return RING_FreeSpace(&subsession_entry->WriteRingBuf);
    #else 
        return JBTRING_FreeSpace(&subsession_entry->WriteRingBuf);
    #endif 
    }
    else
    {
        return JBT_SESSION_INVALID_BUFF_TYPE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  jbt_session_BufAvailableDataLen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  session_type        [IN]        
 *  session_inx         [IN]        
 *  subsession_id       [IN]        
 *  buf_type            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int16 jbt_session_BufAvailableDataLen(
            kal_uint8 session_type,
            kal_uint32 session_inx,
            kal_uint8 subsession_id,
            kal_uint8 buf_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jbt_list *existing_entry = NULL;
    jbt_session_info *session_entry = NULL;
    jbt_subsession *subsession_entry = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check spp connection is open or not: Need to add codes to check: 2007-0902 */

    if (session_type == JBT_SESSION_TYPE_SPP)
    {
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_spp_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            session_inx,
                            JBT_LIST_TYPE_SPP_SESSION);
    }
    else if (session_type == JBT_SESSION_TYPE_L2CAP)
    {
        /* Search the existing entry list */
        existing_entry = jbt_search_an_existing_entry(
                            &jbt_l2cap_context.activeList,
                            JBT_LIST_SEARCH_TYPE_BY_INX,
                            session_inx,
                            JBT_LIST_TYPE_L2CAP_SESSION);
    }
    else
    {
        return JBT_SESSION_INVALID_SESSION_TYPE;
    }

    if (existing_entry == NULL)
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_CAN_NOT_FIND_EXISTING_ENTRY, JBT_LIST_SEARCH_TYPE_BY_INX, session_inx);
        /* ErrorCode= -1: Can not find correct session entry */
        return JBT_SESSION_FIND_NO_ENTRY;
    }
    session_entry = (jbt_session_info*) existing_entry;

    subsession_entry = jbt_search_existing_subsession_entry(session_entry, JBT_LIST_SEARCH_TYPE_BY_INX, subsession_id);
#if (JBT_MAX_SUBSESSION_NO > 1)
    if (subsession_entry == NULL)
    {
        ASSERT(0);
    }
#endif /* (JBT_MAX_SUBSESSION_NO > 1) */
    if (buf_type == JBT_SESSION_RX_BUF_TYPE)
    {
        /* RX Buffer */
    #ifdef __USE_BT_RING_BUF_API__
        return RING_DataLen(&subsession_entry->ReadRingBuf);
    #else 
        return JBTRING_DataLen(&subsession_entry->ReadRingBuf);
    #endif 
    }
    else if (buf_type == JBT_SESSION_TX_BUF_TYPE)
    {
        /* TX Buffer */
    #ifdef __USE_BT_RING_BUF_API__
        return RING_DataLen(&subsession_entry->WriteRingBuf);
    #else 
        return JBTRING_DataLen(&subsession_entry->WriteRingBuf);
    #endif 
    }
    else
    {
        return JBT_SESSION_INVALID_BUFF_TYPE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  jbt_session_BufSize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  session_type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int16 jbt_session_BufSize(kal_uint8 session_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (session_type == JBT_SESSION_TYPE_SPP)
    {
        return JBT_SESSION_SPP_RX_BUFSIZE;
    }
    else if (session_type == JBT_SESSION_TYPE_L2CAP)
    {
        return JBT_SESSION_L2CAP_RX_BUFSIZE;
    }
    else
    {
        return -1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jbt_session_sendData
 * DESCRIPTION
 *  This function is used for JBT to send SEND_DATA_REQ to BT stack
 *  This function is similar to function sppa_sendData()
 *  input_parm: session_index: It is used in btstack (For 3rd, it must use the id passed due to connection_cnf or conneciton_ind)
 * PARAMETERS
 *  session_inx     [IN]        
 *  l2cap_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_session_sendData(kal_uint32 session_inx, kal_uint16 l2cap_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_jsr82_tx_data_req_struct *ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_JBT_SPP_SEND_DATA);

    ptr = (bt_jsr82_tx_data_req_struct*) construct_local_para(sizeof(bt_jsr82_tx_data_req_struct), TD_UL);
    /*
     * For Read and Write procedure, only session_inx is meaningful
     * identify field can be removed !
     */
    ptr->index = session_inx;
    ptr->length = 0;
    ptr->data = NULL;
    ptr->l2cap_id = l2cap_id;
    jbt_send_msg(MSG_ID_BT_JSR82_TX_DATA_REQ, MOD_JASYN, MOD_BT, BT_APP_SAP, (local_para_struct*) ptr, NULL);

}

#endif /* __SUPPORT_JBT__ */ 

