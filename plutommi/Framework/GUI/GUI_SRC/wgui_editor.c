/*******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
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
*******************************************************************************/

/*******************************************************************************
* Filename:
* ---------
*  wgui_editor.c
*
* Project:
* --------
*  Maui_Software
*
* Description:
* ------------
*  Editor APIs for MRE APP
*
* Author:
* -------
 * -------
*
*------------------------------------------------------------------------------
* $Log$
 *
 * 02 22 2013 ye.tian
 * removed!
 * updata IMG_INLINE_ML_HIGHLIGHT_BG and IMG_INLINE_ML_NORMAL_BG  image data .
 *
 * 02 04 2013 ye.tian
 * removed!
 * - in wgui_editor_set_fit_text_font ,change code to avoid U8 size ,from  0 to 255 .
 *
 * 01 31 2013 ye.tian
 * removed!
 * update  to remove no used image.
 *
 * 01 18 2013 ye.tian
 * removed!
 * -  fix build warning.
 *
 * 12 25 2012 ye.tian
 * removed!
 * - patch back pluto slim to 11B step 2.
* 
* 09 24 2012 liu.cheng
 * removed!
* .
 *
 * 09 20 2012 ye.tian
 * removed!
 * - add smart input method flag when  editor handle msg: MMI_IMC_MESSAGE_GET_STRING_BEFORE_CANDIDATE,
 *         avoid clipboard state doing [editor_ptr->cursor_p = editor_ptr->highlight_start_position],it just for smart
 *         input method.
* 
* 09 20 2012 liu.cheng
 * removed!
* .
* 
* 09 05 2012 liu.cheng
 * removed!
* .
* 
* 09 03 2012 liu.cheng
 * removed!
* .
* 
* 08 23 2012 liu.cheng
 * removed!
* .
* 
* 07 27 2012 liu.cheng
 * removed!
* process key for qwerty key pad.
 *
 * 07 18 2012 liu.cheng
 * removed!
 * .
 *
 * 07 14 2012 hongtao.liu
 * removed!
 * add API : vm_editor_show_from_first_line
 *
 * 07 13 2012 liu.cheng
 * removed!
 * .
 *
 * 06 27 2012 liu.cheng
 * removed!
 * .
 *
 * 06 14 2012 liu.cheng
 * removed!
 * .
 *
 * 06 07 2012 liu.cheng
 * removed!
 * .
 *
 * 06 04 2012 liu.cheng
 * removed!
 * Fix build error.
 *
 * 06 04 2012 liu.cheng
 * removed!
 * Add update text callback with cursor rect.
 *
 * 05 31 2012 liu.cheng
 * removed!
 * Fix issue. Deactive editor, there is no rsk/lsk, but pressing key_rsk/lsk, shows abnormal.
 *
 * 05 23 2012 liu.cheng
 * removed!
 * .
 *
 * 05 21 2012 liu.cheng
 * removed!
 * fix issue, reset history to null after using history to active.
 *
 * 04 26 2012 liu.cheng
 * removed!
 * cosmos background image, and fix some bug.
 *
 * 04 24 2012 liu.cheng
 * removed!
 * .
 *
 * 04 18 2012 liu.cheng
 * removed!
 * .
 *
 * 04 06 2012 liu.cheng
 * removed!
 * .
 *
 * 04 01 2012 liu.cheng
 * removed!
 * fix some ui bug
 *
 * 03 31 2012 liu.cheng
 * removed!
 * .
 *
 * 03 31 2012 liu.cheng
 * removed!
 * .
 *
 * 03 30 2012 liu.cheng
 * removed!
 * .
 *
 * 03 27 2012 liu.cheng
 * removed!
 * .
 *
 * 03 26 2012 liu.cheng
 * removed!
 * .
 *
 * 03 09 2012 liu.cheng
 * removed!
 * .
 *
 * 03 08 2012 liu.cheng
 * removed!
 * .
 *
 * 03 08 2012 liu.cheng
 * removed!
 * .
 *
 * 03 05 2012 liu.cheng
 * removed!
 * .
 *
 * 03 05 2012 liu.cheng
 * removed!
 * .
 *
 * 03 02 2012 liu.cheng
 * removed!
 * .
 *
 * 02 17 2012 liu.cheng
 * removed!
 * .
 *
 * 02 13 2012 liu.cheng
 * removed!
 * .
 *
 * 02 06 2012 liu.cheng
 * removed!
 * .
 *
 * 02 06 2012 liu.cheng
 * removed!
 * .
 *
 * 02 03 2012 liu.cheng
 * removed!
 * .
 *
 * 01 11 2012 liu.cheng
 * removed!
 * .
 *
 * 01 11 2012 liu.cheng
 * removed!
 * .
 *
 * 01 10 2012 liu.cheng
 * removed!
 * .
 *
 * 01 10 2012 liu.cheng
 * removed!
 * .
 *
 * 01 09 2012 liu.cheng
 * removed!
 * .
*
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================
*******************************************************************************/

#include "wgui_editor.h"
#include "gui_inputs.h"
#include "gui_touch_feedback.h"
#include "wgui_include.h"
#include "GlobalResDef.h"
#include "wgui_softkeys.h"
#include "wgui_categories_util.h"
#include "mmi_rp_app_uiframework_def.h"
#include "Gui.h"
#include "Gsm7BitNationalLang.h"
#include "wgui_categories_inputs.h"
#ifdef __COSMOS_MMI_PACKAGE__
#include "mmi_rp_srv_venus_component_text_view_def.h"
#endif


#include "Imc.h"


#define WGUI_EDITOR_LEFT_RIGHT_MARGIN_IMAGE_BG              7
#define WGUI_EDITOR_LEFT_RIGHT_MARGIN_RECT_BG               2
#define WGUI_EDITOR_MULTILINE_TOP_DOWN_MARGIN_IMAGE_BG      12
#define WGUI_EDITOR_MULTILINE_TOP_DOWN_MARGIN_RECT_BG       2

static U32 wgui_editor_msg_call_back_adaptor(void * input_box_handle, mmi_imc_message_struct_p msg_ptr);
static U32 wgui_editor_msg_call_back_single_line(void * input_box_handle, mmi_imc_message_struct_p msg_ptr);
static U32 wgui_editor_msg_call_back_multi_line(void * input_box_handle, mmi_imc_message_struct_p msg_ptr);
static MMI_BOOL wgui_editor_previous_character(void);
static MMI_BOOL wgui_editor_next_character(void);
static MMI_BOOL wgui_editor_previous_line(void);
static MMI_BOOL wgui_editor_next_line(void);
static void wgui_editor_handle_right_softkey(void);
static void wgui_editor_handle_input(void);
static void wgui_editor_redraw_active_editor(void);
static void wgui_editor_update_text_callback(UI_buffer_type text, UI_buffer_type cursor, S32 text_length);
static void wgui_editor_update_text_with_cursor_rect_callback(void);
static void wgui_editor_redraw_softkey(void);

extern void mmi_imc_draw_indicator_floating(MMI_BOOL);

extern mmi_editor_handler_struct g_mmi_editor_hanler;

static wgui_editor_struct *g_current_active_editor;
static S32 imui_height = 0;
static U8 close_flag = 0;
static MMI_BOOL ime_floating_indicator_flag = MMI_TRUE;

static void (*wgui_editor_draw_imui_background_funcptr)(S32 x1, S32 y1, S32 x2, S32 y2); 

/*****************************************************************************
* FUNCTION
*  wgui_editor_get_memory_size
* DESCRIPTION
*  Get memory size of an editor instance
* PARAMETERS
*  editor_type     [IN]        Is the editor type
* RETURNS
*  U32: memory size of an editor instance
*****************************************************************************/
U32 wgui_editor_get_memory_size(WGUI_EDITOR_TYPE editor_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (editor_type == WGUI_EDITOR_SINGLELINE)
    {
        return sizeof(wgui_editor_struct) + sizeof(single_line_input_box);
    }
    else
    {
        return sizeof(wgui_editor_struct) + sizeof(multi_line_input_box);
    }
}

/*****************************************************************************
* FUNCTION
*  wgui_editor_create
* DESCRIPTION
*  Creates an editor
* PARAMETERS
*  buffer                      [IN/OUT]    Is the wgui editor buffer (pre-allocated)
*  editor_type                 [IN]        Is the editor type
*  x                           [IN]        Is the left-top corner
*  y                           [IN]        Is the left-top corner
*  width                       [IN]        Is the width of the editor
*  height                      [IN]        Is the height of the editor
*  text_buffer                 [IN]        Is the text buffer the editor should use (pre-allocated)
*  text_buffer_size            [IN]        Is the text buffer size in Bytes
*  is_disable_softkey          [IN]        disable softkey or not
*  layer_handle                [IN]        Is the layer handle
* RETURNS
*  void
*****************************************************************************/
void wgui_editor_create(
                        wgui_editor_struct *buffer,
                        WGUI_EDITOR_TYPE editor_type,
                        S32 x,
                        S32 y,
                        S32 width,
                        S32 height,
                        UI_string_type text_buffer,
                        S32 text_buffer_size,
                        MMI_BOOL is_disable_softkey,
                        GDI_HANDLE layer_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_editor_struct *b;
    single_line_input_box *single_line;
    multi_line_input_box *multi_line;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (buffer == NULL)
    {
        return;
    }

    b = (wgui_editor_struct *)buffer;
    memset(b, 0, sizeof(wgui_editor_struct));

    b->editor_type = editor_type;
    b->is_disable_softkey = is_disable_softkey;
    b->layer_handle = layer_handle;
    b->RSK_label_clear = 0;
    if (editor_type == WGUI_EDITOR_SINGLELINE)
    {
        single_line = (single_line_input_box *)((U8*)buffer + sizeof(wgui_editor_struct));
        gui_create_single_line_input_box_set_buffer(
            single_line,
            x,
            y,
            width,
            height,
            text_buffer,
            text_buffer_size,
            (gui_strlen(text_buffer) + 1) * ENCODING_LENGTH,
            gui_strlen(text_buffer));

        /* before active, do not show cursor*/
        single_line->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
        /* clip */
        single_line->flags |= UI_SINGLE_LINE_INPUT_BOX_USE_PRESET_CLIPPING;
        b->editor = single_line;
        
        single_line->ext_flags |= GUI_SINGLE_LINE_INPUT_BOX_CUSTOM_STYLE_BACKGROUND;

#ifdef __COSMOS_MMI_PACKAGE__
        wgui_editor_set_bg_image_from_resource(b, (PU8)GetImage(VCP_IMG_TEXT_VIEW_HIGHLIGHT_BG), (PU8)GetImage(VCP_IMG_TEXT_VIEW_NORMAL_BG));
#else
#ifdef __MMI_FTE_SUPPORT__
        /* set default background image */        
        wgui_editor_set_bg_image_from_resource(b, (PU8)current_MMI_theme->inline_item_textedit_highlighted_bg_filler->b, (PU8)current_MMI_theme->inline_item_textedit_unhighlighted_bg_filler->b);
#else
        /* set default background style (normal rectangle background) */
        wgui_editor_set_bg_border_style(b, WGUI_EDITOR_SINGLE_BORDER, UI_COLOR_BLACK, UI_COLOR_GREEN);
#endif
#endif
    }
    else
    {
        multi_line = (multi_line_input_box *)((U8*)buffer + sizeof(wgui_editor_struct));
        gui_create_multi_line_input_box_set_buffer(
            multi_line,
            x,
            y,
            width,
            height,
            text_buffer,
            text_buffer_size,
            (gui_strlen(text_buffer) + 1) * ENCODING_LENGTH,
            gui_strlen(text_buffer));

        /* before active, do not show cursor*/
        multi_line->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
        /* preset clip */
        multi_line->flags |= UI_MULTI_LINE_INPUT_BOX_USE_PRESET_CLIPPING;
        multi_line->is_hide_floating_counter = MMI_TRUE;
        b->editor = multi_line;

#ifdef __COSMOS_MMI_PACKAGE__
        wgui_editor_set_bg_image_from_resource(b, (PU8)GetImage(VCP_IMG_TEXT_VIEW_HIGHLIGHT_BG), (PU8)GetImage(VCP_IMG_TEXT_VIEW_NORMAL_BG));
#else
#ifdef __MMI_FTE_SUPPORT__        
        /* set default background image */
        //wgui_editor_set_bg_image_from_resource(b, (PU8)GetImage(IMG_INLINE_DISPLAY_ONLY_HIGHLIGHT_BG), (PU8)GetImage(IMG_INLINE_DISPLAY_ONLY_NORMAL_BG));
        wgui_editor_set_bg_image_from_resource(b, (PU8)GetImage(IMG_INLINE_ML_HIGHLIGHT_BG), (PU8)GetImage(IMG_INLINE_ML_NORMAL_BG));

#else
        /* set default background style (normal rectangle background) */
        wgui_editor_set_bg_border_style(b, WGUI_EDITOR_SINGLE_BORDER, UI_COLOR_BLACK, UI_COLOR_GREEN);
#endif
#endif

    }
}


/*****************************************************************************
* FUNCTION
*  wgui_editor_close
* DESCRIPTION
*  Close the editor
* PARAMETERS
*  b               [IN/OUT]    Is the wgui editor instance
* RETURNS
*  void
*****************************************************************************/
void wgui_editor_close(wgui_editor_struct *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (b == NULL)
    {
        return;
    }

    if (b == g_current_active_editor)
    {
        close_flag = 1;
        wgui_editor_deactivate(b);
        close_flag = 0;
    }

    b->editor_type = (WGUI_EDITOR_TYPE)0;
    b->is_disable_softkey = MMI_FALSE;
    b->layer_handle = 0;
    b->input_type = IMM_INPUT_TYPE_NONE;
    b->input_setting = 0;
    b->input_mode_array = NULL;
    b->default_input_mode = IMM_INPUT_MODE_NONE;
    b->ime_msg_callback = NULL;
    b->RSK_label_clear = 0;
    b->update_text_callback = NULL;
    b->update_text_with_cursor_rect_callback = NULL;
}

/*****************************************************************************
* FUNCTION
*  wgui_editor_set_IME
* DESCRIPTION
*  set ime
* PARAMETERS
*  b                           [IN/OUT]    Is the wgui editor instance
*  input_type                  [IN]        Is the input type
*  input_setting               [IN]        Is the input setting
*  input_mode_array            [IN]        Is the input mode set, can pass null to use default mode set
*  default_input_mode          [IN]        Is the highest priority input mode in the mode set, can pass 0 to use default
*  mmi_imc_message_funcptr     [IN]        Is the ime callback function
* RETURNS
*  void
*****************************************************************************/
void wgui_editor_set_IME(
                         wgui_editor_struct *b,
                         mmi_imm_input_type_enum input_type,
                         S32 input_setting,
                         mmi_imm_input_mode_enum *input_mode_array,
                         mmi_imm_input_mode_enum default_input_mode,
                         mmi_imc_message_funcptr ime_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    single_line_input_box *single_line;
    multi_line_input_box *multi_line;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (b == NULL)
    {
        return;
    }

    b->input_type = input_type;
    b->input_setting = input_setting;
    b->input_mode_array = input_mode_array;
    b->default_input_mode = default_input_mode;
    b->ime_msg_callback = ime_callback;

    if (b->editor_type == WGUI_EDITOR_SINGLELINE)
    {
        /* singleline */
        single_line = (single_line_input_box *)(b->editor);

        if (b->input_type & IMM_INPUT_TYPE_EXT_PASSWORD)
        {
            single_line->flags |= UI_SINGLE_LINE_INPUT_BOX_MASK_CHARACTERS;
        }
    }
    else
    {
        /* multiline */
        multi_line = (multi_line_input_box *)(b->editor);
        
        if (b->input_type & IMM_INPUT_TYPE_EXT_PASSWORD)
        {
            multi_line->flags |= UI_MULTI_LINE_INPUT_BOX_MASK_CHARACTERS;
        }
    }
}

