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
 *  wgui..c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  key_handlers wrappers and initialize UI..
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 */

/**********************************************************************************
   Filename:      wgui.c
   Author:        manju
   Date Created:  August-07-2002
   Contains:      PixTel UI wrapper routines
               Contains several parts and has been split to multiple
               code files. See other files named wgui_*.c and wgui_*.h
               This file contains common functions and data.
**********************************************************************************/
#include "MMI_features.h"
/* Include: MMI header file */
#include "wgui_virtual_keyboard.h"
#include "mmi_frm_prot.h"
#if(!UI_DISABLE_EMS_INPUT_BOX)
#endif 

#include "CustVenusThemeRes.h"

#include "wgui_softkeys.h"
#include "gui_config.h"
#include "MMIDataType.h"
#include "wgui.h"
#include "kal_general_types.h"
#include "CustThemesRes.h"
#include "gui_data_types.h"
#include "gui_typedef.h"
#include "wgui_include.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_input_gprot.h"
#include "GlobalConstants.h"
#include "gui_themes.h"
#include "gui_ems.h"
#include "wgui_fixed_menus.h"
#include "gui.h"
#include "wgui_inputs.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "wgui_categories_list.h"
#include "wgui_draw_manager.h"
#include "wgui_draw_manager_int.h"
#include "gui_effect_oem.h"
#include "wgui_categories_util.h"
#include "gdi_include.h"
#include "wgui_touch_screen.h"
#include "TouchScreenGprot_Int.h"
#include "ImeGprot.h"
#include "mmi_rp_app_uiframework_def.h"
#include "mmi_frm_timer_gprot.h"
#include "gui_fixed_menuitems.h"
#include "gui_windows.h"
#include "ScreenRotationGprot.h"
#include "CustDataRes.h"
#include "mmi_frm_mem_gprot.h"
#include "BootupSrvGprot.h"
#include "GlobalDefs.h"


#include "gdi_image_9slice.h"

#ifdef __MMI_VUI_ENGINE__
#include "vrt_canvas.h"

//extern void vrt_canvas_suspend();
#endif    
#ifndef __MTK_TARGET__ 
//#include "mte.h"
extern void mmi_mte_mmi_notify_new_screen(void);
#endif   
#ifdef __MMI_LCM_PRIMITIVE_FLUSH__
extern void mmi_frm_screen_set_sse_backup(MMI_BOOL isOn);
#endif
/* 
 * Local Variable
 */
static void (*MMI_keyboard_key_handler) (S32 vkey_code, S32 key_state) = NULL;
static void (*MMI_keyboard_input_handler) (S32 vkey_code) = NULL;
static void (*MMI_keyboard_global_key_handler) (S32 vkey_code, S32 key_state) = NULL;
static void (*MMI_keyboard_global_input_handler) (S32 vkey_code) = NULL;
static void (*MMI_key_input_handler_function) (MMI_key_code_type key_code, MMI_key_event_type key_event);
static void (*MMI_key_down_handler_function) (MMI_key_code_type key_code);
static void (*MMI_key_up_handler_function) (MMI_key_code_type key_code);

/* 
 * Global Variable
 */
S32 MMI_status_bar_height;
S32 MMI_content_x;
S32 MMI_content_y;
S32 MMI_content_width;
S32 MMI_content_height;
static MMI_BOOL g_mmi_is_in_ui_common_exit = MMI_FALSE;
extern MMI_theme **MMI_themes;
extern void mmi_frm_screen_set_sse_backup(MMI_BOOL isOn);
extern void mmi_frm_touch_screen_switch_action(void);

/* 
 * Global Function
 */

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_is_in_ui_common_exit_procedure
 * DESCRIPTION
 *  This function is used to judge if in UI_common_screen_exit
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if in UI_common_screen_ext
 *****************************************************************************/
MMI_BOOL mmi_frm_is_in_ui_common_exit_procedure(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_is_in_ui_common_exit;
}


/*****************************************************************************
 * FUNCTION
 *  MMI_dummy_function
 * DESCRIPTION
 *  Dummy function used in MMI
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMI_dummy_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

/* Functions for keyboard Support   */


/*****************************************************************************
 * FUNCTION
 *  dummy_keyboard_key_handler
 * DESCRIPTION
 *  Dummy keyboard key handler
 * PARAMETERS
 *  vkey_code       [IN]        Key_code
 *  key_state       [IN]        Key_state
 * RETURNS
 *  void
 *****************************************************************************/
