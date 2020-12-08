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
 *  wgui_categories_IMPS.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  IMPS related categories. 
 *
 *  [Category420]       About Me Screen
 *  [Category425]       Contact List Screen (also used by PoC)
 *  [Category435]       Chat Screen with Popup Editor
 *
 *
 *  TTY related categories.
 *  [Category430]       Chat Log Screen 
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "MMI_features.h"

#include "ScreenRotationGprot.h"
#include "lcd_sw_rnd.h"

#if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) || defined(__MMI_SMART_MESSAGE_MT__)
#include "MyPicture.h"
#endif 

#include "wgui_fixed_menuitems.h"
#include "wgui_asyncdynamic_menus.h"

#include "wgui_tab_bars.h"
#include "gui_font_size.h"
#include "MMIDataType.h"
#include "gui_theme_struct.h"
#include "wgui.h"
#include "FontRes.h"
#include "gui_data_types.h"
#include "gdi_datatype.h"
#include "wgui_categories_IMPS.h"
#include "CustThemesRes.h"
#include "gui_typedef.h"
#include "wgui_tree.h"
#include "gui_windows.h"
#include "gui_inputs.h"
#include "gui.h"
#include "gui_themes.h"
#include "PixcomFontEngine.h"
#include "gui_switch.h"
#include "gui_config.h"
#include "CustDataRes.h"
#include "gdi_include.h"
#include "mmi_frm_mem_gprot.h"
#include "DebugInitDef_Int.h"
#include "gdi_const.h"
#include "wgui_inputs.h"
#include "gui_scrollbars.h"
#include "gui_fixed_menuitems.h"
#include "wgui_fixed_menus.h"
#include "gui_fixed_menus.h"
#include "lcd_sw_inc.h"
#include "Gui_Setting.h"
#include "wgui_draw_manager.h"
#include "mmi_frm_input_gprot.h"
#include "wgui_touch_screen.h"
#include "wgui_categories_enum.h"
#include "wgui_categories_util.h"
#include "GlobalConstants.h"
#include "ImeGprot.h"
#include "wgui_categories_popup.h"
#include "wgui_include.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_title.h"
#include "gui_title_pre_oem.h"
#include "gui_menu_shortcut.h"
#include "wgui_asyncdynamic_menuitems.h"
#include "gui_tab_bars_pre_oem.h"
#include "string.h"
#include "wgui_categories_inputs.h"
extern S32 gui_asyncdynamic_list_error;
extern BOOL r2lMMIFlag;
extern UI_ime_theme *current_ime_theme;

/***************************************************************************** 
* Customizable Definitions
*****************************************************************************/
/* 
 * Category 420 
 */
#define CAT420_TEXT_COLOR_R                  64
#define CAT420_TEXT_COLOR_G                  64
#define CAT420_TEXT_COLOR_B                  64

#define CAT420_LINE_COLOR_R                  144
#define CAT420_LINE_COLOR_G                  104
#define CAT420_LINE_COLOR_B                  48

/* 
 * Category 425
 */
#if defined(__MMI_MAINLCD_240X320__)|| defined(__MMI_MAINLCD_240X400__)

#define CAT425_ICON_BORDER_COLOR_R           187
#define CAT425_ICON_BORDER_COLOR_G           227
#define CAT425_ICON_BORDER_COLOR_B           254

#define CAT425_ICON_HIGHLIGHT_BORDER_COLOR_R          128
#define CAT425_ICON_HIGHLIGHT_BORDER_COLOR_G          0
#define CAT425_ICON_HIGHLIGHT_BORDER_COLOR_B          0

// #define CAT425_TEXT1_COLOR_R                                         230
// #define CAT425_TEXT1_COLOR_G                                         230
// #define CAT425_TEXT1_COLOR_B                                         230

// #define CAT425_TEXT2_COLOR_R                                         148
// #define CAT425_TEXT2_COLOR_G                                         188
// #define CAT425_TEXT2_COLOR_B                                         220

// #define CAT425_TEXT1_HIGHLIGHT_COLOR_R                               255
// #define CAT425_TEXT1_HIGHLIGHT_COLOR_G                               255
// #define CAT425_TEXT1_HIGHLIGHT_COLOR_B                               255

// #define CAT425_TEXT2_HIGHLIGHT_COLOR_R                               255
// #define CAT425_TEXT2_HIGHLIGHT_COLOR_G                               255
// #define CAT425_TEXT2_HIGHLIGHT_COLOR_B                               106

#define CAT425_TEXT2_BRACKET_COLOR_R         187
#define CAT425_TEXT2_BRACKET_COLOR_G         227
#define CAT425_TEXT2_BRACKET_COLOR_B         254

#define CAT425_LINE_COLOR_R                  192
#define CAT425_LINE_COLOR_G                  192
#define CAT425_LINE_COLOR_B                  192

#else /* defined(__MMI_MAINLCD_240X320__)|| defined(__MMI_MAINLCD_240X400__) */ 

#define CAT425_ICON_BORDER_COLOR_R           0
#define CAT425_ICON_BORDER_COLOR_G           56
#define CAT425_ICON_BORDER_COLOR_B           136

#define CAT425_ICON_HIGHLIGHT_BORDER_COLOR_R          128
#define CAT425_ICON_HIGHLIGHT_BORDER_COLOR_G          0
#define CAT425_ICON_HIGHLIGHT_BORDER_COLOR_B          0

#define CAT425_TEXT1_COLOR_R                 72
#define CAT425_TEXT1_COLOR_G                 72
#define CAT425_TEXT1_COLOR_B                 72

#define CAT425_TEXT2_COLOR_R                 48
#define CAT425_TEXT2_COLOR_G                 88
#define CAT425_TEXT2_COLOR_B                 120

#define CAT425_TEXT1_HIGHLIGHT_COLOR_R          255
#define CAT425_TEXT1_HIGHLIGHT_COLOR_G          255
#define CAT425_TEXT1_HIGHLIGHT_COLOR_B          255

#define CAT425_TEXT2_HIGHLIGHT_COLOR_R          255
#define CAT425_TEXT2_HIGHLIGHT_COLOR_G          255
#define CAT425_TEXT2_HIGHLIGHT_COLOR_B          106

#define CAT425_TEXT2_BRACKET_COLOR_R         56
#define CAT425_TEXT2_BRACKET_COLOR_G         112
#define CAT425_TEXT2_BRACKET_COLOR_B         200

#define CAT425_LINE_COLOR_R                  142
#define CAT425_LINE_COLOR_G                  142
#define CAT425_LINE_COLOR_B                  142

#endif /* defined(__MMI_MAINLCD_240X320__)|| defined(__MMI_MAINLCD_240X400__) */ 

/* 
 * Category 428
 */
#if defined(__MMI_MAINLCD_128X160__)

#define CAT428_DEFAULT_ICON_WIDTH            26
#define CAT428_DEFAULT_ICON_HEIGHT           26
#define CAT428_DEFAULT_ICON2_WIDTH           10
#define CAT428_DEFAULT_ICON2_HEIGHT          10
#define CAT428_ICON_TEXT_GAP                 4
#define CAT428_TEXT_SCROLLBAR_GAP            2

#elif defined(__MMI_MAINLCD_176X220__)

#define CAT428_DEFAULT_ICON_WIDTH            32
#define CAT428_DEFAULT_ICON_HEIGHT           32
#define CAT428_DEFAULT_ICON2_WIDTH           10
#define CAT428_DEFAULT_ICON2_HEIGHT          10
#define CAT428_ICON_TEXT_GAP                 4
#define CAT428_TEXT_SCROLLBAR_GAP            4

#else 

#define CAT428_DEFAULT_ICON_WIDTH            40
#define CAT428_DEFAULT_ICON_HEIGHT           42
#define CAT428_DEFAULT_ICON2_WIDTH           10
#define CAT428_DEFAULT_ICON2_HEIGHT          10
#define CAT428_ICON_TEXT_GAP                 6
#define CAT428_TEXT_SCROLLBAR_GAP            4

#endif 

#define CAT428_TEXT1_COLOR_R                 72
#define CAT428_TEXT1_COLOR_G                 72
#define CAT428_TEXT1_COLOR_B                 72

#define CAT428_TEXT1_HIGHLIGHT_COLOR_R          255
#define CAT428_TEXT1_HIGHLIGHT_COLOR_G          255
#define CAT428_TEXT1_HIGHLIGHT_COLOR_B          255

/* 
 * Category 429
 */
#if defined(__MMI_MAINLCD_128X128__)
#define CAT429_TOP_MARGIN                    2
#define CAT429_LEFT_MARGIN                   5
#define CAT429_IMAGE_RIGHT_MARGIN        2
#define CAT429_IMAGE_BOTTOM_MARGIN        2
#define CAT429_IMAGE_DEFAULT_WIDTH          25
#define CAT429_IMAGE_DEFAULT_HEIGHT        28
#define CAT429_STRING_WIDTH                    50
#define CAT429_TEXT_TEXT_GAP                  2
#elif defined(__MMI_MAINLCD_128X160__)
#define CAT429_TOP_MARGIN                    2
#define CAT429_LEFT_MARGIN                   5
#define CAT429_IMAGE_RIGHT_MARGIN        2
#define CAT429_IMAGE_BOTTOM_MARGIN        2
#define CAT429_IMAGE_DEFAULT_WIDTH          30
#define CAT429_IMAGE_DEFAULT_HEIGHT         30
#define CAT429_STRING_WIDTH                    50
#define CAT429_TEXT_TEXT_GAP                  2
#elif defined(__MMI_MAINLCD_176X220__)
#define CAT429_TOP_MARGIN                    2
#define CAT429_LEFT_MARGIN                   5
#define CAT429_IMAGE_RIGHT_MARGIN        2
#define CAT429_IMAGE_BOTTOM_MARGIN        2
#define CAT429_IMAGE_DEFAULT_WIDTH          41
#define CAT429_IMAGE_DEFAULT_HEIGHT         41
#define CAT429_STRING_WIDTH                    60
#define CAT429_TEXT_TEXT_GAP                  2
#elif defined(__MMI_MAINLCD_240X320__)
#define CAT429_TOP_MARGIN                    4
#define CAT429_LEFT_MARGIN                   5
#define CAT429_IMAGE_RIGHT_MARGIN        5
#define CAT429_IMAGE_BOTTOM_MARGIN        2
#define CAT429_IMAGE_DEFAULT_WIDTH          52
#define CAT429_IMAGE_DEFAULT_HEIGHT         52
#define CAT429_STRING_WIDTH                    70
#define CAT429_TEXT_TEXT_GAP                  2
#elif defined(__MMI_MAINLCD_320X240__)
#define CAT429_TOP_MARGIN                    2
#define CAT429_LEFT_MARGIN                   5
#define CAT429_IMAGE_RIGHT_MARGIN        2
#define CAT429_IMAGE_BOTTOM_MARGIN        2
#define CAT429_IMAGE_DEFAULT_WIDTH          52
#define CAT429_IMAGE_DEFAULT_HEIGHT         52
#define CAT429_STRING_WIDTH                    80
#define CAT429_TEXT_TEXT_GAP                  2
#else
#define CAT429_TOP_MARGIN                    2
#define CAT429_LEFT_MARGIN                   5
#define CAT429_IMAGE_RIGHT_MARGIN        2
#define CAT429_IMAGE_BOTTOM_MARGIN        2
#define CAT429_IMAGE_DEFAULT_WIDTH          50
#define CAT429_IMAGE_DEFAULT_HEIGHT         50
#define CAT429_STRING_WIDTH                    70
#define CAT429_TEXT_TEXT_GAP                  2
#endif
#define CAT429_CONTROLLED_AREA_HEIGHT  2*MMI_MENUITEM_HEIGHT
#define CAT429_LINE_COLOR_R                  144
#define CAT429_LINE_COLOR_G                  104
#define CAT429_LINE_COLOR_B                  48

/* 
 * Category 430
 */

#define CAT430_NAME1_COLOR_R                 107
#define CAT430_NAME1_COLOR_G                 93
#define CAT430_NAME1_COLOR_B                 247

#define CAT430_NAME2_COLOR_R                 231
#define CAT430_NAME2_COLOR_G                 77
#define CAT430_NAME2_COLOR_B                 198

#define CAT430_NAME_FONT_ENUM                MEDIUM_FONT
#define CAT430_NAME_FONT                     (&MMI_medium_font)

#define CAT430_SENT_COLOR_MARKER             GUI_INPUT_COLOR_BLACK

/* Marker length in sending box, we use two color code */
#define CAT430_MARKER_COUNT                  2


/* 
 * Category 435
 */

#define CAT435_POPUP_X                       (MMI_content_x)
#define CAT435_POPUP_WIDTH                   (MMI_CONTENT_WIDTH_WITH_H_TAB)

#if defined(__MMI_MAINLCD_128X64__)

#ifdef __MMI_TOUCH_SCREEN__
/* Virtual keyboard takes more space */
#define CAT435_POPUP_Y                       (MMI_CONTENT_Y_WITH_H_TAB)
#define CAT435_POPUP_HEIGHT                  (MMI_CONTENT_HEIGHT_WITH_H_TAB)
#undef CAT435_SHOW_LOG_BOX_WITH_POPUP
#else /* __MMI_TOUCH_SCREEN__ */ 
#define CAT435_POPUP_Y                       (MMI_CONTENT_Y_WITH_H_TAB + (MMI_CONTENT_HEIGHT_WITH_H_TAB /5))
#define CAT435_POPUP_HEIGHT                  (MMI_CONTENT_HEIGHT_WITH_H_TAB - (MMI_CONTENT_HEIGHT_WITH_H_TAB /5))
#define CAT435_SHOW_LOG_BOX_WITH_POPUP
#endif /* __MMI_TOUCH_SCREEN__ */ 

#define CAT435_POPUP_WITH_BORDER_TITLE
/* Title height in popup */
#define CAT435_POPUP_TITLE_HEIGHT            30
/* Bottom gap between editor and multitap */
#define CAT435_POPUP_BOTTOM_GAP              0  /* HACK. 0 for ZI input method */
/* Horizontal gap */
#define CAT435_POPUP_H_GAP                   0  /* HACK. 0 for ZI input method */


#elif defined(__MMI_MAINLCD_128X128__)

#define CAT435_POPUP_OVERLAP_TAB_BAR         1

#define CAT435_POPUP_Y                       (MMI_CONTENT_Y_WITH_H_TAB - 12)
#define CAT435_POPUP_HEIGHT                  (MMI_CONTENT_HEIGHT_WITH_H_TAB + 12)
/* Title height in popup */
#define CAT435_POPUP_TITLE_HEIGHT            6
#undef CAT435_SHOW_LOG_BOX_WITH_POPUP
#undef CAT435_POPUP_WITH_BORDER_TITLE
/* Bottom gap between editor and multitap */
#define CAT435_POPUP_BOTTOM_GAP              0  /* HACK. 0 for ZI input method */
/* Horizontal gap */
#define CAT435_POPUP_H_GAP                   0  /* HACK. 0 for ZI input method */

#elif defined(__MMI_MAINLCD_128X160__)

#define CAT435_POPUP_OVERLAP_TAB_BAR         1

#ifdef __MMI_TOUCH_SCREEN__
#define CAT435_POPUP_Y                       (MMI_CONTENT_Y_WITH_H_TAB - MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT + 6)
#define CAT435_POPUP_HEIGHT                  (MMI_CONTENT_HEIGHT_WITH_H_TAB + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT - 6)
/* Title height in popup */
#define CAT435_POPUP_TITLE_HEIGHT            6
#else /* __MMI_TOUCH_SCREEN__ */
#define CAT435_POPUP_Y                       (MMI_CONTENT_Y_WITH_H_TAB)
#define CAT435_POPUP_HEIGHT                  (MMI_CONTENT_HEIGHT_WITH_H_TAB)
/* Title height in popup */
#define CAT435_POPUP_TITLE_HEIGHT            6
#endif /* __MMI_TOUCH_SCREEN__ */
#undef CAT435_SHOW_LOG_BOX_WITH_POPUP
#undef CAT435_POPUP_WITH_BORDER_TITLE
/* Bottom gap between editor and multitap */
#define CAT435_POPUP_BOTTOM_GAP              0  /* HACK. 0 for ZI input method */
/* Horizontal gap */
#define CAT435_POPUP_H_GAP                   0  /* HACK. 0 for ZI input method */

#elif defined(__MMI_MAINLCD_176X220__)

#undef CAT435_POPUP_OVERLAP_TAB_BAR

#ifdef __MMI_TOUCH_SCREEN__
/* Virtual keyboard takes more space */
#define CAT435_POPUP_Y                       (MMI_CONTENT_Y_WITH_H_TAB - 4)
#define CAT435_POPUP_HEIGHT                  (MMI_CONTENT_HEIGHT_WITH_H_TAB + 4)
#undef CAT435_SHOW_LOG_BOX_WITH_POPUP
#else /* __MMI_TOUCH_SCREEN__ */ 
#define CAT435_POPUP_Y                       (MMI_CONTENT_Y_WITH_H_TAB + (MMI_CONTENT_HEIGHT_WITH_H_TAB /5))
#define CAT435_POPUP_HEIGHT                  (MMI_CONTENT_HEIGHT_WITH_H_TAB - (MMI_CONTENT_HEIGHT_WITH_H_TAB /5))
#define CAT435_SHOW_LOG_BOX_WITH_POPUP
#endif /* __MMI_TOUCH_SCREEN__ */ 

#define CAT435_POPUP_WITH_BORDER_TITLE
/* Title height in popup */
#define CAT435_POPUP_TITLE_HEIGHT            19
/* Bottom gap between editor and multitap */
#define CAT435_POPUP_BOTTOM_GAP              0  /* HACK. 0 for ZI input method */
/* Horizontal gap */
#define CAT435_POPUP_H_GAP                   0  /* HACK. 0 for ZI input method */


#elif defined(__MMI_MAINLCD_320X240__)

#define CAT435_POPUP_OVERLAP_TAB_BAR         1

#ifdef __MMI_TOUCH_SCREEN__
#define CAT435_POPUP_Y                       (MMI_CONTENT_Y_WITH_H_TAB - MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT)
#define CAT435_POPUP_HEIGHT                  (MMI_CONTENT_HEIGHT_WITH_H_TAB + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT)
#else /* __MMI_TOUCH_SCREEN__ */
#define CAT435_POPUP_Y                       (MMI_CONTENT_Y_WITH_H_TAB - 6)
#define CAT435_POPUP_HEIGHT                  (MMI_CONTENT_HEIGHT_WITH_H_TAB + 6)
#endif /* __MMI_TOUCH_SCREEN__ */

#undef CAT435_SHOW_LOG_BOX_WITH_POPUP
#undef CAT435_POPUP_WITH_BORDER_TITLE
/* Title height in popup */
#define CAT435_POPUP_TITLE_HEIGHT            5
/* Bottom gap between editor and multitap */
#define CAT435_POPUP_BOTTOM_GAP              0  /* HACK. 0 for ZI input method */
/* Horizontal gap */
#define CAT435_POPUP_H_GAP                   0  /* HACK. 0 for ZI input method */


#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)

#ifdef __MMI_TOUCH_SCREEN__
/* Virtual keyboard takes more space */
#define CAT435_POPUP_Y                       (MMI_CONTENT_Y_WITH_H_TAB)
#define CAT435_POPUP_HEIGHT                  (MMI_CONTENT_HEIGHT_WITH_H_TAB)
#undef CAT435_SHOW_LOG_BOX_WITH_POPUP
#else /* __MMI_TOUCH_SCREEN__ */ 
#define CAT435_POPUP_Y                       (MMI_CONTENT_Y_WITH_H_TAB + (MMI_CONTENT_HEIGHT_WITH_H_TAB /5))
#define CAT435_POPUP_HEIGHT                  (MMI_CONTENT_HEIGHT_WITH_H_TAB - (MMI_CONTENT_HEIGHT_WITH_H_TAB /5))
#define CAT435_SHOW_LOG_BOX_WITH_POPUP
#endif /* __MMI_TOUCH_SCREEN__ */ 

#define CAT435_POPUP_WITH_BORDER_TITLE
/* Title height in popup */
#define CAT435_POPUP_TITLE_HEIGHT            30
/* Bottom gap between editor and multitap */
#define CAT435_POPUP_BOTTOM_GAP              0  /* HACK. 0 for ZI input method */
/* Horizontal gap */
#define CAT435_POPUP_H_GAP                   0  /* HACK. 0 for ZI input method */

#else
#error "Unsupported LCD size."
#endif 

#define CAT435_BACKGROUND_WHITE_VALUE        (80)

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/* 
 * Category 420 
 */
typedef struct
{
    /* Data */
    UI_string_type name;
    U16 mood_caption;
    UI_string_type mood_string;
    PU8 mood_icon;
    U16 status_caption;
    UI_string_type status_string;
    PU8 status_icon;
    S16 image_ori_width, image_ori_height;
    /* Image cache */
    U32 display_image:1;
    U32 image_is_cached:1;
    gdi_handle cache_layer;
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    U8 *cache_buf_ptr;
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */

    /* Layout */
    S16 content_width;
    S16 editor_header_height;

    S16 name_x, name_y, name_width;
    S16 line_x1, line_x2, line_y;

    S16 mood_caption_x, mood_caption_y;
    S16 mood_image_x, mood_image_y;
#ifdef CAT420_DISP_INFO_TEXT
    S16 mood_text_x, mood_text_y;
#endif 

    S16 status_caption_x, status_caption_y;
    S16 status_image_x, status_image_y;
#ifdef CAT420_DISP_INFO_TEXT
    S16 status_text_x, status_text_y;
#endif 

    S16 image_area_x, image_area_y;
    S16 image_area_width, image_area_height;

    S16 image_x_offset, image_y_offset;
    S16 image_resized_width, image_resized_height;  /* 0 if no resize */

} gui_cat420_context_struct;

/* 
 * Category 425
 */
typedef struct
{
    U32 backup_menu_flags;
    UI_filled_area *backup_menu_filler;

    S16 icon_border_x1, icon_border_y1, icon_border_x2, icon_border_y2;
    S16 bracket_x, bracket_y;

    S16 num_tab;
    S32 content_x, content_y, content_width, content_height;

    /* For RefreshCategory425Screen */
    GetAsyncItemFuncPtr get_item_func;
    GetAsyncHintFuncPtr get_hint_func;
} gui_cat425_context_struct;

/* 
 * Category 428
 */
typedef struct
{
    wgui_tree_get_item_level_callback_funcptr_type get_level_funcptr;    
    wgui_tree_get_item_state_callback_funcptr_type get_state_funcptr;
    checkbox_clicked_funcptr_type clicked_checkbox_callback; 
    checkbox_get_image_funcptr_type get_checkbox_image_callback;

    S32 n_items;

    S16 num_tab;
    S32 content_x, content_y, content_width, content_height;
	UI_string_type information;
    PU8 info_image;
} gui_cat_tree_context_struct;

static scrolling_text imps_scroll_text;


/* 
 * Category 429 
 */
typedef struct
{
    /* Data */
    UI_string_type name;                /* User name */
    UI_string_type userid;              /* User id */
    UI_string_type mood_caption;    /* User mood string */
    PU8 mood_icon;              /* User mood icon */
    PU8 status_icon;            /* User status icon */
    UI_string_type device_caption;      /* User device caption */
    UI_string_type device_string;       /* User device string */

    U32 display_image:1;
    /* Layout */
    S16 content_width;
    S16 editor_header_height;

    S16 name_x, name_y, name_width;
    S16 userid_x, userid_y, userid_width;

    S16 mood_caption_x, mood_caption_y;
    S16 mood_image_x, mood_image_y;

    S16 status_image_x, status_image_y;
    S16 status_image_width, status_image_height;

    S16 device_caption_x, device_caption_y;
    S16 device_string_x, device_string_y;

    S16 image_area_x, image_area_y;
    S16 image_area_width, image_area_height;
    S16 image_ori_width, image_ori_height;
    S16 image_x_offset, image_y_offset;
    S16 image_resized_width, image_resized_height;  /* 0 if no resize */
    S8 *photo_filename;
    PU8 alternative_photo;
    S32 use_alternative_image;
} gui_cat429_context_struct;

/* 
 * Category 430
 */
typedef struct
{
    /* Another input box */
    multi_line_input_box log_box1;
    U8 *allocated_color_buffer;         /* Add color marker */
    /* Data */
    U8 *name1, *name2;
    U8 *log_buffer1;
    U8 *log_buffer2;
    U8 *sending_buffer;
    S16 log_buffer_size1;
    S16 log_buffer_size2;
    S16 max_sending_buffer_size;
    S16 sent_count;
    S16 allocated_color_buffer_size;
    MMI_BOOL show_sending_buffer;
#ifdef __MMI_TOUCH_SCREEN__
    U8 pen_object;                      /* 0: none, 1: log_box1, 2: log_box2 */
#endif 
    /* Layout */
#ifndef CAT430_NAME_IN_LOG
    S16 name1_x, name1_y;
    S16 name2_x, name2_y;
#else /* CAT430_NAME_IN_LOG */ 
    S16 log_box_header_height;
#endif /* CAT430_NAME_IN_LOG */ 
    S16 log_box1_x, log_box1_y;
    S16 log_box1_width, log_box1_height;
    S16 log_box2_x, log_box2_y;
    S16 log_box2_width, log_box2_height;
    S16 log_box2_footer_height;
    S16 sending_box_x, sending_box_y;   /* relative coordinates */
    S16 sending_box_width;
} gui_cat430_context_struct;

