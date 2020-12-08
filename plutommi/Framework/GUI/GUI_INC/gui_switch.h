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
 *   gui_config_switch.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   GUI Configuration
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/


#ifndef __GUI_SWITCH_H__
#define __GUI_SWITCH_H__

#include "MMI_features.h"


/* this configuration can apply specific style on submenu / common category screen,
 * if it is OFF, the screen will have default style (base_control_set),
 * if it is ON, the screen can apply a specific & custormized style, that is CFG_UI_SUBMENU_SHOW_STATUS_ICON, CFG_UI_SUBMENU_USE_THICK_TITLE */
#if defined(__MMI_MAINLCD_320X240__) && !defined(__MMI_FTE_SUPPORT__)
#define CFG_UI_SUBMENU_USE_SPECIFIC                     (__ON__)
#define CFG_UI_COMMON_USE_SPECIFIC                      (__ON__)
#else
#define CFG_UI_SUBMENU_USE_SPECIFIC                     (__OFF__)
#define CFG_UI_COMMON_USE_SPECIFIC                      (__OFF__)
#endif

/*
 * CFG_UI_MAINMENU_SHOW_STATUS_ICON - Show status icon above main menu
 *
 * CFG_UI_SUBMENU_SHOW_STATUS_ICON - Show status icon above submenu
 * 
 * CFG_UI_COMMON_SHOW_STATUS_ICON - Show status icon above common screen
 * 
 * CFG_UI_DEFAULT_SHOW_STATUS_ICON - show status icon above default screen(word clock, calendar etc.)
*/
#if defined(__MMI_MAINLCD_96X64__) ||defined(__MMI_MAINLCD_128X128__) ||defined(__MMI_MAINLCD_128X36__) || defined(__MMI_MAINLCD_128X160__) || (defined(__MMI_MAINLCD_320X240__) && !defined(__MMI_FTE_SUPPORT__)) || defined(__MMI_MAINLCD_128X64__)
    #define CFG_UI_MAINMENU_SHOW_STATUS_ICON            (__OFF__)
    #define CFG_UI_SUBMENU_SHOW_STATUS_ICON             (__OFF__)
    #define CFG_UI_COMMON_SHOW_STATUS_ICON              (__OFF__)
    #define CFG_UI_DEFAULT_SHOW_STATUS_ICON             (__OFF__)
#else
    #define CFG_UI_MAINMENU_SHOW_STATUS_ICON            (__ON__)
    #define CFG_UI_SUBMENU_SHOW_STATUS_ICON             (__ON__)
    #define CFG_UI_COMMON_SHOW_STATUS_ICON              (__ON__)
    #define CFG_UI_DEFAULT_SHOW_STATUS_ICON             (__ON__)
#endif

/* Editor title layout */
// SLIM_96_64_SLIM
#if (defined(__MMI_MAINLCD_96X64__)) ||(defined(__MMI_MAINLCD_320X240__)) || ((defined(__MMI_MAINLCD_240X320__)) && (defined(__MMI_FTE_SUPPORT__)))
    #define CFG_UI_EDITOR_SHOW_TITLE                    (__OFF__)
#else  
    #define CFG_UI_EDITOR_SHOW_TITLE                    (__ON__)
#endif

#if defined(__MMI_MAINLCD_320X240__) && !defined(__MMI_FTE_SUPPORT__)
    #define CFG_UI_SHOW_STATUS_ICON_IN_TITLE            (__ON__)
#else
    #define CFG_UI_SHOW_STATUS_ICON_IN_TITLE            (__OFF__)
#endif


/*
 * CFG_UI_MAINMENU_USE_THICK_TITLE - show thick title above main menu
 *
 * CFG_UI_SUBMENU_USE_THICK_TITLE - Show thick title above submenu
 * 
 * CFG_UI_COMMON_USE_THICK_TITLE - Show thick title above common screen
 * 
 * CFG_UI_DEFAULT_USE_THICK_TITLE - Show thick title above default screen(word clock, calendar etc.)
*/
#define CFG_UI_MAINMENU_USE_THICK_TITLE           (__OFF__)
#define CFG_UI_SUBMENU_USE_THICK_TITLE           (__OFF__)
#define CFG_UI_COMMON_USE_THICK_TITLE            (__OFF__)
#define CFG_UI_DEFAULT_USE_THICK_TITLE            (__OFF__)

/* status icons have been drawn from bottom baseline or from center baseline */
#if defined(__MMI_MAINLCD_320X240__)||defined(__MMI_FWUI_SLIM__)
    #define CFG_UI_STATUS_ICONS_DRAW_FROM_BOTTOM_BASELINE      (__OFF__)
#else
    #define CFG_UI_STATUS_ICONS_DRAW_FROM_BOTTOM_BASELINE      (__ON__)
#endif

/* Calling screen */
#if (defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)) && !defined(__MMI_FTE_SUPPORT__)
    #define WGUI_CATCALL_STYLE_2
    #define CFG_WGUI_CATCALL_STYLE_2_WITH_BUTTON                (__OFF__)
#endif /* defined(__MMI_MAINLCD_320X480__) && !defined(__MMI_FTE_SUPPORT__) */


#if defined(__MMI_FTE_SUPPORT__)

#if defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)
/* maximun number of buttons of iconbar in call related screens */
#define WGUI_CATCALL_INCALL_ICONBAR_MAX_NUM    (4)
#else /* defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) */
/* maximun number of buttons of iconbar in call related screens */
#define WGUI_CATCALL_INCALL_ICONBAR_MAX_NUM    (2)
#endif /* defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) */


#if defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)
/* maximun number of buttons of iconbar in call related screens */
#define WGUI_CATCALL_ICONBAR_MAX_NUM    (4)
#else /* defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) */
/* maximun number of buttons of iconbar in call related screens */
#define WGUI_CATCALL_ICONBAR_MAX_NUM    (2)
#endif /* defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) */
#endif /* defined(__MMI_FTE_SUPPORT__) */

#if defined(__MMI_FTE_SUPPORT__)

/* coordinate */
#ifdef __MMI_TOUCH_SCREEN__
#define WGUI_CATCALL_FTE_POPUP_X            (0)
#define WGUI_CATCALL_FTE_POPUP_Y            (MMI_status_bar_height)
#define WGUI_CATCALL_FTE_POPUP_W            (UI_device_width)
#define WGUI_CATCALL_FTE_POPUP_H            (UI_device_height - MMI_status_bar_height - MMI_softkey_height)
#if defined(__MMI_MAINLCD_320X480__)
#define WGUI_CATCALL_FTE_IMG_X              (19)//(20)
#define WGUI_CATCALL_FTE_IMG_Y              (37)//(50)
#define WGUI_CATCALL_FTE_IMG_W              (283)//(280)
#define WGUI_CATCALL_FTE_IMG_H              (161)//(210)
#elif defined(__MMI_MAINLCD_240X400__)
#define WGUI_CATCALL_FTE_IMG_X              (15)
#define WGUI_CATCALL_FTE_IMG_Y              (45)
#define WGUI_CATCALL_FTE_IMG_W              (210)
#define WGUI_CATCALL_FTE_IMG_H              (150)
#elif defined(__MMI_MAINLCD_320X240__)
#define WGUI_CATCALL_FTE_IMG_X              (14)
#define WGUI_CATCALL_FTE_IMG_Y              (30)
#define WGUI_CATCALL_FTE_IMG_W              (206)
#define WGUI_CATCALL_FTE_IMG_H              (108)
#else
#define WGUI_CATCALL_FTE_IMG_X              (15)
#define WGUI_CATCALL_FTE_IMG_Y              (45)
#define WGUI_CATCALL_FTE_IMG_W              (210)
#define WGUI_CATCALL_FTE_IMG_H              (85)
#endif
#else /* __MMI_TOUCH_SCREEN__ */
#if defined(__MMI_MAINLCD_320X480__)
#define WGUI_CATCALL_FTE_POPUP_X            (0)
#define WGUI_CATCALL_FTE_POPUP_Y            (60)
#define WGUI_CATCALL_FTE_POPUP_W            (UI_device_width)
#define WGUI_CATCALL_FTE_POPUP_H            (300)
#define WGUI_CATCALL_FTE_IMG_X              (19)//(20)
#define WGUI_CATCALL_FTE_IMG_Y              (77)//(50)
#define WGUI_CATCALL_FTE_IMG_W              (283)//(280)
#define WGUI_CATCALL_FTE_IMG_H              (161)//(210)
#elif defined(__MMI_MAINLCD_240X400__)
#define WGUI_CATCALL_FTE_POPUP_X            (0)
#define WGUI_CATCALL_FTE_POPUP_Y            (MMI_status_bar_height)
#define WGUI_CATCALL_FTE_POPUP_W            (UI_device_width)
#define WGUI_CATCALL_FTE_POPUP_H            (UI_device_height - MMI_status_bar_height - MMI_softkey_height)
#define WGUI_CATCALL_FTE_IMG_X              (15)
#define WGUI_CATCALL_FTE_IMG_Y              (45)
#define WGUI_CATCALL_FTE_IMG_W              (210)
#define WGUI_CATCALL_FTE_IMG_H              (150)
#else
#define WGUI_CATCALL_FTE_POPUP_X            (0)
#define WGUI_CATCALL_FTE_POPUP_Y            (MMI_status_bar_height)
#define WGUI_CATCALL_FTE_POPUP_W            (UI_device_width)
#define WGUI_CATCALL_FTE_POPUP_H            (UI_device_height - MMI_status_bar_height - MMI_softkey_height)
#define WGUI_CATCALL_FTE_IMG_X              (15)
#define WGUI_CATCALL_FTE_IMG_Y              (45)
#define WGUI_CATCALL_FTE_IMG_W              (210)
#define WGUI_CATCALL_FTE_IMG_H              (85)
#endif
#endif /* __MMI_TOUCH_SCREEN__ */

#define WGUI_CATCALL_FTE_STR1_X             (WGUI_CATCALL_FTE_IMG_X)
#define WGUI_CATCALL_FTE_STR1_Y             (WGUI_CATCALL_FTE_IMG_Y + WGUI_CATCALL_FTE_IMG_H + 10)
#define WGUI_CATCALL_FTE_STR1_W             (WGUI_CATCALL_FTE_IMG_W)
#define WGUI_CATCALL_FTE_STR1_H             (26)
#define WGUI_CATCALL_FTE_STR2_X             (WGUI_CATCALL_FTE_STR1_X)
#define WGUI_CATCALL_FTE_STR2_Y             (WGUI_CATCALL_FTE_STR1_Y + WGUI_CATCALL_FTE_STR1_H + 1)
#define WGUI_CATCALL_FTE_STR2_W             (WGUI_CATCALL_FTE_STR1_W)
#define WGUI_CATCALL_FTE_STR2_H             (WGUI_CATCALL_FTE_STR1_H)
#if defined(__MMI_MAINLCD_320X240__)
#define WGUI_CATCALL_FTE_ICONBAR_X          (WGUI_CATCALL_FTE_IMG_X + WGUI_CATCALL_FTE_IMG_W + 9)
#define WGUI_CATCALL_FTE_ICONBAR_Y          (WGUI_CATCALL_FTE_IMG_Y)
#define WGUI_CATCALL_FTE_ICONBAR_W          (77)
#else /* __MMI_MAINLCD_320X240__ */
#define WGUI_CATCALL_FTE_ICONBAR_X          (WGUI_CATCALL_FTE_IMG_X)
#define WGUI_CATCALL_FTE_ICONBAR_Y          (WGUI_CATCALL_FTE_STR2_Y + WGUI_CATCALL_FTE_STR2_H + 10)
#define WGUI_CATCALL_FTE_ICONBAR_W          (WGUI_CATCALL_FTE_IMG_W)
#endif /* __MMI_MAINLCD_320X240__ */
#if defined(__MMI_MAINLCD_320X240__)
#define WGUI_CATCALL_FTE_ICONBAR_GAP		(6)
#else /* __MMI_MAINLCD_320X240__ */
#define WGUI_CATCALL_FTE_ICONBAR_GAP        (3)
#endif /* __MMI_MAINLCD_320X240__ */
#if defined(__MMI_MAINLCD_320X480__)
#define WGUI_CATCALL_FTE_TEXT_GAP_X        (12)
#define WGUI_CATCALL_FTE_TEXT_GAP_Y        (12)
#elif defined(__MMI_MAINLCD_320X240__)
#define WGUI_CATCALL_FTE_TEXT_GAP_X		   (10)
#define WGUI_CATCALL_FTE_TEXT_GAP_Y		   (5)
#else
#define WGUI_CATCALL_FTE_TEXT_GAP_X        (10)
#define WGUI_CATCALL_FTE_TEXT_GAP_Y        (10)
#endif


#if defined(__MMI_MAINLCD_320X480__)
#define WGUI_CATCALL_FTE_ICONBAR_H          (75)
#define WGUI_CATCALL_FTE_ICONBAR_2LINE_H    (75 * 2 + WGUI_CATCALL_FTE_ICONBAR_GAP)
#elif defined(__MMI_MAINLCD_320X240__)
#define WGUI_CATCALL_FTE_ICONBAR_H			(49)
#define WGUI_CATCALL_FTE_ICONBAR_2LINE_H	(40)
#else
#define WGUI_CATCALL_FTE_ICONBAR_H          (65)
#define WGUI_CATCALL_FTE_ICONBAR_2LINE_H    (65 * 2 + WGUI_CATCALL_FTE_ICONBAR_GAP)

#endif

#if defined(__MMI_MAINLCD_320X480__)
#define WGUI_CATCALL_FTE_ICONBAR_UNLOCK_W   (58)
#define WGUI_CATCALL_FTE_ICONBAR_UNLOCK_H   (38)
#else /*__MMI_MAINLCD_320X480__*/
#define WGUI_CATCALL_FTE_ICONBAR_UNLOCK_W   (50)
#define WGUI_CATCALL_FTE_ICONBAR_UNLOCK_H   (32)
#endif /*__MMI_MAINLCD_320X480__*/

#endif /* __MMI_FTE_SUPPORT__ */






