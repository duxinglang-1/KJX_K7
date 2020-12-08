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
 *   gui_single_line_inputs.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Editor layout
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//#include "mmi_frm_gprot.h"
//#include "WguiCategoryGprot.h"
//#include "lcd_sw_rnd.h"

#ifdef __MMI_INDIC_ALG__
#include "IndicEngineGprot.h"
extern U32 add_template_multiline_flag;

#define MAX_EDITOR_DISP_LEN      60
#endif /* __MMI_INDIC_ALG__ */ 

#include "LangModuleGProt.h"


/* MTK Elvis for R2L characters */
#include "BIDIDEF.h"
#include "BIDIProt.h"

#include "gui_inputs_internal.h"
#include "IMERes.h"
#if defined (__MMI_ARSHAPING_ENGINE__)
#include "ArabicGProt.h"
#endif 

    #include "MMIDataType.h"
    #include "gui_inputs.h"
    #include "gui_data_types.h"
    #include "string.h"
    #include "CustThemesRes.h"
    #include "gui.h"
    #include "wgui_inputs.h"
    #include "gui_themes.h"
    #include "kal_general_types.h"
    #include "wgui_categories_util.h"
    #include "gdi_include.h"
    #include "Unicodexdcl.h"
    #include "PixcomFontEngine.h"
    #include "gui_config.h"
    
    #include "MMI_features.h"
    #include "ImeGprot.h"
    #include "kal_public_api.h"
    #include "DebugInitDef_Int.h"
    #include "lcd_sw_inc.h"
#ifdef __MMI_VUI_ENGINE__
    #include "vadp_p2v_uc.h"
#endif
    #include "gdi_const.h"

/* Static function */
static U8 gui_get_single_line_current_cluster(
    single_line_input_box *b,
    single_line_input_box_show_struct *bs,
    UI_character_type *current_character_p,
    mmi_lm_cluster_info_p pre2_cl,
    mmi_lm_cluster_info_p pre_cl,
    mmi_lm_cluster_info_p cur_cl);

static void gui_get_single_line_character_color(
                single_line_input_box *b,
                single_line_input_box_show_struct *bs);

static S32 gui_check_single_line_character_highlight(single_line_input_box *b, single_line_input_box_show_struct *bs);

static void gui_draw_single_line_character(
                single_line_input_box *b,
                single_line_input_box_show_struct *bs,
                UI_character_type current_character);
static void gui_handle_single_line_cursor(
                single_line_input_box *b,
                single_line_input_box_show_struct *bs,
                U8 last_one_flag);

static void gui_draw_single_line_highlight(single_line_input_box *b, single_line_input_box_show_struct *bs);

/*****************************************************************************
 * FUNCTION
 *  gui_init_single_line_show_struct
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     [?]
 *  bs      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_init_single_line_show_struct(single_line_input_box *b, single_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* maybe this init-zero can be  */
    memset(bs, 0, sizeof(single_line_input_box_show_struct));

    bs->current_text_p = b->text;
    bs->current_cursor_p = b->current_text_p;
    bs->previous_cursor_p = b->current_text_p;
    bs->selector_color = b->selection_color;
    bs->selected_text_color = b->selection_text_color;
    bs->flags = b->flags;
    bs->default_direction = BIDI_L;
    bs->text_gap = b->text_gap;

    g_editor_line.bidi_done_flag = 0;

    b->hilite_s_x = 0;
    b->hilite_s_y = 0;
    b->hilite_e_x = 0;
    b->hilite_e_y = 0;
}

#ifdef __MMI_BIDI_ALG__
/*****************************************************************************
 * FUNCTION
 *  gui_get_single_line_text_language_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     [?]
 *  bs      [?]     [?]
 * RETURNS
 *  PMT_BIDI_TYPES
 *****************************************************************************/
PMT_BIDI_TYPES gui_get_single_line_text_language_type(single_line_input_box *b, MMI_BOOL *arabic_char_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 iCount;
    U8 lastest_char_type;
    U16 strongCharType = 0xFFFF;
    const sIMEModeDetails *mode_details_ptr = NULL;
    PMT_BIDI_TYPES default_direction = BIDI_L;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->text_length / ENCODING_LENGTH > 1)
    {
        /* text is not '\0' or null */
        for (iCount = 0; iCount < (U32) ((b->text_length >> 1) - 1); iCount++)
        {
            bidi_get_char_type((U8*) (b->text + iCount * ENCODING_LENGTH), (U8*) & lastest_char_type);
            if ((lastest_char_type == AL 
                || lastest_char_type == BIDI_L 
                || lastest_char_type == BIDI_R
                || lastest_char_type == AN)
                && strongCharType == 0xFFFF)
            {
                strongCharType = lastest_char_type;
            }

            if ((lastest_char_type == AL) || (lastest_char_type == AN) || (lastest_char_type == BIDI_R))
            {
                *arabic_char_flag = MMI_TRUE;
                break;
            }
        }

    #ifdef GUI_INPUTBOX_ALIGNMENT_WHEN_EXIST_R2L_CHAR
        if (*arabic_char_flag)
    #else 
        if (strongCharType == AL || strongCharType == BIDI_R || strongCharType == AN)
    #endif 
        {
            default_direction = BIDI_R;
        }
        else
        {
            default_direction = BIDI_L;

            if (strongCharType == 0xFFFF)
            {
                if (mmi_imc_is_connected() && !(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW))
                {
                    mode_details_ptr = mmi_imm_get_input_mode_array_item(mmi_imm_get_curr_input_mode());
                    
                    if (mode_details_ptr)
                    {
                        if (mode_details_ptr->lang_id == IME_WRITING_LANG_AR
                            || mode_details_ptr->lang_id == IME_WRITING_LANG_UR
                            || mode_details_ptr->lang_id == IME_WRITING_LANG_PS
                            || mode_details_ptr->lang_id == IME_WRITING_LANG_HE)
                        {
                            default_direction = BIDI_R;
                        }
                    }
                }
            }
        }
    }
    else
    {
        /* text is '\0' or null */
        if (mmi_imc_is_connected() && !(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW))
        {
            /* imc connected, deside editor direction from ime language */
            mode_details_ptr = mmi_imm_get_input_mode_array_item(mmi_imm_get_curr_input_mode());
            
            if (mode_details_ptr)
            {
                if (mode_details_ptr->lang_id == IME_WRITING_LANG_AR
                    || mode_details_ptr->lang_id == IME_WRITING_LANG_UR
                    || mode_details_ptr->lang_id == IME_WRITING_LANG_PS
                    || mode_details_ptr->lang_id == IME_WRITING_LANG_HE)
                {
                    default_direction = BIDI_R;
                }
            }
        }
        else
        {
            /* not connected ime, deside editor direction from system setting */
            if (mmi_fe_get_r2l_state())
            {
                default_direction = BIDI_R;
            }
        }
    }

    return default_direction;
}


