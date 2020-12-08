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
 * jbt_gap.c
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
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _JBT_SPP_C
#define _JBT_SPP_C
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
#include "jbt_interface.h"
#include "jbt_internal.h"

JBT_SPP_CNTX jbt_spp_context;
kal_uint8 jbt_session_allocate_RWRingBuf(kal_uint8 session_type, jbt_subsession *subsession_entry);
kal_uint8 jbt_session_free_RWRingBuf(jbt_subsession *subsession_entry);


/*****************************************************************************
 * FUNCTION
 *  jbt_spp_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_spp_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;

#ifdef __JBT_SESSION_LINK_LIST__
    jbt_list *head = NULL, *tail = NULL;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_SPP_INIT);
    kal_mem_set((kal_uint8*) & jbt_spp_context, 0, sizeof(jbt_spp_context));

#ifdef __JBT_SESSION_LINK_LIST__
    /* Initialization freeList and activeList */
    jbt_spp_context.freeList.Blink = &jbt_spp_context.freeList;
    jbt_spp_context.freeList.Flink = &jbt_spp_context.freeList;

    jbt_spp_context.activeList.Flink = &jbt_spp_context.activeList;
    jbt_spp_context.activeList.Blink = &jbt_spp_context.activeList;

    head = &jbt_spp_context.freeList;
    tail = head;
#endif /* __JBT_SESSION_LINK_LIST__ */ 

    for (i = 0; i < JBT_MAX_SPP_NO; i++)
    {
    #ifdef __JBT_SESSION_LINK_LIST__
        jbt_list *entry = &jbt_spp_context.spp[i].spp_session.node;
    #endif 
        kal_uint8 j = 0;
        jbt_session_info *session = &jbt_spp_context.spp[i].spp_session;

        for (j = 0; j < JBT_MAX_SUBSESSION_NO; j++)
        {
            session->subsession[j].is_tx_empty = KAL_TRUE;
            session->subsession[j].readyToRead = KAL_TRUE;
            session->subsession[j].notifyReadyToWrite = KAL_FALSE;
        }

    #ifdef __JBT_SESSION_LINK_LIST__
        tail->Flink = entry;
        entry->Blink = tail;
        entry->Flink = head;
        head->Blink = entry;
        tail = entry;
    #endif /* __JBT_SESSION_LINK_LIST__ */ 

    }

}


/*****************************************************************************
 * FUNCTION
 *  jbt_spp_getData
 * DESCRIPTION
 *  This function is used for JBT to send GET_DATA_REQ to BT stack
 *  This function is similar to function sppa_getData()
 *  input_parm: session_index: It is used in btstack (For 3rd, it must use the id passed due to connection_cnf or conneciton_ind)
 * PARAMETERS
 *  session_inx     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_spp_getData(kal_uint32 session_inx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_jsr82_spp_get_data_req_struct *ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_JBT_SPP_GET_DATA);

    /* Check if BTStack is in PowerOn state */
    if (jbt_general_non_poweron_reject())
    {
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_REJCT_DUE_TO_POWEROFF_ONGOING);
        return;
    }
    ptr = (bt_jsr82_spp_get_data_req_struct*) construct_local_para(sizeof(bt_jsr82_spp_get_data_req_struct), TD_UL);
    ptr->index = (U8) session_inx;
    /*
     * Because this function is used to check credit internally, only session_inx for its corresponding SPP connection is enough 
     * identify field can be removed
     */
    ptr->identify = 0;
    ptr->l2cap_id = 0;
    jbt_send_msg(MSG_ID_BT_JSR82_SPP_GET_DATA_REQ, MOD_JASYN, MOD_BT, BT_APP_SAP, (local_para_struct*) ptr, NULL);

}

#endif /* __SUPPORT_JBT__ */ 

