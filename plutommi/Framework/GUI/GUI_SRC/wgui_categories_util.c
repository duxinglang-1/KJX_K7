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
 *  wgui_categories_util.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "MMI_features.h"
#include "stdC.h"
#include "mmi_platform.h"
#include "mmi_frm_gprot.h"
#include "GlobalDefs.h"
#include "CustDataProts.h"
#include "CustMenuRes.h"
#include "WguiCategoryGprot.h"
#include "wgui_clock.h"
#include "wgui_virtual_keyboard.h"
#include "wgui_calendar.h"
#include "gui_calendar.h"
#include "wgui_tab_bars.h"


// #include "CallStructureManagementProt.h"
#include "IdleAppDef.h"
#include "IdleAppProt.h"
#include "WallpaperDefs.h"
#include "ScreenSaverDefs.h"
#include "MainMenuDef.h"
#include "lcd_sw_rnd.h"
#include "SettingGProts.h"
#include "ShortcutsDefs.h"
#include "PhoneBookTypes.h"

#include "MMIThemes.h"
#ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__
#include "MMI_features.h"       /* Add for Effect type entry for Title & highlighter */
#endif 

#ifdef __MMI_AUDIO_PLAYER__
/* dependent headers for AudioPlayerXXX.h" */
#include "mdi_datatype.h"
#include "kal_release.h"
#include "Conversions.h"
#include "FileMgr.h"

#include "AudioPlayerDef.h"
#include "AudioPlayerType.h"
#include "AudioPlayerProt.h"
#include "AudioPlayerMainScreen.h"
#endif /* __MMI_AUDIO_PLAYER__ */ 

/* for R2L characters */
#include "BIDIDEF.h"
#include "BIDIProt.h"


#include "ScreenRotationGprot.h"

#include "Wgui_fixed_menuitems.h"
#include "Wgui_softkeys.h"

#include "gui_typedef.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "MMIDataType.h"
#include "gui_data_types.h"
#include "gui_windows.h"
#include "GlobalConstants.h"
#include "wgui_categories_defs.h"
#include "kal_general_types.h"
#include "wgui_categories_list.h"
#include "gui_buttons.h"
#include "CustDataRes.h"
#include "kal_public_api.h"
#include "gui.h"
#include "wgui.h"
#include "wgui_categories_sublcd.h"
#include "wgui_include.h"
#include "wgui_fixed_menus.h"
#include "wgui_inputs.h"
#include "gdi_include.h"
#include "mmi_frm_history_gprot.h"
#include "CustThemesRes.h"
#include "gui_themes.h"
#include "gui_switch.h"
#include "lcd_sw_inc.h"
#include "Gui_Setting.h"
#include "gui_fixed_menus.h"
#include "gui_fixed_menuitems.h"
#include "gui_config.h"
#include "wgui_dynamic_menuitems.h"
#include "wgui_asyncdynamic_menuitems.h"
#include "mmi_frm_input_gprot.h"
#include "wgui_draw_manager.h"
#include "wgui_categories_util.h"
#include "gui_theme_struct.h"
#include "wgui_categories_enum.h"
#include "DebugInitDef_Int.h"
#include "wgui_categories_inputs.h"
#include "gui_inputs.h"
#include "GlobalResDef.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_title.h"
#include "gui_effect_oem.h"
#include "gui_scrollbars.h"
#include "gui_virtual_keyboard.h"
#include "gui_menu_shortcut.h"
#include "gui_title_pre_oem.h"
#include "gui_title.h"
#include "gui_tab_bars_pre_oem.h"
#include "gui_tab_bars.h"
#include "wgui_inline_edit.h"
#include "gui_clock.h"
#include "PixcomFontEngine.h"

#include "wgui_asyncdynamic_menus.h"
#ifdef __ATV_SMS_SUPPORT__
#include "Mdi_audio.h"
#endif

#define WGUI_POPUP_DESCRIPTION_Y_GAP       1

#if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_MAINLCD_128X64__)
#define __MMI_RADIO_BUTTON_HIGHLIGHT_NO_SELECT__
#endif /* __MMI_FTE_SUPPORT__ || __MMI_MAINLCD_128X64__ */

/* Slim Version Menu Style */
static wgui_list_menu_slim_style_enum wgui_current_list_menu_slim_style = WGUI_LIST_MENU_SLIM_STYLE_DEFAULT;

/* Globals  */
gdi_handle animation_handle = GDI_ERROR_HANDLE;

/*** Store the value of height, width , x, y position of title bar ,status icons
    popup dialog in global variables these valeu r also #define in wgui.h */

/* move init value to wgui.c */
S32 MMI_matrix_bar_height;
S32 MMI_matrix_bar_x;
S32 MMI_matrix_bar_y;
S32 MMI_matrix_bar_width;
S32 MMI_title_height;
S32 MMI_title_width;
S32 MMI_title_x;
S32 MMI_title_y;
S32 MMI_button_bar_height;
S32 MMI_menuitem_height;
/* animated title icon */
S32 MMI_title_icon_x;
S32 MMI_title_icon_y;
S32 MMI_title_icon_width;
S32 MMI_title_icon_height;

S32 MMI_pop_up_dialog_x;
S32 MMI_pop_up_dialog_y;
S32 MMI_pop_up_dialog_width;
S32 MMI_pop_up_dialog_height;
S32 MMI_pop_up_dialog_full_height;

U8 wgui_switch_title_with_status_bar = 0;   /* 0: Title, 1: Status icons  */
U8 wgui_category_screen_no_buttons = 0;

/* Store the clipping value of current image */
S32 wgui_image_clip_x1 = 0;
S32 wgui_image_clip_y1 = 0;
S32 wgui_image_clip_x2 = 0;
S32 wgui_image_clip_y2 = 0;

/* Support for displaying animations in Category screens:
   These functions allow the display of a single animated
   icon in any category screen. The position of the icon
   is decided by the category screen                  */
PU8 _MMI_animated_icon = NULL;
U8 *_MMI_animated_icon_name;
S32 _MMI_animated_icon_x;
S32 _MMI_animated_icon_y;
UI_animated_image_handle _MMI_animated_icon_handle = NULL;

UI_pop_up_description wgui_pop_up_description;

/* store number of strigs of pop up */
S32 wgui_pop_up_descriptions_n_strings = 0;

/* store current index of popup */
S32 wgui_current_pop_up_description_index = -1;

/* store number of popup */
S32 wgui_pop_up_descriptions_n_items = 0;

/* store flag of popup */
U8 wgui_pop_up_description_flag = 0;

wgui_pop_up_description_string_type wgui_pop_up_description_strings[WGUI_MAX_POP_UP_DESCRIPTION_STRINGS];

U8 *checklist_category_menu_item_states = NULL;
S32 item_checked = 0;
void (*checkbox_toggle_DONE_RSK_function) (void) = NULL;
void (*checkbox_toggle_BACK_RSK_function) (void) = NULL;


/* Store the scrolling text of title bar */
scrolling_text scrolling_title_text;

/* Scrolling title support */
/** global variables store value of x,y,width of title bar text , icon to scroll the text on title bar */
S32 scrolling_title_icon_x = 0;
S32 scrolling_title_icon_y = 0;

/* Store the message of current multibox dispaly on main lcd */
UI_string_type MMI_message_string = NULL;
UI_string_type MMI_message_string2 = NULL;

/** Store the address of icon display on content area of current main lcd scrren */
PU8 MMI_message_icon = NULL;
PU8 MMI_message_icon2 = NULL;

/* Store the text of current highlighted item in menu */
UI_string_type MMI_highlighted_item_text = NULL;
/* Store the icon of current highlighted item in menu */
PU8 MMI_highlighted_item_icon = NULL;
/* high level wrappers  */
PU8 MMI_mm_animation = NULL;

U8 gMMI_UI_U8_flag_1 = 0, gMMI_UI_U8_flag_2 = 0;
U16 gMMI_UI_U16_var_1 = 0, gMMI_UI_U16_var_2 = 0;
S32 gMMI_UI_S32_var_1 = 0, gMMI_UI_S32_var_2 = 0, gMMI_UI_S32_var_3 = 0, gMMI_UI_S32_var_4 = 0;
void *gMMI_UI_ptr_1 = NULL, *gMMI_UI_ptr_2 = NULL, *gMMI_UI_ptr_3 = NULL, *gMMI_UI_ptr_4 = NULL;


MMI_BOOL gMMI_wallpaper_on_bottom = MMI_FALSE;      /* support wallpaper on bottom */


FuncPtr gExitFullScreenCallBack = NULL;
S32 gOnFullScreen = 0x00000000;

/* Add for Draw Manager */
S32 g_gui_current_catid = 0;


/* R2L characters */
#ifdef __MMI_BIDI_ALG__
extern U8 visual_str[];
#endif 

#ifdef __PLUTO_MMI_PACKAGE__
extern U16 gMainMenuAnimation[];
extern U16 gMainMenuTitleIcon[];
#endif
extern S32 volume_level_UI;

extern bitmap main_LCD_device_bitmap;
extern bitmap sub_LCD_device_bitmap;
extern bitmap *current_LCD_device_bitmap;

/* store Main lcd width */
extern S32 MAIN_LCD_device_width;

/* store Main LCD height */
extern S32 MAIN_LCD_device_height;

extern icontext_button MMI_softkeys[];

extern gdi_handle g_gui_ssp_static_layer;

#ifndef __MTK_TARGET__
/* MTE */
extern void mmi_mte_mmi_notify_new_screen(void);
#endif /* __MTK_TARGET__ */

/***************************************************************************** 
*  Dummy functions
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  dummy_get_history
 * DESCRIPTION
 *  Dummy function to get history
 * PARAMETERS
 *  buffer      [IN]        History buffer
 * RETURNS
 *  byte*
 *****************************************************************************/
U8 *dummy_get_history(U8 *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (buffer);
}   /* end of dummy_get_hisgory */


/*****************************************************************************
 * FUNCTION
 *  dummy_get_history_size
 * DESCRIPTION
 *  Dummy function to get history size
 * PARAMETERS
 *  void
 * RETURNS
 *  size of history
 *****************************************************************************/
S32 dummy_get_history_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (0);
}   /* end of dummy_get_history_size */

/***************************************************************************** 
*  Get Resource
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  get_string
 * DESCRIPTION
 *  Wrapper for GetString() function, to get string for given id
 * PARAMETERS
 *  i       [IN]        String id
 * RETURNS
 *  pointer to the string corresponding to the given string ID
 *****************************************************************************/
UI_string_type get_string(MMI_ID_TYPE i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type s = (UI_string_type) GetString((U16) i);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (s == NULL)
    {
        return (NULL);
    }
    if (s[0] == '\0')
    {
        return (NULL);
    }
    return ((UI_string_type) s);
}


/*****************************************************************************
 * FUNCTION
 *  get_image
 * DESCRIPTION
 *  Wrapper for GetImage() function
 * PARAMETERS
 *  i       [IN]        Image id
 * RETURNS
 *  pointer to the image corresponding to the given image ID
 *****************************************************************************/
PU8 get_image(MMI_ID_TYPE i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 s;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (i == 0)
    {
        return (NULL);
    }
    s = (PU8) GetImage((U16) i);
    if (s == NULL)
    {
        return (NULL);
    }

	if ( CheckIsEmptyImage(s))
    {
        return (NULL);
    }
    return ((PU8) s);
}


/*****************************************************************************
 * FUNCTION
 *  get_audio
 * DESCRIPTION
 *  Wrapper for GetAudio() function
 * PARAMETERS
 *  i           [IN]        Audio id
 *  type        [OUT]       Audio type
 *  filelen     [OUT]       File length
 * RETURNS
 *  pointer to the audio raw data corresponding to the given audio ID
 *****************************************************************************/
U8 *get_audio(MMI_ID_TYPE i, U8 *type, U32 *filelen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *s = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(type != NULL && filelen != NULL);

    *type = 0;;
    *filelen = 0;

    if (i == 0)
    {
        return (NULL);
    }

    s = (U8*) GetAudio((U16) i);
    if (s == NULL)
    {
        return (NULL);
    }
    if (s[0] == '\0')
    {
        return (NULL);
    }

    *type = s[0];

    *filelen |= (U32) (s[1]);
    *filelen |= (U32) ((U32) s[2] << 8);
    *filelen |= (U32) ((U32) s[3] << 16);
    *filelen |= (U32) ((U32) s[4] << 24);

    return (s + 8);
}


/***************************************************************************** 
* Category screen wrappers
*****************************************************************************/
/*****************************************************************************
* FUNCTION
*  MMI_list_highlight_handler
*
* DESCRIPTION
*   Function pointer store the address of function which get executed
*  when any item in list get high lighted
*
* PARAMETERS
*  item _index IN store the current index of item highlighted
* 
* RETURNS
*  void
*
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void (*MMI_list_highlight_handler) (S32 item_index);

/*****************************************************************************
* FUNCTION
*  MMI_matrix_highlight_handler
*
* DESCRIPTION
*   Function pointer store the address of function which get executed
*  when any item in matrix list get high lighted
*
* PARAMETERS
*  item _index IN store the current index of item highlighted
* 
* RETURNS
*  void
*
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void (*MMI_matrix_highlight_handler) (S32 item_index);

/*****************************************************************************
* FUNCTION
*  MMI_circular_3D_highlight_handler
*
* DESCRIPTION
*   Function pointer store the address of function which get executed
*  when any item in 3D circular list get high lighted
*
* PARAMETERS
*  item _index IN store the current index of item highlighted
* 
* RETURNS
*  void
*
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void (*MMI_circular_3D_highlight_handler) (S32 item_index);

/* For the main LCD  */
/*****************************************************************************
* FUNCTION
*  ExitCategoryFunction
*
* DESCRIPTION
*   Function pointer store the address of redraw category function of current
*  main lcd category scrren
*
* PARAMETERS
* 
* RETURNS
*  void
*
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void (*ExitCategoryFunction) (void) = UI_dummy_function;

/*****************************************************************************
* FUNCTION
*  RedrawCategoryFunction
*
* DESCRIPTION
*   Function pointer store the address of redraw category function of current
*  main lcd category scrren
*
* PARAMETERS
* 
* RETURNS
*  void
*
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void (*RedrawCategoryFunction) (void) = UI_dummy_function;

/*****************************************************************************
* FUNCTION
*  RedrawCategoryFunction
*
* DESCRIPTION
*   Function pointer store the address of getcategory history function of current
*  main lcd category scrren
*
* PARAMETERS
*  buffer   IN buffer store the valeu of history 
*
* RETURNS
*  U8*                        
*
* GLOBALS AFFECTED
*   buffer 
*****************************************************************************/
U8 *(*GetCategoryHistory) (U8 *buffer) = dummy_get_history;

/*****************************************************************************
* FUNCTION
*  RedrawInputMethodBoxesFunction
*
* DESCRIPTION
*   Function pointer store the address of RedrawInputMethodBoxesFunction
*
* PARAMETERS
* 
* RETURNS
*  void
*
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void (*RedrawSpellingOrCandidateBoxesFunction) (void) = UI_dummy_function;

/*****************************************************************************
* FUNCTION
*  GetCategoryHistorySize
*
* DESCRIPTION
*   Function pointer store the address of getcategory history size  function of current
*  main lcd category scrren
*
* PARAMETERS
* 
* RETURNS
*  S32   return size of history buffer
*
* GLOBALS AFFECTED
*   none
*****************************************************************************/
S32(*GetCategoryHistorySize) (void) = dummy_get_history_size;


/*****************************************************************************
 * FUNCTION
 *  initialize_category_screens
 * DESCRIPTION
 *  Called once during bootup to initialize category screens
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void initialize_category_screens(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RegisterHighlightHandler(MMI_dummy_highlight_handler);

    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = MMI_dummy_function;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;

    SUBLCD_ExitCategoryFunction = MMI_dummy_function;
    SUBLCD_RedrawCategoryFunction = MMI_dummy_function;
    SUBLCD_GetCategoryHistory = dummy_get_history;
    SUBLCD_GetCategoryHistorySize = dummy_get_history_size;
}   /* end of initialize_category_screens */


/*****************************************************************************
 * FUNCTION
 *  reset_category_functions
 * DESCRIPTION
 *  Calls the reset functions of all MMI objects and category screens
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_category_functions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    reset_softkeys();
//    reset_menu_shortcut_handler();
    reset_fixed_list();
    reset_fixed_matrix();
    reset_singleline_inputbox();
    reset_multiline_inputbox();
    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = MMI_dummy_function;
}   /* end of reset_category_functions */

U32 category_screen_layout_flags;


/*****************************************************************************
 * FUNCTION
 *  SetCategoryScreenLayout
 * DESCRIPTION
 *  set the layout of category screen
 * PARAMETERS
 *  flags       [IN]        Vaule to set flags
 * RETURNS
 *  void
 *****************************************************************************/
void SetCategoryScreenLayout(U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    category_screen_layout_flags = flags;
}   /* end of SetCategoryScreenLayout */

/***************************************************************************** 
* Start : Animation control
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  wgui_show_animation
 * DESCRIPTION
 *  Displays an animated icon that was set previously. If GIF library of
 *  pluto is enabled then it calls pluto animation function
 *  otherwise pixtel animation function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_show_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle lcd_h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_get_active(&lcd_h);

    if (lcd_h == GDI_LCD_MAIN_LCD_HANDLE)
    {
        gdi_image_draw_animation(_MMI_animated_icon_x, _MMI_animated_icon_y, _MMI_animated_icon, NULL);
    }
    else if (lcd_h == GDI_LCD_SUB_LCD_HANDLE)
    {
        gdi_image_draw_animation(
            SUBLCD_MMI_animated_icon_x,
            SUBLCD_MMI_animated_icon_y,
            SUBLCD_MMI_animated_icon,
            NULL);
    }
}   /* end of wgui_show_animation */


/*****************************************************************************
 * FUNCTION
 *  wgui_show_transparent_animation
 * DESCRIPTION
 *  Displays an animated icon that was set previously, with transparency
 *  If GIF library of pluto is enabled then it calls pluto animation function
 *  otherwise pixtel animation function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_show_transparent_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle lcd_h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_get_active(&lcd_h);

    if (lcd_h == GDI_LCD_MAIN_LCD_HANDLE)
    {
        gdi_image_draw_animation(_MMI_animated_icon_x, _MMI_animated_icon_y, _MMI_animated_icon, NULL);
    }
    else if (lcd_h == GDI_LCD_SUB_LCD_HANDLE)
    {
        gdi_image_draw_animation(
            SUBLCD_MMI_animated_icon_x,
            SUBLCD_MMI_animated_icon_y,
            SUBLCD_MMI_animated_icon,
            NULL);
    }
}   /* end of wgui_show_transparent_animation */


/*****************************************************************************
 * FUNCTION
 *  wgui_set_animation
 * DESCRIPTION
 *  Sets up the animated icon to be displayed in the category screens
 * PARAMETERS
 *  x           [IN]        X-coordinate of animation
 *  y           [IN]        Y-coordinate of animation
 *  img         [IN]        
 *  imag(?)     [IN]        Id of animation
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_set_animation(S32 x, S32 y, MMI_ID_TYPE img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_set_animation_image(x, y, get_image(img));
}   /* end of wgui_set_animation */


/*****************************************************************************
 * FUNCTION
 *  wgui_set_animation_y
 * DESCRIPTION
 *  Sets up the animated icon to be displayed in the category screens
 * PARAMETERS
 *  x           [IN]        Coordinates around which the icon is centered horizontally
 *  y           [IN]        Position from which the top of the icon is drawn
 *  img         [IN]        
 *  imag(?)     [IN]        Id of animation
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_set_animation_y(S32 x, S32 y, MMI_ID_TYPE img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_set_animation_image_y(x, y, get_image(img));
}   /* end of wgui_set_animation_y */