/*****************************************************************************
 * FUNCTION
 *  gui_translate_single_line_bidi_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_translate_single_line_bidi_text(single_line_input_box *b, single_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 char_type;
    S32 num_char, iCount;
    MMI_BOOL line_arabic_char_flag = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bs->arabic_char_flag || bs->default_direction != BIDI_L)
    {
        num_char = mmi_ucs2strlen((const CHAR*)b->text);

        if (num_char == 0)
        {
            return;
        }

        /* adjust the cursor position */
        MMI_ASSERT(b->current_text_p >= b->text);
        MMI_ASSERT(num_char <= GUI_INPUTS_MAX_NUM_OF_CHAR_FOR_BIDI_IN_ONE_LINE/2);
        bs->logical_cur_pos = (b->current_text_p - b->text) / ENCODING_LENGTH;

        if (bs->logical_cur_pos > num_char)
            bs->logical_cur_pos = num_char;

        for (iCount = 0; iCount < num_char; iCount++)
        {
            bidi_get_char_type((U8*) (b->text + iCount * ENCODING_LENGTH), (U8*) & char_type);
            if ((char_type == AL) 
                || (char_type == AN) 
                || (char_type == BIDI_R)
                || (char_type == WS)
                || (char_type == NSM))
            {
                line_arabic_char_flag = MMI_TRUE;
                break;
            }
        }

        bidi_main_ext(
            b->text,
            (U16) num_char,
            bs->logical_cur_pos,
            g_editor_line.visual_str,
            &bs->visual_str_len,
            &bs->visual_cur_pos,
            g_editor_line.logic_to_visual_map,
            g_editor_line.visual_to_logic_map,
            0,
            MMI_bidi_input_type,
            0,
            /* (bs->default_direction == BIDI_L) ? P_LTR : P_RTL); */
            (bs->default_direction == BIDI_L) ? P_LTR : (line_arabic_char_flag ? P_RTL : P_LTR));

        bs->current_text_p = g_editor_line.visual_str;

        bs->current_cursor_p = bs->current_text_p + (bs->visual_cur_pos) * ENCODING_LENGTH;
        bs->previous_cursor_p =
            bs->current_text_p + g_editor_line.logic_to_visual_map[bs->logical_cur_pos >
                                                                   0 ? bs->logical_cur_pos - 1 : 0] * ENCODING_LENGTH;

        g_editor_line.bidi_done_flag = 1;
    }
}
#endif /* __MMI_BIDI_ALG__ */ 

#if defined(__MMI_ARSHAPING_ENGINE__) && defined(__MMI_BIDI_ALG__)
/*****************************************************************************
 * FUNCTION
 *  gui_translate_single_line_buffer_to_shaping
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     [?]
 *  bs      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_translate_single_line_buffer_to_shaping(single_line_input_box *b, single_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 text_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bs->arabic_char_flag && (b->text_length / ENCODING_LENGTH) != 0)
    {
        int i;

        mmi_ucs2ncpy((CHAR*) shaping_str, (const CHAR*)b->text, MAX_TEXT_LENGTH - 1);
        shaping_str[MAX_TEXT_LENGTH - 1] = 0;
        bs->backup_text = b->text;

        if (b->text_length < MAX_TEXT_LENGTH * ENCODING_LENGTH)
            unshaped_text_len = text_len = (b->text_length / 2) - 1;
        else
            unshaped_text_len = text_len = MAX_TEXT_LENGTH - 1;

        for (i = 0; i <= text_len; i++)
            OrgToSha[i] = i;

        ArabicShapeEngine2_ext((U16*) & text_len, (U16*) shaping_str, (U16*) OrgToSha, NULL);

        b->text = (UI_buffer_type) shaping_str;
        shaped_text_len = text_len;
        OrgToSha[unshaped_text_len] = shaped_text_len;
        OrgToSha[unshaped_text_len + 1] = shaped_text_len + 1;

        b->current_text_p = b->text + gui_multi_line_mapping_org_to_sha_forward((b->current_text_p - bs->backup_text) / 2) * 2;

        if ((b->flags & UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT) && b->highlight_start_position != NULL)
        {
            if (b->highlight_start_position - bs->backup_text > b->text_length)
                b->highlight_start_position = bs->backup_text + b->text_length;
            if (b->highlight_end_position - bs->backup_text > b->text_length)
                b->highlight_end_position = bs->backup_text + b->text_length;

            b->highlight_start_position = b->text
                + gui_multi_line_mapping_org_to_sha((b->highlight_start_position - bs->backup_text) / 2) * 2;
            b->highlight_end_position = b->text
                + gui_multi_line_mapping_org_to_sha((b->highlight_end_position - bs->backup_text) / 2) * 2;

            /* For shaping case, we should expand the highlight_end_psosition by ENCODING_LENGTH because the
               highlight information will be lost in smart input method */
            if (b->highlight_start_position == b->highlight_end_position)
            {
                b->highlight_end_position += ENCODING_LENGTH;
            }
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
        #endif

        b->last_position_p = b->text + (shaped_text_len + 1) * 2;       /* initialize */
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_retore_single_line_buffer_from_shaping
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_retore_single_line_buffer_from_shaping(single_line_input_box *b, single_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bs->arabic_char_flag && (b->text_length / ENCODING_LENGTH)!= 0)
    {
        b->text = bs->backup_text;

        if ((b->flags & UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT) && b->highlight_start_position != NULL)
        {
            b->highlight_start_position = b->text
                + gui_multi_line_mapping_sha_to_org((b->highlight_start_position - (UI_buffer_type) shaping_str) / 2) *
                2;
            b->highlight_end_position =
                b->text +
                gui_multi_line_mapping_sha_to_org((b->highlight_end_position - (UI_buffer_type) shaping_str) / 2) * 2;
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
        #endif
        b->current_text_p = b->text + gui_multi_line_mapping_sha_to_org((b->current_text_p - (UI_buffer_type) shaping_str) / 2) * 2;
        b->last_position_p =
            b->text + gui_multi_line_mapping_sha_to_org((b->last_position_p - (UI_buffer_type) shaping_str) / 2) * 2;
    }
}
#endif /* defined(__MMI_ARSHAPING_ENGINE__) && defined(__MMI_BIDI_ALG__) */ 


