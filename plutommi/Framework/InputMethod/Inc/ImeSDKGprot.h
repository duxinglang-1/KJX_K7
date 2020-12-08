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
 *  ImeSDKGprot.h
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *  The header file of IME SDK for external module
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __IMESDKGPROT_H__
#define __IMESDKGPROT_H__

#include "MMI_features.h"
#ifdef __MMI_IME_PLUG_IN__


/*****************************************************************************
 * Includes
 *****************************************************************************/
#include "ImeGprot.h"
#include "Imc.h"
#include "Imui.h"
#include "gui_data_types.h"
#include "mmi_frm_input_gprot.h"
#include "gui_virtual_keyboard_language_type.h"
#include "MMIDataType.h"
#include "IMERes.h"
#include "gui_typedef.h"


/*****************************************************************************
 * Enums
 *****************************************************************************/

/* IME SDK state enums */
typedef enum {
    /* The begin of IME SDK state */
    MMI_IME_SDK_STATE_NONE = 0,
    /* MTK private states, all MTK states will be mapped to it */
    MMI_IME_SDK_STATE_MTK,
    /* Map to MTK initial state */
    MMI_IME_SDK_STATE_INITIAL,
    /* Vendor adds own state below MMI_IME_SDK_STATE_BEGIN */
    MMI_IME_SDK_STATE_BEGIN = MMI_IMC_STATE_CUSTOM_BEGIN,
    /* Vendor adds own state upper MMI_IME_SDK_STATE_END */
    MMI_IME_SDK_STATE_END = MMI_IMC_STATE_CUSTOM_END,
    /* The dummy state */
    MMI_IME_SDK_STATE_MAX
} mmi_ime_sdk_state_enum;


