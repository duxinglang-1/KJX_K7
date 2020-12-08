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
 * HistoryGprot_Int.h
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef HISTORYGPROT_INT_H
#define HISTORYGPROT_INT_H

/***************************************************************************** 
* Define
*****************************************************************************/
/* maximum history data */
#if defined(WAP_SUPPORT)
    #define MAX_INPUT_BUFFER         1600
#elif defined(__MMI_BROWSER_2__)
    #define MAX_INPUT_BUFFER         1500
#else    
    #define MAX_INPUT_BUFFER         1024
#endif

#ifndef MAX_GUI_BUFFER
#define MAX_GUI_BUFFER           128
#endif

/* Definition for delete callback handler */
#define MMI_HIST_EXIT_SCREEN_TYPE       (1)
#define MMI_HIST_DELETE_SCREEN_TYPE     (0)

#define MMI_HIST_STOP_DELETING          (1)
#define MMI_HIST_ALLOW_DELETING         (0)

#define MMI_HIST_TOP_SCREEN             GetCurrScrnId()

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/* JL added for new history callback */
typedef U8(*HistoryDelCBPtr) (void *);
typedef U8(*MainLcdHistoryCBPtr) (void *);
typedef U8* (*HistoryGetData) (U8*);    /* Get GUI-buffer/input-buffer to history */
typedef S32 (*HistoryGetSize) (void);   /* Get input buffer size */
typedef void *(*MemAlloc) (U32);
typedef void (*MemFree) (void *);

typedef enum
{
    MMI_HIST_NODE_NORMAL = 0,
    MMI_HIST_NODE_DELETING,
    MMI_HIST_NODE_GOBACKING,
    MMI_HIST_NODE_WAIT_TO_DESTROY,

    /* add the enum value above here */
    MMI_HIST_NODE_END    
}mmi_history_node_status_enum;

typedef enum
{
    MMI_FRM_SCREEN_NONE,     /* The initial state */
    MMI_FRM_SCREEN_FORWARD,  /* Show the screen */
    MMI_FRM_SCREEN_BACKWARD, /* Go back to previous screen */
    MMI_FRM_SCREEN_REDRAW,   /* In small screen procedure */
    MMI_FRM_SCREEN_INACTIVE, /* The screen is in the history */
    MMI_FRM_SCREEN_DELETE,   /* Delete the screen in the history */
    MMI_FRM_SCREEN_DESTROY,  /* Destroy the screen */

    /* add the enum value above here */
    MMI_FRM_SCREEN_END    
}mmi_frm_screen_state_enum;

typedef struct{
    U16 new_scrn_id;
    U16 curr_scrn_id;
    mmi_frm_screen_state_enum state;
} mmi_frm_scrn_info_struct;

typedef void (*entry_func_ptr) (void *arg);
typedef void (*exit_func_ptr) (void *arg);

typedef enum
{
    MMI_HIST_SMALLSCREEN_NONE,
    MMI_HIST_SMALLSCREEN_ACTIVE,
    MMI_HIST_SMALLSCREEN_ACTIVE_IN_EXIT_FUNC,
    
    /* add the enum value above here */
    MMI_HIST_SMALLSCREEN_END
}mmi_hist_smallscreen_state_enum;





/* history information stuct */
typedef struct _history
{
    U16 scrnID;
    FuncPtr entryFuncPtr;
    U8 inputBuffer[MAX_INPUT_BUFFER];   /* running text data                   */
    U8 guiBuffer[MAX_GUI_BUFFER];       /* this includes hilite item, input mode & etc.. */
} history;

/* history information stuct */
typedef struct _historyNode
{
    U32     isTab : 1;
    U32     isGroupNode : 1;

    U32     isSmallScreen : 1;

    U16     scrnID;
    U8      *inputBuffer;        /* running text data                   */
    U8      *guiBuffer;          /* this includes hilite item, input mode & etc.. */
    void    *app_arg;

    MemAlloc        mallcFuncPtr;  /* keep the memory allocated function */
    MemFree         mfreeFuncPtr;  /* keep the memory freed function */
    entry_func_ptr  entryFuncPtr;
    exit_func_ptr   exitFuncPtr;
//    HistoryDelCBPtr delScrnCBFuncPtr;
    HistoryDelCBPtr destroyFuncPtr;

    mmi_history_node_status_enum status;   
} historyNode;

/* history information stuct */
typedef struct _historyCallback
{
    U16 scrnID;
    HistoryDelCBPtr historydelCBPtr;
} historyCallback;