/*****************************************************************************
 * FUNCTION
 *  gui_draw_single_line_background
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_draw_single_line_background(single_line_input_box *b, single_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_filled_area *f;
    U8 border_type = 0;
    S32 border_width;/* slim_2_2 */ //
    gui_inputs_bg_mem_image_struct *bg_image = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MTK Leo end 1205 */
    if (bs->flags & UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED)
    {
        f = b->selected_filler;
        bg_image = b->selected_mem_bg_image;
    }
    else if (bs->flags & UI_SINGLE_LINE_INPUT_BOX_STATE_DISABLED)
    {
        f = b->disabled_filler;
    }
    else
    {
        f = b->normal_filler;
        bg_image = b->normal_mem_bg_image;
    }

#ifndef __MMI_FTE_SUPPORT__
    /* FTE will use fixed image to draw singleline background */
    if ((f->flags & UI_FILLED_AREA_DOUBLE_BORDER) == UI_FILLED_AREA_DOUBLE_BORDER)
    {
        bs->sy1 += 3;
        bs->sy2 -= 3;
        border_type = 2;
    }
    else if (f->flags & UI_FILLED_AREA_BORDER)
    {
        bs->sy1 += 2;
        bs->sy2 -= 2;
        border_type = 1;
    }
#endif /* __MMI_FTE_SUPPORT__ */

    gui_push_clip();
    if (bs->flags & UI_SINGLE_LINE_INPUT_BOX_NO_BORDER)
    {
        if (bs->flags & UI_SINGLE_LINE_INPUT_BOX_USE_PRESET_CLIPPING)
        {
            gui_inputs_set_clip_preset(bs->x1 + 1, bs->y1 + 1, bs->x2 - 1, bs->y2 - 1);
        }
        else
        {
            gui_set_clip(bs->x1 + 1, bs->y1 + 1, bs->x2 - 1, bs->y2 - 1);
        }
        if (border_type == 0)
        {
            bs->sy1 += 1;
            bs->sy2 -= 1;
        }
        border_type = 1;
    }
    else
    {
        if (bs->flags & UI_SINGLE_LINE_INPUT_BOX_USE_PRESET_CLIPPING)
        {
            gui_inputs_set_clip_preset(bs->x1, bs->y1, bs->x2 + 2, bs->y2 + 2);
        }
        else
        {
            gui_set_clip(bs->x1, bs->y1, bs->x2 + 2, bs->y2 + 2);
        }
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
    #endif

    if ((wgui_is_wallpaper_on_bottom() == MMI_TRUE) &&
        b->ext_flags & GUI_SINGLE_LINE_INPUT_BOX_TRANSPARENT_BACKGROUND)
    {
        gdi_draw_solid_rect(bs->x1, bs->y1, bs->x2, bs->y2, GDI_COLOR_TRANSPARENT);
    }
    else if (!(bs->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW) &&
        !(bs->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_BACKGROUND))
    {       
        if (b->ext_flags & GUI_SINGLE_LINE_INPUT_BOX_CUSTOM_STYLE_BACKGROUND)
        {
            /* custom style */
            if (bg_image)
            {
                /* image background */
                /* from memmory */
                gdi_image_draw_mem_blend2layers(
                    bs->x1,
                    bs->y1,
                    bg_image->data,
                    bg_image->type,
                    bg_image->len);
            }
            else if (f->b)
            { 
                /* from resource*/
                gdi_image_draw_resized_blend2layers(
                    bs->x1,
                    bs->y1,
                    b->width,
                    b->height,
                    f->b);
            }
            else
            {
                /* rectangle background */
                gui_draw_filled_area(bs->x1, bs->y1, bs->x2, bs->y2, f);
            }
        }
        else
        {
            /* native style */
#ifndef __MMI_FTE_SUPPORT__
            gui_draw_filled_area(bs->x1, bs->y1, bs->x2, bs->y2, f);
#else

#if defined(__MMI_VUI_ENGINE__)
            if (vadp_p2v_uc_is_in_venus())
            {
                gui_draw_filled_area(bs->x1, bs->y1, bs->x2, bs->y2, f);
            }
            else
#endif
            {
                UI_filled_area  *bg_filler; /* slim_2_2 */ //
                /* Redraw category background */
                if (g_inputs_background_filler)
                {
                    g_inputs_background_filler(bs->x1, bs->y1, bs->x2, bs->y2);
                }



                if ((bs->flags & UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED))
                {
                    bg_filler = current_MMI_theme->inline_item_textedit_highlighted_bg_filler;                    
                }
                else
                {
                    bg_filler = current_MMI_theme->inline_item_textedit_unhighlighted_bg_filler;
                }

                if (bg_filler)
                {
                    if (bg_filler->b)
                    {
                        gdi_image_draw_resized_blend2layers(
                            bs->x1,
                            bs->y1,
                            b->width,
                            b->height,
                            bg_filler->b);
                    }
                    else
                    {
                        gui_fill_rectangle(
                            bs->x1,
                            bs->y1,
                            bs->x1 + b->width - 1,
                            bs->y1 + b->height - 1,
                            bg_filler->c);
                    }
                }
                else
                {
                    gui_draw_filled_area(bs->x1, bs->y1, bs->x2, bs->y2, f);
                }
            }
#endif
        }
    }

    gui_push_text_clip();
    
    border_width = (S32)border_type;/* slim_2_2 */ //
    if (bs->flags & UI_SINGLE_LINE_INPUT_BOX_USE_PRESET_CLIPPING)
    {
        gui_set_text_clip_preset(bs->x1 + border_width, bs->y1, bs->x2 - border_width, bs->y2);
        gui_inputs_set_clip_preset(bs->x1 + border_width, bs->y1 + border_width, bs->x2 - border_width, bs->y2 - border_width);
    }
    else
    {
        gui_set_text_clip(bs->x1 + border_width, bs->y1, bs->x2 - border_width, bs->y2);
        gui_set_clip(bs->x1 + border_width, bs->y1 + border_width, bs->x2 - border_width, bs->y2 - border_width);
    }
    /* set text font */

    gui_set_font(b->text_font);
 
    bs->edit_width = (bs->x2 - bs->x1 - 6);

    if (bs->flags & UI_SINGLE_LINE_INPUT_BOX_FULL_HEIGHT_BLOCK_CURSOR)
    {
        bs->sy1 -= 1;
        bs->sy2 += 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_adjust_single_line_cursor_for_language
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     [?]
 *  bs      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_adjust_single_line_cursor_for_language(single_line_input_box *b, single_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_lm_cluster_info cur_cluster;
    UI_buffer_type pre_cluster_p;
    UI_buffer_type temp_cursor_p = b->current_text_p;
    UI_character_type temp_char;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_NEXT_CHARACTER(temp_cursor_p, temp_char);

    if ((b->text_length <= ENCODING_LENGTH) || (temp_char == 0) || (b->current_text_p == b->text))
    {
        return;
    }
    mmi_lm_get_prev_cluster(b->text, b->text + b->text_length - 2, b->current_text_p, MMI_TRUE, &cur_cluster);
    pre_cluster_p = cur_cluster.data_ptr;
    mmi_lm_get_next_cluster(b->text, b->text + b->text_length - 2, pre_cluster_p, MMI_TRUE, &cur_cluster);
    b->current_text_p = cur_cluster.data_ptr;
}


/* Singleline highlight is draw character by character and draw after character
   So for Indic language, the highlighter will cover previous character */
static MMI_BOOL g_is_first_highlight_char;


/*****************************************************************************
 * FUNCTION
 *  gui_draw_single_line_highlight
 * DESCRIPTION
 *  Draw singleline highlight
 * PARAMETERS
 *  b         [IN]
 *  bs        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_draw_single_line_highlight(single_line_input_box *b, single_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    S32 max_num = 0;
    UI_buffer_type saved_current_text_p;
    U8 highlight;
    S32 top_down_gap = 0;
    S32 old_text_x;
    UI_character_type current_character = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_text_x = bs->text_x;

    top_down_gap = b->margin.top_margin;
    
    if (!g_editor_line.bidi_done_flag)
    {
        max_num = (S32) mmi_ucs2strlen((CHAR*)b->text);
    }
#ifdef __MMI_BIDI_ALG__
    else
    {
        max_num = (S32) bs->visual_str_len;
    }
#endif /* __MMI_BIDI_ALG__ */ 

    mmi_lm_cluster_init(&bs->pre2_cluster);
    mmi_lm_cluster_init(&bs->pre_cluster);
    mmi_lm_cluster_init(&bs->cur_cluster);
    
    saved_current_text_p = bs->current_text_p;
    
    for (i = 0; i < max_num;)
    {
        /* parsing the text one by one */
        bs->cluster_type = gui_get_single_line_current_cluster(b, 
            bs, 
            &current_character, 
            &bs->pre2_cluster,
            &bs->pre_cluster,
            &bs->cur_cluster);

        // left gap for first character
        if (bs->cur_cluster.is_gap || (i == 0))
        {
            bs->text_x += bs->text_gap;
        }
    
        i += bs->cur_cluster.data_len;
        bs->character_width = bs->cur_cluster.adv_x;
#if defined(__MMI_LANG_THAI__)
        if (bs->cluster_type == THAI_CLUSTER)
        {
            if (b->current_text_p > bs->current_text_p
                && b->current_text_p < bs->current_text_p + bs->cur_cluster.data_len* ENCODING_LENGTH)
            {
                /* adjust the cursor position for THAI cluster */
                b->current_text_p = bs->current_text_p + bs->cur_cluster.data_len* ENCODING_LENGTH;
            }
        }
#endif

        if (bs->flags & UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR
            && !(bs->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW))
        {
#ifdef __MMI_EDITOR_SINGLELINE_SUPPORT_96_64_STYLE__
            if (bs->current_cursor_p == bs->current_text_p)
            {
                gui_fill_rectangle(
                    bs->x1 + bs->text_x+1,
                    bs->sy1 + 2,
                    bs->x1 + bs->text_x + bs->character_width ,
                    bs->sy2 - 2,
                    bs->selector_color);
            
                b->hilite_s_x = bs->x1 + bs->text_x+1;
                b->hilite_s_y = bs->sy1 + 2;
                b->hilite_e_x = bs->x1 + bs->text_x + bs->character_width ;
                b->hilite_e_y = bs->sy2 - 2;
                bs->word_highlight = 0;
                bs->text_x = old_text_x;
                bs->current_text_p = saved_current_text_p;
                return;
            }
#else /**/
            if (bs->current_cursor_p == bs->current_text_p)
            {
                gui_fill_rectangle(
                    bs->x1 + bs->text_x,
                    bs->sy1 + 1,
                    bs->x1 + bs->text_x + bs->character_width - 1,
                    bs->sy2 - 1,
                    bs->selector_color);

                b->hilite_s_x = bs->x1 + bs->text_x;
                b->hilite_s_y = bs->sy1 + 1;
                b->hilite_e_x = bs->x1 + bs->text_x + bs->character_width - 1;
                b->hilite_e_y = bs->sy2 - 1;
                bs->word_highlight = 0;
                bs->text_x = old_text_x;
                bs->current_text_p = saved_current_text_p;
                return;
            }
#endif      
        }
        
        highlight = gui_check_single_line_character_highlight(b, bs);
        
        if (highlight)
        {
            #if 0  /* slim_2_2 */ //            
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
            if (bs->cur_cluster.is_gap || g_is_first_highlight_char)
            {
                gui_fill_rectangle(
                    bs->x1 + bs->text_x,
                    bs->sy1 + top_down_gap,
                    bs->x1 + bs->text_x + bs->character_width,
                    bs->sy2 - top_down_gap,
                    bs->selector_color);
                
                g_is_first_highlight_char = MMI_FALSE;
            }
            else
            {
                gui_fill_rectangle(
                    bs->x1 + bs->text_x + 1, /* +1 for indic character overlap */
                    bs->sy1 + top_down_gap,
                    bs->x1 + bs->text_x + bs->character_width,
                    bs->sy2 - top_down_gap,
                    bs->selector_color);
            }
            
            if (b->hilite_s_x == 0 && b->hilite_s_y == 0)
            {
                b->hilite_s_x = bs->x1 + bs->text_x;
                b->hilite_s_y = bs->sy1 + top_down_gap;
            }
            b->hilite_e_x = bs->x1 + bs->text_x + bs->character_width - 1;
            b->hilite_e_y = bs->sy1 + top_down_gap;
        }

        bs->text_x += bs->character_width;
        bs->current_text_p += bs->cur_cluster.data_len * ENCODING_LENGTH;
        bs->pre2_cluster = bs->pre_cluster;
        bs->pre_cluster = bs->cur_cluster;
    }

    bs->word_highlight = 0;
    bs->text_x = old_text_x;
    bs->current_text_p = saved_current_text_p;
}


/*****************************************************************************
 * FUNCTION
 *  gui_draw_single_line_one_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_draw_single_line_one_line(single_line_input_box *b, single_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 box_width, current_text_width, text_height, cx;
    S32 total_width = 0, max_num = 0, i;
    UI_character_type current_character = 0;
    mmi_fe_get_string_info_param_struct query;
    UI_character_type ch = 0x31;
    UI_buffer_type saved_current_text_p;
    UI_string_type default_text = NULL;
    S32 def_text_width, def_text_height;    
    S32 left_gap, right_gap;
    S32 ch_width, ch_height;
    S32 truncate_width, truncate_height;
    S32 text_height_simply, text_ascent_simply, text_descent_simply;
    S32 temp_text_y, real_text_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    left_gap = b->left_width + b->margin.left_margin;
    right_gap = b->right_width + b->margin.right_margin;

    g_is_first_highlight_char = MMI_TRUE;

    box_width = bs->edit_width;

    if (bs->flags & UI_SINGLE_LINE_INPUT_BOX_TRUNCATE_CONTENT)
        bs->text_gap = 0;
    
    Get_StringWidthHeight_n((U8*)INPUTBOX_TRUNCATE_STRING, INPUTBOX_TRUNCATE_DOT_NUM, &truncate_width, &truncate_height);

#if 0 //def __MMI_BIDI_ALG__
/* under construction !*/
/* under construction !*/
#endif

    if (!g_editor_line.bidi_done_flag)
    {
        max_num = (S32) mmi_ucs2strlen((CHAR*)b->text);
    }
#ifdef __MMI_BIDI_ALG__
    else
    {
        max_num = (S32) bs->visual_str_len;
    }
#endif /* __MMI_BIDI_ALG__ */ 

    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    query.String = (U8*)bs->current_text_p;
    query.n = mmi_ucs2strlen((const char*)bs->current_text_p);
    query.enableTruncated = MMI_FALSE;
    query.w = bs->text_gap;
    mmi_fe_get_string_widthheight(&query);

    /* For right alignment style, we don't use font engine API to caculate the width */
	if (bs->flags & UI_SINGLE_LINE_INPUT_BOX_RIGHT_JUSTIFY || (bs->default_direction == BIDI_R))
    {
    	mmi_lm_cluster_init(&bs->pre2_cluster);
	    mmi_lm_cluster_init(&bs->pre_cluster);
	    mmi_lm_cluster_init(&bs->cur_cluster);

        saved_current_text_p = bs->current_text_p;

        for (i = 0; i < max_num;)
	    {
	        /* parsing the text one by one */
	        bs->cluster_type = gui_get_single_line_current_cluster(b, 
	            bs, 
	            &current_character, 
	            &bs->pre2_cluster,
	            &bs->pre_cluster,
	            &bs->cur_cluster);
	        
	        i += bs->cur_cluster.data_len;
	        bs->character_width = bs->cur_cluster.adv_x;
        #if defined(__MMI_LANG_THAI__)
	        if (bs->cluster_type == THAI_CLUSTER)
	        {
	            if (b->current_text_p > bs->current_text_p
	                && b->current_text_p < bs->current_text_p + bs->cur_cluster.data_len* ENCODING_LENGTH)
	            {
	                /* adjust the cursor position for THAI cluster */
	                b->current_text_p = bs->current_text_p + bs->cur_cluster.data_len* ENCODING_LENGTH;
	            }
	        }
		#endif

            if (bs->cur_cluster.is_gap)
            {
                total_width += bs->text_gap;
            }

            total_width += bs->character_width;

	        bs->current_text_p += bs->cur_cluster.data_len * ENCODING_LENGTH;
	        bs->pre2_cluster = bs->pre_cluster;
	        bs->pre_cluster = bs->cur_cluster;
	    }
        current_text_width = total_width;
        /* Need to Restore for draw loop */
        total_width = 0;
		bs->current_text_p = saved_current_text_p;
    }
    else
    {
    	current_text_width = (query.pWidth > query.adv_w ? query.pWidth : query.adv_w);
    }

    /* Use mark character to query metrics */
    if (bs->flags & UI_SINGLE_LINE_INPUT_BOX_MASK_CHARACTERS)
    {
        memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
        query.String = (U8*)&b->mask_character;
        query.n = 1;
        query.enableTruncated = MMI_FALSE;
        query.w = bs->text_gap;
        mmi_fe_get_string_widthheight(&query);
    }
    else
    {
        Get_CharWidthHeight(ch, &ch_width, &ch_height);
        if (query.pHeight < ch_height)
        {
            memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
            query.String = (U8*)&ch;
            query.n = 1;
            query.enableTruncated = MMI_FALSE;
            query.w = bs->text_gap;
            mmi_fe_get_string_widthheight(&query);
        }
    }

    /* save text_y for default_text show */
    real_text_y = (b->height - query.pHeight) >> 1;
    if (real_text_y == 0)
    {
        real_text_y = 1;
    }

    /* get simply language's height/base_line*/
    mmi_fe_get_char_info_of_simply_lang(b->text_font->size, &text_height_simply, &(text_ascent_simply), &text_descent_simply); 
    
    if(query.pHeight <= text_height_simply && query.maxAscent <= text_ascent_simply)
    {
        /* use simply language's height/base_line to avoid text jumps up and down */
        text_height = text_height_simply;
        bs->base_line = text_ascent_simply;
    }
    else
    {
        /* use max height/base_line of current string to avoid shown out of the border */
        text_height = query.pHeight;
        bs->base_line = query.baseline;
    }    
    
    temp_text_y = b->height - text_height;
    /* odd, one pixel down */
    bs->text_y = (temp_text_y >> 1) + (temp_text_y & 1);    
    if (bs->text_y == 0)
    {
        bs->text_y = 1;
    }
    b->text_y = bs->text_y;

#ifdef __MMI_FTE_SUPPORT__
    if (bs->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_BACKGROUND)
    {
        /* For datatime/IP... controls */
        b->text_x = GUI_SINGLE_LINE_LEFT_TEXT_MARGIN_NO_BG + b->text_gap;
    }
#endif

    /* MTK added by Elvis and Manju */
    if (bs->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW)
    {
        /* MTK Elvis for R2L characters */
        if (bs->default_direction == BIDI_L)
        {
            bs->text_x = b->text_x + b->left_width;
        }
#ifdef __MMI_BIDI_ALG__/**/
        else
        {
            bs->text_x = box_width - current_text_width - b->margin.right_margin;
        }
#endif /*__MMI_BIDI_ALG__*/           
    }
    else
    {
        /* MTK Elvis for R2L characters */
        if (bs->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_SCROLLING)
        {
            if (bs->default_direction == BIDI_L)
            {
                bs->text_x = b->text_x;
            }
#ifdef __MMI_BIDI_ALG__/**/
            else
            {
                bs->text_x = box_width - current_text_width - b->margin.right_margin;
            }
#endif /*__MMI_BIDI_ALG__*/                
        }
        else
        {
            if (bs->default_direction == BIDI_L)
            {
                bs->text_x = b->text_x + b->text_offset_x + b->left_width;
            }
#ifdef __MMI_BIDI_ALG__/**/
            else
            {
                bs->text_x = box_width - b->text_offset_x - current_text_width - b->margin.right_margin;
            }
#endif /*__MMI_BIDI_ALG__*/           
        }

    }

    if (current_text_width <= box_width)
    {
        if (bs->flags & UI_SINGLE_LINE_INPUT_BOX_CENTER_JUSTIFY)
        {
            bs->text_x = (b->width >> 1) - (current_text_width >> 1);
        }
        else if (bs->flags & UI_SINGLE_LINE_INPUT_BOX_RIGHT_JUSTIFY)
        {
            bs->text_x = (box_width - current_text_width - b->right_width + 4 - b->margin.right_margin);
        }
    }

    if ((bs->flags & UI_SINGLE_LINE_INPUT_BOX_RIGHT_JUSTIFY) && (bs->text_x + current_text_width) < box_width)
    {
        bs->text_x = box_width - current_text_width - b->right_width + 4 - b->margin.right_margin;
    }

    /* set the last_position_p */
    if (max_num)
        b->last_position_p = b->text + (max_num + 1) * ENCODING_LENGTH;
    else
        b->last_position_p = b->text;

    mmi_lm_cluster_init(&bs->pre2_cluster);
    mmi_lm_cluster_init(&bs->pre_cluster);
    mmi_lm_cluster_init(&bs->cur_cluster);

    if (max_num == 0)
    {
        bs->cluster_type = gui_get_single_line_current_cluster(b, 
            bs, 
            &current_character, 
            &bs->pre2_cluster,
            &bs->pre_cluster,
            &bs->cur_cluster);
        bs->text_x += bs->text_gap;

        if (!(bs->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW))
        {
            if (b->default_text)
            {
                default_text = b->default_text;
            }
            if( (default_text != NULL)&&(bs->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW))
            {
                #ifdef __MMI_FTE_SUPPORT__
                    gui_set_text_color(*(current_MMI_theme->inputbox_default_text_color));
		#else
                    gui_set_text_color(gui_color(160, 160, 160));
                #endif /* __MMI_FTE_SUPPORT__ */
               
                bs->text_y = real_text_y;

                Get_StringWidthHeight((PU8)default_text, &def_text_width, &def_text_height);

                if ((mmi_fe_get_r2l_state() && bs->default_direction == BIDI_R)
                     ||( !mmi_fe_get_r2l_state() && bs->default_direction == BIDI_L))
                {
                    /* editor direction is equal to the system setting */
                    mmi_fe_show_string_n_baseline(bs->x1 + bs->text_x,
                        bs->y1 + bs->text_y,
                        (PU8)default_text,
                        mmi_ucs2strlen(( PS8)default_text),
                        bs->base_line);
                }
                else if (mmi_fe_get_r2l_state() && bs->default_direction == BIDI_L)
                {
                    mmi_fe_show_string_n_baseline(bs->x1 + bs->text_x + def_text_width,
                        bs->y1 + bs->text_y,
                        (PU8)default_text,
                        mmi_ucs2strlen(( PS8)default_text),
                        bs->base_line);
                }
                else
                {
                    mmi_fe_show_string_n_baseline(bs->x1 + bs->text_x - def_text_width,
                        bs->y1 + bs->text_y,
                        (PU8)default_text,
                        mmi_ucs2strlen(( PS8)default_text),
                        bs->base_line);
                }              
                
            }
        }

        gui_handle_single_line_cursor(b, bs, 1);
        return;
    }

    /* Draw single line editor highlight */
    if (!(bs->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW))
    {
        gui_draw_single_line_highlight(b, bs);
    }

    for (i = 0; i < max_num;)
    {
        /* parsing the text one by one */
        bs->cluster_type = gui_get_single_line_current_cluster(b, 
            bs, 
            &current_character, 
            &bs->pre2_cluster,
            &bs->pre_cluster,
            &bs->cur_cluster);
        
        i += bs->cur_cluster.data_len;
        bs->character_width = bs->cur_cluster.adv_x;
        bs->character_height = bs->cur_cluster.h;
        
#if defined(__MMI_LANG_THAI__)
        if (bs->cluster_type == THAI_CLUSTER)
        {
            if (b->current_text_p > bs->current_text_p
                && b->current_text_p < bs->current_text_p + bs->cur_cluster.data_len* ENCODING_LENGTH)
            {
                /* adjust the cursor position for THAI cluster */
                b->current_text_p = bs->current_text_p + bs->cur_cluster.data_len* ENCODING_LENGTH;
            }
        }
#endif

        // left gap for first character
        if (bs->cur_cluster.is_gap || ((i - bs->cur_cluster.data_len) == 0))
        {
            bs->text_x += bs->text_gap;
            total_width += bs->text_gap;
        }

        if (!(bs->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW))
        {
            /* get character color */
            gui_get_single_line_character_color(b, bs);

            /* draw the current text */
            cx = bs->x1 + bs->text_x;

            if ((bs->flags & UI_SINGLE_LINE_INPUT_BOX_TRUNCATE_CONTENT) 
                && (current_text_width > (box_width - b->left_width - b->margin.left_margin - b->right_width - b->margin.right_margin))
                && ((cx >= (bs->x1 + left_gap)) 
                && (cx + bs->character_width + truncate_width) >= (bs->x2 - right_gap)))
            {
                FONT_CANCEL_WIDTH(1);
                ShowString_n_baseline(cx, bs->y1 + bs->text_y, *UI_font, 0, (U8*)INPUTBOX_TRUNCATE_STRING, INPUTBOX_TRUNCATE_DOT_NUM, bs->base_line);
                FONT_CANCEL_WIDTH(0);
                break;
            }

            if ((bs->flags & UI_SINGLE_LINE_INPUT_BOX_TRUNCATE_CONTENT_NO_BRIEF)
                && ((cx >= bs->x1 + left_gap) && (cx + bs->character_width) >= bs->x2 - right_gap)
                && !(bs->flags & UI_SINGLE_LINE_INPUT_BOX_RIGHT_JUSTIFY))
            {
                FONT_CANCEL_WIDTH(1);
                gui_set_text_color(bs->text_color);
                ShowString_n_baseline(cx, bs->y1 + bs->text_y, *UI_font, 0, (U8*)(L" "), 1, bs->base_line);
                FONT_CANCEL_WIDTH(0);
                break;
            }

            if (((bs->flags & UI_SINGLE_LINE_INPUT_BOX_VIEW_FULL_CHARACTERS)
                 && ((cx >= (bs->x1 + left_gap)) && ((cx + bs->character_width) <= (bs->x2 - right_gap))))
                || (!(bs->flags & UI_SINGLE_LINE_INPUT_BOX_VIEW_FULL_CHARACTERS)
                    && ((cx + bs->character_width) >= (bs->x1 + left_gap) && (cx <= (bs->x2- right_gap)))))
            {
                gui_move_text_cursor(cx, bs->y1 + bs->text_y);

                gui_set_text_color(bs->text_color);

                gui_draw_single_line_character(b, bs, current_character);

            }
        }

        gui_handle_single_line_cursor(b, bs, (U8) (i == max_num));

        bs->text_x += bs->character_width;
        total_width += bs->character_width;

        bs->current_text_p += bs->cur_cluster.data_len * ENCODING_LENGTH;
        bs->pre2_cluster = bs->pre_cluster;
        bs->pre_cluster = bs->cur_cluster;
    }

    b->text_width = total_width;
}


