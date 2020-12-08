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
 *   wgui_inputs_multiline.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   wgui layer of multiline inputbox
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "wgui_virtual_keyboard.h"
#include "phbsrvgprot.h"
#include "gui_font_size.h"
#include "gui_inputs_internal.h"
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)  
#include "mmi_frm_gestures.h"
#endif

#include "gui_touch_feedback.h"
#include "wgui_categories_UCE.h"

    #include "gui_inputs.h"
    #include "MMIDataType.h"
    #include "MMI_features.h"
    #include "kal_general_types.h"
    #include "gui.h"
    #include "gui_config.h"
    #include "lcd_sw_inc.h"
    #include "Gui_Setting.h"
    #include "wgui_inputs.h"
    #include "gui_data_types.h"
    #include "wgui_categories_list.h"
    #include "wgui_categories_inputs.h"
    #include "mmi_frm_events_gprot.h"
    #include "CommonScreensResDef.h"
    #include "GlobalConstants.h"
    #include "ImeGprot.h"
    #include "wgui_inline_edit.h"
    #include "gui_switch.h"
    #include "wgui.h"
    #include "wgui_fixed_menus.h"
    #include "gui_fixed_menus.h"
    #include "PixcomFontEngine.h"
    #include "FontRes.h"
    #include "wgui_include.h"
    #include "gui_themes.h"
    #include "kal_public_api.h"
    #include "gui_scrollbars.h"
    #include "wgui_categories_util.h"
    #include "wgui_draw_manager.h"
    #include "gdi_include.h"
    #include "mmi_frm_input_gprot.h"
    #include "gui_typedef.h"
    #include "wgui_touch_screen.h"
    #include "mmi_rp_app_uiframework_def.h"
    #include "mmi_frm_timer_gprot.h"
    #include "string.h"
    #include "gui_virtual_keyboard_language_type.h"
    #include "CustThemesRes.h"
    #include "GlobalResDef.h"
    #include "DebugInitDef_Int.h"
    #include "mmi_frm_history_gprot.h"
    #include "wgui_categories_enum.h"
    #include "wgui_categories_defs.h"
    #include "Unicodexdcl.h"
    #include "wgui_categories_search.h"
    #include "wgui_categories_text_viewer.h"
    #include "gui_dynamic_menus.h"
    #include "wgui_categories_MMS_viewer.h"
    #include "mmi_frm_gestures_gprot.h"
    #include "mmi_clipboard_gprot.h"
    #include "custom_hw_default.h"
    
    #include "wgui_categories_idlescreen_op.h"
    #include "wgui_dynamic_menus.h"
    
/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
multi_line_input_box MMI_multiline_inputbox;

S32 MMI_multiline_inputbox_x;
S32 MMI_multiline_inputbox_y;
S32 MMI_multiline_inputbox_width;
S32 MMI_multiline_inputbox_height;

#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
pBOOL wgui_paging_show_percentage = 0;
#endif /* __UI_PAGING_IN_MULTILINE_EDITOR__ */

typedef void (*percentage_hdlr) (S32 value);
percentage_hdlr percentage_callback = NULL;

typedef void (*stop_scroll_hdlr)(void);
stop_scroll_hdlr stop_auto_scroll_callback = NULL;

static BOOL multi_line_pen_down_hilite_flag = MMI_FALSE;

void (*multiline_inputbox_input_callback) (void);
void (*multiline_inputbox_navigate_callback) (void) = UI_dummy_function;

void (*multiline_inputbox_set_key_callback) (void) = NULL;

#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
S32 wgui_multiline_inputbox_frame_counter = 0;
#endif 

S32 redraw_on_input_method_change = 0;

#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
static U8 shared_data[GUI_SHARED_BYTES];
gui_page_info_app gui_page_info;
#endif

/* for linebase mode */
wgui_ml_line_base_info linebase_page_info;

#ifdef __MMI_INDIC_ALG__
U32 add_template_multiline_flag =0;
extern void gui_multi_line_post_template_addition_adjustment(multi_line_input_box *b);
#endif /* __MMI_INDIC_ALG__ */

S32 wgui_inputbox_buffer_size = 0;

S8 g_mmi_wgui_halfline_marquee_scroll_enable = 0;

void (*wgui_inputbox_RSK_function) (void) = NULL;
U8 wgui_inputbox_RSK_label_clear = 0;

/* store label string of RSK of input box */
UI_string_type wgui_inputbox_RSK_label_string;

/* store label icon of RSK key */
PU8 wgui_inputbox_RSK_label_icon;

/* flag used to check decimal input in multline input box */
U8 wgui_multiline_inputbox_decimal_flag = 0;

/* flag used to store decimal input mode flag */
U8 wgui_multiline_inputbox_decimal_input_mode_flag = 0;

static wgui_multiline_icon_handler_struct g_mmi_wgui_multiline_icon_handler_cntx;

/* e-dic */
void (*wgui_register_multiline_inputbox_up_down_key_handler) (void) = NULL;

static U8 *wgui_multiline_history_buffer = NULL;
static S16 wgui_multiline_history_ID = (S16)-1;

#ifdef __MMI_TOUCH_SCREEN__
pBOOL full_screen_flag;

#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
/* for async pen event handler callback */
static void (*multiline_paging_async_pen_callback)(void) = NULL;
#endif

/* Pen down cursor_p, when pen up, we'll locate cursor to the position when
   pen down */
UI_buffer_type g_wgui_inputs_ml_pen_down_cursor_p = NULL;

static MMI_BOOL wgui_inputbox_pen_down_inside_multiline_with_hilite_flag = MMI_FALSE;

#endif /* __MMI_TOUCH_SCREEN__ */

#define WGUI_PAGING_SCROLL_TIMER     200

static void wgui_inputs_ml_handle_left_arrow_repeat(void);
static void wgui_inputs_ml_handle_right_arrow_repeat(void);
static void wgui_inputs_ml_handle_up_arrow_repeat(void);
static void wgui_inputs_ml_handle_down_arrow_repeat(void);

#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
static void wgui_inputs_ml_inline_handle_up_arrow_repeat(void);
static void wgui_inputs_ml_inline_handle_up_arrow_repeat(void);
#endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 


static wgui_inputs_ml_key_hdlr g_wgui_inputs_ml_pre_key_handler = NULL;
static MMI_BOOL wgui_inputs_ml_pre_key_handler(U16 key_code, U16 key_type);
static FuncPtr g_wgui_inputs_ml_pre_delete_handler = NULL;

#ifdef __MMI_EDITOR_MULTILINE_DIALER_STYLE_SUPPORT__
static void wgui_inputs_ml_change_callback(void);
static void wgui_inputs_ml_handle_plus_key(void);
#endif
static void wgui_inputs_ml_handle_input_int(S32 show_counter_flag);/* slim_2_2 */ //
static void wgui_inputs_ml_set_RSK_int(S32 show_counter_flag);/* slim_2_2 */ //

// clear key delete all flag. By default the clear key long press will fast delete character by character
static MMI_BOOL g_wgui_inputs_is_clear_key_delete_all = MMI_FALSE;

/***************************************************************************** 
 * Global Function
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_register_input_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_register_input_callback(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    multiline_inputbox_input_callback = f;
}

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_register_validation_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_register_validation_callback(void (*f) (UI_buffer_type text, UI_buffer_type cursor, S32 text_length))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputbox_validation_callback = f;
}

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_register_navigate_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_register_navigate_callback(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    multiline_inputbox_navigate_callback = f;
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
/* under construction !*/
#endif 
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_create_set_buffer
 * DESCRIPTION
 *  Creates a multiline inputbox
 *  
 *  Displays the text that was passed and allows editing
 * PARAMETERS
 *  buffer              [IN]        Is the buffer to use
 *  buffer_length       [IN]        Is the length of the buffer to use
 *  text_length         [IN]        Is the length of the text in the buffer
 *  edit_position       [IN]        Is the cursor position on entry
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_create_set_buffer(UI_string_type buffer, S32 buffer_length, S32 text_length, S32 edit_position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    multiline_inputbox_input_callback = UI_dummy_function;
    multiline_inputbox_navigate_callback = UI_dummy_function;
    MMI_current_input_ext_type = 0;
    /* Warning: Temporary change only UCS2 / ASCII. This has to be done in a more formal manner  */
#ifdef __UCS2_ENCODING
    gui_create_multi_line_input_box_set_buffer(
        &MMI_multiline_inputbox,
        MMI_multiline_inputbox_x,
        MMI_multiline_inputbox_y,
        MMI_multiline_inputbox_width,
        MMI_multiline_inputbox_height,
        buffer,
        buffer_length * 2,
        (text_length + 1) * 2,
        edit_position);
#endif /* __UCS2_ENCODING */ 
#ifdef __ASCII
    gui_create_multi_line_input_box_set_buffer(
        &MMI_multiline_inputbox,
        MMI_multiline_inputbox_x,
        MMI_multiline_inputbox_y,
        MMI_multiline_inputbox_width,
        MMI_multiline_inputbox_height,
        buffer,
        buffer_length,
        text_length + 1,
        edit_position);
#endif /* __ASCII */ 
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
    wgui_multiline_inputbox_frame_counter = 0;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_create_set_buffer_no_text_reset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer              [IN]        
 *  buffer_length       [IN]        
 *  text_length         [IN]        
 *  edit_position       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_create_set_buffer_no_text_reset(
        UI_string_type buffer,
        S32 buffer_length,
        S32 text_length,
        S32 edit_position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    multiline_inputbox_input_callback = UI_dummy_function;
    multiline_inputbox_navigate_callback = UI_dummy_function;
    MMI_current_input_ext_type = 0;
    /* Warning: Temporary change only UCS2 / ASCII. This has to be done in a more formal manner  */
#ifdef __UCS2_ENCODING
    gui_create_multi_line_input_box_set_buffer_no_text_reset(
        &MMI_multiline_inputbox,
        MMI_multiline_inputbox_x,
        MMI_multiline_inputbox_y,
        MMI_multiline_inputbox_width,
        MMI_multiline_inputbox_height,
        buffer,
        buffer_length * 2,
        (text_length + 1) * 2,
        edit_position);
#endif /* __UCS2_ENCODING */ 
#ifdef __ASCII
    gui_create_multi_line_input_box_set_buffer_no_text_reset(
        &MMI_multiline_inputbox,
        MMI_multiline_inputbox_x,
        MMI_multiline_inputbox_y,
        MMI_multiline_inputbox_width,
        MMI_multiline_inputbox_height,
        buffer,
        buffer_length,
        text_length + 1,
        edit_position);
#endif /* __ASCII */ 
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
    wgui_multiline_inputbox_frame_counter = 0;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_resize_fit
 * DESCRIPTION
 *  Changes the size of the multiline inputbox to fit content
 * PARAMETERS
 *  width           [IN]        Are the new dimensions
 *  height          [IN]        Are the new dimensions
 *  fit_width       [?]         
 *  fit_height      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_resize_fit(S32 width, S32 height, S32 *fit_width, S32 *fit_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_resize_multi_line_input_box(&MMI_multiline_inputbox, width, height);
    wgui_inputs_ml_show_no_draw();
    gui_set_font(MMI_multiline_inputbox.text_font);
    gui_resize_multi_line_input_box(
        &MMI_multiline_inputbox,
        MMI_multiline_inputbox.width,
        MMI_multiline_inputbox.text_height + MULTILINE_INPUTBOX_HEIGHT_PAD + MMI_multiline_inputbox.text_y + MMI_multiline_inputbox.margin.down_margin);
    *fit_width = width;
    *fit_height = MMI_multiline_inputbox.text_height + MULTILINE_INPUTBOX_HEIGHT_PAD + MMI_multiline_inputbox.text_y + MMI_multiline_inputbox.margin.down_margin;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_resize
 * DESCRIPTION
 *  Changes the size of the multiline inputbox
 * PARAMETERS
 *  width       [IN]        Are the new dimensions
 *  height      [IN]        Are the new dimensions
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_resize(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (width == WGUI_INPUTS_STYLE_DEFAULT)
    {
        width = MMI_multiline_inputbox.width;
    }
    
    if (height == WGUI_INPUTS_STYLE_DEFAULT)
    {
        height = MMI_multiline_inputbox.height;
    }

    gui_resize_multi_line_input_box(&MMI_multiline_inputbox, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_move
 * DESCRIPTION
 *  Changes the size of the multiline inputbox
 * PARAMETERS
 *  x       [IN]        Is the new position of the multiline inputbox
 *  y       [IN]        Is the new position of the multiline inputbox
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_move(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (x == WGUI_INPUTS_STYLE_DEFAULT)
    {
        x = MMI_multiline_inputbox.x;
    }
    
    if (y == WGUI_INPUTS_STYLE_DEFAULT)
    {
        y = MMI_multiline_inputbox.y;
    }

    gui_move_multi_line_input_box(&MMI_multiline_inputbox, x, y);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_show
 * DESCRIPTION
 *  Displays the multiline inputbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_show_multi_line_input_box(&MMI_multiline_inputbox);
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_BLT_double_buffer(
        MMI_multiline_inputbox.x,
        MMI_multiline_inputbox.y,
        MMI_multiline_inputbox.x + MMI_multiline_inputbox.width,
        MMI_multiline_inputbox.y + MMI_multiline_inputbox.height);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_show_no_draw
 * DESCRIPTION
 *  Refreshes the multiline inputbox without redrawing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_show_no_draw(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_show_multi_line_input_box(&MMI_multiline_inputbox);
    // MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_multi_line_input_box_no_draw(&MMI_multiline_inputbox);
}

#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_end_frame
 * DESCRIPTION
 *  Redraws the multiline inputbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_end_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_multiline_inputbox_frame_counter >= 1)
    {
        S32 y2, BLT_y2;

        gui_show_multi_line_input_box(&MMI_multiline_inputbox);
        if (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INCLUDE_INFO_AREA)
        {
            if (wgui_inputbox_information_flag)
            {
                wgui_inputs_ml_redraw_input_information_bar();
            }
        }
        BLT_y2 = MMI_multiline_inputbox.y + MMI_multiline_inputbox.height;
        y2 = MMI_multitap_y + MMI_multitap_height + 1;
        if (BLT_y2 < y2)
        {
            BLT_y2 = y2;
        }
    #if(UI_DOUBLE_BUFFER_SUPPORT)
        gui_BLT_double_buffer(
            MMI_multiline_inputbox.x,
            MMI_multiline_inputbox.y,
            MMI_multiline_inputbox.x + MMI_multiline_inputbox.width - 1,
            BLT_y2);
    #endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
        wgui_multiline_inputbox_frame_counter = 0;
        gui_start_timer(UI_FRAME_SKIP_TIMEOUT, wgui_inputs_ml_end_frame);
    }
}

#endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING)) */ 


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_redraw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_redraw(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FRM_HISTORY__
    if (GetExitScrnID() != SCR_POPUP_SCREEN)
#endif
    {
    #if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
        if (wgui_multiline_inputbox_frame_counter > 0)
        {
            wgui_multiline_inputbox_frame_counter++;
        }
        else
        {
            wgui_multiline_inputbox_frame_counter = 1;
            gui_start_timer(UI_FRAME_START_TIMEOUT, wgui_inputs_ml_end_frame);
        }
    #else /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING)) */ 
		{
			gui_show_multi_line_input_box(&MMI_multiline_inputbox);
		}

    #ifdef __MMI_FTE_SUPPORT__
         if ((wgui_inputs_get_editor_handler()->input_box_sub_type == MMI_EDITOR_INPUT_BOX_EBOOK)
             && mmi_imc_is_clipboard_state() && percentage_callback)
         {
             percentage_callback(MMI_multiline_inputbox.visible_line_info->start_line_index);
         }
    #endif
        gui_BLT_double_buffer(
            MMI_multiline_inputbox.x,
            MMI_multiline_inputbox.y,
            MMI_multiline_inputbox.x + MMI_multiline_inputbox.width,
            MMI_multiline_inputbox.y + MMI_multiline_inputbox.height);
    #endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING)) */ 
    }
}

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_multitap_input_string
 * DESCRIPTION
 *  inserts a multitap character
 *  
 *  Normally called by multitap handlers
 * PARAMETERS
 *  str       [IN]        Is the string to be inserted
 * RETURNS
 *  S32
 *****************************************************************************/
S32 wgui_inputs_ml_multitap_input_string(PU8 str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_EDITOR_MULTILINE_SUPPORT_MULTIGRAPH__
    ret = gui_multi_line_input_box_insert_multitap_string(&MMI_multiline_inputbox, str);
    
    if (ret)
    {
	    wgui_inputs_ml_redraw();
	    
	#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
	    if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INCLUDE_INFO_AREA))
	#endif 
	        multiline_inputbox_input_callback();
	}
	 
    #endif /*__MMI_EDITOR_MULTILINE_SUPPORT_MULTIGRAPH__*/
	return ret;
}

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_multitap_input
 * DESCRIPTION
 *  inserts a multitap character
 *  
 *  Normally called by multitap handlers
 * PARAMETERS
 *  c       [IN]        Is the character to be inserted
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL wgui_inputs_ml_multitap_input(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_PLUS_CHARACTER_HANDLING)
    {
        if ((c == '+') && (MMI_multiline_inputbox.text[0] != '+') && (MMI_multiline_inputbox.cursor_p == MMI_multiline_inputbox.text) && (MMI_multiline_inputbox.text_length >= MMI_multiline_inputbox.available_length))
        {
            MMI_multiline_inputbox.available_length = (wgui_inputbox_buffer_size + 1) * ENCODING_LENGTH;
            gui_multi_line_input_box_start_input(&MMI_multiline_inputbox);
        }
        else if (MMI_multiline_inputbox.available_length == (wgui_inputbox_buffer_size + 1) * ENCODING_LENGTH)
        {
            if (MMI_multiline_inputbox.text_length == MMI_multiline_inputbox.available_length)
            {
                if (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP)
                {
                    if (MMI_multiline_inputbox.cursor_p == MMI_multiline_inputbox.text + ENCODING_LENGTH)
                    {
                        if (c != '+')
                        {
                            gui_multi_line_input_box_delete_character_in_pos(&MMI_multiline_inputbox, 0);
                            gui_multi_line_input_box_confirm_multitap_character(&MMI_multiline_inputbox);
                            if (MMI_multiline_inputbox.text[0] == '+')
                            {
                                MMI_multiline_inputbox.available_length = (wgui_inputbox_buffer_size + 1) * ENCODING_LENGTH;
                            }
                            else
                            {
                                MMI_multiline_inputbox.available_length = wgui_inputbox_buffer_size * ENCODING_LENGTH;
                            }
                            gui_multi_line_input_box_stop_input(&MMI_multiline_inputbox);
                            UI_editor_play_tone_cannot_insert();
                            return MMI_FALSE;
                        }
                    }
                }
                else
                {
                    UI_editor_play_tone_cannot_insert();
                    return MMI_FALSE;
                }
            }
            else if ((MMI_multiline_inputbox.text_length == MMI_multiline_inputbox.available_length - ENCODING_LENGTH) &&
                    (c != '+') && (MMI_multiline_inputbox.cursor_p == MMI_multiline_inputbox.text))
            {
                if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP))
                {
                    UI_editor_play_tone_cannot_insert();
                    return MMI_FALSE;
                }
            }
        }
        else if ((MMI_multiline_inputbox.text_length == MMI_multiline_inputbox.available_length) &&
                (MMI_multiline_inputbox.cursor_p == MMI_multiline_inputbox.text) &&
                (MMI_multiline_inputbox.available_length == wgui_inputbox_buffer_size * ENCODING_LENGTH) &&
                (c != '+'))
		{
			UI_editor_play_tone_cannot_insert();
			return MMI_FALSE;
		}
    }

    ret = gui_multi_line_input_box_insert_multitap_character(&MMI_multiline_inputbox, c);
    if (ret)
    {
    #ifdef __MMI_EDITOR_MULTILINE_DIALER_STYLE_SUPPORT__
        if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_DIALER_STYLE)
        {
            wgui_inputs_ml_handle_plus_key();
        }
    #endif /* __MMI_EDITOR_MULTILINE_DIALER_STYLE_SUPPORT__ */

	    wgui_inputs_ml_redraw();
	    
	#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
	    if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INCLUDE_INFO_AREA))
	#endif 
	        multiline_inputbox_input_callback();
	}
	
	return ret;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_multitap_input_complete
 * DESCRIPTION
 *  Completes a multitap input sequence
 *  
 *  Normally called by multitap handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_multitap_input_complete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_multi_line_input_box_confirm_multitap_character(&MMI_multiline_inputbox);
    wgui_inputs_ml_redraw();
    
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_direct_input
 * DESCRIPTION
 *  Inserts a character
 *  
 *  Normally registered with keyboard handlers (simulator)
 * PARAMETERS
 *  c       [IN]        Is a character to be inserted
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_inputs_ml_direct_input(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_PLUS_CHARACTER_HANDLING)
    {
        if ((c == '+') && (MMI_multiline_inputbox.cursor_p == MMI_multiline_inputbox.text))
        {
            MMI_multiline_inputbox.available_length = (wgui_inputbox_buffer_size + 1) * ENCODING_LENGTH;
        }

        /* If + is at the starting place followed by 40 number, it should not allow to insert any character before and after + */
        if ((MMI_multiline_inputbox.text[0] == '+') &&
            (((MMI_multiline_inputbox.cursor_p == MMI_multiline_inputbox.text) &&
              (MMI_multiline_inputbox.text_length >= (MMI_multiline_inputbox.available_length - ENCODING_LENGTH))) ||
             ((MMI_multiline_inputbox.cursor_p == (MMI_multiline_inputbox.text + ENCODING_LENGTH)) &&
              (MMI_multiline_inputbox.text_length == MMI_multiline_inputbox.available_length))))
        {
            UI_editor_play_tone_cannot_insert();
            return MMI_FALSE;
        }
    }
    if (UI_TEST_LF_CHARACTER(c))
    {
        if (gui_multi_line_input_box_insert_newline(&MMI_multiline_inputbox))
        {
            ret = MMI_TRUE;
        }
        else
        {
            ret = MMI_FALSE;
        }
    }
    else
    {
        ret = gui_multi_line_input_box_insert_character(&MMI_multiline_inputbox, c);

    #ifdef __MMI_EDITOR_MULTILINE_DIALER_STYLE_SUPPORT__
        if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_DIALER_STYLE)
        {
            wgui_inputs_ml_handle_plus_key();
        }
    #endif /* __MMI_EDITOR_MULTILINE_DIALER_STYLE_SUPPORT__ */
    }
    
    wgui_inputs_ml_redraw();

    if (ret)
    {
    #if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
        if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INCLUDE_INFO_AREA))
    #endif 
            multiline_inputbox_input_callback();
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_direct_input_no_draw
 * DESCRIPTION
 *  Inserts a character
 *  
 *  Normally registered with keyboard handlers (simulator)
 * PARAMETERS
 *  c       [IN]        Is a character to be inserted
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_inputs_ml_direct_input_no_draw(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_PLUS_CHARACTER_HANDLING)
    {
        if ((c == '+') && (MMI_multiline_inputbox.cursor_p == MMI_multiline_inputbox.text))
        {
            MMI_multiline_inputbox.available_length = (wgui_inputbox_buffer_size + 1) * ENCODING_LENGTH;
        }
        else if ((MMI_multiline_inputbox.text[0] == '+') && (MMI_multiline_inputbox.cursor_p == MMI_multiline_inputbox.text)
            && (MMI_multiline_inputbox.text_length >= (MMI_multiline_inputbox.available_length - ENCODING_LENGTH)))
        {
            UI_editor_play_tone_cannot_insert();
            return MMI_FALSE;
        }
    }
    if (UI_TEST_LF_CHARACTER(c))
    {
        if (gui_multi_line_input_box_insert_newline(&MMI_multiline_inputbox))
        {
            ret = MMI_TRUE;
        }
        else
        {
            ret = MMI_FALSE;
        }
    }
    else if (c == '.')
    {
        if (wgui_multiline_inputbox_decimal_input_mode_flag)
        {
            if (wgui_multiline_inputbox_decimal_flag)
            {
                return MMI_FALSE;
            }
        }
        ret = gui_multi_line_input_box_insert_character(&MMI_multiline_inputbox, c);
        if (ret)
        {
            if (wgui_multiline_inputbox_decimal_input_mode_flag)
            {
                wgui_multiline_inputbox_decimal_flag = 1;
            }
        }
    }
    else
    {
        ret = gui_multi_line_input_box_insert_character(&MMI_multiline_inputbox, c);
        #ifdef __MMI_EDITOR_MULTILINE_DIALER_STYLE_SUPPORT__
        if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_DIALER_STYLE)
        {
            wgui_inputs_ml_handle_plus_key();
        }
        #endif /* __MMI_EDITOR_MULTILINE_DIALER_STYLE_SUPPORT__ */        
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_direct_input_no_LF_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_direct_input_no_LF_check(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_PLUS_CHARACTER_HANDLING)
    {
        if ((c == '+') && (MMI_multiline_inputbox.cursor_p == MMI_multiline_inputbox.text))
        {
            MMI_multiline_inputbox.available_length = (wgui_inputbox_buffer_size + 1) * ENCODING_LENGTH;
        }
        else if ((MMI_multiline_inputbox.text[0] == '+') && (MMI_multiline_inputbox.cursor_p == MMI_multiline_inputbox.text)
            && (MMI_multiline_inputbox.text_length >= (MMI_multiline_inputbox.available_length - ENCODING_LENGTH)))
        {
            UI_editor_play_tone_cannot_insert();
            return;
        }
    }
    gui_multi_line_input_box_insert_character(&MMI_multiline_inputbox, c);
    wgui_inputs_ml_redraw();
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
    if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INCLUDE_INFO_AREA))
#endif 
        multiline_inputbox_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_delete_character
 * DESCRIPTION
 *  Deletes a character before the cursor position (Backspace)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_delete_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_ml_delete_character_no_draw();
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
/* under construction !*/
/* under construction !*/
    #endif
    wgui_inputs_ml_redraw();
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
    if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INCLUDE_INFO_AREA))
#endif 
        multiline_inputbox_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_delete_character_no_draw
 * DESCRIPTION
 *  Deletes a character before the cursor position (Backspace)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_delete_character_no_draw(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_multiline_inputbox_decimal_input_mode_flag)
    {
        if (wgui_multiline_inputbox_decimal_flag)
        {
            UI_buffer_type p = MMI_multiline_inputbox.cursor_p;
            UI_character_type c;
            
            if (p != MMI_multiline_inputbox.text)
            {
                UI_STRING_GET_PREVIOUS_CHARACTER(p, c);
                if (c == (UI_character_type) '.')
                {
                    wgui_multiline_inputbox_decimal_flag = 0;
                }
            }
        }
    }

    gui_multi_line_input_box_delete_character(&MMI_multiline_inputbox);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_previous_character
 * DESCRIPTION
 *  Moves the cursor to the previous character
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_previous_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SMART_ALPHABETIC_RESELECTION__)  
    UI_buffer_type words_start_p = MMI_multiline_inputbox.cursor_p;
	UI_buffer_type old_cursor_p = MMI_multiline_inputbox.cursor_p;
    UI_character_type c;
    MMI_BOOL is_valid_cluster = MMI_FALSE;
    S32 word_length = 0;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wgui_inputs_ml_pre_key_handler)
    {
        if (g_wgui_inputs_ml_pre_key_handler(KEY_LEFT_ARROW))
        {
            return;
        }
    }

#if defined(__MMI_SMART_ALPHABETIC_RESELECTION__)   
    if (mmi_imc_is_reselection_input_mode(mmi_imm_get_curr_input_mode())
        && mmi_imc_is_smart_alphabetic_word_reselection_enabled())
    {
        c = (UI_character_type)((*((words_start_p)+0))|((*((words_start_p)+1))<<8));

        if (c != 0x20 && c != 0x0D && c != 0x0A && c != 0)
        {
            gui_multi_line_input_box_next(&MMI_multiline_inputbox);

            is_valid_cluster = mmi_imc_is_valid_alphabetic_word_of_current_input_mode((U8 *)words_start_p, 
                                                                                      (MMI_multiline_inputbox.cursor_p - words_start_p)/ENCODING_LENGTH);

            gui_multi_line_input_box_previous(&MMI_multiline_inputbox);
        }

        if (c == 0x20 || c == 0 || c == 0x0D || c == 0x0A || !is_valid_cluster)
        {
            if (words_start_p > MMI_multiline_inputbox.text)
            {
                do
                {
                    words_start_p -= ENCODING_LENGTH;
                    c = (UI_character_type)((*((words_start_p)+0))|((*((words_start_p)+1))<<8));

                    if (!(c != 0x20 && c != 0x0D && c != 0x0A && mmi_imc_is_valid_alphabetic_word_of_current_input_mode((U8 *)&c, 1)))
                    {
                        break;
                    }
 
                    word_length++;

                }while (word_length <= mmi_imc_get_max_reselection_word_length() && words_start_p > MMI_multiline_inputbox.text);
            }
            
            if (word_length <= mmi_imc_get_max_reselection_word_length() && word_length > 0)
            {
                MMI_multiline_inputbox.cursor_p = words_start_p;

                #ifdef GUI_INPUT_BOX_CACHE_SUPPORT
                    gui_mlc_all_line_update();
                #endif

                gui_show_multi_line_input_box_ext(&MMI_multiline_inputbox, -1, -1);

                if (c != 0 && (c == 0x20 || c == 0x0D || c == 0x0A || !mmi_imc_is_valid_alphabetic_word_of_current_input_mode((U8 *)&c, 1)) 
                    && MMI_multiline_inputbox.cursor_p < old_cursor_p
                    && MMI_multiline_inputbox.cursor_p == words_start_p)
                {
				    gui_multi_line_input_box_next(&MMI_multiline_inputbox);
                }    
            
                words_start_p = MMI_multiline_inputbox.cursor_p;

                c = (UI_character_type)((*((words_start_p)+0))|((*((words_start_p)+1))<<8));

                MMI_multiline_inputbox.cursor_p = old_cursor_p;

                #ifdef GUI_INPUT_BOX_CACHE_SUPPORT
                    gui_mlc_all_line_update();
                #endif

                gui_show_multi_line_input_box_ext(&MMI_multiline_inputbox, -1, -1);
            
                if ((c != 0x20 && c != 0x0D && c != 0x0A && mmi_imc_is_valid_alphabetic_word_of_current_input_mode((U8 *)&c, 1))&& words_start_p < MMI_multiline_inputbox.cursor_p)
                {
                    if (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT)
                    {
                        MMI_multiline_inputbox.cursor_p = words_start_p;
                        MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
                    
                        gui_multi_line_input_box_stop_input(&MMI_multiline_inputbox);
                    
                    #ifdef GUI_INPUT_BOX_CACHE_SUPPORT
                        gui_mlc_all_line_update();
                    #endif

                        gui_show_multi_line_input_box_ext(&MMI_multiline_inputbox, -1, -1);

					    if (old_cursor_p != MMI_multiline_inputbox.cursor_p)
					    {
                            MMI_multiline_inputbox.cursor_fixed_x = -1;
					    }
                    
					    if (words_start_p > MMI_multiline_inputbox.text) 
					    {
						    c = (UI_character_type)((*((words_start_p - 2)+0))|((*((words_start_p - 2)+1))<<8));

						    if (c == 0x20) 
						    {
                                gui_multi_line_input_box_previous(&MMI_multiline_inputbox);

							    words_start_p = MMI_multiline_inputbox.cursor_p;
						    }
					    }
                    
                        wgui_inputs_ml_redraw();

                        mmi_imc_key_unhighlight_alphabetic_word();
                    
                        return;
                    }
                    else if (mmi_imc_is_valid_alphabetic_word_of_current_input_mode(words_start_p, (MMI_multiline_inputbox.cursor_p - words_start_p) / ENCODING_LENGTH))
                    {
                        MMI_multiline_inputbox.highlight_start_position = words_start_p;
                        MMI_multiline_inputbox.highlight_end_position = MMI_multiline_inputbox.cursor_p;
                        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
                    
                        gui_multi_line_input_box_start_input(&MMI_multiline_inputbox);
                    
					    if (old_cursor_p != MMI_multiline_inputbox.cursor_p)
					    {
                            MMI_multiline_inputbox.cursor_fixed_x = -1;
					    }
                    
                        wgui_inputs_ml_redraw();

                        mmi_imc_key_highlight_alphabetic_word();
                    
                        return;
                    }
                }
            }
        }
    }

	if (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT)
	{
        MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;

        gui_multi_line_input_box_stop_input(&MMI_multiline_inputbox);
	}
#endif /* #if defined(__MMI_SMART_ALPHABETIC_RESELECTION__)   */
    {
        gui_multi_line_input_box_previous(&MMI_multiline_inputbox);
        wgui_inputs_ml_redraw();
        multiline_inputbox_navigate_callback();
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_next_character
 * DESCRIPTION
 *  Moves the cursor to the next character
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_next_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SMART_ALPHABETIC_RESELECTION__)  
    UI_buffer_type words_end_p = MMI_multiline_inputbox.cursor_p;
    UI_buffer_type old_cursor_p = MMI_multiline_inputbox.cursor_p;
    MMI_BOOL is_valid_pre_cluster = MMI_FALSE, is_valid_cluster = MMI_FALSE;
    S32 word_length = 0;
#endif
    UI_character_type c = 0, pre_c = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wgui_inputs_ml_pre_key_handler)
    {
        if (g_wgui_inputs_ml_pre_key_handler(KEY_RIGHT_ARROW))
        {
            return;
        }
    }

#if defined(__MMI_SMART_ALPHABETIC_RESELECTION__)   

    if (mmi_imc_is_reselection_input_mode(mmi_imm_get_curr_input_mode()))
    {
        if (words_end_p > MMI_multiline_inputbox.text)
        {
            pre_c = (UI_character_type)((*((words_end_p - ENCODING_LENGTH)+0))|((*((words_end_p - ENCODING_LENGTH)+1))<<8));
        }
    	
        if (pre_c != 0 && pre_c != 0x20 && pre_c != 0x0D && pre_c != 0x0A)
        {
            gui_multi_line_input_box_previous(&MMI_multiline_inputbox);

            is_valid_pre_cluster = mmi_imc_is_valid_alphabetic_word_of_current_input_mode((U8 *)MMI_multiline_inputbox.cursor_p, 
                                       (old_cursor_p - MMI_multiline_inputbox.cursor_p)/ENCODING_LENGTH);

            gui_multi_line_input_box_next(&MMI_multiline_inputbox);
        }
    	
        c = (UI_character_type)((*((words_end_p)+0))|((*((words_end_p)+1))<<8));
    		
        if (c != 0 && c != 0x20 && c != 0x0D && c != 0x0A)
        {
            gui_multi_line_input_box_next(&MMI_multiline_inputbox);

            is_valid_cluster = mmi_imc_is_valid_alphabetic_word_of_current_input_mode((U8 *)old_cursor_p, 
                                       (MMI_multiline_inputbox.cursor_p - old_cursor_p)/ENCODING_LENGTH);

            gui_multi_line_input_box_previous(&MMI_multiline_inputbox);
        }


        if ((c != 0 && c != 0x20 && c != 0x0D && c != 0x0A && is_valid_cluster) 
			&& (pre_c == 0 || pre_c == 0x20 || pre_c == 0x0D || pre_c == 0x0A || !is_valid_pre_cluster))
        {
            if (words_end_p < MMI_multiline_inputbox.text + MMI_multiline_inputbox.text_length)
            {
                word_length++;

                do
                {
                    words_end_p += ENCODING_LENGTH;
                    c = (UI_character_type)((*((words_end_p)+0))|((*((words_end_p)+1))<<8));

                    if (!(c != 0 && c != 0x20 && c != 0x0D && c != 0x0A && mmi_imc_is_valid_alphabetic_word_of_current_input_mode((U8 *)&c, 1)))
                    {
                        break;
                    }

                    word_length++;

                }while (word_length <= mmi_imc_get_max_reselection_word_length());
            }

            if (word_length <= mmi_imc_get_max_reselection_word_length() && word_length > 0)
            {
                MMI_multiline_inputbox.cursor_p = words_end_p;

                #ifdef GUI_INPUT_BOX_CACHE_SUPPORT
                    gui_mlc_all_line_update();
                #endif

                gui_show_multi_line_input_box_ext(&MMI_multiline_inputbox, -1, -1);

                if (MMI_multiline_inputbox.cursor_p != words_end_p) 
                {   
                    /* Cursor may be changed by gui_EMS_input_box_locate_cursor() because of cluster */
                    gui_multi_line_input_box_previous(&MMI_multiline_inputbox);
                }

                words_end_p = MMI_multiline_inputbox.cursor_p;

                MMI_multiline_inputbox.cursor_p = old_cursor_p;

                #ifdef GUI_INPUT_BOX_CACHE_SUPPORT
                    gui_mlc_all_line_update();
                #endif

                gui_show_multi_line_input_box_ext(&MMI_multiline_inputbox, -1, -1);

                if ((c == 0x20 || c == 0 || c == 0x0D || c == 0x0A || !mmi_imc_is_valid_alphabetic_word_of_current_input_mode((U8 *)&c, 1)) && words_end_p > MMI_multiline_inputbox.cursor_p)
                {
                    if (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT)
            	    {
                        MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
                        MMI_multiline_inputbox.cursor_p = words_end_p;
                    
                        gui_multi_line_input_box_stop_input(&MMI_multiline_inputbox);
                    
					    if (old_cursor_p != MMI_multiline_inputbox.cursor_p)
                        {
                            MMI_multiline_inputbox.cursor_fixed_x = -1;
					    }
					    
                        wgui_inputs_ml_redraw();

                        mmi_imc_key_unhighlight_alphabetic_word();

					    return;
            	    }	
                    else if (mmi_imc_is_valid_alphabetic_word_of_current_input_mode(MMI_multiline_inputbox.cursor_p, (words_end_p - MMI_multiline_inputbox.cursor_p) / ENCODING_LENGTH))
                    {
                        MMI_multiline_inputbox.highlight_start_position = MMI_multiline_inputbox.cursor_p;
                        MMI_multiline_inputbox.highlight_end_position = words_end_p;
                        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;

                        MMI_multiline_inputbox.cursor_p = words_end_p;

                        gui_multi_line_input_box_start_input(&MMI_multiline_inputbox);
                    
					    if (old_cursor_p != MMI_multiline_inputbox.cursor_p)
                        {
                            MMI_multiline_inputbox.cursor_fixed_x = -1;
					    }
                    
                        wgui_inputs_ml_redraw();

                        mmi_imc_key_highlight_alphabetic_word();
                    
                        return;
                    }
                }
            }
        }
    }

    if (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT)
	{
        MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
		
        gui_multi_line_input_box_stop_input(&MMI_multiline_inputbox);
		
		words_end_p = MMI_multiline_inputbox.cursor_p;

		if (old_cursor_p != MMI_multiline_inputbox.cursor_p)
		{
			MMI_multiline_inputbox.cursor_fixed_x = -1;
		}

		if (words_end_p < MMI_multiline_inputbox.text + MMI_multiline_inputbox.text_length) 
		{
			words_end_p = MMI_multiline_inputbox.cursor_p;
			
			c = (UI_character_type)((*(words_end_p))|((*(words_end_p+1))<<8));
			
			if (c == 0x20) 
			{
				gui_multi_line_input_box_next(&MMI_multiline_inputbox);
			}
		}
		
		wgui_inputs_ml_redraw();
		
        mmi_imc_key_unhighlight_alphabetic_word();

		return;
	}	
#endif /* #if defined(__MMI_SMART_ALPHABETIC_RESELECTION__)   */

    if (mmi_imc_is_append_one_more_space_input_mode(mmi_imm_get_curr_input_mode())&&
        !mmi_imc_is_ime_state())
    {
        pre_c = 0;
        
        if (MMI_multiline_inputbox.cursor_p > MMI_multiline_inputbox.text)
        {
            pre_c = (UI_character_type)((*((MMI_multiline_inputbox.cursor_p - ENCODING_LENGTH)+0))|((*((MMI_multiline_inputbox.cursor_p - ENCODING_LENGTH)+1))<<8));
        }

        c = (UI_character_type)((*((MMI_multiline_inputbox.cursor_p)+0))|((*((MMI_multiline_inputbox.cursor_p)+1))<<8));

        if (c == 0 && pre_c != 0 && pre_c != L' ')
        {
            wgui_inputs_ml_direct_input(L' ');
            
            return;
        }
    }

    gui_multi_line_input_box_next(&MMI_multiline_inputbox);
    wgui_inputs_ml_redraw();
    multiline_inputbox_navigate_callback();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_delete_all_characters
 * DESCRIPTION
 *  Deletes all characters
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_delete_all_characters(void)
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
#if defined(__MMI_TOUCH_SCREEN__)
    mmi_pen_get_state(&is_enabled, &is_pen_down);
    if (is_pen_down)
#endif
    {
        gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_HOLD);
    }

    gui_multi_line_input_box_delete_all(&MMI_multiline_inputbox);
    if (wgui_multiline_inputbox_decimal_input_mode_flag)
    {
        wgui_multiline_inputbox_decimal_flag = 0;
    }
    wgui_inputs_ml_redraw();
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
    if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INCLUDE_INFO_AREA))
#endif 
        multiline_inputbox_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_is_inline
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item        [?]     
 * RETURNS
 *  
 *****************************************************************************/
S8 wgui_inputs_ml_is_inline(void *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_text_edit *i = (wgui_inline_item_text_edit*) item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((i->flags & 0xff) == INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_vertical_scroll
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_vertical_scroll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nvisiblearea = MMI_multiline_inputbox.height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (nvisiblearea > MMI_multiline_inputbox.text_height)
    {
        return;
    }
    if (nvisiblearea > MMI_multiline_inputbox.edit_height)
    {
        nvisiblearea = MMI_multiline_inputbox.edit_height;
    }
    
    MMI_multiline_inputbox.vertical_scroll_on = 1;

    if (!wgui_inputs_ml_is_last_line())
    {
        if (nvisiblearea - MMI_multiline_inputbox.text_offset_y >= MMI_multiline_inputbox.text_height)
        {
            MMI_multiline_inputbox.text_offset_y = 0;
        }
        else
        {
            gui_set_font(MMI_multiline_inputbox.text_font);
            g_mmi_wgui_halfline_marquee_scroll_enable = 1;  /* Enable it here */
            MMI_multiline_inputbox.text_offset_y -= ((gui_get_character_height()) >> 1);
        }
    }
    else
    {
        /* reach the last line, back to the beginning */
        MMI_multiline_inputbox.text_offset_y = 0;
    }

    /* Inline read only multiline (ID = 2) will use list clip, so it should set before show */
    if (MMI_multi_line_inputbox_present == 2)
    {
        gui_push_clip();
        gui_set_clip(MMI_fixed_list_menu.x, MMI_fixed_list_menu.y, MMI_fixed_list_menu.x + MMI_fixed_list_menu.width - 1, MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1);
        wgui_inputs_ml_redraw();
        gui_pop_clip();
    }
    else
    {
        wgui_inputs_ml_redraw();
    }

    MMI_multiline_inputbox.vertical_scroll_on = 0;
    multiline_inputbox_navigate_callback();
    gui_start_timer(UI_MULTI_LINE_SCROLL_TIMEOUT, wgui_inputs_ml_vertical_scroll);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_previous_line
 * DESCRIPTION
 *  Moves the cursor to the previous line
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_previous_line(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wgui_inputs_ml_pre_key_handler)
    {
        if (g_wgui_inputs_ml_pre_key_handler(KEY_UP_ARROW))
        {
            return;
        }
    }

    if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE) ||
        (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INSIDE_INLINE_MENU) ||
        MMI_multiline_inputbox.text_offset_y < 0)
    {
        #ifdef __MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__
        if (gui_multi_line_input_box_is_hilite_in_visible_range(&MMI_multiline_inputbox, MMI_multiline_inputbox.current_hilite_idx - 1) &&
            MMI_multiline_inputbox.hilite_str_number > 2)
        {
            if (MMI_multiline_inputbox.current_hilite_idx == 1 && 
                gui_multi_line_input_box_is_hilite_in_visible_range(&MMI_multiline_inputbox, MMI_multiline_inputbox.current_hilite_idx) &&
                MMI_multiline_inputbox.text_offset_y < 0)
            {
                /* previous hilite is first hilite, but current hilite is still visible, not reach the start line */
                gui_multi_line_input_box_previous_line(&MMI_multiline_inputbox);
            }
            else
            {
                gui_push_clip();
                gui_set_clip(MMI_fixed_list_menu.x, MMI_fixed_list_menu.y, MMI_fixed_list_menu.x + MMI_fixed_list_menu.width - 1, MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1);
                gui_multi_line_input_box_go_to_hilite(
                            &MMI_multiline_inputbox,
                            MMI_multiline_inputbox.current_hilite_idx - 1,
                            MMI_FALSE);
                gui_pop_clip();
            }
        }
        else
        #endif /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/
        {
            gui_multi_line_input_box_previous_line(&MMI_multiline_inputbox);
        }

        if (hilited_item_changed != 1)
        {
            /* Inline read only multiline (ID = 2) will use list clip, so it should set before show */
            if (MMI_multi_line_inputbox_present == 2)
            {
                gui_push_clip();
                gui_set_clip(MMI_fixed_list_menu.x, MMI_fixed_list_menu.y, MMI_fixed_list_menu.x + MMI_fixed_list_menu.width - 1, MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1);
                wgui_inputs_ml_redraw();
                gui_pop_clip();
            }
            else
            {
                wgui_inputs_ml_redraw();
            }

            multiline_inputbox_navigate_callback();
            return;
        }
        else
        {
            if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE))
            {
                handle_inline_full_screen_edit_close();
            }
            else
            {
            #if defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__)
                handle_multi_line_rd_only_close();
            #endif
            }
            inline_fixed_list_goto_previous_item();
            g_mmi_wgui_halfline_marquee_scroll_enable = 0;
        }
        hilited_item_changed = 0;
    }
    return;
}

#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)

/* Function Pointer to call at presing of up arrow in inscreen multiline edit. */


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_inline_previous_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_inline_previous_line(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_multi_line_input_box_previous_line(&MMI_multiline_inputbox);
    if (hilited_item_changed != 1)
    {
        /* W05.34 Fix Multitap in arrow keys */
        if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE))
        {
            wgui_inputs_ml_redraw();
        }
        multiline_inputbox_navigate_callback();
        return;
    }
    else
    {

        if (wgui_inline_edit_is_able_to_switch_highlight(0))
        {
#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
#if defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__)
            if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE))
            {
                handle_inline_multi_line_edit_complete();
            }
#endif
#endif    
            inline_fixed_list_goto_previous_item();
        }
        else
        {
            UI_editor_play_tone_cannot_navigate();
            wgui_inputs_ml_redraw();
        }

        
    }
    hilited_item_changed = 0;
    return;
}

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_inline_handle_up_arrow_repeat
 * DESCRIPTION
 *  handle up arrow key repeat of inline multiline input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inputs_ml_inline_handle_up_arrow_repeat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_fast_del_nav_handler(WGUI_INPUTS_OPER_FAST_NAV_UP, WGUI_INPUTS_EDITOR_INLINE_ML, WGUI_INPUTS_KPD_REPEAT_PERIOD);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_inline_handle_down_arrow_repeat
 * DESCRIPTION
 *  handle down arrow key repeat of inline multiline input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inputs_ml_inline_handle_down_arrow_repeat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_fast_del_nav_handler(WGUI_INPUTS_OPER_FAST_NAV_DOWN, WGUI_INPUTS_EDITOR_INLINE_ML, WGUI_INPUTS_KPD_REPEAT_PERIOD);
}

#endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_next_line
 * DESCRIPTION
 *  Moves the cursor to the next line
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_next_line(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wgui_inputs_ml_pre_key_handler)
    {
        if (g_wgui_inputs_ml_pre_key_handler(KEY_DOWN_ARROW))
        {
            return;
        }
    }

    if (current_wgui_inline_item != NULL)
    {
        /* This case moves the multiline input box up untill it reached at the first item. */
        wgui_inline_item_text_edit *i = (wgui_inline_item_text_edit*) current_wgui_inline_item->item;
//#ifndef __MMI_FTE_SUPPORT__
        /* Read Only Control Now Only Display For Number Of Lines Text Present */
        if (((i->height_of_item + MMI_fixed_list_menu.highlighted_item -
              MMI_fixed_list_menu.first_displayed_item) * MMI_MENUITEM_HEIGHT > MMI_fixed_list_menu.height) &&
            (MMI_fixed_list_menu.first_displayed_item != MMI_fixed_list_menu.n_items - 1))
        {
            /* multiline in inline, multiline half showed */
            if (wgui_inputs_ml_is_inline(&wgui_inline_items[MMI_fixed_list_menu.first_displayed_item]))
            {
                #ifdef __MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__
                
                if ((MMI_multiline_inputbox.current_hilite_idx + 1 < MMI_multiline_inputbox.hilite_str_number - 1 &&
                     MMI_multiline_inputbox.hilite_str_number > 2 &&
                     gui_multi_line_input_box_is_hilite_in_visible_range(&MMI_multiline_inputbox, MMI_multiline_inputbox.current_hilite_idx + 1)) ||
                     (MMI_multiline_inputbox.current_hilite_idx + 1 == MMI_multiline_inputbox.hilite_str_number - 1 &&
                     MMI_multiline_inputbox.text_offset_y == MMI_multiline_inputbox.edit_height - MMI_multiline_inputbox.text_height))
                {
                    /* next hilite is visible(not the last) or last hilite and reach the last line*/                                
                    gui_push_clip();
                    gui_set_clip(MMI_fixed_list_menu.x, MMI_fixed_list_menu.y, MMI_fixed_list_menu.x + MMI_fixed_list_menu.width - 1, MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1);
                    gui_multi_line_input_box_go_to_hilite(
                        &MMI_multiline_inputbox,
                        MMI_multiline_inputbox.current_hilite_idx + 1,
                        MMI_FALSE);
                    gui_pop_clip();

                    if (!hilited_item_changed)
                    {
                        /* Inline read only multiline (ID = 2) will use list clip, so it should set before show */
                        if (MMI_multi_line_inputbox_present == 2)
                        {
                            gui_push_clip();
                            gui_set_clip(MMI_fixed_list_menu.x, MMI_fixed_list_menu.y, MMI_fixed_list_menu.x + MMI_fixed_list_menu.width - 1, MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1);
                            wgui_inputs_ml_redraw();
                            gui_pop_clip();
                        }
                        else
                        {
                            wgui_inputs_ml_redraw();
                        }

                        multiline_inputbox_navigate_callback();
                    }
                }
                else
                #endif /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/                    
                {
                    BOOL gdi_freeze = gdi_lcd_get_freeze();
                    /* save some var */
                    U32 savedIndex = MMI_multiline_inputbox.current_hilite_idx;
                    S32 saved_visible_start = MMI_multiline_inputbox.visible_start;
                    S32 saved_visible_end = MMI_multiline_inputbox.visible_end;
                    S32 saved_text_offset_y = MMI_multiline_inputbox.text_offset_y;
                    UI_buffer_type saved_highlight_start_position = MMI_multiline_inputbox.highlight_start_position;
                    UI_buffer_type saved_highlight_end_position = MMI_multiline_inputbox.highlight_end_position;

                    gdi_lcd_freeze(TRUE);
                    /* scroll inline list */
                    MMI_fixed_list_menu.first_displayed_item++;
                    wgui_inline_item_handled = 0;
                    /* redraw the list(will create and show multiline) */
                    show_fixed_list();

                    /* inline change the current hilite idx */
                    if (MMI_multiline_inputbox.current_hilite_idx != savedIndex)
                    {
                        /* reset the saved var */ 
                        MMI_multiline_inputbox.current_hilite_idx = savedIndex;
                        /* should send message to email that hilite idx has been changed */
                        if(MMI_multiline_inputbox.hilite_cb)
                        {
                            MMI_multiline_inputbox.hilite_cb(MMI_multiline_inputbox.current_hilite_idx);
                        }
                    }

                    /* reset the saved var */                    
                    MMI_multiline_inputbox.visible_start = saved_visible_start;
                    MMI_multiline_inputbox.visible_end = saved_visible_end;
                    MMI_multiline_inputbox.text_offset_y = saved_text_offset_y;
                    MMI_multiline_inputbox.highlight_start_position = saved_highlight_start_position;
                    MMI_multiline_inputbox.highlight_end_position = saved_highlight_end_position;

                    /* redraw the multiline, using the saved var */
                    if (MMI_multi_line_inputbox_present == 2)
                    {
                        gui_push_clip();
                        gui_set_clip(MMI_fixed_list_menu.x, MMI_fixed_list_menu.y, MMI_fixed_list_menu.x + MMI_fixed_list_menu.width - 1, MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1);
                        wgui_inputs_ml_redraw();
                        gui_pop_clip();
                    }
                    else
                    {
                        wgui_inputs_ml_redraw();
                    }

                    gdi_lcd_freeze(gdi_freeze);
                    gdi_layer_blt_previous(0,0,UI_device_width-1, UI_device_height-1);
                }
            }
        }
        else
//#endif
        {
            /* multiline in inline, multiline full showed */
            #ifdef __MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__
            if (gui_multi_line_input_box_is_hilite_in_visible_range(&MMI_multiline_inputbox, MMI_multiline_inputbox.current_hilite_idx + 1) &&
                (MMI_multiline_inputbox.hilite_str_number > 2))
            {
                /* next hilite is visible */
                if (MMI_multiline_inputbox.current_hilite_idx + 1 == MMI_multiline_inputbox.hilite_str_number - 1 && 
                    gui_multi_line_input_box_is_hilite_in_visible_range(&MMI_multiline_inputbox, MMI_multiline_inputbox.current_hilite_idx) &&
                    MMI_multiline_inputbox.text_offset_y != MMI_multiline_inputbox.edit_height - MMI_multiline_inputbox.text_height)
                {
                    /* next hilite is last hilite, but current hilite is still visible, not reach the end line */
                    gui_multi_line_input_box_next_line(&MMI_multiline_inputbox);
                }
                else
                {
                    gui_push_clip();
                    gui_set_clip(MMI_fixed_list_menu.x, MMI_fixed_list_menu.y, MMI_fixed_list_menu.x + MMI_fixed_list_menu.width - 1, MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1);
                    gui_multi_line_input_box_go_to_hilite(
                            &MMI_multiline_inputbox,
                            MMI_multiline_inputbox.current_hilite_idx + 1,
                            MMI_FALSE);
                    gui_pop_clip();
                }
            }
            else
            #endif /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/
            {
                gui_multi_line_input_box_next_line(&MMI_multiline_inputbox);
            }

            if (!hilited_item_changed)
            {
                /* Inline read only multiline (ID = 2) will use list clip, so it should set before show */
                if (MMI_multi_line_inputbox_present == 2)
                {
                    gui_push_clip();
                    gui_set_clip(MMI_fixed_list_menu.x, MMI_fixed_list_menu.y, MMI_fixed_list_menu.x + MMI_fixed_list_menu.width - 1, MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1);
                    wgui_inputs_ml_redraw();
                    gui_pop_clip();
                }
                else
                {
                    wgui_inputs_ml_redraw();
                }

                multiline_inputbox_navigate_callback();
            }
            hilited_item_changed = 0;
        }
    }
    else
    {
        if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE) ||
            (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INSIDE_INLINE_MENU) ||
            MMI_multiline_inputbox.text_offset_y + MMI_multiline_inputbox.text_height >
            MMI_multiline_inputbox.edit_height)
        {
            gui_multi_line_input_box_next_line(&MMI_multiline_inputbox);

            wgui_inputs_ml_redraw();
        }
        multiline_inputbox_navigate_callback();
    }
}

#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
/* Function Pointer to call at presing of down arrow in inscreen multiline edit. */


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_inline_next_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_inline_next_line(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_multi_line_input_box_next_line(&MMI_multiline_inputbox);
    if (hilited_item_changed != 1)
    {
        wgui_inputs_ml_redraw();
        multiline_inputbox_navigate_callback();
        return;
    }
    else
    {
        /* Issue #74 UI Internal */
        
        if (wgui_inline_edit_is_able_to_switch_highlight(1))
        {
#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
#if defined( __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__) || defined( __MMI_INLINE_ITEM_MULTILINE_EDIT__)
            handle_inline_multi_line_edit_complete();
#endif
#endif
            inline_fixed_list_goto_next_item();
        }
        else
        {
            UI_editor_play_tone_cannot_navigate();
            wgui_inputs_ml_redraw();
        }
        
    }
    hilited_item_changed = 0;
    return;
}
#else /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_next_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_next_line(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_multi_line_input_box_next_line(&MMI_multiline_inputbox);

    wgui_inputs_ml_redraw();
    multiline_inputbox_navigate_callback();
}
#endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 


void wgui_inputs_ml_next_line_with_hilite_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_multi_line_input_box_next_line_with_hilite_list(&MMI_multiline_inputbox);
    wgui_inputs_ml_redraw();
}


void wgui_inputs_ml_previous_line_with_hilite_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_multi_line_input_box_previous_line_with_hilite_list(&MMI_multiline_inputbox);
    wgui_inputs_ml_redraw();
}

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_home
 * DESCRIPTION
 *  Moves the cursor to the first line, first character
 *  
 *  Not yet implemented
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_home(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Move Contents To Top In Inscreen Multiline Readonly */
    MMI_multiline_inputbox.text_offset_y = 0;
    gui_push_clip();
    gui_set_clip(MMI_fixed_list_menu.x, MMI_fixed_list_menu.y, MMI_fixed_list_menu.x + MMI_fixed_list_menu.width - 1, MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1);
    wgui_inputs_ml_redraw();
    gui_pop_clip();
    multiline_inputbox_navigate_callback();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_end
 * DESCRIPTION
 *  Moves the cursor to the last line, last character
 *  
 *  Not yet implemented
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_ml_redraw();
    multiline_inputbox_navigate_callback();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_previous_page
 * DESCRIPTION
 *  Moves the cursor to the previous page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_previous_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
    if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE)
    {
        wgui_inputs_ml_paging_previous_page();
    }
    else
    {
#endif /* __UI_PAGING_IN_MULTILINE_EDITOR__ */
        gui_multi_line_input_box_previous_page(&MMI_multiline_inputbox);
        wgui_inputs_ml_redraw();
        multiline_inputbox_navigate_callback();
#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
    }
#endif /* __UI_PAGING_IN_MULTILINE_EDITOR__ */    
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_next_page
 * DESCRIPTION
 *  Moves the cursor to the next page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_next_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
    if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE)
    {
        wgui_inputs_ml_paging_next_page();
    }
    else
    {
#endif /* __UI_PAGING_IN_MULTILINE_EDITOR__ */
        gui_multi_line_input_box_next_page(&MMI_multiline_inputbox);
        wgui_inputs_ml_redraw();
        multiline_inputbox_navigate_callback();
#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
    }
#endif /* __UI_PAGING_IN_MULTILINE_EDITOR__ */
}

#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_previous_page
 * DESCRIPTION
 *  show the previous page of text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_previous_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 percentage_scale;
    static MMI_BOOL first_page_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INSIDE_INLINE_MENU) ||
        MMI_multiline_inputbox.text_offset_y < 0)
    {
        first_page_flag = MMI_FALSE;
        if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE)
        {
            if (stop_auto_scroll_callback)
                stop_auto_scroll_callback();
            wgui_inputs_ml_paging_stop_text_scroll();
        }

        gui_paging_multi_line_input_box_previous_page(&MMI_multiline_inputbox);

        wgui_inputs_ml_show_no_draw();

        wgui_inputs_ml_paging_calculate_percentage(&percentage_scale);

        if (wgui_inputs_ml_paging_check_to_end())
        {
            percentage_scale = COMPLETE_PERCENTAGE_SCALE;
        }

        if (MMI_multiline_inputbox.text_offset_y == 0)
        {
            percentage_scale = 0;
        }

        if (percentage_scale > COMPLETE_PERCENTAGE_SCALE)
        {
            percentage_scale = COMPLETE_PERCENTAGE_SCALE;
        }

        gui_page_info.last_showed_percentage = percentage_scale;

        wgui_inputs_ml_paging_set_percentage_scale(percentage_scale);

        gui_page_info.last_text_offset_y = MMI_multiline_inputbox.text_offset_y;        /* ritesh added for text relocation */

        multiline_inputbox_navigate_callback();
        wgui_inputs_ml_redraw();

        /* call it again for the application to caculate the percentage */
        wgui_inputs_ml_paging_set_percentage_scale(percentage_scale);
        return;
    }
    else
    {
        if (!first_page_flag)
        {
            wgui_inputs_ml_redraw();
            first_page_flag = MMI_TRUE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_next_page
 * DESCRIPTION
 *  show the next page of text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_next_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 percentage_scale;
    static MMI_BOOL last_page_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INSIDE_INLINE_MENU) ||
        !wgui_inputs_ml_paging_check_to_end())
    {
        last_page_flag = MMI_FALSE;
        gui_paging_multi_line_input_box_next_page(&MMI_multiline_inputbox);

        if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE))
        {
            if ((MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE)
                && (MMI_multiline_inputbox.line_after_cursor_line_p == MMI_multiline_inputbox.cursor_line_p))
            {
                if (stop_auto_scroll_callback)
                    stop_auto_scroll_callback();
                wgui_inputs_ml_paging_stop_text_scroll();
            }
        }
        wgui_inputs_ml_show_no_draw();

        wgui_inputs_ml_paging_calculate_percentage(&percentage_scale);

        if (wgui_inputs_ml_paging_check_to_end())
        {
            percentage_scale = COMPLETE_PERCENTAGE_SCALE;
        }
        if (percentage_scale > COMPLETE_PERCENTAGE_SCALE)
        {
            percentage_scale = COMPLETE_PERCENTAGE_SCALE;
        }

        gui_page_info.last_showed_percentage = percentage_scale;

        wgui_inputs_ml_paging_set_percentage_scale(percentage_scale);
        wgui_inputs_ml_redraw();
        /* call it again for the application to caculate the percentage */
        wgui_inputs_ml_paging_set_percentage_scale(percentage_scale);
    }
    else
    {
        wgui_inputs_ml_paging_calculate_percentage(&percentage_scale);
        if (percentage_scale < COMPLETE_PERCENTAGE_SCALE &&
            MMI_multiline_inputbox.text_height > MMI_multiline_inputbox.edit_height)
        {
            percentage_scale = COMPLETE_PERCENTAGE_SCALE;
        }

        gui_page_info.last_showed_percentage = percentage_scale;

        if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE)
        {
            if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE))
            {
                if ((MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE)
                    && (MMI_multiline_inputbox.line_after_cursor_line_p == MMI_multiline_inputbox.cursor_line_p))
                {
                    if (stop_auto_scroll_callback)
                        stop_auto_scroll_callback();
                    wgui_inputs_ml_paging_stop_text_scroll();
                }
            }
            else
            {
                if (stop_auto_scroll_callback)
                    stop_auto_scroll_callback();
                wgui_inputs_ml_paging_stop_text_scroll();
            }
        }
        
        wgui_inputs_ml_paging_set_percentage_scale(percentage_scale);
        gui_page_info.last_text_offset_y = MMI_multiline_inputbox.text_offset_y;  /* for text relocation */
        if (!last_page_flag)
        {
            wgui_inputs_ml_redraw();
            last_page_flag = MMI_TRUE;
        }
        /* call it again for the application to caculate the percentage */
        wgui_inputs_ml_paging_set_percentage_scale(percentage_scale);
    }
    multiline_inputbox_navigate_callback();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_next_line_in_paging_scroll
 * DESCRIPTION
 *  show the next line of text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_next_line_in_paging_scroll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE)
    {
        MMI_multiline_inputbox.next_line_scroll_flag = 1;
    }
    wgui_inputs_ml_paging_next_line_in_paging();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_next_line_in_paging
 * DESCRIPTION
 *  show the next line of text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_next_line_in_paging(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 percentage_scale;
    static MMI_BOOL last_page_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE) ||
        (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INSIDE_INLINE_MENU) ||
        !wgui_inputs_ml_paging_check_to_end())
    {
        last_page_flag = MMI_FALSE;
        gui_paging_multi_line_input_box_next_line_in_paging(&MMI_multiline_inputbox);

        if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE))
        {
            if ((MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE)
                && (MMI_multiline_inputbox.line_after_cursor_line_p == MMI_multiline_inputbox.cursor_line_p))
            {
                if (stop_auto_scroll_callback)
                    stop_auto_scroll_callback();
                wgui_inputs_ml_paging_stop_text_scroll();
            }
        }
        wgui_inputs_ml_show_no_draw();
        wgui_inputs_ml_paging_calculate_percentage(&percentage_scale);
        if (wgui_inputs_ml_paging_check_to_end())
        {
            percentage_scale = COMPLETE_PERCENTAGE_SCALE;
        }

        if (MMI_multiline_inputbox.text_offset_y == 0)
        {
            percentage_scale = 0;
        }

        if (percentage_scale > COMPLETE_PERCENTAGE_SCALE)
        {
            percentage_scale = COMPLETE_PERCENTAGE_SCALE;
        }
        
        if (percentage_scale < gui_page_info.last_showed_percentage)
        {
            percentage_scale = gui_page_info.last_showed_percentage;
        }
        
        gui_page_info.last_showed_percentage = percentage_scale;

        wgui_inputs_ml_paging_set_percentage_scale(percentage_scale);
        wgui_inputs_ml_redraw();
    }
    else
    {
        wgui_inputs_ml_paging_calculate_percentage(&percentage_scale);
        if (percentage_scale < COMPLETE_PERCENTAGE_SCALE && percentage_scale != 0)
        {
            percentage_scale = COMPLETE_PERCENTAGE_SCALE;
        }

        if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE)
        {
            if (stop_auto_scroll_callback)
                stop_auto_scroll_callback();
            wgui_inputs_ml_paging_stop_text_scroll();
        }

        gui_page_info.last_showed_percentage = percentage_scale;

        wgui_inputs_ml_paging_set_percentage_scale(percentage_scale);
        if (!last_page_flag)
        {
            wgui_inputs_ml_redraw();
            last_page_flag = MMI_TRUE;
        }
    }

    gui_page_info.last_text_offset_y = MMI_multiline_inputbox.text_offset_y;    /* for text relocation */
    multiline_inputbox_navigate_callback();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_set_stop_scroll_callback
 * DESCRIPTION
 *  set the autoscroll stop callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_set_stop_scroll_callback(void* callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stop_auto_scroll_callback = (stop_scroll_hdlr)callback;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_previous_line_in_paging
 * DESCRIPTION
 *  show the previous line of text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_previous_line_in_paging(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 percentage_scale;
    static MMI_BOOL first_page_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE) ||
        (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INSIDE_INLINE_MENU) ||
        MMI_multiline_inputbox.text_offset_y < 0)
    {
        first_page_flag = MMI_FALSE;
        if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE)
        {
            if (stop_auto_scroll_callback)
                stop_auto_scroll_callback();
            wgui_inputs_ml_paging_stop_text_scroll();
        }
        gui_paging_multi_line_input_box_previous_line_in_paging(&MMI_multiline_inputbox);
        if (hilited_item_changed != 1)
        {
            wgui_inputs_ml_show_no_draw();
            wgui_inputs_ml_paging_calculate_percentage(&percentage_scale);
            
            if (wgui_inputs_ml_paging_check_to_end())
            {
                percentage_scale = COMPLETE_PERCENTAGE_SCALE;
            }
            
            if (MMI_multiline_inputbox.text_offset_y == 0)
            {
                percentage_scale = 0;
            }
            if (percentage_scale > COMPLETE_PERCENTAGE_SCALE)
            {
                percentage_scale = COMPLETE_PERCENTAGE_SCALE;
            }

            if (percentage_scale > gui_page_info.last_showed_percentage)
            {
                percentage_scale = gui_page_info.last_showed_percentage;
            }

            gui_page_info.last_showed_percentage = percentage_scale;

            wgui_inputs_ml_paging_set_percentage_scale(percentage_scale);
            wgui_inputs_ml_redraw();
            gui_page_info.last_text_offset_y = MMI_multiline_inputbox.text_offset_y;    /* for text relocation */
            multiline_inputbox_navigate_callback();
            return;
        }
        else
        {
            if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE))
            {
                handle_inline_full_screen_edit_close();
            }
            inline_fixed_list_goto_previous_item();
            g_mmi_wgui_halfline_marquee_scroll_enable = 0;
        }
        hilited_item_changed = 0;
    }
    else
    {
        if (!first_page_flag)
        {
            wgui_inputs_ml_redraw();
            first_page_flag = MMI_TRUE;
        }
    }
    gui_page_info.last_text_offset_y = MMI_multiline_inputbox.text_offset_y;    /* for text relocation */
    return;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_calculate_percentage
 * DESCRIPTION
 *  show the previous line of text
 * PARAMETERS
 *  percentage_scale        [IN]        
 *  pointer(?)              [IN]        To percentage_value
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_calculate_percentage(PU8 percentage_scale)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 percentage_offset;
    float actual_percentage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (MMI_multiline_inputbox.header_height != 0 || MMI_multiline_inputbox.footer_height != 0)
	{
		if (wgui_inputs_ml_paging_check_to_end())
		{
			actual_percentage = 1;
		}
		else
		{
			/*check whether stay at header*/
                        if (MMI_multiline_inputbox.text_offset_y >= 0)
                        {
                                actual_percentage = 0;
                        }
			else if (-MMI_multiline_inputbox.text_offset_y < MMI_multiline_inputbox.header_height)
			{
				actual_percentage = (-MMI_multiline_inputbox.text_offset_y) / (float)(MMI_multiline_inputbox.size_of_total_data
					+ MMI_multiline_inputbox.header_height
					+ MMI_multiline_inputbox.footer_height);
			}
			/*check whether stay at footer*/
			else if(-MMI_multiline_inputbox.text_offset_y > MMI_multiline_inputbox.text_height - MMI_multiline_inputbox.footer_height - Get_CharHeightOfAllLang(LARGE_FONT))
			{
				actual_percentage = (-MMI_multiline_inputbox.text_offset_y - (MMI_multiline_inputbox.text_height - MMI_multiline_inputbox.header_height - MMI_multiline_inputbox.footer_height)
					+ MMI_multiline_inputbox.size_of_total_data) 
					/ (float)(MMI_multiline_inputbox.size_of_total_data + MMI_multiline_inputbox.header_height + MMI_multiline_inputbox.footer_height);
			}
			else
			{
				percentage_offset =
					MMI_multiline_inputbox.text_offset - MMI_multiline_inputbox.previous_shared_bytes +
					(MMI_multiline_inputbox.start_id) * GUI_PAGE_SIZE;
				actual_percentage = (percentage_offset + MMI_multiline_inputbox.header_height) 
                    / (float)(MMI_multiline_inputbox.size_of_total_data + MMI_multiline_inputbox.header_height + MMI_multiline_inputbox.footer_height);
			}
		}
	}
	else
	{
            percentage_offset =
                MMI_multiline_inputbox.text_offset - MMI_multiline_inputbox.previous_shared_bytes +
                (MMI_multiline_inputbox.start_id) * GUI_PAGE_SIZE;
            actual_percentage = (percentage_offset) / (float)MMI_multiline_inputbox.size_of_total_data;
	}

    actual_percentage = actual_percentage * 100;
    *percentage_scale = (U8) actual_percentage;
    if ((actual_percentage - (float)*percentage_scale) >= 0.8)
    {
        (*percentage_scale)++;
    }
    if ((*percentage_scale) > COMPLETE_PERCENTAGE_SCALE)
    {
        (*percentage_scale) = COMPLETE_PERCENTAGE_SCALE;
    }

    if (!(-MMI_multiline_inputbox.text_offset_y + MMI_multiline_inputbox.edit_height >=
        MMI_multiline_inputbox.text_height && MMI_multiline_inputbox.end_id == MMI_multiline_inputbox.last_page_id))
    {
        if (*percentage_scale == COMPLETE_PERCENTAGE_SCALE)
            *percentage_scale = 99;
    }

    if (MMI_multiline_inputbox.text_offset_y < 0 && *percentage_scale == 0)
    {
        *percentage_scale = 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_start_text_scroll
 * DESCRIPTION
 *  Start scrolling of text either page-by-page or line-by-line
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_start_text_scroll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_VK_POPUP_HINT__) && !defined(__MMI_FTE_SUPPORT__)
    if (mmi_imc_is_connected())
	{
		gui_lock_double_buffer();
        wgui_virtual_keyboard_recover_covered_area();
	}
#endif /* __MMI_TOUCH_SCREEN__ || __MMI_VK_POPUP_HINT__ */

    if (gui_page_info.scroll_type == WGUI_PAGING_SCROLL_LINE_BY_LINE &&
        gui_page_info.scroll_flag == WGUI_PAGING_AUTO_SCROLL_ON)
    {
        wgui_inputs_ml_paging_next_line_in_paging();

        if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE)
        {
            gui_start_timer(
                gui_page_info.scroll_speed * UI_MULTI_LINE_SCROLL_TIMEOUT / 2,
            wgui_inputs_ml_paging_start_text_scroll);
        }
    }
    else
    {
        wgui_inputs_ml_paging_next_page();
        if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE)
        {
            gui_start_timer(
                (UI_MULTI_LINE_INIT_SCROLL * WGUI_MAX_SCROLL_TIME) / gui_page_info.scroll_speed,
            wgui_inputs_ml_paging_start_text_scroll);
        }
    }

#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_VK_POPUP_HINT__) && !defined(__MMI_FTE_SUPPORT__)
	if (mmi_imc_is_connected())
	{
		gui_unlock_double_buffer();
        #ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__
        wgui_show_virtual_keyboard();
        #else
            wgui_virtual_keyboard_show();
        #endif
	}
#endif /* __MMI_TOUCH_SCREEN__ || __MMI_VK_POPUP_HINT__ */
}

#ifdef __MMI_TOUCH_SCREEN__

#ifdef __MMI_EDITOR_SSP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  wgui_paging_get_ssp_update_client
 * DESCRIPTION
 *  
 * PARAMETERS
 *  offset              [IN]    the new offset position
 * RETURNS
 *  MMI_TRUE if this pen event is handled; otherwise, MMI_FALSE.
 *****************************************************************************/
static void wgui_inputs_ml_paging_ssp_update_client(void *user_data, S32 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    multi_line_input_box *b = (multi_line_input_box *)user_data;
    S32 old_offset = b->text_offset_y;
    U8 percentage_scale;
    U32 start_id = b->start_id;
    S32 reload_data = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->size_of_total_data <= GUI_PAGE_SIZE * 4)
    {
        if (b->text_offset_y == -offset)
            return;
        
        b->text_offset_y = -offset;
        
        if (old_offset > b->text_offset_y)
        {
            old_offset = b->text_offset_y;
            if ((b->text_offset_y) <= (-(b->text_height - b->edit_height)))
            {
                /* make b->text_offset_y > final pos */
                b->text_offset_y = -(b->text_height - b->edit_height) + 1; 
            }
            gui_paging_multi_line_input_box_next_line_in_paging(b); 
        }
        else
        {
            old_offset = b->text_offset_y;
            if (b->text_offset_y >= 0)
            {
                /* make b->text_offset_y > the first page range */
                b->text_offset_y = -(b->page_details[PAGE_ZERO].page_height - b->edit_height_displayed_lines) + 1; 
            }
            gui_paging_multi_line_input_box_previous_line_in_paging(b);
        }
        
        b->text_offset_y = old_offset;
    }
    else
    {
        b->text_offset_y = -offset;

        if (b->text_offset_y >= 0
            || -b->text_offset_y < b->header_height)
        {
            if (b->start_id > 0)
                reload_data = 0;
        }
        else if(-b->text_offset_y > b->size_of_total_data + b->header_height)
        {
            b->text_offset_y = -(offset - (b->size_of_total_data + b->header_height) 
                + (b->text_height - b->footer_height));
            if (b->end_id != b->last_page_id)
                reload_data = b->end_id - 3;
        }
        else
        {
            S32 text_offset, cur_start, cur_end, cur_id;
            
            text_offset = offset - b->header_height;
            cur_start = b->start_id * GUI_PAGE_SIZE ;
            cur_end = b->end_id * GUI_PAGE_SIZE;
            if (text_offset >= cur_start + GUI_PAGE_SIZE
                && text_offset <= cur_end)
            {
                b->page_offset = text_offset - cur_start;
            }
            else
            {
                cur_id = text_offset/GUI_PAGE_SIZE;
                reload_data = cur_id - 1;
                if (reload_data < 0)
                    reload_data = 0;
                else if (reload_data > (S32)(b->last_page_id - 3))
                    reload_data = (S32)b->last_page_id - 3;
                
                if (reload_data == (S32)start_id)
                {
                    reload_data = -1;
                    b->page_offset = text_offset - cur_start;
                }
                else
                {
                    b->page_offset = text_offset - reload_data*GUI_PAGE_SIZE;
                }
            }

            b->text_offset_y = -b->header_height;
        }

        if (reload_data >= 0)
        {
            b->start_id = reload_data;
            b->end_id = reload_data + 3;
            
            b->get_page_cb(
                b->start_id,
                b->end_id,
                b->text);

            b->text_length = (mmi_ucs2strlen((const S8*)b->text)+1)*ENCODING_LENGTH;

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
            gui_mlc_all_line_update();
#endif
        }

        //b->ext_flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        //gui_show_multi_line_input_box(b);
        //b->ext_flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        gui_show_multi_line_input_box_no_draw(b);
    }
        
    wgui_inputs_ml_paging_calculate_percentage(&percentage_scale);
    
    if (wgui_inputs_ml_paging_check_to_end())
    {
        percentage_scale = COMPLETE_PERCENTAGE_SCALE;
    }
    
    if (b->text_offset_y == 0)
    {
        percentage_scale = 0;
    }
    
    if (percentage_scale > COMPLETE_PERCENTAGE_SCALE)
    {
        percentage_scale = COMPLETE_PERCENTAGE_SCALE;
    }
    
    wgui_inputs_ml_paging_set_percentage_scale(percentage_scale);
    
    b->ext_flags |= GUI_MULTI_LINE_INPUT_BOX_FIXED_Y_OFFSET | GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
    
    if (start_id != b->start_id
        && multiline_paging_async_pen_callback != NULL)
        multiline_paging_async_pen_callback();

    gui_show_multi_line_input_box(b);
    b->ext_flags &= ~(GUI_MULTI_LINE_INPUT_BOX_FIXED_Y_OFFSET | GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR);
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_BLT_double_buffer(
        b->x,
        b->y,
        b->x + b->width,
        b->y + b->height);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
    
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_ssp_get_client_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  offset              [IN]    the new offset position
 * RETURNS
 *  MMI_TRUE if this pen event is handled; otherwise, MMI_FALSE.
 *****************************************************************************/
static void wgui_inputs_ml_paging_ssp_get_client_info(void *user_data, S32 *total_offset, S32 *cur_offset, S32 *move_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    multi_line_input_box *b = (multi_line_input_box *)user_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (total_offset)
    {
        if (b->size_of_total_data <= GUI_PAGE_SIZE * 4)
        {
            *total_offset = b->text_height - b->edit_height;
        }
        else
        {
            *total_offset = b->size_of_total_data + b->header_height + b->footer_height;
        }

        if (*total_offset < 0)
            *total_offset = 0;
    }

    if (cur_offset)
    {
        if (b->size_of_total_data <= GUI_PAGE_SIZE * 4)
        {
            *cur_offset = -b->text_offset_y;
        }
        else
        {
            if (b->text_offset_y >= 0
                || -b->text_offset_y < b->header_height)
            {
                *cur_offset = -b->text_offset_y;
            }
            else if(-b->text_offset_y > b->text_height - b->footer_height - Get_CharHeightOfAllLang(LARGE_FONT))
            {
                *cur_offset = (-b->text_offset_y - (b->text_height - b->header_height - b->footer_height)+ b->size_of_total_data);
            }
            else
            {
                S32 text_offset;

                text_offset = b->text_offset - b->previous_shared_bytes +(b->start_id) * GUI_PAGE_SIZE;
                *cur_offset = text_offset + b->header_height;
            }
        }
        
    }

    if (move_type)
    {
        *move_type = GUI_INPUT_BOX_SSP_BY_Y;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_linebase_ssp_notify_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status              [IN]    ssp status
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_ssp_notify_status(void *user_data, S32 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (status == GUI_INPUT_BOX_SSP_STATE_UNFOCUS)
    {
        if (multiline_paging_async_pen_callback != NULL)
        {
            multiline_paging_async_pen_callback();
            wgui_inputs_ml_redraw();
        }
    }
}
#endif /* __MMI_EDITOR_SSP_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_set_scroll_data_callback
 * DESCRIPTION
 *  sets get_data_during_scrolling callback
 * PARAMETERS
 *  gui_scroll_info     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_set_scroll_data_callback(get_data_during_scrolling_cb data_callback)
{
	gui_page_info.get_data_during_scrolling = data_callback;

#ifdef __MMI_EDITOR_SSP_SUPPORT__
    gui_input_box_ssp_set_client_callback_ext(
        wgui_inputs_ml_paging_ssp_update_client, 
        wgui_inputs_ml_paging_ssp_get_client_info,
        wgui_inputs_ml_paging_ssp_notify_status,
        &MMI_multiline_inputbox);
#endif /* __MMI_EDITOR_SSP_SUPPORT__ */
}

#endif /* __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_set_scroll_info
 * DESCRIPTION
 *  sets the speed of scrolling
 * PARAMETERS
 *  gui_scroll_info     [IN]        
 *  instance(?)         [IN]        Of gui_page_info_app structure
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_set_scroll_info(gui_page_info_app **gui_scroll_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_page_info = **gui_scroll_info;
    MMI_multiline_inputbox.scroll_type = (*gui_scroll_info)->scroll_type;
    MMI_multiline_inputbox.scroll_speed = (*gui_scroll_info)->scroll_speed;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_stop_text_scroll
 * DESCRIPTION
 *  stop the scrolling of text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_stop_text_scroll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_multiline_inputbox.ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE;
    gui_cancel_timer(wgui_inputs_ml_paging_start_text_scroll);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_paging_start_text_scroll
 * DESCRIPTION
 *  stop the scrolling of text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_paging_start_text_scroll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE;
    if (gui_page_info.scroll_type == WGUI_PAGING_SCROLL_LINE_BY_LINE)
    {
        gui_start_timer(200, wgui_inputs_ml_paging_start_text_scroll);
    }
    else
    {
        gui_start_timer(
            (UI_MULTI_LINE_INIT_SCROLL * WGUI_MAX_SCROLL_TIME) / gui_page_info.scroll_speed,
            wgui_inputs_ml_paging_start_text_scroll);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_set_font
 * DESCRIPTION
 *  Set the font type of text going to be dispalyed
 * PARAMETERS
 *  gui_paging_font_type        [IN]        
 *  gui_paging_font_style       [IN]        
 *  font(?)                     [IN]        Type
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_set_font(U8 gui_paging_font_type, U8 gui_paging_font_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (gui_paging_font_type)
    {
        case FONT_SIZE_SMALL:
            MMI_multiline_inputbox.text_font = &MMI_small_font;
            break;

        case FONT_SIZE_MEDIUM:
            MMI_multiline_inputbox.text_font = &MMI_medium_font;
            break;

        case FONT_SIZE_LARGE:
            MMI_multiline_inputbox.text_font = &MMI_large_font;
            break;
    }
    MMI_multiline_inputbox.font_style = gui_paging_font_style;

}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_set_get_page_callback
 * DESCRIPTION
 * get_page_callback setter function
 * PARAMETERS
 *  get_page_callback        [IN]        callback
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_set_get_page_callback(get_page_callback get_page)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT (get_page);
    MMI_multiline_inputbox.get_page_cb = get_page;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_set_scrollbar_range
 * DESCRIPTION
 *  Sets the scrollbar range according to the book size
 * PARAMETERS
 *  document_size       [IN]        
 *  size(?)             [IN]        Of the text going to be opened
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_set_scrollbar_range(U32 document_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 scrollbar_range = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_multiline_inputbox.last_page_id = (document_size / GUI_PAGE_SIZE)
        + ((document_size % GUI_PAGE_SIZE)>0 ? 1 : 0);

    if (MMI_multiline_inputbox.last_page_id > 0)
    {
        MMI_multiline_inputbox.last_page_id--;
    }

    if (MMI_multiline_inputbox.end_id > MMI_multiline_inputbox.last_page_id)
        MMI_multiline_inputbox.end_id = MMI_multiline_inputbox.last_page_id;

    MMI_multiline_inputbox.last_page_size = document_size % GUI_PAGE_SIZE;

    MMI_multiline_inputbox.size_of_total_data = document_size;

    if (MMI_multiline_inputbox.text_height > MMI_multiline_inputbox.edit_height)
    {
        gui_set_vertical_scrollbar_range(&MMI_multiline_inputbox.vbar, MMI_multiline_inputbox.text_height);
        wgui_inputs_ml_show_no_draw();
    }

    if (document_size <= GUI_PAGE_SIZE * 4)
    {
        scrollbar_range = MMI_multiline_inputbox.text_height;
    }
    else
    {
        scrollbar_range = (MMI_multiline_inputbox.last_page_id / GUI_NO_OF_PAGES) * MMI_multiline_inputbox.text_height;
    }
    gui_set_vertical_scrollbar_range(&MMI_multiline_inputbox.vbar, scrollbar_range);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_set_percentage
 * DESCRIPTION
 *  sets the percentage parameter
 * PARAMETERS
 *  start_id        [IN]        And text_offset
 *  text_offset     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_set_percentage(U32 start_id, S16 text_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 percentage_scale;
    U32 percentage_offset;
    float actual_percentage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    percentage_offset = start_id * GUI_PAGE_SIZE + text_offset;

    if (MMI_multiline_inputbox.header_height != 0 || MMI_multiline_inputbox.footer_height != 0)
    {
        MMI_multiline_inputbox.text_offset = text_offset;
        wgui_inputs_ml_paging_calculate_percentage(&percentage_scale);
        wgui_inputs_ml_paging_set_percentage_scale(percentage_scale);
    }
    else if (MMI_multiline_inputbox.size_of_total_data != 0)
    {
        actual_percentage = (percentage_offset) / (float)MMI_multiline_inputbox.size_of_total_data;
        actual_percentage = actual_percentage * 100;
        percentage_scale = (U8) actual_percentage;
        if ((actual_percentage - (float)percentage_scale) >= 0.8)
        {
            if(percentage_scale + 1 < COMPLETE_PERCENTAGE_SCALE)
                percentage_scale++;
        }

        if (percentage_scale >= COMPLETE_PERCENTAGE_SCALE)
        {
            percentage_scale = COMPLETE_PERCENTAGE_SCALE;
        }

        if (-MMI_multiline_inputbox.text_offset_y + MMI_multiline_inputbox.edit_height >=
            MMI_multiline_inputbox.text_height && MMI_multiline_inputbox.end_id == MMI_multiline_inputbox.last_page_id)
        {
            if (percentage_scale != 0)
                percentage_scale = COMPLETE_PERCENTAGE_SCALE;
        }

        if (gui_page_info.last_showed_percentage != percentage_scale 
            && gui_page_info.last_showed_percentage != 0
            && gui_page_info.last_showed_percentage != COMPLETE_PERCENTAGE_SCALE)
        {
            percentage_scale = gui_page_info.last_showed_percentage;
        }

        if (MMI_multiline_inputbox.text_offset_y < 0 && percentage_scale == 0)
        {
            percentage_scale = 1;
        }

        wgui_inputs_ml_paging_set_percentage_scale(percentage_scale);
    }

}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_translate_to_text_percentage
 * DESCRIPTION
 *  sets the percentage parameter
 * PARAMETERS
 *  percentage_scale        [IN]        the scrollbar percentage       
 * RETURNS
 *  void
 *****************************************************************************/
U8 wgui_inputs_ml_paging_translate_to_text_percentage(U8 percentage_scale)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float actual_percentage;
    double percent, header_percent, footer_percent;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_multiline_inputbox.header_height != 0 
        ||MMI_multiline_inputbox.footer_height != 0)
    {
        percent = (double)(percentage_scale)/100;
        header_percent = (double)(MMI_multiline_inputbox.header_height)
            /(double)(MMI_multiline_inputbox.size_of_total_data + MMI_multiline_inputbox.header_height + MMI_multiline_inputbox.footer_height);
        footer_percent = (double)(MMI_multiline_inputbox.footer_height)
            /(double)(MMI_multiline_inputbox.size_of_total_data + MMI_multiline_inputbox.header_height + MMI_multiline_inputbox.footer_height);

        /*stay at the header*/
        if (percent <= header_percent)
            return 1;
        /*stay at the footer*/
        else if (percent >= (1 - footer_percent))
            return COMPLETE_PERCENTAGE_SCALE;
        /*stay at the text content*/
        else
        {
            actual_percentage = (percent - header_percent)/(1 - header_percent - footer_percent);
            actual_percentage = actual_percentage * 100;
            percentage_scale = (U8) actual_percentage;
            if ((actual_percentage - (float)percentage_scale) >= 0.8)
            {
                percentage_scale++;
            }
            
            if (percentage_scale >= COMPLETE_PERCENTAGE_SCALE)
            {
                percentage_scale = COMPLETE_PERCENTAGE_SCALE;
            }

            if (wgui_inputs_ml_paging_check_to_end())
            {
                if (percentage_scale != 0)
                    percentage_scale = COMPLETE_PERCENTAGE_SCALE;
            }
        }
        
    }
    
    return percentage_scale;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_check_to_end
 * DESCRIPTION
 *  check whether the view is to the end
 * PARAMETERS
 *  void          
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_inputs_ml_paging_check_to_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (-MMI_multiline_inputbox.text_offset_y + MMI_multiline_inputbox.edit_height >= MMI_multiline_inputbox.text_height
		&& MMI_multiline_inputbox.end_id == MMI_multiline_inputbox.last_page_id)
	{
		return MMI_TRUE;
	}
	else
		return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_check_to_start
 * DESCRIPTION
 *  check whether the view is to the start
 * PARAMETERS
 *  void          
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_inputs_ml_paging_check_to_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_multiline_inputbox.text_offset_y == 0) ? MMI_TRUE : MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_check_cursor_to_end
 * DESCRIPTION
 *  check whether the cursor line is to the end
 * PARAMETERS
 *  void          
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_inputs_ml_paging_check_cursor_to_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_multiline_inputbox.line_after_cursor_line_p == MMI_multiline_inputbox.cursor_line_p)
        return MMI_TRUE;
    else
        return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_clear_last_percentage
 * DESCRIPTION
 *  sets the percentage parameter
 * PARAMETERS
 *  void   
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_clear_last_percentage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_page_info.last_showed_percentage = 0;
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_set_percentage_scale_TS
 * DESCRIPTION
 *  sets the percentage parameter
 * PARAMETERS
 *  percentage_scale        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_set_percentage_scale_TS(U8 percentage_scale)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type s[10];
    S32 l, character_height, shortcut_width;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (percentage_scale >= COMPLETE_PERCENTAGE_SCALE)
    {
        percentage_scale = COMPLETE_PERCENTAGE_SCALE;
    }
    if (percentage_scale == 0)
    {
        wgui_title_set_menu_shortcut_number(percentage_scale + 1);
    }
    else
    {
        wgui_title_set_menu_shortcut_number(percentage_scale);
    }
    shortcut_width = set_menu_item_count(100) + 7;
    resize_menu_shortcut_handler(shortcut_width, MMI_title_height);
    gui_itoa(100, (UI_string_type) s, 10);
    gui_measure_string((UI_string_type) s, &l, &character_height);

    if (percentage_callback != NULL)
    {
        if (!gui_multi_line_input_box_is_in_shown(&MMI_multiline_inputbox))
            gui_show_multi_line_input_box(&MMI_multiline_inputbox);
        (*percentage_callback)(wgui_title_get_menu_shortcut_number());
    }
    else
    {
        if (wgui_paging_show_percentage == 1)
        {
            gui_redraw_menu_shortcut();
        }
    }
    
    gui_page_info.last_showed_percentage = percentage_scale;

}
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_set_page
 * DESCRIPTION
 *  Moves the cursor to the previous page
 * PARAMETERS
 *  start_id        [IN]        
 *  end_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_set_page(U32 start_id, U32 end_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_multiline_inputbox.start_id = start_id;
    MMI_multiline_inputbox.end_id = end_id;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_set_show_percentage_flag
 * DESCRIPTION
 *  sets the percentage flag
 * PARAMETERS
 *  void
 *  start_id(?)     [IN]        And text_offset
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_set_show_percentage_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_paging_show_percentage = 1;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_reset_show_percentage_flag
 * DESCRIPTION
 *  sets the percentage flag
 * PARAMETERS
 *  void
 *  start_id(?)     [IN]        And text_offset
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_reset_show_percentage_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_paging_show_percentage = 0;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_set_dm_data
 * DESCRIPTION
 *  sets the percentage flag
 * PARAMETERS
 *  gui_multiline_get_coordinates       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_set_dm_data(dm_coordinates *gui_multiline_get_coordinates)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_multiline_inputbox_x = gui_multiline_get_coordinates->s16X;
    MMI_multiline_inputbox_y = gui_multiline_get_coordinates->s16Y;
    MMI_multiline_inputbox_width = gui_multiline_get_coordinates->s16Width;
    MMI_multiline_inputbox_height = gui_multiline_get_coordinates->s16Height;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_set_percentage_scale
 * DESCRIPTION
 *  show how much part of book has been read in percentage
 * PARAMETERS
 *  percentage_scale        [IN]        =percentage of the book read.
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_set_percentage_scale(U8 percentage_scale)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type s[10];
    S32 l, character_height, shortcut_width /* ,scroll_offset */ ;
    U32 scroll_offset;
    double percent;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (percentage_scale == 0)
    {
        wgui_title_set_menu_shortcut_number(percentage_scale + 1);
    }
    else
    {
        wgui_title_set_menu_shortcut_number(percentage_scale);
    }

    if (percentage_scale == COMPLETE_PERCENTAGE_SCALE)
    {   
        scroll_offset = MMI_multiline_inputbox.vbar.range  - MMI_multiline_inputbox.vbar.scale;
        
    }
    else
    {
        percent = (double)percentage_scale/100;
        scroll_offset = (U32)((MMI_multiline_inputbox.vbar.range  - MMI_multiline_inputbox.vbar.scale) * percent);
    }

    shortcut_width = set_menu_item_count(100) + 7;
    resize_menu_shortcut_handler(shortcut_width, MMI_title_height);
    gui_itoa(100, (UI_string_type) s, 10);
    gui_measure_string((UI_string_type) s, &l, &character_height);
    gui_set_vertical_scrollbar_value(&MMI_multiline_inputbox.vbar, scroll_offset);

    if (percentage_callback != NULL)
    {
        if (!gui_multi_line_input_box_is_in_shown(&MMI_multiline_inputbox))
            gui_show_multi_line_input_box(&MMI_multiline_inputbox);
        (*percentage_callback)(wgui_title_get_menu_shortcut_number());
    }
    else
    {
        if (wgui_paging_show_percentage == 1)
        {
            gdi_layer_lock_frame_buffer();/* it should not be displayed to LCD right now */
            gui_redraw_menu_shortcut();
            gdi_layer_unlock_frame_buffer();
        }
    }
    gui_page_info.last_showed_percentage = percentage_scale;

}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_set_percentage_callback
 * DESCRIPTION
 *  set the percentage show function callback
 * PARAMETERS
 *  callback        [IN]        =show callback function
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_set_percentage_callback(void* callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    percentage_callback = (percentage_hdlr)callback;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_highlight_search_string
 * DESCRIPTION
 *  hightlight the search string
 * PARAMETERS
 *  text_offset         [IN]        And the string_len
 *  search_str_len      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_highlight_search_string(S32 text_offset, S8 search_str_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_multiline_inputbox.highlight_start_position = MMI_multiline_inputbox.text + (text_offset * ENCODING_LENGTH);
    MMI_multiline_inputbox.highlight_end_position =
        MMI_multiline_inputbox.text + (text_offset + search_str_len) * ENCODING_LENGTH;

    MMI_multiline_inputbox.cursor_p = MMI_multiline_inputbox.highlight_start_position;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_get_current_page
 * DESCRIPTION
 *  during exit of the screen concerned application make a demand for current page ,text offset and shared bytes currently existing in the multiline buffer.
 * PARAMETERS
 *  page_id                     [IN]        Pointer to the start_id of the page
 *  text_offset                 [IN]        Pointer to the offset of the displayed text position
 *  shared_bytes                [IN]        Currently number of shared bytes
 *  last_showed_percentage      [IN]        Currently displayed page
 *  last_text_offset_y          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_get_current_page(
        PU32 page_id,
        PS32 text_offset,
        PU8 shared_bytes,
        PU8 last_showed_percentage,
        PS32 last_text_offset_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_multiline_inputbox.size_of_total_data <= GUI_PAGE_SIZE)
    {
        *page_id = MMI_multiline_inputbox.start_id;
    }
    else
    {
        *page_id = MMI_multiline_inputbox.page_details[PAGE_ZERO].page_id;
    }
    *text_offset = MMI_multiline_inputbox.text_offset;
    *shared_bytes = MMI_multiline_inputbox.previous_shared_bytes / 2;
    *last_showed_percentage = gui_page_info.last_showed_percentage;

    *last_text_offset_y = MMI_multiline_inputbox.text_offset_y; /* for relocation of text at the end */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_get_visible_count
 * DESCRIPTION
 *  sets the wgui_inputs_ml_get_visible_count flag
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 wgui_inputs_ml_get_visible_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_multiline_inputbox.current_page_count;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_jump_to_end
 * DESCRIPTION
 *  sets the percentage flag
 * PARAMETERS
 *  void
 *  start_id(?)     [IN]        And text_offset
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_jump_to_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 percentage_scale;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (MMI_multiline_inputbox.text_height + MMI_multiline_inputbox.text_offset_y >
           MMI_multiline_inputbox.edit_height)
    {
        gui_paging_multi_line_input_box_next_page(&MMI_multiline_inputbox);
    }
    wgui_inputs_ml_resize(MMI_multiline_inputbox_width, MMI_multiline_inputbox_height);

    percentage_scale = COMPLETE_PERCENTAGE_SCALE;
    wgui_inputs_ml_paging_set_percentage_scale(percentage_scale);
    
    gui_lock_double_buffer();
    wgui_inputs_ml_redraw();
    gui_unlock_double_buffer();
}

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_set_page_info
 * DESCRIPTION
 *  Get the page structure and fill the multiline inputbox element required in 
	 Touch Screen.
 * PARAMETERS
 * gui_page_info_app  
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_set_page_info(gui_page_info_app *page_info_d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	wgui_inputs_ml_paging_set_page(page_info_d->start_id, page_info_d->end_id);
	wgui_inputs_ml_paging_set_font(page_info_d->font_size, page_info_d->font_style);
				   
        MMI_multiline_inputbox.text_offset_y = 0;
	MMI_multiline_inputbox.page_offset = page_info_d->text_offset;
	MMI_multiline_inputbox.jump_offset_from_app = page_info_d->jump_offset_from_app;
	MMI_multiline_inputbox.search_flag_is_on = page_info_d->search_flag_is_on;
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_key_mapping_TS
 * DESCRIPTION
 *  Gives the specified key to application for their handling
 * PARAMETERS
 *  c       [IN]        
 *  UI_character_type
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_key_mapping_TS(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gui_page_info.key_callback != NULL)
    {
        gui_page_info.key_callback(c);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_linebase_key_mapping_TS
 * DESCRIPTION
 *  Gives the specified key to application for their handling
 * PARAMETERS
 *  c       [IN]        
 *  UI_character_type
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_linebase_key_mapping_TS(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (linebase_page_info.key_callback != NULL)
    {
        linebase_page_info.key_callback(c);
    }
}

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_get_data_during_scrolling
 * DESCRIPTION
 *  according to page_id get the data in multiline text buffer for display
 * PARAMETERS
 *  percentage_val  [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_get_data_during_scrolling(S32 percentage_val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	gui_page_info.get_data_during_scrolling(percentage_val,MMI_multiline_inputbox.text);
}
	

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_set_full_screen_flag
 * DESCRIPTION
 *  sets full screen flag to 0 or 1
 * PARAMETERS
 *  flag_value     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_set_full_screen_flag(pBOOL flag_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	full_screen_flag=flag_value;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_pen_up_handler
 * DESCRIPTION
 *  touch screen hadler for category 75 & 77
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_inputs_ml_paging_pen_up_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;
    gui_multi_line_input_box_pen_enum multi_line_input_box_event;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_multiline_inputbox.pen_state.pen_on_scroll_bar = 0;

#ifdef __MMI_CLIPBOARD__
    /* DO NOT handle pen up if in clipboard state */
    if (mmi_imc_is_clipboard_state())
    {
        return MMI_FALSE;
    }
#endif

    if ((MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR)
        || ((MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR) && (MMI_multiline_inputbox.vbar.scale > MMI_multiline_inputbox.vbar.range)))
        return MMI_FALSE;

    if (PEN_CHECK_BOUND
        (pos.x, pos.y, MMI_multiline_inputbox.vbar.x, MMI_multiline_inputbox.vbar.y, MMI_multiline_inputbox.vbar.width,
         MMI_multiline_inputbox.vbar.height))
    {
        gui_vertical_scrollbar_translate_pen_event(
            &MMI_multiline_inputbox.vbar,
            MMI_PEN_EVENT_UP,
            pos.x,
            pos.y,
            &scrollbar_event,
            &scrollbar_param);

        gui_start_timer(WGUI_PAGING_SCROLL_TIMER, wgui_inputs_ml_paging_timer_pen_up_callback);
        return MMI_TRUE;
    }
    else
    {
        ret = (MMI_BOOL)gui_multi_line_input_box_translate_pen_event(
            &MMI_multiline_inputbox,
            MMI_PEN_EVENT_UP,
            pos.x,
            pos.y,
            &multi_line_input_box_event);

        if (ret)
        {
            if (GUI_MULTI_LINE_INPUT_BOX_PEN_SCROLL_BAR != multi_line_input_box_event)
            {
                /* If underline cursor line style multiline (Language learning) */
                if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_UNDERLINE_CURSOR_LINE)
                {
                    gui_show_multi_line_input_box_ext(&MMI_multiline_inputbox, pos.x, pos.y);
                    wgui_inputs_ml_redraw();
                }

                if (percentage_callback != NULL)
                {
                    (*percentage_callback)(wgui_title_get_menu_shortcut_number());
                }
                gui_start_timer(WGUI_PAGING_SCROLL_TIMER, wgui_inputs_ml_paging_timer_pen_up_callback);
                return MMI_TRUE;
            }
        }
        else    
        {
            gui_start_timer(WGUI_PAGING_SCROLL_TIMER, wgui_inputs_ml_paging_timer_pen_up_callback);
        }
    }
    
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_pen_down_handler
 * DESCRIPTION
 *  touch screen hadler for category 75 & 77
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_inputs_ml_paging_pen_down_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 prev_val_scrollbar = MMI_multiline_inputbox.vbar.value;
    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;
    gui_multi_line_input_box_pen_enum multi_line_input_box_event;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR)
        || ((MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR) && (MMI_multiline_inputbox.vbar.scale > MMI_multiline_inputbox.vbar.range)))
        return MMI_FALSE;

    if (PEN_CHECK_BOUND
        (pos.x, pos.y, MMI_multiline_inputbox.vbar.x, MMI_multiline_inputbox.vbar.y, MMI_multiline_inputbox.vbar.width,
         MMI_multiline_inputbox.vbar.height))
    {
        gui_vertical_scrollbar_translate_pen_event(
            &MMI_multiline_inputbox.vbar,
            MMI_PEN_EVENT_DOWN,
            pos.x,
            pos.y,
            &scrollbar_event,
            &scrollbar_param);
        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
        {

            int r = 0;
            
            if(MMI_multiline_inputbox.vbar.scale != 1) /* for file under 4 * page size*/
            {
                r = ((int)MMI_multiline_inputbox.vbar.range - (int)MMI_multiline_inputbox.vbar.scale);
           
                if (prev_val_scrollbar > r) /* means the scroll value large than scrollbar's max value and may adjust the value by scrollbar algo. */
                {
                    if (MMI_multiline_inputbox.vbar.value == r) /* the value has been adjusted */
                    {
                        prev_val_scrollbar = r - 1; /* let pre value less than currnet value for get next page data */
                    }
                }
            }

			gui_cancel_timer(wgui_inputs_ml_paging_timer_forward_callback);
            gui_cancel_timer(wgui_inputs_ml_paging_timer_backward_callback);
            
            if (prev_val_scrollbar < MMI_multiline_inputbox.vbar.value)
            {
                gui_start_timer(WGUI_PAGING_SCROLL_TIMER, wgui_inputs_ml_paging_timer_forward_callback);
            }
            else if (prev_val_scrollbar > MMI_multiline_inputbox.vbar.value)
            {
                gui_start_timer(WGUI_PAGING_SCROLL_TIMER, wgui_inputs_ml_paging_timer_backward_callback);
            }
        }
        else if(MMI_multiline_inputbox.vbar.pen_state.state != GUI_SCROLLBAR_PEN_STATE_SBUTTON)
        {
        	gui_cancel_timer(wgui_inputs_ml_paging_timer_forward_callback);
            gui_cancel_timer(wgui_inputs_ml_paging_timer_backward_callback);
        	
            if (prev_val_scrollbar == 0)
            {
                gui_start_timer(WGUI_PAGING_SCROLL_TIMER, wgui_inputs_ml_paging_timer_backward_callback);
            }
            else
            {
                gui_start_timer(WGUI_PAGING_SCROLL_TIMER, wgui_inputs_ml_paging_timer_forward_callback);
            }
        }

        MMI_multiline_inputbox.pen_state.pen_on_scroll_bar = 1;
        return MMI_TRUE;
    }
    else
    {
        ret = (MMI_BOOL)gui_multi_line_input_box_translate_pen_event(
            &MMI_multiline_inputbox,
            MMI_PEN_EVENT_DOWN,
            pos.x,
            pos.y,
            &multi_line_input_box_event);

        if (ret)
            return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_pen_repeat_handler
 * DESCRIPTION
 *  touch screen handler for category 75 & 77
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_inputs_ml_paging_pen_repeat_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 prev_val_scrollbar = MMI_multiline_inputbox.vbar.value;
    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;
    gui_multi_line_input_box_pen_enum multi_line_input_box_event;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR)
        || ((MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR) && (MMI_multiline_inputbox.vbar.scale > MMI_multiline_inputbox.vbar.range)))
        return MMI_FALSE;

    if (PEN_CHECK_BOUND
        (pos.x, pos.y, MMI_multiline_inputbox.vbar.x, MMI_multiline_inputbox.vbar.y, MMI_multiline_inputbox.vbar.width,
         MMI_multiline_inputbox.vbar.height))
    {
        gui_vertical_scrollbar_translate_pen_event(
            &MMI_multiline_inputbox.vbar,
            MMI_PEN_EVENT_REPEAT,
            pos.x,
            pos.y,
            &scrollbar_event,
            &scrollbar_param);
        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
        {

            int r = 0;
            
            if(MMI_multiline_inputbox.vbar.scale != 1) /* for file under 4 * page size*/
            {
                r = ((int)MMI_multiline_inputbox.vbar.range - (int)MMI_multiline_inputbox.vbar.scale);
           
                if (prev_val_scrollbar > r) /* means the scroll value large than scrollbar's max value and may adjust the value by scrollbar algo. */
                {
                    if (MMI_multiline_inputbox.vbar.value == r) /* the value has been adjusted */
                    {
                        prev_val_scrollbar = r - 1; /* let pre value less than currnet value for get next page data */
                    }
                }
            }

            if (prev_val_scrollbar < MMI_multiline_inputbox.vbar.value)
            {
                gui_start_timer(WGUI_PAGING_SCROLL_TIMER, wgui_inputs_ml_paging_timer_forward_callback);
            }
            else if (prev_val_scrollbar > MMI_multiline_inputbox.vbar.value)
            {
                gui_start_timer(WGUI_PAGING_SCROLL_TIMER, wgui_inputs_ml_paging_timer_backward_callback);
            }
        }

        return MMI_TRUE;
    }
    else
    {
        ret = (MMI_BOOL)gui_multi_line_input_box_translate_pen_event(
            &MMI_multiline_inputbox,
            MMI_PEN_EVENT_REPEAT,
            pos.x,
            pos.y,
            &multi_line_input_box_event);

        if (ret)
            return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_set_async_pen_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_set_async_pen_callback(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    multiline_paging_async_pen_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_timer_pen_up_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_timer_pen_up_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE))
        return;

    if (wgui_inputs_ml_paging_check_to_end())
    {
        gui_set_vertical_scrollbar_value(&MMI_multiline_inputbox.vbar, MMI_multiline_inputbox.vbar.range - MMI_multiline_inputbox.vbar.scale);
        gui_lock_double_buffer();
        gui_show_vertical_scrollbar(&MMI_multiline_inputbox.vbar);
        gui_unlock_double_buffer();
        gui_BLT_double_buffer(
            MMI_multiline_inputbox.vbar.x, 
            MMI_multiline_inputbox.vbar.y, 
            MMI_multiline_inputbox.vbar.x + MMI_multiline_inputbox.vbar.width - 1, 
            MMI_multiline_inputbox.vbar.y + MMI_multiline_inputbox.vbar.height - 1);
    }
    else if (wgui_inputs_ml_paging_check_to_start())
    {
        gui_set_vertical_scrollbar_value(&MMI_multiline_inputbox.vbar, 0);
        gui_lock_double_buffer();
        gui_show_vertical_scrollbar(&MMI_multiline_inputbox.vbar);
        gui_unlock_double_buffer();
        gui_BLT_double_buffer(
            MMI_multiline_inputbox.vbar.x, 
            MMI_multiline_inputbox.vbar.y, 
            MMI_multiline_inputbox.vbar.x + MMI_multiline_inputbox.vbar.width - 1, 
            MMI_multiline_inputbox.vbar.y + MMI_multiline_inputbox.vbar.height - 1);
   }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_timer_backward_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_timer_backward_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE))
        return;

    gdi_layer_lock_frame_buffer();
    if (MMI_multiline_inputbox.scroll_type == WGUI_PAGING_SCROLL_LINE_BY_LINE)
    {
        wgui_inputs_ml_paging_previous_line_in_paging();
    }
    else
    {
        wgui_inputs_ml_paging_previous_page();
    }
    if (multiline_paging_async_pen_callback != NULL)
        multiline_paging_async_pen_callback();
    gdi_layer_unlock_frame_buffer();
    wgui_inputs_ml_show();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_timer_forward_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_timer_forward_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE))
        return;

    gdi_layer_lock_frame_buffer();
    if (MMI_multiline_inputbox.scroll_type == WGUI_PAGING_SCROLL_LINE_BY_LINE)
    {
        wgui_inputs_ml_paging_next_line_in_paging_scroll();
    }
    else
    {
        wgui_inputs_ml_paging_next_page();
    }
    if (multiline_paging_async_pen_callback != NULL)
        multiline_paging_async_pen_callback();
    gdi_layer_unlock_frame_buffer();
    wgui_inputs_ml_show();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_timer_pen_move_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_timer_pen_move_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 real_val, text_val;
    S32 val;
    double act_val;
    S16 page_offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE))
        return;

    act_val = ((double)MMI_multiline_inputbox.vbar.value / (double)(MMI_multiline_inputbox.vbar.range  - MMI_multiline_inputbox.vbar.scale));
    act_val *= (double)100.0;
    
    real_val = (U32) act_val;
    if (act_val - (double)real_val >= 0.7)
    {
        real_val++;
    }
    
    if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE)
    {
        if (stop_auto_scroll_callback)
            stop_auto_scroll_callback();
        wgui_inputs_ml_paging_stop_text_scroll();
    }
    
    MMI_multiline_inputbox.text_offset_y = 0;

    text_val = (U32)wgui_inputs_ml_paging_translate_to_text_percentage((U8)real_val);
    
    wgui_inputs_ml_paging_get_data_during_scrolling(text_val);
    
    MMI_multiline_inputbox.previous_shared_bytes = 0;
    
    MMI_multiline_inputbox.search_flag_is_on = 0;
    
    if (MMI_multiline_inputbox.header_height > 0 )
    {
        MMI_multiline_inputbox.text_offset_y = -MMI_multiline_inputbox.header_height;
    }
    
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    if (MMI_multiline_inputbox.last_page_id > 3)
        gui_mlc_all_line_update();
#endif

    if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_UNDERLINE_CURSOR_LINE)
    {
        MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_LOCATE_CURSOR;
        wgui_inputs_ml_show_no_draw();
        MMI_multiline_inputbox.ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_LOCATE_CURSOR;
    }
    else
        wgui_inputs_ml_show_no_draw();
    
    if(MMI_multiline_inputbox.header_height > 0 || MMI_multiline_inputbox.footer_height > 0)
    {
        act_val = (double)real_val/100;
        val = (S32)((MMI_multiline_inputbox.size_of_total_data + MMI_multiline_inputbox.header_height + MMI_multiline_inputbox.footer_height)
            * act_val);
        if(val <= MMI_multiline_inputbox.header_height)
            MMI_multiline_inputbox.text_offset_y = -val;
        else if(val >= MMI_multiline_inputbox.size_of_total_data + MMI_multiline_inputbox.header_height)
            MMI_multiline_inputbox.text_offset_y = -(MMI_multiline_inputbox.text_height - MMI_multiline_inputbox.footer_height
            + (val - MMI_multiline_inputbox.size_of_total_data - MMI_multiline_inputbox.header_height));              
        
        if (wgui_inputs_ml_paging_check_to_end())
            MMI_multiline_inputbox.text_offset_y = MMI_multiline_inputbox.edit_height - MMI_multiline_inputbox.text_height;
    }
    
    if (MMI_multiline_inputbox.vbar.value == MMI_multiline_inputbox.vbar.range - MMI_multiline_inputbox.vbar.scale)
    {
        MMI_multiline_inputbox.text_offset_y = MMI_multiline_inputbox.edit_height - MMI_multiline_inputbox.text_height;
    }
    
    if (wgui_inputs_ml_paging_check_to_end())
    {
        MMI_multiline_inputbox.text_offset_y = MMI_multiline_inputbox.edit_height - MMI_multiline_inputbox.text_height;
        real_val = COMPLETE_PERCENTAGE_SCALE;
        /* text_offset_y changed, so we need re caculate the information */
        wgui_inputs_ml_show_no_draw();
    }
    
    if (MMI_multiline_inputbox.text_offset_y > 0)
        MMI_multiline_inputbox.text_offset_y = 0;
    
    wgui_inputs_ml_paging_set_percentage_scale_TS((U8) real_val);
    if (multiline_paging_async_pen_callback != NULL)
        multiline_paging_async_pen_callback();
    wgui_inputs_ml_redraw();

    UI_UNUSED_PARAMETER(page_offset);
    return ;  
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_pen_move_handler
 * DESCRIPTION
 *  touch screen handler for category 75 & 77
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_inputs_ml_paging_pen_move_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 wgui_prev_scrollbar_value, page_id, required_bytes, real_val, text_val;
    S32 val;
    double act_val;
    S16 page_offset;
    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;
#ifdef __MMI_FTE_SUPPORT__
    MMI_BOOL ret = MMI_FALSE;
    gui_multi_line_input_box_pen_enum multi_line_input_box_event;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(page_offset);
    UI_UNUSED_PARAMETER(act_val);
    UI_UNUSED_PARAMETER(val);
    UI_UNUSED_PARAMETER(page_id);
    UI_UNUSED_PARAMETER(required_bytes);
    UI_UNUSED_PARAMETER(real_val);
    UI_UNUSED_PARAMETER(text_val);
    
    if ((MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR)
        || ((MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR) && (MMI_multiline_inputbox.vbar.scale > MMI_multiline_inputbox.vbar.range)))
            return MMI_FALSE;

#ifdef __MMI_FTE_SUPPORT__
    if (PEN_CHECK_BOUND
        (pos.x, pos.y, MMI_multiline_inputbox.vbar.x, MMI_multiline_inputbox.vbar.y, MMI_multiline_inputbox.vbar.width,
        MMI_multiline_inputbox.vbar.height))
#endif /* __MMI_FTE_SUPPORT__ */
    {
        wgui_prev_scrollbar_value = MMI_multiline_inputbox.vbar.value;
        gui_vertical_scrollbar_translate_pen_event(
            &MMI_multiline_inputbox.vbar,
            MMI_PEN_EVENT_MOVE,
            pos.x,
            pos.y,
            &scrollbar_event,
            &scrollbar_param);

        if ((scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I) && 
            (MMI_multiline_inputbox.vbar.pen_state.state == GUI_SCROLLBAR_PEN_STATE_SBUTTON))
        {
            if (MMI_multiline_inputbox.vbar.value != wgui_prev_scrollbar_value)
            {
                gui_cancel_timer(wgui_inputs_ml_paging_timer_pen_up_callback);
                gui_start_timer(WGUI_PAGING_SCROLL_TIMER, wgui_inputs_ml_paging_timer_pen_move_callback);
            }
        }
        return MMI_TRUE;
    }
#ifdef __MMI_FTE_SUPPORT__
    else
    {
        ret = (MMI_BOOL)gui_multi_line_input_box_translate_pen_event(
            &MMI_multiline_inputbox,
            MMI_PEN_EVENT_MOVE,
            pos.x,
            pos.y,
            &multi_line_input_box_event);
        
        MMI_multiline_inputbox.pen_state.pen_on_scroll_bar = 0;
        
        if (ret)
            return MMI_TRUE;
    }
    return MMI_FALSE;
#endif /* __MMI_FTE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_clear_pen_timer_handler
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_clear_pen_timer_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(wgui_inputs_ml_paging_timer_forward_callback);
    gui_cancel_timer(wgui_inputs_ml_paging_timer_backward_callback);
    gui_cancel_timer(wgui_inputs_ml_paging_timer_pen_move_callback);
    gui_cancel_timer(wgui_inputs_ml_paging_timer_pen_up_callback);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_virtual_keypad_callback
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_paging_virtual_keypad_callback()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_redraw_screen_by_state();
}				
#endif /* __MMI_TOUCH_SCREEN__ */ 
#endif /* __UI_PAGING_IN_MULTILINE_EDITOR__ */ /* ritesh */

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_update_content
 * DESCRIPTION
 *  Update Multiline editor content cache infor, called by app when multiline
 *  text changed.
 * PARAMETERS
 *  void  
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_update_content(void)
{
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    gui_mlc_all_line_update();
#endif
}

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_toggle_insert_mode
 * DESCRIPTION
 *  Toggles between insert and overwrite modes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_toggle_insert_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_multi_line_input_box_toggle_insert_mode(&MMI_multiline_inputbox);
    wgui_inputs_ml_redraw();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_delete_current_character
 * DESCRIPTION
 *  Deletes a character at the cursor position (Delete)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_delete_current_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_multi_line_input_box_delete_current_character(&MMI_multiline_inputbox);
    wgui_inputs_ml_redraw();
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
    if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INCLUDE_INFO_AREA))
#endif 
        multiline_inputbox_input_callback();
}

#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_wcss_alphabetic_keyboard_input_handler
 * DESCRIPTION
 *  Alphabatic keyboard input handler for the multiline inputbox
 *  
 *  Internal function
 * PARAMETERS
 *  keyc        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_wcss_alphabetic_keyboard_input_handler(S32 keyc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (keyc == 0xc0)
    {
        wgui_inputs_ml_direct_input_no_LF_check((UI_character_type) '\n');
    }
    else if (keyc == 0xbb)
    {
        wgui_inputs_ml_direct_input((UI_character_type) 0x0d);
    }
    else if (keyc == 0xbd)
    {
        wgui_inputs_ml_direct_input((UI_character_type) 0x1b);
    }
    else if (keyc == 0x08)
    {
        wgui_inputs_ml_delete_character();
    }
    else if (keyc == 0x1b)
    {
        wgui_inputs_ml_delete_all_characters();
    }
    else if (keyc == 0x0d)
    {
        wgui_inputs_ml_direct_input((U8) '\n');
    }
    else if (keyc >= '0' && keyc <= '9');   /* We cannot input numbers for some input formats */
    else if (keyc > 0x1f)
    {
        wgui_inputs_ml_direct_input((U8) keyc);
    }
}
#endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_key_handler
 * DESCRIPTION
 *  Keyboard handler for the multiline inputbox
 *  
 *  Internal function
 * PARAMETERS
 *  vkey_code       [IN]        Scan code of the key
 *  key_state       [IN]        Key event type (up, down...)
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_key_handler(S32 vkey_code, S32 key_state)
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
        #if(ENABLE_MULTILINE_INPUTBOX_TEST_WORD_HIGHLIGHT)
                MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        #endif 
                wgui_inputs_ml_previous_character();
                break;
            case 38:
        #if(ENABLE_MULTILINE_INPUTBOX_TEST_WORD_HIGHLIGHT)
                gui_multi_line_input_box_highlight_cursor_start(&MMI_multiline_inputbox);
                wgui_inputs_ml_show();
        #else /* (ENABLE_MULTILINE_INPUTBOX_TEST_WORD_HIGHLIGHT) */ 
                wgui_inputs_ml_previous_line();
        #endif /* (ENABLE_MULTILINE_INPUTBOX_TEST_WORD_HIGHLIGHT) */ 
                break;
            case 39:
        #if(ENABLE_MULTILINE_INPUTBOX_TEST_WORD_HIGHLIGHT)
                MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        #endif 
                wgui_inputs_ml_next_character();
                break;
            case 40:
        #if(ENABLE_MULTILINE_INPUTBOX_TEST_WORD_HIGHLIGHT)
                gui_multi_line_input_box_highlight_cursor_end(&MMI_multiline_inputbox);
                wgui_inputs_ml_show();
        #else /* (ENABLE_MULTILINE_INPUTBOX_TEST_WORD_HIGHLIGHT) */ 
                wgui_inputs_ml_next_line();
        #endif /* (ENABLE_MULTILINE_INPUTBOX_TEST_WORD_HIGHLIGHT) */ 
                break;
            case 36:
                wgui_inputs_ml_home();
                break;
            case 35:
                wgui_inputs_ml_end();
                break;
            case 33:
                wgui_inputs_ml_previous_page();
                break;
            case 34:
                wgui_inputs_ml_next_page();
                break;
            case 45:
                wgui_inputs_ml_toggle_insert_mode();
                break;
            case 46:
                wgui_inputs_ml_delete_current_character();
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
 *  wgui_inputs_ml_register_keys
 * DESCRIPTION
 *  Registers the keys for the multiline inputbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_register_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(wgui_inputs_ml_previous_character, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_inputs_ml_next_character, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

#if defined(__COSMOS_MMI_PACKAGE__)
    SetKeyHandler(wgui_inputs_ml_delete_character, KEY_CLEAR, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_inputs_ml_delete_all_characters, KEY_CLEAR, KEY_LONG_PRESS);
   // SetKeyHandler(wgui_inputs_ml_delete_character, KEY_VOL_DOWN, KEY_EVENT_DOWN);
  //  SetKeyHandler(wgui_inputs_ml_delete_all_characters, KEY_VOL_DOWN, KEY_LONG_PRESS);
#endif

    SetKeyHandler(wgui_inputs_ml_handle_left_arrow_repeat, KEY_LEFT_ARROW, KEY_REPEAT);
    SetKeyHandler(wgui_inputs_ml_handle_right_arrow_repeat, KEY_RIGHT_ARROW, KEY_REPEAT);
    SetKeyHandler(wgui_inputs_fast_del_nav_reset_repeat_count, KEY_LEFT_ARROW, KEY_LONG_PRESS);
    SetKeyHandler(wgui_inputs_fast_del_nav_reset_repeat_count, KEY_RIGHT_ARROW, KEY_LONG_PRESS);

#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
    if (MMI_multi_line_inputbox_present)
    {
        SetKeyHandler(wgui_inputs_ml_inline_previous_line, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(wgui_inputs_ml_inline_previous_line, KEY_VOL_UP, KEY_EVENT_DOWN);
        SetKeyHandler(wgui_inputs_ml_inline_next_line, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(wgui_inputs_ml_inline_next_line, KEY_VOL_DOWN, KEY_EVENT_DOWN);

        SetKeyHandler(wgui_inputs_ml_inline_handle_up_arrow_repeat, KEY_UP_ARROW, KEY_REPEAT);
        SetKeyHandler(wgui_inputs_ml_inline_handle_down_arrow_repeat, KEY_DOWN_ARROW, KEY_REPEAT);
        SetKeyHandler(wgui_inputs_ml_inline_handle_up_arrow_repeat, KEY_VOL_UP, KEY_REPEAT);
        SetKeyHandler(wgui_inputs_ml_inline_handle_down_arrow_repeat, KEY_VOL_DOWN, KEY_REPEAT);
        SetKeyHandler(wgui_inputs_fast_del_nav_reset_repeat_count, KEY_UP_ARROW, KEY_LONG_PRESS);
        SetKeyHandler(wgui_inputs_fast_del_nav_reset_repeat_count, KEY_DOWN_ARROW, KEY_LONG_PRESS);
        SetKeyHandler(wgui_inputs_fast_del_nav_reset_repeat_count, KEY_VOL_UP, KEY_LONG_PRESS);
        SetKeyHandler(wgui_inputs_fast_del_nav_reset_repeat_count, KEY_VOL_DOWN, KEY_LONG_PRESS);        
    }
    else
    {
#endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 
        SetKeyHandler(wgui_inputs_ml_previous_line, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(wgui_inputs_ml_next_line, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        
        SetKeyHandler(wgui_inputs_ml_handle_up_arrow_repeat, KEY_UP_ARROW, KEY_REPEAT);
        SetKeyHandler(wgui_inputs_ml_handle_down_arrow_repeat, KEY_DOWN_ARROW, KEY_REPEAT);
        SetKeyHandler(wgui_inputs_fast_del_nav_reset_repeat_count, KEY_UP_ARROW, KEY_LONG_PRESS);
        SetKeyHandler(wgui_inputs_fast_del_nav_reset_repeat_count, KEY_DOWN_ARROW, KEY_LONG_PRESS);
        
    #if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
    }
    #endif 
    /* SetKeyHandler(wgui_inputs_ml_delete_character,KEY_CLEAR,KEY_EVENT_DOWN); */
    register_keyboard_key_handler(wgui_inputs_ml_key_handler);
    /* Add key handlers here for Clear and input mode key */
    if (wgui_register_multiline_inputbox_up_down_key_handler != NULL)
    {
        wgui_register_multiline_inputbox_up_down_key_handler();
    }

    mmi_imc_key_set_pre_key_handler(wgui_inputs_ml_pre_key_handler);
}

#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
/* Function to register arrow key function pointers for inscreen multiline box. */


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_inline_register_keys
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_inline_register_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(wgui_inputs_ml_previous_character, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_inputs_ml_next_character, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_inputs_ml_inline_previous_line, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_inputs_ml_inline_next_line, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    register_keyboard_key_handler(wgui_inputs_ml_key_handler);
}
#endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_viewer_key_handler
 * DESCRIPTION
 *  Keyboard handler for the multiline inputbox
 *  
 *  Internal function
 * PARAMETERS
 *  vkey_code       [IN]        Scan code of the key
 *  key_state       [IN]        Key event type (up, down...)
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_viewer_key_handler(S32 vkey_code, S32 key_state)
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
            case 37:    /* multiline inputbox viewer supports only two way navigation  */
                break;
            case 38:
                wgui_inputs_ml_previous_line();
                break;
            case 39:    /* multiline inputbox viewer supports only two way navigation  */
                break;
            case 40:
                wgui_inputs_ml_next_line();
                break;
            case 36:
                wgui_inputs_ml_home();
                break;
            case 35:
                wgui_inputs_ml_end();
                break;
            case 33:
                wgui_inputs_ml_previous_page();
                break;
            case 34:
                wgui_inputs_ml_next_page();
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
 *  wgui_inputs_ml_register_viewer_keys
 * DESCRIPTION
 *  Registers the keys for the multiline inputbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_register_viewer_keys(void)
{   /* multiline inputbox viewer supports only two way navigation  */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(wgui_inputs_ml_previous_line, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_inputs_ml_next_line, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_inputs_ml_previous_line, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_inputs_ml_next_line, KEY_VOL_DOWN, KEY_EVENT_DOWN);

    SetKeyHandler(wgui_inputs_ml_previous_line, KEY_UP_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(wgui_inputs_ml_next_line, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(wgui_inputs_ml_previous_line, KEY_VOL_UP, KEY_EVENT_REPEAT);
    SetKeyHandler(wgui_inputs_ml_next_line, KEY_VOL_DOWN, KEY_EVENT_REPEAT);

    if (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INSIDE_INLINE_MENU)
    {
        SetKeyHandler(wgui_inputs_ml_home, KEY_UP_ARROW, KEY_LONG_PRESS);
    }
    
    /* Set key for App's */
    if (multiline_inputbox_set_key_callback)
    {
        multiline_inputbox_set_key_callback();
    }

    register_keyboard_key_handler(wgui_inputs_ml_viewer_key_handler);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_previous_hilite
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_previous_hilite(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_multi_line_input_box_go_to_pre_hilite(&MMI_multiline_inputbox);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_next_hilite
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_next_hilite(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_multi_line_input_box_go_to_next_hilite(&MMI_multiline_inputbox);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_register_hilite_keys
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_register_hilite_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(wgui_inputs_ml_previous_hilite, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_inputs_ml_next_hilite, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

#ifdef __MMI_TOUCH_SCREEN__

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_hilite_pen_handler
 * DESCRIPTION
 *  Handle pen event in hilite, it will only handle the pen event in editor
 *  if pos is out of editor bounds, it will return MMI_FALSE directly
 *  currently not support clipboard pen event
 * PARAMETERS
 *  pos             [IN]        
 *  pen_event       [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL wgui_inputs_ml_hilite_pen_handler(mmi_pen_point_struct pos, mmi_pen_event_type_enum pen_event)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL ret = MMI_FALSE;
	gui_multi_line_input_box_pen_enum multi_line_input_box_event;
	MMI_BOOL isSSP = MMI_FALSE;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!PEN_CHECK_BOUND(
            pos.x,
            pos.y,
            MMI_multiline_inputbox.x,
            MMI_multiline_inputbox.y,
            MMI_multiline_inputbox.width,
            MMI_multiline_inputbox.height))
	{
		// not in editor area
		return MMI_FALSE;
	}

	ret = (MMI_BOOL)gui_multi_line_input_box_translate_pen_event(
            &MMI_multiline_inputbox,
            pen_event,
            pos.x,
            pos.y,
            &multi_line_input_box_event);

	switch (pen_event)
	{
	case MMI_PEN_EVENT_DOWN:
		{
			if ((ret == MMI_TRUE) && (multi_line_input_box_event == GUI_MULTI_LINE_INPUT_BOX_PEN_TEXT_DOWN))
			{
				MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
				gui_show_multi_line_input_box_ext(&MMI_multiline_inputbox, pos.x, pos.y);
				MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
				if (gui_multi_line_input_box_is_pen_down_in_hilite(&MMI_multiline_inputbox))
				{
					wgui_inputs_ml_set_pen_down_flag();
					gui_multi_line_input_box_go_to_hilite(
						&MMI_multiline_inputbox,
						MMI_multiline_inputbox.current_hilite_idx,
						MMI_FALSE);
					wgui_inputs_ml_clear_pen_down_flag();
				}
			}
			break;
		}
	case MMI_PEN_EVENT_UP:
		{
		#ifdef __MMI_EDITOR_SSP_SUPPORT__
			isSSP = gui_input_box_ssp_is_scrolling();
		#endif
			if (!isSSP)
			{
				if ((ret == MMI_TRUE) && (multi_line_input_box_event == GUI_MULTI_LINE_INPUT_BOX_PEN_TEXT_UP) &&
					MMI_multiline_inputbox.hilite_click_cb)
				{
					// click on highlight list
					U16 idx = 0;
					MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
					gui_show_multi_line_input_box_ext(&MMI_multiline_inputbox, pos.x, pos.y);
					MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
					if (gui_multi_line_input_box_is_pos_inside_hilite_ext(&MMI_multiline_inputbox, MMI_multiline_inputbox.cursor_p, &idx))
					{
						if (idx == MMI_multiline_inputbox.current_hilite_idx)
						{
							MMI_multiline_inputbox.hilite_click_cb(MMI_multiline_inputbox.current_hilite_idx);
						}
					}
				}
	 		}
			break;
		}
	default:
		break;
	}

	return ret;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_hilite_pen_down_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_hilite_pen_down_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    gui_multi_line_input_box_pen_enum multi_line_input_box_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputbox_pen_down_inside_multiline_with_hilite_flag = MMI_FALSE;
    ret = (MMI_BOOL)gui_multi_line_input_box_translate_pen_event(
            &MMI_multiline_inputbox,
            MMI_PEN_EVENT_DOWN,
            pos.x,
            pos.y,
            &multi_line_input_box_event);

#ifdef __MMI_CLIPBOARD__
    if (mmi_imc_is_clipboard_state())
    {
        wgui_general_pen_down_hdlr(pos);
        return;
    }
#endif

    if ((ret == MMI_TRUE) && (multi_line_input_box_event == GUI_MULTI_LINE_INPUT_BOX_PEN_TEXT_DOWN))
    {
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        gui_show_multi_line_input_box_ext(&MMI_multiline_inputbox, pos.x, pos.y);
        MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        if (gui_multi_line_input_box_is_pen_down_in_hilite(&MMI_multiline_inputbox))
        {
            wgui_inputs_ml_set_pen_down_flag();
            gui_multi_line_input_box_go_to_hilite(
                &MMI_multiline_inputbox,
                MMI_multiline_inputbox.current_hilite_idx,
                MMI_FALSE);
            wgui_inputs_ml_clear_pen_down_flag();
        #ifdef __MMI_CLIPBOARD__
            /* Should pass the pen event to clipboard/IME to handle down event */
            wgui_general_pen_down_hdlr(pos);
        #endif /* __MMI_CLIPBOARD__ */
        }
        else
        {
            wgui_general_pen_down_hdlr(pos);
            //gui_show_multi_line_input_box(&MMI_multiline_inputbox);
            //gui_BLT_double_buffer(MMI_multiline_inputbox.x, MMI_multiline_inputbox.y, MMI_multiline_inputbox.x + MMI_multiline_inputbox.width, 
            //    MMI_multiline_inputbox.y + MMI_multiline_inputbox.height);
        }
        wgui_inputbox_pen_down_inside_multiline_with_hilite_flag = MMI_TRUE;
    }
    else
    {
        wgui_general_pen_down_hdlr(pos);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_hilite_pen_up_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_hilite_pen_up_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    gui_multi_line_input_box_pen_enum multi_line_input_box_event;
    MMI_BOOL isSSP = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EDITOR_SSP_SUPPORT__
    isSSP = gui_input_box_ssp_is_scrolling();
#endif /* __MMI_EDITOR_SSP_SUPPORT__ */

    if (!isSSP)
    {
        ret = (MMI_BOOL)gui_multi_line_input_box_translate_pen_event(
                &MMI_multiline_inputbox,
                MMI_PEN_EVENT_DOWN,
                pos.x,
                pos.y,
                &multi_line_input_box_event);

        if ((ret == MMI_TRUE) && (multi_line_input_box_event == GUI_MULTI_LINE_INPUT_BOX_PEN_TEXT_DOWN) &&
            MMI_multiline_inputbox.hilite_click_cb && wgui_inputbox_pen_down_inside_multiline_with_hilite_flag)
        {
            // click on highlight list
            U16 idx = 0;
            MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
            gui_show_multi_line_input_box_ext(&MMI_multiline_inputbox, pos.x, pos.y);
            MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
            if (gui_multi_line_input_box_is_pos_inside_hilite_ext(&MMI_multiline_inputbox, MMI_multiline_inputbox.cursor_p, &idx))
            {
                if (idx == MMI_multiline_inputbox.current_hilite_idx)
                {
                    MMI_multiline_inputbox.hilite_click_cb(MMI_multiline_inputbox.current_hilite_idx);
                }
            }
        }
        else
        {
            wgui_general_pen_up_hdlr(pos);
        }
    }
    else
    {
        wgui_general_pen_up_hdlr(pos);
    }
    wgui_inputbox_pen_down_inside_multiline_with_hilite_flag = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_register_hilite_pen_event_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_register_hilite_pen_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_register_down_handler(wgui_inputs_ml_hilite_pen_down_handler);
#if !defined(__MMI_CLIPBOARD__)
    mmi_pen_register_up_handler(wgui_inputs_ml_hilite_pen_up_handler);
#endif
}
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_set_mask
 * DESCRIPTION
 *  Sets character masking for the multiline inputbox
 * PARAMETERS
 *  m       [IN]        0: Normal, 1: Masked
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_set_mask(U8 m)
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
            MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_MASK_CHARACTERS;
            break;
        case 1:
            MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_MASK_CHARACTERS;

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
            gui_mlc_change_request(0);
#endif
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_reset
 * DESCRIPTION
 *  Clears the keyhandlers for the multiline inputbox
 * PARAMETERS
 *  void
 *  m(?)        [IN]        0: Normal, 1: Masked
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_reset(void)
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
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
    gui_cancel_timer(wgui_inputs_ml_end_frame);
    wgui_multiline_inputbox_frame_counter = 0;
#endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING)) */ 
    gui_cancel_timer(wgui_inputs_ml_vertical_scroll);

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    gui_inputs_cache_destroy();
#endif

    g_mmi_wgui_halfline_marquee_scroll_enable = 0;  /* Disable it here */

    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_UP);
    ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_UP);
    ClearKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_UP);
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_REPEAT);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_REPEAT);
    ClearKeyHandler(KEY_UP_ARROW, KEY_REPEAT);
    ClearKeyHandler(KEY_DOWN_ARROW, KEY_REPEAT);
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_UP_ARROW, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_DOWN_ARROW, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_CLEAR, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_CLEAR, KEY_EVENT_UP);
    ClearKeyHandler(KEY_CLEAR, KEY_EVENT_LONG_PRESS);
    clear_keyboard_key_handler();
    clear_keyboard_input_handler();
    wgui_inputs_multitap_clear_key_handlers();
    /* The callback function might be invalid after screen exit function */
    MMI_multiline_inputbox.icon_callback = NULL;
    multiline_inputbox_input_callback = UI_dummy_function;
    multiline_inputbox_navigate_callback = UI_dummy_function;
    wgui_inputs_ml_reset_pre_key_handler();
    wgui_inputs_ml_reset_pre_delete_callback();

    multiline_inputbox_set_key_callback = NULL;
    
#ifdef __MMI_EDITOR_SSP_SUPPORT__
    {
        mmi_pen_point_struct point = {0, 0};
        
        gui_input_box_ssp_pen_translate(point, MMI_PEN_EVENT_ABORT);
    }

    mmi_pen_config_sampling_period(MMI_PEN_SAMPLING_PERIOD_1, MMI_PEN_SAMPLING_PERIOD_2);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_reset_vertical_scroll
 * DESCRIPTION
 *  Resets the multiline input bix vertical scroll timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_reset_vertical_scroll()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(wgui_inputs_ml_vertical_scroll);
#if(UI_BLINKING_CURSOR_SUPPORT)
    /* gui_cancel_timer(UI_inputbox_blink_cursor); */
    StopTimer(BLINKING_CURSOR);
#endif /* (UI_BLINKING_CURSOR_SUPPORT) */ 
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
    gui_cancel_timer(wgui_inputs_ml_end_frame);
    wgui_multiline_inputbox_frame_counter = 0;
#endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING)) */ 

}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_is_empty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 wgui_inputs_ml_is_empty(void)
{
#ifdef __ASCII
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_multiline_inputbox.text_length <= 1)
    {
        return (1);
    }
    else
    {
        return (0);
    }
#endif /* __ASCII */ 
#ifdef __UCS2_ENCODING
    if (MMI_multiline_inputbox.text_length <= 2)
    {
        return (1);
    }
    else
    {
        return (0);
    }
#endif /* __UCS2_ENCODING */ 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_get_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 wgui_inputs_ml_get_length(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Function is not accurate. Should actually return the number of characters, not including the end of string character */
#ifdef __ASCII
    return (MMI_multiline_inputbox.text_length);
#endif 
#ifdef __UCS2_ENCODING
    return (MMI_multiline_inputbox.text_length / 2);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_get_line_height
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 wgui_inputs_ml_get_line_height(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_multiline_inputbox.max_line_height == 0)
    {
        return (1);
    }
    else
    {
        return (MMI_multiline_inputbox.max_line_height);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_get_display_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL wgui_inputs_ml_get_display_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW)
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
 *  wgui_inputs_ml_get_height
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 wgui_inputs_ml_get_height(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_multiline_inputbox.height;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_get_line_height_with_obj
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 wgui_inputs_ml_get_line_height_with_obj(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b == NULL)
    {
        return 0;
    }

    if (b->max_line_height == 0)
    {
        return (1);
    }
    else
    {
        return (b->max_line_height);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_is_in_view_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL wgui_inputs_ml_is_in_view_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

/* 
 * General multiline inputbox icon handler provided by WGUI.
 *
 * Applications can create its own icon handlers or use wgui_inputs_ml_general_icon_handler()
 */


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_config_general_icon_handler
 * DESCRIPTION
 *  setup general icon handler that can be used inside multiline_input_box
 * PARAMETERS
 *  is_sorted       [IN]        If there are many types of icons, it is suggested
 *  num_items       [IN]        The number of icon types available
 *  items           [IN]        Icon types
 *  to(?)           [IN]        Sort them by gui_multiline_icon_item_struct.string.
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_config_general_icon_handler(BOOL is_sorted, U8 num_items, const wgui_multiline_icon_struct *items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_wgui_multiline_icon_handler_cntx.is_sorted = is_sorted;
    g_mmi_wgui_multiline_icon_handler_cntx.num_items = num_items;
    g_mmi_wgui_multiline_icon_handler_cntx.items = items;
    g_mmi_wgui_multiline_icon_handler_cntx.last_items = items + num_items - 1;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_reset_general_icon_handler
 * DESCRIPTION
 *  Reset general icon handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_reset_general_icon_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_wgui_multiline_icon_handler_cntx.is_sorted = MMI_FALSE;
    g_mmi_wgui_multiline_icon_handler_cntx.num_items = 0;
    g_mmi_wgui_multiline_icon_handler_cntx.items = NULL;
    g_mmi_wgui_multiline_icon_handler_cntx.last_items = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_general_icon_handler
 * DESCRIPTION
 *  setup general icon handler that can be used inside multiline_input_box
 * PARAMETERS
 *  s               [IN]        Input string
 *  do_draw         [IN]        Whether to draw the icon
 *  icon_width      [OUT]       
 *  icon_height     [OUT]       
 *  x               [IN]        X-axis of icon position
 *  y               [IN]        Y-axis of icon position
 * RETURNS
 *  the number of character in the icon sequence.
 *****************************************************************************/
S32 wgui_inputs_ml_general_icon_handler(const U8 *s, BOOL do_draw, S32 *icon_width, S32 *icon_height, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL found = MMI_FALSE;
    const wgui_multiline_icon_struct *item;
    S32 char_cnt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_wgui_multiline_icon_handler_cntx.is_sorted)   /* Use binary search */
    {
        S32 l, r, x;
        const char *t1, *t2;

        l = 0;
        r = g_mmi_wgui_multiline_icon_handler_cntx.num_items - 1;

        while (r >= l)
        {
            x = ((l + r) >> 1);
            item = g_mmi_wgui_multiline_icon_handler_cntx.items + x;

            t1 = item->string;
            t2 = item->string + MMI_MULTILINE_ICON_MAX_STRING_LEN;
            char_cnt = 0;
            for (; t1 <= t2; t1++, char_cnt++)
            {
                S32 char_cnt2 = char_cnt << 1;

                if (!*t1)
                {
                    found = MMI_TRUE;
                    break;
                }
                if (s[char_cnt2 + 1] || ((U8) * t1 < s[char_cnt2]))
                {
                    l = x + 1;
                    break;
                }
                if ((U8) * t1 > s[char_cnt2])
                {
                    r = x - 1;
                    break;
                }
            }
            if (found)
            {
                break;
            }
        }
    }
    else    /* Use linear search */
    {
        const wgui_multiline_icon_struct *last_item;
        const char *t1, *t2;

        item = g_mmi_wgui_multiline_icon_handler_cntx.items;
        last_item = g_mmi_wgui_multiline_icon_handler_cntx.last_items;
        for (; item <= last_item; item++)
        {
            t1 = item->string;
            t2 = item->string + MMI_MULTILINE_ICON_MAX_STRING_LEN;
            char_cnt = 0;
            for (; t1 <= t2; t1++, char_cnt++)
            {
                S32 char_cnt2 = char_cnt << 1;

                if (!*t1)
                {
                    found = MMI_TRUE;
                    break;
                }
                if (s[char_cnt2 + 1] || (U8) * t1 != s[char_cnt2])
                {
                    break;
                }
            }
            if (found)
            {
                break;
            }
        }
    }

    if (found)
    {
        if (do_draw)
        {
            gui_show_transparent_image(x, y, item->icon, 0);
        }
        if (icon_width)
        {
            *icon_width = (S32) item->icon_width;
        }
        if (icon_height)
        {
            *icon_height = (S32) item->icon_height;
        }
        return char_cnt;
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_set_register_up_down_key_funcptr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  FuncPtr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_set_register_up_down_key_funcptr(void (*FuncPtr) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_register_multiline_inputbox_up_down_key_handler = FuncPtr;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_reset_register_up_down_key_funcptr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_reset_register_up_down_key_funcptr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_register_multiline_inputbox_up_down_key_handler = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_register_infobar_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_register_infobar_callback(
                void(*redraw_callback)(S32 x1,S32 y1,S32 x2,S32 y2),
                void(*reminder_char_callback)(S32 x1,S32 y1,S32 x2,S32 y2),
                U32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_height = wgui_inputbox_information_bar_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_multi_line_input_box_register_infobar_callback(
            &MMI_multiline_inputbox,
            redraw_callback,
            reminder_char_callback,
            height);

    if(old_height != wgui_inputbox_information_bar_height)
    {
        S32 new_height = MMI_multiline_inputbox.height + old_height - wgui_inputbox_information_bar_height;
        S32 new_y = MMI_multiline_inputbox.y + MMI_multiline_inputbox.height - new_height;

        gui_move_multi_line_input_box(&MMI_multiline_inputbox, MMI_multiline_inputbox.x,new_y);
        gui_resize_multi_line_input_box(&MMI_multiline_inputbox,MMI_multiline_inputbox.width, new_height);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_register_change_event_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_register_change_event_handler(
			MMI_BOOL (*handler)(gui_multi_line_input_box_change_event_enum event,U16 C))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	gui_multi_line_input_box_register_change_event_handler(&MMI_multiline_inputbox,handler);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_set_text_color
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_set_text_color(color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_multiline_inputbox.normal_text_color = c;
}


/*****************************************************************************
* FUNCTION
*  wgui_inputs_ml_clear_pen_down_flag
* DESCRIPTION
*         
* PARAMETERS
* void        
* RETURNS
*  void
*****************************************************************************/
void wgui_inputs_ml_clear_pen_down_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    multi_line_pen_down_hilite_flag = MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  wgui_inputs_ml_set_pen_down_flag
* DESCRIPTION
*  
* PARAMETERS
* void       
* RETURNS
*  void
*****************************************************************************/
void wgui_inputs_ml_set_pen_down_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    multi_line_pen_down_hilite_flag = MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  wgui_inputs_ml_get_pen_down_flag
* DESCRIPTION
*  
* PARAMETERS
* void        
* RETURNS
*  void
*****************************************************************************/
BOOL wgui_inputs_ml_get_pen_down_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return multi_line_pen_down_hilite_flag;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_set_category_history_ext
 * DESCRIPTION
 *  Sets the history data for the multiline inputbox from the given history buffer
 * PARAMETERS
 *  history_ID          [IN]        Is the ID used by category screens
 *  history_buffer      [IN]        Is the buffer from which history data is taken
 *  input_type          [?]         
 * RETURNS
 *  Returns true if the history ID is valid
 *****************************************************************************/
U8 wgui_inputs_ml_set_category_history_ext(multi_line_input_box *b, U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        multiline_inputbox_category_history *h = (multiline_inputbox_category_history*) history_buffer;

        if (history_valid(h->history_ID, history_ID))
        {
            b->text_length = h->text_length;
            b->allocated_length = h->allocated_length;
        #if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
            if (GetMessagesCurrScrnID() != SCR_ID_MSG_WRITE)
            {
                b->available_length = h->available_length;
            }
        #else /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 
            b->available_length = h->available_length;
        #endif /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 
            b->n_lines = h->n_lines;
            b->text_height = h->text_height;
            b->text_offset_x = h->text_offset_x;
            b->text_offset_y = h->text_offset_y;
            if (b->text_offset_y > 0)
            {
                b->text_offset_y = 0;
            }
            b->cursor_x = h->cursor_x;
            b->cursor_y = h->cursor_y;
            b->cursor_line_position_counter = h->cursor_line_position_counter;
            b->line_before_cursor_line_p =
                (UI_buffer_type) (b->text + h->line_before_cursor_line_p);
            b->cursor_line_p = (UI_buffer_type) (b->text + h->cursor_line_p);
            b->cursor_p = (UI_buffer_type) (b->text + h->cursor_p);
            b->line_after_cursor_line_p =
                (UI_buffer_type) (b->text + h->line_after_cursor_line_p);
            b->line_after_cursor_line_last_p =
                (UI_buffer_type) (b->text + h->line_after_cursor_line_last_p);
            b->last_position_p =
                (UI_buffer_type) (b->text + h->last_position_p);
            b->UCS2_count = h->UCS2_count;
            b->pre_scrollbar_state = h->pre_scrollbar_state;
            b->pre_height = h->pre_height;

            b->flags = h->flags;
            b->ext_flags=h->ext_flags;
            b->editor_changed = (S32)h->changed;
            if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_INPUT_METHOD_MODE
            && mmi_imc_is_multitap_state(h->ime_history.state))
            {
                b->input_mode_cursor_p = (UI_buffer_type) (b->text + h->input_mode_cursor_p);
                b->input_start_cursor_p = (UI_buffer_type) (b->text + h->input_mode_start_p);
            }
            
        #ifdef __MMI_CLIPBOARD__
            if (b->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE)
            {
                /* Should not show cursor if editor is view mode. The cursor maybe shown for selecting text */
                b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
            }
        #endif

             /* barcode */
            b->current_hilite_idx = h->current_hilite_idx;
            b->curr_hilite_text_offset_y = h->curr_hilite_text_offset_y;
            b->hilite_list = h->hilite_list;
            b->hilite_cb = h->hilite_cb;
            b->last_cursor_offset = h->last_cursor_offset;
        #ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
            if (h->ext_flags & GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE)
            {
                memcpy(b->text,shared_data, h->previous_shared_bytes);
                b->start_id = h->start_page_id;
                b->end_id = h->end_page_id;
                b->text_offset = h->text_offset;
          
                ASSERT(b->get_page_cb);
                b->get_page_cb(
                    b->start_id,
                    b->end_id,
                    b->text + h->previous_shared_bytes);

            }
        #endif /* __UI_PAGING_IN_MULTILINE_EDITOR__ */ 
			
            /* fix issue
               make sure that text length in history wont be shorter than the real text app pass
               cut the text */
#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)    
            if (b->flags & UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE)
            {
                if (!(b->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE) && !(b->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW)
                    && (mmi_ucs2strlen(b->text) + 1) * ENCODING_LENGTH > h->text_length)
                {
                    b->text[b->text_length - 2] = '\0';
                    b->text[b->text_length - 1] = 0;
                }
            }
#endif
            return (1);
        }
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_set_category_history
 * DESCRIPTION
 *  Sets the history data for the multiline inputbox from the given history buffer
 * PARAMETERS
 *  history_ID          [IN]        Is the ID used by category screens
 *  history_buffer      [IN]        Is the buffer from which history data is taken
 *  input_type          [?]         
 * RETURNS
 *  Returns true if the history ID is valid
 *****************************************************************************/
U8 wgui_inputs_ml_set_category_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    return wgui_inputs_ml_set_category_history_ext(&MMI_multiline_inputbox, history_ID, history_buffer);
}

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_get_category_history_ext
 * DESCRIPTION
 *  Gets the history data for the multiline inputbox and stores into the given history buffer
 * PARAMETERS
 *  history_ID          [IN]        Is the ID used by category screens
 *  history_buffer      [IN]        Is the buffer from which history data is taken
 *  input_type          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_get_category_history_ext(multi_line_input_box *b, U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        U32 tmp_flags;  
        S8 i;

        U16 hID = (U16) (history_ID | 0x8000);
        multiline_inputbox_category_history *h = (multiline_inputbox_category_history*) history_buffer;
        wgui_multiline_history_buffer = history_buffer;
        wgui_multiline_history_ID = (S16)history_ID;

        h->history_ID = hID;
        h->text_length = (S16) b->text_length;
        h->allocated_length = (S16) b->allocated_length;
        h->available_length = (S16) b->available_length;
        h->n_lines = (S16) b->n_lines;
        h->text_height = (S16) b->text_height;
        h->text_offset_x = (S16) b->text_offset_x;
        h->text_offset_y = (S16) b->text_offset_y;
        h->cursor_x = (S16) b->cursor_x;
        h->cursor_y = (S16) b->cursor_y;
        h->cursor_line_position_counter = (S16) b->cursor_line_position_counter;
        h->line_before_cursor_line_p =
            (S16) (b->line_before_cursor_line_p - b->text);
        h->cursor_line_p = (S16) (b->cursor_line_p - b->text);
        h->cursor_p = (S16) (b->cursor_p - b->text);
        h->line_after_cursor_line_p =
            (S16) (b->line_after_cursor_line_p - b->text);
        h->line_after_cursor_line_last_p =
            (S16) (b->line_after_cursor_line_last_p - b->text);
        h->last_position_p = (S16) (b->last_position_p - b->text);
        h->changed = (U8)b->editor_changed;
        h->pre_scrollbar_state = b->scrollbar_state;
        h->pre_height = b->height;
        mmi_imc_get_input_method_history(&(h->ime_history));
        
        /* barcode */
        h->current_hilite_idx = b->current_hilite_idx;
        h->curr_hilite_text_offset_y = b->curr_hilite_text_offset_y;
        h->hilite_list = b->hilite_list;
        h->hilite_cb = b->hilite_cb;
        h->ext_flags = (U32)b->ext_flags;
        h->last_cursor_offset = b->last_cursor_offset;
        if (mmi_imc_is_multitap_state(h->ime_history.state))
        {
            if (b->input_mode_cursor_p < b->text)
                b->input_mode_cursor_p = b->cursor_p;

            if (b->input_start_cursor_p < b->text)
                b->input_start_cursor_p = b->cursor_p;

            h->input_mode_cursor_p = (S16) (b->input_mode_cursor_p - b->text);
            h->input_mode_start_p = (S16) (b->input_start_cursor_p - b->text);
            h->ext_flags |= GUI_MULTI_LINE_INPUT_BOX_INPUT_METHOD_MODE;
        }
        else
            h->ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_INPUT_METHOD_MODE;

    #ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
        if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE)
        {
            h->start_page_id = b->start_id;
            h->end_page_id = b->end_id;
            h->previous_shared_bytes = b->previous_shared_bytes;
            h->text_offset = b->text_offset;
            memset(shared_data,0,sizeof(shared_data));
            memcpy((void *)shared_data, (void*)b->text, h->previous_shared_bytes);
        }
    #endif /* __UI_PAGING_IN_MULTILINE_EDITOR__ */ 
        /* modified to ensure 4 byte alignment */

    #ifdef __MMI_CLIPBOARD__
        if (mmi_imc_is_connected()
            && g_mmi_editor_hanler.input_box_type == MMI_EDITOR_MULTILINE_INPUT_BOX
            && mmi_imc_clipboard_is_editor_read_only())
        {
            b->flags |= UI_MULTI_LINE_INPUT_BOX_VIEW_MODE;
        }
    #endif

        tmp_flags = b->flags;
        /* to disable multitap flag 20040712 to disable highlight flag */
        tmp_flags &= ~UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP;
        
        if (b->hilite_cb == NULL)
        {
        tmp_flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        }

        for (i = 0; i < sizeof(U32); i++)
        {
            memcpy((U8*) (&h->flags) + i, (U8*) (&tmp_flags) + i, 1);
        }

        h->UCS2_count = (S16) b->UCS2_count;
    #if defined(__MMI_VIRTUAL_KEYBOARD__)
        /* W05.41 Do not Strore Virtual Keyboard into History when View Mode */
        if (b->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE)
        {
            h->ime_history.vk_type = GUI_VIRTUAL_KEYBOARD_EMPTY_TRAY;
        }

    #endif /* defined(__MMI_VIRTUAL_KEYBOARD__) */ 

        h->state = (S8) - 1;    /* MTK 2004-02-13 Wilson, Initialize history buffer state */
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_get_category_history
 * DESCRIPTION
 *  Gets the history data for the multiline inputbox and stores into the given history buffer
 * PARAMETERS
 *  history_ID          [IN]        Is the ID used by category screens
 *  history_buffer      [IN]        Is the buffer from which history data is taken
 *  input_type          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_get_category_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_ml_get_category_history_ext(&MMI_multiline_inputbox, history_ID, history_buffer);
}

/* Set and Get state of multiine inputbox history buffer */


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_set_category_history_state
 * DESCRIPTION
 *  Sets the state of history data for state list
 * PARAMETERS
 *  history_ID          [IN]        Is the ID used by category screens
 *  history_buffer      [IN]        Is the buffer into which history data is written
 *  state               [IN]        Is the state to be set to state list
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_set_category_history_state(U16 history_ID, U8 *history_buffer, S8 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        multiline_inputbox_category_history *h = (multiline_inputbox_category_history*) history_buffer;

        h->state = state;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_get_category_history_state
 * DESCRIPTION
 *  Gets the state of history data for state list
 * PARAMETERS
 *  history_ID          [IN]        Is the ID used by category screens
 *  history_buffer      [IN]        Is the buffer into which history data is written
 *  state(?)            [IN]        Is the state to be set to state list
 * RETURNS
 *  void
 *****************************************************************************/
S8 wgui_inputs_ml_get_category_history_state(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        multiline_inputbox_category_history *h = (multiline_inputbox_category_history*) history_buffer;

        return h->state;
    }
    return (S8) - 1;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_redraw_remaining_characters_display_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_redraw_remaining_characters_display_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifndef __MMI_HIDE_MUL_REMAINING_CHAR__

    color c;

    /* for BW_MMI display */
#ifdef __BW_MMI__
    S32 x1 = UI_device_width - 21;
    S32 y1 = 2;
    S32 x2 = UI_device_width - 1;
    S32 y2 = (MMI_title_y + MMI_title_height) - 2;
#else /* __BW_MMI__ */ 
    /* for R2L characters */
    S32 x1;
    S32 x2;
    S32 y1 = wgui_inputbox_information_bar_y;
    S32 y2 = wgui_inputbox_information_bar_y + wgui_inputbox_information_bar_height - 1;

#endif /* __BW_MMI__ */ 

#if !defined(__MMI_TOUCH_SCREEN__)
    stFontAttribute *f = &MMI_small_font;
#else /* !defined(__MMI_TOUCH_SCREEN__) */ 
    stFontAttribute *f = &MMI_medium_font;
#endif /* !defined(__MMI_TOUCH_SCREEN__) */
    S32 w, h, n, max_n;
    UI_character_type str[32];

    /* for 0x81 encoding support for Phone Book */
    U32 temp_0x81 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    /* Warning: Temporary change only UCS2 / ASCII. This has to be done in a more formal manner  */
    n = (MMI_multiline_inputbox.text_length >> 1) - 1;
    max_n = (MMI_multiline_inputbox.available_length >> 1) - 1;
    if ((MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_CHECK_GSM_EXTENDED) &&
        (MMI_multiline_inputbox.UCS2_count == 0))
    {
        n += MMI_multiline_inputbox.GSM_ext_count;
    }
    if ((MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_PLUS_CHARACTER_HANDLING) &&
        (MMI_multiline_inputbox.text[0] == '+'))
    {
        n--;
        max_n--;
    }
    if (MMI_current_input_ext_type & INPUT_TYPE_EXT_USE_0x81_ENCODING)
    {
        temp_0x81 = srv_phb_convert_to_0x81((U16*) MMI_multiline_inputbox.text, MMI_FALSE);
        if (0 != temp_0x81)
        {
            max_n = (MMI_multiline_inputbox.allocated_length >> 1) - 4;
            n = temp_0x81 - 3;
        }
    }

    gui_set_font(f);

    if (max_n > 999)
    {
        gui_sprintf(str, "%d/%d", max_n, max_n);
    }
    else
    {
        gui_sprintf(str, "%d/%d", 999, 999);
    }

    gui_measure_string(str, &w, &h);

    if (!mmi_fe_get_r2l_state())
    {
        x2 = wgui_inputbox_information_bar_x + wgui_inputbox_information_bar_width - 1;
        x1 = x2 - w - 1;
    }
    else
    {
        x1 = wgui_inputbox_information_bar_x;
        x2 = wgui_inputbox_information_bar_x + w + 1;
        
    }
    
    if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INCLUDE_INFO_AREA))
    {
        wgui_inputs_input_information_background(x1, y1, x2, y2);
    }
	gui_push_clip();
    gui_reset_text_clip();
    gui_sprintf(str, "%d/%d", n, max_n);
    c = *current_MMI_theme->remaining_length_text_color;
    gui_set_font(f);
    gui_set_text_color(c);
    gui_set_text_clip(0, 0, UI_device_width - 1, UI_device_height - 1);

    gui_measure_string(str, &w, &h);

    if (!mmi_fe_get_r2l_state())
    {
        gui_move_text_cursor(x2 - 1 - w, y1 + (wgui_inputbox_information_bar_height - h) / 2);
    }
    else
    {
        gui_move_text_cursor(x1 + 1 + w, y1 + (wgui_inputbox_information_bar_height - h) / 2);
    }

    gui_print_text(str);
	gui_pop_clip();
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 

#endif /* __MMI_HIDE_MUL_REMAINING_CHAR__ */ 
}


#ifdef __OP01_FWPBW__

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_redraw_remaining_characters_display
 * DESCRIPTION
 *  wgui_inputs_ml_redraw_remaining_characters_display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_redraw_remaining_characters_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 n, max_n;
    U8 temp_0x81 = 0;
    S32 csk_x, csk_y, csk_width, csk_height;
    S32 text_x, text_y;
    S32 str_width, str_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    n = (MMI_multiline_inputbox.text_length >> 1) - 1;
    max_n = (MMI_multiline_inputbox.available_length >> 1) - 1;
    if ((MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_CHECK_GSM_EXTENDED) &&
        (MMI_multiline_inputbox.UCS2_count == 0))
    {
        n += MMI_multiline_inputbox.GSM_ext_count;
    }
    if ((MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_PLUS_CHARACTER_HANDLING) &&
        (MMI_multiline_inputbox.text[0] == '+'))
    {
        n--;
        max_n--;
    }
    if (MMI_current_input_ext_type & INPUT_TYPE_EXT_USE_0x81_ENCODING)
    {
        temp_0x81 = srv_phb_convert_to_0x81((U16*) MMI_multiline_inputbox.text, FALSE);
        if (0 != temp_0x81)
        {
            max_n = (MMI_multiline_inputbox.allocated_length >> 1) - 4;
            n = temp_0x81 - 3;
        }
    }

    g_wgui_inputs_remaining_characters_str[0] = 0;
    gui_sprintf(g_wgui_inputs_remaining_characters_str, "%d/%d", n, max_n);

    // show remaining counter on csk
    wgui_softkey_get_position(MMI_CENTER_SOFTKEY, &csk_x, &csk_y);
    wgui_softkey_get_dimension(MMI_CENTER_SOFTKEY, &csk_width, &csk_height);
    gui_push_clip();
    gui_set_clip(csk_x, csk_y, csk_x + csk_width - 1, csk_y + csk_height - 1);
    // clear background
    gui_fill_rectangle(csk_x, csk_y, csk_x + csk_width - 1, csk_y + csk_height - 1, gui_color(255, 255, 255));

    // show text
    gui_set_font(&MMI_small_font);
    gui_measure_string(g_wgui_inputs_remaining_characters_str, &str_width, &str_height);
    str_width = str_width + 2; /* 2 is border width */
    text_x = csk_x + ((csk_width - str_width)>>1);
    text_y = csk_y + ((csk_height - str_height)>>1);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_move_text_cursor(text_x, text_y);
    gui_print_text(g_wgui_inputs_remaining_characters_str);
    gui_pop_clip();

    // start time to display the input method
    gui_start_timer(1000, wgui_inputs_show_current_input_method_timer_handler);

    gui_BLT_double_buffer(csk_x, csk_y, csk_x + csk_width - 1, csk_y + csk_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_redraw_input_information_bar
 * DESCRIPTION
 *  redrwa input information bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_redraw_input_information_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_ml_redraw_remaining_characters_display();
}

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
/* under construction !*/
/* under construction !*/
#if defined(__ATV_SMS_SUPPORT__)
#if(UI_DOUBLE_BUFFER_SUPPORT)
/* under construction !*/
#endif
#endif
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
            #if defined(__ATV_SMS_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
            #if defined(__ATV_SMS_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_FTE_SUPPORT__
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
/* under construction !*/
/* under construction !*/
#ifdef __MMI_FTE_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__ATV_SMS_SUPPORT__)
#if(UI_DOUBLE_BUFFER_SUPPORT)
/* under construction !*/
/* under construction !*/
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
#endif
/* under construction !*/
#endif 

#else

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_redraw_remaining_characters_display
 * DESCRIPTION
 *  wgui_inputs_ml_redraw_remaining_characters_display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_redraw_remaining_characters_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_multiline_inputbox.infobar_reminder_char_callback==NULL)
        wgui_inputs_ml_redraw_remaining_characters_display_internal();
    else
    {
        S32 x1 = wgui_inputbox_information_bar_x;
        S32 y1 = wgui_inputbox_information_bar_y;
        S32 x2 = wgui_inputbox_information_bar_x + wgui_inputbox_information_bar_width - 1;
        S32 y2 = wgui_inputbox_information_bar_y + wgui_inputbox_information_bar_height - 1;

        MMI_multiline_inputbox.infobar_reminder_char_callback(x1,y1,x2,y2);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_redraw_input_information_bar
 * DESCRIPTION
 *  redrwa input information bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_redraw_input_information_bar(void)
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
#ifdef __MMI_CLIPBOARD__
    if (mmi_imc_is_connected()
        && g_mmi_editor_hanler.input_box_type == MMI_EDITOR_MULTILINE_INPUT_BOX
        && mmi_imc_clipboard_is_editor_read_only())
    {
        return;
    }
#endif

    gui_lock_double_buffer();
    if(MMI_multiline_inputbox.infobar_redraw_callback)
    {
       MMI_multiline_inputbox.infobar_redraw_callback(x1,y1,x2,y2); 
    }
    else
    {
        #if(!((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING)))
        if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INCLUDE_INFO_AREA) || redraw_on_input_method_change)
        #endif
            wgui_inputs_input_information_background(x1, y1, x2, y2);
        wgui_inputs_ml_show_current_input_method(x1,y1,x2,y2);
        wgui_inputs_ml_redraw_remaining_characters_display();
    }
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
}

#endif


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_show_current_input_method
 * DESCRIPTION
 *  wgui_inputs_ml_show_current_input_method
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_show_current_input_method(S32 x1,S32 y1,S32 x2,S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	wgui_inputs_show_input_mode_internal(
            x1,
            y1,
            x2-x1+1,
            y2-y1+1,
            mmi_imm_get_curr_input_mode(), NULL);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_handle_right_softkey_down
 * DESCRIPTION
 *  handle RSK down key of input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_handle_right_softkey_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gui_multi_line_input_box_get_text_length(&MMI_multiline_inputbox) > 0)
    {
        if (g_wgui_inputs_ml_pre_delete_handler)
        {
            g_wgui_inputs_ml_pre_delete_handler();
        }
        wgui_inputs_ml_delete_character();

    #if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
        if ((MMI_multiline_inputbox.flags & UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE) 
            || MMI_multiline_inputbox.predefine_char_pos != NULL)
        {
            set_right_softkey_function(wgui_inputs_ml_handle_right_softkey_long_press, KEY_LONG_PRESS);
        }
    #endif
    }
    else
    {        
        UI_editor_play_tone_cannot_change();
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_handle_right_softkey_up
 * DESCRIPTION
 *  handle RSK up  key of input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_handle_right_softkey_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_inputbox_RSK_function != NULL)
    {
        wgui_inputbox_RSK_function();
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
 *  wgui_inputs_ml_register_handle_right_softkey_up
 * DESCRIPTION
 *  register RSK function handler of input box key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_register_handle_right_softkey_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_right_softkey_function(wgui_inputs_ml_handle_right_softkey_up, KEY_EVENT_UP);
}



/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_handle_right_softkey_long_press
 * DESCRIPTION
 *  handle right soft key long press of multiline input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_handle_right_softkey_long_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wgui_inputs_is_clear_key_delete_all)
    {
        wgui_inputs_ml_delete_all_characters();
    }
    else
    {
        if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
        {
            g_wgui_inputs_repeat_count = 0;
            SetKeyHandler(wgui_inputs_ml_handle_right_softkey_repeat, KEY_CLEAR, KEY_REPEAT);
        }
        else
        {
            g_wgui_inputs_repeat_count = 0;
            set_right_softkey_function(wgui_inputs_ml_handle_right_softkey_touch_repeat, KEY_REPEAT);
            SetKeyHandler(wgui_inputs_ml_handle_right_softkey_repeat, KEY_RSK, KEY_REPEAT);
        }
    }

#ifdef __MMI_CAT203_SUPPORT__
    if (g_wgui_cat203_search_function)
    {
        wgui_cat203_refresh_search_list(MMI_multiline_inputbox.text);
    }
#endif /* __MMI_CAT203_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_handle_input
 * DESCRIPTION
 *  handle input box input
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inputs_ml_handle_input_int(S32 show_counter_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__ATV_SMS_SUPPORT__)
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif
#endif
    if (gui_multi_line_input_box_get_text_length(&MMI_multiline_inputbox) > 0)
    {
        if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
        {
            if (wgui_inputbox_RSK_label_clear == 0)
            {
                if (wgui_inputbox_not_empty_callback != NULL && !mmi_imc_is_ime_state())
                {
                    wgui_inputbox_not_empty_callback();
                }
                wgui_inputbox_RSK_label_clear = 1;
                SetKeyHandler(wgui_inputs_ml_handle_right_softkey_down, KEY_CLEAR, KEY_EVENT_DOWN);
                SetKeyHandler(UI_dummy_function, KEY_CLEAR, KEY_EVENT_UP);
                SetKeyHandler(wgui_inputs_ml_handle_right_softkey_long_press, KEY_CLEAR, KEY_EVENT_LONG_PRESS);

            }
        }
        else
        {
            if (wgui_inputbox_RSK_label_clear == 0)
            {
                set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_CLEAR));
                set_right_softkey_icon(NULL);
                if (wgui_inputbox_not_empty_callback != NULL && !mmi_imc_is_ime_state())
                {
                    wgui_inputbox_not_empty_callback();
                }
                redraw_right_softkey();
                register_right_softkey_handler();
            #if defined(__ATV_SMS_SUPPORT__)
                redraw_left_softkey();
                register_left_softkey_handler();
                redraw_center_softkey();
                register_softkey_handler(MMI_CENTER_SOFTKEY);
            #endif
                wgui_inputbox_RSK_label_clear = 1;
                set_right_softkey_function(NULL, KEY_EVENT_UP);
                set_right_softkey_function(wgui_inputs_ml_handle_right_softkey_down, KEY_EVENT_DOWN);
                set_right_softkey_function(wgui_inputs_ml_handle_right_softkey_long_press, KEY_EVENT_LONG_PRESS);
            }
        }
    }
    else
    {
        if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
        {
            if (wgui_inputbox_RSK_label_clear == 1)
            {

                wgui_inputbox_RSK_label_clear = 0;
                if (wgui_inputbox_empty_callback != NULL && !mmi_imc_is_ime_state())
                {
                    wgui_inputbox_empty_callback();
                }
                SetKeyHandler(wgui_inputs_ml_handle_right_softkey_down, KEY_CLEAR, KEY_EVENT_DOWN);
                SetKeyHandler(UI_dummy_function, KEY_CLEAR, KEY_EVENT_UP);
                SetKeyHandler(UI_dummy_function, KEY_CLEAR, KEY_EVENT_LONG_PRESS);

            }
        }
        else
        {
            if (wgui_inputbox_RSK_label_clear == 1)
            {
                set_right_softkey_label(wgui_inputbox_RSK_label_string);
                set_right_softkey_icon(wgui_inputbox_RSK_label_icon);
                if (wgui_inputbox_empty_callback != NULL && !mmi_imc_is_ime_state())
                {
                    wgui_inputbox_empty_callback();
                }
                redraw_right_softkey();
                register_right_softkey_handler();
                wgui_inputbox_RSK_label_clear = 0;
                set_right_softkey_function(wgui_inputs_ml_register_handle_right_softkey_up, KEY_EVENT_DOWN);
            }
            else
            {
                set_right_softkey_label(wgui_inputbox_RSK_label_string);
                set_right_softkey_icon(wgui_inputbox_RSK_label_icon);
                if (wgui_inputbox_empty_callback != NULL && !mmi_imc_is_ime_state())
                {
                    wgui_inputbox_empty_callback();
                }
                redraw_right_softkey();
            }
            #if defined(__ATV_SMS_SUPPORT__)
                redraw_left_softkey();
                register_left_softkey_handler();
                redraw_center_softkey();
                register_softkey_handler(MMI_CENTER_SOFTKEY);
            #endif
        }
    }

    if (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_PLUS_CHARACTER_HANDLING)
    {

#ifdef __MMI_FTE_SUPPORT__
        S32 length = MMI_multiline_inputbox.available_length;
#endif

        if (MMI_multiline_inputbox.text[0] == '+')
        {
            MMI_multiline_inputbox.available_length = (wgui_inputbox_buffer_size + 1) * ENCODING_LENGTH;
        }
        else
        {
            MMI_multiline_inputbox.available_length = wgui_inputbox_buffer_size * ENCODING_LENGTH;
        }

#ifdef __MMI_FTE_SUPPORT__
        if (length != MMI_multiline_inputbox.available_length)
        {
            wgui_inputs_ml_redraw();
        }
#endif

    }
    if (wgui_inputbox_information_flag)
    {
        if (show_counter_flag) /* slim_2_2 */ //
        {
            wgui_inputs_ml_redraw_remaining_characters_display();
        }
#ifdef __OP01_FWPBW__
        else
        {
            wgui_inputs_show_current_input_method_timer_handler();
        }
#endif
    }
    
#if defined(__ATV_SMS_SUPPORT__)
#if(UI_DOUBLE_BUFFER_SUPPORT)
        gui_unlock_double_buffer();
        gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
#endif
    
    }

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_handle_input
 * DESCRIPTION
 *  handle input box input
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_handle_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_ml_handle_input_int(1);
    #if 0/* slim_2_2 */ // 
/* under construction !*/
#if defined(__ATV_SMS_SUPPORT__)
#if(UI_DOUBLE_BUFFER_SUPPORT)
/* under construction !*/
#endif
#endif
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
            #if defined(__ATV_SMS_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
            #if defined(__ATV_SMS_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_FTE_SUPPORT__
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
/* under construction !*/
/* under construction !*/
#ifdef __MMI_FTE_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__ATV_SMS_SUPPORT__)
#if(UI_DOUBLE_BUFFER_SUPPORT)
/* under construction !*/
/* under construction !*/
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
#endif
#endif /* slim_2_2 */ //

}



/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_handle_navigate
 * DESCRIPTION
 *  handle input box navigation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_handle_navigate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gui_multi_line_input_box_test_first_position(&MMI_multiline_inputbox))
    {
        if (wgui_inputbox_RSK_label_clear == 1)
        {
            set_right_softkey_label(wgui_inputbox_RSK_label_string);
            set_right_softkey_icon(wgui_inputbox_RSK_label_icon);
            redraw_right_softkey();
            wgui_inputbox_RSK_label_clear = 0;
            set_right_softkey_function(wgui_inputs_ml_handle_right_softkey_up, KEY_EVENT_UP);
            set_right_softkey_function(UI_dummy_function, KEY_EVENT_DOWN);
        }
    }
    else
    {
        if (wgui_inputbox_RSK_label_clear == 0)
        {
            set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_CLEAR));
            set_right_softkey_icon(NULL);
            redraw_right_softkey();
            wgui_inputbox_RSK_label_clear = 1;
            set_right_softkey_function(UI_dummy_function, KEY_EVENT_UP);
            set_right_softkey_function(wgui_inputs_ml_handle_right_softkey_down, KEY_EVENT_DOWN);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_change_information_bar_input_method
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_change_information_bar_input_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    redraw_on_input_method_change = 1;
    /* Check the flag before redrawing the info bar */
    if (wgui_inputbox_information_flag)
    {
        wgui_inputs_ml_redraw_input_information_bar();
    }
    else
    {
        mmi_imc_redraw_ime_indicator();
    }

    redraw_on_input_method_change = 0;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_show_with_information_bar
 * DESCRIPTION
 *  show input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_show_with_information_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
#ifndef __OP01_FWPBW__
    if (wgui_inputbox_information_flag)
    {
        wgui_inputs_ml_redraw_input_information_bar();
    }
#endif
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
#endif 
    wgui_inputs_ml_show();

#ifdef __OP01_FWPBW__
    // the information bar is show on CSK
    redraw_softkey(MMI_CENTER_SOFTKEY);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_hide_text_content
 * DESCRIPTION
 *  hide/show multi-line input box content
 * PARAMETERS
 *  hide      [IN]  MMI_TRUE -> hide the content ; MMI_FALSE -> show the content (normal)       
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_hide_text_content(MMI_BOOL hide)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(hide == MMI_TRUE)
    {
        MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT;
    }
    else
    {
        MMI_multiline_inputbox.ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_validation_callback
 * DESCRIPTION
 *  multiline input boxvalidation call back
 * PARAMETERS
 *  text            [IN]        Text of input box
 *  cursor          [IN]        
 *  text_length     [IN]        Text length
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_validation_callback(UI_buffer_type text, UI_buffer_type cursor, S32 text_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_inputbox_validation_callback != NULL && mmi_imc_is_ime_state() == MMI_FALSE)
    {
        wgui_inputbox_validation_callback(text, cursor, text_length);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_get_ucs2_count
 * DESCRIPTION
 *  Return UCS2 count of multiline input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 wgui_inputs_ml_get_ucs2_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_multiline_inputbox.UCS2_count);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_get_ext_gsm_count
 * DESCRIPTION
 *  Returns the number of GSM extended characters in the
 *  multiline input box buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  The number of extended characters
 *****************************************************************************/
S32 wgui_inputs_ml_get_ext_gsm_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_multiline_inputbox.GSM_ext_count);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_test_change_input_mode
 * DESCRIPTION
 *  test the input mode of input box
 * PARAMETERS
 *  void
 * RETURNS
 *  byte
 *****************************************************************************/
U8 wgui_inputs_ml_test_change_input_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
    {
        if (MMI_multiline_inputbox.UCS2_count <= 0)
        {
                if ((MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_ONE_LESS_CHARACTER) &&
                    (MMI_multiline_inputbox.text_length + MMI_multiline_inputbox.GSM_ext_count * ENCODING_LENGTH
                    >= (MMI_multiline_inputbox.available_length>>1)-1))
                {
                    return (0);
                }
                else if (MMI_multiline_inputbox.text_length + MMI_multiline_inputbox.GSM_ext_count * ENCODING_LENGTH
                    >= (MMI_multiline_inputbox.available_length >> 1))
                {
                    return (0);
                }
                else
                {
                    return (1);
                }
        }
        else
        {
            return (1);
        }
    }
    else
    {
        return (1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_setup_ext
 * DESCRIPTION
 *  set teh input box
 * PARAMETERS
 *  x                           [IN]        Start x postition of inputr box
 *  y                           [IN]        Strar y position of input box
 *  width                       [IN]        Width of input box
 *  height                      [IN]        Height of input boxc
 *  buffer                      [IN]        Buffer of input box
 *  buffer_size                 [IN]        
 *  category_screen_ID          [IN]        Category screen id
 *  RSK_label                   [IN]        RSK label
 *  RSK_icon                    [IN]        RSK icon
 *  input_type                  [IN]        
 *  history_buffer              [IN]        History buffer
 *  information_bar_flag        [IN]        Information flag
 *  additional_flags            [IN]        Additional inputbox flags
 *  min_text_height             [IN]        Minimum text height
 *  min_line_height             [IN]        Minimum text height
 *  header_height               [IN]        Editor header height
 *  footer_height               [IN]        Editor footer height
 *  icon_callback               [IN]        
 *  input(?)                    [IN]        Type
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_setup_ext(
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
        mmi_imm_input_mode_enum *input_mode_array,
        U8 information_bar_flag,
        U32 additional_flags,
        S16 min_text_height,
        S16 min_line_height,
        S16 header_height,
        S16 footer_height,
        multi_line_input_box_icon_hdlr icon_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_ml_setup_ext2(
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
        input_mode_array,
        information_bar_flag,
        additional_flags,
        min_text_height,
        min_line_height,
        header_height,
        footer_height,
        icon_callback,
        mmi_input_box_msg_call_back_multiline,
        MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_setup_ext2
 * DESCRIPTION
 *  set teh input box
 * PARAMETERS
 *  x                           [IN]        Start x postition of inputr box
 *  y                           [IN]        Strar y position of input box
 *  width                       [IN]        Width of input box
 *  height                      [IN]        Height of input boxc
 *  buffer                      [IN]        Buffer of input box
 *  buffer_size                 [IN]        
 *  category_screen_ID          [IN]        Category screen id
 *  RSK_label                   [IN]        RSK label
 *  RSK_icon                    [IN]        RSK icon
 *  input_type                  [IN]        
 *  history_buffer              [IN]        History buffer
 *  information_bar_flag        [IN]        Information flag
 *  additional_flags            [IN]        Additional inputbox flags
 *  min_text_height             [IN]        Minimum text height
 *  min_line_height             [IN]        Minimum text height
 *  header_height               [IN]        Editor header height
 *  footer_height               [IN]        Editor footer height
 *  icon_callback               [IN]        
 *  input(?)                    [IN]        Type
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_setup_ext2(
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
        mmi_imm_input_mode_enum *input_mode_array,
        U8 information_bar_flag,
        U32 additional_flags,
        S16 min_text_height,
        S16 min_line_height,
        S16 header_height,
        S16 footer_height,
        multi_line_input_box_icon_hdlr icon_callback,
        U32 (*msg_call_back) (void * input_box_handle, mmi_imc_message_struct_p msg_ptr),
        MMI_BOOL connect_ime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 l, h, fh;
    U32 input_type_flags = input_type & (~INPUT_TYPE_MASK);
    U32 saved_inputbox_flags;
    U8 plus_character_handling = 0;
    UI_buffer_type t;
    UI_character_type c;
    U8 is_valid_history;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_INDIC_ALG__)
	/*set up required in indic engine when multi-line editor is launched*/
	ire_set_use_multitap_multi_line();
#endif /* defined(__MMI_INDIC_ALG__) */

    UI_UNUSED_PARAMETER(width);
    /* W05.36 Fix Vietnamese Tone Input Issue */
    wgui_inputs_set_current_input_box_type(EDITOR_MULTILINE_INPUT_BOX);
    /* to add the T9 max length limitation */

    /* for wgui_set_default_input_type */
    wgui_inputbox_buffer_size = buffer_size;
    if (input_type & INPUT_TYPE_PLUS_CHARACTER_HANDLING)
    {
        plus_character_handling = 1;
    }

    /* Buffer maybe not two bytes align, we have to take this in to consideration */
    l = gui_strlen((UI_string_type) buffer);
    t = (UI_buffer_type)buffer;
    UI_STRING_GET_NEXT_CHARACTER(t, c);
    if ((l >= buffer_size) && !(input_type & INPUT_TYPE_PLUS_CHARACTER_HANDLING))
    {
        l = buffer_size - 1;
        t = (UI_buffer_type)buffer + l * ENCODING_LENGTH;
        UI_STRING_INSERT_CHARACTER(t, 0);
        t = (UI_buffer_type)buffer + l * ENCODING_LENGTH;
        UI_STRING_GET_NEXT_CHARACTER(t, c);
        MMI_ASSERT(c == 0);   /* cann't support large buffer on ROM */
    }
    else if ((input_type & INPUT_TYPE_PLUS_CHARACTER_HANDLING) && (c == '+') && (l > buffer_size))
    {
        l = buffer_size;
        t = (UI_buffer_type)buffer + l * ENCODING_LENGTH;
        UI_STRING_INSERT_CHARACTER(t, 0);
        t = (UI_buffer_type)buffer + l * ENCODING_LENGTH;
        UI_STRING_GET_NEXT_CHARACTER(t, c);
        MMI_ASSERT(c == 0);   /* cann't support large buffer on ROM */
    }

    wgui_inputs_ml_create_set_buffer((UI_string_type) buffer, buffer_size, l, l);
    if (information_bar_flag)
        wgui_inputbox_information_flag = 1;
    MMI_multiline_inputbox.flags |= additional_flags;
    MMI_multiline_inputbox.min_text_height = min_text_height;
    MMI_multiline_inputbox.min_line_height = min_line_height;
    MMI_multiline_inputbox.header_height = header_height;
    MMI_multiline_inputbox.footer_height = footer_height;
    MMI_multiline_inputbox.icon_callback = icon_callback;
    wgui_inputbox_RSK_label_icon = RSK_icon;
    wgui_inputbox_RSK_label_string = RSK_label;

    wgui_inputs_ml_register_keys();
    if (wgui_inputbox_information_flag)
    {
    #ifndef __OP01_FWPBW__
        #ifdef __BW_MMI__
            wgui_inputs_ml_move(x, y);
            h = height;
        #else /* __BW_MMI__ */ 
            wgui_inputs_ml_move(x, y + wgui_inputbox_information_bar_height);
            h = height - wgui_inputbox_information_bar_height;
        #endif /* __BW_MMI__ */ 
    #else
        wgui_inputs_ml_move(x, y);
        h = height;
    #endif
    }
    else
    {
        wgui_inputs_ml_move(x, y);
        h = height;
    }

    gui_set_font(MMI_multiline_inputbox.text_font);
    fh = gui_get_character_height();

    wgui_inputs_ml_resize(width, h); /* it should use user defined width */

    if (wgui_inputbox_information_flag)
    {
    #ifndef __OP01_FWPBW__
#ifdef __MMI_SMALL_EDIT_SCREEN__
        if (wgui_small_editor_information_flag && whether_no_small_screen())
        {
            wgui_inputs_setup_input_information(
                MMI_multiline_inputbox.x + 1,
                MMI_multiline_inputbox.y - wgui_inputbox_information_bar_height,
                MMI_multiline_inputbox.width - 2,
                wgui_inputbox_information_bar_height);
        }
        else
#endif /* __MMI_SMALL_EDIT_SCREEN__ */ 
            wgui_inputs_setup_input_information(
            MMI_multiline_inputbox.x,
            MMI_multiline_inputbox.y - wgui_inputbox_information_bar_height,
            MMI_multiline_inputbox.width,
            wgui_inputbox_information_bar_height);
    #else
        wgui_inputs_setup_input_information(0, 0, 0, 0);
    #endif
    }
    
    is_valid_history = wgui_inputs_ml_set_category_history(category_screen_ID, history_buffer);

    /* app might not close multiline to clear this two variables when exit screen, so reset them when setup*/
    wgui_multiline_history_buffer = NULL;
    wgui_multiline_history_ID = (S16)-1;

    saved_inputbox_flags = MMI_multiline_inputbox.flags;

    wgui_multiline_inputbox_decimal_input_mode_flag = 0;
    wgui_inputbox_UCS2_count_function = wgui_inputs_ml_get_ucs2_count;
    wgui_inputbox_GSM_ext_count_function = wgui_inputs_ml_get_ext_gsm_count;
    if (input_type & INPUT_TYPE_USE_ENCODING_BASED_LENGTH)
    {
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH;
        if (input_type & INPUT_TYPE_ONE_LESS_CHARACTER)
        {
            MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_ONE_LESS_CHARACTER;
            UI_TEST_UCS2_COUNT_SET_LENGTH_TYPE2(
                MMI_multiline_inputbox.UCS2_count,
                MMI_multiline_inputbox.allocated_length,
                MMI_multiline_inputbox.available_length);
        }
        else if (input_type & INPUT_TYPE_FORTY_FOUR_LESS_CHARACTER)
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
        #if 0 /* slim_2_2 */ //
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif 

    }

#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
    MMI_multiline_inputbox.change_callback = set_multiline_inputbox_change_callback;    /* Originally for WCSS editor */
#endif 
    
    if (plus_character_handling)
    {
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_PLUS_CHARACTER_HANDLING;
    }
    if (input_type_flags & INPUT_TYPE_GSM_EXTENDED_HANDLING)
    {
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_CHECK_GSM_EXTENDED;
    }

    if ((saved_inputbox_flags & UI_MULTI_LINE_INPUT_BOX_MASK_CHARACTERS))
    {
        wgui_inputs_ml_set_mask(1);
    }
    wgui_inputbox_RSK_label_icon = RSK_icon;
    wgui_inputbox_RSK_label_string = RSK_label;
    /* move to the front for wgui_set_default_input_type */
    wgui_inputs_ml_register_input_callback(wgui_inputs_ml_handle_input);

    if (is_valid_history)
    {
        mmi_imc_set_input_method_history(&(((multiline_inputbox_category_history*)history_buffer)->ime_history));
    }

    if (connect_ime)
    {
        mmi_imm_set_required_mode_list(input_type & INPUT_TYPE_MASK, input_mode_array, IMM_INPUT_MODE_NONE);

        g_mmi_editor_hanler.input_box_type = MMI_EDITOR_MULTILINE_INPUT_BOX;
        
        if (category_screen_ID == MMI_CATEGORY201_ID)
        {
            g_mmi_editor_hanler.input_box_sub_type = MMI_EDITOR_DICT_MULTILINE_INPUT_BOX;
        }
        else if (category_screen_ID == MMI_CATEGORY404_ID)
        {
            g_mmi_editor_hanler.input_box_sub_type = MMI_EDITOR_VOIP_DIALER_MULTLINE_INPUT_BOX;
        }
    #ifdef __UI_UNIFIED_COMPOSER_EDITOR_CATEGORY__
        else if (category_screen_ID == MMI_CATEGORY280_ID)
        {
            g_mmi_editor_hanler.input_box_sub_type = MMI_EDITOR_UCE_MULTLINE_INPUT_BOX;
        }
    #endif /* __UI_UNIFIED_COMPOSER_EDITOR_CATEGORY__ */
    #if defined(__MMI_CAT203_SUPPORT__)
        else if (category_screen_ID == MMI_CATEGORY203_ID)
        {
            g_mmi_editor_hanler.input_box_sub_type = MMI_EDITOR_DIALER_SEARCH_MULTI_LINE_INPUT_BOX;
        }
    #endif /* __MMI_CAT203_SUPPORT__ */
        else
        {
            g_mmi_editor_hanler.input_box_sub_type = MMI_EDITOR_NORMAL_INPUT_BOX;
        }
        
        g_mmi_editor_hanler.input_box_handler = &MMI_multiline_inputbox;

        mmi_imc_connect((void *)&g_mmi_editor_hanler, msg_call_back);
        #if defined(__MMI_MAINLCD_96X64__)
		mmi_imc_set_is_disable_candidate_box(KAL_TRUE);
        #endif
    }

    g_wgui_inputs_is_clear_key_delete_all = MMI_FALSE;
    wgui_inputs_ml_set_decimal_flag(input_type);  /* slim_2_2 */ //
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
    #endif

    if (input_type & IMM_INPUT_TYPE_EXT_PASSWORD)
            wgui_inputs_ml_set_mask(1);
    wgui_inputs_ml_set_RSK();
    /* for avoid text_offset_y not be calculated. wgui_inputs_ml_show_no_draw() */
	gui_lock_double_buffer();
	wgui_inputs_ml_show_no_draw();
	gui_unlock_double_buffer();
    UI_UNUSED_PARAMETER(fh);
}

/* Simplified interface for wgui_setup_inputbox_ext() */


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_setup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x                           [IN]        
 *  y                           [IN]        
 *  width                       [IN]        
 *  height                      [IN]        
 *  buffer                      [?]         
 *  buffer_size                 [IN]        
 *  category_screen_ID          [IN]        
 *  RSK_label                   [IN]        
 *  RSK_icon                    [IN]        
 *  input_type                  [IN]        
 *  history_buffer              [?]         
 *  information_bar_flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_setup(
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
    wgui_inputs_ml_setup_ext2(
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
        NULL,
        information_bar_flag,
        0,
        0,
        0,
        0,
        0,
        NULL,
        mmi_input_box_msg_call_back_multiline,
        MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_view_mode_setup
 * DESCRIPTION
 *  Setup view only multiline inputbox
 * PARAMETERS
 *  x                           [IN]        Start x postition of inputr box
 *  y                           [IN]        Strar y position of input box
 *  width                       [IN]        Width of input box
 *  height                      [IN]        Height of input boxc
 *  buffer                      [IN]        Buffer of input box
 *  buffer_size                 [IN]        text buffer string length
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_view_mode_setup(
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        U8 *buffer,
        S32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 l = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    l = gui_strlen((UI_string_type) buffer);
    wgui_inputs_ml_create_set_buffer((UI_string_type) buffer, buffer_size, l, 0);
    MMI_multiline_inputbox.flags |= (UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW |
                                     UI_MULTI_LINE_INPUT_BOX_VIEW_MODE);
    wgui_inputs_ml_register_viewer_keys();
    gui_set_font(MMI_multiline_inputbox.text_font);

    if (x != WGUI_INPUTS_STYLE_DEFAULT || y != WGUI_INPUTS_STYLE_DEFAULT)
    {
        wgui_inputs_ml_move(x, y);
    }
    if (width != WGUI_INPUTS_STYLE_DEFAULT || height != WGUI_INPUTS_STYLE_DEFAULT)
    {
        wgui_inputs_ml_resize(width, height);   
    }

    wgui_inputs_ml_show_no_draw();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_set_common_style
 * DESCRIPTION
 *  Set common multiline style
 * PARAMETERS
 *  info_area       [in]        if include info area
 *  wallpaper       [in]        if draw wallpaper on bottom
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_set_common_style(MMI_BOOL info_area, MMI_BOOL wallpaper)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if UI_INCLUDE_INFORMATION_AREA_IN_MULTI_LINE
    if (info_area)
    {
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_INCLUDE_INFO_AREA;
    }
#endif

#ifdef __MMI_WALLPAPER_ON_BOTTOM__
    if (wallpaper)
    {
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_TRANSPARENT_BACKGROUND;
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_set_style
 * DESCRIPTION
 *  Set multiline style through set flags and ext_flags. 
 *  use '|' to add more than two style
 * PARAMETERS
 *  style       [in]        flags
 *  ext_style   [in]        ext_flags
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_set_style(U32 style, U32 ext_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_ml_set_style_with_obj(&MMI_multiline_inputbox, style, ext_style);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_set_style_with_obj
 * DESCRIPTION
 *  Set multiline style through set flags and ext_flags. 
 *  use '|' to add more than two style
 * PARAMETERS
 *  style       [in]        flags
 *  ext_style   [in]        ext_flags
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_set_style_with_obj(multi_line_input_box *b, U32 style, U32 ext_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (style)
    {
        b->flags |= style;
    }

    if (ext_style)
    {
        b->ext_flags |= ext_style;
    }

#ifdef __MMI_EDITOR_MULTILINE_DIALER_STYLE_SUPPORT__
    if (ext_style & GUI_MULTI_LINE_INPUT_BOX_DIALER_STYLE)
    {
        MMI_multiline_inputbox.change_callback = wgui_inputs_ml_change_callback;
        wgui_inputs_ml_change_callback();
    }
#endif

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    gui_mlc_change_request(0);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_move_cursor_to_start
 * DESCRIPTION
 *  Move the cursor the the start position and edit from the beginning
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_move_cursor_to_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_multiline_inputbox.cursor_p = MMI_multiline_inputbox.text;
    MMI_multiline_inputbox.cursor_line_position_counter = 0;
    wgui_inputs_ml_show_no_draw();
}


#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__ /**/
/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_set_predefine_pos_info
 * DESCRIPTION
 *  Set predefined pos related info, used in WCSS category.
 * PARAMETERS
 *  predefined_pos              [IN]        the predefined the format array.
 *  cursor_move_callback        [IN]        the cursor move callback function
 *  change_event_handler        [IN]        change event handler
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_set_predefine_pos_info(
        S16 *predefined_pos,
        void (*cursor_move_callback)(S32 cursor_offset),
        MMI_BOOL (*change_event_handler)(gui_multi_line_input_box_change_event_enum event,U16 c))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_multiline_inputbox.predefine_char_pos = predefined_pos;
    MMI_multiline_inputbox.cursor_move_callback = cursor_move_callback;
    MMI_multiline_inputbox.change_event_handler = change_event_handler;
}
#endif /*__MMI_WCSS_INPUT_FORMAT_SUPPORT__*/ /**/


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_get_text_length
 * DESCRIPTION
 *  Get the text length of current multilne inputbox
 * PARAMETERS
 *  void
 * RETURNS
 *  text length of current multiline inputbox
 *****************************************************************************/
S32 wgui_inputs_ml_get_text_length(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_multiline_inputbox.text_length;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_go_to_last_line
 * DESCRIPTION
 *  Go to the last line of the whole text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_go_to_last_line(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_multiline_inputbox.text_height > MMI_multiline_inputbox.edit_height)
    {
        while (MMI_multiline_inputbox.text_offset_y + MMI_multiline_inputbox.text_height >
               MMI_multiline_inputbox.edit_height)
        {
            gui_multi_line_input_box_next_line(&MMI_multiline_inputbox);
        }
    }
    else
    {
        for (index = 0; index < (MMI_multiline_inputbox.n_lines); index++)
        {
            gui_multi_line_input_box_next_line(&MMI_multiline_inputbox);
        }
    }

    wgui_inputs_ml_show();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_is_last_line
 * DESCRIPTION
 *  Check if it is the last line of multiline inputbox
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL wgui_inputs_ml_is_last_line(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_multiline_inputbox.text_offset_y + MMI_multiline_inputbox.text_height <=
        MMI_multiline_inputbox.edit_height) ? MMI_TRUE : MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_set_RSK
 * DESCRIPTION
 *  set RSK function handler of multiline input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_set_RSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_ml_set_RSK_int(1);
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
#ifdef __ASCII
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __ASCII */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif /* slim_2_2 */ //
}
/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_set_RSK
 * DESCRIPTION
 *  set RSK function handler of multiline input box
 * PARAMETERS
 *  show_counter_flag   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inputs_ml_set_RSK_int(S32 show_counter_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputbox_RSK_label_clear = 0;
    if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
    {
        SetKeyHandler(wgui_inputs_ml_handle_right_softkey_down, KEY_CLEAR, KEY_EVENT_DOWN);
        SetKeyHandler(wgui_inputs_ml_handle_right_softkey_long_press, KEY_CLEAR, KEY_LONG_PRESS);
        set_right_softkey_function(wgui_inputs_ml_handle_right_softkey_up, KEY_EVENT_UP);
    }
    else
    {
        set_right_softkey_function(wgui_inputs_ml_handle_right_softkey_down, KEY_EVENT_DOWN);
        set_right_softkey_function(wgui_inputs_ml_handle_right_softkey_long_press, KEY_LONG_PRESS);
    } 

    wgui_inputs_ml_handle_input_int(show_counter_flag);    

    if (wgui_inputs_ml_is_empty())
    {
    
        if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
        {
            SetKeyHandler(UI_dummy_function, KEY_CLEAR, KEY_EVENT_UP);
            SetKeyHandler(UI_dummy_function, KEY_CLEAR, KEY_EVENT_LONG_PRESS);
        }
        else
        {
            set_right_softkey_function(wgui_inputs_ml_register_handle_right_softkey_up, KEY_EVENT_DOWN);
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
    MMI_multiline_inputbox.validation_callback = wgui_inputs_ml_validation_callback;
    /* MMI_multiline_inputbox.validation_callback(MMI_multiline_inputbox.text,MMI_multiline_inputbox.cursor_p,MMI_multiline_inputbox.text_length); */
#ifdef __ASCII
    MMI_multiline_inputbox.validation_callback(
                            MMI_multiline_inputbox.text,
                            MMI_multiline_inputbox.cursor_p,
                            MMI_multiline_inputbox.text_length - 1);
#endif /* __ASCII */ 
    MMI_multiline_inputbox.validation_callback(
                            MMI_multiline_inputbox.text,
                            MMI_multiline_inputbox.cursor_p,
                            (MMI_multiline_inputbox.text_length >> 1) - 1);

}


#ifdef __OP01_FWPBW__
/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_set_RSK_no_show_counter
 * DESCRIPTION
 *  set RSK function handler of multiline input box without show counter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_set_RSK_no_show_counter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_ml_set_RSK_int(0);

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
#ifdef __ASCII
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __ASCII */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* slim_2_2 */ //
}
#endif


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_close
 * DESCRIPTION
 *  close input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_multiline_inputbox_decimal_input_mode_flag = 0;
    mmi_imc_disconnect();
    wgui_inputs_ml_reset();
    wgui_multiline_history_buffer = NULL;
    wgui_multiline_history_ID = (S16)-1;
    //wgui_inputbox_RSK_function = NULL;
    wgui_inputs_category_set_rsk_func(NULL);
    wgui_inputbox_RSK_label_clear = 0;
    wgui_inputbox_information_flag = 0;
    wgui_inputbox_not_empty_callback = NULL;
    wgui_inputbox_empty_callback = NULL;
    wgui_inputbox_validation_callback = NULL;
    wgui_inputbox_UCS2_count_function = NULL;
    wgui_inputbox_GSM_ext_count_function = NULL;
    wgui_inputbox_input_method_change_callback = NULL;

    multiline_inputbox_set_key_callback = NULL;
    g_wgui_inputs_is_clear_key_delete_all = MMI_FALSE;

    ClearKeyHandler(KEY_STAR, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_POUND, KEY_EVENT_DOWN);
    /* W05.36 Fix Vietnamese Tone Input Issue */
    wgui_inputs_set_current_input_box_type(EDITOR_NONE_INPUT_BOX);

#ifdef __OP01_FWPBW__
    gui_cancel_timer(wgui_inputs_show_current_input_method_timer_handler);
#endif
}

/* Api Call to intialize the multiline inscreen editor control. */


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_inline_setup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x                           [IN]        
 *  y                           [IN]        
 *  width                       [IN]        
 *  height                      [IN]        
 *  buffer                      [?]         
 *  buffer_size                 [IN]        
 *  category_screen_ID          [IN]        
 *  RSK_label                   [IN]        
 *  RSK_icon                    [IN]        
 *  input_type                  [IN]        
 *  history_buffer              [?]         
 *  information_bar_flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_inline_setup(
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
    S32 l;
    U32 input_type_flags = input_type & (~INPUT_TYPE_MASK);
    U32 saved_inputbox_flags;
    U8 plus_character_handling = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* W05.36 Fix Vietnamese Tone Input Issue */
    wgui_inputs_set_current_input_box_type(EDITOR_INLINE_MULTILINE_INPUT_BOX);
    /* patch for inline multiline input box */

    wgui_inputbox_buffer_size = buffer_size;
    if (input_type & INPUT_TYPE_PLUS_CHARACTER_HANDLING)
    {
        plus_character_handling = 1;
    }
    /* Information Bar For Inline Multiline */
    if (information_bar_flag)
    {
        wgui_inputbox_information_flag = 1;
    }
    l = gui_strlen((UI_string_type) buffer);
    wgui_inputs_ml_create_set_buffer((UI_string_type) buffer, buffer_size, l, l);
    wgui_inputs_ml_inline_register_keys();
    /* Information Bar For Inline Multiline */
    if (information_bar_flag)
    {
        /* Inline Multiline Control Information Bar Height Change */
        wgui_inputbox_information_bar_height = INFORMATION_BAR_HEIGHT;
        wgui_inputs_setup_input_information(x + 2, y + 1, width - 5, wgui_inputbox_information_bar_height);
        /* Inline Multiline Control Information Bar Height Change */
        wgui_inputs_ml_move(x, y + wgui_inputbox_information_bar_height + 2);
    }
    else
    {
        wgui_inputs_ml_move(x, y);
    }
    
    gui_set_font(MMI_multiline_inputbox.text_font);
    /* Information Bar For Inline Multiline */
#if !defined(__MMI_TOUCH_SCREEN__)
    wgui_inputs_ml_resize(width - 2, height/* + MMI_ICONTEXT_MENUITEM_HEIGHT*/ - wgui_inputbox_information_bar_height - 2);
#else 
    wgui_inputs_ml_resize(width - 2, height);
#endif 

    wgui_inputs_ml_set_category_history(category_screen_ID, history_buffer);

#if defined(__MMI_IMC_CAPITAL_SWITCH__)	
    if (history_buffer != NULL)
	{
        mmi_imm_set_writing_language_from_history(IME_WRITING_LANG_NONE);
	}	
#endif
	
    saved_inputbox_flags = MMI_multiline_inputbox.flags;

    input_type |= input_type_flags;
    wgui_multiline_inputbox_decimal_input_mode_flag = 0;
    wgui_inputbox_UCS2_count_function = wgui_inputs_ml_get_ucs2_count;
    wgui_inputbox_GSM_ext_count_function = wgui_inputs_ml_get_ext_gsm_count;
    if (input_type & INPUT_TYPE_USE_ENCODING_BASED_LENGTH)
    {
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH;
        if (input_type & INPUT_TYPE_ONE_LESS_CHARACTER)
        {
            MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_ONE_LESS_CHARACTER;
            UI_TEST_UCS2_COUNT_SET_LENGTH_TYPE2(
                MMI_multiline_inputbox.UCS2_count,
                MMI_multiline_inputbox.allocated_length,
                MMI_multiline_inputbox.available_length);
        }
        else if (input_type & INPUT_TYPE_FORTY_FOUR_LESS_CHARACTER)
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
    if (plus_character_handling)
    {
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_PLUS_CHARACTER_HANDLING;
    }
    if (input_type_flags & INPUT_TYPE_GSM_EXTENDED_HANDLING)
    {
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_CHECK_GSM_EXTENDED;
    }

    if ((saved_inputbox_flags & UI_MULTI_LINE_INPUT_BOX_MASK_CHARACTERS))
    {
        wgui_inputs_ml_set_mask(1);

    }
    wgui_inputbox_RSK_label_icon = RSK_icon;
    wgui_inputbox_RSK_label_string = RSK_label;
    MMI_multiline_inputbox.change_callback = set_multiline_inputbox_change;
    wgui_inputs_ml_register_input_callback(wgui_inputs_ml_handle_input);
    wgui_inputs_ml_show_no_draw();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_append_string
 * DESCRIPTION
 *  append the string in category 5 (editor) text
 * PARAMETERS
 *  input_type          [IN]        Input ype
 *  buffer              [IN]        Buffer
 *  buffer_size         [IN]        Buffer isze
 *  s                   [IN]        String
 *  history_buffer      [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_append_string(
                    U32 input_type, 
                    U8 *buffer, 
                    S32 buffer_size, 
                    U8 *s, 
                    U8 *history_buffer,
                    U16 category_id,
                    MMI_BOOL (*change_event_handler)(gui_multi_line_input_box_change_event_enum event,U16 C))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 l, h, fh, i;
    UI_string_type ts = (UI_string_type) s;
    mmi_imc_history temp_ime_history;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    l = gui_strlen((UI_string_type) buffer);
    wgui_inputs_ml_create_set_buffer((UI_string_type) buffer, buffer_size, l, l);
    gui_multi_line_input_box_register_change_event_handler(&MMI_multiline_inputbox,change_event_handler);
    if (input_type & INPUT_TYPE_USE_ENCODING_BASED_LENGTH)
    {
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH;
        if (input_type & INPUT_TYPE_ONE_LESS_CHARACTER)
        {
            MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_ONE_LESS_CHARACTER;
            UI_TEST_UCS2_COUNT_SET_LENGTH_TYPE2(
                MMI_multiline_inputbox.UCS2_count,
                MMI_multiline_inputbox.allocated_length,
                MMI_multiline_inputbox.available_length);
        }
        else if (input_type & INPUT_TYPE_FORTY_FOUR_LESS_CHARACTER)
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

#ifdef __BW_MMI__
    h = MMI_content_height - MMI_multitap_height;
#else 
    h = MMI_content_height - MMI_multitap_height - MULTILINE_INPUTBOX_EDIT_HEIGHT_PAD;
#endif 

    memcpy(&temp_ime_history, &(((multiline_inputbox_category_history*)history_buffer)->ime_history), sizeof(mmi_imc_history));

    wgui_inputs_ml_set_category_history(category_id, history_buffer);
    wgui_inputs_ml_show_no_draw();
    fh = wgui_inputs_ml_get_line_height();
    h = ((h / fh) * fh) + MULTILINE_INPUTBOX_EDIT_HEIGHT_PAD;
    wgui_inputs_ml_resize(MMI_multiline_inputbox.width, h);

    l = gui_strlen(ts);

    MMI_multiline_inputbox.show_action_flag = 0;
    for (i = 0; i < l; i++)
    {
        if (!gui_multi_line_input_box_insert_character(&MMI_multiline_inputbox, (UI_character_type) ts[i]))
            break;
    }
    
    MMI_multiline_inputbox.show_action_flag = 1;
    
    //MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_show_multi_line_input_box(&MMI_multiline_inputbox);
    //MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_multi_line_input_box_no_draw(&MMI_multiline_inputbox);
    
    wgui_inputs_ml_get_category_history(category_id, history_buffer);

#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
    temp_ime_history.skip_auto_cap_first_filter = MMI_TRUE;
#endif

    memcpy(&(((multiline_inputbox_category_history*)history_buffer)->ime_history), &temp_ime_history, sizeof(mmi_imc_history));

    /* wgui_inputs_ml_show(); */

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_input_box_msg_call_back_multiline
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_input_box_msg_call_back_multiline(void * input_box_handle, mmi_imc_message_struct_p msg_ptr)
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
    UI_character_type first_char;
    UI_character_type second_char;
    U32 old_show_action_flag = 0;
#ifdef __MMI_CLIPBOARD__
    UI_buffer_type cut_cursor_p = NULL;
    U32 cursor_move_old_flags;
	U32 cut_char_count = 0;
#endif /* __MMI_CLIPBOARD__ */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    editor_ptr = (multi_line_input_box *)((mmi_editor_handler_struct *)input_box_handle)->input_box_handler;
    
    MMI_ASSERT(editor_ptr == &MMI_multiline_inputbox);
    
    switch (msg_ptr->message_id)
    {
    case MMI_IMC_MESSAGE_INSERT_CHAR:

#ifdef __MMI_EDITOR_SSP_SUPPORT__
        {
            mmi_pen_point_struct point = {0, 0};
            
            gui_input_box_ssp_pen_translate(point, MMI_PEN_EVENT_ABORT);
        }
#endif
        
#if defined(__UI_PAGING_IN_MULTILINE_EDITOR__)
#ifdef __MMI_TOUCH_SCREEN__
        if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_PAGING_IN_MULTLINE_INPUT_BOX)
        {
            wgui_inputs_ml_paging_key_mapping_TS((UI_character_type)msg_ptr->param_0);
        }
        else if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_LINE_BASED_IN_MULTLINE_INPUT_BOX)
        {
            wgui_inputs_ml_linebase_key_mapping_TS((UI_character_type)msg_ptr->param_0);
        }
        else
#endif /* __MMI_TOUCH_SCREEN__ */
#endif
        {
            lresult = wgui_inputs_ml_direct_input((UI_character_type)msg_ptr->param_0);

#ifdef __MMI_TOUCH_SCREEN__
            /* smart abc, pen down in editor will insert a space behind, so move the pen down cursor to current cursor */
            if (g_wgui_inputs_ml_pen_down_cursor_p && (UI_character_type)msg_ptr->param_0 == 0x20)
            {
                g_wgui_inputs_ml_pen_down_cursor_p = editor_ptr->cursor_p;
            }
#endif
            /* in message app, when input long text to switch sms to mms, popup appears,
               category will get history first-->then close editor(close will disconnect ime)--> set history. 
               when inputmode is smart, mmi_imc_disconnet will comfirm condidate and insert a space in the end, so history is changed
               Thus we need get history again to get right value */
            if (lresult && wgui_multiline_history_buffer != NULL && wgui_multiline_history_ID != (S16)-1)
            {
                wgui_inputs_ml_get_category_history_ext(editor_ptr, wgui_multiline_history_ID, wgui_multiline_history_buffer);
            }
        }
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

    #if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) /* We should force cursor to update in WCSS editor */
        if (!((editor_ptr->flags & UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE) 
            || editor_ptr->predefine_char_pos != NULL))
    #endif
        {
            old_show_action_flag = editor_ptr->show_action_flag;

            editor_ptr->show_action_flag = 0;
        }

        for (i = 0; i < str_len; i++)
        {
            /* TODO: Insert successfully? */
            if (temp_str[i] != 0)
            {
				if (MMI_TRUE == multiline_inputbox_direct_input_no_draw((UI_character_type)temp_str[i]))
				{
					total_len ++;
				}
				else
				{
					break;
				}
			}	
			else
			{
                break;
			}
        }
        
    #if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) /* We should force cursor to update in WCSS editor */
        if (!((editor_ptr->flags & UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE) 
            || editor_ptr->predefine_char_pos != NULL))
    #endif
        {
            editor_ptr->show_action_flag = old_show_action_flag;
        
        #ifdef GUI_INPUT_BOX_CACHE_SUPPORT
            if (str_len > 10)
            {
                gui_mlc_all_line_update();
            }
        #endif
        }    

        wgui_inputs_ml_redraw();
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
    if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INCLUDE_INFO_AREA))
#endif 
    {
        if (total_len >0)
            multiline_inputbox_input_callback();
    }

        lresult = total_len;
        
        break;

    case MMI_IMC_MESSAGE_INSERT_STRING_NO_DRAW:

        temp_str = (UI_string_type)msg_ptr->param_0;

        str_len = (S32)mmi_ucs2strlen((const S8 *)temp_str);

        for (i = 0; i < str_len; i++)
        {
            if (MMI_TRUE == wgui_inputs_ml_direct_input_no_draw((UI_character_type)temp_str[i]))
            {
                total_len ++;
            }
            else
            {
                break;
            }
        }

    #if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
        if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INCLUDE_INFO_AREA))
    #endif 
        {
            if (total_len >0)
                multiline_inputbox_input_callback();
        }

        lresult = total_len;
        break;

	case MMI_IMC_MESSAGE_REPLACE_HIGHLIGHT_STRING:

		old_show_action_flag = editor_ptr->show_action_flag;

        editor_ptr->show_action_flag = 0;

		for (i = 0; i < msg_ptr->param_0; i ++)
        {
            wgui_inputs_ml_delete_character_no_draw();
        }
		
		temp_str = (UI_string_type)msg_ptr->param_1;
		
        str_len = (S32)mmi_ucs2strlen((const S8 *)temp_str);
		
        for (i = 0; i < str_len; i++)
        {
            if (MMI_TRUE == wgui_inputs_ml_direct_input_no_draw((UI_character_type)temp_str[i]))
            {
                total_len ++;
            }
            else
            {
                break;
            }
        }
		
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
        if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INCLUDE_INFO_AREA))
#endif 
        {
            if (msg_ptr->param_0 > 0 || total_len > 0)
                multiline_inputbox_input_callback();
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

		wgui_inputs_ml_redraw();
		
        lresult = total_len;

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
            *((UI_buffer_type *)(msg_ptr->param_0)) = MMI_multiline_inputbox.highlight_start_position;
            *((UI_buffer_type *)(msg_ptr->param_1)) = MMI_multiline_inputbox.highlight_end_position;
            lresult = (U32)((MMI_multiline_inputbox.highlight_end_position - MMI_multiline_inputbox.highlight_start_position) / ENCODING_LENGTH);
        }
        else
        {
            *((UI_buffer_type *)(msg_ptr->param_0)) = 0;
            *((UI_buffer_type *)(msg_ptr->param_1)) = 0;
            lresult = 0;
        }
        break;
        
    case MMI_IMC_MESSAGE_MOVE_CURSOR_TO_HIGHLIGHT_START:
        if (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT)
        {
            UI_buffer_type words_start_p = MMI_multiline_inputbox.highlight_start_position;
            UI_buffer_type old_cursor_p = MMI_multiline_inputbox.cursor_p;    
            UI_character_type c;
            
            MMI_multiline_inputbox.cursor_p = words_start_p;
            
        #ifdef GUI_INPUT_BOX_CACHE_SUPPORT
            gui_mlc_all_line_update();
        #endif

            gui_show_multi_line_input_box_ext(&MMI_multiline_inputbox, -1, -1);

			if (old_cursor_p != MMI_multiline_inputbox.cursor_p)
			{
                MMI_multiline_inputbox.cursor_fixed_x = -1;
			}
            
			while (words_start_p > MMI_multiline_inputbox.text) /* Go to the end of the previous word */
			{
				c = (UI_character_type)((*((words_start_p - 2)+0))|((*((words_start_p - 2)+1))<<8));

				if (c == 0x20) 
				{
                    gui_multi_line_input_box_previous(&MMI_multiline_inputbox);

					words_start_p = MMI_multiline_inputbox.cursor_p;
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

        for (i = 0; i < msg_ptr->param_0; i ++)
        {
            wgui_inputs_ml_delete_character_no_draw();
        }

        editor_ptr->show_action_flag = old_show_action_flag;

        if (!msg_ptr->param_1)
        {
            wgui_inputs_ml_redraw();
        }
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
    if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INCLUDE_INFO_AREA))
#endif 
        multiline_inputbox_input_callback();
        break;
    case MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR:
        ch = (UI_character_type)msg_ptr->param_0;
        lresult = wgui_inputs_ml_multitap_input(ch);
        break;

    case MMI_IMC_MESSAGE_INSERT_MULTITAP_STRING:
        #ifdef __MMI_EDITOR_MULTILINE_SUPPORT_MULTIGRAPH__ 
        temp_str = (UI_string_type)msg_ptr->param_0;
        /* Insert the string in editor */
        lresult = wgui_inputs_ml_multitap_input_string((PU8)temp_str);
        #endif /*__MMI_EDITOR_MULTILINE_SUPPORT_MULTIGRAPH__*/
        break;

    case MMI_IMC_MESSAGE_RESET_MULTITAP_STATE:
        wgui_inputs_ml_multitap_input_complete();
        gui_multi_line_input_box_stop_input(editor_ptr);
    #if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
        if (MMI_multiline_inputbox.flags & UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE)
        {
            gui_set_WCSS_Esc_Char(MMI_TRUE);
            gui_change_WCSS_input_method(&MMI_multiline_inputbox);
        }
    #endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 
        break;
        
    case MMI_IMC_MESSAGE_DELETE_CHAR:
        {
            U16 keyCode, keyType;
        #if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
            if ((editor_ptr->flags & UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE) 
                 || editor_ptr->predefine_char_pos != NULL)
            {
                if (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP)
                {
                    gui_multi_line_input_box_confirm_multitap_character(&MMI_multiline_inputbox);
                }
            }
        #endif /* __MMI_WCSS_INPUT_FORMAT_SUPPORT__ */

            mmi_frm_get_key_info(&keyCode, &keyType);
            if (keyType == KEY_REPEAT)
            {
                wgui_inputs_fast_del_nav_handler(WGUI_INPUTS_OPER_FAST_DEL, WGUI_INPUTS_EDITOR_ML, WGUI_INPUTS_KPD_REPEAT_PERIOD);
            }
            else
            {
                for (i = 0; i < msg_ptr->param_0; i++)
                {
                    wgui_inputs_ml_delete_character_no_draw();
                }
                wgui_inputs_ml_redraw();
        #if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
                if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INCLUDE_INFO_AREA))
        #endif 
                    multiline_inputbox_input_callback();
            }

#ifdef __MMI_TOUCH_SCREEN__
            /* smart abc, pen down in editor sometimes delete a space, so move the pen down cursor to current cursor */
            if (g_wgui_inputs_ml_pen_down_cursor_p)
            {
                g_wgui_inputs_ml_pen_down_cursor_p = editor_ptr->cursor_p;
            }
#endif
            break;
        }
    case MMI_IMC_MESSAGE_CLEAR_ALL:
    #ifdef __MMI_TOUCH_SCREEN__
        if (g_wgui_inputs_is_clear_key_delete_all)
        {
            wgui_inputs_ml_delete_all_characters();
        }
        else
        {
            wgui_inputs_fast_del_pen_handler(WGUI_INPUTS_OPER_FAST_DEL, WGUI_INPUTS_EDITOR_ML, MMI_PEN_EVENT_LONG_TAP);
        }
    #else
        wgui_inputs_fast_del_nav_reset_repeat_count();
    #endif
        break;

    case MMI_IMC_MESSAGE_BACKSPACE_KEY_EVENT:
    #ifdef __MMI_TOUCH_SCREEN__
        wgui_inputs_fast_del_pen_handler(WGUI_INPUTS_OPER_FAST_DEL, WGUI_INPUTS_EDITOR_ML, (mmi_pen_event_type_enum)msg_ptr->param_0);
    #endif
        break;

    case MMI_IMC_MESSAGE_CHANGE_TO_INITIAL:
        if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_DICT_MULTILINE_INPUT_BOX)
        {
#ifdef __MMI_PHB_QUICK_SEARCH__     //**/            
            wgui_cat201_register_key_handler();
#endif /* __MMI_PHB_QUICK_SEARCH__ */
        }

        /* Because empty callback will not called in ML editor input callback if in IME state, so we need to
           re-call empty callback after change to initial state */
        if (wgui_inputs_ml_is_empty() && (wgui_inputbox_empty_callback != NULL))
        {
            wgui_inputbox_empty_callback();
        }
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
				wgui_inputs_ml_redraw();
                break;
            case MMI_IMC_EDITOR_CURSOR_DOWN:
                for (i = 0; i <(S32)msg_ptr->param_1; i ++)
                {
                    gui_multi_line_input_box_next_line(editor_ptr);
                }
				wgui_inputs_ml_redraw();
                break;
            case MMI_IMC_EDITOR_CURSOR_LEFT:
                for (i = 0; i <(S32)msg_ptr->param_1; i ++)
                {
                    wgui_inputs_ml_previous_character();
                }
                break;
            case MMI_IMC_EDITOR_CURSOR_RIGHT:
                for (i = 0; i <(S32)msg_ptr->param_1; i ++)
                {
                    wgui_inputs_ml_next_character();
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
        wgui_inputs_ml_redraw();
        break;
    case MMI_IMC_MESSAGE_CLEAR_HILIGHT:
        editor_ptr->flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        editor_ptr->highlight_start_position = NULL;
        editor_ptr->highlight_end_position = NULL;
        break;
    case MMI_IMC_MESSAGE_GET_INPUT_BOX_RECT:
#if defined(__MMI_EBOOK_READER__)    	
        if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_LINE_BASED_IN_MULTLINE_INPUT_BOX)
        {
            wgui_category375_get_inputbox_and_counter_size(
                &((mmi_imc_rect_p)msg_ptr->param_0)->x,
                &((mmi_imc_rect_p)msg_ptr->param_0)->y,
                &((mmi_imc_rect_p)msg_ptr->param_0)->width,
                &((mmi_imc_rect_p)msg_ptr->param_0)->height);
        }
        else
#endif /* __MMI_EBOOK_READER__ */
      	{
            ((mmi_imc_rect_p)msg_ptr->param_0)->x = editor_ptr->x;
            ((mmi_imc_rect_p)msg_ptr->param_0)->y = editor_ptr->y;
            ((mmi_imc_rect_p)msg_ptr->param_0)->width = editor_ptr->width;
            ((mmi_imc_rect_p)msg_ptr->param_0)->height = editor_ptr->height;
        }
        break;

	case MMI_IMC_MESSGAE_GET_EXT_INPUT_BOX_RECT:
		if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_DICT_MULTILINE_INPUT_BOX)
		{
            ((mmi_imc_rect_p)msg_ptr->param_0)->x = MMI_fixed_list_menu.x;
			((mmi_imc_rect_p)msg_ptr->param_0)->y = MMI_fixed_list_menu.y;
			((mmi_imc_rect_p)msg_ptr->param_0)->width = MMI_fixed_list_menu.width;
            ((mmi_imc_rect_p)msg_ptr->param_0)->height = MMI_fixed_list_menu.height;
			
            lresult = MMI_TRUE;
		}	
		break;
       
    case MMI_IMC_MESSAGE_RESIZE:
        
        switch(((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type)
        {
        case MMI_EDITOR_NORMAL_INPUT_BOX:

            if ((S32)msg_ptr->param_1 != editor_ptr->height)
            {
                gui_resize_multi_line_input_box(editor_ptr, (S32)msg_ptr->param_0, (S32)msg_ptr->param_1);
            }

			break;

        case MMI_EDITOR_PAGING_IN_MULTLINE_INPUT_BOX:
            if ((S32)msg_ptr->param_1 != editor_ptr->height)
            {
                gui_resize_multi_line_input_box(editor_ptr, (S32)msg_ptr->param_0, (S32)msg_ptr->param_1);
				wgui_inputs_ml_redraw();
            }

            break;
            
        case MMI_EDITOR_DICT_MULTILINE_INPUT_BOX:
            resize_fixed_list(MMI_fixed_list_menu.width, MMI_fixed_list_menu.height + (S32)msg_ptr->param_1 - editor_ptr->height);
            /* W06.03 Adjust highlight position */
            gui_dynamic_list_menu_locate_highlighted_item(&MMI_fixed_list_menu);
            gui_move_multi_line_input_box(editor_ptr, editor_ptr->x, 
                                          MMI_fixed_list_menu.y + MMI_fixed_list_menu.height + wgui_inputbox_information_bar_height);
            wgui_inputs_setup_input_information(
                editor_ptr->x,
                editor_ptr->y - wgui_inputbox_information_bar_height,
                editor_ptr->width,
                wgui_inputbox_information_bar_height);
            break;
		case MMI_EDITOR_UCE_MULTLINE_INPUT_BOX:
            if ((S32)msg_ptr->param_1 != editor_ptr->height)
            {   
                MMI_BOOL disable = wgui_inputs_ml_is_disable();
                gui_resize_multi_line_input_box_no_draw(editor_ptr, (S32)msg_ptr->param_0, (S32)msg_ptr->param_1);

                if (MMI_multiline_inputbox.text_offset_y < (MMI_multiline_inputbox.height - MMI_multiline_inputbox.text_height - 2))
                {
                    MMI_multiline_inputbox.text_offset_y = MMI_multiline_inputbox.height - MMI_multiline_inputbox.text_height - 2;
                }

                if (MMI_multiline_inputbox.text_offset_y > 0)
                {
                    MMI_multiline_inputbox.text_offset_y = 0;
                }
                
                //editor_ptr->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
                if (disable == MMI_TRUE)
                {
                    editor_ptr->ext_flags |= GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
                }
                //gui_show_multi_line_input_box(editor_ptr);   /* show multiline input box */
                //editor_ptr->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;   
                gui_show_multi_line_input_box_no_draw(editor_ptr);
                
            }
            break;
#if defined(__MMI_EBOOK_READER__)
        case MMI_EDITOR_LINE_BASED_IN_MULTLINE_INPUT_BOX:
            {
                wgui_category375_resize_inputbox_and_counter(editor_ptr, (S32)msg_ptr->param_0, (S32)msg_ptr->param_1);
            }
            break;      
#endif /* __MMI_EBOOK_READER__ */
#if defined(__MMI_CAT203_SUPPORT__)
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
        case MMI_EDITOR_UCE_MULTLINE_INPUT_BOX:
            if ((S32)msg_ptr->param_1 != editor_ptr->height)
            {
                gui_move_multi_line_input_box(editor_ptr, (S32)msg_ptr->param_0, (S32)msg_ptr->param_1);
            }
            
            break;
        case MMI_EDITOR_DICT_MULTILINE_INPUT_BOX:
            resize_fixed_list(MMI_fixed_list_menu.width, (S32)msg_ptr->param_1 - MMI_fixed_list_menu.y - wgui_inputbox_information_bar_height);
            /* W06.03 Adjust highlight position */
            gui_dynamic_list_menu_locate_highlighted_item(&MMI_fixed_list_menu);
            gui_move_multi_line_input_box(editor_ptr, (S32)msg_ptr->param_0, (S32)msg_ptr->param_1);
            wgui_inputs_setup_input_information(
                editor_ptr->x,
                editor_ptr->y - wgui_inputbox_information_bar_height,
                editor_ptr->width,
                wgui_inputbox_information_bar_height);
            break;
    #if defined(__MMI_CAT203_SUPPORT__)
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

#ifdef __MMI_EDITOR_SSP_SUPPORT__
        {
            mmi_pen_point_struct point = {0, 0};
            
            gui_input_box_ssp_pen_translate(point, MMI_PEN_EVENT_ABORT);
        }
#endif

        if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_DICT_MULTILINE_INPUT_BOX)
        {
            if (msg_ptr->param_0 == 1)
            {
                dm_imui_window_hide();
            }
            else
            {
#ifdef __MMI_PHB_QUICK_SEARCH__     //**/                
                wgui_cat201_redraw_controlled_area();
#endif /*__MMI_PHB_QUICK_SEARCH__*/
            }
        }
    #if defined(__MMI_EBOOK_READER__)
        else if(((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_LINE_BASED_IN_MULTLINE_INPUT_BOX)
        {
            if (msg_ptr->param_0 == 1)
            {
                dm_imui_window_hide();
            }
            else
            {
                wgui_category375_redraw_inputbox_and_counter();
            }
        }
    #endif /* __MMI_EBOOK_READER__ */
    #ifdef __MMI_CLIPBOARD__
        else if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_INPUT_BOX_MMS_VIEWER)
        {
            /* MMS viewer use control area to show editor, so we need to redraw here */
            if (msg_ptr->param_0 == 1)
            {
                wgui_inputs_ml_redraw();
              //  dm_imui_window_hide();
            }
            else
            {
                wgui_inputs_ml_redraw();
            }
        }
        else if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_INPUT_BOX_EBOOK)
        {
        /*    if (msg_ptr->param_0 == 1)
            {
                dm_imui_window_hide();
            }
            else*/
            {
                wgui_inputs_ml_redraw();
            }
        }
    #endif
        else
        {
            MMI_multiline_inputbox.validation_callback = wgui_inputs_ml_validation_callback;

        #ifdef __ASCII
            MMI_multiline_inputbox.validation_callback(
                MMI_multiline_inputbox.text,
                MMI_multiline_inputbox.cursor_p,
                MMI_multiline_inputbox.text_length - 1);
        #else
            MMI_multiline_inputbox.validation_callback(
                MMI_multiline_inputbox.text,
                MMI_multiline_inputbox.cursor_p,
                (MMI_multiline_inputbox.text_length >> 1) - 1);
        #endif /* __ASCII */ 

            if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type != MMI_EDITOR_PAGING_IN_MULTLINE_INPUT_BOX
            && ((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type != MMI_EDITOR_LINE_BASED_IN_MULTLINE_INPUT_BOX)
            {
                if (msg_ptr->param_0 == 1)
                {
                    dm_imui_window_hide();
                }
                else
                {
                    wgui_inputs_ml_redraw();
                }
             }
        }
        
        break;
        
    case MMI_IMC_MESSAGE_FLOATING_UI_APPEAR_INDICATION:
        dm_imui_window_display();
        break;

    case MMI_IMC_MESSAGE_DRAW_INFORMATION_BAR:

        wgui_inputs_ml_redraw_input_information_bar();

        break;
        
    case MMI_IMC_MESSAGE_UPDATE_SOFTKEY:
        break;
    case MMI_IMC_MESSAGE_IS_SOFTKEY_HIDE:
        if ((((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_LINE_BASED_IN_MULTLINE_INPUT_BOX ||
             ((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_INPUT_BOX_EBOOK) &&
            wgui_cat_ebook_is_full_screen())
        {
            lresult = MMI_TRUE;
        }
        else
        { 
            lresult = MMI_FALSE;
        }
        break;
    case MMI_IMC_MESSAGE_KEY_EVENT:
        break;
    case MMI_IMC_MESSAGE_MODE_CHANGED:
            if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_DICT_MULTILINE_INPUT_BOX)
            {
                if (wgui_check_pound_key_buffer_flush)
                {
                    if (wgui_check_pound_key_buffer_flush())
                    {
                        wgui_inputs_ml_delete_all_characters();
                    }
                    else
                    {
                        MMI_multiline_inputbox.change_callback();
                    }
                }
                else
                {
                    MMI_multiline_inputbox.change_callback();
                }
            }
            else 
            {
                if (wgui_check_pound_key_buffer_flush)
                {
                    if (wgui_check_pound_key_buffer_flush())
                    {
                        wgui_inputs_ml_delete_all_characters();
                    }
                }
            }

            if (wgui_inputbox_input_method_change_callback)
            {
                wgui_inputbox_input_method_change_callback();
            }

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
    #if !defined(__MMI_CLIPBOARD__)
        if (!(((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_PAGING_IN_MULTLINE_INPUT_BOX
              || ((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_LINE_BASED_IN_MULTLINE_INPUT_BOX))
    #endif
        {
            MMI_BOOL isDisableBefore;
            MMI_BOOL isDisableAfter;
            static MMI_BOOL ignore = MMI_FALSE;

            isDisableBefore = wgui_inputs_ml_is_disable();
            ret = (MMI_BOOL)gui_multi_line_input_box_translate_pen_event(
                            editor_ptr,
                            ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event,
                            ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.x,
                            ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.y,
                            &input_box_event);
            /* translate pen event will change the disable state by category callback */
            isDisableAfter = wgui_inputs_ml_is_disable();

            /* If the editor disable state is change in pen callback, should ignore the pen event
               because currently, there is no return value of pen_control_area_callback,
               use this flag as a temp solution */
            if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_DOWN)
            {
                if (isDisableBefore == isDisableAfter)
                {
                    ignore = MMI_FALSE;
                }
                else
                {
                    ignore = MMI_TRUE;
                }
            }
            if (ret && !ignore)
            {
                ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->editor_pen_event = (mmi_imc_editor_pen_event_enum)input_box_event;

            #if defined(__MMI_CLIPBOARD__)
                /* DONOT handle scroll bar event for EBOOK and MMS Viewer screen */
                if ((((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_PAGING_IN_MULTLINE_INPUT_BOX
                    || ((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_LINE_BASED_IN_MULTLINE_INPUT_BOX))
                {
                    if (GUI_MULTI_LINE_INPUT_BOX_PEN_SCROLL_BAR == input_box_event)
                    {
                        return MMI_FALSE;
                    }
                }
            #endif

            #if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
				/* In WCSS, we can only calculate cursor position when pen up, */
				/* Because editor will draw cursor once it's changed           */
				if ((editor_ptr->flags & UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE) 
					|| editor_ptr->predefine_char_pos != NULL)
				{
					if (GUI_MULTI_LINE_INPUT_BOX_PEN_SCROLL_BAR != input_box_event 
						&& ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_UP)
					{
						gui_show_multi_line_input_box_ext(editor_ptr, 
							                       ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.x, 
												   ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.y);
						
						wgui_inputs_ml_redraw();
						msg_ptr->param_1 = 1;
					}

                    if ((((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_DOWN) ||
                        (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_LONG_TAP))
                    {
                        *((U32 *)msg_ptr->param_1) = 1;
                    }
					g_wgui_inputs_ml_pen_down_cursor_p = NULL;
				}
				else
            #endif  /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */
				{
				    U8* old_cursor_p = editor_ptr->cursor_p;
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
                    #if(UI_DOUBLE_BUFFER_SUPPORT)
                        gui_lock_double_buffer();
                    #endif
                        editor_ptr->ext_flags |= GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
                        wgui_inputs_ml_show_no_draw();
						editor_ptr->ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
                    #if(UI_DOUBLE_BUFFER_SUPPORT)
                        gui_unlock_double_buffer();
                    #endif
                        *((U32 *)msg_ptr->param_1) = 1;

#if defined(__MMI_CAT203_SUPPORT__)
                        if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_DIALER_SEARCH_MULTI_LINE_INPUT_BOX)
                        {
                            wgui_cat203_set_editor_focus_state(MMI_TRUE);
                            wgui_cat203_set_menu_focus_state(MMI_FALSE);
                            dynamic_list_goto_item_no_redraw(0);
                            wgui_text_menuitem_reset_scrolling();
                            redraw_dynamic_list(); 
                        } 
#endif /* defined(__MMI_CAT203_SUPPORT__) */
					}
					else if (GUI_MULTI_LINE_INPUT_BOX_PEN_SCROLL_BAR != input_box_event 
                             && GUI_MULTI_LINE_INPUT_BOX_PEN_CONTROL_AREA != input_box_event
							 && ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_UP)
					{
						if (g_wgui_inputs_ml_pen_down_cursor_p)
						{
							editor_ptr->cursor_p = g_wgui_inputs_ml_pen_down_cursor_p;
							g_wgui_inputs_ml_pen_down_cursor_p = NULL;
						    wgui_inputs_ml_redraw();
						    msg_ptr->param_1 = 1;
					    }
					}
					else if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_MOVE)
					{
						g_wgui_inputs_ml_pen_down_cursor_p = NULL;
					}
#ifdef __MMI_CLIPBOARD__
                    else if (GUI_MULTI_LINE_INPUT_BOX_PEN_SCROLL_BAR != input_box_event 
                             && GUI_MULTI_LINE_INPUT_BOX_PEN_CONTROL_AREA != input_box_event
							 && ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_LONG_TAP)
                    {
                        *((U32 *)msg_ptr->param_1) = 1;
                    }
#endif /* __MMI_CLIPBOARD__ */
				}
            }
			else
			{
				g_wgui_inputs_ml_pen_down_cursor_p = NULL;
            }
        }
        lresult = ret;
        
        break;

    case MMI_IMC_MESSAGE_GET_HANDWRITING_STYLE:
        
    #if defined(__MMI_HANDWRITING_MULTI_BLOCK__)
        if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_VOIP_DIALER_MULTLINE_INPUT_BOX)
        {
            lresult = MMI_IMC_PEN_HANDWRITING_STYLE_FULL_SCREEN;
        }
        else
        {
            lresult = MMI_IMC_PEN_HANDWRITING_STYLE_MULTI_BLOCK;
        }
    #else
        lresult = MMI_IMC_PEN_HANDWRITING_STYLE_FULL_SCREEN;
    #endif

        break;
        
#endif
    case MMI_IMC_MESSAGE_INSERT_NEW_LINE:
        gui_multi_line_input_box_insert_newline(editor_ptr);
        wgui_inputs_ml_redraw();
        multiline_inputbox_input_callback();
        break;
    case MMI_IMC_MESSAGE_IS_EDITOR_EMPTY:
        if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_LINE_BASED_IN_MULTLINE_INPUT_BOX ||
            ((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_INPUT_BOX_EBOOK ||
            ((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_INPUT_BOX_READ_ONLY ||
            ((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_INPUT_BOX_MMS_VIEWER)
        {
            lresult = MMI_TRUE;
        }
        else
		{	
            lresult = wgui_inputs_ml_is_empty();
		}
        break;
        
    case MMI_IMC_MESSAGE_GET_PREVIOUS_CHAR:
        lresult = gui_multi_line_input_box_get_previous_character(editor_ptr, (UI_character_type *)msg_ptr->param_0);
        break;
        
    case MMI_IMC_MESSAGE_GET_TEXT_LENGTH:
        lresult = (U32)(editor_ptr->text_length / ENCODING_LENGTH);
        break;
        
    case MMI_IMC_MESSAGE_SET_MASK:
        wgui_inputs_ml_set_mask(1);
        break;    
    case MMI_IMC_MESSAGE_WCSS_CHECK:
#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
        if ((editor_ptr->flags & UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE) 
			|| editor_ptr->predefine_char_pos != NULL)
        {
            lresult = MMI_TRUE;
        }
        else
#endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 
        lresult = MMI_FALSE;
        break;

    case MMI_IMC_MESSAGE_INSERT_PAIRED_SYMBOLS:
        {
            temp_str = (UI_string_type)msg_ptr->param_0;
            
            str_len = (S32)mmi_ucs2strlen((const S8 *)temp_str);
            
            for (i = 0; i < str_len; i++)
            {
                /* TODO: Insert successfully? */
                if (temp_str[i] != 0)
                {
                    if (MMI_TRUE == multiline_inputbox_direct_input_no_draw((UI_character_type)temp_str[i]))
                    {
                        total_len ++;
                    }
                    else
                    {
                        break;
                    }
                }	
                else
                {
                    break;
                }
            }
            
            wgui_inputs_ml_redraw();
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
            if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INCLUDE_INFO_AREA))
#endif 
            {
                if (total_len >0)
                    multiline_inputbox_input_callback();
            }

#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
            if ((editor_ptr->flags & UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE) 
                || editor_ptr->predefine_char_pos != NULL)
            {
                lresult = MMI_FALSE;
            }
            else
#endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 
            {
                if (total_len == str_len)
                {
                    wgui_inputs_ml_previous_character();
                    lresult = MMI_TRUE;
                }
                else
                {
                    lresult = MMI_FALSE;
                }  
            }  
        }    
        break;

    case MMI_IMC_MESSGAE_IS_WRITING_LANG_SELECTION_SCREEN_DISABLED:
#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
        if ((editor_ptr->flags & UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE) 
            || editor_ptr->predefine_char_pos != NULL)
        {
            lresult = MMI_TRUE;
        }
        else
#endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 
        lresult = MMI_FALSE;
        break;

	case MMI_IMC_MESSAGE_IS_OVERWRITE_MODE:
#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
        if ((editor_ptr->flags & UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE) 
			|| editor_ptr->predefine_char_pos != NULL)
        {
            lresult = MMI_TRUE;
        }
        else
#endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 
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
    case MMI_IMC_MESSAGE_INSERT_DECIMAL_SYMBOL:    
        first_char = MMI_multiline_inputbox.text[0] | (MMI_multiline_inputbox.text[1] << 8);
        second_char = MMI_multiline_inputbox.text[2] | (MMI_multiline_inputbox.text[3] << 8);
        if (wgui_multiline_inputbox_decimal_flag)
                {
            UI_editor_play_tone_invalid_data();
                    break;
                }
        if (gui_multi_line_input_box_test_first_position(&MMI_multiline_inputbox)  ||
            (first_char == (UI_character_type)'-' && second_char == 0))
        {
            wgui_inputs_ml_direct_input((UI_character_type) '0');
        }
        if (wgui_inputs_ml_direct_input((UI_character_type) '.') == MMI_TRUE)
        {
            wgui_multiline_inputbox_decimal_flag = 1;
        }

        break;
    case MMI_IMC_MESSAGE_SET_KEY:
        if (!(((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_LINE_BASED_IN_MULTLINE_INPUT_BOX) &&
            !(((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_INPUT_BOX_READ_ONLY) &&
            !(((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_INPUT_BOX_EBOOK) &&
            !(((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_INPUT_BOX_MMS_VIEWER))
        {
        #ifdef __OP01_FWPBW__
            if (msg_ptr->param_0 == 1)
            {
                wgui_inputs_ml_set_RSK_no_show_counter();
            }
            else
        #endif
            {
                gdi_layer_lock_frame_buffer();
                wgui_inputs_ml_set_RSK();
                gdi_layer_unlock_frame_buffer();
            }
            wgui_inputs_ml_register_keys();
        }
        
		if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_DICT_MULTILINE_INPUT_BOX)
		{
#ifdef __MMI_PHB_QUICK_SEARCH__     //**/            
                wgui_cat201_register_key_handler();
#endif /*__MMI_PHB_QUICK_SEARCH__*/
		}
    #ifdef __MMI_CLIPBOARD__
        /* For support text viewer category clipboard function */
        else if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_INPUT_BOX_READ_ONLY)
        {
            wgui_inputs_ml_register_viewer_keys();
            /* Register highlight viewer keys */
            if (g_dm_data.s32CatId == MMI_CATEGORY228_ID)
            {
                wgui_inputs_ml_register_hilite_keys();
            }
        }
        else if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_INPUT_BOX_MMS_VIEWER)
        {
        #ifdef __UI_MMS_VIEWER_CATEGORY__
            wgui_mv_register_keys();
        #endif
        }
    #endif /* __MMI_CLIPBOARD__ */

#if defined(__MMI_TOUCH_SCREEN__) && defined(__UI_PAGING_IN_MULTILINE_EDITOR__)
		if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_PAGING_IN_MULTLINE_INPUT_BOX)
		{
			if (gui_page_info.scroll_type == WGUI_PAGING_SCROLL_LINE_BY_LINE)
			{
				SetKeyHandler(wgui_inputs_ml_paging_previous_line_in_paging, KEY_UP_ARROW, KEY_EVENT_DOWN);
				SetKeyHandler(wgui_inputs_ml_paging_next_line_in_paging_scroll, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
				SetKeyHandler(wgui_inputs_ml_paging_previous_line_in_paging, KEY_VOL_UP, KEY_EVENT_DOWN);
				SetKeyHandler(wgui_inputs_ml_paging_next_line_in_paging_scroll, KEY_VOL_DOWN, KEY_EVENT_DOWN);
				
			}
			else
			{
				SetKeyHandler(wgui_inputs_ml_paging_previous_page, KEY_UP_ARROW, KEY_EVENT_DOWN);
				SetKeyHandler(wgui_inputs_ml_paging_next_page, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
				SetKeyHandler(wgui_inputs_ml_paging_previous_page, KEY_VOL_UP, KEY_EVENT_DOWN);
				SetKeyHandler(wgui_inputs_ml_paging_next_page, KEY_VOL_DOWN, KEY_EVENT_DOWN);
			}
		}
#endif /* defined(__MMI_TOUCH_SCREEN__) && defined(__UI_PAGING_IN_MULTILINE_EDITOR__) */

#if defined(__MMI_EBOOK_READER__)    	
        if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_LINE_BASED_IN_MULTLINE_INPUT_BOX ||
            ((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_INPUT_BOX_EBOOK)
        {
            SetKeyHandler(wgui_inputs_ml_linebase_previous_page, KEY_UP_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(wgui_inputs_ml_linebase_next_page, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(wgui_inputs_ml_linebase_previous_page, KEY_VOL_UP, KEY_EVENT_DOWN);
            SetKeyHandler(wgui_inputs_ml_linebase_next_page, KEY_VOL_DOWN, KEY_EVENT_DOWN);
            SetKeyHandler(wgui_inputs_ml_linebase_previous_line, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(wgui_inputs_ml_linebase_next_line, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

            SetKeyHandler(wgui_inputs_ml_linebase_previous_page, KEY_UP_ARROW, KEY_REPEAT);
            SetKeyHandler(wgui_inputs_ml_linebase_next_page, KEY_DOWN_ARROW, KEY_REPEAT);
            SetKeyHandler(wgui_inputs_ml_linebase_previous_page, KEY_VOL_UP, KEY_REPEAT);
            SetKeyHandler(wgui_inputs_ml_linebase_next_page, KEY_VOL_DOWN, KEY_REPEAT);
            SetKeyHandler(wgui_inputs_ml_linebase_previous_line, KEY_LEFT_ARROW, KEY_REPEAT);
            SetKeyHandler(wgui_inputs_ml_linebase_next_line, KEY_RIGHT_ARROW, KEY_REPEAT);
        }
#endif
#if defined(__MMI_CAT203_SUPPORT__)
        if ((((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type) == MMI_EDITOR_DIALER_SEARCH_MULTI_LINE_INPUT_BOX)
        {
            if (wgui_cat203_is_editor_active() == MMI_FALSE)
            {
                wgui_cat203_set_editor_focus_state(MMI_FALSE);
                wgui_cat203_set_menu_focus_state(MMI_TRUE);
                register_fixed_list_highlight_handler(dynamic_list_highlight_handler);
                register_dynamic_list_keys();
            }
        }            
#endif /* defined(__MMI_CAT203_SUPPORT__) */

        break;
    case MMI_IMC_MESSAGE_CHECK_CSK_ENABLE:
        if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_LINE_BASED_IN_MULTLINE_INPUT_BOX ||
            ((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_INPUT_BOX_EBOOK ||
            ((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_INPUT_BOX_READ_ONLY ||
            ((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_INPUT_BOX_MMS_VIEWER)
        {
            lresult = MMI_FALSE;
        }
        else
		{
            lresult = MMI_TRUE;
		}
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
			        &&(editor_ptr->ext_flags & GUI_MULTI_LINE_INPUT_BOX_INPUT_METHOD_MODE))/*(editor_ptr->cursor_p != editor_ptr->text && 
                 (editor_ptr->highlight_start_position != editor_ptr->highlight_end_position) &&
                 (editor_ptr->highlight_start_position <= editor_ptr->cursor_p &&
                   editor_ptr->highlight_end_position >= editor_ptr->cursor_p))*/
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
        wgui_inputs_ml_direct_input((UI_character_type)(0x20));
        break;
    case MMI_IMC_MESSAGE_CHECK_FLOAT:
            lresult = wgui_multiline_inputbox_decimal_flag;
        break;
    case MMI_IMC_MESSAGE_SET_MULTITAP_STATE:
        editor_ptr->flags |= UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP;
        break;

    case MMI_IMC_MESSAGE_IS_LOCK_GDI_FRAME_BUFFER_DISABLED:
        if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_PAGING_IN_MULTLINE_INPUT_BOX ||
            ((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_LINE_BASED_IN_MULTLINE_INPUT_BOX ||
            ((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_INPUT_BOX_EBOOK ||
            ((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_INPUT_BOX_READ_ONLY ||
            ((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_INPUT_BOX_MMS_VIEWER)
        {
            lresult = MMI_TRUE;
        }
        else
        {
            lresult = MMI_FALSE;
        }    
        break;

    case MMI_IMC_MESSAGE_GET_EDITOR_SCROLL_BAR_WIDTH:
        lresult = (U32)wgui_inputs_ml_get_scroll_bar_width();
        break;

#ifdef __MMI_CLIPBOARD__

#if defined(__MMI_TOUCH_SCREEN__)
    case MMI_IMC_MESSAGE_CLIPBOARD_LOCATE_CURSOR_P_BY_POS:
        ret = (MMI_BOOL)gui_multi_line_input_box_translate_pen_event(
                            editor_ptr,
                            ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event,
                            ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.x,
                            ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.y,
                            &input_box_event);
        if (ret)
        {
            ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->editor_pen_event = (mmi_imc_editor_pen_event_enum)input_box_event;
			if (GUI_MULTI_LINE_INPUT_BOX_PEN_SCROLL_BAR != input_box_event)
			{
                S32 old_text_offset_y = editor_ptr->text_offset_y;
                UI_buffer_type old_cursor_p = editor_ptr->cursor_p;
				gui_show_multi_line_input_box_ext(editor_ptr, 
										   ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.x, 
										   ((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.y);
                editor_ptr->text_offset_y = old_text_offset_y;
    
                if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_INPUT_BOX_MMS_VIEWER)
                {
                    if (((editor_ptr->cursor_p - editor_ptr->text) < editor_ptr->visible_start_ex * ENCODING_LENGTH) ||
                        ((editor_ptr->cursor_p - editor_ptr->text) > editor_ptr->visible_end_ex * ENCODING_LENGTH))
                    {
                        editor_ptr->cursor_p = old_cursor_p;
                    }
                }
    
                if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_LONG_TAP)
                {
                    ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->ccp_start_cursor_p = editor_ptr->cursor_p;
                }
                else if ((((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_MOVE) ||
                    (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_UP) &&
                    (((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->ccp_start_cursor_p != NULL))
                {
                    ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->ccp_end_cursor_p = editor_ptr->cursor_p;
                    /* Caculate the highlight text length */
                    ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->highlight_text_length =
                        (((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->ccp_end_cursor_p -
                        ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->ccp_start_cursor_p) / ENCODING_LENGTH;
                }
			}

            if ((((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event != MMI_PEN_EVENT_LONG_TAP) &&
                (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event != MMI_PEN_EVENT_UP) &&
                (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type != MMI_EDITOR_INPUT_BOX_MMS_VIEWER) &&
                (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type != MMI_EDITOR_LINE_BASED_IN_MULTLINE_INPUT_BOX) &&
                (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type != MMI_EDITOR_INPUT_BOX_EBOOK))
            {
                /* Adjust editor view when out of boundary */
                if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.y < (editor_ptr->y + WGUI_INPUTS_ADJUST_VIEW_OFFSET))
                {
                    editor_ptr->text_offset_y += WGUI_INPUTS_ADJUST_VIEW_OFFSET;
                }
                else if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.y > (editor_ptr->y + editor_ptr->height - WGUI_INPUTS_ADJUST_VIEW_OFFSET))
                {
                    editor_ptr->text_offset_y -= WGUI_INPUTS_ADJUST_VIEW_OFFSET;
                }
                if (editor_ptr->text_offset_y > 0 || editor_ptr->edit_height >= editor_ptr->text_height)
                {
                    editor_ptr->text_offset_y = 0;
                }
                else if (editor_ptr->text_offset_y < (editor_ptr->edit_height - editor_ptr->text_height) && (editor_ptr->edit_height < editor_ptr->text_height))
                {
                    editor_ptr->text_offset_y = editor_ptr->edit_height - editor_ptr->text_height;
                }
            }
        }
        else
        {
            if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->mmi_pen_event == MMI_PEN_EVENT_LONG_TAP)
            {
                ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->ccp_start_cursor_p = editor_ptr->cursor_p;
            }
        }
        break;

    case MMI_IMC_MESSAGE_CLIPBOARD_ADJUST_VIEW:
        if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type != MMI_EDITOR_INPUT_BOX_MMS_VIEWER &&
            ((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type != MMI_EDITOR_LINE_BASED_IN_MULTLINE_INPUT_BOX &&
            ((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type != MMI_EDITOR_INPUT_BOX_EBOOK)
        {
            if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.y < editor_ptr->y)
            {
                gui_multi_line_input_box_previous_line(editor_ptr);
                ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->ccp_end_cursor_p = editor_ptr->cursor_p;
                ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->highlight_text_length =
                    (((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->ccp_end_cursor_p -
                    ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->ccp_start_cursor_p) / ENCODING_LENGTH;
            }
            else if (((mmi_imc_editor_pen_event_struct_p)msg_ptr->param_0)->pos.y > (editor_ptr->y + editor_ptr->height))
            {
                gui_multi_line_input_box_next_line(editor_ptr);
                ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->ccp_end_cursor_p = editor_ptr->cursor_p;
                ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->highlight_text_length =
                    (((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->ccp_end_cursor_p -
                    ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->ccp_start_cursor_p) / ENCODING_LENGTH;
            }
        }
        break;
#endif /* __MMI_TOUCH_SCREEN__ */

    case MMI_IMC_MESSAGE_CLIPBOARD_INSERT_STRING_WITH_LENGTH:
        /* Lock frame buffer to prevent cursor flash after insert string */
    #if(UI_DOUBLE_BUFFER_SUPPORT)
        gui_lock_double_buffer();
    #endif
        lresult = wgui_inputs_ml_insert_string((UI_string_type)msg_ptr->param_0, (U32)msg_ptr->param_1, MMI_TRUE);
    #if(UI_DOUBLE_BUFFER_SUPPORT)
        gui_unlock_double_buffer();
    #endif
        wgui_inputs_ml_redraw();
        break;

    case MMI_IMC_MESSAGE_CLIPBOARD_SET_START_CURSOR_P:
        ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_start_cursor_p = editor_ptr->cursor_p;
        break;

    case MMI_IMC_MESSAGE_CLIPBOARD_MARK_TEXT:
        if (((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->highlight_text_length > 0)
        {
            editor_ptr->highlight_start_position = ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_start_cursor_p;
            editor_ptr->highlight_end_position = ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_end_cursor_p;
        #if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) && defined(__MMI_CLIPBOARD_FLOATING_MENU__)
            if (MMI_multi_line_inputbox_present)
            {
                dm_imui_window_hide();
            }
            else
        #endif
            {
                wgui_inputs_ml_redraw();
            }
        }
        else if (((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->highlight_text_length < 0)
        {
            editor_ptr->highlight_start_position = ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_end_cursor_p;
            editor_ptr->highlight_end_position = ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_start_cursor_p;
        #if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) && defined(__MMI_CLIPBOARD_FLOATING_MENU__)
            if (MMI_multi_line_inputbox_present)
            {
                dm_imui_window_hide();
            }
            else
        #endif
            {
                wgui_inputs_ml_redraw();
            }
        }
        else if ((((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_start_cursor_p) ==
                 (((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_end_cursor_p))
        {
            editor_ptr->highlight_start_position = ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_start_cursor_p;
            editor_ptr->highlight_end_position = ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_start_cursor_p;
        #if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) && defined(__MMI_CLIPBOARD_FLOATING_MENU__)
            if (MMI_multi_line_inputbox_present)
            {
                dm_imui_window_hide();
            }
            else
        #endif
            {
                wgui_inputs_ml_redraw();
            }
        }
        break;

    case MMI_IMC_MESSAGE_CLIPBOARD_MOVE_CORSOR:
        cursor_move_old_flags = editor_ptr->flags;
        editor_ptr->flags &= ~UI_MULTI_LINE_INPUT_BOX_VIEW_MODE;
        switch (msg_ptr->param_0)
        {
            case MMI_IMC_EDITOR_CURSOR_UP:
                gui_multi_line_input_box_previous_line(editor_ptr);
                break;
            case MMI_IMC_EDITOR_CURSOR_DOWN:
                gui_multi_line_input_box_next_line(editor_ptr);
                break;
            case MMI_IMC_EDITOR_CURSOR_LEFT:
                gui_multi_line_input_box_previous(editor_ptr);
                break;
            case MMI_IMC_EDITOR_CURSOR_RIGHT:
                gui_multi_line_input_box_next(editor_ptr);
                break;
        }

/* Handle inline multiline */
#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
        if (hilited_item_changed == 1)
        {
            UI_editor_play_tone_cannot_navigate();
            wgui_inputs_ml_redraw();
            hilited_item_changed = 0;
        }
#endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */

        editor_ptr->flags = cursor_move_old_flags;
        if (msg_ptr->param_1)
        {
            ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->ccp_end_cursor_p = editor_ptr->cursor_p;
            /* Caculate the highlight text length */
            ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->highlight_text_length =
                (((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->ccp_end_cursor_p -
                ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_1)->ccp_start_cursor_p) / ENCODING_LENGTH;
        }
        else
        {
            /* Redraw editor in locate start cursor mode */
            wgui_inputs_ml_redraw();
        }

        break;

    case MMI_IMC_MESSAGE_CLIPBOARD_SAVE_STATUS:
        ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->pre_flags = editor_ptr->flags;
        if (!mmi_imc_is_ime_state())
        {
            ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->pre_highlight_start_cursor_p = editor_ptr->highlight_start_position;
            ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->pre_highlight_end_cursor_p = editor_ptr->highlight_end_position;
        }
        else
        {
            ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->pre_flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        }

        if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_INPUT_BOX_MMS_VIEWER)
        {
            g_imc_clipboard_data.visible_start_p = editor_ptr->text + editor_ptr->visible_start_ex * ENCODING_LENGTH;
            g_imc_clipboard_data.visible_end_p = editor_ptr->text + editor_ptr->visible_end_ex * ENCODING_LENGTH;
        }

        ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->is_saved = 1;

        /* If view mode editor and locate start cursor position mode, we set the cursor at text start position */
        if (editor_ptr->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE && (msg_ptr->param_1))
        {
            editor_ptr->cursor_p = editor_ptr->text;
            editor_ptr->text_offset_y = 0;
        }

        if (editor_ptr->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE)
        {
            editor_ptr->flags &= ~UI_MULTI_LINE_INPUT_BOX_VIEW_MODE;
        }
        mmi_imc_clipboard_save_keys();
        wgui_inputs_ml_register_set_key_callback(mmi_imc_clipboard_restore_keys);

    #if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__) 
        mmi_frm_gesture_disable(); 
    #endif
        editor_ptr->flags |= UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        editor_ptr->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
        editor_ptr->highlight_start_position = NULL;
        editor_ptr->highlight_end_position = NULL;
        editor_ptr->state = GUI_INPUT_BOX_STATE_SELECTING_TEXT;
        break;

    case MMI_IMC_MESSAGE_CLIPBOARD_RESTORE_STATUS:
        editor_ptr->highlight_start_position = ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->pre_highlight_start_cursor_p;
        editor_ptr->highlight_end_position = ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->pre_highlight_end_cursor_p;
        editor_ptr->flags = ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->pre_flags;
        editor_ptr->state = GUI_INPUT_BOX_STATE_IDLE;
  
        /* If read only editor, stop cursor draw */
        if (editor_ptr->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW)
        {
            StopTimer(BLINKING_CURSOR);
        }

        /* If not view mode, always show cursor */
        if (!(editor_ptr->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE))
        {
            editor_ptr->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
        }

    #if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__) 
        mmi_frm_gesture_enable(); 
    #endif
        break;

    case MMI_IMC_MESSAGE_CLIPBOARD_GET_ALL_TEXT:
        if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_INPUT_BOX_MMS_VIEWER)
        {
            *((U8 **)(msg_ptr->param_0)) = g_imc_clipboard_data.visible_start_p;
            *((U32 *)msg_ptr->param_1) = g_imc_clipboard_data.visible_end_p - g_imc_clipboard_data.visible_start_p;
        }
    #ifdef __UI_LINEBASE_IN_MULTILINE_EDITOR__
        else if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_INPUT_BOX_EBOOK ||
            ((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_LINE_BASED_IN_MULTLINE_INPUT_BOX)
        {
            wgui_inputs_ml_jump_to_line(MMI_multiline_inputbox.visible_line_info->start_line_index, MMI_FALSE);
            *((U8 **)(msg_ptr->param_0)) = editor_ptr->text;
            *((U32 *)msg_ptr->param_1) = editor_ptr->visible_line_info->array[editor_ptr->visible_line_info->line_count].offset * ENCODING_LENGTH;
        }
    #endif    
        else
        {
            *((U8 **)(msg_ptr->param_0)) = editor_ptr->text;
            *((U32 *)msg_ptr->param_1) = editor_ptr->text_length - ENCODING_LENGTH;
        }
        break;
    case MMI_IMC_MESSAGE_CLIPBOARD_GET_HIGHLIGHT_TEXT:
    #ifdef __UI_LINEBASE_IN_MULTILINE_EDITOR__
        if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_INPUT_BOX_EBOOK ||
            ((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_LINE_BASED_IN_MULTLINE_INPUT_BOX)
        {
            wgui_inputs_ml_jump_to_line(MMI_multiline_inputbox.visible_line_info->start_line_index, MMI_FALSE);
        }
    #endif
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
        if (msg_ptr->param_0 == 0)
        {
            lresult = (editor_ptr->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE);
        }
        else 
        {
            if (((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->is_saved == 1)
            {
                lresult = (((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->pre_flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE);
            }
            else
            {
                lresult = (editor_ptr->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE);
            }
        }
        break;

    case MMI_IMC_MESSAGE_CLIPBOARD_SET_HIGHLIGHT:
        if (((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->highlight_text_length > 0)
        {
            editor_ptr->highlight_start_position = ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_start_cursor_p;
            editor_ptr->highlight_end_position = ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_end_cursor_p;
        }
        else if (((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->highlight_text_length < 0)
        {
            editor_ptr->highlight_start_position = ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_end_cursor_p;
            editor_ptr->highlight_end_position = ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_start_cursor_p;
        }

        if (((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_end_cursor_p != NULL)
        {
            editor_ptr->cursor_p = ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_end_cursor_p;
        }
        editor_ptr->flags |= UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        editor_ptr->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
        editor_ptr->flags &= ~UI_MULTI_LINE_INPUT_BOX_VIEW_MODE;
        ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->is_saved = 1;

        /* When close cascading menu, the set key callback will be reset when previous exit screen, need reset here */
        wgui_inputs_ml_register_set_key_callback(mmi_imc_clipboard_restore_keys);
        break;
    
    case MMI_IMC_MESSAGE_CLIPBOARD_GET_EDITOR_TYPE:
#if defined (__UI_UNIFIED_COMPOSER_EDITOR_CATEGORY__) && defined (__MMI_MSG_EDITOR_WITH_RECIPIENT__)
        if (((((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type) == MMI_EDITOR_UCE_MULTLINE_INPUT_BOX) &&
            (wgui_cat280_get_highlight_state() != WGUI_UCE_EDITOR))
        {
            ((mmi_imc_editor_menu_history_data_struct_p)msg_ptr->param_0)->is_read_only = MMI_TRUE;
            ((mmi_imc_editor_menu_history_data_struct_p)msg_ptr->param_0)->is_paging = MMI_FALSE;
            ((mmi_imc_editor_menu_history_data_struct_p)msg_ptr->param_0)->is_empty = MMI_TRUE;
            ((mmi_imc_editor_menu_history_data_struct_p)msg_ptr->param_0)->is_wcss = MMI_FALSE;
            ((mmi_imc_editor_menu_history_data_struct_p)msg_ptr->param_0)->is_password = MMI_FALSE;
        }
        else
#endif /* __UI_UNIFIED_COMPOSER_EDITOR_CATEGORY__ */
        {
            if (editor_ptr->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE)
            {
                ((mmi_imc_editor_menu_history_data_struct_p)msg_ptr->param_0)->is_read_only = MMI_TRUE;
            }
            else
            {
                ((mmi_imc_editor_menu_history_data_struct_p)msg_ptr->param_0)->is_read_only = MMI_FALSE;
            }
#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__ /**/
            if (editor_ptr->ext_flags & GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE)
            {
                ((mmi_imc_editor_menu_history_data_struct_p)msg_ptr->param_0)->is_paging = MMI_TRUE;
            }
            else
#endif /*__UI_PAGING_IN_MULTILINE_EDITOR__*/ /**/                
            {
                ((mmi_imc_editor_menu_history_data_struct_p)msg_ptr->param_0)->is_paging = MMI_FALSE;
            }

            if (wgui_inputs_ml_is_empty())
            {
                ((mmi_imc_editor_menu_history_data_struct_p)msg_ptr->param_0)->is_empty = MMI_TRUE;
            }
            else
            {
                ((mmi_imc_editor_menu_history_data_struct_p)msg_ptr->param_0)->is_empty = MMI_FALSE;
            }

    #if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
            if ((editor_ptr->flags & UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE) 
			    || editor_ptr->predefine_char_pos != NULL)
            {
                ((mmi_imc_editor_menu_history_data_struct_p)msg_ptr->param_0)->is_wcss = MMI_TRUE;
            }
            else
    #endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 
                ((mmi_imc_editor_menu_history_data_struct_p)msg_ptr->param_0)->is_wcss = MMI_FALSE;

            if (editor_ptr->flags & UI_MULTI_LINE_INPUT_BOX_MASK_CHARACTERS)
            {
                ((mmi_imc_editor_menu_history_data_struct_p)msg_ptr->param_0)->is_password = MMI_TRUE;
            }
            else
            {
                ((mmi_imc_editor_menu_history_data_struct_p)msg_ptr->param_0)->is_password = MMI_FALSE;
            }
        }

        lresult = MMI_TRUE;
        break;

    case MMI_IMC_MESSAGE_CLIPBOARD_CUT_HIGHLIGHT_STRING:
        if (msg_ptr->param_1 == 1)
        {
            editor_ptr->cursor_p = ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_start_cursor_p;
            cut_cursor_p = ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_end_cursor_p;
        }
        else if (msg_ptr->param_1 == 0)
        {
            cut_cursor_p = ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_start_cursor_p;
        }
        else if (msg_ptr->param_1 == 3)
        {
            cut_cursor_p = ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_end_cursor_p;
            editor_ptr->cursor_p = cut_cursor_p + WGUI_INPUTS_CLIPBOARD_MAX_SIZE;
        }
        else if (msg_ptr->param_1 == 2)
        {
            cut_cursor_p = ((mmi_imc_clipboard_data_struct_p)msg_ptr->param_0)->ccp_start_cursor_p;
            editor_ptr->cursor_p = cut_cursor_p + WGUI_INPUTS_CLIPBOARD_MAX_SIZE;
        }
    
        old_show_action_flag = editor_ptr->show_action_flag;
    #if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
        if ((editor_ptr->flags & UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE) 
            || editor_ptr->predefine_char_pos != NULL)
        {
            /* Call show to recaculate the editor information after change cursor position */
            wgui_inputs_ml_show();
            editor_ptr->show_action_flag = 1;
        }
        else
    #endif
        {
            wgui_inputs_ml_show_no_draw();
            editor_ptr->show_action_flag = 0;
        }

        if (cut_cursor_p != NULL)
        {
            cut_char_count = (editor_ptr->cursor_p - cut_cursor_p) / ENCODING_LENGTH;
        }
        while (cut_char_count--)
        {
#ifdef __MMI_EDITOR_MULTILINE_SUPPORT_ICON_CALLBACK__             
            /* If IMPS editor */
            if (editor_ptr->icon_callback && (editor_ptr->cursor_p <= cut_cursor_p))
            {
                break;
            }
#endif /*__MMI_EDITOR_MULTILINE_SUPPORT_ICON_CALLBACK__*/    
    
            gui_multi_line_input_box_delete_character(&MMI_multiline_inputbox);
        }
        editor_ptr->show_action_flag = old_show_action_flag;

        wgui_inputs_ml_redraw();
        
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
        if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INCLUDE_INFO_AREA))
#endif 
            multiline_inputbox_input_callback();
        break;

    case MMI_IMC_MESSAGE_CLIPBOARD_CUT_ALL:
        if (msg_ptr->param_0 == 0)
        {
        #if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
            if ((editor_ptr->flags & UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE) 
			    || editor_ptr->predefine_char_pos != NULL)
            {
                /* If cursor is not in last position, it will not clear all the content due to the WCSS cursor move calback */
                MMI_multiline_inputbox.cursor_p = MMI_multiline_inputbox.last_position_p - ENCODING_LENGTH;
                /* Call show to recaculate the editor information after change cursor position */
                wgui_inputs_ml_show();
            }
        #endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 
            wgui_inputs_ml_delete_all_characters();
        }
        else if (msg_ptr->param_0 == 1)
        {
            editor_ptr->cursor_p = editor_ptr->text + WGUI_INPUTS_CLIPBOARD_MAX_SIZE;
            old_show_action_flag = editor_ptr->show_action_flag;
            editor_ptr->show_action_flag = 0;
            while (editor_ptr->cursor_p > editor_ptr->text)
            {
                gui_multi_line_input_box_delete_character(&MMI_multiline_inputbox);
            }
            editor_ptr->show_action_flag = old_show_action_flag;

            wgui_inputs_ml_redraw();
        }
        break;

    case MMI_IMC_MESSAGE_CLIPBOARD_IS_PASSWORD_EDITOR:
        if (editor_ptr->flags & UI_MULTI_LINE_INPUT_BOX_MASK_CHARACTERS)
        {
            lresult = MMI_TRUE;
        }
        else
        {
            lresult = MMI_FALSE;
        }
        break;

     case MMI_IMC_MESSAGE_CLIPBOARD_IS_DISABLE:
        if (editor_ptr->ext_flags & GUI_MULTI_LINE_INPUT_BOX_DISABLE_CLIPBOARD)
        {
            lresult = MMI_TRUE;
        }
    #ifdef __UI_LINEBASE_IN_MULTILINE_EDITOR__
        else if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_INPUT_BOX_EBOOK ||
                 ((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_LINE_BASED_IN_MULTLINE_INPUT_BOX)
        {
            if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE)
            {
                lresult = MMI_TRUE;
            }
            else
            {
                lresult = MMI_FALSE;
            }
        }
    #endif /* __UI_LINEBASE_IN_MULTILINE_EDITOR__ */
        else
        {
            lresult = MMI_FALSE;
        }
        break;

#ifdef __MMI_CLIPBOARD_FLOATING_MENU__
    case MMI_IMC_MESSAGE_CLIPBOARD_GET_HILITE_RECT:
        ((mmi_imc_clipboard_hilite_rect_p)msg_ptr->param_0)->s_x = editor_ptr->hilite_s_x;
        ((mmi_imc_clipboard_hilite_rect_p)msg_ptr->param_0)->s_y = editor_ptr->hilite_s_y;
        ((mmi_imc_clipboard_hilite_rect_p)msg_ptr->param_0)->e_x = editor_ptr->hilite_e_x;
        ((mmi_imc_clipboard_hilite_rect_p)msg_ptr->param_0)->e_y = editor_ptr->hilite_e_y;
        break;
#endif /* __MMI_CLIPBOARD_FLOATING_MENU__ */

#endif /* __MMI_CLIPBOARD__ */
    case MMI_IMC_MESSAGE_INSERT_CHAR_AT_DESIRED_POSITION:
        gui_multi_line_input_box_insert_character_in_pos(editor_ptr, (UI_character_type)msg_ptr->param_1, msg_ptr->param_0);
        redraw_multiline_inputbox();
        multiline_inputbox_input_callback();
        break;
    case MMI_IMC_MESSAGE_DELETE_CHAR_AT_DESIRED_POSITION:
        gui_multi_line_input_box_delete_character_in_pos(editor_ptr, msg_ptr->param_0);		
        redraw_multiline_inputbox();
        multiline_inputbox_input_callback();
        break;
    case MMI_IMC_MESSAGE_GET_CHAR_AT_DESIRED_POSITION:
        lresult = editor_ptr->text[msg_ptr->param_0];
        break;
    case MMI_IMC_MESSAGE_HAS_SSP_ACTED:
    #if defined(__MMI_EDITOR_SSP_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        lresult = gui_input_box_ssp_is_scrolling();
    #endif
        break;
    case MMI_IMC_MESSAGE_HIDE_MULTITAP_CANDIDATE_BOX:
#if defined(__MMI_CAT203_SUPPORT__)
        if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_DIALER_SEARCH_MULTI_LINE_INPUT_BOX)
        {
            lresult = MMI_TRUE;
        }
#endif /* defined(__MMI_CAT203_SUPPORT__) */
        break;
	case MMI_IMC_MESSAGE_IS_SKIP_GENERAL_PEN_UP_EVENT:
		if (((mmi_editor_handler_struct *)input_box_handle)->input_box_sub_type == MMI_EDITOR_INPUT_BOX_MMS_VIEWER)
        {
            lresult = MMI_TRUE;
        }
        break;
    default:
        break;
    }
		UI_UNUSED_PARAMETER(ret);
    return lresult;
}


/*****************************************************************************
* FUNCTION
*  wgui_inputs_ml_insert_string
* DESCRIPTION
*  Insert string at current cursor position.
* PARAMETERS
* str           [in]        string to insert
* len           [in]        string length
* is_redraw     [in]        if need redraw after insert        
* RETURNS
*  characters inserted
*****************************************************************************/
U32 wgui_inputs_ml_insert_string(UI_string_type str, U32 len, MMI_BOOL is_redraw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, total_len = 0;
    U32 old_show_action_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_show_action_flag = MMI_multiline_inputbox.show_action_flag;
    MMI_multiline_inputbox.show_action_flag = 0;
    for (i = 0; i < len; i++)
    {
        if (MMI_TRUE == wgui_inputs_is_input_char_valid((UI_character_type)str[i]))
        {
            if (((UI_character_type)str[i] == 0x0D) || ((UI_character_type)str[i] == 0x1b))
            {
                continue;
            }
            else if (MMI_TRUE == wgui_inputs_ml_direct_input_no_draw((UI_character_type)str[i]))
            {
                total_len ++;
            }
            else
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
    MMI_multiline_inputbox.show_action_flag = old_show_action_flag;

#ifdef __MMI_EDITOR_MULTILINE_DIALER_STYLE_SUPPORT__
    if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_DIALER_STYLE)
    {
        wgui_inputs_ml_handle_plus_key();
    }
#endif /* __MMI_EDITOR_MULTILINE_DIALER_STYLE_SUPPORT__ */

    if (is_redraw)
    {
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
        gui_mlc_all_line_update();
#endif
        wgui_inputs_ml_redraw();
    }

#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
    if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INCLUDE_INFO_AREA))
#endif 
    {
        if (total_len >0)
            multiline_inputbox_input_callback();
    }

    return total_len;
}


/*****************************************************************************
* FUNCTION
*  wgui_inputs_ml_delete_string
* DESCRIPTION
*  Delete string of given length
* PARAMETERS
* len               [in]        string length to delete
* no_redraw         [in]        if need to redraw after delete
* RETURNS
*  characters deleted
*****************************************************************************/
U32 wgui_inputs_ml_delete_string(U32 len, MMI_BOOL no_redraw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 old_show_action_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_show_action_flag = MMI_multiline_inputbox.show_action_flag;
    MMI_multiline_inputbox.show_action_flag = 0;

    for (i = 0; i < len; i ++)
    {
        gui_multi_line_input_box_delete_character(&MMI_multiline_inputbox);
    }

    MMI_multiline_inputbox.show_action_flag = old_show_action_flag;

    if (!no_redraw)
    {
        wgui_inputs_ml_redraw();
    }
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
    if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INCLUDE_INFO_AREA))
#endif 
        multiline_inputbox_input_callback();

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_handle_right_arrow_repeat
 * DESCRIPTION
 *  handle right arrow key repeat of multiline input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inputs_ml_handle_right_arrow_repeat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_fast_del_nav_handler(WGUI_INPUTS_OPER_FAST_NAV_RIGHT, WGUI_INPUTS_EDITOR_ML, WGUI_INPUTS_KPD_REPEAT_PERIOD);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_handle_up_arrow_repeat
 * DESCRIPTION
 *  handle up arrow key repeat of multiline input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inputs_ml_handle_up_arrow_repeat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_fast_del_nav_handler(WGUI_INPUTS_OPER_FAST_NAV_UP, WGUI_INPUTS_EDITOR_ML, WGUI_INPUTS_KPD_REPEAT_PERIOD);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_handle_down_arrow_repeat
 * DESCRIPTION
 *  handle down arrow key repeat of multiline input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inputs_ml_handle_down_arrow_repeat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_fast_del_nav_handler(WGUI_INPUTS_OPER_FAST_NAV_DOWN, WGUI_INPUTS_EDITOR_ML, WGUI_INPUTS_KPD_REPEAT_PERIOD);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_handle_left_arrow_repeat
 * DESCRIPTION
 *  handle left arrow key repeat of multiline input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inputs_ml_handle_left_arrow_repeat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_fast_del_nav_handler(WGUI_INPUTS_OPER_FAST_NAV_LEFT, WGUI_INPUTS_EDITOR_ML, WGUI_INPUTS_KPD_REPEAT_PERIOD);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_handle_right_softkey_repeat
 * DESCRIPTION
 *  handle right softkey repeat of multiline input box (keypad RSK)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_handle_right_softkey_repeat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_inputs_ml_is_empty())
    {
        return;
    }
    wgui_inputs_fast_del_nav_handler(WGUI_INPUTS_OPER_FAST_DEL, WGUI_INPUTS_EDITOR_ML, WGUI_INPUTS_KPD_REPEAT_PERIOD);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_handle_right_softkey_touch_repeat
 * DESCRIPTION
 *  handle right softkey repeat of multiline input box (Touch panel RSK)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_handle_right_softkey_touch_repeat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_inputs_ml_is_empty())
    {
        return;
    }
    wgui_inputs_fast_del_nav_handler(WGUI_INPUTS_OPER_FAST_DEL, WGUI_INPUTS_EDITOR_ML, WGUI_INPUTS_TP_REPEAT_PERIOD);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_setup_input_ext_type
 * DESCRIPTION
 *  wgui_inputs_ml_setup_input_ext_type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_handle_input_ext_type(U32 input_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_current_input_ext_type & INPUT_TYPE_EXT_ASCII_ENCODING_BASE_LENGTH)
    {
        MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_USE_ASCII_ENCODING_BASE_LENGTH;
        if (input_type & INPUT_TYPE_ONE_LESS_CHARACTER)
        {
            MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_ONE_LESS_CHARACTER;
            UI_TEST_UCS2_COUNT_SET_LENGTH_TYPE2(
                MMI_multiline_inputbox.non_ascii_count,
                MMI_multiline_inputbox.allocated_length,
                MMI_multiline_inputbox.available_length);
        }
        else
        {
            UI_TEST_UCS2_COUNT_SET_LENGTH(
                MMI_multiline_inputbox.non_ascii_count,
                MMI_multiline_inputbox.allocated_length,
                MMI_multiline_inputbox.available_length);
        }
    }
}


#ifdef __UI_LINEBASE_IN_MULTILINE_EDITOR__
/* Line Base Mode Start */

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_set_dirty
 * DESCRIPTION
 *  Set the editor buffer dirty, if this flag is MMI_TURE, Editor will call 
 *  get_data_cb to re-get the data when show
 * PARAMETERS
 * is_dirty     [IN]                 set dirty or not           
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_set_dirty(MMI_BOOL is_dirty)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_multiline_inputbox.is_dirty = is_dirty;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_jump_to_line
 * DESCRIPTION
 *  jump to the line by the line_index
 * PARAMETERS
 * line_index     [in]        
 * b_show         [in]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_jump_to_line(S32 line_index, MMI_BOOL b_show)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 flags = MMI_multiline_inputbox.flags;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* it will corrupt editor content and cursor if run this function when in clipboard state */
    if (mmi_imc_is_clipboard_state() && (b_show == MMI_TRUE))
    {
        return;
    }

    if (MMI_multiline_inputbox.get_data_cb(&MMI_multiline_inputbox.text, &MMI_multiline_inputbox.text_length,
        line_index, line_index + GUI_MAX_VISIBLE_LINE - 1))
    {
        MMI_multiline_inputbox.text_length *= ENCODING_LENGTH;
        MMI_multiline_inputbox.line_info->start_line_index = line_index;
        MMI_multiline_inputbox.cursor_p = MMI_multiline_inputbox.text;
        
        if (b_show)
        {
            MMI_multiline_inputbox.visible_line_info->start_line_index = line_index;
            
#ifdef __MMI_FTE_SUPPORT__
            gui_show_multi_line_input_box(&MMI_multiline_inputbox);
            if (percentage_callback)
            {
                percentage_callback(MMI_multiline_inputbox.visible_line_info->start_line_index);
            }

#if(UI_DOUBLE_BUFFER_SUPPORT)
            gui_BLT_double_buffer(
                MMI_multiline_inputbox.x,
                MMI_multiline_inputbox.y,
                MMI_multiline_inputbox.x + MMI_multiline_inputbox.width,
                MMI_multiline_inputbox.y + MMI_multiline_inputbox.height);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
            
#else  
            if (percentage_callback)
                percentage_callback(MMI_multiline_inputbox.visible_line_info->start_line_index);
            
            show_multiline_inputbox();
#endif
        }
        else
            show_multiline_inputbox_no_draw();

        MMI_multiline_inputbox.flags = flags;
    }

}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_get_layout_info
 * DESCRIPTION
 *  get the current layout information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
gui_line_struct * wgui_inputs_ml_get_layout_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_multiline_inputbox.line_info;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_get_visible_info
 * DESCRIPTION
 *  get the current visible layout information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
gui_line_struct * wgui_inputs_ml_get_visible_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_multiline_inputbox.visible_line_info;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_linebase_register_callback
 * DESCRIPTION
 *  register query data callback for linebase mode
 * PARAMETERS
 *  f  [in]
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_linebase_register_callback(gui_inputs_get_data_callback f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_multiline_inputbox.get_data_cb = f;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_set_total_line_count
 * DESCRIPTION
 *  udpate the current total line
 * PARAMETERS
 * line_count     [in]        
 * b_show         [in]  
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_set_total_line_count(S32 line_count, MMI_BOOL b_show)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_FTE_EDITOR_SCROLLBAR_STYLE__
    S32 old_count = MMI_multiline_inputbox.total_line_count;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_multiline_inputbox.total_line_count = line_count; 

    if (b_show)
    {
        if (percentage_callback)
            percentage_callback(MMI_multiline_inputbox.visible_line_info->start_line_index);
        
    #if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_VK_POPUP_HINT__) && !defined(__MMI_FTE_SUPPORT__)
        if (mmi_imc_is_connected())
        {
            gui_lock_double_buffer();
            wgui_virtual_keyboard_recover_covered_area();
        }
    #endif /* __MMI_TOUCH_SCREEN__ || __MMI_VK_POPUP_HINT__ */

#ifdef __MMI_FTE_EDITOR_SCROLLBAR_STYLE__
        wgui_inputs_ml_jump_to_line(MMI_multiline_inputbox.visible_line_info->start_line_index, MMI_TRUE);
#else /*__MMI_FTE_EDITOR_SCROLLBAR_STYLE__*/

        if (MMI_multiline_inputbox.visible_line_info->start_line_index >= old_count - GUI_MAX_VISIBLE_LINE)
        {
            /* To prevent pop up hint restore and draw the wrong background, we should not draw vk in this function */
        #if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_VK_POPUP_HINT__) && !defined(__MMI_FTE_SUPPORT__)
            mmi_imc_config_redraw_vk(MMI_FALSE);
            /* the editor area need to be updated */
            wgui_inputs_ml_jump_to_line(MMI_multiline_inputbox.visible_line_info->start_line_index, MMI_TRUE);
            mmi_imc_config_redraw_vk(MMI_TRUE);
        #else
            wgui_inputs_ml_jump_to_line(MMI_multiline_inputbox.visible_line_info->start_line_index, MMI_TRUE);
        #endif
        }
        else
        {
            /* only update the scrollbar */
            gui_update_multi_line_linebase_scrollbar(&MMI_multiline_inputbox);
 
            gui_push_clip();

            gui_set_text_clip(MMI_multiline_inputbox.x, 
                              MMI_multiline_inputbox.y, 
                              MMI_multiline_inputbox.x + MMI_multiline_inputbox.width - 1, 
                              MMI_multiline_inputbox.y + MMI_multiline_inputbox.height - 1);

            gui_show_vertical_scrollbar(&MMI_multiline_inputbox.vbar);
            gui_pop_clip();
        }
#endif /*__MMI_FTE_EDITOR_SCROLLBAR_STYLE__*/

    #if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_VK_POPUP_HINT__) && !defined(__MMI_FTE_SUPPORT__)
	    if (mmi_imc_is_connected())
	    {
		    gui_unlock_double_buffer();
        #ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__
            wgui_show_virtual_keyboard();
        #else
            wgui_virtual_keyboard_show();
        #endif
	    }
    #endif /* __MMI_TOUCH_SCREEN__ || __MMI_VK_POPUP_HINT__ */

        gui_BLT_double_buffer(
            MMI_multiline_inputbox.x,
            MMI_multiline_inputbox.y,
            MMI_multiline_inputbox.x + MMI_multiline_inputbox.width - 1,
            MMI_multiline_inputbox.y + MMI_multiline_inputbox.height - 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_linebase_next_line
 * DESCRIPTION
 *  line base key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_linebase_next_line(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 new_start;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_multiline_inputbox.visible_line_info->start_line_index  
        + MMI_multiline_inputbox.visible_line_info->line_count >= 
        MMI_multiline_inputbox.total_line_count)
    {
        if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE)
        {
            if (stop_auto_scroll_callback)
                stop_auto_scroll_callback();
            wgui_inputs_ml_linebase_stop_text_scroll();
        }
        
        wgui_inputs_ml_jump_to_line(MMI_multiline_inputbox.visible_line_info->start_line_index, MMI_TRUE);
        multiline_inputbox_navigate_callback();
        return;
    }

    if (MMI_multiline_inputbox.visible_line_info->start_line_index + 1
        >= MMI_multiline_inputbox.total_line_count)
    {
        wgui_inputs_ml_jump_to_line(MMI_multiline_inputbox.visible_line_info->start_line_index, MMI_TRUE);
        multiline_inputbox_navigate_callback();
        return;
    }
    
    new_start = MMI_multiline_inputbox.visible_line_info->start_line_index + 1;
    new_start = wgui_inputs_ml_linebase_validate_for_last_page(new_start);
    wgui_inputs_ml_jump_to_line(new_start, MMI_TRUE);
    multiline_inputbox_navigate_callback();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_linebase_previous_line
 * DESCRIPTION
 *  line base key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_linebase_previous_line(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 new_start;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_multiline_inputbox.visible_line_info->start_line_index == 0)
    {
        wgui_inputs_ml_jump_to_line(MMI_multiline_inputbox.visible_line_info->start_line_index, MMI_TRUE);
        multiline_inputbox_navigate_callback();
        return;
    }

    if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE)
    {
        if (stop_auto_scroll_callback)
            stop_auto_scroll_callback();
        wgui_inputs_ml_linebase_stop_text_scroll();
    }
        
    new_start = MMI_multiline_inputbox.visible_line_info->start_line_index - 1;
    wgui_inputs_ml_jump_to_line(new_start, MMI_TRUE);
    multiline_inputbox_navigate_callback();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_linebase_next_page
 * DESCRIPTION
 *  line base key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_linebase_next_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 new_start;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_multiline_inputbox.visible_line_info->b_to_end
        || (MMI_multiline_inputbox.visible_line_info->start_line_index + MMI_multiline_inputbox.visible_line_info->line_count
         >= MMI_multiline_inputbox.total_line_count))
    {
        if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE)
        {
            if (stop_auto_scroll_callback)
                stop_auto_scroll_callback();
            wgui_inputs_ml_linebase_stop_text_scroll();
        }
        
        wgui_inputs_ml_jump_to_line(MMI_multiline_inputbox.visible_line_info->start_line_index, MMI_TRUE);
        multiline_inputbox_navigate_callback();
        return;
    }

    if (MMI_multiline_inputbox.visible_line_info->start_line_index + MMI_multiline_inputbox.visible_line_info->line_count
         >= MMI_multiline_inputbox.total_line_count)
    {
        wgui_inputs_ml_jump_to_line(MMI_multiline_inputbox.visible_line_info->start_line_index, MMI_TRUE);
        multiline_inputbox_navigate_callback();
        return;
    }
    new_start = MMI_multiline_inputbox.visible_line_info->start_line_index 
        + MMI_multiline_inputbox.visible_line_info->line_count - GUI_REUSED_VISIBLE_LINE_COUNT;
    
    if (new_start >= MMI_multiline_inputbox.total_line_count)
        new_start = MMI_multiline_inputbox.total_line_count - 1;
    
    new_start = wgui_inputs_ml_linebase_validate_for_last_page(new_start);
    wgui_inputs_ml_jump_to_line(new_start, MMI_TRUE);
    multiline_inputbox_navigate_callback();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_linebase_previous_page
 * DESCRIPTION
 *  line base key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_linebase_previous_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 start_index = MMI_multiline_inputbox.visible_line_info->start_line_index
                        - (GUI_MAX_VISIBLE_LINE/2) + GUI_REUSED_VISIBLE_LINE_COUNT;
    S32 y = 0, i = 0, new_start;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_multiline_inputbox.visible_line_info->start_line_index == 0)
    {
        wgui_inputs_ml_jump_to_line(MMI_multiline_inputbox.visible_line_info->start_line_index, MMI_TRUE);
        multiline_inputbox_navigate_callback();
        return;
    }

    if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE)
    {
        if (stop_auto_scroll_callback)
            stop_auto_scroll_callback();
        wgui_inputs_ml_linebase_stop_text_scroll();
    }
    
    if (start_index < 0)
        start_index = 0;

    MMI_multiline_inputbox.force_stop_line_index = MMI_multiline_inputbox.visible_line_info->start_line_index - 1
        + GUI_REUSED_VISIBLE_LINE_COUNT;

    wgui_inputs_ml_jump_to_line(start_index, MMI_FALSE);

    MMI_multiline_inputbox.force_stop_line_index = -1;

    i = MMI_multiline_inputbox.visible_line_info->start_line_index - 1 + GUI_REUSED_VISIBLE_LINE_COUNT;
    
    while (1)
    {
        y += MMI_multiline_inputbox.line_info->line_height[i-MMI_multiline_inputbox.line_info->start_line_index];
        if (y > MMI_multiline_inputbox.edit_height)
        {
            i++;
            break;
        }
        
        i--;
        
        if (i<0)
        {
            i = 0;
            break;
        }
    }

    new_start = i;
    
    wgui_inputs_ml_jump_to_line(new_start, MMI_TRUE);
    multiline_inputbox_navigate_callback();
    
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_linebase_start_auto_scroll
 * DESCRIPTION
 *  line base key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_linebase_start_auto_scroll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE;
    if (linebase_page_info.scroll_type == WGUI_SCROLL_LINE_BY_LINE)
    {
        gui_start_timer(200, wgui_inputs_ml_linebase_start_text_scroll);
    }
    else
    {
        gui_start_timer(
            (UI_MULTI_LINE_INIT_SCROLL * WGUI_MAX_SCROLL_TIME) / linebase_page_info.scroll_speed,
            wgui_inputs_ml_linebase_start_text_scroll);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_linebase_start_text_scroll
 * DESCRIPTION
 *  Start scrolling of text either page-by-page or line-by-line
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_linebase_start_text_scroll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_VK_POPUP_HINT__) && !defined(__MMI_FTE_SUPPORT__)
    if (mmi_imc_is_connected())
	{
		gui_lock_double_buffer();
        wgui_virtual_keyboard_recover_covered_area();
	}
#endif /* __MMI_TOUCH_SCREEN__ || __MMI_VK_POPUP_HINT__ */
	MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE;

    if (linebase_page_info.scroll_type == WGUI_SCROLL_LINE_BY_LINE &&
        linebase_page_info.scroll_flag == WGUI_AUTO_SCROLL_ON)
    {
        wgui_inputs_ml_linebase_next_line();

        if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE)
        {
            gui_start_timer(
                (WGUI_MAX_SCROLL_TIME * UI_MULTI_LINE_SCROLL_TIMEOUT) / linebase_page_info.scroll_speed,
            wgui_inputs_ml_linebase_start_text_scroll);
        }
    }
    else
    {
        wgui_inputs_ml_linebase_next_page();
        if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE)
        {
            gui_start_timer(
                (UI_MULTI_LINE_INIT_SCROLL * WGUI_MAX_SCROLL_TIME) / linebase_page_info.scroll_speed,
            wgui_inputs_ml_linebase_start_text_scroll);
        }
    }

#ifndef __MMI_FTE_SUPPORT__
    /* Redraw counter information bar to fix VK large icon background issue */
    wgui_category375_redraw_inputbox_and_counter();
#endif

#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_VK_POPUP_HINT__) && !defined(__MMI_FTE_SUPPORT__)
	if (mmi_imc_is_connected())
	{
		gui_unlock_double_buffer();
        #ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__
        wgui_show_virtual_keyboard();
        #else
            wgui_virtual_keyboard_show();
        #endif
	}
#endif /* __MMI_TOUCH_SCREEN__ || __MMI_VK_POPUP_HINT__ */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_stop_text_scroll
 * DESCRIPTION
 *  stop the scrolling of text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_linebase_stop_text_scroll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_multiline_inputbox.ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE;
    gui_cancel_timer(wgui_inputs_ml_linebase_start_text_scroll);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_linebase_set_stop_scroll_callback
 * DESCRIPTION
 *  set the autoscroll stop callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_linebase_set_stop_scroll_callback(void* callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stop_auto_scroll_callback = (stop_scroll_hdlr)callback;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_linebase_set_font
 * DESCRIPTION
 *  Set the font type of text going to be dispalyed
 * PARAMETERS
 *  gui_font_type        [IN]        
 *  gui_font_style       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_linebase_set_font(U8 gui_font_type, U8 gui_font_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (gui_font_type)
    {
        case FONT_SIZE_SMALL:
            MMI_multiline_inputbox.text_font = &MMI_small_font;
            break;

        case FONT_SIZE_MEDIUM:
            MMI_multiline_inputbox.text_font = &MMI_medium_font;
            break;

        case FONT_SIZE_LARGE:
            MMI_multiline_inputbox.text_font = &MMI_large_font;
            break;
    }
    MMI_multiline_inputbox.font_style = gui_font_style;

}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_linebase_highlight_search_string
 * DESCRIPTION
 *  hightlight the search string
 * PARAMETERS
 *  text_offset         [IN]        And the string_len
 *  search_str_len      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_linebase_highlight_search_string(S32 text_offset, S8 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_multiline_inputbox.highlight_start_position = MMI_multiline_inputbox.text + (text_offset * ENCODING_LENGTH);
    MMI_multiline_inputbox.highlight_end_position =
    MMI_multiline_inputbox.text + (text_offset + len) * ENCODING_LENGTH;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_linebase_set_scroll_info
 * DESCRIPTION
 *  sets the speed of scrolling
 * PARAMETERS
 *  gui_scroll_info     [IN]        
 *  instance(?)         [IN]        Of gui_page_info_app structure
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_linebase_set_scroll_info(wgui_ml_line_base_info *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    linebase_page_info = *info;
    MMI_multiline_inputbox.scroll_type = info->scroll_type;
    MMI_multiline_inputbox.scroll_speed = info->scroll_speed;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_linebase_set_percentage_callback
 * DESCRIPTION
 *  set the percentage show function callback
 * PARAMETERS
 *  callback        [IN]        =show callback function
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_linebase_set_percentage_callback(void* callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    percentage_callback = (percentage_hdlr)callback;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_linebase_jump_to_end
 * DESCRIPTION
 *  jump to end of the text content
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_linebase_jump_to_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    index = MMI_multiline_inputbox.total_line_count - 1;

    index = wgui_inputs_ml_linebase_validate_for_last_page(index);

    wgui_inputs_ml_jump_to_line(index, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_linebase_get_percentage
 * DESCRIPTION
 *  get the current percentage string
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_linebase_get_percentage(UI_character_type *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (MMI_multiline_inputbox.total_line_count == 0)
    {
        gui_sprintf(str, "%d/%d", 0, 0);
    }
    else
    {
        gui_sprintf(str, "%d/%d", MMI_multiline_inputbox.visible_line_info->start_line_index + 1, MMI_multiline_inputbox.total_line_count);
    }
}

/* The following functions provide background layout 
 * But bg_multiline_inputbox must have been copied from the MMI_multiline_inputbox
 */

static multi_line_input_box bg_multiline_inputbox;
static gui_line_struct g_visible_multiline_line_info_bg;
static gui_line_struct g_multiline_line_info_bg;


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_linebase_init_bg_layout
 * DESCRIPTION
 *  initialize background layout
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_linebase_init_bg_layout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    bg_multiline_inputbox = MMI_multiline_inputbox;
    bg_multiline_inputbox.total_line_count = 0x7FFFFFFF;
    memset(&g_visible_multiline_line_info_bg, 0, sizeof(g_visible_multiline_line_info_bg));
    memset(&g_multiline_line_info_bg, 0, sizeof(g_multiline_line_info_bg));
    bg_multiline_inputbox.visible_line_info = &g_visible_multiline_line_info_bg;
    bg_multiline_inputbox.line_info = &g_multiline_line_info_bg;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_jump_to_line_bg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  line_index    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_jump_to_line_bg(S32 line_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stFontAttribute Font;
    U8 arrCount;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetFont(&Font, &arrCount);

    bg_multiline_inputbox.get_data_cb(&bg_multiline_inputbox.text, &bg_multiline_inputbox.text_length,
        line_index, line_index + GUI_MAX_VISIBLE_LINE);

	bg_multiline_inputbox.text_length *= ENCODING_LENGTH;

	bg_multiline_inputbox.cursor_p = bg_multiline_inputbox.text;

    bg_multiline_inputbox.line_info->start_line_index = line_index;

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    gui_inputs_cache_switch(1);
#endif

    //bg_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_show_multi_line_input_box(&bg_multiline_inputbox);
    //bg_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_multi_line_input_box_no_draw(&bg_multiline_inputbox);

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    gui_inputs_cache_switch(0);
#endif

    SetFont(Font, arrCount);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_get_layout_info_bg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
gui_line_struct * wgui_inputs_ml_get_layout_info_bg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return bg_multiline_inputbox.line_info;
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_linebase_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_inputs_ml_linebase_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR)
        || ((MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR) && (MMI_multiline_inputbox.vbar.scale > MMI_multiline_inputbox.vbar.range)))
        return MMI_FALSE;

#ifdef __MMI_EDITOR_SSP_SUPPORT__
    gui_input_box_ssp_pen_translate(pos, MMI_PEN_EVENT_UP);
    return MMI_TRUE;
#endif /* __MMI_EDITOR_SSP_SUPPORT__ */

    if (PEN_CHECK_BOUND
        (pos.x, pos.y, MMI_multiline_inputbox.vbar.x, MMI_multiline_inputbox.vbar.y, MMI_multiline_inputbox.vbar.width,
         MMI_multiline_inputbox.vbar.height))
    {
        gui_vertical_scrollbar_translate_pen_event(
            &MMI_multiline_inputbox.vbar,
            MMI_PEN_EVENT_UP,
            pos.x,
            pos.y,
            &scrollbar_event,
            &scrollbar_param);

        index = wgui_inputs_ml_linebase_validate_for_last_page(MMI_multiline_inputbox.vbar.value);
        wgui_inputs_ml_jump_to_line(index, MMI_TRUE);

        multiline_inputbox_navigate_callback();
        return MMI_TRUE;
    }
    
    index = wgui_inputs_ml_linebase_validate_for_last_page(MMI_multiline_inputbox.vbar.value);
    wgui_inputs_ml_jump_to_line(index, MMI_TRUE);

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_paging_pen_down_handler
 * DESCRIPTION
 *  touch screen hadler for category 75 & 77
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_inputs_ml_linebase_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR)
        || ((MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR) && (MMI_multiline_inputbox.vbar.scale > MMI_multiline_inputbox.vbar.range)))
        return MMI_FALSE;

#ifdef __MMI_EDITOR_SSP_SUPPORT__
    gui_input_box_ssp_pen_translate(pos, MMI_PEN_EVENT_DOWN);
    return MMI_TRUE;
#endif /* __MMI_EDITOR_SSP_SUPPORT__ */

    if (PEN_CHECK_BOUND
        (pos.x, pos.y, MMI_multiline_inputbox.vbar.x, MMI_multiline_inputbox.vbar.y, MMI_multiline_inputbox.vbar.width,
         MMI_multiline_inputbox.vbar.height))
    {
		gui_vertical_scrollbar_set_pen_self_scroll(&MMI_multiline_inputbox.vbar, MMI_FALSE);
        gui_vertical_scrollbar_translate_pen_event(
            &MMI_multiline_inputbox.vbar,
            MMI_PEN_EVENT_DOWN,
            pos.x,
            pos.y,
            &scrollbar_event,
            &scrollbar_param);
		gui_vertical_scrollbar_set_pen_self_scroll(&MMI_multiline_inputbox.vbar, MMI_TRUE);

        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
        {
            if (MMI_multiline_inputbox.vbar.pen_state.state == GUI_SCROLLBAR_PEN_STATE_AREA1)
            {
                wgui_inputs_ml_linebase_previous_page();
            }
            else if (MMI_multiline_inputbox.vbar.pen_state.state == GUI_SCROLLBAR_PEN_STATE_AREA2)
            {
                wgui_inputs_ml_linebase_next_page();
            }
            else if (MMI_multiline_inputbox.vbar.pen_state.state == GUI_SCROLLBAR_PEN_STATE_BUTTON1)
            {
                wgui_inputs_ml_linebase_previous_line();
            }
            else if (MMI_multiline_inputbox.vbar.pen_state.state == GUI_SCROLLBAR_PEN_STATE_BUTTON2)
            {
                wgui_inputs_ml_linebase_next_line();
            }
        }
        
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  wgui_inputs_ml_linebase_pen_move_hdlr
* DESCRIPTION
*  touch screen handler for category 75 & 77
* PARAMETERS
*  pos     [IN]        
* RETURNS
*  void
*****************************************************************************/
MMI_BOOL wgui_inputs_ml_linebase_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR)
        || ((MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR) && (MMI_multiline_inputbox.vbar.scale > MMI_multiline_inputbox.vbar.range)))
        return MMI_FALSE;
    
#ifdef __MMI_EDITOR_SSP_SUPPORT__
    gui_input_box_ssp_pen_translate(pos, MMI_PEN_EVENT_MOVE);
    return MMI_TRUE;
#endif /* __MMI_EDITOR_SSP_SUPPORT__ */

    if (gui_vertical_scrollbar_translate_pen_event(
            &MMI_multiline_inputbox.vbar,
            MMI_PEN_EVENT_MOVE,
            pos.x,
            pos.y,
            &scrollbar_event,
            &scrollbar_param))
    {
        index = wgui_inputs_ml_linebase_validate_for_last_page(MMI_multiline_inputbox.vbar.value);
        wgui_inputs_ml_jump_to_line(index, MMI_TRUE);

        if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE)
        {
            if (stop_auto_scroll_callback)
                stop_auto_scroll_callback();
            wgui_inputs_ml_linebase_stop_text_scroll();
        }

        return MMI_TRUE;
    }
    return MMI_FALSE;
}

#ifdef __MMI_EDITOR_SSP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_linebase_ssp_update_client
 * DESCRIPTION
 *  
 * PARAMETERS
 *  offset              [IN]    the new offset position
 * RETURNS
 *  MMI_TRUE if this pen event is handled; otherwise, MMI_FALSE.
 *****************************************************************************/
void wgui_inputs_ml_linebase_ssp_update_client(void *user_data, S32 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    multi_line_input_box *b = (multi_line_input_box *)user_data;
    S32 index, addition, bk_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bk_index = b->visible_line_info->start_line_index;

    if (b->visible_line_info->start_line_index == offset)
        return;

    if (offset < 0)
        offset = 0;

    index = offset / 20;

    if (gui_input_box_ssp_get_state() == GUI_INPUT_BOX_SSP_STATE_FREE_RUN)
        addition = offset % 20;
    else
        addition = 0;

    if (index == b->visible_line_info->start_line_index
        && addition > 0)
    {
        b->visible_line_info->start_line_index++;
    }
    else
    {
        b->visible_line_info->start_line_index = index;
    }
    
    if (b->visible_line_info->start_line_index >= b->total_line_count)
        b->visible_line_info->start_line_index = b->total_line_count - 1;

    index = wgui_inputs_ml_linebase_validate_for_last_page(b->visible_line_info->start_line_index);
    wgui_inputs_ml_jump_to_line(index, MMI_TRUE);
    
    if (index < bk_index)
    {
        if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE)
        {
            if (stop_auto_scroll_callback)
                stop_auto_scroll_callback();
            wgui_inputs_ml_linebase_stop_text_scroll();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_multiline_ssp_get_client_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_linebase_ssp_get_client_info(void *user_data, S32 *total_offset, S32 *cur_offset, S32 *move_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    multi_line_input_box *b = (multi_line_input_box *)user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (total_offset)
    {
        *total_offset = b->total_line_count - MMI_multiline_inputbox.visible_line_info->line_count;
        if (*total_offset < 0)
            *total_offset = 0;
        *total_offset *= 20;
    }

    if (cur_offset)
    {
        *cur_offset = b->visible_line_info->start_line_index;
        *cur_offset *= 20;
    }

    if (move_type)
    {
        *move_type = GUI_INPUT_BOX_SSP_BY_Y;
    }
}

#endif /* __MMI_EDITOR_SSP_SUPPORT__ */


#endif /* __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
* FUNCTION
*  wgui_inputs_ml_linebase_init
* DESCRIPTION
*  
* PARAMETERS
*  pos     [IN]        
* RETURNS
*  void
*****************************************************************************/
void wgui_inputs_ml_linebase_init(wgui_ml_line_base_info *page_info_d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = page_info_d->start_line_index;
    S32 old_index = page_info_d->start_line_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_multiline_inputbox.override_direction = page_info_d->override_direction ? 2 : 1;
    wgui_inputs_ml_linebase_set_font(page_info_d->font_size, page_info_d->font_style);

    wgui_inputs_ml_set_total_line_count(page_info_d->total_line_count, MMI_FALSE);
    wgui_inputs_ml_linebase_register_callback(page_info_d->get_data_cb);
    wgui_inputs_ml_linebase_set_scroll_info(page_info_d);
    wgui_inputs_ml_linebase_init_bg_layout();

    if (page_info_d->jump_to_end)
    {
        wgui_inputs_ml_linebase_jump_to_end();
    }
    else
    {
        index = wgui_inputs_ml_linebase_validate_for_last_page(index);
        wgui_inputs_ml_jump_to_line(index, MMI_FALSE);
    }

    page_info_d->start_line_index = index;
    if (page_info_d->b_highlight)
    {
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        if (old_index != page_info_d->start_line_index)
        {
            /* the start line is adjust by us for the last page, we must correct the highlight offset */
            page_info_d->highlight_offset +=
                MMI_multiline_inputbox.line_info->array[old_index - index].offset;
        }
        wgui_inputs_ml_linebase_highlight_search_string(page_info_d->highlight_offset, (S8)page_info_d->highlight_len);
    }
    
#ifdef __MMI_EDITOR_SSP_SUPPORT__
    gui_input_box_ssp_set_client_callback(
        wgui_inputs_ml_linebase_ssp_update_client, 
        wgui_inputs_ml_linebase_ssp_get_client_info, 
        &MMI_multiline_inputbox);
#endif /* __MMI_EDITOR_SSP_SUPPORT__ */
}


/*****************************************************************************
* FUNCTION
*  wgui_inputs_ml_linebase_validate_for_last_page
* DESCRIPTION
*  
* PARAMETERS
*  S32     [IN]        
* RETURNS
*  S32
*****************************************************************************/
S32 wgui_inputs_ml_linebase_validate_for_last_page(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static S32 already_in = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (already_in)
        return index;
    
    already_in = 1;

    if (index + GUI_MAX_VISIBLE_LINE <= MMI_multiline_inputbox.total_line_count)
    {
        already_in = 0;
        return index;
    }

    wgui_inputs_ml_jump_to_line(index, MMI_FALSE);
    if (MMI_multiline_inputbox.line_info->b_to_end
        || (MMI_multiline_inputbox.line_info->start_line_index + MMI_multiline_inputbox.line_info->line_count
         >= MMI_multiline_inputbox.total_line_count))
    {
        gui_lock_double_buffer();
        wgui_inputs_ml_jump_to_line(MMI_multiline_inputbox.total_line_count - 1, MMI_TRUE);
        wgui_inputs_ml_linebase_previous_page();
        gui_unlock_double_buffer();
        
        already_in = 0;
        return MMI_multiline_inputbox.line_info->start_line_index;
    }
    
    already_in = 0;
    return index;
}
/* Line Base Mode End */
#endif   /* __UI_LINEBASE_IN_MULTILINE_EDITOR__  */

void wgui_inputs_ml_get_visible_character_range(S32 *start, S32 *end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *start = MMI_multiline_inputbox.visible_start;
    *end = MMI_multiline_inputbox.visible_end;
}


/*****************************************************************************
* FUNCTION
*  wgui_inputs_ml_register_pre_key_handler
* DESCRIPTION
*  Register multiline inputbox pre key handler
* PARAMETERS
*  S32     [IN]        
* RETURNS
*  void
*****************************************************************************/
void wgui_inputs_ml_register_pre_key_handler(wgui_inputs_ml_key_hdlr f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_inputs_ml_pre_key_handler = f;
}


/*****************************************************************************
* FUNCTION
*  wgui_inputs_ml_register_pre_key_handler
* DESCRIPTION
*  Reset multiline inputbox pre key handler
* PARAMETERS
*  S32     [IN]        
* RETURNS
*  void
*****************************************************************************/
void wgui_inputs_ml_reset_pre_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_inputs_ml_pre_key_handler = NULL;
}


/*****************************************************************************
* FUNCTION
*  wgui_inputs_ml_disable
* DESCRIPTION
*  Disable multiline inputbox. 
*  Only hide the cursor and change the background filler to disabled_filler 
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
void wgui_inputs_ml_disable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_multiline_inputbox.flags |= (UI_MULTI_LINE_INPUT_BOX_STATE_DISABLED | UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW);
    MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
    StopTimer(BLINKING_CURSOR);
    //wgui_inputs_ml_redraw();
}


/*****************************************************************************
* FUNCTION
*  wgui_inputs_ml_enable
* DESCRIPTION
*  Enable multiline inputbox. 
*  Show the cursor and reset the background filler to normal_filler
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
void wgui_inputs_ml_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_multiline_inputbox.flags &= ~(UI_MULTI_LINE_INPUT_BOX_STATE_DISABLED | UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW);
    MMI_multiline_inputbox.ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
    //wgui_inputs_ml_redraw();
}


/*****************************************************************************
* FUNCTION
*  wgui_inputs_ml_is_disable
* DESCRIPTION
*  Check if multiline inputbox is in disabled mode. 
* PARAMETERS
*  void        
* RETURNS
*  MMI_BOOL
*****************************************************************************/
MMI_BOOL wgui_inputs_ml_is_disable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_STATE_DISABLED) &&
        (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
* FUNCTION
*  wgui_inputs_ml_pre_key_handler
* DESCRIPTION
*  Multiline inputbox pre key handler. 
* PARAMETERS
*  void        
* RETURNS
*  MMI_BOOL
*****************************************************************************/
static MMI_BOOL wgui_inputs_ml_pre_key_handler(U16 key_code, U16 key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_type == KEY_EVENT_DOWN)
    {
        if (g_wgui_inputs_ml_pre_key_handler)
        {
            if (g_wgui_inputs_ml_pre_key_handler(key_code))
            {
                return MMI_TRUE;
            }
        }
    }

    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_move_cursor
 * DESCRIPTION
 *  Move the multiline editor cursor
 * PARAMETERS
 *  pos             [IN]                              cursor position
 *                  WGUI_INPUTS_CURSOR_POS_START   start position
 *                  WGUI_INPUTS_CURSOR_POS_END     end position
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_move_cursor(wgui_inputs_cursor_pos_enum pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pos == WGUI_INPUTS_CURSOR_POS_START)
    {
        MMI_multiline_inputbox.cursor_p = MMI_multiline_inputbox.text;
    }
    else if(pos == WGUI_INPUTS_CURSOR_POS_END)
    {
        MMI_multiline_inputbox.cursor_p = MMI_multiline_inputbox.last_position_p - ENCODING_LENGTH;
    }
    else
    {
        MMI_ASSERT(0);
    }

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    gui_mlc_all_line_update();
#endif

    gui_show_multi_line_input_box_ext(&MMI_multiline_inputbox, -1, -1);
}


/*****************************************************************************
* FUNCTION
*  wgui_inputs_ml_register_before_delete_callback
* DESCRIPTION
*  Register multiline inputbox pre delete handler
* PARAMETERS
*  FuncPtr     [IN]      callback function
* RETURNS
*  void
*****************************************************************************/
void wgui_inputs_ml_register_pre_delete_callback(FuncPtr f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_inputs_ml_pre_delete_handler = f;
}


/*****************************************************************************
* FUNCTION
*  wgui_inputs_ml_reset_pre_delete_callback
* DESCRIPTION
*  Reset multiline inputbox pre delete handler
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void wgui_inputs_ml_reset_pre_delete_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_inputs_ml_pre_delete_handler = NULL;
}


/*****************************************************************************
* FUNCTION
*  wgui_inputs_ml_get_scroll_bar_width
* DESCRIPTION
*  Get Multiline inputbox scroll bar width, if no scroll bar, return 0
* PARAMETERS
*  void        
* RETURNS
*  S32
*****************************************************************************/
S32 wgui_inputs_ml_get_scroll_bar_width(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR) ||
        ((MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR) && 
         ((MMI_multiline_inputbox.vbar.scale != 0) && 
          (MMI_multiline_inputbox.vbar.scale >= MMI_multiline_inputbox.vbar.range))))
    {
        return 0;
    }
    else
    {
        return MMI_multiline_inputbox.vbar.width;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_get_cursor_index
 * DESCRIPTION
 *  Get multiline editor cursor index
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 wgui_inputs_ml_get_cursor_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_multiline_inputbox.cursor_p - MMI_multiline_inputbox.text) / ENCODING_LENGTH;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_set_decimal_flag
 * DESCRIPTION
 *  set multiline decimal flag according to input type
 * PARAMETERS
 *  input_type               [IN]             input type
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_set_decimal_flag(U32 input_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_multiline_inputbox_decimal_input_mode_flag = 0;
    wgui_multiline_inputbox_decimal_flag = 0;
    if (input_type & IMM_INPUT_TYPE_DECIMAL_NUMERIC ||
        input_type & IMM_INPUT_TYPE_SIGNED_DECIMAL_NUMERIC)
    {
        wgui_multiline_inputbox_decimal_input_mode_flag = 1;
        if (MMI_multiline_inputbox.text_length > 2)
        {
            S32 i;
            UI_buffer_type t = MMI_multiline_inputbox.text;
            UI_character_type c;
        
            for (i = 0; i < (MMI_multiline_inputbox.text_length / ENCODING_LENGTH); i++)
            {
                UI_STRING_GET_NEXT_CHARACTER(t, c);
                if (c == (UI_character_type) '.')
                {
                    wgui_multiline_inputbox_decimal_flag = 1;
                    break;
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_register_floating_counter
 * DESCRIPTION
 *  register the floating counter callback
 * PARAMETERS
 *  buffer               [IN]             buffer to store the remaining counter
 *  buffer_size          [IN]             buffer length
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_register_floating_counter(MMI_BOOL (*get_remaining_counter)(UI_character_type *buffer, S32 buffer_size))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef GUI_INPUT_BOX_FLOATING_COUNTER
    MMI_multiline_inputbox.get_remaining_counter = get_remaining_counter;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_register_set_key_callback
 * DESCRIPTION
 *  Set key handler for App in editor screen
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_register_set_key_callback(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    multiline_inputbox_set_key_callback = f;
}


#ifdef __MMI_EDITOR_MULTILINE_DIALER_STYLE_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_change_callback
 * DESCRIPTION
 *  change callback funtion of multiline input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_change_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_multiline_inputbox.text_font = gui_font_get_type(GUI_FONT_SIZE_DIALER_LARGE);

    gui_lock_double_buffer();
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    gui_inputs_cache_invalid();
#endif
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_multi_line_input_box_basic(&MMI_multiline_inputbox, -1, -1);
    MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_unlock_double_buffer();

    /* Vertical center alignment */
    MMI_multiline_inputbox.text_y = MMI_multiline_inputbox.height / 2 - MMI_multiline_inputbox.text_height / 2;
    if (MMI_multiline_inputbox.n_lines > 1)
    {
        if((MMI_multiline_inputbox.text_height+4)>MMI_multiline_inputbox.height)
        MMI_multiline_inputbox.text_font = gui_font_get_type(GUI_FONT_SIZE_DIALER_SMALL);
        gui_lock_double_buffer();
    #ifdef GUI_INPUT_BOX_CACHE_SUPPORT
        gui_inputs_cache_invalid();
    #endif
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        gui_show_multi_line_input_box_basic(&MMI_multiline_inputbox, -1, -1);
        MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        gui_unlock_double_buffer();

        /* Vertical center alignment */
        MMI_multiline_inputbox.text_y = MMI_multiline_inputbox.height / 2 - MMI_multiline_inputbox.text_height / 2;
    }
    MMI_multiline_inputbox.text_y = MMI_multiline_inputbox.text_y > 2 ? MMI_multiline_inputbox.text_y : 2;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_handle_plus_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inputs_ml_handle_plus_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_multiline_inputbox.text[0] == '+')
    {
        if (MMI_multiline_inputbox.text != MMI_multiline_inputbox.cursor_p)
        {
            MMI_multiline_inputbox.available_length = (wgui_inputbox_buffer_size + 1) * ENCODING_LENGTH;
        }
    }
    else
    {
        U8 done = 0;
        UI_buffer_type current_position = MMI_multiline_inputbox.text;
        UI_buffer_type previous_position = MMI_multiline_inputbox.text;
        UI_character_type c;

        MMI_multiline_inputbox.available_length = wgui_inputbox_buffer_size * ENCODING_LENGTH;
        if (MMI_multiline_inputbox.text_length > MMI_multiline_inputbox.allocated_length)
        {
            MMI_multiline_inputbox.text_length -= ENCODING_LENGTH;
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
            MMI_multiline_inputbox.last_position_p = previous_position;
            if (MMI_multiline_inputbox.cursor_p != MMI_multiline_inputbox.text)
            {
                UI_STRING_GET_PREVIOUS_CHARACTER(MMI_multiline_inputbox.cursor_p, c);
            }
        }
    }
}

#endif /* __MMI_EDITOR_MULTILINE_DIALER_STYLE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_is_area_visible
 * DESCRIPTION
 *  Check the area is visible or not
 * PARAMETERS
 *  x               [IN]               
 *  y               [IN]
 *  width           [IN]
 *  height          [IN]
 *  gap             [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
S32 wgui_inputs_ml_is_area_visible(S32 x, S32 y, S32 width, S32 height, S32 gap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((y - gap) > 0)
    {
        y -= gap;
    }
    if (1) /* height + (gap << 1) < text total height */
    {
        height += (gap << 1);
    }
    

    if ( y >= (-MMI_multiline_inputbox.text_offset_y) &&
        y <= (-MMI_multiline_inputbox.text_offset_y + MMI_multiline_inputbox.height) &&
        (y + height) >= (-MMI_multiline_inputbox.text_offset_y) &&
        (y + height) <= (-MMI_multiline_inputbox.text_offset_y + MMI_multiline_inputbox.height))
    {
        return 0;
    }
    else
    {
        if (y < (-MMI_multiline_inputbox.text_offset_y))
        {
            return (y + MMI_multiline_inputbox.text_offset_y);
        }
        else if (y > (-MMI_multiline_inputbox.text_offset_y + MMI_multiline_inputbox.height))
        {
            return (y + MMI_multiline_inputbox.text_offset_y - MMI_multiline_inputbox.height + height);
        }
        else if ((y + height) < (-MMI_multiline_inputbox.text_offset_y))
        {
            return (y + MMI_multiline_inputbox.text_offset_y);
        }
        else if ((y + height) > (-MMI_multiline_inputbox.text_offset_y + MMI_multiline_inputbox.height))
        {
            return (y + height + MMI_multiline_inputbox.text_offset_y - MMI_multiline_inputbox.height);
        }
        else
        {
            return 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_set_auto_display_remaining_counter
 * DESCRIPTION
 *  set multiline auto display remaining counter
 * PARAMETERS
 
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_set_auto_display_remaining_counter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_multi_line_input_box_set_auto_display_remaining_counter(&MMI_multiline_inputbox);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ml_set_clear_key_delete_all_mode
 * DESCRIPTION
 *  Set clear key delete all mode. 
 *  By default the clear key long press will fast delete character by character
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_ml_set_clear_key_delete_all_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_inputs_is_clear_key_delete_all = MMI_TRUE;
}