/*****************************************************************************
* FUNCTION
*  wgui_editor_set_softkey
* DESCRIPTION
*  set softkey
* PARAMETERS
*  b                           [IN/OUT]    Is the wgui editor instance
*  s                           [IN]        Is the label
*  icon                        [IN]        Is the icon
*  key                         [IN]        Is softkey type
*  f                           [IN]        Is the softkey handle
* RETURNS
*  void
*****************************************************************************/
void wgui_editor_set_softkey(
                             wgui_editor_struct *b,
                             UI_string_type s,
                             PU8 icon,
                             WGUI_SOFTKEY_ENUM key,
                             void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (b == NULL)
    {
        return;
    }

    b->is_disable_softkey = MMI_FALSE;
    b->softkey_label[key] = s;
    b->softkey_icon[key] = icon;
    b->softkey_handle[key] = f;    
}

/*****************************************************************************
* FUNCTION
*  wgui_editor_show
* DESCRIPTION
*  Display the editor (not blt)
* PARAMETERS
*  b               [IN]        Is the wgui editor instance
* RETURNS
*  void
*****************************************************************************/
void wgui_editor_show(wgui_editor_struct *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    single_line_input_box *single_line;
    multi_line_input_box *multi_line;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (b == NULL)
    {
        return;
    }

    if (b->layer_handle != GDI_NULL_HANDLE)
    {
        gdi_layer_push_and_set_active(b->layer_handle);
    }

    if (b->editor_type == WGUI_EDITOR_SINGLELINE)
    {
        single_line = (single_line_input_box *)(b->editor);        
        gui_show_single_line_input_box(single_line);
    }
    else
    {
        multi_line = (multi_line_input_box *)(b->editor);
        gui_show_multi_line_input_box(multi_line);
    }

    if (ime_floating_indicator_flag && b == g_current_active_editor)
    {
        /* draw ime floating indicator */
        mmi_imc_draw_indicator_floating(MMI_FALSE);
    }

    if (b->layer_handle != GDI_NULL_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }    
}

/*****************************************************************************
* FUNCTION
*  wgui_editor_redraw
* DESCRIPTION
*  Display the active editor (show and blt)
* PARAMETERS
*  b               [IN]        Is the wgui editor instance
* RETURNS
*  void
*****************************************************************************/
void wgui_editor_redraw(wgui_editor_struct *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    single_line_input_box *single_line;
    multi_line_input_box *multi_line; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (b == NULL)
    {
        return;
    }

    /* show */
    wgui_editor_show(b);

    /* blt */
    if (b->editor_type == WGUI_EDITOR_SINGLELINE)
    {
        single_line = (single_line_input_box *)(b->editor);
        gui_BLT_double_buffer(
            single_line->x,
            single_line->y,
            single_line->x + single_line->width,
            single_line->y + single_line->height);  
    }
    else
    {
        multi_line = (multi_line_input_box *)(b->editor);
        gui_BLT_double_buffer(
            multi_line->x,
            multi_line->y,
            multi_line->x + multi_line->width,
            multi_line->y + multi_line->height);  
    }

}

/*****************************************************************************
* FUNCTION
*  wgui_editor_redraw_active_editor
* DESCRIPTION
*  Display the active editor (blt)
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void wgui_editor_redraw_active_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (g_current_active_editor)
    {
        BOOL lcd_freeze = gdi_lcd_get_freeze();
        gdi_lcd_freeze(MMI_TRUE);

        /* draw active editor*/        
        if (g_current_active_editor->layer_handle != GDI_NULL_HANDLE)
        {
            gdi_layer_push_and_set_active(g_current_active_editor->layer_handle);
        }
        if (g_current_active_editor->editor_type == WGUI_EDITOR_SINGLELINE)
        {              
            gui_show_single_line_input_box((single_line_input_box *)(g_current_active_editor->editor));
        }
        else
        {
            gui_show_multi_line_input_box((multi_line_input_box *)(g_current_active_editor->editor));
        }
        if (g_current_active_editor->layer_handle != GDI_NULL_HANDLE)
        {
            gdi_layer_pop_and_restore_active();
        }
        

        if (ime_floating_indicator_flag)
        {
            /* draw ime floating indicator */
            mmi_imc_draw_indicator_floating(MMI_TRUE);
        }

        /* draw softkey */
        if (g_current_active_editor && !(g_current_active_editor->is_disable_softkey) &&
            !(mmi_imc_get_current_imui_height_skip_fixed_editor() > 0))
        {
            show_softkey_background();
            redraw_right_softkey();
            redraw_left_softkey();
            redraw_center_softkey();
        }

        gdi_lcd_freeze(lcd_freeze);
        gdi_lcd_repaint_all();
    }
}

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_set_text_font
 * DESCRIPTION
 *  set text font
 * PARAMETERS
 *  b               [IN]        Is the wgui editor instance
 *  text_font       [IN]        Is the text font
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_editor_set_text_font(wgui_editor_struct *b, UI_font_type text_font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    single_line_input_box *single_line;
    multi_line_input_box *multi_line; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (b == NULL || text_font == NULL)
    {
        return;
    }

    memcpy(&(b->text_font), text_font, sizeof(stFontAttribute));

    if (b->editor_type == WGUI_EDITOR_SINGLELINE)
    {
        single_line = (single_line_input_box *)(b->editor);
        single_line->text_font = &(b->text_font);
    }
    else
    {
        multi_line = (multi_line_input_box *)(b->editor);
        multi_line->text_font = &(b->text_font);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_editor_set_fit_text_font
 * DESCRIPTION
 *  set fit text font according to editor's height autoly for single line editor
 * PARAMETERS
 *  b               [IN]        Is the wgui editor instance
 *  text_font       [IN]        Is the text font
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_editor_set_fit_text_font(wgui_editor_struct *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    single_line_input_box *single_line;  
    S32 line_height, target_height;
    U8 size, start, end;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b == NULL || b->editor_type != WGUI_EDITOR_SINGLELINE)
    {
        return;        
    }

    single_line = (single_line_input_box *)(b->editor);
    target_height = single_line->height - single_line->margin.top_margin - single_line->margin.down_margin;
    
    if (target_height <= 0)
    {
        return;
    }

    if (mmi_fe_is_vector_font_support())
    {
        /* vector font, search by pixel */
        start = FONT_PIXEL_SIZE(target_height);
        end = FONT_PIXEL_SIZE(1);
    }
    else
    {
        /* bitmap font, search among small\medium\large font */
        start = LARGE_FONT;
        end = SMALL_FONT;
    }

    for (size = start; size >= end; size--)
    {
        line_height = Get_CharHeightOfAllLang(size);
        if (line_height <= target_height)
            break;
        if(size == end)
            break;
    }

    if (size !=  b->text_font.size)
    {
        b->text_font.size = size;
        single_line->text_font = &(b->text_font);
        /* locate cursor */
        gui_single_line_input_box_locate_cursor(single_line);
    }    
}
    

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_set_bg_image_from_resource
 * DESCRIPTION
 *  set the normal and focuss image pointers for image background from resource
 *  (there are two styles of background: image background and rectangle background)
 * PARAMETERS
 *  b                   [IN]        Is the wgui editor instance
 *  focussed_image      [IN]        Is the focuss image
 *  normal_image        [IN]        Is the normal image
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_editor_set_bg_image_from_resource(wgui_editor_struct *b, PU8 focussed_image, PU8 normal_image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    single_line_input_box *single_line;
    multi_line_input_box *multi_line; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (b == NULL)
    {
        return;
    }

    b->focussed_bg_filler.b = focussed_image;
    b->normal_bg_filler.b = normal_image;
    if (b->editor_type == WGUI_EDITOR_SINGLELINE)
    {
        single_line = (single_line_input_box *)(b->editor);
        single_line->selected_filler = &(b->focussed_bg_filler);
        single_line->normal_filler = &(b->normal_bg_filler);

        // clear mem image 
        single_line->normal_mem_bg_image = NULL;
        single_line->selected_mem_bg_image = NULL;
        
        /* set margin */
        gui_single_line_input_box_set_margin(single_line, -1, -1, WGUI_EDITOR_LEFT_RIGHT_MARGIN_IMAGE_BG, WGUI_EDITOR_LEFT_RIGHT_MARGIN_IMAGE_BG);
    }
    else
    {
        multi_line = (multi_line_input_box *)(b->editor);
        multi_line->focussed_filler = &(b->focussed_bg_filler);
        multi_line->normal_filler = &(b->normal_bg_filler);        

        // clear mem image 
        multi_line->normal_mem_bg_image = NULL;
        multi_line->focussed_mem_bg_image = NULL;

        /* set margin */
        gui_multi_line_input_box_set_margin(
            multi_line,
            WGUI_EDITOR_MULTILINE_TOP_DOWN_MARGIN_IMAGE_BG,
            WGUI_EDITOR_MULTILINE_TOP_DOWN_MARGIN_IMAGE_BG,
            WGUI_EDITOR_LEFT_RIGHT_MARGIN_IMAGE_BG,
            WGUI_EDITOR_LEFT_RIGHT_MARGIN_IMAGE_BG);
    }
}

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_set_bg_image_from_memory
 * DESCRIPTION
 *  set the normal and focuss image pointers for image background from memory
 *  (there are two styles of background: image background and rectangle background)
 * PARAMETERS
 *  b                           [IN]        Is the wgui editor instance
 *  focussed_image              [IN]        Is the focuss image
 *  normal_image                [IN]        Is the normal image
 *  focussed_image_length       [IN]        Is the image length of focuss image
 *  normal_image_length         [IN]        Is the image length of normal image
 *  focussed_image_type         [IN]        Is the image type of focuss image
 *  normal_image_type           [IN]        Is the image type of normal image
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_editor_set_bg_image_from_memory(
        wgui_editor_struct *b,
        PU8 focussed_image,
        PU8 normal_image,
        S32 focussed_image_length,
        S32 normal_image_length,
        U8 focussed_image_type,
        U8 normal_image_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    single_line_input_box *single_line;
    multi_line_input_box *multi_line; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (b == NULL)
    {
        return;
    }

    b->normal_mem_bg_image.data = normal_image;
    b->focussed_mem_bg_image.data = focussed_image;
    b->normal_mem_bg_image.len = normal_image_length;
    b->focussed_mem_bg_image.len = focussed_image_length;
    b->normal_mem_bg_image.type = normal_image_type;
    b->focussed_mem_bg_image.type = focussed_image_type;
   
    if (b->editor_type == WGUI_EDITOR_SINGLELINE)
    {
        single_line = (single_line_input_box *)(b->editor);
        single_line->normal_mem_bg_image = &(b->normal_mem_bg_image);
        single_line->selected_mem_bg_image = &(b->focussed_mem_bg_image);

        /* set margin */
        gui_single_line_input_box_set_margin(single_line, -1, -1, WGUI_EDITOR_LEFT_RIGHT_MARGIN_IMAGE_BG, WGUI_EDITOR_LEFT_RIGHT_MARGIN_IMAGE_BG);
    }
    else
    {
        multi_line = (multi_line_input_box *)(b->editor);
        multi_line->normal_mem_bg_image = &(b->normal_mem_bg_image);
        multi_line->focussed_mem_bg_image = &(b->focussed_mem_bg_image);  

        /* set margin */
        gui_multi_line_input_box_set_margin(
            multi_line,
            WGUI_EDITOR_MULTILINE_TOP_DOWN_MARGIN_IMAGE_BG,
            WGUI_EDITOR_MULTILINE_TOP_DOWN_MARGIN_IMAGE_BG,
            WGUI_EDITOR_LEFT_RIGHT_MARGIN_IMAGE_BG,
            WGUI_EDITOR_LEFT_RIGHT_MARGIN_IMAGE_BG);
    }
}

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_set_bg_border_style
 * DESCRIPTION
 *  set border style for rectangle background
 *  (there are two styles of background: image background and rectangle background)
 * PARAMETERS
 *  b                       [IN]        Is the wgui editor instance
 *  border_width            [IN]        Is the border width(no border/single border/double border)
 *  border_normal_color     [IN]        Is the border color of normal style
 *  border_focussed_color     [IN]        Is the border color of focuss style
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_editor_set_bg_border_style(wgui_editor_struct *b, WGUI_EDITOR_BORDER_TYPE border_width, color border_normal_color, color border_focussed_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    single_line_input_box *single_line;
    multi_line_input_box *multi_line; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (b == NULL)
    {
        return;
    }

    switch (border_width)
    {
    case WGUI_EDITOR_NO_BORDER:
        b->focussed_bg_filler.flags |= UI_FILLED_AREA_TYPE_NO_BORDER;
        b->normal_bg_filler.flags |= UI_FILLED_AREA_TYPE_NO_BORDER;       
        break;
    case WGUI_EDITOR_SINGLE_BORDER:
        b->focussed_bg_filler.flags |= UI_FILLED_AREA_SINGLE_BORDER;
        b->normal_bg_filler.flags |= UI_FILLED_AREA_SINGLE_BORDER;
        break;
    case WGUI_EDITOR_DOUBLE_BORDER:
        b->focussed_bg_filler.flags |= UI_FILLED_AREA_DOUBLE_BORDER;
        b->normal_bg_filler.flags |= UI_FILLED_AREA_DOUBLE_BORDER;
        break;
    }

    b->focussed_bg_filler.border_color = border_focussed_color;
    b->normal_bg_filler.border_color = border_normal_color;
    b->focussed_bg_filler.b = NULL;
    b->normal_bg_filler.b = NULL;
    b->focussed_bg_filler.c = UI_COLOR_WHITE;
    b->normal_bg_filler.c = UI_COLOR_WHITE; 
    
    if (b->editor_type == WGUI_EDITOR_SINGLELINE)
    {
        single_line = (single_line_input_box *)(b->editor);
        single_line->selected_filler = &(b->focussed_bg_filler);
        single_line->normal_filler = &(b->normal_bg_filler);

        // clear mem image 
        single_line->normal_mem_bg_image = NULL;
        single_line->selected_mem_bg_image = NULL;
   
        /* set margin */
        gui_single_line_input_box_set_margin(single_line, -1, -1, WGUI_EDITOR_LEFT_RIGHT_MARGIN_RECT_BG, WGUI_EDITOR_LEFT_RIGHT_MARGIN_RECT_BG);
    }
    else
    {
        multi_line = (multi_line_input_box *)(b->editor);
        multi_line->focussed_filler = &(b->focussed_bg_filler);
        multi_line->normal_filler = &(b->normal_bg_filler);

        // clear mem image 
        multi_line->normal_mem_bg_image = NULL;
        multi_line->focussed_mem_bg_image = NULL;

        /* set margin */
        gui_multi_line_input_box_set_margin(
            multi_line,
            WGUI_EDITOR_MULTILINE_TOP_DOWN_MARGIN_RECT_BG,
            WGUI_EDITOR_MULTILINE_TOP_DOWN_MARGIN_RECT_BG,
            WGUI_EDITOR_LEFT_RIGHT_MARGIN_RECT_BG,
            WGUI_EDITOR_LEFT_RIGHT_MARGIN_RECT_BG);
    }
}

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_set_margin
 * DESCRIPTION
 *  set margin for editor
 *  (for singleline, align center along y direction)
 * PARAMETERS
 *  b           [IN/OUT]    Is the wgui editor instance
 *  top         [IN]        top >0: set new value; -1: use default value
 *  down        [IN]        down >0: set new value; -1: use default value
 *  left        [IN]        left >0: set new value; -1: use default value
 *  right       [IN]        right >0: set new value; -1: use default value
 * RETURNS
 *  byte
 *****************************************************************************/
void wgui_editor_set_margin(wgui_editor_struct *b, S32 top, S32 down, S32 left, s32 right)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    single_line_input_box *single_line;
    multi_line_input_box *multi_line; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (b == NULL)
    {
        return;
    }

    if (b->editor_type == WGUI_EDITOR_SINGLELINE)
    {
        single_line = (single_line_input_box *)(b->editor);        
        /* set margin, for singleline, align center along y direction */
        top = down = (top + down) / 2;
        gui_single_line_input_box_set_margin(
            single_line,
            top,
            down,
            left,
            right);
    }
    else
    {
        multi_line = (multi_line_input_box *)(b->editor);        

        /* set margin */
        gui_multi_line_input_box_set_margin(
            multi_line,
            top,
            down,
            left,
            right);
    }
}


