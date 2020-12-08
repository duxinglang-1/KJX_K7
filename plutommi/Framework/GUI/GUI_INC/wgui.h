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
 *   wgui.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Common definitions for WGUI coordinates
 *                  gui_switch.h
 *                   /        \
 *           gui_config.h    wgui.h
 * There are three files containing configuration variables about gui components.
 * gui_switch.h is in the bottom layer.
 * All these configuration variable which can be modified by customers have been defined or switched in this file.
 * And all these configuration variable prefixed with CFG_
 * gui_config.h and wgui.h are in the topper layer
 * The macros and compile options used in gui components can be defined in these two files. 
 * Some of them based on the macros in gui_switch.h
 *
 *
 *  Author:
 * -------
 *   Ning Gu (MBJ06063)
 *
 *==============================================================================
 *              HISTORY
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef __WGUI_H__
#define __WGUI_H__

#include "MMI_features.h"
#include "gui_switch.h"

#ifndef __OPTR_NONE__
#include "operator_gui.h"
#endif

/* Framework header files */
#include "mmi_frm_gprot.h"
#include "FrameworkBackwardCompatible.h"

#include "DateTimeType.h"
#include "gui.h"
#include "gui_setting.h"
#include "gui_windows.h"
/*
#include "gui_buttons.h"
#include "gui_scrollbars.h"
#include "gui_inputs.h"
#include "gui_generic_menuitems.h"
#include "gui_fixed_menuitems.h"
#include "gui_generic_menus.h"
#include "gui_fixed_menus.h"
#include "gui_dynamic_menus.h"
#include "wgui_draw_manager.h"
*/

/*
** Typedef
*/
typedef S32         MMI_key_code_type;
typedef S32         MMI_key_event_type;
typedef U16         UI_string_ID_type;
typedef U16         UI_image_ID_type;
typedef U16         UI_audio_ID_type;
typedef MYTIME      UI_time;

/*
** Define
*/
#define KEYBOARD_KEY_DOWN                                   256
#define KEYBOARD_KEY_UP                                     257
#define STRING_ID_NULL                                      0
#define IMAGE_ID_NULL                                       0
#define MMI_BG_GREYSCALE_VALUE                              (40)
#define MMI_BG_GREYSCALE_BLACK_VALUE                        (70)
#define MMI_EDITOR_BG_OPACITY                               (current_MMI_theme->bg_opacity_low)

/*  Settings    */
/*  Timeouts: All in milliseconds   */
#define MMI_MENU_SHORTCUT_TIMEOUT                           (600)   
#define MMI_MULTITAP_TIMEOUT                                (600)

/*  Dimensions and co-ordinates         */
/*  All values in pixels                */
#define MMI_SUBLCD_TITLE_HEIGHT                             15

/*******************
 * Layout Switches
 *******************/

#if defined(CFG_UI_SHOW_STATUS_ICON_IN_TITLE) && (CFG_UI_SHOW_STATUS_ICON_IN_TITLE == __ON__)
    #define MMI_SHOW_STATUS_ICON_IN_TITLE
#endif


/* Show status icon above main menu */
#if defined(CFG_UI_MAINMENU_SHOW_STATUS_ICON) && (CFG_UI_MAINMENU_SHOW_STATUS_ICON == __ON__)
    #define GUI_MAINMENU_SHOW_STATUS_ICON
#endif

/* Show status icon above submenu */
#if defined(CFG_UI_SUBMENU_SHOW_STATUS_ICON) && (CFG_UI_SUBMENU_SHOW_STATUS_ICON == __ON__)
    #define GUI_SUBMENU_SHOW_STATUS_ICON
#endif

/* Show status icon above common category screens */
#if defined(CFG_UI_COMMON_SHOW_STATUS_ICON) && (CFG_UI_COMMON_SHOW_STATUS_ICON == __ON__)
    #define GUI_COMMON_SHOW_STATUS_ICON
#endif

/* Show status icon in default screen */
#if defined(CFG_UI_DEFAULT_SHOW_STATUS_ICON) && (CFG_UI_DEFAULT_SHOW_STATUS_ICON == __ON__)
    #define GUI_DEFAULT_SHOW_STATUS_ICON
#endif



/* height of title in mainmenu screen*/
#if defined(CFG_UI_MAINMENU_USE_THICK_TITLE) && (CFG_UI_MAINMENU_USE_THICK_TITLE == __ON__)
    #define GUI_MAINMENU_USE_THICK_TITLE  
#endif

/* height of title in sub menu*/
#if defined(CFG_UI_SUBMENU_USE_THICK_TITLE) && (CFG_UI_SUBMENU_USE_THICK_TITLE == __ON__)
    #define GUI_SUBMENU_USE_THICK_TITLE
#endif

/* height of title in common screen*/
#if defined(CFG_UI_COMMON_USE_THICK_TITLE) && (CFG_UI_COMMON_USE_THICK_TITLE == __ON__)
    #define GUI_COMMON_USE_THICK_TITLE
#endif

/* height of title in default screen*/
#if defined(CFG_UI_DEFAULT_USE_THICK_TITLE) && (CFG_UI_DEFAULT_USE_THICK_TITLE == __ON__)
    #define GUI_DEFAULT_USE_THICK_TITLE  
#endif



/* Overriding common category screen layout */
#if defined(CFG_UI_COMMON_USE_SPECIFIC) && (CFG_UI_COMMON_USE_SPECIFIC == __ON__)
    #define GUI_COMMON_USE_SPECIFIC_STYLE
#endif 

/* Overriding sub-menu layout */
#if defined(CFG_UI_SUBMENU_USE_SPECIFIC) && (CFG_UI_SUBMENU_USE_SPECIFIC == __ON__)
    #define GUI_SUBMENU_USE_SPECIFIC_STYLE
#endif 

/* Editor title layout */
#if defined(CFG_UI_EDITOR_SHOW_TITLE) && (CFG_UI_EDITOR_SHOW_TITLE == __ON__)
    #define GUI_EDITOR_SHOW_TITLE
#endif 

#if defined(CFG_UI_LIST_TRUNCATE_ITEM) && (CFG_UI_LIST_TRUNCATE_ITEM == __ON__)
#define __MMI_UI_LIST_TRUNCATE_ITEM__
#endif 


/*******************
 * Status Icon
 *******************/

#if defined (CFG_UI_STATUS_BAR_HEIGHT)
    #define MMI_STATUS_BAR_HEIGHT                       CFG_UI_STATUS_BAR_HEIGHT
#else 
    #error "Wrong option"
#endif

#if defined (CFG_UI_STATUS_BAR_IDLE_Y)
#define MMI_STATUS_BAR_IDLE_Y                           CFG_UI_STATUS_BAR_IDLE_Y
#else 
#error "Wrong option"
#endif

/* gap between status icon and edge */
#if defined (CFG_UI_STATUSBAR_GAP)
    #define MMI_UI_STATUSBAR_GAP                        CFG_UI_STATUSBAR_GAP
#else 
    #error "Wrong option"
#endif


/*******************
 * Softkey
 *******************/

/* height of button bar */
#if defined(CFG_UI_BUTTON_BAR_HEIGHT)
    #define MMI_BUTTON_BAR_HEIGHT                       CFG_UI_BUTTON_BAR_HEIGHT
#else 
    #error "Wrong option"
#endif

#if defined(CFG_UI_SOFTKEY_BAR_HEIGHT)
    #define MMI_SOFTKEY_BAR_HEIGHT                      CFG_UI_SOFTKEY_BAR_HEIGHT
#else 
    #error "Wrong option"
#endif

/* width of softkey */
#if defined(CFG_UI_SOFTKEY_WIDTH)
    #define MMI_SOFTKEY_WIDTH                           CFG_UI_SOFTKEY_WIDTH
#else 
    #error "Wrong option"
#endif

/* width of center softkey */
#if defined(CFG_UI_CENTER_SOFTKEY_WIDTH)
    #define MMI_CENTER_SOFTKEY_WIDTH                    CFG_UI_CENTER_SOFTKEY_WIDTH
#else 
    #error "Wrong option"
#endif

/* height of softkey */
#if defined(CFG_UI_SOFTKEY_HEIGHT)
    #define MMI_SOFTKEY_HEIGHT                          CFG_UI_SOFTKEY_HEIGHT
#else 
    #error "Wrong option"
#endif

/* gap between softkey and edge */
#if defined (CFG_UI_SOFTKEY_GAP)
    #define MMI_UI_SOFTKEY_GAP                          CFG_UI_SOFTKEY_GAP
#else 
    #error "Wrong option"
#endif

#ifdef __MMI_FTE_SUPPORT__
    #if defined(CFG_UI_ICON_BAR_HEIGHT)
        #define MMI_ICON_BAR_HEIGHT                 CFG_UI_ICON_BAR_HEIGHT
    #else
        #error "Wrong option"
    #endif
#endif /* __MMI_FTE_SUPPORT__ */

/*******************
 * Calling screen
 *******************/
#if defined(CFG_WGUI_CATCALL_STYLE_2_WITH_BUTTON) && (CFG_WGUI_CATCALL_STYLE_2_WITH_BUTTON == __ON__) &&\
    defined(WGUI_CATCALL_STYLE_2) && defined(__MMI_TOUCH_SCREEN__)
    #define WGUI_CATCALL_STYLE_2_WITH_BUTTON
#endif 


/*******************
 * Spacing in menu item
 *******************/

/* height of menu item */
#if defined (CFG_UI_MENUITEM_HEIGHT)
    #define MMI_MENUITEM_HEIGHT                         CFG_UI_MENUITEM_HEIGHT
#else 
    #error "Wrong option"
#endif

#if defined (CFG_UI_MENUITEM_TWOLINE_HEIGHT)
    #define MMI_MENUITEM_TWOLINE_HEIGHT                 CFG_UI_MENUITEM_TWOLINE_HEIGHT
#else 
    #error "Wrong option"
#endif

#if defined (CFG_UI_MENUITEM_MULTIROW_HEIGHT)
    #define MMI_MENUITEM_MULTIROW_HEIGHT                CFG_UI_MENUITEM_MULTIROW_HEIGHT
#else 
    #error "Wrong option"
#endif

#if defined (CFG_UI_MENUITEM_THICK_HEIGHT)
    #define MMI_MENUITEM_THICK_HEIGHT                   CFG_UI_MENUITEM_THICK_HEIGHT
#else 
    #error "Wrong option"
#endif

#if defined (CFG_UI_MENUITEM_THICK_WITH_TAB_HEIGHT)
    #define MMI_MENUITEM_THICK_WITH_TAB_HEIGHT          CFG_UI_MENUITEM_THICK_WITH_TAB_HEIGHT
#else 
    #error "Wrong option"
#endif

#if defined (CFG_UI_TEXT_MENUITEM_TEXT_X)
    #define GUI_TEXT_MENUITEM_TEXT_X                    CFG_UI_TEXT_MENUITEM_TEXT_X
#else
    #error "Wrong option"
#endif

#if defined (CFG_UI_ICONTEXT_MENUITEM_ICON_X)
    #define GUI_ICONTEXT_MENUITEM_ICON_X                CFG_UI_ICONTEXT_MENUITEM_ICON_X
#else
    #error "Wrong option"
#endif

#if defined (CFG_UI_ICONTEXT_MENUITEM_TEXT_X)
    #define GUI_ICONTEXT_MENUITEM_TEXT_X                CFG_UI_ICONTEXT_MENUITEM_TEXT_X
#else 
    #error "Wrong option"
#endif

/*******************
 * Popup Dialog
 *******************/

/* width of popup dialog */
#if defined (CFG_UI_POP_UP_DIALOG_WIDTH)
    #define MMI_POP_UP_DIALOG_WIDTH                     CFG_UI_POP_UP_DIALOG_WIDTH
#else 
    #error "Wrong option"
#endif

/* height of popup dialog */
#if defined (CFG_UI_POP_UP_DIALOG_HEIGHT)
    #define MMI_POP_UP_DIALOG_HEIGHT                    CFG_UI_POP_UP_DIALOG_HEIGHT
#else 
    #error "Wrong option"
#endif

/* x of popup dialog */
#if defined (CFG_UI_POP_UP_DIALOG_X)
    #define MMI_POP_UP_DIALOG_X                         CFG_UI_POP_UP_DIALOG_X
#else 
    #error "Wrong option"
#endif

/* y of popup dialog */
#if defined (CFG_UI_POP_UP_DIALOG_Y)
    #define MMI_POP_UP_DIALOG_Y                         CFG_UI_POP_UP_DIALOG_Y
#else 
    #error "Wrong option"
#endif

/* height of full popup dialog */
#if defined (CFG_UI_POP_UP_DIALOG_FULL_HEIGHT)  
    #define MMI_POP_UP_DIALOG_FULL_HEIGHT               CFG_UI_POP_UP_DIALOG_FULL_HEIGHT
#else 
    #error "Wrong option"
#endif

/* margin of popup content */
#if defined (CFG_UI_POP_UP_CONTENT_MARGIN_X)  
    #define MMI_POP_UP_CONTENT_MARGIN_X                 CFG_UI_POP_UP_CONTENT_MARGIN_X
#else 
    #error "Wrong option"
#endif

/* margin of popup content */
#if defined (CFG_UI_POP_UP_CONTENT_MARGIN_Y)  
    #define MMI_POP_UP_CONTENT_MARGIN_Y                 CFG_UI_POP_UP_CONTENT_MARGIN_Y
#else 
    #error "Wrong option"
#endif

/* For pop-up sliding effect, we will draw pop-up background at the upper layer instead of bottom layer.
   However, it may need more time to redraw / refresh the screen */
#if defined(__MMI_MAINLCD_480X800__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_SCREEN_SWITCH_EFFECT__) || defined(__MMI_FTE_SUPPORT__)
    #define DM_NEW_POPUPBG_METHOD
#endif /* defined (__MMI_MAINLCD_320X480__) || defined(__MMI_SCREEN_SWITCH_EFFECT__) */

/*******************
 * Thin/Thick Title
 *******************/

/* heifht of thin title*/
#if defined(CFG_UI_THIN_TITLE_HEIGHT)
    #define MMI_THIN_TITLE_HEIGHT                       CFG_UI_THIN_TITLE_HEIGHT
#else 
    #error "Wrong option"
#endif

/* heifht of thick title*/
#if defined(CFG_UI_THICK_TITLE_HEIGHT)
    #define MMI_THICK_TITLE_HEIGHT                      CFG_UI_THICK_TITLE_HEIGHT
#else 
    #error "Wrong option"
#endif

/*******************
 * Idlescreen
 *******************/

#if defined (__MMI_UI_TECHNO_IDLESCREEN_BAR__) && defined (__MMI_TOUCH_IDLESCREEN_SHORTCUTS__)
    #if defined (CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO_AND_SHORTCUT)
        #define MMI_IDLE_NETWORK_NAME_Y     CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO_AND_SHORTCUT
    #endif
    #if defined (CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO_AND_SHORTCUT)
        #define MMI_IDLE_NETWORK_STATUS_Y   CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO_AND_SHORTCUT
    #endif
