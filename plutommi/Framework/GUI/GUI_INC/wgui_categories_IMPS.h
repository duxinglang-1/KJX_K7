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
 *  wgui_categories_IMPS.h
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
 *  [Category425]       Contact List Screen
 *  [Category435]       Chat Screen with Popup Editor
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __WGUI_CATEGORIES_IMPS_H__
#define __WGUI_CATEGORIES_IMPS_H__
/* <hExpand noExpand> DO NOT REMOVE THIS LINE */
#ifdef __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__
#include "wgui_categories_inputs.h"
#include "wgui_categories.h"
#endif /* __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__ */
/* </hExpand> DO NOT REMOVE THIS LINE */
#include "wgui_tree.h"
#include "gui_config.h"
#include "MMIDataType.h"
#include "gui_data_types.h"
#include "gui_typedef.h"
#include "kal_general_types.h"
#include "gui_inputs.h"
/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

/*DOM-NOT_FOR_SDK-BEGIN*/

/* Category 420 */
#if defined(__MMI_MAINLCD_96X64__)

#define CAT420_DISP_INFO_TEXT                   /* Whether to display mood/status description text */
#define CAT420_TOP_MARGIN                    2
#define CAT420_BOTTOM_MARGIN                 7  /* Between information and description text */
#define CAT420_LEFT_MARGIN                   6
#define CAT420_RIGHT_MARGIN                  6
#define CAT420_IMAGE_H_SPACING               (CAT420_RIGHT_MARGIN)
#define CAT420_NAME_LINE_V_SPACING           4
#define CAT420_LINE_IMAGE_V_SPACING          8
#define CAT420_CAPTION_IMAGE_H_SPACING       6
#define CAT420_MOOD_STATUS_V_SPACING         4
#define CAT420_IMAGE_AREA_WIDTH              (80)  /* Default image width */
#define CAT420_IMAGE_AREA_MIN_WIDTH          (60)   /* Minimum image width */
#define CAT420_EDITOR_LEFT_BORDER_PADDING    (CAT420_LEFT_MARGIN)
#define CAT420_EDITOR_RIGHT_BORDER_PADDING   (CAT420_RIGHT_MARGIN)
#define CAT420_EDITOR_BOTTOM_PADDING         (7)


#elif defined(__MMI_MAINLCD_128X64__)

#define CAT420_DISP_INFO_TEXT                   /* Whether to display mood/status description text */
#define CAT420_TOP_MARGIN                    2
#define CAT420_BOTTOM_MARGIN                 7  /* Between information and description text */
#define CAT420_LEFT_MARGIN                   6
#define CAT420_RIGHT_MARGIN                  6
#define CAT420_IMAGE_H_SPACING               (CAT420_RIGHT_MARGIN)
#define CAT420_NAME_LINE_V_SPACING           4
#define CAT420_LINE_IMAGE_V_SPACING          8
#define CAT420_CAPTION_IMAGE_H_SPACING       6
#define CAT420_MOOD_STATUS_V_SPACING         4
#define CAT420_IMAGE_AREA_WIDTH              (100)  /* Default image width */
#define CAT420_IMAGE_AREA_MIN_WIDTH          (60)   /* Minimum image width */
#define CAT420_EDITOR_LEFT_BORDER_PADDING    (CAT420_LEFT_MARGIN)
#define CAT420_EDITOR_RIGHT_BORDER_PADDING   (CAT420_RIGHT_MARGIN)
#define CAT420_EDITOR_BOTTOM_PADDING         (7)
// baiwenlin 20130821  
#elif defined(__MMI_MAINLCD_128X36__)

#define CAT420_DISP_INFO_TEXT                   /* Whether to display mood/status description text */
#define CAT420_TOP_MARGIN                    2
#define CAT420_BOTTOM_MARGIN                 7  /* Between information and description text */
#define CAT420_LEFT_MARGIN                   6
#define CAT420_RIGHT_MARGIN                  6
#define CAT420_IMAGE_H_SPACING               (CAT420_RIGHT_MARGIN)
#define CAT420_NAME_LINE_V_SPACING           4
#define CAT420_LINE_IMAGE_V_SPACING          8
#define CAT420_CAPTION_IMAGE_H_SPACING       6
#define CAT420_MOOD_STATUS_V_SPACING         4
#define CAT420_IMAGE_AREA_WIDTH              (100)  /* Default image width */
#define CAT420_IMAGE_AREA_MIN_WIDTH          (60)   /* Minimum image width */
#define CAT420_EDITOR_LEFT_BORDER_PADDING    (CAT420_LEFT_MARGIN)
#define CAT420_EDITOR_RIGHT_BORDER_PADDING   (CAT420_RIGHT_MARGIN)
#define CAT420_EDITOR_BOTTOM_PADDING         (7)

#elif defined(__MMI_MAINLCD_128X128__)
#undef CAT420_DISP_INFO_TEXT                    /* Whether to display mood/status description text */
#define CAT420_TOP_MARGIN                    2
#define CAT420_BOTTOM_MARGIN                 4  /* Between information and description text */
#define CAT420_LEFT_MARGIN                   5
#define CAT420_RIGHT_MARGIN                  3
#define CAT420_IMAGE_H_SPACING               (CAT420_RIGHT_MARGIN)
#define CAT420_NAME_LINE_V_SPACING           3
#define CAT420_LINE_IMAGE_V_SPACING          6
#define CAT420_CAPTION_IMAGE_H_SPACING       6
#define CAT420_MOOD_STATUS_V_SPACING         3
#define CAT420_IMAGE_AREA_WIDTH              (60)   /* Default image width */
#define CAT420_IMAGE_AREA_MIN_WIDTH          (40)   /* Minimum image width */
#define CAT420_EDITOR_LEFT_BORDER_PADDING    (CAT420_LEFT_MARGIN)
#define CAT420_EDITOR_RIGHT_BORDER_PADDING   (CAT420_RIGHT_MARGIN)
#define CAT420_EDITOR_BOTTOM_PADDING         (5)

#elif defined(__MMI_MAINLCD_128X160__)
#undef CAT420_DISP_INFO_TEXT                    /* Whether to display mood/status description text */
#define CAT420_TOP_MARGIN                    2
#define CAT420_BOTTOM_MARGIN                 4  /* Between information and description text */
#define CAT420_LEFT_MARGIN                   5
#define CAT420_RIGHT_MARGIN                  3
#define CAT420_IMAGE_H_SPACING               (CAT420_RIGHT_MARGIN)
#define CAT420_NAME_LINE_V_SPACING           3
#define CAT420_LINE_IMAGE_V_SPACING          6
#define CAT420_CAPTION_IMAGE_H_SPACING       6
#define CAT420_MOOD_STATUS_V_SPACING         3
#define CAT420_IMAGE_AREA_WIDTH              (60)   /* Default image width */
#define CAT420_IMAGE_AREA_MIN_WIDTH          (40)   /* Minimum image width */
#define CAT420_EDITOR_LEFT_BORDER_PADDING    (CAT420_LEFT_MARGIN)
#define CAT420_EDITOR_RIGHT_BORDER_PADDING   (CAT420_RIGHT_MARGIN)
#define CAT420_EDITOR_BOTTOM_PADDING         (5)