typedef struct
{
    U16     screen_id;
    FuncPtr tab_entry_func;
    U8*     tab_icon;
    U8*     tab_string;
    void*   user_data;
}mmi_frm_tab_struct;

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/



/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
extern void InitHistory(MainLcdHistoryCBPtr main_root_ptr, SubLcdHistoryCBPtr sub_root_ptr);
extern void HistoryDump(void);
extern MMI_BOOL HistoryReplace(U16 out_scrn_id, U16 in_scrn_id, FuncPtr in_src_func);


#ifdef OSL_MEMORY_DUMP
    extern void AddHistoryReferenceMemoryRecord(history *addHistory, char *fileName, int lineNumber);
    #define AddHistory(addHistory) AddHistoryReferenceMemoryRecord(&(addHistory), __FILE__, __LINE__)
#else /* OSL_MEMORY_DUMP */ 
    extern void AddHistoryReference(history *addHistory);
    #define AddHistory(addHistory) AddHistoryReference(&(addHistory))

    extern void InsertHistoryBeforeThisScrnReference(U16 scrnId, history *addHistory);
    #define InsertHistoryBeforeThisScrn(scrnId, addHistory) InsertHistoryBeforeThisScrnReference(scrnId, &(addHistory))
#endif /* OSL_MEMORY_DUMP */ 

extern MMI_BOOL InsertHistoryAfterThisScrnReference(U16 scrnId, history *addHistory);


extern U8 GetHistory(U16 scrnID, history *ptrHistory);
extern U8 GetHistoryPointer(U16 scrnID, historyNode **ptrHistory);

/* please change to use GetHistoryPointer, rather than GetHistoryScrID */
extern U8 GetHistoryScrID(U16 scrnID, historyNode **ptrHistory);
extern MMI_BOOL CheckIsBackHistory(void);
extern void GoBackHistory(void);
extern U8 GoBackToHistory(U16 scrnid);
extern U8 GoBacknHistory(U16 nHistory);
extern S16 GetScreenCountInHistory(void);
extern U8 *GetCurrGuiBuffer(U16 scrnid);                /* get current screen history */
extern U8 *GetCurrInputBuffer(U16 scrnid);
extern void DeleteNHistory(U16 DeleteCount);
extern void ExecutecurrHisIndEntryFunc(void);
extern U8 GoBeyondMarkerScr(U16 scrnid);
extern U8 DeleteScreens(U16 start_scrnid, U16 end_scrnid);

extern U32 DeleteHistory(U16 startScrId, U8 bIncStart, U16 count, U16 endScrId, U8 bIncEnd);

extern U8 DeleteBeyondScrTillScr(U16 beyondScrnid, U16 tillScrnid);
extern U16 DeleteBetweenScreen(U16 StartScrId, U16 EndScrId);
extern U8 DeleteUptoScrID(U16 scrnid);
extern U16 DeleteScreenFromToNnodes(U16 ScrId, U16 num_nodes);
extern U8 DeleteFromScrUptoScr(U16 start_scrnid, U16 upto_scrnid);
extern U8 DeleteNScrId(U16 scrnid);
extern U16 DeleteScreenIfPresent(U16 ScrId);
extern MMI_BOOL IsScreenPresent(U16 scrnId);
extern MMI_BOOL IsMainLCDHistoryBack(void);
extern U8 IsCurrMarkerScreen(U16 scrnid);
extern void DinitHistory(void);
extern U8 ExecuteRootMainHistoryScreen(void *funcPtr);  /* execute main lcd history callback function and root history function */
extern U8 GetNHistory(U16 scrnID, history *ptrHistory);

extern void AddNHistory_ext(history *addHistory, U16 size);

#define AddNHistory(addHistory,size)   AddNHistory_ext(&(addHistory),size)

MMI_BOOL mmi_frm_add_history(
            U16 scrn_id,                            /* the screen id */
            entry_func_ptr entryFuncPtr,            /* the screen's entry function */
            HistoryGetData getGuiFuncPtr,           /* the function to get GUI data */
            HistoryGetSize getInputBufSizeFuncPtr,  /* the function to get input buffer size */
            HistoryGetData getInputBufFuncPtr,      /* the function to get input buffer */
            MemAlloc mallocFuncPtr,                 /* the function to allocate memory */
            MemFree mfreeFuncPtr,                   /* the function to free memory */
            void* app_arg_p);

