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
 * mmi_frm_history_gprot.h
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef MMI_FRM_HISTORY_GPROT_H
#define MMI_FRM_HISTORY_GPROT_H


#ifndef HISTORYGPROT_INT_H
#define HISTORYGPROT_INT_H
#include "MMIDataType.h"
#include "MMI_features.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_general_types.h"
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + Main LCD History Mech.
 +
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
 
/***************************************************************************** 
* Define
*****************************************************************************/
/* DOM-NOT_FOR_SDK-BEGIN */

// #define HISTORY_TAB_MANGER

/*
*
* The feature __MMI_FRM_REMOVE_HISTORY__ is indicating that the history mechanism is disable.
* Apps only can use screen group mechanism for screen management if the history mechanism is disable.
* Now the feature is only opened in 32*32 project from W1132MP in 11B, such as LION52_V2_3232_GPRS(QQ).
* If so, all history apis is invalided except the follows:
* GoBackHistory \ 
* mmi_is_redrawing_bk_screens \ 
* enable_resized_small_screen \ 
* disable_resized_small_screen \ 
* whether_no_small_screen \ 
* set_small_screen \ 
* reset_small_screen \ 
* force_no_small_screen \ 
* restore_small_screen \ 
* GetActiveScreenId \ 
* GetExitScrnID \ 
* mmi_frm_set_cur_sel_page \ 
* mmi_frm_general_tab_l_arrow_key_hdlr \ 
* mmi_frm_general_tab_r_arrow_key_hdlr \ 
* mmi_frm_enable_redraw_empty_bg \ 
* mmi_frm_in_exit_hdlr_proc
*
* because these apis only export screen group interface and App not need modify.
*
*/
#if !defined(__MMI_FRM_REMOVE_HISTORY__) && !defined(__COSMOS_MMI_PACKAGE__)
#define __MMI_FRM_HISTORY__
#endif

/* 
 * Length of input buffer
 * Unit: byte
 */
#if defined(WAP_SUPPORT)
    #define MAX_INPUT_BUFFER         (1600)
#elif defined(__MMI_BROWSER_2__)
    #define MAX_INPUT_BUFFER         (1500)
#else    
    #define MAX_INPUT_BUFFER         (1024)
#endif

/*
 * Length of gui buffer
 * Unit: byte
 */
#ifndef MAX_GUI_BUFFER
#define MAX_GUI_BUFFER           (128)
#endif

/*
 * The flag value of the delete call back handler
 * can use this value in the delete call to judge
 * in which procedure this screen will be deleted
 * Active screen delete in Back to IDLE procedure */
#define MMI_HIST_EXIT_SCREEN_IN_END_KEY_TYPE        (3)
/* Inactive screen delete in Back to IDLE procedure */
#define MMI_HIST_DELETE_SCREEN_IN_END_KEY_TYPE      (2)
/* Active screen delete in normal case */
#define MMI_HIST_EXIT_SCREEN_TYPE                   (1)
/* Inactive screen delete in normal case */
#define MMI_HIST_DELETE_SCREEN_TYPE                 (0)

/*
 * The return value of the delete call back handler
 * If the screen is allowed to be deleted, return 
 * MMI_HIST_ALLOW_DELETING
 * or return MMI_HIST_STOP_DELETING
 * Pay attention: mmi_delete_scrn_if_present will ignore this return
 * value
 */
#define MMI_HIST_STOP_DELETING          (1)
/* See the discription of MMI_HIST_STOP_DELETING */
#define MMI_HIST_ALLOW_DELETING         (0)


#define MMI_HIST_STOP_BUT_DEL_THIS_ONE  (2)

#define MMI_FULL_SCREEN     ((void*)1)   /* identify full-screen APP in EntryNewScreen() */
#define MMI_SMALL_SCREEN    ((void*)2)   /* *RESERVED* identify small-screen APP in EntryNewScreen() */
#define MMI_TAB_PAGE        ((void*)3)

/*
 * Top screen ID in the history stack
 * (The toppest inactive screen ID)
 */
#define MMI_HIST_TOP_SCREEN             GetCurrScrnId()


/* screen entry function point */
typedef void (*entry_func_ptr) (void *arg);
/* screen exit function point */
typedef void (*exit_func_ptr) (void *arg);

/***************************************************************************** 
* Call Back function 
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  Screen Delete Call back function
 * DESCRIPTION
 *  This callback will be invoke when the screen will be deleted
 *  In goback procedure:   Delete call back/Exit Handler/Destroy call back
 *  In delete procedure: Delete call back/Destroy call back
 * PARAMETERS
 *   arg       : [IN]  MMI_HIST_EXIT_SCREEN_IN_END_KEY_TYPE
 *                     MMI_HIST_DELETE_SCREEN_IN_END_KEY_TYPE
 *                     MMI_HIST_EXIT_SCREEN_TYPE
 *                     MMI_HIST_DELETE_SCREEN_TYPE
 * RETURNS
 *  MMI_HIST_ALLOW_DELETING to allow deleted
 *  MMI_HIST_STOP_DELETING  to forbit deleted
 *****************************************************************************/
typedef U8(*HistoryDelCBPtr) (void *arg);

/*****************************************************************************
 * FUNCTION
 *  Call back to get gui buffer/input buffer data
 * DESCRIPTION
 *  This Call back is used to move the data to the gui_buffer/input_buffer in history
 * PARAMETERS
 *  buf          : [IN] gui_buffer/input_bufer in history
 * RETURNS
 *  reserved
 *****************************************************************************/
typedef U8* (*HistoryGetData) (U8* buf);

/*****************************************************************************
 * FUNCTION
 *  Call back function to get the history data size
 * DESCRIPTION
 *  This callback will be invoke when the screen will be deleted
 *  In goback procedure:   Delete call back/Exit Handler/Destroy call back
 *  In delete procedure: Delete call back/Destroy call back
 * PARAMETERS
 *  void
 * RETURNS
 *  size of data that will be put in gui_buffer/input_buffer
 *  Unit: byte
 *****************************************************************************/
typedef S32 (*HistoryGetSize) (void);

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/* This enum is for identify different screen types */
typedef enum
{
    /* The enum begin */
    MMI_FRM_UNKNOW_SCRN,
    /* The screen type is the idle screen */
    MMI_FRM_IDLE_SCRN,
    /* The screen type is the full screen */
    MMI_FRM_FULL_SCRN,
    /* The screen type is the small screen */
    MMI_FRM_SMALL_SCRN,
    /* The screen type is the tab page screen */
    MMI_FRM_TAB_PAGE,
    /* The screen type is the tab screen */
    MMI_FRM_TAB,
    /* The screen type is the full screen */
    MMI_FRM_SCRN_GROUP,
    /* The screen will not enter history, such as dummy screen */
    MMI_FRM_FG_ONLY_SCRN,
    /* The enum total number */
    MMI_FRM_SCRN_TYPE_MAX
} mmi_frm_scrn_type_enum;

/* screen state */
typedef enum
{
    /* The initial state */
    MMI_FRM_SCREEN_NONE,
    /* Show the screen */
    MMI_FRM_SCREEN_FORWARD,
    /* Go back to previous screen */
    MMI_FRM_SCREEN_BACKWARD,
    /* In small screen procedure */
    MMI_FRM_SCREEN_REDRAW,
    /* The screen is in the history */
    MMI_FRM_SCREEN_INACTIVE,
    /* Delete the screen in the history */
    MMI_FRM_SCREEN_DELETE,
    /* Destroy the screen */
    MMI_FRM_SCREEN_DESTROY, 
    /* add the enum value above here */
    MMI_FRM_SCREEN_END    
} mmi_frm_screen_state_enum;

/* 
 * delete/goback related state of history node
 */
typedef enum
{
    /* history node is Normal */
    MMI_HIST_NODE_NORMAL = 0,
    /* history node is deleteing */
    MMI_HIST_NODE_DELETING,
    /* history node is in goback procedure */
    MMI_HIST_NODE_GOBACKING,
    /* history node is wait to destory */
    MMI_HIST_NODE_WAIT_TO_DESTROY,
    /* add the enum value above here */
    MMI_HIST_NODE_END    
}mmi_history_node_status_enum;


/* 
 * screen info
 * The para of API mmi_frm_get_screen_info
 */
typedef struct{
    /* new screen id */
    U16 new_scrn_id;
    /* current screen id */
    U16 curr_scrn_id;
    /* screen state */
    mmi_frm_screen_state_enum state;
} mmi_frm_scrn_info_struct;