void dummy_keyboard_key_handler(S32 vkey_code, S32 key_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(vkey_code);
    UI_UNUSED_PARAMETER(key_state);
}


/*****************************************************************************
 * FUNCTION
 *  dummy_keyboard_input_handler
 * DESCRIPTION
 *  Dummy keyboard input handler
 * PARAMETERS
 *  vkey_code       [IN]        Key_code
 * RETURNS
 *  void
 *****************************************************************************/
void dummy_keyboard_input_handler(S32 vkey_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(vkey_code);
}


/*****************************************************************************
 * FUNCTION
 *  keyboard_key_handler
 * DESCRIPTION
 *  Handles key events (UP/DOWN)
 * PARAMETERS
 *  vkey_code       [IN]        Key's scan code
 *  key_state       [IN]        Key's state (up or down)
 * RETURNS
 *  void
 *****************************************************************************/
void keyboard_key_handler(S32 vkey_code, S32 key_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 state = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Perform scan code and key state mapping here */
    if (key_state == KEYBOARD_KEY_DOWN)
    {
        state = 1;
    }
    else if (key_state == KEYBOARD_KEY_UP)
    {
        state = 0;
    }
    if (MMI_keyboard_key_handler != NULL)
    {
        MMI_keyboard_key_handler(vkey_code, state);
    }
}


/*****************************************************************************
 * FUNCTION
 *  keyboard_input_handler
 * DESCRIPTION
 *  Handles keyboard input
 * PARAMETERS
 *  vkey_code       [IN]        Key's character code (ASCII)
 * RETURNS
 *  void
 *****************************************************************************/
void keyboard_input_handler(S32 vkey_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_keyboard_input_handler != NULL)
    {
        MMI_keyboard_input_handler(vkey_code);
    }
}


/*****************************************************************************
 * FUNCTION
 *  keyboard_global_key_handler
 * DESCRIPTION
 *  Handles key events (UP/DOWN)
 * PARAMETERS
 *  vkey_code       [IN]        Key's scan code
 *  key_state       [IN]        Key's state (up or down)
 * RETURNS
 *  void
 *****************************************************************************/
void keyboard_global_key_handler(S32 vkey_code, S32 key_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 state = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Perform scan code and key state mapping here */
    if (key_state == KEYBOARD_KEY_DOWN)
    {
        state = 1;
    }
    else if (key_state == KEYBOARD_KEY_UP)
    {
        state = 0;
    }

    if (MMI_keyboard_global_key_handler != NULL)
    {
        MMI_keyboard_global_key_handler(vkey_code, state);
    }
}


/*****************************************************************************
 * FUNCTION
 *  keyboard_global_input_handler
 * DESCRIPTION
 *  Handles keyboard input
 * PARAMETERS
 *  vkey_code       [IN]        Key's character code (ASCII)
 * RETURNS
 *  void
 *****************************************************************************/
void keyboard_global_input_handler(S32 vkey_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_keyboard_global_input_handler != NULL)
    {
        MMI_keyboard_global_input_handler(vkey_code);
    }
}


/*****************************************************************************
 * FUNCTION
 *  register_keyboard_key_handler
 * DESCRIPTION
 *  Registers a function to be called for key handling
 * PARAMETERS
 *  f       [IN]        Function to be called for key handling
 * RETURNS
 *  void
 *****************************************************************************/
void register_keyboard_key_handler(void (*f) (S32 vkey_code, S32 key_state))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_keyboard_key_handler = f;
}


/*****************************************************************************
 * FUNCTION
 *  register_keyboard_input_handler
 * DESCRIPTION
 *  Registers a function to be called for key input
 * PARAMETERS
 *  f       [IN]        Function that is called upon key events
 * RETURNS
 *  void
 *****************************************************************************/
void register_keyboard_input_handler(void (*f) (S32 vkey_code))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_keyboard_input_handler = f;
}


/*****************************************************************************
 * FUNCTION
 *  register_keyboard_global_key_handler
 * DESCRIPTION
 *  Registers a function to be called for key handling
 * PARAMETERS
 *  f       [IN]        Function that is called upon key events
 * RETURNS
 *  void
 *****************************************************************************/
void register_keyboard_global_key_handler(void (*f) (S32 vkey_code, S32 key_state))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_keyboard_global_key_handler = f;
}


