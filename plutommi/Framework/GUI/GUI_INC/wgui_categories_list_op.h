/*******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
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
*******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   wgui_categories_list_op.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *  Operator related categories for list menu
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef __WGUI_CATEGORIES_LIST_OP_H__
#define __WGUI_CATEGORIES_LIST_OP_H__

#include "MMI_features.h"
#include "gui_data_types.h"
#include "MMIDataType.h"
#include "kal_general_types.h"


#if defined(__MMI_OP01_DCD__)
    typedef MMI_BOOL (*wgui_cat_182_getimagepath)(S32 item_index, S8 * image_buff);
#if defined(__MMI_MAINLCD_176X220__)
    #define CAT182_TEXT_X          64
    #define CAT182_ICON_X          6
    #define CAT182_ICON_Y          1
    #define CAT182_MENUITEM_HEIGHT 52
#elif (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__))
    #define CAT182_TEXT_X          64
    #define CAT182_ICON_X          9
    #define CAT182_ICON_Y          5
    #define CAT182_MENUITEM_HEIGHT 60
#else
    #define CAT182_TEXT_X          64
    #define CAT182_ICON_X          6
    #define CAT182_ICON_Y          1
    #define CAT182_MENUITEM_HEIGHT 52
#endif
    #define CAT182_ICON_WIDTH      50
    #define CAT182_ICON_HEIGHT     50


/**************************************************************
  * FUNCTION
  *  ShowCategory182Screen
  * Description
  *  DCD channel/story list category screen.The image in each menuitem may be gif/jgeg style.
  * 
  * <img name="wgui_cat182_img1" />
  * PARAMETERS
  *  title                         : [IN ] (TITLE) Title for the screen
  *  title_icon                    : [IN ] (N/A) Icon shown with the title
  *  left_softkey                  : [IN ] (LSK) Left softkey label
  *  left_softkey_icon             : [IN ] (N/A) Icon for the Left softkey
  *  right_softkey                 : [IN ] (RSK) Right softkey label
  *  right_softkey_icon            : [IN ] (N/A) Icon for the right softkey
  *  number_of_items               : [IN ] (N/A) Number of items
  *  list_of_items                 : [IN ] (ICONTEXT) Array of items to be displayed
  *  get_image_func                : [IN ] (N/A) Get first column icons path callback
  *  list_of_state                 : [IN ] (N/A) Read state(0 read,1 unread)
  *  highlighted_item              : [IN ] (N/A) Default item to be highlighted(if there is no history)
  *  history_buffer                : [IN ] (N/A) History buffer
  * Returns
  *  void
  **************************************************************/
extern void ShowCategory182Screen(
                UI_string_type title,
                PU8 title_icon,
                UI_string_type left_softkey,
                PU8 left_softkey_icon,
                UI_string_type right_softkey,
                PU8 right_softkey_icon,
                S32 number_of_items,
                U8 **list_of_items,
                wgui_cat_182_getimagepath get_image_func,
                U8 *list_of_state,
                S32 highlighted_item,
                U8 *history_buffer);
#endif /* __MMI_OP01_DCD__ */


#if defined(__MMI_OP11_HOMESCREEN__)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_OP11_HOMESCREEN__) */