/*****************************************************************************
 * FUNCTION
 *  wgui_set_animation_image
 * DESCRIPTION
 *  Sets up the animated icon to be displayed in the category screens
 * PARAMETERS
 *  x           [IN]        Coordinates around which the icon is centered horizontally
 *  y           [IN]        Position from which of the icon is drawn centered.
 *  img         [IN]        
 *  imag(?)     [IN]        The icon to be displayed
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_set_animation_image(S32 x, S32 y, PU8 img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width, height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (UI_test_sub_LCD_graphics_context())
    {
        SUBLCD_MMI_animated_icon = img;
        if (SUBLCD_MMI_animated_icon == NULL)
        {
            return;
        }
        gui_measure_image(SUBLCD_MMI_animated_icon, &width, &height);
        SUBLCD_MMI_animated_icon_x = x - (width >> 1);
        SUBLCD_MMI_animated_icon_y = y - (height >> 1);
    }
    else
    {
        _MMI_animated_icon = img;
        if (_MMI_animated_icon == NULL)
        {
            return;
        }
        gui_measure_image(_MMI_animated_icon, &width, &height);
        _MMI_animated_icon_x = x - (width >> 1);
        _MMI_animated_icon_y = y - (height >> 1);
    }
}   /* end of wgui_set_animation_image */


/*****************************************************************************
 * FUNCTION
 *  wgui_set_animation_image_y
 * DESCRIPTION
 *  Sets up the animated icon to be displayed in the category screens
 * PARAMETERS
 *  x           [IN]        Coordinates around which the icon is centered horizontally
 *  y           [IN]        Position from which the top of the icon is drawn
 *  img         [IN]        
 *  imag(?)     [IN]        The icon to be displayed
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_set_animation_image_y(S32 x, S32 y, PU8 img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width, height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (UI_test_sub_LCD_graphics_context())
    {
        SUBLCD_MMI_animated_icon = img;
        if (SUBLCD_MMI_animated_icon == NULL)
        {
            return;
        }
        gui_measure_image(SUBLCD_MMI_animated_icon, &width, &height);
        SUBLCD_MMI_animated_icon_x = x - (width >> 1);
        SUBLCD_MMI_animated_icon_y = y;

    }
    else
    {
        _MMI_animated_icon = img;
        if (_MMI_animated_icon == NULL)
        {
            return;
        }
        gui_measure_image(_MMI_animated_icon, &width, &height);
        _MMI_animated_icon_x = x - (width >> 1);
        _MMI_animated_icon_y = y;
    }
}   /* end of wgui_set_animation_image_y */


/*****************************************************************************
 * FUNCTION
 *  wgui_measure_set_animation
 * DESCRIPTION
 *  Sets up the animated icon to be displayed in the category screens
 * PARAMETERS
 *  x           [IN]        Coordinates around which the icon is centered horizontally
 *  y           [IN]        Position from which the icon is drawn centered vertically.
 *  width       [?]         
 *  height      [?]         
 *  img         [IN]        
 *  imag(?)     [IN]        The id of icon to be displayed
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_measure_set_animation(S32 x, S32 y, S32 *width, S32 *height, MMI_ID_TYPE img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_measure_set_animation_image(x, y, width, height, get_image(img));
}


/*****************************************************************************
 * FUNCTION
 *  wgui_measure_set_animation_y
 * DESCRIPTION
 *  Sets up the animated icon to be displayed in the category screens
 * PARAMETERS
 *  x           [IN]        Coordinates around which the icon is centered horizontally
 *  y           [IN]        Position from which the top of the icon is drawn
 *  width       [?]         
 *  height      [?]         
 *  img         [IN]        
 *  imag(?)     [IN]        The id of icon to be displayed
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_measure_set_animation_y(S32 x, S32 y, S32 *width, S32 *height, MMI_ID_TYPE img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_measure_set_animation_image_y(x, y, width, height, get_image(img));
}


/*****************************************************************************
 * FUNCTION
 *  wgui_measure_set_animation_image
 * DESCRIPTION
 *  Sets up the animated icon to be displayed in the category screens
 * PARAMETERS
 *  x           [IN]        Coordinates around which the icon is centered horizontally
 *  y           [IN]        Position from which the icon is drawn centered vertically.
 *  width       [?]         
 *  height      [?]         
 *  img         [IN]        
 *  imag(?)     [IN]        The icon to be displayed
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_measure_set_animation_image(S32 x, S32 y, S32 *width, S32 *height, PU8 img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *width = 0;
    *height = 0;

    if (UI_test_sub_LCD_graphics_context())
    {
        SUBLCD_MMI_animated_icon = img;
        if (SUBLCD_MMI_animated_icon == NULL)
        {
            return;
        }
        gui_measure_image(SUBLCD_MMI_animated_icon, width, height);
        SUBLCD_MMI_animated_icon_x = x - ((*width) >> 1);
        SUBLCD_MMI_animated_icon_y = y - ((*height) >> 1);
    }
    else
    {
        _MMI_animated_icon = img;
        if (_MMI_animated_icon == NULL)
        {
            return;
        }
        gui_measure_image(_MMI_animated_icon, width, height);
        _MMI_animated_icon_x = x - ((*width) >> 1);
        _MMI_animated_icon_y = y - ((*height) >> 1);
    }
}   /* end of wgui_measure_set_animation_image */


/*****************************************************************************
 * FUNCTION
 *  wgui_measure_set_animation_image_y
 * DESCRIPTION
 *  Sets up the animated icon to be displayed in the category screens
 * PARAMETERS
 *  x           [IN]        Coordinates around which the icon is centered horizontally
 *  y           [IN]        Position from which the top of the icon is drawn
 *  width       [?]         
 *  height      [?]         
 *  img         [IN]        
 *  imag(?)     [IN]        The icon to be displayed
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_measure_set_animation_image_y(S32 x, S32 y, S32 *width, S32 *height, PU8 img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *width = 0;
    *height = 0;
    /* check whether the current graphic context is sub lcd */
    if (UI_test_sub_LCD_graphics_context())
    {
        SUBLCD_MMI_animated_icon = img;
        if (SUBLCD_MMI_animated_icon == NULL)
        {
            return;
        }
        gui_measure_image(SUBLCD_MMI_animated_icon, width, height);
        SUBLCD_MMI_animated_icon_x = x - ((*width) >> 1);
        SUBLCD_MMI_animated_icon_y = y;
    }
    else
    {
        _MMI_animated_icon = img;
        if (_MMI_animated_icon == NULL)
        {
            return;
        }
        gui_measure_image(_MMI_animated_icon, width, height);
        _MMI_animated_icon_x = x - ((*width) >> 1);
        _MMI_animated_icon_y = y;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_hide_animation
 * DESCRIPTION
 *  Hides the Category screen animation. Stop the animation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_hide_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (UI_test_sub_LCD_graphics_context())
    {
        gui_hide_animated_image(0, 0, SUBLCD_MMI_animated_icon_handle);
    }
    else
    {
        gui_hide_animated_image(0, 0, _MMI_animated_icon_handle);
    }
}

/***************************************************************************** 
* Common Utility
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  wgui_fill_rectangle_clip
 * DESCRIPTION
 *  set clip and draw rectangle
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_fill_rectangle_clip(S32 x1, S32 y1, S32 x2, S32 y2, color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);
    gui_fill_rectangle(x1, y1, x2, y2, c);
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  clear_screen_with_color
 * DESCRIPTION
 *  Clears the screen with specific color
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void clear_screen_with_color(color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_push_clip();
#if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_360X640__)
    if ((gOnFullScreen & MMI_IN_NORMAL_SCREEN)) /* current screen is not full screen */
    {
        gui_set_clip(0, MMI_title_y, UI_device_width - 1, UI_device_height - 1);
        gui_fill_rectangle(0, MMI_title_y, UI_device_width - 1, UI_device_height - 1, c);
    }
    else
#endif /* defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X240__) */ 
    {
        gui_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);
        gui_fill_rectangle(0, 0, UI_device_width - 1, UI_device_height - 1, c);
    }
    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  clear_screen
 * DESCRIPTION
 *  Clears the screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clear_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c.r = 255;
    c.g = 255;
    c.b = 255;
    c.alpha = 100;
    clear_screen_with_color(c);
}


/*****************************************************************************
 * FUNCTION
 *  clear_buttonbar
 * DESCRIPTION
 *  Clears the button bar portion of the screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clear_buttonbar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c = gui_color(255, 255, 255);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_reset_clip();
    if (UI_device_height == 128)
    {
        gui_fill_rectangle(0, UI_device_height - MMI_softkey_height - 10, UI_device_width - 1, UI_device_height - 1, c);
    }
    else
    if (whether_no_small_screen())
    {
        gui_fill_rectangle(0, UI_device_height - MMI_softkey_height, UI_device_width - 1, UI_device_height - 1, c);     
    }
    else
    {
        gui_fill_rectangle(0, UI_device_height - MMI_softkey_height - 4, UI_device_width - 1, UI_device_height - 1, c);
    }
}


/*****************************************************************************
 * FUNCTION
 *  set_button_bar_height
 * DESCRIPTION
 *  This function is used to set the button bar height
 * PARAMETERS
 *  height                      [IN]            
 *  UICtrlAccessPtr_p(?)        [IN/OUT]        It specifies the start position to take out the coordinates.
 *  dm_image_info_struct I  N/OUT image area coordinate info.(?)
 * RETURNS
 *  void
 *****************************************************************************/
void set_button_bar_height(S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_button_bar_height = height;
}


/*****************************************************************************
 * FUNCTION
 *  clear_contentarea
 * DESCRIPTION
 *  Clears the content area.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clear_contentarea(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c = gui_color(255, 255, 255);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_reset_clip();
    gui_fill_rectangle(0, (MMI_title_y + MMI_title_height), UI_device_width, UI_device_height - MMI_softkey_height, c);
}


/*****************************************************************************
 * FUNCTION
 *  draw_arrow_indication
 * DESCRIPTION
 *  Displays the arror key indication image
 * PARAMETERS
 *  left        [IN]        1:show, 0: hide
 *  right       [IN]        1:show, 0: hide
 *  up          [IN]        1:show, 0: hide
 *  down        [IN]        1:show, 0: hide
 * RETURNS
 *  void
 *****************************************************************************/
#define WGUI_COLOR_TO_GDI_FORMAT(c) gdi_act_color_from_rgb(255,c.r, c.g, c.b)
void draw_arrow_indication(S8 left, S8 right, S8 up, S8 down)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 center_x = 0, center_y = 0;
    S32 area_width = 20, area_height = MMI_button_bar_height - 2;
    S32 arrow_height = 5;
    color content= *current_MMI_theme->arrow_indication_color;
    color line = *current_MMI_theme->arrow_indication_border_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (left == 0 && right == 0 && up == 0 && down == 0)
    {
        return;
    }

    
#ifdef __MMI_SCREEN_ROTATE__
    if (mmi_frm_is_screen_width_height_swapped())
    {
        area_height = MMI_BUTTON_BAR_HEIGHT - 2;
        center_x = MMI_ROTATED_LCD_WIDTH -  (MMI_BUTTON_BAR_HEIGHT >> 1);
        center_y = MMI_ROTATED_LCD_HEIGHT >> 1;
        gui_push_clip();
        gui_set_clip(MMI_ROTATED_LCD_HEIGHT - MMI_BUTTON_BAR_HEIGHT, 0, MMI_ROTATED_LCD_WIDTH, MMI_ROTATED_LCD_HEIGHT);
    }
    else
#endif
    {
        center_x = UI_device_width >> 1;
        center_y = UI_device_height - (MMI_button_bar_height >> 1);
        gui_push_clip();
        gui_set_clip(0, UI_device_height - MMI_button_bar_height, UI_device_width, UI_device_height);
    }


    if (up >= 1)
    {
        gdi_draw_line(
            center_x - 3,
            center_y - ((area_height >> 1) - arrow_height),
            center_x + 3,
            center_y - ((area_height >> 1) - arrow_height),
            WGUI_COLOR_TO_GDI_FORMAT(line));
        gdi_draw_point(
            center_x - 3,
            center_y - ((area_height >> 1) - arrow_height) - 1,
            WGUI_COLOR_TO_GDI_FORMAT(line));
        gdi_draw_point(
            center_x + 3,
            center_y - ((area_height >> 1) - arrow_height) - 1,
            WGUI_COLOR_TO_GDI_FORMAT(line));
        gdi_draw_point(
            center_x - 2,
            center_y - ((area_height >> 1) - arrow_height) - 2,
            WGUI_COLOR_TO_GDI_FORMAT(line));
        gdi_draw_point(
            center_x + 2,
            center_y - ((area_height >> 1) - arrow_height) - 2,
            WGUI_COLOR_TO_GDI_FORMAT(line));
        gdi_draw_point(
            center_x - 1,
            center_y - ((area_height >> 1) - arrow_height) - 3,
            WGUI_COLOR_TO_GDI_FORMAT(line));
        gdi_draw_point(
            center_x + 1,
            center_y - ((area_height >> 1) - arrow_height) - 3,
            WGUI_COLOR_TO_GDI_FORMAT(line));
        gdi_draw_point(center_x, center_y - ((area_height >> 1) - arrow_height) - 4, WGUI_COLOR_TO_GDI_FORMAT(line));

        gdi_draw_point(
            center_x - 2,
            center_y - ((area_height >> 1) - arrow_height) - 1,
            WGUI_COLOR_TO_GDI_FORMAT(content));
        gdi_draw_point(
            center_x - 1,
            center_y - ((area_height >> 1) - arrow_height) - 1,
            WGUI_COLOR_TO_GDI_FORMAT(content));
        gdi_draw_point(center_x, center_y - ((area_height >> 1) - arrow_height) - 1, WGUI_COLOR_TO_GDI_FORMAT(content));
        gdi_draw_point(
            center_x + 1,
            center_y - ((area_height >> 1) - arrow_height) - 1,
            WGUI_COLOR_TO_GDI_FORMAT(content));
        gdi_draw_point(
            center_x + 2,
            center_y - ((area_height >> 1) - arrow_height) - 1,
            WGUI_COLOR_TO_GDI_FORMAT(content));
        gdi_draw_point(
            center_x - 1,
            center_y - ((area_height >> 1) - arrow_height) - 2,
            WGUI_COLOR_TO_GDI_FORMAT(content));
        gdi_draw_point(center_x, center_y - ((area_height >> 1) - arrow_height) - 2, WGUI_COLOR_TO_GDI_FORMAT(content));
        gdi_draw_point(
            center_x + 1,
            center_y - ((area_height >> 1) - arrow_height) - 2,
            WGUI_COLOR_TO_GDI_FORMAT(content));
        gdi_draw_point(center_x, center_y - ((area_height >> 1) - arrow_height) - 3, WGUI_COLOR_TO_GDI_FORMAT(content));
    }
    if (down >= 1)
    {
        gdi_draw_line(
            center_x - 3,
            center_y + ((area_height >> 1) - arrow_height),
            center_x + 3,
            center_y + ((area_height >> 1) - arrow_height),
            WGUI_COLOR_TO_GDI_FORMAT(line));
        gdi_draw_point(
            center_x - 3,
            center_y + ((area_height >> 1) - arrow_height) + 1,
            WGUI_COLOR_TO_GDI_FORMAT(line));
        gdi_draw_point(
            center_x + 3,
            center_y + ((area_height >> 1) - arrow_height) + 1,
            WGUI_COLOR_TO_GDI_FORMAT(line));
        gdi_draw_point(
            center_x - 2,
            center_y + ((area_height >> 1) - arrow_height) + 2,
            WGUI_COLOR_TO_GDI_FORMAT(line));
        gdi_draw_point(
            center_x + 2,
            center_y + ((area_height >> 1) - arrow_height) + 2,
            WGUI_COLOR_TO_GDI_FORMAT(line));
        gdi_draw_point(
            center_x - 1,
            center_y + ((area_height >> 1) - arrow_height) + 3,
            WGUI_COLOR_TO_GDI_FORMAT(line));
        gdi_draw_point(
            center_x + 1,
            center_y + ((area_height >> 1) - arrow_height) + 3,
            WGUI_COLOR_TO_GDI_FORMAT(line));
        gdi_draw_point(center_x, center_y + ((area_height >> 1) - arrow_height) + 4, WGUI_COLOR_TO_GDI_FORMAT(line));

        gdi_draw_point(
            center_x - 2,
            center_y + ((area_height >> 1) - arrow_height) + 1,
            WGUI_COLOR_TO_GDI_FORMAT(content));
        gdi_draw_point(
            center_x - 1,
            center_y + ((area_height >> 1) - arrow_height) + 1,
            WGUI_COLOR_TO_GDI_FORMAT(content));
        gdi_draw_point(center_x, center_y + ((area_height >> 1) - arrow_height) + 1, WGUI_COLOR_TO_GDI_FORMAT(content));
        gdi_draw_point(
            center_x + 1,
            center_y + ((area_height >> 1) - arrow_height) + 1,
            WGUI_COLOR_TO_GDI_FORMAT(content));
        gdi_draw_point(
            center_x + 2,
            center_y + ((area_height >> 1) - arrow_height) + 1,
            WGUI_COLOR_TO_GDI_FORMAT(content));
        gdi_draw_point(
            center_x - 1,
            center_y + ((area_height >> 1) - arrow_height) + 2,
            WGUI_COLOR_TO_GDI_FORMAT(content));
        gdi_draw_point(center_x, center_y + ((area_height >> 1) - arrow_height) + 2, WGUI_COLOR_TO_GDI_FORMAT(content));
        gdi_draw_point(
            center_x + 1,
            center_y + ((area_height >> 1) - arrow_height) + 2,
            WGUI_COLOR_TO_GDI_FORMAT(content));
        gdi_draw_point(center_x, center_y + ((area_height >> 1) - arrow_height) + 3, WGUI_COLOR_TO_GDI_FORMAT(content));
    }
    if (left >= 1)
    {
        gdi_draw_line(
            center_x - ((area_width >> 1) - arrow_height),
            center_y - 3,
            center_x - ((area_width >> 1) - arrow_height),
            center_y + 3,
            WGUI_COLOR_TO_GDI_FORMAT(line));
        gdi_draw_point(center_x - ((area_width >> 1) - arrow_height) - 1, center_y - 3, WGUI_COLOR_TO_GDI_FORMAT(line));
        gdi_draw_point(center_x - ((area_width >> 1) - arrow_height) - 1, center_y + 3, WGUI_COLOR_TO_GDI_FORMAT(line));
        gdi_draw_point(center_x - ((area_width >> 1) - arrow_height) - 2, center_y - 2, WGUI_COLOR_TO_GDI_FORMAT(line));
        gdi_draw_point(center_x - ((area_width >> 1) - arrow_height) - 2, center_y + 2, WGUI_COLOR_TO_GDI_FORMAT(line));
        gdi_draw_point(center_x - ((area_width >> 1) - arrow_height) - 3, center_y - 1, WGUI_COLOR_TO_GDI_FORMAT(line));
        gdi_draw_point(center_x - ((area_width >> 1) - arrow_height) - 3, center_y + 1, WGUI_COLOR_TO_GDI_FORMAT(line));
        gdi_draw_point(center_x - ((area_width >> 1) - arrow_height) - 4, center_y, WGUI_COLOR_TO_GDI_FORMAT(line));

        gdi_draw_point(
            center_x - ((area_width >> 1) - arrow_height) - 1,
            center_y - 2,
            WGUI_COLOR_TO_GDI_FORMAT(content));
        gdi_draw_point(
            center_x - ((area_width >> 1) - arrow_height) - 1,
            center_y - 1,
            WGUI_COLOR_TO_GDI_FORMAT(content));
        gdi_draw_point(center_x - ((area_width >> 1) - arrow_height) - 1, center_y, WGUI_COLOR_TO_GDI_FORMAT(content));
        gdi_draw_point(
            center_x - ((area_width >> 1) - arrow_height) - 1,
            center_y + 1,
            WGUI_COLOR_TO_GDI_FORMAT(content));
        gdi_draw_point(
            center_x - ((area_width >> 1) - arrow_height) - 1,
            center_y + 2,
            WGUI_COLOR_TO_GDI_FORMAT(content));
        gdi_draw_point(
            center_x - ((area_width >> 1) - arrow_height) - 2,
            center_y - 1,
            WGUI_COLOR_TO_GDI_FORMAT(content));
        gdi_draw_point(center_x - ((area_width >> 1) - arrow_height) - 2, center_y, WGUI_COLOR_TO_GDI_FORMAT(content));
        gdi_draw_point(
            center_x - ((area_width >> 1) - arrow_height) - 2,
            center_y + 1,
            WGUI_COLOR_TO_GDI_FORMAT(content));
        gdi_draw_point(center_x - ((area_width >> 1) - arrow_height) - 3, center_y, WGUI_COLOR_TO_GDI_FORMAT(content));

    }
    if (right >= 1)
    {
        gdi_draw_line(
            center_x + ((area_width >> 1) - arrow_height),
            center_y - 3,
            center_x + ((area_width >> 1) - arrow_height),
            center_y + 3,
            WGUI_COLOR_TO_GDI_FORMAT(line));
        gdi_draw_point(center_x + ((area_width >> 1) - arrow_height) + 1, center_y - 3, WGUI_COLOR_TO_GDI_FORMAT(line));
        gdi_draw_point(center_x + ((area_width >> 1) - arrow_height) + 1, center_y + 3, WGUI_COLOR_TO_GDI_FORMAT(line));
        gdi_draw_point(center_x + ((area_width >> 1) - arrow_height) + 2, center_y - 2, WGUI_COLOR_TO_GDI_FORMAT(line));
        gdi_draw_point(center_x + ((area_width >> 1) - arrow_height) + 2, center_y + 2, WGUI_COLOR_TO_GDI_FORMAT(line));
        gdi_draw_point(center_x + ((area_width >> 1) - arrow_height) + 3, center_y - 1, WGUI_COLOR_TO_GDI_FORMAT(line));
        gdi_draw_point(center_x + ((area_width >> 1) - arrow_height) + 3, center_y + 1, WGUI_COLOR_TO_GDI_FORMAT(line));
        gdi_draw_point(center_x + ((area_width >> 1) - arrow_height) + 4, center_y, WGUI_COLOR_TO_GDI_FORMAT(line));

        gdi_draw_point(
            center_x + ((area_width >> 1) - arrow_height) + 1,
            center_y - 2,
            WGUI_COLOR_TO_GDI_FORMAT(content));
        gdi_draw_point(
            center_x + ((area_width >> 1) - arrow_height) + 1,
            center_y - 1,
            WGUI_COLOR_TO_GDI_FORMAT(content));
        gdi_draw_point(center_x + ((area_width >> 1) - arrow_height) + 1, center_y, WGUI_COLOR_TO_GDI_FORMAT(content));
        gdi_draw_point(
            center_x + ((area_width >> 1) - arrow_height) + 1,
            center_y + 1,
            WGUI_COLOR_TO_GDI_FORMAT(content));
        gdi_draw_point(
            center_x + ((area_width >> 1) - arrow_height) + 1,
            center_y + 2,
            WGUI_COLOR_TO_GDI_FORMAT(content));
        gdi_draw_point(
            center_x + ((area_width >> 1) - arrow_height) + 2,
            center_y - 1,
            WGUI_COLOR_TO_GDI_FORMAT(content));
        gdi_draw_point(center_x + ((area_width >> 1) - arrow_height) + 2, center_y, WGUI_COLOR_TO_GDI_FORMAT(content));
        gdi_draw_point(
            center_x + ((area_width >> 1) - arrow_height) + 2,
            center_y + 1,
            WGUI_COLOR_TO_GDI_FORMAT(content));
        gdi_draw_point(center_x + ((area_width >> 1) - arrow_height) + 3, center_y, WGUI_COLOR_TO_GDI_FORMAT(content));

    }

    gui_pop_clip(); 
}