#define AddHistoryEx(scrnID, entryFuncPtr, getGuiFuncPtr, getInputBufSizeFuncPtr, getInputBufFuncPtr, mallocFuncPtr, mfreeFuncPtr) \
    mmi_frm_add_history(scrnID, (entry_func_ptr)entryFuncPtr, getGuiFuncPtr, getInputBufSizeFuncPtr, getInputBufFuncPtr, mallocFuncPtr, mfreeFuncPtr, NULL) 

extern MMI_BOOL mmi_frm_set_destroy_scrn_callback(U16 scrn_id, HistoryDelCBPtr func_ptr);
extern MMI_BOOL mmi_frm_history_replace(U16 out_scrn_id, U16 in_scrn_id, entry_func_ptr in_src_func);
extern MMI_BOOL mmi_frm_history_replace_ex(U16 out_scrn_id, U16 in_scrn_id, entry_func_ptr in_src_func, U16 is_small_screen);
extern void* mmi_frm_get_argument_with_screen(U16 scrn_id);
extern void* mmi_frm_get_current_screen_argument(void);
extern MMI_BOOL mmi_frm_get_screen_info(U16 scrn_id, mmi_frm_scrn_info_struct *info);
extern void mmi_set_orderly_exit_screen(void);
extern U8 *GetCurrNInputBuffer(U16 scrnid, U16 *size);
extern MMI_BOOL GetPreviousScrnIdOf(U16 scrnId, U16 *previousScrnId);
extern MMI_BOOL GetNextScrnIdOf(U16 scrnId, U16 *nextScrnId);
extern U16 GetCurrScrnId(void);
extern U8 SetDelScrnIDCallbackHandler(U16 ScrnID, HistoryDelCBPtr funcPtr);
extern U8 ClearDelScrnIDCallbackHandler(U16 ScrnID, HistoryDelCBPtr funcPtr);
extern void set_small_screen(void); 
extern void reset_small_screen(void);
extern void force_no_small_screen(void);
extern void restore_small_screen(void);
extern S32 mmi_is_redrawing_bk_screens(void);
extern mmi_hist_smallscreen_state_enum mmi_get_redrawing_bk_screens_status(void);
extern MMI_BOOL mmi_set_redrawing_bk_screens_status(mmi_hist_smallscreen_state_enum status);
extern U16 GetCurrSmallScrnID(void);
extern S16 mmi_frm_get_screen_index(U16 screen_id);
/* 
 * enable_resized_small_screen(), disable_resized_small_screen(), and whether_no_small_screen()
 * There is no relation with small screen process in history.
 * It's only used for tha WGUI and application and decide to 
 * show the small screen or the normal screen.
 */
extern void enable_resized_small_screen(void);
extern void disable_resized_small_screen(void);
extern S32 whether_no_small_screen(void);
extern MMI_BOOL mmi_frm_general_tab_entry(U16 screen_id, FuncPtr entry_func_ptr, mmi_frm_tab_struct *tab_pages_info_array, U8 tab_pages_count);
extern MMI_BOOL mmi_frm_general_tab_entry_ex(U16 screen_id, FuncPtr entry_func_ptr, mmi_frm_tab_struct *tab_pages_info_array, U8 tab_pages_count, U8 sel_idx);
extern void mmi_frm_general_tab_exit(void);
extern U8 mmi_frm_general_tab_delete_hdlr(void* p);
extern MMI_BOOL mmi_frm_add_tab_history(U16 screen_id , history *tab_page_history);
extern MMI_BOOL mmi_frm_add_tab_n_history(U16 screen_id , history *tab_page_history, U16 size);
extern void mmi_frm_set_cur_sel_page (S32 index);
extern U8 *mmi_frm_get_cur_tab_gui_buffer(U16 screen_id);
extern U8 *mmi_frm_get_cur_tab_input_buffer(U16 screen_id);
extern U8 *mmi_frm_get_cur_tab_n_input_buffer(U16 screen_id, U16 *size); 
extern void mmi_frm_general_tab_l_arrow_key_hdlr(void);
extern void mmi_frm_general_tab_r_arrow_key_hdlr(void);
extern void mmi_frm_set_first_sel_page(S32 index);
extern MMI_BOOL mmi_frm_general_tab_entry_change_page_index(U16 screen_id, U8 page_index);
extern MMI_BOOL mmi_frm_history_is_held(void);
extern MMI_BOOL mmi_frm_hold_history_buffer(U16 scrn_id);
extern MMI_BOOL mmi_frm_free_history_buffer(U16 scrn_id);

#endif /* HISTORYGPROT_INT_H */ 


