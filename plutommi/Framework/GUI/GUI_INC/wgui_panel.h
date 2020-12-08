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
 *  wgui_panel.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Panel - UI component
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
 * This file contains internal UI component API, and is intended to be used by category screen module only. 
 * It's not recommended to be included in application code directly. 
 * For application developers, please include category screen header files instead (e.g., wgui_categories.h).
*/


#ifndef __WGUI_PANEL_H__
#define __WGUI_PANEL_H__

/*****************************************************************************
 * include
 ****************************************************************************/

/* DOM-NOT_FOR_SDK-BEGIN */
#include "MMIDataType.h"
#include "gui.h"
#include "gui_panel.h"
/* DOM-NOT_FOR_SDK-END */

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/



/*****************************************************************************
 * <group dom_panel_gui_layer_basic>
 * FUNCTION
 *  wgui_panel_create
 * DESCRIPTION
 *  Create panel object.
 * PARAMETERS
 *  x              : [IN] Is the x position of panel
 *  y              : [IN] Is the y position of panel
 *  width          : [IN] Is the width of panel
 *  height         : [IN] Is the height of panel
 *  background     : [IN] Is the background of panel
 *  display_focus  : [IN] Is flag of whether to display focussed state of element
 * RETURNS
 *  void
 * REMARKS
 *  This API should be paired with wgui_panel_close.
 * SEE ALSO
 *  You should also know wgui_panel_close as well.
 *****************************************************************************/
extern void wgui_panel_create(
                S32 x, 
                S32 y, 
                S32 width, 
                S32 height, 
                gui_util_painter_struct background,
                MMI_BOOL display_focus);

/*****************************************************************************
 * <group dom_panel_wgui_layer_basic>
 * FUNCTION
 *  wgui_panel_close
 * DESCRIPTION
 *  Close panel object.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * REMARKS
 *  This API should be paired with wgui_panel_create.
 * SEE ALSO
 *  You should also know wgui_panel_create as well.
 *****************************************************************************/
extern void wgui_panel_close(void);


/*****************************************************************************
 * <group dom_panel_gui_layer_basic>
 * FUNCTION
 *  wgui_panel_show
 * DESCRIPTION
 *  Display panel object and blt it to LCD.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_panel_show(void);


/*****************************************************************************
 * <group dom_panel_gui_layer_property_setting>
 * FUNCTION
 *  wgui_panel_set_element_focus
 * DESCRIPTION
 *  Set the foccused element to panel object.
 * PARAMETERS
 *  element_index       : [IN] Is the index of element
 *  update_display      : [IN] Is the flag of whether to update display or not
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_panel_set_element_focus(
                S32 element_index,
                MMI_BOOL update_display);

/*****************************************************************************
 * <group dom_panel_gui_layer_basic>
 * FUNCTION
 *  wgui_panel_add_element
 * DESCRIPTION
 *  Add one element to panel object.
 * PARAMETERS
 *  x                              : [IN] Is the x position of element
 *  y                              : [IN] Is the y position of element
 *  width                          : [IN] Is the width of element
 *  height                         : [IN] Is the height of element
 *  keycode                        : [IN] Is the registered key event (KEY_INVALID if no key event registered)
 *  down_event_callback            : [IN] Is the handler of callback when key/pen down
 *  up_event_callback              : [IN] Is the handler of callback when key/pen up
 *  repeat_event_callback          : [IN] Is the handler of callback when key stays pressed or pen stays on element
 *  normal_painter                 : [IN] Is the painter when element in up state
 *  down_painter                   : [IN] Is the painter when element in down state
 *  focussed_painter               : [IN] Is the painter when element in focussed state
 *  disabled_painter               : [IN] Is the painter when element in disabled state
 *  redraw_bg_after_state_changed  : [IN] Whether to redraw panel background when state of pressed/released/focussed/unfocussed change or not
 * RETURNS
 *  S32
 * RETURN VALUES
 *  S32 : Is the current element count of panel.
 *****************************************************************************/
extern S32 wgui_panel_add_element(
            S32 x,
            S32 y,
            S32 width,
            S32 height,
            U16 keycode,
            FuncPtr down_event_callbac,
            FuncPtr up_event_callback,
            FuncPtr repeat_event_callback,
            gui_util_painter_struct normal_painter,
            gui_util_painter_struct down_painter,
            gui_util_painter_struct focussed_painter,
            gui_util_painter_struct disabled_painter,
            MMI_BOOL redraw_bg_after_state_changed);

/*****************************************************************************
 * <group dom_panel_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_panel_register_keys
 * DESCRIPTION
 *  Register panel's element to corresponding key.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_panel_register_keys(void);

/*****************************************************************************
 * <group dom_panel_gui_layer_property_setting>
 * FUNCTION
 *  wgui_panel_set_element_image_id
 * DESCRIPTION
 *  Set image's ID to one element of panel object. 
 * PARAMETERS
 *  element_index       : [IN] Is the element index to be set image
 *  state               : [IN] Is the state that image to remark
 *  image_id            : [IN] image's ID number
 * RETURNS
 *  void
 * SEE ALSO
 *  You should also need to know gui_panel_elem_state_enum as well
 *****************************************************************************/
extern void wgui_panel_set_element_image_id(
        S32 element_index,
        gui_panel_elem_state_enum state,
        MMI_ID_TYPE image_id);


#endif /* __WGUI_PANEL_H__ */


