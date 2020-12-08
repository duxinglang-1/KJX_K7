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
 *  wgui_categories_search.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Category header file
 *
 * Author:
 * -------
 *  
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __WGUI_CATEGORIES_SEARCH_H__
#define __WGUI_CATEGORIES_SEARCH_H__

//RHR
    #include "MMI_features.h"
    #include "Gui_Setting.h"
    #include "wgui.h"
    #include "gui_typedef.h"
    #include "MMIDataType.h"
    #include "gui_data_types.h"
    #include "kal_general_types.h"
    #include "wgui_draw_manager.h"
    #include "ImeGprot.h"

#if defined(__MMI_MAINLCD_96X64__)
    
#define   INFO_HIGHT INFORMATION_BAR_HEIGHT  // SLIM_96_64_SLIM   
#define   MMI_CATEGORIES_SUPPORT_EDITOR_INFO_BAR 
#endif
/* DOM-NOT_FOR_SDK-BEGIN */
#ifdef __MMI_CAT103_SUPPORT__
    #define CAT103_SINGLE_LINE_INPUTBOX_Y     (MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_SINGLELINE_INPUTBOX_HEIGHT - 1)
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    #define CAT103_DYNAMIC_LIST_Y             (MMI_TITLE_HEIGHT)
#else
    #define CAT103_DYNAMIC_LIST_Y             (MMI_STATUS_BAR_HEIGHT + MMI_TITLE_HEIGHT)    
#endif /* MMI_SHOW_STATUS_ICON_IN_TITLE */    
    #define CAT103_DYNAMIC_LIST_H             (CAT103_SINGLE_LINE_INPUTBOX_Y - CAT103_DYNAMIC_LIST_Y - INFORMATION_BAR_HEIGHT)
    #define CAT103_INVALID_HIGHLIGHT          (WGUI_LIST_INVALID_HIGHLIGHT)

    extern void (*g_wgui_cat103_resize_and_draw_func) (S32);
    extern void (*g_wgui_cat103_highlight_handler) (S32);
    extern S32 (*g_wgui_cat103_search_function) (UI_buffer_type);
/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  wgui_cat103_set_right_softkey_function
 * DESCRIPTION
 *  set right softkey function of category103
 * PARAMETERS
 *  f     : [IN] <N/A />  RSK function
 *  k     : [IN] <N/A />  key event type
 * RETURNS
 *  void
 *****************************************************************************/
    extern void wgui_cat103_set_right_softkey_function(void (*f) (void), MMI_key_event_type k);

/* DOM-NOT_FOR_SDK-BEGIN */    
    extern void wgui_cat103_refresh_input_area(U8* input_buffer, S32 input_buffer_max_length, U32 input_type);
/* DOM-NOT_FOR_SDK-END */    

/*****************************************************************************
 * FUNCTION
 *  wgui_cat103_register_highlight_handler
 * DESCRIPTION
 *  register category103 highlight handler
 * PARAMETERS
 *  f     : [IN] <N/A />   highlight handler function
 * RETURNS
 *  void
 *****************************************************************************/
    extern void wgui_cat103_register_highlight_handler(void (*f) (S32));

/* DOM-NOT_FOR_SDK-BEGIN */     
    extern void wgui_cat103_set_menu_focus_state(MMI_BOOL active);
    extern void wgui_cat103_set_editor_focus_state(MMI_BOOL active);
    extern void wgui_cat103_refresh_search_list(U8 * input_number);
    extern MMI_BOOL wgui_cat103_is_editor_active(void);
/* DOM-NOT_FOR_SDK-END */ 

/********************************************************************
  * FUNCTION
  * ShowCategory103Screen
  * Description
  * category screen for WAP auto-complete
  *  [FTE]: support(tool bar is avaiable)
  * 
  * <img name="wgui_cat103_img1" />
  * Parameters
  * title :                    [IN] <TITLE /> Title
  * title_icon :               [IN] <N/A /> Title icon
  * left_softkey :             [IN] <LSK /> Left softkey label
  * left_softkey_icon :        [IN] <N/A /> Left softkey icon
  * right_softkey :            [IN] <RSK /> Right softkey label
  * right_softkey_icon :       [IN] <N/A /> Right softkey icon
  * number_of_items :          [IN] <N/A /> Number of list items
  * get_item_func :            [IN] <ICONTEXT /> Get menu item function
  * get_hint_func :            [IN] <HINT /> Get menu hint funtion
  * search_func :              [IN] <N/A /> Search result function
  * input_buffer :             [IN] <N/A /> Buffer for input
  * input_buffer_max_length :  [IN] <N/A /> Max length for input
  * history_buffer :           [IN] <N/A /> Histpry buffer
  * Returns
  *  void   
  * EXAMPLE
  * <code>
  * void EntryScreen_103(void)
  * {
  *     U8 *guiBuffer = NULL;
  * 
  *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
  *     memset(g_buffer, 0, MAX_LOCAL_BUFFER); 
  * 
  * 
  *     ShowCategory103Screen(
  *             (UI_string_type) GetString(STR_ID_CSB_TEXT),
  *             0,
  *             (UI_string_type) GetString(STR_ID_CSB_LSK_TEXT),
  *             0,
  *             (UI_string_type) GetString(STR_ID_CSB_RSK_TEXT),
  *             0,
  *             10,
  *             CAT103_INVALID_HIGHLIGHT,
  *             Get_List_Items, 
  *             get_async_hints,
  *             cat103_search_callback,        
  *             (U8*) g_buffer,
  *             CSB_MAX_BUFFER_LEN,
  *             NULL); 
  *     wgui_cat103_register_highlight_handler(cat103_highlight_handler);
  * }
  * </code>                                                         
  ********************************************************************/
    extern void ShowCategory103Screen(
            UI_string_type title,
            PU8 title_icon,
            UI_string_type left_softkey,
            PU8 left_softkey_icon,
            UI_string_type right_softkey,
            PU8 right_softkey_icon,
            S32 number_of_items,
            S32 highlighted_item,
            GetItemFuncPtr get_item_func,
            GetHintFuncPtr get_hint_func,
            S32(*search_func) (UI_buffer_type),
            U8 *input_buffer,
            S32 input_buffer_max_length,
            U32 input_type,
            U8 *history_buffer);