#if defined( __MMI_DUAL_SIM_MASTER__)    
    #if defined (CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_TECHNO_AND_SHORTCUT)
        #define MMI_IDLE_SIM2_NETWORK_NAME_Y     CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_TECHNO_AND_SHORTCUT
    #endif
    #if defined (CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_TECHNO_AND_SHORTCUT)
        #define MMI_IDLE_SIM2_NETWORK_STATUS_Y   CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_TECHNO_AND_SHORTCUT
    #endif    
#endif /*  __MMI_DUAL_SIM_MASTER__ */    
    #if defined (CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO_AND_SHORTCUT)
        #define MMI_IDLE_EXTRA_Y            CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO_AND_SHORTCUT
    #endif
    #if defined (CFG_UI_IDLE_SATICON_Y_WITH_TECHNO_AND_SHORTCUT)
        #define MMI_IDLE_SATICON_Y          CFG_UI_IDLE_SATICON_Y_WITH_TECHNO_AND_SHORTCUT
    #endif
#elif defined (__MMI_UI_TECHNO_IDLESCREEN_BAR__)
    #if defined (CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO)
        #define MMI_IDLE_NETWORK_NAME_Y     CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO
    #endif
    #if defined (CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO)
        #define MMI_IDLE_NETWORK_STATUS_Y   CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO
    #endif
#if defined( __MMI_DUAL_SIM_MASTER__)      
    #if defined (CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_TECHNO)
        #define MMI_IDLE_SIM2_NETWORK_NAME_Y     CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_TECHNO
    #endif
    #if defined (CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_TECHNO)
        #define MMI_IDLE_SIM2_NETWORK_STATUS_Y   CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_TECHNO
    #endif    
#endif /*  __MMI_DUAL_SIM_MASTER__ */    
    #if defined (CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO)
        #define MMI_IDLE_EXTRA_Y            CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO
    #endif
    #if defined (CFG_UI_IDLE_SATICON_Y_WITH_TECHNO)
        #define MMI_IDLE_SATICON_Y          CFG_UI_IDLE_SATICON_Y_WITH_TECHNO
    #endif
#elif defined (__MMI_UI_STATUS_BAR_AT_BOTTOM__)
    #if defined (CFG_UI_IDLE_NETWORK_NAME_Y_WITH_STATUS_AT_BOTTOM)
        #define MMI_IDLE_NETWORK_NAME_Y     CFG_UI_IDLE_NETWORK_NAME_Y_WITH_STATUS_AT_BOTTOM
    #endif
    #if defined (CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_STATUS_AT_BOTTOM)
        #define MMI_IDLE_NETWORK_STATUS_Y   CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_STATUS_AT_BOTTOM
    #endif
#if defined( __MMI_DUAL_SIM_MASTER__)       
    #if defined (CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_STATUS_AT_BOTTOM)
        #define MMI_IDLE_SIM2_NETWORK_NAME_Y     CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_STATUS_AT_BOTTOM
    #endif
    #if defined (CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_STATUS_AT_BOTTOM)
        #define MMI_IDLE_SIM2_NETWORK_STATUS_Y   CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_STATUS_AT_BOTTOM
    #endif    
#endif /* __MMI_DUAL_SIM_MASTER__ */
    #if defined (CFG_UI_IDLE_EXTRA_Y_WITH_STATUS_AT_BOTTOM)
        #define MMI_IDLE_EXTRA_Y            CFG_UI_IDLE_EXTRA_Y_WITH_STATUS_AT_BOTTOM
    #endif
    #if defined (CFG_UI_IDLE_SATICON_Y_WITH_STATUS_AT_BOTTOM)
        #define MMI_IDLE_SATICON_Y          CFG_UI_IDLE_SATICON_Y_WITH_STATUS_AT_BOTTOM
    #endif
#else
    #if defined (CFG_UI_IDLE_NETWORK_NAME_Y)
        #define MMI_IDLE_NETWORK_NAME_Y     CFG_UI_IDLE_NETWORK_NAME_Y
    #endif
    #if defined (CFG_UI_IDLE_NETWORK_STATUS_Y)
        #define MMI_IDLE_NETWORK_STATUS_Y   CFG_UI_IDLE_NETWORK_STATUS_Y
    #endif
#if defined( __MMI_DUAL_SIM_MASTER__)||defined(__KJX_FUN__)	//xb add 2017-07-18     
    #if defined (CFG_UI_IDLE_SIM2_NETWORK_NAME_Y)
        #define MMI_IDLE_SIM2_NETWORK_NAME_Y     CFG_UI_IDLE_SIM2_NETWORK_NAME_Y
    #endif
    #if defined (CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y)
        #define MMI_IDLE_SIM2_NETWORK_STATUS_Y   CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y
    #endif    
#endif /* __MMI_DUAL_SIM_MASTER__ */
    #if defined (CFG_UI_IDLE_EXTRA_Y)
        #define MMI_IDLE_EXTRA_Y            CFG_UI_IDLE_EXTRA_Y
    #endif
    #if defined (CFG_UI_IDLE_SATICON_Y)
        #define MMI_IDLE_SATICON_Y          CFG_UI_IDLE_SATICON_Y
    #endif
#endif

#define IDLE_TEXT_CENTER_ALIGN  1
#define IDLE_TEXT_LEFT_ALIGN    2

#if (defined(__MMI_MAINLCD_96X64__) ||defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__)) && defined( __MMI_DUAL_SIM_MASTER__)
    #define MMI_IDLE_TEXT_ALIGN_TYPE          IDLE_TEXT_LEFT_ALIGN
#else
    #define MMI_IDLE_TEXT_ALIGN_TYPE          IDLE_TEXT_CENTER_ALIGN
#endif

/* Idle screen error check */
#ifndef MMI_IDLE_NETWORK_NAME_Y
    #error "Please define MMI_IDLE_NETWORK_NAME_Y in wgui.h!!"
#endif

#ifndef MMI_IDLE_NETWORK_STATUS_Y
    #error "Please define MMI_IDLE_NETWORK_STATUS_Y in wgui.h!!"
#endif

#if defined( __MMI_DUAL_SIM_MASTER__)    
    #ifndef MMI_IDLE_NETWORK_NAME_Y
        #error "Please define MMI_IDLE_NETWORK_NAME_Y in wgui.h!!"
    #endif

    #ifndef MMI_IDLE_NETWORK_STATUS_Y
        #error "Please define MMI_IDLE_NETWORK_STATUS_Y in wgui.h!!"
    #endif
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifndef MMI_IDLE_EXTRA_Y
    #error "Please define MMI_IDLE_EXTRA_Y in wgui.h!!"
#endif

#ifndef MMI_IDLE_SATICON_Y
    #error "Please define MMI_IDLE_SATICON_Y in wgui.h!!"
#endif


/*******************
 * Matrix Main Menu Icon
 *******************/
 
/* main menu matrix menuitem image width and height */
/* equal to MAIN_MENU_NORMAL_IMAGE_WIDTH */
#if defined(CFG_UI_MAIN_MENU_NORMAL_IMAGE_CLIP_WIDTH)
    #define MAIN_MENU_NORMAL_IMAGE_CLIP_WIDTH               CFG_UI_MAIN_MENU_NORMAL_IMAGE_CLIP_WIDTH
#else 
    #error "Wrong option"
#endif

/* equal to MAIN_MENU_NORMAL_IMAGE_HEIGHT */
#if defined(CFG_UI_MAIN_MENU_NORMAL_IMAGE_CLIP_HEIGHT)
    #define MAIN_MENU_NORMAL_IMAGE_CLIP_HEIGHT              CFG_UI_MAIN_MENU_NORMAL_IMAGE_CLIP_HEIGHT
#else 
    #error "Wrong option"
#endif

/* MAX normal image width */
#if defined(CFG_UI_MAIN_MENU_NORMAL_IMAGE_WIDTH)
    #define MAIN_MENU_NORMAL_IMAGE_WIDTH                    CFG_UI_MAIN_MENU_NORMAL_IMAGE_WIDTH
#else 
    #error "Wrong option"
#endif

/* MAX normal image height */
#if defined(CFG_UI_MAIN_MENU_NORMAL_IMAGE_HEIGHT)
    #define MAIN_MENU_NORMAL_IMAGE_HEIGHT                   CFG_UI_MAIN_MENU_NORMAL_IMAGE_HEIGHT
#else 
    #error "Wrong option"
#endif

/* MAX highlighted image width, affects the cache buffer size */
#if defined(CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_WIDTH)
    #define MAIN_MENU_HIGHLIGHTED_IMAGE_WIDTH               CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_WIDTH
#else 
    #error "Wrong option"
#endif

/* MAX highlighted image height, affects the cache buffer size */
#if defined(CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_HEIGHT)
    #define MAIN_MENU_HIGHLIGHTED_IMAGE_HEIGHT              CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_HEIGHT
#else 
    #error "Wrong option"
#endif

#if defined(CFG_UI_MAIN_MENU_CONTROL_AREA_HEIGHT)
#define MAIN_MENU_CONTROL_AREA_HEIGHT               CFG_UI_MAIN_MENU_CONTROL_AREA_HEIGHT
#else 
#error "Wrong option"
#endif

#if defined(CFG_UI_MAIN_MENU_CONTROL_AREA_X_GAP)
#define MAIN_MENU_CONTROL_AREA_X_GAP               CFG_UI_MAIN_MENU_CONTROL_AREA_X_GAP
#else 
#error "Wrong option"
#endif

#if defined(CFG_UI_MAIN_MENU_CONTROL_AREA_Y_GAP)
#define MAIN_MENU_CONTROL_AREA_Y_GAP               CFG_UI_MAIN_MENU_CONTROL_AREA_Y_GAP
#else 
#error "Wrong option"
#endif


#if defined(CFG_UI_MAIN_MENU_MATRIX_AREA_X_GAP)
#define MAIN_MENU_MATRIX_AREA_X_GAP               CFG_UI_MAIN_MENU_MATRIX_AREA_X_GAP
#else 
#error "Wrong option"
#endif


#if defined(CFG_UI_MAIN_MENU_MATRIX_AREA_Y_GAP)
#define MAIN_MENU_MATRIX_AREA_Y_GAP               CFG_UI_MAIN_MENU_MATRIX_AREA_Y_GAP
#else 
#error "Wrong option"
#endif

/*******************
 * Default Layout
 *******************/

#ifdef GUI_DEFAULT_SHOW_STATUS_ICON
    #define MMI_TITLE_Y                                     (MMI_STATUS_BAR_HEIGHT)
#else
    #define MMI_TITLE_Y                                     (0)
#endif

/* heifht of title in common screen*/
#if defined(GUI_DEFAULT_USE_THICK_TITLE)
    #define MMI_TITLE_HEIGHT                                MMI_THICK_TITLE_HEIGHT
#else
    #define MMI_TITLE_HEIGHT                                MMI_THIN_TITLE_HEIGHT
#endif

#ifdef GUI_DEFAULT_SHOW_STATUS_ICON
    #define MMI_CONTENT_HEIGHT                              (MAIN_LCD_DEVICE_HEIGHT-MMI_BUTTON_BAR_HEIGHT-MMI_TITLE_HEIGHT-MMI_STATUS_BAR_HEIGHT)
#else
    #define MMI_CONTENT_HEIGHT                              (MAIN_LCD_DEVICE_HEIGHT-MMI_BUTTON_BAR_HEIGHT-MMI_TITLE_HEIGHT)
#endif
#ifdef __MMI_MAINLCD_96X64__
    #define MMI_IDLE_DT_BORDER_GAP                          (3)
    #define MMI_IDLE_DT_TIME_Y                              (36)
    #define MMI_IDLE_DT_DATE_Y                              (MMI_IDLE_DT_TIME_Y)

    #define MMI_IDLE_NETWORK_INFO_MARGIN_GAP                (2)
    #define MMI_IDLE_NETWORK_NAME_AREA_WIDTH                (76)
    #define MMI_IDLE_NETWORK_STATUS_AREA_WIDTH              (MAIN_LCD_DEVICE_WIDTH - MMI_IDLE_NETWORK_NAME_AREA_WIDTH - (MMI_IDLE_NETWORK_INFO_MARGIN_GAP << 1))

        #define MMI_SMALL_SCREEN_X_OFFSET                   (16)
        #define MMI_SMALL_SCREEN_Y_OFFSET                   (22)
        #define MMI_SMALL_LIST_LEFT_OFFSET                  2
        #define MMI_SMALL_LIST_SCREEN_WIDTH                 ((MAIN_LCD_DEVICE_WIDTH*3)/4)

    #if defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)
        #define MMI_IDLESCREEN_BAR_HEIGHT                   (80)
        #define MMI_SIGNAL_X                                (0)
        #define MMI_SIGNAL_Y                                (0)
        #define MMI_SIGNAL_WIDTH                            (3)
        #define ANALOG_BACKGROUND_X                         (MMI_SIGNAL_X + MMI_SIGNAL_WIDTH)
        #define ANALOG_BACKGROUND_Y                         (MMI_STATUS_BAR_HEIGHT)
        #define ANALOG_BACKGROUND_WIDTH                     (80)
    #if !defined(__MMI_DIGITAL_CLOCK_IMAGE_NUMBER__)
        #define DIGITAL_BACKGROUND_X                         (MMI_SIGNAL_X + MMI_SIGNAL_WIDTH)
        #define DIGITAL_BACKGROUND_Y                         (MMI_STATUS_BAR_HEIGHT)
        #define DIGITAL_BACKGROUND_WIDTH                     (88)
        #define DIGITAL_BACKGROUND_HEIGHT                    (88)
    #else
        #define DIGITAL_BACKGROUND_X                         (MMI_SIGNAL_X + MMI_SIGNAL_WIDTH)
        #define DIGITAL_BACKGROUND_Y                         (MMI_STATUS_BAR_HEIGHT)
        #define DIGITAL_BACKGROUND_WIDTH                     (94)
        #define DIGITAL_BACKGROUND_HEIGHT                    (88)
    #endif /* (__MMI_DIGITAL_CLOCK_IMAGE_NUMBER__) */
        #define MMI_IDLE_DETAILS_START_Y_WITH_REMINDER      (84)
        #define MMI_IDLE_DETAILS_VGAP_WITH_REMINDER         (6)
    #else
        #define MMI_IDLE_DETAILS_START_Y_WITH_REMINDER      (MMI_IDLE_NETWORK_NAME_Y)
        #define MMI_IDLE_DETAILS_VGAP_WITH_REMINDER         (6)
    #endif /* defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__) */
    
    #if defined(__MMI_OP01_DCD__)
        #define MMI_IDLE_DCD_HEIGHT                         (74)
        #define MMI_IDLE_DCD_START_Y                        (MAIN_LCD_DEVICE_HEIGHT - MMI_SOFTKEY_HEIGHT - MMI_IDLE_DCD_HEIGHT /* 222 */)
        #define MMI_DCD_DT_DISPLAY_GAP                      (17)
    #endif /* defined(__MMI_OP01_DCD__) */

        #define MMI_IDLE_NETWORK_NAME_Y_WITH_CLOCK_BG       (45)
        #define MMI_IDLE_NETWORK_NAME_ICON_GAP              (1)
        #define MMI_IDLE_STRING_MARGIN_GAP                  (16)
        #define MMI_IDLE_SIM2_NETWORK_NAME_Y_WITH_CLOCK_BG  (68)
        
        #define MMI_TITLE_PADDING                           (4)
        #define MMI_TITLE_X                                 (0)
    
        #define MMI_TITLE_WIDTH                             (MAIN_LCD_DEVICE_WIDTH)
        #define MMI_CONTENT_X                               (0)
        #define MMI_CONTENT_Y                               (MMI_TITLE_Y+MMI_TITLE_HEIGHT)
        #define MMI_CONTENT_WIDTH                           (MAIN_LCD_DEVICE_WIDTH)

        #define MMI_ICONTEXT_MENUITEM_HEIGHT                (15)
        #define MMI_INLINE_EDIT_MENUITEM_HEIGHT             (30)

        #define MMI_MULTIROW_MENUITEM_HEIGHT                (48)

    #ifdef __MMI_UI_TAB_PANE__
        #define MMI_TAB_HEIGHT                              (30)
    #endif
    
    #ifdef __MMI_TOUCH_IDLESCREEN_SHORTCUTS__
        #define WGUI_TOUCH_IDLESCREEN_SHORTCUTS_HEIGHT      (50)
    #endif

        #define MMI_ROTATED_LCD_WIDTH                       (MAIN_LCD_DEVICE_HEIGHT)
        #define MMI_ROTATED_LCD_HEIGHT                      (MAIN_LCD_DEVICE_WIDTH)

        #define MMI_ROTATED_TITLE_WIDTH                     (230)
        #define MMI_ROTATED_TITLE_HEIGHT                    (MMI_TITLE_HEIGHT)

        #define MMI_ROTATED_CONTENT_WIDTH                   (230)
        #define MMI_ROTATED_CONTENT_HEIGHT                  (MMI_CONTENT_HEIGHT-(MMI_MENUITEM_HEIGHT << 1))

        #define MMI_ROTATED_TITLE_X                         (15)
        #define MMI_ROTATED_TITLE_Y                         ((MMI_ROTATED_LCD_HEIGHT -  MMI_ROTATED_CONTENT_HEIGHT - MMI_ROTATED_TITLE_HEIGHT)/2)

        #define MMI_ROTATED_CONTENT_X                       (15)
        #define MMI_ROTATED_CONTENT_Y                       (MMI_ROTATED_TITLE_Y + MMI_ROTATED_TITLE_HEIGHT)