#elif defined(__MMI_MAINLCD_176X220__)
#define CAT420_DISP_INFO_TEXT                   /* Whether to display mood/status description text */
#define CAT420_TOP_MARGIN                    2
#define CAT420_BOTTOM_MARGIN                 7  /* Between information and description text */
#define CAT420_LEFT_MARGIN                   7
#define CAT420_RIGHT_MARGIN                  5
#define CAT420_IMAGE_H_SPACING               (CAT420_RIGHT_MARGIN)
#define CAT420_NAME_LINE_V_SPACING           3
#define CAT420_LINE_IMAGE_V_SPACING          6
#define CAT420_CAPTION_IMAGE_H_SPACING       6
#define CAT420_MOOD_STATUS_V_SPACING         3
#define CAT420_IMAGE_AREA_WIDTH              (65)   /* Default image width */
#define CAT420_IMAGE_AREA_MIN_WIDTH          (45)   /* Minimum image width */
#define CAT420_EDITOR_LEFT_BORDER_PADDING    (CAT420_LEFT_MARGIN)
#define CAT420_EDITOR_RIGHT_BORDER_PADDING   (CAT420_RIGHT_MARGIN)
#define CAT420_EDITOR_BOTTOM_PADDING         (7)

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)|| defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)||defined(__MMI_MAINLCD_240X240__)
#define CAT420_DISP_INFO_TEXT                   /* Whether to display mood/status description text */
#define CAT420_TOP_MARGIN                    2
#define CAT420_BOTTOM_MARGIN                 7  /* Between information and description text */
#define CAT420_LEFT_MARGIN                   6
#define CAT420_RIGHT_MARGIN                  6
#define CAT420_IMAGE_H_SPACING               (CAT420_RIGHT_MARGIN)
#define CAT420_NAME_LINE_V_SPACING           4
#define CAT420_LINE_IMAGE_V_SPACING          8
#define CAT420_CAPTION_IMAGE_H_SPACING       6
#define CAT420_MOOD_STATUS_V_SPACING         4
#define CAT420_IMAGE_AREA_WIDTH              (100)  /* Default image width */
#define CAT420_IMAGE_AREA_MIN_WIDTH          (60)   /* Minimum image width */
#define CAT420_EDITOR_LEFT_BORDER_PADDING    (CAT420_LEFT_MARGIN)
#define CAT420_EDITOR_RIGHT_BORDER_PADDING   (CAT420_RIGHT_MARGIN)
#define CAT420_EDITOR_BOTTOM_PADDING         (7)

#else
#error "Unsupported LCD size."
#endif 

#define CAT420_LINE_EXTRA_PIXEL              (UI_SCROLLBAR_WIDTH + CAT420_RIGHT_MARGIN)

/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  ShowCategory420Screen
 * DESCRIPTION
 *  Displays the category420 screen
 *  [FTE]: support (tool bar is not avaiable)
 *  The pointer of name, mood_string, status_string are used directly  in category 420.
 *  They should not be released before category 420 exits.
 *  photo_filename can be released immediately after ShowCategory420Screen() returns.
 * 
 * <img name="wgui_cat420_img1" />
 * PARAMETERS
 *   title                         : [IN ] (TITLE) Title for the screen
 *   title_icon                    : [IN ] (N/A) Icon shown with the title
 *   left_softkey                  : [IN ] (LSK) Left softkey label
 *   left_softkey_icon             : [IN ] (N/A) Icon for the left softkey
 *   right_softkey                 : [IN ] (RSK) Right softkey label
 *   right_softkey_icon            : [IN ] (N/A) Icon for the right softkey
 *   name                          : [IN ] (C420_1) User Name
 *   photo_filename                : [IN ] (N/A) File name of photo
 *   alternative_photo             : [IN ] (N/A) Default photo if 'photo_filename' is NULL
 *   mood_caption                  : [IN ] (C420_2) String ID to "Mood" literally
 *   mood_string                   : [IN ] (C420_3) Text indicating mood
 *   mood_icon                     : [IN ] (N/A) Image indicating mood
 *   status_caption                : [IN ] (C420_2) String ID to "Status" literally
 *   status_string                 : [IN ] (C420_3) Text indicating mood
 *   status_icon                   : [IN ] (N/A) Image indicating mood
 *   buffer                        : [IN ] (UNLIM) Buffer the input box should use.
 *   buffer_size                   : [IN ] (N/A) Size of the buffer.
 *   history_buffer                : [IN ] (N/A) History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_420(void)
 * {
 *     U8 *guiBuffer = NULL;
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     memset(g_buffer, 0, MAX_LOCAL_BUFFER);
 *     memset(g_buffer1, 0, MAX_LOCAL_BUFFER_1);
 * 
 *     mmi_asc_to_ucs2((PS8) g_buffer1, (PS8) "JOE");
 *     mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "D:\\CSB\\category_52.jpg");
 * 
 *     ShowCategory420Screen(
 *         STR_ID_CSB_CATEGORY_TEXT,
 *         0,
 *         STR_ID_CSB_LSK_TEXT,
 *         0,
 *         STR_ID_CSB_RSK_TEXT,
 *         0,
 *         (UI_string_type) g_buffer1,
 *         (S8*) g_buffer,
 *         IMG_GLOBAL_DEFAULT,
 *         STR_ID_CSB_MENUITEM1_TEXT,
 *         (UI_string_type) GetString(STR_ID_CSB_DUMMY_TEXT),
 *         (PU8) GetImage(STR_ID_CSB_DUMMY_TEXT),
 *         STR_ID_CSB_MENUITEM2_TEXT,
 *         (UI_string_type) GetString((U16) (STR_ID_CSB_DUMMY_TEXT)),
 *         (PU8) GetImage((U16) (IMG_PROFILES_OUTDOOR)),
 *         (U8*) g_buffer1,
 *         (S32) mmi_ucs2strlen((S8*) g_buffer1),
 *         guiBuffer);
 * 
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory420Screen(
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
                U8 *history_buffer);

/*DOM-NOT_FOR_SDK-BEGIN*/

/* Category 425 */
#if defined(__MMI_MAINLCD_96X64__)

#define CAT425_DEFAULT_ICON_WIDTH            40
#define CAT425_DEFAULT_ICON_HEIGHT           42
#define CAT425_DEFAULT_ICON2_WIDTH           10
#define CAT425_DEFAULT_ICON2_HEIGHT          10
#define CAT425_ICON_X                        2
#define CAT425_ICON_Y                        5
#define CAT425_ICON_TEXT_GAP                 6
#define CAT425_TEXT_SCROLLBAR_GAP            4
#define CAT425_TEXT1_Y                       3
#define CAT425_TEXT2_Y                       27
#define CAT425_TEXT_HEIGHT                   22
#define CAT425_MENUITEM_HEIGHT               55
#define CAT425_MENUITEM_HEIGHT_NO_TAB        60
#define CAT425_TEXT2_BRACKET_GAP             2

#elif defined(__MMI_MAINLCD_128X64__)