/* DOM-NOT_FOR_SDK-BEGIN */
/* Just for backward compatible with the existing category. */
extern void ShowCategory103Screen_int(
        UI_string_type title,
        PU8 title_icon,
        UI_string_type left_softkey,
        UI_string_type right_softkey,
        S32 number_of_items,
        S32 highlighted_item,
        GetItemFuncPtr get_item_func,
        GetHintFuncPtr get_hint_func,
        S32(*search_func) (UI_buffer_type),
        U8 *input_buffer,
        S32 input_buffer_max_length,
        U32 input_type,
        U8 *history_buffer);

#define ShowCategory103Screen(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14) \
        ShowCategory103Screen_int(_arg0, _arg1, _arg2, _arg4, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14)
/* DOM-NOT_FOR_SDK-END */

#endif /* __MMI_CAT103_SUPPORT__ */


/* DOM-NOT_FOR_SDK-BEGIN */
#if defined(__MMI_MAINLCD_96X64__)
    #define CAT200_MARGIN_WIDTH 2
#else /**/
    #define CAT200_MARGIN_WIDTH 2
#endif
#if defined(__MMI_FTE_SUPPORT__)
    #define CAT200_INPUTBOX_X   2
#else
    #if defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_176X220__)
        #define CAT200_INPUTBOX_X   22
    #elif defined(__MMI_MAINLCD_240X320__)
        #define CAT200_INPUTBOX_X   28
    #elif defined(__MMI_MAINLCD_320X480__)
        #define CAT200_INPUTBOX_X   30
    #elif defined(__MMI_MAINLCD_96X64__)   //SLIM_96_64_SLIM
        #define CAT200_INPUTBOX_X   3        
    #else
        #define CAT200_INPUTBOX_X   26 /* 320x240, 240x400, 320x480 */
    #endif
#endif /* __MMI_FTE_SUPPORT__ */

#if defined(__MMI_FTE_SUPPORT__)
    #if defined(__MMI_MAINLCD_240X320__)
        #define CAT200_INPUTBOX_H  (MMI_SINGLELINE_INPUTBOX_HEIGHT)
    #else
        #define CAT200_INPUTBOX_H  (MMI_SINGLELINE_INPUTBOX_HEIGHT)
    #endif
#else
    #if defined(__MMI_VECTOR_FONT_SUPPORT__)
        #define CAT200_INPUTBOX_H   (34)
    #else /* defined(__MMI_VECTOR_FONT_SUPPORT__) */
        #if defined(__MMI_MAINLCD_320X480__)
        #define CAT200_INPUTBOX_H   (30)
        #else
        #define CAT200_INPUTBOX_H   MMI_SINGLELINE_INPUTBOX_HEIGHT
        #endif /* defined(__MMI_MAINLCD_320X480__) */
    #endif /* defined(__MMI_VECTOR_FONT_SUPPORT__) */
#endif

#if defined(__MMI_FTE_SUPPORT__)
    #if defined(__MMI_MAINLCD_240X320__)
        #define CAT199_INPUTBOX_H   (MMI_SINGLELINE_INPUTBOX_HEIGHT)
    #else
        #define CAT199_INPUTBOX_H   (MMI_SINGLELINE_INPUTBOX_HEIGHT)
    #endif
#else
    #if defined(__MMI_VECTOR_FONT_SUPPORT__)
        #define CAT199_INPUTBOX_H   (34)
    #else /* defined(__MMI_VECTOR_FONT_SUPPORT__) */
        #if defined(__MMI_MAINLCD_128X128__)
        #define CAT199_INPUTBOX_H (MMI_MENUITEM_HEIGHT)
        #else
        #define CAT199_INPUTBOX_H (MMI_SINGLELINE_INPUTBOX_HEIGHT)
        #endif /* defined(__MMI_MAINLCD_128X128__) */
    #endif /* defined(__MMI_VECTOR_FONT_SUPPORT__) */
#endif

#if defined(__MMI_MAINLCD_128X128__)
#define CAT199_MARGIN_WIDTH (0)
#else
#define CAT199_MARGIN_WIDTH (2)
#endif /* defined(__MMI_MAINLCD_128X128__) */

    extern void (*g_wgui_cat200_resize_and_move_func)(S32);
    extern void (*g_wgui_cat200_draw_information_bar_func)(void);
    extern void (*g_wgui_cat200_set_special_key_func)(void);
/* DOM-NOT_FOR_SDK-END */