typedef struct
{
    S32 dummy;
} gui_cat430_history_header_struct;

/* 
 * Category 435
 */
typedef struct
{
    /* Backup original MMI context */
    color backup_information_bar_color;
    S32 backup_MMI_editor_width, backup_MMI_editor_height;
    /* Log editor box */
    multi_line_input_box log_box;
    UI_filled_area log_box_scrollbar_sbutton_filler;
    /* Category parameters */
    U16 right_softkey;
    U16 right_softkey_icon;
    U16 left_softkey;
    U16 left_softkey_icon;
    U16 editor_right_softkey;
    U16 editor_right_softkey_icon;
    U16 editor_left_softkey;
    U16 editor_left_softkey_icon;
    UI_string_type popup_title;
    /* Softkey handlers */
    void (*editor_LSK_func) (void);
    void (*editor_RSK_func) (void);
    void (*LSK_func) (void);
    void (*RSK_func) (void);
    /* Whether the popup editor is displayed */
    BOOL show_popup;
    /* Data used to setup the popup editor */
    BOOL editor_created;    /* For debug only */
    U32 input_type;
    U8 *buffer;
    S8 icon_height;
    S32 buffer_size;
    multi_line_input_box_icon_hdlr icon_callback;

    U8 backup_information_bar_alpha;
} gui_cat435_context_struct;

typedef struct
{
    U8 show_popup;
    U8 dummy[3];    /* Align to four bytes */
} gui_cat435_history_header_struct;

/***************************************************************************** 
* Local Variable
*****************************************************************************/

/* 
 * Category 420 
 */
static gui_cat420_context_struct *g_mmi_gui_cat420_context_p;

#define CAT420_CTX         (g_mmi_gui_cat420_context_p)

static const U8 g_mmi_gui_cat420_line_style[] = {1, 1, 1, 0, 1, 0};

static UI_filled_area g_mmi_gui_cat420_text_filler = {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_BORDER,
    NULL,
    NULL,
    {200, 248, 232, 100},
    {0, 0, 0, 0},
    {80, 136, 80, 0},
    {0, 0, 0, 0},
    0
};

static UI_filled_area g_mmi_gui_cat420_bg_filler = {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_TYPE_NO_BORDER,
    NULL,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

/* 
 * Category 425
 */
static gui_cat425_context_struct *g_mmi_gui_cat425_context_p;

#define CAT425_CTX         (g_mmi_gui_cat425_context_p)


static const U8 g_mmi_gui_cat425_line_bitvalues[] = {1, 1, 0};

/* 
 * Category 428
 */
static gui_cat_tree_context_struct *g_mmi_gui_cat_tree_context_p;

#define CAT_TREE_CTX         (g_mmi_gui_cat_tree_context_p)

/* 
 * Category 429
 */

static gui_cat429_context_struct *g_mmi_gui_cat429_context_p;
static scrolling_text scroll_text_cat429;

#define CAT429_CTX         (g_mmi_gui_cat429_context_p)

/* 
 * Category 430
 */

static const color g_mmi_gui_cat430_editor_text_color = {0, 0, 0, 100};

static gui_cat430_context_struct *g_mmi_gui_cat430_context_p;

#define CAT430_CTX         (g_mmi_gui_cat430_context_p)

static const UI_filled_area g_mmi_gui_cat430_logbox_filler = 
{
    UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_BORDER,
    NULL,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {33, 28, 140, 100},
    {0, 0, 0, 0},
    0
};

static const UI_filled_area g_mmi_gui_cat430_sending_filler = 
{
    UI_FILLED_AREA_TYPE_COLOR,
    NULL,
    NULL,
    {225, 220, 225, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

/* 
 * Category 435
 */
static gui_cat435_context_struct *g_mmi_gui_cat435_context_p;

#define CAT435_CTX         (g_mmi_gui_cat435_context_p)

static const UI_filled_area g_mmi_gui_cat435_editor_filler = 
{
#ifdef __MMI_TOUCH_SCREEN__
    UI_FILLED_AREA_TYPE_COLOR,  /* No border due to virtual keyboard */
#else 
    UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_BORDER,
#endif 
    NULL,
    NULL,
    {255, 254, 209, 100},
    {0, 0, 0, 0},
    {184, 184, 184, 100},
    {0, 0, 0, 0},
    0
};
static const color g_mmi_gui_cat435_editor_text_color = {0, 0, 0, 100};


static const color g_mmi_gui_cat435_popup_color = {216, 208, 200, 100};

#if defined (__MMI_WALLPAPER_ON_BOTTOM__)
static U8 editor_scr_bg_opacity;
#endif /* defined (__MMI_WALLPAPER_ON_BOTTOM__) */ 

#define WGUI_CATIMPS_BG_IMG_OPACITY     50
#define WGUI_CATIMPS_BG_IMG_TXT_COLOR   gui_color(0, 0, 0)
static U8* g_wgui_catimps_bg_img_name = NULL;

static HILITE_STR *g_wgui_cat435_hilite_list = NULL;
static U16 g_wgui_cat435_number_of_hilite_list = 0;
static U16 g_wgui_cat435_current_hilite_index = 0;
static void (*g_wgui_cat435_hilite_cb)(S32 idx) = NULL;
static void (*g_wgui_cat435_hilite_click_cb)(S32 idx) = NULL;
static void (*g_wgui_cat435_text_lengh_changed_hdlr)(S32 text_length) = NULL;
static void wgui_cat435_validation_hdlr(
    PU8 dial_string,
    PU8 cursor_position,
    S32 length);
/***************************************************************************** 
* Local Function
*****************************************************************************/

/* 
 * Category 420 
 */


/*****************************************************************************
 * FUNCTION
 *  category420_compute_layout
 * DESCRIPTION
 *  compute layout
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void category420_compute_layout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sw, sh; /* string width/height */
    S32 iw, ih; /* image width/height */
    S32 cw;     /* content width */
    S32 line_height, tmp_y;
    S32 img_left_bound, img_left_lower_bound;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cw = CAT420_CTX->content_width = UI_device_width - current_MMI_theme->scrollbar_size;

    gui_set_font(&MMI_medium_font);

    /* Name */
    Get_StringWidthHeight((U8*) CAT420_CTX->name, &sw, &sh);
    if (sw > UI_device_width - (CAT420_LINE_EXTRA_PIXEL << 1))
    {
        sw = UI_device_width - (CAT420_LINE_EXTRA_PIXEL << 1);
    }
    CAT420_CTX->name_x = (cw - sw) >> 1;
    CAT420_CTX->name_y = CAT420_TOP_MARGIN;
    CAT420_CTX->name_width = sw;

    CAT420_CTX->line_x1 = CAT420_CTX->name_x - CAT420_LINE_EXTRA_PIXEL;
    CAT420_CTX->line_x2 = CAT420_CTX->name_x + sw + CAT420_LINE_EXTRA_PIXEL - 1;
    if (CAT420_CTX->line_x1 < CAT420_LEFT_MARGIN)
    {
        CAT420_CTX->line_x1 = CAT420_LEFT_MARGIN;
    }
    if (CAT420_CTX->line_x2 >= cw)
    {
        CAT420_CTX->line_x2 = cw - 1;
    }
    CAT420_CTX->line_y = CAT420_CTX->name_y + sh + CAT420_NAME_LINE_V_SPACING;

    img_left_lower_bound = 0;

    /* Mood */
#ifdef CAT420_DISP_INFO_TEXT
    tmp_y = CAT420_CTX->line_y + CAT420_LINE_IMAGE_V_SPACING;
    Get_StringWidthHeight((U8*) GetString(CAT420_CTX->mood_caption), &sw, &sh);
    gui_measure_image(CAT420_CTX->mood_icon, &iw, &ih);
    CAT420_CTX->mood_caption_x = CAT420_LEFT_MARGIN;
    CAT420_CTX->mood_image_x = CAT420_CTX->mood_caption_x + sw + CAT420_CAPTION_IMAGE_H_SPACING;
    line_height = sh > ih ? sh : ih;
    CAT420_CTX->mood_caption_y = tmp_y + ((line_height - sh) >> 1);
    CAT420_CTX->mood_image_y = tmp_y + ((line_height - ih) >> 1);
    if (CAT420_CTX->mood_image_x + iw > img_left_lower_bound)
    {
        img_left_lower_bound = CAT420_CTX->mood_image_x + iw;
    }
    Get_StringWidthHeight((U8*) CAT420_CTX->mood_string, &sw, &sh);
    CAT420_CTX->mood_text_x = CAT420_LEFT_MARGIN;
    CAT420_CTX->mood_text_y = tmp_y + line_height + CAT420_MOOD_STATUS_V_SPACING;
    if (CAT420_CTX->mood_text_x + sw > img_left_lower_bound)
    {
        img_left_lower_bound = CAT420_CTX->mood_text_x + sw;
    }
#else /* CAT420_DISP_INFO_TEXT */ 
    UI_UNUSED_PARAMETER(line_height);
    tmp_y = CAT420_CTX->line_y + CAT420_LINE_IMAGE_V_SPACING;
    Get_StringWidthHeight((U8*) GetString(CAT420_CTX->mood_caption), &sw, &sh);
    gui_measure_image(CAT420_CTX->mood_icon, &iw, &ih);
    CAT420_CTX->mood_caption_x = CAT420_LEFT_MARGIN;
    CAT420_CTX->mood_caption_y = tmp_y;
    CAT420_CTX->mood_image_x = CAT420_LEFT_MARGIN;
    CAT420_CTX->mood_image_y = tmp_y + sh + CAT420_MOOD_STATUS_V_SPACING;
    if (CAT420_CTX->mood_caption_x + sw > img_left_lower_bound)
    {
        img_left_lower_bound = CAT420_CTX->mood_caption_x + sw;
    }
    if (CAT420_CTX->mood_image_x + iw > img_left_lower_bound)
    {
        img_left_lower_bound = CAT420_CTX->mood_image_x + iw;
    }
#endif /* CAT420_DISP_INFO_TEXT */ 

    /* Status */
#ifdef CAT420_DISP_INFO_TEXT
    tmp_y = CAT420_CTX->mood_text_y + sh + CAT420_MOOD_STATUS_V_SPACING;
    Get_StringWidthHeight((U8*) GetString(CAT420_CTX->status_caption), &sw, &sh);
    gui_measure_image(CAT420_CTX->status_icon, &iw, &ih);
    CAT420_CTX->status_caption_x = CAT420_LEFT_MARGIN;
    CAT420_CTX->status_image_x = CAT420_CTX->status_caption_x + sw + CAT420_CAPTION_IMAGE_H_SPACING;
    line_height = sh > ih ? sh : ih;
    CAT420_CTX->status_caption_y = tmp_y + ((line_height - sh) >> 1);
    CAT420_CTX->status_image_y = tmp_y + ((line_height - ih) >> 1);
    if (CAT420_CTX->status_image_x + iw > img_left_lower_bound)
    {
        img_left_lower_bound = CAT420_CTX->status_image_x + iw;
    }
    Get_StringWidthHeight((U8*) CAT420_CTX->status_string, &sw, &sh);
    CAT420_CTX->status_text_x = CAT420_LEFT_MARGIN;
    CAT420_CTX->status_text_y = tmp_y + line_height + CAT420_MOOD_STATUS_V_SPACING;
    if (CAT420_CTX->status_text_x + sw > img_left_lower_bound)
    {
        img_left_lower_bound = CAT420_CTX->status_text_x + sw;
    }
#else /* CAT420_DISP_INFO_TEXT */ 
    tmp_y = CAT420_CTX->mood_image_y + ih + CAT420_MOOD_STATUS_V_SPACING;
    Get_StringWidthHeight((U8*) GetString(CAT420_CTX->status_caption), &sw, &sh);
    gui_measure_image(CAT420_CTX->status_icon, &iw, &ih);

    CAT420_CTX->status_caption_x = CAT420_LEFT_MARGIN;
    CAT420_CTX->status_caption_y = tmp_y;
    CAT420_CTX->status_image_x = CAT420_LEFT_MARGIN;
    CAT420_CTX->status_image_y = tmp_y + sh + CAT420_MOOD_STATUS_V_SPACING;

    if (CAT420_CTX->status_caption_x + sw > img_left_lower_bound)
    {
        img_left_lower_bound = CAT420_CTX->status_caption_x + sw;
    }
    if (CAT420_CTX->status_image_x + iw > img_left_lower_bound)
    {
        img_left_lower_bound = CAT420_CTX->status_image_x + iw;
    }
#endif /* CAT420_DISP_INFO_TEXT */ 

    /* Compute image width */
    img_left_lower_bound += CAT420_IMAGE_H_SPACING;
    if (img_left_lower_bound > cw - CAT420_RIGHT_MARGIN - CAT420_IMAGE_AREA_MIN_WIDTH)
    {
        img_left_lower_bound = cw - CAT420_RIGHT_MARGIN - CAT420_IMAGE_AREA_MIN_WIDTH;
    }
    img_left_bound = cw - CAT420_RIGHT_MARGIN - CAT420_IMAGE_AREA_WIDTH - 2 /* editor border */ - 1 /* editor gap */ - 1;
    if (img_left_bound < img_left_lower_bound)
    {
        img_left_bound = img_left_lower_bound;
    }
    img_left_lower_bound -= CAT420_IMAGE_H_SPACING;

    /* Total height */
#ifdef CAT420_DISP_INFO_TEXT
    CAT420_CTX->editor_header_height = CAT420_CTX->status_text_y + sh + CAT420_BOTTOM_MARGIN;
#else 
    CAT420_CTX->editor_header_height = CAT420_CTX->status_image_y + ih + CAT420_BOTTOM_MARGIN;
#endif 

    /* Image */
    if (img_left_bound + CAT420_RIGHT_MARGIN >= cw || CAT420_CTX->image_ori_width == 0 ||
        CAT420_CTX->image_ori_height == 0)
    {
        CAT420_CTX->display_image = MMI_FALSE;
    }

    CAT420_CTX->image_area_x = img_left_bound;
    CAT420_CTX->image_area_y = CAT420_CTX->line_y + CAT420_LINE_IMAGE_V_SPACING;
    CAT420_CTX->image_area_width = cw - CAT420_RIGHT_MARGIN - 2 /* editor border */ - (img_left_bound + 1) - 1 /* editor gap */;
#ifdef CAT420_DISP_INFO_TEXT
    CAT420_CTX->image_area_height = CAT420_CTX->status_text_y + sh - CAT420_CTX->image_area_y;
#else 
    CAT420_CTX->image_area_height = CAT420_CTX->status_image_y + ih - CAT420_CTX->image_area_y;
#endif 

    /* Align text/icon to right for Arabic language */
    if (r2lMMIFlag)
    {
        S32 xd;

        /* Align mood to right */
        xd = CAT420_CTX->mood_caption_x - CAT420_LEFT_MARGIN;
        sw = gui_get_string_width((UI_string_type) GetString(CAT420_CTX->mood_caption));
        CAT420_CTX->mood_caption_x = img_left_lower_bound - xd - sw + 1;

        xd = CAT420_CTX->mood_image_x - CAT420_LEFT_MARGIN;
        gui_measure_image(CAT420_CTX->mood_icon, &iw, &ih);
        CAT420_CTX->mood_image_x = img_left_lower_bound - xd - iw + 1;

    #ifdef CAT420_DISP_INFO_TEXT
        xd = CAT420_CTX->mood_text_x - CAT420_LEFT_MARGIN;
        sw = gui_get_string_width(CAT420_CTX->mood_string);
        CAT420_CTX->mood_text_x = img_left_lower_bound - xd - sw + 1;
    #endif /* CAT420_DISP_INFO_TEXT */ 

        /* Align status to right */
        xd = CAT420_CTX->status_caption_x - CAT420_LEFT_MARGIN;
        sw = gui_get_string_width((UI_string_type) GetString(CAT420_CTX->status_caption));
        CAT420_CTX->status_caption_x = img_left_lower_bound - xd - sw + 1;

        xd = CAT420_CTX->status_image_x - CAT420_LEFT_MARGIN;
        gui_measure_image(CAT420_CTX->status_icon, &iw, &ih);
        CAT420_CTX->status_image_x = img_left_lower_bound - xd - iw + 1;

    #ifdef CAT420_DISP_INFO_TEXT
        xd = CAT420_CTX->status_text_x - CAT420_LEFT_MARGIN;
        sw = gui_get_string_width(CAT420_CTX->status_string);
        CAT420_CTX->status_text_x = img_left_lower_bound - xd - sw + 1;
    #endif /* CAT420_DISP_INFO_TEXT */ 

    }

    /* Resize photo if required */
    if (CAT420_CTX->display_image)
    {
        S32 zoom_offset_x, zoom_offset_y, zoom_size_width, zoom_size_height;

        if (CAT420_CTX->image_ori_width <= CAT420_CTX->image_area_width &&
            CAT420_CTX->image_ori_height <= CAT420_CTX->image_area_height)
        {
            zoom_offset_x = (CAT420_CTX->image_area_width - CAT420_CTX->image_ori_width) >> 1;
            zoom_offset_y = (CAT420_CTX->image_area_height - CAT420_CTX->image_ori_height) >> 1;
            zoom_size_width = 0;
            zoom_size_height = 0;
        }
        else
        {
            gdi_image_util_fit_bbox(
                (S32) CAT420_CTX->image_area_width,
                (S32) CAT420_CTX->image_area_height,
                (S32) CAT420_CTX->image_ori_width,
                (S32) CAT420_CTX->image_ori_height,
                &zoom_offset_x,
                &zoom_offset_y,
                &zoom_size_width,
                &zoom_size_height);
        }
        CAT420_CTX->image_x_offset = (S16) CAT420_CTX->image_area_x + zoom_offset_x;
        CAT420_CTX->image_y_offset = (S16) CAT420_CTX->image_area_y + zoom_offset_y;
        CAT420_CTX->image_resized_width = (S16) zoom_size_width;
        CAT420_CTX->image_resized_height = (S16) zoom_size_height;
    }
}


/*****************************************************************************
 * FUNCTION
 *  category420_cache_image
 * DESCRIPTION
 *  cache image
 * PARAMETERS
 *  image_path                  [IN]        Path of image
 *  alternative_image           [IN]        Image to alternative
 *  use_alternative_image       [IN]        Is use alternative image
 * RETURNS
 *  void
 *****************************************************************************/
static void category420_cache_image(S8 *image_path, U8 *alternative_image, S32 use_alternative_image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!CAT420_CTX->display_image)
    {
        CAT420_CTX->image_is_cached = 0;
        CAT420_CTX->cache_layer = GDI_LAYER_EMPTY_HANDLE;
    }
    else
    {
        CAT420_CTX->image_is_cached = 1;
        gdi_layer_multi_layer_enable();
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
        CAT420_CTX->cache_buf_ptr = mmi_frm_scrmem_alloc_framebuffer((UI_device_width*UI_device_height*GDI_MAINLCD_BIT_PER_PIXEL + 7) >> 3);
        MMI_ASSERT(CAT420_CTX->cache_buf_ptr);
        gdi_layer_create_using_outside_memory(0, 0, UI_device_width, UI_device_height, &CAT420_CTX->cache_layer, CAT420_CTX->cache_buf_ptr, (UI_device_width*UI_device_height*GDI_MAINLCD_BIT_PER_PIXEL + 7) >> 3);
#else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
        gdi_layer_create(0, 0, UI_device_width, UI_device_height, &CAT420_CTX->cache_layer);
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
        gdi_layer_push_and_set_active(CAT420_CTX->cache_layer);

        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);

        if (CAT420_CTX->image_resized_width == 0 || CAT420_CTX->image_resized_height == 0)
        {
            /* Fill background in case that the image is truncated */
            gdi_draw_solid_rect(
                0,
                0,
                CAT420_CTX->image_ori_width,
                CAT420_CTX->image_ori_height,
                gdi_act_color_from_rgb(255, 255, 255, 255));
            if (use_alternative_image)
            {
                gdi_image_draw(0, 0, alternative_image);
            }
            else
            {
                gdi_image_draw_file(0, 0, image_path);
            }
        }
        else
        {
            gdi_draw_solid_rect(
                0,
                0,
                CAT420_CTX->image_resized_width,
                CAT420_CTX->image_resized_height,
                gdi_act_color_from_rgb(255, 255, 255, 255));
            if (use_alternative_image)
            {
                gdi_image_draw_resized(
                    0,
                    0,
                    CAT420_CTX->image_resized_width,
                    CAT420_CTX->image_resized_height,
                    alternative_image);
            }
            else
            {
                gdi_image_draw_resized_file(
                    0,
                    0,
                    CAT420_CTX->image_resized_width,
                    CAT420_CTX->image_resized_height,
                    image_path);
            }
        }

        gdi_layer_pop_and_restore_active();
    }
}


/*****************************************************************************
 * FUNCTION
 *  category420_free_image_cache
 * DESCRIPTION
 *  free image cache
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void category420_free_image_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CAT420_CTX->image_is_cached)
    {
        gdi_layer_free(CAT420_CTX->cache_layer);
        gdi_layer_multi_layer_disable();
    }
}


/*****************************************************************************
 * FUNCTION
 *  category420_show_cached_image
 * DESCRIPTION
 *  show cached image
 * PARAMETERS
 *  x_offset        [IN]        offset x
 *  y_offset        [IN]        offset y
 *  width           [IN]        width
 *  height          [IN]        height
 * RETURNS
 *  void
 *****************************************************************************/
static void category420_show_cached_image(S32 x_offset, S32 y_offset, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, x, y, y_multiple;
    U16 *cached_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!CAT420_CTX->image_is_cached)
    {
        return;
    }

    /* Get clipping region inside the editor */
    gdi_layer_get_clip(&x1, &y1, &x2, &y2);

    gdi_layer_push_and_set_active(CAT420_CTX->cache_layer);
    gdi_layer_get_buffer_ptr((U8 **) & cached_buffer);
    gdi_layer_pop_and_restore_active();

    if (x1 < x_offset)
    {
        x1 = x_offset;
    }
    if (y1 < y_offset)
    {
        y1 = y_offset;
    }
    if (x2 > x_offset + width - 1)
    {
        x2 = x_offset + width - 1;
    }
    if (y2 > y_offset + height - 1)
    {
        y2 = y_offset + height - 1;
    }

    y_multiple = (y1 - y_offset) * UI_device_width;
    for (y = y1; y <= y2; y++)
    {
        for (x = x1; x <= x2; x++)
        {
            GDI_SET_BUFFER_PIXEL2(x, y, cached_buffer[y_multiple + x - x_offset]);
        }
        y_multiple += UI_device_width;
    }
}


/*****************************************************************************
 * FUNCTION
 *  category420_header_callback
 * DESCRIPTION
 *  redraw header callback
 * PARAMETERS
 *  yoffset     [IN]        header1 y offset  
 *  clip_x1     [IN]        start x
 *  clip_y1     [IN]        start y
 *  clip_x2     [IN]        end x
 *  clip_y2     [IN]        end y
 * RETURNS
 *  void
 *****************************************************************************/
static void category420_header_callback(MMI_BOOL is_draw, S32 yoffset, S32 height, S32 clip_x1, S32 clip_y1, S32 clip_x2, S32 clip_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sw, sh; /* string width/height */
#if !defined(__MMI_WALLPAPER_ON_BOTTOM__)
    color tc;
#endif /* !defined(__MMI_WALLPAPER_ON_BOTTOM__) */
    gdi_color c;
    S32 xoffset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_draw == MMI_FALSE)
    {
        return ;
    }
    
    /* Hack. xoffset should be provided in callback function */
    if (r2lMMIFlag)
    {
        xoffset = MMI_multiline_inputbox.vbar.width;
    }

    gui_push_clip();
    gui_push_text_clip();
    gui_set_clip(clip_x1, clip_y1, clip_x2, clip_y2);
    gui_set_text_clip(clip_x1, clip_y1, clip_x2, clip_y2);
    gui_set_font(&MMI_medium_font);

#if !defined(__MMI_WALLPAPER_ON_BOTTOM__)
    tc.r = CAT420_TEXT_COLOR_R;
    tc.g = CAT420_TEXT_COLOR_G;
    tc.b = CAT420_TEXT_COLOR_B;
    tc.alpha = 100;
    gui_set_text_color(tc);
#else /* !defined(__MMI_WALLPAPER_ON_BOTTOM__) */
    gui_set_text_color(*current_MMI_theme->list_normal_text_color);
#endif /* !defined(__MMI_WALLPAPER_ON_BOTTOM__) */

#if !defined(__MMI_WALLPAPER_ON_BOTTOM__)
    c = gdi_act_color_from_rgb(255, CAT420_LINE_COLOR_R, CAT420_LINE_COLOR_G, CAT420_LINE_COLOR_B);
#else /* !defined(__MMI_WALLPAPER_ON_BOTTOM__) */
    c = gdi_act_color_from_rgb(255, current_MMI_theme->list_normal_text_color->r, current_MMI_theme->list_normal_text_color->g, current_MMI_theme->list_normal_text_color->b);