#ifdef __MMI_FTE_SUPPORT__
        #define MMI_ROTATED_POP_UP_DIALOG_X                 (25)
        #define MMI_ROTATED_POP_UP_DIALOG_Y                 (57)
        #define MMI_ROTATED_POP_UP_DIALOG_WIDTH             (215)
        #define MMI_ROTATED_POP_UP_DIALOG_HEIGHT            (163)
        #define MMI_ROTATED_POP_UP_DIALOG_FULL_HEIGHT       (163)
        #define MMI_ROTATED_POP_UP_DIALOG_CENTERED_X        ((MMI_ROTATED_LCD_WIDTH - MMI_ROTATED_POP_UP_DIALOG_WIDTH) >> 1)

#else
        #define MMI_ROTATED_POP_UP_DIALOG_X                 (MMI_ROTATED_CONTENT_X + 10)
        #define MMI_ROTATED_POP_UP_DIALOG_Y                 (MMI_ROTATED_TITLE_Y + MMI_ROTATED_TITLE_HEIGHT + 10)
        #define MMI_ROTATED_POP_UP_DIALOG_WIDTH             (MMI_ROTATED_CONTENT_WIDTH - 15)
        #define MMI_ROTATED_POP_UP_DIALOG_HEIGHT            (MMI_ROTATED_LCD_HEIGHT - MMI_ROTATED_POP_UP_DIALOG_Y - 20)
        #define MMI_ROTATED_POP_UP_DIALOG_FULL_HEIGHT       (MMI_ROTATED_POP_UP_DIALOG_HEIGHT)
        #define MMI_ROTATED_POP_UP_DIALOG_CENTERED_X        ((MMI_ROTATED_LCD_WIDTH - MMI_ROTATED_POP_UP_DIALOG_WIDTH) >> 1)
#endif
        #define MMI_ROTATED_BUTTON_BAR_X                    (MMI_ROTATED_CONTENT_X + MMI_ROTATED_CONTENT_WIDTH + 3 /* leave space for border frame */)
        #define MMI_ROTATED_BUTTON_BAR_Y                    (0)
        #define MMI_ROTATED_BUTTON_BAR_WIDTH                (MMI_ROTATED_LCD_WIDTH - MMI_ROTATED_CONTENT_X - MMI_ROTATED_CONTENT_WIDTH - 3)
        #define MMI_ROTATED_BUTTON_BAR_HEIGHT               (MMI_ROTATED_LCD_HEIGHT)
        #define MMI_ROTATED_SOFTKEY_WIDTH                   (MMI_ROTATED_BUTTON_BAR_WIDTH)
        #define MMI_ROTATED_SOFTKEY_HEIGHT                  (MMI_SOFTKEY_HEIGHT)
        #define MMI_ROTATED_SOFTKEY_GAP                     (MMI_UI_SOFTKEY_GAP)


#elif __MMI_MAINLCD_128X64__
    #define MMI_IDLE_DT_BORDER_GAP                          (3)
    #define MMI_IDLE_DT_TIME_Y                              (36)
    #define MMI_IDLE_DT_DATE_Y                              (MMI_IDLE_DT_TIME_Y)

    #define MMI_IDLE_NETWORK_INFO_MARGIN_GAP                (2)
    #define MMI_IDLE_NETWORK_NAME_AREA_WIDTH                (76)
    #define MMI_IDLE_NETWORK_STATUS_AREA_WIDTH              (MAIN_LCD_DEVICE_WIDTH - MMI_IDLE_NETWORK_NAME_AREA_WIDTH - (MMI_IDLE_NETWORK_INFO_MARGIN_GAP << 1))

        #define MMI_SMALL_SCREEN_X_OFFSET                   (16)
        #define MMI_SMALL_SCREEN_Y_OFFSET                   (22)
        #define MMI_SMALL_LIST_LEFT_OFFSET                  2
        #define MMI_SMALL_LIST_SCREEN_WIDTH                 ((MAIN_LCD_DEVICE_WIDTH*3)/4)

    #if defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)
        #define MMI_IDLESCREEN_BAR_HEIGHT                   (80)
        #define MMI_SIGNAL_X                                (0)
        #define MMI_SIGNAL_Y                                (0)
        #define MMI_SIGNAL_WIDTH                            (3)
        #define ANALOG_BACKGROUND_X                         (MMI_SIGNAL_X + MMI_SIGNAL_WIDTH)
        #define ANALOG_BACKGROUND_Y                         (MMI_STATUS_BAR_HEIGHT)
        #define ANALOG_BACKGROUND_WIDTH                     (80)
    #if !defined(__MMI_DIGITAL_CLOCK_IMAGE_NUMBER__)
        #define DIGITAL_BACKGROUND_X                         (MMI_SIGNAL_X + MMI_SIGNAL_WIDTH)
        #define DIGITAL_BACKGROUND_Y                         (MMI_STATUS_BAR_HEIGHT)
        #define DIGITAL_BACKGROUND_WIDTH                     (88)
        #define DIGITAL_BACKGROUND_HEIGHT                    (88)
    #else
        #define DIGITAL_BACKGROUND_X                         (MMI_SIGNAL_X + MMI_SIGNAL_WIDTH)
        #define DIGITAL_BACKGROUND_Y                         (MMI_STATUS_BAR_HEIGHT)
        #define DIGITAL_BACKGROUND_WIDTH                     (94)
        #define DIGITAL_BACKGROUND_HEIGHT                    (88)
    #endif /* (__MMI_DIGITAL_CLOCK_IMAGE_NUMBER__) */
        #define MMI_IDLE_DETAILS_START_Y_WITH_REMINDER      (104)
        #define MMI_IDLE_DETAILS_VGAP_WITH_REMINDER         (6)
    #else
        #define MMI_IDLE_DETAILS_START_Y_WITH_REMINDER      (MMI_IDLE_NETWORK_NAME_Y)
        #define MMI_IDLE_DETAILS_VGAP_WITH_REMINDER         (6)
    #endif /* defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__) */
    
    #if defined(__MMI_OP01_DCD__)
        #define MMI_IDLE_DCD_HEIGHT                         (74)
        #define MMI_IDLE_DCD_START_Y                        (MAIN_LCD_DEVICE_HEIGHT - MMI_SOFTKEY_HEIGHT - MMI_IDLE_DCD_HEIGHT /* 222 */)
        #define MMI_DCD_DT_DISPLAY_GAP                      (17)
    #endif /* defined(__MMI_OP01_DCD__) */

        #define MMI_IDLE_NETWORK_NAME_Y_WITH_CLOCK_BG       (45)
        #define MMI_IDLE_NETWORK_NAME_ICON_GAP              (1)
        #define MMI_IDLE_STRING_MARGIN_GAP                  (16)
        #define MMI_IDLE_SIM2_NETWORK_NAME_Y_WITH_CLOCK_BG  (68)
        
        #define MMI_TITLE_PADDING                           (4)
        #define MMI_TITLE_X                                 (0)
    
        #define MMI_TITLE_WIDTH                             (MAIN_LCD_DEVICE_WIDTH)
        #define MMI_CONTENT_X                               (0)
        #define MMI_CONTENT_Y                               (MMI_TITLE_Y+MMI_TITLE_HEIGHT)
        #define MMI_CONTENT_WIDTH                           (MAIN_LCD_DEVICE_WIDTH)

        #define MMI_ICONTEXT_MENUITEM_HEIGHT                (15)
        #define MMI_INLINE_EDIT_MENUITEM_HEIGHT             (30)

        #define MMI_MULTIROW_MENUITEM_HEIGHT                (48)

    #ifdef __MMI_UI_TAB_PANE__
        #define MMI_TAB_HEIGHT                              (30)
    #endif
    
    #ifdef __MMI_TOUCH_IDLESCREEN_SHORTCUTS__
        #define WGUI_TOUCH_IDLESCREEN_SHORTCUTS_HEIGHT      (50)
    #endif

        #define MMI_ROTATED_LCD_WIDTH                       (MAIN_LCD_DEVICE_HEIGHT)
        #define MMI_ROTATED_LCD_HEIGHT                      (MAIN_LCD_DEVICE_WIDTH)

        #define MMI_ROTATED_TITLE_WIDTH                     (230)
        #define MMI_ROTATED_TITLE_HEIGHT                    (MMI_TITLE_HEIGHT)

        #define MMI_ROTATED_CONTENT_WIDTH                   (230)
        #define MMI_ROTATED_CONTENT_HEIGHT                  (MMI_CONTENT_HEIGHT-(MMI_MENUITEM_HEIGHT << 1))

        #define MMI_ROTATED_TITLE_X                         (15)
        #define MMI_ROTATED_TITLE_Y                         ((MMI_ROTATED_LCD_HEIGHT -  MMI_ROTATED_CONTENT_HEIGHT - MMI_ROTATED_TITLE_HEIGHT)/2)

        #define MMI_ROTATED_CONTENT_X                       (15)
        #define MMI_ROTATED_CONTENT_Y                       (MMI_ROTATED_TITLE_Y + MMI_ROTATED_TITLE_HEIGHT)

#ifdef __MMI_FTE_SUPPORT__
        #define MMI_ROTATED_POP_UP_DIALOG_X                 (25)
        #define MMI_ROTATED_POP_UP_DIALOG_Y                 (57)
        #define MMI_ROTATED_POP_UP_DIALOG_WIDTH             (215)
        #define MMI_ROTATED_POP_UP_DIALOG_HEIGHT            (163)
        #define MMI_ROTATED_POP_UP_DIALOG_FULL_HEIGHT       (163)
        #define MMI_ROTATED_POP_UP_DIALOG_CENTERED_X        ((MMI_ROTATED_LCD_WIDTH - MMI_ROTATED_POP_UP_DIALOG_WIDTH) >> 1)

#else
        #define MMI_ROTATED_POP_UP_DIALOG_X                 (MMI_ROTATED_CONTENT_X + 10)
        #define MMI_ROTATED_POP_UP_DIALOG_Y                 (MMI_ROTATED_TITLE_Y + MMI_ROTATED_TITLE_HEIGHT + 10)
        #define MMI_ROTATED_POP_UP_DIALOG_WIDTH             (MMI_ROTATED_CONTENT_WIDTH - 15)
        #define MMI_ROTATED_POP_UP_DIALOG_HEIGHT            (MMI_ROTATED_LCD_HEIGHT - MMI_ROTATED_POP_UP_DIALOG_Y - 20)
        #define MMI_ROTATED_POP_UP_DIALOG_FULL_HEIGHT       (MMI_ROTATED_POP_UP_DIALOG_HEIGHT)
        #define MMI_ROTATED_POP_UP_DIALOG_CENTERED_X        ((MMI_ROTATED_LCD_WIDTH - MMI_ROTATED_POP_UP_DIALOG_WIDTH) >> 1)
#endif
        #define MMI_ROTATED_BUTTON_BAR_X                    (MMI_ROTATED_CONTENT_X + MMI_ROTATED_CONTENT_WIDTH + 3 /* leave space for border frame */)
        #define MMI_ROTATED_BUTTON_BAR_Y                    (0)
        #define MMI_ROTATED_BUTTON_BAR_WIDTH                (MMI_ROTATED_LCD_WIDTH - MMI_ROTATED_CONTENT_X - MMI_ROTATED_CONTENT_WIDTH - 3)
        #define MMI_ROTATED_BUTTON_BAR_HEIGHT               (MMI_ROTATED_LCD_HEIGHT)
        #define MMI_ROTATED_SOFTKEY_WIDTH                   (MMI_ROTATED_BUTTON_BAR_WIDTH)
        #define MMI_ROTATED_SOFTKEY_HEIGHT                  (MMI_SOFTKEY_HEIGHT)
        #define MMI_ROTATED_SOFTKEY_GAP                     (MMI_UI_SOFTKEY_GAP)