/*****************************************************************************
 * FUNCTION
 *  register_keyboard_global_input_handler
 * DESCRIPTION
 *  Register_keyboard_global_input_handler
 * PARAMETERS
 *  f       [IN]        Function that is called upon key events
 * RETURNS
 *  void
 *****************************************************************************/
void register_keyboard_global_input_handler(void (*f) (S32 vkey_code))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_keyboard_global_input_handler = f;
}


/*****************************************************************************
 * FUNCTION
 *  clear_keyboard_key_handler
 * DESCRIPTION
 *  Clears the function called to handle key events
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clear_keyboard_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_keyboard_key_handler = dummy_keyboard_key_handler;
}


/*****************************************************************************
 * FUNCTION
 *  clear_keyboard_input_handler
 * DESCRIPTION
 *  Clears the function called to handle key input
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clear_keyboard_input_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_keyboard_input_handler = dummy_keyboard_input_handler;
}


/*****************************************************************************
 * FUNCTION
 *  clear_keyboard_global_key_handler
 * DESCRIPTION
 *  Clears the function called to handle key events
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clear_keyboard_global_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_keyboard_global_key_handler = dummy_keyboard_key_handler;
}


/*****************************************************************************
 * FUNCTION
 *  clear_keyboard_global_input_handler
 * DESCRIPTION
 *  Clears the function called to handle key input
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clear_keyboard_global_input_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_keyboard_global_input_handler = dummy_keyboard_input_handler;
}

/* Key handling wrappers      */


/*****************************************************************************
 * FUNCTION
 *  clear_key_handlers
 * DESCRIPTION
 *  Clears the key handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clear_key_handlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_softkey_handler(MMI_LEFT_SOFTKEY);
    clear_softkey_handler(MMI_RIGHT_SOFTKEY);
    clear_softkey_handler(MMI_CENTER_SOFTKEY);
    register_keyboard_key_handler(dummy_keyboard_key_handler);
    register_keyboard_input_handler(dummy_keyboard_input_handler);
    register_keyboard_global_input_handler(dummy_keyboard_input_handler);
    ClearInputEventHandler(MMI_DEVICE_KEY);
}


/*****************************************************************************
 * FUNCTION
 *  clear_category_screen_key_handlers
 * DESCRIPTION
 *  Clears the key handlers used in category screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clear_category_screen_key_handlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_softkey_handler(MMI_LEFT_SOFTKEY);
    clear_softkey_handler(MMI_RIGHT_SOFTKEY);
    clear_softkey_handler(MMI_CENTER_SOFTKEY);
    register_keyboard_key_handler(dummy_keyboard_key_handler);
    register_keyboard_input_handler(dummy_keyboard_input_handler);
}


/*****************************************************************************
 * FUNCTION
 *  register_key_input_handler
 * DESCRIPTION
 *  Registers a key input handler for a keypad key
 * PARAMETERS
 *  f       [IN]        Function that is called on receiving key events
 * RETURNS
 *  void
 *****************************************************************************/
void register_key_input_handler(void (*f) (MMI_key_code_type key_code, MMI_key_event_type key_event))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_key_input_handler_function = f;
}


/*****************************************************************************
 * FUNCTION
 *  register_key_up_handler
 * DESCRIPTION
 *  Registers handler for the key up events of all keys
 * PARAMETERS
 *  f       [IN]        Function that is called whenever any key is released
 * RETURNS
 *  void
 *****************************************************************************/
void register_key_up_handler(void (*f) (MMI_key_code_type key_code))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_key_up_handler_function = f;
}


/*****************************************************************************
 * FUNCTION
 *  register_key_down_handler
 * DESCRIPTION
 *  Registers handler for the key down events of all keys
 * PARAMETERS
 *  f       [IN]        Function that is called whenever any key is pressed
 * RETURNS
 *  void
 *****************************************************************************/
void register_key_down_handler(void (*f) (MMI_key_code_type key_code))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_key_down_handler_function = f;
}