#define CAT425_DEFAULT_ICON_WIDTH            40
#define CAT425_DEFAULT_ICON_HEIGHT           42
#define CAT425_DEFAULT_ICON2_WIDTH           10
#define CAT425_DEFAULT_ICON2_HEIGHT          10
#define CAT425_ICON_X                        2
#define CAT425_ICON_Y                        5
#define CAT425_ICON_TEXT_GAP                 6
#define CAT425_TEXT_SCROLLBAR_GAP            4
#define CAT425_TEXT1_Y                       3
#define CAT425_TEXT2_Y                       27
#define CAT425_TEXT_HEIGHT                   22
#define CAT425_MENUITEM_HEIGHT               55
#define CAT425_MENUITEM_HEIGHT_NO_TAB        60
#define CAT425_TEXT2_BRACKET_GAP             2
#elif defined(__MMI_MAINLCD_128X36__)// baiwenlin 20130821  

#define CAT425_DEFAULT_ICON_WIDTH            40
#define CAT425_DEFAULT_ICON_HEIGHT           42
#define CAT425_DEFAULT_ICON2_WIDTH           10
#define CAT425_DEFAULT_ICON2_HEIGHT          10
#define CAT425_ICON_X                        2
#define CAT425_ICON_Y                        5
#define CAT425_ICON_TEXT_GAP                 6
#define CAT425_TEXT_SCROLLBAR_GAP            4
#define CAT425_TEXT1_Y                       3
#define CAT425_TEXT2_Y                       27
#define CAT425_TEXT_HEIGHT                   22
#define CAT425_MENUITEM_HEIGHT               55
#define CAT425_MENUITEM_HEIGHT_NO_TAB        60
#define CAT425_TEXT2_BRACKET_GAP             2

#elif defined(__MMI_MAINLCD_128X128__)
#define CAT425_DEFAULT_ICON_WIDTH            26
#define CAT425_DEFAULT_ICON_HEIGHT           26
#define CAT425_DEFAULT_ICON2_WIDTH           10
#define CAT425_DEFAULT_ICON2_HEIGHT          10
#define CAT425_ICON_X                        2
#define CAT425_ICON_Y                        4
#define CAT425_ICON_TEXT_GAP                 4
#define CAT425_TEXT_SCROLLBAR_GAP            2
#define CAT425_TEXT1_Y                       0
#define CAT425_TEXT2_Y                       16
#define CAT425_TEXT_HEIGHT                   16
#define CAT425_MENUITEM_HEIGHT               33
#define CAT425_MENUITEM_HEIGHT_NO_TAB        39
#define CAT425_TEXT2_BRACKET_GAP             1

#elif defined(__MMI_MAINLCD_128X160__)
#define CAT425_DEFAULT_ICON_WIDTH            26
#define CAT425_DEFAULT_ICON_HEIGHT           26
#define CAT425_DEFAULT_ICON2_WIDTH           10
#define CAT425_DEFAULT_ICON2_HEIGHT          10
#define CAT425_ICON_X                        2
#define CAT425_ICON_Y                        4
#define CAT425_ICON_TEXT_GAP                 4
#define CAT425_TEXT_SCROLLBAR_GAP            2
#define CAT425_TEXT1_Y                       0
#define CAT425_TEXT2_Y                       16
#define CAT425_TEXT_HEIGHT                   16
#define CAT425_MENUITEM_HEIGHT               33
#define CAT425_MENUITEM_HEIGHT_NO_TAB        39
#define CAT425_TEXT2_BRACKET_GAP             1

#elif defined(__MMI_MAINLCD_176X220__)
#define CAT425_DEFAULT_ICON_WIDTH            32
#define CAT425_DEFAULT_ICON_HEIGHT           32
#define CAT425_DEFAULT_ICON2_WIDTH           10
#define CAT425_DEFAULT_ICON2_HEIGHT          10
#define CAT425_ICON_X                        2
#define CAT425_ICON_Y                        1
#define CAT425_ICON_TEXT_GAP                 4
#define CAT425_TEXT_SCROLLBAR_GAP            4
#define CAT425_TEXT1_Y                       1
#define CAT425_TEXT2_Y                       18
#define CAT425_TEXT_HEIGHT                   17
#define CAT425_MENUITEM_HEIGHT               35
#define CAT425_MENUITEM_HEIGHT_NO_TAB        39
#define CAT425_TEXT2_BRACKET_GAP             1

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)|| defined(__MMI_MAINLCD_240X240__)
#define CAT425_DEFAULT_ICON_WIDTH            40
#define CAT425_DEFAULT_ICON_HEIGHT           42
#define CAT425_DEFAULT_ICON2_WIDTH           10
#define CAT425_DEFAULT_ICON2_HEIGHT          10
#define CAT425_ICON_X                        2
#define CAT425_ICON_Y                        5
#define CAT425_ICON_TEXT_GAP                 6
#define CAT425_TEXT_SCROLLBAR_GAP            4
#define CAT425_TEXT1_Y                       3
#define CAT425_TEXT2_Y                       27
#define CAT425_TEXT_HEIGHT                   22
#if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
#define CAT425_MENUITEM_HEIGHT               58
#define CAT425_MENUITEM_HEIGHT_NO_TAB        63
#elif defined(__MMI_MAINLCD_320X240__)
#define CAT425_MENUITEM_HEIGHT               50
#define CAT425_MENUITEM_HEIGHT_NO_TAB        60
#else
#define CAT425_MENUITEM_HEIGHT               55
#define CAT425_MENUITEM_HEIGHT_NO_TAB        60
#endif
#define CAT425_TEXT2_BRACKET_GAP             2

#elif defined(__MMI_MAINLCD_240X400__)
#define CAT425_DEFAULT_ICON_WIDTH            40
#define CAT425_DEFAULT_ICON_HEIGHT           41
#define CAT425_DEFAULT_ICON2_WIDTH           10
#define CAT425_DEFAULT_ICON2_HEIGHT          10
#define CAT425_ICON_X                        2
#define CAT425_ICON_Y                        3
#define CAT425_ICON_TEXT_GAP                 6
#define CAT425_TEXT_SCROLLBAR_GAP            4
#define CAT425_TEXT1_Y                       1
#define CAT425_TEXT2_Y                       24
#define CAT425_TEXT_HEIGHT                   22
#define CAT425_MENUITEM_HEIGHT               47
#define CAT425_MENUITEM_HEIGHT_NO_TAB        76
#define CAT425_TEXT2_BRACKET_GAP             2

#else 
#error "Unsupported LCD size."
#endif

