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
 *  wgui_categories_idlescreen_op.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Operator idle screen related categories.
 *
 *  Author:
 * -------
 *  Kaiwei Jiang (MTK80131)
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __WGUI_CATEGORIES_IDLESCREEN_OP_H__
#define __WGUI_CATEGORIES_IDLESCREEN_OP_H__

#include "MMI_features.h"
#include "wgui.h"
#include "gui_typedef.h"

#if defined(__MMI_OP11_CAT433_SUPPORT__)
#define SCRMEM_CAT433_POOL_SIZE ((GDI_LCD_WIDTH * GDI_LCD_HEIGHT * GDI_MAINLCD_BIT_PER_PIXEL + 7) >> 3)
#endif /* __MMI_OP11_CAT433_SUPPORT__ */

#ifdef __MMI_OP12_CAT533_SUPPORT__
#include "wgui_toolbar.h"
#endif /* __MMI_OP12_CAT533_SUPPORT__ */

#include "gdi_lcd_config.h"
#include "gdi_include.h"
#include "Gui_Setting.h"
#include "MMIDataType.h"
#include "gui_data_types.h"
#include "gui_side_bar.h"
#include "wgui_categories_list.h"
#include "kal_general_types.h"

#ifdef __MMI_OP11_CAT433_SUPPORT__
#define WGUI_CAT433_STRING_V_GAP                1
#define WGUI_CAT433_STRING_H_GAP                1
#if defined(__MMI_MAINLCD_240X320__)
    #define WGUI_CAT433_STRING_MAX_OPNAME_W     110
    #define WGUI_CAT433_BAR_MAX_WIDTH           34
    #define WGUI_CAT433_STRING_OFFSET_Y         6
#elif defined(__MMI_MAINLCD_176X220__)
    #define WGUI_CAT433_STRING_MAX_OPNAME_W     80
    #define WGUI_CAT433_BAR_MAX_WIDTH           31
    #define WGUI_CAT433_STRING_OFFSET_Y         8
#else
    #error "The resolution is currently not supported."
#endif

#define WGUI_CAT433_STRING_HEIGHT       (Get_CharDisplayHeightOfAllLangAndType(MMI_medium_font.size) + 2 /* gap */)
#define WGUI_CAT433_STRING_LOCALTIME_Y  (MMI_STATUS_BAR_HEIGHT + WGUI_CAT433_STRING_V_GAP + WGUI_CAT433_STRING_OFFSET_Y) 
#define WGUI_CAT433_STRING_LOCALDATE_Y  (MMI_STATUS_BAR_HEIGHT + WGUI_CAT433_STRING_V_GAP + WGUI_CAT433_STRING_OFFSET_Y + (WGUI_CAT433_STRING_HEIGHT) * 1)
#define WGUI_CAT433_STRING_OPNAME_Y     (MMI_STATUS_BAR_HEIGHT + WGUI_CAT433_STRING_V_GAP + WGUI_CAT433_STRING_OFFSET_Y + (WGUI_CAT433_STRING_HEIGHT) * 2)
#define WGUI_CAT433_STRING_CITYNAME_Y   (MMI_STATUS_BAR_HEIGHT + WGUI_CAT433_STRING_V_GAP + WGUI_CAT433_STRING_OFFSET_Y + (WGUI_CAT433_STRING_HEIGHT) * 3 + WGUI_CAT433_STRING_V_GAP)
#define WGUI_CAT433_STRING_DUALDAY_Y    (MMI_STATUS_BAR_HEIGHT + WGUI_CAT433_STRING_V_GAP + WGUI_CAT433_STRING_OFFSET_Y + (WGUI_CAT433_STRING_HEIGHT) * 4 + WGUI_CAT433_STRING_V_GAP)
#define WGUI_CAT433_STRING_DUALTIME_Y   (MMI_STATUS_BAR_HEIGHT + WGUI_CAT433_STRING_V_GAP + WGUI_CAT433_STRING_OFFSET_Y + (WGUI_CAT433_STRING_HEIGHT) * 5 + WGUI_CAT433_STRING_V_GAP)
#define WGUI_CAT433_STRING_EXTRA_Y   (MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - (WGUI_CAT433_STRING_HEIGHT + WGUI_CAT433_STRING_V_GAP) * 2)