/****************************************************************************
  * FUNCTION
  *  ShowCategory199Screen
  * Description
  * Show category199 screen
  *  [FTE]: support(tool bar is avaiable)
  * 
  * <img name="wgui_cat199_img1" />
  * Parameters
  * left_softkey :        [IN] <LSK /> Left soft key label
  * left_softkey_icon :   [IN] <N/A /> Left soft key icon
  * right_softkey :       [IN] <RSK /> Right soft key label
  * right_softkey_icon :  [IN] <N/A /> Right soft key icon
  * highlighted_tab :     [IN] <N/A /> Highlighted tab
  * tab_title :           [IN] <TITLE /> Tab title
  * info_message :        [IN] <UNLIM /> Text in info area, NULL will not show
  *                       info area
  * number_of_items :     [IN] <N/A /> Number of items
  * get_item_func :       [IN] <ICONTEXT /> Callback function of get menu item
  * get_hint_func :       [IN] <HINT /> Callback function of get menu item hint
  * get_state_func :      [IN] <TWOSTATE /> Callback function of get state,
  *                       NULL will not show check box
  * set_state_func :      [IN] <N/A /> Callback function of state changed, NULL
  *                       will not show check box
  * highlighted_item :    [IN] <N/A /> Highlighted item index
  * buffer :              [IN] <N/A /> Buffer
  * buffer_max_length :   [IN] <N/A /> Buffer max length
  * history_buffer :      [IN] <N/A /> Histpry buffer
  * Returns
  *  void  
  * EXAMPLE
  * <code>
  * void entry_category199_tab_1(void)
  * {
  *
  *  U8 *guiBuffer = NULL;    
  *
  *  EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID + 2, ExitScreen_Generic, EntryCSBStartView, MMI_TAB_PAGE);
  *
  *  memset(g_buffer, 0, MAX_LOCAL_BUFFER);
  *
  *  RegisterCat200SearchFunction(cat200_callback);
  *
  *   ShowCategory199Screen(
  *          get_string(STR_ID_CSB_LSK_TEXT),
  *          0,
  *          get_string(STR_ID_CSB_RSK_TEXT),
  *          0,
  *          (S8)1,
  *          get_string(STR_ID_CSB_CATEGORY_TEXT),
  *          NULL,
  *          4,
  *          Get_List_Items,
  *          get_async_hints,
  *          NULL,
  *          NULL,
  *          0,
  *          (U8*) g_buffer,
  *          CSB_MAX_BUFFER_LEN,
  *          guiBuffer);
  * }
  *
  * void EntryScreen_199(void)
  * {
  *     mmi_frm_tab_struct tab_pages_info_array[2];
  * 
  *     tab_pages_info_array[0].screen_id = SCR_ID_CSB_DUMMY_SCR_ID + 1;
  *     tab_pages_info_array[0].tab_entry_func = entry_category199_tab_0;
  *     tab_pages_info_array[0].tab_icon = (U8*)GetImage(gIndexIconsImageList[0]);
  *     tab_pages_info_array[0].tab_string = NULL;   
  * 
  *     
  *     tab_pages_info_array[1].screen_id = SCR_ID_CSB_DUMMY_SCR_ID + 2;
  *     tab_pages_info_array[1].tab_entry_func = entry_category199_tab_1;
  *     tab_pages_info_array[1].tab_icon = (U8*)GetImage(gIndexIconsImageList[1]);
  *     tab_pages_info_array[1].tab_string = NULL;
  *     
  *     mmi_frm_general_tab_entry(SCR_ID_CSB_DUMMY_SCR_ID, EntryScreen_199, tab_pages_info_array, 2);
  * }
  * </code>                                                                  
  ****************************************************************************/
    extern void ShowCategory199Screen(
            UI_string_type left_softkey,
            PU8 left_softkey_icon,
            UI_string_type right_softkey,
            PU8 right_softkey_icon,
            S8 highlighted_tab,
            UI_string_type tab_title,
            UI_string_type info_message,
            S32 number_of_items,
            GetItemFuncPtr get_item_func,
            GetHintFuncPtr get_hint_func,
            checkbox_get_image_funcptr_type get_state_func,
            checkbox_clicked_funcptr_type set_state_func,
            S32 highlighted_item,
            U8 *buffer,
            S32 buffer_max_length,
            U8 *history_buffer);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat199_setup_search_button
 * DESCRIPTION
 *  Setup the search button of category199.
 * PARAMETERS
 *  up_image   :       [IN] (N/A) the normal status image of search button.
 *  down_image :       [IN] (N/A) the press-down status image of search button.
 *  search_function :  [IN] (N/A) search function.
 * RETURNS
 *  void.
 *****************************************************************************/
extern void wgui_cat199_setup_search_button(PU8 up_image, PU8 down_image, FuncPtr search_function);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat199_refresh_search_list
 * DESCRIPTION
 *  refresh category199 search list
 * PARAMETERS
 *  no_entries         [IN]   number of menu item
 *  highlighted_item   [IN]   highlight item
 *  has_tab_title      [IN]   if tab has title
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat199_refresh_search_list(S32 no_entries, S32 highlighted_item, BOOL has_tab_title);

/* DOM-NOT_FOR_SDK-BEGIN */
/* Just for backward compatible with the existing category. */
extern void ShowCategory199Screen_int(
        UI_string_type left_softkey,
        UI_string_type right_softkey,
        S8 highlighted_tab,
        UI_string_type tab_title,
        UI_string_type info_message,
        S32 number_of_items,
        GetItemFuncPtr get_item_func,
        GetHintFuncPtr get_hint_func,
        checkbox_get_image_funcptr_type get_state_func,
        checkbox_clicked_funcptr_type set_state_func,
        S32 highlighted_item,
        U8 *buffer,
        S32 buffer_max_length,
        U8 *history_buffer);

#define ShowCategory199Screen(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15) \
        ShowCategory199Screen_int(_arg0, _arg2, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15)
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * define for category199_ext
 ****************************************************************************/
/* MMI_content_width = gap_1 + left_icon_width + gap2 + text_width + gap3 + right_icon + gap_4 */
#define WGUI_CAT199_GAP_1            (4)
#define WGUI_CAT199_GAP_2            (8)
#define WGUI_CAT199_GAP_3            (WGUI_CAT199_GAP_2)
#define WGUI_CAT199_GAP_4            (WGUI_CAT199_GAP_1)


/*****************************************************************************
 * FUNCTION
 *  ShowCategory199Screen_ext
 * DESCRIPTION
 *  Quick search screen, support tab bar.
 *  [FTE]: support(tool bar is avaiable)
 *
 * PARAMETERS
 *  left_softkey            [IN]        Left soft key label
 *  left_softkey_icon       [IN]        Left soft key icon
 *  right_softkey           [IN]        Right soft key label
 *  right_softkey_icon      [IN]        Right soft key icon
 *  highlighted_tab         [IN]        Highlighted tab
 *  tab_title               [IN]        Tab title
 *  number_of_items         [IN]        Number of items
 *  info_message            [IN]        Text in info area, NULL will not show info area
 *  get_item_func           [IN]        Callback function of get menu item 
 *  get_hint_func           [IN]        Callback function of get menu item hint
 *  get_state_func          [IN]        Callback function of get state, NULL will not show check box
 *  set_state_func          [IN]        Callback function of state changed, NULL will not show check box
 *  highlighted_item        [IN]        Highlighted item index
 *  left_icon               [IN]        Menuitme left icon 
 *  right_icon              [IN]        Menuitme right icon 
 *  buffer                  [IN]        Buffer
 *  buffer_max_length       [IN]        Buffer max length
 *  history_buffer          [IN]        Histpry buffer
 * RETURNS
 *  void
 *****************************************************************************/