// baiwenlin 20130821  
#elif defined __MMI_MAINLCD_128X36__
        #define MMI_SMALL_SCREEN_X_OFFSET                   (9)
        #define MMI_SMALL_SCREEN_Y_OFFSET                   (9)
        #define MMI_SMALL_LIST_LEFT_OFFSET                  2
        #define MMI_SMALL_LIST_SCREEN_WIDTH                 ((MAIN_LCD_DEVICE_WIDTH*3)/4)

        #define MMI_IDLE_NETWORK_NAME_Y_WITH_CLOCK_BG       (19)
        #define MMI_IDLE_NETWORK_NAME_ICON_GAP              (1)
        #define MMI_IDLE_STRING_MARGIN_GAP                  (16)
        #define MMI_IDLE_DETAILS_START_Y_WITH_REMINDER      (MMI_IDLE_NETWORK_NAME_Y)
        #define MMI_IDLE_DETAILS_VGAP_WITH_REMINDER         (3)
        #define MMI_IDLE_SIM2_NETWORK_NAME_Y_WITH_CLOCK_BG  (0)
        #define MMI_TITLE_PADDING                           (0)
        #define MMI_TITLE_X                                 (0)
        
        #define MMI_TITLE_WIDTH                             (MAIN_LCD_DEVICE_WIDTH)
        
        #define MMI_CONTENT_X                               (0)
        #define MMI_CONTENT_Y                               (MMI_TITLE_HEIGHT)
        #define MMI_CONTENT_WIDTH                           (MAIN_LCD_DEVICE_WIDTH)

        #define MMI_ICONTEXT_MENUITEM_HEIGHT                (18)
        #define MMI_INLINE_EDIT_MENUITEM_HEIGHT             (18)

        #define MMI_MULTIROW_MENUITEM_HEIGHT                (39)

        #define MMI_ROTATED_LCD_HEIGHT                      (128)
        #define MMI_ROTATED_BUTTON_BAR_X                    (128 - MMI_SOFTKEY_WIDTH - 3)
        #define MMI_ROTATED_BUTTON_BAR_Y                    (0)
        #define MMI_ROTATED_BUTTON_BAR_WIDTH                (MMI_SOFTKEY_WIDTH + 2)
        #define MMI_ROTATED_BUTTON_BAR_HEIGHT               (MMI_ROTATED_LCD_HEIGHT)
        #define MMI_ROTATED_SOFTKEY_WIDTH                   (MMI_ROTATED_BUTTON_BAR_WIDTH)
        #define MMI_ROTATED_SOFTKEY_HEIGHT                  (MMI_SOFTKEY_HEIGHT)
        #define MMI_ROTATED_SOFTKEY_GAP                     (2)

#elif defined __MMI_MAINLCD_128X128__
        #define MMI_SMALL_SCREEN_X_OFFSET                   (9)
        #define MMI_SMALL_SCREEN_Y_OFFSET                   (9)
        #define MMI_SMALL_LIST_LEFT_OFFSET                  2
        #define MMI_SMALL_LIST_SCREEN_WIDTH                 ((MAIN_LCD_DEVICE_WIDTH*3)/4)

        #define MMI_IDLE_NETWORK_NAME_Y_WITH_CLOCK_BG       (19)
        #define MMI_IDLE_NETWORK_NAME_ICON_GAP              (1)
        #define MMI_IDLE_STRING_MARGIN_GAP                  (18)
        #define MMI_IDLE_DETAILS_START_Y_WITH_REMINDER      (MMI_IDLE_NETWORK_NAME_Y)
        #define MMI_IDLE_DETAILS_VGAP_WITH_REMINDER         (3)
        #define MMI_IDLE_SIM2_NETWORK_NAME_Y_WITH_CLOCK_BG  (0)
        #define MMI_TITLE_PADDING                           (0)
        #define MMI_TITLE_X                                 (0)
        
        #define MMI_TITLE_WIDTH                             (MAIN_LCD_DEVICE_WIDTH)
        
        #define MMI_CONTENT_X                               (0)
        #define MMI_CONTENT_Y                               (MMI_TITLE_HEIGHT)
        #define MMI_CONTENT_WIDTH                           (MAIN_LCD_DEVICE_WIDTH)

        #define MMI_ICONTEXT_MENUITEM_HEIGHT                (18)
        #define MMI_INLINE_EDIT_MENUITEM_HEIGHT             (18)

        #define MMI_MULTIROW_MENUITEM_HEIGHT                (39)

        #define MMI_ROTATED_LCD_HEIGHT                      (128)
        #define MMI_ROTATED_BUTTON_BAR_X                    (128 - MMI_SOFTKEY_WIDTH - 3)
        #define MMI_ROTATED_BUTTON_BAR_Y                    (0)
        #define MMI_ROTATED_BUTTON_BAR_WIDTH                (MMI_SOFTKEY_WIDTH + 2)
        #define MMI_ROTATED_BUTTON_BAR_HEIGHT               (MMI_ROTATED_LCD_HEIGHT)
        #define MMI_ROTATED_SOFTKEY_WIDTH                   (MMI_ROTATED_BUTTON_BAR_WIDTH)
        #define MMI_ROTATED_SOFTKEY_HEIGHT                  (MMI_SOFTKEY_HEIGHT)
        #define MMI_ROTATED_SOFTKEY_GAP                     (2)
#elif defined __MMI_MAINLCD_128X160__

        #define MMI_SMALL_SCREEN_X_OFFSET                   (9)
        #define MMI_SMALL_SCREEN_Y_OFFSET                   (11)
        #define MMI_SMALL_LIST_LEFT_OFFSET                  2
        #define MMI_SMALL_LIST_SCREEN_WIDTH                 ((MAIN_LCD_DEVICE_WIDTH*3)/4)

        #define MMI_IDLE_NETWORK_NAME_Y_WITH_CLOCK_BG       (22)
        #define MMI_IDLE_NETWORK_NAME_ICON_GAP              (1)
        #define MMI_IDLE_STRING_MARGIN_GAP                  (18)
        #define MMI_IDLE_DETAILS_START_Y_WITH_REMINDER      (MMI_IDLE_NETWORK_NAME_Y)
        #define MMI_IDLE_DETAILS_VGAP_WITH_REMINDER         (3)
        #define MMI_IDLE_SIM2_NETWORK_NAME_Y_WITH_CLOCK_BG  (0)
        
        #define MMI_TITLE_PADDING                           (0)
        #define MMI_TITLE_X                                 (0)
        
        #define MMI_TITLE_WIDTH                             (MAIN_LCD_DEVICE_WIDTH)
        #define MMI_CONTENT_X                               (0)
        #define MMI_CONTENT_Y                               (MMI_TITLE_HEIGHT)
        #define MMI_CONTENT_WIDTH                           (MAIN_LCD_DEVICE_WIDTH)

        #define MMI_ICONTEXT_MENUITEM_HEIGHT                (17)
        #define MMI_INLINE_EDIT_MENUITEM_HEIGHT             (17)
        #define MMI_MULTIROW_MENUITEM_HEIGHT                (39)

        #define MMI_ROTATED_LCD_HEIGHT                      (128)
        #define MMI_ROTATED_BUTTON_BAR_X                    (160 - MMI_SOFTKEY_WIDTH - 3)
        #define MMI_ROTATED_BUTTON_BAR_Y                    (0)
        #define MMI_ROTATED_BUTTON_BAR_WIDTH                (MMI_SOFTKEY_WIDTH + 2)
        #define MMI_ROTATED_BUTTON_BAR_HEIGHT               (MMI_ROTATED_LCD_HEIGHT)
        #define MMI_ROTATED_SOFTKEY_WIDTH                   (MMI_ROTATED_BUTTON_BAR_WIDTH)
        #define MMI_ROTATED_SOFTKEY_HEIGHT                  (MMI_SOFTKEY_HEIGHT)
        #define MMI_ROTATED_SOFTKEY_GAP                     (2)
#elif defined __MMI_MAINLCD_176X220__

        #define MMI_SMALL_SCREEN_X_OFFSET                   (12)
        #define MMI_SMALL_SCREEN_Y_OFFSET                   (15)
        #define MMI_SMALL_LIST_LEFT_OFFSET                  2
        #define MMI_SMALL_LIST_SCREEN_WIDTH                 ((MAIN_LCD_DEVICE_WIDTH*3)/4)

    #if defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)
        #define MMI_IDLESCREEN_BAR_HEIGHT                   (60)
        #define MMI_SIGNAL_X                                (0)
        #define MMI_SIGNAL_Y                                (0)
        #define MMI_SIGNAL_WIDTH                            (5)
        #define ANALOG_BACKGROUND_X                         (MMI_SIGNAL_X + MMI_SIGNAL_WIDTH)
        #define ANALOG_BACKGROUND_Y                         (MMI_STATUS_BAR_HEIGHT)
        #define ANALOG_BACKGROUND_WIDTH                     (60)
        #define DIGITAL_BACKGROUND_X                         (MMI_SIGNAL_X + MMI_SIGNAL_WIDTH)
        #define DIGITAL_BACKGROUND_Y                         (MMI_STATUS_BAR_HEIGHT)
        #define DIGITAL_BACKGROUND_WIDTH                     (60)
        #define DIGITAL_BACKGROUND_HEIGHT                    (60)
    #endif /* defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__) */

    #if defined(__MMI_OP01_DCD__)
        #define MMI_IDLE_DCD_START_Y                        (148)
        #define MMI_IDLE_DCD_HEIGHT                         (52)
        #define MMI_DCD_DT_DISPLAY_GAP                      (1)
    #endif /*defined(__MMI_OP01_DCD__)*/

        #define MMI_IDLE_NETWORK_NAME_Y_WITH_CLOCK_BG       (26)
        #define MMI_IDLE_NETWORK_NAME_ICON_GAP              (1)
        #define MMI_IDLE_STRING_MARGIN_GAP                  (18)
        #define MMI_IDLE_DETAILS_START_Y_WITH_REMINDER      (MMI_IDLE_NETWORK_NAME_Y)
    #if defined(__MMI_OP01_DCD__)
        #define MMI_IDLE_DETAILS_VGAP_WITH_REMINDER         (1)
    #else 
        #define MMI_IDLE_DETAILS_VGAP_WITH_REMINDER         (3)
    #endif 
        #define MMI_IDLE_SIM2_NETWORK_NAME_Y_WITH_CLOCK_BG  (46)
        
        #define MMI_TITLE_PADDING                           (0)
        #define MMI_TITLE_X                                 (0)
    
        #define MMI_TITLE_WIDTH                             (MAIN_LCD_DEVICE_WIDTH)
        #define MMI_CONTENT_X                               (0)
        #define MMI_CONTENT_Y                               (MMI_TITLE_Y+MMI_TITLE_HEIGHT)
        #define MMI_CONTENT_WIDTH                           (MAIN_LCD_DEVICE_WIDTH)


        #define MMI_ICONTEXT_MENUITEM_HEIGHT                (22)
        #define MMI_INLINE_EDIT_MENUITEM_HEIGHT             (22)

        #define MMI_MULTIROW_MENUITEM_HEIGHT                (39)

        #define MMI_ROTATED_LCD_WIDTH                       (MAIN_LCD_DEVICE_HEIGHT)
        #define MMI_ROTATED_LCD_HEIGHT                      (MAIN_LCD_DEVICE_WIDTH)

        #define MMI_ROTATED_TITLE_WIDTH                     (155)
        #define MMI_ROTATED_TITLE_HEIGHT                    (MMI_TITLE_HEIGHT)

        #define MMI_ROTATED_CONTENT_WIDTH                   (155)
        #define MMI_ROTATED_CONTENT_HEIGHT                  (MMI_MENUITEM_HEIGHT * 5 + MMI_ROTATED_TITLE_HEIGHT)

        #define MMI_ROTATED_TITLE_X                         (10)
        #define MMI_ROTATED_TITLE_Y                         ((MMI_ROTATED_LCD_HEIGHT -  MMI_ROTATED_CONTENT_HEIGHT - MMI_ROTATED_TITLE_HEIGHT)/2)

        #define MMI_ROTATED_CONTENT_X                       (10)
        #define MMI_ROTATED_CONTENT_Y                       (MMI_ROTATED_TITLE_Y + MMI_ROTATED_TITLE_HEIGHT)

        #define MMI_ROTATED_POP_UP_DIALOG_X                 (MMI_ROTATED_CONTENT_X + 7)
        #define MMI_ROTATED_POP_UP_DIALOG_Y                 (MMI_ROTATED_TITLE_Y + MMI_ROTATED_TITLE_HEIGHT + 7)
        #define MMI_ROTATED_POP_UP_DIALOG_WIDTH             (MMI_ROTATED_CONTENT_WIDTH - 15)
        #define MMI_ROTATED_POP_UP_DIALOG_HEIGHT            (MMI_ROTATED_LCD_HEIGHT - MMI_ROTATED_POP_UP_DIALOG_Y - 20)
        #define MMI_ROTATED_POP_UP_DIALOG_FULL_HEIGHT       (MMI_ROTATED_POP_UP_DIALOG_HEIGHT)
        #define MMI_ROTATED_POP_UP_DIALOG_CENTERED_X        ((MMI_ROTATED_LCD_WIDTH - MMI_ROTATED_POP_UP_DIALOG_WIDTH) >> 1)

        #define MMI_ROTATED_BUTTON_BAR_X                    (MMI_ROTATED_CONTENT_X + MMI_ROTATED_CONTENT_WIDTH + 3 /* leave space for border frame */)
        #define MMI_ROTATED_BUTTON_BAR_Y                    (0)
        #define MMI_ROTATED_BUTTON_BAR_WIDTH                (MMI_ROTATED_LCD_WIDTH - MMI_ROTATED_CONTENT_X - MMI_ROTATED_CONTENT_WIDTH - 3)
        #define MMI_ROTATED_BUTTON_BAR_HEIGHT               (MMI_ROTATED_LCD_HEIGHT)
        #define MMI_ROTATED_SOFTKEY_WIDTH                   (MMI_ROTATED_BUTTON_BAR_WIDTH)
        #define MMI_ROTATED_SOFTKEY_HEIGHT                  (MMI_SOFTKEY_HEIGHT)
        #define MMI_ROTATED_SOFTKEY_GAP                     (MMI_UI_SOFTKEY_GAP)

