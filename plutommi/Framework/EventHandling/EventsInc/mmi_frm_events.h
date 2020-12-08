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
 * mmi_frm_events.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Events.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MMI_FRM_EVENTS_H
#define MMI_FRM_EVENTS_H

//RHR Add
#include "MMI_features.h"
#include "MMIDataType.h"
#include "mmi_frm_events_gprot.h"

typedef struct
{
    mmi_event_struct *evt_p;
    mmi_proc_func proc;
} mmi_post_event_proc_struct;


typedef struct
{
    mmi_event_struct *evt_p;
    mmi_proc_func proc;
    mmi_post_event_result_proc_func result_cb;
    void *result_cb_user_data;
} mmi_post_event_proc_ex_struct;




/***************************************************************************** 
* Define
*****************************************************************************/
/*----------------------------------------------------------------*
  Interrupt Mechanism
 *----------------------------------------------------------------*/
#if !defined(LOW_COST_SUPPORT)
    #define MAX_INTERRUPT_EVENT	30       /* max number of interrupt events (protocol, timer & hardware) */
#else
    #define MAX_INTERRUPT_EVENT	20       /* max number of interrupt events (protocol, timer & hardware) */
#endif

#define MMI_INT_EVENT_GROUP_MASK (0x8000)



/***************************************************************************** 
* Typedef 
*****************************************************************************/
/* Async PRT event information struct */
typedef struct _PseventInfo
{
    PsFuncPtr entryFuncPtr;
    U16 eventID;    /* for timer & hardware events      */
    U8 flagMulti;   /* is multi-handler or not */
} PseventInfo;

typedef struct _PIntseventInfo
{
    U16 eventID;    /* for timer & hardware events      */
    PsIntFuncPtr entryIntFuncPtr;
    PsIntFuncPtr postIntFuncPtr;
} PsInteventInfo;

/* enum event table */
typedef enum {
    EVENT_TABLE_MASTER,     /* main table */
#ifdef __MMI_DUAL_SIM__
    EVENT_TABLE_SLAVE,      /* table for dual sim */
#endif
    EVENT_TABLE_END
} mmi_frm_event_table_enum;

/* static info of event table (may declared as const) */
typedef struct {
    PseventInfo *table;     /* pointer to event table */
    U16 num_of_events;      /* number of events (table size) */
} mmi_frm_event_static_info_struct;

/* runtime info of event table */
typedef struct {
    U16 max_events;     /* max. count of events used*/
    U16 used_events;    /* count of currently used events */
} mmi_frm_event_runtime_info_struct;


typedef struct
{
    U32 key;
    U32 data;
}mmi_frm_pair_data_struct;

/*----------------------------------------------------------------*
  Interrupt Mechanism
 *----------------------------------------------------------------*/
/*
 * If we want to add the new interrupt event group,
 * define the new interrupt event group id here.
 */
typedef enum
{
    MMI_SMS_INT_EVENT_GROUP = MMI_INT_EVENT_GROUP_MASK,
    MMI_CARD_PLUG_EVENT_GROUP
} interrtupGroupEventId;



/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/* Event handler global data */
extern U16 maxProtocolEvent;
extern U16 usedProtocolEvent;

#ifdef __MMI_DUAL_SIM__
    extern U16 maxSlaveProtocolEvent;
    extern U16 usedSlaveProtocolEvent;
#endif /* __MMI_DUAL_SIM__ */


/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
extern void InitEvents(void);                           /* initilize events func */

extern void DeInitFramework_KeyAndEventHandler(void);
extern void DeInitFramework_History(void);
extern void DeInitFramework(void);

extern FuncPtrShort mmi_frm_get_hint_hdlr(U16 menu_id);
extern MMI_BOOL mmi_frm_binary_search(U32 key, mmi_frm_pair_data_struct* search_table, U32 table_size, U32* index);
extern MMI_BOOL mmi_frm_binary_search_ex(U32 key, mmi_frm_pair_data_struct* search_table, U32 num, U32* index);

extern void wap_suppress_popup(kal_bool is_true);

extern U8 mmi_frm_get_post_event_peak_num(void);
extern U8 mmi_frm_at_snapshot_req(void *para, int src_mod);
extern U8 mmi_pen_css_req(void *para, int src_mod);
#endif /* MMI_FRM_EVENTS_H */ 