/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  ShowCategory425Screen
 * DESCRIPTION
 *  Displays the category425 screen
 *  [FTE]: support (tool bar is not avaiable)
 *  1. Each menu item has two text strings: name and category.
 *  2. Each menu item has three image icons: buddy icon, message icon, and block icon.
 *  An empty icon can be set as NULL in 'get_item_func'
 *  3. Hint display id not visual appealing in this category screen, and should be avoided.
 * 
 * <img name="wgui_cat425_img1" />
 * PARAMETERS
 *   title                         : [IN ] (TITLE) Title for the screen
 *   title_icon                    : [IN ] (N/A) Title icon, currently only for non-tab mode
 *   left_softkey                  : [IN ] (LSK) Left softkey label
 *   left_softkey_icon             : [IN ] (N/A) Icon for the left softkey
 *   right_softkey                 : [IN ] (RSK) Right softkey label
 *   right_softkey_icon            : [IN ] (N/A) Icon for the right softkey
 *   n_tabs                        : [IN ] (N/A) Number of tabs
 *   highlighted_tab               : [IN ] (N/A) Highlighted tab
 *   tab_items                     : [IN ] (N/A) Tab list
 *   number_of_items               : [IN ] (N/A) Number of menu items
 *   get_item_func                 : [IN ] (C425_1, C425_2) Callback function to get menu text.
 *   get_hint_func                 : [IN ] (N/A) (Deprecated) Callback function to get menu hint.
 *   sample_icon                   : [IN ] (N/A) Sample icon to get image dimension of buddy icon
 *   sample_icon2                  : [IN ] (N/A) Sample icon to get image dimension of message icon
 *   highlighted_item              : [IN ] (N/A) Default highlighted menu item
 *   history_buffer                : [IN ] (N/A) History buffer
 *   list_is_ready_p               : [OUT] (N/A) Whether the dynamic list menu is successfully loaded.
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_425(void)
 * {
 *     U8 *guiBuffer = NULL;
 *     U8 index;
 *     BOOL list_is_ready_p;
 *     tab_bar_item_type MMI_tab_bar_items[2];
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     for (index = 0; index < 2; index++)
 *     {
 *         MMI_tab_bar_items[index].icon = (PU8) GetImage(gIndexIconsImageList[index]);
 *         MMI_tab_bar_items[index].text = NULL;
 *         MMI_tab_bar_items[index].flags = 0;
 *     }
 * 
 *     ShowCategory425Screen(
 *         (UI_string_type) GetString(STR_ID_CSB_CATEGORY_TEXT),
 *         NULL,
 *         STR_ID_CSB_LSK_TEXT,
 *         0,
 *         STR_ID_CSB_RSK_TEXT,
 *         0,
 *         (S8) 2,
 *         (S8) 0,
 *         MMI_tab_bar_items,
 *         (S32) 4,
 *         get425_async_items,
 *         NULL,
 *         (PU8) GetImage(IMG_PROFILES_OUTDOOR),
 *         (PU8) GetImage(IMG_PROFILES_OUTDOOR),
 *         0,
 *         guiBuffer,
 *         &list_is_ready_p);
 * 
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory425Screen(
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
                BOOL *list_is_ready_p);


/*****************************************************************************
 * FUNCTION
 *  RefreshCategory425Screen
 * DESCRIPTION
 *  Refresh the category425 screen
 *  (it will reload menu item data with 'get_item_func' passed in ShowCategory425Screen)
 *  
 *  Category 425 screen should be currently displayed.
 * PARAMETERS
 *   number_of_items               : [IN ] (N/A) The number of menu items.
 *   highlighted_item              : [IN ] (N/A) The highlighted item
 * RETURNS
 *  void
 *****************************************************************************/
extern void RefreshCategory425Screen(S32 number_of_items, S32 highlighted_item);


/*****************************************************************************
 * FUNCTION
 *  UpdateCategory425TabBar
 * DESCRIPTION
 *  update 425 tab bar
 * PARAMETERS
 *   title                         : [IN ] (TITLE) string of title
 *   n_tabs                        : [IN ] (N/A) total tab count
 *   highlighted_tab               : [IN ] (N/A) index of highlight tab
 *   tab_items                     : [IN ] (N/A) tab item list
 * RETURNS
 *  void
 *****************************************************************************/
extern void UpdateCategory425TabBar(UI_string_type title, S8 n_tabs, S8 highlighted_tab, tab_bar_item_type *tab_items);


/*****************************************************************************
 * FUNCTION
 *  SetCategory425TabSelectCallback
 * DESCRIPTION
 *  set 425 tab select callback
 * PARAMETERS
 *   select_callback               : [IN ] (N/A) callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetCategory425TabSelectCallback(void (*select_callback) (int index));


/*****************************************************************************
 * FUNCTION
 *  Category425BlinkTab
 * DESCRIPTION
 *  start tab blink
 * PARAMETERS
 *   tab                           : [IN ] (N/A) inbex of tab
 * RETURNS
 *  void
 *****************************************************************************/
extern void Category425BlinkTab(S8 tab);


/*****************************************************************************
 * FUNCTION
 *  Category425UnBlinkTab
 * DESCRIPTION
 *  category 425 stop tab blink
 * PARAMETERS
 *   tab                           : [IN ] (N/A) index of tab
 * RETURNS
 *  void
 *****************************************************************************/
extern void Category425UnBlinkTab(S8 tab);


#if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) || defined(__MMI_SMART_MESSAGE_MT__)
/*****************************************************************************
 * <GROUP IMPS>
 * FUNCTION
 *  ShowCategoryNSM2Screen
 * DESCRIPTION
 *  Displays the categoryNSM screen
 *  
 *  The pointer of name, mood_string, status_string are used directly  in category NSM2.
 *  They should not be released before category NSM2 exits.
 *  photo_filename can be released immediately after ShowCategoryNSM2Screen() returns.
 * 
 * <img name="wgui_catNSM2_img1" />
 * PARAMETERS
 *   title                         : [IN ] (TITLE) Title for the screen
 *   title_icon                    : [IN ] (N/A) Icon shown with the title
 *   left_softkey                  : [IN ] (LSK) Left softkey label
 *   left_softkey_icon             : [IN ] (N/A) Icon for the left softkey
 *   right_softkey                 : [IN ] (RSK) Right softkey label
 *   right_softkey_icon            : [IN ] (N/A) Icon for the right softkey
 *   name                          : [IN ] (C420_1) User Name
 *   photo_filename                : [IN ] (N/A) File name of photo
 *   alternative_photo             : [IN ] (N/A) Default photo if 'photo_filename' is NULL
 *   mood_caption                  : [IN ] (C420_2) String ID to "Mood" literally
 *   mood_string                   : [IN ] (C420_3) Text indicating mood
 *   mood_icon                     : [IN ] (N/A) Image indicating mood
 *   status_caption                : [IN ] (C420_2) String ID to "Status" literally
 *   status_string                 : [IN ] (C420_3) Text indicating mood
 *   status_icon                   : [IN ] (N/A) Image indicating mood
 *   buffer                        : [IN ] (UNLIM) Buffer the input box should use.
 *   buffer_size                   : [IN ] (N/A) Size of the buffer.
 *   history_buffer                : [IN ] (N/A) History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_NSM2(void)
 * {
 *     U8 *guiBuffer = NULL;
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     memset(g_buffer, 0, MAX_LOCAL_BUFFER);
 *     memset(g_buffer1, 0, MAX_LOCAL_BUFFER_1);
 * 
 *     mmi_asc_to_ucs2((PS8) g_buffer1, (PS8) "JOE");
 *     mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "D:\\CSB\\category_52.jpg");
 * 
 *     ShowCategoryNSM2Screen(
 *         STR_ID_CSB_CATEGORY_TEXT,
 *         0,
 *         STR_ID_CSB_LSK_TEXT,
 *         0,
 *         STR_ID_CSB_RSK_TEXT,
 *         0,
 *         (UI_string_type) g_buffer1,
 *         (S8*) g_buffer,
 *         IMG_GLOBAL_DEFAULT,
 *         STR_ID_CSB_MENUITEM1_TEXT,
 *         (UI_string_type) GetString(STR_ID_CSB_DUMMY_TEXT),
 *         (PU8) GetImage(STR_ID_CSB_DUMMY_TEXT),
 *         STR_ID_CSB_MENUITEM2_TEXT,
 *         (UI_string_type) GetString((U16) (STR_ID_CSB_DUMMY_TEXT)),
 *         (PU8) GetImage((U16) (IMG_PROFILES_OUTDOOR)),
 *         (U8*) g_buffer1,
 *         (S32) mmi_ucs2strlen((S8*) g_buffer1),
 *         guiBuffer);
 * 
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategoryNSM2Screen(
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
                U8 *history_buffer);

#endif /* (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) || defined(__MMI_SMART_MESSAGE_MT__) */ 

/*****************************************************************************
 * FUNCTION
 *  ShowCategory428Screen
 * DESCRIPTION
 *  Displays the category428 screen
 *  [FTE]: support (tool bar is  avaiable)
 *  For New Contact List category, this category have three levels: 0, 1, 2.
 *  Level 2 is for myself with 1 icon and 1 text.
 *  Level 0 is for group  with 1 icon and 1 text.
 *  Level 1 is for list with 3 icon and 1 text.
 *  The friend id will show in hint when highlighted.
 * 
 * <img name="wgui_cat428_img1" />
 * PARAMETERS
 *   title                         : [TITLE ] (N/A) Title for the screen
 *   title_icon                    : [IN ] (N/A) Title icon for the screen
 *   left_softkey                  : [LSK ] (N/A) Left softkey label
 *   left_softkey_icon             : [IN ] (N/A) Icon for the left softkey
 *   right_softkey                 : [RSK ] (N/A) Right softkey label
 *   right_softkey_icon            : [IN ] (N/A) Icon for the right softkey
 *   n_tabs                        : [IN ] (N/A) Number of tabs
 *   highlighted_tab               : [IN ] (N/A) Highlighted tab
 *   tab_items                     : [IN ] (N/A) Tab list
 *   number_of_items               : [IN ] (N/A) Number of menu items
 *   get_item_func                 : [IN ] (N/A) Callback function to get menu text.
 *   get_hint_func                 : [IN ] (N/A) (Deprecated) Callback function to get menu hint.
 *   get_level_callback            : [IN ] (N/A) Callback function to get menu level.
 *   get_state_func                : [IN ] (N/A) Callback function to get group state.
 *   set_state_func                : [IN ] (N/A) Callback function to set group state.
 *   folder_clicked_callback       : [IN ] (N/A) Callback function when pen on first icon.
 *   sample_icon                   : [IN ] (N/A) Sample icon to get image dimension of buddy icon
 *   sample_icon2                  : [IN ] (N/A) Sample icon to get image dimension of message icon
 *   highlighted_item              : [IN ] (N/A) Default highlighted menu item
 *   information                   : [C428_1 ] (N/A) Information will show in information bar.
 *   history_buffer                : [IN ] (N/A) History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * </code>
 *****************************************************************************/
extern  void ShowCategory428Screen(
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
        U8 *history_buffer);


/*****************************************************************************
 * FUNCTION
 *  wgui_cat428_refresh_informationbar
 * DESCRIPTION
 *  refresh cat428 information bar
 *  
 *  Category 428 screen should be currently displayed.
 * PARAMETERS
 *   information                   : [IN ] (C428_1) The refreshed information string
 *   info_image                    : [IN ] (N/A) The refreshed information image
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat428_refresh_informationbar(UI_string_type information, PU8 info_image);


/*****************************************************************************
 * FUNCTION
 *  wgui_cat428_refresh_list
 * DESCRIPTION
 *  Refresh the category428 screen
 *  (it will reload menu item data with 'get_item_func' passed in ShowCategory428Screen)
 *  
 *  Category 428 screen should be currently displayed.
 * PARAMETERS
 *   number_of_items               : [IN ] (N/A) The number of menu items.
 *   highlighted_item              : [IN ] (N/A) The highlighted item
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat428_refresh_list(S32 number_of_items, S32 highlighted_item);


/*****************************************************************************
 * FUNCTION
 *  wgui_cat428_update_tabbar
 * DESCRIPTION
 *  update 425 tab bar
 * PARAMETERS
 *   title                         : [IN ] (N/A) String of title
 *   n_tabs                        : [IN ] (N/A) Total tab count
 *   highlighted_tab               : [IN ] (N/A) Index of highlight tab
 *   tab_items                     : [IN ] (N/A) Tab item list
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat428_update_tabbar(UI_string_type title, PU8 title_icon, S8 n_tabs, S8 highlighted_tab, tab_bar_item_type *tab_items);


/*****************************************************************************
 * FUNCTION
 *  wgui_cat428_SetTabSelectCallback
 * DESCRIPTION
 *  set 428 tab select callback
 * PARAMETERS
 *   select_callback               : [IN ] (N/A) Callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat428_SetTabSelectCallback(void (*select_callback) (int index));


/*****************************************************************************
 * FUNCTION
 *  wgui_cat428_BlinkTab
 * DESCRIPTION
 *  start tab blink
 * PARAMETERS
 *   tab                           : [IN ] (N/A) Inbex of tab
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat428_BlinkTab(S8 tab);


/*****************************************************************************
 * FUNCTION
 *  wgui_cat428_UnBlinkTab
 * DESCRIPTION
 *  category 428 stop tab blink
 * PARAMETERS
 *   tab                           : [IN ] (N/A) Index of tab
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat428_UnBlinkTab(S8 tab);


/*****************************************************************************
 * FUNCTION
 *  wgui_cat428_update_title
 * DESCRIPTION
 *  update the title of category428 screen
 *  Category 428 screen should be currently displayed.
 * PARAMETERS
 *   title                         : [TITLE ] (N/A) 
 *   highlightitle_iconed_item     : [IN ] (N/A) 
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat428_update_title(UI_string_type title, PU8 title_icon);


/*****************************************************************************
 * FUNCTION
 *  ShowCategory428Screen_sty1
 * DESCRIPTION
 *  Displays the category428 screen
 *  [FTE]: support (tool bar is avaiable)
 *  For New Contact List category, this category have three levels: 0, 1, 2.
 *  Level 2 is for contact list with 3 icon and 1 text.
 *  Level 0 is for group  with 1 icon and 1 text.
 *  Level 1 is for group  with 2 icon and 1 text.
 *  The friend id will show in hint when highlighted.
 * 
 * <img name="wgui_cat428_img1" />
 * PARAMETERS
 *   title                         : [IN ] (TITLE) Title for myself
 *   title_icon                    : [IN ] (N/A) Title icon for myself
 *   left_softkey                  : [IN ] (LSK) Left softkey label
 *   left_softkey_icon             : [IN ] (N/A) Icon for the left softkey
 *   right_softkey                 : [IN ] (RSK) Right softkey label
 *   right_softkey_icon            : [IN ] (N/A) Icon for the right softkey
 *   n_tabs                        : [IN ] (N/A) Number of tabs
 *   highlighted_tab               : [IN ] (N/A) Highlighted tab
 *   tab_items                     : [IN ] (N/A) Tab list
 *   number_of_items               : [IN ] (N/A) Number of menu items
 *   get_item_func                 : [IN ] (N/A) Callback function to get menu text.
 *   get_hint_func                 : [IN ] (N/A) (Deprecated) Callback function to get menu hint.
 *   get_level_callback            : [IN ] (N/A) Callback function to get menu level.
 *   get_state_func                : [IN ] (N/A) Callback function to get group state.
 *   set_state_func                : [IN ] (N/A) Callback function to set group state.
 *   folder_clicked_callback       : [IN ] (N/A) Callback function when pen on first icon.
 *   sample_icon                   : [IN ] (N/A) Sample icon to get image dimension of buddy icon
 *   highlighted_item              : [IN ] (N/A) Default highlighted menu item
 *   information                   : [IN ] (C428_1) Information will show in information bar.
 *   history_buffer                : [IN ] (N/A) History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * </code>
 *****************************************************************************/
extern void ShowCategory428Screen_sty1(
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
        U8 *history_buffer);


/*****************************************************************************
 * FUNCTION
 *  ShowCategory429Screen
 * DESCRIPTION
 *  Displays the category429 screen
 *  [FTE]: not support
 * <img name="wgui_cat429_img1" />
 * PARAMETERS
 *   title                         : [IN ] (TITLE) Title for the screen
 *   title_icon                    : [IN ] (N/A) Icon shown with the title
 *   left_softkey                  : [IN ] (LSK) Left softkey label
 *   left_softkey_icon             : [IN ] (N/A) Icon for the left softkey
 *   right_softkey                 : [IN ] (RSK) Right softkey label
 *   right_softkey_icon            : [IN ] (N/A) Icon for the right softkey
 *   name                          : [IN ] (N/A) User Name
 *   userid                        : [IN ] (N/A) User Id
 *   status_icon                   : [IN ] (N/A) Status Icon
 *   photo_filename                : [IN ] (N/A) File name of photo
 *   alternative_photo             : [IN ] (N/A) Default photo if 'photo_filename' is NULL
 *   mood_caption                  : [IN ] (C429_1) String ID to "Mood" literally
 *   mood_icon                     : [IN ] (N/A) Image indicating mood
 *   device_caption                : [IN ] (C429_2) Device Name
 *   device_string                 : [IN ] (C429_3) Device String
 *   buffer                        : [IN ] (N/A) Buffer the input box should use.
 *   buffer_size                   : [IN ] (N/A) Size of the buffer.
 *   history_buffer                : [IN ] (N/A) History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_429(void)
 * {
 *     U8 *guiBuffer = NULL;
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     memset(g_buffer, 0, MAX_LOCAL_BUFFER);
 *     memset(g_buffer1, 0, MAX_LOCAL_BUFFER_1);
 * 
 *     mmi_asc_to_ucs2((PS8) g_buffer1, (PS8) "JOE");
 *     mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "D:\\CSB\\Am.gif");
 * 
 *     ShowCategory429Screen(
 *             (UI_string_type)GetString(STR_ID_CSB_CATEGORY_TEXT),
 *             NULL,
 *             L"LSK",
 *             NULL,
 *             L"RSK",
 *             NULL,
 *             (UI_string_type)GetString(STR_ID_CSB_CATEGORY_TEXT),
 *             L"Joyce@mtk.com ",
 *             (PU8)GetImage((U16) (IMG_PROFILES_OUTDOOR)),
 *             (S8*) g_buffer,
 *             NULL,
 *             L"Mood:",
 *             (PU8)GetImage((U16) (IMG_PROFILES_OUTDOOR)),
 *             L"Device:",
 *             L"Mobile",
 *             (U8*) g_buffer1,
 *             (S32) mmi_ucs2strlen((S8*) g_buffer1),
 *             guiBuffer);
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory429Screen(
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
        U8 *history_buffer);

/*DOM-NOT_FOR_SDK-BEGIN*/        
        
/* Category 430 */
#if defined(__MMI_MAINLCD_240X320__)|| defined(__MMI_MAINLCD_240X400__)
#define CAT430_VERTICAL_GAP                  4
#define CAT430_HORIZONTAL_GAP                3
#define CAT430_SENDING_BOX_V_GAP             2
#define CAT430_SENDING_BOX_H_GAP             0
#else /* defined(__MMI_MAINLCD_240X320__)|| defined(__MMI_MAINLCD_240X400__) */ 
#define CAT430_VERTICAL_GAP                  2
#define CAT430_HORIZONTAL_GAP                2
#define CAT430_SENDING_BOX_V_GAP             2
#define CAT430_SENDING_BOX_H_GAP             0
#endif /* defined(__MMI_MAINLCD_240X320__)|| defined(__MMI_MAINLCD_240X400__) */ 

#if !defined(__MMI_MAINLCD_128X128__)
#undef CAT430_NAME_IN_LOG       /* Show name outside logbox */
#else /* !defined(__MMI_MAINLCD_128X128__) */
#define CAT430_NAME_IN_LOG      /* Show name inside logbox */
#endif /* !defined(__MMI_MAINLCD_128X128__) */

/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  ShowCategory430Screen
 * DESCRIPTION
 *  Displays the category430 screen
 *  [FTE]: support(tool bar is not avaiable)
 * <img name="wgui_cat430_img1" />
 * PARAMETERS
 *   title                         : [IN ] (TITLE) Title for the screen
 *   title_icon                    : [IN ] (N/A) Title icon for the screen
 *   left_softkey                  : [IN ] (LSK) Left softkey label
 *   left_softkey_icon             : [IN ] (N/A) Icon for the left softkey
 *   right_softkey                 : [IN ] (RSK) Right softkey label
 *   right_softkey_icon            : [IN ] (N/A) Icon for the right softkey
 *   log_buffer1                   : [IN ] (UNLIM) log buffer 1
 *   log_buffer_size1              : [IN ] (N/A) log buffer 1 size
 *   log_buffer2                   : [IN ] (UNLIM) log buffer 2
 *   log_buffer_size2              : [IN ] (N/A) log buffer 2 size
 *   show_sending_buffer           : [IN ] (N/A) Is show send string
 *   max_sending_buffer_size       : [IN ] (N/A) Send string buffer size
 *   sending_buffer                : [IN ] (UNLIM) Send string buffer
 *   sent_count                    : [IN ] (N/A) Send count
 *   name1                         : [IN ] (C430_1) String of name 1
 *   name2                         : [IN ] (C430_1) String of name 2
 *   history_buffer                : [IN ] (N/A) Hisotry buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_430(void)
 * {
 *     U8 *guiBuffer = NULL;
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     memset(g_buffer, 0, MAX_LOCAL_BUFFER);
 *     memset(g_buffer1, 0, MAX_LOCAL_BUFFER_1);
 * 
 *     ShowCategory430Screen(
 *         STR_ID_CSB_CATEGORY_TEXT,
 *         0,
 *         STR_ID_CSB_LSK_TEXT,
 *         0,
 *         STR_ID_CSB_RSK_TEXT,
 *         0,
 *         g_buffer,
 *         CSB_MAX_BUFFER_LEN,
 *         g_buffer1,
 *         CSB_MAX_BUFFER_LEN,
 *         TRUE,
 *         CSB_MAX_BUFFER_LEN,
 *         g_buffer1,
 *         0,
 *         (PU8) GetString(STR_ID_CSB_DUMMY_TEXT),
 *         (PU8) GetString(STR_ID_CSB_DUMMY_TEXT),
 *         guiBuffer);
 * 
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory430Screen(
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
                U8 *history_buffer);


/*****************************************************************************
 * FUNCTION
 *  UpdateCategory430LSK
 * DESCRIPTION
 *  update 430 left softkey
 * PARAMETERS
 *   left_softkey                  : [IN ] (LSK) string
 *   left_softkey_icon             : [IN ] (N/A) icon
 * RETURNS
 *  void
 *****************************************************************************/
extern void UpdateCategory430LSK(U16 left_softkey, U16 left_softkey_icon);


/*****************************************************************************
 * FUNCTION
 *  UpdateCategory430RSK
 * DESCRIPTION
 *  update 430 right softkey
 * PARAMETERS
 *   right_softkey                 : [IN ] (RSK) string
 *   right_softkey_icon            : [IN ] (N/A) icon
 * RETURNS
 *  void
 *****************************************************************************/
extern void UpdateCategory430RSK(U16 right_softkey, U16 right_softkey_icon);


/*****************************************************************************
 * FUNCTION
 *  UpdateCategory430LogBox
 * DESCRIPTION
 *  update category 430 logbox
 * PARAMETERS
 *   update_log1                   : [IN ] (UNLIM) Is update log1
 *   update_log2                   : [IN ] (UNLIM) Is update log2
 * RETURNS
 *  void
 *****************************************************************************/
extern void UpdateCategory430LogBox(MMI_BOOL update_log1, MMI_BOOL update_log2);


/*****************************************************************************
 * FUNCTION
 *  ConfigureCategory430SendingBox
 * DESCRIPTION
 *  configure 430 sending box
 * PARAMETERS
 *   show_sending_buffer           : [IN ] (N/A) string buffer to show
 *   sent_count                    : [IN ] (N/A) total count of sent
 * RETURNS
 *  void
 *****************************************************************************/
extern void ConfigureCategory430SendingBox(MMI_BOOL show_sending_buffer, S16 sent_count);


/*****************************************************************************
 * FUNCTION
 *  SetCategory430SendingBoxCharacterCount
 * DESCRIPTION
 *  set sent box char count
 * PARAMETERS
 *   sent_count                    : [IN ] (N/A) count of sending box
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetCategory430SendingBoxCharacterCount(S16 sent_count);


/* Category 435 */


/*****************************************************************************
 * FUNCTION
 *  ShowCategory435Screen
 * DESCRIPTION
 *  Displays the category435 screen
 *  [FTE]: not support
 *  1. Category 435 is composed by one background log and one popup text editor.
 *  2. icon_callback is typically set as wgui_general_multiline_icon_handler()
 *  (configured by wgui_config_general_multiline_icon_handler)
 * 
 * <img name="wgui_cat435_img1" />
 * PARAMETERS
 *   title                         : [IN ] (TITLE) Title for the screen
 *   title_icon                    : [IN ] (N/A) Title icon for the screen
 *   left_softkey                  : [IN ] (LSK) Left softkey label
 *   left_softkey_icon             : [IN ] (N/A) Icon for the left softkey
 *   right_softkey                 : [IN ] (RSK) Right softkey label
 *   right_softkey_icon            : [IN ] (N/A) Icon for the right softkey
 *   editor_left_softkey           : [IN ] (LSK) Left softkey label when popup editor is active
 *   editor_left_softkey_icon      : [IN ] (N/A) Icon for the left softkey when popup editor is active
 *   editor_right_softkey          : [IN ] (RSK) Right softkey label when popup editor is active
 *   editor_right_softkey_icon     : [IN ] (N/A) Icon for the right softkey when popup editor is active
 *   n_tabs                        : [IN ] (N/A) Number of tabs
 *   highlighted_tab               : [IN ] (N/A) Highlighted tab
 *   tab_items                     : [IN ] (N/A) Tab list
 *   show_popup                    : [IN ] (N/A) Whether to display popup editor
 *   popup_title                   : [IN ] (C435_1) The title of popup editor
 *   input_type                    : [IN ] (N/A) Input method type
 *   buffer                        : [IN ] (UNLIM) Buffer the text input
 *   buffer_size                   : [IN ] (N/A) Character count of the text input buffer. (without '\0')
 *   log_buffer                    : [IN ] (UNLIM) Buffer the background log
 *   log_buffer_size               : [IN ] (N/A) Character count of the background log buffer.  (without '\0')
 *   icon_callback                 : [IN ] (N/A) Callback to translate a string to an icon
 *   sample_icon                   : [IN ] (N/A) sample icon data
 *   history_buffer                : [IN ] (N/A) History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_435(void)
 * {
 *     U8 *guiBuffer = NULL;
 *     tab_bar_item_type MMI_tab_bar_items[3];
 *     U8 index;
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     memset(g_buffer, 0, MAX_LOCAL_BUFFER);
 *     memset(g_buffer1, 0, MAX_LOCAL_BUFFER_1);
 * 
 *     for (index = 0; index < 3; index++)
 *     {
 *         MMI_tab_bar_items[index].icon = (PU8) GetImage(gIndexIconsImageList[index]);
 *         MMI_tab_bar_items[index].text = NULL;
 *         MMI_tab_bar_items[index].flags = 0;
 *     }
 * 
 *     ShowCategory435Screen(
 *         (UI_string_type) GetString(STR_ID_CSB_CATEGORY_TEXT),
 *         (PU8)NULL,
 *         STR_ID_CSB_LSK_TEXT,
 *         0,
 *         STR_ID_CSB_RSK_TEXT,
 *         0,
 *         STR_ID_CSB_DUMMY_TEXT,
 *         0,
 *         STR_ID_CSB_DUMMY_TEXT,
 *         0,
 *         (S8) 3,
 *         (S8) 1,
 *         MMI_tab_bar_items,
 *         FALSE,
 *         NULL,
 *         IMM_INPUT_TYPE_SENTENCE,
 *         (U8*) g_buffer,
 *         G_BUF1_STRING_LEN,
 *         (U8*) g_buffer1,
 *         G_BUF1_STRING_LEN,
 *         NULL,
 *         (PU8) GetImage(IMG_PROFILES_OUTDOOR),
 *         guiBuffer);
 * 
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory435Screen(
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
                U8 *history_buffer);


/*****************************************************************************
 * FUNCTION
 *  SetCategory435EditorRSKFunction
 * DESCRIPTION
 *  Set the right softkey function for editor popup in  category435 screen
 * PARAMETERS
 *   f                             : [IN ] (N/A) editory right softkey function
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetCategory435EditorRSKFunction(void (*f) (void));


/*****************************************************************************
 * FUNCTION
 *  SetCategory435EditorLSKFunction
 * DESCRIPTION
 *  Set the left softkey function for editor popup in  category435 screen
 * PARAMETERS
 *   f                             : [IN ] (N/A) editory left softkey function
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetCategory435EditorLSKFunction(void (*f) (void));


/*****************************************************************************
 * FUNCTION
 *  SetCategory435RSKFunction
 * DESCRIPTION
 *  Set the left softkey function category435 screen without popup
 * PARAMETERS
 *   f                             : [IN ] (N/A) right softkey function
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetCategory435RSKFunction(void (*f) (void));


/*****************************************************************************
 * FUNCTION
 *  SetCategory435LSKFunction
 * DESCRIPTION
 *  Set the left softkey function category435 screen without popup
 * PARAMETERS
 *   f                             : [IN ] (N/A) left softkey function
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetCategory435LSKFunction(void (*f) (void));



/*****************************************************************************
 * FUNCTION
 *  UpdateCategory435LogText
 * DESCRIPTION
 *  Update the log text in category 435
 * PARAMETERS
 *   log_buffer                    : [IN ] (UNLIM) log box buffer
 *   log_buffer_size               : [IN ] (UNLIM) log box buffer size
 * RETURNS
 *  void
 *****************************************************************************/
extern void UpdateCategory435LogText(U8 *log_buffer, S32 log_buffer_size);


/*****************************************************************************
 * FUNCTION
 *  UpdateCategory435LogAndEditorText
 * DESCRIPTION
 *  Update the log and editor text in category 435
 * PARAMETERS
 *   buffer                        : [IN ] (UNLIM) editor buffer
 *   buffer_size                   : [IN ] (N/A) editor buffer size
 *   log_buffer                    : [IN ] (UNLIM) log box buffer
 *   log_buffer_size               : [IN ] (N/A) log box buffer size
 * RETURNS
 *  void
 *****************************************************************************/
extern void UpdateCategory435LogAndEditorText(U8 *buffer, S32 buffer_size, U8 *log_buffer, S32 log_buffer_size);


/*****************************************************************************
 * FUNCTION
 *  Category435ShowPopup
 * DESCRIPTION
 *  show popup screen
 * PARAMETERS
 *  update_screen       [IN]        Is update screen
 * RETURNS
 *  void
 *****************************************************************************/
extern void Category435ShowPopup(BOOL update_screen);


/*****************************************************************************
 * FUNCTION
 *  Category435HidePopup
 * DESCRIPTION
 *  set hide popup
 * PARAMETERS
 *  update_screen       [IN]        Is update screen
 * RETURNS
 *  void
 *****************************************************************************/
extern void Category435HidePopup(BOOL update_screen);


/*****************************************************************************
 * FUNCTION
 *  Category435IsPopupDisplayed
 * DESCRIPTION
 *  Check if popup editor in category 435 is displayed
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL
 *****************************************************************************/
extern BOOL Category435IsPopupDisplayed(void);


/*****************************************************************************
 * FUNCTION
 *  Category435DirectInsertString
 * DESCRIPTION
 *  direct insert string
 *  Typically used to insert mood symbols. Not efficient for inserting long string
 * PARAMETERS
 *   s                             : [IN ] (UNLIM) Inputed string 
 *   redraw_screen                 : [IN ] (N/A) Is redraw screen
 * RETURNS
 *  void
 *****************************************************************************/
extern void Category435DirectInsertString(UI_string_type s, BOOL redraw_screen);


/*****************************************************************************
 * FUNCTION
 *  UpdateCategory435TabBar
 * DESCRIPTION
 *  update category 435 tab bar
 * PARAMETERS
 *   title                         : [IN ] (N/A) Title string
 *   n_tabs                        : [IN ] (N/A) Total count of tab items
 *   highlighted_tab               : [IN ] (N/A) Index of highlighted item
 *   tab_items                     : [IN ] (N/A) Tab bar item list
 * RETURNS
 *  void
 *****************************************************************************/
extern void UpdateCategory435TabBar(UI_string_type title, PU8 title_icon, S8 n_tabs, S8 highlighted_tab, tab_bar_item_type *tab_items);


/*****************************************************************************
 * FUNCTION
 *  SetCategory435TabSelectCallback
 * DESCRIPTION
 *  set category 435 tab select callback
 * PARAMETERS
 *  select_callback                : [IN ] (N/A) callback function
 * RETURNS
 *  void
 *****************************************************************************/
void SetCategory435TabSelectCallback(void (*select_callback) (int index));


/*****************************************************************************
 * FUNCTION
 *  Category435BlinkTab
 * DESCRIPTION
 *  start tab blink
 * PARAMETERS
 *   tab                           : [IN ] (N/A) tab index
 * RETURNS
 *  void
 *****************************************************************************/
extern void Category435BlinkTab(S8 tab);


/*****************************************************************************
 * FUNCTION
 *  Category435UnBlinkTab
 * DESCRIPTION
 *  stop tab blink
 * PARAMETERS
 *   tab                           : [IN ] (N/A) tab index
 * RETURNS
 *  void
 *****************************************************************************/
extern void Category435UnBlinkTab(S8 tab);



/*****************************************************************************
 * FUNCTION
 *  wgui_cat435_set_hilite_list
 * DESCRIPTION
 *  set the hilite list information of category 435
 * PARAMETERS
 *   hilite_list                   : [IN ] (N/A) hilite list
 *   number_of_list                : [IN ] (N/A) number of hilite list
 *   curr_hilite_idx               : [IN ] (N/A) current hilite index
 *   hilite_cb                     : [IN ] (N/A) callback while each item is highlighted
 *   click_cb                      : [IN ] (N/A) callback while each item is clicked, hilite_cb will also be triggered at the same time
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat435_set_hilite_list(
            HILITE_STR *hilite_list,
            U16 number_of_list,
            U16 curr_hilite_idx,
            void (*hilite_cb)(S32 idx),
            void (*click_cb)(S32 idx));


/*****************************************************************************
 * FUNCTION
 *  wgui_cat435_log_get_visible_character_range
 * DESCRIPTION
 *  get the visible area of log multiline inputbox
 * PARAMETERS
 *   start                         : [OUT] (N/A) start position
 *   end                           : [OUT] (N/A) end position
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat435_log_get_visible_character_range(S32 *start, S32 *end);

extern void wgui_cat435_register_text_length_changed_hdlr(void(*f)(S32));
/*****************************************************************************
 * FUNCTION
 *  wgui_catimps_set_bg_img_name
 * DESCRIPTION
 *  set the background image filename for IMPS related screens (435 and )
 * PARAMETERS
 *   filename                      : [IN ] (N/A) image filename
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_catimps_set_bg_img_name(U8* filename);


/*****************************************************************************
 * FUNCTION
 *  wgui_cat435_log_check_highlighted_item_in_visible
 * DESCRIPTION
 *  Check whether the highlighted string is at the visible area
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL wgui_cat435_log_check_highlighted_item_in_visible(void);

#endif /* __WGUI_CATEGORIES_IMPS_H__ */ 


