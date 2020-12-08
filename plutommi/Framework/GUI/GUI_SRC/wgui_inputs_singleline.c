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
 *   wgui_inputs_singleline.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   wgui layer of singleline inputbox
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
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 
/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "wgui_inputs_internal.h"

#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)  
#include "mmi_frm_gestures.h"
#endif

#include "gui_touch_feedback.h"

    #include "gui_inputs.h"
    #include "MMIDataType.h"
    #include "gui.h"
    #include "gui_config.h"
    #include "gui_data_types.h"
    #include "kal_general_types.h"
    #include "MMI_features.h"
    #include "ImeGprot.h"
    #include "wgui.h"
    #include "GlobalConstants.h"
    #include "mmi_frm_input_gprot.h"
    #include "mmi_rp_app_uiframework_def.h"
    #include "mmi_frm_timer_gprot.h"
    #include "wgui_inputs.h"
    #include "gui_themes.h"
    #include "PixcomFontEngine.h"
    #include "CustThemesRes.h"
    #include "wgui_categories_inputs.h"
    #include "wgui_categories_util.h"
    #include "wgui_categories_search.h"
    #include "gui_typedef.h"
    #include "GlobalResDef.h"
    #include "wgui_include.h"
    #include "gdi_include.h"
    #include "kal_public_api.h"
    #include "DebugInitDef_Int.h"
    #include "Unicodexdcl.h"
    #include "gui_fixed_menuitems.h"
    #include "wgui_draw_manager.h"
    #include "gui_windows.h"
    #include "wgui_dynamic_menus.h"
    #include "wgui_fixed_menus.h"
    #include "mmi_frm_gestures_gprot.h"
    #include "mmi_clipboard_gprot.h"
    #include "custom_hw_default.h"
    
    #include "wgui_categories_enum.h"
    #include "wgui_categories_CM.h"
    #include "wgui_categories_idlescreen_op.h"

#ifdef __MMI_INDIC_ALG__
#include "IndicEngineGprot.h"
#endif

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
single_line_input_box MMI_singleline_inputbox;

S32 MMI_singleline_inputbox_x;
S32 MMI_singleline_inputbox_y;
S32 MMI_singleline_inputbox_width;
S32 MMI_singleline_inputbox_height;

void (*singleline_inputbox_input_callback) (void) = UI_dummy_function;
void (*singleline_inputbox_navigate_callback) (void) = UI_dummy_function;

#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_SINGLELINE_INPUTBOX_FRAME_SKIPPING))
S32 wgui_singleline_inputbox_frame_counter = 0;
#endif 

void (*wgui_singleline_inputbox_RSK_function) (void) = NULL;

/* for QSearch */
void (*wgui_singleline_inputbox_LSK_function) (void) = UI_dummy_function;

/* store rsk key string of single input box */
UI_string_type wgui_singleline_inputbox_LSK_label_string;

/* store rsk key icon of single input box */
PU8 wgui_singleline_inputbox_LSK_label_icon;

U8 wgui_singleline_inputbox_RSK_label_clear = 0;

/* store rsk key string of single input box */
UI_string_type wgui_singleline_inputbox_RSK_label_string;

/* store rsk key icon of single input box */
PU8 wgui_singleline_inputbox_RSK_label_icon;

/* store flag of decimal input of single input box */
U8 wgui_singleline_inputbox_decimal_flag = 0;

/* store flag of decimal input of mode single input box */
U8 wgui_singleline_inputbox_decimal_input_mode_flag = 0;

/* store buffer size of single input box */
S32 wgui_singleline_inputbox_buffer_size = 0;

static MMI_BOOL g_is_disable_up_down_key_register = MMI_TRUE;
static MMI_BOOL g_is_disable_left_right_key_register = MMI_FALSE;
static void wgui_inputs_sl_cannot_navigate(void);
static MMI_BOOL wgui_inputs_sl_input_overflow_check(void);

static void wgui_inputs_sl_handle_left_arrow_repeat(void);
static void wgui_inputs_sl_handle_right_arrow_repeat(void);
static void wgui_inputs_sl_handle_right_softkey_repeat(void);
static void wgui_inputs_sl_handle_right_softkey_touch_repeat(void);

static void wgui_inputs_sl_check_decimal(void); /* slim_2_2 */ //

/* If need break insert loop when can't insert */
MMI_BOOL g_wgui_inputs_is_break_insert = MMI_TRUE;


/***************************************************************************** 
 * Global Function
 *****************************************************************************/
#if 0 /* slim_2_2 */ // 
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
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_SINGLELINE_INPUTBOX_FRAME_SKIPPING))
/* under construction !*/
#endif 
/* under construction !*/
#endif


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_create_set_buffer
 * DESCRIPTION
 *  Creates a singleline inputbox
 * PARAMETERS
 *  buffer              [IN]        
 *  buffer_length       [IN]        
 *  text_length         [IN]        
 *  edit_position       [IN]        
 * RETURNS
 *  void
 * VJ
 *****************************************************************************/
void wgui_inputs_sl_create_set_buffer(UI_string_type buffer, S32 buffer_length, S32 text_length, S32 edit_position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    singleline_inputbox_input_callback = UI_dummy_function;
    singleline_inputbox_navigate_callback = UI_dummy_function;
    /* Warning: Temporary change only UCS2 / ASCII. This has to be done in a more formal manner  */
#ifdef __UCS2_ENCODING
    gui_create_single_line_input_box_set_buffer(
        &MMI_singleline_inputbox,
        MMI_singleline_inputbox_x,
        MMI_singleline_inputbox_y,
        MMI_singleline_inputbox_width,
        MMI_singleline_inputbox_height,
        buffer,
        buffer_length * 2,
        (text_length + 1) * 2,
        edit_position);
#endif /* __UCS2_ENCODING */ 
#ifdef __ASCII
    gui_create_single_line_input_box_set_buffer(
        &MMI_singleline_inputbox,
        MMI_singleline_inputbox_x,
        MMI_singleline_inputbox_y,
        MMI_singleline_inputbox_width,
        MMI_singleline_inputbox_height,
        buffer,
        buffer_length,
        text_length + 1,
        edit_position);
#endif /* __ASCII */ 
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_SINGLELINE_INPUTBOX_FRAME_SKIPPING))
    wgui_singleline_inputbox_frame_counter = 0;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_set_show_flag
 * DESCRIPTION
 *  turn on/off the single line shown
 * PARAMETERS
 *  MMI_BOOL
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_set_show_flag(MMI_BOOL is_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_singleline_inputbox.show_action_flag = is_on;
}

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_show
 * DESCRIPTION
 *  Displays the singleline inputbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_show_single_line_input_box(&MMI_singleline_inputbox);

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_BLT_double_buffer(
        MMI_singleline_inputbox.x,
        MMI_singleline_inputbox.y,
        MMI_singleline_inputbox.x + MMI_singleline_inputbox.width,
        MMI_singleline_inputbox.y + MMI_singleline_inputbox.height);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_SINGLELINE_INPUTBOX_FRAME_SKIPPING))

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_end_frame
 * DESCRIPTION
 *  Redraws the singleline inputbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_end_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_singleline_inputbox_frame_counter >= 1)
    {
        S32 y2, BLT_y2;

        gui_show_single_line_input_box(&MMI_singleline_inputbox);
        BLT_y2 = MMI_singleline_inputbox.y + MMI_singleline_inputbox.height;
        y2 = MMI_multitap_y + MMI_multitap_height + 1;
        if (BLT_y2 < y2)
        {
            BLT_y2 = y2;
        }
    #if(UI_DOUBLE_BUFFER_SUPPORT)
        gui_BLT_double_buffer(
            MMI_singleline_inputbox.x,
            MMI_singleline_inputbox.y,
            MMI_singleline_inputbox.x + MMI_singleline_inputbox.width,
            BLT_y2);
    #endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
        wgui_singleline_inputbox_frame_counter = 0;
        gui_start_timer(UI_FRAME_SKIP_TIMEOUT, wgui_inputs_sl_end_frame);
    }
}

#endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_SINGLELINE_INPUTBOX_FRAME_SKIPPING)) */ 


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_redraw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_redraw(void)
{
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_SINGLELINE_INPUTBOX_FRAME_SKIPPING))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_singleline_inputbox_frame_counter > 0)
    {
        wgui_singleline_inputbox_frame_counter++;
    }
    else
    {
        wgui_singleline_inputbox_frame_counter = 1;
        gui_start_timer(UI_FRAME_START_TIMEOUT, wgui_inputs_sl_end_frame);
    }
#else /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_SINGLELINE_INPUTBOX_FRAME_SKIPPING)) */ 

    if (MMI_singleline_inputbox.show_action_flag)
    {
        wgui_inputs_sl_show();        
        #if 0 /* slim_2_2 */ //
/* under construction !*/
/* under construction !*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
    }

#endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_SINGLELINE_INPUTBOX_FRAME_SKIPPING)) */ 
}

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_multitap_input_string
 * DESCRIPTION
 *  Inserts a multitap character
 *  
 *  Normally called by multitap objects
 * PARAMETERS
 *  str       [IN]        String to be inserted
 * RETURNS
 *  S32
 *****************************************************************************/
