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
 *   wgui_inputs_dialer.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   wgui layer of dialer inputbox
 *
 * Author:
 * -------
 * -------
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include 
 *****************************************************************************/
//#include "mmi_frm_gprot.h"
#include "wgui_inputs_internal.h"
#include "gui_font_size.h"

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
#include "ImeQwertyProt.h"
#endif /* __MMI_QWERTY_KEYPAD_SUPPORT__ */


    #include "gui_inputs.h"
    #include "MMI_features.h"
    #include "gui.h"
    #include "MMIDataType.h"
    #include "gui_config.h"
    #include "wgui_categories_list.h"
    #include "wgui_categories_inputs.h"
    #include "gui_data_types.h"
    #include "kal_general_types.h"
    #include "wgui_inputs.h"
    #include "PixcomFontEngine.h"
    #include "string.h"
    #include "Unicodexdcl.h"
    #include "gui_themes.h"
    #include "CustThemesRes.h"
    #include "GlobalConstants.h"
    #include "mmi_frm_input_gprot.h"
    #include "wgui.h"
    #include "TimerEvents.h"
    #include "mmi_frm_timer_gprot.h"
    #include "gdi_include.h"
    #include "mmi_rp_app_uiframework_def.h"
    #include "wgui_categories_util.h"
    #include "gui_typedef.h"
    #include "GlobalResDef.h"
    #include "wgui_include.h"
    #include "kal_public_api.h"
    #include "custom_hw_default.h"
    
    #include "lcd_sw_inc.h"
    #include "Gui_Setting.h"

    #include "gui_touch_feedback.h"
    
/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
dialer_input_box MMI_dialer_inputbox;

#ifdef __MMI_TOUCH_DIAL_SCREEN__
dialing_keypad_struct dialing_keypad;
#endif /* __MMI_TOUCH_DIAL_SCREEN__ */ 

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__

#define WGUI_INPUTS_DIALER_KEY_MAX_CHAR     5
#define WGUI_INPUTS_DIALER_ALLOW_MAX_CHAR   15

static UI_character_type g_wgui_inputs_dialer_allow_char[WGUI_INPUTS_DIALER_ALLOW_MAX_CHAR] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '*', '#', '+', 'p', 'w'};
//static UI_character_type g_wgui_inputs_dialer_qwerty_multitap_char[WGUI_INPUTS_DIALER_ALLOW_MAX_CHAR];
//static UI_character_type g_wgui_inputs_dialer_qwerty_multitap_star_char[WGUI_INPUTS_DIALER_ALLOW_MAX_CHAR] = {'*', '+', 'p', 'w'};
#endif
#ifdef __MMI_EDITOR_DIALER_SUPPORT__

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
static UI_character_type g_wgui_inputs_dialer_qwerty_multitap_char[WGUI_INPUTS_DIALER_ALLOW_MAX_CHAR];
static UI_character_type g_wgui_inputs_dialer_qwerty_multitap_star_char[WGUI_INPUTS_DIALER_ALLOW_MAX_CHAR] = {'*', '+', 'p', 'w'};
#endif
void (*dialer_inputbox_input_callback) (void) = UI_dummy_function;
#if 0/* slim_2_2 */ //
/* under construction !*/
#endif

S32 wgui_dialer_inputbox_buffer_size = 0;
U8 wgui_dialer_inputbox_plus_character_flag = 0;

#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_DIALER_INPUTBOX_FRAME_SKIPPING))
S32 wgui_dialer_inputbox_frame_counter = 0;
#endif 

/* to store the zero key hander for idleScreenDigitHandler */
FuncPtr storeZeroKeyFuncPtrs[1][4];

/* struxcture handle star key input in dialer box */
multitap_input wgui_dialer_box_star_key_handler;

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
/* struxcture handle qwerty key input in dialer box */
multitap_input wgui_dialer_box_qwerty_key_handler;
#endif

#if(ENABLE_DIALER_ZERO_KEY_MULTITAP)
multitap_input wgui_dialer_box_zero_key_handler;
#endif 
U8 wgui_dialer_box_active_multitap = WGUI_DIALER_BOX_ACTIVE_MULTITAP_NONE;

#if(ENABLE_DIALER_ZERO_KEY_MULTITAP)
UI_character_type wgui_dialer_box_star_key_string[] = { '*', 'p', 'w', '\0' };

/* for multitap zero Key */
#ifdef __MMI_MULTITAP_KEY_0__
UI_character_type wgui_dialer_box_zero_key_string[] = { '+', 'p', 'w', '\0' };
#else 
UI_character_type wgui_dialer_box_zero_key_string[] = { '0', '+', '\0' };
#endif 
#else /* (ENABLE_DIALER_ZERO_KEY_MULTITAP) */ 
UI_character_type wgui_dialer_box_star_key_string[] = { '*', '+', 'p', 'w', '\0' };
#endif /* (ENABLE_DIALER_ZERO_KEY_MULTITAP) */ 

void (*wgui_dialer_inputbox_RSK_function) (void) = NULL;

U8 wgui_dialer_inputbox_RSK_label_clear = 0;

/* store the string of RSK of dialer input box */
UI_string_type wgui_dialer_inputbox_RSK_label_string;

/* store the icon of RSK of dialer input box */
PU8 wgui_dialer_inputbox_RSK_label_icon;

/* used to keep tarck of decimal input in dialer input box */
U8 wgui_dialer_inputbox_decimal_flag = 0;

/* used to chekc if decimal input is enable for dialer box or not */
U8 wgui_dialer_inputbox_decimal_input_mode_flag = 0;

MMI_BOOL wgui_dialer_inputbox_zero_ley_long_press_flag = MMI_FALSE;

/* Popup then long press 0 to input multitap character, the former char will be deleted (MAUI_01111349). */
#if(ENABLE_DIALER_ZERO_KEY_MULTITAP)
static MMI_BOOL g_dialer_is_zero_inputed = MMI_FALSE;
#endif

static void wgui_inputs_dialer_handle_left_arrow_repeat(void);
static void wgui_inputs_dialer_handle_right_arrow_repeat(void);
static void wgui_inputs_dialer_handle_up_arrow_repeat(void);
static void wgui_inputs_dialer_handle_down_arrow_repeat(void);
static void wgui_inputs_dialer_handle_right_softkey_repeat(void);
static void wgui_inputs_dialer_handle_right_softkey_touch_repeat(void);

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
static void wgui_inputs_dialer_multitap_handle_qwerty_key_down(void);
static void wgui_inputs_dialer_multitap_handle_qwerty_key_up(void);
static void wgui_inputs_dialer_multitap_complete_qwerty_key(void);
static void wgui_inputs_dialer_qwerty_multitap_key_down_time_callback(void);

#define MMI_QWERTY_DIALER_KEY_DOWN_TIME_OUT              50

/* Save current key down key code */
static S16 g_qwerty_multitap_key_down_key_code = KEY_INVALID;
#endif

static void (*wgui_inputs_dialer_star_key_up_callback) (void) = NULL;

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

#if 0/* slim_2_2 */ //
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
    #if 0/* slim_2_2 */ //
/* under construction !*/
    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_DIALER_INPUTBOX_FRAME_SKIPPING))
/* under construction !*/
#endif 
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_create_set_buffer
 * DESCRIPTION
 *  Creates a dialer inputbox
 * PARAMETERS
 *  buffer              [IN]        
 *  buffer_length       [IN]        
 *  text_length         [IN]        
 *  edit_position       [IN]        
 * RETURNS
 *  void
 * VJ
 *****************************************************************************/
void wgui_inputs_dialer_create_set_buffer(UI_string_type buffer, S32 buffer_length, S32 text_length, S32 edit_position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_dialer_inputbox_plus_character_flag = 0;
    wgui_dialer_inputbox_buffer_size = buffer_length;
    dialer_inputbox_input_callback = UI_dummy_function;
    #if 0/* slim_2_2 */ //
/* under construction !*/
    #endif
    /* Warning: Temporary change only UCS2 / ASCII. This has to be done in a more formal manner  */
#ifdef __UCS2_ENCODING
    gui_create_dialer_input_box_set_buffer(
        &MMI_dialer_inputbox,
        MMI_general_inputbox_x,
        MMI_general_inputbox_y,
        MMI_general_inputbox_width,
        MMI_general_inputbox_height,
        buffer,
        buffer_length * 2,
        (text_length + 1) * 2,
        edit_position);
#endif /* __UCS2_ENCODING */ 
#ifdef __ASCII
    gui_create_dialer_input_box_set_buffer(
        &MMI_dialer_inputbox,
        MMI_dialer_inputbox_x,
        MMI_dialer_inputbox_y,
        MMI_dialer_inputbox_width,
        MMI_dialer_inputbox_height,
        buffer,
        buffer_length,
        text_length + 1,
        edit_position);
#endif /* __ASCII */ 
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_DIALER_INPUTBOX_FRAME_SKIPPING))
    wgui_dialer_inputbox_frame_counter = 0;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_show
 * DESCRIPTION
 *  Displays the dialer inputbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_show_dialer_input_box(&MMI_dialer_inputbox);
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_BLT_double_buffer(
        MMI_dialer_inputbox.x,
        MMI_dialer_inputbox.y,
        MMI_dialer_inputbox.x + MMI_dialer_inputbox.width,
        MMI_dialer_inputbox.y + MMI_dialer_inputbox.height);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}

#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_DIALER_INPUTBOX_FRAME_SKIPPING))


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_end_frame
 * DESCRIPTION
 *  Redraws the dialer inputbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_end_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_dialer_inputbox_frame_counter >= 1)
    {
        gui_show_dialer_input_box(&MMI_dialer_inputbox);
    #if(UI_DOUBLE_BUFFER_SUPPORT)
        gui_BLT_double_buffer(
            MMI_dialer_inputbox.x,
            MMI_dialer_inputbox.y,
            MMI_dialer_inputbox.x + MMI_dialer_inputbox.width,
            MMI_dialer_inputbox.y + MMI_dialer_inputbox.height);
    #endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
        wgui_dialer_inputbox_frame_counter = 0;
        gui_start_timer(UI_FRAME_SKIP_TIMEOUT, wgui_inputs_dialer_end_frame);
    }
}

#endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_DIALER_INPUTBOX_FRAME_SKIPPING)) */ 


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_redraw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_redraw(void)
{
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_DIALER_INPUTBOX_FRAME_SKIPPING))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_dialer_inputbox_frame_counter > 0)
    {
        wgui_dialer_inputbox_frame_counter++;
    }
    else
    {
        wgui_dialer_inputbox_frame_counter = 1;
        gui_start_timer(UI_FRAME_START_TIMEOUT, wgui_inputs_dialer_end_frame);
    }