/*****************************************************************************
* FUNCTION
*  wgui_editor_set_pos
* DESCRIPTION
*  Move the editor
* PARAMETERS
*  b               [IN/OUT]    Is the wgui editor instance
*  x               [IN]        Is the left-top corner
*  y               [IN]        Is the left-top corner
* RETURNS
*  void
*****************************************************************************/
void wgui_editor_set_pos(wgui_editor_struct *b, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    single_line_input_box *single_line;
    multi_line_input_box *multi_line;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (b == NULL)
    {
        return;
    }

    if (b->editor_type == WGUI_EDITOR_SINGLELINE)
    {
        single_line = (single_line_input_box *)(b->editor);
        gui_move_single_line_input_box(single_line, x, y);
    }
    else
    {
        multi_line = (multi_line_input_box *)(b->editor);
        gui_move_multi_line_input_box(multi_line, x, y);
    }   
}

/*****************************************************************************
* FUNCTION
*  wgui_editor_set_size
* DESCRIPTION
*  Resize the editor
* PARAMETERS
*  b               [IN/OUT]    Is the wgui editor instance
*  width           [IN]        Is the width of the editor
*  height          [IN]        Is the height of the editor
* RETURNS
*  void
*****************************************************************************/
void wgui_editor_set_size(wgui_editor_struct *b, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    single_line_input_box *single_line;
    multi_line_input_box *multi_line;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (b == NULL)
    {
        return;
    }

    if (b->editor_type == WGUI_EDITOR_SINGLELINE)
    {
        single_line = (single_line_input_box *)(b->editor);
        gui_resize_single_line_input_box(single_line, width, height); 
    }
    else
    {
        multi_line = (multi_line_input_box *)(b->editor);
        gui_resize_multi_line_input_box(multi_line, width, height);
    }
}

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_set_text_color
 * DESCRIPTION
 *  set text color
 * PARAMETERS
 *  b               [IN/OUT]    Is the wgui editor instance
 *  text_color      [IN]        Is the text color
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_editor_set_text_color(wgui_editor_struct *b, color text_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    single_line_input_box *single_line;
    multi_line_input_box *multi_line;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (b == NULL)
    {
        return;
    }

    if (b->editor_type == WGUI_EDITOR_SINGLELINE)
    {
        single_line = (single_line_input_box *)(b->editor);
        single_line->normal_text_color = text_color;
    }
    else
    {
        multi_line = (multi_line_input_box *)(b->editor);
        multi_line->normal_text_color = multi_line->focussed_text_color = text_color;
    }
}

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_set_cursor_color
 * DESCRIPTION
 *  set cursor color
 * PARAMETERS
 *  b               [IN/OUT]    Is the wgui editor instance
 *  cursor_color    [IN]        Is the cursor color
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_editor_set_cursor_color(wgui_editor_struct *b, color cursor_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    single_line_input_box *single_line;
    multi_line_input_box *multi_line;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (b == NULL)
    {
        return;
    }

    if (b->editor_type == WGUI_EDITOR_SINGLELINE)
    {
        single_line = (single_line_input_box *)(b->editor);
        single_line->cursor_color = cursor_color;
    }
    else
    {
        multi_line = (multi_line_input_box *)(b->editor);
        multi_line->cursor_color = cursor_color;
    }
}

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_set_layer_handle
 * DESCRIPTION
 *  set editor layer handle
 * PARAMETERS
 *  b                           [IN/OUT]    Is the wgui editor instance
 *  layer_handle                [IN]        Is the layer handle
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_editor_set_layer_handle(wgui_editor_struct *b, GDI_HANDLE layer_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (b == NULL)
    {
        return;
    }

    b->layer_handle = layer_handle;
}

/*****************************************************************************
* FUNCTION
*  wgui_editor_set_is_draw_ime_floating_indicator
* DESCRIPTION
*  set if draw ime floating indicator
* PARAMETERS
*  is_draw_ime_floating_indicator        [IN]        if draw ime floating indicator
* RETURNS
*  void
*****************************************************************************/
void wgui_editor_set_is_draw_ime_floating_indicator(MMI_BOOL is_draw_ime_floating_indicator)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ime_floating_indicator_flag = is_draw_ime_floating_indicator;
}

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_set_update_text_callback
 * DESCRIPTION
 *  set update text call back
 * PARAMETERS
 *  b                           [IN/OUT]    Is the wgui editor instance
 *  f                           [IN]        Is update text callback
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_editor_set_update_text_callback(
    wgui_editor_struct *b, 
    void (*f)(UI_buffer_type text, UI_buffer_type cursor, S32 text_length))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    single_line_input_box *single_line;
    multi_line_input_box *multi_line;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b != NULL && f != NULL)
    {
        b->update_text_callback = f;

        if (b->editor_type == WGUI_EDITOR_SINGLELINE)
        {
            single_line = (single_line_input_box *)(b->editor);
            single_line->validation_callback = wgui_editor_update_text_callback;
        }
        else
        {
            multi_line = (multi_line_input_box *)(b->editor);
            multi_line->validation_callback = wgui_editor_update_text_callback;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_set_update_text_with_cursor_rect_callback
 * DESCRIPTION
 *  set update text call back(with curosr x, y info)
 * PARAMETERS
 *  b                           [IN/OUT]    Is the wgui editor instance
 *  f                           [IN]        Is update text with x y callback
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_editor_set_update_text_with_cursor_rect_callback(
    wgui_editor_struct *b, 
    void (*f)(UI_buffer_type text, UI_buffer_type cursor, S32 text_length, wgui_editor_rect_points_p cursor_rect_points))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b != NULL && f != NULL)
    {
        b->update_text_with_cursor_rect_callback = f;
    }
}


/*****************************************************************************
* FUNCTION
*  wgui_editor_get_pos
* DESCRIPTION
*  Get editor position
* PARAMETERS
*  b               [IN]        Is the wgui editor instance
*  x               [OUT]       Is the left-top corner
*  y               [OUT]       Is the left-top corner
* RETURNS
*  void
*****************************************************************************/
void wgui_editor_get_pos(wgui_editor_struct *b, S32 *x, S32 *y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    single_line_input_box *single_line;
    multi_line_input_box *multi_line;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (b == NULL)
    {
        return;
    }

    if (b->editor_type == WGUI_EDITOR_SINGLELINE)
    {
        single_line = (single_line_input_box *)(b->editor);
        *x = single_line->x;
        *y = single_line->y;
    }
    else
    {
        multi_line = (multi_line_input_box *)(b->editor);
        *x = multi_line->x;
        *y = multi_line->y;
    }
}

/*****************************************************************************
* FUNCTION
*  wgui_editor_get_size
* DESCRIPTION
* get editor size
* PARAMETERS
*  b               [IN]        Is the wgui editor instance
*  width           [OUT]        Is the width of the editor
*  height          [OUT]        Is the height of the editor
* RETURNS
*  void
*****************************************************************************/
void wgui_editor_get_size(wgui_editor_struct *b, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    single_line_input_box *single_line;
    multi_line_input_box *multi_line;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (b == NULL)
    {
        return;
    }

    if (b->editor_type == WGUI_EDITOR_SINGLELINE)
    {
        single_line = (single_line_input_box *)(b->editor);
        *width = single_line->width;
        *height = single_line->height;
    }
    else
    {
        multi_line = (multi_line_input_box *)(b->editor);
        *width = multi_line->width;
        *height = multi_line->height;
    }
}

/*****************************************************************************
* FUNCTION
*  wgui_editor_get_fit_height
* DESCRIPTION
*  get fit editor height according to the font size. only for singleline editor
* PARAMETERS
*  b               [IN]         Is the wgui editor instance
*  vertical_margin [IN]         Is the top/down margin
*  font_size       [IN]         Is the font size
* RETURNS
*  fit singleline editor height
*****************************************************************************/
S32 wgui_editor_get_fit_height(S32 vertical_margin, U8 font_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    S32 temp_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_height = Get_CharHeightOfAllLang(font_size);

    temp_height += vertical_margin * 2;

    return temp_height;
}

/*****************************************************************************
* FUNCTION
*  wgui_editor_set_text
* DESCRIPTION
*  Set text
* PARAMETERS
*  b               [IN]        Is the wgui editor instance
*  text_buffer     [IN]       Is the text buffer
*  buffer_size     [IN]       Is the buffer size (byte)
* RETURNS
*  void
*****************************************************************************/
void wgui_editor_set_text(wgui_editor_struct *b, UI_string_type text_buffer, S32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    single_line_input_box *single_line;
    multi_line_input_box *multi_line;
    UI_character_type dummy_c = 0;
    UI_buffer_type text;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* Check parameter */
    if (b == NULL)
    {
        return;
    }

    if (b->editor_type == WGUI_EDITOR_SINGLELINE)
    {
        single_line = (single_line_input_box *)(b->editor);
        single_line->text = (UI_buffer_type)text_buffer;
        single_line->allocated_length = buffer_size;
        single_line->available_length = buffer_size;

        if (single_line->text != NULL)
        {
            text = single_line->text;
            UI_STRING_GET_NEXT_CHARACTER(text, dummy_c);
            for (i = 0; !UI_STRING_END_OF_STRING_CHARACTER(dummy_c); i++)
            {                
                UI_TEST_UCS2_INCREMENT_COUNT(dummy_c, single_line->UCS2_count);
                UI_TEST_GSM_INCREMENT_COUNT(dummy_c, single_line->GSM_ext_count);
                UI_TEST_NON_ASCII_INCREMENT_COUNT(dummy_c, single_line->non_ascii_count);
                UI_STRING_GET_NEXT_CHARACTER(text, dummy_c);
            }

            single_line->text_length = (gui_strlen(text_buffer) + 1) * ENCODING_LENGTH;
            single_line->last_position_p = text;            
            single_line->current_text_p = single_line->text + single_line->text_length - ENCODING_LENGTH;
        }
        else
        {
            single_line->text_length = 0;
        }

        single_line->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
        gui_show_single_line_input_box(single_line);
        single_line->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    }
    else
    {
        multi_line = (multi_line_input_box *)(b->editor);
        multi_line->text = (UI_buffer_type)text_buffer;
        multi_line->allocated_length = buffer_size;
        multi_line->available_length = buffer_size; 

        if (multi_line->text != NULL)
        {
            text = multi_line->text;
            UI_STRING_GET_NEXT_CHARACTER(text, dummy_c);
            for (i = 0; !UI_STRING_END_OF_STRING_CHARACTER(dummy_c); i++)
            {                
                UI_TEST_UCS2_INCREMENT_COUNT(dummy_c, multi_line->UCS2_count);
                UI_TEST_GSM_INCREMENT_COUNT(dummy_c, multi_line->GSM_ext_count);
                UI_TEST_NON_ASCII_INCREMENT_COUNT(dummy_c, multi_line->non_ascii_count);
                UI_STRING_GET_NEXT_CHARACTER(text, dummy_c);
            }

            multi_line->text_length = (gui_strlen(text_buffer) + 1) * ENCODING_LENGTH;
            multi_line->last_position_p = text;            
            multi_line->cursor_p = multi_line->text + multi_line->text_length - ENCODING_LENGTH;
        }
        else
        {
            multi_line->text_length = 0;
        }    

        multi_line->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        gui_show_multi_line_input_box(multi_line);
        multi_line->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;

        #ifdef GUI_INPUT_BOX_CACHE_SUPPORT
            gui_mlc_all_line_update();
        #endif
    } 
}

/*****************************************************************************
* FUNCTION
*  wgui_editor_set_default_text
* DESCRIPTION
*  Set default text
* PARAMETERS
*  b                       [IN]        Is the wgui editor instance
*  default_text_buffer     [IN]       Is the default text buffer
* RETURNS
*  void
*****************************************************************************/
void wgui_editor_set_default_text(wgui_editor_struct *b, UI_string_type default_text_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    single_line_input_box *single_line;
    multi_line_input_box *multi_line;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* Check parameter */
    if (b == NULL || default_text_buffer == NULL)
    {
        return;
    }

    if (b->editor_type == WGUI_EDITOR_SINGLELINE)
    {
        single_line = (single_line_input_box *)(b->editor);
        single_line->default_text = default_text_buffer;
    }
    else
    {
        multi_line = (multi_line_input_box *)(b->editor);
        multi_line->default_text = default_text_buffer;
    }
}

/*****************************************************************************
* FUNCTION
*  wgui_editor_insert_string
* DESCRIPTION
*  insert string
* PARAMETERS
*  b                       [IN]        Is the wgui editor instance
*  str                     [IN]        Is the string to be inserted
*  len                     [IN]        string length
* RETURNS
*  U32: length of the string actually inserted
*****************************************************************************/
U32 wgui_editor_insert_string(wgui_editor_struct *b, UI_string_type str, U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    single_line_input_box *single_line;
    multi_line_input_box *multi_line;
    U32 i, total_len = 0;
    S32 old_show_action_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* Check parameter */
    if (b == NULL || str == NULL || b != g_current_active_editor)
    {
        return 0;
    }

    if (b->editor_type == WGUI_EDITOR_SINGLELINE)
    {
        single_line = (single_line_input_box *)(b->editor);
        
        old_show_action_flag = single_line->show_action_flag;
        single_line->show_action_flag = 0;
        for (i = 0; i < len; i++)
        {
            if (gui_single_line_input_box_insert_character(single_line, (UI_character_type)str[i]))
            {
                total_len ++;
            }
            else
            {
                break;
            }
        }
        single_line->show_action_flag = old_show_action_flag;

        gui_single_line_input_box_locate_cursor(single_line);
    }
    else
    {
        multi_line = (multi_line_input_box *)(b->editor);

        old_show_action_flag = multi_line->show_action_flag;
        multi_line->show_action_flag = 0;
        for (i = 0; i < len; i++)
        {
            if (gui_multi_line_input_box_insert_character(multi_line, (UI_character_type)str[i]))
            {
                total_len ++;
            }
            else
            {
                break;
            }
        }
        multi_line->show_action_flag = old_show_action_flag;

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
        gui_mlc_all_line_update();        
#endif 
    }

    wgui_editor_handle_input();
    //redraw editor
    wgui_editor_redraw_active_editor();
    
    return total_len;
}

