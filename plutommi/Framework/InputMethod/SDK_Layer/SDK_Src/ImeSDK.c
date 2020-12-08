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
 *  ImeSDK.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  The implementation of IME SDK interface
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#ifdef __MMI_IME_PLUG_IN__

/****************************************************************************
 * Includes
 *****************************************************************************/
#include "ImeGprot.h"
#include "ImeSDKGprot.h"
#include "ImeSDKProt.h"
#include "Imc.h"
#include "Imc_key.h"
#include "Imc_pen.h"
#include "Imui.h"
#include "ImmProt.h"
#include "CommonScreens.h"
#include "wgui.h"
#include "wgui_softkeys.h"
#include "GlobalConstants.h"

#ifdef __MMI_VUI_ENGINE__
#include "framework\vadp_p2v_uc.h"
#include "ime\vadp_p2v_input_server_interface.h"
#endif



/****************************************************************************
 * Typedef
 *****************************************************************************/
typedef void (*vendor_init_func_ptr)(void);


/******************************************************************
 * Define
 ******************************************************************/
#define IMESDK_C_USED
/******************************************************************
 * extern void vendor_init_func(void); 
 ******************************************************************/
#define MMI_IME_SDK_REG_BEGIN()
#define MMI_IME_SDK_REG(vendor_init_func) extern void vendor_init_func(void);
#define MMI_IME_SDK_REG_END()
#include "ImeSDKConfig.h"
/******************************************************************
 * static const mmi_ime_sdk_msg_funcptr mmi_ime_sdk_init_func_table[] = 
 * {
 *     vendor_init_func,
 *     NULL
 * };
 ******************************************************************/
#undef MMI_IME_SDK_REG_BEGIN
#undef MMI_IME_SDK_REG
#undef MMI_IME_SDK_REG_END

#define MMI_IME_SDK_VENDOR_INIT_ARRAY mmi_ime_sdk_init_func_table

#define MMI_IME_SDK_REG_BEGIN() static const vendor_init_func_ptr MMI_IME_SDK_VENDOR_INIT_ARRAY[] =  {
#define MMI_IME_SDK_REG(vendor_init_func) vendor_init_func,
#define MMI_IME_SDK_REG_END() NULL	};
#include "ImeSDKConfig.h"


/*****************************************************************************
 * Structs
 *****************************************************************************/
typedef struct
{
    mmi_ime_sdk_msg_funcptr msg_callback_func; /* only one member now */
} mmi_ime_sdk_context_struct;


/*****************************************************************************
 * External Variables
 *****************************************************************************/
#if defined(UI_SMALL_CATEGORY_EDITOR)
extern BOOL g_small_editor_category_present;
#endif


/****************************************************************************
 * Local Variables                                                                
 *****************************************************************************/
static mmi_ime_sdk_context_struct g_ime_sdk_context;

#ifdef __MMI_IME_PLUG_IN_SETTING__
static mmi_ime_sdk_setting_funcptr g_ime_sdk_setting_cb_func = NULL;
#endif

/****************************************************************************
 * Local Functions                                                                 
 *****************************************************************************/
static void mmi_ime_sdk_traverse_vendor_init_array(void);


/*****************************************************************************
 * Functions
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_init
 * DESCRIPTION
 *  It initializes the ime sdk
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  Always return MMI_TRUE
 *****************************************************************************/
MMI_BOOL mmi_ime_sdk_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ime_sdk_context.msg_callback_func = NULL;
    mmi_ime_sdk_traverse_vendor_init_array();
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_deinit
 * DESCRIPTION
 *  It deinits the ime sdk
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_sdk_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ime_sdk_context.msg_callback_func = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_send_sdk_msg
 * DESCRIPTION
 *  It sends the message to registered sdk message callback function
 * PARAMETERS
 *  msg_id      :   [IN]            the message id of message to be sent
 *  param0      :   [IN]            the first parameter of message to be sent
 *  param1      :   [IN]            the second parameter of message to be sent
 * RETURNS
 *  U32
 * RETURN VALUES
 *  The return value of registered sdk message callback function, or 0 if there
 *  is no registered callback function for optional message.
 *****************************************************************************/