#define WGUI_CAT433_DISPLAY_DUAL_CLOCK  0x00000001
#define WGUI_CAT433_DISPLAY_ALARM       0x00000002

#define wgui_cat433_get_popup_menu_layout_info  wgui_side_bar_get_popout_menu_layout
#define wgui_cat433_update_popup_menu           wgui_side_bar_update_popout_menu
#define wgui_cat433_update_indicator            wgui_cat433_update_indicators
#define wgui_cat433_update_op_name              wgui_cat433_update_details
#define wgui_cat433_reset_sidebar               wgui_side_bar_reset_to_inactive

extern void wgui_cat433_update_indicators(S32 index);
extern void wgui_cat433_update_details(void);


/**************************************************************
  * FUNCTION
  *  ShowCategory433Screen
  * Description
  *  Sidebar category homescreen
  * 
  * <img name="wgui_cat433_img1" />
  * PARAMETERS
  *  left_softkey                  : [IN ] (LSK) Left softkey label
  *  left_softkey_icon             : [IN ] (N/A) Icon for the Left softkey
  *  right_softkey                 : [IN ] (RSK) Right softkey label
  *  right_softkey_icon            : [IN ] (N/A) Icon for the right softkey
  *  number_of_items               : [IN ] (N/A) Number of side bar menu items
  *  normal_side_bar_icons         : [IN ] (N/A) normal icons of side bar menu items
  *  highlighted_side_bar_icons    : [IN ] (N/A) Highlighted icons of side bar menu items
  *  get_menu_cb                   : [IN ] (N/A) Get pop-out menu item callback
  *  get_indicator_cb              : [IN ] (N/A) Get indicator callback
  *  get_highlight_cb              : [IN ] (N/A) Get pop-out menu item highlight callback
  *  sidebar_highlight_cb          : [IN ] (N/A) Highlight side bar menu item callback
  *  left_arrow_down_handler       : [IN ] (N/A) Pre-defined left arrow handler
  *  right_arrow_down_handler      : [IN ] (N/A) Pre-defined right arrow handler
  *  options                       : [IN ] (N/A) Flags(display alarm/dual clock or not)
  *  history_buffer                : [IN ] (N/A) History buffer
  * Returns
  *  void                                                   
  **************************************************************/
extern void ShowCategory433Screen(
        UI_string_type left_softkey,
        PU8 left_softkey_icon,
        UI_string_type right_softkey,
        PU8 right_softkey_icon,
        S32 number_of_items,
        PU8* normal_side_bar_icons,
        PU8* highlighted_side_bar_icons,
        wgui_sidebar_getmenudata_funcptr_type *get_menu_cb,
        wgui_sidebar_getindicator_funcptr_type *get_indicator_cb,
        wgui_sidebar_popout_menu_highlighthandler_funcptr_type *get_highlight_cb,
        wgui_sidebar_popout_side_bar_highlighthandler_funcptr_type sidebar_highlight_cb,
        FuncPtr left_arrow_down_handler,
        FuncPtr right_arrow_down_handler,
        S32 options,
        U8* history_buffer);
#endif /* __MMI_OP11_CAT433_SUPPORT__ */


#ifdef __MMI_OP12_CAT533_SUPPORT__
#define SCRMEM_CAT533_POOL_SIZE ((GDI_LCD_WIDTH * GDI_LCD_HEIGHT * GDI_MAINLCD_BIT_PER_PIXEL + 7) >> 3)

#define wgui_cat533_change_toolbar_icon wgui_toolbar_change_bar_icon
#define wgui_cat533_update_popout_menu wgui_toolbar_update_popout_menu
#define wgui_cat533_update_song_name wgui_cat533_update_details
#define wgui_cat533_update_network_name wgui_cat533_update_details
#define wgui_cat533_change_menu_highlight wgui_toolbar_change_popout_menu_highlight