/*****************************************************************************
 * FUNCTION
 *  clear_key_input_handler
 * DESCRIPTION
 *  Clears the key input handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clear_key_input_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_key_input_handler_function = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  clear_key_down_handler
 * DESCRIPTION
 *  Clears the key down handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clear_key_down_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_key_down_handler_function = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  clear_key_up_handler
 * DESCRIPTION
 *  Clears the key up handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clear_key_up_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_key_up_handler_function = NULL;
}

/*----------------------------------------------------------------------------
   The following functions are used internally and are not meant to be called
   by other functions.
----------------------------------------------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  MMI_key_input_handler
 * DESCRIPTION
 *  Handler key input events
 * PARAMETERS
 *  key_code        [IN]        
 *  key_event       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MMI_key_input_handler(MMI_key_code_type key_code, MMI_key_event_type key_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_key_input_handler_function != NULL)
    {
        MMI_key_input_handler_function(key_code, key_event);
    }

    switch (key_event)
    {
        case KEY_EVENT_DOWN:
            if (MMI_key_down_handler_function != NULL)
            {
                MMI_key_down_handler_function(key_code);
            }
            break;
        case KEY_EVENT_UP:
            if (MMI_key_up_handler_function != NULL)
            {
                MMI_key_up_handler_function(key_code);
            }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  MMI_key_0_down
 * DESCRIPTION
 *  Handle key 0 pressed event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMI_key_0_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_key_input_handler(KEY_0, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  MMI_key_1_down
 * DESCRIPTION
 *  Handle key 1 pressed event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMI_key_1_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_key_input_handler(KEY_1, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  MMI_key_2_down
 * DESCRIPTION
 *  Handle key 2 pressed event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMI_key_2_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_key_input_handler(KEY_2, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  MMI_key_3_down
 * DESCRIPTION
 *  Handle key 3 pressed event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMI_key_3_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_key_input_handler(KEY_3, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  MMI_key_4_down
 * DESCRIPTION
 *  Handle key 4 pressed event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMI_key_4_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_key_input_handler(KEY_4, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  MMI_key_5_down
 * DESCRIPTION
 *  Handle key 5 pressed event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMI_key_5_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_key_input_handler(KEY_5, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  MMI_key_6_down
 * DESCRIPTION
 *  Handle key 6 pressed event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMI_key_6_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_key_input_handler(KEY_6, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  MMI_key_7_down
 * DESCRIPTION
 *  Handle key 7 pressed event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMI_key_7_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_key_input_handler(KEY_7, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  MMI_key_8_down
 * DESCRIPTION
 *  Handle key 8 pressed event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMI_key_8_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_key_input_handler(KEY_8, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  MMI_key_9_down
 * DESCRIPTION
 *  Handle key 9 pressed event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMI_key_9_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_key_input_handler(KEY_9, KEY_EVENT_DOWN);
}

/* multitap for star and Pound */


/*****************************************************************************
 * FUNCTION
 *  MMI_key_star_down
 * DESCRIPTION
 *  Handle key star pressed event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMI_key_star_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_key_input_handler(KEY_STAR, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  MMI_key_pound_down
 * DESCRIPTION
 *  Handle key pound pressed event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMI_key_pound_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_key_input_handler(KEY_POUND, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  MMI_key_0_up
 * DESCRIPTION
 *  Handle key 0 release event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMI_key_0_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_key_input_handler(KEY_0, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  MMI_key_1_up
 * DESCRIPTION
 *  Handle key 1 release event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMI_key_1_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_key_input_handler(KEY_1, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  MMI_key_2_up
 * DESCRIPTION
 *  Handle key 2 release event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMI_key_2_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_key_input_handler(KEY_2, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  MMI_key_3_up
 * DESCRIPTION
 *  Handle key 3 release event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMI_key_3_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_key_input_handler(KEY_3, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  MMI_key_4_up
 * DESCRIPTION
 *  Handle key 4 release event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMI_key_4_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_key_input_handler(KEY_4, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  MMI_key_5_up
 * DESCRIPTION
 *  Handle key 5 release event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMI_key_5_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_key_input_handler(KEY_5, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  MMI_key_6_up
 * DESCRIPTION
 *  Handle key 6 release event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMI_key_6_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_key_input_handler(KEY_6, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  MMI_key_7_up
 * DESCRIPTION
 *  Handle key 7 release event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMI_key_7_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_key_input_handler(KEY_7, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  MMI_key_8_up
 * DESCRIPTION
 *  Handle key 8 release event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMI_key_8_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_key_input_handler(KEY_8, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  MMI_key_9_up
 * DESCRIPTION
 *  Handle key 9 release event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMI_key_9_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_key_input_handler(KEY_9, KEY_EVENT_UP);
}

/* multitap for star and pound */