typedef enum {
    /* The begin of IME SDK message */
    MMI_IME_SDK_MSG_NONE = 0,
    
    /* The being of Must handled messages */
    MMI_IME_SDK_MSG_MUST_BEGIN,
    
    /* 
     * Handler should reset its current IME state to initial state.
     *
     * No parameter.
     *
     * MTK IME doesn't check return value.
     */
    MMI_IME_SDK_MSG_RESET = MMI_IME_SDK_MSG_MUST_BEGIN,

    /* 
     * Hardware key event, including qwerty and non-qwerty
     *
     * Param0 [mmi_ime_sdk_key_event_data_struct_p] [IN]: pointer to the key event data 
     * Param1 [mmi_ime_sdk_key_event_special_data_struct_p] [IN]: pointer to the special key event data, 
     *        if it's NULL, means there is not special key event data, the event happened in non-qwerty keypad.
     *
     * If handler returns 0, MTK IME goes on its own process for this key event.
     * If handler returns 1, MTK IME doesn't go on its own process for this key event.
     * If hander returns 1 on one key down event, it should also return 1 on the following key event untill
     * the state returns to initial state
     */
    MMI_IME_SDK_MSG_KEY_EVENT,

    /* 
     * IMUI pen event. Handler should check whether the event happened in vendor's control.
     * If the event is happening on the vendor's control, handler should draw the corresponding
     * UI effect and finish the IME related actions while processing this message, and returns 1.
     *
     * Param0 [mmi_ime_sdk_imui_control_enum] [IN]: IMUI control to check
     * Param1 [mmi_ime_sdk_pen_event_data_struct_p] [IN]: pen event data
     *
     * If handler returns 0, it means the pen event is not handled
     * If handler returns 1, it means the pen event is handled
     */
    MMI_IME_SDK_MSG_IMUI_CONTROL_TRANSLATE_PEN_EVENT,

    /* 
     * This message notify handler that the input mode changed. Vendor should change it context to the
     * latest input mode while processing this message
     * Note: Only context's update would be in the process of this message, don't redraw anything here
     *
     * Param0 [mmi_imm_input_mode_enum] [IN]: Latest input mode 
     * Param1 : not used
     *
     * If handler change its input mode successfully, return 1; else return 0
     */
    MMI_IME_SDK_MSG_CHANGE_INPUT_MODE,

    /* 
     * Notify the handler that adding all own controls into control set.
     * Note: Handler should use the interface of mmi_ime_sdk_is_in_imui_control_set() 
     * and mmi_ime_sdk_add_imui_control() to insert control into control set.
     *
     * No parameter.
     *
     * MTK IME doesn't check return value.
     */
    MMI_IME_SDK_MSG_ADD_ALL_CONTROLS,
    
    /* 
     * Draw all vendor fixed IMUI controls, the fixed control is the control in the buttom of the screen
     *
     * Param0 [U32] [IN]: the visible fixed IMUI control flags, vendor can check it by using 
     *                    (flag & MMI_IME_SDK_IMUI_CONTROL_MASK([mmi_ime_sdk_imui_control_enum])) to get if 
     *                    a certain control is visible
     *                    Note: Handler should filters out the control that is not controlled by vendor(for example: MTK IME
     *                          Virtual Kaypad) and floating controls.
     * Param1 [U32] [IN]: the start bottom y coordinate to draw the controls
     *
     * MTK IME doesn't check return value
     */
    MMI_IME_SDK_MSG_DRAW_CURRENT_FIXED_UI_CONTROLS,

    /* 
     * Clear all vendor fixed IMUI controls that is showing on screen,
     * the fixed control is the control in the buttom of the screen
     *
     * Param0 [U32] [IN]: the visible showing vendor IMUI control flags, vendor can check it by using 
     *                    (flag & MMI_IME_SDK_IMUI_CONTROL_MASK([mmi_ime_sdk_imui_control_enum])) to get if 
     *                    a certain control is showing
     *                    Note: Handler should filters out the control that is not controlled by vendor(for example: MTK IME
     *                          Virtual Kaypad) and floating controls.
     * Param1 : no used
     *
     * MTK IME doesn't check return value
     */
    MMI_IME_SDK_MSG_CLEAR_LAST_FIXED_UI_CONTROLS,
    
    /* 
     * Draw all vendor floating IMUI controls, the floating control is the control floating beside editor cursor
     *
     * Param0 [U32] [IN]: the visible floating IMUI control flags, vendor can check it by using 
     *                    (flag & MMI_IME_SDK_IMUI_CONTROL_MASK([mmi_ime_sdk_imui_control_enum])) to get if 
     *                    a certain control is visible.
     *                    Note: Handler should filters out the control that is not controlled by vendor(for example: MTK IME
     *                          Virtual Kaypad) and fixed controls.
     * Param1 : not used
     *
     * If drawing successful, return 1. else return 0 (the return value doesn't depend on whether there is floating control)
     * Note: If there is not vender's floating control, and the handler process this situation successfully,
     * the return value should be 1 and following handling for message MMI_IME_SDK_MSG_GET_CURRENT_FLOATING_UI_RECT
     * should outputs the rectangle structure with all members filled 0.
     */
    MMI_IME_SDK_MSG_DRAW_CURRENT_FLOATING_UI_CONTROLS,
    
    
    /* 
     * Get the current visible fixed control set of vendor IMUI
     *
     * Param0 [PU32] [OUT]: Param0 is the flag to store the control set of vendor fixed IMUI under current imc state     
     * Param1 : not used
     *
     * If handler returned 0, MTK IME will go on its own process 
     * If handler returned 1, MTK IME doesn't go on its own process
     * 
     */
    MMI_IME_SDK_MSG_GET_CURRENT_FIXED_CONTROL_SET,

    /* 
     * Redraw the required vendor IMUI controls, handler should redraw the required controls on their current
     * position
     *
     * Param0 [U32] [IN]: the required vendor IMUI control flags, handler can check it by using 
     *                    (flag & MMI_IME_SDK_IMUI_CONTROL_MASK([mmi_ime_sdk_imui_control_enum])) to get if 
     *                    a certain control is required to be redrawn
     *                    Note: Handler should filters out the control that is not controlled by vendor(for example: MTK IME
     *                          Virtual Kaypad).
     * Param1 : not used
     *
     * MTK IME doesn't check return value
     */
    MMI_IME_SDK_MSG_REDRAW_UI_CONTROLS,

    /* 
     * Get the total height of the required IMUI controls (including the fixed and floating controls)
     *
     * Param0 [U32] [IN]: the required vendor IMUI control flags, handler can check it by using 
     *                    (flag & MMI_IME_SDK_IMUI_CONTROL_MASK([mmi_ime_sdk_imui_control_enum])) to get if 
     *                    a certain control is required
     *                    Note: Handler should filters out the control that is not controlled by vendor(for example: MTK IME
     *                          Virtual Kaypad).
     * Param1 : not used
     *
     * The return value is total height of the required IMUI controls
     */
    MMI_IME_SDK_MSG_GET_UI_CONTROL_HEIGHT,

    /* 
     * Get the current visible floating control set of vendor IMUI
     *
     * Param0 [U32] [IN]: the current vendor IMUI control flags(including fixed and floating controls),
     *                    handler can check it by using (flag & MMI_IME_SDK_IMUI_CONTROL_MASK([mmi_ime_sdk_imui_control_enum]))
     *                    to get if a certain control is in current control set.
     *                    Note: Handler should filters out the control that is not controlled by vendor(for example: MTK IME
     *                          Virtual Kaypad) and fixed controls.
     * Param1 : not used
     *
     * The return value is control set of vendor floating IMUI, the flag of each control can be made by 
     * MMI_IME_SDK_IMUI_CONTROL_MASK([mmi_ime_sdk_imui_control_enum]).
     * Note: If there is not vender's floating control, returns 0.
     */
    MMI_IME_SDK_MSG_GET_CURRENT_FLOATING_CONTROL_SET,

    /* 
     * Vendor must process this message to configure all UI controls according to current IME state,
     * setting the controls to be visible (through the interface of mmi_ime_sdk_set_visible_control())
     * are required here, because before this message, all visible IMUI controls are hidden.
     *
     * Param0 : not used
     * Param1 : not used
     *
     * If handler returned 0, MTK IME will go on its own process 
     * If handler returned 1, MTK IME doesn't go on its own process 
     */
    MMI_IME_SDK_MSG_CONFIG_UI_CONTROLS_BY_IME_STATE,

    /* 
     * Get current vendor floating UI rectangle
     *
     * Param0 [U32] [IN]: the current vendor IMUI control flags, handler can check it by using 
     *                    (flag & MMI_IME_SDK_IMUI_CONTROL_MASK([mmi_ime_sdk_imui_control_enum])) to get if 
     *                    a certain control is required
     *                    Note: Handler should filters out the control that is not controlled by vendor(for example: MTK IME
     *                          Virtual Kaypad) and fixed controls.
     * Param1 : [mmi_imc_rect_p] [OUT]: pointer to the rectangle structure to be filled
     *
     * MTK IME doesn't check return value
     * Note: If there is not vender's floating control, handler
     * should outputs the rectangle structure with all members filled 0.
     */
    MMI_IME_SDK_MSG_GET_CURRENT_FLOATING_UI_RECT,

    /* 
     * Vendor must process this message to set softkeys according to state (there is not initial state),
     * including setting softkey label, icon and handlers. Vendor must use the IME SDK
     * APIs to set them
     *
     * Param0 [mmi_ime_sdk_state_enum] [IN]: the state which set softkey for
     * Param1 : not used
     *
     * MTK IME doesn't check return value 
     */
    MMI_IME_SDK_MSG_SET_SOFTKEY_BY_STATE,

    /* 
     * Vendor must process this message to redraw softkeys according to state (there is not initial state).
     * Vendor must use the interface of mmi_ime_sdk_show_softkey().
     *
     * Param0 [mmi_ime_sdk_state_enum] [IN]: the state which redraw softkey for
     * Param1 : not used
     *
     * MTK IME doesn't check return value 
     */
    MMI_IME_SDK_MSG_REDRAW_SOFTKEY_BY_STATE,

    MMI_IME_SDK_MSG_MUST_END = MMI_IME_SDK_MSG_REDRAW_SOFTKEY_BY_STATE,
    /* Must handled messages end */

    /* Optional handled messages */
    MMI_IME_SDK_MSG_OPT_BEGIN,
    
    /* 
     * Notify that a editor is connected to IME.
     *
     * No parameter
     *
     * MTK IME doesn't check return value 
     */
    MMI_IME_SDK_MSG_EDITOR_CONNECTED = MMI_IME_SDK_MSG_OPT_BEGIN, 

    /* 
     * Notify that a editor is disconnected from IME.
     *
     * No parameter
     *
     * MTK IME doesn't check return value 
     */
    MMI_IME_SDK_MSG_EDITOR_DISCONNECTING, 
                                         
    /* 
     * Notify that a editor is disconnected from IME.
     *
     * No parameter
     *
     * MTK IME doesn't check return value 
     */
    MMI_IME_SDK_MSG_EDITOR_DISCONNECTED, 

    /* 
     * Notify that IME state is changed
     * Note: when there is state changing, this message always is sent. If the previous state and
     *       current state both are MMI_IME_SDK_STATE_MTK, vendor can ignore it.
     *
     * Param0 [mmi_ime_sdk_state_enum] [IN]: the previous state
     * Param1 [mmi_ime_sdk_state_enum] [IN]: the current state 
     *
     * MTK IME doesn't check return value                            
     */
    MMI_IME_SDK_MSG_STATE_CHANGED,

    /* 
     * Notify that the IMUI background filler is changed
     *
     * Param0 [mmi_imui_draw_back_ground_funcptr] [IN]: the pointer to the background filler
     * Param1: not used
     *
     * MTK IME doesn't check return value                            
     */
    MMI_IME_SDK_MSG_IMUI_BG_FILLER_CHANGED,

    /* 
     * MTK Virtual keyboard event. If a pen event happens in MTK virtual keyboard, there would be a vk event
     *
     * Param0 [mmi_pen_event_type_enum] [IN]: pen event type 
     * Param1 [mmi_ime_sdk_vk_event_data_struct_p] [IN]: vk event data
     *
     * If handler returned 0, it means the vk event is not handled, MTK IME will go on its own process 
     * for this event
     * If handler returned 1, it means the vk event is handled, MTK IME doesn't go on its own process 
     * for this event
     */
    MMI_IME_SDK_MSG_VK_EVENT,

    /* 
     * Notify that the editor cursor is moved.
     *
     * No parameter
     *
     * MTK IME doesn't check return value 
     */
    MMI_IME_SDK_MSG_EDITOR_CURSOR_MOVED,

    /* 
     * Get the invalid Qwerty special key under current condition, Ex. Fn and Shift would be invalid
     * if it's pure number input mode
     * Note: The invlid special key is relative with input mode. There are some default setting for each
     *       input mode. So the return value from the handling of this message is added into default value.
     *       Be able to see the inplementation of mmi_imm_config_special_key_validation() to know the
     *       default invalid special key.
     *
     * Param0 : not used
     * Param1 : not used
     *
     * The return value is the set of special key flags, the flags are defined in mmi_frm_input_gprot.h, 
     * they are MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_XXX
     */
    MMI_IME_SDK_MSG_GET_INVALID_QWERTY_SPECIAL_KEY,

    /* 
     * Get IME indicator size of current input mode
     *
     * Param0 [S32 *] [OUT]: pointer to the width variable
     * Param1 [S32 *] [OUT]: pointer to the height variable
     *
     * If handler returned 0, handler doesn't return a valid size, MTK IME will go on its own process
     * If handler returned 1, handler returns a valid size, MTK IME doesn't go on its own process 
     */
    MMI_IME_SDK_MSG_GET_CURRENT_IME_INDICATOR_SIZE,

    /* 
     * Draw IME indicator in the specified rectangle
     * Note: if vendor handled MMI_IME_SDK_MSG_GET_IME_INDICATOR_SIZE for one input mode, it should 
     *       also handle this message to draw the corresponding indicator
     *
     * Param0 [mmi_imc_rect_p] [IN]: the rectangle to draw the IME indicator
     * Param1 : not used
     *
     * If handler returned 0, handler doesn't draw its indicator, MTK IME will go on its own process 
     * If handler returned 1, handler draw its indicator, MTK IME doesn't go on its own process
     */
    MMI_IME_SDK_MSG_DRAW_CURRENT_IME_INDICATOR,

    /* 
     * Vendor can handle this message to change Qwerty special key status, and replace MTK
     * default special key update policy
     *
     * Param0 [mmi_ime_sdk_key_event_data_struct_p] [IN]: current key event data
     * Param1 [mmi_ime_sdk_special_key_status_struct_p] [OUT]: pointer to the special key status 
     *        structure which would be filled by handler
     *
     * If handler returned 0, handler doesn't want to change the status, MTK will go on its own process 
     * If handler returned 1, handler changes the status, MTK doesn't go on its own process,
     */
    MMI_IME_SDK_MSG_UPDATE_SPECIAL_KEY_STATUS,

    /* 
     * Notify that the Qwerty special key status is changed
     *
     * Param0 [mmi_ime_sdk_special_key_status_struct_p] [IN]: the latest special key status
     * Param1 : not used
     *
     * MTK IME doesn't check return value 
     */
    MMI_IME_SDK_MSG_SPECIAL_KEY_STATUS_CHANGED,

    /* 
     * Notify that vendor should add its own virtual keyboard in mtk state (because the state need vk).
     *
     * Param0 : the flag of vk of vendor in imui set
     * Param1 : not used
     *
     * If handler returned 0, handler wants to show MTK virtual keyborad in mtk state. There is no vendor's virtual keyboard.
     * If handler returned 1, handler doesn't want to show MTK virtual keyborad in mtk state, there is vendor's virtual keyboard or not.
     * Note: the handler adds its own virtual keyboard by mmi_ime_sdk_add_imui_control()
     */
    MMI_IME_SDK_MSG_CONFIG_VK_IN_MTK_STATE,

    /* 
     * Check whether the input mode is added in current allowed input mode list
     *
     * Param0 : the input mode to check
     * Param1 : not used
     *
     * If handler returned 0, handler wants to add this input mode
     * If handler returned 1, handler doesn't want to add this input mode 
     */
    MMI_IME_SDK_MSG_CHECK_INPUT_MODE_AVAILABLE,
    
    /* 
     * MTK Virtual keyboard event. If a pen event happens in MTK virtual keyboard, there would be a vk callback event
     *
     * Param0 [mmi_ime_sdk_vk_event_callback_data_struct] [IN/OUT]: callback event data 
     * Param1 : not used
     *
     * If handler returned 0, it means the vk callback event is not handled, MTK IME will go on its own process 
     * for this event
     * If handler returned 1, it means the vk callback event is handled, MTK IME doesn't go on its own process 
     * for this event
     */
    MMI_IME_SDK_MSG_VK_CALLBACK_EVENT,

    /* 
     * Platform -> Vendor event. Query whether the control is vendor imui control
     *
     * Param0 [VfxControl*] [IN]: pointer of the control 
     * Param1 : not used
     *
     * If handler returned 0, the control is not a vendor imui control. 
     * If handler returned 1, the control is vendor imui control. 
     */
    MMI_IME_SDK_MSG_IS_IMUI_CONTROL,  


    /* 
     * Vendor need to handle this message to do some setting when user choice to  restor 
     * factory setting.
     *
     * Param0 : not used
     * Param1 : not used
     *
     * MTK does not check the return vlaue
     */
    MMI_IME_SDK_MSG_RESTOR_FACTRORY_SETTING,


    /* 
     * Vendor need to handle this message to do something when user click in the
     * editor.
     *
     * Param0 : mmi_ime_sdk_state_enum            [IN]  ime sdk state when pen down
     *                                                            
     *                                                            
     *                                                            
     * Param1 : not used
     *
     * MTK does not check the return vlaue
     */
    MMI_IME_SDK_MSG_PEN_CLICK_IN_EDITOR,
    

    /* 
     * Vendor need to handle this message to do some setting when user changes 
     * VK style.
     *
     * Param0 : mmi_imc_pen_input_style_enum            [IN]      input style to be setted, vlaues:
     *                                                            MMI_IMC_PEN_INPUT_STYLE_VK_QWERTY,
     *                                                            MMI_IMC_PEN_INPUT_STYLE_VK_ALPHANUMERIC,
     *                                                            MMI_IMC_PEN_INPUT_STYLE_HW
     * Param1 : not used
     *
     * MTK does not check the return vlaue
     */
    MMI_IME_SDK_MSG_INPUT_STYLE_CHANGED,       

    MMI_IME_SDK_MSG_OPT_END = MMI_IME_SDK_MSG_INPUT_STYLE_CHANGED,
    /* Optional handled messages end */
    
    MMI_IME_SDK_MSG_MAX
} mmi_ime_sdk_msg_id_enum;