U32 mmi_ime_sdk_send_sdk_msg(mmi_ime_sdk_msg_id_enum msg_id, U32 param0, U32 param1)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ime_sdk_context.msg_callback_func != NULL)
    {
        return g_ime_sdk_context.msg_callback_func(msg_id, param0, param1);
    }
    else
    {
        return 0;
    }
}


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
void mmi_ime_sdk_register_msg_callback(mmi_ime_sdk_msg_funcptr msg_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ime_sdk_context.msg_callback_func != NULL && g_ime_sdk_context.msg_callback_func != msg_cb)
    {
        /* current message callback function is registerd by other one */
        MMI_ASSERT(0);
    }
    g_ime_sdk_context.msg_callback_func = msg_cb;
}


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
void mmi_ime_sdk_unregister_msg_callback(mmi_ime_sdk_msg_funcptr msg_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ime_sdk_context.msg_callback_func != NULL && g_ime_sdk_context.msg_callback_func != msg_cb)
    {
        /* 
         * current message callback function is not consistent with
         * the one which want to be unrigistered
         */
        MMI_ASSERT(0);
    }
    g_ime_sdk_context.msg_callback_func = NULL;
}


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
void mmi_ime_sdk_set_state(mmi_ime_sdk_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (state == MMI_IME_SDK_STATE_INITIAL)
    {
        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
    }
    else if (state >= MMI_IME_SDK_STATE_BEGIN && state <= MMI_IME_SDK_STATE_END)
    {
        mmi_imc_set_state((mmi_imc_state_enum)state);
    }
    else
    {
        MMI_ASSERT(0); /* the state is invalid */
    }
}


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
mmi_ime_sdk_state_enum mmi_ime_sdk_get_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_state_enum  curr_state = mmi_imc_get_state();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (curr_state >= MMI_IMC_STATE_CUSTOM_BEGIN && curr_state <= MMI_IMC_STATE_CUSTOM_END)
    {
        return (mmi_ime_sdk_state_enum)curr_state;
    }
    else if (curr_state == MMI_IMC_STATE_NONE)
    {
        return MMI_IME_SDK_STATE_NONE;
    }
    else if (curr_state == MMI_IMC_STATE_INITIAL)
    {
        return MMI_IME_SDK_STATE_INITIAL;
    }
    else
    {
        return MMI_IME_SDK_STATE_MTK;
    }
}


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
MMI_BOOL mmi_ime_sdk_redraw_screen_by_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_imc_redraw_screen_by_state_ext();
}


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
U32 mmi_ime_sdk_send_editor_msg(mmi_imc_message_struct_p msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_ptr == NULL)
    {
        MMI_ASSERT(0);
    }
    
    return mmi_imc_send_message(msg_ptr);
}


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
MMI_BOOL mmi_ime_sdk_set_current_input_mode(mmi_imm_input_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mode > IMM_INPUT_MODE_NONE && mode < IMM_INPUT_MODE_MAX_NUM)
    {
        return mmi_imm_set_current_input_mode(mode);
    }
    else
    {
        MMI_ASSERT(0); /* the mode is invalid */
        return MMI_FALSE;
    }    
}


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
MMI_BOOL mmi_ime_sdk_change_input_mode(mmi_imm_input_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 reserved = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mode > IMM_INPUT_MODE_NONE && mode < IMM_INPUT_MODE_MAX_NUM)
    {
        return mmi_imc_change_input_mode(mode, reserved);
    }
    else
    {
        MMI_ASSERT(0); /* the mode is invalid */
        return MMI_FALSE;
    }
}


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
mmi_imm_input_mode_enum mmi_ime_sdk_get_next_input_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_imm_get_next_mode();
}


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
mmi_imm_input_mode_enum mmi_ime_sdk_get_current_input_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_imm_get_curr_input_mode();
}


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
const sIMEModeDetails * mmi_ime_sdk_get_input_mode_array_item(mmi_imm_input_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mode > IMM_INPUT_MODE_NONE && mode < IMM_INPUT_MODE_MAX_NUM)
    {
        return mmi_imm_get_input_mode_array_item(mode);
    }
    else
    {
        MMI_ASSERT(0); /* the mode is invalid */
        return NULL;
    }
}


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
S32 mmi_ime_sdk_get_current_allowed_input_mode_list(mmi_imm_input_mode_enum *mode_array, S32 max)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mode_array == NULL || max == 0)
    {
        MMI_ASSERT(0);
    }
    
    return mmi_imm_get_curr_allow_input_mode_list(mode_array, max);
}


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
S32 mmi_ime_sdk_get_current_allowed_input_mode_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_imm_get_current_allowed_input_mode_num();
}


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
mmi_imm_input_type_enum mmi_ime_sdk_get_current_input_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_imm_get_curr_input_type();
}


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
MMI_BOOL mmi_ime_sdk_is_symbol_picker_disabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_imc_is_symbol_picker_disable();
}


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
MMI_BOOL mmi_ime_sdk_is_valid_string(UI_string_type string, S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (string == NULL || length == 0)
    {
        MMI_ASSERT(0);
    }
    
    return mmi_imm_test_input(string, length);
}


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
MMI_BOOL mmi_ime_sdk_is_auto_completion_enabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_imm_is_auto_completion_enabled();
}


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
MMI_BOOL mmi_ime_sdk_is_auto_capitalization_enabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_imm_is_auto_capitalization_enabled();
}


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
MMI_BOOL mmi_ime_sdk_is_chinese_next_word_prediction_enabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_imm_is_chinese_word_prediction_enabled();
}


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
MMI_BOOL mmi_ime_sdk_is_alphabetic_next_word_prediction_enabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_imm_is_alphabetic_word_prediction_enabled();
}


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
void mmi_ime_sdk_entry_symbol_picker_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   // EntrySymbolPickerScreen();
   
