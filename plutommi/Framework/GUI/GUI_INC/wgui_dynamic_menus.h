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
 * Filename:
 * ---------
 *  wgui_dynamic_menus.h
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  In order to use limited memory (size decided in compile-time) to load 
 *  unlimited items (size decide in run-time) to a category screen, a 
 *  modification in MMI for dynamic item loading is required as the following.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *			   HISTORY
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

#ifndef __WGUI_DYNAMIC_MENUS_H__
#define __WGUI_DYNAMIC_MENUS_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMIDataType.h"
#include "gui_effect_oem.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * <group dom_menu_wgui_layer_dynamic_menu_basic>
 * FUNCTION
 *  show_dynamic_list
 * DESCRIPTION
 *  Show the dynamic list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void show_dynamic_list(void);

/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * <group dom_menu_wgui_layer_dynamic_menu_basic>
 * FUNCTION
 *  reset_dynamic_list
 * DESCRIPTION
 *  Reset the dynamic list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void reset_dynamic_list(void);

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * <group dom_menu_wgui_layer_dynamic_menu_basic>
 * FUNCTION
 *  redraw_dynamic_list
 * DESCRIPTION
 *  Redraw the dynamic list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void redraw_dynamic_list(void);

extern void show_dynamic_matrix(void);
extern void reset_dynamic_matrix(void);
extern void redraw_dynamic_matrix(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_dynamic_menu_basic>
 * FUNCTION
 *  wgui_dynamic_list_menu_end_frame
 * DESCRIPTION
 *  Show the dynamic list for the last frame.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_dynamic_list_menu_end_frame(void);



/*****************************************************************************
 * <group dom_menu_wgui_layer_dynamic_menu_property_setting>
 * FUNCTION
 *  register_dynamic_list_shortcut_handler
 * DESCRIPTION
 *  Register menu shortcut for the dynamic list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void register_dynamic_list_shortcut_handler(void);

extern void register_dynamic_matrix_shortcut_handler(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_dynamic_menu_property_setting>
 * FUNCTION
 *  register_dynamic_list_keys
 * DESCRIPTION
 *  Register key handlers of the dynamic list, including 
 *  KEY_UP_ARROW, KEY_VOL_UP, KEY_DOWN_ARROW, and KEY_VOL_DOWN.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void register_dynamic_list_keys(void);



/*****************************************************************************
 * <group dom_menu_wgui_layer_dynamic_menu_misc>
 * FUNCTION
 *  dynamic_list_goto_item
 * DESCRIPTION
 *  Go to the specified item.
 * PARAMETERS
 *  item_index      : [IN]        Item index
 * RETURNS
 *  void
 *****************************************************************************/
extern void dynamic_list_goto_item(S32 item_index);


/*****************************************************************************
 * <group dom_menu_wgui_layer_dynamic_menu_misc>
 * FUNCTION
 *  dynamic_list_goto_item
 * DESCRIPTION
 *  Go to the specified item.
 * PARAMETERS
 *  item_index      : [IN]        Item index
 * RETURNS
 *  void
 *****************************************************************************/
extern void dynamic_list_shortcut_handle(S32 item_index);


#ifdef GUI_LIST_MENU_SMOOTH_SCROLLING_BY_NUMBER_KEY
/*****************************************************************************
 * <group dom_menu_wgui_layer_dynamic_menu_misc>
 * FUNCTION
 *  dynamic_list_shortcut_handle_with_SSK
 * DESCRIPTION
 *  Go to the specified item with ssk effect.
 * PARAMETERS
 *  item_index      : [IN]        Item index
 * RETURNS
 *  void
 *****************************************************************************/
extern void dynamic_list_shortcut_handle_with_SSK(S32 item_index);
#endif  /* GUI_LIST_MENU_SMOOTH_SCROLLING_BY_NUMBER_KEY */


/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * <group dom_menu_wgui_layer_dynamic_menu_misc>
 * FUNCTION
 *  dynamic_list_goto_item_no_redraw
 * DESCRIPTION
 *  Go to a specified item without redrawing. For example, set the highlighted item
 *  before the dynamic list is shown by the draw manager.
 * PARAMETERS
 *  item_index      : [IN]        Item index
 * RETURNS
 *  void
 *****************************************************************************/
extern void dynamic_list_goto_item_no_redraw(S32 item_index);

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * <group dom_menu_wgui_layer_dynamic_menu_misc>
 * FUNCTION
 *  dynamic_list_goto_previous_item
 * DESCRIPTION
 *  Go to the previous item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void dynamic_list_goto_previous_item(void);


/*****************************************************************************
 * <group dom_menu_wgui_layer_dynamic_menu_misc>
 * FUNCTION
 *  dynamic_list_goto_next_item
 * DESCRIPTION
 *  Go to the next item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void dynamic_list_goto_next_item(void);

extern void dynamic_matrix_goto_item(S32 item_index);
extern void dynamic_matrix_goto_item_no_redraw(S32 item_index);
extern void dynamic_matrix_goto_next_item(void);
extern void dynamic_matrix_goto_next_row(void);
extern void dynamic_matrix_goto_previous_item(void);
extern void dynamic_matrix_goto_previous_row(void);


/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * <group dom_menu_wgui_layer_dynamic_menu_property_setting>
 * FUNCTION
 *  DynamicListIncreaseItem
 * DESCRIPTION
 *  Increase the total number of dynamic item.
 * PARAMETERS
 *  steps       : [IN]        Number of items to be increased
 * RETURNS
 *  void
 *****************************************************************************/
extern void DynamicListIncreaseItem(S16 steps);


/*****************************************************************************
 * <group dom_menu_wgui_layer_dynamic_menu_property_setting>
 * FUNCTION
 *  DynamicListGetItems
 * DESCRIPTION
 *  Return total number of dynamic items and the requested item text from the dynamic buffer.
 *  The caller must take care of the validity of the specified item in the buffer.
 * PARAMETERS
 *  string          : [OUT]       Pointer of parameter to store requested item text
 *  item_index      : [IN]        Index of the requested item
 * RETURNS
 *  Total number of dynamic items
 *****************************************************************************/
extern S32 DynamicListGetItems(U8 *string, U16 item_index);


/*****************************************************************************
 * <group dom_menu_wgui_layer_dynamic_menu_property_setting>
 * FUNCTION
 *  DynamicListGetHighlightedItem
 * DESCRIPTION
 *  Return the index and text of the highlighted item.
 * PARAMETERS
 *  string      : [OUT]       Highlighted item text
 * RETURNS
 *  Highlighted item index
 *****************************************************************************/
extern S32 DynamicListGetHighlightedItem(U8 *string);


/*****************************************************************************
 * <group dom_menu_wgui_layer_dynamic_menu_property_setting>
 * FUNCTION
 *  DynamicGetFirstDisplayedItem
 * DESCRIPTION
 *  Return the index and text of first displayed item.
 * PARAMETERS
 *  string      : [OUT]       Pointer of parameter to store first displayed item text
 * RETURNS
 *  First displayed item index
 *****************************************************************************/
extern S32 DynamicGetFirstDisplayedItem(U8 *string);


#endif /* __WGUI_DYNAMIC_MENUS_H__ */ 