/*****************************************************************************
 * FUNCTION
 *  SetHighlightedItem
 * DESCRIPTION
 *  Highlights a given item in a menu screen
 * PARAMETERS
 *  item_index      [IN]        Index (zero based) of the item to be highlighted
 * RETURNS
 *  void
 *****************************************************************************/
void SetHighlightedItem(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (MMI_current_menu_type)
    {
        case PAGE_MENU:
        case LIST_MENU:
        case ANI_BG_LIST_MENU:
            fixed_list_goto_item(item_index);
            break;

        case MATRIX_MENU:
        case MATRIX_PAGE_MENU:
            fixed_matrix_goto_item(item_index);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetHighlightedItem
 * DESCRIPTION
 *  Returns the index of the highlighted item
 * PARAMETERS
 *  void
 * RETURNS
 *  Returns the index of the highlighted item
 *****************************************************************************/
S32 GetHighlightedItem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (MMI_current_menu_type)
    {
        case PAGE_MENU:
        case LIST_MENU:
        case ANI_BG_LIST_MENU:
            return (MMI_fixed_list_menu.highlighted_item);

        case MATRIX_MENU:
        case MATRIX_PAGE_MENU:
            return (MMI_fixed_matrix_menu.highlighted_item);
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  get_item_text
 * DESCRIPTION
 *  Gets the text of the item at the given index in the currently displayed menu
 * PARAMETERS
 *  index       [IN]        (zero based) index of the item whose text needs to be retrieved
 * RETURNS
 *  a pointer to the text of the specified item
 *****************************************************************************/
UI_string_type get_item_text(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (MMI_current_menu_type)
    {
        case LIST_MENU:
        case PAGE_MENU:
        case ANI_BG_LIST_MENU:
            if (index >= 0 && index < MMI_fixed_list_menu.n_items)
            {
                if (MMI_fixed_list_menu.common_item_data == (void*)&MMI_fixed_text_menuitem)
                {
                    return (MMI_fixed_text_menuitems[index].item_text);
                }
                else if (MMI_fixed_list_menu.common_item_data == (void*)&MMI_fixed_icontext_menuitem)
                {
                    return (MMI_fixed_icontext_menuitems[index].item_text);
                }
                else if (MMI_fixed_list_menu.common_item_data == (void*)&MMI_fixed_icontext_list_menuitem)
                {
                    return (MMI_fixed_icontext_list_menuitems[index].item_texts[0]);
                }
            }
            break;

        case MATRIX_MENU:
        case MATRIX_MENU_EMS:
        case MATRIX_PAGE_MENU:
            if (index >= 0 && index < MMI_fixed_matrix_menu.n_items)
            {
                if (MMI_fixed_matrix_menu.common_item_data == (void*)&MMI_fixed_text_menuitem)
                {
                    return (MMI_fixed_text_menuitems[index].item_text);
                }
                else if (MMI_fixed_matrix_menu.common_item_data == (void*)&MMI_fixed_icontext_menuitem)
                {
                    return (MMI_fixed_icontext_menuitems[index].item_text);
                }
                else if (MMI_fixed_matrix_menu.common_item_data == (void*)&MMI_fixed_icontext_list_menuitem)
                {
                    return (MMI_fixed_icontext_list_menuitems[index].item_texts[0]);
                }
            }
            break;

        #if(ENABLE_CIRCULAR_3D_MENU)
        case CIRCULAR_3D_MENU:
            if (index >= 0 && index < wgui_CM3D_n_items)
            {
                return (wgui_CM3D_items[index]);
            }
            break;
        #endif /* (ENABLE_CIRCULAR_3D_MENU) */ 
        #if(ENABLE_ROTATE_MENU) 
        case ROTATE_MENU:
            if (index >= 0 && index < wgui_CM3D_n_items)
            {
                return (wgui_CM3D_items[index]);
            }
            break;
        #endif /* (ENABLE_ROTATE_MENU) */ 
    }
    return (NULL);
}


/*****************************************************************************
 * FUNCTION
 *  get_dynamic_item_text
 * DESCRIPTION
 *  get dynamic item text
 * PARAMETERS
 *  index       [IN]        Index of list
 * RETURNS
 *  UI_string_type
 *****************************************************************************/
UI_string_type get_dynamic_item_text(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fixed_icontext_menuitem_type *item_p = get_dynamic_item_from_buffer(index);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_p != NULL)
    {
        return item_p->item_text;
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  get_dynamic_item_text
 * DESCRIPTION
 *  get dynamic item text
 * PARAMETERS
 *  index       [IN]        Index of list
 * RETURNS
 *  UI_string_type
 *****************************************************************************/
PU8 get_dynamic_item_icon(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fixed_icontext_menuitem_type *item_p = get_dynamic_item_from_buffer(index);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_p != NULL)
    {
        return item_p->item_icon;
    }

    return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  get_asyncdynamic_item_icon
 * DESCRIPTION
 *  get asyncdynamic item text
 * PARAMETERS
 *  index       [IN]        Index of list
 * RETURNS
 *  UI_string_type
 *****************************************************************************/
PU8 get_asyncdynamic_item_icon(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fixed_icontext_list_menuitem_type *item_p = get_asyncdynamic_item_from_buffer(index);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_p != NULL)
    {
        return item_p->item_icons[0];
    }

    return NULL;
}

#ifdef ENABLE_BOTTOM_NAVIGATION_KEYS
/*to enable the navigation keys on the soft key bar.*/
/*Utilty Function added to show navigation icon between soft keys.*/


/*****************************************************************************
 * FUNCTION
 *  gui_show_navigation_keys
 * DESCRIPTION
 *  show navigation keys
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_navigation_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 left= 0;
    S8 right= 0;
    S8 up= 0;
    S8 down = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_frm_get_key_handler(KEY_UP_ARROW, KEY_EVENT_DOWN) != 0) || (mmi_frm_get_key_handler(KEY_UP_ARROW, KEY_EVENT_UP) != 0))
    {
        up = 1;
    }

    if ((mmi_frm_get_key_handler(KEY_DOWN_ARROW, KEY_EVENT_DOWN) != 0) || (mmi_frm_get_key_handler(KEY_DOWN_ARROW, KEY_EVENT_UP) != 0))
    {
        down = 1;
    }

    if ((mmi_frm_get_key_handler(KEY_LEFT_ARROW, KEY_EVENT_DOWN) != 0) || (mmi_frm_get_key_handler(KEY_LEFT_ARROW, KEY_EVENT_UP) != 0))
    {
        left = 1;
    }

    if ((mmi_frm_get_key_handler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN) != 0) ||
        (mmi_frm_get_key_handler(KEY_RIGHT_ARROW, KEY_EVENT_UP) != 0))
    {
        right = 1;
    }
    draw_arrow_indication(left, right, up, down);
}
#endif /* ENABLE_BOTTOM_NAVIGATION_KEYS */ 


/*****************************************************************************
 * FUNCTION
 *  DisableCategoryScreenScrollBar
 * DESCRIPTION
 *  Disable showing scroll bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DisableCategoryScreenScrollBar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    flag_scroll = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  SetupCategoryKeyHandlers
 * DESCRIPTION
 *  Common functions to clear all key handlers and setup default softkey handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetupCategoryKeyHandlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_category_screen_key_handlers();
    clear_left_softkey();
    clear_right_softkey();
    clear_softkey_display_functions(MMI_CENTER_SOFTKEY);
    register_left_softkey_handler();
    register_right_softkey_handler();
	register_softkey_handler(MMI_CENTER_SOFTKEY);
    register_default_hide_softkeys();
}

/***************************************************************************** 
* UI_STYLE_3 Full Screen Control Related Functions
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  set_exit_full_screen_call_back
 * DESCRIPTION
 *  set callback function when exit full screen
 * PARAMETERS
 *  f       [IN]        Callback function
 * RETURNS
 *  void
 *****************************************************************************/
void set_exit_full_screen_call_back(FuncPtr f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gExitFullScreenCallBack = f;
}

/*****************************************************************************
 * FUNCTION
 *  wgui_set_java_screen
 * DESCRIPTION
 *  set gOnFullScreen flag to java screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_set_java_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gOnFullScreen |= MMI_IN_JAVA_SCREEN;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_unset_java_screen
 * DESCRIPTION
 *  unset gOnFullScreen flag to java screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_unset_java_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gOnFullScreen &= ~MMI_IN_JAVA_SCREEN;
}

/*****************************************************************************
 * FUNCTION
 *  entry_full_screen
 * DESCRIPTION
 *  turn on gOnFullScreen flag, to redraw status icons
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_full_screen(void)
{
#if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_360X640__) || defined (__MMI_MAINLCD_480X800__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_H_BAR);
#ifdef WGUI_STATUS_ICON_SHOW_V_BAR    
    wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_V_BAR);
#endif
    gOnFullScreen = MMI_IN_FULL_SCREEN;
    set_exit_full_screen_call_back(leave_full_screen);
    dm_set_scr_bg_redraw(MMI_TRUE);
#endif /* defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X240__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  leave_full_screen
 * DESCRIPTION
 *  turn on gIsRedrawStatusIcons flag, to redraw status icons
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void leave_full_screen(void)
{
#if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_360X640__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gOnFullScreen |= MMI_LEAVE_FULL_SCREEN;
#endif /* defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X240__) */ 
}
void show_hide_status_icons_bar0(void);


/*****************************************************************************
 * FUNCTION
 *  in_idle_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void in_idle_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (!defined(__MMI_MAINLCD_128X128__)) && (!defined (__MMI_MAINLCD_128X160__)) && (!defined (__MMI_MAINLCD_128X64__))
    gOnFullScreen = MMI_IN_IDLE_SCREEN;
    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR);
  #if !defined(__MMI_MAINLCD_320X480__) &&  !defined (__MMI_MAINLCD_360X640__)
    #ifdef WGUI_STATUS_ICON_SHOW_V_BAR    
    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_V_BAR);
    #endif
  #endif
    dm_set_scr_bg_redraw(MMI_TRUE);
#endif /* (!defined(__MMI_MAINLCD_128X128__)) && (!defined (__MMI_MAINLCD_128X160__)) */
}


/*****************************************************************************
 * FUNCTION
 *  leave_idle_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void leave_idle_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (!defined(__MMI_MAINLCD_128X128__)) && (!defined (__MMI_MAINLCD_128X160__)) && (!defined (__MMI_MAINLCD_128X64__))
#ifdef WGUI_STATUS_ICON_SHOW_V_BAR    
    wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_V_BAR);
#endif
#ifdef __MMI_IDLE_FULL_SCREEN__
    gOnFullScreen |= MMI_LEAVE_FULL_IDLE_SCREEN;
    gOnFullScreen |= MMI_LEAVE_FULL_SCREEN;
    gOnFullScreen &= ~MMI_IN_IDLE_SCREEN;
#endif /* __MMI_IDLE_FULL_SCREEN__ */
#endif /* (!defined(__MMI_MAINLCD_128X128__)) && (!defined (__MMI_MAINLCD_128X160__)) */
}


/*****************************************************************************
 * FUNCTION
 *  if_full_screen_hide_status_icons
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL if_full_screen_hide_status_icons(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* for close status icons above titlebar */
    if (gOnFullScreen == MMI_IN_NORMAL_SCREEN_WITHOUT_STATUSBAR)
    {
        return MMI_TRUE;
    }
    if (gOnFullScreen == MMI_IN_IDLE_SCREEN)
    {
        return MMI_FALSE;
    }
    /* just leave from full screen (except full idlescreen ) */
    if (gOnFullScreen & MMI_LEAVE_FULL_SCREEN && !(gOnFullScreen & MMI_LEAVE_FULL_IDLE_SCREEN))
    {
        return MMI_TRUE;
    }
    /* now in full screen */
    if (gOnFullScreen & MMI_IN_FULL_SCREEN)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  reset_title_status_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_title_status_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X240__)  || defined(__MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_360X640__)
    gOnFullScreen = MMI_IN_FULL_SCREEN | MMI_LEAVE_FULL_SCREEN;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  close_title_status_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void close_title_status_icon(void)
{
#if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X240__)  || defined(__MMI_MAINLCD_320X480__)       || defined (__MMI_MAINLCD_360X640__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gOnFullScreen = MMI_IN_NORMAL_SCREEN_WITHOUT_STATUSBAR;
    wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_H_BAR);
#ifdef WGUI_STATUS_ICON_SHOW_V_BAR        
    wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_V_BAR);
#endif
#endif /* defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X240__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  show_title_status_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_title_status_icon(void)
{
#if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_360X640__)|| defined (__MMI_MAINLCD_480X800__) || defined(__MMI_MAINLCD_96X64__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!whether_no_small_screen())
    {
        gOnFullScreen = MMI_IN_NORMAL_SCREEN;
        wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR);
        wgui_status_icon_bar_update();
    }
#endif /* defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X240__)  || defined(__MMI_MAINLCD_96X64__)*/ 
}

/***************************************************************************** 
* History related wrappers
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  history_valid
 * DESCRIPTION
 *  Returns true if the history ID is valid
 * PARAMETERS
 *  history_ID              [IN]        Is the value obtained by reading the history buffer
 *  category_screen_ID      [IN]        Is the category screen's ID
 * RETURNS
 *  true  if the given history ID is valid
 *  false if the given history ID is not valid
 *****************************************************************************/
U8 history_valid(U16 history_ID, U16 category_screen_ID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((history_ID & 0x8000) && ((history_ID & 0x7fff) == category_screen_ID))
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
 *  wgui_cat_block_list_effect
 * DESCRIPTION
 *  block list effect of next category.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat_block_list_effect(void)
{
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */   
}


/*****************************************************************************
 * FUNCTION
 *  check_list_menu_history_valid
 * DESCRIPTION
 *  Returns true if the history ID and menu item count are valid
 *
 *  If the number of menu items recorded in history is different than the current setting,
 *  then the history is invalid.
 * PARAMETERS
 *  history_ID              [IN]        Is the history ID recorded in history 
 *  num_items               [IN]        Is the number of menu items recorded in history 
 *  category_screen_ID      [IN]        Is the category screen's ID
 * RETURNS
 *  true  if the given history ID is valid
 *  false if the given history ID is not valid
 *****************************************************************************/
static U8 check_list_menu_history_valid(U16 history_ID, S32 num_items, U16 category_screen_ID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((history_ID & 0x8000) && ((history_ID & 0x7fff) == category_screen_ID) &&
        (num_items == MMI_fixed_list_menu.n_items))
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
 *  change_list_menu_category_history
 * DESCRIPTION
 *  change the highlight index of category screen
 * PARAMETERS
 *  history_buffer              [IN]        History buffer
 *  new_highlighted_index       [IN]        New highlighted index
 *  new_n_items                 [IN]        Number of items
 *  flag                        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void change_list_menu_category_history(U8 *history_buffer, S32 new_highlighted_index, S32 new_n_items, U8 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_UI_LIST_SCROLL_BY_PIXEL__)
	MMI_BOOL IsChange = MMI_FALSE;
#endif /* __MMI_UI_LIST_SCROLL_BY_PIXEL__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((new_highlighted_index < 0) || (new_highlighted_index > (new_n_items - 1)))
    {
        return;
    }
    if (history_buffer != NULL)
    {
        S32 first_displayed_item;
        list_menu_category_history *h = (list_menu_category_history*) history_buffer;

        first_displayed_item = h->first_displayed_item;
        if (new_highlighted_index < first_displayed_item)
        {
            h->first_displayed_item = new_highlighted_index;
		#if defined(__MMI_UI_LIST_SCROLL_BY_PIXEL__)
			if (h->flags & UI_LIST_MENU_INEQUAL_HEIGHT_ITEMS)
			{
				h->last_displayed_item = new_highlighted_index;
				IsChange = MMI_TRUE;
			}
		#endif /* __MMI_UI_LIST_SCROLL_BY_PIXEL__ */
        }
        if (new_highlighted_index == (new_n_items - 1))
        {
        #if defined(__MMI_UI_LIST_SCROLL_BY_PIXEL__)
			if (h->flags & UI_LIST_MENU_INEQUAL_HEIGHT_ITEMS)
			{
				if ((h->highlighted_item != new_highlighted_index) || (h->num_items != new_n_items))
				{
					if (h->last_displayed_item != new_highlighted_index - 1)
					{
						IsChange = MMI_TRUE;
					}
					h->first_displayed_item = new_highlighted_index - 1;
					if (h->first_displayed_item < 0)
					{
						h->first_displayed_item = 0;
					}
					h->last_displayed_item = new_highlighted_index - 1;
				}
			}
			else
			{
				h->last_displayed_item = new_highlighted_index - 1;
			}
		#else /* __MMI_UI_LIST_SCROLL_BY_PIXEL__ */
            h->last_displayed_item = new_highlighted_index - 1;
		#endif /* __MMI_UI_LIST_SCROLL_BY_PIXEL__ */
        }
        h->highlighted_item = new_highlighted_index;
        if (flag)
        {
            h->first_displayed_item = new_highlighted_index;
		#if defined(__MMI_UI_LIST_SCROLL_BY_PIXEL__)
			if (h->flags & UI_LIST_MENU_INEQUAL_HEIGHT_ITEMS)
			{
				if (first_displayed_item != new_highlighted_index)
				{
					IsChange = MMI_TRUE;
				}
			}
		#endif /* __MMI_UI_LIST_SCROLL_BY_PIXEL__ */
            h->flags |= UI_LIST_MENU_FIRST_SHIFT_HIGHLIGHTED_ITEM;
        }
	#if defined(__MMI_UI_LIST_SCROLL_BY_PIXEL__)
		if (h->flags & UI_LIST_MENU_INEQUAL_HEIGHT_ITEMS)
		{
		    h->flags |= UI_LIST_MENU_ENABLE_GOTO_HALF_ITEM;
			if ((IsChange) || (h->num_items != new_n_items))
			{
				h->first_displayed_offset = 0;
				h->last_displayed_offset = 0;
				wgui_cat_list_menu_set_changeitem(MMI_TRUE);
			}
		}
	#endif /* __MMI_UI_LIST_SCROLL_BY_PIXEL__ */
        h->num_items = new_n_items;
    }
}


/*****************************************************************************
 * FUNCTION
 *  create_list_menu_category_history
 * DESCRIPTION
 *  change the highlight index of category screen
 * 
 *  Remark: deprecated API
 * PARAMETERS
 *  history_ID                  [IN]        Histiry id
 *  history_buffer              [IN]        History buffer
 *  new_highlighted_index       [IN]        New highlighted index
 *  new_n_items                 [IN]        Number of items
 *  flag                        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void create_list_menu_category_history(
        S32 history_ID,
        U8 *history_buffer,
        S32 new_highlighted_index,
        S32 new_n_items,
        U8 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((new_highlighted_index < 0) || (new_highlighted_index > (new_n_items - 1)))
    {
        return;
    }
    if (history_buffer != NULL)
    {
        list_menu_category_history *h = (list_menu_category_history*) history_buffer;

        h->first_displayed_item = 0;
        h->highlighted_item = new_highlighted_index;
        h->history_ID = (U16) (history_ID | 0x8000);
        h->flags = current_UI_theme->fixed_list_menu_theme->flags;
        h->displayed_items = 0;
        h->last_displayed_item = 0;
	#if defined(__MMI_UI_LIST_SCROLL_BY_PIXEL__)
		h->first_displayed_offset = 0;
		h->last_displayed_offset = 0;
	#endif /* __MMI_UI_LIST_SCROLL_BY_PIXEL__ */
        if (new_highlighted_index < h->first_displayed_item)
        {
            h->first_displayed_item = new_highlighted_index;
        }
        if (new_highlighted_index == (new_n_items - 1))
        {
            h->last_displayed_item = new_highlighted_index - 1;
        }
        h->highlighted_item = new_highlighted_index;
        if (flag)
        {
            h->first_displayed_item = new_highlighted_index;
            h->flags |= UI_LIST_MENU_FIRST_SHIFT_HIGHLIGHTED_ITEM;
        }
        h->num_items = new_n_items;
    }
}