extern void wgui_cat533_pause_wallpaper(void);
extern void wgui_cat533_resume_wallpaper(void);
extern void wgui_cat533_set_popout_menu_state(S32 index, mmi_gui_toolbar_popout_menu_state_enum state);
extern void wgui_cat533_set_toolbar_state(mmi_gui_toolbar_state_enum state);
extern void wgui_cat533_update_details(void);
extern wgui_toolbar_history_struct* wgui_cat533_get_toolbar_history(U8* buffer);


/**************************************************************
  * FUNCTION
  *  ShowCategory533Screen
  * Description
  *  Toolbar category homescreen
  * 
  * <img name="wgui_cat533_img1" />
  * PARAMETERS
  *  left_softkey                      : [IN ] (LSK) Left softkey label
  *  left_softkey_icon                 : [IN ] (N/A) Icon for the Left softkey
  *  right_softkey                     : [IN ] (RSK) Right softkey label
  *  right_softkey_icon                : [IN ] (N/A) Icon for the right softkey
  *  number_of_toolbar_menu            : [IN ] (N/A) number of toolbar menu
  *  icons_of_toolbar_menu_normal      : [IN ] (N/A) icon of toolbar menu icon in normal state
  *  icons_of_toolbar_menu_highlight   : [IN ] (N/A) icon of toolbar menu icon in highlight state
  *  icons_of_toolbar_menu_state       : [IN ] (N/A) toolbar menu state
  *  get_menu_data_callback            : [IN ] (N/A) get menu data callback function
  *  menu_highlight_handler            : [IN ] (N/A) menu highlight handler
  *  history_buffer                    : [IN ] (N/A) History buffer
  * Returns
  *  void                                                   
  **************************************************************/
extern void ShowCategory533Screen(
            UI_string_type left_softkey,
            PU8 left_softkey_icon,
            UI_string_type right_softkey,
            PU8 right_softkey_icon,
            S32 number_of_toolbar_menu,
            PU8* icons_of_toolbar_menu_normal,
            PU8* icons_of_toolbar_menu_highlight,
            mmi_gui_toolbar_popout_menu_state_enum* icons_of_toolbar_menu_state,
            wgui_toolbar_getmenudata_funcptr_type *get_menu_data_callback,
            wgui_toolbar_popout_menu_highlighthandler_funcptr_type *menu_highlight_handler,
            U8* history_buffer);
extern void ExitCategory533Screen(void);
extern S32 wgui_cat533_get_history_size(void);
extern U8* wgui_cat533_get_history(U8* buffer);
#endif /* __MMI_OP12_CAT533_SUPPORT__ */

#ifdef __MMI_CAT203_SUPPORT__
#ifdef __MMI_FTE_SUPPORT__
#define CAT203_DELETE_ALL_TIMER                 (600)
#define CAT203_VK_DEFAULE_H                     (50)
#if defined(__MMI_MAINLCD_240X320__)
    #define CAT203_CONTENT_X                     (0)
    #define CAT203_CONTENT_Y                     (MMI_STATUS_BAR_HEIGHT)
    #define CAT203_CONTENT_W                     (MAIN_LCD_DEVICE_WIDTH)
    #define CAT203_CONTENT_H                     (MAIN_LCD_DEVICE_HEIGHT - MMI_STATUS_BAR_HEIGHT - MMI_BUTTON_BAR_HEIGHT)

    #define CAT203_DYNAMIC_LIST_X                (CAT203_CONTENT_X)
    #define CAT203_DYNAMIC_LIST_Y                (CAT203_CONTENT_Y)
    #define CAT203_DYNAMIC_LIST_W                (CAT203_CONTENT_W)
#if defined(__MMI_TOUCH_SCREEN__)
    #define CAT203_DYNAMIC_LIST_H                (MAIN_LCD_DEVICE_HEIGHT - CAT203_CONTENT_Y - MMI_SINGLELINE_INPUTBOX_HEIGHT - 2)
    #define CAT203_SL_INPUTBOX_W                (149)
#else
    #define CAT203_DYNAMIC_LIST_H                (MAIN_LCD_DEVICE_HEIGHT - CAT203_CONTENT_Y - MMI_SINGLELINE_INPUTBOX_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 5)
    #define CAT203_SL_INPUTBOX_W                (228)