/*
 * position to insert a screen
 *
 *      |---------------|   Top
 *      |    After      |
 *      |---------------|
 *      |    scrnId     |   History stack
 *      |---------------|
 *      |    Before     |
 *      |---------------|   Bottom 
 */
typedef enum
{
    /* insert before screen */
    MMI_FRM_INSERT_BEFORE_SCRN,
    /* insert after screen */
    MMI_FRM_INSERT_AFTER_SCRN
} mmi_frm_insert_scrn_enum;

/* 
 * The following struct is deprecated struct
 * Please don't use it any more.
 * Because sizeof(history) > 1k bytes,
 * it will occupy the stack size if use it 
 * as local variable. It may result in
 * MMI task stack overflow.
 *
 * history information stuct 
 */
typedef struct _history
{   
    /* Screen ID */
    U16 scrnID;
    /* Screen entry function */
    FuncPtr entryFuncPtr;
    /*Screen input buffer */
    U8 inputBuffer[MAX_INPUT_BUFFER];
    /* Screen guibuffer */
    U8 guiBuffer[MAX_GUI_BUFFER];
} history;

/*
 * structure for screen insert & screen replace
 */
typedef struct
{
    /* Screen ID */
    U16     scrnID;
#ifdef HISTORY_TAB_MANGER
    /* is tab group or not */
    U32     isTab : 1;
#endif
    /* is screen group adapter or not */
    U32     isGroupNode : 1;
    /* is small screen or not */
    U32     isSmallScreen : 1;
    /* entry function of screen */
    entry_func_ptr entryFuncPtr;
    /* user data of the screen */ 
    void *app_arg;
    /* input buffer pointer of the screen */
    U8 *inputBuffer;
    /* gui buffer pointer of the screen */
    U8 *guiBuffer;
    /* memory allocate callback of the input buffer */
    MemAlloc mallcFuncPtr;
    /* memory free callback of the input buffer */
    MemFree  mfreeFuncPtr;
} mmi_frm_screen_struct;

/* This is history node struct */
typedef struct _historyNode
{   
#ifdef HISTORY_TAB_MANGER
    /* is tab group or not */
    U32     isTab : 1;
#endif
    /* is screen group adapter or not */
    U32     isGroupNode : 1;
    /* is small screen or not */
    U32     isSmallScreen : 1;
     /* Screen ID */
    U16     scrnID;
    /* input buffer pointer of the node */
    U8      *inputBuffer;
    /* gui buffer pointer of the node */
    U8      *guiBuffer;
    /* user data of the node */
    void    *app_arg;
    /* memory allocate callback of the input buffer */
    MemAlloc        mallcFuncPtr;
    /* memory free callback of the gui buffer */
    MemFree         mfreeFuncPtr;
    /* screen entry function */
    entry_func_ptr  entryFuncPtr;
    /* screen exit function */
    exit_func_ptr   exitFuncPtr;
    /* screen destroy call back */
    HistoryDelCBPtr destroyFuncPtr;
    /* delete/goback related state of the history node */
    mmi_history_node_status_enum status;
    /* Data for WGUI, category, SSE and other UI module */
    U32             uiData;
} historyNode;

/*
 * structure for tab group
 */
typedef struct
{
    /* tab page id */
    U16     screen_id;
    /* tab page entry function */
    FuncPtr tab_entry_func;
    /* tab page icon list */
    U8*     tab_icon;
    /* tab page string list */
    U8*     tab_string;
    /* user data for the tab page */
    void*   user_data;               
} mmi_frm_tab_struct;
/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */
#ifdef __MMI_FRM_HISTORY__
/* DOM-NOT_FOR_SDK-END */
/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
/* DOM-NOT_FOR_SDK-BEGIN */
extern pBOOL IsBackHistory;
/* DOM-NOT_FOR_SDK-END */

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
/* DOM-NOT_FOR_SDK-BEGIN */
/* API need to revise and phase out */
#define AddHistory(addHistory) AddHistoryReference(&(addHistory))    
#define AddNHistory(addHistory,size)   AddNHistory_ext(&(addHistory),size)
#define AddHistoryEx(scrnID, entryFuncPtr, getGuiFuncPtr, getInputBufSizeFuncPtr, getInputBufFuncPtr, mallocFuncPtr, mfreeFuncPtr) \
        mmi_frm_add_history(scrnID, (entry_func_ptr)entryFuncPtr, getGuiFuncPtr, getInputBufSizeFuncPtr, getInputBufFuncPtr, mallocFuncPtr, mfreeFuncPtr, NULL) 
#define InsertHistoryBeforeThisScrn(scrnId, addHistory) InsertHistoryBeforeThisScrnReference(scrnId, &(addHistory))
extern MMI_BOOL InsertHistoryAfterThisScrnReference(U16 scrnId, history *addHistory);
extern void AddHistoryReference(history *addHistory);
extern void AddNHistory_ext(history *addHistory, U16 size);
extern void DeleteNHistory(U16 DeleteCount);
extern U8 DeleteScreens(U16 start_scrnid, U16 end_scrnid);
extern U8 DeleteBeyondScrTillScr(U16 beyondScrnid, U16 tillScrnid);
extern U16 DeleteBetweenScreen(U16 StartScrId, U16 EndScrId);
extern U8 DeleteUptoScrID(U16 scrnid);
extern U16 DeleteScreenFromToNnodes(U16 ScrId, U16 num_nodes);
extern U8 DeleteFromScrUptoScr(U16 start_scrnid, U16 upto_scrnid);
extern U8 DeleteNScrId(U16 scrnid);
extern U16 DeleteScreenIfPresent(U16 ScrId);
extern void InsertHistoryBeforeThisScrnReference(U16 scrnId, history *addHistory);
extern MMI_BOOL HistoryReplace(U16 out_scrn_id, U16 in_scrn_id, FuncPtr in_src_func);
extern MMI_BOOL mmi_frm_history_replace(U16 out_scrn_id, U16 in_scrn_id, entry_func_ptr in_src_func);
//extern MMI_BOOL mmi_frm_history_replace_ex(U16 out_scrn_id, U16 in_scrn_id, entry_func_ptr in_src_func, U16 is_small_screen);
extern U16 GetCurrSmallScrnID(void);
extern U8 GetHistoryScrID(U16 scrnID, historyNode **ptrHistory);
/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  GetNHistory
 * DESCRIPTION
 *  Used to get the history for a screen id, and also the history buffer size
 * PARAMETERS
 *  scrnID:          [IN]   The screen ID of the history node.     
 *  ptrHistory:      [OUT]  The history buffer of the specified screen ID.         
 * RETURNS
 *  Returns ST_SUCCESS if success; ST_FAILURE otherwise.
 *****************************************************************************/
extern U8 GetNHistory(U16 scrnID, history *ptrHistory);

/*****************************************************************************
 * FUNCTION
 *  GetHistory
 * DESCRIPTION
 *  Used to get the history buffer for a screen id
 * PARAMETERS
 *  scrnID:          [IN]  The screen ID of the history node.      
 *  ptrHistory:      [OUT] The history buffer of the specified screen ID.       
 * RETURNS
 *  Returns ST_SUCCESS if success; ST_FAILURE otherwise.
 *****************************************************************************/
extern U8 GetHistory(U16 scrnID, history *ptrHistory);

/*****************************************************************************
 * FUNCTION
 *  GetHistoryPointer
 * DESCRIPTION
 *  Used to get the reference of the history buffer for a screen id
 * PARAMETERS
 *  scrnID:       [IN]   The screen ID of the history node.     
 *  ptrHistory:   [OUT]  The pointer to the history buffer of the specified screen ID.      
 * RETURNS
 *  Returns ST_SUCCESS if success; ST_FAILURE otherwise.
 *****************************************************************************/
extern U8 GetHistoryPointer(U16 scrnID, historyNode **ptrHistory);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_screen_index
 * DESCRIPTION
 *  Queries the index in history database for specified screen Id
 * PARAMETERS
 *  scrnId:          [IN] the specified Screen ID which want to query.       
 * RETURNS
 *  Returns positive number or 0 if the specified Screen ID is in the history database; 
 *  otherwise returns -1.
 *****************************************************************************/
extern S16 mmi_frm_get_screen_index(U16 screen_id);

/*****************************************************************************
 * FUNCTION
 *  GetScreenCountInHistory
 * DESCRIPTION
 *  Get the screen numbers in the history
 * PARAMETERS
 *  void
 * RETURNS
 *  S16 - screen count
 *****************************************************************************/