extern void ShowCategory199Screen_ext(
        UI_string_type left_softkey,
        PU8 left_softkey_icon,
        UI_string_type right_softkey,
        PU8 right_softkey_icon,
        S8 highlighted_tab,
        UI_string_type tab_title,
        UI_string_type info_message,
        S32 number_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        checkbox_get_image_funcptr_type get_state_func,
        checkbox_clicked_funcptr_type set_state_func,
        S32 highlighted_item,
        PU8 left_icon,
        PU8 right_icon,
        U8 *buffer,
        S32 buffer_max_length,
        U8 *history_buffer);

/* DOM-NOT_FOR_SDK-BEGIN */
/* Just for backward compatible with the existing category. */
extern void ShowCategory199Screen_ext_int(
        UI_string_type left_softkey,
        UI_string_type right_softkey,
        S8 highlighted_tab,
        UI_string_type tab_title,
        UI_string_type info_message,
        S32 number_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        checkbox_get_image_funcptr_type get_state_func,
        checkbox_clicked_funcptr_type set_state_func,
        S32 highlighted_item,
        PU8 left_icon,
        PU8 right_icon,
        U8 *buffer,
        S32 buffer_max_length,
        U8 *history_buffer);

#define ShowCategory199Screen_ext(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17) \
        ShowCategory199Screen_ext_int(_arg0, _arg2, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17)
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************************************
  * FUNCTION
  *  ShowCategory200Screen
  * Description
  *  This is a category screen to show quick search screen to user, 
  *  while the the single-line inputbox text is changing, we will callback to application to refresh list.
  *  The charactors will be saved in the buffer which is passed by application.
  *  <FTE: support(tool bar is avaiable) />
  * 
  * <img name="wgui_cat200_img1" />
  * Parameters
  * title :               [IN] <TITLE /> Title id
  * title_icon :          [IN] <N/A /> Title icon
  * left_softkey :        [IN] <LSK /> Left soft key label
  * left_softkey_icon :   [IN] <N/A /> Left soft key icon
  * right_softkey :       [IN] <RSK /> Right soft key label
  * right_softkey_icon :  [IN] <N/A /> Right soft key icon
  * number_of_items :     [IN] <N/A /> Number of items
  * get_item_func :       [IN] <ICONTEXT /> Callback function of get menu
  *                       item
  * get_hint_func :       [IN] <HINT /> Callback function of get menu item
  *                       hint
  * highlighted_item :    [IN] <N/A /> Highlighted item index
  * search_image :        [IN] <N/A /> Seach image in input area
  * buffer :              [IN] <N/A /> Buffer
  * buffer_max_length :   [IN] <N/A /> Buffer max length
  * history_buffer :      [IN] <N/A /> Histpry buffer
  * Returns
  *  void
  * Example
  * <code>
  * void EntryScreen_200(void)
  * {
  *   U8 *guiBuffer = NULL;
  * 
  *   EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
  * 
  *   memset(g_buffer, NULL, MAX_LOCAL_BUFFER);
  * 
  *   RegisterCat200SearchFunction(cat200_callback);
  * 
  *   ShowCategory200Screen(
  *       STR_ID_CSB_CATEGORY_TEXT,
  *       NULL,
  *       STR_ID_CSB_LSK_TEXT,
  *       0,
  *       STR_ID_CSB_RSK_TEXT,
  *       0,
  *       4,
  *       Get_List_Items,
  *       NULL,
  *       0,
  *       NULL,
  *       (U8*) g_buffer,
  *       5,
  *       guiBuffer);
  * }
  * 
  * pBOOL Get_List_Items(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
  * {
  *   if (item_index &lt; 0)
  *   {
  *       return FALSE;
  *   }
  * 
  *   pfnUnicodeStrcpy((S8*) str_buff, (S8*) GetString(STR_ID_CSB_MENUITEM1_TEXT + (U16) item_index));
  *   \*img_buff_p = (U8*) GetImage(gIndexIconsImageList[item_index]);
  * 
  *   return TRUE;
  * }
  * </code>                                                                                           
  *****************************************************************************************************/
    extern void ShowCategory200Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    S32 number_of_items,
                    GetItemFuncPtr get_item_func,
                    GetHintFuncPtr get_hint_func,
                    S32 highlighted_item,
                    U16 search_image,
                    U8 *buffer,
                    S32 buffer_max_length,
                    U8 *history_buffer);

/* DOM-NOT_FOR_SDK-BEGIN */
/* Just for backward compatible with the existing category. */
extern void ShowCategory200Screen_int(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 right_softkey,
                S32 number_of_items,
                GetItemFuncPtr get_item_func,
                GetHintFuncPtr get_hint_func,
                S32 highlighted_item,
                U16 search_image,
                U8 *buffer,
                S32 buffer_max_length,
                U8 *history_buffer);

#define ShowCategory200Screen(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13) \
        ShowCategory200Screen_int(_arg0, _arg1, _arg2, _arg4, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13)
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************************************
  * FUNCTION
  *  ShowCategory200Screen_ext
  * Description
  * Show Category200 screen (phonebook quick search)
  *  [FTE]: support(tool bar is avaiable)
  * 
  * Parameters
  * title :               [IN] <TITLE /> Title id
  * title_icon :          [IN] <N/A /> Title icon
  * left_softkey :        [IN] <LSK /> Left soft key label
  * left_softkey_icon :   [IN] <N/A /> Left soft key icon
  * right_softkey :       [IN] <RSK /> Right soft key label
  * right_softkey_icon :  [IN] <N/A /> Right soft key icon
  * number_of_items :     [IN] <N/A /> Number of items
  * get_item_func :       [IN] <ICONTEXT /> Callback function of get menu
  *                       item
  * get_hint_func :       [IN] <HINT /> Callback function of get menu item
  *                       hint
  * highlighted_item :    [IN] <N/A /> Highlighted item index
  * search_image :        [IN] <N/A /> Seach image in input area
  *  left_icon            [IN] <N/A /> Menuitme left icon 
  *  right_icon           [IN] <N/A /> Menuitme right icon 
  * buffer :              [IN] <N/A /> Buffer
  * buffer_max_length :   [IN] <N/A /> Buffer max length
  * history_buffer :      [IN] <N/A /> Histpry buffer
  * Returns
  *  void                                                            
  *****************************************************************************************************/
