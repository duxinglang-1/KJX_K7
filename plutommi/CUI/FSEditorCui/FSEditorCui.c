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
 *  FSEditorCui.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

//#include "MMI_include.h"
#include "FSEditorCui.h"
#include "FSEditorCuiGprot.h"
#include "CommonScreensResDef.h"        /* SCR_FSEDITOR ID */
//#include "CommonScreens.h"
#include "MenuCuiGprot.h"
#include "mmi_rp_srv_editor_def.h"
//#include "mmi_rp_menu_misc_def.h"

    #include "gui_data_types.h"
    #include "MMIDataType.h"
    #include "mmi_frm_scenario_gprot.h"
    #include "kal_general_types.h"
    #include "gui_inputs.h"
    #include "MMI_fw_trc.h"
    #include "mmi_fw_trc.h"
    #include "DebugInitDef_Int.h"
    #include "kal_trace.h"
    #include "kal_public_api.h"
    #include "GlobalResDef.h"
    #include "ImeGprot.h"
    #include "wgui_categories_list.h"
    #include "mmi_frm_events_gprot.h"
    #include "wgui_categories_inputs.h"
    #include "wgui_inputs.h"
    #include "wgui_categories_util.h"
    #include "GlobalConstants.h"
    #include "MMI_features.h"
    #include "gdi_include.h"
    #include "gui.h"
    #include "gui_config.h"
    #include "lcd_sw_inc.h"
    #include "Gui_Setting.h"
    #include "CustDataRes.h"
    #include "CustMenuRes.h"
    #include "string.h"
    #include "wgui_title.h"
    #include "gui_title.h"
    #include "wgui_include.h"
    #include "Unicodexdcl.h"
    #include "gui_typedef.h"
#ifdef __MMI_NCENTER_SUPPORT__
    #include "vapp_ncenter_gprot.h"
#endif
/***************************************************************************** 
*  Define
*****************************************************************************/
#define CUI_FSEDITOR_MAX_INSTANCE_COUNT      3
#define CUI_FSEDITOR_DEFAULT_LSK_TEXT        STR_GLOBAL_OPTIONS
#define CUI_FSEDITOR_DEFAULT_LSK_ICON        IMG_GLOBAL_OPTIONS
#define CUI_FSEDITOR_DEFAULT_RSK_TEXT        STR_GLOBAL_BACK
#define CUI_FSEDITOR_DEFAULT_RSK_ICON        IMG_GLOBAL_BACK
#define CUI_FSEDITOR_DEFAULT_CSK_TEXT        0
#define CUI_FSEDITOR_DEFAULT_CSK_ICON        IMG_GLOBAL_COMMON_CSK
#define CUI_FSEDITOR_DEFAULT_OPTIONS_DONE    STR_GLOBAL_DONE
#define CUI_FSEDITOR_DEFAULT_OPTIONS_CANCEL  STR_GLOBAL_CANCEL
#define CUI_FSEDITOR_MAX_OPTION_ITEMS        20

/***************************************************************************** 
*  Typedef 
*****************************************************************************/

/***************************************************************************** 
*  Extern Variables
*****************************************************************************/
/* store label string of RSK of input box */
extern UI_string_type wgui_inputbox_RSK_label_string;

/* store label icon of RSK key */
extern PU8 wgui_inputbox_RSK_label_icon;

/***************************************************************************** 
*  Global Variables
*****************************************************************************/

/*****************************************************************************  
*  Local Variables 
*****************************************************************************/
static cui_fseditor_struct g_cui_fseditor_data[CUI_FSEDITOR_MAX_INSTANCE_COUNT];
static mmi_id g_fseditor_gid = 0;
static mmi_id g_opt_menu_gid, g_opt_menu_id;

/*****************************************************************************  
*   Local Functions  
*****************************************************************************/
static void cui_fseditor_init(mmi_id fseditor_gid);
static mmi_ret cui_fseditor_proc(mmi_event_struct *evt);
static void cui_fseditor_lsk_handler(void);
static void cui_fseditor_rsk_handler(void);
static void cui_fseditor_csk_handler(void);
static void cui_fseditor_scr_entry(mmi_scrn_essential_struct* info);
static void cui_fseditor_entry_options_screen(void);
static cui_fseditor_struct *cui_fseditor_get_data(void);
static WCHAR* cui_fseditor_malloc_text_buffer(mmi_id fseditor_gid, S32 buffer_size);
static MMI_BOOL cui_fseditor_edit_change_event_handler(gui_multi_line_input_box_change_event_enum event, U16 c);
static void cui_fseditor_options_done_handler(void);
static void cui_fseditor_options_cancel_handler(void);
static void cui_fseditor_options_custom_menu_handler(mmi_menu_id menu_id);
static void cui_fseditor_change_buffer(mmi_id fseditor_gid);
static mmi_ret cui_fseditor_options_menu_handler(mmi_menu_id menu_id);