extern S16 GetScreenCountInHistory(void);

/*****************************************************************************
 * FUNCTION
 *  GetCurrGuiBuffer
 * DESCRIPTION
 *  This function is used to retrieve current GUI buffer. In GUI buffer all GUI 
 *  related information is stored by framework whenever this screen is overwritten.
 *  The application use this function to get GUI buffer pointer of MMI history 
 *  database directly and its life cycle in during this screen is active. If the
 *¡¡current screen ID isn't the same with the input parameter, the function will
 *  return NULL GUI buffer pointer.
 * PARAMETERS
 *  scrnid      : [IN] Screen ID of screen whose corresponding GUI buffer is to be retrieved.       
 * RETURNS
 *  Pointer to unsigned char pointing to the GUI buffer returned. 
 *****************************************************************************/
extern U8 *GetCurrGuiBuffer(U16 scrnid);

/*****************************************************************************
 * FUNCTION
 *  GetCurrInputBuffer
 * DESCRIPTION
 *  This is used to get current screen input buffer.
 *  This function is used to retrieve current Input buffer. In Input buffer all 
 *  running text related information is stored by framework whenever this screen
 *  is overwritten. The application use this function to get Input buffer pointer
 *  of MMI history database directly, its size is not exceed MAX_INPUT_BUFFER and
 *  its life cycle in during this screen is active. If the current screen ID 
 *  isn't the same with the input parameter, the function will return NULL input
 *  buffer pointer.
 * PARAMETERS
 *  scrnid:      [IN]  Screen ID of screen whose corresponding Input buffer is to be retrieved.       
 * RETURNS
 *  Pointer to unsigned char pointing to the Input buffer returned.
 *****************************************************************************/
extern U8 *GetCurrInputBuffer(U16 scrnid);

/*****************************************************************************
 * FUNCTION
 *  GetCurrNInputBuffer
 * DESCRIPTION
 *  This function is used to retrieve current Input buffer with the Inptut buffer
 *  size. In Input buffer all running text related information is stored by 
 *  framework whenever this screen is overwritten. The application use this 
 *  function to get Input buffer pointer of MMI history database directly, its 
 *  size could be larger than MAX_INPUT_BUFFER and its life cycle in during this
 *  screen is active. If the current screen ID isn't the same with the input 
 *  parameter, the function will return NULL Input buffer pointer.
 * PARAMETERS
 *  scrnid      : [IN] Screen ID of screen whose corresponding Input buffer is to be retrieved.       
 *  size        : [IN] The Input buffer size.       
 * RETURNS
 *  Pointer to unsigned char pointing to the Input buffer returned.
 *****************************************************************************/
extern U8 *GetCurrNInputBuffer(U16 scrnid, U16 *size);

/*****************************************************************************
 * FUNCTION
 *  GetPreviousScrnIdOf
 * DESCRIPTION
 *  Queries previous scrn id of this Id
 * PARAMETERS
 *  scrnId              : [IN]   The based Screen ID.     
 *  previousScrnId      : [OUT]  The previous Screen ID.       
 * RETURNS
 *  Returns MMI_TRUE if get the previous Screen ID succeed ; MMI_FALSE otherwise. 
 *****************************************************************************/
extern MMI_BOOL GetPreviousScrnIdOf(U16 scrnId, U16 *previousScrnId);

/*****************************************************************************
 * FUNCTION
 *  GetNextScrnIdOf
 * DESCRIPTION
 *  Queries next scrn id of this Id
 * PARAMETERS
 *  scrnId          : [IN]   The based Screen ID.      
 *  nextScrnId      : [OUT]  The next Screen ID.       
 * RETURNS
 *  Returns MMI_TRUE if get the next Screen ID succeed ; MMI_FALSE otherwise.
 *****************************************************************************/
extern MMI_BOOL GetNextScrnIdOf(U16 scrnId, U16 *nextScrnId);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_current_delete_screen_id
 * DESCRIPTION
 *  Get the current deleted screen id
 * PARAMETERS
 *  scrnId          : [OUT] the specified Screen ID is in delete process.
 * RETURNS
 *  Returns MMI_TRUE if get the deleted screen ID succeed ; MMI_FALSE otherwise.
 *****************************************************************************/
extern MMI_BOOL mmi_frm_get_current_delete_screen_id(U16 *scrn_id);

/*****************************************************************************
 * FUNCTION
 *  GetCurrScrnId
 * DESCRIPTION
 *  Gets the id of the screen on the top of history stack.
 *  This is used to get current screen input buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  U16 - Current Screen Id
 *****************************************************************************/
extern U16 GetCurrScrnId(void);

/*****************************************************************************
 * FUNCTION
 *  CheckIsBackHistory
 * DESCRIPTION
 *  Is in GoBackHistory in original screen-histroy mech. or in screen group mech.
 *  
 *  This is typically used by entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  Returns MMI_TRUE if in GoBackHistory; MMI_FALSE otherwise.
 *****************************************************************************/
extern MMI_BOOL CheckIsBackHistory(void);

/*****************************************************************************
 * FUNCTION
 *  GoBackToHistory
 * DESCRIPTION
 *  Goes back to specified screen
 * PARAMETERS
 *  scrnid      : [IN]  Screen ID of screen which needs to be displayed.        
 * RETURNS
 *  Returns ST_SUCCESS if go back to the specified history succeed; ST_FAILURE otherwise.
 *****************************************************************************/
extern U8 GoBackToHistory(U16 scrnid);

/*****************************************************************************
 * FUNCTION
 *  GoBacknHistory
 * DESCRIPTION
 *  Goes 'n' screens back
 * PARAMETERS
 *  nHistory        : [IN] Number of screens one want to go back.       
 * RETURNS
 *  Returns ST_SUCCESS if go back to the specified history succeed; ST_FAILURE otherwise.
 *****************************************************************************/
extern U8 GoBacknHistory(U16 nHistory);

/*****************************************************************************
 * FUNCTION
 *  GoBeyondMarkerScr
 * DESCRIPTION
 *  This function deletes the history nodes from the current node up to the node
 *  corresponding to specified Screen ID and execute the entry function of the 
 *  node beyond it. The screen ID should be in the history database, or the 
 *  function will return fail.
 * PARAMETERS
 *  scrnid      : [IN] Screen ID of screen beyond which one want to go and execute the Entry Function of that screen.       
 * RETURNS
 *  Returns ST_SUCCESS if go back to the specified history succeed; ST_FAILURE otherwise. 
 *****************************************************************************/
extern U8 GoBeyondMarkerScr(U16 scrnid);

/*****************************************************************************
 * FUNCTION
 *  IsScreenPresent
 * DESCRIPTION
 *  Queries history for presence of a screen Id
 * PARAMETERS
 *  scrnId:          [IN] the specified Screen ID which want to query.       
 * RETURNS
 *  Returns MMI_TRUE if the specified Screen ID is in the history database; MMI_FALSE otherwise.
 *****************************************************************************/
extern MMI_BOOL IsScreenPresent(U16 scrnId);


/*****************************************************************************
 * FUNCTION
 *  IsMainLCDHistoryBack
 * DESCRIPTION
 *  Queries MainLCD history is back now or not
 * PARAMETERS
 *  void
 * RETURNS
 *  Returns MMI_TRUE if the MainLCD history is back now ; MMI_FALSE otherwise.
 *****************************************************************************/
extern MMI_BOOL IsMainLCDHistoryBack(void);

/*****************************************************************************
 * FUNCTION
 *  DeleteHistory
 * DESCRIPTION
 *  Delete history
 *  1. SCR ID should be larger than 0
 *  2. This function is greedy, which means delete histories for 
 *     max( startScrId to endScrId, count)
 *  3. index of startScrId >= index of endScrId
 * 
 * PARAMETERS
 *  startScrId  : [IN]    screen id of start node
 *  bIncStart   : [IN]    includes start node or not
 *  count       : [IN]    delete count
 *  endScrId    : [IN]    screen id of end node
 *  bIncEnd     : [IN]    includes end node or not
 * RETURNS
 *  number of nodes deleted
 *****************************************************************************/
extern U32 DeleteHistory(U16 startScrId, U8 bIncStart, U16 count, U16 endScrId, U8 bIncEnd);

