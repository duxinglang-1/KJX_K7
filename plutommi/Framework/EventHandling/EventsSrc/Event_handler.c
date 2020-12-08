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
* Event_handler.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   This file is intends for protocol/keypad/interrupt event handler .
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
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
#include "mmi_frm_prot.h"
#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "BTMMIScrGprots.h"
#include "Device.h"
#include "Mmi_msg_struct.h"
#include "mmi_frm_events_gprot.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_frm_events.h"
#include "stack_msgs.h"
#include "MMI_features.h"
#include "mmi_fw_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "string.h"
#include "mmi_frm_at_util_prot.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "wgui_categories_list.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "stdio.h"
#include "fix_size_mem.h"
#include "mmi_cb_mgr_gprot.h"
#include "GlobalResDef.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_history.h"
#include "gdi_include.h"
#include "mmi_frm_scenario_gprot.h"
#include "Mmi_frm_mem_gprot.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define MMI_EVENT_INVALID  0
#define INTERRUPT_EVENT_GREOUP_SIZE     (4)
#define IS_INTERRUPT_EVENT_GROUP(x)    (((x)&MMI_INT_EVENT_GROUP_MASK) == MMI_INT_EVENT_GROUP_MASK)
#define MMI_FRM_PRE_INT_HDLR    1
#define MMI_FRM_POST_INT_HDLR   2
/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
/* Post event mechanism */
typedef struct _mmi_post_evt_node_struct
{
    U8 flag;
    void *evt_p;
    struct _mmi_post_evt_node_struct *next;
} mmi_post_evt_node_struct;

#ifdef __MMI_LCM_PRIMITIVE_FLUSH__

#define MAX_SCREEN_LOG_SIZE (10)
#define MMI_FRM_SCREEN_ID_IVALID   (0xFFFF)    /* reserved screen ID for invalid case */

typedef struct  __mmi_frm_scr_mgm_struct
{
    MMI_BOOL    dirty;
    MMI_BOOL    changeRecording;                        /* For the controlling to filter some dummy screen such as screen adaptor */
    MMI_BOOL    sseBackupOn;                            /* For SSE module to control timing */
    MMI_BOOL    apControlBltOnce;                       /* application has used blt control API to manually flush */
	MMI_BOOL	apEnterScreen;		
	

    mmi_frm_scr_blt_mode_enum   bltMode;
    U16         scrnLogData[MAX_SCREEN_LOG_SIZE];       /* circular */
    S32         scrnLogIdx;
    U32         currScrnLevel;
    U32         prevScrnLevel;
}mmi_frm_scr_mgm_struct;

#endif /* __MMI_LCM_PRIMITIVE_FLUSH__ */
/*****************************************************************************
 * Global Variable                                                             
 *****************************************************************************/
PseventInfo protocolEventHandler[MAX_PROTOCOL_EVENT];

/* static event table info, e.g. table pointer, num. of table items */
const mmi_frm_event_static_info_struct g_event_table_static_info[EVENT_TABLE_END] = {
    {protocolEventHandler, sizeof(protocolEventHandler)/sizeof(PseventInfo)},
};

/* runtime event table info, e.g. used and max. size */
mmi_frm_event_runtime_info_struct g_event_table_runtime_info[EVENT_TABLE_END];

/* Post event link list */
static mmi_post_evt_node_struct *post_evt_header = NULL;
static U8 post_evt_num = 0;
static U8 post_evt_peak_num = 0;

#ifdef __MMI_LCM_PRIMITIVE_FLUSH__
static mmi_frm_scr_mgm_struct   mmi_frm_scr_mgm_data;
MMI_BOOL  g_mmi_frm_screen_enable_anti_blink = MMI_TRUE;  
#endif /* __MMI_LCM_PRIMITIVE_FLUSH__ */

#ifdef __VENUS_UI_ENGINE__
extern void vfx_mmi_check_update(void);
extern void vfx_mmi_screen_entered(void);
#endif
extern MMI_BOOL gui_sse_get_is_dummy_screen(void);
/*****************************************************************************
 * Local Variable                                                             
 *****************************************************************************/


/*****************************************************************************
 * Local Function                                                              
 *****************************************************************************/
static S16 mmi_frm_search_event(
            mmi_frm_event_table_enum tableType,
            U16 eventID, 
            PsFuncPtr* pFuncPtr,
            S16 startIdx, 
            MMI_BOOL doSwap,
            S16 *pNextIdx, 
            S16 *pFirstEmptyIdx, 
            MMI_BOOL *pIsMultiInTable);

static void mmi_frm_set_protocol_event_handler_int(
                mmi_frm_event_table_enum tableType, 
                U16 eventID, 
                PsFuncPtr funcPtr, 
                MMI_BOOL isMultiHandler);

static void mmi_frm_clear_protocol_event_handler_int(
                mmi_frm_event_table_enum tableType, 
                U16 eventID, 
                PsFuncPtr funcPtr);

static void mmi_frm_exec_post_event_end(void);

extern void mmi_frm_dump_screen_id(void);
#ifdef __MMI_LCM_PRIMITIVE_FLUSH__
static void mmi_frm_screen_commit(void);
extern void gdi_lcd_set_high_priority_freeze(BOOL);
extern U32 mmi_frm_get_screen_level(U16 scrn_id);
extern void gui_screen_switch_effect_reset_flag(void);
extern void gui_sse_launch(void);
#endif
/*****************************************************************************
 * Extern data and function                                                             
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_execute_current_protocol_handler
 * DESCRIPTION
 *  This function is used for executes current protocol func handler.
 * PARAMETERS
 *  eventID         [IN]  Unique Protocol/System EventID       
 *  MsgStruct       [IN]  The pointer to the Local parameter.      
 *  mod_src         [IN]  Source module ID.     
 *  Message         [IN]  The pointer to the ILM.       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_execute_current_protocol_handler(U16 eventID, void *MsgStruct, int mod_src, void *Message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 idx = 0;
    MMI_BOOL isMultiHandler = MMI_FALSE, isExecuted;
    S16 nextIdxToSearch = 0;    /* used for multi-handler to enhance search efficiency */
    PsExtPeerIntFuncPtr currFuncPtr = NULL;
    mmi_frm_event_table_enum tableType = EVENT_TABLE_MASTER;
        