#elif defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X240__)
        #define MMI_SMALL_SCREEN_X_OFFSET                   (16)
        #define MMI_SMALL_SCREEN_Y_OFFSET                   (22)
        #define MMI_SMALL_LIST_LEFT_OFFSET                  2
        #define MMI_SMALL_LIST_SCREEN_WIDTH                 ((MAIN_LCD_DEVICE_WIDTH*3)/4)

    #if defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)
        #define MMI_IDLESCREEN_BAR_HEIGHT                   (80)
        #define MMI_SIGNAL_X                                (0)
        #define MMI_SIGNAL_Y                                (0)
        #define MMI_SIGNAL_WIDTH                            (3)
        #define ANALOG_BACKGROUND_X                         (MMI_SIGNAL_X + MMI_SIGNAL_WIDTH)
        #define ANALOG_BACKGROUND_Y                         (MMI_STATUS_BAR_HEIGHT)
        #define ANALOG_BACKGROUND_WIDTH                     (80)
    #if !defined(__MMI_DIGITAL_CLOCK_IMAGE_NUMBER__)
        #define DIGITAL_BACKGROUND_X                         (MMI_SIGNAL_X + MMI_SIGNAL_WIDTH)
        #define DIGITAL_BACKGROUND_Y                         (MMI_STATUS_BAR_HEIGHT)
        #define DIGITAL_BACKGROUND_WIDTH                     (88)
        #define DIGITAL_BACKGROUND_HEIGHT                    (88)
    #else
        #define DIGITAL_BACKGROUND_X                         (MMI_SIGNAL_X + MMI_SIGNAL_WIDTH)
        #define DIGITAL_BACKGROUND_Y                         (MMI_STATUS_BAR_HEIGHT)
        #define DIGITAL_BACKGROUND_WIDTH                     (94)
        #define DIGITAL_BACKGROUND_HEIGHT                    (88)
    #endif /* (__MMI_DIGITAL_CLOCK_IMAGE_NUMBER__) */
        #define MMI_IDLE_DETAILS_START_Y_WITH_REMINDER      (104)
        #define MMI_IDLE_DETAILS_VGAP_WITH_REMINDER         (6)
    #else
        #define MMI_IDLE_DETAILS_START_Y_WITH_REMINDER      (MMI_IDLE_NETWORK_NAME_Y)
        #define MMI_IDLE_DETAILS_VGAP_WITH_REMINDER         (6)
    #endif /* defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__) */
    
    #if defined(__MMI_OP01_DCD__)
        #define MMI_IDLE_DCD_HEIGHT                         (74)
        #define MMI_IDLE_DCD_START_Y                        (MAIN_LCD_DEVICE_HEIGHT - MMI_SOFTKEY_HEIGHT - MMI_IDLE_DCD_HEIGHT)
        #define MMI_DCD_DT_DISPLAY_GAP                      (17)
    #endif /* defined(__MMI_OP01_DCD__) */

        #define MMI_IDLE_NETWORK_NAME_Y_WITH_CLOCK_BG       (45)
        #define MMI_IDLE_NETWORK_NAME_ICON_GAP              (1)
        #define MMI_IDLE_STRING_MARGIN_GAP                  (22)
        #define MMI_IDLE_SIM2_NETWORK_NAME_Y_WITH_CLOCK_BG  (68)
        
        #define MMI_TITLE_PADDING                           (4)
        #define MMI_TITLE_X                                 (0)
    
        #define MMI_TITLE_WIDTH                             (MAIN_LCD_DEVICE_WIDTH)
        #define MMI_CONTENT_X                               (0)
        #define MMI_CONTENT_Y                               (MMI_TITLE_Y+MMI_TITLE_HEIGHT)
        #define MMI_CONTENT_WIDTH                           (MAIN_LCD_DEVICE_WIDTH)

        #define MMI_ICONTEXT_MENUITEM_HEIGHT                (30)
        #define MMI_INLINE_EDIT_MENUITEM_HEIGHT             (30)

        #define MMI_MULTIROW_MENUITEM_HEIGHT                (48)

    #ifdef __MMI_UI_TAB_PANE__
        #define MMI_TAB_HEIGHT                              (30)
    #endif
    
    #ifdef __MMI_TOUCH_IDLESCREEN_SHORTCUTS__
        #define WGUI_TOUCH_IDLESCREEN_SHORTCUTS_HEIGHT      (50)
    #endif

        #define MMI_ROTATED_LCD_WIDTH                       (MAIN_LCD_DEVICE_HEIGHT)
        #define MMI_ROTATED_LCD_HEIGHT                      (MAIN_LCD_DEVICE_WIDTH)

        #define MMI_ROTATED_TITLE_WIDTH                     (230)
        #define MMI_ROTATED_TITLE_HEIGHT                    (MMI_TITLE_HEIGHT)
#if defined(__MMI_MAINLCD_240X320__) && defined(__COSMOS_MMI__)
        #define MMI_ROTATED_CONTENT_WIDTH                   (MMI_ROTATED_LCD_WIDTH - MMI_ROTATED_CONTENT_X - MMI_SOFTKEY_WIDTH - 3)//(320-5)//for 24 font
        #define MMI_ROTATED_CONTENT_HEIGHT                  (140)
        #define MMI_ROTATED_CONTENT_X                       (0)
#else
        #define MMI_ROTATED_CONTENT_WIDTH                   (MMI_ROTATED_LCD_WIDTH - MMI_ROTATED_CONTENT_X - MMI_SOFTKEY_WIDTH - 3)//(230-5)//for 24 font
        #define MMI_ROTATED_CONTENT_HEIGHT                  (MMI_CONTENT_HEIGHT-(MMI_MENUITEM_HEIGHT << 1))
        #define MMI_ROTATED_CONTENT_X                       (15)
#endif
        #define MMI_ROTATED_TITLE_X                         (15)
        #define MMI_ROTATED_TITLE_Y                         ((MMI_ROTATED_LCD_HEIGHT -  MMI_ROTATED_CONTENT_HEIGHT - MMI_ROTATED_TITLE_HEIGHT)/2)

        #define MMI_ROTATED_CONTENT_Y                       (MMI_ROTATED_TITLE_Y + MMI_ROTATED_TITLE_HEIGHT)

#ifdef __MMI_FTE_SUPPORT__
        #define MMI_ROTATED_POP_UP_DIALOG_X                 (25)
        #define MMI_ROTATED_POP_UP_DIALOG_Y                 (57)
        #define MMI_ROTATED_POP_UP_DIALOG_WIDTH             (215)
        #define MMI_ROTATED_POP_UP_DIALOG_HEIGHT            (163)
        #define MMI_ROTATED_POP_UP_DIALOG_FULL_HEIGHT       (163)
        #define MMI_ROTATED_POP_UP_DIALOG_CENTERED_X        ((MMI_ROTATED_LCD_WIDTH - MMI_ROTATED_POP_UP_DIALOG_WIDTH) >> 1)

#else
        #define MMI_ROTATED_POP_UP_DIALOG_X                 (MMI_ROTATED_CONTENT_X + 10)
        #define MMI_ROTATED_POP_UP_DIALOG_Y                 (38)
        #define MMI_ROTATED_POP_UP_DIALOG_WIDTH             (MMI_ROTATED_CONTENT_WIDTH - 15)
        #define MMI_ROTATED_POP_UP_DIALOG_HEIGHT            (163)
        #define MMI_ROTATED_POP_UP_DIALOG_FULL_HEIGHT       (MMI_ROTATED_POP_UP_DIALOG_HEIGHT)
        #define MMI_ROTATED_POP_UP_DIALOG_CENTERED_X        ((MMI_ROTATED_LCD_WIDTH - MMI_ROTATED_POP_UP_DIALOG_WIDTH) >> 1)
#endif
        #define MMI_ROTATED_BUTTON_BAR_X                    (MMI_ROTATED_CONTENT_X + MMI_ROTATED_CONTENT_WIDTH + 1 /* leave space for border frame */)
        #define MMI_ROTATED_BUTTON_BAR_Y                    (0)
        #define MMI_ROTATED_BUTTON_BAR_WIDTH                (MMI_ROTATED_LCD_WIDTH - MMI_ROTATED_CONTENT_X - MMI_ROTATED_CONTENT_WIDTH - 1)
        #define MMI_ROTATED_BUTTON_BAR_HEIGHT               (MMI_ROTATED_LCD_HEIGHT)
        #define MMI_ROTATED_SOFTKEY_WIDTH                   (MMI_ROTATED_BUTTON_BAR_WIDTH)
        #define MMI_ROTATED_SOFTKEY_HEIGHT                  (MMI_SOFTKEY_HEIGHT)
        #define MMI_ROTATED_SOFTKEY_GAP                     (2)

#elif defined __MMI_MAINLCD_240X400__
        #define MMI_SMALL_SCREEN_X_OFFSET                   (16)
        #define MMI_SMALL_SCREEN_Y_OFFSET                   (22)
        #define MMI_SMALL_LIST_LEFT_OFFSET                  2
        #define MMI_SMALL_LIST_SCREEN_WIDTH                 ((MAIN_LCD_DEVICE_WIDTH*3)/4)

    #if defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)
        #define MMI_IDLESCREEN_BAR_HEIGHT                   (80)
        #define MMI_SIGNAL_X                                (0)
        #define MMI_SIGNAL_Y                                (0)
        #define MMI_SIGNAL_WIDTH                            (3)
        #define ANALOG_BACKGROUND_X                         (MMI_SIGNAL_X + MMI_SIGNAL_WIDTH)
        #define ANALOG_BACKGROUND_Y                         (MMI_STATUS_BAR_HEIGHT)
        #define ANALOG_BACKGROUND_WIDTH                     (80)
    #if !defined(__MMI_DIGITAL_CLOCK_IMAGE_NUMBER__)
        #define DIGITAL_BACKGROUND_X                         (MMI_SIGNAL_X + MMI_SIGNAL_WIDTH)
        #define DIGITAL_BACKGROUND_Y                         (MMI_STATUS_BAR_HEIGHT)
        #define DIGITAL_BACKGROUND_WIDTH                     (88)
        #define DIGITAL_BACKGROUND_HEIGHT                    (89)
    #else
        #define DIGITAL_BACKGROUND_X                         (MMI_SIGNAL_X + MMI_SIGNAL_WIDTH)
        #define DIGITAL_BACKGROUND_Y                         (MMI_STATUS_BAR_HEIGHT)
        #define DIGITAL_BACKGROUND_WIDTH                     (94)
        #define DIGITAL_BACKGROUND_HEIGHT                    (88)
    #endif /* (__MMI_DIGITAL_CLOCK_IMAGE_NUMBER__) */        
    #endif /* defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__) */


    #if defined(__MMI_OP01_DCD__)
        #define MMI_IDLE_DCD_HEIGHT                         (74)
        #define MMI_IDLE_DCD_START_Y                        (MAIN_LCD_DEVICE_HEIGHT - MMI_SOFTKEY_HEIGHT - MMI_IDLE_DCD_HEIGHT)
        #define MMI_DCD_DT_DISPLAY_GAP                      (17)
    #endif /* defined(__MMI_OP01_DCD__) */

        #define MMI_IDLE_NETWORK_NAME_Y_WITH_CLOCK_BG       (45)
        #define MMI_IDLE_NETWORK_NAME_ICON_GAP              (1)
        #define MMI_IDLE_STRING_MARGIN_GAP                  (22)
        #define MMI_IDLE_DETAILS_START_Y_WITH_REMINDER      (MMI_IDLE_NETWORK_NAME_Y)
        #define MMI_IDLE_DETAILS_VGAP_WITH_REMINDER         (6)
        #define MMI_IDLE_SIM2_NETWORK_NAME_Y_WITH_CLOCK_BG  (65)
        
        #define MMI_TITLE_PADDING                           (4)
        #define MMI_TITLE_X                                 (0)
    
        #define MMI_TITLE_WIDTH                             (MAIN_LCD_DEVICE_WIDTH)
        #define MMI_CONTENT_X                               (0)
        #define MMI_CONTENT_Y                               (MMI_TITLE_Y+MMI_TITLE_HEIGHT)
        #define MMI_CONTENT_WIDTH                           (MAIN_LCD_DEVICE_WIDTH)

        #define MMI_ICONTEXT_MENUITEM_HEIGHT                (38)
        #define MMI_INLINE_EDIT_MENUITEM_HEIGHT             (38)

        #define MMI_MULTIROW_MENUITEM_HEIGHT                (50)

    #ifdef __MMI_UI_TAB_PANE__
        #define MMI_TAB_HEIGHT                              (30)
    #endif
    
    #ifdef __MMI_TOUCH_IDLESCREEN_SHORTCUTS__
        #define WGUI_TOUCH_IDLESCREEN_SHORTCUTS_HEIGHT      (50)
    #endif

        #define MMI_ROTATED_LCD_WIDTH                       (MAIN_LCD_DEVICE_HEIGHT)
        #define MMI_ROTATED_LCD_HEIGHT                      (MAIN_LCD_DEVICE_WIDTH)

        #define MMI_ROTATED_TITLE_WIDTH                     (296)
        #define MMI_ROTATED_TITLE_HEIGHT                    (MMI_TITLE_HEIGHT)

        #define MMI_ROTATED_TITLE_X                         (7)
        #define MMI_ROTATED_TITLE_Y                         (7)
#if defined(__MMI_MAINLCD_240X400__) && defined(__COSMOS_MMI__)
        #define MMI_ROTATED_CONTENT_WIDTH                   (MMI_ROTATED_LCD_WIDTH - MMI_ROTATED_CONTENT_X - MMI_SOFTKEY_WIDTH - 3)//(400-5)//for 24 font
        #define MMI_ROTATED_CONTENT_HEIGHT                  (140)
        #define MMI_ROTATED_CONTENT_X                       (0)
#else
        #define MMI_ROTATED_CONTENT_WIDTH                   (MMI_ROTATED_LCD_WIDTH - MMI_ROTATED_CONTENT_X - MMI_SOFTKEY_WIDTH - 3)//(296-5)//for 24 font
        #define MMI_ROTATED_CONTENT_HEIGHT                  (MMI_ROTATED_LCD_HEIGHT - MMI_ROTATED_TITLE_HEIGHT - (MMI_ROTATED_TITLE_Y*2))
        #define MMI_ROTATED_CONTENT_X                       (7)
#endif
        #define MMI_ROTATED_CONTENT_Y                       (MMI_ROTATED_TITLE_Y + MMI_ROTATED_TITLE_HEIGHT)

        #define MMI_ROTATED_POP_UP_DIALOG_X                 (48)
        #define MMI_ROTATED_POP_UP_DIALOG_Y                 (41)
        #define MMI_ROTATED_POP_UP_DIALOG_WIDTH             (219)
        #define MMI_ROTATED_POP_UP_DIALOG_HEIGHT            (162)
        #define MMI_ROTATED_POP_UP_DIALOG_FULL_HEIGHT       (MMI_ROTATED_POP_UP_DIALOG_HEIGHT)
        #define MMI_ROTATED_POP_UP_DIALOG_CENTERED_X        ((MMI_ROTATED_LCD_WIDTH - MMI_ROTATED_POP_UP_DIALOG_WIDTH) >> 1)

        #define MMI_ROTATED_BUTTON_BAR_X                    (MMI_ROTATED_CONTENT_X + MMI_ROTATED_CONTENT_WIDTH + 3 /* leave space for border frame */)
        #define MMI_ROTATED_BUTTON_BAR_Y                    (0)
        #define MMI_ROTATED_BUTTON_BAR_WIDTH                (MMI_ROTATED_LCD_WIDTH - MMI_ROTATED_CONTENT_X - MMI_ROTATED_CONTENT_WIDTH - 3)
        #define MMI_ROTATED_BUTTON_BAR_HEIGHT               (MMI_ROTATED_LCD_HEIGHT)
        #define MMI_ROTATED_SOFTKEY_WIDTH                   (MMI_ROTATED_BUTTON_BAR_WIDTH)
        #define MMI_ROTATED_SOFTKEY_HEIGHT                  (MMI_SOFTKEY_HEIGHT)
        #define MMI_ROTATED_SOFTKEY_GAP                     (MMI_UI_SOFTKEY_GAP)