/*****************************************************************************
 * FUNCTION
 *  MMI_key_star_up
 * DESCRIPTION
 *  Handle key star release event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMI_key_star_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_key_input_handler(KEY_STAR, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  MMI_key_pound_up
 * DESCRIPTION
 *  Handle key pound release event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMI_key_pound_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_key_input_handler(KEY_POUND, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  register_MMI_key_input_extend_handler
 * DESCRIPTION
 *  Register key handlers for start and pound key.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_MMI_key_input_extend_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(MMI_key_star_down, KEY_STAR, KEY_EVENT_DOWN);
    SetKeyHandler(MMI_key_star_up, KEY_STAR, KEY_EVENT_UP);

    SetKeyHandler(MMI_key_pound_down, KEY_POUND, KEY_EVENT_DOWN);
    SetKeyHandler(MMI_key_pound_up, KEY_POUND, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  register_MMI_key_input_handler
 * DESCRIPTION
 *  Register key handlers for all digit keys
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_MMI_key_input_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(MMI_key_0_down, KEY_0, KEY_EVENT_DOWN);
    SetKeyHandler(MMI_key_1_down, KEY_1, KEY_EVENT_DOWN);
    SetKeyHandler(MMI_key_2_down, KEY_2, KEY_EVENT_DOWN);
    SetKeyHandler(MMI_key_3_down, KEY_3, KEY_EVENT_DOWN);
    SetKeyHandler(MMI_key_4_down, KEY_4, KEY_EVENT_DOWN);
    SetKeyHandler(MMI_key_5_down, KEY_5, KEY_EVENT_DOWN);
    SetKeyHandler(MMI_key_6_down, KEY_6, KEY_EVENT_DOWN);
    SetKeyHandler(MMI_key_7_down, KEY_7, KEY_EVENT_DOWN);
    SetKeyHandler(MMI_key_8_down, KEY_8, KEY_EVENT_DOWN);
    SetKeyHandler(MMI_key_9_down, KEY_9, KEY_EVENT_DOWN);

    SetKeyHandler(MMI_key_0_down, KEY_0, KEY_REPEAT);
    SetKeyHandler(MMI_key_1_down, KEY_1, KEY_REPEAT);
    SetKeyHandler(MMI_key_2_down, KEY_2, KEY_REPEAT);
    SetKeyHandler(MMI_key_3_down, KEY_3, KEY_REPEAT);
    SetKeyHandler(MMI_key_4_down, KEY_4, KEY_REPEAT);
    SetKeyHandler(MMI_key_5_down, KEY_5, KEY_REPEAT);
    SetKeyHandler(MMI_key_6_down, KEY_6, KEY_REPEAT);
    SetKeyHandler(MMI_key_7_down, KEY_7, KEY_REPEAT);
    SetKeyHandler(MMI_key_8_down, KEY_8, KEY_REPEAT);
    SetKeyHandler(MMI_key_9_down, KEY_9, KEY_REPEAT);

    SetKeyHandler(MMI_key_0_up, KEY_0, KEY_EVENT_UP);
    SetKeyHandler(MMI_key_1_up, KEY_1, KEY_EVENT_UP);
    SetKeyHandler(MMI_key_2_up, KEY_2, KEY_EVENT_UP);
    SetKeyHandler(MMI_key_3_up, KEY_3, KEY_EVENT_UP);
    SetKeyHandler(MMI_key_4_up, KEY_4, KEY_EVENT_UP);
    SetKeyHandler(MMI_key_5_up, KEY_5, KEY_EVENT_UP);
    SetKeyHandler(MMI_key_6_up, KEY_6, KEY_EVENT_UP);
    SetKeyHandler(MMI_key_7_up, KEY_7, KEY_EVENT_UP);
    SetKeyHandler(MMI_key_8_up, KEY_8, KEY_EVENT_UP);
    SetKeyHandler(MMI_key_9_up, KEY_9, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  clear_MMI_key_input_handler
 * DESCRIPTION
 *  Clear key handlers for input
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clear_MMI_key_input_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_0, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_1, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_2, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_3, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_4, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_5, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_6, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_7, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_8, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_9, KEY_EVENT_DOWN);

    ClearKeyHandler(KEY_0, KEY_EVENT_UP);
    ClearKeyHandler(KEY_1, KEY_EVENT_UP);
    ClearKeyHandler(KEY_2, KEY_EVENT_UP);
    ClearKeyHandler(KEY_3, KEY_EVENT_UP);
    ClearKeyHandler(KEY_4, KEY_EVENT_UP);
    ClearKeyHandler(KEY_5, KEY_EVENT_UP);
    ClearKeyHandler(KEY_6, KEY_EVENT_UP);
    ClearKeyHandler(KEY_7, KEY_EVENT_UP);
    ClearKeyHandler(KEY_8, KEY_EVENT_UP);
    ClearKeyHandler(KEY_9, KEY_EVENT_UP);

#if defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
    ClearKeyHandler(KEY_POUND, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);

    ClearKeyHandler(KEY_STAR, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_STAR, KEY_EVENT_UP);
#endif

}

/* Initialization / termination wrappers  */