#if defined (MMI_EVENT_PROFILING)
    kal_uint32 start_tick, end_tick;
    static kal_uint32 accu_ticks = 0;
    static U32 accu_count = 0;
#endif /* defined (MMI_EVENT_PROFILING) */ 
    mmi_frm_pre_post_protocol_event_struct event;
    mmi_ret ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (MMI_EVENT_PROFILING)
    kal_get_time(&start_tick);
#endif 
        
    /* Search events in protocol event handler table */
    idx = mmi_frm_search_event(
            tableType,
            eventID, 
            (PsFuncPtr*) &currFuncPtr,
            0, 
            MMI_TRUE, 
            &nextIdxToSearch, 
            NULL, 
            &isMultiHandler);


#if defined (MMI_EVENT_PROFILING)
    if (idx > 0)
        accu_count += idx;
#endif /* defined (MMI_EVENT_PROFILING) */ 


    MMI_FRM_INIT_EVENT(&event, EVT_ID_PRE_PROTOCOL);
    event.message = Message;
    ret = MMI_FRM_CB_EMIT_EVENT(&event);

    if ((currFuncPtr)  
     && (ret != MMI_RET_STOP_PROTOCOL))
     {

        do {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_EXECURPTO_HDLR, tableType, eventID, currFuncPtr, isMultiHandler);

            isExecuted = (*currFuncPtr) (MsgStruct, mod_src, Message) ? MMI_TRUE: MMI_FALSE;

            currFuncPtr = NULL; /* reset handler to NULL */

            /* search and execute next handler if (1) multi-handler and (2) event is not executed */
            if (isMultiHandler && !isExecuted)
            {
                idx = mmi_frm_search_event(
                        tableType,
                        eventID, 
                        (PsFuncPtr*) &currFuncPtr,
                        nextIdxToSearch, 
                        MMI_TRUE, 
                        &nextIdxToSearch, 
                        NULL, 
                        NULL);

                if (idx < 0)
                {
                    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_FRM_INFO_EVENT_EXECURPTO_NO_HDLR, tableType, eventID, currFuncPtr);
                    
                }
            }
        } while (currFuncPtr);
    }
    else
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_EXECURPTO_NO_HDLR, tableType, eventID, currFuncPtr);
    }