/*****************************************************************************
 * FUNCTION
 *  set_list_menu_category_history
 * DESCRIPTION
 *  Sets the history data for the list menu from the given history buffer
 * PARAMETERS
 *  history_ID          [IN]        Is the ID used by category screens
 *  history_buffer      [IN]        Is the buffer from which history data is taken
 * RETURNS
 *  Returns true if the history ID is valid
 *****************************************************************************/
U8 set_list_menu_category_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        list_menu_category_history *h = (list_menu_category_history*) history_buffer;

        if (history_valid(h->history_ID, history_ID))
        {
            /* Backward compatible */
            if (MMI_fixed_list_menu.highlighted_item >= MMI_fixed_list_menu.n_items)
            {   /* Menu items become fewer than before. Go to the last index. */
                if (MMI_fixed_list_menu.n_items == 0)
                {   /* prevent highlighted_item goes to -1 */
                    MMI_fixed_list_menu.highlighted_item = 0;
                }
                else
                {
                    MMI_fixed_list_menu.highlighted_item = MMI_fixed_list_menu.n_items - 1;
                }
            }
            else
            {
                MMI_fixed_list_menu.highlighted_item = h->highlighted_item;
            }

			if (check_list_menu_history_valid(h->history_ID, h->num_items, history_ID))
			{
				MMI_fixed_list_menu.first_displayed_item = h->first_displayed_item;
				MMI_fixed_list_menu.last_displayed_item = h->last_displayed_item;
			#if defined(__MMI_UI_LIST_SCROLL_BY_PIXEL__)
				MMI_fixed_list_menu.first_displayed_offset = h->first_displayed_offset;
				MMI_fixed_list_menu.last_displayed_offset = h->last_displayed_offset;
			#endif /* __MMI_UI_LIST_SCROLL_BY_PIXEL__ */
				MMI_fixed_list_menu.displayed_items = h->displayed_items;
				MMI_fixed_list_menu.flags = h->flags;
			}
            
            return (1);
        }
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  change_cat184_list_menu_history_highlighted_item
 * DESCRIPTION
 *  Change the highlighted item stored in history data. (for SMS updating list)
 * PARAMETERS
 *  index               [IN]        New index
 *  history_buffer      [IN]        The history buffer wanted to be changed.
 * RETURNS
 *  void
 *****************************************************************************/
void change_cat184_list_menu_history_highlighted_item(S32 index, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        list_menu_category_history *h = (list_menu_category_history*) history_buffer;
        
        if (history_valid(h->history_ID, MMI_CATEGORY184_ID))
        {
            h->highlighted_item = index;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  change_cat1032_list_menu_history_highlighted_item
 * DESCRIPTION
 *  Change the highlighted item stored in history data. (for SMS updating list)
 * PARAMETERS
 *  index               [IN]        New index
 *  history_buffer      [IN]        The history buffer wanted to be changed.
 * RETURNS
 *  void
 *****************************************************************************/
void change_cat1032_list_menu_history_highlighted_item(S32 index, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        list_menu_category_history *h = (list_menu_category_history*) history_buffer;
        
        if (history_valid(h->history_ID, MMI_CAT1031_NO_TAB_ID))
        {
            h->highlighted_item = index;
        }
    }
}


/* Set and Get state of multiine inputbox history buffer */


/*****************************************************************************
 * FUNCTION
 *  set_list_menu_category_history_state
 * DESCRIPTION
 *  Sets the state of history data for state list
 * PARAMETERS
 *  history_ID          [IN]        Is the ID used by category screens
 *  history_buffer      [IN]        Is the buffer into which history data is written
 *  state               [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_list_menu_category_history_state(U16 history_ID, U8 *history_buffer, S8 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        list_menu_category_history *h = (list_menu_category_history*) history_buffer;

        h->state = state;
    }

}


/*****************************************************************************
 * FUNCTION
 *  get_list_menu_category_history
 * DESCRIPTION
 *  Gets the history data for list menu and stores into the given history buffer
 * PARAMETERS
 *  history_ID          [IN]        Is the ID used by category screens
 *  history_buffer      [IN]        Is the buffer into which history data is written
 * RETURNS
 *  void
 *****************************************************************************/
void get_list_menu_category_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        U16 hID = (U16) (history_ID | 0x8000);
        list_menu_category_history *h = (list_menu_category_history*) history_buffer;

        h->history_ID = hID;
        h->highlighted_item = MMI_fixed_list_menu.highlighted_item;
        h->first_displayed_item = MMI_fixed_list_menu.first_displayed_item;
        h->last_displayed_item = MMI_fixed_list_menu.last_displayed_item;
	#if defined(__MMI_UI_LIST_SCROLL_BY_PIXEL__)
		h->first_displayed_offset = MMI_fixed_list_menu.first_displayed_offset;
		h->last_displayed_offset = MMI_fixed_list_menu.last_displayed_offset;
	#endif /* __MMI_UI_LIST_SCROLL_BY_PIXEL__ */
        h->displayed_items = MMI_fixed_list_menu.displayed_items;
        h->flags = MMI_fixed_list_menu.flags;
        h->state = (S8) (-1);
        h->num_items = MMI_fixed_list_menu.n_items;
    }
}


/*****************************************************************************
 * FUNCTION
 *  get_list_menu_category_history_size
 * DESCRIPTION
 *  Gets the history data size for the list menu
 * PARAMETERS
 *  void
 * RETURNS
 *  Returns the size of list menu history
 *****************************************************************************/
S32 get_list_menu_category_history_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (sizeof(list_menu_category_history));
}


/*****************************************************************************
 * FUNCTION
 *  get_list_menu_category_history_state
 * DESCRIPTION
 *  Gets the history data for list menu and stores into the given history buffer
 * PARAMETERS
 *  history_ID          [IN]        Is the ID used by category screens
 *  history_buffer      [IN]        Is the buffer into which history data is written
 * RETURNS
 *  void
 *****************************************************************************/
S8 get_list_menu_category_history_state(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        list_menu_category_history *h = (list_menu_category_history*) history_buffer;

        return h->state;
    }
    return (S8) (-1);
}


/*****************************************************************************
 * FUNCTION
 *  set_matrix_menu_category_history
 * DESCRIPTION
 *  Sets the history data for the matrix menu from the given history buffer
 * PARAMETERS
 *  history_ID          [IN]        Is the ID used by category screens
 *  history_buffer      [IN]        Is the buffer from which history data is taken
 * RETURNS
 *  Returns true if the history ID is valid
 *****************************************************************************/
U8 set_matrix_menu_category_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        matrix_menu_category_history *h = (matrix_menu_category_history*) history_buffer;

        if (history_valid(h->history_ID, history_ID))
        {
            MMI_fixed_matrix_menu.highlighted_item = h->highlighted_item;
            if (MMI_fixed_matrix_menu.highlighted_item > MMI_fixed_matrix_menu.n_items - 1)
            {
                if (MMI_fixed_matrix_menu.n_items == 0)
                {
                    MMI_fixed_matrix_menu.highlighted_item = 0;
                }
                else
                {
                    MMI_fixed_matrix_menu.highlighted_item = MMI_fixed_matrix_menu.n_items - 1;
                }
            }
            MMI_fixed_matrix_menu.highlighted_column = h->highlighted_column;
            MMI_fixed_matrix_menu.highlighted_row = h->highlighted_row;
            MMI_fixed_matrix_menu.displayed_columns = h->displayed_columns;
            MMI_fixed_matrix_menu.displayed_rows = h->displayed_rows;
            MMI_fixed_matrix_menu.first_displayed_column = h->first_displayed_column;
            MMI_fixed_matrix_menu.first_displayed_row = h->first_displayed_row;
            MMI_fixed_matrix_menu.flags = h->flags;
            return (1);
        }
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  get_matrix_menu_category_history
 * DESCRIPTION
 *  Gets the history data for the matrix menu and stores into the given history buffer
 * PARAMETERS
 *  history_ID          [IN]        Is the ID used by category screens
 *  history_buffer      [IN]        Is the buffer into which history data is written
 * RETURNS
 *  void
 *****************************************************************************/
void get_matrix_menu_category_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        U16 hID = (U16) (history_ID | 0x8000);
        matrix_menu_category_history *h = (matrix_menu_category_history*) history_buffer;

        h->history_ID = hID;
        h->highlighted_item = (S16) MMI_fixed_matrix_menu.highlighted_item;
        h->highlighted_column = (S16) MMI_fixed_matrix_menu.highlighted_column;
        h->highlighted_row = (S16) MMI_fixed_matrix_menu.highlighted_row;
        h->displayed_columns = (S16) MMI_fixed_matrix_menu.displayed_columns;
        h->displayed_rows = (S16) MMI_fixed_matrix_menu.displayed_rows;
        h->first_displayed_column = (S16) MMI_fixed_matrix_menu.first_displayed_column;
        h->first_displayed_row = (S16) MMI_fixed_matrix_menu.first_displayed_row;
        h->flags = MMI_fixed_matrix_menu.flags;
    }
}

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__


/*****************************************************************************
 * FUNCTION
 *  set_list_matrix_menu_category_history
 * DESCRIPTION
 *  Sets the history data for the list_matrix main menu from the given history buffer
 * PARAMETERS
 *  history_ID          [IN]        Is the ID used by category screens
 *  history_buffer      [IN]        Is the buffer from which history data is taken
 * RETURNS
 *  Returns true if the history ID is valid
 *****************************************************************************/
U8 set_list_matrix_menu_category_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 flag1 = 0, flag2 = 0;
    list_matrix_menu_category_history *h = (list_matrix_menu_category_history*) history_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer == NULL)
    {
        return 0;
    }
    flag1 = set_list_menu_category_history(history_ID, (U8*) & (h->list_menu_history));
    flag2 = set_matrix_menu_category_history(history_ID, (U8*) & (h->matrix_menu_history));
    if (flag1 || flag2)
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
 *  get_list_matrix_menu_category_history
 * DESCRIPTION
 *  Gets the history data for the list_matrix main menu and stores into the given history buffer
 * PARAMETERS
 *  history_ID          [IN]        Is the ID used by category screens
 *  history_buffer      [IN]        Is the buffer into which history data is written
 * RETURNS
 *  void
 *****************************************************************************/
void get_list_matrix_menu_category_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    list_matrix_menu_category_history *h = (list_matrix_menu_category_history*) history_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_list_menu_category_history(history_ID, (U8*) & (h->list_menu_history));
    get_matrix_menu_category_history(history_ID, (U8*) & (h->matrix_menu_history));
}
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 


/*****************************************************************************
 * FUNCTION
 *  wgui_pen_set_curr_menuitem_wait_longpress
 * DESCRIPTION
 *  Set the current highlighted item to use Wait-Longpress Animation on pen events
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_pen_set_curr_menuitem_wait_longpress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Only support icontext menu item in current design */
    MMI_ASSERT(MMI_fixed_list_menu.common_item_data == (void*)&MMI_fixed_icontext_menuitem);
    MMI_fixed_icontext_menuitems[MMI_fixed_list_menu.highlighted_item].ext_flags |= UI_MENUITEM_PEN_USE_LONGPRESS;
}


/*****************************************************************************
 * FUNCTION
 *  set_object_list_category_history
 * DESCRIPTION
 *  set history of object list
 * PARAMETERS
 *  history_ID          [IN]        Is the ID used by category screens
 *  history_buffer      [IN]        Is the buffer from which history data is taken
 *  index               [IN]        
 * RETURNS
 *  byte
 *****************************************************************************/
