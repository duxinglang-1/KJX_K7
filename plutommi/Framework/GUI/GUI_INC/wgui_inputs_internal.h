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
 *   wgui_inputs_internal.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   editor wgui layer internal header file
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __WGUI_INPUTS_INTERNAL_H__
#define __WGUI_INPUTS_INTERNAL_H__

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "wgui_inputs.h"
#include "MMI_features.h"
//#include "mmi_frm_gprot.h"
//#include "wgui_categories_inputs.h"
//#include "CommonScreens.h"
//#include "Gui_Setting.h"
//#include "IMEres.h"
//#include "ImeGprot.h"
//#include "wgui_include.h"
//#include "wgui_fixed_menus.h"
//#include "wgui_touch_screen.h"
//#include "gui_ems.h"

#ifdef __MMI_TOUCH_DIAL_SCREEN__
#include "gui_inputs.h"
//#include "wgui.h"
#endif /* __MMI_TOUCH_DIAL_SCREEN__ */ 

//#include "gdi_include.h"

//#include "LangModuleGProt.h"

//#include "gui_ems.h"
//#include "IdleAppDef.h"

//#include "wgui_dynamic_menus.h"
//#include "gui_dynamic_menus.h"

    #include "MMIDataType.h"
    #include "wgui_draw_manager.h"
    #include "kal_general_types.h"
    #include "wgui_inline_edit.h"
    #include "gui_data_types.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define ENABLE_SINGLELINE_INPUTBOX_TEST_WORD_HIGHLIGHT   0
#define ENABLE_MULTILINE_INPUTBOX_TEST_WORD_HIGHLIGHT 0

#define MMI_INJECT_STRING_TO_MODULE_MAX_LENGTH 128
#define MMI_INJECT_STRING_TO_MODULE_UNICODE_UNDONE_INDEX 10
#define MMI_INJECT_STRING_TO_MODULE_UNICODE_DONE_INDEX 11
#define MMI_INJECT_STRING_TO_MODULE_ASCII_UNDONE_INDEX 12
#define MMI_INJECT_STRING_TO_MODULE_ASCII_DONE_INDEX 13

#define MMI_IS_NUM(c)               ((c) >= L'0' && (c) <= L'9')
#define MMI_IS_VALID_SIM_PHONE_CHAR(c) ((c) == L'*' || (c) == L'+' || (c) == L'#')
#define MMI_IS_VALID_PHONE_CHAR(c)     (MMI_IS_VALID_SIM_PHONE_CHAR(c) || (c) == L'p' || (c) == L'P' || (c) == L'w' || (c) == L'W')
#define MMI_IS_ALPHA(c)             (((c) > 0x0020 && (c) <= 0x0241))

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
typedef struct
{
    BOOL is_sorted;
    S32 num_items;
    const wgui_multiline_icon_struct *items, *last_items;
} wgui_multiline_icon_handler_struct;


/***************************************************************************** 
 * Extern Functions and variables
 *****************************************************************************/
extern void StopTimer(U16 timerid);
extern S32 MMI_button_bar_height;
extern U16 GetExitScrnID(void);
extern mmi_editor_handler_struct g_mmi_editor_hanler;
extern void RedrawCategoryControlledArea200Screen(dm_coordinates *coordinate);
extern void PbookListSearchEntryReq(void);
extern void refresh_search_list_change_list_ext(S32 no_entries, S32 highlighted_item);
extern U8 inPinyinSearchScreen;
extern void refresh_search_list(U8 *name);
extern void PbookListSearchEntryReq(void);
extern U8 inPinyinSearchScreen;
extern S32(*cat200_search_function) (U8 *);
#if defined(__MMI_PHB_QUICK_SEARCH__)
extern void mmi_phb_quick_search_change_input_mode(void);
#endif 

/* store Main LCD height */
extern S32 MAIN_LCD_device_height;
extern void inline_fixed_list_goto_previous_item(void);
extern S8 hilited_item_changed;

#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
extern void  gui_set_WCSS_Esc_Char(MMI_BOOL v);
extern void  gui_change_WCSS_input_method(multi_line_input_box *b);
#endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 

extern U8 mmi_phb_convert_to_0x81(S8 *input_name, BOOL is_convert);

/* Api added to check that first hilighted item is multi line view box or not. */
extern U8 wgui_inline_item_handled;
extern wgui_inline_item *current_wgui_inline_item;
extern wgui_inline_item wgui_inline_items[];
extern void GetkeyInfo(U16 *keyCode, U16 *keyType); /* gives key code & key type of last key event */

#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
extern S8 MMI_multi_line_inputbox_present;
#endif 

#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
extern nsm_msg_struct g_nsm_msg_context;
#endif 

extern void inline_fixed_list_goto_next_item(void);

extern MMI_BOOL mmi_is_valid_symbol(U16 c);
extern MMI_BOOL mmi_is_no_need_symbol(U16 c);

#ifdef UI_EMS_SUPPORT
extern MMI_BOOL EMS_inputbox_direct_input(UI_character_type c);
#endif /* UI_EMS_SUPPORT */

extern MMI_BOOL inline_edit_singleline_inputbox_direct_input(UI_character_type c);

#endif /* __WGUI_INPUTS_INTERNAL_H__ */