#endif /* !defined(__MMI_WALLPAPER_ON_BOTTOM__) */

    /* Name */
    Get_StringWidthHeight((U8*) CAT420_CTX->name, &sw, &sh);
    if (sw > CAT420_CTX->name_width)
    {
        if (r2lMMIFlag)
        {
            gui_print_truncated_text(
                xoffset + CAT420_CTX->name_x + CAT420_CTX->name_width - 1,
                yoffset + CAT420_CTX->name_y,
                CAT420_CTX->name_width,
                CAT420_CTX->name);
        }
        else
        {
            gui_print_truncated_text(
                xoffset + CAT420_CTX->name_x,
                yoffset + CAT420_CTX->name_y,
                CAT420_CTX->name_width,
                CAT420_CTX->name);
        }
    }
    else
    {
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(xoffset + CAT420_CTX->name_x + sw - 1, yoffset + CAT420_CTX->name_y);
        }
        else
        {
            gui_move_text_cursor(xoffset + CAT420_CTX->name_x, yoffset + CAT420_CTX->name_y);
        }
        gui_print_text(CAT420_CTX->name);
    }

    gdi_draw_line_style(
        xoffset + CAT420_CTX->line_x1,
        yoffset + CAT420_CTX->line_y,
        xoffset + CAT420_CTX->line_x2,
        yoffset + CAT420_CTX->line_y,
        c,
        sizeof(g_mmi_gui_cat420_line_style),
        g_mmi_gui_cat420_line_style);

    /* Mood */
    sw = gui_get_string_width((UI_string_type) GetString(CAT420_CTX->mood_caption));
    if (r2lMMIFlag)
    {
        gui_move_text_cursor(xoffset + CAT420_CTX->mood_caption_x + sw - 1, yoffset + CAT420_CTX->mood_caption_y);
    }
    else
    {
        gui_move_text_cursor(xoffset + CAT420_CTX->mood_caption_x, yoffset + CAT420_CTX->mood_caption_y);
    }
    gui_print_text((UI_string_type) GetString(CAT420_CTX->mood_caption));
    gui_show_transparent_image(
        xoffset + CAT420_CTX->mood_image_x,
        yoffset + CAT420_CTX->mood_image_y,
        CAT420_CTX->mood_icon,
        UI_DEFAULT_TRANSPARENT_COLOR);
#ifdef CAT420_DISP_INFO_TEXT
    sw = gui_get_string_width(CAT420_CTX->mood_string);
    if (r2lMMIFlag)
    {
        gui_move_text_cursor(xoffset + CAT420_CTX->mood_text_x + sw - 1, yoffset + CAT420_CTX->mood_text_y);
    }
    else
    {
        gui_move_text_cursor(xoffset + CAT420_CTX->mood_text_x, yoffset + CAT420_CTX->mood_text_y);
    }
    gui_print_text(CAT420_CTX->mood_string);
#endif /* CAT420_DISP_INFO_TEXT */ 

    /* Status */
    sw = gui_get_string_width((UI_string_type) GetString(CAT420_CTX->status_caption));
    if (r2lMMIFlag)
    {
        gui_move_text_cursor(xoffset + CAT420_CTX->status_caption_x + sw - 1, yoffset + CAT420_CTX->status_caption_y);
    }
    else
    {
        gui_move_text_cursor(xoffset + CAT420_CTX->status_caption_x, yoffset + CAT420_CTX->status_caption_y);
    }
    gui_print_text((UI_string_type) GetString(CAT420_CTX->status_caption));
    gui_show_transparent_image(
        xoffset + CAT420_CTX->status_image_x,
        yoffset + CAT420_CTX->status_image_y,
        CAT420_CTX->status_icon,
        UI_DEFAULT_TRANSPARENT_COLOR);
#ifdef CAT420_DISP_INFO_TEXT
    sw = gui_get_string_width(CAT420_CTX->status_string);
    if (r2lMMIFlag)
    {
        gui_move_text_cursor(xoffset + CAT420_CTX->status_text_x + sw - 1, yoffset + CAT420_CTX->status_text_y);
    }
    else
    {
        gui_move_text_cursor(xoffset + CAT420_CTX->status_text_x, yoffset + CAT420_CTX->status_text_y);
    }
    gui_print_text(CAT420_CTX->status_string);
#endif /* CAT420_DISP_INFO_TEXT */ 

    /* Image */
    if (CAT420_CTX->display_image)
    {
        if (CAT420_CTX->image_resized_width == 0 || CAT420_CTX->image_resized_height == 0)
        {
            category420_show_cached_image(
                xoffset + CAT420_CTX->image_x_offset,
                yoffset + CAT420_CTX->image_y_offset,
                CAT420_CTX->image_ori_width,
                CAT420_CTX->image_ori_height);
        }
        else
        {
            category420_show_cached_image(
                xoffset + CAT420_CTX->image_x_offset,
                yoffset + CAT420_CTX->image_y_offset,
                CAT420_CTX->image_resized_width,
                CAT420_CTX->image_resized_height);
        }
    }
    gdi_draw_rect(
        xoffset + CAT420_CTX->image_area_x - 1,
        yoffset + CAT420_CTX->image_area_y - 1,
        xoffset + CAT420_CTX->image_area_x + CAT420_CTX->image_area_width,
        yoffset + CAT420_CTX->image_area_y + CAT420_CTX->image_area_height,
        c);

    gui_pop_text_clip();
    gui_pop_clip();
}

/* 
 * Category 425
 */


/*****************************************************************************
 * FUNCTION
 *  category425_set_icontext_list_text_color
 * DESCRIPTION
 *  set list text color
 * PARAMETERS
 *  col     [IN]        column index
 *  c1      [IN]        normal_text_colors and disabled_text_colors
 *  c2      [IN]        selected_text_colors and focussed_text_colors
 * RETURNS
 *  void
 *****************************************************************************/
static void category425_set_icontext_list_text_color(int col, color c1, color c2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_icontext_list_menuitem.normal_text_colors[col] = c1;
    MMI_fixed_icontext_list_menuitem.disabled_text_colors[col] = c1;
    MMI_fixed_icontext_list_menuitem.selected_text_colors[col] = c2;
    MMI_fixed_icontext_list_menuitem.focussed_text_colors[col] = c2;
}


/*****************************************************************************
 * FUNCTION
 *  category425_setup_text_color
 * DESCRIPTION
 *  setup 425 text color
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void category425_setup_text_color(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c1, c2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    c1 = *current_MMI_theme->list_normal_text_color;
    c2 = *current_MMI_theme->list_selected_text_color;
#else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
    c1.r = CAT425_TEXT1_COLOR_R;
    c1.g = CAT425_TEXT1_COLOR_G;
    c1.b = CAT425_TEXT1_COLOR_B;
    c2.r = CAT425_TEXT1_HIGHLIGHT_COLOR_R;
    c2.g = CAT425_TEXT1_HIGHLIGHT_COLOR_G;
    c2.b = CAT425_TEXT1_HIGHLIGHT_COLOR_B;
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
    category425_set_icontext_list_text_color(0, c1, c2);

#if !(defined(__MMI_WALLPAPER_ON_BOTTOM__))
    c1.r = CAT425_TEXT2_COLOR_R;
    c1.g = CAT425_TEXT2_COLOR_G;
    c1.b = CAT425_TEXT2_COLOR_B;
    c2.r = CAT425_TEXT2_HIGHLIGHT_COLOR_R;
    c2.g = CAT425_TEXT2_HIGHLIGHT_COLOR_G;
    c2.b = CAT425_TEXT2_HIGHLIGHT_COLOR_B;
#endif /* !(defined(__MMI_WALLPAPER_ON_BOTTOM__)) */ 
    category425_set_icontext_list_text_color(1, c1, c2);
}


/*****************************************************************************
 * FUNCTION
 *  category425_reset_context
 * DESCRIPTION
 *  reset context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void category425_reset_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.flags = CAT425_CTX->backup_menu_flags;
    MMI_fixed_list_menu.normal_filler = CAT425_CTX->backup_menu_filler;
    fixed_icontext_list_menuitem_apply_current_theme();

    OslMfree(g_mmi_gui_cat425_context_p);
    g_mmi_gui_cat425_context_p = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  category425_post_display_menuitem
 * DESCRIPTION
 *  post menuitem to display
 * PARAMETERS
 *  item                    [IN]        item type
 *  common_item_data        [IN]        item list
 *  x                       [IN]        list x
 *  y                       [IN]        list y
 * RETURNS
 *  void
 *****************************************************************************/
static void category425_post_display_menuitem(void *item, void *common_item_data, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c;
    fixed_icontext_list_menuitem *m = (fixed_icontext_list_menuitem*) common_item_data;
    fixed_icontext_list_menuitem_type *mi = (fixed_icontext_list_menuitem_type*) item;
    S32 x2, y2;
    gdi_color border_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x2 = x + m->width - 1;
    y2 = y + m->height - 1;

    gui_push_clip();
    gui_set_clip(x, y, x2, y2);

    border_color =
        (gdi_color) ((mi->flags & UI_MENUITEM_STATE_FOCUSSED) ?
                     gdi_act_color_from_rgb(
                        255,
                        CAT425_ICON_HIGHLIGHT_BORDER_COLOR_R,
                        CAT425_ICON_HIGHLIGHT_BORDER_COLOR_G,
                        CAT425_ICON_HIGHLIGHT_BORDER_COLOR_B) : 
                     gdi_act_color_from_rgb(
                        255,
                        CAT425_ICON_BORDER_COLOR_R,
                        CAT425_ICON_BORDER_COLOR_G,
                        CAT425_ICON_BORDER_COLOR_B));

    c.r = CAT425_TEXT2_BRACKET_COLOR_R;
    c.g = CAT425_TEXT2_BRACKET_COLOR_G;
    c.b = CAT425_TEXT2_BRACKET_COLOR_B;
    gui_set_text_color(c);
    if (r2lMMIFlag)
    {
        gui_move_text_cursor(x2 - CAT425_CTX->bracket_x, y + CAT425_CTX->bracket_y);
        gui_print_text((UI_string_type) L"]");
        gui_move_text_cursor(
            x2 - m->text_coordinates[1].x - m->text_coordinates[1].width - CAT425_TEXT2_BRACKET_GAP,
            y + CAT425_CTX->bracket_y);
        gui_print_text((UI_string_type) L"[");

        gdi_draw_rect(
            x2 - CAT425_CTX->icon_border_x1,
            y + CAT425_CTX->icon_border_y1,
            x2 - CAT425_CTX->icon_border_x2,
            y + CAT425_CTX->icon_border_y2,
            border_color);
    }
    else
    {
        gui_move_text_cursor(x + CAT425_CTX->bracket_x, y + CAT425_CTX->bracket_y);
        gui_print_text((UI_string_type) L"[");
        gui_move_text_cursor(
            x + m->text_coordinates[1].x + m->text_coordinates[1].width + CAT425_TEXT2_BRACKET_GAP,
            y + CAT425_CTX->bracket_y);
        gui_print_text((UI_string_type) L"]");

        gdi_draw_rect(
            x + CAT425_CTX->icon_border_x1,
            y + CAT425_CTX->icon_border_y1,
            x + CAT425_CTX->icon_border_x2,
            y + CAT425_CTX->icon_border_y2,
            border_color);
    }

    gdi_draw_line_style(
        x,
        y2,
        x2,
        y2,
        gdi_act_color_from_rgb(255, CAT425_LINE_COLOR_R, CAT425_LINE_COLOR_G, CAT425_LINE_COLOR_B),
        sizeof(g_mmi_gui_cat425_line_bitvalues),
        g_mmi_gui_cat425_line_bitvalues);

    gui_pop_clip();
}

/* 
 * Category 429 
 */


/*****************************************************************************
 * FUNCTION
 *  wgui_cat429_compute_layout
 * DESCRIPTION
 *  compute layout
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat429_compute_layout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sw, sh; /* string width/height */
    S32 iw, ih; /* image width/height */
    S32 tmp_x;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(&MMI_medium_font);

    /* Image */
    if (CAT429_CTX->image_ori_width == 0 || CAT429_CTX->image_ori_height == 0)
    {
        CAT429_CTX->display_image = MMI_FALSE;
    }

    CAT429_CTX->image_area_y = MMI_COMMON_CONTENT_Y + CAT429_TOP_MARGIN;
    CAT429_CTX->image_area_height = CAT429_IMAGE_DEFAULT_HEIGHT;
    CAT429_CTX->image_area_width = CAT429_IMAGE_DEFAULT_WIDTH;
    if (r2lMMIFlag)
    {
        CAT429_CTX->image_area_x = MMI_COMMON_CONTENT_WIDTH - CAT429_LEFT_MARGIN - CAT429_IMAGE_DEFAULT_WIDTH;                
        tmp_x = CAT429_CTX->image_area_x - CAT429_IMAGE_RIGHT_MARGIN;
    }
    else
    {
        CAT429_CTX->image_area_x = CAT429_LEFT_MARGIN;
        tmp_x = CAT429_CTX->image_area_x + CAT429_IMAGE_DEFAULT_WIDTH + CAT429_IMAGE_RIGHT_MARGIN;
    }

    /* Status */
    gui_measure_image(CAT429_CTX->status_icon, &iw, &ih);

    CAT429_CTX->status_image_y = CAT429_CTX->image_area_y;
    CAT429_CTX->status_image_x = tmp_x;

    if ((iw == 0) || (ih == 0))
    {
        CAT429_CTX->status_image_width = 0;
        CAT429_CTX->status_image_height = 0;
    }
    else
    {
        CAT429_CTX->status_image_width = iw;
        CAT429_CTX->status_image_height = ih;
        if (r2lMMIFlag)
        {
            CAT429_CTX->status_image_x = tmp_x - iw;
            tmp_x = CAT429_CTX->status_image_x - CAT429_IMAGE_RIGHT_MARGIN;            
        }
        else
        {
            tmp_x = tmp_x + iw + CAT429_IMAGE_RIGHT_MARGIN;
        }
    }

    /* Name */
    Get_StringWidthHeight((U8*) CAT429_CTX->name, &sw, &sh);
    CAT429_CTX->name_x = tmp_x;
    
    if (ih > sh)
    {
        CAT429_CTX->name_y = CAT429_CTX->status_image_y + (ih - sh) / 2;
    }
    else
    {
        CAT429_CTX->name_y = CAT429_CTX->status_image_y;
    }

    if (r2lMMIFlag)
    {
        CAT429_CTX->name_width = CAT429_CTX->name_x;
    }
    else
    {
        CAT429_CTX->name_width = MMI_CONTENT_WIDTH - CAT429_CTX->name_x;
    }    

    /* UserId */
    CAT429_CTX->userid_y = CAT429_CTX->status_image_y + ih + CAT429_TEXT_TEXT_GAP;
    if (r2lMMIFlag)
    {
        CAT429_CTX->userid_x = CAT429_CTX->status_image_x + CAT429_CTX->status_image_width;
        CAT429_CTX->userid_width = CAT429_CTX->userid_x - 1;    /* add 1 pixel as gap */
    }
    else
    {
        CAT429_CTX->userid_x = CAT429_CTX->status_image_x;
        CAT429_CTX->userid_width = MMI_CONTENT_WIDTH - CAT429_CTX->userid_x - 1;    /* add 1 pixel as gap */
    }

    /* Mood */
    Get_StringWidthHeight((U8*) CAT429_CTX->mood_caption, &sw, &sh);
    gui_measure_image(CAT429_CTX->mood_icon, &iw, &ih);
    CAT429_CTX->mood_caption_x = CAT429_LEFT_MARGIN;
    CAT429_CTX->mood_caption_y = CAT429_TOP_MARGIN;
    CAT429_CTX->mood_image_x = CAT429_CTX->mood_caption_x + CAT429_STRING_WIDTH + CAT429_TEXT_TEXT_GAP;
    CAT429_CTX->mood_image_y = CAT429_TOP_MARGIN;
    if (ih > sh)
    {
        CAT429_CTX->mood_caption_y = CAT429_CTX->mood_caption_y + (ih - sh) / 2;
    }

    /* Device */
    CAT429_CTX->device_caption_x = CAT429_LEFT_MARGIN;
    CAT429_CTX->device_caption_y = CAT429_CTX->mood_caption_y + sh + CAT429_TEXT_TEXT_GAP;
    CAT429_CTX->device_string_x = CAT429_CTX->device_caption_x + CAT429_STRING_WIDTH + CAT429_TEXT_TEXT_GAP;
    CAT429_CTX->device_string_y = CAT429_CTX->device_caption_y;

    /* Total height */
    CAT429_CTX->editor_header_height = CAT429_CTX->device_string_y + sh + CAT429_TEXT_TEXT_GAP;

    /* Resize photo if required */
    if (CAT429_CTX->display_image)
    {
        S32 zoom_offset_x, zoom_offset_y, zoom_size_width, zoom_size_height;

        if (CAT429_CTX->image_ori_width <= CAT429_CTX->image_area_width &&
            CAT429_CTX->image_ori_height <= CAT429_CTX->image_area_height)
        {
            zoom_offset_x = (CAT429_CTX->image_area_width - CAT429_CTX->image_ori_width) >> 1;
            zoom_offset_y = (CAT429_CTX->image_area_height - CAT429_CTX->image_ori_height) >> 1;
            zoom_size_width = 0;
            zoom_size_height = 0;
        }
        else
        {
            gdi_image_util_fit_bbox(
                (S32) CAT429_CTX->image_area_width,
                (S32) CAT429_CTX->image_area_height,
                (S32) CAT429_CTX->image_ori_width,
                (S32) CAT429_CTX->image_ori_height,
                &zoom_offset_x,
                &zoom_offset_y,
                &zoom_size_width,
                &zoom_size_height);
        }
        CAT429_CTX->image_x_offset = (S16) CAT429_CTX->image_area_x + zoom_offset_x;
        CAT429_CTX->image_y_offset = (S16) CAT429_CTX->image_area_y + zoom_offset_y;
        CAT429_CTX->image_resized_width = (S16) zoom_size_width;
        CAT429_CTX->image_resized_height = (S16) zoom_size_height;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat429_header_callback
 * DESCRIPTION
 *  redraw header callback
 * PARAMETERS
 *  is_draw     [IN]        
 *  yoffset     [IN]        Header1 y offset
 *  height      [IN]        
 *  clip_x1     [IN]        Start x
 *  clip_y1     [IN]        Start y
 *  clip_x2     [IN]        End x
 *  clip_y2     [IN]        End y
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat429_header_callback(MMI_BOOL is_draw, S32 yoffset, S32 height, S32 clip_x1, S32 clip_y1, S32 clip_x2, S32 clip_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sw, sh; /* string width/height */
    S32 xstart = 0;
	S32 iw = 0, ih = 0;
	S32 xend = 0;
    S32 scrollbar_w = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_draw == MMI_FALSE)
    {
        return;
    }

    scrollbar_w = wgui_inputs_ml_get_scroll_bar_width();
    xstart = scrollbar_w;
    xend = MMI_content_width - scrollbar_w;

    gui_push_clip();
    gui_set_clip(clip_x1, clip_y1, clip_x2, clip_y2);
 
    gui_set_font(&MMI_medium_font);
    gui_set_text_color(*current_MMI_theme->inputbox_normal_text_color);

    /* Mood */
    Get_StringWidthHeight((U8*) CAT429_CTX->mood_caption, &sw, &sh);
    if (CAT429_STRING_WIDTH > sw)
    {
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(xend - CAT429_CTX->mood_caption_x, CAT429_CTX->mood_caption_y + yoffset);
        }
        else
        {
            gui_move_text_cursor(xstart + CAT429_CTX->mood_caption_x, CAT429_CTX->mood_caption_y + yoffset);
        }
        gui_print_text(CAT429_CTX->mood_caption);
    }
    else
    {
        if (r2lMMIFlag)
        {
            gui_print_truncated_text(
                xend - CAT429_CTX->mood_caption_x,
                CAT429_CTX->mood_caption_y + yoffset,
                CAT429_STRING_WIDTH,
                CAT429_CTX->mood_caption);
        }
        else
        {
            gui_print_truncated_text(
                xstart + CAT429_CTX->mood_caption_x,
                CAT429_CTX->mood_caption_y + yoffset,
                CAT429_STRING_WIDTH,
                CAT429_CTX->mood_caption);
        }
    }

    /* Mood Icon */
    gui_measure_image(CAT429_CTX->mood_icon, &iw, &ih);
	if(r2lMMIFlag)
	{
		gui_show_transparent_image(
			xend - CAT429_CTX->mood_image_x - iw + 1,
			yoffset + CAT429_CTX->mood_image_y,
			CAT429_CTX->mood_icon,
			UI_DEFAULT_TRANSPARENT_COLOR);
	}
	else
	{
		gui_show_transparent_image(
			xstart + CAT429_CTX->mood_image_x,
			yoffset + CAT429_CTX->mood_image_y,
			CAT429_CTX->mood_icon,
			UI_DEFAULT_TRANSPARENT_COLOR);
	}

    /* Device */
    Get_StringWidthHeight((U8*) CAT429_CTX->device_caption, &sw, &sh);
    if (CAT429_STRING_WIDTH > sw)
    {
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(xend - CAT429_CTX->device_caption_x, CAT429_CTX->device_caption_y + yoffset);
        }
        else
        {
            gui_move_text_cursor(xstart + CAT429_CTX->device_caption_x, CAT429_CTX->device_caption_y + yoffset);
        }
        gui_print_text(CAT429_CTX->device_caption);
    }
    else
    {
        if (r2lMMIFlag)
        {
            gui_print_truncated_text(
                xend - CAT429_CTX->device_caption_x,
                CAT429_CTX->device_caption_y + yoffset,
                CAT429_STRING_WIDTH,
                CAT429_CTX->device_caption);
        }
        else
        {
            gui_print_truncated_text(
                xstart + CAT429_CTX->device_caption_x,
                CAT429_CTX->device_caption_y + yoffset,
                CAT429_STRING_WIDTH,
                CAT429_CTX->device_caption);
        }
    }
    /* Device String */
    Get_StringWidthHeight((U8*) CAT429_CTX->device_string, &sw, &sh);
    if (r2lMMIFlag)
    {
        gui_move_text_cursor(xend - CAT429_CTX->device_string_x, CAT429_CTX->device_string_y + yoffset);
    }
    else
    {
        gui_move_text_cursor(xstart + CAT429_CTX->device_string_x, CAT429_CTX->device_string_y + yoffset);
    }
    gui_print_text(CAT429_CTX->device_string);

    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat429_scrolling_timer
 * DESCRIPTION
 *  timer callback of category429 scrolling text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat429_scrolling_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_handle_scrolling_text(&scroll_text_cat429);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat429_scrolling_text_draw_background
 * DESCRIPTION
 *  draw background callback function of scrolling text of category251
 * PARAMETERS
 *  x1      [IN]        Start x posityion
 *  y1      [IN]        Start y position
 *  x2      [IN]        End x position
 *  y2      [IN]        End y position
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat429_scrolling_text_draw_background(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat429_draw_control_area
 * DESCRIPTION
 *  Draw Cat429 control area,
 *  including Mood, Device
 * PARAMETERS
 *  coordinate          [IN]    Useless, we have pre-defined area
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat429_draw_control_area(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_color c;
    S32 sw, sh;
	color text_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Image */
    gui_push_clip();
    gui_push_text_clip();
    gui_set_clip(coordinate->s16X, coordinate->s16Y, coordinate->s16X + coordinate->s16Width, coordinate->s16Y + coordinate->s16Height);
    gui_set_text_clip(coordinate->s16X, coordinate->s16Y, coordinate->s16X + coordinate->s16Width, coordinate->s16Y + coordinate->s16Height);
    gui_set_font(&MMI_medium_font);
    c = gdi_act_color_from_rgb(255, CAT429_LINE_COLOR_R, CAT429_LINE_COLOR_G, CAT429_LINE_COLOR_B);
#ifdef __MMI_FTE_SUPPORT__
	text_color = gui_color(255, 255, 255);
#else
	text_color = *current_MMI_theme->inputbox_normal_text_color;
#endif
    if (CAT429_CTX->display_image)
    {
        if (CAT429_CTX->image_resized_width == 0 || CAT429_CTX->image_resized_height == 0)
        {
            if (CAT429_CTX->use_alternative_image)
            {
                gdi_image_draw(CAT429_CTX->image_x_offset, CAT429_CTX->image_y_offset, CAT429_CTX->alternative_photo);
            }
            else
            {
                gdi_image_draw_file(CAT429_CTX->image_x_offset, CAT429_CTX->image_y_offset, CAT429_CTX->photo_filename);
            }
        }
        else
        {
            if (CAT429_CTX->use_alternative_image)
            {
                gdi_image_draw_resized(
                    CAT429_CTX->image_x_offset,
                    CAT429_CTX->image_y_offset,
                    CAT429_CTX->image_resized_width,
                    CAT429_CTX->image_resized_height,
                    CAT429_CTX->alternative_photo);
            }
            else
            {
                gdi_image_draw_resized_file(
                    CAT429_CTX->image_x_offset,
                    CAT429_CTX->image_y_offset,
                    CAT429_CTX->image_resized_width,
                    CAT429_CTX->image_resized_height,
                    CAT429_CTX->photo_filename);
            }
        }
    }

    gdi_draw_rect(
        CAT429_CTX->image_area_x - 1,
        CAT429_CTX->image_area_y - 1,
        CAT429_CTX->image_area_x + CAT429_CTX->image_area_width,
        CAT429_CTX->image_area_y + CAT429_CTX->image_area_height,
        c);

    /* Status */
    gui_show_transparent_image(
        CAT429_CTX->status_image_x,
        CAT429_CTX->status_image_y,
        CAT429_CTX->status_icon,
        UI_DEFAULT_TRANSPARENT_COLOR);

    gui_set_text_color(text_color);
    /* name */
    Get_StringWidthHeight((U8*) CAT429_CTX->name, &sw, &sh);
    if (sw > CAT429_CTX->name_width)
    {
        gui_print_truncated_text(
            CAT429_CTX->name_x,
            CAT429_CTX->name_y,
            CAT429_CTX->name_width,
            CAT429_CTX->name);
    }
    else
    {
        gui_move_text_cursor(CAT429_CTX->name_x, CAT429_CTX->name_y);
        gui_print_text(CAT429_CTX->name);
    }
    /* userid */
    Get_StringWidthHeight((U8*) CAT429_CTX->userid, &sw, &sh);
    if (CAT429_CTX->userid_width > sw)
    {
        gui_move_text_cursor(CAT429_CTX->userid_x, CAT429_CTX->userid_y);
        gui_print_text(CAT429_CTX->userid);
    }
    else
    {
		if (r2lMMIFlag)
		{
			gui_create_scrolling_text(
				&scroll_text_cat429,
				CAT429_CTX->userid_x - CAT429_CTX->userid_width,
				CAT429_CTX->userid_y,
				CAT429_CTX->userid_width,
				sh,
				CAT429_CTX->userid,
				wgui_cat429_scrolling_timer,
				wgui_cat429_scrolling_text_draw_background,
				text_color,
				gui_color(255, 255, 255));
		}
		else
		{
			gui_create_scrolling_text(
				&scroll_text_cat429,
				CAT429_CTX->userid_x,
				CAT429_CTX->userid_y,
				CAT429_CTX->userid_width,
				sh,
				CAT429_CTX->userid,
				wgui_cat429_scrolling_timer,
				wgui_cat429_scrolling_text_draw_background,
				text_color,
				gui_color(255, 255, 255));
		}
        gui_show_scrolling_text(&scroll_text_cat429);
    }

    gui_pop_text_clip();
    gui_pop_clip();
}

/* 
 * Category 430
 */

/* b is configured, and b->height is computed */


/*****************************************************************************
 * FUNCTION
 *  category430_create_sending_box
 * DESCRIPTION
 *  carete send box
 * PARAMETERS
 *  b       [IN]        Input box struct
 *  x       [IN]        position x
 *  y       [IN]        poxition y
 * RETURNS
 *  void
 *****************************************************************************/
static void category430_create_sending_box(multi_line_input_box *b, S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 length;
    S32 read_index;
    wgui_color_buffer_writer_struct writer;
    S32 h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    length = gui_strlen((UI_string_type) CAT430_CTX->sending_buffer);

    /* Create color text buffer */
    MMI_ASSERT(CAT430_CTX->sent_count <= length && length <= CAT430_CTX->max_sending_buffer_size);

    CAT430_CTX->allocated_color_buffer[0] = CAT430_CTX->allocated_color_buffer[1] = 0;
    wgui_inputs_color_buffer_create_write(
        &writer,
        CAT430_CTX->allocated_color_buffer,
        CAT430_CTX->allocated_color_buffer_size);
    wgui_inputs_color_buffer_write_char(&writer, GUI_INPUT_COLOR_BLACK);
    for (read_index = 0; read_index < CAT430_CTX->sent_count; read_index++)
    {
        wgui_inputs_color_buffer_write_char(&writer, *((U16*) & CAT430_CTX->sending_buffer[read_index << 1]));
    }
    wgui_inputs_color_buffer_write_char(&writer, GUI_INPUT_COLOR_TEAL);
    for (read_index = CAT430_CTX->sent_count; read_index < length; read_index++)
    {
        wgui_inputs_color_buffer_write_char(&writer, *((U16*) & CAT430_CTX->sending_buffer[read_index << 1]));
    }

    gui_create_multi_line_input_box_set_buffer(
        b,
        x,
        y,
        CAT430_CTX->sending_box_width,
        UI_device_height /* max height */ ,
        (UI_string_type) CAT430_CTX->allocated_color_buffer,
        CAT430_CTX->max_sending_buffer_size * 2,
        (length + 1) * 2,
        0);

    wgui_inputs_ml_set_style_with_obj(b, (UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | UI_MULTI_LINE_INPUT_BOX_VIEW_MODE |
         UI_MULTI_LINE_INPUT_BOX_RICHTEXT | UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR), 0);


    b->normal_filler = (UI_filled_area*)&g_mmi_gui_cat430_sending_filler;
    b->normal_text_color = g_mmi_gui_cat430_editor_text_color;

    /* Compute text height and adjust scroll offset */
    b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_multi_line_input_box(b);
    b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;

    /* Setup height */
    h = b->text_height + b->text_y;
    gui_resize_multi_line_input_box(b, b->width, h);
}


/*****************************************************************************
 * FUNCTION
 *  category430_setup_sending_box
 * DESCRIPTION
 *  setup sending box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void category430_setup_sending_box(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    multi_line_input_box b;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CAT430_CTX->show_sending_buffer)
    {
        CAT430_CTX->sending_box_x = CAT430_SENDING_BOX_H_GAP;
        CAT430_CTX->sending_box_y = CAT430_SENDING_BOX_V_GAP;
        CAT430_CTX->sending_box_width = CAT430_CTX->log_box2_width -
            2 * CAT430_SENDING_BOX_H_GAP - current_multi_line_input_box_theme->vbar_width;
        category430_create_sending_box(&b, 0, 0);
        CAT430_CTX->log_box2_footer_height = b.height + 2 * CAT430_SENDING_BOX_V_GAP;
    }
    else
    {
        CAT430_CTX->log_box2_footer_height = 0;
    }
}

#ifdef CAT430_NAME_IN_LOG
/*****************************************************************************
 * FUNCTION
 *  category430_header1_callback
 * DESCRIPTION
 *  header 1 redraw
 * PARAMETERS
 *  yoffset     [IN]        header1 y offset  
 *  clip_x1     [IN]        start x
 *  clip_y1     [IN]        start y
 *  clip_x2     [IN]        end x
 *  clip_y2     [IN]        end y
 * RETURNS
 *  void
 *****************************************************************************/
static void category430_header1_callback(MMI_BOOL is_draw, S32 yoffset, S32 height, S32 clip_x1, S32 clip_y1, S32 clip_x2, S32 clip_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sw;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_draw == MMI_FALSE)
    {
        return ;
    }
    
    gui_push_clip();
    gui_set_clip(clip_x1, clip_y1, clip_x2, clip_y2);

    gui_set_font(CAT430_NAME_FONT);
    sw = gui_get_string_width((UI_string_type) CAT430_CTX->name1);

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(CAT430_CTX->log_box1_x + CAT430_HORIZONTAL_GAP + sw - 1, yoffset);
    }
    else
    {
        gui_move_text_cursor(CAT430_CTX->log_box1_x + CAT430_HORIZONTAL_GAP, yoffset);
    }
    gui_set_text_color(gui_color(CAT430_NAME1_COLOR_R, CAT430_NAME1_COLOR_G, CAT430_NAME1_COLOR_B));
    gui_print_text((UI_string_type) CAT430_CTX->name1);

    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  category430_header2_callback
 * DESCRIPTION
 *  header 2 redraw
 * PARAMETERS
 *  yoffset     [IN]        header2 y offset  
 *  clip_x1     [IN]        start x
 *  clip_y1     [IN]        start y
 *  clip_x2     [IN]        end x
 *  clip_y2     [IN]        end y
 * RETURNS
 *  void
 *****************************************************************************/
