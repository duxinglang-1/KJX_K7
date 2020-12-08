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
 * gui_input_owl.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

/* Native system part */
#include "GlobalDefs.h"
#include "kal_non_specific_general_types.h"
#include "stack_config.h"
#include "kal_trace.h"

#include "MMI_features.h"
#include "mmi_frm_gprot.h"
#include "WguiCategoryGprot.h"

#include "PixcomFontEngine.h"
#include "App_mine.h"


#include "app_str.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
extern S16* predef_pos;
extern U8 wcss_format_result[];
extern MMI_BOOL is_wcss_use_star;
extern MMI_BOOL is_1st_use_115ex;
extern S32 wcss_cursor_pos;
extern S32 wcss_cursor_pre_pos;
extern U16 wcss_buffer_len;
/* Since Valid format position can be '0' also so "-1" has been taken as default value */
static S32 g_format_position = -1;
extern MMI_BOOL mmi_ime_is_in_symbol_picker(U16 ch);

/*****************************************************************************              
 * Local Variable                                                                    
 *****************************************************************************/
MMI_BOOL cursor_move_cb_chk_recursive = MMI_FALSE;
/* check cusror move callback is from deleting escape */
static MMI_BOOL is_from_delete_escape = MMI_FALSE;
static MMI_BOOL is_skip_redraw_imc_cursor_cb = MMI_FALSE;


/****  MAUI_03119320 starts  ****/
//char count_flag;  //MAUI_03254896 side effect of MAUI_03119320
/****  MAUI_03119320 ends  ****/


/*****************************************************************************              
 * Local Function                                                                    
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  wcss_cursor_move_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cursor_offset          [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void wcss_cursor_move_cb(S32 cursor_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_imm_input_mode_enum required_input_mode[3] = 
        {IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC_NO_NUMERIC,
         IMM_INPUT_MODE_NONE,
         IMM_INPUT_MODE_NONE};
    S32 format_pos = 0, i;
    UI_character_type replace_char = ' ';
    U32 imm_input_type;
    mmi_imm_input_mode_enum* required_input_mode_array = required_input_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* prevent infinite recursive call */
    if (cursor_move_cb_chk_recursive == MMI_TRUE)
    {
        return;
    }

    /* Skip while in multitap active mode */
    if (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP)
    {
        /* prevent to avoid the cursor movement */
        return;        
    }

    MMI_ASSERT(cursor_offset >= 0);
    wcss_cursor_pre_pos = wcss_cursor_pos;
    wcss_cursor_pos = cursor_offset;
    format_pos = wcss_cursor_pos;

    /* no need to change input mode when out of wcss buffer length */
    if ((is_wcss_use_star == MMI_FALSE) && ((wcss_buffer_len-1) <= wcss_cursor_pos))
    {
        // When cursor is out-of-position, always set to last one
        for (i = wcss_buffer_len - 2; i >= 0; i--)
        {
            if (wcss_format_result[i] != '\\')
            {
                break;
            }
        }
        if (i < 0)
        {
            return;
        }
        format_pos = i;
    }
    else if ((is_wcss_use_star == MMI_TRUE) && ((wcss_buffer_len - 1) < wcss_cursor_pos))
    {
        // When cursor is out-of-position, always set to last one
        format_pos = wcss_buffer_len - 1;
    }

    switch (wcss_format_result[format_pos])
    {
        case '\\':
            gui_multi_line_input_box_next(&MMI_multiline_inputbox);
            return;
        case 'A':
            required_input_mode[0] = IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC_NO_NUMERIC;
            imm_input_type = IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_EXT_MULTITAP | IMM_INPUT_TYPE_EXT_ENGLISH_UPPERCASE;
            break;
        case 'a':
            required_input_mode[0] = IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC_NO_NUMERIC;
            imm_input_type = IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_EXT_MULTITAP;
            break;
        case 'N':
            replace_char = '0';
            required_input_mode[0] = IMM_INPUT_MODE_123;
            imm_input_type = IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_EXT_MULTITAP;
            break;
        case 'n':
            replace_char = '0';
            required_input_mode[0] = IMM_INPUT_MODE_123_SYMBOLS;
            imm_input_type = IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_EXT_MULTITAP;
            break;
        case 'X':
            required_input_mode[0] = IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC;
            required_input_mode[1] = IMM_INPUT_MODE_123_SYMBOLS;
            imm_input_type = IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_EXT_MULTITAP| IMM_INPUT_TYPE_EXT_ENGLISH_UPPERCASE;
            break;
        case 'M':
            required_input_mode[0] = IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC;
/* MAUI_03254896 starts */
            if (mmi_ucs2strlen(MMI_multiline_inputbox.text) > 0)
            {
                required_input_mode[0] = mmi_imm_get_curr_input_mode();
            }
/* MAUI_03254896 emds */
            imm_input_type = IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_EXT_MULTITAP | IMM_INPUT_TYPE_EXT_ENGLISH_UPPERCASE;
            required_input_mode_array  = NULL;
            break;
        case 'x':
            required_input_mode[0] = IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC;
            required_input_mode[1] = IMM_INPUT_MODE_123_SYMBOLS;
            imm_input_type = IMM_INPUT_TYPE_USER_SPECIFIC | IMM_INPUT_TYPE_EXT_MULTITAP;
            break;
        case 'm':
            required_input_mode[0] = IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC;
            imm_input_type = IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_EXT_MULTITAP;
            required_input_mode_array  = NULL;
            break;
        default:
			imm_input_type = 0;
            MMI_ASSERT(0);
    }

    if (is_from_delete_escape == MMI_TRUE)
    {
        is_from_delete_escape = MMI_FALSE;
        gui_multi_line_input_box_insert_character(&MMI_multiline_inputbox, replace_char);
        gui_multi_line_input_box_previous(&MMI_multiline_inputbox);
    }

    cursor_move_cb_chk_recursive = MMI_TRUE;