#if defined (MMI_EVENT_PROFILING)
    kal_get_time(&end_tick);
    accu_ticks += (end_tick - start_tick);
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_EVENT_TRC_EVENT_PROFILING_COUNT, accu_count);
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_EVENT_TRC_EVENT_PROFILING_TICKS, accu_ticks);
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_EVENT_TRC_EVENT_PROFILING_MAX, g_event_table_runtime_info[tableType].max_events);
#endif /* defined (MMI_EVENT_PROFILING) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_protocol_event_handler
 * DESCRIPTION
 *  This function is used for register the protocol event handler. Whenever 
 *  an event is received from the protocol or system corresponding function 
 *  is executed.
 * PARAMETERS
 *  eventID         [IN] Unique Protocol/System EventID.       
 *  funcPtr         [IN] Function to be executed whenever a event is received from the protocol or system
 *  isMultiHandler  [IN] is multi-handler or not. for multi-handler, it shall return MMI_TRUE when event is handled (taken) by it.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_set_protocol_event_handler(U16 eventID, PsIntFuncPtr funcPtr, MMI_BOOL isMultiHandler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_protocol_event_handler_int(EVENT_TABLE_MASTER, eventID, (PsFuncPtr)funcPtr, isMultiHandler);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_protocol_event_handler
 * DESCRIPTION
 *  This is used to clear protocol event handler
 * PARAMETERS
 *  eventID     [IN] event ID to clear
 *  funcPtr     [IN] handler of event ID to clear for multi-handler. can just assign NULL for single-handler event.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_clear_protocol_event_handler(U16 eventID, PsIntFuncPtr funcPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_clear_protocol_event_handler_int(EVENT_TABLE_MASTER, eventID, (PsFuncPtr)funcPtr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_protocol_event_handler
 * DESCRIPTION
 *  This is used to get protocal event handler(only support MSG_ID_MMI_EQ_KEYPAD_DETECT_IND)
 * PARAMETERS
 *  eventID     :[IN] event ID
 *  funcPtr     :[IN] protocol event handler of eventID
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_get_protocol_event_handler(U16 eventID, PsFuncPtr* pFuncPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PsFuncPtr funcPtr = NULL;
    S16 idx = -1, firstNotUsed = -1;
    MMI_BOOL isMultiInTable;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(eventID == MSG_ID_MMI_EQ_KEYPAD_DETECT_IND);

    idx = mmi_frm_search_event(
            EVENT_TABLE_MASTER,
            eventID, 
            &funcPtr,
            0, 
            MMI_FALSE, 
            NULL, 
            &firstNotUsed, 
            &isMultiInTable);
    if (idx >= 0)
    {
       *pFuncPtr = funcPtr;
    }
    else
    {
       *pFuncPtr = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_search_event
 * DESCRIPTION
 *  search event in eventTable.
 * PARAMETERS
 *  tableType       [IN]  type of event table to search
 *  eventID         [IN]  event ID to search
 *  pFuncPtr        [IN/OUT] [IN] handler to search, or NULL to search event ID only [OUT] handler found for given event ID
 *  startIdx        [IN]  start index
 *  doSwap          [IN]  swap found event or not (now only swap when executing event)
 *  pNextIdx        [OUT] next index to search
 *  pFirstEmptyIdx  [OUT] index of 1st empty
 *  pIsMultiInTable [OUT] is multi-handler found in event table
 * RETURNS
 *  index found or -1 (not found)
 *****************************************************************************/
static S16 mmi_frm_search_event(
            mmi_frm_event_table_enum tableType,
            U16 eventID, 
            PsFuncPtr* pFuncPtr,
            S16 startIdx, 
            MMI_BOOL doSwap,
            S16 *pNextIdx, 
            S16 *pFirstEmptyIdx, 
            MMI_BOOL *pIsMultiInTable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 idx = -1;
    S16 maxEvents = g_event_table_runtime_info[tableType].max_events;
    PseventInfo *eventTable = g_event_table_static_info[tableType].table;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pFirstEmptyIdx)
        *pFirstEmptyIdx = -1;

    /* Search events in protocol event handler table */
    for (idx = startIdx; idx < maxEvents; idx++)
    {
        /* eventID match */
        if (eventTable[idx].eventID == eventID)
        {
            /* if handler type is diff., return type in table */
            if ((pIsMultiInTable) && (*pIsMultiInTable != (MMI_BOOL)eventTable[idx].flagMulti))
                *pIsMultiInTable = (MMI_BOOL)eventTable[idx].flagMulti;

            /* search for handler or not */
            if (pFuncPtr)
    {
                /* match eventID only, no handler to search */
                if (*pFuncPtr == NULL)
                {
                    *pFuncPtr = eventTable[idx].entryFuncPtr;
                }
                /* has handler to search */
                else
                {
                    /* handler not found */
                    if (*pFuncPtr != eventTable[idx].entryFuncPtr)
        {
                        continue;   /* keep searching */
                    }
                    /* else: handler found */
                }
            }

            if (pNextIdx) /* next index to search */
                *pNextIdx = idx+1;

            if (doSwap && (idx > 0))
            {   /* improve the search efficiently */
                PseventInfo tmpEvent = eventTable[idx];
                eventTable[idx]     = eventTable[idx-1];
                eventTable[idx-1]   = tmpEvent;
                idx--;
            }
         
            break;
        }
        
        /* find 1st empty at the same time */
        if (pFirstEmptyIdx && (*pFirstEmptyIdx == -1) && (eventTable[idx].eventID == MMI_EVENT_INVALID))
        {
            *pFirstEmptyIdx = idx;
        }

    }

    if (idx < maxEvents)
        return idx;
    else
        return -1;  /* not found */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_protocol_event_handler_int
 * DESCRIPTION
 *  This function is used for register the protocol event handler. Whenever 
 *  an event is received from the protocol or system corresponding function 
 *  is executed.
 * PARAMETERS
 *  tableType       [IN] event table type
 *  eventID         [IN] Unique Protocol/System EventID.       
 *  funcPtr         [IN] Function to be executed whenever a event is received from the protocol or system
 *  isMultiHandler  [IN] is multi-handler or not. for multi-handler, it shall return MMI_TRUE when event is handled (taken) by it.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_set_protocol_event_handler_int(mmi_frm_event_table_enum tableType, U16 eventID, PsFuncPtr funcPtr, MMI_BOOL isMultiHandler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U16 maxUsedInHistory[EVENT_TABLE_END] = {0};
    S16 idx = -1, firstNotUsed = -1;
    MMI_BOOL isMultiInTable = isMultiHandler;  /* initial to same as input */
    PsFuncPtr funcToSearch = NULL;
    PseventInfo *eventTable = g_event_table_static_info[tableType].table;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(eventID != 0);
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_EVENT_SETPTO_HDLR,
              eventID, funcPtr, isMultiHandler);
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_EVENT_SETPTO_HDLR_DETAIL,
              tableType, g_event_table_runtime_info[tableType].used_events, g_event_table_runtime_info[tableType].max_events);

    /* serach */
    if (isMultiHandler)
    {
        funcToSearch = funcPtr;
        MMI_ASSERT(funcPtr != NULL);    /* funcPtr=NULL is only for single-handler */
   }

    idx = mmi_frm_search_event(
            tableType,
            eventID, 
            &funcToSearch,
            0, 
            MMI_FALSE, 
            NULL, 
            &firstNotUsed, 
            &isMultiInTable);

    MMI_ASSERT(isMultiHandler == isMultiInTable);  /* handler type mismatch with existing in table */

    /* found */
    if (idx >= 0)
    {
        /* single-handler */
        if (!isMultiHandler)
        {
            if (funcPtr != NULL)
            {
                /* just need to update */
                eventTable[idx].entryFuncPtr = funcPtr;
            }
            else
            {
                /* funcPtr=NULL, means clear => reset it */
                memset(&eventTable[idx], 0, sizeof(PseventInfo));
                g_event_table_runtime_info[tableType].used_events--;
            }
        }
        /* multi-handler: eventID/funcPtr already exists, do nothing */
    }
    /* not found */
    else
    {
        if (funcPtr != NULL)
        {
            /* newly set */
            if (firstNotUsed != -1)
            {
                idx = firstNotUsed;
            }
            else
            {
                /* need to enlarge current searching list */
                idx = g_event_table_runtime_info[tableType].max_events;
                g_event_table_runtime_info[tableType].max_events++;
                MMI_ASSERT(g_event_table_runtime_info[tableType].max_events < g_event_table_static_info[tableType].num_of_events);
            }
            g_event_table_runtime_info[tableType].used_events++;
            eventTable[idx].eventID       = eventID;
            eventTable[idx].entryFuncPtr  = funcPtr;
            eventTable[idx].flagMulti     = (U8)isMultiHandler;
        }
        else
        {
            /* funcPtr=NULL, means clear. but not found => do nothing */
        }
    }

    /* recycle not-used items in the tail of list. It is for searching efficency */
    for (idx = (g_event_table_runtime_info[tableType].max_events - 1); idx >= 0; idx--)
    {
        if (eventTable[idx].eventID != MMI_EVENT_INVALID)
        {
            break;
        }
    }
    g_event_table_runtime_info[tableType].max_events= idx + 1;

    /* record the max value for array size analysis */
    if (maxUsedInHistory[tableType] < g_event_table_runtime_info[tableType].max_events)
    {
        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_EVENT_TRC_SET_PROTOCOL_EVENT_HDLR_MAX_1, maxUsedInHistory[tableType]);
        maxUsedInHistory[tableType] = g_event_table_runtime_info[tableType].max_events;
        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_EVENT_TRC_SET_PROTOCOL_EVENT_HDLR_MAX_2, maxUsedInHistory[tableType]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_protocol_event_handler_int
 * DESCRIPTION
 *  This is used to clear protocol event handler
 * PARAMETERS
 *  tableType   [IN] event table type
 *  eventID     [IN] event ID to clear
 *  funcPtr     [IN] handler of event ID to clear for multi-handler. can just assign NULL for single-handler event.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_clear_protocol_event_handler_int(mmi_frm_event_table_enum tableType, U16 eventID, PsFuncPtr funcPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 idx = -1;
    MMI_BOOL isMultiInTable = MMI_FALSE;
    PsFuncPtr funcToClear = funcPtr;
    PseventInfo *eventTable = g_event_table_static_info[tableType].table;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx = mmi_frm_search_event(
            tableType,
            eventID, 
            &funcToClear,
            0, 
            MMI_FALSE, 
            NULL, 
            NULL, 
            &isMultiInTable);

    if (idx >= 0)  /* found */
    {
        if (isMultiInTable)
        {
            MMI_ASSERT(funcPtr);    /* can't use NULL for multi-handler */
        }

        /* shows actual (eventID, funcPtr) to clear */
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_EVENT_CLRPTO_HDLR, tableType, eventID, funcToClear);

        memset(&eventTable[idx], 0, sizeof(PseventInfo));
        g_event_table_runtime_info[tableType].used_events--;

        /* recycle not-used items in the tail of list. It is for searching efficency */
        for (idx = (g_event_table_runtime_info[tableType].max_events - 1); idx >= 0; idx--)
        {
            if (eventTable[idx].eventID != MMI_EVENT_INVALID)
            {
                break;
            }
        }
        g_event_table_runtime_info[tableType].max_events= idx + 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_all_protocol_event_handler
 * DESCRIPTION
 *  This is used to clear all the protocol event handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_clear_all_protocol_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_EVENT_CLRALLPTO_HDLR, EVENT_TABLE_MASTER);

    memset(protocolEventHandler, 0, sizeof(PseventInfo)*g_event_table_runtime_info[EVENT_TABLE_MASTER].max_events); 
    memset(&g_event_table_runtime_info[EVENT_TABLE_MASTER], 0, sizeof(mmi_frm_event_runtime_info_struct));
    
    mmi_frm_set_protocol_event_handler(MSG_ID_TST_INJECT_STRING, (PsIntFuncPtr)mmi_proc_inject_string, MMI_FALSE);
}


void mmi_frm_init_event(mmi_event_struct *evt, MMI_ID evt_id, U16 size)
{
    memset(evt, 0, size);
    evt->evt_id = evt_id;
    evt->size = size;
}


void mmi_frm_init_group_event(mmi_group_event_struct *evt, MMI_ID evt_id, MMI_ID sender_id, U16 size)
{
    memset(evt, 0, size);
    evt->evt_id = evt_id;
    evt->sender_id = sender_id;
    evt->size = size;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_send_event
 * DESCRIPTION
 *  Send directly event to designated proc with user data.
 * PARAMETERS
 *  evt              [IN]
 *  proc             [IN]
 *  user_data        [IN]
 * RETURN VALUES
 *  MMI_RET_OK: Emit the event to the specific proc function without return value from the receiver.
 *  Others: Emit the event to the specific proc function and carry the return value from the receiver.
 *****************************************************************************/
mmi_ret mmi_frm_send_event(mmi_event_struct *evt, mmi_proc_func proc, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt->user_data = user_data;

    return proc(evt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_post_event
 * DESCRIPTION
 *  Send post event to designated proc with user data, it will be invoked after current
 *  function flow and before next input event like key, pen, timer, primitive.
 * PARAMETERS
 *  evt              [IN]   event structure pointer;
 *  proc             [IN]   process handler
 *  user_data        [IN]   user data pointer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_post_event(mmi_event_struct *evt, mmi_proc_func proc, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_post_event_proc_struct *post_evt_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt != NULL && proc != NULL);
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_CB_POST_EVT, evt, evt->evt_id, proc, user_data);
    /* Copy event struct and push into post evt queue */
    post_evt_p = mmi_frm_malloc(sizeof(mmi_post_event_proc_struct));
    post_evt_p->evt_p = mmi_frm_malloc(evt->size);
    memcpy(post_evt_p->evt_p, evt, evt->size);
    post_evt_p->proc = proc;
    post_evt_p->evt_p->user_data = user_data;

    enqueue_post_evt((void *)post_evt_p, POST_EVT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_post_event_ex
 * DESCRIPTION
 *  Send post event to designated proc with user data, it will be invoked after current
 *  function flow and before next input event like key, pen, timer, primitive.
 *  And result callback will be invoked with EVT_ID_POST_CB_RST and result_cb_user_data to
 *  notify sender the result.
 * PARAMETERS
 *  evt                 [IN]   event structure pointer;
 *  proc                [IN]   designated process handler;
 *  user_data           [IN]   designated user data pointer;
 *  result_cb           [IN]   result process handler;
 *  result_cb_user_data [IN]   result user data;
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_post_event_ex(mmi_event_struct *evt, mmi_proc_func proc, void *user_data, mmi_post_event_result_proc_func result_cb, void *result_cb_user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_post_event_proc_ex_struct *post_evt_ex_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt != NULL && proc != NULL);
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_CB_POST_EVT_EX, evt, evt->evt_id, proc, user_data, result_cb, result_cb_user_data);
    /* Copy event struct and push into post evt queue */
    post_evt_ex_p = mmi_frm_malloc(sizeof(mmi_post_event_proc_ex_struct));
    post_evt_ex_p->evt_p = mmi_frm_malloc(evt->size);
    memcpy(post_evt_ex_p->evt_p, evt, evt->size);
    post_evt_ex_p->proc = proc;
    post_evt_ex_p->evt_p->user_data = user_data;
    post_evt_ex_p->result_cb = result_cb;
    post_evt_ex_p->result_cb_user_data = result_cb_user_data;

    enqueue_post_evt((void *)post_evt_ex_p, POST_EVT_EX);
}


/**************************************************************************************
 * Post event mechanism
 **************************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_is_event_posted
 * DESCRIPTION
 *  Check if event is in post event queue.
 * PARAMETERS
 *  evt_p :      [IN]  event structure pointer.
 * RETURNS
 *  Return MMI_TRUE if the designated post event is in queue by checking event id & user data pointer,
 *  otherwise return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL mmi_frm_is_event_posted(mmi_event_struct *check_evt_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_post_evt_node_struct *position;
    mmi_event_struct *post_evt_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!post_evt_header || !check_evt_p)
    {
        return MMI_FALSE;
    }
    
    for (position = post_evt_header->next; position != NULL; position = position->next)
    {/* position should point to current cell */
        post_evt_p = (mmi_event_struct *)position->evt_p;
        if (post_evt_p->evt_id == check_evt_p->evt_id && post_evt_p->user_data == check_evt_p->user_data)
        {
            return MMI_TRUE;
        }        
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_post_evt_num
 * DESCRIPTION
 *  Get event number of post queue.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return event number.
 *****************************************************************************/
U32 mmi_frm_get_post_evt_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_post_evt_node_struct *position;
    U32 num = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!post_evt_header)
    {
        return 0;
    }
    for (position = post_evt_header->next; position != NULL; position = position->next)
    {
        num++;
    }
    return num;
}

U32 mmi_frm_get_post_num_by_proc(mmi_proc_func proc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_post_evt_node_struct *position;
    U32 num = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!post_evt_header)
    {
        return 0;
    }
    for (position = post_evt_header->next; position != NULL; position = position->next)
    {
		if (position->flag == POST_EVT)
		{
			mmi_post_event_proc_struct *post_evt_p = (mmi_post_event_proc_struct *)position->evt_p;
			if (post_evt_p->proc == proc)
			{
				num++;
			}
		}
		else if (position->flag == POST_EVT_EX)
		{
			mmi_post_event_proc_ex_struct *post_evt_p = (mmi_post_event_proc_ex_struct *)position->evt_p;
			if (post_evt_p->proc == proc)
			{
				num++;
			}
		}
    }
    return num;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_is_post_evt_queue_empty
 * DESCRIPTION
 *  Check if post event queue is empty.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return MMI_TRUE if there is some post event in queue, 
 *  otherwise return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL mmi_frm_is_post_evt_queue_empty(void)
{
    return (post_evt_header == NULL) ? MMI_TRUE : MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  enqueue_post_evt
 * DESCRIPTION
 *  Enqueue event into post event queue.
 * PARAMETERS
 *  evt_p             [IN]  event structure pointer;
 *  evt_flag          [IN]  post event type;
 * RETURNS
 *  Return event number.
 *****************************************************************************/
void enqueue_post_evt(void *evt_p, U8 evt_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_post_evt_node_struct *position, *tmp_cell;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(NULL != evt_p);
    if (!post_evt_header)
    {
        post_evt_header = mmi_frm_malloc(sizeof(mmi_post_evt_node_struct));
        memset(post_evt_header, 0, sizeof(mmi_post_evt_node_struct));
    }
    for (position = post_evt_header; position->next != NULL; position = position->next)
    /* position should point to previous cell */
        ;
    tmp_cell = mmi_frm_malloc(sizeof(mmi_post_evt_node_struct));
    tmp_cell->flag = evt_flag;
    tmp_cell->evt_p = evt_p;
    tmp_cell->next = position->next;    /* NULL */
    position->next = tmp_cell;
    post_evt_num++;
    if (post_evt_peak_num < post_evt_num)
    {
        post_evt_peak_num = post_evt_num;
    }
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_CB_ENQ_POST_EVT, evt_p, evt_flag, post_evt_num);
}


/*****************************************************************************
 * FUNCTION
 *  dequeue_post_evt
 * DESCRIPTION
 *  Dequeue post event with designated event type.
 * PARAMETERS
 *  evt_flag             [IN]  post event type;
 * RETURNS
 *  void
 *****************************************************************************/
void *dequeue_post_evt(U8 *evt_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_post_evt_node_struct *position;
    void *evt_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!post_evt_header)
    {
        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_CB_DEQ_POST_EVT_NULL);
        return NULL;
}
    position = post_evt_header->next;
    if (!position)
    {
        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_CB_DEQ_POST_EVT_EMPTY);
        return NULL;
    }
    post_evt_header->next = position->next;
    evt_p = position->evt_p;
    *evt_flag = position->flag;
    mmi_frm_free(position);
    MMI_ASSERT(NULL != evt_p);

    if (!post_evt_header->next)
    {
        mmi_frm_free(post_evt_header);
		post_evt_header = NULL;
    }
    post_evt_num--;
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_CB_DEQ_POST_EVT, evt_p, ((mmi_event_struct *)evt_p)->evt_id, *evt_flag, post_evt_num);

    return evt_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_invoke_post_event
 * DESCRIPTION
 *  Emit post events, the callback of this events will be invoked after current 
 *  function flow.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return MMI_RET_ERR_NO_POST_EVENT if there is no post event,
 *  Return MMI_RET_ERR_UNKNOWN_EVT_FLAG if can't find event flag,
 *  otherwise return result of callback function;
 *****************************************************************************/