U8 set_object_list_category_history(U16 history_ID, U8 *history_buffer, S32 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        object_list_category_history *h = (object_list_category_history*) history_buffer;

        if (history_valid(h->history_ID, history_ID))
        {
            if (index != NULL)
            {
                *index = h->index;
            }
            return (1);
        }
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  get_object_list_category_history
 * DESCRIPTION
 *  get history of object list
 * PARAMETERS
 *  history_ID          [IN]        Is the ID used by category screens
 *  history_buffer      [IN]        Is the buffer from which history data is taken
 *  index               [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void get_object_list_category_history(U16 history_ID, U8 *history_buffer, S32 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        U16 hID = (U16) (history_ID | 0x8000);
        object_list_category_history *h = (object_list_category_history*) history_buffer;

        h->history_ID = hID;
        if (index != NULL)
        {
            h->index = (S16) * index;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  get_slide_control_category_history
 * DESCRIPTION
 *  set teh history of slide control screen
 * PARAMETERS
 *  history_ID          [IN]        
 *  history_buffer      [IN]        
 *  byte(?)             [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void get_slide_control_category_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        U16 hID = (U16) (history_ID | 0x8000);
        U16 idx = 0;
        slide_control_category_history *h = (slide_control_category_history*) history_buffer;

        h->history_ID = hID;
        for (idx = 0; idx < dm_get_slide_control_count(); idx++)
        {
            h->value[idx] = *MMI_slide_control_value[idx];
            h->n_items = dm_get_slide_control_count();
            if (MMI_current_slide_control == &MMI_slide_control[idx])
            {
                h->current_focus = idx;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  set_slide_control_category_history
 * DESCRIPTION
 *  set teh history of slide control screen
 * PARAMETERS
 *  history_ID          [IN]        
 *  history_buffer      [IN]        
 *  byte(?)             [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
U8 set_slide_control_category_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        slide_control_category_history *h = (slide_control_category_history*) history_buffer;

        if (history_valid(h->history_ID, history_ID))
        {
            U16 idx = 0;

            for (idx = 0; idx < h->n_items; idx++)
            {
                *MMI_slide_control_value[idx] = h->value[idx];
            }
            MMI_current_slide_control = &MMI_slide_control[h->current_focus];
            MMI_current_slide_control_value = MMI_slide_control_value[h->current_focus];
            return (U8) (h->n_items);
        }
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  set_dialer_inputbox_category_history
 * DESCRIPTION
 *  get teh history of dialer inputbox screen
 * PARAMETERS
 *  history_ID          [IN]        
 *  history_buffer      [IN]        
 *  byte(?)             [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
U8 set_dialer_inputbox_category_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        dialer_inputbox_category_history *h = (dialer_inputbox_category_history*) history_buffer;

        if (history_valid(h->history_ID, history_ID))
        {
            MMI_dialer_inputbox.cursor_x = h->cursor_x;
            MMI_dialer_inputbox.cursor_y = h->cursor_y;
            MMI_dialer_inputbox.current_text_p = h->current_text_p;
            MMI_dialer_inputbox.last_position_p = h->last_position_p;
            MMI_dialer_inputbox.n_lines = h->n_lines;
            MMI_dialer_inputbox.UCS2_count = h->UCS2_count;
        #ifdef __MMI_FIXED_DIALER_FONT__
            MMI_dialer_inputbox.bottom_line_index = h->bottom_line_index;
            memcpy(MMI_dialer_inputbox.line_start_p, h->line_start_p, sizeof(MMI_dialer_inputbox.line_start_p));
        #endif
            return (1);
        }
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  get_dialer_inputbox_category_history
 * DESCRIPTION
 *  get teh history of dialer inputbox screen
 * PARAMETERS
 *  history_ID          [IN]        
 *  history_buffer      [IN]        
 *  byte(?)             [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void get_dialer_inputbox_category_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        U16 hID = (U16) (history_ID | 0x8000);
        dialer_inputbox_category_history *h = (dialer_inputbox_category_history*) history_buffer;

        h->history_ID = hID;
        h->cursor_x = MMI_dialer_inputbox.cursor_x;
        h->cursor_y = MMI_dialer_inputbox.cursor_y;
        h->current_text_p = MMI_dialer_inputbox.current_text_p;
        h->last_position_p = MMI_dialer_inputbox.last_position_p;
        h->n_lines = MMI_dialer_inputbox.n_lines;
        h->UCS2_count = MMI_dialer_inputbox.UCS2_count;
    #ifdef __MMI_FIXED_DIALER_FONT__
        h->bottom_line_index = MMI_dialer_inputbox.bottom_line_index;
        memcpy(h->line_start_p, MMI_dialer_inputbox.line_start_p, sizeof(MMI_dialer_inputbox.line_start_p));
    #endif
    }
}

/* 121106 HID Start */
/*****************************************************************************
 * FUNCTION
 *  get_panel_category_history
 * DESCRIPTION
 *  get the history of panel
 * PARAMETERS
 *  history_ID          [IN]        
 *  history_buffer      [IN]        
 *  byte(?)             [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void get_panel_category_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        U16 hID = (U16) (history_ID | 0x8000);
        S32 idx = 0;
        S32 num_of_panel;
        U16 focused_panel = 0;
        panel_category_history *h = (panel_category_history*) history_buffer;

        h->history_ID = hID;
        h->focused_panel = focused_panel;
        num_of_panel = dm_get_panel_count();
        h->n_items = num_of_panel;
        for (idx = 0; idx < num_of_panel; idx++)
        {
            h->focused_element[idx] = dm_get_panel_element_focus(idx);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  set_panel_category_history
 * DESCRIPTION
 *  set the history of panel
 * PARAMETERS
 *  history_ID          [IN]        
 *  history_buffer      [IN]        
 *  byte(?)             [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
U8 set_panel_category_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        panel_category_history *h = (panel_category_history*) history_buffer;

        if (history_valid(h->history_ID, history_ID))
        {
            S32 idx = 0;

            MMI_ASSERT(h->n_items<=dm_get_panel_count());
            for (idx = 0; idx < h->n_items; idx++)
            {
                dm_set_panel_element_focus(idx, h->focused_element[idx], MMI_FALSE);
            }
            return (U8) (h->n_items);
        }
    }
    return (0);
}
/* 121106 HID End */

/***************************************************************************** 
* Start : status icons control
*****************************************************************************/


#ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT

/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_show_clock
 * DESCRIPTION
 *  Show clock in status icon bar
 * PARAMETERS
 *  x1          [IN]        The top-right x coordinate of clock 
 *  y1          [IN]        The top-right y coordinate of clock 
 *  x2          [IN]        The left-bottom x coordinate of clock 
 *  y2          [IN]        The left-bottom y coordinate of clock
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_show_clock(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 clock_id;
    gdi_handle target_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clock_id = wgui_status_icon_bar_get_clock();
    if (clock_id != WGUI_CLOCK_INVALID_INDEX)
    {
        target_layer = wgui_status_icon_bar_get_target_layer(WGUI_STATUS_ICON_BAR_H_BAR);
        if (target_layer == GDI_NULL_HANDLE)
        {
            gdi_layer_get_active(&target_layer);
        }
        wgui_clock_set_target_layer(clock_id, target_layer);
        gdi_layer_push_clip();
        gdi_layer_set_clip(x1, y1, x2, y2);
        gdi_layer_lock_frame_buffer();
        wgui_clock_show_clock(clock_id);
        gdi_layer_unlock_frame_buffer();
        gdi_layer_pop_clip();                    
    }
}
#endif /* WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT */


/* support wallpaper on bottom */


/*****************************************************************************
 * FUNCTION
 *  hide_status_icons_bar0_by_transparent
 * DESCRIPTION
 *  hide function of horizontal status bar by transparent color
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void hide_status_icons_bar0_by_transparent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_push_clip();
    wgui_status_icon_bar_get_clip(WGUI_STATUS_ICON_BAR_H_BAR, &x1, &y1, &x2, &y2);
    gui_set_clip(x1, y1, x2, y2);
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
    gui_pop_clip();
}

/* Calvin end */


/*****************************************************************************
 * FUNCTION
 *  ShowStatusIconsTitle
 * DESCRIPTION
 *  show staus bar on main lcd screen
 * PARAMETERS
 *  void
 *  S16(?)      [IN]        Icon_ID
 * RETURNS
 *  void
 *****************************************************************************/
void ShowStatusIconsTitle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_set_clip(WGUI_STATUS_ICON_BAR_H_BAR, 0, 0, UI_device_width - 1, MMI_status_bar_height - 1);
    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR);
#ifdef WGUI_STATUS_ICON_SHOW_V_BAR    
    wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_V_BAR);
#endif
}



/***************************************************************************** 
* Common List Related Functions
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  resize_fixed_list_to_content_height
 * DESCRIPTION
 *  resize fixed list to content width ,height
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void resize_fixed_list_to_content_height(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_resize_fixed_list_menu(&MMI_fixed_list_menu, MMI_fixed_list_menu.width, MMI_content_height);
}

/***************************************************************************** 
* Check List Control Related Functions
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  toggle_check_list_handle_left_softkey_up
 * DESCRIPTION
 *  Chaneg the string of lsk according to stat of check box of current
 *  highlight item and chaneg the string of RSK to Done and
 *  set the function handler of RSK
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void toggle_check_list_handle_left_softkey_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* get index of current highlight item, */
    S32 i = GetHighlightedItem();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item_checked = 1;   /* some item has been checked or unchecked */

    standard_check_list_handle_item_select(i);
    if (checklist_category_menu_item_states != NULL)
    {
        checklist_category_menu_item_states[i] = get_fixed_twostate_item_state(i);
        /* Item is set to check */
        if (checklist_category_menu_item_states[i] == 1)
        {
            ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
        }
    
        /* item is set to off */
        if (checklist_category_menu_item_states[i] == 0)
        {
            ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
        }
    }

    ChangeRightSoftkey(STR_GLOBAL_DONE, 0);
    set_right_softkey_function(checkbox_toggle_DONE_RSK_function, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  special_check_list_handle_left_softkey_up
 * DESCRIPTION
 *  Chaneg the string of lsk according to stat of check box of current
 *  highlight item and chaneg the string of RSK to Done and
 *  set the function handler of RSK
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void special_check_list_handle_left_softkey_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = GetHighlightedItem();
    S32 j;
    U8 check_flag;
    U8 uncheck_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item_checked = 1;   /* some item has been checked or unchecked */

    if (i >= 0 && i < (*fixed_twostate_menu_n_items))
    {
        toggle_fixed_twostate_item(i);
        if (checklist_category_menu_item_states != NULL)
        {
            checklist_category_menu_item_states[i] = get_fixed_twostate_item_state(i);
        
            if (i > 0)
            {
                check_flag = 1;
                uncheck_flag = 1;
                for (j = 1; j < (*fixed_twostate_menu_n_items); j++)
                {
                    if (!(MMI_fixed_twostate_menuitems[j].flags & UI_MENUITEM_STATE_SELECTED))
                    {
                        check_flag = 0;
                    }
                    else
                    {
                        uncheck_flag = 0;
                    }
                }
                if ((check_flag) && (!uncheck_flag))
                {
                    MMI_fixed_twostate_menuitems[0].flags |= UI_MENUITEM_STATE_SELECTED;
                    if (checklist_category_menu_item_states != NULL)
                    {
                        checklist_category_menu_item_states[0] = 1;
                    }
                }
                else if ((!check_flag) && (!uncheck_flag))
                {
                    MMI_fixed_twostate_menuitems[0].flags &= ~UI_MENUITEM_STATE_SELECTED;
                    if (checklist_category_menu_item_states != NULL)
                    {
                        checklist_category_menu_item_states[0] = 0;
                    }
                }
                else if ((!check_flag) && (uncheck_flag))
                {
                    MMI_fixed_twostate_menuitems[0].flags &= ~UI_MENUITEM_STATE_SELECTED;
                    checklist_category_menu_item_states[0] = 0;
                }
            }
        }
    }
    if (i == 0)
    {
        check_flag = get_fixed_twostate_item_state(0);
        if (check_flag)
        {
            if (checklist_category_menu_item_states != NULL)
            {
                for (j = 0; j < (*fixed_twostate_menu_n_items); j++)
                {
                    MMI_fixed_twostate_menuitems[j].flags |= UI_MENUITEM_STATE_SELECTED;
                    checklist_category_menu_item_states[j] = 1;
                }
            }
            else
            {
                for (j = 0; j < (*fixed_twostate_menu_n_items); j++)
                {
                    MMI_fixed_twostate_menuitems[j].flags |= UI_MENUITEM_STATE_SELECTED;
                }
            }
        }
        else
        {
            if (checklist_category_menu_item_states != NULL)
            {
                for (j = 0; j < (*fixed_twostate_menu_n_items); j++)
                {
                    MMI_fixed_twostate_menuitems[j].flags &= ~UI_MENUITEM_STATE_SELECTED;
                    checklist_category_menu_item_states[j] = 0;
                }
            }
            else
            {
                for (j = 0; j < (*fixed_twostate_menu_n_items); j++)
                {
                    MMI_fixed_twostate_menuitems[j].flags &= ~UI_MENUITEM_STATE_SELECTED;
                }
            }
        }
    }
    else
    {
        if (checklist_category_menu_item_states != NULL)
        {
        }
    }
    show_fixed_list();
    if (checklist_category_menu_item_states != NULL)
    {
        if (checklist_category_menu_item_states[i] == 1)
        {
            ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
        }
        if (checklist_category_menu_item_states[i] == 0)
        {
            ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
        }
    }
    ChangeRightSoftkey(STR_GLOBAL_DONE, 0);
    set_right_softkey_function(checkbox_toggle_DONE_RSK_function, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  toggle_check_list_handle_item_select
 * DESCRIPTION
 *  Display the showrcut number on right iside of title of selected
 *  item in check list screen
 * PARAMETERS
 *  h       [IN]        Index of highlight item
 * RETURNS
 *  void
 *****************************************************************************/
void toggle_check_list_handle_item_select(S32 h)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (h >= 0 && h < (*fixed_twostate_menu_n_items))
    {
        standard_check_list_handle_item_select(h);

        if (checklist_category_menu_item_states != NULL)
        {
            checklist_category_menu_item_states[h] = get_fixed_twostate_item_state(h);
            
            if (checklist_category_menu_item_states[h] == 1)
            {
                ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
            }
    
            if (checklist_category_menu_item_states[h] == 0)
            {
                ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
            }
        }

        ChangeRightSoftkey(STR_GLOBAL_DONE, 0);
        set_right_softkey_function(checkbox_toggle_DONE_RSK_function, KEY_EVENT_UP);
    }

}


/*****************************************************************************
 * FUNCTION
 *  SetCheckboxToggleRightSoftkeyFunctions
 * DESCRIPTION
 *  SEt the RSK function phandlers of check box screen
 * PARAMETERS
 *  done_function       [IN]        
 *  back_function       [IN]        
 *  S32(?)              [IN]        H:- index of highlight item
 * RETURNS
 *  void
 *****************************************************************************/
void SetCheckboxToggleRightSoftkeyFunctions(void (*done_function) (void), void (*back_function) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    checkbox_toggle_DONE_RSK_function = done_function;
    checkbox_toggle_BACK_RSK_function = back_function;
}


/*****************************************************************************
 * FUNCTION
 *  standard_check_list_handle_item_select
 * DESCRIPTION
 *  Handles the selection of an item in a check list and draw the check list
 *  
 *  Toggles the given item between selected and unselected modes
 * PARAMETERS
 *  h       [IN]        Is the index of the item
 * RETURNS
 *  void
 *****************************************************************************/
void standard_check_list_handle_item_select(S32 h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (h >= 0 && h < (*fixed_twostate_menu_n_items))
    {
        toggle_fixed_twostate_item(h);
        redraw_fixed_list();
    }
}


/*****************************************************************************
 * FUNCTION
 *  standard_check_list_handle_left_softkey_up
 * DESCRIPTION
 *  Handles Check List Selection/Deselection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void standard_check_list_handle_left_softkey_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = GetHighlightedItem();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    standard_check_list_handle_item_select(i);
    if (checklist_category_menu_item_states != NULL)
    {
        checklist_category_menu_item_states[i] = get_fixed_twostate_item_state(i);
    }
}

/***************************************************************************** 
* Radio List Control Related Functions
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  radio_list_handle_item_select
 * DESCRIPTION
 *  Handles the selection of an item in a radio list and draw the list again
 *  
 *  Unselects all other items and selects the given item
 * PARAMETERS
 *  h       [IN]        Is the index of the item
 * RETURNS
 *  void
 *****************************************************************************/
void radio_list_handle_item_select(S32 h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (h >= 0 && h < (*fixed_twostate_menu_n_items))
    {
        for (i = 0; i < (*fixed_twostate_menu_n_items); i++)
        {
            unselect_fixed_twostate_item(i);
        }
        select_fixed_twostate_item(h);
        redraw_fixed_list();
    }
}


/*****************************************************************************
 * FUNCTION
 *  radio_list_handle_item_select_no_draw
 * DESCRIPTION
 *  Handles the selection of an item in a radio list but not draw the list
 *  
 *  Unselects all other items and selects the given item
 * PARAMETERS
 *  h       [IN]        Is the index of the item
 * RETURNS
 *  void
 *****************************************************************************/
void radio_list_handle_item_select_no_draw(S32 h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (h >= 0 && h < (*fixed_twostate_menu_n_items))
    {
        for (i = 0; i < (*fixed_twostate_menu_n_items); i++)
        {
            unselect_fixed_twostate_item(i);
        }
        select_fixed_twostate_item(h);
    }
}

/***************************************************************************** 
* AsyncDynamic List Control Related Functions
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  get_asyncdynamic_item_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  UI_string_type
 *****************************************************************************/
UI_string_type get_asyncdynamic_item_text(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fixed_icontext_list_menuitem_type *item_p = get_asyncdynamic_item_from_buffer(index);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_p != NULL)
    {
        return item_p->item_texts[0];
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  asyncdynamic_list_highlight_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void asyncdynamic_list_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_set_menu_shortcut_number(item_index + 1);
    MMI_highlighted_item_text = get_asyncdynamic_item_text(item_index);
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__	
    if (!wgui_title_get_menu_shortcut_handler_display())
    {
        gui_redraw_menu_shortcut();
    }
#endif	
	MMI_user_highlight_handler_Ext((U8)eListhighlight, item_index);
#if(UI_ENABLE_POP_UP_DESCRIPTIONS)
    gui_pop_up_description_stop_scroll();
    wgui_current_pop_up_description_index = item_index;
#endif /* (UI_ENABLE_POP_UP_DESCRIPTIONS) */ 
}


#ifdef __MMI_UI_HINTS_IN_MENUITEM__


/*****************************************************************************
 * FUNCTION
 *  wgui_get_current_asyncdynamic_pop_up_description_string
 * DESCRIPTION
 *  returns the current popup description string for asyncdynamic menu
 * PARAMETERS
 *  void
 * RETURNS
 *  current_popup_description_string
 *****************************************************************************/
UI_string_type wgui_get_current_asyncdynamic_pop_up_description_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 array_index, index, hints;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items == 0)
    {
        return NULL;
    }
    if (MMI_fixed_list_menu.current_displayed_item == -1)
    {
        index = MMI_fixed_list_menu.highlighted_item;
    }
    else
    {
        index = MMI_fixed_list_menu.current_displayed_item;
    }
    array_index = (index - asyncdynamic_item_buffer.head_item_index +
                   asyncdynamic_item_buffer.head) & MASK_ASYNCDYNAMIC_ITEMS_BUFF;
    hintDataPtrs[array_index] = hintData[array_index];
    if (asyncdynamic_item_buffer.hint_func)
    {
        hints = asyncdynamic_item_buffer.hint_func(index, (UI_string_type*) & hintDataPtrs[array_index]);
    }
    else
    {
        return NULL;
    }
    if (hints)
    {
        MMI_DBG_ASSERT((((S32)hintDataPtrs[array_index]) %2) == 0);
        return (UI_string_type) hintDataPtrs[array_index];
    }
    else
    {
        return NULL;
    }
}
#endif /* __MMI_UI_HINTS_IN_MENUITEM__ */ 


extern UI_pop_up_description_theme MMI_pop_up_description_theme;


/*****************************************************************************
 * FUNCTION
 *  set_asyncdynamic_pop_up_descriptions
 * DESCRIPTION
 *  
 * PARAMETERS
 *  highlighted_item        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_asyncdynamic_pop_up_descriptions(S32 highlighted_item)
{
#if( UI_ENABLE_POP_UP_DESCRIPTIONS )
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_HINT_NUM; i++)
    {
        hintDataPtrs[i] = hintData[i];
    }
    wgui_current_pop_up_description_index = highlighted_item;
    current_pop_up_description_theme = &MMI_pop_up_description_theme;
    current_pop_up_description_theme->text_font = &MMI_default_font;
    gui_create_pop_up_description(&wgui_pop_up_description, 0, 0, 0, 0);
#if( UI_POP_UP_DESCRIPTION_SCROLL_TYPE == UI_POP_UP_DESCRIPTION_SCROLL_TYPE_MARQUEE )
    wgui_pop_up_description.flags |= UI_POP_UP_DESCRIPTION_MARQUEE_SCROLL;
#elif( UI_POP_UP_DESCRIPTION_SCROLL_TYPE == UI_POP_UP_DESCRIPTION_SCROLL_TYPE_TWO_DIRECTION )
    wgui_pop_up_description.flags |= UI_POP_UP_DESCRIPTION_TWO_DIRECTION_SCROLL;
#endif 
    MMI_fixed_list_menu.gui_display_pop_up_description = wgui_handle_fixed_text_list_pop_up_description;

#ifdef __MMI_UI_HINTS_IN_MENUITEM__
    MMI_fixed_list_menu.gui_get_current_pop_up_description_string = wgui_get_current_asyncdynamic_pop_up_description_string;
#endif 

#endif /* ( UI_ENABLE_POP_UP_DESCRIPTIONS ) */ 
}

/***************************************************************************** 
* Highlight Handler Related Functions
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *	MMI_user_highlight_handler_Ext
 * DESCRIPTION
 *	highlighted handler for internal
 * PARAMETERS
 *	item_index			[IN]		index
 * RETURNS
 *	void
 *****************************************************************************/
void MMI_user_highlight_handler_Ext(U8 menu_type, S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cat_evt_struct evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (menu_type == eListhighlight)
    {
        if (MMI_list_highlight_handler != MMI_dummy_highlight_handler)
        {
            MMI_list_highlight_handler(item_index);
            return ;
        }
    }
    else if (menu_type == eMatrixhighlight)
    {
        if (MMI_matrix_highlight_handler != MMI_dummy_highlight_handler)
        {
            MMI_matrix_highlight_handler(item_index);
            return ;
        }
    }
    
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SCRN_HIGHLIGHT_CHANGE);
    evt.item_index = item_index;
    if (MMI_RET_OK == mmi_frm_send_event_to_active_screen((mmi_event_struct*)&evt))
    {
        if (GetParentHandler() != 0)
        {
            ExecuteCurrHiliteHandler_Ext(item_index);
			return ;
        }
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_SCRN_GET_CURR_PARENT_ID);
        mmi_frm_send_event_to_active_screen((mmi_event_struct*)&evt);
        if (evt.parent_id != 0)
        {
            SetParentHandler(evt.parent_id);
        }
        ExecuteCurrHiliteHandler_Ext(item_index);
    }
}

/*****************************************************************************
 * FUNCTION
 *  RegisterHighlightHandler
 * DESCRIPTION
 *  Registers the highlight handler to be called in menu screens
 * PARAMETERS
 *  f           [IN]        Is a pointer to a highlight handler function
 *  This(?)     [IN]        Is a zero based index of the highlighted menuitem.
 * RETURNS
 *  void
 *****************************************************************************/
void RegisterHighlightHandler(void (*f) (S32 item_index))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_list_highlight_handler = f;
    MMI_matrix_highlight_handler = f;
    MMI_circular_3D_highlight_handler = f;
}


/*****************************************************************************
 * FUNCTION
 *  MMI_dummy_highlight_handler
 * DESCRIPTION
 *  Dummy function of highlight handler
 * PARAMETERS
 *  item_index      [IN]        
 *  index(?)        [IN]        Store teh current index
 * RETURNS
 *  Returns the index of the highlighted item(?)
 *****************************************************************************/
void MMI_dummy_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(item_index);
}


/*****************************************************************************
 * FUNCTION
 *  ClearHighlightHandler
 * DESCRIPTION
 *  Clears the highlight handler that was previously registered
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ClearHighlightHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_list_highlight_handler = MMI_dummy_highlight_handler;
    MMI_matrix_highlight_handler = MMI_dummy_highlight_handler;
    MMI_circular_3D_highlight_handler = MMI_dummy_highlight_handler;
}


/*****************************************************************************
 * FUNCTION
 *  standard_list_highlight_handler
 * DESCRIPTION
 *  System Highlight handler
 *  
 *  Internal function
 * PARAMETERS
 *  item_index      [IN]        Index of current highlight item
 * RETURNS
 *  void
 *****************************************************************************/
void standard_list_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_set_menu_shortcut_number(item_index + 1);
    MMI_highlighted_item_text = get_item_text(item_index);
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__	
    if (!wgui_title_get_menu_shortcut_handler_display())
    {
        gui_redraw_menu_shortcut();
    }
#endif
    MMI_user_highlight_handler_Ext((U8)eListhighlight, item_index);
#if (UI_ENABLE_POP_UP_DESCRIPTIONS)
    gui_pop_up_description_stop_scroll();
    wgui_current_pop_up_description_index = item_index;
