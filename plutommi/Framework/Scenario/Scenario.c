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
 * Scenario.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for scenario mechanism.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
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
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/***************************************************************************** 
*  Definition
*****************************************************************************/ 
//#include "MMI_include.h"
#include "mmi_frm_prot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_scenario_prot.h"
//#include "CommonScreens.h"
#include "AppMgrSrvProt.h"


//RHR Add

#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "kal_general_types.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_events.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories.h"
#include "gui_effect_oem.h"
#include "mmi_fw_trc.h"
#include "MMI_fw_trc.h"
#include "kal_trace.h"
#include "mmi_frm_history.h"
#include "fix_size_mem.h"
#include "string.h"
//#include "app_buff_alloc.h"
#include "mmi_frm_mem_gprot.h"
#include "pluto_fw_trc.h"
#include "mmi_frm_input.h"
#include "wgui_categories_list.h"
#include "wgui_categories_enum.h"
#include "wgui_draw_manager.h"
#include "wgui_inline_edit.h"
#include "gui_typedef.h"
#include "Unicodexdcl.h"
#include "mmi_frm_at_util_prot.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "MMI_features.h"
#include "wgui_touch_screen.h"
#include "wgui_categories_util.h"
#include "mmi_cb_mgr_gprot.h"
#include "gui_data_types.h"
#include "mmi_theme_mgr.h"
#include "Kal_debug.h"


/***************************************************************************** 
*  To do move this part to resource gen procedure
*****************************************************************************/ 

/***************************************************************************** 
*  Internal Small Feature
*****************************************************************************/
#define __MMI_SCENARIO_SMALL_SCREEN_SUPPORT_EXIT_CHANGE__
#define __MMI_SCENARIO_CLOSE_ADAPTOR_NODE_AT_DELCB__

//#if defined(__MMI_FRM_HISTORY__) && !defined(__MTK_TARGET__)
//#define _SCENARIO_TEST_
//#endif

/***************************************************************************** 
*  Define
*****************************************************************************/

/*
 * scenario post event type
 */
#define SCENARIO_POST_TYPE_INTERNAL         (0x0)
#define SCENARIO_POST_TYPE_APP              (0x1)

/* FRM_RESERVED_GROUP_NUMBER should be 32 bit-align */
#define FRM_RESERVED_GROUP_MASK_UNIT        (32)

/* record the latest free idx  for framework auto gen case */
#define FRM_AUTO_GEN_GROUP_FREE_RECORD      (3)

/* scenario post queue size */
#define SCENARIO_POST_QUEUE_SIZE            (30)

/* The way of search trees (scenario_tree, background tree, service tree)*/

/* API to post scenario event */
#define _POST_INTERNAL_SCENARIO_EVT(g_id, s_id, act, evt)   \
    post_scenario_evt((MMI_ID)g_id, s_id, act, (mmi_scenario_evt_struct *)evt, 0, MMI_FALSE)
#define _POST_APP_SCENARIO_EVT(g_id, s_id, act, evt)        \
    post_scenario_evt((MMI_ID)g_id, s_id, act, (mmi_scenario_evt_struct *)evt, 1, MMI_FALSE)

#define _POST_APP_SCENARIO_EVT_TO_FRONT(g_id, s_id, act, evt)        \
    post_scenario_evt((MMI_ID)g_id, s_id, act, (mmi_scenario_evt_struct *)evt, 1, MMI_TRUE)

/* API to allocate/free memory */
#define _MMI_MEM_ALLOC(s, t)                   mmi_frm_malloc_dbg(s, (void *)t)
#define _MMI_MEM_FREE(p, t)                    mmi_frm_mfree_dbg(p, (void *)t)

/* user data for input/gui buffer allocate by framework */
#define SCENARIO_HISTORY_DATA               ((void*)0x11111111)


/***************************************************************************** 
*  Local Variable
*****************************************************************************/

/* screen manager context */
shell_struct shell = {0};

/* total 64 bits to present framework's autogen group id */
static U32 g_frm_group_mask[FRM_RESERVED_GROUP_NUMBER/FRM_RESERVED_GROUP_MASK_UNIT];

/* last index of auto genenarated group id */
static U8 g_frm_group_last_idx = 1;

/* keep the last free idx */
static U8 g_frm_group_free_idx[FRM_AUTO_GEN_GROUP_FREE_RECORD];

/* input buffer pointer */
static WCHAR* g_curr_input_buf = NULL;

/* input buffer size */
static U16 g_curr_input_size = 0;

/*
 * There are two kinds of post event. 
 * One is for scenario internal usage
 * another is for posting the application action. 
 */
static post_queue_struct post_queue[SCENARIO_POST_QUEUE_SIZE];
static S32 post_queue_idx = -1;

/*
 * Memory record for debug usage
 */
static U32 g_mem_dbg_record[100];
static S32 g_mem_dbg_record_idx = -1;

/*
 * screen manager information
 */
static screen_mgr_struct g_scrn_mgr_cntx = {0};



#ifdef __MMI_FRM_HISTORY__
extern MMI_BOOL g_is_back_root_main_hist;
extern MMI_BOOL g_is_stop_when_forbiden;
#endif
extern mmi_ret mmi_frm_asm_scenario_hook(scenario_hook_evt_enum evt, base_node_struct *node);

#ifndef __MMI_FRM_HISTORY__ 
static MMI_BOOL isEnableSmallScrnRedraw_sg = MMI_TRUE;
#endif
static MMI_BOOL group_close_from_gprot = MMI_TRUE; // need check re_entry(post)

static const CHAR g_fake_gui_buf = 'G';

/***************************************************************************** 
*  Local Function
*****************************************************************************/
/* scenario event related */
static void post_scenario_evt(MMI_ID group_id, U32 scrn_id, post_scenario_act_enum act, mmi_scenario_evt_struct *evt, U32 type, MMI_BOOL is_front);
static void scenario_process_post_evt_ex(U32 type);

/* tree base operation */
static void add_node_tree_op(group_node_struct* node_parent, base_node_struct* node_new);
static void remove_node_tree_op(group_node_struct* node_parent, base_node_struct* node_del);
static base_node_struct* get_child_tree_op(group_node_struct* node_parent, U32 child_id);
static base_node_struct* get_node_tree_op(group_node_struct* node_parent, U32 self_id);
/* screen \ group base operation */
static base_node_struct* get_node_sg_op(U32 self_id, U8 tree_type);
static void replace_node_sg_op(base_node_struct* node_old, mmi_frm_node_struct* node_new_info, MMI_BOOL b_group);
static void free_node_sg_op(base_node_struct* node_free, MMI_BOOL b_include_self);
static void remove_free_node_sg_op(group_node_struct* node_parent, base_node_struct* node_free);

static mmi_ret node_exec_entry_proc(scrn_node_struct*   scrn_ptr);
static mmi_ret process_root_screen_enter(mmi_event_struct *evt);

/* tree related operation */
static base_node_struct* find_prev_node(base_node_struct* node);
static base_node_struct* find_next_node(base_node_struct* node);
static scrn_node_struct* find_latest_descendant_scrn(U32 id, group_node_struct* node);

static base_node_struct *find_root_screen(U32 group_id);
static group_node_struct* find_caller(group_node_struct* parent, group_node_struct* node);


/* screen history */
static U32 is_category57_screen(void);
static void scrn_add_history(scrn_node_struct *node);
static void scrn_free_history(scrn_node_struct *node);

/* group related*/
static group_node_struct* create_new_group(group_node_struct* node_parent, MMI_ID node_new_id, mmi_proc_func proc, void *data, MMI_BOOL* b_exist);
static void group_post_hide(group_node_struct *node, mmi_scenario_evt_struct* evt);
static void group_move(group_node_struct *node, mmi_scenario_evt_struct* evt);
static void group_inactive(group_node_struct *node, mmi_scenario_evt_struct* evt);
static void group_post_inactive(group_node_struct *node, mmi_scenario_evt_struct* evt);
static void group_active(group_node_struct *node, mmi_scenario_evt_struct* evt);
static void group_hide(group_node_struct *node, mmi_scenario_evt_struct* evt);
static void group_unhide(group_node_struct *node, mmi_scenario_evt_struct* evt);
static void group_post_active(group_node_struct *node, mmi_scenario_evt_struct* evt);
static void group_focus_change(group_node_struct *node, mmi_scenario_evt_struct* evt, MMI_BOOL is_focus);
static void group_post_exit(group_node_struct *node, mmi_scenario_evt_struct* evt);
static mmi_ret group_close(group_node_struct *node, mmi_scenario_evt_struct* evt);
static mmi_ret mmi_frm_group_close_ex (MMI_ID group_id, U32 type, group_node_struct **parent, MMI_BOOL post_to_front);

/* screen related */
static scrn_node_struct* create_new_scrn(MMI_ID parent_id, MMI_ID id, mmi_scrn_func entry_proc, void *user_data);
static void scrn_inactive_internal_process(scrn_node_struct *node, U32 forward_flag);
static void scrn_inactive(scrn_node_struct *node, mmi_scenario_evt_struct* evt);
static void scrn_active(scrn_node_struct *node, mmi_scenario_evt_struct* evt);
static void scrn_hide(scrn_node_struct *node, mmi_scenario_evt_struct* evt);
static void scrn_unhide(scrn_node_struct *node, mmi_scenario_evt_struct* evt);
static void scrn_post_active(scrn_node_struct *node, mmi_scenario_evt_struct* evt);
static mmi_ret scrn_close(scrn_node_struct *node, mmi_scenario_evt_struct* evt);
static mmi_ret mmi_frm_scrn_close_ex (MMI_ID parent_id, MMI_ID scrn_id, scrn_close_type_enum flag);


#ifndef __MMI_NOT_TAB_SUPPORT__
/* tab related */
static tab_node_struct* create_new_tab(
                            MMI_ID parent_id, 
                            MMI_ID id, 
                            mmi_scrn_func entry_proc, 
                            void *user_data, 
                            mmi_frm_tab_struct *tab_pages_info_array, 
                            U8 tab_pages_count, 
                            U8 sel_idx);
static void tab_l_arrow_key_action(void);
static void tab_r_arrow_key_action(void);
#endif /* __MMI_NOT_TAB_SUPPORT__ */

static void execute_node_inactive(base_node_struct *node, mmi_event_struct* param);
static void execute_node_active(base_node_struct *node, mmi_event_struct* param);
static void execute_node_hide(base_node_struct *node, mmi_event_struct* param);
static void execute_node_unhide(base_node_struct *node, mmi_event_struct* param);
static mmi_ret execute_node_close(base_node_struct *node, mmi_event_struct* param);
static void execute_node_deinit(base_node_struct *node, mmi_event_struct* param);
static void execute_node_post_deinit(base_node_struct *node, mmi_scenario_evt_struct* evt);

/* Memory allocate API */
static void *mmi_frm_malloc_dbg(U32 size, void *arg);
static void mmi_frm_mfree_dbg(void *ptr, void *arg);

#ifdef __MMI_FRM_HISTORY__
/* screen group history adaptor API */
static void scrn_group_adaptor_entry(group_node_struct *node);
static U8 scrn_group_adaptor_delete_cb(void* type);
static U8 scrn_group_adaptor_destroy_cb(void* type);

#endif
#ifndef __MMI_FRM_HISTORY__
static mmi_ret scrn_check_small_ex(base_node_struct *node_ptr, void *arg);
static void mmi_frm_redraw_bg_ex(void);
#endif

/* related related */
static mmi_ret scrn_redraw_clean(scrn_node_struct *node);
static mmi_ret group_redraw_start(base_node_struct *node_ptr, void * arg);
static mmi_ret group_redraw_end(base_node_struct *node_ptr, void * arg);

static void adaptor_show_dummy_screen(void);

static base_node_struct* traverse_scenario_tree(base_node_struct *start_node_ptr, TraverseNodeOpFunc scrnFunc, TraverseNodeOpFunc groupStartFunc, TraverseNodeOpFunc groupEndFunc, void* arg);


void insert_node_by_handle(group_node_struct* node_parent,base_node_struct* node_base,base_node_struct* new_node,mmi_scenario_node_flag flag);
mmi_ret mmi_frm_node_insert (MMI_ID parent_id, MMI_ID base_id, mmi_frm_node_struct *new_node_info, mmi_scenario_node_flag flag, U8 is_group_node);
static mmi_ret scrn_common_exit(mmi_scrn_essential_struct* data);
static mmi_ret scrn_common_entry(mmi_scrn_essential_struct* data);
static base_node_struct *is_need_to_active_previous(group_node_struct *node);

#ifndef __MMI_NOT_TAB_SUPPORT__
static void change_tab_info(tab_node_struct *tab, mmi_frm_tab_struct *tab_pages_info_array, U8 tab_pages_count, U8 sel_idx);
#endif/* __MMI_NOT_TAB_SUPPORT__ */


#define EXECUTE_NODE_PROCESS(action) \
        if(SCENARIO_GROUP_NODE == node->type) \
        { \
            group_##action##(_GROUP(node), evt); \
        } \
        else \
        { \
            scrn_##action##(_SCRN(node), evt); \
        } \


#define EXECUTE_NODE_PROCESS_EX(action) \
        if(SCENARIO_GROUP_NODE == node->type) \
        { \
            result = group_##action##(_GROUP(node), evt); \
        } \
        else \
        {\
            result = scrn_##action##(_SCRN(node), evt); \
        } \


/***************************************************************************** 
*  Framework Global funcation
*****************************************************************************/
static void adaptor_show_dummy_screen(void)
{
    ShowCategoryDummyScreen();
    gui_sse_set_is_dummy_screen(MMI_FALSE);
}


mmi_ret mmi_dummy_proc(mmi_event_struct *in)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_RET_OK;
}

void mmi_frm_set_active_group_int(MMI_ID group_id)
{
	group_node_struct *target_node = NULL;
    MMI_ID dummy_id;
	target_node = (group_node_struct*)SG_GET_CHILD(&shell.scenario_root, group_id);
	/* 1. Entry dummy screen */
    dummy_id = mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_dummy_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_display_dummy_screen();

#ifdef __MMI_FRM_HISTORY__        
        /* 2. Move the target group node to the top of history */
    mmi_frm_move_history_node_to_top(group_id);
#endif

    /* 3. change the group order in shell.scenario_root */
    SG_REMOVE_NODE(&shell.scenario_root, _NODE(target_node));
    insert_node_by_handle(&shell.scenario_root,SG_GET_CHILD(&shell.scenario_root, dummy_id),
        _NODE(target_node), MMI_FRM_NODE_BEFORE_FLAG);
    /* 4. Close the dummy screen */
    mmi_frm_group_close(dummy_id);
}

MMI_BOOL mmi_frm_set_active_group(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    group_node_struct *target_node = NULL;
	MMI_ID dummy_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SET_ACTIVE_GROUP_START, group_id);
    if (shell.state == MMI_SCENARIO_STATE_NONE )
    {
		mmi_ret ret;
		target_node = (group_node_struct*)SG_GET_CHILD(&shell.scenario_root, group_id);
		if (target_node == NULL)
		{
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SET_ACTIVE_GROUP_END, 10);
            MMI_ASSERT(0);
            return MMI_FALSE;
		}

		if (mmi_frm_group_is_in_active_serial(group_id) == MMI_TRUE)
		{
			MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SET_ACTIVE_GROUP_END, 30);
			return MMI_TRUE;
		}

		//put a dummy here to prevent to trigger small screen redraw after on_hook return MMI_RET_OK
		dummy_id = mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_dummy_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

		ret = mmi_frm_asm_scenario_hook(HOOK_EVT_SET_ACTIVE_APP, (base_node_struct *)target_node);
		if (ret != MMI_RET_OK)
		{
			return MMI_FALSE;
		}

		mmi_frm_set_active_group_int(group_id);
		mmi_frm_group_close(dummy_id);

        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SET_ACTIVE_GROUP_END, 0);
    #ifdef __TST_TRACE_ENABLED__
        HistoryDump();
        mmi_frm_event_set_dump_history_flag(MMI_FALSE);
    #endif
        return MMI_TRUE;

    }
    else
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SET_ACTIVE_GROUP_END, 30);
        return MMI_FALSE;
    }
}


S32 mmi_frm_node_query_sequence(MMI_ID group_id, MMI_ID base_id, MMI_ID query_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    group_node_struct   *group_node = NULL;
    base_node_struct    *tmp = NULL;
    S32                 idx = 0;
    S32                 base_idx = -1;
    S32                 query_idx = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_node = (group_node_struct*)SG_GET_NODE_FROM_ROOT(group_id);
    if (group_node && group_node->m_count > 2)
    {
        tmp = group_node->m_head;
        while (tmp)
        {
            if (base_id == (MMI_ID)(tmp->id))
            {
                base_idx = idx;
            }
            else if (query_id == (MMI_ID)(tmp->id))
            {
                query_idx = idx;
            }

            if (base_idx != -1 && query_idx != -1)
            {
                /* We found base_idx and query_idx and could exit the while loop */
                return (query_idx - base_idx);
            }
            idx++;
            tmp = tmp->m_next;
        }
    }
    return 0;
}

mmi_ret dummy_screen_entry_proc(mmi_scrn_essential_struct* data)
{
    if(mmi_frm_scrn_enter(data->group_id, data->scrn_id, NULL, (FuncPtr)dummy_screen_entry_proc, MMI_FRM_FULL_SCRN))
    {
        /* dummy screen doesn't need to add in the history */
        mmi_frm_scrn_clear_attribute(data->group_id, data->scrn_id, MMI_SCRN_ATTRIB_ADD_HISTORY);
        adaptor_show_dummy_screen();
    }
    return MMI_RET_OK;
}

void mmi_frm_display_dummy_screen_ex(MMI_ID parent_id, MMI_ID scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* We only allow display dummy screen on the active group */
    if (mmi_frm_group_is_in_active_serial(parent_id) == MMI_TRUE)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_ENTRY_DUMMY, parent_id, (U16)scrn_id, SCENARIO_NORMAL);
        mmi_frm_scrn_first_enter(parent_id, scrn_id, (FuncPtr)dummy_screen_entry_proc, NULL );
    }
    else
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_ENTRY_DUMMY, parent_id, (U16)scrn_id, ERR_ENTRY_DUMMY_NOT_ACTIVE);
    }
}


void mmi_frm_display_dummy_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_display_dummy_screen_ex((MMI_ID)shell.active_group->id, SCR_ID_DUMMY);
}


/***************************************************************************** 
*  Framework Memory Debug
*****************************************************************************/
U8 mmi_frm_scenario_get_dync_obj_info(U8 obj_type, U8 stat_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_ASSERT(obj_type < SCENARIO_NODE_END);
    MMI_ASSERT(stat_type < SCENARIO_OBJ_STAT_TYPE_END);
    return g_scrn_mgr_cntx.scenario_obj_stat[obj_type][stat_type];
}
static void *mmi_frm_malloc_dbg(U32 size, void* arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i <= g_mem_dbg_record_idx; i++)
    {
        if (g_mem_dbg_record[i] == 0)
        {
            g_mem_dbg_record[i] = (U32)mmi_frm_malloc(size);
            memset((void*)g_mem_dbg_record[i], 0, size);
            return (void*)(g_mem_dbg_record[i]);
        }
    }

    g_mem_dbg_record_idx++;
    g_mem_dbg_record[g_mem_dbg_record_idx] =  (U32)mmi_frm_malloc(size);
    memset((void*)g_mem_dbg_record[i], 0, size);
    return (void*)(g_mem_dbg_record[i]); 

}


static void mmi_frm_mfree_dbg(void *node, void *arg)
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U32 type;
    U32 size = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    type = (U32)arg;   
    for (i = 0; i <= g_mem_dbg_record_idx; i++)
    {
        if (g_mem_dbg_record[i] == (U32)node)
        {
            g_mem_dbg_record[i] = 0;

            if (SCENARIO_HISTORY_DATA == arg)
            {
                /* history data, don't need to reset the buffer */
            }
            else
            {
                if (type == SCENARIO_GROUP_NODE)
                {
                    size = sizeof(group_node_struct);
                }
                else if (type == SCENARIO_SCRN_NODE)
                {
                    size = sizeof(scrn_node_struct);
                }
            #ifndef __MMI_NOT_TAB_SUPPORT__
                else if (type == SCENARIO_TAB_NODE)
                {
                    size = sizeof(tab_node_struct);
                }
                else if (type == SCENARIO_TAB_PAGE_NODE)
                {
                    size = sizeof(tab_page_node_struct);
                }
            #endif /* __MMI_NOT_TAB_SUPPORT__ */
                else if (type == SCENARIO_POST_EVT)
                {
                    size = sizeof(mmi_post_scenario_evt_struct);
                }

                if (size != 0)
                    memset(node, 0xCC, size);
            }
            mmi_frm_free(node);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  history_buffer_malloc
 * DESCRIPTION
 *  This function is used to allocate gui buffer & input buffer
 * 
 * PARAMETERS
 *  size        : [IN]  buffer size
 *  arg         : [IN]  argument for malloc
 * RETURNS
 *  the address of history buffer
 *****************************************************************************/
void *history_buffer_malloc(U32 size, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 type = (U32)arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(type < HISTORY_BUF_END);
    return mmi_frm_malloc(size);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_max_history_buffer_size
 * DESCRIPTION
 *  This function is used to allocate gui buffer & input buffer
 * 
 * PARAMETERS
 *  size        : [IN]  buffer size
 *  arg         : [IN]  argument for malloc
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_frm_get_max_history_buffer_size(U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(type < HISTORY_BUF_END);
    return g_scrn_mgr_cntx.max_his_buf_size[type];
}


/*****************************************************************************
 * FUNCTION
 *  history_buffer_free
 * DESCRIPTION
 *  This function is used to free history buffer
 * 
 * PARAMETERS
 *  p        : [IN]  the buffer pointer
 * RETURNS
 *  void
 *****************************************************************************/
void  history_buffer_free(void *p, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_free(p);
}

/***************************************************************************** 
*  Shell
*****************************************************************************/
void mmi_frm_shell_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_frm_group_mask, 0, sizeof(U32)*(FRM_RESERVED_GROUP_NUMBER/32));
    memset(g_frm_group_free_idx, 0, sizeof(U8)*FRM_AUTO_GEN_GROUP_FREE_RECORD);
    
    memset(post_queue, 0, sizeof(post_queue));
    post_queue_idx = -1;

    shell.state = MMI_SCENARIO_STATE_NONE;
    memset(&shell.scenario_root, 0, sizeof(group_node_struct));
    shell.scenario_root.type = SCENARIO_GROUP_NODE;
    shell.scenario_root.id = GRP_ID_ROOT;
    shell.scenario_root.parent = &shell.scenario_root;
    shell.scenario_root.proc = mmi_dummy_proc;
    shell.active_group = NULL;
    shell.active_scrn = NULL;
    shell.active_tab = NULL;
    shell.scenario_dangle.type = SCENARIO_GROUP_NODE;
    shell.scenario_dangle.id = GRP_ID_DANGLE;
    shell.scenario_dangle.parent = &shell.scenario_dangle;
    shell.scenario_dangle.proc = mmi_dummy_proc;

    memset(&shell.scenario_bg, 0, sizeof(group_node_struct));
    shell.scenario_bg.type =  SCENARIO_GROUP_NODE;
    shell.scenario_bg.id   = GRP_ID_BK;
    shell.scenario_bg.parent = _GROUP(&shell.scenario_bg);
    shell.scenario_bg.proc   = mmi_dummy_proc;
}

#ifdef __MMI_FRM_HISTORY__

void mmi_frm_shell_inactive(base_node_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scenario_evt_struct evt = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SHELL_INACTIVE, node->id);
    SetBit(evt.state, MMI_SCENARIO_STATE_FORWARD_IDX);
    evt.evt_id      = EVT_ID_GROUP_INACTIVE;
    evt.user_data   = node->user_data;
    evt.targ_group  = node->id;
    evt.targ_scrn   = SCR_ID_INVALID; 
    evt.curr_group  = shell.active_group->id;
    evt.curr_scrn   = (shell.active_scrn) ? shell.active_scrn->id : SCR_ID_INVALID;
    evt.new_group   = GRP_ID_INVALID;
    evt.new_scrn    = SCR_ID_INVALID;
    shell.state     = evt.state;
	//temp = GetActiveScreenId();
    _EXECUTE_NODE_INACTIVE(node, &evt);
    if (get_active_scrn_type() == MMI_FRM_SCRN_GROUP)
    {
        scenario_process_post_evt_ex(SCENARIO_POST_TYPE_INTERNAL);
    }
    else
    {
        scenario_process_post_evt_ex(SCENARIO_POST_TYPE_APP);
    }
    shell.active_scrn = NULL;
}


void mmi_frm_shell_active(base_node_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scenario_evt_struct evt = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SHELL_ACTIVE, node->id);
#ifdef __TST_TRACE_ENABLED__
    if (node == shell.scenario_root.m_tail)
    {
        /* dump the history content fot debugging */
        HistoryDump();
        mmi_frm_event_set_dump_history_flag(MMI_FALSE);
    }
#endif

    SetBit(evt.state, MMI_SCENARIO_STATE_BACKWARD_IDX);
    evt.evt_id      = EVT_ID_SCENARIO_CHANGE;
    evt.user_data   = node->user_data;
    evt.targ_group  = node->id;
    evt.targ_scrn   = SCR_ID_INVALID;
    evt.curr_group  = GRP_ID_ORIG_MECH;
    evt.curr_scrn   = GRP_ID_ORIG_MECH;
    evt.new_group   = node->id;
    evt.new_scrn    = SCR_ID_INVALID;
    shell.state     = evt.state;

    MMI_ASSERT(_IS_GROUP(node) && node->proc);
    _EXECUTE_NODE_ACTIVE(node, &evt);
    if (is_group_node((MMI_ID)node->id) == MMI_TRUE)
    {
        scenario_process_post_evt_ex(SCENARIO_POST_TYPE_INTERNAL);
    }
    else
    {
        scenario_process_post_evt_ex(SCENARIO_POST_TYPE_APP);
    }
}
#endif /* __MMI_FRM_HISTORY__ */

static group_node_struct* is_in_active_group_serial(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    group_node_struct *group = shell.active_group;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    while (group && group != &shell.scenario_root)
    {
        if (group->id == group_id)
        {
            /* found out */
            return group;
        }
        group = group->parent;
    }
    return NULL;    
}


MMI_BOOL mmi_frm_group_is_in_dangle(MMI_ID id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    base_node_struct *node = SG_GET_NODE_FROM_DANGLE(id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return ((node != NULL) && _IS_GROUP(node)) ? MMI_TRUE : MMI_FALSE;
}


MMI_BOOL mmi_frm_is_asm_allocator(MMI_ID id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    group_node_struct *node = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node = (group_node_struct *)SG_GET_NODE_FROM_ALL(id);

    return (node != NULL) ? MMI_TRUE : MMI_FALSE;
}

MMI_ID mmi_frm_get_root_app(MMI_ID allocator_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    group_node_struct *node = NULL;
    MMI_ID id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (allocator_id == GRP_ID_ROOT ||
		allocator_id == GRP_ID_DANGLE ||
		allocator_id == GRP_ID_BK)
	{
		return GRP_ID_INVALID;
	}
    
    node = (group_node_struct*)SG_GET_NODE_FROM_ALL(allocator_id);
    
    if (node != NULL)
    {
		id = node->id;
		while(node && (node->parent!=NULL) && (node->parent != &shell.scenario_root) && (node->parent != &shell.scenario_bg))
        {
            id = node->parent->id;
            node = node->parent;
        }
        return id;
    }
    return GRP_ID_INVALID;
}

MMI_BOOL mmi_frm_shell_is_in_backward_scenario(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (shell.active_group)
    {
        return (IsBitSet(shell.state, MMI_SCENARIO_STATE_BACKWARD_IDX)) ? MMI_TRUE : MMI_FALSE;
    }
    return MMI_FALSE;
}


MMI_BOOL mmi_frm_is_in_deinit_scenario(void)
{
     return IsBitSet(shell.state, MMI_SCENARIO_STATE_DEINIT_IDX);
}


MMI_BOOL mmi_frm_is_in_backward_scenario(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL bRet = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (shell.active_group)
    {
        bRet = IsBitSet(shell.state, MMI_SCENARIO_STATE_BACKWARD_IDX) ? MMI_TRUE : MMI_FALSE;
    }
#ifdef __MMI_FRM_HISTORY__
    else
    {
        bRet = mmi_frm_check_is_back_history();
    }
#endif
    //MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_IS_BACKWARD_RET, bRet);
    return bRet;
}


/***************************************************************************** 
*  Scenario Group/Screen
*****************************************************************************/

/* tree base operation */
static void add_node_tree_op(group_node_struct* node_parent, base_node_struct* node_new)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (node_parent && node_new && NULL == get_child_tree_op(node_parent, node_new->id))
    {
        node_new->m_prev = node_parent->m_tail;
        node_new->m_next = NULL;
        if (node_parent->m_tail)
        {
            node_parent->m_tail->m_next = node_new;
        }
        node_parent->m_tail = node_new;
        if (node_parent->m_count == 0)
        {
            node_parent->m_head = node_new;
            node_parent->m_tail = node_new;
        }
        
        node_parent->m_count++;
    }
}
// base tree operation
// remove node_del from node_parent
static void remove_node_tree_op(group_node_struct* node_parent, base_node_struct* node_del)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (node_parent && node_del && get_child_tree_op(node_parent, node_del->id))
    {
        MMI_ASSERT(node_parent->m_count > 0);
        
        if (node_del->m_prev)
            node_del->m_prev->m_next = node_del->m_next;
        if (node_del->m_next)
            node_del->m_next->m_prev = node_del->m_prev;
        if (node_parent->m_tail == node_del)
            node_parent->m_tail = node_del->m_prev;
        if (node_parent->m_head == node_del)
            node_parent->m_head = node_del->m_next;
            
        node_parent->m_count--;
    }
}
static base_node_struct* get_child_tree_op(group_node_struct* node_parent, U32 child_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    base_node_struct *node_iterator = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (node_parent)
    {
        node_iterator = node_parent->m_head;
        while (node_iterator)
        {
            if (node_iterator->id == child_id)
                break;
            node_iterator = node_iterator->m_next;
        }
    }
    return node_iterator;
}

mmi_ret Equal(base_node_struct *node, void *arg)
{
    mmi_ret ret = MMI_RET_OK;
    if(node->id == (U32)arg)
        ret = MMI_RET_ERR; /* stop */
    return ret;
}

static base_node_struct* get_node_tree_op(group_node_struct* node_parent, U32 self_id)
{
    return traverse_scenario_tree((base_node_struct *)node_parent, Equal, Equal, NULL, (void*)self_id);
}

/* screen \ group base operation */
static base_node_struct* get_node_sg_op(U32 self_id, U8 tree_type)
{
    base_node_struct* node_ret = NULL;
    
    if(tree_type & 0x01)    // ROOT
    {
        node_ret = get_node_tree_op(&shell.scenario_root, self_id);
    }
    
    if(node_ret == NULL && (tree_type & 0x02))    // dangle
    {
        node_ret = get_node_tree_op(&shell.scenario_dangle, self_id);
    }

    if(node_ret == NULL && (tree_type & 0x04))    // bg
    {
        node_ret = get_node_tree_op(&shell.scenario_bg, self_id);
    }

    return node_ret;
}

static void replace_node_sg_op(base_node_struct* node_old, mmi_frm_node_struct* node_new_info, MMI_BOOL b_group)
{
    base_node_struct* node_new = NULL;

    MMI_ASSERT(node_old != NULL && node_new_info != NULL);

    /* check in dangle */
    node_new = SG_GET_NODE_FROM_DANGLE(node_new_info->id);
    if (node_new != NULL)
    {
        if(b_group)
        {
            SG_REMOVE_NODE(&shell.scenario_dangle, node_new);
            insert_node_by_handle(node_old->parent,node_old,node_new,MMI_FRM_NODE_BEFORE_FLAG);
            SG_REMOVE_FREE_NODE(node_old->parent,node_old);
        }
    }
    else
    {
        node_old->id = node_new_info->id;
        if(!_IS_GROUP(node_old)) // add screen replace processing
        {
            node_old->id = _SCRN_ID(node_old->parent->id, node_new_info->id);
        }
        node_old->user_data = node_new_info->user_data;
        if (b_group)
        {
            node_old->proc = node_new_info->entry_proc;
        }
        else
        {
            ((scrn_node_struct*)(node_old))->entry_proc = (mmi_scrn_func)node_new_info->entry_proc;
        }
    }
}
/*
* free node itself memory
*
* group: free all the children
* scrn: free gui\input buffer
* tab: free tab and tab pages gui\input buffer
* 
*/
static void free_node_sg_op(base_node_struct* node_free, MMI_BOOL b_include_self)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (node_free == NULL)
        return;

	type = node_free->type;
    
    if (_IS_GROUP(node_free))
    {
        if (node_free->id >= GRP_ID_AUTO_GEN_BASE && 
            node_free->id < GRP_ID_AUTO_GEN_MAX)
        {
            /* the group id was auto-generated from framework */
            memmove(&g_frm_group_free_idx[1], &g_frm_group_free_idx[0], sizeof(U8)*(FRM_AUTO_GEN_GROUP_FREE_RECORD-1));
            g_frm_group_free_idx[0] = (node_free->id-GRP_ID_AUTO_GEN_BASE);
            ResetBit(
                g_frm_group_mask[g_frm_group_free_idx[0]/FRM_RESERVED_GROUP_MASK_UNIT], 
                g_frm_group_free_idx[0]%FRM_RESERVED_GROUP_MASK_UNIT);
        }
    }
    switch (node_free->type)
    {
    case SCENARIO_GROUP_NODE:   
        {
            base_node_struct* node_iterator = NULL;
            base_node_struct* node_next = NULL;
            group_node_struct* node_group = (group_node_struct*)node_free;

            if (b_include_self && node_group->app_name)
                mmi_mfree(node_group->app_name);

            /* free children */
            node_iterator = node_group->m_head;
            while (node_iterator)
            {
                node_next = node_iterator->m_next;
                free_node_sg_op(node_iterator,MMI_TRUE);
                node_iterator = node_next;
            }
            node_group->m_count = 0;
            node_group->m_head = node_group->m_tail = NULL;
            if(b_include_self)
                memset(node_group, 0, sizeof(group_node_struct));
        }
        break;

    case SCENARIO_SCRN_NODE:
	case SCENARIO_TAB_PAGE_NODE:
        scrn_free_history((scrn_node_struct*)(node_free));
        break;

    case SCENARIO_TAB_NODE:
        {
            base_node_struct* node_page_iterator = NULL;
            base_node_struct* node_page_next = NULL;            
            tab_node_struct* node_tab = (tab_node_struct*)(node_free);

            /* free pages */
            node_page_iterator = node_tab->m_head;
            while (node_page_iterator)
            {
                node_page_next = node_page_iterator->m_next;
                scrn_free_history((scrn_node_struct*)node_page_iterator);
                _MMI_MEM_FREE(node_page_iterator, node_page_iterator->type);
                node_page_iterator = node_page_next;
            }
            node_tab->m_count = 0;
            node_tab->m_head = node_tab->m_tail = NULL;
            
            if(b_include_self)
            {
                scrn_free_history((scrn_node_struct*)node_tab);
                memset(node_tab, 0, sizeof(tab_node_struct));
            }
        }
        break;
    default:
        MMI_ASSERT(0);
    }
    if(b_include_self)
        _MMI_MEM_FREE(node_free, type);
}

static void remove_free_node_sg_op(group_node_struct* node_parent, base_node_struct* node_free)
{
    remove_node_tree_op(node_parent,node_free);
    free_node_sg_op(node_free, MMI_TRUE);
}


#ifndef __MMI_NOT_TAB_SUPPORT__
static base_node_struct* move_node_to_tail(base_node_struct* parent, base_node_struct *node, U8 page_index, MMI_BOOL is_tab)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tab_node_struct         *tab = _TAB(parent);
    tab_page_node_struct    *tab_tail = _TAB_PAGE(tab->m_tail);
    tab_page_node_struct    *child = NULL;
    base_node_struct        *tmp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_tab)
    {
        child = tab_tail;
        if (child && child->index != page_index)
        {
            MMI_ASSERT(_IS_TAB_PAGE(child));
            tmp = child->m_prev;
            while (child && child->index != page_index)
            {
                child = _TAB_PAGE(child->m_prev);
            }
            if (child == NULL || child->index != page_index)
            {
                tab->cur_sel_index = tab_tail->index;
                return NULL;
            }

            /* if child is conjoint with tail node */
            if (child->m_next == _NODE(tab_tail))
            {
                if (child->m_prev)
                {
                    child->m_prev->m_next = _NODE(tab_tail);
                }
                tab_tail->m_prev = child->m_prev;
                tab_tail->m_next = _NODE(child);
                child->m_prev = _NODE(tab_tail);
                child->m_next = NULL;
            }
            else
            {
                /* child isn't conjoint with the tail node */
                if (child->m_next)
                {
                    child->m_next->m_prev = _NODE(tab_tail);
                }
                if (child->m_prev)
                {
                    child->m_prev->m_next = _NODE(tab_tail);
                }
                tab_tail->m_prev = child->m_prev;
                tab_tail->m_next = child->m_next;

                if (tmp)
                {
                    tmp->m_next = _NODE(child);
                }
                child->m_prev = tmp;
                child->m_next = NULL;
            }

            if (tab_tail->m_prev == NULL)
            {
                tab->m_head = _NODE(tab_tail);
            }
            tab->m_tail = _NODE(child);
            tab->cur_sel_index = page_index;
        }
    }
    return _NODE(child);
}
#endif /* __MMI_NOT_TAB_SUPPORT__ */

static base_node_struct* find_prev_node(base_node_struct* node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (node && node->parent != &shell.scenario_dangle)
    {
        return node->m_prev;
    }
    return NULL;
}


static base_node_struct* find_next_node(base_node_struct* node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (node && node->parent != &shell.scenario_dangle)
    {
        return node->m_next;
    }
    return NULL;
}


static MMI_BOOL is_in_tail_serial(group_node_struct *group, base_node_struct *node)
{
    base_node_struct *t;
    t = group->m_tail;
    while (t != NULL)
    {
        if (_NODE(node) == _NODE(t))
        {
            return MMI_TRUE;
        }
        if (_IS_GROUP(t))
        {
            t = _GROUP(t)->m_tail;
        }
        else
        {
            return MMI_FALSE;
        }
    }
    return MMI_FALSE;
}



static void update_status(U16 evt_id, base_node_struct *node, MMI_BOOL is_prev_app_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    U32 state = shell.state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt_id)
    {
        case EVT_ID_GROUP_ENTER:
            if (is_prev_app_evt == MMI_TRUE)
            {
                SetBit(shell.state, MMI_SCENARIO_STATE_FIRST_ENTRY_IDX);
                SetBit(node->state, MMI_SCENARIO_STATE_FIRST_ENTRY_IDX);
            }
            else
            {
                ResetBit(shell.state, MMI_SCENARIO_STATE_FIRST_ENTRY_IDX);
                ResetBit(node->state, MMI_SCENARIO_STATE_CREATE_IDX);
                ResetBit(node->state, MMI_SCENARIO_STATE_FIRST_ENTRY_IDX);
            }
            break;
            
        case EVT_ID_GROUP_ACTIVE:
            if (is_prev_app_evt == MMI_TRUE)
            {
                ResetBit(node->state, MMI_SCENARIO_STATE_UNHIDE_IDX);
                ResetBit(node->state, MMI_SCENARIO_STATE_INACTIVE_IDX);
                SetBit(node->state, MMI_SCENARIO_STATE_ACTIVE_IDX);

                
                SetBit(shell.state, MMI_SCENARIO_STATE_ACTIVE_IDX);
                ResetBit(shell.state, MMI_SCENARIO_STATE_INACTIVE_IDX);
                
                ResetBit(shell.state, MMI_SCENARIO_STATE_INACTIVE_IDX);
            }
            break;
            
        case EVT_ID_GROUP_INACTIVE:
            if (is_prev_app_evt == MMI_TRUE)
            {
                SetBit(shell.state, MMI_SCENARIO_STATE_INACTIVE_IDX);
                ResetBit(shell.state, MMI_SCENARIO_STATE_ACTIVE_IDX);
                SetBit(node->state, MMI_SCENARIO_STATE_INACTIVE_IDX);
                ResetBit(node->state, MMI_SCENARIO_STATE_ACTIVE_IDX);
            }
            break;
            
        case EVT_ID_GROUP_FOCUSED:
            if (is_prev_app_evt == MMI_FALSE)
            {
                SetBit(shell.state, MMI_SCENARIO_STATE_FOCUS_IDX);
                SetBit(node->state, MMI_SCENARIO_STATE_FOCUS_IDX);
            }
            break;
    
        case EVT_ID_GROUP_DEFOCUSED:
            if (is_prev_app_evt == MMI_FALSE)
            {
                ResetBit(shell.state, MMI_SCENARIO_STATE_FOCUS_IDX);
                ResetBit(node->state, MMI_SCENARIO_STATE_FOCUS_IDX);
            }
            break;
            
        case EVT_ID_GROUP_HIDE:
            if (is_prev_app_evt == MMI_TRUE)
            {
                
            }
            else
            {
                SetBit(node->state, MMI_SCENARIO_STATE_HIDE_IDX);
                ResetBit(node->state, MMI_SCENARIO_STATE_UNHIDE_IDX);
                ResetBit(node->state, MMI_SCENARIO_STATE_APP_DO_HIDE_IDX);
            }
            break;
            
        case EVT_ID_GROUP_UNHIDE:
            if (is_prev_app_evt == MMI_TRUE)
            {
            }
            else
            {
                ResetBit(node->state, MMI_SCENARIO_STATE_HIDE_IDX);
                SetBit(node->state, MMI_SCENARIO_STATE_UNHIDE_IDX);
                ResetBit(node->state, MMI_SCENARIO_STATE_APP_DO_UNHIDE_IDX);
            }
            break;
          
        case EVT_ID_GROUP_DELETE_REQ:
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
        case EVT_ID_DELETE_DANGLE_GROUP_REQ:
        case EVT_ID_SCRN_DELETE_REQ:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:

            if (is_prev_app_evt == MMI_TRUE)
            {
                //SetBit(shell.state, MMI_SCENARIO_STATE_DELETE_REQ_IDX);
                SetBit(node->state, MMI_SCENARIO_STATE_DELETE_REQ_IDX);
            }
            else
            {
                //ResetBit(shell.state, MMI_SCENARIO_STATE_DELETE_REQ_IDX);
                ResetBit(node->state, MMI_SCENARIO_STATE_DELETE_REQ_IDX);
            }
            break;
            
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
            {
                MMI_ASSERT(is_in_active_group_serial((MMI_ID)node->id));
            }
        case EVT_ID_SCRN_GOBACK:
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:

            if (is_prev_app_evt == MMI_TRUE)
            {
                SetBit(shell.state, MMI_SCENARIO_STATE_BACKWARD_IDX);
                SetBit(shell.state, MMI_SCENARIO_STATE_CLOSE_IND_IDX);
                SetBit(node->state, MMI_SCENARIO_STATE_CLOSE_IND_IDX);
                SetBit(node->state, MMI_SCENARIO_STATE_BACKWARD_IDX);
            }
            else
            {
                ResetBit(shell.state, MMI_SCENARIO_STATE_CLOSE_IND_IDX);
                ResetBit(node->state, MMI_SCENARIO_STATE_CLOSE_IND_IDX);
            }
            break;
            
        case EVT_ID_GROUP_DEINIT:
        case EVT_ID_SCRN_DEINIT:
            if (is_prev_app_evt == MMI_TRUE)
            {
                SetBit(shell.state, MMI_SCENARIO_STATE_DEINIT_IDX);
                SetBit(node->state, MMI_SCENARIO_STATE_DEINIT_IDX);
            }
            else
            {
                ResetBit(shell.state, MMI_SCENARIO_STATE_DEINIT_IDX);
                ResetBit(node->state, MMI_SCENARIO_STATE_DEINIT_IDX);
            }
            break;
            
        case EVT_ID_GROUP_EXIT:
            if (is_prev_app_evt == MMI_TRUE)
            {
                ResetBit(shell.state, MMI_SCENARIO_STATE_CLOSE_IND_IDX);
                ResetBit(shell.state, MMI_SCENARIO_STATE_DELETE_REQ_IDX);
                SetBit(shell.state, MMI_SCENARIO_STATE_EXIT_IDX);
                ResetBit(node->state, MMI_SCENARIO_STATE_CLOSE_IND_IDX);
                ResetBit(node->state, MMI_SCENARIO_STATE_DELETE_REQ_IDX);
                SetBit(node->state, MMI_SCENARIO_STATE_EXIT_IDX);
            }
            else
            {
                ResetBit(shell.state, MMI_SCENARIO_STATE_EXIT_IDX);
            }
            break;

        case EVT_ID_SCRN_ACTIVE:
            SetBit(shell.state, MMI_SCENARIO_STATE_ACTIVE_IDX);
            ResetBit(shell.state, MMI_SCENARIO_STATE_INACTIVE);
            break;
            
        case EVT_ID_SCRN_INACTIVE:
            SetBit(shell.state, MMI_SCENARIO_STATE_INACTIVE);
            ResetBit(shell.state, MMI_SCENARIO_STATE_ACTIVE_IDX);
            break;
        case EVT_ID_SCRN_HIDE:
            if (is_prev_app_evt == MMI_FALSE)
            {
                SetBit(node->state, MMI_SCENARIO_STATE_HIDE_IDX);
                ResetBit(node->state, MMI_SCENARIO_STATE_UNHIDE_IDX);
            }
            break;
            
        case EVT_ID_SCRN_UNHIDE:
            if (is_prev_app_evt == MMI_FALSE)
            {
                ResetBit(node->state, MMI_SCENARIO_STATE_HIDE_IDX);
                SetBit(node->state, MMI_SCENARIO_STATE_UNHIDE_IDX);
            }
            break;       
            
    }

}




static mmi_ret send_scenario_event(U16 evt_id, base_node_struct *node, mmi_scenario_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt->evt_id = evt_id;
    if (_IS_GROUP(node))
    {
        evt->targ_group = node->id;
        evt->targ_scrn  = SCR_ID_INVALID;
    }
    else
    {
        evt->targ_group = (node->parent) ? node->parent->id : GRP_ID_INVALID;
        evt->targ_scrn  = (MMI_ID)node->id;
    }
	evt->user_data = node->user_data;
    MMI_TRACE(MMI_FW_TRC_G1_FRM, 
        MMI_FRM_SCENARIO_EVT,
        evt->evt_id,
        evt->targ_group,
        evt->targ_scrn,
        shell.state,
        node->state,
        node->attrib);
	if (node->proc)
	{
		ret = node->proc((mmi_event_struct *)evt);
	}
    return ret;
}

static mmi_ret interaction(U16 evt_id, base_node_struct *node, mmi_scenario_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	update_status(evt_id, node, MMI_TRUE);
    ret = send_scenario_event(evt_id, node, evt);
    update_status(evt_id, node, MMI_FALSE);
	return ret;
}


static mmi_ret mmi_scenario_external_post_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_post_evt_struct             *post_evt = NULL;
    mmi_group_event_struct          *group_evt = NULL;
    mmi_post_result_event_struct    rst_evt = {0};
    scenario_err_enum   ret_log = SCENARIO_NORMAL;
    mmi_event_struct                *content_evt = NULL;

    group_node_struct   *sender;
    group_node_struct   *receiver;
    mmi_proc_func       receiver_proc = NULL;
    void*               receiver_user_data = NULL;
    mmi_ret             rst = MMI_RET_OK;   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_EXTERNAL_POST_PROC, evt->evt_id);
    switch (evt->evt_id)
    {
    case EVT_ID_APP_GROUP_POST_NOTIFY:
        post_evt = (mmi_post_evt_struct*)evt;
        group_evt = (mmi_group_event_struct*)post_evt->data;

        /* If the group is in shell.dangle, we don't need to do this post event */
        receiver = (group_node_struct*)SG_GET_NODE_FROM_ROOT(post_evt->receiver_gid);
        if (receiver)
        {
            receiver_proc = receiver->proc;
            receiver_user_data = receiver->user_data;
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_POST_EVENT_HANDLER, post_evt->sender_gid, (group_evt ? group_evt->evt_id : 0), (U16)receiver->id, receiver_proc, receiver_user_data, G_POST_EVENT_EX_API);

            if (receiver_proc)
            {
                rst = MMI_FRM_SEND_EVENT(group_evt, receiver_proc, receiver_user_data);
            }
        }

        /*
         * After receiver process the event, it may close the sender group.
         * If the sender group is closed, we don't send the result.
         */
        sender = (group_node_struct*)SG_GET_NODE_FROM_ROOT(post_evt->sender_gid);
        if (post_evt->need_result && sender)
        {
            /* Feedback to caller by result callback */
            rst_evt.evt_id = EVT_ID_POST_CB_RST;
            rst_evt.user_data = sender->user_data;
            rst_evt.result = rst;
            rst_evt.evt_p = (mmi_event_struct*)group_evt;
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_POST_EVENT_NOTIFY_BASE_HANDLER, rst, (U16)sender->id, sender->proc, G_POST_EVENT_NEED_RESULT_EX_API);
            sender->proc((mmi_event_struct*)&rst_evt);
        }
        break;

    case EVT_ID_GROUP_POST_CALLER_NOTIFY:
    case EVT_ID_GROUP_POST_PARENT_NOTIFY:
        post_evt = (mmi_post_evt_struct*)evt;
        group_evt = (mmi_group_event_struct*)post_evt->data;
        /* avoid build warning */
        ret_log = ret_log;

        /* If the group is in shell.dangle, we don't need to do this post event */
        sender = (group_node_struct*)SG_GET_NODE_FROM_ROOT(post_evt->sender_gid);
        receiver = (group_node_struct*)SG_GET_NODE_FROM_ROOT(post_evt->receiver_gid);
        if (receiver)
        {           
            receiver_proc = receiver->proc;
            receiver_user_data = receiver->user_data;
            if (evt->evt_id == EVT_ID_GROUP_POST_CALLER_NOTIFY)
                ret_log = G_POST_EVENT_CALLER_HANDLER;
            else if (evt->evt_id == EVT_ID_GROUP_POST_PARENT_NOTIFY)
                ret_log = G_POST_EVENT_PARENT_HANDLER;
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_POST_EVENT_HANDLER, post_evt->sender_gid, (group_evt ? group_evt->evt_id : 0), (U16)receiver->id, receiver_proc, receiver_user_data, ret_log);

            if (receiver_proc)
            {
                rst = MMI_FRM_SEND_EVENT(group_evt, receiver_proc, receiver_user_data);
            }
        }

        /*
         * After receiver process the event, it may close the sender group.
         * If the sender group is closed, we don't send the result.
         */
        sender = (group_node_struct*)SG_GET_NODE_FROM_ROOT(post_evt->sender_gid);
        if (post_evt->need_result && sender)
        {
            /* Feedback to caller by result callback */
            rst_evt.evt_id = EVT_ID_POST_CB_RST;
            rst_evt.user_data = sender->user_data;
            rst_evt.result = rst;
            rst_evt.evt_p = (mmi_event_struct*)group_evt;
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_POST_EVENT_NOTIFY_BASE_HANDLER, rst, (U16)sender->id, sender->proc, G_POST_EVENT_NEED_RESULT_HANDLER);
            
            sender->proc((mmi_event_struct*)&rst_evt);
        }
        break;

    case EVT_ID_SCRN_POST_PARENT_NOTIFY:
        post_evt = (mmi_post_evt_struct*)evt;
        content_evt = (mmi_event_struct*)post_evt->data;

        /* If the group is in shell.dangle, we don't need to do this post event */
        receiver = (group_node_struct*)SG_GET_NODE_FROM_ROOT(post_evt->receiver_gid);
        if (receiver && receiver->proc)
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_HANDLE_POST_PARENT_NOTIFY, (U16)receiver->id, receiver->proc, receiver->user_data);
            MMI_FRM_SEND_EVENT(content_evt, receiver->proc, receiver->user_data);
        }
        break;

#ifndef __MMI_NOT_TAB_SUPPORT__
    case EVT_ID_TAB_POST_LEFT_ARROW_NOTIFY:
        tab_l_arrow_key_action();
        break;
        
    case EVT_ID_TAB_POST_RIGHT_ARROW_NOTIFY:
        tab_r_arrow_key_action();
        break;
#endif /* __MMI_NOT_TAB_SUPPORT__ */

    case EVT_ID_GOBACK_HISTORY:
        mmi_frm_scrn_close_active_id();
        break;
    
    case EVT_ID_ROOT_SCRN_FIRST_ENTER:
    case EVT_ID_ROOT_SCRN_COMM_ENTER:
        return process_root_screen_enter(evt);
    

    case EVT_ID_POST_TO_GROUP:
        post_evt = (mmi_post_evt_struct*)evt;
        group_evt = (mmi_group_event_struct*)post_evt->data;
        receiver= (group_node_struct *)SG_GET_NODE_FROM_ALL(post_evt->receiver_gid);
        if (receiver && receiver->proc)
        {   
            MMI_FRM_SEND_EVENT(group_evt, receiver->proc, receiver->user_data);
        }
        break;
        
    default:
        break;
    }

    return MMI_RET_OK;
}


static void post_scenario_evt(MMI_ID group_id, U32 scrn_id, post_scenario_act_enum act, mmi_scenario_evt_struct *evt, U32 type, MMI_BOOL is_front)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_post_scenario_evt_struct *post_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(PLUTO_FW_TRC_SCREEN, MMI_FRM_SCENARIO_POST_EVT_INTERNAL, act, group_id, (U16)scrn_id);

    /* We maintain scenario internal post event queue to process these acts. */
    post_evt = (mmi_post_scenario_evt_struct *)_MMI_MEM_ALLOC(sizeof(mmi_post_scenario_evt_struct), SCENARIO_POST_EVT);
    post_evt->group_id = group_id;
    post_evt->scrn_id = scrn_id;
    post_evt->act = act;
    if (evt)
    {
        memcpy(post_evt, evt, sizeof(mmi_scenario_evt_struct));
    }
    MMI_ASSERT(act < POST_EXECUTE_MAX);
    switch (act)
    {
    case POST_EXECUTE_ACTIVE:
    case POST_EXECUTE_GROUP_ACTIVE:
    case POST_EXECUTE_SCRN_ACTIVE:
        SetBit(post_evt->scenario_evt.state, MMI_SCENARIO_STATE_ACTIVE_IDX);
        break;
    case POST_EXECUTE_INACTIVE:
    case POST_EXECUTE_GROUP_INACTIVE:
        SetBit(post_evt->scenario_evt.state, MMI_SCENARIO_STATE_INACTIVE_IDX);
        break;
    case POST_EXECUTE_DEINIT:
        SetBit(post_evt->scenario_evt.state, MMI_SCENARIO_STATE_DEINIT_IDX);
        break;
    case POST_EXECUTE_GROUP_EXIT:
        SetBit(post_evt->scenario_evt.state, MMI_SCENARIO_STATE_EXIT_IDX);
        break;
    default:      
		 break;
    }
    /*
     * Tricky: use high byte of scenario_evt.state to keep 'SCENARIO_POST_EVT' type info. 
     * We use this byte to check the memory type in mmi_frm_mfree_dbg().
     */
    post_evt->scenario_evt.state |= SCENARIO_POST_EVT << 24;
    post_queue_idx++;
	MMI_ASSERT(post_queue_idx != SCENARIO_POST_QUEUE_SIZE);
	if (is_front == MMI_FALSE)
	{		
        post_queue[post_queue_idx].evt = post_evt;
        post_queue[post_queue_idx].flag = type;
	}
	else
	{
		S32 i;
		if (post_queue_idx > 0)
		{
			for (i = post_queue_idx -1; i >= 0; i--)
			{
				post_queue[i+1] = post_queue[i];
			}
		}
		post_queue[0].evt = post_evt;
		post_queue[0].flag = type;
	}
}

mmi_post_scenario_evt_struct *fetch_post_event_process(U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_post_scenario_evt_struct *post_evt = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i <= post_queue_idx; i++)
    {
        if (post_queue[i].flag == type)
        {
            post_evt = post_queue[i].evt;

            if (post_queue_idx >= 0)
            {
                memmove(&post_queue[i], &post_queue[i+1], sizeof(post_queue_struct)*(post_queue_idx-i));
            }
            memset(&post_queue[post_queue_idx], 0, sizeof(post_queue_struct));
            post_queue_idx--;
            return post_evt;
        }
    }
    return post_evt;
}


static void scenario_process_post_evt_ex(U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_post_scenario_evt_struct *post_evt;
    base_node_struct *node = NULL;
    
    U32 tmp;
    U32 queue_type = SCENARIO_POST_TYPE_INTERNAL;
	U32 process_state = 0; /* 0 - process internal post event; 1 - process app post event; 2 - change shell state done */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(PLUTO_FW_TRC_SCREEN, MMI_FRM_SCENARIO_PROCESS_POST_EVT, type);
    /* fetch post event (start) */
    post_evt = fetch_post_event_process(queue_type);
    if (post_evt == NULL && queue_type < type)
    {
        queue_type++;
        post_evt = fetch_post_event_process(queue_type);
        queue_type = SCENARIO_POST_TYPE_INTERNAL;
		process_state = 1;
    }
	else
	{
		process_state = 0; 
	}
    /* fetch post event (end) */
    while (post_evt)
    {
        /* Tricky: retrive scenario_evt.state info. */
        tmp = post_evt->scenario_evt.state;
        post_evt->scenario_evt.state &= 0x00FFFFFF;
        post_evt->scenario_evt.targ_group  = post_evt->group_id;
        post_evt->scenario_evt.targ_scrn   = post_evt->scrn_id;

		if (process_state == 1)
		{
			/* After processing internal post event, shell state should change to normal */
			shell.state = MMI_SCENARIO_STATE_NONE;
		}
#ifdef __MMI_FRM_HISTORY__
        if (post_evt->act == POST_EXECUTE_GOBACK_ORG_HIST)
        {
            U16 scrn_id;
            /*
             * close group and goback to original screen-history mechanism. 
             * We need to fetch post event first because when we invoke
             * mmi_go_back_to_history() may trigger another scrn_group_adaptor screen
             * that calls scenario_process_post_evt_ex again.
             */
            MMI_TRACE(PLUTO_FW_TRC_SCREEN, MMI_FRM_SCENARIO_PROCESS_POST_EVT_HANDLING, post_evt->act, post_evt->group_id, (U16)post_evt->scrn_id, node);
            post_evt->scenario_evt.state = tmp;
            scrn_id = post_evt->group_id;
            _MMI_MEM_FREE(post_evt, SCENARIO_POST_EVT);

            shell.in_external_goback_process = 1;
            /* close the group from scenario mechanism, we do nothing in delete screen callback. */
            ClearDelScrnIDCallbackHandler(scrn_id, scrn_group_adaptor_delete_cb);
            if (IsScreenPresent(scrn_id) || is_top_history_node(scrn_id))
            {
                mmi_go_back_to_history();
            }
            else
            {
                mmi_delete_scrn_if_present(scrn_id);
            }
			shell.in_external_goback_process = 0;

            /* fetch post event (start) */
            post_evt = fetch_post_event_process(queue_type);
            if (post_evt == NULL && queue_type < type)
            {
                queue_type++;
                post_evt = fetch_post_event_process(queue_type);
                process_state = 1;
                queue_type = SCENARIO_POST_TYPE_INTERNAL;
            }
			else
			{
				process_state = 0;
			}
        }
        else
#endif /* __MMI_FRM_HISTORY__ */
        {
            if (post_evt->act == POST_EXECUTE_CLOSE_TO_ROOT_GROUP)
			{
				MMI_ASSERT(shell.state == MMI_SCENARIO_STATE_NONE);
				mmi_frm_close_to_root_screen(post_evt->group_id);
			}
			else if (post_evt->act == POST_EXECUTE_CLOSE_TO_IDLE_GROUP)
            {
                MMI_ASSERT(shell.state == MMI_SCENARIO_STATE_NONE);
                mmi_frm_close_to_idle_group();
            }
			else if (post_evt->act == POST_EXECUTE_DISPLAY_DESKTOP)
			{
				MMI_ASSERT(shell.state == MMI_SCENARIO_STATE_NONE);
				mmi_frm_display_desktop();
			}
            else if (post_evt->act == POST_EXECUTE_CLOSE_ALL_BG_GROUPS)
            {
                MMI_ASSERT(shell.state == MMI_SCENARIO_STATE_NONE);
                mmi_frm_close_all_background_groups();
            }
            else if (post_evt->act == POST_EXECUTE_INSERT)
            {
                insert_op_info_struct* insert_info_p = (insert_op_info_struct*)(post_evt->scenario_evt.user_data);
                if(insert_info_p) // node insert
                {
                    mmi_frm_node_insert(insert_info_p->parent_id, insert_info_p->base_id, 
                        &insert_info_p->new_node_info, insert_info_p->flag, insert_info_p->is_group_node);
                }
                mmi_mfree(insert_info_p);
            }
            else if (post_evt->act == POST_EXECUTE_DEINIT)
            {
                if (post_evt->scrn_id == SCR_ID_INVALID)
                {
                    node = SG_GET_NODE_FROM_DANGLE(post_evt->group_id);
                }
                else
                {
                    node = SG_GET_NODE_FROM_DANGLE(post_evt->scrn_id);
                }
            }
            else
            {
                if (post_evt->scrn_id == SCR_ID_INVALID)
                {
                    node = SG_GET_NODE_FROM_ALL(post_evt->group_id);
                }
                else
                {
                    /* parent */
                    node = SG_GET_NODE_FROM_ALL(post_evt->group_id);

                    node = SG_GET_CHILD((group_node_struct*)node, post_evt->scrn_id);
                }
            }
            MMI_TRACE(PLUTO_FW_TRC_SCREEN, MMI_FRM_SCENARIO_PROCESS_POST_EVT_HANDLING, post_evt->act, post_evt->group_id, (U16)post_evt->scrn_id, node);
            if (node)
            {
                switch(post_evt->act)
                {
                case POST_EXECUTE_DEINIT:
                    {
                        /* the node maybe in shell.scenario_dangle, we don't need to check node vaule */
                        execute_node_post_deinit(node, &(post_evt->scenario_evt));
                    }
                    break;
                case POST_EXECUTE_GROUP_FOCUS:
                    group_focus_change(_GROUP(node), &(post_evt->scenario_evt), MMI_TRUE);
                    break;

#ifdef __MMI_FRM_HISTORY__
                case POST_EXECUTE_DEL_HIST:
                    mmi_delete_scrn_if_present((MMI_ID)node->id);
                    break;
#endif /* __MMI_FRM_HISTORY__ */

                case POST_EXECUTE_ACTIVE:
					if (node->type == SCENARIO_SCRN_NODE)
					{
						if (is_in_active_group_serial((MMI_ID)node->parent->id) == NULL)
						{
							SetBit(node->state, MMI_SCENARIO_STATE_INACTIVE_IDX);
							break;
						}
					}                    
					if ((_IS_SCRN(node) || _IS_TAB(node)) &&
                        shell.active_scrn && 
                        shell.active_scrn->parent != node->parent)
                    {
                        /*
                         *                 (G-id3*) - (S3*)
                         *                 (S1)
                         * ROOT - (G-id) - (S0)
                         * If close S1 and S1 display popup in G-id in leave_proc,
                         * we need to inactive G-id3 first.
                         * ref. screen_group_test_case13
                         */
                        if (node->m_prev)
                        {
                            _EXECUTE_NODE_INACTIVE(node->m_prev, &(post_evt->scenario_evt));
                            scenario_process_post_evt_ex(SCENARIO_POST_TYPE_INTERNAL);
                        }
                        shell.active_group = node->parent;
                        group_focus_change(shell.active_group, &(post_evt->scenario_evt), MMI_TRUE);
                    }
                    _EXECUTE_NODE_ACTIVE(node, &(post_evt->scenario_evt));
                    break;
                case POST_EXECUTE_INACTIVE:
                    _EXECUTE_NODE_INACTIVE(node, &(post_evt->scenario_evt));
                    break;
                case POST_EXECUTE_CLOSE:
                    if (node && (node == _NODE(shell.active_group) || node == _NODE(shell.active_scrn) || mmi_frm_group_is_in_active_serial((MMI_ID)(node->id))))
                    {
                        SetBit(shell.state, MMI_SCENARIO_STATE_BACKWARD_IDX);
                        SetBit(node->attrib, NODE_ATTRIB_CLOSED_TARGET_IDX);
                        /* May need to consider group node & tab node case */
                    }
                    else if (node && IsBitSet(node->state, MMI_SCENARIO_STATE_INACTIVE_IDX))
                    {
                        SetBit(shell.state, MMI_SCENARIO_STATE_DELETE_REQ_IDX);
                    }
					if (node->type == SCENARIO_GROUP_NODE)
					{
						
						if (is_in_active_group_serial(node->id))
						{
							/* the active group was closed and it invokes the goback process */
							SetBit(post_evt->scenario_evt.state, MMI_SCENARIO_STATE_BACKWARD_IDX);
							post_evt->scenario_evt.targ_group  = node->id;
							post_evt->scenario_evt.targ_scrn   = SCR_ID_INVALID;
							post_evt->scenario_evt.curr_group  = node->id;
							post_evt->scenario_evt.curr_scrn   = shell.active_scrn ? shell.active_scrn->id : SCR_ID_INVALID;
						}
						else
						{
							/* the inactive group was closed and it invokes the deinit process */
							SetBit(post_evt->scenario_evt.state, MMI_SCENARIO_STATE_DELETE_REQ_IDX);
							post_evt->scenario_evt.targ_group  = node->id;
							post_evt->scenario_evt.targ_scrn   = SCR_ID_INVALID;
							post_evt->scenario_evt.curr_group  = GRP_ID_INVALID;
							post_evt->scenario_evt.curr_scrn   = SCR_ID_INVALID;
						}

						post_evt->scenario_evt.evt_id      = EVT_ID_SCENARIO_CHANGE;
						post_evt->scenario_evt.user_data   = node->user_data;
						post_evt->scenario_evt.new_group   = GRP_ID_INVALID;
						post_evt->scenario_evt.new_scrn    = SCR_ID_INVALID;
					}
					SetBit(node->attrib, NODE_ATTRIB_CLOSED_TARGET_IDX);
                    _EXECUTE_NODE_CLOSE(node, &(post_evt->scenario_evt));                   
                    break;
                case POST_EXECUTE_HIDE:
					{
                        _EXECUTE_NODE_HIDE(node, &(post_evt->scenario_evt));
					}
                    break;
                case POST_EXECUTE_UNHIDE:
                    {
                        _EXECUTE_NODE_UNHIDE(node, &(post_evt->scenario_evt));
                    }
                    break;
				case POST_EXECUTE_GROUP_MOVE:
					group_move(_GROUP(node), &(post_evt->scenario_evt));
					break;
                case POST_EXECUTE_GROUP_HIDE:
                    group_post_hide(_GROUP(node), &(post_evt->scenario_evt));
                    break;
                case POST_EXECUTE_GROUP_UNHIDE:
                    //group_post_unhide(_GROUP(node), &(post_evt->scenario_evt));
                    break;
                case POST_EXECUTE_GROUP_ACTIVE:
                    group_post_active(_GROUP(node), &(post_evt->scenario_evt));
                    break;

                case POST_EXECUTE_SCRN_ACTIVE:
                    scrn_post_active(_SCRN(node), &(post_evt->scenario_evt));
                    break;

                case POST_EXECUTE_GROUP_INACTIVE:
                    group_post_inactive(_GROUP(node), &(post_evt->scenario_evt));
                    break;

                case POST_EXECUTE_GROUP_EXIT:
                    group_post_exit(_GROUP(node), &(post_evt->scenario_evt));
                    break;

                case POST_EXECUTE_SCRN_FIRST_ENTRY:
                    /* invoke screen entry directly */
                    if (IsBitReset(node->state, MMI_SCENARIO_STATE_ACTIVE_IDX))
                    {
						shell.state = MMI_SCENARIO_STATE_NONE;
						SetBit(node->state, MMI_SCENARIO_STATE_FIRST_ENTRY_IDX);
                     
                        node_exec_entry_proc((scrn_node_struct*)node);
                        
                        ResetBit(node->state, MMI_SCENARIO_STATE_FIRST_ENTRY_IDX);
                    }

                    break;
                case POST_EXECUTE_SCRN_DUMMY_CLEANUP:
                    if (IsBitReset(node->state, MMI_SCENARIO_STATE_ACTIVE_IDX))
                    {
                        if (_SCRN(node)->parent)
                        {
                            SG_REMOVE_FREE_NODE(_SCRN(node)->parent,node);
                        }
                    }
                    break;

				case POST_EXECUTE_NO_CHILD:
				{
					mmi_scenario_evt_struct evt = {0};
					MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_CLOSE, node->id, G_CLOSE_NOTIFY_PARENT_NO_CHILD);
					evt.curr_group = node->id;
					evt.targ_group = node->id;
					interaction(EVT_ID_NO_CHILD_NOTIFY, (base_node_struct*)node, &evt);
					break;
				}
                default:
                    MMI_ASSERT(0);
                }
            }
            post_evt->scenario_evt.state = tmp;
            _MMI_MEM_FREE(post_evt, SCENARIO_POST_EVT);

            /* fetch post event (start) */
            post_evt = fetch_post_event_process(queue_type);
            if (post_evt == NULL && queue_type < type)
            {
                queue_type++;
                post_evt = fetch_post_event_process(queue_type);
				process_state = 1;
                queue_type = SCENARIO_POST_TYPE_INTERNAL;
            }
			else
			{
				process_state = 0;
			}
            /* fetch post event (end) */
            node = NULL;
        }

    };
    #ifndef __MMI_FRM_HISTORY__
    if(SCENARIO_POST_TYPE_APP == type)
    #endif
        shell.state = MMI_SCENARIO_STATE_NONE;
    MMI_TRACE(PLUTO_FW_TRC_SCREEN, MMI_FRM_SCENARIO_PROCESS_POST_EVT_END, type);
}


static void execute_node_init(base_node_struct *node, mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (_IS_GROUP(node))
    {
        mmi_scenario_evt_struct *evt = (mmi_scenario_evt_struct*)param;
        U32 tmp = evt->state;

        if (IsBitSet(tmp, MMI_SCENARIO_STATE_FIRST_ENTRY_IDX))
        {
            mmi_frm_asm_scenario_hook(HOOK_EVT_BEFORE_ENTER, (base_node_struct *)node);
            interaction(EVT_ID_GROUP_ENTER, _NODE(node), evt);
            evt->state = tmp;
        }
    }
    else
    {
        MMI_ASSERT(0);
    }
}


static void execute_node_inactive(base_node_struct *node, mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scenario_evt_struct *evt = (mmi_scenario_evt_struct*)param;
    U32 tmp = evt->state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ResetBit(evt->state, MMI_SCENARIO_STATE_ACTIVE_IDX);
    SetBit(evt->state, MMI_SCENARIO_STATE_INACTIVE_IDX);
    EXECUTE_NODE_PROCESS(inactive);
    evt->state = tmp;
}


static void execute_node_active(base_node_struct *node, mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scenario_evt_struct *evt = (mmi_scenario_evt_struct*)param;
    U32 tmp = evt->state;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ResetBit(evt->state, MMI_SCENARIO_STATE_INACTIVE_IDX);
    SetBit(evt->state, MMI_SCENARIO_STATE_ACTIVE_IDX);
    EXECUTE_NODE_PROCESS(active);
    evt->state = tmp;
}

static void execute_node_hide(base_node_struct *node, mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scenario_evt_struct *evt = (mmi_scenario_evt_struct*)param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ResetBit(evt->state, MMI_SCENARIO_STATE_UNHIDE_IDX);
    SetBit(evt->state, MMI_SCENARIO_STATE_HIDE_IDX);
    EXECUTE_NODE_PROCESS(hide);
}

static void execute_node_unhide(base_node_struct *node, mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scenario_evt_struct *evt = (mmi_scenario_evt_struct*)param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ResetBit(evt->state, MMI_SCENARIO_STATE_HIDE_IDX);
    SetBit(evt->state, MMI_SCENARIO_STATE_UNHIDE_IDX);
    EXECUTE_NODE_PROCESS(unhide);
}


static  scrn_node_struct *find_prev_screen_node(base_node_struct*node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (node == NULL)
    {
        return NULL;
    }

    if (node->parent == &shell.scenario_root)
    {
        return NULL;
    }
    if (node->m_prev)
    {
        if (_IS_SCRN(node->m_prev))
        {
            return (scrn_node_struct *)node->m_prev;
        }
        else if(_IS_GROUP(node->m_prev))
        {
            scrn_node_struct *node_p; 
            node_p = (scrn_node_struct *)find_latest_descendant_scrn(SCR_ID_INVALID, (group_node_struct *)node->m_prev);
            return (node_p != NULL)? node_p: find_prev_screen_node(node->m_prev); 
        }
    }
    return find_prev_screen_node((base_node_struct *)node->parent);
}

static U32 get_prev_scrn_id(base_node_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    scrn_node_struct *node_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node_p = find_prev_screen_node(node);
    if (node_p != NULL)
    {
        return node_p->id;
    }
    return GRP_ID_ROOT;
}


static mmi_ret execute_node_close(base_node_struct *node, mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret result = MMI_RET_OK;
    mmi_scenario_evt_struct *evt = (mmi_scenario_evt_struct*)param;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EXECUTE_NODE_PROCESS_EX(close);
    return result;
}


static void execute_node_deinit(base_node_struct *node, mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    post_scenario_act_enum act;
    /* execute the deinit process in mmi_frm_scrn_close() */
    act = POST_EXECUTE_DEINIT;
            
    if (_IS_GROUP(node))
    {
    }
    else
    {
         _POST_INTERNAL_SCENARIO_EVT(node->parent->id, node->id, act, evt);
    }
    SG_REMOVE_NODE(node->parent, node);
    SG_ADD_NODE(&shell.scenario_dangle, node);

}


static void execute_node_post_deinit(base_node_struct *node, mmi_scenario_evt_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 evt_id = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (node == NULL)
    {
        return;
    }

    if (_IS_GROUP(node))
    {        
        mmi_frm_asm_scenario_hook(HOOK_EVT_AFTER_DEINIT, (base_node_struct *)node);
        
        /*
         * 1. If the node has MMI_SCENARIO_STATE_CREATE_IDX, this group node is in create state, didn't enter the group, yet.
         * 2. the application may delete the same group node in EVT_ID_GROUP_DEINIT, and we need to check the node again. 
         */
#ifdef __MMI_FRM_HISTORY__
        if (IsBitReset(node->state, MMI_SCENARIO_STATE_CREATE_IDX) && IsBitSet(node->attrib, NODE_ATTRIB_CLOSE_TO_EXTERNAL_IDX))
        {
            if (IsBitSet(shell.state, MMI_SCENARIO_STATE_BACKWARD_IDX))
            {
                /* close the group from scenario mechanism, we do nothing in delete screen callback. */
                if (IsScreenPresent(node->id) || is_top_history_node(node->id))
                {
                    ClearDelScrnIDCallbackHandler(node->id, scrn_group_adaptor_delete_cb);
                    //_POST_INTERNAL_SCENARIO_EVT(GRP_ID_INVALID, SCR_ID_INVALID, POST_EXECUTE_GOBACK_ORG_HIST, NULL);
                    if (GetIdleScrnId() != node->id)
                    {
                        _POST_INTERNAL_SCENARIO_EVT(node->id, SCR_ID_INVALID, POST_EXECUTE_GOBACK_ORG_HIST, NULL);
                    }
                    else
                    {
                        DinitHistory();
                        Deinit_active_screen_info();
                    }
                }
            }
            else
            {
                mmi_delete_scrn_if_present(node->id);
            }
        }
#endif /* __MMI_FRM_HISTORY__ */
        evt_id = EVT_ID_GROUP_DEINIT;
    }
    else if (_IS_SCRN(node) || _IS_TAB(node))
    {
        evt_id = EVT_ID_SCRN_DEINIT;
        if (_IS_SCRN(node))
        {
            MMI_ID group_id;
            MMI_ID scrn_id;
            get_scrn_layer_id(&group_id, &scrn_id);
            if (group_id == (MMI_ID)node->parent->id && scrn_id == (MMI_ID)node->id)
            {
                clear_scrn_layer_key_proc();
            }
        }        
    } /* _IS_GROUP(node) */

    interaction(evt_id, _NODE(node), evt);
	if (IsBitSet(node->attrib, NODE_ATTRIB_CLOSED_TARGET_IDX) && _GROUP(node->parent)->m_count == 0)
	{
		_POST_INTERNAL_SCENARIO_EVT(node->parent->id, 0, POST_EXECUTE_NO_CHILD, NULL);
	}
    SG_REMOVE_FREE_NODE(&shell.scenario_dangle, node);
}
void insert_node_by_handle(group_node_struct* node_parent,base_node_struct* node_base,base_node_struct* new_node,mmi_scenario_node_flag flag)
{
    MMI_ASSERT(node_parent != NULL && new_node != NULL);
    /* adjust base node for depending on base node in the following process */
    if (MMI_FRM_NODE_AT_LATEST_FLAG == flag)
        node_base = node_parent->m_tail;
    if (MMI_FRM_NODE_AT_BEGINNING_FLAG == flag)
        node_base = node_parent->m_head;
    if (node_base == NULL && node_parent->m_count == 0) /* the parent no child */
    {
        node_parent->m_head = new_node;
        node_parent->m_tail = new_node;
    }
    switch(flag)
    {
        /* insert the new node before the base node */
        case MMI_FRM_NODE_BEFORE_FLAG:
        case MMI_FRM_NODE_AT_BEGINNING_FLAG:
        {
            base_node_struct* base_node_pre = node_base != NULL ? node_base->m_prev : NULL;
            new_node->m_prev = base_node_pre;
            new_node->m_next = node_base;
            if(node_base)
                node_base->m_prev = new_node;
            if(base_node_pre)
                base_node_pre->m_next = new_node;
            else if(node_base == node_parent->m_head)
                node_parent->m_head = new_node;
            node_parent->m_count++;
            SetBit(new_node->state, MMI_SCENARIO_STATE_INACTIVE_IDX);
        }
        break;
        case MMI_FRM_NODE_AFTER_FLAG:
        case MMI_FRM_NODE_AT_LATEST_FLAG:
        {
            base_node_struct* base_node_after = node_base != NULL ? node_base->m_next : NULL;
            new_node->m_prev = node_base;
            new_node->m_next = base_node_after;
            if(node_base != NULL)
                node_base->m_next = new_node;
            node_parent->m_count++;
            if (base_node_after)
                base_node_after->m_prev = new_node;
            else if(node_base == node_parent->m_tail || node_base == NULL)
                node_parent->m_tail = new_node;
        }
        break;
        default:
            MMI_ASSERT(0);
    }
    new_node->parent = node_parent;
    if(IsBitSet(node_parent->state, MMI_SCENARIO_STATE_INACTIVE_IDX)) // set node state
        SetBit(new_node->state, MMI_SCENARIO_STATE_INACTIVE_IDX);
}
mmi_ret mmi_frm_node_insert (MMI_ID parent_id, MMI_ID base_id, mmi_frm_node_struct *new_node_info, mmi_scenario_node_flag flag, U8 is_group_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    base_node_struct *new_node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    group_node_struct*  node_parent;
    base_node_struct*   node_base;
    #ifdef __MMI_FRM_HISTORY__
    MMI_BOOL            b_need_notify_history = MMI_TRUE;
    #endif

    /* step1: check parent node */
    node_parent = (group_node_struct*)SG_GET_NODE_FROM_ALL(parent_id);
    if(node_parent == NULL)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_NODE_INSERT, NODE_INSERT_NO_PARENT);
        return MMI_RET_ERR;
    }
    
    /* step2: check base node */
    node_base = SG_GET_CHILD(node_parent, base_id);
    if (node_base == NULL)
    {
        node_base = SG_GET_CHILD(node_parent, _SCRN_ID(parent_id, base_id));
    }
    if (node_base == NULL && flag != MMI_FRM_NODE_AT_BEGINNING_FLAG && flag != MMI_FRM_NODE_AT_LATEST_FLAG)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_NODE_INSERT, NODE_INSERT_PARA_ERROR);
        return MMI_RET_ERR;
    }
	if (is_group_node == MMI_TRUE)
	{
		/* step3: check new node */
		new_node = SG_GET_NODE_FROM_ROOT(new_node_info->id);
	}
	else
	{
		new_node = SG_GET_NODE_FROM_ROOT(_SCRN_ID(parent_id, new_node_info->id));
	}
    if(new_node != NULL)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_NODE_INSERT, NODE_INSERT_NEW_NODE_EXIST);
        return MMI_RET_ERR;
    }
    new_node = SG_GET_NODE_FROM_DANGLE(new_node_info->id);
    if (new_node == NULL)
    {
        if (is_group_node)
        {
            MMI_BOOL is_exist;
            new_node = (base_node_struct*)create_new_group(node_parent, new_node_info->id, new_node_info->entry_proc, new_node_info->user_data, &is_exist);
            SG_ADD_NODE(&shell.scenario_dangle, new_node);
        }
        else
        {
            new_node = _NODE(create_new_scrn(parent_id, new_node_info->id, (mmi_scrn_func)new_node_info->entry_proc, new_node_info->user_data));
        }
    }
    
    /* step4: imp insert operation */
    SG_REMOVE_NODE(&shell.scenario_dangle, new_node);
    insert_node_by_handle(node_parent,node_base,new_node,flag);
   
    if ((new_node == node_parent->m_tail) && 
        (IsBitSet(node_parent->state, MMI_SCENARIO_STATE_ACTIVE_IDX) || node_parent == &shell.scenario_root))
    {
        mmi_scenario_evt_struct evt = {0};
        SetBit(evt.state, MMI_SCENARIO_STATE_FORWARD_IDX);
        _EXECUTE_NODE_ACTIVE(node_parent->m_tail, &evt);
        #ifdef __MMI_FRM_HISTORY__
        b_need_notify_history = MMI_FALSE;
        #endif
    }
    ResetBit(new_node->state, MMI_SCENARIO_STATE_CREATE_IDX);
    /* notify history */
    #ifdef __MMI_FRM_HISTORY__
        if(parent_id == GRP_ID_ROOT && b_need_notify_history)
        {
            historyNode *p = NULL;
            mmi_frm_screen_struct scrn_group_adaptor_node;
            mmi_frm_init_screen_struct(&scrn_group_adaptor_node);
            scrn_group_adaptor_node.scrnID = new_node->id;
            scrn_group_adaptor_node.entryFuncPtr = (entry_func_ptr)scrn_group_adaptor_entry;
            scrn_group_adaptor_node.app_arg = new_node;

            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_NODE_INSERT, NODE_INSERT_NOTIFY_HISTORY_BEG);
            
            if (MMI_FRM_NODE_AT_LATEST_FLAG == flag)
                node_base = node_parent->m_tail;
            if (MMI_FRM_NODE_AT_BEGINNING_FLAG == flag)
                node_base = node_parent->m_head;

            base_id = node_base->id;
            
            if(flag == MMI_FRM_NODE_BEFORE_FLAG || flag == MMI_FRM_NODE_AT_BEGINNING_FLAG)
            {
                /* because history not support insert a screen before active screen */
				MMI_ID active_history_node_id;
				if (shell.active_group)
				{
					active_history_node_id = mmi_frm_get_root_app(shell.active_group->id);
				}
				else
				{
					active_history_node_id = GetActiveScreenId();
				}
                if(base_id ==  active_history_node_id)
                    mmi_frm_insert_screen(MMI_HIST_TOP_SCREEN, &scrn_group_adaptor_node, MMI_FRM_INSERT_AFTER_SCRN);
                else
                    mmi_frm_insert_screen((U16)base_id, &scrn_group_adaptor_node, MMI_FRM_INSERT_BEFORE_SCRN);
            }
            if(flag == MMI_FRM_NODE_AFTER_FLAG || flag == MMI_FRM_NODE_AT_LATEST_FLAG)
                mmi_frm_insert_screen((U16)base_id, &scrn_group_adaptor_node, MMI_FRM_INSERT_AFTER_SCRN);
            
            GetHistoryPointer(new_node->id, &p);
			MMI_ASSERT(p != NULL);
            p->isGroupNode = 1;
            SetDelScrnIDCallbackHandler((U16)new_node->id, scrn_group_adaptor_delete_cb);
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_NODE_INSERT, NODE_INSERT_NOTIFY_HISTORY_END);
        }
    #endif
    scenario_process_post_evt_ex(SCENARIO_POST_TYPE_APP);
    return MMI_RET_OK;
}


void *mmi_frm_get_user_data (MMI_ID group_id, MMI_ID id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    base_node_struct *node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (id == SCR_ID_INVALID)
    {
        /* Find the group node in scenario tree and shell.scenario_dangle */
        node = SG_GET_NODE_FROM_ALL(group_id);
    }
    else
    {
        /* Find the screen node in scenario tree */
        node = SG_GET_NODE_FROM_ALL(_SCRN_ID(group_id, id));
    }

    if (node)
    {
        return node->user_data;
    }

    return NULL;
}


void mmi_frm_node_info_init (mmi_frm_node_struct *node_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(node_info, 0, sizeof(mmi_frm_node_struct));
}


/***************************************************************************** 
*  Scenario Group
*****************************************************************************/
static MMI_ID auto_gen_group_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Try to generate the group id averagely to avoid generate the same group ID in the short time */
    for (i = g_frm_group_last_idx; i < FRM_RESERVED_GROUP_NUMBER; i++)
    {
        for (j = 0; j < FRM_AUTO_GEN_GROUP_FREE_RECORD; j++)
        {
            if (i == g_frm_group_free_idx[j])
            {
                /* skip the latest free idx first */
                continue;
            }
        }
        if (IsBitReset(g_frm_group_mask[i/FRM_RESERVED_GROUP_MASK_UNIT], i%FRM_RESERVED_GROUP_MASK_UNIT))
        {
            g_frm_group_last_idx = i + 1;
            SetBit(g_frm_group_mask[i/FRM_RESERVED_GROUP_MASK_UNIT], i%FRM_RESERVED_GROUP_MASK_UNIT);
            return (GRP_ID_AUTO_GEN_BASE + i);
        }
    }

    for (i = 0; i < g_frm_group_last_idx; i++)
    {
        for (j = 0; j < FRM_AUTO_GEN_GROUP_FREE_RECORD; j++)
        {
            if (i == g_frm_group_free_idx[j])
            {
                /* skip the latest free idx first */
                continue;
            }
        }
        if (IsBitReset(g_frm_group_mask[i/FRM_RESERVED_GROUP_MASK_UNIT], i%FRM_RESERVED_GROUP_MASK_UNIT))
        {
            g_frm_group_last_idx = i + 1;
            SetBit(g_frm_group_mask[i/FRM_RESERVED_GROUP_MASK_UNIT], i%FRM_RESERVED_GROUP_MASK_UNIT);
            return (GRP_ID_AUTO_GEN_BASE + i);
        }
    }

    for (i = FRM_AUTO_GEN_GROUP_FREE_RECORD; i <= 0; i--)
    {
        if (IsBitReset(g_frm_group_mask[g_frm_group_free_idx[i]/FRM_RESERVED_GROUP_MASK_UNIT], g_frm_group_free_idx[i]%FRM_RESERVED_GROUP_MASK_UNIT))
        {
            g_frm_group_last_idx = g_frm_group_free_idx[i] + 1;
            SetBit(g_frm_group_mask[g_frm_group_free_idx[i]/FRM_RESERVED_GROUP_MASK_UNIT], g_frm_group_free_idx[i]%FRM_RESERVED_GROUP_MASK_UNIT);
            return (GRP_ID_AUTO_GEN_BASE + g_frm_group_free_idx[i]);
        }
    }

    /* framework group number isn't enough */
    MMI_ASSERT(0);
    return GRP_ID_INVALID;
}

static scrn_node_struct* find_latest_descendant_scrn(U32 id, group_node_struct* node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    group_node_struct *group;
    base_node_struct *temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* If node is NULL, we find and get group node according the id */
    group = (node) ? node : (group_node_struct*)SG_GET_NODE_FROM_ROOT(id);
    if (group)
    {
        temp = group->m_tail;

        if (temp)
        {
            if (_IS_GROUP(temp))
            {
                return find_latest_descendant_scrn(SCR_ID_INVALID, _GROUP(temp));
            }
            else
            {
                /* we will return the node if it is screen or tab page */
                return _SCRN(temp);
            }
        }
    }
    return NULL;
}

static group_node_struct* find_caller(group_node_struct* parent, group_node_struct* node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    group_node_struct* caller_ret = NULL;
    base_node_struct* curr_node = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if( parent != NULL && node != NULL && node->caller != NULL )
    {
        curr_node = parent->m_head;
        while( curr_node )
        {
            if( _IS_GROUP(curr_node) )
            {
                if( (U32)curr_node == (U32)node->caller )
                {
                    caller_ret = node->caller;
                    break;
                }
                caller_ret = find_caller((group_node_struct*)curr_node, node);
            }
            if( caller_ret )
            {
                break;
            }
            curr_node = curr_node->m_next;
        }
    }
    return caller_ret;
}
#ifdef __MMI_FRM_HISTORY__

static U8 scrn_group_adaptor_destroy_cb(void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    group_node_struct       *top_group = (group_node_struct*)user_data;
    MMI_BOOL                need_clean_dangle = MMI_FALSE;
    mmi_scenario_evt_struct evt = {0};
    base_node_struct        *node = NULL;
    base_node_struct        *next = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (IsBitSet(top_group->attrib, NODE_ATTRIB_IN_END_KEY_PROCESS_IDX))
    {
        /* Need to remove the node in shell.dangle */
        need_clean_dangle = MMI_TRUE;
    }
    if (IsBitSet(top_group->attrib, NODE_ATTRIB_CLOSE_FROM_EXTERNAL_IDX))
    {
        mmi_frm_group_close_ex ((MMI_ID)top_group->id, SCENARIO_POST_TYPE_INTERNAL, NULL, MMI_FALSE);
        /* There may some post event need to be handled in goback process, we should handle these post events here. */
        scenario_process_post_evt_ex(SCENARIO_POST_TYPE_INTERNAL);
    }

    if (need_clean_dangle)
    {
        node = shell.scenario_dangle.m_head;
        while (node)
        {
            mmi_ret ret = MMI_RET_OK;
            next = node->m_next;
            ret = interaction(EVT_ID_DELETE_DANGLE_GROUP_REQ, node, &evt);
            if (ret == MMI_RET_OK)
            {
                evt.targ_group  = _IS_GROUP(node) ? node->id : GRP_ID_INVALID;
                evt.targ_scrn   = (!_IS_GROUP(node)) ? node->id : SCR_ID_INVALID;
                evt.curr_group  = GRP_ID_INVALID;
                evt.curr_scrn   = SCR_ID_INVALID;
			    evt.evt_id      = EVT_ID_SCENARIO_CHANGE;
			    evt.user_data   = node->user_data;
			    evt.new_group   = GRP_ID_INVALID;
			    evt.new_scrn    = SCR_ID_INVALID;

			    execute_node_post_deinit(node, &evt);
            }
            node = next;
        }
    }

    return MMI_TRUE;
}

static U8 scrn_group_adaptor_delete_cb(void* type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	group_node_struct *top_group = NULL;
    U16 delete_scrn_id;
    base_node_struct *node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((U32)type == (U32)MMI_HIST_EXIT_SCREEN_TYPE ||
        (U32)type == (U32)MMI_HIST_EXIT_SCREEN_IN_END_KEY_TYPE)
    {
        top_group = _GROUP(mmi_frm_get_current_screen_argument());
    }
    else if ((U32)type == (U32)MMI_HIST_DELETE_SCREEN_TYPE ||
             (U32)type == (U32)MMI_HIST_DELETE_SCREEN_IN_END_KEY_TYPE)
    {
        mmi_frm_get_current_delete_screen_id(&delete_scrn_id);
		top_group = _GROUP(mmi_frm_get_argument_with_screen(delete_scrn_id));
    }
    MMI_ASSERT(top_group);

    /* when hide the node that parent is ROOT, need delete from history, but not need delete from tree */
    if (IsBitSet((top_group->state),MMI_SCENARIO_STATE_HIDE_IDX))
        return MMI_HIST_ALLOW_DELETING;

    if (IsBitReset(top_group->attrib, NODE_ATTRIB_CLOSE_TO_EXTERNAL_IDX))
    {
        /*
         * If close group adaptor node and back to external screen-history mechanism,
         * we don't set NODE_ATTRIB_CLOSE_FROM_EXTERNAL_IDX flag.
         */
        SetBit(top_group->attrib, NODE_ATTRIB_CLOSE_FROM_EXTERNAL_IDX);
    }

    if ((U32)type == (U32)MMI_HIST_EXIT_SCREEN_IN_END_KEY_TYPE ||
        (U32)type == (U32)MMI_HIST_DELETE_SCREEN_IN_END_KEY_TYPE)
    {
        /* check if it is in end key process */
        SetBit(top_group->attrib, NODE_ATTRIB_IN_END_KEY_PROCESS_IDX);
    }
    shell.is_allow_delete_adapor_node = 1;
	g_is_stop_when_forbiden = MMI_FALSE;
    scrn_group_adaptor_destroy_cb(top_group);
    if (shell.is_allow_delete_adapor_node == 0)
    {
        ResetBit(top_group->attrib, NODE_ATTRIB_CLOSE_FROM_EXTERNAL_IDX);
        ResetBit(top_group->attrib, NODE_ATTRIB_IN_END_KEY_PROCESS_IDX);
        node = SG_GET_NODE_FROM_BG(top_group->id);
        if (node != NULL)
        {
            return MMI_HIST_STOP_BUT_DEL_THIS_ONE;
        }
        return MMI_HIST_STOP_DELETING;
    }
    return MMI_HIST_ALLOW_DELETING;
}


static void scrn_group_adaptor_exit(group_node_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_info_struct scrn_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scenario_is_redrawing())
    {
        //TODO: may merge the redraw case to normal inactive
        if (shell.active_scrn)
        {    
            scrn_redraw_clean(shell.active_scrn);
            shell.active_scrn = NULL;
        }
        return;
    }
    mmi_frm_get_screen_info((MMI_ID)node->id, &scrn_info);
    if (scrn_info.state == MMI_FRM_SCREEN_FORWARD)
    {
        mmi_frm_shell_inactive(_NODE(node));
    }
}

static void scrn_group_adaptor_entry(group_node_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_info_struct scrn_info;
    mmi_event_struct         evt = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_LCM_PRIMITIVE_FLUSH__
    /* skip adaptor case */
    mmi_frm_screen_set_change_record_mode(MMI_FALSE);
#endif    
    mmi_frm_entry_new_screen((U16)node->id, (exit_func_ptr)scrn_group_adaptor_exit, (entry_func_ptr)scrn_group_adaptor_entry, (void*)MMI_FRM_SCRN_GROUP);

#ifdef __MMI_LCM_PRIMITIVE_FLUSH__
    mmi_frm_screen_set_change_record_mode(MMI_TRUE);    
#endif

    adaptor_show_dummy_screen();

    if (mmi_is_redrawing_bk_screens() == MMI_TRUE)
        return;

    mmi_frm_get_screen_info((MMI_ID)node->id, &scrn_info);
    switch (scrn_info.state)
    {
    case MMI_FRM_SCREEN_REDRAW:
        break;
    case MMI_FRM_SCREEN_NONE:
    case MMI_FRM_SCREEN_FORWARD:
    case MMI_FRM_SCREEN_BACKWARD:
 
        SetDelScrnIDCallbackHandler((U16)node->id, scrn_group_adaptor_delete_cb);
        /* If we entry root't goup, we will enter screen in original screen-history. */
        if (shell.post_flow_in_org_back_history == 0 && 
            scrn_info.state == MMI_FRM_SCREEN_BACKWARD)
        {
            if (SG_GET_NODE_FROM_ROOT(node->id) != NULL)
            {
                /* We need to active the shell screen group when back from original screen-history to screen group mech. */
                mmi_frm_shell_active(_NODE(node));
            }
            else
            {
                MMI_FRM_INIT_EVENT(&evt, EVT_ID_GOBACK_HISTORY);
                MMI_FRM_POST_EVENT(&evt, mmi_scenario_external_post_proc, NULL);
            }
        }
    }
}

#endif
static mmi_ret mmi_frm_dummy_proc(mmi_event_struct* evt)
{
    return MMI_RET_OK;
}


static void group_inactive(group_node_struct *node, mmi_scenario_evt_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    base_node_struct* top_child;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsBitSet(node->state, MMI_SCENARIO_STATE_ACTIVE_IDX))
    {
        /* If the node is active state, we need to execute inactive process */
        top_child = node->m_tail;
        while(top_child != NULL)
        {
            if (((_IS_TAB(top_child)) && (top_child == (base_node_struct*)shell.active_tab)) || (_IS_SCRN(top_child)) && (top_child == (base_node_struct*)shell.active_scrn))
            {
                break;
            }
            if (_IS_GROUP(top_child) && (is_in_active_group_serial(top_child->id)))
            {
                break;
            }
            top_child = ((group_node_struct *)top_child)->m_prev;
        }
        if (top_child)
        {
            //if (g_scrn_mgr_cntx.active_scrn_id == g_scrn_mgr_cntx.exit_scrn_id)
            //{
            //    set_active_scrn_id(GRP_ID_INVALID, SCR_ID_INVALID);
            //}
            _EXECUTE_NODE_INACTIVE(top_child, evt);
        }

        /* post the inactive event to the group */
        _POST_INTERNAL_SCENARIO_EVT(node->id, SCR_ID_INVALID, POST_EXECUTE_GROUP_INACTIVE, evt);
    }
}


static void group_post_inactive(group_node_struct *node, mmi_scenario_evt_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (shell.active_group == node)
    {
        /* send the defocus event to the top group */
        group_focus_change(shell.active_group, evt, MMI_FALSE);
    }
    interaction(EVT_ID_GROUP_INACTIVE, _NODE(node), evt);


    mmi_frm_asm_scenario_hook(HOOK_EVT_BEFORE_INACTIVE, (base_node_struct *)node);
    mmi_frm_asm_scenario_hook(HOOK_EVT_AFTER_INACTIVE, (base_node_struct *)node);

    if (shell.active_group == node)
    {
        shell.active_group = (node->parent != &shell.scenario_root) ? node->parent : NULL;
        shell.active_scrn = NULL;
        
        if (g_scrn_mgr_cntx.active_scrn_id == g_scrn_mgr_cntx.exit_scrn_id)
        {
            set_active_scrn_id(shell.active_group ? shell.active_group->id : GRP_ID_INVALID, SCR_ID_INVALID);
        }
    }
}


static void group_active(group_node_struct *node, mmi_scenario_evt_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL    in_active_group_serial = MMI_FALSE;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IsBitSet(node->state, MMI_SCENARIO_STATE_ACTIVE_IDX))
    {
        /*
         * check if the parent node belongs to active group serial:
         * case1: mmi_frm_group_enter(GRP_ID_ROOT, yyy, ...)
         *        we will invoke scrn_group_adaptor screen and active yyy node.
         * case2: mmi_frm_group_enter(xxx, yyy, ...)
         *        we will active yyy if xxx is in active group serial.
         * case3: mmi_frm_group_enter(xxx, yyy, ...)
         *        we do nothing on yyy if xxx isn't in active group serial
         *        because we already add yyy in xxx at mmi_frm_group_enter_ex()
         */
    #ifdef __MMI_FRM_HISTORY__
        if (node->parent == &shell.scenario_root)
        {
            /* case 1 */
            if (IsBitSet(evt->state, MMI_SCENARIO_STATE_FORWARD_IDX))
            {
                /* 
                 * If the parent is scenario root,
                 * we will add scrn_group_adaptor node in original historyData[].
                 */
                mmi_frm_create_new_screen((entry_func_ptr)scrn_group_adaptor_entry, (void*)node);
                in_active_group_serial = MMI_TRUE;
            }
            else if (IsBitSet(evt->state, MMI_SCENARIO_STATE_BACKWARD_IDX))
            {
                historyNode *hist;
                MMI_ASSERT(GetHistoryPointer((MMI_ID)node->id, &hist));
                in_active_group_serial = MMI_TRUE;
            }
        }
        else if (is_in_active_group_serial((MMI_ID)node->parent->id))
        {
            /* case 2 */
            in_active_group_serial = MMI_TRUE;
        }
    #else 
        if ((node->parent == &shell.scenario_root) || 
			is_in_active_group_serial((MMI_ID)node->parent->id))
            in_active_group_serial = MMI_TRUE;
    #endif /* __MMI_FRM_HISTORY__ */
        if (in_active_group_serial)
        {
            /*
             * Because the node was added in parent and wait to active, 
             * we found the previous node to execute the inactive process.
             */
            if (IsBitSet(evt->state, MMI_SCENARIO_STATE_FORWARD_IDX))
            {
                /* forward case: we need to inactive the previous node
                 * backward case: we don't need to execute inactive process
                 */
                if (find_prev_node(_NODE(node)))
                {
					_EXECUTE_NODE_INACTIVE(find_prev_node(_NODE(node)), evt);
                }
                ResetBit(node->attrib, NODE_ATTRIB_BK_ACTIVE);
            }
            else if(IsBitSet(evt->state, MMI_SCENARIO_STATE_BACKWARD_IDX))
            {
                SetBit(node->attrib, NODE_ATTRIB_BK_ACTIVE);
            }
            /* Active the group */
            _POST_INTERNAL_SCENARIO_EVT(node->id, SCR_ID_INVALID, POST_EXECUTE_GROUP_ACTIVE, evt);
            
        }
		else
		{
			ResetBit(node->state, MMI_SCENARIO_STATE_ACTIVE_IDX);
			SetBit(node->state, MMI_SCENARIO_STATE_INACTIVE_IDX);
		}
    }
    else
    {
        ResetBit(node->state, MMI_SCENARIO_STATE_INACTIVE_IDX);
        SetBit(node->state, MMI_SCENARIO_STATE_ACTIVE_IDX);
    }
}


static void group_post_active(group_node_struct *node, mmi_scenario_evt_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 tmp = evt->state;
	base_node_struct *previous;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	previous = find_prev_node(_NODE(node));
	if (IsBitSet(evt->state, MMI_SCENARIO_STATE_FORWARD_IDX) &&
		node->parent &&
		node->parent != &shell.scenario_root &&
		( previous == NULL || !_IS_GROUP(previous)) || IsBitSet(evt->state, MMI_SCENARIO_STATE_BACKWARD_IDX) && (node->parent == shell.active_group))
    {
        group_focus_change(shell.active_group, evt, MMI_FALSE);
    }

	mmi_frm_asm_scenario_hook(HOOK_EVT_BEFORE_ACTIVE, (base_node_struct *)node);

    interaction(EVT_ID_GROUP_ACTIVE, _NODE(node), evt);

    if (shell.active_group != node)
    {
        shell.active_group = node;
        shell.active_scrn = NULL;
        if (g_scrn_mgr_cntx.active_scrn_id == g_scrn_mgr_cntx.exit_scrn_id)
		{
			set_active_scrn_id(shell.active_group ? shell.active_group->id : GRP_ID_INVALID, SCR_ID_INVALID);
		}
        group_focus_change(shell.active_group, evt, MMI_TRUE);
    }

	if (node->m_tail && IsBitSet(node->m_tail->state, MMI_SCENARIO_STATE_INACTIVE_IDX)) 
	{
		evt->state = tmp;
		evt->targ_group = node->id;
		evt->targ_scrn  = node->m_tail->id;
		_EXECUTE_NODE_ACTIVE(node->m_tail, evt);
	}

	mmi_frm_asm_scenario_hook(HOOK_EVT_AFTER_ACTIVE, (base_node_struct *)node);
}


static void group_focus_change(group_node_struct *node, mmi_scenario_evt_struct* evt, MMI_BOOL is_focus)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scenario_evt_enum evt_id_tmp = (mmi_scenario_evt_enum)evt->evt_id;
    void *user_data_tmp = evt->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (is_focus == MMI_TRUE)
	{
		if (IsBitSet(node->state, MMI_SCENARIO_STATE_FOCUS_IDX))
		{
			return;
		}
	}
	else
	{
		if (IsBitReset(node->state, MMI_SCENARIO_STATE_FOCUS_IDX))
		{
			return;
		}
	}
    /*
     * We may use current evt to sent EVT_ID_GROUP_FOCUS and 
     * we need to keep origina evt_id and user_data (like in scrn_node_enter()) 
     */
    evt->evt_id = (is_focus) ? EVT_ID_GROUP_FOCUSED : EVT_ID_GROUP_DEFOCUSED;
	evt->user_data = node->user_data;

    interaction(evt->evt_id, _NODE(node), evt);

    evt->evt_id = evt_id_tmp;
    evt->user_data = user_data_tmp;
}


static void group_post_exit(group_node_struct *node, mmi_scenario_evt_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    interaction(EVT_ID_GROUP_EXIT, _NODE(node), evt);
    if (shell.active_group == node)
    {
        shell.active_group = (node->parent != &shell.scenario_root) ? node->parent : NULL;
        shell.active_scrn = NULL;
    }
    SG_REMOVE_NODE(node->parent, node);
    SG_ADD_NODE(&shell.scenario_dangle, node);

}

static void group_post_hide(group_node_struct *node, mmi_scenario_evt_struct* evt)
{
    interaction(EVT_ID_GROUP_HIDE, _NODE(node), evt);
}

static void group_move(group_node_struct *node, mmi_scenario_evt_struct* evt)
{
    if (node == NULL)
        return;
    SG_REMOVE_NODE(&shell.scenario_root, node); 
    SG_ADD_NODE(&shell.scenario_bg, node);
    node->parent = &shell.scenario_bg;
	SetBit(shell.state, MMI_SCENARIO_STATE_BACKWARD_IDX);
}


static void group_hide(group_node_struct *node, mmi_scenario_evt_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    base_node_struct *children = NULL;
    base_node_struct *next_children = NULL;
    U32 tmp;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(node != &shell.scenario_root && node != &shell.scenario_dangle);
	children = node->m_tail; 
    while(children)
    {
        next_children = find_prev_node(children);
        _EXECUTE_NODE_HIDE(children, evt);
        tmp = shell.state;
        /* scenario_process_post_evt will reset shell.state, we need to retrieve the value */
        scenario_process_post_evt_ex(SCENARIO_POST_TYPE_INTERNAL);
        shell.state = tmp;
        children = next_children;
    };

    if (IsBitSet(node->state, MMI_SCENARIO_STATE_ACTIVE_IDX))
    {
        _POST_INTERNAL_SCENARIO_EVT(node->id, SCR_ID_INVALID, POST_EXECUTE_GROUP_INACTIVE, evt);
    }
    _POST_INTERNAL_SCENARIO_EVT(node->id, SCR_ID_INVALID, POST_EXECUTE_GROUP_HIDE, evt);

    if (node->parent == &shell.scenario_root)
    {
         _POST_INTERNAL_SCENARIO_EVT(node->id, SCR_ID_INVALID, POST_EXECUTE_GROUP_MOVE, evt);
     #ifdef __MMI_FRM_HISTORY__
         if (g_is_back_root_main_hist == MMI_FALSE)
         {
    		 if (IsBitSet(node->state, MMI_SCENARIO_STATE_ACTIVE_IDX))
    		 {
    	         _POST_INTERNAL_SCENARIO_EVT(node->id, SCR_ID_INVALID, POST_EXECUTE_GOBACK_ORG_HIST, NULL);
    		 }
             else
             {
                 _POST_INTERNAL_SCENARIO_EVT(node->id, SCR_ID_INVALID, POST_EXECUTE_DEL_HIST, NULL);           
             }
         }
     #else
        if (IsBitSet(node->state, MMI_SCENARIO_STATE_ACTIVE_IDX) && node->m_prev)
        {
            _POST_INTERNAL_SCENARIO_EVT(node->parent->id, node->m_prev->id, POST_EXECUTE_ACTIVE, evt);
        }
     #endif /* __MMI_FRM_HISTORY__ */
    }
}

static void group_unhide(group_node_struct *node, mmi_scenario_evt_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    base_node_struct *children = NULL;
    base_node_struct *next_children = NULL;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (node->parent == &shell.scenario_bg)
    {
        SG_REMOVE_NODE(&shell.scenario_bg, _NODE(node));
        SG_ADD_NODE(&shell.scenario_root,node);
        node->parent = &shell.scenario_root;
    #ifdef __MMI_FRM_HISTORY__
        mmi_frm_create_new_screen((entry_func_ptr)scrn_group_adaptor_entry, (void*)node);
    #else
        if (shell.active_group != NULL)
        {
            base_node_struct* pNode = (base_node_struct *)shell.active_group;
            while(pNode && pNode->parent != &shell.scenario_root)
                pNode = (base_node_struct *)pNode->parent;
            _EXECUTE_NODE_INACTIVE(pNode,evt);
            scenario_process_post_evt_ex(SCENARIO_POST_TYPE_INTERNAL);
        }
    #endif
    }
    interaction(EVT_ID_GROUP_UNHIDE, _NODE(node), evt);
    
    if (is_in_tail_serial(&shell.scenario_root, _NODE(node)))
    {
        mmi_frm_asm_scenario_hook(HOOK_EVT_BEFORE_ACTIVE, (base_node_struct *)node);
		if (node->parent != &shell.scenario_root)
		{
			group_focus_change(node->parent, evt, MMI_FALSE);
		}
        interaction(EVT_ID_GROUP_ACTIVE, _NODE(node), evt);

        if (shell.active_group != node)
        {
            shell.active_group = node;
            shell.active_scrn = NULL;
            if (g_scrn_mgr_cntx.active_scrn_id == g_scrn_mgr_cntx.exit_scrn_id)
    		{
    			set_active_scrn_id(shell.active_group ? shell.active_group->id : GRP_ID_INVALID, SCR_ID_INVALID);
    		}
            group_focus_change(shell.active_group, evt, MMI_TRUE);
        }    
    }
	children = node->m_head; 
    while(children)
    {
        next_children = find_next_node(children);
        _EXECUTE_NODE_UNHIDE(children, evt);
        children = next_children;
    };

}

static mmi_ret close_children(group_node_struct *node, mmi_scenario_evt_struct* evt, base_node_struct **stoped_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    base_node_struct *children = NULL;
    base_node_struct *next_children = NULL;
    U32 tmp = 0;
    mmi_ret  result = MMI_RET_OK;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *stoped_node = NULL;
    children = node->m_tail;
    while (children)
    {
        if (IsBitSet(node->attrib, NODE_ATTRIB_IN_END_KEY_PROCESS_IDX))
        {
            SetBit(children->attrib, NODE_ATTRIB_IN_END_KEY_PROCESS_IDX);
        }
        next_children = find_prev_node(children);
        result = _EXECUTE_NODE_CLOSE(children, evt);
        if (result != MMI_RET_OK)
        {
            *stoped_node = children;
#ifndef __MMI_FRM_HISTORY__
            if(group_close_from_gprot)
                result = MMI_RET_STOP_END_KEY_FLOW;
#endif
            break;
        }
        tmp = shell.state;
        scenario_process_post_evt_ex(SCENARIO_POST_TYPE_INTERNAL);
        shell.state = tmp;
        children = next_children;
    }
    return result;
}

static U16 get_group_close_event_id(group_node_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (IsBitSet(node->attrib, NODE_ATTRIB_IN_END_KEY_PROCESS_IDX))
    {
        if (IsBitSet(node->state, MMI_SCENARIO_STATE_ACTIVE_IDX))
        {
            return EVT_ID_GROUP_GOBACK_IN_END_KEY;
        }
        else
        {
            return EVT_ID_GROUP_DELETE_REQ_IN_END_KEY;
        }
    }
    else
    {
        if (IsBitSet(node->state, MMI_SCENARIO_STATE_ACTIVE_IDX))
        {
            return EVT_ID_GROUP_GOBACK;
        }
        else
        {
            return EVT_ID_GROUP_DELETE_REQ;
        }        
    }
}

static base_node_struct *is_need_to_focus_parent(group_node_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    base_node_struct *focus_node = NULL;
    base_node_struct *previous;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IsBitSet(node->state, MMI_SCENARIO_STATE_ACTIVE_IDX) ||  /* inactive node will not cause focus change */
        !IsBitSet(node->attrib, NODE_ATTRIB_CLOSED_TARGET_IDX) || /* sub node will not cause focus change */
        node->parent == &shell.scenario_root)                     /* root node will use history change to change focus */
    {
        return NULL;
    }

    previous = find_prev_node(_NODE(node));

    if (previous == NULL || !_IS_GROUP(previous))
    {
        focus_node = _NODE(node->parent);
    }
    return focus_node;
}


static base_node_struct *is_need_to_active_previous(group_node_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    base_node_struct *previous = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((IsBitSet(node->state, MMI_SCENARIO_STATE_ACTIVE_IDX)) && 
        (IsBitSet(node->attrib, NODE_ATTRIB_CLOSED_TARGET_IDX)) )        
    {
        /* If the group is the closed target, we need to active the previous node at the same level. */
        previous = node->m_prev; 
    }
#ifdef __MMI_FRM_HISTORY__
    if(node->parent == &shell.scenario_root)
        previous = NULL;
#else
    if(IsBitSet(shell.state, MMI_SCENARIO_STATE_BACK_TO_IDLE_IDX))
        previous = NULL;
#endif
    return previous;
}


static mmi_ret group_close(group_node_struct *node, mmi_scenario_evt_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret  result = MMI_RET_OK;
    base_node_struct *stop_close_node = NULL;
    U16 evt_id;    
    #ifdef __MMI_FRM_HISTORY__
    base_node_struct  *root_screen = NULL;    
    MMI_ID tail_node_id = node->m_tail ? node->m_tail->id : 0;
    #endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(node != &shell.scenario_root && node != &shell.scenario_dangle);
#ifdef __TST_TRACE_ENABLED__
    mmi_frm_event_set_dump_history_flag(MMI_TRUE);
#endif

    evt_id = get_group_close_event_id(node);

    /* query group if can be closed */
    result = interaction(evt_id, _NODE(node), evt);

    if (result != MMI_RET_OK)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM,
            MMI_FRM_SCENARIO_FORBID_CLOSE,
            node->id,
            0,
            node->proc);
    }
#ifdef __MMI_FRM_HISTORY__
    if (result == MMI_RET_STOP_END_KEY_FLOW)
    {
        if (node->parent == &shell.scenario_root)
        {
            g_is_stop_when_forbiden = MMI_TRUE;
        }
    }
#endif /* __MMI_FRM_HISTORY__ */

    /* if group allow to be closed, close its children */
    if (result == MMI_RET_OK)
    {
        result = close_children(node, evt, &stop_close_node);
    }

    /* if group or its children don't allow to be closed */
    if (result != MMI_RET_OK)
    {
        ResetBit(node->attrib, NODE_ATTRIB_IN_END_KEY_PROCESS_IDX);
        ResetBit(node->state, MMI_SCENARIO_STATE_BACKWARD_IDX);
    #ifdef __MMI_FRM_HISTORY__
        shell.is_allow_delete_adapor_node = 0;        
        root_screen = find_root_screen(node->id);
        if (root_screen)
        {
            ResetBit(root_screen->attrib, NODE_ATTRIB_NOT_ALLOW_DEL);
        }

        if (stop_close_node && node->m_tail && (stop_close_node->id != tail_node_id))
        {
            _POST_INTERNAL_SCENARIO_EVT(stop_close_node->parent->id, stop_close_node->id, POST_EXECUTE_ACTIVE, evt);
        }
    #else
        if(IsBitReset(shell.state,MMI_SCENARIO_STATE_STOP_CLOSE_BREAK_IDX) &&
                IsBitReset(shell.state,MMI_SCENARIO_STATE_STOP_CLOSE_CONTINUE_IDX))
        {
            shell.targ_node = (base_node_struct*)node;
            if(stop_close_node != NULL)
                shell.targ_node = (base_node_struct*)stop_close_node;
        }
        
        if(result == MMI_RET_STOP_END_KEY_FLOW )
        {
            SetBit(shell.state,MMI_SCENARIO_STATE_STOP_CLOSE_BREAK_IDX);
        }
        else
        {
            SetBit(shell.state,MMI_SCENARIO_STATE_STOP_CLOSE_CONTINUE_IDX);
        }
    #endif /* __MMI_FRM_HISTORY__ */
        mmi_frm_asm_scenario_hook(HOOK_EVT_CLOSE_FAIL, (base_node_struct *)node);

    }
    else
    {
        base_node_struct *previous;
        base_node_struct *parent;
        if (IsBitSet(node->state, MMI_SCENARIO_STATE_ACTIVE_IDX))
        {
            if (IsBitSet(node->state, MMI_SCENARIO_STATE_FOCUS_IDX))
            {
                //_POST_INTERNAL_SCENARIO_EVT(node->id, SCR_ID_INVALID, POST_EXECUTE_GROUP_DEFOCUS, evt);    
            }
            _POST_INTERNAL_SCENARIO_EVT(node->id, SCR_ID_INVALID, POST_EXECUTE_GROUP_INACTIVE, evt);
        }

        _POST_INTERNAL_SCENARIO_EVT(node->id, SCR_ID_INVALID, POST_EXECUTE_GROUP_EXIT, evt);

    #ifdef __MMI_FRM_HISTORY__
        if (node->parent == &shell.scenario_root && 
            IsBitReset(node->attrib, NODE_ATTRIB_CLOSE_FROM_EXTERNAL_IDX))
        {
            SetBit(node->attrib, NODE_ATTRIB_CLOSE_TO_EXTERNAL_IDX);
        }
    #endif /* __MMI_FRM_HISTORY__ */
        _POST_INTERNAL_SCENARIO_EVT(node->id, SCR_ID_INVALID, POST_EXECUTE_DEINIT, evt);

        if ((parent = is_need_to_focus_parent(node)) != NULL)
        {
            _POST_INTERNAL_SCENARIO_EVT(parent->id, SCR_ID_INVALID, POST_EXECUTE_GROUP_FOCUS, evt);
        }

        if ((previous = is_need_to_active_previous(node)) != NULL)
        {     
            _POST_INTERNAL_SCENARIO_EVT(previous->parent->id, previous->id, POST_EXECUTE_ACTIVE, evt);
        }
    }
    return result;
}

extern mmi_ret mmi_frm_asm_scenario_hook(scenario_hook_evt_enum evt, base_node_struct *node);

static void set_scenario_evt(mmi_scenario_evt_struct *evt, MMI_ID group_id, MMI_ID scrn_id, void *user_data)
{
	evt->targ_group = group_id;
	evt->targ_scrn  = scrn_id;
	evt->user_data  = user_data;
}

static group_node_struct* create_new_group(group_node_struct* node_parent, MMI_ID node_new_id, mmi_proc_func proc, void *data, MMI_BOOL* b_exist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    group_node_struct* group_new = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(b_exist != NULL)
        *b_exist = MMI_TRUE;
    /* check node_new_id already exist in parent */
    group_new = (group_node_struct*)SG_GET_NODE(node_parent, node_new_id);
    if (group_new == NULL)
        group_new = (group_node_struct*)SG_GET_NODE_FROM_DANGLE(node_new_id);
    if (group_new == NULL)
    {
        if(b_exist != NULL)
            *b_exist = MMI_FALSE;
        group_new = _MMI_MEM_ALLOC(sizeof(group_node_struct), SCENARIO_GROUP_NODE);        
        group_new->type = SCENARIO_GROUP_NODE;
        
        if (proc == NULL)
        {
            proc = mmi_frm_dummy_proc;
        }
        group_new->proc = proc;
        group_new->user_data = data;
        group_new->parent = node_parent;        
        /* The default value of caller is the same with parent */
        group_new->caller = node_parent;
        if (node_new_id == GRP_ID_AUTO_GEN)
        {
            group_new->id = (U32)auto_gen_group_id();
        }
        else
        {
            group_new->id = (U32)node_new_id;
        }
    }
    return group_new;
}



MMI_ID mmi_frm_group_create_ex(MMI_ID parent_id, MMI_ID group_id, mmi_proc_func proc, void *user_data, mmi_group_enter_flag flag)
{
	MMI_ID gid;
    if(mmi_frm_scenario_is_redrawing())
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_CREATE, group_id, G_CREATE_IN_REDRAW_SG_API_END);
        return GRP_ID_INVALID;
    }
    gid = mmi_frm_group_create(parent_id, group_id, proc, user_data);
    mmi_frm_group_enter(gid, flag);
    return gid;
}


MMI_ID mmi_frm_group_create (MMI_ID parent_id, MMI_ID group_id, mmi_proc_func proc, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    group_node_struct *node_parent = NULL, *node_new;
    MMI_BOOL is_exist;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check parent is exist */
    node_parent = (group_node_struct*)SG_GET_NODE_FROM_ALL(parent_id);
    if (node_parent == NULL)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_CREATE, parent_id, group_id, proc, user_data, 0, G_CREATE_NO_PARENT_SG_API_END);
        return GRP_ID_INVALID;
    }
    node_new = create_new_group(node_parent, group_id, proc, user_data, &is_exist);
    
    if (!is_exist && SG_GET_NODE_FROM_DANGLE(group_id) == NULL)
    {
        node_new->state = MMI_SCENARIO_STATE_CREATE;
        SG_ADD_NODE(&shell.scenario_dangle, node_new);
        mmi_frm_asm_scenario_hook(HOOK_EVT_AFTER_CREATE, (base_node_struct *)node_new);
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_CREATE, parent_id, group_id, proc, user_data, node_new->id, SG_API_END);
    }
    else
    {
        /* group is alreay existed in the scenario tree */        
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_CREATE, parent_id, group_id, proc, user_data, group_id, G_CREATE_EXIST_SG_API_END);
    }
    return node_new->id;
}


MMI_ID mmi_frm_group_enter_ex (MMI_ID parent_id, MMI_ID group_id, mmi_proc_func proc, void *user_data, mmi_group_enter_flag flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scenario_evt_struct evt = {0};
    group_node_struct *new_node = NULL;
    group_node_struct *parent = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parent = (group_node_struct*)SG_GET_NODE_FROM_ROOT(parent_id);

    new_node = (group_node_struct*)SG_GET_NODE_FROM_DANGLE(group_id);
    if (new_node == NULL)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_ENTER, group_id, flag, G_ENTER_EX_NO_CREATE);
        new_node = create_new_group(parent, group_id, proc, user_data,NULL);
    }
    
    if (flag == MMI_FRM_NODE_SMART_CLOSE_FLAG)
    {
        SetBit(new_node->attrib, NODE_ATTRIB_SMART_CLOSED_IDX);
    }
    else if (flag == MMI_FRM_NODE_SMART_CLOSE_CAUSED_BY_CLOSE_FLAG)
    {
        SetBit(new_node->attrib, NODE_ATTRIB_SMART_CLOSED_CAUSE_BY_CLOSE_IDX);
    }
    
    /* entry new group in the active group */
    SetBit(evt.state, MMI_SCENARIO_STATE_FIRST_ENTRY_IDX);
    SetBit(evt.state, MMI_SCENARIO_STATE_FORWARD_IDX);    
    set_scenario_evt(&evt, new_node->id, SCR_ID_INVALID, new_node->user_data);

    MMI_ASSERT(new_node->proc);

    SG_REMOVE_NODE(&shell.scenario_dangle, new_node);
    SG_ADD_NODE(parent, new_node);
    if (shell.state == MMI_SCENARIO_STATE_NONE)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_ENTER, group_id, flag, SCENARIO_NORMAL);
        shell.state = evt.state;
        _EXECUTE_NODE_INIT(new_node, &evt);
        _EXECUTE_NODE_ACTIVE(new_node, &evt);

        scenario_process_post_evt_ex(SCENARIO_POST_TYPE_APP);
    }
    else
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_ENTER, group_id, flag, SCENARIO_POST);
        _EXECUTE_NODE_INIT(new_node, &evt);
        _POST_APP_SCENARIO_EVT(new_node->id, SCR_ID_INVALID, POST_EXECUTE_ACTIVE, &evt);
    }
    return new_node->id;
}



MMI_ID mmi_frm_group_enter (MMI_ID group_id, mmi_group_enter_flag flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    group_node_struct *node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_ENTER, group_id, flag, SG_API_BEG);
    if (SG_GET_NODE_FROM_ROOT(group_id) == NULL)
    {
        node = (group_node_struct*)SG_GET_NODE_FROM_DANGLE(group_id);
        if (node)
        {
            if (node->parent && SG_GET_NODE_FROM_ROOT(node->parent->id))
            {
                /* If its parent is valid, we entry new group */
                mmi_frm_group_enter_ex((MMI_ID)node->parent->id, (MMI_ID)node->id, node->proc, node->user_data, flag);
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_ENTER, group_id, flag, SG_API_END);
                return node->id;
            }
            else
            {
                /* We will close the group if its parent is invalid */
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_ENTER, group_id, flag, G_ENTER_NO_PARENT_SG_API_END); 
                mmi_frm_group_close(group_id);                 
                return GRP_ID_INVALID;
            }
        }
        else
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_ENTER, group_id, flag, G_ENTER_NO_CREATE_SG_API_END);
            return GRP_ID_INVALID;
        }
    }
    else
    {
        /* group is alreay existed in the scenario tree */
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_ENTER, group_id, flag, G_ENTER_EXIST_SG_API_END);
        return group_id;
    }
}


MMI_ID mmi_frm_get_previous_app_id(MMI_ID app_id)
{
    mmi_id prev_id = GRP_ID_INVALID;

#ifdef __MMI_FRM_HISTORY__
    /* Pluto has many tricks, put them in one place. */
    if(app_id == get_active_history_node_id())
    {
        prev_id = GetCurrScrnId();
    }
    else
    {
        GetPreviousScrnIdOf(app_id, &prev_id);
    }
#else
	prev_id = mmi_frm_scrn_get_neighbor_id(GRP_ID_ROOT, app_id, MMI_FRM_NODE_BEFORE_FLAG);
#endif
    
    return prev_id;
}


mmi_ret mmi_frm_group_set_app_name(MMI_ID gid, CHAR *app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    group_node_struct *node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node = (group_node_struct *)SG_GET_NODE_FROM_ALL(gid);
    if (node)
    {
        /* Use control buffer to allocate app_name for the group node */
        if (node->app_name == NULL)
        {
            node->app_name = mmi_malloc(MMI_APP_NAME_MAX_LEN + 1);
        }
        strncpy(node->app_name, app_name, MMI_APP_NAME_MAX_LEN);
        return MMI_RET_OK;
    }
    else
    {
        return MMI_RET_ERR;
    }
}

mmi_ret node_state_update(base_node_struct *node, void *arg)
{
    if (arg == (void *)0)
    {
        SetBit(node->state, MMI_SCENARIO_STATE_APP_DO_HIDE_IDX);
        ResetBit(node->state, MMI_SCENARIO_STATE_APP_DO_UNHIDE_IDX);        
    }
    else if (arg == (void *)1)
    {
        SetBit(node->state, MMI_SCENARIO_STATE_APP_DO_UNHIDE_IDX);
        ResetBit(node->state, MMI_SCENARIO_STATE_APP_DO_HIDE_IDX);        
    }
    else
    {
        MMI_ASSERT(0);
    }
	return MMI_RET_OK;
}



void mmi_frm_group_hide(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scenario_evt_struct evt = {0};
    group_node_struct *group;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt.targ_group  = group_id;
    evt.targ_scrn   = SCR_ID_INVALID;
    group = (group_node_struct *)SG_GET_NODE_FROM_ROOT(group_id);
    if (group != NULL && SG_GET_NODE_FROM_BG(group_id) == NULL)
    {

        traverse_scenario_tree((base_node_struct *)group, node_state_update, node_state_update, NULL, (void*)0);
        if (shell.state == MMI_SCENARIO_STATE_NONE)
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_SCENARIO_GROUP_HIDE, group_id, SCENARIO_NORMAL);
            _EXECUTE_NODE_HIDE(group, &evt);
            scenario_process_post_evt_ex(SCENARIO_POST_TYPE_APP);
        }
        else
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_SCENARIO_GROUP_HIDE, group_id, SCENARIO_POST);
            _POST_APP_SCENARIO_EVT(group_id, SCR_ID_INVALID, POST_EXECUTE_HIDE, &evt);
        }
    }
    else
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_SCENARIO_GROUP_HIDE, group_id, ERR_G_HIDE_NOT_EXIST);
    }
}

void mmi_frm_group_unhide(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scenario_evt_struct evt = {0};
    group_node_struct *group;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt.targ_group  = group_id;
    evt.targ_scrn   = SCR_ID_INVALID;
    group = (group_node_struct *)SG_GET_NODE_FROM_BG(group_id);
    if (group != NULL)
    {
        traverse_scenario_tree((base_node_struct *)group, node_state_update, node_state_update, NULL, (void*)1);
        if (shell.state == MMI_SCENARIO_STATE_NONE )
        {
            
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_SCENARIO_GROUP_UNHIDE, group_id, SCENARIO_NORMAL);
            _EXECUTE_NODE_UNHIDE(group, &evt);
            scenario_process_post_evt_ex(SCENARIO_POST_TYPE_APP);
        }
        else
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_SCENARIO_GROUP_UNHIDE, group_id, SCENARIO_POST);
            _POST_APP_SCENARIO_EVT(group_id, SCR_ID_INVALID, POST_EXECUTE_UNHIDE, &evt);
        }
    }
    else
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_SCENARIO_GROUP_UNHIDE, group_id, ERR_G_UNHIDE_NOT_EXIST);
    }
}


mmi_ret mmi_frm_group_insert (MMI_ID parent_id, MMI_ID base_id, mmi_frm_node_struct *new_node_info, mmi_scenario_node_flag flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret                 rst = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (new_node_info == NULL)
        return MMI_RET_ERR;

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_INSERT,\
        (U16)parent_id, (U16)base_id, (U16)new_node_info->id, new_node_info->entry_proc, flag, SG_API_BEG);

    if (shell.state == MMI_SCENARIO_STATE_NONE)
    {        
        /* Aleady consider parent_id is GRP_ID_ROOT case. */
        rst = mmi_frm_node_insert(parent_id, base_id, new_node_info, flag, 1);
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_INSERT,\
            (U16)parent_id, (U16)base_id, (U16)new_node_info->id, new_node_info->entry_proc, flag, SG_API_END);
    }
    else
    {
        mmi_scenario_evt_struct evt = {0};
        insert_op_info_struct* insert_info_p = (insert_op_info_struct*)mmi_malloc(sizeof(insert_op_info_struct));
        if (insert_info_p != NULL)
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_INSERT, \
                (U16)parent_id, (U16)base_id, (U16)new_node_info->id, new_node_info->entry_proc, flag, SCENARIO_POST);
            insert_info_p->parent_id = parent_id;
            insert_info_p->base_id = base_id;
            insert_info_p->flag = flag;
            insert_info_p->is_group_node = MMI_TRUE;
            memcpy(&insert_info_p->new_node_info, new_node_info, sizeof(mmi_frm_node_struct));
            evt.user_data = (void*)insert_info_p;
            _POST_APP_SCENARIO_EVT(GRP_ID_INVALID, SCR_ID_INVALID, POST_EXECUTE_INSERT, &evt);
        }
    }
    return rst;
}


mmi_ret mmi_frm_group_replace (MMI_ID parent_id, MMI_ID out_id, mmi_frm_node_struct *new_node_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    base_node_struct* node_old = NULL;
    base_node_struct* node_new = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (new_node_info == NULL)
        return MMI_RET_ERR;
        
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_REPLACE, \
        (U16)parent_id, (U16)out_id, (U16)new_node_info->id, new_node_info->entry_proc, SG_API_BEG);

    node_old = SG_GET_NODE_FROM_ROOT(out_id);
    if (node_old == NULL)
        return MMI_RET_ERR;
    node_new = SG_GET_NODE_FROM_ROOT(new_node_info->id);
    if (node_new != NULL)
        return MMI_RET_ERR;
    
    replace_node_sg_op(node_old, new_node_info, MMI_TRUE);    
    
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_REPLACE, \
        (U16)parent_id, (U16)out_id, (U16)new_node_info->id, new_node_info->entry_proc, SG_API_END);
    return MMI_RET_OK;
}



static mmi_ret mmi_frm_group_close_ex (MMI_ID group_id, U32 type, group_node_struct **parent, MMI_BOOL post_to_front)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scenario_evt_struct evt = {0};
    group_node_struct* group = NULL;
    mmi_ret rst = MMI_RET_ERR;
	MMI_BOOL bActive = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group = (group_node_struct*)SG_GET_NODE_FROM_ROOT(group_id);

	if (group == NULL)
	{
		group = (group_node_struct*)SG_GET_NODE_FROM_BG(group_id);
	}

	if (group == NULL)
	{
		MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_CLOSE_EX, group_id, type, G_CLOSE_NOT_EXIST);
        return MMI_RET_ERR;
	}

    if (group && group->parent && 
        (IsBitSet(group->parent->attrib, NODE_ATTRIB_SMART_CLOSED_IDX) ||
        IsBitSet(group->parent->attrib, NODE_ATTRIB_SMART_CLOSED_CAUSE_BY_CLOSE_IDX)))
    {
	    /* If the parent group enable smart close flag, we will check if need to close the parent directly. */
	    while (group->parent &&
               group->parent != &shell.scenario_root && 
               group->parent->m_count == 1)
        {
            /* Because only this group node is in the parent group, we close the parent group directly. */
            group = group->parent;
            group_id = group->id;
            if ((IsBitReset(group->parent->attrib, NODE_ATTRIB_SMART_CLOSED_IDX) ||
                IsBitSet(group->parent->attrib, NODE_ATTRIB_SMART_CLOSED_CAUSE_BY_CLOSE_IDX)))
            {
                break;
            }
        }
    }
    if (parent)
    {
        *parent = group? group->parent: NULL;
    }
    mmi_frm_asm_scenario_hook(HOOK_EVT_BEFORE_CLOSE, (base_node_struct *)group);

    
    if (is_in_active_group_serial(group_id))
	{
		/* the active group was closed and it invokes the goback process */
        bActive = MMI_TRUE;
		SetBit(evt.state, MMI_SCENARIO_STATE_BACKWARD_IDX);
	}
	else
	{
		/* the inactive group was closed and it invokes the deinit process */
		SetBit(evt.state, MMI_SCENARIO_STATE_DELETE_REQ_IDX);
	}

    set_scenario_evt(&evt, group_id, SCR_ID_INVALID, group->user_data);
	
    if (shell.state == MMI_SCENARIO_STATE_NONE && shell.is_smart_close_in_forward_case == 0)
    { 
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_CLOSE_EX, group_id, type, SCENARIO_NORMAL);
        shell.state = evt.state;
		SetBit(group->attrib, NODE_ATTRIB_CLOSED_TARGET_IDX);
        rst = _EXECUTE_NODE_CLOSE(group, &evt);
    #ifndef __MMI_FRM_HISTORY__
        if(IsBitSet(shell.state,MMI_SCENARIO_STATE_STOP_CLOSE_BREAK_IDX))
        {
            mmi_scenario_evt_struct evt = {0};
            if(shell.targ_node)
            {
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_CLOSE_FORBID, (U16)shell.targ_node->id);
                if(bActive)
                {
                    base_node_struct* node_parent = shell.targ_node;
                    node_parent = (base_node_struct*)node_parent->parent;
                    while(node_parent && node_parent != (base_node_struct*)&shell.scenario_root)
                    {
                        if(IsBitSet(node_parent->state, MMI_SCENARIO_STATE_INACTIVE_IDX))
                        {
                            shell.targ_node = (base_node_struct*)node_parent;
                            break;
                        }
                        node_parent = (base_node_struct*)node_parent->parent;
                    }
                    _EXECUTE_NODE_ACTIVE(shell.targ_node, &evt);
                }
            }
            shell.targ_node = NULL;
        }
    #endif
        scenario_process_post_evt_ex(type);

    }
#ifndef __MMI_FRM_HISTORY__
    else if (IsBitSet(shell.state, MMI_SCENARIO_STATE_BACK_TO_IDLE_IDX) && !group_close_from_gprot)
    { 
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_CLOSE_EX, group_id, type, G_CLOSE_GOTO_IDLE);
        SetBit(group->attrib, NODE_ATTRIB_IN_END_KEY_PROCESS_IDX);
        rst = _EXECUTE_NODE_CLOSE(group, &evt);            
        scenario_process_post_evt_ex(type);
    }
#endif
    else if (IsBitSet(shell.state, MMI_SCENARIO_STATE_CLOSE_ALL_BG_GROUPS) && !group_close_from_gprot)
    {
        SetBit(group->attrib, NODE_ATTRIB_CLOSED_TARGET_IDX);
        rst = _EXECUTE_NODE_CLOSE(group, &evt);
        scenario_process_post_evt_ex(type);
    }
    else
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_CLOSE_EX, group_id, type, SCENARIO_POST);
		if (post_to_front)
		{
			_POST_APP_SCENARIO_EVT_TO_FRONT(group_id, SCR_ID_INVALID, POST_EXECUTE_CLOSE, &evt);
		}
		else
		{
			_POST_APP_SCENARIO_EVT(group_id, SCR_ID_INVALID, POST_EXECUTE_CLOSE, &evt);
		}
	}
    return rst;
}


MMI_RET mmi_frm_group_urgent_close(MMI_ID group_id)
{
	return mmi_frm_group_close_ex(group_id, SCENARIO_POST_TYPE_APP, NULL, MMI_TRUE);
}



mmi_ret mmi_frm_group_close (MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret;
    mmi_scenario_evt_struct evt = {0};
    MMI_BOOL temp_backup = group_close_from_gprot;
	group_node_struct *group;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_CLOSE, group_id, SG_API_BEG);
	group = (group_node_struct*)SG_GET_NODE_FROM_DANGLE(group_id);
	if (group != NULL)
	{
		if (IsBitSet(group->state, MMI_SCENARIO_STATE_CREATE_IDX) && IsBitReset(group->state, MMI_SCENARIO_STATE_DEINIT_IDX))
		{
			set_scenario_evt(&evt, group_id, SCR_ID_INVALID, group->user_data);
			execute_node_post_deinit(_NODE(group), &evt);
		}
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_CLOSE_EX, group_id, 0, G_CLOSE_NO_ENTER);
		return MMI_RET_OK;
	}


    if(mmi_frm_scenario_is_redrawing())
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_CLOSE, group_id, G_CLOSE_IN_REDRAWING_SG_API_END);
        return MMI_RET_OK;
    }
 
    group_close_from_gprot = MMI_TRUE;
    ret = mmi_frm_group_close_ex (group_id, SCENARIO_POST_TYPE_APP, NULL, MMI_FALSE);
    group_close_from_gprot = temp_backup;
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_CLOSE, group_id, SG_API_END);
    return ret;
}


mmi_ret mmi_frm_group_set_caller (MMI_ID group_id, MMI_ID caller_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    group_node_struct *node = (group_node_struct *)SG_GET_NODE_FROM_ALL(group_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_SET_CALLER, group_id, caller_id);
    if (node)
    {
        node->caller = (group_node_struct*)SG_GET_NODE_FROM_ROOT(caller_id);
        return MMI_RET_OK;
    }
    else
    {
        return MMI_RET_ERR;
    }
}


mmi_ret mmi_frm_group_set_caller_proc (MMI_ID group_id, mmi_proc_func caller_proc, void *caller_user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    group_node_struct *node = (group_node_struct *)SG_GET_NODE_FROM_ALL(group_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_SET_CALLER_PROC, group_id, caller_proc, caller_user_data);
    if (node)
    {
        node->caller_proc = caller_proc;
        node->caller_user_data = caller_user_data;
        return MMI_RET_OK;
    }
    else
    {
        return MMI_RET_ERR;
    }
}


mmi_ret mmi_frm_group_set_proc_data (MMI_ID group_id, mmi_proc_func proc, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    group_node_struct *node = (group_node_struct *)SG_GET_NODE_FROM_ALL(group_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_SET_PROC_DATA, group_id, proc, data);
    if (node)
    {
        node->proc = proc;
        node->user_data = data;
        return MMI_RET_OK;
    }
    else
    {
        return MMI_RET_ERR;
    }
}


mmi_ret mmi_frm_group_set_user_data (MMI_ID group_id, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    group_node_struct *node = (group_node_struct *)SG_GET_NODE_FROM_ALL(group_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (node)
    {
        node->user_data = data;
        return MMI_RET_OK;
    }
    else
    {
        return MMI_RET_ERR;
    }
}



mmi_ret mmi_frm_group_set_attribute (MMI_ID group_id, mmi_group_attrib_enum attrib)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    group_node_struct *node = (group_node_struct *)SG_GET_NODE_FROM_ALL(group_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_SET_ATTRIBUTE, group_id, attrib);
    if (_IS_GROUP(node))
    {
        switch(attrib)
        {
        case MMI_FRM_NODE_SMART_CLOSE_FLAG:
            SetBit(node->attrib, NODE_ATTRIB_SMART_CLOSED_IDX);
            break;
        case MMI_FRM_NODE_SMART_CLOSE_CAUSED_BY_CLOSE_FLAG:
            SetBit(node->attrib, NODE_ATTRIB_SMART_CLOSED_CAUSE_BY_CLOSE_IDX);
            break;
        default:
            return MMI_RET_ERR;
        }
        return MMI_RET_OK;
    }
    else
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_SET_ATTRIBUTE_ERROR);
        return MMI_RET_ERR;
    }
}


mmi_ret mmi_frm_group_clear_attribute (MMI_ID group_id, mmi_group_attrib_enum attrib)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    group_node_struct *node = (group_node_struct *)SG_GET_NODE_FROM_ALL(group_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_CLEAR_ATTRIBUTE, group_id, attrib);
    if (_IS_GROUP(node))
    {
        switch(attrib)
        {
        case MMI_FRM_NODE_SMART_CLOSE_FLAG:
            ResetBit(node->attrib, NODE_ATTRIB_SMART_CLOSED_IDX);
            break;   
        case MMI_FRM_NODE_SMART_CLOSE_CAUSED_BY_CLOSE_FLAG:
            ResetBit(node->attrib, NODE_ATTRIB_SMART_CLOSED_CAUSE_BY_CLOSE_IDX);
            break;            
        default:
            return MMI_RET_ERR;
        }
        return MMI_RET_OK;
    }
    else
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_CLEAR_ATTRIBUTE_ERROR);
        return MMI_RET_ERR;
    }
}


mmi_ret mmi_frm_group_set_attribute_int(MMI_ID group_id, U32 attrib, MMI_BOOL val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    group_node_struct *node = (group_node_struct *)SG_GET_NODE_FROM_ALL(group_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_SET_ATTRIBUTE, group_id, attrib);
    if (_IS_GROUP(node))
    {
        if (val)
            SetBit(node->attrib, attrib);
        else
            ResetBit(node->attrib, attrib);
        return MMI_RET_OK;
    }
    else
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_SET_ATTRIBUTE_ERROR);
        return MMI_RET_ERR;
    }

}


MMI_BOOL mmi_frm_group_get_attribute_int(MMI_ID group_id, U32 attrib)
{
    group_node_struct *node = (group_node_struct *)SG_GET_NODE_FROM_ALL(group_id);

    if (node)
    {
        if (_IS_GROUP(node))
        {
            return (IsBitSet(node->attrib, attrib) > 0 ? MMI_TRUE : MMI_FALSE);
        }
        MMI_ASSERT(0); /* attribute not exists or group is invalid */
    }
	return MMI_FALSE;
}


asm_data_struct * mmi_frm_group_get_asm_data_ptr(MMI_ID group_id)
{
    group_node_struct *node = (group_node_struct *)SG_GET_NODE_FROM_ALL(group_id);

    if (node)
    {
        if (_IS_GROUP(node))
        {
            return &(node->asm_data);
        }
        MMI_ASSERT(0); /* attribute not exists or group is invalid */
    }
    return NULL;
}


void *mmi_frm_group_get_user_data (MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_frm_get_user_data(group_id, SCR_ID_INVALID);
}


mmi_ret mmi_frm_group_get_info (MMI_ID group_id, mmi_group_node_struct *node_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    group_node_struct* group_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    group_ret = (group_node_struct *)SG_GET_NODE_FROM_ALL(group_id);
    if (group_ret)
    {
        node_info->parent       = group_ret->parent ? group_ret->parent->id : GRP_ID_INVALID;
        /* update caller, maybe is closed, so reset */
        group_ret->caller       = find_caller(&shell.scenario_root, group_ret);
        node_info->caller       = group_ret->caller ? group_ret->caller->id : GRP_ID_INVALID;
        node_info->priority     = group_ret->priority;
        node_info->user_data    = group_ret->user_data;
        node_info->proc         = group_ret->proc;
        node_info->state        = group_ret->state;
        node_info->caller_proc  = group_ret->caller_proc;
        node_info->caller_user_data = group_ret->caller_user_data;

        return MMI_RET_OK;
    }

     return MMI_RET_ERR;
}


MMI_BOOL mmi_frm_group_is_in_active_serial(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (is_in_active_group_serial(group_id)) ? MMI_TRUE : MMI_FALSE;
}


MMI_ID mmi_frm_group_get_active_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scenario_is_redrawing())
    {
        return (shell.active_scrn && shell.active_scrn->parent) ? (shell.active_scrn->parent->id):GRP_ID_INVALID;
    }

    return (shell.active_group) ? shell.active_group->id : GRP_ID_INVALID;
}


MMI_BOOL mmi_frm_group_is_in_top_scope(MMI_ID group_id)
{
    return mmi_frm_group_is_in_active_serial(group_id);
}


MMI_BOOL mmi_frm_group_is_present (MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    group_node_struct* found;
    MMI_BOOL rst = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    found = (group_node_struct *)SG_GET_NODE_FROM_ALL(group_id);
    /* check the group id is in the scenario tree. */
    if (found &&
        found->state != MMI_SCENARIO_STATE_CREATE)
    {
        rst = MMI_TRUE;
    }
    return rst;
}


MMI_ID mmi_frm_group_get_top_parent_group_id(MMI_ID group_id)
{
    return mmi_frm_get_root_app(group_id);
}


mmi_scenario_state_enum mmi_frm_group_get_state (MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    group_node_struct* found;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    found = (group_node_struct *)SG_GET_NODE_FROM_ALL(group_id);
    if (found)
    {
        return (mmi_scenario_state_enum)found->state;
    }
    else
    {
        return MMI_SCENARIO_STATE_NONE;
    }
}


mmi_ret mmi_frm_group_query_children_list(MMI_ID group_id, MMI_ID *in_table, S32 *table_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    group_node_struct   *group_node = NULL;
    base_node_struct    *tmp = NULL;
    S32                 idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FRM_HISTORY__
    if (group_id == GRP_ID_ROOT)
    {
        memset(in_table, 0, sizeof(MMI_ID)*(*table_size));
        idx = GetScreenCountInHistory() + 1;
        MMI_ASSERT(*table_size >= idx);
        *table_size = idx;
        /* Get active screen/group id */
        idx--;
        in_table[idx] = (MMI_ID)((g_scrn_mgr_cntx.active_group_id != GRP_ID_ROOT)?g_scrn_mgr_cntx.active_group_id: g_scrn_mgr_cntx.active_scrn_id);
        idx--;
        /* Get top node screen/group id of historyData[] */
        in_table[idx] = (MMI_ID)GetCurrScrnId();
        idx--;
        for (; idx >= 0; idx--)
        {
            GetPreviousScrnIdOf(in_table[idx+1], &in_table[idx]);
        }
        return MMI_RET_OK;
    }
    else
#endif /* __MMI_FRM_HISTORY__ */
    {
        group_node = (group_node_struct *)SG_GET_NODE_FROM_ROOT(group_id);
        memset(in_table, 0, sizeof(MMI_ID)*(*table_size));
        if (group_node && group_node->m_count <= *table_size)
        {
            *table_size = group_node->m_count;
            tmp = group_node->m_head;
            while (tmp)
            {
                in_table[idx] = (MMI_ID)(tmp->id);
                idx++;
                tmp = tmp->m_next;
            }
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_QUERY_CHILDREN_LIST, group_id, group_node, group_node->m_count, *table_size);
            return MMI_RET_OK;
        }
    }
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_QUERY_CHILDREN_LIST_ERR, group_id, group_node, (group_node)?(group_node->m_count):0, *table_size);
    *table_size = -1;
    return MMI_RET_ERR;
}


MMI_ID mmi_frm_group_get_app_name_by_tree(group_node_struct  *group_node, const char *app_name)
{
    while (group_node)
    {
        if (group_node->app_name)
        {
            if (0 == strcmp(group_node->app_name, app_name))
            {
                /* find out the matched app_name */
                return (MMI_ID)group_node->id;
            }
        }
        group_node = _GROUP(group_node->m_next);
    }
    return GRP_ID_INVALID;
}


MMI_ID mmi_frm_group_query_app_name(const char *app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID tmp_id = GRP_ID_INVALID;

    /* find the app_name in scenario_root first */
    tmp_id = mmi_frm_group_get_app_name_by_tree(_GROUP(shell.scenario_root.m_head), app_name);
    if(GRP_ID_INVALID == tmp_id)
    {
        tmp_id = mmi_frm_group_get_app_name_by_tree(_GROUP(shell.scenario_bg.m_head), app_name);
    }
    return tmp_id;
}

S32 mmi_frm_group_query_app_num(scenario_tree_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GROUP_TREE == type)
    {
        return shell.scenario_root.m_count;
    }
    else if (GROUP_BG_TREE == type)
    {
        return shell.scenario_bg.m_count;
    }
    else if (GROUP_DANGLE_TREE == type)
    {
        return shell.scenario_dangle.m_count;       
    }

    return 0;
}


mmi_ret mmi_frm_group_query_app_list(scenario_tree_type_enum type, group_node_struct **table, S32 table_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    group_node_struct   *group_node = NULL;
    S32                 i = 0, size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GROUP_TREE == type)
    {
        group_node = _GROUP(shell.scenario_root.m_head);
        size = shell.scenario_root.m_count;
    }
    else if (GROUP_BG_TREE == type)
    {
        group_node = _GROUP(shell.scenario_bg.m_head);
        size = shell.scenario_bg.m_count;
    }
    else if (GROUP_DANGLE_TREE == type)
    {
        group_node = _GROUP(shell.scenario_dangle.m_head);
        size = shell.scenario_dangle.m_count;       
    }
    if (size > table_size)
    {
        return MMI_RET_ERR;
    }

    /* clean the table content */
    memset(table, 0, sizeof(U32)*table_size);
    while (group_node)
    {
        table[i] = group_node;
        i++;
        group_node = _GROUP(group_node->m_next);
    }
    return MMI_RET_OK;
}


mmi_ret mmi_frm_send_event_to_group(MMI_ID group_id, mmi_group_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    group_node_struct* node;
    mmi_ret ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node = (group_node_struct *)SG_GET_NODE_FROM_ALL(group_id);
	if (node && node->proc && (node->proc != mmi_frm_dummy_proc))
    {
        ret = MMI_FRM_SEND_EVENT(evt, node->proc, node->user_data);
    }
    else
    {
        ret = MMI_RET_ERR;
    }
    
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_SEND_TO_EVT_TO_GROUP, group_id, evt->evt_id);
    return ret;
}


mmi_ret mmi_frm_post_event_to_group(MMI_ID group_id, mmi_group_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_post_evt_struct     post_evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&post_evt, EVT_ID_POST_TO_GROUP);
    memcpy(post_evt.data, evt, evt->size);
    post_evt.need_result = MMI_FALSE;
    post_evt.sender_gid  = GRP_ID_INVALID;
    post_evt.receiver_gid = group_id;
    MMI_FRM_POST_EVENT(&post_evt, mmi_scenario_external_post_proc, NULL);
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_POST_TO_EVT_TO_GROUP, group_id, evt->evt_id, G_POST_EVENT);
    return MMI_RET_OK;;

}



static mmi_ret mmi_frm_group_send_event (MMI_ID gid, mmi_group_event_struct *evt, MMI_BOOL is_send_to_caller)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    group_node_struct*  group_curr;
    mmi_proc_func     receiver_proc = NULL;
    void              *receiver_user_data = NULL;
    mmi_ret           ret = MMI_RET_ERR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if( (group_curr = _GROUP(SG_GET_NODE_FROM_ALL(gid))) == NULL)
        return ret;

    /* find receiver_proc and receiver_user_data */
    if (is_send_to_caller)
    {   
        if (group_curr->caller_proc)
        {
            /* if the group has caller_proc, we will send event to caller_proc in high priority */
            receiver_proc = group_curr->caller_proc;
            receiver_user_data = group_curr->caller_user_data;
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_SEND_EVENT, gid, 0, receiver_proc, receiver_user_data,G_SEND_EVENT_CALLER_PROC);
        }
        else
        {
            /* update caller, maybe is closed, so reset */
            group_curr->caller = find_caller(&shell.scenario_root, group_curr);
            if( group_curr->caller != NULL )
            {
                receiver_proc = group_curr->caller->proc;
                receiver_user_data = group_curr->caller->user_data;
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_SEND_EVENT, gid, group_curr->caller->id, receiver_proc, receiver_user_data,G_SEND_EVENT_CALLER);
            }
            else
            {
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_SEND_EVENT, gid, 0, 0, 0,G_SEND_EVENT_NO_CALLER);
            }
        }
    }
    else if(group_curr->parent)
    {
        receiver_proc = group_curr->parent->proc;
        receiver_user_data = group_curr->parent->user_data;
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_SEND_EVENT, gid, (U16)group_curr->parent->id, receiver_proc, receiver_user_data,G_SEND_EVENT_PARENT);
    }
    if (receiver_proc)
    {
        ret = MMI_FRM_SEND_EVENT(evt, receiver_proc, receiver_user_data);
    }
    return ret;
}


mmi_ret mmi_frm_group_send_event_ex (MMI_ID sender_gid, MMI_ID receiver_gid, mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret                 ret = MMI_RET_ERR;
    group_node_struct       *sender = _GROUP(SG_GET_NODE_FROM_ALL(sender_gid));
    group_node_struct       *receiver = _GROUP(SG_GET_NODE_FROM_ALL(receiver_gid));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Post event to gid */
    if (sender == NULL || receiver == NULL)
    {
        /* gid isn't exist */
        return ret;
    }

    if (receiver->proc)
    {
        ret = MMI_FRM_SEND_EVENT(evt, receiver->proc, receiver->user_data);
    }
    return ret;
}


mmi_ret mmi_frm_group_send_to_caller (MMI_ID group_id, mmi_group_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_SEND_TO_CALLER, group_id, (evt ? evt->evt_id : 0));
    return mmi_frm_group_send_event(group_id, evt, MMI_TRUE);
}


mmi_ret mmi_frm_group_send_to_parent (MMI_ID self_gid, mmi_group_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_SEND_TO_PARENT, (U16)self_gid, (evt ? evt->evt_id : 0));
    return mmi_frm_group_send_event(self_gid, evt, MMI_FALSE);
}


static void mmi_frm_group_post_event (MMI_ID self_gid, mmi_group_event_struct *evt, MMI_BOOL need_result, MMI_BOOL is_send_to_caller)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_post_evt_struct     post_evt = {0};
    group_node_struct       *sender = _GROUP(SG_GET_NODE_FROM_ALL(self_gid));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sender == NULL)
    {
        /* self_gid isn't exist */
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_POST_EVENT, (U16)self_gid, 0, 0, need_result, G_POST_EVENT_NO_SENDER);
        return;
    }

    if (is_send_to_caller && sender->caller_proc)
    {
        /* if the group has caller_proc, we will post event to caller_proc in high priority */
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_POST_EVENT, (U16)self_gid, 0, sender->caller_proc, need_result, G_POST_EVENT_CALLER_PROC);
        MMI_FRM_POST_EVENT(evt, sender->caller_proc, sender->caller_user_data);
        return;
    }

    MMI_ASSERT(evt->size <= MMI_SCENARIO_POST_GROUP_EVENT_MAX_SIZE<<2);

    if (is_send_to_caller)
    {
        /* update caller, maybe is closed, so reset */
        sender->caller = find_caller(&shell.scenario_root, sender);
        MMI_FRM_INIT_EVENT(&post_evt, EVT_ID_GROUP_POST_CALLER_NOTIFY);
        if (sender->caller)
        {
            post_evt.receiver_gid = sender->caller->id;
        }
    }
    else
    {
        MMI_FRM_INIT_EVENT(&post_evt, EVT_ID_GROUP_POST_PARENT_NOTIFY);
        if (sender->parent)
        {
            post_evt.receiver_gid = sender->parent->id;
        }
    }
    post_evt.sender_gid = self_gid;
    post_evt.need_result = need_result;
    memcpy(&post_evt.data[0], evt, evt->size);

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_POST_EVENT, (U16)self_gid, post_evt.receiver_gid, 0, need_result, G_POST_EVENT);
    MMI_FRM_POST_EVENT(&post_evt, mmi_scenario_external_post_proc, NULL);
}


void mmi_frm_group_post_event_ex (MMI_ID sender_gid, MMI_ID receiver_gid, mmi_event_struct *evt, U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_post_evt_struct     post_evt = {0};
    MMI_BOOL                need_result = (MMI_BOOL)(flag & MMI_SCENARIO_SEND_GROUP_EVENT_NEED_RESULT);
    group_node_struct       *sender = _GROUP(SG_GET_NODE_FROM_ALL(sender_gid));
    group_node_struct       *receiver = _GROUP(SG_GET_NODE_FROM_ALL(receiver_gid));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_POST_EVENT_EX, (U16)sender_gid, (U16)receiver_gid, (evt ? evt->evt_id : 0), need_result);
    /* Post event to gid */
    if (sender == NULL || receiver == NULL)
    {
        /* gid isn't exist */
        return;
    }
    /* the post event size should less than MMI_SCENARIO_POST_GROUP_EVENT_MAX_SIZE */
    MMI_ASSERT(evt->size <= MMI_SCENARIO_POST_GROUP_EVENT_MAX_SIZE<<2);

    MMI_FRM_INIT_EVENT(&post_evt, EVT_ID_APP_GROUP_POST_NOTIFY);
    post_evt.sender_gid = sender_gid;
    post_evt.receiver_gid = receiver_gid;
    
    post_evt.need_result = need_result;
    memcpy(&post_evt.data[0], evt, evt->size);

    MMI_FRM_POST_EVENT(&post_evt, mmi_scenario_external_post_proc, NULL);
}


void mmi_frm_group_post_to_caller (MMI_ID self_gid, mmi_group_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_POST_TO_CALLER, (U16)self_gid, (evt ? evt->evt_id : 0));
    mmi_frm_group_post_event(self_gid, evt, MMI_FALSE, MMI_TRUE);
}

void mmi_frm_group_post_to_parent (MMI_ID self_gid, mmi_group_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_POST_TO_PARENT, (U16)self_gid, (evt ? evt->evt_id : 0));
    mmi_frm_group_post_event(self_gid, evt, MMI_FALSE, MMI_FALSE);
}


void mmi_frm_group_post_to_caller_ex (MMI_ID self_gid, mmi_group_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_POST_TO_CALLER_EX, (U16)self_gid, (evt ? evt->evt_id : 0));
    mmi_frm_group_post_event(self_gid, evt, MMI_TRUE, MMI_TRUE);
}

void mmi_frm_group_post_to_parent_ex (MMI_ID self_gid, mmi_group_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_POST_TO_PARENT_EX, (U16)self_gid, (evt ? evt->evt_id : 0));
    mmi_frm_group_post_event(self_gid, evt, MMI_TRUE, MMI_FALSE);
}


void mmi_frm_close_active_empty_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    group_node_struct *group;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group = shell.active_group;
    if (group)
    {
        if (group->m_count == 0)
        {
            if (IsBitSet(group->attrib, NODE_ATTRIB_SMART_CLOSED_IDX))
			{
				mmi_frm_group_close(group->id);
			}
			else
			{
				MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_EMPTY_GROUP, group->id, group->attrib);
			}
        }
    }
}

/***************************************************************************** 
*  Scenario Screen
*****************************************************************************/
static U32 is_category57_screen(void)
{
    if (g_dm_data.s32CatId == MMI_CATEGORY57_ID ||
        g_dm_data.s32CatId == MMI_CATEGORY157_ID ||
        g_dm_data.s32CatId == MMI_CATEGORY257_ID ||
        g_dm_data.s32CatId == MMI_CATEGORY357_ID ||
        g_dm_data.s32CatId == MMI_CATEGORY657_ID)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

static void scrn_add_history(scrn_node_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    scrn_node_history_struct    *history = NULL;
    mmi_malloc_func_ptr         malloc_fp = history_buffer_malloc;
    mmi_mfree_func_ptr          mfree_fp = history_buffer_free;
    void*                       mem_user_data = SCENARIO_HISTORY_DATA;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (node->type == SCENARIO_SCRN_NODE || node->type == SCENARIO_TAB_PAGE_NODE || node->type == SCENARIO_TAB_NODE)
    {
        /*
         * we don't need to do add history in tab node.
         * Only SCENARIO_SCRN_NODE & SCENARIO_TAB_PAGE_NODE need to save history
         *
         * add history: tricky!! convert to history structure 
         */
        history = (scrn_node_history_struct*)&(node->mem_alloc);
    }

    /* Check if need to close category 57 serial screens */
    if (MMI_TRUE == is_category57_screen())
    {
        /* Category57Screen */
        CloseCategory57Screen();
    }
    if (history)
    {
        /* GUI buffer */
        if (history->gui_buf && history->gui_buf != (U8 *)&g_fake_gui_buf)
        {
            mfree_fp(history->gui_buf, mem_user_data);
        }

        history->gui_buf_size = GetCategoryHistorySize();
        if (history->gui_buf_size == 0)
        {
            /*
             * We will always alloacte gui buffer because a lot of applications use 
             * mmi_frm_scrn_get_active_gui_buf/mmi_frm_scrn_get_gui_buf to check 
             * if we entry the screen first time.
             */
			history->gui_buf = (U8 *)&g_fake_gui_buf;
        }
        if (history->gui_buf_size)
        {
            mem_user_data = (void *)GUI_BUFFER;
            history->gui_buf = (U8*)(malloc_fp(history->gui_buf_size, mem_user_data));
            memset(history->gui_buf, 0, history->gui_buf_size);
            GetCategoryHistory((U8*)history->gui_buf);
        }

        /* Input buffer */
        if (MMI_TRUE == is_category57_screen())
        {     
            
            if (node->mem_free)
            {
                mfree_fp = node->mem_free;
                mem_user_data = node->mem_user_data;
            }

            if (history->input_buf)
            {
                mfree_fp(history->input_buf, mem_user_data);
            }

            if (node->mem_alloc)
            {
                malloc_fp = node->mem_alloc;
                mem_user_data = node->mem_user_data;
            }
            else
            {
                mem_user_data = (void *)INPUT_BUFFER;
            }

            /* Category57Screen */
            history->input_buf_size = (U16)GetCategory57DataSize();
            if (history->input_buf_size > 0)
            {
                history->input_buf = (U16*)(malloc_fp(history->input_buf_size + ENCODING_LENGTH, mem_user_data));
                memset(history->input_buf, 0, history->input_buf_size);
                GetCategory57Data((U8*)history->input_buf);
            }
        }
        else
        {
            if (history->input_buf)
            {
                mfree_fp(history->input_buf, mem_user_data);
            }

            /* General CategoryScreen. */
            if (g_curr_input_buf)
            {
                if (g_curr_input_size == 0)
                {
                    history->input_buf_size = (U16)(mmi_wcslen((const WCHAR*)g_curr_input_buf) + 1) * ENCODING_LENGTH;
                }
                else
                {
                    history->input_buf_size = g_curr_input_size;
                }
                if (history->input_buf_size > 0)
                {
                    mem_user_data = (void *)INPUT_BUFFER;
                    history->input_buf = (WCHAR*)(malloc_fp(history->input_buf_size, mem_user_data));
                    memset(history->input_buf, 0, history->input_buf_size);
                    if (g_curr_input_size)
                    {
                        /* If assign the input buffer size, we use copy this size from the input buffer */
                        memcpy((U8*)history->input_buf, (U8*)g_curr_input_buf, g_curr_input_size);
                    }
                    else
                    {
                        /* If not assign the input buffer size, we assume the input buffer pointer is USC2 string */
                        mmi_wcscpy(history->input_buf, (const WCHAR*)g_curr_input_buf);
                    }
                }
            }
        }
        MMI_TRACE(MMI_FW_TRC_G1_FRM,
            MMI_FRM_SCENARIO_ADD_HISTORY,
            history->gui_buf,
            history->gui_buf_size,
            history->input_buf,
            history->input_buf_size);
        g_curr_input_buf = NULL;
        g_curr_input_size = 0;
    }
}


static void scrn_free_history(scrn_node_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mfree_func_ptr  mfree_fp = history_buffer_free;
    void                *mem_user_data = SCENARIO_HISTORY_DATA;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (node->type == SCENARIO_SCRN_NODE || node->type == SCENARIO_TAB_PAGE_NODE)
    {
		if (node->gui_buf == (U8 *)&g_fake_gui_buf)
		{
			node->gui_buf = NULL;
		}
        else if (node->gui_buf)
        {
            mfree_fp(node->gui_buf, mem_user_data);
            node->gui_buf = NULL;
        }

        if (node->input_buf)
        {
            if (node->mem_free)
            {
                mfree_fp = node->mem_free;
                mem_user_data = node->mem_user_data;
            }
            mfree_fp(_SCRN(node)->input_buf, mem_user_data);
            node->input_buf = NULL;
        }
    }
}


static void scrn_inactive_internal_process(scrn_node_struct *node, U32 forward_flag)
{
    U8 count = 0;
    mmi_scrn_essential_struct _data = {0};
    
    /* Failsafe common function before exit screen */
    UI_common_screen_pre_exit();

    for (count = 0; count < MAX_SUB_MENUS; count++)
    {
       subMenuDataPtrs[count] = subMenuData[count];
    }
        
    _data.group_id = node->parent->id;
#ifndef __MMI_NOT_TAB_SUPPORT__
    if (_IS_TAB(node))
    {
       _data.tab_id =  (shell.active_tab) ? shell.active_tab->id : node->id;
       _data.tab_id = (MMI_ID)_data.tab_id;
    }
    else
#endif /* __MMI_NOT_TAB_SUPPORT__ */
       _data.tab_id = SCR_ID_INVALID;
       
    _data.scrn_id = (MMI_ID)node->id;
    _data.user_data = node->user_data;

    MMI_TRACE(MMI_FW_TRC_G1_FRM, 
        MMI_FRM_SCENARIO_SCRN_EXIT,
        (U16)_data.group_id,
        (U16)_data.scrn_id,
        (U16)_data.tab_id,
        node->user_data,
        node->exit_proc);
    if ( node->exit_proc )
    {
        node->exit_proc(&_data);
    }

    /* If evt->state is forward, we check if need to save this screen data in the history */
    if ( MMI_SCENARIO_STATE_FORWARD_IDX == forward_flag )
    {
        if (IsBitSet(node->attrib, NODE_ATTRIB_AUTO_ADD_HISTORY_IDX)) 
        {
            ResetBit(node->attrib, NODE_ATTRIB_FREE_NODE_IDX);
            scrn_add_history(node);
        }        
    }
    else if( MMI_SCENARIO_STATE_BACKWARD_IDX == forward_flag )
    {
         /* Check if need to close category 57 serial screens */
        if (MMI_TRUE == is_category57_screen())
        {
            /* Category57Screen */
            CloseCategory57Screen();
        }
    }
    
    g_curr_input_buf = NULL;
    g_curr_input_size = 0;

    /* Failsafe common screen exit function   */
    UI_common_screen_exit();
}


#define INVALID_DIRECT_TYPE 0xff

static void scrn_inactive(scrn_node_struct *node, mmi_scenario_evt_struct* evt)
{
#ifndef __MMI_NOT_TAB_SUPPORT__
    tab_page_node_struct *child;
#endif /* __MMI_NOT_TAB_SUPPORT__ */
    U32 forward_flag = INVALID_DIRECT_TYPE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* If the node is active state, we need to execute inactive process */
    MMI_TRACE(PLUTO_FW_TRC_SCREEN,
        MMI_FRM_SCENARIO_SCRN_INACTIVE,
        node,
        node->state,
        node->attrib,
        node->type,
        shell.state);
    if (IsBitSet(node->state, MMI_SCENARIO_STATE_ACTIVE_IDX))
    {
        SetBit(shell.state, MMI_SCENARIO_STATE_SCRN_EXIT_IDE);
        mmi_frm_dss_clear_backup_string();       

    #ifndef __MMI_NOT_TAB_SUPPORT__
        if (_IS_TAB(node))
        {
            /* If it is in inactive tab process, we need to inactive page first to save page history data. */
            child = _TAB_PAGE(_TAB(node)->m_tail);
            MMI_ASSERT(_IS_TAB_PAGE(child));

            scrn_inactive((scrn_node_struct*)child, evt);
            if (IsBitSet(evt->state, MMI_SCENARIO_STATE_BACKWARD_IDX))
            {
                /* It is in backward case, and we should keep the current page index in tab node */
                _TAB(node)->cur_sel_index = _TAB_PAGE(child)->index;
            }
        }
    #endif /* __MMI_NOT_TAB_SUPPORT__ */

        ResetBit(node->state, MMI_SCENARIO_STATE_ACTIVE_IDX);
        SetBit(node->state, MMI_SCENARIO_STATE_INACTIVE_IDX);
        if (IsBitSet(evt->state, MMI_SCENARIO_STATE_FORWARD_IDX))
        {
            SetBit(node->attrib, NODE_ATTRIB_FREE_NODE_IDX);
            forward_flag = MMI_SCENARIO_STATE_FORWARD_IDX;
        }
        else if (IsBitSet(evt->state, MMI_SCENARIO_STATE_BACKWARD_IDX))
        {
            ResetBit(node->attrib, NODE_ATTRIB_FREE_NODE_IDX);
            forward_flag = MMI_SCENARIO_STATE_BACKWARD_IDX;
        }
        
        scrn_inactive_internal_process(node,forward_flag);

        /* change the screen */
    #ifdef __TST_TRACE_ENABLED__
        mmi_frm_event_set_dump_history_flag(MMI_TRUE);
    #endif
        mmi_frm_key_event_screen_switch_action();   

#ifdef __COSMOS_MMI_PACKAGE__
	mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
#else
        mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);
#endif
        /* it clears all the key handlers, registered by the current screen */
        ClearInputEventHandler(MMI_DEVICE_KEY);
    #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
        mmi_tm_reset_imageid_image_header_pool();
    #ifdef __MMI_DLT_CACHE_SUPPORT__
        mmi_tm_clear_ondemand_cache();
    #endif 
    #endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
        /* MTK end */

        SetBit(node->state, MMI_SCENARIO_STATE_INACTIVE_IDX);

    #ifndef __MMI_NOT_TAB_SUPPORT__
        if (IsBitSet(shell.state, MMI_SCENARIO_STATE_BACKWARD_IDX) &&
            _IS_TAB_PAGE(node) && shell.active_tab)
        {
            SetBit(shell.active_tab->state, MMI_SCENARIO_STATE_INACTIVE_IDX);
        }

        if (_IS_TAB(node) && shell.active_tab == _TAB(node))
        {
            shell.active_tab = NULL;
        }
    #endif /* __MMI_NOT_TAB_SUPPORT__ */
    
        ResetBit(shell.state, MMI_SCENARIO_STATE_SCRN_EXIT_IDE);
        shell.active_scrn = NULL;
        if (IsBitSet(node->attrib, NODE_ATTRIB_FREE_NODE_IDX))
        {
            /* If we don't add the screen in the history, we could deinit immediately. */
            _EXECUTE_NODE_DEINIT(_NODE(node), evt);
            if (node->parent && 
                IsBitSet(node->parent->attrib, NODE_ATTRIB_SMART_CLOSED_IDX) && 
                node->parent->m_count == 0)
            {				
				mmi_frm_group_close((MMI_ID)node->parent->id);				
            } 
        }        
    }
}


static void scrn_active(scrn_node_struct *node, mmi_scenario_evt_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_NOT_TAB_SUPPORT__
    base_node_struct     *changed_node = NULL;
    tab_page_node_struct *child = NULL;
#endif /* __MMI_NOT_TAB_SUPPORT__ */    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * If the node isn't in active state, we execute the active process.
     * We leave the current screen first, and then execute this screen's
     * active process.
     */
    
    MMI_TRACE(PLUTO_FW_TRC_SCREEN, 
        MMI_FRM_SCENARIO_SCRN_ACTIVE,
        node,
        node->state,
        node->attrib,
        node->type,
        shell.state);
    if (IsBitSet(evt->state, MMI_SCENARIO_STATE_FORWARD_IDX))
    {
        /* node parent should be active first */
        if (!IsBitSet(node->parent->state, MMI_SCENARIO_STATE_ACTIVE_IDX))
        {
            return;
        }
    }

    shell.targ_node = (base_node_struct*)node;

    if (!IsBitSet(node->state, MMI_SCENARIO_STATE_ACTIVE_IDX))
    {
        set_active_scrn_id((MMI_ID)node->parent->id, (MMI_ID)(node->id));

        /* execute the current screen inactive process */
        if (IsBitReset(shell.state, MMI_SCENARIO_STATE_BACKWARD_IDX))
        {
            /*
             * In forward case, we may need to inactive current screen in scrn_active() first.
             * In backward case, we will inactive current screen in scrn_close().
             */
         #ifndef __MMI_NOT_TAB_SUPPORT__
            if (_IS_SCRN(node) && shell.active_tab)
            {
                _EXECUTE_NODE_INACTIVE(shell.active_tab, evt);
            }
            else
         #endif /* __MMI_NOT_TAB_SUPPORT__ */
            if ((_IS_SCRN(node) || _IS_TAB(node)) &&
                     shell.active_scrn)
            {
                _EXECUTE_NODE_INACTIVE(shell.active_scrn, evt);
            }
        #ifndef __MMI_NOT_TAB_SUPPORT__
            else if (_IS_TAB_PAGE(node) && shell.active_tab)
            {
                if (IsBitReset(shell.active_tab->state, MMI_SCENARIO_STATE_FIRST_ENTRY_IDX) &&
                    shell.active_scrn && _IS_TAB_PAGE(shell.active_scrn))
                {
                    MMI_ASSERT(_IS_TAB_PAGE(shell.active_scrn));
                    scrn_inactive(shell.active_scrn, evt);
                }
            }
        #endif /* __MMI_NOT_TAB_SUPPORT__ */
        }
        shell.targ_node = NULL;
        set_exit_scrn_id((MMI_ID)node->parent->id, (MMI_ID)node->id);

        /* execute the new screen active process */
        /* disable small screen flatten for full-screen APPs */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        {
            dm_enable_small_screen_flatten();
        }

        /* update active screen */
        
        shell.active_group = node->parent;
        shell.active_scrn = node;
        MMI_TRACE(
            MMI_FW_TRC_G1_FRM,
            MMI_FRM_SCENARIO_CHANGE_ACTIVE_SCRN,
            shell.active_group->id,
            (MMI_ID)shell.active_scrn->id
            );
        /* check to handle small screen mechanism */
        if (IsBitSet(node->attrib, NODE_ATTRIB_SMALL_SCREEN_IDX) && 
            (IsBitSet(shell.state, MMI_SCENARIO_STATE_BACKWARD_IDX) 
              || (IsBitSet(shell.state, MMI_SCENARIO_STATE_DELETE_REQ_IDX))))     // for tab 
        {
        #ifdef __MMI_FRM_HISTORY__
            mmi_frm_redraw_bg();
            mmi_set_redrawing_bk_screens_status(MMI_HIST_SMALLSCREEN_NONE);
        #else
            mmi_frm_redraw_bg_ex();
        #endif /* __MMI_FRM_HISTORY__ */
        }

        /*
         * If we first entry the screen, we execute init process.
         * Else, we execute active process
         */
        ResetBit(node->state, MMI_SCENARIO_STATE_INACTIVE_IDX);
        SetBit(node->state, MMI_SCENARIO_STATE_ACTIVE_IDX);
    #ifdef __MMI_TOUCH_SCREEN__
        wgui_register_general_pen_handler();
    #endif

        if (IsBitSet(shell.state, MMI_SCENARIO_STATE_BACKWARD_IDX))
        {
            /* If it is backward process, we disable NODE_ATTRIB_AUTO_ADD_HISTORY_IDX */
            ResetBit(node->attrib, NODE_ATTRIB_AUTO_ADD_HISTORY_IDX);
        }

    #ifndef __MMI_NOT_TAB_SUPPORT__
        /* emit the active event to the screen */
        if (_IS_TAB(node) && IsBitSet(shell.state, MMI_SCENARIO_STATE_BACKWARD_IDX) && IsBitSet(node->state, MMI_SCENARIO_STATE_FIRST_ENTRY_IDX))
        {
            /*
             * In goback process, the application changes the general screen to tab screen.
             * We don't need to invoke tab entry_proc again because we aleady finished tab entry_proc.
             */
            ResetBit(node->state, MMI_SCENARIO_STATE_FIRST_ENTRY_IDX);
            ResetBit(node->attrib, NODE_ATTRIB_CHANGE_NODE_TYPE_IN_GOBACK_IDX);
            if (node->entry_proc)
            {
                /* We need to check should be enable NODE_ATTRIB_AUTO_ADD_HISTORY_IDX when change screen type */
                SetBit(node->attrib, NODE_ATTRIB_AUTO_ADD_HISTORY_IDX);
            }
        }
        else
        {
     #endif /* __MMI_NOT_TAB_SUPPORT__ */

#ifdef __MMI_LCM_PRIMITIVE_FLUSH__
                mmi_frm_screen_change();
#endif /* __MMI_LCM_PRIMITIVE_FLUSH__*/

            if (IsBitReset(node->state, MMI_SCENARIO_STATE_FIRST_ENTRY_IDX))
            {
                node_exec_entry_proc(node);
            }
            else if (IsBitSet(node->attrib, NODE_ATTRIB_CHANGE_NODE_TYPE_IN_GOBACK_IDX))
            {
                node_exec_entry_proc(node);
                
                if (IsBitSet(node->attrib, NODE_ATTRIB_CHANGE_NODE_TYPE_IN_GOBACK_IDX))
                {
                    ResetBit(node->attrib, NODE_ATTRIB_CHANGE_NODE_TYPE_IN_GOBACK_IDX);
                    ResetBit(node->state, MMI_SCENARIO_STATE_FIRST_ENTRY_IDX);
                }
            }
     #ifndef __MMI_NOT_TAB_SUPPORT__
        }   

        if (IsBitSet(shell.state, MMI_SCENARIO_STATE_BACKWARD_IDX) &&
            IsBitSet(node->attrib, NODE_ATTRIB_CHANGE_NODE_TYPE_IN_GOBACK_IDX))
        {
            /* This node type is change in goback process, and we need to active changed node later */
            changed_node = node->m_next;
            SG_REMOVE_FREE_NODE(node->parent, node);
            
            if (shell.active_scrn == node)
            {
                shell.active_scrn = NULL;
            }
            if (changed_node)
            {
                _POST_INTERNAL_SCENARIO_EVT(changed_node->parent->id, changed_node->id, POST_EXECUTE_ACTIVE, evt);
            }
        }  
        else
        {
            if (_IS_TAB(node))
            {
                shell.active_tab = _TAB(node);
                wgui_horizontal_tab_bar_set_first_displayed_item (_TAB(node)->first_item_index);
                wgui_horizontal_tab_bar_set_use_pen_switch(_TAB(node)->use_pen_switch);
                /* tab is dummy screen and execute page active process */
                adaptor_show_dummy_screen();

                child = _TAB_PAGE(move_node_to_tail(_NODE(node), NULL, _TAB(node)->cur_sel_index, MMI_TRUE));
                if (child && child->index == _TAB(node)->cur_sel_index)
                {
                    scrn_active((scrn_node_struct*)child, evt);
                }
            }
        }
    #endif    /* __MMI_NOT_TAB_SUPPORT__ */   
    }
    else
    {
        ResetBit(node->state, MMI_SCENARIO_STATE_INACTIVE_IDX);
        SetBit(node->state, MMI_SCENARIO_STATE_ACTIVE_IDX);
    }
}


static void scrn_post_active(scrn_node_struct *node, mmi_scenario_evt_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    scrn_active(node, evt);
}

void group_status_backup(shell_struct *backup_shell_ptr)
{
    *backup_shell_ptr = shell;
    
    //reset the active_scrn;
    //Todo: may need to change fxn name.
    shell.active_scrn = NULL;
}

void group_status_restore(shell_struct *backup_shell_ptr)
{
    /* Clean up the active scrn before resotre */
    /* Note: the condition that th fg is hisotory node, and the previous bg is scenario node,
       the adaptor exit function will be invoke during executeCurrExitHandler/entryNewScreen/go back history. 
       However, the timing of the adpator exit function be invoked is after sheel.active_scrn has been restored (mmi_frm_redraw), 
       the pointer of previous bg will be lost. 
       So, we add clean up code bellow to make sure the topmost fg has been clean.
   */
    group_node_struct dangle;
    if (shell.active_scrn)
    {    
        scrn_redraw_clean(shell.active_scrn);
    }

    //we allow create/close group in redraw, need keep the dangle info
    dangle = shell.scenario_dangle;
    shell = *backup_shell_ptr;
    shell.scenario_dangle = dangle;
}

static mmi_ret execute_scrn_leave(scrn_node_struct *node, mmi_scenario_evt_struct* evt, mmi_scenario_evt_enum evt_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret result = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = interaction(evt_id, _NODE(node), evt);

    if (result != MMI_RET_OK)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM,
            MMI_FRM_SCENARIO_FORBID_CLOSE,
            node->parent->id,
            (MMI_ID)node->id,
            node->proc);
    }
    return result;
}

static void scrn_hide(scrn_node_struct *node, mmi_scenario_evt_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 temp_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsBitSet(node->state, MMI_SCENARIO_STATE_ACTIVE_IDX))
    {
        temp_id = get_prev_scrn_id((base_node_struct *)node);
        if (g_scrn_mgr_cntx.active_scrn_id == g_scrn_mgr_cntx.exit_scrn_id)
        {
             set_active_scrn_id((U16)(temp_id >> 16), (U16)temp_id);
        }
        scrn_inactive(node, evt);        
        shell.active_scrn = NULL;
    }
    interaction(EVT_ID_SCRN_HIDE, _NODE(node), evt);

}

static void scrn_unhide(scrn_node_struct *node, mmi_scenario_evt_struct* evt)
{
    interaction(EVT_ID_SCRN_UNHIDE, _NODE(node), evt);
    if (is_in_tail_serial(&shell.scenario_root, _NODE(node)))
    {
        scrn_active(node, evt);
    }
}

static mmi_ret scrn_close(scrn_node_struct *node, mmi_scenario_evt_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret result = MMI_RET_OK;
    MMI_BOOL in_end_key_process = MMI_FALSE;
    base_node_struct *previous = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (_IS_TAB_PAGE(node) && shell.active_tab == NULL)
    {
        /* if we want to close the page, the active screen must be active tab */
        return result;
    }

    
    /*
     * If the node isn't in active state, we execute the active process.
     * We leave the current screen first, and then execute this screen's
     * active process.
     */
    if (IsBitSet(node->attrib, NODE_ATTRIB_IN_END_KEY_PROCESS_IDX))
    {
        in_end_key_process = MMI_TRUE;
    }

    /* may change the scenario tree */
#ifdef __TST_TRACE_ENABLED__
    mmi_frm_event_set_dump_history_flag(MMI_TRUE);
#endif
    if (!IsBitSet(node->state, MMI_SCENARIO_STATE_ACTIVE_IDX))
    {
        /* execute the delete process directly */
        if (IsBitReset(node->attrib, NODE_ATTRIB_NOT_ALLOW_DEL))
        {
            result = execute_scrn_leave(
                        node, 
                        evt, 
                        (in_end_key_process) ? EVT_ID_SCRN_DELETE_REQ_IN_END_KEY : EVT_ID_SCRN_DELETE_REQ);
        }
        else
        {
            ResetBit(node->attrib, NODE_ATTRIB_NOT_ALLOW_DEL);
            result = MMI_RET_ERR;
        }

        if (result == MMI_RET_OK)
        {
            /*
             * We don't invoke screen exit_proc in delete process 
             * and execute deinit process directly. 
             * It follws the original screen-history behavior.
             */
            _EXECUTE_NODE_DEINIT(_NODE(node), evt);
        }
        else
        {
            ResetBit(node->attrib, NODE_ATTRIB_IN_END_KEY_PROCESS_IDX);
        #ifdef __MMI_FRM_HISTORY__
            shell.is_allow_delete_adapor_node = 0;
        #endif
        }
    }
    else
    {
        U32 temp_id;
        /* execute the goback process */
        
        /* find the previous screen node first */
        previous = find_prev_node(_NODE(node));

        SetBit(node->state, MMI_SCENARIO_STATE_BACKWARD_IDX);
        /*
         * indicate the current screen (active screen) to close 
         * If attrib is set NODE_ATTRIB_MULTI_CLOSE_ACTIVE_SCRN_IDX,
         * we already sent EVT_ID_SCRN_GOBACK to leave_proc in mmi_frm_scrn_multiple_close.
         */
        if (IsBitReset(node->attrib, NODE_ATTRIB_MULTI_CLOSE_ACTIVE_SCRN_IDX))
        {
            if (IsBitReset(node->attrib, NODE_ATTRIB_NOT_ALLOW_DEL))
            {    
                result = execute_scrn_leave(
                    node, 
                    evt, 
                    (in_end_key_process) ? EVT_ID_SCRN_GOBACK_IN_END_KEY : EVT_ID_SCRN_GOBACK);
            }
            else
            {
                ResetBit(node->attrib, NODE_ATTRIB_NOT_ALLOW_DEL);
                result = MMI_RET_ERR;                
            }
        }
        ResetBit(node->attrib, NODE_ATTRIB_MULTI_CLOSE_ACTIVE_SCRN_IDX);

        /*
         * We will invoke screen exit_proc in goback process. 
         * It follws the original screen-history behavior.
         */
        if (result == MMI_RET_OK)
        {
            temp_id = get_prev_scrn_id((base_node_struct *)node);
            if (g_scrn_mgr_cntx.active_scrn_id == g_scrn_mgr_cntx.exit_scrn_id)
            {
                if(temp_id == GRP_ID_ROOT || ((MMI_ID)(temp_id >> 16))!= g_scrn_mgr_cntx.active_group_id)
                    temp_id = SCR_ID_INVALID;
                set_active_scrn_id(g_scrn_mgr_cntx.active_group_id, (U16)temp_id);
            }
            scrn_inactive(node, evt);


            _EXECUTE_NODE_DEINIT(_NODE(node), evt);

            /* indicate the previous screen to active */
            if (previous && 
                IsBitReset(previous->parent->state, MMI_SCENARIO_STATE_BACKWARD_IDX))
            {
                /*
                 * If current process isn't the group goback process and we found the previous node,
                 * we active the same level previous node.
                 */
                if (_IS_GROUP(previous))
                {
                    _POST_INTERNAL_SCENARIO_EVT(previous->id, SCR_ID_INVALID, POST_EXECUTE_ACTIVE, evt);
                }
                else
                {
                    _POST_INTERNAL_SCENARIO_EVT(previous->parent->id, previous->id, POST_EXECUTE_ACTIVE, evt);
                }
            }
            else
            {
                set_exit_scrn_id(g_scrn_mgr_cntx.active_group_id, SCR_ID_INVALID);
            }
        }
        else
        {
            ResetBit(node->attrib, NODE_ATTRIB_IN_END_KEY_PROCESS_IDX);
            ResetBit(node->state, MMI_SCENARIO_STATE_BACKWARD_IDX);
        #ifdef __MMI_FRM_HISTORY__
            shell.is_allow_delete_adapor_node = 0;
        #endif
        }
    }
    return result;
}


static scrn_node_struct* create_new_scrn(MMI_ID parent_id, MMI_ID id, mmi_scrn_func entry_proc, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    scrn_node_struct *screen = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    screen = _SCRN(SG_GET_NODE_FROM_ROOT(_SCRN_ID(parent_id, id)));
    if ((screen && screen->type != SCENARIO_SCRN_NODE) ||
        screen == NULL)
    {
        screen = _MMI_MEM_ALLOC(sizeof(scrn_node_struct), SCENARIO_SCRN_NODE);

        
        screen->type = SCENARIO_SCRN_NODE;
        screen->entry_proc = entry_proc;
        if (entry_proc)
        {
            SetBit(screen->attrib, NODE_ATTRIB_AUTO_ADD_HISTORY_IDX);
        }
        screen->proc = mmi_frm_dummy_proc;
        screen->user_data = user_data;
        screen->id = _SCRN_ID(parent_id, id);
        screen->parent = (group_node_struct *)SG_GET_NODE_FROM_ROOT(parent_id);
    }

    return screen;
}


static MMI_BOOL scrn_node_enter (
                    MMI_ID parent_id, 
                    MMI_ID scrn_id, 
                    mmi_scrn_func exit_proc, 
                    mmi_scrn_func entry_proc, 
                    mmi_frm_scrn_type_enum scrn_type,
                    mmi_frm_tab_struct *tab_pages_info_array, 
                    U8 tab_pages_count, 
                    U8 sel_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_created_new_node = MMI_FALSE;
    mmi_scenario_evt_struct evt = {0};
    scrn_node_struct *new_node = NULL;
#ifndef __MMI_NOT_TAB_SUPPORT__
    scrn_node_struct *org_node = NULL;
    tab_page_node_struct *page = NULL;
#endif /* __MMI_NOT_TAB_SUPPORT__ */
    group_node_struct *parent = NULL;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parent = (group_node_struct *)SG_GET_NODE_FROM_ROOT(parent_id);
    if (parent)
    {
        /* If the parent is valid, we allow to entry new screen */
        new_node = _SCRN(SG_GET_CHILD(parent, _SCRN_ID(parent_id, scrn_id)));
        if ((shell.state == MMI_SCENARIO_STATE_NONE ) /* not post condition */
            &&(is_in_active_group_serial(parent_id) == NULL)            /* not active group serial */
            && (entry_proc == NULL || scrn_type == MMI_FRM_FG_ONLY_SCRN))    /* don't need enter to history */ 
        {
            /* first_enter + scrn_enter, and set entry proc as null when scrn enter */
            if (new_node != NULL)
			{
				SetBit(new_node->state, MMI_SCENARIO_STATE_INACTIVE_IDX);				
			}
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_NODE_ENTER,\
                parent_id, (MMI_ID)scrn_id, scrn_type, ERR_S_ENTER_INACTIVE_GROUP_WITHOUT_ENTER_PROC);
            return MMI_FALSE;
        }

        if (new_node == NULL)
        {
            is_created_new_node = MMI_TRUE;
        #ifndef __MMI_NOT_TAB_SUPPORT__
            if (scrn_type == MMI_FRM_TAB)
            {
                new_node = _SCRN(create_new_tab(parent_id, scrn_id, entry_proc, NULL, tab_pages_info_array, tab_pages_count, sel_idx));
            }
            else if (scrn_type == MMI_FRM_TAB_PAGE)
            {
                MMI_ASSERT(shell.active_tab);
                page = _TAB_PAGE(shell.active_tab->m_tail);
                while (page)
                {
                    if (page->id == _SCRN_ID(parent_id, scrn_id))
                    {
                        new_node = _SCRN(page);
                        break;
                    }
                    page = _TAB_PAGE(page->m_prev);
                }
                MMI_ASSERT(new_node);
            }        
            else
            {
        #endif /* __MMI_NOT_TAB_SUPPORT__ */
                if(mmi_frm_scenario_is_redrawing())
                {
                    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_NODE_ENTER,\
                            (MMI_ID)parent_id, (MMI_ID)scrn_id, scrn_type, ERR_ENTER_DIFF_SCRN_IN_REDRAWING);
                    return MMI_FALSE;

                }
                /* During redrawing, the screen should be in the history */
                //MMI_ASSERT(mmi_frm_scenario_is_redrawing() == MMI_FALSE);
                new_node = create_new_scrn(parent_id, scrn_id, entry_proc, NULL);
        #ifndef __MMI_NOT_TAB_SUPPORT__
            }
        #endif /* __MMI_NOT_TAB_SUPPORT__ */
        }
        #ifndef __MMI_NOT_TAB_SUPPORT__
        else
		{
			if (scrn_type == MMI_FRM_TAB && new_node->type == SCENARIO_TAB_NODE && _TAB(new_node)->page_count != tab_pages_count)
			{
				change_tab_info(_TAB(new_node), tab_pages_info_array, tab_pages_count, sel_idx);
			}
		}
        #endif /* __MMI_NOT_TAB_SUPPORT__ */
        
#ifdef __MMI_SCENARIO_SMALL_SCREEN_SUPPORT_EXIT_CHANGE__

        new_node->exit_proc = exit_proc;

        if (mmi_frm_scenario_is_redrawing() == MMI_FALSE) 
        {
            /* We need to set the page exit funtion here because we may return first in some situations. */
            new_node->entry_proc = entry_proc;
        }
        else
        {   
            SetBit(new_node->attrib, NODE_ATTRIB_REDRAW_ENTER_IDX);
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_NODE_ENTER,\
                parent_id, (MMI_ID)scrn_id, scrn_type, SCENARIO_S_ENTER_REDRAW);
            return MMI_TRUE;
        }
#else
        /* Avoid to break orig exit and entry during redraw in some extrem condition that enter a same node with several different entry/exit function. */
        if (mmi_frm_scenario_is_redrawing() == MMI_FALSE) 
        {
            /* We need to set the page exit funtion here because we may return first in some situations. */
            new_node->exit_proc = exit_proc;
            new_node->entry_proc = entry_proc;
        }
        else
        {   
            SetBit(new_node->attrib, NODE_ATTRIB_REDRAW_ENTER_IDX);
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_NODE_ENTER,\
                (MMI_ID)parent_id, (MMI_ID)scrn_id, scrn_type, SCENARIO_S_ENTER_REDRAW);
            return MMI_TRUE;
        }
#endif
        if (new_node->entry_proc)
        {
            /* We need to set NODE_ATTRIB_AUTO_ADD_HISTORY_IDX again because we will clean this attribute in goback process. */
            SetBit(new_node->attrib, NODE_ATTRIB_AUTO_ADD_HISTORY_IDX);
        }
        if (scrn_type == MMI_FRM_FG_ONLY_SCRN)
        {
            ResetBit(new_node->attrib, NODE_ATTRIB_AUTO_ADD_HISTORY_IDX);
        }
    #ifdef __TST_TRACE_ENABLED__  
        mmi_frm_event_set_dump_history_flag(MMI_TRUE);
    #endif
        /* Check if the active screen is the same with this new node */
        if (shell.active_scrn)
        {
            if (IsBitSet(shell.state, MMI_SCENARIO_STATE_BACKWARD_IDX))
            {
                if (shell.active_scrn->id == new_node->id)
                {
            #ifndef __MMI_NOT_TAB_SUPPORT__
                    /* In goback process, new_node scrn id is the same, but the scrn type is different. */
                    /* Check if the screen node change the type in goback process. */
                    if (scrn_type == MMI_FRM_TAB && !_IS_TAB(new_node))
                    {
                        /*
                         * The screen node changes to tab frame screen in goback process.
                         * non-tab scrn -> dummy scrn -> close(goback) -> tab scrn
                         */
                        org_node = new_node;
                        SetBit(org_node->attrib, NODE_ATTRIB_CHANGE_NODE_TYPE_IN_GOBACK_IDX);
                        new_node = _SCRN(create_new_tab(parent_id, scrn_id, entry_proc, org_node->user_data, tab_pages_info_array, tab_pages_count, sel_idx));
                        insert_node_by_handle(parent,NULL,_NODE(new_node),MMI_FRM_NODE_AT_LATEST_FLAG);
                        SetBit(new_node->attrib, NODE_ATTRIB_CHANGE_NODE_TYPE_IN_GOBACK_IDX);
                        SetBit(new_node->state, MMI_SCENARIO_STATE_FIRST_ENTRY_IDX);
                        SetBit(new_node->state, MMI_SCENARIO_STATE_INACTIVE_IDX);
                        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_NODE_ENTER,\
                            parent_id, (MMI_ID)scrn_id, scrn_type, SCENARIO_S_SCRN_TO_TAB);

                        return MMI_FALSE;
                    }
                    else if (_IS_TAB(new_node) && scrn_type != MMI_FRM_TAB)
                    {
                        /*
                         * The screen node changes to tab frame screen in goback process.
                         * tab scrn -> dummy scrn -> close(goback) -> non-tab scrn
                         */
                        org_node = new_node;
                        SetBit(org_node->attrib, NODE_ATTRIB_CHANGE_NODE_TYPE_IN_GOBACK_IDX);
                        new_node = _SCRN(create_new_scrn(parent_id, scrn_id, entry_proc, NULL));
                        insert_node_by_handle(parent,NULL,_NODE(new_node),MMI_FRM_NODE_AT_LATEST_FLAG);
                        SetBit(new_node->attrib, NODE_ATTRIB_CHANGE_NODE_TYPE_IN_GOBACK_IDX);
                        SetBit(new_node->state, MMI_SCENARIO_STATE_FIRST_ENTRY_IDX);
                        SetBit(new_node->state, MMI_SCENARIO_STATE_INACTIVE_IDX);
                        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_NODE_ENTER,\
                            parent_id, (MMI_ID)scrn_id, scrn_type, SCENARIO_S_TAB_TO_SCRN);    

                        return MMI_FALSE;
                    }
                    else/* if (IsBitSet(new_node->attrib, NODE_ATTRIB_CHANGE_NODE_TYPE_IN_GOBACK_IDX)) */
                    {
                #endif /* __MMI_NOT_TAB_SUPPORT__ */
                        /*
                         * case 1:
                         * If the active screen is the same with new_node, we return MMI_TRUE directly.
                         * case 2:
                         * If scrn type is changed in goback process, we will enter the new screen in post event.
                         * When we enter this kind of screen, we return MMI_TRUE directly.
                         */
                        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_NODE_ENTER,\
                            parent_id, (MMI_ID)scrn_id, scrn_type, SCENARIO_S_ENTER_BW);
                        return MMI_TRUE;
                #ifndef __MMI_NOT_TAB_SUPPORT__
                    }
                #endif /* __MMI_NOT_TAB_SUPPORT__ */
                }
            }
            else
            {
                if (shell.active_scrn->id == new_node->id)
                {
                    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_NODE_ENTER,\
                        parent_id, (MMI_ID)scrn_id, scrn_type, ERR_S_ENTER_EXIST_FW);

                    /*
                     * If current active screen is the same with the screen we want to entry,
                     * we return MMI_TRUE directly.
                     */
                    return MMI_TRUE;
                }
                else if (mmi_frm_scrn_is_present((MMI_ID)new_node->parent->id, (MMI_ID)new_node->id, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG) &&
                         IsBitReset(new_node->state, MMI_SCENARIO_STATE_FIRST_ENTRY_IDX))
                {
                    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_NODE_ENTER,\
                        parent_id, (MMI_ID)scrn_id, scrn_type, ERR_S_ENTER_EXIST_FW);
                    /* The application want to enter the existed screen in the same group (forward case) exclude entering from mmi_frm_scrn_first_enter */
                    return MMI_FALSE;
                }
            }
        }
        
    #ifndef __MMI_NOT_TAB_SUPPORT__
        else if (scrn_type == MMI_FRM_TAB && new_node->type != SCENARIO_TAB_NODE)
        {
            /* Check if need to change screen type to SCENARIO_TAB_NODE from mmi_frm_scrn_first_enter */
            new_node = _SCRN(create_new_tab(parent_id, scrn_id, entry_proc, new_node->user_data, tab_pages_info_array, tab_pages_count, sel_idx));
            mmi_frm_scrn_close_ex (parent_id, scrn_id, SCRN_CLOSE_ITSELF);
            insert_node_by_handle(parent, NULL, _NODE(new_node), MMI_FRM_NODE_AT_LATEST_FLAG);
        }
    #endif /* __MMI_NOT_TAB_SUPPORT__ */

        if ((U32)scrn_type == (U32)MMI_FRM_FULL_SCRN)
        {
            MMI_ASSERT(_NODE(new_node)->type == SCENARIO_SCRN_NODE);
            SetBit(new_node->attrib, NODE_ATTRIB_FULL_SCREEN_IDX);
        }
        else if ((U32)scrn_type == (U32)MMI_FRM_SMALL_SCRN)
        {
            /* we don't add screen node in the scenario tree in small screen case. */
            MMI_ASSERT(_NODE(new_node)->type == SCENARIO_SCRN_NODE);
            SetBit(new_node->attrib, NODE_ATTRIB_SMALL_SCREEN_IDX);
        }
        else if ((U32)scrn_type == (U32)MMI_FRM_IDLE_SCRN)
        {
            SetBit(new_node->attrib, NODE_ATTRIB_IDLE_SCREEN_IDX);
        }
        else if ((U32)scrn_type == (U32)MMI_FRM_TAB_PAGE)
        {
            /* Change the node type to tab page */
            new_node->type = SCENARIO_TAB_PAGE_NODE;
        }
        else if (scrn_type == MMI_FRM_TAB)
        {
            /* tab frame screen */
            _TAB(new_node)->cur_sel_index = sel_idx;
            if (IsBitReset(new_node->state, MMI_SCENARIO_STATE_FIRST_ENTRY_IDX))
            {
                MMI_ASSERT(_IS_TAB(new_node));
            }
        }

        new_node->exit_proc = exit_proc;

        if (shell.state == MMI_SCENARIO_STATE_NONE)
        {
            SetBit(evt.state, MMI_SCENARIO_STATE_FIRST_ENTRY_IDX);
            SetBit(evt.state, MMI_SCENARIO_STATE_FORWARD_IDX);
        }
        else if (IsBitSet(shell.state, MMI_SCENARIO_STATE_FORWARD_IDX))
        {
            SetBit(evt.state, MMI_SCENARIO_STATE_FORWARD_IDX);
            if (IsBitSet(new_node->state, MMI_SCENARIO_STATE_ACTIVE_IDX))
            {
                /* Now it is in entry new screen, return MMI_TRUE directly. */
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_NODE_ENTER,\
                    parent_id, (MMI_ID)scrn_id, scrn_type, SCENARIO_S_ENTER_EXIST_ACTIVE);
                return MMI_TRUE;
            }
        }
        else
        {
            /* shell is in backward process */

            if (is_created_new_node)
            {
                /* when back to previous screen and entry new screen again */
                SetBit(evt.state, MMI_SCENARIO_STATE_FORWARD_IDX);
            }
            else
            {
                new_node = _SCRN(SG_GET_NODE_FROM_ROOT(_SCRN_ID(parent_id, scrn_id)));

                if (IsBitSet(shell.state, MMI_SCENARIO_STATE_BACKWARD_IDX))
                {
                    SetBit(evt.state, MMI_SCENARIO_STATE_BACKWARD_IDX);
                }
                else
                {
                    MMI_ASSERT(FALSE);
                }
            }
        }

        
       set_scenario_evt(&evt, parent_id, new_node->id, new_node->user_data);
       
        if (!_IS_TAB_PAGE(new_node))
        {
            SG_ADD_NODE(parent, new_node);
        }

        if (shell.state == MMI_SCENARIO_STATE_NONE )
        {
			if (is_in_active_group_serial(parent_id))
			{

				shell.state = evt.state;
				SetBit(new_node->state, MMI_SCENARIO_STATE_FIRST_ENTRY_IDX);
				if (shell.active_scrn && 
					shell.active_scrn->parent != parent  || shell.active_group != parent)
				{
					mmi_scenario_evt_struct focus_evt;
					if (find_prev_node(_NODE(new_node)))
					{
						_EXECUTE_NODE_INACTIVE(find_prev_node(_NODE(new_node)), &evt);
						scenario_process_post_evt_ex(SCENARIO_POST_TYPE_APP);
					}
					shell.active_group = parent;
					MMI_FRM_INIT_EVENT(&focus_evt, EVT_ID_GROUP_FOCUSED);
					focus_evt.targ_group = shell.active_group->id;
					group_focus_change(shell.active_group, &focus_evt, MMI_TRUE);
				}
				MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_NODE_ENTER,\
					parent_id, (MMI_ID)scrn_id, scrn_type, SCENARIO_NORMAL);
				/* If new screen's parent is active group, we execute screen change process */
				_EXECUTE_NODE_ACTIVE(new_node, &evt);
				ResetBit(new_node->state, MMI_SCENARIO_STATE_FIRST_ENTRY_IDX);
				scenario_process_post_evt_ex(SCENARIO_POST_TYPE_APP);

                if (scrn_type == MMI_FRM_TAB_PAGE)
                    return MMI_TRUE;
                return mmi_frm_scrn_is_present(parent_id,scrn_id,MMI_FRM_NODE_ALL_FLAG);
				//return MMI_TRUE;
			}
			else
			{
				/* only add screen in the scenario tree and set it state in inactive */
				SetBit(new_node->state, MMI_SCENARIO_STATE_INACTIVE_IDX);
				if (scrn_type == MMI_FRM_FG_ONLY_SCRN)
				{
					_POST_APP_SCENARIO_EVT(parent_id, _SCRN_ID(parent_id, scrn_id), POST_EXECUTE_SCRN_DUMMY_CLEANUP, &evt);
				}
				MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_NODE_ENTER,\
					parent_id, (MMI_ID)scrn_id, scrn_type, SCENARIO_S_ENTER_INACTIVE);
			}

		}
		else
		{            
			MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_NODE_ENTER,\
				parent_id, (MMI_ID)scrn_id, scrn_type, SCENARIO_POST);
			_POST_APP_SCENARIO_EVT(parent_id, _SCRN_ID(parent_id, scrn_id), POST_EXECUTE_ACTIVE, &evt);
		}

    }
    else
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM,MMI_FRM_SCENARIO_NODE_ENTER,\
            parent_id, (MMI_ID)scrn_id, scrn_type, ERR_S_ENTER_NO_PARENT);
    }

    return MMI_FALSE;
}


MMI_BOOL mmi_frm_scrn_enter (MMI_ID parent_id, MMI_ID scrn_id, FuncPtr exit_proc, FuncPtr entry_proc, mmi_frm_scrn_type_enum scrn_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL r;
    mmi_frm_scrn_enter_success_evt  evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM,MMI_FRM_SCENARIO_SCRN_ENTER,parent_id,(MMI_ID)scrn_id,exit_proc,entry_proc,scrn_type,SG_API_BEG);
    if (parent_id == GRP_ID_ROOT)
    {
        // only support common screen, not support tab/tab-page 
        MMI_ASSERT(scrn_type < MMI_FRM_TAB_PAGE || scrn_type == MMI_FRM_FG_ONLY_SCRN);
        
        // must have entry function 
        MMI_ASSERT(entry_proc);

        // use the scrn id as the group id, so must unique in global
        if (mmi_frm_group_is_present(scrn_id) == MMI_FALSE)
        {
            comm_enter_root_screen_evt_struct rs_evt;
            MMI_FRM_INIT_EVENT(&rs_evt, EVT_ID_ROOT_SCRN_COMM_ENTER);
            rs_evt.entry_proc = entry_proc;
            rs_evt.scrn_id = scrn_id;
            rs_evt.exit_proc = exit_proc;
            rs_evt.type = scrn_type;

            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_ENTER_PROCESSING,parent_id,(MMI_ID)scrn_id,S_ENTER_PID_IS_ROOT_NOT_EXIST);
            {
                mmi_ret ret;
                ret = MMI_FRM_SEND_EVENT(&rs_evt, mmi_scenario_external_post_proc, NULL);
                return (ret == MMI_RET_OK) ? MMI_TRUE : MMI_FALSE;
            }
        }
        else
        {
            mmi_group_node_struct node;
            mmi_frm_group_get_info(scrn_id, &node);
            MMI_ASSERT(node.parent == GRP_ID_ROOT);
            MMI_ASSERT(MMI_TRUE == mmi_frm_scrn_is_present(scrn_id, scrn_id, MMI_FRM_NODE_ALL_FLAG));
            MMI_ASSERT(mmi_frm_scrn_get_count(scrn_id) == 1);

            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_ENTER_PROCESSING,parent_id,(MMI_ID)scrn_id,S_ENTER_PID_IS_ROOT_EXIST);
            return mmi_frm_scrn_enter(scrn_id, scrn_id, exit_proc, entry_proc, scrn_type);
        }

    }

    if (scrn_type == MMI_FRM_UNKNOW_SCRN)
    {
        scrn_type = MMI_FRM_FULL_SCRN;
    }
    MMI_ASSERT(scrn_type != MMI_FRM_TAB);
    r =  scrn_node_enter (
            parent_id, 
            scrn_id, 
            (mmi_scrn_func)exit_proc, 
            (mmi_scrn_func)entry_proc, 
            scrn_type, 
            NULL, 
            0, 
            0);
    if (r == MMI_TRUE)
    {
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_SCRN_ENTER_SUCCESS_NOFITY);
        evt.group_id = parent_id;
        evt.scrn_id  = scrn_id;
        MMI_FRM_CB_EMIT_EVENT(&evt);
    }
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_ENTER_RET, r, SG_API_END);
    return r;
}


static mmi_ret process_root_screen_enter(mmi_event_struct *evt)
{
   
    enter_root_screen_evt_struct *rs_evt = (enter_root_screen_evt_struct *)evt;

   
    mmi_frm_group_create(GRP_ID_ROOT, rs_evt->scrn_id, mmi_scenario_external_post_proc, NULL);
    mmi_frm_group_enter(rs_evt->scrn_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    if (evt->evt_id == EVT_ID_ROOT_SCRN_FIRST_ENTER)
    {
       first_enter_root_screen_evt_struct *f_rs_evt = (first_enter_root_screen_evt_struct *)evt;
       mmi_frm_scrn_first_enter_ex(f_rs_evt->scrn_id, f_rs_evt->scrn_id, f_rs_evt->entry_proc, f_rs_evt->arg, f_rs_evt->scrn_proc);
    }
    else if (evt->evt_id == EVT_ID_ROOT_SCRN_COMM_ENTER)
    {
        comm_enter_root_screen_evt_struct *c_rs_evt = (comm_enter_root_screen_evt_struct *)evt;
        mmi_ret ret;
        ret = mmi_frm_scrn_enter( 
                    c_rs_evt->scrn_id,
                    c_rs_evt->scrn_id,
                    c_rs_evt->exit_proc,
                    c_rs_evt->entry_proc,
                    c_rs_evt->type);
        return (ret == MMI_TRUE) ? MMI_RET_OK : MMI_RET_ERR;
    }
    else if (evt->evt_id == EVT_ID_ROOT_SCRN_COMM_POST_ENTER)
    {
        
    }
    else
    {
        MMI_ASSERT(0);
    }
    return MMI_RET_OK;
}


static mmi_ret scrn_common_exit(mmi_scrn_essential_struct* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_inactive_evt_struct inactiv_evt = {0};
    scrn_node_struct* node_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&inactiv_evt, EVT_ID_SCRN_INACTIVE);
    inactiv_evt.group_id = data->group_id;
    inactiv_evt.scrn_id = data->scrn_id;
    node_p = _SCRN(SG_GET_NODE_FROM_ROOT(_SCRN_ID(data->group_id, data->scrn_id)));
    
    if (node_p->proc)
    {
        MMI_FRM_SEND_EVENT(&inactiv_evt, node_p->proc, data->user_data); 
    }

    return MMI_RET_OK;
}

static mmi_ret scrn_common_entry(mmi_scrn_essential_struct* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL b_first_enter = MMI_FALSE;
    scrn_node_struct* node_p = _SCRN(SG_GET_NODE_FROM_ROOT(_SCRN_ID(data->group_id, data->scrn_id)));
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (node_p == NULL)
        return MMI_RET_ERR;
    
    if (IsBitSet(node_p->state, MMI_SCENARIO_STATE_FIRST_ENTRY_IDX))
        b_first_enter = MMI_TRUE;

    if (mmi_frm_scrn_enter(
            data->group_id,
            data->scrn_id,
            (FuncPtr)scrn_common_exit,
            (FuncPtr)scrn_common_entry,
            MMI_FRM_FULL_SCRN) && (node_p->proc != NULL))
    {
        mmi_frm_scrn_active_evt_struct active_evt = {0};
        
        mmi_frm_scrn_set_key_proc(data->group_id, data->scrn_id, node_p->proc);
        MMI_FRM_INIT_EVENT(&active_evt, EVT_ID_SCRN_ACTIVE);

        active_evt.group_id = node_p->parent->id;
        active_evt.scrn_id = node_p->id;
        active_evt.gui_buffer = mmi_frm_scrn_get_active_gui_buf();
        active_evt.input_buffer = mmi_frm_scrn_get_active_input_buf();
        active_evt.is_first_active = b_first_enter;
        active_evt.is_bg_redrawing = (mmi_is_redrawing_bk_screens())? MMI_TRUE : MMI_FALSE;

		if (b_first_enter == MMI_TRUE)
		{
			SetBit(shell.state, MMI_SCENARIO_STATE_FIRST_ENTRY_IDX);
		}

        MMI_FRM_SEND_EVENT(&active_evt, node_p->proc, data->user_data);
		
		if (b_first_enter == MMI_TRUE)
		{
			ResetBit(shell.state, MMI_SCENARIO_STATE_FIRST_ENTRY_IDX);
		}

		if (b_first_enter == MMI_TRUE)
		{
			scenario_process_post_evt_ex(SCENARIO_POST_TYPE_APP);
		}
    }
    return MMI_RET_OK;
}

void mmi_frm_scrn_create(MMI_ID parent_id, MMI_ID scrn_id, mmi_proc_func proc, void *user_data)
{
    mmi_frm_scrn_first_enter_ex(parent_id, scrn_id, (FuncPtr)scrn_common_entry, user_data, proc);
}

void mmi_frm_scrn_first_enter_ex (MMI_ID parent_id, MMI_ID scrn_id, FuncPtr entry_proc, void *user_data, mmi_proc_func leave_proc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    scrn_node_struct *new_node = NULL;
    group_node_struct *parent = NULL;
    mmi_scenario_evt_struct evt = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_FIRST_ENTER, \
        parent_id, (MMI_ID)scrn_id, entry_proc, user_data, leave_proc, SG_API_BEG);
    
    if (parent_id == GRP_ID_ROOT)
    {
        first_enter_root_screen_evt_struct rs_evt;
        MMI_ASSERT(entry_proc != NULL);
        MMI_ASSERT(mmi_frm_group_is_present(scrn_id) == MMI_FALSE);
        MMI_FRM_INIT_EVENT(&rs_evt, EVT_ID_ROOT_SCRN_FIRST_ENTER);
        rs_evt.entry_proc = entry_proc;
        rs_evt.scrn_id = scrn_id;
        rs_evt.arg = user_data;
        rs_evt.scrn_proc = leave_proc;

        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_FIRST_ENTER_PROCESSING, \
                parent_id, (MMI_ID)scrn_id, S_FIRST_ENTER_PID_IS_ROOT);
        if (mmi_frm_shell_is_in_backward_scenario() == MMI_TRUE)
        {
            MMI_FRM_POST_EVENT(&rs_evt, mmi_scenario_external_post_proc, NULL);
        }
        else
        {
            MMI_FRM_SEND_EVENT(&rs_evt, mmi_scenario_external_post_proc, NULL);
        }
        return;
    }
    

    parent = (group_node_struct *)SG_GET_NODE_FROM_ROOT(parent_id);
    if (parent)
    {
        /* If the parent is valid, we allow to entry new screen */
        new_node = _SCRN(SG_GET_CHILD(parent, _SCRN_ID(parent_id, scrn_id)));
        MMI_ASSERT(entry_proc != NULL);
        MMI_ASSERT(mmi_frm_scenario_is_redrawing() == MMI_FALSE);
        if (new_node == NULL)
        {
            new_node = create_new_scrn(parent_id, scrn_id, (mmi_scrn_func)entry_proc, user_data);
            ResetBit(new_node->attrib, NODE_ATTRIB_AUTO_ADD_HISTORY_IDX);
        }
        else
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_FIRST_ENTER, \
                parent_id, (MMI_ID)scrn_id, S_FIRST_ENTER_EXIST_SCRN_SG_API_END);
            return;
        }
        
        new_node->proc = leave_proc;

        SG_ADD_NODE(parent, new_node);
		
        /* notify app init event */
        if(new_node->proc)
        {
            mmi_frm_scrn_init_evt_struct init_evt = {0};
            MMI_FRM_INIT_EVENT(&init_evt, EVT_ID_SCRN_INIT);
            init_evt.group_id = parent_id;
            init_evt.scrn_id = scrn_id;
            MMI_FRM_SEND_EVENT(&init_evt, new_node->proc, new_node->user_data);
        }
        if (shell.state == MMI_SCENARIO_STATE_NONE )
        {
            /* invoke screen entry directly */
            SetBit(new_node->state, MMI_SCENARIO_STATE_FIRST_ENTRY_IDX);
         
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_FIRST_ENTER_PROCESSING, \
                parent_id, (MMI_ID)scrn_id, S_FIRST_ENTER_EXECUTE_ENTRY_PROC);
          
            node_exec_entry_proc(new_node);
            
            ResetBit(new_node->state, MMI_SCENARIO_STATE_FIRST_ENTRY_IDX);
        }
        else
        {
            SetBit(evt.state, MMI_SCENARIO_STATE_FIRST_ENTRY_IDX);

            set_scenario_evt(&evt, parent_id, new_node->id, new_node->user_data);

            MMI_TRACE(MMI_FW_TRC_G1_FRM,MMI_FRM_SCENARIO_SCRN_FIRST_ENTER_PROCESSING, \
                parent_id, (MMI_ID)scrn_id, SCENARIO_POST);
            _POST_APP_SCENARIO_EVT(parent_id, _SCRN_ID(parent_id, scrn_id), POST_EXECUTE_SCRN_FIRST_ENTRY  , &evt);
        }
    }
    else
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_FIRST_ENTER_PROCESSING, \
            parent_id, (MMI_ID)scrn_id, S_FIRST_ENTER_NO_PARENT_SG_API_END);
    }
}


void mmi_frm_scrn_first_enter(MMI_ID parent_id, MMI_ID scrn_id, FuncPtr entry_proc, void *user_data)
{
    mmi_frm_scrn_first_enter_ex(parent_id,scrn_id, entry_proc, user_data, NULL);
}


mmi_ret mmi_frm_scrn_insert (MMI_ID parent_id, MMI_ID base_id, mmi_frm_node_struct *new_node_info, mmi_scenario_node_flag flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret rst = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (new_node_info == NULL)
        return MMI_RET_ERR;
        
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_INSERT, parent_id,(MMI_ID)base_id, (MMI_ID)new_node_info->id, new_node_info->entry_proc, flag, SG_API_BEG);
    MMI_ASSERT(parent_id != GRP_ID_ROOT);    
    rst = mmi_frm_node_insert(parent_id, (MMI_ID)base_id, new_node_info, flag, 0);

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_INSERT, parent_id, base_id, new_node_info->id, new_node_info->entry_proc, flag, SG_API_END);
    return rst;
}


mmi_ret mmi_frm_scrn_replace (MMI_ID parent_id, MMI_ID out_id, mmi_frm_node_struct *new_node_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    base_node_struct* node_old = NULL;
    base_node_struct* node_new = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (new_node_info == NULL)
        return MMI_RET_ERR;
        
    MMI_ASSERT(parent_id != GRP_ID_ROOT);
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_REPLACE, \
        parent_id, (MMI_ID)out_id, (MMI_ID)new_node_info->id, new_node_info->entry_proc, SG_API_BEG);


    node_old = SG_GET_NODE_FROM_ROOT(_SCRN_ID(parent_id, out_id));
    if (node_old == NULL)
        return MMI_RET_ERR;
    node_new = SG_GET_NODE_FROM_ROOT(_SCRN_ID(parent_id, new_node_info->id));
    if (node_new != NULL)
        return MMI_RET_ERR;

    replace_node_sg_op(node_old, new_node_info, MMI_FALSE);

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_REPLACE, \
        parent_id, (MMI_ID)out_id, (MMI_ID)new_node_info->id, new_node_info->entry_proc, SG_API_END);
    return MMI_RET_OK;
}



static mmi_ret mmi_frm_scrn_close_ex (MMI_ID parent_id, MMI_ID scrn_id, scrn_close_type_enum flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scenario_evt_struct evt = {0};
    scrn_node_struct        *screen = NULL;
    tab_page_node_struct    *page = NULL;
    U32                     id = 0;
    mmi_ret                 rst = MMI_RET_ERR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    id = _SCRN_ID(parent_id, scrn_id);
    if (shell.active_tab && shell.active_tab->m_tail)
    {
        /* check if want to close page screen first */
        page = _TAB_PAGE(shell.active_tab->m_tail);
        while (page)
        {
            if (page->id == _SCRN_ID(parent_id, scrn_id))
            {
                /* we should close tab directly. */
                id = shell.active_tab->id;
                screen = _SCRN(shell.active_tab);
                break;
            }
            page = _TAB_PAGE(page->m_prev);
        }       
    }
    else
    {
        screen = _SCRN(SG_GET_NODE_FROM_ROOT(id));
        if(screen == NULL)
            screen = _SCRN(SG_GET_NODE_FROM_BG(id));
    }

    if (screen)
    {
        if (flag != SCRN_CLOSE_ITSELF && 
            screen->parent &&
            screen->parent->m_count == 1 &&
            (IsBitSet(screen->parent->attrib, NODE_ATTRIB_SMART_CLOSED_IDX) ||
            IsBitSet(screen->parent->attrib, NODE_ATTRIB_SMART_CLOSED_CAUSE_BY_CLOSE_IDX)))
        {
            /* because only one screen in this group, we close the group directly. */
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_CLOSE_EX, parent_id, (MMI_ID)scrn_id, S_CLOSE_SMART_CLOSE_PARENT);
            return mmi_frm_group_close((MMI_ID)screen->parent->id);
        }

        if (shell.active_scrn && screen == shell.active_scrn)
        {
            /* We want close the active screen. Executing the goback process */
            MMI_ASSERT(screen->parent == shell.active_group);
            SetBit(evt.state, MMI_SCENARIO_STATE_BACKWARD_IDX);
        }
        else
        {
            /* Because the closed screen isn't active screen, we deinit it directly */
            SetBit(evt.state, MMI_SCENARIO_STATE_DELETE_REQ_IDX);
        }

        evt.evt_id      = EVT_ID_SCENARIO_CHANGE;        
        set_scenario_evt(&evt, screen->parent->id, id, screen->user_data);

        if (shell.state == MMI_SCENARIO_STATE_NONE)
        {
            shell.state = evt.state;
			SetBit(screen->attrib, NODE_ATTRIB_CLOSED_TARGET_IDX);
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_CLOSE_EX, parent_id, (MMI_ID)scrn_id, SCENARIO_NORMAL);
            rst = _EXECUTE_NODE_CLOSE(screen, &evt);
            scenario_process_post_evt_ex(SCENARIO_POST_TYPE_APP);
        }
        else
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_CLOSE_EX, parent_id, (MMI_ID)scrn_id, SCENARIO_POST);
            _POST_APP_SCENARIO_EVT(parent_id, id, POST_EXECUTE_CLOSE, &evt);
        }
    }

    return rst;
}


void mmi_frm_scrn_close_active_id (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_CLOSE_ACTIVE_ID, SG_API_BEG);
    if (shell.active_scrn)
    {
        mmi_frm_scrn_close((MMI_ID)shell.active_group->id, (MMI_ID)shell.active_scrn->id);
    }
#ifdef __MMI_FRM_HISTORY__
    else if(shell.state == MMI_SCENARIO_STATE_NONE)
    {
        shell.in_external_goback_process = 1;
        mmi_go_back_to_history();
        shell.in_external_goback_process = 0;
        scenario_process_post_evt_ex(SCENARIO_POST_TYPE_APP);
    }
#endif /* __MMI_FRM_HISTORY__ */
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_CLOSE_ACTIVE_ID, SG_API_END);
}


U8 mmi_frm_scenario_close_to_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 status = ST_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_FRM_HISTORY__
    status = mmi_frm_history_back_to_idle();
    scenario_process_post_evt_ex(SCENARIO_POST_TYPE_APP);
    #endif /* __MMI_FRM_HISTORY__ */
    return status;   
}


void mmi_frm_execute_scenario_post_event(void)
{
    scenario_process_post_evt_ex(SCENARIO_POST_TYPE_APP);
}


mmi_ret mmi_frm_scrn_close (MMI_ID parent_id, MMI_ID scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_CLOSE, parent_id, (MMI_ID)scrn_id, SG_API_BEG);
    if(mmi_frm_scenario_is_redrawing())
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_CLOSE, parent_id, scrn_id, S_CLOSE_IN_REDRAWING_SG_API_END);
        return MMI_RET_OK;
    }
    parent_id = _PARENT_ID(parent_id, scrn_id);
    ret = mmi_frm_scrn_close_ex(parent_id, scrn_id, SCRN_CLOSE_DEFAULT);
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_CLOSE, parent_id, (MMI_ID)scrn_id, SG_API_END);
    return ret;
}

base_node_struct *find_root_screen(U32 group_id)
{
    group_node_struct *group;
    base_node_struct *node;
    group = (group_node_struct *)SG_GET_NODE_FROM_ROOT(group_id);
    if (group != NULL)
    {
        node = group->m_head;
        while(1)
        {
            if (node == NULL)
            {
                return NULL;
            }
            else if (_IS_SCRN(node) || _IS_TAB(node))
            {
                break;
            }
            node = ((group_node_struct *)node)->m_head;
        }
        return node;
    }
    return NULL;   
}

void mmi_frm_display_desktop(void)
{
	if(shell.state == MMI_SCENARIO_STATE_NONE)
	{
		MMI_ID group_id;
		mmi_frm_close_to_idle_group();
        group_id = mmi_frm_group_get_active_id();
		group_id = mmi_frm_group_get_top_parent_group_id(group_id);
    #ifdef __MMI_FRM_HISTORY__
        if (GetIdleScrnId() == group_id)
    #else
        if (shell.scenario_root.m_head->id== group_id)
    #endif /* __MMI_FRM_HISTORY__ */
        {
            mmi_frm_close_to_root_screen(group_id);
        }
	}
	else
	{
		mmi_scenario_evt_struct evt = {0};
		_POST_APP_SCENARIO_EVT(GRP_ID_INVALID, SCR_ID_INVALID, POST_EXECUTE_DISPLAY_DESKTOP, &evt);
	}
}

mmi_ret mmi_frm_close_to_idle_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FRM_HISTORY__
	if(shell.state == MMI_SCENARIO_STATE_NONE)
    {
		base_node_struct* pCurrNode = NULL;
		pCurrNode = shell.scenario_root.m_tail;
		mmi_frm_asm_scenario_hook(HOOK_EVT_BEFORE_TO_IDLE, (base_node_struct *)pCurrNode);
		ExecuteRootMainHistoryScreen(NULL);
	}
	else
	{
        mmi_scenario_evt_struct evt = {0};
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GOTO_IDLE, \
            (MMI_ID)g_scrn_mgr_cntx.active_group_id, \
            (MMI_ID)g_scrn_mgr_cntx.active_scrn_id, \
            shell.state, \
            shell.scenario_root.m_count, SCENARIO_POST);

        _POST_APP_SCENARIO_EVT(GRP_ID_INVALID, SCR_ID_INVALID, POST_EXECUTE_CLOSE_TO_IDLE_GROUP, &evt);
        return MMI_RET_OK;
	}
#else
    {
        MMI_ID currID;
        mmi_scenario_evt_struct evt = {0};
        base_node_struct* pCurrNode = NULL;
        MMI_BOOL temp_backup = group_close_from_gprot;
        pCurrNode = shell.scenario_root.m_tail;


        if(shell.state != MMI_SCENARIO_STATE_NONE)
        {
            mmi_scenario_evt_struct evt = {0};
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GOTO_IDLE, \
                (MMI_ID)g_scrn_mgr_cntx.active_group_id, \
                (MMI_ID)g_scrn_mgr_cntx.active_scrn_id, \
                shell.state, \
                shell.scenario_root.m_count, SCENARIO_POST);

            _POST_APP_SCENARIO_EVT(GRP_ID_INVALID, SCR_ID_INVALID, POST_EXECUTE_CLOSE_TO_IDLE_GROUP, &evt);
            return MMI_RET_OK;
        }
        if (shell.scenario_root.m_tail == shell.scenario_root.m_head)
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GOTO_IDLE, \
                (MMI_ID)g_scrn_mgr_cntx.active_group_id, \
                (MMI_ID)g_scrn_mgr_cntx.active_scrn_id, \
                shell.state, \
                shell.scenario_root.m_count, ONLY_IDLE_SG_API_END);
                    
            scenario_process_post_evt_ex(SCENARIO_POST_TYPE_APP);
            return MMI_RET_OK;
        }
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GOTO_IDLE, \
            (MMI_ID)g_scrn_mgr_cntx.active_group_id, \
            (MMI_ID)g_scrn_mgr_cntx.active_scrn_id, \
            shell.state,\
            shell.scenario_root.m_count, SG_API_BEG);

        mmi_frm_asm_scenario_hook(HOOK_EVT_BEFORE_TO_IDLE, (base_node_struct *)pCurrNode);
        while(pCurrNode && pCurrNode->m_prev)
        {
            SetBit(shell.state, MMI_SCENARIO_STATE_BACK_TO_IDLE_IDX);
            SetBit(pCurrNode->attrib, NODE_ATTRIB_IN_END_KEY_PROCESS_IDX);
            currID = pCurrNode->id;
            pCurrNode = pCurrNode->m_prev;
            group_close_from_gprot = MMI_FALSE;
            mmi_frm_group_close_ex(currID,SCENARIO_POST_TYPE_INTERNAL, NULL, MMI_FALSE);
            group_close_from_gprot = temp_backup;

            if(IsBitSet(shell.state,MMI_SCENARIO_STATE_STOP_CLOSE_BREAK_IDX))
            {
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_BREAK_CLOSE,currID);
                pCurrNode = pCurrNode->m_next;
                break;
            }
        }
        if(IsBitSet(shell.state,MMI_SCENARIO_STATE_STOP_CLOSE_BREAK_IDX) ||
            IsBitSet(shell.state,MMI_SCENARIO_STATE_STOP_CLOSE_CONTINUE_IDX))
        {
            base_node_struct* node_parent = shell.targ_node;
            if (shell.targ_node) 
            {
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_CLOSE_FORBID, (MMI_ID)shell.targ_node->id);
                node_parent = (base_node_struct*)node_parent->parent;
                while(node_parent && node_parent != (base_node_struct*)&shell.scenario_root)
                {
                    if(IsBitSet(node_parent->state, MMI_SCENARIO_STATE_INACTIVE_IDX))
                    {
                        shell.targ_node = (base_node_struct*)node_parent;
                    }
                    node_parent = (base_node_struct*)node_parent->parent;
                }                
                _EXECUTE_NODE_ACTIVE(shell.targ_node, &evt);
            }
            shell.targ_node = NULL;
        }
        if (pCurrNode && pCurrNode == shell.scenario_root.m_head && shell.scenario_root.m_count == 1)
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_ACTIVE_IDLE,(MMI_ID)pCurrNode->id);
            SetBit(evt.state, MMI_SCENARIO_STATE_BACKWARD_IDX);
            _EXECUTE_NODE_ACTIVE(pCurrNode, &evt);
		}
        scenario_process_post_evt_ex(SCENARIO_POST_TYPE_APP);
        ResetBit(shell.state, MMI_SCENARIO_STATE_BACK_TO_IDLE_IDX);
        
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GOTO_IDLE, \
            (MMI_ID)g_scrn_mgr_cntx.active_group_id, \
            (MMI_ID)g_scrn_mgr_cntx.active_scrn_id, \
            shell.state,\
            shell.scenario_root.m_count, SG_API_END);
    }
#endif /* __MMI_FRM_HISTORY__ */
    return MMI_RET_OK;
}

mmi_ret mmi_frm_close_to_idle_group_with_start_id(MMI_ID start_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FRM_HISTORY__
    MMI_ID active_group_id = GRP_ID_INVALID;
    MMI_ID active_scrn_id  = GRP_ID_INVALID;
    MMI_BOOL b_active = MMI_FALSE;
	MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_CLOSE_TO_IDLE_WITH_START_ID, start_id);
    mmi_frm_get_active_scrn_id(&active_group_id, &active_scrn_id);
    if((active_group_id == GRP_ID_ROOT && active_scrn_id == start_id) || 
        (mmi_frm_get_root_app(active_group_id) == start_id))
    {
        b_active = MMI_TRUE;
    }

    if (b_active)        
    {
        g_is_stop_when_forbiden = MMI_TRUE;
        mmi_frm_close_to_idle_group();
        g_is_stop_when_forbiden = MMI_FALSE;
    }
    else
    {
        g_is_back_root_main_hist = MMI_TRUE;
        g_is_stop_when_forbiden = MMI_TRUE;
        DeleteHistory(start_id,1,0, GetIdleScrnId(), 0);
        g_is_back_root_main_hist = MMI_FALSE;
        g_is_stop_when_forbiden = MMI_FALSE;
    }
#else
    MMI_BOOL temp_backup = group_close_from_gprot;
	MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_CLOSE_TO_IDLE_WITH_START_ID, start_id);
    if(shell.active_group && mmi_frm_get_root_app(shell.active_group->id) == start_id)
    {
        mmi_frm_close_to_idle_group();
    }
    else
    {
        U32 currID;
        base_node_struct* pCurrNode = NULL;
        pCurrNode = SG_GET_CHILD(&shell.scenario_root, start_id);
        
        while(pCurrNode && pCurrNode->m_prev)
        {
            currID = pCurrNode->id;
			SetBit(pCurrNode->attrib, NODE_ATTRIB_IN_END_KEY_PROCESS_IDX);
            pCurrNode = pCurrNode->m_prev;
            group_close_from_gprot = MMI_FALSE;
			mmi_frm_group_close_ex(currID,SCENARIO_POST_TYPE_INTERNAL, NULL, MMI_FALSE);
            group_close_from_gprot = temp_backup;
        }
		scenario_process_post_evt_ex(SCENARIO_POST_TYPE_APP);
    }
#endif
	return MMI_RET_OK;
}

mmi_ret mmi_frm_close_all_background_groups(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID currID = 0;
    mmi_scenario_evt_struct evt = {0};
    base_node_struct* pCurrNode = NULL;
    MMI_BOOL temp_backup = group_close_from_gprot;

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_CLOSE_ALL_BG_GROUPS, shell.state, SG_API_BEG);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(shell.state != MMI_SCENARIO_STATE_NONE)
    {
        _POST_APP_SCENARIO_EVT(GRP_ID_INVALID, SCR_ID_INVALID, POST_EXECUTE_CLOSE_ALL_BG_GROUPS, &evt);
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_CLOSE_ALL_BG_GROUPS, shell.state, SCENARIO_POST_SG_API_END);
        return MMI_RET_OK;
    }
    pCurrNode = shell.scenario_bg.m_tail;
    while (pCurrNode)
    {
        SetBit(shell.state, MMI_SCENARIO_STATE_CLOSE_ALL_BG_GROUPS);
        currID = pCurrNode->id;
        pCurrNode = pCurrNode->m_prev;            
        group_close_from_gprot = MMI_FALSE;
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_CLOSE_BG_GROUP, shell.state, currID);
        mmi_frm_group_close_ex(currID, SCENARIO_POST_TYPE_INTERNAL, NULL, MMI_FALSE);
        group_close_from_gprot = temp_backup;
    }
    ResetBit(shell.state, MMI_SCENARIO_STATE_CLOSE_ALL_BG_GROUPS);
    scenario_process_post_evt_ex(SCENARIO_POST_TYPE_APP);

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_CLOSE_ALL_BG_GROUPS, shell.state, SG_API_END);
    return MMI_RET_OK;
}


mmi_ret mmi_frm_close_to_root_screen(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    base_node_struct *node;
    group_node_struct *group = NULL;
    mmi_ret ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_CLOSE_TO_ROOT_SCREEN, group_id);

	if(shell.state != MMI_SCENARIO_STATE_NONE)
    {
        mmi_scenario_evt_struct evt = {0};

        _POST_APP_SCENARIO_EVT(group_id, SCR_ID_INVALID, POST_EXECUTE_CLOSE_TO_ROOT_GROUP, &evt);
        return MMI_RET_OK;
	}
    node = find_root_screen(group_id);
    if (node == NULL)
    {
        return MMI_RET_ERR;
    }
#ifdef __MMI_FRM_HISTORY__
    if (GetIdleScrnId() == group_id)
#else
    if (shell.scenario_root.m_head->id== group_id)
#endif /* __MMI_FRM_HISTORY__ */
    {
        group = (group_node_struct *)SG_GET_NODE_FROM_ROOT(group_id);
        MMI_ASSERT(group != NULL);
        SetBit(group->attrib, NODE_ATTRIB_IN_END_KEY_PROCESS_IDX);
    }
    SetBit(node->attrib, NODE_ATTRIB_NOT_ALLOW_DEL);
    ret = mmi_frm_group_close(group_id);
    ResetBit(node->attrib, NODE_ATTRIB_NOT_ALLOW_DEL);
    if(group != NULL)
        ResetBit(group->attrib, NODE_ATTRIB_IN_END_KEY_PROCESS_IDX);
    return ret;
}

mmi_ret mmi_frm_scrn_multiple_close (MMI_ID parent_id, MMI_ID start_scrn_id, U8 b_inc_start, U16 count, MMI_ID end_scrn_id, U8 b_inc_end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    base_node_struct* start_node = NULL; /* latest node */
    base_node_struct* next_node = NULL;  /* next node */
    base_node_struct* end_node = NULL;   /* older node */
    U32 i;
    mmi_ret result = MMI_RET_OK;

    MMI_BOOL need_close_active_scrn = MMI_FALSE;
    mmi_scenario_evt_struct evt = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* get max range (when count is given) and validate it.
     * Conditions :
     * [1] no startIdx/count/endIdx         (not support)
     * [2] startIdx exists, no count/endIdx (not support)
     * [3] count exists, no startIdx/endIdx (not support)
     * [4] endIdx exists, no startIdx/count (not support)
     * [5] startIdx/count exist, no endIdx  (support)
     * [6] startIdx/endIdx exist, no count  (support)
     * [7] endIdx/count exist, no startIdx  (not support)
     * [8] startIdx/count/endIdx all exist  (not support)
     */


    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_MULTIPLE_CLOSE, parent_id, start_scrn_id, b_inc_start, count, end_scrn_id, b_inc_end);

    if (parent_id == GRP_ID_ROOT)
    {
        result = MMI_RET_ERR;
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_MULTIPLE_CLOSE_END, ERR_M_S_CLOSE_1);
 
        return result;
    }

    start_node = SG_GET_NODE_FROM_ROOT(_SCRN_ID(parent_id, start_scrn_id));
    end_node = SG_GET_NODE_FROM_ROOT(_SCRN_ID(parent_id, end_scrn_id));

    if (start_node == NULL && end_node == NULL)
    {
        /* We can't find the screen node (start_node or end_node may be the group node) */
        
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_MULTIPLE_CLOSE_END, ERR_M_S_CLOSE_2);
        return MMI_RET_ERR;
    }

    /* handle inclusion */
    if (!b_inc_start && start_node)
    {
        start_node = find_prev_node(start_node);
    }

    /* handle inclusion */
    if (!b_inc_end && (end_node != NULL))
    {
        if (start_node == end_node)
        {
            /*
             * If start_node and end_node are conjoint and 
             * both of b_inc_start and b_inc_end are MMI_FALSE,
             * we don't need to close any node.
             */
            
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_MULTIPLE_CLOSE_END, ERR_M_S_CLOSE_3);
            return MMI_RET_OK;
        }
        end_node = find_next_node(end_node);
    }

    if (start_node)
    {
        if (count > 0)
        {
            if (end_node)
            {
                // [8] startIdx/count/endIdx all exist  (not support)
                
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_MULTIPLE_CLOSE_END, ERR_M_S_CLOSE_4);
                result = MMI_RET_ERR;
            }
            else
            {
                // [5] startIdx/count exist, no endIdx (support)
                i = count - 1;
                end_node = start_node;
                while (i > 0)
                {
                    end_node = find_prev_node(end_node);
                    if (end_node && _SCRN(end_node))
                    {
                        i--;
                    }
                    else
                    {
                        result = MMI_RET_ERR;
                        break;
                    }
                }
            }
        }
        else 
        {
            if (end_node)
            {
                // [6] startIdx/endIdx exist, no count (support)
            }
            else
            {
                // [2] startIdx exists, no count/endIdx (not support)
                
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_MULTIPLE_CLOSE_END, ERR_M_S_CLOSE_5);
                result = MMI_RET_ERR;
            }
        }
    }
    else
    {
        /*
         * [1] no startIdx/count/endIdx         (not support)
         * [3] count exists, no startIdx/endIdx (not support)
         * [4] endIdx exists, no startIdx/count (not support)
         * [7] endIdx/count exist, no startIdx  (not support)
         */
        result = MMI_RET_ERR;
    }

    if (start_node == NULL || end_node == NULL)
    {
        
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_MULTIPLE_CLOSE_END, ERR_M_S_CLOSE_6);
        return MMI_RET_ERR;
    }

    if (result == MMI_RET_OK)
    {
        if (start_node == end_node)
       {
            /* If only one screen, we call mmi_frm_scrn_close() directly. */
            result = mmi_frm_scrn_close((MMI_ID)parent_id, (MMI_ID)start_node->id);
            
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_MULTIPLE_CLOSE_END, result);
            return result;
        }
        /*
         * If need to close active screen, we query active screen first,
         * and delete the following screens, and goback the active screen at latest.
         */
        if (_SCRN(start_node) == shell.active_scrn)
        {
            need_close_active_scrn = MMI_TRUE;
            if (_SCRN(start_node)->proc)
            {
            
                evt.evt_id      = EVT_ID_SCRN_GOBACK;
                evt.curr_group  = parent_id;        /* it is active group */
                evt.curr_scrn   = start_node->id;   /* it is active screen */
                evt.targ_group  = parent_id;        /* it is active group */
                evt.targ_scrn   = start_node->id;   /* it is active screen */
                evt.new_group   = GRP_ID_INVALID;
                evt.new_scrn    = SCR_ID_INVALID;
                evt.user_data   = start_node->user_data;
    
                SetBit(start_node->state, MMI_SCENARIO_STATE_CLOSE_IND_IDX);
                SetBit(start_node->attrib, NODE_ATTRIB_MULTI_CLOSE_ACTIVE_SCRN_IDX);
                MMI_TRACE(MMI_FW_TRC_G1_FRM,
                    MMI_FRM_SCENARIO_EVT,
                    evt.evt_id,
                    parent_id,
                    (MMI_ID)start_node->id,
                    shell.state,
                    start_node->state,
                    start_node->attrib);
                result = _SCRN(start_node)->proc((mmi_event_struct*)&evt);
                ResetBit(start_node->state, MMI_SCENARIO_STATE_CLOSE_IND_IDX);
                if (result != MMI_RET_OK)
                {
                    /*
                     * Not allow to close the active screen.
                     * reset NODE_ATTRIB_MULTI_CLOSE_ACTIVE_SCRN_IDX and return MMI_RET_ERR.
                     */
                    ResetBit(start_node->state, NODE_ATTRIB_MULTI_CLOSE_ACTIVE_SCRN_IDX);
                    result = MMI_RET_ERR;
                }
            }
            /* allow to close the active screen. we execute close the following screen first. */
            start_node = (result == MMI_RET_OK) ? find_prev_node(start_node) : start_node;
        }
    
        if (result == MMI_RET_OK)
        {
            /* close the start_node to end_node (exclude end_node itself) */
            while (start_node != end_node)
            {
                next_node = find_prev_node(start_node);
                if (mmi_frm_scrn_close(parent_id, (MMI_ID)start_node->id) != MMI_RET_OK)
                {
                    result = MMI_RET_ERR;
                    break;
                }
                start_node = next_node;
            }
        }

        if (result == MMI_RET_OK)
        {
            /* close the end_node screen */
            if (start_node == end_node)
            {
                if (mmi_frm_scrn_close(parent_id, (MMI_ID)end_node->id) != MMI_RET_OK)
                {
                    result = MMI_RET_ERR;
                }
            }
        }

        if (result == MMI_RET_OK)
        {
            /*
             * If need to close active screen, we query active screen first,
             * and delete the following screens, and goback the active screen at latest.
             */
            if (need_close_active_scrn)
            {
                result = mmi_frm_scrn_close(parent_id, (MMI_ID)shell.active_scrn->id);
            }
        }
        
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_MULTIPLE_CLOSE_END, result);
    }
    else
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_MULTIPLE_CLOSE_END, ERR_M_S_CLOSE_7);
    }

    return result;
}


mmi_ret mmi_frm_scrn_set_leave_proc (MMI_ID parent_id, MMI_ID scrn_id, mmi_proc_func proc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    base_node_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_SET_LEAVE_PROC, parent_id, (MMI_ID)scrn_id, proc);
    node = SG_GET_NODE_FROM_ROOT(_SCRN_ID(_PARENT_ID(parent_id, scrn_id), scrn_id));

    if (_IS_SCRN(node) || _IS_TAB(node))
    {
        _SCRN(node)->proc = proc;
        return MMI_RET_OK;
    }
    else
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_SET_LEAVE_PROC_ERROR);
        return MMI_RET_ERR;
    }
}

void mmi_frm_scrn_set_key_proc(MMI_ID parent_id, MMI_ID scrn_id, mmi_proc_func proc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_SET_KEY_PROC, parent_id, (MMI_ID)scrn_id, proc);
    if (parent_id != GRP_ID_ROOT)
    {
        user_data = mmi_frm_scrn_get_user_data(parent_id, scrn_id);
    }
    else
    {
    #ifdef __MMI_FRM_HISTORY__
        user_data = mmi_frm_get_argument_with_screen(scrn_id);
    #else
        user_data = mmi_frm_group_get_user_data(scrn_id);
    #endif /* __MMI_FRM_HISTORY__ */
    }
    set_scrn_layer_id(parent_id, scrn_id);
    MMI_SCR_SET_KEY_PROC(proc, user_data);
}


void mmi_frm_scrn_set_active_input_buf_ptr (WCHAR *input_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_SET_ACTIVE_INPUT_BUF_PTR, input_buf_ptr);
    g_curr_input_buf = input_buf_ptr;
}


void mmi_frm_scrn_set_active_input_buf_size (U16 input_buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_SET_ACTIVE_INPUT_BUF_SIZE, input_buf_size);
    g_curr_input_size = input_buf_size;
}


MMI_RET mmi_frm_scrn_update_attribute(MMI_ID parent_id, MMI_ID scrn_id, mmi_scrn_attrib_enum attrib, U32 isSet)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    base_node_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_SET_ATTRIBUTE, parent_id, (MMI_ID)scrn_id, attrib);
    node = SG_GET_NODE_FROM_ROOT(_SCRN_ID(_PARENT_ID(parent_id, scrn_id), scrn_id));
    if (_IS_SCRN(node))
    {
        switch(attrib)
        {
        case MMI_SCRN_ATTRIB_ADD_HISTORY:
            if(isSet)
            {
                SetBit(node->attrib, NODE_ATTRIB_AUTO_ADD_HISTORY_IDX);
            }
            else
            {
                ResetBit(node->attrib, NODE_ATTRIB_AUTO_ADD_HISTORY_IDX);
            }            
            break;
        case MMI_SCRN_ATTRIB_SMALL_SCRN:
            if(isSet)
            {
                SetBit(node->attrib, NODE_ATTRIB_SMALL_SCREEN_IDX);
                ResetBit(node->attrib, NODE_ATTRIB_FULL_SCREEN_IDX);
            }
            else
            {
                SetBit(node->attrib, NODE_ATTRIB_FULL_SCREEN_IDX);
                ResetBit(node->attrib, NODE_ATTRIB_SMALL_SCREEN_IDX);
            }
            break;
        default:
            return MMI_RET_ERR;
        }
        return MMI_RET_OK;
    }
    else
    {
        if(isSet == MMI_FALSE)
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_CLEAR_ATTRIBUTE_ERROR);
        }
        else
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_SET_ATTRIBUTE_ERROR);
        }
        return MMI_RET_ERR;
    }
}


MMI_RET mmi_frm_scrn_set_attribute(MMI_ID parent_id, MMI_ID scrn_id, mmi_scrn_attrib_enum attrib)
{
    return mmi_frm_scrn_update_attribute(parent_id, scrn_id, attrib, MMI_TRUE);
}


MMI_RET mmi_frm_scrn_clear_attribute (MMI_ID parent_id, MMI_ID scrn_id, mmi_scrn_attrib_enum attrib)
{
    return mmi_frm_scrn_update_attribute(parent_id, scrn_id, attrib, MMI_FALSE);
}


mmi_ret mmi_frm_scrn_set_input_buf_mem (MMI_ID parent_id, MMI_ID scrn_id, mmi_malloc_func_ptr malloc_fp, mmi_mfree_func_ptr mfree_fp, void *mem_fp_user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    base_node_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_SET_INPUT_BUF_MEM_MECH, parent_id, (MMI_ID)scrn_id, malloc_fp, mfree_fp, mem_fp_user_data);
    node = SG_GET_NODE_FROM_ROOT(_SCRN_ID(_PARENT_ID(parent_id, scrn_id), scrn_id));
    if (_IS_SCRN(node))
    {
        _SCRN(node)->mem_alloc = malloc_fp;
        _SCRN(node)->mem_free = mfree_fp;
        _SCRN(node)->mem_user_data = mem_fp_user_data;
        return MMI_RET_OK;
    }
    else
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_SET_INPUT_BUF_MEM_MECH_ERROR);
        return MMI_RET_ERR;
    }
}


mmi_ret mmi_frm_scrn_set_user_data (MMI_ID parent_id, MMI_ID scrn_id, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    base_node_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_SET_USER_DATA, parent_id, (MMI_ID)scrn_id, user_data);
    node = SG_GET_NODE_FROM_ROOT(_SCRN_ID(_PARENT_ID(parent_id, scrn_id), scrn_id));
    if (_IS_SCRN(node) || _IS_TAB(node))
    {
        _SCRN(node)->user_data = user_data;
        return MMI_RET_OK;
    }
    else
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_SET_USER_DATA_ERROR);
        /* not support set page user_data */
        return MMI_RET_ERR;
    }
}

mmi_ret mmi_frm_send_event_to_active_screen(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt && shell.active_scrn && shell.active_scrn->proc)
    {
        evt->user_data = shell.active_scrn->user_data;
        ret = shell.active_scrn->proc(evt);
    }
    return ret;
}


void *mmi_frm_scrn_get_user_data (MMI_ID parent_id, MMI_ID scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parent_id = _PARENT_ID(parent_id, scrn_id);
    return mmi_frm_get_user_data(parent_id, scrn_id);
}


U8* mmi_frm_scrn_get_active_gui_buf (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* pRet = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (shell.active_tab && shell.active_scrn)
    {
    #ifndef __MMI_NOT_TAB_SUPPORT__
        pRet = mmi_frm_scrn_tab_page_get_active_gui_buf();
    #endif /* __MMI_NOT_TAB_SUPPORT__ */
    }
    else if (shell.active_scrn)
    {
        pRet = shell.active_scrn->gui_buf;
    }
    else
    {
    #ifdef __MMI_FRM_HISTORY__
        if(shell.active_group == NULL)
        {
            pRet = (U8*)GetCurrGuiBuffer(GetCurrScrnId());
        }
    #endif /* __MMI_FRM_HISTORY__ */
    }
	return pRet;
}


U8* mmi_frm_scrn_get_gui_buf (MMI_ID parent_id, MMI_ID scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    scrn_node_struct *found;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parent_id = _PARENT_ID(parent_id, scrn_id);
    
    found = (scrn_node_struct*)SG_GET_NODE_FROM_ALL(_SCRN_ID(parent_id, scrn_id));
    if (found)
    {
        return found->gui_buf;
    }
    else
    {
        return NULL;
    }
}


WCHAR* mmi_frm_scrn_get_active_input_buf (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR* pRet = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (shell.active_tab && shell.active_scrn)
    {
        pRet = mmi_frm_scrn_tab_page_get_active_input_buf();
    }
    else if (shell.active_scrn)
    {
        pRet = shell.active_scrn->input_buf;
    }
    else
    {
    #ifdef __MMI_FRM_HISTORY__
        if(shell.active_group == NULL)
        { 
            pRet = (WCHAR*)GetCurrInputBuffer(GetCurrScrnId());
        }
    #endif /* __MMI_FRM_HISTORY__ */
    }
	return pRet;
}


WCHAR* mmi_frm_scrn_get_input_buf (MMI_ID parent_id, MMI_ID scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    scrn_node_struct *found;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parent_id = _PARENT_ID(parent_id, scrn_id);
    found = (scrn_node_struct*)SG_GET_NODE_FROM_ALL(_SCRN_ID(parent_id, scrn_id));

    if (found)
    {
        return found->input_buf;
    }
    else
    {
        return NULL;
    }
}


void mmi_frm_scrn_clean_gui_buf (MMI_ID parent_id, MMI_ID scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    scrn_node_struct    *found;
    mmi_mfree_func_ptr  mfree_fp = history_buffer_free;
    void                *mem_user_data = SCENARIO_HISTORY_DATA;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parent_id = _PARENT_ID(parent_id, scrn_id);
    found = (scrn_node_struct*)SG_GET_NODE_FROM_ALL(_SCRN_ID(parent_id, scrn_id));

    if (found &&
        (found->type == SCENARIO_SCRN_NODE || found->type == SCENARIO_TAB_PAGE_NODE))
    {
        if (found->gui_buf && found->gui_buf != (U8 *)&g_fake_gui_buf)
        {
            mfree_fp(found->gui_buf, mem_user_data);
        }
		found->gui_buf = NULL;
        found->gui_buf_size = 0;
    }
}


void mmi_frm_scrn_clean_input_buf (MMI_ID parent_id, MMI_ID scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    scrn_node_struct    *found;
    mmi_mfree_func_ptr  mfree_fp = history_buffer_free;
    void                *mem_user_data = SCENARIO_HISTORY_DATA;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parent_id = _PARENT_ID(parent_id, scrn_id);
    found = (scrn_node_struct*)SG_GET_NODE_FROM_ALL(_SCRN_ID(parent_id, scrn_id));

    if (found &&
        (found->type == SCENARIO_SCRN_NODE || found->type == SCENARIO_TAB_PAGE_NODE))
    {
        if (found->input_buf)
        {
            mfree_fp(found->input_buf, mem_user_data);
            found->input_buf = NULL;
            found->input_buf_size = 0;
        }
    }
}



void mmi_frm_scrn_add_history (MMI_ID parent_id, MMI_ID scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parent_id = _PARENT_ID(parent_id, scrn_id);
    if ((MMI_ID)shell.active_group->id == (MMI_ID)parent_id &&
        (MMI_ID)shell.active_scrn->id == (MMI_ID)scrn_id)
    {
        /* Only allow the active screen to add it into history */
        if (mmi_frm_is_in_backward_scenario() == MMI_FALSE)
        {
            /* Only support on the screen node, don't support on tab or tab-page. */

            scrn_add_history(_SCRN(shell.active_scrn));
            ResetBit(shell.active_scrn->attrib, NODE_ATTRIB_AUTO_ADD_HISTORY_IDX);
            ResetBit(shell.active_scrn->attrib, NODE_ATTRIB_FREE_NODE_IDX);
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_ADD_HISTORY, parent_id, (MMI_ID)scrn_id);
        }
        else
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_ADD_HISTORY_ERR_1, parent_id, (MMI_ID)scrn_id);
        }
    }
    else
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_ADD_HISTORY_ERR_2, parent_id, (MMI_ID)scrn_id);
    }
}


mmi_ret mmi_frm_scrn_get_info (MMI_ID parent_id, MMI_ID scrn_id, mmi_scrn_node_struct *node_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    scrn_node_struct *found;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parent_id = _PARENT_ID(parent_id, scrn_id);
    found = (scrn_node_struct*)SG_GET_NODE_FROM_ALL(_SCRN_ID(parent_id, scrn_id));
    if (found)
    {
        node_info->parent           = found->parent ? found->parent->id : GRP_ID_INVALID;
        node_info->priority         = found->priority;
        node_info->user_data        = found->user_data;
        node_info->entry_proc       = (FuncPtr)found->entry_proc;
        node_info->exit_proc        = (FuncPtr)found->exit_proc;
        node_info->leave_proc       = found->proc;
        node_info->gui_buf_size     = found->gui_buf_size;
        node_info->input_buf_size   = found->input_buf_size;
        node_info->gui_buf          = found->gui_buf;
        node_info->input_buf        = found->input_buf;
        node_info->state            = found->state;

        return MMI_RET_OK;
    }
    else
    {
        if (node_info)
        {
            memset(node_info, 0, sizeof(mmi_scrn_node_struct));
        }
        return MMI_RET_ERR;
    }
}


MMI_ID mmi_frm_scrn_get_active_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID uRet = SCR_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (shell.active_tab)
    {
        uRet = shell.active_tab->id;
    }
    else if (shell.active_scrn)
    {
        uRet = shell.active_scrn->id;
    }
    else
    {
    #ifdef __MMI_FRM_HISTORY__
        if(shell.active_group == NULL)
        {
            return (MMI_ID)GetActiveScreenId();
        }
    #endif /* __MMI_FRM_HISTORY__ */
    }
	return uRet;
}

MMI_BOOL mmi_frm_is_in_tab_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return shell.active_tab ? MMI_TRUE : MMI_FALSE;
}


MMI_ID mmi_frm_scrn_get_neighbor_id (MMI_ID parent_id, MMI_ID base_id, mmi_scenario_node_flag flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    group_node_struct   *parent = NULL;
    scrn_node_struct    *found = NULL;
    MMI_ID              rst_id = SCR_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Find group in scenario tree only */
    //MMI_ASSERT(parent_id != GRP_ID_ROOT);
    parent = _GROUP(SG_GET_NODE_FROM_ALL(parent_id));

    if (parent)
    {
        /* Check if base_id is the screen id */
        found = _SCRN(SG_GET_CHILD(parent, _SCRN_ID(parent_id, base_id)));
        if (found == NULL)
        {
            /* Check if base_id is the group id */
            found = _SCRN(SG_GET_CHILD(parent, (U32)base_id));
        }

        switch (flag)
        {
        case MMI_FRM_NODE_AT_BEGINNING_FLAG:
            if (parent->m_head)
            {
                rst_id = parent->m_head->id;
            }
            break;
        case MMI_FRM_NODE_AT_LATEST_FLAG:
            if (parent->m_tail)
            {
                rst_id = parent->m_tail->id;
            }
            break;
        case MMI_FRM_NODE_AFTER_FLAG:
            if (find_next_node(_NODE(found)))
            {
                rst_id = found->m_next->id;
            }
            break;
        case MMI_FRM_NODE_BEFORE_FLAG:
            if (find_prev_node(_NODE(found)))
            {
                rst_id = found->m_prev->id;
            }
            break;
        default:
            MMI_ASSERT(0);
        }
    }

    //MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_GET_NEIGHBOR_ID, parent_id, base_id, flag, rst_id);

    return rst_id;
}


U32 mmi_frm_scrn_get_count (MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    group_node_struct *found;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(group_id != GRP_ID_ROOT);
    /* Find group in scenario tree only */
    found = _GROUP(SG_GET_NODE_FROM_ALL(group_id));  
    if (found)
    {
        return found->m_count;
    }
    else
    {
        return 0;
    }
}




MMI_ID mmi_frm_scrn_get_top_parent_group_id(MMI_ID parent_id, MMI_ID scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    scrn_node_struct *found = NULL;
    group_node_struct *group = NULL;
    MMI_ID id = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(parent_id != GRP_ID_ROOT);
    found = _SCRN(SG_GET_NODE_FROM_ROOT(_SCRN_ID(parent_id, scrn_id)));
    if (found && found->parent != &shell.scenario_root)
    {
        id = found->id;
        group = found->parent;
    }
    while (group && group->parent != &shell.scenario_root)
    {
        id = group->parent->id;
        group = group->parent;
    }
    return id;
}

MMI_BOOL mmi_frm_scrn_query_first_entry (MMI_ID parent_id, MMI_ID scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* TO-DO */
    /* help the application to know if first entry the screen. (now is use get current gui buffer) */
    parent_id = _PARENT_ID(parent_id, scrn_id);
    return MMI_FALSE;
}

mmi_scenario_state_enum mmi_frm_scrn_get_state (MMI_ID parent_id, MMI_ID scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    scrn_node_struct *found;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parent_id = _PARENT_ID(parent_id, scrn_id);
    found = (scrn_node_struct*)(SG_GET_NODE_FROM_ALL(_SCRN_ID(parent_id,scrn_id)));
    if (found)
    {
        return (mmi_scenario_state_enum)found->state;
    }
    else
    {
        return MMI_SCENARIO_STATE_NONE;
    }
}


MMI_BOOL mmi_frm_scrn_is_present (MMI_ID parent_id, MMI_ID scrn_id, mmi_node_present_flag flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    scrn_node_struct    *found;
    MMI_BOOL            rst = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parent_id = _PARENT_ID(parent_id, scrn_id);
    found = (scrn_node_struct*)(SG_GET_NODE_FROM_ALL(_SCRN_ID(parent_id,scrn_id)));

    if (found)
    {
        if (flag == MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG &&
            shell.active_scrn != found)
        {
            /*
             * the behavior is the same with IsScreenPresent().
             * the screen id is in the scenario tree but not the active screen.
             */
            rst = MMI_TRUE;
        }
        else if (flag == MMI_FRM_NODE_ALL_FLAG)
        {
            rst = MMI_TRUE;
        }
    }

    //MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_IS_PRESENT, parent_id, scrn_id, flag, rst);

    return rst;
}


mmi_ret mmi_frm_scrn_send_to_parent (MMI_ID self_gid, mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    group_node_struct *sender;
    mmi_ret           ret = MMI_RET_ERR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(self_gid != GRP_ID_ROOT);
    sender = _GROUP(SG_GET_NODE_FROM_ROOT(self_gid));
    if (sender)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_SEND_TO_PARENT, (MMI_ID)self_gid);

        if (sender->proc)
        {
            ret = MMI_FRM_SEND_EVENT(evt, sender->proc, sender->user_data);
        }
    }
    return ret;
}


void mmi_frm_scrn_post_to_parent (MMI_ID self_gid, mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_post_evt_struct post_evt = {0};
    group_node_struct   *sender = _GROUP(SG_GET_NODE_FROM_ROOT(self_gid));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sender == NULL)
    {
        /* self_gid isn't exist */
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_POST_TO_PARENT, (MMI_ID)self_gid, G_POST_EVENT_NO_RECEIVER);
        return;
    }
    MMI_ASSERT(self_gid != GRP_ID_ROOT);
    MMI_ASSERT(sender && evt->size <= MMI_SCENARIO_POST_GROUP_EVENT_MAX_SIZE<<2);

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_POST_TO_PARENT, (MMI_ID)self_gid, G_POST_EVENT);
    MMI_FRM_INIT_EVENT(&post_evt, EVT_ID_SCRN_POST_PARENT_NOTIFY);
    post_evt.receiver_gid = self_gid; /* screen's parent id */
    post_evt.need_result = MMI_FALSE;
    memcpy(&post_evt.data[0], evt, evt->size);

    MMI_FRM_POST_EVENT(&post_evt, mmi_scenario_external_post_proc, NULL);
}

MMI_ID mmi_frm_scrn_get_target_id()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 targ_scrn_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((shell.state == MMI_SCENARIO_STATE_NONE) || (shell.targ_node == NULL))
        return SCR_ID_INVALID;
    targ_scrn_id = (shell.targ_node->id)&0xFFFF;
    return targ_scrn_id;
}



mmi_ret mmi_frm_scrn_set_ui_data(MMI_ID parent_id, MMI_ID scrn_id, U32 ui_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    base_node_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FRM_HISTORY__
    if (parent_id == GRP_ID_INVALID)
    {
        return mmi_frm_set_hist_ui_data(scrn_id, ui_data);
    }
    else
#endif /* __MMI_FRM_HISTORY__ */
    {
        node = SG_GET_NODE_FROM_ROOT(_SCRN_ID(_PARENT_ID(parent_id, scrn_id), scrn_id));
        if (_IS_SCRN(node) || _IS_TAB(node))
        {
            _SCRN(node)->ui_data = ui_data;
            return MMI_RET_OK;
        }
        else
        {
            return MMI_RET_ERR;        
        }
    }
}


U32 mmi_frm_scrn_get_ui_data(MMI_ID parent_id, MMI_ID scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    base_node_struct *node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_FRM_HISTORY__
    if (parent_id == GRP_ID_INVALID)
    {
        return mmi_frm_get_hist_ui_data(scrn_id);
    }
    else
#endif /* __MMI_FRM_HISTORY__ */
    {
        if (scrn_id == SCR_ID_INVALID)
        {
            /* Find the group node in scenario tree and shell.scenario_dangle */
            node = SG_GET_NODE_FROM_ROOT(parent_id);
        }
        else
        {
            /* Find the screen node in scenario tree */
            node = SG_GET_NODE_FROM_ALL(_SCRN_ID(parent_id, scrn_id));
        }

        if (node)
        {
            return _SCRN(node)->ui_data;
        }
    }
    return 0;
}


#ifndef __MMI_NOT_TAB_SUPPORT__
/***************************************************************************** 
*  Scenario Tab & Tab-page
*****************************************************************************/
static tab_page_node_struct* create_new_page(MMI_ID parent_id, MMI_ID id, mmi_scrn_func entry_proc, void *user_data, U8 page_idx, U8* page_icon, WCHAR* page_label)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tab_page_node_struct *page = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    page = (tab_page_node_struct*)SG_GET_NODE_FROM_ROOT(_SCRN_ID(parent_id, id));
    if (page == NULL)
    {
        page = _MMI_MEM_ALLOC(sizeof(tab_page_node_struct), SCENARIO_TAB_PAGE_NODE);

        
        page->type = SCENARIO_TAB_PAGE_NODE;
        page->entry_proc = entry_proc;
        if (entry_proc)
        {
            SetBit(page->attrib, NODE_ATTRIB_AUTO_ADD_HISTORY_IDX);
        }
        page->proc      = mmi_frm_dummy_proc;
        page->user_data = user_data;
        page->id        = _SCRN_ID(parent_id, id);
        page->parent    = (group_node_struct *)SG_GET_NODE_FROM_ROOT(parent_id);
        page->index     = page_idx;
        page->icon      = page_icon;
        page->label     = page_label;
    }

    return page;
}


S32 find_page_by_id(tab_page_node_struct **page_table, U8 page_count, MMI_ID parent_id, MMI_ID page_id)
{
    S32 i;
    for (i = 0; i < page_count; i++)
    {
        if (page_table[i] && page_table[i]->id == _SCRN_ID(parent_id, page_id))
        {
            return i;
        }
    }
    return -1;
}



static void change_tab_info(tab_node_struct *tab, mmi_frm_tab_struct *tab_pages_info_array, U8 tab_pages_count, U8 sel_idx)
{
    U32 i = 0;
    S32 idx;
    tab_page_node_struct *page = NULL;
    tab_page_node_struct **old_pages = (tab_page_node_struct **)mmi_frm_malloc(tab->page_count*sizeof(tab_page_node_struct **));
	tab->cur_sel_index      = (sel_idx < tab_pages_count) ? sel_idx : 0;


    page = _TAB_PAGE(tab->m_tail);
    while (page)
    {
        old_pages[i] = page;
        page = _TAB_PAGE(page->m_prev);
        i++;
    }
    tab->m_tail = NULL;
    tab->m_head = NULL;
    tab->m_count = 0;
    for (i = 0; i < tab_pages_count; i++)
    {
        idx = find_page_by_id(old_pages, tab->page_count, tab->parent->id, tab_pages_info_array[i].screen_id);
        if (idx < 0)
        {
            page = create_new_page(
                    (MMI_ID)tab->parent->id,
                    (MMI_ID)tab_pages_info_array[i].screen_id,
                    (mmi_scrn_func)tab_pages_info_array[i].tab_entry_func,
                    tab_pages_info_array[i].user_data,
                    (U8)i,
                    tab_pages_info_array[i].tab_icon,
                    (WCHAR*)(tab_pages_info_array[i].tab_string));

        }
        else
        {
            page = old_pages[idx];
            page->index     = i;
            //page->icon      = tab_pages_info_array[i].tab_icon;
            //page->label     = tab_pages_info_array[i].tab_string;
            //page->entry_proc = tab_pages_info_array[i].tab_entry_func;
            //page->user_data = tab_pages_info_array[i].user_data;
            old_pages[idx] = NULL;
        }
        /* insert page in page from head */
        if (tab->m_tail == NULL)
        {
            /* list is empty */
            tab->m_head = _NODE(page);
            tab->m_tail = _NODE(page);
            page->m_prev = NULL;
            page->m_next = NULL;
        }
        else
        {
            page->m_prev = NULL;
            page->m_next = _NODE(tab->m_head);
            tab->m_head->m_prev = _NODE(page);
            tab->m_head = _NODE(page);
        }
        tab->m_count++;

    }
    for (i = 0; i < tab->page_count; i++)
    {
        if (old_pages[i])
        {
            SG_FREE_NODE(old_pages[i]);
        }
    }
    tab->page_count = tab_pages_count;
    mmi_frm_free(old_pages);
}


static tab_node_struct* create_new_tab(MMI_ID parent_id, MMI_ID id, mmi_scrn_func entry_proc, void *user_data, mmi_frm_tab_struct *tab_pages_info_array, U8 tab_pages_count, U8 sel_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tab_node_struct *tab = NULL;
    tab_page_node_struct *page = NULL;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    tab = (tab_node_struct*)SG_GET_NODE_FROM_ROOT(_SCRN_ID(parent_id, id));
    if ((tab && tab->type != SCENARIO_TAB_NODE) ||
        tab == NULL)
    {
        tab = _MMI_MEM_ALLOC(sizeof(tab_node_struct), SCENARIO_TAB_NODE);

        
        tab->type               = SCENARIO_TAB_NODE;
        tab->entry_proc         = entry_proc;
        if (entry_proc)
        {
            SetBit(tab->attrib, NODE_ATTRIB_AUTO_ADD_HISTORY_IDX);
        }
        tab->proc               = mmi_frm_dummy_proc;
        tab->user_data          = user_data;
        tab->id                 = _SCRN_ID(parent_id, id);
        tab->parent             = (group_node_struct *)SG_GET_NODE_FROM_ROOT(parent_id);
        tab->page_count         = tab_pages_count;
        tab->cur_sel_index      = (sel_idx < tab_pages_count) ? sel_idx : 0;
        tab->use_pen_switch     = MMI_FALSE;
        tab->first_item_index   = (S8)UI_HORIZONTAL_TAB_BAR_ERROR_INDEX;
        for (i = 0; i < tab_pages_count; i++)
        {
            page = create_new_page(
                    (MMI_ID)parent_id,
                    (MMI_ID)tab_pages_info_array[i].screen_id,
                    (mmi_scrn_func)tab_pages_info_array[i].tab_entry_func,
                    tab_pages_info_array[i].user_data,
                    (U8)i,
                    tab_pages_info_array[i].tab_icon,
                    (WCHAR*)(tab_pages_info_array[i].tab_string));

            SetBit(page->state, MMI_SCENARIO_STATE_INACTIVE_IDX);
            /* insert page in page from head */
            if (tab->m_tail == NULL)
            {
                /* list is empty */
                tab->m_head = _NODE(page);
                tab->m_tail = _NODE(page);
                page->m_prev = NULL;
                page->m_next = NULL;
            }
            else
            {
                page->m_prev = NULL;
                page->m_next = _NODE(tab->m_head);
                tab->m_head->m_prev = _NODE(page);
                tab->m_head = _NODE(page);
            }
            tab->m_count++;
        }

    }

    return tab;
}


MMI_BOOL mmi_frm_scrn_tab_enter(MMI_ID group_id, MMI_ID tab_id, FuncPtr exit_proc, FuncPtr entry_proc, mmi_frm_tab_struct *tab_pages_info_array, U8 tab_pages_count, U8 sel_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL rst = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_TAB_ENTER, group_id, (MMI_ID)tab_id, exit_proc, entry_proc,tab_pages_count,sel_idx, SG_API_BEG);
    MMI_ASSERT(group_id != GRP_ID_ROOT);
    rst = scrn_node_enter (
            group_id, 
            tab_id, 
            (mmi_scrn_func)exit_proc, 
            (mmi_scrn_func)entry_proc,
            MMI_FRM_TAB, 
            tab_pages_info_array, 
            tab_pages_count, 
            sel_idx);
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_TAB_ENTER, group_id, (MMI_ID)tab_id, exit_proc, entry_proc,tab_pages_count,sel_idx, SG_API_END);
    
    return rst;
}


MMI_BOOL mmi_frm_scrn_tab_page_enter (MMI_ID parent_id, MMI_ID tab_id, MMI_ID page_id, FuncPtr exit_proc, FuncPtr entry_proc, mmi_frm_scrn_type_enum scrn_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scenario_state_enum state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scenario_is_redrawing() == MMI_FALSE)
    {
        state = mmi_frm_scrn_get_state(parent_id, tab_id);
        MMI_ASSERT(IsBitSet(state, MMI_SCENARIO_STATE_ACTIVE_IDX));
    }
    return mmi_frm_scrn_enter(parent_id, page_id, exit_proc, entry_proc, MMI_FRM_TAB_PAGE);
}


tab_page_node_struct*  get_page_node(U32 group_id, group_node_struct *group_node, U32 tab_id, tab_node_struct *tab_node, MMI_ID search_page_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tab_page_node_struct *page = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (tab_node == NULL)
    {
        if (group_node == NULL)
            group_node = (group_node_struct*)SG_GET_NODE_FROM_ALL(group_id);
        tab_node = _TAB(SG_GET_CHILD(group_node, _SCRN_ID(group_id, tab_id)));
        if (tab_node == NULL)
        {
            return NULL;
        }
    }

    if (_IS_TAB(tab_node))
    {
        page = _TAB_PAGE(tab_node->m_tail);
        while (page)
        {
            /* simple check the page id. Check the complete id is better. */
            if ((U16)(page->id) == search_page_id)
            {
                return page;
            }
            page = _TAB_PAGE(page->m_prev);
        }
    }
    /* can't find page node */
    return NULL;


}


static void tab_l_arrow_key_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 next_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(shell.active_tab);

    if(shell.active_tab->page_count <= 1)
    {
        return;
    }
	if (wgui_horizontal_tab_bar_is_disabled(shell.active_tab->cur_sel_index) == MMI_TRUE)
	{
		return;
	}
	next_index = shell.active_tab->cur_sel_index;
	do
	{
		if (next_index > 0)
		{
			next_index = next_index - 1;
		}
		else
		{
			next_index = shell.active_tab->page_count - 1;
		}
	} while(wgui_horizontal_tab_bar_is_disabled(next_index) == MMI_TRUE);

	if (next_index == shell.active_tab->cur_sel_index)
	{
		return;
	}

    wgui_horizontal_tab_bar_store_first_displayed_item();
    mmi_frm_scrn_tab_change_page_index((MMI_ID)shell.active_group->id, (MMI_ID)shell.active_tab->id, next_index);
}


static void tab_r_arrow_key_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 next_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(shell.active_tab);

    if(shell.active_tab->page_count <= 1)
    {
        return;
    }
	if (wgui_horizontal_tab_bar_is_disabled(shell.active_tab->cur_sel_index) == MMI_TRUE)
	{
		return;
	}
	next_index = shell.active_tab->cur_sel_index;
	do
	{
		if (next_index < shell.active_tab->page_count - 1)
		{
			next_index = next_index + 1;
		}
		else
		{
			next_index = 0;
		}
	} while(wgui_horizontal_tab_bar_is_disabled(next_index) == MMI_TRUE);

	if (next_index == shell.active_tab->cur_sel_index)
	{
		return;
	}

    wgui_horizontal_tab_bar_store_first_displayed_item();
    mmi_frm_scrn_tab_change_page_index((MMI_ID)shell.active_group->id, (MMI_ID)shell.active_tab->id, next_index);
}


void tab_l_arrow_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_struct evt = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_TAB_POST_LEFT_ARROW_NOTIFY);
    MMI_FRM_POST_EVENT(&evt, mmi_scenario_external_post_proc, NULL);
}

void tab_r_arrow_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_struct evt = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_TAB_POST_RIGHT_ARROW_NOTIFY);
    MMI_FRM_POST_EVENT(&evt, mmi_scenario_external_post_proc, NULL);
}



MMI_ID mmi_frm_scrn_tab_page_get_active_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (shell.active_tab)
    {
        return (shell.active_scrn) ? (MMI_ID)shell.active_scrn->id : SCR_ID_INVALID;
    }
    else
    {
        return SCR_ID_INVALID;
    }
}


U8 mmi_frm_scrn_tab_get_active_page_index (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tab_node_struct *tab = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (shell.active_scrn && shell.active_scrn->type == SCENARIO_TAB_NODE)
    {
        /* It is in the tab screen */
        tab = _TAB(shell.active_scrn);
        return tab->cur_sel_index;
    }
    else if (shell.active_tab && shell.active_scrn && shell.active_scrn->type == SCENARIO_TAB_PAGE_NODE)
    {
        /* It is in the tab page */
        tab = _TAB(shell.active_tab);
        return tab->cur_sel_index;
    }
    return 0;
}


mmi_ret mmi_frm_scrn_tab_page_set_user_data (MMI_ID parent_id, MMI_ID tab_id, MMI_ID page_id, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tab_page_node_struct *page = get_page_node(parent_id, NULL, tab_id, NULL, page_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (_IS_TAB_PAGE(page))
    {
        page->user_data = user_data;
        return MMI_RET_OK;
    }

    return MMI_RET_ERR;
}


mmi_ret mmi_frm_scrn_tab_page_set_attribute(MMI_ID parent_id, MMI_ID tab_id, MMI_ID page_id, mmi_tab_page_attrib_enum attrib)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tab_page_node_struct *page = get_page_node(parent_id, NULL, tab_id, NULL, page_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (_IS_TAB_PAGE(page))
    {
		switch (attrib)
		{
			case MMI_TAB_PAGE_DISABLE:
				SetBit(page->attrib, NODE_ATTRIB_PAGE_DISABLE);
				break;
				
			default:
				break;
		}
		return MMI_RET_OK;
    }

	return MMI_RET_ERR;
}


mmi_ret mmi_frm_scrn_tab_page_clear_attribute(MMI_ID parent_id, MMI_ID tab_id, MMI_ID page_id, mmi_tab_page_attrib_enum attrib)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tab_page_node_struct *page = get_page_node(parent_id, NULL, tab_id, NULL, page_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (_IS_TAB_PAGE(page))
    {
		switch (attrib)
		{
			case MMI_TAB_PAGE_DISABLE:
				ResetBit(page->attrib, NODE_ATTRIB_PAGE_DISABLE);
				break;
				
			default:
				break;
		}
		return MMI_RET_OK;
    }

	return MMI_RET_ERR;
}


void* mmi_frm_scrn_tab_page_get_user_data (MMI_ID parent_id, MMI_ID tab_id, MMI_ID page_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tab_page_node_struct *page = get_page_node(parent_id, NULL, tab_id, NULL, page_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (_IS_TAB_PAGE(page))
    {
        return page->user_data;
    }

    return NULL;
}


mmi_ret mmi_frm_scrn_tab_page_get_info (MMI_ID parent_id, MMI_ID tab_id, MMI_ID page_id, mmi_scrn_tab_page_node_struct *node_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tab_page_node_struct *found = get_page_node(parent_id, NULL, tab_id, NULL, page_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (found && _TAB_PAGE(found))
    {
        node_info->tab              = tab_id;
        node_info->parent           = parent_id;
        node_info->user_data        = found->user_data;
        node_info->entry_proc       = (FuncPtr)found->entry_proc;
        node_info->exit_proc        = (FuncPtr)found->exit_proc;
        node_info->gui_buf_size     = found->gui_buf_size;
        node_info->input_buf_size   = found->input_buf_size;
        node_info->gui_buf          = found->gui_buf;
        node_info->input_buf        = found->input_buf;
        node_info->state            = found->state;

        return MMI_RET_OK;
    }
    else
    {
        memset(node_info, 0, sizeof(mmi_scrn_tab_page_node_struct));

        return MMI_RET_ERR;
    }
}


mmi_scenario_state_enum mmi_frm_scrn_tab_page_get_state (MMI_ID parent_id, MMI_ID tab_id, MMI_ID page_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tab_page_node_struct *found = get_page_node(parent_id, NULL, tab_id, NULL, page_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (found && _TAB_PAGE(found))
    {
        return (mmi_scenario_state_enum)found->state;
    }
    else
    {
        return MMI_SCENARIO_STATE_NONE;
    }
}


U8 *mmi_frm_scrn_tab_page_get_gui_buf (MMI_ID parent_id, MMI_ID tab_id, MMI_ID page_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tab_page_node_struct *found = get_page_node(parent_id, NULL, tab_id, NULL, page_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (found && _TAB_PAGE(found))
    {
        return found->gui_buf;
    }

    return NULL;
}

U8 *mmi_frm_scrn_tab_page_get_active_gui_buf (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tab_page_node_struct *active_page = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (shell.active_tab && shell.active_scrn && _IS_TAB_PAGE(shell.active_scrn))
    {
        active_page = _TAB_PAGE(shell.active_scrn);
        return active_page->gui_buf;
    }

    return NULL;
}



WCHAR *mmi_frm_scrn_tab_page_get_input_buf (MMI_ID parent_id, MMI_ID tab_id, MMI_ID page_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tab_page_node_struct *found = get_page_node(parent_id, NULL, tab_id, NULL, page_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (found && _TAB_PAGE(found))
    {
        return found->input_buf;
    }

    return NULL;
}


MMI_BOOL mmi_frm_scrn_tab_change_page_index (MMI_ID group_id, MMI_ID tab_id, U8 page_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL                    rst = MMI_FALSE;
    scrn_node_struct            *found;
    tab_page_node_struct        *page;
    mmi_scrn_essential_struct   _data = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_TAB_CHANGE_PAGE_INDEX, group_id, (MMI_ID)tab_id, page_index);
    found = _SCRN(SG_GET_NODE_FROM_ROOT(_SCRN_ID(group_id, tab_id)));

    if (found && _IS_TAB(found))
    {
        if (IsBitSet(found->state, MMI_SCENARIO_STATE_INACTIVE_IDX))
        {
            /* tab is inactive */
            _TAB(found)->cur_sel_index = page_index; 

            rst = MMI_TRUE;
        }
        else
        {
            /* tab is active screen */
            if (_TAB(found)->cur_sel_index == page_index && 
                IsBitSet(_TAB(found)->state, MMI_SCENARIO_STATE_ACTIVE_IDX))
            {
                rst = MMI_TRUE;
                //return MMI_TRUE;
            }

            if (rst != MMI_TRUE)
            {
                page = _TAB_PAGE(move_node_to_tail(_NODE(found), NULL, page_index, MMI_TRUE));
    
                if (page && page->entry_proc)
                {
                    _data.group_id = (MMI_ID)page->parent->id;
                    _data.tab_id = (MMI_ID)shell.active_tab->id;
                    _data.scrn_id = (MMI_ID)page->id;
                    _data.user_data = page->user_data;
                    page->entry_proc(&_data);
                }
    
                rst = MMI_TRUE;
            }
        }
    }

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_TAB_CHANGE_PAGE_INDEX_END, rst);
    return rst;
}


MMI_BOOL mmi_frm_scrn_tab_get_bar_items(tab_bar_item_type *tab_bar_items_p, S8 *tabs_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tab_page_node_struct *page;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (shell.active_tab)
    {
        *tabs_p = shell.active_tab->page_count;
        if (shell.active_tab->page_count == 0)
        {
            return MMI_FALSE;
        }

        memset(tab_bar_items_p, 0, sizeof(tab_bar_item_type)*shell.active_tab->page_count);

        page = _TAB_PAGE(shell.active_tab->m_tail);
        while (page)
        {
            tab_bar_items_p[page->index].icon = page->icon;
            tab_bar_items_p[page->index].text = (UI_string_type)page->label;
            
			if (IsBitSet(page->attrib, NODE_ATTRIB_PAGE_DISABLE))
			{
				wgui_horizontal_tab_bar_set_disabled(page->index, MMI_TRUE);
			}
			page = _TAB_PAGE(page->m_prev);
        }
        return MMI_TRUE;
    }
    else
    {
//        return mmi_frm_get_tab_bar_items_int(tab_bar_items_p, tabs_p);
        return MMI_FALSE;
    }
}



MMI_BOOL mmi_frm_scrn_tab_change_page_items(MMI_ID group_id, MMI_ID tab_id, mmi_frm_tab_struct *tab_pages_info_array, U8 tab_pages_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tab_node_struct         *found;
    tab_page_node_struct    *page;
    S32                     i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_TAB_CHANGE_PAGE_ITEMS, group_id, (MMI_ID)tab_id, tab_pages_count);
    //found = _TAB(_GET_NODE(group_id, NULL, _SCRN_ID(group_id, tab_id), GROUP_TREE));
    found = _TAB(SG_GET_NODE_FROM_ROOT(_SCRN_ID(group_id, tab_id)));

    if (found && _IS_TAB(found) && _IS_GROUP(found->parent) && 
        found->m_tail && _IS_TAB_PAGE(found->m_tail) &&
        IsBitSet(found->m_tail->state, MMI_SCENARIO_STATE_INACTIVE_IDX))
    {
        SG_FREE_NODE_CHILDREN(found);

        /* create new tab page items */
        for (i = 0; i < tab_pages_count; i++)
        {
            page = create_new_page(
                    (MMI_ID)found->parent->id,
                    (MMI_ID)tab_pages_info_array[i].screen_id,
                    (mmi_scrn_func)tab_pages_info_array[i].tab_entry_func,
                    tab_pages_info_array[i].user_data,
                    (U8)i,
                    tab_pages_info_array[i].tab_icon,
                    (WCHAR*)(tab_pages_info_array[i].tab_string));

            SetBit(page->state, MMI_SCENARIO_STATE_INACTIVE_IDX);
            /* insert page to head */
            page->m_prev = NULL;
            page->m_next = found->m_head;
            if (found->m_head)
            {
                found->m_head->m_prev = (base_node_struct*)page;
            }
            found->m_head = (base_node_struct*)page;
            
            if (found->m_count == 0)
            {
                found->m_head = (base_node_struct*)page;
                found->m_tail = (base_node_struct*)page;
            }
            found->m_count++;
        }
        found->page_count       = tab_pages_count;
        found->cur_sel_index    = (found->cur_sel_index < tab_pages_count) ? found->cur_sel_index : 0;

        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_TAB_CHANGE_PAGE_ITEMS_END, MMI_TRUE);
        return MMI_TRUE;
    }
    else
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_TAB_CHANGE_PAGE_ITEMS_END, MMI_FALSE);
        return MMI_FALSE;
    }
}

#endif /* __MMI_NOT_TAB_SUPPORT__ */


WCHAR *mmi_frm_scrn_tab_page_get_active_input_buf (void)
{
#ifndef __MMI_NOT_TAB_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tab_page_node_struct *active_page = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (shell.active_tab && shell.active_scrn && _IS_TAB_PAGE(shell.active_scrn))
    {
        active_page = _TAB_PAGE(shell.active_scrn);
        return active_page->input_buf;
    }
#endif /* __MMI_NOT_TAB_SUPPORT__ */
    return NULL;
}


MMI_ID mmi_frm_scrn_tab_get_active_id(void)
{
#ifndef __MMI_NOT_TAB_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (shell.active_tab) ? shell.active_tab->id : SCR_ID_INVALID;
#else
    return SCR_ID_INVALID;
#endif  /* __MMI_NOT_TAB_SUPPORT__ */
}


/***************************************************************************** 
 * FUNCTION
 *  mmi_frm_scrn_in_external_goback
 * DESCRIPTION
 *  
 *   The function is for the temp solution of SSE. 
 *   Do not reference the function in other place.
 *
 * PARAMETERS
 *  None
 * RETURNS
 *  True for external goback
 *****************************************************************************/
MMI_BOOL mmi_frm_scrn_in_external_goback(void)
{
    if ((shell.state == MMI_SCENARIO_STATE_BACKWARD) && (shell.in_external_goback_process == 1)) 
    {
        return MMI_TRUE;
    }
    else
    {    
        return MMI_FALSE;
    }
}


typedef mmi_ret (*TraverseNodeOpFunc) (base_node_struct *node, void *arg);

static base_node_struct* traverse_scenario_tree(base_node_struct *start_node_ptr, TraverseNodeOpFunc scrnFunc, TraverseNodeOpFunc groupStartFunc, TraverseNodeOpFunc groupEndFunc, void* arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    base_node_struct    *curr_node, *ret_node = NULL;
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (start_node_ptr == NULL) 
    {
        return ret_node;
    }
    //MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_FRM_SCENARIO_REDRAW_TRAVERSE_TREE, start_node_ptr, start_node_ptr->type);
    
    
    switch (start_node_ptr->type)
    {
    case SCENARIO_GROUP_NODE:
        {
            group_node_struct* group_str = (group_node_struct*)start_node_ptr;
            if (groupStartFunc)
            {
                /* ret == MMI_RET_OK -> traverse the group. */
                if(groupStartFunc(start_node_ptr, arg) != MMI_RET_OK)
                    ret_node = (base_node_struct*)group_str;
            }
            if(ret_node != NULL)
                return ret_node;

            for (curr_node = group_str->m_head; curr_node != NULL; curr_node = curr_node->m_next)
            {
                ret_node = traverse_scenario_tree(curr_node, scrnFunc, groupStartFunc, groupEndFunc, arg);
                if(ret_node != NULL)
                    break;
            }
            if(ret_node != NULL)
                return ret_node;

            if (groupEndFunc && groupEndFunc(start_node_ptr, arg) != MMI_RET_OK)
            {
                ret_node = start_node_ptr;
            }
        }
        break;

    case SCENARIO_TAB_NODE:
    case SCENARIO_TAB_PAGE_NODE:
    case SCENARIO_SCRN_NODE:
        if (scrnFunc && scrnFunc(start_node_ptr, arg) != MMI_RET_OK)
        {
            ret_node = start_node_ptr;
        }
        break;

    default:
        MMI_ASSERT(MMI_FALSE);
    }
    return ret_node;
}


static mmi_ret scrn_check_small(base_node_struct *node_ptr, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    scrn_node_struct*           scrn_ptr = _SCRN(node_ptr);
    traverse_find_ctxt_struct*  find_ctxt_ptr = (traverse_find_ctxt_struct*) arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_FRM_SCENARIO_REDRAW_SCRN_CHECK_SMALL, scrn_ptr->id, scrn_ptr->attrib);

    if (_IS_TAB_PAGE(scrn_ptr))
    {
        return MMI_RET_ERR;
    }

    if (_IS_TAB(scrn_ptr))
    {
        scrn_ptr = _SCRN(_TAB_PAGE(_TAB(node_ptr)->m_tail));
    }

    if (IsBitReset(scrn_ptr->attrib, NODE_ATTRIB_SMALL_SCREEN_IDX))
    {  
        find_ctxt_ptr->topmost_full_scrn_id = _SCRN(node_ptr)->id;
        find_ctxt_ptr->history_idx = find_ctxt_ptr->tmp_idx;
    }
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_FRM_SCENARIO_REDRAW_FIND_CTXT_DUMP, find_ctxt_ptr->topmost_full_scrn_id, find_ctxt_ptr->history_idx, find_ctxt_ptr->tmp_idx);
    return MMI_RET_OK;
}

void group_check_small_by_id(U32 scrn_id, traverse_find_ctxt_struct* find_ctxt_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    base_node_struct* start_node_ptr = SG_GET_NODE_FROM_ROOT(scrn_id);
    traverse_scenario_tree(start_node_ptr, scrn_check_small, NULL, NULL, (void *) find_ctxt_ptr);
}
#ifndef __MMI_FRM_HISTORY__ 

U32 mmi_frm_get_screen_level_sg(U16 scrn_id)
{
    traverse_level_ctxt_struct      level_ctxt;

    level_ctxt.target_scrn_id = scrn_id;
    level_ctxt.result = 0;
    level_ctxt.currLevel = 0;
    group_check_level_by_id(shell.scenario_root.id, &level_ctxt);
    return level_ctxt.result;
}

MMI_BOOL mmi_frm_in_exit_hdlr_proc_sg(void)
{
    return IsBitSet(shell.state, MMI_SCENARIO_STATE_SCRN_EXIT_IDE) ? MMI_TRUE : MMI_FALSE;
}
void mmi_frm_switch_small_screen_redraw_sg(MMI_BOOL enable)
{
    isEnableSmallScrnRedraw_sg = enable;
}
#endif
static mmi_ret scrn_check_level(base_node_struct *node_ptr, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    scrn_node_struct*           scrn_ptr = _SCRN(node_ptr);
    traverse_level_ctxt_struct*  level_ctx_ptr = (traverse_level_ctxt_struct *) arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (_IS_TAB_PAGE(scrn_ptr))
    {
        return MMI_RET_OK;
    }
    level_ctx_ptr->currLevel++;

    if (_IS_TAB(scrn_ptr))
    {
        scrn_ptr = _SCRN(_TAB_PAGE(_TAB(node_ptr)->m_tail));
    }

    if (level_ctx_ptr->target_scrn_id == (scrn_ptr->id & 0xFFFF))
    {
        level_ctx_ptr->result = level_ctx_ptr->currLevel;
    }
    return MMI_RET_OK;        
}

void group_check_level_by_id(U32 scrn_id, traverse_level_ctxt_struct* level_ctxt_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    base_node_struct* start_node_ptr = SG_GET_NODE_FROM_ROOT(scrn_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   traverse_scenario_tree(start_node_ptr, scrn_check_level, NULL, NULL, (void *) level_ctxt_ptr);
}

static mmi_ret node_exec_entry_proc(scrn_node_struct*   scrn_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scrn_essential_struct   data = {0};
    mmi_ret                     ret = MMI_RET_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scrn_ptr->entry_proc)
    {
        data.group_id = scrn_ptr->parent->id;
        if (_IS_TAB_PAGE(scrn_ptr) && shell.active_tab)
        {
            data.tab_id = shell.active_tab->id;
        }
        else
        {
            data.tab_id = SCR_ID_INVALID;
        }
        data.scrn_id = scrn_ptr->id;
        data.user_data = scrn_ptr->user_data;

        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_FRM_SCENARIO_REDRAW_SCRN_EXEC_ENTRY, data.scrn_id, scrn_ptr->entry_proc, data.user_data);
        ret = scrn_ptr->entry_proc(&data);
    }
    return ret;
}

static mmi_ret scrn_redraw_clean(scrn_node_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // ToDO: may need to integrate with scrn_inactive flow
    // ToDo: should consider tab screen case, redraw tab has not been implemented
    if (IsBitSet(node->attrib, NODE_ATTRIB_REDRAW_ENTER_IDX))
    {   
        scrn_inactive_internal_process(node,MMI_SCENARIO_STATE_BACKWARD_IDX);
    }
    return MMI_RET_OK;
}

static mmi_ret group_redraw_start_first_time(base_node_struct *node_ptr, void * arg)
{
    mmi_ret ret = MMI_RET_OK;
    traverse_redraw_ctxt_struct* redraw_ctxt_ptr = (traverse_redraw_ctxt_struct*) arg;
    
    MMI_ASSERT(_IS_GROUP(node_ptr));

    if (IsBitSet(node_ptr->attrib, NODE_ATTRIB_GRP_REDRAW_START_IDX))
    {
        ret = group_redraw_start(node_ptr, arg);
        if (ret == MMI_RET_TRAVERSE_GROUP_SKIP)
            redraw_ctxt_ptr->skip_group_ptr = _GROUP(node_ptr);
    }
    return ret;
}

static mmi_ret group_redraw_all_parent_start(scrn_node_struct *scrn_ptr, traverse_redraw_ctxt_struct* redraw_ctxt_ptr)
{
    group_node_struct *group_ptr;
    group_node_struct *adaptor_node_ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (_IS_TAB_PAGE(scrn_ptr))
        scrn_ptr = _SCRN(scrn_ptr->parent);

    /* Mark all parent group to send redraw start message */
    for (group_ptr = scrn_ptr->parent; 
            group_ptr && group_ptr != &shell.scenario_root; 
            group_ptr = group_ptr->parent)
    {
        SetBit(group_ptr->attrib, NODE_ATTRIB_GRP_REDRAW_START_IDX);
        adaptor_node_ptr = group_ptr;
    }
#ifdef __MMI_FRM_HISTORY__
    scrn_group_adaptor_entry((group_node_struct *) adaptor_node_ptr);
#endif
    traverse_scenario_tree((base_node_struct *) adaptor_node_ptr, NULL, group_redraw_start_first_time, NULL, (void *) redraw_ctxt_ptr);

    /* Clean up the marker for sending redraw start message */
    for (group_ptr = scrn_ptr->parent; 
            group_ptr && group_ptr != &shell.scenario_root; 
            group_ptr = group_ptr->parent)
    {
        ResetBit(group_ptr->attrib, NODE_ATTRIB_GRP_REDRAW_START_IDX);
    }
    return MMI_RET_OK;
}

static mmi_ret scrn_redraw(base_node_struct *node_ptr, void * arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    traverse_redraw_ctxt_struct* redraw_ctxt_ptr = (traverse_redraw_ctxt_struct*) arg;
    scrn_node_struct*   scrn_ptr = _SCRN(node_ptr);;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scrn_ptr->id == redraw_ctxt_ptr->topmost_full_scrn_id)
    {
        redraw_ctxt_ptr->start_draw = MMI_TRUE;
        
        /* simulate the condition that the group been activated 
           send group start message to all parent before redraw first screen */
        group_redraw_all_parent_start(scrn_ptr, redraw_ctxt_ptr);
    }

    /* Maintain status of variable shell.active_tab (mmi_frm_scrn_enter will reference the variable) */
    if (_IS_TAB(node_ptr))
    {
        scrn_ptr = _SCRN(_TAB_PAGE(_TAB(node_ptr)->m_tail));
        shell.active_tab = _TAB(node_ptr);
    }
    else
    {
        shell.active_tab = NULL;
    }

    /* reach the orignal active screen, stop redraw */
    if (scrn_ptr == redraw_ctxt_ptr->backup_group_shell.active_scrn)
    {
        group_node_struct *parent_group_ptr = NULL;        
        /* send redraw end message to all parent group */
        for (parent_group_ptr = scrn_ptr->parent; 
                parent_group_ptr && parent_group_ptr != &shell.scenario_root; 
                parent_group_ptr = parent_group_ptr->parent)
        {
            group_redraw_end((base_node_struct*)parent_group_ptr,arg);
        }
        redraw_ctxt_ptr->start_draw = MMI_FALSE;        
    }

    /* Note: redraw_ctxt_ptr->skip_group_ptr!=NULL means one of the parent group of current 
             screen return MMI_RET_TRAVERSE_GROUP_SKIP during group_redraw_start, so 
             the current gourp should be skip.
    */
    if ((redraw_ctxt_ptr->start_draw == MMI_FALSE) || _IS_TAB_PAGE(node_ptr) || redraw_ctxt_ptr->skip_group_ptr)
    {
        return MMI_RET_OK;
    }

    /* Clean previous UI screen, if any */
    if (shell.active_scrn != NULL)
    {
        scrn_redraw_clean(shell.active_scrn);
    }
#ifdef __MMI_FRM_HISTORY__
    mmi_frm_reset_redraw_empty_bg();
#endif
    if (shell.active_scrn != scrn_ptr)
    {    
        shell.active_scrn = scrn_ptr;
        ResetBit(node_ptr->attrib, NODE_ATTRIB_REDRAW_ENTER_IDX);

        node_exec_entry_proc(scrn_ptr);
    #ifdef __MMI_FRM_HISTORY__
        if (mmi_frm_is_redraw_empty_bg())
        {
            mmi_frm_redraw_fill_empty_bg();
            ShowCategoryDummyScreen();
        }
    #endif
    }
    return MMI_RET_OK;
}


static mmi_ret group_redraw_start(base_node_struct *node_ptr, void * arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    traverse_redraw_ctxt_struct* redraw_ctxt_ptr = (traverse_redraw_ctxt_struct*) arg;
    group_node_struct *group_ptr = _GROUP(node_ptr);
    mmi_scenario_evt_struct         evt = {EVT_ID_GROUP_REDRAW_START, 0, NULL};
    mmi_ret                         ret = MMI_RET_TRAVERSE_GROUP_OK;
    mmi_ret                         group_proc_ret;
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_FRM_SCENARIO_REDRAW_GROUP_START, node_ptr);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_ASSERT(group_ptr&&_IS_GROUP(group_ptr));
    
    /* Note: redraw_ctxt_ptr->skip_group_ptr!=NULL means one of the parents of current 
             group return MMI_RET_TRAVERSE_GROUP_SKIP during group_redraw_start, so 
             the current gourp should be skip.
    */
    if (redraw_ctxt_ptr->start_draw == MMI_FALSE || redraw_ctxt_ptr->skip_group_ptr)
    {
        return ret;
    }
    /* To keep the exit screen allways be invoked before group done
       to keep the relationship of group_start, scrn_enter, scrn_exit,...group_done symmetrical
    */
    if (shell.active_scrn != NULL)
    {
        scrn_redraw_clean(shell.active_scrn);
        shell.active_scrn = NULL;
    }
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_REDRAW_GROUP_EVENT, (U16)group_ptr->id, group_ptr, EVT_ID_GROUP_REDRAW_START);
    evt.targ_group = group_ptr->id;
    evt.targ_scrn = NULL;
    group_proc_ret = MMI_FRM_SEND_EVENT(&evt, group_ptr->proc, group_ptr->user_data);
    if (group_proc_ret == MMI_RET_REDRAW_EMPTY_BG)
    {
        mmi_frm_redraw_fill_empty_bg();
        redraw_ctxt_ptr->skip_group_ptr = group_ptr;
        ret = MMI_RET_TRAVERSE_GROUP_SKIP;
    } 
    return ret;
}

static mmi_ret group_redraw_end(base_node_struct *node_ptr, void * arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    traverse_redraw_ctxt_struct* redraw_ctxt_ptr = (traverse_redraw_ctxt_struct*) arg;
    group_node_struct *group_ptr = _GROUP(node_ptr);
    mmi_scenario_evt_struct         evt = {EVT_ID_GROUP_REDRAW_DONE, 0, NULL};
    mmi_ret                         ret = MMI_RET_TRAVERSE_GROUP_OK;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_FRM_SCENARIO_REDRAW_GROUP_END, node_ptr);

    MMI_ASSERT(group_ptr&&_IS_GROUP(group_ptr));
    
    /* To keep the exit screen allways be invoked before group done
       to keep the relationship of group_start, scrn_enter, scrn_exit,...group_done symmetrical
    */
    if (shell.active_scrn != NULL)
    {
        scrn_redraw_clean(shell.active_scrn);
        shell.active_scrn = NULL;
    }

    evt.targ_group = group_ptr->id;
    evt.targ_scrn = NULL;
    
    if ((redraw_ctxt_ptr->start_draw == MMI_TRUE)&&(redraw_ctxt_ptr->skip_group_ptr == NULL))
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_REDRAW_GROUP_EVENT, (U16)group_ptr->id, group_ptr, EVT_ID_GROUP_REDRAW_DONE);
        ret = MMI_FRM_SEND_EVENT(&evt, group_ptr->proc, group_ptr->user_data);
    }

    /* End the process of skip group */
    if (_GROUP(node_ptr) == redraw_ctxt_ptr->skip_group_ptr)
    {
        redraw_ctxt_ptr->skip_group_ptr = NULL;
    }
    return ret;
}
   
void group_redraw_by_id(U32 scrn_id, traverse_redraw_ctxt_struct* redraw_ctxt_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    base_node_struct* start_node_ptr = SG_GET_NODE_FROM_ROOT(scrn_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    traverse_scenario_tree(start_node_ptr, scrn_redraw, group_redraw_start,  group_redraw_end, redraw_ctxt_ptr);
}


MMI_BOOL mmi_frm_scenario_is_redrawing(void)
{
#ifdef __MMI_FRM_HISTORY__
    return (mmi_is_redrawing_bk_screens() == 1) ? MMI_TRUE : MMI_FALSE;    
#else
    return IsBitSet(shell.state, MMI_SCENARIO_STATE_REDRAW_IDX) ? MMI_TRUE : MMI_FALSE;
#endif /* __MMI_FRM_HISTORY__ */
}
#ifndef __MMI_FRM_HISTORY__
static mmi_ret scrn_check_small_ex(base_node_struct *node_ptr, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    scrn_node_struct*           scrn_ptr = _SCRN(node_ptr);
    traverse_find_ctxt_struct_ex*  find_ctxt_ptr = (traverse_find_ctxt_struct_ex*) arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (_IS_TAB_PAGE(scrn_ptr))
    {
        return MMI_RET_ERR;
    }

    if (_IS_TAB(scrn_ptr))
    {
        scrn_ptr = _SCRN(_TAB_PAGE(_TAB(node_ptr)->m_tail));
    }

    if (IsBitReset(scrn_ptr->attrib, NODE_ATTRIB_SMALL_SCREEN_IDX))
    {
        find_ctxt_ptr->topmost_full_scrn_id = _SCRN(node_ptr)->id;        
    }
    return MMI_RET_OK;
}

static void mmi_frm_redraw_bg_ex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    traverse_find_ctxt_struct_ex       find_ctxt;
    traverse_redraw_ctxt_struct     redraw_ctxt;
    base_node_struct* pCurrNode = NULL;
    U32 topmost_full_scrn_id = 0;
    MMI_ID group_id = GRP_ID_INVALID;
    MMI_ID scrn_id  = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scenario_is_redrawing() || !isEnableSmallScrnRedraw_sg)
        return;
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_REDRAW_BEG, (MMI_ID)g_scrn_mgr_cntx.active_group_id, (MMI_ID)g_scrn_mgr_cntx.active_scrn_id, shell.scenario_root.m_count,shell.scenario_bg.m_count);
        
    SetBit(shell.state, MMI_SCENARIO_STATE_REDRAW_IDX);
    find_ctxt.topmost_full_scrn_id = MMI_SCR_ID_INAVLID;
    find_ctxt.level_one_node = 0;

    /* backup orignal group status */
    mmi_frm_get_active_scrn_id(&group_id, &scrn_id);
    group_status_backup(&redraw_ctxt.backup_group_shell);    
    gdi_lcd_freeze(TRUE);
    /* force small screen flatten always on */
    dm_force_small_screen_flatten();
    
    pCurrNode = shell.scenario_root.m_head;
    /*  Step1: Traverse scenario tree to find topmost full screen. */
    while (pCurrNode != NULL)
    {
        topmost_full_scrn_id = find_ctxt.topmost_full_scrn_id;
        traverse_scenario_tree(pCurrNode, scrn_check_small_ex, NULL, NULL, &find_ctxt);
        if (topmost_full_scrn_id != find_ctxt.topmost_full_scrn_id)
            find_ctxt.level_one_node = (U32)pCurrNode;
        pCurrNode = pCurrNode->m_next;
    }
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_REDRAWING, (MMI_ID)find_ctxt.topmost_full_scrn_id, find_ctxt.level_one_node, REDRAWING_STAGE1);

    /* Step2: Redraw background screen, may include small screen */
    redraw_ctxt.topmost_full_scrn_id = find_ctxt.topmost_full_scrn_id;
    redraw_ctxt.start_draw = MMI_FALSE;
    redraw_ctxt.skip_group_ptr = NULL;

    pCurrNode = (base_node_struct*)find_ctxt.level_one_node;
    while (pCurrNode != NULL)
    {
        traverse_scenario_tree(pCurrNode, scrn_redraw, group_redraw_start,  group_redraw_end, &redraw_ctxt);
        pCurrNode = pCurrNode->m_next;
    }

    /* unforce small screen flatten always on */
    dm_unforce_small_screen_flatten();

    gui_sse_set_is_dummy_screen(MMI_FALSE);
    group_status_restore(&redraw_ctxt.backup_group_shell);
    set_active_scrn_id(group_id, scrn_id);
    //set_active_history_node_id(backup_active_scr_id);

    gdi_lcd_freeze(FALSE);
    //mmi_set_redrawing_bk_screens_status(MMI_HIST_SMALLSCREEN_ACTIVE_IN_EXIT_FUNC);
    ResetBit(shell.state, MMI_SCENARIO_STATE_REDRAW_IDX); 
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_REDRAW_END, (MMI_ID)g_scrn_mgr_cntx.active_group_id, (MMI_ID)g_scrn_mgr_cntx.active_scrn_id, shell.scenario_root.m_count,shell.scenario_bg.m_count);
}
#endif 


/*****************************************************************************
 * Screen Manager: screen/history + screen group
 *****************************************************************************/
void set_active_scrn_id(MMI_ID group_id, MMI_ID scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_scrn_mgr_cntx.active_group_id = group_id;
    g_scrn_mgr_cntx.active_scrn_id  = scrn_id;
}

void set_exit_scrn_id(MMI_ID group_id, MMI_ID scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    g_scrn_mgr_cntx.exit_group_id = group_id;
    g_scrn_mgr_cntx.exit_scrn_id  = scrn_id;

}


void mmi_frm_get_active_scrn_id(MMI_ID *group_id, MMI_ID *scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (group_id == NULL || scrn_id == NULL)
    {
        MMI_ASSERT(0);
    }
    *group_id = g_scrn_mgr_cntx.active_group_id;
    *scrn_id  = g_scrn_mgr_cntx.active_scrn_id;
}

void mmi_frm_get_exit_scrn_id(MMI_ID *group_id, MMI_ID *scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (group_id == NULL || scrn_id == NULL)
    {
        MMI_ASSERT(0);
    }
    *group_id = g_scrn_mgr_cntx.exit_group_id;
    *scrn_id  = g_scrn_mgr_cntx.exit_scrn_id;

}

/***************************************************************************** 
*  Trace
*****************************************************************************/

#ifndef __MTK_TARGET__
static void frm_dump_space(U32 level)
{
    U32 i;
    for(i=0;i<level;i++)
        kal_printf("  ");
}

void mmi_frm_dump_node_on_modis(void* in, U32 level)
{
    base_node_struct* pNode = (base_node_struct*)in;
    while(pNode && pNode->type != 0xcc)
    {
        frm_dump_space(level);
        switch(pNode->type)
        {
            case SCENARIO_GROUP_NODE:
            {
                kal_printf("id = [0x%04x] (G: [0x%08x]): [%d]\n", (U16)(_GROUP(pNode)->id), pNode, _GROUP(pNode)->m_count);
                mmi_frm_dump_node_on_modis((void*)(_GROUP(pNode)->m_head), level+1);
            }
            break;
            case SCENARIO_TAB_NODE:
            {
                kal_printf("id = [0x%04x] (T: [0x%08x]): [%d]\n", (U16)(_TAB(pNode)->id), pNode, _TAB(pNode)->m_count);
                mmi_frm_dump_node_on_modis((void*)(_TAB(pNode)->m_head), level+1);            
            }
            break;
            case SCENARIO_SCRN_NODE:
            {
                kal_printf("id = [0x%04x] (S: [0x%08x])\n", (U16)(_SCRN(pNode)->id), pNode);
            }
            break;
            case SCENARIO_TAB_PAGE_NODE:
            {
                kal_printf("id = [0x%04x] (TP: [0x%08x])\n", (U16)(_TAB_PAGE(pNode)->id), pNode);
            }
            break;
        }
        if (level > 0)
        {
            pNode = (base_node_struct*)(pNode->m_next);
        }
        else
        {
            pNode = NULL;
        }
    }
}


void mmi_frm_dbg_dump_shell(void)
{
    kal_printf("[app tree]\n");
    mmi_frm_dump_node_on_modis((void*)(&shell.scenario_root), 0);
    kal_printf("[background tree]\n");
    mmi_frm_dump_node_on_modis((void*)(&shell.scenario_bg), 0);
}

#endif /* #ifndef __MTK_TARGET__*/

void mmi_frm_dump_one_tree(group_node_struct* node_ret)
{
    for(; node_ret; node_ret = _GROUP(node_ret->m_prev))
    {
        mmi_frm_dump_node(node_ret, 0);
    }
}

void mmi_frm_dump_tree(U8 tree_type)
{
    group_node_struct* node_ret = NULL;
    
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_TREE_STATE, \
        (MMI_ID)g_scrn_mgr_cntx.active_group_id, \
        (MMI_ID)g_scrn_mgr_cntx.active_scrn_id, \
        shell.state, \
        shell.scenario_root.m_count);
    
    if(tree_type & 0x01)    // ROOT
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_TREE_ROOT);
        mmi_frm_dump_one_tree(_GROUP(shell.scenario_root.m_tail));
    }
    else if(node_ret == NULL && (tree_type & 0x04))    // bg
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_TREE_BG);  
        mmi_frm_dump_one_tree(_GROUP(shell.scenario_bg.m_tail));
    }
    else if(node_ret == NULL && (tree_type & 0x02))    // dangle
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_TREE_DANGLE);
        mmi_frm_dump_one_tree(_GROUP(shell.scenario_dangle.m_tail));
    }
}


void mmi_frm_dump_node(void* in, U32 level)
{
    base_node_struct* pNode = (base_node_struct*)in;
    while(pNode && pNode->type != 0xcc)
    {
        if (level == 0)
        {
            if (pNode->type == SCENARIO_GROUP_NODE)
            {
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_NODE_L0,
                        level,
                       _GROUP(pNode)->id, _GROUP(pNode)->proc, _GROUP(pNode)->user_data, _GROUP(pNode)->m_count,
                       _GROUP(pNode)->asm_data.usage,
                       mmi_res_get_app_base_mem_size(_GROUP(pNode)->id),
                       mmi_res_get_app_fg_mem_size(_GROUP(pNode)->id),
                       mmi_res_get_app_heap_size(_GROUP(pNode)->id));
                mmi_frm_dump_node((void*)(_GROUP(pNode)->m_head), level + 1);
            }
        }
        else if (level == 1)
        {
            switch(pNode->type)
            {
            case SCENARIO_GROUP_NODE:
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_NODE_L1,
                       level,
                       (U16)(_GROUP(pNode)->id), _GROUP(pNode)->proc, _GROUP(pNode)->user_data, _GROUP(pNode)->m_count);
                mmi_frm_dump_node((void*)(_GROUP(pNode)->m_head), level+1);
                break;
        #ifndef __MMI_NOT_TAB_SUPPORT__
            case SCENARIO_TAB_NODE:
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_TAB_NODE_L1,
                        level,
                        (U16)(_TAB(pNode)->id), _TAB(pNode)->exit_proc, _TAB(pNode)->entry_proc, _TAB(pNode)->user_data, _TAB(pNode)->page_count, _TAB(pNode)->first_item_index);
                
                mmi_frm_dump_node((void*)(_TAB(pNode)->m_head), level+1);
                break;
            case SCENARIO_TAB_PAGE_NODE:
        #endif /* __MMI_NOT_TAB_SUPPORT__ */
            case SCENARIO_SCRN_NODE:            
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_NODE_L1,
                        level,
                        (U16)(_SCRN(pNode)->id), _SCRN(pNode)->exit_proc, _SCRN(pNode)->entry_proc, _SCRN(pNode)->user_data, _SCRN(pNode)->proc);
                break;
            default:
                break;
            }
        }
        else if (level == 2)
        {
            switch(pNode->type)
            {
            case SCENARIO_GROUP_NODE:
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_NODE_L2,
                       level,
                       (U16)(_GROUP(pNode)->id), _GROUP(pNode)->proc, _GROUP(pNode)->user_data, _GROUP(pNode)->m_count);
                mmi_frm_dump_node((void*)(_GROUP(pNode)->m_head), level+1);
                break;
        #ifndef __MMI_NOT_TAB_SUPPORT__
            case SCENARIO_TAB_NODE:
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_TAB_NODE_L2,
                        level,
                        (U16)(_TAB(pNode)->id), _TAB(pNode)->exit_proc, _TAB(pNode)->entry_proc, _TAB(pNode)->user_data, _TAB(pNode)->page_count, _TAB(pNode)->first_item_index);
                
                mmi_frm_dump_node((void*)(_TAB(pNode)->m_head), level+1);
                break;
            case SCENARIO_TAB_PAGE_NODE:
        #endif /* __MMI_NOT_TAB_SUPPORT__ */
            case SCENARIO_SCRN_NODE:           
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_NODE_L2,
                        level,
                        (U16)(_SCRN(pNode)->id), _SCRN(pNode)->exit_proc, _SCRN(pNode)->entry_proc, _SCRN(pNode)->user_data, _SCRN(pNode)->proc);
                break;
            default:
                break;
            }
        }
        else if (level == 3)
        {
            switch(pNode->type)
            {
            case SCENARIO_GROUP_NODE:
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_NODE_L3,
                       level,
                       (U16)(_GROUP(pNode)->id), _GROUP(pNode)->proc, _GROUP(pNode)->user_data, _GROUP(pNode)->m_count);
                mmi_frm_dump_node((void*)(_GROUP(pNode)->m_head), level+1);
                break;
        #ifndef __MMI_NOT_TAB_SUPPORT__
            case SCENARIO_TAB_NODE:
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_TAB_NODE_L3,
                        level,
                        (U16)(_TAB(pNode)->id), _TAB(pNode)->exit_proc, _TAB(pNode)->entry_proc, _TAB(pNode)->user_data, _TAB(pNode)->page_count, _TAB(pNode)->first_item_index);
                
                mmi_frm_dump_node((void*)(_TAB(pNode)->m_head), level+1);
                break;
            case SCENARIO_TAB_PAGE_NODE:
        #endif /* __MMI_NOT_TAB_SUPPORT__ */
            case SCENARIO_SCRN_NODE:           
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_NODE_L3,
                        level,
                        (U16)_SCRN(pNode)->id, _SCRN(pNode)->exit_proc, _SCRN(pNode)->entry_proc, _SCRN(pNode)->user_data, _SCRN(pNode)->proc);
                break;
            default:
                break;
            }
        }
        else if (level == 4)
        {
            switch(pNode->type)
            {
            case SCENARIO_GROUP_NODE:
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_NODE_L4,
                       level,
                       (U16)(_GROUP(pNode)->id), _GROUP(pNode)->proc, _GROUP(pNode)->user_data, _GROUP(pNode)->m_count);
                mmi_frm_dump_node((void*)(_GROUP(pNode)->m_head), level+1);
                break;
        #ifndef __MMI_NOT_TAB_SUPPORT__
            case SCENARIO_TAB_NODE:
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_TAB_NODE_L4,
                        level,
                        (U16)(_TAB(pNode)->id), _TAB(pNode)->exit_proc, _TAB(pNode)->entry_proc, _TAB(pNode)->user_data, _TAB(pNode)->page_count, _TAB(pNode)->first_item_index);
                
                mmi_frm_dump_node((void*)(_TAB(pNode)->m_head), level+1);
                break;
            case SCENARIO_TAB_PAGE_NODE:
        #endif /* __MMI_NOT_TAB_SUPPORT__ */
            case SCENARIO_SCRN_NODE:           
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_NODE_L4,
                        level,
                        (U16)_SCRN(pNode)->id, _SCRN(pNode)->exit_proc, _SCRN(pNode)->entry_proc, _SCRN(pNode)->user_data, _SCRN(pNode)->proc);
                break;
            default:
                break;
            }
        }
        else if (level == 5)
        {
            switch(pNode->type)
            {
            case SCENARIO_GROUP_NODE:
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_NODE_L5,
                       level,
                       (U16)(_GROUP(pNode)->id), _GROUP(pNode)->proc, _GROUP(pNode)->user_data, _GROUP(pNode)->m_count);
                mmi_frm_dump_node((void*)(_GROUP(pNode)->m_head), level+1);
                break;
        #ifndef __MMI_NOT_TAB_SUPPORT__ 
            case SCENARIO_TAB_NODE:
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_TAB_NODE_L5,
                        level,
                        (U16)(_TAB(pNode)->id), _TAB(pNode)->exit_proc, _TAB(pNode)->entry_proc, _TAB(pNode)->user_data, _TAB(pNode)->page_count, _TAB(pNode)->first_item_index);
                
                mmi_frm_dump_node((void*)(_TAB(pNode)->m_head), level+1);
                break;
            case SCENARIO_TAB_PAGE_NODE:
        #endif /* __MMI_NOT_TAB_SUPPORT__ */
            case SCENARIO_SCRN_NODE:            
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_NODE_L5,
                        level,
                        (U16)(_SCRN(pNode)->id), _SCRN(pNode)->exit_proc, _SCRN(pNode)->entry_proc, _SCRN(pNode)->user_data, _SCRN(pNode)->proc);
                break;
            default:
                break;
            }
        }
        else
        {
            switch(pNode->type)
            {
            case SCENARIO_GROUP_NODE:
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_GROUP_NODE_Lx,
                       level, (U16)(_GROUP(pNode)->id), _GROUP(pNode)->proc, _GROUP(pNode)->user_data, _GROUP(pNode)->m_count);
                mmi_frm_dump_node((void*)(_GROUP(pNode)->m_head), level+1);
                break;
        #ifndef __MMI_NOT_TAB_SUPPORT__
            case SCENARIO_TAB_NODE:
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_TAB_NODE_Lx,
                       level, (U16)(_TAB(pNode)->id), _TAB(pNode)->exit_proc, _TAB(pNode)->entry_proc, _TAB(pNode)->user_data, _TAB(pNode)->page_count, _TAB(pNode)->first_item_index);
                mmi_frm_dump_node((void*)(_TAB(pNode)->m_head), level+1);
                break;
            case SCENARIO_TAB_PAGE_NODE:
        #endif /* __MMI_NOT_TAB_SUPPORT__ */
            case SCENARIO_SCRN_NODE:            
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_SCENARIO_SCRN_NODE_Lx,
                        level, (U16)(_SCRN(pNode)->id), _SCRN(pNode)->exit_proc, _SCRN(pNode)->entry_proc, _SCRN(pNode)->user_data, _SCRN(pNode)->proc);
                break;
            default:
                break;
            }
        }
        if (level > 0)
        {
            pNode = (base_node_struct*)pNode->m_next;
        }
        else
        {
            pNode = NULL;
        }
    }
}


MMI_ID cosmos_home_launch(MMI_ID app_id, MMI_ID base_id)
{
	mmi_frm_node_struct group_info;
	mmi_frm_group_create(GRP_ID_ROOT, app_id, NULL, NULL);
	group_info.id = app_id;
	group_info.entry_proc = NULL;
	group_info.user_data = NULL;
	mmi_frm_group_insert(
		GRP_ID_ROOT,
		base_id,
		&group_info,
		MMI_FRM_NODE_AFTER_FLAG);
	mmi_frm_scrn_create(app_id, 0x1000, NULL, NULL);
	return app_id;
}

/***************************************************************************** 
*  Service Object
*****************************************************************************/
//#define __MMI_FRM_SCENARIO_UT__
#ifdef  __MMI_FRM_SCENARIO_UT__
#define ARRAY_COUNT(a)               (sizeof(a)/sizeof(a[0]))


/***************************************************************************** 
*  Test Case
*****************************************************************************/
#include "Custom_events_notify.h"
#include "SettingProfileEnum.h"
#include "CommonScreens.h"
#include "mmi_frm_timer_gprot.h"
#include "CommonScreensResDef.h"
#include "TimerEvents.h"

/******************************************************************************
 * Test Framework
 ******************************************************************************/

/* unit test function */
typedef mmi_ret (*unit_test_func)(void *para);

/* unit test struct */
typedef struct
{
    U8 index;
    unit_test_func test;
} mmi_unit_test_struct;


#ifdef __MMI_FRM_HISTORY__

static void __trace(base_node_struct* node, mmi_scenario_evt_struct* evt, int flag);
/* API for internal trace */
#define INTERNAL_TRACE(n,e)                 __trace(_NODE(n), (mmi_scenario_evt_struct*)e, 0)
#define APP_VIEWPOINT_TRACE(n,e)            __trace(_NODE(n), (mmi_scenario_evt_struct*)e, 1)

/*
extern void DisplayPopupRotated_ScreenGroup(MMI_ID parentId, U8 *string, U16 imageId, U8 imageOnBottom, U32 popupDuration, U8 toneId,
                         mmi_frm_screen_rotate_enum rotation);
*/

typedef struct _test_group_context
{
    MMI_ID  id;
    MMI_ID  id2;
    MMI_ID  id3;
    MMI_ID  id4;
    MMI_ID  id5;
    MMI_ID  id6;
    MMI_ID  id7;
    MMI_ID  id8;
    MMI_ID  id9;
    MMI_ID  id10;
}test_group_context;

test_group_context test_group_ctx = {0};

group_node_struct *g_group_tmp = NULL;
scrn_node_struct *g_scrn_tmp = NULL;
tab_node_struct *g_tab_tmp = NULL;
tab_page_node_struct *g_page_tmp = NULL;

static int _test_case_display_popup = 0;
static S32 test_case_idx = 0;
static U32 g_mem_dbg_test_record[100];

typedef struct _test_case_check_struct
{   
    group_node_struct       *group;
    scrn_node_struct        *scrn;
    tab_node_struct         *tab;
}test_case_check_struct;

test_case_check_struct test_case_check_ctxt;

void __trace(base_node_struct* node, mmi_scenario_evt_struct* evt, int flag)
{
#ifndef __MTK_TARGET__
    static int __trace_cfg = 0x26;
    U32 evt_id = evt->evt_id - (FRAMEWORK_BASE + 1);
    U8 evt_id_name[12][20] = {"SCENAIO_CHANGE", "GROUP_FIRST_ENTRY", "GROUP_ACTIVE", "GROUP_INACTIVE", "GROUP_GOBACK", "GROUP_DEL_REQ", "GROUP_DEINIT", "SCRN_ACTIVE", "SCRN_INACTIVE", "SCRN_GOBACK", "SCRN_DEL_REQ", "SCRN_DEINIT"};
    U8 type_name[4][10] = {"NODE", "GROUP", "SCREEN", "TAB-PAGE"};

    return;

    if (IsBitReset(__trace_cfg, 4) && flag == 0)
    {
        return;
    }
    if (IsBitReset(__trace_cfg, 5) && flag == 1)
    {
        return;
    }
    else
    {
        kal_printf(" APP_VIEWPOINT:  \n");
    }

    if (IsBitSet(__trace_cfg, 0))
    {
        /* print shell info */
        kal_printf("Shell State: 0x%x, active(g,s)=(%d, %d)\n", shell.state, (shell.active_group)?(shell.active_group->id):-1, (shell.active_scrn)?(shell.active_scrn->id):-1);
    }


    if (IsBitSet(__trace_cfg, 1) && evt)
    {
        /* print evt info */
        kal_printf("\tEVT_ID: [%s], state:0x%x, userdate:0x%u, (g,s)[targ-curr-new]=(%d,%d)-(%d, %d)-(%d, %d) \n", evt_id_name[evt_id], evt->state, evt->user_data, evt->targ_group, evt->targ_scrn, evt->curr_group, evt->curr_scrn, evt->new_group, evt->new_scrn);
    }

    if (IsBitSet(__trace_cfg, 2) && node)
    {
        /* print node info. */
        kal_printf("\tNode:<%s>, node_id:%d, node_sate:0x%x \n\n", type_name[node->type], node->id, node->state);
    }
#endif /* #ifndef __MTK_TARGET__ */
}


void test_case_check_init(void)
{
    test_case_check_ctxt.group = shell.active_group;
    test_case_check_ctxt.scrn = shell.active_scrn;
    test_case_check_ctxt.tab = shell.active_tab;
}


void check_memory_leak(void)
{
    int i;
    for (i=0; i < 100; i++)
    {
        if (g_mem_dbg_test_record[i] != g_mem_dbg_record[i])
        {
            /* memory leak */
            kal_printf("ERROR!! TEST_CASE_%d : MEMORY LEAK!!\n\n", test_case_idx-1);
            MMI_ASSERT(0);
        }
    }    
}

void test_case_check_pass(void)
{

    /* check there is no scenario tree */
    MMI_ASSERT(shell.active_group == test_case_check_ctxt.group);
    MMI_ASSERT(shell.active_scrn == test_case_check_ctxt.scrn);
    MMI_ASSERT(shell.active_tab == test_case_check_ctxt.tab);
    /* check memory leak */
    check_memory_leak();
}

void test_case0_timeout(void)
{
    mmi_frm_group_close(test_group_ctx.id);

    /* check test case result */
    test_case_check_pass();
}

mmi_ret test_group_proc(mmi_event_struct* evt)
{
    APP_VIEWPOINT_TRACE(NULL, evt);
    switch(evt->evt_id)
    {
    case EVT_ID_GROUP_ENTER:
        break;
    case EVT_ID_GROUP_DEINIT:
        break;
    }
    return MMI_RET_OK;
}


void screen_group_test_case0(void)
{
    static test_case0_cfg = 0;

    if (test_case0_cfg)
    {
        test_group_ctx.id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx);
        mmi_frm_group_enter(test_group_ctx.id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }
    else
    {
        test_group_ctx.id = mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }

    StartTimer(KEY_TIMER_ID33, 100, test_case0_timeout);
}


void test1_scrn_exit(mmi_event_struct* arg)
{
}

void test1_scrn_entry(mmi_scrn_essential_struct* arg)
{
    if (mmi_frm_scrn_enter(test_group_ctx.id, 0x123, (FuncPtr)test1_scrn_exit, (FuncPtr)test1_scrn_entry, MMI_FRM_FULL_SCRN))
    {
        test_group_ctx.id += 100;
        ShowCategoryDummyScreen();
    }
}

mmi_ret test1_group_proc(mmi_event_struct* evt)
{
    APP_VIEWPOINT_TRACE(NULL, evt);
    switch(evt->evt_id)
    {
    case EVT_ID_GROUP_ENTER:
        test1_scrn_entry((mmi_scrn_essential_struct*)evt);
        break;
    case EVT_ID_GROUP_DEINIT:
        break;
    }
    return MMI_RET_OK;
}

void test_case1_timeout(void)
{
    mmi_frm_group_close((MMI_ID)(test_group_ctx.id-100));

    /* check test case result */
    test_case_check_pass();
}

void screen_group_test_case1(void)
{
    test_group_ctx.id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test1_group_proc, &test_group_ctx);
    mmi_frm_group_enter(test_group_ctx.id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    StartTimer(KEY_TIMER_ID33, 100, test_case1_timeout);
}



void test2_scrn_entry(void)
{

    if (mmi_frm_scrn_enter(test_group_ctx.id, 0x123, NULL, test2_scrn_entry, MMI_FRM_FULL_SCRN))
    {
        test_group_ctx.id += 50;
        ShowCategoryDummyScreen();
    }
}

void test_case2_timeout(void)
{
    mmi_frm_scrn_close((MMI_ID)(test_group_ctx.id-50), (MMI_ID)0x123);
    mmi_frm_group_close((MMI_ID)(test_group_ctx.id-50));

    /* check test case result */
    test_case_check_pass();
}

void screen_group_test_case2(void)
{
    test_group_ctx.id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx);
    mmi_frm_group_enter(test_group_ctx.id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test2_scrn_entry();
    StartTimer(KEY_TIMER_ID33, 100, test_case2_timeout);
}


void screen_group_test_case3(void)
{
    test_group_ctx.id = mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_group_enter(test_group_ctx.id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_group_ctx.id += 100;
    StartTimer(KEY_TIMER_ID33, 100, test_case1_timeout);
}


void test_case4_timeout(void)
{
    mmi_frm_group_close((MMI_ID)(test_group_ctx.id-50));

    /* check test case result */
    test_case_check_pass();
}

void screen_group_test_case4(void)
{
    test_group_ctx.id = mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_group_ctx.id += 50;
    StartTimer(KEY_TIMER_ID33, 100, test_case4_timeout);
}


void test_case5_timeout(void)
{
    /* symbol ^ means active node
     *                 (G-id3*) - (S3*)     (G-id4) - (S4)
     *                 (G-id2) ------------ (S2)
     *                 (S1)
     * ROOT - (G-id) - (S0)
     */

    /* close inactive group (G-id4) */
    mmi_frm_group_close(test_group_ctx.id4);

    /* close inactive screen (S0) */
    mmi_frm_scrn_close(test_group_ctx.id, 0x456);

    /* close active screen (S3) */
    mmi_frm_scrn_close(test_group_ctx.id3, 0x135);

    /* close active group (G-id) */
    mmi_frm_group_close(test_group_ctx.id);

    /* check test case result */
    test_case_check_pass();
}

void test_id_scrn_entry(void) /* (G-id) - (S0) */
{

    if (mmi_frm_scrn_enter(test_group_ctx.id, 0x456, NULL, test_id_scrn_entry, MMI_FRM_FULL_SCRN))
    {
        ShowCategoryDummyScreen();
    }
}

void test_id_scrn_entry1(void) /* (G-id) - (S1) */
{

    if (mmi_frm_scrn_enter(test_group_ctx.id, 0x579, NULL, test_id_scrn_entry1, MMI_FRM_FULL_SCRN))
    {
        ShowCategoryDummyScreen();
    }
}

void test_id2_scrn_entry2(void) /* (G-id) - (G-id2) - (S2) */
{

    if (mmi_frm_scrn_enter(test_group_ctx.id2, 0x789, NULL, test_id2_scrn_entry2, MMI_FRM_FULL_SCRN))
    {
        ShowCategoryDummyScreen();
    }
}

void test_id3_scrn_entry3(void) /* (G-id) - (G-id3) - (S3) */
{

    if (mmi_frm_scrn_enter(test_group_ctx.id3, 0x135, NULL, test_id3_scrn_entry3, MMI_FRM_FULL_SCRN))
    {
        ShowCategoryDummyScreen();
    }
}

void test_id4_scrn_entry4(void) /* (G-id) - (G-id2) - (G-id4) - (S4) */
{

    if (mmi_frm_scrn_enter(test_group_ctx.id4, 0x246, NULL, test_id4_scrn_entry4, MMI_FRM_FULL_SCRN))
    {
        ShowCategoryDummyScreen();
    }
}

void establish_scenario_tree(void)
{
    /* symbol ^ means active node
     *                  (S1^)
     * ROOT - (G-id^) - (S0)
     */
    test_group_ctx.id = mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_id_scrn_entry();
    test_id_scrn_entry1();

    /* symbol ^ means active node
     *                 (G-id2*) - (S2*)
     *                 (S1)
     * ROOT - (G-id) - (S0)
     */
    test_group_ctx.id2 = mmi_frm_group_create(test_group_ctx.id, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx);
    mmi_frm_group_enter(test_group_ctx.id2, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_id2_scrn_entry2();

    /* symbol ^ means active node
     *                 (G-id3*) - (S3*)
     *                 (G-id2) ------------ (S2)
     *                 (S1)
     * ROOT - (G-id) - (S0)
     */
    test_group_ctx.id3 = mmi_frm_group_create(test_group_ctx.id, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx);
    mmi_frm_group_enter(test_group_ctx.id3, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_id3_scrn_entry3();

    /* symbol ^ means active node
     *                 (G-id3*) - (S3*)     (G-id4) - (S4)
     *                 (G-id2) ------------ (S2)
     *                 (S1)
     * ROOT - (G-id) - (S0)
     */
    test_group_ctx.id4 = mmi_frm_group_enter_ex(test_group_ctx.id2, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_id4_scrn_entry4();

}

void screen_group_test_case5(void)
{
    establish_scenario_tree();

    StartTimer(KEY_TIMER_ID33, 100, test_case5_timeout);
}


void screen_group_test_case6(void)
{
    test_group_ctx.id = mmi_frm_group_create(test_group_ctx.id, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx);
    mmi_frm_group_close((MMI_ID)(test_group_ctx.id+1000));
    mmi_frm_group_close(test_group_ctx.id);

    /* check test case result */
    test_case_check_pass();

}


void test_case7_timeout(void)
{
    mmi_frm_group_close(test_group_ctx.id2);
    mmi_frm_group_close(test_group_ctx.id);

    /* check test case result */
    test_case_check_pass();
}

void screen_group_test_case7(void)
{
    test_group_ctx.id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx);
    mmi_frm_group_enter(test_group_ctx.id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    test_group_ctx.id2 = mmi_frm_group_enter_ex(test_group_ctx.id, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_id2_scrn_entry2();

    StartTimer(KEY_TIMER_ID33, 100, test_case7_timeout);
}


void test_case8_timeout(void *arg)
{
    if ((U32)arg == 1)
    {
        mmi_frm_group_close(test_group_ctx.id2);
        StartTimerEx(KEY_TIMER_ID33, 100, test_case8_timeout, (void*)2);
    }
    else
    {
        mmi_frm_group_close(test_group_ctx.id);

        /* check test case result */
        test_case_check_pass();
    }
}

void test_id_scrn_entry5(void) /* (G-id) - (S5) */
{
    if (mmi_frm_scrn_enter(test_group_ctx.id, 0x555, NULL, test_id_scrn_entry5, MMI_FRM_FULL_SCRN))
    {
        ShowCategoryDummyScreen();
    }
}

void test_id_scrn_entry6(void) /* (G-id) - (S6) */
{
    if (mmi_frm_scrn_enter(test_group_ctx.id, 0x666, NULL, test_id_scrn_entry6, MMI_FRM_FULL_SCRN))
    {
        ShowCategoryDummyScreen();
    }
}

void test_id_scrn_entry8_8(void) /* (G-id8) - (S8) */
{
    if (mmi_frm_scrn_enter(test_group_ctx.id8, 0x888, NULL, test_id_scrn_entry8_8, MMI_FRM_FULL_SCRN))
    {
        ShowCategoryDummyScreen();
    }
}

mmi_ret test_id_scrn_leave(mmi_event_struct *param)
{
    return MMI_RET_OK;
}

void screen_group_test_case8(void)
{
    mmi_frm_node_struct new_node = {0};
    void *tmp;
    mmi_group_node_struct group_info;
    mmi_scrn_node_struct scrn_info;

    /* establish the scenario tree */
    establish_scenario_tree();
    /* 
     * symbol ^ means active node
     *
     *                 (G-id3*) - (S3*)     (G-id4) - (S4)
     *                 (G-id2) ------------ (S2)
     *                 (S1)
     * ROOT - (G-id) - (S0)
     */

    new_node.id = 0x555;
    new_node.entry_proc = (mmi_proc_func)test_id_scrn_entry5;
    mmi_frm_scrn_insert(test_group_ctx.id, test_group_ctx.id3, &new_node, MMI_FRM_NODE_BEFORE_FLAG);
    MMI_ASSERT(mmi_frm_scrn_is_present(test_group_ctx.id, 0x555, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(test_group_ctx.id3 == mmi_frm_scrn_get_neighbor_id(test_group_ctx.id, 0x555, MMI_FRM_NODE_AFTER_FLAG));
    /* 
     * symbol ^ means active node
     *
     *                 (G-id3*) - (S3*)
     *                 (S5)                 (G-id4) - (S4)
     *                 (G-id2) ------------ (S2)
     *                 (S1)
     * ROOT - (G-id) - (S0)
     */

    mmi_frm_group_set_caller(test_group_ctx.id3, test_group_ctx.id4);    
    mmi_frm_group_set_proc_data(test_group_ctx.id4, test_id_scrn_leave, (void*)0x41414141);
    tmp = mmi_frm_group_get_user_data(test_group_ctx.id4);
    mmi_frm_group_get_info(test_group_ctx.id4, &group_info);    
    mmi_frm_scrn_set_user_data(test_group_ctx.id, 0x555, (void*)0x51515151);
    mmi_frm_scrn_set_leave_proc(test_group_ctx.id, 0x555, test_id_scrn_leave);
    tmp = mmi_frm_scrn_get_user_data(test_group_ctx.id, 0x555);
    mmi_frm_scrn_get_info(test_group_ctx.id, 0x555, &scrn_info);
    mmi_frm_scrn_get_neighbor_id(test_group_ctx.id, test_group_ctx.id2, MMI_FRM_NODE_AFTER_FLAG);
    mmi_frm_scrn_get_neighbor_id(test_group_ctx.id, test_group_ctx.id2, MMI_FRM_NODE_BEFORE_FLAG);
    mmi_frm_scrn_get_count(test_group_ctx.id2);
    mmi_frm_scrn_get_state(test_group_ctx.id, test_group_ctx.id3);
    mmi_frm_scrn_get_state(test_group_ctx.id3, 0x135/* S(3) */);
    mmi_frm_scrn_get_state(test_group_ctx.id, test_group_ctx.id2);
    mmi_frm_scrn_get_state(test_group_ctx.id3, 0x579/* S(1) */);
    new_node.id = 0x666;
    new_node.entry_proc = (mmi_proc_func)test_id_scrn_entry6;
    mmi_frm_scrn_insert(test_group_ctx.id, 0x579 /* (S1) */, &new_node, MMI_FRM_NODE_AFTER_FLAG);
    MMI_ASSERT(mmi_frm_scrn_is_present(test_group_ctx.id, 0x666, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(0x579 /* (S1) */ == mmi_frm_scrn_get_neighbor_id(test_group_ctx.id, 0x666, MMI_FRM_NODE_BEFORE_FLAG));
    /* 
     * symbol ^ means active node
     *
     *                 (G-id3*) - (S3*)
     *                 (S5)                 (G-id4) - (S4)
     *                 (G-id2) ------------ (S2)
     *                 (S6)
     *                 (S1)
     * ROOT - (G-id) - (S0)
     */

    test_group_ctx.id5 = auto_gen_group_id();
    new_node.id = test_group_ctx.id5;
    new_node.entry_proc = test_group_proc;
    mmi_frm_group_insert(test_group_ctx.id, SCR_ID_INVALID, &new_node, MMI_FRM_NODE_AT_BEGINNING_FLAG);
    MMI_ASSERT(mmi_frm_group_is_present(test_group_ctx.id5));
    MMI_ASSERT(test_group_ctx.id5 == mmi_frm_scrn_get_neighbor_id(test_group_ctx.id, GRP_ID_INVALID, MMI_FRM_NODE_AT_BEGINNING_FLAG));
    /* 
     * symbol ^ means active node
     *
     *                 (G-id3*) - (S3*)
     *                 (S5)                 (G-id4) - (S4)
     *                 (G-id2) ------------ (S2)
     *                 (S6)
     *                 (S1)
     *                 (S0)
     * ROOT - (G-id) - (G-id5)
     */

    test_group_ctx.id6 = mmi_frm_group_create(test_group_ctx.id2, GRP_ID_AUTO_GEN, test_group_proc, NULL);
    new_node.id = test_group_ctx.id6;
    new_node.entry_proc = test_group_proc;
    /* mmi_frm_group_insert will correct id6's parent info. automatically. */
    mmi_frm_group_insert(test_group_ctx.id2, SCR_ID_INVALID, &new_node, MMI_FRM_NODE_AT_LATEST_FLAG);
    MMI_ASSERT(mmi_frm_group_is_present(test_group_ctx.id6));
    MMI_ASSERT(test_group_ctx.id4 == mmi_frm_scrn_get_neighbor_id(test_group_ctx.id2, test_group_ctx.id6, MMI_FRM_NODE_BEFORE_FLAG));
    /* 
     * symbol ^ means active node
     *
     *                 (G-id3*) - (S3*)     (G-id6)
     *                 (S5)                 (G-id4) - (S4)
     *                 (G-id2) ------------ (S2)
     *                 (S6)
     *                 (S1)
     *                 (S0)
     * ROOT - (G-id) - (G-id5)
     */

    test_group_ctx.id7 = auto_gen_group_id();
    new_node.id = test_group_ctx.id7;
    new_node.entry_proc = test_group_proc;
    mmi_frm_group_insert(test_group_ctx.id2, test_group_ctx.id6, &new_node, MMI_FRM_NODE_BEFORE_FLAG);
    MMI_ASSERT(mmi_frm_group_is_present(test_group_ctx.id7));
    MMI_ASSERT(test_group_ctx.id6 == mmi_frm_scrn_get_neighbor_id(test_group_ctx.id2, test_group_ctx.id7, MMI_FRM_NODE_AFTER_FLAG));
    /* 
     * symbol ^ means active node
     *                                      (G-id6)
     *                 (G-id3*) - (S3*)     (G-id7)
     *                 (S5)                 (G-id4) - (S4)
     *                 (G-id2) ------------ (S2)
     *                 (S6)
     *                 (S1)
     *                 (S0)
     * ROOT - (G-id) - (G-id5)
     */

    test_group_ctx.id8 = auto_gen_group_id();
    new_node.id = test_group_ctx.id8;
    new_node.entry_proc = test_group_proc;
    mmi_frm_group_insert(GRP_ID_ROOT, test_group_ctx.id, &new_node, MMI_FRM_NODE_AFTER_FLAG);
    MMI_ASSERT(mmi_frm_group_is_present(test_group_ctx.id8));
    MMI_ASSERT(test_group_ctx.id == mmi_frm_scrn_get_neighbor_id(GRP_ID_ROOT, test_group_ctx.id8, MMI_FRM_NODE_BEFORE_FLAG));
    /* 
     * symbol ^ means active node
     *                                        (G-id6)
     *                   (G-id3) - (S3)       (G-id7)
     *                   (S5)                 (G-id4) - (S4)
     *                   (G-id2) ------------ (S2)
     *                   (S6)
     *                   (S1)
     *        (G-id8*)   (S0)
     * ROOT - (G-id) --- (G-id5)
     */

    test_group_ctx.id9 = auto_gen_group_id();
    new_node.id = test_group_ctx.id9;
    new_node.entry_proc = test_group_proc;
    mmi_frm_group_insert(GRP_ID_ROOT, test_group_ctx.id, &new_node, MMI_FRM_NODE_AFTER_FLAG);
    MMI_ASSERT(mmi_frm_group_is_present(test_group_ctx.id9));
    MMI_ASSERT(test_group_ctx.id == mmi_frm_scrn_get_neighbor_id(GRP_ID_ROOT, test_group_ctx.id9, MMI_FRM_NODE_BEFORE_FLAG));
    /* 
     * symbol ^ means active node
     *                                        (G-id6)
     *                   (G-id3) - (S3)       (G-id7)
     *                   (S5)                 (G-id4) - (S4)
     *                   (G-id2) ------------ (S2)
     *                   (S6)
     *        (G-id8*)   (S1)
     *        (G-id9)    (S0)
     * ROOT - (G-id) --- (G-id5)
     */

    new_node.id = 0x888;    /* (S8) */
    new_node.entry_proc = (mmi_proc_func)test_id_scrn_entry8_8;
    mmi_frm_scrn_insert(test_group_ctx.id8, GRP_ID_INVALID, &new_node, MMI_FRM_NODE_AT_LATEST_FLAG);
    MMI_ASSERT(mmi_frm_scrn_is_present(test_group_ctx.id8, 0x888, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(0x888 /* (S8) */ == mmi_frm_scrn_get_neighbor_id(test_group_ctx.id8, SCR_ID_INVALID, MMI_FRM_NODE_AT_BEGINNING_FLAG));
    /* 
     * symbol ^ means active node
     *                                               (G-id6)
     *                          (G-id3) - (S3)       (G-id7)
     *                          (S5)                 (G-id4) - (S4)
     *                          (G-id2) ------------ (S2)
     *                          (S6)
     *        (G-id8*) - (S8*)  (S1)
     *        (G-id9)           (S0)
     * ROOT - (G-id) ---------- (G-id5)
     */
    
    mmi_frm_group_close(test_group_ctx.id9);
    mmi_frm_group_close(test_group_ctx.id8);

    StartTimerEx(KEY_TIMER_ID33, 100, test_case8_timeout, (void*)1);
}


void test_id_scrn_entry7(void)
{
    if (mmi_frm_scrn_enter(test_group_ctx.id5, 0x777, NULL, test_id_scrn_entry7, MMI_FRM_FULL_SCRN))
    {
        ShowCategoryDummyScreen();
    }
}

void test_id_scrn_entry8(void)
{
    if (mmi_frm_scrn_enter(test_group_ctx.id, 0x888, NULL, test_id_scrn_entry8, MMI_FRM_FULL_SCRN))
    {
        ShowCategoryDummyScreen();
    }
}

void screen_group_test_case9(void)
{
    mmi_frm_node_struct new_node = {0};

    /* establish the scenario tree */
    establish_scenario_tree();
    /* 
     * symbol ^ means active node
     *
     *                 (G-id3*) - (S3*)     (G-id4) - (S4)
     *                 (G-id2) ------------ (S2)
     *                 (S1)
     * ROOT - (G-id) - (S0)
     */

    test_group_ctx.id5 = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, NULL);
    new_node.id = 0x777;
    new_node.entry_proc = (mmi_proc_func)test_id_scrn_entry7;
    mmi_frm_scrn_insert(test_group_ctx.id5, SCR_ID_INVALID, &new_node, MMI_FRM_NODE_AT_BEGINNING_FLAG);
    new_node.id = test_group_ctx.id5;
    new_node.entry_proc = test_group_proc;
    mmi_frm_group_replace(test_group_ctx.id, test_group_ctx.id2, &new_node);
    /* 
     * symbol ^ means active node
     *
     *                 (G-id3*) - (S3*)
     *                 (G-id5) ------------ (S7)
     *                 (S1)
     * ROOT - (G-id) - (S0)
     */

    new_node.id = 0x888;
    new_node.entry_proc = (mmi_proc_func)test_id_scrn_entry8;
    mmi_frm_scrn_replace(test_group_ctx.id, 0x456/* S(0) */, &new_node);
    /* 
     * symbol ^ means active node
     *
     *                 (G-id3*) - (S3*)
     *                 (G-id5) ------------ (S7)
     *                 (S1)
     * ROOT - (G-id) - (S8)
     */

    mmi_frm_scrn_close(test_group_ctx.id3, 0x135/* S(3) */);
    /* 
     * symbol ^ means active node
     *
     *                 (G-id5*) ------------ (S7*)
     *                 (S1)
     * ROOT - (G-id) - (S8)
     */

    /* close active group (G-id) */
    mmi_frm_group_close(test_group_ctx.id);

    /* check test case result */
    test_case_check_pass();

}

    
void test_id_scrn_entry10(void)
{
    if (mmi_frm_scrn_enter(test_group_ctx.id3, 0xaaa, NULL, test_id_scrn_entry10, MMI_FRM_FULL_SCRN))
    {
        ShowCategoryDummyScreen();
    }
}

void test_case9_timeout(void * arg)
{
    if ((U32)arg == 1)
    {
        test_id_scrn_entry10();
        /* 
         * symbol ^ means active node
         *
         *                            (S10*)
         *                            (S9)  
         *                 (G-id3*) - (S3)     (G-id4) - (S4)
         *                 (G-id2) ------------ (S2)
         *                 (S1)
         * ROOT - (G-id) - (S0)
         */
    
        mmi_frm_scrn_close(test_group_ctx.id3, 0xaaa);

        StartTimerEx(KEY_TIMER_ID33, 100, test_case9_timeout, (void*)2);
    }
    else
    {
        if (_test_case_display_popup == 0)
        {
            /* display global popup */
            mmi_frm_scrn_close_active_id();
        }
        mmi_frm_group_close(test_group_ctx.id);

        /* check test case result */
#if 0
/* under construction !*/
#endif
    }
}

void test_id_scrn_entry9(void)
{
    if (mmi_frm_scrn_enter(test_group_ctx.id3, 0x999, NULL, test_id_scrn_entry9, MMI_FRM_FULL_SCRN))
    {
        ShowCategoryDummyScreen();

        if (_test_case_display_popup)
        {
            /* display popup in screen group */
            //mmi_display_popup_with_sg(test_group_ctx.id3, (UI_string_type)get_string(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE), MMI_EVENT_INFO, 0);
            mmi_popup_display_simple((WCHAR*)((UI_string_type)get_string(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE)), MMI_EVENT_INFO, test_group_ctx.id3, NULL);
        }
        else
        {
            if (!mmi_frm_is_in_backward_scenario())
            {
                /* display popup in original screen-history mech. */
                //DisplayPopup((U8*)get_string(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE), IMG_GLOBAL_INFO, 0, 1000, WARNING_TONE);
                mmi_popup_display_simple((WCHAR*)((U8*)get_string(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE)), MMI_EVENT_INFO, GRP_ID_ROOT, NULL);
            }
        }
    }
}

void screen_group_test_case10_common(void)
{
    /* establish the scenario tree */
    establish_scenario_tree();
    /* 
     * symbol ^ means active node
     *
     *                 (G-id3*) - (S3*)     (G-id4) - (S4)
     *                 (G-id2) ------------ (S2)
     *                 (S1)
     * ROOT - (G-id) - (S0)
     */

    test_id_scrn_entry9();
    /* 
     * symbol ^ means active node
     *
     *                            (popup*)
     *                            (S9)  
     *                 (G-id3*) - (S3)     (G-id4) - (S4)
     *                 (G-id2) ------------ (S2)
     *                 (S1)
     * ROOT - (G-id) - (S0)
     */

    StartTimerEx(KEY_TIMER_ID33, 100, test_case9_timeout, (void*)1);
}

void screen_group_test_case10(void)
{
    /* display popup in screen group */
    _test_case_display_popup = 1;
    screen_group_test_case10_common();
}


void screen_group_test_case11(void)
{
    /* display popup in original screen-history mech. */
    _test_case_display_popup = 0;
    screen_group_test_case10_common();
}


void test_case12_timeout(void)
{
    mmi_frm_group_close(test_group_ctx.id);

    /* check test case result */
    test_case_check_pass();
}

mmi_ret test_group_proc_123(mmi_event_struct* evt)
{
    return MMI_RET_OK;
}

mmi_ret test_group_proc_122(mmi_event_struct* evt)
{
    return MMI_RET_OK;
}

void screen_group_test_case12(void)
{
    mmi_group_event_struct evt;
    /* symbol ^ means active node
     *                  (S1^)
     * ROOT - (G-id^) - (S0)
     */
    test_group_ctx.id = mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_id_scrn_entry();
    test_id_scrn_entry1();

    /* symbol ^ means active node
     *                 (G-id2*) - (S2*)
     *                 (S1)
     * ROOT - (G-id) - (S0)
     */
    test_group_ctx.id2 = mmi_frm_group_create(test_group_ctx.id, GRP_ID_AUTO_GEN, test_group_proc_122, (void*)0x112112);
    mmi_frm_group_enter(test_group_ctx.id2, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_id2_scrn_entry2();

    /* symbol ^ means active node
     *                 (G-id3*) - (S3*)
     *                 (G-id2) ------------ (S2)
     *                 (S1)
     * ROOT - (G-id) - (S0)
     */
    test_group_ctx.id3 = mmi_frm_group_create(test_group_ctx.id, GRP_ID_AUTO_GEN, test_group_proc_123, (void*)0x113113);
    mmi_frm_group_enter(test_group_ctx.id3, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_id3_scrn_entry3();

    /* symbol ^ means active node
     *                 (G-id3*) - (S3*)     (G-id4) - (S4)
     *                 (G-id2) ------------ (S2)
     *                 (S1)
     * ROOT - (G-id) - (S0)
     */
    test_group_ctx.id4 = mmi_frm_group_enter_ex(test_group_ctx.id2, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_group_set_caller(test_group_ctx.id4, test_group_ctx.id3);
    MMI_FRM_INIT_GROUP_EVENT(&evt, 0x9876, test_group_ctx.id4);
    mmi_frm_group_send_to_caller(test_group_ctx.id4, &evt);
    MMI_FRM_INIT_GROUP_EVENT(&evt, 0x1122, test_group_ctx.id4);
    mmi_frm_group_send_to_parent(test_group_ctx.id4, &evt);

    MMI_FRM_INIT_GROUP_EVENT(&evt, 0x1234, test_group_ctx.id4);
    mmi_frm_group_post_to_caller(test_group_ctx.id4, &evt);
    MMI_FRM_INIT_GROUP_EVENT(&evt, 0x5566, test_group_ctx.id4);
    mmi_frm_group_post_to_parent(test_group_ctx.id4, &evt);

    StartTimer(KEY_TIMER_ID33, 100, test_case12_timeout);
}


mmi_ret test_id_scrn_leave1(mmi_event_struct *param)
{
    switch (param->evt_id)
    {
    case EVT_ID_SCRN_GOBACK:
        break;
    case EVT_ID_SCRN_DELETE_REQ:
        /* display popup in screen group */
        //DisplayPopupRotated_ScreenGroup(test_group_ctx.id, (PU8)get_string(STR_GLOBAL_DISCONNECTING), IMG_GLOBAL_WARNING, 0, 1000, WARNING_TONE, MMI_FRM_SCREEN_ROTATE_0);
        //mmi_display_popup_with_sg(test_group_ctx.id, (UI_string_type)get_string(STR_GLOBAL_DISCONNECTING), MMI_EVENT_QUERY, 0);
        mmi_popup_display_simple((WCHAR*)((UI_string_type)get_string(STR_GLOBAL_DISCONNECTING)), MMI_EVENT_QUERY, test_group_ctx.id, NULL);
        break;
    case EVT_ID_SCRN_DEINIT:
        break;
    }
    return MMI_RET_OK;
}

void screen_group_test_case13(void)
{
    /* display popup in screen group */
    _test_case_display_popup = 1;

    /* establish the scenario tree */
    establish_scenario_tree();
    /* 
     * symbol ^ means active node
     *
     *                 (G-id3*) - (S3*)     (G-id4) - (S4)
     *                 (G-id2) ------------ (S2)
     *                 (S1)
     * ROOT - (G-id) - (S0)
     */

    /* S1 */
    mmi_frm_scrn_set_leave_proc(test_group_ctx.id, 0x579, test_id_scrn_leave1);
    mmi_frm_scrn_close(test_group_ctx.id, 0x579);
    mmi_frm_group_close(test_group_ctx.id3);
    /* 
     * symbol ^ means active node
     *
     *                                      (G-id4*) - (S4*)
     *                 (G-id2) ------------ (S2)
     *                 (S1)
     * ROOT - (G-id) - (S0)
     */

    mmi_frm_group_close(test_group_ctx.id);

    /* check test case result */
    test_case_check_pass();
}


void screen_group_test_case14(void)
{
    mmi_frm_node_struct new_node = {0};

    /* establish the scenario tree */
    establish_scenario_tree();
    /* 
     * symbol ^ means active node
     *
     *                 (G-id3*) - (S3*)     (G-id4) - (S4)
     *                 (G-id2) ------------ (S2)
     *                 (S1)
     * ROOT - (G-id) - (S0)
     */

    new_node.id = 0x666;
    new_node.entry_proc = (mmi_proc_func)test_id_scrn_entry6;
    mmi_frm_scrn_insert(test_group_ctx.id3, SCR_ID_INVALID, &new_node, MMI_FRM_NODE_AT_BEGINNING_FLAG);

    test_group_ctx.id5 = mmi_frm_group_create(test_group_ctx.id3, GRP_ID_AUTO_GEN, test_group_proc, NULL);
    new_node.id = 0x777;
    new_node.entry_proc = (mmi_proc_func)test_id_scrn_entry7;
    mmi_frm_scrn_insert(test_group_ctx.id5, SCR_ID_INVALID, &new_node, MMI_FRM_NODE_AT_BEGINNING_FLAG);
    new_node.id = test_group_ctx.id5;
    new_node.entry_proc = test_group_proc;
    mmi_frm_group_insert(test_group_ctx.id3, SCR_ID_INVALID, &new_node, MMI_FRM_NODE_AT_BEGINNING_FLAG);
    /* 
     * symbol ^ means active node
     *
     *                            (S3*)
     *                            (S6)
     *                 (G-id3*) - (G-id5) - (S7)       (G-id4) - (S4)
     *                 (G-id2) ----------------------- (S2)
     *                 (S1)
     * ROOT - (G-id) - (S0)
     */

    mmi_frm_scrn_multiple_close(test_group_ctx.id2, test_group_ctx.id4, 1, 0, 0x789, 1);
    /* 
     * symbol ^ means active node
     *
     *                            (S3*)
     *                            (S6)
     *                 (G-id3*) - (G-id5) - (S7)       (G-id4) - (S4)
     *                 (G-id2) ----------------------- (S2)
     *                 (S1)
     * ROOT - (G-id) - (S0)
     */
    mmi_frm_scrn_multiple_close(test_group_ctx.id3, 0x135, 0, 0, 0x666, 0);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x135);
    mmi_frm_scrn_multiple_close(test_group_ctx.id3, 0x135, 1, 0, 0x666, 1);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x777);

    mmi_frm_group_close(test_group_ctx.id);

    /* check test case result */
    test_case_check_pass();
}


void screen_group_test_case15(void)
{
    test_group_ctx.id = mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_group_ctx.id2 = mmi_frm_group_create(test_group_ctx.id, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx);
    mmi_frm_group_enter(test_group_ctx.id2, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_id2_scrn_entry2();
    /* display popup in original screen-history mech. */
    //DisplayPopup((U8*)get_string(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE), IMG_GLOBAL_INFO, 0, 1000, WARNING_TONE);
    mmi_popup_display_simple((WCHAR*)((U8*)get_string(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE)), MMI_EVENT_INFO, GRP_ID_ROOT, NULL);
    /* symbol ^ means active node
     * 
     * <popup>
     * <ROOT> - (G-id) - (G-id2*) - (S2*)
     */
    mmi_frm_scrn_close(test_group_ctx.id2, 0x789);  /* close S2 */
    mmi_frm_group_close(test_group_ctx.id);
    GoBackHistory();

    test_group_ctx.id = mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_group_ctx.id2 = mmi_frm_group_create(test_group_ctx.id, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx);
    mmi_frm_group_enter(test_group_ctx.id2, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_id2_scrn_entry2();
    /* display popup in original screen-history mech. */
    //DisplayPopup((U8*)get_string(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE), IMG_GLOBAL_INFO, 0, 1000, WARNING_TONE);
    mmi_popup_display_simple((WCHAR*)((U8*)get_string(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE)), MMI_EVENT_INFO, GRP_ID_ROOT, NULL);
    /* symbol ^ means active node
     * 
     * <popup>
     * <ROOT> - (G-id) - (G-id2*) - (S2*)
     */
    mmi_frm_group_close(test_group_ctx.id2);
    mmi_frm_group_close(test_group_ctx.id);
    GoBackHistory();


    test_group_ctx.id = mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_id_scrn_entry();
    test_group_ctx.id2 = mmi_frm_group_create(test_group_ctx.id, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx);
    mmi_frm_group_enter(test_group_ctx.id2, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_id2_scrn_entry2();
    test_id_scrn_entry1();
    /* symbol ^ means active node
     *                  (S1*)
     *                  (G-id2) - (S2)
     * ROOT - (G-id^) - (S0)
     */
    mmi_frm_group_close(test_group_ctx.id2);
    mmi_frm_group_close(test_group_ctx.id);
    
    test_group_ctx.id = mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_id_scrn_entry();
    test_id_scrn_entry1();
    /* symbol ^ means active node
     *                  (S1^)
     * ROOT - (G-id^) - (S0)
     */

    test_group_ctx.id2 = mmi_frm_group_create(test_group_ctx.id, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx);
    mmi_frm_group_enter(test_group_ctx.id2, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_id2_scrn_entry2();
    /* symbol ^ means active node
     *                 (G-id2*) - (S2*)
     *                 (S1)
     * ROOT - (G-id) - (S0)
     */

    test_group_ctx.id3 = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx);
    mmi_frm_group_enter(test_group_ctx.id3, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_id3_scrn_entry3();
    /* symbol ^ means active node
     *                 
     *                                    (G-id2) ------------ (S2)
     *        (G-id3*) - (S3*)            (S1)
     * ROOT - (G-id) -------------------- (S0)
     */

    test_group_ctx.id4 = mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_id4_scrn_entry4();
    /* symbol ^ means active node
     *                 
     *        (G-id4*) - (S4*)            (G-id2) ------------ (S2)
     *        (G-id3) - (S3)              (S1)
     * ROOT - (G-id) -------------------- (S0)
     */

    /* close S3 */
    mmi_frm_group_close(test_group_ctx.id3);
    /* close S4 */
    mmi_frm_scrn_close(test_group_ctx.id4, 0x246);
    mmi_frm_group_close(test_group_ctx.id);
    mmi_frm_group_close(test_group_ctx.id4);

    /* check test case result */
    test_case_check_pass();
}


void screen_group_test_case16(void)
{
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
#endif
}


void screen_group_test_case17(void)
{
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
#endif
}


void scrn_test_case18_1(void)
{
    EntryNewScreen(0xaaa0, NULL, scrn_test_case18_1, NULL);
    ShowCategoryDummyScreen();
}

void scrn_test_case18_2(void)
{
    EntryNewScreen(0xaab0, NULL, scrn_test_case18_2, NULL);
    ShowCategory65Screen((U8*)get_string(STR_GLOBAL_COPYING), IMG_GLOBAL_INFO, NULL);
}

void screen_group_test_case18(void)
{
    scrn_test_case18_1();
    scrn_test_case18_2();
    test_group_ctx.id = mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_id_scrn_entry();
    test_id_scrn_entry1();
    EntryNewScreen(0xaab1, NULL, NULL, NULL);
    ShowCategory65Screen((U8*)get_string(STR_GLOBAL_DEFAULT), IMG_GLOBAL_INFO, NULL);
    /* symbol ^ means active node
     *
     * <0xaab1*>
     *                     (S1)
     * < ROOT > - (G-id) - (S0)
     * <0xaab0>
     * ...
     */

    GoBackToHistory(0xaab0);
    GoBacknHistory(1);

    /* check test case result */
    test_case_check_pass();
}

void scrn1_entry(mmi_scrn_essential_struct *data)
{
    MMI_ASSERT(&test_group_ctx == data->user_data);
    if (mmi_frm_scrn_enter(test_group_ctx.id, 0x123, NULL, (FuncPtr)scrn1_entry, MMI_FRM_FULL_SCRN))
    {
        ShowCategoryDummyScreen();
    }
}

void screen_group_test_case19(void)
{
    void *user_data;
    test_group_ctx.id = mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_id_scrn_entry8();
    mmi_frm_scrn_first_enter(test_group_ctx.id, 0x123, (FuncPtr)scrn1_entry, &test_group_ctx);
    MMI_ASSERT(mmi_frm_group_get_active_id() == test_group_ctx.id);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x123);
    user_data = mmi_frm_scrn_get_user_data (test_group_ctx.id, 0x123);
    mmi_frm_scrn_close(test_group_ctx.id, 0x123);
    mmi_frm_scrn_close(test_group_ctx.id, 0x888);

    /* check test case result */
    test_case_check_pass();
}


void screen_group_test_case20(void)
{
    /* display popup in screen group */
    _test_case_display_popup = 1;

    /* establish the scenario tree */
    establish_scenario_tree();
    test_id_scrn_entry9();
    /* 
     * symbol ^ means active node
     *
     *                            (popup*)
     *                            (S9)  
     *                 (G-id3*) - (S3)     (G-id4) - (S4)
     *                 (G-id2) ------------ (S2)
     *                 (S1)
     * ROOT - (G-id) - (S0)
     */

    test_id_scrn_entry10();
    /* 
     * symbol ^ means active node
     *
     *                            (S10*)
     *                            (S9)  
     *                 (G-id3*) - (S3)     (G-id4) - (S4)
     *                 (G-id2) ------------ (S2)
     *                 (S1)
     * ROOT - (G-id) - (S0)
     */
    mmi_frm_scrn_close(test_group_ctx.id3, 0xaaa);
    mmi_frm_scrn_close(test_group_ctx.id3, 0x999);

    /* 
     * symbol ^ means active node
     *
     *                            (popup*)
     *                            (S9)  
     *                 (G-id3*) - (S3)     (G-id4) - (S4)
     *                 (G-id2) ------------ (S2)
     *                 (S1)
     * ROOT - (G-id) - (S0)
     */
    mmi_frm_group_close(test_group_ctx.id);

    /* check test case result */
    test_case_check_pass();
}


void test_case21_timeout(void)
{
    mmi_frm_group_close(test_group_ctx.id);

    /* check test case result */
    test_case_check_pass();
}

mmi_ret test_group_case21_proc(mmi_event_struct* evt)
{
    test_group_context* ctx = (test_group_context*)evt->user_data;
    U32 state = ((mmi_scenario_evt_struct*)evt)->state;

    switch(evt->evt_id)
    {
    case EVT_ID_GROUP_ACTIVE:
        if (state == MMI_SCENARIO_STATE_BACKWARD_ACTIVE)
        {
            /* goback to the group from display confirm of original screen-history */
            mmi_frm_group_close(ctx->id3);
            StartTimer(KEY_TIMER_ID33, 100, test_case21_timeout);
        }
        break;
    case EVT_ID_GROUP_DEINIT:
        break;
    }
    return MMI_RET_OK;
}

/*
void screen_group_test_case21_sk(void)
{
    GoBackHistory();
}
*/
static mmi_ret screen_group_test_case21_confirmCb(mmi_alert_result_evt_struct *evt)
{
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
        case MMI_ALERT_CNFM_1:
        case MMI_ALERT_CNFM_2:
        case MMI_ALERT_CNFM_3:
            GoBackHistory();
            break;
        case MMI_ALERT_CNFM_OK:
            GoBackHistory();
            break;
        case MMI_ALERT_CNFM_YES:
        case MMI_ALERT_CNFM_NO:
            GoBackHistory();
            break;
        }
    }
    return MMI_RET_OK;
}

void screen_group_test_case21(void)
{
    mmi_confirm_property_struct arg;

    test_group_ctx.id = mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_group_ctx.id2 = mmi_frm_group_create(test_group_ctx.id, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx);
    mmi_frm_group_enter(test_group_ctx.id2, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_id2_scrn_entry2();
    /* symbol ^ means active node
     *                 
     * ROOT - (G-id) - (G-id2*) - (S2*)
     */

    test_group_ctx.id3 = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_case21_proc, &test_group_ctx);
    mmi_frm_group_enter(test_group_ctx.id3, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	mmi_confirm_property_init(&arg, CNFM_TYPE_USER_DEFINE);
	arg.softkey[0].str = (WCHAR *)((UI_string_type)get_string(STR_GLOBAL_OK));
	arg.softkey[2].str = (WCHAR *)((UI_string_type)get_string(STR_GLOBAL_BACK));
	arg.callback = (mmi_proc_func)screen_group_test_case21_confirmCb;
	mmi_confirm_display((WCHAR *)((UI_string_type)get_string(STR_GLOBAL_PROXY)), MMI_EVENT_PROGRESS, &arg);

/*
    mmi_display_popup_confirm(
        (UI_string_type)get_string(STR_GLOBAL_OK), 
        (U8*)get_image(IMG_GLOBAL_OK), 
        (UI_string_type)get_string(STR_GLOBAL_BACK), 
        (U8*)get_image(IMG_GLOBAL_BACK), 
        (UI_string_type)get_string(STR_GLOBAL_PROXY), 
        MMI_EVENT_PROGRESS);
	SetLeftSoftkeyFunction(screen_group_test_case21_sk, KEY_EVENT_UP);
	SetRightSoftkeyFunction(screen_group_test_case21_sk, KEY_EVENT_UP);
*/
    /* symbol ^ means active node
     *
     *<confirm>
     *        (G-id3*)
     * ROOT - (G-id) ------------- (G-id2) - (S2)
     */

    ExecuteCurrKeyHandler(KEY_LSK, KEY_EVENT_DOWN);
    ExecuteCurrKeyHandler(KEY_LSK, KEY_EVENT_UP);
    mmi_frm_group_close(test_group_ctx.id);
}


#define MAX_LOCAL_BUFFER 256
extern const U16 gIndexIconsImageList[];


static U8 g_buffer[MAX_LOCAL_BUFFER];
static U8 g_buffer1[MAX_LOCAL_BUFFER];

#ifndef __MMI_CSB_BROWSER__

pBOOL Get_List_Items(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    UI_UNUSED_PARAMETER(str_img_mask);
    if (item_index < 0)
    {
        return FALSE;
    }

    mmi_ucs2cpy((CHAR*) str_buff, (CHAR*) GetString((U16)(STR_GLOBAL_PHONE + (U16) item_index)));
    *img_buff_p = (U8*) GetImage(gIndexIconsImageList[item_index]);

    return TRUE;
}

S32 get_async_hints(S32 start_indx, UI_string_type *hintArray)
{
    UI_UNUSED_PARAMETER(start_indx);
    mmi_ucs2cpy((CHAR*) hintArray[0], (CHAR*) GetString((U16)(STR_GLOBAL_SAVE + start_indx)));
    return TRUE;
}

S32 cat200_callback(U8 *keyword)
{
    UI_UNUSED_PARAMETER(keyword);
    return 4;
}

void inline_tab_hilite_item(S32 index)
{    
/*    SetKeyHandler(GoBackToMainMenu, KEY_END, KEY_EVENT_DOWN);
    
    SetKeyHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);    
*/
}

void csb_full_screen_edit(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    SetLeftSoftkeyFunction(EntryScrForInputMethodAndDone, KEY_EVENT_UP);
    SetInputMethodAndDoneCaptionIcon(GetRootTitleIcon(SERVICES_WAP_MENU_ID));
}

#else

extern pBOOL Get_List_Items(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);

extern S32 get_async_hints(S32 start_indx, UI_string_type *hintArray);

extern S32 cat200_callback(U8 *keyword);

extern void inline_tab_hilite_item(S32 index);

extern void csb_full_screen_edit(void);

#endif /* #ifndef __MMI_CSB_BROWSER__ */

void entry_category199_tab_01 (mmi_scrn_essential_struct *data)
{
    U8 *guiBuffer = NULL;    

    //EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID + 1, ExitScreen_Generic, EntryCSBStartView, MMI_TAB_PAGE);
    if (mmi_frm_scrn_tab_page_enter(data->group_id, mmi_frm_scrn_get_active_id(), data->scrn_id, NULL, (FuncPtr)entry_category199_tab_01, MMI_FRM_TAB_PAGE) == MMI_FALSE)
    {
        return;
    }

#ifndef __MMI_NOT_TAB_SUPPORT__
    guiBuffer = mmi_frm_scrn_tab_page_get_active_gui_buf();
#endif /* __MMI_NOT_TAB_SUPPORT__ */

    RegisterCat200SearchFunction(cat200_callback);

    ShowCategory199Screen(
            get_string(STR_GLOBAL_START),
            0,
            get_string(STR_GLOBAL_STOP),
            0,                 
            (S8)0,
            get_string(STR_GLOBAL_SEARCHING),
            NULL,
            4,
            Get_List_Items,
            get_async_hints,
            NULL,
            NULL,
            0,
            (U8*) g_buffer,
            4,
            guiBuffer);


    /* Set the key handlers */
    SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

void entry_inline_tab_01 (mmi_scrn_essential_struct *data)
{
    U8 *guiBuffer = NULL;
	WCHAR *inputBuffer = NULL;
    S32 index;
    U16 nImgIds[5];

    if (mmi_frm_scrn_tab_page_enter(data->group_id, mmi_frm_scrn_get_active_id(), data->scrn_id, NULL, (FuncPtr)entry_inline_tab_01, MMI_FRM_TAB_PAGE) == MMI_FALSE)
    {
        return;
    }

    InitializeCategory57Screen();
    RegisterHighlightHandler(inline_tab_hilite_item);

    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    memset(g_buffer1, 0, MAX_LOCAL_BUFFER);

    SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[0], (U8*) L"Caption 1");
    SetInlineItemFullWidth(&wgui_inline_items[0]);

    SetInlineItemActivation(&wgui_inline_items[1], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit(&wgui_inline_items[1], STR_GLOBAL_OPTIONS, GetRootTitleIcon(SERVICES_WAP_MENU_ID), g_buffer, 20, IMM_INPUT_TYPE_SENTENCE);
    SetInlineFullScreenEditCustomFunction(
        &wgui_inline_items[1], 
        csb_full_screen_edit);

    SetInlineItemActivation(&wgui_inline_items[2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[2], (U8*)L"Caption 2");
    SetInlineItemFullWidth(&wgui_inline_items[2]);
    
    SetInlineItemActivation(&wgui_inline_items[3], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit(&wgui_inline_items[3], STR_GLOBAL_OPTIONS, GetRootTitleIcon(SERVICES_WAP_MENU_ID), g_buffer1, 20, IMM_INPUT_TYPE_SENTENCE);
    SetInlineFullScreenEditCustomFunction(
        &wgui_inline_items[3], 
        csb_full_screen_edit);

    SetInlineItemActivation(&wgui_inline_items[4], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[4], (U8*) L"Caption 3");
    SetInlineItemFullWidth(&wgui_inline_items[4]);

    for (index = 0; index < 5; index++)
    {        
        nImgIds[index] = IMG_GLOBAL_SAVE;        
    }

    #ifndef __MMI_NOT_TAB_SUPPORT__
	guiBuffer = mmi_frm_scrn_tab_page_get_active_gui_buf();//mmi_frm_scrn_get_active_gui_buf();
	#endif /* __MMI_NOT_TAB_SUPPORT__ */
    inputBuffer = mmi_frm_scrn_tab_page_get_active_input_buf();//mmi_frm_scrn_get_active_input_buf();
	//inputBuffer = mmi_frm_get_cur_tab_n_input_buffer(SCR_ID_CSB_DUMMY_SCR_ID + 1,  &inputBufferSize);

    //guiBuffer   = mmi_frm_get_cur_tab_gui_buffer(SCR_ID_CSB_DUMMY_SCR_ID + 1); 
		
	if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 5, (U8*)inputBuffer);
    }

    ShowCategory657Screen(
        STR_GLOBAL_PICTURE,
        0,
        STR_GLOBAL_PICTURE,
        0,
        STR_GLOBAL_PAUSE,
        0,
        5,
        nImgIds,
        wgui_inline_items,
        0,
        1,
        guiBuffer);    

#ifdef __MMI_TOUCH_SCREEN__ 
    wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);
#endif /* __MMI_TOUCH_SCREEN__ */
    //SetCategory57RightSoftkeyFunctions(GoBackToMainMenu, GoBackToMainMenu);
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);

    //SetKeyHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    //SetKeyHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    
}

void test_id_22_tab_entry(void)
{
    mmi_frm_tab_struct tab_pages_info_array[2];

    tab_pages_info_array[0].screen_id = 0x1201;
    tab_pages_info_array[0].tab_entry_func = (FuncPtr)entry_category199_tab_01;
    tab_pages_info_array[0].tab_icon = (U8*)GetImage(gIndexIconsImageList[0]);
    tab_pages_info_array[0].tab_string = NULL;
    tab_pages_info_array[0].user_data = &test_group_ctx;

    
    tab_pages_info_array[1].screen_id = 0x1202;
    tab_pages_info_array[1].tab_entry_func = (FuncPtr)entry_inline_tab_01;
    tab_pages_info_array[1].tab_icon = (U8*)GetImage(gIndexIconsImageList[1]);
    tab_pages_info_array[1].tab_string = NULL;
    tab_pages_info_array[1].user_data = &test_group_ctx;
    
    mmi_frm_scrn_tab_enter (test_group_ctx.id, 0x1200, NULL, test_id_22_tab_entry, tab_pages_info_array, 2, 0);
}

void screen_group_test_case22(void)
{
    test_group_ctx.id = mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_id_22_tab_entry();

    mmi_frm_group_close(test_group_ctx.id);

    /* check test case result */
    test_case_check_pass();
}


void screen_group_test_case23(void)
{
    test_group_ctx.id = mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_id_scrn_entry();
    test_id_scrn_entry1();
    test_id_22_tab_entry();

    mmi_frm_scrn_close(test_group_ctx.id, 0x456);   /* (S0) */
    mmi_frm_scrn_close(test_group_ctx.id, 0x579);   /* (S1) */
    mmi_frm_scrn_close(test_group_ctx.id, 0x1200);   /* (tab) */
    
    /* check test case result */
    test_case_check_pass();
}


void test_id_24_tab_entry(void)
{
    mmi_frm_tab_struct tab_pages_info_array[2];

    tab_pages_info_array[0].screen_id = 0x2401;
    tab_pages_info_array[0].tab_entry_func = (FuncPtr)entry_category199_tab_01;
    tab_pages_info_array[0].tab_icon = (U8*)GetImage(gIndexIconsImageList[0]);
    tab_pages_info_array[0].tab_string = NULL;
    tab_pages_info_array[0].user_data = &test_group_ctx;

    
    tab_pages_info_array[1].screen_id = 0x2402;
    tab_pages_info_array[1].tab_entry_func = (FuncPtr)entry_inline_tab_01;
    tab_pages_info_array[1].tab_icon = (U8*)GetImage(gIndexIconsImageList[1]);
    tab_pages_info_array[1].tab_string = NULL;
    tab_pages_info_array[1].user_data = &test_group_ctx;
    
    mmi_frm_scrn_tab_enter (test_group_ctx.id2, 0x2400, NULL, test_id_22_tab_entry, tab_pages_info_array, 2, 0);
}

void screen_group_test_case24(void)
{
    test_group_ctx.id = mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_id_22_tab_entry();

    test_group_ctx.id2 = mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_id_24_tab_entry();

    mmi_frm_scrn_close(test_group_ctx.id2, 0x2400);
    mmi_frm_scrn_close(test_group_ctx.id, 0x1200);

    mmi_frm_group_close(test_group_ctx.id);

    /* check test case result */
    test_case_check_pass();
}


void test_id_25_tab_entry_1(void)
{
    mmi_frm_tab_struct tab_pages_info_array[2];

    if (mmi_frm_is_in_backward_scenario())
    {
        /* in goback process */
        if (mmi_frm_scrn_enter(test_group_ctx.id, 0x1200, NULL, (FuncPtr)test_id_25_tab_entry_1, MMI_FRM_FULL_SCRN))
        {
            ShowCategoryDummyScreen();
        }
        //mmi_popup_display_simple((WCHAR*)((PU8)get_string(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE)), MMI_EVENT_INFO, test_group_ctx.id, NULL);
        return;
    }

    tab_pages_info_array[0].screen_id = 0x1201;
    tab_pages_info_array[0].tab_entry_func = (FuncPtr)entry_category199_tab_01;
    tab_pages_info_array[0].tab_icon = (U8*)GetImage(gIndexIconsImageList[0]);
    tab_pages_info_array[0].tab_string = NULL;
    tab_pages_info_array[0].user_data = &test_group_ctx;

    
    tab_pages_info_array[1].screen_id = 0x1202;
    tab_pages_info_array[1].tab_entry_func = (FuncPtr)entry_inline_tab_01;
    tab_pages_info_array[1].tab_icon = (U8*)GetImage(gIndexIconsImageList[1]);
    tab_pages_info_array[1].tab_string = NULL;
    tab_pages_info_array[1].user_data = &test_group_ctx;
    
    mmi_frm_scrn_tab_enter (test_group_ctx.id, 0x1200, NULL, test_id_25_tab_entry_1, tab_pages_info_array, 2, 0);
}

void test_id_25_tab_entry_2(void)
{
    mmi_frm_tab_struct tab_pages_info_array[2];

    if (mmi_frm_is_in_backward_scenario())
    {
        /* in goback process */
        tab_pages_info_array[0].screen_id = 0x1201;
        tab_pages_info_array[0].tab_entry_func = (FuncPtr)entry_category199_tab_01;
        tab_pages_info_array[0].tab_icon = (U8*)GetImage(gIndexIconsImageList[0]);
        tab_pages_info_array[0].tab_string = NULL;
        tab_pages_info_array[0].user_data = &test_group_ctx;

    
        tab_pages_info_array[1].screen_id = 0x1202;
        tab_pages_info_array[1].tab_entry_func = (FuncPtr)entry_inline_tab_01;
        tab_pages_info_array[1].tab_icon = (U8*)GetImage(gIndexIconsImageList[1]);
        tab_pages_info_array[1].tab_string = NULL;
        tab_pages_info_array[1].user_data = &test_group_ctx;
    
        mmi_frm_scrn_tab_enter (test_group_ctx.id, 0x1200, NULL, test_id_25_tab_entry_2, tab_pages_info_array, 2, 0);
        return;
    }

    if (mmi_frm_scrn_enter(test_group_ctx.id, 0x1200, NULL, (FuncPtr)test_id_25_tab_entry_2, MMI_FRM_FULL_SCRN))
    {
        ShowCategoryDummyScreen();
    }
}

void test_id_25_tab_entry_3_1(void)
{
    mmi_frm_tab_struct tab_pages_info_array[2];

    tab_pages_info_array[0].screen_id = 0x1201;
    tab_pages_info_array[0].tab_entry_func = (FuncPtr)entry_category199_tab_01;
    tab_pages_info_array[0].tab_icon = (U8*)GetImage(gIndexIconsImageList[0]);
    tab_pages_info_array[0].tab_string = NULL;
    tab_pages_info_array[0].user_data = &test_group_ctx;


    tab_pages_info_array[1].screen_id = 0x1202;
    tab_pages_info_array[1].tab_entry_func = (FuncPtr)entry_inline_tab_01;
    tab_pages_info_array[1].tab_icon = (U8*)GetImage(gIndexIconsImageList[1]);
    tab_pages_info_array[1].tab_string = NULL;
    tab_pages_info_array[1].user_data = &test_group_ctx;

    mmi_frm_scrn_tab_enter (test_group_ctx.id, 0x1210, NULL, test_id_25_tab_entry_3_1, tab_pages_info_array, 2, 0);
}

void test_id_25_tab_entry_3(void)
{
    static S32 first_enter_flag = 1;
    if (mmi_frm_is_in_backward_scenario())
    {
        /* in goback process */
        if (first_enter_flag)
        {
            mmi_frm_scrn_first_enter (test_group_ctx.id, 0x1210, test_id_25_tab_entry_3_1, NULL);
        }
        else
        {
            test_id_25_tab_entry_3_1();
        }
        return;
    }

    if (mmi_frm_scrn_enter(test_group_ctx.id, 0x1200, NULL, (FuncPtr)test_id_25_tab_entry_3, MMI_FRM_FULL_SCRN))
    {
        ShowCategoryDummyScreen();
    }
}

void screen_group_test_case25(void)
{
    /* test case 1: change screen id (0x1200) from tab to normal screen in goback process */
    test_group_ctx.id = mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_id_25_tab_entry_1();
    mmi_frm_display_dummy_screen();

    mmi_frm_scrn_close_active_id();

    mmi_frm_group_close(test_group_ctx.id);


    /* test case 2: change screen id (0x1200) from normal screen to tab in goback process */
    test_group_ctx.id = mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_id_25_tab_entry_2();
    mmi_frm_display_dummy_screen();

    mmi_frm_scrn_close_active_id();

    mmi_frm_group_close(test_group_ctx.id);

    /* test case 3: enter another tab (0x1210) when back to normal screen(0x1200) */
    test_group_ctx.id = mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_id_25_tab_entry_3();
    mmi_frm_display_dummy_screen();

    mmi_frm_scrn_close_active_id();

    mmi_frm_group_close(test_group_ctx.id);
    
    /* check test case result */
    test_case_check_pass();
}


void test_id_26_tab_entry(void)
{
    mmi_frm_tab_struct tab_pages_info_array[4];
    S32 sel_idx = 0;

    if (mmi_frm_is_in_backward_scenario())
    {
        /* in goback process */
        tab_pages_info_array[0].screen_id = 0x2401;
        tab_pages_info_array[0].tab_entry_func = (FuncPtr)entry_category199_tab_01;
        tab_pages_info_array[0].tab_icon = (U8*)GetImage(gIndexIconsImageList[0]);
        tab_pages_info_array[0].tab_string = NULL;
        tab_pages_info_array[0].user_data = &test_group_ctx;

    
        tab_pages_info_array[1].screen_id = 0x2402;
        tab_pages_info_array[1].tab_entry_func = (FuncPtr)entry_inline_tab_01;
        tab_pages_info_array[1].tab_icon = (U8*)GetImage(gIndexIconsImageList[1]);
        tab_pages_info_array[1].tab_string = NULL;
        tab_pages_info_array[1].user_data = &test_group_ctx;

        tab_pages_info_array[2].screen_id = 0x2403;
        tab_pages_info_array[2].tab_entry_func = (FuncPtr)entry_category199_tab_01;
        tab_pages_info_array[2].tab_icon = (U8*)GetImage(gIndexIconsImageList[2]);
        tab_pages_info_array[2].tab_string = NULL;
        tab_pages_info_array[2].user_data = &test_group_ctx;

    
        tab_pages_info_array[3].screen_id = 0x2404;
        tab_pages_info_array[3].tab_entry_func = (FuncPtr)entry_inline_tab_01;
        tab_pages_info_array[3].tab_icon = (U8*)GetImage(gIndexIconsImageList[3]);
        tab_pages_info_array[3].tab_string = NULL;
        tab_pages_info_array[3].user_data = &test_group_ctx;

        sel_idx = 3;
        mmi_frm_scrn_tab_change_page_items(test_group_ctx.id, 0x1200, tab_pages_info_array, 4);
    }
    else
    {
        tab_pages_info_array[0].screen_id = 0x1201;
        tab_pages_info_array[0].tab_entry_func = (FuncPtr)entry_category199_tab_01;
        tab_pages_info_array[0].tab_icon = (U8*)GetImage(gIndexIconsImageList[0]);
        tab_pages_info_array[0].tab_string = NULL;
        tab_pages_info_array[0].user_data = &test_group_ctx;

    
        tab_pages_info_array[1].screen_id = 0x1202;
        tab_pages_info_array[1].tab_entry_func = (FuncPtr)entry_inline_tab_01;
        tab_pages_info_array[1].tab_icon = (U8*)GetImage(gIndexIconsImageList[1]);
        tab_pages_info_array[1].tab_string = NULL;
        tab_pages_info_array[1].user_data = &test_group_ctx;
    }
    
    mmi_frm_scrn_tab_enter (test_group_ctx.id, (MMI_ID)0x1200, NULL, test_id_26_tab_entry, tab_pages_info_array, 2, (U8)sel_idx);
}

void screen_group_test_case26(void)
{
    test_group_ctx.id = mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_id_26_tab_entry();
    mmi_frm_display_dummy_screen();

    mmi_frm_scrn_close_active_id();

    mmi_frm_group_close(test_group_ctx.id);

    /* check test case result */
    test_case_check_pass();
}


void screen_group_test_case27(void)
{
    test_group_ctx.id = mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_group_ctx.id2 = mmi_frm_group_enter_ex(test_group_ctx.id, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_group_ctx.id3 = mmi_frm_group_enter_ex(test_group_ctx.id2, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_group_ctx.id4 = mmi_frm_group_enter_ex(test_group_ctx.id3, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_group_close(test_group_ctx.id4);


    test_group_ctx.id = mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, 0);
    test_group_ctx.id2 = mmi_frm_group_enter_ex(test_group_ctx.id, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_group_ctx.id3 = mmi_frm_group_enter_ex(test_group_ctx.id2, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_group_ctx.id4 = mmi_frm_group_enter_ex(test_group_ctx.id3, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_group_close(test_group_ctx.id4);
    mmi_frm_group_close(test_group_ctx.id);

    
    test_group_ctx.id = mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_group_ctx.id2 = mmi_frm_group_enter_ex(test_group_ctx.id, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, 0);
    test_group_ctx.id3 = mmi_frm_group_enter_ex(test_group_ctx.id2, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_group_ctx.id4 = mmi_frm_group_enter_ex(test_group_ctx.id3, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_group_close(test_group_ctx.id4);
    mmi_frm_group_close(test_group_ctx.id2);

    
    test_group_ctx.id = mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_id_scrn_entry();
    test_group_ctx.id2 = mmi_frm_group_enter_ex(test_group_ctx.id, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_group_ctx.id3 = mmi_frm_group_enter_ex(test_group_ctx.id2, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_group_ctx.id4 = mmi_frm_group_enter_ex(test_group_ctx.id3, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_group_close(test_group_ctx.id4);
    mmi_frm_group_close(test_group_ctx.id);


    test_group_ctx.id = mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_group_ctx.id2 = mmi_frm_group_enter_ex(test_group_ctx.id, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    if (mmi_frm_scrn_enter(test_group_ctx.id2, 0x789, NULL, test_id2_scrn_entry2, MMI_FRM_FULL_SCRN))
    {
        ShowCategoryDummyScreen();
    }
    test_group_ctx.id3 = mmi_frm_group_enter_ex(test_group_ctx.id2, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_group_ctx.id4 = mmi_frm_group_enter_ex(test_group_ctx.id3, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_group_close(test_group_ctx.id4);
    mmi_frm_group_close(test_group_ctx.id2);

    /* check test case result */
    test_case_check_pass();
}


mmi_ret test_id_28_caller_proc(mmi_event_struct *param)
{
    switch (param->evt_id)
    {
    case 0x9999:
        MMI_ASSERT(param->user_data == (void*)0x1234);

        break;
    default:
        break;
    }
    return MMI_RET_OK;
}

void screen_group_test_case28_timeout(void* param)
{

    if (mmi_frm_scrn_enter(test_group_ctx.id2, 0x789, NULL, test_id2_scrn_entry2, MMI_FRM_FULL_SCRN))
    {
        ShowCategoryDummyScreen();
    }

    mmi_frm_scrn_close_active_id();

    mmi_frm_group_close(test_group_ctx.id);

    /* check test case result */
    test_case_check_pass();
}

void screen_group_test_case28(void)
{
    mmi_group_event_struct evt;

    test_group_ctx.id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx);
    mmi_frm_group_enter(test_group_ctx.id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_group_ctx.id2 = mmi_frm_group_create(test_group_ctx.id, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx);
    mmi_frm_group_enter(test_group_ctx.id2, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_group_set_caller_proc(test_group_ctx.id2, test_id_28_caller_proc, (void*)0x1234);
    if (mmi_frm_scrn_enter(test_group_ctx.id2, 0x789, NULL, test_id2_scrn_entry2, MMI_FRM_FULL_SCRN))
    {
        ShowCategoryDummyScreen();
    }
    if (mmi_frm_scrn_enter(test_group_ctx.id2, 0x135, NULL, test_id2_scrn_entry2, MMI_FRM_FULL_SCRN))
    {
        ShowCategoryDummyScreen();
    }
    MMI_FRM_INIT_GROUP_EVENT(&evt, 0x9999, test_group_ctx.id2);
    mmi_frm_group_send_to_caller(test_group_ctx.id2, &evt);
    mmi_frm_group_post_to_caller(test_group_ctx.id2, &evt);

    StartTimerEx(KEY_TIMER_ID31, 10, screen_group_test_case28_timeout, NULL);
}


void test_id2_scrn_entry29_0(void) /* (G-id) - (G-id2) - (S0) */
{

    if (mmi_frm_scrn_enter(test_group_ctx.id2, 0x111, NULL, test_id2_scrn_entry29_0, MMI_FRM_FULL_SCRN))
    {
        ShowCategoryDummyScreen();
    }
}

void test_id2_scrn_entry29_1(void) /* (G-id) - (G-id2) - (S1) */
{

    if (mmi_frm_scrn_enter(test_group_ctx.id2, 0x789, NULL, test_id2_scrn_entry29_1, MMI_FRM_FULL_SCRN))
    {
        ShowCategoryDummyScreen();
    }
}

void test_id2_scrn_entry29_2(void) /* (G-id) - (G-id2) - (S2) */
{

    if (mmi_frm_scrn_enter(test_group_ctx.id2, 0x135, NULL, test_id2_scrn_entry29_2, MMI_FRM_FULL_SCRN))
    {
        ShowCategoryDummyScreen();
    }
}

void screen_group_test_case29_timeout(void* param)
{
    /* 1. Try to enter the same active screen id again. */
    if (mmi_frm_scrn_enter(test_group_ctx.id2, 0x135, NULL, test_id2_scrn_entry29_2, MMI_FRM_FULL_SCRN))
    {
        /* Don't do screen switch process but return MMI_TRUE to show the screen. */
        ShowCategoryDummyScreen();
    }

    /* 2. Try to enter the same screen id that is inactive. */
    if (mmi_frm_scrn_enter(test_group_ctx.id2, 0x789, NULL, test_id2_scrn_entry29_1, MMI_FRM_FULL_SCRN))
    {
        /* Don't do screen switch process and return MMI_FALSE directly. */
        ShowCategoryDummyScreen();
    }


    mmi_frm_scrn_close_active_id();

    mmi_frm_group_close(test_group_ctx.id);

    /* check test case result */
    test_case_check_pass();
}

void screen_group_test_case29(void)
{

    test_group_ctx.id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx);
    mmi_frm_group_enter(test_group_ctx.id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_group_ctx.id2 = mmi_frm_group_create(test_group_ctx.id, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx);
    mmi_frm_group_enter(test_group_ctx.id2, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_group_set_caller_proc(test_group_ctx.id2, test_id_28_caller_proc, (void*)0x1234);
    mmi_frm_scrn_first_enter(test_group_ctx.id2, 0x111, test_id2_scrn_entry29_0, NULL);
    if (mmi_frm_scrn_enter(test_group_ctx.id2, 0x789, NULL, test_id2_scrn_entry29_1, MMI_FRM_FULL_SCRN))
    {
        ShowCategoryDummyScreen();
    }
    if (mmi_frm_scrn_enter(test_group_ctx.id2, 0x135, NULL, test_id2_scrn_entry29_2, MMI_FRM_FULL_SCRN))
    {
        ShowCategoryDummyScreen();
    }


    StartTimerEx(KEY_TIMER_ID31, 10, screen_group_test_case29_timeout, NULL);
}


void screen_group_test_case30(void)
{
    scrn_test_case18_1();   /* 0xaaa0 */
    test_group_ctx.id = mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_id_scrn_entry();   /* G-id--S0 - 0X456 */
    test_group_ctx.id2 = mmi_frm_group_create(test_group_ctx.id, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx);
    mmi_frm_group_enter(test_group_ctx.id2, MMI_FRM_NODE_SMART_CLOSE_FLAG); 
    test_id2_scrn_entry2(); /* Gid--Gid2--S2 - 0x789 */
    test_id_scrn_entry1();  /* Gid--S1 - 0x579 */

    test_group_ctx.id3 = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx);
    mmi_frm_group_enter(test_group_ctx.id3, MMI_FRM_NODE_SMART_CLOSE_FLAG); 
    test_id3_scrn_entry3();
    EntryNewScreen(0xaab1, NULL, NULL, NULL);

    /* symbol * means active node
     *
     * <0xaab1*>                    (S1)
     * (G-id3)    - (S3)            (G-id2) - (S2)
     * (G-id)     ----------------- (S0)
     * <0xaaa0>
     * ...
     */

    /* want to set invalid group active --> do nothing */
    //mmi_frm_set_active_group(GRP_ID_ROOT);

    /* want to set G-id2 active --> do nothing */
    //mmi_frm_set_active_group(test_group_ctx.id2);

    /* want to set G-id active --> should be workable */
    mmi_frm_set_active_group(test_group_ctx.id);
    MMI_ASSERT(mmi_frm_group_is_in_active_serial(test_group_ctx.id));
    /* symbol * means active node
     *                              (S1*)
     *                              (G-id2) - (S2)
     * (G-id)     ----------------- (S0)
     * (G-id3)    - (S3)
     * <0xaaa0>
     * ...
     */

    scrn_test_case18_2();   /* 0xaab0 */
    /* symbol * means active node
     *                              (S1)
     * <0xaab0*>                    (G-id2) - (S2)
     * (G-id)     ----------------- (S0)
     * (G-id3)    - (S3)
     * <0xaaa0>
     * ...
     */

    /* want to set G-id3 active --> should be workable */
    mmi_frm_set_active_group(test_group_ctx.id3);
    MMI_ASSERT(mmi_frm_group_get_top_parent_group_id(mmi_frm_group_get_active_id()) == test_group_ctx.id3);
    /* symbol * means active node
     * (G-id3)    - (S3*)           (S1)
     * <0xaab0>                     (G-id2) - (S2)
     * (G-id)     ----------------- (S0)
     * <0xaaa0>
     * ...
     */

    GoBackToHistory(0xaaa0);
    GoBackHistory();

    /* check test case result */
    test_case_check_pass();

}


void screen_group_test_case31(void)
{
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
#endif
}

void test_id_scrn_exit33_0(void)
{
}

void test_id_scrn_entry33_0(void) /* (G-id) - (S0) */
{

    if (mmi_frm_scrn_enter(test_group_ctx.id, 0x456, test_id_scrn_exit33_0, test_id_scrn_entry33_0, MMI_FRM_FULL_SCRN))
    {
        ShowCategoryDummyScreen();
    }
}

void test_id_scrn_exit33_1(void)
{
    mmi_frm_scrn_add_history(test_group_ctx.id, 0x579);
}

void test_id_scrn_entry33_1(void) /* (G-id) - (S1) */
{

    if (mmi_frm_scrn_enter(test_group_ctx.id, 0x579, test_id_scrn_exit33_1, test_id_scrn_entry33_1, MMI_FRM_FULL_SCRN))
    {
        ShowCategoryDummyScreen();
    }
}

void test_id_scrn_exit33_2(void)
{
    mmi_frm_scrn_add_history(test_group_ctx.id, 0x135);
}

void test_id_scrn_entry33_2(void) /* (G-id) - (S2) */
{

    if (mmi_frm_scrn_enter(test_group_ctx.id, 0x135, test_id_scrn_exit33_2, NULL, MMI_FRM_FULL_SCRN))
    {
        ShowCategoryDummyScreen();
    }
}

void test_id_scrn_entry33_3(void) /* (G-id) - (S3) */
{

    if (mmi_frm_scrn_enter(test_group_ctx.id, 0x222, NULL, test_id_scrn_entry33_3, MMI_FRM_FULL_SCRN))
    {
        ShowCategoryDummyScreen();
    }
}

void screen_group_test_case33(void)
{
    test_group_ctx.id = mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_id_scrn_entry33_0();   /* G-id--S0 - 0X456 */
    test_id_scrn_entry33_1();   /* Gid--S1 - 0x579 */
    test_id_scrn_entry33_2();   /* Gid--S2 - 0x135 */
    /* Active Screen: S2, Check S1 is in the history */
    MMI_ASSERT(SG_GET_NODE_FROM_ROOT(_SCRN_ID(test_group_ctx.id,0x579)));
    test_id_scrn_entry33_3();   /* Gid--S3 - 0x222 */
    /* Active Screen: S3, Check S2 is in the history */
    MMI_ASSERT(SG_GET_NODE_FROM_ROOT(_SCRN_ID(test_group_ctx.id,0x135)));
    
    mmi_frm_scrn_close_active_id(); /* goback to S2 */
    mmi_frm_scrn_close_active_id(); /* goback to S1 */
    /* Active Screen: S1, Check S2 isn't in the history */
    MMI_ASSERT(SG_GET_NODE_FROM_ROOT(_SCRN_ID(test_group_ctx.id,0x135)) == NULL);
    mmi_frm_scrn_close_active_id(); /* goback to S0 */
    /* Active Screen: S0, Check S1 isn't in the history */
    MMI_ASSERT(SG_GET_NODE_FROM_ROOT(_SCRN_ID(test_group_ctx.id,0x579)) == NULL);

    mmi_frm_group_close(test_group_ctx.id);

    /* check test case result */
    test_case_check_pass();
}


/* Interactive Test Case */

void enterDummy20000Scr(void)
{
    if (mmi_frm_scrn_enter(10003, 20000, NULL, enterDummy20000Scr, MMI_FRM_FG_ONLY_SCRN))
    {
        ShowCategoryDummyScreen();
    }
}

void enterDummy19999Scr(void)
{
    if (mmi_frm_scrn_enter(10003, 19999, NULL, enterDummy20000Scr, MMI_FRM_FG_ONLY_SCRN))
    {
        ShowCategoryDummyScreen();
    }
}

void enterDummy20001Scr(void)
{
    if (mmi_frm_scrn_enter(10002, 20001, NULL, enterDummy20001Scr, MMI_FRM_FG_ONLY_SCRN))
    {
        ShowCategoryDummyScreen();
    }
}

void enterDummy20003Scr(void)
{
    if (mmi_frm_scrn_enter(10002, 20003, NULL, enterDummy20003Scr, MMI_FRM_FG_ONLY_SCRN))
    {
        ShowCategoryDummyScreen();
    }
}

void enterDummy20002Scr(void)
{
    if (mmi_frm_scrn_enter(10001, 20002, NULL, enterDummy20002Scr, MMI_FRM_FG_ONLY_SCRN))
    {
        MMI_ASSERT(FALSE);
    }
}

mmi_ret test34_group_proc_10001(mmi_event_struct* evt)
{
    switch(evt->evt_id)
    {
    case EVT_ID_GROUP_ENTER:
        break;
    case EVT_ID_GROUP_DEINIT:
        break;
    }
    return MMI_RET_OK;
}

mmi_ret test34_group_proc_10003(mmi_event_struct* evt)
{
    APP_VIEWPOINT_TRACE(NULL, evt);
    switch(evt->evt_id)
    {
    case EVT_ID_GROUP_ENTER:
        break;
    case EVT_ID_GROUP_DEINIT:
        if (mmi_frm_group_is_present(10002) && mmi_frm_group_is_present(10001))
        {   
            enterDummy20001Scr();
            enterDummy20002Scr();
            mmi_frm_scrn_close_active_id();
        }
        break;
    }
    return MMI_RET_OK;
}

void screen_group_test_case34(void)
{
    MMI_ID  gid1, gid2, gid3;

    gid1 = mmi_frm_group_enter_ex(GRP_ID_ROOT, 10001, test34_group_proc_10001, 0, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    gid2 = mmi_frm_group_enter_ex(GRP_ID_ROOT, 10002, test_group_proc, 0, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    gid3 = mmi_frm_group_enter_ex(GRP_ID_ROOT, 10003, test34_group_proc_10003, 0, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    enterDummy19999Scr();   /* active 19999 */
    kal_printf("act 19999\n");
    HistoryDump();
    enterDummy20000Scr();   /* active 20000. no otehr screen */
    kal_printf("act 20000\n");
    HistoryDump();
    mmi_frm_scrn_close_active_id(); /* active 20001. no other screen */
    kal_printf("act 20001\n");
    HistoryDump();
    enterDummy20003Scr();   /* active 20003. no other screen */
    kal_printf("act 20003\n");
    HistoryDump();
    enterDummy20002Scr();   /* active 20003. no other screen */
    kal_printf("act 20003\n");
    HistoryDump();
    mmi_frm_group_close(10001); 
    kal_printf("none\n");
    HistoryDump();
    mmi_frm_group_close(10002);
    kal_printf("end\n");
    HistoryDump();
    gid1 = mmi_frm_group_enter_ex(GRP_ID_ROOT, 10003, test34_group_proc_10003, 0, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    gid3 = mmi_frm_group_enter_ex(10003, 10001, test34_group_proc_10001, 0, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    gid2 = mmi_frm_group_enter_ex(10003, 10002, test_group_proc, 0, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    HistoryDump();
    enterDummy19999Scr();   /* active 19999 */
    kal_printf("act 19999\n");
    HistoryDump();
    enterDummy20000Scr();   /* active 20000. no otehr screen */
    kal_printf("act 20000\n");
    HistoryDump();
    mmi_frm_scrn_close_active_id(); /* active 20001. no other screen */
    kal_printf("act 20001\n");
    HistoryDump();
    enterDummy20003Scr();   /* active 20003. no other screen */
    kal_printf("act 20003\n");
    HistoryDump();
    enterDummy20002Scr();   /* active 20003. no other screen */
    kal_printf("act 20003\n");
    HistoryDump();
    mmi_frm_group_close(10001); 
    kal_printf("none\n");
    HistoryDump();
    mmi_frm_group_close(10003);
    kal_printf("end\n");
    HistoryDump();
}

void test_id_confirm_scrn_entry(void)
{
    if (mmi_frm_scrn_enter(test_group_ctx.id, 0x135, NULL, test_id_confirm_scrn_entry, MMI_FRM_FULL_SCRN))
    {
        ShowCategory163Screen(get_string(STR_GLOBAL_OK), get_image(IMG_GLOBAL_OK), get_string(STR_GLOBAL_BACK), get_image(IMG_GLOBAL_BACK), (UI_string_type)get_string(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE), mmi_get_event_based_image(MMI_EVENT_INFO), NULL);
        SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
}

void screen_group_test_case1000(void)
{
    test_group_ctx.id = mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    test_id_confirm_scrn_entry();
}


void screen_group_test_case1001_timeout(void *arg)
{
    EntryNewScreen(0x1234, NULL, (FuncPtr)screen_group_test_case1001_timeout, 0);
    ShowCategory163Screen(get_string(STR_GLOBAL_OK), get_image(IMG_GLOBAL_OK), get_string(STR_GLOBAL_BACK), get_image(IMG_GLOBAL_BACK), (UI_string_type)get_string(STR_GLOBAL_MOVING), mmi_get_event_based_image(MMI_EVENT_INFO), NULL);
    SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

void screen_group_test_case1001(void)
{
    StartTimerEx(KEY_TIMER_ID31, 10000, screen_group_test_case1001_timeout, NULL);
}


/*****************************************************************************
 * Small screen redraw test related data structure and define
 *****************************************************************************/

/* ID base for screen, group , history */ 
#define REDRAW_TEST_SCRN_BASE       (10000)
#define REDRAW_TEST_GRP_BASE        (20000)
#define REDRAW_TEST_HIST_BASE       (30000)
#define REDRAW_TEST_INVALID_SCR_SN  (0)

/* Serial number to screen id, group id */
#define REDRAW_TEST_SCRN_ID(SN)      ((SN) + REDRAW_TEST_SCRN_BASE)
#define REDRAW_TEST_GRP_ID(SN)       ((SN) + REDRAW_TEST_GRP_BASE)
#define REDRAW_TEST_HIST_ID(SN)      ((SN) + REDRAW_TEST_HIST_BASE)

#ifndef __MTK_TARGET__
    #define REDRAW_TC_TRACE(x)               kal_printf x
#else
    #define REDRAW_TC_TRACE(x)    
#endif


/* Log record size */
#define REDRAW_TEST_MAX_LOG_COUNT     (32)

/* Log structure to recorde the entry/exit relation.
   We use the log to check whether the exit function is paired to entry function properly */
typedef struct 
{
    S32         data[REDRAW_TEST_MAX_LOG_COUNT];
    S32         idx;
    MMI_BOOL    clean;    
}redraw_test_log_struct;
 
/*
  Data structure of global data for small screen redraw test
*/
typedef struct _redraw_test_data_struct
{
    redraw_test_log_struct      log;
    U32                         topmost_full_screen_sn;         /* serial number of topmost full screen in test simulation */
    MMI_BOOL                    building_tree;                  /* is the redraw test in establish scenario tree process */
    U32                         skip_group;                     /* group that simulate to be skip */
    U32                         result_first_bg_screen;         /* test result of first background screen be drawn at the test condition */
    U32                         target_first_bg_screen;         /* test result of first background screen be drawn at the test condition */
}redraw_test_data_struct;

static redraw_test_data_struct  redraw_test_data;

/*****************************************************************************
 * Small screen redraw test related function implementation - Log
 *****************************************************************************/

/* Log related funtion implementation*/
static void redraw_test_init_log()
{
    memset(&redraw_test_data.log, 0, sizeof(redraw_test_data.log));
    redraw_test_data.log.clean = MMI_TRUE;
}

static void redraw_test_set_tag(U32   tag)
{
    MMI_ASSERT(redraw_test_data.log.clean == MMI_TRUE);
    redraw_test_data.log.data[redraw_test_data.log.idx] = tag;
    redraw_test_data.log.clean = MMI_FALSE;
}

static void redraw_test_check_and_clean_tag(U32 tag)
{

    MMI_ASSERT(redraw_test_data.log.data[redraw_test_data.log.idx] == (S32)tag);
    redraw_test_data.log.idx++;
    redraw_test_data.log.idx %= REDRAW_TEST_MAX_LOG_COUNT;
    redraw_test_data.log.clean = MMI_TRUE;
}

static void redraw_test_trace_prefix()
{
    if (mmi_is_redrawing_bk_screens() == MMI_TRUE)
    {
        REDRAW_TC_TRACE(("** BG "));
    }
    else
    {
        REDRAW_TC_TRACE(("** FG "));
    }
}

/*****************************************************************************
 * Small screen redraw test related function implementation - common entry/exit
 *****************************************************************************/

//#define SHOW_CAGEGORY_SCREEN   ShowCategory65Screen((U8*) L"REDRAW TEST", IMG_GLOBAL_INFO, NULL)
#define SHOW_CAGEGORY_SCREEN    ShowCategoryDummyScreen()

/* simulate show category process
   the function will set full/small screen attribute according to current test case 
*/
static void redraw_test_simulate_show_category(U32 scrn_sn)
{
    MMI_ID  active_grp_ID;
    redraw_test_set_tag(scrn_sn);
    if (redraw_test_data.building_tree)
    {
        SHOW_CAGEGORY_SCREEN;
        /* scrn_sn > 100: tab pages */
        if ((scrn_sn %100) <= redraw_test_data.topmost_full_screen_sn)
        {   
            REDRAW_TC_TRACE(("FULL"));
            if ((active_grp_ID = mmi_frm_group_get_active_id()) != GRP_ID_INVALID)
            {
                ResetBit(shell.active_scrn->attrib, NODE_ATTRIB_SMALL_SCREEN_IDX);
                SetBit(shell.active_scrn->attrib, NODE_ATTRIB_FULL_SCREEN_IDX);
             }
            else
            {
                reset_small_screen();
            }
        }
        else
        {
            REDRAW_TC_TRACE(("SMALL"));
            if ((active_grp_ID = mmi_frm_group_get_active_id()) != GRP_ID_INVALID)
            {
                /* set small screen seems not work at tab condition, use set bit directly. */
                SetBit(shell.active_scrn->attrib, NODE_ATTRIB_SMALL_SCREEN_IDX);
                ResetBit(shell.active_scrn->attrib, NODE_ATTRIB_FULL_SCREEN_IDX);
            }
            else
            {
                set_small_screen();
            }
        }
    }
    else
    {
        if (mmi_is_redrawing_bk_screens() == MMI_TRUE)
        {
            mmi_frm_enable_redraw_empty_bg();
            if (redraw_test_data.result_first_bg_screen == REDRAW_TEST_INVALID_SCR_SN)
            {   
                redraw_test_data.result_first_bg_screen = REDRAW_TEST_SCRN_ID(scrn_sn);
            }
        }
        else
        {
            SHOW_CAGEGORY_SCREEN;
        }
    }
    REDRAW_TC_TRACE(("\n"));
}

/*  Macro for define scenario enter/exit function of the test scenario
*/
#define TEST_SCRN_DECLARE(GRP_SN, SCRN_SN, TYPE)                                                            \
static void redraw_test_exit_##SCRN_SN(void)                                                                \
{                                                                                                           \
    REDRAW_TC_TRACE(("**    REDRAW TEST SCRN EXIT:  %d\n", REDRAW_TEST_SCRN_ID(SCRN_SN)));                  \
    redraw_test_check_and_clean_tag(SCRN_SN);                                                               \
}                                                                                                           \
                                                                                                            \
static void redraw_test_enter_##SCRN_SN(void)                                                               \
{                                                                                                           \
                                                                                                            \
    if (mmi_frm_scrn_enter(                                                                                 \
        REDRAW_TEST_GRP_ID(GRP_SN), REDRAW_TEST_SCRN_ID(SCRN_SN),                                           \
        redraw_test_exit_##SCRN_SN, redraw_test_enter_##SCRN_SN, TYPE))                                     \
    {                                                                                                       \
        redraw_test_trace_prefix();                                                                         \
        REDRAW_TC_TRACE(("REDRAW TEST SCRN ENTER: %d ", REDRAW_TEST_SCRN_ID(SCRN_SN)));                     \
        redraw_test_simulate_show_category(SCRN_SN);                                                        \
    }                                                                                                       \
}                                                                                                           \
 
/*  Macro for define history enter/exit function of the test scenario
*/
#define TEST_SCRN_HIST_DECLARE(SCRN_SN, TYPE)                                                               \
static void redraw_test_hist_exit_##SCRN_SN(void)                                                           \
{                                                                                                           \
    REDRAW_TC_TRACE(("**    REDRAW TEST HIST EXIT:  %d\n", REDRAW_TEST_HIST_ID(SCRN_SN)));                  \
    redraw_test_check_and_clean_tag(SCRN_SN);                                                               \
}                                                                                                           \
                                                                                                            \
static void redraw_test_hist_entry_##SCRN_SN(void)                                                          \
{                                                                                                           \
    EntryNewScreen(REDRAW_TEST_HIST_ID(SCRN_SN),                                                            \
            redraw_test_hist_exit_##SCRN_SN, redraw_test_hist_entry_##SCRN_SN, TYPE);                       \
    redraw_test_trace_prefix();                                                                             \
    REDRAW_TC_TRACE(("REDRAW TEST HIST ENTER: %d ", REDRAW_TEST_HIST_ID(SCRN_SN)));                         \
    redraw_test_simulate_show_category(SCRN_SN);                                                            \
}                                                                                                           \

#define REDRAW_TEST_SCRN_COUNT          (14)
#define REDRAW_TEST_TAB_PAGE_COUNT      (4)
#define REDRAW_TEST_SCRN_ALL_COUNT      (REDRAW_TEST_SCRN_COUNT + REDRAW_TEST_TAB_PAGE_COUNT)    
#define REDRAW_TEST_GROUP_MAX           (6)

/*****************************************************************************
 * Small screen redraw test related function implementation -
 * Redraw test screen function main body
 *****************************************************************************/
TEST_SCRN_DECLARE(1, 1, MMI_FRM_SMALL_SCRN)     /* Grp 1, Scrn 1 */
TEST_SCRN_DECLARE(1, 2, MMI_FRM_SMALL_SCRN)
TEST_SCRN_DECLARE(2, 3, MMI_FRM_SMALL_SCRN)     /* Grp 2, Scrn 3 */
TEST_SCRN_DECLARE(2, 4, MMI_FRM_SMALL_SCRN) 
TEST_SCRN_DECLARE(3, 5, MMI_FRM_SMALL_SCRN)     /* Grp 3, Scrn 5 */
TEST_SCRN_DECLARE(4, 6, MMI_FRM_SMALL_SCRN)     /* Grp 4, Scrn 6 */
//7 -> TAB                                      /* Grp 4, Scrn 7, Scrn tab */
TEST_SCRN_DECLARE(4, 107, MMI_FRM_TAB_PAGE)     /* Grp 4, Scrn 107, 207 Tab pages (for Scrn 7)*/    
TEST_SCRN_DECLARE(4, 207, MMI_FRM_TAB_PAGE)
TEST_SCRN_DECLARE(4, 8, MMI_FRM_SMALL_SCRN)
TEST_SCRN_HIST_DECLARE(9, NULL)                 /* Scrn 9, history screen */
TEST_SCRN_DECLARE(5,10, MMI_FRM_SMALL_SCRN)     /* Grp 5, Scrn 10 */
TEST_SCRN_DECLARE(6,11, MMI_FRM_SMALL_SCRN)     /* Grp 6, Scrn 11 */
//12 -> History Tab                             /* Scrn 12, Hist Tab */ 
//TEST_SCRN_HIST_DECLARE(312, MMI_TAB_PAGE)       /* Scrn 312: Tab page for scrn 12 */
//TEST_SCRN_HIST_DECLARE(412, MMI_TAB_PAGE)       /* Scrn 412: Tab page for scrn 12 */
TEST_SCRN_HIST_DECLARE(12, NULL)                /* Scrn 12, history screen */
TEST_SCRN_HIST_DECLARE(13, NULL)                /* Scrn 13, history screen */
TEST_SCRN_HIST_DECLARE(14, NULL)                /* Scrn 14, history screen */


static mmi_ret redraw_test_group_proc(mmi_event_struct* evt)
{
    mmi_ret ret = MMI_RET_OK;
    APP_VIEWPOINT_TRACE(NULL, evt);
    switch(evt->evt_id)
    {
    case EVT_ID_GROUP_ENTER:
        break;
    case EVT_ID_GROUP_DEINIT:
        break;
    case EVT_ID_GROUP_REDRAW_START:
        REDRAW_TC_TRACE(("!!!!!! GROUP REDRAW START:  %d\n", (U32) evt->user_data));
        if (REDRAW_TEST_GRP_ID(redraw_test_data.skip_group) == (U32)evt->user_data)
        {
            REDRAW_TC_TRACE(("!!!!!!!!!!!!!!!!!!!! GROUP REDRAW SKIP:   %d !!!!!!!!!!!!!!!!!!!!!!\n", (U32) evt->user_data));
            ret = MMI_RET_REDRAW_EMPTY_BG;
        }
        break;
    case EVT_ID_GROUP_REDRAW_DONE:
        REDRAW_TC_TRACE(("!!!!! GROUP REDRAW DONE:   %d\n", (U32) evt->user_data));
        break;
    }
    return ret;
}

void redraw_test_tab_enter_7(void)
{
    mmi_frm_tab_struct tab_pages_info_array[2];
    tab_pages_info_array[0].screen_id = REDRAW_TEST_SCRN_ID(107);
    tab_pages_info_array[0].tab_entry_func = (FuncPtr)redraw_test_enter_107;
    tab_pages_info_array[0].tab_icon = (U8*)GetImage(gIndexIconsImageList[0]);
    
    tab_pages_info_array[1].screen_id = REDRAW_TEST_SCRN_ID(207);
    tab_pages_info_array[1].tab_entry_func = (FuncPtr)redraw_test_enter_207;
    tab_pages_info_array[1].tab_icon = (U8*)GetImage(gIndexIconsImageList[1]);
    
    mmi_frm_scrn_tab_enter(REDRAW_TEST_GRP_ID(4), REDRAW_TEST_SCRN_ID(7), NULL, redraw_test_tab_enter_7, tab_pages_info_array, 2, 0);
}
/*
void redraw_test_tab_hist_entry_12(void)
{
    mmi_frm_tab_struct tab_pages_info_array[2];
    tab_pages_info_array[0].screen_id = REDRAW_TEST_SCRN_ID(312);
    tab_pages_info_array[0].tab_entry_func = redraw_test_hist_entry_312;
    tab_pages_info_array[0].tab_icon = (U8*)GetImage(gIndexIconsImageList[0]);
    
    tab_pages_info_array[1].screen_id = REDRAW_TEST_SCRN_ID(412);
    tab_pages_info_array[1].tab_entry_func = redraw_test_hist_entry_412;
    tab_pages_info_array[1].tab_icon = (U8*)GetImage(gIndexIconsImageList[1]);
    
    mmi_frm_general_tab_entry(REDRAW_TEST_SCRN_ID(12), redraw_test_tab_hist_entry_12, tab_pages_info_array, 2);
}
*/
/*****************************************************************************
 * Small screen redraw test related function implementation -
 * Establish scenario tree
 *****************************************************************************/
static void small_screen_redraw_test_establish_tree(void)
{

    mmi_frm_group_enter_ex(GRP_ID_ROOT, REDRAW_TEST_GRP_ID(1), redraw_test_group_proc, (void*)REDRAW_TEST_GRP_ID(1), MMI_FRM_NODE_SMART_CLOSE_FLAG);
    redraw_test_enter_1();
    redraw_test_enter_2();
    mmi_frm_group_create(REDRAW_TEST_GRP_ID(1), REDRAW_TEST_GRP_ID(2), redraw_test_group_proc, (void*)REDRAW_TEST_GRP_ID(2));
    mmi_frm_group_enter(REDRAW_TEST_GRP_ID(2), MMI_FRM_NODE_SMART_CLOSE_FLAG);
    redraw_test_enter_3();
    redraw_test_enter_4();
    mmi_frm_group_create(REDRAW_TEST_GRP_ID(1), REDRAW_TEST_GRP_ID(3), redraw_test_group_proc, (void*)REDRAW_TEST_GRP_ID(3));
    mmi_frm_group_enter(REDRAW_TEST_GRP_ID(3), MMI_FRM_NODE_SMART_CLOSE_FLAG);
    redraw_test_enter_5();
    mmi_frm_group_create(REDRAW_TEST_GRP_ID(3), REDRAW_TEST_GRP_ID(4), redraw_test_group_proc, (void*)REDRAW_TEST_GRP_ID(4));
    mmi_frm_group_enter(REDRAW_TEST_GRP_ID(4), MMI_FRM_NODE_SMART_CLOSE_FLAG);
    redraw_test_enter_6();

    /* 107, 207, tab pages, 7 tab screen, group 4 */
    redraw_test_tab_enter_7();
    redraw_test_enter_8();

    redraw_test_hist_entry_9();
    mmi_frm_group_enter_ex(GRP_ID_ROOT, REDRAW_TEST_GRP_ID(5), redraw_test_group_proc, (void*)REDRAW_TEST_GRP_ID(5), MMI_FRM_NODE_SMART_CLOSE_FLAG);
    redraw_test_enter_10();
    mmi_frm_group_enter_ex(GRP_ID_ROOT, REDRAW_TEST_GRP_ID(6), redraw_test_group_proc, (void*)REDRAW_TEST_GRP_ID(6), MMI_FRM_NODE_SMART_CLOSE_FLAG);
    redraw_test_enter_11();
    
    /* 312, 412, tab pages, 12 tab screen, history node */
    //redraw_test_tab_hist_entry_12();
    redraw_test_hist_entry_12();
    redraw_test_hist_entry_13();
    redraw_test_hist_entry_14();

    REDRAW_TC_TRACE(("* REDRAW TEST TREE ESTABLISHED\n"));
    HistoryDump();
}

/*****************************************************************************
 * Small screen redraw test related function implementation -
 * Main test loop
 *****************************************************************************/
static void small_screen_redraw_test_case1(void)
{
    S32 i, j, k;
    S32 target_scr_sn, current_fg_scr_sn;
    redraw_test_init_log();
    
    for (k = 0; k <= REDRAW_TEST_GROUP_MAX; k++)
    {
        /* test the condition the grop proc of specfic group k for return MMI_RET_REDRAW_EMPTY_BG */
        redraw_test_data.skip_group = k;
        for (i = 1; i <= REDRAW_TEST_SCRN_ALL_COUNT; i++)
        {
            /* test the condition that the scenario tree contains i small screen */
            redraw_test_data.topmost_full_screen_sn = i;
            REDRAW_TC_TRACE(("********** REDRAW TEST FULL SCREEN COUNT: %d ************\n", i));
            redraw_test_data.building_tree = MMI_TRUE;
            small_screen_redraw_test_establish_tree();
            redraw_test_data.building_tree = MMI_FALSE;
            for (j = 0; j < REDRAW_TEST_SCRN_COUNT; j++)
            {
                /* test the condition that go back the scenario tree step by step */
                REDRAW_TC_TRACE(("------------------------------------------\n"));
                REDRAW_TC_TRACE(("* REDRAW TEST CLOSE ACTIVE COUNT: %d\n", j));
                /* reset first_bg_screen */
                redraw_test_data.result_first_bg_screen = REDRAW_TEST_INVALID_SCR_SN;
                redraw_test_data.target_first_bg_screen = REDRAW_TEST_INVALID_SCR_SN;               
                /* caculate the screen that the redraw should start at */
                current_fg_scr_sn = REDRAW_TEST_SCRN_COUNT - j - 1;     // -1 because go backhistory 
                target_scr_sn = redraw_test_data.topmost_full_screen_sn;

                if (target_scr_sn >= current_fg_scr_sn)
                    target_scr_sn = 0;
                if ((target_scr_sn > 0) && (target_scr_sn < REDRAW_TEST_SCRN_COUNT))
                {
                    redraw_test_data.target_first_bg_screen = REDRAW_TEST_SCRN_ID(target_scr_sn);
                }

                /* set test pass criterial */
                mmi_frm_scrn_close_active_id();
               
                MMI_ASSERT(
                    (redraw_test_data.result_first_bg_screen % 100 )== (redraw_test_data.target_first_bg_screen %100)
                    ||(k!=0));  // Only verify the correctness of first bg redraw when no group skip case 
            }
        }
    }
}

const static FuncPtr test_case_func_table[] = {
                        /* Interaction between original screen-history mech. and screen group mech. */
#if 1
                        //screen_group_test_case34,
                        screen_group_test_case0,
                        screen_group_test_case1,
                        screen_group_test_case2,
                        screen_group_test_case3,
                        screen_group_test_case4,
                        /*
                         * In screen group mech.
                         * 1. Entry group/screen that the parent isn't active
                         * 2. Close group/screen with the target node is active or inactive
                         */
                        screen_group_test_case5,

                        /* In screen group mech. close the unused group */
                        screen_group_test_case6,

                        /*
                         * In screen group mech.
                         * Entry group/screen twice (invoke at the active group) 
                         */
                        screen_group_test_case7,

                        /*
                         * In screen group mech.
                         * Insert group/screen & set/get group/screen 
                         */
                        screen_group_test_case8,

                        /*
                         * In screen group mech.
                         * Replace group/screen & Close group(has sub-tree)
                         */
                        screen_group_test_case9,

                        /*
                         * entry screen twice in goback process & 
                         * display popup in screen group
                         */
                        screen_group_test_case10,

                        /*
                         * entry screen twice in goback process & 
                         * display popup in original screen-history mech.
                         */
                        screen_group_test_case11,

                        /*
                         * screen notification send & post
                         */
                        screen_group_test_case12,

                        /*
                         * entry new screen when deleting someone screen
                         */
                        screen_group_test_case13,

                        /* multiple close screens */
                        screen_group_test_case14,

                        /* entry conjoint group in root and close one of them */
                        screen_group_test_case15,

                        /* Press END key to leave the screen within screen group mechanism */
                        screen_group_test_case16,

                        /* Press END key in the historyData[] includes screen-group-adaptor node */
                        screen_group_test_case17,

                        /* GoBacknHistory when the historyData[] includes screen-group-adaptor node */
                        screen_group_test_case18,
                        /* mmi_frm_scrn_first_enter */
                        screen_group_test_case19,

                        /* re-entry */
                        screen_group_test_case20,

                        /* GobackHistory from confirm of original screen-history mech. to screen group */
                        screen_group_test_case21,

                        /* entry tab, tab-page */
                        screen_group_test_case22,

                        /* entry screen, entry tab, tab-page and then close screen */
                        screen_group_test_case23,

                        /* entry group, entry tab, tab-page and enter group, enter tab, tab-page */
                        screen_group_test_case24,

                        /* enter SCR_ID_A(tab), enter dummy screen, goback to SCR_ID_A(scrn) [SCR_ID_A changed from tab to screen] */
                        //screen_group_test_case25,

                        /* enter tab , enter dummy screen, goback to tab and change tab page items */
                        screen_group_test_case26,

                        /* smart close (group) */
                        screen_group_test_case27,
#endif
                        /* verify mmi_frm_group_set_caller_proc behavior */
                        screen_group_test_case28,

                        /* enter the same screen id (active and inactive case) */
                        screen_group_test_case29,
                        /* verify mmi_frm_set_group_active behavior */
                        screen_group_test_case30,
                        /* verify mmi_frm_group_query_children_list behavior */
                        screen_group_test_case31,

                        /* verify mmi_frm_scrn_add_history behavior */
                        screen_group_test_case33,
                        /* Test case for small screen background redraw */
                        small_screen_redraw_test_case1,
                        NULL
                        };


const static FuncPtr test_case_interactive_func_table[] = {
                        /* [Need human response] confirm for testing small screen bk redrawing */
                        screen_group_test_case1000,

                        /* [Need human response: Special] start timer to show confirm in historyData to test screen group */
                        screen_group_test_case1001,

                        NULL
                        };

void screen_group_testbed(void *arg)
{
    const FuncPtr *test_table = test_case_func_table;

    static MMI_ID   dummyGrpId; 
     if (arg == (void*)'AUTO')
    {
        /* auto-testing test case */
        test_table = test_case_func_table;
        test_case_idx = 0;
        /* Init check */
        dummyGrpId = mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, test_group_proc, &test_group_ctx, MMI_FRM_NODE_NONE_FLAG);
         
        test_case_check_init();
        memcpy(g_mem_dbg_test_record, g_mem_dbg_record, sizeof(U32)*100);
    }
    else if (arg == (void*)'INTA')
    {
        /* interactive test case */
        test_table = test_case_interactive_func_table;
        test_case_idx = 0;
    }
    else if (arg == (void*)'NEXT')
    {
    #ifndef __MTK_TARGET__
        kal_printf("EXECUTE_TEST_CASE_%d <END>\n\n", test_case_idx-1);
    #endif
    }

    if (test_table[test_case_idx])
    {
    #ifndef __MTK_TARGET__
        kal_printf("EXECUTE_TEST_CASE_%d <BEGIN>\n", test_case_idx);
    #endif
        test_table[test_case_idx]();

        if (test_table[test_case_idx] == screen_group_test_case10 ||
            test_table[test_case_idx] == screen_group_test_case11)
        {
            test_case_idx++;
            StartTimerEx(KEY_TIMER_ID32, 2500, screen_group_testbed, (void*)'NEXT');
        }
        else
        {
            test_case_idx++;
            StartTimerEx(KEY_TIMER_ID32, 300, screen_group_testbed, (void*)'NEXT');
        }
    }
    else
    {
        /* Finish test case flow */
        test_case_idx = 0;
        mmi_frm_group_close(dummyGrpId);
    }
}

void start_screen_group_testbed(void)
{
    StartTimerEx(KEY_TIMER_ID32, 300, screen_group_testbed, (void*)'AUTO');
}



U8 check1, check2;

typedef struct
{
	MMI_ID id;
	const CHAR *name;
} evt_info;

const evt_info evt_map[] = 
{
	EVT_ID_GROUP_ENTER, "EVT_ID_GROUP_ENTER",
	EVT_ID_GROUP_ACTIVE, "EVT_ID_GROUP_ACTIVE",
	EVT_ID_GROUP_INACTIVE, "EVT_ID_GROUP_INACTIVE",
	EVT_ID_GROUP_FOCUSED, "EVT_ID_GROUP_FOCUSED",
	EVT_ID_GROUP_DEFOCUSED, "EVT_ID_GROUP_DEFOCUSED",
	EVT_ID_GROUP_GOBACK, "EVT_ID_GROUP_GOBACK",
	EVT_ID_GROUP_GOBACK_IN_END_KEY, "EVT_ID_GROUP_GOBACK_IN_END_KEY",
	EVT_ID_GROUP_DELETE_REQ, "EVT_ID_GROUP_DELETE_REQ",
	EVT_ID_GROUP_DELETE_REQ_IN_END_KEY, "EVT_ID_GROUP_DELETE_REQ_IN_END_KEY",
	EVT_ID_GROUP_EXIT, "EVT_ID_GROUP_EXIT",
	EVT_ID_GROUP_DEINIT, "EVT_ID_GROUP_DEINIT",
	EVT_ID_GROUP_REDRAW_START, "EVT_ID_GROUP_REDRAW_START",
	EVT_ID_GROUP_REDRAW_DONE, "EVT_ID_GROUP_REDRAW_DONE",
	EVT_ID_SCRN_ACTIVE, "EVT_ID_SCRN_ACTIVE",
	EVT_ID_SCRN_INACTIVE, "EVT_ID_SCRN_INACTIVE",
	EVT_ID_SCRN_GOBACK, "EVT_ID_SCRN_GOBACK",
	EVT_ID_SCRN_GOBACK_IN_END_KEY, "EVT_ID_SCRN_GOBACK_IN_END_KEY",
	EVT_ID_SCRN_DELETE_REQ, "EVT_ID_SCRN_DELETE_REQ",
	EVT_ID_SCRN_DELETE_REQ_IN_END_KEY, "EVT_ID_SCRN_DELETE_REQ_IN_END_KEY",
	EVT_ID_SCRN_DEINIT, "EVT_ID_SCRN_DEINIT",
    EVT_ID_GROUP_HIDE, "EVT_ID_GROUP_HIDE",
    EVT_ID_GROUP_UNHIDE, "EVT_ID_GROUP_UNHIDE",
    EVT_ID_SCRN_HIDE, "EVT_ID_SCRN_HIDE",
    EVT_ID_SCRN_UNHIDE, "EVT_ID_SCRN_UNHIDE",
    EVT_ID_NO_CHILD_NOTIFY, "EVT_ID_NO_CHILD_NOTIFY"
};

void print_evt_string(MMI_ID id)
{
	S32 i;
	for (i = 0; i < ARRAY_COUNT(evt_map); i++)
	{
		if (evt_map[i].id == id)
		{
			kal_prompt_trace(MOD_MMI, evt_map[i].name);
		}
	}

}

void print_event_info(MMI_ID evt_id, MMI_ID group_id, MMI_ID tab_id, MMI_ID scrn_id)
{
	S32 i;
	for (i = 0; i < ARRAY_COUNT(evt_map); i++)
	{
		if (evt_map[i].id == evt_id)
		{
			kal_prompt_trace(MOD_MMI, "[E]%s, [G]%d, [T]%d, [S]%d", evt_map[i].name, group_id, tab_id, scrn_id);
			break;
		}
	}
}
/******************************************************************************
 * Find previous screen id
 ******************************************************************************/

//case 1,  previous node is screen node
//case 2,  previous node is group node and the group node has screen node
//case 3,  previous node is group node and the group node has no screen node
//case 4,  No previous node



/******************************************************************************
 * scrn id update in screen group
 ******************************************************************************/
typedef enum
{
    SCR_ID_A = 1,
    SCR_ID_B,
    SCR_ID_C,
    SCR_ID_D,
    GRP_ID_A  = 10000,
    GRP_ID_B,
    GRP_ID_C,
    NODE_ID_END
} node_id_enum;
static void check_scrn_id(U16 ep_a_gid, U16 ep_a_sid, U16 ep_e_gid, U16 ep_e_sid)
{
    U16 group_id = GRP_ID_INVALID;
    U16 scrn_id  = SCR_ID_INVALID;
    
    MMI_ASSERT(GetActiveScreenId() == ep_a_sid);
    MMI_ASSERT(GetExitScrnID() == ep_e_sid);
    mmi_frm_get_exit_scrn_id(&group_id, &scrn_id);
    MMI_ASSERT(group_id == ep_e_gid);
    MMI_ASSERT(scrn_id == ep_e_sid);
    mmi_frm_get_active_scrn_id(&group_id, &scrn_id);
    MMI_ASSERT(group_id == ep_a_gid);
    MMI_ASSERT(scrn_id == ep_a_sid);
}

void _scrn_entry_A(void *arg)
{
}
void _scrn_exit_A(void *arg)
{
    check_scrn_id(GRP_ID_ROOT, GRP_ID_A, GRP_ID_ROOT, SCR_ID_A);
}

mmi_ret scrn_id_test_common_proc(void *user_data)
{
    return MMI_RET_OK;
}

mmi_ret _scrn_enter_B(mmi_scrn_essential_struct *data)
{
    return MMI_RET_OK;
}

mmi_ret _scrn_exit_B(mmi_scrn_essential_struct *data)
{
    check_scrn_id(GRP_ID_A, SCR_ID_C, GRP_ID_A, SCR_ID_B);
    return MMI_RET_OK;
}

mmi_ret _scrn_enter_C(mmi_scrn_essential_struct *data)
{
    return MMI_RET_OK;
}

mmi_ret _scrn_exit_C(mmi_scrn_essential_struct *data)
{
    check_scrn_id(GRP_ID_A, SCR_ID_B, GRP_ID_A, SCR_ID_C);
    return MMI_RET_OK;
}

mmi_ret test_scrn_id_update(void *para)
{
    mmi_frm_close_to_idle_group();
    mmi_frm_entry_new_screen(SCR_ID_A, _scrn_exit_A, _scrn_entry_A, NULL);
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_A, scrn_id_test_common_proc, NULL);
    mmi_frm_group_enter(GRP_ID_A, MMI_FRM_NODE_NONE_FLAG);
    mmi_frm_scrn_enter(GRP_ID_A, SCR_ID_B, (FuncPtr)_scrn_exit_B, (FuncPtr)_scrn_enter_B, MMI_FRM_FULL_SCRN);
    mmi_frm_scrn_enter(GRP_ID_A, SCR_ID_C, (FuncPtr)_scrn_exit_C, (FuncPtr)_scrn_enter_C, MMI_FRM_FULL_SCRN);
    mmi_frm_scrn_close(GRP_ID_A, SCR_ID_C);
    mmi_frm_group_close(GRP_ID_A);
    kal_prompt_trace(MOD_MMI, "[SG]test scrn id update in group PASS");
    return MMI_RET_OK;
}


/*************************************** 
 *  Screen Group Smart Close Test Case
 ***************************************/

typedef enum
{
	SCR_ID_SMC_A = 5000,
	SCR_ID_SMC_B,
	SCR_ID_SMC_S1,
    SCR_ID_SMC_S2,

	GRP_ID_SMC_G1,
	GRP_ID_SMC_G2,
	GRP_ID_SMC_G3,
	SMC_ID_END
} smc_test_id;

typedef enum
{
    SMC_CASE1,
    SMC_CASE2,
    SMC_CASE3,
    SMC_CASE4,
    SMC_CASE5,
    SMC_CASE6,
    SMC_CASE7,
    SMC_CASE8,
    SMC_CASE9,
    SMC_CASE10,
    SMC_CASE11,
    SMC_CASE12,
    SMC_CASE13,
    SMC_CASE14,
    SMC_CASE15,
    SMC_CASE16,
    SMC_CASE17,
    SMC_CASE18,
    SMC_CASE19,
    SMC_CASE20,
    SMC_CASE21,
    SMC_CASE22,
    SMC_CASE23,
    SMC_CASE24,
    SMC_CASE25,
    SMC_CASE26,
    SMC_CASE_END    
} smc_test_case_id;

typedef void (* smc_test_check)(void);

typedef struct
{
    smc_test_check    check;
} smc_test_cntx;

void smc_case1_check(void);
void smc_case2_check(void);
void smc_case3_check(void);
void smc_case4_check(void);
void smc_case5_check(void);
void smc_case6_check(void);
void smc_case7_check(void);
void smc_case8_check(void);
void smc_case9_check(void);
void smc_case10_check(void);
void smc_case11_check(void);
void smc_case12_check(void);
void smc_case13_check(void);
void smc_case14_check(void);
void smc_case15_check(void);
void smc_case16_check(void);
void smc_case17_check(void);
void smc_case18_check(void);
void smc_case19_check(void);
void smc_case20_check(void);
void smc_case21_check(void);
void smc_case22_check(void);
void smc_case23_check(void);
void smc_case24_check(void);
void smc_case25_check(void);
void smc_case26_check(void);
mmi_ret smc_test_case_check_proc(mmi_event_struct *evt);
smc_test_cntx smc_test_table[] =
{
    {smc_case1_check},
    {smc_case2_check},
    {smc_case3_check},
    {smc_case4_check},
    {smc_case5_check},
    {smc_case6_check},
    {smc_case7_check}, 
    {smc_case8_check},
    {smc_case9_check},
    {smc_case10_check},
    {smc_case11_check}, 
    {smc_case12_check},
    {smc_case13_check},
    {smc_case14_check},
    {smc_case15_check}, 
    {smc_case16_check},
    {smc_case17_check},
    {smc_case18_check},
    {smc_case19_check}, 
    {smc_case20_check},
    {smc_case21_check},
    {smc_case22_check},
    {smc_case23_check},
    {smc_case24_check},
    {smc_case25_check},
    {smc_case26_check},
};
MMI_BOOL group1_close_check;
MMI_BOOL group2_close_check; 
void smc_case_a_entry(void)
{
    EntryNewScreen(SCR_ID_SMC_A, NULL, smc_case_a_entry, NULL);
}
void smc_case_b_entry(void)
{
    EntryNewScreen(SCR_ID_SMC_B, NULL, smc_case_b_entry, NULL);
}
mmi_ret group_proc(mmi_event_struct *evt)
{
    mmi_scenario_evt_struct *s_evt = (mmi_scenario_evt_struct *)evt;
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            if (s_evt->targ_group == GRP_ID_SMC_G1)
                group1_close_check = MMI_TRUE;
            if (s_evt->targ_group == GRP_ID_SMC_G2)
                group2_close_check = MMI_TRUE;
            break;
    }
    return MMI_RET_OK;
}

/*
 * case 1
 * 
 *  [history stack + scenario tree]
 *  
 *  G1(g) -->   G1(smc) --> S1(not add history)
 *  A(s)
 *  IDLE(s)
 *
 *  [scenario change]
 *
 *  enter screen (root, B)
 *
 *  [expected result]
 *  
 *  B(s)
 *  A(s)
 *  IDLE(s)
 */

mmi_ret sg_smc_test_case_1(void *para)
{
    mmi_event_struct evt;
    
    mmi_frm_close_to_idle_group();
    group1_close_check = MMI_FALSE;
    kal_prompt_trace(MOD_MMI, "[SMC_UT] Case 1 Start");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] In idle screen");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen (root, A) - will add to history");
    EntryNewScreen(SCR_ID_SMC_A, NULL, smc_case_a_entry, NULL);
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SMC_G1, group_proc, NULL);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (root, G1) - support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G1, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen (G1, S1) - not add to history");
    mmi_frm_scrn_enter(GRP_ID_SMC_G1, SCR_ID_SMC_S1, NULL, NULL, MMI_FRM_FULL_SCRN);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen (root, B)");
    EntryNewScreen(SCR_ID_SMC_B, NULL, smc_case_b_entry, NULL);
    MMI_FRM_INIT_EVENT(&evt, SMC_CASE1);
    mmi_frm_post_event(&evt, smc_test_case_check_proc, NULL);
    return MMI_RET_OK;
}
void smc_case1_check()
{
    MMI_ASSERT(GetActiveScreenId() == SCR_ID_SMC_B);
    MMI_ASSERT(IsScreenPresent(GRP_ID_SMC_G1) == MMI_FALSE);
    MMI_ASSERT(GetCurrScrnId() == SCR_ID_SMC_A);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G1) == MMI_FALSE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SMC_G1, SCR_ID_SMC_S1, SCR_ID_SMC_S1) == MMI_FALSE);
    MMI_ASSERT(group1_close_check == MMI_TRUE);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] smart close test case 1 PASS!!");    
}

/*
 * case 2
 * 
 *  [history stack + scenario tree]
 *  
 *  G1(g) -->   G1 --> S1(not add history)
 *  A(s)
 *  IDLE(s)
 *
 *  [scenario change]
 *
 *  enter screen (root, B)
 *
 *  [expected result]
 *
 *  B(s)
 *  G1(g)  --> G1
 *  A(s)
 *  IDLE(s)
 */
mmi_ret sg_smc_test_case_2(void *para)
{
    mmi_event_struct evt;
    mmi_frm_close_to_idle_group();
    group1_close_check = MMI_FALSE;
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] Case 2 Start ");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] In idle screen");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen (root, A) - will add to history");
    EntryNewScreen(SCR_ID_SMC_A, NULL, smc_case_a_entry, NULL);
    
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SMC_G1, group_proc, NULL);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (root, G1) - don't support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G1, MMI_FRM_NODE_NONE_FLAG);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen  (G1, S1) - not add to history");
    mmi_frm_scrn_enter(GRP_ID_SMC_G1, SCR_ID_SMC_S1, NULL, NULL, MMI_FRM_FULL_SCRN);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen  (root, B) - will add to history");
    EntryNewScreen(SCR_ID_SMC_B, NULL, smc_case_b_entry, NULL);
    
    MMI_FRM_INIT_EVENT(&evt, SMC_CASE2);
    mmi_frm_post_event(&evt, smc_test_case_check_proc, NULL);
    return MMI_RET_OK;
}

void smc_case2_check()
{
    MMI_ASSERT(GetActiveScreenId() == SCR_ID_SMC_B);
    MMI_ASSERT(IsScreenPresent(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(GetCurrScrnId() == GRP_ID_SMC_G1);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SMC_G1, SCR_ID_SMC_S1, SCR_ID_SMC_S1) == MMI_FALSE);
    MMI_ASSERT(group1_close_check == MMI_FALSE);
    kal_prompt_trace(MOD_MMI, "[SG] smart close test case 2 PASS!!");    
}

/*
 * case 3
 * 
 *  [history stack + scenario tree]
 *  
 *  G1(g) -->   G1 --> G2(smc)->S1(not add to history)
 *  A(s)
 *  IDLE(s)
 *
 *  [scenario change]
 *
 *  enter screen (root, B)
 *
 *  [expected result]
 *
 *  B(s)
 *  G1(g)   --> G1
 *  A(s)
 *  ILDE(s)
 */
mmi_ret sg_smc_test_case_3(void *para)
{
    mmi_event_struct evt;
    
    mmi_frm_close_to_idle_group();
    group1_close_check = MMI_FALSE;
    group2_close_check = MMI_FALSE;
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] Case 3 start");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] In idle screen");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen (root, A) - will add to history");    
    EntryNewScreen(SCR_ID_SMC_A, NULL, smc_case_a_entry, NULL);
    
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SMC_G1, group_proc, NULL);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (root, G1) - don't support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G1, MMI_FRM_NODE_NONE_FLAG);
    
    mmi_frm_group_create(GRP_ID_SMC_G1, GRP_ID_SMC_G2, group_proc, NULL);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (G1, G2) - support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G2, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen  (G2, S1) - not add to history");
    mmi_frm_scrn_enter(GRP_ID_SMC_G2, SCR_ID_SMC_S1, NULL, NULL, MMI_FRM_FULL_SCRN);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen  (root, B) - will add to history");
    EntryNewScreen(SCR_ID_SMC_B, NULL, smc_case_b_entry, NULL);
    MMI_FRM_INIT_EVENT(&evt, SMC_CASE3);
    mmi_frm_post_event(&evt, smc_test_case_check_proc, NULL);    

    
    return MMI_RET_OK;
}

void smc_case3_check()
{
    MMI_ASSERT(GetActiveScreenId() == SCR_ID_SMC_B);
    MMI_ASSERT(IsScreenPresent(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(GetCurrScrnId() == GRP_ID_SMC_G1);
    MMI_ASSERT(group1_close_check == MMI_FALSE);
    MMI_ASSERT(group2_close_check == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G2) == MMI_FALSE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SMC_G2, SCR_ID_SMC_S1, MMI_FRM_NODE_ALL_FLAG) == MMI_FALSE);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] smart close test case 3 PASS!!");    
}


/*
 * case 4
 * 
 *  [history stack + scenario tree]
 *  
 *  G1(g) -->   G1 --> G2 ->S1(not add to history)
 *  A(s)
 *  IDLE(s)
 *
 *  [scenario change]
 *
 *  enter screen (root, B)
 *
 *  [expected result]
 *  
 *  B(s)
 *  G1(g)  --> G1 -- >G2
 *  A(s)
 *  IDLE(s)
 */
 
mmi_ret sg_smc_test_case_4(void *para)
{
    mmi_event_struct evt;
    
    mmi_frm_close_to_idle_group();
    group1_close_check = MMI_FALSE;
    group2_close_check = MMI_FALSE;
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] Case 4 Start");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] In idle screen");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen (root, A) - will add to history");    
    EntryNewScreen(SCR_ID_SMC_A, NULL, smc_case_a_entry, NULL);
    
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SMC_G1, group_proc, NULL);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (root, G1) - don't support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G1, MMI_FRM_NODE_NONE_FLAG);
    
    mmi_frm_group_create(GRP_ID_SMC_G1, GRP_ID_SMC_G2, group_proc, NULL);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (G1, G2) - don't support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G2, MMI_FRM_NODE_NONE_FLAG);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen  (G2, S1) - not add to history");
    mmi_frm_scrn_enter(GRP_ID_SMC_G2, SCR_ID_SMC_S1, NULL, NULL, MMI_FRM_FULL_SCRN);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen  (root, B) - will add to history");
    EntryNewScreen(SCR_ID_SMC_B, NULL, smc_case_b_entry, NULL);
    MMI_FRM_INIT_EVENT(&evt, SMC_CASE4);
    mmi_frm_post_event(&evt, smc_test_case_check_proc, NULL);    

    
    return MMI_RET_OK;
}

void smc_case4_check()
{
    MMI_ASSERT(GetActiveScreenId() == SCR_ID_SMC_B);
    MMI_ASSERT(IsScreenPresent(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(GetCurrScrnId() == GRP_ID_SMC_G1);
    MMI_ASSERT(group1_close_check == MMI_FALSE);
    MMI_ASSERT(group2_close_check == MMI_FALSE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G2) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SMC_G2, SCR_ID_SMC_S1, MMI_FRM_NODE_ALL_FLAG) == MMI_FALSE);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] smart close test case 4 PASS!!");    
}

/*
 * case 5
 * 
 *  [history stack + scenario tree.
 *  
 *  G1(g) -->   G1(smc) --> G2(smc) ->S1(not add to history)
 *  A(s)
 *  IDLE
 *
 *  scenario change
 *  enter group (root, G3)
 *
 *  [Expected result]
 *
 *  G3(g)
 *  A(s)
 *  IDLE
 */

mmi_ret sg_smc_test_case_5(void *para)
{
    mmi_event_struct evt;
    mmi_frm_close_to_idle_group();
    group1_close_check = MMI_FALSE;
    group2_close_check = MMI_FALSE;
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] Case 5 start");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] In idle screen");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen (root, A) - will add to history");    
    EntryNewScreen(SCR_ID_SMC_A, NULL, smc_case_a_entry, NULL);
    
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SMC_G1, group_proc, NULL);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (root, G1) - support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G1, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    mmi_frm_group_create(GRP_ID_SMC_G1, GRP_ID_SMC_G2, group_proc, NULL);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (G1, G2) - support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G2, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen  (G2, S1) - not add to history");
    mmi_frm_scrn_enter(GRP_ID_SMC_G2, SCR_ID_SMC_S1, NULL, NULL, MMI_FRM_FULL_SCRN);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (root, G3) ");
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SMC_G3, group_proc, NULL);
    mmi_frm_group_enter(GRP_ID_SMC_G3, MMI_FRM_NODE_NONE_FLAG);
    MMI_FRM_INIT_EVENT(&evt, SMC_CASE5);
    mmi_frm_post_event(&evt, smc_test_case_check_proc, NULL);      
    return MMI_RET_OK;
}
void smc_case5_check()
{
    MMI_ASSERT(IsScreenPresent(GRP_ID_SMC_G1) == MMI_FALSE);
    MMI_ASSERT(GetCurrScrnId() == SCR_ID_SMC_A);
    MMI_ASSERT(is_top_history_node(GRP_ID_SMC_G3) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G1) == MMI_FALSE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G2) == MMI_FALSE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G3) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SMC_G2, SCR_ID_SMC_S1, MMI_FRM_NODE_ALL_FLAG) == MMI_FALSE);
    MMI_ASSERT(group1_close_check == MMI_TRUE);
    MMI_ASSERT(group2_close_check == MMI_TRUE);
    kal_prompt_trace(MOD_MMI, "[SG] smart close test case 5 PASS!!");       
}

/*
 * case 6
 * 
 *  [history stack + scenario tree]
 *  
 *  G1(g) -->   G1 --> G2(smc) ->S1(not add to history)
 *  A(s)
 *  IDLE
 *
 *  scenario change
 *  enter group (root, G3)
 *
 *  [Expected result]
 *
 *  G3(g)
 *  G1(g)   --> G1
 *  IDLE
 */

mmi_ret sg_smc_test_case6(void *para)
{
    mmi_event_struct evt;
    mmi_frm_close_to_idle_group();
    group1_close_check = MMI_FALSE;
    group2_close_check = MMI_FALSE;
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] Case 6 Start");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] In idle screen");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen (root, A) - will add to history");    
    EntryNewScreen(SCR_ID_SMC_A, NULL, smc_case_a_entry, NULL);
    
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SMC_G1, group_proc, NULL);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (root, G1) - don't support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G1, MMI_FRM_NODE_NONE_FLAG);
    
    mmi_frm_group_create(GRP_ID_SMC_G1, GRP_ID_SMC_G2, group_proc, NULL);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (G1, G2) - support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G2, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen  (G2, S1) - not add to history");
    mmi_frm_scrn_enter(GRP_ID_SMC_G2, SCR_ID_SMC_S1, NULL, NULL, MMI_FRM_FULL_SCRN);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (root, G3) - will add to history");
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SMC_G3, group_proc, NULL);
    mmi_frm_group_enter(GRP_ID_SMC_G3, MMI_FRM_NODE_NONE_FLAG);
    MMI_FRM_INIT_EVENT(&evt, SMC_CASE6);
    mmi_frm_post_event(&evt, smc_test_case_check_proc, NULL);      
    return MMI_RET_OK;
}
void smc_case6_check()
{
    MMI_ASSERT(IsScreenPresent(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(GetCurrScrnId() == GRP_ID_SMC_G1);
    MMI_ASSERT(is_top_history_node(GRP_ID_SMC_G3) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G2) == MMI_FALSE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G3) == MMI_TRUE);
    MMI_ASSERT(group1_close_check == MMI_FALSE);
    MMI_ASSERT(group2_close_check == MMI_TRUE);
    kal_prompt_trace(MOD_MMI, "[SG] smart close test case 6 PASS!!");       
}


/*
 * case 7
 * 
 *  [history stack + scenario tree]
 *  
 *  G1(g) -->   G1 --> G2 ->S1(not add to history)
 *  A(s)
 *  IDLE
 *
 *  [scenario change]
 *
 *  enter group (root, G3)
 *  
 *  G3(g)
 *  G1(g) -->  G1 --> G2
 *  A(s)
 *  IDLE
 */

mmi_ret sg_smc_test_case7(void *para)
{
    mmi_event_struct evt;
    mmi_frm_close_to_idle_group();
    group1_close_check = MMI_FALSE;
    group2_close_check = MMI_FALSE;
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] Case 7 start ");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] In idle screen");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen (root, A) - will add to history");    
    EntryNewScreen(SCR_ID_SMC_A, NULL, smc_case_a_entry, NULL);
    
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SMC_G1, group_proc, NULL);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (root, G1) - don't support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G1, MMI_FRM_NODE_NONE_FLAG);
    
    mmi_frm_group_create(GRP_ID_SMC_G1, GRP_ID_SMC_G2, group_proc, NULL);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (G1, G2) - don't support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G2, MMI_FRM_NODE_NONE_FLAG);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen  (G2, S1) - not add to history");
    mmi_frm_scrn_enter(GRP_ID_SMC_G2, SCR_ID_SMC_S1, NULL, NULL, MMI_FRM_FULL_SCRN);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (root, G3)");
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SMC_G3, group_proc, NULL);
    mmi_frm_group_enter(GRP_ID_SMC_G3, MMI_FRM_NODE_NONE_FLAG);
    MMI_FRM_INIT_EVENT(&evt, SMC_CASE7);
    mmi_frm_post_event(&evt, smc_test_case_check_proc, NULL);      
    return MMI_RET_OK;
}
void smc_case7_check()
{
    MMI_ASSERT(IsScreenPresent(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(GetCurrScrnId() == GRP_ID_SMC_G1);
    MMI_ASSERT(is_top_history_node(GRP_ID_SMC_G3) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G2) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G3) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SMC_G2, SCR_ID_SMC_S1, SCR_ID_SMC_S1) == MMI_FALSE);
    MMI_ASSERT(group1_close_check == MMI_FALSE);
    MMI_ASSERT(group2_close_check == MMI_FALSE);
    kal_prompt_trace(MOD_MMI, "[SG] smart close test case 7 PASS!!");       
}

/*
 * case 8
 * 
 *  [history stack + scenario tree]
 *  
 *  G1(g) -->   G1 --> G2(smc) ->S1(not add to history)
 *  A(s)
 *  IDLE
 *
 *  scenario change
 *
 *  enter group (G1, G3)
 *
 *  [expect result]
 *
 *  G1(g)  --> G1 ---> G3
 *  A(s)
 *  ILDE
 */

mmi_ret sg_smc_test_case_8(void *para)
{
    mmi_event_struct evt;
    mmi_frm_close_to_idle_group();
    group1_close_check = MMI_FALSE;
    group2_close_check = MMI_FALSE;
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] Case 8 Start");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] In idle screen");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen (root, A) - will add to history");    
    EntryNewScreen(SCR_ID_SMC_A, NULL, smc_case_a_entry, NULL);
    
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SMC_G1, group_proc, NULL);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (root, G1) - don't support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G1, MMI_FRM_NODE_NONE_FLAG);
    
    mmi_frm_group_create(GRP_ID_SMC_G1, GRP_ID_SMC_G2, group_proc, NULL);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (G1, G2) - support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G2, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen  (G2, S1) - not add to history");
    mmi_frm_scrn_enter(GRP_ID_SMC_G2, SCR_ID_SMC_S1, NULL, NULL, MMI_FRM_FULL_SCRN);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (G1, G3)");
    mmi_frm_group_create(GRP_ID_SMC_G1, GRP_ID_SMC_G3, group_proc, NULL);
    mmi_frm_group_enter(GRP_ID_SMC_G3, MMI_FRM_NODE_NONE_FLAG);
    MMI_FRM_INIT_EVENT(&evt, SMC_CASE8);
    mmi_frm_post_event(&evt, smc_test_case_check_proc, NULL);      
    return MMI_RET_OK;
}
void smc_case8_check()
{
    MMI_ASSERT(IsScreenPresent(GRP_ID_SMC_G1) == MMI_FALSE);
    MMI_ASSERT(GetCurrScrnId() == SCR_ID_SMC_A);
    MMI_ASSERT(is_top_history_node(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G2) == MMI_FALSE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G3) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SMC_G2, SCR_ID_SMC_S1, MMI_FRM_NODE_ALL_FLAG) == MMI_FALSE);
    MMI_ASSERT(group1_close_check == MMI_FALSE);
    MMI_ASSERT(group2_close_check == MMI_TRUE);
    kal_prompt_trace(MOD_MMI, "[SG] smart close test case 8 PASS!!");       
}


/*
 * case 9
 * 
 *  [history stack + scenario tree]
 *  
 *  G1(g) -->   G1 --> G2 ->S1(not add to history)
 *  A(s)
 *  IDLE
 *
 *  [scenario change]
 *
 *  enter group (G1, G3)
 *
 *  [Expected result]
 *                    G3
 *  G1(g) -->  G1 --> G2
 *  A(s)
 *  IDLE
 */

mmi_ret sg_smc_test_case_9(void *para)
{
    mmi_event_struct evt;
    mmi_frm_close_to_idle_group();
    group1_close_check = MMI_FALSE;
    group2_close_check = MMI_FALSE;
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] Case 9 Start");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] In idle screen");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen (root, A) - will add to history");    
    EntryNewScreen(SCR_ID_SMC_A, NULL, smc_case_a_entry, NULL);
    
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SMC_G1, group_proc, NULL);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (root, G1) - don't support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G1, MMI_FRM_NODE_NONE_FLAG);
    
    mmi_frm_group_create(GRP_ID_SMC_G1, GRP_ID_SMC_G2, group_proc, NULL);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (G1, G2) - don't support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G2, MMI_FRM_NODE_NONE_FLAG);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen  (G2, S1) - not add to history");
    mmi_frm_scrn_enter(GRP_ID_SMC_G2, SCR_ID_SMC_S1, NULL, NULL, MMI_FRM_FULL_SCRN);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (G1, G3) ");
    mmi_frm_group_create(GRP_ID_SMC_G1, GRP_ID_SMC_G3, group_proc, NULL);
    mmi_frm_group_enter(GRP_ID_SMC_G3, MMI_FRM_NODE_NONE_FLAG);
    MMI_FRM_INIT_EVENT(&evt, SMC_CASE9);
    mmi_frm_post_event(&evt, smc_test_case_check_proc, NULL);      
    return MMI_RET_OK;
}
void smc_case9_check()
{
    MMI_ASSERT(IsScreenPresent(GRP_ID_SMC_G1) == MMI_FALSE);
    MMI_ASSERT(GetCurrScrnId() == SCR_ID_SMC_A);
    MMI_ASSERT(is_top_history_node(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G2) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G3) == MMI_TRUE);
    MMI_ASSERT(group1_close_check == MMI_FALSE);
    MMI_ASSERT(group2_close_check == MMI_FALSE);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] smart close test case 9 PASS!!");       
}


/*
 * case 10
 * 
 *  [history stack + scenario tree]
 *  
 *  G1(g) -->   G1 --> G2(smc) ->S1(not add to history)
 *  A(s)
 *  IDLE
 *
 *  [scenario change]
 *
 *  enter screen (G1, S2)
 *
 *  [Expected result]
 *  
 *  G1 (g) -- >G1 --> S2
 *  A(s)
 *  IDLE
 *
 */

mmi_ret sg_smc_test_case_10(void *para)
{
    mmi_event_struct evt;
    mmi_frm_close_to_idle_group();
    group1_close_check = MMI_FALSE;
    group2_close_check = MMI_FALSE;
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] Case 10 Start");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] In idle screen");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen (root, A) - will add to history");    
    EntryNewScreen(SCR_ID_SMC_A, NULL, smc_case_a_entry, NULL);
    
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SMC_G1, group_proc, NULL);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (root, G1) - don't support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G1, MMI_FRM_NODE_NONE_FLAG);
    
    mmi_frm_group_create(GRP_ID_SMC_G1, GRP_ID_SMC_G2, group_proc, NULL);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (G1, G2) - support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G2, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen  (G2, S1) - not add to history");
    mmi_frm_scrn_enter(GRP_ID_SMC_G2, SCR_ID_SMC_S1, NULL, NULL, MMI_FRM_FULL_SCRN);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen  (G1, S2)");
    mmi_frm_scrn_enter(GRP_ID_SMC_G1, SCR_ID_SMC_S2, NULL, NULL, MMI_FRM_FULL_SCRN);
    MMI_FRM_INIT_EVENT(&evt, SMC_CASE10);
    mmi_frm_post_event(&evt, smc_test_case_check_proc, NULL);      
    return MMI_RET_OK;
}
void smc_case10_check()
{
    MMI_ASSERT(IsScreenPresent(GRP_ID_SMC_G1) == MMI_FALSE);
    MMI_ASSERT(GetCurrScrnId() == SCR_ID_SMC_A);
    MMI_ASSERT(is_top_history_node(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G2) == MMI_FALSE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SMC_G1, SCR_ID_SMC_S2, MMI_FRM_NODE_ALL_FLAG) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SMC_G1, SCR_ID_SMC_S1, MMI_FRM_NODE_ALL_FLAG) == MMI_FALSE);
    MMI_ASSERT(group1_close_check == MMI_FALSE);
    MMI_ASSERT(group2_close_check == MMI_TRUE);;
    kal_prompt_trace(MOD_MMI, "[SMC_UT] smart close test case 10 PASS!!");       
}

/*
 * case 11
 * 
 *  [history stack + scenario tree]
 *  
 *  G1(g) -->   G1 --> G2 ->S1(not add to history)
 *  A(s)
 *  IDLE
 *
 *  scenario change
 *  enter screen (G1, S2)
 *
 *  [expected result]
 *
 *                   S2
 *  G1(g)  --> G1 -- G2
 *  A(s)
 *  ILDE
 */

mmi_ret sg_smc_test_case_11(void *para)
{
    mmi_event_struct evt;
    mmi_frm_close_to_idle_group();
    group1_close_check = MMI_FALSE;
    group2_close_check = MMI_FALSE;
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] Case 11 Start");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] In idle screen");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen (root, A) - will add to history");    
    EntryNewScreen(SCR_ID_SMC_A, NULL, smc_case_a_entry, NULL);
    
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SMC_G1, group_proc, NULL);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (root, G1) - don't support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G1, MMI_FRM_NODE_NONE_FLAG);
    
    mmi_frm_group_create(GRP_ID_SMC_G1, GRP_ID_SMC_G2, group_proc, NULL);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (G1, G2) - don't support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G2, MMI_FRM_NODE_NONE_FLAG);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen  (G2, S1) - not add to history");
    mmi_frm_scrn_enter(GRP_ID_SMC_G2, SCR_ID_SMC_S1, NULL, NULL, MMI_FRM_FULL_SCRN);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen  (G1, S2)");
    mmi_frm_scrn_enter(GRP_ID_SMC_G1, SCR_ID_SMC_S2, NULL, NULL, MMI_FRM_FULL_SCRN);
    MMI_FRM_INIT_EVENT(&evt, SMC_CASE11);
    mmi_frm_post_event(&evt, smc_test_case_check_proc, NULL);      
    return MMI_RET_OK;
}
void smc_case11_check()
{
    MMI_ASSERT(IsScreenPresent(GRP_ID_SMC_G1) == MMI_FALSE);
    MMI_ASSERT(GetCurrScrnId() == SCR_ID_SMC_A);
    MMI_ASSERT(is_top_history_node(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G2) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SMC_G2, SCR_ID_SMC_S1, MMI_FRM_NODE_ALL_FLAG) == MMI_FALSE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SMC_G1, SCR_ID_SMC_S2, MMI_FRM_NODE_ALL_FLAG) == MMI_TRUE);
    MMI_ASSERT(group1_close_check == MMI_FALSE);
    MMI_ASSERT(group2_close_check == MMI_FALSE);;
    kal_prompt_trace(MOD_MMI, "[SMC_UT] smart close test case 11 PASS!!");       
}


/*
 * case 12
 * 
 *  [history stack + scenario tree]
 *  
 *  G1(g) -->   G1(smc) --> G2(smc) ->S1
 *  A(s)
 *  IDLE
 *  
 *  [scenario change]
 *  close screen (G2, S1)
 *
 *  [Expect result]
 *
 *  A(s)
 *  IDLE
 */

mmi_ret sg_smc_test_case_12(void *para)
{
    mmi_event_struct evt;
    mmi_frm_close_to_idle_group();
    group1_close_check = MMI_FALSE;
    group2_close_check = MMI_FALSE;
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] Case 12 Start");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] In idle screen");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen (root, A) - will add to history");    
    EntryNewScreen(SCR_ID_SMC_A, NULL, smc_case_a_entry, NULL);
    
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SMC_G1, group_proc, NULL);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (root, G1) - support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G1, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    mmi_frm_group_create(GRP_ID_SMC_G1, GRP_ID_SMC_G2, group_proc, NULL);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (G1, G2) - support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G2, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen  (G2, S1) - add to history");
    mmi_frm_scrn_enter(GRP_ID_SMC_G2, SCR_ID_SMC_S1, NULL, smc_case_a_entry, MMI_FRM_FULL_SCRN);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] close screen  (G1, S1)");
    mmi_frm_scrn_close(GRP_ID_SMC_G2, SCR_ID_SMC_S1);
    MMI_FRM_INIT_EVENT(&evt, SMC_CASE12);
    mmi_frm_post_event(&evt, smc_test_case_check_proc, NULL);      
    return MMI_RET_OK;
}
void smc_case12_check()
{
    MMI_ASSERT(GetActiveScreenId() == SCR_ID_SMC_A);
    MMI_ASSERT(IsScreenPresent(GRP_ID_SMC_G1) == MMI_FALSE);
    MMI_ASSERT(is_top_history_node(SCR_ID_SMC_A) == MMI_TRUE);
    MMI_ASSERT(is_top_history_node(GRP_ID_SMC_G1) == MMI_FALSE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G1) == MMI_FALSE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G2) == MMI_FALSE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SMC_G2, SCR_ID_SMC_S1, MMI_FRM_NODE_ALL_FLAG) == MMI_FALSE);
    MMI_ASSERT(group1_close_check == MMI_TRUE);
    MMI_ASSERT(group2_close_check == MMI_TRUE);;
    kal_prompt_trace(MOD_MMI, "[SMC_UT] smart close test case 12 PASS!!");       
}

/*
 * case 13
 * 
 *  [history stack + scenario tree]
 *
 *  B(s)
 *  G1(g) -->   G1(smc) --> G2(smc) ->S1 (add to history)
 *  A(s)
 *  ILDE
 *  
 *  [scenario change]
 *  close screen (G2, S1)
 *
 *  [Expected result]
 *  
 *  B(s)
 *  A(s)
 *  IDLE
 */

mmi_ret sg_smc_test_case_13(void *para)
{
    mmi_event_struct evt;
    mmi_frm_close_to_idle_group();
    group1_close_check = MMI_FALSE;
    group2_close_check = MMI_FALSE;
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] Case 13 Start");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] In idle screen");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen (root, A) - will add to history");    
    EntryNewScreen(SCR_ID_SMC_A, NULL, smc_case_a_entry, NULL);
    
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SMC_G1, group_proc, NULL);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (root, G1) - support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G1, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    mmi_frm_group_create(GRP_ID_SMC_G1, GRP_ID_SMC_G2, group_proc, NULL);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (G1, G2) - support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G2, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen  (G2, S1) - add to history");
    mmi_frm_scrn_enter(GRP_ID_SMC_G2, SCR_ID_SMC_S1, NULL, smc_case_a_entry, MMI_FRM_FULL_SCRN);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen  (root, B) - add to history");
    EntryNewScreen(SCR_ID_SMC_B, NULL, smc_case_b_entry, NULL);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] close screen  (G1, S1)");
    mmi_frm_scrn_close(GRP_ID_SMC_G2, SCR_ID_SMC_S1);
    MMI_FRM_INIT_EVENT(&evt, SMC_CASE13);
    mmi_frm_post_event(&evt, smc_test_case_check_proc, NULL);      
    return MMI_RET_OK;
}
void smc_case13_check()
{
    MMI_ASSERT(GetActiveScreenId() == SCR_ID_SMC_B);
    MMI_ASSERT(IsScreenPresent(GRP_ID_SMC_G1) == MMI_FALSE);
    MMI_ASSERT(GetCurrScrnId() == SCR_ID_SMC_A);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G1) == MMI_FALSE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G2) == MMI_FALSE);
    MMI_ASSERT(group1_close_check == MMI_TRUE);
    MMI_ASSERT(group2_close_check == MMI_TRUE);;
    kal_prompt_trace(MOD_MMI, "[SMC_UT] smart close test case 13 PASS!!");       
}


/*
 * case 14
 * 
 *  [history stack + scenario tree]
 *  
 *  G1(g) -->   G1 --> G2(smc) ->S1 (add to history)
 *  A(s)
 *  IDLE
 *  
 *  [scenario change]
 *
 *  close screen (G2, S1)
 *
 *  [Expected result]
 *
 *  G1(g) -->  G1
 *  A(s)
 *  IDLE
 */

mmi_ret sg_smc_test_case_14(void *para)
{
    mmi_event_struct evt;
    mmi_frm_close_to_idle_group();
    group1_close_check = MMI_FALSE;
    group2_close_check = MMI_FALSE;

    kal_prompt_trace(MOD_MMI, "[SMC_UT] Case 14 Start");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] In idle screen");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen (root, A) - will add to history");    
    EntryNewScreen(SCR_ID_SMC_A, NULL, smc_case_a_entry, NULL);
    
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SMC_G1, group_proc, NULL);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (root, G1) - support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G1, MMI_FRM_NODE_NONE_FLAG);
    
    mmi_frm_group_create(GRP_ID_SMC_G1, GRP_ID_SMC_G2, group_proc, NULL);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (G1, G2) - support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G2, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen  (G2, S1) - add to history");
    mmi_frm_scrn_enter(GRP_ID_SMC_G2, SCR_ID_SMC_S1, NULL, smc_case_a_entry, MMI_FRM_FULL_SCRN);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] close screen  (G1, S1)");
    mmi_frm_scrn_close(GRP_ID_SMC_G2, SCR_ID_SMC_S1);
    MMI_FRM_INIT_EVENT(&evt, SMC_CASE14);
    mmi_frm_post_event(&evt, smc_test_case_check_proc, NULL);      
    return MMI_RET_OK;
}
void smc_case14_check()
{

    MMI_ASSERT(IsScreenPresent(GRP_ID_SMC_G1) == MMI_FALSE);
    MMI_ASSERT(is_top_history_node(SCR_ID_SMC_A) == MMI_FALSE);
    MMI_ASSERT(is_top_history_node(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(GetCurrScrnId() == SCR_ID_SMC_A);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G2) == MMI_FALSE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SMC_G2, SCR_ID_SMC_S1, MMI_FRM_NODE_ALL_FLAG) == MMI_FALSE);
    MMI_ASSERT(group1_close_check == MMI_FALSE);
    MMI_ASSERT(group2_close_check == MMI_TRUE);;
    kal_prompt_trace(MOD_MMI, "[SMC_UT] smart close test case 14 PASS!!");       
}

/*
 * case 15
 * 
 *  [history stack + scenario tree]
 *  B(s)
 *  G1(g) -->   G1 --> G2(smc) ->S1 (add to history)
 *  A(s)
 *  IDLE
 *  
 *  [scenario change]
 *  close screen (G2, S1)
 *
 *  B(s)
 *  G1(g)  --> G1
 *  A(s)
 *  IDLE
 */

mmi_ret sg_smc_test_case_15(void *para)
{
    mmi_event_struct evt;
    mmi_frm_close_to_idle_group();
    group1_close_check = MMI_FALSE;
    group2_close_check = MMI_FALSE;
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] Case 15 Start");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] In idle screen");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen (root, A) - will add to history");    
    EntryNewScreen(SCR_ID_SMC_A, NULL, smc_case_a_entry, NULL);
    
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SMC_G1, group_proc, NULL);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (root, G1) - support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G1, MMI_FRM_NODE_NONE_FLAG);
    
    mmi_frm_group_create(GRP_ID_SMC_G1, GRP_ID_SMC_G2, group_proc, NULL);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (G1, G2) - support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G2, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen  (G2, S1) - add to history");
    mmi_frm_scrn_enter(GRP_ID_SMC_G2, SCR_ID_SMC_S1, NULL, smc_case_a_entry, MMI_FRM_FULL_SCRN);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen (root, B) - will add to history");  
    EntryNewScreen(SCR_ID_SMC_B, NULL, smc_case_b_entry, NULL);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] close screen  (G1, S1)");
    mmi_frm_scrn_close(GRP_ID_SMC_G2, SCR_ID_SMC_S1);
    MMI_FRM_INIT_EVENT(&evt, SMC_CASE15);
    mmi_frm_post_event(&evt, smc_test_case_check_proc, NULL);      
    return MMI_RET_OK;
}
void smc_case15_check()
{
    MMI_ASSERT(GetActiveScreenId() == SCR_ID_SMC_B);
    MMI_ASSERT(IsScreenPresent(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(GetCurrScrnId() == GRP_ID_SMC_G1);
    MMI_ASSERT(is_top_history_node(SCR_ID_SMC_A) == MMI_FALSE);
    MMI_ASSERT(is_top_history_node(GRP_ID_SMC_G1) == MMI_FALSE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G2) == MMI_FALSE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SMC_G2, SCR_ID_SMC_S1, MMI_FRM_NODE_ALL_FLAG) == MMI_FALSE);
    MMI_ASSERT(group1_close_check == MMI_FALSE);
    MMI_ASSERT(group2_close_check == MMI_TRUE);;
    kal_prompt_trace(MOD_MMI, "[SMC_UT] smart close test case 15 PASS!!");       
}

/*
 * case 16
 * 
 *  [history stack + scenario tree]
 * 
 *  G1(g) -->   G1 --> G2 ->S1 (add to history)
 *  A(s)
 *  IDLE
 *  
 *  [scenario change]
 *  close screen (G2, S1)
 *
 *  G1(g)  -->  G1 --> G1
 *  A(s)
 *  ILDE
 */

mmi_ret sg_smc_test_case_16(void *para)
{
    mmi_event_struct evt;
    mmi_frm_close_to_idle_group();
    group1_close_check = MMI_FALSE;
    group2_close_check = MMI_FALSE;
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] Case 16 Start");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] In idle screen");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen (root, A) - will add to history");    
    EntryNewScreen(SCR_ID_SMC_A, NULL, smc_case_a_entry, NULL);
    
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SMC_G1, group_proc, NULL);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (root, G1) - don't support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G1, MMI_FRM_NODE_NONE_FLAG);
    
    mmi_frm_group_create(GRP_ID_SMC_G1, GRP_ID_SMC_G2, group_proc, NULL);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (G1, G2) - don't support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G2, MMI_FRM_NODE_NONE_FLAG);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen  (G2, S1) - add to history");
    mmi_frm_scrn_enter(GRP_ID_SMC_G2, SCR_ID_SMC_S1, NULL, smc_case_a_entry, MMI_FRM_FULL_SCRN);
    

    kal_prompt_trace(MOD_MMI, "[SMC_UT] close screen  (G1, S1)");
    mmi_frm_scrn_close(GRP_ID_SMC_G2, SCR_ID_SMC_S1);
    MMI_FRM_INIT_EVENT(&evt, SMC_CASE16);
    mmi_frm_post_event(&evt, smc_test_case_check_proc, NULL);      
    return MMI_RET_OK;
}
void smc_case16_check()
{
    MMI_ASSERT(IsScreenPresent(GRP_ID_SMC_G1) == MMI_FALSE);
    MMI_ASSERT(GetCurrScrnId() == SCR_ID_SMC_A);
    MMI_ASSERT(is_top_history_node(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G2) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SMC_G2, SCR_ID_SMC_S1, MMI_FRM_NODE_ALL_FLAG) == MMI_FALSE);
    MMI_ASSERT(group1_close_check == MMI_FALSE);
    MMI_ASSERT(group2_close_check == MMI_FALSE);;
    kal_prompt_trace(MOD_MMI, "[SMC_UT] smart close test case 16 PASS!!");       
}


/*
 * case 17
 * 
 *  [history stack + scenario tree]
 *  
 *  B(s)
 *  G1(g) -->   G1 --> G2 ->S1 (add to history)
 *  A(s)
 *  IDLE
 *  
 *  [scenario change]
 *
 *  close screen (G2, S1)
 *
 *  [Expected result]
 *
 *  B(s)
 *  G1(g) -->  G1  --> G2
 *  A(s)
 *  IDLE
 */

mmi_ret sg_smc_test_case_17(void *para)
{
    mmi_event_struct evt;
    mmi_frm_close_to_idle_group();
    group1_close_check = MMI_FALSE;
    group2_close_check = MMI_FALSE;
    kal_prompt_trace(MOD_MMI, "[SMC_UT] Case 17 Start");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] In idle screen");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen (root, A) - will add to history");    
    EntryNewScreen(SCR_ID_SMC_A, NULL, smc_case_a_entry, NULL);
    
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SMC_G1, group_proc, NULL);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (root, G1) - don't support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G1, MMI_FRM_NODE_NONE_FLAG);
    
    mmi_frm_group_create(GRP_ID_SMC_G1, GRP_ID_SMC_G2, group_proc, NULL);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (G1, G2) - don't support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G2, MMI_FRM_NODE_NONE_FLAG);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen  (G2, S1) - add to history");
    mmi_frm_scrn_enter(GRP_ID_SMC_G2, SCR_ID_SMC_S1, NULL, smc_case_a_entry, MMI_FRM_FULL_SCRN);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen (root, B) - will add to history");  
    EntryNewScreen(SCR_ID_SMC_B, NULL, smc_case_b_entry, NULL);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] close screen  (G1, S1)");
    mmi_frm_scrn_close(GRP_ID_SMC_G2, SCR_ID_SMC_S1);
    MMI_FRM_INIT_EVENT(&evt, SMC_CASE17);
    mmi_frm_post_event(&evt, smc_test_case_check_proc, NULL);      
    return MMI_RET_OK;
}
void smc_case17_check()
{
    MMI_ASSERT(GetActiveScreenId() == SCR_ID_SMC_B);
    MMI_ASSERT(IsScreenPresent(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(is_top_history_node(SCR_ID_SMC_A) == MMI_FALSE);
    MMI_ASSERT(is_top_history_node(GRP_ID_SMC_G1) == MMI_FALSE);
    MMI_ASSERT(GetCurrScrnId() == GRP_ID_SMC_G1);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G2) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SMC_G2, SCR_ID_SMC_S1, MMI_FRM_NODE_ALL_FLAG) == MMI_FALSE);
    MMI_ASSERT(group1_close_check == MMI_FALSE);
    MMI_ASSERT(group2_close_check == MMI_FALSE);;
    kal_prompt_trace(MOD_MMI, "[SMC_UT] smart close test case 17 PASS!!");       
}


/*
 * case 18
 * 
 *  [history stack + scenario tree]
 *  
 *
 *  G1(g) -->   G1 --> G2(s) ->G3
 *  A(s)
 *  IDLE
 *  
 *  [scenario change]
 *  close group (G2, G3)
 *
 *  [Expected result]
 *
 *  G1(g)  --> G1
 *  A(s)
 *  IDLE
 */

mmi_ret sg_smc_test_case_18(void *para)
{
    mmi_event_struct evt;
    mmi_frm_close_to_idle_group();
    group1_close_check = MMI_FALSE;
    group2_close_check = MMI_FALSE;
    kal_prompt_trace(MOD_MMI, "[SMC_UT] Case 18 start");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] In idle screen");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen (root, A) - will add to history");    
    EntryNewScreen(SCR_ID_SMC_A, NULL, smc_case_a_entry, NULL);
    
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SMC_G1, group_proc, NULL);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (root, G1) - don't support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G1, MMI_FRM_NODE_NONE_FLAG);
    
    mmi_frm_group_create(GRP_ID_SMC_G1, GRP_ID_SMC_G2, group_proc, NULL);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (G1, G2) - support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G2, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    mmi_frm_group_create(GRP_ID_SMC_G2, GRP_ID_SMC_G3, group_proc, NULL);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (G2, G3)");
    mmi_frm_group_enter(GRP_ID_SMC_G3, MMI_FRM_NODE_NONE_FLAG);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] close group  (G3)");
    mmi_frm_group_close(GRP_ID_SMC_G3);
    MMI_FRM_INIT_EVENT(&evt, SMC_CASE18);
    mmi_frm_post_event(&evt, smc_test_case_check_proc, NULL);      
    return MMI_RET_OK;
}
void smc_case18_check()
{
    MMI_ASSERT(IsScreenPresent(GRP_ID_SMC_G1) == MMI_FALSE);
    MMI_ASSERT(GetCurrScrnId() == SCR_ID_SMC_A);
    MMI_ASSERT(is_top_history_node(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G2) == MMI_FALSE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G3) == MMI_FALSE);
    MMI_ASSERT(group1_close_check == MMI_FALSE);
    MMI_ASSERT(group2_close_check == MMI_TRUE);;
    kal_prompt_trace(MOD_MMI, "[SMC_UT] smart close test case 18 PASS!!");       
}


/*
 * case 19
 * 
 *  [history stack + scenario tree]
 *  
 *  G1(g) -->   G1 --> G2 --> G3
 *  A(s)
 *  IDLE
 *
 *  [scenario change]
 *
 *  close group (G2, G3)
 *
 *  [Expected result]
 *
 *  G1(g)  -->  G1 --> G2
 *  A(s)
 *  IDLE
 */

mmi_ret sg_smc_test_case_19(void *para)
{
    mmi_event_struct evt;
    mmi_frm_close_to_idle_group();
    group1_close_check = MMI_FALSE;
    group2_close_check = MMI_FALSE;
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT]Case 19 Start");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] In idle screen");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen (root, A) - will add to history");    
    EntryNewScreen(SCR_ID_SMC_A, NULL, smc_case_a_entry, NULL);
    
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SMC_G1, group_proc, NULL);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (root, G1) - don't support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G1, MMI_FRM_NODE_NONE_FLAG);
    
    mmi_frm_group_create(GRP_ID_SMC_G1, GRP_ID_SMC_G2, group_proc, NULL);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (G1, G2) - don't support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G2, MMI_FRM_NODE_NONE_FLAG);
    
    mmi_frm_group_create(GRP_ID_SMC_G2, GRP_ID_SMC_G3, group_proc, NULL);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (G2, G3)");
    mmi_frm_group_enter(GRP_ID_SMC_G2, MMI_FRM_NODE_NONE_FLAG);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] close group  (G3)");
    mmi_frm_group_close(GRP_ID_SMC_G3);
    MMI_FRM_INIT_EVENT(&evt, SMC_CASE19);
    mmi_frm_post_event(&evt, smc_test_case_check_proc, NULL);      
    return MMI_RET_OK;
}
void smc_case19_check()
{
    MMI_ASSERT(is_top_history_node(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(IsScreenPresent(GRP_ID_SMC_G1) == MMI_FALSE);
    MMI_ASSERT(GetCurrScrnId() == SCR_ID_SMC_A);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G2) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G3) == MMI_FALSE);
    MMI_ASSERT(group1_close_check == MMI_FALSE);
    MMI_ASSERT(group2_close_check == MMI_FALSE);;
    kal_prompt_trace(MOD_MMI, "[SMC_UT] smart close test case 19 PASS!!");       
}


/*
 * case 20
 * 
 *  [history stack + scenario tree]
 *  
 *                               S2
 *  G1(g) --> G1 --> G2(smc) --> S1
 *  A(s)
 *  IDLE
 *  
 *  [scenario change]
 *
 *  multi-scrn close (G2, S2, S1)
 *
 *  [Expected result]
 *  
 *  G1(g)  --> G1
 *  A(s)
 *  IDLE
 */

mmi_ret sg_smc_test_case_20(void *para)
{
    mmi_event_struct evt;
    mmi_frm_close_to_idle_group();
    group1_close_check = MMI_FALSE;
    group2_close_check = MMI_FALSE;
    kal_prompt_trace(MOD_MMI, "[SMC_UT] Case 20 start");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] In idle screen");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen (root, A) - will add to history");    
    EntryNewScreen(SCR_ID_SMC_A, NULL, smc_case_a_entry, NULL);
    
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SMC_G1, group_proc, NULL);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (root, G1) - don't support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G1, MMI_FRM_NODE_NONE_FLAG);
    
    mmi_frm_group_create(GRP_ID_SMC_G1, GRP_ID_SMC_G2, group_proc, NULL);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (G1, G2) - support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G2, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen  (G2, S1) - add to history");
    mmi_frm_scrn_enter(GRP_ID_SMC_G2, SCR_ID_SMC_S1, NULL, smc_case_a_entry, MMI_FRM_FULL_SCRN);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen  (G1, S2) - add to history");
    mmi_frm_scrn_enter(GRP_ID_SMC_G2, SCR_ID_SMC_S2, NULL, smc_case_b_entry, MMI_FRM_FULL_SCRN);

    kal_prompt_trace(MOD_MMI, "[SMC_UT] close screen (G2, S1, S2)");
    mmi_frm_scrn_multiple_close(GRP_ID_SMC_G2, SCR_ID_SMC_S2, 1, 0, SCR_ID_SMC_S1, 1);

    MMI_FRM_INIT_EVENT(&evt, SMC_CASE20);
    mmi_frm_post_event(&evt, smc_test_case_check_proc, NULL);      
    return MMI_RET_OK;
}
void smc_case20_check()
{
    MMI_ASSERT(is_top_history_node(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(IsScreenPresent(GRP_ID_SMC_G1) == MMI_FALSE);
    MMI_ASSERT(GetCurrScrnId() == SCR_ID_SMC_A);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G2) == MMI_FALSE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SMC_G2, SCR_ID_SMC_S1, MMI_FRM_NODE_ALL_FLAG) == MMI_FALSE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SMC_G2, SCR_ID_SMC_S2, MMI_FRM_NODE_ALL_FLAG) == MMI_FALSE);
    MMI_ASSERT(group1_close_check == MMI_FALSE);
    MMI_ASSERT(group2_close_check == MMI_TRUE);;
    kal_prompt_trace(MOD_MMI, "[SMC_UT] smart close test case 20 PASS!!");       
}

/*
 * case 21
 * 
 *  [history stack + scenario tree]
 *  
 *  G1(g) -->   G1(smc) --> G2(smc) ->S1(not add to history)
 *  A(s)
 *  IDLE
 *
 *  [scenario change]
 *
 *  enter screen (G1, S2)
 *
 *  [Expected result]
 *  
 *  G1 (g) -- >G1(smc) --> S2
 *  A(s)
 *  IDLE
 *
 */

mmi_ret sg_smc_test_case_21(void *para)
{
    mmi_event_struct evt;
    mmi_frm_close_to_idle_group();
    group1_close_check = MMI_FALSE;
    group2_close_check = MMI_FALSE;
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] Case 10 Start");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] In idle screen");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen (root, A) - will add to history");    
    EntryNewScreen(SCR_ID_SMC_A, NULL, smc_case_a_entry, NULL);
    
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SMC_G1, group_proc, NULL);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (root, G1) -  support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G1, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    mmi_frm_group_create(GRP_ID_SMC_G1, GRP_ID_SMC_G2, group_proc, NULL);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (G1, G2) - support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G2, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen  (G2, S1) - not add to history");
    mmi_frm_scrn_enter(GRP_ID_SMC_G2, SCR_ID_SMC_S1, NULL, NULL, MMI_FRM_FULL_SCRN);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen  (G1, S2)");
    mmi_frm_scrn_enter(GRP_ID_SMC_G1, SCR_ID_SMC_S2, NULL, NULL, MMI_FRM_FULL_SCRN);
    MMI_FRM_INIT_EVENT(&evt, SMC_CASE21);
    mmi_frm_post_event(&evt, smc_test_case_check_proc, NULL);      
    return MMI_RET_OK;
}
void smc_case21_check()
{
    MMI_ASSERT(IsScreenPresent(GRP_ID_SMC_G1) == MMI_FALSE);
    MMI_ASSERT(GetCurrScrnId() == SCR_ID_SMC_A);
    MMI_ASSERT(is_top_history_node(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G2) == MMI_FALSE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SMC_G1, SCR_ID_SMC_S2, MMI_FRM_NODE_ALL_FLAG) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SMC_G1, SCR_ID_SMC_S1, MMI_FRM_NODE_ALL_FLAG) == MMI_FALSE);
    MMI_ASSERT(group1_close_check == MMI_FALSE);
    MMI_ASSERT(group2_close_check == MMI_TRUE);;
    kal_prompt_trace(MOD_MMI, "[SMC_UT] smart close test case 21 PASS!!");       
}


/*
 * case 22
 * 
 *  [history stack + scenario tree]
 *  
 *  G1(g) -->   G1(smc) --> G2(smc) ->S1(not add to history)
 *  A(s)
 *  IDLE
 *
 *  scenario change
 *
 *  enter group (G1, G3)
 *
 *  [expect result]
 *
 *  G1(g)  --> G1(smc) ---> G3
 *  A(s)
 *  ILDE
 */

mmi_ret sg_smc_test_case_22(void *para)
{
    mmi_event_struct evt;
    mmi_frm_close_to_idle_group();
    group1_close_check = MMI_FALSE;
    group2_close_check = MMI_FALSE;
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] Case 22 Start");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] In idle screen");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen (root, A) - will add to history");    
    EntryNewScreen(SCR_ID_SMC_A, NULL, smc_case_a_entry, NULL);
    
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SMC_G1, group_proc, NULL);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (root, G1) - support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G1, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    mmi_frm_group_create(GRP_ID_SMC_G1, GRP_ID_SMC_G2, group_proc, NULL);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (G1, G2) - support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G2, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen  (G2, S1) - not add to history");
    mmi_frm_scrn_enter(GRP_ID_SMC_G2, SCR_ID_SMC_S1, NULL, NULL, MMI_FRM_FULL_SCRN);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (G1, G3)");
    mmi_frm_group_create(GRP_ID_SMC_G1, GRP_ID_SMC_G3, group_proc, NULL);
    mmi_frm_group_enter(GRP_ID_SMC_G3, MMI_FRM_NODE_NONE_FLAG);
    MMI_FRM_INIT_EVENT(&evt, SMC_CASE22);
    mmi_frm_post_event(&evt, smc_test_case_check_proc, NULL);      
    return MMI_RET_OK;
}
void smc_case22_check()
{
    MMI_ASSERT(IsScreenPresent(GRP_ID_SMC_G1) == MMI_FALSE);
    MMI_ASSERT(GetCurrScrnId() == SCR_ID_SMC_A);
    MMI_ASSERT(is_top_history_node(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G2) == MMI_FALSE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G3) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SMC_G2, SCR_ID_SMC_S1, MMI_FRM_NODE_ALL_FLAG) == MMI_FALSE);
    MMI_ASSERT(group1_close_check == MMI_FALSE);
    MMI_ASSERT(group2_close_check == MMI_TRUE);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] smart close test case 22 PASS!!");       
}


/*
 * case 23
 * 
 *  [history stack + scenario tree]
 *                         S1(not add to history)  
 *  G1(g) -->   G1(smc) -->S2(add to history)
 *  A(s)
 *  IDLE
 *
 *  scenario change
 *
 *  enter screen (root, B)
 *
 *  [expect result]
 *  
 *  B(s)
 *  G1(g)  --> G1(smc) ---> S2
 *  A(s)
 *  ILDE
 */
mmi_ret sg_smc_test_case_23(void *para)
{
    mmi_event_struct evt;
    mmi_frm_close_to_idle_group();
    group1_close_check = MMI_FALSE;
    group2_close_check = MMI_FALSE;
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] Case 23 Start");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] In idle screen");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen (root, A) - will add to history");    
    EntryNewScreen(SCR_ID_SMC_A, NULL, smc_case_a_entry, NULL);
    
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SMC_G1, group_proc, NULL);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (root, G1) - support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G1, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen  (G1, S1) - add to history");
    mmi_frm_scrn_enter(GRP_ID_SMC_G1, SCR_ID_SMC_S2, NULL, smc_case_a_entry, MMI_FRM_FULL_SCRN);    
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen  (G1, S1) - not add to history");
    mmi_frm_scrn_enter(GRP_ID_SMC_G1, SCR_ID_SMC_S1, NULL, NULL, MMI_FRM_FULL_SCRN);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen  (root, B)");
    EntryNewScreen(SCR_ID_SMC_B, NULL, smc_case_b_entry, NULL);
    MMI_FRM_INIT_EVENT(&evt, SMC_CASE23);
    mmi_frm_post_event(&evt, smc_test_case_check_proc, NULL);      
    return MMI_RET_OK;
}

void smc_case23_check()
{
    MMI_ASSERT(IsScreenPresent(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(GetCurrScrnId() == GRP_ID_SMC_G1);
    MMI_ASSERT(is_top_history_node(SCR_ID_SMC_B) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SMC_G1, SCR_ID_SMC_S1, MMI_FRM_NODE_ALL_FLAG) == MMI_FALSE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SMC_G1, SCR_ID_SMC_S2, MMI_FRM_NODE_ALL_FLAG) == MMI_TRUE);
    MMI_ASSERT(group1_close_check == MMI_FALSE);

    kal_prompt_trace(MOD_MMI, "[SMC_UT] smart close test case 23 PASS!!");       
}


/*
 * case 24
 * 
 *  [history stack + scenario tree]
 *                         
 *  G1(g) -->   G1(smc) -->S1(not add to history)
 *  A(s)
 *  IDLE
 *
 *  scenario change
 *
 *  enter group (G1, G2)
 *
 *  [expect result]
 *  
 *  
 *  G1(g)  --> G1(smc) ---> G2
 *  A(s)
 *  ILDE
 */
mmi_ret sg_smc_test_case_24(void *para)
{
    mmi_event_struct evt;
    mmi_frm_close_to_idle_group();
    group1_close_check = MMI_FALSE;
    group2_close_check = MMI_FALSE;
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] Case 24 Start");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] In idle screen");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen (root, A) - will add to history");    
    EntryNewScreen(SCR_ID_SMC_A, NULL, smc_case_a_entry, NULL);
    
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SMC_G1, group_proc, NULL);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (root, G1) - support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G1, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen  (G1, S1) - not add to history");
    mmi_frm_scrn_enter(GRP_ID_SMC_G1, SCR_ID_SMC_S1, NULL, NULL, MMI_FRM_FULL_SCRN);
    
    mmi_frm_group_create(GRP_ID_SMC_G1, GRP_ID_SMC_G2, group_proc, NULL);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (G1, G3)");
    mmi_frm_group_enter(GRP_ID_SMC_G2, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    MMI_FRM_INIT_EVENT(&evt, SMC_CASE24);
    mmi_frm_post_event(&evt, smc_test_case_check_proc, NULL);      
    return MMI_RET_OK;
}

void smc_case24_check()
{
    MMI_ASSERT(is_top_history_node(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G2) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SMC_G1, SCR_ID_SMC_S1, MMI_FRM_NODE_ALL_FLAG) == MMI_FALSE);
    MMI_ASSERT(group1_close_check == MMI_FALSE);

    kal_prompt_trace(MOD_MMI, "[SMC_UT] smart close test case 24 PASS!!");       
}

/*
 * case 24
 * 
 *  [history stack + scenario tree]
 *                         
 *  G1(g) -->   G1(smc) -->S1(not add to history)
 *  A(s)
 *  IDLE
 *
 *  scenario change
 *
 *  enter screen (G1, S2)
 *
 *  [expect result]
 *  
 *  
 *  G1(g)  --> G1(smc) ---> S2
 *  A(s)
 *  ILDE
 */
mmi_ret sg_smc_test_case_25(void *para)
{
    mmi_event_struct evt;
    mmi_frm_close_to_idle_group();
    group1_close_check = MMI_FALSE;
    group2_close_check = MMI_FALSE;
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] Case 25 Start");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] In idle screen");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen (root, A) - will add to history");    
    EntryNewScreen(SCR_ID_SMC_A, NULL, smc_case_a_entry, NULL);
    
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SMC_G1, group_proc, NULL);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (root, G1) - support smart close");
    mmi_frm_group_enter(GRP_ID_SMC_G1, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen  (G1, S1) - not add to history");
    mmi_frm_scrn_enter(GRP_ID_SMC_G1, SCR_ID_SMC_S1, NULL, NULL, MMI_FRM_FULL_SCRN);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen  (G1, S2) - not add to history");
    mmi_frm_scrn_enter(GRP_ID_SMC_G1, SCR_ID_SMC_S2, NULL, NULL, MMI_FRM_FULL_SCRN);
    MMI_FRM_INIT_EVENT(&evt, SMC_CASE25);
    mmi_frm_post_event(&evt, smc_test_case_check_proc, NULL);      
    return MMI_RET_OK;
}

void smc_case25_check()
{
    MMI_ASSERT(is_top_history_node(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SMC_G1, SCR_ID_SMC_S1, MMI_FRM_NODE_ALL_FLAG) == MMI_FALSE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SMC_G1, SCR_ID_SMC_S2, MMI_FRM_NODE_ALL_FLAG) == MMI_TRUE);
    MMI_ASSERT(group1_close_check == MMI_FALSE);
    
    kal_prompt_trace(MOD_MMI, "[SMC_UT] smart close test case 25 PASS!!");       
}


/*
 * case 26
 * 
 *  [history stack + scenario tree]
 *  
 *  G1(g) -->   G1(smc only bk) --> S1(not add history)
 *  A(s)
 *  IDLE(s)
 *
 *  [scenario change]
 *
 *  enter screen (root, B)
 *
 *  [expected result]
 *  
 *  B(s)
 *  G1(g) --> G1
 *  A(s)
 *  IDLE(s)
 */

mmi_ret sg_smc_test_case_26(void *para)
{
    mmi_event_struct evt;
    
    mmi_frm_close_to_idle_group();
    group1_close_check = MMI_FALSE;
    kal_prompt_trace(MOD_MMI, "[SMC_UT] Case 1 Start");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] In idle screen");
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen (root, A) - will add to history");
    EntryNewScreen(SCR_ID_SMC_A, NULL, smc_case_a_entry, NULL);
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SMC_G1, group_proc, NULL);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter group  (root, G1) - support smart close(bk only)");
    mmi_frm_group_enter(GRP_ID_SMC_G1, MMI_FRM_NODE_SMART_CLOSE_CAUSED_BY_CLOSE_FLAG);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen (G1, S1) - not add to history");
    mmi_frm_scrn_enter(GRP_ID_SMC_G1, SCR_ID_SMC_S1, NULL, NULL, MMI_FRM_FULL_SCRN);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] enter screen (root, B)");
    EntryNewScreen(SCR_ID_SMC_B, NULL, smc_case_b_entry, NULL);
    MMI_FRM_INIT_EVENT(&evt, SMC_CASE26);
    mmi_frm_post_event(&evt, smc_test_case_check_proc, NULL);
    return MMI_RET_OK;
}
void smc_case26_check()
{
    MMI_ASSERT(GetActiveScreenId() == SCR_ID_SMC_B);
    MMI_ASSERT(IsScreenPresent(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(GetCurrScrnId() == GRP_ID_SMC_G1);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SMC_G1) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SMC_G1, SCR_ID_SMC_S1, SCR_ID_SMC_S1) == MMI_FALSE);
    MMI_ASSERT(group1_close_check == MMI_FALSE);
    kal_prompt_trace(MOD_MMI, "[SMC_UT] smart close test case 26 PASS!!");    
}
mmi_ret smc_test_case_check_proc(mmi_event_struct *evt)
{
    MMI_ASSERT(evt->evt_id < SMC_CASE_END);
    
    smc_test_table[evt->evt_id].check();
    return MMI_RET_OK;
}


mmi_ret sg_test(void *para)
{
    mmi_frm_close_to_idle_group();
	start_screen_group_testbed();
    return MMI_RET_OK;
}

/******************************************************************************
 * Test Case for mmi_frm_scrn_enter(GRP_ID_ROOT, ...)
 ******************************************************************************/

typedef enum
{
    SCR_ID_RS_A = 1000,
    SCR_ID_RS_B,
    SCR_ID_RS_C,
    SCR_ID_RS_D,
    SCR_ID_RS_E,
    SCR_ID_RS_F,
    SCR_ID_RS_G,
    SCR_ID_RS_H,
    SCR_ID_RS_I,
    SCR_ID_RS_J,
    SCR_ID_RS_K,
    SCR_ID_RS_L,
    SCR_ID_RS_M,
    SCR_ID_RS_N
} rs_id_enum;
WCHAR input_buffer[32];
void rs_A_entry(void)
{
    MMI_BOOL ret;
    U8 *gui_buffer;
    WCHAR *input_buf;
    scrn_node_struct *found;
    ret = mmi_frm_scrn_enter(GRP_ID_ROOT, SCR_ID_RS_A, NULL, rs_A_entry, MMI_FRM_FULL_SCRN);
    if(ret == MMI_FALSE) return;
    gui_buffer = mmi_frm_scrn_get_gui_buf(GRP_ID_ROOT, SCR_ID_RS_A);
    input_buf = mmi_frm_scrn_get_input_buf(GRP_ID_ROOT, SCR_ID_RS_A);
    //found = _SCRN(_GET_NODE(SCR_ID_RS_A, NULL, _SCRN_ID(SCR_ID_RS_A, SCR_ID_RS_A), GROUP_TREE));
    found = _SCRN(SG_GET_NODE_FROM_ROOT(_SCRN_ID(SCR_ID_RS_A, SCR_ID_RS_A)));
    MMI_ASSERT(found->gui_buf == gui_buffer);
    MMI_ASSERT(found->input_buf == input_buf);
    MMI_ASSERT(found->gui_buf_size == 16);
    MMI_ASSERT(found->input_buf_size == 64);
    MMI_ASSERT(gui_buffer != NULL);
    MMI_ASSERT(gui_buffer[0] == 0x55);
    MMI_ASSERT(input_buf != NULL);
    MMI_ASSERT(input_buf[0] == 0x6666);
    mmi_frm_scrn_clean_gui_buf(GRP_ID_ROOT, SCR_ID_RS_A);
    MMI_ASSERT(found->gui_buf == NULL);
    MMI_ASSERT(found->gui_buf_size == 0);
}
static U8 A_proc_check_counter;
mmi_ret rs_A_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_GOBACK:
            A_proc_check_counter++;
            break;
        case EVT_ID_SCRN_DEINIT:
            A_proc_check_counter++;
            break;
        default:
            break;
    }
    return MMI_RET_OK;
}

/*
 * In IDLE.
 * enter (root, A)
 * close (root, A)
 */
mmi_ret rs_screen_test_case1(void *para)
{
    MMI_BOOL ret;
    mmi_scrn_node_struct node;
    scrn_node_struct *found;
    U8 state;
    mmi_frm_close_to_idle_group();
    ret = mmi_frm_scrn_enter(GRP_ID_ROOT, SCR_ID_RS_A, NULL, rs_A_entry, MMI_FRM_FULL_SCRN);
    MMI_ASSERT(ret == MMI_TRUE);
    state = mmi_frm_scrn_get_state(GRP_ID_ROOT, SCR_ID_RS_A);
    MMI_ASSERT(MMI_SCENARIO_STATE_ACTIVE == state);
    MMI_ASSERT(mmi_frm_group_is_present(SCR_ID_RS_A) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_scrn_get_count(SCR_ID_RS_A) == 1);
    MMI_ASSERT(MMI_TRUE == mmi_frm_scrn_is_present(SCR_ID_RS_A, SCR_ID_RS_A,MMI_FRM_NODE_ALL_FLAG));
    mmi_frm_scrn_set_leave_proc(GRP_ID_ROOT, SCR_ID_RS_A, rs_A_proc);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_ROOT, SCR_ID_RS_A, MMI_FRM_NODE_ALL_FLAG) == MMI_TRUE);
    memset(&node, 0x00, sizeof(node));    
    mmi_frm_scrn_set_user_data(GRP_ID_ROOT, SCR_ID_RS_A, (void *)5050);
    MMI_ASSERT((mmi_frm_scrn_get_user_data(GRP_ID_ROOT, SCR_ID_RS_A) == (void *)5050) == MMI_TRUE);
    mmi_frm_scrn_set_input_buf_mem(GRP_ID_ROOT, SCR_ID_RS_A, mmi_frm_malloc_dbg, mmi_frm_mfree_dbg, (void *)789);
    mmi_frm_scrn_get_info(GRP_ID_ROOT, SCR_ID_RS_A, &node);
    //MMI_ASSERT(node.priority == 1234);
    MMI_ASSERT(node.user_data == (void *)5050);
    MMI_ASSERT(node.entry_proc == rs_A_entry);
    MMI_ASSERT(node.exit_proc == NULL);
    mmi_frm_scrn_set_attribute(GRP_ID_ROOT, SCR_ID_RS_A, MMI_SCRN_ATTRIB_ADD_HISTORY);
//    found = _SCRN(_GET_NODE(SCR_ID_RS_A, NULL, _SCRN_ID(SCR_ID_RS_A, SCR_ID_RS_A), GROUP_TREE));
    found = _SCRN(SG_GET_NODE_FROM_ROOT(_SCRN_ID(SCR_ID_RS_A, SCR_ID_RS_A)));

    MMI_ASSERT(found->mem_alloc == mmi_frm_malloc_dbg);
    MMI_ASSERT(found->mem_free == mmi_frm_mfree_dbg);
    MMI_ASSERT(found->mem_user_data == (void *)789);
    MMI_ASSERT(found->proc == rs_A_proc);
    MMI_ASSERT(IsBitSet(found->attrib, NODE_ATTRIB_AUTO_ADD_HISTORY_IDX));
    mmi_frm_scrn_clear_attribute(GRP_ID_ROOT, SCR_ID_RS_A, MMI_SCRN_ATTRIB_ADD_HISTORY);
    MMI_ASSERT(IsBitReset(found->attrib, NODE_ATTRIB_AUTO_ADD_HISTORY_IDX));
    A_proc_check_counter = 0;
    mmi_frm_scrn_close(GRP_ID_ROOT, SCR_ID_RS_A);
    MMI_ASSERT(mmi_frm_group_is_present(SCR_ID_RS_A) == MMI_FALSE);
    MMI_ASSERT(MMI_FALSE == mmi_frm_scrn_is_present(SCR_ID_RS_A, SCR_ID_RS_A, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(MMI_FALSE == mmi_frm_scrn_is_present(GRP_ID_ROOT, SCR_ID_RS_A, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(A_proc_check_counter == 2);
    kal_prompt_trace(MOD_MMI, "[SG_RS] test case 1 pass");
    return MMI_RET_OK;
}

/*
 * In IDLE.
 * enter (root, A) not add history
 * enter (root, B)
 */
void rs_B_entry(void)
{
    mmi_frm_scrn_enter(GRP_ID_ROOT, SCR_ID_RS_B, NULL, rs_B_entry, MMI_FRM_FULL_SCRN);
}
mmi_ret rs_screen_test_case2(void *para)
{
    MMI_BOOL ret;
    mmi_frm_close_to_idle_group();
    ret = mmi_frm_scrn_enter(GRP_ID_ROOT, SCR_ID_RS_A, NULL, rs_A_entry, MMI_FRM_FULL_SCRN);
    MMI_ASSERT(ret == MMI_TRUE);
    mmi_frm_scrn_set_leave_proc(GRP_ID_ROOT, SCR_ID_RS_A, rs_A_proc);
    A_proc_check_counter = 0;
    mmi_frm_scrn_clear_attribute(GRP_ID_ROOT, SCR_ID_RS_A, MMI_SCRN_ATTRIB_ADD_HISTORY);
    ret = mmi_frm_scrn_enter(GRP_ID_ROOT, SCR_ID_RS_B, NULL, rs_B_entry, MMI_FRM_FULL_SCRN);
    MMI_ASSERT(A_proc_check_counter == 1);
    MMI_ASSERT(ret == MMI_TRUE);
    MMI_ASSERT(MMI_FALSE == mmi_frm_scrn_is_present(GRP_ID_ROOT, SCR_ID_RS_A, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(MMI_FALSE == mmi_frm_group_is_present(SCR_ID_RS_A));
    MMI_ASSERT(MMI_FALSE == mmi_frm_scrn_is_present(SCR_ID_RS_A, SCR_ID_RS_A, MMI_FRM_NODE_ALL_FLAG));
    mmi_frm_scrn_close(GRP_ID_ROOT, SCR_ID_RS_B);
    kal_prompt_trace(MOD_MMI, "[SG_RS] test case 2 pass");
    return MMI_RET_OK;
}

S32 get_rs_gui_size(void)
{
    return 16;
}

U8 * get_rs_gui_data(U8 *buf)
{
    memset(buf, 0x55, 16);
    return buf;
}


/*
 * In IDLE
 * enter (root ,A)
 * enter (root, B)
 * close (root, B)
 */
mmi_ret rs_screen_test_case3(void *para)
{
    MMI_BOOL ret;
    memset(input_buffer, 0x66, 64);
    mmi_frm_close_to_idle_group();
    ret = mmi_frm_scrn_enter(GRP_ID_ROOT, SCR_ID_RS_A, NULL, rs_A_entry, MMI_FRM_FULL_SCRN);
    MMI_ASSERT(ret == MMI_TRUE);
    GetCategoryHistorySize = get_rs_gui_size;
    GetCategoryHistory = get_rs_gui_data;
    mmi_frm_scrn_set_leave_proc(GRP_ID_ROOT, SCR_ID_RS_A, rs_A_proc);
    mmi_frm_scrn_set_active_input_buf_ptr(input_buffer);
    mmi_frm_scrn_set_active_input_buf_size(64);
    A_proc_check_counter = 0;
    ret = mmi_frm_scrn_enter(GRP_ID_ROOT, SCR_ID_RS_B, NULL, rs_B_entry, MMI_FRM_FULL_SCRN);
    mmi_frm_scrn_close(GRP_ID_ROOT, SCR_ID_RS_B);
    kal_prompt_trace(MOD_MMI, "[SG_RS] test case 3 pass");
    return MMI_RET_OK;
}
/*
 *  In IDLE
 *  first enter(root, C)
 *  close(C)
 */
static U8 C_proc_check_counter;
mmi_ret rs_C_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_GOBACK:
            C_proc_check_counter++;
            break;
        case EVT_ID_SCRN_DEINIT:
            C_proc_check_counter++;
            break;
        default:
            break;
    }
    return MMI_RET_OK;
}

void rs_C_entry(void)
{
    MMI_BOOL ret;
    U8 state;
    mmi_scrn_node_struct node;
    scrn_node_struct *found;
    ret = mmi_frm_scrn_enter(GRP_ID_ROOT, SCR_ID_RS_C, NULL, rs_C_entry, MMI_FRM_FULL_SCRN);
    MMI_ASSERT(ret == MMI_TRUE);
    state = mmi_frm_scrn_get_state(GRP_ID_ROOT, SCR_ID_RS_C);
    MMI_ASSERT(MMI_SCENARIO_STATE_ACTIVE == state);
    MMI_ASSERT(mmi_frm_group_is_present(SCR_ID_RS_C) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_scrn_get_count(SCR_ID_RS_C) == 1);
    MMI_ASSERT(MMI_TRUE == mmi_frm_scrn_is_present(SCR_ID_RS_C, SCR_ID_RS_C,MMI_FRM_NODE_ALL_FLAG));
    mmi_frm_scrn_set_leave_proc(GRP_ID_ROOT, SCR_ID_RS_C, rs_C_proc);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_ROOT, SCR_ID_RS_C, MMI_FRM_NODE_ALL_FLAG) == MMI_TRUE);
    memset(&node, 0x00, sizeof(node));    
    MMI_ASSERT((mmi_frm_scrn_get_user_data(GRP_ID_ROOT, SCR_ID_RS_C) == (void *)0x7777) == MMI_TRUE);
    mmi_frm_scrn_set_input_buf_mem(GRP_ID_ROOT, SCR_ID_RS_C, mmi_frm_malloc_dbg, mmi_frm_mfree_dbg, (void *)789);
    mmi_frm_scrn_get_info(GRP_ID_ROOT, SCR_ID_RS_C, &node);
//    MMI_ASSERT(node.priority == 1234);
    MMI_ASSERT(node.user_data == (void *)0x7777);
    MMI_ASSERT(node.entry_proc == rs_C_entry);
    MMI_ASSERT(node.exit_proc == NULL);
    mmi_frm_scrn_set_attribute(GRP_ID_ROOT, SCR_ID_RS_C, MMI_SCRN_ATTRIB_ADD_HISTORY);
//    found = _SCRN(_GET_NODE(SCR_ID_RS_C, NULL, _SCRN_ID(SCR_ID_RS_C, SCR_ID_RS_C), GROUP_TREE));
    found = _SCRN(SG_GET_NODE_FROM_ROOT(_SCRN_ID(SCR_ID_RS_C, SCR_ID_RS_C)));

    MMI_ASSERT(found->mem_alloc == mmi_frm_malloc_dbg);
    MMI_ASSERT(found->mem_free == mmi_frm_mfree_dbg);
    MMI_ASSERT(found->mem_user_data == (void *)789);
    MMI_ASSERT(found->proc == rs_C_proc);
    MMI_ASSERT(IsBitSet(found->attrib, NODE_ATTRIB_AUTO_ADD_HISTORY_IDX));
    mmi_frm_scrn_clear_attribute(GRP_ID_ROOT, SCR_ID_RS_C, MMI_SCRN_ATTRIB_ADD_HISTORY);
    MMI_ASSERT(IsBitReset(found->attrib, NODE_ATTRIB_AUTO_ADD_HISTORY_IDX));
    C_proc_check_counter = 0;
}

mmi_ret rs_screen_test_case4(void *para)
{
    mmi_frm_close_to_idle_group();
    mmi_frm_scrn_first_enter(GRP_ID_ROOT, SCR_ID_RS_C, rs_C_entry, (void *)0x7777);
    mmi_frm_scrn_close(GRP_ID_ROOT, SCR_ID_RS_C);
    MMI_ASSERT(mmi_frm_group_is_present(SCR_ID_RS_C) == MMI_FALSE);
    MMI_ASSERT(MMI_FALSE == mmi_frm_scrn_is_present(SCR_ID_RS_C, SCR_ID_RS_C, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(MMI_FALSE == mmi_frm_scrn_is_present(GRP_ID_ROOT, SCR_ID_RS_C, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(C_proc_check_counter == 2);
    kal_prompt_trace(MOD_MMI, "[SG_RS] test case 4 pass");
    return MMI_RET_OK;
}

/*
 *  In IDLE
 *  first enter(root, D) not add history
 *  first enter(root, E)
 *  close (root, E)
 */
void rs_D_entry(void)
{
    MMI_BOOL ret;
    ret = mmi_frm_scrn_enter(GRP_ID_ROOT, SCR_ID_RS_D, NULL, rs_D_entry, MMI_FRM_FULL_SCRN);
    MMI_ASSERT(ret == MMI_TRUE);
    mmi_frm_scrn_clear_attribute(GRP_ID_ROOT, SCR_ID_RS_D, MMI_SCRN_ATTRIB_ADD_HISTORY);
}
void rs_E_entry(void)
{
    MMI_BOOL ret;
    ret = mmi_frm_scrn_enter(GRP_ID_ROOT, SCR_ID_RS_E, NULL, rs_E_entry, MMI_FRM_FULL_SCRN);
    MMI_ASSERT(ret == MMI_TRUE);
}
mmi_ret rs_screen_test_case5(void *para)
{
    mmi_frm_close_to_idle_group();
    mmi_frm_scrn_first_enter(GRP_ID_ROOT, SCR_ID_RS_D, rs_D_entry, (void *)0x7777);
    mmi_frm_scrn_first_enter(GRP_ID_ROOT, SCR_ID_RS_E, rs_E_entry, (void *)0x8888);
    MMI_ASSERT(MMI_FALSE == mmi_frm_scrn_is_present(GRP_ID_ROOT, SCR_ID_RS_D, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(MMI_FALSE == mmi_frm_scrn_is_present(SCR_ID_RS_D, SCR_ID_RS_D, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(MMI_FALSE == mmi_frm_group_is_present(SCR_ID_RS_D));
    kal_prompt_trace(MOD_MMI, "[SG_RS] test case 5 pass");
    return MMI_RET_OK;
}

/*
 *  In IDLE
 *  first enter(root, F)
 *  first enter(root, G)
 *  close (root, G)
 */
void rs_F_exit(void)
{
    mmi_frm_scrn_set_user_data(GRP_ID_ROOT, SCR_ID_RS_F, (void *)0x5555);
}
void rs_F_entry(void)
{
    MMI_BOOL ret;
    void *arg;
    U8 *gui_buffer;
    WCHAR *input_buf;
    scrn_node_struct *found;
    ret = mmi_frm_scrn_enter(GRP_ID_ROOT, SCR_ID_RS_F, rs_F_exit, rs_F_entry, MMI_FRM_FULL_SCRN);
    MMI_ASSERT(MMI_TRUE == ret);
    arg = mmi_frm_scrn_get_user_data(GRP_ID_ROOT, SCR_ID_RS_F);
    if (arg == (void *)0x5555)
    {
        gui_buffer = mmi_frm_scrn_get_gui_buf(GRP_ID_ROOT, SCR_ID_RS_F);
        input_buf = mmi_frm_scrn_get_input_buf(GRP_ID_ROOT, SCR_ID_RS_F);
        //found = _SCRN(_GET_NODE(SCR_ID_RS_F, NULL, _SCRN_ID(SCR_ID_RS_F, SCR_ID_RS_F), GROUP_TREE));
        found = _SCRN(SG_GET_NODE_FROM_ROOT(_SCRN_ID(SCR_ID_RS_F, SCR_ID_RS_F)));
        
        MMI_ASSERT(found->gui_buf == gui_buffer);
        MMI_ASSERT(found->input_buf == input_buf);
        MMI_ASSERT(found->gui_buf_size == 16);
        MMI_ASSERT(found->input_buf_size == 64);
        MMI_ASSERT(gui_buffer != NULL);
        MMI_ASSERT(gui_buffer[0] == 0x55);
        MMI_ASSERT(input_buf != NULL);
        MMI_ASSERT(input_buf[0] == 0x6666);
        mmi_frm_scrn_clean_gui_buf(GRP_ID_ROOT, SCR_ID_RS_F);
        MMI_ASSERT(found->gui_buf == NULL);
        MMI_ASSERT(found->gui_buf_size == 0);

    }
    else if (arg == (void *)0x6666)
    {
        gui_buffer = mmi_frm_scrn_get_gui_buf(GRP_ID_ROOT, SCR_ID_RS_F);
        MMI_ASSERT(gui_buffer == NULL);
        GetCategoryHistorySize = get_rs_gui_size;
        GetCategoryHistory = get_rs_gui_data;
        memset(input_buffer, 0x66, 64);
        mmi_frm_scrn_set_active_input_buf_ptr(input_buffer);
        mmi_frm_scrn_set_active_input_buf_size(64);        
    }    
}
void rs_G_entry(void)
{
    mmi_frm_scrn_enter(GRP_ID_ROOT, SCR_ID_RS_G, NULL, rs_G_entry, MMI_FRM_FULL_SCRN);
}
mmi_ret rs_screen_test_case6(void *para)
{
    mmi_frm_close_to_idle_group();
    mmi_frm_scrn_first_enter(GRP_ID_ROOT, SCR_ID_RS_F, rs_F_entry, (void*)0x6666);
    mmi_frm_scrn_first_enter(GRP_ID_ROOT, SCR_ID_RS_G, rs_G_entry, (void*)0x8888);
    mmi_frm_scrn_close(GRP_ID_ROOT, SCR_ID_RS_G);
    kal_prompt_trace(GRP_ID_ROOT, "[SG_RS] test case 6 pass");
    return MMI_RET_OK;
}

/*
 *  In IDLE
 *  enter(root, H)
 *  enter(root, I)
 *  close (root, I)
 *  In the H's entry enter J
 */
static MMI_BOOL is_J_entry = MMI_FALSE;
void rs_J_entry(void)
{
    MMI_BOOL ret; 
    ret = mmi_frm_scrn_enter(GRP_ID_ROOT, SCR_ID_RS_J, NULL, rs_J_entry, MMI_FRM_FULL_SCRN);
    MMI_ASSERT(ret == MMI_TRUE);
    is_J_entry = MMI_TRUE;
    
}
void rs_H_entry(void)
{
    MMI_BOOL ret;
    ret = mmi_frm_scrn_enter(GRP_ID_ROOT, SCR_ID_RS_J, NULL, rs_J_entry, MMI_FRM_FULL_SCRN);
}
void rs_I_entry(void)
{
}
mmi_ret rs_test_case_7_check(mmi_event_struct *evt)
{
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_ROOT, SCR_ID_RS_J, MMI_FRM_NODE_ALL_FLAG) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(SCR_ID_RS_J) == MMI_TRUE);
    MMI_ASSERT(is_J_entry == MMI_TRUE);
    is_J_entry = MMI_FALSE;
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_ROOT, SCR_ID_RS_H, MMI_FRM_NODE_ALL_FLAG) == MMI_FALSE);
    MMI_ASSERT(mmi_frm_group_is_present(SCR_ID_RS_H) == MMI_FALSE);
    kal_prompt_trace(MOD_MMI, "[SG_RS] test case 7 pass");
    return MMI_RET_OK;
}
mmi_ret rs_screen_test_case7(void *para)
{
    MMI_BOOL ret;
    mmi_event_struct evt;
    mmi_frm_close_to_idle_group();
    ret = mmi_frm_scrn_enter(GRP_ID_ROOT, SCR_ID_RS_H, NULL, rs_H_entry, MMI_FRM_FULL_SCRN);
    MMI_ASSERT(ret == MMI_TRUE);
    ret = mmi_frm_scrn_enter(GRP_ID_ROOT, SCR_ID_RS_I, NULL, rs_I_entry, MMI_FRM_FULL_SCRN);
    mmi_frm_scrn_close(GRP_ID_ROOT, SCR_ID_RS_I);
    MMI_FRM_INIT_EVENT(&evt, 0x1234);
    MMI_FRM_POST_EVENT(&evt, rs_test_case_7_check, NULL);
    return MMI_RET_OK;
}

/*
 * In IDLE
 * first enter(root, K)
 */
static MMI_BOOL rs_goback = MMI_FALSE;
static MMI_BOOL is_M_entry = MMI_FALSE;
void rs_M_entry(void)
{
    MMI_BOOL ret;
    ret = mmi_frm_scrn_enter(GRP_ID_ROOT, SCR_ID_RS_M, NULL, rs_H_entry, MMI_FRM_FULL_SCRN);
    MMI_ASSERT(ret == MMI_TRUE);
    MMI_ASSERT(mmi_frm_scrn_get_user_data(GRP_ID_ROOT, SCR_ID_RS_M) == (void *)0x66);
    is_M_entry = MMI_TRUE;  
}
void rs_K_entry(void)
{
    MMI_BOOL ret;
    if (rs_goback == MMI_FALSE)
    {
        ret = mmi_frm_scrn_enter(GRP_ID_ROOT, SCR_ID_RS_K, NULL, rs_K_entry, MMI_FRM_FULL_SCRN);
        MMI_ASSERT(ret == MMI_TRUE);
    }
    else
    {
        rs_goback = MMI_FALSE;
        mmi_frm_scrn_first_enter(GRP_ID_ROOT, SCR_ID_RS_M, rs_M_entry, (void *)0x66);
    }
}
mmi_ret rs_test_case_8_check(void *para)
{
    MMI_ASSERT(is_M_entry == MMI_TRUE);
    is_M_entry = MMI_FALSE;
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_ROOT, SCR_ID_RS_M, MMI_FRM_NODE_ALL_FLAG) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_ROOT, SCR_ID_RS_K, MMI_FRM_NODE_ALL_FLAG) == MMI_FALSE);
    MMI_ASSERT(mmi_frm_group_is_present(SCR_ID_RS_M) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(SCR_ID_RS_K) == MMI_FALSE);
    kal_prompt_trace(MOD_MMI, "[SG_RS] test case 8 PASS");
    return  MMI_RET_OK;
}
void rs_L_entry(void){};
mmi_ret rs_screen_test_case8(void *para)
{
    mmi_event_struct evt;
    mmi_frm_close_to_idle_group();
    mmi_frm_scrn_first_enter(GRP_ID_ROOT, SCR_ID_RS_K, rs_K_entry, (void *)0x55);
    mmi_frm_scrn_enter(GRP_ID_ROOT, SCR_ID_RS_L, NULL, rs_L_entry, MMI_FRM_FULL_SCRN);
    rs_goback = MMI_TRUE;
    mmi_frm_scrn_close(GRP_ID_ROOT, SCR_ID_RS_L);
    MMI_FRM_INIT_EVENT(&evt, 0x1234);
    MMI_FRM_POST_EVENT(&evt, rs_test_case_8_check, NULL);
    return MMI_RET_OK;
}


/******************************************************************************
 * stop delete test case
 ******************************************************************************/
typedef enum
{
    GRP_ID_SD_A = 1000,
    SCR_ID_SD_S1,
    GRP_ID_SD_B,
    GRP_ID_SD_C,
    GRP_ID_SD_D,
    SCR_ID_SD_1,
    SCR_ID_SD_2,
} stop_delete_id_enum;

/*
 * In IDLE
 *   group_create(root, A)
 *   group_enter(root, A)
 *   scrn_enter(A, S1)
 *   close group(A) , not allow delete/allow delete
 *   Goback IDLE,     allow delete/not allow delete
 */
static MMI_BOOL is_allow_delete = MMI_TRUE;
static U8 goback_cnt = 0;
static U8 goback_cnt_in_end = 0;
static U8 del_cnt = 0;
static U8 del_in_end_cnt = 0;
mmi_ret stop_delete_case1_group_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
    case EVT_ID_GROUP_GOBACK:
         if (is_allow_delete == MMI_TRUE)
         {
            goback_cnt++;
            break;
         }
         else
         {
            return MMI_RET_ERR;
         }
    case EVT_ID_GROUP_DELETE_REQ:
         if (is_allow_delete == MMI_TRUE)
         {
            del_cnt++;
            break;
         }
         else
         {
            return MMI_RET_ERR;
         }
         
    case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        if (is_allow_delete == MMI_TRUE)
        {
           goback_cnt_in_end++;
           break;
        }
        else
        {
           return MMI_RET_ERR;
        }

    case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
        if (is_allow_delete == MMI_TRUE)
        {
           del_in_end_cnt++;
           break;
        }
        else
        {
           return MMI_RET_ERR;
        }

    }
    return MMI_RET_OK;
}
void sd_S1_entry(void) {}
mmi_ret stop_delete_test_case1(void *para)
{
    mmi_frm_close_to_idle_group();
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SD_A) == MMI_FALSE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SD_A, SCR_ID_SD_S1, MMI_FRM_NODE_ALL_FLAG) == MMI_FALSE);

    is_allow_delete = MMI_FALSE;
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SD_A, stop_delete_case1_group_proc, NULL);
    mmi_frm_group_enter(GRP_ID_SD_A, MMI_FRM_NODE_NONE_FLAG);
    mmi_frm_scrn_enter(GRP_ID_SD_A, SCR_ID_SD_S1, NULL, sd_S1_entry, MMI_FRM_FULL_SCRN);

    mmi_frm_group_close(GRP_ID_SD_A);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SD_A) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SD_A, SCR_ID_SD_S1, MMI_FRM_NODE_ALL_FLAG) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_get_active_id() == GRP_ID_SD_A);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == SCR_ID_SD_S1);

    mmi_frm_close_to_idle_group();
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SD_A) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SD_A, SCR_ID_SD_S1, MMI_FRM_NODE_ALL_FLAG) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_get_active_id() == GRP_ID_SD_A);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == SCR_ID_SD_S1);
    MMI_ASSERT(is_top_history_node(GRP_ID_SD_A) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_get_active_id() == GRP_ID_SD_A);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == SCR_ID_SD_S1);
    is_allow_delete = MMI_TRUE;

    mmi_frm_group_close(GRP_ID_SD_A);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SD_A) == MMI_FALSE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SD_A, SCR_ID_SD_S1, MMI_FRM_NODE_ALL_FLAG) == MMI_FALSE);
    //MMI_ASSERT(mmi_frm_group_get_active_id() == GRP_ID_IDLE_MAIN);
    MMI_ASSERT(goback_cnt == 1);
    goback_cnt = 0;
    //MMI_ASSERT(mmi_frm_scrn_get_active_id() == SCR_ID_IDLE_MAIN);
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SD_A, stop_delete_case1_group_proc, NULL);
    mmi_frm_group_enter(GRP_ID_SD_A, MMI_FRM_NODE_NONE_FLAG);
    mmi_frm_scrn_enter(GRP_ID_SD_A, SCR_ID_SD_S1, NULL, sd_S1_entry, MMI_FRM_FULL_SCRN);
    mmi_frm_close_to_idle_group();
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SD_A) == MMI_FALSE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SD_A, SCR_ID_SD_S1, MMI_FRM_NODE_ALL_FLAG) == MMI_FALSE);
    //MMI_ASSERT(mmi_frm_group_get_active_id() == GRP_ID_INVALID);
    MMI_ASSERT(goback_cnt_in_end == 1);
    goback_cnt_in_end = 0;    
      
    kal_prompt_trace(MOD_MMI, "[SG_UT] stop delete test case 1 PASS");
    return MMI_RET_OK;
}


/*
 *  In IDLE
 *  group_create(root A)
 *  group_enter(root, A)
 *  scrn_enter(S1)
 *  EntryNewScreen(B)
 *  close group(A) not allow delete/allow delete
 *  Goback Idle    not allow delete/allow delete
 */
mmi_ret stop_delete_test_case2(void *para)
{
	U16 ID;
	mmi_frm_close_to_idle_group();
	ID = get_active_history_node_id();
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SD_A) == MMI_FALSE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SD_A, SCR_ID_SD_S1, MMI_FRM_NODE_ALL_FLAG) == MMI_FALSE);
    is_allow_delete = MMI_FALSE;
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SD_A, stop_delete_case1_group_proc, NULL);
    mmi_frm_group_enter(GRP_ID_SD_A, MMI_FRM_NODE_NONE_FLAG);
    mmi_frm_scrn_enter(GRP_ID_SD_A, SCR_ID_SD_S1, NULL, sd_S1_entry, MMI_FRM_FULL_SCRN);
    EntryNewScreen(GRP_ID_SD_B, NULL, sd_S1_entry, NULL);
    mmi_frm_group_close(GRP_ID_SD_A);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SD_A) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SD_A, SCR_ID_SD_S1, MMI_FRM_NODE_ALL_FLAG) == MMI_TRUE);
    MMI_ASSERT(IsScreenPresent(GRP_ID_SD_A) == MMI_TRUE);
    mmi_frm_close_to_idle_group();
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SD_A) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SD_A, SCR_ID_SD_S1, MMI_FRM_NODE_ALL_FLAG) == MMI_TRUE);
    MMI_ASSERT(is_top_history_node(GRP_ID_SD_A) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_get_active_id() == GRP_ID_SD_A);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == SCR_ID_SD_S1);
    is_allow_delete = MMI_TRUE;
    EntryNewScreen(GRP_ID_SD_B, NULL, sd_S1_entry, NULL);
    mmi_frm_group_close(GRP_ID_SD_A);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SD_A) == MMI_FALSE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SD_A, SCR_ID_SD_S1, MMI_FRM_NODE_ALL_FLAG) == MMI_FALSE);
    MMI_ASSERT(del_cnt == 1);
    del_cnt = 0;
    MMI_ASSERT(IsScreenPresent(GRP_ID_SD_A) == MMI_FALSE);
    MMI_ASSERT(is_top_history_node(GRP_ID_SD_B) == MMI_TRUE);   
    mmi_frm_close_to_idle_group();
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SD_A, stop_delete_case1_group_proc, NULL);
    mmi_frm_group_enter(GRP_ID_SD_A, MMI_FRM_NODE_NONE_FLAG);
    mmi_frm_scrn_enter(GRP_ID_SD_A, SCR_ID_SD_S1, NULL, sd_S1_entry, MMI_FRM_FULL_SCRN);
    EntryNewScreen(GRP_ID_SD_B, NULL, sd_S1_entry, NULL);
    mmi_frm_close_to_idle_group();
    MMI_ASSERT(del_in_end_cnt == 1);
    del_in_end_cnt = 0;
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SD_A) == MMI_FALSE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SD_A, SCR_ID_SD_S1, MMI_FRM_NODE_ALL_FLAG) == MMI_FALSE);
    MMI_ASSERT(IsScreenPresent(GRP_ID_SD_A) == MMI_FALSE);
    MMI_ASSERT(is_top_history_node(ID) == MMI_TRUE);

    kal_prompt_trace(MOD_MMI, "[SG_UT] stop delete test case 2 PASS");
    return MMI_RET_OK;
}


/*
 * In IDLE
 * group_create (root, C)
 * group_enter (C)
 * scrn_enter(C, 1)
 * scrn_enter(C, 2)
 * close group(C), 1 not allow to be deleted 
 */
static MMI_BOOL is_1_entry = MMI_FALSE;
void sd_1_entry(void)
{
    is_1_entry = MMI_TRUE;
    mmi_frm_scrn_enter(GRP_ID_SD_C, SCR_ID_SD_1, NULL, sd_1_entry, MMI_FRM_FULL_SCRN);
}
void sd_2_entry(void){}
mmi_ret sd_1_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
    case EVT_ID_SCRN_DELETE_REQ:
    case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
    if (is_allow_delete == FALSE)
    {
      return  MMI_RET_ERR;
    }
    }
    return MMI_RET_OK;
}
mmi_ret stop_delete_test_case3(void *para)
{
    mmi_ret ret;
    mmi_frm_close_to_idle_group();
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SD_C, NULL, NULL);
    mmi_frm_group_enter(GRP_ID_SD_C, 0);
    ret = mmi_frm_scrn_enter(GRP_ID_SD_C, SCR_ID_SD_1, NULL, sd_1_entry, MMI_FRM_FULL_SCRN);
    mmi_frm_scrn_set_leave_proc(GRP_ID_SD_C, SCR_ID_SD_1, sd_1_proc);
    MMI_ASSERT(ret == MMI_TRUE);
    ret = mmi_frm_scrn_enter(GRP_ID_SD_C, SCR_ID_SD_2, NULL, sd_2_entry, MMI_FRM_FULL_SCRN);
    MMI_ASSERT(ret == MMI_TRUE);
    is_allow_delete = MMI_FALSE;
    mmi_frm_group_close(GRP_ID_SD_C);
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_SD_C) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SD_C, SCR_ID_SD_1, MMI_FRM_NODE_ALL_FLAG) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_SD_C, SCR_ID_SD_2, MMI_FRM_NODE_ALL_FLAG) == MMI_FALSE);
    MMI_ASSERT(is_1_entry == MMI_TRUE);
    is_1_entry = MMI_FALSE;
    kal_prompt_trace(MOD_MMI, "[SG_UT] stop delete test case 3 PASS");
    return MMI_RET_OK;
}


/******************************************************************************
 * END key process test case
 ******************************************************************************/
typedef enum
{
    GRP_ID_EKP_A = 1000,
    SCR_ID_EKP_S1,
    GRP_ID_EKP_B,
} end_key_process_enum;

/*
 * case 1:
 * ExecuteRootMain
 * In some group's delete /goback event enter a group
 */
static MMI_BOOL is_group_active = MMI_FALSE;
mmi_ret ek_process_case1_B_proc(mmi_event_struct *evt)
{
    if (evt->evt_id == EVT_ID_GROUP_ACTIVE)
    {
        is_group_active = MMI_TRUE;
    }
    return MMI_RET_OK;
}
mmi_ret ek_process_case1_A_proc(mmi_event_struct *evt)
{
    if (evt->evt_id == EVT_ID_GROUP_GOBACK_IN_END_KEY)
    {
        mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_EKP_B, ek_process_case1_B_proc, NULL);
        mmi_frm_group_enter(GRP_ID_EKP_B, 0);
    }
    return MMI_RET_OK;
}
void ekp_S1_entry(void) {}
// This case will fail, because In Go Back Procedure to EntryNewScreen
mmi_ret end_key_process_test_case1(void *para)
{
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
#endif
    kal_prompt_trace(MOD_MMI, "[SG_EKP] test case 1 PASS");
    return MMI_RET_OK;
}

/*
 * case 2:
 *
 * ExecuteRootMain
 * In Idle Callback enter group
 */

static MMI_BOOL is_enable_idle_call_back = MMI_FALSE;
U8 mmi_sg_test_check(void)
{
    return is_enable_idle_call_back;
}

void mmi_sg_test_idle_callback_exec(void)
{
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_EKP_B, ek_process_case1_B_proc, NULL);
    mmi_frm_group_enter(GRP_ID_EKP_B, 0);
}

mmi_ret  end_key_process_2_check(mmi_event_struct *event)
{
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_EKP_B) == MMI_TRUE);
    MMI_ASSERT(is_group_active == MMI_TRUE);
    is_group_active = MMI_FALSE;
    MMI_ASSERT(is_top_history_node(GRP_ID_EKP_B) == MMI_TRUE);
    is_enable_idle_call_back = MMI_FALSE;
    kal_prompt_trace(MOD_MMI, "[SG_EKP] test case 2 PASS");
    return MMI_RET_OK;
}

mmi_ret end_key_process_test_case2(void *para)
{
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
#endif
    
    return MMI_RET_OK;
}


/******************************************************************************
 * small screen test case
 ******************************************************************************/
typedef enum
{
    GRP_ID_SS_A = 1000,
    GRP_DI_SS_B,
    SCR_ID_SS_1,
    SCR_ID_SS_2,
    SCR_ID_SS_3
} small_screen_id;
void ss_1_entry(void)
{
    MMI_BOOL ret;
    U8 *gui_buf;
    U8 *gui_buf2;
    WCHAR *input_buf;
    WCHAR *input_buf2;
    ret = mmi_frm_scrn_enter(GRP_ID_SS_A, SCR_ID_SS_1, NULL, ss_1_entry, MMI_FRM_FULL_SCRN);
    MMI_ASSERT(ret == MMI_TRUE);
    gui_buf = mmi_frm_scrn_get_active_gui_buf();
    gui_buf2 = mmi_frm_scrn_get_gui_buf(GRP_ID_SS_A, SCR_ID_SS_1);
    MMI_ASSERT(gui_buf == gui_buf2);
    MMI_ASSERT(gui_buf != NULL);
    MMI_ASSERT(gui_buf[0] == 0x55);
    input_buf = mmi_frm_scrn_get_active_input_buf();
    input_buf2 = mmi_frm_scrn_get_input_buf(GRP_ID_SS_A,SCR_ID_SS_1);
    MMI_ASSERT(input_buf == input_buf2);
    MMI_ASSERT(input_buf != NULL);
    MMI_ASSERT(input_buf[0] = 0x6666);
    
}
void ss_2_entry(void)
{
    MMI_BOOL ret;
    ret =mmi_frm_scrn_enter(GRP_DI_SS_B, SCR_ID_SS_2, NULL, ss_2_entry, MMI_FRM_SMALL_SCRN);
    if (ret == MMI_TRUE)    
    set_small_screen();
}
void ss_3_entry(void)
{
    MMI_BOOL ret;
    ret =mmi_frm_scrn_enter(GRP_DI_SS_B, SCR_ID_SS_3, NULL, ss_3_entry, MMI_FRM_SMALL_SCRN);
    if (ret == MMI_TRUE)    
    set_small_screen();    
}
mmi_ret  small_screen_test_case1(void *para)
{
    mmi_frm_close_to_idle_group();
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SS_A, NULL, NULL);
    mmi_frm_group_enter(GRP_ID_SS_A, 0);    
    mmi_frm_scrn_enter(GRP_ID_SS_A, SCR_ID_SS_1, NULL, ss_1_entry, MMI_FRM_FULL_SCRN);
    GetCategoryHistorySize = get_rs_gui_size;
    GetCategoryHistory = get_rs_gui_data;
    mmi_frm_scrn_set_active_input_buf_ptr(input_buffer);
    memset(input_buffer, 0x66, 64);
    mmi_frm_scrn_set_active_input_buf_size(64);

    mmi_frm_group_create(GRP_ID_SS_A, GRP_DI_SS_B, NULL, NULL);
    mmi_frm_group_enter(GRP_DI_SS_B, 0);

    ss_2_entry();
    ss_3_entry();
    mmi_frm_scrn_close(GRP_DI_SS_B, SCR_ID_SS_3);
    kal_prompt_trace(MOD_MMI, "[SG_UT] small screen test case 1  pass");
    return MMI_RET_OK;
}


/******************************************************************************
 * adaptor node
 ******************************************************************************/
typedef enum
{
    GRP_ID_ADP_1 = 1000,
    SCR_ID_ADP_1,
    GRP_ID_ADP_2,
    GRP_ID_ADP_3
} adaptor_node_enum;
static void *p_scrm_mem;
static MMI_BOOL is_back = MMI_FALSE;
void adp_1_exit(void)
{
    mmi_frm_scrmem_free(p_scrm_mem);
}
void adp_1_entry(void)
{
    MMI_BOOL ret;
    ret = mmi_frm_scrn_enter(GRP_ID_ADP_1, SCR_ID_ADP_1, adp_1_exit, adp_1_entry, MMI_FRM_FULL_SCRN);
    MMI_ASSERT(ret == MMI_TRUE);
    p_scrm_mem = mmi_frm_scrmem_alloc(1024);
    if (is_back == MMI_TRUE)
    {
        is_back = MMI_FALSE;
        mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_ADP_3, NULL, NULL);
        mmi_frm_group_enter(GRP_ID_ADP_3, 0);
    }    

}
//This case will fail
mmi_ret adaptor_node_related_test_case1(void *para)
{
#if 0   
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    return MMI_RET_OK;
}


/******************************************************************************
 * screen group re-entry
 ******************************************************************************/
typedef enum
{
    GRP_ID_RE_A = 1000,
    SCR_ID_RE_1,
    SCR_ID_RE_2,
    SCR_ID_RE_3
} reentry_test_id;
void re_3_entry(void)
{
    mmi_frm_scrn_enter(GRP_ID_RE_A, SCR_ID_RE_3, NULL, re_3_entry, MMI_FRM_FULL_SCRN);
}
void re_1_entry(void)
{
    mmi_frm_scrn_enter(GRP_ID_RE_A, SCR_ID_RE_1, NULL, re_1_entry, MMI_FRM_FULL_SCRN);
    mmi_frm_scrn_enter(GRP_ID_RE_A, SCR_ID_RE_3, NULL, re_3_entry, MMI_FRM_FULL_SCRN);
    mmi_frm_scrn_close(GRP_ID_RE_A, SCR_ID_RE_3);
    mmi_frm_scrn_enter(GRP_ID_RE_A, SCR_ID_RE_3, NULL, re_3_entry, MMI_FRM_FULL_SCRN);
}
mmi_ret sg_ree_test_case1_check(mmi_event_struct *evt)
{
    
    MMI_ASSERT(mmi_frm_scrn_is_present(GRP_ID_RE_A, SCR_ID_RE_1, MMI_FRM_NODE_ALL_FLAG) == MMI_TRUE);
    return MMI_RET_OK;
}
mmi_ret sg_ree_test_case1(void *para)
{
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
#endif
    return MMI_RET_OK;
}


typedef enum
{
    GPR_ID_CLOSE_A = 1000,
    GPR_ID_CLOSE_B,
    GPR_ID_CLOSE_C,
    GRP_ID_CLOSE_D,
    SCR_ID_CLOSE_1,
    SCR_ID_CLOSE_2,

} close_id_enum;
mmi_ret close_test_proc_A(mmi_event_struct *evt)
{

    return MMI_RET_OK;
}
mmi_ret close_test_proc_B(mmi_event_struct *evt)
{
    if (evt->evt_id == EVT_ID_GROUP_DELETE_REQ)
    {
        mmi_frm_group_close(GPR_ID_CLOSE_B);
    }
    return MMI_RET_OK;
}
mmi_ret close_test_proc_C(mmi_event_struct *evt)
{
    if (evt->evt_id == EVT_ID_GROUP_INACTIVE)
    {
        mmi_frm_group_close(GPR_ID_CLOSE_C);
    }    
    return MMI_RET_OK;
}
void close_scr_1_entry(void)
{
    mmi_frm_scrn_enter(GPR_ID_CLOSE_A, SCR_ID_CLOSE_1, NULL, re_1_entry, MMI_FRM_FULL_SCRN);
}
mmi_ret sg_group_close_test(void *para)
{

    mmi_frm_close_to_idle_group();
    mmi_frm_group_create(GRP_ID_ROOT, GPR_ID_CLOSE_A, close_test_proc_A, NULL);
    mmi_frm_group_enter(GPR_ID_CLOSE_A, 0);
    close_scr_1_entry();
    mmi_frm_group_create(GPR_ID_CLOSE_A, GPR_ID_CLOSE_B, close_test_proc_B, NULL);
    mmi_frm_group_enter(GPR_ID_CLOSE_B, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_group_create(GPR_ID_CLOSE_B, GPR_ID_CLOSE_C, close_test_proc_C, NULL);
    mmi_frm_group_enter(GPR_ID_CLOSE_C, 0);
    mmi_frm_scrn_enter(GPR_ID_CLOSE_C, SCR_ID_CLOSE_2, NULL, NULL, MMI_FRM_FULL_SCRN);
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_CLOSE_D, NULL, NULL);
    mmi_frm_group_enter(GRP_ID_CLOSE_D, 0);    
    return MMI_RET_OK;
}

typedef enum
{
    GRP_ID_RED = 1000,
    SCR_ID_RED,
    GRP_ID_BLUE,
    SCR_ID_BLUE,
    GRP_ID_YELLOW,
    SCR_ID_YELLOW
} color_id_enum;
static U32 curent_color;
static MMI_BOOL is_post_sent = MMI_FALSE;
static MMI_BOOL is_need_back_to_idle = MMI_FALSE;
mmi_ret back_to_idle(mmi_event_struct *evt)
{
    is_post_sent = MMI_FALSE;
    if (is_need_back_to_idle == MMI_TRUE)
    {    
        mmi_frm_close_to_idle_group();
		is_need_back_to_idle = MMI_FALSE;
        kal_prompt_trace(MOD_MMI, "[SG] back to idle");
    }
    return MMI_RET_OK;
}

mmi_ret prohibit_scrn_enter_proc(mmi_event_struct *evt)
{
    mmi_event_struct tmp;
    mmi_frm_scrn_enter_success_evt *s_evt = (mmi_frm_scrn_enter_success_evt *)evt;
    if ((s_evt->group_id == GRP_ID_YELLOW) && (s_evt->scrn_id == SCR_ID_YELLOW))
    {
        is_need_back_to_idle = MMI_FALSE;
        return MMI_RET_OK;
    }
    if (is_post_sent == MMI_FALSE)
    {    
        MMI_FRM_INIT_EVENT(&tmp, 0);
        MMI_FRM_POST_EVENT(&tmp, back_to_idle, NULL);
        is_post_sent = MMI_TRUE;
        is_need_back_to_idle = MMI_TRUE;
    }    
    return MMI_RET_PROHIBIT_SCRN_ENTER;
}

void entry_red(void)
{
    if (mmi_frm_scrn_enter(GRP_ID_RED, SCR_ID_RED, NULL, entry_red, MMI_FRM_FULL_SCRN))
    {
        kal_prompt_trace(MOD_MMI, "[SG] show red");
    }    
}
void entry_blue(void)
{
    if (mmi_frm_scrn_enter(GRP_ID_BLUE, SCR_ID_BLUE, NULL, entry_blue, MMI_FRM_FULL_SCRN))
    {
        kal_prompt_trace(MOD_MMI, "[SG] show blue");
    }    
}
void entry_yellow(void)
{
    if (mmi_frm_scrn_enter(GRP_ID_YELLOW, SCR_ID_YELLOW, NULL, entry_yellow, MMI_FRM_FULL_SCRN))
    {
        kal_prompt_trace(MOD_MMI, "[SG] show yellow");
    }    
}
mmi_ret  prohibit_screen_enter_test1(void *para)
{
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
#endif
    return MMI_RET_OK;
}

mmi_ret prohibit_screen_enter_test2(void *para)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    return MMI_RET_OK;
}
MMI_BOOL is_deinit = MMI_FALSE;
mmi_ret create_close_proc(mmi_event_struct *event)
{
    //if (event->evt_id == EVT_ID_GROUP_DEINIT)
    {
        is_deinit = MMI_TRUE;
    }
    return MMI_RET_OK;
}

mmi_ret  create_close_test(void *para)
{
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_RED, create_close_proc, NULL);
    mmi_frm_group_close(GRP_ID_RED);
    MMI_ASSERT(is_deinit == MMI_TRUE);
    return MMI_RET_OK;
}

mmi_ret scenario_multiple_close_test(void *para)
{
    //scenario_multiple_close_test
    return MMI_RET_OK;
}

MMI_BOOL is_in_end_key = MMI_FALSE;

mmi_ret end_key_in_idle_proc(mmi_event_struct *evt)
{
    if (evt->evt_id == EVT_ID_SCRN_GOBACK_IN_END_KEY)
    {
        is_in_end_key = MMI_TRUE;
    }
    return MMI_RET_OK;
}
mmi_ret end_key_in_idle_group(void *para)
{
    MMI_ID active_group;
    MMI_ID active_scrn_id;
    MMI_ID  root_group_id;
    mmi_frm_close_to_idle_group();
    active_group = mmi_frm_group_get_active_id();
    active_scrn_id = mmi_frm_scrn_get_active_id();
    mmi_frm_scrn_enter(active_group, 100, NULL, NULL, MMI_FRM_FULL_SCRN);
    MMI_ASSERT(100 == mmi_frm_scrn_get_active_id());
    mmi_frm_scrn_set_leave_proc(active_group, 100, end_key_in_idle_proc);
    root_group_id = mmi_frm_group_get_top_parent_group_id(active_group);
    mmi_frm_close_to_root_screen(root_group_id);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == active_scrn_id);
    MMI_ASSERT(is_in_end_key == MMI_TRUE);
    is_in_end_key = MMI_FALSE;
    return MMI_RET_OK;
}

void empty_group_check(void *arg)
{
	U32 b = (U32)arg;
	if (b == 1)
	{
		MMI_ASSERT(mmi_frm_group_is_present(1000) == MMI_FALSE);;
		kal_prompt_trace(MOD_MMI,"[SG_UT] empty group close, test case1 Pass");
	}
	else if (b == 2)
	{
		//MMI_ASSERT(mmi_frm_group_is_present(1000) == MMI_TRUE);
		mmi_frm_group_create(1000, 1001, NULL, NULL);
		mmi_frm_group_enter(1001, MMI_FRM_NODE_NONE_FLAG);

		StartTimerEx(12, 10, empty_group_check, (void *)3);
	}
	else if (b == 3)
	{
		//MMI_ASSERT(mmi_frm_group_is_present(1000) == MMI_TRUE);
		kal_prompt_trace(MOD_MMI,"[SG_UT] empty group close, test case2 Pass");
	}
	else if (b == 4)
	{
		MMI_ASSERT(mmi_frm_group_is_present(1000) == MMI_TRUE);;
		kal_prompt_trace(MOD_MMI,"[SG_UT] empty group close, test case13 Pass");
	}
}
mmi_ret empty_group_close_test1(void *para)
{
	is_need_back_to_idle = MMI_FALSE;
	mmi_frm_close_to_idle_group();
	mmi_frm_group_create(GRP_ID_ROOT, 1000, NULL, NULL);
	mmi_frm_group_enter(1000, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	mmi_frm_group_create(GRP_ID_ROOT, 1001, NULL, NULL);
	mmi_frm_group_enter(1001, MMI_FRM_NODE_NONE_FLAG);
	mmi_frm_group_close(1001);
	StartTimerEx(10, 10,  empty_group_check, (void *)1);
	return MMI_RET_OK;
}
mmi_ret empty_group_close_test2(void *para)
{
	mmi_frm_close_to_idle_group();
	mmi_frm_group_create(GRP_ID_ROOT, 1000, NULL, NULL);
	mmi_frm_group_enter(1000, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	StartTimerEx(11, 10, empty_group_check, (void *)2);
	return MMI_RET_OK;
}

mmi_ret empty_group_close_test3(void *para)
{
	mmi_frm_close_to_idle_group();
	mmi_frm_group_create(GRP_ID_ROOT, 1000, NULL, NULL);
	mmi_frm_group_enter(1000, MMI_FRM_NODE_NONE_FLAG);
	mmi_frm_group_create(GRP_ID_ROOT, 1001, NULL, NULL);
	mmi_frm_group_enter(1001, MMI_FRM_NODE_NONE_FLAG);
	mmi_frm_group_close(1001);
	StartTimerEx(10, 10,  empty_group_check, (void *)4);
	return MMI_RET_OK;
}
static MMI_BOOL g_is_active = MMI_FALSE;
void set_active_entry(void)
{
    g_is_active = MMI_TRUE;
}
mmi_ret set_active_group_test(void *para)
{
    mmi_frm_close_to_idle_group();
    mmi_frm_group_create(GRP_ID_ROOT, 1000, NULL, NULL);
    mmi_frm_group_enter(1000, 0);
    mmi_frm_group_create(1000, 1500, NULL, NULL);
    mmi_frm_group_enter(1500, 0);
    mmi_frm_scrn_enter(1500, 100, NULL, set_active_entry, MMI_FRM_FULL_SCRN);
    mmi_frm_group_create(GRP_ID_ROOT, 1100, NULL, NULL);
    mmi_frm_group_enter(1100, 0);
    g_is_active = MMI_FALSE;
    mmi_frm_set_active_group(1000);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 1500);
    MMI_ASSERT(mmi_frm_group_is_in_active_serial(1000) == MMI_TRUE);
    MMI_ASSERT(IsScreenPresent(1000) == MMI_FALSE);
    MMI_ASSERT(GetCurrScrnId() == 1100);
    MMI_ASSERT(is_top_history_node(1000) == MMI_TRUE);
    MMI_ASSERT(g_is_active == MMI_TRUE);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 100);
	mmi_frm_set_active_group(1000);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 1500);
    MMI_ASSERT(mmi_frm_group_is_in_active_serial(1000) == MMI_TRUE);
    MMI_ASSERT(IsScreenPresent(1000) == MMI_FALSE);
    MMI_ASSERT(GetCurrScrnId() == 1100);
    MMI_ASSERT(is_top_history_node(1000) == MMI_TRUE);
    MMI_ASSERT(g_is_active == MMI_TRUE);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 100);
	kal_prompt_trace(MOD_MMI, "[SG_UT] test set active group pass");
	return MMI_RET_OK;
}

void enter20100607_1(void)
{
	mmi_frm_scrn_enter(1000, 1001, NULL, enter20100607_1, MMI_FRM_FULL_SCRN);
}
void enter20100607_2(void)
{
	mmi_frm_scrn_enter(1000, 1002, NULL, enter20100607_2, MMI_FRM_FULL_SCRN);
	mmi_frm_scrn_close(1000, 1001);
	mmi_frm_scrn_close(1000, 1002);
}
mmi_ret leave_proc20100607(mmi_event_struct *evt)
{
	if (evt->evt_id == EVT_ID_SCRN_DEINIT)
	{
        mmi_popup_display_simple((WCHAR*)((UI_string_type)get_string(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE)), MMI_EVENT_INFO, GRP_ID_ROOT, NULL);
	
	}
	return MMI_RET_OK;
}

mmi_ret show_popup_in_deinit(void *para)
{
    mmi_frm_close_to_idle_group();
	mmi_frm_group_create(GRP_ID_ROOT, 1000, NULL, NULL);
	mmi_frm_group_enter(1000, 0);
	mmi_frm_scrn_enter(1000, 1001, NULL, enter20100607_1, MMI_FRM_FULL_SCRN);
	mmi_frm_scrn_set_leave_proc(1000, 1001, leave_proc20100607);
	mmi_frm_scrn_enter(1000, 1002, NULL, enter20100607_2, MMI_FRM_FULL_SCRN);
	
	EntryNewScreen(2000, NULL, NULL, NULL);
	GoBackHistory();
	kal_prompt_trace(MOD_MMI, "show popup in deinit test PASS");
	return MMI_RET_OK;
}

mmi_ret group_proc_201000607(mmi_event_struct *evt)
{
	if (evt->evt_id == EVT_ID_GROUP_DEINIT)
	{
		mmi_frm_group_close(1000);
	}
	return MMI_RET_OK;
}

mmi_ret close_group_in_deinit(void *para)
{
    mmi_frm_close_to_idle_group();
	mmi_frm_group_create(GRP_ID_ROOT, 1000, NULL, NULL);
	mmi_frm_group_enter(1000, 0);
	mmi_frm_group_create(GRP_ID_ROOT, 1001, NULL, NULL);
	mmi_frm_group_enter(1001, 0);
	mmi_frm_group_create(GRP_ID_ROOT, 1002, group_proc_201000607, NULL);
	mmi_frm_group_enter(1002, 0);
	mmi_frm_close_to_idle_group();
	return MMI_RET_OK;
}



void enter_20100610_1(void)
{
	mmi_frm_scrn_enter(1000, 1000, NULL, enter_20100610_1, MMI_FRM_FULL_SCRN);

}

void enter_20100301_3(void)
{
	MMI_BOOL ret;
	ret = mmi_frm_scrn_enter(5000, 6000, NULL, enter_20100301_3, MMI_FRM_FULL_SCRN);
	if (ret == MMI_TRUE)
	{
		kal_prompt_trace(MOD_MMI, "[SG]scrn  6000 active\n");
	}
}
void enter_20100301_4(void)
{
	MMI_BOOL ret;
	ret = mmi_frm_scrn_enter(7000, 7000, NULL, enter_20100301_4, MMI_FRM_FULL_SCRN);
	if (ret == MMI_TRUE)
	{
		kal_prompt_trace(MOD_MMI, "[SG]scrn  7000 active\n");
	}
}
mmi_ret proc_201006(mmi_event_struct *evt)
{
	mmi_scenario_evt_struct *s_evt = (mmi_scenario_evt_struct *)evt;
	if (evt->evt_id == EVT_ID_GROUP_ACTIVE)
	{
		kal_prompt_trace(MOD_MMI, "[SG]group  %d  active\n", s_evt->targ_group);
	}
	return MMI_RET_OK;

}

void enter_20100601_2(void)
{
	mmi_frm_scrn_enter(2000, 2000, NULL, enter_20100601_2, MMI_FRM_FULL_SCRN);
	mmi_frm_group_create(2000, 4000, NULL, NULL);
	mmi_frm_group_enter(4000, 0);
	mmi_frm_group_create(4000, 5000, proc_201006, NULL);
	mmi_frm_group_enter(5000, 0);
	mmi_frm_scrn_first_enter(5000, 6000, enter_20100301_3, NULL);
	mmi_frm_group_create(5000, 7000, proc_201006, NULL);
	mmi_frm_group_enter(7000, 0);
	mmi_frm_scrn_first_enter(7000, 7000, enter_20100301_4, NULL);
	mmi_frm_group_close(7000);
}


mmi_ret  MAUI_02118353(void *para) 
{
    mmi_frm_close_to_idle_group();
	mmi_frm_group_create(GRP_ID_ROOT, 1000, NULL, NULL);
	mmi_frm_group_enter(1000, 0);
	mmi_frm_scrn_enter(1000, 1000, NULL, enter_20100610_1, MMI_FRM_FULL_SCRN);
	mmi_frm_group_create(GRP_ID_ROOT, 2000, NULL, NULL);
	mmi_frm_group_enter(2000, 0);
	mmi_frm_scrn_enter(2000, 2000, NULL, enter_20100601_2, MMI_FRM_FULL_SCRN);
	mmi_frm_group_create(2000, 3000, NULL, NULL);
	mmi_frm_group_enter(3000, 0);
	mmi_frm_group_close(3000);
	kal_prompt_trace(MOD_MMI, "[SG] MAUI_02118353 pass");
	return MMI_RET_OK;
}

void entry_proc_maui_02216247(void)
{
	MMI_BOOL ret;
	ret = mmi_frm_scrn_enter(1000, 1000, NULL, entry_proc_maui_02216247, MMI_FRM_FULL_SCRN);
	if (ret == MMI_TRUE)
	{
		//kal_printf("[SG]scrn_enter return true\n");
	}
	else
	{
		//kal_printf("[SG]scrn_enter return false\n");
	}
}
mmi_ret group_proc_maui_02216247(mmi_event_struct *evt)
{
	switch (evt->evt_id)
	{
	case EVT_ID_GROUP_ENTER:
		{
			mmi_frm_scrn_first_enter(1000, 1000, entry_proc_maui_02216247, NULL);
		}
		break;
	}
	return MMI_RET_OK;
}

mmi_ret MAUI_02216247(void *para)
{
    
	mmi_frm_close_to_idle_group();
	mmi_frm_group_create(GRP_ID_ROOT, 1000, group_proc_maui_02216247, NULL);
	mmi_frm_group_enter(1000, 0);
	MMI_ASSERT(mmi_frm_scrn_get_active_id() == 1000);
	kal_prompt_trace(MOD_MMI, "[SG] MAUI_02216247 pass");
	return MMI_RET_OK;
}
void entry_proc_maui_02304522(void)
{
	MMI_BOOL ret;
	ret = mmi_frm_scrn_enter(2000, 3000, NULL, entry_proc_maui_02304522, MMI_FRM_FULL_SCRN);
	if (ret == MMI_TRUE)
	{
		//kal_printf("[SG]scrn_enter return true\n");
	}
	else
	{
		//kal_printf("[SG]scrn_enter return false\n");
	}
}
mmi_ret group_proc_maui_02304522(mmi_event_struct *evt)
{
	switch (evt->evt_id)
	{
	case EVT_ID_GROUP_ENTER:
		{
			mmi_frm_group_create(1000, 2000, NULL, NULL);
			mmi_frm_group_enter(2000, 0);
			mmi_frm_scrn_first_enter(2000, 3000, entry_proc_maui_02304522, NULL);
		}
		break;
	}
	return MMI_RET_OK;
}
mmi_ret MAUI_02304522(void *para)
{
	mmi_frm_close_to_idle_group();
	mmi_frm_group_create(GRP_ID_ROOT, 1000, group_proc_maui_02304522, NULL);
	mmi_frm_group_enter(1000, 0);
	MMI_ASSERT(mmi_frm_scrn_get_active_id() == 3000);
	kal_prompt_trace(MOD_MMI, "[SG] MAUI_02304522 pass");
	return MMI_RET_OK;
}

mmi_ret group_set_user_data_test_proc(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}

mmi_ret group_set_user_data_test(void *para)
{
    U32 i;
    MMI_ID p_id = GRP_ID_ROOT;
    mmi_group_event_struct evt;
	MMI_FRM_INIT_GROUP_EVENT(&evt, 0, 0);
    mmi_frm_close_to_idle_group();
	mmi_frm_group_create(GRP_ID_ROOT, 100, NULL, NULL);
	MMI_ASSERT(mmi_frm_send_event_to_group(100, &evt) == MMI_RET_ERR);
    MMI_ASSERT(mmi_frm_post_event_to_group(100, &evt) == MMI_RET_ERR);
    MMI_ASSERT(mmi_frm_send_event_to_group(5000, &evt) == MMI_RET_ERR);
    MMI_ASSERT(mmi_frm_post_event_to_group(5000, &evt) == MMI_RET_ERR);
    for (i = 0; i < 10; i++)
    {
        p_id = mmi_frm_group_create(p_id, 1000 + i, group_set_user_data_test_proc, NULL);
        mmi_frm_group_set_user_data(p_id, (void *)(1234 + i));
        MMI_ASSERT(mmi_frm_send_event_to_group(p_id, &evt) == MMI_RET_OK);
        MMI_ASSERT(mmi_frm_post_event_to_group(p_id, &evt) == MMI_RET_OK);
        MMI_ASSERT(mmi_frm_group_get_user_data(p_id) == (void *)(1234 + i));
        mmi_frm_group_enter(p_id, 0);
        mmi_frm_group_set_user_data(p_id, (void *)(1234 + 2 * i));
        MMI_ASSERT(mmi_frm_group_get_user_data(p_id) == (void *)(1234 + 2 * i));
        MMI_ASSERT(mmi_frm_send_event_to_group(p_id, &evt) == MMI_RET_OK);
        MMI_ASSERT(mmi_frm_post_event_to_group(p_id, &evt) == MMI_RET_OK);       
    }
	kal_prompt_trace(MOD_MMI, "[SG]group_set user data test Pass");
	return MMI_RET_OK;
}

mmi_ret enter_screen_after_group_proc(mmi_event_struct *evt)
{
	mmi_scenario_evt_struct *s_evt = (mmi_scenario_evt_struct *)evt;
	switch (evt->evt_id)
	{
	case EVT_ID_GROUP_ACTIVE:
		kal_prompt_trace(MOD_MMI, "EVT_ID_GROUP_ACTIVE, %d", s_evt->targ_group);
		break;
	case EVT_ID_GROUP_INACTIVE:
		kal_prompt_trace(MOD_MMI, "EVT_ID_GROUP_INACTIVE, %d", s_evt->targ_group);
		break;
	case EVT_ID_GROUP_FOCUSED:
		kal_prompt_trace(MOD_MMI, "EVT_ID_GROUP_FOCUSED, %d", s_evt->targ_group);
		break;
	case EVT_ID_GROUP_DEFOCUSED:
		kal_prompt_trace(MOD_MMI, "EVT_ID_GROUP_DEFOCUSED, %d", s_evt->targ_group);

		break;
	default:
		break;
	}

	return MMI_RET_OK;
}

void enter_screen_after_group_entry(void)
{
	if (MMI_TRUE == mmi_frm_scrn_enter(1000, 3000, NULL, enter_screen_after_group_entry, MMI_FRM_FULL_SCRN))
	{
		kal_prompt_trace(MOD_MMI, "enter 1000, 3000");
	}

}
mmi_ret enter_screen_after_group(void *para)
{
	mmi_frm_close_to_idle_group();
	mmi_frm_group_create(GRP_ID_ROOT, 1000, enter_screen_after_group_proc, NULL);
	mmi_frm_group_enter(1000, 0);
	mmi_frm_group_create(1000, 2000, enter_screen_after_group_proc, NULL);
	mmi_frm_group_enter(2000, 0);
	enter_screen_after_group_entry();
	kal_prompt_trace(MOD_MMI, "enter_screen_after_group test PASS");
	return MMI_RET_OK;
}
void MAUI_02573189_entry_2(void)
{
	if (mmi_frm_scrn_enter(4000, 5000, NULL, MAUI_02573189_entry_2, MMI_FRM_FULL_SCRN) == MMI_TRUE)
	{
			kal_prompt_trace(MOD_MMI, "enter 4000 5000");
	}
}
void MAUI_02573189_entry_3(void)
{
	mmi_frm_scrn_enter(566, 230, NULL, MAUI_02573189_entry_3, MMI_FRM_FULL_SCRN);
}
void MAUI_02573189_entry(void)
{
	if (MMI_TRUE == mmi_frm_scrn_enter(2000, 3000, NULL, MAUI_02573189_entry, MMI_FRM_FULL_SCRN))
	{
		mmi_frm_scrn_enter(566, 230, NULL, MAUI_02573189_entry_3, MMI_FRM_FULL_SCRN);
		mmi_frm_group_create(2000, 4000, NULL, NULL);
		mmi_frm_group_enter(4000, 0);
		mmi_frm_scrn_first_enter(4000, 5000, MAUI_02573189_entry_2, NULL);
	}

}
mmi_ret MAUI_02573189(mmi_event_struct *evt)
{
	mmi_frm_close_to_idle_group();
	mmi_frm_group_create(GRP_ID_ROOT, 566, NULL, NULL);
	mmi_frm_group_enter(566, 0);
	mmi_frm_group_create(GRP_ID_ROOT, 1000, enter_screen_after_group_proc, NULL);
	mmi_frm_group_enter(1000, 0);
	mmi_frm_group_create(1000, 2000, enter_screen_after_group_proc, NULL);
	mmi_frm_group_enter(2000, 0);
	mmi_frm_scrn_enter(2000, 3000, NULL, MAUI_02573189_entry, MMI_FRM_FULL_SCRN);
	EntryNewScreen(10, NULL, NULL, NULL);
	GoBackHistory();
	MMI_ASSERT(shell.active_group->id == 4000);
	MMI_ASSERT((MMI_ID)shell.active_scrn->id == 5000);
	return MMI_RET_OK;
}
void *p;
void MAUI_02220671_entry1(void)
{
	if(MMI_TRUE == mmi_frm_scrn_enter(1001, 2000, NULL, MAUI_02220671_entry1, MMI_FRM_FULL_SCRN))
	{
		kal_prompt_trace(MOD_MMI, "enter 1003 2000");
		p = mmi_frm_scrmem_alloc(100);
	}

}
void MAUI_02220671_entry3(void)
{
	if (MMI_TRUE == mmi_frm_scrn_enter(1003, 2003, NULL, MAUI_02220671_entry3, MMI_FRM_FULL_SCRN))
	{
		kal_prompt_trace(MOD_MMI, "enter 1003 2003");
	}
}
mmi_ret MAUI_02220671_proc(mmi_event_struct *evt)
{
	if (evt->evt_id == EVT_ID_GROUP_ACTIVE)
	{
		kal_prompt_trace(MOD_MMI, "group 1003 active");
		
	}
	return MMI_RET_OK;
}
mmi_ret MAUI_02220671_timer(mmi_event_struct *evt)
{
	mmi_frm_close_to_idle_group();
	return MMI_RET_OK;
}
void MAUI_02220671_entry2(void)
{
	//if (MMI_TRUE == mmi_frm_scrn_enter(1002, 2001, NULL, MAUI_02220671_entry2, MMI_FRM_FULL_SCRN))

	mmi_event_struct evt;
	mmi_frm_group_create(1000, 1003, MAUI_02220671_proc, NULL);
	mmi_frm_group_enter(1003, 0);
	mmi_frm_scrn_first_enter(1003, 2003, MAUI_02220671_entry3, NULL);
	MMI_FRM_INIT_EVENT(&evt, 0);
	MMI_FRM_POST_EVENT(&evt, MAUI_02220671_timer, NULL);
	//gui_start_timer(0, MAUI_02220671_timer);
}
void MAUI_02220671_exit1(void)
{
	kal_prompt_trace(MOD_MMI, "exit 1001 2000");
	mmi_frm_scrmem_free(p);
	p = NULL;
}
mmi_ret MAUI_02220671(mmi_event_struct *evt)
{
	mmi_frm_close_to_idle_group();
	mmi_frm_group_create(GRP_ID_ROOT, 1000, NULL, NULL);
	mmi_frm_group_enter(1000, 0);
	mmi_frm_group_create(1000, 1001, NULL, NULL);
	mmi_frm_group_enter(1001, 0);
	p = mmi_frm_scrmem_alloc(100);
	mmi_frm_scrn_enter(1001, 2000, MAUI_02220671_exit1, MAUI_02220671_entry1, MMI_FRM_FULL_SCRN);
	mmi_frm_group_create(1000, 1002, NULL, NULL);
	mmi_frm_group_enter(1002, 1);
	mmi_frm_scrn_enter(1002, 2001, NULL, MAUI_02220671_entry2, MMI_FRM_FULL_SCRN);
	EntryNewScreen(10, NULL, NULL, NULL);
	GoBackHistory();
	kal_prompt_trace(MOD_MMI, "MAUI_02220671 Pass");
	return MMI_RET_OK;
}

void first_enter_post_case_entry2(void)
{
	mmi_frm_scrn_enter(1000, 4000, NULL, first_enter_post_case_entry2, MMI_FRM_FULL_SCRN);
}
void first_enter_post_case_entry1(void)
{
	mmi_frm_scrn_enter(1000, 2000, NULL, first_enter_post_case_entry1, MMI_FRM_FULL_SCRN);
	mmi_frm_scrn_first_enter(1000, 4000, first_enter_post_case_entry2, NULL);
}

mmi_ret first_enter_post_case(mmi_event_struct *evt)
{
	mmi_frm_group_create(GRP_ID_ROOT, 1000, NULL, NULL);
	mmi_frm_group_enter(1000, 0);
	mmi_frm_scrn_enter(1000, 2000, NULL, first_enter_post_case_entry1, MMI_FRM_FULL_SCRN);
	mmi_frm_scrn_enter(1000, 3000, NULL, NULL, MMI_FRM_FULL_SCRN);
	mmi_frm_scrn_close(1000, 3000);
	return MMI_RET_OK;
}
void MAUI_02312790_entry2(void)
{
	MMI_ASSERT(IsBitSet(shell.state, MMI_SCENARIO_STATE_BACKWARD_IDX) == 0);
	mmi_frm_scrn_enter(2000, 4000, NULL, MAUI_02312790_entry2, MMI_FRM_FULL_SCRN);
}
void MAUI_02312790_entry1(void)
{
	if (MMI_TRUE == mmi_frm_scrn_enter(2000, 3000, NULL, MAUI_02312790_entry1, MMI_FRM_FULL_SCRN))
	{
		mmi_frm_scrn_first_enter(2000, 4000, MAUI_02312790_entry2, NULL);
	}
}

mmi_ret MAUI_02312790_proc1(mmi_event_struct *evt)
{
	if (evt->evt_id == EVT_ID_SCRN_DEINIT)
	{
		mmi_frm_scrn_close(5000, 200);
	}
	return MMI_RET_OK;
}

void MAUI_02312790_entry3(void)
{
	mmi_frm_scrn_enter(5000, 100, NULL, MAUI_02312790_entry3, MMI_FRM_FULL_SCRN);
}
void MAUI_02312790_entry4(void)
{
	mmi_frm_scrn_enter(5000, 200, NULL, MAUI_02312790_entry4, MMI_FRM_FULL_SCRN);
}

mmi_ret MAUI_02312790(mmi_event_struct *evt)
{
	mmi_frm_group_create(GRP_ID_ROOT, 1000, NULL, NULL);
	mmi_frm_group_enter(1000, 0);
	mmi_frm_group_create(1000, 2000, NULL, NULL);
	mmi_frm_group_enter(2000, 0);
	mmi_frm_scrn_enter(2000, 3000, NULL, MAUI_02312790_entry1, MMI_FRM_FULL_SCRN);
	mmi_frm_group_create(1000, 5000, NULL, NULL);
	mmi_frm_group_enter(5000, 1);
	mmi_frm_scrn_enter(5000, 100, NULL, MAUI_02312790_entry3, MMI_FRM_FULL_SCRN);
	mmi_frm_scrn_set_leave_proc(5000, 100, MAUI_02312790_proc1);
	mmi_frm_scrn_enter(5000, 200, NULL, MAUI_02312790_entry4, MMI_FRM_FULL_SCRN);
	mmi_frm_scrn_close(5000, 100);
	return MMI_RET_OK;
}

MMI_BOOL is_go_back = MMI_FALSE;
mmi_ret MAUI_02316418_proc(mmi_event_struct *evt)
{
	if (evt->evt_id == EVT_ID_GROUP_ACTIVE && is_go_back == MMI_TRUE)
	{
		mmi_frm_group_close(2000);
		mmi_frm_group_create(1000, 3000, NULL, NULL);
		mmi_frm_group_enter(3000, 0);

	}
	return MMI_RET_OK;
}
mmi_ret MAUI_02316418(mmi_event_struct *evt)
{
	mmi_frm_close_to_idle_group();
	mmi_frm_group_create(GRP_ID_ROOT, 1000, MAUI_02316418_proc, NULL);
	mmi_frm_group_enter(1000, 0);
	mmi_frm_group_create(1000, 2000, NULL, NULL);
	mmi_frm_group_enter(2000, 0);
	is_go_back = MMI_TRUE;
	EntryNewScreen(100, NULL, NULL, NULL);
	GoBackHistory();
	is_go_back = MMI_FALSE;
	return MMI_RET_OK;
}

mmi_ret MAUI_02316329(mmi_event_struct *evt)
{
	mmi_frm_close_to_idle_group();
	mmi_frm_group_create(GRP_ID_ROOT, 1000, MAUI_02316418_proc, NULL);
	mmi_frm_group_enter(1000, 0);
	mmi_frm_group_create(1000, 2000, NULL, NULL);
	EntryNewScreen(100, NULL, NULL, NULL);
	mmi_frm_group_enter(2000, 0);
	GoBackHistory();
	MMI_ASSERT(shell.active_group->id == 2000);
	kal_prompt_trace(MOD_MMI, "[SG_UT] MAUI_02316329 PASS");
	return MMI_RET_OK;
}

void MAUI_02313807_entry2(void)
{
	mmi_frm_scrn_enter(5000, 6000, NULL, MAUI_02313807_entry2, MMI_FRM_FULL_SCRN);
}
void MAUI_02313807_entry1(void)
{
    if (MMI_TRUE == mmi_frm_scrn_enter(2000, 3000, NULL, MAUI_02313807_entry1, MMI_FRM_FULL_SCRN))
    {
        mmi_frm_scrn_first_enter(5000, 6000, MAUI_02313807_entry2, NULL);
		MMI_ASSERT(mmi_frm_shell_is_in_backward_scenario() == MMI_TRUE);
		mmi_frm_group_create(GRP_ID_ROOT, 4000, NULL, NULL);
        mmi_frm_group_enter(4000, 0);
    }
}
mmi_ret MAUI_02313807(void *para)
{
    mmi_frm_close_to_idle_group();
    mmi_frm_group_create(GRP_ID_ROOT, 1000, NULL, NULL);
    mmi_frm_group_enter(1000, 0);
	mmi_frm_group_create(1000, 5000, NULL, NULL);
	mmi_frm_group_enter(5000, 0);
    mmi_frm_group_create(1000, 2000, NULL, NULL);
    mmi_frm_group_enter(2000, 0);
    mmi_frm_scrn_enter(2000, 3000, NULL, MAUI_02313807_entry1, MMI_FRM_FULL_SCRN);
    EntryNewScreen(100, NULL, NULL, NULL);
    GoBackHistory();
    return MMI_RET_OK;
}


mmi_ret group_hid_test1_proc(mmi_event_struct *evt)
{
    mmi_scenario_evt_struct *sevt = (mmi_scenario_evt_struct *)evt;
    switch (sevt->evt_id)
    {
        case EVT_ID_GROUP_ENTER:
            kal_prompt_trace(MOD_MMI, "EVT_ID_GROUP_ENTER %d", sevt->targ_group);
            break;
        case EVT_ID_GROUP_ACTIVE:
            kal_prompt_trace(MOD_MMI, "EVT_ID_GROUP_ACTIVE %d", sevt->targ_group);
            break;
        case EVT_ID_GROUP_INACTIVE:
            kal_prompt_trace(MOD_MMI, "EVT_ID_GROUP_INACTIVE %d", sevt->targ_group);
            break;
        case EVT_ID_GROUP_FOCUSED:
            kal_prompt_trace(MOD_MMI, "EVT_ID_GROUP_FOCUSED %d", sevt->targ_group);
            break;
        case EVT_ID_GROUP_DEFOCUSED:
            kal_prompt_trace(MOD_MMI, "EVT_ID_GROUP_DEFOCUSED %d", sevt->targ_group);
            break;
        case EVT_ID_GROUP_HIDE:
            kal_prompt_trace(MOD_MMI, "EVT_ID_GROUP_HIDE %d", sevt->targ_group);
            break;
        case EVT_ID_SCRN_HIDE:
            kal_prompt_trace(MOD_MMI, "EVT_ID_SCRN_HIDE %d %d", sevt->targ_group, sevt->targ_scrn);
            break;
		case EVT_ID_GROUP_UNHIDE:
			kal_prompt_trace(MOD_MMI, "EVT_ID_GROUP_UNHIDE %d", sevt->targ_group);
			break;
        case EVT_ID_SCRN_UNHIDE:
            kal_prompt_trace(MOD_MMI, "EVT_ID_SCRN_UNHIDE %d %d", sevt->targ_group, sevt->targ_scrn);
            break;
        default:
            break;
    }
    return MMI_RET_OK;
}

mmi_ret group_hide_test1_exit(mmi_scrn_essential_struct *data)
{
    kal_prompt_trace(MOD_MMI, "EVT_ID_SCRN_INACTIVE %d %d", data->group_id, data->scrn_id);
    return MMI_RET_OK;
}
mmi_ret group_hide_test1_entry(mmi_scrn_essential_struct *data)
{
    MMI_BOOL ret;
    ret = mmi_frm_scrn_enter(data->group_id,
            data->scrn_id, 
            (FuncPtr)group_hide_test1_exit, 
            (FuncPtr)group_hide_test1_entry, 
            MMI_FRM_FULL_SCRN);
    {
        static WCHAR str[100];
		mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
		kal_wsprintf(str, "group id = %d, scrn id = %d", data->group_id, data->scrn_id);
		ShowCategory61Screen((PU8)str, IMG_GLOBAL_EMPTY, NULL);
		SetKeyHandler(GoBackHistory, KEY_LSK, KEY_EVENT_UP);
		kal_prompt_trace(MOD_MMI, "EVT_ID_SCRN_ACTIVE %d %d", data->group_id, data->scrn_id);
    }
    return MMI_RET_OK;
}
mmi_ret mmi_xxx_dummy_proc(mmi_event_struct *in)
{
	return MMI_RET_OK;
}
mmi_ret group_hide_test1(void *para)
{
	mmi_group_node_struct  node;
    mmi_frm_close_to_idle_group();
	mmi_frm_group_create(GRP_ID_ROOT, 100, group_hid_test1_proc, NULL);
	mmi_frm_group_enter(100, 0);
    mmi_frm_scrn_first_enter(100, 1000, (FuncPtr)group_hide_test1_entry, NULL);
	mmi_frm_scrn_set_leave_proc(100, 1000, group_hid_test1_proc);
    mmi_frm_group_create(100, 200, group_hid_test1_proc, NULL);
    mmi_frm_group_enter(200, 0);
    mmi_frm_scrn_first_enter(200, 1001, (FuncPtr)group_hide_test1_entry, NULL);
	mmi_frm_scrn_set_leave_proc(200, 1001, group_hid_test1_proc);
    mmi_frm_group_create(100, 300, group_hid_test1_proc, NULL);
    mmi_frm_group_enter(300, 0);
    mmi_frm_scrn_first_enter(300, 1002, (FuncPtr)group_hide_test1_entry, NULL);
	mmi_frm_scrn_set_leave_proc(300, 1002, group_hid_test1_proc);
    mmi_frm_group_create(300, 400, group_hid_test1_proc, NULL);
    mmi_frm_group_enter(400, 0);
    mmi_frm_scrn_first_enter(400, 1003, (FuncPtr)group_hide_test1_entry, NULL);
	mmi_frm_scrn_set_leave_proc(400, 1003, group_hid_test1_proc);
    mmi_frm_scrn_first_enter(400, 1004, (FuncPtr)group_hide_test1_entry, NULL);
	mmi_frm_scrn_set_leave_proc(400, 1004, group_hid_test1_proc);
	mmi_frm_group_set_caller(400, 300);
	mmi_frm_group_set_caller_proc(400, mmi_xxx_dummy_proc, (void *)0x5555);
	mmi_frm_group_get_info(400, &node);

	MMI_ASSERT(node.caller_proc == mmi_xxx_dummy_proc);
    MMI_ASSERT(node.caller_user_data == (void *)0x5555);
	
	kal_prompt_trace(MOD_MMI, "group_hide start");
    mmi_frm_group_hide(100);
    
	mmi_frm_group_set_caller_proc(400, mmi_xxx_dummy_proc, (void *)0x6666);
	mmi_frm_group_get_info(400, &node);
	MMI_ASSERT(node.caller_user_data == (void *)0x6666);
    MMI_ASSERT(mmi_frm_scrn_get_neighbor_id(400, 0, MMI_FRM_NODE_AT_BEGINNING_FLAG) == 1003);
    MMI_ASSERT(mmi_frm_scrn_get_neighbor_id(400, 0, MMI_FRM_NODE_AT_LATEST_FLAG) == 1004);
    MMI_ASSERT(mmi_frm_scrn_get_neighbor_id(400, 1004, MMI_FRM_NODE_BEFORE_FLAG) == 1003);
    MMI_ASSERT(mmi_frm_scrn_get_neighbor_id(400, 1003, MMI_FRM_NODE_AFTER_FLAG) == 1004);
	MMI_ASSERT(mmi_frm_is_asm_allocator(100) == MMI_TRUE);
	MMI_ASSERT(mmi_frm_is_asm_allocator(200) == MMI_TRUE);
	kal_prompt_trace(MOD_MMI, "group_unhide start");
    mmi_frm_group_unhide(100);
    kal_prompt_trace(MOD_MMI, "group_hide_test1 PASS");
    return MMI_RET_OK;
}

mmi_ret set_node_info(base_node_struct *node, void *arg)
{
    U32* node_count_p = (U32*)arg;
    (*node_count_p)++;
    node->priority = (U16)0xAA;
	return MMI_RET_OK;
}
mmi_ret check_node_info(base_node_struct *node, void *arg)
{
    U32* node_count_p = (U32*)arg;
    (*node_count_p)++;
    MMI_ASSERT(node->priority == (U16)0xAA);
	return MMI_RET_OK;
}

mmi_ret hide_group_in_history(void *para)
{
    group_node_struct* group_node;
    U32 node_count = 0,node_count_check = 0;

    mmi_frm_close_to_idle_group();
    mmi_frm_group_create(GRP_ID_ROOT, 250, group_hid_test1_proc, NULL);
	mmi_frm_group_create(GRP_ID_ROOT, 100, group_hid_test1_proc, NULL);
	mmi_frm_group_enter(100, 0);
    mmi_frm_scrn_first_enter(100, 1000, (FuncPtr)group_hide_test1_entry, NULL);
	mmi_frm_scrn_set_leave_proc(100, 1000, group_hid_test1_proc);
    mmi_frm_group_create(100, 200, group_hid_test1_proc, NULL);
    mmi_frm_group_enter(200, 0);
    mmi_frm_scrn_first_enter(200, 1001, (FuncPtr)group_hide_test1_entry, NULL);
	mmi_frm_scrn_set_leave_proc(200, 1001, group_hid_test1_proc);
    mmi_frm_group_create(100, 300, group_hid_test1_proc, NULL);
    mmi_frm_group_enter(300, 0);
    mmi_frm_scrn_first_enter(300, 1002, (FuncPtr)group_hide_test1_entry, NULL);
	mmi_frm_scrn_set_leave_proc(300, 1002, group_hid_test1_proc);
    mmi_frm_group_create(300, 400, group_hid_test1_proc, NULL);
    mmi_frm_group_enter(400, 0);
    mmi_frm_scrn_first_enter(400, 1003, (FuncPtr)group_hide_test1_entry, NULL);
	mmi_frm_scrn_set_leave_proc(400, 1003, group_hid_test1_proc);
    mmi_frm_scrn_first_enter(400, 1004, (FuncPtr)group_hide_test1_entry, NULL);
	mmi_frm_scrn_set_leave_proc(400, 1004, group_hid_test1_proc);
    EntryNewScreen(1234, NULL, NULL, NULL);
	kal_prompt_trace(MOD_MMI, "group_hide start");
    
    group_node = (group_node_struct *)SG_GET_NODE_FROM_ROOT(100);
    traverse_scenario_tree((base_node_struct *)group_node, set_node_info, set_node_info, NULL, (void*)&node_count);
    mmi_frm_group_hide(100);

    node_count_check = 0;
    traverse_scenario_tree((base_node_struct *)group_node, check_node_info, check_node_info, NULL, (void*)&node_count_check);
    MMI_ASSERT(node_count_check == node_count);

    MMI_ASSERT(MMI_SCENARIO_STATE_HIDE & mmi_frm_group_get_state(100));
    MMI_ASSERT(MMI_SCENARIO_STATE_HIDE & mmi_frm_scrn_get_state(100, 1000));
	MMI_ASSERT(mmi_frm_is_asm_allocator(100) == MMI_TRUE);
	MMI_ASSERT(mmi_frm_is_asm_allocator(200) == MMI_TRUE);
	kal_prompt_trace(MOD_MMI, "group_unhide start");
    mmi_frm_group_unhide(100);
    
    node_count_check = 0;
    traverse_scenario_tree((base_node_struct *)group_node, check_node_info, check_node_info, NULL, (void*)&node_count_check);
    MMI_ASSERT(MMI_SCENARIO_STATE_UNHIDE & mmi_frm_scrn_get_state(100, 1000));
    MMI_ASSERT(node_count_check == node_count);
    
    kal_prompt_trace(MOD_MMI, "hide_group_in_history PASS");
    return MMI_RET_OK;

}
mmi_ret SetBitCheck(void *para)
{
	U32 a = 0;
	S32 i;
	for (i = 0; i < 32; i++)
	{
		MMI_ASSERT(!IsBitSet(a, i));
		MMI_ASSERT(IsBitSet(a, i) == MMI_FALSE);
		MMI_ASSERT(IsBitReset(a, i));
		MMI_ASSERT(IsBitReset(a, i) == MMI_TRUE);
	}
	a = 0xFFFFFFFF;
	for (i = 0; i < 32; i++)
	{
		MMI_ASSERT(IsBitSet(a, i));
		MMI_ASSERT(IsBitSet(a, i) == MMI_TRUE);
		MMI_ASSERT(!IsBitReset(a, i));
		MMI_ASSERT(IsBitReset(a, i) == MMI_FALSE);
	}
	kal_prompt_trace(MOD_MMI, "SetBitCheck Pass");
    return MMI_RET_OK;
}

void tab_enter(void)
{
    mmi_frm_tab_struct tab_pages_info_array[2];

    tab_pages_info_array[0].screen_id = 0x1201;
    tab_pages_info_array[0].tab_entry_func = (FuncPtr)entry_category199_tab_01;
    tab_pages_info_array[0].tab_icon = (U8*)GetImage(gIndexIconsImageList[0]);
    tab_pages_info_array[0].tab_string = NULL;
    tab_pages_info_array[0].user_data = NULL;


    tab_pages_info_array[1].screen_id = 0x1202;
    tab_pages_info_array[1].tab_entry_func = (FuncPtr)entry_inline_tab_01;
    tab_pages_info_array[1].tab_icon = (U8*)GetImage(gIndexIconsImageList[1]);
    tab_pages_info_array[1].tab_string = NULL;
    tab_pages_info_array[1].user_data = NULL;

    mmi_frm_scrn_tab_enter (104, 106, NULL, tab_enter, tab_pages_info_array, 2, 0);    
}

void trace_test_entry(void)
{
}

mmi_ret trace_check(void *para)
{

    mmi_frm_close_to_idle_group();
    mmi_frm_group_create(GRP_ID_ROOT, 100, NULL, NULL);
    mmi_frm_group_enter(100, 0); //level 0
    mmi_frm_group_create(100, 101, NULL, NULL);
    mmi_frm_group_enter(101, 0); // level1
    mmi_frm_group_create(101, 102, NULL, NULL);
    mmi_frm_group_enter(102, 0); // level2
    mmi_frm_group_create(102, 103, NULL, NULL);
    mmi_frm_group_enter(103, 0); // level3
    mmi_frm_group_create(103, 104, NULL, NULL);
    mmi_frm_group_enter(104, 0); // level4
    mmi_frm_scrn_enter(104, 105, NULL, trace_test_entry, MMI_FRM_FULL_SCRN); // level5
	MMI_ASSERT(mmi_frm_get_root_app(104) == 100);
    tab_enter();
    HistoryDump();
    mmi_frm_group_hide(100);
	MMI_ASSERT(mmi_frm_get_root_app(104) == 100);

    HistoryDump();
    mmi_frm_group_unhide(100);
    HistoryDump();
   
	MMI_ASSERT(mmi_frm_get_root_app(1000) == 100);
    HistoryDump();
   
	return MMI_RET_OK;
}

mmi_frm_pair_data_struct a[] =
{
    {10, 10},
    {20, 20},
    {30, 30},
    {40, 40},
    {50, 50}
};


mmi_ret mmi_frm_binary_search_ex_test(void *para)
{
    U32 index = 255;
	MMI_ASSERT(MMI_FALSE == mmi_frm_binary_search_ex(5, a, ARRAYSIZE(a), &index));
	MMI_ASSERT(index == 0);
	
	index = 255;
	MMI_ASSERT(MMI_TRUE == mmi_frm_binary_search_ex(10, a, ARRAYSIZE(a), &index));
	MMI_ASSERT(index == 0);
	
	index = 255;
	MMI_ASSERT(MMI_TRUE == mmi_frm_binary_search_ex(15, a, ARRAYSIZE(a), &index));
	MMI_ASSERT(index == 0);
	
	index = 255;
	MMI_ASSERT(MMI_TRUE == mmi_frm_binary_search_ex(20, a, ARRAYSIZE(a), &index));
	MMI_ASSERT(index == 1);

	index = 255;
    MMI_ASSERT(MMI_TRUE == mmi_frm_binary_search_ex(25, a, ARRAYSIZE(a), &index));
    MMI_ASSERT(index == 1);

	index = 255;
	MMI_ASSERT(MMI_TRUE == mmi_frm_binary_search_ex(30, a, ARRAYSIZE(a), &index));
	MMI_ASSERT(index == 2);

	index = 255;
    MMI_ASSERT(MMI_TRUE == mmi_frm_binary_search_ex(35, a, ARRAYSIZE(a), &index));
    MMI_ASSERT(index == 2);

	index = 255;
	MMI_ASSERT(MMI_TRUE == mmi_frm_binary_search_ex(40, a, ARRAYSIZE(a), &index));
	MMI_ASSERT(index == 3);

	index = 255;
    MMI_ASSERT(MMI_TRUE == mmi_frm_binary_search_ex(45, a, ARRAYSIZE(a), &index));
    MMI_ASSERT(index == 3);

	index = 255;
	MMI_ASSERT(MMI_TRUE == mmi_frm_binary_search_ex(50, a, ARRAYSIZE(a), &index));
	MMI_ASSERT(index == 4);

	index = 255;
    MMI_ASSERT(MMI_TRUE == mmi_frm_binary_search_ex(55, a, ARRAYSIZE(a), &index));
    MMI_ASSERT(index == 4);

	kal_prompt_trace(MOD_MMI, "test mmi_frm_binary_search_ex PASS");
	return MMI_RET_OK;
}

mmi_ret find_free_slot_test(void *para)
{

    return MMI_RET_OK;
}


mmi_ret test_allocate_free_id_by_app_base(void *para)
{
    return MMI_RET_OK;    
}


MMI_BOOL _switch = MMI_FALSE;
mmi_ret back_to_idle_proc(mmi_event_struct *p)
{
	mmi_scenario_evt_struct *evt = (mmi_scenario_evt_struct *)p;
	print_evt_string(evt->evt_id);
	switch (evt->evt_id)
	{
		case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
			if (evt->targ_group == 566 && _switch)
			{
				return -1;
			}
			if (evt->targ_group == 600 && _switch)
			{
				return -1;
			}
			if (evt->targ_group == 1588 && _switch)
			{
				return -1;
			}
			if (evt->targ_group == 1599 && _switch)
			{
				return -1;
			}
			break;
		default:
			break;
	}
	return MMI_RET_OK;
}
mmi_ret back_to_idle_test1(void *para)
{
	mmi_frm_close_to_idle_group();
	_switch = MMI_TRUE;
	mmi_frm_group_create(GRP_ID_ROOT, 566, back_to_idle_proc, NULL);
	mmi_frm_group_enter(566, 0);
	mmi_frm_group_create(GRP_ID_ROOT, 577, back_to_idle_proc, NULL);
	mmi_frm_group_enter(577, 0);
	mmi_frm_close_to_idle_group();
	MMI_ASSERT(mmi_frm_group_is_present(566) == MMI_TRUE);
	MMI_ASSERT(mmi_frm_group_is_present(577) == MMI_FALSE);
	MMI_ASSERT(IsScreenPresent(577) == MMI_FALSE);
	_switch = MMI_FALSE;
	mmi_frm_close_to_idle_group();
	MMI_ASSERT(mmi_frm_group_is_present(566) == MMI_FALSE);
	mmi_frm_group_create(GRP_ID_ROOT, 588, back_to_idle_proc, NULL);
	mmi_frm_group_enter(588, 0);
	mmi_frm_group_create(GRP_ID_ROOT, 599, back_to_idle_proc, NULL);
	mmi_frm_group_enter(599, 0);
	mmi_frm_group_create(GRP_ID_ROOT, 600, back_to_idle_proc, NULL);
	mmi_frm_group_enter(600, 0);
	mmi_frm_group_create(GRP_ID_ROOT, 700, back_to_idle_proc, NULL);
	mmi_frm_group_enter(700, 0);
	_switch = MMI_TRUE;
	mmi_frm_close_to_idle_group();
	MMI_ASSERT(mmi_frm_group_is_present(588) == MMI_FALSE);
	MMI_ASSERT(mmi_frm_group_is_present(599) == MMI_FALSE);
	MMI_ASSERT(mmi_frm_group_is_present(600) == MMI_TRUE);
	MMI_ASSERT(mmi_frm_group_is_present(700) == MMI_FALSE);
	MMI_ASSERT(IsScreenPresent(700) == MMI_FALSE);
	MMI_ASSERT(mmi_frm_group_get_active_id() == 600);
	_switch = MMI_FALSE;
	mmi_frm_close_to_idle_group();
	mmi_frm_group_create(GRP_ID_ROOT, 1588, back_to_idle_proc, NULL);
	mmi_frm_group_enter(1588, 0);
	mmi_frm_group_create(GRP_ID_ROOT, 1599, back_to_idle_proc, NULL);
	mmi_frm_group_enter(1599, 0);
	mmi_frm_group_create(GRP_ID_ROOT, 1600, back_to_idle_proc, NULL);
	mmi_frm_group_enter(1600, 0);
	mmi_frm_group_create(GRP_ID_ROOT, 1700, back_to_idle_proc, NULL);
	mmi_frm_group_enter(1700, 0);
	_switch = MMI_TRUE;
	mmi_frm_close_to_idle_group();
	MMI_ASSERT(mmi_frm_group_is_present(1588) == MMI_TRUE);
	MMI_ASSERT(mmi_frm_group_is_present(1599) == MMI_TRUE);
	MMI_ASSERT(mmi_frm_group_is_present(1600) == MMI_FALSE);
	MMI_ASSERT(mmi_frm_group_is_present(1700) == MMI_FALSE);
	MMI_ASSERT(IsScreenPresent(1700) == MMI_FALSE);
	MMI_ASSERT(mmi_frm_group_get_active_id() == 1599);
	_switch = MMI_FALSE;
	return MMI_RET_OK;
}
mmi_ret hide_test2_proc(mmi_event_struct *evt)
{
    mmi_scenario_evt_struct *sevt = (mmi_scenario_evt_struct *)evt;
    switch (sevt->evt_id)
    {
        case EVT_ID_GROUP_ENTER:
            kal_prompt_trace(MOD_MMI, "EVT_ID_GROUP_ENTER %d", sevt->targ_group);
            break;
        case EVT_ID_GROUP_ACTIVE:
            kal_prompt_trace(MOD_MMI, "EVT_ID_GROUP_ACTIVE %d", sevt->targ_group);
            break;
        case EVT_ID_GROUP_INACTIVE:
            kal_prompt_trace(MOD_MMI, "EVT_ID_GROUP_INACTIVE %d", sevt->targ_group);
            break;
        case EVT_ID_GROUP_FOCUSED:
            kal_prompt_trace(MOD_MMI, "EVT_ID_GROUP_FOCUSED %d", sevt->targ_group);
            break;
        case EVT_ID_GROUP_DEFOCUSED:
            kal_prompt_trace(MOD_MMI, "EVT_ID_GROUP_DEFOCUSED %d", sevt->targ_group);
            break;
        case EVT_ID_GROUP_HIDE:
            kal_prompt_trace(MOD_MMI, "EVT_ID_GROUP_HIDE %d", sevt->targ_group);
            break;
        case EVT_ID_SCRN_HIDE:
            kal_prompt_trace(MOD_MMI, "EVT_ID_SCRN_HIDE %d %d", sevt->targ_group, sevt->targ_scrn);
            break;
		case EVT_ID_GROUP_UNHIDE:
			kal_prompt_trace(MOD_MMI, "EVT_ID_GROUP_UNHIDE %d", sevt->targ_group);
			break;
        case EVT_ID_SCRN_UNHIDE:
            kal_prompt_trace(MOD_MMI, "EVT_ID_SCRN_UNHIDE %d %d", sevt->targ_group, sevt->targ_scrn);
            break;
        default:
            break;
    }
    return MMI_RET_OK;

}

mmi_ret group_hide_test2_exit(mmi_scrn_essential_struct *data)
{
    kal_prompt_trace(MOD_MMI, "EVT_ID_SCRN_INACTIVE %d %d", data->group_id, data->scrn_id);
    return MMI_RET_OK;
}
mmi_ret group_hide_test2_entry(mmi_scrn_essential_struct *data)
{
    MMI_BOOL ret;
    ret = mmi_frm_scrn_enter(data->group_id,
            data->scrn_id, 
            (FuncPtr)group_hide_test1_exit, 
            (FuncPtr)group_hide_test1_entry, 
            MMI_FRM_FULL_SCRN);
    {
        static WCHAR str[100];
		mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
		kal_wsprintf(str, "group id = %d, scrn id = %d", data->group_id, data->scrn_id);
		ShowCategory61Screen((PU8)str, IMG_GLOBAL_EMPTY, NULL);
		SetKeyHandler(GoBackHistory, KEY_LSK, KEY_EVENT_UP);
		kal_prompt_trace(MOD_MMI, "EVT_ID_SCRN_ACTIVE %d %d", data->group_id, data->scrn_id);
    }
    return MMI_RET_OK;
}


mmi_ret group_hide_test2(void *para)
{
    mmi_frm_close_to_idle_group();
    mmi_frm_group_create(GRP_ID_ROOT, 100, hide_test2_proc, NULL);
    mmi_frm_group_enter(100, 0);
    mmi_frm_group_create(100, 200, hide_test2_proc, NULL);
    mmi_frm_group_enter(200, 0);
    mmi_frm_scrn_first_enter(200, 1000, (FuncPtr)group_hide_test2_entry, NULL);
    mmi_frm_scrn_set_leave_proc(200, 1000, hide_test2_proc);
    mmi_frm_scrn_first_enter(200, 2000, (FuncPtr)group_hide_test2_entry, NULL);
    mmi_frm_scrn_set_leave_proc(200, 2000, hide_test2_proc);
    mmi_frm_group_create(100, 300, hide_test2_proc, NULL);
    mmi_frm_group_enter(300, 0);
    mmi_frm_scrn_first_enter(300, 4000, (FuncPtr)group_hide_test2_entry, NULL);
    mmi_frm_scrn_set_leave_proc(300, 4000, hide_test2_proc);
    mmi_frm_scrn_first_enter(300, 5000, (FuncPtr)group_hide_test2_entry, NULL);
    mmi_frm_scrn_set_leave_proc(300, 5000, hide_test2_proc);

    mmi_frm_group_create(GRP_ID_ROOT, 2100, hide_test2_proc, NULL);
    mmi_frm_group_enter(2100, 0);
    mmi_frm_group_create(2100, 2200, hide_test2_proc, NULL);
    mmi_frm_group_enter(2200, 0);
    mmi_frm_scrn_first_enter(2200, 21000, (FuncPtr)group_hide_test2_entry, NULL);
    mmi_frm_scrn_set_leave_proc(2200, 21000, hide_test2_proc);
    mmi_frm_scrn_first_enter(2200, 22000, (FuncPtr)group_hide_test2_entry, NULL);
    mmi_frm_scrn_set_leave_proc(2200, 22000, hide_test2_proc);
    mmi_frm_group_create(2100, 2300, hide_test2_proc, NULL);
    mmi_frm_group_enter(2300, 0);
    mmi_frm_scrn_first_enter(2300, 24000, (FuncPtr)group_hide_test2_entry, NULL);
    mmi_frm_scrn_set_leave_proc(2300, 24000, hide_test2_proc);
    mmi_frm_scrn_first_enter(2300, 25000, (FuncPtr)group_hide_test2_entry, NULL);
    mmi_frm_scrn_set_leave_proc(2300, 25000, hide_test2_proc);
	kal_prompt_trace(MOD_MMI, "group_hide start");
    mmi_frm_group_hide(2100);
	kal_prompt_trace(MOD_MMI, "group_hide start");
	mmi_frm_group_hide(100);
	kal_prompt_trace(MOD_MMI, "group_unhide start");
    mmi_frm_group_unhide(100);
	kal_prompt_trace(MOD_MMI, "group_unhide start");
	mmi_frm_group_unhide(2100);
    kal_prompt_trace(MOD_MMI, "group_hide_test1 PASS");
    return MMI_RET_OK;
}
MMI_BOOL stop_delete = MMI_FALSE;
mmi_ret test_close_to_idle_with_start_id_proc(mmi_event_struct *evt)
{
    mmi_scenario_evt_struct *s_evt = (mmi_scenario_evt_struct*)evt;
    kal_prompt_trace(MOD_MMI, "group_id = %d, scrn_id = %d", s_evt->targ_group, s_evt->targ_scrn);
    print_evt_string(evt->evt_id);
    if (s_evt->targ_group == 300 && stop_delete) return -1;
    return MMI_RET_OK;
}
mmi_ret test_close_to_idle_with_start_id(void *para)
{
    mmi_frm_close_to_idle_group();
    mmi_frm_group_create(GRP_ID_ROOT, 100, test_close_to_idle_with_start_id_proc, NULL);
    mmi_frm_group_enter(100, 0);
    mmi_frm_group_create(100, 200, test_close_to_idle_with_start_id_proc, NULL);
    mmi_frm_group_enter(200, 0);
    mmi_frm_group_create(GRP_ID_ROOT, 300, test_close_to_idle_with_start_id_proc, NULL);
    mmi_frm_group_enter(300, 0);
    mmi_frm_group_create(300, 400, test_close_to_idle_with_start_id_proc, NULL);
    mmi_frm_group_enter(400, 0);
    mmi_frm_group_create(GRP_ID_ROOT, 1000, test_close_to_idle_with_start_id_proc, NULL);
    mmi_frm_group_enter(1000, 0);
    mmi_frm_group_create(GRP_ID_ROOT, 500, test_close_to_idle_with_start_id_proc, NULL);
    mmi_frm_group_enter(500, 0);
    stop_delete = MMI_TRUE;
    mmi_frm_close_to_idle_group_with_start_id(1000);
    stop_delete = MMI_FALSE;
    mmi_frm_close_to_idle_group();
    kal_prompt_trace(MOD_MMI, "test_close_to_idle_with_start_id test pass");
    return MMI_RET_OK;
}

mmi_ret test_hide_post_proc(mmi_event_struct *evt)
{
    if (evt->evt_id ==  EVT_ID_GROUP_GOBACK_IN_END_KEY)
    {
		mmi_frm_group_hide(100);
        return -1;
    }
    return MMI_RET_OK;
}
mmi_ret test_hide_post_case(void *para)
{
    mmi_frm_close_to_idle_group();
    mmi_frm_group_create(GRP_ID_ROOT, 100, test_hide_post_proc, NULL);
	mmi_frm_group_enter(100, 0);
    mmi_frm_close_to_idle_group();
    mmi_frm_group_create(GRP_ID_ROOT, 200, NULL, NULL);
    mmi_frm_group_enter(200, 0);
    mmi_frm_group_hide(200);
    MMI_ASSERT(mmi_frm_scrn_get_neighbor_id(GRP_ID_BK, 0, MMI_FRM_NODE_AT_BEGINNING_FLAG) == 100);
    MMI_ASSERT(mmi_frm_scrn_get_neighbor_id(GRP_ID_BK, 0, MMI_FRM_NODE_AT_LATEST_FLAG) == 200);
    MMI_ASSERT(mmi_frm_scrn_get_neighbor_id(GRP_ID_BK, 100, MMI_FRM_NODE_AFTER_FLAG) == 200);
    MMI_ASSERT(mmi_frm_scrn_get_neighbor_id(GRP_ID_BK, 200, MMI_FRM_NODE_BEFORE_FLAG) == 100);

    mmi_frm_group_unhide(100);
    mmi_frm_group_unhide(200);

    return MMI_RET_OK;
}

mmi_ret MAUI_02638067(void *para)
{
    mmi_frm_node_struct node;
    mmi_frm_close_to_idle_group();
    EntryNewScreen(100, NULL, NULL, NULL);
    node.id = 200;
    node.entry_proc = NULL;
    node.user_data = NULL;
    mmi_frm_group_insert(GRP_ID_ROOT, 100, &node, MMI_FRM_NODE_BEFORE_FLAG);
    return MMI_RET_OK;    
}

mmi_ret test_get_root_app_proc(mmi_event_struct *para)
{
    if (para->evt_id == EVT_ID_GROUP_DEINIT)
    {
        MMI_ASSERT(mmi_frm_get_root_app(200) == 100);
    }
    return MMI_RET_OK;
}

mmi_ret test_get_root_app(void *para)
{
    mmi_frm_close_to_idle_group();
    mmi_frm_group_create(GRP_ID_ROOT, 100, NULL, NULL);
    mmi_frm_group_enter(100, 0);
    mmi_frm_group_create(100, 200, test_get_root_app_proc, NULL);
    mmi_frm_group_enter(200, 0);
    mmi_frm_group_close(200);
	MMI_ASSERT(GRP_ID_INVALID == mmi_frm_get_root_app(GRP_ID_ROOT));
	MMI_ASSERT(GRP_ID_INVALID == mmi_frm_get_root_app(GRP_ID_DANGLE));
	MMI_ASSERT(GRP_ID_INVALID == mmi_frm_get_root_app(GRP_ID_BK));

	return MMI_RET_OK;
}

mmi_ret state_check(mmi_event_struct *evt)
{
    mmi_scenario_state_enum state;
    if (evt->evt_id == EVT_ID_GROUP_HIDE)
    {
        state = mmi_frm_group_get_state(100);
        MMI_ASSERT(state == 0x2002);
    }
    else if (evt->evt_id == EVT_ID_GROUP_UNHIDE)
    {
        state = mmi_frm_group_get_state(100);
        MMI_ASSERT(0x4802 == state);
    }
    return MMI_RET_OK;
}
mmi_ret group_hide_state_check(void *para)
{
    mmi_scenario_state_enum state;
    mmi_frm_close_to_idle_group();
    mmi_frm_group_create(GRP_ID_ROOT, 100, state_check, NULL);
    mmi_frm_group_enter(100, 0);
    state = mmi_frm_group_get_state(100);
    MMI_ASSERT(state == 0x8001);
    mmi_frm_group_hide(100);
    state = mmi_frm_group_get_state(100);
    MMI_ASSERT(state ==0x0802);
    mmi_frm_group_unhide(100);
	state = mmi_frm_group_get_state(100);
    MMI_ASSERT(state == 0x8001);
    return MMI_RET_OK;
}

mmi_ret group_hide_in_idle_check_proc(mmi_event_struct *evt)
{
    if (evt->evt_id ==  EVT_ID_GROUP_GOBACK_IN_END_KEY)
    {
        mmi_scenario_state_enum state;
		state = mmi_frm_group_get_state(100);
		MMI_ASSERT(state == 0x80A1);
		mmi_frm_group_hide(100);
        return MMI_RET_STOP_END_KEY_FLOW;
    }
    return MMI_RET_OK;
}

mmi_ret group_hide_in_idle_check(void *para)
{
	mmi_scenario_state_enum state;
	mmi_frm_close_to_idle_group();
    mmi_frm_group_create(GRP_ID_ROOT, 100, group_hide_in_idle_check_proc, NULL);
	mmi_frm_group_enter(100, 0);
    mmi_frm_close_to_idle_group();
	state = mmi_frm_group_get_state(100);
	MMI_ASSERT(state == 0x0802);
	mmi_frm_group_unhide(100);
	state = mmi_frm_group_get_state(100);
	MMI_ASSERT(state == 0x8001);

    mmi_frm_group_close(100);
	return MMI_RET_OK;
}

static U8 count_small_screen = 0;
void bk_exit(void)
{
    count_small_screen--;
}
void enter_bk_scrn(void)
{
    if (mmi_frm_scrn_enter(100, 1000, bk_exit, enter_bk_scrn, MMI_FRM_FULL_SCRN) == MMI_TRUE)
    {
        count_small_screen++;
    }
}
void enter_small_scrn(void)
{
    if (mmi_frm_scrn_enter(300, 2000, NULL, enter_small_scrn, MMI_FRM_SMALL_SCRN) == MMI_TRUE)
    {
        ShowCategoryDummySmallScreen();
    }

}
mmi_ret small_screen_check(void *para)
{
 	mmi_frm_close_to_idle_group();
    mmi_frm_group_create(GRP_ID_ROOT, 100, NULL, NULL);
    mmi_frm_group_enter(100, 0);
    enter_bk_scrn();
    mmi_frm_group_create(GRP_ID_ROOT, 200, NULL, NULL);
    mmi_frm_group_enter(200, 0);
    mmi_frm_group_create(200, 300, NULL, NULL);
    mmi_frm_group_enter(300, 0);
    enter_small_scrn();
    EntryNewScreen(20, NULL, NULL, NULL);
    GoBackHistory();
    MMI_ASSERT(count_small_screen == 0);
    return MMI_RET_OK;
}

mmi_ret group_close_in_bk_proc(mmi_event_struct *evt)
{
    print_evt_string(evt->evt_id);
    return MMI_RET_OK;
}

void group_close_in_bk_entry(void)
{
    mmi_frm_scrn_enter(200, 1000, NULL, group_close_in_bk_entry, MMI_FRM_FULL_SCRN);
    mmi_frm_scrn_set_leave_proc(200, 1000, group_close_in_bk_proc);
}
mmi_ret test_group_close_in_bg_tree(void *para)
{
 	mmi_frm_close_to_idle_group();
    mmi_frm_group_create(GRP_ID_ROOT, 100, group_close_in_bk_proc, NULL);
    mmi_frm_group_enter(100, 0);
    mmi_frm_group_create(100, 200, group_close_in_bk_proc, NULL);
    mmi_frm_group_enter(200, 0);
    group_close_in_bk_entry();
    mmi_frm_group_hide(100);
    MMI_ASSERT(mmi_frm_group_is_present(100) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_group_is_present(200) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_scrn_is_present(200, 1000, MMI_FRM_NODE_ALL_FLAG) == MMI_TRUE);
    mmi_frm_group_close(100);
    MMI_ASSERT(mmi_frm_group_is_present(100) == MMI_FALSE);
    MMI_ASSERT(mmi_frm_group_is_present(200) == MMI_FALSE);
    MMI_ASSERT(mmi_frm_scrn_is_present(200, 1000, MMI_FRM_NODE_ALL_FLAG) == MMI_FALSE);
    return MMI_RET_OK;
}

void show_small_screen(void)
{
    if (MMI_TRUE == mmi_frm_scrn_enter(200, 1000, NULL, show_small_screen, MMI_FRM_SMALL_SCRN))
    {
        ShowCategoryDummySmallScreen();
    }    
}
MMI_BOOL check = MMI_FALSE;
void _entry_MAUI_02640797(void)
{
    if (MMI_TRUE == mmi_frm_scrn_enter(400, 4000, NULL, _entry_MAUI_02640797, MMI_FRM_FULL_SCRN))
	{
		check = MMI_TRUE;
	}
}
mmi_ret MAUI_02640797(void *para)
{
    mmi_frm_node_struct node;
    mmi_frm_close_to_idle_group();
    mmi_frm_group_create(GRP_ID_ROOT, 100, NULL, NULL);
    mmi_frm_group_enter(100, 0);
    mmi_frm_group_create(GRP_ID_ROOT, 200, NULL, NULL);
    mmi_frm_group_enter(200, 0);
    show_small_screen();
    EntryNewScreen(300, NULL, NULL, NULL);
    mmi_frm_group_create(GRP_ID_ROOT, 400, NULL, NULL);
    node.id  = 400;
    node.entry_proc = NULL;
    node.user_data = NULL;
    mmi_frm_group_insert(GRP_ID_ROOT, 100, &node, MMI_FRM_NODE_AFTER_FLAG);
    mmi_frm_scrn_first_enter(400, 4000, _entry_MAUI_02640797, NULL);
    GoBackHistory();
    MMI_ASSERT(check == MMI_TRUE);
    check = MMI_FALSE;
    kal_prompt_trace(MOD_MMI, "MAUI_02640797 PASS");
	return MMI_RET_OK;
}

typedef struct
{
	MMI_ID evt_id;
	MMI_ID group_id;
	MMI_ID tab_id;
	MMI_ID scrn_id;
} check_item_struct;

typedef struct
{
	U16 type;
	MMI_ID parent_id;
	MMI_ID this_id;
} node_set_struct;

typedef void (*close_callback)(node_set_struct *tree, U16 size);
typedef struct
{
	node_set_struct *tree;
	close_callback callback;
	check_item_struct *expected_table;
	U16 tree_size;
	U16 evt_size;
} evt_flow_test_item_struct;



#define EVT_ITEM(evt_id, group_id, tab_id, scrn_id) \
	{evt_id, group_id, tab_id, scrn_id},

#define EVT_START(name) \
	check_item_struct name##evt[] = \
	{

#define EVT_END()\
	};
#define GET_EVT(name)\
	&name##evt[0]

#define GET_EVT_SIZE(name)\
	(sizeof(name##evt)/sizeof(name##evt[0]))

#define TEST_EVT_ITEM_START() \
	evt_flow_test_item_struct evt_flow_test_table[] = \
	{

#define TEST_EVT_ITEM_END() \
	};

#define TEST_EVT_ITEM(tree, close_cb, evt_flow) \
	{GET_TREE(tree), close_cb, GET_EVT(evt_flow), GET_TREE_SIZE(tree), GET_EVT_SIZE(evt_flow)},

#define TEST_NODE(type, parent_id, this_id) \
	{type, parent_id, this_id},

#define GET_TREE(name) \
	&name##tree[0]

#define GET_TREE_SIZE(name)\
	(sizeof(name##tree)/sizeof(name##tree[0]))

#define TREE_START(name) \
	node_set_struct name##tree[] = \
	{

#define TREE_END() \
	};

static check_item_struct record_buffer[500];
static U32 record_number = -1;
void desequence_close(node_set_struct *tree, U16 size);
TREE_START(tree1)
TEST_NODE(SCENARIO_GROUP_NODE, GRP_ID_ROOT, 1000)
TEST_NODE(SCENARIO_GROUP_NODE, GRP_ID_ROOT, 2000)
TREE_END()

EVT_START(tree1_sequence1)
EVT_ITEM(EVT_ID_GROUP_ENTER,     1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ACTIVE,    1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ENTER,     2000, 0, 0) //pay attention this
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE , 1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ACTIVE,    2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_GOBACK,    2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_EXIT,      2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEINIT,    2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ACTIVE,    1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_GOBACK,    1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_EXIT,      1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEINIT,    1000, 0, 0)
EVT_END()
void tree1_sequence1_close(node_set_struct *tree, U16 size)
{
	desequence_close(tree, size);
}


TREE_START(tree2)
TEST_NODE(SCENARIO_GROUP_NODE, GRP_ID_ROOT, 1000)
TEST_NODE(SCENARIO_GROUP_NODE, 1000,        2000)
TEST_NODE(SCENARIO_GROUP_NODE, 2000,        3000)
TREE_END()

EVT_START(tree2_sequence1)
EVT_ITEM(EVT_ID_GROUP_ENTER,     1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ACTIVE,    1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ENTER,     2000, 0, 0) //pay attention this
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ACTIVE,    2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ENTER,     3000, 0, 0) //pay attention this
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ACTIVE,    3000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   3000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_GOBACK,    3000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 3000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  3000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_EXIT,      3000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEINIT,    3000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   2000, 0, 0)
EVT_ITEM(EVT_ID_NO_CHILD_NOTIFY, 2000, 0, 0)


EVT_ITEM(EVT_ID_GROUP_GOBACK,    2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_EXIT,      2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEINIT,    2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   1000, 0, 0)
EVT_ITEM(EVT_ID_NO_CHILD_NOTIFY, 1000, 0, 0)


EVT_ITEM(EVT_ID_GROUP_GOBACK,    1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_EXIT,      1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEINIT,    1000, 0, 0)
EVT_END()

void tree2_sequence1_close(node_set_struct *tree, U16 size)
{
	desequence_close(tree, size);
}

EVT_START(tree2_sequence2)
EVT_ITEM(EVT_ID_GROUP_ENTER,     1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ACTIVE,    1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ENTER,     2000, 0, 0) //pay attention this
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ACTIVE,    2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ENTER,     3000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ACTIVE,    3000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   3000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_GOBACK,    2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_GOBACK,    3000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 3000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  3000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_EXIT,      3000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEINIT,    3000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_INACTIVE,  2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_EXIT,      2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEINIT,    2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   1000, 0, 0)
EVT_ITEM(EVT_ID_NO_CHILD_NOTIFY, 1000, 0, 0)


EVT_ITEM(EVT_ID_GROUP_GOBACK,    1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_EXIT,      1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEINIT,    1000, 0, 0)
EVT_END()

void tree2_sequence2_close(node_set_struct *tree, U16 size)
{
	mmi_frm_group_close(2000);
	mmi_frm_group_close(1000);
}

TREE_START(tree3)
TEST_NODE(SCENARIO_GROUP_NODE, GRP_ID_ROOT, 1000)
TEST_NODE(SCENARIO_GROUP_NODE, 1000,        2000)
TEST_NODE(SCENARIO_GROUP_NODE, 1000,        3000)
TREE_END()

EVT_START(tree3_sequence1)
EVT_ITEM(EVT_ID_GROUP_ENTER,     1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ACTIVE,    1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ENTER,     2000, 0, 0) //attention
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ACTIVE,    2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   2000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_ENTER,     3000, 0, 0) //attention
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ACTIVE,    3000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   3000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_GOBACK,    3000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 3000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  3000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_EXIT,      3000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEINIT,    3000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_ACTIVE,    2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   2000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_GOBACK,    2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_EXIT,      2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEINIT,    2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   1000, 0, 0)
EVT_ITEM(EVT_ID_NO_CHILD_NOTIFY, 1000, 0, 0)


EVT_ITEM(EVT_ID_GROUP_GOBACK,    1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_EXIT,      1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEINIT,    1000, 0, 0)
EVT_END()


void tree3_sequence1_close(node_set_struct *tree, U16 size)
{
	desequence_close(tree, size);
}


TREE_START(tree4)
TEST_NODE(SCENARIO_GROUP_NODE, GRP_ID_ROOT, 1000)
TEST_NODE(SCENARIO_GROUP_NODE, GRP_ID_ROOT, 2000)
TEST_NODE(SCENARIO_GROUP_NODE, 2000,        3000)
TREE_END()
EVT_START(tree4_sequence1)
EVT_ITEM(EVT_ID_GROUP_ENTER,     1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ACTIVE,    1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ENTER,     2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ACTIVE,    2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   2000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_ENTER,     3000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ACTIVE,    3000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   3000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_GOBACK,    2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_GOBACK,    3000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 3000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  3000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_EXIT,      3000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEINIT,    3000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_EXIT,      2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEINIT,    2000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_ACTIVE,    1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   1000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_GOBACK,    1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_EXIT,      1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEINIT,    1000, 0, 0)
EVT_END()

void tree4_sequence1_close(node_set_struct *tree, U16 size)
{
	mmi_frm_group_close(2000);
	mmi_frm_group_close(1000);
}

TREE_START(tree5)
TEST_NODE(SCENARIO_GROUP_NODE, GRP_ID_ROOT, 1000)
TEST_NODE(SCENARIO_SCRN_NODE,  1000,        2000)
TEST_NODE(SCENARIO_GROUP_NODE, 1000,        3000)
TREE_END()

EVT_START(tree5_sequence1)
EVT_ITEM(EVT_ID_GROUP_ENTER,     1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ACTIVE,    1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   1000, 0, 0)
EVT_ITEM(EVT_ID_SCRN_ACTIVE,     1000, 0, 2000)
EVT_ITEM(EVT_ID_GROUP_ENTER,     3000, 0, 0)   //attention
EVT_ITEM(EVT_ID_SCRN_INACTIVE,   1000, 0, 2000)
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ACTIVE,    3000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   3000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_GOBACK,    3000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 3000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  3000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_EXIT,      3000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEINIT,    3000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   1000, 0, 0)
EVT_ITEM(EVT_ID_SCRN_ACTIVE,     1000, 0, 2000)



EVT_ITEM(EVT_ID_GROUP_GOBACK,    1000, 0, 0)
EVT_ITEM(EVT_ID_SCRN_GOBACK,     1000, 0, 2000)
EVT_ITEM(EVT_ID_SCRN_INACTIVE,   1000, 0, 2000)
EVT_ITEM(EVT_ID_SCRN_DEINIT,     1000, 0, 2000)

EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_EXIT,      1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEINIT,    1000, 0, 0)
EVT_END()

void tree5_sequence1_close(node_set_struct *tree, U16 size)
{
	mmi_frm_group_close(3000);
	mmi_frm_group_close(1000);
}

TREE_START(tree6)
TEST_NODE(SCENARIO_GROUP_NODE, GRP_ID_ROOT, 1000)
TEST_NODE(SCENARIO_GROUP_NODE, 1000,        2000)
TEST_NODE(SCENARIO_SCRN_NODE,  1000,        3000)
TREE_END()

EVT_START(tree6_sequence1)
EVT_ITEM(EVT_ID_GROUP_ENTER,     1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ACTIVE,    1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   1000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_ENTER,     2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ACTIVE,    2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   2000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   1000, 0, 0)
EVT_ITEM(EVT_ID_SCRN_ACTIVE,     1000, 0, 3000)


EVT_ITEM(EVT_ID_SCRN_GOBACK,     1000, 0, 3000)
EVT_ITEM(EVT_ID_SCRN_INACTIVE,   1000, 0, 3000)
EVT_ITEM(EVT_ID_SCRN_DEINIT,     1000, 0, 3000)

EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ACTIVE,    2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   2000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_GOBACK,    1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_GOBACK,    2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_EXIT,      2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEINIT,    2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_EXIT,      1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEINIT,    1000, 0, 0)
EVT_END()


void tree6_sequence1_close(node_set_struct *tree, U16 size)
{
	kal_prompt_trace(MOD_MMI,"[S] close 1000, 3000");
	mmi_frm_scrn_close(1000, 3000);
	kal_prompt_trace(MOD_MMI, "[G] close 1000");
	mmi_frm_group_close(1000);
}

TREE_START(tree7)
TEST_NODE(SCENARIO_GROUP_NODE, GRP_ID_ROOT, 1000)
TEST_NODE(SCENARIO_GROUP_NODE, 1000,        2000)
TEST_NODE(SCENARIO_SCRN_NODE,  2000,        3000)
TEST_NODE(SCENARIO_SCRN_NODE,  1000,        4000)
TREE_END()

EVT_START(tree7_sequence1)
EVT_ITEM(EVT_ID_GROUP_ENTER,     1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ACTIVE,    1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   1000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_ENTER,     2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ACTIVE,    2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   2000, 0, 0)

EVT_ITEM(EVT_ID_SCRN_ACTIVE,     2000, 0, 3000)

EVT_ITEM(EVT_ID_SCRN_INACTIVE,   2000, 0, 3000)
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  2000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_FOCUSED,   1000, 0, 0)
EVT_ITEM(EVT_ID_SCRN_ACTIVE,     1000, 0, 4000)


EVT_ITEM(EVT_ID_SCRN_GOBACK,     1000, 0, 4000)
EVT_ITEM(EVT_ID_SCRN_INACTIVE,   1000, 0, 4000)
EVT_ITEM(EVT_ID_SCRN_DEINIT,     1000, 0, 4000)

EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ACTIVE,    2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   2000, 0, 0)
EVT_ITEM(EVT_ID_SCRN_ACTIVE,     2000, 0, 3000)

EVT_ITEM(EVT_ID_GROUP_GOBACK,    1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_GOBACK,    2000, 0, 0)
EVT_ITEM(EVT_ID_SCRN_GOBACK,     2000, 0, 3000)

EVT_ITEM(EVT_ID_SCRN_INACTIVE,   2000, 0, 3000)
EVT_ITEM(EVT_ID_SCRN_DEINIT,     2000, 0, 3000)

EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_EXIT,      2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEINIT,    2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_EXIT,      1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEINIT,    1000, 0, 0)
EVT_END()
void tree7_sequence1_close(node_set_struct *tree, U16 size)
{
	mmi_frm_scrn_close(1000, 4000);
	mmi_frm_group_close(1000);
}

TREE_START(tree8)
TEST_NODE(SCENARIO_GROUP_NODE, GRP_ID_ROOT, 5000)
TEST_NODE(SCENARIO_GROUP_NODE, 5000,        7000)
TEST_NODE(SCENARIO_SCRN_NODE,  7000,        6000)
TEST_NODE(SCENARIO_GROUP_NODE, GRP_ID_ROOT, 1000)
TEST_NODE(SCENARIO_GROUP_NODE, 1000,        2000)
TEST_NODE(SCENARIO_SCRN_NODE,  2000,        3000)
TEST_NODE(SCENARIO_SCRN_NODE,  1000,        4000)
TREE_END()


EVT_START(tree8_sequence1)
EVT_ITEM(EVT_ID_GROUP_ENTER,     5000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ACTIVE,    5000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   5000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_ENTER,     7000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 5000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ACTIVE,    7000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   7000, 0, 0)
EVT_ITEM(EVT_ID_SCRN_ACTIVE,     7000, 0, 6000)

EVT_ITEM(EVT_ID_GROUP_ENTER,     1000, 0, 0)
EVT_ITEM(EVT_ID_SCRN_INACTIVE,   7000, 0, 6000)
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 7000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  7000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  5000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_ACTIVE,    1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   1000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_ENTER,     2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ACTIVE,    2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   2000, 0, 0)

EVT_ITEM(EVT_ID_SCRN_ACTIVE,     2000, 0, 3000)

EVT_ITEM(EVT_ID_SCRN_INACTIVE,   2000, 0, 3000)
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  2000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_FOCUSED,   1000, 0, 0)
EVT_ITEM(EVT_ID_SCRN_ACTIVE,     1000, 0, 4000)

EVT_ITEM(EVT_ID_GROUP_GOBACK_IN_END_KEY,        1000, 0, 0)
EVT_ITEM(EVT_ID_SCRN_GOBACK_IN_END_KEY,         1000, 0, 4000)
EVT_ITEM(EVT_ID_SCRN_INACTIVE,   1000, 0, 4000)
EVT_ITEM(EVT_ID_SCRN_DEINIT,     1000, 0, 4000)

EVT_ITEM(EVT_ID_GROUP_DELETE_REQ_IN_END_KEY,    2000, 0, 0)
EVT_ITEM(EVT_ID_SCRN_DELETE_REQ_IN_END_KEY,     2000, 0, 3000)


EVT_ITEM(EVT_ID_SCRN_DEINIT,     2000, 0, 3000)

EVT_ITEM(EVT_ID_GROUP_EXIT,      2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEINIT,    2000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_EXIT,      1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEINIT,    1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DELETE_REQ_IN_END_KEY, 5000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DELETE_REQ_IN_END_KEY, 7000, 0, 0)
EVT_ITEM(EVT_ID_SCRN_DELETE_REQ_IN_END_KEY,      7000, 0, 6000)
EVT_ITEM(EVT_ID_SCRN_DEINIT,     7000, 0, 6000)
EVT_ITEM(EVT_ID_GROUP_EXIT,      7000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEINIT,    7000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_EXIT,      5000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEINIT,    5000, 0, 0)
EVT_END()

void tree8_sequence1_close(node_set_struct *tree, U16 size)
{
	mmi_frm_close_to_idle_group();
}
EVT_START(tree8_sequence2)
EVT_ITEM(EVT_ID_GROUP_ENTER,     5000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ACTIVE,    5000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   5000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_ENTER,     7000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 5000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ACTIVE,    7000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   7000, 0, 0)
EVT_ITEM(EVT_ID_SCRN_ACTIVE,     7000, 0, 6000)

EVT_ITEM(EVT_ID_GROUP_ENTER,     1000, 0, 0)
EVT_ITEM(EVT_ID_SCRN_INACTIVE,   7000, 0, 6000)
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 7000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  7000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  5000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_ACTIVE,    1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   1000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_ENTER,     2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ACTIVE,    2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   2000, 0, 0)

EVT_ITEM(EVT_ID_SCRN_ACTIVE,     2000, 0, 3000)

EVT_ITEM(EVT_ID_SCRN_INACTIVE,   2000, 0, 3000)
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  2000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_FOCUSED,   1000, 0, 0)
EVT_ITEM(EVT_ID_SCRN_ACTIVE,     1000, 0, 4000)


EVT_ITEM(EVT_ID_SCRN_INACTIVE,   1000, 0, 4000)
EVT_ITEM(EVT_ID_SCRN_HIDE,       1000, 0, 4000)
EVT_ITEM(EVT_ID_SCRN_HIDE,       2000, 0, 3000)
EVT_ITEM(EVT_ID_GROUP_HIDE,      2000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_HIDE,      1000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_ACTIVE,    5000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   5000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 5000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ACTIVE,    7000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   7000, 0, 0)


EVT_ITEM(EVT_ID_SCRN_ACTIVE,     7000, 0, 6000)
EVT_ITEM(EVT_ID_SCRN_INACTIVE,   7000, 0, 6000)

EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 7000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  7000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  5000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_UNHIDE,    1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ACTIVE,    1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   1000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_UNHIDE,    2000, 0, 0)
EVT_ITEM(EVT_ID_SCRN_UNHIDE,     2000, 0, 3000)
EVT_ITEM(EVT_ID_SCRN_UNHIDE,     1000, 0, 4000)
EVT_ITEM(EVT_ID_SCRN_ACTIVE,     1000, 0, 4000)

EVT_ITEM(EVT_ID_SCRN_HIDE,       7000, 0, 6000)
EVT_ITEM(EVT_ID_GROUP_HIDE,      7000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_HIDE,      5000, 0, 0)

EVT_ITEM(EVT_ID_SCRN_INACTIVE,   1000, 0, 4000)
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  1000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_UNHIDE,    5000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ACTIVE,    5000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   5000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_UNHIDE,    7000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 5000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ACTIVE,    7000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   7000, 0, 0)

EVT_ITEM(EVT_ID_SCRN_UNHIDE,     7000, 0, 6000)
EVT_ITEM(EVT_ID_SCRN_ACTIVE,     7000, 0, 6000)





EVT_ITEM(EVT_ID_GROUP_GOBACK_IN_END_KEY,        5000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_GOBACK_IN_END_KEY,        7000, 0, 0)
EVT_ITEM(EVT_ID_SCRN_GOBACK_IN_END_KEY,         7000, 0, 6000)
EVT_ITEM(EVT_ID_SCRN_INACTIVE,   7000, 0, 6000)
EVT_ITEM(EVT_ID_SCRN_DEINIT,     7000, 0, 6000)
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 7000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  7000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_EXIT,      7000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEINIT,    7000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  5000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_EXIT,      5000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEINIT,    5000, 0, 0)


EVT_ITEM(EVT_ID_GROUP_DELETE_REQ_IN_END_KEY,    1000, 0, 0)
EVT_ITEM(EVT_ID_SCRN_DELETE_REQ_IN_END_KEY,     1000, 0, 4000)
EVT_ITEM(EVT_ID_SCRN_DEINIT,     1000, 0, 4000)
EVT_ITEM(EVT_ID_GROUP_DELETE_REQ_IN_END_KEY,    2000, 0, 0)
EVT_ITEM(EVT_ID_SCRN_DELETE_REQ_IN_END_KEY,     2000, 0, 3000)
EVT_ITEM(EVT_ID_SCRN_DEINIT,     2000, 0, 3000)

EVT_ITEM(EVT_ID_GROUP_EXIT,      2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEINIT,    2000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_EXIT,      1000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEINIT,    1000, 0, 0)
EVT_END()

void tree8_sequence2_close(node_set_struct *tree, U16 size)
{
	kal_prompt_trace(MOD_MMI, "[G] group hide 1000");
	mmi_frm_group_hide(1000);

	kal_prompt_trace(MOD_MMI, "[G] group unhide 1000");
	mmi_frm_group_unhide(1000);

	kal_prompt_trace(MOD_MMI, "[G] group hide 5000");
	mmi_frm_group_hide(5000);

	kal_prompt_trace(MOD_MMI, "[G] group unhide 5000");
	mmi_frm_group_unhide(5000);
	mmi_frm_close_to_idle_group();
}

TREE_START(tree9)
TEST_NODE(SCENARIO_GROUP_NODE, GRP_ID_ROOT, 5000)
TEST_NODE(SCENARIO_SCRN_NODE,  5000,        1000)
TEST_NODE(SCENARIO_SCRN_NODE,  5000,        2000)
TREE_END()

void tree9_sequence1_close(node_set_struct *tree, U16 size)
{
    desequence_close(tree, size);
}
EVT_START(tree9_sequence1)
EVT_ITEM(EVT_ID_GROUP_ENTER,     5000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_ACTIVE,    5000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_FOCUSED,   5000, 0, 0)
EVT_ITEM(EVT_ID_SCRN_ACTIVE,     5000, 0, 1000)

EVT_ITEM(EVT_ID_SCRN_INACTIVE,   5000, 0, 1000)
EVT_ITEM(EVT_ID_SCRN_ACTIVE,     5000, 0, 2000)

EVT_ITEM(EVT_ID_SCRN_GOBACK,     5000, 0, 2000)
EVT_ITEM(EVT_ID_SCRN_INACTIVE,   5000, 0, 2000)
EVT_ITEM(EVT_ID_SCRN_DEINIT,     5000, 0, 2000)
EVT_ITEM(EVT_ID_SCRN_ACTIVE,     5000, 0, 1000)
EVT_ITEM(EVT_ID_SCRN_GOBACK,     5000, 0, 1000)
EVT_ITEM(EVT_ID_SCRN_INACTIVE,   5000, 0, 1000)
EVT_ITEM(EVT_ID_SCRN_DEINIT,     5000, 0, 1000)
EVT_ITEM(EVT_ID_NO_CHILD_NOTIFY, 5000, 0, 0)

EVT_ITEM(EVT_ID_GROUP_GOBACK,    5000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEFOCUSED, 5000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_INACTIVE,  5000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_EXIT,  5000, 0, 0)
EVT_ITEM(EVT_ID_GROUP_DEINIT,    5000, 0, 0)

EVT_END()


TEST_EVT_ITEM_START()
TEST_EVT_ITEM(tree1, tree1_sequence1_close, tree1_sequence1)
TEST_EVT_ITEM(tree2, tree2_sequence1_close, tree2_sequence1)
TEST_EVT_ITEM(tree2, tree2_sequence2_close, tree2_sequence2)
TEST_EVT_ITEM(tree3, tree3_sequence1_close, tree3_sequence1)
TEST_EVT_ITEM(tree4, tree4_sequence1_close, tree4_sequence1)
TEST_EVT_ITEM(tree5, tree5_sequence1_close, tree5_sequence1)
TEST_EVT_ITEM(tree6, tree6_sequence1_close, tree6_sequence1)
TEST_EVT_ITEM(tree7, tree7_sequence1_close, tree7_sequence1)
TEST_EVT_ITEM(tree8, tree8_sequence1_close, tree8_sequence1)
TEST_EVT_ITEM(tree8, tree8_sequence2_close, tree8_sequence2)
TEST_EVT_ITEM(tree9, tree9_sequence1_close, tree9_sequence1)

TEST_EVT_ITEM_END()



void desequence_close(node_set_struct *tree, U16 size)
{
	S32 i;
	for (i = size -1; i >=0; i--)
	{
		if (tree[i].type == SCENARIO_GROUP_NODE)
		{
			kal_prompt_trace(MOD_MMI, "[G] close %d", tree[i].this_id);
			mmi_frm_group_close(tree[i].this_id);
		}
		else if(tree[i].type == SCENARIO_SCRN_NODE)
		{
			kal_prompt_trace(MOD_MMI, "[S] close %d, %d", tree[i].parent_id, tree[i].this_id);
			mmi_frm_scrn_close(tree[i].parent_id, tree[i].this_id);
		}
	}
}

void start_record_event_flow()
{
	record_number = 0;
}

void end_record_event_flow()
{
	memset(record_buffer, 0, sizeof(record_buffer));
	record_number = -1;
}

MMI_BOOL is_record_equal(check_item_struct *a, check_item_struct *b)
{
	if (a->evt_id == b->evt_id &&
		a->group_id == b->group_id &&
		a->scrn_id  == b->scrn_id &&
		a->tab_id  == b->tab_id)
	{
		return MMI_TRUE;
	}
	return MMI_FALSE;
}

mmi_ret focus_defocus_test_proc(mmi_event_struct *evt)
{
	mmi_scenario_evt_struct *s = (mmi_scenario_evt_struct *)evt;
	print_event_info(s->evt_id, s->targ_group, 0, s->targ_scrn);
	record_buffer[record_number].evt_id = s->evt_id;
	record_buffer[record_number].group_id = s->targ_group;
	record_buffer[record_number].tab_id   = 0;
	record_buffer[record_number].scrn_id  = s->targ_scrn;
	record_number++;
	return MMI_RET_OK;
}

mmi_ret focus_defocus_test_screen_exit(mmi_scrn_essential_struct *p)
{
	mmi_scenario_evt_struct s;

	MMI_FRM_INIT_EVENT(&s, EVT_ID_SCRN_INACTIVE);
	s.targ_group = p->group_id;
	s.targ_scrn  = p->scrn_id;
	MMI_FRM_SEND_EVENT(&s, focus_defocus_test_proc, NULL);
	return MMI_RET_OK;
}

mmi_ret focus_defocus_test_screen(mmi_scrn_essential_struct *p)
{

	if (mmi_frm_scrn_enter(
		p->group_id,
		p->scrn_id,
		(FuncPtr)focus_defocus_test_screen_exit,
		(FuncPtr)focus_defocus_test_screen, MMI_FRM_FULL_SCRN) == MMI_TRUE)
	{
		mmi_scenario_evt_struct s;

		MMI_FRM_INIT_EVENT(&s, EVT_ID_SCRN_ACTIVE);
		s.targ_group = p->group_id;
		s.targ_scrn  = p->scrn_id;
		MMI_FRM_SEND_EVENT(&s, focus_defocus_test_proc, NULL);
	}
	return MMI_RET_OK;
}

void event_flow_check(check_item_struct *expected_flow, U16 expected_number)
{
	U32 i;
	MMI_ASSERT(expected_number == record_number);
	for (i = 0; i < record_number; i++)
	{
		MMI_ASSERT(is_record_equal(&expected_flow[i], &record_buffer[i]) == MMI_TRUE);
	}
}

void evt_flow_test_engine(void)
{
	U32 i;
	for (i = 0; i < sizeof(evt_flow_test_table)/ sizeof(evt_flow_test_table[0]); i++)
	{
		U32 j;
		kal_prompt_trace(MOD_MMI, "case %d start", i + 1);
		start_record_event_flow();
		for (j = 0; j < evt_flow_test_table[i].tree_size; j++)
		{
			if (evt_flow_test_table[i].tree[j].type == SCENARIO_GROUP_NODE)
			{
				kal_prompt_trace(MOD_MMI, "[G] Enter %d, %d", 
					evt_flow_test_table[i].tree[j].parent_id, 
					evt_flow_test_table[i].tree[j].this_id);
				mmi_frm_group_create(evt_flow_test_table[i].tree[j].parent_id,
					evt_flow_test_table[i].tree[j].this_id,
					focus_defocus_test_proc,
					NULL);
				mmi_frm_group_enter(evt_flow_test_table[i].tree[j].this_id, 0);
			}
			else if (evt_flow_test_table[i].tree[j].type == SCENARIO_SCRN_NODE)
			{
				kal_prompt_trace(MOD_MMI, "[S] Enter %d, %d", 
					evt_flow_test_table[i].tree[j].parent_id, 
					evt_flow_test_table[i].tree[j].this_id);
				mmi_frm_scrn_first_enter(
					evt_flow_test_table[i].tree[j].parent_id,
					evt_flow_test_table[i].tree[j].this_id, 
					(FuncPtr)focus_defocus_test_screen,
					NULL);
				mmi_frm_scrn_set_leave_proc(
					evt_flow_test_table[i].tree[j].parent_id,
					evt_flow_test_table[i].tree[j].this_id,
					focus_defocus_test_proc);
			}
		}
		if (evt_flow_test_table[i].callback)
		{
			evt_flow_test_table[i].callback(evt_flow_test_table[i].tree, evt_flow_test_table[i].tree_size);
		}
		event_flow_check(evt_flow_test_table[i].expected_table, evt_flow_test_table[i].evt_size);
		end_record_event_flow();
	}
}


mmi_ret focus_defocus_test(void *para)
{
	mmi_frm_close_to_idle_group();
	evt_flow_test_engine();
	mmi_frm_close_to_idle_group();
	return MMI_RET_OK;
}
U32 stop_way = 0;
mmi_ret end_key_flow_test1(mmi_event_struct *evt)
{
	mmi_scenario_evt_struct *s = (mmi_scenario_evt_struct *)evt;
	switch (s->evt_id)
	{
		case EVT_ID_GROUP_GOBACK_IN_END_KEY:
		case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
			if (stop_way == 0)
			{
				return MMI_RET_OK;
			}
			else if (stop_way == 1)
			{
				if (s->targ_group == 2000)
				{
					return MMI_RET_STOP_END_KEY_FLOW;
				}
			}
			else if (stop_way == 2)
			{
				if (s->targ_group == 2000)
				return MMI_RET_ERR;
			}
			break;
	}
	return MMI_RET_OK;
}



mmi_ret end_key_flow_test(void *para)
{
	mmi_frm_close_to_idle_group();
	mmi_frm_group_create(GRP_ID_ROOT, 1000, end_key_flow_test1, NULL);
	mmi_frm_group_enter(1000, 0);
	mmi_frm_group_create(GRP_ID_ROOT, 2000, end_key_flow_test1, NULL);
	mmi_frm_group_enter(2000, 0);
	stop_way = 1;
	mmi_frm_close_to_idle_group();
	MMI_ASSERT(mmi_frm_group_is_present(2000) == MMI_TRUE);
	MMI_ASSERT(mmi_frm_group_is_present(1000) == MMI_TRUE);
	stop_way = 2;
	mmi_frm_close_to_idle_group();
	MMI_ASSERT(mmi_frm_group_is_present(2000) == MMI_TRUE);
	MMI_ASSERT(mmi_frm_group_is_present(1000) == MMI_FALSE);
	stop_way = 0;
	mmi_frm_close_to_idle_group();
	MMI_ASSERT(mmi_frm_group_is_present(2000) == MMI_FALSE);
	MMI_ASSERT(mmi_frm_group_is_present(1000) == MMI_FALSE);

	return MMI_RET_OK;
}
mmi_ret end_key_flow_test2_proc(mmi_event_struct *evt)
{
	mmi_scenario_evt_struct *s = (mmi_scenario_evt_struct *)evt;
	if (s->evt_id != 0)
	{
		print_event_info(s->evt_id, s->targ_group, 0, s->targ_scrn);
	}
	switch (s->evt_id)
	{
		case EVT_ID_GROUP_GOBACK_IN_END_KEY:
		case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
			if (s->targ_group == 2000)
			{
				return MMI_RET_OK;
			}
			if (s->targ_group == 1000)
			{
                mmi_event_struct post_evt;
				mmi_id id = mmi_frm_scrn_get_neighbor_id(
                        GRP_ID_ROOT, 
                        1000,
                        MMI_FRM_NODE_BEFORE_FLAG);
				mmi_frm_group_hide(1000);
				MMI_FRM_INIT_EVENT(&post_evt, 0);
				MMI_FRM_POST_EVENT(&post_evt, end_key_flow_test2_proc, (void *)id);
				
				return MMI_RET_STOP_END_KEY_FLOW;
			}
			break;
		case 0:
			{
				mmi_id id = (mmi_id)evt->user_data;
				mmi_frm_close_to_idle_group_with_start_id(id);
                mmi_frm_group_unhide(1000);
				mmi_frm_group_close(1000);
				mmi_frm_close_to_idle_group();
			}

			break;

	}
	return MMI_RET_OK;
}
mmi_ret end_key_flow_test2(void *para)
{
	mmi_frm_close_to_idle_group();
	mmi_frm_group_create(GRP_ID_ROOT, 3000, end_key_flow_test2_proc, NULL);
	mmi_frm_group_enter(3000, 0);
	mmi_frm_group_create(GRP_ID_ROOT, 1000, end_key_flow_test2_proc, NULL);
	mmi_frm_group_enter(1000, 0);
	mmi_frm_group_create(GRP_ID_ROOT, 2000, end_key_flow_test2_proc, NULL);
	mmi_frm_group_enter(2000, 0);
	mmi_frm_close_to_idle_group();
	return MMI_RET_OK;
}
mmi_ret MAUI_02647226_proc(mmi_event_struct *evt)
{
	if (evt->evt_id == EVT_ID_GROUP_DEINIT)
	{
		MMI_ASSERT(mmi_frm_group_get_user_data(1000) == (void *)1000);
	}
	return MMI_RET_OK;
}

mmi_ret MAUI_02647226(void *p)
{
	mmi_frm_close_to_idle_group();
	mmi_frm_group_create(GRP_ID_ROOT, 1000, MAUI_02647226_proc, (void *)1000);
	mmi_frm_group_close(1000);
	return MMI_RET_OK;
}
mmi_ret MAUI_02450790_proc(mmi_event_struct *evt)
{
	if (evt->evt_id == EVT_ID_GROUP_DEINIT)
	{
		mmi_frm_group_close(1000);
	}
	return MMI_RET_OK;
}
mmi_ret MAUI_02450790(void *para)
{
	mmi_frm_close_to_idle_group();
	mmi_frm_group_create(100, 1000, MAUI_02450790_proc, NULL);
	mmi_frm_group_enter(1000, 1);
	return MMI_RET_OK;
}

void show_back_ground_exit(void)
{
    if (mmi_is_redrawing_bk_screens())
    {
        mmi_frm_group_close(6000);
    }
}


void show_back_ground(void)
{
    if (MMI_TRUE == mmi_frm_scrn_enter(1000, 2000, show_back_ground_exit, show_back_ground, MMI_FRM_FULL_SCRN))
    {
        //ShowCategoryDummySmallScreen();
    }
}

void __show_small_screen(void)
{
    if (MMI_TRUE == mmi_frm_scrn_enter(3000, 4000, NULL, __show_small_screen, MMI_FRM_FULL_SCRN))
    {
        ShowCategoryDummySmallScreen();
    }    
}

mmi_ret MAUI_02451294(void *p)
{
    mmi_frm_close_to_idle_group();
    mmi_frm_group_create(GRP_ID_ROOT, 1000, NULL, NULL);
    mmi_frm_group_enter(1000, 0);
    show_back_ground();
    mmi_frm_group_create(GRP_ID_ROOT, 3000, NULL, NULL);
    mmi_frm_group_enter(3000, 0);
    __show_small_screen();
    mmi_frm_group_create(GRP_ID_ROOT, 5000, NULL, NULL);
    mmi_frm_group_enter(5000, 0);
    mmi_frm_group_create(GRP_ID_ROOT, 6000, NULL, NULL);
	mmi_frm_group_close(5000);

    mmi_frm_group_create(GRP_ID_ROOT, 7000, NULL, NULL);
    mmi_frm_group_enter(7000, 0);
    return MMI_RET_OK;
}
U32 MAUI_02738851_counter;
void MAUI_02738851_entry1(void)
{
	mmi_frm_scrn_enter(200, 1000, NULL, MAUI_02738851_entry1, MMI_FRM_FULL_SCRN);
}
void MAUI_02738851_entry2(void)
{
	mmi_frm_scrn_enter(300, 2000, NULL, MAUI_02738851_entry2, MMI_FRM_FULL_SCRN);
	MAUI_02738851_counter++;
}

void MAUI_02738851_entry3(void)
{
	mmi_frm_scrn_enter(500, 3000, NULL, MAUI_02738851_entry3, MMI_FRM_FULL_SCRN);
}

mmi_ret MAUI_02738851_proc(mmi_event_struct *evt)
{
	if (evt->evt_id == EVT_ID_GROUP_INACTIVE)
	{
		mmi_frm_group_close(400);
	}
	return MMI_RET_OK;
}

mmi_ret MAUI_02738851(void *p)
{
	mmi_frm_close_to_idle_group();
	mmi_frm_group_create(GRP_ID_ROOT, 100, NULL, NULL);
	mmi_frm_group_enter(100, 0);
	mmi_frm_group_create(100, 200, NULL, NULL);
	mmi_frm_group_enter(200, 0);
	mmi_frm_scrn_first_enter(200, 1000, MAUI_02738851_entry1, NULL);
	
	mmi_frm_group_create(100, 300, NULL, NULL);
	mmi_frm_group_enter(300, 0);
	MAUI_02738851_counter = 0;
	mmi_frm_scrn_first_enter(300, 2000, MAUI_02738851_entry2, NULL);

	mmi_frm_group_create(300, 400, NULL, NULL);
	mmi_frm_group_enter(400, 0);

	mmi_frm_group_create(400, 500, MAUI_02738851_proc, NULL);
	mmi_frm_group_enter(500, 0);
	mmi_frm_scrn_first_enter(500, 3000, MAUI_02738851_entry3, NULL);

	mmi_frm_group_close(300);
	MMI_ASSERT(MAUI_02738851_counter == 1);
	return MMI_RET_OK;
}
void scrn_A_exit_proc(void)
{
    kal_print("\nscreen A exit");
}
void scrn_A_entry_proc(void)
{
    kal_print("\nscreen A entry");
    if (mmi_frm_scrn_enter(0x100, 0x901, scrn_A_exit_proc, scrn_A_entry_proc, MMI_FRM_FULL_SCRN))
    {
        //ShowCategoryDummyScreen();
    }
}

void scrn_B_exit_proc(void)
{
    kal_print("\nscreen B exit");
}
void scrn_B_entry_proc(void)
{
    kal_print("\nscreen B entry");
    if (mmi_frm_scrn_enter(0x200, 0x902, scrn_B_exit_proc, scrn_B_entry_proc, MMI_FRM_FULL_SCRN))
    {
        //ShowCategoryDummyScreen();
    }
}

void scrn_C_exit_proc(void)
{
    kal_print("\nscreen C exit");
}
void scrn_C_entry_proc(void)
{
    kal_print("\nscreen C entry");
    if (mmi_frm_scrn_enter(0x400, 0x903, scrn_C_exit_proc, scrn_C_entry_proc, MMI_FRM_SMALL_SCRN))
    {
        //ShowCategoryDummyScreen();
    }
}

mmi_ret group_proc_A(mmi_event_struct *param)
{
    mmi_ret ret = MMI_RET_OK;
    switch(param->evt_id)
    {
        case EVT_ID_GROUP_REDRAW_START:
            check1++;
            kal_print("\nGROUP A event: EVT_ID_GROUP_REDRAW_START");
            break;
        case EVT_ID_GROUP_REDRAW_DONE:
            check2++;
            kal_print("\nGROUP A event: EVT_ID_GROUP_REDRAW_END");
            break;
        default:
            break;
    }
    return ret;
}

mmi_ret group_proc_B(mmi_event_struct *param)
{
    mmi_ret ret = MMI_RET_OK;
    switch(param->evt_id)
    {
        case EVT_ID_GROUP_REDRAW_START:
            check1++;
            kal_print("\nGROUP B event: EVT_ID_GROUP_REDRAW_START");
            break;
        case EVT_ID_GROUP_REDRAW_DONE:
            check2++;
            kal_print("\nGROUP B event: EVT_ID_GROUP_REDRAW_END");
            break;
        default:
            break;
    }
    
    return ret;
}
mmi_ret group_proc_C(mmi_event_struct *param)
{
    mmi_ret ret = MMI_RET_OK;
    switch(param->evt_id)
    {
        case EVT_ID_GROUP_REDRAW_START:
            check1++;
            kal_print("\nGROUP C event: EVT_ID_GROUP_REDRAW_START");
            break;
        case EVT_ID_GROUP_REDRAW_DONE:
            check2++;
            kal_print("\nGROUP C event: EVT_ID_GROUP_REDRAW_END");
            break;
        default:
            break;
    }
    
    return ret;
}
mmi_ret group_proc_D(mmi_event_struct *param)
{
    mmi_ret ret = MMI_RET_OK;
    switch(param->evt_id)
    {
        case EVT_ID_GROUP_REDRAW_START:
            check1++;
            kal_print("\nGROUP D event: EVT_ID_GROUP_REDRAW_START");
            break;
        case EVT_ID_GROUP_REDRAW_DONE:
            check2++;
            kal_print("\nGROUP D event: EVT_ID_GROUP_REDRAW_END");
            break;
        default:
            break;
    }
    
    return ret;

}
mmi_ret test_small_scrn_redraw(void *para)
{
    check1 = 0;
    check2 = 0;
    mmi_frm_close_to_idle_group();
    mmi_frm_group_create(GRP_ID_ROOT, 0x100, group_proc_A, NULL);
    mmi_frm_group_enter(0x100, 0);
    scrn_A_entry_proc();

    mmi_frm_group_create(GRP_ID_ROOT, 0x300, group_proc_C, NULL);
    mmi_frm_group_enter(0x300, 0);
    mmi_frm_group_create(0x300, 0x400, group_proc_D, NULL);
    mmi_frm_group_enter(0x400, 0);
    scrn_C_entry_proc();

    mmi_frm_group_create(GRP_ID_ROOT, 0x200, group_proc_B, NULL);
    mmi_frm_group_enter(0x200, 0);
    scrn_B_entry_proc();

    mmi_frm_group_close(0x200);

    MMI_ASSERT(check1 == check2);
    mmi_frm_close_to_idle_group();    
    return MMI_RET_OK;
}

mmi_ret MAUI_02742942(void *para)
{
    mmi_group_event_struct evt = {0};
    
    ExecuteRootMainHistoryScreen(NULL);
    mmi_frm_group_create(GRP_ID_ROOT, 0x100, NULL, NULL);
    mmi_frm_group_enter(0x100, 0);
    mmi_frm_group_create(0x100, 0x1001, NULL, NULL);
    mmi_frm_group_enter(0x1001, 0);
    
    mmi_frm_group_create(GRP_ID_ROOT, 0x200, NULL, NULL);
    mmi_frm_group_enter(0x200, 0);
    mmi_frm_group_create(GRP_ID_ROOT, 0x300, NULL, NULL);
    mmi_frm_group_enter(0x300, 0);
    mmi_frm_group_create(GRP_ID_ROOT, 0x400, NULL, NULL);
    mmi_frm_group_enter(0x400, 0);
    mmi_frm_group_set_caller(0x400,0x1001);
    mmi_frm_group_send_to_caller(0x400, &evt);
    mmi_frm_group_close(0x100);
    mmi_frm_group_send_to_caller(0x400, &evt);    
    return MMI_RET_OK;
}
mmi_ret MAUI_02962772(void *para)
{    
    mmi_frm_node_struct insert_node;

    ExecuteRootMainHistoryScreen(NULL);
    mmi_frm_group_create(GRP_ID_ROOT, 0x100, NULL, NULL);
    mmi_frm_group_enter(0x100, 0);
    mmi_frm_group_create(0x100, 0x200, NULL, NULL);
    mmi_frm_group_enter(0x200, 0);
    mmi_frm_scrn_enter(0x200, 0x2001, NULL, NULL, MMI_FRM_FULL_SCRN);

    //mmi_frm_scrn_close(0x200, 0x2001);
    mmi_frm_group_close(0x200);

    mmi_frm_group_create(GRP_ID_ROOT, 0x300, NULL, 0);
    insert_node.entry_proc = NULL;
    insert_node.id = 0x300;
    insert_node.user_data = 0;
    mmi_frm_group_insert(GRP_ID_ROOT, 0x100, &insert_node, MMI_FRM_NODE_BEFORE_FLAG);

    
    //mmi_frm_close_to_root_screen(0x100);
    mmi_frm_close_to_idle_group();
	return MMI_RET_OK;
}


typedef struct
{
	U16 scrn_id;
	void *user_data;
} his_scrn_cntx;

static void scrn_exit_hisory(void *arg)
{
}

static U8 scrn_destroy_history(void *arg)
{
	mmi_mfree(arg);
	return 0;
}

static void scrn_entry_history(void *arg)
{
	his_scrn_cntx *cntx = (his_scrn_cntx *)arg;
	mmi_frm_entry_new_screen(cntx->scrn_id, scrn_exit_hisory, scrn_entry_history, NULL);
	mmi_frm_set_destroy_scrn_callback(cntx->scrn_id, scrn_destroy_history);
}

void create_history_screen(U16 scrn_id, void *user_data)
{
	his_scrn_cntx *cntx = (his_scrn_cntx *)mmi_malloc(sizeof(his_scrn_cntx));
	cntx->scrn_id = scrn_id;
	cntx->user_data = user_data;
	mmi_frm_create_new_screen(scrn_entry_history, cntx);
}



mmi_ret test_mmi_frm_get_previous_app_id(void *para)
{
	MMI_ID idle_app_id;
	mmi_frm_close_to_idle_group();
	idle_app_id = mmi_frm_group_get_active_id();
	idle_app_id = mmi_frm_get_root_app(idle_app_id);
	MMI_ASSERT(mmi_frm_get_previous_app_id(idle_app_id) == GRP_ID_INVALID);
	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x400, NULL, NULL, 0);
	MMI_ASSERT(mmi_frm_get_previous_app_id(idle_app_id) == GRP_ID_INVALID);
	MMI_ASSERT(mmi_frm_get_previous_app_id(0x400) == idle_app_id);
	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x500, NULL, NULL, 0);
	MMI_ASSERT(mmi_frm_get_previous_app_id(idle_app_id) == GRP_ID_INVALID);
	MMI_ASSERT(mmi_frm_get_previous_app_id(0x400) == idle_app_id);
	MMI_ASSERT(mmi_frm_get_previous_app_id(0x500) == 0x400);
	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x600, NULL, NULL, 0);
	MMI_ASSERT(mmi_frm_get_previous_app_id(idle_app_id) == GRP_ID_INVALID);
	MMI_ASSERT(mmi_frm_get_previous_app_id(0x400) == idle_app_id);
	MMI_ASSERT(mmi_frm_get_previous_app_id(0x500) == 0x400);
	MMI_ASSERT(mmi_frm_get_previous_app_id(0x600) == 0x500);
	mmi_frm_close_to_idle_group();
	create_history_screen(0x100, NULL);
	MMI_ASSERT(mmi_frm_get_previous_app_id(idle_app_id) == GRP_ID_INVALID);
	MMI_ASSERT(mmi_frm_get_previous_app_id(0x100) == idle_app_id);
	create_history_screen(0x200, NULL);
	MMI_ASSERT(mmi_frm_get_previous_app_id(idle_app_id) == GRP_ID_INVALID);
	MMI_ASSERT(mmi_frm_get_previous_app_id(0x100) == idle_app_id);
	MMI_ASSERT(mmi_frm_get_previous_app_id(0x200) == 0x100);
	return MMI_RET_OK;
}
mmi_ret xxx_group_proc(mmi_event_struct *evt)
{
	switch (evt->evt_id)
	{
		case EVT_ID_GROUP_ENTER:
		{
			mmi_scenario_evt_struct *p = (mmi_scenario_evt_struct *)evt;
			if (p->targ_group == 0x4000 && p->user_data == (void *)0x03162087)
			{
				mmi_frm_group_close(0x2000);
			}
			break;
		}

		case EVT_ID_NO_CHILD_NOTIFY:
		{
			mmi_scenario_evt_struct *p = (mmi_scenario_evt_struct *)evt;
			if (p->targ_group == 0x1000 && p->user_data == (void *)0x03162087)
			{
				mmi_frm_group_close(0x1000);
			}
			break;
		}
	}
	return MMI_RET_OK;
}
mmi_ret scrn_proc(mmi_event_struct *evt)
{
	if (evt->evt_id == EVT_ID_SCRN_INACTIVE)
	{
		mmi_frm_scrn_inactive_evt_struct *p = (mmi_frm_scrn_inactive_evt_struct *)evt;
		if (p->scrn_id == 35058 && p->user_data == (void *)0x03104056)
		{
			mmi_frm_group_create_ex(GRP_ID_ROOT, 0x800, xxx_group_proc, NULL, 0);
			mmi_frm_scrn_create(0x800, 0x900, scrn_proc, NULL);
		}
	}

	if (evt->evt_id == EVT_ID_SCRN_ACTIVE)
	{
		mmi_frm_scrn_active_evt_struct *p = (mmi_frm_scrn_active_evt_struct *)evt;
		ShowCategory74Screen(
			0,
			0,
			0,
			0,
			STR_GLOBAL_BACK,
			0,
			(U8 *)L"Hello World",
			mmi_ucs2strlen((CHAR*) L"Hello World"),
			(U8 *)p->gui_buffer);
		if (p->scrn_id == 0x500 && p->user_data == (void *)0x03106775 && p->is_first_active == MMI_FALSE)
		{
			mmi_idle_display();
		}
	}
	return MMI_RET_OK;
}


static void scrn_enter_null(mmi_scrn_essential_struct *arg)
{
    if (mmi_frm_scrn_enter(arg->group_id,
                            arg->scrn_id, 
                            (FuncPtr)NULL, 
                            NULL,
                            MMI_FRM_SMALL_SCRN))
    {

	}
}

mmi_ret MAUI_03104056(void *para)
{
	/*
	 * 35052(G)
	 *    35058(S)
	 * 0x400(G) 
	 *    0x500(G)
	 *        48350(S)
	 *    0x600(G)
	 *        48351(S)
	 *    
	 */
	mmi_frm_close_to_idle_group();
	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x400, xxx_group_proc, NULL, 0);
	mmi_frm_group_create_ex(0x400, 0x500, xxx_group_proc, NULL, 0);
	mmi_frm_scrn_create(0x500, 48350, scrn_proc, NULL);
	mmi_frm_group_create_ex(0x400, 0x600, xxx_group_proc, NULL, 0);
	mmi_frm_scrn_create(0x600, 48351, scrn_proc, NULL);

	mmi_frm_group_create_ex(GRP_ID_ROOT, 35052, xxx_group_proc, NULL, 0);
	mmi_frm_scrn_create(35052, 35058, scrn_proc, (void *)0x03104056);

	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x700, xxx_group_proc, NULL, 0);
	mmi_frm_scrn_first_enter(0x700, 0x1234, (FuncPtr)scrn_enter_null, NULL);
	mmi_frm_group_close(0x800);

	MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x1234);

	return MMI_RET_OK;
}

mmi_ret MMI_03106775(void *para)
{
	mmi_frm_close_to_idle_group();
	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x400, xxx_group_proc, NULL, 0);
	mmi_frm_scrn_create(0x400, 0x500, scrn_proc, (void *)0x03106775);

	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x600, xxx_group_proc, NULL, 0);
	mmi_frm_group_close(0x600);

	return MMI_RET_OK;
}
MMI_RET xxx_page_common_exit(mmi_scrn_essential_struct *data)
{
	return MMI_RET_OK;
}
MMI_RET xxx_page_common_enter(mmi_scrn_essential_struct *data)
{
    U8 *guiBuffer = NULL;
	U16 string_ids[] = {STR_GLOBAL_1, STR_GLOBAL_2, STR_GLOBAL_3, STR_GLOBAL_4} ;
    if (mmi_frm_scrn_tab_page_enter(
        data->group_id, 
        data->tab_id,
        data->scrn_id, 
        (FuncPtr)xxx_page_common_exit, 
        (FuncPtr)xxx_page_common_enter,
        MMI_FRM_TAB_PAGE) == MMI_FALSE)
    {
        return MMI_RET_OK;
    }

#ifndef __MMI_NOT_TAB_SUPPORT__
    guiBuffer = mmi_frm_scrn_tab_page_get_active_gui_buf();
#endif /* __MMI_NOT_TAB_SUPPORT__ */
    
    RegisterCat200SearchFunction(cat200_callback);

    ShowCategory199Screen(
            get_string(STR_GLOBAL_START),
            0,
            get_string(STR_GLOBAL_STOP),
            0,                 
            (S8)mmi_frm_scrn_tab_get_active_page_index(),
            get_string(string_ids[mmi_frm_scrn_tab_get_active_page_index()]),
            NULL,
            4,
            Get_List_Items,
            get_async_hints,
            NULL,
            NULL,
            0,
            (U8*) g_buffer,
            4,
            guiBuffer);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);
#endif /* __MMI_TOUCH_SCREEN__ */  
	return MMI_RET_OK;
}



MMI_RET xxx_tab_common_exit(mmi_scrn_essential_struct *data)
{
	return MMI_RET_OK;
}


MMI_RET xxx_tab_common_enter(mmi_scrn_essential_struct *data)
{
    mmi_frm_tab_struct pages[4] = {0};
    U32 i;
    U32 page_count = sizeof(pages)/sizeof(pages[0]);
	if (mmi_frm_scrn_get_gui_buf(data->group_id, data->scrn_id) != NULL)
	{
		static MMI_BOOL a = MMI_FALSE;
		page_count = a ? 4:2;
		a = !a;
	}
    for (i = 0; i < page_count; i++)
    {
        pages[i].screen_id = 0x3000 + i;
        pages[i].tab_entry_func = (FuncPtr)xxx_page_common_enter;
        pages[i].tab_icon = (U8*)GetImage(gIndexIconsImageList[i]);;
        pages[i].tab_string = NULL;
        pages[i].user_data = NULL;
    }
    mmi_frm_scrn_tab_enter(
        data->group_id,
        data->scrn_id,
        (FuncPtr)xxx_tab_common_exit,
        (FuncPtr)xxx_tab_common_enter,
        pages,
        page_count,
        0);
    
    return MMI_RET_OK;
}



void  xxx_create_tab_screen(MMI_ID group_id, MMI_ID tab_id, mmi_proc_func proc, void *user_data)
{

    mmi_frm_scrn_first_enter_ex(
        group_id, 
        tab_id,
        (FuncPtr)xxx_tab_common_enter, 
        user_data,
        proc);
}

MMI_RET xxx_tab_proc(mmi_event_struct *evt)
{

	return MMI_RET_OK;
}

MMI_RET tab_support_hide(void *para)
{
	U32 i;
    mmi_frm_group_create_ex(GRP_ID_ROOT, 0x1000, NULL, NULL, 1);
    xxx_create_tab_screen(0x1000, 0x2000, xxx_tab_proc, NULL);
	for (i = 0; i < 500;i++)
	{
		mmi_frm_group_create_ex(GRP_ID_ROOT, 0x5000, NULL, NULL, 1);
		mmi_frm_scrn_create(0x5000, 0x6000, scrn_proc, NULL);
		mmi_frm_group_close(0x5000);
	}
    return MMI_RET_OK;
}


MMI_RET MAUI_03162087(void *para)
{
	mmi_frm_close_to_idle_group();
	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x1000, xxx_group_proc, (void *)0x03162087, 0);
	mmi_frm_group_create_ex(0x1000, 0x2000, xxx_group_proc, (void *)0x03162087, 0);
	mmi_frm_scrn_create(0x2000, 0x3000, scrn_proc, NULL);
	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x4000, xxx_group_proc, (void *)0x3162087, 1);
	mmi_frm_scrn_create(0x4000, 0x3000, scrn_proc, NULL);
	MMI_ASSERT(mmi_frm_group_is_present(0x1000) == MMI_FALSE);
	return MMI_RET_OK;
}


const static mmi_unit_test_struct g_sg_ut[] =
{
    //{1, test_scrn_id_update},
    {1,  sg_smc_test_case_1},
    {2,  sg_smc_test_case_2},    
    {3,  sg_smc_test_case_3},    
    {4,  sg_smc_test_case_4},
    {5,  sg_smc_test_case_5},    
    {6,  sg_smc_test_case6},
    {7,  sg_smc_test_case7},    
    {8,  sg_smc_test_case_8},
    {9,  sg_smc_test_case_9}, 
    {10, sg_smc_test_case_10},
    {11, sg_smc_test_case_11},
    {12, sg_smc_test_case_12},
    {13, sg_smc_test_case_13},    
    {14, sg_smc_test_case_14},
    {15, sg_smc_test_case_15},    
    {16, sg_smc_test_case_16},
    {17, sg_smc_test_case_17},
    {18, sg_smc_test_case_18},    
    {19, sg_smc_test_case_19},
    {20, sg_smc_test_case_20},
    {21, sg_smc_test_case_21},
    {22, sg_smc_test_case_22},
    {23, sg_smc_test_case_23},
    {24, sg_smc_test_case_24},
    {25, sg_smc_test_case_25},
    {26, sg_smc_test_case_26},
    {27, rs_screen_test_case1},
    {28, rs_screen_test_case2},
    {29, rs_screen_test_case3},
    {30, rs_screen_test_case4},
    {31, rs_screen_test_case5},
    {32, rs_screen_test_case6},
    {33, rs_screen_test_case7},
    {34, rs_screen_test_case8},
    {35, stop_delete_test_case1},
    {36, stop_delete_test_case2},
    {37, stop_delete_test_case3},
    {38, end_key_process_test_case1},
    {39, end_key_process_test_case2},
    {40, small_screen_test_case1},
    {41, adaptor_node_related_test_case1},
    {42, sg_ree_test_case1},
    {43, prohibit_screen_enter_test1},
    {44, prohibit_screen_enter_test2},
    {45, sg_group_close_test},
    {46, create_close_proc},
    {47, scenario_multiple_close_test},
    {48, end_key_in_idle_group},
	{49, empty_group_close_test1},
	{50, empty_group_close_test2},
	{51, empty_group_close_test3},
    {52, set_active_group_test},
    {53, MAUI_02118353},
	{54, MAUI_02216247},
	{55, MAUI_02304522},
	{56, MAUI_02573189},

    {57, MAUI_02220671},
    {58, first_enter_post_case},
	{59, MAUI_02312790},
	{60, MAUI_02316418},
	{61, MAUI_02316329},
    {62, MAUI_02313807},
    {65, group_hide_test1},
	{66, SetBitCheck},
    {67, trace_check},
    {68, mmi_frm_binary_search_ex_test},
    {69, find_free_slot_test},
    {70, test_allocate_free_id_by_app_base},
    {71, hide_group_in_history},
    {72, group_hide_test2},
    {73, test_close_to_idle_with_start_id},
    {74, test_hide_post_case},
    {75, MAUI_02638067},
    {76, test_get_root_app},
    {77, group_hide_state_check},
	{78, group_hide_in_idle_check},
    {79, small_screen_check},
    {80, test_group_close_in_bg_tree},
	{81, MAUI_02640797},
	{82, focus_defocus_test},
	{83, end_key_flow_test},
	{84, end_key_flow_test2},
    {85, MAUI_02450790},
	{86, MAUI_02738851},
    {87, test_small_scrn_redraw},
    {88, MAUI_02742942},
    {89, MAUI_02962772},
	{90, test_mmi_frm_get_previous_app_id},
	{91, MAUI_03104056},
	{92, MMI_03106775},
	{93, MAUI_03162087},
    {94, sg_test}
};
#else
static U8 small_scrn_redraw_check = 0;
static U8 no_child_evt_times = 0;

mmi_ret mmi_group_proc_func(mmi_event_struct *param)
{
    mmi_ret ret = MMI_RET_OK;
    MMI_ID group_id = ((mmi_scenario_evt_struct*)param)->targ_group;
    MMI_ID scrn_id = ((mmi_scenario_evt_struct*)param)->targ_scrn;
    switch(param->evt_id)
    {
    case EVT_ID_GROUP_ENTER:
        kal_printf("\n[0x%4x] [0x%4x] EVT_ID_GROUP_ENTER", group_id, scrn_id);
        break;
    case EVT_ID_GROUP_ACTIVE:
        kal_printf("\n[0x%4x] [0x%4x] EVT_ID_GROUP_ACTIVE", group_id, scrn_id);
        break;
    case EVT_ID_GROUP_INACTIVE:
        kal_printf("\n[0x%4x] [0x%4x] EVT_ID_GROUP_INACTIVE", group_id, scrn_id);
        break;
    case EVT_ID_GROUP_FOCUSED:
        kal_printf("\n[0x%4x] [0x%4x] EVT_ID_GROUP_FOCUSED", group_id, scrn_id);
        break;
    case EVT_ID_GROUP_DEFOCUSED:
        kal_printf("\n[0x%4x] [0x%4x] EVT_ID_GROUP_DEFOCUSED", group_id, scrn_id);
        break;
    case EVT_ID_GROUP_GOBACK:
        {
            kal_printf("\n[0x%4x] [0x%4x] EVT_ID_GROUP_GOBACK", group_id, scrn_id);
            if(0x6666 == (U32)param->user_data)
                ret = MMI_RET_ERR;
            if(0x4444 == (U32)param->user_data)
                ret = MMI_RET_STOP_END_KEY_FLOW;
        }
        break;
    case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        {
            kal_printf("\n[0x%4x] [0x%4x] EVT_ID_GROUP_GOBACK_IN_END_KEY", group_id, scrn_id);
            if((U32)param->user_data == 0x9999)
            {
                mmi_frm_group_hide(0x400);
                ret = MMI_RET_ERR;
            }
            if(0x6666 == (U32)param->user_data)
                ret = MMI_RET_ERR;
            if(0x4444 == (U32)param->user_data)
                ret = MMI_RET_STOP_END_KEY_FLOW;
        }
        break;
    case EVT_ID_GROUP_DELETE_REQ:
        {
            kal_printf("\n[0x%4x] [0x%4x] EVT_ID_GROUP_DELETE_REQ", group_id, scrn_id);
            if(0x6666 == (U32)param->user_data)
                ret = MMI_RET_ERR;
            if(0x4444 == (U32)param->user_data)
                ret = MMI_RET_STOP_END_KEY_FLOW;

			if (0x03090630 == (U32)param->user_data)
			{
				MMI_ASSERT(0);
			}
        }
        break;
    case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
        {
            kal_printf("\n[0x%4x] [0x%4x] EVT_ID_GROUP_DELETE_REQ_IN_END_KEY", group_id, scrn_id);
            if(0x6666 == (U32)param->user_data)
                ret = MMI_RET_ERR;
            if(0x4444 == (U32)param->user_data)
                ret = MMI_RET_STOP_END_KEY_FLOW;

        }
        break;
    case EVT_ID_GROUP_EXIT:
        kal_printf("\n[0x%4x] [0x%4x] EVT_ID_GROUP_EXIT", group_id, scrn_id);
        break;
    case EVT_ID_GROUP_DEINIT:
        kal_printf("\n[0x%4x] [0x%4x] EVT_ID_GROUP_DEINIT", group_id, scrn_id);
		if (0x03090630 == (U32)param->user_data)
		{
			mmi_frm_group_close(0x100);
		}
		if (0x03149357 == (U32)param->user_data)
		{
			mmi_idle_display();
		}
        break;
    case EVT_ID_GROUP_REDRAW_START:
        kal_printf("\n[0x%4x] [0x%4x] EVT_ID_GROUP_REDRAW_START", group_id, scrn_id);
        break;
    case EVT_ID_GROUP_REDRAW_DONE:
        kal_printf("\n[0x%4x] [0x%4x] EVT_ID_GROUP_REDRAW_DONE", group_id, scrn_id);
        break;
    case EVT_ID_NO_CHILD_NOTIFY:
        kal_printf("\n[0x%4x] [0x%4x] EVT_ID_NO_CHILD_NOTIFY", group_id, scrn_id);
        no_child_evt_times++;
        break;
    case EVT_ID_GROUP_HIDE:
		kal_printf("\n[0x%4x] [0x%4x] EVT_ID_GROUP_HIDE", group_id, scrn_id);
        break;
    case EVT_ID_GROUP_UNHIDE:
        kal_printf("\n[0x%4x] [0x%4x] EVT_ID_GROUP_UNHIDE", group_id, scrn_id);
        break;

    default:
        break;
    }
    /* small screen redraw check */
    if(mmi_frm_scenario_is_redrawing())
    {
        if( EVT_ID_GROUP_REDRAW_START == param->evt_id )
        {
            if( (U32)param->user_data == 0x5502 )
                MMI_ASSERT(small_scrn_redraw_check++ == 0);
            if( (U32)param->user_data == 0x5504 )
                MMI_ASSERT(small_scrn_redraw_check++ == 1);
            if( (U32)param->user_data == 0x5505 )
                MMI_ASSERT(small_scrn_redraw_check++ == 10);
            if( (U32)param->user_data == 0x5506 )
                MMI_ASSERT(small_scrn_redraw_check++ == 11);
        }
        if( EVT_ID_GROUP_REDRAW_DONE == param->evt_id )
        {
            if( (U32)param->user_data == 0x5502 )
                MMI_ASSERT(small_scrn_redraw_check++ == 9);
            if( (U32)param->user_data == 0x5504 )
                MMI_ASSERT(small_scrn_redraw_check++ == 6);
            if( (U32)param->user_data == 0x5506 )
                MMI_ASSERT(small_scrn_redraw_check++ == 12);
            if( (U32)param->user_data == 0x5505 )
                MMI_ASSERT(small_scrn_redraw_check++ == 13);
        }
    }

    return ret;    
}

mmi_ret scrn_entry(mmi_scrn_essential_struct* data);
mmi_ret  scrn_leave_proc(mmi_event_struct *param);

void scrn_exit(mmi_scrn_essential_struct* data)
{
    kal_printf("\nscrn_exit groupID = [0x%x], scrnID = [0x%x]", data->group_id, data->scrn_id);
    if(mmi_frm_scenario_is_redrawing())
    {
        if(data->group_id == 0x400 && data->scrn_id == 0x4001)
            MMI_ASSERT(small_scrn_redraw_check++ == 3);
        if(data->group_id == 0x400 && data->scrn_id == 0x4002)
            MMI_ASSERT(small_scrn_redraw_check++ == 5);
        if(data->group_id == 0x200 && data->scrn_id == 0x2002)
            MMI_ASSERT(small_scrn_redraw_check++ == 8);
    }
	/* bootup and shutdown test */
	if(data->group_id == 32449 && data->scrn_id == 24765)
	{
		mmi_frm_node_struct group_info;

		mmi_frm_group_create(GRP_ID_ROOT, 32866, mmi_group_proc_func, 0);
		
		group_info.id = 32866;
		group_info.entry_proc = mmi_group_proc_func;
		group_info.user_data = NULL;

		mmi_frm_group_insert(GRP_ID_ROOT, 32449, &group_info, MMI_FRM_NODE_AFTER_FLAG);

		mmi_frm_scrn_first_enter(32866, 24766, (FuncPtr)scrn_entry,NULL);

		mmi_frm_group_close(32449);
	}
    if(data->group_id == 0x1402 && data->scrn_id == 0x1402)
    {
        mmi_frm_group_close(0x1402);
    }
    if(data->group_id == 38084 && data->scrn_id == 24434)
    {
        mmi_frm_close_all_background_groups();
    }
}
mmi_ret scrn_entry(mmi_scrn_essential_struct* data)
{
    mmi_ret ret = MMI_RET_OK;
    kal_printf("\nscrn_entry groupID = [0x%x], scrnID = [0x%x]", data->group_id, data->scrn_id);
    if(mmi_frm_scenario_is_redrawing())
    {
        if(data->group_id == 0x400 && data->scrn_id == 0x4001)
            MMI_ASSERT(small_scrn_redraw_check++ == 2);
        if(data->group_id == 0x400 && data->scrn_id == 0x4002)
            MMI_ASSERT(small_scrn_redraw_check++ == 4);
        if(data->group_id == 0x200 && data->scrn_id == 0x2002)
            MMI_ASSERT(small_scrn_redraw_check++ == 7);
    }
    if(mmi_frm_scrn_enter(data->group_id, data->scrn_id, (FuncPtr)scrn_exit, (FuncPtr)scrn_entry,MMI_FRM_FULL_SCRN))
    {
        ShowCategoryDummyScreen(); 
    }
    mmi_frm_scrn_set_leave_proc(data->group_id,data->scrn_id,scrn_leave_proc);
    
    return ret;
}
mmi_ret  scrn_leave_proc(mmi_event_struct *param)
{
    mmi_ret ret = MMI_RET_OK;
    MMI_ID group_id = ((mmi_scenario_evt_struct*)param)->targ_group;
    MMI_ID scrn_id = ((mmi_scenario_evt_struct*)param)->targ_scrn;
	static void *ptr = NULL;
    switch(param->evt_id)
    {
    case EVT_ID_SCRN_INIT:
        {
            group_id = ((mmi_frm_scrn_init_evt_struct*)param)->group_id; 
            scrn_id = ((mmi_frm_scrn_init_evt_struct*)param)->scrn_id;
            kal_printf("\n[0x%4x] [0x%4x] EVT_ID_SCRN_INIT", group_id, scrn_id);

			if (((void *)0x03095328 == param->user_data) && (scrn_id == 0x600))
			{
				mmi_frm_scrn_set_attribute(0x300, 0x600, MMI_SCRN_ATTRIB_SMALL_SCRN);
			}
        }
        break;
    case EVT_ID_SCRN_ACTIVE:
        {
			mmi_frm_scrn_active_evt_struct *p =  (mmi_frm_scrn_active_evt_struct *)param;
            group_id = ((mmi_frm_scrn_active_evt_struct*)param)->group_id; 
            scrn_id = ((mmi_frm_scrn_active_evt_struct*)param)->scrn_id;
            kal_printf("\n[0x%4x] [0x%4x] EVT_ID_SCRN_ACTIVE", group_id, scrn_id);
			
			if ((void *)0x03090135 == param->user_data)
			{
				
				if (p->is_first_active == MMI_FALSE)
				{
					MMI_ASSERT(mmi_frm_is_in_backward_scenario() == MMI_TRUE);
				}
			}
			if (((void *)0x03095328 == param->user_data) && (scrn_id == 0x500) && (p->is_first_active == MMI_FALSE))
			{
				mmi_frm_group_create(GRP_ID_ROOT, 0x3000, NULL, NULL);
			}

			if (((void *)0x03095328 == param->user_data) && (scrn_id == 0x600))
			{
				MMI_ASSERT(shell.scenario_dangle.m_tail->m_next == NULL);
			}

			if ((void *)0x03099990 == param->user_data && (p->is_first_active == MMI_FALSE))
			{
				mmi_scrn_essential_struct data;
				ptr = mmi_frm_scrmem_alloc(100);
				data.group_id = 0x300;
				data.scrn_id = 0x600;
				data.user_data = NULL;
				data.tab_id = 0x00;
				scrn_entry(&data);
			}
			if ((void *)0x03131247 == param->user_data && group_id == 0x400 && scrn_id == 0x500)
			{
				set_small_screen();
				MMI_ASSERT(p->is_bg_redrawing == 0);
			}
			if ((void *)0x03131247 == param->user_data && group_id == 0x300 && scrn_id == 0x500)
			{
				MMI_ASSERT(p->is_bg_redrawing == 0);
			}
			if ((void *)0x03144892 == param->user_data)
			{
				mmi_frm_group_close(group_id);
				MMI_ASSERT(mmi_frm_group_is_present(group_id) == MMI_TRUE);
			}
			if ((void *)0x03134995 == param->user_data && scrn_id == 0x600)
			{
				set_small_screen();
			}

			if ((void *)0x03134995 == param->user_data && scrn_id == 0x500)
			{
				MMI_ID id = mmi_frm_group_create(GRP_ID_ROOT, 0x1000, NULL, NULL);
				MMI_ASSERT(id == 0x1000);
				if (p->is_bg_redrawing)
				{
					MMI_ASSERT(id == 0x1000);
				}
			}

            if((void*)0x54575457 == param->user_data && scrn_id == 0x1300)
            {
                if(mmi_frm_scenario_is_redrawing())
                {
                    mmi_frm_scrn_create(0x1000, 0x1600, scrn_leave_proc, NULL);
                }
            }
        }
        break;
    case EVT_ID_SCRN_INACTIVE:
        {
            group_id = ((mmi_frm_scrn_inactive_evt_struct*)param)->group_id; 
            scrn_id = ((mmi_frm_scrn_inactive_evt_struct*)param)->scrn_id;
            kal_printf("\n[0x%4x] [0x%4x] EVT_ID_SCRN_INACTIVE", group_id, scrn_id);
			if (ptr != NULL)
			{
				mmi_frm_scrmem_free(ptr);
				ptr = NULL;
			}
			if ((void *)0x03134995 == param->user_data && scrn_id == 0x500)
			{
				mmi_frm_group_close(0x1000);
				MMI_ASSERT(mmi_frm_group_is_present(0x1000) == MMI_FALSE);
			}
        }
        break;
    case EVT_ID_SCRN_GOBACK:
        kal_printf("\n[0x%4x] [0x%4x] EVT_ID_SCRN_GOBACK", group_id, scrn_id);
        break;
    case EVT_ID_SCRN_DELETE_REQ:
        kal_printf("\n[0x%4x] [0x%4x] EVT_ID_SCRN_DELETE_REQ", group_id, scrn_id);
        break;
    case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        kal_printf("\n[0x%4x] [0x%4x] EVT_ID_SCRN_DELETE_REQ_IN_END_KEY", group_id, scrn_id);
        break;
    case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        kal_printf("\n[0x%4x] [0x%4x] EVT_ID_SCRN_GOBACK_IN_END_KEY", group_id, scrn_id);
        break;
    case EVT_ID_SCRN_DEINIT:
        kal_printf("\n[0x%4x] [0x%4x] EVT_ID_SCRN_DEINIT", group_id, scrn_id);
		if ((void *)0x03094319 == param->user_data)
		{
			MMI_ASSERT(IsBitSet(shell.state, MMI_SCENARIO_STATE_DEINIT_IDX));
			mmi_frm_group_close(0x300);
		}
        break;
    default:
        break;
    }
    if(0x6666666 == (U32)param->user_data)
        ret = MMI_RET_ERR;
    if(0x4444444 == (U32)param->user_data)
        ret = MMI_RET_STOP_END_KEY_FLOW;
    
    return ret;
}

/*
* scenario tree:
*
*                         group(0x500) --> scrn(0x5001)
*                             |
*         group(0x400)--> scrn(0x4001)
*           |                              scrn(0x3002)
*           |                                   |
*           |             group(0x300) --> scrn(0x3001)
*           |                 |
*         group(0x200)--> scrn(0x2001)
*           |
*           |             scrn(0x1002)
*           |                 |
* ROOT--> group(0x100)--> scrn(0x1001)
*/
mmi_ret sg_history_disable_test_case_1(void *para)
{
    MMI_ID active_group_id, active_scrn_id;
    mmi_scrn_essential_struct scrn_data = {0};
    
    active_group_id = mmi_frm_group_get_active_id();
    active_scrn_id = mmi_frm_scrn_get_active_id();
    
    mmi_frm_close_to_idle_group();

    kal_printf("\n *** sg_history_disable_test_case_1 *** ");
    mmi_frm_group_create(GRP_ID_ROOT, 0x100, mmi_group_proc_func, (void *)0x1101);
    mmi_frm_group_enter(0x100, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x100;
    scrn_data.scrn_id = 0x1001;
    scrn_entry(&scrn_data);
    scrn_data.scrn_id = 0x1002;
    scrn_entry(&scrn_data);

    mmi_frm_group_create(GRP_ID_ROOT, 0x200, mmi_group_proc_func, (void *)0x1102);
    mmi_frm_group_enter(0x200, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x200;
    scrn_data.scrn_id = 0x2001;
    scrn_entry(&scrn_data);
    mmi_frm_group_create(0x200, 0x300, mmi_group_proc_func, (void *)0x1103);
    mmi_frm_group_enter(0x300, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x300;
    scrn_data.scrn_id = 0x3001;
    scrn_entry(&scrn_data);
    scrn_data.group_id = 0x300;
    scrn_data.scrn_id = 0x3002;
    scrn_entry(&scrn_data);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x300);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x3002);

    mmi_frm_scrn_close(0x300, 0x3002);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x300);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x3001);

    mmi_frm_group_close(0x200);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x100);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x1002);

    
    mmi_frm_group_create(GRP_ID_ROOT, 0x200, mmi_group_proc_func, (void *)0x1102);
    mmi_frm_group_enter(0x200, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x200;
    scrn_data.scrn_id = 0x2001;
    scrn_entry(&scrn_data);
    mmi_frm_group_create(0x200, 0x300, mmi_group_proc_func, (void *)0x1103);
    mmi_frm_group_enter(0x300, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x300;
    scrn_data.scrn_id = 0x3001;
    scrn_entry(&scrn_data);
    scrn_data.group_id = 0x300;
    scrn_data.scrn_id = 0x3002;
    scrn_entry(&scrn_data);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x300);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x3002);

    mmi_frm_group_create(GRP_ID_ROOT, 0x400, mmi_group_proc_func, (void *)0x1104);
    mmi_frm_group_enter(0x400, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x400;
    scrn_data.scrn_id = 0x4001;
    scrn_entry(&scrn_data);
    mmi_frm_group_create(0x400, 0x500, mmi_group_proc_func, (void *)0x1105);
    mmi_frm_group_enter(0x500, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x500;
    scrn_data.scrn_id = 0x5001;
    scrn_entry(&scrn_data);

    mmi_frm_scrn_close(0x300, 0x3002);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x500);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x5001);

    mmi_frm_group_close(0x200);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x500);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x5001);

    kal_printf("\n *** go back to idle *** ");
    mmi_frm_close_to_idle_group();
    MMI_ASSERT(mmi_frm_group_get_active_id() == active_group_id);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == active_scrn_id);

    return MMI_RET_OK;
}
/*
* scenario tree:
*
*                         scrn(0x6003)
*                           |
*                         scrn(0x6002)
*                           |
*         group(0x600)--> scrn(0x6001)
*           |
*           |
*           |
*         group(0x500)--> scrn(0x5001)
*           |
*           |
*           |
*         group(0x400)
*           |
*           |             scrn(0x2002)
*           |               |
*           |             group(0x300)
*           |               |
*         group(0x200)--> scrn(0x2001)
*           |
*           |
*           |
* ROOT--> group(0x100)--> scrn(0x1001)
*/
mmi_ret sg_history_disable_test_case_2(void *para)
{
    mmi_scrn_essential_struct scrn_data = {0};
    mmi_frm_node_struct insert_node_info = {0};
    mmi_frm_close_to_idle_group();

    kal_printf("\n *** sg_history_disable_test_case_2 *** ");
    mmi_frm_group_create(GRP_ID_ROOT, 0x100, mmi_group_proc_func, (void *)0x2201);
    mmi_frm_group_enter(0x100, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x100;
    scrn_data.scrn_id = 0x1001;
    scrn_entry(&scrn_data);

    mmi_frm_group_create(GRP_ID_ROOT, 0x500, mmi_group_proc_func, (void *)0x2205);
    mmi_frm_group_enter(0x500, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x500;
    scrn_data.scrn_id = 0x5001;
    scrn_entry(&scrn_data);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x500);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x5001);

    insert_node_info.entry_proc = mmi_group_proc_func;
    insert_node_info.id = 0x400;
    insert_node_info.user_data = (void*)0x2204;
    mmi_frm_group_insert(GRP_ID_ROOT,0x500,&insert_node_info,MMI_FRM_NODE_BEFORE_FLAG);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x500);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x5001);

    insert_node_info.entry_proc = mmi_group_proc_func;
    insert_node_info.id = 0x200;
    insert_node_info.user_data = (void*)0x2202;
    mmi_frm_group_insert(GRP_ID_ROOT,0x100,&insert_node_info,MMI_FRM_NODE_AFTER_FLAG);
    scrn_data.group_id = 0x200;
    scrn_data.scrn_id = 0x2002;
    scrn_entry(&scrn_data);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x500);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x5001);

    insert_node_info.entry_proc = mmi_group_proc_func;
    insert_node_info.id = 0x300;
    insert_node_info.user_data = (void*)0x2203;
    mmi_frm_group_insert(0x200,0,&insert_node_info,MMI_FRM_NODE_AT_BEGINNING_FLAG);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x500);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x5001);

    insert_node_info.entry_proc = (mmi_proc_func)scrn_entry;
    insert_node_info.id = 0x2001;    
    mmi_frm_scrn_insert(0x200,0x300,&insert_node_info,MMI_FRM_NODE_BEFORE_FLAG);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x500);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x5001);

    insert_node_info.entry_proc = mmi_group_proc_func;
    insert_node_info.id = 0x600;
    insert_node_info.user_data = (void*)0x2206;
    mmi_frm_group_insert(GRP_ID_ROOT,0,&insert_node_info,MMI_FRM_NODE_AT_LATEST_FLAG);
    insert_node_info.entry_proc = (mmi_proc_func)scrn_entry;
    insert_node_info.id = 0x6002;
    mmi_frm_scrn_insert(0x600,0,&insert_node_info,MMI_FRM_NODE_AT_LATEST_FLAG);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    insert_node_info.entry_proc = (mmi_proc_func)scrn_entry;
    insert_node_info.id = 0x6001;
    mmi_frm_scrn_insert(0x600,0,&insert_node_info,MMI_FRM_NODE_AT_BEGINNING_FLAG);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);

    insert_node_info.entry_proc = (mmi_proc_func)scrn_entry;
    insert_node_info.id = 0x6003;
    mmi_frm_scrn_insert(0x600,0x6002,&insert_node_info,MMI_FRM_NODE_AFTER_FLAG);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6003);
    mmi_frm_close_to_idle_group();

    return MMI_RET_OK;
}

void construct_tree()
{
    mmi_scrn_essential_struct scrn_data = {0};
    HistoryDump();
    mmi_frm_invoke_post_event();
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */

    
    mmi_frm_group_create(GRP_ID_ROOT, 0x700, mmi_group_proc_func, (void *)0x3307);
    mmi_frm_group_enter(0x700, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x700;
    scrn_data.scrn_id = 0x7001;
    scrn_entry(&scrn_data);
    
    mmi_frm_group_create(GRP_ID_ROOT, 0x100, mmi_group_proc_func, (void *)0x3301);
    mmi_frm_group_enter(0x100, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x100;
    scrn_data.scrn_id = 0x1001;
    scrn_entry(&scrn_data);
    scrn_data.scrn_id = 0x1002;
    scrn_entry(&scrn_data);    
    mmi_frm_group_create(0x100, 0x200, mmi_group_proc_func, (void *)0x3302);
    mmi_frm_group_enter(0x200, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x200;
    scrn_data.scrn_id = 0x2001;
    scrn_entry(&scrn_data);
    scrn_data.scrn_id = 0x2002;
    scrn_entry(&scrn_data);
    mmi_frm_group_create(0x100, 0x300, mmi_group_proc_func, (void *)0x3303);
    mmi_frm_group_enter(0x300, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x300;
    scrn_data.scrn_id = 0x3001;
    scrn_entry(&scrn_data);
    scrn_data.scrn_id = 0x3002;
    scrn_entry(&scrn_data);

    mmi_frm_group_create(GRP_ID_ROOT, 0x400, mmi_group_proc_func, (void *)0x3304);
    mmi_frm_group_enter(0x400, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x400;
    scrn_data.scrn_id = 0x4001;
    scrn_entry(&scrn_data);
    scrn_data.scrn_id = 0x4002;
    scrn_entry(&scrn_data);
    mmi_frm_group_create(0x400, 0x500, mmi_group_proc_func, (void *)0x3305);
    mmi_frm_group_enter(0x500, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x500;
    scrn_data.scrn_id = 0x5001;
    scrn_entry(&scrn_data);
    scrn_data.scrn_id = 0x5002;
    scrn_entry(&scrn_data);
    mmi_frm_group_create(0x400, 0x600, mmi_group_proc_func, (void *)0x3306);
    mmi_frm_group_enter(0x600, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x600;
    scrn_data.scrn_id = 0x6001;
    scrn_entry(&scrn_data);
    scrn_data.scrn_id = 0x6002;
    scrn_entry(&scrn_data); 

    HistoryDump();
}
/* stop close, coutine */
mmi_ret sg_history_disable_test_case_3(void *para)
{
    kal_printf("\n *** sg_history_disable_test_case_3 *** ");
    construct_tree();

    // check close to root screen
    mmi_frm_close_to_root_screen(0x400);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x400);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x4001);
    MMI_ASSERT(!mmi_frm_scrn_is_present(0x400, 0x4002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x500));
    MMI_ASSERT(!mmi_frm_group_is_present(0x600));
    construct_tree();
    mmi_frm_close_to_root_screen(0x100);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_scrn_is_present(0x100, 0x1002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x200));
    MMI_ASSERT(!mmi_frm_group_is_present(0x300));   
    construct_tree();

    // goto idle, active group request stop
    mmi_frm_group_set_user_data(0x400,(void*)0x6666);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_group_set_user_data(0x400,(void*)0x3304);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x500));
    MMI_ASSERT(mmi_frm_group_is_present(0x600));
    MMI_ASSERT(!mmi_frm_group_is_present(0x100));
    construct_tree();
    // 
    mmi_frm_scrn_set_user_data(0x400,0x4001, (void*)0x6666666);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_scrn_set_user_data(0x400,0x4001, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x400);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x4001);    
    MMI_ASSERT(!mmi_frm_scrn_is_present(0x400, 0x4002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x500));
    MMI_ASSERT(!mmi_frm_group_is_present(0x600));
    MMI_ASSERT(!mmi_frm_group_is_present(0x100));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x400,0x4002, (void*)0x6666666);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_scrn_set_user_data(0x400,0x4002, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x400);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x4002);    
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x500));
    MMI_ASSERT(!mmi_frm_group_is_present(0x600));    
    MMI_ASSERT(!mmi_frm_group_is_present(0x100));
    construct_tree();
    //
    mmi_frm_group_set_user_data(0x500,(void*)0x6666);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_group_set_user_data(0x500,(void*)0x3305);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x500);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x5002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x500, 0x5001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x600));
    MMI_ASSERT(!mmi_frm_group_is_present(0x100));    
    construct_tree();
    // 
    mmi_frm_scrn_set_user_data(0x500,0x5001, (void*)0x6666666);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_scrn_set_user_data(0x500,0x5001, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x500);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x5001);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_scrn_is_present(0x500, 0x5002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x600));
    MMI_ASSERT(!mmi_frm_group_is_present(0x100));    
    construct_tree();    
    // 
    mmi_frm_scrn_set_user_data(0x500,0x5002, (void*)0x6666666);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_scrn_set_user_data(0x500,0x5002, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x500);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x5002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x500, 0x5001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x600));
    MMI_ASSERT(!mmi_frm_group_is_present(0x100));    
    construct_tree();
    // 
    mmi_frm_group_set_user_data(0x600,(void*)0x6666);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_group_set_user_data(0x600,(void*)0x3306);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x500));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x600, 0x6001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x100));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x600,0x6001, (void*)0x6666666);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_scrn_set_user_data(0x600,0x6001, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6001);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x500));
    MMI_ASSERT(!mmi_frm_scrn_is_present(0x600, 0x6002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x100));
    construct_tree();
    //
    kal_printf("\n\n *** sg_history_disable_test_case_3 active screen request stop*** ");
    mmi_frm_scrn_set_user_data(0x600,0x6002, (void*)0x6666666);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_scrn_set_user_data(0x600,0x6002, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x500));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x600, 0x6001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x100));
    construct_tree();

    // goto idle, inactive group request stop
    mmi_frm_group_set_user_data(0x100,(void*)0x6666);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_group_set_user_data(0x100,(void*)0x3301);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x300);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x3002);
    MMI_ASSERT(!mmi_frm_group_is_present(0x400));
    MMI_ASSERT(!mmi_frm_group_is_present(0x700));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x200));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x300, 0x3001, MMI_FRM_NODE_ALL_FLAG));
    construct_tree();
    // 
    mmi_frm_scrn_set_user_data(0x100,0x1001, (void*)0x6666666);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_scrn_set_user_data(0x100,0x1001, (void*)0);
    MMI_ASSERT(!mmi_frm_group_is_present(0x400));
    MMI_ASSERT(!mmi_frm_group_is_present(0x700));
    MMI_ASSERT(!mmi_frm_scrn_is_present(0x100, 0x1002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x200));
    MMI_ASSERT(!mmi_frm_group_is_present(0x300));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x100,0x1002, (void*)0x6666666);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_scrn_set_user_data(0x100,0x1002, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x100);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x1002);
    MMI_ASSERT(!mmi_frm_group_is_present(0x400));
    MMI_ASSERT(!mmi_frm_group_is_present(0x700));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x200));
    MMI_ASSERT(!mmi_frm_group_is_present(0x300));
    construct_tree();
    //
    mmi_frm_group_set_user_data(0x200,(void*)0x6666);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_group_set_user_data(0x200,(void*)0x3302);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x200);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x2002);
    MMI_ASSERT(!mmi_frm_group_is_present(0x400));
    MMI_ASSERT(!mmi_frm_group_is_present(0x700));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x200, 0x2001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x300));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x200,0x2001, (void*)0x6666666);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_scrn_set_user_data(0x200,0x2001, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x200);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x2001);
    MMI_ASSERT(!mmi_frm_group_is_present(0x400));
    MMI_ASSERT(!mmi_frm_group_is_present(0x700));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_scrn_is_present(0x200, 0x2002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x300));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x200,0x2002, (void*)0x6666666);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_scrn_set_user_data(0x200,0x2002, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x200);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x2002);
    MMI_ASSERT(!mmi_frm_group_is_present(0x400));
    MMI_ASSERT(!mmi_frm_group_is_present(0x700));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x200, 0x2001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x300));
    construct_tree();
    //
    mmi_frm_group_set_user_data(0x300,(void*)0x6666);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_group_set_user_data(0x300,(void*)0x3302);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x300);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x3002);
    MMI_ASSERT(!mmi_frm_group_is_present(0x400));
    MMI_ASSERT(!mmi_frm_group_is_present(0x700));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x200));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x300, 0x3001, MMI_FRM_NODE_ALL_FLAG));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x300,0x3001, (void*)0x6666666);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_scrn_set_user_data(0x300,0x3001, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x300);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x3001);
    MMI_ASSERT(!mmi_frm_group_is_present(0x400));
    MMI_ASSERT(!mmi_frm_group_is_present(0x700));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x200));
    MMI_ASSERT(!mmi_frm_scrn_is_present(0x300, 0x3002, MMI_FRM_NODE_ALL_FLAG));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x300,0x3002, (void*)0x6666666);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_scrn_set_user_data(0x300,0x3002, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x300);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x3002);
    MMI_ASSERT(!mmi_frm_group_is_present(0x400));
    MMI_ASSERT(!mmi_frm_group_is_present(0x700));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x200));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x300, 0x3001, MMI_FRM_NODE_ALL_FLAG));
    construct_tree();

    // close active group
    mmi_frm_group_set_user_data(0x400,(void*)0x6666);
    mmi_frm_group_close(0x400);
    mmi_frm_group_set_user_data(0x400,(void*)0x3304);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x500));
    MMI_ASSERT(mmi_frm_group_is_present(0x600));
    construct_tree();
    // 
    mmi_frm_scrn_set_user_data(0x400,0x4001, (void*)0x6666666);
    mmi_frm_group_close(0x400);
    mmi_frm_scrn_set_user_data(0x400,0x4001, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x400);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x4001);    
    MMI_ASSERT(!mmi_frm_scrn_is_present(0x400, 0x4002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x500));
    MMI_ASSERT(!mmi_frm_group_is_present(0x600));    
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x400,0x4002, (void*)0x6666666);
    mmi_frm_group_close(0x400);
    mmi_frm_scrn_set_user_data(0x400,0x4002, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x400);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x4002);    
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x500));
    MMI_ASSERT(!mmi_frm_group_is_present(0x600));    
    construct_tree();
    //
    mmi_frm_group_set_user_data(0x500,(void*)0x6666);
    mmi_frm_group_close(0x400);
    mmi_frm_group_set_user_data(0x500,(void*)0x3305);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x500);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x5002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x500, 0x5001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x600));
    MMI_ASSERT(mmi_frm_group_is_present(0x100));
    MMI_ASSERT(mmi_frm_group_is_present(0x700));
    construct_tree();
    // 
    mmi_frm_scrn_set_user_data(0x500,0x5001, (void*)0x6666666);
    mmi_frm_group_close(0x400);
    mmi_frm_scrn_set_user_data(0x500,0x5001, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x500);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x5001);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_scrn_is_present(0x500, 0x5002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x600));
    MMI_ASSERT(mmi_frm_group_is_present(0x100));
    MMI_ASSERT(mmi_frm_group_is_present(0x700));   
    construct_tree();    
    // 
    mmi_frm_scrn_set_user_data(0x500,0x5002, (void*)0x6666666);
    mmi_frm_group_close(0x400);
    mmi_frm_scrn_set_user_data(0x500,0x5002, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x500);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x5002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x500, 0x5001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x600));
    MMI_ASSERT(mmi_frm_group_is_present(0x100));
    MMI_ASSERT(mmi_frm_group_is_present(0x700));
    construct_tree();
    // 
    mmi_frm_group_set_user_data(0x600,(void*)0x6666);
    mmi_frm_group_close(0x400);
    mmi_frm_group_set_user_data(0x600,(void*)0x3306);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x500));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x600, 0x6001, MMI_FRM_NODE_ALL_FLAG));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x600,0x6001, (void*)0x6666666);
    mmi_frm_group_close(0x400);
    mmi_frm_scrn_set_user_data(0x600,0x6001, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6001);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x500));
    MMI_ASSERT(!mmi_frm_scrn_is_present(0x600, 0x6002, MMI_FRM_NODE_ALL_FLAG));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x600,0x6002, (void*)0x6666666);
    mmi_frm_group_close(0x400);
    mmi_frm_scrn_set_user_data(0x600,0x6002, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x500));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x600, 0x6001, MMI_FRM_NODE_ALL_FLAG));
    construct_tree();
    // 
    mmi_frm_group_set_user_data(0x600,(void*)0x6666);
    mmi_frm_group_close(0x600);
    mmi_frm_group_set_user_data(0x600,(void*)0x3304);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x600, 0x6001, MMI_FRM_NODE_ALL_FLAG));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x600,0x6001, (void*)0x6666666);
    mmi_frm_group_close(0x600);
    mmi_frm_scrn_set_user_data(0x600,0x6001, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6001);
    MMI_ASSERT(!mmi_frm_scrn_is_present(0x600, 0x6002, MMI_FRM_NODE_ALL_FLAG));
    construct_tree();
    //    
    mmi_frm_scrn_set_user_data(0x600,0x6002, (void*)0x6666666);
    mmi_frm_group_close(0x600);
    mmi_frm_scrn_set_user_data(0x600,0x6002, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x600, 0x6001, MMI_FRM_NODE_ALL_FLAG));
    construct_tree();
    //    
    mmi_frm_scrn_set_user_data(0x600,0x6002, (void*)0x6666666);
    mmi_frm_scrn_close(0x600, 0x6002);
    mmi_frm_scrn_set_user_data(0x600,0x6002, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x600,0x6001, (void*)0x6666666);
    mmi_frm_scrn_close(0x600, 0x6001);
    mmi_frm_scrn_set_user_data(0x600,0x6001, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x600, 0x6001, MMI_FRM_NODE_ALL_FLAG));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x500,0x5001, (void*)0x6666666);
    mmi_frm_group_close(0x500);
    mmi_frm_scrn_set_user_data(0x500,0x5001, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(!mmi_frm_scrn_is_present(0x500, 0x5002, MMI_FRM_NODE_ALL_FLAG));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x500,0x5001, (void*)0x6666666);
    mmi_frm_scrn_close(0x500, 0x5001);
    mmi_frm_scrn_set_user_data(0x500,0x5001, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x500, 0x5001, MMI_FRM_NODE_ALL_FLAG));
    construct_tree();
    // close inactive group
    mmi_frm_group_set_user_data(0x100,(void*)0x6666);
    mmi_frm_group_close(0x100);
    mmi_frm_group_set_user_data(0x100,(void*)0x3301);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x200));
    MMI_ASSERT(mmi_frm_group_is_present(0x300));
    construct_tree();
    // 
    mmi_frm_scrn_set_user_data(0x100,0x1001, (void*)0x6666666);
    mmi_frm_group_close(0x100);
    mmi_frm_scrn_set_user_data(0x100,0x1001, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(!mmi_frm_scrn_is_present(0x100, 0x1002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x200));
    MMI_ASSERT(!mmi_frm_group_is_present(0x300));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x100,0x1002, (void*)0x6666666);
    mmi_frm_group_close(0x100);
    mmi_frm_scrn_set_user_data(0x100,0x1002, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x200));
    MMI_ASSERT(!mmi_frm_group_is_present(0x300));
    construct_tree();
    //
    mmi_frm_group_set_user_data(0x200,(void*)0x6666);
    mmi_frm_group_close(0x100);
    mmi_frm_group_set_user_data(0x200,(void*)0x3302);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x200, 0x2001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x300));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x200,0x2001, (void*)0x6666666);
    mmi_frm_group_close(0x100);
    mmi_frm_scrn_set_user_data(0x200,0x2001, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_scrn_is_present(0x200, 0x2002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x300));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x200,0x2002, (void*)0x6666666);
    mmi_frm_group_close(0x100);
    mmi_frm_scrn_set_user_data(0x200,0x2002, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x200, 0x2001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x300));
    construct_tree();
    //
    mmi_frm_group_set_user_data(0x300,(void*)0x6666);
    mmi_frm_group_close(0x100);
    mmi_frm_group_set_user_data(0x300,(void*)0x3302);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x200));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x300, 0x3002, MMI_FRM_NODE_ALL_FLAG));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x300,0x3001, (void*)0x6666666);
    mmi_frm_group_close(0x100);
    mmi_frm_scrn_set_user_data(0x300,0x3001, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x200));
    MMI_ASSERT(!mmi_frm_scrn_is_present(0x300, 0x3002, MMI_FRM_NODE_ALL_FLAG));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x300,0x3002, (void*)0x6666666);
    mmi_frm_group_close(0x100);
    mmi_frm_scrn_set_user_data(0x300,0x3002, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x200));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x300, 0x3002, MMI_FRM_NODE_ALL_FLAG));
    construct_tree();
    
    //
    mmi_frm_group_set_user_data(0x300,(void*)0x6666);
    mmi_frm_group_close(0x300);
    mmi_frm_group_set_user_data(0x300,(void*)0x3303);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x300, 0x3001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x300, 0x3002, MMI_FRM_NODE_ALL_FLAG));
    construct_tree();
    //
    mmi_frm_group_set_user_data(0x200,(void*)0x6666);
    mmi_frm_group_close(0x200);
    mmi_frm_group_set_user_data(0x200,(void*)0x3302);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x200, 0x2001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x200, 0x2002, MMI_FRM_NODE_ALL_FLAG));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x300,0x3002, (void*)0x6666666);
    mmi_frm_scrn_close(0x300, 0x3002);
    mmi_frm_scrn_set_user_data(0x300,0x3002, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x300, 0x3002, MMI_FRM_NODE_ALL_FLAG));
    construct_tree();   
    //
    mmi_frm_scrn_set_user_data(0x200,0x2001, (void*)0x6666666);
    mmi_frm_scrn_close(0x200, 0x2001);
    mmi_frm_scrn_set_user_data(0x200,0x2001, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x200, 0x2001, MMI_FRM_NODE_ALL_FLAG));
    //
    mmi_frm_scrn_set_user_data(0x200,0x2001, (void*)0x6666666);
    mmi_frm_group_close(0x200);
    mmi_frm_scrn_set_user_data(0x200,0x2001, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(!mmi_frm_scrn_is_present(0x200, 0x2002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x200, 0x2001, MMI_FRM_NODE_ALL_FLAG));
    
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);
    return MMI_RET_OK;
}

mmi_ret sg_history_disable_test_case_4(void *para)
{
    construct_tree(); 

    // goto idle, active group request stop
    mmi_frm_group_set_user_data(0x400,(void*)0x4444);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_group_set_user_data(0x400,(void*)0x3304);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x500));
    MMI_ASSERT(mmi_frm_group_is_present(0x600));
    MMI_ASSERT(mmi_frm_group_is_present(0x100));
    MMI_ASSERT(mmi_frm_group_is_present(0x700));
    construct_tree();
    // 
    mmi_frm_scrn_set_user_data(0x400,0x4001, (void*)0x4444444);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_scrn_set_user_data(0x400,0x4001, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x400);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x4001);    
    MMI_ASSERT(!mmi_frm_scrn_is_present(0x400, 0x4002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x500));
    MMI_ASSERT(!mmi_frm_group_is_present(0x600));
    MMI_ASSERT(mmi_frm_group_is_present(0x100));
    MMI_ASSERT(mmi_frm_group_is_present(0x700));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x400,0x4002, (void*)0x4444444);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_scrn_set_user_data(0x400,0x4002, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x400);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x4002);    
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x500));
    MMI_ASSERT(!mmi_frm_group_is_present(0x600));    
    MMI_ASSERT(mmi_frm_group_is_present(0x100));
    MMI_ASSERT(mmi_frm_group_is_present(0x700));
    construct_tree();
    //
    mmi_frm_group_set_user_data(0x500,(void*)0x4444);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_group_set_user_data(0x500,(void*)0x3305);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x500);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x5002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x500, 0x5001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x600));
    MMI_ASSERT(mmi_frm_group_is_present(0x100));
    MMI_ASSERT(mmi_frm_group_is_present(0x700));
    construct_tree();
    // 
    mmi_frm_scrn_set_user_data(0x500,0x5001, (void*)0x4444444);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_scrn_set_user_data(0x500,0x5001, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x500);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x5001);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_scrn_is_present(0x500, 0x5002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x600));
    MMI_ASSERT(mmi_frm_group_is_present(0x100));
    MMI_ASSERT(mmi_frm_group_is_present(0x700));
    construct_tree();    
    // 
    mmi_frm_scrn_set_user_data(0x500,0x5002, (void*)0x4444444);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_scrn_set_user_data(0x500,0x5002, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x500);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x5002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x500, 0x5001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x600));
    MMI_ASSERT(mmi_frm_group_is_present(0x100));
    MMI_ASSERT(mmi_frm_group_is_present(0x700));
    construct_tree();
    // 
    mmi_frm_group_set_user_data(0x600,(void*)0x4444);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_group_set_user_data(0x600,(void*)0x3306);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x500));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x600, 0x6001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x100));
    MMI_ASSERT(mmi_frm_group_is_present(0x700));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x600,0x6001, (void*)0x4444444);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_scrn_set_user_data(0x600,0x6001, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6001);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x500));
    MMI_ASSERT(!mmi_frm_scrn_is_present(0x600, 0x6002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x100));
    MMI_ASSERT(mmi_frm_group_is_present(0x700));
    construct_tree();
    //
    kal_printf("\n\n *** sg_history_disable_test_case_3 active screen request stop*** ");
    mmi_frm_scrn_set_user_data(0x600,0x6002, (void*)0x4444444);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_scrn_set_user_data(0x600,0x6002, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x500));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x600, 0x6001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x100));
    MMI_ASSERT(mmi_frm_group_is_present(0x700));
    construct_tree();

    // goto idle, inactive group request stop
    mmi_frm_group_set_user_data(0x100,(void*)0x4444);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_group_set_user_data(0x100,(void*)0x3301);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x300);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x3002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x200));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x300, 0x3001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x400));
    MMI_ASSERT(mmi_frm_group_is_present(0x700));
    construct_tree();
    // 
    mmi_frm_scrn_set_user_data(0x100,0x1001, (void*)0x4444444);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_scrn_set_user_data(0x100,0x1001, (void*)0);
    MMI_ASSERT(!mmi_frm_scrn_is_present(0x100, 0x1002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x200));
    MMI_ASSERT(!mmi_frm_group_is_present(0x300));
    MMI_ASSERT(!mmi_frm_group_is_present(0x400));
    MMI_ASSERT(mmi_frm_group_is_present(0x700));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x100,0x1002, (void*)0x4444444);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_scrn_set_user_data(0x100,0x1002, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x100);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x1002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x200));
    MMI_ASSERT(!mmi_frm_group_is_present(0x300));
    MMI_ASSERT(!mmi_frm_group_is_present(0x400));
    MMI_ASSERT(mmi_frm_group_is_present(0x700));
    construct_tree();
    //
    mmi_frm_group_set_user_data(0x200,(void*)0x4444);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_group_set_user_data(0x200,(void*)0x3302);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x200);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x2002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x200, 0x2001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x300));
    MMI_ASSERT(!mmi_frm_group_is_present(0x400));
    MMI_ASSERT(mmi_frm_group_is_present(0x700));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x200,0x2001, (void*)0x4444444);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_scrn_set_user_data(0x200,0x2001, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x200);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x2001);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_scrn_is_present(0x200, 0x2002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x300));
    MMI_ASSERT(!mmi_frm_group_is_present(0x400));
    MMI_ASSERT(mmi_frm_group_is_present(0x700));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x200,0x2002, (void*)0x4444444);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_scrn_set_user_data(0x200,0x2002, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x200);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x2002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x200, 0x2001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x300));
    MMI_ASSERT(!mmi_frm_group_is_present(0x400));
    MMI_ASSERT(mmi_frm_group_is_present(0x700));
    construct_tree();
    //
    mmi_frm_group_set_user_data(0x300,(void*)0x4444);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_group_set_user_data(0x300,(void*)0x3302);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x300);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x3002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x200));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x300, 0x3001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x400));
    MMI_ASSERT(mmi_frm_group_is_present(0x700));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x300,0x3001, (void*)0x4444444);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_scrn_set_user_data(0x300,0x3001, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x300);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x3001);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x200));
    MMI_ASSERT(!mmi_frm_scrn_is_present(0x300, 0x3002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x400));
    MMI_ASSERT(mmi_frm_group_is_present(0x700));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x300,0x3002, (void*)0x4444444);
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);/* GRP_ID_IDLE_MAIN */
    mmi_frm_scrn_set_user_data(0x300,0x3002, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x300);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x3002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x200));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x300, 0x3001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x400));
    MMI_ASSERT(mmi_frm_group_is_present(0x700));
    construct_tree();

    // close active group
    mmi_frm_group_set_user_data(0x400,(void*)0x4444);
    mmi_frm_group_close(0x400);
    mmi_frm_group_set_user_data(0x400,(void*)0x3304);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x500));
    MMI_ASSERT(mmi_frm_group_is_present(0x600));
    construct_tree();
    // 
    mmi_frm_scrn_set_user_data(0x400,0x4001, (void*)0x4444444);
    mmi_frm_group_close(0x400);
    mmi_frm_scrn_set_user_data(0x400,0x4001, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x400);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x4001);    
    MMI_ASSERT(!mmi_frm_scrn_is_present(0x400, 0x4002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x500));
    MMI_ASSERT(!mmi_frm_group_is_present(0x600));    
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x400,0x4002, (void*)0x4444444);
    mmi_frm_group_close(0x400);
    mmi_frm_scrn_set_user_data(0x400,0x4002, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x400);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x4002);    
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x500));
    MMI_ASSERT(!mmi_frm_group_is_present(0x600));    
    construct_tree();
    //
    mmi_frm_group_set_user_data(0x500,(void*)0x4444);
    mmi_frm_group_close(0x400);
    mmi_frm_group_set_user_data(0x500,(void*)0x3305);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x500);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x5002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x500, 0x5001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x600));
    MMI_ASSERT(mmi_frm_group_is_present(0x100));
    MMI_ASSERT(mmi_frm_group_is_present(0x700));
    construct_tree();
    // 
    mmi_frm_scrn_set_user_data(0x500,0x5001, (void*)0x4444444);
    mmi_frm_group_close(0x400);
    mmi_frm_scrn_set_user_data(0x500,0x5001, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x500);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x5001);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_scrn_is_present(0x500, 0x5002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x600));
    MMI_ASSERT(mmi_frm_group_is_present(0x100));
    MMI_ASSERT(mmi_frm_group_is_present(0x700));   
    construct_tree();    
    // 
    mmi_frm_scrn_set_user_data(0x500,0x5002, (void*)0x4444444);
    mmi_frm_group_close(0x400);
    mmi_frm_scrn_set_user_data(0x500,0x5002, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x500);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x5002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x500, 0x5001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x600));
    MMI_ASSERT(mmi_frm_group_is_present(0x100));
    MMI_ASSERT(mmi_frm_group_is_present(0x700));
    construct_tree();
    // 
    mmi_frm_group_set_user_data(0x600,(void*)0x4444);
    mmi_frm_group_close(0x400);
    mmi_frm_group_set_user_data(0x600,(void*)0x3306);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x500));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x600, 0x6001, MMI_FRM_NODE_ALL_FLAG));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x600,0x6001, (void*)0x4444444);
    mmi_frm_group_close(0x400);
    mmi_frm_scrn_set_user_data(0x600,0x6001, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6001);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x500));
    MMI_ASSERT(!mmi_frm_scrn_is_present(0x600, 0x6002, MMI_FRM_NODE_ALL_FLAG));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x600,0x6002, (void*)0x4444444);
    mmi_frm_group_close(0x400);
    mmi_frm_scrn_set_user_data(0x600,0x6002, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x400, 0x4002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x500));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x600, 0x6001, MMI_FRM_NODE_ALL_FLAG));
    construct_tree();
    // 
    mmi_frm_group_set_user_data(0x600,(void*)0x4444);
    mmi_frm_group_close(0x600);
    mmi_frm_group_set_user_data(0x600,(void*)0x3304);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x600, 0x6001, MMI_FRM_NODE_ALL_FLAG));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x600,0x6001, (void*)0x4444444);
    mmi_frm_group_close(0x600);
    mmi_frm_scrn_set_user_data(0x600,0x6001, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6001);
    MMI_ASSERT(!mmi_frm_scrn_is_present(0x600, 0x6002, MMI_FRM_NODE_ALL_FLAG));
    construct_tree();
    //    
    mmi_frm_scrn_set_user_data(0x600,0x6002, (void*)0x4444444);
    mmi_frm_group_close(0x600);
    mmi_frm_scrn_set_user_data(0x600,0x6002, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x600, 0x6001, MMI_FRM_NODE_ALL_FLAG));
    construct_tree();
    //    
    mmi_frm_scrn_set_user_data(0x600,0x6002, (void*)0x4444444);
    mmi_frm_scrn_close(0x600, 0x6002);
    mmi_frm_scrn_set_user_data(0x600,0x6002, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x600,0x6001, (void*)0x4444444);
    mmi_frm_scrn_close(0x600, 0x6001);
    mmi_frm_scrn_set_user_data(0x600,0x6001, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x600, 0x6001, MMI_FRM_NODE_ALL_FLAG));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x500,0x5001, (void*)0x4444444);
    mmi_frm_group_close(0x500);
    mmi_frm_scrn_set_user_data(0x500,0x5001, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(!mmi_frm_scrn_is_present(0x500, 0x5002, MMI_FRM_NODE_ALL_FLAG));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x500,0x5001, (void*)0x4444444);
    mmi_frm_scrn_close(0x500, 0x5001);
    mmi_frm_scrn_set_user_data(0x500,0x5001, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x500, 0x5001, MMI_FRM_NODE_ALL_FLAG));
    construct_tree();
    // close inactive group
    mmi_frm_group_set_user_data(0x100,(void*)0x4444);
    mmi_frm_group_close(0x100);
    mmi_frm_group_set_user_data(0x100,(void*)0x3301);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x200));
    MMI_ASSERT(mmi_frm_group_is_present(0x300));
    construct_tree();
    // 
    mmi_frm_scrn_set_user_data(0x100,0x1001, (void*)0x4444444);
    mmi_frm_group_close(0x100);
    mmi_frm_scrn_set_user_data(0x100,0x1001, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(!mmi_frm_scrn_is_present(0x100, 0x1002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x200));
    MMI_ASSERT(!mmi_frm_group_is_present(0x300));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x100,0x1002, (void*)0x4444444);
    mmi_frm_group_close(0x100);
    mmi_frm_scrn_set_user_data(0x100,0x1002, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x200));
    MMI_ASSERT(!mmi_frm_group_is_present(0x300));
    construct_tree();
    //
    mmi_frm_group_set_user_data(0x200,(void*)0x4444);
    mmi_frm_group_close(0x100);
    mmi_frm_group_set_user_data(0x200,(void*)0x3302);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x200, 0x2001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x300));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x200,0x2001, (void*)0x4444444);
    mmi_frm_group_close(0x100);
    mmi_frm_scrn_set_user_data(0x200,0x2001, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_scrn_is_present(0x200, 0x2002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x300));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x200,0x2002, (void*)0x4444444);
    mmi_frm_group_close(0x100);
    mmi_frm_scrn_set_user_data(0x200,0x2002, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x200, 0x2001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(!mmi_frm_group_is_present(0x300));
    construct_tree();
    //
    mmi_frm_group_set_user_data(0x300,(void*)0x4444);
    mmi_frm_group_close(0x100);
    mmi_frm_group_set_user_data(0x300,(void*)0x3302);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x200));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x300, 0x3002, MMI_FRM_NODE_ALL_FLAG));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x300,0x3001, (void*)0x4444444);
    mmi_frm_group_close(0x100);
    mmi_frm_scrn_set_user_data(0x300,0x3001, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x200));
    MMI_ASSERT(!mmi_frm_scrn_is_present(0x300, 0x3002, MMI_FRM_NODE_ALL_FLAG));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x300,0x3002, (void*)0x4444444);
    mmi_frm_group_close(0x100);
    mmi_frm_scrn_set_user_data(0x300,0x3002, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x100, 0x1002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_group_is_present(0x200));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x300, 0x3002, MMI_FRM_NODE_ALL_FLAG));
    construct_tree();
    
    //
    mmi_frm_group_set_user_data(0x300,(void*)0x4444);
    mmi_frm_group_close(0x300);
    mmi_frm_group_set_user_data(0x300,(void*)0x3303);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x300, 0x3001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x300, 0x3002, MMI_FRM_NODE_ALL_FLAG));
    construct_tree();
    //
    mmi_frm_group_set_user_data(0x200,(void*)0x4444);
    mmi_frm_group_close(0x200);
    mmi_frm_group_set_user_data(0x200,(void*)0x3302);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x200, 0x2001, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x200, 0x2002, MMI_FRM_NODE_ALL_FLAG));
    construct_tree();
    //
    mmi_frm_scrn_set_user_data(0x300,0x3002, (void*)0x4444444);
    mmi_frm_scrn_close(0x300, 0x3002);
    mmi_frm_scrn_set_user_data(0x300,0x3002, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x300, 0x3002, MMI_FRM_NODE_ALL_FLAG));
    construct_tree();   
    //
    mmi_frm_scrn_set_user_data(0x200,0x2001, (void*)0x4444444);
    mmi_frm_scrn_close(0x200, 0x2001);
    mmi_frm_scrn_set_user_data(0x200,0x2001, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(mmi_frm_scrn_is_present(0x200, 0x2001, MMI_FRM_NODE_ALL_FLAG));
    //
    mmi_frm_scrn_set_user_data(0x200,0x2001, (void*)0x4444444);
    mmi_frm_group_close(0x200);
    mmi_frm_scrn_set_user_data(0x200,0x2001, (void*)0);
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x600);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x6002);
    MMI_ASSERT(!mmi_frm_scrn_is_present(0x200, 0x2002, MMI_FRM_NODE_ALL_FLAG));
    MMI_ASSERT(mmi_frm_scrn_is_present(0x200, 0x2001, MMI_FRM_NODE_ALL_FLAG));
    
    mmi_frm_close_to_idle_group();
    mmi_frm_close_to_root_screen(shell.scenario_root.m_head->id);
    return MMI_RET_OK;
}

/*
* scenario tree:
*
*                                          scrn(0x6002)
*                                            |
*         group(0x500)--> group(0x600) --> scrn(0x6001)
*           |
*           |
*           |             scrn(0x2002)    scrn(0x4002)
*           |               |                |
*           |             group(0x400)--> full scrn(0x4001)
*           |               |
*           |             group(0x300)--> scrn(0x3001)
*           |               |
*         group(0x200)--> scrn(0x2001)
*           |
*           |
*           |
* ROOT--> group(0x100)--> scrn(0x1001)
*/
mmi_ret sg_history_disable_test_case_5(void *para)
{
    mmi_scrn_essential_struct scrn_data = {0};
    
    mmi_frm_close_to_idle_group();

    kal_printf("\n *** sg_history_disable_test_case_5 *** ");
    mmi_frm_group_create(GRP_ID_ROOT, 0x100, mmi_group_proc_func, (void *)0x5501);
    mmi_frm_group_enter(0x100, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x100;
    scrn_data.scrn_id = 0x1001;
    scrn_entry(&scrn_data);
    mmi_frm_scrn_set_attribute(0x100,0x1001,MMI_SCRN_ATTRIB_SMALL_SCRN);

    mmi_frm_group_create(GRP_ID_ROOT, 0x200, mmi_group_proc_func, (void *)0x5502);
    mmi_frm_group_enter(0x200, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x200;
    scrn_data.scrn_id = 0x2001;
    scrn_entry(&scrn_data);
    mmi_frm_scrn_set_attribute(0x200,0x2001,MMI_SCRN_ATTRIB_SMALL_SCRN);
    mmi_frm_group_create(0x200, 0x300, mmi_group_proc_func, (void *)0x5503);
    mmi_frm_group_enter(0x300, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x300;
    scrn_data.scrn_id = 0x3001;
    scrn_entry(&scrn_data);
    mmi_frm_scrn_set_attribute(0x300,0x3001,MMI_SCRN_ATTRIB_SMALL_SCRN);
    mmi_frm_group_create(0x200, 0x400, mmi_group_proc_func, (void *)0x5504);
    mmi_frm_group_enter(0x400, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x400;
    scrn_data.scrn_id = 0x4001;
    scrn_entry(&scrn_data);
    scrn_data.scrn_id = 0x4002;
    scrn_entry(&scrn_data);
    mmi_frm_scrn_set_attribute(0x400,0x4002,MMI_SCRN_ATTRIB_SMALL_SCRN);
    scrn_data.group_id = 0x200;
    scrn_data.scrn_id = 0x2002;
    scrn_entry(&scrn_data);
    mmi_frm_scrn_set_attribute(0x200,0x2002,MMI_SCRN_ATTRIB_SMALL_SCRN);
    
    mmi_frm_group_create(GRP_ID_ROOT, 0x500, mmi_group_proc_func, (void *)0x5505);
    mmi_frm_group_enter(0x500, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_group_create(0x500, 0x600, mmi_group_proc_func, (void *)0x5506);
    mmi_frm_group_enter(0x600, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x600;
    scrn_data.scrn_id = 0x6001;
    scrn_entry(&scrn_data);
    mmi_frm_scrn_set_attribute(0x600,0x6001,MMI_SCRN_ATTRIB_SMALL_SCRN);
    scrn_data.scrn_id = 0x6002;
    scrn_entry(&scrn_data);
    mmi_frm_scrn_set_attribute(0x600,0x6002,MMI_SCRN_ATTRIB_SMALL_SCRN);

    small_scrn_redraw_check = 0;
    mmi_frm_scrn_close(0x600,0x6002);
    /*
    Background draw:
    * [0x5502] EVT_ID_GROUP_REDRAW_START
    * [0x5504] EVT_ID_GROUP_REDRAW_START
    * scrn_entry groupID = [0x400], scrnID = [0x4001]
    * scrn_exit groupID = [0x400], scrnID = [0x4001]
    * scrn_entry groupID = [0x400], scrnID = [0x4002]
    * scrn_exit groupID = [0x400], scrnID = [0x4002]
    * [0x5504] EVT_ID_GROUP_REDRAW_DONE
    * scrn_entry groupID = [0x200], scrnID = [0x2002]
    * scrn_exit groupID = [0x200], scrnID = [0x2002]
    * [0x5502] EVT_ID_GROUP_REDRAW_DONE
    *
    * [0x5505] EVT_ID_GROUP_REDRAW_START
    * [0x5506] EVT_ID_GROUP_REDRAW_START
    * [0x5506] EVT_ID_GROUP_REDRAW_DONE
    * [0x5505] EVT_ID_GROUP_REDRAW_DONE

    Foreground draw:
    * scrn_entry groupID = [0x600], scrnID = [0x6001]
    */
    MMI_ASSERT(small_scrn_redraw_check == 14);
    return MMI_RET_OK;
}
static U8 slim_check = 0;
/* slim test case */
mmi_ret mmi_proc_slim_func(mmi_event_struct *param)
{
    mmi_ret ret = MMI_RET_OK;
    switch(param->evt_id)
    {
        case EVT_ID_SCRN_INIT:
        {}
        break;
        case EVT_ID_SCRN_ACTIVE:
        {
            mmi_frm_scrn_active_evt_struct *p = (mmi_frm_scrn_active_evt_struct *)param;
            ShowCategory74Screen(
                STR_GLOBAL_MESSAGE,
                0,
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                (PU8)L"Hello World",
                mmi_ucs2strlen((PU8)L"Hello World") + 2,
                (PU8)p->gui_buffer);
            if(0xB == (U32)param->user_data)
            {
                slim_check++;
            }
        }
        break;
        case EVT_ID_SCRN_INACTIVE:
        {}
        break;
        /* screen de init */
        case EVT_ID_SCRN_DEINIT:
        {}
        break;
        default:
            break;
    }
    return ret;
}

mmi_ret slim_test1(void *para)
{
    mmi_frm_close_to_idle_group();
 	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x100, mmi_proc_slim_func, (void *)0xA100, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_create(0x100, 0x1001, NULL, (void *)0xB1001);
    mmi_frm_scrn_create(0x100, 0x1002, mmi_proc_slim_func, (void *)0xB1002);

    mmi_frm_group_create_ex(0x100, 0x200, mmi_proc_slim_func, (void *)0xA200, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_create(0x200, 0x2001, mmi_proc_slim_func, (void *)0xB2001);

    mmi_frm_scrn_close(0x200, 0x2001);
    
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x100);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x1002);

    mmi_frm_scrn_close(0x100, 0x1002);

    mmi_frm_close_to_idle_group();
    return MMI_RET_OK;
}
mmi_ret slim_test2(void *para)
{
    slim_check = 0;
    mmi_frm_close_to_idle_group();
    mmi_frm_scrn_create(GRP_ID_ROOT, 0x1001, mmi_proc_slim_func, (void *)0xB);

    MMI_ASSERT(slim_check == 1);
    mmi_frm_scrn_close(GRP_ID_ROOT, 0x1001);
    mmi_frm_close_to_idle_group();

    /* not add to history */
    mmi_frm_scrn_create(GRP_ID_ROOT, 0x1001, mmi_proc_slim_func, 0);
    mmi_frm_scrn_clear_attribute(GRP_ID_ROOT, 0x1001, MMI_SCRN_ATTRIB_ADD_HISTORY);
    mmi_frm_scrn_create(GRP_ID_ROOT, 0x1002, mmi_proc_slim_func, 0);
    mmi_frm_close_to_idle_group();
    return MMI_RET_OK;
}


mmi_ret MAUI_02947404(void *para)
{
    mmi_scrn_essential_struct scrn_data = {0};    
    mmi_frm_close_to_idle_group();
    
    mmi_frm_group_create(GRP_ID_ROOT, 32449, mmi_group_proc_func, 0);
    mmi_frm_group_enter(32449, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 32449;
    scrn_data.scrn_id = 24765;
    scrn_entry(&scrn_data);
    
    mmi_frm_group_create(GRP_ID_ROOT, 32650, mmi_group_proc_func, 0);
    mmi_frm_group_enter(32650, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_first_enter(32650, 24767, (FuncPtr)scrn_entry,NULL);

    MMI_ASSERT(shell.active_group->id == 32650);
    MMI_ASSERT(_SCRN_ID(32650,24767) == shell.active_scrn->id);

    mmi_frm_close_to_idle_group();

	return MMI_RET_OK;
}
void tab_page_one_entry(mmi_scrn_essential_struct* et_data)
{
    if (!mmi_frm_scrn_tab_page_enter(et_data->group_id, mmi_frm_scrn_get_active_id(), et_data->scrn_id, NULL,
                                        (FuncPtr)tab_page_one_entry, MMI_FRM_TAB_PAGE))
    {
        return;
    }
}
void tab_page_two_entry(mmi_scrn_essential_struct* et_data)
{
    if (!mmi_frm_scrn_tab_page_enter(et_data->group_id, mmi_frm_scrn_get_active_id(), et_data->scrn_id, NULL,
                                        (FuncPtr)tab_page_two_entry, MMI_FRM_TAB_PAGE))
    {
        return;
    }
}


void mmi_app_tab_enter(void)
{
    mmi_frm_tab_struct tab_pages_info_array[2] = {0};

    tab_pages_info_array[0].screen_id = 0x1011;
    tab_pages_info_array[0].tab_entry_func = (FuncPtr)tab_page_one_entry;
    tab_pages_info_array[0].tab_icon = NULL;
    tab_pages_info_array[0].tab_string = (U8 *)L"abcd";
    tab_pages_info_array[0].user_data = NULL;
    
    tab_pages_info_array[1].screen_id = 0x1012;
    tab_pages_info_array[1].tab_entry_func = (FuncPtr)tab_page_two_entry;
    tab_pages_info_array[1].tab_icon = NULL;
    tab_pages_info_array[1].tab_string = (U8 *)L"efgh";
    tab_pages_info_array[0].user_data = NULL;
    mmi_frm_scrn_tab_enter (0x100, 0x1001, NULL, mmi_app_tab_enter, tab_pages_info_array, 2, 0);

}

/* tab first enter test cast */
mmi_ret tab_insert_case(void* para)
{
    mmi_frm_close_to_idle_group();

    mmi_frm_group_create_ex(GRP_ID_ROOT, 0x100, mmi_proc_slim_func, (void *)0xA100, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_first_enter(0x100, 0x1001, (FuncPtr)mmi_app_tab_enter, (void *)0xB1001);
    
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x100);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x1001);

    mmi_frm_close_to_idle_group();
    return MMI_RET_OK;
}

mmi_ret music_bg_play(void* para)
{
    MMI_ID pre_id;
    mmi_scrn_essential_struct scrn_data = {0};
    mmi_frm_close_to_idle_group();

    mmi_frm_group_create(GRP_ID_ROOT, 0x100, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x100, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x100;
    scrn_data.scrn_id = 0x1001;
    scrn_entry(&scrn_data);

    mmi_frm_group_create(GRP_ID_ROOT, 0x200, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x200, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x200;
    scrn_data.scrn_id = 0x2001;
    scrn_entry(&scrn_data);
    mmi_frm_group_create(0x200, 0x300, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x300, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x300;
    scrn_data.scrn_id = 0x3001;
    scrn_entry(&scrn_data);

    mmi_frm_group_create(GRP_ID_ROOT, 0x400, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x400, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x400;
    scrn_data.scrn_id = 0x4001;
    scrn_entry(&scrn_data);
    scrn_data.scrn_id = 0x4002;
    scrn_entry(&scrn_data); 
    
	pre_id = mmi_frm_scrn_get_neighbor_id(GRP_ID_ROOT, 0x400, MMI_FRM_NODE_BEFORE_FLAG);
    /* check 3 */    
    mmi_frm_group_set_user_data(0x400,(void*)0x9999);
    mmi_frm_close_to_idle_group();

    mmi_frm_group_close(0x400);
    
    return MMI_RET_OK;
}
mmi_ret MAUI_02948246_notify_parent_no_child(void *para)
{
    mmi_scrn_essential_struct scrn_data = {0};
    mmi_frm_close_to_idle_group();
    no_child_evt_times = 0;
    mmi_frm_group_create(GRP_ID_ROOT, 0x100, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x100, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x100;
    scrn_data.scrn_id = 0x1001;
    scrn_entry(&scrn_data);
    mmi_frm_scrn_close(0x100, 0x1001);

    mmi_frm_group_create(GRP_ID_ROOT, 0x100, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x100, MMI_FRM_NODE_NONE_FLAG);
    mmi_frm_group_create(0x100, 0x200, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x200, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x200;
    scrn_data.scrn_id = 0x2001;
    scrn_entry(&scrn_data);
    mmi_frm_scrn_close(0x200, 0x2001);

    scrn_data.group_id = 0x100;
    scrn_data.scrn_id = 0x1001;
    scrn_entry(&scrn_data);
    mmi_frm_scrn_close(0x100, 0x1001);

    MMI_ASSERT(no_child_evt_times == 2);

    mmi_frm_close_to_idle_group();
    
    return MMI_RET_OK;
}

mmi_ret ASM_insert(void *para)
{
    mmi_scrn_essential_struct scrn_data = {0};
    mmi_frm_close_to_idle_group();
    
    mmi_frm_group_create(GRP_ID_ROOT, 0x100, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x100, 0);
    mmi_frm_group_create(0x100, 0x200, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x200, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x200;
    scrn_data.scrn_id = 0x2001;
    scrn_entry(&scrn_data);
    mmi_frm_scrn_close(0x200, 0x2001);      /* no fatal error */

    mmi_frm_group_create(0x100, 0x200, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x200, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x200;
    scrn_data.scrn_id = 0x2001;
    scrn_entry(&scrn_data);
    mmi_frm_group_close(0x200);             /* no fatal error */
    mmi_frm_group_close(0x100);

    mmi_frm_group_create(GRP_ID_ROOT, 0x100, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x100, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_group_create(0x100, 0x200, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x200, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x200;
    scrn_data.scrn_id = 0x2001;
    scrn_entry(&scrn_data);
    mmi_frm_scrn_close(0x200, 0x2001);      /* no fatal error */
    
    mmi_frm_group_create(GRP_ID_ROOT, 0x100, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x100, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_group_create(0x100, 0x200, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x200, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x200;
    scrn_data.scrn_id = 0x2001;
    scrn_entry(&scrn_data);
    mmi_frm_group_close(0x200);             /* no fatal error */

    mmi_frm_group_create(GRP_ID_ROOT, 0x100, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x100, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_group_create(0x100, 0x200, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x200, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x200;
    scrn_data.scrn_id = 0x2001;
    scrn_entry(&scrn_data);
    mmi_frm_group_close(0x100);             /* no fatal error */

    mmi_frm_group_create(GRP_ID_ROOT, 0x100, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x100, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x100;
    scrn_data.scrn_id = 0x1001;
    scrn_entry(&scrn_data);
    mmi_frm_group_create(GRP_ID_ROOT, 0x200, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x200, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x200;
    scrn_data.scrn_id = 0x2001;
    scrn_entry(&scrn_data);
    mmi_frm_scrn_set_attribute(0x200,0x2001,MMI_SCRN_ATTRIB_SMALL_SCRN);
    
    mmi_frm_group_create(GRP_ID_ROOT, 0x300, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x300, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x300;
    scrn_data.scrn_id = 0x3001;
    scrn_entry(&scrn_data);    

    mmi_frm_group_close(0x300);
    mmi_frm_group_close(0x200);
    
    mmi_frm_close_to_idle_group();

    return MMI_RET_OK;
}

mmi_ret sg_screen_level_test_case(void *para)
{
    U32 screen_level = 0;
    mmi_scrn_essential_struct scrn_data = {0};
    mmi_frm_close_to_idle_group();

    mmi_frm_group_create(GRP_ID_ROOT, 0x100, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x100, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x100;
    scrn_data.scrn_id = 0x1001;
    scrn_entry(&scrn_data);
    mmi_frm_scrn_set_leave_proc(scrn_data.group_id,scrn_data.scrn_id, mmi_group_proc_func);
    
    mmi_frm_group_create(0x100, 0x200, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x200, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x200;
    scrn_data.scrn_id = 0x2001;
    scrn_entry(&scrn_data);    
    mmi_frm_scrn_set_leave_proc(scrn_data.group_id,scrn_data.scrn_id, mmi_group_proc_func);
    
    mmi_frm_group_create(GRP_ID_ROOT, 0x300, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x300, MMI_FRM_NODE_SMART_CLOSE_FLAG);    
    mmi_frm_group_create(0x300, 0x400, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x400, MMI_FRM_NODE_SMART_CLOSE_FLAG);    
    scrn_data.group_id = 0x400;
    scrn_data.scrn_id = 0x4001;
    scrn_entry(&scrn_data);    
    mmi_frm_scrn_set_leave_proc(scrn_data.group_id,scrn_data.scrn_id, mmi_group_proc_func);
    mmi_frm_group_create(0x400, 0x500, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x500, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x500;
    scrn_data.scrn_id = 0x5001;
    scrn_entry(&scrn_data);    
    scrn_data.group_id = 0x500;
    scrn_data.scrn_id = 0x5002;
    scrn_entry(&scrn_data);

    screen_level = mmi_frm_get_screen_level(0x1001);
    MMI_ASSERT(screen_level == 2);
    screen_level = mmi_frm_get_screen_level(0x2001);
    MMI_ASSERT(screen_level == 3);
    screen_level = mmi_frm_get_screen_level(0x4001);
    MMI_ASSERT(screen_level == 4);
    screen_level = mmi_frm_get_screen_level(0x5001);
    MMI_ASSERT(screen_level == 5);
    screen_level = mmi_frm_get_screen_level(0x5002);
    MMI_ASSERT(screen_level == 6);

    mmi_frm_close_to_idle_group();
    return MMI_RET_OK;
}
mmi_ret goto_idle_invoke_close(void *para)
{
    mmi_scrn_essential_struct scrn_data = {0};
    mmi_frm_close_to_idle_group();
    
    mmi_frm_group_create(GRP_ID_ROOT, 0x100, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x100, 0);
    scrn_data.group_id = 0x100;
    scrn_data.scrn_id = 0x1001;
    scrn_entry(&scrn_data);

    mmi_frm_group_create(GRP_ID_ROOT, 0x1402, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x1402, 0);
    scrn_data.group_id = 0x1402;
    scrn_data.scrn_id = 0x1402;
    scrn_entry(&scrn_data);
    mmi_frm_scrn_set_leave_proc(0x1402,0x1402,scrn_leave_proc);
    mmi_frm_scrn_set_user_data(0x1402,0x1402,(void*)0x14021402);

    mmi_frm_close_to_idle_group();

    return MMI_RET_OK;
}
mmi_ret MAUI_03001122(void *para)
{
    mmi_scrn_essential_struct scrn_data = {0};
    mmi_frm_close_to_idle_group();

    mmi_frm_group_create(GRP_ID_ROOT, 39975, mmi_group_proc_func, 0);
    mmi_frm_group_enter(39975, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 39975;
    scrn_data.scrn_id = 24783;
    scrn_entry(&scrn_data);
    
    mmi_frm_group_create(GRP_ID_ROOT, 33869, mmi_group_proc_func, 0);
    mmi_frm_group_enter(33869, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 33869;
    scrn_data.scrn_id = 24784;
    scrn_entry(&scrn_data);    

    mmi_frm_group_create(GRP_ID_ROOT, 26747, mmi_group_proc_func, (void *)0x6666);
    mmi_frm_group_enter(26747, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 26747;
    scrn_data.scrn_id = 26748;
    scrn_entry(&scrn_data);

    mmi_frm_group_create(GRP_ID_ROOT, 41800, mmi_group_proc_func, 0);
    mmi_frm_group_enter(41800, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 41800;
    scrn_data.scrn_id = 24786;
    scrn_entry(&scrn_data);

    // check
    mmi_frm_close_to_idle_group();
//    MMI_ASSERT(historyData[1].scrnID == 26747);
//    MMI_ASSERT(currHistoryIndex == 0);
//    MMI_ASSERT(activeScrnIndex == 1);
//    MMI_ASSERT(topHistoryIndex == 0);

    mmi_frm_group_set_user_data(26747, (void*)0);
    mmi_frm_group_create(GRP_ID_ROOT, 41800, mmi_group_proc_func, (void *)0x6666);
    mmi_frm_group_enter(41800, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 41800;
    scrn_data.scrn_id = 24786;
    scrn_entry(&scrn_data);
    // check 2
    mmi_frm_close_to_idle_group();
//    MMI_ASSERT(historyData[1].scrnID == 41800);
//    MMI_ASSERT(currHistoryIndex == 0);
//    MMI_ASSERT(activeScrnIndex == 1);
//    MMI_ASSERT(topHistoryIndex == 0);
    mmi_frm_group_set_user_data(41800, (void*)0);
    mmi_frm_close_to_idle_group();

    return MMI_RET_OK;
}
mmi_ret MAUI_03040168(void *para)
{
    mmi_scrn_essential_struct scrn_data = {0};
    mmi_frm_close_to_idle_group();

    // case 1
    mmi_frm_group_create(GRP_ID_ROOT, 0x100, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x100, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x100;
    scrn_data.scrn_id = 0x1001;
    scrn_entry(&scrn_data);
    
    mmi_frm_group_create(GRP_ID_ROOT, 0x200, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x200, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x200;
    scrn_data.scrn_id = 0x2001;
    scrn_entry(&scrn_data);
    
    mmi_frm_group_create(GRP_ID_ROOT, 0x300, mmi_group_proc_func, (void *)0x6666);
    mmi_frm_group_enter(0x300, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x300;
    scrn_data.scrn_id = 0x3001;
    scrn_entry(&scrn_data);

    // check
    mmi_frm_close_to_idle_group(); // no assert and fatal error   
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x300);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x3001);
    MMI_ASSERT(!mmi_frm_group_is_present(0x200));
    mmi_frm_group_set_user_data(0x300,(void*)0);
    mmi_frm_group_close(0x300);

    // case 2
    mmi_frm_group_create(GRP_ID_ROOT, 0x100, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x100, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x100;
    scrn_data.scrn_id = 0x1001;
    scrn_entry(&scrn_data);
    
    mmi_frm_group_create(GRP_ID_ROOT, 0x200, mmi_group_proc_func, (void *)0x6666);
    mmi_frm_group_enter(0x200, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x200;
    scrn_data.scrn_id = 0x2001;
    scrn_entry(&scrn_data);
    
    mmi_frm_group_create(GRP_ID_ROOT, 0x300, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x300, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x300;
    scrn_data.scrn_id = 0x3001;
    scrn_entry(&scrn_data);

    // check
    mmi_frm_close_to_idle_group(); // no assert and fatal error   
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x200);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x2001);
    MMI_ASSERT(!mmi_frm_group_is_present(0x100));
    mmi_frm_group_set_user_data(0x200,(void*)0);
    mmi_frm_group_close(0x200);

    // case 3    
    mmi_frm_group_create(GRP_ID_ROOT, 0x100, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x100, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x100;
    scrn_data.scrn_id = 0x1001;
    scrn_entry(&scrn_data);
    
    mmi_frm_group_create(GRP_ID_ROOT, 0x200, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x200, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x200;
    scrn_data.scrn_id = 0x2001;
    scrn_entry(&scrn_data);
    
    mmi_frm_group_create(GRP_ID_ROOT, 0x300, mmi_group_proc_func, (void *)0x4444);
    mmi_frm_group_enter(0x300, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x300;
    scrn_data.scrn_id = 0x3001;
    scrn_entry(&scrn_data);

    // check
    mmi_frm_close_to_idle_group(); // no assert and fatal error   
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x300);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x3001);
    MMI_ASSERT(mmi_frm_group_is_present(0x200));
    mmi_frm_group_set_user_data(0x300,(void*)0);
    mmi_frm_close_to_idle_group();

    // case 4
    mmi_frm_group_create(GRP_ID_ROOT, 0x100, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x100, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x100;
    scrn_data.scrn_id = 0x1001;
    scrn_entry(&scrn_data);
    
    mmi_frm_group_create(GRP_ID_ROOT, 0x200, mmi_group_proc_func, (void *)0x4444);
    mmi_frm_group_enter(0x200, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x200;
    scrn_data.scrn_id = 0x2001;
    scrn_entry(&scrn_data);
    
    mmi_frm_group_create(GRP_ID_ROOT, 0x300, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x300, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x300;
    scrn_data.scrn_id = 0x3001;
    scrn_entry(&scrn_data);

    // check
    mmi_frm_close_to_idle_group(); // no assert and fatal error   
    MMI_ASSERT(mmi_frm_group_get_active_id() == 0x200);
    MMI_ASSERT(mmi_frm_scrn_get_active_id() == 0x2001);
    MMI_ASSERT(mmi_frm_group_is_present(0x100));
    mmi_frm_group_set_user_data(0x200,(void*)0);
    mmi_frm_close_to_idle_group();
	return MMI_RET_OK;
}

mmi_ret MAUI_03082728(void *para)
{
    mmi_scrn_essential_struct scrn_data = {0};
    mmi_frm_close_to_idle_group();

    mmi_frm_group_create(GRP_ID_ROOT, 0x200, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x200, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 0x200;
    scrn_data.scrn_id = 0x2001;
    scrn_entry(&scrn_data);
    mmi_frm_group_hide(0x200);
    
    
    mmi_frm_group_create(GRP_ID_ROOT, 37883, mmi_group_proc_func, 0);
    mmi_frm_group_enter(37883, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 37883;
    scrn_data.scrn_id = 24433;
    scrn_entry(&scrn_data);
    
    mmi_frm_group_create(37883, 38084, mmi_group_proc_func, 0);
    mmi_frm_group_enter(38084, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    scrn_data.group_id = 38084;
    scrn_data.scrn_id = 24434;
    scrn_entry(&scrn_data);

    mmi_frm_group_create(GRP_ID_ROOT, 0x100, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x100, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_close_to_idle_group();
    
    return MMI_RET_OK;
}

mmi_ret MAUI_03082797(void *para)
{
    mmi_scrn_essential_struct scrn_data = {0};
    mmi_frm_close_to_idle_group();

    mmi_frm_group_create(GRP_ID_ROOT, 0x100, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x100, MMI_FRM_NODE_NONE_FLAG);
    scrn_data.group_id = 0x100;
    scrn_data.scrn_id = 0x1001;
    scrn_entry(&scrn_data);

    mmi_frm_group_create(GRP_ID_ROOT, 0x200, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x200, MMI_FRM_NODE_NONE_FLAG);
    scrn_data.group_id = 0x200;
    scrn_data.scrn_id = 0x2001;
    scrn_entry(&scrn_data);
    mmi_frm_group_create(0x200, 0x300, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x300, MMI_FRM_NODE_NONE_FLAG);
    scrn_data.group_id = 0x300;
    scrn_data.scrn_id = 0x3001;
    scrn_entry(&scrn_data);
    mmi_frm_group_create(0x300, 0x400, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x400, MMI_FRM_NODE_NONE_FLAG);
    scrn_data.group_id = 0x400;
    scrn_data.scrn_id = 0x4001;
    scrn_entry(&scrn_data);

    mmi_frm_scrn_close(0x200, 0x2001);
    mmi_frm_group_close(0x300);
    mmi_frm_group_close(0x200);

    mmi_frm_close_to_idle_group();

    return MMI_RET_OK;
}

mmi_ret MAUI_03090630(void *para)
{
	mmi_frm_close_to_idle_group();

    /* 
	 *  0x100
	 *     -0x200
	 *  IDLE
	 *  
	 */

    mmi_frm_group_create(GRP_ID_ROOT, 0x100, mmi_group_proc_func, (void *)0x4444);
    mmi_frm_group_enter(0x100, MMI_FRM_NODE_NONE_FLAG);
    mmi_frm_group_create(0x100, 0x200, mmi_group_proc_func, 0);
    mmi_frm_group_enter(0x200, MMI_FRM_NODE_NONE_FLAG);
	mmi_frm_close_to_idle_group();
	MMI_ASSERT(shell.state == 0);
	MMI_ASSERT(mmi_frm_group_is_present(0x100));
	MMI_ASSERT(mmi_frm_group_get_active_id() == 0x200);
	mmi_frm_group_set_user_data(0x100, 0);
	mmi_frm_close_to_idle_group_with_start_id(0x100);
	MMI_ASSERT(shell.state == 0);

	mmi_frm_close_to_idle_group();

    /* 
	 *  0x200
	 *  0x100
	 *  0x300
	 *  IDLE
	 */
	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x300, mmi_group_proc_func, (void *)0x03090630, 0);
	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x100, mmi_group_proc_func, NULL, 0);
	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x200, mmi_group_proc_func, NULL, 0);
	mmi_frm_close_to_idle_group_with_start_id(0x300);
	MMI_ASSERT(shell.state == 0);
	MMI_ASSERT(mmi_frm_group_is_present(0x200) == MMI_TRUE);
	MMI_ASSERT(mmi_frm_group_is_present(0x100) == MMI_FALSE);
	mmi_frm_group_close(0x200);
	return MMI_RET_OK;
}


mmi_ret MAUI_03090135(void *para)
{
	mmi_frm_close_to_idle_group();

	/*
	 * 0x100(G)
	 *     --0x500(S)
	 * 0x300(G)
	 * IDLE
	 */
	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x300, mmi_group_proc_func, NULL, 0);
	mmi_frm_scrn_create(0x300, 0x500, scrn_leave_proc, (void *)0x03090135);
	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x100, mmi_group_proc_func, NULL, 0);
	mmi_frm_group_hide(0x100);
	mmi_frm_group_close(0x100);

	mmi_frm_close_to_idle_group();

	return MMI_RET_OK;
}

mmi_ret MAUI_03094319(void *para)
{
	mmi_frm_close_to_idle_group();
	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x300, mmi_group_proc_func, NULL, 0);
	mmi_frm_scrn_create(0x300, 0x500, scrn_leave_proc, (void *)0x03094319);
	mmi_frm_scrn_close(0x300, 0x500);
	return MMI_RET_OK;
}

mmi_ret MAUI_03095328(void *para)
{
	mmi_frm_close_to_idle_group();
	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x300, mmi_group_proc_func, NULL, 0);
	mmi_frm_scrn_create(0x300, 0x500, scrn_leave_proc, (void *)0x03095328);
	mmi_frm_scrn_create(0x300, 0x600, scrn_leave_proc, (void *)0x03095328);
	mmi_frm_scrn_create(0x300, 0x700, scrn_leave_proc, NULL);
	mmi_frm_scrn_close(0x300, 0x700);
	return MMI_RET_OK;
}

mmi_ret MAUI_03099990(void *para)
{
	mmi_frm_close_to_idle_group();
	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x300, mmi_group_proc_func, NULL, 0);
	mmi_frm_scrn_create(0x300, 0x500, scrn_leave_proc, (void *)0x03099990);
	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x400, mmi_group_proc_func, NULL, 0);

	mmi_frm_scrn_create(0x400, 0x700, scrn_leave_proc, NULL);
	mmi_frm_group_close(0x400);
	mmi_frm_scrn_create(0x300, 0x700, scrn_leave_proc, NULL);
	mmi_frm_close_to_idle_group();
	HistoryDump();
	return MMI_RET_OK;
}

mmi_ret MAUI_03102608(void *para) 
{
	mmi_frm_node_struct node;
	mmi_frm_close_to_idle_group();
	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x300, mmi_group_proc_func, NULL, 0);
	mmi_frm_scrn_create(0x300, 0x500, scrn_leave_proc, NULL);
	mmi_frm_group_create_ex(0x300, 0x400, mmi_group_proc_func, NULL, 0);
	mmi_frm_scrn_create(0x400, 0x700, scrn_leave_proc, NULL);
	mmi_frm_scrn_close(0x300, 0x600);
	node.id = 0x500;
	node.user_data = NULL;
	node.entry_proc = (mmi_proc_func)scrn_entry;
	mmi_frm_scrn_insert(0x300, 0x600, &node, MMI_FRM_NODE_AT_BEGINNING_FLAG);
	MMI_ASSERT(0 == mmi_frm_scrn_get_neighbor_id(0x300, 0x500, MMI_FRM_NODE_BEFORE_FLAG));
	MMI_ASSERT(0x400 == mmi_frm_scrn_get_neighbor_id(0x300, 0x500, MMI_FRM_NODE_AFTER_FLAG));
	return MMI_RET_OK;
}

mmi_ret test_mmi_frm_get_previous_app_id(void *para)
{
	MMI_ID idle_app_id;
	mmi_frm_close_to_idle_group();
	idle_app_id = mmi_frm_group_get_active_id();
	idle_app_id = mmi_frm_get_root_app(idle_app_id);
	MMI_ASSERT(mmi_frm_get_previous_app_id(idle_app_id) == GRP_ID_INVALID);
	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x400, NULL, NULL, 0);
	MMI_ASSERT(mmi_frm_get_previous_app_id(idle_app_id) == GRP_ID_INVALID);
	MMI_ASSERT(mmi_frm_get_previous_app_id(0x400) == idle_app_id);
	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x500, NULL, NULL, 0);
	MMI_ASSERT(mmi_frm_get_previous_app_id(idle_app_id) == GRP_ID_INVALID);
	MMI_ASSERT(mmi_frm_get_previous_app_id(0x400) == idle_app_id);
	MMI_ASSERT(mmi_frm_get_previous_app_id(0x500) == 0x400);
	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x600, NULL, NULL, 0);
	MMI_ASSERT(mmi_frm_get_previous_app_id(idle_app_id) == GRP_ID_INVALID);
	MMI_ASSERT(mmi_frm_get_previous_app_id(0x400) == idle_app_id);
	MMI_ASSERT(mmi_frm_get_previous_app_id(0x500) == 0x400);
	MMI_ASSERT(mmi_frm_get_previous_app_id(0x600) == 0x500);
	return MMI_RET_OK;
}

mmi_ret MAUI_03131247(void *para)
{
	mmi_frm_close_to_idle_group();
	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x300, mmi_group_proc_func, NULL, 0);
	mmi_frm_scrn_create(0x300, 0x500, scrn_leave_proc, (void *)0x03131247);
	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x400, mmi_group_proc_func, NULL, 0);
	mmi_frm_scrn_create(0x400, 0x500, scrn_leave_proc, (void *)0x03131247);
	mmi_frm_set_active_group(0x300);
	return MMI_RET_OK;
}

MMI_RET MAUI_03144892(void *para)
{
	mmi_frm_close_to_idle_group();
	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x400, NULL, NULL, 0);
	mmi_frm_scrn_create(0x400, 0x600, scrn_leave_proc, (void *)0x03144892);
	return MMI_RET_OK;
}

void scrn_enter_B()
{
    mmi_frm_scrn_close(0x100, 0x1002);
    mmi_frm_scrn_enter(0x100, 0x1002, NULL, scrn_enter_B, 0);
}

void scrn_enter_A()
{
    mmi_frm_scrn_enter(0x100, 0x1001, NULL, scrn_enter_A, 0);
    scrn_enter_B();
}

MMI_RET MAUI_SelfTest(void *para)
{
    mmi_frm_close_to_idle_group();
    mmi_frm_group_create_ex(GRP_ID_ROOT, 0x100, mmi_group_proc_func, (void*)0x99, MMI_FRM_NODE_SMART_CLOSE_FLAG);    
    scrn_enter_A();
}


MMI_RET MAUI_03149357(void *para)
{
	mmi_frm_close_to_idle_group();
	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x400, mmi_group_proc_func, (void *)0x03149357, 0);
	mmi_frm_group_close(0x400);
	return MMI_RET_OK;
}

MMI_RET MAUI_03134995(void *para)
{
	mmi_frm_close_to_idle_group();
	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x400, mmi_group_proc_func, NULL, 0);
	mmi_frm_scrn_create(0x400, 0x500, scrn_leave_proc, (void *)0x03134995);
	mmi_frm_scrn_create(0x400, 0x600, scrn_leave_proc, (void *)0x03134995);
	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x401, mmi_group_proc_func, NULL, 0);
	mmi_frm_group_close(0x401);
	mmi_frm_group_close(0x400);
	return MMI_RET_OK;
}

void smc_case_1300_exit()
{
}

void smc_case_1300_entry()
{
}


mmi_ret sg_smc_test_case_scrnEnterTwice(void *para)
{   
    mmi_frm_close_to_idle_group();
  
    mmi_frm_group_create(GRP_ID_ROOT, 0x1000, mmi_group_proc_func, NULL);
    mmi_frm_group_enter(0x1000, MMI_FRM_NODE_SMART_CLOSE_FLAG);

  
    //mmi_frm_scrn_create(0x1000, 0x1200, scrn_leave_proc, NULL);

    //mmi_frm_scrn_create(0x1000, 0x1200, scrn_leave_proc, NULL);

    mmi_frm_scrn_enter(0x1000, 0x1200, smc_case_1300_exit, smc_case_1300_entry, MMI_FRM_FULL_SCRN);
	mmi_frm_scrn_enter(0x1000, 0x1200, smc_case_1300_exit, smc_case_1300_entry, MMI_FRM_FULL_SCRN);

    return MMI_RET_OK;
}


mmi_ret sg_smc_test_case_closetoIdle(void *para)
{   
    mmi_frm_close_to_idle_group();
  
    mmi_frm_group_create(GRP_ID_ROOT, 0x1000, mmi_group_proc_func, NULL);
    mmi_frm_group_enter(0x1000, MMI_FRM_NODE_SMART_CLOSE_FLAG);    
    mmi_frm_scrn_enter(0x1000, 0x1200, smc_case_1300_exit, smc_case_1300_entry, MMI_FRM_FULL_SCRN);

    mmi_frm_group_create(GRP_ID_ROOT, 0x2000, mmi_group_proc_func, NULL);
    mmi_frm_group_enter(0x2000, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_enter(0x2000, 0x3000, smc_case_1300_exit, smc_case_1300_entry, MMI_FRM_FULL_SCRN);

	mmi_frm_close_to_idle_group();

    return MMI_RET_OK;
}

void smc_1200_exit()
{
}
    
void smc_1200_entry()
{
    if(mmi_frm_is_in_backward_scenario())
    {
        /*
        if(MMI_TRUE == mmi_frm_scrn_enter(0x1000, 0x1200, 
                                          smc_1200_exit, //smc_case_1300_exit, 
                                          smc_1200_entry, //smc_case_1300_entry, 
                                          MMI_FRM_FULL_SCRN))
        {
            ShowCategoryDummyScreen();
        }
        */
        if(MMI_TRUE == mmi_frm_scrn_enter(0x1000, 0x1300, 
                                          smc_case_1300_exit, 
                                          smc_case_1300_entry, 
                                          MMI_FRM_FULL_SCRN))
        {
            ShowCategoryDummyScreen();
        }
    }
    else
    {
        if(MMI_TRUE == mmi_frm_scrn_enter(0x1000, 0x1200, 
                                          smc_1200_exit, 
                                          smc_1200_entry, 
                                          MMI_FRM_FULL_SCRN))
        {
            ShowCategoryDummyScreen();
        }
    }
}

mmi_ret sg_smc_test_case_gpbackNewScrn(void *para)
{   
    mmi_frm_close_to_idle_group();
  
    mmi_frm_group_create_ex(GRP_ID_ROOT, 0x1000, mmi_group_proc_func, 
                            NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    smc_1200_entry();

    mmi_frm_group_create_ex(GRP_ID_ROOT, 0x2000, mmi_group_proc_func, 
                            NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_enter(0x2000, 0x3000, NULL, NULL, MMI_FRM_FULL_SCRN);

	mmi_frm_group_close(0x2000);

    return MMI_RET_OK;
}


mmi_ret sg_smc_test_case_redrawNewEvent(void *para)
{   
    mmi_frm_close_to_idle_group();
  
    mmi_frm_group_create_ex(GRP_ID_ROOT, 0x1000, mmi_group_proc_func, 
                            NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    mmi_frm_scrn_create(0x1000, 0x1300, scrn_leave_proc, (void*)0x54575457);
    mmi_frm_scrn_create(0x1000, 0x1500, scrn_leave_proc, NULL);
    mmi_frm_scrn_set_attribute(0x1000, 0x1500,MMI_SCRN_ATTRIB_SMALL_SCRN);

    mmi_frm_group_create_ex(GRP_ID_ROOT, 0x2000, mmi_group_proc_func, 
                            NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);    
    
    mmi_frm_group_close(0x2000);

    return MMI_RET_OK;
}


mmi_ret sg_smc_test_case_redrawNewEvent2(void *para)
{   
    mmi_frm_close_to_idle_group();
  
    mmi_frm_group_create_ex(GRP_ID_ROOT, 0x1000, mmi_group_proc_func, 
                            NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);    
    mmi_frm_scrn_create(0x1000, 0x1300, scrn_leave_proc, (void*)0x54575457);    

    mmi_frm_group_create_ex(GRP_ID_ROOT, 0x2000, mmi_group_proc_func, 
                            NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_create(0x2000, 0x2500, scrn_leave_proc, NULL);
    mmi_frm_scrn_set_attribute(0x2000, 0x2500,MMI_SCRN_ATTRIB_SMALL_SCRN);

    mmi_frm_group_create_ex(GRP_ID_ROOT, 0x3000, mmi_group_proc_func, 
                            NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);    
    
    mmi_frm_group_close(0x3000);

    return MMI_RET_OK;
}


const static mmi_unit_test_struct g_sg_ut[] =
{
    {1,  sg_history_disable_test_case_1}, /* foreward and backward case*/
    {2,  sg_history_disable_test_case_2}, /* insert case */
    {3,  sg_history_disable_test_case_3}, /* stop close, coutine */
    {4,  sg_history_disable_test_case_4}, /* stop close, break */    
    {5,  sg_history_disable_test_case_5}, /* small screen redraw */
    {6,  slim_test1},
    {7,  slim_test2},
    {8,  MAUI_02947404},
    {9,  tab_insert_case},
    {10, music_bg_play},
    {11, MAUI_02948246_notify_parent_no_child},
    {12, ASM_insert},
    {13, sg_screen_level_test_case},
    {14, goto_idle_invoke_close},// MAUI_02985576
    {15, MAUI_03001122},
    {16, MAUI_03040168},
    {17, MAUI_03082728},
    {18, MAUI_03082797},
	{19, MAUI_03090630},
	{20, MAUI_03099990},
	{21, MAUI_03144892}
};


#endif /* __MMI_FRM_HISTORY__ */

void sg_test_timer(void)
{
    static U32  count = 0;
    g_sg_ut[count].test(NULL);
    count++;
    if (count < ARRAY_COUNT(g_sg_ut))
    { 
        StartTimer(KEY_TIMER_ID_NONE, 100, sg_test_timer);
    }
	else
	{
		count = 0;
	}
}


void mmi_frm_sg_ut(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, "[SG] welcome to sg unit test");    
    if (index == 0)
    {
        StartTimer(KEY_TIMER_ID_NONE, 100, sg_test_timer);
    }
    else
    {
        for (i = 0; i < ARRAY_COUNT(g_sg_ut); i++)
        {
            if (g_sg_ut[i].index == index)
            {
                g_sg_ut[i].test(NULL);
            }
        }
    }
}

    
#endif