#if defined __MMI_COSMOS_KEYPAD_BAR__ || defined  __MMI_COSMOS_KEYPAD_SLIDER__
#if defined(__MMI_VUI_ENGINE__)
        if (vadp_p2v_uc_is_in_venus())
        {
            vadp_p2v_show_symbol_picker();
        }
        else
#endif
#endif
        {
            EntrySymbolPickerScreen();
        }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_set_softkey_label_in_ime_state
 * DESCRIPTION
 *  Set the softkey label when it's in ime state.
 *  VENUS does not have softkey, call this api will do nothing in venus.
 * PARAMETERS
 *  s    :    [IN]  The string pointer to of the label
 *  key  :    [IN]  The softkey to change label
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_sdk_set_softkey_label_in_ime_state(UI_string_type s, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key < MMI_LEFT_SOFTKEY || key >= WGUI_MAX_SOFTKEYS)
    {
        MMI_ASSERT(0);
    }
    
    mmi_imc_key_set_softkey_label(s, key);
}


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
void mmi_ime_sdk_set_softkey_icon_in_ime_state(PU8 icon, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key < MMI_LEFT_SOFTKEY || key >= WGUI_MAX_SOFTKEYS)
    {
        MMI_ASSERT(0);
    }
    
    mmi_imc_key_set_softkey_icon(icon, key);
}


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
void mmi_ime_sdk_set_softkey_function(void (*f) (void), MMI_key_event_type k, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (f == NULL || key < MMI_LEFT_SOFTKEY || key >= WGUI_MAX_SOFTKEYS)
    {
        MMI_ASSERT(0);
    }
    
    mmi_imc_key_set_softkey_function(f, k, key);
}


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
void mmi_ime_sdk_clear_softkey_handler(WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key < MMI_LEFT_SOFTKEY || key >= WGUI_MAX_SOFTKEYS)
    {
        MMI_ASSERT(0);
    }
    
    mmi_imc_key_clear_softkey_handler(key);
}


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
void mmi_ime_sdk_show_softkey(WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key < MMI_LEFT_SOFTKEY || key >= WGUI_MAX_SOFTKEYS)
    {
        MMI_ASSERT(0);
    }
    
    mmi_imc_key_show_softkey(key);
}


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
void mmi_ime_sdk_register_softkey_handler(WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key < MMI_LEFT_SOFTKEY || key >= WGUI_MAX_SOFTKEYS)
    {
        MMI_ASSERT(0);
    }
    
    mmi_imc_key_register_softkey_handler(key);
}


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
void mmi_ime_sdk_set_key_handler(FuncPtr funcPtr, U16 keyCode, U16 keyType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (funcPtr == NULL || keyCode >= MAX_KEYS || keyType >= MAX_KEY_TYPE)
    {
        MMI_ASSERT(0);
    }
    
    mmi_imc_key_set_key_handler(funcPtr, keyCode, keyType);
}


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
FuncPtr mmi_ime_sdk_get_key_handler(U16 keyCode, U16 keyType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (keyCode >= MAX_KEYS || keyType >= MAX_KEY_TYPE)
    {
        MMI_ASSERT(0);
    }
    
    return mmi_imc_key_get_key_handler(keyCode, keyType);
}


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
void mmi_ime_sdk_clear_key_handler(U16 keyCode, U16 keyType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (keyCode >= MAX_KEYS || keyType >= MAX_KEY_TYPE)
    {
        MMI_ASSERT(0);
    }
    
    mmi_imc_key_clear_key_handler(keyCode, keyType);
}


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
UI_ime_theme *mmi_ime_sdk_get_ime_theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return current_ime_theme;
}


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
MMI_BOOL mmi_ime_sdk_is_small_screen_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef UI_SMALL_CATEGORY_EDITOR
    return (MMI_BOOL)g_small_editor_category_present;