extern void ShowCategory200Screen_ext(
            U16 title,
            U16 title_icon,
            U16 left_softkey,
            U16 left_softkey_icon,
            U16 right_softkey,
            U16 right_softkey_icon,
            S32 number_of_items,
            GetAsyncItemFuncPtr get_item_func,
            GetAsyncHintFuncPtr get_hint_func,
            S32 highlighted_item,
            U16 search_image,
            PU8 left_icon,
            PU8 right_icon,
            U8 *buffer,
            S32 buffer_max_length,
            U8 *history_buffer);

/* DOM-NOT_FOR_SDK-BEGIN */
/* Just for backward compatible with the existing category. */
extern void ShowCategory200Screen_ext_int(
            U16 title,
            U16 title_icon,
            U16 left_softkey,
            U16 right_softkey,
            S32 number_of_items,
            GetAsyncItemFuncPtr get_item_func,
            GetAsyncHintFuncPtr get_hint_func,
            S32 highlighted_item,
            U16 search_image,
            PU8 left_icon,
            PU8 right_icon,
            U8 *buffer,
            S32 buffer_max_length,
            U8 *history_buffer);

#define ShowCategory200Screen_ext(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15) \
        ShowCategory200Screen_ext_int(_arg0, _arg1, _arg2, _arg4, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15)
/* DOM-NOT_FOR_SDK-END */


/* DOM-NOT_FOR_SDK-BEGIN */                    
    extern void ExitCategory200Screen(void);
    extern U8 *GetCategory200History(U8 *history_buffer);
    extern S32 GetCategory200HistorySize(void);
    extern void RedrawCategory200Screen(void);
/* DOM-NOT_FOR_SDK-END */    

/*****************************************************************************
 * FUNCTION
 *  RegisterCat200SearchFunction
 * DESCRIPTION
 *  Register the search function, it will be invoked after editor content changed.
 * PARAMETERS
 *  search_function    : [IN]<N/A />       Function pointer
 * RETURNS
 *  void
 *****************************************************************************/
    extern void RegisterCat200SearchFunction(S32(*search_function) (U8 *));

/*****************************************************************************
 * FUNCTION
 *  wgui_cat199_register_get_attachment_icon_callback
 * DESCRIPTION
 *  Register search function (for APP)
 * PARAMETERS
 *  search_function     [IN]        Function pointer
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat199_register_get_attachment_icon_callback(PU8(*get_attachment_icon) (S32));

/*****************************************************************************
 * FUNCTION
 *  wgui_cat199_register_get_attachment_icon_filepath_callback
 * DESCRIPTION
 *  Register search function (for APP)
 * PARAMETERS
 *  search_function     [IN]        Function pointer
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat199_register_get_attachment_icon_filepath_callback(PU8(*get_attachment_icon_filepath) (S32));

/*****************************************************************************
 * FUNCTION
 *  wgui_cat199_register_get_attachment_icon_buffer_callback
 * DESCRIPTION
 *  Register search function (for APP)
 * PARAMETERS
 *  search_function     [IN]        Function pointer
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat199_register_get_attachment_icon_buffer_callback(gdi_image_cache_bmp_struct(*get_attachment_icon_buffer) (S32));

/*****************************************************************************
 * FUNCTION
 *  SetCategory200LeftSoftkeyFunction
 * DESCRIPTION
 *  Set left softkey function of category 200
 * PARAMETERS
 *  f              : [IN] <N/A />        Function pointer
 *  k              : [IN] <N/A />       Event type
 * RETURNS
 *  void
 *****************************************************************************/
    extern void SetCategory200LeftSoftkeyFunction(void (*f) (void), MMI_key_event_type k);

/*****************************************************************************
 * FUNCTION
 *  SetCategory200RightSoftkeyFunction
 * DESCRIPTION
 *  Set right soft key function of category 200
 * PARAMETERS
 *  f              : [IN] <N/A />       Function pointer
 *  k              : [IN] <N/A />       Event type
 * RETURNS
 *  void
 *****************************************************************************/    
    extern void SetCategory200RightSoftkeyFunction(void (*f) (void), MMI_key_event_type k);
    /* DOM-NOT_FOR_SDK-BEGIN */ 
    #define SetCategory200RightSoftkeyFunction(_arg0, _arg1) wgui_inputs_category_set_rsk_func(_arg0)
    /* DOM-NOT_FOR_SDK-END */

    extern void wgui_cat200_set_specific_highlight(void);

/* DOM-NOT_FOR_SDK-BEGIN */
#if defined(__MMI_MAINLCD_128X160__)
    #define CAT202_SCROLL_HEIGHT (MMI_SINGLELINE_INPUTBOX_HEIGHT - 4)
#else
    #define CAT202_SCROLL_HEIGHT MMI_SINGLELINE_INPUTBOX_HEIGHT
#endif

#if defined(__MMI_MAINLCD_240X320__) && defined(__MMI_FTE_SUPPORT__)
    #define CAT202_SCROLL_Y (MMI_COMMON_CONTENT_Y)
#elif defined(__MMI_MAINLCD_320X240__) && defined(__MMI_FTE_SUPPORT__)
    #define CAT202_SCROLL_Y (MMI_COMMON_CONTENT_Y)
#else
#if !defined(GUI_EDITOR_SHOW_TITLE)
    #define CAT202_SCROLL_Y (0)
