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
*  LAWS PRINCIPLES.	 ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 * Filename:
 * ---------
 *  wgui_asyncdynamic_menuitems.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/

#ifndef __WGUI_ASYNCDYNAMIC_MENUITEMS_H__
#define __WGUI_ASYNCDYNAMIC_MENUITEMS_H__

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "gui_typedef.h"
#include "gui_fixed_menuitems.h"
#include "MMIDataType.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/* DOM-NOT_FOR_SDK-BEGIN */

typedef struct
{
    S32 head_item_index;
    S32 head;
    S32 tail;
    S32 count;
    S32 n_total_items;
    GetAsyncItemFuncPtr load_func;
    GetAsyncHintFuncPtr hint_func;
} asyncdynamic_item_circular_buffer_t;

typedef void (*wgui_asyncdynamic_menuitem_load_complete_funcptr_type)(S32 start_index, S32 n_items);

/* DOM-NOT_FOR_SDK-END */

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
extern asyncdynamic_item_circular_buffer_t asyncdynamic_item_buffer;
    
/***************************************************************************** 
 * Global Function 
 *****************************************************************************/



/*****************************************************************************
 * <group dom_menu_wgui_layer_asyncdynamic_menu_item>
 * FUNCTION
 *  init_asyncdynamic_item_buffer
 * DESCRIPTION
 *  Initialize the asyncdynamic item buffer.
 *
 *  a. If the icontext-list menu item has more than one string, it can not support hint callback
 *  because hint and second string item use the same memory buffer.
 *  b. If 'history' is not NULL, 'h_item' is ignored. 
 * PARAMETERS
 *  total_items         : [IN]        Total number of items
 *  get_item_func       : [IN]        A call back function for filling in item text & image at run time
 *  get_hint_func       : [IN]        Callback function for filling hint data
 * RETURNS
 *  Return 1 if successful; otherwise 0.
 *****************************************************************************/
extern S32 init_asyncdynamic_item_buffer(
            S32 n_items,
            GetAsyncItemFuncPtr get_item_func,
            GetAsyncHintFuncPtr get_hint_func);

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * <group dom_menu_wgui_layer_asyncdynamic_menu_item>
 * FUNCTION
 *  get_asyncdynamic_item_from_buffer
 * DESCRIPTION
 *  Get the specified item in the buffer.
 * PARAMETERS
 *  index       : [IN]        Item index to be retrieved
 * RETURNS
 *  An icontext list menu item
 *****************************************************************************/
extern fixed_icontext_list_menuitem_type* get_asyncdynamic_item_from_buffer(S32 index);


/*****************************************************************************
 * <group dom_menu_wgui_layer_asyncdynamic_menu_item>
 * FUNCTION
 *  in_asyncdynamic_item_buffer
 * DESCRIPTION
 *  Check whether a item is loaded in buffer
 * PARAMETERS
 *  index       : [IN]        Item index to be checked
 * RETURNS
 *  Return TRUE if the specified item exists in the buffer; otherwise, FALSE.
 *****************************************************************************/
extern pBOOL in_asyncdynamic_item_buffer(S32 index);


/*****************************************************************************
 * <group dom_menu_wgui_layer_asyncdynamic_menu_item>
 * FUNCTION
 *  load_chunk_asyncdynamic_item_buffer
 * DESCRIPTION
 *  Load a chunk of items, starting from [start_index] to [start_index+n_items-1], to the buffer.
 *  The loading mechanism will try to maintain the continuous buffer as large as possible.
 * PARAMETERS
 *  start_index     : [IN]        The starting index of requested items
 *  n_items         : [IN]        The number of items to be loaded
 * RETURNS
 *  1: success, 0: fail
 *****************************************************************************/
extern S32 load_chunk_asyncdynamic_item_buffer(S32 start_index, S32 n_items);

/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * <group dom_menu_wgui_layer_asyncdynamic_menu_item>
 * FUNCTION
 *  resize_asyncdynamic_icontext_menuitems_to_list_width
 * DESCRIPTION
 *  Resize the asyncdynamic menu item width to the maximum.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void resize_asyncdynamic_icontext_menuitems_to_list_width(void);

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * <group dom_menu_wgui_layer_asyncdynamic_menu_item>
 * FUNCTION
 *  wgui_asyncdynamic_menuitem_register_load_complete_callback
 * DESCRIPTION
 *  Registers the load complete callback after items are loaded in load_chunk_asyncdynamic_item_buffer().
 * PARAMETERS
 *  callback       : [IN]     Load complete callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_asyncdynamic_menuitem_register_load_complete_callback(wgui_asyncdynamic_menuitem_load_complete_funcptr_type callback);

/* DOM-NOT_FOR_SDK-END */

#endif /* __WGUI_ASYNCDYNAMIC_MENUITEMS_H__ */