#else
    return MMI_FALSE;
#endif 
}


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
void mmi_ime_sdk_config_auto_capitalization(MMI_BOOL is_enabled)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
    mmi_imm_config_auto_capitalization_validation(is_enabled);
#endif
}


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
void mmi_ime_sdk_config_chinese_word_prediction_by_pen(MMI_BOOL is_enabled)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    mmi_imc_pen_config_chinese_word_prediction_by_pen_enabled(is_enabled);
#endif
}


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
void mmi_ime_sdk_add_imui_control(mmi_ime_sdk_imui_control_enum imui_control)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_control_type_enum control = MMI_IMUI_CONTROL_MAX;
    mmi_imui_message_struct imui_msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imui_control == MMI_IME_SDK_IMUI_CONTROL_MTK_VK)
    {
        control = MMI_IMUI_VIRTUAL_KEYBOARD;
    }
    else if (imui_control >= MMI_IME_SDK_IMUI_CONTROL_BEGIN && imui_control <= MMI_IME_SDK_IMUI_CONTROL_END)
    {
        control = (mmi_imui_control_type_enum)imui_control;
    }
    else
    {
        MMI_ASSERT(0); /* the imui control is invalid */
    }
    
    imui_msg.message_id = (U8)MMI_IMUI_MESSAGE_ADD_CONTROL;
    imui_msg.param_0 = (U32)control;
    mmi_imui_send_message(&imui_msg, NULL);
}


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
MMI_BOOL mmi_ime_sdk_is_in_imui_control_set(mmi_ime_sdk_imui_control_enum imui_control)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_control_type_enum control = MMI_IMUI_CONTROL_MAX;
    mmi_imui_message_struct imui_msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imui_control == MMI_IME_SDK_IMUI_CONTROL_MTK_VK)
    {
        control = MMI_IMUI_VIRTUAL_KEYBOARD;
    }
    else if (imui_control >= MMI_IME_SDK_IMUI_CONTROL_BEGIN && imui_control <= MMI_IME_SDK_IMUI_CONTROL_END)
    {
        control = (mmi_imui_control_type_enum)imui_control;
    }
    else
    {
        MMI_ASSERT(0); /* the imui control is invalid */
    }

    imui_msg.message_id = (U8)MMI_IMUI_MESSAGE_IS_IN_CONTROL_SET;
    imui_msg.param_0 = (U32)control;
    return (MMI_BOOL)mmi_imui_send_message(&imui_msg, NULL);
}


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
void mmi_ime_sdk_set_visible_control(mmi_ime_sdk_imui_control_enum imui_control)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_control_type_enum control = MMI_IMUI_CONTROL_MAX;
    mmi_imui_message_struct imui_msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imui_control == MMI_IME_SDK_IMUI_CONTROL_MTK_VK)
    {
        control = MMI_IMUI_VIRTUAL_KEYBOARD;
    }
    else if (imui_control >= MMI_IME_SDK_IMUI_CONTROL_BEGIN && imui_control <= MMI_IME_SDK_IMUI_CONTROL_END)
    {
        control = (mmi_imui_control_type_enum)imui_control;
    }
    else
    {
        MMI_ASSERT(0); /* the imui control is invalid */
    }
    
    imui_msg.message_id = (U8)MMI_IMUI_MESSAGE_SET_VISIBLE_CONTROL;
    imui_msg.param_0 = (U32)control;
    mmi_imui_send_message(&imui_msg, NULL);
}


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
void mmi_ime_sdk_set_hidden_control(mmi_ime_sdk_imui_control_enum imui_control)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_control_type_enum control = MMI_IMUI_CONTROL_MAX;
    mmi_imui_message_struct imui_msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imui_control == MMI_IME_SDK_IMUI_CONTROL_MTK_VK)
    {
        control = MMI_IMUI_VIRTUAL_KEYBOARD;
    }
    else if (imui_control >= MMI_IME_SDK_IMUI_CONTROL_BEGIN && imui_control <= MMI_IME_SDK_IMUI_CONTROL_END)
    {
        control = (mmi_imui_control_type_enum)imui_control;
    }
    else
    {
        MMI_ASSERT(0); /* the imui control is invalid */
    }
    
    imui_msg.message_id = (U8)MMI_IMUI_MESSAGE_SET_HIDDEN_CONTROL;
    imui_msg.param_0 = (U32)control;
    mmi_imui_send_message(&imui_msg, NULL);
}


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
void mmi_ime_sdk_hide_all_controls(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imui_msg.message_id = (U8)MMI_IMUI_MESSAGE_HIDE_ALL;
    mmi_imui_send_message(&imui_msg, NULL);
}


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
MMI_BOOL mmi_ime_sdk_is_visible_control(mmi_ime_sdk_imui_control_enum imui_control)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_control_type_enum control = MMI_IMUI_CONTROL_MAX;
    mmi_imui_message_struct imui_msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imui_control == MMI_IME_SDK_IMUI_CONTROL_MTK_VK)
    {
        control = MMI_IMUI_VIRTUAL_KEYBOARD;
    }
    else if (imui_control >= MMI_IME_SDK_IMUI_CONTROL_BEGIN && imui_control <= MMI_IME_SDK_IMUI_CONTROL_END)
    {
        control = (mmi_imui_control_type_enum)imui_control;
    }
    else
    {
        MMI_ASSERT(0); /* the imui control is invalid */
    }

    imui_msg.message_id = (U8)MMI_IMUI_MESSAGE_IS_VISIBLE_CONTROL;
    imui_msg.param_0 = (U32)control;
    return (MMI_BOOL)mmi_imui_send_message(&imui_msg, NULL);
}


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
MMI_BOOL mmi_ime_sdk_is_previous_visible_control(mmi_ime_sdk_imui_control_enum imui_control)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_control_type_enum control = MMI_IMUI_CONTROL_MAX;
    mmi_imui_message_struct imui_msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imui_control == MMI_IME_SDK_IMUI_CONTROL_MTK_VK)
    {
        control = MMI_IMUI_VIRTUAL_KEYBOARD;
    }
    else if (imui_control >= MMI_IME_SDK_IMUI_CONTROL_BEGIN && imui_control <= MMI_IME_SDK_IMUI_CONTROL_END)
    {
        control = (mmi_imui_control_type_enum)imui_control;
    }
    else
    {
        MMI_ASSERT(0); /* the imui control is invalid */
    }

    imui_msg.message_id = (U8)MMI_IMUI_MESSAGE_IS_PREVIOUS_VISIBLE_CONTROL;
    imui_msg.param_0 = (U32)control;
    return (MMI_BOOL)mmi_imui_send_message(&imui_msg, NULL);
}


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
MMI_BOOL mmi_ime_sdk_is_previous_visible_floating_control(mmi_ime_sdk_imui_control_enum imui_control)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_control_type_enum control = MMI_IMUI_CONTROL_MAX;
    mmi_imui_message_struct imui_msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imui_control == MMI_IME_SDK_IMUI_CONTROL_MTK_VK)
    {
        control = MMI_IMUI_VIRTUAL_KEYBOARD;
    }
    else if (imui_control >= MMI_IME_SDK_IMUI_CONTROL_BEGIN && imui_control <= MMI_IME_SDK_IMUI_CONTROL_END)
    {
        control = (mmi_imui_control_type_enum)imui_control;
    }
    else
    {
        MMI_ASSERT(0); /* the imui control is invalid */
    }

    imui_msg.message_id = (U8)MMI_IMUI_MESSAGE_IS_PREVIOUS_VISIBLE_FLOATING_CONTROL;
    imui_msg.param_0 = (U32)control;
    return (MMI_BOOL)mmi_imui_send_message(&imui_msg, NULL);
}


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
void mmi_ime_sdk_get_imui_param(mmi_imui_param_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param == NULL)
    {
        MMI_ASSERT(0);
    }

    imui_msg.message_id = (U8)MMI_IMUI_MESSAGE_GET_IMUI_PARAMETERS;
    imui_msg.param_0 = (U32)param;
    mmi_imui_send_message(&imui_msg, NULL);
}


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
void mmi_ime_sdk_redraw_imui_background(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
    mmi_imc_rect rect;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(x1 >= x2 || y1 >= y2)
    {
        MMI_ASSERT(0);
    }

    rect.x = x1;
    rect.y = y1;
    rect.width= x2 - x1;
    rect.height = y2 - y1;
    
    imui_msg.message_id = (U8)MMI_IMUI_MESSAGE_REDRAW_IMUI_BACKGROUND;
    imui_msg.param_0 = (U32)&rect;
    mmi_imui_send_message(&imui_msg, NULL);
}