#endif
    #define CAT203_SL_INPUTBOX_X                (6)
    #define CAT203_SL_INPUTBOX_Y                (CAT203_DYNAMIC_LIST_Y + CAT203_DYNAMIC_LIST_H + 3)
    #define CAT203_SL_INPUTBOX_H                (MMI_SINGLELINE_INPUTBOX_HEIGHT)

    #define CAT203_BACKSPACE_X                  (161)
    #define CAT203_BACKSPACE_Y_BASED_ON_SL      (1)
    #define CAT203_BACKSPACE_W                  (73)
    #define CAT203_BACKSPACE_H                  ((CAT203_BACKSPACE_Y_BASED_ON_SL << 1) + CAT203_SL_INPUTBOX_H)
    
#elif defined(__MMI_MAINLCD_240X400__)
    #define CAT203_CONTENT_X                     (0)
    #define CAT203_CONTENT_Y                     (MMI_STATUS_BAR_HEIGHT)
    #define CAT203_CONTENT_W                     (MAIN_LCD_DEVICE_WIDTH)
    #define CAT203_CONTENT_H                     (MAIN_LCD_DEVICE_HEIGHT - MMI_STATUS_BAR_HEIGHT - MMI_BUTTON_BAR_HEIGHT)

    #define CAT203_DYNAMIC_LIST_X                (CAT203_CONTENT_X)
    #define CAT203_DYNAMIC_LIST_Y                (CAT203_CONTENT_Y)
    #define CAT203_DYNAMIC_LIST_W                (CAT203_CONTENT_W)
#if defined(__MMI_TOUCH_SCREEN__)
    #define CAT203_DYNAMIC_LIST_H                (MAIN_LCD_DEVICE_HEIGHT - CAT203_CONTENT_Y - MMI_SINGLELINE_INPUTBOX_HEIGHT - 2)
    #define CAT203_SL_INPUTBOX_W                (152)
#else
    #define CAT203_DYNAMIC_LIST_H                (MAIN_LCD_DEVICE_HEIGHT - CAT203_CONTENT_Y - MMI_SINGLELINE_INPUTBOX_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 5)
    #define CAT203_SL_INPUTBOX_W                (228)
#endif
    #define CAT203_SL_INPUTBOX_X                (6)
    #define CAT203_SL_INPUTBOX_Y                (CAT203_DYNAMIC_LIST_Y + CAT203_DYNAMIC_LIST_H + 6)
    #define CAT203_SL_INPUTBOX_H                (MMI_SINGLELINE_INPUTBOX_HEIGHT)

    #define CAT203_BACKSPACE_X                  (160)
    #define CAT203_BACKSPACE_Y_BASED_ON_SL  (1)
    #define CAT203_BACKSPACE_W                  (74)
    #define CAT203_BACKSPACE_H                  ((CAT203_BACKSPACE_Y_BASED_ON_SL << 1) + CAT203_SL_INPUTBOX_H)
#elif defined(__MMI_MAINLCD_320X480__)
    #define CAT203_CONTENT_X                     (0)
    #define CAT203_CONTENT_Y                     (MMI_STATUS_BAR_HEIGHT)
    #define CAT203_CONTENT_W                     (MAIN_LCD_DEVICE_WIDTH)
    #define CAT203_CONTENT_H                     (MAIN_LCD_DEVICE_HEIGHT - MMI_STATUS_BAR_HEIGHT - MMI_BUTTON_BAR_HEIGHT)

    #define CAT203_DYNAMIC_LIST_X                (CAT203_CONTENT_X)
    #define CAT203_DYNAMIC_LIST_Y                (CAT203_CONTENT_Y)
    #define CAT203_DYNAMIC_LIST_W                (CAT203_CONTENT_W)
#if defined(__MMI_TOUCH_SCREEN__)
    #define CAT203_DYNAMIC_LIST_H                (MAIN_LCD_DEVICE_HEIGHT - CAT203_CONTENT_Y - MMI_SINGLELINE_INPUTBOX_HEIGHT - 2)
    #define CAT203_SL_INPUTBOX_W                (193)