/*****************************************************************************
 * FUNCTION
 *  mmi_delete_scrn_if_present
 * DESCRIPTION
 *  This function Deletes specified screen ID history nodes from the history 
 *  database. The screen ID should be in the history database, or the function 
 *  will return fail. This function is only used for internal. MMI framework
 *  scenario module use this function to delete the adaptor node.
 * PARAMETERS
 *  ScrId       : [IN] Specify the Screen ID wants to delete the nodes.       
 * RETURNS
 *  Returns ST_SUCCESS if success; ST_FAILURE otherwise.
 *****************************************************************************/
extern U16 mmi_delete_scrn_if_present(U16 scrn_id);

/*****************************************************************************
 * FUNCTION
 *  DinitHistory
 * DESCRIPTION
 *  Free the history node
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void DinitHistory(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_add_history
 * DESCRIPTION
 *  This function is used to add history node to the history stack.
 *  Generally, if the 3rd para(Entry function) of the mmi_frm_entry_new_screen 
 *  is not NULL, framework will help to add the screen to history node when the
 *  screen exit. 
 *  eg. mmi_frm_entry_new_screen(SCR_ID_XXX, NULL, screen_entry, NULL);
 *  If the 3rd para of the mmi_frm_entry_new_screen is NULL,
 *  the application may need to add history in exit function by himself.
 *  eg. mmi_frm_entry_new_screen(SCR_ID_XXX, screen_exit, NULL, NULL);
 *  If the application don't want to save his own data in history
 *  In exit handler of screen A, for common category, use
 *  mmi_frm_generic_exit_scrn to add history
 *  void screen_a_exit_handler(void *arg)
 *  {
 *       mmi_frm_generic_exit_scrn(SCR_ID_A, screen_a_entry);     
 *  }
 *  In exit handler of screen B, for category 57, use
 *  mmi_frm_generic_exit_inline_scrn to add history 
 *  void screen_b_exit(void *arg)
 *  {
 *       mmi_frm_generic_exit_inline_scrn(SCR_ID_B, screen_b_entry) 
 *  }
 *  If application want to save his own data in history node, it can use this
 *  interface to save the history data
 *  eg. input buffer size < MAX_INPUT_BUFFER
 *  mmi_frm_add_history(SCR_ID_A,
 *                      screen_a_entry,
 *                      screen_a_get_gui_data,
 *                      screen_a_get_input_data_size,
 *                      screen_a_get_input_data,
 *                      NULL,
 *                      NULL);
 *  U8 *screen_a_get_gui_data(U8 *gui_buf)
 *  {
 *      //copy the gui data to gui_buf here, pay attention that
 *      //gui buffer is 128bytes control buffer
 *  }
 *  S32 screen_a_get_input_data_size
 *  {
 *       //return the input data size (Bytes)
 *  }
 *  U8 *screen_a_get_input_data(U8 *input_buf)
 *  {
 *       //copy the input data to input buffer, pay attention that
 *       // input_buffer_size < MAX_INPUT_BUFFER (use control buffer to store)
 *  }
 *  eg. input buffer size > MAX_INPUT_BUFFER, application should provide
 *  the memory allocation callback and deallocation call back
 *  mmi_frm_add_history(SCR_ID_B
 *                      screen_b_entry,
 *                      screen_b_get_gui_data,
 *                      screen_b_get_input_data_size,
 *                      screen_b_get_input_data,
 *                      screen_b_input_mem_malloc,
 *                      screen_b_input_mem_free);
 * PARAMETERS
 *  scrnID                  : [IN]  the screen id      
 *  entryFuncPtr            : [IN]  the screen's entry function
 *  getGuiFuncPtr           : [IN]  the function to get GUI data
 *  getInputBufSizeFuncPtr  : [IN]  the function to get input buffer size 
 *  getInputBufFuncPtr      : [IN]  the function to get input buffer
 *  mallocFuncPtr           : [IN]  the function to allocate memory
 *  mfreeFuncPtr            : [IN]  the function to free memory
 * RETURNS
 *  reserved, always returns MMI_TRUE now.
 *****************************************************************************/
 extern MMI_BOOL mmi_frm_add_history(
            U16 scrn_id,
            entry_func_ptr entryFuncPtr,
            HistoryGetData getGuiFuncPtr,
            HistoryGetSize getInputBufSizeFuncPtr,
            HistoryGetData getInputBufFuncPtr,
            MemAlloc mallocFuncPtr,
            MemFree mfreeFuncPtr,
            void* app_arg_p);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_destroy_scrn_callback
 * DESCRIPTION
 *  This function is used to set screen's destroy callback function.
 *
 *   When to invoke this callback
 *   Basically, 
 *        1. Goback case: the active screen is gone and after the exit handler
 *              Delete Callback/Exit Handler/Destroy Callback
 *        2. Delete case:
 *              Delete Callback/Destroy Callback
 *               
 * PARAMETERS
 *   scrn_id     : [IN]  screen id
 *   func_ptr    : [IN]  destroy call back handler
 * RETURNS
 *  reserved - if return MMI_FALSE assert will happen
 *****************************************************************************/ 
extern MMI_BOOL mmi_frm_set_destroy_scrn_callback(U16 scrn_id, HistoryDelCBPtr func_ptr);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_init_screen_struct
 * DESCRIPTION
 *  This function is used to init all field of the screen_struct to 0
 * PARAMETERS
 *  screen_struct         : [IN]  Screen struct pointer.
 * RETURNS
 *  void
 * EXAMPLE
 *  <code>
 *   mmi_frm_screen_struct new_screen;
 *   mmi_frm_init_screen_struct(&new_screen);
 *  </code>
 *****************************************************************************/
extern void mmi_frm_init_screen_struct(mmi_frm_screen_struct *screen_struct);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_replace_screen
 * DESCRIPTION
 *  Replace history node with screen infomation, user must fill all information should be replaced,
 *  other information must be fill to 0 or NULL.
 *
 *  eg. replace screen B with screen A
 *   |---------------|               |---------------|
 *   |        C      |               |        C      |  
 *   |---------------|               |---------------|
 *   |        B      |       =>      |        A      |
 *   |---------------|               |---------------|
 *   |        D      |               |        D      |
 *   |---------------|               |---------------|
 *
 * PARAMETERS
 *  out_scrn_id     : [IN]  Specify the Screen ID wants to be replaced.      
 *  rep_screen      : [IN]  Screen struct pointer that wants to be replaced with.
 * RETURNS
 *  Returns MMI_TRUE if replace the specified history node succeed; MMI_FALSE otherwise.
 * EXAMPLE
 *  <code>
 *   mmi_frm_screen_struct new_screen;
 *   mmi_frm_init_screen_struct(&new_screen);
 *   new_screen.scrnID       = SCR_ID_A;
 *   new_screen.entryFuncPtr = screen_a_entry;
 *   ...set other field if needed
 *   mmi_frm_replace_screen(SCR_ID_B, &new_screen)
 *  </code> 
 *****************************************************************************/
//extern MMI_BOOL mmi_frm_replace_screen(U16 out_scrn_id, mmi_frm_screen_struct *rep_screen);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_insert_screen
 * DESCRIPTION
 *  Insert new screen into history
 * PARAMETERS
 *  scrnId          : [IN] The specified screen ID.
 *  scrn_struct     : [IN] The node to be added to  history stack.
 *  insert_type     : [IN] The position need to insert.
 *                         MMI_FRM_INSERT_BEFORE_SCRN means insert screen under designated screen in history stack;
 *                         MMI_FRM_INSERT_AFTER_SCRN means insert screen up designated screen in history stack;
 *                     |---------------|   Top
 *                     |    After      |
 *                     |---------------|
 *      History stack  |    scrnId     |   reference id
 *                     |---------------|
 *                     |    Before     |
 *                     |---------------|   Bottom
 * RETURNS
 *  If the screen doesn't exist in history will return MMI_FALSE, 
 *  return MMI_TRUE if successfull.
 * EXAMPLE
 *  <code>
 *   mmi_frm_screen_struct new_screen;
 *   mmi_frm_init_screen_struct(&new_screen);
 *   new_screen.scrnID       = SCR_ID_A;
 *   new_screen.entryFuncPtr = screen_a_entry;
 *   ...write other field if needed.
 *   mmi_frm_insert_screen(SCR_ID_B, &new_screen, MMI_FRM_INSERT_BEFORE_SCRN);
 *   or
 *   mmi_frm_insert_screen(SCR_ID_B, &new_screen, MMI_FRM_INSERT_AFTER_SCRN);
 *  </code> 
 *****************************************************************************/