#if defined(__MMI_TOUCH_SCREEN__)
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
void mmi_ime_sdk_set_virtual_keyboard_type(gui_virtual_keyboard_language_enum vk_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vk_type >= GUI_VIRTUAL_KEYBOARD_ENGLISH && vk_type < GUI_VIRTUAL_KEYBOARD_MAX_LANG)
    {
        mmi_imc_pen_set_virtual_keyboard(vk_type, MMI_FALSE);
    }
    else
    {
        MMI_ASSERT(0); /* the vk type is invalid */
    }
}


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
gui_virtual_keyboard_language_enum mmi_ime_sdk_get_virtual_keyboard_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imui_msg.message_id = (U8)MMI_IMUI_MESSAGE_GET_VK_TYPE;
    return (gui_virtual_keyboard_language_enum)mmi_imui_send_message(&imui_msg, NULL);
}


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
S32 mmi_ime_sdk_get_virtual_keyboard_area_height(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imui_msg.message_id = (U8)MMI_IMUI_MESSAGE_GET_VK_AREA_HEIGHT;
    return (S32)mmi_imui_send_message(&imui_msg, NULL);
}

#if defined(__MMI_IME_FTE_ENHANCE__)
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
void mmi_ime_sdk_set_virtual_keyboard_style(U32 vk_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vk_style != MMI_VK_TYPE_QWERTY && vk_style != MMI_VK_TYPE_ALPHANUMERIC)
    {
        MMI_ASSERT(0);
    }
    
    imui_msg.message_id = (U8)MMI_IMUI_MESSAGE_SET_VK_STYLE;
    imui_msg.param_0 = (U32)vk_style;
    mmi_imui_send_message(&imui_msg, NULL);
}