/*****************************************************************************
 * FUNCTION
 *  gui_get_single_line_current_cluster
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                       [?]     [?]
 *  bs                      [?]     [?]
 *  current_character_p     [?]     [?]
 *  cluster_count_p         [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_get_single_line_current_cluster(
    single_line_input_box *b,
    single_line_input_box_show_struct *bs,
    UI_character_type *current_character_p,
    mmi_lm_cluster_info_p pre2_cl,
    mmi_lm_cluster_info_p pre_cl,
    mmi_lm_cluster_info_p cur_cl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 rtn;
    UI_character_type current_character;
    UI_buffer_type text_p = bs->current_text_p, text_end_p;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_NEXT_CHARACTER(text_p, current_character);

    if (bs->flags & UI_SINGLE_LINE_INPUT_BOX_MASK_CHARACTERS
        && !UI_STRING_END_OF_STRING_CHARACTER(current_character))
    {
        /* if this is a mask style, we will not find any cluster */
        if (!((bs->flags & UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP) && (bs->current_text_p == bs->previous_cursor_p)))
        {
            text_p = &b->mask_character;
            current_character = b->mask_character;
            rtn = MASK_CHAR;
        }
        else
        {
            text_p = bs->current_text_p; 
            rtn = SINGLE_CHAR;
        }

        /* mask style, so always draw single character */
        text_end_p = text_p + ENCODING_LENGTH;

        mmi_lm_cluster_init(cur_cl);
        mmi_lm_get_current_cluster(text_p, text_end_p, pre2_cl, pre_cl, cur_cl);    

        if (rtn == MASK_CHAR)
        {
            cur_cl->data_ptr = bs->current_text_p;
        }
        
        *current_character_p = current_character;
        return rtn;
    }
    else
    {
        text_p = bs->current_text_p;
        text_end_p = (UI_buffer_type)(b->text + b->text_length);
        
        mmi_lm_cluster_init(cur_cl);
        mmi_lm_get_current_cluster(text_p, text_end_p, pre2_cl, pre_cl, cur_cl);
        *current_character_p = current_character;
        return gui_get_char_type_by_lm_lang((mmi_lm_lang_enum)(cur_cl->lang_id));
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_check_single_line_character_highlight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     [?]
 *  bs      [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
S32 gui_check_single_line_character_highlight(single_line_input_box *b, single_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 highlight = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((bs->flags & UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT) && b->highlight_start_position != NULL)
    {
        if (!g_editor_line.bidi_done_flag)
        {
            /* this is a normal line */
            if ((bs->current_text_p == b->highlight_start_position) || 
                (!bs->word_highlight && (bs->current_text_p < b->highlight_start_position) &&
                (bs->current_text_p + bs->cur_cluster.data_len * ENCODING_LENGTH > b->highlight_start_position)))
            {
                bs->word_highlight = 1;
            }

            if ((bs->current_text_p == b->highlight_end_position) ||
                     (bs->word_highlight && (bs->current_text_p > b->highlight_end_position)))
            {
                bs->word_highlight = 0;
            }
        }
    #ifdef __MMI_BIDI_ALG__
        else
        {
            /* this is a line after bidi alg */
            UI_buffer_type current_logic_text_p = b->text;

            current_logic_text_p +=
                (g_editor_line.visual_to_logic_map[(bs->current_text_p - g_editor_line.visual_str) / ENCODING_LENGTH]) *
                ENCODING_LENGTH;

            /* If cluster is formed with prev character when smart input method */
            if ((current_logic_text_p >= b->highlight_start_position) ||
                ((current_logic_text_p < b->highlight_start_position) &&
                 (current_logic_text_p + bs->cur_cluster.data_len * ENCODING_LENGTH > b->highlight_start_position)))
            {
                bs->word_highlight = 1;
            }
            else
            {
                bs->word_highlight = 0;
            }

            if ((current_logic_text_p >= b->highlight_end_position)
                || (bs->current_text_p - g_editor_line.visual_str) / ENCODING_LENGTH >= bs->visual_str_len)
            {
                bs->word_highlight = 0;
            }
        }
    #endif /* __MMI_BIDI_ALG__ */ 
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
    #ifdef __MMI_BIDI_ALG__
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
    #endif /* __MMI_BIDI_ALG__ */ 
/* under construction !*/
    #endif

    if (bs->word_highlight)
    {
        highlight = bs->word_highlight;
    }
    else if ((bs->multitap_flag
              && (bs->current_text_p <= bs->previous_cursor_p)
              && (bs->previous_cursor_p < bs->current_text_p + bs->cur_cluster.data_len * ENCODING_LENGTH)))
    {
        highlight = 3;
    }
    else if (bs->current_text_p == bs->current_cursor_p)
    {
        if (bs->overwrite_flag && !bs->multitap_flag && !(bs->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW))
        {
            highlight = 4;
        }
    }
   /* This logic ensures that the characters entered by multitap mode are highlighted 
    * The logic works by looking that the character is in between the input mode start
    * and cursor position and highlight the characters.
    */
    if (bs->multitap_flag)
    {
#if defined(__MMI_ARSHAPING_ENGINE__) && defined(__MMI_BIDI_ALG__)
		if (bs->arabic_char_flag && (b->text_length / ENCODING_LENGTH) != 0)
		{
			/* shaping applied */
			UI_buffer_type original_p;

			original_p = bs->current_text_p - (UI_buffer_type)shaping_str + bs->backup_text;

			if(original_p + bs->cur_cluster.data_len * ENCODING_LENGTH  > b->input_start_cursor_p &&
                bs->current_text_p + bs->cur_cluster.data_len * ENCODING_LENGTH <= b->current_text_p &&
                b->input_start_cursor_p != NULL)
            highlight = 3;
		}
		else
#endif
		{
			if(bs->current_text_p + bs->cur_cluster.data_len * ENCODING_LENGTH  > b->input_start_cursor_p &&
                bs->current_text_p + bs->cur_cluster.data_len * ENCODING_LENGTH <= b->current_text_p &&
                b->input_start_cursor_p != NULL)
				highlight = 3;
		}
    }

    return highlight;
}


/*****************************************************************************
 * FUNCTION
 *  gui_get_single_line_character_color
 * DESCRIPTION
 *  get text color for each character 
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_get_single_line_character_color(single_line_input_box *b, single_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 highlight;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bs->text_color = b->normal_text_color;
    
    if (bs->flags & UI_SINGLE_LINE_INPUT_BOX_STATE_DISABLED && bs->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW )
    {
        /* for baidu/google search, when disable editor, text color turn grey */
        bs->text_color = gui_color(160, 160, 160);
        return;
    }

    if (bs->flags & UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR
        && !(bs->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW))
    {
        if (bs->current_cursor_p == bs->current_text_p)
        {
            bs->text_color = bs->selected_text_color;
            return;
        }
    }

    highlight = gui_check_single_line_character_highlight(b, bs);
    if (highlight)
    {
        /* if highlight, change text color to selected text color */
        bs->text_color = bs->selected_text_color;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_draw_single_line_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                       [?]         
 *  bs                      [?]         
 *  current_character       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_draw_single_line_character(
        single_line_input_box *b,
        single_line_input_box_show_struct *bs,
        UI_character_type current_character)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_lm_show_cluster_param lm_show_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lm_show_param.cluster= &bs->cur_cluster;
    lm_show_param.prev_cluster = &bs->pre_cluster;
    lm_show_param.x = UI_text_x;
    lm_show_param.y = UI_text_y;
    lm_show_param.bordered = 0;
    lm_show_param.baseline = bs->base_line;

    switch (bs->cluster_type)
    {
        case SINGLE_CHAR:
        {
            if (bs->flags & UI_SINGLE_LINE_INPUT_BOX_MASK_CHARACTERS)
            {
                if ((bs->flags & UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP)
                    && (bs->current_text_p == bs->previous_cursor_p))
                {

                    mmi_lm_draw_cluster(&lm_show_param);

                }
                else
                {
                    gui_print_character(b->mask_character);
                }
            }
            else
            {
                mmi_lm_draw_cluster(&lm_show_param);
            }
        }
            break;

        default:
        {
            mmi_lm_draw_cluster(&lm_show_param);
        }
            break;

    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_handle_single_line_cursor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                   [?]         
 *  bs                  [?]         
 *  last_one_flag       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_handle_single_line_cursor(single_line_input_box *b, single_line_input_box_show_struct *bs, U8 last_one_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, num;
    S32 cy, ch;
    U8 show_cursor = 0;
#ifdef __MMI_BIDI_ALG__
    U16 visual_index, logic_index = 0;
#endif
    UI_buffer_type cursor_p = b->text;
    UI_buffer_type current_text_p = bs->current_text_p, temp_text_p = bs->current_text_p;
    UI_character_type current_character = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cy = bs->sy1 + b->margin.top_margin;
    ch = bs->sy2 - bs->sy1 - 2 * b->margin.top_margin + 1;
    
    UI_STRING_GET_NEXT_CHARACTER(temp_text_p, current_character);

    if (bs->find_new_cursor_flag == FINDING_CURSOR)
    {
        /* we need to find the cursor_p */
        num = mmi_ucs2strlen((const CHAR*)b->text);

        if (!g_editor_line.bidi_done_flag)
        {
            cursor_p = bs->current_text_p;
        }
    #ifdef __MMI_BIDI_ALG__
        else
        {
            visual_index = (bs->current_text_p - g_editor_line.visual_str) / ENCODING_LENGTH;
            if (visual_index < bs->visual_str_len)
                logic_index = g_editor_line.visual_to_logic_map[visual_index];
            cursor_p = b->text + logic_index * ENCODING_LENGTH;
        }
    #endif /* __MMI_BIDI_ALG__ */ 

        x = bs->move_to_x;

        if ((bs->x1 + bs->text_x + b->text_offset_x + bs->character_width >= x) &&
            (bs->default_direction == BIDI_L))
        {
            b->current_text_p = cursor_p;
            bs->find_new_cursor_flag = FOUND_CURSOR;
        }
#ifdef __MMI_BIDI_ALG__/**/        
        else if ((bs->x1 + bs->text_x - b->text_offset_x + bs->character_width >= x) &&
                 (bs->default_direction == BIDI_R))
        {
            if ((bs->x1 + bs->text_x) >= x)
            {
                /* pen down before the first character (the white space area), 
                   like pen down on x area,  -> |        x    abc|
                   so set the cursor to the end of the text (before a |            |abc|) */
                b->current_text_p = b->text + num * ENCODING_LENGTH;
            }
            else
            {
                b->current_text_p = cursor_p;
            }
            bs->find_new_cursor_flag = FOUND_CURSOR;
        }
#endif /*__MMI_BIDI_ALG__*/        
        else if (last_one_flag)
        {
            /* if (!g_editor_line.bidi_done_flag) */
            if (bs->default_direction == BIDI_L)
            {
                b->current_text_p = b->text + num * ENCODING_LENGTH;
            }
#ifdef __MMI_BIDI_ALG__/**/          
            else
                b->current_text_p = b->text;
#endif /*__MMI_BIDI_ALG__*/  

            bs->find_new_cursor_flag = FOUND_CURSOR;
        }
    }
    else if (bs->find_new_cursor_flag == NORMAL_CURSOR)
    {
        /* the normal case , attemp to draw the cursor */
        if (current_text_p == bs->current_cursor_p)
        {
            show_cursor = 1;
        }
        else if (last_one_flag && bs->current_cursor_p >= current_text_p + ENCODING_LENGTH)
        {
            show_cursor = 2;
        }

        if (show_cursor)
        {
            if (show_cursor == 1)
            {
                x = bs->x1 + bs->text_x;
            }
            else
                x = bs->x1 + bs->text_x + bs->character_width;

            if (!(bs->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW)
                && !(bs->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW)
                && !(bs->flags & UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR)
                && !(bs->flags & UI_SINGLE_LINE_INPUT_BOX_FULL_HEIGHT_BLOCK_CURSOR)
                && !(bs->flags & UI_SINGLE_LINE_INPUT_BOX_CHARACTER_HIGHLIGHT))
            {
                gui_single_line_input_box_show_cursor(b, x, cy, ch);
            }

            b->cursor_x = x - bs->x1;
        }

    }

    UI_UNUSED_PARAMETER(current_character);
}