#ifdef __MMI_CAT1X_0P11_SUPPORT__
typedef MMI_BOOL (*wgui_cat1002_op11_draw_menuitem_func) (S32 idx, MMI_BOOL is_hilighted, S32 x1, S32 y1, S32 x2, S32 y2);
/*****************************************************************************
 * FUNCTION
 *  wgui_cat1004_show
 * DESCRIPTION
 *  Displays the category1004 screen (adjust list order) for orange
 *  
 * PARAMETERS
 *  message_title               [IN]        Title for text area
 *  message                     [IN]        Text area
 *  left_softkey                [IN]        Left softkey label
 *  left_softkey_icon           [IN]        Left softkey icon
 *  right_softkey               [IN]        Right softkey label
 *  right_softkey_icon          [IN]        Right softkey icon
 *  number_of_items             [IN]        Number of items in the menu
 *  list_of_items               [IN]        Array of items
 *  list_of_icons               [IN]        Array of icons
 *  highlighted_item            [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat1002_op11_show(
            UI_string_type message_title,
            UI_string_type message,
            UI_string_type left_softkey,
            PU8 left_softkey_icon,
            UI_string_type right_softkey,
            PU8 right_softkey_icon,
            S32 number_of_items,
            U8 **list_of_items,
            U16 *list_of_icons1,
            U16 *list_of_icons2,
            S32 highlighted_item,
            wgui_cat1002_op11_draw_menuitem_func draw_menuitem_func,
            U8 *history_buffer);

extern void wgui_cat1002_op11_goto_list(S32 highlighted_item);
extern void wgui_cat1002_op11_touch_refresh_list(void);
extern void wgui_cat1002_op11_refresh_item_list(void);
extern void wgui_cat1002_op11_set_order_screen(MMI_BOOL is_order_screen);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat1001_op11_show
 * DESCRIPTION
 *  Displays the category1001 screen for op11
 *  
 * PARAMETERS
 *  message_title               [IN]        Title for text area
 *  message                     [IN]        Text area
 *  left_softkey                [IN]        Left softkey label
 *  left_softkey_icon           [IN]        Left softkey icon
 *  right_softkey               [IN]        Right softkey label
 *  right_softkey_icon          [IN]        Right softkey icon
 *  number_of_items             [IN]        Number of items in the menu
 *  list_of_items               [IN]        Array of items
 *  list_of_icons               [IN]        Array of icons
 *  highlighted_item            [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat1001_op11_show(
            UI_string_type message_title,
            UI_string_type message,
            UI_string_type left_softkey,
            PU8 left_softkey_icon,
            UI_string_type right_softkey,
            PU8 right_softkey_icon,
            S32 number_of_items,
            U8 **list_of_items,
            U16 *list_of_icons,
            U8 **list_of_descriptions,
            S32 highlighted_item,
            U8 *history_buffer);
#endif /* __MMI_CAT1X_0P11_SUPPORT__ */

#if defined(__MMI_OP01_DCD_V30__)
typedef MMI_BOOL (*wgui_cat9005_op01_getimagepath)(S32 item_index, S8 * image_buff);
#if defined(__MMI_MAINLCD_176X220__)
    #define CAT9005_OP01_TEXT_X          64
    #define CAT9005_OP01_ICON_X          6
    #define CAT9005_OP01_ICON_Y          1
    #define CAT9005_OP01_MENUITEM_HEIGHT 52
#elif (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__))
    #define CAT9005_OP01_TEXT_X          64
    #define CAT9005_OP01_ICON_X          9
    #define CAT9005_OP01_ICON_Y          5
    #define CAT9005_OP01_MENUITEM_HEIGHT 60
#else
    #define CAT9005_OP01_TEXT_X          64
    #define CAT9005_OP01_ICON_X          6
    #define CAT9005_OP01_ICON_Y          1
    #define CAT9005_OP01_MENUITEM_HEIGHT 52
#endif
    #define CAT9005_OP01_ICON_WIDTH      50
    #define CAT9005_OP01_ICON_HEIGHT     50

void wgui_cat9005_op01_show(
        UI_string_type title,
        PU8 title_icon,
        UI_string_type left_softkey,
        PU8 left_softkey_icon,
        UI_string_type right_softkey,
        PU8 right_softkey_icon,
        S32 number_of_items,
        U8 **list_of_items1,
        U8 **list_of_items2,
        wgui_cat9005_op01_getimagepath get_image_func,
        U8 *list_of_state,
        S32 highlighted_item,
        U8 *history_buffer,
        MMI_BOOL ext_flag);

#endif
#endif /* __WGUI_CATEGORIES_LIST_OP_H__ */ 