#elif defined __MMI_MAINLCD_320X240__
        #define MMI_SMALL_SCREEN_X_OFFSET                   (16)
        #define MMI_SMALL_SCREEN_Y_OFFSET                   (22)
        #define MMI_SMALL_LIST_LEFT_OFFSET                  2
        #define MMI_SMALL_LIST_SCREEN_WIDTH                 ((MAIN_LCD_DEVICE_WIDTH*3)/4)

    #if defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)
        #if defined(__MMI_DUAL_SIM_MASTER__)
            #define MMI_IDLESCREEN_BAR_HEIGHT                   (75)
        #else 
            #define MMI_IDLESCREEN_BAR_HEIGHT                   (65)
        #endif
        #define MMI_SIGNAL_X                                (0)
        #define MMI_SIGNAL_Y                                (0)
        #define MMI_SIGNAL_WIDTH                            (5)
        #define ANALOG_BACKGROUND_X                         (MMI_SIGNAL_X + MMI_SIGNAL_WIDTH)
        #define ANALOG_BACKGROUND_Y                         (MMI_STATUS_BAR_HEIGHT)
        #define ANALOG_BACKGROUND_WIDTH                     (80)
        #if !defined(__MMI_DIGITAL_CLOCK_IMAGE_NUMBER__)
        #define DIGITAL_BACKGROUND_X                         (3)
        #define DIGITAL_BACKGROUND_Y                         (MMI_STATUS_BAR_HEIGHT)
        #define DIGITAL_BACKGROUND_WIDTH                     (90)
        #define DIGITAL_BACKGROUND_HEIGHT                    (90)
    #else
        #define DIGITAL_BACKGROUND_X                         (6)
        #define DIGITAL_BACKGROUND_Y                         (MMI_STATUS_BAR_HEIGHT)
        #define DIGITAL_BACKGROUND_WIDTH                     (96)
        #define DIGITAL_BACKGROUND_HEIGHT                    (88)
    #endif /* (__MMI_DIGITAL_CLOCK_IMAGE_NUMBER__) */        

    #endif /* defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__) */
        
        #define MMI_IDLE_NETWORK_NAME_Y_WITH_CLOCK_BG       (40)
        #define MMI_IDLE_NETWORK_NAME_ICON_GAP              (1)
        #define MMI_IDLE_STRING_MARGIN_GAP                  (22)
        #define MMI_IDLE_DETAILS_START_Y_WITH_REMINDER      (MMI_IDLE_NETWORK_NAME_Y)
        #define MMI_IDLE_DETAILS_VGAP_WITH_REMINDER         (3)
        #define MMI_IDLE_SIM2_NETWORK_NAME_Y_WITH_CLOCK_BG  (63)
        
        #define MMI_TITLE_PADDING                           (4)
        #define MMI_TITLE_X                                 (0)
        #define MMI_TITLE_WIDTH                             (MAIN_LCD_DEVICE_WIDTH)
        #define MMI_CONTENT_X                               (0)
        #define MMI_CONTENT_Y                               (MMI_TITLE_Y+MMI_TITLE_HEIGHT)
        #define MMI_CONTENT_WIDTH                           (MAIN_LCD_DEVICE_WIDTH)

        #define MMI_ICONTEXT_MENUITEM_HEIGHT                (30)
        #define MMI_INLINE_EDIT_MENUITEM_HEIGHT             (30)

        #define MMI_MULTIROW_MENUITEM_HEIGHT                (48)

    #ifdef __MMI_TOUCH_IDLESCREEN_SHORTCUTS__
        #define WGUI_TOUCH_IDLESCREEN_SHORTCUTS_HEIGHT      50
    #endif

        #define MMI_ROTATED_LCD_WIDTH                       (MAIN_LCD_DEVICE_HEIGHT)
        #define MMI_ROTATED_LCD_HEIGHT                      (MAIN_LCD_DEVICE_WIDTH)

        #define MMI_ROTATED_TITLE_WIDTH                     (230)
        #define MMI_ROTATED_TITLE_HEIGHT                    (MMI_TITLE_HEIGHT)

        #define MMI_ROTATED_CONTENT_WIDTH                   (MMI_ROTATED_LCD_WIDTH - MMI_ROTATED_CONTENT_X - MMI_SOFTKEY_WIDTH - 3)//(230-5)//for 24 font
        #define MMI_ROTATED_CONTENT_HEIGHT                  (MMI_CONTENT_HEIGHT-(MMI_MENUITEM_HEIGHT << 1))

        #define MMI_ROTATED_TITLE_X                         (15)
        #define MMI_ROTATED_TITLE_Y                         ((MMI_ROTATED_LCD_HEIGHT -  MMI_ROTATED_CONTENT_HEIGHT - MMI_ROTATED_TITLE_HEIGHT)/2)

        #define MMI_ROTATED_CONTENT_X                       (15)
        #define MMI_ROTATED_CONTENT_Y                       (MMI_ROTATED_TITLE_Y + MMI_ROTATED_TITLE_HEIGHT)

        #define MMI_ROTATED_POP_UP_DIALOG_X                 (13)
        #define MMI_ROTATED_POP_UP_DIALOG_Y                 (75)
        #define MMI_ROTATED_POP_UP_DIALOG_WIDTH             (217)
        #define MMI_ROTATED_POP_UP_DIALOG_HEIGHT            (195)
        #define MMI_ROTATED_POP_UP_DIALOG_FULL_HEIGHT       (MMI_ROTATED_POP_UP_DIALOG_HEIGHT)
        #define MMI_ROTATED_POP_UP_DIALOG_CENTERED_X        ((MMI_ROTATED_LCD_WIDTH - MMI_ROTATED_POP_UP_DIALOG_WIDTH) >> 1)

        #define MMI_ROTATED_BUTTON_BAR_X                    (167)
        #define MMI_ROTATED_BUTTON_BAR_Y                    (0)
        #define MMI_ROTATED_BUTTON_BAR_WIDTH                (64)
        #define MMI_ROTATED_BUTTON_BAR_HEIGHT               (MMI_ROTATED_LCD_HEIGHT)
        #define MMI_ROTATED_SOFTKEY_WIDTH                   (MMI_ROTATED_BUTTON_BAR_WIDTH)
        #define MMI_ROTATED_SOFTKEY_HEIGHT                  (MMI_SOFTKEY_HEIGHT)
        #define MMI_ROTATED_SOFTKEY_GAP                     (2)
#elif defined __MMI_MAINLCD_480X800__ || defined __MMI_MAINLCD_320X480__ || defined __MMI_MAINLCD_360X640__
        #define MMI_SMALL_SCREEN_X_OFFSET                   (16)
        #define MMI_SMALL_SCREEN_Y_OFFSET                   (22)
        #define MMI_SMALL_LIST_LEFT_OFFSET                  2
        #define MMI_SMALL_LIST_SCREEN_WIDTH                 ((MAIN_LCD_DEVICE_WIDTH*3)/4)

    #if defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)
        #define MMI_IDLESCREEN_BAR_HEIGHT                   (80)
        #define MMI_SIGNAL_X                                (0)
        #define MMI_SIGNAL_Y                                (0)
        #define MMI_SIGNAL_WIDTH                            (5)
        #define ANALOG_BACKGROUND_X                         (MMI_SIGNAL_X + MMI_SIGNAL_WIDTH)
        #define ANALOG_BACKGROUND_Y                         (MMI_STATUS_BAR_HEIGHT)
        #define ANALOG_BACKGROUND_WIDTH                     (80)
        #define DIGITAL_BACKGROUND_X                         (3)
        #define DIGITAL_BACKGROUND_Y                         (MMI_STATUS_BAR_HEIGHT)
        #define DIGITAL_BACKGROUND_WIDTH                     (135)
        #define DIGITAL_BACKGROUND_HEIGHT                    (90)
    #endif /* defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__) */
        
    #if defined(__MMI_OP01_DCD__)
        #define MMI_IDLE_DCD_HEIGHT                         (74)
        #define MMI_IDLE_DCD_START_Y                        (MAIN_LCD_DEVICE_HEIGHT - MMI_SOFTKEY_HEIGHT - MMI_IDLE_DCD_HEIGHT)
        #define MMI_DCD_DT_DISPLAY_GAP                      (17)
    #endif /* defined(__MMI_OP01_DCD__) */
    
        #define MMI_IDLE_NETWORK_NAME_Y_WITH_CLOCK_BG       (45)
        #define MMI_IDLE_NETWORK_NAME_ICON_GAP              (1)
        #define MMI_IDLE_STRING_MARGIN_GAP                  (22)
        #define MMI_IDLE_DETAILS_START_Y_WITH_REMINDER      (MMI_IDLE_NETWORK_NAME_Y)
        #define MMI_IDLE_DETAILS_VGAP_WITH_REMINDER         (3)
        #define MMI_IDLE_SIM2_NETWORK_NAME_Y_WITH_CLOCK_BG  (65)
        
        #define MMI_TITLE_PADDING                           (4)
        #define MMI_TITLE_X                                 (0)
        #define MMI_TITLE_WIDTH                             (MAIN_LCD_DEVICE_WIDTH)
        #define MMI_CONTENT_X                               (0)
        #define MMI_CONTENT_Y                               (MMI_TITLE_Y+MMI_TITLE_HEIGHT)
        #define MMI_CONTENT_WIDTH                           (MAIN_LCD_DEVICE_WIDTH)

        #define MMI_ICONTEXT_MENUITEM_HEIGHT                (47)
        #define MMI_INLINE_EDIT_MENUITEM_HEIGHT             (47)

        #define MMI_MULTIROW_MENUITEM_HEIGHT                (76)

    #ifdef __MMI_TOUCH_IDLESCREEN_SHORTCUTS__
        #define WGUI_TOUCH_IDLESCREEN_SHORTCUTS_HEIGHT      50
    #endif

    #ifdef __MMI_IDLE_SCREEN_ICON_SHORTCUT__
        #define WGUI_IDLE_SCREEN_ICON_SHORTCUT_HEIGHT       (64)
    #endif /* __MMI_IDLE_SCREEN_ICON_SHORTCUT__ */

        #define MMI_ROTATED_LCD_WIDTH                       (MAIN_LCD_DEVICE_HEIGHT)
        #define MMI_ROTATED_LCD_HEIGHT                      (MAIN_LCD_DEVICE_WIDTH)

        #define MMI_ROTATED_TITLE_WIDTH                     (320)
        #define MMI_ROTATED_TITLE_HEIGHT                    (MMI_TITLE_HEIGHT)
#ifdef  __MMI_MAINLCD_480X800__
        #define MMI_ROTATED_CONTENT_WIDTH                   (MMI_ROTATED_LCD_WIDTH - MMI_ROTATED_CONTENT_X - MMI_SOFTKEY_WIDTH - 3)//(800-5)//for 24 font
		#define MMI_ROTATED_CONTENT_HEIGHT                  (315)
        #define MMI_ROTATED_TITLE_X                         (15)
        #define MMI_ROTATED_TITLE_Y                         (34)

        #define MMI_ROTATED_CONTENT_X                       (0)
        #define MMI_ROTATED_CONTENT_Y                       (80)
#elif defined(__MMI_MAINLCD_320X480__) && defined(__COSMOS_MMI__)
        #define MMI_ROTATED_CONTENT_WIDTH                   (MMI_ROTATED_LCD_WIDTH - MMI_ROTATED_CONTENT_X - MMI_SOFTKEY_WIDTH - 3)//(480-5)//for 24 font
		#define MMI_ROTATED_CONTENT_HEIGHT                  (220)
        #define MMI_ROTATED_TITLE_X                         (15)
        #define MMI_ROTATED_TITLE_Y                         (34)

        #define MMI_ROTATED_CONTENT_X                       (0)
        #define MMI_ROTATED_CONTENT_Y                       (48)
#else
        #define MMI_ROTATED_CONTENT_WIDTH                   (MMI_ROTATED_LCD_WIDTH - MMI_ROTATED_CONTENT_X - MMI_SOFTKEY_WIDTH - 3)//(320-5)//for 24 font
        #define MMI_ROTATED_CONTENT_HEIGHT                  (235)
        #define MMI_ROTATED_TITLE_X                         (15)
        #define MMI_ROTATED_TITLE_Y                         ((MMI_ROTATED_LCD_HEIGHT -  MMI_ROTATED_CONTENT_HEIGHT - MMI_ROTATED_TITLE_HEIGHT)/2)

        #define MMI_ROTATED_CONTENT_X                       (15)
        #define MMI_ROTATED_CONTENT_Y                       (MMI_ROTATED_TITLE_Y + MMI_ROTATED_TITLE_HEIGHT)
#endif
        #define MMI_ROTATED_POP_UP_DIALOG_X                 (30)
        #define MMI_ROTATED_POP_UP_DIALOG_Y                 (30)
        #define MMI_ROTATED_POP_UP_DIALOG_WIDTH             (300)
        #define MMI_ROTATED_POP_UP_DIALOG_HEIGHT            (260)
        #define MMI_ROTATED_POP_UP_DIALOG_FULL_HEIGHT       (MMI_ROTATED_POP_UP_DIALOG_HEIGHT)
        #define MMI_ROTATED_POP_UP_DIALOG_CENTERED_X        ((MMI_ROTATED_LCD_WIDTH - MMI_ROTATED_POP_UP_DIALOG_WIDTH) >> 1)

        #define MMI_ROTATED_BUTTON_BAR_X                    (MMI_ROTATED_CONTENT_X + MMI_ROTATED_CONTENT_WIDTH + 3 /* leave space for border frame */)
        #define MMI_ROTATED_BUTTON_BAR_Y                    (0)
        #define MMI_ROTATED_BUTTON_BAR_WIDTH                (MMI_ROTATED_LCD_WIDTH - MMI_ROTATED_CONTENT_X - MMI_ROTATED_CONTENT_WIDTH - 3)
        #define MMI_ROTATED_BUTTON_BAR_HEIGHT               (MMI_ROTATED_LCD_HEIGHT)
        #define MMI_ROTATED_SOFTKEY_WIDTH                   (MMI_ROTATED_BUTTON_BAR_WIDTH)
        #define MMI_ROTATED_SOFTKEY_HEIGHT                  (MMI_SOFTKEY_HEIGHT) 
        #define MMI_ROTATED_SOFTKEY_GAP                     (MMI_UI_SOFTKEY_GAP)
           
        #define MMI_POP_UP_SOFTKEY_X                        (20)
        #define MMI_POP_UP_SOFTKEY_Y                        (423)
        #define MMI_POP_UP_SOFTKEY_WIDTH                    (105)
        #define MMI_POP_UP_SOFTKEY_HEIGHT                   (45)    
#else
    #error "No UI Style is Specified!!"
#endif

/*******************
 * MainMenu Layout
 *******************/

#define MMI_MAINMENU_TITLE_X                                (MMI_TITLE_X)
#define MMI_MAINMENU_TITLE_WIDTH                            (MMI_TITLE_WIDTH)
#define MMI_MAINMENU_CONTENT_X                              (MMI_CONTENT_X)
#define MMI_MAINMENU_CONTENT_WIDTH                          (MMI_CONTENT_WIDTH)

#ifdef GUI_MAINMENU_SHOW_STATUS_ICON
#define MMI_MAINMENU_TITLE_Y                                (MMI_STATUS_BAR_HEIGHT)
#else 
    #define MMI_MAINMENU_TITLE_Y                            (0)
#endif

#ifdef GUI_MAINMENU_USE_THICK_TITLE
    #define MMI_MAINMENU_TITLE_HEIGHT                       (MMI_THICK_TITLE_HEIGHT)
#else
    #define MMI_MAINMENU_TITLE_HEIGHT                       (MMI_THIN_TITLE_HEIGHT)
#endif

#define MMI_MAINMENU_CONTENT_Y                              (MMI_MAINMENU_TITLE_Y + MMI_MAINMENU_TITLE_HEIGHT)
#define MMI_MAINMENU_CONTENT_HEIGHT                         (MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_MAINMENU_CONTENT_Y )