#endif /* (UI_ENABLE_POP_UP_DESCRIPTIONS) */ 
}


/*****************************************************************************
 * FUNCTION
 *  toggle_check_list_highlight_handler
 * DESCRIPTION
 *  Chaneg the string of lsk according to stat of check box of current
 *  highlight item to on or off
 * PARAMETERS
 *  item_index      [IN]        
 *  item(?)         [IN]        Index :- index of highlight item
 * RETURNS
 *  void
 *****************************************************************************/
S32 category_140_itemselected;
void toggle_check_list_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_set_menu_shortcut_number(item_index + 1);
    
    MMI_highlighted_item_text = get_item_text(item_index);
    category_140_itemselected = item_index;
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__
    if (!wgui_title_get_menu_shortcut_handler_display())
    {
        gui_redraw_menu_shortcut();
    }
#endif	
	MMI_user_highlight_handler_Ext((U8)eListhighlight, item_index);
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
#endif 

    if (checklist_category_menu_item_states != NULL)
    {
        checklist_category_menu_item_states[item_index] = get_fixed_twostate_item_state(item_index);
        
        if (checklist_category_menu_item_states[item_index] == 0)
        {
            ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
        }
        else if (checklist_category_menu_item_states[item_index] == 1)
        {
            ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
        }
    }

#if(UI_ENABLE_POP_UP_DESCRIPTIONS)
    gui_pop_up_description_stop_scroll();
    wgui_current_pop_up_description_index = item_index;
#endif /* (UI_ENABLE_POP_UP_DESCRIPTIONS) */ 
}


/*****************************************************************************
 * FUNCTION
 *  standard_check_list_highlight_handler
 * DESCRIPTION
 *  System Highlight handler
 *  
 *  Internal function
 * PARAMETERS
 *  item_index      [IN]        Index of current highlight item
 * RETURNS
 *  void
 *****************************************************************************/
void standard_check_list_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_set_menu_shortcut_number(item_index + 1);
    MMI_highlighted_item_text = get_item_text(item_index);
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__	
    if (!wgui_title_get_menu_shortcut_handler_display())
    {
        gui_redraw_menu_shortcut();
    }
#endif	
	MMI_user_highlight_handler_Ext((U8)eListhighlight, item_index);
    gui_pop_up_description_stop_scroll();
    wgui_current_pop_up_description_index = item_index;
}


/*****************************************************************************
 * FUNCTION
 *  standard_radio_list_highlight_handler
 * DESCRIPTION
 *  System Highlight handler of check box  list
 *  
 *  Internal function
 * PARAMETERS
 *  item_index      [IN]        Index of current highlight item
 * RETURNS
 *  void
 *****************************************************************************/
void standard_radio_list_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_set_menu_shortcut_number(item_index + 1);

#ifndef __MMI_RADIO_BUTTON_HIGHLIGHT_NO_SELECT__        /* changing highlight but not selecting */
    //radio_list_handle_item_select_no_draw(item_index);
#endif 

    MMI_highlighted_item_text = get_item_text(item_index);
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__
    if (!wgui_title_get_menu_shortcut_handler_display())
    {
        gui_redraw_menu_shortcut();
    }
#endif	
	MMI_user_highlight_handler_Ext((U8)eListhighlight, item_index);
    gui_pop_up_description_stop_scroll();
    wgui_current_pop_up_description_index = item_index;
}


/*****************************************************************************
 * FUNCTION
 *  inputbox_radio_list_highlight_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void inputbox_radio_list_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_RADIO_BUTTON_HIGHLIGHT_NO_SELECT__        /* changing highlight but not selecting */
    radio_list_handle_item_select_no_draw(item_index);
#endif 

    MMI_highlighted_item_text = get_item_text(item_index);
    gui_lock_double_buffer();

    MMI_user_highlight_handler_Ext((U8)eListhighlight, item_index);
    gui_unlock_double_buffer();
#if(UI_ENABLE_POP_UP_DESCRIPTIONS)
    gui_pop_up_description_stop_scroll();
    wgui_current_pop_up_description_index = item_index;
#endif /* (UI_ENABLE_POP_UP_DESCRIPTIONS) */ 
}


/*****************************************************************************
 * FUNCTION
 *  dynamic_list_highlight_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void dynamic_list_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_icontext_menuitem.flags & UI_MENUITEM_DISABLE_HIGHLIGHT)
        return;
    
    wgui_title_set_menu_shortcut_number(item_index + 1);
    MMI_highlighted_item_text = get_dynamic_item_text(item_index);
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__	
    if (!wgui_title_get_menu_shortcut_handler_display())
    {
        gui_redraw_menu_shortcut();
    }
#endif	
	MMI_user_highlight_handler_Ext((U8)eListhighlight, item_index);
#if(UI_ENABLE_POP_UP_DESCRIPTIONS)
    gui_pop_up_description_stop_scroll();
    wgui_current_pop_up_description_index = item_index;
#endif /* (UI_ENABLE_POP_UP_DESCRIPTIONS) */ 
}


/*****************************************************************************
 * FUNCTION
 *  dynamic_matrix_highlight_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void dynamic_matrix_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_icontext_menuitem.flags & UI_MENUITEM_DISABLE_HIGHLIGHT)
        return;
    
    wgui_title_set_menu_shortcut_number(item_index + 1);
    MMI_highlighted_item_icon = get_dynamic_item_icon(item_index);
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__	
    if (!wgui_title_get_menu_shortcut_handler_display())
    {
        gui_redraw_menu_shortcut();
    }
#endif	
	MMI_user_highlight_handler_Ext((U8)eMatrixhighlight, item_index);
#if(UI_ENABLE_POP_UP_DESCRIPTIONS)
    gui_pop_up_description_stop_scroll();
    wgui_current_pop_up_description_index = item_index;
#endif /* (UI_ENABLE_POP_UP_DESCRIPTIONS) */ 
}

/*****************************************************************************
 * FUNCTION
 *  dynamic_matrix_highlight_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void asyncdynamic_matrix_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_icontext_list_menuitem.flags & UI_MENUITEM_DISABLE_HIGHLIGHT)
        return;
    
    wgui_title_set_menu_shortcut_number(item_index + 1);
    MMI_highlighted_item_icon = get_asyncdynamic_item_icon(item_index);
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__	
    if (!wgui_title_get_menu_shortcut_handler_display())
    {
        gui_redraw_menu_shortcut();
    }
#endif	
	MMI_user_highlight_handler_Ext((U8)eMatrixhighlight, item_index);
#if(UI_ENABLE_POP_UP_DESCRIPTIONS)
    gui_pop_up_description_stop_scroll();
    wgui_current_pop_up_description_index = item_index;
#endif /* (UI_ENABLE_POP_UP_DESCRIPTIONS) */ 
}


/*****************************************************************************
 * FUNCTION
 *  standard_stop_watch_list_highlight_handler
 * DESCRIPTION
 *  Stop Watch Highlight handler
 *  
 *  Same as standard list highlight handler. Except it does not
 *  redraw the the title bar,
 * PARAMETERS
 *  item_index      [IN]        Index of current highlight item
 * RETURNS
 *  void
 *****************************************************************************/
void standard_stop_watch_list_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_set_menu_shortcut_number(item_index + 1);
    MMI_highlighted_item_text = get_item_text(item_index);
	MMI_user_highlight_handler_Ext((U8)eListhighlight, item_index);
    gui_pop_up_description_stop_scroll();
    wgui_current_pop_up_description_index = item_index;
}


/*****************************************************************************
 * FUNCTION
 *  standard_animated_list_highlight_handler
 * DESCRIPTION
 *  System Highlight handler
 *  
 *  Internal function
 * PARAMETERS
 *  item_index      [IN]        Index of current highlight item
 * RETURNS
 *  void
 *****************************************************************************/
void standard_animated_list_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_set_menu_shortcut_number(item_index + 1);
    MMI_highlighted_item_text = get_item_text(item_index);
    gui_lock_double_buffer();
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__	
    if (!wgui_title_get_menu_shortcut_handler_display())
    {
        gui_redraw_menu_shortcut();
    }
#endif	
	MMI_user_highlight_handler_Ext((U8)eListhighlight, item_index);
    gui_hide_animations();
    gui_unlock_double_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  standard_noshortcut_matrix_highlight_handler
 * DESCRIPTION
 *  System Highlight handler
 *  
 *  Internal function
 * PARAMETERS
 *  item_index      [IN]        Index of current highlight item
 * RETURNS
 *  void
 *****************************************************************************/
void standard_noshortcut_matrix_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_set_menu_shortcut_number(item_index + 1);
    MMI_highlighted_item_text = get_item_text(item_index);
	MMI_user_highlight_handler_Ext((U8)eMatrixhighlight, item_index);
}

/*****************************************************************************
 * FUNCTION
 *  standard_animated_matrix_highlight_handler
 * DESCRIPTION
 *  System Highlight handler
 *  
 *  Internal function
 * PARAMETERS
 *  item_index      [IN]        Index of current highlight item
 * RETURNS
 *  void
 *****************************************************************************/
void standard_animated_matrix_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_set_menu_shortcut_number(item_index + 1);
    MMI_highlighted_item_text = get_item_text(item_index);
    gui_lock_double_buffer();
	MMI_user_highlight_handler_Ext((U8)eMatrixhighlight, item_index);
    gui_hide_animations();
    gui_unlock_double_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  standard_animated_matrix_highlight_handler_type2
 * DESCRIPTION
 *  System Highlight handler used by Main menu type2.
 *  
 *  Internal function
 * PARAMETERS
 *  item_index      [IN]        Index of current highlight item
 * RETURNS
 *  void
 *****************************************************************************/
void standard_animated_matrix_highlight_handler_type2(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __PLUTO_MMI_PACKAGE__
#if !defined(__MMI_MAINMENU_SPREAD_SUPPORT__)
    wgui_title_set_menu_shortcut_number(item_index + 1);
    MMI_highlighted_item_text = get_item_text(item_index);
    MMI_mm_animation = get_image(gMainMenuAnimation[item_index]);
    MMI_title_string = MMI_highlighted_item_text;

    /* draw_title() for matrix main menu is called in the following MMI_matrix_highlight_handler(). */
    if (!(MMI_fixed_matrix_menu.flags & UI_MATRIX_MENU_FOR_MAINMENU))
    {
        draw_title();
    }
#endif 

    MMI_user_highlight_handler_Ext((U8)eMatrixhighlight, item_index);
#endif
}


/***************************************************************************** 
* Popup Description Related Functions.
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  wgui_display_fixed_text_list_pop_up_description
 * DESCRIPTION
 *  Diaply pop up list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern gui_effect_struct    *g_slide_effect;
void wgui_display_fixed_text_list_pop_up_description(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, yy;
    S32 x = wgui_pop_up_description.x;
    S32 y = wgui_pop_up_description.y;
    S32 width = wgui_pop_up_description.width;
    S32 height = wgui_pop_up_description.height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!wgui_pop_up_description_flag)
    {
        return;
    }

    if (g_gui_ssp_static_layer)
    {
        return;
    }
#ifdef __MMI_FTE_SUPPORT__
    if (wgui_pop_up_description.hint_cache_buf.buf_ptr && g_slide_effect->state != GUI_EFFECT_STATE_RUNNING)
    {
        wgui_pop_up_description.hint_cache_buf.buf_ptr = NULL;
    }
#endif
    if (wgui_current_pop_up_description_index < 0 ||
        wgui_pop_up_description_strings[wgui_current_pop_up_description_index].text_strings[0] == NULL ||
        (*((U8*)(wgui_pop_up_description_strings[wgui_current_pop_up_description_index].text_strings[0])) == 0
        && *(((U8*)(wgui_pop_up_description_strings[wgui_current_pop_up_description_index].text_strings[0]))+1) == 0))
    {
        wgui_pop_up_description_flag = 0;
        return;
    }
    if ((wgui_current_pop_up_description_index >= 0) &&
        (wgui_current_pop_up_description_index < wgui_pop_up_descriptions_n_items))
    {
        if (wgui_pop_up_descriptions_n_strings > 0)
        {
            for (i = 0; i < wgui_pop_up_descriptions_n_strings; i++)
            {
                gui_set_pop_up_description_text(
                    &wgui_pop_up_description,
                    i,
                    wgui_pop_up_description_strings[wgui_current_pop_up_description_index]. text_strings[i]);
            }
            if (gui_autoresize_pop_up_description(&wgui_pop_up_description, width, height))
            {
                yy = y + height + WGUI_POPUP_DESCRIPTION_Y_GAP;
                if ((yy + wgui_pop_up_description.height) > (MMI_fixed_list_menu.y + MMI_fixed_list_menu.height))
                {
                    yy = y - wgui_pop_up_description.height - WGUI_POPUP_DESCRIPTION_Y_GAP;
                    wgui_pop_up_description.flags |= UI_POP_UP_DESCRIPTION_ABOVE_MENUITEM;

                    /* Do not display the hint when the hint goes out of the menu region. */
                    if (yy < MMI_fixed_list_menu.y)
                    {                        
                        wgui_pop_up_description_flag = 0;
                        gui_pop_up_description_stop_scroll();
                        
                        return;
                    }                    
                }
                else
                {
                    wgui_pop_up_description.flags &= ~UI_POP_UP_DESCRIPTION_ABOVE_MENUITEM;
                }
                /* R2L characters */
                if (!mmi_fe_get_r2l_state())
                {
                    gui_move_pop_up_description(
                        &wgui_pop_up_description,
                        x + width - wgui_pop_up_description.width,
                        yy);
                }
                else
                {
                    gui_move_pop_up_description(&wgui_pop_up_description, UI_device_width - width, yy);
                }
                gui_show_pop_up_description(&wgui_pop_up_description);
                gui_pop_up_description_start_scroll(&wgui_pop_up_description);
            }
        }
    }
    wgui_pop_up_description_flag = 0;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_display_dynamic_text_list_pop_up_description
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_display_dynamic_text_list_pop_up_description(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, yy;
    S32 x = wgui_pop_up_description.x;
    S32 y = wgui_pop_up_description.y;
    S32 width = wgui_pop_up_description.width;
    S32 height = wgui_pop_up_description.height;
    S32 n_hints;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!wgui_pop_up_description_flag)
    {
        return;
    }

    if (g_gui_ssp_static_layer)
    {
        return;
    }
#ifdef __MMI_FTE_SUPPORT__
    if (wgui_pop_up_description.hint_cache_buf.buf_ptr && g_slide_effect->state != GUI_EFFECT_STATE_RUNNING)
    {
        wgui_pop_up_description.hint_cache_buf.buf_ptr = NULL;
    }
#endif
    if (wgui_current_pop_up_description_index >= 0 && dynamic_item_buffer.hint_func != NULL)
    {
        if ((n_hints = dynamic_item_buffer.hint_func(wgui_current_pop_up_description_index, (UI_string_type*) hintDataPtrs)) > 0)
        {
            wgui_pop_up_description.n_strings = n_hints;
            for (i = 0; i < n_hints; i++)
            {
                wgui_pop_up_description.text_strings[i] = (UI_string_type) hintDataPtrs[i];
            }
            if (gui_autoresize_pop_up_description(&wgui_pop_up_description, width, height))
            {
                yy = y + height + WGUI_POPUP_DESCRIPTION_Y_GAP;
                if ((yy + wgui_pop_up_description.height) > (MMI_fixed_list_menu.y + MMI_fixed_list_menu.height))
                {
                    yy = y - wgui_pop_up_description.height - WGUI_POPUP_DESCRIPTION_Y_GAP;
                    wgui_pop_up_description.flags |= UI_POP_UP_DESCRIPTION_ABOVE_MENUITEM;

                    /* Do not display the hint when the hint goes out of the menu region. */
                    if (yy < MMI_fixed_list_menu.y)
                    {                        
                        wgui_pop_up_description_flag = 0;
                        gui_pop_up_description_stop_scroll();

                        return;
                    }                    
                }
                else
                {
                    wgui_pop_up_description.flags &= ~UI_POP_UP_DESCRIPTION_ABOVE_MENUITEM;
                }

                /* R2L characters */
                if (!mmi_fe_get_r2l_state())
                {
                    gui_move_pop_up_description(
                        &wgui_pop_up_description,
                        x + width - wgui_pop_up_description.width,
                        yy);
                }
                else
                {
                    gui_move_pop_up_description(&wgui_pop_up_description, UI_device_width - width, yy);
                }
                gui_show_pop_up_description(&wgui_pop_up_description);
                gui_pop_up_description_start_scroll(&wgui_pop_up_description);
            }
        }
    }
    wgui_pop_up_description_flag = 0;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_display_asyncdynamic_text_list_pop_up_description
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_display_asyncdynamic_text_list_pop_up_description(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, yy;
    S32 x = wgui_pop_up_description.x;
    S32 y = wgui_pop_up_description.y;
    S32 width = wgui_pop_up_description.width;
    S32 height = wgui_pop_up_description.height;
    S32 n_hints;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!wgui_pop_up_description_flag)
    {
        return;
    }
    if (g_gui_ssp_static_layer)
    {
        return;
    }
#ifdef __MMI_FTE_SUPPORT__
    if (wgui_pop_up_description.hint_cache_buf.buf_ptr && g_slide_effect->state != GUI_EFFECT_STATE_RUNNING)
    {
        wgui_pop_up_description.hint_cache_buf.buf_ptr = NULL;
    }
#endif
    if (wgui_current_pop_up_description_index >= 0 && asyncdynamic_item_buffer.hint_func != NULL)
    {
        if ((n_hints = asyncdynamic_item_buffer.hint_func(
                                                    wgui_current_pop_up_description_index,
                                                    (UI_string_type*) hintDataPtrs)) > 0)
        {
            wgui_pop_up_description.n_strings = n_hints;
            for (i = 0; i < n_hints; i++)
            {
                wgui_pop_up_description.text_strings[i] = (UI_string_type) hintDataPtrs[i];
            }
            if (gui_autoresize_pop_up_description(&wgui_pop_up_description, width, height))
            {
                yy = y + height + WGUI_POPUP_DESCRIPTION_Y_GAP;
                if ((yy + wgui_pop_up_description.height) > (MMI_fixed_list_menu.y + MMI_fixed_list_menu.height))
                {
                    yy = y - wgui_pop_up_description.height - WGUI_POPUP_DESCRIPTION_Y_GAP;
                    wgui_pop_up_description.flags |= UI_POP_UP_DESCRIPTION_ABOVE_MENUITEM;
                    
                    /* Do not display the hint when the hint goes out of the menu region. */
                    if (yy < MMI_fixed_list_menu.y)
                    {                        
                        wgui_pop_up_description_flag = 0;
                        gui_pop_up_description_stop_scroll();
                        
                        return;
                    }
                }
                else
                {
                    wgui_pop_up_description.flags &= ~UI_POP_UP_DESCRIPTION_ABOVE_MENUITEM;
                }

                /* R2L characters */
                if (!mmi_fe_get_r2l_state())
                {
                    gui_move_pop_up_description(
                        &wgui_pop_up_description,
                        x + width - wgui_pop_up_description.width,
                        yy);
                }
                else
                {
                    gui_move_pop_up_description(&wgui_pop_up_description, UI_device_width - width, yy);
                }
                gui_show_pop_up_description(&wgui_pop_up_description);
                gui_pop_up_description_start_scroll(&wgui_pop_up_description);
            }
        }
    }
    wgui_pop_up_description_flag = 0;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_handle_fixed_text_list_pop_up_description
 * DESCRIPTION
 *  set teh x,y width,height flag of pop up
 * PARAMETERS
 *  x           [IN]        Start x position of pop up
 *  y           [IN]        Start y position of pop up
 *  width       [IN]        Width of pop up
 *  height      [IN]        Height of pop up
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
extern S32 is_draw_next_frame_list_highlight_effect_value(void);
#endif 