#ifndef __MMI_FULL_DIALSCREEN_FEATURE__ /* __MMI_FULL_DIALSCREEN_FEATURE__ is a kind of dialing box, it's position is fullscreen' */
    #if defined(__MMI_FTE_SUPPORT__) && (defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
        #define MMI_DIALING_KEYPAD_COLOMNS                      (3)
        #define MMI_DIALING_KEYPAD_ROWS                         (4)
        #define MMI_DIALING_KEYPAD_LAYER_WIDTH                  (320)
        #define MMI_DIALING_KEYPAD_LAYER_HEIGHT                 (480)
        #define MMI_DIALING_KEYPAD_LAYER_X                      (0)
        #define MMI_DIALING_KEYPAD_LAYER_Y                      (0)
        #define MMI_DIALING_KEYPAD_X                            (7)
        #define MMI_DIALING_KEYPAD_Y                            (140)
        #define MMI_DIALING_KEYPAD_WIDTH                        (307)
        #define MMI_DIALING_KEYPAD_HEIGHT                       (282)
        #define MMI_DIALING_KEY_WIDTH                           (101)
        #define MMI_DIALING_KEY_HEIGHT                          (56)
        #define MMI_DIALING_KEY_HORIZONTAL_GAP                  (2)
        #define MMI_DIALING_KEY_VERTICAL_GAP                    (0)
        #define MMI_DIALING_BOX_X                               (12)
        #define MMI_DIALING_BOX_Y                               (35)
        #define MMI_DIALING_BOX_WIDTH                           (297)
        #define MMI_DIALING_BOX_HEIGHT                          (92)
         #if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
            #if defined (__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__) \
				&& (!(defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)))
				#define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (3)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS				(1)
                #define MMI_DIALING_KEYPAD_FUNC_X					(7)
                #define MMI_DIALING_KEYPAD_FUNC_Y					(366)
				#define MMI_DIALING_FUNC_KEY_WIDTH                  (101)
                #define MMI_DIALING_FUNC_KEY_HEIGHT 				(58)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP 		(2)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP			(0)
            #else
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (2)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (1)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (7)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (366)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (101)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (58)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (2)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (0)
            #endif
        #endif
    #elif defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_240X400__)
        #define MMI_DIALING_KEYPAD_COLOMNS                      (3)
        #define MMI_DIALING_KEYPAD_ROWS                         (4)
        #define MMI_DIALING_KEYPAD_LAYER_WIDTH                  (240)
        #define MMI_DIALING_KEYPAD_LAYER_HEIGHT                 (400)
        #define MMI_DIALING_KEYPAD_LAYER_X                      (0)
        #define MMI_DIALING_KEYPAD_LAYER_Y                      (0)
        #define MMI_DIALING_KEYPAD_X                            (4)
        #define MMI_DIALING_KEYPAD_Y                            (124)
        #define MMI_DIALING_KEYPAD_WIDTH                        (232)
        #define MMI_DIALING_KEYPAD_HEIGHT                       (226)
        #define MMI_DIALING_KEY_WIDTH                           (76)
        #define MMI_DIALING_KEY_HEIGHT                          (45)
        #define MMI_DIALING_KEY_HORIZONTAL_GAP                  (2)
        #define MMI_DIALING_KEY_VERTICAL_GAP                    (1)
        #define MMI_DIALING_BOX_X                               (6)
        #define MMI_DIALING_BOX_Y                               (27)
        #define MMI_DIALING_BOX_WIDTH                           (228)
        #define MMI_DIALING_BOX_HEIGHT                          (91)
         #if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
            #if defined (__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__) \
				&& (!(defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)))
				#define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (3)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (1)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (4)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (308)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (76)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (45)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (2)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (0)
            #else
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (2)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (1)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (4)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (308)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (76)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (45)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (2)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (0)
            #endif
        #endif
    #elif defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_240X320__)
        #define MMI_DIALING_KEYPAD_COLOMNS                      (3)
        #define MMI_DIALING_KEYPAD_ROWS                         (4)
        #define MMI_DIALING_KEYPAD_LAYER_WIDTH                  (240)
        #define MMI_DIALING_KEYPAD_LAYER_HEIGHT                 (320)
        #define MMI_DIALING_KEYPAD_LAYER_X                      (0)
        #define MMI_DIALING_KEYPAD_LAYER_Y                      (0)
        #define MMI_DIALING_KEYPAD_X                            (4)
        #define MMI_DIALING_KEYPAD_Y                            (99)
        #define MMI_DIALING_KEYPAD_WIDTH                        (234)
        #define MMI_DIALING_KEYPAD_HEIGHT                       (180)
        #define MMI_DIALING_KEY_WIDTH                           (76)
        #define MMI_DIALING_KEY_HEIGHT                          (36)
        #define MMI_DIALING_KEY_HORIZONTAL_GAP                  (2)
        #define MMI_DIALING_KEY_VERTICAL_GAP                    (0)
        #define MMI_DIALING_BOX_X                               (6)
        #define MMI_DIALING_BOX_Y                               (21)
        #define MMI_DIALING_BOX_WIDTH                           (229)
        #define MMI_DIALING_BOX_HEIGHT                          (75)
         #if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
            #if defined (__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__) \
				&& (!(defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)))
				#define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (3)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (1)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (4)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (243)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (76)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (36)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (2)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (0)
            #else
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (2)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (1)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (4)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (243)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (76)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (36)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (2)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (0)
            #endif
        #endif
	#elif defined (__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X240__)
        #define MMI_DIALING_KEYPAD_COLOMNS						(4)
        #define MMI_DIALING_KEYPAD_ROWS 						(3)
        #define MMI_DIALING_KEYPAD_LAYER_WIDTH					(320)
        #define MMI_DIALING_KEYPAD_LAYER_HEIGHT 				(240)
        #define MMI_DIALING_KEYPAD_LAYER_X						(0)
        #define MMI_DIALING_KEYPAD_LAYER_Y						(0)
        #define MMI_DIALING_KEYPAD_X							(6)
        #define MMI_DIALING_KEYPAD_Y							(101)
        #define MMI_DIALING_KEYPAD_WIDTH						(310)
        #define MMI_DIALING_KEYPAD_HEIGHT						(100)
        #define MMI_DIALING_KEY_WIDTH							(60)
        #define MMI_DIALING_KEY_HEIGHT							(32)
        #define MMI_DIALING_KEY_HORIZONTAL_GAP					(2)
        #define MMI_DIALING_KEY_VERTICAL_GAP					(2)
        #define MMI_DIALING_BOX_X								(0)
        #define MMI_DIALING_BOX_Y								(18)
        #define MMI_DIALING_BOX_WIDTH							(320)
        #define MMI_DIALING_BOX_HEIGHT							(73)
        #if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
            #if defined (__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__) \
				&& (!(defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)))
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS 			(1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS				(3)
                #define MMI_DIALING_KEYPAD_FUNC_X					(254)
                #define MMI_DIALING_KEYPAD_FUNC_Y					(101)
                #define MMI_DIALING_FUNC_KEY_WIDTH					(60)
                #define MMI_DIALING_FUNC_KEY_HEIGHT 				(32)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP 		(2)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP			(2)
            #else
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS 			(1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS				(2)
                #define MMI_DIALING_KEYPAD_FUNC_X					(254)
                #define MMI_DIALING_KEYPAD_FUNC_Y					(101)
                #define MMI_DIALING_FUNC_KEY_WIDTH					(60)
                #define MMI_DIALING_FUNC_KEY_HEIGHT 				(49)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP 		(2)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP			(2)
            #endif
        #endif
    #elif defined (__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
        #define MMI_DIALING_KEYPAD_COLOMNS                      (3)
        #define MMI_DIALING_KEYPAD_ROWS                         (4)
        #define MMI_DIALING_KEYPAD_LAYER_WIDTH                  (320)
        #define MMI_DIALING_KEYPAD_LAYER_HEIGHT                 (480)
        #define MMI_DIALING_KEYPAD_LAYER_X                      (0)
        #define MMI_DIALING_KEYPAD_LAYER_Y                      (0)
        #define MMI_DIALING_KEYPAD_X                            (14)
        #define MMI_DIALING_KEYPAD_Y                            (135)
        #define MMI_DIALING_KEYPAD_WIDTH                        (320)
        #define MMI_DIALING_KEYPAD_HEIGHT                       (480)
        #define MMI_DIALING_KEY_WIDTH                           (96)
        #define MMI_DIALING_KEY_HEIGHT                          (60)
        #define MMI_DIALING_KEY_HORIZONTAL_GAP                  (3)
        #define MMI_DIALING_KEY_VERTICAL_GAP                    (1)
        #define MMI_DIALING_BOX_X                               (30)
        #define MMI_DIALING_BOX_Y                               (45)
        #define MMI_DIALING_BOX_WIDTH                           (260)
        #define MMI_DIALING_BOX_HEIGHT                          (75)
        /* For function key on idlescreen */
        #if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
            #if defined (__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__)
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (3)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (1)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (14)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (380)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (96)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (60)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (3)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (0)
            #else
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (2)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (1)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (45)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (380)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (112)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (65)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (10)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (0)
            #endif
        #endif
    #elif defined (__MMI_MAINLCD_240X400__)
        #define MMI_DIALING_KEYPAD_COLOMNS                      (3)
        #define MMI_DIALING_KEYPAD_ROWS                         (4)
        #define MMI_DIALING_KEYPAD_LAYER_WIDTH                  (240)
        #define MMI_DIALING_KEYPAD_LAYER_HEIGHT                 (400)
        #define MMI_DIALING_KEYPAD_LAYER_X                      (0)
        #define MMI_DIALING_KEYPAD_LAYER_Y                      (0)
        #define MMI_DIALING_KEYPAD_X                            (2)
        #define MMI_DIALING_KEYPAD_Y                            (115)
        #define MMI_DIALING_KEYPAD_WIDTH                        (240)
        #define MMI_DIALING_KEYPAD_HEIGHT                       (400)
        #define MMI_DIALING_KEY_WIDTH                           (77)
        #define MMI_DIALING_KEY_HEIGHT                          (49)
        #define MMI_DIALING_KEY_HORIZONTAL_GAP                  (2)
        #define MMI_DIALING_KEY_VERTICAL_GAP                    (2)
        #define MMI_DIALING_BOX_X                               (19)
        #define MMI_DIALING_BOX_Y                               (37)
        #define MMI_DIALING_BOX_WIDTH                           (202)
        #define MMI_DIALING_BOX_HEIGHT                          (64)
        /* For function key on idlescreen */
        #if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
            #if defined (__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__)
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (3)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (1)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (2)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (319)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (77)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (49)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (2)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (0)
            #else
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (2)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (1)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (9)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (321)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (108)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (47)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (6)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (0)
            #endif
        #endif
    #elif defined (__MMI_MAINLCD_320X240__)
        #define MMI_DIALING_KEYPAD_COLOMNS                      (3)
        #define MMI_DIALING_KEYPAD_ROWS                         (4)
        #define MMI_DIALING_KEYPAD_LAYER_WIDTH                  (265)
        #define MMI_DIALING_KEYPAD_LAYER_HEIGHT                 (141)
        #define MMI_DIALING_KEYPAD_LAYER_X                      ((MAIN_LCD_DEVICE_WIDTH-MMI_DIALING_KEYPAD_LAYER_WIDTH)>>1)
        #define MMI_DIALING_KEYPAD_LAYER_Y                      (((MAIN_LCD_DEVICE_HEIGHT-MMI_DIALING_KEYPAD_LAYER_HEIGHT)>>1)+20)
        #define MMI_DIALING_KEYPAD_X                            (13)
        #define MMI_DIALING_KEYPAD_Y                            (9)
        #define MMI_DIALING_KEYPAD_WIDTH                        (265)
        #define MMI_DIALING_KEYPAD_HEIGHT                       (141)
        #define MMI_DIALING_KEY_WIDTH                           (59)
        #define MMI_DIALING_KEY_HEIGHT                          (26)
        #define MMI_DIALING_KEY_HORIZONTAL_GAP                  (4)
        #define MMI_DIALING_KEY_VERTICAL_GAP                    (5)
        #define MMI_DIALING_BOX_HEIGHT                          (47)
        /* For function key on idlescreen */
        #if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
            #ifdef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (3)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (218)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (14)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (32)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (33)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (8)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (8)
            #else /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (2)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (216)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (22)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (32)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (33)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (18)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (28)            
            #endif /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
        #endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */
    #elif defined (__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
        #define MMI_DIALING_KEYPAD_COLOMNS                      (3)
        #define MMI_DIALING_KEYPAD_ROWS                         (4)
        #define MMI_DIALING_KEYPAD_LAYER_WIDTH                  (265)
        #define MMI_DIALING_KEYPAD_LAYER_HEIGHT                 (141)
        #define MMI_DIALING_KEYPAD_LAYER_X                      ((MAIN_LCD_DEVICE_WIDTH-MMI_DIALING_KEYPAD_LAYER_WIDTH)>>1)
        #define MMI_DIALING_KEYPAD_LAYER_Y                      (((MAIN_LCD_DEVICE_HEIGHT-MMI_DIALING_KEYPAD_LAYER_HEIGHT)>>1)+20)
        #define MMI_DIALING_KEYPAD_X                            (13)
        #define MMI_DIALING_KEYPAD_Y                            (9)
        #define MMI_DIALING_KEYPAD_WIDTH                        (265)
        #define MMI_DIALING_KEYPAD_HEIGHT                       (141)
        #define MMI_DIALING_KEY_WIDTH                           (59)
        #define MMI_DIALING_KEY_HEIGHT                          (26)
        #define MMI_DIALING_KEY_HORIZONTAL_GAP                  (4)
        #define MMI_DIALING_KEY_VERTICAL_GAP                    (5)
        #define MMI_DIALING_BOX_HEIGHT                          (47)
        /* For function key on idlescreen */
        #if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
            #ifdef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (3)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (218)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (14)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (32)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (33)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (8)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (8)
            #else /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (2)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (216)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (22)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (32)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (33)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (18)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (28)            
            #endif /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
        #endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */        
    #elif defined (__MMI_MAINLCD_240X320__)
        #define MMI_DIALING_KEYPAD_COLOMNS                      (3)
        #define MMI_DIALING_KEYPAD_ROWS                         (4)
        #define MMI_DIALING_KEYPAD_LAYER_WIDTH                  (218)
        #define MMI_DIALING_KEYPAD_LAYER_HEIGHT                 (177)
        #define MMI_DIALING_KEYPAD_LAYER_X                      ((MAIN_LCD_DEVICE_WIDTH-MMI_DIALING_KEYPAD_LAYER_WIDTH)>>1)
        #define MMI_DIALING_KEYPAD_LAYER_Y                      (((MAIN_LCD_DEVICE_HEIGHT-MMI_DIALING_KEYPAD_LAYER_HEIGHT)>>1)+20)
        #define MMI_DIALING_KEYPAD_X                            (14)
        #define MMI_DIALING_KEYPAD_Y                            (5)
        #define MMI_DIALING_KEYPAD_WIDTH                        (218)
        #define MMI_DIALING_KEYPAD_HEIGHT                       (177)
        #define MMI_DIALING_KEY_WIDTH                           (37)
        #define MMI_DIALING_KEY_HEIGHT                          (37)
        #define MMI_DIALING_KEY_HORIZONTAL_GAP                  (12)
        #define MMI_DIALING_KEY_VERTICAL_GAP                    (5)
        #define MMI_DIALING_BOX_X                               (0)
        #define MMI_DIALING_BOX_Y                               (0)
        #define MMI_DIALING_BOX_WIDTH                           (0)
        #define MMI_DIALING_BOX_HEIGHT                          (66)
        /* For function key on idlescreen */
        #if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
            #ifdef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (3)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (165)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (15)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (37)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (37)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (0)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (16)
            #else   /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */    
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (2)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (165)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (33)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (37)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (37)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (12)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (27)
            #endif   /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */    
        #endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */
    #elif defined (__MMI_MAINLCD_176X220__)
        /* For function key on idlescreen */
        #if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
            #define MMI_DIALING_KEYPAD_COLOMNS                      (3)
            #define MMI_DIALING_KEYPAD_ROWS                         (4)
            #define MMI_DIALING_KEYPAD_LAYER_WIDTH                  (176)
            #define MMI_DIALING_KEYPAD_LAYER_HEIGHT                 (200)
            #define MMI_DIALING_KEYPAD_LAYER_X                      (0)
            #define MMI_DIALING_KEYPAD_LAYER_Y                      (54)
            #define MMI_DIALING_KEYPAD_X                            (7)
            #define MMI_DIALING_KEYPAD_Y                            (11)
            #define MMI_DIALING_KEYPAD_WIDTH                        (176)
            #define MMI_DIALING_KEYPAD_HEIGHT                       (152)
            #define MMI_DIALING_KEY_WIDTH                           (40)
            #define MMI_DIALING_KEY_HEIGHT                          (31)
            #define MMI_DIALING_KEY_HORIZONTAL_GAP                  (3)
            #define MMI_DIALING_KEY_VERTICAL_GAP                    (3)
            #define MMI_DIALING_BOX_X                               (0)
            #define MMI_DIALING_BOX_Y                               (0)    
            #define MMI_DIALING_BOX_WIDTH                           (0)
            #define MMI_DIALING_BOX_HEIGHT                          (33)
            #ifdef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (3)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (139)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (13)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (31)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (39)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (0)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (4)
            #else   /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */        
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (2)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (165)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (33)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (37)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (37)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (12)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (27)
            #endif   /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */        
        #else /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ */     
            #define MMI_DIALING_KEYPAD_COLOMNS                      (3)
            #define MMI_DIALING_KEYPAD_ROWS                         (4)
            #define MMI_DIALING_KEYPAD_LAYER_WIDTH                  (176)
            #define MMI_DIALING_KEYPAD_LAYER_HEIGHT                 (200)
            #define MMI_DIALING_KEYPAD_LAYER_X                      (0)
            #define MMI_DIALING_KEYPAD_LAYER_Y                      (50)
            #define MMI_DIALING_KEYPAD_X                            (16)
            #define MMI_DIALING_KEYPAD_Y                            (7)
            #define MMI_DIALING_KEYPAD_WIDTH                        (145)
            #define MMI_DIALING_KEYPAD_HEIGHT                       (137)
            #define MMI_DIALING_KEY_WIDTH                           (39)
            #define MMI_DIALING_KEY_HEIGHT                          (31)
            #define MMI_DIALING_KEY_HORIZONTAL_GAP                  (14)
            #define MMI_DIALING_KEY_VERTICAL_GAP                    (5)
            #define MMI_DIALING_BOX_X                               (0)
            #define MMI_DIALING_BOX_Y                               (0)    
            #define MMI_DIALING_BOX_WIDTH                           (0)
            #define MMI_DIALING_BOX_HEIGHT                          (33)
        #endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ */
    #else /* LCD szie */
        #if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
            #define MMI_DIALING_KEYPAD_COLOMNS                      (3)
            #define MMI_DIALING_KEYPAD_ROWS                         (4)
            #define MMI_DIALING_KEYPAD_LAYER_WIDTH                  (128)
            #define MMI_DIALING_KEYPAD_LAYER_HEIGHT                 (160)
            #define MMI_DIALING_KEYPAD_LAYER_X                      (0)
            #define MMI_DIALING_KEYPAD_LAYER_Y                      (MMI_DIALING_BOX_HEIGHT)
            #define MMI_DIALING_KEYPAD_X                            (6)
            #define MMI_DIALING_KEYPAD_Y                            (7)
            #define MMI_DIALING_KEYPAD_WIDTH                        (112)
            #define MMI_DIALING_KEYPAD_HEIGHT                       (110)
            #define MMI_DIALING_KEY_WIDTH                           (27)
            #define MMI_DIALING_KEY_HEIGHT                          (22)
            #define MMI_DIALING_KEY_HORIZONTAL_GAP                  (3)
            #define MMI_DIALING_KEY_VERTICAL_GAP                    (3)
            #define MMI_DIALING_BOX_X                               (0)
            #define MMI_DIALING_BOX_Y                               (0)    
            #define MMI_DIALING_BOX_WIDTH                           (0)
            #define MMI_DIALING_BOX_HEIGHT                          (30)
            /* For function key on idlescreen */
            #ifdef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (3)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (98)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (14)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (25)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (25)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (4)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (4)
            #else   /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */        
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (2)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (98)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (14)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (25)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (25)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (4)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (4)
            #endif   /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */    
        #else /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */
            #define MMI_DIALING_KEYPAD_COLOMNS                      (3)
            #define MMI_DIALING_KEYPAD_ROWS                         (4)
            #define MMI_DIALING_KEYPAD_LAYER_WIDTH                  (128)
            #define MMI_DIALING_KEYPAD_LAYER_HEIGHT                 (160)
            #define MMI_DIALING_KEYPAD_LAYER_X                      (0)
            #define MMI_DIALING_KEYPAD_LAYER_Y                      (MMI_DIALING_BOX_HEIGHT)
            #define MMI_DIALING_KEYPAD_X                            (8)
            #define MMI_DIALING_KEYPAD_Y                            (0)
            #define MMI_DIALING_KEYPAD_WIDTH                        (112)
            #define MMI_DIALING_KEYPAD_HEIGHT                       (110)
            #define MMI_DIALING_KEY_WIDTH                           (31)
            #define MMI_DIALING_KEY_HEIGHT                          (25)
            #define MMI_DIALING_KEY_HORIZONTAL_GAP                  (9)
            #define MMI_DIALING_KEY_VERTICAL_GAP                    (3)
            #define MMI_DIALING_BOX_X                               (0)
            #define MMI_DIALING_BOX_Y                               (0)    
            #define MMI_DIALING_BOX_WIDTH                           (0)
            #define MMI_DIALING_BOX_HEIGHT                          (30)
        #endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */
    #endif  /* LCD szie */
#else   /* __MMI_FULL_DIALSCREEN_FEATURE__ */
    #if defined (__MMI_MAINLCD_320X240__)
        #define MMI_DIALING_KEYPAD_COLOMNS                      (3)
        #define MMI_DIALING_KEYPAD_ROWS                         (4)
        #define MMI_DIALING_KEYPAD_LAYER_WIDTH                  (265)
        #define MMI_DIALING_KEYPAD_LAYER_HEIGHT                 (141)
        #define MMI_DIALING_KEYPAD_LAYER_X                      ((MAIN_LCD_DEVICE_WIDTH-MMI_DIALING_KEYPAD_LAYER_WIDTH)>>1)
        #define MMI_DIALING_KEYPAD_LAYER_Y                      (((MAIN_LCD_DEVICE_HEIGHT-MMI_DIALING_KEYPAD_LAYER_HEIGHT)>>1)+20)
        #define MMI_DIALING_KEYPAD_X                            (13)
        #define MMI_DIALING_KEYPAD_Y                            (9)
        #define MMI_DIALING_KEYPAD_WIDTH                        (265)
        #define MMI_DIALING_KEYPAD_HEIGHT                       (141)
        #define MMI_DIALING_KEY_WIDTH                           (59)
        #define MMI_DIALING_KEY_HEIGHT                          (26)
        #define MMI_DIALING_KEY_HORIZONTAL_GAP                  (4)
        #define MMI_DIALING_KEY_VERTICAL_GAP                    (5)
        #define MMI_DIALING_BOX_HEIGHT                          (47)
        /* For function key on idlescreen */
        #if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
            #ifdef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (3)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (218)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (14)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (32)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (33)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (8)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (8)
            #else /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (2)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (216)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (22)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (32)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (33)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (18)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (28)            
            #endif /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
        #endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */
    #elif defined (__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
        #define MMI_DIALING_KEYPAD_COLOMNS                      (3)
        #define MMI_DIALING_KEYPAD_ROWS                         (4)
        #define MMI_DIALING_KEYPAD_LAYER_WIDTH                  (265)
        #define MMI_DIALING_KEYPAD_LAYER_HEIGHT                 (141)
        #define MMI_DIALING_KEYPAD_LAYER_X                      ((MAIN_LCD_DEVICE_WIDTH-MMI_DIALING_KEYPAD_LAYER_WIDTH)>>1)
        #define MMI_DIALING_KEYPAD_LAYER_Y                      (((MAIN_LCD_DEVICE_HEIGHT-MMI_DIALING_KEYPAD_LAYER_HEIGHT)>>1)+20)
        #define MMI_DIALING_KEYPAD_X                            (13)
        #define MMI_DIALING_KEYPAD_Y                            (9)
        #define MMI_DIALING_KEYPAD_WIDTH                        (265)
        #define MMI_DIALING_KEYPAD_HEIGHT                       (141)
        #define MMI_DIALING_KEY_WIDTH                           (59)
        #define MMI_DIALING_KEY_HEIGHT                          (26)
        #define MMI_DIALING_KEY_HORIZONTAL_GAP                  (4)
        #define MMI_DIALING_KEY_VERTICAL_GAP                    (5)
        #define MMI_DIALING_BOX_HEIGHT                          (47)
        /* For function key on idlescreen */
        #if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
            #ifdef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (3)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (218)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (14)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (32)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (33)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (8)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (8)
            #else /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (2)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (216)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (22)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (32)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (33)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (18)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (28)            
            #endif /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
        #endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */        
    #elif defined (__MMI_MAINLCD_240X320__)
        #define MMI_DIALING_KEYPAD_COLOMNS                  (3)
        #define MMI_DIALING_KEYPAD_ROWS                     (4)
        #define MMI_DIALING_KEYPAD_LAYER_WIDTH              (240)
        #define MMI_DIALING_KEYPAD_LAYER_HEIGHT             (212) ///(212)
        #define MMI_DIALING_KEYPAD_LAYER_X                  (0)//((MAIN_LCD_DEVICE_WIDTH-MMI_DIALING_KEYPAD_LAYER_WIDTH)>>1)
        #define MMI_DIALING_KEYPAD_LAYER_Y                  (84) //(((MAIN_LCD_DEVICE_HEIGHT-MMI_DIALING_KEYPAD_LAYER_HEIGHT)>>1)+30)
        #define MMI_DIALING_KEYPAD_X                        (0) //(0)
        #define MMI_DIALING_KEYPAD_Y                        (0) //(0)
        #define MMI_DIALING_KEYPAD_WIDTH                    (240)
        #define MMI_DIALING_KEYPAD_HEIGHT                   (212)//(212)
        #define MMI_DIALING_KEY_WIDTH                       (61) //(61)
        #define MMI_DIALING_KEY_HEIGHT                      (53) //(53)
        #define MMI_DIALING_KEY_HORIZONTAL_GAP              (0) //(0)
        #define MMI_DIALING_KEY_VERTICAL_GAP                (0) //(0)
        #define MMI_DIALING_BOX_X                           (0)
        #define MMI_DIALING_BOX_Y                           (0)
        #define MMI_DIALING_BOX_WIDTH                       (0)
        #define MMI_DIALING_BOX_HEIGHT                      (60) //(60)
        /* For function key on idlescreen */
        #if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
            #ifdef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS     (1) 
                #define MMI_DIALING_KEYPAD_FUNC_ROWS        (3) 
                #define MMI_DIALING_KEYPAD_FUNC_X       (183)
                #define MMI_DIALING_KEYPAD_FUNC_Y       (0)
                #define MMI_DIALING_FUNC_KEY_WIDTH      (57)
                #define MMI_DIALING_FUNC_KEY_HEIGHT     (71)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP (12)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP   (0)
            #else   /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS     (1) 
                #define MMI_DIALING_KEYPAD_FUNC_ROWS        (2) 
                #define MMI_DIALING_KEYPAD_FUNC_X       (183)
                #define MMI_DIALING_KEYPAD_FUNC_Y       (0)
                #define MMI_DIALING_FUNC_KEY_WIDTH      (57)
                #define MMI_DIALING_FUNC_KEY_HEIGHT     (106)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP (12)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP   (0)
            #endif  /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
        #endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */
    #elif defined (__MMI_MAINLCD_176X220__)
        #define MMI_DIALING_KEYPAD_COLOMNS                      (3)
        #define MMI_DIALING_KEYPAD_ROWS                         (4)
        #define MMI_DIALING_KEYPAD_LAYER_WIDTH                  (176)
        #define MMI_DIALING_KEYPAD_LAYER_HEIGHT                 (200)
        #define MMI_DIALING_KEYPAD_LAYER_X                      (0)
        #define MMI_DIALING_KEYPAD_LAYER_Y                      (50)
        #define MMI_DIALING_KEYPAD_X                            (16)
        #define MMI_DIALING_KEYPAD_Y                            (7)
        #define MMI_DIALING_KEYPAD_WIDTH                        (145)
        #define MMI_DIALING_KEYPAD_HEIGHT                       (137)
        #define MMI_DIALING_KEY_WIDTH                           (39)
        #define MMI_DIALING_KEY_HEIGHT                          (31)
        #define MMI_DIALING_KEY_HORIZONTAL_GAP                  (14)
        #define MMI_DIALING_KEY_VERTICAL_GAP                    (5)
        #define MMI_DIALING_BOX_X                               (0)
        #define MMI_DIALING_BOX_Y                               (0)
        #define MMI_DIALING_BOX_WIDTH                           (0)
        #define MMI_DIALING_BOX_HEIGHT                          (33)
        /* For function key on idlescreen */
        #if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
            #ifdef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (3)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (165)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (33)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (37)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (25)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (12)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (27)
            #else   /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */    
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (2)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (165)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (33)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (37)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (37)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (12)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (27)
            #endif /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */            
        #endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */
    #else /* LCD Size */
        #if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
            #define MMI_DIALING_KEYPAD_COLOMNS                      (3)
            #define MMI_DIALING_KEYPAD_ROWS                         (4)
            #define MMI_DIALING_KEYPAD_LAYER_WIDTH                  (128)
            #define MMI_DIALING_KEYPAD_LAYER_HEIGHT                 (160)
            #define MMI_DIALING_KEYPAD_LAYER_X                      (0)
            #define MMI_DIALING_KEYPAD_LAYER_Y                      (MMI_DIALING_BOX_HEIGHT)
            #define MMI_DIALING_KEYPAD_X                            (6)
            #define MMI_DIALING_KEYPAD_Y                            (7)
            #define MMI_DIALING_KEYPAD_WIDTH                        (112)
            #define MMI_DIALING_KEYPAD_HEIGHT                       (110)
            #define MMI_DIALING_KEY_WIDTH                           (27)
            #define MMI_DIALING_KEY_HEIGHT                          (22)
            #define MMI_DIALING_KEY_HORIZONTAL_GAP                  (3)
            #define MMI_DIALING_KEY_VERTICAL_GAP                    (3)
            #define MMI_DIALING_BOX_X                               (0)
            #define MMI_DIALING_BOX_Y                               (0)
            #define MMI_DIALING_BOX_WIDTH                           (0)
            #define MMI_DIALING_BOX_HEIGHT                          (30)
            /* For function key on idlescreen */
            #ifdef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (3)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (98)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (14)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (25)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (25)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (4)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (4)
            #else   /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */        
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (2)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (98)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (14)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (25)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (25)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (4)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (4)
            #endif   /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */    
        #else /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */
            #define MMI_DIALING_KEYPAD_COLOMNS                      (3)
            #define MMI_DIALING_KEYPAD_ROWS                         (4)
            #define MMI_DIALING_KEYPAD_LAYER_WIDTH                  (128)
            #define MMI_DIALING_KEYPAD_LAYER_HEIGHT                 (160)
            #define MMI_DIALING_KEYPAD_LAYER_X                      (0)
            #define MMI_DIALING_KEYPAD_LAYER_Y                      (MMI_DIALING_BOX_HEIGHT)
            #define MMI_DIALING_KEYPAD_X                            (8)
            #define MMI_DIALING_KEYPAD_Y                            (0)
            #define MMI_DIALING_KEYPAD_WIDTH                        (112)
            #define MMI_DIALING_KEYPAD_HEIGHT                       (110)
            #define MMI_DIALING_KEY_WIDTH                           (31)
            #define MMI_DIALING_KEY_HEIGHT                          (25)
            #define MMI_DIALING_KEY_HORIZONTAL_GAP                  (9)
            #define MMI_DIALING_KEY_VERTICAL_GAP                    (3)
            #define MMI_DIALING_BOX_X                               (0)
            #define MMI_DIALING_BOX_Y                               (0)
            #define MMI_DIALING_BOX_WIDTH                           (0)
            #define MMI_DIALING_BOX_HEIGHT                          (30)
        #endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */
    #endif /* LCD Size */
#endif  /* __MMI_FULL_DIALSCREEN_FEATURE__ */


/* Idle screen */
#if defined( __MMI_DUAL_SIM_MASTER__)||defined(__KJX_FUN__)	//xb add 2017-07-18
/******************************************************************************
 *This Area, is define of Dual SIM IDLE
 ******************************************************************************/
 #if defined(__MMI_MAINLCD_96X64__)
    #define CFG_UI_IDLE_NETWORK_NAME_Y                              (15)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y                            (40)
    #define CFG_UI_IDLE_EXTRA_Y                                     (32)
    #define CFG_UI_IDLE_SATICON_Y                                   (0)
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y                         (22)
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y                       (40)
#elif defined(__MMI_MAINLCD_128X128__)
    #define CFG_UI_IDLE_NETWORK_NAME_Y                              (22)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y                            (40)
    #define CFG_UI_IDLE_EXTRA_Y                                     (58)
    #define CFG_UI_IDLE_SATICON_Y                                   (0)
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y                         (22)
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y                       (40)
#elif defined(__MMI_MAINLCD_128X160__)
    #define CFG_UI_IDLE_NETWORK_NAME_Y                              (18)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y                            (36)
    #define CFG_UI_IDLE_EXTRA_Y                                     (90)
    #define CFG_UI_IDLE_SATICON_Y                                   (0)
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y                         (54)
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y                       (72)
#elif defined(__MMI_MAINLCD_176X220__)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO                  (98)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_STATUS_AT_BOTTOM        (24)
    #define CFG_UI_IDLE_NETWORK_NAME_Y                              (24)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO                (120)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_STATUS_AT_BOTTOM      (44)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y                            (44)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO                         (184)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_STATUS_AT_BOTTOM               (104)
    #define CFG_UI_IDLE_EXTRA_Y                                     (104)
    #define CFG_UI_IDLE_SATICON_Y_WITH_TECHNO                       (160)
    #define CFG_UI_IDLE_SATICON_Y_WITH_STATUS_AT_BOTTOM             (0)
    #define CFG_UI_IDLE_SATICON_Y                                   (0)
    
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_TECHNO             (142)
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_STATUS_AT_BOTTOM   (64)
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y                         (64)
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_TECHNO           (164)
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_STATUS_AT_BOTTOM (84)
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y                       (84)
#elif defined(__MMI_MAINLCD_240X320__)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO_AND_SHORTCUT     (108)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO                  (108)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_STATUS_AT_BOTTOM        (45)
    #define CFG_UI_IDLE_NETWORK_NAME_Y                              (41)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO_AND_SHORTCUT   (138)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO                (138)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_STATUS_AT_BOTTOM      (65)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y                            (50)
  #if defined(__KJX_FUN__)
	#define CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO_AND_SHORTCUT            (235)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO                         (235)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_STATUS_AT_BOTTOM               (235)
    #define CFG_UI_IDLE_EXTRA_Y                                     (235)
    #define CFG_UI_IDLE_SATICON_Y_WITH_TECHNO_AND_SHORTCUT          (235)
    #define CFG_UI_IDLE_SATICON_Y_WITH_TECHNO                       (235)
    #define CFG_UI_IDLE_SATICON_Y_WITH_STATUS_AT_BOTTOM             (235)
    #define CFG_UI_IDLE_SATICON_Y                                   (235)
  #else
    #define CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO_AND_SHORTCUT            (228)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO                         (228)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_STATUS_AT_BOTTOM               (125)
    #define CFG_UI_IDLE_EXTRA_Y                                     (147)
    #define CFG_UI_IDLE_SATICON_Y_WITH_TECHNO_AND_SHORTCUT          (220)
    #define CFG_UI_IDLE_SATICON_Y_WITH_TECHNO                       (220)
    #define CFG_UI_IDLE_SATICON_Y_WITH_STATUS_AT_BOTTOM             (220)
    #define CFG_UI_IDLE_SATICON_Y                                   (153)
  #endif

  #if defined(__KJX_FUN__)
	#define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_TECHNO_AND_SHORTCUT    (168+20)
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_TECHNO                 (168+20)
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_STATUS_AT_BOTTOM       (85+20)
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y                             (95+20)
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_TECHNO_AND_SHORTCUT  (198+25)    
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_TECHNO               (198+25)
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_STATUS_AT_BOTTOM     (105+25)
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y                           (122+25)
  #else
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_TECHNO_AND_SHORTCUT    (168)
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_TECHNO                 (168)
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_STATUS_AT_BOTTOM       (85)
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y                             (95)
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_TECHNO_AND_SHORTCUT  (198)    
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_TECHNO               (198)
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_STATUS_AT_BOTTOM     (105)
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y                           (122)
  #endif
#elif defined(__MMI_MAINLCD_320X240__)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO_AND_SHORTCUT     (105)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO                  (105)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_STATUS_AT_BOTTOM        (45)
    #define CFG_UI_IDLE_NETWORK_NAME_Y                              (40)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO_AND_SHORTCUT   (128)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO                (128)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_STATUS_AT_BOTTOM      (64)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y                            (63)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO_AND_SHORTCUT            (154)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO                         (154)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_STATUS_AT_BOTTOM               (130)
    #define CFG_UI_IDLE_EXTRA_Y                                     (132)
    #define CFG_UI_IDLE_SATICON_Y_WITH_TECHNO_AND_SHORTCUT          (180)
    #define CFG_UI_IDLE_SATICON_Y_WITH_TECHNO                       (180)
    #define CFG_UI_IDLE_SATICON_Y_WITH_STATUS_AT_BOTTOM             (155)
    #define CFG_UI_IDLE_SATICON_Y                                   (112)
    
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_TECHNO_AND_SHORTCUT    (151)
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_TECHNO                 (151)
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_STATUS_AT_BOTTOM       (85)
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y                             (86)
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_TECHNO_AND_SHORTCUT  (174)    
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_TECHNO               (174)
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_STATUS_AT_BOTTOM     (105)
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y                           (109)
#elif defined(__MMI_MAINLCD_240X400__)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO_AND_SHORTCUT     (102)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO                  (102)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_STATUS_AT_BOTTOM        (59)
    #define CFG_UI_IDLE_NETWORK_NAME_Y                              (59)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO_AND_SHORTCUT   (135)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO                (135)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_STATUS_AT_BOTTOM      (80)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y                            (80)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO_AND_SHORTCUT            (277)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO                         (277)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_STATUS_AT_BOTTOM               (227)
    #define CFG_UI_IDLE_EXTRA_Y                                     (227)
    #define CFG_UI_IDLE_SATICON_Y_WITH_TECHNO_AND_SHORTCUT          (302)
    #define CFG_UI_IDLE_SATICON_Y_WITH_TECHNO                       (302)
    #define CFG_UI_IDLE_SATICON_Y_WITH_STATUS_AT_BOTTOM             (309)
    #define CFG_UI_IDLE_SATICON_Y                                   (347)
    
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_TECHNO_AND_SHORTCUT    (168)
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_TECHNO                 (168)
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_STATUS_AT_BOTTOM       (101)
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y                             (101)
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_TECHNO_AND_SHORTCUT  (201)
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_TECHNO               (201)
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_STATUS_AT_BOTTOM     (122)
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y                           (122)
#elif defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO_AND_SHORTCUT     (105)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO                  (105)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_STATUS_AT_BOTTOM        (45)
    #define CFG_UI_IDLE_NETWORK_NAME_Y                              (45)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO_AND_SHORTCUT   (128)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO                (128)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_STATUS_AT_BOTTOM      (75)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y                            (75)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO_AND_SHORTCUT            (154)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO                         (154)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_STATUS_AT_BOTTOM               (165)
    #define CFG_UI_IDLE_EXTRA_Y                                     (165)
    #define CFG_UI_IDLE_SATICON_Y_WITH_TECHNO_AND_SHORTCUT          (180)
    #define CFG_UI_IDLE_SATICON_Y_WITH_TECHNO                       (180)
    #define CFG_UI_IDLE_SATICON_Y_WITH_STATUS_AT_BOTTOM             (195)
    #define CFG_UI_IDLE_SATICON_Y                                   (195)
    
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_TECHNO_AND_SHORTCUT    (151)
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_TECHNO                 (151)
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_STATUS_AT_BOTTOM       (105)
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y                             (105)
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_TECHNO_AND_SHORTCUT  (174)    
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_TECHNO               (174)
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_STATUS_AT_BOTTOM     (135)
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y                           (135)
#else
    #error "No UI Style is Specified!!"
#endif
/******************************************************************************/

#else /* defined( __MMI_DUAL_SIM_MASTER__) */
/******************************************************************************
 *This Area, is define of Singel SIM IDLE
 ******************************************************************************/
 // baiwenlin 20130821  
#if defined (__MMI_MAINLCD_128X64__)||defined (__MMI_MAINLCD_128X36__)

    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO_AND_SHORTCUT 	(138)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO					(138)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_STATUS_AT_BOTTOM		(45)
    #define CFG_UI_IDLE_NETWORK_NAME_Y								(17)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO_AND_SHORTCUT	(168)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO				(168)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_STATUS_AT_BOTTOM		(68)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y							(68)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO_AND_SHORTCUT			(198)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO 						(198)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_STATUS_AT_BOTTOM				(91)
    #define CFG_UI_IDLE_EXTRA_Y 									(91)
    #define CFG_UI_IDLE_SATICON_Y_WITH_TECHNO_AND_SHORTCUT			(220)
    #define CFG_UI_IDLE_SATICON_Y_WITH_TECHNO						(220)
    #define CFG_UI_IDLE_SATICON_Y_WITH_STATUS_AT_BOTTOM 			(220)
    #define CFG_UI_IDLE_SATICON_Y									(153)
#elif defined(__MMI_MAINLCD_96X64__)
    #define CFG_UI_IDLE_NETWORK_NAME_Y                              (15)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y                            (40)
    #define CFG_UI_IDLE_EXTRA_Y                                     (32)
    #define CFG_UI_IDLE_SATICON_Y                                   (0)

#elif defined(__MMI_MAINLCD_128X128__)
    #define CFG_UI_IDLE_NETWORK_NAME_Y                              (22)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y                            (40)
    #define CFG_UI_IDLE_EXTRA_Y                                     (58)
    #define CFG_UI_IDLE_SATICON_Y                                   (0)
#elif defined(__MMI_MAINLCD_128X160__)
    #define CFG_UI_IDLE_NETWORK_NAME_Y                              (28)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y                            (49)
    #define CFG_UI_IDLE_EXTRA_Y                                     (69)
    #define CFG_UI_IDLE_SATICON_Y                                   (0)
#elif defined(__MMI_MAINLCD_176X220__)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO                  (98)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_STATUS_AT_BOTTOM        (24)
    #define CFG_UI_IDLE_NETWORK_NAME_Y                              (24)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO                (120)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_STATUS_AT_BOTTOM      (42)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y                            (44)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO                         (142)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_STATUS_AT_BOTTOM               (60)
    #define CFG_UI_IDLE_EXTRA_Y                                     (60)
    #define CFG_UI_IDLE_SATICON_Y_WITH_TECHNO                       (160)
    #define CFG_UI_IDLE_SATICON_Y_WITH_STATUS_AT_BOTTOM             (0)
    #define CFG_UI_IDLE_SATICON_Y                                   (0)
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X240__)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO_AND_SHORTCUT     (138)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO                  (138)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_STATUS_AT_BOTTOM        (45)
    #define CFG_UI_IDLE_NETWORK_NAME_Y                              (45)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO_AND_SHORTCUT   (168)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO                (168)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_STATUS_AT_BOTTOM      (68)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y                            (68)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO_AND_SHORTCUT            (198)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO                         (198)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_STATUS_AT_BOTTOM               (91)
    #define CFG_UI_IDLE_EXTRA_Y                                     (91)
    #define CFG_UI_IDLE_SATICON_Y_WITH_TECHNO_AND_SHORTCUT          (220)
    #define CFG_UI_IDLE_SATICON_Y_WITH_TECHNO                       (220)
    #define CFG_UI_IDLE_SATICON_Y_WITH_STATUS_AT_BOTTOM             (220)
    #define CFG_UI_IDLE_SATICON_Y                                   (153)
#elif defined(__MMI_MAINLCD_320X240__)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO_AND_SHORTCUT     (105)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO                  (105)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_STATUS_AT_BOTTOM        (45)
    #define CFG_UI_IDLE_NETWORK_NAME_Y                              (45)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO_AND_SHORTCUT   (128)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO                (128)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_STATUS_AT_BOTTOM      (64)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y                            (65)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO_AND_SHORTCUT            (154)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO                         (154)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_STATUS_AT_BOTTOM               (130)
    #define CFG_UI_IDLE_EXTRA_Y                                     (90)
    #define CFG_UI_IDLE_SATICON_Y_WITH_TECHNO_AND_SHORTCUT          (180)
    #define CFG_UI_IDLE_SATICON_Y_WITH_TECHNO                       (180)
    #define CFG_UI_IDLE_SATICON_Y_WITH_STATUS_AT_BOTTOM             (155)
    #define CFG_UI_IDLE_SATICON_Y                                   (112)
#elif defined(__MMI_MAINLCD_240X400__)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO_AND_SHORTCUT     (102)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO                  (102)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_STATUS_AT_BOTTOM        (59)
    #define CFG_UI_IDLE_NETWORK_NAME_Y                              (59)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO_AND_SHORTCUT   (135)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO                (135)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_STATUS_AT_BOTTOM      (80)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y                            (82)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO_AND_SHORTCUT            (277)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO                         (277)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_STATUS_AT_BOTTOM               (227)
    #define CFG_UI_IDLE_EXTRA_Y                                     (227)
    #define CFG_UI_IDLE_SATICON_Y_WITH_TECHNO_AND_SHORTCUT          (302)
    #define CFG_UI_IDLE_SATICON_Y_WITH_TECHNO                       (302)
    #define CFG_UI_IDLE_SATICON_Y_WITH_STATUS_AT_BOTTOM             (309)
    #define CFG_UI_IDLE_SATICON_Y                                   (347)
#elif defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO_AND_SHORTCUT     (105)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO                  (105)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_STATUS_AT_BOTTOM        (45)
    #define CFG_UI_IDLE_NETWORK_NAME_Y                              (45)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO_AND_SHORTCUT   (128)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO                (128)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_STATUS_AT_BOTTOM      (64)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y                            (65)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO_AND_SHORTCUT            (154)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO                         (154)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_STATUS_AT_BOTTOM               (130)
    #define CFG_UI_IDLE_EXTRA_Y                                     (90)
    #define CFG_UI_IDLE_SATICON_Y_WITH_TECHNO_AND_SHORTCUT          (180)
    #define CFG_UI_IDLE_SATICON_Y_WITH_TECHNO                       (180)
    #define CFG_UI_IDLE_SATICON_Y_WITH_STATUS_AT_BOTTOM             (155)
    #define CFG_UI_IDLE_SATICON_Y                                   (112)
#else
    #error "No UI Style is Specified!!"
#endif
/******************************************************************************/

#endif /* defined( __MMI_DUAL_SIM_MASTER__) */



/* 
 * MAIN MENU
 */
/* main menu matrix menuitem image width and height */
#if defined (__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_CLIP_WIDTH               (100)   /* equal to MAIN_MENU_NORMAL_IMAGE_WIDTH */
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_CLIP_HEIGHT              (100)   /* equal to MAIN_MENU_NORMAL_IMAGE_HEIGHT */
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_WIDTH                    (100)   /* MAX normal image width */ 
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_HEIGHT                   (100)   /* MAX normal image height */
#if defined (__MMI_FTE_SUPPORT__)
    #define CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_WIDTH               (106)   /* MAX highlighted image width, affects the cache buffer size */
    #define CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_HEIGHT              (102)   /* MAX highlighted image height, affects the cache buffer size */
#else
    #define CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_WIDTH               (100)   /* MAX highlighted image width, affects the cache buffer size */
    #define CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_HEIGHT              (100)   /* MAX highlighted image height, affects the cache buffer size */
#endif
#elif defined(__MMI_MAINLCD_240X320__)

#ifdef __MMI_SLIM_IMG_RES__
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_CLIP_WIDTH               (60)   /* equal to MAIN_MENU_NORMAL_IMAGE_WIDTH */
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_CLIP_HEIGHT              (60)   /* equal to MAIN_MENU_NORMAL_IMAGE_HEIGHT */
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_WIDTH                    (60)   /* MAX normal image width */ 
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_HEIGHT                   (60)   /* MAX normal image height */
    #define CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_WIDTH               (80)   /* MAX highlighted image width, affects the cache buffer size */
    #define CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_HEIGHT              (60)   /* MAX highlighted image height, affects the cache buffer size */
#else
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_CLIP_WIDTH               (80)   /* equal to MAIN_MENU_NORMAL_IMAGE_WIDTH */
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_CLIP_HEIGHT              (60)   /* equal to MAIN_MENU_NORMAL_IMAGE_HEIGHT */
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_WIDTH                    (80)   /* MAX normal image width */ 
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_HEIGHT                   (60)   /* MAX normal image height */
    #define CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_WIDTH               (80)   /* MAX highlighted image width, affects the cache buffer size */
    #define CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_HEIGHT              (60)   /* MAX highlighted image height, affects the cache buffer size */
#endif
#elif defined(__MMI_MAINLCD_320X240__)
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_CLIP_WIDTH               (80)   /* equal to MAIN_MENU_NORMAL_IMAGE_WIDTH */
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_CLIP_HEIGHT              (58)   /* equal to MAIN_MENU_NORMAL_IMAGE_HEIGHT */
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_WIDTH                    (80)   /* MAX normal image width */ 
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_HEIGHT                   (58)   /* MAX normal image height */
    #define CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_WIDTH               (80)   /* MAX highlighted image width, affects the cache buffer size */
    #define CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_HEIGHT              (58)   /* MAX highlighted image height, affects the cache buffer size */
#elif defined(__MMI_MAINLCD_240X400__)  
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_CLIP_WIDTH               (50)   /* equal to MAIN_MENU_NORMAL_IMAGE_WIDTH */
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_CLIP_HEIGHT              (50)   /* equal to MAIN_MENU_NORMAL_IMAGE_HEIGHT */
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_WIDTH                    (50)   /* MAX normal image width */ 
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_HEIGHT                   (50)   /* MAX normal image height */
    #define CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_WIDTH               (80)   /* MAX highlighted image width, affects the cache buffer size */
    #define CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_HEIGHT              (60)   /* MAX highlighted image height, affects the cache buffer size */
#elif defined(__MMI_MAINLCD_176X220__)
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_CLIP_WIDTH               (41)   /* equal to MAIN_MENU_NORMAL_IMAGE_WIDTH */
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_CLIP_HEIGHT              (30)   /* equal to MAIN_MENU_NORMAL_IMAGE_HEIGHT */
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_WIDTH                    (42)   /* MAX normal image width */ 
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_HEIGHT                   (31)   /* MAX normal image height */
    /* highligted image dimension: 176x220 -> 50x50, 128x160 -> 38x38, 128x128 -> 34x34 */
    // TODO: use different dimensions for each resolution to save memory
    #define CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_WIDTH               (50)   /* MAX highlighted image width, affects the cache buffer size */
    #define CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_HEIGHT              (50)   /* MAX highlighted image height, affects the cache buffer size */
#elif defined(__MMI_MAINLCD_128X160__)
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_CLIP_WIDTH               (41)   /* equal to MAIN_MENU_NORMAL_IMAGE_WIDTH */
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_CLIP_HEIGHT              (30)   /* equal to MAIN_MENU_NORMAL_IMAGE_HEIGHT */
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_WIDTH                    (42)   /* MAX normal image width */ 
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_HEIGHT                   (31)   /* MAX normal image height */
    #define CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_WIDTH               (38)   /* MAX highlighted image width, affects the cache buffer size */
    #define CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_HEIGHT              (38)   /* MAX highlighted image height, affects the cache buffer size */
#else /* defined (__MMI_MAINLCD_128X128__) */
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_CLIP_WIDTH               (41)   /* equal to MAIN_MENU_NORMAL_IMAGE_WIDTH */
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_CLIP_HEIGHT              (30)   /* equal to MAIN_MENU_NORMAL_IMAGE_HEIGHT */
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_WIDTH                    (42)   /* MAX normal image width */ 
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_HEIGHT                   (31)   /* MAX normal image height */
    #define CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_WIDTH               (34)   /* MAX highlighted image width, affects the cache buffer size */
    #define CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_HEIGHT              (34)   /* MAX highlighted image height, affects the cache buffer size */
#endif /* defined (__MMI_MAINLCD_320X480__) */

#ifdef __MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT__
#if defined(__MMI_MAINLCD_240X320__)
    #undef  CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_WIDTH
    #define CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_WIDTH               (120)   /* MAX highlighted image width, affects the cache buffer size */
    #undef  CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_HEIGHT
    #define CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_HEIGHT              (90)   /* MAX highlighted image height, affects the cache buffer size */
#elif defined(__MMI_MAINLCD_320X240__)  
    #undef	CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_WIDTH
    #define CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_WIDTH               (120)   /* MAX highlighted image width, affects the cache buffer size */
    #undef  CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_HEIGHT
    #define CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_HEIGHT              (87)   /* MAX highlighted image height, affects the cache buffer size */
#elif defined(__MMI_MAINLCD_176X220__)  
    #undef	CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_WIDTH
    #define CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_WIDTH               (90)   /* MAX highlighted image width, affects the cache buffer size */
    #undef  CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_HEIGHT
    #define CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_HEIGHT              (70)   /* MAX highlighted image height, affects the cache buffer size */
#endif /* defined(__MMI_MAINLCD_240X320__)  || defined(__MMI_MAINLCD_320X240__)  */
#endif /* __MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT__ */

#if defined (__MMI_MAINLCD_240X400__)
    #define CFG_UI_MAIN_MENU_MATRIX_AREA_X_GAP                       (20)
    #define CFG_UI_MAIN_MENU_MATRIX_AREA_Y_GAP                       (10)
    #define CFG_UI_MAIN_MENU_CONTROL_AREA_HEIGHT                     (135)
    #define CFG_UI_MAIN_MENU_CONTROL_AREA_X_GAP                      (10)
    #define CFG_UI_MAIN_MENU_CONTROL_AREA_Y_GAP                      (248)
#else
    #define CFG_UI_MAIN_MENU_MATRIX_AREA_X_GAP                       (0)
    #define CFG_UI_MAIN_MENU_MATRIX_AREA_Y_GAP                       (0)
    #define CFG_UI_MAIN_MENU_CONTROL_AREA_HEIGHT                     (0)
    #define CFG_UI_MAIN_MENU_CONTROL_AREA_X_GAP                      (0)
    #define CFG_UI_MAIN_MENU_CONTROL_AREA_Y_GAP                      (0)
#endif

#if defined (__MMI_MAINLCD_96X64__)
    
    /* height of status icon bar */
    #define CFG_UI_STATUS_BAR_HEIGHT                       (12)
    /* y position of status icon bar in idle screen*/
    #define CFG_UI_STATUS_BAR_IDLE_Y                        (0)
    /* height of thin title */
    #define CFG_UI_THIN_TITLE_HEIGHT                       (14)
    /* height of thin title */
    #define CFG_UI_THICK_TITLE_HEIGHT                      (14)
    /* height of button bar*/
    #define CFG_UI_BUTTON_BAR_HEIGHT                       (14)
    /* height of softkey bar*/
    #define CFG_UI_SOFTKEY_BAR_HEIGHT                      (14)
    /* width of left & right softkey */
    #define CFG_UI_SOFTKEY_WIDTH                           (42)
    /* width of center softkey */
    #define CFG_UI_CENTER_SOFTKEY_WIDTH                    (12)
    /* height of softkey */
    #define CFG_UI_SOFTKEY_HEIGHT                          (14)
    /* height of single menu item */
    #define CFG_UI_MENUITEM_HEIGHT                         (12)
    /* height of two-line menu item*/
    #define CFG_UI_MENUITEM_TWOLINE_HEIGHT                 (15) 
    /* height of multi-row menu item*/
    #define CFG_UI_MENUITEM_MULTIROW_HEIGHT                (15)
    /* height of thick menu item*/
    #define CFG_UI_MENUITEM_THICK_HEIGHT                   (15)
    /* height of thick with tab menu item*/
    #define CFG_UI_MENUITEM_THICK_WITH_TAB_HEIGHT          (15)
    /* width of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_WIDTH                     (86)
    /* height of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_HEIGHT                    (56)
    /* x of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_X                         (5)
    /* y of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_Y                         (4)
    /* full height of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_FULL_HEIGHT               (56)
    /* margin x of pop up content */
    #define CFG_UI_POP_UP_CONTENT_MARGIN_X                  (20)
    /* margin y of pop up content */
    #define CFG_UI_POP_UP_CONTENT_MARGIN_Y                  (20)

#elif defined (__MMI_MAINLCD_128X64__)
    
    /* height of status icon bar */
    #define CFG_UI_STATUS_BAR_HEIGHT                       (12)
    /* y position of status icon bar in idle screen*/
    #define CFG_UI_STATUS_BAR_IDLE_Y                        (0)
    /* height of thin title */
    #define CFG_UI_THIN_TITLE_HEIGHT                       (0)
    /* height of thin title */
    #define CFG_UI_THICK_TITLE_HEIGHT                      (0)
    /* height of button bar*/
    #define CFG_UI_BUTTON_BAR_HEIGHT                       (0)
    /* height of softkey bar*/
    #define CFG_UI_SOFTKEY_BAR_HEIGHT                      (0)
    /* width of left & right softkey */
    #define CFG_UI_SOFTKEY_WIDTH                           (0)
    /* width of center softkey */
    #define CFG_UI_CENTER_SOFTKEY_WIDTH                    (0)
    /* height of softkey */
    #define CFG_UI_SOFTKEY_HEIGHT                          (0)
    /* height of single menu item */
    #define CFG_UI_MENUITEM_HEIGHT                         (12)
    /* height of two-line menu item*/
    #define CFG_UI_MENUITEM_TWOLINE_HEIGHT                 (12) 
    /* height of multi-row menu item*/
    #define CFG_UI_MENUITEM_MULTIROW_HEIGHT                (12)
    /* height of thick menu item*/
    #define CFG_UI_MENUITEM_THICK_HEIGHT                   (12)
    /* height of thick with tab menu item*/
    #define CFG_UI_MENUITEM_THICK_WITH_TAB_HEIGHT          (12)
    /* width of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_WIDTH                     (128)
    /* height of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_HEIGHT                    (63)
    /* x of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_X                         (0)
    /* y of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_Y                         (0)
    /* full height of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_FULL_HEIGHT               (64)
    /* margin x of pop up content */
    #define CFG_UI_POP_UP_CONTENT_MARGIN_X                  (0)
    /* margin y of pop up content */
    #define CFG_UI_POP_UP_CONTENT_MARGIN_Y                  (0)
// baiwenlin 20130821  	
#elif defined (__MMI_MAINLCD_128X36__)
    
    /* height of status icon bar */
    #define CFG_UI_STATUS_BAR_HEIGHT                       (12)
    /* y position of status icon bar in idle screen*/
    #define CFG_UI_STATUS_BAR_IDLE_Y                        (0)
    /* height of thin title */
    #define CFG_UI_THIN_TITLE_HEIGHT                       (0)
    /* height of thin title */
    #define CFG_UI_THICK_TITLE_HEIGHT                      (0)
    /* height of button bar*/
    #define CFG_UI_BUTTON_BAR_HEIGHT                       (16)
    /* height of softkey bar*/
    #define CFG_UI_SOFTKEY_BAR_HEIGHT                      (16)
    /* width of left & right softkey */
    #define CFG_UI_SOFTKEY_WIDTH                           (44)
    /* width of center softkey */
    #define CFG_UI_CENTER_SOFTKEY_WIDTH                    (40)
    /* height of softkey */
    #define CFG_UI_SOFTKEY_HEIGHT                          (16)
    /* height of single menu item */
    #define CFG_UI_MENUITEM_HEIGHT                         (15)
    /* height of two-line menu item*/
    #define CFG_UI_MENUITEM_TWOLINE_HEIGHT                 (15) 
    /* height of multi-row menu item*/
    #define CFG_UI_MENUITEM_MULTIROW_HEIGHT                (15)
    /* height of thick menu item*/
    #define CFG_UI_MENUITEM_THICK_HEIGHT                   (15)
    /* height of thick with tab menu item*/
    #define CFG_UI_MENUITEM_THICK_WITH_TAB_HEIGHT          (15)
    /* width of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_WIDTH                     (216)
    /* height of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_HEIGHT                    (192)
    /* x of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_X                         (12)
    /* y of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_Y                         (74)
    /* full height of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_FULL_HEIGHT               (192)
    /* margin x of pop up content */
    #define CFG_UI_POP_UP_CONTENT_MARGIN_X                  (20)
    /* margin y of pop up content */
    #define CFG_UI_POP_UP_CONTENT_MARGIN_Y                  (20)
	
#elif defined (__MMI_MAINLCD_128X128__)

    /* height of status icon bar */
    #define CFG_UI_STATUS_BAR_HEIGHT                       (16)
    /* y position of status icon bar in idle screen*/
    #define CFG_UI_STATUS_BAR_IDLE_Y                            (0)
    /* height of thin title */
    #define CFG_UI_THIN_TITLE_HEIGHT                       (18)
    /* height of thick title */
    #define CFG_UI_THICK_TITLE_HEIGHT                      (18)
    /* height of button bar*/
    #define CFG_UI_BUTTON_BAR_HEIGHT                       (18)
    /* height of softkey bar*/
    #define CFG_UI_SOFTKEY_BAR_HEIGHT                      (18)
    /* width of left & right softkey */
    #define CFG_UI_SOFTKEY_WIDTH                           (50)
    /* width of center softkey */
    #define CFG_UI_CENTER_SOFTKEY_WIDTH                    (28)
    /* height of softkey */
    #define CFG_UI_SOFTKEY_HEIGHT                          (18)
    /* height of single line menu item */
    #define CFG_UI_MENUITEM_HEIGHT                         (18)
    /* height of two-line menu item*/
    #define CFG_UI_MENUITEM_TWOLINE_HEIGHT                 (36) 
    /* height of multi-row menu item*/
    #define CFG_UI_MENUITEM_MULTIROW_HEIGHT                (39)
    /* height of thick menu item*/
    #define CFG_UI_MENUITEM_THICK_HEIGHT                   (39)
    /* height of thick with tab menu item*/
    #define CFG_UI_MENUITEM_THICK_WITH_TAB_HEIGHT          (33)
    /* width of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_WIDTH                     (108)
    /* height of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_HEIGHT                    (86)
    /* x of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_X                         (10)
    /* y of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_Y                         (21)
    /* full height of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_FULL_HEIGHT               (101)
    /* margin x of pop up content */
    #define CFG_UI_POP_UP_CONTENT_MARGIN_X                  (15)
    /* margin y of pop up content */
    #define CFG_UI_POP_UP_CONTENT_MARGIN_Y                  (15)

#elif defined __MMI_MAINLCD_128X160__

    /* height of status icon bar */
    #define CFG_UI_STATUS_BAR_HEIGHT                       (18)
    /* y position of status icon bar in idle screen*/
    #define CFG_UI_STATUS_BAR_IDLE_Y                        (0)
    /* height of thin title */
    #define CFG_UI_THIN_TITLE_HEIGHT                       (20)
    /* height of thick title */
    #define CFG_UI_THICK_TITLE_HEIGHT                      (38)
    /* height of button bar*/
    #define CFG_UI_BUTTON_BAR_HEIGHT                       (20)
    /* height of softkey bar*/
    #define CFG_UI_SOFTKEY_BAR_HEIGHT                      (20)
    /* width of left & right softkey */
    #define CFG_UI_SOFTKEY_WIDTH                           (50)
    /* width of center softkey */
    #define CFG_UI_CENTER_SOFTKEY_WIDTH                    (28)
    /* height of softkey */
    #define CFG_UI_SOFTKEY_HEIGHT                          (20)
    /* height of single line menu item */
    #define CFG_UI_MENUITEM_HEIGHT                         (17)
    /* height of two-line menu item*/
    #define CFG_UI_MENUITEM_TWOLINE_HEIGHT                 (34) 
    /* height of multi-row menu item*/
    #define CFG_UI_MENUITEM_MULTIROW_HEIGHT                (39)
    /* height of thick menu item*/
    #define CFG_UI_MENUITEM_THICK_HEIGHT                   (39)
    /* height of thick with tab menu item*/
    #define CFG_UI_MENUITEM_THICK_WITH_TAB_HEIGHT          (33)
    /* width of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_WIDTH                     (108)
    /* height of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_HEIGHT                    (116)
    /* x of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_X                         (10)
    /* y of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_Y                         (22)
    /* full height of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_FULL_HEIGHT               (132)
    /* margin x of pop up content */
    #define CFG_UI_POP_UP_CONTENT_MARGIN_X                  (15)
    /* margin y of pop up content */
    #define CFG_UI_POP_UP_CONTENT_MARGIN_Y                  (15)

#elif defined __MMI_MAINLCD_176X220__

    /* height of status icon bar */
    #define CFG_UI_STATUS_BAR_HEIGHT                       (18)
    /* y position of status icon bar in idle screen*/
    #define CFG_UI_STATUS_BAR_IDLE_Y                        (0)
    /* height of thin title */
    #define CFG_UI_THIN_TITLE_HEIGHT                        (24)
    /* height of thick title */
    #define CFG_UI_THICK_TITLE_HEIGHT                      (42)
    /* height of button bar*/
    #define CFG_UI_BUTTON_BAR_HEIGHT                       (20)
    /* height of softkey bar*/
    #define CFG_UI_SOFTKEY_BAR_HEIGHT                      (20)
    /* width of left & right softkey */
    #define CFG_UI_SOFTKEY_WIDTH                           (70)
    /* width of center softkey */
    #define CFG_UI_CENTER_SOFTKEY_WIDTH                    (30)
    /* height of softkey */
    #define CFG_UI_SOFTKEY_HEIGHT                          (20)
    /* height of single line menu item */
    #define CFG_UI_MENUITEM_HEIGHT                         (22)
    /* height of two-line menu item*/
    #define CFG_UI_MENUITEM_TWOLINE_HEIGHT                 (44) 
    /* height of multi-row menu item*/
    #define CFG_UI_MENUITEM_MULTIROW_HEIGHT                (39)
    /* height of thick menu item*/
    #define CFG_UI_MENUITEM_THICK_HEIGHT                   (39)
    /* height of thick with tab menu item*/
    #define CFG_UI_MENUITEM_THICK_WITH_TAB_HEIGHT          (35)
    /* width of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_WIDTH                     (136)
#ifdef __MMI_BASIC_UI_STYLE__
    /* height of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_HEIGHT                    (95)
#else
    #define CFG_UI_POP_UP_DIALOG_HEIGHT                    (138)
#endif
    /* x of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_X                         (20)
    /* y of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_Y                         (52)
#ifdef __MMI_BASIC_UI_STYLE__
    /* full height of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_FULL_HEIGHT               (95)
#else
    /* full height of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_FULL_HEIGHT               (138)
#endif
    /* margin x of pop up content */
    #define CFG_UI_POP_UP_CONTENT_MARGIN_X                  (20)
    /* margin y of pop up content */
    #define CFG_UI_POP_UP_CONTENT_MARGIN_Y                  (20)

#elif defined (__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X240__)
    #ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
    /* height of status icon bar */
    #define CFG_UI_STATUS_BAR_HEIGHT                       (24)
    #elif defined __MMI_FTE_SUPPORT__
    /* height of status icon bar */
    #define CFG_UI_STATUS_BAR_HEIGHT                       (20)
    #else
    /* height of status icon bar */
    #define CFG_UI_STATUS_BAR_HEIGHT                       (18)
    #endif /* __MMI_FTE_SUPPORT__ */
    /* y position of status icon bar in idle screen*/
    #define CFG_UI_STATUS_BAR_IDLE_Y                        (0)
    #ifdef __MMI_FTE_SUPPORT__
    /* height of thin title */
    #define CFG_UI_THIN_TITLE_HEIGHT                       (34)
    #else
    /* height of thin title */
    #define CFG_UI_THIN_TITLE_HEIGHT                       (36)
    #endif /* __MMI_FTE_SUPPORT__ */
    /* height of thin title */
    #define CFG_UI_THICK_TITLE_HEIGHT                      (50)
#ifdef __MMI_FTE_SUPPORT__
    /* height of button bar*/
    #define CFG_UI_BUTTON_BAR_HEIGHT                       (38)    
#else
    /* height of button bar*/
    #define CFG_UI_BUTTON_BAR_HEIGHT                       (24)
#endif /* __MMI_FTE_SUPPORT__ */
#ifdef __MMI_FTE_SUPPORT__
    /* height of softkey bar*/
    #define CFG_UI_SOFTKEY_BAR_HEIGHT                      (38)
#else /* __MMI_FTE_SUPPORT__ */
    /* height of softkey bar*/
    #define CFG_UI_SOFTKEY_BAR_HEIGHT                      (24)
#endif /* __MMI_FTE_SUPPORT__ */
#ifdef  __MMI_FTE_SUPPORT__
    /* height of icon bar*/
    #define CFG_UI_ICON_BAR_HEIGHT                         (38)
#endif /* __MMI_FTE_SUPPORT__ */
#ifdef __MMI_FTE_SUPPORT__
    /* width of left & right softkey */
    #define CFG_UI_SOFTKEY_WIDTH                           (120)
#else /* __MMI_FTE_SUPPORT__ */
    /* width of left & right softkey */
    #define CFG_UI_SOFTKEY_WIDTH                           (84)
#endif /* __MMI_FTE_SUPPORT__ */
#ifdef __MMI_FTE_SUPPORT__
    /* width of center softkey */
    #define CFG_UI_CENTER_SOFTKEY_WIDTH                    (0)
#else /* __MMI_FTE_SUPPORT__ */
    /* width of center softkey */
    #define CFG_UI_CENTER_SOFTKEY_WIDTH                    (70)
#endif /* __MMI_FTE_SUPPORT__ */
#ifdef __MMI_FTE_SUPPORT__
    /* height of softkey */
    #define CFG_UI_SOFTKEY_HEIGHT                          (38)
#else /* __MMI_FTE_SUPPORT__ */
    /* height of softkey */
    #define CFG_UI_SOFTKEY_HEIGHT                          (24)
#endif /* __MMI_FTE_SUPPORT__ */
#ifdef __MMI_FTE_SUPPORT__
    /* height of single menu item */
    #define CFG_UI_MENUITEM_HEIGHT                         (38)
    /* height of two-line menu item*/
    #define CFG_UI_MENUITEM_TWOLINE_HEIGHT                 (76) 
    /* height of multi-row menu item*/
    #define CFG_UI_MENUITEM_MULTIROW_HEIGHT                (47)
    /* height of thick menu item*/
    #define CFG_UI_MENUITEM_THICK_HEIGHT                   (57)
    /* height of thick with tab menu item*/
    #define CFG_UI_MENUITEM_THICK_WITH_TAB_HEIGHT          (57)
#else /* __MMI_FTE_SUPPORT__ */
    /* height of single menu item */
    #define CFG_UI_MENUITEM_HEIGHT                         (30)
    /* height of two-line menu item*/
    #define CFG_UI_MENUITEM_TWOLINE_HEIGHT                 (60) 
    /* height of multi-row menu item*/
    #define CFG_UI_MENUITEM_MULTIROW_HEIGHT                (48)
    /* height of thick menu item*/
    #define CFG_UI_MENUITEM_THICK_HEIGHT                   (60)
    /* height of thick with tab menu item*/
    #define CFG_UI_MENUITEM_THICK_WITH_TAB_HEIGHT          (55)
#endif /* __MMI_FTE_SUPPORT__ */
    /* width of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_WIDTH                     (216)
    /* height of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_HEIGHT                    (200)
    /* x of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_X                         (12)
    /* y of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_Y                         (74)
    /* full height of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_FULL_HEIGHT               (200)
    /* margin x of pop up content */
    #define CFG_UI_POP_UP_CONTENT_MARGIN_X                  (20)
    /* margin y of pop up content */
    #define CFG_UI_POP_UP_CONTENT_MARGIN_Y                  (20)
#elif defined __MMI_MAINLCD_240X400__
    #ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
    /* height of status icon bar */
    #define CFG_UI_STATUS_BAR_HEIGHT                       (24)
    #elif defined __MMI_FTE_SUPPORT__
    /* height of status icon bar */
    #define CFG_UI_STATUS_BAR_HEIGHT                       (20)
    #else
    /* height of status icon bar */
    #define CFG_UI_STATUS_BAR_HEIGHT                       (20)
    #endif /* __MMI_FTE_SUPPORT__ */
    /* y position of status icon bar in idle screen*/
    #define CFG_UI_STATUS_BAR_IDLE_Y                        (0)
    #ifdef __MMI_FTE_SUPPORT__
    /* height of thin title */
    #define CFG_UI_THIN_TITLE_HEIGHT                       (42)
    #else
    /* height of thin title */
    #define CFG_UI_THIN_TITLE_HEIGHT                       (46)
    #endif /* __MMI_FTE_SUPPORT__ */
    /* height of thin title */
    #define CFG_UI_THICK_TITLE_HEIGHT                      (46)
#ifdef __MMI_FTE_SUPPORT__
    /* height of button bar*/
    #define CFG_UI_BUTTON_BAR_HEIGHT                       (44)
#else /* __MMI_FTE_SUPPORT__ */
    /* height of button bar*/
    #define CFG_UI_BUTTON_BAR_HEIGHT                       (30)
#endif /* __MMI_FTE_SUPPORT__ */
#ifdef __MMI_FTE_SUPPORT__
   /* height of softkey bar*/
    #define CFG_UI_SOFTKEY_BAR_HEIGHT                      (44)
#else /* __MMI_FTE_SUPPORT__ */ 
   /* height of softkey bar*/
    #define CFG_UI_SOFTKEY_BAR_HEIGHT                      (30)
#endif /* __MMI_FTE_SUPPORT__ */
#ifdef __MMI_FTE_SUPPORT__
    /* height of icon bar*/
    #define CFG_UI_ICON_BAR_HEIGHT                         (42)
#endif /* __MMI_FTE_SUPPORT__ */
#ifdef __MMI_FTE_SUPPORT__
    /* width of left & right softkey */
    #define CFG_UI_SOFTKEY_WIDTH                           (120)
#else /* __MMI_FTE_SUPPORT__ */
    /* width of left & right softkey */
    #define CFG_UI_SOFTKEY_WIDTH                           (84)
#endif /* __MMI_FTE_SUPPORT__ */
#ifdef __MMI_FTE_SUPPORT__
    /* width of center softkey */
    #define CFG_UI_CENTER_SOFTKEY_WIDTH                    (0)
#else /* __MMI_FTE_SUPPORT__ */
    /* width of center softkey */
    #define CFG_UI_CENTER_SOFTKEY_WIDTH                    (70)
#endif /* __MMI_FTE_SUPPORT__ */
#ifdef __MMI_FTE_SUPPORT__
    /* height of softkey */
    #define CFG_UI_SOFTKEY_HEIGHT                          (44)
#else /* __MMI_FTE_SUPPORT__ */
    /* height of softkey */
    #define CFG_UI_SOFTKEY_HEIGHT                          (30)
#endif /* __MMI_FTE_SUPPORT__ */
#ifdef __MMI_FTE_SUPPORT__
    /* height of single menu item */
    #define CFG_UI_MENUITEM_HEIGHT                         (42)
    /* height of two-line menu item*/
    #define CFG_UI_MENUITEM_TWOLINE_HEIGHT                 (84) 
    /* height of multi-row menu item*/
    #define CFG_UI_MENUITEM_MULTIROW_HEIGHT                (62)
    /* height of thick menu item*/
    #define CFG_UI_MENUITEM_THICK_HEIGHT                   (59)
    /* height of thick with tab menu item*/
    #define CFG_UI_MENUITEM_THICK_WITH_TAB_HEIGHT          (59)
#else /* __MMI_FTE_SUPPORT__ */
    /* height of single line menu item */
    #define CFG_UI_MENUITEM_HEIGHT                         (38)
    /* height of two-line menu item*/
    #define CFG_UI_MENUITEM_TWOLINE_HEIGHT                 (76) 
    /* height of multi-row menu item*/
    #define CFG_UI_MENUITEM_MULTIROW_HEIGHT                (50)
    /* height of thick menu item*/
    #define CFG_UI_MENUITEM_THICK_HEIGHT                   (76)
    /* height of thick with tab menu item*/
    #define CFG_UI_MENUITEM_THICK_WITH_TAB_HEIGHT          (47)
#endif /* __MMI_FTE_SUPPORT__ */
    /* width of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_WIDTH                     (195)
    /* height of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_HEIGHT                    (216)
    /* x of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_X                         (23)
    /* y of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_Y                         (110)
    /* full height of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_FULL_HEIGHT               (216)
    /* margin x of pop up content */
    #define CFG_UI_POP_UP_CONTENT_MARGIN_X                  (20)
    /* margin y of pop up content */
    #define CFG_UI_POP_UP_CONTENT_MARGIN_Y                  (20)
    
#elif defined __MMI_MAINLCD_320X240__
#ifdef __MMI_FTE_SUPPORT__
    #define CFG_UI_STATUS_BAR_HEIGHT                       (18)
#else
    /* height of status icon bar */
    #define CFG_UI_STATUS_BAR_HEIGHT                       (36)
#endif
    /* y position of status icon bar in idle screen*/
    #define CFG_UI_STATUS_BAR_IDLE_Y                        (0)
#ifdef __MMI_FTE_SUPPORT__
    #define CFG_UI_THIN_TITLE_HEIGHT                       (34)
#else
    /* height of thin title */
    #define CFG_UI_THIN_TITLE_HEIGHT                       (36)
#endif
    /* height of thin title */
    #define CFG_UI_THICK_TITLE_HEIGHT                      (50)
#ifdef __MMI_FTE_SUPPORT__
    /* height of button bar*/
    #define CFG_UI_BUTTON_BAR_HEIGHT                       (36)
    /* height of softkey bar*/
    #define CFG_UI_SOFTKEY_BAR_HEIGHT                      (36)
#else
    /* height of button bar*/
    #define CFG_UI_BUTTON_BAR_HEIGHT                       (28)
    /* height of softkey bar*/
    #define CFG_UI_SOFTKEY_BAR_HEIGHT                      (28)
#endif
    /* width of left & right softkey */
    #define CFG_UI_SOFTKEY_WIDTH                           (130)
    /* width of center softkey */
    #define CFG_UI_CENTER_SOFTKEY_WIDTH                    (60)
#ifdef __MMI_FTE_SUPPORT__
    /* height of softkey */
    #define CFG_UI_SOFTKEY_HEIGHT                          (36)
    /* height of single menu item */
    #define CFG_UI_MENUITEM_HEIGHT                         (38)
    /* height of two-line menu item*/
    #define CFG_UI_MENUITEM_TWOLINE_HEIGHT                 (50) 
    /* height of multi-row menu item*/
    #define CFG_UI_MENUITEM_MULTIROW_HEIGHT                (47)
    /* height of thick menu item*/
    #define CFG_UI_MENUITEM_THICK_HEIGHT                   (57)
    /* height of thick with tab menu item*/
    #define CFG_UI_MENUITEM_THICK_WITH_TAB_HEIGHT          (57)
#else
    /* height of softkey */
    #define CFG_UI_SOFTKEY_HEIGHT                          (28)
    /* height of single line menu item */
    #define CFG_UI_MENUITEM_HEIGHT                         (29)
    /* height of two-line menu item*/
    #define CFG_UI_MENUITEM_TWOLINE_HEIGHT                 (58) 
    /* height of multi-row menu item*/
    #define CFG_UI_MENUITEM_MULTIROW_HEIGHT                (48)
    /* height of thick menu item*/
    #define CFG_UI_MENUITEM_THICK_HEIGHT                   (60)
    /* height of thick with tab menu item*/
    #define CFG_UI_MENUITEM_THICK_WITH_TAB_HEIGHT          (50)
#endif
    /* width of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_WIDTH                     (240)
    /* height of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_HEIGHT                    (172)
    /* x of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_X                         (40)
    /* y of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_Y                         (38)
    /* full height of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_FULL_HEIGHT               (172)
    /* margin x of pop up content */
    #define CFG_UI_POP_UP_CONTENT_MARGIN_X                  (10)
    /* margin y of pop up content */
    #define CFG_UI_POP_UP_CONTENT_MARGIN_Y                  (2)
#ifdef  __MMI_FTE_SUPPORT__
    /* height of icon bar*/
    #define CFG_UI_ICON_BAR_HEIGHT                         (38)
#endif /* __MMI_FTE_SUPPORT__ */

#elif defined __MMI_MAINLCD_320X480__ || defined(__MMI_MAINLCD_360X640__)
    #ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
    /* height of status icon bar */
    #define CFG_UI_STATUS_BAR_HEIGHT                       (24)
    #elif defined __MMI_FTE_SUPPORT__
    /* height of status icon bar */
    #define CFG_UI_STATUS_BAR_HEIGHT                       (20)
    #else
    /* height of status icon bar */
    #define CFG_UI_STATUS_BAR_HEIGHT                       (20)
    #endif /* __MMI_FTE_SUPPORT__ */
    /* y position of status icon bar in idle screen*/
    #define CFG_UI_STATUS_BAR_IDLE_Y                        (0)
    #ifdef __MMI_FTE_SUPPORT__
    /* height of thin title */
    #define CFG_UI_THIN_TITLE_HEIGHT                       (52)
    #else
    /* height of thin title */
    #define CFG_UI_THIN_TITLE_HEIGHT                       (44)
    #endif /* __MMI_FTE_SUPPORT__ */
    /* height of thin title */
    #define CFG_UI_THICK_TITLE_HEIGHT                      (44)
#ifdef __MMI_FTE_SUPPORT__
    /* height of button bar*/
    #define CFG_UI_BUTTON_BAR_HEIGHT                       (51)
#else /* __MMI_FTE_SUPPORT__ */
    /* height of button bar*/
    #define CFG_UI_BUTTON_BAR_HEIGHT                       (36)
#endif /* __MMI_FTE_SUPPORT__ */
#ifdef __MMI_FTE_SUPPORT__
    /* height of softkey bar*/
    #define CFG_UI_SOFTKEY_BAR_HEIGHT                      (51)
#else /* __MMI_FTE_SUPPORT__ */
    /* height of softkey bar*/
    #define CFG_UI_SOFTKEY_BAR_HEIGHT                      (36)
#endif /* __MMI_FTE_SUPPORT__ */
#ifdef __MMI_FTE_SUPPORT__
    /* height of icon bar*/
    #define CFG_UI_ICON_BAR_HEIGHT                         (51)
#endif /* __MMI_FTE_SUPPORT__ */
#ifdef __MMI_FTE_SUPPORT__
    /* width of left & right softkey */
    #define CFG_UI_SOFTKEY_WIDTH                           (160)
#else /* __MMI_FTE_SUPPORT__ */
    /* width of left & right softkey */
    #define CFG_UI_SOFTKEY_WIDTH                           (129)
#endif /* __MMI_FTE_SUPPORT__ */
#ifdef __MMI_FTE_SUPPORT__
    /* width of center softkey */
    #define CFG_UI_CENTER_SOFTKEY_WIDTH                    (0)
#else /* __MMI_FTE_SUPPORT__ */
    /* width of center softkey */
    #define CFG_UI_CENTER_SOFTKEY_WIDTH                    (60)
#endif /* __MMI_FTE_SUPPORT__ */
#ifdef __MMI_FTE_SUPPORT__
    /* height of softkey */
    #define CFG_UI_SOFTKEY_HEIGHT                          (51)
#else /* __MMI_FTE_SUPPORT__ */
    /* height of softkey */
    #define CFG_UI_SOFTKEY_HEIGHT                          (36)
#endif /* __MMI_FTE_SUPPORT__ */
#ifdef __MMI_FTE_SUPPORT__
    /* height of single menu item */
    #define CFG_UI_MENUITEM_HEIGHT                         (51)
    /* height of two-line menu item*/
    #define CFG_UI_MENUITEM_TWOLINE_HEIGHT                 (102) 
    /* height of multi-row menu item*/
    #define CFG_UI_MENUITEM_MULTIROW_HEIGHT                (76)
    /* height of thick menu item*/
    #define CFG_UI_MENUITEM_THICK_HEIGHT                   (71)
    /* height of thick with tab menu item*/
    #define CFG_UI_MENUITEM_THICK_WITH_TAB_HEIGHT          (71)
#else /* __MMI_FTE_SUPPORT__ */
    /* height of single line menu item */
    #define CFG_UI_MENUITEM_HEIGHT                         (47)
    /* height of two-line menu item*/
    #define CFG_UI_MENUITEM_TWOLINE_HEIGHT                 (94) 
    /* height of multi-row menu item*/
    #define CFG_UI_MENUITEM_MULTIROW_HEIGHT                (76)
    /* height of thick menu item*/
    #define CFG_UI_MENUITEM_THICK_HEIGHT                   (63)
    /* height of thick with tab menu item*/
    #define CFG_UI_MENUITEM_THICK_WITH_TAB_HEIGHT          (58)
#endif /* __MMI_FTE_SUPPORT__ */
    /* width of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_WIDTH                     (320)
    /* height of pop up dialog */
#ifdef __MMI_FTE_SUPPORT__
    #define CFG_UI_POP_UP_DIALOG_HEIGHT                     (250)
#else
    #define CFG_UI_POP_UP_DIALOG_HEIGHT                    (280)
#endif
    /* x of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_X                         (0)
    /* y of pop up dialog */
#ifdef __MMI_FTE_SUPPORT__
    #define CFG_UI_POP_UP_DIALOG_Y                         (179)
#else
    #define CFG_UI_POP_UP_DIALOG_Y                         (200)
#endif
    /* full height of pop up dialog */
#ifdef __MMI_FTE_SUPPORT__
    #define CFG_UI_POP_UP_DIALOG_FULL_HEIGHT               (250)
#else
    #define CFG_UI_POP_UP_DIALOG_FULL_HEIGHT               (280)
#endif
    /* margin x of pop up content */
    #define CFG_UI_POP_UP_CONTENT_MARGIN_X                  (10)
    /* margin y of pop up content */
    #define CFG_UI_POP_UP_CONTENT_MARGIN_Y                  (2)
#elif defined(__MMI_MAINLCD_480X800__)
    #ifdef __MMI_FTE_SUPPORT__
    /* height of status icon bar */
    #define CFG_UI_STATUS_BAR_HEIGHT                       (38)
    #else
    /* height of status icon bar */
    #define CFG_UI_STATUS_BAR_HEIGHT                       (38)
    #endif /* __MMI_FTE_SUPPORT__ */
    /* y position of status icon bar in idle screen*/
    #define CFG_UI_STATUS_BAR_IDLE_Y                        (0)
    #ifdef __MMI_FTE_SUPPORT__
    /* height of thin title */
    #define CFG_UI_THIN_TITLE_HEIGHT                       (45)
    #else
    /* height of thin title */
    #define CFG_UI_THIN_TITLE_HEIGHT                       (45)
    #endif /* __MMI_FTE_SUPPORT__ */
    /* height of thin title */
    #define CFG_UI_THICK_TITLE_HEIGHT                      (45)
#ifdef __MMI_FTE_SUPPORT__
    /* height of button bar*/
    #define CFG_UI_BUTTON_BAR_HEIGHT                       (85)
#else /* __MMI_FTE_SUPPORT__ */
    /* height of button bar*/
    #define CFG_UI_BUTTON_BAR_HEIGHT                       (85)
#endif /* __MMI_FTE_SUPPORT__ */
#ifdef __MMI_FTE_SUPPORT__
    /* height of softkey bar*/
    #define CFG_UI_SOFTKEY_BAR_HEIGHT                      (85)
#else /* __MMI_FTE_SUPPORT__ */
    /* height of softkey bar*/
    #define CFG_UI_SOFTKEY_BAR_HEIGHT                      (85)
#endif /* __MMI_FTE_SUPPORT__ */
#ifdef __MMI_FTE_SUPPORT__
    /* height of icon bar*/
    #define CFG_UI_ICON_BAR_HEIGHT                         (89)
#endif /* __MMI_FTE_SUPPORT__ */
#ifdef __MMI_FTE_SUPPORT__
    /* width of left & right softkey */
    #define CFG_UI_SOFTKEY_WIDTH                           (240)
#else /* __MMI_FTE_SUPPORT__ */
    /* width of left & right softkey */
    #define CFG_UI_SOFTKEY_WIDTH                           (240)
#endif /* __MMI_FTE_SUPPORT__ */
#ifdef __MMI_FTE_SUPPORT__
    /* width of center softkey */
    #define CFG_UI_CENTER_SOFTKEY_WIDTH                    (0)
#else /* __MMI_FTE_SUPPORT__ */
    /* width of center softkey */
    #define CFG_UI_CENTER_SOFTKEY_WIDTH                    (0)
#endif /* __MMI_FTE_SUPPORT__ */
#ifdef __MMI_FTE_SUPPORT__
    /* height of softkey */
    #define CFG_UI_SOFTKEY_HEIGHT                          (85)
#else /* __MMI_FTE_SUPPORT__ */
    /* height of softkey */
    #define CFG_UI_SOFTKEY_HEIGHT                          (85)
#endif /* __MMI_FTE_SUPPORT__ */
#ifdef __MMI_FTE_SUPPORT__
    /* height of single menu item */
    #define CFG_UI_MENUITEM_HEIGHT                         (86)
    /* height of two-line menu item*/
    #define CFG_UI_MENUITEM_TWOLINE_HEIGHT                 (172) 
    /* height of multi-row menu item*/
    #define CFG_UI_MENUITEM_MULTIROW_HEIGHT                (172)
    /* height of thick menu item*/
    #define CFG_UI_MENUITEM_THICK_HEIGHT                   (172)
    /* height of thick with tab menu item*/
    #define CFG_UI_MENUITEM_THICK_WITH_TAB_HEIGHT          (172)
#else /* __MMI_FTE_SUPPORT__ */
    /* height of single line menu item */
    #define CFG_UI_MENUITEM_HEIGHT                         (85)
    /* height of two-line menu item*/
    #define CFG_UI_MENUITEM_TWOLINE_HEIGHT                 (94) 
    /* height of multi-row menu item*/
    #define CFG_UI_MENUITEM_MULTIROW_HEIGHT                (76)
    /* height of thick menu item*/
    #define CFG_UI_MENUITEM_THICK_HEIGHT                   (63)
    /* height of thick with tab menu item*/
    #define CFG_UI_MENUITEM_THICK_WITH_TAB_HEIGHT          (58)
#endif /* __MMI_FTE_SUPPORT__ */
    /* width of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_WIDTH                     (320)
    /* height of pop up dialog */
#ifdef __MMI_FTE_SUPPORT__
    #define CFG_UI_POP_UP_DIALOG_HEIGHT                     (250)
#else
    #define CFG_UI_POP_UP_DIALOG_HEIGHT                    (280)
#endif
    /* x of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_X                         (0)
    /* y of pop up dialog */
#ifdef __MMI_FTE_SUPPORT__
    #define CFG_UI_POP_UP_DIALOG_Y                         (179)
#else
    #define CFG_UI_POP_UP_DIALOG_Y                         (200)
#endif
    /* full height of pop up dialog */
#ifdef __MMI_FTE_SUPPORT__
    #define CFG_UI_POP_UP_DIALOG_FULL_HEIGHT               (250)
#else
    #define CFG_UI_POP_UP_DIALOG_FULL_HEIGHT               (280)
#endif
    /* margin x of pop up content */
    #define CFG_UI_POP_UP_CONTENT_MARGIN_X                  (10)
    /* margin y of pop up content */
    #define CFG_UI_POP_UP_CONTENT_MARGIN_Y                  (2)

#else
    #error "No UI Style is Specified!!"
#endif

#if defined(__MMI_FTE_SUPPORT__)

    #define CFG_UI_SCROLLBAR_WIDTH          6
    
#elif defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)

    #define CFG_UI_SCROLLBAR_WIDTH          25
    
#elif defined(__MMI_MAINLCD_240X400__)
    #if defined(__MMI_UI_SCROLLBAR_DEFAULT_STYLE_5__)
        #define CFG_UI_SCROLLBAR_WIDTH          13
    #elif defined(__MMI_TOUCH_SCREEN__)        
        #define CFG_UI_SCROLLBAR_WIDTH          21
    #else
        #define CFG_UI_SCROLLBAR_WIDTH          10
    #endif
#elif (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__))
	#if defined(__MMI_UI_SCROLLBAR_DEFAULT_STYLE_5__)
		#define CFG_UI_SCROLLBAR_WIDTH          13
    #elif defined(__MMI_TOUCH_SCREEN__)
        #define CFG_UI_SCROLLBAR_WIDTH          16
    #elif defined(__MMI_OP12_SCROLLBAR_STYLE__)
        #define CFG_UI_SCROLLBAR_WIDTH          12
    #else
        #define CFG_UI_SCROLLBAR_WIDTH          10
    #endif
#elif defined(__MMI_MAINLCD_176X220__)
	#if defined(__MMI_UI_SCROLLBAR_DEFAULT_STYLE_5__)
		#define CFG_UI_SCROLLBAR_WIDTH          8
    #elif defined(__MMI_TOUCH_SCREEN__)
        #define CFG_UI_SCROLLBAR_WIDTH          14
    #elif defined(__MMI_OP12_SCROLLBAR_STYLE__)
        #define CFG_UI_SCROLLBAR_WIDTH          10
    #else
        #define CFG_UI_SCROLLBAR_WIDTH          8
    #endif
#elif (defined(__MMI_MAINLCD_128X160__) && defined(__MMI_TOUCH_SCREEN__))
    #define CFG_UI_SCROLLBAR_WIDTH              11
#else 
    #define CFG_UI_SCROLLBAR_WIDTH              6
#endif 

#if defined(__MMI_FTE_SUPPORT__)
    #if defined(__MMI_MAINLCD_240X320__)
        #define CFG_UI_SCROLLBAR_WIDER_WIDTH    (22)
    #elif defined(__MMI_MAINLCD_240X400__)
        #define CFG_UI_SCROLLBAR_WIDER_WIDTH    (24)
    #elif defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
        #define CFG_UI_SCROLLBAR_WIDER_WIDTH    (28)
    #else
        #define CFG_UI_SCROLLBAR_WIDER_WIDTH    (24)
    #endif /* __MMI_MAINLCD_240X320__ */
#endif


/* code added vandana to enable the 4 way navigation key on the softkey background */
/* ISSUE GPRS PPT 6 BOTTOM NAVIAGTION KEYS */
#define CFG_UI_ENABLE_BOTTOM_NAVIGATION_KEYS  (__ON__)

/* Support for two way or four way navigation            */
/* These values should not be changed                 */
#define UI_TWO_WAY_NAVIGATION_KEYS    1
#define UI_FOUR_WAY_NAVIGATION_KEYS    2

/* Support for two way or four way navigation            */
/* Valid values are one of the above navigation types    */
#define CFG_UI_NAVIGATION_KEYS_TYPE        UI_FOUR_WAY_NAVIGATION_KEYS


/* Used by UI_TEXT_MENUITEM_SCROLL_TYPE, don't modify    */
#define UI_TEXT_MENUITEM_SCROLL_TYPE_NONE       0
#define UI_TEXT_MENUITEM_SCROLL_TYPE_MARQUEE    1
#define UI_TEXT_MENUITEM_SCROLL_TYPE_TWO_DIRECTION 2

/* Type of scrolling to use in text menuitems            */
/* Valid values are one of the above symbols          */
#define CFG_UI_TEXT_MENUITEM_SCROLL_TYPE   UI_TEXT_MENUITEM_SCROLL_TYPE_MARQUEE

/* Time for scrolling text in menu items              */
/* Value must be an integer (milliseconds)               */
/* Typical values: 100 to 500                      */
#define  CFG_UI_TEXT_MENUITEM_SCROLL_TIME  350

/* Number of pixels by which the text scrolls            */
/* in menu items.                               */
/* Value must be an integer (units are in pixels)        */
/* Typical values: 1 to 5                          */
#define CFG_UI_TEXT_MENUITEM_SCROLL_SIZE   3

/* For Marquee type text scrolling in menu items, this      */
/* specifies the blank gap that should appear at the end */
/* of the string.                                  */
/* Value must be an integer (units are in pixels)        */
/* Typical values: 16 to 64 (This depends on font size)  */
#define CFG_UI_TEXT_MENUITEM_SCROLL_GAP    32

/* This specifies the delay after which a highlighted item  */
/* will scroll. This is a multiple of                 */
/* UI_TEXT_MENUITEM_SCROLL_TIME                    */
/* Value must be an integer. Typically 1, 2 -- etc.      */
    /* Depends on the value of UI_TEXT_MENUITEM_SCROLL_TIME  */
#define CFG_UI_TEXT_MENUITEM_SCROLL_PAUSE  4

/* gap from the menu X1 to menuitem X1 */
#define CFG_UI_MENUITEM_X1_GAP 1
/* gap from the menu X2 to menuitem X2 */
#define CFG_UI_MENUITEM_X2_GAP 1

/* 
 * text right gap for text, icontext, and two-state menu items 
 *
 * This is ONLY VALID for image highlight enabled list menus because 
 * the right side of the highlight image may have borders or rounded edges.
 *
 * Note: Icontext list menu items should use this GAP to have a consistent behavior.
 *  _____________________
 * | **  THIS IS A TEXT  |
 *  ---------------------
 *                     <-> CFG_UI_MENUITEM_TEXT_RIGHT_GAP
 */
#ifdef __MMI_FTE_SUPPORT__
#define CFG_UI_MENUITEM_TEXT_RIGHT_GAP 6
#else
#define CFG_UI_MENUITEM_TEXT_RIGHT_GAP 3
#endif

/* 
 * menu item icon and text position
 *
 * Menu Item Type       Icon and Text Position
 * =================================================
 * Text                 CFG_UI_TEXT_MENUITEM_TEXT_X
 * Icontext             CFG_UI_ICONTEXT_MENUITEM_ICON_X, CFG_UI_ICONTEXT_MENUITEM_TEXT_X
 * Two-state            CFG_UI_ICONTEXT_MENUITEM_ICON_X, CFG_UI_ICONTEXT_MENUITEM_TEXT_X
 * Icontext List        NONE
 *
 * CAUTION: The coordinate value must be larger than 0.
 */
#if defined(__MMI_FTE_SUPPORT__)
#define CFG_UI_TEXT_MENUITEM_TEXT_X        14   /* text only */
#else
#define CFG_UI_TEXT_MENUITEM_TEXT_X        1   /* text only */
#endif

#if defined(__MMI_FTE_SUPPORT__)
#define CFG_UI_ICONTEXT_MENUITEM_ICON_X    5   /* icon in icon-text */
#elif defined(__MMI_MAINLCD_240X400__)
#define CFG_UI_ICONTEXT_MENUITEM_ICON_X    4   /* icon in icon-text */
#else
#define CFG_UI_ICONTEXT_MENUITEM_ICON_X    1   /* icon in icon-text */
#endif

#if defined(__MMI_FTE_SUPPORT__)
#define CFG_UI_ICONTEXT_MENUITEM_TEXT_X    39  /* text in icon-text */
#else
#define CFG_UI_ICONTEXT_MENUITEM_TEXT_X    (CFG_UI_MENUITEM_HEIGHT + 2)  /* text in icon-text */
#endif

#define CFG_UI_ENABLE_POP_UP_DESCRIPTIONS (__ON__)

/* Used by UI_POP_UP_DESCRIPTION_SCROLL_TYPE, don't modify  */
#define UI_POP_UP_DESCRIPTION_SCROLL_TYPE_NONE           0
#define UI_POP_UP_DESCRIPTION_SCROLL_TYPE_MARQUEE        1
#define UI_POP_UP_DESCRIPTION_SCROLL_TYPE_TWO_DIRECTION     2

/* Type of scrolling to use in Pop up descriptions       */
/* Valid values are one of the above symbols          */
#define CFG_UI_POP_UP_DESCRIPTION_SCROLL_TYPE UI_POP_UP_DESCRIPTION_SCROLL_TYPE_MARQUEE

#define CFG_UI_CURSOR_WAIT_TIME            (1000)
#define CFG_UI_CURSOR_BLINK_TIME           (500)

/*----------------------------------------------------------------*/
/* Slider                                                         */
/*----------------------------------------------------------------*/ 
/*
 *                      UI_SLIDER_X1_GAP
 *                          <--> 
 *                              --
 *  Slider Background Image <--|##|--------------->
 *                              --
 *                         Slider Button 
 *                         at the LEFTEST position
 *
 *
 *                                          UI_SLIDER_X2_GAP
 *                                              <-> 
 *                                            -- 
 *  Slider Background Image <----------------|##|->
 *                                            -- 
 *                                       Slider Button 
 *                                       at the RIGHTEST position
 *
 */

/* 
 * the left gap from the slider button to the slider background image
 * This value depends on the background image style, e.g. round-rected or bordered.
 */
#ifndef __MMI_FTE_SUPPORT__

#define CFG_UI_SLIDER_X1_GAP    2

/* 
 * the right gap from the slider button to the slider background image
 * This value depends on the background image style, e.g. round-rected or bordered.
 */
#define CFG_UI_SLIDER_X2_GAP    2

/*
 *  TEXT LABEL            
 *          ^ 
 *          | <- GUI_SLIDE_CONTROL_TEXT_LABEL_TO_FOCUS_GAP (at least 1)
 *  ________v_____________    
 * |  __________________  | | <- GUI_SLIDE_CONTROL_FOCUS_GAP (the 1-pixel rectangle is included.)
 * | |     SLIDER       | |
 * | |__________________| |
 * |______________________|<- FOCUS Rectangle
 *
 */
#define CFG_UI_SLIDE_CONTROL_FOCUS_GAP                  (2)
#define CFG_UI_SLIDE_CONTROL_TEXT_LABEL_TO_FOCUS_GAP    (2)
#define CFG_UI_SLIDE_TEXT_X_GAP                         (0)

#else /* __MMI_FTE_SUPPORT__ */
    #define CFG_UI_SLIDER_X1_GAP                            (4)
    #define CFG_UI_SLIDER_X2_GAP                            (4)
    #define CFG_UI_SLIDE_CONTROL_FOCUS_GAP                  (2)
    #define CFG_UI_SLIDE_CONTROL_TEXT_LABEL_TO_FOCUS_GAP    (3) 
    #define CFG_UI_SLIDE_TEXT_X_GAP                         (2) /* add this macro for FTE */
#endif  /* __MMI_FTE_SUPPORT__ */


/* shortcut */
#define CFG_UI_SHORTCUT_WIDTH              (30)          /* default wdith of shortcut */
#define CFG_UI_SHORTCUT_GAP                (8)           /* default GAP of shortcut */

#if defined(__MMI_MAINLCD_240X320__)  || defined(__MMI_MAINLCD_240X400__)  || defined(__MMI_MAINLCD_320X240__) 
    #define CFG_UI_SHORTCUT_TEXT_BORDER_X_GAP  (5)           /* gap of border text */
#else 
    #define CFG_UI_SHORTCUT_TEXT_BORDER_X_GAP  (2)           /* gap of border text */
#endif 

#define CFG_UI_SHORTCUT_INSERT_GAP         (2)           /* gap between normal mode and insert mode */     


/* title */
#define CFG_UI_TITLE_NON_ICON_GAP          (2)           /* gap between text area and title area */
#if defined(__MMI_MAINLCD_320X240__) 
    #define CFG_UI_TITLE_ICON_GAP          (3)           /* gap between text area and icon area */
#elif defined(__MMI_MAINLCD_128X160__)
    #define CFG_UI_TITLE_ICON_GAP          (0)           /* gap between text area and icon area */
#else
    #define CFG_UI_TITLE_ICON_GAP          (1)           /* gap between text area and icon area */
#endif
#define CFG_UI_TITLE_TEXT_GAP              (2)           /* gap between text width and text area */
#define CFG_UI_TITLE_SCROLLING_GAP         (4)           /* gap between scrolling area and title area */

#define CFG_UI_TITLE_SCROLLING_INIT_X      (-2)          /* init x of scrolling */
#define CFG_UI_TITLE_SCROLLING_INIT_Y      (0)           /* init y of scrolling */
#define CFG_UI_TITLE_SCROLLING_INIT_WIDTH  (0)           /* init width of scrolling */
#define CFG_UI_TITLE_SCROLLING_INIT_HEIGHT (0)           /* init height of scrolling */
#define CFG_UI_TITLE_SCROLLING_ICON_X      (1)           /* left position of icon*/

#if defined(__MMI_MAINLCD_320X240__)
#ifdef __MMI_FTE_SUPPORT__
#define CFG_UI_SOFTKEY_GAP                  (10)			/* gap between softkey and edge */
#else
#define CFG_UI_SOFTKEY_GAP                  (36)			/* gap between softkey and edge */
#endif
#elif defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
#ifdef __MMI_FTE_SUPPORT__
#define CFG_UI_SOFTKEY_GAP                  (10)                  /* gap between softkey and edge */
#else
#define CFG_UI_SOFTKEY_GAP                  (25)                  /* gap between softkey and edge */
#endif
#elif defined(__MMI_FTE_SUPPORT__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__))
#define CFG_UI_SOFTKEY_GAP                  (6)			/* gap between softkey and edge */
#else
#define CFG_UI_SOFTKEY_GAP                  (2)			/* gap between softkey and edge */
#endif

#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
#define CFG_UI_STATUSBAR_GAP                (4)			/* gap between status icon and edge */
#else
    #if defined(__MMI_FWUI_SLIM__)
    #define CFG_UI_STATUSBAR_GAP                (3)			/* gap between status icon and edge */
    #else
    #define CFG_UI_STATUSBAR_GAP                (0)			/* gap between status icon and edge */
    #endif
#endif

#if defined(__MMI_ANIMATED_DIAL__)
    #define __MMI_ANIM_DIAL_KEYIN_ANIMATION__  
    #define __MMI_ANIM_DIAL_CURSOR_ANIMATION__
    #define __MMI_ANIM_DIAL_CLEAR_ANIMATION__ 

    #if defined(__MMI_ANIM_DIAL_KEYIN_ANIMATION__) && defined(__MMI_MAINLCD_176X220__)
        #define __MMI_ANIM_DIAL_KEYIN_ANIMATION_ANIM_SYTLE__
    #elif defined(__MMI_ANIM_DIAL_KEYIN_ANIMATION__) && defined(__MMI_MAINLCD_240X320__)
        #define __MMI_ANIM_DIAL_KEYIN_ANIMATION_FLYIN_SYTLE__
    #elif defined(__MMI_ANIM_DIAL_KEYIN_ANIMATION__)
        #define __MMI_ANIM_DIAL_KEYIN_ANIMATION_ANIM_SYTLE__
    #endif    
#endif /* __MMI_ANIMATED_DIAL__ */

/* static calendar on idle screen */
#if defined (__MMI_CALENDAR_ON_IDLE_SCREEN__)
    #if defined (__MMI_MAINLCD_240X400__)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_X           (40)
        #if defined(__MMI_SEARCH_WEB__)
            #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_Y           (162)
        #else
            #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_Y           (178)
        #endif
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_WIDTH       (156)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_HEIGHT      (133)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_TITLE_HEIGHT            (24)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_X        (44)
        #if defined(__MMI_SEARCH_WEB__)
            #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_Y        (192)
        #else
            #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_Y        (208)
        #endif
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_WIDTH    (148)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_HEIGHT   (11)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_X            (45)
        #if defined(__MMI_SEARCH_WEB__)
            #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_Y            (202)
        #else
            #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_Y            (218)
        #endif
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_WIDTH        (146)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_HEIGHT       (83)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_X                (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_Y                (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_WIDTH            (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_HEIGHT           (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_HORIZONTAL_GAP   (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_VERTICAL_GAP     (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_X                (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_Y                (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_WIDTH            (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_HEIGHT           (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_TITLE_Y                  (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_TITLE_HEIGHT             (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_X         (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_Y         (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_WIDTH     (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_HEIGHT    (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_X             (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_Y             (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_WIDTH         (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_HEIGHT        (0)
    #elif defined (__MMI_MAINLCD_240X320__)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_X           (40)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_Y           (98)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_WIDTH       (156)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_HEIGHT      (133)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_TITLE_HEIGHT            (24)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_X        (44)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_Y        (128)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_WIDTH    (148)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_HEIGHT   (11)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_X            (45)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_Y            (138)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_WIDTH        (146)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_HEIGHT       (83)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_X                (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_Y                (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_WIDTH            (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_HEIGHT           (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_HORIZONTAL_GAP   (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_VERTICAL_GAP     (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_X                (58)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_Y                (179)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_WIDTH            (173)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_HEIGHT           (63)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_TITLE_Y                  (184)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_TITLE_HEIGHT             (20)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_X         (71)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_Y         (207)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_WIDTH     (146)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_HEIGHT    (34)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_X             (71)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_Y             (223)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_WIDTH         (146)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_HEIGHT        (0)
    #elif defined (__MMI_MAINLCD_320X240__)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_X           (40)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_Y           (78)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_WIDTH       (156)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_HEIGHT      (133)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_TITLE_HEIGHT            (24)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_X        (44)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_Y        (108)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_WIDTH    (148)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_HEIGHT   (11)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_X            (45)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_Y            (118)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_WIDTH        (146)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_HEIGHT       (83)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_X                (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_Y                (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_WIDTH            (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_HEIGHT           (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_HORIZONTAL_GAP   (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_VERTICAL_GAP     (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_X                (57)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_Y                (179)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_WIDTH            (174)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_HEIGHT           (63)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_TITLE_Y                  (184)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_TITLE_HEIGHT             (20)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_X         (57)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_Y         (207)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_WIDTH     (174)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_HEIGHT    (34)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_X             (57)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_Y             (223)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_WIDTH         (174)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_HEIGHT        (0)
    #elif defined (__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_X           (69)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_Y           (103)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_WIDTH       (182)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_HEIGHT      (154)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_TITLE_HEIGHT            (30)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_X        (74)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_Y        (138)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_WIDTH    (174)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_HEIGHT   (11)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_X            (74)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_Y            (151)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_WIDTH        (174)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_HEIGHT       (95)       
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_X                (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_Y                (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_WIDTH            (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_HEIGHT           (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_HORIZONTAL_GAP   (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_VERTICAL_GAP     (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_X                (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_Y                (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_WIDTH            (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_HEIGHT           (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_TITLE_Y                  (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_TITLE_HEIGHT             (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_X         (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_Y         (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_WIDTH     (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_HEIGHT    (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_X             (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_Y             (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_WIDTH         (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_HEIGHT        (0)
    #elif defined (__MMI_MAINLCD_176X220__)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_X           (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_Y           (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_WIDTH       (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_HEIGHT      (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_TITLE_HEIGHT            (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_X        (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_Y        (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_WIDTH    (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_HEIGHT   (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_X            (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_Y            (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_WIDTH        (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_HEIGHT       (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_X                (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_Y                (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_WIDTH            (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_HEIGHT           (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_HORIZONTAL_GAP   (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_VERTICAL_GAP     (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_X                (41)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_Y                (120)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_WIDTH            (120)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_HEIGHT           (47)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_TITLE_Y                  (121)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_TITLE_HEIGHT             (15)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_X         (42)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_Y         (136)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_WIDTH     (118)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_HEIGHT    (30)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_X             (42)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_Y             (151)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_WIDTH         (118)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_HEIGHT        (0)
    #elif defined (__MMI_MAINLCD_128X160__)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_X           (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_Y           (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_WIDTH       (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_FRAME_START_HEIGHT      (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_TITLE_HEIGHT            (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_X        (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_Y        (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_WIDTH    (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_HORIZON_STRING_HEIGHT   (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_X            (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_Y            (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_WIDTH        (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_CELL_ARRAY_HEIGHT       (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_X                (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_Y                (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_WIDTH            (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_HEIGHT           (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_HORIZONTAL_GAP   (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_MONTH_DETAIL_VERTICAL_GAP     (0)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_X                (31)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_Y                (89)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_WIDTH            (92)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CONTENT_HEIGHT           (34)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_TITLE_Y                  (89)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_TITLE_HEIGHT             (11)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_X         (32)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_Y         (100)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_WIDTH     (90)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_HORIZON_STRING_HEIGHT    (21)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_X             (32)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_Y             (110)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_WIDTH         (90)
        #define CFG_UI_IDLE_STATIC_CALENDAR_WEEK_CELL_ARRAY_HEIGHT        (0)
    #else /* __MMI_MAINLCD_240X400__ */
        #error "No Static calendar UI Style is Specified!!"
    #endif /* __MMI_MAINLCD_240X400__ */
#endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */

#if defined(__MMI_SEARCH_WEB__)
   #if defined(__MMI_MAINLCD_240X400__)
       #define CFG_UI_IDLE_STATIC_SEARCH_START_Y                         (297)
       #define CFG_UI_IDLE_STATIC_SEARCH_IMAGE_STRING_GAP                 (10)
   #elif defined(__MMI_MAINLCD_240X320__)
       #if !defined(__MMI_CALENDAR_ON_IDLE_SCREEN__)
       #define CFG_UI_IDLE_STATIC_SEARCH_START_Y                         (162)
       #define CFG_UI_IDLE_STATIC_SEARCH_IMAGE_STRING_GAP                 (10)
       #else
       #define CFG_UI_IDLE_STATIC_SEARCH_START_Y                         (244)
       #define CFG_UI_IDLE_STATIC_SEARCH_IMAGE_STRING_GAP                 (10)
       #endif
   #elif defined(__MMI_MAINLCD_320X240__)
       #if (defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__) && !defined(__MMI_CALENDAR_ON_IDLE_SCREEN__))
       #define CFG_UI_IDLE_STATIC_SEARCH_START_Y                         (143)
       #define CFG_UI_IDLE_STATIC_SEARCH_IMAGE_STRING_GAP                 (10)
       #else
       #define CFG_UI_IDLE_STATIC_SEARCH_START_Y                         (156)
       #define CFG_UI_IDLE_STATIC_SEARCH_IMAGE_STRING_GAP                 (10)
       #endif
   #elif defined(__MMI_MAINLCD_128X160__)
       #define CFG_UI_IDLE_STATIC_SEARCH_START_Y                         (88)
       #define CFG_UI_IDLE_STATIC_SEARCH_IMAGE_STRING_GAP                 (3)
   #elif defined(__MMI_MAINLCD_176X220__) 
       #define CFG_UI_IDLE_STATIC_SEARCH_START_Y                         (128)
       #define CFG_UI_IDLE_STATIC_SEARCH_IMAGE_STRING_GAP                 (3)
   #elif defined(__MMI_MAINLCD_320X480__)
       #define CFG_UI_IDLE_STATIC_SEARCH_START_Y                         (128)
       #define CFG_UI_IDLE_STATIC_SEARCH_IMAGE_STRING_GAP                 (3)
   #else
       #define CFG_UI_IDLE_STATIC_SEARCH_START_Y                         (128)
       #define CFG_UI_IDLE_STATIC_SEARCH_IMAGE_STRING_GAP                 (3)
   #endif
#endif /* __MMI_SEARCH_WEB__ */

#define CFG_UI_LIST_TRUNCATE_ITEM               (__ON__)

#if defined (__MMI_MAINLCD_320X480__) || defined (__MMI_FTE_SUPPORT__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
#define CFG_UI_LIST_GRID_LINE                   (__ON__)
#else
#define CFG_UI_LIST_GRID_LINE                   (__OFF__)
#endif

#endif /* __GUI_SWITCH_H__ */

