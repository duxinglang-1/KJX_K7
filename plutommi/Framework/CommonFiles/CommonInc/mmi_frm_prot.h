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
 *  mmi_frm_prot.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Framework function declaration
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MMI_FRM_PROT_H
#define MMI_FRM_PROT_H


/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
 * Include header file
 *****************************************************************************/
#include "MMI_features.h"           /* Must include these files for data type */

//#include <stdarg.h>
//#include "kal_release.h"        /* Basic data type */
//#include "kal_trace.h"
//#include "stack_common.h"
//#include "stack_msgs.h"
//#include "app_ltlcom.h" /* Task message communiction */
//#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
//#include "app_buff_alloc.h"
//#include "stack_timer.h"
//#include "event_shed.h"
//#include "syscomp_config.h"
//#include "task_config.h"
//#include "l4a.h"
//#include "fat_fs.h"
//#include "custom_config.h"
//#include "lcd_ip_cqueue.h"
//#include "stack_types.h"
//#include "stack_init.h"
//#include "stack_ltlcom.h"
//#include "l3_inc_enums.h"
//#include "phb_defs.h"
//#include "mmi_msg_struct.h"
#include "MMIDataType.h"
//#include "GlobalConstants.h"

/* Trace & debug related service */
//#include "MMI_trc_int.h"
//#include "MMI_fw_trc.h"
//#include "MMI_inet_app_trc.h"
//#include "MMI_media_app_trc.h"
//#include "MMI_common_app_trc.h"
//#include "MMI_conn_app_trc.h"
//#include "DebugInitDef_Int.h"

/* Framework internal service */
//#include "mmi_frm_queue_gprot.h"
//#include "mmi_frm_mem_gprot.h"
//#include "mmi_frm_events.h"
//#include "mmi_frm_input.h"
//#include "mmi_frm_history.h"
//#include "mmi_theme_converter.h"
//#include "filemgr.h"                /* Must include this file before ThemeArchiverDef.h */
//#include "mmi_clipboard_prot.h"
//#include "fix_size_mem.h"
//#include "mmi_frm_remutex_gprot.h"
//#include "mmi_frm_at_util_prot.h"
//#include "mmi_frm_event_flag_prot.h"
#include "gui_typedef.h"


//RHR Add

#include "kal_public_defs.h"
#include "stack_config.h"
#include "mmi_frm_gprot.h"
#include "mmi_frm_history_gprot.h"

#include "kal_general_types.h"
/***************************************************************************** 
* Define
*****************************************************************************/
/*
 * This macro is used to calculate the the size of array, whose unit is bytes
 */
#define  ARRAYSIZE(a)   sizeof(a) / sizeof(a[0])

#ifdef MMI_CB_MGR_UT
    extern void mmi_cb_manager_ut_entry(U8 index);
#endif /* MMI_CB_MGR_UT */

/*----------------------------------------------------------------*
  Queue
 *----------------------------------------------------------------*/
/* Queue global MACRO */
#if defined(__MMI_DUAL_SIM_MASTER__)
	#define CIRCQ_NO_OF_NODES 130
#else
	#define CIRCQ_NO_OF_NODES 65 
#endif


/*----------------------------------------------------------------*
  Event mechanism 
 *----------------------------------------------------------------*/
/* Post event type recorded in link list node */
#define POST_CB_EVT        1
#define POST_CB_EVT_EX     2
#define POST_EVT           3
#define POST_EVT_EX        4

/* swtich for turn on anti-blink mechanism */
#define __MMI_LCM_PRIMITIVE_FLUSH__

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/*----------------------------------------------------------------*
  Callback manager 
 *----------------------------------------------------------------*/
typedef struct
{
    mmi_event_struct *evt_p;
    mmi_post_event_result_proc_func result_cb;
    void *result_cb_user_data;
} mmi_post_evt_ex_struct;

/***************************************************************************** 
* Extern Variable
*****************************************************************************/

/*----------------------------------------------------------------*
  MMI task
 *----------------------------------------------------------------*/
extern oslMsgqid mmi_ext_qid; 
extern U8 g_input_msg_in_queue;     /* to check if input messages wait to process */

/***************************************************************************** 
* Extern Function
*****************************************************************************/
/*----------------------------------------------------------------*
  MMI task
 *----------------------------------------------------------------*/