/* IME SDK IMUI control enums */
typedef enum {
    MMI_IME_SDK_IMUI_CONTROL_MTK_VK = MMI_IMUI_VIRTUAL_KEYBOARD, /* map to MTK Virtual Keypad */
    /* 
     * Vendor adds own IMUI control between MMI_IME_SDK_IMUI_CONTROL_BEGIN
     * and MMI_IME_SDK_IMUI_CONTROL_END. There are about 10 positions
     */
    MMI_IME_SDK_IMUI_CONTROL_BEGIN = MMI_IMUI_CUSTOM_CONTROL_BEGIN, 
    MMI_IME_SDK_IMUI_CONTROL_END = MMI_IMUI_CUSTOM_CONTROL_END
} mmi_ime_sdk_imui_control_enum;


/*****************************************************************************
 * Typedef
 *****************************************************************************/
typedef U32 (*mmi_ime_sdk_msg_funcptr)(mmi_ime_sdk_msg_id_enum, U32, U32);
typedef void (*mmi_ime_sdk_setting_funcptr)(mmi_id);

/*****************************************************************************
 * Define
 *****************************************************************************/
#define MMI_IME_SDK_IMUI_CONTROL_MASK(i) MMI_IMUI_CONTROL_MASK(i)


/*****************************************************************************
 * Structs 
 *****************************************************************************/