void wgui_handle_fixed_text_list_pop_up_description(S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    if (is_draw_next_frame_list_highlight_effect_value() == 1)
    {
        return; /* To restrict the change in the pop up positions */
    }
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */ 
    wgui_pop_up_description.x = x;
    wgui_pop_up_description.y = y;
    wgui_pop_up_description.width = width;
    wgui_pop_up_description.height = height;
#if defined(__MMI_MAINLCD_128X64__)
    wgui_pop_up_description_flag = 0;
#else /* __MMI_MAINLCD_128X64__ */
    wgui_pop_up_description_flag = 1;
#endif /* __MMI_MAINLCD_128X64__ */
}

#ifdef __MMI_UI_HINTS_IN_MENUITEM__


/*****************************************************************************
 * FUNCTION
 *  wgui_get_current_pop_up_description_string
 * DESCRIPTION
 *  returns the current popup sescription string
 * PARAMETERS
 *  void
 * RETURNS
 *  current_popup_description_string
 *****************************************************************************/
UI_string_type wgui_get_current_pop_up_description_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.current_displayed_item == -1)
    {
        MMI_DBG_ASSERT((((S32)wgui_pop_up_description_strings[MMI_fixed_list_menu.highlighted_item].text_strings[0]) %2) == 0);
        if (MMI_fixed_list_menu.highlighted_item != -1)
            return wgui_pop_up_description_strings[MMI_fixed_list_menu.highlighted_item].text_strings[0];
        else
            return NULL;
    }
    else
    {
        MMI_DBG_ASSERT((((S32)wgui_pop_up_description_strings[MMI_fixed_list_menu.current_displayed_item].text_strings[0]) %2) == 0);
        return wgui_pop_up_description_strings[MMI_fixed_list_menu.current_displayed_item].text_strings[0];
    }
}
#endif /* __MMI_UI_HINTS_IN_MENUITEM__ */ 


/*****************************************************************************
 * FUNCTION
 *  set_pop_up_descriptions
 * DESCRIPTION
 *  set popup description of current high light item
 * PARAMETERS
 *  n_strings               [IN]        Number of strings
 *  n_items                 [IN]        Number if items
 *  highlighted_item        [IN]        Highlight item
 * RETURNS
 *  void
 *****************************************************************************/
extern UI_pop_up_description_theme MMI_pop_up_description_theme;

void set_pop_up_descriptions(S32 n_strings, S32 n_items, S32 highlighted_item)
{
#if(UI_ENABLE_POP_UP_DESCRIPTIONS)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_pop_up_descriptions_n_strings = n_strings;
    wgui_current_pop_up_description_index = highlighted_item;
    wgui_pop_up_descriptions_n_items = n_items;
    current_pop_up_description_theme = &MMI_pop_up_description_theme;
    current_pop_up_description_theme->text_font = &MMI_default_font;
    gui_create_pop_up_description(&wgui_pop_up_description, 0, 0, 0, 0);
#if(UI_POP_UP_DESCRIPTION_SCROLL_TYPE == UI_POP_UP_DESCRIPTION_SCROLL_TYPE_MARQUEE)
    wgui_pop_up_description.flags |= UI_POP_UP_DESCRIPTION_MARQUEE_SCROLL;
#elif(UI_POP_UP_DESCRIPTION_SCROLL_TYPE==UI_POP_UP_DESCRIPTION_SCROLL_TYPE_TWO_DIRECTION)
    wgui_pop_up_description.flags |= UI_POP_UP_DESCRIPTION_TWO_DIRECTION_SCROLL;
#endif 
    gui_set_pop_up_description_n_strings(&wgui_pop_up_description, n_strings);
    MMI_fixed_list_menu.gui_display_pop_up_description = wgui_handle_fixed_text_list_pop_up_description;

#ifdef __MMI_UI_HINTS_IN_MENUITEM__
    MMI_fixed_list_menu.gui_get_current_pop_up_description_string = wgui_get_current_pop_up_description_string;
#endif 

#endif /* (UI_ENABLE_POP_UP_DESCRIPTIONS) */ 
}


#ifdef __MMI_UI_HINTS_IN_MENUITEM__


/*****************************************************************************
 * FUNCTION
 *  wgui_get_current_dynamic_pop_up_description_string
 * DESCRIPTION
 *  returns the current popup description string for dynamic menu
 * PARAMETERS
 *  void
 * RETURNS
 *  current_popup_description_string
 *****************************************************************************/
UI_string_type wgui_get_current_dynamic_pop_up_description_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 array_index, index, hints;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items == 0)
    {
        return NULL;
    }
    if (MMI_fixed_list_menu.current_displayed_item == -1)
    {
        index = MMI_fixed_list_menu.highlighted_item;
    }
    else
    {
        index = MMI_fixed_list_menu.current_displayed_item;
    }
    array_index = (index - dynamic_item_buffer.head_item_index + dynamic_item_buffer.head) & MASK_DYNAMIC_ITEMS_BUFF;
    hintDataPtrs[array_index] = hintData[array_index];
    if (dynamic_item_buffer.hint_func)
    {
        hints = dynamic_item_buffer.hint_func(index, (UI_string_type*) & hintDataPtrs[array_index]);
    }
    else
    {
        return NULL;
    }
    if (hints)
    {
        MMI_DBG_ASSERT((((S32)hintDataPtrs[array_index]) %2) == 0);
        return (UI_string_type) hintDataPtrs[array_index];
    }
    else
    {
        return NULL;
    }

}
#endif /* __MMI_UI_HINTS_IN_MENUITEM__ */ 


/*****************************************************************************
 * FUNCTION
 *  set_dynamic_pop_up_descriptions
 * DESCRIPTION
 *  
 * PARAMETERS
 *  highlighted_item        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_dynamic_pop_up_descriptions(S32 highlighted_item)
{
#if( UI_ENABLE_POP_UP_DESCRIPTIONS )
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_HINT_NUM; i++)
    {
        hintDataPtrs[i] = hintData[i];
    }
    wgui_current_pop_up_description_index = highlighted_item;
    current_pop_up_description_theme = &MMI_pop_up_description_theme;
    current_pop_up_description_theme->text_font = &MMI_default_font;
    gui_create_pop_up_description(&wgui_pop_up_description, 0, 0, 0, 0);
#if( UI_POP_UP_DESCRIPTION_SCROLL_TYPE == UI_POP_UP_DESCRIPTION_SCROLL_TYPE_MARQUEE )
    wgui_pop_up_description.flags |= UI_POP_UP_DESCRIPTION_MARQUEE_SCROLL;
#elif( UI_POP_UP_DESCRIPTION_SCROLL_TYPE == UI_POP_UP_DESCRIPTION_SCROLL_TYPE_TWO_DIRECTION )
    wgui_pop_up_description.flags |= UI_POP_UP_DESCRIPTION_TWO_DIRECTION_SCROLL;
#endif 
    MMI_fixed_list_menu.gui_display_pop_up_description = wgui_handle_fixed_text_list_pop_up_description;

#ifdef __MMI_UI_HINTS_IN_MENUITEM__
    MMI_fixed_list_menu.gui_get_current_pop_up_description_string = wgui_get_current_dynamic_pop_up_description_string;
#endif 

#endif /* ( UI_ENABLE_POP_UP_DESCRIPTIONS ) */ 
}


/*****************************************************************************
 * FUNCTION
 *  reset_pop_up_descriptions
 * DESCRIPTION
 *  reset poup descriptions to default values
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_pop_up_descriptions(void)
{
#if(UI_ENABLE_POP_UP_DESCRIPTIONS)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_pop_up_descriptions_n_strings = 0;
    wgui_current_pop_up_description_index = -1;
    wgui_pop_up_descriptions_n_items = 0;
    MMI_fixed_list_menu.gui_display_pop_up_description = UI_dummy_display_pop_up_description;

#ifdef __MMI_UI_HINTS_IN_MENUITEM__
    MMI_fixed_list_menu.gui_get_current_pop_up_description_string = UI_dummy_get_current_pop_up_description_string;
#endif 

    gui_pop_up_description_stop_scroll();
#endif /* (UI_ENABLE_POP_UP_DESCRIPTIONS) */ 
}

#ifdef __MMI_UI_HINT_TOGGLE_TRANSITION__


/*****************************************************************************
 * FUNCTION
 *  wgui_setup_pop_up_description_transition
 * DESCRIPTION
 *  Start transition animation of popup description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_setup_pop_up_description_transition(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_setup_pop_up_description_transition(&wgui_pop_up_description);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_reset_pop_up_description_transition
 * DESCRIPTION
 *  Reset transition animation of popup description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_reset_pop_up_description_transition(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_reset_pop_up_description_transition(&wgui_pop_up_description);
}
#endif /* __MMI_UI_HINT_TOGGLE_TRANSITION__ */ 

/***************************************************************************** 
* Slim List Menu Related Functions.
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  wgui_override_list_menu_slim_style
 * DESCRIPTION
 *  Override the current list menu icon style (Typically used at screen entry function)
 * PARAMETERS
 *  style       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_override_list_menu_slim_style(wgui_list_menu_slim_style_enum style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_current_list_menu_slim_style = style;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_restore_list_menu_slim_style
 * DESCRIPTION
 *  Override the current list menu icon style (Typically used at screen entry function)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_restore_list_menu_slim_style(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_current_list_menu_slim_style = WGUI_LIST_MENU_SLIM_STYLE_DEFAULT;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_get_list_menu_icon
 * DESCRIPTION
 *  Return the list menu itm icon according to MMI configuration
 * PARAMETERS
 *  index                   [IN]        
 *  default_image_id        [IN]        
 * RETURNS
 *  image data
 *****************************************************************************/
PU8 wgui_get_list_menu_icon(int index, MMI_ID_TYPE default_image_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_list_menu_slim_style_enum style;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_current_list_menu_slim_style == WGUI_LIST_MENU_SLIM_STYLE_DEFAULT)
    {
      style = WGUI_LIST_MENU_SLIM_STYLE_NUMBER;
#if 0    
    #if defined ( __MMI_SLIM_LISTMENU_NUMBER__ )
/* under construction !*/
    #elif defined ( __MMI_SLIM_LISTMENU_NO_ICON__ )
/* under construction !*/
    #else 
/* under construction !*/
    #endif 
#endif	
    }
    else
    {
        style = wgui_current_list_menu_slim_style;
    }

    switch (style)
    {
        case WGUI_LIST_MENU_SLIM_STYLE_NUMBER:
       //     return get_image((MMI_ID_TYPE) (IMG_GLOBAL_L1 + index));
            return *(&current_MMI_theme->list_menuitem_auto_number_img1 +index);
	   /*
			{
			   switch(index)
			   { 
			   case 0:
				   return current_MMI_theme->list_menuitem_auto_number_img1;
				   break;
               case 1:
				   return current_MMI_theme->list_menuitem_auto_number_img2;
				   break;
			   case 2:
				   return current_MMI_theme->list_menuitem_auto_number_img3;
				   break;
               case 3:
				   return current_MMI_theme->list_menuitem_auto_number_img4;
				   break;
			   case 4:
				   return current_MMI_theme->list_menuitem_auto_number_img5;
				   break;
               case 5:
				   return current_MMI_theme->list_menuitem_auto_number_img6;
				   break;
			   case 6:
				   return current_MMI_theme->list_menuitem_auto_number_img7;
				   break;
               case 7:
				   return current_MMI_theme->list_menuitem_auto_number_img8;
				   break;
			   case 8:
				   return current_MMI_theme->list_menuitem_auto_number_img9;
				   break;
               case 9:
				   return current_MMI_theme->list_menuitem_auto_number_img10;
				   break;
			   case 10:
				   return current_MMI_theme->list_menuitem_auto_number_img11;
				   break;
               case 11:
				   return current_MMI_theme->list_menuitem_auto_number_img12;
				   break;
			   case 12:
				   return current_MMI_theme->list_menuitem_auto_number_img13;
				   break;
               case 13:
				   return current_MMI_theme->list_menuitem_auto_number_img14;
				   break;
			   case 14:
				   return current_MMI_theme->list_menuitem_auto_number_img15;
				   break;
               case 15:
				   return current_MMI_theme->list_menuitem_auto_number_img16;
				   break;
			   case 16:
				   return current_MMI_theme->list_menuitem_auto_number_img17;
				   break;
               case 17:
				   return current_MMI_theme->list_menuitem_auto_number_img18;
				   break;
			   case 18:
				   return current_MMI_theme->list_menuitem_auto_number_img19;
				   break;
               case 19:
				   return current_MMI_theme->list_menuitem_auto_number_img20;
				   break;
			   case 20:
				   return current_MMI_theme->list_menuitem_auto_number_img21;
				   break;
               case 21:
				   return current_MMI_theme->list_menuitem_auto_number_img22;
				   break;
			   case 22:
				   return current_MMI_theme->list_menuitem_auto_number_img23;
				   break;
               case 23:
				   return current_MMI_theme->list_menuitem_auto_number_img24;
				   break;
			   case 24:
				   return current_MMI_theme->list_menuitem_auto_number_img25;
				   break;
               case 25:
				   return current_MMI_theme->list_menuitem_auto_number_img26;
				   break;
			   case 26:
				   return current_MMI_theme->list_menuitem_auto_number_img27;
				   break;
               case 27:
				   return current_MMI_theme->list_menuitem_auto_number_img28;
				   break;
			   case 28:
				   return current_MMI_theme->list_menuitem_auto_number_img29;
				   break;
               case 29:
				   return current_MMI_theme->list_menuitem_auto_number_img30;
				   break;	   
			   }
			
			}
			*/
        case WGUI_LIST_MENU_SLIM_STYLE_NO_ICON:
            return get_image(0);

        case WGUI_LIST_MENU_SLIM_STYLE_DRAW_ICON:
        default:
            return get_image(default_image_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_get_list_menu_icon_if_not_empty
 * DESCRIPTION
 *  Return the list menu itm icon according to MMI configuration
 *  For WGUI_LIST_MENU_SLIM_STYLE_NUMBER, we only set default icon
 *  if original icon is not emty.
 * PARAMETERS
 *  index                   [IN]        
 *  default_image_id        [IN]        
 * RETURNS
 *  image data
 *****************************************************************************/
PU8 wgui_get_list_menu_icon_if_not_empty(int index, MMI_ID_TYPE default_image_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_list_menu_slim_style_enum style;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_current_list_menu_slim_style == WGUI_LIST_MENU_SLIM_STYLE_DEFAULT)
    {
    #if defined ( __MMI_SLIM_LISTMENU_NUMBER__ )
        style = WGUI_LIST_MENU_SLIM_STYLE_NUMBER;
    #elif defined ( __MMI_SLIM_LISTMENU_NO_ICON__ )
        style = WGUI_LIST_MENU_SLIM_STYLE_NO_ICON;
    #else 
        style = WGUI_LIST_MENU_SLIM_STYLE_DRAW_ICON;
    #endif 
    }
    else
    {
        style = wgui_current_list_menu_slim_style;
    }

    switch (style)
    {
        case WGUI_LIST_MENU_SLIM_STYLE_NUMBER:
            /* We cannot simply test default_image_id == 0 because some applications use non-zero image id 
               to indicate empty images. */
            if (get_image(default_image_id))
            {
                return get_image((MMI_ID_TYPE) (IMG_GLOBAL_L1 + index));
            }
            else
            {
                return get_image(0);
            }

        case WGUI_LIST_MENU_SLIM_STYLE_NO_ICON:
            return get_image(0);

        case WGUI_LIST_MENU_SLIM_STYLE_DRAW_ICON:
        default:
            return get_image(default_image_id);
    }
}



/*****************************************************************************
* Title & Scrolling Title Control Related Functions.
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  GetRootTitleIcon
 * DESCRIPTION
 *  Get Root MenuItem TitleIcon Id in mainmenu
 * PARAMETERS
 *  ItemId          [IN]        
 *  MenuItem(?)     [IN]        Id
 * RETURNS
 *  TitleIcon id
 *****************************************************************************/
U16 GetRootTitleIcon(U16 ItemId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __COSMOS_MMI_PACKAGE__
    U16 idx;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VUI_3D_MAINMENU__) || defined(__MMI_APP_MANAGER_SUPPORT__)
	return IMG_NONE;
//#endif
#else
#ifdef __COSMOS_MMI_PACKAGE__
	return IMG_GLOBAL_DEFAULT;
#else
    idx = GetRootParentIndex(ItemId);
    if (idx == 0xFF)
    {
        return IMG_GLOBAL_DEFAULT;
    }
    return gMainMenuTitleIcon[idx];
#endif
#endif
}

/* support wallpaper on bottom */


/*****************************************************************************
 * FUNCTION
 *  wgui_set_wallpaper_on_bottom
 * DESCRIPTION
 *  set the flag of wallpaper on bottom
 * PARAMETERS
 *  state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_set_wallpaper_on_bottom(MMI_BOOL state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gMMI_wallpaper_on_bottom = state;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_reset_wallpaper_on_bottom
 * DESCRIPTION
 *  reset the flag of wallpaper on bottom
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_reset_wallpaper_on_bottom(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gMMI_wallpaper_on_bottom = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_is_wallpaper_on_bottom
 * DESCRIPTION
 *  is the flag of wallpaper on bottom set?
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL wgui_is_wallpaper_on_bottom(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gMMI_wallpaper_on_bottom;
}


/***************************************************************************** 
* Theme related wrappers
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  MMI_apply_current_theme
 * DESCRIPTION
 *  Applies the current MMI theme to all MMI objects
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_setup_inline_edit_themes(void);
extern void (*SUBLCD_RedrawCategoryFunction) (void);

void MMI_apply_current_theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_icontext_button_theme(&MMI_softkeys[MMI_LEFT_SOFTKEY], current_UI_theme->icontext_button_theme);
    gui_set_icontext_button_theme(&MMI_softkeys[MMI_RIGHT_SOFTKEY], current_UI_theme->icontext_button_theme);
    gui_set_fixed_list_menu_theme(&MMI_fixed_list_menu, current_UI_theme->fixed_list_menu_theme);
    gui_set_fixed_text_menuitem_theme(&MMI_fixed_text_menuitem, current_UI_theme->fixed_text_menuitem_theme);
    gui_set_fixed_icontext_menuitem_theme(
        &MMI_fixed_icontext_menuitem,
        current_UI_theme->fixed_icontext_menuitem_theme);
    gui_set_fixed_icontext_list_menuitem_theme(
        &MMI_fixed_icontext_list_menuitem,
        current_UI_theme->fixed_icontext_list_menuitem_theme);
    gui_set_single_line_input_box_theme(&MMI_singleline_inputbox, current_UI_theme->single_line_input_box_theme);
    gui_set_multi_line_input_box_theme(&MMI_multiline_inputbox, current_UI_theme->multi_line_input_box_theme);
    gui_set_fixed_matrix_menu_theme(&MMI_fixed_matrix_menu, current_UI_theme->fixed_matrix_menu_theme);
    gui_set_fixed_list_menu_theme(&MMI_fixed_list_menu, current_UI_theme->fixed_list_menu_theme);
    gui_set_vertical_scrollbar_theme(&MMI_fixed_list_menu.vbar, current_UI_theme->vertical_scrollbar_theme);
    gui_set_vertical_scrollbar_theme(&MMI_multiline_inputbox.vbar, current_UI_theme->vertical_scrollbar_theme);
    gui_set_vertical_scrollbar_theme(&MMI_fixed_matrix_menu.vbar, current_UI_theme->vertical_scrollbar_theme);
    gui_set_horizontal_scrollbar_theme(&MMI_fixed_matrix_menu.hbar, current_UI_theme->horizontal_scrollbar_theme);
    set_MMI_LSK_theme();
    gui_set_icontext_button_theme(&MMI_softkeys[MMI_LEFT_SOFTKEY], current_UI_theme->icontext_button_theme);
    set_MMI_RSK_theme();
    gui_set_icontext_button_theme(&MMI_softkeys[MMI_RIGHT_SOFTKEY], current_UI_theme->icontext_button_theme);
    set_MMI_regular_button_theme();
    
#if defined(__MMI_VIRTUAL_KEYBOARD__)
    #ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__
    gui_set_virtual_keyboard_theme(&MMI_virtual_keyboard, current_UI_theme->virtual_keyboard_theme);
    #else
    gui_virtual_keyboard_set_theme(&g_wgui_virtual_keyboard, current_UI_theme->virtual_keyboard_theme);
    #endif
#endif /* defined(__MMI_VIRTUAL_KEYBOARD__) */

    gui_shortcut_set_theme(&MMI_menu_shortcut_box, current_UI_theme->shortcut_box_theme);
    gui_title_set_theme(&g_wgui_title_bar, current_UI_theme->window_title_theme);
    gui_title_set_theme(&MMI_horizontal_tab_bar.title, current_UI_theme->tab_title_theme);
    gui_set_horizontal_tab_bar_theme(&MMI_horizontal_tab_bar, current_UI_theme->horizontal_tab_bar_theme);


    /* 
     * wgui_setup_inline_edit_themes() modifies current_UI_theme->fixed_text_menuitem_theme,
     * and so does set_MMI_current_fixed_text_menuitem_theme_list(). The order is critical.
     */
    // TODO: remove this line    
    wgui_setup_inline_edit_themes();
    
    /* This assumes that MMI_apply_current_theme is called only from the theme setting menu which uses a list menu */
    set_MMI_current_fixed_text_menuitem_theme_list();
    gui_set_fixed_twostate_menuitem_current_theme(&MMI_fixed_twostate_menuitem);    

    gui_clock_set_theme(g_wgui_clock_list, current_UI_theme->clock_theme);
    
    gui_calendar_set_theme(&g_wgui_calendar, current_UI_theme->calendar_theme);
    
    
    SUBLCD_RedrawCategoryFunction();
}