#else
    #define CAT203_DYNAMIC_LIST_H                (MAIN_LCD_DEVICE_HEIGHT - CAT203_CONTENT_Y - MMI_SINGLELINE_INPUTBOX_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 10)
    #define CAT203_SL_INPUTBOX_W                (300)
#endif
    #define CAT203_SL_INPUTBOX_X                (10)
    #define CAT203_SL_INPUTBOX_Y                (CAT203_DYNAMIC_LIST_Y + CAT203_DYNAMIC_LIST_H + 4)
    #define CAT203_SL_INPUTBOX_H                (MMI_SINGLELINE_INPUTBOX_HEIGHT)

    #define CAT203_BACKSPACE_X                  (213)
    #define CAT203_BACKSPACE_Y_BASED_ON_SL  (1)
    #define CAT203_BACKSPACE_W                  (97)
    #define CAT203_BACKSPACE_H                  ((CAT203_BACKSPACE_Y_BASED_ON_SL << 1) + CAT203_SL_INPUTBOX_H)
#else
    #define CAT203_CONTENT_X                     (0)
    #define CAT203_CONTENT_Y                     (MMI_STATUS_BAR_HEIGHT)
    #define CAT203_CONTENT_W                     (MAIN_LCD_DEVICE_WIDTH)
    #define CAT203_CONTENT_H                     (MAIN_LCD_DEVICE_HEIGHT - MMI_STATUS_BAR_HEIGHT - MMI_BUTTON_BAR_HEIGHT)

    #define CAT203_DYNAMIC_LIST_X                (CAT203_CONTENT_X)
    #define CAT203_DYNAMIC_LIST_Y                (CAT203_CONTENT_Y)
    #define CAT203_DYNAMIC_LIST_W                (CAT203_CONTENT_W)
#if defined(__MMI_TOUCH_SCREEN__)
    #define CAT203_DYNAMIC_LIST_H                (MAIN_LCD_DEVICE_HEIGHT - CAT203_CONTENT_Y - MMI_SINGLELINE_INPUTBOX_HEIGHT - 2)
    #define CAT203_SL_INPUTBOX_W                (193)
#else
    #define CAT203_DYNAMIC_LIST_H                (MAIN_LCD_DEVICE_HEIGHT - CAT203_CONTENT_Y - MMI_SINGLELINE_INPUTBOX_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 5)
    #define CAT203_SL_INPUTBOX_W                (300)
#endif

    #define CAT203_SL_INPUTBOX_X                (10)
    #define CAT203_SL_INPUTBOX_Y                (CAT203_DYNAMIC_LIST_Y + CAT203_DYNAMIC_LIST_H + 4)
    #define CAT203_SL_INPUTBOX_H                (MMI_SINGLELINE_INPUTBOX_HEIGHT)

    #define CAT203_BACKSPACE_X                  (213)
    #define CAT203_BACKSPACE_Y_BASED_ON_SL  (1)
    #define CAT203_BACKSPACE_W                  (97)
    #define CAT203_BACKSPACE_H                  ((CAT203_BACKSPACE_Y_BASED_ON_SL << 1) + CAT203_SL_INPUTBOX_H)
#endif
#else /* __MMI_FTE_SUPPORT__ */
    #define CAT203_CONTENT_X                     (0)
    #define CAT203_CONTENT_Y                     (MMI_STATUS_BAR_HEIGHT)
    #define CAT203_CONTENT_W                     (MAIN_LCD_DEVICE_WIDTH)
    #define CAT203_CONTENT_H                     (MAIN_LCD_DEVICE_HEIGHT - MMI_STATUS_BAR_HEIGHT - MMI_BUTTON_BAR_HEIGHT)
    
    #define CAT203_MULTI_LINE_INPUTBOX_Y        (CAT203_CONTENT_Y)
    #define CAT203_MULTI_LINE_INPUTBOX_H        (2 * MMI_SINGLELINE_INPUTBOX_HEIGHT)

    #define CAT203_STRING_Y                      (CAT203_MULTI_LINE_INPUTBOX_Y + CAT203_MULTI_LINE_INPUTBOX_H)
    #define CAT203_STRING_H                      (MMI_MENUITEM_HEIGHT)

    #define CAT203_DYNAMIC_LIST_Y                (CAT203_STRING_Y + CAT203_STRING_H)
    #define CAT203_DYNAMIC_LIST_H                (CAT203_CONTENT_H - CAT203_MULTI_LINE_INPUTBOX_H - CAT203_STRING_H)