/*******************
 * SubMenu Layout
 *******************/

#define MMI_SUBMENU_TITLE_X                                 (MMI_TITLE_X)
#define MMI_SUBMENU_TITLE_WIDTH                             (MMI_TITLE_WIDTH)
#define MMI_SUBMENU_CONTENT_X                               (MMI_CONTENT_X)
#define MMI_SUBMENU_CONTENT_WIDTH                           (MMI_CONTENT_WIDTH)

#ifdef GUI_SUBMENU_SHOW_STATUS_ICON
#define MMI_SUBMENU_TITLE_Y                                 (MMI_STATUS_BAR_HEIGHT)
#else 
    #define MMI_SUBMENU_TITLE_Y                             (0)
#endif

#ifdef GUI_SUBMENU_USE_THICK_TITLE
    #define MMI_SUBMENU_TITLE_HEIGHT                        (MMI_THICK_TITLE_HEIGHT)
#else
    #define MMI_SUBMENU_TITLE_HEIGHT                        (MMI_THIN_TITLE_HEIGHT)
#endif

#define MMI_SUBMENU_CONTENT_Y                               (MMI_SUBMENU_TITLE_Y + MMI_SUBMENU_TITLE_HEIGHT)
#define MMI_SUBMENU_CONTENT_HEIGHT                          (MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_SUBMENU_CONTENT_Y )

/*******************
 * Common Layout
 *******************/

#define MMI_COMMON_TITLE_X                                  (MMI_TITLE_X)
#define MMI_COMMON_TITLE_WIDTH                              (MMI_TITLE_WIDTH)
#define MMI_COMMON_CONTENT_X                                (MMI_CONTENT_X)
#define MMI_COMMON_CONTENT_WIDTH                            (MMI_CONTENT_WIDTH)

#ifdef GUI_COMMON_SHOW_STATUS_ICON
#define MMI_COMMON_TITLE_Y                                  (MMI_STATUS_BAR_HEIGHT)
#else 
#define MMI_COMMON_TITLE_Y                                  (0)
#endif

#ifdef GUI_COMMON_USE_THICK_TITLE
    #define MMI_COMMON_TITLE_HEIGHT                         (MMI_THICK_TITLE_HEIGHT)
#else
    #define MMI_COMMON_TITLE_HEIGHT                         (MMI_THIN_TITLE_HEIGHT)
#endif
    
#if defined(__OLED_BW_MMI__)&&defined(__MMI_MAINLCD_128X64__)
#define MMI_COMMON_CONTENT_Y                                (MMI_COMMON_TITLE_Y + MMI_COMMON_TITLE_HEIGHT)
#define MMI_COMMON_CONTENT_HEIGHT                           (MAIN_LCD_DEVICE_HEIGHT  - MMI_COMMON_CONTENT_Y )
#else /*__OLED_BW_MMI__*/
#define MMI_COMMON_CONTENT_Y                                (MMI_COMMON_TITLE_Y + MMI_COMMON_TITLE_HEIGHT)
#define MMI_COMMON_CONTENT_HEIGHT                           (MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_COMMON_CONTENT_Y )
#endif /* __OLED_BW_MMI__ */

/*******************
 * Others
 *******************/

#define MMI_MATRIX_BAR_WIDTH                                (MAIN_LCD_DEVICE_WIDTH)
#define MMI_MATRIX_BAR_HEIGHT                               (19)
#define MMI_MATRIX_BAR_X                                    (0)
#define MMI_MATRIX_BAR_Y                                    (MAIN_LCD_DEVICE_HEIGHT-MMI_BUTTON_BAR_HEIGHT-MMI_MATRIX_BAR_HEIGHT+1)

#define MMI_MULTITAP_X                                      (2)
#define MMI_MULTITAP_WIDTH                                  (MAIN_LCD_DEVICE_WIDTH-4)

#if defined(__MMI_MAINLCD_240X320__)  || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X240__) 
   #define MMI_MULTITAP_HEIGHT                              (23)
#else
   #define MMI_MULTITAP_HEIGHT                              (17)
#endif

#define MMI_MULTITAP_Y                                      (MAIN_LCD_DEVICE_HEIGHT-MMI_BUTTON_BAR_HEIGHT-MMI_MULTITAP_HEIGHT)


#define MMI_SINGLELINE_INPUTBOX_X                           (5)
#define MMI_SINGLELINE_INPUTBOX_Y                           (40)
#define MMI_SINGLELINE_INPUTBOX_WIDTH                       (MAIN_LCD_DEVICE_WIDTH-10)
#if defined(__MMI_MAINLCD_240X320__)  || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X240__) 
#ifdef __MMI_FTE_SUPPORT__
    #define MMI_SINGLELINE_INPUTBOX_HEIGHT                  (35)
#else
    #define MMI_SINGLELINE_INPUTBOX_HEIGHT                  (26)
#endif
#elif defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
#ifdef __MMI_FTE_SUPPORT__
    #define MMI_SINGLELINE_INPUTBOX_HEIGHT                  (40)
#else
    #define MMI_SINGLELINE_INPUTBOX_HEIGHT                  (30)
#endif
#elif defined(__MMI_MAINLCD_128X64__)
    #define MMI_SINGLELINE_INPUTBOX_HEIGHT                  (14)
#elif defined(__MMI_MAINLCD_96X64__)
    #define MMI_SINGLELINE_INPUTBOX_HEIGHT                  (15)// SLIM_96_64_SLIM
#else
    #define MMI_SINGLELINE_INPUTBOX_HEIGHT                  (20)
#endif

#define MMI_RESERVED_PIXEL_FOR_MULTILINE                    5

#define MMI_MULTILINE_INPUTBOX_X                            (0)
#define MMI_MULTILINE_INPUTBOX_Y                            (20)
#define MMI_MULTILINE_INPUTBOX_WIDTH                        (MAIN_LCD_DEVICE_WIDTH)
#define MMI_MULTILINE_INPUTBOX_HEIGHT                       (MAIN_LCD_DEVICE_HEIGHT-82)

#define MMI_GENERAL_INPUTBOX_X                              (0)
#define MMI_GENERAL_INPUTBOX_Y                              (20)
#define MMI_GENERAL_INPUTBOX_WIDTH                          (MAIN_LCD_DEVICE_WIDTH)
#define MMI_GENERAL_INPUTBOX_HEIGHT                         (MAIN_LCD_DEVICE_HEIGHT-82)

/* Tab bar */
#define MMI_HORIZONTAL_TAB_BAR_X                            (MMI_TITLE_X)
#define MMI_HORIZONTAL_TAB_BAR_Y                            (MMI_TITLE_Y)
#define MMI_HORIZONTAL_TAB_BAR_WIDTH                        (MMI_TITLE_WIDTH)

#if defined(__MMI_MAINLCD_320X480__)  || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
    #ifdef __MMI_FTE_SUPPORT__
        #define MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT          (51)
        #define MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT         (52)
        #define MMI_HORIZONTAL_TAB_BAR_FOCUSED_TAB_WIDTH        (80)
        #define MMI_HORIZONTAL_TAB_BAR_TAB_WIDTH                (80)
    #else
        #define MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT          (38)
        #define MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT         (38)
        #define MMI_HORIZONTAL_TAB_BAR_FOCUSED_TAB_WIDTH        (64)
        #define MMI_HORIZONTAL_TAB_BAR_TAB_WIDTH                (64)
    #endif
#elif defined(__MMI_MAINLCD_320X240__) 
    #define MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT         (26)
#ifdef __MMI_FTE_SUPPORT__
    #define MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT          (34)
    #define MMI_HORIZONTAL_TAB_BAR_FOCUSED_TAB_WIDTH        (80)
    #define MMI_HORIZONTAL_TAB_BAR_TAB_WIDTH                (80)
#else
    #define MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT          (36)
    #define MMI_HORIZONTAL_TAB_BAR_FOCUSED_TAB_WIDTH        (50)
    #define MMI_HORIZONTAL_TAB_BAR_TAB_WIDTH                (50)
#endif
#elif defined(__MMI_MAINLCD_240X320__)
    #ifdef __MMI_OP11_TAB_BAR__
        #define MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT          (41)
        #define MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT         (34)
        #define MMI_HORIZONTAL_TAB_BAR_FOCUSED_TAB_WIDTH        (60)
        #define MMI_HORIZONTAL_TAB_BAR_TAB_WIDTH                (60)
    #elif defined(__MMI_FTE_SUPPORT__)
        #define MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT          (38)
        #define MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT         (34)
        #define MMI_HORIZONTAL_TAB_BAR_FOCUSED_TAB_WIDTH        (60)
        #define MMI_HORIZONTAL_TAB_BAR_TAB_WIDTH                (60)
    #else
        #define MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT          (28)
        #define MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT         (26)
        #define MMI_HORIZONTAL_TAB_BAR_FOCUSED_TAB_WIDTH        (60)
        #define MMI_HORIZONTAL_TAB_BAR_TAB_WIDTH                (60)
    #endif
#elif defined(__MMI_MAINLCD_240X400__)
    #ifdef __MMI_FTE_SUPPORT__
        #define MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT          (42)
        #define MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT         (42)
        #define MMI_HORIZONTAL_TAB_BAR_FOCUSED_TAB_WIDTH        (60)
        #define MMI_HORIZONTAL_TAB_BAR_TAB_WIDTH                (60)
    #else
        #define MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT          (34)
        #define MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT         (34)
        #define MMI_HORIZONTAL_TAB_BAR_FOCUSED_TAB_WIDTH        (52)
        #define MMI_HORIZONTAL_TAB_BAR_TAB_WIDTH                (52)
    #endif
#elif defined(__MMI_MAINLCD_176X220__)
    #define MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT          (20)
    #define MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT         (20)
    #define MMI_HORIZONTAL_TAB_BAR_FOCUSED_TAB_WIDTH        (44)
    #define MMI_HORIZONTAL_TAB_BAR_TAB_WIDTH                (44)
#elif defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__)
    #define MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT          (20)
    #define MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT         (20)
    #define MMI_HORIZONTAL_TAB_BAR_FOCUSED_TAB_WIDTH        (42)
    #define MMI_HORIZONTAL_TAB_BAR_TAB_WIDTH                (42)
#elif defined(__MMI_MAINLCD_128X64__)
    #define MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT			(15)
    #define MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT 		(15)
    #define MMI_HORIZONTAL_TAB_BAR_FOCUSED_TAB_WIDTH		(42)
    #define MMI_HORIZONTAL_TAB_BAR_TAB_WIDTH				(42)
#elif defined(__MMI_MAINLCD_128X36__)// baiwenlin 20130821  
    #define MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT			(15)
    #define MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT 		(15)
    #define MMI_HORIZONTAL_TAB_BAR_FOCUSED_TAB_WIDTH		(42)
    #define MMI_HORIZONTAL_TAB_BAR_TAB_WIDTH				(42)
#elif defined(__MMI_MAINLCD_96X64__)
    #define MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT			(15)
    #define MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT 		(15)
    #define MMI_HORIZONTAL_TAB_BAR_FOCUSED_TAB_WIDTH		(42)
    #define MMI_HORIZONTAL_TAB_BAR_TAB_WIDTH				(42)	
#else
    #define MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT          (20)
    #define MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT         (20)
    #define MMI_HORIZONTAL_TAB_BAR_FOCUSED_TAB_WIDTH        (42)
    #define MMI_HORIZONTAL_TAB_BAR_TAB_WIDTH                (42)
#endif

#ifdef __MMI_OP11_TAB_BAR__
    #define GUI_TAB_BAR_BACKGROUND_IMAGE_BORDER_WIDTH           (5)
#else/* __MMI_OP11_TAB_BAR__ */
    #if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
        #define GUI_TAB_BAR_BACKGROUND_IMAGE_BORDER_WIDTH       (20)
    #elif (defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__))
        #define GUI_TAB_BAR_BACKGROUND_IMAGE_BORDER_WIDTH       (15)
    #else
        #define GUI_TAB_BAR_BACKGROUND_IMAGE_BORDER_WIDTH       (10)
    #endif
#endif/* __MMI_OP11_TAB_BAR__ */

#ifdef __MMI_OP11_TAB_BAR__
    #if defined(__MMI_MAINLCD_240X320__)
        #define GUI_TAB_BAR_BACKGROUND_IMAGE_NORMAL_HEIGHT              (28)
        #define GUI_TAB_BAR_BACKGROUND_IMAGE_HIGHLIGHT_HEIGHT           (28)
    #else
        #define GUI_TAB_BAR_BACKGROUND_IMAGE_NORMAL_HEIGHT              (18)
        #define GUI_TAB_BAR_BACKGROUND_IMAGE_HIGHLIGHT_HEIGHT           (18)
    #endif
#else/* __MMI_OP11_TAB_BAR__ */
    #if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
        #define GUI_TAB_BAR_BACKGROUND_IMAGE_NORMAL_HEIGHT              (33)
        #define GUI_TAB_BAR_BACKGROUND_IMAGE_HIGHLIGHT_HEIGHT           (37)
    #elif defined(__MMI_MAINLCD_240X400__) 
        #define GUI_TAB_BAR_BACKGROUND_IMAGE_NORMAL_HEIGHT              (30)
        #define GUI_TAB_BAR_BACKGROUND_IMAGE_HIGHLIGHT_HEIGHT           (33)
    #elif defined(__MMI_MAINLCD_240X320__) 
        #define GUI_TAB_BAR_BACKGROUND_IMAGE_NORMAL_HEIGHT              (24)
        #define GUI_TAB_BAR_BACKGROUND_IMAGE_HIGHLIGHT_HEIGHT           (27)
    #elif defined(__MMI_MAINLCD_320X240__)
        #define GUI_TAB_BAR_BACKGROUND_IMAGE_NORMAL_HEIGHT              (32)
        #define GUI_TAB_BAR_BACKGROUND_IMAGE_HIGHLIGHT_HEIGHT           (35)
    #else
        #define GUI_TAB_BAR_BACKGROUND_IMAGE_NORMAL_HEIGHT              (17)
        #define GUI_TAB_BAR_BACKGROUND_IMAGE_HIGHLIGHT_HEIGHT           (19)
    #endif
#endif/* __MMI_OP11_TAB_BAR__ */


#define MMI_CONTENT_WIDTH_WITH_H_TAB                        (MMI_content_width)
#define MMI_CONTENT_HEIGHT_WITH_H_TAB                       (MMI_content_height + MMI_TITLE_HEIGHT - MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT - MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT)
#define MMI_CONTENT_X_WITH_H_TAB                            (MMI_content_x)
#define MMI_CONTENT_Y_WITH_H_TAB                            (MMI_content_y + MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT - MMI_TITLE_HEIGHT)

#define MMI_DROPDOWN_MENUITEM_HEIGHT                        (18)

#ifdef __MMI_FTE_SUPPORT__
    #define INFORMATION_BAR_HEIGHT                          (0)