S32 wgui_inputs_sl_multitap_input_string(PU8 str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 ret = 0;
#ifdef __MMI_EDITOR_SINGLE_SUPPORT_MULTIGRAPH__

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    ret = gui_single_line_input_box_insert_multitap_string(&MMI_singleline_inputbox, (UI_string_type)str);
    if (ret)
    {
	    wgui_inputs_sl_redraw();
	    singleline_inputbox_input_callback();
	}
	
#endif /*__MMI_EDITOR_SINGLE_SUPPORT_MULTIGRAPH__*/
	return ret;
}

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_multitap_input
 * DESCRIPTION
 *  Inserts a multitap character
 *  
 *  Normally called by multitap objects
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL wgui_inputs_sl_multitap_input(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL ret = MMI_FALSE;
    single_line_input_box *b = &MMI_singleline_inputbox;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_singleline_inputbox.flags & UI_SINGLE_LINE_INPUT_BOX_PLUS_CHARACTER_HANDLING)
    {
        b->available_length = (wgui_singleline_inputbox_buffer_size + 1) * ENCODING_LENGTH;
        
        ret = gui_single_line_input_box_insert_multitap_character(&MMI_singleline_inputbox, c);
        
        if (b->text[0] != '+')
        {
            b->available_length = wgui_singleline_inputbox_buffer_size * ENCODING_LENGTH;
        }
        
        if (ret)
        {
            if (wgui_inputs_sl_input_overflow_check())
            {
                if (b->text[0] != '+')
                {
                    if (MMI_singleline_inputbox.flags & UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP)
                    {
                        gui_single_line_input_box_confirm_multitap_character(b);
                    }
                    
                    gui_single_line_input_box_delete_character(b);
                    
                    UI_editor_play_tone_cannot_insert(); 
                    
                    ret = MMI_FALSE;
                }
            }
        }
    }
    else
    {
        ret = gui_single_line_input_box_insert_multitap_character(&MMI_singleline_inputbox, c);
    }

    if (ret)
    {
	    wgui_inputs_sl_redraw();
	    singleline_inputbox_input_callback();
	}
	
	return ret;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_multitap_input_complete
 * DESCRIPTION
 *  Completes a multitap input sequence
 *  
 *  Normally called by multitap objects
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_multitap_input_complete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_single_line_input_box_confirm_multitap_character(&MMI_singleline_inputbox);
    wgui_inputs_sl_redraw();
    singleline_inputbox_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_input_overflow_check
 * DESCRIPTION
 *  Check if the input character has overflow
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL wgui_inputs_sl_input_overflow_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_deleted_char = MMI_TRUE;
    UI_buffer_type text_p;
    UI_character_type current_character;
    single_line_input_box *b = &MMI_singleline_inputbox;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    text_p = MMI_singleline_inputbox.text + MMI_singleline_inputbox.text_length - 2 * ENCODING_LENGTH;
    UI_STRING_GET_NEXT_CHARACTER(text_p, current_character);
    /* 
       delete the redunant character in following condition
         1) recipient mode: 
             a. if last character is ';' (text_length>available_length), 
             b. else (text_length>=available_length)
         2) non recipient mode:
             text_length > available_length
     */
    
    if (b->ext_flags & GUI_SINGLE_LINE_INPUT_BOX_RECIPIENT_SEMICOLON_MODE)
    {
        if (UI_TEST_SEMICOLON_CHAR(current_character))
        {
            if (b->text_length > b->available_length)
            {
                is_deleted_char = MMI_TRUE;
            }
            else
            {
                is_deleted_char = MMI_FALSE;
            }
        }
        else
        {
            if (b->text_length >= b->available_length)
            {
                is_deleted_char = MMI_TRUE;
            }
            else
            {
                is_deleted_char = MMI_FALSE;
            }
        }
    }
    else
    {
        if (b->text_length > b->available_length)
        {
            is_deleted_char = MMI_TRUE;
        }
        else
        {
            is_deleted_char = MMI_FALSE;
        }
    }

    return is_deleted_char;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_direct_input
 * DESCRIPTION
 *  inserts a character at cursor position
 *  
 *  Normally registered to a keyboard input handler
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_inputs_sl_direct_input(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    /* slim_2_2 */ // single_line_input_box *b = &MMI_singleline_inputbox;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = wgui_inputs_sl_direct_input_no_draw(c);
    #if 0 /* slim_2_2 */ //
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
    if (ret == 0)
    {
        gui_single_line_input_box_locate_cursor(&MMI_singleline_inputbox);
    }

    wgui_inputs_sl_redraw();
    singleline_inputbox_input_callback();
         
    return ret; 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_direct_input_no_draw
 * DESCRIPTION
 *  inserts a character at cursor position
 *  
 *  Normally registered to a keyboard input handler
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_inputs_sl_direct_input_no_draw(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    single_line_input_box *b = &MMI_singleline_inputbox;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_singleline_inputbox.flags & UI_SINGLE_LINE_INPUT_BOX_PLUS_CHARACTER_HANDLING)
    {
        b->available_length = (wgui_singleline_inputbox_buffer_size + 1) * ENCODING_LENGTH;
        
        ret = gui_single_line_input_box_insert_character(&MMI_singleline_inputbox, c);
        
        if (b->text[0] != '+')
        {
            b->available_length = wgui_singleline_inputbox_buffer_size * ENCODING_LENGTH;
        }
        
        if (ret)
        {
            if (wgui_inputs_sl_input_overflow_check())
            {
                if (b->text[0] != '+')
                {
                    if (MMI_singleline_inputbox.flags & UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP)
                    {
                        gui_single_line_input_box_confirm_multitap_character(b);
                    }
                    
                    gui_single_line_input_box_delete_character(b);
                    
                    UI_editor_play_tone_cannot_insert(); 
                    
                    ret = MMI_FALSE;
                }
            }
        }
    }
    else if (c == '.')
    {
        if (wgui_singleline_inputbox_decimal_input_mode_flag)
        {
            if (wgui_singleline_inputbox_decimal_flag)
            {
                return MMI_FALSE;
            }
        }
        ret = gui_single_line_input_box_insert_character(&MMI_singleline_inputbox, c);
        if (ret)
        {
            if (wgui_singleline_inputbox_decimal_input_mode_flag)
            {
                wgui_singleline_inputbox_decimal_flag = 1;
            }
        }
    }
    else
    {
        ret = gui_single_line_input_box_insert_character(&MMI_singleline_inputbox, c);
    }
         
    return ret; 
}

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_check_decimal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inputs_sl_check_decimal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_singleline_inputbox_decimal_input_mode_flag)
    {
        if (wgui_singleline_inputbox_decimal_flag)
        {
            UI_buffer_type p = MMI_singleline_inputbox.current_text_p;
            UI_character_type c;

            if (p != MMI_singleline_inputbox.text)
            {
                UI_STRING_GET_PREVIOUS_CHARACTER(p, c);
                if (c == (UI_character_type) '.')
                {
                    wgui_singleline_inputbox_decimal_flag = 0;
                }
            }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_delete_character
 * DESCRIPTION
 *  deletes a character at cursor position
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_delete_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__
    if (MMI_singleline_inputbox.ext_flags & GUI_SINGLE_LINE_INPUT_BOX_RECIPIENT_MODE)
    {
        if (MMI_TRUE == gui_single_line_input_box_delete_all(&MMI_singleline_inputbox))
        {
            wgui_inputs_sl_redraw();
            singleline_inputbox_input_callback();
            MMI_singleline_inputbox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        }
        return;
    }
    #endif /*__MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__*/
    wgui_inputs_sl_check_decimal();
    #if 0 /* slim_2_2 */ //    
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
    if (MMI_TRUE == gui_single_line_input_box_delete_character(&MMI_singleline_inputbox))
    {
        wgui_inputs_sl_redraw();
        singleline_inputbox_input_callback();
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_delete_character_no_draw
 * DESCRIPTION
 *  deletes a character at cursor position
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_delete_character_no_draw(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__
    if (MMI_singleline_inputbox.ext_flags & GUI_SINGLE_LINE_INPUT_BOX_RECIPIENT_MODE)
    {
        gui_single_line_input_box_delete_all(&MMI_singleline_inputbox);
        MMI_singleline_inputbox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
    }
    else
    #endif /*__MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__*/
    {
        gui_single_line_input_box_delete_character(&MMI_singleline_inputbox);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_previous_character
 * DESCRIPTION
 *  Moves the cursor to the previous character
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_previous_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__
    if (MMI_singleline_inputbox.ext_flags & GUI_SINGLE_LINE_INPUT_BOX_RECIPIENT_MODE)
    {
        if (MMI_singleline_inputbox.text_length > ENCODING_LENGTH)
        {
            if (MMI_singleline_inputbox.text == MMI_singleline_inputbox.current_text_p)
            {
                /* start position and highlight */
                if (MMI_singleline_inputbox.flags & UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT)
                {
                    MMI_singleline_inputbox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
                }
                else
                {
                    UI_editor_play_tone_cannot_navigate();
                }
            }
            else
            {
                if (MMI_singleline_inputbox.flags & UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT)
                {
                    MMI_singleline_inputbox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
                    MMI_singleline_inputbox.highlight_start_position = NULL;
                    MMI_singleline_inputbox.highlight_end_position = NULL;
                }
                else
                {
                    MMI_singleline_inputbox.flags |= UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
                    MMI_singleline_inputbox.highlight_start_position = MMI_singleline_inputbox.text;
                    MMI_singleline_inputbox.highlight_end_position = MMI_singleline_inputbox.last_position_p - ENCODING_LENGTH;
                }
                MMI_singleline_inputbox.current_text_p = MMI_singleline_inputbox.text;
                gui_single_line_input_box_locate_cursor(&MMI_singleline_inputbox);
            }
        }
    }
    else
    #endif /*__MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__*/
    {
        gui_single_line_input_box_previous(&MMI_singleline_inputbox);
    }
    wgui_inputs_sl_redraw();
#ifdef __MMI_PINYIN_SEARCH__
    if (inPinyinSearchScreen)
    {
        wgui_inputs_redraw_input_mode_only();
        wgui_title_set_menu_shortcut_handler_display(MMI_TRUE);
    }
#endif /* __MMI_PINYIN_SEARCH__ */ 
    singleline_inputbox_navigate_callback();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_next_character
 * DESCRIPTION
 *  Moves the cursor to the next character
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_next_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type c = 0, pre_c = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__
    if (MMI_singleline_inputbox.ext_flags & GUI_SINGLE_LINE_INPUT_BOX_RECIPIENT_MODE)
    {
        if (MMI_singleline_inputbox.text_length > ENCODING_LENGTH)
        {
            if (MMI_singleline_inputbox.current_text_p == (MMI_singleline_inputbox.last_position_p - ENCODING_LENGTH))
            {
                /* start position and highlight */
                if (MMI_singleline_inputbox.flags & UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT)
                {
                    MMI_singleline_inputbox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
                }
                else
                {
                    UI_editor_play_tone_cannot_navigate();
                }
            }
            else
            {
                if (MMI_singleline_inputbox.flags & UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT)
                {
                    MMI_singleline_inputbox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
                    MMI_singleline_inputbox.highlight_start_position = NULL;
                    MMI_singleline_inputbox.highlight_end_position = NULL;
                }
                else
                {
                    MMI_singleline_inputbox.flags |= UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
                    MMI_singleline_inputbox.highlight_start_position = MMI_singleline_inputbox.text;
                    MMI_singleline_inputbox.highlight_end_position = MMI_singleline_inputbox.last_position_p - ENCODING_LENGTH;
                }
                MMI_singleline_inputbox.current_text_p = MMI_singleline_inputbox.last_position_p - ENCODING_LENGTH;
                gui_single_line_input_box_locate_cursor(&MMI_singleline_inputbox);
            }
        }
    }
    else
    #endif /*__MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__*/
    { 
        if (mmi_imc_is_append_one_more_space_input_mode(mmi_imm_get_curr_input_mode()) &&
            !mmi_imc_is_ime_state() &&
            #ifdef __MMI_EDITOR_SL_AUTO_CLEAR_HILITE_MODE__
            !(MMI_singleline_inputbox.flags & UI_SINGLE_LINE_INPUT_BOX_AUTO_CLEAR_HIGHLIGHT_MODE) &&            
            #endif /*__MMI_EDITOR_SL_AUTO_CLEAR_HILITE_MODE__*/
            
            #ifdef __MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__
            !(MMI_singleline_inputbox.ext_flags & GUI_SINGLE_LINE_INPUT_BOX_RECIPIENT_MODE) &&
            #endif /*__MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__*/
            !(MMI_singleline_inputbox.ext_flags & GUI_SINGLE_LINE_INPUT_BOX_RECIPIENT_SEMICOLON_MODE))
        {
            pre_c = 0;
            
            if (MMI_singleline_inputbox.current_text_p > MMI_singleline_inputbox.text)
            {
                pre_c = (UI_character_type)((*((MMI_singleline_inputbox.current_text_p - ENCODING_LENGTH)+0))|((*((MMI_singleline_inputbox.current_text_p - ENCODING_LENGTH)+1))<<8));
            }

            c = (UI_character_type)((*((MMI_singleline_inputbox.current_text_p)+0))|((*((MMI_singleline_inputbox.current_text_p)+1))<<8));

            if (c == 0 && pre_c != 0 && pre_c != L' ')
            {
                wgui_inputs_sl_direct_input(L' ');
                
                return;
            }
        }
        gui_single_line_input_box_next(&MMI_singleline_inputbox);
    }
    wgui_inputs_sl_redraw();
#ifdef __MMI_PINYIN_SEARCH__
    if (inPinyinSearchScreen)
    {
        wgui_inputs_redraw_input_mode_only();
        wgui_title_set_menu_shortcut_handler_display(MMI_TRUE);
    }
#endif /* __MMI_PINYIN_SEARCH__ */ 
    singleline_inputbox_navigate_callback();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_toggle_insert_mode
 * DESCRIPTION
 *  Toggles between insert and overwrite modes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_toggle_insert_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_single_line_input_box_toggle_insert_mode(&MMI_singleline_inputbox);
    wgui_inputs_sl_redraw();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_delete_current_character
 * DESCRIPTION
 *  Deletes a character at the cursor position (Delete)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_delete_current_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_single_line_input_box_delete_current_character(&MMI_singleline_inputbox);
    wgui_inputs_sl_redraw();
    singleline_inputbox_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_delete_all_characters
 * DESCRIPTION
 *  Deletes all characters
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_delete_all_characters(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_TOUCH_SCREEN__)
    kal_bool is_enabled, is_pen_down;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == gui_single_line_input_box_delete_all(&MMI_singleline_inputbox))
    {
    #if defined(__MMI_TOUCH_SCREEN__)
        mmi_pen_get_state(&is_enabled, &is_pen_down);
        if (is_pen_down)
    #endif
        {
            gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_HOLD);
        }
        wgui_inputs_sl_redraw();
        singleline_inputbox_input_callback();
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_handle_key_down
 * DESCRIPTION
 *  Keypad Key down handler
 *  
 *  Internal function
 * PARAMETERS
 *  k           [IN]        
 *  keyc(?)     [IN]        Is the keypad key code.
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_handle_key_down(MMI_key_code_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MULTITAP_ARABIC__)
    if (mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_ARABIC_NUMERIC )
        wgui_inputs_sl_direct_input((UI_character_type) (0x0660 + k));
    else
#endif
    wgui_inputs_sl_direct_input((UI_character_type) ('0' + k));
#ifdef __MMI_PINYIN_SEARCH__
    if (inPinyinSearchScreen)
    {
        PbookListSearchEntryReq();
        wgui_inputs_redraw_input_mode_only();
    }
#endif /* __MMI_PINYIN_SEARCH__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_key_handler
 * DESCRIPTION
 *  Keyboard (simulator) key handler for the singleline inputbox
 *  
 *  Internal function
 * PARAMETERS
 *  vkey_code       [IN]        Is the scan code of the key
 *  key_state       [IN]        Is the key event type (up, down ...)
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_key_handler(S32 vkey_code, S32 key_state)
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
        #if(ENABLE_SINGLELINE_INPUTBOX_TEST_WORD_HIGHLIGHT)
                MMI_singleline_inputbox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        #endif 
                wgui_inputs_sl_previous_character();
                break;

            case 38:    /* up */
        #if(ENABLE_SINGLELINE_INPUTBOX_TEST_WORD_HIGHLIGHT)
                gui_single_line_input_box_highlight_cursor_start(&MMI_singleline_inputbox);
                wgui_inputs_sl_show();
        #endif /* (ENABLE_SINGLELINE_INPUTBOX_TEST_WORD_HIGHLIGHT) */ 
                break;

            case 39:
        #if(ENABLE_SINGLELINE_INPUTBOX_TEST_WORD_HIGHLIGHT)
                MMI_singleline_inputbox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        #endif 
                wgui_inputs_sl_next_character();
                break;
            case 40:    /* down */
        #if(ENABLE_SINGLELINE_INPUTBOX_TEST_WORD_HIGHLIGHT)
                gui_single_line_input_box_highlight_cursor_end(&MMI_singleline_inputbox);
                wgui_inputs_sl_show();
        #endif /* (ENABLE_SINGLELINE_INPUTBOX_TEST_WORD_HIGHLIGHT) */ 
                break;
            case 36:    /* home */
                break;
            case 35:    /* end */
                break;
            case 33:    /* page up */
                break;
            case 34:    /* page down */
                break;
            case 45:
                wgui_inputs_sl_toggle_insert_mode();
                break;
            case 46:
                wgui_inputs_sl_delete_current_character();
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
 *  wgui_inputs_sl_register_keys
 * DESCRIPTION
 *  Registers the keys for the singleline inputbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_register_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_is_disable_left_right_key_register == MMI_FALSE)
    {
        SetKeyHandler(wgui_inputs_sl_previous_character, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(wgui_inputs_sl_next_character, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

        SetKeyHandler(wgui_inputs_sl_handle_left_arrow_repeat, KEY_LEFT_ARROW, KEY_REPEAT);
        SetKeyHandler(wgui_inputs_sl_handle_right_arrow_repeat, KEY_RIGHT_ARROW, KEY_REPEAT);
        SetKeyHandler(wgui_inputs_fast_del_nav_reset_repeat_count, KEY_LEFT_ARROW, KEY_LONG_PRESS);
        SetKeyHandler(wgui_inputs_fast_del_nav_reset_repeat_count, KEY_RIGHT_ARROW, KEY_LONG_PRESS);
    }

    if (g_is_disable_up_down_key_register == MMI_FALSE)
    {
        SetKeyHandler(wgui_inputs_sl_cannot_navigate, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(wgui_inputs_sl_cannot_navigate, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
   }
    /* SetKeyHandler(singleline_inputbox_delete_character,KEY_CLEAR,KEY_EVENT_DOWN); */
    register_keyboard_key_handler(wgui_inputs_sl_key_handler);
    /* Add key handlers here for Clear key and input mode key   */

#if defined(__COSMOS_MMI_PACKAGE__)
    SetKeyHandler(wgui_inputs_sl_delete_character, KEY_CLEAR, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_inputs_sl_delete_all_characters, KEY_CLEAR, KEY_LONG_PRESS);
   // SetKeyHandler(wgui_inputs_sl_delete_character, KEY_VOL_DOWN, KEY_EVENT_DOWN);
   // SetKeyHandler(wgui_inputs_sl_delete_all_characters, KEY_VOL_DOWN, KEY_LONG_PRESS);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_cannot_navigate
 * DESCRIPTION
 *  Up/down/left/right key cannot navigate handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_cannot_navigate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_editor_play_tone_cannot_navigate();
    wgui_inputs_sl_redraw();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_disable_up_down_key_register
 * DESCRIPTION
 *  Registers the keys for the singleline inputbox
 * PARAMETERS
 *  is_diable   [in]    if disable up down key handler register
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_disable_up_down_key_register(MMI_BOOL is_disable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_is_disable_up_down_key_register = is_disable;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_disable_left_right_key_register
 * DESCRIPTION
 *  Disable registers the left/right keys for the singleline inputbox
 * PARAMETERS
 *  is_diable   [in]    if disable left/right key handler register
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_disable_left_right_key_register(MMI_BOOL is_disable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_is_disable_left_right_key_register = is_disable;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_set_mask
 * DESCRIPTION
 *  Sets masked display of characters
 * PARAMETERS
 *  m       [IN]        0: Normal, 1: Masked
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_set_mask(U8 m)
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
            MMI_singleline_inputbox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_MASK_CHARACTERS;
            break;
        case 1:
            MMI_singleline_inputbox.flags |= UI_SINGLE_LINE_INPUT_BOX_MASK_CHARACTERS;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_reset
 * DESCRIPTION
 *  Removes the keyhandlers for the singleline inputbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_reset(void)
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
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_SINGLELINE_INPUTBOX_FRAME_SKIPPING))
    gui_cancel_timer(wgui_inputs_sl_end_frame);
    wgui_singleline_inputbox_frame_counter = 0;
#endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_SINGLELINE_INPUTBOX_FRAME_SKIPPING)) */ 
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_UP);
    ClearKeyHandler(KEY_CLEAR, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_CLEAR, KEY_EVENT_UP);
    ClearKeyHandler(KEY_CLEAR, KEY_EVENT_LONG_PRESS);
    clear_keyboard_key_handler();
    clear_keyboard_input_handler();
    wgui_inputs_multitap_clear_key_handlers();
    singleline_inputbox_input_callback = UI_dummy_function;
    singleline_inputbox_navigate_callback = UI_dummy_function;
    g_is_disable_up_down_key_register = MMI_TRUE;
    g_is_disable_left_right_key_register = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_get_display_status
 * DESCRIPTION
 *  to see if display singleline inputbox
 * PARAMETERS
 *  void
 *  width(?)        [IN]        Is the new width
 *  height(?)       [IN]        Is the new height
 * RETURNS
 *  void
 * VJ
 *****************************************************************************/
MMI_BOOL wgui_inputs_sl_get_display_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_singleline_inputbox.flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_resize
 * DESCRIPTION
 *  Resizes the singleline input box
 * PARAMETERS
 *  width       [IN]        Is the new width
 *  height      [IN]        Is the new height
 * RETURNS
 *  void
 * VJ
 *****************************************************************************/
void wgui_inputs_sl_resize(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_resize_single_line_input_box(&MMI_singleline_inputbox, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_resize_fix
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_resize_fix(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 string_width = 0, string_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_measure_string((UI_string_type) MMI_singleline_inputbox.text, &string_width, &string_height);
    gui_resize_single_line_input_box(&MMI_singleline_inputbox, string_width + 6, string_height + 6);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_move
 * DESCRIPTION
 *  Resizes the singleline input box
 * PARAMETERS
 *  x               [IN]        
 *  y               [IN]        
 *  width(?)        [IN]        Is the new width
 *  height(?)       [IN]        Is the new height
 * RETURNS
 *  void
 * VJ
 *****************************************************************************/
void wgui_inputs_sl_move(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_move_single_line_input_box(&MMI_singleline_inputbox, x, y);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_register_input_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_register_input_callback(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    singleline_inputbox_input_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_register_navigate_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_register_navigate_callback(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    singleline_inputbox_navigate_callback = f;
}

#if 0 /* slim_2_2 */ //
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
#endif

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_is_empty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 wgui_inputs_sl_is_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_singleline_inputbox.text_length <= 2)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

/* Function Added To Display Remaining Character for Single Line Box */


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_redraw_remaining_characters_display
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_redraw_remaining_characters_display(void)
{
#ifndef __MMI_HIDE_SGL_REMAINING_CHAR__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    color c;

    /* for R2L characters */
    S32 x1;
    S32 x2;
    S32 y1 = wgui_inputbox_information_bar_y;
    S32 y2 = wgui_inputbox_information_bar_y + wgui_inputbox_information_bar_height - 1;

#if !defined(__MMI_TOUCH_SCREEN__)
    stFontAttribute *f = &MMI_small_font;
#else /* !defined(__MMI_TOUCH_SCREEN__) */ 
    stFontAttribute *f = &MMI_medium_font;
#endif /* !defined(__MMI_TOUCH_SCREEN__) */
    S32 w, h, n, max_n;
    UI_character_type str[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* for R2L characters */
    if (!mmi_fe_get_r2l_state())
    {
        x1 = wgui_inputbox_information_bar_x + (wgui_inputbox_information_bar_width >> 1);
        x2 = wgui_inputbox_information_bar_x + wgui_inputbox_information_bar_width - 1;
    }
    else
    {
        x1 = wgui_inputbox_information_bar_x;
        x2 = wgui_inputbox_information_bar_x + (wgui_inputbox_information_bar_width / 2) - 1;

    }

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    /* Warning: Temporary change only UCS2 / ASCII. This has to be done in a more formal manner  */
    n = (MMI_singleline_inputbox.text_length >> 1) - 1;
    max_n = (MMI_singleline_inputbox.available_length >> 1) - 1;
    if ((MMI_singleline_inputbox.flags & UI_SINGLE_LINE_INPUT_BOX_CHECK_GSM_EXTENDED) &&
        (MMI_singleline_inputbox.UCS2_count == 0))
    {
        n += MMI_singleline_inputbox.GSM_ext_count;
    }
    if ((MMI_singleline_inputbox.flags & UI_SINGLE_LINE_INPUT_BOX_PLUS_CHARACTER_HANDLING) &&
        (MMI_singleline_inputbox.text[0] == '+'))
    {
        n--;
        max_n--;
    }

    /* sms recipient mode support */
    if (MMI_singleline_inputbox.ext_flags & GUI_SINGLE_LINE_INPUT_BOX_RECIPIENT_SEMICOLON_MODE)
    {
        UI_buffer_type text_p;
        UI_character_type current_character;
        text_p = MMI_singleline_inputbox.text + MMI_singleline_inputbox.text_length - 2 * ENCODING_LENGTH;
        UI_STRING_GET_NEXT_CHARACTER(text_p, current_character);
        if (UI_TEST_SEMICOLON_CHAR(current_character))
        {
            n--;
        }
        max_n--;
    }

    /* if(!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INCLUDE_INFO_AREA)) */
    wgui_inputs_input_information_background(x1, y1, x2, y2);
    gui_reset_text_clip();
    gui_sprintf(str, "%d/%d", n, max_n);
    c = *current_MMI_theme->remaining_length_text_color;
    gui_set_font(f);
    gui_set_text_color(c);
    gui_set_text_clip(0, 0, UI_device_width - 1, UI_device_height - 1);

    gui_measure_string(str, &w, &h);

    /* for R2L characters */
    if (!mmi_fe_get_r2l_state())
    {
        gui_move_text_cursor(x2 - 2 - w, y1 + (wgui_inputbox_information_bar_height - h) / 2);
    }
    else
    {
        gui_move_text_cursor(x1 + 2 + w, y1 + (wgui_inputbox_information_bar_height - h) / 2);
    }

    gui_print_text(str);
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 

#endif /* __MMI_HIDE_SGL_REMAINING_CHAR__ */ 
}

/* Function Added To Display Information Bar For Single Line Input Box */


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_redraw_information_bar
 * DESCRIPTION
 *  redrwa input information bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_redraw_information_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 x1 = wgui_inputbox_information_bar_x;
    S32 y1 = wgui_inputbox_information_bar_y;
    S32 x2 = wgui_inputbox_information_bar_x + wgui_inputbox_information_bar_width - 1;
    S32 y2 = wgui_inputbox_information_bar_y + wgui_inputbox_information_bar_height - 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    wgui_inputs_input_information_background(x1, y1, x2, y2);
    wgui_inputs_show_input_mode(mmi_imm_get_curr_input_mode(), NULL);
    wgui_inputs_sl_redraw_remaining_characters_display();
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_set_category_history_ext
 * DESCRIPTION
 *  Sets the history data for the singleline inputbox from the given history buffer
 * PARAMETERS
 *  history_ID          [IN]        Is the ID used by category screens
 *  history_buffer      [IN]        Is the buffer from which history data is taken
 *  input_type          [?]         
 * RETURNS
 *  Returns true if the history ID is valid
 *****************************************************************************/
U8 wgui_inputs_sl_set_category_history_ext(single_line_input_box *b, U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        singleline_inputbox_category_history *h = (singleline_inputbox_category_history*) history_buffer;

        if (history_valid(h->history_ID, history_ID))
        {
            b->text_length = h->text_length;
            b->allocated_length = h->allocated_length;
            b->available_length = h->available_length;
            b->current_text_p =
                (UI_buffer_type) (b->text + h->current_position);
            b->text_offset_x = h->text_offset_x;
            b->UCS2_count = h->UCS2_count;
            b->flags = h->flags;
            b->highlight_start_position = h->highlight_start_position;
            b->highlight_end_position = h->highlight_end_position;
            return (1);
        }
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_set_category_history
 * DESCRIPTION
 *  Sets the history data for the singleline inputbox from the given history buffer
 * PARAMETERS
 *  history_ID          [IN]        Is the ID used by category screens
 *  history_buffer      [IN]        Is the buffer from which history data is taken
 *  input_type          [?]         
 * RETURNS
 *  Returns true if the history ID is valid
 *****************************************************************************/
U8 wgui_inputs_sl_set_category_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wgui_inputs_sl_set_category_history_ext(&MMI_singleline_inputbox, history_ID, history_buffer);
}

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_get_category_history
 * DESCRIPTION
 *  gets the history data for the singleline inputbox from the given history buffer
 * PARAMETERS
 *  history_ID          [IN]        Is the ID used by category screens
 *  history_buffer      [IN]        Is the buffer from which history data is taken
 *  input_type          [IN]        
 * RETURNS
 *  Returns true if the history ID is valid(?)
 *****************************************************************************/
void wgui_inputs_sl_get_category_history_ext(single_line_input_box *b, U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        U16 hID = (U16) (history_ID | 0x8000);
        singleline_inputbox_category_history *h = (singleline_inputbox_category_history*) history_buffer;

        h->history_ID = hID;
        h->text_length = (S16) b->text_length;
        h->allocated_length = (S16) b->allocated_length;
        h->available_length = (S16) b->available_length;
        h->current_position = (S16) (b->current_text_p - b->text);
        h->text_offset_x = (S16) b->text_offset_x;
        h->UCS2_count = (S16) b->UCS2_count;
        h->flags = (U32) b->flags;
        h->highlight_start_position = b->highlight_start_position;
        h->highlight_end_position = b->highlight_end_position;
        /* W06.48 - for removing multitap state when exiting category */
        if ((h->flags & UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP) || (h->flags & UI_SINGLE_LINE_INPUT_BOX_INPUT_METHOD_MODE) ||
            mmi_imc_is_clipboard_state())
        {
            h->flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        }
        h->flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP;
        h->flags &= ~UI_SINGLE_LINE_INPUT_BOX_INPUT_METHOD_MODE;

        mmi_imc_get_input_method_history(&(h->ime_history));
		h->ime_history.state = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_get_category_history
 * DESCRIPTION
 *  gets the history data for the singleline inputbox from the given history buffer
 * PARAMETERS
 *  history_ID          [IN]        Is the ID used by category screens
 *  history_buffer      [IN]        Is the buffer from which history data is taken
 *  input_type          [IN]        
 * RETURNS
 *  Returns true if the history ID is valid(?)
 *****************************************************************************/
void wgui_inputs_sl_get_category_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_sl_get_category_history_ext(&MMI_singleline_inputbox, history_ID, history_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_handle_right_softkey_down
 * DESCRIPTION
 *  handle single line input box RSK down key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_handle_right_softkey_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__
    if (MMI_singleline_inputbox.ext_flags & GUI_SINGLE_LINE_INPUT_BOX_RECIPIENT_MODE)
    {
        wgui_inputs_sl_delete_all_characters();
        MMI_singleline_inputbox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        return;
    }
    #endif /*__MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__*/

    if (wgui_singleline_inputbox_decimal_input_mode_flag)
    {
        wgui_inputs_sl_check_decimal();
        #if 0 /* slim_2_2 */ //
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
        if (gui_single_line_input_box_get_text_length(&MMI_singleline_inputbox) > 0)
        {
            wgui_inputs_sl_delete_character();
        }
    }
    else
    {
        if (gui_single_line_input_box_get_text_length(&MMI_singleline_inputbox) > 0)
        {
            UI_buffer_type p = MMI_singleline_inputbox.current_text_p;
            
            wgui_inputs_sl_delete_character();
            /* if the text buffer length is zero, it's not required to call this function to redraw screen */
            if (cat200_search_function 
                && p != MMI_singleline_inputbox.text)
            {
#ifdef __MMI_PHB_QUICK_SEARCH__     //**/                  
                refresh_search_list(MMI_singleline_inputbox.text);
#endif /*__MMI_PHB_QUICK_SEARCH__*/
            }
        #ifdef __MMI_CAT103_SUPPORT__
            else if (g_wgui_cat103_search_function
                     && p != MMI_singleline_inputbox.text)
            {
                wgui_cat103_refresh_search_list(MMI_singleline_inputbox.text);
            }
        #endif /* __MMI_CAT103_SUPPORT__ */

        #ifdef __MMI_PINYIN_SEARCH__
            if (inPinyinSearchScreen)
            {
                PbookListSearchEntryReq();
            }
        #endif /* __MMI_PINYIN_SEARCH__ */ 
        }
        else
        {
            if (!(MMI_singleline_inputbox.flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
            {
                UI_editor_play_tone_cannot_change();
                return;
            }
        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_handle_right_softkey_up
 * DESCRIPTION
 *  handle single line input box RSK up  key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_handle_right_softkey_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_singleline_inputbox_RSK_function != NULL)
    {
        wgui_singleline_inputbox_RSK_function();
    }
    else
    {
        mmi_event_struct evt;

        MMI_FRM_INIT_EVENT(&evt, 0);
        evt.evt_id = EVT_ID_WGUI_RSK_CLICK;
        MMI_FRM_CB_EMIT_EVENT(&evt);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_register_handle_right_softkey_up
 * DESCRIPTION
 *  register a function handler of RSK up key of single input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_register_handle_right_softkey_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_right_softkey_function(wgui_inputs_sl_handle_right_softkey_up, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_register_handle_clear_key_up
 * DESCRIPTION
 *  register a function handler of RSK up key of single input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_register_handle_clear_key_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(wgui_inputs_sl_handle_right_softkey_up, KEY_CLEAR, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_handle_right_softkey_long_press
 * DESCRIPTION
 *  handle long press of RSK of single input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_handle_right_softkey_long_press(void)
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
        SetKeyHandler(wgui_inputs_sl_handle_right_softkey_repeat, KEY_CLEAR, KEY_REPEAT);
    }
    else
    {        
        set_right_softkey_function(wgui_inputs_sl_handle_right_softkey_touch_repeat, KEY_REPEAT);
        SetKeyHandler(wgui_inputs_sl_handle_right_softkey_repeat, KEY_RSK, KEY_REPEAT); 
    }

    if (gui_single_line_input_box_test_first_position(&MMI_singleline_inputbox))
    {
        return;
    }

#ifdef __MMI_CAT103_SUPPORT__
    else if (g_wgui_cat103_search_function)
    {
        wgui_cat103_refresh_search_list(MMI_singleline_inputbox.text);
    }
#endif /* __MMI_CAT103_SUPPORT__ */

}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_handle_input
 * DESCRIPTION
 *  handle input of single line input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_handle_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gui_single_line_input_box_get_text_length(&MMI_singleline_inputbox) > 0)
    {
        if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
        {
            if (wgui_singleline_inputbox_RSK_label_clear == 0)
            {
                if (wgui_inputbox_not_empty_callback != NULL)
                {
                    wgui_inputbox_not_empty_callback();
                }
                wgui_singleline_inputbox_RSK_label_clear = 1;
                SetKeyHandler(wgui_inputs_sl_handle_right_softkey_down, KEY_CLEAR, KEY_EVENT_DOWN);
                SetKeyHandler(UI_dummy_function, KEY_CLEAR, KEY_EVENT_UP);
                SetKeyHandler(wgui_inputs_sl_handle_right_softkey_long_press, KEY_CLEAR, KEY_EVENT_LONG_PRESS);

            }
        }
        else
        {
            if (wgui_singleline_inputbox_RSK_label_clear == 0)
            {
                set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_CLEAR));
                set_right_softkey_icon(NULL);

                redraw_right_softkey();
                wgui_singleline_inputbox_RSK_label_clear = 1;
                set_right_softkey_function(NULL, KEY_EVENT_UP);
                set_right_softkey_function(wgui_inputs_sl_handle_right_softkey_down, KEY_EVENT_DOWN);
                set_right_softkey_function(wgui_inputs_sl_handle_right_softkey_long_press, KEY_EVENT_LONG_PRESS);

                if (wgui_inputbox_not_empty_callback != NULL)
                {
                    wgui_inputbox_not_empty_callback();
                }
            }
        }
    }
    else
    {
        if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
        {
            if (wgui_singleline_inputbox_RSK_label_clear == 1)
            {
                if (wgui_inputbox_empty_callback != NULL)
                {
                    wgui_inputbox_empty_callback();
                }
                wgui_singleline_inputbox_RSK_label_clear = 0;
                SetKeyHandler(wgui_inputs_sl_handle_right_softkey_down, KEY_CLEAR, KEY_EVENT_DOWN);
                /* MTK Terry Temp solution for C key in Enter Pin */
                SetKeyHandler(UI_dummy_function, KEY_CLEAR, KEY_EVENT_UP);
                SetKeyHandler(UI_dummy_function, KEY_CLEAR, KEY_EVENT_LONG_PRESS);

            }
        }
        else
        {
            if (wgui_singleline_inputbox_RSK_label_clear == 1)
            {
                BOOL gdi_freeze = gdi_lcd_get_freeze();
                gdi_lcd_freeze(TRUE);

                set_right_softkey_label(wgui_singleline_inputbox_RSK_label_string);
                set_right_softkey_icon(wgui_singleline_inputbox_RSK_label_icon);

                redraw_right_softkey();
                register_right_softkey_handler();
                wgui_singleline_inputbox_RSK_label_clear = 0;
                set_right_softkey_function(wgui_inputs_sl_register_handle_right_softkey_up, KEY_EVENT_DOWN);

                if (wgui_inputbox_empty_callback != NULL)
                {
                    wgui_inputbox_empty_callback();
                }
                gdi_lcd_freeze(gdi_freeze);
                gdi_layer_blt_previous(0,0,UI_device_width-1, UI_device_height-1);
            }
            else
            {
                set_right_softkey_label(wgui_singleline_inputbox_RSK_label_string);
                set_right_softkey_icon(wgui_singleline_inputbox_RSK_label_icon);
                redraw_right_softkey();
            }
        }
    }

    if ((MMI_singleline_inputbox.flags & UI_SINGLE_LINE_INPUT_BOX_PLUS_CHARACTER_HANDLING) &&
        (MMI_singleline_inputbox.text[0] == '+'))
    {
        MMI_singleline_inputbox.available_length = (wgui_singleline_inputbox_buffer_size + 1) * ENCODING_LENGTH;
    }
    else
    {
        MMI_singleline_inputbox.available_length = wgui_singleline_inputbox_buffer_size * ENCODING_LENGTH;
    }

#if defined(__UI_UNIFIED_COMPOSER_EDITOR_CATEGORY__) && defined(__MMI_FTE_SUPPORT__)
    if (wgui_inputbox_information_flag && (g_dm_data.s32CatId != MMI_CATEGORY280_ID))
#else
    if (wgui_inputbox_information_flag && (g_dm_data.s32CatId != MMI_CATEGORY280_ID) && (g_dm_data.s32CatId != MMI_CATEGORY28_ID))
#endif
    {
        wgui_inputs_sl_redraw_information_bar();
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_handle_navigate
 * DESCRIPTION
 *  handle navigation  of single line input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_handle_navigate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gui_single_line_input_box_test_first_position(&MMI_singleline_inputbox) ||
        (gui_single_line_input_box_get_text_length(&MMI_singleline_inputbox) <= 0))
    {
        if (wgui_singleline_inputbox_RSK_label_clear == 1)
        {
            set_right_softkey_label(wgui_singleline_inputbox_RSK_label_string);
            set_right_softkey_icon(wgui_singleline_inputbox_RSK_label_icon);
            redraw_right_softkey();
            wgui_singleline_inputbox_RSK_label_clear = 0;
            set_right_softkey_function(wgui_inputs_sl_handle_right_softkey_up, KEY_EVENT_UP);
            set_right_softkey_function(UI_dummy_function, KEY_EVENT_DOWN);
        }
    }
    else
    {
        if (wgui_singleline_inputbox_RSK_label_clear == 0)
        {
            set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_CLEAR));
            set_right_softkey_icon(NULL);
            redraw_right_softkey();
            wgui_singleline_inputbox_RSK_label_clear = 1;
            set_right_softkey_function(UI_dummy_function, KEY_EVENT_UP);
            set_right_softkey_function(wgui_inputs_sl_handle_right_softkey_down, KEY_EVENT_DOWN);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_validation_callback
 * DESCRIPTION
 *  input box validation call back function
 * PARAMETERS
 *  text            [IN]        Buffer of input box
 *  cursor          [IN]        
 *  text_length     [IN]        Length of text
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_validation_callback(UI_buffer_type text, UI_buffer_type cursor, S32 text_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_inputbox_validation_callback != NULL  && mmi_imc_is_ime_state() == MMI_FALSE)
    {
        wgui_inputbox_validation_callback(text, cursor, text_length);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_get_ucs2_count
 * DESCRIPTION
 *  UCS2 coumt of input box :- length of string in UNCODE mode of input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 wgui_inputs_sl_get_ucs2_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_singleline_inputbox.UCS2_count);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_get_ext_gsm_count
 * DESCRIPTION
 *  Returns the number of GSM extended characters in the
 *  single line input box buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  Number of GSM extended characters
 *****************************************************************************/
S32 wgui_inputs_sl_get_ext_gsm_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_singleline_inputbox.GSM_ext_count);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_set_RSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_set_RSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_singleline_inputbox_RSK_label_clear = 0;
    if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
    {
        SetKeyHandler(wgui_inputs_sl_handle_right_softkey_down, KEY_CLEAR, KEY_EVENT_DOWN);
        SetKeyHandler(wgui_inputs_sl_handle_right_softkey_long_press, KEY_CLEAR, KEY_LONG_PRESS);
        set_right_softkey_function(wgui_inputs_sl_handle_right_softkey_up, KEY_EVENT_UP);
    }
    else
    {
        set_right_softkey_function(wgui_inputs_sl_handle_right_softkey_down, KEY_EVENT_DOWN);
        set_right_softkey_function(wgui_inputs_sl_handle_right_softkey_long_press, KEY_LONG_PRESS);
    }
    wgui_inputs_sl_handle_input();
    if (gui_single_line_input_box_get_text_length(&MMI_singleline_inputbox) <= 0)
    {
        if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
        {
            /* Temp solution for C key in Enter Pin */
            SetKeyHandler(UI_dummy_function, KEY_CLEAR, KEY_EVENT_UP);
        }
        else
        {
            set_right_softkey_function(wgui_inputs_sl_register_handle_right_softkey_up, KEY_EVENT_DOWN);
            set_right_softkey_function(UI_dummy_function, KEY_EVENT_LONG_PRESS);
        }     
        if (wgui_inputbox_empty_callback != NULL)
        {
            wgui_inputbox_empty_callback();
        }
    }
    else if (wgui_inputbox_not_empty_callback != NULL)
    {
        wgui_inputbox_not_empty_callback();
    }
    MMI_singleline_inputbox.validation_callback = wgui_inputs_sl_validation_callback;
    MMI_singleline_inputbox.validation_callback(
                                MMI_singleline_inputbox.text,
                                MMI_singleline_inputbox.current_text_p,
                                (MMI_singleline_inputbox.text_length >> 1) - 1);
    register_right_softkey_handler();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_setup_ext
 * DESCRIPTION
 *  create single line input box
 * PARAMETERS
 *  x                           [IN]        Start x of single line input box
 *  y                           [IN]        Stsrt y of single line input box
 *  width                       [IN]        Width of single line input box
 *  height                      [IN]        Height of single line input box
 *  buffer                      [IN]        Buffer of single line input box
 *  buffer_size                 [IN]        Size of buffer
 *  category_screen_ID          [IN]        Id ofcategory screen
 *  RSK_label                   [IN]        String of RSK
 *  RSK_icon                    [IN]        Icon of RSK
 *  input_type                  [IN]        
 *  history_buffer              [IN]        History buffer
 *  information_bar_flag        [IN]        
 *  input(?)                    [IN]        Type
 *  Change(?)                   [IN]        The parameter for setup function - Gurinder - 23/4/2004
 * RETURNS
 *  void
 *****************************************************************************/
/* Change the parameter for setup function */
void wgui_inputs_sl_setup_ext(
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        U8 *buffer,
        S32 buffer_size,
        U16 category_screen_ID,
        UI_string_type RSK_label,
        PU8 RSK_icon,
        U32 input_type,
        U8 *history_buffer,
        U8 information_bar_flag,
        U32 (*msg_call_back) (void * input_box_handle, mmi_imc_message_struct_p msg_ptr))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 l;
    U32 input_type_flags = input_type & (~INPUT_TYPE_MASK);
    U32 saved_inputbox_flags;
    U8 plus_character_handling = 0;
    U8 h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_singleline_inputbox_buffer_size = buffer_size;
    if (input_type & INPUT_TYPE_PLUS_CHARACTER_HANDLING)
    {
        plus_character_handling = 1;
    }

    wgui_inputs_set_current_input_box_type(EDITOR_SINGLE_LINE_INPU_BOX);

    #if defined(__MMI_INDIC_ALG__)
	/*set up required in indic engine when single-line editor is launched*/
    ire_set_use_multitap_single_line();
    #endif

    l = gui_strlen((UI_string_type) buffer);
    wgui_inputs_sl_create_set_buffer((UI_string_type) buffer, buffer_size, l, l);
    wgui_inputs_sl_register_keys();
    /* Information Bar Setup For Single Line Box */
    if (information_bar_flag)
    {
        wgui_inputbox_information_flag = 1;
        wgui_inputbox_information_bar_height = INFORMATION_BAR_HEIGHT;
        wgui_inputs_setup_input_information(
            0,
            (MMI_title_y + MMI_title_height),
            UI_device_width,
            wgui_inputbox_information_bar_height);
    }

    wgui_inputs_sl_move(x, y);
    wgui_inputs_sl_resize(width, height);

    wgui_singleline_inputbox_decimal_input_mode_flag = 0;
    wgui_singleline_inputbox_decimal_flag = 0;

    h = wgui_inputs_sl_set_category_history(category_screen_ID, history_buffer);
    
    saved_inputbox_flags = MMI_singleline_inputbox.flags;
    
    input_type |= input_type_flags;
    wgui_singleline_inputbox_decimal_input_mode_flag = 0;
    wgui_inputbox_UCS2_count_function = wgui_inputs_sl_get_ucs2_count;
    wgui_inputbox_GSM_ext_count_function = wgui_inputs_sl_get_ext_gsm_count;
    if (input_type & INPUT_TYPE_USE_ENCODING_BASED_LENGTH)
    {
        MMI_singleline_inputbox.flags |= UI_SINGLE_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH;
        if (input_type & INPUT_TYPE_ONE_LESS_CHARACTER)
        {
            MMI_singleline_inputbox.flags |= UI_SINGLE_LINE_INPUT_BOX_ONE_LESS_CHARACTER;
            UI_TEST_UCS2_COUNT_SET_LENGTH_TYPE2(
                MMI_singleline_inputbox.UCS2_count,
                MMI_singleline_inputbox.allocated_length,
                MMI_singleline_inputbox.available_length);
        }
        if (input_type & INPUT_TYPE_ONE_LESS_CHARACTER)
        {
            MMI_singleline_inputbox.flags |= UI_SINGLE_LINE_INPUT_BOX_ONE_LESS_CHARACTER;
            UI_TEST_UCS2_COUNT_SET_LENGTH_TYPE2(
                MMI_singleline_inputbox.UCS2_count,
                MMI_singleline_inputbox.allocated_length,
                MMI_singleline_inputbox.available_length);
        }
        else
        {
            UI_TEST_UCS2_COUNT_SET_LENGTH(
                MMI_singleline_inputbox.UCS2_count,
                MMI_singleline_inputbox.allocated_length,
                MMI_singleline_inputbox.available_length);
        }
    }
    if (plus_character_handling)
    {
        MMI_singleline_inputbox.flags |= UI_SINGLE_LINE_INPUT_BOX_PLUS_CHARACTER_HANDLING;

        if (MMI_singleline_inputbox.text[0] == '+')
        {
            MMI_singleline_inputbox.available_length = (wgui_singleline_inputbox_buffer_size + 1) * ENCODING_LENGTH;
        }
    }
    
    if ((saved_inputbox_flags & UI_SINGLE_LINE_INPUT_BOX_MASK_CHARACTERS))
    {
        wgui_inputs_sl_set_mask(1);
    }
    wgui_singleline_inputbox_RSK_label_clear = 0;
    wgui_singleline_inputbox_RSK_label_icon = RSK_icon;
    wgui_singleline_inputbox_RSK_label_string = RSK_label;

    wgui_inputs_sl_set_RSK();
    wgui_inputs_sl_register_input_callback(wgui_inputs_sl_handle_input);

    if (h)
    {
        mmi_imc_set_input_method_history(&(((singleline_inputbox_category_history*)history_buffer)->ime_history));
    }
    
    mmi_imm_set_required_mode_list(input_type & INPUT_TYPE_MASK, NULL, IMM_INPUT_MODE_NONE);

    g_mmi_editor_hanler.input_box_type = MMI_EDITOR_SINGLE_LINE_INPU_BOX;

    if (cat200_search_function)
    {
    #if defined(__MMI_TOUCH_SCREEN__)
        mmi_imc_disable_handwriting();
    #endif /* defined(__MMI_TOUCH_SCREEN__) */
        g_mmi_editor_hanler.input_box_sub_type = MMI_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPUT_BOX;
    }
#if defined(__MMI_CAT116_SUPPORT__)
    else if (g_wgui_cat116_resize_and_draw_func)
    {
        g_mmi_editor_hanler.input_box_sub_type = MMI_EDITOR_CALL_PLAN_SINGLE_LINE_INPUT_BOX;
    }
#endif /* defined(__MMI_CAT116_SUPPORT__) */
#if defined(__MMI_CAT103_SUPPORT__)
    else if (g_wgui_cat103_resize_and_draw_func)
    {
#if defined(__MMI_TOUCH_SCREEN__)
        mmi_imc_disable_handwriting();
#endif /* defined(__MMI_TOUCH_SCREEN__) */
        g_mmi_editor_hanler.input_box_sub_type = MMI_EDITOR_AUTO_URL_COMPLETION_SINGLE_LINE_INPUT_BOX;
    }
#endif /* defined(__MMI_CAT103_SUPPORT__) */
#ifdef __MMI_SEARCH_WEB__
    else if (g_wgui_cat2001_resize_and_draw_func)
    {
        g_mmi_editor_hanler.input_box_sub_type = MMI_EDITOR_BAIDU_SEARCH_SINGLE_LINE_INPUT_BOX;
    }
#endif /* __MMI_SEARCH_WEB__  */
#if defined(__MMI_CAT203_SUPPORT__) && defined(__MMI_FTE_SUPPORT__)
    else if (g_wgui_cat203_resize_and_draw_func)
    {
        mmi_imm_set_required_mode_list(
            (IMM_INPUT_TYPE_SPECIAL_EXT_SHOW_DIALER_VK | IMM_INPUT_TYPE_PHONE_NUMBER), 
            NULL, 
            IMM_INPUT_MODE_PHONE_NUMBER);
        g_mmi_editor_hanler.input_box_sub_type = MMI_EDITOR_DIALER_SEARCH_MULTI_LINE_INPUT_BOX;
    }
#endif /* defined(__MMI_CAT203_SUPPORT__) */

    else
    {
        g_mmi_editor_hanler.input_box_sub_type = MMI_EDITOR_NORMAL_INPUT_BOX;
    }

    g_mmi_editor_hanler.input_box_handler = &MMI_singleline_inputbox;

    //mmi_imc_connect((void *)&g_mmi_editor_hanler, mmi_input_box_msg_call_back_singleline);
    mmi_imc_connect((void *)&g_mmi_editor_hanler, msg_call_back);

    if (input_type == IMM_INPUT_TYPE_DECIMAL_NUMERIC ||
        input_type == IMM_INPUT_TYPE_SIGNED_DECIMAL_NUMERIC)
    {
        wgui_singleline_inputbox_decimal_input_mode_flag = 1;
        if (MMI_singleline_inputbox.text_length > 2)
        {
            S32 i;
            UI_buffer_type t = MMI_singleline_inputbox.text;
            UI_character_type c;

            for (i = 0; i < MMI_singleline_inputbox.text_length; i++)
            {
                UI_STRING_GET_NEXT_CHARACTER(t, c);
                if (c == (UI_character_type) '.')
                {
                    wgui_singleline_inputbox_decimal_flag = 1;
                    break;
                }
            }
        }
    }

    if (input_type & IMM_INPUT_TYPE_EXT_PASSWORD)
        wgui_inputs_sl_set_mask(1);

    /* Relocate singeline cursor position */
    gui_single_line_input_box_locate_cursor(&MMI_singleline_inputbox);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_setup
 * DESCRIPTION
 *  create single line input box
 * PARAMETERS
 *  x                           [IN]        Start x of single line input box
 *  y                           [IN]        Stsrt y of single line input box
 *  width                       [IN]        Width of single line input box
 *  height                      [IN]        Height of single line input box
 *  buffer                      [IN]        Buffer of single line input box
 *  buffer_size                 [IN]        Size of buffer
 *  category_screen_ID          [IN]        Id ofcategory screen
 *  RSK_label                   [IN]        String of RSK
 *  RSK_icon                    [IN]        Icon of RSK
 *  input_type                  [IN]        
 *  history_buffer              [IN]        History buffer
 *  information_bar_flag        [IN]        
 *  input(?)                    [IN]        Type
 *  Change(?)                   [IN]        The parameter for setup function - Gurinder - 23/4/2004
 * RETURNS
 *  void
 *****************************************************************************/
/* Change the parameter for setup function */
void wgui_inputs_sl_setup(
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        U8 *buffer,
        S32 buffer_size,
        U16 category_screen_ID,
        UI_string_type RSK_label,
        PU8 RSK_icon,
        U32 input_type,
        U8 *history_buffer,
        U8 information_bar_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_sl_setup_ext(
        x,
        y,
        width,
        height,
        buffer,
        buffer_size,
        category_screen_ID,
        RSK_label,
        RSK_icon,
        input_type,
        history_buffer,
        information_bar_flag,
        mmi_input_box_msg_call_back_singleline);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_close
 * DESCRIPTION
 *  close single line input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();

    wgui_inputbox_information_flag = 0;
    mmi_imc_disconnect();
    wgui_inputs_sl_reset();

    gdi_layer_unlock_frame_buffer();

    //wgui_singleline_inputbox_RSK_function = NULL;
    wgui_inputs_category_set_rsk_func(NULL);
    wgui_singleline_inputbox_RSK_label_clear = 0;
    wgui_singleline_inputbox_decimal_input_mode_flag = 0;
    wgui_inputbox_not_empty_callback = NULL;
    wgui_inputbox_empty_callback = NULL;
    wgui_inputbox_validation_callback = NULL;
    wgui_inputbox_UCS2_count_function = NULL;
    wgui_inputbox_GSM_ext_count_function = NULL;
    wgui_inputs_sl_register_change_event_handler(NULL);
    /* W05.36 Fix Vietnamese Tone Input Issue */
    wgui_inputs_set_current_input_box_type(EDITOR_NONE_INPUT_BOX);

    gui_inputs_register_redraw_background_filler(NULL);
}


/*****************************************************************************
* FUNCTION
*  mmi_input_box_msg_call_back_singleline
* DESCRIPTION
*  
* PARAMETERS
* void        
* RETURNS
*  void
*****************************************************************************/
U32 mmi_input_box_msg_call_back_singleline(void * input_box_handle, mmi_imc_message_struct_p msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    single_line_input_box * editor_ptr;
    MMI_BOOL ret = MMI_FALSE;
    S32 i, str_len, total_len = 0;
    U32 lresult = 0;
    UI_string_type temp_str;
    UI_character_type ch; 

#if defined(__MMI_TOUCH_SCREEN__)
    gui_single_line_input_box_pen_enum single_line_input_box_event;
#endif
    UI_character_type first_char;
    UI_character_type second_char;
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    static MMI_BOOL is_multitap_completed = MMI_FALSE;
#endif
    U32 old_show_action_flag;
#ifdef __MMI_CLIPBOARD__
    UI_buffer_type cut_cursor_p = NULL;
#endif /* __MMI_CLIPBOARD__ */
    
#ifdef __MMI_EDITOR_SSP_SUPPORT__
    MMI_BOOL is_ssp = MMI_FALSE;
#endif /* __MMI_EDITOR_SSP_SUPPORT__ */    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_ptr = (single_line_input_box *)((mmi_editor_handler_struct *)input_box_handle)->input_box_handler;
    
    MMI_ASSERT(editor_ptr == &MMI_singleline_inputbox);
    
    switch (msg_ptr->message_id)
    {
    case MMI_IMC_MESSAGE_IS_EDITOR_EMPTY:
        lresult = wgui_inputs_sl_is_empty();
        break;
    case MMI_IMC_MESSAGE_INSERT_CHAR:

        #ifdef __MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__
        if ((MMI_singleline_inputbox.ext_flags & GUI_SINGLE_LINE_INPUT_BOX_RECIPIENT_MODE) &&
            (MMI_singleline_inputbox.current_text_p != (MMI_singleline_inputbox.last_position_p - ENCODING_LENGTH)))
        {
            wgui_inputs_sl_move_cursor(WGUI_INPUTS_CURSOR_POS_END);
     
        }
        #endif

        if (wgui_inputs_sl_direct_input((UI_character_type)msg_ptr->param_0))
        {
            if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPUT_BOX)
            {
                //refresh_search_list(editor_ptr->text);
            }            
        #if defined(__MMI_CAT103_SUPPORT__)
            else if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_AUTO_URL_COMPLETION_SINGLE_LINE_INPUT_BOX)
            {
                wgui_cat103_refresh_search_list(editor_ptr->text);
            }
        #endif  /* defined(__MMI_CAT103_SUPPORT__) */
            lresult = MMI_TRUE;
        }
        else
        {
            lresult = MMI_FALSE;
        }

        break;
    case MMI_IMC_MESSAGE_INSERT_SPACE:
        wgui_inputs_sl_direct_input((UI_character_type)(0x20));
        break;        
    case MMI_IMC_MESSAGE_HIDE_MULTITAP_CANDIDATE_BOX:
        if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPUT_BOX)
        {
            lresult = MMI_TRUE;
        }
#if defined(__MMI_CAT103_SUPPORT__)
        if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_AUTO_URL_COMPLETION_SINGLE_LINE_INPUT_BOX)
        {
            lresult = MMI_TRUE;
        }
#endif /* defined(__MMI_CAT103_SUPPORT__) */
#if defined(__MMI_CAT203_SUPPORT__) && defined(__MMI_FTE_SUPPORT__)
        if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_DIALER_SEARCH_MULTI_LINE_INPUT_BOX)
        {
            lresult = MMI_TRUE;
        }
#endif /* defined(__MMI_CAT203_SUPPORT__) */   
        break;
        
    case MMI_IMC_MESSAGE_INSERT_STRING:
    case MMI_IMC_MESSAGE_INSERT_STRING_NO_DRAW:  
        #ifdef __MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__
        if ((MMI_singleline_inputbox.ext_flags & GUI_SINGLE_LINE_INPUT_BOX_RECIPIENT_MODE) &&
            (MMI_singleline_inputbox.current_text_p != (MMI_singleline_inputbox.last_position_p - ENCODING_LENGTH)))
        {
            wgui_inputs_sl_move_cursor(WGUI_INPUTS_CURSOR_POS_END);
     
        }
        #endif /*__MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__*/

        g_wgui_inputs_is_break_insert = MMI_TRUE;

        temp_str = (UI_string_type)msg_ptr->param_0;
        
        str_len = (S32)mmi_ucs2strlen((const CHAR *)temp_str);

        old_show_action_flag = editor_ptr->show_action_flag;
        
        editor_ptr->show_action_flag = 0;

        for (i = 0; i < str_len; i++)
        {
            if (wgui_inputs_sl_direct_input_no_draw((UI_character_type)temp_str[i]))
            {
                g_wgui_inputs_is_break_insert = MMI_TRUE;
                total_len ++;
            }
            else if (g_wgui_inputs_is_break_insert)
            {
                break;
            }
        }

        editor_ptr->show_action_flag = old_show_action_flag;

        if (total_len)
		{
            if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPUT_BOX)
            {
#ifdef __MMI_PHB_QUICK_SEARCH__     //**/              
                refresh_search_list(editor_ptr->text);
#endif /*__MMI_PHB_QUICK_SEARCH__*/
            }            
        #if defined(__MMI_CAT103_SUPPORT__)
            else if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_AUTO_URL_COMPLETION_SINGLE_LINE_INPUT_BOX)
            {
                wgui_cat103_refresh_search_list(editor_ptr->text);
            }
        #endif  /* defined(__MMI_CAT103_SUPPORT__) */
		}

        gui_single_line_input_box_locate_cursor(&MMI_singleline_inputbox);
        wgui_inputs_sl_redraw();
        singleline_inputbox_input_callback();
    
        lresult = total_len;
        
        break;

    case MMI_IMC_MESSAGE_REPLACE_HIGHLIGHT_STRING:

        old_show_action_flag = editor_ptr->show_action_flag;
        
        editor_ptr->show_action_flag = 0;

        #ifdef __MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__
        if ((MMI_singleline_inputbox.ext_flags & GUI_SINGLE_LINE_INPUT_BOX_RECIPIENT_MODE) &&
            (MMI_singleline_inputbox.current_text_p != (MMI_singleline_inputbox.last_position_p - ENCODING_LENGTH)))
        {
            wgui_inputs_sl_move_cursor(WGUI_INPUTS_CURSOR_POS_END);
            gui_single_line_input_box_start_input(&MMI_singleline_inputbox);
        }
        #endif /*__MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__*/
        
		for (i = 0; i < msg_ptr->param_0; i ++)
        {
            wgui_inputs_sl_delete_character_no_draw();
        }
		
		temp_str = (UI_string_type)msg_ptr->param_1;
        
        str_len = (S32)mmi_ucs2strlen((const CHAR *)temp_str);
		
        for (i = 0; i < str_len; i++)
        {
            if (wgui_inputs_sl_direct_input_no_draw((UI_character_type)temp_str[i]))
            {
                total_len ++;
            }
            else
            {
                break;
            }
        }

        editor_ptr->show_action_flag = old_show_action_flag;

        if (total_len)
		{
            if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPUT_BOX)
            {
#ifdef __MMI_PHB_QUICK_SEARCH__     //**/                
                refresh_search_list(editor_ptr->text);
#endif /*__MMI_PHB_QUICK_SEARCH__*/
            }            
        #if defined(__MMI_CAT103_SUPPORT__)
            else if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_AUTO_URL_COMPLETION_SINGLE_LINE_INPUT_BOX)
            {
                wgui_cat103_refresh_search_list(editor_ptr->text);
            }
        #endif  /* defined(__MMI_CAT103_SUPPORT__) */		
		}

		if (total_len)
		{
			editor_ptr->flags |= UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
            gui_single_line_input_box_highlight_cursor_number(editor_ptr, (S32)total_len);
		}
        else
        {
            /* if no character gets inserted , no character will be highlighted*/
            editor_ptr->flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;

        }

		wgui_inputs_sl_redraw();
        singleline_inputbox_input_callback();
		
        lresult = total_len;
		
		break;
        
    case MMI_IMC_MESSAGE_CHANGE_TO_INITIAL:
        break;
        
    case MMI_IMC_MESSAGE_DELETE_STRING:
        old_show_action_flag = editor_ptr->show_action_flag;
        
        editor_ptr->show_action_flag = 0;

        for (i = 0; i < msg_ptr->param_0; i ++)
        {
            wgui_inputs_sl_delete_character_no_draw();
        }

        editor_ptr->show_action_flag = old_show_action_flag;

        if (!msg_ptr->param_1)
        {
            wgui_inputs_sl_redraw();
        }

        gui_single_line_input_box_locate_cursor(editor_ptr);
        singleline_inputbox_input_callback();
        break;
    case MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR:
        ch = (UI_character_type)msg_ptr->param_0;
        #ifdef __MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__ 
        if ((MMI_singleline_inputbox.ext_flags & GUI_SINGLE_LINE_INPUT_BOX_RECIPIENT_MODE) &&
            (MMI_singleline_inputbox.current_text_p != (MMI_singleline_inputbox.last_position_p - ENCODING_LENGTH)))
        {
            wgui_inputs_sl_move_cursor(WGUI_INPUTS_CURSOR_POS_END);
            gui_single_line_input_box_start_input(&MMI_singleline_inputbox);
        }
        #endif /*__MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__*/

        lresult = wgui_inputs_sl_multitap_input(ch);
    #ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
        if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPUT_BOX)
        {
            is_multitap_completed = MMI_FALSE;
        }    
    #endif
        break;

    case MMI_IMC_MESSAGE_INSERT_MULTITAP_STRING:
        #ifdef __MMI_EDITOR_SINGLE_SUPPORT_MULTIGRAPH__
        temp_str = (UI_string_type)msg_ptr->param_0;
        /* Insert the string in editor */
        total_len = wgui_inputs_sl_multitap_input_string((PU8)temp_str);
        if (total_len)
		{
            if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPUT_BOX)
            {
#ifdef __MMI_PHB_QUICK_SEARCH__     //**/                
                refresh_search_list(editor_ptr->text);
#endif /*__MMI_PHB_QUICK_SEARCH__*/
            }            
        #if defined(__MMI_CAT103_SUPPORT__)
            else if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_AUTO_URL_COMPLETION_SINGLE_LINE_INPUT_BOX)
            {
                wgui_cat103_refresh_search_list(editor_ptr->text);
            }
        #endif  /* defined(__MMI_CAT103_SUPPORT__) */
		}
        lresult = total_len;
        #endif /*__MMI_EDITOR_SINGLE_SUPPORT_MULTIGRAPH__*/
        break;


    case MMI_IMC_MESSAGE_RESET_MULTITAP_STATE:
        {
        #ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
            S32 is_blocked = gui_list_effect_is_blocked();
        #endif

        #ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
            if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPUT_BOX
                && !is_blocked)
            {
                gui_block_list_effect();
            }    
        #endif    
            wgui_inputs_sl_multitap_input_complete();
            gui_single_line_input_box_stop_input(editor_ptr);
        #ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
            if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPUT_BOX
                && !is_blocked)
            {
                gui_unblock_list_effect();
                is_multitap_completed = MMI_TRUE;
            }    
        #endif
        }
        break;

    case MMI_IMC_MESSAGE_GET_PREVIOUS_CHAR:
        lresult = gui_single_line_input_box_get_previous_character(editor_ptr, (UI_character_type *)msg_ptr->param_0);
        break;

    case MMI_IMC_MESSAGE_GET_TEXT_LENGTH:
        lresult = (U32)(editor_ptr->text_length / ENCODING_LENGTH);
        break;
        
    case MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC:
        gui_single_line_input_box_stop_input(editor_ptr);
        break;
    case MMI_IMC_MESSAGE_START_SMART_ALPHABETIC:
        gui_single_line_input_box_start_input(editor_ptr);
        break;
    case MMI_IMC_MESSAGE_GET_HIGHLIGHT_WORD:
        if (editor_ptr->flags & UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT)
        {
            *((UI_buffer_type *)(msg_ptr->param_0)) = editor_ptr->highlight_start_position;
            *((UI_buffer_type *)(msg_ptr->param_1)) = editor_ptr->highlight_end_position;
            lresult = (U32)((editor_ptr->highlight_end_position - editor_ptr->highlight_start_position) / ENCODING_LENGTH);
        }
        else
        {
            *((UI_buffer_type *)(msg_ptr->param_0)) = 0;
            *((UI_buffer_type *)(msg_ptr->param_1)) = 0;
            lresult = 0;
        }
        break;
    case MMI_IMC_MESSAGE_MOVE_CURSOR_TO_HIGHLIGHT_START:
        if (editor_ptr->flags & UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT)
        {
            UI_buffer_type words_start_p = editor_ptr->highlight_start_position;
            UI_character_type c;
            
            editor_ptr->current_text_p = words_start_p;
            
            gui_single_line_input_box_locate_cursor(editor_ptr);
            
			while (words_start_p > editor_ptr->text) /* Go to the end of the previous word */
			{
				c = (UI_character_type)((*((words_start_p - 2)+0))|((*((words_start_p - 2)+1))<<8));

				if (c == 0x20) 
				{
                    gui_single_line_input_box_previous(editor_ptr);

					words_start_p = editor_ptr->current_text_p;
				}
				else
				{
					break;
				}
			}

            lresult = 1;
        }
        break;
        
	case MMI_IMC_MESSAGE_IS_OVERWRITE_MODE:
		if (editor_ptr->flags & UI_SINGLE_LINE_INPUT_BOX_MASK_CHARACTERS)
		{
			lresult = MMI_TRUE;
		}
		else
		{
            lresult = MMI_FALSE;
		}
		break;	
        
    case MMI_IMC_MESSAGE_DELETE_CHAR:
        {
            U16 keyCode, keyType;
            mmi_frm_get_key_info(&keyCode, &keyType);
            #ifdef __MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__
            if (keyType == KEY_REPEAT && !(MMI_singleline_inputbox.ext_flags & GUI_SINGLE_LINE_INPUT_BOX_RECIPIENT_MODE))
            #else /*__MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__*/
            if (keyType == KEY_REPEAT)
            #endif /*__MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__*/
            {
                wgui_inputs_fast_del_nav_handler(WGUI_INPUTS_OPER_FAST_DEL, WGUI_INPUTS_EDITOR_SL, WGUI_INPUTS_KPD_REPEAT_PERIOD);
            }
            else
            {
                #ifdef __MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__ 
                if (MMI_singleline_inputbox.ext_flags & GUI_SINGLE_LINE_INPUT_BOX_RECIPIENT_MODE)
                {
                    gui_single_line_input_box_delete_all(&MMI_singleline_inputbox);
                }
                else
                #endif /*__MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__*/
                {
                    for (i = 0; i < msg_ptr->param_0; i ++)
                    {
                        wgui_inputs_sl_delete_character_no_draw();
                    }
                }

                wgui_inputs_sl_redraw();
                singleline_inputbox_input_callback();
            }
            break;
        }
    case MMI_IMC_MESSAGE_CLEAR_ALL:
    #ifdef __MMI_TOUCH_SCREEN__
        wgui_inputs_fast_del_pen_handler(WGUI_INPUTS_OPER_FAST_DEL, WGUI_INPUTS_EDITOR_SL, MMI_PEN_EVENT_LONG_TAP);
    #else
        wgui_inputs_fast_del_nav_reset_repeat_count();
    #endif

        break;

    case MMI_IMC_MESSAGE_BACKSPACE_KEY_EVENT:
    #ifdef __MMI_TOUCH_SCREEN__
        wgui_inputs_fast_del_pen_handler(WGUI_INPUTS_OPER_FAST_DEL, WGUI_INPUTS_EDITOR_SL, (mmi_pen_event_type_enum)msg_ptr->param_0);
    #endif
        break;
        
    case MMI_IMC_MESSAGE_GET_CURSOR_RECT:
        if (editor_ptr->flags & UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR)
        {
            ((mmi_imc_rect_p)msg_ptr->param_0)->x = editor_ptr->hilite_s_x;
            ((mmi_imc_rect_p)msg_ptr->param_0)->y = editor_ptr->hilite_s_y;
            ((mmi_imc_rect_p)msg_ptr->param_0)->width = editor_ptr->hilite_e_x - editor_ptr->hilite_s_x + 1;
            ((mmi_imc_rect_p)msg_ptr->param_0)->height = editor_ptr->hilite_e_y - editor_ptr->hilite_s_y + 1;
        }
        else
        {
            ((mmi_imc_rect_p)msg_ptr->param_0)->x = UI_cursor_x1;
            ((mmi_imc_rect_p)msg_ptr->param_0)->y = UI_cursor_y1;
            ((mmi_imc_rect_p)msg_ptr->param_0)->width = UI_cursor_x2 - UI_cursor_x1 + 1;
            ((mmi_imc_rect_p)msg_ptr->param_0)->height = UI_cursor_y2 - UI_cursor_y1 + 1;
        }
        lresult = MMI_TRUE;
        break;
        
    case MMI_IMC_MESSAGE_IS_EDITOR_IN_REPLACE_MODE:
        
        if (
            #ifdef __MMI_EDITOR_SL_AUTO_CLEAR_HILITE_MODE__
            (editor_ptr->flags & UI_SINGLE_LINE_INPUT_BOX_AUTO_CLEAR_HIGHLIGHT_MODE) || 
            #endif /*__MMI_EDITOR_SL_AUTO_CLEAR_HILITE_MODE__*/
            
            (editor_ptr->flags & UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP))
        {
            lresult = MMI_TRUE;
        }
        else
        {
            lresult = MMI_FALSE;
        }
        break;

    case MMI_IMC_MESSAGE_MOVE_CURSOR:
        if (mmi_frm_is_key_event())
        {
            U16 keycode = 0, keytype = 0;
            /* get key code and type */
            GetkeyInfo(&keycode, &keytype);    
            /* for phonebook search, if g_is_disable_left_right_key_register set, donot go previous char or next char by arrow key */
            if ((keycode == KEY_LEFT_ARROW || keycode == KEY_RIGHT_ARROW) && keytype == KEY_EVENT_DOWN && g_is_disable_left_right_key_register)
                return lresult;
        }
        switch (msg_ptr->param_0)
        {    
            case MMI_IMC_EDITOR_CURSOR_LEFT:
                for (i = 0; i <(S32)msg_ptr->param_1; i ++)
                {
                    wgui_inputs_sl_previous_character();
                }
                break;
                
            case MMI_IMC_EDITOR_CURSOR_RIGHT:
                for (i = 0; i <(S32)msg_ptr->param_1; i ++)
                {
                    wgui_inputs_sl_next_character();
                }
                break;
        }
        
        break;
        
    case MMI_IMC_MESSAGE_INSERT_PAIRED_SYMBOLS:
        temp_str = (UI_string_type)msg_ptr->param_0;
        
        str_len = (S32)mmi_ucs2strlen((const CHAR *)temp_str);
        
        for (i = 0; i < str_len; i++)
        {
            if (wgui_inputs_sl_direct_input_no_draw((UI_character_type)temp_str[i]))
            {
                total_len ++;
            }
            else
            {
                break;
            }
        }
        if (total_len)
        {
            if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPUT_BOX)
            {
#ifdef __MMI_PHB_QUICK_SEARCH__     //**/                
                refresh_search_list(editor_ptr->text);
#endif /*__MMI_PHB_QUICK_SEARCH__*/
            }            
#if defined(__MMI_CAT103_SUPPORT__)
            else if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_AUTO_URL_COMPLETION_SINGLE_LINE_INPUT_BOX)
            {
                wgui_cat103_refresh_search_list(editor_ptr->text);
            }
