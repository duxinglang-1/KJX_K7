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
 * wgui_inline_edit.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Functions for Inline items.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * This file contains following sections:
 *
 * 1.Inline Editor Common 
 * 2.Inline Text Edit
 * 3.Inline Full Screen Edit 
 * 4.Inline Image Text 
 * 5.Inline Image Attachment
 * 6.Inline Select
 * 7.Inline Date Edit 
 * 8.Inline Time Edit 
 * 9.Inline User Defined Select 
 * 10.Inline Day Of Week Select 
 * 11.Inline Time Period Edit 
 * 12.Inline IP4 Edit
 * 13.Inline Color Select 
 * 14.Inline Multiline Edit Read Only
 * 15.Some Utility function for Inline Editor 
 * 16.Categories for inline editor
 *
 *****************************************************************************/


/***************************************************************************** 
 * Inline Editor Common 
 *
 * This is Inline Editor Common used Declaration and Function 
 *****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "CustDataRes.h"
#include "CustDataProts.h"
#include "wgui_datetime.h"
#include "CommonScreens.h"
#include "wgui_virtual_keyboard.h"
#ifdef __MMI_INDIC_ALG__
#include "IndicEngineGprot.h"
#endif
#include "wgui_fixed_menuitems.h"
#include "wgui_asyncdynamic_menus.h"
#include "wgui_softkeys.h"
#include "wgui_tab_bars.h"
#include "ImeGprot.h"
#include "InlineCui.h"
#include "gui_progress_bar.h"
#include "wgui_progress_bar.h"
#include "gui_font_size.h"

#include "Menucuigprot.h"
#include "Gui_font_size.h"

#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)  
#include "mmi_frm_gestures.h"
#endif
#include "MMIDataType.h"
#include "gui_touch_feedback.h"

#include "gui_horizontal_selector.h"
#include "kal_debug.h"


 #include "MMIDataType.h"
    #include "kal_public_defs.h"
#include "wgui_inline_edit.h"
    #include "kal_general_types.h"
#include "mmi_frm_input_gprot.h"
#include "wgui_categories_util.h"
#include "CustThemesRes.h"
#include "gui.h"
#include "gui_data_types.h"
#include "gui_theme_struct.h"
#include "gui_themes.h"
#include "gui_typedef.h"
#include "gui_windows.h"
#include "gui_inputs.h"
#include "gui_scrollbars.h"
#include "wgui_inputs.h"
#include "gui_buttons.h"
#include "wgui_fixed_menus.h"
#include "gdi_include.h"
#include "gui_fixed_menus.h"
#include "gui_config.h"
#include "wgui.h"
#include "GlobalConstants.h"
#include "GlobalResDef.h"
#include "wgui_include.h"
#include "Unicodexdcl.h"
    #include "mmi_frm_events_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "gui_fixed_menuitems.h"
#include "string.h"
#include "gdi_datatype.h"
#include "mmi_rp_app_uiframework_def.h"
#include "gdi_const.h"
#include "PixcomFontEngine.h"
    #include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_events_gprot.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "gui_effect_oem.h"
#include "wgui_categories_inputs.h"
#include "InlineCuiGprot.h"
    #include "wgui_draw_manager.h"
#include "wgui_touch_screen.h"
#include "mmi_frm_gestures_gprot.h"
#include "mmi_clipboard_gprot.h"
#include "ScreenRotationGprot.h"
#include "wgui_draw_manager.h"
#include "wgui_title.h"
#include "gui_virtual_keyboard_language_type.h"
    #include "gui_virtual_keyboard.h"
#include "wgui_categories_enum.h"
#include "gui_switch.h"
#include "IdleAppResDef.h"
#include "WapResDef.h"
   // #include "PocResDef.h"
#ifndef __COSMOS_MMI_PACKAGE__
#include "mmi_rp_app_sms_def.h"
#endif
#include "CommonScreensResDef.h"
#include "lcd_sw_inc.h"
#include "Gui_Setting.h"
#include "wgui_categories_res.h"
#include "mmi_cb_mgr_gprot.h"
#include "wgui_categories_list.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_common_defs.h"
#include "CustMenuRes.h"
    #include "kal_trace.h"
#include "stdio.h"
#include "mmi_rp_srv_editor_def.h"
#include "mmi_frm_scenario_gprot.h"

#include "mmi_frm_mem_gprot.h"
#include "FSEditorCuiGprot.h"



/***************************************************************************** 
 * Define
 *****************************************************************************/
/* History IDs for inline items  */
#define INLINE_TEXT_EDIT_HISTORY_ID                1
#define INLINE_SELECT_HISTORY_ID                   3
#define INLINE_USER_DEFINED_SELECT_HISTORY_ID      4
#define INLINE_DATE_HISTORY_ID                     5
#define INLINE_TIME_HISTORY_ID                     6
#define INLINE_DOW_SELECT_HISTORY_ID               7
#define INLINE_TIME_PERIOD_HISTORY_ID              8
#define INLINE_IP4_HISTORY_ID                      9
#define INLINE_FULL_SCREEN_EDIT_HISTORY_ID         10
#define INLINE_MULTI_LINE_EDIT_HISTORY_ID          11
#define INLINE_COLOR_SELECT_SCREEN_ID              12
#define INLINE_IMAGE_TEXT_HISTORY_ID               13

#define CATEGORY57_NO_KEY_FLAG                     0
#define CATEGORY57_UP_ARROW_KEY_FLAG               1
#define CATEGORY57_DOWN_ARROW_KEY_FLAG             2

#define INLINE_DEFAULT_TEXT_BORDAR               1  
#define INLINE_DEFAULT_TEXT_BORDAR_GAP           1 

#ifdef  __MMI_FTE_SUPPORT__


U8 g_inline_vk_status;
#endif

#define MMI_INLINE_PROGRESS_BAR_Y_OFFSET_TO_SSP     10

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
    
typedef enum
{
    /* Ignore pen events */
    WGUI_INLINE_PEN_HANDLER_NONE,
    /* Prepare to change highlight on Pen Up. Do nothing else. */
    WGUI_INLINE_PEN_HANDLER_SWITCH_ITEM,
    /* Redirect pen events to scrollbar */
    WGUI_INLINE_PEN_HANDLER_SCROLLBAR,
    /* Redirect pen events to the current menu item */
    WGUI_INLINE_PEN_HANDLER_CURRENT_ITEM,
    /* Wait long press animation to invoke LSK */
    WGUI_INLINE_PEN_HANDLER_WAIT_LONGPRESS,
    /* Redirect pen events to fullscreen editor */
    WGUI_INLINE_PEN_HANDLER_FULLSCREEN_EDITOR
} wgui_inline_pen_handler_type_enum;

#endif /* __MMI_TOUCH_SCREEN__ */
/***************************************************************************** 
 * Local Variable
 *****************************************************************************/
static KAL_ADM_ID   inline_adm_id = NULL;
static void  *wgui_inline_mem_alloc_info[MAX_INLINE_ITEMS*2];
static S32   wgui_inline_mem_alloc_number = 0;
static MMI_BOOL g_inline_menu_disable_loop = MMI_FALSE;
static MMI_BOOL g_inline_disable_auto_enter = MMI_FALSE;
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
static BOOL mmi_pen_editor_is_closecategory57;
#endif /* defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) */ 

static S32 wgui_inline_item_key_code = -1;
static S32 wgui_inline_item_key_event = -1;
static S32 wgui_inline_item_x = 0;
static S32 wgui_inline_item_y = 0;
static S32 wgui_inline_item_width = 0;
static S32 wgui_inline_item_height = 0;
static S32 wgui_current_inline_item_type = 0;
static PU8 wgui_current_history_buffer = NULL;

#ifdef __MMI_INLINE_HIGHLIGHT_CAPTION__
static S32 wgui_inline_should_hl_caption_index = -1;
#endif

#if defined (__MMI_INLINE_ITEM_IMAGETEXT__)
U8 inline_image_text_edit_flag = 0;
#endif
static U16 *wgui_inline_list_of_icons = NULL;

#ifdef __MMI_TOUCH_SCREEN__
static wgui_inline_pen_handler_type_enum wgui_inline_pen_handler_type;
static S32 wgui_inline_pen_down_item_index;
static BOOL(*wgui_current_inline_item_pen_function) (mmi_pen_event_type_enum pen_event, S16 x, S16 y,
                                                     gui_inline_item_pen_enum *item_event) 
                             = UI_dummy_inline_item_pen_function;

#endif /* __MMI_TOUCH_SCREEN__ */



#if defined (__MMI_WALLPAPER_ON_BOTTOM__)
static U8 inline_edit_scr_bg_opacity;
static BOOL inline_opacity_changed = FALSE;
#endif /* defined (__MMI_WALLPAPER_ON_BOTTOM__) */ 

/* for sending inline items' change notify to application */
static void (*inline_item_changed_handler) (U16 index);

static UI_filled_area temp_inline_list_menu_background_filler = 
{
    UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
#ifdef __MMI_DEFAULT_THEME_3__
    {206, 206, 206, 100},
#else 
    {240, 240, 240, 100},
#endif 
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

static UI_filled_area temp_inline_list_menu_normal_item_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
#ifdef __MMI_DEFAULT_THEME_3__
    {206, 206, 206, 100},
#else 
    {240, 240, 240, 100},
#endif 
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

static UI_filled_area temp_inline_list_menu_selected_item_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
#ifdef __MMI_DEFAULT_THEME_3__
    {255, 255, 255, 100},
#else 
    {167, 232, 93, 100},
#endif 
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

static UI_filled_area temp_inline_list_menu_disabled_item_filler = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {192, 192, 192, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};


static UI_fixed_text_menuitem_theme wgui_inline_select_fixed_text_menuitem_theme = { &temp_inline_list_menu_normal_item_filler,
    &temp_inline_list_menu_disabled_item_filler,
    &temp_inline_list_menu_selected_item_filler,
    &temp_inline_list_menu_selected_item_filler,
    &temp_inline_list_menu_selected_item_filler,    
    {0, 0, 0, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 100},
    //{0, 0, 0, 100},
    &MMI_default_font,
    UI_MENUITEM_CENTER_TEXT_Y
};


#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
static U8 wgui_enable_inline_item_default_text = 0;

static UI_filled_area temp_inline_edit_normal_filler = {
    UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {0, 0, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};
#endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 

static U8 wgui_inline_edit_arrow_key_flag = CATEGORY57_NO_KEY_FLAG;

static void (*clear_inline_item_keys) (void) = UI_dummy_function;

static UI_string_type inline_text_edit_APP_Assigned_RSK_label_string = NULL;

static PU8 g_inline_picon = NULL;

/* When we draw unhighlight select item by ourselves, we use it to note icon x corrdinate, because it can not aligned for highlight and unhighlight case. */
static S32 g_select_unhighlight_x_corrdinate = 0;

static scrolling_text wgui_inline_scroll_text;

#ifdef __MMI_FTE_SUPPORT__
static inline_fte_line_style_enum g_inline_fte_item_height_table[MAX_INLINE_ITEMS];
static U16 inline_color_select_control_x_coordinate;
static U16 inline_color_select_control_y_coordinate;
static U16 inline_color_select_control_width;
static U16 inline_color_select_control_height;
#endif

#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
#if defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__)
wgui_inline_ml_rdly_highlight_list_struct g_inline_ml_rdly_highlight_list = {0};
#endif
#endif

/* It must be set when entry inline screen every time, because it is screen faced, not group face. */
MMI_ID g_inline_parent_id = GRP_ID_ROOT;
U8 wgui_inline_list_menu_rsk_back = 0;

#define WGUI_INLINE_ITEM_TYPE(index)	(wgui_inline_items[(index)].flags & INLINE_ITEM_TYPE_MASK)
static void (*g_inline_lsk_functions)(void) = NULL;
static void (*g_inline_edit_back_function) (void) = NULL;
static void (*g_inline_edit_done_function) (void) = NULL;

#if defined(__MMI_TOUCH_SCREEN__)
static void wgui_inline_tap_callback_funtion(mmi_tap_type_enum tap_type,S32 index);
#endif

/***************************************************************************** 
 * Local Function
 *****************************************************************************/
static void wgui_inline_edit_default_list_highlight_handler(S32 item_index);
#if defined (__MMI_INLINE_ITEM_IMAGETEXT__)
static void wgui_show_image_text_item_highlight(S32 x1, S32 y1, S32 iwidth, S32 iheight, wgui_inline_item *item);
#endif
void wgui_show_inline_edit_menuitem(S32 x, S32 y, S32 width, S32 height);


U8 *inline_date_edit_get_history(U8 *history_buffer);
U8 *inline_time_edit_get_history(U8 *history_buffer);
U8 *inline_time_period_edit_get_history(U8 *history_buffer);
U8 *inline_IP4_edit_get_history(U8 *history_buffer);
U8 *inline_DOW_select_get_history(U8 *history_buffer);
U8 *inline_multi_line_edit_get_history(U8 *history_buffer);
void inline_DOW_select_change_complete(void);
U8 *inline_image_text_get_history(U8 * history_buffer);
U8 inline_image_text_set_history(U16 history_ID, U8 * history_buffer);

/* IME related callback functions */
static U32 mmi_input_box_msg_call_back_inline(void * input_box_handle, mmi_imc_message_struct_p msg_ptr);
static void mmi_input_box_keep_current_item_info(void);
static void mmi_input_box_resume_current_item_info(void);


static void cat57_virtual_keypad_callback(void);
static void register_inline_fixed_list_keys(void);

static void ShowCommonCategoryInlineEdit(
               UI_string_type title, U16 title_icon, U16 left_softkey,
               U16 left_softkey_icon,U16 right_softkey, U16 right_softkey_icon,
               S32 number_of_items, U16 *list_of_icons,InlineItem *list_of_items,
               S32 highlighted_item, U8 *history_buffer,
               void (*highlight_handler) (S32 item_index),
               void (*unhighlight_handler) (S32 item_index),
               U16 history_id);


/* Inline Editor ADM API */
static void *wgui_inline_malloc(U16 size);

void wgui_inline_show_icon_in_inlineitem(S32 index, S32 x, S32 y);
void wgui_inline_show_icon_in_singleline(S32 x, S32 y, S32 clip_x1, S32 clip_y1, S32 clip_x2, S32 clip_y2);
void SetInlineIconStyle(InlineItem *item, PU8 picon, BOOL b);
void wgui_inline_get_default_indicator_width( S32 *pwidth, S32 *pheight);


#ifdef __MMI_FTE_SUPPORT__
void wgui_show_inline_fte_displayonly_item_unhighlight_ext(
                S32 x,
                S32 y,
                S32 width,
                S32 height,
                wgui_inline_item *item,
                U8 status_flag);

void wgui_show_inline_fte_displayonly_item_highlight(
                S32 x,
                S32 y,
                S32 width,
                S32 height,
                wgui_inline_item *item);

void wgui_show_inline_fte_displayonly_item_highlight_ext(
                S32 x,
                S32 y,
                S32 width,
                S32 height,
                wgui_inline_item *item,
                U8 status_flag);

void wgui_show_inline_fte_caption_item(
                S32 x,
                S32 y,
                S32 width,
                S32 height,
                wgui_inline_item *item);

BOOL inline_fte_displayonly_item_pen_handler(
                mmi_pen_event_type_enum pen_event,
                S16 x,
                S16 y,
                gui_inline_pen_enum *inline_event,
                U16 index);

void inline_fte_set_item_height_by_guess(InlineItem *list_of_items, S32 number_of_items);
    
void wgui_inline_get_vk_status(U8 *vk_status);
void wgui_inline_set_vk_status(U8 vk_status);
    
#endif

void wgui_inlinescrolling_timer(void);
void wgui_scrolling_text_draw_background(S32 x1, S32 y1, S32 x2, S32 y2);
void wgui_show_inline_text_edit_list_menuitem(S32 x1, S32 y1, S32 width, S32 height, wgui_inline_item *item);
UI_single_line_input_box_theme wgui_inline_singleline_inputbox_unfocussed_theme;
UI_single_line_input_box_theme wgui_inline_singleline_inputbox_focussed_theme;

void wgui_inline_set_focussed_progress_bar_theme();
void wgui_inline_set_unfocussed_progress_bar_theme();
void wgui_show_inline_progress_bar_list_menuitem(S32 x1, S32 y1, S32 width, S32 height, wgui_inline_item *item);

void wgui_inline_stop_scroll(void);
void wgui_inline_start_scroll(void);

#ifdef __MMI_TOUCH_SCREEN__
S32 wgui_inline_get_item_height_for_scroll_bar(gui_scrollbar_dir_enum direction);
#endif

static void wgui_inline_option_handler_for_lsk(void);

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
wgui_inline_item wgui_inline_items[MAX_INLINE_ITEMS];
wgui_inline_item *current_wgui_inline_item = NULL;

PU8 g_wgui_inine_items_buffer = NULL;

S32 wgui_n_inline_items = 0;
S32 wgui_inline_item_highlighted_index = -1;
U8 wgui_inline_item_handled = 0;

U8 g_inline_is_no_redraw_status = 0;

#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
S8 MMI_multi_line_inputbox_present = 0;
#endif 

/* Added to handle (Back/Done) on RSK  */
U8 wgui_inline_list_menu_changed = 0;
U8 wgui_inline_list_menu_disable_done = 0;
void (*wgui_inline_edit_BACK_function) (void) = NULL;
void (*wgui_inline_edit_DONE_function) (void) = NULL;
void (*wgui_inline_edit_LSK_function) (void) = NULL;


UI_fixed_list_menu_theme wgui_inline_fixed_list_menu_theme = { 
    &temp_inline_list_menu_background_filler,
    &temp_inline_list_menu_background_filler,
    5,
    UI_LIST_MENU_LOOP
};

UI_fixed_icontext_menuitem_theme wgui_inline_fixed_icontext_menuitem_theme =
    { &temp_inline_list_menu_normal_item_filler,
    &temp_inline_list_menu_disabled_item_filler,
    &temp_inline_list_menu_selected_item_filler,
    &temp_inline_list_menu_selected_item_filler,
    &temp_inline_list_menu_selected_item_filler,
    {0, 0, 0, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 100},
    //{0, 0, 0, 100},
    &MMI_default_font,
    UI_MENUITEM_CENTER_TEXT_Y | UI_MENUITEM_CENTER_ICON_Y
};


void (*redraw_current_inline_item) (void) = UI_dummy_function;
void (*complete_inline_item_edit) (void) = UI_dummy_function;


/***************************************************************************** 
 * Extern Global Variable
 *****************************************************************************/

extern mmi_editor_handler_struct g_mmi_editor_hanler;

/* for 0x81 encoding support for Phone Book */
extern S16 MMI_current_input_ext_type;

extern UI_single_line_input_box_theme date_time_input_theme;
extern UI_filled_area date_time_input_field_filler;
extern UI_filled_area date_time_input_background_filler;
extern UI_filled_area time_period_input_background_filler;

extern icontext_button MMI_softkeys[];

extern S32(*wgui_inputbox_UCS2_count_function) (void);

#ifdef __MMI_UI_TRANSPARENT_EFFECT__
extern UI_filled_area fixed_icontext_menuitem_transparent_filled_area;
#endif /* __MMI_UI_TRANSPARENT_EFFECT__ */

extern S32 UI_text_menuitem_scroll_time;


/***************************************************************************** 
 * Extern Global Function
 *****************************************************************************/
extern void gui_single_line_input_box_locate_cursor(single_line_input_box *b);
extern void set_current_input_box_type(mmi_editor_inoutbox_enum input_box_type);
#if defined (__MMI_TOUCH_SCREEN__)
extern void date_input_move_to_x_y(date_input *d, S32 x, S32 y);
extern void time_input_move_to_x_y(time_input *t, S32 x, S32 y);
extern void time_period_input_move_to_x_y(time_period_input *tp, S32 x, S32 y);
extern void IP4_input_move_to_x_y(IP4_input *ip4, S32 x, S32 y);
#endif
extern void reset_pop_up_descriptions(void);
extern void GoBackHistory(void);

/***************************************************************************** 
 * Common Function Implementation
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  get_wgui_inline_list_menu_status
 * DESCRIPTION
 *  get inline list menu changed status
 * PARAMETERS
 *  void
 * RETURNS
 *  the value of wgui_inline_list_menu_changed
 *****************************************************************************/
S32 get_wgui_inline_list_menu_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wgui_inline_list_menu_changed;
}


/*****************************************************************************
 * FUNCTION
 *  set_wgui_inline_list_menu_status
 * DESCRIPTION
 *  set inline list menu changed status
 * PARAMETERS
 *  status      [IN]        value of wgui_inline_list_menu_changed
 * RETURNS
 *  void
 *****************************************************************************/
void set_wgui_inline_list_menu_status(S32 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inline_list_menu_changed = (U8) status;
}


/*****************************************************************************
 * FUNCTION
 *  SetInlineListMenuChanged
 * DESCRIPTION
 *  wrapper function of set_wgui_inline_list_menu_changed()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineListMenuChanged(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_wgui_inline_list_menu_changed();
}


/*****************************************************************************
 * FUNCTION
 *  GetInlineListMenuChanged
 * DESCRIPTION
 *  get the value of wgui_inline_list_menu_changed
 * PARAMETERS
 *  void
 * RETURNS
 *  the value value of wgui_inline_list_menu_changed
 *****************************************************************************/
S32 GetInlineListMenuChanged(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wgui_inline_list_menu_changed;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_edit_get_next_highlight_index
 * DESCRIPTION
 *  to get next highlightable inline item's index
 * PARAMETERS
 *  start_index start index of inline item
 * RETURNS
 *  next highlightable index
 *****************************************************************************/
S32 wgui_inline_edit_get_next_highlight_index(S32 start_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = start_index; i < wgui_n_inline_items; i++)
    {
        U32 flags = wgui_inline_items[i].flags;
        S32 item_type = wgui_inline_items[i].flags & 0xff;
        
        if (!((flags & INLINE_ITEM_DISABLED) ||
            (item_type == INLINE_ITEM_TYPE_CAPTION)))
        {
            return i;
        }
        
    }
    
    for (i = 0; i < start_index; i++)
    {
        U32 flags = wgui_inline_items[i].flags;
        S32 item_type = wgui_inline_items[i].flags & 0xff;
        
        if (!((flags & INLINE_ITEM_DISABLED) ||
            (item_type == INLINE_ITEM_TYPE_CAPTION)))
        {
            return i;
        }
        
    }
    
    return start_index;
}


/*****************************************************************************
 * FUNCTION
*  wgui_inline_edit_get_next_highlight_index
* DESCRIPTION
*  to get previous highlightable inline item's index
* PARAMETERS
*  start_index start index of inline item
* RETURNS
*  previous highlightable index
 *****************************************************************************/
S32 wgui_inline_edit_get_previous_highlight_index(S32 start_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = start_index; i >= 0; i--)
    {
        U32 flags = wgui_inline_items[i].flags;
        S32 item_type = wgui_inline_items[i].flags & 0xff;
        
        if (!((flags & INLINE_ITEM_DISABLED) ||
            (item_type == INLINE_ITEM_TYPE_CAPTION)))
        {
            return i;
        }
        
    }
    
    for (i = wgui_n_inline_items - 1; i > start_index; i--)
    {
        U32 flags = wgui_inline_items[i].flags;
        S32 item_type = wgui_inline_items[i].flags & 0xff;
        
        if (!((flags & INLINE_ITEM_DISABLED) ||
            (item_type == INLINE_ITEM_TYPE_CAPTION)))
        {
            return i;
        }
        
    }
    
    return start_index;
}



/*****************************************************************************
 * FUNCTION
 *  wgui_inline_edit_is_able_to_switch_highlight
 * DESCRIPTION
 *  to check if current inline editor can switch highlight to next/previous item
 * PARAMETERS
 *  direction   0 -> previous ; 1-> next
 * RETURNS
 *  MMI_TRUE -> can switch highlight   MMI_FALSE -> can't switch highlight
 *****************************************************************************/
MMI_BOOL wgui_inline_edit_is_able_to_switch_highlight(S32 direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    S32 switchable_item_no = 0;
    S32 ret_idx = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_inline_menu_disable_loop || (!(MMI_fixed_list_menu.flags & UI_LIST_MENU_LOOP)))
    {
        if (direction == 1)
        {
            if (wgui_inline_item_highlighted_index == (wgui_n_inline_items -1))
            {
                return MMI_FALSE;
            }
            else
            {
                i = wgui_inline_item_highlighted_index + 1;
            }
            ret_idx = wgui_inline_edit_get_next_highlight_index(i);
        }
        else
        {
            if (wgui_inline_item_highlighted_index == 0)
            {
                return MMI_FALSE;
            }
            else
            {
                i = wgui_inline_item_highlighted_index - 1;
            }
            ret_idx = wgui_inline_edit_get_previous_highlight_index(i);
        }
        
        if ((ret_idx == wgui_inline_item_highlighted_index)  ||
            ((ret_idx > wgui_inline_item_highlighted_index) && (direction == 0)) ||
            ((ret_idx < wgui_inline_item_highlighted_index) && (direction == 1)))
        {
            return MMI_FALSE;
        }
        else
        {
            return MMI_TRUE;
        }       
    }
    
    for (i = 0; i < wgui_n_inline_items; i++)
    {
        U32 flags = wgui_inline_items[i].flags;
        S32 item_type = wgui_inline_items[i].flags & 0xff;
        
        if (!((flags & INLINE_ITEM_DISABLED)         ||
              (item_type == INLINE_ITEM_TYPE_CAPTION)))
        {
            switchable_item_no++;
        }

        if (switchable_item_no >= 2)
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;

}
    

/*****************************************************************************
 * FUNCTION
 *  inline_fixed_list_goto_previous_item
 * DESCRIPTION
 *  goto previous item in inline fixed list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void inline_fixed_list_goto_previous_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* FIXME. register as complete_inline_item_edit()? */

#if defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__)
    if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE) &&
        (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INSIDE_INLINE_MENU))
    {
        handle_inline_multi_line_edit_complete();
    }
#endif    
    wgui_inline_edit_arrow_key_flag = CATEGORY57_UP_ARROW_KEY_FLAG;
    clear_inline_item_keys();
    register_inline_fixed_list_keys();

#ifdef __MMI_FTE_SUPPORT__
    if(wgui_inline_edit_is_able_to_switch_highlight(0))
    {
        wgui_inline_set_vk_status(g_inline_vk_status);
    }
#endif    
    /* Lock frame buffer to avoid partial screen update 
       (e.g. softkey changed before list is redrawn) */
    gdi_layer_lock_frame_buffer();
    fixed_list_goto_previous_item();
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);    

#ifdef __MMI_FTE_SUPPORT__	
	mmi_imc_set_vk_present(MMI_IMC_VK_DEFAULT_ENLARGE);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  inline_fixed_list_goto_next_item
 * DESCRIPTION
 *  goto next item in inline fixed list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void inline_fixed_list_goto_next_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inline_edit_arrow_key_flag = CATEGORY57_DOWN_ARROW_KEY_FLAG;
    clear_inline_item_keys();
    register_inline_fixed_list_keys();

#ifdef __MMI_FTE_SUPPORT__
    if(wgui_inline_edit_is_able_to_switch_highlight(1))
    {
        wgui_inline_set_vk_status(g_inline_vk_status);
    }
#endif    

    /* Lock frame buffer to avoid partial screen update 
       (e.g. softkey changed before list is redrawn) */
    gdi_layer_lock_frame_buffer();
    fixed_list_goto_next_item();
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

#ifdef __MMI_FTE_SUPPORT__	
	mmi_imc_set_vk_present(MMI_IMC_VK_DEFAULT_ENLARGE);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  inline_fixed_list_goto_item
 * DESCRIPTION
 *  goto item with item index and backward.
 * PARAMETERS
 *  index           [IN]      item index  
 *  backward        [IN]      TRUE -> up ; FALSE -> down  
 * RETURNS
 *  void
 *****************************************************************************/
void inline_fixed_list_goto_item_no_redraw(S32 index, BOOL backward)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (backward)
    {
        wgui_inline_edit_arrow_key_flag = CATEGORY57_UP_ARROW_KEY_FLAG;
    }
    else
    {
        wgui_inline_edit_arrow_key_flag = CATEGORY57_DOWN_ARROW_KEY_FLAG;
    }
    clear_inline_item_keys();
    register_inline_fixed_list_keys();

    gdi_layer_lock_frame_buffer();
    g_inline_is_no_redraw_status = 1;
        if (wgui_inline_edit_is_able_to_switch_highlight(!backward)) 
        {
    gui_fixed_list_menu_goto_item(&MMI_fixed_list_menu, index);   
        }
        else
        {
            S32 old_index = wgui_inline_item_highlighted_index;
            MMI_fixed_list_menu.highlighted_item =  -1 ;
            //wgui_inline_item_highlighted_index = -1;
            gui_fixed_list_menu_goto_item(&MMI_fixed_list_menu, old_index);
        }
    g_inline_is_no_redraw_status = 0;
    gdi_layer_unlock_frame_buffer();

}

/*****************************************************************************
 * FUNCTION
 *  inline_fixed_list_goto_item
 * DESCRIPTION
 *  goto item with item index and backward.
 * PARAMETERS
 *  index           [IN]      item index  
 *  backward        [IN]      TRUE -> up ; FALSE -> down  
 * RETURNS
 *  void
 *****************************************************************************/
void inline_fixed_list_goto_item(S32 index, BOOL backward)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* FIXME. register as complete_inline_item_edit()? */
    if (backward)
    {
        wgui_inline_edit_arrow_key_flag = CATEGORY57_UP_ARROW_KEY_FLAG;
    }
    else
    {
        wgui_inline_edit_arrow_key_flag = CATEGORY57_DOWN_ARROW_KEY_FLAG;
    }
    clear_inline_item_keys();
    register_inline_fixed_list_keys();

    /* Lock frame buffer to avoid partial screen update 
       (e.g. softkey changed before list is redrawn) */
    gdi_layer_lock_frame_buffer();
    fixed_list_goto_item(index);
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);    

}


/*****************************************************************************
 * FUNCTION
 *  inline_fixed_list_key_handler
 * DESCRIPTION
 *  key handler used only on PC
 * PARAMETERS
 *  vkey_code       [IN]  key code      
 *  key_state       [IN]  key state      
 * RETURNS
 *  void
 *****************************************************************************/
void inline_fixed_list_key_handler(S32 vkey_code, S32 key_state)
{
#if(MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_state)
    {
        switch (vkey_code)
        {
            case 37:
                break;
            case 39:
                break;
            case 38:
                inline_fixed_list_goto_previous_item();
                break;
            case 40:
                inline_fixed_list_goto_next_item();
                break;
            case 36:
                clear_inline_item_keys();
                fixed_list_goto_home();
                break;
            case 35:
                clear_inline_item_keys();
                fixed_list_goto_end();
                break;
            case 33:
                clear_inline_item_keys();
                fixed_list_goto_previous_page();
                break;
            case 34:
                clear_inline_item_keys();
                fixed_list_goto_next_page();
                break;
        }
    }
#else /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
    UI_UNUSED_PARAMETER(vkey_code);
    UI_UNUSED_PARAMETER(key_state);
#endif /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
}


/*****************************************************************************
 * FUNCTION
 *  register_inline_fixed_list_keys
 * DESCRIPTION
 *  register inline fixed list key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void register_inline_fixed_list_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_keyboard_key_handler(inline_fixed_list_key_handler);

    /* key rule. 09.10.17 */
    SetKeyHandler(inline_fixed_list_goto_previous_item, KEY_UP_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(inline_fixed_list_goto_next_item, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(inline_fixed_list_goto_previous_item, KEY_VOL_UP, KEY_EVENT_REPEAT);
    SetKeyHandler(inline_fixed_list_goto_next_item, KEY_VOL_DOWN, KEY_EVENT_REPEAT);
    
    SetKeyHandler(inline_fixed_list_goto_previous_item, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(inline_fixed_list_goto_next_item, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(inline_fixed_list_goto_previous_item, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(inline_fixed_list_goto_next_item, KEY_VOL_DOWN, KEY_EVENT_DOWN);
}


/* Changes to allow Back/Done key and Clear key in case of Inline edit  */
/* Max: add state to set RSK to "Clear" */
/*****************************************************************************
 * FUNCTION
 *  wgui_inline_edit_get_RSK_string
 * DESCRIPTION
 *  get RSK String
 * PARAMETERS
 *  void
 * RETURNS
 *  UI_string_type
 *****************************************************************************/
UI_string_type wgui_inline_edit_get_RSK_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_inline_list_menu_changed)
    {
        if (wgui_inline_list_menu_disable_done == 2)
        {
            return ((UI_string_type) get_string(STR_GLOBAL_CLEAR));
        }
		else
		{
		    return ((UI_string_type) get_string(STR_GLOBAL_BACK));
		}
    }
    else
    {
        return ((UI_string_type) get_string(STR_GLOBAL_BACK));
    }
}


/*****************************************************************************
 * FUNCTION
 *  execute_wgui_inline_edit_BACK_function
 * DESCRIPTION
 *  execute BACK func of inline editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void execute_wgui_inline_edit_BACK_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_inline_edit_BACK_function != NULL)
    {
        MMI_multi_line_inputbox_present = 0;
        wgui_inline_edit_BACK_function();
    }
}


/*****************************************************************************
 * FUNCTION
 *  execute_wgui_inline_edit_RSK_function
 * DESCRIPTION
 *  execute RSK func of inline editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void execute_wgui_inline_edit_RSK_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(cui_inline_is_current_cui())
    {
        cui_inline_rsk_function();
        return;
    }

	execute_wgui_inline_edit_BACK_function();
}


/*****************************************************************************
 * FUNCTION
 *  execute_wgui_inline_edit_LSK_function
 * DESCRIPTION
 *  execute LSK func of inline editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void execute_wgui_inline_edit_LSK_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    complete_inline_item_edit();
    if (wgui_inline_edit_LSK_function != NULL)
    {
        wgui_inline_edit_LSK_function();
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_set_anykey_auto_enter
 * DESCRIPTION
 *  disable the anykey auto entering function
 * PARAMETERS
 *  b_enable  [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_set_anykey_auto_enter(MMI_BOOL b_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_inline_disable_auto_enter = (MMI_BOOL)(!b_enable);
}


/*****************************************************************************
 * FUNCTION
 *  register_inline_edit_handle_right_softkey_up
 * DESCRIPTION
 *  register Right softkey up handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_inline_edit_handle_right_softkey_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_right_softkey_function(execute_wgui_inline_edit_RSK_function, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  set_wgui_inline_list_menu_changed
 * DESCRIPTION
 *  set wgui_inline_list_menu_changed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_wgui_inline_list_menu_changed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (inline_item_changed_handler != NULL)
    {
        inline_item_changed_handler((U16) wgui_inline_item_highlighted_index);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_edit_register_BACK_function
 * DESCRIPTION
 *  register BACK key handler of inline editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_edit_register_BACK_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(cui_inline_is_current_cui())
    {
        set_right_softkey_function(cui_inline_rsk_function, KEY_EVENT_UP);
        return;
    }
    set_right_softkey_function(execute_wgui_inline_edit_BACK_function, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_edit_register_ckey_BACK_function
 * DESCRIPTION
 *  register KEY_CLEAR up as back function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_edit_register_ckey_BACK_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(execute_wgui_inline_edit_BACK_function, KEY_CLEAR, KEY_EVENT_UP);
}



/*****************************************************************************
 * FUNCTION
 *  wgui_inline_text_edit_set_RSK_BACK_function
 * DESCRIPTION
 *  set RSK back function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_text_edit_set_RSK_BACK_function(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
    {
        SetKeyHandler(UI_dummy_function, KEY_CLEAR, KEY_EVENT_DOWN);
        SetKeyHandler(wgui_inline_edit_register_ckey_BACK_function, KEY_CLEAR, KEY_EVENT_UP);
    }
    if (inline_text_edit_APP_Assigned_RSK_label_string != NULL)
    {
        set_right_softkey_label(inline_text_edit_APP_Assigned_RSK_label_string);
    }
    else
    {
        set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_BACK));
    }
    /*	On DisableDone station, When  pen down to clear text till text is empty ,
    and pen is not left still pen move away rightkey, the rightkey handler can not be registered.
    So we modify that rightkey is registered for KEY_EVENT_DOWN event. 
    */
    set_right_softkey_function(wgui_inline_edit_register_BACK_function, KEY_EVENT_DOWN);

    if(!g_inline_is_no_redraw_status)
    {
        redraw_right_softkey();
    }

}


/*****************************************************************************
 * FUNCTION
 *  ShowAsControl
 * DESCRIPTION
 *  show inline item as control
 * PARAMETERS
 *  item        [IN]     iniline item's pointer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowAsControl(InlineItem *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item->show_img_flag = TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  SetInlineItemActivation
 * DESCRIPTION
 *  set inline item's key code and key state
 * PARAMETERS
 *  item            [IN]        inline item's pointer 
 *  key_code        [IN]        key code
 *  key_event       [IN]        key event
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineItemActivation(InlineItem *item, S32 key_code, S32 key_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item->key_code = key_code;
    item->key_event = key_event;

}


/*****************************************************************************
 * FUNCTION
 *  DisableInlineItem
 * DESCRIPTION
 *  disable inline item
 * PARAMETERS
 *  item        [IN]    inline item's pointer     
 *  index       [IN]    item's index    
 * RETURNS
 *  void
 *****************************************************************************/
void DisableInlineItem(InlineItem *item, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item->flags |= INLINE_ITEM_DISABLED;
    wgui_inline_items[index].flags |= INLINE_ITEM_DISABLED;
}


/*****************************************************************************
 * FUNCTION
 *  EnableInlineItem
 * DESCRIPTION
 *  Enable inline item
 * PARAMETERS
 *  item        [IN]    inline item's pointer         
 *  index       [IN]    inline item's index    
 * RETURNS
 *  void
 *****************************************************************************/
void EnableInlineItem(InlineItem *item, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item->flags &= ~INLINE_ITEM_DISABLED;
    wgui_inline_items[index].flags &= ~INLINE_ITEM_DISABLED;
}



/*****************************************************************************
 * FUNCTION
 *  DisableInlineItemHighlight
 * DESCRIPTION
 *  Disable inline item's highlight flag
 * PARAMETERS
 *  item        [IN]    inline item's pointer      
 * RETURNS
 *  void
 *****************************************************************************/
void DisableInlineItemHighlight(InlineItem *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item->flags |= INLINE_ITEM_DISABLE_HIGHLIGHT;
}

/* Add this function at W09.47 */
/*****************************************************************************
 * FUNCTION
 *  DisableInlineItemHighlight
 * DESCRIPTION
 *  Disable inline item's highlight flag
 * PARAMETERS
 *  item        [IN]    inline item's pointer      
 * RETURNS
 *  void
 *****************************************************************************/
void EnableInlineItemHighlight(InlineItem *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item->flags &= ~INLINE_ITEM_DISABLE_HIGHLIGHT;
}


/*****************************************************************************
 * FUNCTION
 *  SetInlineItemFullWidth
 * DESCRIPTION
 *  set inline item as full width
 * PARAMETERS
 *  item        [IN]    inline item's pointer     
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineItemFullWidth(InlineItem *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item->flags |= INLINE_ITEM_LEFT_ALIGN;
}

/*****************************************************************************
 * FUNCTION
 *  ResetInlineItemFullWidth
 * DESCRIPTION
 *  set inline item as full width
 * PARAMETERS
 *  item        [IN]    inline item's pointer     
 * RETURNS
 *  void
 *****************************************************************************/
void ResetInlineItemFullWidth(InlineItem *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item->flags &= ~INLINE_ITEM_LEFT_ALIGN;
}


/*****************************************************************************
 * FUNCTION
 *  LeftJustifyInlineItem
 * DESCRIPTION
 *  set inline item as left justify
 * PARAMETERS
 *  item        [IN]    inline item's pointer    
 * RETURNS
 *  void
 *****************************************************************************/
void LeftJustifyInlineItem(InlineItem *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item->flags &= ~INLINE_ITEM_JUSTIFY_MASK;
    item->flags |= INLINE_ITEM_LEFT_JUSTIFY;
}


/*****************************************************************************
 * FUNCTION
 *  RightJustifyInlineItem
 * DESCRIPTION
 *  set inline item as right justify
 * PARAMETERS
 *  item        [IN]    inline item's pointer      
 * RETURNS
 *  void
 *****************************************************************************/
void RightJustifyInlineItem(InlineItem *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item->flags &= ~INLINE_ITEM_JUSTIFY_MASK;

    /* Inline items will not be shown right justify, when the default text effect
       is enabled, so removed the flag in that case. */
#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
    if (!(IsInlineItemDefaultTextEnable()))
#endif 

      item->flags |= INLINE_ITEM_RIGHT_JUSTIFY;
}


/*****************************************************************************
 * FUNCTION
 *  CenterJustifyInlineItem
 * DESCRIPTION
 *  set inline item as center justify
 * PARAMETERS
 *  item        [IN]    inline item's pointer    
 * RETURNS
 *  void
 *****************************************************************************/
void CenterJustifyInlineItem(InlineItem *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item->flags &= ~INLINE_ITEM_JUSTIFY_MASK;
    item->flags |= INLINE_ITEM_CENTER_JUSTIFY;
}


/*****************************************************************************
 * FUNCTION
 *  DisableInlineItemBoundary
 * DESCRIPTION
 *  Disable inline item boundary
 * PARAMETERS
 *  item        [IN]    inline item's pointer     
 * RETURNS
 *  void
 *****************************************************************************/
void DisableInlineItemBoundary(InlineItem *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item->flags &= ~INLINE_ITEM_BOUNDARY_MASK;
    item->flags |= INLINE_ITEM_BOUNDARY_NEVER;
}


/*****************************************************************************
 * FUNCTION
 *  EnableInlineItemBoundary
 * DESCRIPTION
 *  Enable inline item boundary
 * PARAMETERS
 *  item        [IN]    inline item's pointer  
 * RETURNS
 *  void
 *****************************************************************************/
void EnableInlineItemBoundary(InlineItem *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item->flags &= ~INLINE_ITEM_BOUNDARY_MASK;
    item->flags |= INLINE_ITEM_BOUNDARY_ALWAYS;
}


/*****************************************************************************
 * FUNCTION
 *  SetInlineItemDottedUnderline
 * DESCRIPTION
 *  Set inine item's INLINE_ITEM_DOTTED_UNDERLINE flag
 * PARAMETERS
 *  item        [IN]    inline item's pointer    
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineItemDottedUnderline(InlineItem *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item->flags |= INLINE_ITEM_DOTTED_UNDERLINE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_item_key_handler
 * DESCRIPTION
 *  inline item key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_item_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    wgui_text_menuitem_reset_scrolling();
    gdi_layer_unlock_frame_buffer();
    wgui_inline_items[wgui_inline_item_highlighted_index].handler(
                                                            wgui_inline_item_x,
                                                            wgui_inline_item_y,
                                                            wgui_inline_item_width,
                                                            wgui_inline_item_height,
                                                            wgui_inline_item_key_code,
                                                            wgui_inline_item_key_event,
                                                            &wgui_inline_items [wgui_inline_item_highlighted_index].text_p,
                                                            wgui_inline_items[wgui_inline_item_highlighted_index].item,
                                                            wgui_inline_items[wgui_inline_item_highlighted_index].flags,
                                                            wgui_current_history_buffer);
    wgui_current_history_buffer = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  register_inline_item_key_handler
 * DESCRIPTION
 *  register inline item key handler for index(th) item 
 * PARAMETERS
 *  index       [IN]     inline item's index   
 * RETURNS
 *  void
 *****************************************************************************/
void register_inline_item_key_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inline_item_highlighted_index = index;
    wgui_inline_item_key_code = wgui_inline_items[index].key_code;
    wgui_inline_item_key_event = wgui_inline_items[index].key_event;

    if(wgui_inline_item_key_code != INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT)
    {
        if (wgui_inline_item_key_code == KEY_LSK)
        {
            SetLeftSoftkeyFunction(wgui_inline_item_key_handler, wgui_inline_item_key_event);
            if(cui_inline_is_current_cui())
            {
                SetCenterSoftkeyFunction(wgui_inline_item_key_handler, wgui_inline_item_key_event);    
            }   
        }
        else if (wgui_inline_item_key_code == KEY_RSK)
        {
            SetRightSoftkeyFunction(wgui_inline_item_key_handler, wgui_inline_item_key_event);
        }
        else
        {
            SetKeyHandler(wgui_inline_item_key_handler, (U16) wgui_inline_item_key_code, (U16) wgui_inline_item_key_event);
        } 
    }
}

#ifdef __MMI_FTE_SUPPORT__
static MMI_BOOL g_ssp_redraw = MMI_FALSE;

/*****************************************************************************
 * FUNCTION
 *  wgui_inline_shift_input_cursor
 * DESCRIPTION
 *  adjust cursor position
 * PARAMETERS
 *  first_display       [IN]     the first displayed list item index 
 *  last_display        [IN]     the last displayed list item index
 *  index               [IN]     the current highlighted index
 *  y                   [IN]     the new position
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_shift_input_cursor(S32 first_display, S32 last_display, S32 index, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_BLINKING_CURSOR_SUPPORT)
    if (index == wgui_inline_item_highlighted_index)
    {
        S32 clip_y1, clip_y2;
        
        clip_y1 = MMI_fixed_list_menu.y;
        clip_y2 = MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1;

        UI_inputbox_move_cursor(0, y, -1, clip_y1, -1, clip_y2);
    }
    else
    {
        if (wgui_inline_item_highlighted_index < first_display 
            || wgui_inline_item_highlighted_index > last_display)
        {
            UI_inputbox_move_cursor(0, 0, -1, -1, -1, -1);
        }
    }

#endif

}


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_smooth_scrolling_by_pen
 * DESCRIPTION
 *  set whether ssp call this redraw.
 * PARAMETERS
 *  state     [IN]         indicate whether in ssp state
 * RETURNS
 *  void 
 *****************************************************************************/
void wgui_inline_set_ssp_redraw_state(MMI_BOOL state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ssp_redraw = state;
}

/*****************************************************************************
 * FUNCTION
 *  wgui_inline_restore_history
 * DESCRIPTION
 *  restore the inline history
 * PARAMETERS
 *  gui_buffer          [OUT]       the gui_buffer history
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_restore_history(U8* gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (wgui_current_inline_item_type)
    {

        case INLINE_ITEM_TYPE_DATE:
#if defined(__MMI_INLINE_ITEM_DATE__)            
            inline_date_edit_get_history(gui_buffer);
#endif
            break;

        case INLINE_ITEM_TYPE_TIME:
#if defined(__MMI_INLINE_ITEM_TIME__)             
            inline_time_edit_get_history(gui_buffer);
#endif
            break;

        case INLINE_ITEM_TYPE_TIME_PERIOD:
#if defined (__MMI_INLINE_ITEM_TIME_PEROID__)            
            inline_time_period_edit_get_history(gui_buffer);
#endif
            break;

        case INLINE_ITEM_TYPE_IP4_EDIT:
#ifdef __MMI_INLINE_ITEM_IP4__          
            inline_IP4_edit_get_history(gui_buffer);
#endif
            break;

        case INLINE_ITEM_TYPE_DOW_SELECT:
#ifdef __MMI_INLINE_ITEM_DOW__            
            inline_DOW_select_change_complete();
            inline_DOW_select_get_history(gui_buffer);
#endif            
            break;
#if defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__)             
        case INLINE_ITEM_TYPE_MULTI_LINE_EDIT:
        case INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY:
            inline_multi_line_edit_get_history(gui_buffer);
            break;
#endif            
        
        default:
            return;
    }
    
    
    wgui_current_history_buffer = gui_buffer;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  handle_inline_item_location
 * DESCRIPTION
 *  handle inline item's location
 * PARAMETERS
 *  x           [IN]        left corner's x coordinate
 *  y           [IN]        left corner's y coordinate
 *  width       [IN]        width
 *  height      [IN]        height
 * RETURNS
 *  void
 *****************************************************************************/
void handle_inline_item_location(S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 item_index;

#ifdef __MMI_FTE_SUPPORT__
    U8 gui_buffer[MAX_GUI_BUFFER];
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_inline_item_handled)
    {
#ifdef __MMI_FTE_SUPPORT__
        if (!g_ssp_redraw)
#endif
        return;
    }  

#ifdef __MMI_FTE_SUPPORT__
     if (wgui_inline_item_handled && g_ssp_redraw)
     {
         mmi_imc_config_draw(MMI_TRUE);

         wgui_inline_restore_history(gui_buffer);
     }
    
    g_ssp_redraw = MMI_FALSE;
#endif

#ifdef __MMI_FTE_SUPPORT__
    width = width - INLINE_FTE_SCROLL_BAR_WIDTH ;
    if(WGUI_INLINE_ITEM_TYPE(wgui_inline_item_highlighted_index) != INLINE_ITEM_TYPE_CAPTION)
    {
        if((WGUI_INLINE_ITEM_TYPE(wgui_inline_item_highlighted_index) != INLINE_ITEM_TYPE_MULTI_LINE_EDIT) &&
           (WGUI_INLINE_ITEM_TYPE(wgui_inline_item_highlighted_index) != INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY) 
          )
        {
            y = y + INLINE_FTE_CONTROL_VERTICAL_GAP(height);
            height = INLINE_FTE_CONTROL_HEIGHT;
        }
        else
        {
            y = y + INLINE_FTE_CONTROL_VERTICAL_GAP(INLINE_FTE_ONE_LINE_HEIGHT);
            height -= 2 * INLINE_FTE_CONTROL_VERTICAL_GAP(INLINE_FTE_ONE_LINE_HEIGHT);
        }
    }
    if(wgui_inline_items[wgui_inline_item_highlighted_index].side_img !=NULL)
    {
        if(mmi_fe_get_r2l_state())
        {
            x += INLINE_FTE_SCROLL_BAR_WIDTH;
            width = width -  (INLINE_FTE_ICON_SIZE + INLINE_FTE_ICON_CONTROL_GAP + INLINE_FTE_LEFT_GAP);
        }
        else
        {
            x += INLINE_FTE_ICON_SIZE + INLINE_FTE_ICON_CONTROL_GAP + INLINE_FTE_LEFT_GAP; 
            width -= x + 1;
        }

    }
    else
    {
        if(mmi_fe_get_r2l_state())
        {
            x += INLINE_FTE_SCROLL_BAR_WIDTH;
            width = width -  (INLINE_FTE_ICON_CONTROL_GAP + INLINE_FTE_LEFT_GAP); 
        }
        else
        {
            x += INLINE_FTE_ICON_CONTROL_GAP + INLINE_FTE_LEFT_GAP;
            width -= x + 1;
        }
        
    }
#endif

    wgui_inline_item_handled = 1;
    wgui_inline_item_x = x;
    wgui_inline_item_y = y;
    wgui_inline_item_width = width;
    wgui_inline_item_height = height;
    item_index = wgui_inline_item_highlighted_index;


    if (wgui_inline_items[item_index].key_code == INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT)
    {
        gdi_layer_lock_frame_buffer();
        wgui_text_menuitem_reset_scrolling = gui_fixed_icontext_menuitem_stop_scroll;
        wgui_text_menuitem_restart_scrolling = gui_fixed_icontext_menuitem_start_scroll;
        if ((WGUI_INLINE_ITEM_TYPE(item_index) != INLINE_ITEM_TYPE_DISPLAY_ONLY)
			&& (WGUI_INLINE_ITEM_TYPE(item_index) != INLINE_ITEM_TYPE_TEXT_EDIT)
			&& (WGUI_INLINE_ITEM_TYPE(item_index) != INLINE_ITEM_TYPE_FULL_SCREEN_EDIT))
        {
            wgui_text_menuitem_reset_scrolling();
        }
        wgui_inline_items[item_index].handler(
                                        wgui_inline_item_x,
                                        wgui_inline_item_y,
                                        wgui_inline_item_width,
                                        wgui_inline_item_height,
                                        wgui_inline_items[item_index].key_code,
                                        wgui_inline_items[item_index].key_event,
                                        &wgui_inline_items[item_index].text_p,
                                        wgui_inline_items[item_index].item,
                                        wgui_inline_items[item_index].flags,
                                        wgui_current_history_buffer);
        wgui_current_history_buffer = NULL;
        gdi_layer_unlock_frame_buffer();
    }
#if defined (__MMI_INLINE_ITEM_IMAGETEXT__)    
    else if (WGUI_INLINE_ITEM_TYPE(item_index) == INLINE_ITEM_IMAGE_TEXT_TYPE)
    {
        wgui_text_menuitem_reset_scrolling();
        inline_image_text_set_history(INLINE_IMAGE_TEXT_HISTORY_ID, wgui_current_history_buffer);
        if (inline_image_text_edit_flag == 1)
        {
            wgui_inline_items[item_index].handler(
                                            wgui_inline_item_x,
                                            wgui_inline_item_y,
                                            wgui_inline_item_width,
                                            wgui_inline_item_height,
                                            wgui_inline_items[item_index].key_code,
                                            wgui_inline_items[item_index].key_event,
                                            &wgui_inline_items[item_index].text_p,
                                            wgui_inline_items[item_index].item,
                                            wgui_inline_items[item_index].flags,
                                            wgui_current_history_buffer);
            wgui_current_history_buffer = NULL; /* 112105 inline Calvin added */
        }
        else
        {
            if ((wgui_inline_items[item_index].flags & INLINE_ITEM_DISABLE_HIGHLIGHT))
            {
                gui_draw_filled_area(
                    wgui_inline_item_x + 17,
                    wgui_inline_item_y,
                    (wgui_inline_item_x + wgui_inline_item_width - 1),
                    (wgui_inline_item_y + wgui_inline_item_height - 1),
                    (wgui_inline_select_fixed_text_menuitem_theme.selected_filler));
            }
            wgui_show_image_text_item_highlight(
                wgui_inline_item_x,
                wgui_inline_item_y,
                wgui_inline_item_width,
                wgui_inline_item_height,
                &wgui_inline_items[item_index]);
            register_left_softkey_handler();
            register_inline_item_key_handler(item_index);
        }
    }
#endif

    if(cui_inline_is_current_cui())
    {
    	        /*  Watting for bug....
            if Done style is set & Application set CSK function for Selector item, then CSK is overrided by App!!!
            TextEdit & Fullscreen item have no such case, because the CSK is handled by inline before, so App don't set 
            CSK Function for these two items both Done style and Disable style.
        */
        cui_inline_replace_item_softkey_by_app(item_index);
		if ((WGUI_INLINE_ITEM_TYPE(item_index) == INLINE_ITEM_TYPE_TEXT_EDIT)
			|| (WGUI_INLINE_ITEM_TYPE(item_index) == INLINE_ITEM_TYPE_FULL_SCREEN_EDIT))
		{
		    if (!cui_inline_is_item_lsk_by_app(item_index))
		    {
				set_left_softkey_label(get_string(STR_GLOBAL_EDIT));
				register_softkey_handler(MMI_LEFT_SOFTKEY);
				set_softkey_function(wgui_inline_lsk_fs_cui_editor, KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
		    }
		}
        cui_inline_register_csk_handler();
        cui_inline_evt_set_key();
        /* we need csk to handle select item to new radio category screen */
        if (WGUI_INLINE_ITEM_TYPE(item_index) == INLINE_ITEM_TYPE_SELECT)
        {
            register_softkey_handler(MMI_CENTER_SOFTKEY);
            set_softkey_function(wgui_inline_lsk_menu_cui_select, KEY_EVENT_UP, MMI_CENTER_SOFTKEY);
            if (!cui_inline_is_item_lsk_by_app(item_index))
            {
                set_left_softkey_label(get_string(STR_GLOBAL_SELECT));
                register_softkey_handler(MMI_LEFT_SOFTKEY);
                set_softkey_function(wgui_inline_lsk_menu_cui_select, KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
            }
        }
    }   

    if ((wgui_inline_list_menu_rsk_back)
		|| (WGUI_INLINE_ITEM_TYPE(item_index) == INLINE_ITEM_TYPE_FULL_SCREEN_EDIT
			&& (cui_inline_is_current_cui() && (!cui_inline_is_item_lsk_by_app(item_index))))
		|| (WGUI_INLINE_ITEM_TYPE(item_index) == INLINE_ITEM_TYPE_RADIO)
		|| (WGUI_INLINE_ITEM_TYPE(item_index) == INLINE_ITEM_TYPE_CHECKBOX)
		|| (WGUI_INLINE_ITEM_TYPE(item_index) == INLINE_ITEM_TYPE_SELECT
			&& (cui_inline_is_current_cui() && (!cui_inline_is_item_lsk_by_app(item_index))))
		|| (WGUI_INLINE_ITEM_TYPE(item_index) == INLINE_ITEM_TYPE_TEXT_EDIT
			&& (cui_inline_is_current_cui() && (!cui_inline_is_item_lsk_by_app(item_index))))
		)
    {
        wgui_inline_option_handler_for_lsk();
    }

#ifdef __MMI_FTE_SUPPORT__
    mmi_imc_config_draw(MMI_FALSE);
#endif
    redraw_left_softkey();
    redraw_right_softkey();
}


/*****************************************************************************
 * FUNCTION
 *  GetInlineDoneFlag
 * DESCRIPTION
 *  get inline Done flag from history buffer
 * PARAMETERS
 *  history_buffer      [IN]      history buffer
 * RETURNS
 *  DoneFlag
 *****************************************************************************/
U8 GetInlineDoneFlag(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 *flags;
    S32 s = sizeof(list_menu_category_history);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s = (s + 3) / 4;
    s *= 4;
    if (history_buffer == NULL)
    {
        return (0);
    }
    flags = (U32*) (history_buffer + s);
    if (*flags)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetInlineDoneFlag
 * DESCRIPTION
 *  Set inline Done flag into history buffer
 * PARAMETERS
 *  history_buffer      [IN/OUT]     history buffer
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineDoneFlag(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 *flags;
    S32 s = sizeof(list_menu_category_history);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s = (s + 3) / 4;
    s *= 4;
    if (history_buffer == NULL)
    {
        return;
    }
    flags = (U32*) (history_buffer + s);
    *flags = 1;
}


/*****************************************************************************
 * FUNCTION
 *  ResetInlineDoneFlag
 * DESCRIPTION
 *  Rest inline Done flag in history buffer
 * PARAMETERS
 *  history_buffer      [IN/OUT]   history buffer     
 * RETURNS
 *  void
 *****************************************************************************/
void ResetInlineDoneFlag(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 *flags;
    S32 s = sizeof(list_menu_category_history);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s = (s + 3) / 4;
    s *= 4;
    if (history_buffer == NULL)
    {
        return;
    }
    flags = (U32*) (history_buffer + s);
    *flags = 0;
}


/***************************************************************************** 
 * Inline Display Only   
 *
 * This is Display Only Inline Item
 *****************************************************************************/

/***************************************************************************** 
 * Function Implementation
 *****************************************************************************/
 
/*****************************************************************************
 * FUNCTION
 *  wgui_inline_display_only_close
 * DESCRIPTION
 *  close function of inline display only item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_display_only_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    complete_inline_item_edit = UI_dummy_function;
 
    gui_scrolling_text_stop(&wgui_inline_scroll_text);
    clear_inline_item_keys = UI_dummy_function;
    memset(&wgui_inline_scroll_text, 0, sizeof(wgui_inline_scroll_text));

}


/*****************************************************************************
 * FUNCTION
 *  handle_inline_display_only
 * DESCRIPTION
 *  activation function of inline display only
 * PARAMETERS
 *  x                   [IN]        left corner's x coordinate
 *  y                   [IN]        left corner's y coordinate
 *  width               [IN]        width
 *  height              [IN]        height
 *  key_code            [IN]        key code
 *  key_event           [IN]        key event
 *  text_p              [IN]        text pointer
 *  item                [IN]        inline item
 *  flags               [IN]        flags
 *  history_buffer      [IN]        history buffer
 * RETURNS
 *  void
 *****************************************************************************/
void handle_inline_display_only(
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        S32 key_code,
        S32 key_event,
        U8 **text_p,
        void *item,
        U32 flags,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 left_x = 0, right_x= 0;
    S32 left_text_x= 0, right_text_x = 0;
    S32 text_width = 0, text_height = 0;
    UI_font_type ft = {0};
    color text_colr = gui_color(0, 0, 0);
    wgui_inline_item_text_edit *i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(x);
    UI_UNUSED_PARAMETER(y);
    UI_UNUSED_PARAMETER(height);
    UI_UNUSED_PARAMETER(width);
    UI_UNUSED_PARAMETER(key_code);
    UI_UNUSED_PARAMETER(key_event);
    UI_UNUSED_PARAMETER(text_p);
    UI_UNUSED_PARAMETER(item);
    UI_UNUSED_PARAMETER(flags);
    UI_UNUSED_PARAMETER(left_x);

#ifdef  __MMI_FTE_SUPPORT__
    wgui_show_inline_fte_displayonly_item_highlight(
        x,
        y,
        width,
        height,
        &wgui_inline_items[wgui_inline_item_highlighted_index]);
#else

    ft = current_single_line_input_box_theme->text_font;
    gui_set_font(ft);   
    text_colr = MMI_fixed_icontext_menuitem.focussed_text_color;
    gui_set_text_color(text_colr);
	Get_StringWidthHeight((U8*)(*text_p), &text_width, &text_height);    

    if(flags & INLINE_ITEM_RIGHT_JUSTIFY)
    {
        if(mmi_fe_get_r2l_state())
        {
            i = (wgui_inline_item_text_edit*) item;
            right_x = x + width - 1;
            gui_move_text_cursor(right_x, y + (height - text_height)/2);
            gui_print_text((UI_string_type)(*text_p));
        } 
        else 
        {
            i = (wgui_inline_item_text_edit*) item;
            right_x = x + width - 1;
            right_text_x = right_x;
            left_text_x = right_text_x - text_width;   
            gui_move_text_cursor(left_text_x, y + (height - text_height)/2);
            gui_print_text((UI_string_type)((*text_p)));
        }
        UI_UNUSED_PARAMETER(i);
    }
#ifdef __MMI_INLINE_HIGHLIGHT_CAPTION__
	else 
	{
        left_x = x + MMI_fixed_icontext_menuitem.text_x ;
        right_x = x + width - 1;
		if((text_width > (width - MMI_fixed_icontext_menuitem.text_x)))
		{
			text_width = width - MMI_fixed_icontext_menuitem.text_x;
			gui_create_scrolling_text(&wgui_inline_scroll_text, left_x, y + (height - text_height)/2, text_width, text_height, (UI_string_type)(*text_p), wgui_inlinescrolling_timer, wgui_scrolling_text_draw_background, text_colr, text_colr);
			gui_show_scrolling_text(&wgui_inline_scroll_text);
		}
		else
		{
			if(mmi_fe_get_r2l_state())
			{
				right_text_x = right_x;
				gui_move_text_cursor(right_text_x, y + (height - text_height)/2);
				gui_print_text((UI_string_type)(*text_p));
			}
			else
			{
				left_text_x = left_x;
				gui_move_text_cursor(left_text_x, y + (height - text_height)/2);
				gui_print_text((UI_string_type)(*text_p));
			}
        }
	}
#endif /* __MMI_INLINE_HIGHLIGHT_CAPTION__ */

#endif
    complete_inline_item_edit = wgui_inline_display_only_close;
    register_inline_fixed_list_keys();
}

#ifdef __MMI_FTE_SUPPORT__

extern UI_single_line_input_box_theme wgui_inline_singleline_inputbox_focussed_theme;

/*****************************************************************************
 * FUNCTION
 *  wgui_show_inline_fte_displayonly_item_unhighlight
 * DESCRIPTION
 *  display the inline display_only item in unhighlighted status
 * PARAMETERS
 *  x                   [IN]        left corner's x coordinate
 *  y                   [IN]        left corner's y coordinate
 *  width               [IN]        width
 *  height              [IN]        height
 *  item                [IN]        inline item
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_show_inline_fte_displayonly_item_unhighlight(
                S32 x,
                S32 y,
                S32 width,
                S32 height,
                wgui_inline_item *item)
{
   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_show_inline_fte_displayonly_item_unhighlight_ext(
        x,
        y,
        width,
        height,
        item,
        0);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_show_inline_fte_displayonly_item_unhighlight_ext
 * DESCRIPTION
 *  activation function of inline display only
 * PARAMETERS
 *  x                   [IN]        left corner's x coordinate
 *  y                   [IN]        left corner's y coordinate
 *  width               [IN]        width
 *  height              [IN]        height
 *  item                [IN]        inline item
 *  status_flag         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_show_inline_fte_displayonly_item_unhighlight_ext(
                S32 x,
                S32 y,
                S32 width,
                S32 height,
                wgui_inline_item *item,
                U8 status_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 left_text_x= 0;
    S32 text_width = 0, text_height = 0;
    UI_font_type ft = {0};
    color text_colr = gui_color(0, 0, 0);
    U8 * image = NULL;
    UI_filled_area *bg_filler = NULL;
    gdi_handle act_layer;
    U32 item_flags = 0;
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item_flags = wgui_inline_items[MMI_fixed_list_menu.current_displayed_item].flags & 0xff;
    if (item_flags != INLINE_ITEM_TYPE_SELECT)
    {
        wgui_inline_item_text_edit *i = (wgui_inline_item_text_edit *)item->item;
        i->x = x;
        i->y = y;
        i->width = width;
        i->height = height;
        i->status_flag = status_flag;
    }
    else
    {
        wgui_inline_item_select *i = (wgui_inline_item_select *)item->item;
        i->x = x;
        i->y = y;
        i->width = width;
        i->height = height;
        i->status_flag = status_flag;
    }
    
    gdi_layer_push_clip();
    gdi_layer_get_active(&act_layer);
    
    if (MMI_fixed_list_menu.act_layer_handle == act_layer)
    {
        gdi_layer_set_clip(
        MMI_fixed_list_menu.x, 
        MMI_fixed_list_menu.y, 
        MMI_fixed_list_menu.x + MMI_fixed_list_menu.width - 1,
        MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1);
        gui_set_clip_preset(x, y, x + width - 1, y + height - 1);
    }
    else
    {
        gui_set_clip(x, y, x + width - 1, y + height - 1);
    }

    if(item->flags & INLINE_ITEM_DISPLAY_ONLY_SHOW)
    {
        image = (U8*) GetImage(IMG_INLINE_DISPLAY_ONLY_NORMAL_BG);
        gdi_image_draw_resized(x, y, width, height, image);
    }
    else
    {
        if(status_flag == 0)
        {
            bg_filler = current_MMI_theme->inline_item_button_unhighlighted_normal_bg_filler;     
        }
        else
        {
            bg_filler = current_MMI_theme->inline_item_button_unhighlighted_pressed_bg_filler;       
        }

        gui_draw_filled_area(x, y, x + width - 1, y + height - 1, bg_filler);
    }

    
    ft = wgui_inline_singleline_inputbox_focussed_theme.text_font;
    gui_set_font(ft);
    text_colr = wgui_inline_singleline_inputbox_focussed_theme.normal_text_color;
    gui_set_text_color(text_colr);  
    Get_StringWidthHeight(item->text_p, &text_width, &text_height);
    
    if(text_width > (width - INLINE_FTE_BUTTON_RIGHT_BOUNDARY - INLINE_FTE_SINGLELINE_TEXT_OFFSET))
    {
        text_width = width - INLINE_FTE_BUTTON_RIGHT_BOUNDARY - INLINE_FTE_SINGLELINE_TEXT_OFFSET;
    }
    
    if(mmi_fe_get_r2l_state())
    {
        S32 right_text_x = x + (width - INLINE_FTE_BUTTON_RIGHT_BOUNDARY - INLINE_FTE_SINGLELINE_TEXT_OFFSET) - 1;
        gui_print_truncated_text(right_text_x, y + (height - text_height)/2, text_width, (UI_string_type)(item->text_p));
    }
    else 
    {
        left_text_x = x + INLINE_FTE_SINGLELINE_TEXT_OFFSET;
        gui_print_truncated_text(left_text_x, y + (height - text_height)/2, text_width, (UI_string_type)(item->text_p));
    }
       

    gdi_layer_blt_previous(x, y, x + width, y + height);
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_show_inline_fte_displayonly_item_highlight
 * DESCRIPTION
 *  highlight function of inline display only and fullscreen edit
 * PARAMETERS

 * RETURNS
 *  void
 *****************************************************************************/
void wgui_show_inline_fte_displayonly_item_highlight(
                S32 x,
                S32 y,
                S32 width,
                S32 height,
                wgui_inline_item *item)
{
   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    wgui_show_inline_fte_displayonly_item_highlight_ext(
                x,
                y,
                width,
                height,
                item,
                0);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_show_inline_fte_displayonly_item_highlight_ext
 * DESCRIPTION
 *  highlight function of inline display only and fullscreen edit
 * PARAMETERS

 * RETURNS
 *  void
 *****************************************************************************/
void wgui_show_inline_fte_displayonly_item_highlight_ext(
                S32 x,
                S32 y,
                S32 width,
                S32 height,
                wgui_inline_item *item,
                U8 status_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 left_text_x= 0;
    S32 text_width = 0, text_height = 0;
    UI_font_type ft = {0};
    color text_colr = gui_color(0, 0, 0);
    U8 * image = NULL;
    UI_filled_area *bg_filler = NULL;
	U32 item_flags = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item_flags = wgui_inline_items[wgui_inline_item_highlighted_index].flags & 0xff;
    if (item_flags != INLINE_ITEM_TYPE_SELECT)
    {
        wgui_inline_item_text_edit *i = (wgui_inline_item_text_edit *)item->item;
        i->x = x;
        i->y = y;
        i->width = width;
        i->height = height;
        i->status_flag = status_flag;
    }
    else
    {
        wgui_inline_item_select *i = (wgui_inline_item_select *)item->item;
        i->x = x;
        i->y = y;
        i->width = width;
        i->height = height;
        i->status_flag = status_flag;
    }

    clear_inline_item_keys = wgui_inline_display_only_close;
    if((item->flags & INLINE_ITEM_DISPLAY_ONLY_SHOW))
    {
        image = (U8*) GetImage(IMG_INLINE_DISPLAY_ONLY_HIGHLIGHT_BG);
        gdi_image_draw_resized(x, y, width, height, image);
    }
    else 
    {
        if(status_flag == 0)
        {
            bg_filler = current_MMI_theme->inline_item_button_highlighted_normal_bg_filler;     
        }
        else
        {
            bg_filler = current_MMI_theme->inline_item_button_highlighted_pressed_bg_filler;       
        }

        gui_draw_filled_area(x, y, x + width - 1, y + height - 1, bg_filler);
    }
    
    ft = wgui_inline_singleline_inputbox_focussed_theme.text_font;
    gui_set_font(ft);
    text_colr = wgui_inline_singleline_inputbox_focussed_theme.normal_text_color;
    gui_set_text_color(text_colr);  
    
    Get_StringWidthHeight(item->text_p, &text_width, &text_height);
    left_text_x = x + INLINE_FTE_SINGLELINE_TEXT_OFFSET;
    if((text_width > (width - INLINE_FTE_BUTTON_RIGHT_BOUNDARY - INLINE_FTE_SINGLELINE_TEXT_OFFSET)))
    {
        text_width = width - INLINE_FTE_BUTTON_RIGHT_BOUNDARY - INLINE_FTE_SINGLELINE_TEXT_OFFSET;
        gui_create_scrolling_text(&wgui_inline_scroll_text, left_text_x, y + (height - text_height)/2, text_width, text_height, (UI_string_type)(item->text_p), wgui_inlinescrolling_timer, wgui_scrolling_text_draw_background, text_colr, text_colr);
        gui_show_scrolling_text(&wgui_inline_scroll_text);
    }
    else
    {
        if(mmi_fe_get_r2l_state())
        {      
            S32 right_text_x = x + (width - INLINE_FTE_BUTTON_RIGHT_BOUNDARY - INLINE_FTE_SINGLELINE_TEXT_OFFSET) - 1;
            gui_move_text_cursor(right_text_x, y + (height - text_height)/2);
            gui_print_text((UI_string_type)(item->text_p)); 
        }
        else 
        {
            gui_move_text_cursor(left_text_x, y + (height - text_height)/2);
            gui_print_text((UI_string_type)(item->text_p));
        }
    }
    gdi_layer_blt_previous(x, y, x + width, y + height);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_show_inline_fte_caption_item
 * DESCRIPTION
 *  highlight function of inline caption
 * PARAMETERS

 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_show_inline_fte_caption_item(
                S32 x,
                S32 y,
                S32 width,
                S32 height,
                wgui_inline_item *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 text_x= 0;
    S32 text_width = 0, text_height = 0;
    UI_font_type ft = {0};
    color text_colr = gui_color(0, 0, 0);
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    ft = current_single_line_input_box_theme->text_font;
    gui_set_font(ft);
    text_colr = MMI_fixed_icontext_menuitem.normal_text_color;
    gui_set_text_color(text_colr);  
    Get_StringWidthHeight(item->text_p, &text_width, &text_height);
    
    if(mmi_fe_get_r2l_state())
    {
        text_x = x + width - 1 -  INLINE_FTE_SINGLELINE_TEXT_OFFSET;
        gui_move_text_cursor(text_x, y + (height - text_height)/2);
        gui_print_text((UI_string_type)(item->text_p));
    }
    else 
    {
        text_x = x + INLINE_FTE_SINGLELINE_TEXT_OFFSET;
        gui_move_text_cursor(text_x, y + (height - text_height)/2);
        gui_print_text((UI_string_type)(item->text_p));
    }
}


/*****************************************************************************
 * FUNCTION
 *  inline_fte_displayonly_item_pen_handler
 * DESCRIPTION
 *  highlight function of inline caption
 * PARAMETERS

 * RETURNS
 *  void
 *****************************************************************************/
BOOL inline_fte_displayonly_item_pen_handler( 
                mmi_pen_event_type_enum pen_event,
                S16 x,
                S16 y,
                gui_inline_pen_enum *inline_event,
                U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret = MMI_FALSE;
	S32 i_x, i_y, i_width, i_height;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *inline_event = GUI_INLINE_PEN_NONE;

    if ((wgui_inline_items[index].flags & 0xFF) != INLINE_ITEM_TYPE_SELECT)
    {
        wgui_inline_item_text_edit * i = (wgui_inline_item_text_edit*)wgui_inline_items[index].item;
        i_x = (S32)i->x;
        i_y = (S32)i->y;
        i_width = (S32)i->width;
        i_height = (S32)i->height;
    }
    else
    {
        wgui_inline_item_select *i = (wgui_inline_item_select*)wgui_inline_items[index].item;
        i_x = (S32)i->x;
        i_y = (S32)i->y;
        i_width = (S32)i->width;
        i_height = (S32)i->height;		
    }

     switch (pen_event)
    {
        case MMI_PEN_EVENT_DOWN:
        {
            if (PEN_CHECK_BOUND(x, y, i_x, i_y, i_width, i_height))
            {
                if(index == wgui_inline_item_highlighted_index)
                {
                    wgui_show_inline_fte_displayonly_item_highlight_ext(i_x, i_y, 
                        i_width, i_height, 
                        &wgui_inline_items[index], 
                        1);     
                }
                else
                {
                     wgui_show_inline_fte_displayonly_item_unhighlight_ext(i_x, i_y, 
                        i_width, i_height, 
                        &wgui_inline_items[index], 
                        1);     
                }
                return MMI_TRUE;
            }
            else
            {
                return MMI_FALSE;
            }
            
        }       

        case MMI_PEN_EVENT_MOVE:
        {
            if (!PEN_CHECK_BOUND(x, y, i_x, i_y, i_width, i_height))
            {
                if(index == wgui_inline_item_highlighted_index)
                {
                    wgui_show_inline_fte_displayonly_item_highlight_ext(i_x, i_y, 
                        i_width, i_height, 
                        &wgui_inline_items[index], 
                        0);     
                }
                else
                {
                     wgui_show_inline_fte_displayonly_item_unhighlight_ext(i_x, i_y, 
                        i_width, i_height, 
                        &wgui_inline_items[index], 
                        0);     
                }
                return MMI_FALSE; 
            }
            else 
            {
                return MMI_TRUE; 
            }
            
        }

        case MMI_PEN_EVENT_UP:
        {
            if (PEN_CHECK_BOUND(x, y, i_x, i_y, i_width, i_height))
            {
                if(index == wgui_inline_item_highlighted_index)
                {
                    wgui_show_inline_fte_displayonly_item_highlight_ext(i_x, i_y, 
                        i_width, i_height, 
                        &wgui_inline_items[index], 
                        0);     
                #if !defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
                    if ((wgui_inline_items[index].flags & 0xFF) != INLINE_ITEM_TYPE_DISPLAY_ONLY)
                    {
                        *inline_event = GUI_INLINE_PEN_ITEM_SELECTED;
                    }
                #endif /* GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN */
                }
                else
                {
                     wgui_show_inline_fte_displayonly_item_unhighlight_ext(i_x, i_y, 
                        i_width, i_height, 
                        &wgui_inline_items[index], 
                        0);     
                }
                return MMI_TRUE;
            }
            else if(wgui_inline_pen_down_item_index == index)
            {
                if(index == wgui_inline_item_highlighted_index)
                {
                    wgui_show_inline_fte_displayonly_item_highlight_ext(i_x, i_y, 
                        i_width, i_height, 
                        &wgui_inline_items[index], 
                        0);     
                }
            else
            {
                    wgui_show_inline_fte_displayonly_item_unhighlight_ext(i_x, i_y, 
                        i_width, i_height, 
                        &wgui_inline_items[index], 
                        0);     
                }
                return MMI_FALSE;
            }
            break;          
        }

        case MMI_PEN_EVENT_LONG_TAP:
            /* Do Nothing */
            break;

        case MMI_PEN_EVENT_REPEAT:
            /* Do Nothing */
            break;

        case MMI_PEN_EVENT_ABORT:
            /* Do Nothing */
            break;

        default:
            MMI_DBG_ASSERT(0);
    }

    return ret;
}

#endif

/*****************************************************************************
 * FUNCTION
 *  wgui_show_inline_displayonly_item
 * DESCRIPTION
 *  activation function of inline display only
 * PARAMETERS
 *  x                   [IN]        left corner's x coordinate
 *  y                   [IN]        left corner's y coordinate
 *  width               [IN]        width
 *  height              [IN]        height
 *  key_code            [IN]        key code
 *  key_event           [IN]        key event
 *  text_p              [IN]        text pointer
 *  item                [IN]        inline item
 *  flags               [IN]        flags
 *  history_buffer      [IN]        history buffer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_show_inline_displayonly_item(
                S32 x,
                S32 y,
                S32 width,
                S32 height,
                wgui_inline_item *item)
{
   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 left_x = 0, right_x= 0;
    S32 left_text_x= 0, right_text_x = 0;
    S32 text_width = 0, text_height = 0;
    UI_font_type ft = {0};
    color text_colr = gui_color(0, 0, 0);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    left_x = x + MMI_fixed_icontext_menuitem.text_x ;
    right_x = x + width - 1;

    ft = current_single_line_input_box_theme->text_font;
    gui_set_font(ft);
    text_colr = MMI_fixed_icontext_menuitem.normal_text_color;
    gui_set_text_color(text_colr);  
    Get_StringWidthHeight(item->text_p, &text_width, &text_height);

    if(item->flags & INLINE_ITEM_RIGHT_JUSTIFY)
    {

    }
    else
    {
        if(mmi_fe_get_r2l_state())
        {
            right_text_x = right_x;
            gui_move_text_cursor(right_text_x, y + (height - text_height)/2);
            gui_print_text((UI_string_type)(item->text_p));
        }
        else
        {
            left_text_x = left_x;
            gui_move_text_cursor(left_text_x, y + (height - text_height)/2);
            gui_print_text((UI_string_type)(item->text_p));
        }
    }    
    
}

/*****************************************************************************
 * FUNCTION
 *  SetInlineItemDisplayOnly
 * DESCRIPTION
 *  Set the data of inline item display only 
 * PARAMETERS
 *  item        [IN]    inline item's pointer
 *  text_p      [IN]    item's text_p
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineItemDisplayOnly(InlineItem *item, U8 *text_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_text_edit *i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inline_mem_alloc_info[wgui_inline_mem_alloc_number] = item->item = wgui_inline_malloc(sizeof(wgui_inline_item_text_edit));
    wgui_inline_mem_alloc_number++;
    i = (wgui_inline_item_text_edit*) item->item;
    memset(i, 0, sizeof(wgui_inline_item_text_edit));
    i->buffer = text_p;
    item->text_p = text_p;
    item->handler = handle_inline_display_only;
    item->flags = INLINE_ITEM_TYPE_DISPLAY_ONLY;
}


/*****************************************************************************
 * FUNCTION
 *  ReConfigureInlineItemDisplayOnly
 * DESCRIPTION
 *  Re-configure the text_p of inline Display Only item
 * PARAMETERS
 *  item        [IN]    inline item's pointer
 *  text_p      [IN]    item's text_p   
 * RETURNS
 *  void
 *****************************************************************************/
void ReConfigureInlineItemDisplayOnly(InlineItem *item, U8 *text_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((item->flags & 0xff) != INLINE_ITEM_TYPE_DISPLAY_ONLY)
    {
        return;
    }
    item->text_p = text_p;
}


/***************************************************************************** 
 * Inline Caption   
 *
 * This is Caption Inline Item
 *****************************************************************************/

/***************************************************************************** 
 * Function Implementation
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  handle_inline_caption
 * DESCRIPTION
 *  activation function of inline caption
 * PARAMETERS
 *  x                   [IN]        left corner's x coordinate
 *  y                   [IN]        left corner's y coordinate
 *  width               [IN]        width
 *  height              [IN]        height
 *  key_code            [IN]        key code
 *  key_event           [IN]        key event
 *  text_p              [IN]        text pointer
 *  item                [IN]        inline item
 *  flags               [IN]        flags
 *  history_buffer      [IN]        history buffer        
 * RETURNS
 *  void
 *****************************************************************************/
void handle_inline_caption(
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        S32 key_code,
        S32 key_event,
        U8 **text_p,
        void *item,
        U32 flags,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(x);
    UI_UNUSED_PARAMETER(y);
    UI_UNUSED_PARAMETER(height);
    UI_UNUSED_PARAMETER(width);
    UI_UNUSED_PARAMETER(key_code);
    UI_UNUSED_PARAMETER(key_event);
    UI_UNUSED_PARAMETER(text_p);
    UI_UNUSED_PARAMETER(item);
    UI_UNUSED_PARAMETER(flags);
}

#ifdef __MMI_INLINE_HIGHLIGHT_CAPTION__
/*****************************************************************************
 * FUNCTION
 *  wgui_show_inline_caption_item
 * DESCRIPTION
 *  show unhighlight inline Caption item
 * PARAMETERS
 *  x                   [IN]        left corner's x coordinate
 *  y                   [IN]        left corner's y coordinate
 *  width               [IN]        width
 *  height              [IN]        height
 *  item                [IN]        inline item
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_show_inline_caption_item(
                S32 x,
                S32 y,
                S32 width,
                S32 height,
                wgui_inline_item *item)
{
   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 left_x = 0, right_x= 0;
    S32 left_text_x= 0, right_text_x = 0;
    S32 text_width = 0, text_height = 0;
    UI_font_type ft = {0};
    color text_colr = gui_color(0, 0, 0);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if(MMI_fixed_list_menu.current_displayed_item == wgui_inline_should_hl_caption_index)
	{
	    S32 next_item_heigh;
		S32 x1, y1, x2, y2;
        UI_filled_area * f ;

		next_item_heigh = wgui_get_inline_item_height(MMI_fixed_list_menu.current_displayed_item + 1);
		x1 = x-2;
		y1 = y;
		x2 = width+2;
		y2 = y + next_item_heigh + height;

        f = wgui_inline_fixed_icontext_menuitem_theme.focussed_filler;
		gui_draw_filled_area(x1, y1, x2, y2, f);
           
	}

    left_x = x + MMI_fixed_icontext_menuitem.text_x ;
    right_x = x + width - 1;

    ft = current_single_line_input_box_theme->text_font;
    gui_set_font(ft);
    text_colr = MMI_fixed_icontext_menuitem.normal_text_color;
    gui_set_text_color(text_colr);  
    Get_StringWidthHeight(item->text_p, &text_width, &text_height);
     
    if(mmi_fe_get_r2l_state())
    {
        right_text_x = right_x;
        gui_move_text_cursor(right_text_x, y + (height - text_height)/2);
        gui_print_text((UI_string_type)(item->text_p));
    }
    else
    {
        left_text_x = left_x;
        gui_move_text_cursor(left_text_x, y + (height - text_height)/2);
        gui_print_text((UI_string_type)(item->text_p));
    }
}    
#endif

/*****************************************************************************
 * FUNCTION
 *  SetInlineItemCaption
 * DESCRIPTION
 *  Set data of inline Caption item
 * PARAMETERS
 *  item        [IN]    inline item's pointer
 *  text_p      [IN]    item's text_p      
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineItemCaption(InlineItem *item, U8 *text_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item->item = NULL;
    item->text_p = text_p;
    item->handler = handle_inline_caption;
    item->flags = INLINE_ITEM_TYPE_CAPTION;
}


/*****************************************************************************
 * FUNCTION
 *  ReconfigureInlineItemCaption
 * DESCRIPTION
 *  Re-configure inline Caption item
 * PARAMETERS
 *  item        [IN]    inline item's pointer
 *  text_p      [IN]    item's text_p      
 * RETURNS
 *  void
 *****************************************************************************/
void ReconfigureInlineItemCaption(InlineItem *item, U8 *text_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((item->flags & 0xff) != INLINE_ITEM_TYPE_CAPTION)
    {
        return;
    }
    item->text_p = text_p;
}


/***************************************************************************** 
 * Inline Text Edit   
 *
 * This is Text Edit Inline Item
 *****************************************************************************/

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MAX_INLINE_TEXT_EDIT_ITEMS                   20


/***************************************************************************** 
 * Typedef 
 *****************************************************************************/


/***************************************************************************** 
 * Local Variable
 *****************************************************************************/
static wgui_inline_item_text_edit *current_wgui_inline_text_edit_item;
static PU8 *current_wgui_inline_text_edit_text_p;
static S32 n_inline_text_edit_items = 0;
static UI_character_type inline_text_edit_mask_character = (UI_character_type) '*';

static U8 inline_text_edit_RSK_label_clear = 0;
#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
#if defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__)
static UI_string_type inline_text_edit_RSK_label_string;
#endif
#endif

//static single_line_input_box wgui_inline_text_edit_display_inputbox;
static S32   g_inline_text_gap_with_list;

/* Because when calling redraw_fixed_list() the editor will be re-created, 
 * all the status will be reset, so we must keep some status and set them back to
 * the editor if we need*/
static mmi_editor_inputbox_sub_type_enum g_inline_current_inline_item_type = MMI_EDITOR_MAX_SUB_INPUT_BOX;
static MMI_BOOL g_is_item_info_kept = MMI_FALSE;
static void * g_inline_current_input_box_handler = NULL;
static void * g_inline_current_editor_handle = NULL;
static MMI_BOOL g_inline_redraw_entered = MMI_FALSE;
static S16 g_inline_time_current_focus = 0;
static S16 g_inline_time_current_position = 0;
static U32 g_inline_time_flags = 0;
static S16 g_inline_date_current_focus = 0;
static S16 g_inline_date_current_position = 0;
static U32 g_inline_date_flags = 0;
#if defined (__MMI_INLINE_ITEM_TIME_PEROID__)
static S16 g_inline_time_period_current_focus = 0;
static S16 g_inline_time_period_current_position = 0;
static U32 g_inline_time_period_flags = 0;
#endif
#if defined (__MMI_INLINE_ITEM_IP4__)
static S16 g_inline_IP4_current_focus = 0;
static S16 g_inline_IP4_current_position = 0;
static U32 g_inline_IP4_flags = 0;
#endif

#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
#if defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__)
static S16 g_inline_multiline_current_position = 0;
static S32 g_inline_multiline_text_offset_x = 0;
static S32 g_inline_multiline_available_length = 0;
static MMI_BOOL g_is_inline_multiline_highlighted = MMI_FALSE;
static UI_buffer_type g_is_inline_multiline_highlight_start_position = NULL;
static UI_buffer_type g_is_inline_multiline_highlight_end_position = NULL;
static U32 g_is_inline_multiline_flags = 0;
static multi_line_input_box g_inline_multiline_backup_struct;
static UI_buffer_type g_inline_multiline_input_mode_cursor_p = NULL;
static UI_buffer_type g_inline_multiline_input_start_cursor_p = NULL;
#endif
#endif


static UI_filled_area temp_inline_edit_background_filler = {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    NULL,
    NULL,
#ifdef __MMI_DEFAULT_THEME_3__
    {206, 206, 206, 100},
#else 
    {167, 232, 93, 100},
#endif 
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

static UI_filled_area temp_inline_edit_background_filler2 = {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    NULL,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

static UI_filled_area temp_inline_edit_background_filler3 = {UI_FILLED_AREA_TYPE_COLOR,
    NULL,
    NULL,
    {167, 232, 93, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/* Filler used for focussed inputbox   with boundary  */
UI_single_line_input_box_theme wgui_inline_singleline_inputbox_focussed_theme = { &temp_inline_edit_background_filler,
    &temp_inline_edit_background_filler,
    &temp_inline_edit_background_filler,
    {0, 0, 0, 100},
    {128, 128, 128, 100},
    {0, 0, 0, 100},
    {255, 255, 255, 100},
    {51, 88, 171, 100},
    {255, 0, 0, 100},
    &MMI_default_font,
    1,
    UI_SINGLE_LINE_INPUT_BOX_CENTER_Y,
    '*'
};

/* Filler used for unfocussed inputbox with boundary  */
UI_single_line_input_box_theme wgui_inline_singleline_inputbox_unfocussed_theme =
    { &temp_inline_edit_background_filler2,
    &temp_inline_edit_background_filler2,
    &temp_inline_edit_background_filler2,
    {0, 0, 0, 100},
    {128, 128, 128, 100},
    {0, 0, 0, 100},
    {255, 255, 255, 100},
    {51, 88, 171, 100},
    {255, 0, 0, 100},
    &MMI_default_font,
    1,
    UI_SINGLE_LINE_INPUT_BOX_CENTER_Y,
    '*'
};

/* Filler used for inputbox without boundary */
UI_single_line_input_box_theme wgui_inline_singleline_inputbox_no_boundary_theme =
    { &temp_inline_edit_background_filler3,
    &temp_inline_edit_background_filler3,
    &temp_inline_edit_background_filler3,
    {0, 0, 0, 100},
    {128, 128, 128, 100},
    {0, 0, 0, 100},
    {255, 255, 255, 100},
    {51, 88, 171, 100},
    {255, 0, 0, 100},
    &MMI_default_font,
    1,
    UI_SINGLE_LINE_INPUT_BOX_CENTER_Y,
    '*'
};



/***************************************************************************** 
 * Function Implementation
 *****************************************************************************/

#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
/*****************************************************************************
 * FUNCTION
 *  inline_item_default_text_show_background
 * DESCRIPTION
 *  show the background of the inline menu item in case of
 *  default text effect.
 * PARAMETERS
 *  x1      [IN]        Start x position
 *  y1      [IN]        Start y position
 *  x2      [IN]        End x position
 *  y2      [IN]        End y position
 * RETURNS
 *  void
 *****************************************************************************/
static void inline_item_default_text_show_background(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    gui_draw_filled_area(x1, y1, x2, y2, &temp_inline_edit_normal_filler);
    gui_pop_clip();
}

#endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 



/*****************************************************************************
 * FUNCTION
 *  UI_dummy_edit_complete_handler
 * DESCRIPTION
 *  Dummy edit complete handler
 * PARAMETERS
 *  buffer          [IN]    buffer pointer         
 *  buffer_size     [IN]    the size of buffer    
 * RETURNS
 *  void
 *****************************************************************************/
void UI_dummy_edit_complete_handler(U8 *buffer, S32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(buffer);
    UI_UNUSED_PARAMETER(buffer_size);
}


/*****************************************************************************
 * FUNCTION
 *  inline_edit_prepare_mask_buffer
 * DESCRIPTION
 *  prepare mask buffer 
 * PARAMETERS
 *  buffer1     [IN]     input buffer 
 *  buffer2     [OUT]    output buffer with mask character 
 * RETURNS
 *  void
 *****************************************************************************/
static void inline_edit_prepare_mask_buffer(U8 *buffer1, U8 *buffer2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type c = (UI_character_type) - 1;
    U16 eos = '\0';

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (!UI_STRING_END_OF_STRING_CHARACTER(c))
    {
        UI_STRING_GET_NEXT_CHARACTER(buffer1, c);
        if (UI_STRING_END_OF_STRING_CHARACTER(c))
        {
            UI_STRING_INSERT_CHARACTER(buffer2, eos);
        }
        else
        {
            UI_STRING_INSERT_CHARACTER(buffer2, inline_text_edit_mask_character);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_show_icon_in_inlineitem
 * DESCRIPTION
 *  Draw icon in inlineitem.
 * PARAMETERS
 *  index           [IN]       index of item in list.Not used now. 
 *  x               [IN]       the x left top coordinate of icon. 
 *  y               [OUT]      the y left top coordinate of icon. 
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_show_icon_in_inlineitem(S32 index, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 icon_width = 0, icon_height = 0;
    S32 m_gap = MMI_INLINE_ICON_RESERVED / 2;
    U32 x_cordinate = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(g_inline_text_gap_with_list == 0)
    {
        g_inline_text_gap_with_list = x;
        gui_measure_image(g_inline_picon, &icon_width, &icon_height);
        g_inline_text_gap_with_list = g_inline_text_gap_with_list + m_gap;
        if(g_inline_picon != NULL)
        {
            gui_show_image(g_inline_text_gap_with_list, y + m_gap, g_inline_picon);
        }
        if((MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_SCROLLBAR) ||
            ((MMI_fixed_list_menu.flags & UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR) && (MMI_fixed_list_menu.displayed_items >= MMI_fixed_list_menu.n_items)))
        {
            g_inline_text_gap_with_list |= 0xff000000;
        }
    }
    else
    {
        if((MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_SCROLLBAR) ||
            ((MMI_fixed_list_menu.flags & UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR) && (MMI_fixed_list_menu.displayed_items >= MMI_fixed_list_menu.n_items)))
        {
            if((g_inline_text_gap_with_list &0xff000000) == 0)
            {
                x_cordinate = x;
                gui_measure_image(g_inline_picon, &icon_width, &icon_height);
                x_cordinate = x_cordinate + m_gap;
                if(g_inline_picon != NULL)
                {
                    gui_show_image(x_cordinate, y + m_gap, g_inline_picon);
                }
    }
            else
            {    
                if(g_inline_picon != NULL)
                {
                    gui_show_image(g_inline_text_gap_with_list - 0xff000000, y + m_gap, g_inline_picon);
                }
            }
        }
        else
        {
            if((g_inline_text_gap_with_list &0xff000000))
            {
                x_cordinate = x;
                gui_measure_image(g_inline_picon, &icon_width, &icon_height);
                x_cordinate = x_cordinate + m_gap;
                if(g_inline_picon != NULL)
                {
                    gui_show_image(x_cordinate, y + m_gap, g_inline_picon);
                }
            }
            else
            {
    if(g_inline_picon != NULL)
    {
        gui_show_image(g_inline_text_gap_with_list, y + m_gap, g_inline_picon);
    }
            }
        }
    }

  
}


/*****************************************************************************
 * FUNCTION
 *  SetInlineIconStyle
 * DESCRIPTION
 *  Set icon style for  inline item. just set for singleline and fullscreen items now.
 * PARAMETERS
 *  item                [IN]       Inline item pointer . 
 *  picon               [OUT]      The pointer of icon . 
 *  b                   [OUT]      flag to indicate whether set or reset.  1-> set 0-> reset. 
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineIconStyle(InlineItem *item, PU8 picon, BOOL b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(((item->flags & 0xff) == INLINE_ITEM_TYPE_TEXT_EDIT)||
               ((item->flags & 0xff) == INLINE_ITEM_TYPE_FULL_SCREEN_EDIT)||
               ((item->flags & 0xff) == INLINE_ITEM_TYPE_CAPTION)||
               ((item->flags & 0xff) == INLINE_ITEM_TYPE_DISPLAY_ONLY)
              );
    if(b == TRUE && picon != NULL)
    {
        g_inline_picon = picon;
        item->flags |= INLINE_ITEM_ICON_IN_ITEM;
        wgui_fixed_list_register_indicator_display_callback(wgui_inline_show_icon_in_inlineitem);
    }
    else if(b == FALSE)
    {
        g_inline_picon = NULL;
        item->flags &= ~INLINE_ITEM_ICON_IN_ITEM;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_get_default_indicator_width
 * DESCRIPTION
 *  Get area size . 
 * PARAMETERS
 *  pwidth                [OUT]      The area width pointer . 
 *  pheight               [OUT]      The area height pointer . 
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_get_default_indicator_width( S32 *pwidth, S32 *pheight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 icon_width = 0, icon_height = 0;  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if(g_inline_picon)
    {          
        gui_measure_image(g_inline_picon, &icon_width, &icon_height);
        *pwidth =  icon_width + MMI_INLINE_ICON_RESERVED;
        *pheight = icon_height + MMI_INLINE_ICON_RESERVED;
    }
    else
    {
        *pwidth = 0;
        *pheight = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetInlineItemTextEdit
 * DESCRIPTION
 *  Set date for inline text edit
 * PARAMETERS
 *  item            [IN]   inline item         
 *  buffer          [IN]   buffer      
 *  buffer_size     [IN]   size of buffer     
 *  input_type      [IN]   input type    
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineItemTextEdit(InlineItem *item, U8 *buffer, S32 buffer_size, U32 input_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInlineItemTextEdit_ext(item, buffer, buffer_size, input_type, 0, NULL);
}   

/*****************************************************************************
 * FUNCTION
 *  SetInlineItemTextEdit_ext
 * DESCRIPTION
 *  Set date for inline text edit
 * PARAMETERS
 *  item            [IN]   inline item         
 *  buffer          [IN]   buffer      
 *  buffer_size     [IN]   size of buffer     
 *  input_type      [IN]   input type    
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineItemTextEdit_ext(InlineItem *item, U8 *buffer, S32 buffer_size, U32 input_type,S16 input_extended_type, mmi_imm_input_mode_enum *required_input_mode_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   SetInlineItemFullScreenEdit_ext2(item, 0, 0, buffer, buffer_size, input_type, input_extended_type, required_input_mode_set);

   item->flags = INLINE_ITEM_TYPE_TEXT_EDIT;
}


/*****************************************************************************
 * FUNCTION
 *  ReConfigureInlineItemTextEdit
 * DESCRIPTION
 *  re-configure inline text edit
 * PARAMETERS
 *  item            [IN]   inline item         
 *  buffer          [IN]   buffer      
 *  buffer_size     [IN]   size of buffer     
 *  input_type      [IN]   input type         
 * RETURNS
 *  void
 *****************************************************************************/
 void ReConfigureInlineItemTextEdit_ext(InlineItem *item, U8 *buffer, S32 buffer_size, U32 input_type,S16 input_extended_type, mmi_imm_input_mode_enum *required_input_mode_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((item->flags & 0xff) != INLINE_ITEM_TYPE_TEXT_EDIT)
    {
        return;  
    }
   
    ReConfigureInlineItemFullScreenEdit_ext(item, 0, 0, buffer, buffer_size, input_type, input_extended_type, required_input_mode_set);

}


#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
/*****************************************************************************
 * FUNCTION
 *  SetInlineItemTextEditDefaultItemNameIfEmpty
 * DESCRIPTION
 *  Sets the pointer item->text_p to point to default item text
 *  if the buffer is empty
 * PARAMETERS
 *  item                [IN]        Is the pointer to InlineItem structure.
 *  default_text_id     [IN]        Is the string Id of the default text.
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineItemTextEditDefaultItemNameIfEmpty_with_string(InlineItem *item, U8 *default_text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_text_edit *i;
    S32 nLen;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = (wgui_inline_item_text_edit*) item->item;
    nLen = mmi_ucs2strlen((const char*) i->buffer);
    
	i->default_item_text = (U8*) default_text;
     
    if ((IsInlineItemDefaultTextEnable()) && (nLen == 0))
    {
        item->text_p = i->default_item_text;
    }
 
}


/*****************************************************************************
 * FUNCTION
 *  SetInlineItemTextEditDefaultItemNameIfEmpty
 * DESCRIPTION
 *  Sets the pointer item->text_p to point to default item text
 *  if the buffer is empty
 * PARAMETERS
 *  item                [IN]        Is the pointer to InlineItem structure.
 *  default_text_id     [IN]        Is the string Id of the default text.
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineItemTextEditDefaultItemNameIfEmpty(InlineItem *item, U16 default_text_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetInlineItemTextEditDefaultItemNameIfEmpty_with_string(item, (U8*) get_string(default_text_id));
}



/*****************************************************************************
 * FUNCTION
 *  EnableInlineItemDefaultText
 * DESCRIPTION
 *  Sets the global flag variable to 1.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EnableInlineItemDefaultText(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_enable_inline_item_default_text = 1;
}


/*****************************************************************************
 * FUNCTION
 *  DisableInlineItemDefaultText
 * DESCRIPTION
 *  Sets the global flag variable to 0.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DisableInlineItemDefaultText(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_enable_inline_item_default_text = 0;
}


/*****************************************************************************
 * FUNCTION
 *  IsInlineItemDefaultTextEnable
 * DESCRIPTION
 *  Check whether the global flag is on or off.
 * PARAMETERS
 *  void
 * RETURNS
 *  1 if the flag is set otherwise 0.
 *****************************************************************************/
U8 IsInlineItemDefaultTextEnable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
    return 0;
#else
    return (wgui_enable_inline_item_default_text == 1);
#endif

}
#endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 


/*****************************************************************************
 * FUNCTION
 *  wgui_show_inline_text_edit_list_menuitem
 * DESCRIPTION
 *  Displaying inline text edit as a menu item in the fixed list menu
 * PARAMETERS
 *  x1          [IN]        x
 *  y1          [IN]        y
 *  width       [IN]        width
 *  height      [IN]        height
 *  item        [IN]        inline item         
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_show_inline_text_edit_list_menuitem(S32 x1, S32 y1, S32 width, S32 height, wgui_inline_item *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FTE_SUPPORT__)
    wgui_show_inline_fte_displayonly_item_unhighlight(x1, y1, width, height, item);
#else /* __MMI_FTE_SUPPORT__ */
    wgui_show_inline_displayonly_item(x1, y1, width, height, item);
#endif /* __MMI_FTE_SUPPORT__ */
}


/***************************************************************************** 
 * FUNCTION
 *  set_leading_zero
 * DESCRIPTION
 *  set the flag whether zero is allowed as first number or not
 * PARAMETERS
 *  operation      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_set_leading_zero_style(wgui_inline_item *item, MMI_BOOL operation)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                 */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if((item->flags & 0xff ) == INLINE_ITEM_TYPE_TEXT_EDIT)
    {
        if(operation == 1)
        {
            item->flags &= ~INLINE_ITEM_NO_LEADING_ZERO;
        }
        else if(operation == 0)
        {
            item->flags |= INLINE_ITEM_NO_LEADING_ZERO;
        }
    }
}


/***************************************************************************** 
 * Inline Full Screen Edit   
 *
 * This is Inline Full Screen Edit  
 *****************************************************************************/

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MAX_INLINE_FULL_SCREEN_TEXT_EDIT_BUFFER_SIZE 512

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/


/***************************************************************************** 
 * Local Variable
 *****************************************************************************/
#if !defined(GUI_EDITOR_SHOW_TITLE)
static S32 full_screen_edit_open = 0;
#endif /* !defined(GUI_EDITOR_SHOW_TITLE) */


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
U8 inline_full_screen_edit_changed = 0;
PU8 wgui_inline_full_screen_text_edit_buffer;


/***************************************************************************** 
 * Extern Global Function
 *****************************************************************************/
extern void wgui_handle_inputbox_input(void);


/***************************************************************************** 
 * Function Implementation
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  SetInlineItemFullScreenEdit_ext2
 * DESCRIPTION
 *  set data for inline full screen edit
 * PARAMETERS
 *  item                     [IN]      inline item   
 *  title                    [IN]      title string  
 *  title_icon               [IN]      title icon  
 *  buffer                   [IN]      buffer   
 *  buffer_size              [IN]      size of buffer  
 *  input_type               [IN]      input type      
 *  input_extended_type      [IN]      input extended type 
 *  required_input_mode_set  [IN]      requried input mode set
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineItemFullScreenEdit_ext2(
        InlineItem *item,
        U16 title,
        U16 title_icon,
        U8 *buffer,
        S32 buffer_size,
        U32 input_type,
        S16 input_extended_type,
        mmi_imm_input_mode_enum *required_input_mode_set
        )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_text_edit *i;
    UI_buffer_type mask_buffer;
    U32 t = input_type & INPUT_TYPE_MASK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(buffer_size <= (WGUI_INLINE_TEXT_EDIT_BUFFER_SIZE / ENCODING_LENGTH));
    
    if (n_inline_text_edit_items >= MAX_INLINE_TEXT_EDIT_ITEMS)
    {
        return;
    }
    wgui_inline_mem_alloc_info[wgui_inline_mem_alloc_number] = item->item = wgui_inline_malloc(sizeof(wgui_inline_item_text_edit));
    wgui_inline_mem_alloc_number++; 
    item->flags = INLINE_ITEM_TYPE_FULL_SCREEN_EDIT;
    n_inline_text_edit_items++;
    i = (wgui_inline_item_text_edit*) item->item;
    memset(i, 0, sizeof(wgui_inline_item_text_edit));
    i->mask_buffer = NULL;
    i->max_lines = 0;
    i->title = title;
    i->title_icon = title_icon;
    i->buffer = buffer;
    i->buffer_size = buffer_size;
    i->flags = 0;
    i->input_type = input_type;
    i->input_ext_type = input_extended_type;
    item->text_p = i->buffer;
    item->handler = handle_inline_display_only;
    i->edit_complete_callback = UI_dummy_edit_complete_handler;
    i->custom_setup_function = NULL;
    i->validation_callback = UI_dummy_validation_function;
    if ((t == IMM_INPUT_TYPE_NUMERIC_PASSWORD) || (t == IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD) ||
        (t == IMM_INPUT_TYPE_SAT_NUMERIC_PASSWORD) || (t == IMM_INPUT_TYPE_ASCII_PASSWORD))
    {
        wgui_inline_mem_alloc_info[wgui_inline_mem_alloc_number] = mask_buffer = (U8*)wgui_inline_malloc(MAX_INLINE_TEXT_EDIT_BUFFER_SIZE * sizeof(U8));
        wgui_inline_mem_alloc_number++; 
        inline_edit_prepare_mask_buffer(buffer, mask_buffer);
        i->mask_buffer = mask_buffer;
        item->text_p = mask_buffer;
    }
    /* UCS2_count==-1 means this field hasn't been edited */
    i->UCS2_count = -1;
    i->required_input_mode_set = required_input_mode_set;
}



/*****************************************************************************
 * FUNCTION
 *  SetInlineItemFullScreenEdit
 * DESCRIPTION
 *  Set data for inline full screen edit
 * PARAMETERS
 *  item            [IN]      inline item   
 *  title           [IN]      title string  
 *  title_icon      [IN]      title icon  
 *  buffer          [IN]      buffer   
 *  buffer_size     [IN]      size of buffer  
 *  input_type      [IN]      input type  
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineItemFullScreenEdit(
        InlineItem *item,
        U16 title,
        U16 title_icon,
        U8 *buffer,
        S32 buffer_size,
        U32 input_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInlineItemFullScreenEdit_ext2(item, title, title_icon, buffer, buffer_size, input_type, 0, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  SetInlineItemFullScreenEdit_ext
 * DESCRIPTION
 *  set data for inline full screen edit
 * PARAMETERS
 *  item                     [IN]      inline item   
 *  title                    [IN]      title string  
 *  title_icon               [IN]      title icon  
 *  buffer                   [IN]      buffer   
 *  buffer_size              [IN]      size of buffer  
 *  input_type               [IN]      input type      
 *  input_extended_type      [IN]      input extended type      
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineItemFullScreenEdit_ext(
        InlineItem *item,
        U16 title,
        U16 title_icon,
        U8 *buffer,
        S32 buffer_size,
        U32 input_type,
        S16 input_extended_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInlineItemFullScreenEdit_ext2(item, title, title_icon, buffer, buffer_size, input_type, input_extended_type, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  ReConfigureInlineItemFullScreenEdit_ext
 * DESCRIPTION
 *  re-configure inline full screen edit
 * PARAMETERS
 *  item            [IN]      inline item   
 *  title           [IN]      title string  
 *  title_icon      [IN]      title icon  
 *  buffer          [IN]      buffer   
 *  buffer_size     [IN]      size of buffer  
 *  input_type      [IN]      input type         
 * RETURNS
 *  void
 *****************************************************************************/
void ReConfigureInlineItemFullScreenEdit_ext(
        InlineItem *item,
        U16 title,
        U16 title_icon,
        U8 *buffer,
        S32 buffer_size,
           U32 input_type,
           S16 input_extended_type,
           mmi_imm_input_mode_enum *required_input_mode_set)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_text_edit *i;
    UI_buffer_type mask_buffer;
    U32 t = input_type & INPUT_TYPE_MASK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((item->flags & 0xff) != INLINE_ITEM_TYPE_FULL_SCREEN_EDIT) &&
        ((item->flags & 0xff) != INLINE_ITEM_TYPE_TEXT_EDIT))
    {
        return;
    }
    i = (wgui_inline_item_text_edit*) item->item;
    mask_buffer = i->mask_buffer;
    i->max_lines = 0;
    i->title = title;
    i->title_icon = title_icon;
    i->buffer = buffer;
    i->buffer_size = buffer_size;
    i->flags = 0;
    i->input_type = input_type;
    item->text_p = i->buffer;
    i->edit_complete_callback = UI_dummy_edit_complete_handler;
    i->custom_setup_function = NULL;
    if ((t == IMM_INPUT_TYPE_NUMERIC_PASSWORD) || (t == IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD) ||
        (t == IMM_INPUT_TYPE_SAT_NUMERIC_PASSWORD) || (t ==IMM_INPUT_TYPE_ASCII_PASSWORD))
    {
        inline_edit_prepare_mask_buffer(buffer, mask_buffer);
        i->mask_buffer = mask_buffer;
        item->text_p = mask_buffer;
    }
    i->input_ext_type = input_extended_type;
    i->required_input_mode_set = required_input_mode_set;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inlinescrolling_timer
 * DESCRIPTION
 *  inline scrolling timer function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inlinescrolling_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_handle_scrolling_text(&wgui_inline_scroll_text);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_scrolling_text_draw_background
 * DESCRIPTION
 *  draw background of scrolling text
 * PARAMETERS
 *  x1      [IN]        left-top corner x1 coordinate      
 *  y1      [IN]        left-top corner y1 coordinate
 *  x2      [IN]        right-bottom corner x2 coordinate
 *  y2      [IN]        right-bottom corner y2 coordinate
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_scrolling_text_draw_background(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__    
    U8 * image = NULL;
    UI_filled_area *bg_filler = NULL;
#endif    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
    if(((wgui_inline_items[wgui_inline_item_highlighted_index].flags & 0xff) == INLINE_ITEM_TYPE_DISPLAY_ONLY) ||
       ((wgui_inline_items[wgui_inline_item_highlighted_index].flags & 0xff) == INLINE_ITEM_TYPE_FULL_SCREEN_EDIT))  
    {
       wgui_inline_item_text_edit *i = (wgui_inline_item_text_edit*) wgui_inline_items[wgui_inline_item_highlighted_index].item;
        if(wgui_inline_items[wgui_inline_item_highlighted_index].flags & INLINE_ITEM_DISPLAY_ONLY_SHOW)
        {
            image = (U8*) GetImage(IMG_INLINE_DISPLAY_ONLY_HIGHLIGHT_BG);
            gdi_image_draw_resized(i->x, i->y, i->width, i->height, image);
        }
        else
        {
            if(i->status_flag == 0)
            {
                bg_filler = current_MMI_theme->inline_item_button_highlighted_normal_bg_filler;         
            }
            else
            {
                bg_filler = current_MMI_theme->inline_item_button_highlighted_pressed_bg_filler;    
            }

            gui_draw_filled_area(i->x, i->y, i->x + i->width - 1, i->y + i->height - 1, bg_filler);
        }    
             
    }
    else if((wgui_inline_items[wgui_inline_item_highlighted_index].flags & 0xff) == INLINE_ITEM_IMAGE_TEXT_TYPE)
    {
       wgui_inline_image_text  *i = (wgui_inline_image_text*) wgui_inline_items[wgui_inline_item_highlighted_index].item;
       bg_filler = current_MMI_theme->inline_item_textedit_highlighted_bg_filler;
       gui_draw_filled_area(i->x, i->y, i->x + i->width - 1, i->y + i->height - 1, bg_filler);   
    }
#else
    gui_draw_filled_area(x1, y1, x2, y2, (wgui_inline_select_fixed_text_menuitem_theme.selected_filler));
#endif
}


/*****************************************************************************
 * FUNCTION
 *  handle_inline_full_screen_edit_complete
 * DESCRIPTION
 *  complete function of inline full screen edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void handle_inline_full_screen_edit_complete(void)
{
   
}


void handle_inline_full_screen_edit_cancel(void)
{
    
}


/*****************************************************************************
 * FUNCTION
 *  handle_inline_full_screen_edit_close
 * DESCRIPTION
 *  close function of inline full screen edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void handle_inline_full_screen_edit_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  
}


/*****************************************************************************
 * FUNCTION
 *  RegisterInlineSelectHighlightHandler
 * DESCRIPTION
 *  register inline select highlight handler
 * PARAMETERS
 *  item        [IN]    inline item         
 *  f           [IN]    highlight handler    
 * RETURNS
 *  void
 *****************************************************************************/
void RegisterInlineSelectHighlightHandler(InlineItem *item, void (*f) (S32 item_index))
{

}


/* It is no useful and should be removed. */
/*****************************************************************************
 * FUNCTION
 *  SetInlineFullScreenEditCustomFunction
 * DESCRIPTION
 *  set custom function of inline full screen edit
 * PARAMETERS
 *  item        [IN]    inline item         
 *  f           [IN]    custom function    
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineFullScreenEditCustomFunction(InlineItem *item, void (*f) (void))
{

}


#if defined __MMI_PLUTO_GPRS__

#if defined (__MMI_INLINE_ITEM_IMAGETEXT__)

/***************************************************************************** 
 * Inline Image Text 
 *
 * This is Image Text Inline item
 *****************************************************************************/

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define  MAX_INLINE_IMAGE_TEXT_ITEMS      10
#define  IMAGE_TEXT_CONTROL_TEXT_X        26
#define  IMAGE_TEXT_CONTROL_TEXT_WIDTH    83


/***************************************************************************** 
 * Local Variable
 *****************************************************************************/
static wgui_inline_image_text *current_image_text_control = NULL;
static S32 n_inline_image_text = 0;


/***************************************************************************** 
 * Local Function
 *****************************************************************************/
static void draw_image_text_control(
        wgui_inline_image_text *control,
        S32 x1,
        S32 y1,
        S32 iwidth,
        S32 iheight,
        PU8 image1,
        PU8 image2,
        PU8 image3,
        U8 *text,
        U8 highlight_flag);
static void wgui_show_image_text_item(S32 x1, S32 y1, S32 iwidth, S32 iheight, wgui_inline_item *item);
static void handle_inline_full_screen_imagetext_edit(
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        S32 key_code,
        S32 key_event,
        U8 **text_p,
        void *item,
        U32 flags,
        U8 *history_buffer);



static UI_string_type inline_full_screen_edit_saved_title = (UI_string_type) NULL;
static UI_string_type inline_full_screen_edit_saved_LSK_label = (UI_string_type) NULL;
static UI_string_type inline_full_screen_edit_saved_RSK_label = (UI_string_type) NULL;
static PU8 inline_full_screen_edit_saved_LSK_icon = (PU8) NULL;
static PU8 inline_full_screen_edit_saved_RSK_icon = (PU8) NULL;
static PU8 inline_full_screen_edit_saved_title_icon = (PU8) NULL;


/***************************************************************************** 
 * Function Implementation
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  redraw_inline_full_screen_edit
 * DESCRIPTION
 *  redraw function of inline full screen edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void redraw_inline_full_screen_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* micha1111, #219 */
#ifdef __MMI_DEFAULT_THEME_3__
    color c = {206, 206, 206, 100};
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();

    /* micha1111 Chicago Feature */
#ifdef __MMI_DEFAULT_THEME_3__
    gdi_layer_reset_clip();
    gui_fill_rectangle(0, 0, UI_device_width - 1, UI_device_height - 1, c);
#else /* __MMI_DEFAULT_THEME_3__ */ 
    if (wgui_is_wallpaper_on_bottom() == MMI_TRUE)
    {
        gdi_draw_solid_rect(0, 0, UI_device_width - 1, UI_device_height - 1, GDI_COLOR_TRANSPARENT);
    }
    else
    {
        clear_screen();
    }
#endif /* __MMI_DEFAULT_THEME_3__ */ 

#ifdef GUI_COMMON_SHOW_STATUS_ICON
#ifdef __MMI_SCREEN_ROTATE__
    if (mmi_frm_is_screen_width_height_swapped())
    {
       // show_title_status_icon();
    }
    else
#endif
    {
        show_title_status_icon();
    }
#endif

#if defined(GUI_EDITOR_SHOW_TITLE)
    draw_title();
#endif

    wgui_show_inputbox();

    show_softkey_background();
    show_left_softkey();
    show_right_softkey();
#if defined(__MMI_TOUCH_SCREEN__)
    /* W05.36 Add Center Soft Key for switching Input Method */
    show_softkey(MMI_CENTER_SOFTKEY);
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    /* for redrawing spelling or candidate boxes */
    if (RedrawSpellingOrCandidateBoxesFunction)
    {
        RedrawSpellingOrCandidateBoxesFunction();
    }


}

extern fixed_icontext_menuitem *GUI_current_fixed_icontext_menuitem_common_data;
extern fixed_icontext_menuitem_type *GUI_current_fixed_icontext_menuitem_data;


/*****************************************************************************
 * FUNCTION
 *  SetInlineFullScreenEditCustomFunctionImageText
 * DESCRIPTION
 *  set custom function for inline imagetext full screen edit
 * PARAMETERS
 *  item        [IN]    inline item         
 *  f           [IN]    custom function    
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineFullScreenEditCustomFunctionImageText(InlineItem *item, void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_image_text *image_item = (wgui_inline_image_text*) item->item;
    wgui_inline_item_text_edit *i = (wgui_inline_item_text_edit*) image_item->inline_full_text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i->custom_setup_function = f;
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  inline_image_text_redraw_image_by_pen
 * DESCRIPTION
 *  redraw inline imagetext's image for pen event 
 * PARAMETERS
 *  i       [IN]    inline image text    
 * RETURNS
 *  void
 *****************************************************************************/
void inline_image_text_redraw_image_by_pen(wgui_inline_image_text *i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = i->pen_down_image_index;
    PU8 image = NULL;   /* 111605 warning Calvin */
    S32 image_y_offset = 0;
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < 0)
    {
        return;
    }

    gdi_layer_push_clip();
    gdi_layer_reset_clip();
    gdi_layer_lock_frame_buffer();

    x1 = i->image_left_top[index].x;
    y1 = i->image_left_top[index].y;
    x2 = i->image_right_bottom[index].x;
    y2 = i->image_right_bottom[index].y;

#ifdef __MMI_FTE_SUPPORT__
    {
        UI_filled_area *f = current_MMI_theme->inline_item_textedit_highlighted_bg_filler;
        gui_draw_filled_area(i->x, i->y, i->x + i->width - 1, i->y + i->height - 1, f);
    }
#else
    gui_draw_filled_area(x1, y1, x2, y2 + 1, wgui_inline_select_fixed_text_menuitem_theme.selected_filler);
#endif

    if (index == i->pen_curr_pressed_image_index)
    {
        image_y_offset++;
    }

    if (index == 0)
    {
        image = i->image2;
    }
    else if (index == 1)
    {
        image = i->image3;
    }
    else
    {
        MMI_ASSERT(0);
    }

    gui_show_transparent_image(x1, y1 + image_y_offset, image, 0);

    gui_pop_clip();

    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(x1, y1, x2, y2 + 1);
}


/*****************************************************************************
 * FUNCTION
 *  inline_image_text_pen_handler
 * DESCRIPTION
 *  pen handler of inline image text
 * PARAMETERS
 *  pen_event       [IN]    pen event    
 *  x               [IN]    pen x position    
 *  y               [IN]    pen y position    
 *  item_event      [IN]    inline pen enum     
 * RETURNS
 *  ret
 *****************************************************************************/
BOOL inline_image_text_pen_handler(
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_inline_item_pen_enum *item_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret = MMI_TRUE;
    wgui_inline_image_text *i = current_image_text_control;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *item_event = GUI_INLINE_ITEM_PEN_NONE;

    if (!i)
    {
        MMI_DBG_ASSERT(0);
        return MMI_FALSE;
    }

    switch (pen_event)
    {
        case MMI_PEN_EVENT_DOWN:
            i->pen_down_image_index = -1;
            if (i->image2 && i->image_callback[0] && x >= i->image_left_top[0].x && y >= i->image_left_top[0].y &&
                x <= i->image_right_bottom[0].x && y <= i->image_right_bottom[0].y)
            {
                i->pen_down_image_index = 0;
                i->pen_curr_pressed_image_index = 0;
                inline_image_text_redraw_image_by_pen(i);
            }
            else if (i->image3 && i->image_callback[1] && x >= i->image_left_top[1].x && y >= i->image_left_top[1].y &&
                     x <= i->image_right_bottom[1].x && y <= i->image_right_bottom[1].y)
            {
                i->pen_down_image_index = 1;
                i->pen_curr_pressed_image_index = 1;
                inline_image_text_redraw_image_by_pen(i);
            }
            else
            {
                ret = MMI_FALSE;
            }
            break;

        case MMI_PEN_EVENT_MOVE:
            if (i->pen_down_image_index >= 0)
            {
                S32 index = i->pen_down_image_index;

                if (i->pen_curr_pressed_image_index == i->pen_down_image_index)
                {
                    if (!(x >= i->image_left_top[index].x && y >= i->image_left_top[index].y &&
                          x <= i->image_right_bottom[index].x && y <= i->image_right_bottom[index].y))
                    {
                        i->pen_curr_pressed_image_index = -1;
                        inline_image_text_redraw_image_by_pen(i);
                    }
                }
                else
                {
                    if (x >= i->image_left_top[index].x && y >= i->image_left_top[index].y &&
                        x <= i->image_right_bottom[index].x && y <= i->image_right_bottom[index].y)
                    {
                        i->pen_curr_pressed_image_index = index;
                        inline_image_text_redraw_image_by_pen(i);
                    }
                }
            }
            break;

        case MMI_PEN_EVENT_UP:
            if (i->pen_down_image_index >= 0 && i->pen_curr_pressed_image_index >= 0)
            {
                i->pen_curr_pressed_image_index = -1;
                inline_image_text_redraw_image_by_pen(i);

                if (i->image_callback[i->pen_down_image_index])
                {
                   // (i->image_callback[i->pen_down_image_index]) ();
                    mmi_event_struct evt;

                    MMI_FRM_INIT_EVENT(&evt, EVT_ID_INLINE_IMAGETEXT_PEN_UP);
                    evt.user_data = (void *)i->image_callback[i->pen_down_image_index];

                    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
                }
            }
            break;

        case MMI_PEN_EVENT_ABORT:
            if (i->pen_down_image_index >= 0 && i->pen_curr_pressed_image_index >= 0)
            {
                i->pen_curr_pressed_image_index = -1;
                inline_image_text_redraw_image_by_pen(i);
            }
            break;

    }

    return ret;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  SetInlineItemImageText
 * DESCRIPTION
 *  set data of linline image text
 * PARAMETERS
 *  item            [IN]      inline item   
 *  text            [IN]      buffer   
 *  image1          [IN]      image 1   
 *  image2          [IN]      image 2  
 *  image3          [IN]      image 3  
 *  buf_size        [IN]      size of buffer  
 *  title           [IN]      title string  
 *  title_icon      [IN]      title icon  
 *  input_type      [IN]      input type  
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineItemImageText(
        InlineItem *item,
        U8 *text,
        PU8 image1,
        PU8 image2,
        PU8 image3,
        S32 buf_size,
        U16 title,
        U16 title_icon,
        U32 input_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_image_text *image_item;
    wgui_inline_item_text_edit *i;
    UI_buffer_type mask_buffer;
    U32 t = input_type & INPUT_TYPE_MASK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (n_inline_image_text >= MAX_INLINE_IMAGE_TEXT_ITEMS)
    {
        return;
    }
    if (n_inline_text_edit_items >= MAX_INLINE_TEXT_EDIT_ITEMS)
    {
        return;
    }
    wgui_inline_mem_alloc_info[wgui_inline_mem_alloc_number] = item->item = wgui_inline_malloc(sizeof(wgui_inline_image_text));
    wgui_inline_mem_alloc_number++; 
    item->flags = INLINE_ITEM_IMAGE_TEXT_TYPE;
    item->show_img_flag = FALSE;
    n_inline_image_text++;
    image_item = (wgui_inline_image_text*) item->item;
    image_item->flags = 0;
    image_item->buffer_size = buf_size;
    image_item->image1 = image1;
    image_item->image2 = image2;
    image_item->image3 = image3;
    image_item->text = text;
    item->handler = handle_inline_full_screen_imagetext_edit;
#ifdef __MMI_TOUCH_SCREEN__
    memset(image_item->image_callback, 0, sizeof(image_item->image_callback));
    memset(image_item->image_left_top, 0, sizeof(image_item->image_left_top));
    memset(image_item->image_right_bottom, 0, sizeof(image_item->image_right_bottom));
    image_item->pen_down_image_index = -1;
    image_item->pen_curr_pressed_image_index = -1;
#endif /* __MMI_TOUCH_SCREEN__ */ 

    wgui_inline_mem_alloc_info[wgui_inline_mem_alloc_number] = image_item->inline_full_text = wgui_inline_malloc(sizeof(wgui_inline_item_text_edit)); 
    wgui_inline_mem_alloc_number++; 
    n_inline_text_edit_items++;
    i = (wgui_inline_item_text_edit*) image_item->inline_full_text;
    i->mask_buffer = NULL;
    i->title = title;
    i->title_icon = title_icon;
    i->buffer = text;
    i->buffer_size = buf_size;
    i->flags = 0;
    i->input_type = input_type;
    item->text_p = i->buffer;
    i->edit_complete_callback = UI_dummy_edit_complete_handler;
    i->custom_setup_function = NULL;
    i->validation_callback = UI_dummy_validation_function;
    if ((t == IMM_INPUT_TYPE_NUMERIC_PASSWORD) || (t == IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD) ||
        (t == IMM_INPUT_TYPE_SAT_NUMERIC_PASSWORD) || (t ==IMM_INPUT_TYPE_ASCII_PASSWORD))
    {
        wgui_inline_mem_alloc_info[wgui_inline_mem_alloc_number] = mask_buffer = (U8*)wgui_inline_malloc(MAX_INLINE_TEXT_EDIT_BUFFER_SIZE * sizeof(U8));
        wgui_inline_mem_alloc_number++;       
        inline_edit_prepare_mask_buffer(text, mask_buffer);
        i->mask_buffer = mask_buffer;
        item->text_p = mask_buffer;
    }
    /* UCS2_count==-1 means this field hasn't been edited */
    i->UCS2_count = -1;

}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  SetInlineImageTextPenHandler
 * DESCRIPTION
 *  set pen handlers of inline image text
 * PARAMETERS
 *  item                [IN]    inline item         
 *  image2_callback     [IN]    image2 callback function    
 *  image3_callback     [IN]    image3 callback function    
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineImageTextPenHandler(InlineItem *item, FuncPtr image2_callback, FuncPtr image3_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_image_text *image_item = (wgui_inline_image_text*) item->item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    image_item->image_callback[0] = image2_callback;
    image_item->image_callback[1] = image3_callback;
}
#endif /* __MMI_TOUCH_SCREEN__ */ 

typedef struct
{
    U16 history_ID;
    U8 is_open;
} inline_image_text_history_struct;

/*****************************************************************************
 * FUNCTION
 *  inline_image_text_get_history
 * DESCRIPTION
 *  get history buffer for inline image text edit
 * PARAMETERS
 *  history_buffer      [OUT]       history buffer  
 * RETURNS
 *  history buffer
 *****************************************************************************/
U8 *inline_image_text_get_history(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        U16 hID = (U16) (INLINE_IMAGE_TEXT_HISTORY_ID | 0x8000);
        inline_image_text_history_struct *h = (inline_image_text_history_struct*) history_buffer;

        h->history_ID = hID;
        h->is_open = inline_image_text_edit_flag;
    }
    return (history_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  inline_image_text_set_history
 * DESCRIPTION
 *  get history buffer for inline image text edit
 * PARAMETERS
 *  history_ID          [IN]        category id
 *  history_buffer      [OUT]       history buffer
 * RETURNS
 *  history buffer
 *****************************************************************************/
U8 inline_image_text_set_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    if (history_buffer != NULL)
    {
        inline_image_text_history_struct *h = (inline_image_text_history_struct*) history_buffer;

        if (history_valid(h->history_ID, history_ID))
        {
            inline_image_text_edit_flag = h->is_open;
            return (1);
        }
    }
    return (0);

}


/*****************************************************************************
 * FUNCTION
 *  wgui_show_image_text_control
 * DESCRIPTION
 *  show image text control
 * PARAMETERS
 *  i       [IN]    inline image text     
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_show_image_text_control(wgui_inline_image_text *i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S32 y1 = i->y ;
    //S32 height = 0;
    wgui_inline_item_text_edit *i_edit = (wgui_inline_item_text_edit*) i->inline_full_text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    draw_image_text_control(i, i->x, i->y, i->width, i->height, i->image1, i->image2, i->image3, i_edit->buffer, 1);

}


/*****************************************************************************
 * FUNCTION
 *  redraw_image_text_control
 * DESCRIPTION
 *  redraw image text control
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void redraw_image_text_control(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    /*
    wgui_scrolling_text_draw_background(
        current_image_text_control->x,
        current_image_text_control->y,
        current_image_text_control->x + current_image_text_control->width - 1,
        current_image_text_control->y + current_image_text_control->height - 1
    );
    */
    wgui_show_image_text_control(current_image_text_control);
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(
        current_image_text_control->x,
        current_image_text_control->y,
        current_image_text_control->x + current_image_text_control->width - 1,
        current_image_text_control->y + current_image_text_control->height - 1);
}



/*****************************************************************************
 * FUNCTION
 *  draw_image_text_control
 * DESCRIPTION
 *  draw image text control
 * PARAMETERS
 *  control             [IN]    inline image text         
 *  x1                  [IN]    left-top corner x1 coordinate    
 *  y1                  [IN]    left-top corner y1 coordinate    
 *  iwidth              [IN]    width    
 *  iheight             [IN]    height    
 *  image1              [IN]    image 1    
 *  image2              [IN]    image 2    
 *  image3              [IN]    image 3    
 *  text                [?]     buffer    
 *  highlight_flag      [IN]    highlight flag    
 * RETURNS
 *  void
 *****************************************************************************/
static void draw_image_text_control(
        wgui_inline_image_text *control,
        S32 x1,
        S32 y1,
        S32 iwidth,
        S32 iheight,
        PU8 image1,
        PU8 image2,
        PU8 image3,
        U8 *text,
        U8 highlight_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = 0, height = 0, char_height = 0, img_y1 = 0, text_y;
    color text_colr = gui_color(0, 0, 0);
    S32 temp_x = x1 + 1;
    S32 text_x = 0, text_width = 0, text_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gdi_layer_reset_clip();
    gui_reset_text_clip();

    gui_set_font(MMI_fixed_icontext_menuitem.text_font);
    
#ifdef __MMI_FTE_SUPPORT__
    if (highlight_flag)
    {
        UI_filled_area *f = current_MMI_theme->inline_item_textedit_highlighted_bg_filler;
        gui_draw_filled_area(x1, y1, x1 + iwidth - 1, y1 + iheight - 1, f);
    }
    else
    {
        UI_filled_area *f = current_MMI_theme->inline_item_textedit_unhighlighted_bg_filler;
        gui_draw_filled_area(x1, y1, x1 + iwidth - 1, y1 + iheight - 1, f);
    }

    temp_x = x1 + INLINE_FTE_SINGLELINE_TEXT_OFFSET;
    if(image2)
    {
        gui_measure_image((PU8) image1, &width, &height);
        img_y1 = (iheight >> 1) - (height >> 1);
        gui_show_transparent_image(temp_x, (y1 + img_y1), image1, 0);
        if (control)
        {
            control->image_left_top[0].x = temp_x;
            control->image_left_top[0].y = y1 + img_y1;
            control->image_right_bottom[0].x = temp_x + width - 1;
            control->image_right_bottom[0].y = y1 + img_y1 + height - 1;
        }
        temp_x +=  width + GUI_COLOR_SELECT_FTE_BOX_BETWEEN_GAP;
        text_x = temp_x;
    }
    else
    {
        text_x = temp_x;
    }

    temp_x = x1 + iwidth -1 - INLINE_FTE_SINGLELINE_TEXT_OFFSET;
    if(image3)
    {
        gui_measure_image(image3, &width, &height);
        temp_x -= width;
        img_y1 = (iheight >> 1) - (height >> 1);
        gui_show_transparent_image(temp_x, (y1 + img_y1), image3, 0);
        if (control)
        {
            control->image_left_top[1].x = temp_x;
            control->image_left_top[1].y = y1 + img_y1;
            control->image_right_bottom[1].x = temp_x + width - 1;
            control->image_right_bottom[1].y = y1 + img_y1 + height - 1;
        }
        temp_x -= GUI_COLOR_SELECT_FTE_BOX_BETWEEN_GAP;
    }
    text_width = temp_x - text_x;
    
    char_height = gui_get_character_height();

    gui_measure_string((UI_string_type) text, &width, &height);
    text_height = height;
    text_y = y1 + (iheight >> 1) - (height >> 1);
    if (highlight_flag)
    {
        text_colr = wgui_inline_singleline_inputbox_focussed_theme.normal_text_color;
        if (width > text_width)
        {
            gui_create_scrolling_text(&wgui_inline_scroll_text, text_x, text_y, text_width + 1, text_height, (UI_string_type) text, wgui_inlinescrolling_timer, wgui_scrolling_text_draw_background, text_colr, text_colr);     /* 031205 Calvin modified */
            gui_show_scrolling_text(&wgui_inline_scroll_text);
        }
        else
        {
            gdi_layer_set_clip(text_x, text_y - 1, text_x + text_width, text_y + text_height + 1);
            gui_move_text_cursor(text_x, text_y);
            gui_set_line_height(text_height);
            gui_set_text_color(text_colr);
            gui_print_text((UI_string_type) text);
        }
    }
    else
    {
        text_colr = wgui_inline_singleline_inputbox_focussed_theme.normal_text_color;
        gdi_layer_set_clip(text_x, text_y - 1, text_x + text_width, text_y + text_height + 1);
        gui_move_text_cursor(text_x, text_y);
        gui_set_line_height(text_height);
        gui_set_text_color(text_colr);
        gui_print_text((UI_string_type) text);
    }
#else
    /* MTK Elvis for R2L characters */
    if (mmi_fe_get_r2l_state())
    {
        temp_x = x1 + iwidth - 1;
        if (image1)
        {
            gui_measure_image((PU8) image1, &width, &height);
            //img_y1 = (MMI_INLINE_EDIT_MENUITEM_HEIGHT >> 1) - (height >> 1);
            temp_x -= width;
            gui_show_transparent_image(temp_x, (y1 + img_y1), image1, 0);

        }
        else
        {
            temp_x = x1 + iwidth - MMI_fixed_icontext_menuitem.text_x;
        }

        if (image3)
        {
            gui_measure_image(image3, &width, &height);
            img_y1 = (MMI_INLINE_EDIT_MENUITEM_HEIGHT >> 1) - (height >> 1);
            temp_x -= (width + 2);
            gui_show_transparent_image(temp_x, (y1 + img_y1), image3, 0);
            text_x = temp_x - 2;
            text_width = iwidth - (UI_device_width - text_x);
        #ifdef __MMI_TOUCH_SCREEN__
            if (control)
            {
                control->image_left_top[1].x = temp_x;
                control->image_left_top[1].y = y1 + img_y1;
                control->image_right_bottom[1].x = temp_x + width - 1;
                control->image_right_bottom[1].y = y1 + img_y1 + height - 1;
            }
        #endif /* __MMI_TOUCH_SCREEN__ */ 
        }
        else
        {
            text_x = temp_x - 1;
            text_width = iwidth - (UI_device_width - text_x) - 2;
        }

        if (image2)
        {
            gui_measure_image(image2, &width, &height);
            img_y1 = (MMI_INLINE_EDIT_MENUITEM_HEIGHT >> 1) - (height >> 1);
            temp_x = (UI_device_width - 1) - iwidth + 2;
            gui_show_transparent_image(temp_x, (y1 + img_y1), image2, 0);
            text_width = text_x - temp_x - 2 - width;
        #ifdef __MMI_TOUCH_SCREEN__
            if (control)
            {
                control->image_left_top[0].x = temp_x;
                control->image_left_top[0].y = y1 + img_y1;
                control->image_right_bottom[0].x = temp_x + width - 1;
                control->image_right_bottom[0].y = y1 + img_y1 + height - 1;
            }
        #endif /* __MMI_TOUCH_SCREEN__ */ 
        }

    }
    else
    {
        if (image1)
        {
            gui_measure_image((PU8) image1, &width, &height);
            img_y1 = (MMI_INLINE_EDIT_MENUITEM_HEIGHT >> 1) - (height >> 1);
           // gui_show_transparent_image(temp_x, (y1 + img_y1), image1, 0);
            temp_x = x1 + width + 4;
        }
        else

    #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
        if (!IsInlineItemDefaultTextEnable())
    #endif 

            temp_x = x1 + MMI_fixed_icontext_menuitem.text_x;
        if (image2)
        {
            gui_measure_image(image2, &width, &height);
            img_y1 = (MMI_INLINE_EDIT_MENUITEM_HEIGHT >> 1) - (height >> 1);
            gui_show_transparent_image(temp_x, (y1 + img_y1), image2, 0);
            text_x = temp_x + width + 2;
            text_width = iwidth - text_x;
        #ifdef __MMI_TOUCH_SCREEN__
            if (control)
            {
                control->image_left_top[0].x = temp_x;
                control->image_left_top[0].y = y1 + img_y1;
                control->image_right_bottom[0].x = temp_x + width - 1;
                control->image_right_bottom[0].y = y1 + img_y1 + height - 1;
            }
        #endif /* __MMI_TOUCH_SCREEN__ */ 
        }
        else
        {
            text_x = temp_x;
            text_width = iwidth - text_x - x1 - 4;
        }
        if (image3)
        {
            gui_measure_image(image3, &width, &height);
            temp_x = x1 + 1 + iwidth - width - 2;
            img_y1 = (MMI_INLINE_EDIT_MENUITEM_HEIGHT >> 1) - (height >> 1);
            gui_show_transparent_image(temp_x, (y1 + img_y1), image3, 0);
            text_width = temp_x - text_x - 2;
        #ifdef __MMI_TOUCH_SCREEN__
            if (control)
            {
                control->image_left_top[1].x = temp_x;
                control->image_left_top[1].y = y1 + img_y1;
                control->image_right_bottom[1].x = temp_x + width - 1;
                control->image_right_bottom[1].y = y1 + img_y1 + height - 1;
            }
        #endif /* __MMI_TOUCH_SCREEN__ */ 
        }

    }
  

    char_height = gui_get_character_height();

    if (highlight_flag)
    {
        gui_set_font((UI_font_type)gui_font_get_type(GUI_FONT_SIZE_LIST_HIGHLIGHT));
    }
    gui_measure_string((UI_string_type) text, &width, &height);
    text_height = height;
    text_y = y1 + (MMI_INLINE_EDIT_MENUITEM_HEIGHT >> 1) - (height >> 1);
    if (highlight_flag)
    {
        text_colr = MMI_fixed_icontext_menuitem.focussed_text_color;
        if (width > text_width)
        {
            if (mmi_fe_get_r2l_state())
            {
                gui_create_scrolling_text(&wgui_inline_scroll_text, text_x - text_width + 1, text_y, text_width, text_height, (UI_string_type) text, wgui_inlinescrolling_timer, wgui_scrolling_text_draw_background, text_colr, text_colr);        /* 031205 Calvin modified */
            }
            else
            {
                gui_create_scrolling_text(&wgui_inline_scroll_text, text_x, text_y, text_width + 1, text_height, (UI_string_type) text, wgui_inlinescrolling_timer, wgui_scrolling_text_draw_background, text_colr, text_colr);     /* 031205 Calvin modified */
            }
            gui_show_scrolling_text(&wgui_inline_scroll_text);
        }
        else
        {
            if (mmi_fe_get_r2l_state())
            {
                gdi_layer_set_clip(text_x - text_width, text_y - 1, text_x, text_y + text_height + 1);
            }
            else
            {
                gdi_layer_set_clip(text_x, text_y - 1, text_x + text_width, text_y + text_height + 1);
            }
            gui_move_text_cursor(text_x, text_y);
            gui_set_line_height(text_height);
            gui_set_text_color(text_colr);
            gui_print_text((UI_string_type) text);
        }
    }
    else
    {
        text_colr = MMI_fixed_icontext_menuitem.normal_text_color;
        if (mmi_fe_get_r2l_state())
        {
            gdi_layer_set_clip(text_x - text_width + 1, text_y - 1, text_x, text_y + text_height + 1);
        }
        else
        {
            gdi_layer_set_clip(text_x, text_y - 1, text_x + text_width, text_y + text_height + 1);
        }
        gui_move_text_cursor(text_x, text_y);
        gui_set_line_height(text_height);
        gui_set_text_color(text_colr);
        gui_print_text((UI_string_type) text);
    }
#endif    
    gui_pop_clip();
    UI_UNUSED_PARAMETER(char_height);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_show_image_text_item
 * DESCRIPTION
 *  show image text item
 * PARAMETERS
 *  x1                  [IN]    left-top corner x1 coordinate    
 *  y1                  [IN]    left-top corner y1 coordinate    
 *  iwidth              [IN]    width    
 *  iheight             [IN]    height          
 *  item                [IN]    inline item         
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_show_image_text_item(S32 x1, S32 y1, S32 iwidth, S32 iheight, wgui_inline_item *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    wgui_inline_image_text *i = (wgui_inline_image_text*) item->item;
    wgui_inline_item_text_edit *i_edit = (wgui_inline_item_text_edit*) i->inline_full_text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    draw_image_text_control(i, x1, y1, iwidth, iheight, i->image1, i->image2, i->image3, i_edit->buffer, 0);

}


/*****************************************************************************
 * FUNCTION
 *  clear_inline_image_text_item
 * DESCRIPTION
 *  clear inline image text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clear_inline_image_text_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_scrolling_text_stop(&wgui_inline_scroll_text);
    memset(&wgui_inline_scroll_text, 0, sizeof(wgui_inline_scroll_text));
    clear_inline_item_keys = UI_dummy_function;
    redraw_current_inline_item = UI_dummy_function;
#ifdef __MMI_TOUCH_SCREEN__
    wgui_current_inline_item_pen_function = UI_dummy_inline_item_pen_function;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_show_image_text_item_highlight
 * DESCRIPTION
 *  show image text item highlight
 * PARAMETERS
 *  x1                  [IN]    left-top corner x1 coordinate    
 *  y1                  [IN]    left-top corner y1 coordinate    
 *  iwidth              [IN]    width    
 *  iheight             [IN]    height          
 *  item                [IN]    inline item        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_show_image_text_item_highlight(S32 x1, S32 y1, S32 iwidth, S32 iheight, wgui_inline_item *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_image_text *i = (wgui_inline_image_text*) item->item;
    wgui_inline_item_text_edit *i_edit = (wgui_inline_item_text_edit*) i->inline_full_text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i->x = x1;
    i->y = y1;
    i->width = iwidth;
    i->height = iheight;

    clear_inline_item_keys = clear_inline_image_text_item;
    redraw_current_inline_item = redraw_image_text_control;
#ifdef __MMI_TOUCH_SCREEN__
    wgui_current_inline_item_pen_function = inline_image_text_pen_handler;
#endif 
    current_image_text_control = i;
    draw_image_text_control(i, x1, y1, iwidth, iheight, i->image1, i->image2, i->image3, i_edit->buffer, 1);

}


/*****************************************************************************
 * FUNCTION
 *  inline_image_text_full_screen_inputbox_input
 * DESCRIPTION
 *  input handler for inline image text multiline inputbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void inline_image_text_multiline_inputbox_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_handle_inputbox_input();
    inline_full_screen_edit_changed = 1;
}


/*****************************************************************************
 * FUNCTION
 *  handle_inline_full_screen_imagetext_edit
 * DESCRIPTION
 *  activation of inline full screen imagetext edit
 * PARAMETERS
 *  x                   [IN]        left corner's x coordinate
 *  y                   [IN]        left corner's y coordinate
 *  width               [IN]        width
 *  height              [IN]        height
 *  key_code            [IN]        key code
 *  key_event           [IN]        key event
 *  text_p              [IN]        text pointer
 *  item                [IN]         inline item
 *  flags               [IN]        flags
 *  history_buffer      [IN]         history buffer        
 * RETURNS
 *  void
 *****************************************************************************/
static void handle_inline_full_screen_imagetext_edit(
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        S32 key_code,
        S32 key_event,
        U8 **text_p,
        void *item,
        U32 flags,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 input_type;
    wgui_inline_image_text *image_type = (wgui_inline_image_text*) item;

    wgui_inline_item_text_edit *i = (wgui_inline_item_text_edit*) image_type->inline_full_text;
    
    S32 inputbox_x, inputbox_y, inputbox_width, inputbox_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(GUI_EDITOR_SHOW_TITLE)
    inputbox_x = MMI_COMMON_CONTENT_X;
    inputbox_y = MMI_COMMON_CONTENT_Y - MMI_COMMON_TITLE_HEIGHT;
    inputbox_width = MMI_COMMON_CONTENT_WIDTH;
    inputbox_height = MMI_COMMON_CONTENT_HEIGHT + MMI_COMMON_TITLE_HEIGHT;
#else 
    inputbox_x = MMI_COMMON_CONTENT_X;
    inputbox_y = MMI_COMMON_CONTENT_Y;
    inputbox_width = MMI_COMMON_CONTENT_WIDTH;
    inputbox_height = MMI_COMMON_CONTENT_HEIGHT;
#endif 
    UI_UNUSED_PARAMETER(x);
    UI_UNUSED_PARAMETER(y);
    UI_UNUSED_PARAMETER(width);
    UI_UNUSED_PARAMETER(height);
    UI_UNUSED_PARAMETER(key_code);
    UI_UNUSED_PARAMETER(key_event);
    UI_UNUSED_PARAMETER(flags);

    if(cui_inline_is_current_cui())
    {
        cui_inline_evt_item_activate(); 
        return;
    }
    else
    {
        if (i->custom_setup_function != NULL)
        {
            i->custom_setup_function();
            return;
        }
    }

    gdi_layer_lock_frame_buffer();
    wgui_text_menuitem_reset_scrolling();
    clear_inline_image_text_item();

    if (i->flags & INLINE_ITEM_CHANGED)
    {
        inline_full_screen_edit_changed = 1;
    }
    else
    {
        inline_full_screen_edit_changed = 0;
    }
    wgui_current_inline_item_type = INLINE_ITEM_TYPE_FULL_SCREEN_EDIT;
    current_wgui_inline_text_edit_item = i;

    current_wgui_inline_text_edit_text_p = text_p;

    input_type = i->input_type;
    if (inline_image_text_edit_flag == 0)
    {
        if (!(flags & INLINE_ITEM_OPEN))
        {
            gui_strcpy((UI_string_type) wgui_inline_full_screen_text_edit_buffer, (UI_string_type) i->buffer);
            history_buffer = NULL;
        }
    }
    inline_image_text_edit_flag = 1;

    i->flags &= ~INLINE_ITEM_OPEN;
    inline_full_screen_edit_saved_title = MMI_title_string;
    inline_full_screen_edit_saved_title_icon = MMI_title_icon;
    inline_full_screen_edit_saved_LSK_label = MMI_softkeys[MMI_LEFT_SOFTKEY].text;
    inline_full_screen_edit_saved_RSK_label = MMI_softkeys[MMI_RIGHT_SOFTKEY].text;
    inline_full_screen_edit_saved_LSK_icon = MMI_softkeys[MMI_LEFT_SOFTKEY].normal_up_icon;
    inline_full_screen_edit_saved_RSK_icon = MMI_softkeys[MMI_RIGHT_SOFTKEY].normal_up_icon;
    change_left_softkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    change_right_softkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    wgui_title_set_menu_shortcut_number(-1);
    wgui_title_disable_menu_shortcut_display(MMI_TRUE);
    clear_key_handlers();
    change_left_softkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    change_right_softkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    clear_left_softkey();
    clear_right_softkey();
    register_left_softkey_handler();
    register_right_softkey_handler();
    register_default_hide_softkeys();
    MMI_title_string = get_string(i->title);
    MMI_title_icon = get_image(i->title_icon);
    wgui_inputbox_validation_callback = i->validation_callback;
    wgui_setup_inputbox(
        inputbox_x,
        inputbox_y,
        inputbox_width,
        inputbox_height,
        wgui_inline_full_screen_text_edit_buffer,
        i->buffer_size,
        INLINE_FULL_SCREEN_EDIT_HISTORY_ID,
        get_string(STR_GLOBAL_BACK),
        get_image(IMG_GLOBAL_BACK),
        (S16) input_type,
        history_buffer,
    #ifdef __MMI_FTE_SUPPORT__        
        0
    #else
        1
    #endif    
        );
    inputbox_height = MMI_content_height - MMI_multitap_height - wgui_inputbox_information_bar_height;
    if (MMI_multiline_inputbox.height > inputbox_height)
    {
        gui_resize_multi_line_input_box(&MMI_multiline_inputbox, MMI_multiline_inputbox.width, inputbox_height);
    }


#ifdef __MMI_WALLPAPER_ON_BOTTOM__
    if (!inline_opacity_changed)
    {
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_TRANSPARENT_BACKGROUND;
    dm_get_scr_bg_opacity(&inline_edit_scr_bg_opacity);
    dm_set_scr_bg_opacity((U8)(current_MMI_theme->bg_opacity_low));    
    inline_opacity_changed = TRUE;
    }
#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */ 

#if !defined(GUI_EDITOR_SHOW_TITLE)
    {
        S32 dm_flag;
        
        dm_get_dm_data_flag(&dm_flag);
        dm_flag |= DM_NO_TITLE;
        
        dm_set_dm_data_flag(dm_flag);
        
        full_screen_edit_open = 1;
#if defined (MMI_SHOW_STATUS_ICON_IN_TITLE) 
        wgui_status_icon_bar_register_integrated_redraw(NULL);
#endif
    }
#endif /* !defined(GUI_EDITOR_SHOW_TITLE) */

    register_multiline_inputbox_input_callback(inline_image_text_multiline_inputbox_input);
    wgui_inputbox_RSK_function = handle_inline_full_screen_edit_cancel;
    redraw_current_inline_item = redraw_inline_full_screen_edit;
    set_left_softkey_function(handle_inline_full_screen_edit_complete, KEY_EVENT_UP);
    mmi_imc_key_setup_lsk_function(handle_inline_full_screen_edit_complete);

    gdi_layer_unlock_frame_buffer();
    redraw_inline_full_screen_edit();
    complete_inline_item_edit = handle_inline_full_screen_edit_close;

}

#endif  /* defined (__MMI_INLINE_ITEM_IMAGETEXT__) */
#endif /* defined __MMI_PLUTO_GPRS__ */ 


/***************************************************************************** 
 * Inline Select    
 *
 * This is Inline Select Item
 *****************************************************************************/

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define  MAX_INLINE_SELECT_MENU_ITEMS  60

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
#define MAX_INLINE_SELECT_ITEMS        25
#elif !defined(LOW_COST_SUPPORT)
#define MAX_INLINE_SELECT_ITEMS        16
#else
#define MAX_INLINE_SELECT_ITEMS        11
#endif


/***************************************************************************** 
 * Local Variable
 *****************************************************************************/


static S32 n_inline_select_items = 0;


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/


/***************************************************************************** 
 * Function Implementation
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  handle_inline_select
 * DESCRIPTION
 *  activation function of inline select
 * PARAMETERS
 *  x                   [IN]        left corner's x coordinate
 *  y                   [IN]        left corner's y coordinate
 *  width               [IN]        width
 *  height              [IN]        height
 *  key_code            [IN]        key code
 *  key_event           [IN]        key event
 *  text_p              [IN]        text pointer
 *  item                [IN]         inline item
 *  flags               [IN]        flags
 *  history_buffer      [IN]         history buffer          
 * RETURNS
 *  void
 *****************************************************************************/
void handle_inline_select(
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        S32 key_code,
        S32 key_event,
        U8 **text_p,
        void *item,
        U32 flags,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(key_event);
    UI_UNUSED_PARAMETER(key_code);
    UI_UNUSED_PARAMETER(flags);

}


/*****************************************************************************
 * FUNCTION
 *  wgui_show_inline_select_arrow
 * DESCRIPTION
 *  Displaying Selector edit as a menu item in the fixed list menu
 * PARAMETERS
 *  x1          [IN]        x
 *  y1          [IN]        y
 *  width       [IN]        width
 *  height      [IN]        height
 *  item        [IN]        inline item         
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_show_inline_select_arrow(S32 x1, S32 y1, S32 width, S32 height, wgui_inline_item *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FTE_SUPPORT__)
    wgui_show_inline_fte_displayonly_item_unhighlight(x1, y1, width, height, item);
#else /* __MMI_FTE_SUPPORT__ */
    wgui_show_inline_displayonly_item(x1, y1, width, height, item);
#endif /* __MMI_FTE_SUPPORT__ */
}



/*****************************************************************************
 * FUNCTION
 *  SetInlineItemSelect
 * DESCRIPTION
 *  set data for inine select
 * PARAMETERS
 *  item                    [IN]    inline item         
 *  n_items                 [IN]    item number    
 *  list_of_items           [IN]    list of items    
 *  highlighted_item        [IN]    highlighted item index     
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineItemSelect(InlineItem *item, S32 n_items, U8 **list_of_items, S32 *highlighted_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_select *i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(n_items <= MAX_INLINE_SELECT_MENU_ITEMS);
    
    if (n_inline_select_items >= MAX_INLINE_SELECT_ITEMS)
    {
        return;
    }
    wgui_inline_mem_alloc_info[wgui_inline_mem_alloc_number] = item->item = wgui_inline_malloc(sizeof(wgui_inline_item_select));
    wgui_inline_mem_alloc_number++; 
    item->flags = INLINE_ITEM_TYPE_SELECT;
    n_inline_select_items++;
    i = (wgui_inline_item_select*) item->item;
    i->flags = 0;
    i->list_of_strings = list_of_items;
    i->n_items = n_items;
    i->item_highlighted = UI_dummy_function_s32;
    if (highlighted_item == NULL)
    {
        i->highlighted_item = NULL;
        item->text_p = list_of_items[0];
    }
    else
    {
        if (*highlighted_item < 0 || *highlighted_item >= n_items)
        {
            MMI_DBG_ASSERT(0);
            *highlighted_item = 0;
        }
        i->highlighted_item = highlighted_item;
        item->text_p = list_of_items[*highlighted_item];
    }
    item->handler = handle_inline_display_only;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_set_item_selector_by_string_id
 * DESCRIPTION
 *  set data for inine select by string id
 * PARAMETERS
 *  item                    [IN]    inline item         
 *  n_items                 [IN]    item number    
 *  list_of_string_id       [IN]    list of string id    
 *  highlighted_item        [IN]    highlighted item index     
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_set_item_selector_by_string_id(InlineItem *item, S32 n_items, U16 *list_of_string_id, S32 *highlighted_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    PU8 *string_id_list = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (n_inline_select_items >= MAX_INLINE_SELECT_ITEMS)
    {
        return;
    }
    wgui_inline_mem_alloc_info[wgui_inline_mem_alloc_number] = string_id_list = (PU8 *)wgui_inline_malloc(sizeof(U8 *) * n_items );
    wgui_inline_mem_alloc_number++; 

    if(list_of_string_id != NULL)
    {
        for (i = 0; i < n_items; i++)
        {
            string_id_list[i] = (PU8) GetString(list_of_string_id[i]);
        }
    }
    SetInlineItemSelect(item, n_items, string_id_list, highlighted_item);
}

     
/*****************************************************************************
 * FUNCTION
 *  ReConfigureInlineItemSelect
 * DESCRIPTION
 *  re-configure of inline select
 * PARAMETERS
 *  item                    [IN]    inline item         
 *  n_items                 [IN]    item number    
 *  list_of_items           [IN]    list of items    
 *  highlighted_item        [IN]    highlighted item index          
 * RETURNS
 *  void
 *****************************************************************************/
void ReConfigureInlineItemSelect(InlineItem *item, S32 n_items, U8 **list_of_items, S32 *highlighted_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_select *i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((item->flags & 0xff) != INLINE_ITEM_TYPE_SELECT)
    {
        return;
    }
    i = (wgui_inline_item_select*) item->item;
    i->flags = 0;
    i->list_of_strings = list_of_items;
    i->n_items = n_items;
    i->item_highlighted = UI_dummy_function_s32;
    if (highlighted_item == NULL)
    {
        i->highlighted_item = NULL;
        item->text_p = list_of_items[0];
    }
    else
    {
        if (*highlighted_item < 0 || *highlighted_item >= n_items)
        {
            MMI_DBG_ASSERT(0);
            *highlighted_item = 0;
        }
        i->highlighted_item = highlighted_item;
        item->text_p = list_of_items[*highlighted_item];
    }
}


#if defined(__MMI_INLINE_ITEM_DATE__)

/***************************************************************************** 
 * Inline Date Edit    
 *
 * This is Inline Date Edit Item
 *****************************************************************************/

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MAX_INLINE_DATE_ITEMS                   4
#define MAX_INLINE_DATE_DISPLAY_STRING_SIZE     48 // 23 chars with null terminator */


/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
typedef struct _inline_date_edit_history
{
    U16 history_ID;
    S16 current_focus;
    S16 current_position;
    S16 dummy;  /* Added for history issue on hardware */
    U32 flags;
    mmi_imc_history ime_history;
} inline_date_edit_history;


/***************************************************************************** 
 * Local Variable
 *****************************************************************************/
static S32 n_inline_date_items = 0;
static wgui_inline_item_date *current_wgui_inline_date_item;
static PU8 *current_wgui_inline_date_text_p;

date_input wgui_inline_date_input;

/* Displaying date edit as a menu item in the fixed list menu  */
//static date_input wgui_inline_date_input_display;


/***************************************************************************** 
 * Function Implementation
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  handle_inline_date_edit_complete
 * DESCRIPTION
 *  complete function of inline date edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void handle_inline_date_edit_complete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    register_inline_fixed_list_keys();
    current_wgui_inline_date_item->string_construct_callback(
                                    *current_wgui_inline_date_text_p,
                                    current_wgui_inline_date_item->day_buffer,
                                    current_wgui_inline_date_item->month_buffer,
                                    current_wgui_inline_date_item->year_buffer);
    MMI_fixed_icontext_menuitems[wgui_inline_item_highlighted_index].item_text =
        (UI_string_type) * current_wgui_inline_date_text_p;
   // clear_left_softkey();
   // clear_right_softkey();

    register_left_softkey_handler();
    register_right_softkey_handler();
    wgui_inline_item_handled = 0;
    wgui_text_menuitem_restart_scrolling();
    redraw_current_inline_item = UI_dummy_function;
    complete_inline_item_edit = UI_dummy_function;
    set_current_date_input(NULL);
    clear_date_input_callback();
    mmi_imc_disconnect();
    g_inline_current_input_box_handler = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  redraw_inline_date_edit
 * DESCRIPTION
 *  redraw inline date edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void redraw_inline_date_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    date_input_show_background(&wgui_inline_date_input);
    show_date_input(&wgui_inline_date_input);
}


/*****************************************************************************
 * FUNCTION
 *  inline_date_edit_handle_down_arrow
 * DESCRIPTION
 *  down arrow handler of inline date edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void inline_date_edit_handle_down_arrow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(wgui_inline_edit_is_able_to_switch_highlight(1))
    {
#ifdef __MMI_FTE_SUPPORT__    
        wgui_inline_get_vk_status(&g_inline_vk_status);
#endif
        handle_inline_date_edit_complete();
        inline_fixed_list_goto_next_item();
    }
}


/*****************************************************************************
 * FUNCTION
 *  inline_date_edit_handle_up_arrow
 * DESCRIPTION
 *  up arrow handler of inline date edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void inline_date_edit_handle_up_arrow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(wgui_inline_edit_is_able_to_switch_highlight(0))
    {
#ifdef __MMI_FTE_SUPPORT__    
        wgui_inline_get_vk_status(&g_inline_vk_status);
#endif
        handle_inline_date_edit_complete();
        inline_fixed_list_goto_previous_item();
    }
}


/*****************************************************************************
 * FUNCTION
 *  inline_date_input_key_handler
 * DESCRIPTION
 *  key handler of inline date for PC
 * PARAMETERS
 *  vkey_code       [IN]    key code    
 *  key_state       [IN]    key state    
 * RETURNS
 *  void
 *****************************************************************************/
void inline_date_input_key_handler(S32 vkey_code, S32 key_state)
{
#if(MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_state)
    {
        switch (vkey_code)
        {
            case 37:
                date_input_previous_character();
                break;
            case 38:
                inline_date_edit_handle_up_arrow();
                break;
            case 39:
                date_input_next_character();
                break;
            case 40:
                inline_date_edit_handle_down_arrow();
                break;
            case 36:    /* home */
                break;
            case 35:    /* end */
                break;
            case 33:    /* page up */
                break;
            case 34:    /* page down */
                break;
            case 45:
                date_input_toggle_insert_mode();
                break;
            case 46:
                date_input_delete_current_character();
                break;
        }
    }
#else /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
    UI_UNUSED_PARAMETER(vkey_code);
    UI_UNUSED_PARAMETER(key_state);
#endif /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
}



/*****************************************************************************
 * FUNCTION
 *  inline_date_edit_get_history
 * DESCRIPTION
 *  get history buffer of inline date edit
 * PARAMETERS
 *  history_buffer      [OUT]   history buffer     
 * RETURNS
 *  history buffer
 *****************************************************************************/
U8 *inline_date_edit_get_history(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        U16 hID = (U16) (INLINE_DATE_HISTORY_ID | 0x8000);
        inline_date_edit_history *h = (inline_date_edit_history*) history_buffer;

        h->history_ID = hID;
        h->current_focus = (S16) wgui_inline_date_input.current_focus;
        if (wgui_inline_date_input.focus_input_box != NULL)
        {
            h->current_position =
                (S16) (wgui_inline_date_input.focus_input_box->current_text_p -
                       wgui_inline_date_input.focus_input_box->text);
        }
        h->flags = wgui_inline_date_input.input.flags;
        mmi_imc_get_input_method_history(&(h->ime_history));
    }
    return (history_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  inline_date_edit_set_history
 * DESCRIPTION
 *  set history buffer into wgui_inline_date_input
 * PARAMETERS
 *  history_ID          [IN]    history id        
 *  history_buffer      [IN]    history buffer         
 * RETURNS
 *  1->success 0->fail
 *****************************************************************************/
U8 inline_date_edit_set_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        inline_date_edit_history *h = (inline_date_edit_history*) history_buffer;

        if (history_valid(h->history_ID, history_ID))
        {
            wgui_inline_date_input.current_focus = h->current_focus;
            date_input_reset_focus((void*)&wgui_inline_date_input);
            date_input_set_focus((void*)&wgui_inline_date_input);
            if (wgui_inline_date_input.focus_input_box != NULL)
            {
                wgui_inline_date_input.focus_input_box->current_text_p =
                    wgui_inline_date_input.focus_input_box->text + h->current_position;
            }
            wgui_inline_date_input.input.flags= h->flags;
            return (1);
        }
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  handle_inline_date_edit
 * DESCRIPTION
 *  activation function of inline date edit
 * PARAMETERS
 *  x                   [IN]        left corner's x coordinate
 *  y                   [IN]        left corner's y coordinate
 *  width               [IN]        width
 *  height              [IN]        height
 *  key_code            [IN]        key code
 *  key_event           [IN]        key event
 *  text_p              [IN]        text pointer
 *  item                [IN]        inline item
 *  flags               [IN]        flags
 *  history_buffer      [IN]        history buffer         
 * RETURNS
 *  void
 *****************************************************************************/
void handle_inline_date_edit(
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        S32 key_code,
        S32 key_event,
        U8 **text_p,
        void *item,
        U32 flags,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_date *i = (wgui_inline_item_date*) item;
    S32 xx;
    U32 dtflags = DATE_INPUT_TYPE_YYYY_MM_DD;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(key_code);
    UI_UNUSED_PARAMETER(key_event);
    UI_UNUSED_PARAMETER(flags);
    wgui_current_inline_item_type = INLINE_ITEM_TYPE_DATE;

    if (mmi_fe_get_r2l_state())
    {
        xx = 1;
    }
    else
    {
        if (MMI_fixed_icontext_menuitem.text_x == 2)
        {
            xx = -1;
        }
        else
        {
            xx = MMI_fixed_icontext_menuitem.text_x;
        }
    }
    

    if (flags & INLINE_ITEM_LEFT_ALIGN)
    {
        xx = -1;
    }
    switch (flags & INLINE_ITEM_JUSTIFY_MASK)
    {
        case INLINE_ITEM_RIGHT_JUSTIFY:
            dtflags |= DATE_INPUT_RIGHT_JUSTIFY;
            break;
        case INLINE_ITEM_CENTER_JUSTIFY:
            dtflags |= DATE_INPUT_CENTER_JUSTIFY;
            break;
    }
    complete_inline_item_edit = handle_inline_date_edit_complete;
    current_wgui_inline_date_item = i;
    current_wgui_inline_date_text_p = text_p;
    
#ifndef __MMI_FTE_SUPPORT__  
    if (mmi_fe_get_r2l_state())
    {
        if (flags & INLINE_ITEM_LEFT_ALIGN)
        {
            create_date_input(
                &wgui_inline_date_input,
                x + xx,
                y,
                width - xx,
                height,
                dtflags,
                i->day_buffer,
                i->month_buffer,
                i->year_buffer);
        }
        else
        {
            create_date_input(
                &wgui_inline_date_input,
                x + xx,
                y,
                width - MMI_fixed_icontext_menuitem.text_x,
                height,
                dtflags,
                i->day_buffer,
                i->month_buffer,
                i->year_buffer);
            }
        }

    else
    {
        create_date_input(
            &wgui_inline_date_input,
            x + xx,
            y,
            width - xx,
            height,
            dtflags,
            i->day_buffer,
            i->month_buffer,
            i->year_buffer);
    }
    
#else 
    create_date_input(
                &wgui_inline_date_input,
                x,
                y,
                width,
                height,
                dtflags,
                i->day_buffer,
                i->month_buffer,
                i->year_buffer);
#endif

#ifdef __MMI_FTE_SUPPORT__
    wgui_inline_date_input.input.flags|= DATE_INPUT_USE_PRESET_CLIP;
#endif

    if(cui_inline_is_current_cui())
    {
        cui_inline_item_replace_gui_buffer(wgui_inline_item_highlighted_index, &wgui_inline_items[wgui_inline_item_highlighted_index], &history_buffer);
    }
    else
    {
        inline_date_edit_set_history(INLINE_DATE_HISTORY_ID, history_buffer);
    }
    date_input_set_seperator(&wgui_inline_date_input, (UI_character_type) '/');
    date_input_show_background(&wgui_inline_date_input);
    show_date_input(&wgui_inline_date_input);
    set_current_date_input(&wgui_inline_date_input);
    date_input_register_keys();
    mmi_imc_key_register_ime_keys();
    register_keyboard_key_handler(inline_date_input_key_handler);

    /* key rule. 09.10.17 */
    SetKeyHandler(inline_date_edit_handle_down_arrow, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(inline_date_edit_handle_up_arrow, KEY_UP_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(inline_date_edit_handle_down_arrow, KEY_VOL_DOWN, KEY_EVENT_REPEAT);
    SetKeyHandler(inline_date_edit_handle_up_arrow, KEY_VOL_UP, KEY_EVENT_REPEAT);
    
    SetKeyHandler(inline_date_edit_handle_down_arrow, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(inline_date_edit_handle_up_arrow, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(inline_date_edit_handle_down_arrow, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetKeyHandler(inline_date_edit_handle_up_arrow, KEY_VOL_UP, KEY_EVENT_DOWN);
    redraw_current_inline_item = redraw_inline_date_edit;
    register_date_input_callback(set_wgui_inline_list_menu_changed);
    mmi_imc_redraw_screen_by_state();
}


/*****************************************************************************
 * FUNCTION
 *  SetInlineItemDate
 * DESCRIPTION
 *  set data for inline date
 * PARAMETERS
 *  item                [IN]    inline item     
 *  day_buffer          [IN]    day buffer     
 *  month_buffer        [IN]    month buffer     
 *  year_buffer         [IN]    year buffer     
 *  f                   [IN]    string construct callback    
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineItemDate(
        InlineItem *item,
        U8 *day_buffer,
        U8 *month_buffer,
        U8 *year_buffer,
        void (*f) (U8 *string_buffer, U8 *day_buffer, U8 *month_buffer, U8 *year_buffer))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_date *i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (n_inline_date_items >= MAX_INLINE_DATE_ITEMS)
    {
        return;
    }

    wgui_inline_mem_alloc_info[wgui_inline_mem_alloc_number] = item->item = wgui_inline_malloc(sizeof(wgui_inline_item_date));
    wgui_inline_mem_alloc_number++; 
    item->flags = INLINE_ITEM_TYPE_DATE;
    wgui_inline_mem_alloc_info[wgui_inline_mem_alloc_number] = item->text_p = (U8*)wgui_inline_malloc(MAX_INLINE_DATE_DISPLAY_STRING_SIZE * sizeof(U8));
    wgui_inline_mem_alloc_number++;  
    n_inline_date_items++;
    i = (wgui_inline_item_date*) item->item;
    i->day_buffer = day_buffer;
    i->month_buffer = month_buffer;
    i->year_buffer = year_buffer;
    i->flags = INLINE_ITEM_LEFT_JUSTIFY;
    i->string_construct_callback = f;
    i->string_construct_callback(item->text_p, i->day_buffer, i->month_buffer, i->year_buffer);
    item->handler = handle_inline_date_edit;
}


/*****************************************************************************
 * FUNCTION
 *  ReConfigureInlineItemDate
 * DESCRIPTION
 *  re-configure of inline date
 * PARAMETERS
 *  item                [IN]    inline item     
 *  day_buffer          [IN]    day buffer     
 *  month_buffer        [IN]    month buffer     
 *  year_buffer         [IN]    year buffer     
 *  f                   [IN]    string construct callback        
 * RETURNS
 *  void
 *****************************************************************************/
void ReConfigureInlineItemDate(
        InlineItem *item,
        U8 *day_buffer,
        U8 *month_buffer,
        U8 *year_buffer,
        void (*f) (U8 *string_buffer, U8 *day_buffer, U8 *month_buffer, U8 *year_buffer))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_date *i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((item->flags & 0xff) != INLINE_ITEM_TYPE_DATE)
    {
        return;
    }
    i = (wgui_inline_item_date*) item->item;
    i->day_buffer = day_buffer;
    i->month_buffer = month_buffer;
    i->year_buffer = year_buffer;
    i->flags = 0;
    i->string_construct_callback = f;
    i->string_construct_callback(item->text_p, i->day_buffer, i->month_buffer, i->year_buffer);
}

#endif


/*****************************************************************************
 * FUNCTION
 *  wgui_set_date_time_input_focussed_theme
 * DESCRIPTION
 *  set focussed theme for inline date input
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_set_date_time_input_focussed_theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    date_time_input_theme.disabled_filler = &date_time_input_field_filler;
    date_time_input_theme.disabled_filler->c = current_MMI_theme->inline_datatime_focussed_filler->c;
    date_time_input_theme.normal_filler = &date_time_input_field_filler;
    date_time_input_theme.normal_filler->c = current_MMI_theme->inline_datatime_focussed_filler->c;    
    date_time_input_theme.selected_filler = &date_time_input_field_filler;
    date_time_input_theme.selected_filler->c = current_MMI_theme->inline_datatime_focussed_filler->c;
    date_time_input_theme.disabled_text_color = wgui_inline_singleline_inputbox_focussed_theme.disabled_text_color;
    date_time_input_theme.normal_text_color = wgui_inline_singleline_inputbox_focussed_theme.normal_text_color;
    date_time_input_theme.selected_text_color = wgui_inline_singleline_inputbox_focussed_theme.selected_text_color;
    date_time_input_background_filler = *current_MMI_theme->inline_datatime_focussed_filler;
#ifdef  __MMI_FTE_SUPPORT__
    date_time_input_background_filler = *(current_MMI_theme->inline_item_textedit_highlighted_bg_filler);
    date_time_input_theme.selection_text_color = wgui_inline_singleline_inputbox_focussed_theme.selection_text_color;
    date_time_input_theme.selection_color = wgui_inline_singleline_inputbox_focussed_theme.selection_color;
    date_time_input_theme.normal_text_color = wgui_inline_singleline_inputbox_focussed_theme.normal_text_color;
#endif   
    date_time_input_theme.cursor_color = *current_MMI_theme->inline_edit_cursor_color;
    date_time_input_theme.selection_text_color = *current_MMI_theme->inline_edit_selected_text_color;
    date_time_input_theme.selection_color = *current_MMI_theme->inline_edit_selector_color;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_set_date_time_input_unfocussed_theme
 * DESCRIPTION
 *  set unfocussed theme for inline date input
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_set_date_time_input_unfocussed_theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    date_time_input_theme.disabled_filler = current_MMI_theme->inline_datatime_unfocussed_filler;

    /* changed the date time normal filler in case of default text effect is enabled. */
#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
    if (IsInlineItemDefaultTextEnable())
    {
        date_time_input_theme.normal_filler = &temp_inline_edit_normal_filler;
    }
    else
#endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 

    date_time_input_theme.normal_filler = &date_time_input_field_filler;
    date_time_input_theme.normal_filler->c = current_MMI_theme->inline_datatime_unfocussed_filler->c;
    date_time_input_theme.selected_filler = current_MMI_theme->inline_datatime_unfocussed_filler;
    date_time_input_theme.disabled_text_color = wgui_inline_singleline_inputbox_unfocussed_theme.disabled_text_color;
    date_time_input_theme.normal_text_color = wgui_inline_singleline_inputbox_unfocussed_theme.normal_text_color;
    date_time_input_theme.selected_text_color = wgui_inline_singleline_inputbox_unfocussed_theme.selected_text_color;
    date_time_input_background_filler = *current_MMI_theme->inline_datatime_unfocussed_filler;
#ifdef  __MMI_FTE_SUPPORT__
    date_time_input_background_filler = *(current_MMI_theme->inline_item_textedit_unhighlighted_bg_filler);
    date_time_input_theme.selection_text_color= wgui_inline_singleline_inputbox_focussed_theme.selection_text_color;
    date_time_input_theme.selection_color = wgui_inline_singleline_inputbox_focussed_theme.selection_color;
    date_time_input_theme.normal_text_color = wgui_inline_singleline_inputbox_focussed_theme.normal_text_color;
#endif 
    time_period_input_background_filler = MMI_inputbox_normal_filler;   
    date_time_input_theme.cursor_color = *current_MMI_theme->inline_edit_cursor_color;
    date_time_input_theme.selection_text_color = *current_MMI_theme->inline_edit_selected_text_color;
    date_time_input_theme.selection_color = *current_MMI_theme->inline_edit_selector_color;
}


#if defined(__MMI_INLINE_ITEM_DATE__)

/*****************************************************************************
 * FUNCTION
 *  wgui_show_inline_date_list_menuitem
 * DESCRIPTION
 *  show inline date list menuitem
 * PARAMETERS
 *  x1          [IN]  the left-top corner x1 coordinate      
 *  y1          [IN]  the left-top corner y1 coordinate      
 *  width       [IN]  width      
 *  height      [IN]  height      
 *  item        [IN]  inline item         
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_show_inline_date_list_menuitem(S32 x1, S32 y1, S32 width, S32 height, wgui_inline_item *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_date *i = (wgui_inline_item_date*) item->item;
    S32 xx;
    U32 dtflags = DATE_INPUT_TYPE_YYYY_MM_DD;
    date_input wgui_inline_date_input_display = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    if (MMI_fixed_icontext_menuitem.text_x == 2)
    {
        xx = -1;
    }
    else
    {
        xx = MMI_fixed_icontext_menuitem.text_x;
    }
    if (item->flags & INLINE_ITEM_LEFT_ALIGN)
    {
        xx = -1;
    }
    switch (item->flags & INLINE_ITEM_JUSTIFY_MASK)
    {
        case INLINE_ITEM_RIGHT_JUSTIFY:
            dtflags |= DATE_INPUT_RIGHT_JUSTIFY;
            break;
        case INLINE_ITEM_CENTER_JUSTIFY:
            dtflags |= DATE_INPUT_CENTER_JUSTIFY;
            break;
    }
    wgui_set_date_time_input_unfocussed_theme();

#ifndef __MMI_FTE_SUPPORT__    
    create_date_input(
        &wgui_inline_date_input_display,
        x1 + xx,
        y1,
        width - xx,
        height,
        dtflags,
        i->day_buffer,
        i->month_buffer,
        i->year_buffer);
    date_input_set_seperator(&wgui_inline_date_input_display, (UI_character_type) '/');

#else
    create_date_input(
        &wgui_inline_date_input_display,
        x1,
        y1,
        width,
        height,
        dtflags,
        i->day_buffer,
        i->month_buffer,
        i->year_buffer);
#endif    
    date_input_set_seperator(&wgui_inline_date_input_display, (UI_character_type) '/');

#ifdef __MMI_FTE_SUPPORT__
    wgui_inline_date_input_display.input.flags |= DATE_INPUT_USE_PRESET_CLIP;
#endif
    /* show the different background in case of default text effect is enabled
       for the inline item type Date. */
#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
    if (IsInlineItemDefaultTextEnable())
    {
        inline_item_default_text_show_background(
            wgui_inline_date_input_display.input.x,
            wgui_inline_date_input_display.input.y,
            wgui_inline_date_input_display.input.x + wgui_inline_date_input_display.input.width - 1,
            wgui_inline_date_input_display.input.y + wgui_inline_date_input_display.input.height - 1);
    }
    else
#endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 

        date_input_show_background(&wgui_inline_date_input_display);
    date_input_reset_focus((void*)&wgui_inline_date_input_display);
    show_date_input(&wgui_inline_date_input_display);
    wgui_set_date_time_input_focussed_theme();
    gdi_layer_unlock_frame_buffer();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_input_box_msg_call_back_inline_date
 * DESCRIPTION
 *  message call back function of inline date for IME
 * PARAMETERS
 *  editor_ptr      [IN]    date input pointer
 *  msg_ptr         [IN]    message pointer
 * RETURNS
 *  U32
 *****************************************************************************/
static U32 mmi_input_box_msg_call_back_inline_date(date_input  * editor_ptr, mmi_imc_message_struct_p msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_last = MMI_FALSE;
    S32 i, str_len;
    U32 lresult = 0;
    UI_string_type temp_str;
    UI_character_type ch; 
#ifdef __MMI_TOUCH_SCREEN__
    MMI_BOOL ret = MMI_FALSE;
#endif /* __MMI_TOUCH_SCREEN__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(editor_ptr == &wgui_inline_date_input);

    switch(msg_ptr->message_id)
    {
    case MMI_IMC_MESSAGE_INSERT_CHAR:
        
        date_input_direct_input_nodraw((UI_character_type)msg_ptr->param_0);

        redraw_inline_date_edit();

        lresult = MMI_TRUE;

        break;
        
    case MMI_IMC_MESSAGE_INSERT_STRING:
    case MMI_IMC_MESSAGE_INSERT_STRING_NO_DRAW:    
        /* Need to revise */
        temp_str = (UI_string_type)msg_ptr->param_0;
        
        str_len = (S32)mmi_ucs2strlen((const S8 *)temp_str);

        
        if (msg_ptr->param_1 == MMI_TRUE)
        {
            if (date_input_test_last_position(editor_ptr))
            {
                is_last = MMI_TRUE;
            }
            
            date_input_direct_input_nodraw((UI_character_type)temp_str[0]);
            
            if (!is_last)
            {
                date_input_previous_character();
            }
            
            show_date_input(editor_ptr);
            }
        else
        {
            date_input_direct_input((UI_character_type)temp_str[0]);
        }
        
        redraw_inline_date_edit();
        
        lresult = str_len;
        break;
    case MMI_IMC_MESSAGE_REPLACE_HIGHLIGHT_STRING:  
        temp_str = (UI_string_type)msg_ptr->param_1;
        
        str_len = (S32)mmi_ucs2strlen((const S8 *)temp_str);

            if (date_input_test_last_position(editor_ptr))
            {
                is_last = MMI_TRUE;
            }
            
            date_input_direct_input_nodraw((UI_character_type)temp_str[0]);
            
            if (!is_last)
            {
                date_input_previous_character();
            }
            
            show_date_input(editor_ptr);
        
            redraw_inline_date_edit();
        
        lresult = str_len;
        break;

        
    case MMI_IMC_MESSAGE_CLEAR_HILIGHT:
        if (msg_ptr->param_0 == MMI_TRUE)
        {
            date_input_next_character();
        }
        break;
        
    case MMI_IMC_MESSAGE_IS_LAST_POSITION:
        lresult = (U32)date_input_test_last_position(editor_ptr);
        break;
        
    case MMI_IMC_MESSAGE_DELETE_STRING:
        
        break;
        
    case MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR:
        ch = (UI_character_type)msg_ptr->param_0;
        lresult = date_input_direct_input_nodraw(ch);
        break;

    case MMI_IMC_MESSAGE_RESET_MULTITAP_STATE:
        date_input_next_character();
        break;
        
    case MMI_IMC_MESSAGE_DELETE_CHAR:

        for (i = 0; i < (S32)msg_ptr->param_0; i++)
        {
            date_input_previous_character();
        }

        break;
    case MMI_IMC_MESSAGE_CLEAR_ALL:    
        date_input_first_character();
        break;
       
    case MMI_IMC_MESSAGE_REDRAW:
        
        wgui_inline_date_input.current_focus = g_inline_date_current_focus;

        date_input_reset_focus((void*)&wgui_inline_date_input);

        date_input_set_focus((void*)&wgui_inline_date_input);

        if (wgui_inline_date_input.focus_input_box != NULL)
        {
            wgui_inline_date_input.focus_input_box->current_text_p =
                wgui_inline_date_input.focus_input_box->text + g_inline_date_current_position;
        }

        wgui_inline_date_input.input.flags = g_inline_date_flags;
        
        redraw_inline_date_edit();
        
        break;
    case MMI_IMC_MESSAGE_SET_KEY:
        date_input_register_keys();
        mmi_imc_key_register_ime_keys();
        register_keyboard_key_handler(inline_date_input_key_handler);

        /* key rule. 09.10.17 */
        SetKeyHandler(inline_date_edit_handle_down_arrow, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
        SetKeyHandler(inline_date_edit_handle_up_arrow, KEY_UP_ARROW, KEY_EVENT_REPEAT);
        
        SetKeyHandler(inline_date_edit_handle_down_arrow, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(inline_date_edit_handle_up_arrow, KEY_UP_ARROW, KEY_EVENT_DOWN);
        set_right_softkey_label(wgui_inline_edit_get_RSK_string());
        register_right_softkey_handler();
        set_right_softkey_function(register_inline_edit_handle_right_softkey_up, KEY_EVENT_DOWN);
        break;
    case MMI_IMC_MESSAGE_CHECK_CSK_ENABLE:
        lresult = MMI_FALSE;
        break;
    case MMI_IMC_MESSAGE_CHECK_INFO_BAR_ENABL:
        lresult = MMI_FALSE;
        break;

    case MMI_IMC_MESSAGE_GET_CURSOR_RECT:
        if (editor_ptr->focus_input_box->flags & UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR)
        {
            ((mmi_imc_rect_p)msg_ptr->param_0)->x = editor_ptr->focus_input_box->hilite_s_x;
            ((mmi_imc_rect_p)msg_ptr->param_0)->y = editor_ptr->focus_input_box->hilite_s_y;
            ((mmi_imc_rect_p)msg_ptr->param_0)->width = editor_ptr->focus_input_box->hilite_e_x - editor_ptr->focus_input_box->hilite_s_x + 1;
            ((mmi_imc_rect_p)msg_ptr->param_0)->height = editor_ptr->focus_input_box->hilite_e_y - editor_ptr->focus_input_box->hilite_s_y + 1;
        }
        else
        {
            ((mmi_imc_rect_p)msg_ptr->param_0)->x = UI_cursor_x1;
            ((mmi_imc_rect_p)msg_ptr->param_0)->y = UI_cursor_y1;
            ((mmi_imc_rect_p)msg_ptr->param_0)->width = UI_cursor_x2 - UI_cursor_x1 + 1;
            ((mmi_imc_rect_p)msg_ptr->param_0)->height = UI_cursor_y2 - UI_cursor_y1 + 1;
        }
        lresult = MMI_TRUE;
        break;

    case MMI_IMC_MESSAGE_MOVE_CURSOR:
        switch (msg_ptr->param_0)
        {
            case MMI_IMC_EDITOR_CURSOR_UP:
                for (i = 0; i <(S32)msg_ptr->param_1; i ++)
                {
                    inline_date_edit_handle_up_arrow();
                }
                break;
                
            case MMI_IMC_EDITOR_CURSOR_DOWN:
                for (i = 0; i <(S32)msg_ptr->param_1; i ++)
                {
                    inline_date_edit_handle_down_arrow();
                }
                break;
                
            case MMI_IMC_EDITOR_CURSOR_LEFT:
                for (i = 0; i <(S32)msg_ptr->param_1; i ++)
                {
                    date_input_previous_character();
                }
                break;
            case MMI_IMC_EDITOR_CURSOR_RIGHT:
                for (i = 0; i <(S32)msg_ptr->param_1; i ++)
                {
                    date_input_next_character();
                }
                break;
        }
        break;
        
    case MMI_IMC_MESSAGE_IS_BACKSPACE_DISABLED:
        lresult = MMI_TRUE;
        break;
        
#if defined(__MMI_TOUCH_SCREEN__)        
    case MMI_IMC_MESSAGE_PEN_EVENT:
        if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_DOWN)
        {
            if (PEN_CHECK_BOUND(((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.x, 
                                ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.y, 
                                editor_ptr->input.x, editor_ptr->input.y, 
                                editor_ptr->input.width,
                                editor_ptr->input.height))
            {
                *((U32 *)msg_ptr->param_1) = 1;
                ret = MMI_TRUE;
            }
            else
            {
                ret = MMI_FALSE;
            }
        }
        else if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_UP)
        {
            if (PEN_CHECK_BOUND(((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.x, 
                                ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.y, 
                                editor_ptr->input.x, editor_ptr->input.y, 
                                editor_ptr->input.width,
                                editor_ptr->input.height))
            {
                date_input_move_to_x_y(editor_ptr, 
                                   ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.x, 
                                   ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.y);
                ret = MMI_TRUE;
            }
            else
            {
                ret = MMI_FALSE;
            }
            
        }
        
        lresult = ret;
        
        break;
#endif

    default:
        break;
    }

    return lresult;
}

#endif


#if defined(__MMI_INLINE_ITEM_TIME__)

/***************************************************************************** 
 * Inline Time Edit    
 *
 * This is Inline Time Edit Item
 *****************************************************************************/

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MAX_INLINE_TIME_ITEMS                         4
#define MAX_INLINE_TIME_DISPLAY_STRING_SIZE           24


/***************************************************************************** 
 * Typedef 
 *****************************************************************************/ 
typedef struct _inline_time_edit_history
{
    U16 history_ID;
    S16 current_focus;
    S16 current_position;
    S16 dummy;  /* Added for history issue on hardware */
    U32 flags;
    mmi_imc_history ime_history;
} inline_time_edit_history;


/***************************************************************************** 
 * Local Variable
 *****************************************************************************/
static S32 n_inline_time_items = 0;
static wgui_inline_item_time *current_wgui_inline_time_item;
static PU8 *current_wgui_inline_time_text_p;

time_input wgui_inline_time_input;
/* Displaying time edit as a menu item in the fixed list menu  */
//static time_input wgui_inline_time_input_display;
static U8 dummy_second[2];

/***************************************************************************** 
 * Function Implementation
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  handle_inline_time_edit_complete
 * DESCRIPTION
 *  complete function for inline time edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void handle_inline_time_edit_complete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    register_inline_fixed_list_keys();

    current_wgui_inline_time_item->string_construct_callback(
                                    *current_wgui_inline_time_text_p,
                                    current_wgui_inline_time_item->hours_buffer,
                                    current_wgui_inline_time_item->minutes_buffer,
                                    current_wgui_inline_time_item->AM_PM_flag);
    MMI_fixed_icontext_menuitems[wgui_inline_item_highlighted_index].item_text =
        (UI_string_type) * current_wgui_inline_time_text_p;
    register_left_softkey_handler();
    register_right_softkey_handler();

    wgui_inline_item_handled = 0;
    wgui_text_menuitem_restart_scrolling();
    redraw_current_inline_item = UI_dummy_function;
    complete_inline_item_edit = UI_dummy_function;
    set_current_time_input(NULL);
    clear_time_input_callback();
    mmi_imc_disconnect();
    g_inline_current_input_box_handler = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  redraw_inline_time_edit
 * DESCRIPTION
 *  redraw inine time edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void redraw_inline_time_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    time_input_show_background(&wgui_inline_time_input);
    show_time_input(&wgui_inline_time_input);
}


/*****************************************************************************
 * FUNCTION
 *  inline_time_edit_handle_down_arrow
 * DESCRIPTION
 *  down arrow handler of inline time edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void inline_time_edit_handle_down_arrow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__    
    wgui_inline_get_vk_status(&g_inline_vk_status);
#endif
    handle_inline_time_edit_complete();
    inline_fixed_list_goto_next_item();
}


/*****************************************************************************
 * FUNCTION
 *  inline_time_edit_handle_up_arrow
 * DESCRIPTION
 *  up arrow handler of inline time edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void inline_time_edit_handle_up_arrow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__    
    wgui_inline_get_vk_status(&g_inline_vk_status);
#endif
    handle_inline_time_edit_complete();
    inline_fixed_list_goto_previous_item();
}


/*****************************************************************************
 * FUNCTION
 *  inline_time_input_key_handler
 * DESCRIPTION
 *  key handler of inilne time input for PC
 * PARAMETERS
 *  vkey_code       [IN]     key code   
 *  key_state       [IN]     key state   
 * RETURNS
 *  void
 *****************************************************************************/
void inline_time_input_key_handler(S32 vkey_code, S32 key_state)
{
#if(MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_state)
    {
        switch (vkey_code)
        {
            case 37:
                time_input_previous_character();
                break;
            case 38:
                inline_time_edit_handle_up_arrow();
                break;
            case 39:
                time_input_next_character();
                break;
            case 40:
                inline_time_edit_handle_down_arrow();
                break;
            case 36:    /* home */
                break;
            case 35:    /* end */
                break;
            case 33:    /* page up */
                break;
            case 34:    /* page down */
                break;
            case 45:
                time_input_toggle_insert_mode();
                break;
            case 46:
                time_input_delete_current_character();
                break;
        }
    }
#else /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
    UI_UNUSED_PARAMETER(vkey_code);
    UI_UNUSED_PARAMETER(key_state);
#endif /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
}


/*****************************************************************************
 * FUNCTION
 *  inline_time_edit_get_history
 * DESCRIPTION
 *  get history buffer for inline time edit
 * PARAMETERS
 *  history_buffer      [OUT]   history buffer     
 * RETURNS
 *  history buffer
 *****************************************************************************/
U8 *inline_time_edit_get_history(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        U16 hID = (U16) (INLINE_TIME_HISTORY_ID | 0x8000);
        inline_time_edit_history *h = (inline_time_edit_history*) history_buffer;

        h->history_ID = hID;
        h->current_focus = (S16) wgui_inline_time_input.current_focus;
        if (wgui_inline_time_input.focus_input_box != NULL)
        {
            h->current_position =
                (S16) (wgui_inline_time_input.focus_input_box->current_text_p -
                       wgui_inline_time_input.focus_input_box->text);
        }
        h->flags = wgui_inline_time_input.input.flags;
        mmi_imc_get_input_method_history(&(h->ime_history));
    }
    return (history_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  inline_time_edit_set_history
 * DESCRIPTION
 *  set history buffer for inline time edit
 * PARAMETERS
 *  history_ID          [IN]   history id     
 *  history_buffer      [IN]   history buffer      
 * RETURNS
 *  1->success 0->fail
 *****************************************************************************/
U8 inline_time_edit_set_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        inline_time_edit_history *h = (inline_time_edit_history*) history_buffer;

        if (history_valid(h->history_ID, history_ID))
        {
            wgui_inline_time_input.current_focus = h->current_focus;
            time_input_reset_focus((void*)&wgui_inline_time_input);
            time_input_set_focus((void*)&wgui_inline_time_input);
            if (wgui_inline_time_input.focus_input_box != NULL)
            {
                wgui_inline_time_input.focus_input_box->current_text_p =
                    wgui_inline_time_input.focus_input_box->text + h->current_position;
            }
            wgui_inline_time_input.input.flags = h->flags;
            return (1);
        }
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  handle_inline_time_edit
 * DESCRIPTION
 *  activation function of inline time edit
 * PARAMETERS
 *  x                   [IN]        left corner's x coordinate
 *  y                   [IN]        left corner's y coordinate
 *  width               [IN]        width
 *  height              [IN]        height
 *  key_code            [IN]        key code
 *  key_event           [IN]        key event
 *  text_p              [IN]        text pointer
 *  item                [IN]        inline item
 *  flags               [IN]        flags
 *  history_buffer      [IN]        history buffer      
 * RETURNS
 *  void
 *****************************************************************************/
void handle_inline_time_edit(
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        S32 key_code,
        S32 key_event,
        U8 **text_p,
        void *item,
        U32 flags,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_time *i = (wgui_inline_item_time*) item;
    S32 xx;
    U32 dtflags = TIME_INPUT_TYPE_HH_MM; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(key_event);
    UI_UNUSED_PARAMETER(key_code);
    UI_UNUSED_PARAMETER(flags);
    wgui_current_inline_item_type = INLINE_ITEM_TYPE_TIME;

    if (mmi_fe_get_r2l_state())
    {
        xx = 1;
    }
    else
    {
        if (MMI_fixed_icontext_menuitem.text_x == 2)
        {
            xx = -1;
        }
        else
        {
            xx = MMI_fixed_icontext_menuitem.text_x;
        }
    }
    


    if (flags & INLINE_ITEM_LEFT_ALIGN)
    {
        xx = -1;
    }
    switch (flags & INLINE_ITEM_JUSTIFY_MASK)
    {
        case INLINE_ITEM_RIGHT_JUSTIFY:
            dtflags |= TIME_INPUT_RIGHT_JUSTIFY;
            break;
        case INLINE_ITEM_CENTER_JUSTIFY:
            dtflags |= TIME_INPUT_CENTER_JUSTIFY;
            break;
    }
    complete_inline_item_edit = handle_inline_time_edit_complete;
    current_wgui_inline_time_item = i;
    current_wgui_inline_time_text_p = text_p;
    
#ifndef __MMI_FTE_SUPPORT__
    if (mmi_fe_get_r2l_state())
    {
        if (flags & INLINE_ITEM_LEFT_ALIGN)
        {
            create_time_input(
                &wgui_inline_time_input,
                x + xx,
                y,
                width - xx,
                height,
                dtflags,
                i->hours_buffer,
                i->minutes_buffer,
                i->seconds_buffer);
        }
        else
        {
            create_time_input(
                &wgui_inline_time_input,
                x + xx,
                y,
                width - MMI_fixed_icontext_menuitem.text_x,
                height,
                dtflags,
                i->hours_buffer,
                i->minutes_buffer,
                i->seconds_buffer);
        }
    }
    else
    {
        create_time_input(
            &wgui_inline_time_input,
            x + xx,
            y,
            width - xx,
            height,
            dtflags,
            i->hours_buffer,
            i->minutes_buffer,
            i->seconds_buffer);
    }  

#else

    create_time_input(
                &wgui_inline_time_input,
                x,
                y,
                width,
                height,
                dtflags,
                i->hours_buffer,
                i->minutes_buffer,
                i->seconds_buffer);
#endif

#ifdef __MMI_FTE_SUPPORT__
    wgui_inline_time_input.input.flags |= TIME_INPUT_USE_PRESET_CLIP;
#endif

    if(cui_inline_is_current_cui())
    {
        cui_inline_item_replace_gui_buffer(wgui_inline_item_highlighted_index, &wgui_inline_items[wgui_inline_item_highlighted_index], &history_buffer);
    }
    else
    {
        inline_time_edit_set_history(INLINE_TIME_HISTORY_ID, history_buffer);
    }
    
    time_input_set_seperator(&wgui_inline_time_input, (UI_character_type) ':');
    time_input_show_background(&wgui_inline_time_input);
    show_time_input(&wgui_inline_time_input);
    set_current_time_input(&wgui_inline_time_input);
    time_input_register_keys();
    mmi_imc_key_register_ime_keys();
    register_keyboard_key_handler(inline_time_input_key_handler);

    /* key rule. 09.10.17 */
    SetKeyHandler(inline_time_edit_handle_down_arrow, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(inline_time_edit_handle_up_arrow, KEY_UP_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(inline_time_edit_handle_down_arrow, KEY_VOL_DOWN, KEY_EVENT_REPEAT);
    SetKeyHandler(inline_time_edit_handle_up_arrow, KEY_VOL_UP, KEY_EVENT_REPEAT);
    
    SetKeyHandler(inline_time_edit_handle_down_arrow, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(inline_time_edit_handle_up_arrow, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(inline_time_edit_handle_down_arrow, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetKeyHandler(inline_time_edit_handle_up_arrow, KEY_VOL_UP, KEY_EVENT_DOWN);
    register_time_input_callback(set_wgui_inline_list_menu_changed);
    redraw_current_inline_item = redraw_inline_time_edit;
    mmi_imc_redraw_screen_by_state();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_input_box_msg_call_back_inline_time
 * DESCRIPTION
 *  message call back function of inine time for IME
 * PARAMETERS
 *  editor_ptr          [IN]     time input pointer   
 *  msg_ptr             [IN]     message pointer        
 * RETURNS
 *  U32
 *****************************************************************************/
static U32 mmi_input_box_msg_call_back_inline_time(time_input  * editor_ptr, mmi_imc_message_struct_p msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_last = MMI_FALSE;
    S32 i, str_len;
    U32 lresult = 0;
    UI_string_type temp_str;
    UI_character_type ch; 
#ifdef __MMI_TOUCH_SCREEN__
    MMI_BOOL ret = MMI_FALSE;
#endif /* __MMI_TOUCH_SCREEN__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(editor_ptr == &wgui_inline_time_input);

    switch(msg_ptr->message_id)
    {
    case MMI_IMC_MESSAGE_INSERT_CHAR:
        
        time_input_direct_input_nodraw((UI_character_type)msg_ptr->param_0);

        redraw_inline_time_edit();

        lresult = MMI_TRUE;

        break;
        
    case MMI_IMC_MESSAGE_INSERT_STRING:
    case MMI_IMC_MESSAGE_INSERT_STRING_NO_DRAW:    
        /* Need to revise */
        temp_str = (UI_string_type)msg_ptr->param_0;
        
        str_len = (S32)mmi_ucs2strlen((const S8 *)temp_str);

        if (msg_ptr->param_1 == MMI_TRUE)
        {
            if (time_input_test_last_position(editor_ptr))
            {
                is_last = MMI_TRUE;
            }
            
            time_input_direct_input_nodraw((UI_character_type)temp_str[0]);
            
            if (!is_last)
            {
                time_input_previous_character();
            }
            
            show_time_input(editor_ptr);
        }
        else
        {
            time_input_direct_input((UI_character_type)temp_str[0]);
        }
        
        redraw_inline_time_edit();
        
        lresult = str_len;
        
        break;
        case MMI_IMC_MESSAGE_REPLACE_HIGHLIGHT_STRING:
    
        temp_str = (UI_string_type)msg_ptr->param_1;
        
        str_len = (S32)mmi_ucs2strlen((const S8 *)temp_str);

            if (time_input_test_last_position(editor_ptr))
            {
                is_last = MMI_TRUE;
            }
            
            time_input_direct_input_nodraw((UI_character_type)temp_str[0]);
            
            if (!is_last)
            {
                time_input_previous_character();
            }
            
            show_time_input(editor_ptr);
        
    redraw_inline_time_edit();
        
        lresult = str_len;
        
        break;
        
        
    case MMI_IMC_MESSAGE_CLEAR_HILIGHT:
        if (msg_ptr->param_0 == MMI_TRUE)
        {
            time_input_next_character();
        }
        break;
        
    case MMI_IMC_MESSAGE_IS_LAST_POSITION:
        lresult = (U32)time_input_test_last_position(editor_ptr);
        break;
        
    case MMI_IMC_MESSAGE_DELETE_STRING:
        
        break;
        
    case MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR:
        ch = (UI_character_type)msg_ptr->param_0;
        lresult = time_input_direct_input_nodraw(ch);
        break;

    case MMI_IMC_MESSAGE_RESET_MULTITAP_STATE:
        time_input_next_character();
        break;
        
    case MMI_IMC_MESSAGE_DELETE_CHAR:

        for (i = 0; i < (S32)msg_ptr->param_0; i++)
        {
            time_input_previous_character();
        }

        break;

    case MMI_IMC_MESSAGE_CLEAR_ALL:
       time_input_first_character();
       break;
    case MMI_IMC_MESSAGE_REDRAW:
        
        wgui_inline_time_input.current_focus = g_inline_time_current_focus;

        time_input_reset_focus((void*)&wgui_inline_time_input);
        time_input_set_focus((void*)&wgui_inline_time_input);
        
        if (wgui_inline_time_input.focus_input_box != NULL)
        {
            wgui_inline_time_input.focus_input_box->current_text_p =
                wgui_inline_time_input.focus_input_box->text + g_inline_time_current_position;
        }
        
        wgui_inline_time_input.input.flags = g_inline_time_flags;

        redraw_inline_time_edit();
        
        break;
    case MMI_IMC_MESSAGE_SET_KEY:
        time_input_register_keys();
        mmi_imc_key_register_ime_keys();
        register_keyboard_key_handler(inline_time_input_key_handler);

        /* key rule. 09.10.17 */
        SetKeyHandler(inline_time_edit_handle_down_arrow, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
        SetKeyHandler(inline_time_edit_handle_up_arrow, KEY_UP_ARROW, KEY_EVENT_REPEAT);
        SetKeyHandler(inline_time_edit_handle_down_arrow, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(inline_time_edit_handle_up_arrow, KEY_UP_ARROW, KEY_EVENT_DOWN);
        set_right_softkey_label(wgui_inline_edit_get_RSK_string());
        register_right_softkey_handler();
        set_right_softkey_function(register_inline_edit_handle_right_softkey_up, KEY_EVENT_DOWN);
        break;
    case MMI_IMC_MESSAGE_CHECK_CSK_ENABLE:
        lresult = MMI_FALSE;
        break;
    case MMI_IMC_MESSAGE_CHECK_INFO_BAR_ENABL:
        lresult = MMI_FALSE;
        break;
    
    case MMI_IMC_MESSAGE_GET_CURSOR_RECT:
        if (editor_ptr->focus_input_box->flags & UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR)
        {
            ((mmi_imc_rect_p)msg_ptr->param_0)->x = editor_ptr->focus_input_box->hilite_s_x;
            ((mmi_imc_rect_p)msg_ptr->param_0)->y = editor_ptr->focus_input_box->hilite_s_y;
            ((mmi_imc_rect_p)msg_ptr->param_0)->width = editor_ptr->focus_input_box->hilite_e_x - editor_ptr->focus_input_box->hilite_s_x + 1;
            ((mmi_imc_rect_p)msg_ptr->param_0)->height = editor_ptr->focus_input_box->hilite_e_y - editor_ptr->focus_input_box->hilite_s_y + 1;
        }
        else
        {
            ((mmi_imc_rect_p)msg_ptr->param_0)->x = UI_cursor_x1;
            ((mmi_imc_rect_p)msg_ptr->param_0)->y = UI_cursor_y1;
            ((mmi_imc_rect_p)msg_ptr->param_0)->width = UI_cursor_x2 - UI_cursor_x1 + 1;
            ((mmi_imc_rect_p)msg_ptr->param_0)->height = UI_cursor_y2 - UI_cursor_y1 + 1;
        }
        lresult = MMI_TRUE;
        break;
        
    case MMI_IMC_MESSAGE_MOVE_CURSOR:
        switch (msg_ptr->param_0)
        {
            case MMI_IMC_EDITOR_CURSOR_UP:
                for (i = 0; i <(S32)msg_ptr->param_1; i ++)
                {
                    inline_time_edit_handle_up_arrow();
                }
                break;
                
            case MMI_IMC_EDITOR_CURSOR_DOWN:
                for (i = 0; i <(S32)msg_ptr->param_1; i ++)
                {
                    inline_time_edit_handle_down_arrow();
                }
                break;
                
            case MMI_IMC_EDITOR_CURSOR_LEFT:
                for (i = 0; i <(S32)msg_ptr->param_1; i ++)
                {
                    time_input_previous_character();
                }
                break;
            case MMI_IMC_EDITOR_CURSOR_RIGHT:
                for (i = 0; i <(S32)msg_ptr->param_1; i ++)
                {
                    time_input_next_character();
                }
                break;
        }
        break;
        
    case MMI_IMC_MESSAGE_IS_BACKSPACE_DISABLED:
        lresult = MMI_TRUE;
        break;
        
#if defined(__MMI_TOUCH_SCREEN__)        
    case MMI_IMC_MESSAGE_PEN_EVENT:
        if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_DOWN)
        {
            if (PEN_CHECK_BOUND(((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.x, 
                                ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.y, 
                                editor_ptr->input.x, editor_ptr->input.y, 
                                editor_ptr->input.width,
                                editor_ptr->input.height))
            {
                *((U32 *)msg_ptr->param_1) = 1;
                ret = MMI_TRUE;
            }
            else
            {
                ret = MMI_FALSE;
            }
        }
        else if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_UP)
        {
            if (PEN_CHECK_BOUND(((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.x, 
                                ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.y, 
                                editor_ptr->input.x, editor_ptr->input.y, 
                                editor_ptr->input.width,
                                editor_ptr->input.height))
            {
                time_input_move_to_x_y(editor_ptr, 
                                   ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.x, 
                                   ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.y);
                ret = MMI_TRUE;
            }
            else
            {
                ret = MMI_FALSE;
            }
            
        }
        
        lresult = ret;
        
        break;
#endif

    default:
        break;
    }

    return lresult;
}


/*****************************************************************************
 * FUNCTION
 *  SetInlineItemTime
 * DESCRIPTION
 *  set data for inline time edit
 * PARAMETERS
 *  item                [IN]       inline item         
 *  hours_buffer        [IN]       hours buffer  
 *  minutes_buffer      [IN]       minutes buffer  
 *  AM_PM_flag          [IN]       flag for AM_PM  
 *  f                   [IN]       string construct callback 
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineItemTime(
        InlineItem *item,
        U8 *hours_buffer,
        U8 *minutes_buffer,
        U8 *AM_PM_flag,
        void (*f) (U8 *string_buffer, U8 *hours_buffer, U8 *minutes_buffer, U8 *AM_PM_flag))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_time *i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (n_inline_time_items >= MAX_INLINE_TIME_ITEMS)
    {
        return;
    }
    wgui_inline_mem_alloc_info[wgui_inline_mem_alloc_number] = item->item = wgui_inline_malloc(sizeof(wgui_inline_item_time));
    wgui_inline_mem_alloc_number++;  
    item->flags = INLINE_ITEM_TYPE_TIME;
    wgui_inline_mem_alloc_info[wgui_inline_mem_alloc_number] = item->text_p = (U8*)wgui_inline_malloc(MAX_INLINE_TIME_DISPLAY_STRING_SIZE * sizeof(U8));
    wgui_inline_mem_alloc_number++; 
    n_inline_time_items++;
    i = (wgui_inline_item_time*) item->item;
    i->hours_buffer = hours_buffer;
    i->minutes_buffer = minutes_buffer;
    i->seconds_buffer = dummy_second;
    i->AM_PM_flag = AM_PM_flag;
    i->flags = INLINE_ITEM_LEFT_JUSTIFY;
    i->string_construct_callback = f;
    i->string_construct_callback(item->text_p, i->hours_buffer, i->minutes_buffer, i->AM_PM_flag);
    item->handler = handle_inline_time_edit;
}


/*****************************************************************************
 * FUNCTION
 *  ReConfigureInlineItemTime
 * DESCRIPTION
 *  re-configure for inline time edit
 * PARAMETERS
 *  item                [IN]       inline item         
 *  hours_buffer        [IN]       hours buffer  
 *  minutes_buffer      [IN]       minutes buffer  
 *  AM_PM_flag          [IN]       flag for AM_PM  
 *  f                   [IN]       string construct callback       
 * RETURNS
 *  void
 *****************************************************************************/
void ReConfigureInlineItemTime(
        InlineItem *item,
        U8 *hours_buffer,
        U8 *minutes_buffer,
        U8 *AM_PM_flag,
        void (*f) (U8 *string_buffer, U8 *hours_buffer, U8 *minutes_buffer, U8 *AM_PM_flag))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_time *i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((item->flags & 0xff) != INLINE_ITEM_TYPE_TIME)
    {
        return;
    }
    i = (wgui_inline_item_time*) item->item;
    i->hours_buffer = hours_buffer;
    i->minutes_buffer = minutes_buffer;
    i->AM_PM_flag = AM_PM_flag;
    i->flags = 0;
    i->string_construct_callback = f;
    i->string_construct_callback(item->text_p, i->hours_buffer, i->minutes_buffer, i->AM_PM_flag);
}




/*****************************************************************************
 * FUNCTION
 *  wgui_show_inline_time_list_menuitem
 * DESCRIPTION
 *  show inline time list menuitem
 * PARAMETERS
 *  x1          [IN]  the left-top corner x1 coordinate      
 *  y1          [IN]  the left-top corner y1 coordinate      
 *  width       [IN]  width      
 *  height      [IN]  height      
 *  item        [IN]  inline item          
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_show_inline_time_list_menuitem(S32 x1, S32 y1, S32 width, S32 height, wgui_inline_item *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_time *i = (wgui_inline_item_time*) item->item;
    S32 xx;
    U32 dtflags = TIME_INPUT_TYPE_HH_MM;
    time_input wgui_inline_time_input_display = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    if (MMI_fixed_icontext_menuitem.text_x == 2)
    {
        xx = -1;
    }
    else
    {
        xx = MMI_fixed_icontext_menuitem.text_x;
    }
    if (item->flags & INLINE_ITEM_LEFT_ALIGN)
    {
        xx = -1;
    }
    switch (item->flags & INLINE_ITEM_JUSTIFY_MASK)
    {
        case INLINE_ITEM_RIGHT_JUSTIFY:
            dtflags |= DATE_INPUT_RIGHT_JUSTIFY;
            break;
        case INLINE_ITEM_CENTER_JUSTIFY:
            dtflags |= DATE_INPUT_CENTER_JUSTIFY;
            break;
    }
    wgui_set_date_time_input_unfocussed_theme();

#ifndef __MMI_FTE_SUPPORT__    
    create_time_input(
        &wgui_inline_time_input_display,
        x1 + xx,
        y1,
        width - xx,
        height,
        dtflags,
        i->hours_buffer,
        i->minutes_buffer,
        i->seconds_buffer);
    time_input_set_seperator(&wgui_inline_time_input_display, (UI_character_type) ':');

#else
    
    create_time_input(
        &wgui_inline_time_input_display,
        x1 ,
        y1,
        width,
        height,
        dtflags,
        i->hours_buffer,
        i->minutes_buffer,
        i->seconds_buffer);  
#endif

#ifdef __MMI_FTE_SUPPORT__
    wgui_inline_time_input_display.input.flags |= TIME_INPUT_USE_PRESET_CLIP;
#endif

    time_input_set_seperator(&wgui_inline_time_input_display, (UI_character_type) ':');
    /* show the different background in case of default text effect is enabled
       for the inline item type Time. */
#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
    if (IsInlineItemDefaultTextEnable())
    {
        inline_item_default_text_show_background(
            wgui_inline_time_input_display.input.x,
            wgui_inline_time_input_display.input.y,
            wgui_inline_time_input_display.input.x + wgui_inline_time_input_display.input.width - 1,
            wgui_inline_time_input_display.input.y + wgui_inline_time_input_display.input.height - 1);
    }
    else
#endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 
        time_input_show_background(&wgui_inline_time_input_display);
    time_input_reset_focus((void*)&wgui_inline_time_input_display);
    show_time_input(&wgui_inline_time_input_display);
    wgui_set_date_time_input_focussed_theme();
    gdi_layer_unlock_frame_buffer();
}

#endif


/***************************************************************************** 
 * Inline Day Of Week Select    
 *
 * This is Inline Day Of Week Select Item
 *****************************************************************************/

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MAX_INLINE_DOW_SELECT_ITEMS       2


/***************************************************************************** 
 * Typedef 
 *****************************************************************************/ 
typedef struct _inline_DOW_select_history
{
    U16 history_ID;
    S16 highlight_index;
    U32 flags;
} inline_DOW_select_history;

#if defined(__MMI_INLINE_ITEM_DOW__)


/***************************************************************************** 
 * Local Variable
 *****************************************************************************/
static S32 n_inline_DOW_items = 0;
static PU8 current_wgui_inline_DOW_states = NULL;
static PU8 *current_wgui_inline_DOW_text_p = NULL;
DOW_select MMI_inline_DOW_select;

/***************************************************************************** 
 * Function Implementation
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  clear_inline_DOW_select_keys
 * DESCRIPTION
 *  clear key handlers for inline DOW select
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clear_inline_DOW_select_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* key rule. 09.10.17 */
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_REPEAT);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_REPEAT);
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    clear_keyboard_key_handler();
    clear_inline_item_keys = UI_dummy_function;
}


/*****************************************************************************
 * FUNCTION
 *  inline_DOW_select_change_complete
 * DESCRIPTION
 *  change complete function for inline DOW select
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void inline_DOW_select_change_complete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_inline_DOW_select_keys();
    *current_wgui_inline_DOW_text_p = (U8*) "";
    MMI_fixed_icontext_menuitems[wgui_inline_item_highlighted_index].item_text = (UI_string_type) "";
    for (i = 0; i < 7; i++)
    {
        current_wgui_inline_DOW_states[i] = MMI_inline_DOW_select.states[i];
    }
    redraw_current_inline_item = UI_dummy_function;
    complete_inline_item_edit = UI_dummy_function;
#ifdef __MMI_TOUCH_SCREEN__
    wgui_current_inline_item_pen_function = UI_dummy_inline_item_pen_function;
#endif 
    clear_left_softkey();
    clear_right_softkey();
    wgui_inline_item_handled = 0;
}


/*****************************************************************************
 * FUNCTION
 *  inline_DOW_select_handle_up_arrow
 * DESCRIPTION
 *  up arrow handler of inline DOW select
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void inline_DOW_select_handle_up_arrow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inline_DOW_select_change_complete();
    inline_fixed_list_goto_previous_item();
}


/*****************************************************************************
 * FUNCTION
 *  inline_DOW_select_handle_down_arrow
 * DESCRIPTION
 *  down arrow handler of inline DOW select
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void inline_DOW_select_handle_down_arrow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inline_DOW_select_change_complete();
    inline_fixed_list_goto_next_item();
}


/*****************************************************************************
 * FUNCTION
 *  show_inline_DOW_select
 * DESCRIPTION
 *  show inline DOW select
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_inline_DOW_select(DOW_select *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* don't call the function to show background from here, call it from the
       function, which is calling this function, in case of default text effect
       is enabled. */
#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
    if (!(IsInlineItemDefaultTextEnable()))
#endif 

        show_DOW_select_background(b);
    show_DOW_select(b);
    // chnage by Leo, code revise. BLT_DOW_select(&MMI_inline_DOW_select);
    gdi_layer_blt_previous(
        b->x,
        b->y,
        b->x + b->width - 1,
        b->y + b->height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  handle_inline_DOW_select_LSK_display
 * DESCRIPTION
 *  LSK display handler of inline DOW select
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void handle_inline_DOW_select_LSK_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_inline_DOW_select.states[MMI_inline_DOW_select.highlighted_cell])
    {
        set_left_softkey_label(get_string(STR_GLOBAL_OFF));
    }
    else
    {
        set_left_softkey_label(get_string(WGUI_CATEGORY_ON_STRING_ID));
    }
    redraw_left_softkey();
}


/*****************************************************************************
 * FUNCTION
 *  handle_inline_DOW_select_LSK_up
 * DESCRIPTION
 *  LSK up handler of inline DOW select
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void handle_inline_DOW_select_LSK_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DOW_select_toggle_item(&MMI_inline_DOW_select);

#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
    if (IsInlineItemDefaultTextEnable())
    {
        show_DOW_select_background(&MMI_inline_DOW_select);
    }
#endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 

    show_inline_DOW_select(&MMI_inline_DOW_select);
    handle_inline_DOW_select_LSK_display();
    set_wgui_inline_list_menu_changed();
}


/*****************************************************************************
 * FUNCTION
 *  inline_DOW_select_previous_item
 * DESCRIPTION
 *  goto previous item for inline DOW select
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void inline_DOW_select_previous_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DOW_select_previous(&MMI_inline_DOW_select);

#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
    if (IsInlineItemDefaultTextEnable())
    {
        show_DOW_select_background(&MMI_inline_DOW_select);
    }
#endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 

    show_inline_DOW_select(&MMI_inline_DOW_select);
    handle_inline_DOW_select_LSK_display();
}


/*****************************************************************************
 * FUNCTION
 *  inline_DOW_select_next_item
 * DESCRIPTION
 *  goto next item for inline DOW select
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void inline_DOW_select_next_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DOW_select_next(&MMI_inline_DOW_select);

#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
    if (IsInlineItemDefaultTextEnable())
    {
        show_DOW_select_background(&MMI_inline_DOW_select);
    }
#endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 

    show_inline_DOW_select(&MMI_inline_DOW_select);
    handle_inline_DOW_select_LSK_display();
}


/*****************************************************************************
 * FUNCTION
 *  inline_DOW_select_keyboard_key_handler
 * DESCRIPTION
 *  keyboard key handler of inline DOW select
 * PARAMETERS
 *  vkey_code       [IN]       key code 
 *  key_state       [IN]       key state 
 * RETURNS
 *  void
 *****************************************************************************/
void inline_DOW_select_keyboard_key_handler(S32 vkey_code, S32 key_state)
{
#if(MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_state)
    {
        switch (vkey_code)
        {
            case 37:
                inline_DOW_select_previous_item();
                break;
            case 38:
                inline_DOW_select_handle_up_arrow();
                break;
            case 39:
                inline_DOW_select_next_item();
                break;
            case 40:
                inline_DOW_select_handle_down_arrow();
                break;
        }
    }
#else /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
    UI_UNUSED_PARAMETER(vkey_code);
    UI_UNUSED_PARAMETER(key_state);
#endif /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
}


/*****************************************************************************
 * FUNCTION
 *  register_inline_DOW_select_keys
 * DESCRIPTION
 *  register key handlers of inline DOW select
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_inline_DOW_select_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

     /* key rule. 09.10.17 */
    SetKeyHandler(inline_DOW_select_previous_item, KEY_LEFT_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(inline_DOW_select_next_item, KEY_RIGHT_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(inline_DOW_select_handle_up_arrow, KEY_UP_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(inline_DOW_select_handle_down_arrow, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(inline_DOW_select_handle_up_arrow, KEY_VOL_UP, KEY_EVENT_REPEAT);
    SetKeyHandler(inline_DOW_select_handle_down_arrow, KEY_VOL_DOWN, KEY_EVENT_REPEAT);
    
    SetKeyHandler(inline_DOW_select_previous_item, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(inline_DOW_select_next_item, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(inline_DOW_select_handle_up_arrow, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(inline_DOW_select_handle_down_arrow, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(inline_DOW_select_handle_up_arrow, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(inline_DOW_select_handle_down_arrow, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    register_keyboard_key_handler(inline_DOW_select_keyboard_key_handler);
}


/*****************************************************************************
 * FUNCTION
 *  redraw_inline_DOW_select
 * DESCRIPTION
 *  redraw inline DOW select
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void redraw_inline_DOW_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
    if (IsInlineItemDefaultTextEnable())
    {
        show_DOW_select_background(&MMI_inline_DOW_select);
    }
#endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 

    show_inline_DOW_select(&MMI_inline_DOW_select);
}


/*****************************************************************************
 * FUNCTION
 *  inline_DOW_select_get_history
 * DESCRIPTION
 *  get history buffer of inline DOW select
 * PARAMETERS
 *  history_buffer      [OUT]   history buffer     
 * RETURNS
 *  history buffer
 *****************************************************************************/
U8 *inline_DOW_select_get_history(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        U16 hID = (U16) (INLINE_DOW_SELECT_HISTORY_ID | 0x8000);
        inline_DOW_select_history *h = (inline_DOW_select_history*) history_buffer;

        h->history_ID = hID;
        h->highlight_index = (S16) MMI_inline_DOW_select.highlighted_cell;
        h->flags = MMI_inline_DOW_select.flags;
    }
    return (history_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  inline_DOW_select_set_history
 * DESCRIPTION
 *  set history buffer into MMI_inline_DOW_select 
 * PARAMETERS
 *  history_ID          [IN]   history id     
 *  history_buffer      [IN]   history buffer         
 * RETURNS
 *  1->success 0->fail
 *****************************************************************************/
U8 inline_DOW_select_set_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        inline_DOW_select_history *h = (inline_DOW_select_history*) history_buffer;

        if (history_valid(h->history_ID, history_ID))
        {
            MMI_inline_DOW_select.flags = h->flags;
            MMI_inline_DOW_select.highlighted_cell = (U8) h->highlight_index;
            return (1);
        }
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  initialize_inline_DOW_select
 * DESCRIPTION
 *  initialize inline DOW select
 * PARAMETERS
 *  x                   [IN]       left-top x coordinate 
 *  y                   [IN]       left-top y coordinate 
 *  width               [IN]       width 
 *  height              [IN]       height 
 *  list_of_states      [IN]       list of states  
 *  history_buffer      [IN]       history buffer  
 * RETURNS
 *  void
 *****************************************************************************/
void initialize_inline_DOW_select(DOW_select *b, S32 x, S32 y, S32 width, S32 height, U8 *list_of_states, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    create_DOW_select(b, x, y, width, height);
    for (i = 0; i < 7; i++)
    {
        b->states[i] = list_of_states[i];
    }
    current_wgui_inline_DOW_states = list_of_states;
    
    if(cui_inline_is_current_cui())
    {
        cui_inline_item_replace_gui_buffer(wgui_inline_item_highlighted_index, &wgui_inline_items[wgui_inline_item_highlighted_index], &history_buffer);
    }
    else
    {
        inline_DOW_select_set_history(INLINE_DOW_SELECT_HISTORY_ID, history_buffer);
    }

}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  inline_DOW_select_pen_handler
 * DESCRIPTION
 *  pen handler of inline DOW select
 * PARAMETERS
 *  pen_event       [IN]        pen event
 *  x               [IN]        pen x position
 *  y               [IN]        pen y pisition
 *  item_event      [IN]         inline pen enum
 * RETURNS
 *  BOOL
 *****************************************************************************/
BOOL inline_DOW_select_pen_handler(
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_inline_item_pen_enum *item_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret;
    DOW_pen_event_enum DOW_event;
    gui_pen_event_param_struct DOW_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = DOW_translate_pen_event(&MMI_inline_DOW_select, pen_event, x, y, &DOW_event, &DOW_param);

    if (ret)
    {
        switch (DOW_event)
        {
            case DOW_PEN_CHANGE_HIGHLIGHT_AND_TOGGLE_I:
                DOW_select_highlight_item(&MMI_inline_DOW_select, DOW_param._u.i);
                /* FALLTHROUGH no break */
            case DOW_PEN_TOGGLE_CURRENT_ITEM:
                DOW_select_toggle_item(&MMI_inline_DOW_select);

        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
                if (IsInlineItemDefaultTextEnable())
                {
                    show_DOW_select_background(&MMI_inline_DOW_select);
                }
        #endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 

                show_inline_DOW_select(&MMI_inline_DOW_select);
                handle_inline_DOW_select_LSK_display();
                set_wgui_inline_list_menu_changed();
                break;
            case DOW_PEN_NONE:
                /* Do nothing */
                break;
            default:
                MMI_ASSERT(0);
        }
    }

    *item_event = GUI_INLINE_ITEM_PEN_NONE;
    return ret;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  handle_inline_DOW_select
 * DESCRIPTION
 *  activation function of inline DOW select
 * PARAMETERS
 *  x                   [IN]        left corner's x coordinate
 *  y                   [IN]        left corner's y coordinate
 *  width               [IN]        width
 *  height              [IN]        height
 *  key_code            [IN]        key code
 *  key_event           [IN]        key event
 *  text_p              [IN]        text pointer
 *  item                [IN]        inline item
 *  flags               [IN]        flags
 *  history_buffer      [IN]        history buffer        
 * RETURNS
 *  void
 *****************************************************************************/
void handle_inline_DOW_select(
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        S32 key_code,
        S32 key_event,
        U8 **text_p,
        void *item,
        U32 flags,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_DOW_select *i = (wgui_inline_item_DOW_select*) item;
    S32 xx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(key_event);
    UI_UNUSED_PARAMETER(key_code);
    UI_UNUSED_PARAMETER(flags);
    wgui_current_inline_item_type = INLINE_ITEM_TYPE_DOW_SELECT;
    if (MMI_fixed_icontext_menuitem.text_x == 2)
    {
        xx = -1;
    }
    else
    {
        xx = MMI_fixed_icontext_menuitem.text_x;
    }
    if (flags & INLINE_ITEM_LEFT_ALIGN)
    {
        xx = -1;
    }
    clear_inline_item_keys = clear_inline_DOW_select_keys;
    current_wgui_inline_DOW_text_p = text_p;


#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
    if (IsInlineItemDefaultTextEnable())
    {
        initialize_inline_DOW_select(&MMI_inline_DOW_select, x, y, width, height, i->list_of_states, history_buffer);
    }
    else
#endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 

#ifdef __MMI_FTE_SUPPORT__
        initialize_inline_DOW_select(&MMI_inline_DOW_select, x, y, width, height, i->list_of_states, history_buffer);
        set_DOW_select_flags(&MMI_inline_DOW_select, DOW_SELECT_STATE_FOCUSED);   
        MMI_inline_DOW_select.flags |= DOW_SELECT_USE_PRESET_CLIP;
#else
        initialize_inline_DOW_select(&MMI_inline_DOW_select, x + xx, y, width - xx, height, i->list_of_states, history_buffer);
#endif

#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
    if (IsInlineItemDefaultTextEnable())
    {
        show_DOW_select_background(&MMI_inline_DOW_select);
    }
#endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 

#ifdef __MMI_FTE_SUPPORT__
    /* When SSP, it will call DOW complete function which will reset softkey function; but it will not
    call default_highlight_handler(), so we must call register_default_hide_softkey() by DOW self.*/
    register_default_hide_softkeys();
#endif

    handle_inline_DOW_select_LSK_display();
    
    register_left_softkey_handler();
    set_left_softkey_function(handle_inline_DOW_select_LSK_up, KEY_EVENT_UP);
    set_right_softkey_label(wgui_inline_edit_get_RSK_string());
    register_right_softkey_handler();
    set_right_softkey_function(execute_wgui_inline_edit_RSK_function, KEY_EVENT_UP);

    show_inline_DOW_select(&MMI_inline_DOW_select);
    redraw_left_softkey();
    redraw_right_softkey();
    register_inline_DOW_select_keys();
    complete_inline_item_edit = inline_DOW_select_change_complete;
    redraw_current_inline_item = redraw_inline_DOW_select;
#ifdef __MMI_TOUCH_SCREEN__
    wgui_current_inline_item_pen_function = inline_DOW_select_pen_handler;
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  SetInlineItemDOWSelect
 * DESCRIPTION
 *  set data for inline DOW select
 * PARAMETERS
 *  item                [IN]    inline item         
 *  item_index          [IN]    item index    
 *  list_of_states      [IN]    list of states     
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineItemDOWSelect(InlineItem *item, S32 item_index, U8 *list_of_states)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_DOW_select *i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (n_inline_DOW_items >= MAX_INLINE_DOW_SELECT_ITEMS)
    {
        return;
    }

    wgui_inline_mem_alloc_info[wgui_inline_mem_alloc_number] = item->item = wgui_inline_malloc(sizeof(wgui_inline_item_DOW_select));
    wgui_inline_mem_alloc_number++; 
    item->flags = INLINE_ITEM_TYPE_DOW_SELECT;
    n_inline_DOW_items++;
    i = (wgui_inline_item_DOW_select*) item->item;
    i->flags = 0;
    i->list_of_states = list_of_states;
    item->handler = handle_inline_DOW_select;
    MMI_fixed_icontext_menuitems[item_index].flags |= UI_MENUITEM_INLINE_EDIT_OBJECT;
}


/*****************************************************************************
 * FUNCTION
 *  ReConfigureInlineItemDOWSelect
 * DESCRIPTION
 *  re-configure inline DOW select
 * PARAMETERS
 *  item                [IN]    inline item         
 *  item_index          [IN]    item index    
 *  list_of_states      [IN]    list of states           
 * RETURNS
 *  void
 *****************************************************************************/
void ReConfigureInlineItemDOWSelect(InlineItem *item, S32 item_index, U8 *list_of_states)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_DOW_select *i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((item->flags & 0xff) != INLINE_ITEM_TYPE_DOW_SELECT)
    {
        return;
    }
    i = (wgui_inline_item_DOW_select*) item->item;
    i->flags = 0;
    i->list_of_states = list_of_states;
}

/* Displaying DOW select as a menu item in the fixed list menu */


/*****************************************************************************
 * FUNCTION
 *  wgui_show_DOW_list_menuitem
 * DESCRIPTION
 *  show DOW list menuitem
 * PARAMETERS
 *  x1          [IN]  the left-top corner x1 coordinate      
 *  y1          [IN]  the left-top corner y1 coordinate      
 *  width       [IN]  width      
 *  height      [IN]  height      
 *  item        [IN]   inline item          
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_show_DOW_list_menuitem(S32 x1, S32 y1, S32 width, S32 height, wgui_inline_item *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 xx;
    wgui_inline_item_DOW_select *i = (wgui_inline_item_DOW_select*) item->item;
    DOW_select inline_dow_select_display = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_icontext_menuitem.text_x == 2)
    {
        xx = -1;
    }
    else
    {
        xx = MMI_fixed_icontext_menuitem.text_x;
    }
    if (i->flags & INLINE_ITEM_LEFT_ALIGN)
    {
        xx = -1;
    }
    gdi_layer_lock_frame_buffer();

#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
    if (IsInlineItemDefaultTextEnable())
    {
        initialize_inline_DOW_select(&inline_dow_select_display, x1, y1, width, height, i->list_of_states, NULL);
    }
    else
#endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 

#ifdef __MMI_FTE_SUPPORT__
    initialize_inline_DOW_select(&inline_dow_select_display, x1, y1, width, height, i->list_of_states, NULL);
/*
    if((item->flags & INLINE_ITEM_DISABLED) != 0)
    {
        set_DOW_select_flags(&inline_dow_select_display, DOW_SELECT_STATE_DISABLED);  
    }
    else
*/    
    {
       set_DOW_select_flags(&inline_dow_select_display, DOW_SELECT_STATE_NORMAL);   
    }   
#else
        initialize_inline_DOW_select(&inline_dow_select_display, x1 + xx, y1, width - xx, height, i->list_of_states, NULL);
#endif

    inline_dow_select_display.flags |= DOW_SELECT_USE_PRESET_CLIP;

    set_DOW_select_list_menu_theme(&inline_dow_select_display);

#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
    if (IsInlineItemDefaultTextEnable())
    {
        inline_item_default_text_show_background((x1 - 1), y1, (x1 - 1) + (width - 1), y1 + height - 1);
    }
#endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 
   
    show_inline_DOW_select(&inline_dow_select_display);
    gdi_layer_unlock_frame_buffer();
}

#endif

#if defined (__MMI_INLINE_ITEM_TIME_PEROID__)
/***************************************************************************** 
 * Inline Time Period Edit    
 *
 * This is Inline Time Period Edit Item
 *****************************************************************************/

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MAX_INLINE_TIME_PERIOD_ITEMS                        2
#define MAX_INLINE_TIME_PERIOD_DISPLAY_STRING_SIZE          32

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/  
typedef struct _inline_time_period_edit_history
{
    U16 history_ID;
    S16 current_focus;
    S16 current_position;
    S16 dummy;  /* Added for history issue on hardware */
    U32 flags;
    mmi_imc_history ime_history;
} inline_time_period_edit_history;


/***************************************************************************** 
 * Local Variable
 *****************************************************************************/
static S32 n_inline_time_period_items = 0;
static wgui_inline_item_time_period *current_wgui_inline_time_period_item;
static PU8 *current_wgui_inline_time_period_text_p;

time_period_input wgui_inline_time_period_input;

/* Displaying time period edit as a menu item in the fixed list menu */

//time_period_input wgui_inline_time_period_input_display;

/***************************************************************************** 
 * Extern Global Variable
 *****************************************************************************/
extern UI_filled_area time_period_input_background_filler;


/***************************************************************************** 
 * Function Implementation
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  handle_inline_time_period_edit_complete
 * DESCRIPTION
 *  complete function of inline time period edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void handle_inline_time_period_edit_complete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    register_inline_fixed_list_keys();

    current_wgui_inline_time_period_item->string_construct_callback(
                                            *current_wgui_inline_time_period_text_p,
                                            current_wgui_inline_time_period_item->hours_buffer1,
                                            current_wgui_inline_time_period_item-> minutes_buffer1,
                                            current_wgui_inline_time_period_item->AM_PM_flag1,
                                            current_wgui_inline_time_period_item->hours_buffer2,
                                            current_wgui_inline_time_period_item-> minutes_buffer2,
                                            current_wgui_inline_time_period_item->AM_PM_flag2);
    MMI_fixed_icontext_menuitems[wgui_inline_item_highlighted_index].item_text =
        (UI_string_type) * current_wgui_inline_time_period_text_p;
    clear_left_softkey();
    clear_right_softkey();
    register_left_softkey_handler();
    register_right_softkey_handler();

    wgui_inline_item_handled = 0;
    wgui_text_menuitem_restart_scrolling();
    redraw_current_inline_item = UI_dummy_function;
    complete_inline_item_edit = UI_dummy_function;
    set_current_time_period_input(NULL);
    clear_time_period_input_callback();
    mmi_imc_disconnect();
    g_inline_current_input_box_handler = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  redraw_inline_time_period_edit
 * DESCRIPTION
 *  redraw inine time period edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void redraw_inline_time_period_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    time_period_input_show_background(&wgui_inline_time_period_input);
    show_time_period_input(&wgui_inline_time_period_input);
}


/*****************************************************************************
 * FUNCTION
 *  inline_time_period_edit_handle_down_arrow
 * DESCRIPTION
 *  down arrow handler of inline time period edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void inline_time_period_edit_handle_down_arrow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__    
    wgui_inline_get_vk_status(&g_inline_vk_status);
#endif
    handle_inline_time_period_edit_complete();
    inline_fixed_list_goto_next_item();
}


/*****************************************************************************
 * FUNCTION
 *  inline_time_period_edit_handle_up_arrow
 * DESCRIPTION
 *  up arrow handler of inline time period edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void inline_time_period_edit_handle_up_arrow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__    
    wgui_inline_get_vk_status(&g_inline_vk_status);
#endif
    handle_inline_time_period_edit_complete();
    inline_fixed_list_goto_previous_item();
}


/*****************************************************************************
 * FUNCTION
 *  inline_time_period_input_key_handler
 * DESCRIPTION
 *  input key handler of inline time period for PC
 * PARAMETERS
 *  vkey_code       [IN]    key code    
 *  key_state       [IN]    key state    
 * RETURNS
 *  void
 *****************************************************************************/
void inline_time_period_input_key_handler(S32 vkey_code, S32 key_state)
{
#if(MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_state)
    {
        switch (vkey_code)
        {
            case 37:
                time_period_input_previous_character();
                break;
            case 38:
                inline_time_period_edit_handle_up_arrow();
                break;
            case 39:
                time_period_input_next_character();
                break;
            case 40:
                inline_time_period_edit_handle_down_arrow();
                break;
            case 36:    /* home */
                break;
            case 35:    /* end */
                break;
            case 33:    /* page up */
                break;
            case 34:    /* page down */
                break;
            case 45:
                time_period_input_toggle_insert_mode();
                break;
            case 46:
                time_period_input_delete_current_character();
                break;
        }
    }
#else /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
    UI_UNUSED_PARAMETER(vkey_code);
    UI_UNUSED_PARAMETER(key_state);
#endif /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
}


/*****************************************************************************
 * FUNCTION
 *  inline_time_period_edit_get_history
 * DESCRIPTION
 *  get history buffer of inline time period edit
 * PARAMETERS
 *  history_buffer      [OUT]   history buffer     
 * RETURNS
 *  History buffer
 *****************************************************************************/
U8 *inline_time_period_edit_get_history(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        U16 hID = (U16) (INLINE_TIME_PERIOD_HISTORY_ID | 0x8000);
        inline_time_period_edit_history *h = (inline_time_period_edit_history*) history_buffer;

        h->history_ID = hID;
        h->current_focus = (S16) wgui_inline_time_period_input.current_focus;
        if (wgui_inline_time_period_input.focus_input_box != NULL)
        {
            h->current_position =
                (S16) (wgui_inline_time_period_input.focus_input_box->current_text_p -
                       wgui_inline_time_period_input.focus_input_box->text);
        }
        h->flags = wgui_inline_time_period_input.input.flags;
        mmi_imc_get_input_method_history(&(h->ime_history));
    }
    return (history_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  inline_time_period_edit_set_history
 * DESCRIPTION
 *  set history buffer into wgui_inline_time_period_input
 * PARAMETERS
 *  history_ID          [IN]    history id        
 *  history_buffer      [IN]    history buffer     
 * RETURNS
 *  1->success 0->fail
 *****************************************************************************/
U8 inline_time_period_edit_set_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        inline_time_period_edit_history *h = (inline_time_period_edit_history*) history_buffer;

        if (history_valid(h->history_ID, history_ID))
        {
            wgui_inline_time_period_input.current_focus = h->current_focus;
            time_period_input_reset_focus((void*)&wgui_inline_time_period_input);
            time_period_input_set_focus((void*)&wgui_inline_time_period_input);
            if (wgui_inline_time_period_input.focus_input_box != NULL)
            {
                wgui_inline_time_period_input.focus_input_box->current_text_p =
                    wgui_inline_time_period_input.focus_input_box->text + h->current_position;
            }
            wgui_inline_time_period_input.input.flags = h->flags;
            return (1);
        }
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  handle_inline_time_period_edit
 * DESCRIPTION
 *  activation function of inline time period edit
 * PARAMETERS
 *  x                   [IN]        left corner's x coordinate
 *  y                   [IN]        left corner's y coordinate
 *  width               [IN]        width
 *  height              [IN]        height
 *  key_code            [IN]        key code
 *  key_event           [IN]        key event
 *  text_p              [IN]        text pointer
 *  item                [IN]        inline item
 *  flags               [IN]        flags
 *  history_buffer      [IN]        history buffer         
 * RETURNS
 *  void
 *****************************************************************************/
void handle_inline_time_period_edit(
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        S32 key_code,
        S32 key_event,
        U8 **text_p,
        void *item,
        U32 flags,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_time_period *i = (wgui_inline_item_time_period*) item;
    S32 xx;
    U32 dtflags = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(key_code);
    UI_UNUSED_PARAMETER(key_event);
    UI_UNUSED_PARAMETER(flags);
    wgui_current_inline_item_type = INLINE_ITEM_TYPE_TIME_PERIOD;
    /* MTK Elvis for R2L characters */
    if (mmi_fe_get_r2l_state())
    {
        xx = 6;
    }
    else
    {
        if (MMI_fixed_icontext_menuitem.text_x == 2)
        {
            xx = -1;
        }
        else
        {
            xx = MMI_fixed_icontext_menuitem.text_x;
        }
    }
    
    /* MTK end */
    if (flags & INLINE_ITEM_LEFT_ALIGN)
    {
        xx = -1;
    }
    switch (flags & INLINE_ITEM_JUSTIFY_MASK)
    {
        case INLINE_ITEM_RIGHT_JUSTIFY:
            dtflags |= TIME_PERIOD_INPUT_RIGHT_JUSTIFY;
            break;
        case INLINE_ITEM_CENTER_JUSTIFY:
            dtflags |= TIME_PERIOD_INPUT_CENTER_JUSTIFY;
            break;
    }
    if (flags & INLINE_ITEM_DISABLE_HIGHLIGHT)
    {
        time_period_input_background_filler = MMI_inputbox_normal_filler;       /* *MMI_fixed_list_menu.normal_filler; */
        time_period_input_background_filler.flags &= 0x00000fff;
    }
    else
    {
        time_period_input_background_filler = MMI_inputbox_normal_filler;       /* *MMI_fixed_icontext_menuitem.focussed_filler; */
        time_period_input_background_filler.flags &= 0x00000fff;
    }
    complete_inline_item_edit = handle_inline_time_period_edit_complete;
    current_wgui_inline_time_period_item = i;
    current_wgui_inline_time_period_text_p = text_p;

#ifndef __MMI_FTE_SUPPORT__
    if (mmi_fe_get_r2l_state())
    {
        create_time_period_input(
            &wgui_inline_time_period_input,
            x + xx,
            y,
            width - 1 - MMI_fixed_icontext_menuitem.text_x,
            height,
            dtflags,
            i->hours_buffer1,
            i->minutes_buffer1,
            i->hours_buffer2,
            i->minutes_buffer2);
    }
    else
    {
        create_time_period_input(
            &wgui_inline_time_period_input,
            x + xx,
            y,
            width - 1 - xx,
            height,
            dtflags,
            i->hours_buffer1,
            i->minutes_buffer1,
            i->hours_buffer2,
            i->minutes_buffer2);
    }

#else

    create_time_period_input(
            &wgui_inline_time_period_input,
            x,
            y,
            width,
            height,
            dtflags,
            i->hours_buffer1,
            i->minutes_buffer1,
            i->hours_buffer2,
            i->minutes_buffer2);
#endif

#ifdef __MMI_FTE_SUPPORT__
    wgui_inline_time_period_input.input.flags |= TIME_PERIOD_INPUT_USE_PRESET_CLIP;
#endif

    if(cui_inline_is_current_cui())
    {
        cui_inline_item_replace_gui_buffer(wgui_inline_item_highlighted_index, &wgui_inline_items[wgui_inline_item_highlighted_index], &history_buffer);
    }
    else
    {
        inline_time_period_edit_set_history(INLINE_TIME_PERIOD_HISTORY_ID, history_buffer);
    }
    
    time_period_input_set_seperators(&wgui_inline_time_period_input, (UI_character_type) ':', (UI_character_type) '-');
    time_period_input_show_background(&wgui_inline_time_period_input);
    show_time_period_input(&wgui_inline_time_period_input);
    set_current_time_period_input(&wgui_inline_time_period_input);
    time_period_input_register_keys();
    mmi_imc_key_register_ime_keys();
    register_keyboard_key_handler(inline_time_period_input_key_handler);

    /* key rule. 09.10.17 */
    SetKeyHandler(inline_time_period_edit_handle_down_arrow, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(inline_time_period_edit_handle_up_arrow, KEY_UP_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(inline_time_period_edit_handle_down_arrow, KEY_VOL_DOWN, KEY_EVENT_REPEAT);
    SetKeyHandler(inline_time_period_edit_handle_up_arrow, KEY_VOL_UP, KEY_EVENT_REPEAT);
    
    SetKeyHandler(inline_time_period_edit_handle_down_arrow, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(inline_time_period_edit_handle_up_arrow, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(inline_time_period_edit_handle_down_arrow, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetKeyHandler(inline_time_period_edit_handle_up_arrow, KEY_VOL_UP, KEY_EVENT_DOWN);
    register_time_period_input_callback(set_wgui_inline_list_menu_changed);
    redraw_current_inline_item = redraw_inline_time_period_edit;
    mmi_imc_redraw_screen_by_state();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_input_box_msg_call_back_inline_time_period
 * DESCRIPTION
 *  message callback function of inline time period for IME
 * PARAMETERS
 *  editor_ptr          [IN]      time period input pointer  
 *  msg_ptr             [IN]      message pointer       
 * RETURNS
 *  U32
 *****************************************************************************/
static U32 mmi_input_box_msg_call_back_inline_time_period(time_period_input  * editor_ptr, mmi_imc_message_struct_p msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_last = MMI_FALSE;
    S32 i, str_len;
    U32 lresult = 0;
    UI_string_type temp_str;
    UI_character_type ch; 
#ifdef __MMI_TOUCH_SCREEN__
    MMI_BOOL ret = MMI_FALSE;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(editor_ptr == &wgui_inline_time_period_input);

    switch(msg_ptr->message_id)
    {
    case MMI_IMC_MESSAGE_INSERT_CHAR:
        
        time_period_input_direct_input_nodraw((UI_character_type)msg_ptr->param_0);

        redraw_inline_time_period_edit();

        lresult = MMI_TRUE;
        
        break;
        
    case MMI_IMC_MESSAGE_INSERT_STRING:
    case MMI_IMC_MESSAGE_INSERT_STRING_NO_DRAW:    
        /* Need to revise */
        temp_str = (UI_string_type)msg_ptr->param_0;
        
        str_len = (S32)mmi_ucs2strlen((const S8 *)temp_str);

        if (msg_ptr->param_1 == MMI_TRUE)
        {
            if (time_period_input_test_last_position(editor_ptr))
            {
                is_last = MMI_TRUE;
            }
            
            time_period_input_direct_input_nodraw((UI_character_type)temp_str[0]);
            
            if (!is_last)
            {
                time_period_input_previous_character();
            }
            
            show_time_period_input(editor_ptr);
        }
        else
        {
            time_period_input_direct_input((UI_character_type)temp_str[0]);
        }

        redraw_inline_time_period_edit();

        lresult = str_len;
        break;
    case MMI_IMC_MESSAGE_REPLACE_HIGHLIGHT_STRING:
    
        temp_str = (UI_string_type)msg_ptr->param_1;
        
        str_len = (S32)mmi_ucs2strlen((const S8 *)temp_str);

            if (time_period_input_test_last_position(editor_ptr))
            {
                is_last = MMI_TRUE;
            }
            
            time_period_input_direct_input_nodraw((UI_character_type)temp_str[0]);
            
            if (!is_last)
            {
                time_period_input_previous_character();
            }
            
            show_time_period_input(editor_ptr);

        redraw_inline_time_period_edit();

        lresult = str_len;
        break;

    case MMI_IMC_MESSAGE_CLEAR_HILIGHT:
        if (msg_ptr->param_0 == MMI_TRUE)
        {
            time_period_input_next_character();
        }
        break;
        
    case MMI_IMC_MESSAGE_IS_LAST_POSITION:
        lresult = (U32)time_period_input_test_last_position(editor_ptr);
        break;
        
    case MMI_IMC_MESSAGE_DELETE_STRING:
        
        break;
        
    case MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR:
        ch = (UI_character_type)msg_ptr->param_0;
        lresult = time_period_input_direct_input_nodraw(ch);
        break;

    case MMI_IMC_MESSAGE_RESET_MULTITAP_STATE:
        time_period_input_next_character();
        break;
        
    case MMI_IMC_MESSAGE_DELETE_CHAR:

        for (i = 0; i < (S32)msg_ptr->param_0; i++)
        {
            time_period_input_previous_character();
        }

        break;
    case MMI_IMC_MESSAGE_CLEAR_ALL:
    
        time_period_input_first_character();
    
        break;
       
    case MMI_IMC_MESSAGE_REDRAW:
        
        wgui_inline_time_period_input.current_focus = g_inline_time_period_current_focus;

        time_period_input_reset_focus((void*)&wgui_inline_time_period_input);
        time_period_input_set_focus((void*)&wgui_inline_time_period_input);

        if (wgui_inline_time_period_input.focus_input_box != NULL)
        {
            wgui_inline_time_period_input.focus_input_box->current_text_p =
                wgui_inline_time_period_input.focus_input_box->text + g_inline_time_period_current_position;
        }
        
        wgui_inline_time_period_input.input.flags = g_inline_time_period_flags;
        
        redraw_inline_time_period_edit();
        
        break;
        
    case MMI_IMC_MESSAGE_SET_KEY:
        time_period_input_register_keys();
        mmi_imc_key_register_ime_keys();
        register_keyboard_key_handler(inline_time_period_input_key_handler);

        /* key rule. 09.10.17  KEY_EVENT_REPEAT */
        SetKeyHandler(inline_time_period_edit_handle_down_arrow, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
        SetKeyHandler(inline_time_period_edit_handle_up_arrow, KEY_UP_ARROW, KEY_EVENT_REPEAT);
        SetKeyHandler(inline_time_period_edit_handle_down_arrow, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(inline_time_period_edit_handle_up_arrow, KEY_UP_ARROW, KEY_EVENT_DOWN);
        set_right_softkey_label(wgui_inline_edit_get_RSK_string());
        register_right_softkey_handler();
        set_right_softkey_function(register_inline_edit_handle_right_softkey_up, KEY_EVENT_DOWN);
        break;
    case MMI_IMC_MESSAGE_CHECK_CSK_ENABLE:
        lresult = MMI_FALSE;
        break;
    case MMI_IMC_MESSAGE_CHECK_INFO_BAR_ENABL:
        lresult = MMI_FALSE;
        break;
        
    case MMI_IMC_MESSAGE_GET_CURSOR_RECT:
        if (editor_ptr->focus_input_box->flags & UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR)
        {
            ((mmi_imc_rect_p)msg_ptr->param_0)->x = editor_ptr->focus_input_box->hilite_s_x;
            ((mmi_imc_rect_p)msg_ptr->param_0)->y = editor_ptr->focus_input_box->hilite_s_y;
            ((mmi_imc_rect_p)msg_ptr->param_0)->width = editor_ptr->focus_input_box->hilite_e_x - editor_ptr->focus_input_box->hilite_s_x + 1;
            ((mmi_imc_rect_p)msg_ptr->param_0)->height = editor_ptr->focus_input_box->hilite_e_y - editor_ptr->focus_input_box->hilite_s_y + 1;
        }
        else
        {
            ((mmi_imc_rect_p)msg_ptr->param_0)->x = UI_cursor_x1;
            ((mmi_imc_rect_p)msg_ptr->param_0)->y = UI_cursor_y1;
            ((mmi_imc_rect_p)msg_ptr->param_0)->width = UI_cursor_x2 - UI_cursor_x1 + 1;
            ((mmi_imc_rect_p)msg_ptr->param_0)->height = UI_cursor_y2 - UI_cursor_y1 + 1;
        }
        lresult = MMI_TRUE;
        break;
        
    case MMI_IMC_MESSAGE_MOVE_CURSOR:
        switch (msg_ptr->param_0)
        {
            case MMI_IMC_EDITOR_CURSOR_UP:
                for (i = 0; i <(S32)msg_ptr->param_1; i ++)
                {
                    inline_time_period_edit_handle_up_arrow();
                }
                break;
                
            case MMI_IMC_EDITOR_CURSOR_DOWN:
                for (i = 0; i <(S32)msg_ptr->param_1; i ++)
                {
                    inline_time_period_edit_handle_down_arrow();
                }
                break;
                
            case MMI_IMC_EDITOR_CURSOR_LEFT:
                for (i = 0; i <(S32)msg_ptr->param_1; i ++)
                {
                    time_period_input_previous_character();
                }
                break;
            case MMI_IMC_EDITOR_CURSOR_RIGHT:
                for (i = 0; i <(S32)msg_ptr->param_1; i ++)
                {
                    time_period_input_next_character();
                }
                break;
        }
        break;
        
    case MMI_IMC_MESSAGE_IS_BACKSPACE_DISABLED:
        lresult = MMI_TRUE;
        break;
        
#if defined(__MMI_TOUCH_SCREEN__)        
    case MMI_IMC_MESSAGE_PEN_EVENT:
        if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_DOWN)
        {
            if (PEN_CHECK_BOUND(((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.x, 
                                ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.y, 
                                editor_ptr->input.x, editor_ptr->input.y, 
                                editor_ptr->input.width,
                                editor_ptr->input.height))
            {
                *((U32 *)msg_ptr->param_1) = 1;
                ret = MMI_TRUE;
            }
            else
            {
                ret = MMI_FALSE;
            }
        }
        else if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_UP)
        {
            if (PEN_CHECK_BOUND(((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.x, 
                                ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.y, 
                                editor_ptr->input.x, editor_ptr->input.y, 
                                editor_ptr->input.width,
                                editor_ptr->input.height))
            {
                time_period_input_move_to_x_y(editor_ptr, 
                                   ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.x, 
                                   ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.y);
                ret = MMI_TRUE;
            }
            else
            {
                ret = MMI_FALSE;
            }
            
        }
        
        lresult = ret;
        
        break;
#endif

    default:
        break;
    }

    return lresult;
}


/*****************************************************************************
 * FUNCTION
 *  SetInlineItemTimePeriod
 * DESCRIPTION
 *  set data of inline timer period edit
 * PARAMETERS
 *  item                [IN]      inine item   
 *  hours_buffer1       [IN]      hours buffer1   
 *  minutes_buffer1     [IN]      minutes buffer1   
 *  AM_PM_flag1         [IN]      flag1 of AM_PM   
 *  hours_buffer2       [IN]      hours buffer2   
 *  minutes_buffer2     [IN]      minutes buffer2   
 *  AM_PM_flag2         [IN]      flag2 of AM_PM   
 *  f                   [IN]      string construct callback  
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineItemTimePeriod(
        InlineItem *item,
        U8 *hours_buffer1,
        U8 *minutes_buffer1,
        U8 *AM_PM_flag1,
        U8 *hours_buffer2,
        U8 *minutes_buffer2,
        U8 *AM_PM_flag2,
        void (*f) (U8 *string_buffer, U8 *hours_buffer1, U8 *minutes_buffer1, U8 *AM_PM_flag1, U8 *hours_buffer2, U8 *minutes_buffer2, U8 *AM_PM_flag2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_time_period *i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (n_inline_time_period_items >= MAX_INLINE_TIME_PERIOD_ITEMS)
    {
        return;
    }
    wgui_inline_mem_alloc_info[wgui_inline_mem_alloc_number] = item->item = wgui_inline_malloc(sizeof(wgui_inline_item_time_period));
    wgui_inline_mem_alloc_number++; 
    item->flags = INLINE_ITEM_TYPE_TIME_PERIOD;
    wgui_inline_mem_alloc_info[wgui_inline_mem_alloc_number] = item->text_p = (U8*)wgui_inline_malloc(MAX_INLINE_TIME_PERIOD_DISPLAY_STRING_SIZE * sizeof(U8));
    wgui_inline_mem_alloc_number++; 
    n_inline_time_period_items++;
    i = (wgui_inline_item_time_period*) item->item;
    i->hours_buffer1 = hours_buffer1;
    i->minutes_buffer1 = minutes_buffer1;
    i->AM_PM_flag1 = AM_PM_flag1;
    i->hours_buffer2 = hours_buffer2;
    i->minutes_buffer2 = minutes_buffer2;
    i->AM_PM_flag2 = AM_PM_flag2;
    i->flags = INLINE_ITEM_LEFT_JUSTIFY;
    i->string_construct_callback = f;
    i->string_construct_callback(
        item->text_p,
        i->hours_buffer1,
        i->minutes_buffer1,
        i->AM_PM_flag1,
        i->hours_buffer2,
        i->minutes_buffer2,
        i->AM_PM_flag2);
    item->handler = handle_inline_time_period_edit;
}


/*****************************************************************************
 * FUNCTION
 *  ReConfigureInlineItemTimePeriod
 * DESCRIPTION
 *  re-configure data of inline time period
 * PARAMETERS
 *  item                [IN]      inine item   
 *  hours_buffer1       [IN]      hours buffer1   
 *  minutes_buffer1     [IN]      minutes buffer1   
 *  AM_PM_flag1         [IN]      flag1 of AM_PM   
 *  hours_buffer2       [IN]      hours buffer2   
 *  minutes_buffer2     [IN]      minutes buffer2   
 *  AM_PM_flag2         [IN]      flag2 of AM_PM   
 *  f                   [IN]      string construct callback        
 * RETURNS
 *  void
 *****************************************************************************/
void ReConfigureInlineItemTimePeriod(
        InlineItem *item,
        U8 *hours_buffer1,
        U8 *minutes_buffer1,
        U8 *AM_PM_flag1,
        U8 *hours_buffer2,
        U8 *minutes_buffer2,
        U8 *AM_PM_flag2,
        void (*f) (U8 *string_buffer, U8 *hours_buffer1, U8 *minutes_buffer1, U8 *AM_PM_flag1, U8 *hours_buffer2, U8 *minutes_buffer2, U8 *AM_PM_flag2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_time_period *i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((item->flags & 0xff) != INLINE_ITEM_TYPE_TIME_PERIOD)
    {
        return;
    }
    i = (wgui_inline_item_time_period*) item->item;
    i->hours_buffer1 = hours_buffer1;
    i->minutes_buffer1 = minutes_buffer1;
    i->AM_PM_flag1 = AM_PM_flag1;
    i->hours_buffer2 = hours_buffer2;
    i->minutes_buffer2 = minutes_buffer2;
    i->AM_PM_flag2 = AM_PM_flag2;
    i->flags = 0;
    i->string_construct_callback = f;
    i->string_construct_callback(
        item->text_p,
        i->hours_buffer1,
        i->minutes_buffer1,
        i->AM_PM_flag1,
        i->hours_buffer2,
        i->minutes_buffer2,
        i->AM_PM_flag2);
}



/*****************************************************************************
 * FUNCTION
 *  wgui_show_inline_time_period_list_menuitem
 * DESCRIPTION
 *  show inline time period list menuitem
 * PARAMETERS
 *  x1          [IN]       left-top corner x1 coordinate 
 *  y1          [IN]       left-top corner y1 coordinate 
 *  width       [IN]       width 
 *  height      [IN]       height 
 *  item        [IN]       inline item  
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_show_inline_time_period_list_menuitem(S32 x1, S32 y1, S32 width, S32 height, wgui_inline_item *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_time_period *i = (wgui_inline_item_time_period*) item->item;
    S32 xx;
    U32 dtflags = TIME_INPUT_TYPE_HH_MM;
    time_period_input wgui_inline_time_period_input_display = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    if (MMI_fixed_icontext_menuitem.text_x == 2)
    {
        xx = -1;
    }
    else
    {
        xx = MMI_fixed_icontext_menuitem.text_x;
    }
    if (item->flags & INLINE_ITEM_LEFT_ALIGN)
    {
        xx = -1;
    }
    switch (item->flags & INLINE_ITEM_JUSTIFY_MASK)
    {
        case INLINE_ITEM_RIGHT_JUSTIFY:
            dtflags |= DATE_INPUT_RIGHT_JUSTIFY;
            break;
        case INLINE_ITEM_CENTER_JUSTIFY:
            dtflags |= DATE_INPUT_CENTER_JUSTIFY;
            break;
    }
    wgui_set_date_time_input_unfocussed_theme();
#ifndef __MMI_FTE_SUPPORT__    
    create_time_period_input(
        &wgui_inline_time_period_input_display,
        x1 + xx,
        y1,
        width - 1 - xx,
        height,
        dtflags,
        i->hours_buffer1,
        i->minutes_buffer1,
        i->hours_buffer2,
        i->minutes_buffer2);
    
#else

     create_time_period_input(
        &wgui_inline_time_period_input_display,
        x1,
        y1,
        width,
        height,
        dtflags,
        i->hours_buffer1,
        i->minutes_buffer1,
        i->hours_buffer2,
        i->minutes_buffer2);
#endif
    
#ifdef __MMI_FTE_SUPPORT__
    wgui_inline_time_period_input_display.input.flags |= TIME_PERIOD_INPUT_USE_PRESET_CLIP;
#endif

    time_period_input_set_seperators(
        &wgui_inline_time_period_input_display,
        (UI_character_type) ':',
        (UI_character_type) '-');
    time_period_input_show_background(&wgui_inline_time_period_input_display);
    time_period_input_reset_focus((void*)&wgui_inline_time_period_input_display);
    show_time_period_input(&wgui_inline_time_period_input_display);
    wgui_set_date_time_input_focussed_theme();
    gdi_layer_unlock_frame_buffer();
}

#endif


#ifdef __MMI_INLINE_ITEM_IP4__

/***************************************************************************** 
 * Inline IP4 Edit    
 *
 * This is Inline IP4 Edit Item
 *****************************************************************************/

/***************************************************************************** 
 * Define
 *****************************************************************************/
#ifdef LOW_COST_SUPPORT
#define MAX_INLINE_IP4_ITEMS                    5
#else
#define MAX_INLINE_IP4_ITEMS                    5 /* wireless lan need 5 items */
#endif
#define MAX_INLINE_IP4_DISPLAY_STRING_SIZE      48


/***************************************************************************** 
 * Typedef 
 *****************************************************************************/  
typedef struct _inline_IP4_edit_history
{
    U16 history_ID;
    S16 current_focus;
    S16 current_position;
    S16 dummy;  /* Added for history issue on hardware */
    U32 flags;
    mmi_imc_history ime_history;
} inline_IP4_edit_history;


/***************************************************************************** 
 * Local Variable
 *****************************************************************************/
static S32 n_inline_IP4_items = 0;
static wgui_inline_item_IP4 *current_wgui_inline_IP4_item;
static PU8 *current_wgui_inline_IP4_text_p;
IP4_input wgui_inline_IP4_input;

/* Displaying IP address edit as a menu item in the fixed list menu  */
//static IP4_input wgui_inline_IP4_input_display;

/***************************************************************************** 
 * Function Implementation
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  handle_inline_IP4_edit_complete
 * DESCRIPTION
 *  complete function of inline IP4 edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void handle_inline_IP4_edit_complete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    register_inline_fixed_list_keys();
    current_wgui_inline_IP4_item->string_construct_callback(
                                    *current_wgui_inline_IP4_text_p,
                                    current_wgui_inline_IP4_item->b1,
                                    current_wgui_inline_IP4_item->b2,
                                    current_wgui_inline_IP4_item->b3,
                                    current_wgui_inline_IP4_item->b4);
    MMI_fixed_icontext_menuitems[wgui_inline_item_highlighted_index].item_text =
        (UI_string_type) * current_wgui_inline_IP4_text_p;
    register_left_softkey_handler();
    register_right_softkey_handler();

    wgui_inline_item_handled = 0;
    wgui_text_menuitem_restart_scrolling();
    redraw_current_inline_item = UI_dummy_function;
    complete_inline_item_edit = UI_dummy_function;
    set_current_IP4_input(NULL);
    clear_IP4_input_callback();
    mmi_imc_disconnect();
    g_inline_current_input_box_handler = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  redraw_inline_IP4_edit
 * DESCRIPTION
 *  redraw inline IP4 edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void redraw_inline_IP4_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IP4_input_show_background(&wgui_inline_IP4_input);
    show_IP4_input(&wgui_inline_IP4_input);
}


/*****************************************************************************
 * FUNCTION
 *  inline_IP4_edit_handle_down_arrow
 * DESCRIPTION
 *  down arrow handler onf inline IP4 edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void inline_IP4_edit_handle_down_arrow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_inline_edit_is_able_to_switch_highlight(1))
    {
#ifdef __MMI_FTE_SUPPORT__    
        wgui_inline_get_vk_status(&g_inline_vk_status);
#endif
        handle_inline_IP4_edit_complete();
        inline_fixed_list_goto_next_item();
    }

}


/*****************************************************************************
 * FUNCTION
 *  inline_IP4_edit_handle_up_arrow
 * DESCRIPTION
 *  up arrow handler onf inline IP4 edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void inline_IP4_edit_handle_up_arrow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_inline_edit_is_able_to_switch_highlight(0))
    {
#ifdef __MMI_FTE_SUPPORT__    
        wgui_inline_get_vk_status(&g_inline_vk_status);
#endif
        handle_inline_IP4_edit_complete();
        inline_fixed_list_goto_previous_item();
    }
}


/*****************************************************************************
 * FUNCTION
 *  inline_IP4_input_key_handler
 * DESCRIPTION
 *  input key handler of inline IP4 for PC
 * PARAMETERS
 *  vkey_code       [IN]      key code  
 *  key_state       [IN]      key state  
 * RETURNS
 *  void
 *****************************************************************************/
void inline_IP4_input_key_handler(S32 vkey_code, S32 key_state)
{
#if(MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_state)
    {
        switch (vkey_code)
        {
            case 37:
                IP4_input_previous_character();
                break;
            case 38:
                inline_IP4_edit_handle_up_arrow();
                break;
            case 39:
                IP4_input_next_character();
                break;
            case 40:
                inline_IP4_edit_handle_down_arrow();
                break;
            case 36:    /* home */
                break;
            case 35:    /* end */
                break;
            case 33:    /* page up */
                break;
            case 34:    /* page down */
                break;
            case 45:
                IP4_input_toggle_insert_mode();
                break;
            case 46:
                IP4_input_delete_current_character();
                break;
        }
    }
#else /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
    UI_UNUSED_PARAMETER(vkey_code);
    UI_UNUSED_PARAMETER(key_state);
#endif /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
}


/*****************************************************************************
 * FUNCTION
 *  inline_IP4_edit_get_history
 * DESCRIPTION
 *  get history buffer of inline IP4 edit
 * PARAMETERS
 *  history_buffer      [OUT]   history buffer     
 * RETURNS
 *  history buffer
 *****************************************************************************/
U8 *inline_IP4_edit_get_history(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        U16 hID = (U16) (INLINE_IP4_HISTORY_ID | 0x8000);
        inline_IP4_edit_history *h = (inline_IP4_edit_history*) history_buffer;

        h->history_ID = hID;
        h->current_focus = (S16) wgui_inline_IP4_input.current_focus;
        if (wgui_inline_IP4_input.focus_input_box != NULL)
        {
            h->current_position =
                (S16) (wgui_inline_IP4_input.focus_input_box->current_text_p -
                       wgui_inline_IP4_input.focus_input_box->text);
        }
        h->flags = wgui_inline_IP4_input.input.flags;
        mmi_imc_get_input_method_history(&(h->ime_history));
    }
    return (history_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  inline_IP4_edit_set_history
 * DESCRIPTION
 *  set history buffer into wgui_inline_IP4_input
 * PARAMETERS
 *  history_ID          [IN]    history id    
 *  history_buffer      [IN]    history buffer         
 * RETURNS
 *  1->success 0->fail
 *****************************************************************************/
U8 inline_IP4_edit_set_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        inline_IP4_edit_history *h = (inline_IP4_edit_history*) history_buffer;

        if (history_valid(h->history_ID, history_ID))
        {
            wgui_inline_IP4_input.current_focus = h->current_focus;
            IP4_input_reset_focus((void*)&wgui_inline_IP4_input);
            IP4_input_set_focus((void*)&wgui_inline_IP4_input);
            if (wgui_inline_IP4_input.focus_input_box != NULL)
            {
                wgui_inline_IP4_input.focus_input_box->current_text_p =
                    wgui_inline_IP4_input.focus_input_box->text + h->current_position;
            }
            wgui_inline_IP4_input.input.flags = h->flags;
            return (1);
        }
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  handle_inline_IP4_edit
 * DESCRIPTION
 *  activation function of inline IP4 edit
 * PARAMETERS
 *  x                   [IN]        left corner's x coordinate
 *  y                   [IN]        left corner's y coordinate
 *  width               [IN]        width
 *  height              [IN]        height
 *  key_code            [IN]        key code
 *  key_event           [IN]        key event
 *  text_p              [IN]        text pointer
 *  item                [IN]        inline item
 *  flags               [IN]        flags
 *  history_buffer      [IN]        history buffer           
 * RETURNS
 *  void
 *****************************************************************************/
void handle_inline_IP4_edit(
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        S32 key_code,
        S32 key_event,
        U8 **text_p,
        void *item,
        U32 flags,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_IP4 *i = (wgui_inline_item_IP4*) item;
    S32 xx;
    U32 dtflags = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(key_event);
    UI_UNUSED_PARAMETER(key_code);
    UI_UNUSED_PARAMETER(flags);
    wgui_current_inline_item_type = INLINE_ITEM_TYPE_IP4_EDIT;
    /* MTK Elvis for R2L characters */
    if (mmi_fe_get_r2l_state())
    {
        xx = 1;
    }
    else
    {
        if (MMI_fixed_icontext_menuitem.text_x == 2)
        {
            xx = -1;
        }
        else
        {
            xx = MMI_fixed_icontext_menuitem.text_x;
        }
    }
    
    /* MTK end */
    if (flags & INLINE_ITEM_LEFT_ALIGN)
    {
        xx = -1;
    }
    switch (flags & INLINE_ITEM_JUSTIFY_MASK)
    {
        case INLINE_ITEM_RIGHT_JUSTIFY:
            dtflags |= IP4_INPUT_RIGHT_JUSTIFY;
            break;
        case INLINE_ITEM_CENTER_JUSTIFY:
            dtflags |= IP4_INPUT_CENTER_JUSTIFY;
            break;
    }
    complete_inline_item_edit = handle_inline_IP4_edit_complete;
    current_wgui_inline_IP4_item = i;
    current_wgui_inline_IP4_text_p = text_p;

    /* Ignore mmi_fe_get_r2l_state() */
#if !defined(__MMI_FTE_SUPPORT__)
    create_IP4_input(
        &wgui_inline_IP4_input,
        x + xx,
        y,
        width - xx,
        height,
        dtflags,
        i->b1,
        i->b2,
        i->b3,
        i->b4);
#else /* __MMI_FTE_SUPPORT__ */
    create_IP4_input(
        &wgui_inline_IP4_input,
        x,
        y,
        width,
        height,
        dtflags,
        i->b1,
        i->b2,
        i->b3,
        i->b4);
    wgui_inline_IP4_input.input.flags |= IP4_INPUT_USE_PRESET_CLIP;
#endif /* __MMI_FTE_SUPPORT__ */

    if(cui_inline_is_current_cui())
    {
        cui_inline_item_replace_gui_buffer(wgui_inline_item_highlighted_index, &wgui_inline_items[wgui_inline_item_highlighted_index], &history_buffer);
    }
    else
    {
        inline_IP4_edit_set_history(INLINE_IP4_HISTORY_ID, history_buffer);
    }
    
    IP4_input_set_seperator(&wgui_inline_IP4_input, (UI_character_type) '.');
    IP4_input_show_background(&wgui_inline_IP4_input);
    show_IP4_input(&wgui_inline_IP4_input);
    set_current_IP4_input(&wgui_inline_IP4_input);
    IP4_input_register_keys();
    mmi_imc_key_register_ime_keys();
    register_keyboard_key_handler(inline_IP4_input_key_handler);

    /* key rule. 09.10.17  KEY_EVENT_REPEAT */

    SetKeyHandler(inline_IP4_edit_handle_down_arrow, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(inline_IP4_edit_handle_up_arrow, KEY_UP_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(inline_IP4_edit_handle_down_arrow, KEY_VOL_DOWN, KEY_EVENT_REPEAT);
    SetKeyHandler(inline_IP4_edit_handle_up_arrow, KEY_VOL_UP, KEY_EVENT_REPEAT);
    SetKeyHandler(inline_IP4_edit_handle_down_arrow, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(inline_IP4_edit_handle_up_arrow, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(inline_IP4_edit_handle_down_arrow, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetKeyHandler(inline_IP4_edit_handle_up_arrow, KEY_VOL_UP, KEY_EVENT_DOWN);
    register_IP4_input_callback(set_wgui_inline_list_menu_changed);
    redraw_current_inline_item = redraw_inline_IP4_edit;
    UI_UNUSED_PARAMETER(xx);
    
    mmi_imc_redraw_screen_by_state();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_input_box_msg_call_back_inline_ip4
 * DESCRIPTION
 *  message callback function of inline IP4 for IME
 * PARAMETERS
 *  editor_ptr        [IN]         IP4 input pointer
 *  msg_ptr           [IN]         message pointer
 * RETURNS
 *  U32
 *****************************************************************************/
static U32 mmi_input_box_msg_call_back_inline_ip4(IP4_input  * editor_ptr, mmi_imc_message_struct_p msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_last = MMI_FALSE;
    S32 i, str_len;
    U32 lresult = 0;
    UI_string_type temp_str;
    UI_character_type ch;
#ifdef __MMI_TOUCH_SCREEN__
    MMI_BOOL ret = MMI_FALSE;
#endif /* __MMI_TOUCH_SCREEN__ */ 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(editor_ptr == &wgui_inline_IP4_input);

    switch(msg_ptr->message_id)
    {
    case MMI_IMC_MESSAGE_INSERT_CHAR:
        
        IP4_input_direct_input_nodraw((UI_character_type)msg_ptr->param_0);

        redraw_inline_IP4_edit();

        lresult = MMI_FALSE;
        break;
        
    case MMI_IMC_MESSAGE_INSERT_STRING:
    case MMI_IMC_MESSAGE_INSERT_STRING_NO_DRAW:     
        /* Need to revise */
        temp_str = (UI_string_type)msg_ptr->param_0;
        
        str_len = (S32)mmi_ucs2strlen((const S8 *)temp_str);

        if (msg_ptr->param_1 == MMI_TRUE)
        {
            if (IP4_input_test_last_position(editor_ptr))
            {
                is_last = MMI_TRUE;
            }
            
            IP4_input_direct_input_nodraw((UI_character_type)temp_str[0]);
            
            if (!is_last)
            {
                IP4_input_previous_character();
            }
            
            show_IP4_input(editor_ptr);
        }
        else
        {
            IP4_input_direct_input((UI_character_type)temp_str[0]);
        }

        redraw_inline_IP4_edit();

        lresult = str_len;
        break;

        case MMI_IMC_MESSAGE_REPLACE_HIGHLIGHT_STRING:     
        /* Need to revise */
        temp_str = (UI_string_type)msg_ptr->param_1;
        
        str_len = (S32)mmi_ucs2strlen((const S8 *)temp_str);

            if (IP4_input_test_last_position(editor_ptr))
            {
                is_last = MMI_TRUE;
            }
            
            IP4_input_direct_input_nodraw((UI_character_type)temp_str[0]);
            
            if (!is_last)
            {
                IP4_input_previous_character();
            }
            
            show_IP4_input(editor_ptr);

        redraw_inline_IP4_edit();

        lresult = str_len;
        break;  

    case MMI_IMC_MESSAGE_CLEAR_HILIGHT:
        if (msg_ptr->param_0 == MMI_TRUE)
        {
            IP4_input_next_character();
        }
        break;
        
    case MMI_IMC_MESSAGE_IS_LAST_POSITION:
        lresult = (U32)IP4_input_test_last_position(editor_ptr);
        break;
        
    case MMI_IMC_MESSAGE_DELETE_STRING:
        
        break;
        
    case MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR:
        ch = (UI_character_type)msg_ptr->param_0;
        lresult = IP4_input_direct_input_nodraw(ch);
        break;

    case MMI_IMC_MESSAGE_RESET_MULTITAP_STATE:
        IP4_input_next_character();
        break;
        
    case MMI_IMC_MESSAGE_DELETE_CHAR:

        for (i = 0; i < (S32)msg_ptr->param_0; i++)
        {
            IP4_input_previous_character();
        }

        break;
    case MMI_IMC_MESSAGE_CLEAR_ALL:    
        IP4_input_first_character();    
        break;
    case MMI_IMC_MESSAGE_SET_KEY:
        IP4_input_register_keys();
        mmi_imc_key_register_ime_keys();
        register_keyboard_key_handler(inline_IP4_input_key_handler);

        /* key rule. 09.10.17  KEY_EVENT_REPEAT */
        SetKeyHandler(inline_IP4_edit_handle_down_arrow, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
        SetKeyHandler(inline_IP4_edit_handle_up_arrow, KEY_UP_ARROW, KEY_EVENT_REPEAT);
        SetKeyHandler(inline_IP4_edit_handle_down_arrow, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(inline_IP4_edit_handle_up_arrow, KEY_UP_ARROW, KEY_EVENT_DOWN);
        set_right_softkey_label(wgui_inline_edit_get_RSK_string());
        register_right_softkey_handler();
        set_right_softkey_function(register_inline_edit_handle_right_softkey_up, KEY_EVENT_DOWN);
        break;
        
    case MMI_IMC_MESSAGE_CHECK_CSK_ENABLE:
        lresult = MMI_FALSE;
        break;
        
    case MMI_IMC_MESSAGE_CHECK_INFO_BAR_ENABL:
        lresult = MMI_FALSE;
        break;
    case MMI_IMC_MESSAGE_REDRAW:
        
        wgui_inline_IP4_input.current_focus = g_inline_IP4_current_focus;

        IP4_input_reset_focus((void*)&wgui_inline_IP4_input);
        IP4_input_set_focus((void*)&wgui_inline_IP4_input);

        if (wgui_inline_IP4_input.focus_input_box != NULL)
        {
            wgui_inline_IP4_input.focus_input_box->current_text_p =
                wgui_inline_IP4_input.focus_input_box->text + g_inline_IP4_current_position;
        }

        wgui_inline_IP4_input.input.flags = g_inline_IP4_flags;
        
        redraw_inline_IP4_edit();
        
        break;

    case MMI_IMC_MESSAGE_GET_CURSOR_RECT:
        if (editor_ptr->focus_input_box->flags & UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR)
        {
            ((mmi_imc_rect_p)msg_ptr->param_0)->x = editor_ptr->focus_input_box->hilite_s_x;
            ((mmi_imc_rect_p)msg_ptr->param_0)->y = editor_ptr->focus_input_box->hilite_s_y;
            ((mmi_imc_rect_p)msg_ptr->param_0)->width = editor_ptr->focus_input_box->hilite_e_x - editor_ptr->focus_input_box->hilite_s_x + 1;
            ((mmi_imc_rect_p)msg_ptr->param_0)->height = editor_ptr->focus_input_box->hilite_e_y - editor_ptr->focus_input_box->hilite_s_y + 1;
        }
        else
        {
            ((mmi_imc_rect_p)msg_ptr->param_0)->x = UI_cursor_x1;
            ((mmi_imc_rect_p)msg_ptr->param_0)->y = UI_cursor_y1;
            ((mmi_imc_rect_p)msg_ptr->param_0)->width = UI_cursor_x2 - UI_cursor_x1 + 1;
            ((mmi_imc_rect_p)msg_ptr->param_0)->height = UI_cursor_y2 - UI_cursor_y1 + 1;
        }
        lresult = MMI_TRUE;
        break;

    case MMI_IMC_MESSAGE_MOVE_CURSOR:
        switch (msg_ptr->param_0)
        {
            case MMI_IMC_EDITOR_CURSOR_UP:
                for (i = 0; i <(S32)msg_ptr->param_1; i ++)
                {
                    inline_IP4_edit_handle_up_arrow();
                }
                break;
                
            case MMI_IMC_EDITOR_CURSOR_DOWN:
                for (i = 0; i <(S32)msg_ptr->param_1; i ++)
                {
                    inline_IP4_edit_handle_down_arrow();
                }
                break;
                
            case MMI_IMC_EDITOR_CURSOR_LEFT:
                for (i = 0; i <(S32)msg_ptr->param_1; i ++)
                {
                    IP4_input_previous_character();
                }
                break;
            case MMI_IMC_EDITOR_CURSOR_RIGHT:
                for (i = 0; i <(S32)msg_ptr->param_1; i ++)
                {
                    IP4_input_next_character();
                }
                break;
        }
        break;
        
    case MMI_IMC_MESSAGE_IS_BACKSPACE_DISABLED:
        lresult = MMI_TRUE;
        break;
        
#if defined(__MMI_TOUCH_SCREEN__)        
    case MMI_IMC_MESSAGE_PEN_EVENT:
        if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_DOWN)
        {
            if (PEN_CHECK_BOUND(((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.x, 
                                ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.y, 
                                editor_ptr->input.x, editor_ptr->input.y, 
                                editor_ptr->input.width,
                                editor_ptr->input.height))
            {
                *((U32 *)msg_ptr->param_1) = 1;
                ret = MMI_TRUE;
            }
            else
            {
                ret = MMI_FALSE;
            }
        }
        else if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_UP)
        {
            if (PEN_CHECK_BOUND(((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.x, 
                                ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.y, 
                                editor_ptr->input.x, editor_ptr->input.y, 
                                editor_ptr->input.width,
                                editor_ptr->input.height))
            {
                IP4_input_move_to_x_y(editor_ptr, 
                                   ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.x, 
                                   ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.y);
                ret = MMI_TRUE;
            }
            else
            {
                ret = MMI_FALSE;
            }
            
        }
        
        lresult = ret;
        
        break;
#endif

    default:
        break;
    }

    return lresult;
}


/*****************************************************************************
 * FUNCTION
 *  SetInlineItemIP4
 * DESCRIPTION
 *  set data of inline IP4 edit
 * PARAMETERS
 *  item        [IN]    inline item         
 *  b1          [IN]    address part 1     
 *  b2          [IN]    address part 2     
 *  b3          [IN]    address part 3     
 *  b4          [IN]    address part 4     
 *  f           [IN]    string construct callback    
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineItemIP4(
        InlineItem *item,
        U8 *b1,
        U8 *b2,
        U8 *b3,
        U8 *b4,
        void (*f) (U8 *string_buffer, U8 *b1, U8 *b2, U8 *b3, U8 *b4))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_IP4 *i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (n_inline_IP4_items >= MAX_INLINE_IP4_ITEMS)
    {
        return;
    }
    wgui_inline_mem_alloc_info[wgui_inline_mem_alloc_number] = item->item = wgui_inline_malloc(sizeof(wgui_inline_item_IP4));
    wgui_inline_mem_alloc_number++; 
    item->flags = INLINE_ITEM_TYPE_IP4_EDIT;
    wgui_inline_mem_alloc_info[wgui_inline_mem_alloc_number] = item->text_p = (U8*)wgui_inline_malloc(MAX_INLINE_IP4_DISPLAY_STRING_SIZE * sizeof(U8));
    wgui_inline_mem_alloc_number++; 
    n_inline_IP4_items++;
    i = (wgui_inline_item_IP4*) item->item;
    i->b1 = b1;
    i->b2 = b2;
    i->b3 = b3;
    i->b4 = b4;
    i->flags = INLINE_ITEM_LEFT_JUSTIFY;
    i->string_construct_callback = f;
    i->string_construct_callback(item->text_p, i->b1, i->b2, i->b3, i->b4);
    item->handler = handle_inline_IP4_edit;
}


/*****************************************************************************
 * FUNCTION
 *  ReConfigureInlineItemIP4
 * DESCRIPTION
 *  re-configure data of inline IP4 edit
 * PARAMETERS
 *  item        [IN]    inline item         
 *  b1          [IN]    address part 1     
 *  b2          [IN]    address part 2     
 *  b3          [IN]    address part 3     
 *  b4          [IN]    address part 4     
 *  f           [IN]    string construct callback        
 * RETURNS
 *  void
 *****************************************************************************/
void ReConfigureInlineItemIP4(
        InlineItem *item,
        U8 *b1,
        U8 *b2,
        U8 *b3,
        U8 *b4,
        void (*f) (U8 *string_buffer, U8 *b1, U8 *b2, U8 *b3, U8 *b4))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_IP4 *i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((item->flags & 0xff) != INLINE_ITEM_TYPE_IP4_EDIT)
    {
        return;
    }
    i = (wgui_inline_item_IP4*) item->item;
    i->b1 = b1;
    i->b2 = b2;
    i->b3 = b3;
    i->b4 = b4;
    i->flags = 0;
    i->string_construct_callback = f;
    i->string_construct_callback(item->text_p, i->b1, i->b2, i->b3, i->b4);
}



/*****************************************************************************
 * FUNCTION
 *  wgui_show_inline_IP4_list_menuitem
 * DESCRIPTION
 *  show inline IP4 list menuitem
 * PARAMETERS
 *  x1                  [IN]    left-top corner x1 coordinate    
 *  y1                  [IN]    left-top corner y1 coordinate    
 *  width               [IN]    width    
 *  height              [IN]    height          
 *  item                [IN]    inline item      
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_show_inline_IP4_list_menuitem(S32 x1, S32 y1, S32 width, S32 height, wgui_inline_item *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_IP4 *i = (wgui_inline_item_IP4*) item->item;
    S32 xx;
    U32 dtflags = 0;
    IP4_input wgui_inline_IP4_input_display = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    if (MMI_fixed_icontext_menuitem.text_x == 2)
    {
        xx = -1;
    }
    else
    {
        xx = MMI_fixed_icontext_menuitem.text_x;
    }
    if (item->flags & INLINE_ITEM_LEFT_ALIGN)
    {
        xx = -1;
    }
    switch (item->flags & INLINE_ITEM_JUSTIFY_MASK)
    {
        case INLINE_ITEM_RIGHT_JUSTIFY:
            dtflags |= DATE_INPUT_RIGHT_JUSTIFY;
            break;
        case INLINE_ITEM_CENTER_JUSTIFY:
            dtflags |= DATE_INPUT_CENTER_JUSTIFY;
            break;
    }

    wgui_set_date_time_input_unfocussed_theme();
    
#ifndef __MMI_FTE_SUPPORT__    
    create_IP4_input(
        &wgui_inline_IP4_input_display,
        x1 - 1,
        y1,
        width + 1,
        height,
        dtflags,
        i->b1,
        i->b2,
        i->b3,
        i->b4);
    
#else
    create_IP4_input(
        &wgui_inline_IP4_input_display,
        x1,
        y1,
        width,
        height,
        dtflags,
        i->b1,
        i->b2,
        i->b3,
        i->b4);
#endif

    wgui_inline_IP4_input_display.input.flags |= IP4_INPUT_USE_PRESET_CLIP;

    IP4_input_set_seperator(&wgui_inline_IP4_input_display, (UI_character_type) '.');

    /* show the different background in case of default text effect is enabled
       for the inline item type IP4 Edit. */
#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
    if (IsInlineItemDefaultTextEnable())
    {
        inline_item_default_text_show_background(
            wgui_inline_IP4_input_display.input.x,
            wgui_inline_IP4_input_display.input.y,
            wgui_inline_IP4_input_display.input.x + wgui_inline_IP4_input_display.input.width - 1,
            wgui_inline_IP4_input_display.input.y + wgui_inline_IP4_input_display.input.height - 1);
    }
    else
#endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 

        IP4_input_show_background(&wgui_inline_IP4_input_display);
    IP4_input_reset_focus((void*)&wgui_inline_IP4_input_display);
    show_IP4_input(&wgui_inline_IP4_input_display);
    wgui_set_date_time_input_focussed_theme();
    gdi_layer_unlock_frame_buffer();
    UI_UNUSED_PARAMETER(xx);
}

#endif




#if defined (__MMI_INLINE_ITEM_COLOR_SELECT__)

/***************************************************************************** 
 * Inline Color Select    
 *
 * This is Inline Color Select Item
 *****************************************************************************/

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MAX_INLINE_COLOR_SELECT_ITEMS        4
#define INLINE_COLOR_SELECT_HEIGHT_SPACING   3
#define INLINE_COLOR_SELECT_WIDTH_SPACING    15
#define INLINE_COLOR_SELECT_ICON_SPACING     3


/***************************************************************************** 
 * Local Variable
 *****************************************************************************/
static U16 n_inline_color_select_items = 0;
static U16 current_wgui_inline_color_select_region_x1;
static U16 current_wgui_inline_color_select_region_y1;
static U16 current_wgui_inline_color_select_region_x2;
static U16 current_wgui_inline_color_select_region_y2;

static U16 current_wgui_inline_color_select_icon_y;
static U16 current_wgui_inline_color_select_icon1_x1;
static U16 current_wgui_inline_color_select_icon1_x2;
static U16 current_wgui_inline_color_select_icon2_x1;
static U16 current_wgui_inline_color_select_icon2_x2;
static U8 current_wgui_inline_color_select_icon1_pressed;
static U8 current_wgui_inline_color_select_icon2_pressed;
#ifdef __MMI_TOUCH_SCREEN__
static U8 current_wgui_inline_color_select_pen_on_icon1;
static U8 current_wgui_inline_color_select_pen_on_icon2;
#endif /* __MMI_TOUCH_SCREEN__ */
static U16 current_wgui_inline_color_select_box_count;
static U16 current_wgui_inline_color_select_box_size;
static U16 current_wgui_inline_color_select_box_spacing;

static wgui_inline_item_color_select *current_wgui_inline_color_select_item = NULL;

/***************************************************************************** 
 * Function Implementation
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  clear_inline_color_select_menu_keys
 * DESCRIPTION
 *  clear color inline select key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void clear_inline_color_select_menu_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* key rule. 09.10.17  KEY_EVENT_REPEAT */
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_REPEAT);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_REPEAT);
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    clear_keyboard_key_handler();
    clear_inline_item_keys = UI_dummy_function;
    UI_text_menuitem_scroll_time = UI_TEXT_MENUITEM_SCROLL_TIME;
}


/*****************************************************************************
 * FUNCTION
 *  inline_color_select_menu_change_complete
 * DESCRIPTION
 *  move out from inline color select
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void inline_color_select_menu_change_complete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_inline_color_select_menu_keys();
    wgui_inline_item_handled = 0;
    redraw_current_inline_item = UI_dummy_function;
    complete_inline_item_edit = UI_dummy_function;
#ifdef __MMI_TOUCH_SCREEN__
    wgui_current_inline_item_pen_function = UI_dummy_inline_item_pen_function;
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  inline_color_select_menu_handle_up_arrow
 * DESCRIPTION
 *  inline color select up arrow handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void inline_color_select_menu_handle_up_arrow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inline_color_select_menu_change_complete();
    inline_fixed_list_goto_previous_item();
}


/*****************************************************************************
 * FUNCTION
 *  inline_color_select_menu_handle_down_arrow
 * DESCRIPTION
 *  inline color select down arrow handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void inline_color_select_menu_handle_down_arrow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inline_color_select_menu_change_complete();
    inline_fixed_list_goto_next_item();
}


/*****************************************************************************
 * FUNCTION
 *  show_highlighted_inline_color_select_menuitem
 * DESCRIPTION
 *  draw inline color select menu when it is highlighted
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void show_highlighted_inline_color_select_menuitem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 box_count;  /* how many color will display */
    S32 box_size;
    S32 spacing;
    S32 i;
    S32 box_x1;
    S32 box_x2;
    S32 box_y1;
    S32 box_y2;
    S32 start_x;
    U16 start_index;
    U16 highlighted_index;
    U16 color_count;
    U16 color_index;
    color *color_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* pixtel name is too long, hard to read, set to local variable first */
    box_size = current_wgui_inline_color_select_box_size;
    box_count = current_wgui_inline_color_select_box_count;
    spacing = current_wgui_inline_color_select_box_spacing;

    box_y1 = current_wgui_inline_color_select_region_y1;
    box_y2 = current_wgui_inline_color_select_region_y2;
    start_x = current_wgui_inline_color_select_region_x1;

    start_index = current_wgui_inline_color_select_item->start_index;
    highlighted_index = current_wgui_inline_color_select_item->highlighted_index;
    color_list = current_wgui_inline_color_select_item->list_of_color;
    color_count = current_wgui_inline_color_select_item->n_color;

    /* need adjst start index */
    if (start_index == 255)
    {
        /* total color is less then box, always start at 0 */
        if (box_count > color_count)
        {
            start_index = 0;
        }
        else
        {
            if (color_count - highlighted_index >= box_count)
            {
                /* remain color is more than box count */
                start_index = highlighted_index;
            }
            else
            {
                /* remain color not enough */
                start_index = color_count - box_count;
            }

            current_wgui_inline_color_select_item->start_index = start_index;
        }
    }

    if (start_index + box_count <= highlighted_index)
    {
        start_index = highlighted_index - box_count + 1;
        current_wgui_inline_color_select_item->start_index = start_index;
    }

    /* fill the background of the focussed Color Select menu item with modified
       parameters. */
#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
    if (IsInlineItemDefaultTextEnable())
        /* fill region with selected background color */
    {
        gui_draw_filled_area(
            current_wgui_inline_color_select_region_x1 - spacing,
            current_wgui_inline_color_select_region_y1 - spacing,
            current_wgui_inline_color_select_region_x2 + spacing,
            current_wgui_inline_color_select_region_y2 + spacing,
            current_MMI_theme->list_selected_item_filler);
    }
    else
#endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 

#ifndef __MMI_FTE_SUPPORT__
        /* fill region with selected background color */
        gui_draw_filled_area(
            current_wgui_inline_color_select_icon1_x1 - 2,
            current_wgui_inline_color_select_region_y1 - 2,
            current_wgui_inline_color_select_icon2_x2 + 2,
            current_wgui_inline_color_select_region_y2 + 2,
            current_MMI_theme->list_selected_item_filler);
#else
    {
        U8 *image = current_MMI_theme->inline_item_color_select_highlighted_bg_image;
        gdi_image_draw_resized(
            inline_color_select_control_x_coordinate, 
            inline_color_select_control_y_coordinate, 
            inline_color_select_control_width, 
            inline_color_select_control_height, 
            image);
    }        
#endif
    for (i = 0; i < box_count; i++)
    {
        box_x1 = start_x + (box_size + spacing) * i;
        box_x2 = box_x1 + box_size;

        color_index = (U16) (start_index + i);

        if (color_index >= color_count)
        {
            /* no more, get from firsr */
            color_index = color_index - color_count;
        }
#ifdef __MMI_FTE_SUPPORT__
        if (color_index == highlighted_index)
        {
            U8 *image = current_MMI_theme->inline_item_color_select_highlighted_index_image;
            gdi_handle active_layer;
            gdi_layer_get_active(&active_layer);
            gdi_push_and_set_alpha_blending_source_layer(active_layer);
            gdi_image_draw_resized(
                box_x1 - GUI_COLOR_SELECT_FTE_SELECTOR_BORDER, 
                inline_color_select_control_y_coordinate, 
                box_x2 - box_x1 + (2 *  GUI_COLOR_SELECT_FTE_SELECTOR_BORDER) + 1,
                INLINE_FTE_CONTROL_HEIGHT,
                image);
           gdi_pop_and_restore_alpha_blending_source_layer();
        }
#endif         
        gui_fill_rectangle(box_x1, box_y1, box_x2, box_y2, color_list[color_index]);

        /* if is pure blue, draw cross */
        if (color_list[color_index].r == 0 && color_list[color_index].g == 0 && color_list[color_index].b == 255)
        {
            gui_fill_rectangle(box_x1, box_y1, box_x2, box_y2, gui_color(255, 255, 255));
            gui_line(box_x1, box_y1, box_x2, box_y2, gui_color(0, 0, 0));
            gui_line(box_x2, box_y1, box_x1, box_y2, gui_color(0, 0, 0));
        }
        else
        {
            gui_fill_rectangle(box_x1, box_y1, box_x2, box_y2, color_list[color_index]);
        }

        gui_draw_rectangle(box_x1 + 1, box_y1 + 1, box_x2 - 1, box_y2 - 1, gui_color(255, 255, 255));

        if (color_index == highlighted_index)
        {
#ifndef __MMI_FTE_SUPPORT__            
            gui_draw_rectangle(box_x1, box_y1, box_x2, box_y2, gui_color(255, 0, 0));
            gui_draw_rectangle(box_x1 - 1, box_y1 - 1, box_x2 + 1, box_y2 + 1, gui_color(255, 0, 0));
#endif
        }
        else
        {
            gui_draw_rectangle(box_x1, box_y1, box_x2, box_y2, gui_color(0, 0, 0));
        }
    }

#ifdef __MMI_FTE_SUPPORT__
    {
        gdi_handle active_layer;
        U8 *image1;
        U8 *image2;
        S32 icon_width, icon_height;

        gui_measure_image((PU8)(current_MMI_theme->inline_item_select_right_arrow_push_image), &icon_width, &icon_height);
        if(current_wgui_inline_color_select_icon1_pressed  == 0)
        {
            image1 = current_MMI_theme->inline_edit_left_arrow_image;
        }
        else
        {
            image1 = current_MMI_theme->inline_item_select_left_arrow_push_image;
        }
        if(current_wgui_inline_color_select_icon2_pressed == 0)
        {
            image2 = current_MMI_theme->inline_edit_right_arrow_image;
        }
        else
        {
            image2 = current_MMI_theme->inline_item_select_right_arrow_push_image;
        }
        gdi_layer_get_active(&active_layer);
        gdi_push_and_set_alpha_blending_source_layer(active_layer);
        gdi_image_draw_resized(
            current_wgui_inline_color_select_icon1_x1, 
            inline_color_select_control_y_coordinate, 
            icon_width, 
            icon_height, 
            image1);
        gdi_image_draw_resized(
            current_wgui_inline_color_select_icon2_x1, 
            inline_color_select_control_y_coordinate, 
            icon_width, 
            icon_height, 
            image2);     
        gdi_pop_and_restore_alpha_blending_source_layer();
        
        gdi_layer_blt_previous(
            inline_color_select_control_x_coordinate, 
            inline_color_select_control_y_coordinate, 
            inline_color_select_control_width + inline_color_select_control_x_coordinate, 
            inline_color_select_control_height + inline_color_select_control_y_coordinate);        
    }
#else
    gui_show_image(
        current_wgui_inline_color_select_icon1_x1,
        current_wgui_inline_color_select_icon_y + current_wgui_inline_color_select_icon1_pressed,
        (PU8) GetImage(IMG_H_SELECT_LEFT));
    gui_show_image(
        current_wgui_inline_color_select_icon2_x1,
        current_wgui_inline_color_select_icon_y + current_wgui_inline_color_select_icon2_pressed,
        (PU8) GetImage(IMG_H_SELECT_RIGHT));

    gdi_layer_blt_previous(
        current_wgui_inline_color_select_icon1_x1 - 2,
        current_wgui_inline_color_select_region_y1 - 2,
        current_wgui_inline_color_select_icon2_x2 + 2,
        current_wgui_inline_color_select_region_y2 + 2);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_show_highlighted_inline_color_select_menuitemitem
 * DESCRIPTION
 *  show color select menu which is not selected
 * PARAMETERS
 *  x           [IN]        Menuitem start position x
 *  y           [IN]        Menuitem start position y
 *  width       [IN]        Menuitem width
 *  height      [IN]        Menuitem height
 *  item        [IN]        Selected item ptr
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_show_highlighted_inline_color_select_menuitemitem(
                S32 x,
                S32 y,
                S32 width,
                S32 height,
                wgui_inline_item *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 spacing;
    S32 region_spacing;
    S32 box_x1;
    S32 box_x2;
    S32 region_x1;
    S32 region_y1;
    S32 region_x2;
    S32 region_y2;
    S32 box_size;
    S32 box_count;
    S32 i;
    U16 color_index;
    U16 color_count;
    U16 start_index;
    S32 used_width;
    S32 region_width;
    U16 highlighted_index;
    color *color_list;

    S32 icon_width, icon_height;

    wgui_inline_item_color_select *item_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item_ptr = (wgui_inline_item_color_select*) item->item;

#ifndef __MMI_FTE_SUPPORT__
    spacing = INLINE_COLOR_SELECT_HEIGHT_SPACING;

    /* removed the hard-coded value of region_spacing. */
    /* region_spacing = INLINE_COLOR_SELECT_WIDTH_SPACING; */
    gui_measure_image((PU8) GetImage(IMG_H_SELECT_LEFT), &icon_width, &icon_height);
    region_spacing = icon_width + (2 * INLINE_COLOR_SELECT_ICON_SPACING);



    if (mmi_fe_get_r2l_state())
    {
        region_x1 = x + region_spacing - 4;
        region_x2 = x + width - MMI_fixed_icontext_menuitem.text_x - region_spacing;
    }
    else
    {
        region_x1 = x + MMI_fixed_icontext_menuitem.text_x + region_spacing - 4;        /* -4 for arrow width */
        region_x2 = x + width - region_spacing;
    }

#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
    if (IsInlineItemDefaultTextEnable())
    {
        region_x1 = x + region_spacing;
        region_x2 = x + width - region_spacing;
    }
#endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 

    region_y1 = y + spacing;
    region_y2 = y + height - spacing;
#else

    spacing = GUI_COLOR_SELECT_FTE_BOX_VERTICAL_GAP;
    gui_measure_image((PU8)(current_MMI_theme->inline_item_select_right_arrow_push_image), &icon_width, &icon_height);
    region_spacing = icon_width + GUI_COLOR_SELECT_FTE_BOX_BETWEEN_GAP;
    region_x1 = x  + region_spacing;
    region_x2 = x + width  - region_spacing - 1;  
    region_y1 = y + GUI_COLOR_SELECT_FTE_CONTROL_BORDER_WIDTH + GUI_COLOR_SELECT_FTE_BOX_VERTICAL_GAP;
    region_y2 = y + height - GUI_COLOR_SELECT_FTE_CONTROL_BORDER_WIDTH - GUI_COLOR_SELECT_FTE_BOX_VERTICAL_GAP - 1;

    {
        gdi_handle active_layer;
        U16 image1_x = x + GUI_COLOR_SELECT_FTE_CONTROL_BORDER_WIDTH;  
        U16 image2_x = x + width  - icon_width - GUI_COLOR_SELECT_FTE_CONTROL_BORDER_WIDTH; 
        U16 image_y = y;
        U8 *image1 = current_MMI_theme->inline_edit_left_arrow_image;
        U8 *image2 = current_MMI_theme->inline_edit_right_arrow_image;
        U8 *image = current_MMI_theme->inline_item_color_select_unhighlighted_bg_image;       
        gdi_image_draw_resized(
            x, 
            y, 
            width, 
            height, 
            image);
        
        gdi_layer_get_active(&active_layer);
        gdi_push_and_set_alpha_blending_source_layer(active_layer);
        
        gdi_image_draw_resized(
            image1_x, 
            image_y, 
            icon_width, 
            icon_height, 
            image1);

        gdi_image_draw_resized(
            image2_x, 
            image_y, 
            icon_width, 
            icon_height, 
            image2);
        gdi_pop_and_restore_alpha_blending_source_layer();
    }
#endif
 
    highlighted_index = item_ptr->highlighted_index;
    start_index = item_ptr->start_index;
    color_list = item_ptr->list_of_color;
    color_count = item_ptr->n_color;
    box_size = region_y2 - region_y1;
    box_count = (region_x2 - region_x1 + spacing) / (box_size + spacing);

    /* need adjst start index */
    if (start_index == 255)
    {
        /* total color is less then box, always start at 0 */
        if (box_count > color_count)
        {
            start_index = 0;
        }
        else
        {
            if (color_count - highlighted_index >= box_count)
            {
                /* remain color is more than box count */
                start_index = highlighted_index;
            }
            else
            {
                /* remain color not enough */
                start_index = (U16) (color_count - box_count);
            }

            item_ptr->start_index = start_index;
        }
    }

    /* dispatch remain spacing to both side */
    used_width = box_size * box_count + (box_count - 1) * spacing;
    region_width = region_x2 - region_x1 + 1;

    region_x1 += (region_width - used_width) >> 1;

    /* if total color is less then box count, adjust position */
    if (box_count > color_count)
    {
        box_count = color_count;

        /* adjust to center */
        used_width = box_size * box_count + (box_count - 1) * spacing;
        region_width = region_x2 - region_x1 + 1;

        region_x1 += (region_width - used_width) >> 1;
    }


#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
    if (IsInlineItemDefaultTextEnable())
    {
        inline_item_default_text_show_background((x - 1), y, (x - 1) + (width - 1), y + height);
    }
#endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 

    for (i = 0; i < box_count; i++)
    {
        box_x1 = region_x1 + (box_size + spacing) * i;
        box_x2 = box_x1 + box_size;

        color_index = (U16) (start_index + i);

        if (color_index >= color_count)
        {
            /* no more, get from firsr */
            color_index = color_index - color_count;
        }

#ifdef __MMI_FTE_SUPPORT__
        if (color_index == highlighted_index)
        {
            U8 *image = current_MMI_theme->inline_item_color_select_highlighted_index_image;
            gdi_handle active_layer;
            gdi_layer_get_active(&active_layer);
            gdi_push_and_set_alpha_blending_source_layer(active_layer);
            gdi_image_draw_resized(
                box_x1 - GUI_COLOR_SELECT_FTE_SELECTOR_BORDER, 
                y, 
                box_x2 - box_x1 + (2 *  GUI_COLOR_SELECT_FTE_SELECTOR_BORDER) + 1,
                INLINE_FTE_CONTROL_HEIGHT,
                image);
           gdi_pop_and_restore_alpha_blending_source_layer();
        }
#endif         
            /* if is pure blue, draw cross */
            if (color_list[color_index].r == 0 && color_list[color_index].g == 0 && color_list[color_index].b == 255)
            {
                gui_fill_rectangle(box_x1, region_y1, box_x2, region_y2, gui_color(255, 255, 255));
                gui_line(box_x1, region_y1, box_x2, region_y2, gui_color(0, 0, 0));
                gui_line(box_x2, region_y1, box_x1, region_y2, gui_color(0, 0, 0));
            }
            else
            {
                gui_fill_rectangle(box_x1, region_y1, box_x2, region_y2, color_list[color_index]);
            }

        if (color_index == highlighted_index)
        {
#ifndef __MMI_FTE_SUPPORT__
            gui_draw_rectangle(box_x1, region_y1, box_x2, region_y2, gui_color(255, 0, 0));
            gui_draw_rectangle(box_x1 - 1, region_y1 - 1, box_x2 + 1, region_y2 + 1, gui_color(255, 0, 0));
#endif
        }
        else
        {
            gui_draw_rectangle(box_x1, region_y1, box_x2, region_y2, gui_color(0, 0, 0));
        }

        gui_draw_rectangle(box_x1 + 1, region_y1 + 1, box_x2 - 1, region_y2 - 1, gui_color(255, 255, 255));

    }

}


/*****************************************************************************
 * FUNCTION
 *  inline_color_select_menu_previous_item
 * DESCRIPTION
 *  selection change to previous color
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void inline_color_select_menu_previous_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_wgui_inline_color_select_item->highlighted_index == 0)
    {
        current_wgui_inline_color_select_item->highlighted_index = current_wgui_inline_color_select_item->n_color - 1;

        current_wgui_inline_color_select_item->start_index =
            current_wgui_inline_color_select_item->n_color - current_wgui_inline_color_select_box_count;
    }
    else
    {
        current_wgui_inline_color_select_item->highlighted_index--;
        if (current_wgui_inline_color_select_item->highlighted_index <
            current_wgui_inline_color_select_item->start_index)
        {
            current_wgui_inline_color_select_item->start_index--;
        }
    }

    show_highlighted_inline_color_select_menuitem();
    if (current_wgui_inline_color_select_item->color_highlighted != NULL)
    {
        current_wgui_inline_color_select_item->color_highlighted(current_wgui_inline_color_select_item->
                                                                 highlighted_index);
    }

}


/*****************************************************************************
 * FUNCTION
 *  inline_color_select_menu_next_item
 * DESCRIPTION
 *  selection change to next color
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void inline_color_select_menu_next_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_wgui_inline_color_select_item->highlighted_index >= current_wgui_inline_color_select_item->n_color - 1)
    {
        current_wgui_inline_color_select_item->highlighted_index = 0;
        current_wgui_inline_color_select_item->start_index = 0;

    }
    else
    {
        current_wgui_inline_color_select_item->highlighted_index++;

        if (current_wgui_inline_color_select_item->highlighted_index >=
            current_wgui_inline_color_select_item->start_index + current_wgui_inline_color_select_box_count)
        {
            current_wgui_inline_color_select_item->start_index++;
        }
    }

    show_highlighted_inline_color_select_menuitem();
    if (current_wgui_inline_color_select_item->color_highlighted != NULL)
    {
        current_wgui_inline_color_select_item->color_highlighted(current_wgui_inline_color_select_item->
                                                                 highlighted_index);
    }

}


/*****************************************************************************
 * FUNCTION
 *  register_inline_color_select_menu_keys
 * DESCRIPTION
 *  register key handler when highlighted on inline color selection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void register_inline_color_select_menu_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* key rule. 09.10.17  KEY_EVENT_REPEAT */
    SetKeyHandler(inline_color_select_menu_previous_item, KEY_LEFT_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(inline_color_select_menu_next_item, KEY_RIGHT_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(inline_color_select_menu_handle_up_arrow, KEY_UP_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(inline_color_select_menu_handle_down_arrow, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(inline_color_select_menu_handle_up_arrow, KEY_VOL_UP, KEY_EVENT_REPEAT);
    SetKeyHandler(inline_color_select_menu_handle_down_arrow, KEY_VOL_DOWN, KEY_EVENT_REPEAT);
    
    SetKeyHandler(inline_color_select_menu_previous_item, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(inline_color_select_menu_next_item, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(inline_color_select_menu_handle_up_arrow, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(inline_color_select_menu_handle_down_arrow, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(inline_color_select_menu_handle_up_arrow, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(inline_color_select_menu_handle_down_arrow, KEY_VOL_DOWN, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  clear_inline_select_menu_keys
 * DESCRIPTION
 *  clear inline select menu key handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clear_inline_select_menu_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* key rule. 09.10.17 */
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_REPEAT);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_REPEAT);
    
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_UP);
    
    clear_keyboard_key_handler();
    clear_inline_item_keys = UI_dummy_function;
    UI_text_menuitem_scroll_time = UI_TEXT_MENUITEM_SCROLL_TIME;
}


/*****************************************************************************
 * FUNCTION
 *  inline_color_select_pen_handler
 * DESCRIPTION
 *  Pen handler of color picker
 * PARAMETERS
 *  pen_event           [IN]      pen event 
 *  x                   [IN]      pen x position  
 *  y                   [IN]      pen y pisition  
 *  inline_event        [IN]       inine pen enum       
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
static BOOL inline_color_select_pen_handler(
                mmi_pen_event_type_enum pen_event,
                S16 x,
                S16 y,
                gui_inline_item_pen_enum *inline_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret;
    S32 i;
    S32 box_xoffset, box_width;
    S32 x1, y1, x2, y2, region_width, region_height;
    BOOL in_left_arrow, in_right_arrow;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *inline_event = GUI_INLINE_ITEM_PEN_NONE;
    ret = MMI_TRUE;

    x1 = current_wgui_inline_color_select_region_x1;
    y1 = current_wgui_inline_color_select_region_y1;
    x2 = current_wgui_inline_color_select_region_x2;
    y2 = current_wgui_inline_color_select_region_y2;
    region_width = x2 - x1 + 1;
    region_height = y2 - y1 + 1;

    in_left_arrow = MMI_FALSE;
    in_right_arrow = MMI_FALSE;

    if (x >= current_wgui_inline_color_select_icon1_x1
        && x <= current_wgui_inline_color_select_icon1_x2
        && y >= current_wgui_inline_color_select_region_y1 && y <= current_wgui_inline_color_select_region_y2)
    {
        in_left_arrow = MMI_TRUE;
    }
    else if (x >= current_wgui_inline_color_select_icon2_x1
             && x <= current_wgui_inline_color_select_icon2_x2
             && y >= current_wgui_inline_color_select_region_y1 && y <= current_wgui_inline_color_select_region_y2)
    {
        in_right_arrow = MMI_TRUE;
    }

    switch (pen_event)
    {
        case MMI_PEN_EVENT_DOWN:
            current_wgui_inline_color_select_icon1_pressed = 0;
            current_wgui_inline_color_select_icon2_pressed = 0;
            current_wgui_inline_color_select_pen_on_icon1 = 0;
            current_wgui_inline_color_select_pen_on_icon2 = 0;

            if (in_left_arrow)
            {
                current_wgui_inline_color_select_pen_on_icon1 = 1;
                current_wgui_inline_color_select_icon1_pressed = 1;
                show_highlighted_inline_color_select_menuitem();
            }
            else if (in_right_arrow)
            {
                current_wgui_inline_color_select_pen_on_icon2 = 1;
                current_wgui_inline_color_select_icon2_pressed = 1;
                show_highlighted_inline_color_select_menuitem();
            }
            else if (PEN_CHECK_BOUND(x, y, x1, y1, region_width, region_height))
            {
                box_width = current_wgui_inline_color_select_box_size + current_wgui_inline_color_select_box_spacing;
                box_xoffset = x1 + box_width - 1;
                for (i = 0; i < current_wgui_inline_color_select_box_count; i++)
                {
                    if (box_xoffset > x)
                    {
                        current_wgui_inline_color_select_item->highlighted_index =
                            i + current_wgui_inline_color_select_item->start_index;
                        show_highlighted_inline_color_select_menuitem();
                        if (current_wgui_inline_color_select_item->color_highlighted != NULL)
                        {
                            current_wgui_inline_color_select_item->
                                color_highlighted(current_wgui_inline_color_select_item->highlighted_index);
                        }

                        break;
                    }

                    box_xoffset += box_width;
                }
            }
            break;

        case MMI_PEN_EVENT_UP:
            if (current_wgui_inline_color_select_pen_on_icon1 && in_left_arrow)
            {
                inline_color_select_menu_previous_item();
            }
            else if (current_wgui_inline_color_select_pen_on_icon2 && in_right_arrow)
            {
                inline_color_select_menu_next_item();
            }

            if (current_wgui_inline_color_select_icon1_pressed || current_wgui_inline_color_select_icon2_pressed)
            {
                current_wgui_inline_color_select_icon1_pressed = 0;
                current_wgui_inline_color_select_icon2_pressed = 0;
                show_highlighted_inline_color_select_menuitem();
            }
            break;

        case MMI_PEN_EVENT_MOVE:
            if (current_wgui_inline_color_select_pen_on_icon1)
            {
                if (in_left_arrow)
                {
                    if (!current_wgui_inline_color_select_icon1_pressed)
                    {
                        current_wgui_inline_color_select_icon1_pressed = 1;
                        show_highlighted_inline_color_select_menuitem();
                    }
                }
                else
                {
                    if (current_wgui_inline_color_select_icon1_pressed)
                    {
                        current_wgui_inline_color_select_icon1_pressed = 0;
                        show_highlighted_inline_color_select_menuitem();
                    }
                }
            }
            else if (current_wgui_inline_color_select_pen_on_icon2)
            {
                if (in_right_arrow)
                {
                    if (!current_wgui_inline_color_select_icon2_pressed)
                    {
                        current_wgui_inline_color_select_icon2_pressed = 1;
                        show_highlighted_inline_color_select_menuitem();
                    }
                }
                else
                {
                    if (current_wgui_inline_color_select_icon2_pressed)
                    {
                        current_wgui_inline_color_select_icon2_pressed = 0;
                        show_highlighted_inline_color_select_menuitem();
                    }
                }
            }
            break;

        case MMI_PEN_EVENT_LONG_TAP:
            break;

        case MMI_PEN_EVENT_REPEAT:
            break;

        case MMI_PEN_EVENT_ABORT:
            if (current_wgui_inline_color_select_icon1_pressed || current_wgui_inline_color_select_icon2_pressed)
            {
                current_wgui_inline_color_select_icon1_pressed = 0;
                current_wgui_inline_color_select_icon2_pressed = 0;
                show_highlighted_inline_color_select_menuitem();
            }
            break;

        default:
            MMI_ASSERT(0);
    }

    return ret;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  handle_inline_color_select
 * DESCRIPTION
 *  inline color select hihight hanlder, will init required global variables for drawing.
 * PARAMETERS
 *  x                   [IN]        Menuitem start position x
 *  y                   [IN]        Menuitem start position y
 *  width               [IN]        Menuitem width
 *  height              [IN]        Menuitem height
 *  key_code            [IN]        Not used
 *  key_event           [IN]        Not used
 *  text_p              [IN]        Not used
 *  item                [IN]        Selected item pointer
 *  flags               [IN]        Not used
 *  history_buffer      [IN]        Not used
 * RETURNS
 *  void
 *****************************************************************************/
static void handle_inline_color_select(
                S32 x,
                S32 y,
                S32 width,
                S32 height,
                S32 key_code,
                S32 key_event,
                U8 **text_p,
                void *item,
                U32 flags,
                U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 spacing;
    S32 region_spacing;
    S32 icon_spacing;
    S32 icon_width = 0, icon_height = 0;
    S32 used_width;
    S32 region_width;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

 #ifndef __MMI_FTE_SUPPORT__   
    spacing = INLINE_COLOR_SELECT_HEIGHT_SPACING;
    icon_spacing = INLINE_COLOR_SELECT_ICON_SPACING;


    /* removed the hard-coded value of region_spacing. Now it is calculated according to
       the icon width of arrow image. */
    gui_measure_image((PU8) GetImage(IMG_H_SELECT_LEFT), &icon_width, &icon_height);
    region_spacing = icon_width + (2 * icon_spacing);

    current_wgui_inline_color_select_item = (wgui_inline_item_color_select*) item;

    current_wgui_inline_color_select_box_spacing = (U16) spacing;

    if (mmi_fe_get_r2l_state())
    {
        current_wgui_inline_color_select_region_x1 = (U16) (x + region_spacing);
        current_wgui_inline_color_select_region_x2 =
            (U16) (x + width - MMI_fixed_icontext_menuitem.text_x - region_spacing);
    }
    else
    {
        current_wgui_inline_color_select_region_x1 = (U16) (x + MMI_fixed_icontext_menuitem.text_x + region_spacing);
        current_wgui_inline_color_select_region_x2 = (U16) (x + width - region_spacing) - 1;    /* 112205 inline color Calvin */
    }

#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
    if (IsInlineItemDefaultTextEnable())
    {
        current_wgui_inline_color_select_region_x1 = (U16) (x + region_spacing);
        current_wgui_inline_color_select_region_x2 = (U16) (x + width - region_spacing);
    }
#endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 
    /* region_x1 and region_x2 are moved above. */
    /* current_wgui_inline_color_select_region_x1   = (U16)(x+MMI_fixed_icontext_menuitem.text_x+region_spacing); */
    current_wgui_inline_color_select_region_y1 = (U16) (y + spacing);
    /* current_wgui_inline_color_select_region_x2   = (U16)(x+width-region_spacing); */
    current_wgui_inline_color_select_region_y2 = (U16) (y + height - spacing);


    current_wgui_inline_color_select_icon1_x2 = current_wgui_inline_color_select_region_x1 - icon_spacing - 1;  /* 112205 inline color Calvin */
    current_wgui_inline_color_select_icon1_x1 = current_wgui_inline_color_select_icon1_x2 - icon_width + 1;
    current_wgui_inline_color_select_icon2_x1 = current_wgui_inline_color_select_region_x2 + icon_spacing + 1;  /* 112205 inline color Calvin */
    current_wgui_inline_color_select_icon2_x2 = current_wgui_inline_color_select_icon2_x1 + icon_width - 1;
    current_wgui_inline_color_select_icon_y = y + (height >> 1) - (icon_height >> 1);
    current_wgui_inline_color_select_icon1_pressed = 0;
    current_wgui_inline_color_select_icon2_pressed = 0;

    current_wgui_inline_color_select_box_size =
        current_wgui_inline_color_select_region_y2 - current_wgui_inline_color_select_region_y1;
    current_wgui_inline_color_select_box_count = (U16) ((current_wgui_inline_color_select_region_x2 - current_wgui_inline_color_select_region_x1 + 1 + spacing) / (current_wgui_inline_color_select_box_size + spacing));       /* 112205 inline color Calvin */

    current_wgui_inline_color_select_item->color_highlighted(current_wgui_inline_color_select_item->highlighted_index);

    /* dispatch remain spacing to both side */
    used_width =
        current_wgui_inline_color_select_box_size * current_wgui_inline_color_select_box_count +
        (current_wgui_inline_color_select_box_count - 1) * spacing;
    region_width = current_wgui_inline_color_select_region_x2 - current_wgui_inline_color_select_region_x1 + 1;

    current_wgui_inline_color_select_region_x1 += (U16) ((region_width - used_width) >> 1);

    current_wgui_inline_color_select_region_x2 -= (U16) ((region_width - used_width) >> 1);

    /* if total color is less then box count, adjust position */
    if (current_wgui_inline_color_select_box_count > current_wgui_inline_color_select_item->n_color)
    {
        current_wgui_inline_color_select_box_count = current_wgui_inline_color_select_item->n_color;

        /* adjust to center */
        used_width =
            current_wgui_inline_color_select_box_size * current_wgui_inline_color_select_box_count +
            (current_wgui_inline_color_select_box_count - 1) * spacing;
        region_width = current_wgui_inline_color_select_region_x2 - current_wgui_inline_color_select_region_x1 + 1;

        current_wgui_inline_color_select_region_x1 += (U16) ((region_width - used_width) >> 1);

    #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
        if (IsInlineItemDefaultTextEnable())
        {
            current_wgui_inline_color_select_region_x2 -= (U16) ((region_width - used_width) >> 1);
        }
    #endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 

    }

    show_highlighted_inline_color_select_menuitem();
#else
    inline_color_select_control_x_coordinate = x;
    inline_color_select_control_y_coordinate = y;
    inline_color_select_control_height = height;
    inline_color_select_control_width = width;
    spacing = GUI_COLOR_SELECT_FTE_BOX_VERTICAL_GAP; //INLINE_COLOR_SELECT_HEIGHT_SPACING;
    icon_spacing = GUI_COLOR_SELECT_FTE_BOX_BETWEEN_GAP;// INLINE_COLOR_SELECT_ICON_SPACING; 
    
    gui_measure_image((PU8)(current_MMI_theme->inline_item_select_left_arrow_push_image), &icon_width, &icon_height);
    region_spacing = icon_width + icon_spacing;

    current_wgui_inline_color_select_item = (wgui_inline_item_color_select*) item;

    current_wgui_inline_color_select_box_spacing = (U16) spacing;  //vertical gap

   
    current_wgui_inline_color_select_region_x1 = x + region_spacing;
    current_wgui_inline_color_select_region_x2 = (U16) (x + width  - region_spacing - 1);    /* 112205 inline color Calvin */

    
    current_wgui_inline_color_select_region_y1 = (U16) (y + GUI_COLOR_SELECT_FTE_CONTROL_BORDER_WIDTH + GUI_COLOR_SELECT_FTE_BOX_VERTICAL_GAP );
    current_wgui_inline_color_select_region_y2 = (U16) (y + height - GUI_COLOR_SELECT_FTE_CONTROL_BORDER_WIDTH - GUI_COLOR_SELECT_FTE_BOX_VERTICAL_GAP - 1);


    current_wgui_inline_color_select_icon1_x1 = x + GUI_COLOR_SELECT_FTE_CONTROL_BORDER_WIDTH;
    current_wgui_inline_color_select_icon1_x2 = current_wgui_inline_color_select_icon1_x1 + icon_width -1;  

    current_wgui_inline_color_select_icon2_x1 = x + width  - icon_width - GUI_COLOR_SELECT_FTE_CONTROL_BORDER_WIDTH;  
    current_wgui_inline_color_select_icon2_x2 = current_wgui_inline_color_select_icon2_x1 + icon_width - 1;
    current_wgui_inline_color_select_icon_y = y ;
    
    current_wgui_inline_color_select_icon1_pressed = 0;
    current_wgui_inline_color_select_icon2_pressed = 0;

    current_wgui_inline_color_select_box_size =
        current_wgui_inline_color_select_region_y2 - current_wgui_inline_color_select_region_y1;
    current_wgui_inline_color_select_box_count = (U16) ((current_wgui_inline_color_select_region_x2 - current_wgui_inline_color_select_region_x1 + 1 + spacing) / (current_wgui_inline_color_select_box_size + spacing));       /* 112205 inline color Calvin */

    current_wgui_inline_color_select_item->color_highlighted(current_wgui_inline_color_select_item->highlighted_index);

    /* dispatch remain spacing to both side */
    used_width =
        current_wgui_inline_color_select_box_size * current_wgui_inline_color_select_box_count +
        (current_wgui_inline_color_select_box_count - 1) * spacing;
    region_width = current_wgui_inline_color_select_region_x2 - current_wgui_inline_color_select_region_x1 + 1;

    current_wgui_inline_color_select_region_x1 += (U16) ((region_width - used_width) >> 1);
    
    current_wgui_inline_color_select_region_x2 -= (U16) ((region_width - used_width) >> 1);

    /* if total color is less then box count, adjust position */
    if (current_wgui_inline_color_select_box_count > current_wgui_inline_color_select_item->n_color)
    {
        current_wgui_inline_color_select_box_count = current_wgui_inline_color_select_item->n_color;

        /* adjust to center */
        used_width =
            current_wgui_inline_color_select_box_size * current_wgui_inline_color_select_box_count +
            (current_wgui_inline_color_select_box_count - 1) * spacing;
        region_width = current_wgui_inline_color_select_region_x2 - current_wgui_inline_color_select_region_x1 + 1;

        current_wgui_inline_color_select_region_x1 += (U16) ((region_width - used_width) >> 1);

    #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
        if (IsInlineItemDefaultTextEnable())
        {
            current_wgui_inline_color_select_region_x2 -= (U16) ((region_width - used_width) >> 1);
        }
    #endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 

    }

    show_highlighted_inline_color_select_menuitem();
#endif    
    
    register_inline_color_select_menu_keys();

    clear_inline_item_keys = clear_inline_select_menu_keys;
    complete_inline_item_edit = inline_color_select_menu_change_complete;
    redraw_current_inline_item = show_highlighted_inline_color_select_menuitem;
#ifdef __MMI_TOUCH_SCREEN__
    wgui_current_inline_item_pen_function = inline_color_select_pen_handler;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  SetInlineItemColorSelect
 * DESCRIPTION
 *  Set color inline selection
 * PARAMETERS
 *  item                    [IN]        Inline item pointer
 *  n_color                 [IN]        Number of color
 *  hilighted_index         [IN]        Highlighed color index
 *  list_of_color           [IN]        Array of colors
 *  color_highlighted       [IN]        Color highlighted callback function
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineItemColorSelect(
        InlineItem *item,
        S32 n_color,
        U16 hilighted_index,
        color *list_of_color,
        void (*color_highlighted) (U16 index))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_color_select *i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if still have room for another item */
    MMI_ASSERT(n_inline_color_select_items < MAX_INLINE_COLOR_SELECT_ITEMS);
    MMI_ASSERT(hilighted_index < n_color);

    wgui_inline_mem_alloc_info[wgui_inline_mem_alloc_number] = item->item = wgui_inline_malloc(sizeof(wgui_inline_item_color_select));
    wgui_inline_mem_alloc_number++; 
    item->flags = INLINE_ITEM_TYPE_COLOR_SELECT;

    i = (wgui_inline_item_color_select*) item->item;

    i->flags = 0;
    i->list_of_color = list_of_color;
    i->highlighted_index = hilighted_index;
    i->n_color = (U16) n_color;
    i->color_highlighted = color_highlighted;

    item->handler = handle_inline_color_select;

    /* notify start index need re-adjust */
    i->start_index = 255;

    n_inline_color_select_items++;
}

#endif

#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
#if defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__)
/***************************************************************************** 
 * Inline Multiline Edit & Inline Multiline Edit Read Only  
 *
 * This is Multiline Edit Item
 *****************************************************************************/

/***************************************************************************** 
 * Local Variable
 *****************************************************************************/
static U8 inscreen_multi_line_change_flag = 0;
static U8 wgui_inline_inputbox_information_flag;
static S8 MMI_inline_multi_line_inputbox_present;
/***************************************************************************** 
 * Extern Global Function
 *****************************************************************************/
extern void wgui_redraw_input_information_background(void);


/***************************************************************************** 
 * Function Implementation
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_edit_handle_multiline_inputbox_input
 * DESCRIPTION
 *  input handler for inline multiline inputbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inline_edit_handle_multiline_inputbox_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_handle_inputbox_input();
    inline_full_screen_edit_changed = 1;
#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
#if defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__)
    if (wgui_current_inline_item_type == INLINE_ITEM_TYPE_MULTI_LINE_EDIT)
    {
        if (wgui_inline_list_menu_changed)
        {

            if (gui_multi_line_input_box_get_text_length(&MMI_multiline_inputbox) <= 0)
            {
                wgui_inline_text_edit_set_RSK_BACK_function();
                inline_text_edit_RSK_label_clear = 0;
                
                if(cui_inline_is_current_cui())
                {
                   cui_inline_evt_item_text_empty(); 
                }
                else
                {
                    if (wgui_inputbox_empty_callback != NULL)
                    {
                        wgui_inputbox_empty_callback();
                    }
                }    
            }
        }
    }
#endif /* #if defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__) */
#endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  inline_multi_line_edit_get_history
 * DESCRIPTION
 *  get history buffer for inline multi line edit
 * PARAMETERS
 *  history_buffer      [OUT]       history buffer  
 *  input_mode          [IN]        input mode
 * RETURNS
 *  history buffer
 *****************************************************************************/
U8 *inline_multi_line_edit_get_history(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_multiline_inputbox_category_history(INLINE_MULTI_LINE_EDIT_HISTORY_ID, history_buffer);
    return (history_buffer);
}



/*****************************************************************************
 * FUNCTION
 *  SetInlineItemMultiLineHeight
 * DESCRIPTION
 *  Set inline multiline height
 * PARAMETERS
 *  item        [IN]
 *  n_item      [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineItemMultiLineHeight(InlineItem *item, S32 n_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_text_edit *i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = (wgui_inline_item_text_edit*) item->item;
    ASSERT(i != NULL);
    if((item->flags && INLINE_ITEM_TYPE_MULTI_LINE_EDIT) ||
       (item->flags && INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY)
      )
    {
        i->height_of_item = (U8)n_item;
        i->max_lines= (U8)n_item; 
    }   
}

/*****************************************************************************
 * FUNCTION
 *  SetInlineItemMultiLineEdit
 * DESCRIPTION
 *  set data of inline multi line edit
 * PARAMETERS
 *  item            [IN]    inline item         
 *  buffer          [IN]    buffer      
 *  title           [IN]    title string     
 *  buffer_size     [IN]    size of buffer    
 *  input_type      [IN]    input type    
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineItemMultiLineEdit(InlineItem *item, U8 *buffer, U8 *title, S32 buffer_size, U32 input_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_text_edit *i;
    UI_buffer_type mask_buffer;
    U32 t = input_type & INPUT_TYPE_MASK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (n_inline_text_edit_items >= MAX_INLINE_TEXT_EDIT_ITEMS)
    {
        return;
    }
    wgui_inline_mem_alloc_info[wgui_inline_mem_alloc_number] = item->item = wgui_inline_malloc(sizeof(wgui_inline_item_text_edit));
    wgui_inline_mem_alloc_number++; 
    item->flags = INLINE_ITEM_TYPE_MULTI_LINE_EDIT;
    n_inline_text_edit_items++;
    i = (wgui_inline_item_text_edit*) item->item;
    i->mask_buffer = NULL;
    i->max_lines = 0;
    i->title = 0;
    i->title_icon = 0;
    i->buffer = buffer;
    i->buffer_size = buffer_size;
    i->flags = 0;
    i->input_type = input_type;
    item->text_p = i->buffer;
    i->height_of_item = 3;

    item->handler = handle_inline_multi_line_edit;
    i->edit_complete_callback = UI_dummy_edit_complete_handler;
    i->custom_setup_function = NULL;
    i->validation_callback = UI_dummy_validation_function;

    if ((t == IMM_INPUT_TYPE_NUMERIC_PASSWORD) || (t == IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD) ||
        (t == IMM_INPUT_TYPE_SAT_NUMERIC_PASSWORD) || (t ==IMM_INPUT_TYPE_ASCII_PASSWORD))
    {
        wgui_inline_mem_alloc_info[wgui_inline_mem_alloc_number] =  mask_buffer = (U8*)wgui_inline_malloc(MAX_INLINE_TEXT_EDIT_BUFFER_SIZE * sizeof(U8));          
        wgui_inline_mem_alloc_number++; 
        inline_edit_prepare_mask_buffer(buffer, mask_buffer);
        i->mask_buffer = mask_buffer;
        item->text_p = mask_buffer;
    }
    i->UCS2_count = -1;
    MMI_multi_line_inputbox_present = 1;

    MMI_multiline_inputbox.flags = 0;
}


/*****************************************************************************
 * FUNCTION
 *  handle_inline_multi_line_edit
 * DESCRIPTION
 *  activation function of inline multi line edit
 * PARAMETERS
 *  x                   [IN]        left corner's x coordinate
 *  y                   [IN]        left corner's y coordinate
 *  width               [IN]        width
 *  height              [IN]        height
 *  key_code            [IN]        key code
 *  key_event           [IN]        key event
 *  text_p              [IN]        text pointer
 *  item                [IN]        inline item
 *  flags               [IN]        flags
 *  history_buffer      [IN]        history buffer          
 * RETURNS
 *  void
 *****************************************************************************/
void handle_inline_multi_line_edit(
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        S32 key_code,
        S32 key_event,
        U8 **text_p,
        void *item,
        U32 flags,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 input_type;
    wgui_inline_item_text_edit *i = (wgui_inline_item_text_edit*) item;
    S32 inputbox_x = x;
    S32 inputbox_y = y;
    S32 inputbox_width = width + 2;
#ifndef __MMI_FTE_SUPPORT__    
       S32 inputbox_height  = i->height_of_item * MMI_MENUITEM_HEIGHT;
#else
    S32 inputbox_height = height;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_multi_line_inputbox_present = 1;
    wgui_current_inline_item_type = INLINE_ITEM_TYPE_MULTI_LINE_EDIT;   /* Should Be Present. */

    UI_UNUSED_PARAMETER(key_code);
    UI_UNUSED_PARAMETER(key_event);
    UI_UNUSED_PARAMETER(flags);

    gdi_layer_lock_frame_buffer();
    wgui_text_menuitem_reset_scrolling();
    wgui_current_inline_item_type = INLINE_ITEM_TYPE_MULTI_LINE_EDIT;
    current_wgui_inline_text_edit_item = i;
    current_wgui_inline_text_edit_text_p = text_p;
    input_type = i->input_type;
    if (!(flags & INLINE_ITEM_OPEN))
    {
        history_buffer = NULL;
    }
    if(cui_inline_is_current_cui())
    {
        cui_inline_item_replace_gui_buffer(wgui_inline_item_highlighted_index, &wgui_inline_items[wgui_inline_item_highlighted_index], &history_buffer);
    }
    i->flags &= ~INLINE_ITEM_OPEN;

    wgui_inputbox_validation_callback = i->validation_callback;
    wgui_multiline_setup_inputbox(
        inputbox_x,
        inputbox_y,
        inputbox_width,
        inputbox_height,
        i->buffer,
        i->buffer_size,
        INLINE_MULTI_LINE_EDIT_HISTORY_ID,
        inline_text_edit_RSK_label_string,
        NULL,
        (S16) input_type,
        history_buffer,
#ifdef __MMI_FTE_SUPPORT__
        0
#else
        1
#endif
        );

    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_USE_PRESET_CLIPPING;
/*
#if !defined(GUI_EDITOR_SHOW_TITLE)
    {
        S32 dm_flag;
        
        dm_get_dm_data_flag(&dm_flag);
        dm_flag |= DM_NO_TITLE;
        
        dm_set_dm_data_flag(dm_flag);
        
        full_screen_edit_open = 1;
        wgui_status_icon_bar_register_integrated_redraw(NULL);
    }
#endif 
*/

#if defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
    set_left_softkey_label((UI_string_type) get_string(STR_GLOBAL_OPTIONS));
    SetLeftSoftkeyFunction(EntryInLineMultilineEditorOption, KEY_EVENT_UP);
    if(cui_inline_is_current_cui())
    {
        set_softkey_function(EntryInLineMultilineEditorOption, KEY_EVENT_UP, MMI_CENTER_SOFTKEY);
    }
#endif /* defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    redraw_right_softkey();
    redraw_left_softkey();
    register_left_softkey_handler();
    register_right_softkey_handler();
    register_multiline_inputbox_input_callback(wgui_inline_edit_handle_multiline_inputbox_input);
    wgui_inputbox_RSK_function = wgui_inline_edit_BACK_function;
    redraw_current_inline_item = wgui_show_inputbox;    
    if(cui_inline_is_current_cui())
    {
       cui_inline_evt_item_activate(); 
    }
    else
    {
        if (i->custom_setup_function != NULL)
        {
            i->custom_setup_function();
        }
    }

    wgui_show_inputbox();
    complete_inline_item_edit = handle_inline_multi_line_edit_complete;

    /*
     * For IME auto-capitalization, to update input mode by cursor 
     * position, because inline create editor after connecting IME
     */
    mmi_imc_update_input_mode_by_cursor_pos();
    
    mmi_imc_redraw_screen_by_state();
    gdi_layer_unlock_frame_buffer();
    gdi_lcd_repaint_all();
}


/*****************************************************************************
 * FUNCTION
 *  handle_inline_multi_line_edit_complete
 * DESCRIPTION
 *  complete function of inline multi line edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void handle_inline_multi_line_edit_complete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 input_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle_inline_full_screen_edit_close();
    input_type = current_wgui_inline_text_edit_item->input_type & INPUT_TYPE_MASK;
    current_wgui_inline_item->flags &= ~INLINE_ITEM_OPEN;
    if (inline_full_screen_edit_changed)
    {
        wgui_inline_list_menu_changed = 1;
    }
    current_wgui_inline_text_edit_item->UCS2_count = MMI_multiline_inputbox.UCS2_count;
    if ((input_type == IMM_INPUT_TYPE_NUMERIC_PASSWORD) || (input_type == IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD) ||
        (input_type == IMM_INPUT_TYPE_SAT_NUMERIC_PASSWORD) || (input_type ==IMM_INPUT_TYPE_ASCII_PASSWORD))
    {
        inline_edit_prepare_mask_buffer(
            current_wgui_inline_text_edit_item->buffer,
            current_wgui_inline_text_edit_item->mask_buffer);
        *current_wgui_inline_text_edit_text_p = current_wgui_inline_text_edit_item->mask_buffer;
    }
    else
    {
        *current_wgui_inline_text_edit_text_p = current_wgui_inline_text_edit_item->buffer;
    }

    reset_softkeys();
    /* W06.05 Temp Solution Do not draw fixed list in category57 because of virtual keyboard */
#if !defined(__MMI_TOUCH_SCREEN__)
    wgui_close_inputbox();
#endif 
    mmi_imc_disconnect();
    clear_left_softkey();
    clear_right_softkey();

    register_left_softkey_handler();
    register_right_softkey_handler();

    wgui_inline_item_handled = 0;

    current_wgui_inline_text_edit_item->edit_complete_callback(
                                            current_wgui_inline_text_edit_item->buffer,
                                            current_wgui_inline_text_edit_item->buffer_size);

    redraw_current_inline_item = UI_dummy_function;
    wgui_inputbox_UCS2_count_function = NULL;
    wgui_inputbox_not_empty_callback = NULL;
    wgui_inputbox_empty_callback = NULL;
    wgui_inputbox_validation_callback = NULL;
    inline_full_screen_edit_changed = 0;
    complete_inline_item_edit = UI_dummy_function;
    StopTimer(BLINKING_CURSOR);
    g_is_inline_multiline_highlighted = MMI_FALSE;

#ifdef __MMI_FTE_SUPPORT__	
	mmi_imc_set_vk_present(MMI_IMC_VK_DEFAULT_ENLARGE);
#endif	
}

#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
extern gui_list_smooth_scrolling_by_pen_state_enum g_gui_ssp_state;
#endif /* GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN */



/*****************************************************************************
 * FUNCTION
 *  mmi_input_box_msg_call_back_inline_multiline
 * DESCRIPTION
 *  message callback function of inline multiline for IME
 * PARAMETERS
 *  editor_ptr          [IN]      multiline input pointer  
 *  msg_ptr             [IN]      message pointer       
 * RETURNS
 *  U32
 *****************************************************************************/
static U32 mmi_input_box_msg_call_back_inline_multiline(void * input_box_handle, mmi_imc_message_struct_p msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    multi_line_input_box * editor_ptr;
    U32 lresult = 0;
    
#if defined(__MMI_TOUCH_SCREEN__) 
    gui_multi_line_input_box_pen_enum multi_line_input_box_event = {0};
#endif
    
    static S32 down_x = -1, down_y = -1;
    static S32 reset_pre_hdlr = 0;
    static S32 maybe_list_ssp = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    editor_ptr = (multi_line_input_box *)((mmi_editor_handler_struct *)input_box_handle)->input_box_handler;
    
    MMI_ASSERT(editor_ptr == &MMI_multiline_inputbox);

    switch (msg_ptr->message_id)
    {
    case MMI_IMC_MESSAGE_REDRAW:

        //memcpy(editor_ptr, &g_inline_multiline_backup_struct, sizeof(multi_line_input_box));
        
        editor_ptr->flags = g_is_inline_multiline_flags;

        if (g_is_inline_multiline_highlighted)
        {
            editor_ptr->flags |= UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        }
        else
        {
            editor_ptr->flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        }
        editor_ptr->cursor_p = editor_ptr->text + g_inline_multiline_current_position;
        editor_ptr->text_offset_x = g_inline_multiline_text_offset_x;
        editor_ptr->available_length = g_inline_multiline_available_length;
        editor_ptr->highlight_start_position = g_is_inline_multiline_highlight_start_position;
        editor_ptr->highlight_end_position = g_is_inline_multiline_highlight_end_position;
        editor_ptr->input_mode_cursor_p = g_inline_multiline_input_mode_cursor_p;
        editor_ptr->input_start_cursor_p = g_inline_multiline_input_start_cursor_p;

        editor_ptr->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        gui_show_multi_line_input_box(editor_ptr);          /* show multi line input box */
        editor_ptr->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        show_multiline_inputbox();
        
        break;
        
    case MMI_IMC_MESSAGE_HILIGHT_BFCURSOR:
        g_is_inline_multiline_highlighted = MMI_TRUE;
        editor_ptr->flags |= UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        gui_multi_line_input_box_highlight_cursor_number(editor_ptr, (S32)msg_ptr->param_0);
        wgui_inputs_ml_redraw();
        break;
        
    case MMI_IMC_MESSAGE_CLEAR_HILIGHT:
        editor_ptr->flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        g_is_inline_multiline_highlighted = MMI_FALSE;
        
        break;

    case MMI_IMC_MESSAGE_SET_KEY:
        wgui_inputs_ml_set_RSK();
	if (gui_multi_line_input_box_get_text_length(&MMI_multiline_inputbox) <= 0)
        {
            wgui_inline_text_edit_set_RSK_BACK_function();
	}
        wgui_inputs_ml_register_keys();
        break;

    case MMI_IMC_MESSAGE_REPLACE_HIGHLIGHT_STRING:

        lresult = mmi_input_box_msg_call_back_multiline(input_box_handle, msg_ptr);
        
        if (lresult > 0)
        {
            g_is_inline_multiline_highlighted = MMI_TRUE; 
        }
        break;


    case MMI_IMC_MESSAGE_HAS_SSP_ACTED:
    {
        if(gui_screen_smooth_scrolling_moved_by_pen())
        {
            lresult = MMI_TRUE;
        }
        else
        {
            lresult = mmi_input_box_msg_call_back_multiline(input_box_handle, msg_ptr);
        }
        break;
    }
    
    case MMI_IMC_MESSAGE_CLIPBOARD_SAVE_STATUS:
    {
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_FTE_SUPPORT__)
        if(reset_pre_hdlr == 0)
        {
            wgui_pen_reset_pre_hdlr();
            reset_pre_hdlr = 1;
        }       
#endif
        g_is_inline_multiline_highlighted = MMI_TRUE; 
        lresult = mmi_input_box_msg_call_back_multiline(input_box_handle, msg_ptr);
        break;
    }
    case MMI_IMC_MESSAGE_CLIPBOARD_RESTORE_STATUS:
    {
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_FTE_SUPPORT__)
        if(reset_pre_hdlr == 1)
        {
            wgui_pen_restore_pre_hdlr();
            reset_pre_hdlr = 0;
        }       
        
#endif
        g_is_inline_multiline_highlighted = MMI_FALSE; 
        lresult = mmi_input_box_msg_call_back_multiline(input_box_handle, msg_ptr);
        break;
    }
        
    
    case MMI_IMC_MESSAGE_PEN_EVENT:

#ifdef __MMI_EDITOR_SSP_SUPPORT__

        lresult  = gui_multi_line_input_box_translate_pen_event(
                        &MMI_multiline_inputbox,
                        ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event,
                        ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.x,
                        ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.y,
                        &multi_line_input_box_event);
        
        if (lresult)
        {
            S32 x = ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.x;
            S32 y = ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.y;

           // ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->editor_pen_event = single_line_input_box_event;
            
            switch (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event)
            {
                case  MMI_PEN_EVENT_DOWN:
                {
                    down_x = x;
                    down_y = y;
                    maybe_list_ssp = 0;

                    if ((gui_input_box_ssp_get_state() != GUI_INPUT_BOX_SSP_STATE_UNFOCUS) &&
                        (reset_pre_hdlr == 0)
                       )
                    {
                        wgui_pen_reset_pre_hdlr();
                        reset_pre_hdlr = 1;
                    }
                    if((MMI_multiline_inputbox.text_offset_y == 0))
                    {
                        maybe_list_ssp = 1;
                    }
                    break;
                }
                case MMI_PEN_EVENT_MOVE:
                {
                    if((maybe_list_ssp) && (reset_pre_hdlr == 1) && (editor_ptr->state != GUI_INPUT_BOX_STATE_SELECTING_TEXT))
                    {
                        if(y > down_y)
                        {
                            wgui_pen_restore_pre_hdlr();
#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
                            g_gui_ssp_state = GUI_LIST_SMOOTH_SCROLLING_BY_PEN_STATE_FOCUS;
#endif /* GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN */
                            reset_pre_hdlr = 0;
                        }
                        else
                        {
                            maybe_list_ssp = 0;
                        }
                    }
                    break;
                }
                case MMI_PEN_EVENT_UP:
                case MMI_PEN_EVENT_ABORT:
                {   
                    if (reset_pre_hdlr)
                    {
                        wgui_pen_restore_pre_hdlr();
                            reset_pre_hdlr = 0;
                    }
                    break;
                }
                
            }
            return mmi_input_box_msg_call_back_multiline(input_box_handle, msg_ptr);
        }
        
        break;
        
#endif /* __MMI_EDITOR_SSP_SUPPORT__ */
        
    default:
        return mmi_input_box_msg_call_back_multiline(input_box_handle, msg_ptr);
    }

    return lresult;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_show_inline_inscreen_multi_line_edit
 * DESCRIPTION
 *  show inline inscreen multi line edit
 * PARAMETERS
 *  x1                  [IN]    left-top corner x1 coordinate    
 *  y1                  [IN]    left-top corner y1 coordinate    
 *  width               [IN]    width    
 *  height              [IN]    height          
 *  item                [IN]    inline item          
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_show_inline_inscreen_multi_line_edit(S32 x1, S32 y1, S32 width, S32 height, wgui_inline_item *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_text_edit *i = (wgui_inline_item_text_edit*) item->item;
    S32 inputbox_x = x1;
    S32 inputbox_y = y1;
    S32 inputbox_width = width;
    multi_line_input_box *MMI_inline_multiline_inputbox;

#ifndef __MMI_FTE_SUPPORT__
    S32 inputbox_height  = i->height_of_item * MMI_MENUITEM_HEIGHT;
#else
    S32 inputbox_height = height;
#endif
    S32 fh;
    S32 l;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    
    wgui_inline_inputbox_information_flag = wgui_inputbox_information_flag;
    MMI_inline_multi_line_inputbox_present = MMI_multi_line_inputbox_present;
    if (wgui_current_inline_item_type == INLINE_ITEM_TYPE_FULL_SCREEN_EDIT)
    {
        return;
    }

    MMI_inline_multiline_inputbox = (multi_line_input_box *)mmi_frm_asm_alloc_anonymous(sizeof(multi_line_input_box));

    l = gui_strlen((UI_string_type) i->buffer);

    gui_create_multi_line_input_box_set_buffer(
         MMI_inline_multiline_inputbox,
         MMI_multiline_inputbox_x,
         MMI_multiline_inputbox_y,
         MMI_multiline_inputbox_width,
         MMI_multiline_inputbox_height,
         (UI_string_type) i->buffer,
         l * 2,
         (l + 1) * 2,
         0);

    MMI_inline_multiline_inputbox->flags |= UI_MULTI_LINE_INPUT_BOX_USE_PRESET_CLIPPING;
    
    MMI_inline_multiline_inputbox->ext_flags |= GUI_MULTI_LINE_INPUT_BOX_SEMITRANSPARENT_BACKGROUND;
    
    gui_set_font((MMI_inline_multiline_inputbox->text_font));
    fh = gui_get_character_height();
    inputbox_height = (inputbox_height / (fh + 1)) * (fh + 1);

#if(INSCREEN_MUTLILINE_TITLE_ENABLE)
    gui_move_multi_line_input_box(MMI_inline_multiline_inputbox, inputbox_x, inputbox_y);
    gui_resize_multi_line_input_box(MMI_inline_multiline_inputbox, inputbox_width, inputbox_height + 4 + 2);
    wgui_inputbox_information_flag = 0;
#else /* (INSCREEN_MUTLILINE_TITLE_ENABLE) */ 
    {
        S32 t_height = 0;
        gui_move_multi_line_input_box(MMI_inline_multiline_inputbox, inputbox_x, inputbox_y);
        
        t_height = (fh + 1) - (INFORMATION_BAR_HEIGHT + 2);
        gui_resize_multi_line_input_box(MMI_inline_multiline_inputbox, inputbox_width, inputbox_height + 4 - t_height);

        
    }
#endif /* (INSCREEN_MUTLILINE_TITLE_ENABLE) */ 

    MMI_inline_multiline_inputbox->flags |=
        (UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | UI_MULTI_LINE_INPUT_BOX_VIEW_MODE |
         UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR);

    MMI_multi_line_inputbox_present = 3;

    gui_show_multi_line_input_box(MMI_inline_multiline_inputbox);
#if(UI_DOUBLE_BUFFER_SUPPORT)
        gui_BLT_double_buffer(
            MMI_inline_multiline_inputbox->x,
            MMI_inline_multiline_inputbox->y,
            MMI_inline_multiline_inputbox->x + MMI_inline_multiline_inputbox->width,
            MMI_inline_multiline_inputbox->y + MMI_inline_multiline_inputbox->height);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 

     wgui_inputbox_information_flag = wgui_inline_inputbox_information_flag;
     MMI_multi_line_inputbox_present = MMI_inline_multi_line_inputbox_present;

     mmi_frm_asm_free_anonymous(MMI_inline_multiline_inputbox);

}


/*****************************************************************************
 * FUNCTION
 *  inline_multiline_edit_complete
 * DESCRIPTION
 *  complete function of inline multiline edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void inline_multiline_edit_complete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_multi_line_inputbox_present)
    {
        handle_inline_multi_line_edit_complete();
    }
    MMI_multi_line_inputbox_present = 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_draw_inscreen_multi_line_input_box_title
 * DESCRIPTION
 *  draw inline multi line input box title
 * PARAMETERS
 *  x1                  [IN]    left-top corner x1 coordinate    
 *  y1                  [IN]    left-top corner y1 coordinate          
 *  x2                  [IN]    right-bottom corner x2 coordinate    
 *  y2                  [IN]    right-bottom corner y2 coordinate           
 * RETURNS
 *  void
 *****************************************************************************/
void gui_draw_inscreen_multi_line_input_box_title(S32 x1, S32 y1, S32 x2, S32 y2)
{
#if(INSCREEN_MULTILINE_SHOW_TITLE)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_inputbox_information_flag)
    {
        wgui_redraw_input_information_background();
    }
#else /* (INSCREEN_MULTILINE_SHOW_TITLE) */ 
    if (wgui_inputbox_information_flag)
    {
        wgui_redraw_input_information_bar();
    }
#endif /* (INSCREEN_MULTILINE_SHOW_TITLE) */ 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_show_inline_multi_line_rd_only
 * DESCRIPTION
 *  show inline multi line read only
 * PARAMETERS
 *  x1                  [IN]    left-top corner x1 coordinate    
 *  y1                  [IN]    left-top corner y1 coordinate    
 *  width               [IN]    width    
 *  height              [IN]    height          
 *  item                [IN]    inline item          
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_show_inline_multi_line_rd_only(S32 x1, S32 y1, S32 width, S32 height, wgui_inline_item *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_text_edit *i = (wgui_inline_item_text_edit*) item->item;
    S32 l;

    S32 inputbox_x = x1;
    S32 inputbox_y = y1;
    S32 inputbox_width = width;
    S32 inputbox_height = 0;
    S32 screen_item_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_current_inline_item_type == INLINE_ITEM_TYPE_FULL_SCREEN_EDIT)
    {
        return;
    }
    l = gui_strlen((UI_string_type) i->buffer);
    create_multiline_inputbox_set_buffer((UI_string_type) i->buffer, l, l, 0);
    move_multiline_inputbox(inputbox_x, inputbox_y);
    MMI_multiline_inputbox.flags |=
        (UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | UI_MULTI_LINE_INPUT_BOX_VIEW_MODE |
         UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR | UI_MULTI_LINE_INPUT_BOX_USE_PRESET_CLIPPING);

#ifndef __MMI_FTE_SUPPORT__
    /*we limit the height of multilinerdonly so that it can be shown total in screen.*/
   // screen_item_count = MMI_fixed_list_menu.height / MMI_fixed_icontext_menuitem.height;
    //i->height_of_item = (screen_item_count - 1 >  i->height_of_item) ? i->height_of_item : screen_item_count - 1;
    inputbox_height = height * (i->height_of_item);
#else
    inputbox_height = height; 
#endif
    MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_SEMITRANSPARENT_BACKGROUND;
    MMI_multiline_inputbox.trans_color = *(current_MMI_theme->inline_multiline_readonly_bg_color);
    MMI_multiline_inputbox.trans_alpha = current_MMI_theme->inline_multiline_readonly_bg_alpha;
    
    resize_multiline_inputbox(inputbox_width, inputbox_height);

    if(g_inline_ml_rdly_highlight_list.hilite_list)
    {
        gui_inputs_ml_set_hilite_list(
            &MMI_multiline_inputbox,
            g_inline_ml_rdly_highlight_list.hilite_list,
            g_inline_ml_rdly_highlight_list.count,
            0,
            NULL,
            NULL
            ); 
    }
    
    show_multiline_inputbox();
}


/*****************************************************************************
 * FUNCTION
 *  SetInlineMultiLineRdOnly
 * DESCRIPTION
 *  set data of inline multiline read only
 * PARAMETERS
 *  item            [IN]    inline item     
 *  buffer          [IN]    buffer      
 *  buffer_size     [IN]    size of buffer    
 *  input_type      [IN]    input type    
 *  max_lines       [IN]    max lines    
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineMultiLineRdOnly(InlineItem *item, U8 *buffer, S32 buffer_size, U32 input_type, U8 max_lines)    /* input_type :- Other items are hilightable or not. */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_text_edit *i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (n_inline_text_edit_items >= MAX_INLINE_TEXT_EDIT_ITEMS)
    {
        return;
    }
    wgui_inline_mem_alloc_info[wgui_inline_mem_alloc_number] = item->item = wgui_inline_malloc(sizeof(wgui_inline_item_text_edit));
    wgui_inline_mem_alloc_number++; 
    item->flags = INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY;
    item->flags |= INLINE_ITEM_DISABLE_HIGHLIGHT;
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_VIEW_MODE;

    n_inline_text_edit_items++;

    i = (wgui_inline_item_text_edit*) item->item;
  
    i->height_of_item = max_lines;

    i->title = 0;
    i->title_icon = 0;
    i->buffer = buffer;
    i->buffer_size = buffer_size;
    i->flags = 0;
    i->input_type = input_type;

    item->text_p = i->buffer;
    item->handler = handle_inline_multi_line_rd_only;

    i->edit_complete_callback = NULL;
    i->custom_setup_function = NULL;
    i->validation_callback = NULL;

    i->UCS2_count = -1;
    MMI_multi_line_inputbox_present = 2;
}


/*****************************************************************************
 * FUNCTION
 *  menu_item_inline_multiline_box
 * DESCRIPTION
 *  is INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY
 * PARAMETERS
 *  void
 * RETURNS
 *  1->yes 0->no
 *****************************************************************************/
S32 menu_item_inline_multiline_box()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((wgui_inline_items[MMI_fixed_list_menu.n_items - 1].flags & 0xff) == INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  redraw_multiline_rd_only
 * DESCRIPTION
 *  redraw inline multiline rd only
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void redraw_multiline_rd_only(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_push_clip();
    gui_set_clip(MMI_fixed_list_menu.x, MMI_fixed_list_menu.y, MMI_fixed_list_menu.x + MMI_fixed_list_menu.width - 1, MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1);
    register_multiline_inputbox_viewer_keys();
    show_multiline_inputbox();
    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  handle_multi_line_rd_only_close
 * DESCRIPTION
 *  close function of inline multi line rd only
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void handle_multi_line_rd_only_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    reset_multiline_inputbox_vertical_scroll();
    reset_multiline_inputbox();
    complete_inline_item_edit = UI_dummy_function;
    redraw_current_inline_item = UI_dummy_function;
#ifdef __MMI_FTE_SUPPORT__
    wgui_current_inline_item_pen_function = UI_dummy_inline_item_pen_function;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  inscreen_multi_line_input_box_changed
 * DESCRIPTION
 *  is inline multi line input box changed
 * PARAMETERS
 *  void
 * RETURNS
 *  inscreen_multi_line_change_flag
 *****************************************************************************/
S32 inscreen_multi_line_input_box_changed()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return inscreen_multi_line_change_flag;
}


/*****************************************************************************
 * FUNCTION
 *  set_inscreen_multi_line_input_box_changed
 * DESCRIPTION
 *  set inscreen_multi_line_change_flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_inscreen_multi_line_input_box_changed()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inscreen_multi_line_change_flag = 1;
}


/*****************************************************************************
 * FUNCTION
 *  reset_inscreen_multi_line_input_box_changed
 * DESCRIPTION
 *  reset inscreen_multi_line_change_flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_inscreen_multi_line_input_box_changed()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inscreen_multi_line_change_flag = 0;
}

#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
extern gui_list_smooth_scrolling_by_pen_state_enum g_gui_ssp_state;
#endif /* GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN */


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  inline_multiline_rd_only_pen_handler
 * DESCRIPTION
 *  pen handler of inline rd only
 * PARAMETERS
 *  pen_event       [IN]    pen event    
 *  x               [IN]    pen x position    
 *  y               [IN]    pen y pisition    
 *  item_event      [?]     inline pen enum    
 * RETURNS
 *  BOOL
 *****************************************************************************/
BOOL inline_multiline_rd_only_pen_handler(
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_inline_item_pen_enum *item_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_multi_line_input_box_pen_enum multi_line_input_box_event;
    BOOL ret = MMI_TRUE;
    U16 idx = 0;
    static S32 pen_down_hilite_index = -1;
    static S32 reset_pre_hdlr = 0;
    static S32 down_x = -1, down_y = -1;
    static S32 maybe_list_ssp = 0;
    static S32 maybe_list_up_ssp = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *item_event = GUI_INLINE_ITEM_PEN_NONE;

    gdi_layer_set_clip(
        MMI_fixed_list_menu.x, 
        MMI_fixed_list_menu.y, 
        MMI_fixed_list_menu.x + MMI_fixed_list_menu.width - 1,
        MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1);

    if(pen_event == MMI_PEN_EVENT_DOWN)
    {
        if(!PEN_CHECK_BOUND(
            x,
            y,
            MMI_multiline_inputbox.x,
            MMI_multiline_inputbox.y,
            MMI_multiline_inputbox.width,
            MMI_multiline_inputbox.height))
        {
            return MMI_FALSE;
        }
        down_x = x;
        down_y = y;
    }

    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_multi_line_input_box_ext(&MMI_multiline_inputbox, x, y);
    MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    if (((pen_event == MMI_PEN_EVENT_DOWN) || (pen_event == MMI_PEN_EVENT_UP)) &&
        /*gui_multi_line_input_box_is_pen_down_in_hilite(&MMI_multiline_inputbox)*/
        gui_multi_line_input_box_is_pos_inside_hilite_ext(&MMI_multiline_inputbox, MMI_multiline_inputbox.cursor_p, &idx))
    {
        switch (pen_event)
        {
            case MMI_PEN_EVENT_DOWN:
                MMI_multiline_inputbox.current_hilite_idx = idx;
                wgui_inputs_ml_set_pen_down_flag();
                gui_push_clip();
                gui_set_clip(MMI_fixed_list_menu.x, MMI_fixed_list_menu.y, MMI_fixed_list_menu.x + MMI_fixed_list_menu.width - 1, MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1);
                gui_multi_line_input_box_go_to_hilite(
                    &MMI_multiline_inputbox,
                    MMI_multiline_inputbox.current_hilite_idx,
                    MMI_FALSE);
                gui_pop_clip();
                wgui_inputs_ml_clear_pen_down_flag();
                pen_down_hilite_index = MMI_multiline_inputbox.current_hilite_idx;
                break;
            case MMI_PEN_EVENT_UP:
            {
                if (pen_down_hilite_index == idx &&
                    MMI_multiline_inputbox.hilite_click_cb)
                {
                    MMI_multiline_inputbox.hilite_click_cb(MMI_multiline_inputbox.current_hilite_idx);
                }
                break;
            }
        }
    }
    else
    {
         switch (pen_event)
         {
             case MMI_PEN_EVENT_DOWN:
             {
                pen_down_hilite_index = -1;
                break;
             }
            case MMI_PEN_EVENT_UP:
    {
#ifdef __MMI_FTE_SUPPORT__
        if (gui_input_box_ssp_get_state() == GUI_INPUT_BOX_SSP_STATE_FOCUS)
        {
                    *item_event = GUI_INLINE_ITEM_PEN_SELECTED;
                }
#endif
                break;
            }
        }
    }
#ifdef __MMI_FTE_SUPPORT__
    gui_multi_line_input_box_translate_pen_event(&MMI_multiline_inputbox,
        pen_event, x, y, &multi_line_input_box_event);

    switch (pen_event)
    {
    case MMI_PEN_EVENT_DOWN:
        {
            maybe_list_ssp = 0;
            maybe_list_up_ssp = 0;
            if ((gui_input_box_ssp_get_state() != GUI_INPUT_BOX_SSP_STATE_UNFOCUS) &&
                (reset_pre_hdlr == 0)
               ) 
        {
            wgui_pen_reset_pre_hdlr();
            reset_pre_hdlr = 1;
        }
            if(MMI_multiline_inputbox.text_offset_y == 0)
            {
                maybe_list_ssp = 1;
            }
            if(wgui_inputs_ml_is_last_line())
            {
                maybe_list_up_ssp = 1;
            }
        break;
        }    
    case MMI_PEN_EVENT_UP:
    case MMI_PEN_EVENT_ABORT:
        {   
        if (reset_pre_hdlr)
        {
            wgui_pen_restore_pre_hdlr();
                reset_pre_hdlr = 0;
        }
        break;
        }
        case MMI_PEN_EVENT_MOVE:
        {
            if((maybe_list_ssp) &&
               (reset_pre_hdlr == 1)
              )
            {
                if(y > down_y)
                {
                    wgui_pen_restore_pre_hdlr();
#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
                    g_gui_ssp_state = GUI_LIST_SMOOTH_SCROLLING_BY_PEN_STATE_FOCUS;
#endif /* GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN */
                    reset_pre_hdlr = 0;
                }
                else
                {
                    maybe_list_ssp = 0;
                }
            }
            if((maybe_list_up_ssp) &&
               (reset_pre_hdlr == 1)
              )
            {
                if(y < down_y)
                {
                    wgui_pen_restore_pre_hdlr();
#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
                    g_gui_ssp_state = GUI_LIST_SMOOTH_SCROLLING_BY_PEN_STATE_FOCUS;
#endif /* GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN */
                    reset_pre_hdlr = 0;
                }
                else
                {
                    maybe_list_up_ssp = 0;
                }
            }
        }
    default:
        /* ignored events */
        break;
    }
#endif   

    return ret;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  handle_inline_multi_line_rd_only
 * DESCRIPTION
 *  activation function of inline multi line rd only
 * PARAMETERS
 *  x                   [IN]        left corner's x coordinate
 *  y                   [IN]        left corner's y coordinate
 *  width               [IN]        width
 *  height              [IN]        height
 *  key_code            [IN]        key code
 *  key_event           [IN]        key event
 *  text_p              [IN]        text pointer
 *  item                [IN]        inline item
 *  flags               [IN]        flags
 *  history_buffer      [IN]        history buffer         
 * RETURNS
 *  void
 *****************************************************************************/
void handle_inline_multi_line_rd_only(
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        S32 key_code,
        S32 key_event,
        U8 **text_p,
        void *item,
        U32 flags,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_text_edit *i = (wgui_inline_item_text_edit*) item;
    S32 l = 0;

    S32 inputbox_x = x;
    S32 inputbox_y = y;
    S32 inputbox_width = width;
    S32 inputbox_height = 0;
    S32 screen_item_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_current_inline_item_type = INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY;

    l = gui_strlen((UI_string_type) i->buffer);
    if (history_buffer == NULL || inscreen_multi_line_input_box_changed())
    {
        create_multiline_inputbox_set_buffer((UI_string_type) i->buffer, l, l, 0);
        reset_inscreen_multi_line_input_box_changed();
    }
    else
    {
        create_multiline_inputbox_set_buffer_no_text_reset((UI_string_type) i->buffer, l, l, 0);
    }

    move_multiline_inputbox(inputbox_x, inputbox_y);
#ifdef __MMI_FTE_SUPPORT__
    MMI_multiline_inputbox.flags |=
        (UI_MULTI_LINE_INPUT_BOX_VIEW_MODE |
        UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR | UI_MULTI_LINE_INPUT_BOX_INSIDE_INLINE_MENU
          |UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | UI_MULTI_LINE_INPUT_BOX_USE_PRESET_CLIPPING);
#else
    MMI_multiline_inputbox.flags |=
        (/* UI_MULTI_LINE_INPUT_BOX_AUTO_VERTICAL_SCROLL | */ UI_MULTI_LINE_INPUT_BOX_VIEW_MODE |
         UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR | UI_MULTI_LINE_INPUT_BOX_INSIDE_INLINE_MENU
          |UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | UI_MULTI_LINE_INPUT_BOX_USE_PRESET_CLIPPING);
#endif


    inputbox_height = height;

    resize_multiline_inputbox(inputbox_width, inputbox_height);
    register_multiline_inputbox_viewer_keys();
    MMI_multiline_inputbox.vertical_scroll_on = 0;

    if(g_inline_ml_rdly_highlight_list.hilite_list)
    {
        gui_inputs_ml_set_hilite_list(
                &MMI_multiline_inputbox,
                g_inline_ml_rdly_highlight_list.hilite_list,
                g_inline_ml_rdly_highlight_list.count,
                0,
                g_inline_ml_rdly_highlight_list.hilite_cb,
                g_inline_ml_rdly_highlight_list.click_cb
                );
    }

    if(history_buffer != NULL)
    {
        wgui_inputs_ml_set_category_history(INLINE_MULTI_LINE_EDIT_HISTORY_ID, history_buffer);
        if (g_inline_ml_rdly_highlight_list.hilite_list)
        {
            gui_multi_line_input_box_go_to_hilite(
                        &MMI_multiline_inputbox,
                        MMI_multiline_inputbox.current_hilite_idx,
                        MMI_FALSE);
        }
    }

    show_multiline_inputbox();

#ifdef __MMI_TOUCH_SCREEN__
    wgui_current_inline_item_pen_function = inline_multiline_rd_only_pen_handler;
#endif
    redraw_current_inline_item = redraw_multiline_rd_only;
    complete_inline_item_edit = handle_multi_line_rd_only_close;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_multiline_append_string
 * DESCRIPTION
 *  append string into inline multiline
 * PARAMETERS
 *  input_type               [IN]        input type
 *  buffer                   [IN]        buffer pointer
 *  buffer_size              [IN]        buffer size
 *  string                   [IN]        String
 *  history_buffer           [IN]        history buffer 
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_multiline_append_string(
                    U32 input_type, 
                    U8 *buffer, 
                    S32 buffer_size, 
                    U8 *string, 
                    U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 start_offset = 0, s = 0;
    U8 *h_ptr = NULL;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s = sizeof(list_menu_category_history);
    s = (s + 3) / 4;
    s *= 4;
    start_offset = s + sizeof(U32);
    h_ptr = history_buffer + start_offset;
    wgui_inputs_ml_append_string(
        input_type,
        buffer,
        buffer_size,
        string,
        h_ptr,
        INLINE_MULTI_LINE_EDIT_HISTORY_ID,
        NULL);
}


/*****************************************************************************
* FUNCTION
*  wgui_inline_ml_rdly_set_hilite_list
* DESCRIPTION
*  Set highlight list for multiline readonly item.
* PARAMETERS
* RETURNS
*  characters inserted
*****************************************************************************/
void wgui_inline_ml_rdly_set_hilite_list( 
	wgui_inline_item  *item,
  	wgui_inline_ml_rdly_highlight_list_struct *highlight_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 wgui_inline_item_text_edit *i = (wgui_inline_item_text_edit*) item->item;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if((item->flags & 0xff) == INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY)
    {
        memcpy(
            (void *)&g_inline_ml_rdly_highlight_list, 
            (void *)highlight_list, 
            sizeof(wgui_inline_ml_rdly_highlight_list_struct));  
    }
}


#endif /*defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__)*/
#endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 

/*****************************************************************************
 * FUNCTION
 *  wgui_get_inline_item_height
 * DESCRIPTION
 *  get inline multiline height
 * PARAMETERS
 *  item_index  [IN]    
 * RETURNS
 *  S32
 *****************************************************************************/
S32 wgui_get_inline_item_height(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__)    
    wgui_inline_item_text_edit *i;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#ifndef __MMI_FTE_SUPPORT__    
#if defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__)
    if(((wgui_inline_items[item_index].flags & 0xFF) == INLINE_ITEM_TYPE_MULTI_LINE_EDIT) ||
       ((wgui_inline_items[item_index].flags & 0xFF) == INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY)
      )
    {
    i = (wgui_inline_item_text_edit*)wgui_inline_items[item_index].item;
        return (i->height_of_item) * MMI_MENUITEM_HEIGHT; 
    } 
    else 
#endif
    {
        return  MMI_MENUITEM_HEIGHT; 
    }
#else
#if defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__)
    if((wgui_inline_items[item_index].flags & 0xFF) == INLINE_ITEM_TYPE_MULTI_LINE_EDIT)
    {
        i = (wgui_inline_item_text_edit*)wgui_inline_items[item_index].item;
        return (i->height_of_item) * MMI_MENUITEM_HEIGHT + (MMI_fixed_list_menu.height % MMI_fixed_icontext_menuitem.height); 
    } 

    if((wgui_inline_items[item_index].flags & 0xFF) == INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY)
    {
        i = (wgui_inline_item_text_edit*)wgui_inline_items[item_index].item;
            
        return (i->height_of_item) * MMI_MENUITEM_HEIGHT;
    } 
    else 
#endif
    if((wgui_inline_items[item_index].flags & 0xFF) == INLINE_ITEM_TYPE_CAPTION)
    {
        return INLINE_FTE_TWO_LINE_1_HEIGHT;
    }
    else if(g_inline_fte_item_height_table[item_index] == INLINE_LINE_STYLE_ONE_LINE)
    {
        return INLINE_FTE_ONE_LINE_HEIGHT;
    }
    else if(g_inline_fte_item_height_table[item_index] == INLINE_LINE_STYLE_TWO_LINE)
    {
        return INLINE_FTE_TWO_LINE_2_HEIGHT;
    }
#endif

    return 0;
}

/***************************************************************************** 
 * Some Utility function for Inline Editor 
 *
 * This is Utility function related to history and themes
 *****************************************************************************/

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define INLINE_ITEM_DATA_ID_LENGTH                    2
#define INLINE_ITEM_DATA_SIZE_LENGTH                  2
#define INLINE_ITEM_CAPTION_DATA_ID                   0x0001
#define INLINE_ITEM_DISPLAY_ONLY_DATA_ID              0x0002
#define INLINE_ITEM_USER_DEFINED_SELECT_DATA_ID       0x0003
#define INLINE_ITEM_TEXT_EDIT_DATA_ID                 0x0004
#define INLINE_ITEM_FULL_SCREEN_EDIT_DATA_ID          0x0005
#define INLINE_ITEM_SELECT_DATA_ID                    0x0006
#define INLINE_ITEM_DATE_DATA_ID                      0x0007
#define INLINE_ITEM_TIME_DATA_ID                      0x0008
#define INLINE_ITEM_TIME_PERIOD_DATA_ID               0x0009
#define INLINE_ITEM_IP4_EDIT_DATA_ID                  0x0010
#define INLINE_ITEM_DOW_SELECT_DATA_ID                0x0011
#define INLINE_ITEM_ATTACH_IMAGE_DATA_ID              0x0012
#define INLINE_ITEM_TYPE_MULTI_LINE_DATA_ID           0x0013
#define INLINE_ITEM_COLOR_SELECT_DATA_ID              0x0014

#define reverse_pixtel_UI_memcpy(b1,b2,n) gui_memcpy((b2),(b1),(n))
#define reverse_pixtel_UI_strcpy(s1,s2)   gui_strcpy(s2,s1)

/***************************************************************************** 
 * Local Variable
 *****************************************************************************/
#ifdef __MMI_UI_LIST_GRID_LINE__
static MMI_BOOL wgui_inline_separator_table[MAX_INLINE_ITEMS];
#endif /* __MMI_UI_LIST_GRID_LINE__ */

/***************************************************************************** 
 * Function Implementation
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  wgui_get_inline_history_size
 * DESCRIPTION
 *  get current inline item's history size
 * PARAMETERS
 *  void
 * RETURNS
 *  history size
 *****************************************************************************/
S32 wgui_get_inline_history_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 inline_history_size = 0, s;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (wgui_current_inline_item_type)
    {
#if defined(__MMI_INLINE_ITEM_DATE__)    
        case INLINE_ITEM_TYPE_DATE:        
            inline_history_size = sizeof(inline_date_edit_history);
            break;
#endif

#if defined(__MMI_INLINE_ITEM_TIME__) 
        case INLINE_ITEM_TYPE_TIME:           
            inline_history_size = sizeof(inline_time_edit_history);
            break;
#endif

#if defined (__MMI_INLINE_ITEM_TIME_PEROID__)            
        case INLINE_ITEM_TYPE_TIME_PERIOD:
            inline_history_size = sizeof(inline_time_period_edit_history);
            break;
#endif            
#ifdef __MMI_INLINE_ITEM_IP4__
        case INLINE_ITEM_TYPE_IP4_EDIT:
            inline_history_size = sizeof(inline_IP4_edit_history);
            break;
#endif            
#ifdef __MMI_INLINE_ITEM_DOW__ 
        case INLINE_ITEM_TYPE_DOW_SELECT:           
            inline_history_size = sizeof(inline_DOW_select_history);
            break;
#endif            
#if defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__)
        case INLINE_ITEM_TYPE_MULTI_LINE_EDIT:
        case INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY: 
            inline_history_size = sizeof(multiline_inputbox_category_history);
            break;
#endif            
    }
    s = sizeof(list_menu_category_history);
    s = (s + 3) / 4;
    s *= 4;
    return (s + inline_history_size + sizeof(U32));
}

/* Current structure:
   history = <list menu history> + <4 bytes for flags> + <inline edit specific history>
   flags = 1: Content has been changed by user
   flags = 0: Content has not been changed by user       */


/*****************************************************************************
 * FUNCTION
 *  wgui_get_inline_history
 * DESCRIPTION
 *  get current inline item's history buffer
 * PARAMETERS
 *  history_ID          [IN]        history id
 *  history_buffer      [OUT]        history buffer         
 * RETURNS
 *  history buffer
 *****************************************************************************/
U8 *wgui_get_inline_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 *flags;
    S32 start_offset, s;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_list_menu_category_history(history_ID, history_buffer);
    s = sizeof(list_menu_category_history);
    s = (s + 3) / 4;
    s *= 4;
    start_offset = s + sizeof(U32);
    if(cui_inline_is_current_cui() == MMI_FALSE)
    {
        flags = (U32*) (history_buffer + s);
        *flags = wgui_inline_list_menu_changed;
    }
    else
    {
        /* when insert item or delete item, we should update h->num_items,
        ande when h->last_displayed_item > (h->num_items - 1), we should update last and first
        item. 
        */
        list_menu_category_history *h = (list_menu_category_history*) history_buffer;
        h->num_items = g_cui_inline_current_instance->item_count;
        if(h->last_displayed_item > (h->num_items - 1))
        {
            h->last_displayed_item = h->num_items - 1;
            if(h->first_displayed_item > 0)
            {
                h->first_displayed_item --;     
            }
        }
        /*And highlight item of list hisory is invalid when CUI. */
        cui_inline_item_save_gui_buffer(wgui_inline_item_highlighted_index, 
                        &wgui_inline_items[wgui_inline_item_highlighted_index],
                        (U8*)(history_buffer + start_offset));      
    }

    switch (wgui_current_inline_item_type)
    {
#if defined(__MMI_INLINE_ITEM_DATE__)    
        case INLINE_ITEM_TYPE_DATE:
            inline_date_edit_get_history((U8*) (history_buffer + start_offset));
            break;
#endif   
#if defined(__MMI_INLINE_ITEM_TIME__) 
        case INLINE_ITEM_TYPE_TIME:
            inline_time_edit_get_history((U8*) (history_buffer + start_offset));
            break;
#endif            
#if defined (__MMI_INLINE_ITEM_TIME_PEROID__)               
        case INLINE_ITEM_TYPE_TIME_PERIOD:
            inline_time_period_edit_get_history((U8*) (history_buffer + start_offset));
            break;
#endif
#ifdef __MMI_INLINE_ITEM_IP4__
        case INLINE_ITEM_TYPE_IP4_EDIT:            
            inline_IP4_edit_get_history((U8*) (history_buffer + start_offset));
            break;
#endif            
#ifdef __MMI_INLINE_ITEM_DOW__
        case INLINE_ITEM_TYPE_DOW_SELECT:            
            inline_DOW_select_get_history((U8*) (history_buffer + start_offset));
            break;
#endif   
#if defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__)            
        case INLINE_ITEM_TYPE_MULTI_LINE_EDIT:
        case INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY: 
            inline_multi_line_edit_get_history((U8*) (history_buffer + start_offset));
            break;
#endif            
#if defined (__MMI_INLINE_ITEM_IMAGETEXT__)
        case INLINE_ITEM_IMAGE_TEXT_TYPE:
            inline_image_text_get_history((U8*) (history_buffer + start_offset));
            break;
#endif            

    }
    return (history_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_edit_get_current_item_history
 * DESCRIPTION
 *  get current inline item history buffer
 * PARAMETERS
 *  history_buffer      [OUT]   history buffer     
 * RETURNS
 *  history buffer
 *****************************************************************************/
U8 *wgui_inline_edit_get_current_item_history(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (wgui_current_inline_item_type)
    {
#if defined(__MMI_INLINE_ITEM_DATE__)
        case INLINE_ITEM_TYPE_DATE:
            inline_date_edit_get_history((U8*) (history_buffer));
            break;
#endif            
#if defined(__MMI_INLINE_ITEM_TIME__) 
        case INLINE_ITEM_TYPE_TIME:           
            inline_time_edit_get_history((U8*) (history_buffer));
            break;
#endif            
#if defined (__MMI_INLINE_ITEM_TIME_PEROID__)  
        case INLINE_ITEM_TYPE_TIME_PERIOD:
            inline_time_period_edit_get_history((U8*) (history_buffer));
            break;
#endif
#ifdef __MMI_INLINE_ITEM_IP4__
        case INLINE_ITEM_TYPE_IP4_EDIT:            
            inline_IP4_edit_get_history((U8*) (history_buffer));
            break;
#endif            
#ifdef __MMI_INLINE_ITEM_DOW__
        case INLINE_ITEM_TYPE_DOW_SELECT:            
            inline_DOW_select_get_history((U8*) (history_buffer));
            break;
#endif            
#if defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__)            
        case INLINE_ITEM_TYPE_MULTI_LINE_EDIT:
            inline_multi_line_edit_get_history((U8*) (history_buffer));
            break;
#endif            
    }
    wgui_current_history_buffer = history_buffer;
    return (history_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_get_inline_data_size
 * DESCRIPTION
 *  get inline data size
 * PARAMETERS
 *  void
 * RETURNS
 *  inlie data size
 *****************************************************************************/
S32 wgui_get_inline_data_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, total_size = 0, size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(cui_inline_is_current_cui())
    {
        return 1;
    }

    for (i = 0; i < wgui_n_inline_items; i++)
    {
        size = 0;
        switch (wgui_inline_items[i].flags & 0xff)
        {
            case INLINE_ITEM_TYPE_CAPTION:
            case INLINE_ITEM_TYPE_DISPLAY_ONLY:
            case INLINE_ITEM_TYPE_USER_DEFINED_SELECT:
                break;

            case INLINE_ITEM_TYPE_TEXT_EDIT:
            {
                S32 l;
                wgui_inline_item_text_edit *ii = (wgui_inline_item_text_edit*) wgui_inline_items[i].item;

                l = ii->buffer_size * ENCODING_LENGTH;
                if (ii->input_type & INPUT_TYPE_PLUS_CHARACTER_HANDLING)
                {
                    l += ENCODING_LENGTH;
                }
                size = INLINE_ITEM_DATA_ID_LENGTH + INLINE_ITEM_DATA_SIZE_LENGTH + sizeof(S32) + l;
            }
                break;

            case INLINE_ITEM_TYPE_FULL_SCREEN_EDIT:
            {
                S32 l;
                wgui_inline_item_text_edit *ii = (wgui_inline_item_text_edit*) wgui_inline_items[i].item;

                l = ii->buffer_size * ENCODING_LENGTH;
                if (ii->input_type & INPUT_TYPE_PLUS_CHARACTER_HANDLING)
                {
                    l += ENCODING_LENGTH;
                }
                size = INLINE_ITEM_DATA_ID_LENGTH + INLINE_ITEM_DATA_SIZE_LENGTH + sizeof(U32) + sizeof(S32) + (l << 1);
            }
                break;

            case INLINE_ITEM_TYPE_SELECT:
            {
                size = INLINE_ITEM_DATA_ID_LENGTH + 2;
            }
                break;

            case INLINE_ITEM_TYPE_DATE:
            {
                size = INLINE_ITEM_DATA_ID_LENGTH + 5 * ENCODING_LENGTH + 3 * ENCODING_LENGTH + 3 * ENCODING_LENGTH;
            }
                break;

            case INLINE_ITEM_TYPE_TIME:
            {
                size = INLINE_ITEM_DATA_ID_LENGTH + 3 * ENCODING_LENGTH + 3 * ENCODING_LENGTH;
            }
                break;
#if defined (__MMI_INLINE_ITEM_TIME_PEROID__)   
            case INLINE_ITEM_TYPE_TIME_PERIOD:
            {
                size =
                    INLINE_ITEM_DATA_ID_LENGTH + 3 * ENCODING_LENGTH + 3 * ENCODING_LENGTH + 3 * ENCODING_LENGTH +
                    3 * ENCODING_LENGTH;
            }
                break;
#endif
#if defined (__MMI_INLINE_ITEM_IP4__)
            case INLINE_ITEM_TYPE_IP4_EDIT:
            {
                size =
                    INLINE_ITEM_DATA_ID_LENGTH + 4 * ENCODING_LENGTH + 4 * ENCODING_LENGTH + 4 * ENCODING_LENGTH +
                    4 * ENCODING_LENGTH;
            }
                break;
#endif                
#if defined (__MMI_INLINE_ITEM_DOW__)
            case INLINE_ITEM_TYPE_DOW_SELECT:
            {
                size = INLINE_ITEM_DATA_ID_LENGTH + 7;
            }
                break;
#endif                
        #if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) /* 4/5 */
        #if defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__)
            case INLINE_ITEM_TYPE_MULTI_LINE_EDIT:
            case INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY:
            {
                size = INLINE_ITEM_DATA_ID_LENGTH + 4 + sizeof(multiline_inputbox_category_history);
            }
                break;
        #endif /* defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__) */        
        #endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 
#if defined (__MMI_INLINE_ITEM_COLOR_SELECT__)
            case INLINE_ITEM_TYPE_COLOR_SELECT:
            {
                size = INLINE_ITEM_DATA_ID_LENGTH + 4;
            }
#endif            
                break;
        }
        total_size += size;
        total_size = (total_size + 3)&~3;
    }
    return (total_size);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_get_inline_data
 * DESCRIPTION
 *  get inline data
 * PARAMETERS
 *  data        [OUT]   inline data     
 * RETURNS
 *  data
 *****************************************************************************/
U8 *wgui_get_inline_data(U8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, offset = 0, size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(cui_inline_is_current_cui())
    {
        cui_inline_item_save_input_buffer();
        return data;
    }

    for (i = 0; i < wgui_n_inline_items; i++)
    {
        size = 0;
        switch (wgui_inline_items[i].flags & 0xff)
        {
            case INLINE_ITEM_TYPE_CAPTION:
            case INLINE_ITEM_TYPE_DISPLAY_ONLY:
            case INLINE_ITEM_TYPE_USER_DEFINED_SELECT:
                break;

            case INLINE_ITEM_TYPE_DATE:
            {
#if defined(__MMI_INLINE_ITEM_DATE__)                
                U16 ID = INLINE_ITEM_DATE_DATA_ID;
                wgui_inline_item_date *ii = (wgui_inline_item_date*) wgui_inline_items[i].item;

                size = INLINE_ITEM_DATA_ID_LENGTH + 5 * ENCODING_LENGTH + 3 * ENCODING_LENGTH + 3 * ENCODING_LENGTH;
                gui_memcpy((U8*) & data[offset], (U8*) & ID, INLINE_ITEM_DATA_ID_LENGTH);
                gui_strcpy(
                    (UI_string_type) & data[offset + INLINE_ITEM_DATA_ID_LENGTH],
                    (UI_string_type) ii->year_buffer);
                gui_strcpy(
                    (UI_string_type) & data[offset + INLINE_ITEM_DATA_ID_LENGTH + 5 * ENCODING_LENGTH],
                    (UI_string_type) ii->month_buffer);
                gui_strcpy(
                    (UI_string_type) & data[offset + INLINE_ITEM_DATA_ID_LENGTH + 5 * ENCODING_LENGTH + 3 * ENCODING_LENGTH],
                    (UI_string_type) ii->day_buffer);
#endif                
            }
                break;

            case INLINE_ITEM_TYPE_TIME:
            {
#if defined(__MMI_INLINE_ITEM_TIME__)                
                U16 ID = INLINE_ITEM_TIME_DATA_ID;
                wgui_inline_item_time *ii = (wgui_inline_item_time*) wgui_inline_items[i].item;

                size = INLINE_ITEM_DATA_ID_LENGTH + 3 * ENCODING_LENGTH + 3 * ENCODING_LENGTH;
                gui_memcpy((U8*) & data[offset], (U8*) & ID, INLINE_ITEM_DATA_ID_LENGTH);
                gui_strcpy(
                    (UI_string_type) & data[offset + INLINE_ITEM_DATA_ID_LENGTH],
                    (UI_string_type) ii->hours_buffer);
                gui_strcpy(
                    (UI_string_type) & data[offset + INLINE_ITEM_DATA_ID_LENGTH + 3 * ENCODING_LENGTH],
                    (UI_string_type) ii->minutes_buffer);
#endif                
            }
                break;
#if defined (__MMI_INLINE_ITEM_TIME_PEROID__)   
            case INLINE_ITEM_TYPE_TIME_PERIOD:
            {
                U16 ID = INLINE_ITEM_TIME_PERIOD_DATA_ID;
                wgui_inline_item_time_period *ii = (wgui_inline_item_time_period*) wgui_inline_items[i].item;

                size =
                    INLINE_ITEM_DATA_ID_LENGTH + 3 * ENCODING_LENGTH + 3 * ENCODING_LENGTH + 3 * ENCODING_LENGTH +
                    3 * ENCODING_LENGTH;
                gui_memcpy((U8*) & data[offset], (U8*) & ID, INLINE_ITEM_DATA_ID_LENGTH);
                gui_strcpy(
                    (UI_string_type) & data[offset + INLINE_ITEM_DATA_ID_LENGTH],
                    (UI_string_type) ii->hours_buffer1);
                gui_strcpy(
                    (UI_string_type) & data[offset + INLINE_ITEM_DATA_ID_LENGTH + 3 * ENCODING_LENGTH],
                    (UI_string_type) ii->minutes_buffer1);
                gui_strcpy(
                    (UI_string_type) & data[offset + INLINE_ITEM_DATA_ID_LENGTH + 3 * ENCODING_LENGTH + 3 * ENCODING_LENGTH],
                    (UI_string_type) ii->hours_buffer2);
                gui_strcpy(
                    (UI_string_type) & data[offset + INLINE_ITEM_DATA_ID_LENGTH + 3 * ENCODING_LENGTH + 3 * ENCODING_LENGTH + 3 * ENCODING_LENGTH],
                    (UI_string_type) ii->minutes_buffer2);
            }
                break;
#endif
            case INLINE_ITEM_TYPE_IP4_EDIT:
            {
#ifdef __MMI_INLINE_ITEM_IP4__                
                U16 ID = INLINE_ITEM_IP4_EDIT_DATA_ID;
                wgui_inline_item_IP4 *ii = (wgui_inline_item_IP4*) wgui_inline_items[i].item;

                size =
                    INLINE_ITEM_DATA_ID_LENGTH + 4 * ENCODING_LENGTH + 4 * ENCODING_LENGTH + 4 * ENCODING_LENGTH +
                    4 * ENCODING_LENGTH;
                gui_memcpy((U8*) & data[offset], (U8*) & ID, INLINE_ITEM_DATA_ID_LENGTH);
                gui_strcpy((UI_string_type) & data[offset + INLINE_ITEM_DATA_ID_LENGTH], (UI_string_type) ii->b1);
                gui_strcpy(
                    (UI_string_type) & data[offset + INLINE_ITEM_DATA_ID_LENGTH + 4 * ENCODING_LENGTH],
                    (UI_string_type) ii->b2);
                gui_strcpy(
                    (UI_string_type) & data[offset + INLINE_ITEM_DATA_ID_LENGTH + 4 * ENCODING_LENGTH + 4 * ENCODING_LENGTH],
                    (UI_string_type) ii->b3);
                gui_strcpy(
                    (UI_string_type) & data[offset + INLINE_ITEM_DATA_ID_LENGTH + 4 * ENCODING_LENGTH + 4 * ENCODING_LENGTH + 4 * ENCODING_LENGTH],
                    (UI_string_type) ii->b4);
#endif                
            }
                break;

#ifdef __MMI_INLINE_ITEM_DOW__ 
            case INLINE_ITEM_TYPE_DOW_SELECT:
            {               
                U16 ID = INLINE_ITEM_DOW_SELECT_DATA_ID;
                wgui_inline_item_DOW_select *ii = (wgui_inline_item_DOW_select*) wgui_inline_items[i].item;

                size = INLINE_ITEM_DATA_ID_LENGTH + 7;
                gui_memcpy((U8*) & data[offset], (U8*) & ID, INLINE_ITEM_DATA_ID_LENGTH);
                gui_memcpy((U8*) & data[offset + INLINE_ITEM_DATA_ID_LENGTH], (U8*) ii->list_of_states, 7);               
            }
                break;
#endif                 
        #if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
        #if defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__)
            case INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY:
            {
                U32 m;

                m = (offset + INLINE_ITEM_DATA_ID_LENGTH+3)&~3;

                size = INLINE_ITEM_DATA_ID_LENGTH + 4 + sizeof(multiline_inputbox_category_history);
                
                get_multiline_inputbox_category_history(
                    MMI_INLINE_BOX_HISTORY_ID,
                    &data[m]);
            }
                break;
        #endif        
        #endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 
            case INLINE_ITEM_TYPE_COLOR_SELECT:
            {
#if defined (__MMI_INLINE_ITEM_COLOR_SELECT__)                
                U16 ID = INLINE_ITEM_COLOR_SELECT_DATA_ID;
                S32 highlighted_index;
                S32 start_index;

                wgui_inline_item_color_select *ii = (wgui_inline_item_color_select*) wgui_inline_items[i].item;

                size = INLINE_ITEM_DATA_ID_LENGTH + 4;

                highlighted_index = ii->highlighted_index;
                start_index = ii->start_index;

                gui_memcpy((U8*) & data[offset], (U8*) & ID, INLINE_ITEM_DATA_ID_LENGTH);
                gui_memcpy((U8*) & data[offset + INLINE_ITEM_DATA_ID_LENGTH], (U8*) & highlighted_index, 2);
                gui_memcpy((U8*) & data[offset + INLINE_ITEM_DATA_ID_LENGTH + 2], (U8*) & start_index, 2);
#endif
            }
                break;
        }
        offset += size;
        offset = (offset + 3)&~3;
    }
    return (data);
}



/*****************************************************************************
 * FUNCTION
 *  wgui_set_inline_data
 * DESCRIPTION
 *  set inline data
 * PARAMETERS
 *  inline_items        [IN]    inline item     
 *  n_items             [IN]    item number        
 *  data                [IN]    data     
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_set_inline_data(wgui_inline_item *inline_items, S32 n_items, U8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, offset = 0, size;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data == NULL)
    {
        return;
    }
    for (i = 0; i < n_items; i++)
    {
        size = 0;
        switch (inline_items[i].flags & 0xff)
        {
            case INLINE_ITEM_TYPE_CAPTION:
            case INLINE_ITEM_TYPE_DISPLAY_ONLY:
            case INLINE_ITEM_TYPE_USER_DEFINED_SELECT:
                break;

            case INLINE_ITEM_TYPE_DATE:
            {
#if defined(__MMI_INLINE_ITEM_DATE__)                
                U16 ID = INLINE_ITEM_DATE_DATA_ID;
                wgui_inline_item_date *ii = (wgui_inline_item_date*) inline_items[i].item;

                size = INLINE_ITEM_DATA_ID_LENGTH + 5 * ENCODING_LENGTH + 3 * ENCODING_LENGTH + 3 * ENCODING_LENGTH;
                reverse_pixtel_UI_memcpy((U8*) & data[offset], (U8*) & ID, INLINE_ITEM_DATA_ID_LENGTH);
                reverse_pixtel_UI_strcpy(
                    (UI_string_type) & data[offset + INLINE_ITEM_DATA_ID_LENGTH],
                    (UI_string_type) ii->year_buffer);
                reverse_pixtel_UI_strcpy(
                    (UI_string_type) & data[offset + INLINE_ITEM_DATA_ID_LENGTH + 5 * ENCODING_LENGTH],
                    (UI_string_type) ii->month_buffer);
                reverse_pixtel_UI_strcpy(
                    (UI_string_type) & data[offset + INLINE_ITEM_DATA_ID_LENGTH + 5 * ENCODING_LENGTH + 3 * ENCODING_LENGTH],
                    (UI_string_type) ii->day_buffer);
                ii->string_construct_callback(
                        inline_items[i].text_p,
                        ii->day_buffer,
                        ii->month_buffer,
                        ii->year_buffer);
#endif                
            }
                break;

            case INLINE_ITEM_TYPE_TIME:
            {
#if defined(__MMI_INLINE_ITEM_TIME__)                
                U16 ID = INLINE_ITEM_TIME_DATA_ID;
                wgui_inline_item_time *ii = (wgui_inline_item_time*) inline_items[i].item;

                size = INLINE_ITEM_DATA_ID_LENGTH + 3 * ENCODING_LENGTH + 3 * ENCODING_LENGTH;
                reverse_pixtel_UI_memcpy((U8*) & data[offset], (U8*) & ID, INLINE_ITEM_DATA_ID_LENGTH);
                reverse_pixtel_UI_strcpy(
                    (UI_string_type) & data[offset + INLINE_ITEM_DATA_ID_LENGTH],
                    (UI_string_type) ii->hours_buffer);
                reverse_pixtel_UI_strcpy(
                    (UI_string_type) & data[offset + INLINE_ITEM_DATA_ID_LENGTH + 3 * ENCODING_LENGTH],
                    (UI_string_type) ii->minutes_buffer);
                ii->string_construct_callback(
                        inline_items[i].text_p,
                        ii->hours_buffer,
                        ii->minutes_buffer,
                        ii->AM_PM_flag);
#endif                
            }
                break;
#if defined (__MMI_INLINE_ITEM_TIME_PEROID__)   
            case INLINE_ITEM_TYPE_TIME_PERIOD:
            {
                U16 ID = INLINE_ITEM_TIME_PERIOD_DATA_ID;
                wgui_inline_item_time_period *ii = (wgui_inline_item_time_period*) inline_items[i].item;

                size =
                    INLINE_ITEM_DATA_ID_LENGTH + 3 * ENCODING_LENGTH + 3 * ENCODING_LENGTH + 3 * ENCODING_LENGTH +
                    3 * ENCODING_LENGTH;
                reverse_pixtel_UI_memcpy((U8*) & data[offset], (U8*) & ID, INLINE_ITEM_DATA_ID_LENGTH);
                reverse_pixtel_UI_strcpy(
                    (UI_string_type) & data[offset + INLINE_ITEM_DATA_ID_LENGTH],
                    (UI_string_type) ii->hours_buffer1);
                reverse_pixtel_UI_strcpy(
                    (UI_string_type) & data[offset + INLINE_ITEM_DATA_ID_LENGTH + 3 * ENCODING_LENGTH],
                    (UI_string_type) ii->minutes_buffer1);
                reverse_pixtel_UI_strcpy(
                    (UI_string_type) & data[offset + INLINE_ITEM_DATA_ID_LENGTH + 3 * ENCODING_LENGTH + 3 * ENCODING_LENGTH],
                    (UI_string_type) ii->hours_buffer2);
                reverse_pixtel_UI_strcpy(
                    (UI_string_type) & data[offset + INLINE_ITEM_DATA_ID_LENGTH + 3 * ENCODING_LENGTH + 3 * ENCODING_LENGTH + 3 * ENCODING_LENGTH],
                    (UI_string_type) ii->minutes_buffer2);
                ii->string_construct_callback(
                        inline_items[i].text_p,
                        ii->hours_buffer1,
                        ii->minutes_buffer1,
                        ii->AM_PM_flag1,
                        ii->hours_buffer2,
                        ii->minutes_buffer2,
                        ii->AM_PM_flag2);
            }
                break;
#endif         
            case INLINE_ITEM_TYPE_IP4_EDIT:
            {
#ifdef __MMI_INLINE_ITEM_IP4__                
                U16 ID = INLINE_ITEM_IP4_EDIT_DATA_ID;
                wgui_inline_item_IP4 *ii = (wgui_inline_item_IP4*) inline_items[i].item;

                size =
                    INLINE_ITEM_DATA_ID_LENGTH + 4 * ENCODING_LENGTH + 4 * ENCODING_LENGTH + 4 * ENCODING_LENGTH +
                    4 * ENCODING_LENGTH;
                reverse_pixtel_UI_memcpy((U8*) & data[offset], (U8*) & ID, INLINE_ITEM_DATA_ID_LENGTH);
                reverse_pixtel_UI_strcpy(
                    (UI_string_type) & data[offset + INLINE_ITEM_DATA_ID_LENGTH],
                    (UI_string_type) ii->b1);
                reverse_pixtel_UI_strcpy(
                    (UI_string_type) & data[offset + INLINE_ITEM_DATA_ID_LENGTH + 4 * ENCODING_LENGTH],
                    (UI_string_type) ii->b2);
                reverse_pixtel_UI_strcpy(
                    (UI_string_type) & data[offset + INLINE_ITEM_DATA_ID_LENGTH + 4 * ENCODING_LENGTH + 4 * ENCODING_LENGTH],
                    (UI_string_type) ii->b3);
                reverse_pixtel_UI_strcpy(
                    (UI_string_type) & data[offset + INLINE_ITEM_DATA_ID_LENGTH + 4 * ENCODING_LENGTH + 4 * ENCODING_LENGTH + 4 * ENCODING_LENGTH],
                    (UI_string_type) ii->b4);
                ii->string_construct_callback(inline_items[i].text_p, ii->b1, ii->b2, ii->b3, ii->b4);
#endif
            }
                break;
#if defined(__MMI_INLINE_ITEM_DOW__)
            case INLINE_ITEM_TYPE_DOW_SELECT:
            {                
                U16 ID = INLINE_ITEM_DOW_SELECT_DATA_ID;
                wgui_inline_item_DOW_select *ii = (wgui_inline_item_DOW_select*) inline_items[i].item;

                size = INLINE_ITEM_DATA_ID_LENGTH + 7;
                reverse_pixtel_UI_memcpy((U8*) & data[offset], (U8*) & ID, INLINE_ITEM_DATA_ID_LENGTH);
                reverse_pixtel_UI_memcpy(
                    (U8*) & data[offset + INLINE_ITEM_DATA_ID_LENGTH],
                    (U8*) ii->list_of_states,
                    7);                
            }
                break;
#endif                
        #if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
        #if defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__)
            case INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY:
            {
                U32 m;
                m = (offset + INLINE_ITEM_DATA_ID_LENGTH+3)&~3;

                size = INLINE_ITEM_DATA_ID_LENGTH + 4 + sizeof(multiline_inputbox_category_history);
                set_multiline_inputbox_category_history(MMI_INLINE_BOX_HISTORY_ID, &data[m]);
            }
                break;
        #endif        
        #endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 
            case INLINE_ITEM_TYPE_COLOR_SELECT:
            {
#if defined (__MMI_INLINE_ITEM_COLOR_SELECT__)                
                U16 ID = INLINE_ITEM_SELECT_DATA_ID;
                S32 highlighted_index = 0;
                S32 start_index = 0;

                wgui_inline_item_color_select *ii = (wgui_inline_item_color_select*) inline_items[i].item;

                size = INLINE_ITEM_DATA_ID_LENGTH + 4;

                reverse_pixtel_UI_memcpy((U8*) & data[offset], (U8*) & ID, INLINE_ITEM_DATA_ID_LENGTH);
                reverse_pixtel_UI_memcpy(
                    (U8*) & data[offset + INLINE_ITEM_DATA_ID_LENGTH],
                    (U8*) & highlighted_index,
                    2);
                reverse_pixtel_UI_memcpy(
                    (U8*) & data[offset + INLINE_ITEM_DATA_ID_LENGTH + 2],
                    (U8*) & start_index,
                    2);

                ii->highlighted_index = (U16) (highlighted_index);
                ii->start_index = (U16) (start_index);
#endif                
            }
                break;

        }
        offset += size;
        offset = (offset + 3)&~3;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_set_items_csk
 * DESCRIPTION
 *  Default highlight handler used for inline editing menu
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inline_set_items_csk(S32 item_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    switch(item_type)
    {
#if defined (__MMI_INLINE_ITEM_MULTILINE_EDIT__)    
        case INLINE_ITEM_TYPE_MULTI_LINE_EDIT:
        {

            set_softkey_icon(get_image(IMG_GLOBAL_COMMON_CSK), MMI_CENTER_SOFTKEY);
            register_softkey_handler(MMI_CENTER_SOFTKEY);
            set_softkey_function(get_left_softkey_function(KEY_EVENT_UP), KEY_EVENT_UP, MMI_CENTER_SOFTKEY);
            mmi_imc_key_setup_csk_function(get_left_softkey_function(KEY_EVENT_UP));
            break;
        }
#endif        
        case INLINE_ITEM_TYPE_TEXT_EDIT:
        case INLINE_ITEM_TYPE_FULL_SCREEN_EDIT:
        {
             set_softkey_icon(get_image(IMG_GLOBAL_COMMON_CSK), MMI_CENTER_SOFTKEY);
             register_softkey_handler(MMI_CENTER_SOFTKEY);
             set_softkey_function(wgui_inline_lsk_fs_cui_editor, KEY_EVENT_UP, MMI_CENTER_SOFTKEY);
            mmi_imc_key_setup_csk_function(wgui_inline_lsk_fs_cui_editor);  
             break;
        }
#if defined (__MMI_INLINE_ITEM_IMAGETEXT__)        
        case INLINE_ITEM_IMAGE_TEXT_TYPE:
        {
            set_softkey_icon(get_image(IMG_GLOBAL_COMMON_CSK), MMI_CENTER_SOFTKEY);
            register_softkey_handler(MMI_CENTER_SOFTKEY);
            set_softkey_function(wgui_inline_item_key_handler, KEY_EVENT_UP, MMI_CENTER_SOFTKEY);
            mmi_imc_key_setup_csk_function(wgui_inline_item_key_handler); 
            break;
        }
#endif        
        case INLINE_ITEM_TYPE_SELECT:
        {
            set_softkey_icon(get_image(IMG_GLOBAL_COMMON_CSK), MMI_CENTER_SOFTKEY);
            register_softkey_handler(MMI_CENTER_SOFTKEY);
            set_softkey_function(wgui_inline_lsk_menu_cui_select, KEY_EVENT_UP, MMI_CENTER_SOFTKEY);
            break;
        }
#if defined(__MMI_INLINE_ITEM_DOW__)         
        case INLINE_ITEM_TYPE_DOW_SELECT:
        {       
            set_softkey_icon(get_image(IMG_GLOBAL_COMMON_CSK), MMI_CENTER_SOFTKEY);
            register_softkey_handler(MMI_CENTER_SOFTKEY);
            set_softkey_function(handle_inline_DOW_select_LSK_up, KEY_EVENT_UP, MMI_CENTER_SOFTKEY);
            break;
        }
#endif        

    }
}

/*****************************************************************************
 * FUNCTION
 *  wgui_inline_reset_items_csk
 * DESCRIPTION
 *  reset csk
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inline_reset_items_csk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_softkey_handler(MMI_CENTER_SOFTKEY);
    set_softkey_label(NULL, MMI_CENTER_SOFTKEY);
    set_softkey_icon(NULL, MMI_CENTER_SOFTKEY);
}

/*****************************************************************************
 * FUNCTION
 *  wgui_inline_edit_default_list_unhighlight_handler
 * DESCRIPTION
 *  Default unhighlight handler used for inline editing menu
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_edit_default_list_unhighlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_inline_item_highlighted_index != item_index)
        return;
    
    /* Finalize current editing. */
    complete_inline_item_edit();
    
    /* W05.33 Fix inline text edit history issue */
    wgui_current_inline_item_type = 0;
#if defined (__MMI_INLINE_ITEM_MULTILINE_EDIT__)    
    if (item_index > 0 &&
        ((wgui_inline_items[item_index].flags & INLINE_ITEM_TYPE_MULTI_LINE_EDIT) == INLINE_ITEM_TYPE_MULTI_LINE_EDIT))
    {
        reset_multiline_inputbox_vertical_scroll();
    }
#endif    
    wgui_inline_reset_items_csk();


}

/*----------------------------------------------------------------------------
   Default highlight handler used for inline editing menu
----------------------------------------------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_edit_default_list_highlight_handler
 * DESCRIPTION
 *  Default highlight handler used for inline editing menu
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inline_edit_default_list_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 item_type = 0;
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_inline_item_highlighted_index == item_index)
        return;

    wgui_title_set_menu_shortcut_number(item_index + 1);
    MMI_highlighted_item_text = get_item_text(item_index);
    wgui_inline_item_handled = 0;
    wgui_inline_item_highlighted_index = item_index;
    if(cui_inline_is_current_cui())
    {
        g_cui_inline_current_instance->highlight_item = item_index; 
    }
    register_default_hide_softkeys();
    complete_inline_item_edit = UI_dummy_function;
    current_wgui_inline_item = &wgui_inline_items[item_index];
	g_inline_lsk_functions = NULL;

    if (wgui_inline_items[item_index].flags & INLINE_ITEM_DISABLED)
    {
        if ((wgui_inline_edit_arrow_key_flag == CATEGORY57_UP_ARROW_KEY_FLAG) && (wgui_inline_edit_is_able_to_switch_highlight(0)))
        {
            gui_fixed_list_menu_goto_previous_item(&MMI_fixed_list_menu);
        }
        else if ((wgui_inline_edit_arrow_key_flag == CATEGORY57_DOWN_ARROW_KEY_FLAG) && (wgui_inline_edit_is_able_to_switch_highlight(1)))
        {
            gui_fixed_list_menu_goto_next_item(&MMI_fixed_list_menu);
        }
        else if((wgui_inline_edit_arrow_key_flag == CATEGORY57_DOWN_ARROW_KEY_FLAG))
        {
            gui_fixed_list_menu_goto_previous_item(&MMI_fixed_list_menu);
        }
        else
        {
            gui_fixed_list_menu_goto_next_item(&MMI_fixed_list_menu);
        }
        return;
    }

    item_type = wgui_inline_items[item_index].flags & 0xff;
    if(item_type != INLINE_ITEM_TYPE_CAPTION)
    {
        if(item_index > 0)
        {
           if ((MMI_fixed_list_menu.first_displayed_item == item_index) &&
                ((wgui_inline_items[item_index - 1].flags & 0xFF) == INLINE_ITEM_TYPE_CAPTION))
            {
#if defined (__MMI_INLINE_ITEM_MULTILINE_READ_ONLY__)
                if((wgui_inline_items[item_index].flags & 0xFF) != INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY)
#endif                    
                {
                    MMI_fixed_list_menu.first_displayed_item = item_index - 1;
                    MMI_fixed_list_menu.highlighted_item = -1;
                    gui_fixed_list_menu_goto_item(&MMI_fixed_list_menu, item_index);
                }
            }
        }
    }
    else
    {
        if ((wgui_inline_edit_arrow_key_flag == CATEGORY57_UP_ARROW_KEY_FLAG) && (wgui_inline_edit_is_able_to_switch_highlight(0)))
        {
            gui_fixed_list_menu_goto_previous_item(&MMI_fixed_list_menu);
        }
        else if (wgui_inline_edit_arrow_key_flag == CATEGORY57_DOWN_ARROW_KEY_FLAG && (wgui_inline_edit_is_able_to_switch_highlight(1)))
        {
	        gui_fixed_list_menu_goto_next_item(&MMI_fixed_list_menu);
        }
        else if((wgui_inline_edit_arrow_key_flag == CATEGORY57_DOWN_ARROW_KEY_FLAG))
        {
            gui_fixed_list_menu_goto_previous_item(&MMI_fixed_list_menu);
        }
        else
        {
	        gui_fixed_list_menu_goto_next_item(&MMI_fixed_list_menu);
        }
        return;
    }
    
    /* Change the softkey functions and labels   */
#if defined(__MMI_TOUCH_SCREEN__)
    /* W06.05 Do not draw fixed list in category57 because of virtual keyboard */
    if (!mmi_pen_editor_is_closecategory57 && mmi_imc_get_inline_editor_full_height())
    {
        
    #if defined(__MMI_SCREEN_ROTATE__)
        if (mmi_frm_is_screen_width_height_swapped())
        {
#ifdef __MMI_ICON_BAR_SUPPORT__         
#ifdef __MMI_FTE_SUPPORT__ 
            if(wgui_icon_bar_is_created())
            {
                 resize_fixed_list(MMI_ROTATED_CONTENT_WIDTH, mmi_imc_get_inline_editor_full_height() - MMI_ICON_BAR_HEIGHT);
            }
            else
#endif                
#endif /*__MMI_ICON_BAR_SUPPORT__*/
            {
                resize_fixed_list(MMI_ROTATED_CONTENT_WIDTH, mmi_imc_get_inline_editor_full_height());
            }
        }    
        else
    #endif
        {
#ifdef __MMI_ICON_BAR_SUPPORT__         
#ifdef __MMI_FTE_SUPPORT__             
            if(wgui_icon_bar_is_created())
            {
                 resize_fixed_list(MMI_content_width, mmi_imc_get_inline_editor_full_height() - MMI_ICON_BAR_HEIGHT);
            }
            else
    #endif
#endif /*__MMI_ICON_BAR_SUPPORT__*/	
            {
                resize_fixed_list(MMI_content_width, mmi_imc_get_inline_editor_full_height());    
            }
        }
    }
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 

    mmi_imc_disconnect();

#if defined(__MMI_TOUCH_SCREEN__)
    wgui_register_list_tap_callback(wgui_inline_tap_callback_funtion);
#endif    
    
    switch (item_type)
    {
        case INLINE_ITEM_TYPE_CAPTION:
        {
            return;
        }

        case INLINE_ITEM_TYPE_DISPLAY_ONLY:
        {
            clear_left_softkey_handler();
            set_left_softkey_label(NULL);
            set_right_softkey_label(wgui_inline_edit_get_RSK_string());
            register_right_softkey_handler();
            set_right_softkey_function(execute_wgui_inline_edit_RSK_function, KEY_EVENT_UP);
        }
            break;
        case INLINE_ITEM_TYPE_TEXT_EDIT:
        {
            set_left_softkey_label(get_string(STR_GLOBAL_EDIT));
            register_left_softkey_handler();
            if (!cui_inline_is_current_cui())
            {
                set_softkey_function(wgui_inline_lsk_fs_cui_editor, KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
            }
            set_right_softkey_label(wgui_inline_edit_get_RSK_string());
            register_right_softkey_handler();
            set_right_softkey_function(execute_wgui_inline_edit_RSK_function, KEY_EVENT_UP);
            break;
        }
#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
#if defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__)                    
        case INLINE_ITEM_TYPE_MULTI_LINE_EDIT:
        {
        #if defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
            set_left_softkey_label((UI_string_type) get_string(STR_GLOBAL_OPTIONS));
        #else /* defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
            set_left_softkey_label(get_string(STR_GLOBAL_OK));
        #endif /* defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
            register_left_softkey_handler();
            if(cui_inline_is_current_cui())
            {
                set_left_softkey_function(cui_inline_lsk_function, KEY_EVENT_UP);
                mmi_imc_key_setup_lsk_function(cui_inline_lsk_function);
                set_softkey_function(cui_inline_lsk_function, KEY_EVENT_UP, MMI_CENTER_SOFTKEY);
            }
            else
            {
                set_left_softkey_function(execute_wgui_inline_edit_RSK_function, KEY_EVENT_UP);
                mmi_imc_key_setup_lsk_function(execute_wgui_inline_edit_RSK_function);
            }
            if (wgui_inline_list_menu_changed)
            {
                inline_text_edit_RSK_label_string = (UI_string_type) get_string(STR_GLOBAL_BACK);
            }
            else
            {
                inline_text_edit_RSK_label_string = wgui_inline_edit_get_RSK_string();
            }
            set_right_softkey_label(inline_text_edit_RSK_label_string);

            {
                multiline_inputbox_category_history *h = (multiline_inputbox_category_history*) wgui_current_history_buffer;
                wgui_inline_item_text_edit *i = (wgui_inline_item_text_edit*) wgui_inline_items[item_index].item;

                if (wgui_current_history_buffer && history_valid(h->history_ID, INLINE_MULTI_LINE_EDIT_HISTORY_ID))
                {
                    mmi_imc_set_input_method_history(&(h->ime_history));
                }

                mmi_imm_set_required_mode_list(i->input_type & INPUT_TYPE_MASK, NULL, IMM_INPUT_MODE_NONE);
                g_mmi_editor_hanler.input_box_type = MMI_EDITOR_INLINE_INPUT_BOX;
                g_mmi_editor_hanler.input_box_sub_type = MMI_EDITOR_INLINE_MULTILINE_INPUT_BOX;
                g_mmi_editor_hanler.input_box_handler = &MMI_multiline_inputbox;
                mmi_imc_editor_is_not_ready_when_connecting();
                mmi_imc_connect((void *)&g_mmi_editor_hanler, mmi_input_box_msg_call_back_inline);
            }
            break;
        }    
#endif
#endif            

        case INLINE_ITEM_TYPE_FULL_SCREEN_EDIT:
        {
            set_left_softkey_label(get_string(STR_GLOBAL_EDIT));
            register_left_softkey_handler();
            if (!cui_inline_is_current_cui())
            {
                set_softkey_function(wgui_inline_lsk_fs_cui_editor, KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
            }
            set_right_softkey_label(wgui_inline_edit_get_RSK_string());
            register_right_softkey_handler();
            set_right_softkey_function(execute_wgui_inline_edit_RSK_function, KEY_EVENT_UP);
            
        #if defined(__MMI_TOUCH_SCREEN__)
            /* W06.08 Reset wgui_current_history_buffer if !INLINE_ITEM_OPEN to avoid incorrect use */
            if (!(wgui_inline_items[item_index].flags & INLINE_ITEM_OPEN))
            {
                wgui_current_history_buffer = NULL;
            }
        #endif /* defined(__MMI_TOUCH_SCREEN__) */ 
        }
            break;
#if defined (__MMI_INLINE_ITEM_IMAGETEXT__)
        case INLINE_ITEM_IMAGE_TEXT_TYPE:
        {
            set_left_softkey_label(get_string(STR_GLOBAL_EDIT));
            register_left_softkey_handler();
            set_right_softkey_label(wgui_inline_edit_get_RSK_string());
            register_right_softkey_handler();
            set_right_softkey_function(execute_wgui_inline_edit_RSK_function, KEY_EVENT_UP);
        }
            break;
#endif   
#if defined (__MMI_INLINE_ITEM_MULTILINE_READ_ONLY__)
        case INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY:
        {
            set_right_softkey_label(wgui_inline_edit_get_RSK_string());
            register_right_softkey_handler();
            set_right_softkey_function(execute_wgui_inline_edit_RSK_function, KEY_EVENT_UP);
        }
            break;
#endif            
        case INLINE_ITEM_TYPE_SELECT:
        {
            clear_left_softkey_handler();
            set_left_softkey_label(NULL);
            if (!cui_inline_is_current_cui())
            {
                set_softkey_function(wgui_inline_lsk_menu_cui_select, KEY_EVENT_UP, MMI_CENTER_SOFTKEY);
            }
            set_right_softkey_label(wgui_inline_edit_get_RSK_string());
            register_right_softkey_handler();
            set_right_softkey_function(execute_wgui_inline_edit_RSK_function, KEY_EVENT_UP);
        }
            break;
#if defined(__MMI_INLINE_ITEM_DATE__)            
        case INLINE_ITEM_TYPE_DATE:
        {            
            set_left_softkey_label(NULL);
            register_left_softkey_handler();
            set_right_softkey_label(wgui_inline_edit_get_RSK_string());
            register_right_softkey_handler();
            set_right_softkey_function(execute_wgui_inline_edit_RSK_function, KEY_EVENT_UP);
            
            {
                inline_date_edit_history *h = (inline_date_edit_history*) wgui_current_history_buffer;
                if (wgui_current_history_buffer && history_valid(h->history_ID, INLINE_DATE_HISTORY_ID))
                {
                    mmi_imc_set_input_method_history(&(h->ime_history));
                }
            }
            
            mmi_imm_set_required_mode_list(IMM_INPUT_TYPE_NUMERIC, NULL, IMM_INPUT_MODE_NONE);
            g_mmi_editor_hanler.input_box_type = MMI_EDITOR_INLINE_INPUT_BOX;
            g_mmi_editor_hanler.input_box_sub_type = MMI_EDITOR_DATE;
            g_mmi_editor_hanler.input_box_handler = &wgui_inline_date_input;
            mmi_imc_connect((void *)&g_mmi_editor_hanler, mmi_input_box_msg_call_back_inline);
        }
            break;
#endif   
#if defined(__MMI_INLINE_ITEM_TIME__)
        case INLINE_ITEM_TYPE_TIME:
        {
            set_left_softkey_label(NULL);
            register_left_softkey_handler();
            set_right_softkey_label(wgui_inline_edit_get_RSK_string());
            register_right_softkey_handler();
            set_right_softkey_function(execute_wgui_inline_edit_RSK_function, KEY_EVENT_UP);
            
            {
                inline_time_edit_history *h = (inline_time_edit_history*) wgui_current_history_buffer;
                if (wgui_current_history_buffer && history_valid(h->history_ID, INLINE_TIME_HISTORY_ID))
                {
                    mmi_imc_set_input_method_history(&(h->ime_history));
                }  
            }
            
            mmi_imm_set_required_mode_list(IMM_INPUT_TYPE_NUMERIC, NULL, IMM_INPUT_MODE_NONE);
            g_mmi_editor_hanler.input_box_type = MMI_EDITOR_INLINE_INPUT_BOX;
            g_mmi_editor_hanler.input_box_sub_type = MMI_EDITOR_TIME;
            g_mmi_editor_hanler.input_box_handler = &wgui_inline_time_input;
            mmi_imc_connect((void *)&g_mmi_editor_hanler, mmi_input_box_msg_call_back_inline);
        }
            break;
#endif            
#if defined (__MMI_INLINE_ITEM_TIME_PEROID__)               
        case INLINE_ITEM_TYPE_TIME_PERIOD:
        {
            set_left_softkey_label(NULL);
            register_left_softkey_handler();
            set_right_softkey_label(wgui_inline_edit_get_RSK_string());
            register_right_softkey_handler();
            set_right_softkey_function(execute_wgui_inline_edit_RSK_function, KEY_EVENT_UP);
            
            {
                inline_time_period_edit_history *h = (inline_time_period_edit_history*) wgui_current_history_buffer;
                if (wgui_current_history_buffer && history_valid(h->history_ID, INLINE_TIME_PERIOD_HISTORY_ID))
                {
                    mmi_imc_set_input_method_history(&(h->ime_history));
                }   
            }
            
            mmi_imm_set_required_mode_list(IMM_INPUT_TYPE_NUMERIC, NULL, IMM_INPUT_MODE_NONE);
            g_mmi_editor_hanler.input_box_type = MMI_EDITOR_INLINE_INPUT_BOX;
            g_mmi_editor_hanler.input_box_sub_type = MMI_EDITOR_TIME_PERIOD;
            g_mmi_editor_hanler.input_box_handler = &wgui_inline_time_period_input;
            mmi_imc_connect((void *)&g_mmi_editor_hanler, mmi_input_box_msg_call_back_inline);
        }
            break;
#endif   
#if defined (__MMI_INLINE_ITEM_DOW__)
        case INLINE_ITEM_TYPE_DOW_SELECT:
        {
        }
            break;
#endif   
#ifdef __MMI_INLINE_ITEM_IP4__
        case INLINE_ITEM_TYPE_IP4_EDIT:
        {
            set_left_softkey_label(NULL);
            register_left_softkey_handler();
            set_right_softkey_label(wgui_inline_edit_get_RSK_string());
            register_right_softkey_handler();
            set_right_softkey_function(execute_wgui_inline_edit_RSK_function, KEY_EVENT_UP);
            
            {
                inline_IP4_edit_history *h = (inline_IP4_edit_history*) wgui_current_history_buffer;
                if (wgui_current_history_buffer && history_valid(h->history_ID, INLINE_IP4_HISTORY_ID))
                {
                    mmi_imc_set_input_method_history(&(h->ime_history));
                } 
            }
    
            mmi_imm_set_required_mode_list(IMM_INPUT_TYPE_NUMERIC, NULL, IMM_INPUT_MODE_NONE);
            g_mmi_editor_hanler.input_box_type = MMI_EDITOR_INLINE_INPUT_BOX;
            g_mmi_editor_hanler.input_box_sub_type = MMI_EDITOR_IP4;
            g_mmi_editor_hanler.input_box_handler = &wgui_inline_IP4_input;
            mmi_imc_connect((void *)&g_mmi_editor_hanler, mmi_input_box_msg_call_back_inline);
        }
            break;
#endif   
#if defined (__MMI_INLINE_ITEM_COLOR_SELECT__)
        case INLINE_ITEM_TYPE_COLOR_SELECT:
        {            
            clear_left_softkey_handler();
            set_left_softkey_label(NULL);
            set_right_softkey_label(wgui_inline_edit_get_RSK_string());
            register_right_softkey_handler();
            set_right_softkey_function(execute_wgui_inline_edit_RSK_function, KEY_EVENT_UP);

        }
            break;
#endif   
#if  defined(__MMI_INLINE_ITEM_PROGRESS_BAR__)
        case INLINE_ITEM_TYPE_PROGRESS_BAR:
        {            
            clear_left_softkey_handler();
            set_left_softkey_label(NULL);
            set_right_softkey_label(wgui_inline_edit_get_RSK_string());
            register_right_softkey_handler();
            set_right_softkey_function(execute_wgui_inline_edit_RSK_function, KEY_EVENT_UP);            
            break;  
        }
#endif        
    }

#ifdef __MMI_INLINE_HIGHLIGHT_CAPTION__
    //if current highlight item has caption, get the caption index
    if((item_index>0) && ( (wgui_inline_items[item_index-1].flags & 0xff) == INLINE_ITEM_TYPE_CAPTION))
	{
		wgui_inline_should_hl_caption_index = item_index-1;
	}
	else
	{
        wgui_inline_should_hl_caption_index = -1;
	}
#endif 

    if(cui_inline_is_current_cui())
    {
        cui_inline_set_item_default_softkey_attribute(item_index);
#if defined (__MMI_INLINE_ITEM_DOW__) || defined (__MMI_INLINE_ITEM_IMAGETEXT__)        
        if((item_type != INLINE_ITEM_TYPE_DOW_SELECT) &&
           (item_type != INLINE_ITEM_IMAGE_TEXT_TYPE)
          )
#endif          
        {
            register_left_softkey_handler();
            set_left_softkey_function(cui_inline_lsk_function, KEY_EVENT_UP);
            mmi_imc_key_setup_lsk_function(cui_inline_lsk_function);
        }
    }
    else
    {
        wgui_inline_set_items_csk(item_type);
    }

#if defined (__MMI_INLINE_ITEM_MULTILINE_EDIT__) || defined (__MMI_INLINE_ITEM_MULTILINE_READ_ONLY__)
    /* Add this code for the project which is no touch screen. */
  if((wgui_inline_items[wgui_n_inline_items - 1].flags & 0xff) == INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY)
    {
        wgui_inline_item_text_edit *i = (wgui_inline_item_text_edit*)wgui_inline_items[wgui_n_inline_items - 1].item;
        
       // if(i->height_of_item > 4)
     //   {
            /*we limit the height of multilinerdonly so that it can be shown total in screen.*/
            i->height_of_item = MMI_fixed_list_menu.height / MMI_fixed_icontext_menuitem.height;    
     //   } 
    }    
    if((wgui_inline_items[wgui_n_inline_items - 1].flags & 0xff) == INLINE_ITEM_TYPE_MULTI_LINE_EDIT)
    {
        wgui_inline_item_text_edit *i = (wgui_inline_item_text_edit*)wgui_inline_items[wgui_n_inline_items - 1].item;
        if(i->max_lines >=  3)
        {
            /*we limit the height of multilinerdonly so that it can be shown total in screen.*/
            i->height_of_item = MMI_fixed_list_menu.height / MMI_fixed_icontext_menuitem.height;    
        } 
    }
#endif
    
#if defined(__MMI_TOUCH_SCREEN__)
    /* W06.05 Do not draw fixed list in category57 because of virtual keyboard */
    if (!mmi_pen_editor_is_closecategory57)
    {
#if defined(__MMI_VIRTUAL_KEYBOARD__)
    #ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__
        if ((GUI_VIRTUAL_KEYBOARD_EMPTY_TRAY != MMI_virtual_keyboard.lang_type)
            && mmi_imc_is_connected() && (mmi_imc_get_current_imui_height() > 0 )
            && (!((current_wgui_inline_item->flags & INLINE_ITEM_TYPE_MASK) == INLINE_ITEM_TYPE_FULL_SCREEN_EDIT)))
    #else
        if ((GUI_VIRTUAL_KEYBOARD_EMPTY_TRAY != g_wgui_virtual_keyboard_lang_type)
            && mmi_imc_is_connected() && (mmi_imc_get_current_imui_height() > 0 )
            && (!((current_wgui_inline_item->flags & INLINE_ITEM_TYPE_MASK) == INLINE_ITEM_TYPE_FULL_SCREEN_EDIT)))
    #endif 
#endif
       {
#ifdef __MMI_FTE_SUPPORT__             
            resize_fixed_list(MMI_fixed_list_menu.width, UI_device_height - MMI_fixed_list_menu.y - mmi_imc_get_current_imui_height());
       #else
                resize_fixed_list(MMI_fixed_list_menu.width, mmi_imc_get_inline_editor_full_height() - mmi_imc_get_current_imui_height());
       #endif
       }
#if defined (__MMI_INLINE_ITEM_MULTILINE_EDIT__) || defined (__MMI_INLINE_ITEM_MULTILINE_READ_ONLY__)
         if((wgui_inline_items[wgui_n_inline_items - 1].flags & 0xff) == INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY)
    {
        wgui_inline_item_text_edit *i = (wgui_inline_item_text_edit*)wgui_inline_items[wgui_n_inline_items - 1].item;
        
      //  if(i->height_of_item > 4)
      //  {
            /*we limit the height of multilinerdonly so that it can be shown total in screen.*/
            i->height_of_item = MMI_fixed_list_menu.height / MMI_fixed_icontext_menuitem.height;    
      //  } 
    }    
    if((wgui_inline_items[wgui_n_inline_items - 1].flags & 0xff) == INLINE_ITEM_TYPE_MULTI_LINE_EDIT)
    {
        wgui_inline_item_text_edit *i = (wgui_inline_item_text_edit*)wgui_inline_items[wgui_n_inline_items - 1].item;
        if(i->max_lines >  4)
        {
            /*we limit the height of multilinerdonly so that it can be shown total in screen.*/
            i->height_of_item = MMI_fixed_list_menu.height / MMI_fixed_icontext_menuitem.height;    
        } 
    }
#endif
        gui_fixed_list_menu_locate_highlighted_item(&MMI_fixed_list_menu);
    }
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 
    gdi_layer_lock_frame_buffer();
	MMI_user_highlight_handler_Ext((U8)eListhighlight, item_index);
#if defined(__MMI_TOUCH_SCREEN__)
    redraw_softkey(MMI_CENTER_SOFTKEY);
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 
#ifdef __MMI_ICON_BAR_SUPPORT__     
#if defined(__MMI_FTE_SUPPORT__)
    if(MMI_TRUE == wgui_icon_bar_is_created())
    {
        wgui_icon_bar_move(0, UI_device_height - MMI_softkey_height - MMI_ICON_BAR_HEIGHT);
        wgui_icon_bar_resize(UI_device_width, MMI_ICON_BAR_HEIGHT);
        wgui_icon_bar_show();
    }
#endif
#endif /*__MMI_ICON_BAR_SUPPORT__*/
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, UI_device_height - MMI_button_bar_height, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  category_inline_edit_menuitem_flags
 * DESCRIPTION
 *  set flags as ~UI_MENUITEM_INLINE_EDIT_OBJECT
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void category_inline_edit_menuitem_flags(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_INLINE_ITEMS; i++)
    {
        MMI_fixed_icontext_menuitems[i].flags &= ~UI_MENUITEM_INLINE_EDIT_OBJECT;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_show_inline_edit_menuitem
 * DESCRIPTION
 *  show inline edit menuitem
 * PARAMETERS
 *  x                  [IN]    left-top corner x coordinate    
 *  y                  [IN]    left-top corner y coordinate    
 *  width              [IN]    width    
 *  height             [IN]    height                 
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_show_inline_edit_menuitem(S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((MMI_fixed_list_menu.current_displayed_item < 0) ||
        (MMI_fixed_list_menu.current_displayed_item > (MMI_fixed_list_menu.n_items - 1)))
    {
        return;
    }

#ifdef __MMI_FTE_SUPPORT__
    width = width - INLINE_FTE_SCROLL_BAR_WIDTH ;
    if((wgui_inline_items[MMI_fixed_list_menu.current_displayed_item].flags & 0xff) != INLINE_ITEM_TYPE_CAPTION)
    {
        if(((wgui_inline_items[MMI_fixed_list_menu.current_displayed_item].flags & 0xff) != INLINE_ITEM_TYPE_MULTI_LINE_EDIT) &&
           ((wgui_inline_items[MMI_fixed_list_menu.current_displayed_item].flags & 0xff) != INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY) 
          )
        {
            y = y + INLINE_FTE_CONTROL_VERTICAL_GAP(height);
            height = INLINE_FTE_CONTROL_HEIGHT;
        }
        else
        {
            y = y + INLINE_FTE_CONTROL_VERTICAL_GAP(INLINE_FTE_ONE_LINE_HEIGHT);
            height -= 2 * INLINE_FTE_CONTROL_VERTICAL_GAP(INLINE_FTE_ONE_LINE_HEIGHT);
        }
    }
    if(wgui_inline_items[MMI_fixed_list_menu.current_displayed_item].side_img !=NULL)
    {
        if(mmi_fe_get_r2l_state())
        {
            x += INLINE_FTE_SCROLL_BAR_WIDTH;
            width = width -  (INLINE_FTE_ICON_SIZE + INLINE_FTE_ICON_CONTROL_GAP + INLINE_FTE_LEFT_GAP);
        }
        else
        {
            x += INLINE_FTE_ICON_SIZE + INLINE_FTE_ICON_CONTROL_GAP + INLINE_FTE_LEFT_GAP; 
            width -= x + 1;
        }

    }
    else
    {
        if(mmi_fe_get_r2l_state())
        {
            x += INLINE_FTE_SCROLL_BAR_WIDTH;
            width = width -  (INLINE_FTE_ICON_CONTROL_GAP + INLINE_FTE_LEFT_GAP);
        }
        else
        {
            x += INLINE_FTE_ICON_CONTROL_GAP + INLINE_FTE_LEFT_GAP;
            width -= x + 1;
        }         
    }
  //  height = INLINE_FTE_ONE_LINE_HEIGHT;
#endif
    
    switch (wgui_inline_items[MMI_fixed_list_menu.current_displayed_item].flags & 0xff)
    {
#if defined(__MMI_INLINE_ITEM_DOW__)    
        case INLINE_ITEM_TYPE_DOW_SELECT:              
            wgui_show_DOW_list_menuitem(
                x,
                y,
                width,
                height,
                &wgui_inline_items[MMI_fixed_list_menu.current_displayed_item]);
            break;
#endif            
        case INLINE_ITEM_TYPE_TEXT_EDIT:
            wgui_show_inline_text_edit_list_menuitem(
                x,
                y,
                width,
                height,
                &wgui_inline_items[MMI_fixed_list_menu.current_displayed_item]);
            break;
        case INLINE_ITEM_TYPE_DATE:
#if defined(__MMI_INLINE_ITEM_DATE__)            
            wgui_show_inline_date_list_menuitem(
                x,
                y,
                width,
                height,
                &wgui_inline_items[MMI_fixed_list_menu.current_displayed_item]);
#endif
            break;
        case INLINE_ITEM_TYPE_TIME:
#if defined(__MMI_INLINE_ITEM_TIME__)            
            wgui_show_inline_time_list_menuitem(
                x,
                y,
                width,
                height,
                &wgui_inline_items[MMI_fixed_list_menu.current_displayed_item]);
#endif
            break;
#if defined (__MMI_INLINE_ITEM_TIME_PEROID__)             
        case INLINE_ITEM_TYPE_TIME_PERIOD:
            wgui_show_inline_time_period_list_menuitem(
                x,
                y,
                width,
                height,
                &wgui_inline_items[MMI_fixed_list_menu.current_displayed_item]);
            break;
#endif            
        case INLINE_ITEM_TYPE_IP4_EDIT:
#ifdef __MMI_INLINE_ITEM_IP4__            
            wgui_show_inline_IP4_list_menuitem(
                x,
                y,
                width,
                height,
                &wgui_inline_items[MMI_fixed_list_menu.current_displayed_item]);
#endif            
            break;
#if defined (__MMI_INLINE_ITEM_IMAGETEXT__)
        case INLINE_ITEM_IMAGE_TEXT_TYPE:
            wgui_show_image_text_item(
                x,
                y,
                width,
                height,
                &wgui_inline_items[MMI_fixed_list_menu.current_displayed_item]);
            break;
#endif        
        case INLINE_ITEM_TYPE_SELECT:
            wgui_show_inline_select_arrow(
                x,
                y,
                width,
                height,
                &wgui_inline_items[MMI_fixed_list_menu.current_displayed_item]);
            break;
    #if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
    #if defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__)
        case INLINE_ITEM_TYPE_MULTI_LINE_EDIT:
            wgui_show_inline_inscreen_multi_line_edit(
                x,
                y,
                width,
                height,
                &wgui_inline_items[MMI_fixed_list_menu.current_displayed_item]);
            break;
        case INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY:
            wgui_show_inline_multi_line_rd_only(
                x,
                y,
                width,
                height,
                &wgui_inline_items[MMI_fixed_list_menu.current_displayed_item]);
            break;
    #endif        
    #endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */
#if defined (__MMI_INLINE_ITEM_COLOR_SELECT__)    
        case INLINE_ITEM_TYPE_COLOR_SELECT:            
            wgui_show_highlighted_inline_color_select_menuitemitem(
                x,
                y,
                width,
                height,
                &wgui_inline_items [MMI_fixed_list_menu.current_displayed_item]);
            break;
#endif            
        case INLINE_ITEM_TYPE_DISPLAY_ONLY:
        case INLINE_ITEM_TYPE_FULL_SCREEN_EDIT:
#ifdef __MMI_FTE_SUPPORT__
            wgui_show_inline_fte_displayonly_item_unhighlight(
                x,
                y,
                width,
                height,
                &wgui_inline_items[MMI_fixed_list_menu.current_displayed_item]);
            break;
        case INLINE_ITEM_TYPE_CAPTION:
            wgui_show_inline_fte_caption_item(
                x,
                y,
                width,
                height,
                &wgui_inline_items[MMI_fixed_list_menu.current_displayed_item]);
            break;
#else
            wgui_show_inline_displayonly_item(
                x,
                y,
                width,
                height,
                &wgui_inline_items[MMI_fixed_list_menu.current_displayed_item]);
            break;
#ifdef __MMI_INLINE_HIGHLIGHT_CAPTION__
        case INLINE_ITEM_TYPE_CAPTION:
            wgui_show_inline_caption_item(
                x,
                y,
                width,
                height,
                &wgui_inline_items[MMI_fixed_list_menu.current_displayed_item]);
#endif
#endif
#if  defined(__MMI_INLINE_ITEM_PROGRESS_BAR__)
        case INLINE_ITEM_TYPE_PROGRESS_BAR:            
            wgui_show_inline_progress_bar_list_menuitem(
                x,
                y,
                width,
                height,
                &wgui_inline_items[MMI_fixed_list_menu.current_displayed_item]);
            break;
#endif

    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_setup_inline_edit_themes
 * DESCRIPTION
 *  setup inline edit themes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_setup_inline_edit_themes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_set_date_time_input_focussed_theme();
    
#if  defined(__MMI_INLINE_ITEM_PROGRESS_BAR__)    
    wgui_inline_set_unfocussed_progress_bar_theme();
    wgui_inline_set_focussed_progress_bar_theme();
#endif    

    temp_inline_edit_background_filler = date_time_input_background_filler;
    temp_inline_edit_background_filler3 = date_time_input_background_filler;
    temp_inline_edit_background_filler3.flags &= 0x00000fff;
    wgui_inline_select_fixed_text_menuitem_theme.normal_filler =
        wgui_inline_fixed_icontext_menuitem_theme.normal_filler;
    wgui_inline_select_fixed_text_menuitem_theme.disabled_filler =
        wgui_inline_fixed_icontext_menuitem_theme.disabled_filler;
    wgui_inline_select_fixed_text_menuitem_theme.selected_filler =
        wgui_inline_fixed_icontext_menuitem_theme.selected_filler;
    wgui_inline_select_fixed_text_menuitem_theme.focussed_filler =
        wgui_inline_fixed_icontext_menuitem_theme.focussed_filler;
    wgui_inline_select_fixed_text_menuitem_theme.focussed_without_sc_filler =
        wgui_inline_fixed_icontext_menuitem_theme.focussed_without_sc_filler;
    wgui_inline_select_fixed_text_menuitem_theme.normal_text_color =
        wgui_inline_fixed_icontext_menuitem_theme.normal_text_color;
    wgui_inline_select_fixed_text_menuitem_theme.disabled_text_color =
        wgui_inline_fixed_icontext_menuitem_theme.disabled_text_color;
    wgui_inline_select_fixed_text_menuitem_theme.selected_text_color =
        wgui_inline_fixed_icontext_menuitem_theme.selected_text_color;
    wgui_inline_select_fixed_text_menuitem_theme.focussed_text_color =
        wgui_inline_fixed_icontext_menuitem_theme.focussed_text_color;
#ifdef __MMI_FTE_SUPPORT__    
    /* For highlight selector text color */
    wgui_inline_select_fixed_text_menuitem_theme.focussed_text_color =
     wgui_inline_singleline_inputbox_focussed_theme.normal_text_color;
    /* For unhighlight selector text color */
    wgui_inline_select_fixed_text_menuitem_theme.normal_text_color = 
       wgui_inline_singleline_inputbox_focussed_theme.normal_text_color; 
    wgui_inline_select_fixed_text_menuitem_theme.selected_filler = 
        current_MMI_theme->inline_list_selected_item_filler;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  RegisterInlineItemChangedNotification
 * DESCRIPTION
 *  Register inline item changed notification callback
 * PARAMETERS
 *  callback        [IN]        Callback function to application
 * RETURNS
 *  void
 *****************************************************************************/
void RegisterInlineItemChangedNotification(void (*callback) (U16 index))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inline_item_changed_handler = callback;
}


/*****************************************************************************
 * FUNCTION
 *  ResetInlineItemChangedNotification
 * DESCRIPTION
 *  Reset inline item changed notification callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResetInlineItemChangedNotification(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inline_item_changed_handler = NULL;
}


/*****************************************************************************
* FUNCTION
*  wgui_inline_malloc
* DESCRIPTION
*  allocate memory from inline editor ADM
* PARAMETERS
*  size      [IN]          wanted size
* RETURNS
*  memory pointer
*****************************************************************************/
static void *wgui_inline_malloc(U16 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(inline_adm_id);
    MMI_DBG_ASSERT(size > 0);
    
    ptr = kal_adm_alloc(inline_adm_id, size);
    
    if (ptr == NULL)
    {
        /* run out of memory: ADM problem or buffer too small ?? */
        kal_uint32 left_size;

        left_size = kal_adm_get_total_left_size(inline_adm_id);

    #ifndef __MTK_TARGET__
        kal_printf("ADM: buffer not enough, left size:%d\n", left_size);
    #endif 
        MMI_DBG_ASSERT(0);/* Inline editor ADM buffer is not enough */


        if (left_size >= size)
        {
            kal_adm_print_log(inline_adm_id);    /* fragmentation */
            MMI_DBG_ASSERT(0);
        }
    }

    return ptr;

}


/*****************************************************************************
* FUNCTION
*  wgui_inline_alloc_mem
* DESCRIPTION
*  allocate memory for inline editor
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void wgui_inline_alloc_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_inine_items_buffer = (U8*) mmi_frm_scrmem_alloc(WGUI_INLINE_EDITOR_SCR_MEM_SIZE);

    MMI_ASSERT(g_wgui_inine_items_buffer);

    memset(g_wgui_inine_items_buffer, 0, WGUI_INLINE_EDITOR_SCR_MEM_SIZE);
    
    inline_adm_id = NULL;
    inline_adm_id = kal_adm_create(
                        g_wgui_inine_items_buffer,
                        WGUI_INLINE_EDITOR_SCR_MEM_SIZE,
                        NULL,
                        KAL_FALSE);

    if (inline_adm_id == NULL)
    {
        /* ADM creation : Fail */
        MMI_DBG_ASSERT(0);
    }

    wgui_inline_full_screen_text_edit_buffer = wgui_inline_malloc(MAX_INLINE_FULL_SCREEN_TEXT_EDIT_BUFFER_SIZE * sizeof(U8));
}


/*****************************************************************************
* FUNCTION
*  decuma_mfree
* DESCRIPTION
*  free memory for inline editor ADM
* PARAMETERS
*  ptr      [IN]          address of free-space
* RETURNS
*  void
*****************************************************************************/
static void wgui_inline_mfree(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(ptr != NULL);
    MMI_DBG_ASSERT(inline_adm_id);
    kal_adm_free(inline_adm_id, ptr);
}

/*****************************************************************************
* FUNCTION
*  wgui_inline_items_free_mem
* DESCRIPTION
*  free inline items' ADM memory 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void wgui_inline_items_free_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i=0; i< wgui_inline_mem_alloc_number; i++)
    {
        wgui_inline_mfree(wgui_inline_mem_alloc_info[i]);
    }
}


/*****************************************************************************
* FUNCTION
*  wgui_inline_free_mem
* DESCRIPTION
*  free inline editor's memory
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void wgui_inline_free_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(inline_adm_id);
    
    wgui_inline_items_free_mem();

    wgui_inline_mfree(wgui_inline_full_screen_text_edit_buffer);
    
    ret = kal_adm_delete(inline_adm_id);

    MMI_DBG_ASSERT(ret == KAL_SUCCESS);

    inline_adm_id = NULL;


    if (g_wgui_inine_items_buffer)
    {
        mmi_frm_scrmem_free((void*)g_wgui_inine_items_buffer);
    }

    UI_UNUSED_PARAMETER(ret);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_input_box_msg_call_back
 * DESCRIPTION
 *
 * PARAMETERS     
 *
 * RETURNS
 *  U32
 *****************************************************************************/
static U32 mmi_input_box_msg_call_back_inline(void * input_box_handle, mmi_imc_message_struct_p msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 lresult = 0;
#ifdef __MMI_FTE_SUPPORT__    
    static U8 pen_down = 0;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_inline_current_inline_item_type = ((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type;

    g_inline_current_input_box_handler = ((mmi_editor_handler_struct *)input_box_handle)->input_box_handler;

    g_inline_current_editor_handle = input_box_handle;

    switch (msg_ptr->message_id)
    {    
    case MMI_IMC_MESSAGE_GET_INPUT_BOX_RECT:
        ((mmi_imc_rect_p)msg_ptr->param_0)->x = MMI_fixed_list_menu.x;
        ((mmi_imc_rect_p)msg_ptr->param_0)->y = MMI_fixed_list_menu.y;
        ((mmi_imc_rect_p)msg_ptr->param_0)->width = MMI_fixed_list_menu.width;
        ((mmi_imc_rect_p)msg_ptr->param_0)->height = MMI_fixed_list_menu.height;
        break;
       
    case MMI_IMC_MESSAGE_RESIZE:
        
        if ((S32)msg_ptr->param_0 == MMI_fixed_list_menu.width &&
            (S32)msg_ptr->param_1 == MMI_fixed_list_menu.height)
        {
            break;
        }
        
        resize_fixed_list((S32)msg_ptr->param_0, (S32)msg_ptr->param_1);
        wgui_inline_item_handled = 0;
#if defined (__MMI_INLINE_ITEM_MULTILINE_EDIT__) || defined (__MMI_INLINE_ITEM_MULTILINE_READ_ONLY__)
        if((wgui_inline_items[wgui_n_inline_items - 1].flags & 0xff) == INLINE_ITEM_TYPE_MULTI_LINE_EDIT)
        {
            wgui_inline_item_text_edit *i = (wgui_inline_item_text_edit*)wgui_inline_items[wgui_n_inline_items - 1].item;
            if(i->max_lines > 4)
            {
                /*we limit the height of multilinerdonly so that it can be shown total in screen.*/
                i->height_of_item = MMI_fixed_list_menu.height / MMI_fixed_icontext_menuitem.height;    
            } 
        }
        if((wgui_inline_items[wgui_n_inline_items - 1].flags & 0xff) == INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY)
        {
            wgui_inline_item_text_edit *i = (wgui_inline_item_text_edit*)wgui_inline_items[wgui_n_inline_items - 1].item;
            
            /*we limit the height of multilinerdonly so that it can be shown total in screen.*/
            i->height_of_item = MMI_fixed_list_menu.height / MMI_fixed_icontext_menuitem.height;    
 
        }   
#endif        

        gui_fixed_list_menu_locate_highlighted_item(&MMI_fixed_list_menu);


       

        switch (current_wgui_inline_item->flags & INLINE_ITEM_TYPE_MASK)
        {            
        case INLINE_ITEM_TYPE_TIME:
 #if defined(__MMI_INLINE_ITEM_TIME__)            
            current_wgui_inline_time_item->string_construct_callback(
                *current_wgui_inline_time_text_p,
                current_wgui_inline_time_item->hours_buffer,
                current_wgui_inline_time_item->minutes_buffer,
                current_wgui_inline_time_item->AM_PM_flag);
#endif            
            break;
        
        case INLINE_ITEM_TYPE_DATE:
#if defined(__MMI_INLINE_ITEM_DATE__)            
            current_wgui_inline_date_item->string_construct_callback(
                *current_wgui_inline_date_text_p,
                current_wgui_inline_date_item->day_buffer,
                current_wgui_inline_date_item->month_buffer,
                current_wgui_inline_date_item->year_buffer);
#endif
            break;
#if defined (__MMI_INLINE_ITEM_TIME_PEROID__)               
        case INLINE_ITEM_TYPE_TIME_PERIOD:
            
            current_wgui_inline_time_period_item->string_construct_callback(
                *current_wgui_inline_time_period_text_p,
                current_wgui_inline_time_period_item->hours_buffer1,
                current_wgui_inline_time_period_item-> minutes_buffer1,
                current_wgui_inline_time_period_item->AM_PM_flag1,
                current_wgui_inline_time_period_item->hours_buffer2,
                current_wgui_inline_time_period_item-> minutes_buffer2,
                current_wgui_inline_time_period_item->AM_PM_flag2);

            break;
#endif
        case INLINE_ITEM_TYPE_IP4_EDIT:
#ifdef __MMI_INLINE_ITEM_IP4__	                    
            current_wgui_inline_IP4_item->string_construct_callback(
                *current_wgui_inline_IP4_text_p,
                current_wgui_inline_IP4_item->b1,
                current_wgui_inline_IP4_item->b2,
                current_wgui_inline_IP4_item->b3,
                current_wgui_inline_IP4_item->b4);
#endif
            break;

        default:
            break;
        }

        break;
/*    
    case MMI_IMC_MESSAGE_UPDATE_SOFTKEY:
        break;
    case MMI_IMC_MESSAGE_KEY_EVENT:
        break;
    case MMI_IMC_MESSAGE_MODE_CHANGED:
        break;
*/
#if defined(__MMI_TOUCH_SCREEN__)

    case MMI_IMC_MESSAGE_GET_HANDWRITING_RECT:

    #if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
    #if defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__)
        if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_INLINE_MULTILINE_INPUT_BOX)
        {
            return mmi_input_box_msg_call_back_multiline(input_box_handle, msg_ptr);
        }
        else
    #endif
    #endif /* __MMI_INSCREEN_MULTILINE_TEXTBOX__ */ 
        {
            if (mmi_fe_get_r2l_state())
            {
                ((mmi_imc_rect_p)msg_ptr->param_0)->x = MMI_content_x + MMI_fixed_list_menu.vbar.width;
                ((mmi_imc_rect_p)msg_ptr->param_0)->width = MMI_content_width;
            }
            else
            {
                ((mmi_imc_rect_p)msg_ptr->param_0)->x = MMI_content_x;
                ((mmi_imc_rect_p)msg_ptr->param_0)->width = MMI_content_width - MMI_fixed_list_menu.vbar.width;
            }
            ((mmi_imc_rect_p)msg_ptr->param_0)->y = MMI_content_y;
            
            ((mmi_imc_rect_p)msg_ptr->param_0)->height = MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - MMI_content_y;
        }
        break;
        
    case MMI_IMC_MESSAGE_GET_HANDWRITING_STYLE:
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_HANDWRITING_MULTI_BLOCK__)
        lresult = MMI_IMC_PEN_HANDWRITING_STYLE_MULTI_BLOCK;
#else
        lresult = MMI_IMC_PEN_HANDWRITING_STYLE_FULL_SCREEN;
#endif
        break;
#endif
  //  case MMI_IMC_MESSAGE_INSERT_NEW_LINE:
 //       break;

    case MMI_IMC_MESSAGE_HIDE_MULTITAP_CANDIDATE_BOX:

        lresult = MMI_TRUE;

        break;
        
    case MMI_IMC_MESSAGE_GET_EDITOR_SCROLL_BAR_WIDTH:
        lresult = (U32)MMI_fixed_list_menu.vbar.width;
        break;
        
    case MMI_IMC_MESSAGE_REDRAW:
        if (g_inline_redraw_entered ) 
        {
            wgui_inline_item_handled = 1;
            return 0;
        }    
        else 
        {
            g_inline_redraw_entered = MMI_TRUE;
        }
        
        
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING))
        wgui_fixed_list_register_skipping_handler(mmi_input_box_keep_current_item_info, mmi_input_box_resume_current_item_info);
#else
        mmi_input_box_keep_current_item_info();
#endif
        mmi_imc_config_update_input_mode_by_cursor_pos(MMI_FALSE);

        gui_inputs_set_cursor_change_event_state(MMI_FALSE);
 
        if (msg_ptr->param_0 == 1)
        {
            dm_imui_window_hide();
        }
        else if (!wgui_inline_item_handled)
        {
            redraw_fixed_list();
        }

        gui_inputs_set_cursor_change_event_state(MMI_TRUE);

        mmi_imc_config_update_input_mode_by_cursor_pos(MMI_TRUE);
        g_inline_redraw_entered = MMI_FALSE;
#if(!(UI_ENABLE_FRAME_SKIPPING) || !(ENABLE_LIST_MENU_FRAME_SKIPPING))
        mmi_input_box_resume_current_item_info();
#endif

        break;
        
    case MMI_IMC_MESSAGE_FLOATING_UI_APPEAR_INDICATION:
        dm_imui_window_display();
        break;
		
#if defined(__MMI_TOUCH_SCREEN__)   
#ifdef __MMI_FTE_SUPPORT__
    case MMI_IMC_MESSAGE_PEN_EVENT:
        if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_DOWN) 
        {
            switch (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type)
            {
            case MMI_EDITOR_DATE:
#if defined(__MMI_INLINE_ITEM_DATE__)                 
                lresult = mmi_input_box_msg_call_back_inline_date((date_input  *)((mmi_editor_handler_struct *)input_box_handle)->input_box_handler, msg_ptr);
#endif
                break;
                
            case MMI_EDITOR_IP4:
#ifdef __MMI_INLINE_ITEM_IP4__            
                lresult = mmi_input_box_msg_call_back_inline_ip4((IP4_input*)((mmi_editor_handler_struct *)input_box_handle)->input_box_handler, msg_ptr);
#endif

                break;
                
            case MMI_EDITOR_TIME:
#if defined(__MMI_INLINE_ITEM_TIME__)                 
                lresult = mmi_input_box_msg_call_back_inline_time((time_input *)((mmi_editor_handler_struct *)input_box_handle)->input_box_handler, msg_ptr);
#endif
                break;
#if defined (__MMI_INLINE_ITEM_TIME_PEROID__)                  
            case MMI_EDITOR_TIME_PERIOD:
                lresult = mmi_input_box_msg_call_back_inline_time_period((time_period_input *)((mmi_editor_handler_struct *)input_box_handle)->input_box_handler, msg_ptr);
                break;
#endif

#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
#if defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__)
             case MMI_EDITOR_INLINE_MULTILINE_INPUT_BOX:
                lresult = mmi_input_box_msg_call_back_inline_multiline(input_box_handle, msg_ptr);
                break;
#endif
#endif

            default: 
                break;
            }

            if (lresult)
            {
                pen_down = 1;
                wgui_general_pen_down_hdlr(((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos);
            }

            return lresult;
        }
        else if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_MOVE)
        {
            if (pen_down == 1)
            {
                wgui_general_pen_move_hdlr(((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos);
                if (gui_screen_smooth_scrolling_moved_by_pen())
                {
                    ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event = MMI_PEN_EVENT_ABORT;
                }
            }
        }
        else if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_UP)
        {
            if (pen_down == 1)
            {
                if (gui_screen_smooth_scrolling_moved_by_pen())
                {
                    ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event = MMI_PEN_EVENT_ABORT;
                }
                wgui_general_pen_up_hdlr(((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos);

                pen_down = 0;
            }
        } 
        else if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_ABORT)
        {
            if (pen_down == 1)
            {
                wgui_general_pen_abort_hdlr(((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos);

                pen_down = 0;
            }
        }
#endif /* __MMI_FTE_SUPPORT__ */
#endif /**/

    default:
        switch (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type)
        {
            
        case MMI_EDITOR_DATE:
#if defined(__MMI_INLINE_ITEM_DATE__)             
            lresult = mmi_input_box_msg_call_back_inline_date((date_input  *)((mmi_editor_handler_struct *)input_box_handle)->input_box_handler, msg_ptr);
#endif
            break;

        case MMI_EDITOR_IP4:
#ifdef __MMI_INLINE_ITEM_IP4__             
            lresult = mmi_input_box_msg_call_back_inline_ip4((IP4_input*)((mmi_editor_handler_struct *)input_box_handle)->input_box_handler, msg_ptr);
#endif
            break;
            
        case MMI_EDITOR_TIME:
#if defined(__MMI_INLINE_ITEM_TIME__)             
            lresult = mmi_input_box_msg_call_back_inline_time((time_input *)((mmi_editor_handler_struct *)input_box_handle)->input_box_handler, msg_ptr);
#endif
            break;

#if defined (__MMI_INLINE_ITEM_TIME_PEROID__)            
        case MMI_EDITOR_TIME_PERIOD:               
            lresult = mmi_input_box_msg_call_back_inline_time_period((time_period_input *)((mmi_editor_handler_struct *)input_box_handle)->input_box_handler, msg_ptr);
            break;
#endif            
    #if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
    #if defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__)
        case MMI_EDITOR_INLINE_MULTILINE_INPUT_BOX:
            lresult = mmi_input_box_msg_call_back_inline_multiline(input_box_handle, msg_ptr);
            break;
    #endif
    #endif
        default:
            break;
        }
        break;
    }

    return lresult;
        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_input_box_keep_current_item_info
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_input_box_keep_current_item_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!g_inline_current_input_box_handler)
    {
        return;
    }

    switch(g_inline_current_inline_item_type)
    {
    #if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
    #if defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__)
        case MMI_EDITOR_INLINE_MULTILINE_INPUT_BOX:

             memcpy(&g_inline_multiline_backup_struct, (multi_line_input_box *)g_inline_current_input_box_handler, sizeof(multi_line_input_box));

             g_inline_multiline_current_position = (S16)(((multi_line_input_box *)g_inline_current_input_box_handler)->cursor_p
                                                         - ((multi_line_input_box *)g_inline_current_input_box_handler)->text);

             g_inline_multiline_text_offset_x = ((multi_line_input_box *)g_inline_current_input_box_handler)->text_offset_x;

             g_is_inline_multiline_flags = ((multi_line_input_box *)g_inline_current_input_box_handler)->flags;

             g_inline_multiline_available_length = ((multi_line_input_box *)g_inline_current_input_box_handler)->available_length;

             g_is_inline_multiline_highlight_start_position = ((multi_line_input_box *)g_inline_current_input_box_handler)->highlight_start_position;

             g_is_inline_multiline_highlight_end_position = ((multi_line_input_box *)g_inline_current_input_box_handler)->highlight_end_position;
   
             g_inline_multiline_input_mode_cursor_p = ((multi_line_input_box *)g_inline_current_input_box_handler)->input_mode_cursor_p;

             g_inline_multiline_input_start_cursor_p = ((multi_line_input_box *)g_inline_current_input_box_handler)->input_start_cursor_p;
             
             g_is_item_info_kept = MMI_TRUE;
            
             break;
    #endif
    #endif
#if defined(__MMI_INLINE_ITEM_TIME__)     
        case MMI_EDITOR_TIME:
             g_inline_time_current_focus = (S16) wgui_inline_time_input.current_focus;

             if (wgui_inline_time_input.focus_input_box != NULL)
             {
                g_inline_time_current_position = (S16) (wgui_inline_time_input.focus_input_box->current_text_p -
                                                     wgui_inline_time_input.focus_input_box->text);
             }
            
             g_inline_time_flags = wgui_inline_time_input.input.flags;

             g_is_item_info_kept = MMI_TRUE;

             break;
#endif             
#if defined(__MMI_INLINE_ITEM_DATE__) 
        case MMI_EDITOR_DATE:    
             g_inline_date_current_focus = (S16) wgui_inline_date_input.current_focus;

             if (wgui_inline_date_input.focus_input_box != NULL)
             {
                 g_inline_date_current_position =
                    (S16) (wgui_inline_date_input.focus_input_box->current_text_p -
                    wgui_inline_date_input.focus_input_box->text);
             }

             g_inline_date_flags = wgui_inline_date_input.input.flags;

             g_is_item_info_kept = MMI_TRUE;

             break;
#endif             
#if defined (__MMI_INLINE_ITEM_TIME_PEROID__)   
        case MMI_EDITOR_TIME_PERIOD:    

            g_inline_time_period_current_focus = (S16) wgui_inline_time_period_input.current_focus;

            if (wgui_inline_time_period_input.focus_input_box != NULL)
            {
                g_inline_time_period_current_position =
                    (S16) (wgui_inline_time_period_input.focus_input_box->current_text_p -
                    wgui_inline_time_period_input.focus_input_box->text);
            }

            g_inline_time_period_flags = wgui_inline_time_period_input.input.flags;

            g_is_item_info_kept = MMI_TRUE;

            break;
#endif
        case MMI_EDITOR_IP4:
#if defined (__MMI_INLINE_ITEM_IP4__)

            g_inline_IP4_current_focus = (S16) wgui_inline_IP4_input.current_focus;

            if (wgui_inline_IP4_input.focus_input_box != NULL)
            {
                g_inline_IP4_current_position =
                    (S16) (wgui_inline_IP4_input.focus_input_box->current_text_p -
                    wgui_inline_IP4_input.focus_input_box->text);
            }

            g_inline_IP4_flags = wgui_inline_IP4_input.input.flags;

            g_is_item_info_kept = MMI_TRUE;

#endif
            break;
            
        default:
            break;
    }
        
}

        
/*****************************************************************************
 * FUNCTION
 *  mmi_input_box_resume_current_item_info
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_input_box_resume_current_item_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_message_struct msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING))
    wgui_fixed_list_register_skipping_handler(NULL, NULL);
#endif

    if (!g_inline_current_input_box_handler)
    {
        return;
    }

    if (g_is_item_info_kept == MMI_FALSE)
    {
        mmi_input_box_keep_current_item_info();
    }

    msg.message_id = MMI_IMC_MESSAGE_REDRAW;

    switch(g_inline_current_inline_item_type)
    {
        
    case MMI_EDITOR_DATE:
#if defined(__MMI_INLINE_ITEM_DATE__)         
        mmi_input_box_msg_call_back_inline_date((date_input  *)g_inline_current_input_box_handler, &msg);
#endif
        break;
        
    case MMI_EDITOR_IP4:
#if defined (__MMI_INLINE_ITEM_IP4__)        
        mmi_input_box_msg_call_back_inline_ip4((IP4_input*)g_inline_current_input_box_handler, &msg);
#endif
        break;
        
    case MMI_EDITOR_TIME:
#if defined(__MMI_INLINE_ITEM_TIME__)         
        mmi_input_box_msg_call_back_inline_time((time_input *)g_inline_current_input_box_handler, &msg);
#endif
        break;
 #if defined (__MMI_INLINE_ITEM_TIME_PEROID__)          
    case MMI_EDITOR_TIME_PERIOD:
        mmi_input_box_msg_call_back_inline_time_period((time_period_input *)g_inline_current_input_box_handler, &msg);
        break;
#endif
        
#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
#if defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__)
    case MMI_EDITOR_INLINE_MULTILINE_INPUT_BOX:
        mmi_input_box_msg_call_back_inline_multiline((void *)g_inline_current_editor_handle, &msg);
        break;
#endif
#endif
    default:
        break;
    }

    g_is_item_info_kept = MMI_FALSE;
}

#ifdef __MMI_UI_LIST_GRID_LINE__
/*****************************************************************************
 * FUNCTION
 *  wgui_inline_editor_generate_separator_table
 * DESCRIPTION
 *  generate separator index table for inline editor
 * PARAMETERS
 *  list_of_items        [IN]    list of inline items
 *  number_of_items        [IN]    number of inline items
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inline_editor_generate_separator_table(InlineItem *list_of_items, S32 number_of_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    BOOL first_item_is_caption = MMI_TRUE;
    BOOL flag = MMI_TRUE, auto_parse = MMI_FALSE;
    S32 first_enabled_item_idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(wgui_inline_separator_table, 0, sizeof(wgui_inline_separator_table));

    if (wgui_inline_list_of_icons != NULL)
    {
        for (i = 0; i < number_of_items; i++)
        {
            /* if have icon list, then judge separator by icon */
            if ((i != 0) && (wgui_inline_list_of_icons[i] != NULL))
            {
                wgui_inline_separator_table[i - 1] = MMI_TRUE;
            }
            /* If found Caption has no icon, than judge by Caption. */
            else if (wgui_inline_list_of_icons[i] == NULL
                && (list_of_items[i].flags & 0xff) == INLINE_ITEM_TYPE_CAPTION)
            {
                auto_parse = MMI_TRUE;
                memset(wgui_inline_separator_table, 0, sizeof(wgui_inline_separator_table));
                break;
            }
        }
    }
    else
    {
        auto_parse = MMI_TRUE;
    }
    
    if (auto_parse)
    {
        for (i = 0; i < number_of_items; i++)
        {
            
            if ((list_of_items[i].flags & 0xff) != INLINE_ITEM_DISABLED)
            {
                if (flag)
                {
                    first_enabled_item_idx = i;
                    flag = MMI_FALSE;
                }

                /*  First enabled item is not Caption 
                 *  we need to add separator line until meet first Caption 
                    first_item_is_caption means whether find first Caption.
                 */
                if ((i == first_enabled_item_idx) && ((list_of_items[i].flags & 0xff) != INLINE_ITEM_TYPE_CAPTION))
                {
                    first_item_is_caption = MMI_FALSE;
                }
                /* Meet normal item. Not find first Caption, so draw line. if found first caption, will not execute this branch. */
                if (!first_item_is_caption && ((list_of_items[i].flags & 0xff) != INLINE_ITEM_TYPE_CAPTION))
                {
                     wgui_inline_separator_table[i] = MMI_TRUE;             
                }
                /* Meet First Caption. Will not execute this branch anymore. */
                else if (!first_item_is_caption && ((list_of_items[i].flags & 0xff) == INLINE_ITEM_TYPE_CAPTION))
                {
                    first_item_is_caption = MMI_TRUE;
                }
                /* Meet Caption, so draw line above it. */
                else if ((list_of_items[i].flags & 0xff) == INLINE_ITEM_TYPE_CAPTION)
                {
                    if (i > 0)
                    {
                       wgui_inline_separator_table[i - 1] = MMI_TRUE;             
                    }
                }
            }
        }
    }
#ifndef __MMI_FTE_SUPPORT__
    if((list_of_items[number_of_items - 1].flags & 0xff) != INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY)
    {
    wgui_inline_separator_table[number_of_items - 1] = MMI_TRUE;
    }
#else
    wgui_inline_separator_table[number_of_items - 1] = MMI_TRUE;
#endif
   
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_editor_if_need_draw_separator_line
 * DESCRIPTION
 *  query if needed to draw separator line by item index
 * PARAMETERS
 *  item_index        [IN]    index of inline item
 * RETURNS
 *  MMI_BOOL  MMI_TURE --> need to draw ; MMI_FALSE  --> no need
 *****************************************************************************/
MMI_BOOL wgui_inline_editor_if_need_draw_separator_line(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (wgui_inline_separator_table[item_index]);
}
#endif  /* __MMI_UI_LIST_GRID_LINE__ */

/***************************************************************************** 
 * Categories  for inline editor
 *
 * These are Category blocks related to Inline editor
 *****************************************************************************/

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define CAT57_APPEND_NONE                    0x00000000
#define CAT57_APPEND_TOP_INFO_BOX            0x00000001
#define CAT57_APPEND_BUTTOM_INFO_BOX         0x00000002 /* no implement */
#define CAT57_APPEND_TOP_MULTILINE_BOX       0x00000003 /* no implement */
#define CAT57_APPEND_BUTTOM_MULTILINE_BOX    0x00000004 /* no implement */


/***************************************************************************** 
 * Local Variable
 *****************************************************************************/
/* parameter from caller */
#ifdef __MMI_INLINE_TOP_INFO_BOX__ 
static U16 cat57_append_type = CAT57_APPEND_NONE;
static void (*cat57_draw_info_callback) (S32 idx, S32 x1, S32 y1, S32 x2, S32 y2) = NULL;
static void (*cat57_hide_info_callback) (S32 idx) = NULL;
static BOOL cat57_is_draw_once; /* will one callback once */
static U16 cat57_info_row_count;

/* inner parameters */
static S32 cat57_pos_x1;
static S32 cat57_pos_y1;
static S32 cat57_pos_x2;
static S32 cat57_pos_y2;
#endif

static UI_font_type cat57_f1;
static UI_font_type cat57_f2;

static S32 cat657_tab_num = 0;
#ifdef __MMI_TOUCH_SCREEN__
S32 pen_down_x;
S32 pen_down_y;
#endif /* __MMI_TOUCH_SCREEN__ */ 

/***************************************************************************** 
 * Extern Global Function
 *****************************************************************************/
extern void reset_pop_up_descriptions(void);
extern void UI_dummy_menuitem_displayed_function(S32 index, S32 x1, S32 y1, S32 x2, S32 y2);

/***************************************************************************** 
 * Function Implementation
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_menu_disable_looping
 * DESCRIPTION
 *  disable inline editor menu looping
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_menu_disable_looping(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_inline_menu_disable_loop = MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  wgui_inline_menu_disable_looping
 * DESCRIPTION
 *  disable inline editor menu looping
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_menu_enable_looping(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_inline_menu_disable_loop = MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  InitializeCategory57Screen
 * DESCRIPTION
 *  Initialize inline edit related context data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitializeCategory57Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    n_inline_text_edit_items = 0;
    n_inline_select_items = 0;
#if defined(__MMI_INLINE_ITEM_DATE__)     
    n_inline_date_items = 0;
#endif
#if defined(__MMI_INLINE_ITEM_TIME__) 
    n_inline_time_items = 0;
#endif

#if defined (__MMI_INLINE_ITEM_IP4__)  
    n_inline_IP4_items = 0;
#endif

#if defined(__MMI_INLINE_ITEM_DOW__)  
    n_inline_DOW_items = 0;
#endif

#if defined (__MMI_INLINE_ITEM_TIME_PEROID__)   
    n_inline_time_period_items = 0;
#endif
    wgui_n_inline_items = 0;
#if defined (__MMI_INLINE_ITEM_IMAGETEXT__)         
    n_inline_image_text = 0;
#endif

#if defined (__MMI_INLINE_ITEM_COLOR_SELECT__)
    n_inline_color_select_items = 0;
#endif
    wgui_inline_item_highlighted_index = -1;
    wgui_inline_edit_DONE_function = NULL;
    wgui_inline_edit_BACK_function = NULL;
    wgui_inline_list_menu_changed = 0;
    current_wgui_inline_item = NULL;
    wgui_inline_edit_arrow_key_flag = CATEGORY57_NO_KEY_FLAG;
    /* Added to enable the scoll bar in sent or insent items */
    flag_scroll = FALSE;
    /* end */ 

    /* added to clean up wgui_inline_items */
    memset(wgui_inline_items, 0, sizeof(wgui_inline_item) * MAX_INLINE_ITEMS);
    /* end */

    /* for sending inline items' change notify to application */
    inline_item_changed_handler = NULL;
    /* end */

            
    wgui_inline_mem_alloc_number = 0; 

    wgui_inline_alloc_mem();
}


/*****************************************************************************
 * FUNCTION
 *  SetCategory57RightSoftkeyFunctions
 * DESCRIPTION
 *  set Category57 Right Softkey functions
 * PARAMETERS
 *  done_function       [IN]    done function    
 *  back_function       [IN]    back function    
 * RETURNS
 *  void
 *****************************************************************************/
void SetCategory57RightSoftkeyFunctions(void (*done_function) (void), void (*back_function) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inline_edit_DONE_function = done_function;
    wgui_inline_edit_BACK_function = back_function;
	g_inline_edit_done_function = done_function;
	g_inline_edit_back_function = back_function;
}


/*****************************************************************************
 * FUNCTION
 *  SetCategory57LeftSoftkeyFunction
 * DESCRIPTION
 *  set Category57 LSK function
 * PARAMETERS
 *  LSK_function        [IN]   LSK function     
 * RETURNS
 *  void
 *****************************************************************************/
void SetCategory57LeftSoftkeyFunction(void (*LSK_function) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_left_softkey_handler();
    set_left_softkey_function(execute_wgui_inline_edit_LSK_function, KEY_EVENT_UP);
    mmi_imc_key_setup_lsk_function(execute_wgui_inline_edit_LSK_function);
    wgui_inline_edit_LSK_function = LSK_function;
}


/*****************************************************************************
 * FUNCTION
 *  DisableCategory57ScreenDone
 * DESCRIPTION
 *  Diable Done for Cateogry57Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DisableCategory57ScreenDone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inline_list_menu_disable_done = 1;
}


/*****************************************************************************
 * FUNCTION
 *  EnableCategory57ScreenDone
 * DESCRIPTION
 *  Enable Done for Cateogry57Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EnableCategory57ScreenDone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inline_list_menu_disable_done = 0;
}


/*****************************************************************************
 * FUNCTION
 *  DisableCategory57ScreenRskBack
 * DESCRIPTION
 *  Diable FTE Back for Cateogry57Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DisableCategory57ScreenRskBack(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inline_list_menu_rsk_back = 0;
}


/*****************************************************************************
 * FUNCTION
 *  EnableCategory57ScreenRskBack
 * DESCRIPTION
 *  Enable FTE Back for Cateogry57Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EnableCategory57ScreenRskBack(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inline_list_menu_rsk_back = 1;
}


/* Max: set RSK to "Clear" */

/*****************************************************************************
 * FUNCTION
 *  SetCategory57ScreenRSKClear
 * DESCRIPTION
 *  Set Category57 Screen RSK Clear
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetCategory57ScreenRSKClear(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inline_list_menu_disable_done = 2; /* clear */
}


/*****************************************************************************
 * FUNCTION
 *  cat257_virtual_keypad_callback
 * DESCRIPTION
 *  virtual keypad callback for cat257
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cat257_virtual_keypad_callback(void)
{
#if defined(__MMI_TOUCH_SCREEN__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_redraw_screen_by_state();
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory257Screen
 * DESCRIPTION
 *  ShowCategory257Screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  ImgId                   [IN]        Image ID
 *  number_of_items         [IN]        Number of items
 *  list_of_icons           [IN]        List of icons
 *  list_of_items           [IN]        See InlineItem structure.
 *  highlighted_item        [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer          [IN]        History buffer       
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory257Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U16 ImgId,
        S32 number_of_items,
        U16 *list_of_icons,
        InlineItem *list_of_items,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    dm_coordinates gui_list_get_coordinates;
#ifdef __MMI_WALLPAPER_ON_BOTTOM__
    color c = {0, 0, 255, 100}; /* transparent color  */
#else 
    color c = {255, 255, 255, 100};
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    gui_setup_common_layout();
    
    dm_get_control_coordinates_from_category(
                -1,
                MMI_CATEGORY257_ID,
                DM_INLINE_FIXED_LIST1,
                -1,
                &gui_list_get_coordinates);
            
    resize_fixed_list(gui_list_get_coordinates.s16Width, gui_list_get_coordinates.s16Height);
#if defined(__MMI_TOUCH_SCREEN__)
    mmi_imc_set_inline_editor_full_height(MMI_fixed_list_menu.height);
#endif

    ShowCommonCategoryInlineEdit(
        (UI_string_type) get_string(title),
        title_icon,
        left_softkey,
        left_softkey_icon,
        right_softkey,
        right_softkey_icon,
        number_of_items,
        list_of_icons,
        list_of_items,
        highlighted_item,
        history_buffer,
        wgui_inline_edit_default_list_highlight_handler,
        wgui_inline_edit_default_list_unhighlight_handler,
        MMI_CATEGORY57_ID);

    /* scrollbar is disable*/
    resize_fixed_icontext_menuitems(
        MMI_fixed_list_menu.width - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP,
        get_menu_item_height());
    
    gdi_layer_unlock_frame_buffer();

    if (list_of_icons == NULL)
    {
        set_fixed_icontext_positions(4, 0, 1, 0);
    }
    else
    {
        set_fixed_icontext_positions(MMI_INLINE_EDIT_MENUITEM_HEIGHT + 2, 0, 1, 0);
    }
#ifndef __MMI_FTE_SUPPORT__
    MMI_fixed_list_menu.flags |= UI_LIST_MENU_DISABLE_SCROLLBAR | UI_LIST_MENU_DISABLE_BACKGROUND;
#else
    MMI_fixed_list_menu.flags |= UI_LIST_MENU_DISABLE_SCROLLBAR;
#endif


    SetCategory57ScreenRSKClear();
    SetCategory57RightSoftkeyFunctions(NULL, GoBackHistory);
    ExitCategoryFunction = ExitCategory57Screen;
    GetCategoryHistory = GetCategory57History;
    GetCategoryHistorySize = GetCategory57HistorySize;
    RedrawCategoryFunction = dm_redraw_category_screen;
#ifndef __MMI_FTE_SUPPORT__
    dm_add_image(get_image(ImgId), NULL, NULL);
    dm_add_rectangle(c, DM_RECTANGLE_FILL_COLOR);
#endif
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY257_ID;
    dm_data.s32flags = DM_SHOW_VKPAD;

#if !defined(GUI_EDITOR_SHOW_TITLE)
    if (full_screen_edit_open)
    {
        dm_data.s32flags |= DM_NO_TITLE;
    }
#endif /* !defined(GUI_EDITOR_SHOW_TITLE) */

    dm_setup_data(&dm_data);
    dm_register_vkpad_callback(cat57_virtual_keypad_callback);
    dm_redraw_category_screen();
}

/*****************************************************************************
*
* Category 57
*
*****************************************************************************/

#ifdef __MMI_INLINE_TOP_INFO_BOX__   

/*****************************************************************************
 * FUNCTION
 *  Cat57DrawTopInfoBox
 * DESCRIPTION
 *  draw top info box of Category57Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat57DrawTopInfoBox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gui_set_clip(cat57_pos_x1, cat57_pos_y1, cat57_pos_x2, cat57_pos_y2);

    gdi_draw_solid_rect(cat57_pos_x1, cat57_pos_y1, cat57_pos_x2, cat57_pos_y2, GDI_COLOR_WHITE);

    gui_pop_clip();
}
#endif

/*****************************************************************************
 * FUNCTION
 *  RedrawCategory57Screen
 * DESCRIPTION
 *  Category57 redraw function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RedrawCategory57Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dm_redraw_category_screen();
}


/*****************************************************************************
 * FUNCTION
 *  dm_category57_controlled_area
 * DESCRIPTION
 *  Category 57 controlled area callback called by draw manager
 * PARAMETERS
 *  coordinate      [IN/OUT]        It specifies the area in which the category will start the drawing. Also modifies it.
 * RETURNS
 *  void
 *****************************************************************************/
void dm_category57_controlled_area(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_INLINE_TOP_INFO_BOX__     
    if (cat57_append_type == CAT57_APPEND_TOP_INFO_BOX)
    {
        coordinate->s16Y = MMI_title_y + MMI_title_height;
        coordinate->s16Height = MMI_menuitem_height * cat57_info_row_count;
  
        /* draw top info box */
        Cat57DrawTopInfoBox();
        if (cat57_draw_info_callback != NULL)
        {
            cat57_draw_info_callback(
                MMI_fixed_list_menu.highlighted_item,
                cat57_pos_x1,
                cat57_pos_y1,
                cat57_pos_x2,
                cat57_pos_y2);
        }
    }
    else
#endif        
    {
        coordinate->s16Width = 0;
        coordinate->s16Height = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  Cat57HighlightHandler
 * DESCRIPTION
 *  Highlight handler of Category57
 * PARAMETERS
 *  item_index      [IN]    item index    
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat57HighlightHandler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    wgui_inline_edit_default_list_highlight_handler(item_index);
    
#ifdef __MMI_INLINE_TOP_INFO_BOX__ 
    if (cat57_append_type == CAT57_APPEND_TOP_INFO_BOX)
    {
        if (!(wgui_inline_items[item_index].flags & INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT))
        {
            if (cat57_draw_info_callback != NULL && cat57_is_draw_once == FALSE)
            {
                Cat57DrawTopInfoBox();
                cat57_draw_info_callback(item_index, cat57_pos_x1, cat57_pos_y1, cat57_pos_x2, cat57_pos_y2);
            }
        }
    }
#endif    

    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  Cat57UnHighlightHandler
 * DESCRIPTION
 *  unhighlight handler of Category57
 * PARAMETERS
 *  item_index      [IN]    item index    
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat57UnHighlightHandler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inline_edit_default_list_unhighlight_handler(item_index);

#ifdef __MMI_INLINE_TOP_INFO_BOX__
    if (cat57_hide_info_callback != NULL && cat57_is_draw_once == FALSE)
    {
        cat57_hide_info_callback(item_index);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  cat57_virtual_keypad_callback
 * DESCRIPTION
 *  virtual keypad callback for cat57
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cat57_virtual_keypad_callback(void)
{
#if defined(__MMI_TOUCH_SCREEN__)
    mmi_imc_redraw_screen_by_state();
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 
}


#if defined (__MMI_WALLPAPER_ON_BOTTOM__)
/*****************************************************************************
 * FUNCTION
 *  ShowCategory357Screen
 * DESCRIPTION
 *  ShowCategory357Screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  ImgId                   [IN]        Image shown on top of list
 *  number_of_items         [IN]        Number of items
 *  list_of_icons           [IN]        List of icons
 *  list_of_items           [IN]        See InlineItem structure.
 *  highlighted_item        [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory357Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U16 ImgId,
        S32 number_of_items,
        U16 *list_of_icons,
        InlineItem *list_of_items,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    gui_setup_common_layout();
    
    ShowCommonCategoryInlineEdit(
        (UI_string_type) get_string(title),
        title_icon,
        left_softkey,
        left_softkey_icon,
        right_softkey,
        right_softkey_icon,
        number_of_items,
        list_of_icons,
        list_of_items,
        highlighted_item,
        history_buffer,
        Cat57HighlightHandler,
        Cat57UnHighlightHandler,
        MMI_CATEGORY57_ID);

    if (flag_scroll)
    {
        MMI_fixed_list_menu.flags |= UI_LIST_MENU_DISABLE_SCROLLBAR;
    }

    dm_add_image(get_image(ImgId), NULL, NULL);
    dm_get_scr_bg_opacity(&inline_edit_scr_bg_opacity);
    dm_set_scr_bg_opacity((U8)(current_MMI_theme->bg_opacity_low)); 

    inline_opacity_changed = TRUE;

    gdi_layer_unlock_frame_buffer();

    ExitCategoryFunction = ExitCategory57Screen;
    RedrawCategoryFunction = dm_redraw_category_screen;
    GetCategoryHistory = GetCategory57History;
    GetCategoryHistorySize = GetCategory57HistorySize;
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY357_ID;
    dm_data.s32flags = 0;
    dm_data.s32flags |= DM_SHOW_VKPAD;
#if !defined(GUI_EDITOR_SHOW_TITLE)
    if (full_screen_edit_open)
    {
        dm_data.s32flags |= DM_NO_TITLE;
    }
#endif /* !defined(GUI_EDITOR_SHOW_TITLE) */
    dm_setup_data(&dm_data);
    dm_register_category_controlled_callback(dm_category57_controlled_area);
    dm_register_vkpad_callback(cat57_virtual_keypad_callback);
    dm_redraw_category_screen();
}
#endif /* defined (__MMI_WALLPAPER_ON_BOTTOM__) */ 


/*****************************************************************************
 * FUNCTION
 *  ShowCategory657Screen
 * DESCRIPTION
 *  ShowCategory657Screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  number_of_items         [IN]        Number of items
 *  list_of_icons           [IN]        List of icons
 *  list_of_items           [IN]        See InlineItem structure.
 *  highlighted_item        [IN]        Default item to be highlighted (if there is no history)
 *  n_tabs                  [IN]        number of tabs
 *  highlighted_tab         [IN]        highlighted tab
 *  tab_items               [IN]        tab items
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory657Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        U16 *list_of_icons,
        InlineItem *list_of_items,
        S32 highlighted_item,
        S8 highlighted_tab,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    S8 n_tabs;
    dm_coordinates gui_list_get_coordinates;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_setup_common_layout();
    
    gdi_layer_lock_frame_buffer();

    /* Show Tab bars */
    mmi_frm_get_tab_bar_items(MMI_tab_bar_items, &n_tabs);
    cat657_tab_num = n_tabs;
    
    if (n_tabs)
    {
        wgui_create_horizontal_tab_bar(TRUE, (UI_string_type)GetString(title), n_tabs, highlighted_tab, MMI_FALSE);
    }


    dm_get_control_coordinates_from_category(
        -1,
        MMI_CATEGORY657_ID,
        DM_INLINE_FIXED_LIST1,
        -1,
        &gui_list_get_coordinates);

    resize_fixed_list(gui_list_get_coordinates.s16Width, gui_list_get_coordinates.s16Height);
    
#if defined(__MMI_TOUCH_SCREEN__)
    mmi_imc_set_inline_editor_full_height(gui_list_get_coordinates.s16Height);
#endif
    /* Show Inline */

    ShowCommonCategoryInlineEdit(
        (UI_string_type) get_string(title),
        title_icon,
        left_softkey,
        left_softkey_icon,
        right_softkey,
        right_softkey_icon,
        number_of_items,
        list_of_icons,
        list_of_items,
        highlighted_item,
        history_buffer,
        Cat57HighlightHandler,
        Cat57UnHighlightHandler,
        MMI_CATEGORY57_ID);

    if (flag_scroll)
    {
        MMI_fixed_list_menu.flags |= UI_LIST_MENU_DISABLE_SCROLLBAR;
    }

    if (history_buffer == NULL)
    {
#ifdef __MMI_FTE_SUPPORT__
	/* In category657screen, resize fixed list will lead to  list height error, so we set wgui_inline_item_highlighted_index to -1
	to execute highlight item function manipulately. */
	wgui_inline_item_highlighted_index = -1;
#endif
        fixed_list_goto_item_no_redraw(highlighted_item);
    }
    else
    {
#ifdef __MMI_FTE_SUPPORT__
        /* In category657screen, resize fixed list will lead to  list height error, so we set wgui_inline_item_highlighted_index to -1
        to execute highlight item function manipulately. */
        wgui_inline_item_highlighted_index = -1;
#endif
        fixed_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
    }

    gdi_layer_unlock_frame_buffer();

    ExitCategoryFunction = ExitCategory657Screen;
    RedrawCategoryFunction = dm_redraw_category_screen;
    GetCategoryHistory = GetCategory57History;
    GetCategoryHistorySize = GetCategory57HistorySize;
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY657_ID;
    dm_data.s32flags = 0;
    dm_data.s32flags |= DM_SHOW_VKPAD;
    dm_setup_data(&dm_data);
    dm_register_category_controlled_callback(dm_category57_controlled_area);
    dm_register_vkpad_callback(cat57_virtual_keypad_callback);
    dm_redraw_category_screen();
#ifdef __MMI_FTE_SUPPORT__	
    mmi_imc_set_vk_present(MMI_IMC_VK_DEFAULT_ENLARGE);
#endif	

#ifdef __MMI_FTE_SUPPORT__
    wgui_icon_bar_register_pause_interactive_UI_callback(wgui_inline_stop_scroll);
    wgui_icon_bar_register_resume_interactive_UI_callback(wgui_inline_start_scroll);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory57Screen
 * DESCRIPTION
 *  Redraws the category57 screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  number_of_items         [IN]        Number of items
 *  list_of_icons           [IN]        List of icons
 *  list_of_items           [IN]        See InlineItem structure.
 *  highlighted_item        [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory57Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        U16 *list_of_icons,
        InlineItem *list_of_items,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory57Screen_for_title(
	(PU8) get_string(title),
        title_icon,
        left_softkey,
        left_softkey_icon,
        right_softkey,
        right_softkey_icon,
        number_of_items,
        list_of_icons,
        list_of_items,
        highlighted_item,
	    history_buffer);
        
}

/*****************************************************************************
 * FUNCTION
   ShowCategory57Screen_for_title
 * DESCRIPTION
 *  showcategory57 with a string pointer
 * PARAMETERS
 *  title_string            [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  number_of_items         [IN]        Number of items
 *  list_of_icons           [IN]        List of icons
 *  list_of_items           [IN]        See InlineItem structure.
 *  highlighted_item        [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory57Screen_for_title(
        PU8 title_string,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        U16 *list_of_icons,
        InlineItem *list_of_items,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    dm_coordinates gui_list_get_coordinates;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_SCREEN_ROTATE__
    if (!mmi_frm_is_screen_width_height_swapped())
    {
        gui_setup_common_layout();
    }
#endif

#ifdef __MMI_INLINE_TOP_INFO_BOX__     
    /* init append related parameters */
    if (cat57_append_type == CAT57_APPEND_TOP_INFO_BOX)
    {
        cat57_pos_x1 = 0;
        cat57_pos_y1 = MMI_title_y + MMI_title_height;
        cat57_pos_x2 = UI_device_width - 1;
        cat57_pos_y2 = MMI_title_y + MMI_title_height + MMI_menuitem_height * cat57_info_row_count - 1;

    }
#endif
    gdi_layer_lock_frame_buffer();


     dm_get_control_coordinates_from_category(
            -1,
            MMI_CATEGORY57_ID,
            DM_INLINE_FIXED_LIST1,
            -1,
            &gui_list_get_coordinates);
        
        resize_fixed_list(gui_list_get_coordinates.s16Width, gui_list_get_coordinates.s16Height);
        move_fixed_list(gui_list_get_coordinates.s16X, gui_list_get_coordinates.s16Y);

#if defined(__MMI_TOUCH_SCREEN__)
        mmi_imc_set_inline_editor_full_height(MMI_fixed_list_menu.height);
#endif

    ShowCommonCategoryInlineEdit(
        (UI_string_type) title_string,
        title_icon,
        left_softkey,
        left_softkey_icon,
        right_softkey,
        right_softkey_icon,
        number_of_items,
        list_of_icons,
        list_of_items,
        highlighted_item,
        history_buffer,
        Cat57HighlightHandler,
        Cat57UnHighlightHandler,
        MMI_CATEGORY57_ID);

    if (flag_scroll)
    {
        MMI_fixed_list_menu.flags |= UI_LIST_MENU_DISABLE_SCROLLBAR;
    }
    MMI_fixed_list_menu.flags |= UI_LIST_MENU_ALIGN_TO_TOP;

    if (history_buffer == NULL)
    {
        fixed_list_goto_item_no_redraw(highlighted_item);
    }

    gdi_layer_unlock_frame_buffer();

    ExitCategoryFunction = ExitCategory57Screen;
    RedrawCategoryFunction = dm_redraw_category_screen;
    GetCategoryHistory = GetCategory57History;
    GetCategoryHistorySize = GetCategory57HistorySize;
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY57_ID;
    dm_data.s32flags = 0;
    dm_data.s32flags |= DM_SHOW_VKPAD;
    dm_data.s32flags |= DM_CLEAR_SCREEN_BACKGROUND;
#if !defined(GUI_EDITOR_SHOW_TITLE)
    if (full_screen_edit_open)
    {
        dm_data.s32flags |= DM_NO_TITLE;
    }
#endif /* !defined(GUI_EDITOR_SHOW_TITLE) */
    dm_setup_data(&dm_data);
    dm_register_category_controlled_callback(dm_category57_controlled_area);
    dm_register_vkpad_callback(cat57_virtual_keypad_callback);
    dm_redraw_category_screen();
#ifdef __MMI_FTE_SUPPORT__	
	mmi_imc_set_vk_present(MMI_IMC_VK_DEFAULT_ENLARGE);
#endif	

#ifdef __MMI_FTE_SUPPORT__
    wgui_icon_bar_register_pause_interactive_UI_callback(wgui_inline_stop_scroll);
    wgui_icon_bar_register_resume_interactive_UI_callback(wgui_inline_start_scroll);
#endif
}


#ifdef __MMI_INLINE_TOP_INFO_BOX__   
/*****************************************************************************
 * FUNCTION
 *  Category57AppendTopInfoBox
 * DESCRIPTION
 *  Append top info box to Category screen 57.
 *  [NOTIC!] call this function before calling ShowCategory57Screen
 * PARAMETERS
 *  num_of_info_box_rows        [IN]       number of info box row 
 *  draw_info_callback          [IN]       draw info callback function 
 *  hide_info_callback          [IN]       hide info callback function 
 *  is_draw_once                [IN]       is draw once 
 * RETURNS
 *  void
 *****************************************************************************/
void Category57AppendTopInfoBox(
        U16 num_of_info_box_rows,
        void (*draw_info_callback) (S32 idx, S32 x1, S32 y1, S32 x2, S32 y2),
        void (*hide_info_callback) (S32 idx),
        BOOL is_draw_once)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cat57_append_type = CAT57_APPEND_TOP_INFO_BOX;

    cat57_draw_info_callback = draw_info_callback;
    cat57_hide_info_callback = hide_info_callback;
    cat57_info_row_count = num_of_info_box_rows;
    cat57_is_draw_once = is_draw_once;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  CloseCategory57Screen
 * DESCRIPTION
 *  close the category57 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CloseCategory57Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
#if defined(__MMI_TOUCH_SCREEN__)
    mmi_pen_editor_is_closecategory57 = MMI_TRUE;
#endif 
    complete_inline_item_edit();
#if defined(__MMI_TOUCH_SCREEN__)
    mmi_pen_editor_is_closecategory57 = MMI_FALSE;
#endif 
    gdi_layer_unlock_frame_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory657Screen
 * DESCRIPTION
 *  Exit category657Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory657Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (cat657_tab_num)
    {
        wgui_close_horizontal_tab_bar();
        cat657_tab_num = 0;
    }
    ExitCategory57Screen();
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory57Screen
 * DESCRIPTION
 *  Exit Category57Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory57Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inline_free_mem();
    wgui_inline_mem_alloc_number = 0; 
    
#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
#if defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__)
    MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_INSIDE_INLINE_MENU;
#endif 
#endif 

#if(UI_BLINKING_CURSOR_SUPPORT)
    StopTimer(BLINKING_CURSOR);
#endif

#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
    DisableInlineItemDefaultText();
#endif 

    wgui_title_disable_menu_shortcut_display(MMI_FALSE);
    wgui_inline_edit_arrow_key_flag = CATEGORY57_NO_KEY_FLAG;
    gui_set_fixed_list_menu_current_theme(&MMI_fixed_list_menu);
    current_wgui_inline_item = NULL;
    wgui_n_inline_items = 0;
    wgui_inline_item_highlighted_index = -1;
    wgui_inline_list_menu_changed = 0;
    wgui_inline_list_menu_disable_done = 0;
    MMI_multi_line_inputbox_present = 0;
    wgui_inputbox_information_flag = 0;
    wgui_inline_edit_DONE_function = NULL;
    wgui_inline_edit_BACK_function = NULL;
    inline_text_edit_APP_Assigned_RSK_label_string = NULL;
    complete_inline_item_edit = UI_dummy_function;
    category_inline_edit_menuitem_flags();
    clear_inline_item_keys();
    wgui_text_menuitem_reset_scrolling();
    if (g_inline_menu_disable_loop)
    {
        g_inline_menu_disable_loop = MMI_FALSE;
        fixed_list_enable_looping();
    }

#if defined (__MMI_INLINE_ITEM_IMAGETEXT__)    
    clear_inline_image_text_item();
#endif
    
#ifdef __MMI_FTE_SUPPORT__
    /* When FTE, Stop scrolling when highlight item is displayonly or fullscreen edit. */
    wgui_inline_display_only_close();
#endif
    
    //Reset The Change Flag
    MMI_multiline_inputbox.editor_changed = 0;
    reset_pop_up_descriptions();
    redraw_current_inline_item = UI_dummy_function;
#ifdef __MMI_TOUCH_SCREEN__
    wgui_current_inline_item_pen_function = UI_dummy_inline_item_pen_function;
#endif 
    ClearHighlightHandler();
    reset_softkeys();
    mmi_imc_key_setup_csk_function(UI_dummy_function);
	mmi_imc_key_setup_lsk_function(UI_dummy_function);
    mmi_imc_key_setup_rsk_function(UI_dummy_function);
    reset_menu_shortcut_handler();
    reset_fixed_list();
    MMI_fixed_list_menu.flags &= ~UI_LIST_MENU_INLINE_EDIT;
    MMI_fixed_list_menu.item_displayed_callback = UI_dummy_menuitem_displayed_function;
    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = MMI_dummy_function;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;
    MMI_fixed_icontext_menuitem.text_font = cat57_f1;
    MMI_fixed_text_menuitem.text_font = cat57_f2;

    /* reset append */
#ifdef __MMI_INLINE_TOP_INFO_BOX__    
    cat57_append_type = CAT57_APPEND_NONE;
    cat57_draw_info_callback = NULL;
    cat57_hide_info_callback = NULL;
    cat57_info_row_count = 0;
#endif

    g_inline_text_gap_with_list = 0;
    g_inline_picon = NULL;

#ifdef __MMI_WALLPAPER_ON_BOTTOM__
    if (inline_opacity_changed)
    {
        dm_set_scr_bg_opacity(inline_edit_scr_bg_opacity);
        inline_opacity_changed = FALSE;
    }
#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */ 

#if !defined(GUI_EDITOR_SHOW_TITLE)
    {
        S32 dm_flag;
        
        dm_get_dm_data_flag(&dm_flag);
        dm_flag &= ~DM_NO_TITLE;
        
        dm_set_dm_data_flag(dm_flag);
        
        full_screen_edit_open = 0;
    }
#endif /* !defined(GUI_EDITOR_SHOW_TITLE) */

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif 


#ifdef __MMI_UI_TRANSPARENT_EFFECT__
    enable_fixed_icontext_menuitem_transparent_effect();
#endif 

    /* for sending inline items' change notify to application */
    inline_item_changed_handler = NULL;
    /* end */

    g_inline_disable_auto_enter = MMI_FALSE;
    g_select_unhighlight_x_corrdinate = 0;

#ifdef __MMI_FTE_SUPPORT__
    mmi_imc_set_vk_present(MMI_IMC_VK_PRESENT_DEFAULT);
#endif

    if(cui_inline_is_current_cui())
    {
       cui_inline_evt_mainscreen_exit();
       cui_inline_reset_instance_point();
    }

#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
#if defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__)
    memset(&g_inline_ml_rdly_highlight_list, 0, sizeof(wgui_inline_ml_rdly_highlight_list_struct));
#endif
#endif

#ifdef __MMI_TOUCH_SCREEN__
    gui_vertical_scrollbar_reset_get_diff(&(MMI_fixed_list_menu.vbar));
#endif

    g_inline_parent_id = 0;

}


/*****************************************************************************
 * FUNCTION
 *  GetCategory57HistorySize
 * DESCRIPTION
 *  Gets the size of the history buffer for the category57 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  size of history buffer in U8s
 *****************************************************************************/
S32 GetCategory57HistorySize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (wgui_get_inline_history_size());
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory57History
 * DESCRIPTION
 *  Gets the history buffer for the category57 screen
 * PARAMETERS
 *  history_buffer      [IN]        Is the buffer into which the history data is stored (pre-allocated)
 * RETURNS
 *  pointer to the history buffer
 *****************************************************************************/
U8 *GetCategory57History(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (wgui_get_inline_history(MMI_CATEGORY57_ID, history_buffer));
}


/*****************************************************************************
 * FUNCTION
 *  Category57ChangeItemIcon
 * DESCRIPTION
 *  change item icon of category57
 * PARAMETERS
 *  index           [IN]     item index   
 *  image_ID        [IN]     image id   
 * RETURNS
 *  void
 *****************************************************************************/
void Category57ChangeItemIcon(S32 index, U16 image_ID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* FIXME. There is potential problem that some inline items does not have icon. */
    MMI_fixed_icontext_menuitems[index].item_icon = wgui_get_list_menu_icon(index, image_ID);
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory57DataSize
 * DESCRIPTION
 *  Get cat57 data size
 * PARAMETERS
 *  void
 * RETURNS
 *  data size
 *****************************************************************************/
S32 GetCategory57DataSize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (wgui_get_inline_data_size());
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory57Data
 * DESCRIPTION
 *  det cat57 data
 * PARAMETERS
 *  data        [OUT]   data   
 * RETURNS
 *  data pointer
 *****************************************************************************/
U8 *GetCategory57Data(U8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (wgui_get_inline_data(data));
}


/*****************************************************************************
 * FUNCTION
 *  SetCategory57Data
 * DESCRIPTION
 *  set Cat57 data
 * PARAMETERS
 *  list_of_items       [IN]    list of inline item
 *  number_of_items     [IN]    number of item
 *  data                [IN]    data
 * RETURNS
 *  void
 *****************************************************************************/
void SetCategory57Data(InlineItem *list_of_items, S32 number_of_items, U8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_set_inline_data(list_of_items, number_of_items, data);
}


/*****************************************************************************
 * FUNCTION
 *  ShowCommonCategoryInlineEdit
 * DESCRIPTION
 *  show common inline edit category
 * PARAMETERS
  *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  number_of_items         [IN]        Number of items
 *  list_of_icons           [IN]        List of icons
 *  list_of_items           [IN]        See InlineItem structure.
 *  highlighted_item        [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer          [IN]        History buffer        
 *  highlight_handler       [IN]        highlight handler
 *  unhighlight_handler     [IN]        unhighlight handler
 *  history_id              [IN]        history id
 * RETURNS
 *  void
 *****************************************************************************/
static void ShowCommonCategoryInlineEdit(
        UI_string_type title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        U16 *list_of_icons,
        InlineItem *list_of_items,
        S32 highlighted_item,
        U8 *history_buffer,
        void (*highlight_handler) (S32 item_index),
        void (*unhighlight_handler) (S32 item_index),
        U16 history_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 h_flag;
    S32 i;

    UI_fixed_icontext_menuitem_theme *saved_themedata1 = current_fixed_icontext_menuitem_theme;
    UI_fixed_list_menu_theme *saved_themedata2 = current_fixed_list_menu_theme;
    list_menu_category_history *h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Backup font */
    cat57_f1 = MMI_fixed_icontext_menuitem.text_font;
    cat57_f2 = MMI_fixed_text_menuitem.text_font;

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif 

    wgui_title_set_menu_shortcut_number(-1);
    clear_category_screen_key_handlers();
    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);
    clear_left_softkey();
    clear_right_softkey();
    register_left_softkey_handler();
    register_right_softkey_handler();
    register_default_hide_softkeys();

    MMI_title_string = title;
    MMI_title_icon = (PU8) get_image(title_icon);

    wgui_inline_fixed_icontext_menuitem_theme.focussed_filler = current_MMI_theme->list_selected_item_filler;
    wgui_inline_fixed_icontext_menuitem_theme.selected_filler = current_MMI_theme->list_selected_item_filler;
    wgui_inline_fixed_icontext_menuitem_theme.focussed_without_sc_filler = current_MMI_theme->list_selected_item_filler;
    wgui_inline_fixed_list_menu_theme.focussed_filler = current_MMI_theme->list_selected_item_filler;
    wgui_inline_fixed_list_menu_theme.normal_filler = current_fixed_list_menu_theme->normal_filler;
    

    current_fixed_icontext_menuitem_theme = &wgui_inline_fixed_icontext_menuitem_theme;
    current_fixed_list_menu_theme = &wgui_inline_fixed_list_menu_theme;

    gui_set_fixed_list_menu_current_theme(&MMI_fixed_list_menu);

    create_fixed_icontext_menuitems();
#if !defined(__MMI_FTE_SUPPORT__)
    MMI_fixed_list_menu.flags |= UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR;
#endif
    associate_fixed_icontext_list();

    MMI_fixed_list_menu.flags |= UI_LIST_MENU_INLINE_EDIT;

    if (g_inline_menu_disable_loop)
    {
        fixed_list_disable_looping();
    }

#ifdef __MMI_TOUCH_SCREEN__
    /* Avoid menu position shifted when it is resized for differet virtual keyboard layout */
    MMI_fixed_list_menu.flags |= UI_LIST_MENU_ALIGN_TO_TOP;
#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
    temp_inline_edit_normal_filler.border_color = current_fixed_icontext_menuitem_theme->focussed_filler->c;
    MMI_fixed_icontext_menuitem.selected_filler = &temp_inline_edit_normal_filler;
    
#ifndef __GDI_MEMORY_PROFILE_2__
    MMI_fixed_icontext_menuitem.selected_filler = current_MMI_theme->inline_list_normal_item_filler;
#endif

#endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 

#ifdef __MMI_UI_TRANSPARENT_EFFECT__
    disable_fixed_icontext_menuitem_transparent_effect();
#endif 

#ifdef __MMI_FTE_SUPPORT__
    for (i = 0; (i < number_of_items) && (i < MAX_INLINE_ITEMS); i++)
    {
        ShowAsControl(&(wgui_inline_items[i]));
        
            MMI_fixed_icontext_menuitems[i].flags |= UI_MENUITEM_INLINE_EDIT_OBJECT;
        
        list_of_items[i].flags |= INLINE_ITEM_DISABLE_HIGHLIGHT;
        list_of_items[i].flags &= ~INLINE_ITEM_JUSTIFY_MASK;
        list_of_items[i].flags |= INLINE_ITEM_LEFT_JUSTIFY;
    }

    for (i = 0; (i < number_of_items) && (i < MAX_INLINE_ITEMS); i++)
    {
        if(list_of_icons == NULL)
        {
            break;
        }

        if((list_of_icons[i] == NULL) || (get_image(list_of_icons[i]) == NULL))
        {
            list_of_icons = NULL;
            break;
        }
    }
#endif
      //there are no icons in Inline item
   list_of_icons = NULL; 

   wgui_inline_list_of_icons = list_of_icons;

#ifdef __MMI_UI_LIST_GRID_LINE__
    wgui_inline_editor_generate_separator_table(list_of_items,number_of_items);
#endif /* __MMI_UI_LIST_GRID_LINE__ */
    
#ifdef __MMI_FTE_SUPPORT__
    inline_fte_set_item_height_by_guess(list_of_items, number_of_items);
#endif

        /*  icons */
        for (i = 0; (i < number_of_items) && (i < MAX_INLINE_ITEMS); i++)
        {
            wgui_inline_items[i] = list_of_items[i];
            
            if (list_of_icons == NULL)
            {
                add_fixed_icontext_item((UI_string_type) wgui_inline_items[i].text_p, NULL);
            }
            else
            {    
                wgui_inline_items[i].side_img = get_image(list_of_icons[i]);
                add_fixed_icontext_item((UI_string_type) wgui_inline_items[i].text_p, 
                    (PU8)GetImage(list_of_icons[i]));
            }

#ifdef __MMI_INLINE_HIGHLIGHT_CAPTION__
            //Inline draw all items by itself
            MMI_fixed_icontext_menuitems[i].flags |= UI_MENUITEM_INLINE_EDIT_OBJECT;
#endif

            if (WGUI_INLINE_ITEM_TYPE(i) == INLINE_ITEM_TYPE_USER_DEFINED_SELECT)
            {
                MMI_fixed_icontext_menuitems[i].flags |= UI_MENUITEM_DISABLE_BACKGROUND_ALWAYS;
                MMI_fixed_icontext_menuitems[i].ext_flags |= UI_MENUITEM_EXT_DISABLE_FOCUSSED_TEXT_DISPLAY;
            }

#if defined (__MMI_INLINE_ITEM_DOW__)
            if (WGUI_INLINE_ITEM_TYPE(i) == INLINE_ITEM_TYPE_DOW_SELECT)
            {
                MMI_fixed_icontext_menuitems[i].flags |= UI_MENUITEM_INLINE_EDIT_OBJECT;
            }
#endif            

            if (WGUI_INLINE_ITEM_TYPE(i) == INLINE_ITEM_TYPE_DISPLAY_ONLY)
            {
                if((wgui_inline_items[i].flags) & INLINE_ITEM_RIGHT_JUSTIFY)
                {
                    MMI_fixed_icontext_menuitems[i].flags |= UI_MENUITEM_INLINE_EDIT_OBJECT;
                }
            }

#if defined (__MMI_INLINE_ITEM_COLOR_SELECT__)            
            if (WGUI_INLINE_ITEM_TYPE(i) == INLINE_ITEM_TYPE_COLOR_SELECT)
            {                
                MMI_fixed_icontext_menuitems[i].flags |= UI_MENUITEM_INLINE_EDIT_OBJECT;
            }
#endif            

            if (wgui_inline_items[i].flags & INLINE_ITEM_DISABLE_HIGHLIGHT)
            {
                MMI_fixed_icontext_menuitems[i].flags |= UI_MENUITEM_DISABLE_BACKGROUND_ALWAYS;
            }

            if ((wgui_inline_items[i].flags & INLINE_ITEM_BOUNDARY_MASK) == INLINE_ITEM_BOUNDARY_ALWAYS)
            {
                MMI_fixed_icontext_menuitems[i].flags |= UI_MENUITEM_INLINE_EDIT_OBJECT;
            }

            
            if (list_of_icons)
            {
                if (((wgui_inline_items[i].flags & INLINE_ITEM_LEFT_ALIGN) == INLINE_ITEM_LEFT_ALIGN) &&
                    (WGUI_INLINE_ITEM_TYPE(i) == INLINE_ITEM_TYPE_CAPTION) &&
                    (get_image(list_of_icons[i]) == NULL))
                {
                    MMI_fixed_icontext_menuitems[i].flags |= UI_MENUITEM_DISABLE_ICON;
                }

            }

#if defined (__MMI_INLINE_ITEM_IMAGETEXT__)
            if (WGUI_INLINE_ITEM_TYPE(i) == INLINE_ITEM_IMAGE_TEXT_TYPE)
            {
                if (wgui_inline_items[i].show_img_flag == TRUE)
                {
                    MMI_fixed_icontext_menuitems[i].flags |= UI_MENUITEM_INLINE_EDIT_OBJECT;
                }
            }
#endif

#if defined (__MMI_INLINE_ITEM_MULTILINE_EDIT__) || defined (__MMI_INLINE_ITEM_MULTILINE_READ_ONLY__)
            if ((WGUI_INLINE_ITEM_TYPE(i) == INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY) ||
                (WGUI_INLINE_ITEM_TYPE(i) == INLINE_ITEM_TYPE_MULTI_LINE_EDIT))
            {
                MMI_fixed_icontext_menuitems[i].flags |= UI_MENUITEM_INLINE_EDIT_OBJECT;
            }
#endif

#if defined (__MMI_INLINE_ITEM_TIME_PEROID__)
            if (WGUI_INLINE_ITEM_TYPE(i) == INLINE_ITEM_TYPE_TIME_PERIOD)
            {
                MMI_fixed_icontext_menuitems[i].ext_flags |= UI_MENUITEM_EXT_DISABLE_FOCUSSED_TEXT_DISPLAY;
            }
#endif            

#if defined (__MMI_INLINE_ITEM_COLOR_SELECT__) 
            if (WGUI_INLINE_ITEM_TYPE(i) == INLINE_ITEM_TYPE_COLOR_SELECT)
            {               
                if (wgui_inline_items[i].show_img_flag == TRUE)
                {
                    MMI_fixed_icontext_menuitems[i].flags |= UI_MENUITEM_INLINE_EDIT_OBJECT;
                }
                MMI_fixed_icontext_menuitems[i].flags |= UI_MENUITEM_DISABLE_BACKGROUND_ALWAYS;
                MMI_fixed_icontext_menuitems[i].ext_flags |= UI_MENUITEM_EXT_DISABLE_FOCUSSED_TEXT_DISPLAY;
            }
#endif            

            if (WGUI_INLINE_ITEM_TYPE(i) == INLINE_ITEM_TYPE_TEXT_EDIT)
            {
                if(wgui_inline_items[i].flags & INLINE_ITEM_ICON_IN_ITEM)
                {
                    MMI_fixed_icontext_menuitems[i].ext_flags |= UI_MENUITEM_EXT_SHOW_INDICATOR;
                }
                if (list_of_icons)
                {
                    if(wgui_inline_items[i].side_img == NULL)
                    {
                        wgui_inline_items[i].flags &= ~INLINE_ITEM_DISABLE_HIGHLIGHT;
                    }
                }
            }
            
            if ((WGUI_INLINE_ITEM_TYPE(i) == INLINE_ITEM_TYPE_FULL_SCREEN_EDIT) ||
                (WGUI_INLINE_ITEM_TYPE(i) == INLINE_ITEM_TYPE_CAPTION) ||
                (WGUI_INLINE_ITEM_TYPE(i) == INLINE_ITEM_TYPE_DISPLAY_ONLY))
            {  
                if(wgui_inline_items[i].flags & INLINE_ITEM_ICON_IN_ITEM)
                {
                    MMI_fixed_icontext_menuitems[i].ext_flags |= UI_MENUITEM_EXT_SHOW_INDICATOR;
                }
            }

        #ifdef __MMI_WALLPAPER_ON_BOTTOM__
            if ((WGUI_INLINE_ITEM_TYPE(i) == INLINE_ITEM_TYPE_FULL_SCREEN_EDIT
                || WGUI_INLINE_ITEM_TYPE(i) == INLINE_ITEM_IMAGE_TEXT_TYPE)
                && (wgui_inline_items[i].flags & INLINE_ITEM_OPEN))
            {
                dm_get_scr_bg_opacity(&inline_edit_scr_bg_opacity);
                dm_set_scr_bg_opacity((U8)(current_MMI_theme->bg_opacity_low));    
                inline_opacity_changed = TRUE;
            #if !defined(GUI_EDITOR_SHOW_TITLE)
                full_screen_edit_open = 1;
            #endif /* !defined(GUI_EDITOR_SHOW_TITLE) */
            }
        #endif /* __MMI_WALLPAPER_ON_BOTTOM__ */ 

		if ((WGUI_INLINE_ITEM_TYPE(i) == INLINE_ITEM_TYPE_DATE) 
			|| (WGUI_INLINE_ITEM_TYPE(i) == INLINE_ITEM_TYPE_TIME)
			|| (WGUI_INLINE_ITEM_TYPE(i) == INLINE_ITEM_TYPE_IP4_EDIT))
		{
		    MMI_fixed_icontext_menuitems[i].flags |= UI_MENUITEM_DISABLE_BACKGROUND_ALWAYS;
		}

        #if defined(__MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__) && !(defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__)) 
            if (((WGUI_INLINE_ITEM_TYPE(i) == INLINE_ITEM_TYPE_TEXT_EDIT)
                 || (WGUI_INLINE_ITEM_TYPE(i) == INLINE_ITEM_TYPE_FULL_SCREEN_EDIT)
                 || (WGUI_INLINE_ITEM_TYPE(i) == INLINE_ITEM_TYPE_DATE)
                 || (WGUI_INLINE_ITEM_TYPE(i) == INLINE_ITEM_TYPE_SELECT)
                 || (WGUI_INLINE_ITEM_TYPE(i) == INLINE_ITEM_TYPE_TIME)
                 || (WGUI_INLINE_ITEM_TYPE(i) == INLINE_ITEM_TYPE_TIME_PERIOD)
                 || (WGUI_INLINE_ITEM_TYPE(i) == INLINE_ITEM_TYPE_DOW_SELECT)
                 || (WGUI_INLINE_ITEM_TYPE(i) == INLINE_ITEM_TYPE_IP4_EDIT)
                 || (WGUI_INLINE_ITEM_TYPE(i) == INLINE_ITEM_TYPE_COLOR_SELECT))
                && (IsInlineItemDefaultTextEnable()))
            {
                MMI_fixed_icontext_menuitems[i].ext_flags |= UI_MENUITEM_EXT_SHOW_IN_ROUNDED_RECT;
            }
        #endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 

        }    
    
    wgui_setup_inline_edit_themes();
    wgui_n_inline_items = number_of_items;
    register_inline_fixed_list_keys();
    resize_fixed_icontext_menuitems(0, MMI_MENUITEM_HEIGHT);

    if (list_of_icons == NULL)
    {
        set_fixed_icontext_positions(2, 0, 1, 0);
    }
    else
    {
        set_fixed_icontext_positions(GUI_ICONTEXT_MENUITEM_TEXT_X, 0, GUI_ICONTEXT_MENUITEM_ICON_X, 0);
    }

    /* Inline screens use Pop up description components to get x,y,width,height   */
//#if(UI_ENABLE_POP_UP_DESCRIPTIONS)
    MMI_fixed_list_menu.gui_display_pop_up_description = handle_inline_item_location;
#ifdef __MMI_UI_HINTS_IN_MENUITEM__
    MMI_fixed_list_menu.gui_get_current_pop_up_description_string = UI_dummy_get_current_pop_up_description_string;
#endif 
//#endif /* (UI_ENABLE_POP_UP_DESCRIPTIONS) */ 

    register_fixed_list_highlight_handler(highlight_handler);
    register_fixed_list_unhighlight_handler(unhighlight_handler);

    /* Override default font */
    MMI_fixed_icontext_menuitem.text_font = &MMI_medium_font;
    MMI_fixed_text_menuitem.text_font = &MMI_medium_font;

    wgui_title_disable_menu_shortcut_display(MMI_TRUE);
    MMI_current_menu_type = LIST_MENU;
    h_flag = set_list_menu_category_history(history_id, history_buffer);
    h = (list_menu_category_history*) history_buffer;
    if (h_flag && (h->num_items == MMI_fixed_list_menu.n_items))
    {
        U32 *flags;
        S32 s = sizeof(list_menu_category_history);
        s32 save_n;
        S32 save_last_display_item_index;

        s = (s + 3) / 4;
        s *= 4;

        if(cui_inline_is_current_cui() == MMI_FALSE)
        {
            flags = (U32*) (history_buffer + s);

            wgui_inline_list_menu_changed = (U8) * flags;
        }
        else
        {   
            S32 index = cui_inline_convert_id_to_index(g_cui_inline_current_instance->gid, g_cui_inline_current_instance->highlight_item_id);
            
            MMI_fixed_list_menu.highlighted_item = index ;
        }

        if((cui_inline_is_current_cui()) &&
           (g_cui_inline_current_instance->history_item_id != g_cui_inline_current_instance->cui_inline_items[MMI_fixed_list_menu.highlighted_item].common_data.item_id)
          )
        {
            wgui_current_history_buffer = NULL;
        }
        else
        {
        wgui_current_history_buffer = (U8*) (history_buffer + s + sizeof(U32));
        }
        save_n = MMI_fixed_list_menu.first_displayed_item;
        save_last_display_item_index = MMI_fixed_list_menu.last_displayed_item;
        
        fixed_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
        if (save_n != MMI_fixed_list_menu.first_displayed_item)
        {
	    if(cui_inline_is_current_cui())
	    {
                if((MMI_fixed_list_menu.highlighted_item <= (save_n + MMI_fixed_list_menu.displayed_items - 1)) &&
                   (MMI_fixed_list_menu.highlighted_item >= save_n)
                  )
		{
		    MMI_fixed_list_menu.first_displayed_item = save_n;
                    MMI_fixed_list_menu.last_displayed_item = save_last_display_item_index;
		}
	    }
            else
            {
                MMI_fixed_list_menu.first_displayed_item = save_n;
                MMI_fixed_list_menu.last_displayed_item = save_last_display_item_index;
            }
        }

    #if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
    #if defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__)
        for (i = 0; (i < number_of_items) && (i < MAX_INLINE_ITEMS); i++)
        {
            if ((wgui_inline_items[i].flags & 0xff) == INLINE_ITEM_TYPE_MULTI_LINE_EDIT)
            {
                wgui_inline_items[i].flags |= INLINE_ITEM_OPEN;
            }
        }
    #endif
    #endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 
    }
    else
    {
        wgui_current_history_buffer = NULL;        
#if defined (__MMI_INLINE_ITEM_IMAGETEXT__)        
        inline_image_text_edit_flag = 0;
#endif
        fixed_list_goto_item_no_redraw(highlighted_item);
    }
    current_fixed_icontext_menuitem_theme = saved_themedata1;
    current_fixed_list_menu_theme = saved_themedata2;

#ifdef __MMI_TOUCH_SCREEN__
    gui_vertical_scrollbar_register_get_diff(&(MMI_fixed_list_menu.vbar), wgui_inline_get_item_height_for_scroll_bar);
#endif

}


#ifdef __MMI_TOUCH_SCREEN__

/*****************************************************************************
 * FUNCTION
 *  UI_dummy_inline_item_pen_function
 * DESCRIPTION
 *  dummy pen function
 * PARAMETERS
 *  pen_event       [IN]    pen event    
 *  x               [IN]    pen x position    
 *  y               [IN]    pen y position    
 *  item_event      [IN]    inline pen enum         
 * RETURNS
 *  BOOL
 *****************************************************************************/
BOOL UI_dummy_inline_item_pen_function(
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_inline_item_pen_enum *item_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(pen_event);
    UI_UNUSED_PARAMETER(x);
    UI_UNUSED_PARAMETER(y);
    *item_event = GUI_INLINE_ITEM_PEN_NONE;
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_inline_handle_pen_event_by_item
 * DESCRIPTION
 *  handle pen event by inline item
 * PARAMETERS
 *  m                   [IN]    fixed lit menu pointer         
 *  pen_event           [IN]    pen event    
 *  x                   [IN]    pen x position    
 *  y                   [IN]    pen y position    
 *  inline_event        [IN]    inline pen enum     
 * RETURNS
 *  BOOL
 *****************************************************************************/
static BOOL gui_inline_handle_pen_event_by_item(
                fixed_list_menu *m,
                mmi_pen_event_type_enum pen_event,
                S16 x,
                S16 y,
                gui_inline_pen_enum *inline_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_inline_item_pen_enum item_event;
    BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(m);

    *inline_event = GUI_INLINE_PEN_NONE;

    ret = wgui_current_inline_item_pen_function(pen_event, x, y, &item_event);
    if (ret)
    {
        if (item_event == GUI_INLINE_ITEM_PEN_NEED_REDRAW_MENU)
        {
            *inline_event = GUI_INLINE_PEN_NEED_REDRAW;
        }
        else if (item_event == GUI_INLINE_ITEM_PEN_NEED_REDRAW_ITEM)
        {
            redraw_current_inline_item();
        }
        else if (item_event == GUI_INLINE_ITEM_PEN_SELECTED)
        {
            *inline_event = GUI_INLINE_PEN_ITEM_SELECTED;
        }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gui_inline_scroll_by_pen
 * DESCRIPTION
 *  handle scrolling by pen event
 * PARAMETERS
 *  m                   [IN]     fixed list menu pointer    
 *  x                   [IN]     pen x position   
 *  y                   [IN]     pen y position   
 *  first_displayed     [IN]     first displayed menu item   
 *  inline_event        [IN]     inline pen enum    
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_inline_scroll_by_pen(
                fixed_list_menu *m,
                S16 x,
                S16 y,
                S32 first_displayed_offset_y,
                gui_inline_pen_enum *inline_event,
                mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_displayed;
    S32 iwidth, iheight;
    S32 total_height, i;
    S32 first_displayed = 0;
    S32 max_first_displayed = 0;

    MMI_BOOL history_stored;
    U8 gui_buffer[MAX_GUI_BUFFER];
    S32 current_highlight_index = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    total_height = 0;
    for (i = first_displayed; i < m->n_items; i++)
    {
        if (i == m->highlighted_item)
        {
            m->current_displayed_item = -1;
        }
        else
        {
            m->current_displayed_item = i;
        }
        m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);
        total_height += iheight;
        if (total_height > first_displayed_offset_y)
        {
            first_displayed = i;
            break;
        }
    }
    if( total_height <= first_displayed_offset_y)
    {
        first_displayed = m->n_items - 1;
    }
    total_height = 0;
    for(i = m->n_items - 1; i >= 0; i--)
    {
        if (i == m->highlighted_item)
	  {
            m->current_displayed_item = -1;
        }
        else
	  {
            m->current_displayed_item = i;
	  }
        m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);
            
        total_height +=iheight;
        if(total_height > m->height)
        {
           max_first_displayed = i + 1;     
           break;
        }
    }
    if(max_first_displayed < first_displayed)
    {
        first_displayed = max_first_displayed;
    }

    if (first_displayed == m->first_displayed_item)
    {
        *inline_event = GUI_INLINE_PEN_NONE;
        return;
    }
    current_highlight_index = m->highlighted_item;
    /* 
     * Sometimes the inline editor is scrolled (m->first_displayed is changed) but
     * the highlighted item (m->highlighted_item) stays unchanged.
     * 
     * In this case, we should keep the context of inline item unchanged 
     * (e.g. editor cursor & input method), and we put the information in gui_buffer[].
     *
     * Reference: wgui_get_inline_history(), wgui_inline_edit_get_current_item_history(), 
     * and wgui_current_history_buffer.
     */
    history_stored = MMI_TRUE;
    switch (wgui_current_inline_item_type)
    {
#if defined(__MMI_INLINE_ITEM_DATE__)    
        case INLINE_ITEM_TYPE_DATE:               
            inline_date_edit_get_history(gui_buffer);
            break;
#endif            

#if defined(__MMI_INLINE_ITEM_TIME__)
        case INLINE_ITEM_TYPE_TIME:               
            inline_time_edit_get_history(gui_buffer);
            break;
#endif

#if defined (__MMI_INLINE_ITEM_TIME_PEROID__)   
        case INLINE_ITEM_TYPE_TIME_PERIOD:
            inline_time_period_edit_get_history(gui_buffer);
            break;
#endif

#if defined (__MMI_INLINE_ITEM_IP4__)
        case INLINE_ITEM_TYPE_IP4_EDIT:            
            inline_IP4_edit_get_history(gui_buffer);
            break;
#endif

#if defined(__MMI_INLINE_ITEM_DOW__)
        case INLINE_ITEM_TYPE_DOW_SELECT:  
            inline_DOW_select_get_history(gui_buffer);
            break;
#endif

#if defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__)            
        case INLINE_ITEM_TYPE_MULTI_LINE_EDIT:
        case INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY:
            inline_multi_line_edit_get_history(gui_buffer);
            break;
#endif

        default:
            history_stored = MMI_FALSE;
    }

    /* Finalize current editing. */
    complete_inline_item_edit();

    /*
     * Note that m->first_displayed_item might be changed inside m->item_highlighted() 
     * (which is typically wgui_inline_edit_default_list_highlight_handler())
     * if INLINE_ITEM_FOLLOW_DOWN or INLINE_ITEM_FOLLOW_UP is set on the highlighed item. 
     * 
     * inline item handler is invoked from handle_inline_item_location() (typically from gui_show_fixed_list_menu())
     */

    *inline_event = GUI_INLINE_PEN_NONE;

    if(cui_inline_is_current_cui())
    {
        cui_inline_lock_main_screen(g_cui_inline_current_instance->gid);
    }

    /* Scroll down */
    if (first_displayed > m->highlighted_item)
    {
#if defined (__MMI_INLINE_ITEM_MULTILINE_READ_ONLY__)
        /* Revise for multiline. */
        if(((wgui_inline_items[m->n_items - 1].flags & 0xff) == INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY) &&
           (first_displayed == m->n_items - 1)
          )
        {
            m->first_displayed_item = first_displayed;
        }
#endif        
        m->flags |= UI_LIST_MENU_FIRST_SHIFT_HIGHLIGHTED_ITEM;
        inline_fixed_list_goto_item(first_displayed, MMI_FALSE);
        m->flags &= ~UI_LIST_MENU_FIRST_SHIFT_HIGHLIGHTED_ITEM;
    }
    else
    {
        /* Compute last_displayed */
        last_displayed = m->n_items - 1;
        total_height = 0;
        for (i = first_displayed; i < m->n_items; i++)
        {
            if (i == m->highlighted_item)
            {
                m->current_displayed_item = -1;
            }
            else
            {
                m->current_displayed_item = i;
            }
            m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);
            total_height += iheight;
            if (total_height > m->height + 1)
            {
                last_displayed = i - 1;
                break;
            }
        }

        /* Scroll up */
        if (last_displayed < m->highlighted_item)
        {
#if defined (__MMI_INLINE_ITEM_MULTILINE_READ_ONLY__)        
            if(((wgui_inline_items[m->n_items - 1].flags & 0xff) == INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY) &&
               (last_displayed == m->n_items - 2) &&  /* last_displayed item is above ml_rdonly_item */
               ((wgui_inline_items[m->highlighted_item].flags & 0xff) == INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY) 
              )
            {  
                /* 
                  It means ml_rdonly_item is exist, so new highlight item(last_displayed item) shouldn't
                pull above all item out on screen.
                */
                total_height = 0;
                for(i = first_displayed; i <= last_displayed; i++)
                {
                    if (i == m->highlighted_item)
                    {
                        m->current_displayed_item = -1;
                    }
                    else
                    {
                        m->current_displayed_item = i;
                    }
                    m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);
                    total_height += iheight;
                }
                if(total_height < m->height)    /* Means ml_rdonly_item is still shown on screen. */
                {
                    if (history_stored)
                    {
                        wgui_current_history_buffer = gui_buffer;
                    }
                    gui_lock_double_buffer();

                    m->item_unhighlighted(m->highlighted_item);
                    wgui_inline_item_highlighted_index = -1;
                    m->item_highlighted(m->highlighted_item);
                    m->first_displayed_item = first_displayed;
                    m->last_displayed_item = last_displayed;
                    redraw_fixed_list();
                    
                    if (history_stored)
                    {
                    /* Failsafe step because 'gui_buffer' is local variable. 
                    and it's lifecyle is inside the current function */
                    wgui_current_history_buffer = NULL;
                    }
                    gui_unlock_double_buffer();
                    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
                }
                else
                {
                    m->flags |= UI_LIST_MENU_LAST_SHIFT_HIGHLIGHTED_ITEM;
                    inline_fixed_list_goto_item(last_displayed, MMI_TRUE);
                    m->flags &= ~UI_LIST_MENU_LAST_SHIFT_HIGHLIGHTED_ITEM;
                }
            }
            else
#endif                
            {
                /* Pull above item out on screen. */
            m->flags |= UI_LIST_MENU_LAST_SHIFT_HIGHLIGHTED_ITEM;
            inline_fixed_list_goto_item(last_displayed, MMI_TRUE);
            m->flags &= ~UI_LIST_MENU_LAST_SHIFT_HIGHLIGHTED_ITEM;
        }
        }
        else
        {
            S32 old_first_displayed;

            old_first_displayed = m->first_displayed_item;

            if (history_stored)
            {
                /* 
                 * Restore the context of the original highlighted item.
                 *
                 * Ex: Assume it is an inline text edit, we need to setup history
                 * buffer here; otherwise the virtual keyboard type is reset,
                 * and the list menu height might be changed.                     
                 *
                 * However, the current code logic assumes that menu height should
                 * stay unchanged after m->item_highlighted(). 
                 */
                wgui_current_history_buffer = gui_buffer;
            }
            
            gui_lock_double_buffer();

            m->item_unhighlighted(m->highlighted_item);
            m->first_displayed_item = first_displayed;
            m->last_displayed_item = last_displayed;
            wgui_inline_item_highlighted_index = -1;
            m->item_highlighted(m->highlighted_item);

            /* 
             * m->item_highlighted() might change m->first_displayed_item again if 
             * a. INLINE_ITEM_FOLLOW_DOWN and INLINE_ITEM_FOLLOW_UP is set to highlighted item.
             * b. m->first_displayed_item is incremented to display inline caption item
             *
             * Usually we can test the scenario in MMI Todo screen.
             */
            if (m->first_displayed_item == old_first_displayed)
            {
                /* 
                 * In this case, m->first_displayed_item != first_displayed 
                 * because there are other "restrictions" that set 
                 * m->first_displayed_item to the original value.
                 *
                 * It happens in many inline editor screens in MMI. 
                 */
                if (first_displayed < m->first_displayed_item)
                {
                    /*
                     * In this case, we want to scroll up the menu but fail to do so.
                     *
                     * For example, the last displayed item is currently highlighted, and 
                     * the item before the last displayed item is an inline caption.
                     * If we scroll up by one item, The inline caption is highlighted although
                     * it cannot be highlighted, and then highlight is set to the next 
                     * inline item, which is the original highlighted one. 
                     * As a result, the inline editor is not scrolled at all.
                     * 
                     * In order to solve this, we scroll "one" more inline item up.
                     */
                    m->flags |= UI_LIST_MENU_LAST_SHIFT_HIGHLIGHTED_ITEM;
                    inline_fixed_list_goto_item(last_displayed - 1, MMI_TRUE);
                    m->flags &= ~UI_LIST_MENU_LAST_SHIFT_HIGHLIGHTED_ITEM;
                }
                else
                {
                    /* Similar to previous case */
                    /* There are some problems:
                       1 If m->highlighted_item == 5, and old_first_displayed ==  m->first_displayed_item == 2(means not change list present),
                    first_displayed == 3, then the highlight item is changed from 5 to 3(because inline_fixed_list_goto_item(first_displayed + 1) ).
                       2 if(current_highlight_index != first_displayed + 1) can not work, because supposed this scenario:
                    a list contains only one ip4, and many caption. Then, still ip4 is highlight,but it lost its guibuffer.
                       3 we can not think that first_displayed must be equal to m->highlighted_item.
                    */
                    
                    /* first_displayed is list give inline first index */
                    /* 
                       example: first index is caption, 2th index is enable item and highlight, 3th is caption, 4th is enabler item.
                       when pen drags scroll bar, pen move 1 item distance, but inline will jump 2 items distance,
                       because highlight will shift to 4th item, and 4th item is first display item.
                    */
                    if((!((pen_event == MMI_PEN_EVENT_MOVE) && 
                          ((wgui_inline_items[first_displayed + 1].flags & 0xff) == INLINE_ITEM_TYPE_CAPTION))
                       ) ||
                       (m->last_displayed_item + 1 == m->n_items - 1))
                    {
                    gui_lock_double_buffer();
                    m->flags |= UI_LIST_MENU_FIRST_SHIFT_HIGHLIGHTED_ITEM;
                    wgui_current_history_buffer = NULL;
                    inline_fixed_list_goto_item(first_displayed + 1, MMI_FALSE);
                    m->flags &= ~UI_LIST_MENU_FIRST_SHIFT_HIGHLIGHTED_ITEM;
                    if(current_highlight_index != m->highlighted_item)
                    {
                        if (history_stored)
                        {
                            wgui_current_history_buffer = NULL;
                            wgui_inline_item_handled = 0;
                            redraw_fixed_list();                                                    
                        }            
                    }
                    
                    gui_unlock_double_buffer ();
                    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
                }
                    else
                    {
                        gui_lock_double_buffer();
                        redraw_fixed_list();
                        gui_unlock_double_buffer();
                        gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
                    }
            }
            }
            else
            {
                gui_lock_double_buffer();

                redraw_fixed_list();
                
                redraw_current_inline_item();
                /* 
                 * Redraw virtual keyboard. 
                 * There is a small gap (e.g. 2 pixels) between fixed list and virtual keyboard
                 * and some inline item draw outside the list, we need to clear the gap by
                 * redrawing virtual keyboard.
                 */

                gui_unlock_double_buffer();
                gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
            }

            if (history_stored)
            {
                /* Failsafe step because 'gui_buffer' is local variable. 
                   and it's lifecyle is inside the current function */
                wgui_current_history_buffer = NULL;
            }
            
            /* Add it for Inline CUI, because highlight handler will blt softkey */
            gui_unlock_double_buffer();
            gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
        }
    }
    /* 
       Because switch to selector might redraw screen, thus pen event will be reset when switch screen,
    so scroll bar can not be dragged anymore. 
       So we prohibit to redraw screen when drag scroll bar. 
    */
    if(cui_inline_is_current_cui())
    {
        cui_inline_unlock_main_screen(g_cui_inline_current_instance->gid);
    }

    /* Because we do not always follow the value of 'first_displayed',
       we need to adjust scrollbar again. */
    gui_vertical_scrollbar_reconfigure_pen_value(&m->vbar, x, y);
}


/*****************************************************************************
 * FUNCTION
 *  gui_inline_translate_pen_event
 * DESCRIPTION
 *  translate pen event of inline edit
 * PARAMETERS
 *  m                   [IN]       fixed list menu pointer  
 *  pen_event           [IN]       pen event 
 *  x                   [IN]       pen x position  
 *  y                   [IN]       pen y position 
 *  inline_event        [IN]       inline pen enum  
 * RETURNS
 *  BOOL
 *****************************************************************************/
BOOL gui_inline_translate_pen_event(
        fixed_list_menu *m,
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_inline_pen_enum *inline_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(GUI_EDITOR_SHOW_TITLE)
    S32 ix, iy, width, height;
#endif /* defined(GUI_EDITOR_SHOW_TITLE) */
    BOOL ret = MMI_TRUE;
    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *inline_event = GUI_INLINE_PEN_NONE;

    if (pen_event == MMI_PEN_EVENT_DOWN)
    {
        pen_down_x = -1;
        pen_down_y = -1;
    
        wgui_inline_pen_down_item_index = -1;


    #if defined(GUI_EDITOR_SHOW_TITLE)    
        if (wgui_current_inline_item_type == INLINE_ITEM_TYPE_FULL_SCREEN_EDIT)
        {
            wgui_title_get_area(&ix, &iy, &width, &height);

            if (PEN_CHECK_BOUND(x, y, ix, iy, width, height))
            {
                return MMI_TRUE;
            }
        }
    #endif /* defined(GUI_EDITOR_SHOW_TITLE) */


        if (PEN_CHECK_BOUND(x, y, m->x, m->y, m->width, m->height))
        {
            if (wgui_current_inline_item_type == INLINE_ITEM_TYPE_FULL_SCREEN_EDIT)
            {
                /* Redirect pen events to editor */
                wgui_inline_pen_handler_type = WGUI_INLINE_PEN_HANDLER_FULLSCREEN_EDITOR;
                /* Handled by editor */
            }
            else if (!((m->flags & UI_LIST_MENU_DISABLE_SCROLLBAR) ||
                       ((m->flags & UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR) &&
                       (m->displayed_items >= m->n_items))) &&
                     gui_vertical_scrollbar_translate_pen_event(
                        &m->vbar,
                        pen_event,
                        x,
                        y,
                        &scrollbar_event,
                        &scrollbar_param))
            {
                wgui_inline_pen_handler_type = WGUI_INLINE_PEN_HANDLER_SCROLLBAR;
                if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
                {
                    gui_inline_scroll_by_pen(m, x, y, scrollbar_param._u.i, inline_event, pen_event);
                }
            }
            else
            {

                S32 item_index,high_index = 0, real_down_index = 0;
                BOOL is_pen_inside_menu;

                is_pen_inside_menu = gui_fixed_list_menu_translate_pen_position(m, y, &item_index);

                real_down_index = item_index;

                if(item_index != wgui_inline_item_highlighted_index)
                {
                    high_index = wgui_inline_item_highlighted_index;

                    /* if item_index == 0, it will search enable highlight item from index == 1, and 
                    if wgui_inline_edit_is_able_to_switch_highlight() == MMI_FALSE, it means no other can highlight,
                    so the process is correct.
                    */
                    if(item_index != 0)
                    {
                        wgui_inline_item_highlighted_index = item_index - 1; 
                    }
                    else
                    {
                    wgui_inline_item_highlighted_index = item_index;
                    }
                    
                    if(wgui_inline_edit_is_able_to_switch_highlight(1) == MMI_FALSE)
                    {
                        wgui_inline_item_highlighted_index = high_index;
                        wgui_inline_pen_handler_type = WGUI_INLINE_PEN_HANDLER_NONE;
                        return MMI_TRUE;	
                    }	
                    else
                    {
                        wgui_inline_item_highlighted_index = high_index;
                    }	 
                }
                
                high_index = wgui_inline_edit_get_next_highlight_index(item_index);
                if ((item_index != wgui_inline_item_highlighted_index) &&
                    (high_index == wgui_inline_item_highlighted_index))
                {
                    wgui_inline_pen_handler_type = WGUI_INLINE_PEN_HANDLER_NONE;
                    return MMI_TRUE;
                }
       
                if (item_index != high_index)
                {
                    item_index = high_index;
                }
                wgui_inline_pen_down_item_index = item_index;

            #ifdef __MMI_INSCREEN_MULTILINE_TEXTBOX__
            #if defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__)
                /* Special case: inline multiline is larger than its corresponding menu item */
                if (!is_pen_inside_menu &&
                    item_index == m->n_items - 1 &&
                    (wgui_inline_items[item_index].flags & 0xff) == INLINE_ITEM_TYPE_MULTI_LINE_EDIT ||
                    (wgui_inline_items[item_index].flags & 0xff) == INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY)
                {
                    is_pen_inside_menu = MMI_TRUE;
                }
            #endif
            #endif /* __MMI_INSCREEN_MULTILINE_TEXTBOX__ */ 

            #ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
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

                if (!is_pen_inside_menu)
                {
                    wgui_inline_pen_handler_type = WGUI_INLINE_PEN_HANDLER_NONE;
                }
                else if (item_index != m->highlighted_item)
                {
                    if ((wgui_inline_items[item_index].flags & 0xff) == INLINE_ITEM_TYPE_CAPTION &&
                        item_index == MMI_fixed_list_menu.n_items - 1)
                    {
                        /* Clicking on the last item that is inline caption. We should not switch to it; otherwise, it goes to the first item */
                        wgui_inline_pen_handler_type = WGUI_INLINE_PEN_HANDLER_NONE;
                    }
                    else if ((wgui_inline_items[item_index].flags & 0xff) == INLINE_ITEM_TYPE_CAPTION &&
                             item_index == MMI_fixed_list_menu.n_items - 2 &&
                             (wgui_inline_items[item_index + 1].flags & INLINE_ITEM_DISABLED))
                    {
                        /* The last item is disabled. Clicking on the inline caption before it */
                        wgui_inline_pen_handler_type = WGUI_INLINE_PEN_HANDLER_NONE;
                    }
                    else if (!(wgui_inline_items[item_index].flags & INLINE_ITEM_DISABLED))
                    {
                        wgui_inline_pen_handler_type = WGUI_INLINE_PEN_HANDLER_SWITCH_ITEM;
#ifdef __MMI_FTE_SUPPORT__
                        if((((wgui_inline_items[item_index].flags & 0xFF) == INLINE_ITEM_TYPE_DISPLAY_ONLY) ||
                           ((wgui_inline_items[item_index].flags & 0xFF) == INLINE_ITEM_TYPE_FULL_SCREEN_EDIT) ||
                           ((wgui_inline_items[item_index].flags & 0xFF) == INLINE_ITEM_TYPE_TEXT_EDIT) ||
                           ((wgui_inline_items[item_index].flags & 0xFF) == INLINE_ITEM_TYPE_SELECT)
                           ) && (item_index >= m->first_displayed_item)
                          )
                        {
                            if(inline_fte_displayonly_item_pen_handler(pen_event, x, y, inline_event, (U16)item_index) == MMI_FALSE)
                            {
                             //   wgui_inline_pen_handler_type = WGUI_INLINE_PEN_HANDLER_NONE;
                            }
                        }
                        if((wgui_inline_items[m->highlighted_item].flags & 0xff) == INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY)
                        {
                            mmi_pen_point_struct point = {0, 0};
                            gui_input_box_ssp_pen_translate(point, MMI_PEN_EVENT_ABORT);
                        }
#endif
                        pen_down_x = x;
                        pen_down_y = y;
                    }
                    else
                    {
                        wgui_inline_pen_handler_type = WGUI_INLINE_PEN_HANDLER_NONE;
                    }
                }
                else
                {
                    /*
                     * Because the inline item (e.g. horizontal select) might be smaller than the menu item  
                     * * the pen handler might return MMI_FALSE.
                     * *
                     * * Note: It can be extended to handle SetInlineItemActivation() (for fullscreen editor), 
                     * * but we do not handle it deliberately.
                     */
#ifdef __MMI_FTE_SUPPORT__
                    if(((wgui_inline_items[item_index].flags & 0xFF) == INLINE_ITEM_TYPE_DISPLAY_ONLY) ||
                       ((wgui_inline_items[item_index].flags & 0xFF) == INLINE_ITEM_TYPE_FULL_SCREEN_EDIT) ||
                       ((wgui_inline_items[item_index].flags & 0xFF) == INLINE_ITEM_TYPE_TEXT_EDIT) ||
                       ((wgui_inline_items[item_index].flags & 0xFF) == INLINE_ITEM_TYPE_SELECT)
                      )
                    {
                        wgui_inline_pen_handler_type = WGUI_INLINE_PEN_HANDLER_CURRENT_ITEM;
                        inline_fte_displayonly_item_pen_handler(pen_event, x, y, inline_event, (U16)item_index);
                    }
                    else 
#endif
                    if (gui_inline_handle_pen_event_by_item(m, pen_event, x, y, inline_event))
                    {
                        wgui_inline_pen_handler_type = WGUI_INLINE_PEN_HANDLER_CURRENT_ITEM;
                    }
                    else
                    {
                        /*
                         * After long press animation, invoke left softkey handler. 
                         * * Tricky: it only apply to certain inline item types.
                         */
                        S32 type = wgui_inline_items[wgui_inline_item_highlighted_index].flags & 0xff;

                        if ((
#ifndef __MMI_FTE_SUPPORT__                            
                                type == INLINE_ITEM_TYPE_FULL_SCREEN_EDIT ||
                                type == INLINE_ITEM_TYPE_DISPLAY_ONLY ||
#if defined (__MMI_INLINE_ITEM_MULTILINE_READ_ONLY__)                                
                                type == INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY|| 
#endif                                
                                type == INLINE_ITEM_TYPE_SELECT ||
                                type == INLINE_ITEM_TYPE_TEXT_EDIT ||
#endif      
                                type == INLINE_ITEM_IMAGE_TEXT_TYPE ) &&
                            ((get_softkey_label(MMI_LEFT_SOFTKEY) != NULL) || (get_softkey_icon(MMI_LEFT_SOFTKEY) != NULL))  
                           )
                        {
                            gui_wait_longpress_enum w;

                            w = gui_pen_wait_longpress(MMI_PEN_EVENT_DOWN, x, y);
                            if (w == GUI_WAIT_LONGPRESS_INVALID)
                            {
                                wgui_inline_pen_handler_type = WGUI_INLINE_PEN_HANDLER_NONE;
                                
                            }
                            else
                            {
                                wgui_inline_pen_handler_type = WGUI_INLINE_PEN_HANDLER_WAIT_LONGPRESS;
                            }
                        }
                        else
                        {
                            wgui_inline_pen_handler_type = WGUI_INLINE_PEN_HANDLER_NONE;
                        }
                    }
                }
#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
/* under construction !*/
#endif
            }
        }
        else
        {
            ret = MMI_FALSE;
        }

    }
    else
    {
        if (!((m->flags & UI_LIST_MENU_DISABLE_SCROLLBAR) ||
              ((m->flags & UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR) &&
               (m->displayed_items >= m->n_items)
              )
             ) && 
            (wgui_inline_pen_handler_type == WGUI_INLINE_PEN_HANDLER_SCROLLBAR)
           )
        {
            gui_vertical_scrollbar_translate_pen_event(&m->vbar, pen_event, x, y, &scrollbar_event, &scrollbar_param);
            if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
            {
                if(pen_event != MMI_PEN_EVENT_UP)
                {
                gui_inline_scroll_by_pen(m, x, y, scrollbar_param._u.i, inline_event, pen_event);
            }
        }
        }
        else if(wgui_inline_pen_handler_type == WGUI_INLINE_PEN_HANDLER_SCROLLBAR)
        {
            gui_vertical_scrollbar_translate_pen_event(&m->vbar, pen_event, x, y, &scrollbar_event, &scrollbar_param);	
        }
        else if (wgui_inline_pen_handler_type == WGUI_INLINE_PEN_HANDLER_WAIT_LONGPRESS)
        {
            gui_wait_longpress_enum w;

            w = gui_pen_wait_longpress(pen_event, x, y);
            if (w == GUI_WAIT_LONGPRESS_INVALID)
            {
                wgui_inline_pen_handler_type = WGUI_INLINE_PEN_HANDLER_NONE;
            }
            else if (w == GUI_WAIT_LONGPRESS_READY)
            {
                *inline_event = GUI_INLINE_PEN_ITEM_SELECTED;
                /* ignore subsequent pen events */
                wgui_inline_pen_handler_type = WGUI_INLINE_PEN_HANDLER_NONE;
            }       
        }
        else if (wgui_inline_pen_handler_type == WGUI_INLINE_PEN_HANDLER_CURRENT_ITEM)
        {
#ifdef __MMI_FTE_SUPPORT__
            if(((wgui_inline_items[wgui_inline_pen_down_item_index].flags & 0xFF) == INLINE_ITEM_TYPE_DISPLAY_ONLY) 
				|| ((wgui_inline_items[wgui_inline_pen_down_item_index].flags & 0xFF) == INLINE_ITEM_TYPE_FULL_SCREEN_EDIT) 
                || ((wgui_inline_items[wgui_inline_pen_down_item_index].flags & 0xFF) == INLINE_ITEM_TYPE_TEXT_EDIT)
                || ((wgui_inline_items[wgui_inline_pen_down_item_index].flags & 0xFF) == INLINE_ITEM_TYPE_SELECT)
              )
            {
                inline_fte_displayonly_item_pen_handler(pen_event, x, y, inline_event, (U16)wgui_inline_pen_down_item_index);
            }
            else 
            {
                gui_inline_handle_pen_event_by_item(m, pen_event, x, y, inline_event);
            }
#else
            gui_inline_handle_pen_event_by_item(m, pen_event, x, y, inline_event);
#endif
        }
#if 0        
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif        
        else if (wgui_inline_pen_handler_type == WGUI_INLINE_PEN_HANDLER_SWITCH_ITEM)
        {
            if (pen_event == MMI_PEN_EVENT_UP)
            {
                S32 item_index;

                gui_fixed_list_menu_translate_pen_position(m, y, &item_index);
                if (item_index == wgui_inline_pen_down_item_index)
                {
                    gdi_layer_lock_frame_buffer();
                    complete_inline_item_edit();    /* Finalize current editing */
                    /* Automatically select the next item if it's inline caption item */
                    inline_fixed_list_goto_item(item_index, MMI_FALSE);
                    gdi_layer_unlock_frame_buffer();
                    gdi_lcd_repaint_all();                    
                }
                else if (pen_down_x == x && pen_down_y == y)
                {
                    gdi_layer_lock_frame_buffer();
                    complete_inline_item_edit();    /* Finalize current editing */
                    /* Automatically select the next item if it's inline caption item */
                    inline_fixed_list_goto_item(wgui_inline_pen_down_item_index, MMI_FALSE);
                    gdi_layer_unlock_frame_buffer();
                    gdi_lcd_repaint_all();

                    pen_down_x = -1;
                    pen_down_y = -1;
                }
#ifdef __MMI_FTE_SUPPORT__
                else if(((wgui_inline_items[wgui_inline_pen_down_item_index].flags & 0xFF) == INLINE_ITEM_TYPE_DISPLAY_ONLY) ||
                        ((wgui_inline_items[wgui_inline_pen_down_item_index].flags & 0xFF) == INLINE_ITEM_TYPE_FULL_SCREEN_EDIT) ||
                        ((wgui_inline_items[wgui_inline_pen_down_item_index].flags & 0xFF) == INLINE_ITEM_TYPE_TEXT_EDIT) ||
                        ((wgui_inline_items[wgui_inline_pen_down_item_index].flags & 0xFF) == INLINE_ITEM_TYPE_SELECT)
                       )
                {
                    inline_fte_displayonly_item_pen_handler(pen_event, x, y, inline_event, (U16)wgui_inline_pen_down_item_index);
                }
#endif
                wgui_inline_pen_handler_type = WGUI_INLINE_PEN_HANDLER_NONE;
            }
#ifdef __MMI_FTE_SUPPORT__
            else if(pen_event == MMI_PEN_EVENT_MOVE)
            {
                if(((wgui_inline_items[wgui_inline_pen_down_item_index].flags & 0xFF) == INLINE_ITEM_TYPE_DISPLAY_ONLY) ||
                   ((wgui_inline_items[wgui_inline_pen_down_item_index].flags & 0xFF) == INLINE_ITEM_TYPE_FULL_SCREEN_EDIT) ||
                   ((wgui_inline_items[wgui_inline_pen_down_item_index].flags & 0xFF) == INLINE_ITEM_TYPE_TEXT_EDIT) ||
                   ((wgui_inline_items[wgui_inline_pen_down_item_index].flags & 0xFF) == INLINE_ITEM_TYPE_SELECT)
                  )
                {
                    if(inline_fte_displayonly_item_pen_handler(pen_event, x, y, inline_event, (U16)wgui_inline_pen_down_item_index) == MMI_FALSE )
                    {
                        wgui_inline_pen_handler_type = WGUI_INLINE_PEN_HANDLER_NONE;
                    }
                }
            }
#endif
        }
#if 0        
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif        
    }
    return ret;
}


/*****************************************************************************
* FUNCTION
*  wgui_inline_get_item_height_for_scroll_bar
* DESCRIPTION
*  return item height for scroll bar.
* PARAMETERS
* RETURNS
*  BOOL
*****************************************************************************/
S32 wgui_inline_get_item_height_for_scroll_bar(gui_scrollbar_dir_enum direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 iwidth, iheight;
    U8 item_index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(direction == GUI_SCROLLBAR_DIR_DOWN)
    {
        item_index = MMI_fixed_list_menu.first_displayed_item;   
    }
    else if(direction == GUI_SCROLLBAR_DIR_UP)
    {  
#if defined (__MMI_INLINE_ITEM_MULTILINE_READ_ONLY__)
        if(((wgui_inline_items[MMI_fixed_list_menu.n_items - 1].flags & 0xff) == INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY) &&
           (MMI_fixed_list_menu.highlighted_item == MMI_fixed_list_menu.n_items - 1)
          )        
        {
            if(MMI_fixed_list_menu.first_displayed_item > 0)
            {
                item_index = MMI_fixed_list_menu.first_displayed_item - 1;
            }
            else
            {
                item_index = MMI_fixed_list_menu.last_displayed_item;
            }
        }
        else
#endif            
        {
            item_index = MMI_fixed_list_menu.last_displayed_item;
        } 
    }
    {
        if (item_index == MMI_fixed_list_menu.highlighted_item)
        {
            MMI_fixed_list_menu.current_displayed_item = -1;
    }
    else
    {
            MMI_fixed_list_menu.current_displayed_item = item_index;
        }
    MMI_fixed_list_menu.item_measure_function(MMI_fixed_list_menu.items[item_index], MMI_fixed_list_menu.common_item_data, &iwidth, &iheight);
    }
    return iheight;
}


#endif /* __MMI_TOUCH_SCREEN__ */ 


#ifdef __MMI_FTE_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  inline_is_handle_fte_tap
 * DESCRIPTION
 *  handle inline tap behavior
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL inline_is_handle_fte_tap(mmi_tap_type_enum tap_type, U16 index)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(((wgui_inline_items[index].flags & 0xff) == INLINE_ITEM_TYPE_DISPLAY_ONLY) 
        ||
       ((wgui_inline_items[index].flags & 0xff) == INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY) 
      )
    {
        if (cui_inline_is_current_cui())
        {
			if (!cui_inline_is_item_lsk_by_app(index))
			{
				return MMI_TRUE;
			}
        }
        return MMI_FALSE;
    }
#if defined(__COSMOS_MMI_PACKAGE__)
    else if ((wgui_inline_items[index].flags & 0xff) == INLINE_ITEM_TYPE_TEXT_EDIT)
    {
        return MMI_FALSE;
    }
	else if ((wgui_inline_items[index].flags & 0xff) == INLINE_ITEM_TYPE_SELECT)
	{
        return MMI_FALSE;
	}
	else if((wgui_inline_items[index].flags & 0xff) == INLINE_ITEM_TYPE_FULL_SCREEN_EDIT)
	{
	    return MMI_FALSE;
	}
#else /* __COSMOS_MMI_PACKAGE__ */
    else if((wgui_inline_items[index].flags & 0xff) == INLINE_ITEM_TYPE_FULL_SCREEN_EDIT)
    {            
        if(complete_inline_item_edit)
        {
            complete_inline_item_edit();   
        }

        wgui_inline_items[index].handler(
            wgui_inline_item_x,
            wgui_inline_item_y,
            wgui_inline_item_width,
            wgui_inline_item_height,
            wgui_inline_item_key_code,
            wgui_inline_item_key_event,
            &wgui_inline_items [index].text_p,
            wgui_inline_items[index].item,
            wgui_inline_items[index].flags,
            wgui_current_history_buffer);

        wgui_current_history_buffer = NULL;             
    }
#endif /* __COSMOS_MMI_PACKAGE__ */
    return MMI_TRUE;     
}


/*****************************************************************************
 * FUNCTION
 *  inline_fte_set_item_height_by_guess
 * DESCRIPTION
 *  set line style when fte.
 * PARAMETERS
 *  flag          [IN]  flag        
 * RETURNS
 *  void
 *****************************************************************************/
void inline_fte_set_item_height_by_guess(InlineItem *list_of_items, S32 number_of_items)
{
 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    int i;   
    int has_caption = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_inline_fte_item_height_table, 0, sizeof(g_inline_fte_item_height_table));

    for(i = 0; i < number_of_items; i++)
    {
       if((list_of_items[i].flags & 0xff) == INLINE_ITEM_TYPE_CAPTION)
       {
            has_caption = 1;
            g_inline_fte_item_height_table[i] = INLINE_LINE_STYLE_TWO_LINE;
            continue;
       }
       else if(has_caption == 1)
       {
            g_inline_fte_item_height_table[i] = INLINE_LINE_STYLE_TWO_LINE;
       }
       else if(has_caption == 0)
       {
            g_inline_fte_item_height_table[i] = INLINE_LINE_STYLE_ONE_LINE;
       }
    }    
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_stop_scroll_when_ssp
 * DESCRIPTION
 *  Stop scroll when ssp is run.
 * PARAMETERS
 *      
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_stop_scroll_when_ssp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(((wgui_inline_items[wgui_inline_item_highlighted_index].flags & 0xff) == INLINE_ITEM_TYPE_DISPLAY_ONLY) ||
       ((wgui_inline_items[wgui_inline_item_highlighted_index].flags & 0xff) == INLINE_ITEM_TYPE_FULL_SCREEN_EDIT)
      )
    {
       wgui_inline_display_only_close(); 
    }
    
}

/*****************************************************************************
 * FUNCTION
 *  wgui_inline_stop_scroll
 * DESCRIPTION
 *  Stop scroll when .
 * PARAMETERS
 *      
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_stop_scroll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(((wgui_inline_items[wgui_inline_item_highlighted_index].flags & 0xff) == INLINE_ITEM_TYPE_DISPLAY_ONLY) ||
        ((wgui_inline_items[wgui_inline_item_highlighted_index].flags & 0xff) == INLINE_ITEM_TYPE_FULL_SCREEN_EDIT)
        )
    {
        gui_scrolling_text_stop(&wgui_inline_scroll_text);
        memset(&wgui_inline_scroll_text, 0, sizeof(wgui_inline_scroll_text));
    }
}

/*****************************************************************************
 * FUNCTION
 *  wgui_inline_stop_scroll
 * DESCRIPTION
 *  Stop scroll when .
 * PARAMETERS
 *      
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_start_scroll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(((wgui_inline_items[wgui_inline_item_highlighted_index].flags & 0xff) == INLINE_ITEM_TYPE_DISPLAY_ONLY) ||
        ((wgui_inline_items[wgui_inline_item_highlighted_index].flags & 0xff) == INLINE_ITEM_TYPE_FULL_SCREEN_EDIT)
        )
    {
        wgui_inline_item_text_edit * i = wgui_inline_items[wgui_inline_item_highlighted_index].item;
         wgui_show_inline_fte_displayonly_item_highlight_ext(i->x, i->y, 
                        i->width, i->height, 
                        &wgui_inline_items[wgui_inline_item_highlighted_index], 
                        0);     
    }
}

#endif


/*****************************************************************************
* FUNCTION
 *  inline_fte_set_item_show_as_display_only
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * 
 *****************************************************************************/
void wgui_inline_fte_set_item_show_as_display_only(wgui_inline_item *inline_item)
{
#ifdef __MMI_FTE_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(((inline_item->flags & 0xff) == INLINE_ITEM_TYPE_DISPLAY_ONLY) ||
       ((inline_item->flags & 0xff) == INLINE_ITEM_TYPE_FULL_SCREEN_EDIT))
    {
        inline_item->flags |= INLINE_ITEM_DISPLAY_ONLY_SHOW;
    }
#endif

}

/*****************************************************************************
* FUNCTION
 *  wgui_inline_fte_reset_item_show_as_display_only
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * 
 *****************************************************************************/
void wgui_inline_fte_reset_item_show_as_display_only(wgui_inline_item *inline_item)
{
#ifdef __MMI_FTE_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(((inline_item->flags & 0xff) == INLINE_ITEM_TYPE_DISPLAY_ONLY) ||
       ((inline_item->flags & 0xff) == INLINE_ITEM_TYPE_FULL_SCREEN_EDIT))
    {
        inline_item->flags &= ~INLINE_ITEM_DISPLAY_ONLY_SHOW;
    }
#endif

}


mmi_ret wgui_inline_proc_post_event(mmi_event_struct* param)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(param->evt_id == EVT_ID_INLINE_IMAGETEXT_PEN_UP)
    {
        FuncPtr func = (FuncPtr)param->user_data;
        if(func)
        {
            func();
        }
    }
	return MMI_RET_OK;
}


/***************************************************************************** 
 * Progress bar Control Integration in Inline control   
 *****************************************************************************/

#if  defined(__MMI_INLINE_ITEM_PROGRESS_BAR__)


#define MAX_INLINE_PROGRESS_BAR_STRING_SIZE  12

gui_progress_bar_struct* pbar;

gui_progress_bar_theme_struct wgui_inline_progress_bar_focussed_theme;
gui_progress_bar_theme_struct wgui_inline_progress_bar_unfocussed_theme;

UI_filled_area _inline_progress_bar_highlight_bg_defaultTheme={
    UI_FILLED_AREA_TYPE_BITMAP,
    UI_IMAGE_ID_NULL,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 100},
    {0,0,0,100},
    0};
    
UI_filled_area _inline_progress_bar_normal_bg_defaultTheme={
    UI_FILLED_AREA_TYPE_BITMAP,
    UI_IMAGE_ID_NULL,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 100},
    {0,0,0,100},
    0};  

UI_filled_area _inline_progress_bar_button_up_defaultTheme={
    UI_FILLED_AREA_TYPE_BITMAP,
    UI_IMAGE_ID_NULL,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 100},
    {0,0,0,100},
    0};


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_set_focussed_progress_bar_theme
 * DESCRIPTION
 *  Set progress bar focussed theme.
 * PARAMETERS     
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_set_focussed_progress_bar_theme()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_FTE_SUPPORT__    
    wgui_inline_progress_bar_focussed_theme.background_filler = current_MMI_theme->inline_item_progress_bar_highlight_bg_filler;
    wgui_inline_progress_bar_focussed_theme.normal_progress_filler= current_MMI_theme->inline_item_progress_bar_normal_progress_filler;
    wgui_inline_progress_bar_focussed_theme.step_filler= current_MMI_theme->inline_item_progress_bar_step_filler;
    wgui_inline_progress_bar_focussed_theme.button_up_filler= current_MMI_theme->inline_item_progress_bar_button_normal_filler;
    wgui_inline_progress_bar_focussed_theme.button_press_filler= current_MMI_theme->inline_item_progress_bar_button_pressed_filler;
    wgui_inline_progress_bar_focussed_theme.text_color = *(current_MMI_theme->inline_item_progress_bar_text_color);
#else
    wgui_inline_progress_bar_focussed_theme.background_filler = &_inline_progress_bar_highlight_bg_defaultTheme;
    wgui_inline_progress_bar_focussed_theme.background_filler->b = current_MMI_theme->slide_bar_focused_bg_image;
    wgui_inline_progress_bar_focussed_theme.background_filler->flags = UI_FILLED_AREA_TYPE_BITMAP;
    
    wgui_inline_progress_bar_focussed_theme.button_up_filler = &_inline_progress_bar_button_up_defaultTheme;
    wgui_inline_progress_bar_focussed_theme.button_up_filler->b = current_MMI_theme->slide_bar_indicator_image;
    wgui_inline_progress_bar_focussed_theme.button_up_filler->flags = UI_FILLED_AREA_TYPE_BITMAP;
#endif
   
}

/*****************************************************************************
 * FUNCTION
 *  wgui_inline_set_focussed_progress_bar_theme
 * DESCRIPTION
 *  Set progress bar focussed theme.
 * PARAMETERS     
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_set_unfocussed_progress_bar_theme()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_FTE_SUPPORT__
    wgui_inline_progress_bar_unfocussed_theme.background_filler = current_MMI_theme->inline_item_progress_bar_unhighlight_bg_filler;
    wgui_inline_progress_bar_unfocussed_theme.normal_progress_filler= current_MMI_theme->inline_item_progress_bar_normal_progress_filler;
    wgui_inline_progress_bar_unfocussed_theme.step_filler= current_MMI_theme->inline_item_progress_bar_step_filler;
    wgui_inline_progress_bar_unfocussed_theme.button_up_filler= current_MMI_theme->inline_item_progress_bar_button_normal_filler;
    wgui_inline_progress_bar_unfocussed_theme.button_press_filler= current_MMI_theme->inline_item_progress_bar_button_pressed_filler;
    wgui_inline_progress_bar_unfocussed_theme.text_color= *(current_MMI_theme->inline_item_progress_bar_text_color);
#else
    wgui_inline_progress_bar_unfocussed_theme.background_filler = &_inline_progress_bar_normal_bg_defaultTheme;
    wgui_inline_progress_bar_unfocussed_theme.background_filler->b = current_MMI_theme->slide_bar_background_image;
    wgui_inline_progress_bar_unfocussed_theme.background_filler->flags = UI_FILLED_AREA_TYPE_BITMAP;

    wgui_inline_progress_bar_unfocussed_theme.button_up_filler = &_inline_progress_bar_button_up_defaultTheme;
    wgui_inline_progress_bar_unfocussed_theme.button_up_filler->b = current_MMI_theme->slide_bar_indicator_image;
    wgui_inline_progress_bar_unfocussed_theme.button_up_filler->flags = UI_FILLED_AREA_TYPE_BITMAP;
#endif

}


/*****************************************************************************
 * FUNCTION
 *  redraw_progress_bar_control
 * DESCRIPTION
 *  redraw progress bar control
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void redraw_progress_bar_control(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    wgui_progress_bar_draw(pbar);
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(
        pbar->x,
        pbar->y,
        pbar->x + pbar->width - 1,
        pbar->y + pbar->height - 1);
}

#ifdef __MMI_TOUCH_SCREEN__

#if defined(__MMI_FTE_SUPPORT__) && defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
extern gui_list_smooth_scrolling_by_pen_state_enum g_gui_ssp_state;
#endif

/*****************************************************************************
 * FUNCTION
 *  inline_progress_bar_pen_handler
 * DESCRIPTION
 *  pen handler of inline image text
 * PARAMETERS
 *  pen_event       [IN]    pen event    
 *  x               [IN]    pen x position    
 *  y               [IN]    pen y position    
 *  item_event      [IN]    inline pen enum     
 * RETURNS
 *  ret
 *****************************************************************************/
BOOL inline_progress_bar_pen_handler(
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_inline_item_pen_enum *item_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL res = MMI_TRUE;
    U16 old_value = 0;
    static int down_y = -1;
    static S32 reset_pre_hdlr = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    old_value = *(pbar->value);
	*item_event = GUI_INLINE_ITEM_PEN_NONE;
    
    res = wgui_progress_bar_pen_handler(pbar, pen_event, x, y);
    
#if defined(__MMI_FTE_SUPPORT__) && defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
    if(res != MMI_FALSE)
    {
        switch (pen_event)
        {
            case MMI_PEN_EVENT_DOWN:
            if(reset_pre_hdlr == 0)
            {
                wgui_pen_reset_pre_hdlr();
                reset_pre_hdlr = 1;
            }
            down_y = y;
            break;
            default:
                /* ignored events */
                break;
        }
    }
    switch (pen_event)
    {
        case MMI_PEN_EVENT_MOVE:
        {
            if((down_y != -1) && (((down_y - y) > MMI_INLINE_PROGRESS_BAR_Y_OFFSET_TO_SSP) || ((down_y - y) < -MMI_INLINE_PROGRESS_BAR_Y_OFFSET_TO_SSP)))
            {
                if(reset_pre_hdlr == 1)
                {
                wgui_pen_restore_pre_hdlr(); 
                    reset_pre_hdlr = 0;
                }
            }
            break;
        }
        case MMI_PEN_EVENT_UP:
        case MMI_PEN_EVENT_ABORT:
            g_gui_ssp_state = GUI_LIST_SMOOTH_SCROLLING_BY_PEN_STATE_UNFOCUS;
            if(reset_pre_hdlr == 1)
            {
                wgui_pen_restore_pre_hdlr();
                reset_pre_hdlr = 0;
            }
            down_y = -1;
            break; 
    }
#endif
    if(old_value != *(pbar->value))
    {
        redraw_progress_bar_control();
        set_wgui_inline_list_menu_changed();
    }
    return res;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  inline_progress_bar_decrement
 * DESCRIPTION
 *  Decrements the progress bar value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void inline_progress_bar_decrement(void)
{
    if( (*pbar->value) - pbar->step_size >= 0 )
    {
        wgui_progress_bar_decrement(pbar);
        wgui_progress_bar_draw(pbar);
        set_wgui_inline_list_menu_changed();
    }
}

/*****************************************************************************
 * FUNCTION
 *  inline_progress_bar_increment
 * DESCRIPTION
 *  Increment the progress bar value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void inline_progress_bar_increment(void)
{
    if( (*pbar->value) + pbar->step_size <= pbar->max_value )
    {
        wgui_progress_bar_increment(pbar);
        wgui_progress_bar_draw(pbar);
        set_wgui_inline_list_menu_changed();
    }

}
/*****************************************************************************
 * FUNCTION
 *  register_inline_progress_bar_keys
 * DESCRIPTION
 *  register key handlers for progress bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_inline_progress_bar_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(inline_progress_bar_decrement, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(inline_progress_bar_increment, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(inline_progress_bar_increment, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(inline_progress_bar_decrement, KEY_VOL_DOWN, KEY_EVENT_DOWN);

    SetKeyHandler(inline_progress_bar_decrement, KEY_LEFT_ARROW, KEY_REPEAT);
    SetKeyHandler(inline_progress_bar_increment, KEY_RIGHT_ARROW, KEY_REPEAT);
    SetKeyHandler(inline_progress_bar_increment, KEY_VOL_UP, KEY_REPEAT);
    SetKeyHandler(inline_progress_bar_decrement, KEY_VOL_DOWN, KEY_REPEAT);
}

/*****************************************************************************
 * FUNCTION
 *  clear_inline_progress_bar_key_handlers
 * DESCRIPTION
 *  register key handlers for progress bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clear_inline_progress_bar_key_handlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_VOL_UP, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_VOL_DOWN, KEY_EVENT_DOWN);

    ClearKeyHandler(KEY_LEFT_ARROW, KEY_REPEAT);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_REPEAT);
    ClearKeyHandler(KEY_VOL_UP, KEY_REPEAT);
    ClearKeyHandler(KEY_VOL_DOWN, KEY_REPEAT);

    clear_keyboard_key_handler();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_show_inline_progress_bar_list_menuitem
 * DESCRIPTION
 *  Displaying inline text edit as a menu item in the fixed list menu
 * PARAMETERS
 *  x1          [IN]        x
 *  y1          [IN]        y
 *  width       [IN]        width
 *  height      [IN]        height
 *  item        [IN]        inline item         
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_show_inline_progress_bar_list_menuitem(S32 x1, S32 y1, S32 width, S32 height, wgui_inline_item *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_progress_bar *i = (wgui_inline_item_progress_bar*) item->item;
    gui_progress_bar_struct progress_bar_display = {0};
    S32 xx = x1;
    S32 control_width = width;
    gui_progress_bar_theme_struct display_theme = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_fe_get_r2l_state())
    {
        xx = x1;
        if(!(item->flags & INLINE_ITEM_LEFT_ALIGN))
        {
            control_width = width - MMI_fixed_icontext_menuitem.text_x;
        }
        else
        {
            control_width = width;
        }
    }
    else
    {
        if(!(item->flags & INLINE_ITEM_LEFT_ALIGN))
        {
            xx = x1 + MMI_fixed_icontext_menuitem.text_x - 1; 
            control_width = width - MMI_fixed_icontext_menuitem.text_x;
        }
        else
        {
            xx = x1;
            control_width = width;
        }      
    }
    /* Create progress bar */
    wgui_progress_bar_create(&progress_bar_display, (U16)xx, (U16)y1, (U16)control_width, (U16)height, i->max_value, i->step_size, i->value);

    /* Set divided in case application needs divided one */
    if(i->flags & INLINE_PBAR_DIVIDED)
    {
        wgui_progress_bar_set_type_divided(&progress_bar_display);
    }
    /* Set show string in case required */
    if(i->flags & INLINE_PBAR_SHOW_STRING)
    {
        wgui_progress_bar_set_display_string(&progress_bar_display);
        
    }
    if(i->flags & INLINE_PBAR_SHOW_STRING_PERCENTAGE)
    {
        wgui_progress_bar_set_display_string_percentage(&progress_bar_display);
    }
    
    gui_get_progress_bar_theme(&progress_bar_display, &display_theme);
    gui_set_progress_bar_theme(&progress_bar_display, &wgui_inline_progress_bar_unfocussed_theme);
    wgui_progress_bar_draw(&progress_bar_display);
    gui_set_progress_bar_theme(&progress_bar_display, &display_theme);
    
    
}


/*****************************************************************************
 * FUNCTION
 *  inline_select_menu_change_complete
 * DESCRIPTION
 *  change complete function for inline select menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_progress_bar_complete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_inline_progress_bar_key_handlers();
    complete_inline_item_edit = UI_dummy_function;
    redraw_current_inline_item = UI_dummy_function;
#ifdef __MMI_TOUCH_SCREEN__
    wgui_current_inline_item_pen_function = UI_dummy_inline_item_pen_function;
#endif    
      
}


/*****************************************************************************
 * FUNCTION
 *  handle_inline_progress_bar
 * DESCRIPTION
 *  activation function of inline user defined select
 * PARAMETERS
 *  x                   [IN]        left corner's x coordinate
 *  y                   [IN]        left corner's y coordinate
 *  width               [IN]        width
 *  height              [IN]        height
 *  key_code            [IN]        key code
 *  key_event           [IN]        key event
 *  text_p              [IN]        text pointer
 *  item                [IN]        inline item
 *  flags               [IN]        flags
 *  history_buffer      [IN]        history buffer           
 * RETURNS
 *  void
 *****************************************************************************/
void handle_inline_progress_bar(
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        S32 key_code,
        S32 key_event,
        U8 **text_p,
        void *item,
        U32 flags,
        U8 *history_buffer)
{
    wgui_inline_item_progress_bar* i;
    S32 xx = x;
    S32 control_width = width;
    i = (wgui_inline_item_progress_bar*) item;

    redraw_current_inline_item = redraw_progress_bar_control;
#ifdef __MMI_TOUCH_SCREEN__
    wgui_current_inline_item_pen_function = inline_progress_bar_pen_handler;
#endif 
    /* Assign the global pointer to the selected control */
    pbar = &i->pbar;

    if(mmi_fe_get_r2l_state())
    {
        xx = x;
        if(!(flags & INLINE_ITEM_LEFT_ALIGN))
        {
            control_width = width - MMI_fixed_icontext_menuitem.text_x;
        }
        else
        {
            control_width = width;
        }
    }
    else
    {
        if(!(flags & INLINE_ITEM_LEFT_ALIGN))
        {
            xx = x + MMI_fixed_icontext_menuitem.text_x - 1; 
            control_width = width - MMI_fixed_icontext_menuitem.text_x;
        }
        else
        {
            xx = x;
            control_width = width;
        }      
    }
    /* Create progress bar */
    wgui_progress_bar_create(pbar, (U16)xx, (U16)y, (U16)control_width, (U16)height, i->max_value, i->step_size, i->value);
    /* Clear the key handlers */
    clear_inline_progress_bar_key_handlers();
    if(!(i->flags & INLINE_PBAR_READ_ONLY))
    {
        /* Register keys */
        register_inline_progress_bar_keys(); 
    }
    /* Set divided in case application needs divided one */
    if(i->flags & INLINE_PBAR_DIVIDED)
    {
        wgui_progress_bar_set_type_divided(pbar);
    }
    /* Set show string in case required */
    if(i->flags & INLINE_PBAR_SHOW_STRING)
    {
        wgui_progress_bar_set_display_string(pbar);
        
    }
    if(i->flags & INLINE_PBAR_SHOW_STRING_PERCENTAGE)
    {
        wgui_progress_bar_set_display_string_percentage(pbar);
    }
    gui_set_progress_bar_theme(pbar, &wgui_inline_progress_bar_focussed_theme);
    wgui_progress_bar_register_change_listener(pbar, i->callback);
    wgui_progress_bar_draw(pbar);

    complete_inline_item_edit = wgui_inline_progress_bar_complete;
    redraw_current_inline_item = redraw_progress_bar_control;
#ifdef __MMI_TOUCH_SCREEN__
    wgui_current_inline_item_pen_function = inline_progress_bar_pen_handler;
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  SetInlineItemProgressBar
 * DESCRIPTION
 *  set data for inline time edit
 * PARAMETERS
 *  item                [IN]       inline item         
 *  funcptr             [IN]       Callback function from App
 *  value               [IN]       value pointer      
 *  max_value           [IN]       max_value of control
 *  step_size           [IN]       step size
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineItemProgressBar(InlineItem *item, void(*funcptr)(void), U16* value, U16 max_value, U16 step_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_progress_bar* i;
    U8 str[20];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inline_mem_alloc_info[wgui_inline_mem_alloc_number] = item->item = wgui_inline_malloc(sizeof(wgui_inline_item_progress_bar));
    wgui_inline_mem_alloc_number++;
    wgui_inline_mem_alloc_info[wgui_inline_mem_alloc_number] = item->text_p = (U8*)wgui_inline_malloc(MAX_INLINE_PROGRESS_BAR_STRING_SIZE * sizeof(U8));
    wgui_inline_mem_alloc_number++;  
    item->flags = INLINE_ITEM_TYPE_PROGRESS_BAR;
    item->flags |= INLINE_ITEM_DISABLE_HIGHLIGHT;
    i = (wgui_inline_item_progress_bar*) item->item;
    i->callback = funcptr;
    i->value = value;
    i->max_value = max_value;
    i->step_size = step_size;
    sprintf((PS8) str, "%d", *value);
    mmi_asc_to_ucs2((S8*) i->pbar.string, (S8*) str);
    item->text_p = i->pbar.string;
    item->handler = handle_inline_progress_bar;
}


/*****************************************************************************
 * FUNCTION
 *  SetInlineItemProgressBarStyle
 * DESCRIPTION
 *  set Progress bar style
 * PARAMETERS
 *  item                [IN]       inline item         
 *  flags               [IN]       flags
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineItemProgressBarStyle(InlineItem *item, U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_progress_bar* i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = (wgui_inline_item_progress_bar*) item->item;
    i->flags |= flags;
    if(flags & INLINE_PBAR_SHOW_STRING_PERCENTAGE)
    {
        U8 str[20];
        sprintf((PS8)str, "%d %%", *(i->value));
        mmi_asc_to_ucs2((S8*) i->pbar.string, (S8*) str);
        item->text_p = i->pbar.string;
    }
}


#endif /* __MMI_INLINE_ITEM_PROGRESS_BAR__ */


#ifdef __MMI_FTE_SUPPORT__

/*****************************************************************************
* FUNCTION
*  wgui_inline_get_vk_status
* DESCRIPTION
*  Get current vk status.
* PARAMETERS
* RETURNS
*  characters inserted
*****************************************************************************/
void wgui_inline_get_vk_status(U8 *vk_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *vk_status = mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON);
}

/*****************************************************************************
* FUNCTION
*  wgui_inline_set_vk_status
* DESCRIPTION
*  Set current vk status.
* PARAMETERS
* RETURNS
*  characters inserted
*****************************************************************************/
void wgui_inline_set_vk_status(U8 vk_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(vk_status)
    {
        mmi_imc_set_vk_present(MMI_IMC_VK_DEFAULT_ENLARGE); 
    }
    else
    {
        mmi_imc_set_vk_present(MMI_IMC_VK_PRESENT_DEFAULT); 
    }
}

#endif


/*****************************************************************************
 * FUNCTION
 *  cui_inline_option_menu_done_lsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_option_menu_done_lsk_handler(mmi_id menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    if ((current_wgui_inline_item == NULL) || (wgui_n_inline_items <= 0))
    {
        cui_menu_close(menu_gid);
    }
    handle_inline_full_screen_edit_complete();
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  cui_inline_proc_func
 * DESCRIPTION
 *  Process option menu event
 * PARAMETERS
 *  item_type      [IN]        item type
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret wgui_inine_option_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    
    switch (menu_evt->evt_id)
    {   
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            if (menu_evt->highlighted_menu_id == MENU_ID_INLINE_EDITOR_OPT_DONE)
            {
                wgui_inline_option_menu_done_lsk_handler(menu_evt->sender_id);               
            }
            break;
        }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {           
            cui_menu_close(menu_evt->sender_id);
            break;
        }
    }

    wgui_inputs_options_menu_handler(evt, (mmi_id)(U32)menu_evt->app_data); // app_id is menu cui¡¯s parent groupd ID

    return 0;
}



/*****************************************************************************
 * FUNCTION
 *  EntryScrForInputMethodAndDone
 * DESCRIPTION
 *  Entry Fullscreen edit option menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrForInputMethodAndDone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    mmi_id option_menu_gid;
    mmi_id inline_gid;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ExecuteCurrExitHandler (); */
    /*
	g_id = mmi_frm_group_get_active_id();
	if (g_id == GRP_ID_INVALID)
	{
	    if (CheckIsBackHistory())
        {
    		scr_id = GetCurrScrnId();
        }
        else
        {
    		scr_id = mmi_ime_gen_editor_common_scr_id(SCR_INPUT_METHOD_AND_DONE);
    		
    		if (!scr_id)
    		{
    			MMI_ASSERT(0);
    		}
        }
    
		EntryNewScreen(scr_id, ExitScrForInputMethodAndDone, NULL, NULL);
	    guiBuffer = GetCurrGuiBuffer(scr_id);
	}
	else
	{
		if (mmi_frm_scrn_enter(g_id , SCR_INPUT_METHOD_AND_DONE, NULL, EntryScrForInputMethodAndDone, 0) == MMI_FALSE)
		{
			return;
		}
		guiBuffer = mmi_frm_scrn_get_active_gui_buf();	
	}
    */

     inline_gid = mmi_frm_group_create(
            GRP_ID_ROOT, GRP_ID_AUTO_GEN,
            wgui_inine_option_group_proc, (void*)NULL); 
    mmi_frm_group_enter(inline_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    option_menu_gid = cui_menu_create(inline_gid,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_OPTION,
        MENU_ID_INLINE_EDITOR_OPT,
        MMI_TRUE, (void *)(U32)inline_gid);
    //cui_menu_enable_cascading_option_menu(option_menu_gid);
    cui_menu_run(option_menu_gid);

    /* SetExitHandler (SCR_INPUT_METHOD_AND_DONE, ExitScrForInputMethodAndDone); */
}


/*****************************************************************************
 * FUNCTION
 *  DisableInlineItem
 * DESCRIPTION
 *  Set attribute for Dispalyonly item, Press number key to enter edit screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_set_displayonly_no_num_key(InlineItem *item, MMI_BOOL operation)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if((item->flags & 0xff ) == INLINE_ITEM_TYPE_DISPLAY_ONLY)
    {
        if(operation == 1)
        {
            item->flags |= INLINE_ITEM_DISPLAY_ONLY_NO_NUMKEY;
        }
        else if(operation == 0)
        {
            item->flags &= ~INLINE_ITEM_DISPLAY_ONLY_NO_NUMKEY;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_set_text_edit_first_cursor
 * DESCRIPTION
 *  Set attribute for edit item, set cursor to first position.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void wgui_inline_set_text_edit_first_cursor(InlineItem *item, MMI_BOOL operation)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if((item->flags & 0xff ) == INLINE_ITEM_TYPE_TEXT_EDIT)
    {
        if(operation == 1)
        {
            item->flags |= INLINE_ITEM_TEXT_EDIT_FIRST_CURSOR;
        }
        else if(operation == 0)
        {
            item->flags &= ~INLINE_ITEM_TEXT_EDIT_FIRST_CURSOR;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_set_parent_group
 * DESCRIPTION
 *  Set parent  for inline screen.
 * PARAMETERS
 *  MMI_ID  [IN] parent_id
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_set_parent_group(MMI_ID parent_id)
{
    //MMI_ID always >= 0
    g_inline_parent_id = parent_id;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_send_evt_to_parent
 * DESCRIPTION
 *  Send event to inline parent group.
 * PARAMETERS
 *  MMI_ID  [IN] parent_id
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_send_evt_to_parent(MMI_ID group_id, U8 group_type, U16 item_index, mmi_group_event_struct *ext_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_event_inline_notify_struct evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CUI_INLINE_NOTIFY, group_id);
    evt.item_id = item_index;
    
    switch (ext_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_FSEDITOR_SUBMIT:
        case EVT_ID_CUI_FSEDITOR_CSK_PRESSED:
        {
            evt.event_type = CUI_INLINE_NOTIFY_SUB_GROUP_SUBMIT;
            break;
        }
        case EVT_ID_CUI_MENU_LIST_EXIT:
        case EVT_ID_CUI_FSEDITOR_DEINIT:
        {
            evt.event_type = CUI_INLINE_NOTIFY_SUB_GROUP_DEINIT;
            break;
        }
        case EVT_ID_CUI_FSEDITOR_CHANGED:
        {
            evt.event_type = CUI_INLINE_NOTIFY_ITEM_CHANGED;
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) ext_evt;
            evt.event_type = CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED;
            evt.param = menu_evt->highlighted_menu_id;
            break;
        }
    }
    
    mmi_frm_group_send_to_parent(group_id, (mmi_group_event_struct*) & evt);
    
}

    

/*****************************************************************************
 * FUNCTION
 *  wgui_inline_fs_cui_editor_proc_func
 * DESCRIPTION
 *  Inline FS Editor CUI proc of event.
 * PARAMETERS
 *  evt     [OUT] event data struct.    
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret wgui_inline_fs_cui_editor_proc_func(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_group_event_struct *ext_evt = (mmi_group_event_struct*) evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_FSEDITOR_SUBMIT:
        case EVT_ID_CUI_FSEDITOR_CSK_PRESSED:
        {
            U32 group_info = cui_fseditor_get_parent_data(ext_evt->sender_id);
            S32 item_index = group_info & 0xFF;
            S32 text_len = cui_fseditor_get_text_len(ext_evt->sender_id);
            cui_fseditor_get_text(ext_evt->sender_id, (WCHAR *)evt->user_data, (text_len + 1) * ENCODING_LENGTH);

            wgui_inline_send_evt_to_parent(group_info >> 16, 1, item_index, ext_evt);
            
            cui_fseditor_close(ext_evt->sender_id);

            break;
        }
        case EVT_ID_CUI_FSEDITOR_ABORT:
        {
            cui_fseditor_close(ext_evt->sender_id);
            break;
        }
        case EVT_ID_CUI_FSEDITOR_CHANGED:
        {
            U32 group_info = cui_fseditor_get_parent_data(ext_evt->sender_id);
            S32 item_index = group_info & 0xFF;

            wgui_inline_send_evt_to_parent(group_info >> 16, 1, item_index, ext_evt);
            
            break;

        }
        case EVT_ID_CUI_FSEDITOR_DEINIT:
        {
            U32 group_info = cui_fseditor_get_parent_data(ext_evt->sender_id);
            S32 item_index = group_info & 0xFF;
            
            wgui_inline_send_evt_to_parent(group_info >> 16, 1, item_index, ext_evt);
            break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_set_char_filter
 * DESCRIPTION
 *  Set character filter for IME.
 * PARAMETERS
 *  item_index     [OUT] the item index which wiil be set.    
 * RETURNS
 *  
 *****************************************************************************/
void wgui_inline_set_char_filter(S32 item_index, MMI_BOOL is_allowed, const UI_character_type * characters_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_text_edit *i = (wgui_inline_item_text_edit*) wgui_inline_items[item_index].item;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(((wgui_inline_items[item_index].flags & 0xFF) == INLINE_ITEM_TYPE_TEXT_EDIT) ||
       ((wgui_inline_items[item_index].flags & 0xFF) == INLINE_ITEM_TYPE_FULL_SCREEN_EDIT) 
      )
    {
        i->set_characters_flag = is_allowed;
        i->set_characters_list = (UI_character_type *)characters_list;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_get_prev_caption
 * DESCRIPTION
 *  get prev caption name from current item
 * PARAMETERS
 *  item_index     [IN]  current item index.
 * RETURNS
 *  
 *****************************************************************************/
static PU8 wgui_inline_get_prev_caption(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    wgui_inline_item *item;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = item_index; index >= 0; index--)
    {
        item = &wgui_inline_items[index];
        if ((item->flags & INLINE_ITEM_TYPE_MASK) == INLINE_ITEM_TYPE_CAPTION)
        {
            return (PU8)(item->text_p);
        }
    }
    return (PU8)NULL;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_get_input_ext_type
 * DESCRIPTION
 *  get input ext type when item is INLINE_ITEM_TYPE_TEXT_EDIT
 * PARAMETERS
 *  item_index     [IN]  item index.
 *  input_ext_type		[IN/OUT]		input extended type
 * RETURNS
 *  
 *****************************************************************************/
static void wgui_inline_get_input_ext_type(void *item, S16 *input_ext_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_text_edit *i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = (wgui_inline_item_text_edit*)item;
    if (i->input_type & INPUT_TYPE_PLUS_CHARACTER_HANDLING)
    {
        *input_ext_type |= INPUT_TYPE_PLUS_CHARACTER_HANDLING;
    }
}

/*****************************************************************************
 * FUNCTION
 *  wgui_inline_fs_cui_editor
 * DESCRIPTION
 *  Create FS Editor CUI.
 * PARAMETERS
 *  parent_id     [IN]  parent group id.
 * RETURNS
 *  
 *****************************************************************************/
void wgui_inline_fs_cui_editor(MMI_ID parent_id, S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sub_group_id = 0;
    mmi_id fseditor_gid = 0;
	S16 input_ext_type = 0;
    PU8 title, cui_title_string = NULL;
    wgui_inline_item_text_edit *i = (wgui_inline_item_text_edit*) wgui_inline_items[item_index].item;
    wgui_inline_item_text_edit text_edit_item = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&text_edit_item, i, sizeof(wgui_inline_item_text_edit));

	if (cui_inline_is_current_cui() == MMI_TRUE)
	{
	    cui_title_string = g_cui_inline_current_instance->title_string;
		if (cui_title_string == NULL)
		{
		    cui_title_string = (PU8)get_string(g_cui_inline_current_instance->title);
		}
	}

    sub_group_id = mmi_frm_group_create(parent_id, GRP_ID_AUTO_GEN, wgui_inline_fs_cui_editor_proc_func, (void*)i->buffer);
    mmi_frm_group_enter(sub_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    fseditor_gid  = cui_fseditor_create(sub_group_id);
    if (text_edit_item.title != 0)
    {
        cui_fseditor_set_title(fseditor_gid, text_edit_item.title, 0);
    }
    else
    {
        title = wgui_inline_get_prev_caption(item_index);
		if (title != NULL)
		{
		    cui_fseditor_set_title_string(fseditor_gid, (const WCHAR*)title);
		}
		else
		{
            cui_fseditor_set_title_string(fseditor_gid, (const WCHAR*)cui_title_string);
		}
    }
    cui_fseditor_set_parent_data(fseditor_gid, (U32) ((sub_group_id << 16) | item_index));

    cui_fseditor_set_text(
        fseditor_gid,
        (WCHAR *)text_edit_item.buffer,
        (text_edit_item.buffer_size) * ENCODING_LENGTH,
        text_edit_item.buffer_size - 1);

    /* set character filter feature. */


    /* We don't allow to execute this code, because App don't know register g_inline_get_filter_callback now.
       When go to here, g_inline_get_filter_callback is set to NULL because inline screen is exit. So we need 
       All App which not use inline CUi should register g_inline_get_filter_callback, then we don't need clear 
       g_inline_get_filter_callback. 
    */

    
    if(text_edit_item.set_characters_list)
    {
        cui_fseditor_set_characters_filter(fseditor_gid, text_edit_item.set_characters_flag,  text_edit_item.set_characters_list);
    }




/* For Support Leading zero feature. Not supported by Editor CUI now. */
/*      
    if((text_edit_item.flags & INLINE_ITEM_NO_LEADING_ZERO))
    {
        set_leading_zero(0);
    }
*/    

    if(text_edit_item.flags & INLINE_ITEM_TEXT_EDIT_FIRST_CURSOR)
    {
        cui_fseditor_set_cursor_first_pos(fseditor_gid, MMI_TRUE);
    }

    input_ext_type = (S16)text_edit_item.input_ext_type;
	wgui_inline_get_input_ext_type((void*)&text_edit_item, &input_ext_type);

    cui_fseditor_set_input_method(fseditor_gid, text_edit_item.input_type, text_edit_item.required_input_mode_set, input_ext_type);

    cui_fseditor_run(fseditor_gid);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_set_selector_list
 * DESCRIPTION
 *  Set menu items function.
 * PARAMETERS
 *  menu_gid        [IN]   menu group id.     
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_set_selector_list(mmi_id menu_gid, wgui_inline_item_select *selector_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;
    mmi_menu_id root_ids[MAX_INLINE_SELECT_MENU_ITEMS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_INLINE_SELECT_MENU_ITEMS; i++)
    {
        root_ids[i] = i;
    }
    cui_menu_set_currlist(menu_gid, selector_item->n_items, root_ids);

    for (i = 0; i < selector_item->n_items; i++)
    {
        cui_menu_set_item_string(menu_gid, i, (WCHAR*)(selector_item->list_of_strings[i]));
    }
    cui_menu_set_currlist_flags(menu_gid, CUI_MENU_RADIO_BUTTON_LIST_WITH_HINTS);
    cui_menu_set_currlist_left_softkey(menu_gid, (WCHAR*) GetString(STR_GLOBAL_SELECT));
}



/*****************************************************************************
 * FUNCTION
 *  wgui_inline_menu_cui_select_proc_func
 * DESCRIPTION
 *  Inline Menu CUI proc function of event.
 * PARAMETERS
 *  evt     [IN]    event data struct.
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret wgui_inline_menu_cui_select_proc_func(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;
    mmi_group_event_struct *ext_evt = (mmi_group_event_struct*) evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT: 
        {
            free_ctrl_buffer(menu_evt->user_data);
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            U32 group_info = (U32)menu_evt->app_data;
            S32 item_index = group_info & 0xFF;
            
            wgui_inline_item_select *selector_item = menu_evt->user_data;

            *(selector_item->highlighted_item) = menu_evt->highlighted_menu_id;

            wgui_inline_send_evt_to_parent(group_info >> 16, 2, item_index, ext_evt);

            cui_menu_close(menu_evt->sender_id);
            break;
        }
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            mmi_menu_id menu_id = 0;
            wgui_inline_item_select *selector_item = menu_evt->user_data;
            wgui_inline_set_selector_list(menu_evt->sender_id, selector_item);
            if (!mmi_frm_scrn_get_active_gui_buf())
            {
                menu_id = cui_menu_get_currlist_menu_id_from_index(menu_evt->sender_id, *selector_item->highlighted_item);
                cui_menu_set_currlist_highlighted_id(menu_evt->sender_id, menu_id);
            }
            break;
        }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(menu_evt->sender_id);
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        {
            U32 group_info = (U32)menu_evt->app_data;
            S32 item_index = group_info & 0xFF;

            wgui_inline_send_evt_to_parent(group_info >> 16, 1, item_index, ext_evt);
            
            break;
        }
        case EVT_ID_CUI_MENU_LIST_EXIT:
        {
            U32 group_info = (U32)menu_evt->app_data;
            S32 item_index = group_info & 0xFF;
            
            wgui_inline_send_evt_to_parent(group_info >> 16, 1, item_index, ext_evt);
            
            
            break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_menu_cui_select
 * DESCRIPTION
 *  Create Menu CUI for inline.
 * PARAMETERS
 *  parent_id     [IN]  parent group id.
 * RETURNS
 *  
 *****************************************************************************/
void wgui_inline_menu_cui_select(MMI_ID parent_id, S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sub_group_id = 0;
    mmi_id menu_gid = 0;
    PU8 title, cui_title_string = NULL;
    wgui_inline_item_select *i = (wgui_inline_item_select*) wgui_inline_items[item_index].item;
    wgui_inline_item_select *selector_item = get_ctrl_buffer(sizeof(wgui_inline_item_select));
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

        
    memcpy(selector_item, i, sizeof(wgui_inline_item_select));

	if (cui_inline_is_current_cui() == MMI_TRUE)
	{
	    cui_title_string = g_cui_inline_current_instance->title_string;
	}

    sub_group_id = mmi_frm_group_create(parent_id, GRP_ID_AUTO_GEN, wgui_inline_menu_cui_select_proc_func, (void*)selector_item);

    if(sub_group_id == GRP_ID_INVALID)    
    {
        free_ctrl_buffer(selector_item);
    }
    
    mmi_frm_group_enter(sub_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    menu_gid = cui_menu_create(
                           sub_group_id,
                           CUI_MENU_SRC_TYPE_APPCREATE,
                           CUI_MENU_TYPE_APPMAIN,
                           MENU_ID_INLINE_EDITOR_OPT,
                           MMI_TRUE,
                           (void*)((sub_group_id << 16) | item_index));
    
    title = wgui_inline_get_prev_caption(item_index);
	if (title != NULL)
	{
	    cui_menu_set_default_title_string(menu_gid, (WCHAR*)title);
	}
	else
	{
	    cui_menu_set_default_title_string(menu_gid, (WCHAR*)cui_title_string);
	}
   
    cui_menu_run(menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_lsk_fs_cui_editor
 * DESCRIPTION
 *  LSK function to enter FS Editor CUI.
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_lsk_fs_cui_editor(void)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inline_fs_cui_editor(g_inline_parent_id, wgui_inline_item_highlighted_index);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_lsk_menu_cui_select
 * DESCRIPTION
 *  LSK function to enter Menu CUI.
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_lsk_menu_cui_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inline_menu_cui_select(g_inline_parent_id, wgui_inline_item_highlighted_index);
}


static UI_string_type g_inline_lsk_string = NULL;
static U8 g_is_current_cui = 0;

/*****************************************************************************
 * FUNCTION
 *  wgui_inline_set_lsk_function
 * DESCRIPTION
 *  Changes the handler of softkeys for inline
 * PARAMETERS
 *  f       [IN]        Handler function
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_set_lsk_function(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_inline_lsk_functions = f;
}


#define WGUI_INLINE_OPTION_LIST_MAX_NUM	2
/*****************************************************************************
 * FUNCTION
 *  wgui_inline_set_option_list
 * DESCRIPTION
 *  Set menu items function.
 * PARAMETERS
 *  menu_gid        [IN]   menu group id.     
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inline_set_option_list(mmi_id menu_gid, S32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0, n_items = WGUI_INLINE_OPTION_LIST_MAX_NUM;
    mmi_menu_id root_ids[WGUI_INLINE_OPTION_LIST_MAX_NUM];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WGUI_INLINE_OPTION_LIST_MAX_NUM; i++)
    {
        root_ids[i] = i;
    }

    cui_menu_set_currlist(menu_gid, n_items, root_ids);

	i = 0;	
    cui_menu_set_item_string(menu_gid, i, (WCHAR*)(g_inline_lsk_string));
	i++;
	cui_menu_set_item_string(menu_gid, i, (WCHAR*)(get_string(STR_GLOBAL_SAVE)));
    cui_menu_set_currlist_left_softkey(menu_gid, (WCHAR*) GetString(STR_GLOBAL_SELECT));
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_menu_cui_op_proc
 * DESCRIPTION
 *  Inline Menu CUI proc function of event.
 * PARAMETERS
 *  evt     [IN]    event data struct.
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret wgui_inline_menu_cui_op_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;
    //mmi_group_event_struct *ext_evt = (mmi_group_event_struct*) evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
			U32 group_info = (U32)menu_evt->app_data;
			U32 parent_info = (U32)mmi_frm_group_get_user_data((MMI_ID)(group_info >> 16));
			S32 flags = (S32)(group_info & 0xFF);
			S32 fte_back = (S32)((group_info >> 8) & 0xFF);
			
			if (g_is_current_cui)
			{
				if (menu_evt->highlighted_menu_id == 0)
				{
				    if ((flags == INLINE_ITEM_TYPE_FULL_SCREEN_EDIT)
						|| (flags == INLINE_ITEM_TYPE_TEXT_EDIT)
						|| (flags == INLINE_ITEM_TYPE_RADIO)
						|| (flags == INLINE_ITEM_TYPE_CHECKBOX)
						|| (flags == INLINE_ITEM_TYPE_SELECT))
				    {
				        cui_menu_close(menu_evt->sender_id);
						if (g_inline_lsk_functions)
						{
							g_inline_lsk_functions();
						}
						else if ((flags == INLINE_ITEM_TYPE_SELECT)
							|| (flags == INLINE_ITEM_TYPE_FULL_SCREEN_EDIT)
							|| (flags == INLINE_ITEM_TYPE_TEXT_EDIT))
						{
						    cui_inline_evt_submit_int((MMI_ID)parent_info, MMI_LEFT_SOFTKEY);
						}
						return MMI_RET_OK;
				    }
					if (g_inline_lsk_functions)
					{
						g_inline_lsk_functions();
					}
					else
					{
						cui_inline_evt_submit_int((MMI_ID)parent_info, MMI_LEFT_SOFTKEY);
					}
				}
				else if (menu_evt->highlighted_menu_id == 1)
				{
				    if (fte_back)
				    {
				        cui_inline_evt_submit_int((MMI_ID)parent_info, MMI_RIGHT_SOFTKEY);
				    }
					else
					{
					    cui_inline_evt_submit_int((MMI_ID)parent_info, MMI_LEFT_SOFTKEY);
					}
				}
			}
			else
			{
			    if (menu_evt->highlighted_menu_id == 0)
			    {
					if ((flags == INLINE_ITEM_TYPE_FULL_SCREEN_EDIT)
						|| (flags == INLINE_ITEM_TYPE_TEXT_EDIT)
						|| (flags == INLINE_ITEM_TYPE_RADIO)
						|| (flags == INLINE_ITEM_TYPE_CHECKBOX)
						|| (flags == INLINE_ITEM_TYPE_SELECT))
					{
						cui_menu_close(menu_evt->sender_id);
						if (g_inline_lsk_functions)
						{
							g_inline_lsk_functions();
						}
						return MMI_RET_OK;
					}
					if (g_inline_lsk_functions)
					{
						g_inline_lsk_functions();
					}
			    }
				else if (menu_evt->highlighted_menu_id == 1)
				{
				    if (fte_back)
				    {
				        if (g_inline_edit_done_function)
				        {
				            g_inline_edit_done_function();
				        }
				    }
					else
					{
					    if (g_inline_edit_back_function)
					    {
					        g_inline_edit_back_function();
					    }
					}
				}
			}
            cui_menu_close(menu_evt->sender_id);
            break;
        }
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
			U32 group_info = (U32)menu_evt->app_data;
			
			wgui_inline_set_option_list(menu_evt->sender_id, (S32)(group_info & 0xFF));
            break;
        }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
			g_inline_edit_done_function = NULL;
			g_inline_edit_back_function = NULL;
            cui_menu_close(menu_evt->sender_id);
            break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_menu_cui_option
 * DESCRIPTION
 *  Create Menu CUI for inline left softkey.
 * PARAMETERS
 *  parent_id     [IN]  parent group id.
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inline_menu_cui_option(MMI_ID parent_id, S32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sub_group_id = 0, menu_gid = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sub_group_id = mmi_frm_group_create(
    					parent_id, 
    					GRP_ID_AUTO_GEN, 
    					wgui_inline_menu_cui_op_proc, 
    					(void*)(parent_id));
    mmi_frm_group_enter(sub_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    menu_gid = cui_menu_create(
                           sub_group_id,
                           CUI_MENU_SRC_TYPE_APPCREATE,
                           CUI_MENU_TYPE_OPTION,
                           MENU_ID_INLINE_EDITOR_OPT,
                           MMI_TRUE,
                           (void*)((sub_group_id << 16) | flags));
    
    cui_menu_run(menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_csk_menu_cui_option
 * DESCRIPTION
 *  csk function to enter Menu CUI.
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inline_csk_menu_cui_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (cui_inline_is_current_cui())
	{
		if (g_inline_lsk_functions)
		{
			g_inline_lsk_functions();
		}
		else
		{
			cui_inline_evt_submit_int((MMI_ID)g_inline_parent_id, MMI_LEFT_SOFTKEY);
		}
	}
	else
	{
	    if (g_inline_lsk_functions)
	    {
	        g_inline_lsk_functions();
	    }
	}
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_lsk_menu_cui_option
 * DESCRIPTION
 *  lsk function to enter Menu CUI.
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inline_lsk_menu_cui_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
	S32 flag = 0, tmp_flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	flag = WGUI_INLINE_ITEM_TYPE(wgui_inline_item_highlighted_index);
	if (wgui_inline_list_menu_rsk_back)
	{
	    tmp_flag = 1 << 8;
		tmp_flag = (S32)(tmp_flag & 0xff00);
	}
	flag = flag | tmp_flag;
	wgui_inline_menu_cui_option(g_inline_parent_id, flag);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_option_handler_for_lsk
 * DESCRIPTION
 *  LSK function to enter Menu CUI.
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inline_option_handler_for_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
	U16 string_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_is_current_cui = 0;
    if (cui_inline_is_current_cui())
    {
        g_is_current_cui = 1;
		g_inline_lsk_string = 0;
#if defined (__MMI_INLINE_ITEM_RADIO__) || defined (__MMI_INLINE_ITEM_CHECKBOX__)        
		if ((WGUI_INLINE_ITEM_TYPE(wgui_inline_item_highlighted_index) == INLINE_ITEM_TYPE_RADIO)
			|| (WGUI_INLINE_ITEM_TYPE(wgui_inline_item_highlighted_index) == INLINE_ITEM_TYPE_CHECKBOX)
			)
		{
		    g_inline_lsk_string = get_left_softkey_label();
		    wgui_inline_set_lsk_function(get_softkey_function(KEY_EVENT_UP,MMI_LEFT_SOFTKEY));
		}
		else
#endif            
            if ((WGUI_INLINE_ITEM_TYPE(wgui_inline_item_highlighted_index) == INLINE_ITEM_TYPE_SELECT)
			|| (WGUI_INLINE_ITEM_TYPE(wgui_inline_item_highlighted_index) == INLINE_ITEM_TYPE_FULL_SCREEN_EDIT)
    		|| (WGUI_INLINE_ITEM_TYPE(wgui_inline_item_highlighted_index) == INLINE_ITEM_TYPE_TEXT_EDIT))
		{
		    if (cui_inline_is_item_lsk_by_app(wgui_inline_item_highlighted_index))
		    {
		        string_id = cui_inline_get_item_lsk_string_id(wgui_inline_item_highlighted_index);
				g_inline_lsk_string = get_string(string_id);
		    }
			else
			{
			    g_inline_lsk_string = get_left_softkey_label();
				wgui_inline_set_lsk_function(get_softkey_function(KEY_EVENT_UP,MMI_LEFT_SOFTKEY));
			}
		}
		else
		{
		    string_id = cui_inline_get_item_lsk_string_id(wgui_inline_item_highlighted_index);
			g_inline_lsk_string = get_string(string_id);
		}
		
        if ((cui_inline_is_item_lsk_by_app(wgui_inline_item_highlighted_index))
			|| (WGUI_INLINE_ITEM_TYPE(wgui_inline_item_highlighted_index) == INLINE_ITEM_TYPE_FULL_SCREEN_EDIT)
			|| (WGUI_INLINE_ITEM_TYPE(wgui_inline_item_highlighted_index) == INLINE_ITEM_TYPE_RADIO)
			|| (WGUI_INLINE_ITEM_TYPE(wgui_inline_item_highlighted_index) == INLINE_ITEM_TYPE_CHECKBOX)
			|| (WGUI_INLINE_ITEM_TYPE(wgui_inline_item_highlighted_index) == INLINE_ITEM_TYPE_TEXT_EDIT)
			|| (WGUI_INLINE_ITEM_TYPE(wgui_inline_item_highlighted_index) == INLINE_ITEM_TYPE_SELECT)
			)
        {
			set_left_softkey_label(get_string(STR_GLOBAL_OPTIONS));
			register_softkey_handler(MMI_LEFT_SOFTKEY);
			set_softkey_function(wgui_inline_lsk_menu_cui_option, KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
			mmi_imc_key_setup_lsk_function(wgui_inline_lsk_menu_cui_option);
			
			if (!(WGUI_INLINE_ITEM_TYPE(wgui_inline_item_highlighted_index) == INLINE_ITEM_TYPE_SELECT))
			{
			    set_softkey_icon(get_image(IMG_GLOBAL_COMMON_CSK), MMI_CENTER_SOFTKEY);
				register_softkey_handler(MMI_CENTER_SOFTKEY);
			    set_softkey_function(wgui_inline_csk_menu_cui_option, KEY_EVENT_UP, MMI_CENTER_SOFTKEY);
				mmi_imc_key_setup_csk_function(wgui_inline_csk_menu_cui_option);
			}
        }
    }
	else
	{
	    g_inline_lsk_string = get_left_softkey_label();
		if (g_inline_lsk_string)
		{
		    wgui_inline_set_lsk_function(get_softkey_function(KEY_EVENT_UP,MMI_LEFT_SOFTKEY));
		    set_left_softkey_label(get_string(STR_GLOBAL_OPTIONS));
			register_softkey_handler(MMI_LEFT_SOFTKEY);
			set_softkey_function(wgui_inline_lsk_menu_cui_option, KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
			mmi_imc_key_setup_lsk_function(wgui_inline_lsk_menu_cui_option);

			if (!(WGUI_INLINE_ITEM_TYPE(wgui_inline_item_highlighted_index) == INLINE_ITEM_TYPE_SELECT))
			{
			    set_softkey_icon(get_image(IMG_GLOBAL_COMMON_CSK), MMI_CENTER_SOFTKEY);
				register_softkey_handler(MMI_CENTER_SOFTKEY);
				set_softkey_function(wgui_inline_csk_menu_cui_option, KEY_EVENT_UP, MMI_CENTER_SOFTKEY);
				mmi_imc_key_setup_csk_function(wgui_inline_csk_menu_cui_option);
			}
		}
	}
}


#if defined(__MMI_TOUCH_SCREEN__)
static void (*g_wgui_inline_tap_callback_funtion)(mmi_tap_type_enum tap_type, S32 index);

/*****************************************************************************
 * FUNCTION
 *  wgui_inline_tap_callback_funtion
 * DESCRIPTION
 *  the callback function for a intuitive command
 * PARAMETERS
 *  tap_type				[IN]		
 *  index					[IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inline_tap_callback_funtion(mmi_tap_type_enum tap_type,S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 flags = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	flags = wgui_inline_items[index].flags & 0xff;
	if (flags == INLINE_ITEM_TYPE_SELECT)
	{
	    if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
	    {
	        wgui_inline_lsk_menu_cui_select();
	    }
	}
	else if ((flags == INLINE_ITEM_TYPE_FULL_SCREEN_EDIT)
		|| (flags == INLINE_ITEM_TYPE_TEXT_EDIT))
	{
	    if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
	    {
	        wgui_inline_lsk_fs_cui_editor();
	    }
	}
	else
	{
	    if (g_wgui_inline_tap_callback_funtion)
	    {
	        g_wgui_inline_tap_callback_funtion(tap_type, index);
	    }
    #if !defined(__MMI_FTE_SUPPORT__)
        else if (flags == INLINE_ITEM_TYPE_DISPLAY_ONLY ||
			flags == INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY)
        {
            if (GetKeyHandler(KEY_LSK, KEY_EVENT_UP))
            {
                /* Some softkey handlers use GetkeyInfo() */
                SetkeyInfo(KEY_LSK, KEY_EVENT_UP);
                execute_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
            }
        }
    #endif /* __MMI_FTE_SUPPORT__ */
	}
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_register_list_tap_callback
 * DESCRIPTION
 *  register the callback function for a intuitive command
 * PARAMETERS
 *  pen_event_selected_callback_function        [IN]        Callback function
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_register_list_tap_callback(void (*tap_callback_funtion)(mmi_tap_type_enum tap_type,S32 index))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_inline_tap_callback_funtion = tap_callback_funtion;
	wgui_register_list_tap_callback(wgui_inline_tap_callback_funtion);
}
#endif /* __MMI_TOUCH_SCREEN__ */