/*****************************************************************************
 * FUNCTION
 *  wgui_init
 * DESCRIPTION
 *  Initializes the GUI wrappers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_MMI_theme((MMI_theme*) MMI_themes[0]);

    gui_initialize_default_themes();
#if defined(__MMI_FONT_EFFECTS__)
    mmi_fe_init_font_effect_theme_ext();
#endif /* __MMI_FONT_EFFECTS__ */
#ifdef UI_EMS_SUPPORT
#if(!UI_DISABLE_EMS_INPUT_BOX)
    gui_intialize_EMS();
#endif 
#endif /* UI_EMS_SUPPORT */

    register_keyboard_key_handler(dummy_keyboard_key_handler);
    register_keyboard_input_handler(dummy_keyboard_input_handler);
    register_keyboard_global_key_handler(dummy_keyboard_key_handler);

    create_softkeys();
    create_menu_shortcut_handler();
    create_fixed_list();
    create_fixed_matrix();
    
#if defined(__MMI_VIRTUAL_KEYBOARD__)
    #ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__
    create_virtual_keyboard();
    #else
    wgui_virtual_keyboard_init_layout();
    #endif
#endif /* defined(__MMI_VIRTUAL_KEYBOARD__) */

    clear_key_input_handler();
    clear_key_down_handler();
    clear_key_up_handler();
    wgui_status_icon_bar_initialize();
    register_multiline_inputbox_input_callback(UI_dummy_function);
#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN) || defined(GUI_MATRIX_MENU_SMOOTH_SCROLLING_BY_PEN)
    gui_list_ssp_init_parameter();
#endif
}

extern void UpdateUITheme(void);

/** Animation handle of title icon */
GDI_HANDLE MMI_title_icon_ani_handle = GDI_ERROR_HANDLE;

extern FuncPtr gExitFullScreenCallBack;

/*****************************************************************************
 * FUNCTION
 *  UI_common_screen_pre_exit
 * DESCRIPTION
 *  Failsafe screen exit function *before* screen exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * REMARKS
 *  Some functions should not be invoked after screen exit function.
 *  (e.g. BLT on layers that are already released.)
 *****************************************************************************/
void UI_common_screen_pre_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* suspend VRT as soon as possible when screen is exited */
#ifdef __MMI_VUI_ENGINE__
    vrt_canvas_suspend();
#endif    
#ifdef __MMI_TOUCH_SCREEN__
#ifdef __MMI_VUI_3D_CUBE_APP__
    if (!vadp_p2v_uc_is_in_venus())
#endif
    {
        //mmi_pen_reset();
		mmi_frm_touch_screen_switch_action();
    }
#endif 
    gui_pre_cleanup();
    if (!dm_is_activated())
    {
        dm_reset_context_ext();
    }

#ifdef __MMI_SCREEN_SWITCH_EFFECT__
    gui_screen_switch_effect_pre_exit_screen();
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  UI_common_component_exit
 * DESCRIPTION
 *  Failsafe screen exit function *after* screen exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_common_component_exit(void)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_close();
    wgui_title_create();
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__		
    wgui_title_set_no_icon_shct(MMI_TRUE);//MMI_FALSE
#endif
    wgui_title_set_thick(MMI_FALSE);
    wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_H_BAR);
#ifdef WGUI_STATUS_ICON_SHOW_V_BAR        
    wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_V_BAR);
#endif
    wgui_status_icon_bar_reset();
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE 
    wgui_status_icon_bar_enable_integrated(MMI_TRUE);
    wgui_status_icon_bar_register_integrated_redraw(NULL);