#else /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_DIALER_INPUTBOX_FRAME_SKIPPING)) */ 

    gui_show_dialer_input_box(&MMI_dialer_inputbox);
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_BLT_double_buffer(
        MMI_dialer_inputbox.x,
        MMI_dialer_inputbox.y,
        MMI_dialer_inputbox.x + MMI_dialer_inputbox.width,
        MMI_dialer_inputbox.y + MMI_dialer_inputbox.height);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 

#endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_DIALER_INPUTBOX_FRAME_SKIPPING)) */ 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_handle_plus_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_handle_plus_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_dialer_inputbox.text[0] == '+')
    {
        if (MMI_dialer_inputbox.text != MMI_dialer_inputbox.current_text_p)
        {
            MMI_dialer_inputbox.available_length = (wgui_dialer_inputbox_buffer_size + 1) * ENCODING_LENGTH;
            wgui_dialer_inputbox_plus_character_flag = 1;
        }
    }
    else
    {
        if (wgui_dialer_inputbox_plus_character_flag)
        {
            U8 done = 0;
            UI_buffer_type current_position = MMI_dialer_inputbox.text;
            UI_buffer_type previous_position = MMI_dialer_inputbox.text;
            UI_character_type c;

            wgui_dialer_inputbox_plus_character_flag = 0;
            MMI_dialer_inputbox.available_length = wgui_dialer_inputbox_buffer_size * ENCODING_LENGTH;
            if (MMI_dialer_inputbox.text_length > MMI_dialer_inputbox.allocated_length)
            {
                MMI_dialer_inputbox.text_length -= ENCODING_LENGTH;
                UI_STRING_GET_NEXT_CHARACTER(current_position, c);
                while (!done)
                {
                    UI_STRING_GET_NEXT_CHARACTER(current_position, c);
                    UI_STRING_INSERT_CHARACTER(previous_position, c);
                    if (UI_STRING_END_OF_STRING_CHARACTER(c))
                    {
                        done = 1;
                    }
                }

                UI_STRING_GET_PREVIOUS_CHARACTER(previous_position, c);
                MMI_dialer_inputbox.last_position_p = previous_position;
                if (MMI_dialer_inputbox.current_text_p != MMI_dialer_inputbox.text)
                {
                    UI_STRING_GET_PREVIOUS_CHARACTER(MMI_dialer_inputbox.current_text_p, c);
                }

#ifdef __MMI_FIXED_DIALER_FONT__
                gui_dialer_input_box_refresh_for_fixed_font(&MMI_dialer_inputbox);
#endif

            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_multitap_input
 * DESCRIPTION
 *  Inserts a multitap character
 *  
 *  Normally called by multitap objects
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_multitap_input(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Handle plus key */
    if ((c == '+') && (MMI_dialer_inputbox.text[0] != '+') && (MMI_dialer_inputbox.current_text_p == MMI_dialer_inputbox.text) && (MMI_dialer_inputbox.text_length >= MMI_dialer_inputbox.available_length))
    {
        MMI_dialer_inputbox.available_length = (wgui_dialer_inputbox_buffer_size + 1) * ENCODING_LENGTH;
    }
    else if (MMI_dialer_inputbox.available_length == (wgui_dialer_inputbox_buffer_size + 1) * ENCODING_LENGTH)
    {
        if (MMI_dialer_inputbox.text_length == MMI_dialer_inputbox.available_length)
        {
            if (MMI_dialer_inputbox.flags & UI_DIALER_INPUT_BOX_STATE_MULTITAP)
            {
                if (MMI_dialer_inputbox.current_text_p == MMI_dialer_inputbox.text + ENCODING_LENGTH)
                {
                    if (c != '+')
                    {
                        wgui_inputs_dialer_delete_character();
                        /* Delete character will clear UI_DIALER_INPUT_BOX_STATE_MULTITAP, if don't set back, the timer callback
                        wgui_inputs_dialer_multitap_complete_zero_key can't be cancelled in wgui_inputs_dialer_handle_multitap_complete
                        when Exit current screen, issue happens */
                        MMI_dialer_inputbox.flags |= UI_DIALER_INPUT_BOX_STATE_MULTITAP;
                        UI_editor_play_tone_cannot_insert();
                        return;
                    }
                }
            }
            else if (MMI_dialer_inputbox.current_text_p == MMI_dialer_inputbox.text + ENCODING_LENGTH)
            {
                if (c != '+')
                {
                    MMI_dialer_inputbox.flags |= UI_DIALER_INPUT_BOX_STATE_MULTITAP;
                    UI_editor_play_tone_cannot_insert();
                    return;
                }
            }
        }
        else if ((MMI_dialer_inputbox.text_length == MMI_dialer_inputbox.available_length - ENCODING_LENGTH) &&
                (c != '+') && (MMI_dialer_inputbox.current_text_p == MMI_dialer_inputbox.text))
        {
            MMI_dialer_inputbox.flags |= UI_DIALER_INPUT_BOX_STATE_MULTITAP;
            UI_editor_play_tone_cannot_insert();
            return;
        }
    }
    else if ((MMI_dialer_inputbox.text_length == MMI_dialer_inputbox.available_length) &&
            (MMI_dialer_inputbox.current_text_p == MMI_dialer_inputbox.text) &&
            (MMI_dialer_inputbox.available_length == wgui_dialer_inputbox_buffer_size * ENCODING_LENGTH) &&
            (c != '+'))
	{
        MMI_dialer_inputbox.flags |= UI_DIALER_INPUT_BOX_STATE_MULTITAP;
        UI_editor_play_tone_cannot_insert();
		return;
	}

    if (MMI_dialer_inputbox.text[0] == '+')
    {
        if ((MMI_dialer_inputbox.text != MMI_dialer_inputbox.current_text_p) ||
            (c == '+'))
        {
            MMI_dialer_inputbox.available_length = (wgui_dialer_inputbox_buffer_size + 1) * ENCODING_LENGTH;
            wgui_dialer_inputbox_plus_character_flag = 1;
        }
    }
    
    gui_dialer_input_box_insert_multitap_character(&MMI_dialer_inputbox, c);
    if (MMI_dialer_inputbox.flags & UI_DIALER_INPUT_BOX_PLUS_CHARACTER_HANDLING)
    {
        wgui_inputs_dialer_handle_plus_key();
    }
    wgui_inputs_dialer_redraw();
    dialer_inputbox_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_multitap_input_complete
 * DESCRIPTION
 *  Completes a multitap input sequence
 *  
 *  Normally called by multitap objects
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_multitap_input_complete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_dialer_input_box_confirm_multitap_character(&MMI_dialer_inputbox);
    if (MMI_dialer_inputbox.flags & UI_DIALER_INPUT_BOX_PLUS_CHARACTER_HANDLING)
    {
        wgui_inputs_dialer_handle_plus_key();
    }
    wgui_inputs_dialer_redraw();
    dialer_inputbox_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_direct_input
 * DESCRIPTION
 *  inserts a character at cursor position
 *  
 *  Normally registered to a keyboard input handler
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_direct_input(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((MMI_dialer_inputbox.text[0] == '+') || (c == '+'))
    {
        MMI_dialer_inputbox.available_length = (wgui_dialer_inputbox_buffer_size + 1) * ENCODING_LENGTH;
        wgui_dialer_inputbox_plus_character_flag = 1;
    }

    /* If + is at the starting place followed by 40 number, it should not allow to insert any character before and after + */
    if ((MMI_dialer_inputbox.text[0] == '+') &&
        (((MMI_dialer_inputbox.current_text_p == MMI_dialer_inputbox.text) &&
          (MMI_dialer_inputbox.text_length == (MMI_dialer_inputbox.available_length - ENCODING_LENGTH))) ||
         ((MMI_dialer_inputbox.current_text_p == (MMI_dialer_inputbox.text + ENCODING_LENGTH)) &&
          (MMI_dialer_inputbox.text_length == MMI_dialer_inputbox.available_length))))
    {
        UI_editor_play_tone_cannot_insert();
        return;
    }

    gui_dialer_input_box_insert_character(&MMI_dialer_inputbox, c);

#if(ENABLE_DIALER_ZERO_KEY_MULTITAP)
    if (c == '0')
    {
        g_dialer_is_zero_inputed = MMI_TRUE;
    }
#endif

    if (MMI_dialer_inputbox.flags & UI_DIALER_INPUT_BOX_PLUS_CHARACTER_HANDLING)
    {
        wgui_inputs_dialer_handle_plus_key();
    }
    wgui_inputs_dialer_redraw();
    dialer_inputbox_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_delete_character
 * DESCRIPTION
 *  deletes a character at cursor position
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_delete_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_dialer_input_box_delete_character(&MMI_dialer_inputbox);
    if (MMI_dialer_inputbox.flags & UI_DIALER_INPUT_BOX_PLUS_CHARACTER_HANDLING)
    {
        wgui_inputs_dialer_handle_plus_key();
    }
    wgui_inputs_dialer_redraw();
    dialer_inputbox_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_previous_character
 * DESCRIPTION
 *  Moves the cursor to the previous character
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_previous_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_dialer_handle_multitap_complete(WGUI_DIALER_BOX_ACTIVE_MULTITAP_ANY);
    gui_dialer_input_box_previous(&MMI_dialer_inputbox);
    wgui_inputs_dialer_redraw();
    #if 0/* slim_2_2 */ //
/* under construction !*/
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_next_character
 * DESCRIPTION
 *  Moves the cursor to the next character
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_next_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_dialer_handle_multitap_complete(WGUI_DIALER_BOX_ACTIVE_MULTITAP_ANY);
    gui_dialer_input_box_next(&MMI_dialer_inputbox);
    wgui_inputs_dialer_redraw();
    #if 0/* slim_2_2 */ //
/* under construction !*/
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_toggle_insert_mode
 * DESCRIPTION
 *  Toggles between insert and overwrite modes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_toggle_insert_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_dialer_input_box_toggle_insert_mode(&MMI_dialer_inputbox);
    wgui_inputs_dialer_redraw();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_delete_current_character
 * DESCRIPTION
 *  Deletes a character at the cursor position (Delete)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_delete_current_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_dialer_input_box_delete_current_character(&MMI_dialer_inputbox);
    if (MMI_dialer_inputbox.flags & UI_DIALER_INPUT_BOX_PLUS_CHARACTER_HANDLING)
    {
        wgui_inputs_dialer_handle_plus_key();
    }
    wgui_inputs_dialer_redraw();
    dialer_inputbox_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_delete_all_characters
 * DESCRIPTION
 *  Deletes all characters
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_delete_all_characters(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_dialer_input_box_delete_all(&MMI_dialer_inputbox);
    if (MMI_dialer_inputbox.flags & UI_DIALER_INPUT_BOX_PLUS_CHARACTER_HANDLING)
    {
        wgui_inputs_dialer_handle_plus_key();
    }
    wgui_inputs_dialer_redraw();
    dialer_inputbox_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_alphabetic_keyboard_input_handler
 * DESCRIPTION
 *  alphanumeric keyboard input handler
 *  
 *  Internal function
 * PARAMETERS
 *  keyc        [IN]        Is the character code of a key (ASCII)
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_alphabetic_keyboard_input_handler(S32 keyc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (keyc > 0x1f)
    {
        wgui_inputs_dialer_direct_input((U8) keyc);
    }
    else if (keyc == 0x08)
    {
        wgui_inputs_dialer_delete_character();
    }
    else if (keyc == 0x1b)
    {
        wgui_inputs_dialer_delete_all_characters();
    }
    else if (keyc == 0x0d);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_numeric_keyboard_input_handler
 * DESCRIPTION
 *  numeric keyboard input handler
 *  
 *  Internal function
 * PARAMETERS
 *  keyc        [IN]        Is the character code of a key (ASCII)
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_numeric_keyboard_input_handler(S32 keyc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((keyc >= '0' && keyc <= '9') || (keyc == '-') || (keyc == '+') || (keyc == '*') || (keyc == '#'))
    {
        wgui_inputs_dialer_direct_input((UI_character_type) keyc);
    }
    else if (keyc == 0x08)
    {
        wgui_inputs_dialer_delete_character();
    }
    else if (keyc == 0x1b)
    {
        wgui_inputs_dialer_delete_all_characters();
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_next_line
 * DESCRIPTION
 *  move to next line of dialer inputr box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_next_line(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 y1, y2;
    S32 y_up;
    S32 character_height;
    mmi_fe_get_string_info_param_struct query;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_dialer_handle_multitap_complete(WGUI_DIALER_BOX_ACTIVE_MULTITAP_ANY);
    
#ifdef __MMI_FIXED_DIALER_FONT__
    {
        gui_dialer_input_box_next_line(&MMI_dialer_inputbox);
        wgui_inputs_dialer_redraw();
        return;
    }
#endif

    gui_set_font(MMI_dialer_inputbox.text_font);
    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    query.String = (U8*)MMI_dialer_inputbox.text;
    query.n = mmi_ucs2strlen((const char*)MMI_dialer_inputbox.text);
    query.enableTruncated = MMI_FALSE;
    query.w = MMI_dialer_inputbox.text_gap;
    mmi_fe_get_string_widthheight(&query);

    character_height = query.pHeight;

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    if (query.pHeight == query.baseline)
        character_height++;
#endif

#ifndef __MMI_COLOR_DIALLING_FONT__
    if (!(current_MMI_theme->dialer_inputbox_text_border_color->r == 0
        && current_MMI_theme->dialer_inputbox_text_border_color->g == 0
        && current_MMI_theme->dialer_inputbox_text_border_color->b == 255))
        character_height += 2;
#endif

    y1 = MMI_dialer_inputbox.y;
    y2 = y1 + MMI_dialer_inputbox.height - 1;
    y_up = y2 - character_height * (MMI_dialer_inputbox.n_lines - 1) - character_height/2;

    
    if (MMI_dialer_inputbox.n_lines > 1
        && MMI_dialer_inputbox.cursor_y > y_up)
    {
        gui_dialer_input_box_next_line(&MMI_dialer_inputbox);

        #if 0/* slim_2_2 */ //
/* under construction !*/
        #endif
    }
    else
    {
        UI_editor_play_tone_cannot_navigate();
    }
    wgui_inputs_dialer_redraw();  /* slim_2_2 */ //
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_previous_line
 * DESCRIPTION
 *  move to prev line of dialer inputr box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_previous_line(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 y1, y2;
    S32 y_last;
    S32 character_height;
    mmi_fe_get_string_info_param_struct query;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_dialer_handle_multitap_complete(WGUI_DIALER_BOX_ACTIVE_MULTITAP_ANY);
    
#ifdef __MMI_FIXED_DIALER_FONT__
    {
        gui_dialer_input_box_prev_line(&MMI_dialer_inputbox);
        wgui_inputs_dialer_redraw();
        return;
    }
#endif

    gui_set_font(MMI_dialer_inputbox.text_font);
    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    query.String = (U8*)MMI_dialer_inputbox.text;
    query.n = mmi_ucs2strlen((const char*)MMI_dialer_inputbox.text);
    query.enableTruncated = MMI_FALSE;
    query.w = MMI_dialer_inputbox.text_gap;
    mmi_fe_get_string_widthheight(&query);

    character_height = query.pHeight;

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    if (query.pHeight == query.baseline)
        character_height++;
#endif

#ifndef __MMI_COLOR_DIALLING_FONT__
    if (!(current_MMI_theme->dialer_inputbox_text_border_color->r == 0
        && current_MMI_theme->dialer_inputbox_text_border_color->g == 0
        && current_MMI_theme->dialer_inputbox_text_border_color->b == 255))
        character_height += 2;
#endif

    y1 = MMI_dialer_inputbox.y;
    y2 = y1 + MMI_dialer_inputbox.height - 1;
    y_last = y2 - character_height - 2;

#if( defined(__MMI_TOUCH_DIAL_SCREEN__))
    if ((MMI_dialer_inputbox.cursor_y + 1) < y_last && (MMI_dialer_inputbox.n_lines > 1))
#else
    if ((MMI_dialer_inputbox.cursor_y + 2) < y_last && (MMI_dialer_inputbox.n_lines > 1))
#endif
    {
        gui_dialer_input_box_prev_line(&MMI_dialer_inputbox);

        #if 0/* slim_2_2 */ //
/* under construction !*/
        #endif
    }
    else
    {
        UI_editor_play_tone_cannot_navigate();
    }
    wgui_inputs_dialer_redraw();  /* slim_2_2 */ //
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_key_handler
 * DESCRIPTION
 *  dialer input box key handlers
 * PARAMETERS
 *  vkey_code       [IN]        
 *  key_state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_key_handler(S32 vkey_code, S32 key_state)
{
#if(MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_state)
    {
        switch (vkey_code)
        {
            case 37:
                wgui_inputs_dialer_previous_character();
                break;
            case 38:
                wgui_inputs_dialer_next_line();    /* up */
                break;
            case 39:
                wgui_inputs_dialer_next_character();
                break;
            case 40:
                wgui_inputs_dialer_previous_line();    /* down */
                break;
            case 36:                            /* home */
                break;
            case 35:                            /* end */
                break;
            case 33:                            /* page up */
                break;
            case 34:                            /* page down */
                break;
            case 45:
                wgui_inputs_dialer_toggle_insert_mode();
                break;
            case 46:
                wgui_inputs_dialer_delete_current_character();
                break;
        }
    }
#else /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
    UI_UNUSED_PARAMETER(vkey_code);
    UI_UNUSED_PARAMETER(key_state);
#endif /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_register_keys
 * DESCRIPTION
 *  Registers the keys for the dialer inputbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_register_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(wgui_inputs_dialer_previous_character, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_inputs_dialer_next_character, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetKeyHandler(wgui_inputs_dialer_handle_left_arrow_repeat, KEY_LEFT_ARROW, KEY_REPEAT);
    SetKeyHandler(wgui_inputs_dialer_handle_right_arrow_repeat, KEY_RIGHT_ARROW, KEY_REPEAT);
    SetKeyHandler(wgui_inputs_fast_del_nav_reset_repeat_count, KEY_LEFT_ARROW, KEY_LONG_PRESS);
    SetKeyHandler(wgui_inputs_fast_del_nav_reset_repeat_count, KEY_RIGHT_ARROW, KEY_LONG_PRESS);

    /* SetKeyHandler(wgui_inputs_dialer_delete_character,KEY_CLEAR,KEY_EVENT_DOWN); */
    SetKeyHandler(wgui_inputs_dialer_next_line, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_inputs_dialer_previous_line, KEY_DOWN_ARROW, KEY_EVENT_DOWN);

    SetKeyHandler(wgui_inputs_dialer_handle_up_arrow_repeat, KEY_UP_ARROW, KEY_REPEAT);
    SetKeyHandler(wgui_inputs_dialer_handle_down_arrow_repeat, KEY_DOWN_ARROW, KEY_REPEAT);
    SetKeyHandler(wgui_inputs_fast_del_nav_reset_repeat_count, KEY_UP_ARROW, KEY_LONG_PRESS);
    SetKeyHandler(wgui_inputs_fast_del_nav_reset_repeat_count, KEY_DOWN_ARROW, KEY_LONG_PRESS);
    
    register_keyboard_key_handler(wgui_inputs_dialer_key_handler);
    /* Add key handlers here for Clear key and input mode key   */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_set_mask
 * DESCRIPTION
 *  Sets masked display of characters
 * PARAMETERS
 *  m       [IN]        0: Normal, 1: Masked
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_set_mask(U8 m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (m)
    {
        case 0:
            MMI_dialer_inputbox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_MASK_CHARACTERS;
            break;
        case 1:
            MMI_dialer_inputbox.flags |= UI_SINGLE_LINE_INPUT_BOX_MASK_CHARACTERS;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_reset
 * DESCRIPTION
 *  Removes the keyhandlers for the dialer inputbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_reset(void)
{
#if(UI_BLINKING_CURSOR_SUPPORT)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* gui_cancel_timer(UI_inputbox_blink_cursor); */
    StopTimer(BLINKING_CURSOR);

#endif /* (UI_BLINKING_CURSOR_SUPPORT) */ 
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_DIALER_INPUTBOX_FRAME_SKIPPING))
    gui_cancel_timer(wgui_inputs_dialer_end_frame);
    wgui_dialer_inputbox_frame_counter = 0;
#endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_DIALER_INPUTBOX_FRAME_SKIPPING)) */ 
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_UP);
    ClearKeyHandler(KEY_CLEAR, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_CLEAR, KEY_EVENT_UP);
    ClearKeyHandler(KEY_CLEAR, KEY_EVENT_LONG_PRESS);
    clear_keyboard_key_handler();
    clear_keyboard_input_handler();
    wgui_inputs_multitap_clear_key_handlers();
    dialer_inputbox_input_callback = UI_dummy_function;
    #if 0/* slim_2_2 */ //
/* under construction !*/
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_resize
 * DESCRIPTION
 *  Resizes the dialer input box
 * PARAMETERS
 *  width       [IN]        Is the new width
 *  height      [IN]        Is the new height
 * RETURNS
 *  void
 * VJ
 *****************************************************************************/
void wgui_inputs_dialer_resize(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_resize_dialer_input_box(&MMI_dialer_inputbox, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_move
 * DESCRIPTION
 *  Resizes the dialer input box
 * PARAMETERS
 *  x               [IN]        
 *  y               [IN]        
 *  width(?)        [IN]        Is the new width
 *  height(?)       [IN]        Is the new height
 * RETURNS
 *  void
 * VJ
 *****************************************************************************/
void wgui_inputs_dialer_move(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_move_dialer_input_box(&MMI_dialer_inputbox, x, y);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_register_input_callback
 * DESCRIPTION
 *  regsiter dialer input callback func
 * PARAMETERS
 *  f               [IN]        
 *  function(?)     [IN]        Pointer
 * RETURNS
 *  void
 * VJ
 *****************************************************************************/
void wgui_inputs_dialer_register_input_callback(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dialer_inputbox_input_callback = f;
}

#if 0/* slim_2_2 */ //
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
#endif

#ifdef __MMI_TOUCH_DIAL_SCREEN__




/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_show_dialing_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1          [IN]        
 *  y1          [IN]        
 *  width       [IN]        
 *  height      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_show_dialing_screen(S32 x1, S32 y1, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x2 = x1 + width - 1;

    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, UI_device_height - MMI_button_bar_height - 2);
#if defined(__MMI_FTE_SUPPORT_SLIM__)
    gdi_image_draw_resized(0, 0, UI_device_width, UI_device_height, get_image(IMG_DIALING_SCREEN));
#else /* __MMI_FTE_SUPPORT_SLIM__ */
    gui_show_image(x1, y1, (PU8) get_image(IMG_DIALING_SCREEN));
#endif /* __MMI_FTE_SUPPORT_SLIM__ */
    gdi_layer_pop_clip();
    gui_BLT_double_buffer(x1, y1, x2, UI_device_height - MMI_button_bar_height);
}

#endif /* __MMI_TOUCH_DIAL_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_change_callback
 * DESCRIPTION
 *  change callback funtion of dialer input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_change_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* to change the font size while the dialer box is too small to insert chars */
#ifndef __MMI_FIXED_DIALER_FONT__
    S32 text_width = 0, text_height = 0, i = 0, j = 0;
    S32 max_char_height_in_dialer_box = 0;
    UI_buffer_type b_text;
    S32 text_length, right_x, text_gap = MMI_dialer_inputbox.text_gap;
    UI_character_type ch;
    mmi_fe_get_string_info_param_struct query;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_dialer_inputbox.text_font = gui_font_get_type(GUI_FONT_SIZE_DIALER_LARGE);

#ifdef __MMI_FIXED_DIALER_FONT__
    return;
#endif

#ifndef __MMI_FIXED_DIALER_FONT__
    gui_lock_double_buffer();
    MMI_dialer_inputbox.flags |= UI_DIALER_INPUT_BOX_DISABLE_DRAW;
    gui_show_dialer_input_box(&MMI_dialer_inputbox);
    MMI_dialer_inputbox.flags &= ~UI_DIALER_INPUT_BOX_DISABLE_DRAW;
    gui_unlock_double_buffer();

    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    query.String = (U8*)MMI_dialer_inputbox.text;
    query.n = mmi_ucs2strlen((const char*)MMI_dialer_inputbox.text);
    query.enableTruncated = MMI_FALSE;
    query.w = text_gap;
    mmi_fe_get_string_widthheight(&query);
    
    text_height = query.pHeight;

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    if (query.pHeight <= (query.baseline + 2))
        text_height++;
#endif

#ifndef __MMI_COLOR_DIALLING_FONT__
    if (!(current_MMI_theme->dialer_inputbox_text_border_color->r == 0
        && current_MMI_theme->dialer_inputbox_text_border_color->g == 0
        && current_MMI_theme->dialer_inputbox_text_border_color->b == 255))
        text_height += 2;
#endif

    text_width = gui_get_character_width(0x31);
    right_x = (MMI_dialer_inputbox.width % (text_width + text_gap))/2;
    if (right_x == 0)
        right_x = (text_width + text_gap)/2;
    
    text_length = gui_dialer_input_box_get_text_length(&MMI_dialer_inputbox);
    b_text = MMI_dialer_inputbox.text;
    if (max_char_height_in_dialer_box < text_height)
    {
        max_char_height_in_dialer_box = text_height;
    }

    text_width = 0;
    for (i = 0; i < text_length; i++)
    {
        UI_STRING_GET_NEXT_CHARACTER(b_text, ch);
        text_width += gui_get_character_width(ch);
        text_width += MMI_dialer_inputbox.text_gap;
        if (text_width + 1 > MMI_dialer_inputbox.width - right_x*2)
        {
            if (max_char_height_in_dialer_box > 0)
            {
                if (++j >= (((MMI_dialer_inputbox.height - 1) / (max_char_height_in_dialer_box))))
                {
                    MMI_dialer_inputbox.text_font = (gui_font_get_type(GUI_FONT_SIZE_DIALER_SMALL));
                    break;
                }
                else
                {
                    text_width = gui_get_character_width(ch);
                    text_width += MMI_dialer_inputbox.text_gap;
                }
            }
        }
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_handle_multitap_complete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_handle_multitap_complete(S32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_dialer_box_active_multitap != WGUI_DIALER_BOX_ACTIVE_MULTITAP_NONE)
    {
        switch (wgui_dialer_box_active_multitap)
        {
            case WGUI_DIALER_BOX_ACTIVE_MULTITAP_STAR_KEY:
                if (type == WGUI_DIALER_BOX_ACTIVE_MULTITAP_STAR_KEY)
                {
                    gui_cancel_timer(wgui_inputs_dialer_multitap_complete_star_key);
                    return;
                }
                if (MMI_dialer_inputbox.flags & UI_DIALER_INPUT_BOX_STATE_MULTITAP)
                {
                    gui_cancel_timer(wgui_inputs_dialer_multitap_complete_star_key);
                    gui_multitap_input_complete(&wgui_dialer_box_star_key_handler);
                }
                break;
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
            case WGUI_DIALER_BOX_ACTIVE_MULTITAP_QWERTY_KEY:
                if (type == WGUI_DIALER_BOX_ACTIVE_MULTITAP_QWERTY_KEY)
                {
                    gui_cancel_timer(wgui_inputs_dialer_multitap_complete_qwerty_key);
                    return;
                }
                if (MMI_dialer_inputbox.flags & UI_DIALER_INPUT_BOX_STATE_MULTITAP)
                {
                    gui_cancel_timer(wgui_inputs_dialer_multitap_complete_qwerty_key);
                    gui_multitap_input_complete(&wgui_dialer_box_qwerty_key_handler);
                }
                break;
#endif
            #if(ENABLE_DIALER_ZERO_KEY_MULTITAP)
            case WGUI_DIALER_BOX_ACTIVE_MULTITAP_ZERO_KEY:
                if (type == WGUI_DIALER_BOX_ACTIVE_MULTITAP_ZERO_KEY)
                {
                    gui_cancel_timer(wgui_inputs_dialer_multitap_complete_zero_key);
                    return;
                }
                if (MMI_dialer_inputbox.flags & UI_DIALER_INPUT_BOX_STATE_MULTITAP)
                {
                    gui_cancel_timer(wgui_inputs_dialer_multitap_complete_zero_key);
                    gui_multitap_input_complete(&wgui_dialer_box_zero_key_handler);
                    /* to store the zero key hander for idleScreenDigitHandler.... */
                    {
                        SetKeyHandler(storeZeroKeyFuncPtrs[KEY_0][KEY_EVENT_DOWN], KEY_0, KEY_EVENT_DOWN);
                        SetKeyHandler(storeZeroKeyFuncPtrs[KEY_0][KEY_EVENT_UP], KEY_0, KEY_EVENT_UP);
                        SetKeyHandler(storeZeroKeyFuncPtrs[KEY_0][KEY_LONG_PRESS], KEY_0, KEY_LONG_PRESS);
                        SetKeyHandler(UI_dummy_function, KEY_0, KEY_REPEAT);
                    }
                    /* SetKeyHandler(MMI_key_0_down,KEY_0,KEY_EVENT_DOWN); */
                }
                break;
            #endif /* (ENABLE_DIALER_ZERO_KEY_MULTITAP) */ 
        }
        wgui_dialer_box_active_multitap = WGUI_DIALER_BOX_ACTIVE_MULTITAP_NONE;
    }
    
    if (type == WGUI_DIALER_BOX_ACTIVE_MULTITAP_ANY)
    {
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__                
        gui_cancel_timer(wgui_inputs_dialer_multitap_complete_qwerty_key);                
#endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_handle_key_down
 * DESCRIPTION
 *  Function handles a key down wvwnt of dialer input box
 * PARAMETERS
 *  k           [IN]        
 *  S32(?)      [IN]        MMI_key_code_type :- Key code
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_handle_key_down(MMI_key_code_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_dialer_handle_multitap_complete(WGUI_DIALER_BOX_ACTIVE_MULTITAP_ANY);
    wgui_inputs_dialer_direct_input((UI_character_type) ('0' + k));
#if(ENABLE_DIALER_ZERO_KEY_MULTITAP)
    if (k == KEY_0)
    {
        SetKeyHandler(wgui_inputs_dialer_handle_zero_key_long_press, KEY_0, KEY_REPEAT);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_handle_key_up
 * DESCRIPTION
 *  Function handles a key up wvwnt of dialer input box
 * PARAMETERS
 *  k           [IN]        
 *  S32(?)      [IN]        MMI_key_code_type :- Key code
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_handle_key_up(MMI_key_code_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(ENABLE_DIALER_ZERO_KEY_MULTITAP)
    if (k == KEY_0)
    {
        g_dialer_is_zero_inputed = MMI_FALSE;
    }
#endif

    if ((k == KEY_STAR) && (wgui_inputs_dialer_star_key_up_callback != NULL))
    {
        wgui_inputs_dialer_star_key_up_callback();
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_multitap_complete_star_key
 * DESCRIPTION
 *  Function handles a multitap star key down input and draw the dialer input box
 * PARAMETERS
 *  void
 *  noen(?)     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_multitap_complete_star_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_multitap_input_complete(&wgui_dialer_box_star_key_handler);
}


#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_multitap_complete_qwerty_key
 * DESCRIPTION
 *  Function handles a multitap qwerty key down input and draw the dialer input box
 * PARAMETERS
 *  void
 *  noen(?)     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inputs_dialer_multitap_complete_qwerty_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_multitap_input_complete(&wgui_dialer_box_qwerty_key_handler);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_multitap_handle_qwerty_key_down
 * DESCRIPTION
 *  Function handles a multitap qwerty key down input of dialer box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inputs_dialer_multitap_handle_qwerty_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_dialer_handle_multitap_complete(WGUI_DIALER_BOX_ACTIVE_MULTITAP_QWERTY_KEY);
    wgui_dialer_box_active_multitap = WGUI_DIALER_BOX_ACTIVE_MULTITAP_QWERTY_KEY;
    gui_change_multitap_input_state(&wgui_dialer_box_qwerty_key_handler);
    if (MMI_dialer_inputbox.text_length <= 2)
    {
        gui_start_timer(MMI_MULTITAP_TIMEOUT, wgui_inputs_dialer_multitap_complete_qwerty_key);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_multitap_handle_qwerty_key_up
 * DESCRIPTION
 *  Function handles a multitap qwerty key up input of dialer box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_multitap_handle_qwerty_key_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_start_timer(MMI_MULTITAP_TIMEOUT, wgui_inputs_dialer_multitap_complete_qwerty_key);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_multitap_handle_star_key_down
 * DESCRIPTION
 *  Function handles a multitap star key down input of dialer box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_multitap_handle_star_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_dialer_handle_multitap_complete(WGUI_DIALER_BOX_ACTIVE_MULTITAP_STAR_KEY);
    wgui_dialer_box_active_multitap = WGUI_DIALER_BOX_ACTIVE_MULTITAP_STAR_KEY;
    gui_change_multitap_input_state(&wgui_dialer_box_star_key_handler);
    if (MMI_dialer_inputbox.text_length <= 2)
    {
        gui_start_timer(MMI_MULTITAP_TIMEOUT, wgui_inputs_dialer_multitap_complete_star_key);
    }

    SetKeyHandler(wgui_inputs_dialer_multitap_handle_star_key_down, KEY_STAR, KEY_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_multitap_handle_star_key_up
 * DESCRIPTION
 *  Function handles a multitap star key up input of dialer box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_multitap_handle_star_key_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_start_timer(MMI_MULTITAP_TIMEOUT, wgui_inputs_dialer_multitap_complete_star_key);

    if (wgui_inputs_dialer_star_key_up_callback != NULL)
    {
        wgui_inputs_dialer_star_key_up_callback();
    }
}

#if(ENABLE_DIALER_ZERO_KEY_MULTITAP)


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_multitap_complete_zero_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_multitap_complete_zero_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_multitap_input_complete(&wgui_dialer_box_zero_key_handler);
#ifdef __MMI_MULTITAP_KEY_0__
    /* to store the zero key hander for idleScreenDigitHandler.... */
    {
        SetKeyHandler(storeZeroKeyFuncPtrs[KEY_0][KEY_EVENT_DOWN], KEY_0, KEY_EVENT_DOWN);
        SetKeyHandler(storeZeroKeyFuncPtrs[KEY_0][KEY_EVENT_UP], KEY_0, KEY_EVENT_UP);
        SetKeyHandler(storeZeroKeyFuncPtrs[KEY_0][KEY_LONG_PRESS], KEY_0, KEY_LONG_PRESS);
        SetKeyHandler(UI_dummy_function, KEY_0, KEY_REPEAT);
    }
#endif /* __MMI_MULTITAP_KEY_0__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_multitap_handle_zero_key_down
 * DESCRIPTION
 *  Function handles a zero key down input of dialer box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_multitap_handle_zero_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_dialer_handle_multitap_complete(WGUI_DIALER_BOX_ACTIVE_MULTITAP_ZERO_KEY);
    wgui_dialer_box_active_multitap = WGUI_DIALER_BOX_ACTIVE_MULTITAP_ZERO_KEY;
    gui_change_multitap_input_state(&wgui_dialer_box_zero_key_handler);
    if (MMI_dialer_inputbox.text_length <= 2)
    {
        gui_start_timer(MMI_MULTITAP_TIMEOUT, wgui_inputs_dialer_multitap_complete_zero_key);
    }
    SetKeyHandler(wgui_inputs_dialer_multitap_handle_zero_key_up, KEY_0, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_multitap_handle_zero_key_up
 * DESCRIPTION
 *  Function handles a zero key up input of dialer box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_multitap_handle_zero_key_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MULTITAP_KEY_0__
    gui_start_timer(MMI_MULTITAP_TIMEOUT + 400, wgui_inputs_dialer_multitap_complete_zero_key);
#else 
    gui_start_timer(MMI_MULTITAP_TIMEOUT, wgui_inputs_dialer_multitap_complete_zero_key);
#endif
    
    /* Idle app will set disable # key long press to switch profile */
    if (storeZeroKeyFuncPtrs[KEY_0][KEY_EVENT_UP] != wgui_inputs_dialer_multitap_handle_zero_key_up &&
        storeZeroKeyFuncPtrs[KEY_0][KEY_EVENT_UP] != NULL)
    {
        (*storeZeroKeyFuncPtrs[KEY_0][KEY_EVENT_UP]) ();

        /* Re-register zero key up/down handler for multitap */
        SetKeyHandler(wgui_inputs_dialer_multitap_handle_zero_key_down, KEY_0, KEY_EVENT_DOWN);
        SetKeyHandler(wgui_inputs_dialer_multitap_handle_zero_key_up, KEY_0, KEY_EVENT_UP);
    }
}

#endif /* (ENABLE_DIALER_ZERO_KEY_MULTITAP) */ 


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_handle_zero_key_long_press
 * DESCRIPTION
 *  Function handles a zero key long press  input of dialer box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_handle_zero_key_long_press(void)
{
#if(ENABLE_DIALER_ZERO_KEY_MULTITAP)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(wgui_inputs_dialer_multitap_handle_zero_key_down, KEY_0, KEY_REPEAT);
    wgui_dialer_inputbox_zero_ley_long_press_flag = MMI_TRUE;
#else /* (ENABLE_DIALER_ZERO_KEY_MULTITAP) */ 
    SetKeyHandler(UI_dummy_function, KEY_0, KEY_REPEAT);
#endif /* (ENABLE_DIALER_ZERO_KEY_MULTITAP) */ 

    /* To prevent screen flash when deleting character */
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif

#if(ENABLE_DIALER_ZERO_KEY_MULTITAP)
    if (g_dialer_is_zero_inputed == MMI_TRUE)
#endif
    {
        MMI_dialer_inputbox.flags |= UI_DIALER_INPUT_BOX_STATE_MULTITAP;
        //wgui_inputs_dialer_delete_character();
    }
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
#endif

    /* for multitap key register */
#if(ENABLE_DIALER_ZERO_KEY_MULTITAP)
    wgui_dialer_inputbox_zero_ley_long_press_flag = MMI_FALSE;

    /* to store the zero key hander for idleScreenDigitHandler.... */
    if (mmi_frm_get_key_handler(KEY_0, KEY_EVENT_DOWN) != wgui_inputs_dialer_multitap_handle_zero_key_down)
    {
        storeZeroKeyFuncPtrs[KEY_0][KEY_EVENT_DOWN] = mmi_frm_get_key_handler(KEY_0, KEY_EVENT_DOWN);
        storeZeroKeyFuncPtrs[KEY_0][KEY_EVENT_UP] = mmi_frm_get_key_handler(KEY_0, KEY_EVENT_UP);
        storeZeroKeyFuncPtrs[KEY_0][KEY_LONG_PRESS] = mmi_frm_get_key_handler(KEY_0, KEY_LONG_PRESS);
        SetKeyHandler(wgui_inputs_dialer_multitap_handle_zero_key_down, KEY_0, KEY_EVENT_DOWN);
        SetKeyHandler(wgui_inputs_dialer_multitap_handle_zero_key_up, KEY_0, KEY_EVENT_UP);
        ClearKeyHandler(KEY_0, KEY_LONG_PRESS);
    }

    wgui_inputs_dialer_multitap_handle_zero_key_down();

#endif /* (ENABLE_DIALER_ZERO_KEY_MULTITAP) */ 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_handle_hash_key_down
 * DESCRIPTION
 *  Function handles a hash key down input of dialer box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_handle_hash_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_dialer_handle_multitap_complete(WGUI_DIALER_BOX_ACTIVE_MULTITAP_ANY);
    wgui_inputs_dialer_direct_input((UI_character_type) '#');
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_handle_star_key_down
 * DESCRIPTION
 *  Function handles a start key down input of dialer box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_handle_star_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_dialer_handle_multitap_complete(WGUI_DIALER_BOX_ACTIVE_MULTITAP_ANY);
    wgui_inputs_dialer_direct_input((UI_character_type) '*');
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_handle_right_softkey_down
 * DESCRIPTION
 *  Function handles a RSK  key down input of dialer box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_handle_right_softkey_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* to complete the active multitap key */
    wgui_inputs_dialer_handle_multitap_complete(WGUI_DIALER_BOX_ACTIVE_MULTITAP_ANY);
    if (gui_dialer_input_box_get_text_length(&MMI_dialer_inputbox) > 0)
    {
        wgui_inputs_dialer_delete_character();
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_handle_right_softkey_up
 * DESCRIPTION
 *  Function handles a RSK  key up input of dialer box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_handle_right_softkey_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* for reentry issue */
#if defined(__MMI_WITH_C_KEY__)
    static U8 executing = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (1 == executing)
    {
        return;
    }
    executing = 1;
#endif /* defined(__MMI_WITH_C_KEY__) */ 
#ifdef __MMI_MULTITAP_KEY_0__
    if (wgui_dialer_box_active_multitap == WGUI_DIALER_BOX_ACTIVE_MULTITAP_ZERO_KEY)
    {
        gui_cancel_timer(wgui_inputs_dialer_multitap_complete_zero_key);
    }
#else /* __MMI_MULTITAP_KEY_0__ */ 
    if (wgui_dialer_box_active_multitap == WGUI_DIALER_BOX_ACTIVE_MULTITAP_STAR_KEY)
    {
        gui_cancel_timer(wgui_inputs_dialer_multitap_complete_star_key);
    }
#endif /* __MMI_MULTITAP_KEY_0__ */ 

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    if (wgui_dialer_box_active_multitap == WGUI_DIALER_BOX_ACTIVE_MULTITAP_QWERTY_KEY)
    {
        gui_cancel_timer(wgui_inputs_dialer_multitap_complete_qwerty_key);
    }
#endif

    if (wgui_dialer_inputbox_RSK_function != NULL)
    {
        wgui_dialer_inputbox_RSK_function();
    }
#if defined(__MMI_WITH_C_KEY__)
    executing = 0;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_register_handle_right_softkey_up
 * DESCRIPTION
 *  register RSK function of dialer box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_register_handle_right_softkey_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_right_softkey_function(wgui_inputs_dialer_handle_right_softkey_up, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_register_handle_clear_key_up
 * DESCRIPTION
 *  register RSK function of dialer box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_register_handle_clear_key_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(wgui_inputs_dialer_handle_right_softkey_up, KEY_CLEAR, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_handle_input
 * DESCRIPTION
 *  handle dialer input box set RSK function of dialer box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_handle_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gui_dialer_input_box_get_text_length(&MMI_dialer_inputbox) > 0)
    {
        if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
        {
            /* keep this line to avoid re-register the key handler in every insert/delete digitial */
            if (wgui_dialer_inputbox_RSK_label_clear == 0)
            {
                if (wgui_inputbox_not_empty_callback != NULL)
                {
                    wgui_inputbox_not_empty_callback();
                }
                wgui_dialer_inputbox_RSK_label_clear = 1;
                set_right_softkey_label(wgui_dialer_inputbox_RSK_label_string);
                set_right_softkey_icon(wgui_dialer_inputbox_RSK_label_icon);
                SetKeyHandler(wgui_inputs_dialer_handle_right_softkey_down, KEY_CLEAR, KEY_EVENT_DOWN);
                SetKeyHandler(UI_dummy_function, KEY_CLEAR, KEY_EVENT_UP);
                SetKeyHandler(wgui_inputs_dialer_handle_right_softkey_long_press, KEY_CLEAR, KEY_EVENT_LONG_PRESS);
            }
        }
        else
        {
            if (wgui_dialer_inputbox_RSK_label_clear == 0)
            {
                set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_CLEAR));
                set_right_softkey_icon(NULL);
                if (wgui_inputbox_not_empty_callback != NULL)
                {
                    wgui_inputbox_not_empty_callback();
                }
                redraw_right_softkey();
                wgui_dialer_inputbox_RSK_label_clear = 1;
                set_right_softkey_function(NULL, KEY_EVENT_UP);
                set_right_softkey_function(wgui_inputs_dialer_handle_right_softkey_down, KEY_EVENT_DOWN);
            #ifdef __MMI_TOUCH_DIAL_SCREEN__
                //SetRightSoftkeyFunction(TouchDialerClearKey,KEY_LONG_PRESS); 
            #endif /* __MMI_TOUCH_DIAL_SCREEN__ */ 
            }
        }    
    }
    else
    {
        if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))       
        /* Delete this line to make sure the when first launch the dialer screen, the clear key handler
           is register correct before save key handler in IdleScreenDigitHandler. Also, if the editor content
           is empty, should always set the clear key handler*/
     //   if (wgui_dialer_inputbox_RSK_label_clear == 1)
        {
            if (wgui_inputbox_empty_callback != NULL)
            {
                wgui_inputbox_empty_callback();
            }
            wgui_dialer_inputbox_RSK_label_clear = 0;
            set_right_softkey_label(wgui_dialer_inputbox_RSK_label_string);
            set_right_softkey_icon(wgui_dialer_inputbox_RSK_label_icon);

            /* [MTK]: register Clear key handler */
            SetKeyHandler(wgui_inputs_dialer_handle_right_softkey_down, KEY_CLEAR, KEY_EVENT_DOWN);
            SetKeyHandler(UI_dummy_function, KEY_CLEAR, KEY_EVENT_UP);
            SetKeyHandler(wgui_inputs_dialer_handle_right_softkey_long_press, KEY_CLEAR, KEY_EVENT_LONG_PRESS);
            if (!wgui_dialer_inputbox_zero_ley_long_press_flag)
                wgui_inputs_dialer_handle_right_softkey_up();
        }
        else
        {
            if (wgui_dialer_inputbox_RSK_label_clear == 1)
            {
            #if(DISABLE_DIALER_BACK_KEY)
                set_right_softkey_label(wgui_dialer_inputbox_RSK_label_string);
                set_right_softkey_icon(wgui_dialer_inputbox_RSK_label_icon);
                set_right_softkey_function(wgui_inputs_dialer_handle_right_softkey_up, KEY_EVENT_UP);
                if (wgui_inputbox_empty_callback != NULL)
                {
                    wgui_inputbox_empty_callback();
                }
                redraw_right_softkey();
                wgui_dialer_inputbox_RSK_label_clear = 0;
            #else /* (DISABLE_DIALER_BACK_KEY) */ 
                set_right_softkey_label(wgui_dialer_inputbox_RSK_label_string);
                set_right_softkey_icon(wgui_dialer_inputbox_RSK_label_icon);
                if (wgui_inputbox_empty_callback != NULL)
                {
                    wgui_inputbox_empty_callback();
                }
                redraw_right_softkey();
                wgui_dialer_inputbox_RSK_label_clear = 0;
                set_right_softkey_function(wgui_inputs_dialer_register_handle_right_softkey_up, KEY_EVENT_UP);
                set_right_softkey_function(NULL, KEY_EVENT_DOWN);
            #endif /* (DISABLE_DIALER_BACK_KEY) */ 
            }           
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_register_dialer_keys
 * DESCRIPTION
 *  register key handlers of dialer box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_register_dialer_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_dial_key_tone_type(MMI_DIALER_KEY_TONE_DTMF);
#ifndef __MMI_QWERTY_KEYPAD_SUPPORT__ 
    wgui_inputs_dialer_register_keys();
    wgui_inputs_multitap_clear_key_handlers();
    register_MMI_key_input_handler();
    register_key_down_handler(wgui_inputs_dialer_handle_key_down);
    register_key_up_handler(wgui_inputs_dialer_handle_key_up);
    register_keyboard_input_handler(wgui_inputs_dialer_numeric_keyboard_input_handler);
#ifdef __MMI_MULTITAP_KEY_0__
    SetKeyHandler(wgui_inputs_dialer_handle_star_key_down, KEY_STAR, KEY_EVENT_DOWN);
#else /* __MMI_MULTITAP_KEY_0__ */ 
    SetKeyHandler(wgui_inputs_dialer_multitap_handle_star_key_down, KEY_STAR, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_inputs_dialer_multitap_handle_star_key_up, KEY_STAR, KEY_EVENT_UP);
#endif /* __MMI_MULTITAP_KEY_0__ */ 
    SetKeyHandler(wgui_inputs_dialer_handle_hash_key_down, KEY_POUND, KEY_EVENT_DOWN);
#if(ENABLE_DIALER_ZERO_KEY_MULTITAP)
#ifdef __MMI_MULTITAP_KEY_0__
    SetKeyHandler(wgui_inputs_dialer_handle_zero_key_long_press, KEY_0, KEY_EVENT_LONG_PRESS);
#else /* __MMI_MULTITAP_KEY_0__ */ 
    SetKeyHandler(wgui_inputs_dialer_multitap_handle_zero_key_down, KEY_0, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_inputs_dialer_multitap_handle_zero_key_up, KEY_0, KEY_EVENT_UP);
#endif /* __MMI_MULTITAP_KEY_0__ */ 
#endif /* (ENABLE_DIALER_ZERO_KEY_MULTITAP) */ 

#else
    mmi_frm_set_translate_key_handler(MMI_FRM_TRANS_KEY_EDITOR, wgui_inputs_dialer_qwerty_key_handler);
#endif /* #ifndef __MMI_QWERTY_KEYPAD_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_validation_callback
 * DESCRIPTION
 *  validation function of dialer box
 * PARAMETERS
 *  text            [IN]        Text of dialer input box
 *  cursor          [IN]        
 *  text_length     [IN]        Text length
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_validation_callback(UI_buffer_type text, UI_buffer_type cursor, S32 text_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_inputbox_validation_callback != NULL)
    {
        wgui_inputbox_validation_callback(text, cursor, text_length);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_handle_right_softkey_long_press
 * DESCRIPTION
 *  function handle long press of RSK
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_handle_right_softkey_long_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_inputs_repeat_count = 0;
    if (mmi_frm_kbd_is_key_supported(KEY_CLEAR)) 
    {
       SetKeyHandler(wgui_inputs_dialer_handle_right_softkey_repeat, KEY_CLEAR, KEY_REPEAT);
    }
    else
    {
    set_right_softkey_function(wgui_inputs_dialer_handle_right_softkey_touch_repeat, KEY_REPEAT);
    SetKeyHandler(wgui_inputs_dialer_handle_right_softkey_repeat, KEY_RSK, KEY_REPEAT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_set_border
 * DESCRIPTION
 *  add border for dialer inputbox
 * PARAMETERS
 *  is_border_existing      [IN]        
 *  border_color            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_set_border(MMI_BOOL is_border_existing, color border_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_border_existing) /* draw a single border on dialer inputbox */
    {
        MMI_dialer_inputbox.flags |= UI_DIALER_INPUT_BOX_SHOW_BORDER;
    }
    else
    {
        MMI_dialer_inputbox.flags &= ~UI_DIALER_INPUT_BOX_SHOW_BORDER;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_set_cursor_to_first
 * DESCRIPTION
 *  set cursor to before first char
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_set_cursor_to_first(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_dialer_inputbox.current_text_p = MMI_dialer_inputbox.text;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_setup
 * DESCRIPTION
 *  create dialer input box
 * PARAMETERS
 *  x                       [IN]        Start x position of dialer input box
 *  y                       [IN]        Start y position of dialer input box
 *  width                   [IN]        Width of dilaer input box
 *  height                  [IN]        Height of dialer input box
 *  buffer                  [IN]        Text buffer of dialer input box
 *  buffer_size             [IN]        Buffer size
 *  category_screen_ID      [IN]        Category screen iD
 *  RSK_label               [IN]        RSK label
 *  RSK_icon                [IN]        RSK icon
 *  history_buffer          [IN]        History buffer
 *  flags                   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_setup(
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        U8 *buffer,
        S32 buffer_size,
        U16 category_screen_ID,
        UI_string_type RSK_label,
        PU8 RSK_icon,
        U8 *history_buffer,
        U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 l;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(flags);
#ifndef __MMI_MULTITAP_KEY_0__
    gui_create_multitap_input(
        &wgui_dialer_box_star_key_handler,
        0,
        0,
        0,
        0,
        (UI_string_type) wgui_dialer_box_star_key_string);
    gui_set_multitap_input_callbacks(
        &wgui_dialer_box_star_key_handler,
        wgui_inputs_dialer_multitap_input,
        wgui_inputs_dialer_multitap_input_complete);
#endif /* __MMI_MULTITAP_KEY_0__ */ 
#if(ENABLE_DIALER_ZERO_KEY_MULTITAP)
    gui_create_multitap_input(
        &wgui_dialer_box_zero_key_handler,
        0,
        0,
        0,
        0,
        (UI_string_type) wgui_dialer_box_zero_key_string);
    gui_set_multitap_input_callbacks(
        &wgui_dialer_box_zero_key_handler,
        wgui_inputs_dialer_multitap_input,
        wgui_inputs_dialer_multitap_input_complete);
#endif /* (ENABLE_DIALER_ZERO_KEY_MULTITAP) */ 

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    /* qwerty Multitap */
    gui_create_multitap_input(
        &wgui_dialer_box_qwerty_key_handler,
        0,
        0,
        0,
        0,
        (UI_string_type) g_wgui_inputs_dialer_qwerty_multitap_char);
    gui_set_multitap_input_callbacks(
        &wgui_dialer_box_qwerty_key_handler,
        wgui_inputs_dialer_multitap_input,
        wgui_inputs_dialer_multitap_input_complete);
#endif
 
    l = gui_strlen((UI_string_type) buffer);
    wgui_inputs_dialer_create_set_buffer((UI_string_type) buffer, buffer_size, l, l);
    MMI_dialer_inputbox.text_font = gui_font_get_type(GUI_FONT_SIZE_DIALER_SMALL);
    MMI_dialer_inputbox.flags |= UI_DIALER_INPUT_BOX_CHARACTER_QUEUE;
#if(ENABLE_DIALER_PLUS_CHARACTER_HANDLING)
    MMI_dialer_inputbox.flags |= UI_DIALER_INPUT_BOX_PLUS_CHARACTER_HANDLING;
#endif 
    wgui_inputs_dialer_register_keys();
    wgui_inputs_dialer_move(x, y);
    wgui_inputs_dialer_resize(width, height);

    MMI_dialer_inputbox.text_font = gui_font_get_type(GUI_FONT_SIZE_DIALER_LARGE);
    MMI_dialer_inputbox.change_callback = wgui_inputs_dialer_change_callback;
    wgui_inputs_dialer_set_mask(0);
    wgui_inputs_dialer_register_dialer_keys();
    /* This is done to choose the right font size, if the buffer contains valid data */
    wgui_inputs_dialer_change_callback();
    wgui_inputs_dialer_change_callback();

    wgui_inputs_dialer_register_input_callback(wgui_inputs_dialer_handle_input);
    /* add dialer inputbox history */
    set_dialer_inputbox_category_history(category_screen_ID, history_buffer);
    wgui_dialer_inputbox_RSK_label_icon = RSK_icon;
    if (RSK_label == NULL)
    {
        wgui_dialer_inputbox_RSK_label_string = (UI_string_type)get_string(STR_GLOBAL_BACK);
    }
    else
    {
        wgui_dialer_inputbox_RSK_label_string = RSK_label;
    }
    if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
    {
        SetKeyHandler(wgui_inputs_dialer_handle_right_softkey_long_press, KEY_CLEAR, KEY_LONG_PRESS);
        set_right_softkey_function(wgui_inputs_dialer_handle_right_softkey_up, KEY_EVENT_UP);
    }
    else
    {
        set_right_softkey_function(wgui_inputs_dialer_handle_right_softkey_long_press, KEY_LONG_PRESS);
    }
    wgui_inputs_dialer_handle_input();
    if (gui_dialer_input_box_get_text_length(&MMI_dialer_inputbox) <= 0)
    {
        if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
        {
            if (wgui_inputbox_empty_callback != NULL)
            {
                wgui_inputbox_empty_callback();
            }
        }
        else
        {
            set_right_softkey_function(wgui_inputs_dialer_handle_right_softkey_up, KEY_EVENT_UP);
            if (wgui_inputbox_empty_callback != NULL)
            {
                wgui_inputbox_empty_callback();
            }
        }
    }
    else if (wgui_inputbox_not_empty_callback != NULL)
    {
        wgui_inputbox_not_empty_callback();
    }
    MMI_dialer_inputbox.validation_callback = wgui_inputs_dialer_validation_callback;
    MMI_dialer_inputbox.validation_callback(
                            MMI_dialer_inputbox.text,
                            MMI_dialer_inputbox.current_text_p,
                            (MMI_dialer_inputbox.text_length >> 1) - 1);

    if (MMI_dialer_inputbox.flags & UI_DIALER_INPUT_BOX_PLUS_CHARACTER_HANDLING)
    {
        if (MMI_dialer_inputbox.text[0] == '+')
        {
            MMI_dialer_inputbox.available_length = (wgui_dialer_inputbox_buffer_size + 1) * ENCODING_LENGTH;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_close
 * DESCRIPTION
 *  close dialer input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputbox_not_empty_callback = NULL;
    wgui_inputbox_empty_callback = NULL;
    wgui_inputbox_validation_callback = NULL;
    wgui_dialer_inputbox_RSK_function = NULL;
    wgui_inputs_dialer_star_key_up_callback = NULL;
    wgui_dialer_inputbox_RSK_label_clear = 0;
    wgui_inputs_dialer_reset();
    mmi_frm_kbd_reg_post_key_hdlr(NULL);
#ifndef __MMI_MULTITAP_KEY_0__
    gui_cancel_timer(wgui_inputs_dialer_multitap_complete_star_key);
#endif 

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    gui_cancel_timer(wgui_inputs_dialer_qwerty_multitap_key_down_time_callback);
#endif /* __MMI_QWERTY_KEYPAD_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_handle_right_arrow_repeat
 * DESCRIPTION
 *  handle right arrow key repeat of dialer input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inputs_dialer_handle_right_arrow_repeat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_fast_del_nav_handler(WGUI_INPUTS_OPER_FAST_NAV_RIGHT, WGUI_INPUTS_EDITOR_DIALER, WGUI_INPUTS_KPD_REPEAT_PERIOD);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_handle_left_arrow_repeat
 * DESCRIPTION
 *  handle left arrow key repeat of dialer input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inputs_dialer_handle_left_arrow_repeat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_fast_del_nav_handler(WGUI_INPUTS_OPER_FAST_NAV_LEFT, WGUI_INPUTS_EDITOR_DIALER, WGUI_INPUTS_KPD_REPEAT_PERIOD);
}

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_handle_up_arrow_repeat
 * DESCRIPTION
 *  handle up arrow key repeat of dialer input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inputs_dialer_handle_up_arrow_repeat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_fast_del_nav_handler(WGUI_INPUTS_OPER_FAST_NAV_UP, WGUI_INPUTS_EDITOR_DIALER, WGUI_INPUTS_KPD_REPEAT_PERIOD);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_handle_down_arrow_repeat
 * DESCRIPTION
 *  handle down arrow key repeat of dialer input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inputs_dialer_handle_down_arrow_repeat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_fast_del_nav_handler(WGUI_INPUTS_OPER_FAST_NAV_DOWN, WGUI_INPUTS_EDITOR_DIALER, WGUI_INPUTS_KPD_REPEAT_PERIOD);
}



/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_handle_right_softkey_repeat
 * DESCRIPTION
 *  handle right softkey repeat of dialer input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inputs_dialer_handle_right_softkey_repeat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_dialer_inputbox.text_length <= ENCODING_LENGTH)
    {
        return;
    }
    wgui_inputs_fast_del_nav_handler(WGUI_INPUTS_OPER_FAST_DEL, WGUI_INPUTS_EDITOR_DIALER, WGUI_INPUTS_KPD_REPEAT_PERIOD);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_handle_right_softkey_touch_repeat
 * DESCRIPTION
 *  handle right softkey repeat of dialer input box (Touch panel RSK)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inputs_dialer_handle_right_softkey_touch_repeat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_dialer_inputbox.text_length <= ENCODING_LENGTH)
    {
        return;
    }
    wgui_inputs_fast_del_nav_handler(WGUI_INPUTS_OPER_FAST_DEL, WGUI_INPUTS_EDITOR_DIALER, WGUI_INPUTS_TP_REPEAT_PERIOD);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_register_star_key_up_callback
 * DESCRIPTION
 *  Register dialer star key up callback
 * PARAMETERS
 *  f                         [IN]                 star key up callback
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_register_star_key_up_callback(void(*f)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_dialer_star_key_up_callback = f;
}
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
//static UI_character_type g_wgui_inputs_dialer_qwerty_multitap_char[WGUI_INPUTS_DIALER_ALLOW_MAX_CHAR];
//static UI_character_type g_wgui_inputs_dialer_qwerty_multitap_star_char[WGUI_INPUTS_DIALER_ALLOW_MAX_CHAR] = {'*', '+', 'p', 'w'};

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_qwerty_multitap_key_down_time_callback
 * DESCRIPTION
 *  Confirmed QWERTY dialer multitap character. KEY_UP envent maybe dropped in some case,
 *  So confirm character in key up handler is not safe.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inputs_dialer_qwerty_multitap_key_down_time_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_query_mmi_key_state(g_qwerty_multitap_key_down_key_code) == KEY_EVENT_UP)
    {
        g_qwerty_multitap_key_down_key_code = KEY_INVALID;
        gui_start_timer(MMI_MULTITAP_TIMEOUT, wgui_inputs_dialer_multitap_complete_qwerty_key);
    }
    else
    {
        gui_cancel_timer(wgui_inputs_dialer_qwerty_multitap_key_down_time_callback);
        gui_start_timer(MMI_QWERTY_DIALER_KEY_DOWN_TIME_OUT, wgui_inputs_dialer_qwerty_multitap_key_down_time_callback);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_qwerty_key_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL wgui_inputs_dialer_qwerty_key_handler(S16 mmi_key_code, S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type key_char[WGUI_INPUTS_DIALER_KEY_MAX_CHAR * 2] = {0};
    U8 i, j, char_count;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    char_count = 0;
    /* Find all char in current key */
    mmi_imm_qwerty_get_supported_chars(mmi_key_code, key_char, WGUI_INPUTS_DIALER_KEY_MAX_CHAR);

    /* Check if comes key event or APP call execute key handler directly */
    if (!mmi_frm_is_key_event())
    {
        memset(g_wgui_inputs_dialer_qwerty_multitap_char, 0, WGUI_INPUTS_DIALER_ALLOW_MAX_CHAR * sizeof(UI_character_type));
        if (mmi_key_code == KEY_STAR)
        {
            memcpy(g_wgui_inputs_dialer_qwerty_multitap_char, g_wgui_inputs_dialer_qwerty_multitap_star_char, WGUI_INPUTS_DIALER_ALLOW_MAX_CHAR * ENCODING_LENGTH);

            char_count = WGUI_INPUTS_DIALER_ALLOW_MAX_CHAR;
        }
        else
        {
            if (mmi_key_code >= KEY_0 && mmi_key_code <= KEY_9)
            {
                g_wgui_inputs_dialer_qwerty_multitap_char[0] = mmi_key_code - KEY_0 + '0';
                char_count = 1;
            }
            else if (mmi_key_code == KEY_POUND)
            {
                g_wgui_inputs_dialer_qwerty_multitap_char[0] = '#';
                char_count = 1;
            }
            
            g_wgui_inputs_dialer_qwerty_multitap_char[1] = 0;
        }
    }
    else
    {
        /* Find dialer chars in current key */
        for (i = 0; i < WGUI_INPUTS_DIALER_ALLOW_MAX_CHAR; i++)
        {
            for (j = 0; j < WGUI_INPUTS_DIALER_KEY_MAX_CHAR; j++)
            {
                if (key_char[j] == g_wgui_inputs_dialer_allow_char[i])
                {
                    g_wgui_inputs_dialer_qwerty_multitap_char[char_count] = key_char[j];
                    char_count++;
                    break;
                }
            }
        }
        g_wgui_inputs_dialer_qwerty_multitap_char[char_count] = 0;
    }

    if ((mmi_key_type == KEY_EVENT_DOWN) || (mmi_key_type == KEY_EVENT_REPEAT))
    {
        g_qwerty_multitap_key_down_key_code = mmi_key_code;
        gui_cancel_timer(wgui_inputs_dialer_qwerty_multitap_key_down_time_callback);

        if (mmi_key_code == KEY_BACKSPACE)
        {
            if (mmi_key_type == KEY_EVENT_REPEAT)
            {
                wgui_inputs_dialer_handle_right_softkey_repeat();  
            }
            else
            {
                wgui_inputs_dialer_handle_right_softkey_down();
            }

            return MMI_TRUE;
        }
        else
        {
            if (char_count == 1)
            {
                wgui_inputs_dialer_handle_multitap_complete(WGUI_DIALER_BOX_ACTIVE_MULTITAP_ANY);
                wgui_inputs_dialer_direct_input(g_wgui_inputs_dialer_qwerty_multitap_char[0]);
                return MMI_TRUE;
            }
            else if (char_count > 1)
            {
                /* If multitap, save current multitap key, and start a timer to confirm the character */
                if (mmi_frm_is_key_event())
                {
                    gui_start_timer(MMI_QWERTY_DIALER_KEY_DOWN_TIME_OUT, wgui_inputs_dialer_qwerty_multitap_key_down_time_callback);
                }

                wgui_dialer_box_qwerty_key_handler.length = gui_strlen(wgui_dialer_box_qwerty_key_handler.text);
                if (!(MMI_dialer_inputbox.flags & UI_DIALER_INPUT_BOX_STATE_MULTITAP))
                {
                    wgui_dialer_box_qwerty_key_handler.current_position = -1;
                }
                wgui_inputs_dialer_multitap_handle_qwerty_key_down();
                return MMI_TRUE;
            }
            else
            {
                return MMI_FALSE;
            }
        }
    }
    else if (mmi_key_type == KEY_EVENT_UP)
    {
        if (g_qwerty_multitap_key_down_key_code == mmi_key_code)
        {
            gui_cancel_timer(wgui_inputs_dialer_qwerty_multitap_key_down_time_callback);
        }

        if (mmi_key_code == KEY_BACKSPACE)
        {
            if (gui_dialer_input_box_get_text_length(&MMI_dialer_inputbox) <= 0)
            {
                wgui_inputs_dialer_handle_right_softkey_up();
                return MMI_TRUE;
            }
        }
        if (char_count > 1)
        {
            wgui_inputs_dialer_multitap_handle_qwerty_key_up();
            return MMI_TRUE;
        }
    }
    else if (mmi_key_type == KEY_LONG_PRESS)
    {
        if (mmi_key_code == KEY_BACKSPACE)
        {
            g_wgui_inputs_repeat_count = 0;
        }
    }

	return MMI_FALSE;
}
#endif






#else /* __MMI_EDITOR_DIALER_SUPPORT__ */
void wgui_inputs_dialer_move(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
}
void wgui_inputs_dialer_resize(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
}
void wgui_inputs_dialer_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
}

void wgui_inputs_dialer_register_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
}
void wgui_inputs_dialer_handle_multitap_complete(S32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
}




#endif /* __MMI_EDITOR_DIALER_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_display_char
 * DESCRIPTION
 *  Register dialer star key up callback
 * PARAMETERS
 *  f                         [IN]                 star key up callback
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_display_char(U8 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_QWERTY_KEYPAD_SUPPORT__
    FuncPtr f = NULL;
    f = mmi_frm_get_key_handler(key_code, KEY_EVENT_DOWN);
    if (f != NULL)
    {
        f();
    }
#else /* __MMI_QWERTY_KEYPAD_SUPPORT__ */
#ifndef __MMI_EDITOR_DIALER_SUPPORT__ 
    mmi_frm_key_evt_struct tmp_evt;
    mmi_frm_construct_key_event(key_code, KEY_EVENT_DOWN, &tmp_evt);
    tmp_evt.evt_id = EVT_ID_PRE_KEY;
    MMI_FRM_SEND_EVENT(&tmp_evt, mmi_imc_key_qwerty_key_proc, NULL);
    mmi_frm_construct_key_event(key_code, KEY_EVENT_UP, &tmp_evt);
    tmp_evt.evt_id = EVT_ID_PRE_KEY;
    MMI_FRM_SEND_EVENT(&tmp_evt, mmi_imc_key_qwerty_key_proc, NULL);
#else /* __MMI_EDITOR_DIALER_SUPPORT__ */
    wgui_inputs_dialer_qwerty_key_handler(key_code, KEY_EVENT_DOWN, 0, 0);
#endif/* __MMI_EDITOR_DIALER_SUPPORT__ */
#endif /* __MMI_QWERTY_KEYPAD_SUPPORT__ */    
}
#ifdef __MMI_TOUCH_DIAL_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_setup_dialing_keypad
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dialing_keypad      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_dialer_setup_dialing_keypad(dialing_keypad_struct *dialing_keypad)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dialing_keypad->keypad_x = MMI_DIALING_KEYPAD_LAYER_X + MMI_DIALING_KEYPAD_X;
    dialing_keypad->keypad_y = MMI_DIALING_KEYPAD_LAYER_Y + MMI_DIALING_KEYPAD_Y;
    dialing_keypad->keypad_width = MMI_DIALING_KEYPAD_WIDTH;
    dialing_keypad->keypad_height = MMI_DIALING_KEYPAD_HEIGHT;
    dialing_keypad->key_width = MMI_DIALING_KEY_WIDTH;
    dialing_keypad->key_height = MMI_DIALING_KEY_HEIGHT;
    dialing_keypad->horizontal_gap = MMI_DIALING_KEY_HORIZONTAL_GAP;
    dialing_keypad->vertical_gap = MMI_DIALING_KEY_VERTICAL_GAP;
#ifndef __GDI_MEMORY_PROFILE_2__
    dialing_keypad->selected_key_bitmap.width = 0;
    dialing_keypad->selected_key_bitmap.height = 0;
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
    dialing_keypad->n_column = MMI_DIALING_KEYPAD_COLOMNS;
    dialing_keypad->n_rows = MMI_DIALING_KEYPAD_ROWS;
    /* added for handling of star character */
    dialing_keypad->key_type = 0;

    /* added for function key */
#if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
    dialing_keypad->keypad_func_x = MMI_DIALING_KEYPAD_LAYER_X + MMI_DIALING_KEYPAD_FUNC_X;
    dialing_keypad->keypad_func_y = MMI_DIALING_KEYPAD_LAYER_Y + MMI_DIALING_KEYPAD_FUNC_Y;
    dialing_keypad->func_key_width = MMI_DIALING_FUNC_KEY_WIDTH;
    dialing_keypad->func_key_height = MMI_DIALING_FUNC_KEY_HEIGHT;
    dialing_keypad->func_horizontal_gap = MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP;
    dialing_keypad->func_vertical_gap = MMI_DIALING_FUNC_KEY_VERTICAL_GAP;
    dialing_keypad->func_n_column = MMI_DIALING_KEYPAD_FUNC_COLOMNS;
    dialing_keypad->func_n_rows = MMI_DIALING_KEYPAD_FUNC_ROWS;
#if defined(__MMI_CAT_VIDEO_CALL__) || (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X240__))
    dialing_keypad->call_key_width = MMI_DIALING_FUNC_KEY_WIDTH;
#else /* __MMI_CAT_VIDEO_CALL__ */
    dialing_keypad->call_key_width = MMI_DIALING_FUNC_KEY_WIDTH + MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP + MMI_DIALING_FUNC_KEY_WIDTH;
#endif /* __MMI_CAT_VIDEO_CALL__ */

    gui_reset_dialing_func_key_flag();
#endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */ 
}
#endif /* __MMI_TOUCH_DIAL_SCREEN__ */ 
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_is_dialer_keys
 * DESCRIPTION
 *  Check if the key_code has dialer chars
 * PARAMETERS
 *  mmi_key_code          [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL wgui_inputs_dialer_is_dialer_keys(S16 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type key_char[WGUI_INPUTS_DIALER_KEY_MAX_CHAR * 2] = {0};
    U8 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Find all char in current key */
    mmi_imm_qwerty_get_supported_chars(mmi_key_code, key_char, WGUI_INPUTS_DIALER_KEY_MAX_CHAR);

    /* Find dialer chars in current key */
    for (i = 0; i < WGUI_INPUTS_DIALER_ALLOW_MAX_CHAR; i++)
    {
        for (j = 0; j < WGUI_INPUTS_DIALER_KEY_MAX_CHAR; j++)
        {
            if (key_char[j] == g_wgui_inputs_dialer_allow_char[i])
            {
                return MMI_TRUE;
            }
        }
    }
    return MMI_FALSE;
}
#else /* __MMI_QWERTY_KEYPAD_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_dialer_is_dialer_keys
 * DESCRIPTION
 *  Check if the key_code has dialer chars
 * PARAMETERS
 *  mmi_key_code          :[IN] mmi key code
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL wgui_inputs_dialer_is_dialer_keys(S16 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < TOTAL_DIALER_KEYS; i++)
    {
        if (PresentAllDialerKeys[i] == mmi_key_code)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}
#endif