S32 mmi_frm_invoke_post_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *evt_p;
    U8 evt_flag;
    S32 result = MMI_RET_ERR;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __VENUS_UI_ENGINE__
    vfx_mmi_check_update();
#endif

    if (post_evt_num == 0)
    {
        //MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_CB_INVOKE_POST_EVT_NULL);
        result = MMI_RET_ERR_NO_POST_EVENT;
    }
    else
    {
        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_CB_INVOKE_POST_EVT_BEGIN, post_evt_num);
    }

    
    do
    {
        while (NULL != (evt_p = dequeue_post_evt(&evt_flag)))
        {
            MMI_ASSERT(NULL != evt_p);

            if (evt_flag == POST_CB_EVT)
            {
            result = MMI_FRM_CB_EMIT_EVENT(evt_p);
                mmi_frm_free(evt_p);
            }
            else if (evt_flag == POST_CB_EVT_EX)
            {
                mmi_post_evt_ex_struct *evt_ex_p = (mmi_post_evt_ex_struct *)evt_p;
                mmi_post_result_event_struct rst_evt;
                S32 rst;

                /* Send posted event */
            rst = MMI_FRM_CB_EMIT_EVENT(evt_ex_p->evt_p);

                /* Feedback to caller by result callback */
                rst_evt.evt_id = EVT_ID_POST_CB_RST;
                rst_evt.user_data = evt_ex_p->result_cb_user_data;
                rst_evt.result = rst;
                rst_evt.evt_p = evt_ex_p->evt_p;
                result = evt_ex_p->result_cb(&rst_evt);
            
                mmi_frm_free(evt_ex_p->evt_p);
                mmi_frm_free(evt_ex_p);
            }
            else if (evt_flag == POST_EVT)
            {
                mmi_post_event_proc_struct *post_evt_p = (mmi_post_event_proc_struct *)evt_p;

                result = post_evt_p->proc(post_evt_p->evt_p);
            
                mmi_frm_free(post_evt_p->evt_p);
                mmi_frm_free(post_evt_p);
            }
            else if (evt_flag == POST_EVT_EX)
            {
                mmi_post_event_proc_ex_struct *post_evt_ex_p = (mmi_post_event_proc_ex_struct *)evt_p;
                mmi_post_result_event_struct rst_evt;
                S32 rst;

                /* Send posted event to designated proc */
                rst = post_evt_ex_p->proc(post_evt_ex_p->evt_p);
            
                /* Feedback to caller by result callback */
                rst_evt.evt_id = EVT_ID_POST_CB_RST;
                rst_evt.user_data = post_evt_ex_p->result_cb_user_data;
                rst_evt.result = rst;
                rst_evt.evt_p = post_evt_ex_p->evt_p;
                result = post_evt_ex_p->result_cb(&rst_evt);

                mmi_frm_free(post_evt_ex_p->evt_p);
                mmi_frm_free(post_evt_ex_p);
            }
            else
            {
                MMI_ASSERT(0);
                result = MMI_RET_ERR_UNKNOWN_EVT_FLAG;
            }

        #ifdef __VENUS_UI_ENGINE__
            vfx_mmi_check_update();
        #endif
        }
    }while (post_evt_num);
    
    MMI_ASSERT(post_evt_num == 0);
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_CB_INVOKE_POST_EVT_END);

    /* After handling the post events, we check if need to dump the screen history. */
    mmi_frm_exec_post_event_end();