#else
    #define CAT202_SCROLL_Y (MMI_COMMON_CONTENT_Y)
#endif
#endif /* __MMI_FTE_SUPPORT__ */


extern void RedrawCategoryControlledArea202Screen(dm_coordinates *coordinate);
extern void cat202_virtual_keypad_callback(void);
extern void ExitCategory202Screen(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * <GROUP EDITOR>
 * FUNCTION
 *  ShowCategory202Screen
 * DESCRIPTION
 *  category screen of phone search and Multi Select
 *  [FTE]: support(tool bar is avaiable)
 * 
 * <img name="wgui_cat202_img1" />
 * PARAMETERS
 *   title                         : [IN ] <TITLE /> Title id
 *   title_icon                    : [IN ] <N/A /> Title icon
 *   left_softkey                  : [IN ] <LSK /> Left soft key label
 *   left_softkey_icon             : [IN ] <N/A /> Left soft key icon
 *   right_softkey                 : [IN ] <RSK /> Right soft key label
 *   right_softkey_icon            : [IN ] <N/A /> Right soft key icon
 *   number_of_items               : [IN ] <N/A /> Number of items
 *   get_item_func                 : [IN ] <TWOSTATE /> Get item function pointer
 *   get_hint_func                 : [IN ] <N/A /> Get hint function pointer
 *   highlighted_item              : [IN ] <N/A /> Highlighted item index
 *   search_image                  : [IN ] <N/A /> Seach image
 *   buffer                        : [IN ] <UNLIM /> buffer of input box
 *   buffer_max_length             : [IN ] <N/A /> size of buffer
 *   history_buffer                : [IN ] <N/A /> Histpry buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_202(void)
 * {
 *     U8 *guiBuffer = NULL;
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     memset(g_buffer, 0, MAX_LOCAL_BUFFER);
 * 
 *     RegisterCat200SearchFunction(cat200_callback);
 * 
 *     ShowCategory202Screen(
 *         STR_ID_CSB_CATEGORY_TEXT,
 *         0,
 *         STR_ID_CSB_LSK_TEXT,
 *         0,
 *         STR_ID_CSB_RSK_TEXT,
 *         0,
 *         (U8*) L"Hint description. This area is dynamically allocated.",
 *         4,
 *         Get_List_Items,
 *         get_hint_list,
 *         cat384_checkbox_get_image_callback,
 *         cat384_checkbox_clicked_callback,
 *         0,
 *         0,
 *         (U8*) g_buffer,
 *         CSB_MAX_BUFFER_LEN,
 *         guiBuffer);
 * 
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory202Screen(
                           U16 title,
                           U16 title_icon,
                           U16 left_softkey,
                           U16 left_softkey_icon,
                           U16 right_softkey,
                           U16 right_softkey_icon,
                           U8* info_message,
                           S32 number_of_items,
                           GetItemFuncPtr get_item_func,
                           GetHintFuncPtr get_hint_func,
                           checkbox_get_image_funcptr_type get_state_func,
                           checkbox_clicked_funcptr_type set_state_func,        
                           S32 highlighted_item,
                           U16 search_image,
                           U8 *buffer,
                           S32 buffer_max_length,
                           U8 *history_buffer);

/* DOM-NOT_FOR_SDK-BEGIN */
/* Just for backward compatible with the existing category. */
extern void ShowCategory202Screen_int(
                           U16 title,
                           U16 title_icon,
                           U16 left_softkey,
                           U16 right_softkey,
                           U8* info_message,
                           S32 number_of_items,
                           GetItemFuncPtr get_item_func,
                           GetHintFuncPtr get_hint_func,
                           checkbox_get_image_funcptr_type get_state_func,
                           checkbox_clicked_funcptr_type set_state_func,        
                           S32 highlighted_item,
                           U16 search_image,
                           U8 *buffer,
                           S32 buffer_max_length,
                           U8 *history_buffer);


#define ShowCategory202Screen(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16) \
        ShowCategory202Screen_int(_arg0, _arg1, _arg2, _arg4, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16)
/* DOM-NOT_FOR_SDK-END */



/*****************************************************************************
 * FUNCTION
 *  ShowCategory202Screen_ext
 * DESCRIPTION
 *  category screen of phone search and Multi Select
 *  [FTE]: support(tool bar is avaiable)
 *
 * PARAMETERS
 *  title                   [IN]        Title id
 *  title_icon              [IN]        Title icon
 *  left_softkey            [IN]        Left soft key label
 *  left_softkey_icon       [IN]        Left soft key icon
 *  right_softkey           [IN]        Right soft key label
 *  right_softkey_icon      [IN]        Right soft key icon
 *  number_of_items         [IN]        Number of items
 *  get_item_func           [IN]        
 *  get_hint_func           [IN]        
 *  highlighted_item        [IN]        Highlighted item index
 *  search_image            [IN]        Seach image 
 *  left_icon               [IN]        Menuitme left icon 
 *  right_icon              [IN]        Menuitme right icon 
 *  buffer                  [IN]        Buffer
 *  buffer_max_length       [IN]        
 *  history_buffer          [IN]        Histpry buffer
 * RETURNS
 *  void
 *****************************************************************************/
extern void ShowCategory202Screen_ext(
            U16 title,
            U16 title_icon,
            U16 left_softkey,
            U16 left_softkey_icon,
            U16 right_softkey,
            U16 right_softkey_icon,
            U8* info_message,
            S32 number_of_items,
            GetAsyncItemFuncPtr get_item_func,
            GetAsyncHintFuncPtr get_hint_func,
            checkbox_get_image_funcptr_type get_state_func,
            checkbox_clicked_funcptr_type set_state_func,        
            S32 highlighted_item,
            U16 search_image,
            PU8 left_icon,
            PU8 right_icon,
            U8 *buffer,
            S32 buffer_max_length,
            U8 *history_buffer);

/* DOM-NOT_FOR_SDK-BEGIN */
/* Just for backward compatible with the existing category. */
extern void ShowCategory202Screen_ext_int(
            U16 title,
            U16 title_icon,
            U16 left_softkey,
            U16 right_softkey,
            U8* info_message,
            S32 number_of_items,
            GetAsyncItemFuncPtr get_item_func,
            GetAsyncHintFuncPtr get_hint_func,
            checkbox_get_image_funcptr_type get_state_func,
            checkbox_clicked_funcptr_type set_state_func,        
            S32 highlighted_item,
            U16 search_image,
            PU8 left_icon,
            PU8 right_icon,
            U8 *buffer,
            S32 buffer_max_length,
            U8 *history_buffer);

#define ShowCategory202Screen_ext(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18) \
        ShowCategory202Screen_ext_int(_arg0, _arg1, _arg2, _arg4, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17, _arg18)
/* DOM-NOT_FOR_SDK-END */


/* DOM-NOT_FOR_SDK-BEGIN */
#ifdef __MMI_TOUCH_SCREEN__
#if defined(__MMI_MAINLCD_320X480__)
    #define CAT201_EDITOR_HEIGHT (77)
#else
    #define CAT201_EDITOR_HEIGHT (MMI_SINGLELINE_INPUTBOX_HEIGHT * 3)
#endif /* defined(__MMI_MAINLCD_320X480__) */
#else /* __MMI_TOUCH_SCREEN__ */
    #if defined(__MMI_CSTAR__)
    #define CAT201_EDITOR_HEIGHT (MMI_SINGLELINE_INPUTBOX_HEIGHT * 4 + 1)
    #else
    #define CAT201_EDITOR_HEIGHT (MMI_SINGLELINE_INPUTBOX_HEIGHT * 3 + 3)
    #endif /* defined(__MMI_CSTAR__) */
#endif /* __MMI_TOUCH_SCREEN__ */
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************************************
  * FUNCTION
  *  ShowCategory201Screen
  * Description
  * category screen of search
  * 
  * <img name="wgui_cat201_img1" />
  * Parameters
  * title :                    [IN] <TITLE /> Title id
  * title_icon :               [IN] <N/A /> Title icon
  * left_softkey :             [IN] <LSK /> Left soft key label
  * left_softkey_icon :        [IN] <N/A /> Left soft key icon
  * right_softkey :            [IN] <RSK /> Right soft key label
  * right_softkey_icon :       [IN] <N/A /> Right soft key icon
  * number_of_items :          [IN] <N/A /> Number of items
  * get_item_func :            [IN] <ICONTEXT /> Function to get item
  * get_hint_func :            [IN] <HINT /> Function to get hint
  * highlighted_item :         [IN] <N/A /> Highlighted item index
  * search_image :             [IN] <N/A /> Seach image
  * buffer :                   [IN] <N/A /> Buffer
  * buffer_max_length :        [IN] <N/A /> Length
  * input_type :               [IN] <N/A /> Input type
  * history_buffer :           [IN] <N/A /> Histpry buffer
  * required_input_mode_set :  [IN] <N/A /> Input mode set
  * Returns
  *  void
  * Example
  * <code>
  * void EntryScreen_201(void)
  * {
  *   U8 *guiBuffer = NULL;
  * 
  *   EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
  * 
  *   RegisterCat200SearchFunction(cat200_callback);
  * 
  *   memset(g_buffer, NULL, MAX_LOCAL_BUFFER);
  * 
  *   g_dictionary_input_mode_CSB = g_dictionary_input_mode_Chinese_set_CSB;
  * 
  *   ShowCategory201Screen(
  *       STR_ID_CSB_CATEGORY_TEXT,
  *       NULL,
  *       STR_ID_CSB_LSK_TEXT,
  *       0,
  *       STR_ID_CSB_RSK_TEXT,
  *       0,
  *       4,
  *       Get_List_Items,
  *       NULL,
  *       0,
  *       IMG_PROFILES_OUTDOOR,
  *       (U8*) g_buffer,
  *       5 ,
  *       INPUT_TYPE_ALPHANUMERIC_UPPERCASE,
  *       guiBuffer,
  *       g_dictionary_input_mode_CSB);
  * 
  *   SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_DOWN);
  *   SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_UP);
  * 
  * }
  * 
  * pBOOL Get_List_Items(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
  * {
  *   if (item_index &lt; 0)
  *   {
  *       return FALSE;
  *   }
  * 
  *   pfnUnicodeStrcpy((S8*) str_buff, (S8*) GetString(STR_ID_CSB_MENUITEM1_TEXT + (U16) item_index));
  *   \*img_buff_p = (U8*) GetImage(gIndexIconsImageList[item_index]);
  * 
  *   return TRUE;
  * }
  * </code>                                                                                           
  *****************************************************************************************************/
    extern void ShowCategory201Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    S32 number_of_items,
                    GetItemFuncPtr get_item_func,
                    GetHintFuncPtr get_hint_func,
                    S32 highlighted_item,
                    U16 search_image,
                    U8 *buffer,
                    S32 buffer_max_length,
                    U32 input_type,
                    U8 *history_buffer,
                    mmi_imm_input_mode_enum * required_input_mode_set);