#endif  /* defined(__MMI_CAT103_SUPPORT__) */
        }
        wgui_inputs_sl_redraw();
        singleline_inputbox_input_callback();

        if (total_len == str_len)
        {
            wgui_inputs_sl_previous_character();
            lresult = MMI_TRUE;
        }
        else
        {
            lresult = MMI_FALSE;
        }    

        break;

    case MMI_IMC_MESSAGE_IS_THERE_CURSOR:
        if (editor_ptr->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW)
        {
            lresult = MMI_FALSE;
        }
        else
        {
            lresult = MMI_TRUE;
        }
        break;	     
    case MMI_IMC_MESSAGE_HILIGHT_BFCURSOR:
        editor_ptr->flags |= UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        gui_single_line_input_box_highlight_cursor_number(editor_ptr, (S32)msg_ptr->param_0);
        wgui_inputs_sl_redraw();
        break;
        
    case MMI_IMC_MESSAGE_CLEAR_HILIGHT:
        editor_ptr->flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        break;
        
    case MMI_IMC_MESSAGE_IS_AUTO_CLEAR_HIGHLIGHT_WORD_MODE:
        #ifdef __MMI_EDITOR_SL_AUTO_CLEAR_HILITE_MODE__
        if (editor_ptr->flags & UI_SINGLE_LINE_INPUT_BOX_AUTO_CLEAR_HIGHLIGHT_MODE)
        {
            lresult = MMI_TRUE;
        }
        else
        #endif /*__MMI_EDITOR_SL_AUTO_CLEAR_HILITE_MODE__*/
        {
            lresult = MMI_FALSE;
        }
        break;
        
    case MMI_IMC_MESSAGE_GET_INPUT_BOX_RECT:
        ((mmi_imc_rect_p)msg_ptr->param_0)->x = editor_ptr->x;
        ((mmi_imc_rect_p)msg_ptr->param_0)->y = editor_ptr->y;
        ((mmi_imc_rect_p)msg_ptr->param_0)->width = editor_ptr->width;
        ((mmi_imc_rect_p)msg_ptr->param_0)->height = editor_ptr->height;
        break;
        
    case MMI_IMC_MESSAGE_RESIZE:
        switch(((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type)
        {
        case MMI_EDITOR_NORMAL_INPUT_BOX:
            if ((S32)msg_ptr->param_1 != editor_ptr->height)
            {
                gui_move_single_line_input_box(editor_ptr, editor_ptr->x, editor_ptr->y + (S32)msg_ptr->param_1 - editor_ptr->height);
            }
            
            break;
        case MMI_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPUT_BOX:
            MMI_ASSERT(g_wgui_cat200_resize_and_move_func != NULL);
            g_wgui_cat200_resize_and_move_func(editor_ptr->y + (S32)msg_ptr->param_1 - editor_ptr->height);
            break;
    #if defined(__MMI_CAT116_SUPPORT__)
        case MMI_EDITOR_CALL_PLAN_SINGLE_LINE_INPUT_BOX:
            MMI_ASSERT(g_wgui_cat116_resize_and_draw_func != NULL);
            g_wgui_cat116_resize_and_draw_func(MMI_content_y + MMI_content_height - (editor_ptr->y + (S32)msg_ptr->param_1) );            
            break;
    #endif
    #if defined(__MMI_CAT103_SUPPORT__)
        case MMI_EDITOR_AUTO_URL_COMPLETION_SINGLE_LINE_INPUT_BOX:
            MMI_ASSERT(g_wgui_cat103_resize_and_draw_func != NULL);
            g_wgui_cat103_resize_and_draw_func(MMI_content_y + MMI_content_height - (editor_ptr->y + (S32)msg_ptr->param_1) );
            break;
    #endif /* __MMI_CAT103_SUPPORT__ */    
    #ifdef __MMI_SEARCH_WEB__
        case MMI_EDITOR_BAIDU_SEARCH_SINGLE_LINE_INPUT_BOX:
            MMI_ASSERT(g_wgui_cat2001_resize_and_draw_func != NULL);
            g_wgui_cat2001_resize_and_draw_func(MMI_content_y + MMI_content_height - (editor_ptr->y + (S32)msg_ptr->param_1) );            
            break;
    #endif /* __MMI_SEARCH_WEB__  */
    #if defined(__MMI_CAT203_SUPPORT__) && defined(__MMI_FTE_SUPPORT__)
        case MMI_EDITOR_DIALER_SEARCH_MULTI_LINE_INPUT_BOX:
            MMI_ASSERT(g_wgui_cat203_resize_and_draw_func != NULL);
            g_wgui_cat203_resize_and_draw_func(MMI_content_y + MMI_content_height - (editor_ptr->y + (S32)msg_ptr->param_1) );            
            break;
    #endif /* __MMI_CAT203_SUPPORT__ */
        default:
            break;
        }
        break;
        
    case MMI_IMC_MESSAGE_MOVE:
        switch(((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type)
        {
        case MMI_EDITOR_NORMAL_INPUT_BOX:
            if ((S32)msg_ptr->param_1 != editor_ptr->height)
            {
                gui_move_single_line_input_box(editor_ptr, (S32)msg_ptr->param_0, (S32)msg_ptr->param_1);
            }
            
            break;
        case MMI_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPUT_BOX:
            MMI_ASSERT(g_wgui_cat200_resize_and_move_func != NULL);
            g_wgui_cat200_resize_and_move_func((S32)msg_ptr->param_1);
            break;
    #if defined(__MMI_CAT116_SUPPORT__)
        case MMI_EDITOR_CALL_PLAN_SINGLE_LINE_INPUT_BOX:
            MMI_ASSERT(g_wgui_cat116_resize_and_draw_func != NULL);
            g_wgui_cat116_resize_and_draw_func(MMI_content_y + MMI_content_height- (S32)msg_ptr->param_1 - editor_ptr->height );
            break;
    #endif   
    #if defined(__MMI_CAT103_SUPPORT__)
        case MMI_EDITOR_AUTO_URL_COMPLETION_SINGLE_LINE_INPUT_BOX:
            MMI_ASSERT(g_wgui_cat103_resize_and_draw_func != NULL);
            g_wgui_cat103_resize_and_draw_func(MMI_content_y + MMI_content_height- (S32)msg_ptr->param_1 - editor_ptr->height);
            break;
    #endif /* __MMI_CAT103_SUPPORT__ */
    #ifdef __MMI_SEARCH_WEB__
    case MMI_EDITOR_BAIDU_SEARCH_SINGLE_LINE_INPUT_BOX:
        MMI_ASSERT(g_wgui_cat2001_resize_and_draw_func != NULL);
        g_wgui_cat2001_resize_and_draw_func(MMI_content_y + MMI_content_height- (S32)msg_ptr->param_1 - editor_ptr->height );
        break;
    #endif /* __MMI_SEARCH_WEB__  */
    #if defined(__MMI_CAT203_SUPPORT__) && defined(__MMI_FTE_SUPPORT__)
        case MMI_EDITOR_DIALER_SEARCH_MULTI_LINE_INPUT_BOX:
            MMI_ASSERT(g_wgui_cat203_resize_and_draw_func != NULL);
            g_wgui_cat203_resize_and_draw_func(MMI_content_y + MMI_content_height- (S32)msg_ptr->param_1 - editor_ptr->height );
            break;
    #endif /* __MMI_CAT203_SUPPORT__ */        

        default:
            break;
        }
        break;
        
    case MMI_IMC_MESSAGE_REDRAW:
        

		if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPUT_BOX)
		{
        #ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
            if (is_multitap_completed) 
            {
                gui_block_list_effect();
            }
        #endif
            
            if (msg_ptr->param_0 == 1)
            {
                dm_imui_window_hide();
            }
            else
            {
#ifdef __MMI_PHB_QUICK_SEARCH__     //**/                
                RedrawCategoryControlledArea200Screen(NULL);
#endif /*__MMI_PHB_QUICK_SEARCH__*/
            }

        #ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
            if (is_multitap_completed) 
            {
                gui_unblock_list_effect();
                is_multitap_completed = MMI_FALSE;
            }
        #endif
        }
        else
        {
            if (msg_ptr->param_0 == 1)
            {
                dm_imui_window_hide();
            }
            else
            {
                wgui_inputs_sl_redraw();
            }
        }
        
        break;

    case MMI_IMC_MESSAGE_FLOATING_UI_APPEAR_INDICATION:
        if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPUT_BOX)
        {
            gui_fixed_icontext_list_menuitem_stop_scroll();
            gui_fixed_icontext_menuitem_stop_scroll();
            gui_pop_up_description_stop_scroll();
        }
        else
        {
            dm_imui_window_display();
        }    
        break;

    case MMI_IMC_MESSAGE_UPDATE_SOFTKEY:
        break;
    case MMI_IMC_MESSAGE_KEY_EVENT:
        break;
    case MMI_IMC_MESSAGE_MODE_CHANGED:
        if ((((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPUT_BOX) &&
            (mmi_imm_get_curr_input_type() == IMM_INPUT_TYPE_QUICK_SEARCH))
        {
			if (gui_single_line_input_box_get_text_length(editor_ptr) > 0)
			{
				wgui_inputs_sl_delete_all_characters();
			}

        #if defined(__MMI_PHB_QUICK_SEARCH__) && !defined(__COSMOS_MMI_PACKAGE__)
			mmi_phb_quick_search_change_input_mode();
        #endif 
            //refresh_search_list(NULL);
        }
        break;
#if defined(__MMI_TOUCH_SCREEN__)
    case MMI_IMC_MESSAGE_GET_HANDWRITING_RECT:
        switch (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type)
        {
        #if defined(__MMI_CAT116_SUPPORT__)
            case MMI_EDITOR_CALL_PLAN_SINGLE_LINE_INPUT_BOX:					
                wgui_cat116_get_hw_area(
                    &(((mmi_imc_rect_p)msg_ptr->param_0)->x),
                    &(((mmi_imc_rect_p)msg_ptr->param_0)->y),
                    &(((mmi_imc_rect_p)msg_ptr->param_0)->width),
                    &(((mmi_imc_rect_p)msg_ptr->param_0)->height));
                break;
        #endif /* defined(__MMI_CAT116_SUPPORT__) */

            default:
                ((mmi_imc_rect_p)msg_ptr->param_0)->x = MMI_content_x;
                ((mmi_imc_rect_p)msg_ptr->param_0)->y = MMI_content_y;
                ((mmi_imc_rect_p)msg_ptr->param_0)->width = MMI_content_width;
                ((mmi_imc_rect_p)msg_ptr->param_0)->height = MMI_content_height - mmi_imc_get_current_imui_height_skip_fixed_editor();
                break;
        }
        break;
        
    case MMI_IMC_MESSAGE_PEN_EVENT:
        
#ifdef __MMI_EDITOR_SSP_SUPPORT__
        is_ssp = gui_input_box_ssp_is_scrolling();
#endif /* __MMI_EDITOR_SSP_SUPPORT__ */

        ret = (MMI_BOOL)gui_single_line_input_box_translate_pen_event(
                        editor_ptr,
                        ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event,
                        ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.x,
                        ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.y,
                        &single_line_input_box_event);
        if (ret)
        {
#ifdef __MMI_EDITOR_SSP_SUPPORT__
            if (!is_ssp)
#endif /* __MMI_EDITOR_SSP_SUPPORT__ */
            {
                #ifdef __MMI_EDITOR_SL_AUTO_CLEAR_HILITE_MODE__
                if (editor_ptr->flags & UI_SINGLE_LINE_INPUT_BOX_AUTO_CLEAR_HIGHLIGHT_MODE)
                {
                    editor_ptr->flags &= ~UI_SINGLE_LINE_INPUT_BOX_AUTO_CLEAR_HIGHLIGHT_MODE;
                    editor_ptr->flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
                    editor_ptr->highlight_start_position = NULL;
                    editor_ptr->highlight_end_position = NULL;
                }
                #endif /*__MMI_EDITOR_SL_AUTO_CLEAR_HILITE_MODE__*/
                
                ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->editor_pen_event = (mmi_imc_editor_pen_event_enum)single_line_input_box_event;
                
                if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_UP)
                {
                    /* Locate cursor at pen down position */
                    gui_show_single_line_input_box_ext(editor_ptr, 
                        ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.x, 
                        ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.y);
                    
                    gui_single_line_input_box_locate_cursor(editor_ptr);                    
  
                #if defined(__MMI_CAT103_SUPPORT__)
                    if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_AUTO_URL_COMPLETION_SINGLE_LINE_INPUT_BOX)
                    {
                        if (wgui_cat103_is_editor_active() == MMI_FALSE)
                        {
                            g_wgui_cat103_highlight_handler(CAT103_INVALID_HIGHLIGHT);
                            wgui_text_menuitem_reset_scrolling(); /* reset menuitem not to scroll */
                            redraw_dynamic_list();
                        }
                    }
                #endif /* defined(__MMI_CAT103_SUPPORT__) */

                #ifdef __MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__ 
                    if (editor_ptr->ext_flags & GUI_SINGLE_LINE_INPUT_BOX_RECIPIENT_MODE &&
                        !mmi_imc_is_clipboard_state())
                    {
                        if (MMI_singleline_inputbox.current_text_p != (MMI_singleline_inputbox.last_position_p - ENCODING_LENGTH))
                        {
                            /* Highlight whole recipient and locate cursor at last position */
                            MMI_singleline_inputbox.flags |= UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
                            MMI_singleline_inputbox.highlight_start_position = MMI_singleline_inputbox.text;
                            MMI_singleline_inputbox.highlight_end_position = MMI_singleline_inputbox.last_position_p - ENCODING_LENGTH;
                            MMI_singleline_inputbox.current_text_p = MMI_singleline_inputbox.last_position_p - ENCODING_LENGTH;
                        }
                        else
                        {
                            /* Cancel highlight when not pen down on recipient */
                            MMI_singleline_inputbox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
                            MMI_singleline_inputbox.highlight_start_position = NULL;
                            MMI_singleline_inputbox.highlight_end_position = NULL;
                        }
                    }
                #endif /*__MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__*/

                #if defined(__MMI_CAT203_SUPPORT__) && defined(__MMI_FTE_SUPPORT__)
                    if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_DIALER_SEARCH_MULTI_LINE_INPUT_BOX)
                    {
                        if (wgui_cat203_is_editor_active() == MMI_FALSE)
                        {
                            g_wgui_cat203_highlight_handler(WGUI_LIST_INVALID_HIGHLIGHT);
                            wgui_text_menuitem_reset_scrolling(); /* reset menuitem not to scroll */
                            redraw_dynamic_list();
                        }
                    }
                #endif /* defined(__MMI_CAT203_SUPPORT__) */   
                    
                    wgui_inputs_sl_redraw();
                }
                else if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_LONG_TAP ||
                        ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_DOWN)
                {
                #if defined(__MMI_CAT103_SUPPORT__)
                    if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_AUTO_URL_COMPLETION_SINGLE_LINE_INPUT_BOX)
                    {
                        if (wgui_cat103_is_editor_active() == MMI_FALSE)
                        {
                            wgui_cat103_set_editor_focus_state(MMI_TRUE);
                            wgui_cat103_set_menu_focus_state(MMI_FALSE);
                        }
                    }
                #endif

                    #ifdef __MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__
                    /* Highlight whole recipient and locate cursor at last position */
                    if ((((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_DOWN) &&
                         (editor_ptr->ext_flags & GUI_SINGLE_LINE_INPUT_BOX_RECIPIENT_MODE))
                    {
                        if (MMI_singleline_inputbox.current_text_p != (MMI_singleline_inputbox.last_position_p - ENCODING_LENGTH))
                        {
                            /* Highlight whole recipient and locate cursor at last position */
                            MMI_singleline_inputbox.flags |= UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
                            MMI_singleline_inputbox.highlight_start_position = MMI_singleline_inputbox.text;
                            MMI_singleline_inputbox.highlight_end_position = MMI_singleline_inputbox.last_position_p - ENCODING_LENGTH;
                            MMI_singleline_inputbox.current_text_p = MMI_singleline_inputbox.last_position_p - ENCODING_LENGTH;
                        }
                        else
                        {
                            /* Cancel highlight when not pen down on recipient */
                            MMI_singleline_inputbox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
                            MMI_singleline_inputbox.highlight_start_position = NULL;
                            MMI_singleline_inputbox.highlight_end_position = NULL;
                        }
                    }
                    #endif /*__MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__*/

                #if defined(__MMI_CAT203_SUPPORT__) && defined(__MMI_FTE_SUPPORT__)
                    if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_DIALER_SEARCH_MULTI_LINE_INPUT_BOX)
                    {
                        if (wgui_cat203_is_editor_active() == MMI_FALSE)
                        {
                            wgui_cat203_set_editor_focus_state(MMI_TRUE);
                            wgui_cat203_set_menu_focus_state(MMI_FALSE);
                            dynamic_list_goto_item(-1);
                            //redraw_dynamic_list();
                        }
                    }
                #endif
                    *((U32 *)msg_ptr->param_1) = 1;
                } 
            }
        }
        lresult = ret;
        
        break;

    case MMI_IMC_MESSAGE_GET_HANDWRITING_STYLE:
    #if defined(__MMI_HANDWRITING_MULTI_BLOCK__)
        if ((((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type) == MMI_EDITOR_BAIDU_SEARCH_SINGLE_LINE_INPUT_BOX)
        {
            lresult = MMI_IMC_PEN_HANDWRITING_STYLE_MULTI_BLOCK;
        }
        else
    #endif
        {
            lresult = MMI_IMC_PEN_HANDWRITING_STYLE_FULL_SCREEN;
        }
        break;

    case MMI_IMC_MESSAGE_INSERT_SPELLING_DIRECTLY:
        if ((((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPUT_BOX) &&
            (mmi_imm_get_curr_input_type() == IMM_INPUT_TYPE_QUICK_SEARCH))
		{
		    lresult = MMI_TRUE;
        }
        break;
        
#endif /* defined(__MMI_TOUCH_SCREEN__) */
    case MMI_IMC_MESSAGE_INSERT_NEW_LINE:
        break;
        
    case MMI_IMC_MESSAGE_SET_MASK:
        wgui_inputs_sl_set_mask(1);
        break;    
    case MMI_IMC_MESSAGE_CHECK_MULTITAP_STATE:
        if (editor_ptr->flags & UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP)
            lresult = MMI_TRUE;
        break;
        
    case MMI_IMC_MESSAGE_INSERT_DECIMAL_SYMBOL:    
        first_char = editor_ptr->text[0] | (editor_ptr->text[1] << 8);
        second_char = editor_ptr->text[2] | (editor_ptr->text[3] << 8);
        
        if (wgui_singleline_inputbox_decimal_flag)
        {
            UI_editor_play_tone_invalid_data();
            break;
        }
        if (gui_single_line_input_box_test_first_position(editor_ptr) ||
            (first_char == (UI_character_type)'-' && second_char == 0))
                {
            wgui_inputs_sl_direct_input((UI_character_type) '0');
        }
        if (wgui_inputs_sl_direct_input((UI_character_type) '.') == MMI_TRUE)
        {
            wgui_singleline_inputbox_decimal_flag = 1;
        }
    
                    break;
    case MMI_IMC_MESSAGE_CHECK_FLOAT:
            lresult = wgui_singleline_inputbox_decimal_flag;
        break;
    case MMI_IMC_MESSAGE_SET_KEY:
        wgui_inputs_sl_set_RSK();
        wgui_inputs_sl_register_keys();
        if((((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type) == MMI_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPUT_BOX)
        {
            /* set up and down arrow key handler to control menu list */
            SetKeyHandler(dynamic_list_goto_previous_item, KEY_UP_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(dynamic_list_goto_next_item, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(dynamic_list_goto_previous_item, KEY_UP_ARROW, KEY_EVENT_REPEAT);
            SetKeyHandler(dynamic_list_goto_next_item, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
        }

        if (g_wgui_cat200_set_special_key_func != NULL)
        {
            g_wgui_cat200_set_special_key_func();
        }
#ifdef __MMI_SEARCH_WEB__
        if((((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type) == MMI_EDITOR_BAIDU_SEARCH_SINGLE_LINE_INPUT_BOX)
        {
            wgui_cat2001_reset_special_key();
        }
#endif /* __MMI_SEARCH_WEB__ */

#if defined(__MMI_CAT116_SUPPORT__)
        else if ((((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type) == MMI_EDITOR_CALL_PLAN_SINGLE_LINE_INPUT_BOX)
        {
            wgui_inputs_ml_register_viewer_keys();
        }
#endif /* defined(__MMI_CAT116_SUPPORT__) */
#if defined(__MMI_CAT103_SUPPORT__)
        else if ((((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type) == MMI_EDITOR_AUTO_URL_COMPLETION_SINGLE_LINE_INPUT_BOX)
        {
            register_fixed_list_highlight_handler(dynamic_list_highlight_handler);
            register_dynamic_list_keys();
        }
#endif /* defined(__MMI_CAT103_SUPPORT__) */
#if defined(__MMI_CAT203_SUPPORT__) && defined(__MMI_FTE_SUPPORT__)
        else if ((((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type) == MMI_EDITOR_DIALER_SEARCH_MULTI_LINE_INPUT_BOX)
        {
            if (wgui_cat203_is_editor_active() == MMI_FALSE)
            {
                wgui_cat203_set_editor_focus_state(MMI_FALSE);
                wgui_cat203_set_menu_focus_state(MMI_TRUE);
            }
            register_fixed_list_highlight_handler(dynamic_list_highlight_handler);
            register_dynamic_list_keys();
        }
#endif /* defined(__MMI_CAT203_SUPPORT__) */
        else if ((((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type) == MMI_EDITOR_UCE_MULTLINE_INPUT_BOX)
        {
            SetKeyHandler(wgui_inputs_ml_previous_line, KEY_UP_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(wgui_inputs_ml_next_line, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(wgui_inputs_ml_previous_line, KEY_UP_ARROW, KEY_REPEAT);
            SetKeyHandler(wgui_inputs_ml_next_line, KEY_DOWN_ARROW, KEY_REPEAT);
        }

        break;
    case MMI_IMC_MESSAGE_CHECK_CSK_ENABLE:
        lresult = MMI_TRUE;
        break;
    case MMI_IMC_MESSAGE_CHECK_INFO_BAR_ENABL:
        if((((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type) == MMI_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPUT_BOX)
        {
            lresult = MMI_TRUE;
        }
        else
#if defined(__MMI_CAT116_SUPPORT__)
        if ((((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type) == MMI_EDITOR_CALL_PLAN_SINGLE_LINE_INPUT_BOX)
        {
            lresult = MMI_TRUE;
        }
        else
#endif /* defined(__MMI_CAT116_SUPPORT__) */
#if defined(__MMI_CAT103_SUPPORT__)
        if ((((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type) == MMI_EDITOR_AUTO_URL_COMPLETION_SINGLE_LINE_INPUT_BOX)
        {
            lresult = MMI_TRUE;
        }
        else
#endif /* defined(__MMI_CAT103_SUPPORT__) */
        if ((((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type) == MMI_EDITOR_BAIDU_SEARCH_SINGLE_LINE_INPUT_BOX)
        {
            lresult = MMI_TRUE;
        }
        else
        {
            lresult = MMI_FALSE;
        }
        break;
    case MMI_IMC_MESSAGE_GET_TEXT_PTR_BEFORE_CANDIDATE:
        
        if (editor_ptr->flags & UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP)
        {
            *((U8 **)(msg_ptr->param_1)) = (U8 *)editor_ptr->current_text_p - 2;
        }
        else if (editor_ptr->flags & UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT)
        {
            *((U8 **)(msg_ptr->param_1)) = (U8 *)editor_ptr->highlight_start_position;
        }
        else
        {
            *((U8 **)(msg_ptr->param_1)) = (U8 *)editor_ptr->current_text_p;
        }

        *((U8 **)(msg_ptr->param_0)) = (U8 *)editor_ptr->text;
        break;
        
    case MMI_IMC_MESSAGE_GET_TEXT_PTR_BEFORE_CURSOR:
        *((U8 **)(msg_ptr->param_1)) = (U8 *)editor_ptr->current_text_p;

        *((U8 **)(msg_ptr->param_0)) = (U8 *)editor_ptr->text;
        break;
        
    case MMI_IMC_MESSAGE_GET_STRING_BEFORE_CANDIDATE:
        /* if editor is in multitap state. */
        ///TODO: extend the function to get prevoious n character.
        if (editor_ptr->flags & UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP)
        {
            UI_string_type buf = (UI_string_type)msg_ptr->param_1;
			UI_buffer_type backup_cursor_p = editor_ptr->current_text_p;
			
            i = 0;
            
            editor_ptr->current_text_p = editor_ptr->input_start_cursor_p;
            while (msg_ptr->param_0)
            {
                if (gui_single_line_input_box_get_previous_character(editor_ptr, (UI_character_type*)&buf[i]))
                {
                    msg_ptr->param_0 --;
                    i ++;
                    editor_ptr->current_text_p -= ENCODING_LENGTH;
                }
                else
                {
                    break;
                }
            }
            editor_ptr->current_text_p = backup_cursor_p;
            return i;
        }
        else if (editor_ptr->flags & UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT &&
                 editor_ptr->flags & UI_SINGLE_LINE_INPUT_BOX_INPUT_METHOD_MODE)
        {
            UI_string_type buf = (UI_string_type)msg_ptr->param_1;
            UI_buffer_type backup_cursor_p = editor_ptr->current_text_p;
            /* move cursor to the begining of the highlight */
            editor_ptr->current_text_p = editor_ptr->highlight_start_position;
            i = 0;
            while (msg_ptr->param_0)
            {
                if (gui_single_line_input_box_get_previous_character(editor_ptr, (UI_character_type *)&buf[i]))
                {
                    msg_ptr->param_0 --;
                    i ++;
                    editor_ptr->current_text_p -= ENCODING_LENGTH;
                }
                else
                {
                    break;
                }
            }
            /* restore cursor to the begining of the highlight */
            editor_ptr->current_text_p = backup_cursor_p;
            return i;
        }
        else
        {
            UI_string_type buf = (UI_string_type)msg_ptr->param_1;
            UI_buffer_type backup_cursor_p = editor_ptr->current_text_p;
            i = 0;
            while (msg_ptr->param_0)
            {
                if (gui_single_line_input_box_get_previous_character(editor_ptr, (UI_character_type *)&buf[i]))
                {
                    msg_ptr->param_0 --;
                    i ++;
                    editor_ptr->current_text_p -= ENCODING_LENGTH;
                }
                else
                {
                    break;
                }
            }
            editor_ptr->current_text_p = backup_cursor_p;
            return i;
        }
            
    case MMI_IMC_MESSAGE_DRAW_INFORMATION_BAR:
#ifdef __MMI_SEARCH_WEB__
        if ((((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type) == MMI_EDITOR_BAIDU_SEARCH_SINGLE_LINE_INPUT_BOX)
        {
            wgui_cat2001_redraw_information_bar();
        }
        else
#endif /* __MMI_SEARCH_WEB__ */
        {
            wgui_inputs_sl_redraw_information_bar();
        }

        break;
    case MMI_IMC_MESSAGE_DRAW_IME_HINT:
        if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPUT_BOX)
        {
            MMI_ASSERT(g_wgui_cat200_draw_information_bar_func != NULL);
            g_wgui_cat200_draw_information_bar_func();
        }
        if(g_wgui_cat111_draw_information_bar_func!= NULL)
        {
            g_wgui_cat111_draw_information_bar_func();
        }
        break;
    case MMI_IMC_MESSAGE_SET_MULTITAP_STATE:
        editor_ptr->flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP;
        break;
    case MMI_IMC_MESSAGE_WCSS_CHECK:
        lresult = MMI_FALSE;
        break;        
    case MMI_IMC_MESSAGE_INSERT_CHAR_AT_DESIRED_POSITION:
        gui_single_line_input_box_insert_character_in_pos(editor_ptr, (UI_character_type)msg_ptr->param_1, msg_ptr->param_0);
        redraw_singleline_inputbox();
        singleline_inputbox_input_callback();
        break;
    case MMI_IMC_MESSAGE_DELETE_CHAR_AT_DESIRED_POSITION:
        gui_single_line_input_box_delete_character_in_pos(editor_ptr, msg_ptr->param_0);     
        redraw_singleline_inputbox();
        singleline_inputbox_input_callback();
        break;
    case MMI_IMC_MESSAGE_GET_CHAR_AT_DESIRED_POSITION:
        lresult = editor_ptr->text[msg_ptr->param_0];
        break;
        
#ifdef __MMI_CLIPBOARD__

#if defined(__MMI_TOUCH_SCREEN__)
    case MMI_IMC_MESSAGE_CLIPBOARD_LOCATE_CURSOR_P_BY_POS:
        ret = (MMI_BOOL)gui_single_line_input_box_translate_pen_event(
                            editor_ptr,
                            ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event,
                            ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.x,
                            ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.y,
                            &single_line_input_box_event);
        gui_show_single_line_input_box_ext(editor_ptr, 
										   ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.x, 
										   ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.y);
        if (!ret)
        {
            if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_LONG_TAP)
            {
                ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->ccp_start_cursor_p = editor_ptr->current_text_p;
            }
            else if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_UP)
            {
                ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->ccp_end_cursor_p = editor_ptr->current_text_p;
                ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->highlight_text_length =
                    (((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->ccp_end_cursor_p -
                    ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->ccp_start_cursor_p) / ENCODING_LENGTH;
            }
        }
        else
        {
            ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->editor_pen_event = (mmi_imc_editor_pen_event_enum)single_line_input_box_event;
		//	if (GUI_SINGLE_LINE_INPUT_BOX_PEN_SCROLL_BAR != single_line_input_box_event)
			{
			//	gui_show_single_line_input_box_ext(editor_ptr, 
			//							   ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.x, 
			//							   ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.y);
                if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_LONG_TAP)
                {
                    ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->ccp_start_cursor_p = editor_ptr->current_text_p;
                }
                else if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_MOVE)
                {
                    ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->ccp_end_cursor_p = editor_ptr->current_text_p;
                    /* Caculate the highlight text length */
                    ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->highlight_text_length =
                        (((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->ccp_end_cursor_p -
                        ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->ccp_start_cursor_p) / ENCODING_LENGTH;
                }
                else if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_UP &&
                         ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->ccp_end_cursor_p)
                {
                    editor_ptr->current_text_p = ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->ccp_end_cursor_p;
                }
			}

            if ((((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event != MMI_PEN_EVENT_LONG_TAP) &&
                (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event != MMI_PEN_EVENT_UP))
            {
                /* Adjust editor view when out of boundary */
                if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.x < (editor_ptr->x + WGUI_INPUTS_ADJUST_VIEW_OFFSET))
                {
                    editor_ptr->text_offset_x += WGUI_INPUTS_ADJUST_VIEW_OFFSET;
                }
                else if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.x > (editor_ptr->x + editor_ptr->width - WGUI_INPUTS_ADJUST_VIEW_OFFSET))
                {
                    editor_ptr->text_offset_x -= WGUI_INPUTS_ADJUST_VIEW_OFFSET;
                }
                if (editor_ptr->text_offset_x > 0 || editor_ptr->width >= editor_ptr->text_width)
                {
                    editor_ptr->text_offset_x = 0;
                }
                else if (editor_ptr->text_offset_x < (editor_ptr->width - editor_ptr->text_width) && (editor_ptr->width < editor_ptr->text_width))
                {
                    editor_ptr->text_offset_x = editor_ptr->width - editor_ptr->text_width;
                }

                gui_single_line_input_box_locate_cursor(editor_ptr);
            }
        }
        break;

    case MMI_IMC_MESSAGE_CLIPBOARD_ADJUST_VIEW:
        if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.x < editor_ptr->x)
        {
            gui_single_line_input_box_previous(editor_ptr);
            ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->ccp_end_cursor_p = editor_ptr->current_text_p;
            ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->highlight_text_length =
                (((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->ccp_end_cursor_p -
                ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->ccp_start_cursor_p) / ENCODING_LENGTH;
        }
        else if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.x > (editor_ptr->x + editor_ptr->width))
        {
            gui_single_line_input_box_next(editor_ptr);
            ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->ccp_end_cursor_p = editor_ptr->current_text_p;
            ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->highlight_text_length =
                (((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->ccp_end_cursor_p -
                ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->ccp_start_cursor_p) / ENCODING_LENGTH;
        }
        break;
#endif /* __MMI_TOUCH_SCREEN__ */

    case MMI_IMC_MESSAGE_CLIPBOARD_INSERT_STRING_WITH_LENGTH:
        lresult = wgui_inputs_sl_insert_string((UI_string_type)msg_ptr->param_0, (U32)msg_ptr->param_1, MMI_TRUE);
        break;

    case MMI_IMC_MESSAGE_CLIPBOARD_SET_START_CURSOR_P:
        ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_start_cursor_p = editor_ptr->current_text_p;
        break;

    case MMI_IMC_MESSAGE_CLIPBOARD_MARK_TEXT:
        if (((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->highlight_text_length > 0)
        {
            editor_ptr->highlight_start_position = ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_start_cursor_p;
            editor_ptr->highlight_end_position = ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_end_cursor_p;
        #ifdef __MMI_CLIPBOARD_FLOATING_MENU__   
            dm_imui_window_hide();
        #else
            wgui_inputs_sl_redraw();
        #endif
        }
        else if (((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->highlight_text_length < 0)
        {
            editor_ptr->highlight_start_position = ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_end_cursor_p;
            editor_ptr->highlight_end_position = ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_start_cursor_p;
        #ifdef __MMI_CLIPBOARD_FLOATING_MENU__   
            dm_imui_window_hide();
        #else
            wgui_inputs_sl_redraw();
        #endif
        }
        else if ((((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_start_cursor_p) ==
                 (((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_end_cursor_p))
        {
            editor_ptr->highlight_start_position = NULL; //((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_start_cursor_p;
            editor_ptr->highlight_end_position = NULL;   //((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_start_cursor_p;
        #ifdef __MMI_CLIPBOARD_FLOATING_MENU__   
            dm_imui_window_hide();
        #else
            wgui_inputs_sl_redraw();
        #endif
        }

        break;

    case MMI_IMC_MESSAGE_CLIPBOARD_MOVE_CORSOR:
        switch (msg_ptr->param_0)
        {
            case MMI_IMC_EDITOR_CURSOR_LEFT:
                gui_single_line_input_box_previous(editor_ptr);
                break;
            case MMI_IMC_EDITOR_CURSOR_RIGHT:
                gui_single_line_input_box_next(editor_ptr);
                break;
        }

        if (msg_ptr->param_1)
        {
            ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->ccp_end_cursor_p = editor_ptr->current_text_p;
            /* Caculate the highlight text length */
            ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->highlight_text_length =
                (((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->ccp_end_cursor_p -
                ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->ccp_start_cursor_p) / ENCODING_LENGTH;
        }
        else
        {
            /* Redraw editor in locate start cursor mode */
            wgui_inputs_sl_redraw();
        }
        break;

    case MMI_IMC_MESSAGE_CLIPBOARD_SAVE_STATUS:
        ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->pre_highlight_start_cursor_p = editor_ptr->highlight_start_position;
        ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->pre_highlight_end_cursor_p = editor_ptr->highlight_end_position;
        ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->pre_flags = editor_ptr->flags;
        ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->is_saved = 1;

    #if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__) 
        mmi_frm_gesture_disable(); 
    #endif
        editor_ptr->flags |= UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        editor_ptr->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
        editor_ptr->highlight_start_position = NULL;
        editor_ptr->highlight_end_position = NULL;
        editor_ptr->state = GUI_INPUT_BOX_STATE_SELECTING_TEXT;

        mmi_imc_clipboard_save_keys();
        break;

    case MMI_IMC_MESSAGE_CLIPBOARD_RESTORE_STATUS:
    #if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__) 
        mmi_frm_gesture_enable(); 
    #endif
        #ifdef __MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__
        if (MMI_singleline_inputbox.ext_flags & GUI_SINGLE_LINE_INPUT_BOX_RECIPIENT_MODE)
        {
            editor_ptr->highlight_start_position = NULL;
            editor_ptr->highlight_end_position = NULL;
            wgui_inputs_sl_move_cursor(WGUI_INPUTS_CURSOR_POS_END);
        }
        else
        #endif /*__MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__*/    
        {
            editor_ptr->highlight_start_position = ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->pre_highlight_start_cursor_p;
            editor_ptr->highlight_end_position = ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->pre_highlight_end_cursor_p;
        }
        editor_ptr->flags = ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->pre_flags;
        editor_ptr->state = GUI_INPUT_BOX_STATE_IDLE;
        break;

    case MMI_IMC_MESSAGE_CLIPBOARD_GET_ALL_TEXT:
        *((U8 **)(msg_ptr->param_0)) = editor_ptr->text;
        *((U32 *)msg_ptr->param_1) = editor_ptr->text_length - ENCODING_LENGTH;
        break;
    case MMI_IMC_MESSAGE_CLIPBOARD_GET_HIGHLIGHT_TEXT:
        if (((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->highlight_text_length > 0)
        {
            *((U8 **)(msg_ptr->param_1)) = ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_start_cursor_p;
        }
        else
        {
            *((U8 **)(msg_ptr->param_1)) = ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_end_cursor_p;
        }
        break;
    case MMI_IMC_MESSAGE_CLIPBOARD_IS_TEXT_HIGHLIGHT:
        if (((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->highlight_text_length != 0)
        {
            lresult = 1;
        }
        else
        {
            lresult = 0;
        }
        break;

    case MMI_IMC_MESSAGE_CLIPBOARD_IS_READ_ONLY_EDITOR:
        #ifdef __MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__
        if ((MMI_singleline_inputbox.ext_flags & GUI_SINGLE_LINE_INPUT_BOX_RECIPIENT_MODE) && 
			!((editor_ptr->highlight_end_position - editor_ptr->highlight_start_position == 0)
			   && (editor_ptr->current_text_p == MMI_singleline_inputbox.last_position_p - ENCODING_LENGTH))) // no highlight text and cursor is at last position, in this case, it should allow to paste
        {
            lresult = 1;
        }
        #endif /*__MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__*/
        break;

    case MMI_IMC_MESSAGE_CLIPBOARD_SET_HIGHLIGHT:
        break;
    
    case MMI_IMC_MESSAGE_CLIPBOARD_GET_EDITOR_TYPE:

        ((mmi_imc_editor_menu_history_data_struct_p)msg_ptr->param_0)->is_read_only = MMI_FALSE;

        ((mmi_imc_editor_menu_history_data_struct_p)msg_ptr->param_0)->is_paging = MMI_FALSE;

        if (wgui_inputs_sl_is_empty())
        {
            ((mmi_imc_editor_menu_history_data_struct_p)msg_ptr->param_0)->is_empty = MMI_TRUE;
        }
        else
        {
            ((mmi_imc_editor_menu_history_data_struct_p)msg_ptr->param_0)->is_empty = MMI_FALSE;
        }

        ((mmi_imc_editor_menu_history_data_struct_p)msg_ptr->param_0)->is_wcss = MMI_FALSE;

        if (editor_ptr->flags & UI_SINGLE_LINE_INPUT_BOX_MASK_CHARACTERS)
        {
            ((mmi_imc_editor_menu_history_data_struct_p)msg_ptr->param_0)->is_password = MMI_TRUE;
        }
        else
        {
            ((mmi_imc_editor_menu_history_data_struct_p)msg_ptr->param_0)->is_password = MMI_FALSE;
        }

        lresult = MMI_TRUE;
        break;

    case MMI_IMC_MESSAGE_CLIPBOARD_CUT_HIGHLIGHT_STRING:
        #ifdef __MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__
        // should not cut the string in recipient which added from phonebook
        if (MMI_singleline_inputbox.ext_flags & GUI_SINGLE_LINE_INPUT_BOX_RECIPIENT_MODE)
        {
            break;
        }
        #endif /*__MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__*/

        if (msg_ptr->param_1 == 1)
        {
            editor_ptr->current_text_p = ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_start_cursor_p;
            cut_cursor_p = ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_end_cursor_p;
        }
        else if (msg_ptr->param_1 == 0)
        {
            cut_cursor_p = ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_start_cursor_p;
        }
        else if (msg_ptr->param_1 == 3)
        {
            cut_cursor_p = ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_end_cursor_p;
            editor_ptr->current_text_p = cut_cursor_p + WGUI_INPUTS_CLIPBOARD_MAX_SIZE;
        }
        else if (msg_ptr->param_1 == 2)
        {
            cut_cursor_p = ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_start_cursor_p;
            editor_ptr->current_text_p = cut_cursor_p + WGUI_INPUTS_CLIPBOARD_MAX_SIZE;
        }

        old_show_action_flag = editor_ptr->show_action_flag;
        editor_ptr->show_action_flag = 0;
        while ((editor_ptr->current_text_p) > cut_cursor_p && (cut_cursor_p != NULL))
        {
            wgui_inputs_sl_check_decimal();
            #if 0 /* slim_2_2 */ //
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
            gui_single_line_input_box_delete_character(&MMI_singleline_inputbox);
        }
        editor_ptr->show_action_flag = old_show_action_flag;

        gui_single_line_input_box_locate_cursor(&MMI_singleline_inputbox);
        wgui_inputs_sl_redraw();        

        singleline_inputbox_input_callback();
        break;

    case MMI_IMC_MESSAGE_CLIPBOARD_CUT_ALL:
         if (msg_ptr->param_0 == 0)
         {
             wgui_inputs_sl_delete_all_characters();
         }
         else if (msg_ptr->param_0 == 1)
         {
             old_show_action_flag = editor_ptr->show_action_flag;
             editor_ptr->show_action_flag = 0;
             editor_ptr->current_text_p = editor_ptr->text + WGUI_INPUTS_CLIPBOARD_MAX_SIZE;
             while (editor_ptr->current_text_p > editor_ptr->text)
             {
                 gui_single_line_input_box_delete_character(&MMI_singleline_inputbox);
             }
             editor_ptr->show_action_flag = old_show_action_flag;
             wgui_inputs_sl_redraw();
        }
        break;

    case MMI_IMC_MESSAGE_CLIPBOARD_IS_PASSWORD_EDITOR:
        if (editor_ptr->flags & UI_SINGLE_LINE_INPUT_BOX_MASK_CHARACTERS)
        {
            lresult = MMI_TRUE;
        }
        else
        {
            lresult = MMI_FALSE;
        }
        break;

    case MMI_IMC_MESSAGE_CLIPBOARD_IS_ALLOWED_CUT_ALL:
        #ifdef __MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__
        if (MMI_singleline_inputbox.ext_flags & GUI_SINGLE_LINE_INPUT_BOX_RECIPIENT_MODE)
        {
            lresult = MMI_TRUE;
        }
        #endif /*__MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__*/
        break;

#ifdef __MMI_CLIPBOARD_FLOATING_MENU__
    case MMI_IMC_MESSAGE_CLIPBOARD_GET_HILITE_RECT:
        if (editor_ptr->hilite_s_x == 0)
        {
            ((mmi_imc_clipboard_hilite_rect_p)msg_ptr->param_0)->s_x = 0;
        }
        else
        {
            ((mmi_imc_clipboard_hilite_rect_p)msg_ptr->param_0)->s_x = (editor_ptr->hilite_s_x > editor_ptr->x) ? editor_ptr->hilite_s_x : editor_ptr->x;
        }
        ((mmi_imc_clipboard_hilite_rect_p)msg_ptr->param_0)->s_y = editor_ptr->hilite_s_y;
        if (editor_ptr->hilite_e_x == 0)
        {
            ((mmi_imc_clipboard_hilite_rect_p)msg_ptr->param_0)->e_x = 0;
        }
        else
        {
            ((mmi_imc_clipboard_hilite_rect_p)msg_ptr->param_0)->e_x = (editor_ptr->hilite_e_x > (editor_ptr->x + editor_ptr->width)) ? (editor_ptr->x + editor_ptr->width) : editor_ptr->hilite_e_x;
        }
        ((mmi_imc_clipboard_hilite_rect_p)msg_ptr->param_0)->e_y = editor_ptr->hilite_e_y;
        break;
#endif /* __MMI_CLIPBOARD_FLOATING_MENU__ */

#endif /* __MMI_CLIPBOARD__ */
        
    case MMI_IMC_MESSAGE_HAS_SSP_ACTED:
#if defined(__MMI_EDITOR_SSP_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        lresult = gui_input_box_ssp_is_scrolling();
#endif
        break;

    default:
        break;
    }
		UI_UNUSED_PARAMETER(ret);
    return lresult;
    
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_handle_right_arrow_repeat
 * DESCRIPTION
 *  handle right arrow key repeat of singleline input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inputs_sl_handle_right_arrow_repeat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_fast_del_nav_handler(WGUI_INPUTS_OPER_FAST_NAV_RIGHT, WGUI_INPUTS_EDITOR_SL, WGUI_INPUTS_KPD_REPEAT_PERIOD);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_handle_left_arrow_repeat
 * DESCRIPTION
 *  handle left arrow key repeat of singleline input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inputs_sl_handle_left_arrow_repeat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_fast_del_nav_handler(WGUI_INPUTS_OPER_FAST_NAV_LEFT, WGUI_INPUTS_EDITOR_SL, WGUI_INPUTS_KPD_REPEAT_PERIOD);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_handle_right_softkey_repeat
 * DESCRIPTION
 *  handle right softkey repeat of singleline input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inputs_sl_handle_right_softkey_repeat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_inputs_sl_is_empty())
    {
        return;
    }

    wgui_inputs_fast_del_nav_handler(WGUI_INPUTS_OPER_FAST_DEL, WGUI_INPUTS_EDITOR_SL, WGUI_INPUTS_KPD_REPEAT_PERIOD);
    if (wgui_inputs_sl_is_empty())
    {
        if (wgui_singleline_inputbox_decimal_input_mode_flag)
        {
            wgui_singleline_inputbox_decimal_flag = 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_handle_right_softkey_touch_repeat
 * DESCRIPTION
 *  handle right softkey repeat of singleline input box (Touch panel RSK)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inputs_sl_handle_right_softkey_touch_repeat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_inputs_sl_is_empty())
    {
        return;
    }

    wgui_inputs_fast_del_nav_handler(WGUI_INPUTS_OPER_FAST_DEL, WGUI_INPUTS_EDITOR_SL, WGUI_INPUTS_TP_REPEAT_PERIOD);
    if (wgui_inputs_sl_is_empty())
    {
        if (wgui_singleline_inputbox_decimal_input_mode_flag)
        {
            wgui_singleline_inputbox_decimal_flag = 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_register_change_event_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_register_change_event_handler(
			MMI_BOOL (*handler)(gui_multi_line_input_box_change_event_enum event,U16 C))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	gui_single_line_input_box_register_change_event_handler(&MMI_singleline_inputbox,handler);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_set_default_text
 * DESCRIPTION
 *  Set singleline inputbox default text when empty
 * PARAMETERS
 *  default_text         [IN]       default text content, must be global string
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_set_default_text(UI_string_type default_text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_singleline_inputbox.default_text = default_text;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_move_cursor
 * DESCRIPTION
 *  Move the singleline editor cursor
 * PARAMETERS
 *  pos             [IN]                              cursor position
 *                  WGUI_INPUTS_CURSOR_POS_START   start position
 *                  WGUI_INPUTS_CURSOR_POS_END     end position
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_sl_move_cursor(wgui_inputs_cursor_pos_enum pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pos == WGUI_INPUTS_CURSOR_POS_START)
    {
        MMI_singleline_inputbox.current_text_p = MMI_singleline_inputbox.text;
    }
    else if(pos == WGUI_INPUTS_CURSOR_POS_END)
    {
        MMI_singleline_inputbox.current_text_p = MMI_singleline_inputbox.last_position_p - ENCODING_LENGTH;
    }
    else
    {
        MMI_ASSERT(0);
    }

    gui_show_single_line_input_box_ext(&MMI_singleline_inputbox, -1, -1);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_sl_move_cursor
 * DESCRIPTION
 *  Move the singleline editor cursor
 * PARAMETERS
 *  is_break             [IN] break or not
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_set_break_insert(MMI_BOOL is_break)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_inputs_is_break_insert = is_break;
}


/*****************************************************************************
* FUNCTION
*  wgui_inputs_sl_insert_string
* DESCRIPTION
*  Insert string at current cursor position.
* PARAMETERS
* str           [in]        string to insert
* len           [in]        string length
* is_redraw     [in]        if need redraw after insert        
* RETURNS
*  characters inserted
*****************************************************************************/
U32 wgui_inputs_sl_insert_string(UI_string_type str, U32 len, MMI_BOOL is_redraw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, total_len = 0;
    U32 old_show_action_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__
    /* CAN NOT modify the recipient add from phonebook */
    if ((MMI_singleline_inputbox.ext_flags & GUI_SINGLE_LINE_INPUT_BOX_RECIPIENT_MODE) &&
        (MMI_singleline_inputbox.current_text_p != (MMI_singleline_inputbox.last_position_p - ENCODING_LENGTH)))
    {
        wgui_inputs_sl_move_cursor(WGUI_INPUTS_CURSOR_POS_END);
 
    }
    #endif /*__MMI_EDITOR_SINGLE_SUPPORT_RECIPIENT_MODE__*/

    old_show_action_flag = MMI_singleline_inputbox.show_action_flag;
    MMI_singleline_inputbox.show_action_flag = 0;
    g_wgui_inputs_is_break_insert = MMI_TRUE;
    for (i = 0; i < len; i++)
    {
        if (MMI_TRUE == wgui_inputs_is_input_char_valid((UI_character_type)str[i]))
        {
            if (((UI_character_type)str[i] == 0x0D) || ((UI_character_type)str[i] == 0x1b))
            {
                continue;
            }
            else if (MMI_TRUE == wgui_inputs_sl_direct_input_no_draw((UI_character_type)str[i]))
            {
                total_len ++;
                g_wgui_inputs_is_break_insert = MMI_TRUE;
            }
            else if (g_wgui_inputs_is_break_insert)
            {
                break;
            }
        }
        else
        {
            UI_editor_play_tone_cannot_insert();
            break;
        }
    }
    MMI_singleline_inputbox.show_action_flag = old_show_action_flag;

    gui_single_line_input_box_locate_cursor(&MMI_singleline_inputbox);
    if (is_redraw)
    {
        wgui_inputs_sl_redraw();
    }

    if (total_len >0)
    {
        singleline_inputbox_input_callback();
    }

    return total_len;
}


/*****************************************************************************
* FUNCTION
*  wgui_inputs_sl_disable
* DESCRIPTION
*  Disable singleline inputbox. 
*  Only hide the cursor and change the background filler to disabled_filler 
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
void wgui_inputs_sl_disable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_singleline_inputbox.flags |= (UI_SINGLE_LINE_INPUT_BOX_STATE_DISABLED | UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW);
    StopTimer(BLINKING_CURSOR);
    wgui_inputs_sl_redraw();
}


/*****************************************************************************
* FUNCTION
*  wgui_inputs_sl_enable
* DESCRIPTION
*  Enable singleline inputbox. 
*  Show the cursor and reset the background filler to normal_filler
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
void wgui_inputs_sl_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_singleline_inputbox.flags &= ~(UI_SINGLE_LINE_INPUT_BOX_STATE_DISABLED | UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW);
    wgui_inputs_sl_redraw();
}