#endif
    clear_category_screen_key_handlers();
    clear_left_softkey();
    clear_right_softkey();
	
    clear_softkey_display_functions(MMI_CENTER_SOFTKEY);
#ifndef __MMI_WGUI_DISABLE_CSK__	
    ResetCenterSoftkey();
#endif
    /* Editor common exit handler */
    wgui_inputs_close();

    /* for some special screen do not resize list */
    resize_fixed_list(MMI_content_width, MMI_content_height);

    /* Reset the toggle transition effect when exit screen */
#ifdef __MMI_UI_HINT_TOGGLE_TRANSITION__
    wgui_reset_pop_up_description_transition();
#endif
}
/*****************************************************************************
 * FUNCTION
 *  UI_common_screen_exit
 * DESCRIPTION
 *  Failsafe screen exit function *after* screen exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_common_screen_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle main_base_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      
    g_mmi_is_in_ui_common_exit = MMI_TRUE;
    /* de-initialize gui effect */
#ifdef __MMI_UI_EFFECT_ENGINE__
    gui_effect_close();
#endif

#ifdef __MMI_SCREEN_SWITCH_EFFECT__
    gui_screen_switch_effect_pre_exit_category();
#endif
    
#ifdef __MMI_VIRTUAL_KEYBOARD__
    #ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__
    wgui_close_virtual_keyboard();
    #else
    wgui_virtual_keyboard_close();
    #endif
#endif

#ifdef __MMI_ICON_BAR_SUPPORT__ 
	#ifdef __MMI_FTE_SUPPORT__
    wgui_icon_bar_close();
	#endif
#endif

    if (ExitCategoryFunction != NULL)
    {
        ExitCategoryFunction();
    }

#if defined(__MMI_SCREEN_SWITCH_EFFECT__) || defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_KEY) || defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN) || defined(GUI_MATRIX_MENU_SMOOTH_SCROLLING_BY_PEN)
    gui_screen_switch_effect_post_exit_category();
#endif
    
    gui_smooth_scrolling_effect_post_exit_category();
    
    /* set default ABM source layer to the main base layer */
    if (!dm_is_fixed_layer_mode_enabled())
    {
        gdi_layer_get_base_handle(&main_base_layer);
        gdi_set_alpha_blending_source_layer(main_base_layer);    
    }

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_general_pen_handler();
//    mmi_pen_set_event_handler_callback(NULL, NULL);
    wgui_reset_list_item_selected_callback();
    wgui_reset_matrix_item_selected_callback();
#endif /* __MMI_TOUCH_SCREEN__ */ 

	mmi_imc_exit_screen();

    gui_cleanup();

    ClearHighlightHandler();
	SetParentHandler(0);

    gui_hide_animations();
    animation_handle = GDI_ERROR_HANDLE;
    if (MMI_title_icon_ani_handle != GDI_ERROR_HANDLE)
    {
        gdi_image_stop_animation(MMI_title_icon_ani_handle);
        MMI_title_icon_ani_handle = GDI_ERROR_HANDLE;
    }
    StopTimer(BLINKING_CURSOR);
#ifdef __MMI_THEMES_APPLICATION__
#ifndef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    UpdateUITheme();
#endif 
#endif /* __MMI_THEMES_APPLICATION__ */ 
    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = MMI_dummy_function;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */  

    /* set multilayer mask on/off */
#if defined (__GDI_MEMORY_PROFILE_2__)
    {
    #if defined(__MMI_SUBMENU_USE_MM_IMAGE__)
        gui_set_multilayer_mask(gui_get_multilayer_mask() | UI_MUL_BKG_MAINMENU | UI_MUL_BKG_SUBMENU);
        if (!srv_bootup_is_completed())
        {
            gui_set_multilayer_mask(gui_get_multilayer_mask() & (~UI_MUL_BKG_SUBMENU));
        }
        else
        {
            gui_set_multilayer_mask(gui_get_multilayer_mask() | UI_MUL_BKG_SUBMENU);
        }
    #else 
        gui_set_multilayer_mask(gui_get_multilayer_mask() & (~UI_MUL_BKG_MAINMENU) & (~UI_MUL_BKG_SUBMENU));
    #endif 
    }