#endif /* defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) */
#endif /* defined(__MMI_IME_FTE_ENHANCE__) */
#endif /* defined(__MMI_VIRTUAL_KEYBOARD__) */


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
MMI_BOOL mmi_ime_sdk_is_virtual_keyboard_disabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_imc_is_vk_disabled();
}

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
MMI_BOOL mmi_ime_sdk_is_virtual_keyboard_hidden(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imui_msg.message_id = (U8)MMI_IMUI_MESSAGE_IS_VIRTUAL_KEYBOARD_HIDDEN;
    return (MMI_BOOL)mmi_imui_send_message(&imui_msg, NULL);
}

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
void mmi_ime_sdk_print_string_inserted_to_editor(UI_string_type str_ptr, S32 str_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (str_ptr == NULL || str_len == 0)
    {
        MMI_ASSERT(0);
    }
    
    mmi_imc_print_string_inserted_to_editor(str_ptr, str_len);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_traverse_vendor_init_array
 * DESCRIPTION
 *  It traverses the array of vendor initialization function registered in
 *  ImeSDKConfig.h and calls the initialization function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ime_sdk_traverse_vendor_init_array(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* MMI_IME_SDK_VENDOR_INIT_ARRAY is defined in ImeSDKCfg.h */
    while(MMI_IME_SDK_VENDOR_INIT_ARRAY[i] != NULL) 
    {
        if (i >= 1)
        {
            /* because only one item is supported now */
            MMI_ASSERT(0);
        }
        
        (*((vendor_init_func_ptr)MMI_IME_SDK_VENDOR_INIT_ARRAY[i]))();
        i++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_get_custom_control_mask
 * DESCRIPTION
 *  It gets the mask bits of vendor's controls
 * PARAMETERS
 *  void
 * RETURNS
 *  U32
 * RETURN VALUES
 *  The mask bits of vendor's controls
 *****************************************************************************/
U32 mmi_ime_sdk_get_custom_control_mask(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 custom_control_mask = 0;
    // int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    custom_control_mask = (1 << MMI_IMUI_CUSTOM_UI_CONTROL_SIZE) - 1;
    
    custom_control_mask <<= MMI_IMUI_CUSTOM_CONTROL_BEGIN;
    return custom_control_mask;
}


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
S32 mmi_ime_sdk_get_curr_allow_input_mode_list_of_curr_writing_lang(mmi_imm_input_mode_enum *mode_array, S32 max)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(mode_array);
#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    return mmi_imm_get_curr_allow_input_mode_list_of_curr_writing_lang(mode_array, max);
#else
    return mmi_imm_get_curr_allow_input_mode_list(mode_array, max);
#endif
}


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
S32 mmi_ime_sdk_get_current_allowed_writing_language_num(void)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    return mmi_imm_get_current_allowed_writing_language_num();
#else
    return 0;
#endif
}


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
MMI_BOOL mmi_ime_sdk_is_change_language_disabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_change_lang_disabled = MMI_FALSE;
    mmi_imc_message_struct msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&msg, 0, sizeof(msg));
    msg.message_id = MMI_IMC_MESSGAE_IS_WRITING_LANG_SELECTION_SCREEN_DISABLED;

    is_change_lang_disabled = (MMI_BOOL)mmi_imc_send_message(&msg);    
    
    return is_change_lang_disabled;
}


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
void mmi_ime_sdk_entry_change_language_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
    mmi_imc_key_entry_change_language_screen();