typedef struct
{
    U16 mmi_key_code;
    U16 mmi_key_type;
}mmi_ime_sdk_key_event_data_struct, *mmi_ime_sdk_key_event_data_struct_p;

typedef struct
{
    UI_character_type ucs2_code;
    U32 special_key_flag;
}mmi_ime_sdk_key_event_special_data_struct, *mmi_ime_sdk_key_event_special_data_struct_p;

typedef struct
{
    /* The flags defined in mmi_frm_input_gprot.h, they are MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_XXX */
    U32 special_key_flag;
    U32 special_key_lock_flags;
}mmi_ime_sdk_special_key_status_struct, *mmi_ime_sdk_special_key_status_struct_p;


#if defined(__MMI_TOUCH_SCREEN__)
typedef struct
{
    mmi_pen_event_type_enum event_type;
    mmi_pen_point_struct pos;
}mmi_ime_sdk_pen_event_data_struct, *mmi_ime_sdk_pen_event_data_struct_p;
#endif

#if defined(__MMI_VIRTUAL_KEYBOARD__)
typedef struct
{
    UI_character_type character;
    gui_virtual_keyboard_pen_enum vk_event;
}mmi_ime_sdk_vk_event_data_struct, *mmi_ime_sdk_vk_event_data_struct_p;

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
typedef struct
{
    gui_virtual_keyboard_pen_enum vk_event;
    S32 key_param;
    U32 *ret_ptr;
    gui_virtual_keyboard_event_enum *ret_val_ptr;
}mmi_ime_sdk_vk_event_callback_data_struct, *mmi_ime_sdk_vk_event_callback_data_struct_p;
#endif
#endif


/*****************************************************************************
 * Functions
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_register_msg_callback
 * DESCRIPTION
 *  Register the sdk message callback function, user should implement its own
 *  message callback function and register to IME sdk layer through this 
 *  function
 * PARAMETERS
 *  msg_cb     :   [IN]    Pointer to the sdk message callback function to be
 *                         registered
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_register_msg_callback(mmi_ime_sdk_msg_funcptr msg_cb);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_unregister_msg_callback
 * DESCRIPTION
 *  Unregister the sdk message callback function
 * PARAMETERS
 *  msg_cb     :   [IN]    Pointer to the sdk message callback function to be 
 *                         unregistered
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_unregister_msg_callback(mmi_ime_sdk_msg_funcptr msg_cb);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_set_state
 * DESCRIPTION
 *  Set ime state, the state must be in the range of mmi_ime_sdk_state_enum
 * PARAMETERS
 *  state     :   [IN]    The state to be set
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_set_state(mmi_ime_sdk_state_enum state);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_get_state
 * DESCRIPTION
 *  Get the current IME state, if it's MTK IME state, it returns 
 *  MMI_IME_SDK_STATE_MTK
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_ime_sdk_state_enum
 * RETURN VALUES
 *  The current IME state
 *****************************************************************************/