/* Event handler */
static void cui_fseditor_evt_submit(void);
static void cui_fseditor_evt_abort(void);
static void cui_fseditor_evt_empty(void);
static void cui_fseditor_evt_not_empty(void);
static MMI_BOOL cui_fseditor_evt_delete_char(U16 c);
static MMI_BOOL cui_fseditor_evt_insert_char(U16 c);
static void cui_fseditor_evt_changed(void);
static void cui_fseditor_evt_validation(PU8 text, PU8 cursor_position, S32 text_length);
static void cui_fseditor_evt_set_key(void);
static void cui_fseditor_evt_custom_options_menu_select(mmi_menu_id menu_id);
static void cui_fseditor_evt_csk_pressed(void);
static void cui_fseditor_evt_input_method_change(void);


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_init
 * DESCRIPTION
 *  Init full screen editor CUI structure and set default value
 * PARAMETERS
 *  fseditor_gid        [IN]        Full screen editor CUI group ID
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_fseditor_init(mmi_id fseditor_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_struct *editor = (cui_fseditor_struct*) mmi_frm_group_get_user_data(fseditor_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G4_EDITOR, MMI_GUI_EDITOR_CUI_INIT, fseditor_gid);
    MMI_ASSERT(editor != NULL);
    editor->lsk_label = CUI_FSEDITOR_DEFAULT_LSK_TEXT;
    editor->lsk_icon = CUI_FSEDITOR_DEFAULT_LSK_ICON;
    editor->rsk_label = CUI_FSEDITOR_DEFAULT_RSK_TEXT;
    editor->rsk_icon = CUI_FSEDITOR_DEFAULT_RSK_ICON;
    editor->csk_label = CUI_FSEDITOR_DEFAULT_CSK_TEXT;
    editor->csk_icon = CUI_FSEDITOR_DEFAULT_CSK_ICON;
    editor->input_type = IMM_INPUT_TYPE_SENTENCE;
    editor->options_done_label = CUI_FSEDITOR_DEFAULT_OPTIONS_DONE;
    editor->options_cancel_label = CUI_FSEDITOR_DEFAULT_OPTIONS_CANCEL;
    editor->state = CUI_FSEDITOR_STATE_CREATE;
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_proc
 * DESCRIPTION
 *  full screen editor CUI proc function.
 * PARAMETERS
 *  evt     [IN]        Event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret cui_fseditor_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_struct *editor;
    cui_fseditor_evt_struct editor_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
    case EVT_ID_GROUP_DEINIT:

        // notify app
        MMI_FRM_INIT_GROUP_EVENT(&editor_evt, EVT_ID_CUI_FSEDITOR_DEINIT, g_fseditor_gid);  
        mmi_frm_group_send_to_parent(g_fseditor_gid, (mmi_group_event_struct*)&editor_evt);

        /* release resource, e.g. instance memory */
        editor = (cui_fseditor_struct*)evt->user_data;
        MMI_ASSERT(editor != NULL);
        editor->memory_id = 0;
        break;
#ifdef __MMI_NCENTER_SUPPORT__
    case EVT_ID_VAPP_NCENTER_DRAG:
    	  {
            editor = (cui_fseditor_struct*)evt->user_data;
            MMI_ASSERT(editor != NULL);
    	      if (editor->is_disable_ncenter)
    	      {
    	      	 return MMI_RET_ERR;
    	      }
    	  }
		  break;
#endif
    default:
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_scr_entry
 * DESCRIPTION
 *  Full screen editor CUI entry function
 * PARAMETERS
 *  info          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_fseditor_scr_entry(mmi_scrn_essential_struct* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    mmi_id fseditor_gid;
    cui_fseditor_struct *editor;
    mmi_imm_input_mode_enum input_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fseditor_gid = g_fseditor_gid = info->group_id;
    editor = (cui_fseditor_struct*) mmi_frm_group_get_user_data(fseditor_gid);
    MMI_TRACE(MMI_FW_TRC_G4_EDITOR, MMI_GUI_EDITOR_CUI_SCRN_ENTRY, fseditor_gid);
    MMI_ASSERT(editor != NULL);

    if (mmi_frm_scrn_enter(fseditor_gid, SCR_FSEDITOR, NULL, (FuncPtr)cui_fseditor_scr_entry, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }

    if (editor->buffer == NULL)
    {
        /* Current we don't support. It's just for future extension */
        MMI_ASSERT(0);
        editor->buffer = cui_fseditor_malloc_text_buffer(fseditor_gid, editor->buffer_size);
    }

    /* Get gui buffer */
    guiBuffer = (PU8)mmi_frm_scrn_get_gui_buf(fseditor_gid, SCR_FSEDITOR);
    editor->editor_scr_id = SCR_FSEDITOR;

    if (editor->set_characters_list)
    {
        mmi_imm_set_characters(editor->set_characters_flag, editor->set_characters_list);
    }

    if (editor->is_title_in_header)
    {
        wgui_cat5_set_title_in_header(1);
    }

    /* Register editor callback */
    wgui_inputs_register_empty_func(cui_fseditor_evt_empty);
    wgui_inputs_register_not_empty_func(cui_fseditor_evt_not_empty);
    wgui_inputs_register_validation_func(cui_fseditor_evt_validation);
    wgui_inputs_register_input_method_change_func(cui_fseditor_evt_input_method_change);

    if (editor->buffer_change_flag)
    {
        if (guiBuffer)
        {
            /* retrieve last time input type */
            input_mode = (((multiline_inputbox_category_history*)guiBuffer)->ime_history).input_mode;
            mmi_imm_set_app_desired_input_mode(input_mode);
            guiBuffer = NULL;
            editor->buffer_change_flag = MMI_FALSE;
        }
    }

    if (editor->title_string)
    {
        ShowCategory5Screen_ext2(
            (UI_string_type)editor->title_string,
            get_image(editor->title_icon),
            get_string(editor->lsk_label),
            get_image(editor->lsk_icon),
            get_string(editor->rsk_label),
            get_image(editor->rsk_icon),
            editor->input_type,
            (PU8)editor->buffer,
            editor->edit_length + 1,
            guiBuffer,
            editor->input_ext_type,
            (mmi_imm_input_mode_enum *)editor->required_input_mode_set);
    }
    else
    {
        ShowCategory5Screen_ext(
            editor->title,
            editor->title_icon,
            editor->lsk_label,
            editor->lsk_icon,
            editor->rsk_label,
            editor->rsk_icon,
            editor->input_type,
            (PU8)editor->buffer,
            editor->edit_length + 1,
            guiBuffer,
            editor->input_ext_type,
            (mmi_imm_input_mode_enum *)editor->required_input_mode_set);
    }

    if (guiBuffer == NULL && editor->set_cursor_first_pos)
    {
        wgui_inputs_ml_move_cursor(WGUI_INPUTS_CURSOR_POS_START);
    }

    if (editor->is_auto_display_counter)
    {
        wgui_inputs_ml_set_auto_display_remaining_counter();
        wgui_inputs_ml_redraw();
    }

    if (editor->is_delete_all)
    {
        wgui_inputs_ml_set_clear_key_delete_all_mode();
    }

    /* Set change callback after show category because it will reset in showcategory */
    MMI_multiline_inputbox.change_callback = cui_fseditor_evt_changed;
    wgui_inputs_ml_register_change_event_handler(cui_fseditor_edit_change_event_handler);

    SetLeftSoftkeyFunction(cui_fseditor_lsk_handler, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(cui_fseditor_rsk_handler, KEY_EVENT_UP);
#ifndef __OP01_FWPBW__
    ChangeCenterSoftkey(editor->csk_label, editor->csk_icon);
#endif
    SetCenterSoftkeyFunction(cui_fseditor_csk_handler, KEY_EVENT_UP);

    cui_fseditor_evt_set_key();
    editor->state = CUI_FSEDITOR_STATE_RUN;
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_lsk_handler
 * DESCRIPTION
 *  full screen editor CUI left softkey hanlder. If app set the LSK, it will send submit
 *  event to app when user press lsk, else, it will entry editor options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_fseditor_lsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_struct *editor = (cui_fseditor_struct*) mmi_frm_group_get_user_data(g_fseditor_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(editor != NULL);
    if (editor->lsk_change_flag)
    {
        cui_fseditor_evt_submit();
    }
    else
    {
        cui_fseditor_entry_options_screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_rsk_handler
 * DESCRIPTION
 *  full screen editor CUI right softkey hanlder, it will send abort event to app
 *  when user press rsk
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_fseditor_rsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_fseditor_evt_abort();
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_csk_handler
 * DESCRIPTION
 *  full screen editor CUI center softkey hanlder. If app set the CSK, it will send csk pressed
 *  event to app when user press csk, else, it will entry editor options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_fseditor_csk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_struct *editor = (cui_fseditor_struct*) mmi_frm_group_get_user_data(g_fseditor_gid);
    mmi_menu_id menu_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(editor != NULL);
    if (editor->csk_change_flag)
    {
        cui_fseditor_evt_csk_pressed();
    }
    else
    {
        if (!editor->disable_def_opt_menu_flag)
        {
            menu_id = MENU_ID_EDITOR_CUI_OPT_DONE;
            cui_fseditor_options_menu_handler(menu_id);
        }
        else if (editor->options_cust_menu_list)
        {
            menu_id = editor->options_cust_menu_list[0];
            cui_fseditor_options_menu_handler(menu_id);
        }
        else
        {
            menu_id = MENU_ID_EDITOR_CUI_OPT_CANCEL;
            cui_fseditor_options_menu_handler(menu_id);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_options_done_handler
 * DESCRIPTION
 *  full screen editor CUI options Done menu hanlder. It will be invoked when user
 *  select Done menu item and press LSK
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_fseditor_options_done_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Go back history */

    cui_fseditor_evt_submit();
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_options_cancel_handler
 * DESCRIPTION
 *  full screen editor CUI options Cancel menu hanlder. It will be invoked when user
 *  select Cancel menu item and press LSK
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_fseditor_options_cancel_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Go back history */

    cui_fseditor_evt_abort();
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_options_custom_menu_handler
 * DESCRIPTION
 *  full screen editor CUI options Custom menu hanlder. It will be invoked when user
 *  select Custom menu item and press LSK
 * PARAMETERS
 *  menu_id          [IN]             custom menu id
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_fseditor_options_custom_menu_handler(mmi_menu_id menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Go back history */

    cui_fseditor_evt_custom_options_menu_select(menu_id);
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_change_buffer
 * DESCRIPTION
 *  Change editor buffer and redraw. 
 *  Internal function, used by cui_fseditor_set_text
 * PARAMETERS
 *  fseditor_gid          [IN]        group id
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_fseditor_change_buffer(mmi_id fseditor_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 l;
    S32 saved_flags, saved_ext_flags;
    cui_fseditor_struct *editor = (cui_fseditor_struct*) mmi_frm_group_get_user_data(fseditor_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (editor == NULL)
    {
        return;
    }

    gdi_layer_lock_frame_buffer();

#ifdef __MMI_TOUCH_SCREEN__
    gui_multi_line_input_box_scroll_timer_hdlr();
#endif 

    saved_flags = MMI_multiline_inputbox.flags;
    saved_ext_flags = MMI_multiline_inputbox.ext_flags;

    l = gui_strlen((UI_string_type) editor->buffer);

    gui_create_multi_line_input_box_set_buffer(
        &MMI_multiline_inputbox,
        MMI_multiline_inputbox.x,
        MMI_multiline_inputbox.y,
        MMI_multiline_inputbox.width,
        MMI_multiline_inputbox.height,
        (UI_string_type) editor->buffer,
        (editor->edit_length + 1) * ENCODING_LENGTH,
        (l + 1) * 2,
        l);

    MMI_multiline_inputbox.flags = saved_flags;
    MMI_multiline_inputbox.ext_flags = saved_ext_flags;

    if (editor->input_type & INPUT_TYPE_USE_ENCODING_BASED_LENGTH)
    {
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH;
        if (editor->input_type & INPUT_TYPE_ONE_LESS_CHARACTER)
        {
            MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_ONE_LESS_CHARACTER;
            UI_TEST_UCS2_COUNT_SET_LENGTH_TYPE2(
                MMI_multiline_inputbox.UCS2_count,
                MMI_multiline_inputbox.allocated_length,
                MMI_multiline_inputbox.available_length);
        }
        else if (editor->input_type & INPUT_TYPE_FORTY_FOUR_LESS_CHARACTER)
        {
            MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_FORTY_FOUR_LESS_CHARACTER;
            UI_TEST_UCS2_COUNT_SET_LENGTH_TYPE3(
                MMI_multiline_inputbox.UCS2_count,
                MMI_multiline_inputbox.allocated_length,
                MMI_multiline_inputbox.available_length);
        }
        else
        {
            UI_TEST_UCS2_COUNT_SET_LENGTH(
                MMI_multiline_inputbox.UCS2_count,
                MMI_multiline_inputbox.allocated_length,
                MMI_multiline_inputbox.available_length);
        }
    }

#ifdef __MMI_WALLPAPER_ON_BOTTOM__ 
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_TRANSPARENT_BACKGROUND;
#endif

    wgui_inputs_ml_show_with_information_bar();
    gdi_layer_unlock_frame_buffer();

    gdi_layer_blt_previous(0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT);
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_add_options_menu_item
 * DESCRIPTION
 *  Edtior Options screen entry function
 * PARAMETERS
 *  info        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret cui_fseditor_add_options_menu_item(mmi_menu_id sender_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_struct *editor;
    mmi_menu_id root_ids[CUI_FSEDITOR_MAX_OPTION_ITEMS];
    U8 index = 0;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor = (cui_fseditor_struct*) mmi_frm_group_get_user_data(g_fseditor_gid);

    if (editor == NULL)
    {
        return MMI_RET_ERR;
    }

    /* Done/Cancel menu item */
    if (!editor->disable_def_opt_menu_flag)
    {
        root_ids[index++] = MENU_ID_EDITOR_CUI_OPT_DONE;
    }

    /* App's menu item */
    if (editor->options_cust_menu_list)
    {
        for (i = 0; i < editor->options_cust_menu_count; i++)
        {
            root_ids[index++] = editor->options_cust_menu_list[i];
        }
    }

    if (!editor->disable_cancel_item)
    {
        root_ids[index++] = MENU_ID_EDITOR_CUI_OPT_CANCEL;
    }

    /* Input method related menu item */
    root_ids[index++] = MENU_ID_EDIT_OPTS;

    cui_menu_set_currlist(sender_id, index, root_ids);

    /* Set menu item string */
    for (i = 0; i < index; i++)
    {
            cui_menu_set_item_string(sender_id,
                root_ids[i], (UI_string_type)GetString(GetStringIdOfItem(root_ids[i])));
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_is_custom_menu
 * DESCRIPTION
 *  Check if menu id is custom menu id or not
 * PARAMETERS
 *  menu_id        [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL cui_fseditor_is_custom_menu(mmi_menu_id menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_struct *editor;
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor = (cui_fseditor_struct*) mmi_frm_group_get_user_data(g_fseditor_gid);

    if (editor == NULL)
    {
       return MMI_FALSE;
    }

    if (editor->options_cust_menu_list)
    {
        for (i = 0; i < editor->options_cust_menu_count; i++)
        {
            if (editor->options_cust_menu_list[i] == menu_id)
            {
                return MMI_TRUE;
            }
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_options_menu_handler
 * DESCRIPTION
 *  Edtior Options screen entry function
 * PARAMETERS
 *  info        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret cui_fseditor_options_menu_handler(mmi_menu_id menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (menu_id == MENU_ID_EDITOR_CUI_OPT_DONE)
    {
        cui_fseditor_options_done_handler();
    }
    else if (menu_id == MENU_ID_EDITOR_CUI_OPT_CANCEL)
    {
        cui_fseditor_options_cancel_handler();
    }
    else if (cui_fseditor_is_custom_menu(menu_id))
    {
        cui_fseditor_options_custom_menu_handler(menu_id);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_options_proc
 * DESCRIPTION
 *  Edtior Options screen entry function
 * PARAMETERS
 *  info        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret cui_fseditor_options_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            if (MENU_ID_EDITOR_CUI_OPT == menu_evt->parent_menu_id)
            {
                cui_fseditor_add_options_menu_item(menu_evt->sender_id);
            }
            break;
        case EVT_ID_CUI_MENU_ITEM_TAP:
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            cui_fseditor_options_menu_handler(menu_evt->highlighted_menu_id);
            break;
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;
    }

    if (cui_menu_is_menu_event(menu_evt->evt_id))
    {
        wgui_inputs_options_menu_handler(evt, g_fseditor_gid);
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_entry_options_screen
 * DESCRIPTION
 *  Edtior Options screen entry function
 * PARAMETERS
 *  info        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_fseditor_entry_options_screen()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_struct *editor = (cui_fseditor_struct*) mmi_frm_group_get_user_data(g_fseditor_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (editor == NULL)
    {
        return;
    }

    g_opt_menu_gid = mmi_frm_group_create(
        g_fseditor_gid, GRP_ID_AUTO_GEN, cui_fseditor_options_proc, (void*)NULL); 

    MMI_TRACE(MMI_FW_TRC_G4_EDITOR, MMI_GUI_EDITOR_CUI_OPTION_SCRN_ENTRY, g_opt_menu_gid, g_fseditor_gid);

    mmi_frm_group_enter(g_opt_menu_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    g_opt_menu_id = cui_menu_create(g_opt_menu_gid,
        CUI_MENU_SRC_TYPE_APPCREATE,
        CUI_MENU_TYPE_OPTION,
        MENU_ID_EDITOR_CUI_OPT,
        MMI_FALSE, NULL);
    cui_menu_set_default_title(g_opt_menu_id, (WCHAR*)GetString(STR_GLOBAL_OPTIONS), (UI_image_type)GetImage(editor->title_icon));
    cui_menu_run(g_opt_menu_id);
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_get_data
 * DESCRIPTION
 *  Get Full screen instance data, currently we use global memory and the max instance
 *  is defined in MAX_CUI_FSEDITOR_INSTANCE_COUNT. We can improve this by using ADM
 * PARAMETERS
 *  void
 * RETURNS
 *  instance data point
 *****************************************************************************/
static cui_fseditor_struct *cui_fseditor_get_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < CUI_FSEDITOR_MAX_INSTANCE_COUNT; index++)
    {
        if (g_cui_fseditor_data[index].memory_id == 0)
        {
            memset(&g_cui_fseditor_data[index], 0, sizeof(cui_fseditor_struct));
            g_cui_fseditor_data[index].memory_id = index + 1;
            return &g_cui_fseditor_data[index];
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_malloc_text_buffer
 * DESCRIPTION
 *  Malloc fseditor text buffer
 * PARAMETERS
 *  fseditor_gid        [IN]        Full screen edtior CUI group ID created by parent
 * RETURNS
 *  void
 *****************************************************************************/
static WCHAR* cui_fseditor_malloc_text_buffer(mmi_id fseditor_gid, S32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* For future useage */
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_edit_change_event_handler
 * DESCRIPTION
 *  Full screen editor CUI change event handler.
 *  It will be invoke before a char to be inserted/deleted
 * PARAMETERS
 *  event       [IN]        GUI_MULTI_LINE_INPUT_BOX_INSERT_CHAR/GUI_MULTI_LINE_INPUT_BOX_DELETE_CHAR
 *  c           [IN]        Char to be inserted or deleted
 * RETURNS
 *  MMI_BOOL:
 *  MMI_TRUE:  allow to change (delete/inserted)
 *  MMI_FALSE: not allow to change (delete/inserted)
 *****************************************************************************/
static MMI_BOOL cui_fseditor_edit_change_event_handler(gui_multi_line_input_box_change_event_enum event, U16 c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (event == GUI_MULTI_LINE_INPUT_BOX_INSERT_CHAR)
    {
        return cui_fseditor_evt_insert_char(c);
    }
    else if (event == GUI_MULTI_LINE_INPUT_BOX_DELETE_CHAR)
    {
        return cui_fseditor_evt_delete_char(c);
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_evt_submit
 * DESCRIPTION
 *  FSEditor CUI submit event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_fseditor_evt_submit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CUI_FSEDITOR_SUBMMIT, g_fseditor_gid);
    mmi_frm_group_send_to_parent(g_fseditor_gid, (mmi_group_event_struct*) & evt);
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_evt_abort
 * DESCRIPTION
 *  FSEditor CUI abort event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_fseditor_evt_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CUI_FSEDITOR_ABORT, g_fseditor_gid);
    mmi_frm_group_send_to_parent(g_fseditor_gid, (mmi_group_event_struct*) & evt);
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_evt_empty
 * DESCRIPTION
 *  FSEditor CUI empty event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_fseditor_evt_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CUI_FSEDITOR_EMPTY, g_fseditor_gid);
    mmi_frm_group_post_to_parent(g_fseditor_gid, (mmi_group_event_struct*) & evt);
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_evt_not_empty
 * DESCRIPTION
 *  FSEditor CUI not empty event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_fseditor_evt_not_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CUI_FSEDITOR_NOT_EMPTY, g_fseditor_gid);
    mmi_frm_group_post_to_parent(g_fseditor_gid, (mmi_group_event_struct*) & evt);
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_evt_insert_char
 * DESCRIPTION
 *  FSEditor CUI insert event handler
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL cui_fseditor_evt_insert_char(U16 c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_edit_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CUI_FSEDITOR_INSERT_CHAR, g_fseditor_gid);
    evt.c = c;
    mmi_frm_group_send_to_parent(g_fseditor_gid, (mmi_group_event_struct*) & evt);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_evt_delete_char
 * DESCRIPTION
 *  FSEditor CUI delete event handler
 * PARAMETERS
 *  c       [IN]        Character to be deleted
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL cui_fseditor_evt_delete_char(U16 c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_edit_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CUI_FSEDITOR_DELETE_CHAR, g_fseditor_gid);
    evt.c = c;
    mmi_frm_group_send_to_parent(g_fseditor_gid, (mmi_group_event_struct*) & evt);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_evt_changed
 * DESCRIPTION
 *  FSEditor CUI validation handler
 * PARAMETERS
 *  text                [IN]        Text buffer
 *  cursor_position     [IN]        Cursor position
 *  text_length         [IN]        Text length
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_fseditor_evt_validation(PU8 text, PU8 cursor_position, S32 text_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_change_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CUI_FSEDITOR_VALIDATION, g_fseditor_gid);
    evt.text = text;
    evt.cursor_position = cursor_position;
    evt.text_length = text_length;
    mmi_frm_group_send_to_parent(g_fseditor_gid, (mmi_group_event_struct*) & evt);
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_evt_changed
 * DESCRIPTION
 *  FSEditor CUI changed event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_fseditor_evt_changed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_change_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CUI_FSEDITOR_CHANGED, g_fseditor_gid);
    evt.text = MMI_multiline_inputbox.text;
    evt.cursor_position = MMI_multiline_inputbox.cursor_p;
    evt.text_length = MMI_multiline_inputbox.text_length;
    mmi_frm_group_send_to_parent(g_fseditor_gid, (mmi_group_event_struct*) & evt);
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_evt_custom_options_menu_select
 * DESCRIPTION
 *  FSEditor CUI custom options menu selected event handler
 * PARAMETERS
 *  menu_id          [IN]          custom menu id
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_fseditor_evt_custom_options_menu_select(mmi_menu_id menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_custom_menu_select_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CUI_FSEDITOR_CUSTOM_MENU_SELECTED, g_fseditor_gid);
    evt.menu_id = menu_id;
    mmi_frm_group_send_to_parent(g_fseditor_gid, (mmi_group_event_struct*) & evt);
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_evt_set_key
 * DESCRIPTION
 *  FSEditor CUI set key event handler, If App has apply FW new input handle routine,
 *  this event will be deleted in future
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_fseditor_evt_set_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CUI_FSEDITOR_SET_KEY, g_fseditor_gid);
    mmi_frm_group_post_to_parent(g_fseditor_gid, (mmi_group_event_struct*) & evt);
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_evt_input_method_change
 * DESCRIPTION
 *  FSEditor CUI input method change event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_fseditor_evt_input_method_change(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_input_method_change_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CUI_FSEDITOR_INPUT_METHOD_CHANGE, g_fseditor_gid);
    evt.input_method = mmi_imm_get_curr_input_mode();
    mmi_frm_group_post_to_parent(g_fseditor_gid, (mmi_group_event_struct*) & evt);
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_evt_csk_pressed
 * DESCRIPTION
 *  FSEditor CUI CSK pressed event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_fseditor_evt_csk_pressed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CUI_FSEDITOR_CSK_PRESSED, g_fseditor_gid);
    mmi_frm_group_post_to_parent(g_fseditor_gid, (mmi_group_event_struct*) & evt);
}


/*****************************************************************************  
*   Extern Functions 
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_create
 * DESCRIPTION
 *  Create fsedtior CUI.
 *  WARNING: if max fseditor CUI instance number has reached, it will fail to 
 *           create CUI and return GRP_ID_INVALID.
 * PARAMETERS
 *  parent_gid      [IN]        App's Group ID
 * RETURNS
 *  FSeditor CUI group ID
 *****************************************************************************/
mmi_id cui_fseditor_create(mmi_id parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id fseditor_gid = GRP_ID_INVALID;
    cui_fseditor_struct *instance_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    instance_data = cui_fseditor_get_data();
    if (instance_data != NULL)
    {
        fseditor_gid = mmi_frm_group_create(parent_gid, GRP_ID_AUTO_GEN, cui_fseditor_proc, instance_data);
        cui_fseditor_init(fseditor_gid);
    }
    else
    {
        /* Return Invalid group id if can't get instance data */
        fseditor_gid = GRP_ID_INVALID;
    }

    MMI_TRACE(MMI_FW_TRC_G4_EDITOR, MMI_GUI_EDITOR_CUI_CREATE, parent_gid, fseditor_gid);    
    return fseditor_gid;
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_run
 * DESCRIPTION
 *  FSeditor CUI run function. It will entry FSEditor screen after called it
 * PARAMETERS
 *  fseditor_gid        [IN]        FSEditor CUI Group ID
 * RETURNS
 *  void
 *****************************************************************************/
void cui_fseditor_run(mmi_id fseditor_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G4_EDITOR, MMI_GUI_EDITOR_CUI_RUN, fseditor_gid);    
    mmi_frm_group_enter(fseditor_gid, MMI_FRM_NODE_NONE_FLAG);
    mmi_frm_scrn_first_enter(
            fseditor_gid,
            SCR_FSEDITOR, 
            (FuncPtr)cui_fseditor_scr_entry, 
            NULL);
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_close
 * DESCRIPTION
 *  FSEditor CUI close function. It will delete ALL Editor CUI's screen by calling it
 * PARAMETERS
 *  fseditor_gid        [IN]        FSEditor CUI Group ID
 * RETURNS
 *  void
 *****************************************************************************/
void cui_fseditor_close(mmi_id fseditor_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_struct *editor = (cui_fseditor_struct*) mmi_frm_group_get_user_data(fseditor_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G4_EDITOR, MMI_GUI_EDITOR_CUI_CLOSE, fseditor_gid);
    if (editor == NULL)
    {
        return;
    }

    /* close screen group */
    mmi_frm_group_close(fseditor_gid);
    if (g_fseditor_gid == fseditor_gid)
    {
        g_fseditor_gid = GRP_ID_INVALID;
    }
    editor->state = CUI_FSEDITOR_STATE_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_title
 * DESCRIPTION
 *  Set editor title by text resource ID and icon resource ID.
 * PARAMETERS
 *  fseditor_gid        [IN]        FSEditor CUI Group ID
 *  label               [IN]        Title text ID
 *  icon                [IN]        Title icon ID
 * RETURNS
 *  void
 *****************************************************************************/
void cui_fseditor_set_title(mmi_id fseditor_gid, U16 label, U16 icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_struct *editor = (cui_fseditor_struct*) mmi_frm_group_get_user_data(fseditor_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (editor == NULL)
    {
        return;
    }
    editor->title = label;
    editor->title_icon = icon;

    wgui_title_change(editor->title_icon, 0, (PU8)GetString(editor->title), WGUI_TITLE_CHANGE_ICON | WGUI_TITLE_CHANGE_TEXT);

    /* Change title only when editor CUI is running */
    if (editor->state == CUI_FSEDITOR_STATE_RUN)
    {
        wgui_title_show(GUI_TITLE_PART_ALL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_title_string
 * DESCRIPTION
 *  Set editor title text by string.
 * PARAMETERS
 *  fseditor_gid        [IN]        FSEditor CUI Group ID
 *  label               [IN]        Title text string
 * RETURNS
 *  void
 *****************************************************************************/
void cui_fseditor_set_title_string(mmi_id fseditor_gid, const WCHAR *label)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_struct *editor = (cui_fseditor_struct*) mmi_frm_group_get_user_data(fseditor_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (editor == NULL)
    {
        return;
    }
    editor->title_string = label;

    wgui_title_change(0, 0, (PU8)editor->title_string, WGUI_TITLE_CHANGE_TEXT);

    /* Change title only when editor CUI is running */
    if (editor->state == CUI_FSEDITOR_STATE_RUN)
    {
        wgui_title_show(GUI_TITLE_PART_TEXT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_title_icon
 * DESCRIPTION
 *  Set editor title icon ID.
 * PARAMETERS
 *  fseditor_gid        [IN]        FSEditor CUI Group ID
 *  icon                [IN]        Title icon ID
 * RETURNS
 *  void
 *****************************************************************************/
void cui_fseditor_set_title_icon(mmi_id fseditor_gid, U16 icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_struct *editor = (cui_fseditor_struct*) mmi_frm_group_get_user_data(fseditor_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (editor == NULL)
    {
        return;
    }
    editor->title_icon = icon;

    wgui_title_change(editor->title_icon, 0, NULL, WGUI_TITLE_CHANGE_ICON);

    /* Change title only when editor CUI is running */
    if (editor->state == CUI_FSEDITOR_STATE_RUN)
    {
        wgui_title_show(GUI_TITLE_PART_ICON);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_input_method
 * DESCRIPTION
 *  Set editor input method
 *  NOTE: It should be called only before Editor CUI run
 * PARAMETERS
 *  fseditor_gid                [IN]        FSEditor CUI Group ID
 *  input_type                  [IN]        Input type
 *  required_input_mode_set     [IN]        App specific input mode list
 *  input_ext_type              [IN]        Input extention type
 * RETURNS
 *  void
 *****************************************************************************/
void cui_fseditor_set_input_method(
        mmi_id fseditor_gid,
        U32 input_type,
        const mmi_imm_input_mode_enum *required_input_mode_set,
        S16 input_ext_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_struct *editor = (cui_fseditor_struct*) mmi_frm_group_get_user_data(fseditor_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (editor == NULL)
    {
        return;
    }
    editor->input_type = input_type;
    editor->required_input_mode_set = required_input_mode_set;
    editor->input_ext_type = input_ext_type;
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_text
 * DESCRIPTION
 *  Set FSEditor CUI buffer. It can be call before/after CUI run.
 *  [USAGE]:
 *    1. If edit buffer is smaller than CUI_FSEDITOR_MAX_BUFFER_SIZE, Editor CUI will use internal memory for editing
 *       1) If App pass NULL for buffer, Editor will use internal text buffer for edit and initialize it as empty text
 *       2) If App pass local text buffer, Editor will use internal text buffer for edit and copy the local text.
 *    2. If edit buffer is large than CUI_FSEDITOR_MAX_BUFFER_SIZE, App must pass the global/static memory for editing.
 *  [NOTE]: 
 *    1. When finish editing, App must call cui_fseditor_get_text to get text, no matter use app's buffer or editor CUI's buffer.
 *    2. If App call this function after CUI run, 
 *       1) If current screen is editor screen, It will refresh editor content by re entry editor screen
 *       2) If editor screen is in history, it won't refresh editor screen. And only set history buffer
 * PARAMETERS
 *  fseditor_gid        [IN]        FSEditor CUI Group ID
 *  buffer              [IN]        Editor Buffer
 *  buffer_size         [IN]        Editor buffer size in Bytes, including NULL terminal char
 *  edit_length         [IN]        Editor editable text length in character count, not including NULL terminal
 * RETURNS
 *  void
 *****************************************************************************/
void cui_fseditor_set_text(mmi_id fseditor_gid, WCHAR *buffer, S32 buffer_size, S32 edit_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_struct *editor = (cui_fseditor_struct*) mmi_frm_group_get_user_data(fseditor_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G4_EDITOR, MMI_GUI_EDITOR_CUI_SET_TEXT, fseditor_gid, buffer_size, edit_length);
    if (editor == NULL)
    {
        return;
    }
    if (buffer_size <= CUI_FSEDITOR_MAX_BUFFER_SIZE)
    {
        if (buffer)
        {
            mmi_ucs2ncpy((S8*)editor->text_buffer, (S8*)buffer, (CUI_FSEDITOR_MAX_BUFFER_SIZE / 2 - 1));
        }
        editor->buffer = editor->text_buffer;
    }
    else
    {
        if (buffer)
        {
            editor->buffer = buffer;
        }
        else
        {
            /* App must use global/static memory for edit when size large than CUI_FSEDITOR_MAX_BUFFER_SIZE */
            MMI_ASSERT(0);
        }
    }
    editor->buffer_size = buffer_size;
    editor->edit_length = edit_length;

    /* Redraw editor only when editor CUI is running and current screen is editor screen */
    if (editor->state == CUI_FSEDITOR_STATE_RUN)
    {
        if (mmi_frm_scrn_get_active_id() == editor->editor_scr_id)
        {
            /* Update current screen buffer content and redraw screen */
            cui_fseditor_change_buffer(fseditor_gid);

            /* Set change callback after show category because it will reset after change buffer */
            MMI_multiline_inputbox.change_callback = cui_fseditor_evt_changed;
            wgui_inputs_ml_register_change_event_handler(cui_fseditor_edit_change_event_handler);
        }
        else
        {
            /* Discard history buffer by setting buffer change flag, so when entry editor screen, 
               history buffer will be discarded */
            editor->buffer_change_flag = MMI_TRUE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_get_text
 * DESCRIPTION
 *  Copy the edit text from FSEDITOR CUI to APP's buffer. 
 *  [NOTE]:
 *    1. After finish edit, App MUST call this API to get text, no matter use app's buffer or editor CUI's buffer
 *    2. App should guarantee the buffer_size of dest buffer is large enough to copy, if the editor text length is
 *       bigger than the buffer size, edit text will be truncated for app's buffer_size.
 * PARAMETERS
 *  fseditor_gid        [IN]         FSEditor CUI Group ID
 *  buffer              [OUT]        Buffer to copy edit content
 *  buffer_size         [IN]         buffer size to copy the edit content
 * RETURNS
 *  S32  real text length (character count) in editor buffer
 *****************************************************************************/
S32 cui_fseditor_get_text(mmi_id fseditor_gid, WCHAR *buffer, S32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_struct *editor = (cui_fseditor_struct*) mmi_frm_group_get_user_data(fseditor_gid);
    S32 text_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G4_EDITOR, MMI_GUI_EDITOR_CUI_GET_TEXT, fseditor_gid, buffer_size);
    /* Editor instance is not exist any more */
    if (editor == NULL)
    {
        return 0;
    }
    MMI_ASSERT(buffer != NULL); /* App must pass the dest buffer for copy */
    
    text_length = mmi_ucs2strlen((S8*)editor->buffer);

    /* App must pass enough dest buffer for copy, otherwise, text will be truncated */
    if (text_length < (buffer_size / 2) - 1)
    {
        mmi_ucs2cpy((S8*)buffer, (S8*)editor->buffer);
    }
    else
    {
        mmi_ucs2ncpy((S8*)buffer, (S8*)editor->buffer, (buffer_size / 2) - 1);
    }

    return text_length;
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_get_text_len
 * DESCRIPTION
 *  Get the real text length (character count) of editor after editing.
 * PARAMETERS
 *  fseditor_gid        [IN]         FSEditor CUI Group ID
 * RETURNS
 *  S32    text length (character count) of editor buffer
 *****************************************************************************/
S32 cui_fseditor_get_text_len(mmi_id fseditor_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_struct *editor = (cui_fseditor_struct*) mmi_frm_group_get_user_data(fseditor_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Editor instance is not exist any more */
    if (editor == NULL)
    {
        return 0;
    }

    return mmi_ucs2strlen((S8*)editor->buffer);
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_title_in_header
 * DESCRIPTION
 *  Set title in editor header area. For Landscape screen, there is no title in editor
 *  screen, if App want to display information on title, can set this flag.
 * PARAMETERS
 *  fseditor_gid        [IN]         FSEditor CUI Group ID
 *  title_in_header     [IN]         title in header or not
 * RETURNS
 *  void
 *****************************************************************************/
void cui_fseditor_set_title_in_header(mmi_id fseditor_gid, MMI_BOOL title_in_header)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_struct *editor = (cui_fseditor_struct*) mmi_frm_group_get_user_data(fseditor_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Editor instance is not exist any more */
    if (editor == NULL)
    {
        return;
    }

    editor->is_title_in_header = title_in_header;
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_cursor_first_pos
 * DESCRIPTION
 *  Set cursor position to the beginning of whole text.
 * PARAMETERS
 *  fseditor_gid        [IN]         FSEditor CUI Group ID
 *  is_first_pos        [IN]         is cursor at first pos
 * RETURNS
 *  void
 *****************************************************************************/
void cui_fseditor_set_cursor_first_pos(mmi_id fseditor_gid, MMI_BOOL is_first_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_struct *editor = (cui_fseditor_struct*) mmi_frm_group_get_user_data(fseditor_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Editor instance is not exist any more */
    if (editor == NULL)
    {
        return;
    }

    editor->set_cursor_first_pos = is_first_pos;
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_auto_display_remaining_counter
 * DESCRIPTION
 *  set auto display editor counter (Only show the counter when reach certain length)
 * PARAMETERS
 *  fseditor_gid        [IN]         FSEditor CUI Group ID
 * RETURNS
 *  void
 *****************************************************************************/
void cui_fseditor_set_auto_display_remaining_counter(mmi_id fseditor_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_struct *editor = (cui_fseditor_struct*) mmi_frm_group_get_user_data(fseditor_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Editor instance is not exist any more */
    if (editor == NULL)
    {
        return;
    }

    editor->is_auto_display_counter = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_is_disable_ncenter
 * DESCRIPTION
 *  set disable ncenter or not
 * PARAMETERS
 *  fseditor_gid        [IN]         FSEditor CUI Group ID
 *  value               [IN]         disable or not
 * RETURNS
 *  void
 *****************************************************************************/
void cui_fseditor_set_is_disable_ncenter(mmi_id fseditor_gid, MMI_BOOL value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_struct *editor = (cui_fseditor_struct*) mmi_frm_group_get_user_data(fseditor_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Editor instance is not exist any more */
    if (editor == NULL)
    {
        return;
    }

    editor->is_disable_ncenter = value;
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_clear_key_delete_all_mode
 * DESCRIPTION
 *  Set clear key delete all mode. 
 *  By default the clear key long press will fast delete character by character
 * PARAMETERS
 *  fseditor_gid        [IN]         FSEditor CUI Group ID
 * RETURNS
 *  void
 *****************************************************************************/
void cui_fseditor_set_clear_key_delete_all_mode(mmi_id fseditor_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_struct *editor = (cui_fseditor_struct*) mmi_frm_group_get_user_data(fseditor_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Editor instance is not exist any more */
    if (editor == NULL)
    {
        return;
    }

    editor->is_delete_all = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_softkey_text
 * DESCRIPTION
 *  Set Editor softykey text.
 *  NOTE: It call be call before/after editor CUI run.
 *        If CUI is running and current screen is editor screen, it will redraw softkey
 *        Otherwise, it only update softkey variables.
 * PARAMETERS
 *  fseditor_gid        [IN]        FSEditor CUI Group ID
 *  key_type            [IN]        softkey type:
                                    MMI_LEFT_SOFTKEY   -> LSK
                                    MMI_RIGHT_SOFTKEY  -> RSK
                                    MMI_CENTER_SOFTKEY -> CSK
 *  text                [IN]        softkey text
                                    Use STR_ID_CUI_FSEDITOR_DEFAULT set to default value
 * RETURNS
 *  void
 *****************************************************************************/
void cui_fseditor_set_softkey_text(mmi_id fseditor_gid, WGUI_SOFTKEY_ENUM key_type, U16 text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_struct *editor = (cui_fseditor_struct*) mmi_frm_group_get_user_data(fseditor_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (editor == NULL)
    {
        return;
    }
    switch (key_type)
    {
        case MMI_LEFT_SOFTKEY:
            if (text != STR_ID_CUI_FSEDITOR_DEFAULT)
            {
                editor->lsk_label = text;
                editor->lsk_change_flag = MMI_TRUE;
            }
            else
            {
                editor->lsk_label = CUI_FSEDITOR_DEFAULT_LSK_TEXT;
                editor->lsk_change_flag = MMI_FALSE;
            }
            set_softkey_label((UI_string_type)GetString(editor->lsk_label), MMI_LEFT_SOFTKEY);
            /* Redraw lsk only when editor CUI is running and current screen is editor screen */
            if ((editor->state == CUI_FSEDITOR_STATE_RUN) &&
                (mmi_frm_scrn_get_active_id() == editor->editor_scr_id))
            {
                redraw_softkey(MMI_LEFT_SOFTKEY);
            }
            break;
        case MMI_RIGHT_SOFTKEY:
            if (text != STR_ID_CUI_FSEDITOR_DEFAULT)
            {
                editor->rsk_label = text;
            }
            else
            {
                editor->rsk_label = CUI_FSEDITOR_DEFAULT_RSK_TEXT;
            }
            wgui_inputbox_RSK_label_string = (UI_string_type)GetString(editor->rsk_label);

            /* Redraw rsk only when editor CUI is running and current screen is editor screen */
            if ((editor->state == CUI_FSEDITOR_STATE_RUN) &&
                (mmi_frm_scrn_get_active_id() == editor->editor_scr_id))
            {
                redraw_softkey(MMI_RIGHT_SOFTKEY);
            }
            break;
        case MMI_CENTER_SOFTKEY:
            if (text != STR_ID_CUI_FSEDITOR_DEFAULT)
            {
                editor->csk_label = text;
                editor->csk_change_flag = MMI_TRUE;
            }
            else
            {
                editor->csk_label = CUI_FSEDITOR_DEFAULT_CSK_TEXT;
                editor->csk_change_flag = MMI_FALSE;
            }

            if (editor->csk_label == 0)
            {
                set_softkey_label(NULL, MMI_CENTER_SOFTKEY);
            }
            else
            {
                set_softkey_label((UI_string_type)GetString(editor->csk_label), MMI_CENTER_SOFTKEY);
            }

            /* Redraw csk only when editor CUI is running and current screen is editor screen */
            if ((editor->state == CUI_FSEDITOR_STATE_RUN) &&
                (mmi_frm_scrn_get_active_id() == editor->editor_scr_id))
            {
                redraw_softkey(MMI_CENTER_SOFTKEY);
            }
            break;
    }

    register_softkey_handler(key_type);
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_softkey_icon
 * DESCRIPTION
 *  Set Editor softykey icon.
 *  NOTE: It call be call before/after editor CUI run.
 *        If CUI is running and current screen is editor screen, it will redraw softkey
 *        Otherwise, it only update softkey variables.
 * PARAMETERS
 *  fseditor_gid        [IN]        FSEditor CUI Group ID
 *  key_type            [IN]        softkey type
                                    MMI_LEFT_SOFTKEY   -> LSK
                                    MMI_RIGHT_SOFTKEY  -> RSK
                                    MMI_CENTER_SOFTKEY -> CSK
 *  text                [IN]        softkey icon
                                    Use IMG_ID_CUI_FSEDITOR_DEFAULT: set to default value 
 * RETURNS
 *  void
 *****************************************************************************/
void cui_fseditor_set_softkey_icon(mmi_id fseditor_gid, WGUI_SOFTKEY_ENUM key_type, U16 icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_struct *editor = (cui_fseditor_struct*) mmi_frm_group_get_user_data(fseditor_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (editor == NULL)
    {
        return;
    }
    switch (key_type)
    {
        case MMI_LEFT_SOFTKEY:
            if (icon != IMG_ID_CUI_FSEDITOR_DEFAULT)
            {
                editor->lsk_icon = icon;
                editor->lsk_change_flag = MMI_TRUE;
            }
            else
            {
                editor->lsk_icon = CUI_FSEDITOR_DEFAULT_LSK_ICON;
                editor->lsk_change_flag = MMI_FALSE;
            }
            set_softkey_icon((PU8)GetImage(editor->lsk_icon), MMI_LEFT_SOFTKEY);

            /* Redraw lsk only when editor CUI is running and current screen is editor screen */
            if ((editor->state == CUI_FSEDITOR_STATE_RUN) &&
                (mmi_frm_scrn_get_active_id() == editor->editor_scr_id))
            {
                redraw_softkey(MMI_LEFT_SOFTKEY);
            }
            break;
        case MMI_RIGHT_SOFTKEY:
            if (icon != IMG_ID_CUI_FSEDITOR_DEFAULT)
            {
                editor->rsk_icon = icon;
            }
            else
            {
                editor->rsk_icon = CUI_FSEDITOR_DEFAULT_RSK_ICON;
            }
            wgui_inputbox_RSK_label_icon = (PU8)GetImage(editor->rsk_icon);
            set_softkey_icon((PU8)GetImage(editor->lsk_icon), MMI_RIGHT_SOFTKEY);

            /* Redraw rsk only when editor CUI is running and current screen is editor screen */
            if ((editor->state == CUI_FSEDITOR_STATE_RUN) &&
                (mmi_frm_scrn_get_active_id() == editor->editor_scr_id))
            {
                redraw_softkey(MMI_RIGHT_SOFTKEY);
            }
            break;
        case MMI_CENTER_SOFTKEY:
            if (icon != IMG_ID_CUI_FSEDITOR_DEFAULT)
            {
                editor->csk_icon = icon;
                editor->csk_change_flag = MMI_TRUE;
            }
            else
            {
                editor->csk_icon = CUI_FSEDITOR_DEFAULT_CSK_ICON;
                editor->csk_change_flag = MMI_FALSE;
            }

            if (editor->csk_icon == 0)
            {
                set_softkey_icon(NULL, MMI_CENTER_SOFTKEY);
            }
            else
            {
                set_softkey_icon((PU8)GetImage(editor->csk_icon), MMI_CENTER_SOFTKEY);
            }

            /* Redraw csk only when editor CUI is running and current screen is editor screen */
            if ((editor->state == CUI_FSEDITOR_STATE_RUN) &&
                (mmi_frm_scrn_get_active_id() == editor->editor_scr_id))
            {
                redraw_softkey(MMI_CENTER_SOFTKEY);
            }
            break;
    }
    register_softkey_handler(key_type);
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_characters_filter
 * DESCRIPTION
 *  Set allowed/disallowed filter character list.
 *  App can specify which character can/can't be inserted to editor
 * PARAMETERS
 *  fseditor_gid        [IN]        FSEditor CUI Group ID
 *  is_allowed          [IN]        MMI_TRUE: can be inserted, MMI_FALSE: Can't be inserted
 *  characters_list     [IN]        Filter character list
 * RETURNS
 *  void
 *****************************************************************************/
void cui_fseditor_set_characters_filter(mmi_id fseditor_gid, MMI_BOOL is_allowed, const UI_character_type *characters_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_struct *editor = (cui_fseditor_struct*) mmi_frm_group_get_user_data(fseditor_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (editor == NULL)
    {
        return;
    }
    editor->set_characters_flag = is_allowed;
    editor->set_characters_list = characters_list;
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_default_options_menu
 * DESCRIPTION
 *  Set default editor options menu item (Done/Cancel)
 *  App can use this API to change the Done/Cancel item to any other text
 *  NOTE: Editor will always send Submit event for Done, Abort event for Cancel menu item even if App
 *        has change its text.
 * PARAMETERS
 *  fseditor_gid                [IN]        FSEditor CUI Group ID
 *  options_done_label          [IN]        Editor Options done menu item label, use STR_ID_CUI_FSEDITOR_DEFAULT set to default value
 *  options_cancel_label        [IN]        Editor Options cancel menu item label, use STR_ID_CUI_FSEDITOR_DEFAULT set to default value
 * RETURNS
 *  void
 *****************************************************************************/
void cui_fseditor_set_default_options_menu(mmi_id fseditor_gid, U16 options_done_label, U16 options_cancel_label)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_struct *editor = (cui_fseditor_struct*) mmi_frm_group_get_user_data(fseditor_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (editor == NULL)
    {
        return;
    }
    if (options_done_label == STR_ID_CUI_FSEDITOR_DEFAULT)
    {
        editor->options_done_label = CUI_FSEDITOR_DEFAULT_OPTIONS_DONE;
    }
    else
    {
        editor->options_done_label = options_done_label;
    }

    if (options_cancel_label == STR_ID_CUI_FSEDITOR_DEFAULT)
    {
        editor->options_cancel_label = CUI_FSEDITOR_DEFAULT_OPTIONS_CANCEL;
    }
    else
    {
        editor->options_cancel_label = options_cancel_label;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_custom_options_menu
 * DESCRIPTION
 *  Set App custom options menu list. Custom options menu item will be add after Default menu item (Done/Cancel)
 *  Editor CUI will send EVT_ID_CUI_FSEDITOR_CUSTOM_MENU_SELECTED event to APP when custom options menu selected.
 * PARAMETERS
 *  fseditor_gid                [IN]        FSEditor CUI Group ID
 *  is_diable_defaut_menu       [IN]        If disable default menu item (Done/Cancel) or not
 *  menu_list                   [IN]        Custom options menu ID list
 *  count                       [IN]        Custom options menu count
 * RETURNS
 *  void
 *****************************************************************************/
void cui_fseditor_set_custom_options_menu(mmi_id fseditor_gid, MMI_BOOL is_diable_defaut_menu, PU16 menu_list, U8 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_struct *editor = (cui_fseditor_struct*) mmi_frm_group_get_user_data(fseditor_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (editor == NULL)
    {
        return;
    }
    editor->disable_def_opt_menu_flag = is_diable_defaut_menu;
    editor->options_cust_menu_list = menu_list;
    editor->options_cust_menu_count = count;
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_disable_cancel_options_item
 * DESCRIPTION
 *  Disable Cancel option item or item
 * PARAMETERS
 *  fseditor_gid                [IN]        FSEditor CUI Group ID
 *  is_diable                   [IN]        If disable Cancel) or not
 * RETURNS
 *  void
 *****************************************************************************/
void cui_fseditor_disable_cancel_options_item(mmi_id fseditor_gid, MMI_BOOL is_disable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_struct *editor = (cui_fseditor_struct*) mmi_frm_group_get_user_data(fseditor_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (editor == NULL)
    {
        return;
    }
    editor->disable_cancel_item = is_disable;
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_property
 * DESCRIPTION
 *  Set fseditor CUI property. Set all fseditor CUI property at once. App need to create a fseditor property structure
 *  and set the specify value. Example:
 * <code>
    cui_fseditor_property_struct fseditor_property;
    mmi_id fseditor = cui_fseditor_create(my_id);

    CUI_FSEDITOR_STRUCT_INIT(&fseditor_property);
    fseditor_property.buffer = g_buffer;
    fseditor_property.buffer_size = MMI_APP_EDITOR_BUFFER_SIZE;
    fseditor_property.edit_length = MMI_APP_EDITOR_LENGTH;
    fseditor_property.input_type = IMM_INPUT_MODE_123;
    fseditor_property.title = STR_APP_TITLE;
    fseditor_property.title_icon = IMG_APP_ICON;
    cui_fseditor_set_property(fseditor, &fseditor_property);
  * </code>  
 * PARAMETERS
 *  fseditor_gid                [IN]        FSEditor CUI Group ID
 *  s                           [IN]        FSeditor CUI structure
 * RETURNS
 *  void
 *****************************************************************************/
void cui_fseditor_set_property(mmi_id fseditor_gid, cui_fseditor_property_struct_p s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_struct *editor = (cui_fseditor_struct*) mmi_frm_group_get_user_data(fseditor_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (editor == NULL)
    {
        return;
    }
    editor->title = s->title;
    editor->title_icon = s->title_icon;
    editor->title_string = s->title_string;
    if (s->buffer_size <= CUI_FSEDITOR_MAX_BUFFER_SIZE)
    {
        if (s->buffer)
        {
            mmi_ucs2cpy((S8*)editor->text_buffer, (S8*)s->buffer);
            editor->buffer = editor->text_buffer;
        }
    }
    else
    {
        if (s->buffer)
        {
            editor->buffer = s->buffer;
        }
        else
        {
            /* App must use global/static memory for edit when size large than CUI_FSEDITOR_MAX_BUFFER_SIZE */
            MMI_ASSERT(0);
        }
    }
    editor->buffer_size = s->buffer_size;
    editor->edit_length = s->edit_length;
    editor->parent_data = s->parent_data;
    if (s->input_type)
    {
        editor->input_type = s->input_type;
    }
    editor->required_input_mode_set = s->required_input_mode_set;
    editor->input_ext_type = s->input_ext_type;
    if (s->lsk_label)
    {
        editor->lsk_label = s->lsk_label;
    }
    if (s->lsk_icon)
    {
        editor->lsk_icon = s->lsk_icon;
    }
    if (s->rsk_label)
    {
        editor->rsk_label = s->rsk_label;
    }
    if (s->rsk_icon)
    {
        editor->rsk_icon = s->rsk_icon;
    }
    if (s->csk_label)
    {
        editor->csk_label = s->csk_label;
    }
    if (s->csk_icon)
    {
        editor->csk_icon = s->csk_icon;
    }
    if (s->options_done_label)
    {
        editor->options_done_label = s->options_done_label;
    }
    if (s->options_cancel_label)
    {
        editor->options_cancel_label = s->options_cancel_label;
    }
    editor->options_cust_menu_list = s->options_cust_menu_list;
    editor->options_cust_menu_count = s->options_cust_menu_count;
    editor->set_characters_list = s->set_characters_list;
    editor->set_characters_flag = s->set_characters_flag;
    editor->disable_def_opt_menu_flag = s->disable_def_opt_menu_flag;
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_parent_data
 * DESCRIPTION
 *  Set parent data. App can set parent data and retrieve it by cui_fseditor_get_parent_data
 * PARAMETERS
 *  fseditor_gid        [IN]        FSEditor CUI Group ID
 *  parent_data         [IN]        Parent data
 * RETURNS
 *  void
 *****************************************************************************/
void cui_fseditor_set_parent_data(mmi_id fseditor_gid, U32 parent_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_struct *editor = (cui_fseditor_struct*) mmi_frm_group_get_user_data(fseditor_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(editor != NULL);
    editor->parent_data = parent_data;
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_get_parent_data
 * DESCRIPTION
 *  Get parent data. App can set parent data by cui_fseditor_set_parent_data
 * PARAMETERS
 *  fseditor_gid        [IN]        FSEditor CUI Group ID
 * RETURNS
 *  U32
 *****************************************************************************/
U32 cui_fseditor_get_parent_data(mmi_id fseditor_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_struct *editor = (cui_fseditor_struct*) mmi_frm_group_get_user_data(fseditor_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(editor != NULL);
    return editor->parent_data;
}


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_append_text
 * DESCRIPTION
 *  Append text to editor CUI buffer
 * PARAMETERS
 *  fseditor_gid        [IN]        FSEditor CUI Group ID
 *  text                [IN]        text
 * RETURNS
 *  U32
 *****************************************************************************/
void cui_fseditor_append_text(mmi_id fseditor_gid, WCHAR *text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_struct *editor = (cui_fseditor_struct*) mmi_frm_group_get_user_data(fseditor_gid);
    PU8 history_buffer = NULL;
    S32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(editor != NULL);
    history_buffer = mmi_frm_scrn_get_gui_buf(fseditor_gid, SCR_FSEDITOR);

    if (history_buffer)
    {
        AppendCategory5String(
            editor->input_type,
            (PU8)editor->buffer,
            editor->buffer_size,
            (PU8)text,
            history_buffer);
    }
    else
    {
        /* Current screen is editor screen */
        len = gui_strlen(text);
        wgui_inputs_ml_insert_string((UI_string_type)text, len, MMI_TRUE);
    }
}


#ifdef CUI_FSSEDITOR_APP_TEST_SAMPLE

// APP example

static mmi_id app_gid, fseditor_gid;
static U16 g_app_test_menu_list[2] = {MENU_ID_SMS_ED_TEMPL_OPT_SAVEAS_NEW_TEMPL_MENU, MENU_ID_SMS_TEMPLATES_OPTIONS_NEW_MENUENTRY};

mmi_ret mmi_app_fseditor_test_proc(mmi_event_struct* evt)
{
    switch(evt->evt_id)
    {
    case EVT_ID_GROUP_FIRST_ENTRY:
        break;
    case EVT_ID_GROUP_DEINIT:
        break;
    case EVT_ID_CUI_FSEDITOR_SUBMMIT:
        /* App handling */
        cui_fseditor_close(fseditor_gid);
        break;
    case EVT_ID_CUI_FSEDITOR_ABORT:
        /* App handling */
        cui_fseditor_close(fseditor_gid);
        break;
    case EVT_ID_CUI_FSEDITOR_EMPTY:
        /* App handling */
        cui_fseditor_set_softkey_text(fseditor_gid, MMI_LEFT_SOFTKEY, STR_GLOBAL_SEARCH);
        cui_fseditor_set_softkey_text(fseditor_gid, MMI_RIGHT_SOFTKEY, STR_GLOBAL_EXIT);
        cui_fseditor_set_title(fseditor_gid, STR_GLOBAL_EMPTY, IMG_SMS_ENTRY_SCRN_CAPTION);
        break;
    case EVT_ID_CUI_FSEDITOR_NOT_EMPTY:
        /* App handling */
        cui_fseditor_set_softkey_text(fseditor_gid, MMI_LEFT_SOFTKEY, STR_ID_CUI_FSEDITOR_DEFAULT);
        cui_fseditor_set_softkey_text(fseditor_gid, MMI_RIGHT_SOFTKEY, STR_ID_CUI_FSEDITOR_DEFAULT);
        cui_fseditor_set_title(fseditor_gid, STR_GLOBAL_SAVE, IMG_SMS_ENTRY_SCRN_CAPTION);
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_app_fseditor_cui_test1
 * DESCRIPTION
 *  Fseditor CUI App test sample1
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_app_fseditor_cui_test1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_property_struct fseditor_property;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    app_gid = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_app_fseditor_test_proc, NULL);
    mmi_frm_group_enter(app_gid, 0);
    
    if ((fseditor_gid = cui_fseditor_create(app_gid)) != NULL)
    {
        CUI_FSEDITOR_STRUCT_INIT(&fseditor_property);	  /* initialize property structure */
        fseditor_property.buffer = g_app_buffer;
        fseditor_property.buffer_size = MMI_APP_EDITOR_BUFFER_SIZE;
        fseditor_property.edit_length = MMI_APP_EDITOR_LENGTH;
        fseditor_property.input_type = IMM_INPUT_TYPE_SENTENCE;
        fseditor_property.title = STR_APP_TITLE;
        fseditor_property.title_icon = IMG_APP_ICON;
        cui_fseditor_set_property(fseditor, &fseditor_property);
        cui_fseditor_run(fseditor_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_app_fseditor_cui_test2
 * DESCRIPTION
 *  Fseditor CUI App test sample2
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_app_fseditor_cui_test2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    app_gid = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_app_fseditor_test_proc, NULL);
    mmi_frm_group_enter(app_gid, 0);
    
    if ((fseditor_gid = cui_fseditor_create(app_gid)) != NULL)
    {
        cui_fseditor_set_title(fseditor_gid, STR_APP_TITLE, IMG_APP_ICON);
        cui_fseditor_set_text(fseditor_gid, (PU8)g_app_buffer, MMI_APP_EDITOR_BUFFER_SIZE, MMI_APP_EDITOR_LENGTH);
        cui_fseditor_set_input_method(fseditor_gid, IMM_INPUT_TYPE_SENTENCE, 0);
        cui_fseditor_run(fseditor_gid);
    }
}
#endif /* CUI_FSSEDITOR_APP_TEST_SAMPLE */