/*****************************************************************************
* FUNCTION
*  wgui_editor_get_text
* DESCRIPTION
*  Get text
* PARAMETERS
*  b               [IN]        Is the wgui editor instance
*  text_buffer     [IN/OUT]    Is the text buffer
*  buffer_size     [IN]        Is the buffer size(byte)
* RETURNS
*  S32: text length
*****************************************************************************/
S32 wgui_editor_get_text(wgui_editor_struct *b, UI_string_type text_buffer, S32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    single_line_input_box *single_line;
    multi_line_input_box *multi_line;
    S32 text_length;
    CHAR *text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (b == NULL || text_buffer == NULL)
    {
        return -1;
    }

    if (b->editor_type == WGUI_EDITOR_SINGLELINE)
    {
        single_line = (single_line_input_box *)(b->editor);
        text = (CHAR*)single_line->text;
    }
    else
    {
        multi_line = (multi_line_input_box *)(b->editor);
        text = (CHAR*)multi_line->text;        
    }

    text_length = mmi_ucs2strlen(text);

    /* App must pass enough dest buffer for copy, otherwise, text will be truncated */
    if (text_length < (buffer_size / 2) - 1)
    {
        mmi_ucs2cpy((CHAR*)text_buffer, text);
    }
    else
    {
        mmi_ucs2ncpy((CHAR*)text_buffer, text, (buffer_size / 2) - 1);
    }

    return text_length;
}

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_get_cursor_index
 * DESCRIPTION
 *  Get editor cursor index
 * PARAMETERS
 *  b               [IN]        Is the wgui editor instance
 * RETURNS
 *  S32: cursor index
 *****************************************************************************/
S32 wgui_editor_get_cursor_index(wgui_editor_struct *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    single_line_input_box *single_line;
    multi_line_input_box *multi_line;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (b == NULL)
    {
        return -1;
    }

    if (b->editor_type == WGUI_EDITOR_SINGLELINE)
    {
        single_line = (single_line_input_box *)(b->editor);
        return (single_line->current_text_p - single_line->text) / ENCODING_LENGTH;
    }
    else
    {
        multi_line = (multi_line_input_box *)(b->editor);
        return (multi_line->cursor_p - multi_line->text) / ENCODING_LENGTH;
    }    
}

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_set_cursor_index
 * DESCRIPTION
 *  Set editor cursor index
 * PARAMETERS
 *  b               [IN]        Is the wgui editor instance
 *  cursor_index    [IN]        Is the cursor index
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_editor_set_cursor_index(wgui_editor_struct *b, U32 cursor_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    single_line_input_box *single_line;
    multi_line_input_box *multi_line;
    U32 offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (b == NULL)
    {
        return;
    }

    if (b->editor_type == WGUI_EDITOR_SINGLELINE)
    {
        single_line = (single_line_input_box *)(b->editor);
        offset = cursor_index * ENCODING_LENGTH <= single_line->text_length - ENCODING_LENGTH ?
                    cursor_index * ENCODING_LENGTH : single_line->text_length - ENCODING_LENGTH;
        single_line->current_text_p = single_line->text + offset;
    }
    else
    {
        multi_line = (multi_line_input_box *)(b->editor);
        offset = cursor_index * ENCODING_LENGTH <= multi_line->text_length - ENCODING_LENGTH ?
                    cursor_index * ENCODING_LENGTH : multi_line->text_length - ENCODING_LENGTH;
        multi_line->cursor_p = multi_line->text + offset;
    }    
}


/*****************************************************************************
* FUNCTION
*  wgui_editor_activate
* DESCRIPTION
*  Activate the editor
* PARAMETERS
*  b               [IN]        Is the wgui editor instance
*  showVK          [IN]        If show VK when activate
* RETURNS
*  void
*****************************************************************************/
void wgui_editor_activate(wgui_editor_struct *b, MMI_BOOL showVK)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    single_line_input_box *single_line;
    multi_line_input_box *multi_line;
    MMI_BOOL pre_flag;
    BOOL lcd_freeze = gdi_lcd_get_freeze();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (b == NULL || g_current_active_editor == b)
    {
        return;
    }
    
    gdi_lcd_freeze(MMI_TRUE);

    /* deactive if any */
    if (g_current_active_editor != b && g_current_active_editor != NULL)
    {
        wgui_editor_deactivate(g_current_active_editor);
    }

    g_current_active_editor = b;

    /* set editor attribute */
    if (b->editor_type == WGUI_EDITOR_SINGLELINE)
    {
        /* singleline */
        single_line = (single_line_input_box *)(b->editor);

        /* set flags */
        if (b->input_setting & INPUT_SETTING_USE_ENCODING_BASED_LENGTH)
        {
            single_line->flags |= UI_SINGLE_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH;
            UI_TEST_UCS2_COUNT_SET_LENGTH(
                single_line->UCS2_count,
                single_line->allocated_length,
                single_line->available_length);
        }        

        single_line->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
        single_line->flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED;

        g_mmi_editor_hanler.input_box_type = MMI_EDITOR_SINGLE_LINE_INPU_BOX;

        /* disable new line symbol */
        MMI_current_input_ext_type |= INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;     
    }
    else
    {
        /* multiline */
        multi_line = (multi_line_input_box *)(b->editor);

        /* set flags */
        if (b->input_setting & INPUT_SETTING_USE_ENCODING_BASED_LENGTH)
        {
            multi_line->flags |= UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH;
            UI_TEST_UCS2_COUNT_SET_LENGTH(
                multi_line->UCS2_count,
                multi_line->allocated_length,
                multi_line->available_length);
        } 

        multi_line->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
        multi_line->flags |= UI_MULTI_LINE_INPUT_BOX_STATE_FOCUSSED;
        multi_line->is_hide_floating_counter = MMI_FALSE;

        g_mmi_editor_hanler.input_box_type = MMI_EDITOR_MULTILINE_INPUT_BOX;

        /* enable new line symbol */
        MMI_current_input_ext_type &= ~INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;       
    } 
    
    /* set softkey */
    if (!(b->is_disable_softkey))
    {       
        int i;
        
        for (i = 0; i < WGUI_MAX_SOFTKEYS; i++)
        {
            set_softkey_label(b->softkey_label[i], (WGUI_SOFTKEY_ENUM)i);
            set_softkey_icon(b->softkey_icon[i], (WGUI_SOFTKEY_ENUM)i);
            set_softkey_function(b->softkey_handle[i], KEY_EVENT_DOWN, (WGUI_SOFTKEY_ENUM)i);              
            register_softkey_handler((WGUI_SOFTKEY_ENUM)i);

            set_softkey_function(NULL, KEY_EVENT_UP, (WGUI_SOFTKEY_ENUM)i); //clear all up handler
        }

        wgui_editor_handle_input();
        register_default_hide_softkeys();        
    }
    else
    {
        // no softkey
        wgui_softkey_lock_softkey(0, 0, MMI_LEFT_SOFTKEY);
        wgui_softkey_lock_softkey(0, 0, MMI_CENTER_SOFTKEY);
        wgui_softkey_lock_softkey(0, 0, MMI_RIGHT_SOFTKEY);
    }

    /* connect the ime */
    g_mmi_editor_hanler.input_box_sub_type = MMI_EDITOR_NORMAL_INPUT_BOX;
    g_mmi_editor_hanler.input_box_handler = b->editor;
    mmi_imc_disable_ime_handlers();
    #if defined(__MMI_IME_FTE_ENHANCE__)
    if (showVK)
         mmi_imc_set_vk_present(MMI_IMC_VK_DEFAULT_ENLARGE);
    #endif

    if (b->history && b->history->is_valid)
    {
        /* if history, restore the ime history */
        mmi_imc_set_input_method_history(&(b->history->ime_history));
        /* reset */
        b->history->is_valid = 0;
        b->history = NULL;
    }
    else
    {
        /* first in, set input type, mode array, default mode */
        mmi_imm_set_required_mode_list(b->input_type, b->input_mode_array, b->default_input_mode);
    }
    mmi_imc_set_backgroud_filler(wgui_editor_draw_imui_background_funcptr);
    mmi_imc_connect((void *)&g_mmi_editor_hanler, wgui_editor_msg_call_back_adaptor);

    pre_flag = ime_floating_indicator_flag;
    ime_floating_indicator_flag = MMI_FALSE; /* do not draw indicator this time */
    /* redraw ime ui, if not call this api, and set showVK enlarge, it will shows abnormal */
    mmi_imc_redraw_screen_by_state();
    ime_floating_indicator_flag = pre_flag;

    /* when activate a editor, need to redraw editor, ime indicator and softkey area(if no vk) */
    wgui_editor_redraw_active_editor();

    gdi_lcd_freeze(lcd_freeze);
    gdi_lcd_repaint_all();
}

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_deactivate
 * DESCRIPTION
 *  Deactivate the editor
 * PARAMETERS
 *  b               [IN]        Is the wgui editor instance
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_editor_deactivate(wgui_editor_struct *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    single_line_input_box *single_line;
    multi_line_input_box *multi_line;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (b == NULL)
    {
        return;
    }

    if (b == g_current_active_editor && g_current_active_editor != NULL)
    {    
        if (b->editor_type == WGUI_EDITOR_SINGLELINE)
        {
            single_line = (single_line_input_box *)(b->editor);
            single_line->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
            single_line->flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED;
        }
        else
        {
            multi_line = (multi_line_input_box *)(b->editor);
            multi_line->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
            multi_line->flags &= ~UI_MULTI_LINE_INPUT_BOX_STATE_FOCUSSED;
            multi_line->is_hide_floating_counter = MMI_TRUE;
        }

        if (b->is_disable_softkey)
        {
            wgui_softkey_unlock_softkey(MMI_LEFT_SOFTKEY);
            wgui_softkey_unlock_softkey(MMI_CENTER_SOFTKEY);
            wgui_softkey_unlock_softkey(MMI_RIGHT_SOFTKEY);
        }

        /* stop cursor */
        StopTimer(BLINKING_CURSOR);

        /* disconnect ime */
        mmi_imc_disconnect();
 
        g_current_active_editor = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_get_active_editor
 * DESCRIPTION
 *  Get current active editor
 * PARAMETERS
 *  b               [IN]        Is the pointer point to the wgui editor pointer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_editor_get_active_editor(wgui_editor_struct **b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (b == NULL)
    {
        return;
    }
    *b = g_current_active_editor;
}

/*****************************************************************************
* FUNCTION
*  wgui_editor_save
* DESCRIPTION
*  Save gui info of editor
* PARAMETERS
*  b               [IN]        Is the wgui editor instance
*  history_buffer  [IN]        Is the buffer used to save eidtor info
* RETURNS
*  void
*****************************************************************************/
void wgui_editor_save(wgui_editor_struct *b, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    single_line_input_box *single_line;
    multi_line_input_box *multi_line;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b && history_buffer)
    {
        wgui_editor_history_struct *h = (wgui_editor_history_struct*) history_buffer;

        if(b->editor_type == WGUI_EDITOR_SINGLELINE)
        { 
            single_line = (single_line_input_box *)(b->editor);
            h->editor_type = WGUI_EDITOR_SINGLELINE;
            h->text_length = (S16) single_line->text_length;            
            h->current_position = (S16) (single_line->current_text_p - single_line->text);
            h->text_offset_x = (S16) single_line->text_offset_x;            
            h->flags = (U32) single_line->flags;
            h->allocated_length = (S16) single_line->allocated_length;
            h->available_length = (S16) single_line->available_length;
            h->UCS2_count = (S16) single_line->UCS2_count;

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
        else
        {
            U32 tmp_flags;  
            S8 i;           

            multi_line = (multi_line_input_box *)(b->editor);

            h->editor_type = WGUI_EDITOR_MULTILINE;
            h->text_length = (S16) multi_line->text_length;
            h->allocated_length = (S16) multi_line->allocated_length;
            h->available_length = (S16) multi_line->available_length;
            h->UCS2_count = (S16) multi_line->UCS2_count;
            h->n_lines = (S16) multi_line->n_lines;
            h->text_height = (S16) multi_line->text_height;
            h->text_offset_x = (S16) multi_line->text_offset_x;
            h->text_offset_y = (S16) multi_line->text_offset_y;
            h->cursor_x = (S16) multi_line->cursor_x;
            h->cursor_y = (S16) multi_line->cursor_y;
            h->cursor_line_position_counter = (S16) multi_line->cursor_line_position_counter;
            h->line_before_cursor_line_p =
                (S16) (multi_line->line_before_cursor_line_p - multi_line->text);
            h->cursor_line_p = (S16) (multi_line->cursor_line_p - multi_line->text);
            h->current_position = (S16) (multi_line->cursor_p - multi_line->text);
            h->line_after_cursor_line_p =
                (S16) (multi_line->line_after_cursor_line_p - multi_line->text);
            h->line_after_cursor_line_last_p =
                (S16) (multi_line->line_after_cursor_line_last_p - multi_line->text);
            h->last_position_p = (S16) (multi_line->last_position_p - multi_line->text);
            h->changed = (U8)multi_line->editor_changed;
            h->pre_scrollbar_state = multi_line->scrollbar_state;
            h->pre_height = multi_line->height;
            mmi_imc_get_input_method_history(&(h->ime_history));            

            h->ext_flags = (U32)multi_line->ext_flags;
            h->last_cursor_offset = multi_line->last_cursor_offset;
            if (mmi_imc_is_multitap_state(h->ime_history.state))
            {
                if (multi_line->input_mode_cursor_p < multi_line->text)
                    multi_line->input_mode_cursor_p = multi_line->cursor_p;

                if (multi_line->input_start_cursor_p < multi_line->text)
                    multi_line->input_start_cursor_p = multi_line->cursor_p;

                h->input_mode_cursor_p = (S16) (multi_line->input_mode_cursor_p - multi_line->text);
                h->input_mode_start_p = (S16) (multi_line->input_start_cursor_p - multi_line->text);
                h->ext_flags |= GUI_MULTI_LINE_INPUT_BOX_INPUT_METHOD_MODE;
            }
            else
                h->ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_INPUT_METHOD_MODE;


            tmp_flags = multi_line->flags;
            /* to disable multitap flag 20040712 to disable highlight flag */
            tmp_flags &= ~UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP;            

            for (i = 0; i < sizeof(U32); i++)
            {
                memcpy((U8*) (&h->flags) + i, (U8*) (&tmp_flags) + i, 1);
            }

#if defined(__MMI_VIRTUAL_KEYBOARD__)
            /* W05.41 Do not Strore Virtual Keyboard into History when View Mode */
            if (multi_line->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE)
            {
                h->ime_history.vk_type = GUI_VIRTUAL_KEYBOARD_EMPTY_TRAY;
            }

#endif /* defined(__MMI_VIRTUAL_KEYBOARD__) */     
        }
    }
}

/*****************************************************************************
* FUNCTION
*  wgui_editor_restore
* DESCRIPTION
*  Restore history gui info to editor
* PARAMETERS
*  b               [IN]        Is the wgui editor instance
*  history_buffer  [IN]        Is the saved eidtor info
* RETURNS
*  void
*****************************************************************************/
void wgui_editor_restore(wgui_editor_struct *b, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    single_line_input_box *single_line;
    multi_line_input_box *multi_line;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b && history_buffer)
    {
        wgui_editor_history_struct *h = (wgui_editor_history_struct*) history_buffer;
        if (h->editor_type == b->editor_type)
        { 
            if(b->editor_type == WGUI_EDITOR_SINGLELINE)
            { 
                single_line = (single_line_input_box *)(b->editor);
                single_line->text_length = h->text_length;            
                single_line->current_text_p =
                    (UI_buffer_type) (single_line->text + h->current_position);
                single_line->text_offset_x = h->text_offset_x;            
                single_line->flags = h->flags;
                single_line->allocated_length = h->allocated_length;
                single_line->available_length = h->available_length;
                single_line->UCS2_count = h->UCS2_count;
            }
            else
            {
                multi_line = (multi_line_input_box *)(b->editor);            

                multi_line->text_length = h->text_length;
                multi_line->allocated_length = h->allocated_length;
                multi_line->available_length = h->available_length;
                multi_line->n_lines = h->n_lines;
                multi_line->text_height = h->text_height;
                multi_line->text_offset_x = h->text_offset_x;
                multi_line->text_offset_y = h->text_offset_y;
                if (multi_line->text_offset_y > 0)
                {
                    multi_line->text_offset_y = 0;
                }
                multi_line->cursor_x = h->cursor_x;
                multi_line->cursor_y = h->cursor_y;
                multi_line->cursor_line_position_counter = h->cursor_line_position_counter;
                multi_line->line_before_cursor_line_p =
                    (UI_buffer_type) (multi_line->text + h->line_before_cursor_line_p);
                multi_line->cursor_line_p = (UI_buffer_type) (multi_line->text + h->cursor_line_p);
                multi_line->cursor_p= (UI_buffer_type) (multi_line->text + h->current_position);
                multi_line->line_after_cursor_line_p =
                    (UI_buffer_type) (multi_line->text + h->line_after_cursor_line_p);
                multi_line->line_after_cursor_line_last_p =
                    (UI_buffer_type) (multi_line->text + h->line_after_cursor_line_last_p);
                multi_line->last_position_p =
                    (UI_buffer_type) (multi_line->text + h->last_position_p);
                multi_line->UCS2_count = h->UCS2_count;
                multi_line->pre_scrollbar_state = h->pre_scrollbar_state;
                multi_line->pre_height = h->pre_height;

                multi_line->flags = h->flags;
                multi_line->ext_flags=h->ext_flags;
                multi_line->editor_changed = (S32)h->changed;
                if (multi_line->ext_flags & GUI_MULTI_LINE_INPUT_BOX_INPUT_METHOD_MODE
                    && mmi_imc_is_multitap_state(h->ime_history.state))
                {
                    multi_line->input_mode_cursor_p = (UI_buffer_type) (multi_line->text + h->input_mode_cursor_p);
                    multi_line->input_start_cursor_p = (UI_buffer_type) (multi_line->text + h->input_mode_start_p);
                }                

                multi_line->last_cursor_offset = h->last_cursor_offset;
            }

            h->is_valid = 1;
            b->history = h;
        }
        else
        {
            h->is_valid = 0;
            b->history = NULL;
        }
    }

}

/*****************************************************************************
* FUNCTION
*  wgui_editor_previous_character
* DESCRIPTION
*  Previous character
* PARAMETERS
*  void
* RETURNS
*  MMI_BOOL
*****************************************************************************/
static MMI_BOOL wgui_editor_previous_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_current_active_editor->editor_type == WGUI_EDITOR_SINGLELINE)
    {       
        ret = gui_single_line_input_box_previous((single_line_input_box *)(g_current_active_editor->editor));
    }
    else
    {        
        ret = gui_multi_line_input_box_previous((multi_line_input_box *)(g_current_active_editor->editor));
    } 

    return ret;
}