#ifdef MMI_AFM_DEBUG	
    mmi_frm_fix_mem_check_intigrity();
#endif
#ifdef __MMI_MEMORY_MONITOR__
    mmi_mem_mon_print_info();
#endif
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_evt_id
 * DESCRIPTION
 *  Get event id from event structure.
 * PARAMETERS
 *  evt :      [IN]  post event structure pointer.
 * RETURNS
 *  Return event id;
 *****************************************************************************/
U16 mmi_frm_get_evt_id(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return evt->evt_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_evt_user_data
 * DESCRIPTION
 *  Get user data from event structure.
 * PARAMETERS
 *  evt :      [IN]  post event structure pointer.
 * RETURNS
 *  Return user data;
 *****************************************************************************/
void *mmi_frm_get_evt_user_data(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return evt->user_data;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_post_event_number
 * DESCRIPTION
 *  Get user data from event structure.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return post event number;
 *****************************************************************************/
U8 mmi_frm_get_post_event_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return post_evt_num;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_post_event_peak_num
 * DESCRIPTION
 *  This function is used to get post event peak number
 * PARAMETERS
 *  void
 * RETURNS
 *  Return post event peak number;
 *****************************************************************************/
U8 mmi_frm_get_post_event_peak_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return post_evt_peak_num;
} 

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_exec_msg_end
 * DESCRIPTION
 *  execute message end process
 *  
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_exec_post_event_end(void)
{
     if (mmi_frm_event_get_dump_history_flag())
    {
        HistoryDump();
        mmi_frm_event_set_dump_history_flag(MMI_FALSE);

        /* if need to dump the screen id. */
        mmi_frm_dump_screen_id();
    }
    mmi_frm_close_active_empty_group();

#ifdef __MMI_LCM_PRIMITIVE_FLUSH__
     mmi_frm_screen_commit();
#endif
}


#ifdef __MMI_LCM_PRIMITIVE_FLUSH__
/*****************************************************************************
 Anti-blink mechanism
 *****************************************************************************/
void mmi_frm_screen_set_sse_backup(MMI_BOOL isOn)
{
    mmi_frm_scr_mgm_data.sseBackupOn = isOn;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_scr_mgm_init
 * DESCRIPTION
 *  init screen mgm data structure for anti blinking and SSE
 *  called by the initialize process of mmi task
 * PARAMETERS
 *  None   
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_scr_mgm_init()
{
    U32 i;
    mmi_frm_scr_mgm_data.dirty = MMI_FALSE;
    mmi_frm_scr_mgm_data.apControlBltOnce = MMI_FALSE;
    mmi_frm_scr_mgm_data.apEnterScreen = MMI_FALSE;
    mmi_frm_screen_set_sse_backup(MMI_TRUE);
    mmi_frm_scr_mgm_data.bltMode = MMI_FRM_SCR_BLT_DEFAULT;
    for (i = 0; i < MAX_SCREEN_LOG_SIZE; i++)
    {
        mmi_frm_scr_mgm_data.scrnLogData[i] = MMI_FRM_SCREEN_ID_IVALID;
    }
    mmi_frm_scr_mgm_data.scrnLogIdx = 0;
    mmi_frm_scr_mgm_data.changeRecording = MMI_TRUE;
    mmi_frm_scr_mgm_data.prevScrnLevel = 0;
    mmi_frm_scr_mgm_data.currScrnLevel = 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_scr_mgm_deinit
 * DESCRIPTION
 *  init screen mgm data structure for anti blinking and SSE
 *  called by the initialize process of mmi task
 * PARAMETERS
 *  None   
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_scr_mgm_deinit()
{
    U32 i;
    mmi_frm_scr_mgm_data.dirty = MMI_FALSE;
    mmi_frm_scr_mgm_data.apControlBltOnce = MMI_FALSE;
    mmi_frm_screen_set_sse_backup(MMI_FALSE);
    mmi_frm_scr_mgm_data.bltMode = MMI_FRM_SCR_BLT_DEFAULT;
    for (i = 0; i < MAX_SCREEN_LOG_SIZE; i++)
    {
        mmi_frm_scr_mgm_data.scrnLogData[i] = MMI_FRM_SCREEN_ID_IVALID;
    }
    mmi_frm_scr_mgm_data.scrnLogIdx = 0;
    mmi_frm_scr_mgm_data.changeRecording = MMI_FALSE;
    mmi_frm_scr_mgm_data.prevScrnLevel = 0;
    mmi_frm_scr_mgm_data.currScrnLevel = 0;
}

/*****************************************************************************
 * FUNCTION
 *  lock_screen
 * DESCRIPTION
 *  internal use function for lock lcd blit
 *  
 * PARAMETERS
 *  None   
 * RETURNS
 *  void
 *****************************************************************************/
static void lock_screen(void)
{
    if (g_mmi_frm_screen_enable_anti_blink)
    {
        gdi_lcd_set_high_priority_freeze(MMI_TRUE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  unlock_screen
 * DESCRIPTION
 *  internal function for unlock lcd blit
 *  
 * PARAMETERS
 *  None   
 * RETURNS
 *  void
 *****************************************************************************/
static void unlock_screen(void)
{
    gdi_lcd_set_high_priority_freeze(MMI_FALSE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_refrsh_lcm
 * DESCRIPTION
 *  internal function for blit lcm
 *  
 * PARAMETERS
 *  None   
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_refrsh_lcm()
{
    /* Flush content to LCM */
    gdi_lcd_set_high_priority_freeze(FALSE);
#if defined(__MMI_SCREEN_SWITCH_EFFECT__)
    if (!mmi_frm_scr_mgm_data.apControlBltOnce)
    {
        gui_sse_launch();
    }
    else
    {
        gui_screen_switch_effect_reset_flag();
        gdi_lcd_repaint_all();
    }
#else /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
    gdi_lcd_repaint_all();
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */

#if defined(__MMI_VUI_ENGINE__)
    vfx_mmi_screen_entered();
#endif /* defined(__MMI_VUI_ENGINE__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_curr_scr_blt_mode
 * DESCRIPTION
 *  Interface for application to set blit mode of current screen
 *   
 *  - screen level operation
 *  - only affect current screen
 *  - the anti-blink mechanism will be disabled at the screen
 *  - the flush mode will be reset after exit a screen
 *  
 * PARAMETERS
 *     MMI_FRM_SCR_BLT_IMMEDIATE: gdi_lcd_blt will update screen immediately
 *          
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_set_curr_scr_blt_mode(mmi_frm_scr_blt_mode_enum mode)
{
    mmi_frm_scr_mgm_data.bltMode = mode;

    switch(mode)
    {
    case MMI_FRM_SCR_BLT_PRIMITIVE:
        lock_screen();
        break;
    case MMI_FRM_SCR_BLT_IMMEDIATE:
        unlock_screen();
        /* will update screen, reset dirty flag to flase */
        mmi_frm_scr_mgm_data.dirty = MMI_FALSE;
        mmi_frm_scr_mgm_data.apControlBltOnce = MMI_TRUE;
        break;
    }    
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_ui_force_update_now
 * DESCRIPTION
 *  Get screen ID of the screen that is commited previously.
 *  This funciton is prepare for SSE specially, applicaion should not directly use it.
 *  
 * PARAMETERS
 *  None   
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_ui_force_update_now(void)
{
    switch (mmi_frm_scr_mgm_data.bltMode)
    {
    case MMI_FRM_SCR_BLT_PRIMITIVE:
        unlock_screen();
        gdi_lcd_repaint_all();
        /* 
            Assumption: once a screen invoke mmi_frm_ui_force_update_now()
            the screen will not be locked untill we enter next screen()
        */
        break;
    default:  
        gdi_lcd_repaint_all();
        break;
    }    
    /* have updated screen, reset dirty flag to flase */
    mmi_frm_scr_mgm_data.dirty = MMI_FALSE;
    mmi_frm_scr_mgm_data.apControlBltOnce = MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_screen_get_committed_id
 * DESCRIPTION
 *  Get screen ID of the screen that is commited previously.
 *  This funciton is prepare for SSE specially, applicaion should not directly use it.
 *  
 * PARAMETERS
 *  offset  1 -> illeage use
 *  offset  0 -> latest committed 
 *          -1 -> the previously committed id of latest comitted
 *          -2 -> the previously committed id of offset (-1)
 *          ...
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_frm_screen_get_committed_id(S32 offset)
{
    S32 targetIdx;
    MMI_ASSERT(offset <= 0);
    targetIdx = (mmi_frm_scr_mgm_data.scrnLogIdx - 1 + offset) % MAX_SCREEN_LOG_SIZE;
    return mmi_frm_scr_mgm_data.scrnLogData[targetIdx];
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_enable_anti_blink
 * DESCRIPTION
 * Switch on/off antiblink mechanism
 * PARAMETERS
 *  enable TRUE  -> enable anti blink
 *  disable TRUE  -> disableable anti blink
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_frm_enable_anti_blink(MMI_BOOL enable)
{
	g_mmi_frm_screen_enable_anti_blink = enable;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_screen_commit
 * DESCRIPTION
 *  
 *  Finish current message iteration. Commit all the changes of screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_screen_commit(void)
{

    MMI_ID group_id = GRP_ID_INVALID;
    MMI_ID scrn_id  = GRP_ID_INVALID;

    mmi_frm_screen_set_sse_backup(MMI_TRUE);
   if (((mmi_frm_scr_mgm_data.dirty == MMI_FALSE) &&
        (mmi_frm_scr_mgm_data.apControlBltOnce == MMI_FALSE))
        ||(g_mmi_frm_screen_enable_anti_blink == MMI_FALSE))
    {
#if defined(__MMI_SCREEN_SWITCH_EFFECT__)
        gui_screen_switch_effect_reset_flag();
#endif
        return;
    }

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_get_active_scrn_id(&group_id, &scrn_id);
    //activeScrnId = GetActiveScreenId();
    mmi_frm_scr_mgm_data.scrnLogData[mmi_frm_scr_mgm_data.scrnLogIdx] = (group_id<<16)|(scrn_id);
    mmi_frm_scr_mgm_data.prevScrnLevel = mmi_frm_scr_mgm_data.currScrnLevel;
    mmi_frm_scr_mgm_data.currScrnLevel = mmi_frm_get_screen_level(scrn_id);
    mmi_frm_scr_mgm_data.currScrnLevel -= (gui_sse_get_is_dummy_screen()) ? (1) : (0);
    mmi_frm_scr_mgm_data.scrnLogIdx = (mmi_frm_scr_mgm_data.scrnLogIdx + 1) % MAX_SCREEN_LOG_SIZE;
    
    mmi_frm_scr_mgm_data.changeRecording = MMI_TRUE;
    if ( mmi_frm_scr_mgm_data.dirty)
    {
        mmi_frm_scr_mgm_data.dirty = MMI_FALSE;
        mmi_frm_refrsh_lcm();
    }
    else if(mmi_frm_scr_mgm_data.apEnterScreen == MMI_TRUE)
    {
#if defined(__MMI_VUI_ENGINE__)
            vfx_mmi_screen_entered();
#endif /* defined(__MMI_VUI_ENGINE__) */
    }
    mmi_frm_scr_mgm_data.apControlBltOnce = MMI_FALSE;
	mmi_frm_scr_mgm_data.apEnterScreen = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_screen_is_sse_backup_on
 * DESCRIPTION
 *  
 *  The function is designed for SSE to determine the timing of the screen 
 *  that is going to change.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_frm_screen_is_sse_backup_on(void)
{
    return mmi_frm_scr_mgm_data.sseBackupOn;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_screen_set_change_record_mode
 * DESCRIPTION
 *  
 *  Turn on/off change recording mode. This function is used for dealing with some
 *  special case that screens are not real screens and should be skipped recording the
 *  screen change. For example, group adaptor. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_screen_set_change_record_mode(MMI_BOOL changeRecording)
{
    mmi_frm_scr_mgm_data.changeRecording = changeRecording;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_frm_screen_change
 * DESCRIPTION
 *  
 *  The function will be invoked after scrn_active and mmi_frm_entry_new_screen_int
 *  This is not standard interface to applicaiton, application should not use it!
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_screen_change(void)
{
    
    /* skip some special case such as group adaptor */
    if (mmi_frm_scr_mgm_data.changeRecording == MMI_FALSE)
    {
        return;
    }
    
    if (mmi_frm_scr_mgm_data.dirty == MMI_FALSE)
    {
        mmi_frm_scr_mgm_data.dirty = MMI_TRUE;
    }
    // Reset blit mode to default mode
    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_DEFAULT);
	mmi_frm_scr_mgm_data.apEnterScreen = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_screen_get_direction
 * DESCRIPTION
 *  
 *  The function is interface for SSE to get screen moving direction (forward or backward)
 *  SSE can refer this value as a criteria to determine the effect that shoule be applied.
 * PARAMETERS
 *  None
 * RETURNS
 *  > 0     forward
 *  = 0     same level
 *  < 0     backward
 *****************************************************************************/
S32 mmi_frm_screen_get_direction()
{
    return  mmi_frm_scr_mgm_data.currScrnLevel  - mmi_frm_scr_mgm_data.prevScrnLevel;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_screen_get_depth
 * DESCRIPTION
 *  
 *  The function is interface for SSE to get current screen depth.
 *  SSE can refer this value as a criteria to determine the effect that shoule be applied.
 * PARAMETERS
 *  None
 * RETURNS
 *  Current screen level
 *****************************************************************************/
U32 mmi_frm_screen_get_depth()
{
    return  mmi_frm_scr_mgm_data.currScrnLevel;
}


#else /* __MMI_LCM_PRIMITIVE_FLUSH__ */
//Dummy function for turn off the primitive flush feature
void mmi_frm_scr_mgm_init(){}
void mmi_frm_set_curr_scr_blt_mode(mmi_frm_scr_blt_mode_enum mode){}
void mmi_frm_ui_force_update_now(void){}
void mmi_frm_screen_change(void){}

#endif /* __MMI_LCM_PRIMITIVE_FLUSH__ */


//#define __MMI_LCM_PRIMITIVE_FLUSH_UNIT_TEST__


#ifdef __MMI_LCM_PRIMITIVE_FLUSH_UNIT_TEST__
/*****************************************************************************
 Anti blinking mechanism test case  
 *****************************************************************************/


extern void goto_main_meu(void);
extern void mmi_phb_entry_main_menu(void);
extern void EntryOrganizer(void);
extern void ClndrPreEntryApp(void);

static void antiblink_test_hist_entry1(void)                                                              
{                                                                                                     
    EntryNewScreen(30000, NULL, antiblink_test_hist_entry1, NULL);
    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
    ShowCategory65Screen((U8*) L"Immediate mode, should appear", IMG_GLOBAL_INFO, NULL);
}

static void antiblink_test_hist_entry2(void)                                                              
{                                                                                                     
    EntryNewScreen(30000, NULL, antiblink_test_hist_entry2, NULL);
    ShowCategory65Screen((U8*) L"default mode, should disappear", IMG_GLOBAL_INFO, NULL);
}


void start_anitblink_group_test(void)
{
    goto_main_menu();
    mmi_phb_entry_main_menu();
    GoBackHistory();
    GoBackHistory();
    goto_main_menu();
    EntryOrganizer();
    ClndrPreEntryApp();
    antiblink_test_hist_entry1();
    antiblink_test_hist_entry2();
    GoBackHistory();
    GoBackHistory();
    GoBackHistory();
    GoBackHistory();
    GoBackHistory();
}

void start_anitblink_group_test2(void)
{
    mmi_phb_entry_main_menu();
    EntryOrganizer();
    GoBackHistory();
    GoBackHistory();
    GoBackHistory();
}
#endif /*__MMI_LCM_PRIMITIVE_FLUSH_UNIT_TEST__*/