/***************************************************************************** 
* Multiline inputbox Related Functions
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  set_multiline_inputbox_change
 * DESCRIPTION
 *  set the change status of multiline inputbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_multiline_inputbox_change(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_multi_line_input_box_change(&MMI_multiline_inputbox);
    /* Set InLine Screen Status Change On Change In InlineMultiLine Control - Gurinder 15/4/2004 */
    if (MMI_multi_line_inputbox_present)
    {
        set_wgui_inline_list_menu_status(1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  get_mutliline_inputbox_change_status
 * DESCRIPTION
 *  To get The MultiLine Inputbox Change Status at exit handler of application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 get_mutliline_inputbox_change_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_multiline_inputbox.editor_changed;
}


/*****************************************************************************
 * FUNCTION
 *  set_multiline_inputbox_change_callback
 * DESCRIPTION
 *  Set multiline box contents changed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_multiline_inputbox_change_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_multiline_inputbox.editor_changed = 1;
}


/*****************************************************************************
 * FUNCTION
 *  fixed_matrix_loop_key_handler
 * DESCRIPTION
 *  handle matrix menu key handling ..up /down,
 * PARAMETERS
 *  vkey_code       [IN]        Key code
 *  key_state       [IN]        Key state
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_matrix_loop_key_handler(S32 vkey_code, S32 key_state)
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
        MMI_fixed_matrix_menu.last_highlighted_item = MMI_fixed_matrix_menu.highlighted_item;
        switch (vkey_code)
        {
            case 37:
                fixed_matrix_goto_previous_item();
                break;
            case 39:
                fixed_matrix_goto_next_item();
                break;
            case 38:
                fixed_matrix_goto_previous_row();
                break;
            case 40:
                fixed_matrix_goto_next_row();
                break;
            case 36:
                fixed_matrix_goto_home();
                break;
            case 35:
                fixed_matrix_goto_end();
                break;
            case 33:
                fixed_matrix_goto_previous_page();
                break;
            case 34:
                fixed_matrix_goto_next_page();
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
 *  register_fixed_matrix_loop_keys
 * DESCRIPTION
 *  register key handlers of matrix menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_fixed_matrix_loop_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(fixed_matrix_goto_previous_row, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(fixed_matrix_goto_next_row, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(fixed_matrix_goto_previous_item, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(fixed_matrix_goto_previous_item, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(fixed_matrix_goto_next_item, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(fixed_matrix_goto_next_item, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetKeyHandler(fixed_matrix_goto_previous_row, KEY_UP_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(fixed_matrix_goto_next_row, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(fixed_matrix_goto_previous_item, KEY_LEFT_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(fixed_matrix_goto_previous_item, KEY_VOL_UP, KEY_EVENT_REPEAT);
    SetKeyHandler(fixed_matrix_goto_next_item, KEY_RIGHT_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(fixed_matrix_goto_next_item, KEY_VOL_DOWN, KEY_EVENT_REPEAT);
}

#ifdef __MMI_UI_HINTS_IN_MENUITEM__
S32 force_hints_on_highlight_in_menuitem = 0;
S32 force_icon_on_highlight_only_in_menuitem = 0;
S32 force_all_hints_in_menuitem = 0;


/*****************************************************************************
 * FUNCTION
 *  set_force_all_hints_in_menuitem
 * DESCRIPTION
 *  Forces Hints on all hints within menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_force_all_hints_in_menuitem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    force_all_hints_in_menuitem = 1;
}


/*****************************************************************************
 * FUNCTION
 *  reset_force_all_hints_in_menuitem
 * DESCRIPTION
 *  Resets Hints on all hints within menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_force_all_hints_in_menuitem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    force_all_hints_in_menuitem = 0;
}


/*****************************************************************************
 * FUNCTION
 *  is_set_force_all_hints_in_menuitem
 * DESCRIPTION
 *  Tells whether Force Hints is on all hints within menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE/FALSE
 *****************************************************************************/
S32 is_set_force_all_hints_in_menuitem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return force_all_hints_in_menuitem;
}


/*****************************************************************************
 * FUNCTION
 *  set_force_hints_on_highlight_in_menuitem
 * DESCRIPTION
 *  Forces Hints on highlight only within menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_force_hints_on_highlight_in_menuitem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    force_hints_on_highlight_in_menuitem = 1;
}


/*****************************************************************************
 * FUNCTION
 *  reset_force_hints_on_highlight_in_menuitem
 * DESCRIPTION
 *  Resets Hints on highlight only within menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_force_hints_on_highlight_in_menuitem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    force_hints_on_highlight_in_menuitem = 0;

}


/*****************************************************************************
 * FUNCTION
 *  is_set_force_hints_on_highlight_in_menuitem
 * DESCRIPTION
 *  Tells whether Force Hints is on highlight only within menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE/FALSE
 *****************************************************************************/
S32 is_set_force_hints_on_highlight_in_menuitem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return force_hints_on_highlight_in_menuitem;
}


/*****************************************************************************
 * FUNCTION
 *  set_force_icon_on_highlight_only_in_menuitem
 * DESCRIPTION
 *  Forces Icon on highlight only within menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_force_icon_on_highlight_only_in_menuitem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    force_icon_on_highlight_only_in_menuitem = 1;
}


/*****************************************************************************
 * FUNCTION
 *  reset_force_icon_on_highlight_only_in_menuitem
 * DESCRIPTION
 *  Resets Icon on highlight only within menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_force_icon_on_highlight_only_in_menuitem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    force_icon_on_highlight_only_in_menuitem = 0;
}


/*****************************************************************************
 * FUNCTION
 *  is_set_force_icon_on_highlight_only_in_menuitem
 * DESCRIPTION
 *  Tells whether Force Icon on highlight only within menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE/FALSE
 *****************************************************************************/
S32 is_set_force_icon_on_highlight_only_in_menuitem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return force_icon_on_highlight_only_in_menuitem;
}


/*****************************************************************************
 * FUNCTION
 *  reset_all_force_flags_for_hints
 * DESCRIPTION
 *  Resets all forced hint styles.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_all_force_flags_for_hints(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    force_icon_on_highlight_only_in_menuitem = 0;
    force_all_hints_in_menuitem = 0;
    force_hints_on_highlight_in_menuitem = 0;
}
#else
/* Dummy function for SNS */
void set_force_all_hints_in_menuitem(void)
{
}
void reset_force_all_hints_in_menuitem(void)
{
}
S32 is_set_force_all_hints_in_menuitem(void)
{
    return 0;
}
void set_force_hints_on_highlight_in_menuitem(void)
{
}
void reset_force_hints_on_highlight_in_menuitem(void)
{
}
S32 is_set_force_hints_on_highlight_in_menuitem(void)
{
    return 0;
}
void set_force_icon_on_highlight_only_in_menuitem(void)
{
}
void reset_force_icon_on_highlight_only_in_menuitem(void)
{
}
S32 is_set_force_icon_on_highlight_only_in_menuitem(void)
{
    return 0;
}
void reset_all_force_flags_for_hints(void)
{
}
#endif /* __MMI_UI_HINTS_IN_MENUITEM__ */ 


/*****************************************************************************
 * FUNCTION
 *  wgui_is_display_medium_font_string
 * DESCRIPTION
 *  get if the string can be displayed by medium font
 * PARAMETERS
 *  string    [IN]   input string
 *  len       [IN]   string length
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL wgui_is_display_medium_font_string(U8* string, S32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmi_fe_check_string(MMI_medium_font, string, len);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_category_clear_region_with_transparent_color
 * DESCRIPTION
 *  clear the given region with transparent color
 * PARAMETERS
 *  x1    [IN]    start x
 *  y1    [IN]    start y
 *  x2    [IN]    end x
 *  y2    [IN[    end y 
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_category_clear_region_with_transparent_color(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_category_dummy_callback
 * DESCRIPTION
 *  dummy function
 * PARAMETERS
 *  result    [IN]    GDI result
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_category_dummy_callback(GDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}


#ifdef __ATV_SMS_SUPPORT__
static wgui_cat_matv_context_struct g_wgui_cat_matv_cntx;

/*****************************************************************************
 * FUNCTION
 *  wgui_cat_matv_init_video_info
 * DESCRIPTION
 *  initialize the layer buffer and set draw manager flag into fixed layer mode.
 * PARAMETERS
 *  video_layer_buffer         [IN]    video layer buffer.
 *  video_layer_buffer_size    [IN]    video layer buffer size.
 *  util_layer_buffer          [IN]    util layer buffer.
 *  util_layer_buffer_size     [IN]    util layer buffer size.
 *  show_video_callback        [IN]    show video function.
 *  stop_video_callback        [IN]    stop video function.
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat_matv_init_video_info(
        U8 *video_layer_buffer,
        S32 video_layer_buffer_size,
        U8 *util_layer_buffer,
        S32 util_layer_buffer_size,
        show_video_func show_video_callback,
        FuncPtr stop_video_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE *video_layer;
    GDI_HANDLE *util_layer;
	GDI_HANDLE base_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_suspend_background_play();
    
    if (dm_is_fixed_layer_mode_enabled() == MMI_TRUE)
    {
        return;
    }
    
    memset(&g_wgui_cat_matv_cntx, 0, sizeof(wgui_cat_matv_context_struct));

    /* set dm_flag for fixed layer mode */
    dm_enable_fixed_layer_mode(MMI_TRUE);
    

    /* setup layers */
    dm_create_layer_using_outside_memory(
        WGUI_CAT_MATV_VIDEO_X,
        WGUI_CAT_MATV_VIDEO_Y,
        WGUI_CAT_MATV_VIDEO_W,
        WGUI_CAT_MATV_VIDEO_H,
        &video_layer,
        video_layer_buffer,
        video_layer_buffer_size,
        DM_LAYER_ACTIVE_TOP);
    MMI_ASSERT(video_layer);

    /* init layer */
    gdi_layer_push_and_set_active(*(video_layer));
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();



    dm_create_layer_using_outside_memory(
        0,
        0,
        UI_DEVICE_WIDTH,
        UI_DEVICE_HEIGHT,
        &util_layer,
        util_layer_buffer,
        util_layer_buffer_size,
        DM_LAYER_TOP);
    MMI_ASSERT(util_layer);
    /* init layer */
    gdi_layer_push_and_set_active(*(util_layer));
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();


    g_wgui_cat_matv_cntx.video_layer = *video_layer;
    g_wgui_cat_matv_cntx.util_layer = *util_layer;
    g_wgui_cat_matv_cntx.show_video_callback = show_video_callback;
    g_wgui_cat_matv_cntx.stop_video_callback = stop_video_callback; 

    gdi_layer_get_base_handle(&base_handle);
    gdi_layer_set_blt_layer(dm_get_scr_bg_layer(), g_wgui_cat_matv_cntx.video_layer, base_handle, g_wgui_cat_matv_cntx.util_layer);
    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat_matv_reset_video_info
 * DESCRIPTION
 *  reset the video info and draw manager flag.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat_matv_reset_video_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set dm flag for exit fixed layer mode */
    dm_enable_fixed_layer_mode(MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_matv_get_video_layer_handle
 * DESCRIPTION
 *  get the video layer handle
 * PARAMETERS
 *  void
 * RETURNS
 *  GDI_HANDLE
 *****************************************************************************/
GDI_HANDLE wgui_cat_matv_get_video_layer_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_wgui_cat_matv_cntx.video_layer;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_matv_get_util_layer_handle
 * DESCRIPTION
 *  get the util layer handle
 * PARAMETERS
 *  void
 * RETURNS
 *  GDI_HANDLE
 *****************************************************************************/
GDI_HANDLE wgui_cat_matv_get_util_layer_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_wgui_cat_matv_cntx.util_layer;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_matv_get_show_video_func
 * DESCRIPTION
 *  get the show video function
 * PARAMETERS
 *  void
 * RETURNS
 *  show_video_func
 *****************************************************************************/
show_video_func wgui_cat_matv_get_show_video_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_wgui_cat_matv_cntx.show_video_callback;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_matv_stop_video
 * DESCRIPTION
 *  stop the mATV video
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat_matv_stop_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wgui_cat_matv_cntx.stop_video_callback)
    {
        g_wgui_cat_matv_cntx.stop_video_callback();
    }
    mdi_audio_resume_background_play();
}
#endif /* __ATV_SMS_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  wgui_cat_setup_category
 * DESCRIPTION
 *  setup draw manager data and function
 * PARAMETERS
 *  CatId		[IN]		Category ID
 *  flags		[IN]		Category flags for draw manager
 *  exit_function	[IN]		register for exit function
 *  get_history_function		[IN]		register for get history function
 *  get_history_size_function		[IN]		register for get history size function
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat_setup_category(
				S32 CatId,
				S32 flags,
				FuncPtr exit_function,
				U8 *(*get_history_function) (U8 *buffer), 
				S32(*get_history_size_function) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = CatId;
    dm_data.s32flags = flags;
    ExitCategoryFunction = exit_function;
    dm_setup_category_functions(dm_redraw_category_screen, get_history_function, get_history_size_function);
    dm_setup_data(&dm_data);
}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat_setup_category_default_history
 * DESCRIPTION
 *  setup draw manager data and function with default history
 * PARAMETERS
 *  CatId		[IN]		Category ID
 *  flags		[IN]		Category flags for draw manager
 *  exit_function	[IN]		register for exit function
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat_setup_category_default_history(S32 CatId, S32 flags, FuncPtr exit_function)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat_setup_category(CatId, flags, exit_function, dm_get_category_history, dm_get_category_history_size);
}


#if defined(__WGUI_CATE_SUPPORT_HIGHLIGHT_LIST__)

wgui_cate_hilite_list g_cate_hilite_list;

/*****************************************************************************
 * FUNCTION
 *  wgui_cate_set_highlight_list
 * DESCRIPTION
 *  set highlight list struct by application
 * PARAMETERS
 *  hilite_list_ptr	[IN]		struct wgui_cate_hilite_list
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cate_set_highlight_list(wgui_cate_hilite_list *hilite_list_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (hilite_list_ptr == NULL)
    {
        memset((void*)&g_cate_hilite_list, 0, sizeof(wgui_cate_hilite_list));
    }
    else
    {
        memcpy((void*)&g_cate_hilite_list, (void*)hilite_list_ptr, sizeof(wgui_cate_hilite_list));
    }
}


#if defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  wgui_cate_ctrl_area_pen_down_hdlr
 * DESCRIPTION
 *  ctrl area pen down event handler
 * PARAMETERS
 *  point       [IN]   mmi pen point struct
 * RETURNS
 *  MMI_TRUE for parsed, or MMI_FALSE
 *****************************************************************************/
static MMI_BOOL wgui_cate_ctrl_area_pen_down_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wgui_inputs_ml_hilite_pen_handler(point, MMI_PEN_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cate_ctrl_area_pen_up_hdlr
 * DESCRIPTION
 *  ctrl area pen up event handler
 * PARAMETERS
 *  point       [IN]   mmi pen point struct
 * RETURNS
 *  MMI_TRUE for parsed, or MMI_FALSE
 *****************************************************************************/
static MMI_BOOL wgui_cate_ctrl_area_pen_up_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wgui_inputs_ml_hilite_pen_handler(point, MMI_PEN_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cate_ctrl_area_pen_move_hdlr
 * DESCRIPTION
 *  ctrl area pen move event handler
 * PARAMETERS
 *  point       [IN]   mmi pen point struct
 * RETURNS
 *  MMI_TRUE for parsed, or MMI_FALSE
 *****************************************************************************/
static MMI_BOOL wgui_cate_ctrl_area_pen_move_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wgui_inputs_ml_hilite_pen_handler(point, MMI_PEN_EVENT_MOVE);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cate_ctrl_area_pen_abort_hdlr
 * DESCRIPTION
 *  ctrl area pen abort event handler
 * PARAMETERS
 *  point       [IN]   mmi pen point struct
 * RETURNS
 *  MMI_TRUE for parsed, or MMI_FALSE
 *****************************************************************************/
static MMI_BOOL wgui_cate_ctrl_area_pen_abort_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wgui_inputs_ml_hilite_pen_handler(point, MMI_PEN_EVENT_ABORT);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cate_register_ctrl_area_pen_hdlr
 * DESCRIPTION
 *  ctrl area pen event handler register function
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cate_register_ctrl_area_pen_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_register_category_screen_control_area_pen_handlers(
        wgui_cate_ctrl_area_pen_down_hdlr, MMI_PEN_EVENT_DOWN);
    wgui_register_category_screen_control_area_pen_handlers(
        wgui_cate_ctrl_area_pen_up_hdlr, MMI_PEN_EVENT_UP);
    wgui_register_category_screen_control_area_pen_handlers(
        wgui_cate_ctrl_area_pen_move_hdlr, MMI_PEN_EVENT_MOVE);
    wgui_register_category_screen_control_area_pen_handlers(
        wgui_cate_ctrl_area_pen_abort_hdlr, MMI_PEN_EVENT_ABORT);
}
#endif /* __MMI_TOUCH_SCREEN__ */

#endif /* __WGUI_CATE_SUPPORT_HIGHLIGHT_LIST__ */


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_load_image_file_to_buffer
 * DESCRIPTION
 *  load image file to cache buffer
 * PARAMETERS
 *  img_width     [IN]      
 *  img_height    [IN]
 *  buf_ptr       [OUT]
 *  buf_size      [IN]
 *  image_file    [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL wgui_cat_load_image_file_to_buffer(S32 img_width, S32 img_height, U8 *buf_ptr, S32 buf_size, CHAR* image_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle cache_layer;
	MMI_BOOL ret = MMI_TRUE;
    gdi_handle old_act_layer;
    gdi_handle old_alpha_blending_source_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If not enough memory in buffer than layer creation will assert */
    memset((void*)buf_ptr, 0, buf_size);
    if (gdi_layer_create_using_outside_memory
        (0, 0, img_width, img_height, &cache_layer, buf_ptr, buf_size) != GDI_LAYER_SUCCEED)
    {
        return MMI_FALSE;
    }

    gdi_layer_get_active(&old_act_layer);
    gdi_layer_push_and_set_active(cache_layer);
    old_alpha_blending_source_layer = gdi_set_alpha_blending_source_layer(old_act_layer);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_set_clip(0, 0, img_width - 1, img_height - 1);
    gdi_layer_set_position(0, 0);
    //gdi_draw_solid_rect(0, 0, img_width - 1, img_height - 1, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear(gdi_act_color_from_rgb(255, 100, 100, 100));
	
	if (gdi_image_draw_resized_file(0, 0, img_width, img_height, (S8*) image_file) != GDI_SUCCEED)
	{
		ret = MMI_FALSE;
	}

    gdi_layer_pop_and_restore_active();
    gdi_set_alpha_blending_source_layer(old_alpha_blending_source_layer);

    gdi_layer_free(cache_layer);

    return ret;

}