/* DOM-NOT_FOR_SDK-BEGIN */
/* Just for backward compatible with the existing category. */
extern void ShowCategory201Screen_int(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 right_softkey,
                S32 number_of_items,
                GetItemFuncPtr get_item_func,
                GetHintFuncPtr get_hint_func,
                S32 highlighted_item,
                U16 search_image,
                U8 *buffer,
                S32 buffer_max_length,
                U32 input_type,
                U8 *history_buffer,
                mmi_imm_input_mode_enum * required_input_mode_set);

#define ShowCategory201Screen(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15) \
        ShowCategory201Screen_int(_arg0, _arg1, _arg2, _arg4, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15)
/* DOM-NOT_FOR_SDK-END */


/* DOM-NOT_FOR_SDK-BEGIN */                    
    extern void wgui_cat201_redraw_controlled_area(void);
    extern void wgui_cat201_register_key_handler(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  wgui_cat201_register_language_changed_indicator
 * DESCRIPTION
 *  register language changed indicator of category 201
 * PARAMETERS
 *  FuncPtr    : [IN] <N/A />        Function to register
 * RETURNS
 *  void
 *****************************************************************************/    
    extern void wgui_cat201_register_language_changed_indicator(BOOL(*FuncPtr) (U8));

/*****************************************************************************
 * FUNCTION
 *  wgui_cat201_set_right_softkey_function
 * DESCRIPTION
 *  set right softkey callback of multiline inputbox in category 201
 * PARAMETERS
 *  f      : [IN] <N/A />       Function pointer
 *  k      : [IN] <N/A />       Type of key event
 * RETURNS
 *  void
 *****************************************************************************/
    extern void wgui_cat201_set_right_softkey_function(void (*f) (void), MMI_key_event_type k);    
/* DOM-NOT_FOR_SDK-BEGIN */ 
    #define wgui_cat201_set_right_softkey_function(_arg0, _arg1) wgui_inputs_category_set_rsk_func(_arg0)
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  Register_appl_present_function
 * DESCRIPTION
 *  Register application present function
 * PARAMETERS
 *  application_present_function       : [IN] <N/A />        Function pointer
 * RETURNS
 *  void
 *****************************************************************************/    
    extern void Register_appl_present_function(BOOL(*application_present_function) (S32 *));

/*****************************************************************************
 * FUNCTION
 *  wgui_cat_set_search_icon
 * DESCRIPTION
 *  set the search icon.
 * PARAMETERS
 *  search_image   [IN]   search image ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat_set_search_icon(U16 search_image);

#if defined(__MMI_PHB_PHOTO_STICKER_SUPPORT__) || \
    defined(__SOCIAL_NETWORK_SUPPORT__) || \
     defined(__MMI_SNS_CONTACTS__) || \
	 defined(__MMI_MOT_SUPPORT__) || \
	 defined(__MMI_MRE_MSPACE__) || \
	 defined(__MMI_NSS_SUPPORT__) || \
	 defined(__VCARD_CLOUD_SUPPORT__) || \
	 defined(__MMI_SSO__)
	
    #define __MMI_PHONEBOOK_LIST_THUMBNAIL__
#endif

#ifdef __MMI_PHONEBOOK_LIST_THUMBNAIL__
typedef void (*wgui_thumbnail_set_displayable_func)(S32 index, MMI_BOOL displayable);
typedef MMI_BOOL (*wgui_thumbnail_get_displayable_func)(S32 item_idx);
typedef MMI_BOOL (*wgui_thumbnail_get_image_func)(S32 item_idx, CHAR *file_path);
typedef U16 (*wgui_thumbnail_get_store_id_func)(S32 item_idx);
typedef void (*wgui_thumbnail_imgdec_done_callback_func)(S32 item_idx);

typedef enum
{
    WGUI_THUMBNAIL_IMG_SRC_TYPE_FILE,
    WGUI_THUMBNAIL_IMG_SRC_TYPE_RESOURCE,
    WGUI_THUMBNAIL_IMG_SRC_TYPE_RESOURCE_WITHOUT_HEADER,
    WGUI_THUMBNAIL_IMG_SRC_TYPE_MEMORY,
    WGUI_THUMBNAIL_IMG_SRC_TYPE_TOTAL
}wgui_thumbnail_img_src_enum;

typedef struct
{
    S32 img_size;
    U8* img_ptr;
    wgui_thumbnail_imgdec_done_callback_func done_callback;
    wgui_thumbnail_img_src_enum img_src;
    U8 img_type;
}wgui_thumbnail_img_info_struct;
typedef struct
{
    PU8 file_icon_ptr;                          /* Default image pointer */
    MMI_BOOL is_show_thumb;                     /* If show this image as a thumb image */
} wgui_thumbnail_info_struct;
typedef void (*wgui_thumbnail_get_info_func)(S32 item_idx, wgui_thumbnail_info_struct *info_data);
typedef MMI_BOOL (*wgui_thumbnail_get_image_func_ex)(S32 item_idx, wgui_thumbnail_img_info_struct* img_info);