/*****************************************************************************
* FUNCTION
*  wgui_editor_next_character
* DESCRIPTION
*  Next character
* PARAMETERS
*  void
* RETURNS
*  MMI_BOOL
*****************************************************************************/
static MMI_BOOL wgui_editor_next_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_current_active_editor->editor_type == WGUI_EDITOR_SINGLELINE)
    {        
        ret = gui_single_line_input_box_next((single_line_input_box *)(g_current_active_editor->editor));
    }
    else
    {
        ret = gui_multi_line_input_box_next((multi_line_input_box *)(g_current_active_editor->editor));
    }
 
    return ret;
}

/*****************************************************************************
* FUNCTION
*  wgui_editor_previous_line
* DESCRIPTION
*  previous line
* PARAMETERS
*  void
* RETURNS
*  MMI_BOOL
*****************************************************************************/
static MMI_BOOL wgui_editor_previous_line(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    multi_line_input_box *multi_line;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_current_active_editor->editor_type == WGUI_EDITOR_MULTILINE)
    {
        multi_line = (multi_line_input_box *)(g_current_active_editor->editor);

        if (multi_line->cursor_line_p == multi_line->line_before_cursor_line_p)
        {
            /* if already reach the first line */
            ret = MMI_FALSE;
        }
        else
        {            
            ret = MMI_TRUE;
        }

        gui_multi_line_input_box_previous_line(multi_line);
    }

    return ret;
}

/*****************************************************************************
* FUNCTION
*  wgui_editor_next_line
* DESCRIPTION
*  Next line
* PARAMETERS
*  void
* RETURNS
*  MMI_BOOL
*****************************************************************************/
static MMI_BOOL wgui_editor_next_line(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    multi_line_input_box *multi_line;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_current_active_editor->editor_type == WGUI_EDITOR_MULTILINE)
    {
        multi_line = (multi_line_input_box *)(g_current_active_editor->editor);        
        
        if (multi_line->cursor_line_p == multi_line->line_after_cursor_line_p)
        {
            /* if already reach the last line */
            ret = MMI_FALSE;
        }
        else
        {            
            ret = MMI_TRUE;
        }

        gui_multi_line_input_box_next_line(multi_line);
    }

    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_update_text_callback
 * DESCRIPTION
 *  if not ime state, call update text callback which app set
 * PARAMETERS
 *  text               [IN]        text
 *  cursor             [IN]        cursor pointer
 *  text_length        [IN]        length of text
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_editor_update_text_callback(UI_buffer_type text, UI_buffer_type cursor, S32 text_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    single_line_input_box *single_line;
    multi_line_input_box *multi_line;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_current_active_editor && g_current_active_editor->update_text_callback)
    {
        if (g_current_active_editor->editor_type == WGUI_EDITOR_SINGLELINE)
        {
            single_line = (single_line_input_box *)(g_current_active_editor->editor);
            if (!(single_line->flags & UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP)
                && !(single_line->flags & UI_SINGLE_LINE_INPUT_BOX_INPUT_METHOD_MODE))
            {
                g_current_active_editor->update_text_callback(text, cursor, text_length);
            }
        }
        else
        {
            multi_line = (multi_line_input_box *)(g_current_active_editor->editor);
            if (!(multi_line->flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP)
                && !(multi_line->ext_flags & GUI_MULTI_LINE_INPUT_BOX_INPUT_METHOD_MODE))
            {
                g_current_active_editor->update_text_callback(text, cursor, text_length);
            }
        }
        
    }
}

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_update_text_callback
 * DESCRIPTION
 *  if not ime state, call update text callback which app set
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_editor_update_text_with_cursor_rect_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_editor_rect_points cursor_rect_points;
    
    single_line_input_box *single_line;
    multi_line_input_box *multi_line;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cursor_rect_points.x1 = UI_cursor_x1;
    cursor_rect_points.y1 = UI_cursor_y1;    
    cursor_rect_points.x2 = UI_cursor_x2;
    cursor_rect_points.y2 = UI_cursor_y2;
    
    if (g_current_active_editor && g_current_active_editor->update_text_with_cursor_rect_callback)
    {  
        if (g_current_active_editor->editor_type == WGUI_EDITOR_SINGLELINE)
        {
            single_line = (single_line_input_box *)(g_current_active_editor->editor);
            if (!(single_line->flags & UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP)
                && !(single_line->flags & UI_SINGLE_LINE_INPUT_BOX_INPUT_METHOD_MODE))
            {
                g_current_active_editor->update_text_with_cursor_rect_callback(
                                            single_line->text,
                                            single_line->current_text_p,
                                            (single_line->text_length / ENCODING_LENGTH - 1),
                                            &cursor_rect_points);
            }
        }
        else
        {
            multi_line = (multi_line_input_box *)(g_current_active_editor->editor);
            if (!(multi_line->flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP)
                && !(multi_line->ext_flags & GUI_MULTI_LINE_INPUT_BOX_INPUT_METHOD_MODE))
            {
                g_current_active_editor->update_text_with_cursor_rect_callback(
                                            multi_line->text,
                                            multi_line->cursor_p,
                                            (multi_line->text_length / ENCODING_LENGTH - 1),
                                            &cursor_rect_points);
            }
        }
    }

}

/*****************************************************************************
* FUNCTION
*  wgui_editor_redraw_softkey
* DESCRIPTION
*  redraw softkey
* PARAMETERS
*  void
* RETURNS
*  MMI_BOOL
*****************************************************************************/
static void wgui_editor_redraw_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* finally draw softkey, if no fix imui shows */
    if (g_current_active_editor && !(g_current_active_editor->is_disable_softkey) &&
        !(mmi_imc_get_current_imui_height_skip_fixed_editor() > 0))
    {
        BOOL lcd_freeze = gdi_lcd_get_freeze();
        gdi_lcd_freeze(MMI_TRUE);

        show_softkey_background();
        redraw_right_softkey();
        redraw_left_softkey();
        redraw_center_softkey();

        gdi_lcd_freeze(lcd_freeze);
        gdi_lcd_repaint_all();       
    }
}

/*****************************************************************************
* FUNCTION
*  wgui_editor_handle_right_softkey
* DESCRIPTION
*  hangle right softkey, delete character
* PARAMETERS
*  void
* RETURNS
*  MMI_BOOL
*****************************************************************************/
static void wgui_editor_handle_right_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_current_active_editor == NULL)
        return;

    /* delete character */
    if (g_current_active_editor->editor_type == WGUI_EDITOR_SINGLELINE)
    { 
        gui_single_line_input_box_delete_character((single_line_input_box*)(g_current_active_editor->editor));
    }
    else
    {
        gui_multi_line_input_box_delete_character((multi_line_input_box*)(g_current_active_editor->editor));
    }

    /* after delete, re-set RSK */   
    wgui_editor_handle_input();

    /* Redraw the editor */
    wgui_editor_redraw_active_editor();
}

/*****************************************************************************
* FUNCTION
*  wgui_editor_msg_call_back_adaptor
* DESCRIPTION
*  msg adaptor between app and IME
* PARAMETERS
* void        
* RETURNS
* void
*****************************************************************************/
static U32 wgui_editor_msg_call_back_adaptor(void * input_box_handle, mmi_imc_message_struct_p msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 lresult = 0;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    MMI_ASSERT(((mmi_editor_handler_struct *)input_box_handle)->input_box_handler == g_current_active_editor->editor);

    /* pre pass, do something */
    switch (msg_ptr->message_id)
    {
        case MMI_IMC_MESSAGE_REDRAW:
            if (msg_ptr->param_0 == 0)
            {
                /* ime will send redraw_msg with param_0 = 0 after sending MMI_IMC_MESSAGE_IMUI_RECTANGLE_IS_UPDATED. 
                   But according to our design, app will redraw after MMI_IMC_MESSAGE_IMUI_RECTANGLE_IS_UPDATED,
                   so no need to pass redraw_msg to redraw again. 
                   If msg_ptr->param_0 = 1, that means floating ui disappear, pass the msg to let app redraw */
                return lresult;
            }
            break;
        case MMI_IMC_MESSAGE_SET_KEY:
            break;
        case MMI_IMC_MESSAGE_ACTIVATE:
            break;
        case MMI_IMC_MESSAGE_DEACTIVATE:
            /* if pop up ime common screen, exit app screen, do not pass msg to app to redraw screen,
               or the vk maynot redraw cause ime is disconnect*/
            if (close_flag)
            {
                close_flag = 0;
                imui_height = 0;
                return lresult;
            }
            
            /* set softkey to null */
            for (i = 0; i < WGUI_MAX_SOFTKEYS; i++)
            {
                set_softkey_label(NULL, (WGUI_SOFTKEY_ENUM)i);
                set_softkey_icon(NULL, (WGUI_SOFTKEY_ENUM)i);
                set_softkey_function(NULL, KEY_EVENT_DOWN, (WGUI_SOFTKEY_ENUM)i);
            }

            /* enable softkey text display, or text wont be showed if app set softkey after receiving deactivate msg */
            set_softkey_flags_off(UI_BUTTON_DISABLE_TEXT_DISPLAY, MMI_LEFT_SOFTKEY);
            set_softkey_flags_off(UI_BUTTON_DISABLE_TEXT_DISPLAY, MMI_RIGHT_SOFTKEY);
            set_softkey_flags_off(UI_BUTTON_DISABLE_TEXT_DISPLAY, MMI_CENTER_SOFTKEY);
            enable_softkey_background();
            break;
        case MMI_IMC_MESSAGE_IMUI_RECTANGLE_IS_UPDATED:
            /* if imui height not change, return */
            if (imui_height == ((mmi_imc_rect*)msg_ptr->param_0)->height)
            {
                return lresult;
            }
            else
            {
                /* if changed, pass to app */
                imui_height = ((mmi_imc_rect*)msg_ptr->param_0)->height;
                msg_ptr->param_1 = msg_ptr->param_0;
            }
            break;
        case MMI_IMC_MESSAGE_PEN_EVENT:
            if (g_current_active_editor != NULL)
            {
                lresult = g_current_active_editor->ime_msg_callback(g_current_active_editor, msg_ptr);
                if (lresult)
                    return 1;
            }
        default:
        {
            /* editor handles msg like: insert/delete..., do not pass to app or mre */
            if (((mmi_editor_handler_struct *)input_box_handle)->input_box_type == MMI_EDITOR_SINGLE_LINE_INPU_BOX)
            {
                return wgui_editor_msg_call_back_single_line(input_box_handle, msg_ptr);
            }
            else
            {
                return wgui_editor_msg_call_back_multi_line(input_box_handle, msg_ptr);
            }
        }
    }

    /* pass the msg(redraw/set_key/activate/deactivate/IMUI) to app or mre */
    if (g_current_active_editor != NULL)
    {
        lresult = g_current_active_editor->ime_msg_callback(g_current_active_editor, msg_ptr);
    }

    /* after pass, do something */
    switch (msg_ptr->message_id)
    {
        case MMI_IMC_MESSAGE_REDRAW:
            /* after app redraw, need to call this, if there is softkey, will redraw last */
            wgui_editor_redraw_softkey();
            break;
        case MMI_IMC_MESSAGE_SET_KEY:
            if (g_current_active_editor && !(g_current_active_editor->is_disable_softkey))
            {
                int i;
                for (i = 0; i < WGUI_MAX_SOFTKEYS; i++)
                {
                    set_softkey_label(g_current_active_editor->softkey_label[i], (WGUI_SOFTKEY_ENUM)i);
                    set_softkey_icon(g_current_active_editor->softkey_icon[i], (WGUI_SOFTKEY_ENUM)i);
                    set_softkey_function(g_current_active_editor->softkey_handle[i], KEY_EVENT_DOWN, (WGUI_SOFTKEY_ENUM)i);              
                    register_softkey_handler((WGUI_SOFTKEY_ENUM)i);

                    set_softkey_function(NULL, KEY_EVENT_UP, (WGUI_SOFTKEY_ENUM)i); //clear all up handler
                }
                wgui_editor_handle_input();
            }
            break;
        case MMI_IMC_MESSAGE_ACTIVATE:            
            break;
        case MMI_IMC_MESSAGE_DEACTIVATE:            
            /* after deactivate, send set_key msg to app or mre to set key handler */
            if (g_current_active_editor != NULL)
            {
                mmi_imc_message_struct msg;
                msg.message_id = MMI_IMC_MESSAGE_SET_KEY;
                msg.param_0 = msg.param_1 = 0;
                lresult = g_current_active_editor->ime_msg_callback(g_current_active_editor, &msg);
            }
            /* after deactivate, reset imui_height */
            imui_height = 0;
            break;
        case MMI_IMC_MESSAGE_IMUI_RECTANGLE_IS_UPDATED:
            if (ime_floating_indicator_flag)
            {
                /* draw ime floating indicator, case: when touch to  hide vk, the indicator not show */
                mmi_imc_draw_indicator_floating(MMI_TRUE);
            }
            break;
    }    

    return lresult;
}