extern MMI_BOOL mmi_frm_insert_screen(U16 scrn_id, mmi_frm_screen_struct *scrn_struct, mmi_frm_insert_scrn_enum insert_type);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_screen_info
 * DESCRIPTION
 *  The function is used to get the screen's info
 *  1.curr_scrn_id and new_scrn_id
 *     generally, curr_scrn_id == new_scrn_id, they are active screen id
 *     In exit handler, curr_scrn_id != new_scrn_id.
 *  2.screen's state
 *    1) enter a new screen A from B but not goback case
 *        In screen A's entry function
 *        Before mmi_frm_entry_new_screen,  state(A) = MMI_FRM_SCREEN_NONE
 *        After  mmi_frm_entry_new_screen,  state(A) = MMI_FRM_SCREEN_FORWARD
 *        
 *        In screen B' exit function
 *    2) go back history
 *    3) delete screen
 *        in delete callback,  state = MMI_FRM_SCREEN_DELETE
 *        in destroy callback, state = MMI_FRM_SCREEN_DESTROY
 *    
 *
 *  
 * PARAMETERS
 *  scrn_id     : [IN]  screen id(which screen that will be queried)
 *  info        : [OUT] screen info (curr active screen, new enter screen, screen'state of the scrn_id)
 * RETURNS
 *  if scrn_id is SCR_ID_INVALID return MMI_FALSE
 *  others return MMI_TRUE
 * EXAMPLE
 *  <code>
 *     mmi_frm_scrn_info_struct  screen_info;
 *     mmi_frm_get_screen_info(SCR_ID_A, &screen_info);
 *  </code> 
 *****************************************************************************/ 
extern MMI_BOOL mmi_frm_get_screen_info(U16 scrn_id, mmi_frm_scrn_info_struct *info);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_argument_with_screen
 * DESCRIPTION
 *  This function is used to get the specified screen's argument(user data)
 * PARAMETERS
 *  scrn_id    : [IN] the specific screen ID.
 * RETURNS
 *  If the scrn_id exists, return the argument(user data) of the screen,
 *  or return NULL
 *****************************************************************************/
extern void* mmi_frm_get_argument_with_screen(U16 scrn_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_current_screen_argument
 * DESCRIPTION
 *  This function is used to get the current screen's argument(user data)
 * PARAMETERS
 *  void
 * RETURNS
 *  The argument(user_data) of the current screen.
 *****************************************************************************/ 
extern void* mmi_frm_get_current_screen_argument(void);

/*****************************************************************************
 * FUNCTION
 *  SetDelScrnIDCallbackHandler
 * DESCRIPTION
 *  This function is used for register callback function when deleting or exiting
 *  the screens. In some special cases, the application may want to know it screen
 *  is destroyed (exit the screen or delete by other screens). Sometimes, the 
 *  application may want to delete the screens in the history stack, but these 
 *  screens may need to release the resource or not allow for deleting. These 
 *  kind of screens should register history delete callback function, and if the
 *  screen can't be deleted, the function should return MMI_TRUE. 
 * PARAMETERS
 *  ScrnID      : [IN]  Specify the Screen ID that  wants to register delete callback function      
 *  funcPtr     : [IN]  Pointer to the delete callback function to be registered.      
 * RETURNS
 *  Returns MMI_TRUE if set the delete callback function succeed; MMI_FALSE otherwise.
 *****************************************************************************/
extern U8 SetDelScrnIDCallbackHandler(U16 ScrnID, HistoryDelCBPtr funcPtr);

/*****************************************************************************
 * FUNCTION
 *  ClearDelScrnIDCallbackHandler
 * DESCRIPTION
 *  Clear callback fucntion for delete screen occur.
 * PARAMETERS
 *  ScrnID      : [IN] Specify the Screen ID that  wants to remove the registered delete callback function        
 * RETURNS
 *  Returns MMI_TRUE if succeed; MMI_FALSE otherwise.
 *****************************************************************************/
extern U8 ClearDelScrnIDCallbackHandler(U16 ScrnID, HistoryDelCBPtr funcPtr);


/* DOM-NOT_FOR_SDK-END */


/* DOM-NOT_FOR_SDK-BEGIN */

#ifdef HISTORY_TAB_MANGER
/*----------------------------------------------------------------*
  Tab Manager Series APIs
 *----------------------------------------------------------------*/

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_general_tab_entry
 * DESCRIPTION
 *  This function is used for create a tab manager and attaches it to an 
 *  instance of a tab group screen. 
 * PARAMETERS
 *  scrnId               : [IN] the specified Screen ID.
 *  entry_func_ptr       : [IN] entry function pointer.
 *  tab_pages_info_array : [IN] information array of tab pages.
 *  tab_pages_count      : [IN] count of tab pages.
 * RETURNS
 *  Return MMI_TRUE if enter tab screen successfully;
 *  Return MMI_FALSE if can't get tab_group from gui buffer.
 *****************************************************************************/
extern MMI_BOOL mmi_frm_general_tab_entry(
            U16 screen_id, 
            FuncPtr entry_func_ptr,
            mmi_frm_tab_struct *tab_pages_info_array, 
            U8 tab_pages_count);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_general_tab_entry_ex
 * DESCRIPTION
 *  This function is used for create a tab manager and attaches it to an 
 *  instance of a tab group screen. 
 * PARAMETERS
 *  scrnId               : [IN] the specified Screen ID.
 *  entry_func_ptr       : [IN] entry function pointer.
 *  tab_pages_info_array : [IN] information array of tab pages.
 *  tab_pages_count      : [IN] count of tab pages.
 *  sel_idx              : [IN] tab page selected index
 * RETURNS
 *  Return MMI_TRUE if enter tab screen successfully;
 *  Return MMI_FALSE if can't get tab_group from gui buffer.
 *****************************************************************************/
extern MMI_BOOL mmi_frm_general_tab_entry_ex(
            U16 screen_id,
            FuncPtr entry_func_ptr,
            mmi_frm_tab_struct *tab_pages_info_array,
            U8 tab_pages_count,
            U8 sel_idx);

/*****************************************************************************
 * FUNCTION
 *  add_tab_history
 * DESCRIPTION
 *  This function is used to save information about a tab page in a tab group.
 * PARAMETERS
 *  screen_id           : [IN] tap page screen id
 *  tab_page_history    : [IN] information of added taba page
 * RETURNS
 *  MMI_TRUE success to add tab history;
 *  MMI_FALSE fail to add tab history
 *****************************************************************************/
extern MMI_BOOL mmi_frm_add_tab_history(U16 screen_id , history *tab_page_history);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_add_tab_n_history
 * DESCRIPTION
 *  This function is used to save information about a tab page in a tab group.
 * PARAMETERS
 *  screen_id           : [IN] tap page screen id
 *  tab_page_history    : [IN] information of added taba page
 *  size                : [IN] User specifies data size for input buffer.      
 * RETURNS
 *  MMI_TRUE success to add tab history;
 *  MMI_FALSE fail to add tab history
 *****************************************************************************/
extern MMI_BOOL mmi_frm_add_tab_n_history(
            U16 screen_id,
            history *tab_page_history,
            U16 size);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_cur_tab_gui_buffer
 * DESCRIPTION
 *  Get gui buffer pointer by screen id.
 * PARAMETERS
 *  screen_id   :[IN] screen id
 * RETURNS
 *  Gui buffer pointer
 *****************************************************************************/
extern U8 *mmi_frm_get_cur_tab_gui_buffer(U16 screen_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_cur_tab_input_buffer
 * DESCRIPTION
 *  Get input buffer pointer by screen id.
 * PARAMETERS
 *  screen_id:   [IN] screen id
 * RETURNS
 *  Input buffer pointer
 *****************************************************************************/
extern U8 *mmi_frm_get_cur_tab_input_buffer(U16 screen_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_cur_tab_n_input_buffer
 * DESCRIPTION
 *  Get input buffer pointer by screen id.
 * PARAMETERS
 *  screen_id:   [IN]  screen id
 *  size:        [OUT] input buffer size 
 * RETURNS
 *  Input buffer pointer
 *****************************************************************************/
extern U8 *mmi_frm_get_cur_tab_n_input_buffer(U16 screen_id, U16 *size);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_general_tab_entry_change_page_index
 * DESCRIPTION
 *  This function is used for change the first page index in history
 * PARAMETERS
 *   screen_id   : [IN] screen id
 *   page_index  : [IN] tab page index
 * RETURNS
 *  MMI_TRUE if success to change page index;
 *  MMI_FALSE if fail to change page index.
 *****************************************************************************/
extern MMI_BOOL mmi_frm_general_tab_entry_change_page_index(U16 screen_id, U8 page_index);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_first_sel_page
 * DESCRIPTION
 *  Set current select index of tab page.
 * PARAMETERS
 *  index :  [IN] page index
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_set_first_sel_page(S32 index);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_cur_sel_page
 * DESCRIPTION
 *  Get current select index of tab page.
 * PARAMETERS
 *  void
 * RETURNS
 *  Page index
 *****************************************************************************/
extern U8 mmi_frm_get_cur_sel_page(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_general_tab_delete_hdlr
 * DESCRIPTION
 *  This function is used for destroy tab manager.
 * PARAMETERS
 *   void*
 * RETURNS
 *  Allow deleting
 *****************************************************************************/
extern U8 mmi_frm_general_tab_delete_hdlr(void* p);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_general_tab_exit
 * DESCRIPTION
 *  This function is used for save information about tab group. The 
 *  information include which tab page be selected and the pointer to 
 *  attached tab manager buffer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_general_tab_exit(void);

#endif /* HISTORY_TAB_MANGER */


/* events.c */
extern U8 EntryNewScreen(U16 newscrnID, FuncPtr newExitHandler, FuncPtr newEntryHandler, void *flag);        /* execute current entry func handler */
extern U8 EntryNewScreen_Ext(U16 newscrnID, FuncPtr newExitHandler, FuncPtr newEntryHandler, void *peerBuf);    /* execute current entry func handler without clear all keyhandler */
extern void SetCurrExitFuncPtr(FuncPtr ptr);
extern FuncPtr GetCurrExitFuncPtr(void);
extern void SetCurrEntryFuncPtr(FuncPtr ptr);
extern FuncPtr GetCurrEntryFuncPtr(void);
extern void ReplaceNewScreenHandler(U16 scrnID, FuncPtr exitFuncPtr, FuncPtr entryFuncPtr);     /* execute replace current screen screen id, exit and entry func handler */
extern void GenericExitInlineScreen(U16 scrnID, FuncPtr entryFuncPtr);
extern void GenericExitScreen(U16 scrnID, FuncPtr entryFuncPtr);



/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_curr_exit_hdlr
 * DESCRIPTION
 *  Sets current exit function
 * PARAMETERS
 *  ptr     : [IN]  The pointer to the exit function.      
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_set_curr_exit_hdlr(exit_func_ptr ptr);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_curr_exit_hdlr
 * DESCRIPTION
 *  Get current exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  The pointer to the current exit function
 *****************************************************************************/
extern exit_func_ptr mmi_frm_get_curr_exit_hdlr(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_curr_entry_hdlr
 * DESCRIPTION
 *  Get current entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  The pointer to the current entry function.
 *****************************************************************************/
extern entry_func_ptr mmi_frm_get_curr_entry_hdlr(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_replace_new_scrn_hdlr
 * DESCRIPTION
 *  This function is used for sets current new screen handlers.
 * PARAMETERS
 *  scrnID:              [IN]   The screen ID.     
 *  exitFuncPtr:         [IN]   The exit handler.     
 *  entryFuncPtr:        [IN]   The entry handler.     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_replace_new_scrn_hdlr(U16 scrn_id, exit_func_ptr exit_func_p, entry_func_ptr entry_func_p);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_exit_scrn_arg
 * DESCRIPTION
 *  This function is to get exit screen argument.
 * PARAMETERS
 *  void
 * RETURNS
 *  return argument address.
 *****************************************************************************/
extern void* mmi_frm_get_exit_scrn_arg(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_active_scrn_arg
 * DESCRIPTION
 *  This function is to set active screen argument.
 * PARAMETERS
 *   arg_p:        [IN]  User data address.
 * RETURNS
 *  void
 *****************************************************************************/
extern void  mmi_frm_set_active_scrn_arg(void *arg_p);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_create_new_screen
 * DESCRIPTION
 *  The application could use this API to create a new screen and pass the 
 *  screen¡¯s argument through invoke the entry function of the screen.
 * PARAMETERS
 *  entry_func  : [IN] The entry handler of the new screen. 
 *  arg         : [IN] the screen¡¯s argument
 * RETURNS
 *  If succeed returns MMI_TRUE, otherwise  
 *  Returns MMI_TRUE if it succeed; otherwise returns MMI_FALSE. 
 *****************************************************************************/
extern MMI_BOOL mmi_frm_create_new_screen(entry_func_ptr entry_func, void* arg);

/*****************************************************************************
 * FUNCTION
 *  mmi_entry_new_screen
 * DESCRIPTION
 *  This function is used for enter the new screen. When the applications call
 *  this function, it executes the previous screen's exit handler, and adds the
 *  previous screen in the history, then clears the key handlers and entries the
 *  new screen with the parameter setting. After the applications call 
 *  mmi_frm_entry_new_screen(), they can draw the specified category screen.
 * PARAMETERS
 *  new_scrn_id           : [IN] The new screen ID will enter.       
 *  new_exit_handler      : [IN] The exit handler of the new screen. It could be NULL.       
 *  new_entry_handler     : [IN] The entry handler of the new screen. It could be NULL.       
 *  flag                  : [IN] flag parameters.        
 * RETURNS
 *  MMI_TRUE - enter the new screen succeed.
 *  MMI_FALSE - enter the new screen failed.
 *****************************************************************************/
extern U8 mmi_frm_entry_new_screen(U16 new_scrn_id, exit_func_ptr new_exit_handler, entry_func_ptr new_entry_handler, void *flag);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_generic_exit_scrn
 * DESCRIPTION
 *  This function is the general screen's exit handler. If the previous screen
 *  is the normal screen (not inline editor screen) and needs to add in the 
 *  history, the framework calls this function to execute the general exit 
 *  handler first, then tries to call its exit handler.
 * PARAMETERS
 *  scrnID              : [IN]        The specified screen ID will exit.
 *  entryFuncPtr        : [IN]        The entry handler of the specified screen. 
 *                                  The specified screen without inputBuffer[ ].
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_generic_exit_scrn(U16 scrn_id, entry_func_ptr entry_func_ptr);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_generic_exit_inline_scrn
 * DESCRIPTION
 *  This function is the general inline screen's exit handler. If the previous 
 *  screen is the inline editor screen and needs to add in the history, the 
 *  framework calls this function to execute the general exit handler first, 
 *  then tries to call its exit handler.
 * PARAMETERS
 *  scrn_id               : [IN]     The specified screen ID will exit.
 *  entry_func_ptr        : [IN]     The entry handler of the specified screen. 
 *                                  The specified screen should be inline editor
 *                                  screen.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_generic_exit_inline_scrn(U16 scrn_id, entry_func_ptr entry_func_ptr);

/* DOM-NOT_FOR_SDK-BEGIN */
#endif
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  GoBackHistory
 * DESCRIPTION
 *  This is used to goback previous screen history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void GoBackHistory(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_is_redrawing_bk_screens
 * DESCRIPTION
 *  This function is used to judge if in small screen redraw procedure.
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  1 means in small screen redraw procedure, otherwise return 0
 *****************************************************************************/
extern S32 mmi_is_redrawing_bk_screens(void);

/*----------------------------------------------------------------*
  Small Screen Series APIs
 *----------------------------------------------------------------*/

/*****************************************************************************
 * FUNCTION
 *  enable_resized_small_screen
 * DESCRIPTION
 *  This function is used by application to tell category to show small screen
 *  if the specified category support small screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void enable_resized_small_screen(void);

/*****************************************************************************
 * FUNCTION
 *  disable_resized_small_screen
 * DESCRIPTION
 *  This function is used by application to tell category to show full screen
 *  if the specified category support small screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void disable_resized_small_screen(void);

/*****************************************************************************
 * FUNCTION
 *  whether_no_small_screen
 * DESCRIPTION
 *  This function is used by category to judge show full screen or show small
 *  screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 whether_no_small_screen(void);

/*****************************************************************************
 * FUNCTION
 *  set_small_screen
 * DESCRIPTION
 *  Categories use this API tell framework, he will draw a small screen and
 *  framework will enable small screen redrawing mech.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void set_small_screen(void);

/*****************************************************************************
 * FUNCTION
 *  reset_small_screen
 * DESCRIPTION
 *  Called by category to tell history that it is exiting from small screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void reset_small_screen(void);

/*****************************************************************************
 * FUNCTION
 *  force_no_small_screen
 * DESCRIPTION
 *  Called by Application to disable small screen history saving.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void force_no_small_screen(void);

/*****************************************************************************
 * FUNCTION
 *  restore_small_screen
 * DESCRIPTION
 *  Restores small screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void restore_small_screen(void);

/*****************************************************************************
 * FUNCTION
 *  GetActiveScreenId
 * DESCRIPTION
 *  This function is used for query the current active screen ID. The 
 *  application use this function to get the current active screen ID in 
 *  different occasions.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return the screen ID
 *****************************************************************************/
extern U16 GetActiveScreenId(void);

/*****************************************************************************
 * FUNCTION
 *  GetExitScrnID
 * DESCRIPTION
 *  This function is used for query the screen ID that will be exited. 
 * PARAMETERS
 *  void
 * RETURNS
 *  Return the screen ID that will be exited.
 *****************************************************************************/
extern U16 GetExitScrnID(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_cur_sel_page
 * DESCRIPTION
 *  Select a tab page in the tab group and enter this page.
 * PARAMETERS
 *  index   : [IN] page index
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_set_cur_sel_page (S32 index);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_general_tab_l_arrow_key_hdlr
 * DESCRIPTION
 *  Left arrow key handler of tab page.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_general_tab_l_arrow_key_hdlr(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_general_tab_r_arrow_key_hdlr
 * DESCRIPTION
 *  Right arrow key handler of tab page.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_general_tab_r_arrow_key_hdlr(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_enable_redraw_empty_bg
 * DESCRIPTION
 *  For the case that application can't fill background in entry function
 *  during redraw, application can call this function to let framework fill
 *  default background.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

extern void mmi_frm_enable_redraw_empty_bg(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_in_exit_hdlr_proc
 * DESCRIPTION
 *  Check if in exit handler process which means in ExecuteCurrExitHandler function.
 * PARAMETERS
 *  void
 * RETURNS
 *  If it's in the exit handler process.
 *****************************************************************************/
extern MMI_BOOL mmi_frm_in_exit_hdlr_proc(void);

#endif /* HISTORYGPROT_INT_H */
/* DOM-NOT_FOR_SDK-END */



#ifndef SUBLCDHISTORYGPROT_INT_H
#define SUBLCDHISTORYGPROT_INT_H
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + Sub LCD History Mech.
 +
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/***************************************************************************** 
* Define
*****************************************************************************/
/* DOM-NOT_FOR_SDK-BEGIN */
/* redefine the function name */
#define  GetCurrSubLCDScreenFunc    GetCurrSubLCDScreenExitFunc
/* DOM-NOT_FOR_SDK-END */

/***************************************************************************** 
* Typedef 
*****************************************************************************/
/* DOM-NOT_FOR_SDK-BEGIN */

/* SubLCD history node struct */
typedef struct _SubLCDhistoryNode
{
    /* screen id */
    U16 scrnID;
    /* screen entry function */
    FuncPtr entryFuncPtr;
} SubLCDHistoryNode;

/* SubLCD history node struct extend */
typedef struct
{
    /* screen id */
    U16 scrnID;
    /* screen entry function */
    FuncPtr entryFuncPtr;
    /* screen GUI buffer */
    U8 guiBuffer[MAX_GUI_BUFFER];
} SubLCDHistoryNodeEx;



/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  ExecSubLCDCurrExitHandler
 * DESCRIPTION
 *  Execute the Current Exit handler of SubLCD
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void ExecSubLCDCurrExitHandler(void);

/*****************************************************************************
 * FUNCTION
 *  AddSubLCDHistory
 * DESCRIPTION
 *  Saves Sublcd function in History
 * PARAMETERS
 *  CurrSubLCDHistory :      [IN]   Current SubLCD History     
 * RETURNS
 *  void
 *****************************************************************************/
extern void AddSubLCDHistory(SubLCDHistoryNode *CurrSubLCDHistory);

/*****************************************************************************
 * FUNCTION
 *  AddSubLCDHistoryWithScrID
 * DESCRIPTION
 *  Saves Sublcd function in History with ScrID
 * PARAMETERS
 *  CurrSubLCDHistory:       [IN] Current SubLCD History       
 *  scrID:                   [IN] Screen ID       
 * RETURNS
 *  void
 *****************************************************************************/
extern void AddSubLCDHistoryWithScrID(SubLCDHistoryNode *CurrSubLCDHistory, U16 scrID);

/*****************************************************************************
 * FUNCTION
 *  AddSubLCDHistoryWithScrIDEx
 * DESCRIPTION
 *  Saves Sublcd function in History with ScrID, and GUI buffer.
 * PARAMETERS
 *  CurrSubLCDHistory      : [IN]   Current SubLCD History with Gui buffer.      
 *  scrID                  : [IN]   Screen ID     
 * RETURNS
 *  void
 *****************************************************************************/
extern void AddSubLCDHistoryWithScrIDEx(SubLCDHistoryNodeEx *CurrSubLCDHistory, U16 scrID);

/*****************************************************************************
 * FUNCTION
 *  SetSubLCDExitHandler
 * DESCRIPTION
 *  Set Exit handler for Current screen
 * PARAMETERS
 *  CurrSubLCDFn :       [IN] Exit handler of current screen.       
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetSubLCDExitHandler(FuncPtr CurrSubLCDFn);

/*****************************************************************************
 * FUNCTION
 *  SetSubLCDEntryHandler
 * DESCRIPTION
 *  Set Entry handler for Current screen
 * PARAMETERS
 *  CurrSubLCDFn :        [IN]  Entry Handler function pointer.            
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetSubLCDEntryHandler(FuncPtr CurrSubLCDFn);

/*****************************************************************************
 * FUNCTION
 *  ShowSubLCDScreen
 * DESCRIPTION
 *  Calls entry function of the specified screen on the
 *  sub-LCD screen
 * PARAMETERS
 *  SubLCDEntryFn      : [IN]  Entry Handler function pointer.      
 * RETURNS
 *  void
 *****************************************************************************/
extern void ShowSubLCDScreen(FuncPtr SubLCDEntryFn);

/*****************************************************************************
 * FUNCTION
 *  ForceSubLCDScreen
 * DESCRIPTION
 *  force to call entry function of a screen SubLCD Screen
 * PARAMETERS
 *  SubLCDEntryFn      : [IN]  Entry Handler function pointer.      
 * RETURNS
 *  void
 *****************************************************************************/
extern void ForceSubLCDScreen(FuncPtr SubLCDEntryFn);

/*****************************************************************************
 * FUNCTION
 *  DisplaySubLCDScreen
 * DESCRIPTION
 *  Display a screen SubLCD Screen
 * PARAMETERS
 *  scrnId           :  [IN]   SubLCD screen ID.     
 *  SubLCDEntryFn    :  [IN]   Entry Handler function pointer.     
 *  is_force         :  [IN]   is_forse or not.     
 * RETURNS
 *  void
 *****************************************************************************/
extern void DisplaySubLCDScreen(U16 scrnId, FuncPtr SubLCDEntryFn, MMI_BOOL is_force);

/*****************************************************************************
 * FUNCTION
 *  GoBackSubLCDHistory
 * DESCRIPTION
 *  Go back to history On SubLCD Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void GoBackSubLCDHistory(void);

/*****************************************************************************
 * FUNCTION
 *  GoBacknSubLCDHistory
 * DESCRIPTION
 *  Go back 'n' history On SubLCD Screen
 * PARAMETERS
 *  nHistory     :   [IN]  the number that need to goback, not contain current index.       
 * RETURNS
 *  void
 *****************************************************************************/
extern void GoBacknSubLCDHistory(U16 nHistory);

/*****************************************************************************
 * FUNCTION
 *  GoBackToSubLCDHistory
 * DESCRIPTION
 *  Goes back to specified screen on sub-LCD
 * PARAMETERS
 *  scrnid    :  [IN]  Screen ID that need to go to.      
 * RETURNS
 *  U8 - status
 *****************************************************************************/
extern U8 GoBackToSubLCDHistory(U16 scrnid);

/*****************************************************************************
 * FUNCTION
 *  GoBeyondSubLCDMarkerScr
 * DESCRIPTION
 *  Go one node beyond  marker screen on sub-LCD
 * PARAMETERS
 *  scrnid   :  [IN] The screen id that need to go beyond.        
 * RETURNS
 *  U8 - status
 *****************************************************************************/
extern U8 GoBeyondSubLCDMarkerScr(U16 scrnid);

/*****************************************************************************
 * FUNCTION
 *  GoBackBothLCDHistory
 * DESCRIPTION
 *  Go back to history on Main LCD & SubLCD Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void GoBackBothLCDHistory(void);

/*****************************************************************************
 * FUNCTION
 *  DeleteUptoSubLCDScrID
 * DESCRIPTION
 *  Go to a screen on sub-LCD and delete history of all ahead of it
 * PARAMETERS
 *  scrnid   :   [IN]   Screen ID that need to delete up to.     
 * RETURNS
 *  U8 - status success or fail.
 *****************************************************************************/
extern U8 DeleteUptoSubLCDScrID(U16 scrnid);

/*****************************************************************************
 * FUNCTION
 *  DeleteNSubLCDScrId
 * DESCRIPTION
 *  Deletes up to screen id on sub-LCD and go  beyond it one node
 * PARAMETERS
 *  scrnid     : [IN]        
 * RETURNS
 *  U8 - status success or fail.
 *****************************************************************************/
extern U8 DeleteNSubLCDScrId(U16 scrnid);

/*****************************************************************************
 * FUNCTION
 *  DeleteSubLCDScreen
 * DESCRIPTION
 *  Deletes Screen from sub-LCD history
 *  This screen id won't be deleted
 * PARAMETERS
 *  ScrId      : [IN]   SubLCD screen ID.     
 * RETURNS
 *  U16 - status
 * REMARK
 *  The behavior is the same with DeleteScreenIfPresent()
 *****************************************************************************/
extern U16 DeleteSubLCDScreen(U16 ScrId);

/*****************************************************************************
 * FUNCTION
 *  DeleteNSubLCDHistory
 * DESCRIPTION
 *  Deletes 'n' history nodes from current Sub LCDhistory index
 *  
 *  This shall pop 'n' history nodes without invoking
 *  entry functions of the deleted nodes
 * PARAMETERS
 *  DeleteCount   :  [IN]     The number that need to delete.         
 * RETURNS
 *  void
 *****************************************************************************/
extern void DeleteNSubLCDHistory(U16 DeleteCount);

/*****************************************************************************
 * FUNCTION
 *  DeleteBeyondSubLCDScrTillScr
 * DESCRIPTION
 *  To delete scrns beyond scrn A
 *  till scrn B
 * PARAMETERS
 *  beyondScrnid      :  [IN]  beyond screen id.      
 *  tillScrnid        :  [IN]  till screen id.         
 * RETURNS
 *  U16 - status
 *****************************************************************************/
extern U8 DeleteBeyondSubLCDScrTillScr(U16 beyondScrnid, U16 tillScrnid);

/*****************************************************************************
 * FUNCTION
 *  DeleteBetweenSubLCDScreen
 * DESCRIPTION
 *  Deletes Between two Screens including the boundaries
 * PARAMETERS
 *  StartScrId   :   [IN]   start screen id.    
 *  EndScrId     :   [IN]   End screen id.    
 * RETURNS
 *  U16 - status
 *****************************************************************************/
extern U16 DeleteBetweenSubLCDScreen(U16 StartScrId, U16 EndScrId);

/*****************************************************************************
 * FUNCTION
 *  SubLCDHistoryReplace
 * DESCRIPTION
 *  To replace a specific history
 *  HistoryReplace will be used for a exist history
 * PARAMETERS
 *  out_scrn_id    : [IN]        
 *  in_scrn_id     : [IN]        
 *  in_src_func    : [IN]        
 * RETURNS
 *  pBool
 *****************************************************************************/
extern pBOOL SubLCDHistoryReplace(U16 out_scrn_id, U16 in_scrn_id, FuncPtr in_src_func);

/*****************************************************************************
 * FUNCTION
 *  IsSubLCDHistoryBack
 * DESCRIPTION
 *  Queries SubLCD history is back now or not
 * PARAMETERS
 *  void
 * RETURNS
 *  If it's goback now or not.
 *****************************************************************************/
extern pBOOL IsSubLCDHistoryBack(void);

/*****************************************************************************
 * FUNCTION
 *  IsSubLCDScreenPresent
 * DESCRIPTION
 *  Queries history for presence of a screen Id in sub-LCD history
 * PARAMETERS
 *  scrnId      :    [IN]    SubLCD screen id.         
 * RETURNS
 *  pBOOL
 *****************************************************************************/
extern pBOOL IsSubLCDScreenPresent(U16 scrnId);

/*****************************************************************************
 * FUNCTION
 *  GetCurrSubLCDScreenExitFunc
 * DESCRIPTION
 *  Queries present screen exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  screen exit function pointer.
 *****************************************************************************/
extern FuncPtr GetCurrSubLCDScreenExitFunc(void);

/*****************************************************************************
 * FUNCTION
 *  GetCurrSubLCDScreenEntryFunc
 * DESCRIPTION
 *  Queries current screen entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  screen entry function pointer.
 *****************************************************************************/
extern FuncPtr GetCurrSubLCDScreenEntryFunc(void);

/*****************************************************************************
 * FUNCTION
 *  GetSubLCDScreenCountInHistory
 * DESCRIPTION
 *  Get the screen numbers in subLCD history
 * PARAMETERS
 *  void
 * RETURNS
 *  S16 - screen count
 *****************************************************************************/
extern S16 GetSubLCDScreenCountInHistory(void);

/*****************************************************************************
 * FUNCTION
 *  GetSubLCDHistory
 * DESCRIPTION
 *  Used to get sub LCD history buffer for a screen id
 * PARAMETERS
 *  scrnId         : [IN] screen id.        
 *  ptrHistory     : [OUT] history node address include gui buffer.        
 * RETURNS
 *  FuncPtr
 *****************************************************************************/
extern U8 GetSubLCDHistory(U16 scrnID, SubLCDHistoryNodeEx *ptrHistory);

/*****************************************************************************
 * FUNCTION
 *  GetCurrSubLCDGuiBuffer
 * DESCRIPTION
 *  gets current Sub LCD screen gui buffer
 * PARAMETERS
 *  scrnId          [IN]  Current screen id.           
 * RETURNS
 *  FuncPtr
 *****************************************************************************/
extern U8 *GetCurrSubLCDGuiBuffer(U16 scrnid);

/*****************************************************************************
 * FUNCTION
 *  GetPreviousSubLCDScrnIdOf
 * DESCRIPTION
 *  Queries previous scrn id of this Id
 * PARAMETERS
 *  scrnId           :   [IN] Current screen id.       
 *  previousScrnId   :   [OUT] Previous screen id.             
 * RETURNS
 *  FuncPtr
 *****************************************************************************/
extern pBOOL GetPreviousSubLCDScrnIdOf(U16 scrnId, U16 *previousScrnId);

/*****************************************************************************
 * FUNCTION
 *  GetNextSubLCDScrnIdOf
 * DESCRIPTION
 *  Queries next scrn id of this Id
 * PARAMETERS
 *  scrnId        :  [IN]  Current screen id.      
 *  nextScrnId    :  [OUT] The next screen id.         
 * RETURNS
 *  FuncPtr
 *****************************************************************************/
extern pBOOL GetNextSubLCDScrnIdOf(U16 scrnId, U16 *nextScrnId);

/*****************************************************************************
 * FUNCTION
 *  GetSubLCActiveScreenId
 * DESCRIPTION
 *  Get current screen id of Sub LCD.
 *  This is used to clear all the interrupt event handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  Current screen id.
 *****************************************************************************/
extern U16 GetSubLCActiveScreenId(void);

/*****************************************************************************
 * FUNCTION
 *  GetSubLCDExitScrnId
 * DESCRIPTION
 *  Gets current exit screen id of Sub LCD
 * PARAMETERS
 *  void
 * RETURNS
 *  Exit Function pointer.
 *****************************************************************************/
extern U16 GetSubLCDExitScrnId(void);

/*****************************************************************************
 * FUNCTION
 *  GetSubLCDScrnId
 * DESCRIPTION
 *  Gets the id of Sub LCD screen
 * PARAMETERS
 *  index       : [IN] SubLCD screen ID.       
 * RETURNS
 *  FuncPtr
 *****************************************************************************/
extern U16 GetSubLCDScrnId(U16 index);

/*****************************************************************************
 * FUNCTION
 *  DinitSubLCDHistory
 * DESCRIPTION
 *  De-intialize SubLCD Screen history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void DinitSubLCDHistory(void);
#endif /* SUBLCDHISTORYGPROT_INT_H */
/* DOM-NOT_FOR_SDK-END */


#endif /* MMI_FRM_HISTORY_GPROT_H */ 