/****  MAUI_03119320 starts  ****/
//	if(count_flag == 0)     //MAUI_03254896 side effect of MAUI_03119320
	{
/**** MAUI_03119320 ends  ****/
         mmi_imm_config_change_input_mode(MMI_TRUE);
         mmi_imm_set_required_mode_list(
             imm_input_type,
             required_input_mode_array,
             required_input_mode[0]);
	
         mmi_imm_change_input_mode_for_wcss(required_input_mode[0]);
/****  MAUI_03119320 starts ****/
//	     count_flag = 1;    //MAUI_03254896 side effect of MAUI_03119320
/****  MAUI_03119320 ends  ****/
	}
	

    if (required_input_mode_array != NULL && required_input_mode_array[1] == IMM_INPUT_MODE_NONE)
    {
        mmi_imm_config_change_input_mode(MMI_FALSE);
    }
    if ((is_1st_use_115ex != MMI_TRUE) && (is_skip_redraw_imc_cursor_cb != MMI_TRUE))
    {
        mmi_imc_redraw_screen_by_state();
    }
    cursor_move_cb_chk_recursive = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wcss_touch_owladp_event_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event          [IN]     
 *  c              [IN]     
 * RETURNS
 *  Handle event result
 *****************************************************************************/
MMI_BOOL wcss_touch_owladp_event_handler(gui_multi_line_input_box_change_event_enum event,U16 c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 format_pos = 0;
    MMI_BOOL need_to_play_tone = MMI_TRUE;
    static U8 previous_event = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (g_format_position != -1)
	{
	    format_pos = g_format_position;
	}
	else
	{
           format_pos = wcss_cursor_pos;
	}

    switch (event)
    {
        case GUI_MULTI_LINE_INPUT_BOX_DELETEALL:
            if (format_pos <=0)
            {
                UI_editor_play_tone_cannot_change();    /* play tone */
                return MMI_FALSE;
            }
            gdi_layer_lock_frame_buffer();
            is_skip_redraw_imc_cursor_cb = MMI_TRUE;
            while (format_pos > 0)
            {
                /* Check if *M in the end */
                if ((is_wcss_use_star == MMI_TRUE) && ((wcss_buffer_len-1) <= format_pos))
                {
                    gui_multi_line_input_box_delete_character(&MMI_multiline_inputbox);
                    need_to_play_tone = MMI_FALSE;
                    format_pos--;
                    continue;
                }
                format_pos--;
                g_format_position = format_pos;
                switch (wcss_format_result[format_pos])
                {
                    case '\\':
                        continue;
                    case 'A':
                    case 'a':
                    case 'X':
                    case 'x':
                    case 'M':
                    case 'm':
                        gui_multi_line_input_box_previous(&MMI_multiline_inputbox);
                        gui_multi_line_input_box_insert_character(&MMI_multiline_inputbox, ' ');
                        gui_multi_line_input_box_previous(&MMI_multiline_inputbox);
                        need_to_play_tone = MMI_FALSE;
                        continue;
                    case 'N':
                    case 'n':
                        gui_multi_line_input_box_previous(&MMI_multiline_inputbox);
                        gui_multi_line_input_box_insert_character(&MMI_multiline_inputbox, '0'); 
                        gui_multi_line_input_box_previous(&MMI_multiline_inputbox);
                        need_to_play_tone = MMI_FALSE;
                        continue;
                    default:
                        MMI_ASSERT(0);
                }
            }
            if ((is_wcss_use_star == MMI_TRUE) && ((wcss_buffer_len-1) <= format_pos))
            {
                gui_multi_line_input_box_delete_character(&MMI_multiline_inputbox);
                need_to_play_tone = MMI_FALSE;
            }
            is_skip_redraw_imc_cursor_cb = MMI_FALSE;
            gdi_layer_unlock_frame_buffer();
            mmi_imc_redraw_screen_by_state();
            if (need_to_play_tone)
            {
            	UI_editor_play_tone_cannot_change();    /* play tone */
            }
	    /* After deleting all the characters reset it to orgnal value.*/
	    g_format_position = -1;
            return MMI_FALSE;
            break;

        case GUI_MULTI_LINE_INPUT_BOX_DELETE_CHAR:
            /* Check if *M in the end */
            if ((is_wcss_use_star == MMI_TRUE) && ((wcss_buffer_len-1) < format_pos))
            {
                return MMI_TRUE;
            }

            if (format_pos <=0)
            {
                return MMI_FALSE;
            }

            format_pos--;
            if (wcss_format_result[format_pos] == '\\') 
            {
                format_pos --;
            }            
            previous_event = GUI_MULTI_LINE_INPUT_BOX_DELETE_CHAR;
            g_format_position = format_pos;
            switch (wcss_format_result[format_pos])
            {
                case '\\':
                    is_from_delete_escape = MMI_TRUE;
                    gui_multi_line_input_box_previous(&MMI_multiline_inputbox);
                    is_from_delete_escape = MMI_FALSE;
                    return MMI_FALSE;
                case 'A':
                case 'a':
                case 'X':
                case 'x':
                case 'M':
                case 'm':
                    if ((is_wcss_use_star == MMI_TRUE) && ((wcss_buffer_len-1) == format_pos))
                    {
                       return MMI_TRUE;
                    }
                    is_skip_redraw_imc_cursor_cb = MMI_TRUE;
                    gui_multi_line_input_box_previous(&MMI_multiline_inputbox);
                    gui_multi_line_input_box_insert_character(&MMI_multiline_inputbox, ' ');
                    gui_multi_line_input_box_previous(&MMI_multiline_inputbox);
                    is_skip_redraw_imc_cursor_cb = MMI_FALSE;
                    mmi_imc_redraw_screen_by_state();
                    g_format_position = -1;
                    previous_event = -1;
                    return MMI_FALSE;
                case 'N':
                case 'n':
                    if ((is_wcss_use_star == MMI_TRUE) && ((wcss_buffer_len-1) == format_pos))
                    {
                       return MMI_TRUE;
                    }
                    is_skip_redraw_imc_cursor_cb = MMI_TRUE;
                    gui_multi_line_input_box_previous(&MMI_multiline_inputbox);
                    
                    gui_show_multi_line_input_box(&MMI_multiline_inputbox); // newly added to show the 0 in wcss when delete
                   
                    gui_multi_line_input_box_insert_character(&MMI_multiline_inputbox, '0'); 
                    gui_multi_line_input_box_previous(&MMI_multiline_inputbox);

                    gui_show_multi_line_input_box(&MMI_multiline_inputbox); // newly added to show the 0 in wcss when delete
                    
                    is_skip_redraw_imc_cursor_cb = MMI_FALSE;
                    mmi_imc_redraw_screen_by_state();
                    return MMI_FALSE;
                default:
                    MMI_ASSERT(0);
            }
            break;
        case GUI_MULTI_LINE_INPUT_BOX_INSERT_CHAR:
            if ((wcss_buffer_len-1) <= format_pos)
            {
                if (is_wcss_use_star == MMI_TRUE)
                {
                    format_pos = wcss_buffer_len - 1;
                }
                else
                {
                    return MMI_FALSE;
                }
            }

            if (format_pos < 0)
            {
                format_pos = 0;
                //return MMI_FALSE;
            }
            if (previous_event == GUI_MULTI_LINE_INPUT_BOX_DELETE_CHAR && g_format_position != -1)
            {
                format_pos = g_format_position;
            }
            switch (wcss_format_result[format_pos])
            {
                case '\\':
                    gui_multi_line_input_box_next(&MMI_multiline_inputbox);
                    mmi_imc_redraw_screen_by_state();
                    return MMI_FALSE;
                case 'A':
                    if ((c >= '0') && (c <= '9') || (c >= 'a') && (c <= 'z'))
                    {
                        return MMI_FALSE;
                    }
                    else
                    {
                        return MMI_TRUE;
                    }
                case 'a':
                    if ((c >= '0') && (c <= '9') || (c >= 'A') && (c <= 'Z'))
                    {
                        return MMI_FALSE;
                    }
                    else
                    {
                        return MMI_TRUE;
                    }
                case 'X':
                    if ((c >= 'a') && (c <= 'z'))
                    {
                        return MMI_FALSE;
                    }
                    else
                    {
                        return MMI_TRUE;
                    }
                case 'x':
                    if ((c >= 'A') && (c <= 'Z'))
                    {
                        return MMI_FALSE;
                    }
                    else
                    {
                        return MMI_TRUE;
                    }
                case 'M':
                case 'm':
                    return MMI_TRUE;
                case 'n':
		   return (((c >= '0') && (c <= '9')) || (mmi_ime_is_in_symbol_picker(c)));

                case 'N':
                    if ((c >= '0') && (c <= '9'))
                    {
                        return MMI_TRUE;
                    }
                    else
                    {
                        return MMI_FALSE;
                    }
                default:
                    MMI_ASSERT(0);
            }
            break;
        default:
            MMI_ASSERT(0);
    }

    return MMI_TRUE;
}