/*****************************************************************************
* FUNCTION
*  wgui_editor_msg_call_back_single_line
* DESCRIPTION
*  message call back funtion by default (singleline)
* PARAMETERS
* void        
* RETURNS
*  void
*****************************************************************************/
static U32 wgui_editor_msg_call_back_single_line(void * input_box_handle, mmi_imc_message_struct_p msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    single_line_input_box * editor_ptr;
    MMI_BOOL ret = MMI_FALSE;
    S32 i, str_len, total_len = 0;
    U32 lresult = 0;
    UI_string_type temp_str;

#if defined(__MMI_TOUCH_SCREEN__)
    gui_single_line_input_box_pen_enum single_line_input_box_event;
#endif

#ifdef __MMI_EDITOR_SSP_SUPPORT__
    MMI_BOOL is_ssp = MMI_FALSE;
#endif /* __MMI_EDITOR_SSP_SUPPORT__ */

    U32 old_show_action_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_ptr = (single_line_input_box *)((mmi_editor_handler_struct *)input_box_handle)->input_box_handler;

    MMI_ASSERT(editor_ptr == (single_line_input_box *)g_current_active_editor->editor);

    switch (msg_ptr->message_id)
    {
    case MMI_IMC_MESSAGE_IS_EDITOR_EMPTY:
        if (editor_ptr->text_length <= 2)
        {
            lresult = 1;
        }
        break;

    case MMI_IMC_MESSAGE_INSERT_CHAR:
        ret = gui_single_line_input_box_insert_character(editor_ptr, (UI_character_type)msg_ptr->param_0);    
        if (ret == MMI_FALSE)//?
        {
            gui_single_line_input_box_locate_cursor(editor_ptr);
        }        
        wgui_editor_handle_input();

        //redraw editor
        wgui_editor_redraw_active_editor();

        //app might draw some icon on top of the editor in the callbackfunction
        wgui_editor_update_text_with_cursor_rect_callback();
        
        lresult = ret;        
        break;

    case MMI_IMC_MESSAGE_INSERT_SPACE:
        ret = gui_single_line_input_box_insert_character(editor_ptr, (UI_character_type)(0x20));    
        if (ret == MMI_FALSE)//?
        {
            gui_single_line_input_box_locate_cursor(editor_ptr);
        }
        
        wgui_editor_handle_input();
        
        //redraw editor
        wgui_editor_redraw_active_editor();

        //app might draw some icon on top of the editor in the callbackfunction
        wgui_editor_update_text_with_cursor_rect_callback();
        
        lresult = ret;
        break;

    case MMI_IMC_MESSAGE_INSERT_STRING:
    case MMI_IMC_MESSAGE_INSERT_STRING_NO_DRAW: 
        temp_str = (UI_string_type)msg_ptr->param_0;        
        str_len = (S32)mmi_ucs2strlen((const S8 *)temp_str);

        old_show_action_flag = editor_ptr->show_action_flag;        
        editor_ptr->show_action_flag = 0;

        for (i = 0; i < str_len; i++)
        {
            if (gui_single_line_input_box_insert_character(editor_ptr, (UI_character_type)temp_str[i]))
            {
                total_len ++;
            }
            else
            {
                break;
            }
        }

        editor_ptr->show_action_flag = old_show_action_flag;        

        gui_single_line_input_box_locate_cursor(editor_ptr);        
        
        wgui_editor_handle_input();
        
        //redraw editor
        wgui_editor_redraw_active_editor();

        //app might draw some icon on top of the editor in the callbackfunction
        wgui_editor_update_text_with_cursor_rect_callback();
        
        lresult = total_len;        
        break;

    case MMI_IMC_MESSAGE_REPLACE_HIGHLIGHT_STRING:
        old_show_action_flag = editor_ptr->show_action_flag;        
        editor_ptr->show_action_flag = 0;

        for (i = 0; i < (S32)(msg_ptr->param_0); i ++)
        {
            gui_single_line_input_box_delete_character(editor_ptr);
        }

        temp_str = (UI_string_type)msg_ptr->param_1;        
        str_len = (S32)mmi_ucs2strlen((const S8 *)temp_str);

        for (i = 0; i < str_len; i++)
        {
            if (gui_single_line_input_box_insert_character(editor_ptr, (UI_character_type)temp_str[i]))
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
            editor_ptr->flags |= UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
            gui_single_line_input_box_highlight_cursor_number(editor_ptr, (S32)total_len);
        }
        else
        {
            /* if no character gets inserted , no character will be highlighted*/
            editor_ptr->flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        }

        wgui_editor_handle_input();
        
        //redraw editor
        wgui_editor_redraw_active_editor();
        
        lresult = total_len;		
        break;

    case MMI_IMC_MESSAGE_DELETE_STRING:
        old_show_action_flag = editor_ptr->show_action_flag;        
        editor_ptr->show_action_flag = 0;

        for (i = 0; i < (S32)(msg_ptr->param_0); i ++)
        {
            gui_single_line_input_box_delete_character(editor_ptr);
        }

        editor_ptr->show_action_flag = old_show_action_flag;
        gui_single_line_input_box_locate_cursor(editor_ptr); 

        wgui_editor_handle_input();
        if (!msg_ptr->param_1)//?
        {            
            //redraw editor
            wgui_editor_redraw_active_editor();

            //app might draw some icon on top of the editor in the callbackfunction
            wgui_editor_update_text_with_cursor_rect_callback();
        }
        
        break;

    case MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR:        
        gui_single_line_input_box_insert_multitap_character(editor_ptr, (UI_character_type)msg_ptr->param_0);
        wgui_editor_handle_input();
        wgui_editor_redraw_active_editor(); 
       
        lresult = ret;
        break;

    case MMI_IMC_MESSAGE_INSERT_MULTITAP_STRING:       
        /* Insert the string in editor */
        total_len = gui_single_line_input_box_insert_multitap_string(editor_ptr, (UI_string_type)msg_ptr->param_0);
        gui_single_line_input_box_locate_cursor(editor_ptr);
        
        wgui_editor_handle_input();
        wgui_editor_redraw_active_editor(); 
        lresult = total_len;
        break;

    case MMI_IMC_MESSAGE_RESET_MULTITAP_STATE:
        gui_single_line_input_box_confirm_multitap_character(editor_ptr);
        wgui_editor_redraw_active_editor(); 
        gui_single_line_input_box_stop_input(editor_ptr);

        //app might draw some icon on top of the editor in the callbackfunction
        wgui_editor_update_text_with_cursor_rect_callback();
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
        for (i = 0; i < (S32)msg_ptr->param_0; i++)
        {
            gui_single_line_input_box_delete_character(editor_ptr);
        }
        
        wgui_editor_handle_input();
        
        //redraw editor
        wgui_editor_redraw_active_editor();

        //app might draw some icon on top of the editor in the callbackfunction
        wgui_editor_update_text_with_cursor_rect_callback();
        break;

    case MMI_IMC_MESSAGE_CLEAR_ALL:
        if (MMI_TRUE == gui_single_line_input_box_delete_all(editor_ptr))
        {
            gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_HOLD);
        }
        
        wgui_editor_handle_input();
        wgui_editor_redraw_active_editor();
        //app might draw some icon on top of the editor in the callbackfunction
        wgui_editor_update_text_with_cursor_rect_callback();
        break;

    case MMI_IMC_MESSAGE_BACKSPACE_KEY_EVENT:
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
        switch (msg_ptr->param_0)
        {    
        case MMI_IMC_EDITOR_CURSOR_LEFT:
            for (i = 0; i <(S32)msg_ptr->param_1; i ++)
            {
                gui_single_line_input_box_previous(editor_ptr);           
            }
            break;

        case MMI_IMC_EDITOR_CURSOR_RIGHT:
            for (i = 0; i <(S32)msg_ptr->param_1; i ++)
            {
                gui_single_line_input_box_next(editor_ptr);
            }
            break;
        }
        wgui_editor_redraw_active_editor(); 
        break;

    case MMI_IMC_MESSAGE_INSERT_PAIRED_SYMBOLS:
        temp_str = (UI_string_type)msg_ptr->param_0;

        str_len = (S32)mmi_ucs2strlen((const S8 *)temp_str);

        for (i = 0; i < str_len; i++)
        {
            if (gui_single_line_input_box_insert_character(editor_ptr, (UI_character_type)temp_str[i]))
            {
                total_len ++;
            }
            else
            {
                break;
            }
        }

        if (total_len == str_len)
        {
            gui_single_line_input_box_previous(editor_ptr);
            lresult = MMI_TRUE;
        }
        else
        {
            lresult = MMI_FALSE;
        }
        
        wgui_editor_handle_input();
        wgui_editor_redraw_active_editor();
        //app might draw some icon on top of the editor in the callbackfunction
        wgui_editor_update_text_with_cursor_rect_callback();
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
        wgui_editor_redraw_active_editor(); 
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

    case MMI_IMC_MESSAGE_SET_KEY:
        set_right_softkey_label((UI_string_type)get_string(STR_GLOBAL_CLEAR));
        set_right_softkey_icon(NULL);
        set_right_softkey_function(wgui_editor_handle_right_softkey, KEY_EVENT_DOWN); 
        redraw_right_softkey();
        break;
    case MMI_IMC_MESSAGE_FLOATING_UI_APPEAR_INDICATION:
        break;

    case MMI_IMC_MESSAGE_UPDATE_SOFTKEY:
        break;
    case MMI_IMC_MESSAGE_KEY_EVENT:
        break;
    case MMI_IMC_MESSAGE_MODE_CHANGED:        
        break;
#if defined(__MMI_TOUCH_SCREEN__)
    case MMI_IMC_MESSAGE_GET_HANDWRITING_RECT:
        ((mmi_imc_rect_p)msg_ptr->param_0)->x = MMI_content_x;
        ((mmi_imc_rect_p)msg_ptr->param_0)->y = MMI_content_y;
        ((mmi_imc_rect_p)msg_ptr->param_0)->width = MMI_content_width;
        ((mmi_imc_rect_p)msg_ptr->param_0)->height = MMI_content_height - mmi_imc_get_current_imui_height_skip_fixed_editor();            
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

                ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->editor_pen_event = (mmi_imc_editor_pen_event_enum)single_line_input_box_event;

                if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_UP)
                {
                    /* Locate cursor at pen up position */
                    gui_show_single_line_input_box_ext(editor_ptr, 
                        ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.x, 
                        ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.y);

                    gui_single_line_input_box_locate_cursor(editor_ptr); 
                    
                    /* will redraw app screen */
                    wgui_editor_redraw_active_editor(); 
                }
                else if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_LONG_TAP ||
                    ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_DOWN)
                {                    
                    *((U32 *)msg_ptr->param_1) = 1;
                } 
            }
        }
        lresult = ret;
        break;

    case MMI_IMC_MESSAGE_GET_HANDWRITING_STYLE:
        lresult = MMI_IMC_PEN_HANDWRITING_STYLE_FULL_SCREEN;
        break;


#endif /* defined(__MMI_TOUCH_SCREEN__) */
    case MMI_IMC_MESSAGE_SET_MASK:
        editor_ptr->flags |= UI_SINGLE_LINE_INPUT_BOX_MASK_CHARACTERS;
        break;    
    case MMI_IMC_MESSAGE_CHECK_MULTITAP_STATE:
        if (editor_ptr->flags & UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP)
            lresult = MMI_TRUE;
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

    case MMI_IMC_MESSAGE_SET_MULTITAP_STATE:
        editor_ptr->flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP;
        break; 

    case MMI_IMC_MESSAGE_INSERT_CHAR_AT_DESIRED_POSITION:
        gui_single_line_input_box_insert_character_in_pos(editor_ptr, (UI_character_type)msg_ptr->param_1, msg_ptr->param_0);
        wgui_editor_redraw_active_editor(); 
        break;

    case MMI_IMC_MESSAGE_DELETE_CHAR_AT_DESIRED_POSITION:
        gui_single_line_input_box_delete_character_in_pos(editor_ptr, msg_ptr->param_0);     
        wgui_editor_redraw_active_editor(); 
        break;

    case MMI_IMC_MESSAGE_GET_CHAR_AT_DESIRED_POSITION:
        lresult = editor_ptr->text[msg_ptr->param_0];
        break;

    case MMI_IMC_MESSAGE_HAS_SSP_ACTED:
#if defined(__MMI_EDITOR_SSP_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        lresult = gui_input_box_ssp_is_scrolling();
#endif
        break;

    case MMI_IMC_MESSAGE_IS_SOFTKEY_HIDE:
        lresult = g_current_active_editor->is_disable_softkey;
        break;

    default:
        break;
    }
    UI_UNUSED_PARAMETER(ret);
    return lresult;
}

/*****************************************************************************
* FUNCTION
*  wgui_editor_msg_call_back_multi_line
* DESCRIPTION
*  multiline message call back funtion by default (multiline)
* PARAMETERS
* void        
* RETURNS
*  void
*****************************************************************************/
static U32 wgui_editor_msg_call_back_multi_line(void * input_box_handle, mmi_imc_message_struct_p msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_TOUCH_SCREEN__)
    gui_multi_line_input_box_pen_enum input_box_event = GUI_MULTI_LINE_INPUT_BOX_PEN_NONE;