#else
    return;
#endif
}


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
void mmi_ime_sdk_register_setting_callback(mmi_ime_sdk_setting_funcptr setting_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ime_sdk_setting_cb_func = setting_cb;
}


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
void mmi_ime_sdk_call_setting_cb(mmi_id parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ime_sdk_setting_cb_func == NULL)
    {
        MMI_ASSERT(0);
    }

    g_ime_sdk_setting_cb_func(parent_gid);
}

#endif


/* Cstar requires new APIS  */

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_check_ui_style
 * DESCRIPTION
 *  To check if the specific UI style is enabled or not 
 * PARAMETERS
 *  style_flag     :   [IN]    style flag to be checked, MMI_IMC_UI_STYLE_VK_ON 
 *                             or MMI_IMC_UI_STYLE_FLOAT_ON
 * RETURNS
 *  MMI_TRUE       :           The UI style to be checked is enabled      
 *  MMI_FALSE      :           The UI style to be checked is disabled
 *****************************************************************************/
MMI_BOOL mmi_ime_sdk_check_ui_style(U32 style_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_imc_get_ui_style(style_flag);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_config_ui_style
 * DESCRIPTION
 *  To config specific UI style to be enable or not
 *   
 * PARAMETERS
 *  ui_style     :   [IN]    ui style to be configed, MMI_IMC_UI_STYLE_VK_ON 
 *                           or MMI_IMC_UI_STYLE_FLOAT_ON
 *  is_on        :   [IN]    if the UI style enable or not
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_sdk_config_ui_style(U32 ui_style, MMI_BOOL is_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_config_ui_style(ui_style, is_on);
}


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
MMI_BOOL mmi_ime_sdk_is_ime_connected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_imc_is_connected();
}


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
mmi_imm_keypadtype_enum mmi_ime_sdk_get_keyboard_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_imm_get_keyboard_type();
}

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
void mmi_ime_sdk_set_curr_input_style(mmi_imc_pen_input_style_enum input_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_IME_FTE_ENHANCE__)
    mmi_imc_pen_set_curr_input_style(input_style);
    #endif
}

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
void mmi_ime_sdk_enable_single_block_hw(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __MMI_IME_V3__
	    mmi_imc_pen_vk_enable_single_block_hw(MMI_TRUE);
	#else
		mmi_imc_pen_vk_enable_single_block_hw();
	#endif
}


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
 void mmi_ime_sdk_stop_single_block_handwriting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_pen_stop_singleblock_handwriting();
}

