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
 * mmi_frm_history.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for history functions Prototypes.
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
#ifndef MMI_FRM_HISTORY_H
#define MMI_FRM_HISTORY_H

#include "MMIDataType.h"
#include "mmi_frm_history_gprot.h"
#include "wgui_categories_list.h"
#include "kal_general_types.h"
#include "mmi_frm_events_gprot.h"
/***************************************************************************** 
* Define
*****************************************************************************/
#define  MIN_HISTORY    0
    
#if !defined(LOW_COST_SUPPORT)
    #define MAX_HISTORY		25
#else
    #define MAX_HISTORY		15
#endif

/* history: interanl use macro */
#define MMI_HIST_DISABLE_DESTROY_HANDLER (0)
#define MMI_HIST_ENABLE_DESTROY_HANDLER  (1)


#define MMI_SCR_ID_INAVLID  (0xFFFFFFFF)

/***************************************************************************** 
* Typedef 
*****************************************************************************/
/*----------------------------------------------------------------*
  Main LCD History
 *----------------------------------------------------------------*/
typedef U8(*MainLcdHistoryCBPtr) (void *);

typedef enum
{
    MMI_HIST_SMALLSCREEN_NONE,
    MMI_HIST_SMALLSCREEN_ACTIVE,
    MMI_HIST_SMALLSCREEN_ACTIVE_IN_EXIT_FUNC,
    
    /* add the enum value above here */
    MMI_HIST_SMALLSCREEN_END
}mmi_hist_smallscreen_state_enum;

/* history information stuct */
typedef struct _historyCallback
{
    U16 scrnID;
    HistoryDelCBPtr historydelCBPtr;
} historyCallback;

typedef struct
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

    U16             currExitScrnID;
    exit_func_ptr   curr_exit_handler; 
    entry_func_ptr  curr_entry_handler;
    void            *curr_exit_scrn_arg_p;
    void            *curr_entry_scrn_arg_p;
}history_ctxt_struct;

/*----------------------------------------------------------------*
  Sub LCD History
 *----------------------------------------------------------------*/
typedef U8(*SubLcdHistoryCBPtr) (void *);

typedef struct
{
    FuncPtr entryFuncPtr;
    U16 scrnID;
    U16 guiLen;
    U8 *guiBuffer;  /* this includes hilite item, input mode & etc.. */
} SubLCDHistoryInternalNode;


/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
extern MMI_BOOL g_is_back_root_main_hist;
extern S32 small_history_node;


/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
extern U8 ExecTopScrnCallbackHandler_ex(U8 is_main_hist);
extern U8 ExecHistoryScrnCallBackHandle_ex(U16 HistoryIndex, U8 is_main_hist);


/*----------------------------------------------------------------*
  Main LCD History
 *----------------------------------------------------------------*/
extern void InitHistory(MainLcdHistoryCBPtr main_root_ptr, SubLcdHistoryCBPtr sub_root_ptr);
extern void HistoryDump(void);

extern void mmi_frm_set_active_scrn_user_data(void* user_data);
extern void mmi_frm_create_active_scrn(U16 scrn_id, mmi_frm_scrn_type_enum scrn_type, exit_func_ptr exit_handler, entry_func_ptr entry_handler);
extern void mmi_frm_update_active_scrn_from_new_scrn(void);
extern void mmi_frm_update_active_scrn(U16 scrn_id, MMI_BOOL is_tab, exit_func_ptr exit_handler, entry_func_ptr entry_handler, void* user_data);
extern void mmi_go_back_to_history(void);
extern U8   mmi_frm_get_scrn_pointer(U16 scrnID, historyNode **ptrHistory);
extern U8   ExecuteRootMainHistoryScreen(void *funcPtr);  /* execute main lcd history callback function and root history function */
extern U16  mmi_delete_scrn_if_present(U16 scrn_id);

extern U16 GetIdleScrnId(void);
extern MMI_BOOL mmi_frm_move_history_node_to_top(U16 scrn_id);

extern MMI_BOOL mmi_frm_check_is_back_history(void);

extern mmi_hist_smallscreen_state_enum mmi_get_redrawing_bk_screens_status(void);
extern MMI_BOOL mmi_set_redrawing_bk_screens_status(mmi_hist_smallscreen_state_enum status);
extern void mmi_frm_exec_scrn_destroy_hdlr(U16 scrn_id, void *arg_p);
extern S16 mmi_frm_exec_scrn_wait_to_destroy_hdlr(mmi_history_node_status_enum status);
extern MMI_BOOL is_group_node(MMI_ID scrn_id);

/*----------------------------------------------------------------*
  Tab Bar Manager Series APIs
 *----------------------------------------------------------------*/


/*----------------------------------------------------------------*
  Sub LCD History
 *----------------------------------------------------------------*/
extern void InitSubLCDHistory(SubLcdHistoryCBPtr sublcdrootscreen);
extern void SubLCDHistoryDump(void);
extern void GoBackSubLCDHistoryInt(void);
extern void mmi_frm_reset_redraw_empty_bg(void);
extern MMI_BOOL mmi_frm_is_redraw_empty_bg(void);
extern void mmi_frm_redraw_fill_empty_bg(void);
extern mmi_ret mmi_frm_set_hist_ui_data(U16 scrn_id, U32  uiData);
extern U32 mmi_frm_get_hist_ui_data(U16 scrn_id);


#endif /* MMI_FRM_HISTORY_H */ 