#endif
    multi_line_input_box * editor_ptr;

    MMI_BOOL ret = MMI_FALSE;
    S32 i, str_len, total_len = 0;
    U32 lresult = 0;
    UI_string_type temp_str;
    UI_character_type ch;
    U32 old_show_action_flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    editor_ptr = (multi_line_input_box *)((mmi_editor_handler_struct *)input_box_handle)->input_box_handler;

    MMI_ASSERT(editor_ptr == (multi_line_input_box *)g_current_active_editor->editor);

    switch (msg_ptr->message_id)
    {
    case MMI_IMC_MESSAGE_INSERT_CHAR:

#ifdef __MMI_EDITOR_SSP_SUPPORT__
        {
            mmi_pen_point_struct point = {0, 0};

            gui_input_box_ssp_pen_translate(point, MMI_PEN_EVENT_ABORT);
        }
#endif
        ch = (UI_character_type)msg_ptr->param_0;
        if (UI_TEST_LF_CHARACTER(ch))
        {
            lresult = gui_multi_line_input_box_insert_newline(editor_ptr);            
        }
        else
        {
            lresult = gui_multi_line_input_box_insert_character(editor_ptr, ch);
        }
        wgui_editor_handle_input();
        wgui_editor_redraw_active_editor();
        //app might draw some icon on top of the editor in the callbackfunction
        wgui_editor_update_text_with_cursor_rect_callback();
        break;

    case MMI_IMC_MESSAGE_INSERT_STRING:

#ifdef __MMI_EDITOR_SSP_SUPPORT__
        {
            mmi_pen_point_struct point = {0, 0};

            gui_input_box_ssp_pen_translate(point, MMI_PEN_EVENT_ABORT);
        }
#endif

        temp_str = (UI_string_type)msg_ptr->param_0;        
        str_len = (S32)mmi_ucs2strlen((const S8 *)temp_str);

        old_show_action_flag = editor_ptr->show_action_flag;
        editor_ptr->show_action_flag = 0;

        for (i = 0; i < str_len && temp_str[i] != 0; i++)
        {
            if (UI_TEST_LF_CHARACTER(temp_str[i]))
            {
                ret = gui_multi_line_input_box_insert_newline(editor_ptr);            
            }
            else
            {
                ret = gui_multi_line_input_box_insert_character(editor_ptr, temp_str[i]);
            }
            if (ret)
            {
                total_len ++;
            }
            else
            {
                break;
            }			
        }       

        editor_ptr->show_action_flag = old_show_action_flag;

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
        if (str_len > 10)
        {
            gui_mlc_all_line_update();
        }
#endif            
        wgui_editor_handle_input();
        wgui_editor_redraw_active_editor();
        //app might draw some icon on top of the editor in the callbackfunction
        wgui_editor_update_text_with_cursor_rect_callback();
        lresult = total_len;        
        break;

    case MMI_IMC_MESSAGE_INSERT_STRING_NO_DRAW:

        temp_str = (UI_string_type)msg_ptr->param_0;

        str_len = (S32)mmi_ucs2strlen((const S8 *)temp_str);

        for (i = 0; i < str_len; i++)//?
        {
            if (UI_TEST_LF_CHARACTER(temp_str[i]))
            {
                ret = gui_multi_line_input_box_insert_newline(editor_ptr);            
            }
            else
            {
                ret = gui_multi_line_input_box_insert_character(editor_ptr, temp_str[i]);
            }
            if (ret)
            {
                total_len ++;
            }
            else
            {
                break;
            }
        }
        lresult = total_len;
        break;

    case MMI_IMC_MESSAGE_REPLACE_HIGHLIGHT_STRING:

        old_show_action_flag = editor_ptr->show_action_flag;
        editor_ptr->show_action_flag = 0;

        for (i = 0; i < (S32)msg_ptr->param_0; i ++)
        {
            gui_multi_line_input_box_delete_character(editor_ptr);
        }

        temp_str = (UI_string_type)msg_ptr->param_1;		
        str_len = (S32)mmi_ucs2strlen((const S8 *)temp_str);		
        for (i = 0; i < str_len; i++)
        {
            if (UI_TEST_LF_CHARACTER(temp_str[i]))
            {
                ret = gui_multi_line_input_box_insert_newline(editor_ptr);            
            }
            else
            {
                ret = gui_multi_line_input_box_insert_character(editor_ptr, temp_str[i]);
            }
            if (ret)
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
            gui_multi_line_input_box_highlight_cursor_number(editor_ptr, (S32)total_len);
        }
        else
        {
            /* if no character gets inserted , no character will be highlighted*/
            editor_ptr->flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
            editor_ptr->highlight_start_position = NULL;
            editor_ptr->highlight_end_position = NULL;
        }

        wgui_editor_handle_input();
        wgui_editor_redraw_active_editor(); 
        lresult = total_len;
        break;
    case MMI_IMC_MESSAGE_SET_KEY:
        set_right_softkey_label((UI_string_type)get_string(STR_GLOBAL_CLEAR));
        set_right_softkey_icon(NULL);
        set_right_softkey_function(wgui_editor_handle_right_softkey, KEY_EVENT_DOWN);  
        redraw_right_softkey();
        break;
    case MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC:
        gui_multi_line_input_box_stop_input(editor_ptr);
        break;

    case MMI_IMC_MESSAGE_START_SMART_ALPHABETIC:
        gui_multi_line_input_box_start_input(editor_ptr);
        break;

    case MMI_IMC_MESSAGE_GET_HIGHLIGHT_WORD:
        if (editor_ptr->flags & UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT)
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
        if (editor_ptr->flags & UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT)
        {
            UI_buffer_type words_start_p = editor_ptr->highlight_start_position;
            UI_buffer_type old_cursor_p = editor_ptr->cursor_p;    
            UI_character_type c;

            editor_ptr->cursor_p = words_start_p;

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
            gui_mlc_all_line_update();
#endif

            gui_show_multi_line_input_box_ext(editor_ptr, -1, -1);

            if (old_cursor_p != editor_ptr->cursor_p)
            {
                editor_ptr->cursor_fixed_x = -1;
            }

            while (words_start_p > editor_ptr->text) /* Go to the end of the previous word */
            {
                c = (UI_character_type)((*((words_start_p - 2)+0))|((*((words_start_p - 2)+1))<<8));

                if (c == 0x20) 
                {
                    gui_multi_line_input_box_previous(editor_ptr);

                    words_start_p = editor_ptr->cursor_p;
                }
                else
                {
                    break;
                }
            }

            lresult = 1;
        }
        break;

    case MMI_IMC_MESSAGE_DELETE_STRING:
        old_show_action_flag = editor_ptr->show_action_flag;

        editor_ptr->show_action_flag = 0;

        for (i = 0; i < (S32)msg_ptr->param_0; i ++)
        {
            gui_multi_line_input_box_delete_character(editor_ptr);
        }

        editor_ptr->show_action_flag = old_show_action_flag;

        wgui_editor_handle_input();

        if (!msg_ptr->param_1)
        {
            wgui_editor_redraw_active_editor();
            //app might draw some icon on top of the editor in the callbackfunction
            wgui_editor_update_text_with_cursor_rect_callback();
        }

        break;

    case MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR:
        ch = (UI_character_type)msg_ptr->param_0;
        lresult = gui_multi_line_input_box_insert_multitap_character(editor_ptr, ch);

        wgui_editor_handle_input();
        if (lresult)
        {
            wgui_editor_redraw_active_editor(); 
        }
        break;

    case MMI_IMC_MESSAGE_INSERT_MULTITAP_STRING:
        temp_str = (UI_string_type)msg_ptr->param_0;
        /* Insert the string in editor */
        lresult = gui_multi_line_input_box_insert_multitap_string(editor_ptr, (PU8)temp_str);
        wgui_editor_handle_input();
        if (lresult)
        {
            wgui_editor_redraw_active_editor(); 
        }
        break;

    case MMI_IMC_MESSAGE_RESET_MULTITAP_STATE:
        gui_multi_line_input_box_confirm_multitap_character(editor_ptr);
        wgui_editor_redraw_active_editor(); 
        gui_multi_line_input_box_stop_input(editor_ptr);
        //app might draw some icon on top of the editor in the callbackfunction
        wgui_editor_update_text_with_cursor_rect_callback();
        break;

    case MMI_IMC_MESSAGE_DELETE_CHAR:
        for (i = 0; i < (S32)msg_ptr->param_0; i++)
        {
            gui_multi_line_input_box_delete_character(editor_ptr);
        }        
       
        wgui_editor_handle_input();
        wgui_editor_redraw_active_editor(); 
        //app might draw some icon on top of the editor in the callbackfunction
        wgui_editor_update_text_with_cursor_rect_callback();
        break;

    case MMI_IMC_MESSAGE_CLEAR_ALL:
        gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_HOLD);
        gui_multi_line_input_box_delete_all(editor_ptr);
        wgui_editor_handle_input();
        wgui_editor_redraw_active_editor();
        //app might draw some icon on top of the editor in the callbackfunction
        wgui_editor_update_text_with_cursor_rect_callback();
        break;

    case MMI_IMC_MESSAGE_GET_CURSOR_RECT:
        ((mmi_imc_rect_p)msg_ptr->param_0)->x = UI_cursor_x1;
        ((mmi_imc_rect_p)msg_ptr->param_0)->y = UI_cursor_y1;
        ((mmi_imc_rect_p)msg_ptr->param_0)->width = UI_cursor_x2 - UI_cursor_x1 + 1;
        ((mmi_imc_rect_p)msg_ptr->param_0)->height = UI_cursor_y2 - UI_cursor_y1 + 1;
        lresult = MMI_TRUE;
        break;

    case MMI_IMC_MESSAGE_MOVE_CURSOR:
        switch (msg_ptr->param_0)
        {
        case MMI_IMC_EDITOR_CURSOR_UP:
            for (i = 0; i <(S32)msg_ptr->param_1; i ++)
            {
                gui_multi_line_input_box_previous_line(editor_ptr);
            }
            wgui_editor_redraw_active_editor(); 
            break;
        case MMI_IMC_EDITOR_CURSOR_DOWN:
            for (i = 0; i <(S32)msg_ptr->param_1; i ++)
            {
                gui_multi_line_input_box_next_line(editor_ptr);
            }
            wgui_editor_redraw_active_editor(); 
            break;
        case MMI_IMC_EDITOR_CURSOR_LEFT:
            for (i = 0; i <(S32)msg_ptr->param_1; i ++)
            {
                gui_multi_line_input_box_previous(editor_ptr);
                wgui_editor_redraw_active_editor(); 
            }
            break;
        case MMI_IMC_EDITOR_CURSOR_RIGHT:
            for (i = 0; i <(S32)msg_ptr->param_1; i ++)
            {
                gui_multi_line_input_box_next(editor_ptr);
                wgui_editor_redraw_active_editor(); 
            }
            break;
        }

        break;
    case MMI_IMC_MESSAGE_IS_THERE_CURSOR:
        if (editor_ptr->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW)
        {
            lresult = MMI_FALSE;
        }
        else
        {
            lresult = MMI_TRUE;
        }
        break;	
    case MMI_IMC_MESSAGE_HILIGHT_BFCURSOR:
        gui_multi_line_input_box_highlight_cursor_number(editor_ptr, (S32)msg_ptr->param_0);
        wgui_editor_redraw_active_editor(); 
        break;
    case MMI_IMC_MESSAGE_CLEAR_HILIGHT:
        editor_ptr->flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        editor_ptr->highlight_start_position = NULL;
        editor_ptr->highlight_end_position = NULL;
        break;
    case MMI_IMC_MESSAGE_GET_INPUT_BOX_RECT:
        ((mmi_imc_rect_p)msg_ptr->param_0)->x = editor_ptr->x;
        ((mmi_imc_rect_p)msg_ptr->param_0)->y = editor_ptr->y;
        ((mmi_imc_rect_p)msg_ptr->param_0)->width = editor_ptr->width;
        ((mmi_imc_rect_p)msg_ptr->param_0)->height = editor_ptr->height;
        break; 
    case MMI_IMC_MESSAGE_FLOATING_UI_APPEAR_INDICATION:
        break;

    case MMI_IMC_MESSAGE_UPDATE_SOFTKEY:
        break;

    case MMI_IMC_MESSAGE_IS_SOFTKEY_HIDE:
        lresult = g_current_active_editor->is_disable_softkey;
        break;
    case MMI_IMC_MESSAGE_KEY_EVENT:
        break;        

#if defined(__MMI_TOUCH_SCREEN__)
    case MMI_IMC_MESSAGE_GET_HANDWRITING_RECT:
        if (mmi_fe_get_r2l_state())
        {
            ((mmi_imc_rect_p)msg_ptr->param_0)->x = editor_ptr->x + editor_ptr->vbar.width;
        }
        else
        {
            ((mmi_imc_rect_p)msg_ptr->param_0)->x = editor_ptr->x;
        }
        ((mmi_imc_rect_p)msg_ptr->param_0)->y = editor_ptr->y;
        ((mmi_imc_rect_p)msg_ptr->param_0)->width = editor_ptr->width - editor_ptr->vbar.width;
        ((mmi_imc_rect_p)msg_ptr->param_0)->height = editor_ptr->height;
        break;

    case MMI_IMC_MESSAGE_PEN_EVENT:
        {            
            ret = (MMI_BOOL)gui_multi_line_input_box_translate_pen_event(
                editor_ptr,
                ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event,
                ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.x,
                ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.y,
                &input_box_event);         

            if (ret)
            {
                U8* old_cursor_p = editor_ptr->cursor_p;
                ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->editor_pen_event = (mmi_imc_editor_pen_event_enum)input_box_event;

                if (GUI_MULTI_LINE_INPUT_BOX_PEN_SCROLL_BAR != input_box_event 
                    && GUI_MULTI_LINE_INPUT_BOX_PEN_CONTROL_AREA != input_box_event
                    && ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_DOWN)
                {
                    MMI_BOOL is_disabled_drawing = (MMI_BOOL)(editor_ptr->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW);

                    if (!is_disabled_drawing)
                    {
                        editor_ptr->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
                    }

                    gui_show_multi_line_input_box_ext(editor_ptr, 
                        ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.x, 
                        ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.y);

                    if (!is_disabled_drawing)
                    {
                        editor_ptr->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
                    }

                    g_wgui_inputs_ml_pen_down_cursor_p = editor_ptr->cursor_p;
                    editor_ptr->cursor_p = old_cursor_p;
                        
                    /* Lock frame buffer to prevent cursor flash when pen down */
#if (UI_DOUBLE_BUFFER_SUPPORT)
                    gui_lock_double_buffer();
#endif
                    editor_ptr->ext_flags |= GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
                    editor_ptr->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
                    gui_show_multi_line_input_box(editor_ptr);
                    editor_ptr->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
                    editor_ptr->ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
#if (UI_DOUBLE_BUFFER_SUPPORT)
                    gui_unlock_double_buffer();
#endif
                    *((U32 *)msg_ptr->param_1) = 1;
                }
                else if (GUI_MULTI_LINE_INPUT_BOX_PEN_SCROLL_BAR != input_box_event 
                             && GUI_MULTI_LINE_INPUT_BOX_PEN_CONTROL_AREA != input_box_event
							 && ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_UP)
				{
					if (g_wgui_inputs_ml_pen_down_cursor_p)
					{
						editor_ptr->cursor_p = g_wgui_inputs_ml_pen_down_cursor_p;
						g_wgui_inputs_ml_pen_down_cursor_p = NULL;
					    
                        wgui_editor_redraw_active_editor();
					    msg_ptr->param_1 = 1;
				    }
				}
				else if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_MOVE)
				{
					g_wgui_inputs_ml_pen_down_cursor_p = NULL;
				}
            }


            lresult = ret;

            break;
        }
    case MMI_IMC_MESSAGE_GET_HANDWRITING_STYLE:        