#else
#if !defined(__MMI_TOUCH_SCREEN__)
    //W06.03 Adjust the height of the information bar for 240*320
    #if defined(__MMI_MAINLCD_240X320__)  || defined(__MMI_MAINLCD_240X400__)  || defined(__MMI_MAINLCD_320X240__) 
        #define INFORMATION_BAR_HEIGHT                      (24)
    #elif defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
    	#define INFORMATION_BAR_HEIGHT                      (24)
    #elif defined(__MMI_MAINLCD_96X64__) //SLIM_96_64_SLIM
        #define INFORMATION_BAR_HEIGHT                      (9)
    #else
        #define INFORMATION_BAR_HEIGHT                      (12)
    #endif
#else
    #if defined(__MMI_MAINLCD_240X320__)  || defined(__MMI_MAINLCD_240X400__)  || defined(__MMI_MAINLCD_320X240__) 
        #define INFORMATION_BAR_HEIGHT                      (24)
    #elif defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
    	#define INFORMATION_BAR_HEIGHT                      (24)
    #else
        #define INFORMATION_BAR_HEIGHT                      (18)
    #endif
#endif
#endif

#define MMI_POP_UP_DIALOG_FULL_Y                            (((MAIN_LCD_DEVICE_HEIGHT-MMI_POP_UP_DIALOG_FULL_HEIGHT)>>1) + 6)


/* 
 * MAIN MENU
 */

/* cache buffer size for the matrix main menu highlighted area */ 
#if MAIN_MENU_HIGHLIGHTED_IMAGE_WIDTH > MAIN_MENU_HIGHLIGHTED_IMAGE_HEIGHT
#define MMI_MAIN_MENU_MATRIX_HIGHLIGHTED_BUF_SIZE           (MAIN_MENU_HIGHLIGHTED_IMAGE_WIDTH * MAIN_MENU_HIGHLIGHTED_IMAGE_WIDTH * MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL / 8)
#else
#define MMI_MAIN_MENU_MATRIX_HIGHLIGHTED_BUF_SIZE           (MAIN_MENU_HIGHLIGHTED_IMAGE_HEIGHT * MAIN_MENU_HIGHLIGHTED_IMAGE_HEIGHT * MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL / 8)
#endif



/* Upper bound of the number of menu items in one screen */
#define MMI_MAX_MENUITEMS_IN_CONTENT                        (MMI_CONTENT_HEIGHT/MMI_MENUITEM_HEIGHT + 2) /* the magic number 2 is for safety. At least 1. */

#ifdef __MMI_TOUCH_SCREEN__
    #define MMI_PASSWD_KEYBOARD_START_X                     (0)
    #define MMI_PASSWD_KEYBOARD_START_Y                     (138)
#endif

/* Macros defined for title bar buttons used in Touch Panel support */
#if defined(__MMI_MAINLCD_240X320__)
#if defined(__MMI_FTE_SUPPORT__)
    #define MMI_TITLEBAR_BUTTON_GAP                         (1)
    #define MMI_TITLEBAR_BUTTON_WIDTH                       (28)
    #define MMI_TITLEBAR_BUTTON_HEIGHT                      (29)
#else
    #define MMI_TITLEBAR_BUTTON_GAP                         (20)
    #define MMI_TITLEBAR_BUTTON_WIDTH                       (19)
    #define MMI_TITLEBAR_BUTTON_HEIGHT                      (17)
#endif /* __MMI_FTE_SUPPORT__ */
#elif defined(__MMI_MAINLCD_240X400__)
#if defined(__MMI_FTE_SUPPORT__)
    #define MMI_TITLEBAR_BUTTON_GAP                         (1)
    #define MMI_TITLEBAR_BUTTON_WIDTH                       (32)
    #define MMI_TITLEBAR_BUTTON_HEIGHT                      (32)
#else
    #define MMI_TITLEBAR_BUTTON_GAP                         (12)
    #define MMI_TITLEBAR_BUTTON_WIDTH                       (26)
    #define MMI_TITLEBAR_BUTTON_HEIGHT                      (26)
#endif
#elif defined(__MMI_MAINLCD_320X240__)
#if defined(__MMI_FTE_SUPPORT__)
    #define MMI_TITLEBAR_BUTTON_GAP                         (1)
    #define MMI_TITLEBAR_BUTTON_WIDTH                       (28)
    #define MMI_TITLEBAR_BUTTON_HEIGHT                      (29)
#elif defined(__MMI_DUAL_SIM_MASTER__)
    #define MMI_TITLEBAR_BUTTON_GAP                         (46)
    #define MMI_TITLEBAR_BUTTON_WIDTH                       (19)
    #define MMI_TITLEBAR_BUTTON_HEIGHT                      (17)
#else
    #define MMI_TITLEBAR_BUTTON_GAP                         (22)
    #define MMI_TITLEBAR_BUTTON_WIDTH                       (19)
    #define MMI_TITLEBAR_BUTTON_HEIGHT                      (17)
#endif /* defined(__MMI_DUAL_SIM_MASTER__) */
#elif defined(__MMI_MAINLCD_176X220__)
    #define MMI_TITLEBAR_BUTTON_GAP                         (10)
    #define MMI_TITLEBAR_BUTTON_WIDTH                       (15)
    #define MMI_TITLEBAR_BUTTON_HEIGHT                      (15)
#elif defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
#if defined(__MMI_FTE_SUPPORT__)
    #define MMI_TITLEBAR_BUTTON_GAP                         (1)
    #define MMI_TITLEBAR_BUTTON_WIDTH                       (35)
    #define MMI_TITLEBAR_BUTTON_HEIGHT                      (35)
#else
    #define MMI_TITLEBAR_BUTTON_GAP                         (25)
    #define MMI_TITLEBAR_BUTTON_WIDTH                       (32)
    #define MMI_TITLEBAR_BUTTON_HEIGHT                      (32)
#endif /* __MMI_FTE_SUPPORT__ */
#else
    #define MMI_TITLEBAR_BUTTON_GAP                         (1)
    #define MMI_TITLEBAR_BUTTON_WIDTH                       (15)
    #define MMI_TITLEBAR_BUTTON_HEIGHT                      (15)
#endif

/************************************
 * static calendar on idle screen
 ***********************************/
#if defined (__MMI_CALENDAR_ON_IDLE_SCREEN__)
    #if defined (CFG_UI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_X)
        #define MMI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_X     CFG_UI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_X
    #endif    
    #if defined (CFG_UI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_Y)
        #define MMI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_Y     CFG_UI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_Y
    #endif    
    #if defined (CFG_UI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_WIDTH)
        #define MMI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_WIDTH     CFG_UI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_WIDTH
    #endif    
    #if defined (CFG_UI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_HEIGHT)
        #define MMI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_HEIGHT     CFG_UI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_HEIGHT
    #endif    
    #if defined (CFG_UI_IDLE_STATIC_CALENDAR_MONTH_TITLE_HEIGHT)
        #define MMI_IDLE_STATIC_CALENDAR_MONTH_TITLE_HEIGHT     CFG_UI_IDLE_STATIC_CALENDAR_MONTH_TITLE_HEIGHT
    #endif
    #if defined (CFG_UI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_X)
        #define MMI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_X     CFG_UI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_X
    #endif    
    #if defined (CFG_UI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_Y)
        #define MMI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_Y     CFG_UI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_Y
    #endif    
    #if defined (CFG_UI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_WIDTH)
        #define MMI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_WIDTH     CFG_UI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_WIDTH
    #endif    
    #if defined (CFG_UI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_HEIGHT)
        #define MMI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_HEIGHT     CFG_UI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_HEIGHT
    #endif    
    #if defined (CFG_UI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_X)
        #define MMI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_X     CFG_UI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_X
    #endif    
    #if defined (CFG_UI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_Y)
        #define MMI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_Y     CFG_UI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_Y
    #endif    
    #if defined (CFG_UI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_WIDTH)
        #define MMI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_WIDTH     CFG_UI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_WIDTH
    #endif
    #if defined (CFG_UI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_HEIGHT)
        #define MMI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_HEIGHT     CFG_UI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_HEIGHT
    #endif
    
    #if defined (CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_X)
        #define MMI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_X     CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_X
    #endif
    #if defined (CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_Y)
        #define MMI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_Y     CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_Y
    #endif
    #if defined (CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_WIDTH)
        #define MMI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_WIDTH     CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_WIDTH
    #endif
    #if defined (CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_HEIGHT)
        #define MMI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_HEIGHT     CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_HEIGHT
    #endif
    #if defined (CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_HORIZONTAL_GAP)
        #define MMI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_HORIZONTAL_GAP     CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_HORIZONTAL_GAP
    #endif
    #if defined (CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_VERTICAL_GAP)
        #define MMI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_VERTICAL_GAP     CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_VERTICAL_GAP
    #endif
    #if defined (CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_X)
        #define MMI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_X     CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_X
    #endif
    #if defined (CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_Y)
        #define MMI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_Y     CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_Y
    #endif
    #if defined (CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_WIDTH)
        #define MMI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_WIDTH     CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_WIDTH
    #endif
    #if defined (CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_HEIGHT)
        #define MMI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_HEIGHT     CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_HEIGHT
    #endif
    #if defined (CFG_UI_IDLE_STATIC_CALENDAR_WEEK_TITLE_Y)
        #define MMI_IDLE_STATIC_CALENDAR_WEEK_TITLE_Y     CFG_UI_IDLE_STATIC_CALENDAR_WEEK_TITLE_Y
    #endif
    #if defined (CFG_UI_IDLE_STATIC_CALENDAR_WEEK_TITLE_HEIGHT)
        #define MMI_IDLE_STATIC_CALENDAR_WEEK_TITLE_HEIGHT      CFG_UI_IDLE_STATIC_CALENDAR_WEEK_TITLE_HEIGHT
    #endif
    #if defined (CFG_UI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_X)
        #define MMI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_X     CFG_UI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_X
    #endif
    #if defined (CFG_UI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_Y)
        #define MMI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_Y     CFG_UI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_Y
    #endif
    #if defined (CFG_UI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_WIDTH)
        #define MMI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_WIDTH     CFG_UI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_WIDTH
    #endif
    #if defined (CFG_UI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_HEIGHT)
        #define MMI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_HEIGHT     CFG_UI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_HEIGHT
    #endif
    #if defined (CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_X)
        #define MMI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_X     CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_X
    #endif
    #if defined (CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_Y)
        #define MMI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_Y     CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_Y
    #endif
    #if defined (CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_WIDTH)
        #define MMI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_WIDTH     CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_WIDTH
    #endif
    #if defined (CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_HEIGHT)
        #define MMI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_HEIGHT     CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_HEIGHT
    #endif
    
    #ifndef MMI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_X
        #error "Please define MMI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_X in wgui.h!!"
    #endif
    #ifndef MMI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_HEIGHT
        #error "Please define MMI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_HEIGHT in wgui.h!!"
    #endif
#endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */

#if defined(__MMI_SEARCH_WEB__)
    #define MMI_IDLE_STATIC_SEARCH_START_Y                CFG_UI_IDLE_STATIC_SEARCH_START_Y
    #define MMI_IDLE_STATIC_SEARCH_IMAGE_STRING_GAP       CFG_UI_IDLE_STATIC_SEARCH_IMAGE_STRING_GAP 
#endif /* __MMI_SEARCH_WEB__ */
/*
** Extern Global Variable
*/
extern S32 MMI_status_bar_height;
extern S32 MMI_content_x;
extern S32 MMI_content_y;
extern S32 MMI_content_width;
extern S32 MMI_content_height;
extern S32 MMI_pop_up_dialog_x;
extern S32 MMI_pop_up_dialog_y;
extern S32 MMI_pop_up_dialog_width;
extern S32 MMI_pop_up_dialog_height;
extern S32 MMI_pop_up_dialog_full_height;

/*
** Extern Global Function
*/

extern void wgui_init(void);
extern void MMI_dummy_function(void);
extern void register_keyboard_key_handler(void (*f)(S32 vkey_code,S32 key_state));
extern void register_keyboard_input_handler(void (*f)(S32 vkey_code));
extern void register_keyboard_global_key_handler(void (*f)(S32 vkey_code,S32 key_state));
extern void register_keyboard_global_input_handler(void (*f)(S32 vkey_code));
extern void clear_keyboard_key_handler(void);
extern void clear_keyboard_input_handler(void);
extern void clear_keyboard_global_key_handler(void);
extern void clear_keyboard_global_input_handler(void);

/*  key handling wrappers   */
extern void clear_key_handlers(void);
extern void clear_category_screen_key_handlers(void);

extern void register_key_input_handler(void (*f)(MMI_key_code_type key_code,MMI_key_event_type key_event));
extern void register_key_up_handler(void (*f)(MMI_key_code_type key_code));
extern void register_key_down_handler(void (*f)(MMI_key_code_type key_code));
extern void register_MMI_key_input_handler(void);
extern void register_MMI_key_input_extend_handler(void);

extern void clear_key_input_handler(void);
extern void clear_key_down_handler(void);
extern void clear_key_up_handler(void);
extern void clear_MMI_key_input_handler(void);

extern void MMI_key_input_handler(MMI_key_code_type key_code,MMI_key_event_type key_event);
extern MMI_BOOL mmi_frm_is_in_ui_common_exit_procedure(void);

#if defined(CFG_UI_LIST_GRID_LINE) && (CFG_UI_LIST_GRID_LINE == __ON__) && defined(__MMI_TOUCH_SCREEN__)
#define __MMI_UI_LIST_GRID_LINE__
#endif 

#define __MMI_UI_LIST_SKIP_DISABLED__

#if defined(__MMI_UM_CONVERSATION_BOX_ENHANCE__) || defined(__SOCIAL_NETWORK_SUPPORT__)
#define __MMI_UI_LIST_SCROLL_BY_PIXEL__
#define __MMI_UI_LIST_SUPPORT_UNEQUAL_HEIGHT_ITEM__
#endif

#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
#undef  MMI_MAX_MENUITEMS_IN_CONTENT
#define MMI_MAX_MENUITEMS_IN_CONTENT                        (MMI_CONTENT_HEIGHT/MMI_MENUITEM_HEIGHT + 3)/* both first and last item can be partial, and one more for safety. */
#endif

#if defined(__SOCIAL_NETWORK_SUPPORT__)

extern S32 get_status_bar_height(void);
extern S32 get_title_height(void);
extern S32 get_menuitem_height(void);
extern S32 get_multirow_menuitem_height(void);
extern S32 get_icontext_menuitem_icon_x(void);
extern S32 get_text_menuitem_text_x(void);
extern S32 get_menuitem_x2_gap(void);
extern S32 get_menuitem_text_right_gap(void);
extern S32 get_icontext_menuitem_height(void);
extern S32 get_content_x(void);
extern S32 get_content_height(void);
extern S32 get_content_width(void);
extern S32 get_content_height_with_h_bar(void);
extern S32 get_content_x_with_h_tab(void);
extern S32 get_content_y_with_h_tab(void);
extern S32 get_horzontal_tab_bar_hint_area_height(void);
extern S32 get_horizontal_tab_bar_tab_area_height(void);
extern S32 get_horizontal_tab_bar_y(void);
extern S32 get_icon_bar_height(void);
extern S32 get_button_bar_height(void);
extern U16 get_sns_more_string_id(void);
extern U16 get_global_loading_id(void);

#endif
#endif /* __WGUI_H__ */