extern mmi_ime_sdk_state_enum mmi_ime_sdk_get_state(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_redraw_screen_by_state
 * DESCRIPTION
 *  Redraw the screen according to current IME state
 * PARAMETERS
 *  void 
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  If it redraws successfully
 *****************************************************************************/
extern MMI_BOOL mmi_ime_sdk_redraw_screen_by_state(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_send_editor_msg
 * DESCRIPTION
 *  Send message to the editor callback function, IME use this way to 
 *  communicate with editor and category. The message ID is from 
 *  mmi_imc_editor_message_id_enum which is defined in ImeGprot.h
 * PARAMETERS
 *  msg_ptr   :  [IN]  The pointer to the message struct
 * RETURNS
 *  U32 
 * RETURN VALUES
 *  The return value of the specified message
 *****************************************************************************/
extern U32 mmi_ime_sdk_send_editor_msg(mmi_imc_message_struct_p msg_ptr);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_set_current_input_mode
 * DESCRIPTION
 *  Set the current input mode as the specified mode, this function only update
 *  the global variable of current input mode, if want the IME context change
 *  to one input mode, should call mmi_ime_sdk_change_input_mode().
 * PARAMETERS
 *  mode    :  [IN]  The input mode to be set
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE    :    It's set succesfully
 *  MMI_FALSE   :    Faild to set the input mode
 *****************************************************************************/
extern MMI_BOOL mmi_ime_sdk_set_current_input_mode(mmi_imm_input_mode_enum mode);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_change_input_mode
 * DESCRIPTION
 *  Change the input mode to the specified mode, this function doesn't update
 *  the global variable of current input mode, if want to update it, should
 *  call mmi_ime_sdk_set_current_input_mode()
 * PARAMETERS
 *  mode    :    [IN]   The input mode to be changed to 
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE    :    It's changed succesfully
 *  MMI_FALSE   :    Faild to change the input mode
 *****************************************************************************/
extern MMI_BOOL mmi_ime_sdk_change_input_mode(mmi_imm_input_mode_enum mode);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_get_next_input_mode
 * DESCRIPTION
 *  Get the next input mode according to current mode change policy, this 
 *  function will change the global variable of current input mode to the
 *  next input mode. If want the IME context change to one input mode, 
 *  should call mmi_ime_sdk_change_input_mode().
 * PARAMETERS
 *  void 
 * RETURNS
 *  mmi_imm_input_mode_enum
 * RETURN VALUES
 *  The next input mode
 *****************************************************************************/
extern mmi_imm_input_mode_enum mmi_ime_sdk_get_next_input_mode(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_get_current_input_mode
 * DESCRIPTION
 *  Get current input mode
 * PARAMETERS
 *  void 
 * RETURNS
 *  mmi_imm_input_mode_enum
 * RETURN VALUES
 *  The current input mode
 *****************************************************************************/
extern mmi_imm_input_mode_enum mmi_ime_sdk_get_current_input_mode(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_get_input_mode_array_item
 * DESCRIPTION
 *  Get the input mode detail information
 * PARAMETERS
 *  mode    :   [IN]    The input mode to get
 * RETURNS
 *  const sIMEModeDetails *
 * RETURN VALUES
 *  The pointer to the input mode detail information of the specified 
 *  input mode
 *****************************************************************************/
extern const sIMEModeDetails * mmi_ime_sdk_get_input_mode_array_item(mmi_imm_input_mode_enum mode);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_get_current_allowed_input_mode_list
 * DESCRIPTION
 *  Get the current allowed input mode list
 * PARAMETERS
 *  mode_array    :   [OUT]    where The current allowed input mode list to place
 *  max           :   [IN]     the size of mode_array  
 * RETURNS
 *  S32
 * RETURN VALUES
 *  the num of current allowed input mode in mode_array
 *****************************************************************************/
extern S32 mmi_ime_sdk_get_current_allowed_input_mode_list(mmi_imm_input_mode_enum *mode_array, S32 max);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_get_current_allowed_input_mode_num
 * DESCRIPTION
 *  Get the number of current allowed input mode
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 * RETURN VALUES
 *  The number of current allowed input mode
 *****************************************************************************/
extern S32 mmi_ime_sdk_get_current_allowed_input_mode_num(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_get_current_input_type
 * DESCRIPTION
 *  Get the current input type, the input types are defined in ImeGprot.h
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_imm_input_type_enum
 * RETURN VALUES
 *  The current input type
 *****************************************************************************/
extern mmi_imm_input_type_enum mmi_ime_sdk_get_current_input_type(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_is_symbol_picker_disabled
 * DESCRIPTION
 *  Get if the symbol picker screen is disabled or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE    :    The symbol picker screen is disabled
 *  MMI_FALSE   :    The symbol picker screen is enabled
 *****************************************************************************/
extern MMI_BOOL mmi_ime_sdk_is_symbol_picker_disabled(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_is_valid_string
 * DESCRIPTION
 *  Check if there is invalid character in a string
 * PARAMETERS
 *  string    :   [IN]    The pointer to the string to be checked
 *  length    :   [IN]    The length to be checked
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE    :    There is not invalid character
 *  MMI_FALSE   :    There is invalid character
 *****************************************************************************/
extern MMI_BOOL mmi_ime_sdk_is_valid_string(UI_string_type string, S32 length);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_is_auto_completion_enabled
 * DESCRIPTION
 *  Check if auto-completion feature is enabled in this editor
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE    :    Auto-completion is enabled
 *  MMI_FALSE   :    Auto-completion isn't enabled
 *****************************************************************************/
extern MMI_BOOL mmi_ime_sdk_is_auto_completion_enabled(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_is_auto_capitalization_enabled
 * DESCRIPTION
 *  Check if auto-capitalization feature is enabled in this editor
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE    :    Auto-capitalization is enabled
 *  MMI_FALSE   :    Auto-capitalization isn't enabled
 *****************************************************************************/
extern MMI_BOOL mmi_ime_sdk_is_auto_capitalization_enabled(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_is_chinese_next_word_prediction_enabled
 * DESCRIPTION
 *  Check if Chinese next word prediction feature is enabled in this editor
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE    :    Chinese next word prediction is enabled
 *  MMI_FALSE   :    Chinese next word prediction isn't enabled
 *****************************************************************************/
extern MMI_BOOL mmi_ime_sdk_is_chinese_next_word_prediction_enabled(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_is_alphabetic_next_word_prediction_enabled
 * DESCRIPTION
 *  Check if alphabetic next word prediction feature is enabled in this editor
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE    :    Alphabetic next word prediction is enabled
 *  MMI_FALSE   :    Alphabetic next word prediction isn't enabled
 *****************************************************************************/
extern MMI_BOOL mmi_ime_sdk_is_alphabetic_next_word_prediction_enabled(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_entry_symbol_picker_screen
 * DESCRIPTION
 *  Entry the symbol picker screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_entry_symbol_picker_screen(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_set_softkey_label_in_ime_state
 * DESCRIPTION
 *  Set the softkey label when it's in ime state
 *  VENUS does not have softkey, call this api will do nothing in venus.
 * PARAMETERS
 *  s    :    [IN]  The string pointer to of the label
 *  key  :    [IN]  The softkey to change label
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_set_softkey_label_in_ime_state(UI_string_type s, WGUI_SOFTKEY_ENUM key);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_set_softkey_icon_in_ime_state
 * DESCRIPTION
 *  Set the softkey icon when it's in ime state
 *  VENUS does not have softkey, call this api will do nothing in venus.
 * PARAMETERS
 *  icon :    [IN]  The image pointer to of the icon
 *  key  :    [IN]  The softkey to change icon
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_set_softkey_icon_in_ime_state(PU8 icon, WGUI_SOFTKEY_ENUM key);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_set_softkey_function
 * DESCRIPTION
 *  Set the softkey function. (Softkey function will be called by Gui after Gui showes the effect)
 *  Venus does not have softkey, this funciton only support invisible softkey in some special project.
 * PARAMETERS
 *  f           : [IN]        softkey function pointer to be set
 *  k           : [IN]        key event type for which softkey function is called
 *  key         : [IN]        Softkey for which softkey function is called
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_set_softkey_function(void (*f) (void), MMI_key_event_type k, WGUI_SOFTKEY_ENUM key);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_clear_softkey_handler
 * DESCRIPTION
 *  clear the softkey handler (Softkey handler will be called by framework when the user operates softkey)
 *  VENUS does not have softkey, called this api will do nothing in venus
 * PARAMETERS
 *  key         : [IN] The softkey to clear handler
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_clear_softkey_handler(WGUI_SOFTKEY_ENUM key);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_show_softkey
 * DESCRIPTION
 *  show the softkey
 *  VENUS does not have softkey, call this API will do nothing in venus
 * PARAMETERS
 *  key         : [IN] The softkey to show
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_show_softkey(WGUI_SOFTKEY_ENUM key);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_register_softkey_handler
 * DESCRIPTION
 *  register the default gui softkey handler (In the handler, Gui will call softkey function)
 *  VENUS does not have softkey, call this api will do nothing in venus
 * PARAMETERS
 *  key         : [IN] The softkey to register
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_register_softkey_handler(WGUI_SOFTKEY_ENUM key);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_set_key_handler
 * DESCRIPTION
 *  Set the key handler. If want to clear key handler, don't use this interface
 * PARAMETERS
 *  funcPtr     :[IN] Function to be executed on occurrence of the event.
 *  keyCode     :[IN] Key to which this event is associated.
 *  keyType     :[IN] The key event type
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_set_key_handler(FuncPtr funcPtr, U16 keyCode, U16 keyType);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_get_key_handler
 * DESCRIPTION
 *  Get the key handler
 * PARAMETERS
 *  keyCode     :[IN] the key to get handler
 *  keyType     :[IN] The key event type
 * RETURNS
 *  FuncPtr
 * RETURN VALUES
 *  The key handler registered 
 *****************************************************************************/
extern FuncPtr mmi_ime_sdk_get_key_handler(U16 keyCode, U16 keyType);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_clear_key_handler
 * DESCRIPTION
 *  Clear the key handler
 * PARAMETERS
 *  keyCode     :[IN] the key to clear handler
 *  keyType     :[IN] The key event type
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_clear_key_handler(U16 keyCode, U16 keyType);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_get_ime_theme
 * DESCRIPTION
 *  Get the current IME theme data
 * PARAMETERS
 *  void
 * RETURNS
 *  UI_ime_theme *
 * RETURN VALUES
 *  The pointer to the current IME theme data
 *****************************************************************************/
extern UI_ime_theme *mmi_ime_sdk_get_ime_theme(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_is_small_screen_editor
 * DESCRIPTION
 *  Get if the connected editor is small screen or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE    :    The connected editor is small screen editor
 *  MMI_FALSE   :    The connected editor is not small screen editor
 *****************************************************************************/
extern MMI_BOOL mmi_ime_sdk_is_small_screen_editor(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_config_auto_capitalization
 * DESCRIPTION
 *  Configure MTK auto-capitalization feature validation
 * PARAMETERS
 *  is_enabled  : [IN] If auto-capitalization is enabled
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_config_auto_capitalization(MMI_BOOL is_enabled);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_config_chinese_word_prediction_by_pen
 * DESCRIPTION
 *  Configure MTK Chinese word prediction feature, the feature is that, when
 *  user touch in editor after an Chinese character, waite a moment, there 
 *  would be the associated Chinese words of that character in the candidate box
 * PARAMETERS
 *  is_enabled  : [IN] If MTK Chinese word prediction feature is enabled
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_config_chinese_word_prediction_by_pen(MMI_BOOL is_enabled);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_add_imui_control
 * DESCRIPTION
 *  Add a imui control to control set, this API doesn't check if this control
 *  is already in the control set, it always add the control to the end of 
 *  the control set
 * PARAMETERS
 *  imui_control    :    [IN]    The control to be added
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_add_imui_control(mmi_ime_sdk_imui_control_enum imui_control);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_is_in_imui_control_set
 * DESCRIPTION
 *  Check if the control is in IMUI control set
 * PARAMETERS
 *  imui_control    :    [IN]    The control to be checked
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE    :    It's in IMUI control set
 *  MMI_FALSE   :    It's not in IMUI control set
 *****************************************************************************/
extern MMI_BOOL mmi_ime_sdk_is_in_imui_control_set(mmi_ime_sdk_imui_control_enum imui_control);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_set_visible_control
 * DESCRIPTION
 *  Set a IMUI control is visalbe
 * PARAMETERS
 *  imui_control    :    [IN]    The control to be set
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_set_visible_control(mmi_ime_sdk_imui_control_enum imui_control);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_set_hidden_control
 * DESCRIPTION
 *  Set a IMUI control is hidden
 * PARAMETERS
 *  imui_control    :    [IN]    The control to be set
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_set_hidden_control(mmi_ime_sdk_imui_control_enum imui_control);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_hide_all_controls
 * DESCRIPTION
 *  Set all IMUI controls are hidden
 * PARAMETERS
 *  void
 * RETURNS
 *  viod
 *****************************************************************************/
extern void mmi_ime_sdk_hide_all_controls(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_is_visible_control
 * DESCRIPTION
 *  Check if the control should be shown, when user want to redraw the IMUI
 *  controls, he can use the function to get if one control should be redrawn
 * PARAMETERS
 *  imui_control    :    [IN]    The control to be checked
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE    :    It's current visible control
 *  MMI_FALSE   :    It's not current visible control
 *****************************************************************************/
extern MMI_BOOL mmi_ime_sdk_is_visible_control(mmi_ime_sdk_imui_control_enum imui_control);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_is_previous_visible_control
 * DESCRIPTION
 *  Check if the control was shown in the previous redraw process, when user 
 *  wants to redraw the IMUI controls, he can use the function to get if one
 *  control is shown in the previous redraw process, maybe it needs to clear 
 *  previous region which is covered by this control
 * PARAMETERS
 *  imui_control    :    [IN]    The control to be checked
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE    :    It's previous visible control
 *  MMI_FALSE   :    It's not previous visible control
 *****************************************************************************/
extern MMI_BOOL mmi_ime_sdk_is_previous_visible_control(mmi_ime_sdk_imui_control_enum imui_control);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_is_previous_visible_floating_control
 * DESCRIPTION
 *  Check if the control was shown in the previous redraw process, and this
 *  control is floating
 * PARAMETERS
 *  imui_control    :    [IN]    The control to be checked
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE    :    It's previous visible floating control
 *  MMI_FALSE   :    It's not previous visible floating control
 *****************************************************************************/
extern MMI_BOOL mmi_ime_sdk_is_previous_visible_floating_control(mmi_ime_sdk_imui_control_enum imui_control);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_get_imui_param
 * DESCRIPTION
 *  Get the IMUI coordinates parameters, such as IMUI start x, buttom y 
 *  coordinates, they are reference coordinates to show the IMUI controls
 *  Call this API in venus will return 0 directly.
 * PARAMETERS
 *  imui_control    :    [OUT]    Pointer to the IMUI parameter structure 
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_get_imui_param(mmi_imui_param_struct *param);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_redraw_imui_background
 * DESCRIPTION
 *  Redraw IMUI background using MTK IMUI background filler, because App or
 *  category would change the background filler. Vendor can also get the
 *  changed background filler by lisen to MMI_IME_SDK_MSG_IMUI_BG_FILLER_CHANGED
 *  the default background filler is transparent color
 * PARAMETERS
 *  x1    :    [IN]    x coordinate of the left-top of the area  
 *  y1    :    [IN]    y coordinate of the left-top of the area
 *  x2    :    [IN]    x coordinate of the right-bottom of the area
 *  y2    :    [IN]    y coordinate of the right-bottom of the area
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_redraw_imui_background(S32 x1, S32 y1, S32 x2, S32 y2);

#if defined(__MMI_VIRTUAL_KEYBOARD__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_set_virtual_keyboard
 * DESCRIPTION
 *  Set the virtual keyboard type 
 * PARAMETERS
 *  vk_type    :    [IN]    VK type
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_set_virtual_keyboard_type(gui_virtual_keyboard_language_enum vk_type);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_get_virtual_keyboard_type
 * DESCRIPTION
 *  Get the virtual keyboard type 
 * PARAMETERS
 *  void
 * RETURNS
 *  gui_virtual_keyboard_language_enum
 * RETURN VALUES
 *  Virtual keyboard type enum
 *****************************************************************************/
extern gui_virtual_keyboard_language_enum mmi_ime_sdk_get_virtual_keyboard_type(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_get_virtual_keyboard_area_height
 * DESCRIPTION
 *  Get the virtual keyboard area height 
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 * RETURN VALUES
 *  Virtual keyboard area height
 *****************************************************************************/
extern S32 mmi_ime_sdk_get_virtual_keyboard_area_height(void);

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_set_virtual_keyboard_style
 * DESCRIPTION
 *  Set virtual keyboard style of VK-V2
 * PARAMETERS
 *  vk_style    [IN]    The virtual keyboard style value, MMI_VK_TYPE_QWERTY
 *                      or MMI_VK_TYPE_ALPHANUMERIC
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_set_virtual_keyboard_style(U32 vk_style);

#endif /* defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) */
#endif /* defined(__MMI_VIRTUAL_KEYBOARD__) */

#if defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_is_virtual_keyboard_disabled
 * DESCRIPTION
 *  Get if virtual keybaord is disabled in the current editor
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_FALSE : Virtual keyboard is not disabled
 *  MMI_TRUE  : Virtual keyboard is disabled
 *****************************************************************************/
extern MMI_BOOL mmi_ime_sdk_is_virtual_keyboard_disabled(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_is_virtual_keyboard_hidden
 * DESCRIPTION
 *  Get if the virtual keyboard is hidden currently, in FTE, if user uses 
 *  hardware key to input, virtual keyboard should be hidden
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_FALSE : Virtual keyboard is not hidden
 *  MMI_TRUE  : Virtual keyboard is hidden
 *****************************************************************************/
extern MMI_BOOL mmi_ime_sdk_is_virtual_keyboard_hidden(void);

#endif /* defined(__MMI_TOUCH_SCREEN__) */

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_print_string_inserted_to_editor
 * DESCRIPTION
 *  Print the inserted string, it's for auto-test and trace
 * PARAMETERS
 *  str_ptr    :    [IN]    The string to be print
 *  str_len    :    [IN]    The length of the string to be print
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_print_string_inserted_to_editor(UI_string_type str_ptr, S32 str_len);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_get_curr_allow_input_mode_list_of_curr_writing_lang
 * DESCRIPTION
 *  To get the supporting input mode list of current writing language.
 * PARAMETERS
 *  mode_array    :   [OUT]    where The current allowed input mode list to place
 *  max           :   [IN]     the size of mode_array  
 * RETURNS
 *  S32
 * RETURN VALUES
 *  the num of current allowed input mode in mode_array
 *****************************************************************************/
extern S32 mmi_ime_sdk_get_curr_allow_input_mode_list_of_curr_writing_lang(mmi_imm_input_mode_enum *mode_array, S32 max);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_get_current_allowed_writing_language_num
 * DESCRIPTION
 *  Get the number of current allowed writing language
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 * RETURN VALUES
 *  The number of current allowed writing language
 *****************************************************************************/
extern S32 mmi_ime_sdk_get_current_allowed_writing_language_num(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_is_change_language_disabled
 * DESCRIPTION
 *  Get if the vendor can't change language
 *  Call this api in venus will always return false
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE    :    The vendor can't change language
 *  MMI_FALSE   :    The vendor can change language
 *****************************************************************************/
MMI_BOOL mmi_ime_sdk_is_change_language_disabled(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_entry_change_language_screen
 * DESCRIPTION
 *  Entry the change language screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_sdk_entry_change_language_screen(void);

#ifdef __MMI_IME_PLUG_IN_SETTING__
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_register_setting_callback
 * DESCRIPTION
 *  Register the sdk setting callback function, user should implement its own
 *  setting function and register to IME sdk layer through this 
 *  function
 * PARAMETERS
 *  setting_cb     :   [IN]    Pointer to the sdk setting callback function to be
 *                             registered
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_register_setting_callback(mmi_ime_sdk_setting_funcptr setting_cb);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_call_setting_cb
 * DESCRIPTION
 *  This function call the setting callback function registered by vendor
 * PARAMETERS
 *  parent_gid      :   [IN]    parent group id
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_call_setting_cb(mmi_id parent_gid);

#endif


/* Cstar requires new APIS  */

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_check_ui_style
 * DESCRIPTION
 *  To check if the specific UI style is enabled or not 
 * PARAMETERS
 *  style_flag     :   [IN]    style flag to be checked, MMI_IMC_UI_STYLE_FLOAT_ON 
 *                             or MMI_IMC_UI_STYLE_VK_ON
 * RETURNS
 *  MMI_TRUE       :           The UI style to be checked is enabled      
 *  MMI_FALSE      :           The UI style to be checked is disabled
 *****************************************************************************/
extern MMI_BOOL mmi_ime_sdk_check_ui_style(U32 style_flag);


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_config_ui_style
 * DESCRIPTION
 *  To config specific UI style to be enable or not
 *   
 * PARAMETERS
 *  ui_style     :   [IN]    ui style to be configed, MMI_IMC_UI_STYLE_FLOAT_ON 
 *                           or MMI_IMC_UI_STYLE_VK_ON
 *  is_on        :   [IN]    if the UI style enable or not
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_config_ui_style(U32 ui_style, MMI_BOOL is_on);



/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_is_ime_connected
 * DESCRIPTION
 *  To checks if the ime is connected or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE    :       IME is connected        
 *  MMI_FALSE   :       IME is not connected
 *****************************************************************************/
extern MMI_BOOL mmi_ime_sdk_is_ime_connected(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_get_keyboard_type
 * DESCRIPTION
 *  To get the keyboard type, IMM_KEYPAD_ALPHANUMERIC,IMM_KEYPAD_QWERTY or
 *  IMM_KEYPAD_HANDWRITING,
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_imm_keypadtype_enum
 * RETURN VALUES
 *  keypad type enum
 *****************************************************************************/
extern mmi_imm_keypadtype_enum mmi_ime_sdk_get_keyboard_type(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_set_curr_input_style
 * DESCRIPTION
 *  To set current input style, 
 * PARAMETERS
 *  input_style    :   [IN]     input style to be set,
 *                              MMI_IMC_PEN_INPUT_STYLE_NONE(noly key input)
 *                              MMI_IMC_PEN_INPUT_STYLE_VK_QWERTY,		
 *                              MMI_IMC_PEN_INPUT_STYLE_VK_ALPHANUMERIC,
 *                              MMI_IMC_PEN_INPUT_STYLE_HW,
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_set_curr_input_style(mmi_imc_pen_input_style_enum input_style);


#if !defined(__NO_HANDWRITING__)

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_enable_single_block_hw
 * DESCRIPTION
 *  To enable single block handwriting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_enable_single_block_hw(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_stop_single_block_handwriting
 * DESCRIPTION
 *  To stop single block handwriting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 extern void mmi_ime_sdk_stop_single_block_handwriting(void);

#endif  /* !defined(__NO_HANDWRITING__)*/



/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_is_handwriting_disabled
 * DESCRIPTION
 *  To check if the handwriting is disabled
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE    :   handwriting is disabled
 *  MMI_FALSE   :   handwriting is enabled
 *****************************************************************************/
extern MMI_BOOL mmi_ime_sdk_is_handwriting_disabled(void);



/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_cancel_timer
 * DESCRIPTION
 *  To cancel timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_cancel_timer(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_confirm_handwriting_selection
 * DESCRIPTION
 *  To confirm handwriting selection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_confirm_handwriting_selection(void);



/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_get_candidate_case_before_cursor
 * DESCRIPTION
 *  To get the capital state of candidate before cursor
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_ime_word_capital_state_enum
 * RETURNS VALUES
 *  word capital state enum
 *****************************************************************************/
extern mmi_ime_word_capital_state_enum mmi_ime_sdk_get_candidate_case_before_cursor(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_redraw_ime_indicator
 * DESCRIPTION
 *  Redraw IME indicator, including information bar, input mode hint and IME
 *  indicator on status icon bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_redraw_ime_indicator(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_select_candidate_from_candidate_box
 * DESCRIPTION
 *  To select candidate from candidate box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_select_candidate_from_candidate_box(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_common_arrow_key_handler
 * DESCRIPTION
 *  Only for change highlight index in the same page.
 * PARAMETERS
 *  key_code        :       the custom key code value       
 *  event_type      :       the current key event type
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_common_arrow_key_handler(mmi_imc_key_custom_value key_code, U16 event_type);


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_change_input_mode_according_to_capital_state
 * DESCRIPTION
 *  Only for change highlight index in the same page.
 * PARAMETERS
 *  capital_state       :       The current capital state, values may be MMI_IME_WORD_CAPITAL_STATE_LOWER,
 *                              MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER or MMI_IME_WORD_CAPITAL_STATE_UPPER,
 * RETURNS
 *  MMI_TRUE            :       Change the input mode sucessfully
 *  MMI_FALSE           :       Failed to change input mode
 *****************************************************************************/

extern MMI_BOOL mmi_ime_sdk_change_input_mode_according_to_capital_state(mmi_ime_word_capital_state_enum capital_state);



/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_default_key_down
 * DESCRIPTION
 *  need to be discussed
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_default_key_down();


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_default_key_long
 * DESCRIPTION
 *  need to be discussed
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_default_key_long();


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_default_key_up
 * DESCRIPTION
 *  need to be discussed
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_default_key_up();

 

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_get_curr_capital_state
 * DESCRIPTION
 *  To get the current capital state of IME,need to include imeGport.h
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_ime_word_capital_state_enum         :       capital state enum
 *****************************************************************************/
extern mmi_ime_word_capital_state_enum mmi_ime_sdk_get_curr_capital_state(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_set_curr_capital_state
 * DESCRIPTION
 *  To config the current capital state of IME
 * PARAMETERS
 *  mmi_ime_word_capital_state_enum      :      the capital state enum,
 *                                              MMI_IME_WORD_CAPITAL_STATE_NONE,
 *                                              MMI_IME_WORD_CAPITAL_STATE_LOWER,
 *                                              MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER,
 *                                              MMI_IME_WORD_CAPITAL_STATE_UPPER,
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_set_curr_capital_state(mmi_ime_word_capital_state_enum capital_state);



#if defined(__MMI_IME_AUTO_CAPITALIZATION__)

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_is_capital_lock_enable
 * DESCRIPTION
 *  To check if the capital lock is enabled
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE        :       Capital lock is enabled
 *  MMI_FALSE       :       Capital lock is disabled
 *****************************************************************************/
extern MMI_BOOL mmi_ime_sdk_is_capital_lock_enable(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_config_capital_lock
 * DESCRIPTION
 *  To config the capital lock
 * PARAMETERS
 *  isenable        :       the capital lock enable or disable, MMI_TRUE or MMI_FALSE
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ime_sdk_config_capital_lock_enable(MMI_BOOL isenable);

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_is_in_venus_ui_engine_state
 * DESCRIPTION
 *  To check if it is in venus ui engine state
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/

extern MMI_BOOL mmi_ime_sdk_is_in_venus_ui_engine_state(void);


#endif  /*defined(__MMI_IME_AUTO_CAPITALIZATION__)*/


#endif /* __MMI_IME_PLUG_IN__ */
#endif /* __IMESDKGPROT_H__ */