#endif



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
MMI_BOOL mmi_ime_sdk_is_handwriting_disabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    return mmi_imc_is_handwriting_disabled();
}




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
void mmi_ime_sdk_cancel_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    mmi_imc_cancel_timer();
}

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
void mmi_ime_sdk_confirm_handwriting_selection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    mmi_imc_pen_confirm_handwriting_selection();
}


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
mmi_ime_word_capital_state_enum mmi_ime_sdk_get_candidate_case_before_cursor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    return mmi_imc_get_candidate_case_before_cursor();
}

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
void mmi_ime_sdk_redraw_ime_indicator(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_redraw_ime_indicator();
}


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
void mmi_ime_sdk_select_candidate_from_candidate_box(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_select_candidate_from_candidate_box();    
}


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
void mmi_ime_sdk_common_arrow_key_handler(mmi_imc_key_custom_value key_code, U16 event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_key_common_arrow_key_handler(key_code, event_type);
}


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

MMI_BOOL mmi_ime_sdk_change_input_mode_according_to_capital_state(mmi_ime_word_capital_state_enum capital_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_imc_change_input_mode_according_to_capital_state(capital_state);
}


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
void mmi_ime_sdk_default_key_down()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_imc_key_group_key_down();      
}


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
void mmi_ime_sdk_default_key_long()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_imc_key_group_key_long();      
}


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
void mmi_ime_sdk_default_key_up()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_imc_key_group_key_up();      
}


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
mmi_ime_word_capital_state_enum mmi_ime_sdk_get_curr_capital_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_imc_get_global_data()->capital_state;  
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_sdk_set_curr_capital_state
 * DESCRIPTION
 *  To config the current capital state of IME
 * PARAMETERS
 *  capital_state      :      the capital state enum,
 *                            MMI_IME_WORD_CAPITAL_STATE_NONE,
 *                            MMI_IME_WORD_CAPITAL_STATE_LOWER,
 *                            MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER,
 *                            MMI_IME_WORD_CAPITAL_STATE_UPPER,
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_sdk_set_curr_capital_state(mmi_ime_word_capital_state_enum capital_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_get_global_data()->capital_state = capital_state;  
}



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
MMI_BOOL mmi_ime_sdk_is_capital_lock_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_imc_get_global_data()->capital_lock;  
}


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
void mmi_ime_sdk_config_capital_lock_enable(MMI_BOOL isenable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_get_global_data()->capital_lock = isenable; 
}
#endif


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
MMI_BOOL mmi_ime_sdk_is_in_venus_ui_engine_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_VUI_ENGINE__
    return (MMI_BOOL)vadp_p2v_uc_is_in_venus();
    #else
    return MMI_FALSE;
    #endif
}




#endif /* __MMI_IME_PLUG_IN__ */