static void category430_header2_callback(MMI_BOOL is_draw, S32 yoffset, S32 height, S32 clip_x1, S32 clip_y1, S32 clip_x2, S32 clip_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sw;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_draw == MMI_FALSE)
    {
        return ;
    }

    gui_push_clip();
    gui_set_clip(clip_x1, clip_y1, clip_x2, clip_y2);

    gui_set_font(CAT430_NAME_FONT);
    sw = gui_get_string_width((UI_string_type) CAT430_CTX->name2);

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(CAT430_CTX->log_box2_x + CAT430_HORIZONTAL_GAP + sw - 1, yoffset);
    }
    else
    {
        gui_move_text_cursor(CAT430_CTX->log_box2_x + CAT430_HORIZONTAL_GAP, yoffset);
    }
    gui_set_text_color(gui_color(CAT430_NAME2_COLOR_R, CAT430_NAME2_COLOR_G, CAT430_NAME2_COLOR_B));
    gui_print_text((UI_string_type) CAT430_CTX->name2);

    gui_pop_clip();
}
#endif /* CAT430_NAME_IN_LOG */ 


/*****************************************************************************
 * FUNCTION
 *  category430_footer_callback
 * DESCRIPTION
 *  redraw inpubox footer 
 * PARAMETERS
 *  yoffset     [IN]        footer y offset  
 *  clip_x1     [IN]        start x
 *  clip_y1     [IN]        start y
 *  clip_x2     [IN]        end x
 *  clip_y2     [IN]        end y
 * RETURNS
 *  void
 *****************************************************************************/
static void category430_footer_callback(MMI_BOOL is_draw, S32 yoffset, S32 height, S32 clip_x1, S32 clip_y1, S32 clip_x2, S32 clip_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    multi_line_input_box b;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_draw == MMI_FALSE)
    {
        return ;
    }

    category430_create_sending_box(&b, (S16) CAT430_CTX->sending_box_x, (S16) (yoffset + CAT430_CTX->sending_box_y));
    b.flags |= UI_MULTI_LINE_INPUT_BOX_USE_PRESET_CLIPPING;
    gui_push_clip();
    gui_set_clip(clip_x1, clip_y1, clip_x2, clip_y2);
    gui_show_multi_line_input_box(&b);
    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  category430_setup_log_box1
 * DESCRIPTION
 *  setup log box1
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void category430_setup_log_box1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
     * In Arabic, the ailgnment format is decided by the content of file. 
     * * MSN align chat log to left.
     */
    S32 log_length;
    multi_line_input_box *b = &CAT430_CTX->log_box1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    log_length = gui_strlen((UI_string_type) CAT430_CTX->log_buffer1);
    gui_create_multi_line_input_box_set_buffer(
        b,
        CAT430_CTX->log_box1_x,
        CAT430_CTX->log_box1_y,
        CAT430_CTX->log_box1_width,
        CAT430_CTX->log_box1_height,
        (UI_string_type) CAT430_CTX->log_buffer1,
        CAT430_CTX->log_buffer_size1 * 2,
        (log_length + 1) * 2,
        0);

#ifdef CAT430_NAME_IN_LOG
    b->header_height = CAT430_CTX->log_box_header_height;
    b->header_callback = category430_header1_callback;
#endif /* CAT430_NAME_IN_LOG */ 

    b->flags |= (UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | UI_MULTI_LINE_INPUT_BOX_VIEW_MODE);
    b->normal_filler = (UI_filled_area*)&g_mmi_gui_cat430_logbox_filler;
    b->normal_text_color = g_mmi_gui_cat430_editor_text_color;

    /* Compute text height and adjust scroll offset */
    b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_multi_line_input_box(b);
    b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    if (b->text_height > b->edit_height)
    {
        b->text_offset_y = -(b->text_height - b->edit_height);
    }
}


/*****************************************************************************
 * FUNCTION
 *  category430_setup_log_box2
 * DESCRIPTION
 *  setup log box2
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void category430_setup_log_box2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
     * In Arabic, the ailgnment format is decided by the content of file. 
     * * MSN align chat log to left.
     */
    S32 log_length;
    multi_line_input_box *b = &MMI_multiline_inputbox;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    log_length = gui_strlen((UI_string_type) CAT430_CTX->log_buffer2);
    gui_create_multi_line_input_box_set_buffer(
        b,
        CAT430_CTX->log_box2_x,
        CAT430_CTX->log_box2_y,
        CAT430_CTX->log_box2_width,
        CAT430_CTX->log_box2_height,
        (UI_string_type) CAT430_CTX->log_buffer2,
        CAT430_CTX->log_buffer_size2 * 2,
        (log_length + 1) * 2,
        0);

#ifdef CAT430_NAME_IN_LOG
    b->header_height = CAT430_CTX->log_box_header_height;
    b->header_callback = category430_header2_callback;
#endif /* CAT430_NAME_IN_LOG */ 
    b->footer_height = CAT430_CTX->log_box2_footer_height;
    b->footer_callback = category430_footer_callback;
    b->max_empty_text_height = 1;   /* For the case sending box is not empty but log box2 is empty. */

    b->flags |= (UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | UI_MULTI_LINE_INPUT_BOX_VIEW_MODE);
    b->normal_filler = (UI_filled_area*)&g_mmi_gui_cat430_logbox_filler;
    b->normal_text_color = g_mmi_gui_cat430_editor_text_color;

    /* Compute text height and adjust scroll offset */
    b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_multi_line_input_box(b);
    b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    if (b->text_height > b->edit_height)
    {
        b->text_offset_y = -(b->text_height - b->edit_height);
    }
}


/*****************************************************************************
 * FUNCTION
 *  category430_draw_content_area
 * DESCRIPTION
 *  redraw content area
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void category430_draw_content_area(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_WALLPAPER_ON_BOTTOM__
    gui_draw_filled_area(
        MMI_content_x,
        MMI_content_y,
        MMI_content_x + MMI_content_width - 1,
        MMI_content_y + MMI_content_height - 1,
        MMI_fixed_list_menu.normal_filler);
#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */ 

#ifndef CAT430_NAME_IN_LOG
    gui_set_font(CAT430_NAME_FONT);

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(CAT430_CTX->log_box1_x + CAT430_CTX->log_box1_width - 1, CAT430_CTX->name1_y);
    }
    else
    {
        gui_move_text_cursor(CAT430_CTX->name1_x, CAT430_CTX->name1_y);
    }
    gui_set_text_color(gui_color(CAT430_NAME1_COLOR_R, CAT430_NAME1_COLOR_G, CAT430_NAME1_COLOR_B));
    gui_print_text((UI_string_type) CAT430_CTX->name1);

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(CAT430_CTX->log_box2_x + CAT430_CTX->log_box2_width - 1, CAT430_CTX->name2_y);
    }
    else
    {
        gui_move_text_cursor(CAT430_CTX->name2_x, CAT430_CTX->name2_y);
    }
    gui_set_text_color(gui_color(CAT430_NAME2_COLOR_R, CAT430_NAME2_COLOR_G, CAT430_NAME2_COLOR_B));
    gui_print_text((UI_string_type) CAT430_CTX->name2);
#endif /* CAT430_NAME_IN_LOG */ 

    gui_show_multi_line_input_box(&CAT430_CTX->log_box1);
    gui_show_multi_line_input_box(&MMI_multiline_inputbox);
}


/*****************************************************************************
 * FUNCTION
 *  category430_previous_line
 * DESCRIPTION
 *  goto previous line
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void category430_previous_line(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
    gui_multi_line_input_box_previous_line(&CAT430_CTX->log_box1);
    gui_show_multi_line_input_box(&CAT430_CTX->log_box1);
    gui_multi_line_input_box_previous_line(&MMI_multiline_inputbox);
    gui_show_multi_line_input_box(&MMI_multiline_inputbox);
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  category430_next_line
 * DESCRIPTION
 *  goto next line
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void category430_next_line(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
    gui_multi_line_input_box_next_line(&CAT430_CTX->log_box1);
    gui_show_multi_line_input_box(&CAT430_CTX->log_box1);
    gui_multi_line_input_box_next_line(&MMI_multiline_inputbox);
    gui_show_multi_line_input_box(&MMI_multiline_inputbox);
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  category430_draw_controlled_area
 * DESCRIPTION
 *  redraw control area
 * PARAMETERS
 *  coordinate      [IN]     area to redraw
 * RETURNS
 *  void
 *****************************************************************************/