#endif /* __MMI_FTE_SUPPORT__ */
    
    extern S32(*g_wgui_cat203_search_function) (UI_buffer_type);    
    extern void (*g_wgui_cat203_resize_and_draw_func) (S32);
#ifdef __MMI_TOUCH_SCREEN__
    extern void wgui_cat203_get_hw_area(S32*, S32*, S32*, S32*);
#endif /* __MMI_TOUCH_SCREEN__ */

#if (defined __MMI_TOUCH_SCREEN__)
    extern void wgui_cat203_enable_center_softkey(U16 string, U16 icon);
#endif /* (defined __MMI_TOUCH_SCREEN__) */
    extern void wgui_cat203_set_right_softkey_function(void (*f) (void), MMI_key_event_type k);
/* DOM-NOT_FOR_SDK-BEGIN */ 
    #define wgui_cat203_set_right_softkey_function(_arg0, _arg1) wgui_inputs_category_set_rsk_func(_arg0)
/* DOM-NOT_FOR_SDK-END */

#ifdef __MMI_FTE_SUPPORT__

extern void (*g_wgui_cat203_highlight_handler) (S32);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat203_register_highlight_handler
 * DESCRIPTION
 *  register category203 highlight handler
 * PARAMETERS
 *  f      [IN]   highlight handler function
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat203_register_highlight_handler(void (*f) (S32));
#endif /* __MMI_FTE_SUPPORT__ */ 

/**************************************************************
  * FUNCTION
  *  ShowCategory203Screen
  * Description
  *  Dialer search category screen
  *  [FTE]: support(tool bar is avaiable)
  * 
  * <img name="wgui_cat203_img1" />
  * PARAMETERS
  *  left_softkey                      : [IN ] (LSK) Left softkey label
  *  left_softkey_icon                 : [IN ] (N/A) Icon for the Left softkey
  *  right_softkey                     : [IN ] (RSK) Right softkey label
  *  right_softkey_icon                : [IN ] (N/A) Icon for the right softkey
  *  message                           : [IN ] (N/A) Description info
  *  number_of_items                   : [IN ] (N/A) Number of items
  *  get_item_func                     : [IN ] (N/A) Get menu item function
  *  get_hint_func                     : [IN ] (N/A) Get menu hint function
  *  get_underline_func                : [IN ] (N/A) Get menu underline function
  *  search_func                       : [IN ] (N/A) Search result function
  *  buffer                            : [IN ] (N/A) Buffer for input
  *  buffer_max_length                 : [IN ] (N/A) Max length for input
  *  history_buffer                    : [IN ] (N/A) History buffer
  * Returns
  *  void                                                   
  **************************************************************/
extern void ShowCategory203Screen(
                    UI_string_type left_softkey, 
                    PU8 left_softkey_icon,
                    UI_string_type right_softkey,
                    PU8 right_softkey_icon,
                    UI_string_type message,
                    S32 number_of_items,
                    GetItemFuncPtr get_item_func,
                    GetHintFuncPtr get_hint_func,
                    GetUnderLineFuncPtr get_underline_func,
                    S32(*search_func) (UI_buffer_type),
                    U8 *buffer,
                    S32 buffer_max_length,        
                    U8 *history_buffer);
    extern void ExitCategory203Screen(void);
    extern U8 *GetCategory203History(U8 *history_buffer);
    extern S32 GetCategory203HistorySize(void);
 
    extern void wgui_cat203_refresh_search_list(U8 *input_number);
    
    extern MMI_BOOL wgui_cat203_is_editor_active(void);
    extern void wgui_cat203_set_editor_focus_state(MMI_BOOL active);
    extern void wgui_cat203_set_menu_focus_state(MMI_BOOL active);

    extern MMI_BOOL wgui_cat203_is_vk_input(void);

#endif /* __MMI_CAT203_SUPPORT__ */

#endif /* __WGUI_CATEGORIES_IDLESCREEN_OP_H__ */ 