/********************************************************
 *  the below thumbnail functions are used by phonebook list
 *  only valid in cat200_ext, cat202_ext, cat199_ext, cat1034
 ********************************************************/
extern void wgui_thumbnail_register_get_displayable_func(wgui_thumbnail_get_displayable_func get_displayable_func);
extern void wgui_thumbnail_register_set_displayable_func(wgui_thumbnail_set_displayable_func set_displayable_func);
extern void wgui_thumbnail_register_get_image_path_func(wgui_thumbnail_get_image_func get_image_path_func);
extern void wgui_thumbnail_register_get_image_info_func(wgui_thumbnail_get_info_func get_info_func);
extern void wgui_thumbnail_register_get_store_id_func(wgui_thumbnail_get_store_id_func get_store_id_func);
extern void wgui_thumbnail_register_get_image_func(wgui_thumbnail_get_image_func_ex get_image_mem_func);

/********************************************************
 *  the below thumbnail function is used by cat1032
 *  share thumbnail init/post_init/denint/highlight function
 ********************************************************/
extern void wgui_cat_thumbnail_post_display_callback(void *item, void *common_item_data, S32 x, S32 y);

extern void wgui_cat_thumbnail_init(S32 number);
extern void wgui_cat_thumbnail_post_init(S32 num_of_items);
extern void wgui_cat_thumbnail_deninit(void);

extern void wgui_cat_thumbnail_set_is_show(S32 index);
extern void wgui_cat_thumbnail_set_image_box_size(S32 width, S32 height);
#endif /* __MMI_PHONEBOOK_LIST_THUMBNAIL__ */

#if defined(__SOCIAL_NETWORK_SUPPORT__) 
extern S32 get_cat202_scroll_height(void);
extern S32 get_cat199_inputbox_h(void);
extern S32 get_cat199_margin_width(void);
#endif
#endif /* __WGUI_CATEGORIES_SEARCH_H__ */ 