static void category430_draw_controlled_area(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(coordinate);
    category430_draw_content_area();
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  category430_control_area_pen_handler
 * DESCRIPTION
 *  pen handler
 * PARAMETERS
 *  point           [IN]        pen event position
 *  pen_event       [IN]        pen event type
 * RETURNS
 *  Is handled
 *****************************************************************************/
static MMI_BOOL category430_control_area_pen_handler(mmi_pen_point_struct point, mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_multi_line_input_box_pen_enum event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!CAT430_CTX)
    {
        MMI_DBG_ASSERT(0);
        return MMI_FALSE;
    }

    if (pen_event == MMI_PEN_EVENT_DOWN)
    {
        CAT430_CTX->pen_object = 0;

        if (gui_multi_line_input_box_translate_pen_event(&CAT430_CTX->log_box1, pen_event, point.x, point.y, &event))
        {
            CAT430_CTX->pen_object = 1;
            return MMI_TRUE;
        }
        if (gui_multi_line_input_box_translate_pen_event(&MMI_multiline_inputbox, pen_event, point.x, point.y, &event))
        {
            CAT430_CTX->pen_object = 2;
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    }
    else
    {
        switch (CAT430_CTX->pen_object)
        {
            case 1:
                return gui_multi_line_input_box_translate_pen_event(
                        &CAT430_CTX->log_box1,
                        pen_event,
                        point.x,
                        point.y,
                        &event);
            case 2:
                return gui_multi_line_input_box_translate_pen_event(
                        &MMI_multiline_inputbox,
                        pen_event,
                        point.x,
                        point.y,
                        &event);
            default:
                return MMI_TRUE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  category430_control_area_pen_down_handler
 * DESCRIPTION
 *  pen down handler
 * PARAMETERS
 *  point       [IN]        pen move position
 * RETURNS
 *  Is handled
 *****************************************************************************/
static MMI_BOOL category430_control_area_pen_down_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return category430_control_area_pen_handler(point, MMI_PEN_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  category430_control_area_pen_move_handler
 * DESCRIPTION
 *  pen move handler
 * PARAMETERS
 *  point       [IN]        pen move position
 * RETURNS
 *  Is handled
 *****************************************************************************/
static MMI_BOOL category430_control_area_pen_move_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return category430_control_area_pen_handler(point, MMI_PEN_EVENT_MOVE);
}


/*****************************************************************************
 * FUNCTION
 *  category430_control_area_pen_longtap_handler
 * DESCRIPTION
 *  pen longtap handler
 * PARAMETERS
 *  point       [IN]        pen longtap position
 * RETURNS
 *  Is handled
 *****************************************************************************/
static MMI_BOOL category430_control_area_pen_longtap_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return category430_control_area_pen_handler(point, MMI_PEN_EVENT_LONG_TAP);
}


/*****************************************************************************
 * FUNCTION
 *  category430_control_area_pen_repeat_handler
 * DESCRIPTION
 *  pen repeat handler
 * PARAMETERS
 *  point       [IN]        pen repeat position
 * RETURNS
 *  Is handled
 *****************************************************************************/
static MMI_BOOL category430_control_area_pen_repeat_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return category430_control_area_pen_handler(point, MMI_PEN_EVENT_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  category430_control_area_pen_up_handler
 * DESCRIPTION
 *  pen up handler
 * PARAMETERS
 *  point       [IN]        pen up position
 * RETURNS
 *  Is handled
 *****************************************************************************/
static MMI_BOOL category430_control_area_pen_up_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return category430_control_area_pen_handler(point, MMI_PEN_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  category430_control_area_pen_abort_handler
 * DESCRIPTION
 *  pen abort handler
 * PARAMETERS
 *  point       [IN]        pen abort position
 * RETURNS
 *  Is handled
 *****************************************************************************/
static MMI_BOOL category430_control_area_pen_abort_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return category430_control_area_pen_handler(point, MMI_PEN_EVENT_ABORT);
}

#endif /* __MMI_TOUCH_SCREEN__ */ 

/* 
 * Category 435
 */

#if defined(__MMI_TOUCH_SCREEN__)
static MMI_BOOL g_wgui_cat435_is_ml_pen_down = MMI_FALSE;

/*****************************************************************************
 * FUNCTION
 *  wgui_cat435_hilite_general_pen_handler
 * DESCRIPTION
 *  general category 435 hilite pen handler
 * PARAMETERS
 *  pen_event   [IN]    pen event type
 *  pos         [IN]    pen position
 *  ml_event    [OUT]   multiline inputbox event
 * RETURNS
 *  whether to handle this pen event
 *****************************************************************************/
static MMI_BOOL wgui_cat435_hilite_general_pen_handler(mmi_pen_event_type_enum pen_event, mmi_pen_point_struct pos, gui_multi_line_input_box_pen_enum *ml_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    multi_line_input_box *b = &CAT435_CTX->log_box;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	gdi_layer_lock_frame_buffer();
    ret = gui_multi_line_input_box_translate_pen_event(
            b,
            pen_event,
            pos.x,
            pos.y,
            ml_event);
	gdi_layer_unlock_frame_buffer();
    if ((ret == MMI_TRUE) && (*ml_event != GUI_MULTI_LINE_INPUT_BOX_PEN_SCROLL_BAR))
    {
        b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        gui_show_multi_line_input_box_ext(b, pos.x, pos.y);
        b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        if (gui_multi_line_input_box_is_pen_down_in_hilite(b))
        {
            gui_multi_line_input_box_go_to_hilite(
                b,
                (U16)(b->current_hilite_idx),
                MMI_FALSE);
        }
        else
        {
            gui_show_multi_line_input_box(b);
            gdi_lcd_repaint_all();
        }
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat435_hilite_pen_down_handler
 * DESCRIPTION
 *  category 435 pen down handler
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat435_hilite_pen_down_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    gui_multi_line_input_box_pen_enum ml_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = wgui_cat435_hilite_general_pen_handler(MMI_PEN_EVENT_DOWN, pos, &ml_event);
    g_wgui_cat435_is_ml_pen_down = ret;
    if (ret == MMI_FALSE)
    {
        wgui_general_pen_down_hdlr(pos);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat435_hilite_pen_move_handler
 * DESCRIPTION
 *  category 435 pen move handler
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat435_hilite_pen_move_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    gui_multi_line_input_box_pen_enum ml_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wgui_cat435_is_ml_pen_down)
    {
        ret = wgui_cat435_hilite_general_pen_handler(MMI_PEN_EVENT_MOVE, pos, &ml_event);
    }
    if (ret == MMI_FALSE)
    {
        wgui_general_pen_move_hdlr(pos);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat435_hilite_pen_up_handler
 * DESCRIPTION
 *  category 435 pen up handler
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat435_hilite_pen_up_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    multi_line_input_box *b = &CAT435_CTX->log_box;
    gui_multi_line_input_box_pen_enum ml_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wgui_cat435_is_ml_pen_down)
    {
        ret = wgui_cat435_hilite_general_pen_handler(MMI_PEN_EVENT_UP, pos, &ml_event);
    }

    if (ret == MMI_FALSE)
    {
        wgui_general_pen_up_hdlr(pos);
    }
    else
    {
        if (ml_event != GUI_MULTI_LINE_INPUT_BOX_PEN_SCROLL_BAR)
        {
            if (gui_multi_line_input_box_is_pen_down_in_hilite(b))
            {
                if (g_wgui_cat435_hilite_click_cb)
                {
                    g_wgui_cat435_hilite_click_cb(b->current_hilite_idx);
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat435_hilite_pen_up_handler
 * DESCRIPTION
 *  category 435 pen up handler
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat435_register_hilite_pen_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (CAT435_CTX && g_wgui_cat435_hilite_list)
    {
        if (!CAT435_CTX->show_popup)
        {
            mmi_pen_register_down_handler(wgui_cat435_hilite_pen_down_handler);
            mmi_pen_register_move_handler(wgui_cat435_hilite_pen_move_handler);
            mmi_pen_register_up_handler(wgui_cat435_hilite_pen_up_handler);
        }
    }
}
#endif /* defined(__MMI_TOUCH_SCREEN__) */


/*****************************************************************************
 * FUNCTION
 *  category435_setup_log_box
 * DESCRIPTION
 *  setup log box
 * PARAMETERS
 *  log_buffer          [IN]        log box string buffer
 *  log_buffer_size     [IN]        log box buffer size
 * RETURNS
 *  void
 *****************************************************************************/
static void category435_setup_log_box(U8 *log_buffer, S32 log_buffer_size, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
     * In Arabic, the ailgnment format is decided by the content of file. 
     * * MSN align chat log to left.
     */
    S32 log_length;
    multi_line_input_box *b = &CAT435_CTX->log_box;
	S32 height = MMI_CONTENT_HEIGHT_WITH_H_TAB;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    log_length = gui_strlen((UI_string_type) log_buffer);
#ifdef __MMI_FTE_SUPPORT__
	if(wgui_icon_bar_is_created())
	{
		height -= MMI_ICON_BAR_HEIGHT;
	}
#endif
    gui_create_multi_line_input_box_set_buffer(
        b,
        MMI_CONTENT_X_WITH_H_TAB,
        MMI_CONTENT_Y_WITH_H_TAB,
        MMI_CONTENT_WIDTH_WITH_H_TAB,
        height,
        (UI_string_type) log_buffer,
        log_buffer_size * 2,
        (log_length + 1) * 2,
        0);
//	set_multiline_inputbox_category_history(MMI_CATEGORY151_ID, history_buffer);
	 wgui_inputs_ml_set_category_history_ext(b, MMI_CATEGORY435_ID, history_buffer);
    gui_move_multi_line_input_box(b, MMI_CONTENT_X_WITH_H_TAB, MMI_CONTENT_Y_WITH_H_TAB);
    gui_resize_multi_line_input_box(b, MMI_CONTENT_WIDTH_WITH_H_TAB, height);

    wgui_inputs_ml_set_style_with_obj(b, (UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | UI_MULTI_LINE_INPUT_BOX_VIEW_MODE |
         UI_MULTI_LINE_INPUT_BOX_RICHTEXT), 0);

#ifdef __MMI_WALLPAPER_ON_BOTTOM__
    b->flags |= UI_MULTI_LINE_INPUT_BOX_TRANSPARENT_BACKGROUND;
#endif 
    b->icon_callback = CAT435_CTX->icon_callback;
    if (g_wgui_catimps_bg_img_name != NULL)
    {
        b->normal_text_color = WGUI_CATIMPS_BG_IMG_TXT_COLOR;
    }

    if (g_wgui_cat435_hilite_list)
    {
        b->hilite_list = g_wgui_cat435_hilite_list;
        b->hilite_str_number = g_wgui_cat435_number_of_hilite_list;
        b->current_hilite_idx = (S32)g_wgui_cat435_current_hilite_index;
        b->hilite_cb = g_wgui_cat435_hilite_cb;
        b->flags |= UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        gui_multi_line_input_box_go_to_hilite_no_draw(
	            b, (U16)(b->current_hilite_idx));
#ifdef __MMI_TOUCH_SCREEN__
        wgui_cat435_register_hilite_pen_handler();
#endif /* __MMI_TOUCH_SCREEN__ */
    }

    // TODO: combine the following two procedure in one function in gui_inputs.c
    /* Compute text height and adjust scroll offset */
    b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_multi_line_input_box(b);
    b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    if ((b->text_height > b->edit_height) && (history_buffer == NULL))
    {
        b->text_offset_y = -(b->text_height - b->edit_height);
    }
}


/*****************************************************************************
 * FUNCTION
 *  category435_log_box_previous_line
 * DESCRIPTION
 *  log box goto previous line
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void category435_log_box_previous_line(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
    gui_multi_line_input_box_previous_line_with_hilite_list(&CAT435_CTX->log_box);
    gui_show_multi_line_input_box(&CAT435_CTX->log_box);
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  category435_log_box_next_line
 * DESCRIPTION
 *  category 435 goto next line
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void category435_log_box_next_line(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
    gui_multi_line_input_box_next_line_with_hilite_list(&CAT435_CTX->log_box);
    gui_show_multi_line_input_box(&CAT435_CTX->log_box);
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  category435_setup_editor_box
 * DESCRIPTION
 *  setup editor box
 * PARAMETERS
 *  buffer              [IN]        Input box buffer
 *  buffer_size         [IN]        Buffer size
 *  input_type          [IN]        Input type
 *  history_buffer      [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
static void category435_setup_editor_box(U8 *buffer, S32 buffer_size, U32 input_type, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 inputbox_x = CAT435_POPUP_X + CAT435_POPUP_H_GAP;
#ifdef __MMI_FTE_SUPPORT__
	S32 inputbox_y = CAT435_POPUP_Y - MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT;
    S32 inputbox_height = CAT435_POPUP_HEIGHT - CAT435_POPUP_BOTTOM_GAP + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT;
#else
    S32 inputbox_y = CAT435_POPUP_Y + CAT435_POPUP_TITLE_HEIGHT;
    S32 inputbox_height = CAT435_POPUP_HEIGHT - CAT435_POPUP_TITLE_HEIGHT - CAT435_POPUP_BOTTOM_GAP;
#endif
    S32 inputbox_width = CAT435_POPUP_WIDTH - CAT435_POPUP_H_GAP * 2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_FTE_SUPPORT__
    if(MMI_TRUE == wgui_icon_bar_is_created())
     {
         inputbox_height -= MMI_ICON_BAR_HEIGHT;
     }
#endif
    MMI_multiline_inputbox_width = inputbox_width;
    MMI_multiline_inputbox_height = inputbox_height;

    wgui_inputs_ml_setup_ext(
        inputbox_x,
        inputbox_y,
        inputbox_width,
        inputbox_height,
        buffer,
        buffer_size,
        MMI_CATEGORY435_ID,
        get_string(CAT435_CTX->editor_right_softkey),
        get_image(CAT435_CTX->editor_right_softkey_icon),
        input_type,
        history_buffer,
        NULL,
    #ifdef __MMI_FTE_SUPPORT__        
        0,
    #else
        1,
    #endif
        UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR,
        0,
        (S16) (CAT435_CTX->icon_height + 1),
        0,
        0,
        CAT435_CTX->icon_callback
        );

    /* Resize editor height */
    inputbox_height =
        CAT435_POPUP_HEIGHT - CAT435_POPUP_TITLE_HEIGHT - CAT435_POPUP_BOTTOM_GAP -
        wgui_inputbox_information_bar_height;
    inputbox_height -= wgui_inputs_get_current_imui_height(MMI_EDITOR_MULTILINE_INPUT_BOX);
#ifdef __MMI_FTE_SUPPORT__
	inputbox_height += CAT435_POPUP_TITLE_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT;
    if(MMI_TRUE == wgui_icon_bar_is_created())
     {
         inputbox_height -= MMI_ICON_BAR_HEIGHT;
     }
#endif
    wgui_inputs_ml_resize(inputbox_width, inputbox_height);
    wgui_inputs_ml_show_no_draw();

    /* Override editor style */
    MMI_multiline_inputbox.normal_filler = (UI_filled_area*)&g_mmi_gui_cat435_editor_filler;
    MMI_multiline_inputbox.normal_text_color = g_mmi_gui_cat435_editor_text_color;

	/* clear editor cache because editor cache content in setup, so it will not update after override color */
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    gui_mlc_all_line_update();
#endif

    /* Key handler (category435_reset_editor_box reset wgui_inputbox_RSK_function) */
    wgui_inputbox_RSK_function = CAT435_CTX->editor_RSK_func;
    SetLeftSoftkeyFunction(CAT435_CTX->editor_LSK_func, KEY_EVENT_UP);

    /* Virtual keyboard */
#ifdef __MMI_TOUCH_SCREEN__
    dm_register_vkpad_callback(mmi_imc_redraw_screen_by_state);
#endif 

    /* For draw manager, wgui_setup_inputbox_ext and wgui_close_inputbox should be paired. */
    MMI_DBG_ASSERT(!CAT435_CTX->editor_created);
    CAT435_CTX->editor_created = 1;
}


/*****************************************************************************
 * FUNCTION
 *  category435_reset_editor_box
 * DESCRIPTION
 *  reset editor box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void category435_reset_editor_box(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
    /* Virtual keyboard */
#ifdef __MMI_TOUCH_SCREEN__
    dm_register_vkpad_callback(NULL);
#endif 
    wgui_inputs_ml_close();
    gui_unlock_double_buffer();

    CAT435_CTX->editor_created = 0;
}


/*****************************************************************************
 * FUNCTION
 *  category435_draw_popup_background
 * DESCRIPTION
 *  redraw popup background
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void category435_draw_popup_background(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern UI_filled_area wgui_pop_up_dialog_background;
    S32 sw, sh; /* string width/height */
    S32 sx, sy;
    UI_filled_area f;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_push_clip();
    gui_reset_clip();

    gui_greyscale_rectangle(
        0,
        MMI_HORIZONTAL_TAB_BAR_Y + MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT,
        MMI_content_width - 1,
        CAT435_POPUP_Y + 15,    /* the dialog background has round corner */
        CAT435_BACKGROUND_WHITE_VALUE,
        MMI_BG_GREYSCALE_BLACK_VALUE);

    f = wgui_pop_up_dialog_background;
    f.c = g_mmi_gui_cat435_popup_color;
    f.border_color = current_ime_theme->cand_text_color;   /* Tricky. use multitap text color as border color */

    wgui_draw_pop_up_screen_background_style2(
        CAT435_POPUP_X,
        CAT435_POPUP_Y,
        CAT435_POPUP_X + CAT435_POPUP_WIDTH - 1,
        CAT435_POPUP_Y + CAT435_POPUP_HEIGHT - 1,
        (UI_filled_area*)&f,
        MMI_TRUE,
        MMI_FALSE,
        MMI_FALSE,
        MMI_FALSE);

    gui_set_font((UI_font_type)gui_font_get_type(GUI_FONT_SIZE_TITLE));
    gui_set_text_color(*current_MMI_theme->title_text_color);
#ifdef CAT435_POPUP_WITH_BORDER_TITLE
    gui_set_text_border_color(*current_MMI_theme->title_text_border_color);
#endif 
    Get_StringWidthHeight((U8*) CAT435_CTX->popup_title, &sw, &sh);

    if (sw > CAT435_POPUP_WIDTH)
    {
        sx = 0;
    }
    else
    {
        sx = (CAT435_POPUP_WIDTH - sw) >> 1;
    }

    if (sh > CAT435_POPUP_TITLE_HEIGHT)
    {
        sy = 0;
    }
    else
    {
        sy = (CAT435_POPUP_TITLE_HEIGHT - sh) >> 1;
    }

#ifdef CAT435_POPUP_WITH_BORDER_TITLE
    if (r2lMMIFlag)
    {
        gui_print_truncated_borderd_text(
            sx + CAT435_POPUP_X + sw - 1,
            sy + CAT435_POPUP_Y,
            CAT435_POPUP_WIDTH - sx,
            CAT435_CTX->popup_title);
    }
    else
    {
        gui_print_truncated_borderd_text(
            sx + CAT435_POPUP_X,
            sy + CAT435_POPUP_Y,
            CAT435_POPUP_WIDTH - sx,
            CAT435_CTX->popup_title);
    }
#else /* CAT435_POPUP_WITH_BORDER_TITLE */ 
    if (r2lMMIFlag)
    {
        gui_print_truncated_text(
            sx + CAT435_POPUP_X + sw - 1,
            sy + CAT435_POPUP_Y,
            CAT435_POPUP_WIDTH - sx,
            CAT435_CTX->popup_title);
    }
    else
    {
        gui_print_truncated_text(
            sx + CAT435_POPUP_X,
            sy + CAT435_POPUP_Y,
            CAT435_POPUP_WIDTH - sx,
            CAT435_CTX->popup_title);
    }
#endif /* CAT435_POPUP_WITH_BORDER_TITLE */ 

    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  category435_draw_content_area
 * DESCRIPTION
 *  redraw content area (between title and softkey)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void category435_draw_content_area(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Show background log area */
#ifdef CAT435_SHOW_LOG_BOX_WITH_POPUP
    gui_show_multi_line_input_box(&CAT435_CTX->log_box);
#else /* CAT435_SHOW_LOG_BOX_WITH_POPUP */ 
    if (!CAT435_CTX->show_popup)
    {
        gui_show_multi_line_input_box(&CAT435_CTX->log_box);
    }
#endif /* CAT435_SHOW_LOG_BOX_WITH_POPUP */ 

    /* Show editor in popup area */
    if (CAT435_CTX->show_popup)
    {
#ifndef __MMI_FTE_SUPPORT__
        category435_draw_popup_background();
#endif
        wgui_inputs_ml_show_with_information_bar();
    }

    if (RedrawSpellingOrCandidateBoxesFunction)
    {
        RedrawSpellingOrCandidateBoxesFunction();
    }
}


#if defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  category435_control_area_pen_handler
 * DESCRIPTION
 *  pen handler
 * PARAMETERS
 *  point           [IN]        pen event position
 *  pen_event       [IN]        pen event type
 * RETURNS
 *  Is handled
 *****************************************************************************/
static MMI_BOOL category435_control_area_pen_handler(mmi_pen_point_struct point, mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret;
    gui_multi_line_input_box_pen_enum logbox_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!CAT435_CTX)
    {
        MMI_DBG_ASSERT(0);
        return MMI_FALSE;
    }

    if (!CAT435_CTX->show_popup)
    {
        ret = gui_multi_line_input_box_translate_pen_event(
                &CAT435_CTX->log_box,
                pen_event,
                point.x,
                point.y,
                &logbox_event);
    }
    else
    {
        ret = MMI_FALSE;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  category435_control_area_pen_down_handler
 * DESCRIPTION
 *  pen down hanlder
 * PARAMETERS
 *  point       [IN]        pen down position
 * RETURNS
 *  Is handled
 *****************************************************************************/
static MMI_BOOL category435_control_area_pen_down_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return category435_control_area_pen_handler(point, MMI_PEN_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  category435_control_area_pen_move_handler
 * DESCRIPTION
 *  pen move handler
 * PARAMETERS
 *  point       [IN]        pen move position
 * RETURNS
 *  Is handled
 *****************************************************************************/
static MMI_BOOL category435_control_area_pen_move_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return category435_control_area_pen_handler(point, MMI_PEN_EVENT_MOVE);
}


/*****************************************************************************
 * FUNCTION
 *  category435_control_area_pen_longtap_handler
 * DESCRIPTION
 *  pen longtap handler
 * PARAMETERS
 *  point       [IN]        pen longtap position
 * RETURNS
 *  is handled
 *****************************************************************************/
static MMI_BOOL category435_control_area_pen_longtap_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return category435_control_area_pen_handler(point, MMI_PEN_EVENT_LONG_TAP);
}


/*****************************************************************************
 * FUNCTION
 *  category435_control_area_pen_repeat_handler
 * DESCRIPTION
 *  pen repeat handler
 * PARAMETERS
 *  point       [IN]        pen repeat position
 * RETURNS
 *  Is handled
 *****************************************************************************/
static MMI_BOOL category435_control_area_pen_repeat_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return category435_control_area_pen_handler(point, MMI_PEN_EVENT_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  category435_control_area_pen_up_handler
 * DESCRIPTION
 *  pen up handler
 * PARAMETERS
 *  point       [IN]        pen up position
 * RETURNS
 *  Is handled
 *****************************************************************************/
static MMI_BOOL category435_control_area_pen_up_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return category435_control_area_pen_handler(point, MMI_PEN_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  category435_control_area_pen_abort_handler
 * DESCRIPTION
 *  pen abort handler
 * PARAMETERS
 *  point       [IN]        pen abort position
 * RETURNS
 *  Is handled
 *****************************************************************************/
static MMI_BOOL category435_control_area_pen_abort_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return category435_control_area_pen_handler(point, MMI_PEN_EVENT_ABORT);
}
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 


/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ExitCategory420Screen
 * DESCRIPTION
 *  Exit the category420 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategory420Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    category420_free_image_cache();
    reset_softkeys();
    wgui_inputs_ml_reset();

#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    if (CAT420_CTX->cache_buf_ptr != NULL)
    {
        mmi_frm_scrmem_free(CAT420_CTX->cache_buf_ptr);
        CAT420_CTX->cache_buf_ptr = NULL;
    }
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */

    OslMfree(g_mmi_gui_cat420_context_p);
    g_mmi_gui_cat420_context_p = NULL;
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void ShowCategory420Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        UI_string_type name,
        S8 *photo_filename,
        U16 alternative_photo,
        U16 mood_caption,
        UI_string_type mood_string,
        PU8 mood_icon,
        U16 status_caption,
        UI_string_type status_string,
        PU8 status_icon,
        U8 *buffer,
        S32 buffer_size,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Category 420 is a read-only multi-line inputbox with decoration */

    S32 l;
    S32 img_width, img_height;
    S32 use_alternative_image = 0;
    color tc;
    dm_data_struct dm_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_gui_cat420_context_p = OslMalloc(sizeof(gui_cat420_context_struct));
    CAT420_CTX->name = name;
    CAT420_CTX->mood_caption = mood_caption;
    CAT420_CTX->mood_string = mood_string;
    CAT420_CTX->mood_icon = mood_icon;
    CAT420_CTX->status_caption = status_caption;
    CAT420_CTX->status_string = status_string;
    CAT420_CTX->status_icon = status_icon;

    /* Compute image dimension for rendering layout */
    if (!photo_filename || gdi_image_get_dimension_file(photo_filename, &img_width, &img_height) != GDI_IMAGE_SUCCEED)
    {
        if (!alternative_photo ||
            gdi_image_get_dimension((U8*) GetImage(alternative_photo), &img_width, &img_height) != GDI_IMAGE_SUCCEED)
        {
            CAT420_CTX->image_ori_width = 0;
            CAT420_CTX->image_ori_height = 0;
            CAT420_CTX->display_image = MMI_FALSE;
        }
        else
        {
            CAT420_CTX->image_ori_width = (S16) img_width;
            CAT420_CTX->image_ori_height = (S16) img_height;
            CAT420_CTX->display_image = MMI_TRUE;
            use_alternative_image = 1;
        }
    }
    else
    {
        CAT420_CTX->image_ori_width = (S16) img_width;
        CAT420_CTX->image_ori_height = (S16) img_height;
        CAT420_CTX->display_image = MMI_TRUE;
        use_alternative_image = 0;
    }

    category420_compute_layout();
    category420_cache_image(photo_filename, (U8*) GetImage(alternative_photo), use_alternative_image);

    gui_lock_double_buffer();

    wgui_title_set_menu_shortcut_number(-1);
    wgui_title_disable_menu_shortcut_display(MMI_TRUE);

    dm_add_softkey(get_string(left_softkey), get_image(left_softkey_icon), get_string(right_softkey), get_image(right_softkey_icon));
    dm_add_title(get_string(title), get_image(title_icon));

    wgui_set_wallpaper_on_bottom(MMI_TRUE);

    l = gui_strlen((UI_string_type) buffer);
    wgui_inputs_ml_create_set_buffer((UI_string_type) buffer, buffer_size, l, 0);
    wgui_inputs_ml_register_viewer_keys();
    wgui_inputs_ml_move(MMI_content_x, MMI_content_y);
    wgui_inputs_ml_resize(MMI_multiline_inputbox.width, MMI_content_height);
    MMI_multiline_inputbox.flags |= (UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW |
                                     UI_MULTI_LINE_INPUT_BOX_VIEW_MODE |
                                     UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR |
                                     UI_MULTI_LINE_INPUT_BOX_TRANSPARENT_BACKGROUND);
    MMI_multiline_inputbox.header_callback = category420_header_callback;
    MMI_multiline_inputbox.header_height = CAT420_CTX->editor_header_height;
    MMI_multiline_inputbox.footer_height = CAT420_EDITOR_BOTTOM_PADDING;
    /* Better visual effect */
    MMI_multiline_inputbox.min_text_height = MMI_content_height - CAT420_EDITOR_BOTTOM_PADDING;
    MMI_multiline_inputbox.text_filler = &g_mmi_gui_cat420_text_filler;
    tc.r = CAT420_TEXT_COLOR_R;
    tc.g = CAT420_TEXT_COLOR_G;
    tc.b = CAT420_TEXT_COLOR_B;
    tc.alpha = 100;
    MMI_multiline_inputbox.normal_text_color = tc;
    MMI_multiline_inputbox.text_x = CAT420_EDITOR_LEFT_BORDER_PADDING;
    MMI_multiline_inputbox.text_x2_gap_width = CAT420_EDITOR_RIGHT_BORDER_PADDING + 2 /* 2 for editor border */;
    /* resize_multiline_inputbox() recomputes MMI_multiline_inputbox.edit_width by 'text_x' and 'text_x2_gap' */
    wgui_inputs_ml_resize(MMI_multiline_inputbox.width, MMI_multiline_inputbox.height);

    MMI_multiline_inputbox.normal_filler = &g_mmi_gui_cat420_bg_filler;

    wgui_inputs_ml_show_no_draw();

    wgui_inputs_ml_set_category_history(MMI_CATEGORY420_ID, history_buffer);

    gui_unlock_double_buffer();

    ExitCategoryFunction = ExitCategory420Screen;
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY420_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();
}


/*****************************************************************************
 * FUNCTION
 *  RedrawCategory425Screen
 * DESCRIPTION
 *  Redraw the category425 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RedrawCategory425Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
    show_title_status_icon();
    show_asyncdynamic_list();
    if (CAT425_CTX->num_tab)
    {
        wgui_show_horizontal_tab_bar();
    }
    show_softkey_background();
    show_left_softkey();
    show_right_softkey();
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory425Screen
 * DESCRIPTION
 *  Exit the category425 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategory425Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    if (CAT425_CTX->num_tab)
    {
        wgui_close_horizontal_tab_bar();
    }
    reset_asyncdynamic_list();
    reset_pop_up_descriptions();

    category425_reset_context();
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory425HistorySize
 * DESCRIPTION
 *  Gets the size of the history buffer for category425 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *  Returns
 *****************************************************************************/
S32 GetCategory425HistorySize(void)
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
 *  GetCategory425History
 * DESCRIPTION
 *  Get history for category425 screen
 * PARAMETERS
 *  history_buffer      [IN]        Is the buffer into which the history data is stored (pre-allocated)
 * RETURNS
 *  Pointer to the history buffer
 *****************************************************************************/
U8 *GetCategory425History(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_list_menu_category_history(MMI_CATEGORY425_ID, history_buffer);
    return history_buffer;
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void ShowCategory425Screen(
        UI_string_type title,
        PU8 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S8 n_tabs,
        S8 highlighted_tab,
        tab_bar_item_type *tab_items,
        S32 number_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        PU8 sample_icon,
        PU8 sample_icon2,
        S32 highlighted_item,
        U8 *history_buffer,
        BOOL *list_is_ready_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    S32 icon_height, icon_width, icon2_height, icon2_width, text_width;
    S32 tmp_string_width;
	S32 shortcut_width;
    int i;
    S32 catid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_asyncdynamic_list_error = 0;
    *list_is_ready_p = MMI_FALSE;
    g_mmi_gui_cat425_context_p = OslMalloc(sizeof(gui_cat425_context_struct));

    CAT425_CTX->get_item_func = get_item_func;
    CAT425_CTX->get_hint_func = get_hint_func;

    MMI_title_string = NULL;
    MMI_title_icon = NULL;

    gui_lock_double_buffer();

    dm_add_softkey(get_string(left_softkey), get_image(left_softkey_icon), get_string(right_softkey), get_image(right_softkey_icon));

    /* Setup tab bar */
    CAT425_CTX->num_tab = n_tabs;
    if (n_tabs)
    {
        for (i = 0; i < n_tabs; i++)
        {
            MMI_tab_bar_items[i] = tab_items[i];
        }
        wgui_create_horizontal_tab_bar(TRUE, title, n_tabs, highlighted_tab, MMI_FALSE);

        CAT425_CTX->content_x = MMI_CONTENT_X_WITH_H_TAB;
        CAT425_CTX->content_y = MMI_CONTENT_Y_WITH_H_TAB;
        CAT425_CTX->content_width = MMI_CONTENT_WIDTH_WITH_H_TAB;
        CAT425_CTX->content_height = MMI_CONTENT_HEIGHT_WITH_H_TAB;
        catid = MMI_CATEGORY425_ID;
    }
    else
    {
        dm_add_title((UI_string_type)title, (PU8)title_icon);
        CAT425_CTX->content_x = MMI_content_x;
        CAT425_CTX->content_y = MMI_content_y;
        CAT425_CTX->content_width = MMI_content_width;
        CAT425_CTX->content_height = MMI_content_height;
        catid = MMI_CATEGORY425_NO_TAB_ID;
    }

    /* Setup layout of menu */
    if(!(wgui_async_list_create_multi_icontext_menu(
            number_of_items,
            2,
            3,
            get_item_func,
            get_hint_func,
            highlighted_item,
            MMI_MENUITEM_HEIGHT,
            0,
            (U16)catid,
            history_buffer)))
    {
        MMI_DBG_ASSERT(0);  /* not recoverable */
        category425_reset_context();
        gui_unlock_double_buffer();
        return;
    }

    gui_measure_image(sample_icon, &icon_width, &icon_height);
    gui_measure_image(sample_icon2, &icon2_width, &icon2_height);
    if (icon_width == 0 || icon_height == 0)
    {
        icon_width = CAT425_DEFAULT_ICON_WIDTH;
        icon_height = CAT425_DEFAULT_ICON_HEIGHT;
    }
    if (icon2_width == 0 || icon2_height == 0)
    {
        icon2_width = CAT425_DEFAULT_ICON2_WIDTH;
        icon2_height = CAT425_DEFAULT_ICON2_HEIGHT;
    }

    tmp_string_width = gui_get_string_width((UI_string_type) L"[");
    text_width = UI_device_width - MMI_fixed_list_menu.vbar.width - CAT425_ICON_X -
        icon_width - CAT425_ICON_TEXT_GAP - CAT425_TEXT_SCROLLBAR_GAP;
    set_fixed_icontext_list_icon_coordinates(0, CAT425_ICON_X, CAT425_ICON_Y, icon_width, icon_height);
    if (r2lMMIFlag)
    {
        set_fixed_icontext_list_icon_coordinates(
            1,
            CAT425_ICON_X + icon_width - icon2_width,
            CAT425_ICON_Y + icon_height - icon2_height,
            icon2_width,
            icon2_height);
    }
    else
    {
        set_fixed_icontext_list_icon_coordinates(
            1,
            CAT425_ICON_X,
            CAT425_ICON_Y + icon_height - icon2_height,
            icon2_width,
            icon2_height);
    }
    set_fixed_icontext_list_icon_coordinates(2, CAT425_ICON_X, CAT425_ICON_Y, icon_width, icon_height);

    set_fixed_icontext_list_text_coordinates(
        0,
        CAT425_ICON_X + icon_width + CAT425_ICON_TEXT_GAP,
        CAT425_TEXT1_Y,
        text_width,
        CAT425_TEXT_HEIGHT);
    set_fixed_icontext_list_text_coordinates(
        1,
        CAT425_ICON_X + icon_width + CAT425_ICON_TEXT_GAP + tmp_string_width + CAT425_TEXT2_BRACKET_GAP,
        CAT425_TEXT2_Y,
        text_width - (tmp_string_width + CAT425_TEXT2_BRACKET_GAP) * 2,
        CAT425_TEXT_HEIGHT);

    CAT425_CTX->icon_border_x1 = CAT425_ICON_X;
    CAT425_CTX->icon_border_y1 = CAT425_ICON_Y;
    CAT425_CTX->icon_border_x2 = CAT425_ICON_X + icon_width - 1;
    CAT425_CTX->icon_border_y2 = CAT425_ICON_Y + icon_height - 1;
    CAT425_CTX->bracket_x = CAT425_ICON_X + icon_width + CAT425_ICON_TEXT_GAP;
    CAT425_CTX->bracket_y = CAT425_TEXT2_Y;


#ifdef __MMI_SCREEN_ROTATE__
     if (!mmi_frm_is_screen_width_height_swapped())
#endif /* __MMI_SCREEN_ROTATE__ */
    {
        if (n_tabs)
        {
            MMI_fixed_icontext_list_menuitem.focussed_filler = current_MMI_theme->menuitem_thick_with_tab_highlight_filler;
            MMI_fixed_icontext_list_menuitem.selected_filler = current_MMI_theme->menuitem_thick_with_tab_highlight_filler;            
        }
        else
        {
            MMI_fixed_icontext_list_menuitem.focussed_filler = current_MMI_theme->menuitem_thick_highlight_filler;
            MMI_fixed_icontext_list_menuitem.selected_filler = current_MMI_theme->menuitem_thick_highlight_filler;             
        }
    }
    
    set_fixed_icontext_list_menuitems_post_display(category425_post_display_menuitem);
    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_AUTO_CHOOSE_MARQUEE;
    resize_fixed_icontext_list_menuitems(0, n_tabs ? CAT425_MENUITEM_HEIGHT : CAT425_MENUITEM_HEIGHT_NO_TAB);   /* Tricky! do this after associate_fixed_icontext_list_list() */
    CAT425_CTX->backup_menu_flags = MMI_fixed_list_menu.flags;
    CAT425_CTX->backup_menu_filler = MMI_fixed_list_menu.normal_filler;

    /* Override style */
    category425_setup_text_color();
    MMI_fixed_icontext_list_menuitem.flags &=
        ~(UI_MENUITEM_CENTER_TEXT_X | UI_MENUITEM_CENTER_TEXT_Y | UI_MENUITEM_CENTER_ICON_X |
          UI_MENUITEM_CENTER_ICON_Y);

    wgui_async_list_resize_multi_icontext_menu(CAT425_CTX->content_width, CAT425_CTX->content_height);
    wgui_async_list_move_multi_icontext_menu(CAT425_CTX->content_x, CAT425_CTX->content_y);
    if (gui_asyncdynamic_list_error)
    {
        MMI_DBG_ASSERT(0);  /* not recoverable */
        category425_reset_context();
        gui_unlock_double_buffer();
        return;
    }

    /* Setup (hidden) menu shortcut. */
	shortcut_width = set_menu_item_count(number_of_items) + 7;
    if (n_tabs)
    {
        resize_menu_shortcut_handler(shortcut_width, MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT);
        move_menu_shortcut_handler(
            MMI_HORIZONTAL_TAB_BAR_X + MMI_HORIZONTAL_TAB_BAR_WIDTH - MMI_menu_shortcut_box.width,
            MMI_HORIZONTAL_TAB_BAR_Y + MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT);
        register_hide_menu_shortcut(wgui_show_horizontal_tab_bar_hint_area);
    }
    else
    {
        resize_menu_shortcut_handler(shortcut_width, MMI_title_height);
        move_menu_shortcut_handler(MMI_title_x + MMI_title_width - MMI_menu_shortcut_box.width, MMI_title_y);
        register_hide_menu_shortcut(gui_redraw_menu_shortcut);
    }

    gui_unlock_double_buffer();

    ExitCategoryFunction = ExitCategory425Screen;
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = catid;

#ifdef __MMI_WALLPAPER_ON_BOTTOM__
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND; 
#else
    dm_data.s32flags = 0;
#endif 
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();

    *list_is_ready_p = MMI_TRUE;
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void RefreshCategory425Screen(S32 number_of_items, S32 highlighted_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 shortcut_width;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_mmi_gui_cat425_context_p)
    {
        MMI_DBG_ASSERT(0);
        return;
    }

    gui_asyncdynamic_list_error = 0;

    gui_lock_double_buffer();

    MMI_fixed_list_menu.n_items = number_of_items;

    wgui_title_set_menu_shortcut_number(highlighted_item + 1);
    shortcut_width = set_menu_item_count(number_of_items) + 7;
    if (CAT425_CTX->num_tab)
    {
        resize_menu_shortcut_handler(shortcut_width, MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT);
        move_menu_shortcut_handler(
            MMI_HORIZONTAL_TAB_BAR_X + MMI_HORIZONTAL_TAB_BAR_WIDTH - MMI_menu_shortcut_box.width,
            MMI_HORIZONTAL_TAB_BAR_Y + MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT);
    }
    else
    {
        resize_menu_shortcut_handler(shortcut_width, MMI_title_height);
        move_menu_shortcut_handler(MMI_title_x + MMI_title_width - MMI_menu_shortcut_box.width, MMI_title_y);
    }

    init_asyncdynamic_item_buffer(number_of_items, CAT425_CTX->get_item_func, CAT425_CTX->get_hint_func);

    asyncdynamic_list_goto_item_no_redraw(highlighted_item);
    if (gui_asyncdynamic_list_error)
    {
        MMI_DBG_ASSERT(0);  /* not recoverable */
        category425_reset_context();
        gui_unlock_double_buffer();
        return;
    }

    set_asyncdynamic_pop_up_descriptions(highlighted_item);

    gui_unlock_double_buffer();

    RedrawCategoryFunction();
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void UpdateCategory425TabBar(UI_string_type title, S8 n_tabs, S8 highlighted_tab, tab_bar_item_type *tab_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!CAT425_CTX || !CAT425_CTX->num_tab)
    {
        MMI_DBG_ASSERT(0);
        return;
    }

    if (title == NULL)
    {
        title = MMI_horizontal_tab_bar.hint;
    }

    gui_lock_double_buffer();

    wgui_close_horizontal_tab_bar();

    /* Setup horizontal tab bar */
    for (i = 0; i < n_tabs; i++)
    {
        MMI_tab_bar_items[i] = tab_items[i];
    }

    wgui_create_horizontal_tab_bar(TRUE, title, n_tabs, highlighted_tab, MMI_TRUE);

    gui_unlock_double_buffer();

    wgui_show_horizontal_tab_bar();
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void SetCategory425TabSelectCallback(void (*select_callback) (int index))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(CAT425_CTX && CAT425_CTX->num_tab);

    wgui_set_horizontal_tab_bar_select_callback(select_callback);
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void Category425BlinkTab(S8 tab)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(CAT425_CTX && CAT425_CTX->num_tab);

    wgui_horizontal_tab_bar_start_blinking(tab);
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void Category425UnBlinkTab(S8 tab)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(CAT425_CTX && CAT425_CTX->num_tab);

    wgui_horizontal_tab_bar_stop_blinking(tab);
}

#if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) || defined(__MMI_SMART_MESSAGE_MT__) || defined(__MMI_MYPICTURE__)

/*****************************************************************************
 * FUNCTION
 *  mmi_nsm2_category275_draw_inbox_header
 * DESCRIPTION
 *  redraw NSM2 category inbox header
 * PARAMETERS
 *  yy      [IN]        (not used)
 *  x1      [IN]        start  x
 *  y1      [IN]        start  y
 *  x2      [IN]        end  x
 *  y2      [IN]        end  y
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nsm2_category275_draw_inbox_header(MMI_BOOL is_draw, S32 yy, S32 height, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 pic_offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_draw == MMI_FALSE)
    {
        return ;
    }
    
    pic_offset = ((LCD_WIDTH - current_MMI_theme->scrollbar_size) >> 1) - 36;   /* To align nsm picture in centre */
    gui_show_image(x1 + pic_offset, y1 + MMI_multiline_inputbox.text_offset_y + 1, (U8*) gNSMBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategoryNSM2Screen
 * DESCRIPTION
 *  Displays the category420 screen
 *  
 *  The pointer of name, mood_string, status_string are used directly  in category 420.
 *  They should not be released before category 420 exits.
 *  photo_filename can be released immediately after ShowCategory420Screen() returns.
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  name                    [IN]        User Name
 *  photo_filename          [IN]        File name of photo
 *  alternative_photo       [IN]        Default photo if 'photo_filename' is NULL
 *  mood_caption            [IN]        String ID to "Mood" literally
 *  mood_string             [IN]        Text indicating mood
 *  mood_icon               [IN]        Image indicating mood
 *  status_caption          [IN]        String ID to "Status" literally
 *  status_string           [IN]        Text indicating mood
 *  status_icon             [IN]        Image indicating mood
 *  buffer                  [IN]        Buffer the input box should use.
 *  buffer_size             [IN]        Size of the buffer.
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategoryNSM2Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        UI_string_type name,
        S8 *photo_filename,
        U16 alternative_photo,
        U16 mood_caption,
        UI_string_type mood_string,
        PU8 mood_icon,
        U16 status_caption,
        UI_string_type status_string,
        PU8 status_icon,
        U8 *buffer,
        S32 buffer_size,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    S32 l;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_gui_cat420_context_p = OslMalloc(sizeof(gui_cat420_context_struct));
    CAT420_CTX->name = name;
    CAT420_CTX->mood_caption = mood_caption;
    CAT420_CTX->mood_string = mood_string;
    CAT420_CTX->mood_icon = mood_icon;
    CAT420_CTX->status_caption = status_caption;
    CAT420_CTX->status_string = status_string;
    CAT420_CTX->status_icon = status_icon;

    CAT420_CTX->image_ori_width = 120;
    CAT420_CTX->image_ori_height = 30;
    CAT420_CTX->display_image = MMI_TRUE;

    category420_compute_layout();
    gui_lock_double_buffer();

    wgui_title_set_menu_shortcut_number(-1);
    wgui_title_disable_menu_shortcut_display(MMI_TRUE);
    clear_category_screen_key_handlers();
    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);
    clear_left_softkey();
    clear_right_softkey();
    register_left_softkey_handler();
    register_right_softkey_handler();
    register_default_hide_softkeys();

    l = gui_strlen((UI_string_type) buffer);
    create_multiline_inputbox_set_buffer((UI_string_type) buffer, buffer_size, l, 0);
    register_multiline_inputbox_viewer_keys();

    MMI_multiline_inputbox.flags |= (UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | UI_MULTI_LINE_INPUT_BOX_VIEW_MODE);
    MMI_multiline_inputbox.header_callback = mmi_nsm2_category275_draw_inbox_header;    /* To draw image */
    /* JP to fix NSM Picture image and chinese character overlapping */
    MMI_multiline_inputbox.header_height = MAX_NSM_PIC_HEIGHT;  

    MMI_multiline_inputbox.min_text_height = 14;

    show_multiline_inputbox_no_draw();

    set_multiline_inputbox_category_history(MMI_CATEGORY420_ID, history_buffer);
    MMI_title_string = (UI_string_type) get_string(title);
    MMI_title_icon = (PU8) get_image(title_icon);

    gui_unlock_double_buffer();

    ExitCategoryFunction = ExitCategoryNSM2Screen;
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY420_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();

}


/*****************************************************************************
 * FUNCTION
 *  ExitCategoryNSM2Screen
 * DESCRIPTION
 *  Exit the categoryNS screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategoryNSM2Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    reset_softkeys();
    reset_multiline_inputbox();
    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = MMI_dummy_function;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;

    OslMfree(g_mmi_gui_cat420_context_p);
    g_mmi_gui_cat420_context_p = NULL;
}

#endif /* (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) || defined(__MMI_SMART_MESSAGE_MT__) || defined(__MMI_MYPICTURE__) */ 


/* 
 * Category 428
 */
/*****************************************************************************
 * FUNCTION
 *  wgui_cat_tree_reset_context
 * DESCRIPTION
 *  reset context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat_tree_reset_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fixed_icontext_list_menuitem_apply_current_theme();
    OslMfree(g_mmi_gui_cat_tree_context_p);
    g_mmi_gui_cat_tree_context_p = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_imps_scrolling_timer
 * DESCRIPTION
 *  category scrolling timer handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat_imps_scrolling_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_handle_scrolling_text(&imps_scroll_text);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_imps_scrolling_text_draw_background
 * DESCRIPTION
 *  Draw category scrolling text draw background
 * PARAMETERS
 *  x1      [IN]        Start x posityion
 *  y1      [IN]        Start y position
 *  x2      [IN]        End x position
 *  y2      [IN]        End y position
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat_imps_scrolling_text_draw_background(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_tree_highlight_handler
 * DESCRIPTION
 *  tree highlight handler
 * PARAMETERS
 *  item_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat_tree_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 view_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    view_index = MMI_fixed_list_menu.highlighted_item;

    wgui_title_set_menu_shortcut_number(view_index + 1);
    MMI_highlighted_item_text = get_asyncdynamic_item_text(view_index);

    /* real index */
	MMI_user_highlight_handler_Ext((U8)eListhighlight, item_index);

#if(UI_ENABLE_POP_UP_DESCRIPTIONS)
    gui_pop_up_description_stop_scroll();
    wgui_current_pop_up_description_index = view_index;
#endif /* (UI_ENABLE_POP_UP_DESCRIPTIONS) */ 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_tree_is_parent_node
 * DESCRIPTION
 *  Checks if a tree item is a parent.
 * PARAMETERS
 *  item_index       [IN]   item index
 * RETURNS
 *  MMI_TRUE if yes; otherwise MMI_FALSE
 *****************************************************************************/
static MMI_BOOL wgui_cat_tree_is_parent_node(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CAT_TREE_CTX->get_state_funcptr(item_index) & WGUI_TREE_ITEM_FLAG_PARENT) 
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_tree_get_child_num
 * DESCRIPTION
 *  Gets the number of childs of a parent.
 * PARAMETERS
 *  item_index       [IN]   parent index
 * RETURNS
 *  Number of childs.
 *****************************************************************************/
static S32 wgui_cat_tree_get_child_num(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    S32 child_num;
    S32 parent_level;
    
    child_num = 0;
    parent_level = CAT_TREE_CTX->get_level_funcptr(item_index);

    while (++item_index < CAT_TREE_CTX->n_items)
    {    
        if ((CAT_TREE_CTX->get_level_funcptr(item_index) <= parent_level) || wgui_cat_tree_is_parent_node(item_index))
        {
            break;
        }
        else
        {
            child_num++;            
        }       
    }    

    return child_num;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_tree_is_hidden_node
 * DESCRIPTION
 *  Checks if a tree item is hidden.
 * PARAMETERS
 *  item_index       [IN]   item index
 * RETURNS
 *  MMI_TRUE if yes; otherwise MMI_FALSE
 *****************************************************************************/
static MMI_BOOL wgui_cat_tree_is_hidden_node(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CAT_TREE_CTX->get_state_funcptr(item_index) & WGUI_TREE_ITEM_FLAG_HIDDEN) 
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

void (*gui_hide_animations_temp) (void) = UI_dummy_function;
static GDI_HANDLE cat428_animation_handle;

/*****************************************************************************
 * FUNCTION
 *  wgui_cat428_redraw_information
 * DESCRIPTION
 *  redraw category428 information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 static void wgui_cat428_redraw_information(void)
 {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w1, h1;
	S32 y = 0, y1, y2;
	S32 tool_bar_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(CAT_TREE_CTX->information == NULL)
        return;
#if defined(__MMI_FTE_SUPPORT__)
    if(MMI_TRUE == wgui_icon_bar_is_created())
     {
         tool_bar_height = MMI_ICON_BAR_HEIGHT;
     }
#endif
	y1 = MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_MENUITEM_HEIGHT - tool_bar_height -1;
	y2 = MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - tool_bar_height - 1;
    gui_measure_string((UI_string_type) CAT_TREE_CTX->information, &w1, &h1);

	if(h1 < MMI_MENUITEM_HEIGHT)
	{
		y += (MMI_MENUITEM_HEIGHT - h1)>>1;
	}

    gui_lock_double_buffer();
    gdi_draw_solid_rect(0,  y1, UI_device_width, y2, GDI_COLOR_TRANSPARENT); 
    gdi_image_draw_animation(5, y1, CAT_TREE_CTX->info_image, &cat428_animation_handle);

    gui_create_scrolling_text(
            &imps_scroll_text,
            35,
            y1 + y,
            (UI_device_width - 10),
            MMI_MENUITEM_HEIGHT - y,
            (UI_string_type) CAT_TREE_CTX->information,
            wgui_cat_imps_scrolling_timer,
            wgui_cat_imps_scrolling_text_draw_background,
            gui_color(0, 0, 0),
            gui_color(255, 255, 255));
    gui_show_scrolling_text(&imps_scroll_text);

    gui_unlock_double_buffer();

}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat428_redraw_controlled_area
 * DESCRIPTION
 *  redraw category428 control area
 * PARAMETERS
 *  coordinate      [IN]     Area to redraw
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat428_redraw_controlled_area(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(coordinate);
    wgui_cat428_redraw_information();
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory428Screen
 * DESCRIPTION
 *  Exit the category428 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategory428Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif
	gdi_image_stop_animation(cat428_animation_handle);
	gui_hide_animations = gui_hide_animations_temp;
    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    if (CAT_TREE_CTX->num_tab)
    {
        wgui_close_horizontal_tab_bar();
    }
    wgui_tree_close();
    wgui_catimps_set_bg_img_name((U8*)NULL);
	wgui_reset_horizontal_tab_bar_scroll();
    reset_asyncdynamic_list();
    reset_pop_up_descriptions();
    gui_scrolling_text_stop(&imps_scroll_text);
    wgui_cat_tree_reset_context();
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void ShowCategory428Screen(
        UI_string_type title,
        PU8 title_icon,
        UI_string_type left_softkey,
        PU8 left_softkey_icon,
        UI_string_type right_softkey,
        PU8 right_softkey_icon,
        S8 n_tabs,
        S8 highlighted_tab,
        tab_bar_item_type *tab_items,
        S32 number_of_items,
        wgui_tree_get_item_callback_funcptr_type get_item_func,
        wgui_tree_get_hint_callback_funcptr_type get_hint_func,
        wgui_tree_get_item_level_callback_funcptr_type get_level_callback,
        wgui_tree_get_item_state_callback_funcptr_type get_state_func,
        wgui_tree_set_item_state_callback_funcptr_type set_state_callback,
        wgui_tree_folder_clicked_callback_funcptr_type folder_clicked_callback,
        PU8 sample_icon,
        PU8 sample_icon2,
        S32 highlighted_item,
        UI_string_type information,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    int i;
    S32 icon_height, icon_width, icon2_height, icon2_width, text_width, text1_width;
    S32 h, num = highlighted_item;
    S32 tool_bar_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_asyncdynamic_list_error = 0;
    gui_hide_animations_temp = gui_hide_animations;
    cat428_animation_handle = GDI_ERROR_HANDLE;
    g_mmi_gui_cat_tree_context_p = OslMalloc(sizeof(gui_cat_tree_context_struct));
    memset(g_mmi_gui_cat_tree_context_p, 0, sizeof(gui_cat_tree_context_struct));    

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif
    gui_lock_double_buffer();
    dm_add_softkey(left_softkey, left_softkey_icon, right_softkey, right_softkey_icon);

    CAT_TREE_CTX->num_tab = n_tabs;   /* tab */
    if (n_tabs)
    {
        for (i = 0; i < n_tabs; i++)
        {
            MMI_tab_bar_items[i] = tab_items[i];
        }
        wgui_create_horizontal_tab_bar(TRUE, title, n_tabs, highlighted_tab, MMI_FALSE);

        CAT_TREE_CTX->content_x = MMI_CONTENT_X_WITH_H_TAB;
        CAT_TREE_CTX->content_y = MMI_CONTENT_Y_WITH_H_TAB;
        CAT_TREE_CTX->content_width = MMI_CONTENT_WIDTH_WITH_H_TAB;
        CAT_TREE_CTX->content_height = MMI_CONTENT_HEIGHT_WITH_H_TAB - MMI_MENUITEM_HEIGHT;
    }
    else
    {
        dm_add_title(title, title_icon);
        CAT_TREE_CTX->content_x = MMI_content_x;
        CAT_TREE_CTX->content_y = MMI_content_y;
        CAT_TREE_CTX->content_width = MMI_content_width;
        CAT_TREE_CTX->content_height = MMI_content_height - MMI_MENUITEM_HEIGHT;
    }
#if defined(__MMI_FTE_SUPPORT__)
    if(MMI_TRUE == wgui_icon_bar_is_created())
     {
         tool_bar_height = MMI_ICON_BAR_HEIGHT;
     }
     CAT_TREE_CTX->content_height -= tool_bar_height;
#endif
    CAT_TREE_CTX->get_level_funcptr = get_level_callback;
    CAT_TREE_CTX->get_state_funcptr = get_state_func;
    CAT_TREE_CTX->n_items = number_of_items;
    CAT_TREE_CTX->information = information;   /* Information Bar */
    if(information == NULL)
    {
        CAT_TREE_CTX->content_height += MMI_MENUITEM_HEIGHT;
    }
    wgui_set_disable_shortcut_display();
	for(i = 0; i < num; i++)
    {
        if(wgui_cat_tree_is_parent_node(i) && wgui_cat_tree_is_hidden_node(i))
        {
            highlighted_item -= wgui_cat_tree_get_child_num(i);
        }
    }
    /* tree list */
	 resize_fixed_list(CAT_TREE_CTX->content_width, CAT_TREE_CTX->content_height);
    if (n_tabs)
    {
        wgui_tree_create(
            number_of_items,
            3,
            MMI_MENUITEM_HEIGHT,
            get_item_func,
            get_hint_func,
            get_level_callback,
            get_state_func,
            set_state_callback,
            folder_clicked_callback,
            wgui_cat_tree_highlight_handler,
            highlighted_item,
            MMI_CATEGORY428_ID,
            history_buffer);
    }
    else
    {
        wgui_tree_create(
            number_of_items,
            3,
            MMI_MENUITEM_HEIGHT,
            get_item_func,
            get_hint_func,
            get_level_callback,
            get_state_func,
            set_state_callback,
            folder_clicked_callback,
            wgui_cat_tree_highlight_handler,
            highlighted_item,
            MMI_CATEGORY428_NO_TAB_ID,
            history_buffer);
    }

    move_fixed_list(CAT_TREE_CTX->content_x, CAT_TREE_CTX->content_y);
    wgui_tree_set_level_coordinate_num(0, 1, 1);    /* for group */
    wgui_tree_set_level_coordinate_num(1, 1, 3);    /* for list */
    wgui_tree_set_level_coordinate_num(2, 1, 1);    /* for myself */

    gui_measure_image(sample_icon, &icon_width, &icon_height);
    gui_measure_image(sample_icon2, &icon2_width, &icon2_height);
    if (icon_width == 0 || icon_height == 0)
    {
        icon_width = CAT428_DEFAULT_ICON_WIDTH;
        icon_height = CAT428_DEFAULT_ICON_HEIGHT;
    }

    if (icon2_width == 0 || icon2_height == 0)
    {
        icon2_width = CAT428_DEFAULT_ICON2_WIDTH;
        icon2_height = CAT428_DEFAULT_ICON2_HEIGHT;
    }

    text_width = UI_device_width - MMI_fixed_list_menu.vbar.width - GUI_ICONTEXT_MENUITEM_TEXT_X - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - GUI_MENUITEM_TEXT_RIGHT_GAP;
    text1_width = UI_device_width - MMI_fixed_list_menu.vbar.width - GUI_ICONTEXT_MENUITEM_TEXT_X -
        icon_width - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - GUI_MENUITEM_TEXT_RIGHT_GAP;

    if (MMI_MENUITEM_HEIGHT > icon_height)
    {
        h = (MMI_MENUITEM_HEIGHT - icon_height) >> 1;
    }
    else
    {
        h = 0;
    }

    /* level 0 for group */
    wgui_tree_set_icon_coordinate(0, 0, GUI_ICONTEXT_MENUITEM_ICON_X, h, icon_width, icon_height);
    wgui_tree_set_text_coordinate(0, 0, GUI_ICONTEXT_MENUITEM_TEXT_X, 0, text_width, MMI_MENUITEM_HEIGHT);

    /* level 1 for list */
    wgui_tree_set_icon_coordinate(1, 0, GUI_ICONTEXT_MENUITEM_ICON_X + icon_width, h, icon_width, icon_height);

    wgui_tree_set_icon_coordinate(
            1,
            1,
            GUI_ICONTEXT_MENUITEM_ICON_X + icon_width,
            icon_height - icon2_height,
            icon2_width,
            icon2_height);


    wgui_tree_set_icon_coordinate(1, 2, GUI_ICONTEXT_MENUITEM_ICON_X + icon_width, h, icon_width, icon_height);
    wgui_tree_set_text_coordinate(
            1,
            0, 
            GUI_ICONTEXT_MENUITEM_TEXT_X + icon_width,
            0, 
            text1_width, 
            MMI_MENUITEM_HEIGHT); 

    /* level 2 for myself */
    wgui_tree_set_icon_coordinate(2, 0, GUI_ICONTEXT_MENUITEM_ICON_X, h, icon_width, icon_height);
    wgui_tree_set_text_coordinate(2, 0, GUI_ICONTEXT_MENUITEM_TEXT_X, 0, text_width, MMI_MENUITEM_HEIGHT);

    MMI_fixed_icontext_list_menuitem.flags &= ~(UI_MENUITEM_CENTER_ICON_X | UI_MENUITEM_CENTER_ICON_Y);

    if (gui_asyncdynamic_list_error)
    {
        MMI_DBG_ASSERT(0);  /* not recoverable */
        wgui_cat_tree_reset_context();
        gui_unlock_double_buffer();
        return;
    }

    gui_unlock_double_buffer();
    ExitCategoryFunction = ExitCategory428Screen;
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();

    if (n_tabs)
    {
        dm_data.s32CatId = MMI_CATEGORY428_ID;
    }
    else
    {
        dm_data.s32CatId = MMI_CATEGORY428_NO_TAB_ID;
    }

#ifdef __MMI_WALLPAPER_ON_BOTTOM__
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
#else
    dm_data.s32flags = 0;
#endif 
    dm_setup_data(&dm_data);
    dm_register_category_controlled_callback(wgui_cat428_redraw_controlled_area);
    dm_redraw_category_screen();
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void ShowCategory428Screen_sty1(
        UI_string_type title,
        PU8 title_icon,
        UI_string_type left_softkey,
        PU8 left_softkey_icon,
        UI_string_type right_softkey,
        PU8 right_softkey_icon,
        S8 n_tabs,
        S8 highlighted_tab,
        tab_bar_item_type *tab_items,
        S32 number_of_items,
        wgui_tree_get_item_callback_funcptr_type get_item_func,
        wgui_tree_get_hint_callback_funcptr_type get_hint_func,
        wgui_tree_get_item_level_callback_funcptr_type get_level_callback,
        wgui_tree_get_item_state_callback_funcptr_type get_state_func,
        wgui_tree_set_item_state_callback_funcptr_type set_state_callback,
        wgui_tree_folder_clicked_callback_funcptr_type folder_clicked_callback,
        PU8 sample_icon,
        PU8 sample_icon2,
        S32 highlighted_item,
        UI_string_type information,
        PU8 info_image,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    int i;
    S32 icon_height, icon_width, text_width, text1_width, icon2_height, icon2_width;
    S32 h, num = highlighted_item;
    S32 x1;
    S32 tool_bar_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_asyncdynamic_list_error = 0;
    cat428_animation_handle = GDI_ERROR_HANDLE;
    gui_hide_animations_temp = gui_hide_animations;
    gui_hide_animations = UI_dummy_function;
    g_mmi_gui_cat_tree_context_p = OslMalloc(sizeof(gui_cat_tree_context_struct));
    memset(g_mmi_gui_cat_tree_context_p, 0, sizeof(gui_cat_tree_context_struct));    

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif
    gui_lock_double_buffer();
    dm_add_softkey(left_softkey, left_softkey_icon, right_softkey, right_softkey_icon);
    if (g_wgui_catimps_bg_img_name != NULL)
	{
	    dm_set_scr_bg_image(0, (S8*)g_wgui_catimps_bg_img_name, -1, -1, 255);
	    dm_set_scr_bg_opacity(WGUI_CATIMPS_BG_IMG_OPACITY);
	}

    CAT_TREE_CTX->num_tab = n_tabs;   /* tab */

    for (i = 0; i < n_tabs; i++)
    {
        MMI_tab_bar_items[i] = tab_items[i];
    }
    wgui_create_horizontal_tab_bar(TRUE, title, n_tabs, highlighted_tab, MMI_FALSE);
    wgui_set_horizontal_tab_bar_title(title_icon, title);
	wgui_set_horizontal_tab_bar_scroll();

    CAT_TREE_CTX->content_x = MMI_CONTENT_X_WITH_H_TAB;
    CAT_TREE_CTX->content_y = MMI_CONTENT_Y_WITH_H_TAB;
    CAT_TREE_CTX->content_width = MMI_CONTENT_WIDTH_WITH_H_TAB;
    CAT_TREE_CTX->content_height = MMI_CONTENT_HEIGHT_WITH_H_TAB - MMI_MENUITEM_HEIGHT;

    CAT_TREE_CTX->get_level_funcptr = get_level_callback;
    CAT_TREE_CTX->get_state_funcptr = get_state_func;
    CAT_TREE_CTX->n_items = number_of_items;
    CAT_TREE_CTX->information = information;   /* Information Bar */
    CAT_TREE_CTX->info_image = info_image;
    if(CAT_TREE_CTX->information == NULL)
    {
        CAT_TREE_CTX->content_height += MMI_MENUITEM_HEIGHT;
    }
#if defined(__MMI_FTE_SUPPORT__)
    if(MMI_TRUE == wgui_icon_bar_is_created())
     {
         tool_bar_height = MMI_ICON_BAR_HEIGHT;
     }
     CAT_TREE_CTX->content_height -= tool_bar_height;
#endif
    wgui_set_disable_shortcut_display();
	for(i = 0; i < num; i++)
    {
        if(wgui_cat_tree_is_parent_node(i) && wgui_cat_tree_is_hidden_node(i))
        {
            highlighted_item -= wgui_cat_tree_get_child_num(i);
        }
    }
    /* tree list */
	 resize_fixed_list(CAT_TREE_CTX->content_width, CAT_TREE_CTX->content_height);
 
    wgui_tree_create(
            number_of_items,
            3,
            MMI_MENUITEM_HEIGHT,
            get_item_func,
            get_hint_func,
            get_level_callback,
            get_state_func,
            set_state_callback,
            folder_clicked_callback,
            wgui_cat_tree_highlight_handler,
            highlighted_item,
            MMI_CATEGORY428_ID,
            history_buffer);
 

    move_fixed_list(CAT_TREE_CTX->content_x, CAT_TREE_CTX->content_y);
    wgui_tree_set_level_coordinate_num(0, 1, 1);    /* for group */
    wgui_tree_set_level_coordinate_num(1, 1, 2);    /* for group with icon */
    wgui_tree_set_level_coordinate_num(2, 1, 3);    /* for contact list */

    gui_measure_image(sample_icon, &icon_width, &icon_height);
    gui_measure_image(sample_icon2, &icon2_width, &icon2_height);
    if (icon_width == 0 || icon_height == 0)
    {
        icon_width = CAT428_DEFAULT_ICON_WIDTH;
        icon_height = CAT428_DEFAULT_ICON_HEIGHT;
    }

    text_width = UI_device_width - MMI_fixed_list_menu.vbar.width - GUI_ICONTEXT_MENUITEM_TEXT_X - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - GUI_MENUITEM_TEXT_RIGHT_GAP;
    
    text1_width = text_width - icon_width - CAT428_ICON_TEXT_GAP;
    x1 = GUI_ICONTEXT_MENUITEM_TEXT_X + text1_width + CAT428_ICON_TEXT_GAP;
    if (MMI_MENUITEM_HEIGHT > icon_height)
    {
        h = (MMI_MENUITEM_HEIGHT - icon_height) >> 1;
    }
    else
    {
        h = 0;
    }

    /* level 0 for group */
    wgui_tree_set_icon_coordinate(0, 0, GUI_ICONTEXT_MENUITEM_ICON_X, h, icon_width, icon_height);
    wgui_tree_set_text_coordinate(0, 0, GUI_ICONTEXT_MENUITEM_TEXT_X, 0, text_width, MMI_MENUITEM_HEIGHT);
    
    /* level 1 for group with right icon*/
    wgui_tree_set_icon_coordinate(1, 0, GUI_ICONTEXT_MENUITEM_ICON_X, h, icon_width, icon_height);
    wgui_tree_set_text_coordinate(1, 0, GUI_ICONTEXT_MENUITEM_TEXT_X, 0, text1_width, MMI_MENUITEM_HEIGHT); 
	wgui_tree_set_icon_coordinate(1, 1, x1, h, text1_width, icon_height);   

    /* level 2 for list */
    wgui_tree_set_icon_coordinate(2, 0, GUI_ICONTEXT_MENUITEM_ICON_X, h, icon_width, icon_height);
    wgui_tree_set_icon_coordinate(2, 1, GUI_ICONTEXT_MENUITEM_TEXT_X , h, icon_width, icon_height);
    wgui_tree_set_icon_coordinate(2, 2, GUI_ICONTEXT_MENUITEM_TEXT_X + icon_width - icon2_width, icon_height - icon2_height, icon2_width, icon2_height);
    wgui_tree_set_text_coordinate(
            2,
            0, 
            GUI_ICONTEXT_MENUITEM_TEXT_X + icon_width + CAT428_ICON_TEXT_GAP,
            0, 
            text1_width, 
            MMI_MENUITEM_HEIGHT); 

    MMI_fixed_icontext_list_menuitem.flags &= ~(UI_MENUITEM_CENTER_ICON_X | UI_MENUITEM_CENTER_ICON_Y);

    if (gui_asyncdynamic_list_error)
    {
        MMI_DBG_ASSERT(0);  /* not recoverable */
        wgui_cat_tree_reset_context();
        gui_unlock_double_buffer();
        return;
    }

    gui_unlock_double_buffer();
    ExitCategoryFunction = ExitCategory428Screen;
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();


    dm_data.s32CatId = MMI_CATEGORY428_ID;

#ifdef __MMI_WALLPAPER_ON_BOTTOM__
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
#else
    dm_data.s32flags = 0;
#endif 
    dm_setup_data(&dm_data);
    dm_register_category_controlled_callback(wgui_cat428_redraw_controlled_area);
    dm_redraw_category_screen();
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void wgui_cat428_update_title(UI_string_type title, PU8 title_icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!CAT_TREE_CTX || !CAT_TREE_CTX->num_tab)
    {
        MMI_DBG_ASSERT(0);
        return;
    }

    if (title == MMI_horizontal_tab_bar.hint && title_icon == MMI_horizontal_tab_bar.hint_icon )
    {
		return;
	}
	wgui_reset_horizontal_tab_bar_scroll();
    gui_lock_double_buffer();
    wgui_set_horizontal_tab_bar_title(title_icon, title);
    wgui_set_horizontal_tab_bar_scroll();
    gui_unlock_double_buffer();

    wgui_show_horizontal_tab_bar();
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void wgui_cat428_refresh_list(S32 number_of_items, S32 highlighted_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 num = highlighted_item; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_mmi_gui_cat_tree_context_p)
    {
        MMI_DBG_ASSERT(0);
        return;
    }
    if(number_of_items > 0)
    {
        CAT_TREE_CTX->n_items = number_of_items;
    }
    
    for(i = 0; i < num; i++)
    {
        if(wgui_cat_tree_is_parent_node(i) && wgui_cat_tree_is_hidden_node(i))
        {
            highlighted_item -= wgui_cat_tree_get_child_num(i);
        }
    }
    gui_asyncdynamic_list_error = 0;

    gui_lock_double_buffer();
    resize_fixed_list(CAT_TREE_CTX->content_width, CAT_TREE_CTX->content_height);
    wgui_tree_update(number_of_items, highlighted_item);
    if (gui_asyncdynamic_list_error)
    {
        MMI_DBG_ASSERT(0);  /* not recoverable */
        wgui_cat_tree_reset_context();
        gui_unlock_double_buffer();
        return;
    }

    gui_unlock_double_buffer();
    wgui_tree_show();
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void wgui_cat428_refresh_informationbar(UI_string_type information, PU8 info_image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 tool_bar_height = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_scrolling_text_stop(&imps_scroll_text);
    gdi_image_stop_animation(cat428_animation_handle);
    CAT_TREE_CTX->information = information;
    CAT_TREE_CTX->info_image = info_image;
#if defined(__MMI_FTE_SUPPORT__)
    if(MMI_TRUE == wgui_icon_bar_is_created())
     {
         tool_bar_height = MMI_ICON_BAR_HEIGHT;
     }
#endif
    if( information == NULL)
    {
        CAT_TREE_CTX->content_width = MMI_CONTENT_WIDTH_WITH_H_TAB;
        CAT_TREE_CTX->content_height = MMI_CONTENT_HEIGHT_WITH_H_TAB - tool_bar_height;
    }
    else
    {
        CAT_TREE_CTX->content_width = MMI_CONTENT_WIDTH_WITH_H_TAB;
        CAT_TREE_CTX->content_height = MMI_CONTENT_HEIGHT_WITH_H_TAB - MMI_MENUITEM_HEIGHT - tool_bar_height;       
    }
    gui_lock_double_buffer();

    wgui_cat428_redraw_information();
    wgui_cat428_refresh_list(-1, -1);
    gui_unlock_double_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void wgui_cat428_update_tabbar(UI_string_type title, PU8 title_icon, S8 n_tabs, S8 highlighted_tab, tab_bar_item_type *tab_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!CAT_TREE_CTX || !CAT_TREE_CTX->num_tab)
    {
        MMI_DBG_ASSERT(0);
        return;
    }

    if (title == NULL)
    {
        title = MMI_horizontal_tab_bar.hint;
    }

    gui_lock_double_buffer();

    wgui_close_horizontal_tab_bar();

    /* Setup horizontal tab bar */
    for (i = 0; i < n_tabs; i++)
    {
        MMI_tab_bar_items[i] = tab_items[i];
    }

    wgui_create_horizontal_tab_bar(TRUE, title, n_tabs, highlighted_tab, MMI_TRUE);
    wgui_set_horizontal_tab_bar_title(title_icon, title);
    wgui_set_horizontal_tab_bar_scroll();
    gui_unlock_double_buffer();

    wgui_show_horizontal_tab_bar();
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void wgui_cat428_SetTabSelectCallback(void (*select_callback) (int index))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(CAT_TREE_CTX && CAT_TREE_CTX->num_tab);
    wgui_set_horizontal_tab_bar_select_callback(select_callback);
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void wgui_cat428_BlinkTab(S8 tab)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(CAT_TREE_CTX && CAT_TREE_CTX->num_tab);
    wgui_horizontal_tab_bar_start_blinking(tab);
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void wgui_cat428_UnBlinkTab(S8 tab)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(CAT_TREE_CTX && CAT_TREE_CTX->num_tab);
    wgui_horizontal_tab_bar_stop_blinking(tab);
}

/* 
 * Category 429
 */


/*****************************************************************************
 * FUNCTION
 *  ExitCategory429Screen
 * DESCRIPTION
 *  Exit the category429 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategory429Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    reset_softkeys();
    wgui_inputs_ml_reset();
    gui_scrolling_text_stop(&scroll_text_cat429);
    OslMfree(g_mmi_gui_cat429_context_p);
    g_mmi_gui_cat429_context_p = NULL;
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void ShowCategory429Screen(
        UI_string_type title,
        PU8 title_icon,
        UI_string_type left_softkey,
        PU8 left_softkey_icon,
        UI_string_type right_softkey,
        PU8 right_softkey_icon,
        UI_string_type name,
        UI_string_type userid,
        PU8 status_icon,
        S8 *photo_filename,
        PU8 alternative_photo,
        UI_string_type mood_caption,
        PU8 mood_icon,
        UI_string_type device_caption,
        UI_string_type device_string,
        U8 *buffer,
        S32 buffer_size,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 l;
    S32 img_width, img_height;
    dm_data_struct dm_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_gui_cat429_context_p = OslMalloc(sizeof(gui_cat429_context_struct));
    memset(g_mmi_gui_cat429_context_p, 0, sizeof(gui_cat429_context_struct));    

    CAT429_CTX->name = name;
    CAT429_CTX->userid = userid;
    CAT429_CTX->mood_caption = mood_caption;
    CAT429_CTX->mood_icon = mood_icon;
    CAT429_CTX->status_icon = status_icon;
    CAT429_CTX->device_caption = device_caption;
    CAT429_CTX->device_string = device_string;
    CAT429_CTX->photo_filename = photo_filename;
    CAT429_CTX->alternative_photo = alternative_photo;
    CAT429_CTX->use_alternative_image = 0;
    
    /* Title */
    dm_add_title(title, title_icon);

    /* Compute image dimension for rendering layout */
    if (!photo_filename || gdi_image_get_dimension_file(photo_filename, &img_width, &img_height) != GDI_IMAGE_SUCCEED)
    {
        if (!alternative_photo ||
            gdi_image_get_dimension((U8*) alternative_photo, &img_width, &img_height) != GDI_IMAGE_SUCCEED)
        {
            CAT429_CTX->image_ori_width = 0;
            CAT429_CTX->image_ori_height = 0;
            CAT429_CTX->display_image = MMI_FALSE;
        }
        else
        {
            CAT429_CTX->image_ori_width = (S16) img_width;
            CAT429_CTX->image_ori_height = (S16) img_height;
            CAT429_CTX->display_image = MMI_TRUE;
            CAT429_CTX->use_alternative_image = 1;
        }
    }
    else
    {
        CAT429_CTX->image_ori_width = (S16) img_width;
        CAT429_CTX->image_ori_height = (S16) img_height;
        CAT429_CTX->display_image = MMI_TRUE;
        CAT429_CTX->use_alternative_image = 0;
    }

    wgui_cat429_compute_layout();

    gui_lock_double_buffer();

    wgui_title_set_menu_shortcut_number(-1);
    wgui_title_disable_menu_shortcut_display(MMI_TRUE);
    dm_add_softkey(left_softkey, left_softkey_icon, right_softkey, right_softkey_icon);
    l = gui_strlen((UI_string_type) buffer);
    wgui_inputs_ml_create_set_buffer((UI_string_type) buffer, buffer_size, l, 0);
    wgui_inputs_ml_register_viewer_keys();
    MMI_multiline_inputbox.flags |= (UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW |
                                     UI_MULTI_LINE_INPUT_BOX_VIEW_MODE |
                                     UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR |
                                     UI_MULTI_LINE_INPUT_BOX_TRANSPARENT_BACKGROUND);

    MMI_multiline_inputbox.header_callback = wgui_cat429_header_callback;
    MMI_multiline_inputbox.header_height = CAT429_CTX->editor_header_height;
    /* Better visual effect */
    MMI_multiline_inputbox.min_text_height = MMI_content_height - CAT429_CONTROLLED_AREA_HEIGHT - CAT429_LEFT_MARGIN;
    MMI_multiline_inputbox.normal_text_color = *current_MMI_theme->inputbox_normal_text_color;
    MMI_multiline_inputbox.text_x = CAT429_LEFT_MARGIN;
    wgui_inputs_ml_set_category_history(MMI_CATEGORY429_ID, history_buffer);

    gui_unlock_double_buffer();
    ExitCategoryFunction = ExitCategory429Screen;
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY429_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    dm_setup_data(&dm_data);
    dm_register_category_controlled_callback(wgui_cat429_draw_control_area);
    dm_redraw_category_screen();
}

/* 
 * Category 430
 */


/*****************************************************************************
 * FUNCTION
 *  ExitCategory430Screen
 * DESCRIPTION
 *  Exits the category430 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategory430Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    reset_softkeys();
    wgui_inputs_ml_close();

    if (CAT430_CTX->allocated_color_buffer)
    {
        OslMfree(CAT430_CTX->allocated_color_buffer);
    }

    //OslMfree(g_mmi_gui_cat430_context_p);
    if(g_mmi_gui_cat430_context_p != NULL)
    {
        mmi_frm_scrmem_free(g_mmi_gui_cat430_context_p);
    }
    g_mmi_gui_cat430_context_p = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory430HistorySize
 * DESCRIPTION
 *  Gets the size of the history buffer for category430 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  size in U8 of the history buffer
 *****************************************************************************/
S32 GetCategory430HistorySize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Use the four bytes to check if popup exists */
    return sizeof(gui_cat430_history_header_struct);
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory430History
 * DESCRIPTION
 *  Gets the history buffer for category430 screen
 * PARAMETERS
 *  history_buffer      [IN]        Is the buffer into which the history data is stored (pre-allocated)
 * RETURNS
 *  Pointer to the history buffer
 *****************************************************************************/
U8 *GetCategory430History(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Use the four bytes to check if popup exists */
    MMI_ASSERT(g_mmi_gui_cat430_context_p);

    return (history_buffer);
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void ShowCategory430Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U8 *log_buffer1,
        S16 log_buffer_size1,
        U8 *log_buffer2,
        S16 log_buffer_size2,
        MMI_BOOL show_sending_buffer,
        S16 max_sending_buffer_size,
        U8 *sending_buffer,
        S16 sent_count,
        U8 *name1,
        U8 *name2,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    S32 font_height, log_box_height;
	U32 buff_size;

    /*----------------------------------------------------------------*/
    /* Global Variables                                                */
    /*----------------------------------------------------------------*/
    //g_mmi_gui_cat430_context_p = OslMalloc(sizeof(gui_cat430_context_struct)); 
	buff_size = sizeof(gui_cat430_context_struct);
	g_mmi_gui_cat430_context_p = mmi_frm_scrmem_alloc_framebuffer(buff_size);
    memset(g_mmi_gui_cat430_context_p, 0, sizeof(gui_cat430_context_struct));    

    CAT430_CTX->name1 = name1;
    CAT430_CTX->name2 = name2;
    CAT430_CTX->log_buffer1 = log_buffer1;
    CAT430_CTX->log_buffer_size1 = log_buffer_size1;
    CAT430_CTX->log_buffer2 = log_buffer2;
    CAT430_CTX->log_buffer_size2 = log_buffer_size2;

    CAT430_CTX->show_sending_buffer = show_sending_buffer;
    CAT430_CTX->max_sending_buffer_size = max_sending_buffer_size;

    CAT430_CTX->sending_buffer = sending_buffer;
    CAT430_CTX->sent_count = sent_count;

    CAT430_CTX->allocated_color_buffer_size = (max_sending_buffer_size + CAT430_MARKER_COUNT + 1) * 2;
    CAT430_CTX->allocated_color_buffer = OslMalloc(CAT430_CTX->allocated_color_buffer_size);

    /*----------------------------------------------------------------*/
    /* Compute Layout                                                  */
    /*----------------------------------------------------------------*/
    font_height = Get_CharHeightOfAllLang(CAT430_NAME_FONT_ENUM);
#ifndef CAT430_NAME_IN_LOG
    log_box_height = MMI_content_height - (font_height << 1) - (CAT430_VERTICAL_GAP * 5);
    log_box_height >>= 1;
    MMI_DBG_ASSERT(log_box_height > 0);
#else /* CAT430_NAME_IN_LOG */ 
    CAT430_CTX->log_box_header_height = font_height + CAT430_VERTICAL_GAP;
    log_box_height = MMI_content_height - (CAT430_VERTICAL_GAP * 3);
    log_box_height >>= 1;
    MMI_DBG_ASSERT(log_box_height > 0);
#endif /* CAT430_NAME_IN_LOG */ 

#ifndef CAT430_NAME_IN_LOG
    CAT430_CTX->name1_x = CAT430_HORIZONTAL_GAP;
    CAT430_CTX->name1_y = MMI_content_y + CAT430_VERTICAL_GAP;
    CAT430_CTX->log_box1_y = CAT430_CTX->name1_y + font_height + CAT430_VERTICAL_GAP;
#else /* CAT430_NAME_IN_LOG */ 
    CAT430_CTX->log_box1_y = MMI_content_y + CAT430_VERTICAL_GAP;
#endif /* CAT430_NAME_IN_LOG */ 
    CAT430_CTX->log_box1_x = CAT430_HORIZONTAL_GAP;
    CAT430_CTX->log_box1_width = MMI_content_width - CAT430_HORIZONTAL_GAP * 2;
    CAT430_CTX->log_box1_height = log_box_height;
#ifndef CAT430_NAME_IN_LOG
    CAT430_CTX->name2_x = CAT430_HORIZONTAL_GAP;
    CAT430_CTX->name2_y = CAT430_CTX->log_box1_y + CAT430_CTX->log_box1_height + CAT430_VERTICAL_GAP;
    CAT430_CTX->log_box2_y = CAT430_CTX->name2_y + font_height + CAT430_VERTICAL_GAP;
#else /* CAT430_NAME_IN_LOG */ 
    CAT430_CTX->log_box2_y = CAT430_CTX->log_box1_y + CAT430_CTX->log_box1_height + CAT430_VERTICAL_GAP;
#endif /* CAT430_NAME_IN_LOG */ 
    CAT430_CTX->log_box2_x = CAT430_HORIZONTAL_GAP;
    CAT430_CTX->log_box2_width = CAT430_CTX->log_box1_width;
    CAT430_CTX->log_box2_height = log_box_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();

    wgui_title_set_menu_shortcut_number(-1);
    wgui_title_disable_menu_shortcut_display(MMI_TRUE);

    dm_add_softkey(get_string(left_softkey), get_image(left_softkey_icon), get_string(right_softkey), get_image(right_softkey_icon));
    dm_add_title(get_string(title), get_image(title_icon));

    category430_setup_sending_box();
    category430_setup_log_box1();
    category430_setup_log_box2();

    SetKeyHandler(category430_previous_line, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(category430_next_line, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(category430_previous_line, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(category430_next_line, KEY_VOL_DOWN, KEY_EVENT_DOWN);

    gui_unlock_double_buffer();

    ExitCategoryFunction = ExitCategory430Screen;
    dm_register_category_controlled_callback(category430_draw_controlled_area);
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY430_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_category_screen_control_area_pen_handlers(
        category430_control_area_pen_down_handler,
        MMI_PEN_EVENT_DOWN);
    wgui_register_category_screen_control_area_pen_handlers(category430_control_area_pen_up_handler, MMI_PEN_EVENT_UP);
    wgui_register_category_screen_control_area_pen_handlers(
        category430_control_area_pen_move_handler,
        MMI_PEN_EVENT_MOVE);
    wgui_register_category_screen_control_area_pen_handlers(
        category430_control_area_pen_repeat_handler,
        MMI_PEN_EVENT_REPEAT);
    wgui_register_category_screen_control_area_pen_handlers(
        category430_control_area_pen_longtap_handler,
        MMI_PEN_EVENT_LONG_TAP);
    wgui_register_category_screen_control_area_pen_handlers(
        category430_control_area_pen_abort_handler,
        MMI_PEN_EVENT_ABORT);
#endif /* __MMI_TOUCH_SCREEN__ */ 
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void UpdateCategory430LogBox(MMI_BOOL update_log1, MMI_BOOL update_log2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_mmi_gui_cat430_context_p);

    if (update_log1)
    {
        category430_setup_log_box1();
    }
    if (update_log2)
    {
        category430_setup_log_box2();
    }
    RedrawCategoryFunction();
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void ConfigureCategory430SendingBox(MMI_BOOL show_sending_buffer, S16 sent_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_mmi_gui_cat430_context_p);

    CAT430_CTX->show_sending_buffer = show_sending_buffer;
    CAT430_CTX->sent_count = sent_count;

    category430_setup_sending_box();
    /* Setup logbox2 because 'log_box2_footer_height' might be changed */
    category430_setup_log_box2();
    RedrawCategoryFunction();
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void SetCategory430SendingBoxCharacterCount(S16 sent_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CAT430_CTX->sent_count = sent_count;
    RedrawCategoryFunction();
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void UpdateCategory430LSK(U16 left_softkey, U16 left_softkey_icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();

    change_left_softkey(left_softkey, left_softkey_icon);
    /* setup key handler again if previous softkey is empty */
    register_left_softkey_handler();
    register_right_softkey_handler();
    register_default_hide_softkeys();

    show_softkey_background();
    show_left_softkey();
    show_right_softkey();
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void UpdateCategory430RSK(U16 right_softkey, U16 right_softkey_icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();

    change_right_softkey(right_softkey, right_softkey_icon);
    /* setup key handler again if previous softkey is empty */
    register_left_softkey_handler();
    register_right_softkey_handler();
    register_default_hide_softkeys();

    show_softkey_background();
    show_left_softkey();
    show_right_softkey();
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
}

/* 
 * Category 435
 */


/*****************************************************************************
 * FUNCTION
 *  category435_draw_controlled_area
 * DESCRIPTION
 *  Category-controlled area draw callback for category435 screen
 * PARAMETERS
 *  coordinate      [IN]     area to redraw
 * RETURNS
 *  void
 *****************************************************************************/
void category435_draw_controlled_area(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(coordinate);
    category435_draw_content_area();
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void SetCategory435EditorRSKFunction(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CAT435_CTX->editor_RSK_func = f;
    wgui_inputbox_RSK_function = f;
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void SetCategory435EditorLSKFunction(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ShowCategory435Screen should be invoked first */
    MMI_ASSERT(CAT435_CTX);

    CAT435_CTX->editor_LSK_func = f;
    if (CAT435_CTX->show_popup)
    {
        SetLeftSoftkeyFunction(f, KEY_EVENT_UP);
    }
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void SetCategory435RSKFunction(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ShowCategory435Screen should be invoked first */
    MMI_ASSERT(CAT435_CTX);

    CAT435_CTX->RSK_func = f;
    if (!CAT435_CTX->show_popup)
    {
        SetRightSoftkeyFunction(f, KEY_EVENT_UP);
    }
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void SetCategory435LSKFunction(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ShowCategory435Screen should be invoked first */
    MMI_ASSERT(CAT435_CTX);

    CAT435_CTX->LSK_func = f;
    if (!CAT435_CTX->show_popup)
    {
        SetLeftSoftkeyFunction(f, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory435Screen
 * DESCRIPTION
 *  Exits the category435 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategory435Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    reset_softkeys();
    wgui_reset_horizontal_tab_bar_scroll();
    wgui_close_horizontal_tab_bar();
    if (CAT435_CTX->show_popup)
    {
        category435_reset_editor_box();
    }
	else
	{
		wgui_inputs_ml_close();
	}
#ifdef __MMI_WALLPAPER_ON_BOTTOM__
    dm_set_scr_bg_opacity(editor_scr_bg_opacity);
#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */ 

    /* Restore context */
    MMI_multiline_inputbox_width = CAT435_CTX->backup_MMI_editor_width;
    MMI_multiline_inputbox_height = CAT435_CTX->backup_MMI_editor_height;

    current_information_bar_theme->background_alpha = CAT435_CTX->backup_information_bar_alpha;
    current_information_bar_theme->background_color = CAT435_CTX->backup_information_bar_color;

    if(g_mmi_gui_cat435_context_p != NULL)
    {
        mmi_frm_scrmem_free(g_mmi_gui_cat435_context_p);
    }
    g_mmi_gui_cat435_context_p = NULL;
    g_wgui_cat435_text_lengh_changed_hdlr = NULL;
    wgui_catimps_set_bg_img_name((U8*)NULL);
    
    g_wgui_cat435_hilite_list = NULL;
    g_wgui_cat435_number_of_hilite_list = 0;
    g_wgui_cat435_current_hilite_index = 0;
    g_wgui_cat435_hilite_cb = NULL;
    g_wgui_cat435_hilite_click_cb = NULL;

#if defined(__MMI_TOUCH_SCREEN__)
    g_wgui_cat435_is_ml_pen_down = MMI_FALSE;
#endif /* defined(__MMI_TOUCH_SCREEN__) */
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory435HistorySize
 * DESCRIPTION
 *  Gets the size of the history buffer for category435 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  size in U8 of the history buffer
 *****************************************************************************/
static S32 GetCategory435HistorySize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return sizeof(gui_cat435_history_header_struct) + sizeof(multiline_inputbox_category_history);
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory435History
 * DESCRIPTION
 *  Gets the history buffer for category435 screen
 * PARAMETERS
 *  history_buffer      [IN]        Is the buffer into which the history data is stored (pre-allocated)
 * RETURNS
 *  Pointer to the history buffer
 *****************************************************************************/
static U8 *GetCategory435History(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_cat435_history_header_struct *h = (gui_cat435_history_header_struct*) history_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h->show_popup = (U8) CAT435_CTX->show_popup;
    if (CAT435_CTX->show_popup)
    {
        /* Get editor history only if editor is active */
        get_multiline_inputbox_category_history(
            MMI_CATEGORY435_ID,
            history_buffer + sizeof(gui_cat435_history_header_struct));

    }
	else
	{
		wgui_inputs_ml_get_category_history_ext(
			&CAT435_CTX->log_box, 
			MMI_CATEGORY435_ID,
			 history_buffer + sizeof(gui_cat435_history_header_struct));

    }
    return (history_buffer);
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void UpdateCategory435LogText(U8 *log_buffer, S32 log_buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ShowCategory435Screen should be invoked first */
    MMI_ASSERT(CAT435_CTX);

    gui_lock_double_buffer();
    category435_setup_log_box(log_buffer, log_buffer_size, NULL);
    gui_unlock_double_buffer();

    /* We do not update the background if popup is displayed */
    if (!CAT435_CTX->show_popup)
    {
        RedrawCategoryFunction();
    }
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void UpdateCategory435LogAndEditorText(U8 *buffer, S32 buffer_size, U8 *log_buffer, S32 log_buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ShowCategory435Screen should be invoked first */
    MMI_ASSERT(CAT435_CTX);

    gui_lock_double_buffer();

    /* Setup log box */
    category435_setup_log_box(log_buffer, log_buffer_size, NULL);

    /* Setup editor box */
    CAT435_CTX->buffer = buffer;
    CAT435_CTX->buffer_size = buffer_size;
    if (CAT435_CTX->show_popup)
    {
        /* If IME is active. We need to abort it */
        category435_reset_editor_box();
        category435_setup_editor_box(buffer, buffer_size, CAT435_CTX->input_type, NULL);
    }

    gui_unlock_double_buffer();
    RedrawCategoryFunction();
}


/*****************************************************************************
 * FUNCTION
 *  Category435ShowPopupInternal
 * DESCRIPTION
 *  set show popup
 * PARAMETERS
 *  update_screen       [IN]        Is update screen
 *  history_buffer      [IN]        history buffer
 *  force_execution     [IN]        Is force executrion
 * RETURNS
 *  void
 *****************************************************************************/
static void Category435ShowPopupInternal(BOOL update_screen, U8 *history_buffer, BOOL force_execution)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CAT435_CTX->show_popup && !force_execution)
    {
        /* Popup already displayed */
        return;
    }

    CAT435_CTX->show_popup = MMI_TRUE;

#if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_FTE_SUPPORT__)
    wgui_enable_horizontal_tab_bar_pen_events(MMI_FALSE);
#endif 
    wgui_reset_horizontal_tab_bar_scroll();

    gui_lock_double_buffer();

    ClearInputEventHandler(MMI_DEVICE_KEY);
    change_left_softkey(CAT435_CTX->editor_left_softkey, CAT435_CTX->editor_left_softkey_icon);
    change_right_softkey(CAT435_CTX->editor_right_softkey, CAT435_CTX->editor_right_softkey_icon);
    clear_left_softkey();
    clear_right_softkey();
    register_left_softkey_handler();
    register_right_softkey_handler();
    register_default_hide_softkeys();

    category435_setup_editor_box(CAT435_CTX->buffer, CAT435_CTX->buffer_size, CAT435_CTX->input_type, history_buffer);
	wgui_inputs_register_validation_func(wgui_cat435_validation_hdlr);
    gui_unlock_double_buffer();

    if (update_screen)
    {
        RedrawCategoryFunction();
    }
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void Category435ShowPopup(BOOL update_screen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Category435ShowPopupInternal(update_screen, NULL, MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  Category435HidePopupInternal
 * DESCRIPTION
 *  set hide popup
 * PARAMETERS
 *  update_screen       [IN]        Is update screen
 *  force_execution     [IN]        Is force executrion
 * RETURNS
 *  void
 *****************************************************************************/
static void Category435HidePopupInternal(BOOL update_screen, BOOL force_execution)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!CAT435_CTX->show_popup && !force_execution)
    {
        /* Popup already hidden */
        return;
    }

    CAT435_CTX->show_popup = MMI_FALSE;

#ifdef __MMI_TOUCH_SCREEN__
    wgui_enable_horizontal_tab_bar_pen_events(MMI_TRUE);
#endif 
    wgui_set_horizontal_tab_bar_scroll();

    gui_lock_double_buffer();

    /* Reset editor (cf. RedrawCategory435Screen) */
    category435_reset_editor_box();

#if defined(__MMI_TOUCH_SCREEN__)
    /* reset pen handler, because APP will show category 435 with editor first and hide the popup */
    wgui_register_general_pen_handler();
    wgui_cat435_register_hilite_pen_handler();
#endif /* __MMI_TOUCH_SCREEN__ */

    ClearInputEventHandler(MMI_DEVICE_KEY);
    change_left_softkey(CAT435_CTX->left_softkey, CAT435_CTX->left_softkey_icon);
    change_right_softkey(CAT435_CTX->right_softkey, CAT435_CTX->right_softkey_icon);
    clear_left_softkey();
    clear_right_softkey();
    register_left_softkey_handler();
    register_right_softkey_handler();
    register_default_hide_softkeys();

    SetKeyHandler(category435_log_box_previous_line, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(category435_log_box_next_line, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(category435_log_box_previous_line, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(category435_log_box_next_line, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(CAT435_CTX->LSK_func, KEY_EVENT_UP);
    SetRightSoftkeyFunction(CAT435_CTX->RSK_func, KEY_EVENT_UP);

    gui_unlock_double_buffer();

    if (update_screen)
    {
        RedrawCategoryFunction();
    }
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void Category435HidePopup(BOOL update_screen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Category435HidePopupInternal(update_screen, MMI_FALSE);
}


/* For detail description, please refer to wgui_categories_IMPS.h */
BOOL Category435IsPopupDisplayed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ShowCategory435Screen should be invoked first */
    MMI_ASSERT(CAT435_CTX);
    return CAT435_CTX->show_popup;
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void Category435DirectInsertString(UI_string_type s, BOOL redraw_screen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, l;
    UI_buffer_type cursor_p;
    UI_character_type current_character;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ShowCategory435Screen should be invoked first */
    MMI_ASSERT(CAT435_CTX);

    gui_lock_double_buffer();

    MMI_multiline_inputbox.show_action_flag = 0;
    l = gui_strlen(s);
    for (i = 0; i < l; i++)
    {
        cursor_p = MMI_multiline_inputbox.cursor_p;

        if (MMI_multiline_inputbox.text_length >= MMI_multiline_inputbox.available_length)
        {
            gui_multi_line_input_box_insert_character(&MMI_multiline_inputbox, s[i]);
            break;
        }
        else
        {
            gui_multi_line_input_box_insert_character(&MMI_multiline_inputbox, s[i]);

            UI_STRING_GET_NEXT_CHARACTER(cursor_p, current_character);
            MMI_multiline_inputbox.cursor_p = cursor_p;
        }
    }
    MMI_multiline_inputbox.show_action_flag = 1;

    /* adjust the cursor position for imps icon */
    if (MMI_multiline_inputbox.icon_callback != NULL)
    {
        MMI_multiline_inputbox.cursor_p = 
            gui_multi_line_inputbox_adjust_cursor_for_icon_callback(&MMI_multiline_inputbox, MMI_multiline_inputbox.cursor_p, 1);
    }

    multiline_inputbox_input_callback();

    gui_unlock_double_buffer();

    if (redraw_screen && CAT435_CTX->show_popup)
    {
        wgui_inputs_ml_show_with_information_bar();
    }
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void Category435BlinkTab(S8 tab)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_horizontal_tab_bar_start_blinking(tab);
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void Category435UnBlinkTab(S8 tab)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_horizontal_tab_bar_stop_blinking(tab);
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void UpdateCategory435TabBar(UI_string_type title, PU8 title_icon, S8 n_tabs, S8 highlighted_tab, tab_bar_item_type *tab_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!CAT435_CTX)
    {
        MMI_DBG_ASSERT(0);
        return;
    }

    if (title == NULL)
    {
        title = MMI_horizontal_tab_bar.hint;
    }

    gui_lock_double_buffer();

    wgui_close_horizontal_tab_bar();

    /* Setup horizontal tab bar */
    for (i = 0; i < n_tabs; i++)
    {
        MMI_tab_bar_items[i] = tab_items[i];
    }
    wgui_create_horizontal_tab_bar(TRUE, title, n_tabs, highlighted_tab, MMI_FALSE);
    wgui_set_horizontal_tab_bar_title(title_icon, title);
    if (!(CAT435_CTX->show_popup))
    {
        wgui_set_horizontal_tab_bar_scroll();
    }
    else
    {
#ifdef __MMI_TOUCH_SCREEN__
        wgui_enable_horizontal_tab_bar_pen_events(MMI_FALSE);
#endif 
    }

    gui_unlock_double_buffer();

#if defined(CAT435_POPUP_OVERLAP_TAB_BAR) || defined(__MMI_FTE_SUPPORT__)
    if (CAT435_CTX->show_popup)
    {
        wgui_show_horizontal_tab_bar_tab_area();
    }
    else
    {
        wgui_show_horizontal_tab_bar();
    }
#else /* CAT435_POPUP_OVERLAP_TAB_BAR */ 
    wgui_show_horizontal_tab_bar();
#endif /* CAT435_POPUP_OVERLAP_TAB_BAR */ 
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void SetCategory435TabSelectCallback(void (*select_callback) (int index))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(g_mmi_gui_cat435_context_p);
    wgui_set_horizontal_tab_bar_select_callback(select_callback);
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void wgui_cat435_log_get_visible_character_range(S32 *start, S32 *end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    multi_line_input_box *b = &CAT435_CTX->log_box;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *start = b->visible_start;
    *end = b->visible_end;
}


/* For detail description, please refer to wgui_categories_IMPS.h */
MMI_BOOL wgui_cat435_log_check_highlighted_item_in_visible(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return gui_multi_line_input_box_is_highligter_in_visible_area(&CAT435_CTX->log_box) == 0 ? MMI_TRUE : MMI_FALSE;
}


static void wgui_cat435_validation_hdlr(
    PU8 dial_string,
    PU8 cursor_position,
    S32 length)
{
	if(g_wgui_cat435_text_lengh_changed_hdlr != NULL)
		g_wgui_cat435_text_lengh_changed_hdlr(length);
}
void wgui_cat435_register_text_length_changed_hdlr(void(*f)(S32))
{
	g_wgui_cat435_text_lengh_changed_hdlr = f;
}
/* For detail description, please refer to wgui_categories_IMPS.h */
void ShowCategory435Screen(
        UI_string_type title,
        PU8 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U16 editor_left_softkey,
        U16 editor_left_softkey_icon,
        U16 editor_right_softkey,
        U16 editor_right_softkey_icon,
        S8 n_tabs,
        S8 highlighted_tab,
        tab_bar_item_type *tab_items,
        BOOL show_popup,
        UI_string_type popup_title,
        U32 input_type,
        U8 *buffer,
        S32 buffer_size,
        U8 *log_buffer,
        S32 log_buffer_size,
        multi_line_input_box_icon_hdlr icon_callback,
        PU8 sample_icon,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    S32 sample_icon_width = 0, sample_icon_height = 0;
    dm_data_struct dm_data;
    U32 buff_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	buff_size = sizeof(gui_cat435_context_struct);
	g_mmi_gui_cat435_context_p = mmi_frm_scrmem_alloc_framebuffer(buff_size);
    memset(g_mmi_gui_cat435_context_p, 0, sizeof(gui_cat435_context_struct));    
    
    CAT435_CTX->right_softkey = right_softkey;
    CAT435_CTX->right_softkey_icon = right_softkey_icon;
    CAT435_CTX->left_softkey = left_softkey;
    CAT435_CTX->left_softkey_icon = left_softkey_icon;
    CAT435_CTX->editor_right_softkey = editor_right_softkey;
    CAT435_CTX->editor_right_softkey_icon = editor_right_softkey_icon;
    CAT435_CTX->editor_left_softkey = editor_left_softkey;
    CAT435_CTX->editor_left_softkey_icon = editor_left_softkey_icon;
    CAT435_CTX->popup_title = popup_title;
    CAT435_CTX->editor_RSK_func = UI_dummy_function;
    CAT435_CTX->editor_LSK_func = UI_dummy_function;
    CAT435_CTX->LSK_func = UI_dummy_function;
    CAT435_CTX->RSK_func = UI_dummy_function;
    /* We might need to setup/close editor later */
    CAT435_CTX->buffer = buffer;
    CAT435_CTX->buffer_size = buffer_size;
    CAT435_CTX->editor_created = 0;
    CAT435_CTX->input_type = input_type;
    CAT435_CTX->icon_callback = icon_callback;
    gui_measure_image(sample_icon, &sample_icon_width, &sample_icon_height);
    CAT435_CTX->icon_height = (S8) sample_icon_height;

    gui_lock_double_buffer();

    wgui_title_set_menu_shortcut_number(-1);
    wgui_title_disable_menu_shortcut_display(MMI_TRUE);
    MMI_title_string = NULL;
    MMI_title_icon = NULL;

    clear_category_screen_key_handlers();
    clear_left_softkey();
    clear_right_softkey();
    register_left_softkey_handler();
    register_right_softkey_handler();
    register_default_hide_softkeys();

    /* Setup horizontal tab bar */
    for (i = 0; i < n_tabs; i++)
    {
        MMI_tab_bar_items[i] = tab_items[i];
    }
    wgui_create_horizontal_tab_bar(TRUE, title, n_tabs, highlighted_tab, MMI_FALSE);
    wgui_set_horizontal_tab_bar_title(title_icon, title);
    if (!show_popup)
    {
        wgui_set_horizontal_tab_bar_scroll();
    }

    if (history_buffer)
    {
        /* Check the first four bytes on whether popup exists */
        gui_cat435_history_header_struct *h = (gui_cat435_history_header_struct*) history_buffer;

        show_popup = (BOOL) (h->show_popup ? MMI_TRUE : MMI_FALSE);
        if (1) //(show_popup)
        {
            history_buffer += sizeof(gui_cat435_history_header_struct);
        }
        else
        {
            /* No history for editor */
            history_buffer = NULL;
        }
    }
    /* Setup log area */
	if (show_popup)
		category435_setup_log_box(log_buffer, log_buffer_size, NULL);
	else
		category435_setup_log_box(log_buffer, log_buffer_size, history_buffer);
		
    /* Setup editor area */
    CAT435_CTX->backup_MMI_editor_width = MMI_multiline_inputbox_width;
    CAT435_CTX->backup_MMI_editor_height = MMI_multiline_inputbox_height;
    CAT435_CTX->backup_information_bar_alpha = current_information_bar_theme->background_alpha;
    CAT435_CTX->backup_information_bar_color = current_information_bar_theme->background_color;

    current_information_bar_theme->background_alpha = 100;
    current_information_bar_theme->background_color = g_mmi_gui_cat435_popup_color;


    /* Setup key */
    if (show_popup)
    {
        Category435ShowPopupInternal(MMI_FALSE, history_buffer, MMI_TRUE);
    }
    else
    {
        Category435HidePopupInternal(MMI_FALSE, MMI_TRUE);
    }
	wgui_inputs_register_validation_func(wgui_cat435_validation_hdlr);
#ifdef __MMI_WALLPAPER_ON_BOTTOM__
    dm_get_scr_bg_opacity(&editor_scr_bg_opacity);
    dm_set_scr_bg_opacity((U8)(current_MMI_theme->bg_opacity_low));
    if (g_wgui_catimps_bg_img_name != NULL)
    {
        dm_set_scr_bg_image(0, (S8*)g_wgui_catimps_bg_img_name, -1, -1, 255);
        dm_set_scr_bg_opacity(WGUI_CATIMPS_BG_IMG_OPACITY);
    }
#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */ 

    gui_unlock_double_buffer();

    ExitCategoryFunction = ExitCategory435Screen;
    dm_register_category_controlled_callback(category435_draw_controlled_area);
    dm_setup_category_functions(dm_redraw_category_screen, GetCategory435History, GetCategory435HistorySize);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY435_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    dm_data.s32flags |= DM_SHOW_VKPAD;
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_category_screen_control_area_pen_handlers(
        category435_control_area_pen_down_handler,
        MMI_PEN_EVENT_DOWN);
    wgui_register_category_screen_control_area_pen_handlers(category435_control_area_pen_up_handler, MMI_PEN_EVENT_UP);
    wgui_register_category_screen_control_area_pen_handlers(
        category435_control_area_pen_move_handler,
        MMI_PEN_EVENT_MOVE);
    wgui_register_category_screen_control_area_pen_handlers(
        category435_control_area_pen_repeat_handler,
        MMI_PEN_EVENT_REPEAT);
    wgui_register_category_screen_control_area_pen_handlers(
        category435_control_area_pen_longtap_handler,
        MMI_PEN_EVENT_LONG_TAP);
    wgui_register_category_screen_control_area_pen_handlers(
        category435_control_area_pen_abort_handler,
        MMI_PEN_EVENT_ABORT);
#endif /* __MMI_TOUCH_SCREEN__ */ 
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void wgui_cat435_set_hilite_list(
        HILITE_STR *hilite_list,
        U16 number_of_list,
        U16 curr_hilite_idx,
        void (*hilite_cb)(S32 idx),
        void (*click_cb)(S32 idx))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_cat435_hilite_list = hilite_list;
    g_wgui_cat435_number_of_hilite_list = number_of_list;
    g_wgui_cat435_current_hilite_index = curr_hilite_idx;
    g_wgui_cat435_hilite_cb = hilite_cb;
    g_wgui_cat435_hilite_click_cb = click_cb;
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void wgui_catimps_set_bg_img_name(U8* filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_catimps_bg_img_name = filename;
}