#if defined(__MMI_HANDWRITING_MULTI_BLOCK__)
        lresult = MMI_IMC_PEN_HANDWRITING_STYLE_MULTI_BLOCK;        
#else
        lresult = MMI_IMC_PEN_HANDWRITING_STYLE_FULL_SCREEN;
#endif

        break;

#endif
    case MMI_IMC_MESSAGE_INSERT_NEW_LINE:
        gui_multi_line_input_box_insert_newline(editor_ptr);
        wgui_editor_handle_input();
        wgui_editor_redraw_active_editor(); 
        break;

    case MMI_IMC_MESSAGE_IS_EDITOR_EMPTY:
        if (editor_ptr->text_length <= 2)
        {
            lresult = 1;
        }
        break;

    case MMI_IMC_MESSAGE_GET_PREVIOUS_CHAR:
        lresult = gui_multi_line_input_box_get_previous_character(editor_ptr, (UI_character_type *)msg_ptr->param_0);
        break;

    case MMI_IMC_MESSAGE_GET_TEXT_LENGTH:
        lresult = (U32)(editor_ptr->text_length / ENCODING_LENGTH);
        break;

    case MMI_IMC_MESSAGE_SET_MASK:
        editor_ptr->flags |= UI_MULTI_LINE_INPUT_BOX_MASK_CHARACTERS;

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
        gui_mlc_change_request(0);
#endif
        break;    

    case MMI_IMC_MESSAGE_INSERT_PAIRED_SYMBOLS:
        temp_str = (UI_string_type)msg_ptr->param_0;

        str_len = (S32)mmi_ucs2strlen((const S8 *)temp_str);

        for (i = 0; i < str_len && temp_str[i] != 0; i++)
        {

            if (UI_TEST_LF_CHARACTER(temp_str[i]))
            {
                ret = gui_multi_line_input_box_insert_newline(editor_ptr);            
            }
            else
            {
                ret = gui_multi_line_input_box_insert_character(editor_ptr, temp_str[i]);
            }
            if (ret)
            {
                total_len ++;
            }
            else
            {
                break;
            }
        }

        if (total_len == str_len)
        {
            gui_multi_line_input_box_previous(editor_ptr);
            lresult = MMI_TRUE;
        }
        else
        {
            lresult = MMI_FALSE;
        }
        wgui_editor_handle_input();
        wgui_editor_redraw_active_editor(); 
        break;

    case MMI_IMC_MESSAGE_IS_OVERWRITE_MODE:
        if ((editor_ptr->flags & UI_MULTI_LINE_INPUT_BOX_OVERWRITE_MODE)	
            || (editor_ptr->flags & UI_MULTI_LINE_INPUT_BOX_MASK_CHARACTERS))
        {
            lresult = MMI_TRUE;
        }
        else
        {	
            lresult = MMI_FALSE;
        }
        break;

    case MMI_IMC_MESSAGE_IS_EDITOR_IN_REPLACE_MODE:
    case MMI_IMC_MESSAGE_CHECK_MULTITAP_STATE:        
        if (editor_ptr->flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP)
            lresult = MMI_TRUE;
        break;  

    case MMI_IMC_MESSAGE_CHECK_CSK_ENABLE:
        break;

    case MMI_IMC_MESSAGE_CHECK_INFO_BAR_ENABL:
        lresult = MMI_TRUE;
        break;

    case MMI_IMC_MESSAGE_GET_TEXT_PTR_BEFORE_CANDIDATE:        
        if (editor_ptr->flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP)
        {
            *((U8 **)(msg_ptr->param_1)) = (U8 *)editor_ptr->cursor_p - 2;
        }
        else if (editor_ptr->flags & UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT)
        {
            *((U8 **)(msg_ptr->param_1)) = (U8 *)editor_ptr->highlight_start_position;
        }
        else
        {
            *((U8 **)(msg_ptr->param_1)) = (U8 *)editor_ptr->cursor_p;
        }

        *((U8 **)(msg_ptr->param_0)) = (U8 *)editor_ptr->text;
        break;

    case MMI_IMC_MESSAGE_GET_TEXT_PTR_BEFORE_CURSOR:
        *((U8 **)(msg_ptr->param_1)) = (U8 *)editor_ptr->cursor_p;
        *((U8 **)(msg_ptr->param_0)) = (U8 *)editor_ptr->text;
        break;

    case MMI_IMC_MESSAGE_GET_STRING_BEFORE_CANDIDATE:
        /* if editor is in multitap state. */
        ///TODO: extend the function to get prevoious n character.
        if (editor_ptr->flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP)
        {
            UI_string_type buf = (UI_string_type)msg_ptr->param_1;
            UI_buffer_type backup_cursor_p = editor_ptr->cursor_p;

            i = 0;

            editor_ptr->cursor_p = editor_ptr->input_start_cursor_p;
            while (msg_ptr->param_0)
            {
                if (gui_multi_line_input_box_get_previous_character(editor_ptr, (UI_character_type*)&buf[i]))
                {
                    msg_ptr->param_0 --;
                    i ++;
                    editor_ptr->cursor_p -= ENCODING_LENGTH;
                }
                else
                {
                    break;
                }
            }

            editor_ptr->cursor_p = backup_cursor_p;

            return i;
        }
        else if ((editor_ptr->flags & UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT)
                  &&(editor_ptr->ext_flags & GUI_MULTI_LINE_INPUT_BOX_INPUT_METHOD_MODE))
        {
            UI_string_type buf = (UI_string_type)msg_ptr->param_1;
            UI_buffer_type backup_cursor_p = editor_ptr->cursor_p;

            /* move cursor to the begining of the highlight */
            editor_ptr->cursor_p = editor_ptr->highlight_start_position;
            i = 0;
            while (msg_ptr->param_0)
            {
                if (gui_multi_line_input_box_get_previous_character(editor_ptr, (UI_character_type *)&buf[i]))
                {
                    msg_ptr->param_0 --;
                    i ++;
                    editor_ptr->cursor_p -= ENCODING_LENGTH;
                }
                else
                {
                    break;
                }
            }
            /* restore cursor to the begining of the highlight */
            editor_ptr->cursor_p = backup_cursor_p;
            return i;
        }
        else
        {
            UI_string_type buf = (UI_string_type)msg_ptr->param_1;
            UI_buffer_type backup_cursor_p = editor_ptr->cursor_p;
            i = 0;
            while (msg_ptr->param_0)
            {
                if (gui_multi_line_input_box_get_previous_character(editor_ptr, (UI_character_type *)&buf[i]))
                {
                    msg_ptr->param_0 --;
                    i ++;
                    editor_ptr->cursor_p -= ENCODING_LENGTH;
                }
                else
                {
                    break;
                }
            }
            editor_ptr->cursor_p = backup_cursor_p;
            return i;
        }

    case MMI_IMC_MESSAGE_INSERT_SPACE:
        gui_multi_line_input_box_insert_character(editor_ptr, (UI_character_type)(0x20));
        wgui_editor_handle_input();
        wgui_editor_redraw_active_editor(); 
        break;  

    case MMI_IMC_MESSAGE_SET_MULTITAP_STATE:
        editor_ptr->flags |= UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP;
        break;

    case MMI_IMC_MESSAGE_GET_EDITOR_SCROLL_BAR_WIDTH:
        if ((editor_ptr->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR) ||
            ((editor_ptr->flags & UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR) && 
            ((editor_ptr->vbar.scale != 0) && 
            (editor_ptr->vbar.scale >= editor_ptr->vbar.range))))
        {
            lresult = 0;
        }
        else
        {
            lresult =  (U32)editor_ptr->vbar.width;
        }        
        break;

    case MMI_IMC_MESSAGE_INSERT_CHAR_AT_DESIRED_POSITION:
        gui_multi_line_input_box_insert_character_in_pos(editor_ptr, (UI_character_type)msg_ptr->param_1, msg_ptr->param_0);
        wgui_editor_redraw_active_editor(); 
        break;

    case MMI_IMC_MESSAGE_DELETE_CHAR_AT_DESIRED_POSITION:
        gui_multi_line_input_box_delete_character_in_pos(editor_ptr, msg_ptr->param_0);		
        wgui_editor_redraw_active_editor(); 
        break;

    case MMI_IMC_MESSAGE_GET_CHAR_AT_DESIRED_POSITION:
        lresult = editor_ptr->text[msg_ptr->param_0];
        break;

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
*  wgui_editor_handle_input
* DESCRIPTION
*  after input, re-set RSK according to text length
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void wgui_editor_handle_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    single_line_input_box *single_line;
    multi_line_input_box *multi_line;
    S32 length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_current_active_editor->editor_type == WGUI_EDITOR_SINGLELINE)
    {
        single_line = (single_line_input_box *)(g_current_active_editor->editor);
        length = gui_single_line_input_box_get_text_length(single_line);
    }
    else
    {
        multi_line = (multi_line_input_box *)(g_current_active_editor->editor);
        length = gui_multi_line_input_box_get_text_length(multi_line);
    }

    if (length > 0)
    {
        /* if there is text in editor, rsk turn to clear */
        if (g_current_active_editor->RSK_label_clear == 0)
        {
            g_current_active_editor->RSK_label_clear = 1;                
        }        
        set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_CLEAR));
        set_right_softkey_icon(NULL);
        set_right_softkey_function(wgui_editor_handle_right_softkey, KEY_EVENT_DOWN);
        register_right_softkey_handler();
        set_right_softkey_function(NULL, KEY_EVENT_UP);//clear the up          
    }
    else
    {
        /* else rsk turn to user's default set */
        if (g_current_active_editor->RSK_label_clear == 1)
        {
            g_current_active_editor->RSK_label_clear = 0;
        }
        set_right_softkey_label(g_current_active_editor->softkey_label[MMI_RIGHT_SOFTKEY]);
        set_right_softkey_icon(g_current_active_editor->softkey_icon[MMI_RIGHT_SOFTKEY]);
        set_right_softkey_function(g_current_active_editor->softkey_handle[MMI_RIGHT_SOFTKEY], KEY_EVENT_DOWN);
        register_right_softkey_handler();
    }
}

/*****************************************************************************
* FUNCTION
*  wgui_editor_process_key_ext
* DESCRIPTION
*  process key(include qwerty key)
* PARAMETERS
*  keyCode               [IN]        key code
*  keyType               [IN]        key type
*  ucs2_value            [IN]
*  special_key_flag      [IN]
* RETURNS
*  MMI_BOOL
*****************************************************************************/
MMI_BOOL wgui_editor_process_key_ext(U16 keyCode, U16 keyType, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    MMI_BOOL ret = MMI_FALSE;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_current_active_editor)
    {
        /* handle ime key */
        if (mmi_imc_process_key_input(keyCode, keyType, ucs2_value, special_key_flag))
        {
            return MMI_TRUE;
        }

        /* handle editor navigation key */
        switch (keyType)
        {
        case KEY_EVENT_DOWN:
            {
                switch (keyCode)
                {
                case KEY_LEFT_ARROW:
                    ret = wgui_editor_previous_character();
                    break;
                case KEY_RIGHT_ARROW:
                    ret = wgui_editor_next_character();
                    break;
                case KEY_UP_ARROW:
                    ret =  wgui_editor_previous_line();
                    break;
                case KEY_DOWN_ARROW:
                    ret = wgui_editor_next_line();
                    break;       
                case KEY_CLEAR:
                    if (g_current_active_editor->RSK_label_clear == 1)
                    {
                        wgui_editor_handle_right_softkey();
                        ret = MMI_TRUE;
                    }
                    break;
                }

                if (ret)
                {
                    wgui_editor_redraw_active_editor(); 
                }

                break;
            }
        case KEY_EVENT_UP:
            break;
        }
    }

    return ret;
}

/*****************************************************************************
* FUNCTION
*  wgui_editor_process_key
* DESCRIPTION
*  process key
* PARAMETERS
*  keyCode               [IN]        key code
*  keyType               [IN]        key type
* RETURNS
*  MMI_BOOL
*****************************************************************************/
MMI_BOOL wgui_editor_process_key(U16 keyCode, U16 keyType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wgui_editor_process_key_ext(keyCode, keyType, 0, 0);
}

#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
* FUNCTION
*  wgui_editor_process_pen
* DESCRIPTION
*  process pen
* PARAMETERS
*  pos                      [IN]        pen position
*  eventType                [IN]        pen event type
* RETURNS
*  MMI_BOOL
*****************************************************************************/
MMI_BOOL wgui_editor_process_pen(mmi_pen_point_struct pos , mmi_pen_event_type_enum eventType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_current_active_editor)
    {
        if (mmi_imc_process_pen_input(pos, eventType))
        {
            return MMI_TRUE;
        }

        //fix bug, press RSK exit
        if (g_current_active_editor == NULL)
        {
            return MMI_TRUE;
        }
    }
   
    return MMI_FALSE;
}

#endif  /* __MMI_TOUCH_SCREEN__ */
/*****************************************************************************
 * FUNCTION
 *  wgui_editor_redraw_ime_floating_ui_within_rect
 * DESCRIPTION
 *  Redraw ime floating ui within given rectangle area
 * PARAMETERS
 *  rect               [IN]        Is the given rectangle area
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_editor_redraw_ime_floating_ui_within_rect(mmi_imc_rect_p rect)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_redraw_floating_ui_within_rect(rect);
}

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_redraw_ime_screen
 * DESCRIPTION
 *  Redraw ime UIs(floating ui and fixed ui) 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_editor_redraw_ime_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_redraw_screen_by_state();
}

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_get_extra_imui_layer_handler
 * DESCRIPTION
 *  get extra imui layer handler (like handwriting drawn layer)
 * PARAMETERS
 *  void
 * RETURNS
 *  GDI_HANDLE
 *****************************************************************************/
GDI_HANDLE wgui_editor_get_extra_imui_layer_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_imc_get_extra_imui_layer_handler();
}

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_set_imui_background_filler
 * DESCRIPTION
 *  set imui background filler
 * PARAMETERS
 *  draw_imui_background_funcptr        [in]        draw imui background funtion pointer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_editor_set_imui_background_filler(void (*draw_imui_background_funcptr)(S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_editor_draw_imui_background_funcptr = draw_imui_background_funcptr;    
}

/*****************************************************************************
* FUNCTION
*  wgui_editor_show_from_start
* DESCRIPTION
*  jump to start to show from the beginning
* PARAMETERS
*  b               [IN]        Is the wgui editor instance
* RETURNS
*  void
*****************************************************************************/
void wgui_editor_show_from_start(wgui_editor_struct *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
   single_line_input_box *single_line;
   multi_line_input_box *multi_line;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (b == NULL)
    {
        return;
    }

    if (b->editor_type == WGUI_EDITOR_SINGLELINE)
    {
        single_line = (single_line_input_box *)(b->editor);
        single_line->text_offset_x = 0;
    }
    else
    {
        multi_line = (multi_line_input_box *)(b->editor);
        multi_line->text_offset_y = 0;
        multi_line->ext_flags |= GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR; 
    }
    wgui_editor_show(b);
}