extern MMI_BOOL MMI_Init(task_indx_type task_indx);        
extern void MMI_task(oslEntryType *entry_param);
extern void Dummy_task(oslEntryType *entry_param);
extern void InitNvramData(void);
extern void ProtocolEventHandler(U16 eventID, void *MsgStruct, int mod_src, void *Message);
extern void mmi_frm_fetch_msg_from_extQ_to_circularQ(void);
extern void InitFramework(void);

/*----------------------------------------------------------------*
  Timer
 *----------------------------------------------------------------*/
extern void EvshedMMITimerHandler(void *dataPtr); 
extern void L4InitTimer(void);

/*----------------------------------------------------------------*
  Events
 *----------------------------------------------------------------*/
extern void mmi_frm_event_set_switch_screen_flag(MMI_BOOL flag);
extern MMI_BOOL mmi_frm_event_get_switch_screen_flag(void);
extern void mmi_frm_event_set_dump_history_flag(MMI_BOOL flag);
extern MMI_BOOL mmi_frm_event_get_dump_history_flag(void);
extern MMI_BOOL mmi_execute_scrn_exit_func(void);
extern void mmi_frm_get_protocol_event_handler(U16 eventID, PsFuncPtr* pFuncPtr);

/*----------------------------------------------------------------*
  Touch screen 
 *----------------------------------------------------------------*/
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MTK_TARGET__)
extern void mmi_frm_pen_reset_context_for_new_screen(void);
#endif

/*----------------------------------------------------------------*
  Callback manager 
 *----------------------------------------------------------------*/
extern S32 mmi_frm_invoke_post_event(void);

/*----------------------------------------------------------------*
  Event mechanism 
 *----------------------------------------------------------------*/
extern U32 mmi_frm_get_post_evt_num(void);
extern void enqueue_post_evt(void *evt_p, U8 evt_flag);
extern void *dequeue_post_evt(U8 *evt_flag);

/*----------------------------------------------------------------*
  Scenario - screen group
 *----------------------------------------------------------------*/
extern void mmi_frm_shell_init(void);
extern MMI_BOOL mmi_frm_shell_is_in_backward_scenario(void);
extern void scenario_process_post_process(void);
extern mmi_id mmi_frm_scrn_tab_get_active_id(void);
extern void tab_l_arrow_key_hdlr(void);
extern void tab_r_arrow_key_hdlr(void);
extern void set_active_scrn_id(MMI_ID group_id, MMI_ID scrn_id);
extern void set_exit_scrn_id(MMI_ID group_id, MMI_ID scrn_id);
extern void mmi_frm_ui_exit(void);
extern void mmi_frm_ui_pre_exit(void);
extern U16 get_active_history_node_id(void);
extern U16 get_exit_history_node_id(void);
extern void set_active_history_node_id(U16 id);
extern U8 mmi_frm_scenario_close_to_idle(void);
extern U8 mmi_frm_history_back_to_idle(void);
extern MMI_BOOL mmi_frm_scrn_in_external_goback(void);
extern MMI_BOOL mmi_frm_is_in_tab_screen(void);
extern void mmi_frm_close_active_empty_group(void);
extern MMI_BOOL mmi_frm_is_in_deinit_scenario(void);
extern void Deinit_active_screen_info(void);
extern MMI_BOOL mmi_frm_is_in_end_key_process(void);
extern U16 get_active_scrn_type(void);
extern void mmi_frm_execute_scenario_post_event(void);
extern void mmi_frm_dump_tree(U8 tree_type);
extern void mmi_frm_dump_node(void* in, U32 level);
extern MMI_BOOL mmi_frm_asm_prepare_check(mmi_id app_id);
extern MMI_BOOL mmi_frm_get_tab_bar_items_int(tab_bar_item_type *tab_bar_items_p, S8 *tabs_p);
extern void mmi_frm_redraw_bg(void);
#ifdef __MMI_LCM_PRIMITIVE_FLUSH__
extern void mmi_frm_screen_change(void);
extern void mmi_frm_screen_set_change_record_mode(MMI_BOOL changeRecording);
#endif /* __MMI_LCM_PRIMITIVE_FLUSH__ */
extern void UI_common_screen_exit(void);
extern void UI_common_screen_pre_exit(void);
/*----------------------------------------------------------------*
  History
 *----------------------------------------------------------------*/
extern MMI_BOOL is_top_history_node(U16 srnID);
extern U16 top_scrn_in_go_back_id;
extern HistoryDelCBPtr top_scrn_in_go_back_destroy_func;
extern void *top_scrn_in_go_back_arg_p;
//#define ENHANCE_HISTORY_UNIT_TEST
#endif /* MMI_TASK_H*/ 