#endif /* defined (__GDI_MEMORY_PROFILE_2__) */ 

    /* free all layer to be base layer */
	if(!dm_is_fixed_layer_mode_enabled())
	{
        gui_free_multilayer_screen();
	}
    gui_set_entry_new_screen(MMI_TRUE);
    /* redraw status */
    if (wgui_is_wallpaper_on_bottom())
    {
        gOnFullScreen = MMI_LEAVE_BG_ON_BOTTOM_SCREEN;
        wgui_reset_wallpaper_on_bottom();   /* support wallpaper on bottom */
    }
    gdi_image_gif_reset();
    gui_reset_clip();
    gui_reset_text_clip();
    reset_softkeys();
    
#if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X240__)
    if (gExitFullScreenCallBack != NULL)
    {
        gExitFullScreenCallBack();
        gExitFullScreenCallBack = NULL;
    }
#endif /* defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X240__) */    

#ifdef __MMI_SCREEN_ROTATE__
    mmi_frm_reset_screen_rotation();
#endif 

    UI_common_component_exit();

    gui_setup_default_layout();

    MMI_RES_STR_CHK_RESET();

#ifndef __MTK_TARGET__    
    /* 
     * Notify MTE there is a screen switch.
     *
     * Actually, this is quite tricky. But to get the current screen refreshed for 
     * full screen applications, such as JAVA, WAP, camera, ... , and etc,
     * this is necessary.
     */
    mmi_mte_mmi_notify_new_screen();
#endif /* __MTK_TARGET__ */
#ifdef __MMI_LCM_PRIMITIVE_FLUSH__
    mmi_frm_screen_set_sse_backup(MMI_FALSE);
#endif
    g_mmi_is_in_ui_common_exit = MMI_FALSE;
    mmi_frm_scrmem_debug_check_leak();

#if defined(__MMI_CABC__)
    /* reset cabc mode to default */
    gdi_cabc_reset();
#endif /* defined(__MMI_CABC__) */

    /* 9slice will keep memory allocation during one screen */
    gdi_image_9slice_handle_scrn_exit_proc();

}   /* end of UI_common_screen_exit */

#if defined(__SOCIAL_NETWORK_SUPPORT__)

S32 get_status_bar_height(void)
{
    return MMI_STATUS_BAR_HEIGHT;
}
S32 get_title_height(void)
{
    return MMI_TITLE_HEIGHT;
}
S32 get_menuitem_height(void)
{
    return MMI_MENUITEM_HEIGHT;
}
S32 get_multirow_menuitem_height(void)
{
    return MMI_MULTIROW_MENUITEM_HEIGHT;
}
S32 get_icontext_menuitem_icon_x(void)
{
    return GUI_ICONTEXT_MENUITEM_ICON_X;
}
S32 get_text_menuitem_text_x(void)
{
    return GUI_TEXT_MENUITEM_TEXT_X;
}
S32 get_menuitem_x2_gap(void)
{
    return GUI_MENUITEM_X2_GAP;
}
S32 get_menuitem_text_right_gap(void)
{
    return GUI_MENUITEM_TEXT_RIGHT_GAP;
}
S32 get_icontext_menuitem_height(void)
{
    return MMI_ICONTEXT_MENUITEM_HEIGHT;
}
S32 get_content_x(void)
{
    return MMI_CONTENT_X;
}
S32 get_content_height(void)
{
    return MMI_CONTENT_HEIGHT;
}
S32 get_content_width(void)
{
    return MMI_CONTENT_WIDTH;
}
S32 get_content_height_with_h_bar(void)
{
    return CAT_MMI_CONTENT_HEIGHT_WITH_H_TAB;
}
S32 get_content_x_with_h_tab(void)
{
    return CAT_MMI_CONTENT_X_WITH_H_TAB;
}
S32 get_content_y_with_h_tab(void)
{
    return CAT_MMI_CONTENT_Y_WITH_H_TAB;
}
S32 get_horzontal_tab_bar_hint_area_height(void)
{
    return MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT;
}
S32 get_horizontal_tab_bar_tab_area_height(void)
{
    return MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT;
}
S32 get_horizontal_tab_bar_y(void)
{
    return MMI_HORIZONTAL_TAB_BAR_Y;
}
S32 get_icon_bar_height(void)
{
    return MMI_ICON_BAR_HEIGHT;
}
S32 get_button_bar_height(void)
{
    return MMI_BUTTON_BAR_HEIGHT;
}
U16 get_sns_more_string_id(void)
{
    return WGUI_SNS_GET_MORE_STRING_ID;
}
U16 get_global_loading_id(void)
{
    return STR_GLOBAL_LOADING;
}
#endif


