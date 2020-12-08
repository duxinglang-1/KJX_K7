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
 *    wgui_inputs.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Input related wrapper functions
 *
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/**
 * Copyright Notice
 * (c) 2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   Filename:      wgui_inputs.c
   Author:        manju
   Date Created:  August-07-2002
   Contains:      PixTel UI wrapper routines for Input related objects
**********************************************************************************/

/***************************************************************************** 
 * Include 
 *****************************************************************************/
//#include "mmi_frm_gprot.h"
#include "wgui_inputs_internal.h"
#include "CommonScreensProt.h"

#ifndef __MTK_TARGET__
#include "mmiapi_struct.h" /* HAL */
#endif

#ifdef __OP01_FWPBW__
#include "imui.h"
#endif


#ifdef __MMI_INDIC_ALG__
#include "IndicEngineGprot.h"
#endif 

//#include "WguiCategoryGprot.h"
#include "Wgui_softkeys.h"

#include "immProt.h"

#include "MenuCuiGprot.h"

#include "mmi_rp_srv_editor_def.h"
#include "mmi_rp_menu_misc_def.h"

    #include "MMIDataType.h"
    #include "gui_data_types.h"
    #include "gui_typedef.h"
    #include "kal_general_types.h"
    #include "ImeGprot.h"
    #include "IndicRuleEngineCommon.h"
    #include "gui_inputs.h"
    #include "MMI_features.h"
    #include "wgui_inputs.h"
    #include "CustThemesRes.h"
    #include "gui.h"
    #include "wgui.h"
    #include "Unicodexdcl.h"
    #include "kal_public_api.h"
    #include "DebugInitDef_Int.h"
    #include "wgui_categories_inputs.h"
    #include "string.h"
    #include "wgui_inline_edit.h"
    #include "gui_config.h"
    #include "gui_theme_struct.h"
    #include "gdi_datatype.h"
    #include "gdi_include.h"
    #include "wgui_categories_list.h"
    #include "wgui_categories_util.h"
    #include "CommonScreens.h"
    #include "CustDataRes.h"
    #include "GlobalResDef.h"
    #include "GlobalConstants.h"
    #include "mmi_frm_input_gprot.h"
    #include "mmi_frm_history_gprot.h"
    #include "wgui_include.h"
    #include "CustMenuRes.h"
    #include "mmi_frm_events_gprot.h"

#if !defined (__MTK_TARGET__)
#include "mmi_msg_struct.h"
#endif

#define WGUI_INPUTS_MENU_ITEM_SIZE  6
#define WGUI_INPUTS_SYMBOL_TABLE_ARRAY_MAX_SIZE 2

#ifdef __MMI_VUI_ENGINE__
extern U32 vadp_p2v_editor_direct_input(U8 index, U16 *string);
extern U32 vadp_p2v_uc_is_in_venus(void);
#endif

#ifdef UI_EMS_SUPPORT
extern void (*EMS_inputbox_input_callback) (void);
#endif
#ifndef __MMI_INLINE_SLIM__ 
extern single_line_input_box MMI_inline_singleline_inputbox;
extern  void (*inline_singleline_inputbox_input_callback) (void);
#endif
/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
typedef struct
{
    U16             icon_id;
    UI_string_type  string;
    UI_string_type  description;
    void (*f_entry) (void);
} wgui_inputs_menu_info_struct;

typedef struct 
{
    wgui_inputs_menu_info_struct    menu_info[WGUI_INPUTS_MENU_ITEM_SIZE];
    S32                             new_menu_item_num;
    S32                             input_method_index;
    S32                             edit_options_index;
    void (*highlight_handler) (S32 item_index);
    wgui_inputs_key_info_struct     key_info;
    MMI_BOOL                        menu_index_in_editor_range;
} wgui_inputs_option_menu_context;

typedef struct 
{
    MMI_ID group_id;
    MMI_ID screen_id;
    mmi_imm_allowed_character_list_struct symbol_table;
} wgui_inputs_symbol_table_struct;

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
/* multitap object wrappers            */
S32 MMI_multitap_x;
S32 MMI_multitap_y;
S32 MMI_multitap_width;
S32 MMI_multitap_height;
S32 MMI_general_inputbox_x;
S32 MMI_general_inputbox_y;
S32 MMI_general_inputbox_width;
S32 MMI_general_inputbox_height;

#if defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__)
	extern U8 g_advanced_settings_menustates_first_enter;
#endif
#if defined (__MMI_IME_INPUT_ADVANCED_SETTING__)
    extern MMI_BOOL  g_advanced_settings_changed;
#endif 
/* New IME start */
const UI_character_type english_uppercase_multitap_strings[MAX_MULTITAPS][6] = 
{
    {'\0'},
    {'\0'},
    {'A', 'B', 'C', '2', '\0'},
    {'D', 'E', 'F', '3', '\0'},
    {'G', 'H', 'I', '4', '\0'},
    {'J', 'K', 'L', '5', '\0'},
    {'M', 'N', 'O', '6', '\0'},
    {'P', 'Q', 'R', 'S', '7', '\0'},
    {'T', 'U', 'V', '8', '\0'},
    {'W', 'X', 'Y', 'Z', '9', '\0'},
#if defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
    {'\0'},
    {'\0'},
#endif 
};

const UI_character_type english_uppercase_no_number_multitap_strings[MAX_MULTITAPS][6] =    
{
    {'\0'},
    {'\0'},
    {'A', 'B', 'C', '\0'},
    {'D', 'E', 'F', '\0'},
    {'G', 'H', 'I', '\0'},
    {'J', 'K', 'L', '\0'},
    {'M', 'N', 'O', '\0'},
    {'P', 'Q', 'R', 'S', '\0'},
    {'T', 'U', 'V', '\0'},
    {'W', 'X', 'Y', 'Z', '\0'},
#if defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
    {'\0'},
    {'\0'},
#endif 
};

multitap_input g_active_multitap_table[MAX_MULTITAPS];

S32 g_active_multitap = -1;

/* for 0x81 encoding support for Phone Book */
S16 MMI_current_input_ext_type = 0;

S32 wgui_inputbox_information_bar_x;
S32 wgui_inputbox_information_bar_y;
S32 wgui_inputbox_information_bar_width;
S32 wgui_inputbox_information_bar_height;
U8 wgui_inputbox_information_flag = 0;

#ifdef __MMI_SMALL_EDIT_SCREEN__
U8 wgui_small_editor_information_flag = 0;
#endif 

mmi_editor_inoutbox_enum MMI_current_input_box_type = EDITOR_NONE_INPUT_BOX;

#if defined(__MMI_TOUCH_SCREEN__)
UI_filled_area information_bar_BG_filler = 
{
    UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_ROUNDED_BORDER | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {255, 185, 253, 100},
    {0, 0, 0, 0},
    {160, 72, 168, 100},
    {255, 0, 0, 100},
    0
};
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 

void (*wgui_inputbox_not_empty_callback) (void) = NULL;
void (*wgui_inputbox_empty_callback) (void) = NULL;
void (*wgui_inputbox_validation_callback) (U8 *text, U8 *cursor, S32 text_length) = NULL;
BOOL(*wgui_check_pound_key_buffer_flush) (void) = NULL;
S32(*wgui_inputbox_GSM_ext_count_function) (void) = NULL;
S32(*wgui_inputbox_UCS2_count_function) (void) = NULL;
void (*wgui_inputbox_insert_symbol) (UI_character_type c) = UI_dummy_function_character;
void (*wgui_inputbox_input_method_change_callback) (void) = NULL;
static wgui_inputs_option_menu_context g_wgui_inputs_option_menu_ctx;

static wgui_inputs_symbol_table_struct g_wgui_inputs_symbol_table[WGUI_INPUTS_SYMBOL_TABLE_ARRAY_MAX_SIZE] = {0};

U32 g_wgui_inputs_repeat_count;

/***************************************************************************** 
 * Local Function
 *****************************************************************************/
static void wgui_inputs_multitap_key_down_handler(S32 key);
static void wgui_inputs_multitap_key_up_handler(S32 key);
static void wgui_inputs_multitap_input_complete(void);
static U32 wgui_inputs_direct_input(U16 *input);

static void wgui_inputs_options_menu_save_key_info(void);
static void wgui_inputs_options_menu_restore_key_info(void);
static void wgui_inputs_options_menu_reset_key_info(void);
static void wgui_inputs_options_menu_config_menu_items(void);
static void wgui_inputs_options_menu_insert_menu(U16 icon_id, U16 menu_item, U16 hint, void (*f) (void));

static void (*g_wgui_inputs_option_menu_key_cb) (void) = NULL;
static void (*g_wgui_inputs_option_menu_highlight_cb) (U32) = NULL;

static MMI_BOOL wgui_inputs_fast_del_nav_check_callback(wgui_inputs_fast_del_nav_oper_enum op_type, wgui_inputs_fast_del_nav_editor_enum editor);
static FuncPtr wgui_inputs_fast_del_nav_get_op_handler(wgui_inputs_fast_del_nav_oper_enum op_type, wgui_inputs_fast_del_nav_editor_enum editor);

/***************************************************************************** 
 * Global Function
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  dummy_input_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void dummy_input_callback(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(c);
}


/*****************************************************************************
 * FUNCTION
 *  dummy_input_complete_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dummy_input_complete_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_set_current_input_box_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input_box_type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_set_current_input_box_type(mmi_editor_inoutbox_enum input_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_current_input_box_type = input_box_type;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_multitap_clear_key_handlers
 * DESCRIPTION
 *  Clears the key handlers used by the multitap objects
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_multitap_clear_key_handlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_MMI_key_input_handler();
}


/* 
 * API to read/write color editor buffer (UI_MULTI_LINE_INPUT_BOX_RICHTEXT) 
 * Please refer to gui_inputs.h for color buffer format
 */


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_color_buffer_create_reader
 * DESCRIPTION
 *  Create a reader object for buffer containing text format
 *  
 *  1.  The reader object can be released in memory directly.
 *  There is no other API to release it explicitly.
 *  2. If the content of 'buffer' is modified externally,
 *  reader object should be re-created.
 * PARAMETERS
 *  reader      [IN]        A reader object
 *  buffer      [IN]        Source text buffer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_color_buffer_create_reader(wgui_color_buffer_reader_struct *reader, U8 *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    reader->buffer = buffer;
    reader->head = 0;
    reader->byte_count = (mmi_ucs2strlen((S8*) buffer) << 1);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_color_buffer_read_stripped_text
 * DESCRIPTION
 *  Create a reader object for buffer containing text format
 *  
 *  dest_buffer will be null terminated
 * PARAMETERS
 *  reader              [IN]        A reader object
 *  dest_buffer         [IN]        Destination buffer
 *  size_of_dest        [IN]        Destination buffer size (including '\0')
 *  bytes_written       [OUT]       Number of bytes written into 'dest_buffer' (including '\0')
 * RETURNS
 *  Whether there are more bytes left to read
 *****************************************************************************/
BOOL wgui_inputs_color_buffer_read_stripped_text(
        wgui_color_buffer_reader_struct *reader,
        U8 *dest_buffer,
        S32 size_of_dest,
        S32 *bytes_written)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 rest, dst_cnt;
    U8 *src_ptr, *src_end;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rest = reader->byte_count - reader->head;

    /* At least two bytes are reserved for  */
    MMI_DBG_ASSERT(rest >= 0 && (rest % 2) == 0 && size_of_dest > 2);

    size_of_dest -= (size_of_dest % 2);
    size_of_dest -= 2;

    if (rest == 0 || size_of_dest <= 0)
    {
        return (rest > 0);
    }

    src_ptr = reader->buffer + reader->head;
    src_end = reader->buffer + reader->byte_count;
    for (dst_cnt = 0; src_ptr < src_end && dst_cnt < size_of_dest; src_ptr += 2)
    {
        U16 ch = ((U16) src_ptr[0]) | (((U16) src_ptr[1]) << 8);

        if (ch < GUI_INPUT_MARKER_BEGIN || ch > GUI_INPUT_MARKER_END)
        {
            dest_buffer[dst_cnt++] = src_ptr[0];
            dest_buffer[dst_cnt++] = src_ptr[1];
        }
    }
    dest_buffer[dst_cnt++] = '\0';
    dest_buffer[dst_cnt++] = '\0';

    *bytes_written = dst_cnt;
    reader->head = src_ptr - reader->buffer;

    if (src_ptr >= src_end)
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
 *  wgui_inputs_color_buffer_create_write
 * DESCRIPTION
 *  Create a writer object for buffer containing text format
 *  
 *  1.  The writer object can be released in memory directly.
 *  There is no other API to release it explicitly.
 *  2. If the content of 'buffer' is modified externally,
 *  writer object should be re-created.
 * PARAMETERS
 *  writer      [IN]        A writer object
 *  buffer      [IN]        Destination text buffer
 *  size        [IN]        Size of buffer in bytes
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_color_buffer_create_write(wgui_color_buffer_writer_struct *writer, U8 *buffer, S32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    writer->buffer = buffer;
    writer->tail = (mmi_ucs2strlen((S8*) buffer) << 1);
    writer->size = size - (size % 2);
    MMI_DBG_ASSERT(writer->size >= writer->tail + 2);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_color_buffer_get_space_for_write
 * DESCRIPTION
 *  Get the empty space in the destination buffer
 * PARAMETERS
 *  writer      [IN]        A writer object
 * RETURNS
 *  Number of bytes available to write (excl. '\0')
 *****************************************************************************/
S32 wgui_inputs_color_buffer_get_space_for_write(wgui_color_buffer_writer_struct *writer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = writer->size - writer->tail - 2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ret < 0)
    {
        ret = 0;
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_color_buffer_write_char
 * DESCRIPTION
 *  Append a character in destination buffer
 * PARAMETERS
 *  writer      [IN]        A writer object
 *  ch          [IN]        Character
 * RETURNS
 *  Is written successfully
 *****************************************************************************/
BOOL wgui_inputs_color_buffer_write_char(wgui_color_buffer_writer_struct *writer, U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (writer->size - writer->tail >= 4)
    {
        U8 *dst_ptr = writer->buffer + writer->tail;

        *dst_ptr++ = (U8) (ch & 0xFF);
        *dst_ptr++ = (U8) ((ch >> 8) & 0xFF);
        *dst_ptr++ = '\0';
        *dst_ptr++ = '\0';
        writer->tail += 2;
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_color_buffer_write_2char
 * DESCRIPTION
 *  Append two characters in destination buffer
 * PARAMETERS
 *  writer      [IN]        A writer object
 *  ch1         [IN]        Characters
 *  ch2         [IN]        Characters
 * RETURNS
 *  Is written successfully
 *****************************************************************************/
BOOL wgui_inputs_color_buffer_write_2char(wgui_color_buffer_writer_struct *writer, U16 ch1, U16 ch2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (writer->size - writer->tail >= 6)
    {
        U8 *dst_ptr = writer->buffer + writer->tail;

        *dst_ptr++ = (U8) (ch1 & 0xFF);
        *dst_ptr++ = (U8) ((ch1 >> 8) & 0xFF);
        *dst_ptr++ = (U8) (ch2 & 0xFF);
        *dst_ptr++ = (U8) ((ch2 >> 8) & 0xFF);
        *dst_ptr++ = '\0';
        *dst_ptr++ = '\0';
        writer->tail += 4;
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_color_buffer_write_3char
 * DESCRIPTION
 *  Append three characters in destination buffer
 * PARAMETERS
 *  writer      [IN]        A writer object
 *  ch1         [IN]        Characters
 *  ch2         [IN]        Characters
 *  ch3         [IN]        Characters
 * RETURNS
 *  Is written successfully
 *****************************************************************************/
BOOL wgui_inputs_color_buffer_write_3char(wgui_color_buffer_writer_struct *writer, U16 ch1, U16 ch2, U16 ch3)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (writer->size - writer->tail >= 8)
    {
        U8 *dst_ptr = writer->buffer + writer->tail;

        *dst_ptr++ = (U8) (ch1 & 0xFF);
        *dst_ptr++ = (U8) ((ch1 >> 8) & 0xFF);
        *dst_ptr++ = (U8) (ch2 & 0xFF);
        *dst_ptr++ = (U8) ((ch2 >> 8) & 0xFF);
        *dst_ptr++ = (U8) (ch3 & 0xFF);
        *dst_ptr++ = (U8) ((ch3 >> 8) & 0xFF);
        *dst_ptr++ = '\0';
        *dst_ptr++ = '\0';
        writer->tail += 6;
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_color_buffer_write_4char
 * DESCRIPTION
 *  Append four characters in destination buffer
 * PARAMETERS
 *  writer      [IN]        A writer object
 *  ch1         [IN]        Characters
 *  ch2         [IN]        Characters
 *  ch3         [IN]        Characters
 *  ch4         [IN]        Characters
 * RETURNS
 *  Is written successfully
 *****************************************************************************/
BOOL wgui_inputs_color_buffer_write_4char(wgui_color_buffer_writer_struct *writer, U16 ch1, U16 ch2, U16 ch3, U16 ch4)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (writer->size - writer->tail >= 10)
    {
        U8 *dst_ptr = writer->buffer + writer->tail;

        *dst_ptr++ = (U8) (ch1 & 0xFF);
        *dst_ptr++ = (U8) ((ch1 >> 8) & 0xFF);
        *dst_ptr++ = (U8) (ch2 & 0xFF);
        *dst_ptr++ = (U8) ((ch2 >> 8) & 0xFF);
        *dst_ptr++ = (U8) (ch3 & 0xFF);
        *dst_ptr++ = (U8) ((ch3 >> 8) & 0xFF);
        *dst_ptr++ = (U8) (ch4 & 0xFF);
        *dst_ptr++ = (U8) ((ch4 >> 8) & 0xFF);
        *dst_ptr++ = '\0';
        *dst_ptr++ = '\0';
        writer->tail += 8;
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_color_buffer_write_string
 * DESCRIPTION
 *  Append a string in destination buffer
 *  
 *  The writer object can be released in memory directly.
 *  There is no other API to release it explicitly.
 * PARAMETERS
 *  writer                      [IN]        A writer object
 *  string                      [IN]        Destination text buffer
 *  allow_partial_write         [IN]        If destination buffer does not have enough space
 *  whole_string_written        [OUT]       The whole string is written
 *  for(?)                      [IN]        The whole string, write partial string?
 * RETURNS
 *  Number of bytes written (excluding '\0')
 *****************************************************************************/
S32 wgui_inputs_color_buffer_write_string(
        wgui_color_buffer_writer_struct *writer,
        const U8 *string,
        BOOL allow_partial_write,
        BOOL *whole_string_written)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_size = (mmi_ucs2strlen((S8*) string) << 1);
    const U8 *src, *src_end;
    U8 *dst;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (writer->tail + str_size + 2 > writer->size)
    {
        if (!allow_partial_write)
        {
            return 0;
        }
        else
        {
            *whole_string_written = MMI_FALSE;
            str_size = writer->size - writer->tail - 2;
        }
    }
    else
    {
        *whole_string_written = MMI_TRUE;
    }
    src = string;
    src_end = string + str_size;
    dst = writer->buffer + writer->tail;
    while (src < src_end)
    {
        *dst++ = *src++;
    }
    *dst++ = '\0';
    *dst++ = '\0';
    writer->tail += str_size;

    return str_size;
}


/* Get the editor style of the current screen */


/*****************************************************************************
 * FUNCTION
 *  mmi_get_current_editor_style
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_get_current_editor_style(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_current_input_box_type != EDITOR_NONE_INPUT_BOX)
    {
        return MMI_current_input_box_type;
    }
    else
    {
        return -1;
    }
}

/* Check the content is valid */


/*****************************************************************************
 * FUNCTION
 *  mmi_is_input_content_valid
 * DESCRIPTION
 *  Check if the string to be inputed is valid string
 * PARAMETERS
 *  input       [in]     string to be inputed     
 * RETURNS
 *  MMI_TRUE if valid, MMI_FALSE if invalid
 *****************************************************************************/
MMI_BOOL mmi_is_input_content_valid(U16 *input)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *in = input;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*in != 0)
    {
        if (wgui_inputs_is_input_char_valid(*in) == MMI_FALSE)
        {
            return MMI_FALSE;
        }
        in++;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_is_input_char_valid
 * DESCRIPTION
 *  Check if the character to be inputed is valid character
 * PARAMETERS
 *  input       [in]       char need to check     
 * RETURNS
 *  MMI_TRUE if valid, MMI_FALSE if invalid
 *****************************************************************************/
MMI_BOOL wgui_inputs_is_input_char_valid(U16 in)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_imm_get_curr_input_type() & INPUT_TYPE_MASK)
    {
        case IMM_INPUT_TYPE_PHONE_NUMBER:
            if (MMI_current_input_ext_type & INPUT_TYPE_EXT_SIM_NUMERIC)
            {
                /* Allow to show ' *, +, 0-9, # */
                if (!MMI_IS_NUM(in) && !MMI_IS_VALID_SIM_PHONE_CHAR(in))
                {
                    return MMI_FALSE;
                }
                if (mmi_is_no_need_symbol(in))
                {
                    return MMI_FALSE;
                }
            }
            else
            {
                /* Allow to show '  *, +, p, w, 0-9, # */
                if (!MMI_IS_NUM(in) && !MMI_IS_VALID_PHONE_CHAR(in))
                {
                    return MMI_FALSE;
                }
                if (mmi_is_no_need_symbol(in))
                {
                    return MMI_FALSE;
                }
            }
            break;
        case IMM_INPUT_TYPE_NUMERIC:
        case IMM_INPUT_TYPE_NUMERIC_PASSWORD:
        case IMM_INPUT_TYPE_DECIMAL_NUMERIC:
        case IMM_INPUT_TYPE_DECIMAL_NUMERIC_PASSWORD:
            if (!MMI_IS_NUM(in) && (in != L'.'))
            {
                return MMI_FALSE;
            }
            if (mmi_is_no_need_symbol(in))
            {
                return MMI_FALSE;
            }
            break;
        case IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD:
            if (!MMI_IS_ALPHA(in) && !MMI_IS_NUM(in))
            {
				if (mmi_is_no_need_symbol(in))
                return MMI_FALSE;
            }
            if (mmi_is_no_need_symbol(in))
            {
                return MMI_FALSE;
            }
            break;
        case IMM_INPUT_TYPE_SAT_NUMERIC_PASSWORD:
            if (!MMI_IS_NUM(in) || (in != L'*') || (in != L'#'))
            {
                return MMI_FALSE;
            }
            if (mmi_is_no_need_symbol(in))
            {
                return MMI_FALSE;
            }
            break;
		case IMM_INPUT_TYPE_ASCII_CHAR:
            if (in > 0xFF)
            {
                return MMI_FALSE;
            }
			if (mmi_is_no_need_symbol(in))
			{
				return MMI_FALSE;
            }
            break;
        case IMM_INPUT_TYPE_EMAIL:
		case IMM_INPUT_TYPE_URL:
		case IMM_INPUT_TYPE_SIM_NUMERIC:
			if (mmi_is_no_need_symbol(in))
            {
                return MMI_FALSE;
            }
			break;

        default:
            if (MMI_current_input_ext_type & INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL)
            {
                /* Don't allow '\n' */
                if ((in == L'\n') || (in == 0x000a) || (in == 0x000d))
                {
                    return MMI_FALSE;
                }

                /* if character belong to symbol, check is it valid symbol */
                /*
                 * need to know the code set range of the symbols 
                 * if (!mmi_is_valid_symbol(*in)
                 * {
                 * return MMI_FALSE;
                 * }
                 */
			}	

            if (mmi_is_no_need_symbol(in))
            {
                return MMI_FALSE;
            }
            
            break;
    }

    return MMI_TRUE;
}


/* input the content to editor components */

#if !defined (__MTK_TARGET__)

#define WGUI_INPUT_DIRECT_INPUT_QUEUE_SIZE  8
static S32 g_modis_direct_input_count = 0;

/*****************************************************************************
 * FUNCTION
 *  mmi_direct_input_from_modis_req
 * DESCRIPTION
 *  Direct input string into editor from modis window
 * PARAMETERS
 *  p       [in]     input string
 * RETURNS
 *  number of character input into the module
 *****************************************************************************/
U32 mmi_direct_input_from_modis_req(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_direct_input_req_struct *data = (mmi_direct_input_req_struct*) p;
    U32 size = 0;
    U16 *input = data->input;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VUI_ENGINE__
    if (vadp_p2v_uc_is_in_venus())
    {
        size = vadp_p2v_editor_direct_input(0, input);
    }
    else
#endif
    {
        size = wgui_inputs_direct_input(input);
    }
    g_modis_direct_input_count--;

    return size;
}


/* send the message to MMI task to request input directly. */


/*****************************************************************************
 * FUNCTION
 *  mmi_send_direct_input_req
 * DESCRIPTION
 *  Set direct input message from modis window handler, MESSAGE ID:MSG_ID_MMI_EQ_DIRECT_INPUT_REQ
 * PARAMETERS
 *  input               [IN]         
 *  editor_style        [IN]        
 * RETURNS
 *  0 if failed, 1 if sucessful
 *****************************************************************************/
int mmi_send_direct_input_req(unsigned short *input, int editor_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE msgStruct;
    mmi_direct_input_req_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if the input is valid  */
    if (mmi_is_input_content_valid(input) == MMI_FALSE)
    {
        return 0;
    }

    /* Drop direct input messages if the reach max queue size */
    if (g_modis_direct_input_count > WGUI_INPUT_DIRECT_INPUT_QUEUE_SIZE)
    {
        return 1;
    }

    p = OslConstructDataPtr(sizeof(mmi_direct_input_req_struct));
    memcpy((char*)p->input, (char*)input, sizeof(p->input));
    p->editor_style = editor_style;

    msgStruct.oslSrcId = MOD_L4C;
    msgStruct.oslDestId = MOD_MMI;
    msgStruct.oslMsgId = MSG_ID_MMI_EQ_DIRECT_INPUT_REQ;
    msgStruct.oslSapId = 0;
    msgStruct.oslDataPtr = (oslParaType*) p;
    msgStruct.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&msgStruct);
    g_modis_direct_input_count++;

    SetProtocolEventHandler(mmi_direct_input_from_modis_req, MSG_ID_MMI_EQ_DIRECT_INPUT_REQ);
    return 1;
}

#endif 


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_direct_input_from_tst_module
 * DESCRIPTION
 *  Direct input string into MMI module from tst module using MSC composer or catcher
 * PARAMETERS
 *  index   [in]    string type, unicode(10, 11) or ascii(12, 13)
 *  p       [in]    input string     
 * RETURNS
 *  number of character input into the module
 *****************************************************************************/
U32 wgui_inputs_direct_input_from_tst_module(U8 index, U8 *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 size = 0;
    U16 *input = NULL;
    U32 i = 0;
    U16 input_buff[MMI_INJECT_STRING_TO_MODULE_MAX_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == MMI_INJECT_STRING_TO_MODULE_UNICODE_DONE_INDEX ||
        index == MMI_INJECT_STRING_TO_MODULE_UNICODE_UNDONE_INDEX)
    {
        /* For byte alignment */
        memcpy(input_buff, p, MMI_INJECT_STRING_TO_MODULE_MAX_LENGTH);
        input = input_buff;
        input[MMI_INJECT_STRING_TO_MODULE_MAX_LENGTH / ENCODING_LENGTH - 1] = 0;
    }
    else if (index == MMI_INJECT_STRING_TO_MODULE_ASCII_DONE_INDEX ||
             index == MMI_INJECT_STRING_TO_MODULE_ASCII_UNDONE_INDEX)
    {
        p[MMI_INJECT_STRING_TO_MODULE_MAX_LENGTH - 1] = 0;
        while ((*p) != 0)
        {
            input_buff[i++] = *(p++);
        }
        input_buff[i] = 0;
        input = input_buff;
    }
    else
    {
        return 0;
    }
    
    size = wgui_inputs_direct_input(input);
    return size;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_direct_input
 * DESCRIPTION
 *  Direct input string into MMI module character by character
 * PARAMETERS
 *  input       [in]    input string     
 * RETURNS
 *  number of character input into the module
 *****************************************************************************/
static U32 wgui_inputs_direct_input(U16 *input)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 style = 0;
    U32 size = 0;
    U8  flag_callback = 0;
        U32 old_show_action_flag = 0;
        S32 old_show_action_s    = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_reset_ime_state();
    style = mmi_get_current_editor_style();
    switch (style)
    {
        case EDITOR_MULTILINE_INPUT_BOX:
                old_show_action_flag = MMI_multiline_inputbox.show_action_flag;
                MMI_multiline_inputbox.show_action_flag = 0;
            while ((*input) != 0)
            {
                if (((*input)==0x0d) && (*(input+1)==0x0a))
                {
                    /* Editor component will insert 0x0d, 0x0a when receiving 0x0a */
                    input++;
                }
                if (wgui_inputs_is_input_char_valid(*input))
                {
                    if (!wgui_inputs_ml_direct_input_no_draw(*input))
                    {
                        break;
                    }
                    flag_callback = 1;
                }
                input++;
                size++;
            }
                MMI_multiline_inputbox.show_action_flag = old_show_action_flag;
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
                gui_mlc_all_line_update();
#endif                
            wgui_inputs_ml_redraw();            
            if (flag_callback)
            {
            #if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
                if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INCLUDE_INFO_AREA))
            #endif 
                    multiline_inputbox_input_callback();
            }
            break;
#ifdef UI_EMS_SUPPORT
        case EDITOR_EMS_INPUT_BOX:
                old_show_action_flag = MMI_EMS_inputbox.show_action_flag;
                MMI_EMS_inputbox.show_action_flag = 0;
            while ((*input) != 0)
            {
                if (((*input)==0x0d) && (*(input+1)==0x0a))
                {
                    /* Editor component will insert 0x0d, 0x0a when receiving 0x0a */
                    input++;
                }
                if (wgui_inputs_is_input_char_valid(*input))
                {
                    if (!EMS_inputbox_direct_input_no_draw(*input))
                    {
                        break;
                    }
                    flag_callback = 1;
                }
                input++;
                size++;
            }
                MMI_EMS_inputbox.show_action_flag = old_show_action_flag;
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
                gui_emsc_all_line_update();
#endif                
                gui_EMS_input_box_locate_cursor(&MMI_EMS_inputbox);
            redraw_EMS_inputbox();
            EMS_inputbox_input_callback();
            break;       
#endif /* UI_EMS_SUPPORT */

        case EDITOR_SINGLE_LINE_INPU_BOX:
                old_show_action_s = MMI_singleline_inputbox.show_action_flag;
                MMI_singleline_inputbox.show_action_flag = 0;
            while ((*input) != 0)
            {
                if (((*input)==0x0d) && (*(input+1)==0x0a))
                {
                    /* Editor component will insert 0x0d, 0x0a when receiving 0x0a */
                    input++;
                }
                if (wgui_inputs_is_input_char_valid(*input))
                {
                    if (!wgui_inputs_sl_direct_input_no_draw(*input))
                    {
                        break;
                    }
                    flag_callback = 1;
                }
                input++;
                size++;
            }
                MMI_singleline_inputbox.show_action_flag = old_show_action_s;
                gui_single_line_input_box_locate_cursor(&MMI_singleline_inputbox);
            wgui_inputs_sl_redraw();
            singleline_inputbox_input_callback();
            break;
        case EDITOR_INLINE_MULTILINE_INPUT_BOX:
                old_show_action_flag = MMI_multiline_inputbox.show_action_flag;
                MMI_multiline_inputbox.show_action_flag = 0;
            while ((*input) != 0)
            {
                if (((*input)==0x0d) && (*(input+1)==0x0a))
                {
                    /* Editor component will insert 0x0d, 0x0a when receiving 0x0a */
                    input++;
                }
                if (wgui_inputs_is_input_char_valid(*input))
                {
                    if (!wgui_inputs_ml_direct_input_no_draw(*input))
                    {
                        break;
                    }
                    flag_callback = 1;
                }
                input++;
                size++;
            }
                MMI_multiline_inputbox.show_action_flag = old_show_action_flag;
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
                gui_mlc_all_line_update();
#endif                
            wgui_inputs_ml_redraw();

            if (flag_callback)
            {
            #if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
                if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INCLUDE_INFO_AREA))
            #endif 
                    multiline_inputbox_input_callback();
            }
            break;
        case EDITOR_QUICK_SEARCH_SINGLE_LINE_INPU_BOX:
            /* No use */
            break;
        case EDITOR_INLINE_TEXT:
#ifndef __MMI_INLINE_SLIM__            
                old_show_action_s = MMI_inline_singleline_inputbox.show_action_flag;
                MMI_inline_singleline_inputbox.show_action_flag = 0;
            while ((*input) != 0)
            {
                if (((*input)==0x0d) && (*(input+1)==0x0a))
                {
                    /* Editor component will insert 0x0d, 0x0a when receiving 0x0a */
                    input++;
                }
                if (wgui_inputs_is_input_char_valid(*input))
                {
                    if (!inline_edit_singleline_inputbox_direct_input_no_draw(*input))
                    {
                        break;
                    }
                    flag_callback = 1;
                }
                input++;
                size++;
            }
                MMI_inline_singleline_inputbox.show_action_flag = old_show_action_s;
                gui_single_line_input_box_locate_cursor(&MMI_inline_singleline_inputbox);
            if (!gui_screen_smooth_scrolling_moved_by_pen())
            {
                redraw_inline_singleline_inputbox();
            }
            inline_singleline_inputbox_input_callback();
#endif            
            break;
        default:
            return 0;
    }    
    return size;
}


/*****************************************************************************
* FUNCTION
*  wgui_inputs_multitap_setup_functions
* DESCRIPTION
* PARAMETERS
* void        
* RETURNS
*  void
*****************************************************************************/
MMI_BOOL wgui_inputs_multitap_setup_functions(wgui_multitap_type_enum multitap_type, void (*input_callback) (UI_character_type), void (*input_complete_callback) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type  multitap_table;
    S32 i;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_MULTITAPS; i++)
    {
		switch(multitap_type)
		{
		case WGUI_MULTITAP_TYPE_UPPERCASE_ABC:
			
			multitap_table = (UI_string_type)english_uppercase_multitap_strings[i];
			ret =  MMI_TRUE;
			
			break;
			
		case WGUI_MULTITAP_TYPE_UPPERCASE_ABC_NO_NUMBER:
			multitap_table = (UI_string_type)english_uppercase_no_number_multitap_strings[i];
			ret =  MMI_TRUE;
			break;
			
		default:
			ret =  MMI_FALSE;
			break;
		}
        
		if (!ret)
        {
            break;
		}

        gui_create_multitap_input(
            &g_active_multitap_table[i],
            MMI_multitap_x,
            MMI_multitap_y,
            MMI_multitap_width,
            MMI_multitap_height,
            multitap_table);
        
        gui_set_multitap_input_callbacks(&g_active_multitap_table[i], input_callback, input_complete_callback);
    }

    if (ret)
    {
        register_MMI_key_input_handler();
        register_key_up_handler(wgui_inputs_multitap_key_up_handler);
        register_key_down_handler(wgui_inputs_multitap_key_down_handler);
        
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
* FUNCTION
*  wgui_inputs_multitap_reset
* DESCRIPTION
* PARAMETERS
* void        
* RETURNS
*  void
*****************************************************************************/
void wgui_inputs_multitap_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_active_multitap = -1;

    gui_cancel_timer(wgui_inputs_multitap_input_complete);
        
    for (i = 0; i < MAX_MULTITAPS; i++)
    {
        gui_set_multitap_input_callbacks(&g_active_multitap_table[i], dummy_input_callback, dummy_input_complete_callback);
    }
}


/*****************************************************************************
* FUNCTION
*  wgui_inputs_multitap_stop
* DESCRIPTION
* PARAMETERS
* void        
* RETURNS
*  void
*****************************************************************************/
void wgui_inputs_multitap_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (g_active_multitap >= 0)
	{
	    g_active_multitap_table[g_active_multitap].current_position = g_active_multitap_table[g_active_multitap].length - 1;
    }

    g_active_multitap = -1;

    gui_cancel_timer(wgui_inputs_multitap_input_complete);
}


/*****************************************************************************
* FUNCTION
*  wgui_inputs_multitap_key_down_handler
* DESCRIPTION
* PARAMETERS
* void        
* RETURNS
*  void
*****************************************************************************/
static void wgui_inputs_multitap_key_down_handler(S32 key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_active_multitap != key && g_active_multitap >= 0)
    {
        gui_multitap_input_complete(&g_active_multitap_table[g_active_multitap]);
    }
    
    g_active_multitap = key;

    gui_change_multitap_input_state(&g_active_multitap_table[g_active_multitap]);
}


/*****************************************************************************
* FUNCTION
*  wgui_inputs_multitap_key_up_handler
* DESCRIPTION
* PARAMETERS
* void        
* RETURNS
*  void
*****************************************************************************/
static void wgui_inputs_multitap_key_up_handler(S32 key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(key);

    if (g_active_multitap >= 0)
    {
        if (g_active_multitap_table[g_active_multitap].length > 0)
        {
            gui_start_timer(MMI_MULTITAP_TIMEOUT, wgui_inputs_multitap_input_complete);
        }
        else
        {
            g_active_multitap = -1;
        }
    }
}


/*****************************************************************************
* FUNCTION
*  wgui_inputs_multitap_input_complete
* DESCRIPTION
* PARAMETERS
* void        
* RETURNS
*  void
*****************************************************************************/
static void wgui_inputs_multitap_input_complete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_active_multitap >= 0)
    {
        gui_multitap_input_complete(&g_active_multitap_table[g_active_multitap]);
        g_active_multitap = -1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_is_r2l_display
 * DESCRIPTION
 *  query r2lMMIFlag
 *  Input Parameter      void
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL wgui_inputs_is_r2l_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_fe_get_r2l_state())
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
 *  wgui_inputs_register_pound_key_buffer_flush_test_function
 * DESCRIPTION
 *  
 * PARAMETERS
 *  FuncPtr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_register_pound_key_buffer_flush_test_function(BOOL(*FuncPtr) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_check_pound_key_buffer_flush = FuncPtr;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_register_validation_func
 * DESCRIPTION
 *  register input box validation function
 * PARAMETERS
 *  f       [IN]        )(U8*,U8*,S32) function pointer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_register_validation_func(void (*f) (U8 *, U8 *, S32))
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
 *  wgui_inputs_register_not_empty_func
 * DESCRIPTION
 *  register input box validation function
 * PARAMETERS
 *  f       [IN]        )(void) function pointer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_register_not_empty_func(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputbox_not_empty_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_register_input_method_change_func
 * DESCRIPTION
 *  register input box input method change function
 * PARAMETERS
 *  f       [IN]        function pointer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_register_input_method_change_func(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputbox_input_method_change_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_register_empty_func
 * DESCRIPTION
 *  register input box validation function
 * PARAMETERS
 *  f       [IN]        )(void) function pointer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_register_empty_func(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputbox_empty_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_get_ucs2_count
 * DESCRIPTION
 *  Returns the number of UCS2 characters present
 *  in the current inputbox buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  Number of UCS2 characters
 *****************************************************************************/
S32 wgui_inputs_get_ucs2_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_inputbox_UCS2_count_function != NULL)
    {
        return (wgui_inputbox_UCS2_count_function());
    }
    else
    {
        return (0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_get_ext_gsm_count
 * DESCRIPTION
 *  Returns the number of GSM extended characters present
 *  in the current inputbox buffer.
 * PARAMETERS
 *  void
 * RETURNS
 *  Number of GSM extended characters
 *****************************************************************************/
S32 wgui_inputs_get_ext_gsm_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_inputbox_GSM_ext_count_function != NULL)
    {
        return (wgui_inputbox_GSM_ext_count_function());
    }
    else
    {
        return (0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_redraw_input_mode_only
 * DESCRIPTION
 *  change input mode of single line input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_redraw_input_mode_only(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = wgui_inputbox_information_bar_x;
    S32 y1 = wgui_inputbox_information_bar_y;
    S32 x2 = x1 + wgui_inputbox_information_bar_width - 1;
    S32 y2 = y1 + wgui_inputbox_information_bar_height - 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    wgui_inputs_input_information_background(x1, y1, x2, y2);
    wgui_inputs_show_input_mode(mmi_imm_get_curr_input_mode(), NULL);
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 

}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_setup_input_information
 * DESCRIPTION
 *  set input information of  input box like bar width/bar height
 * PARAMETERS
 *  x           [IN]        Start x position of input box
 *  y           [IN]        Start y position of input box
 *  width       [IN]        Width of input box
 *  height      [IN]        Height of input box
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_setup_input_information(S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputbox_information_bar_x = x;
    wgui_inputbox_information_bar_y = y;
    wgui_inputbox_information_bar_width = width;
    wgui_inputbox_information_bar_height = height;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_input_information_background
 * DESCRIPTION
 *  fill the background color of information of input box
 * PARAMETERS
 *  x1      [IN]        Start x position of input box
 *  y1      [IN]        Start y position of input box
 *  x2      [IN]        End x position of input box
 *  y2      [IN]        End y position of input box
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_input_information_background(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Now reads color from the theme structure  */
    color c = current_information_bar_theme->background_color;
    U32 alpha = ((U32) current_information_bar_theme->background_alpha) * 255 / 100;
	gdi_handle act_layer, src_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_push_clip();
    gui_reset_clip();

    gdi_layer_get_active(&act_layer);
    gdi_get_alpha_blending_source_layer(&src_layer);

    if ((act_layer != src_layer) && src_layer)
    {
        gdi_effect_alpha_blending_rect(src_layer, x1, y1, x2, y2, alpha, c.r, c.g, c.b);
    }
    else if (act_layer)
    {
        gdi_effect_alpha_blending_rect(act_layer, x1, y1, x2, y2, 255, c.r, c.g, c.b);
    }

    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_hide_input_information_bar
 * DESCRIPTION
 *  hide information bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_hide_input_information_bar()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = 0;
    S32 y1 = wgui_inputbox_information_bar_y;
    S32 x2 = UI_device_width - 1;
    S32 y2 = wgui_inputbox_information_bar_y + wgui_inputbox_information_bar_height - 1;
    color c = gui_color(255, 255, 255);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_reset_clip();
    gui_fill_rectangle(x1, y1, x2, y2, c);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_redraw_input_information_background
 * DESCRIPTION
 *  redrwa input information background
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_redraw_input_information_background(void)
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
    gui_lock_double_buffer();
    wgui_inputs_input_information_background(x1, y1, x2, y2);
    wgui_inputs_show_input_mode(mmi_imm_get_curr_input_mode(), NULL);
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);

}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_show_input_mode_internal
 * DESCRIPTION
 *  wgui_inputs_show_input_mode_internal
 * PARAMETERS
 *  input_mode                      [IN]        
 *  inputbox_information_icon       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_show_input_mode_internal(
                    S32 info_bar_x,
                    S32 info_bar_y,
                    S32 info_bar_width,
                    S32 info_bar_height,
                    mmi_imm_input_mode_enum input_mode, 
                    PU8 inputbox_information_icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_draw_input_mode_infor(info_bar_x, info_bar_y, info_bar_x + info_bar_width - 1, info_bar_y + info_bar_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_show_input_mode
 * DESCRIPTION
 *  show current input mode on the top of editor scrren
 * PARAMETERS
 *  input_mode                      [IN]        
 *  inputbox_information_icon       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_show_input_mode(mmi_imm_input_mode_enum input_mode, PU8 inputbox_information_icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_show_input_mode_internal(
                    wgui_inputbox_information_bar_x,
                    wgui_inputbox_information_bar_y,
                    wgui_inputbox_information_bar_width,
                    wgui_inputbox_information_bar_height,
                    input_mode,
                    inputbox_information_icon);

}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_set_LSK_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_set_LSK_func(FuncPtr f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_key_setup_lsk_function(f);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_set_LSK_text
 * DESCRIPTION
 * PARAMETERS    
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_set_LSK_text(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_key_setup_lsk_text();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ucs2_to_gb_len
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 wgui_inputs_ucs2_to_gb_len(U16 ucs2_char)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ucs2_char <= 255)
        return 1;
    else
        return 2;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_input_box_msg_call_back
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_input_box_msg_call_back(void * input_box_handle, mmi_imc_message_struct_p msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(((mmi_editor_handler_struct *)input_box_handle)->input_box_type)
    {
    case MMI_EDITOR_MULTILINE_INPUT_BOX:
        return mmi_input_box_msg_call_back_multiline(input_box_handle, msg_ptr);
        
#ifdef UI_EMS_SUPPORT
    case MMI_EDITOR_EMS_INPUT_BOX:
        return mmi_input_box_msg_call_back_ems(input_box_handle, msg_ptr);
#endif /* UI_EMS_SUPPORT */

    default:
        break;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_options_add_menu_items
 * DESCRIPTION
 *  Insert new menu item after Input method menu item.
 * PARAMETERS
 *  number_of_items             [IN]        number of items before add editor menu item
 *  list_of_items               [IN]        list of menu item string
 *  new_list_of_items           [OUT]       list of menu item string after add editor menu item
 *  list_of_icons               [IN]        list of menu icons
 *  new_list_of_icons           [IN]        list of menu icons after add editor menu item
 *  list_of_descriptions        [IN]        list of menu descriptions
 *  new_list_of_descriptions    [IN]        list of menu descriptions after add editor menu item
 *  f_highlight                 [IN]        App's highlight handler
 *  f_close                     [IN]        Close function to return to editor screen
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  number of menu items after add editor menu item
 *****************************************************************************/
U16 wgui_inputs_options_add_menu_items(
         S32 number_of_items,
         U8 **list_of_items,
         U8 **new_list_of_items,
         U16 *list_of_icons,
         U16 *new_list_of_icons,
         U8 **list_of_descriptions,
         U8 **new_list_of_descriptions,
         void (*f_highlight) (S32 item_index),
         void (*f_close) (void),
         U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    S32 j = 0;
    S32 k = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RegisterHighlightHandler(wgui_inputs_options_menu_highlight_handler);
    RegisterInputMethodScreenCloseFunction(f_close);
    /* Initialize */
    g_wgui_inputs_option_menu_ctx.input_method_index = -1;
    g_wgui_inputs_option_menu_ctx.edit_options_index = -1;
    g_wgui_inputs_option_menu_ctx.new_menu_item_num = 0;
    g_wgui_inputs_option_menu_ctx.menu_index_in_editor_range = MMI_FALSE;

    /* Saving App's highlight handler */
    g_wgui_inputs_option_menu_ctx.highlight_handler = f_highlight;

    if (history_buffer == NULL)
    {
        wgui_inputs_options_menu_reset_key_info();
    }
    else
    {
        wgui_inputs_options_menu_set_editor_history(history_buffer);
    }

#if defined(__MMI_CLIPBOARD__)
    /* Save Edit option menu index in to history */    
    for (i = 0; i < number_of_items; i++)
    {
        if (list_of_items != NULL)
        {
            if (!mmi_ucs2cmp((const S8 *)list_of_items[i], (const S8 *)GetString(STR_ID_CLIPBOARD_EDIT_OPTION)))
            {
                g_wgui_inputs_option_menu_ctx.edit_options_index = i;
                break;
            }
        }
    }
#endif

    /* Find Input method index */    
    for (i = 0; i < number_of_items; i++)
    {
        if (list_of_items != NULL)
        {
            if (!mmi_ucs2cmp((const S8 *)list_of_items[i], (const S8 *)GetString(STR_GLOBAL_INPUT_METHOD)))
            {
                g_wgui_inputs_option_menu_ctx.input_method_index = i;
                break;
            }
        }
    }
    /* Use gIndexIconsImageList for Option list icon */
    if ((list_of_icons != NULL) && (list_of_icons != (U16 *)gIndexIconsImageList) &&
        (g_wgui_inputs_option_menu_ctx.input_method_index != -1))
    {
        list_of_icons = (U16 *)gIndexIconsImageList;
    }

    /* Add the app's menu item when it's not Input method menu item */
    for (i = 0; i < number_of_items; i++)
    {
        /* Menu item string */
        if (list_of_items != NULL)
        {
            if (!mmi_ucs2cmp((const S8 *)list_of_items[i], (const S8 *)GetString(STR_GLOBAL_INPUT_METHOD)))
            {
                g_wgui_inputs_option_menu_ctx.input_method_index = i;
                break;    
            }
            new_list_of_items[i] = list_of_items[i];
        }
        /* Menu item icons */
        if ((list_of_icons != NULL) && (list_of_icons != (U16 *)gIndexIconsImageList))
        {
            new_list_of_icons[i] = list_of_icons[i];
        }
        else if (list_of_icons == (U16 *)gIndexIconsImageList)
        {
            if (i < MAX_GLOBAL_IMAGE_LIST)
            {
                new_list_of_icons[i] = (U16)gIndexIconsImageList[i];
            }
            else
            {
                new_list_of_icons[i] = 0;
            }
        }
        /* Menu item descriptions */
        if (list_of_descriptions != NULL)
        {
            new_list_of_descriptions[i] = list_of_descriptions[i];
        }
    }

    /* If contains input method menu item, we insert editor internal menu items */
    if (g_wgui_inputs_option_menu_ctx.input_method_index >= 0)
    {
        /* Config editor menu item */
        wgui_inputs_options_menu_config_menu_items();

        for (k = 0; k < g_wgui_inputs_option_menu_ctx.new_menu_item_num; k++)
        {
            /* Menu item string */
            if (list_of_items != NULL)
            {
                new_list_of_items[i] = (U8 *)(g_wgui_inputs_option_menu_ctx.menu_info[k].string);
            }
            /* Menu item icons */
            if ((list_of_icons != NULL) && (list_of_icons != (U16 *)gIndexIconsImageList))
            {
                new_list_of_icons[i] = g_wgui_inputs_option_menu_ctx.menu_info[k].icon_id;
            }
            else if (list_of_icons == (U16 *)gIndexIconsImageList)
            {
                if (i < MAX_GLOBAL_IMAGE_LIST)
                {
                    new_list_of_icons[i] = (U16)gIndexIconsImageList[i];
                }
                else
                {
                    new_list_of_icons[i] = 0;
                }
            }
            /* Menu item descriptions */
            if (list_of_descriptions != NULL)
            {
                new_list_of_descriptions[i] = (U8 *)(g_wgui_inputs_option_menu_ctx.menu_info[k].description);
            }
            i++;
        }

        /* Add the rest of the app's menu item */
        for (j = g_wgui_inputs_option_menu_ctx.input_method_index + 1; j < number_of_items; j++)
        {
            /* Menu item string */
            if (list_of_items != NULL)
            {
                new_list_of_items[i] = list_of_items[j];
            }
            /* Menu item icons */
            if ((list_of_icons != NULL) && (list_of_icons != (U16 *)gIndexIconsImageList))
            {
                new_list_of_icons[i] = list_of_icons[j];
            }
            else if (list_of_icons == (U16 *)gIndexIconsImageList)
            {
                if (i < MAX_GLOBAL_IMAGE_LIST)
                {
                    new_list_of_icons[i] = (U16)gIndexIconsImageList[i];
                }
                else
                {
                    new_list_of_icons[i] = 0;
                }
            }
            /* Menu item descriptions */
            if (list_of_descriptions != NULL)
            {
                new_list_of_descriptions[i] = list_of_descriptions[j];
            }
            i++;
        }
    }

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_options_menu_highlight_handler
 * DESCRIPTION
 *  The main highlight hanlder of option menu list category. It will call different
 *  highlight handler according to current highlight index.
 * PARAMETERS
 *  item_index          [IN]        highlight index
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_options_menu_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wgui_inputs_option_menu_ctx.input_method_index < 0)
    {
        /* No input method menu item in the list */
        g_wgui_inputs_option_menu_ctx.highlight_handler(item_index);

        g_wgui_inputs_option_menu_ctx.menu_index_in_editor_range = MMI_FALSE;
    }
    else if (item_index < g_wgui_inputs_option_menu_ctx.input_method_index || item_index >= (g_wgui_inputs_option_menu_ctx.input_method_index + g_wgui_inputs_option_menu_ctx.new_menu_item_num))
    {
        /* With input method menu item in the list, and hightlight on the App's menu item */
        wgui_inputs_options_menu_restore_key_info();
        index = item_index;
        /* Mapping to old index */
        if (item_index >= (g_wgui_inputs_option_menu_ctx.input_method_index + g_wgui_inputs_option_menu_ctx.new_menu_item_num))
        {
            item_index -= (g_wgui_inputs_option_menu_ctx.new_menu_item_num - 1);
        }

        /* If App register special highlight cb, we should use this highlight call back and pass
           real highlight index instead of index after mapping */
        if (g_wgui_inputs_option_menu_highlight_cb)
        {
            g_wgui_inputs_option_menu_highlight_cb(index);
        }
        else
        {
            g_wgui_inputs_option_menu_ctx.highlight_handler(item_index);
        }

        g_wgui_inputs_option_menu_ctx.menu_index_in_editor_range = MMI_FALSE;
    }
    else
    {
        /* We need to call app's registered highlight handler although it will be overwrite by Editor's highlight handler because
           for some app's highlight handler, it will save the highlight index in its own context instead of gui buffer.
           For example, Q03C V1 WAP */
        if (g_wgui_inputs_option_menu_highlight_cb)
        {
            g_wgui_inputs_option_menu_highlight_cb(item_index);
        }

        /* With input method menu item in the list, and hightlight on the Editor's menu item */
        wgui_inputs_options_menu_save_key_info();
        index = (item_index - g_wgui_inputs_option_menu_ctx.input_method_index);
        set_softkey_label_for_IME((UI_string_type)GetString(STR_GLOBAL_SELECT), MMI_LEFT_SOFTKEY);
        set_softkey_label_for_IME((UI_string_type)GetString(STR_GLOBAL_BACK), MMI_RIGHT_SOFTKEY);
        redraw_left_softkey();
        redraw_right_softkey();
        SetLeftSoftkeyFunction(g_wgui_inputs_option_menu_ctx.menu_info[index].f_entry, KEY_EVENT_UP);
        SetKeyHandler(g_wgui_inputs_option_menu_ctx.menu_info[index].f_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(g_wgui_inputs_option_menu_ctx.menu_info[index].f_entry, KEY_EVENT_UP);

        /* Register app's key call back. (LSK/RSK key handler override) */
        if (g_wgui_inputs_option_menu_key_cb)
        {
            g_wgui_inputs_option_menu_key_cb();
        }
        g_wgui_inputs_option_menu_ctx.menu_index_in_editor_range = MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_options_menu_save_key_info
 * DESCRIPTION
 *  Save APP's key info, when highlight Editor's menu item, App's key info will be save
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inputs_options_menu_save_key_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_wgui_inputs_option_menu_ctx.key_info.is_saved)
    {
        g_wgui_inputs_option_menu_ctx.key_info.f_LSK = get_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
        g_wgui_inputs_option_menu_ctx.key_info.f_RSK = get_softkey_function(KEY_EVENT_UP, MMI_RIGHT_SOFTKEY);
        g_wgui_inputs_option_menu_ctx.key_info.f_CSK = get_softkey_function(KEY_EVENT_UP, MMI_CENTER_SOFTKEY);
        g_wgui_inputs_option_menu_ctx.key_info.f_left_arrow = GetKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        g_wgui_inputs_option_menu_ctx.key_info.f_right_arrow = GetKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

        g_wgui_inputs_option_menu_ctx.key_info.csk_icon = get_softkey_icon(MMI_CENTER_SOFTKEY);
        /* Set key info saving flag. When restore and save key info, the flag will be used */
        g_wgui_inputs_option_menu_ctx.key_info.is_saved = MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_options_menu_restore_key_info
 * DESCRIPTION
 *  Restore the APP's key info, when highlight App's menu item, the key will be restored.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inputs_options_menu_restore_key_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wgui_inputs_option_menu_ctx.key_info.is_saved)
    {
        SetLeftSoftkeyFunction(g_wgui_inputs_option_menu_ctx.key_info.f_LSK, KEY_EVENT_UP);
        SetRightSoftkeyFunction(g_wgui_inputs_option_menu_ctx.key_info.f_RSK, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(g_wgui_inputs_option_menu_ctx.key_info.f_CSK, KEY_EVENT_UP);
        SetKeyHandler(g_wgui_inputs_option_menu_ctx.key_info.f_left_arrow, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(g_wgui_inputs_option_menu_ctx.key_info.f_right_arrow, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

        /* Restore Softkey label */
        set_softkey_label_for_IME(mmi_imc_key_get_lsk_text(), MMI_LEFT_SOFTKEY);
        set_softkey_label_for_IME(mmi_imc_key_get_rsk_text(), MMI_RIGHT_SOFTKEY);
        set_softkey_icon(g_wgui_inputs_option_menu_ctx.key_info.csk_icon, MMI_CENTER_SOFTKEY);
        redraw_left_softkey();
        redraw_right_softkey();
        redraw_center_softkey();

        g_wgui_inputs_option_menu_ctx.key_info.is_saved = MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_options_menu_reset_key_info
 * DESCRIPTION
 *  Reset key info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inputs_options_menu_reset_key_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_wgui_inputs_option_menu_ctx.key_info, 0, sizeof(wgui_inputs_key_info_struct));
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_options_menu_config_menu_items
 * DESCRIPTION
 *  Config editor option menu item. Call wgui_inputs_options_menu_insert_menu()
 *  to insert menu item one by one, the adding sequence will decide the menu item
 *  sequence in the option list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inputs_options_menu_config_menu_items(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_set_id = 0;
    U16 str_new_word_id = 0;
#if defined(__MMI_CLIPBOARD__)    
    U16 list_num;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Initialize editor menu info struct */
    g_wgui_inputs_option_menu_ctx.new_menu_item_num = 0;
    memset(&g_wgui_inputs_option_menu_ctx.menu_info, 0, sizeof(wgui_inputs_menu_info_struct) * WGUI_INPUTS_MENU_ITEM_SIZE);

#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
#if defined(__MMI_ZI__)
    str_set_id = STR_INPUT_METHOD_MENU_SET_ZI;
#elif defined(__MMI_T9__)
    str_set_id = STR_INPUT_METHOD_MENU_SET_T9;
#elif defined(__MMI_CSTAR__)
    str_set_id = STR_INPUT_METHOD_MENU_SET_CSTAR;
#endif
#endif

#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && ( defined(__MMI_IME_USER_DATABASE__)||  ( defined(__MMI_CSTAR_USER_DICT__) && !defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_IME_USER_DATABASE__))   ) && (defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_IME_FTE_ENHANCE__))
#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_IME_USER_DATABASE__) && defined(__MMI_EDITOR_OPTION_MENU_STYLE_2__) && defined(__MMI_NORMAL_KEYPAD__)
#if defined(__MMI_ZI__)
    str_new_word_id = STR_INPUT_METHOD_MENU_NEW_ZI_WORD;
#elif defined(__MMI_T9__)
    str_new_word_id = STR_INPUT_METHOD_MENU_NEW_T9_WORD;
#elif defined(__MMI_CSTAR__)
    str_new_word_id = STR_INPUT_METHOD_MENU_NEW_CSTAR_WORD;
#endif
#endif
#endif

#if defined(__MMI_EDITOR_OPTION_MENU_STYLE_1__)

    wgui_inputs_options_menu_insert_menu(
        NULL,
        STR_INPUT_METHOD_MENU_INSERT_SYMBOLS,
        0,
        EntrySymbolPickerScreenFromMenuList);

    #if defined(__MMI_IMC_CAPITAL_SWITCH__)
        if (mmi_imm_get_current_allowed_input_mode_num() > 1)
        {
            wgui_inputs_options_menu_insert_menu(
		        NULL,
		        STR_GLOBAL_INPUT_METHOD,
		        0,
                EntryInputModeScreen);
        }
    #endif
    
    if (mmi_imm_get_current_allowed_input_mode_num() > 1)
    {
    #if defined(__MMI_IMC_CAPITAL_SWITCH__) 
        wgui_inputs_options_menu_insert_menu(
            NULL,
            STR_ID_PHNSET_PREFERED_WRITING_LANG,
            0,
            EntryInputMethodScreen);
    #else
        wgui_inputs_options_menu_insert_menu(
            NULL,
            STR_GLOBAL_INPUT_METHOD,
            0,
            EntryInputMethodScreen);
    #endif
    }

#elif defined(__MMI_EDITOR_OPTION_MENU_STYLE_2__)

    wgui_inputs_options_menu_insert_menu(
        NULL,
        STR_INPUT_METHOD_MENU_INSERT_SYMBOLS,
        0,
        EntrySymbolPickerScreenFromMenuList);

    #if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
        if (str_set_id > 0 && mmi_imm_is_smart_input_mode_valid())
        {
            wgui_inputs_options_menu_insert_menu(
                NULL,
                str_set_id,
                0,
                mmi_imc_entry_config_smart_input_method_screen);
        }
    #endif
    if (mmi_imm_get_current_allowed_input_mode_num() > 1)
    {
    #if defined(__MMI_IMC_CAPITAL_SWITCH__) 
        wgui_inputs_options_menu_insert_menu(
            NULL,
            STR_ID_PHNSET_PREFERED_WRITING_LANG,
            0,
            EntryInputMethodScreen);
    #else
        wgui_inputs_options_menu_insert_menu(
            NULL,
            STR_GLOBAL_INPUT_METHOD,
            0,
            EntryInputMethodScreen);
    #endif
    }

    #if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_IME_USER_DATABASE__) && defined(__MMI_NORMAL_KEYPAD__)
        if (mmi_imm_is_smart_alphabetic_input_modes_enabled() && mmi_imm_does_current_lang_support_add_new_word())
        {
            if (str_new_word_id > 0)
            {
                wgui_inputs_options_menu_insert_menu(
                    NULL,
                    str_new_word_id,
                    0,
                    mmi_imc_entry_add_new_word_screen);
            }
        }
    #endif
#elif defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__)

wgui_inputs_options_menu_insert_menu(
        NULL,
        STR_INPUT_METHOD_MENU_INSERT_SYMBOLS,
        0,
        EntrySymbolPickerScreenFromMenuList);
#if defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_PREFER_WRITING_LANG__)
wgui_inputs_options_menu_insert_menu(
        NULL,
        STR_GLOBAL_INPUT_METHOD,
        0,
        EntryInputModeScreen);

#elif defined (__MMI_PREFER_INPUT_METHOD__)
wgui_inputs_options_menu_insert_menu(
        NULL,
        STR_GLOBAL_INPUT_METHOD,
        0,
        EntryInputMethodScreen);

#endif         

#if defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__)
g_advanced_settings_menustates_first_enter= MMI_TRUE; /* Done to avoid the popup issues on top of advanced settings */
#endif

#if defined (__MMI_IME_INPUT_ADVANCED_SETTING__)
	g_advanced_settings_changed = MMI_FALSE; /* Done to avoid popup coming when nothing is saved on advanced setting screen */ 
#endif 
wgui_inputs_options_menu_insert_menu(
        NULL,
        STR_INPUT_METHOD_OPTIONS,
        0,
        mmi_ime_commonscreens_entry_imeoptions);

               

#else
    if (mmi_imm_get_current_allowed_input_mode_num() > 1)
    {
    #if defined(__MMI_IMC_CAPITAL_SWITCH__) 
        wgui_inputs_options_menu_insert_menu(
            NULL,
            STR_ID_PHNSET_PREFERED_WRITING_LANG,
            0,
            EntryInputMethodScreen);
    #else
        wgui_inputs_options_menu_insert_menu(
            NULL,
            STR_GLOBAL_INPUT_METHOD,
            0,
            EntryInputMethodScreen);
    #endif
    }
#endif
#if defined(__MMI_CLIPBOARD__)
    /* ADD clipboard menu here */
    mmi_imc_clipboard_show_hide_edit_option_menu(mmi_imc_get_editor_history_data());
    list_num = GetNumOfChild_Ext(MENU_ID_EDITOR_OPT_EDIT_OPTIONS);
    /* Currently we only support Multiline and EMS inputbox copy/cut/paste */
    if ((list_num > 0) &&
        ((mmi_imc_get_editor_history_data()->editor_type == MMI_EDITOR_MULTILINE_INPUT_BOX) || 
         (mmi_imc_get_editor_history_data()->editor_type == MMI_EDITOR_EMS_INPUT_BOX) ||
         ((mmi_imc_get_editor_history_data()->editor_type == MMI_EDITOR_INLINE_INPUT_BOX) &&
          (mmi_imc_get_editor_history_data()->editor_sub_type == MMI_EDITOR_INLINE_MULTILINE_INPUT_BOX))))
    {
        wgui_inputs_options_menu_insert_menu(
            NULL,
            STR_ID_CLIPBOARD_EDIT_OPTION,
            0,
            EntryClipboardOptionScreen);
    }
#endif

    UI_UNUSED_PARAMETER(str_set_id);
    UI_UNUSED_PARAMETER(str_new_word_id);
}

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_options_menu_get_menu_info
 * DESCRIPTION
 *  Get menu item added by editor.
 * PARAMETERS
 *  new_item_num          [OUT]        new added item nubmer (0 for didn't add any item)
 *  start_index           [OUT]        new added item start index (from 0)
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_options_menu_get_menu_info(S32 *new_item_num,  S32 *start_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *new_item_num = g_wgui_inputs_option_menu_ctx.new_menu_item_num;
    *start_index = g_wgui_inputs_option_menu_ctx.input_method_index;
}

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_options_menu_insert_menu
 * DESCRIPTION
 *  Insert menu item in the option menu list.
 * PARAMETERS
 *  icon_id         [IN]      menu icon id
 *  menu_item       [IN]      menu item string
 *  hint            [IN]      menu item description or hint information
 *  f               [IN]      entry function
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_inputs_options_menu_insert_menu(U16 icon_id, U16 menu_item, U16 hint, void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = g_wgui_inputs_option_menu_ctx.new_menu_item_num;
    g_wgui_inputs_option_menu_ctx.menu_info[index].icon_id = icon_id;
    g_wgui_inputs_option_menu_ctx.menu_info[index].string = (UI_string_type)GetString(menu_item);
    g_wgui_inputs_option_menu_ctx.menu_info[index].description = (UI_string_type)GetString(hint);
    g_wgui_inputs_option_menu_ctx.menu_info[index].f_entry = f;
    g_wgui_inputs_option_menu_ctx.new_menu_item_num++;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_menu_index_in_editor_range
 * DESCRIPTION
 *  Check if the highlight menu item index belongs to new added menu item for editor option
 *  When App register key handler(LSK, RSK, left/right arrow key...) after ShowCategoryScreen, 
 *  The function will be called to check if the highlight menu item belongs to App. 
 *  If belongs to App's, App's can register it's key hanlder, otherwise not. ( Because when ShowCategoryScreen
 *  Highlight handler will be called. And in the highlight handler we will register key handler for editor's menu
 *  item. It will override the editor's menu item key handler if not check by this function.)
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE    menu item belongs to new added menu item for editor option
 *  MMI_FALSE   menu item doesn't belong to new added menu item for editor option
 *****************************************************************************/
MMI_BOOL wgui_inputs_menu_index_in_editor_range(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_wgui_inputs_option_menu_ctx.menu_index_in_editor_range;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_options_menu_set_editor_history
 * DESCRIPTION
 *  Set editor history of option menu
 * PARAMETERS
 *  history_buffer      [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_options_menu_set_editor_history(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 s;
    U8 i = 0;
    MMI_ID group_id = GRP_ID_INVALID;
    MMI_ID scrn_id  = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        s = sizeof(list_menu_category_history);
        memcpy((S8 *)mmi_imc_get_editor_history_data(), (S8 *)(((U32)history_buffer + s + 3) & ~3), sizeof(mmi_imc_editor_menu_history_data_struct));

        mmi_imm_create_input_method_list(mmi_imc_get_editor_history_data()->input_type, mmi_imc_get_editor_history_data()->input_mode_list);
        mmi_imm_set_current_input_mode(mmi_imc_get_editor_history_data()->input_mode);
        MMI_current_input_ext_type = mmi_imc_get_editor_history_data()->input_ext_type;
    #if defined(__MMI_IMC_CAPITAL_SWITCH__)
        mmi_imm_set_current_writing_lang(mmi_imc_get_editor_history_data()->writing_lang);
    #endif

        /* 
         * Resume allowed and disabled character list to IME, 
         * otherwise symbol picker screen may show wrong symbols
         */
        mmi_frm_get_active_scrn_id(&group_id, &scrn_id);
        while (i < WGUI_INPUTS_SYMBOL_TABLE_ARRAY_MAX_SIZE)
        {
            if (g_wgui_inputs_symbol_table[i].group_id == group_id &&
                g_wgui_inputs_symbol_table[i].screen_id == scrn_id)
            {
                break;
            }
            i++;
        }

        if (i < WGUI_INPUTS_SYMBOL_TABLE_ARRAY_MAX_SIZE)
        {
            mmi_imm_set_disabled_and_allowed_character_list(&g_wgui_inputs_symbol_table[i].symbol_table);
            g_wgui_inputs_symbol_table[i].group_id = GRP_ID_INVALID;
            g_wgui_inputs_symbol_table[i].screen_id = GRP_ID_INVALID;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_option_menu_register_key_callback
 * DESCRIPTION
 *  register key callback
 * PARAMETERS
 *  f      [IN]        key call back
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_option_menu_register_key_callback(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_inputs_option_menu_key_cb = f;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_option_menu_reset_key_callback
 * DESCRIPTION
 *  Reset key callback
 * PARAMETERS
 *  f      [IN]        key call back
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_option_menu_reset_key_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_inputs_option_menu_key_cb = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_option_menu_register_highlight_callback
 * DESCRIPTION
 *  register key callback
 * PARAMETERS
 *  f      [IN]        highlight call back
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_option_menu_register_highlight_callback(void (*f) (U32))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_inputs_option_menu_highlight_cb = f;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_option_menu_reset_highlight_callback
 * DESCRIPTION
 *  Reset key callback
 * PARAMETERS
 *  f      [IN]        highlight call back
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_option_menu_reset_highlight_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_inputs_option_menu_highlight_cb = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_get_current_imui_height
 * DESCRIPTION
 *  Get the imui height of the specific editor
 * PARAMETERS
 *  input_box_type      [IN]        input box type
 * RETURNS
 *  void
 *****************************************************************************/
S32  wgui_inputs_get_current_imui_height(mmi_editor_inputbox_type_enum input_box_type)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_editor_handler_struct *editor_handler = wgui_inputs_get_editor_handler();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if (!editor_handler)
	{
		return 0;
	}

	if (input_box_type == editor_handler->input_box_type)
	{
		if (editor_handler->input_box_sub_type == MMI_EDITOR_DICT_MULTILINE_INPUT_BOX)
		{
			return 0;
		}
                else if (editor_handler->input_box_sub_type == MMI_EDITOR_DIALER_SEARCH_MULTI_LINE_INPUT_BOX)
                {
                    return 0;
                }
                else
		{
                    return mmi_imc_get_current_imui_height();
		}
	}
	else
	{
		return 0;
	}
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_options_menu_get_category_history
 * DESCRIPTION
 *  Get edit option menu list category history
 * PARAMETERS
 *  history_buffer      [IN]        Is the buffer into which history data is written
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_options_menu_get_category_history(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    MMI_ID group_id = GRP_ID_INVALID;
    MMI_ID scrn_id = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        editor_list_menu_category_history *h = (editor_list_menu_category_history*) history_buffer;

        h->edit_option_index = g_wgui_inputs_option_menu_ctx.edit_options_index;
#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_IME_USER_DATABASE__) && defined(__MMI_NORMAL_KEYPAD__)
        h->input_method_index = g_wgui_inputs_option_menu_ctx.input_method_index;
        h->new_word_on_off = mmi_imm_is_smart_alphabetic_input_modes_enabled();
#endif
        /* Save key info into history */
        memcpy(&h->key_info, &g_wgui_inputs_option_menu_ctx.key_info, sizeof(wgui_inputs_key_info_struct));

        /* Save allowed and disabled character table for IME */
        mmi_frm_get_exit_scrn_id(&group_id, &scrn_id);
        while (i < WGUI_INPUTS_SYMBOL_TABLE_ARRAY_MAX_SIZE)
        {
            if (g_wgui_inputs_symbol_table[i].screen_id == GRP_ID_INVALID)
            {
                break;
            }
            else if (!mmi_frm_scrn_is_present(g_wgui_inputs_symbol_table[i].group_id, g_wgui_inputs_symbol_table[i].screen_id, MMI_FRM_NODE_ALL_FLAG) ||
                     (g_wgui_inputs_symbol_table[i].group_id == group_id && g_wgui_inputs_symbol_table[i].screen_id == scrn_id))
            {
                break;
            }
            i++;
        }

        if (i < WGUI_INPUTS_SYMBOL_TABLE_ARRAY_MAX_SIZE)
        {
            mmi_imm_get_disabled_and_allowed_character_list(&g_wgui_inputs_symbol_table[i].symbol_table);
            g_wgui_inputs_symbol_table[i].group_id = group_id;
            g_wgui_inputs_symbol_table[i].screen_id = scrn_id;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_options_menu_set_category_history_key_info
 * DESCRIPTION
 *  Set edit option menu category history key info
 * PARAMETERS
 *  history_buffer      [IN]        Is the buffer into which history data is written
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_options_menu_set_category_history_key_info(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&g_wgui_inputs_option_menu_ctx.key_info, history_buffer, sizeof(wgui_inputs_key_info_struct));
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_close
 * DESCRIPTION
 *  Common exit handling for editor when exit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Reset singleline leading zero flag (numeric_leading_zero)*/
    set_leading_zero(TRUE);
}

extern mmi_ret mmi_imc_options_menu_handler(mmi_event_struct *evt , mmi_id g_id);
extern void mmi_ime_options_show_hide_ime_option_menus(cui_menu_event_struct *menu_evt);

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_options_menu_handler
 * DESCRIPTION
 *  Editor Options related menu item handle PROC function.
 *  It should be called after App's menu PROC. It will handle editor's menu item
 *  App need to add these edit related menu item in it's menu tree (both resource or runtime create)
 *  App needn't to handle these menu item in it's PROC and only pass the evt to 
 *  wgui_inputs_options_menu_proc to let editor handle it. Editor will return MMI_RET_OK if the menu
 *  is handled.
 * PARAMETERS
 *  evt         [IN]        Event structure
 *  parent_id   [IN]        parent id
 * RETURNS
 *  mmi_ret
 *     MMI_RET_OK:                 message not processed
 *****************************************************************************/
mmi_ret wgui_inputs_options_menu_handler(mmi_event_struct *evt, mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    mmi_ret ret = MMI_RET_OK;
#if defined(__MMI_CLIPBOARD__)
    S32 list_num = 0;
    U16 ItemIDList[10];
#endif
    U16 *menu_list;
    U16 menu_count = 0;
    U8 i = 0;
    BOOL gdi_freeze = gdi_lcd_get_freeze();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Pass to IME options proc function */
    mmi_imc_options_menu_handler(evt, parent_id);

    switch (menu_evt->evt_id)
    {
    case EVT_ID_CUI_MENU_LIST_ENTRY:

        /* insert editor/IME options */
        menu_count = mmi_res_menu_group_get_menuitems(MENU_GROUP_EDITOR, &menu_list);
        
        cui_menu_insert_currlist(menu_evt->sender_id, menu_count, menu_list, MENU_ID_EDIT_OPTS);

        for (i = 0; i < menu_count; i++)
        {
            cui_menu_set_item_string(menu_evt->sender_id,
                menu_list[i], (UI_string_type)GetString(GetStringIdOfItem(menu_list[i])));
        }
     
        cui_menu_delete_currlist_menuid(menu_evt->sender_id, MENU_ID_EDIT_OPTS);

        /* Show/hide menu items*/
           mmi_ime_options_show_hide_ime_option_menus(menu_evt);
#if defined(__MMI_CLIPBOARD__)
        /* ADD clipboard menu here */
        mmi_imc_clipboard_show_hide_edit_option_menu(mmi_imc_get_editor_history_data());
        list_num = GetNumOfChild_Ext(MENU_ID_EDITOR_OPT_EDIT_OPTIONS);
        /* Currently we only support Multiline and EMS inputbox copy/cut/paste */
        if ((list_num > 0) &&
            ((mmi_imc_get_editor_history_data()->editor_type == MMI_EDITOR_MULTILINE_INPUT_BOX) || 
            (mmi_imc_get_editor_history_data()->editor_type == MMI_EDITOR_SINGLE_LINE_INPU_BOX) ||
            (mmi_imc_get_editor_history_data()->editor_type == MMI_EDITOR_EMS_INPUT_BOX) ||
            ((mmi_imc_get_editor_history_data()->editor_type == MMI_EDITOR_INLINE_INPUT_BOX) &&
            (mmi_imc_get_editor_history_data()->editor_sub_type == MMI_EDITOR_INLINE_MULTILINE_INPUT_BOX))))
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_EDITOR_OPT_EDIT_OPTIONS, MMI_FALSE);
            cui_menu_set_non_leaf_item(menu_evt->sender_id, MENU_ID_EDITOR_OPT_EDIT_OPTIONS, MMI_TRUE);

            if (menu_evt->parent_menu_id == MENU_ID_EDITOR_OPT_EDIT_OPTIONS)
            {
                GetSequenceItemIds_Ext(MENU_ID_EDITOR_OPT_EDIT_OPTIONS, ItemIDList);
                cui_menu_set_currlist(menu_evt->sender_id, list_num, ItemIDList);
                cui_menu_set_currlist_title(menu_evt->sender_id, (WCHAR*)GetString(STR_ID_CLIPBOARD_EDIT_OPTION), NULL);
                for (i = 0; i < list_num; i++)
                {
                    cui_menu_set_item_string(menu_evt->sender_id,
                        ItemIDList[i], (UI_string_type)GetString(GetStringIdOfItem(ItemIDList[i])));
                }
            }
        }
        else
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_EDITOR_OPT_EDIT_OPTIONS, MMI_TRUE);
        }
#endif
        break;
    case EVT_ID_CUI_MENU_ITEM_TAP:
    case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
    case EVT_ID_CUI_MENU_ITEM_SELECT:

    #ifdef __MMI_CLIPBOARD__
        if (menu_evt->highlighted_menu_id == MENU_ID_CLIPBOARD_EDIT_OPTION_MARK)
        {
            RegisterInputMethodScreenCloseFunction(UI_dummy_function);
            gdi_lcd_freeze(TRUE);
            cui_menu_close(menu_evt->sender_id);
            EntryClipboardLocateCursorScreen();
            gdi_lcd_freeze(gdi_freeze);
            gdi_layer_blt_previous(0,0,UI_device_width-1, UI_device_height-1);
        }
        else if (menu_evt->highlighted_menu_id == MENU_ID_CLIPBOARD_EDIT_OPTION_COPY_ALL)
        {
            RegisterInputMethodScreenCloseFunction(UI_dummy_function);
            gdi_lcd_freeze(TRUE);
            cui_menu_close(menu_evt->sender_id);
            EntryClipboardCopyAll();
            gdi_lcd_freeze(gdi_freeze);
            gdi_layer_blt_previous(0,0,UI_device_width-1, UI_device_height-1);
        }
        else if (menu_evt->highlighted_menu_id == MENU_ID_CLIPBOARD_EDIT_OPTION_CUT_ALL)
        {
            RegisterInputMethodScreenCloseFunction(UI_dummy_function);
            gdi_lcd_freeze(TRUE);
            cui_menu_close(menu_evt->sender_id);
            EntryClipboardCutAll();
            gdi_lcd_freeze(gdi_freeze);
            gdi_layer_blt_previous(0,0,UI_device_width-1, UI_device_height-1);
        }
        else if (menu_evt->highlighted_menu_id == MENU_ID_CLIPBOARD_EDIT_OPTION_PASTE)
        {
            RegisterInputMethodScreenCloseFunction(UI_dummy_function);
            gdi_lcd_freeze(TRUE);
            cui_menu_close(menu_evt->sender_id);
            EntryClipboardPaste();
            gdi_lcd_freeze(gdi_freeze);
            gdi_layer_blt_previous(0,0,UI_device_width-1, UI_device_height-1);
        }
    #endif
        break;
    default:
        break;
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_connect
 * DESCRIPTION
 *  Connect editor
 * PARAMETERS
 *  input_type              [IN]            input type
 *  input_mode_array        [IN]            input mode array
 *  default_input_mode      [IN]            default input mode
 *  input_box_type          [IN]            inputbox type
 *  input_box_sub_type      [IN]            inputbox sub type
 *  input_box_handler       [IN]            editor pointer
 *  msg_callback            [IN]            message callback
 * RETURNS
 *  Connect IME successfully or not
 *****************************************************************************/
MMI_BOOL wgui_inputs_connect(
              U32 input_type,
              mmi_imm_input_mode_enum *input_mode_array,
              mmi_imm_input_mode_enum default_input_mode,
              mmi_editor_inputbox_type_enum input_box_type,
              mmi_editor_inputbox_sub_type_enum input_box_sub_type,
              void * input_box_handler,
              mmi_imc_message_funcptr msg_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imm_set_required_mode_list(input_type, input_mode_array, default_input_mode);
    g_mmi_editor_hanler.input_box_type = input_box_type;
    g_mmi_editor_hanler.input_box_sub_type = input_box_sub_type;
    g_mmi_editor_hanler.input_box_handler = input_box_handler;

    if (input_box_type == MMI_EDITOR_MULTILINE_INPUT_BOX)
    {
        wgui_inputs_ml_set_RSK();
        wgui_inputs_ml_register_keys();
    }
    else if (input_box_type == MMI_EDITOR_SINGLE_LINE_INPU_BOX)
    {
        wgui_inputs_sl_set_RSK();
        wgui_inputs_sl_register_keys();
    }
    return mmi_imc_connect((void *)&g_mmi_editor_hanler, msg_callback);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_disconnect
 * DESCRIPTION
 *  Disconnect editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_disconnect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_disconnect();
}


#ifdef __OP01_FWPBW__

UI_character_type g_wgui_inputs_remaining_characters_str[10];
UI_character_type g_wgui_inputs_input_mode_str[10];

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_show_current_input_method
 * DESCRIPTION
 *  wgui_inputs_ml_show_current_input_method
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_show_current_input_method_timer_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL isSmart = MMI_TRUE;
    UI_string_type inputModeStr = mmi_imui_get_inputmode_string(&isSmart);
    S32 csk_x, csk_y, csk_width, csk_height;
    S32 text_x, text_y;
    S32 str_width, str_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_inputs_input_mode_str[0] = 0;
    if (isSmart)
    {
        mmi_ucs2cpy((S8*)g_wgui_inputs_input_mode_str, (S8*)L"s");
    }
    mmi_ucs2cat((S8*)g_wgui_inputs_input_mode_str, (S8*)inputModeStr);

	// show remaining counter on csk
    wgui_softkey_get_position(MMI_CENTER_SOFTKEY, &csk_x, &csk_y);
    wgui_softkey_get_dimension(MMI_CENTER_SOFTKEY, &csk_width, &csk_height);
    gui_push_clip();
    gui_set_clip(csk_x, csk_y, csk_x + csk_width - 1, csk_y + csk_height - 1);
    // clear background
    gui_fill_rectangle(csk_x, csk_y, csk_x + csk_width - 1, csk_y + csk_height - 1, gui_color(255, 255, 255));

    // show text
    gui_set_font(&MMI_small_font);
    gui_measure_string(g_wgui_inputs_input_mode_str, &str_width, &str_height);
    str_width = str_width + 2; /* 2 is border width */
    text_x = csk_x + ((csk_width - str_width)>>1);
    text_y = csk_y + ((csk_height - str_height)>>1);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_move_text_cursor(text_x, text_y);
    gui_print_text(g_wgui_inputs_input_mode_str);
    gui_pop_clip();

    gui_BLT_double_buffer(csk_x, csk_y, csk_x + csk_width - 1, csk_y + csk_height - 1);
}

#endif


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_reset_repeat_count
 * DESCRIPTION
 *  reset repeat count for fast del/navigate
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_fast_del_nav_reset_repeat_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_inputs_repeat_count = 0;
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_fast_del_pen_handler
 * DESCRIPTION
 *  handle fast delete and navigation pen event
 * PARAMETERS
 *  type             [IN]     operation type
 *  editor           [IN]     editor type
 *  pen_event        [IN]     pen event
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_fast_del_pen_handler(wgui_inputs_fast_del_nav_oper_enum type, wgui_inputs_fast_del_nav_editor_enum editor, mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr operatorFuncPtr = wgui_inputs_fast_del_nav_get_op_handler(type, editor);
    U32 begin_tick = 0;
    U32 end_tick = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (operatorFuncPtr == NULL)
        return;

    if (pen_event == MMI_PEN_EVENT_LONG_TAP)
    {
        wgui_inputs_fast_del_nav_reset_repeat_count();
    }
    if (pen_event == MMI_PEN_EVENT_UP || pen_event == MMI_PEN_EVENT_ABORT)
    {
        mmi_pen_config_timeout_period(MMI_PEN_LONGTAP_TIME, MMI_PEN_REPEAT_TIME, MMI_PEN_STROKE_LONGTAP_TIME);
        wgui_inputs_fast_del_nav_reset_repeat_count();
    }
    else if (pen_event == MMI_PEN_EVENT_REPEAT)
    {
        U32 repeat_period = 0;
        kal_get_time(&begin_tick);
        operatorFuncPtr();
        kal_get_time(&end_tick);
        end_tick -= begin_tick;
        end_tick = kal_ticks_to_milli_secs(end_tick);
        if ((end_tick < WGUI_INPUTS_QUICK_DEL_NAV_PER_CHAR_TIME) &&
            (g_wgui_inputs_repeat_count < (WGUI_INPUTS_MAX_REPEAT_COUNT * 3)))
        {
            /* Normal speed (100ms per char) */
            repeat_period = 10;
        }
        else if (end_tick < WGUI_INPUTS_QUICK_DEL_NAV_MIN_CHAR_TIME)
        {
            /* Fastest speed (50ms per char) */
            repeat_period = 5;
        }
        else
        {
            // use current delete time as repeat period to avoid the key event accumulate
            repeat_period = (end_tick / 10) + 1;
            if (repeat_period < 5)
                repeat_period = 5;
        }
        mmi_pen_config_timeout_period(MMI_PEN_LONGTAP_TIME, repeat_period, MMI_PEN_STROKE_LONGTAP_TIME);
        //kal_prompt_trace(MOD_MMI, "[Editor fast delete] repeat period = %d, time = %d, repeat count = %d", repeat_period, end_tick, g_wgui_inputs_repeat_count);
        g_wgui_inputs_repeat_count++;
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_fast_del_nav_handler
 * DESCRIPTION
 *  handle fast delete and navigation within specific time period
 * PARAMETERS
 *  type             [IN]     operation type
 *  time_period      [IN]     time period of operation
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_fast_del_nav_handler(wgui_inputs_fast_del_nav_oper_enum type, wgui_inputs_fast_del_nav_editor_enum editor, U32 time_period)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    S32 char_num = 0;
    U32 delay = 0;
    U32 begin_tick = 0;
    U32 end_tick = 0;
    FuncPtr operatorFuncPtr = wgui_inputs_fast_del_nav_get_op_handler(type, editor);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (operatorFuncPtr == NULL)
    {
        return;
    }

    kal_get_time(&begin_tick);
    operatorFuncPtr();
    kal_get_time(&end_tick);
    end_tick -= begin_tick;
    end_tick = kal_ticks_to_milli_secs(end_tick);

    if ((end_tick < WGUI_INPUTS_QUICK_DEL_NAV_PER_CHAR_TIME) &&
        (g_wgui_inputs_repeat_count < WGUI_INPUTS_MAX_REPEAT_COUNT))
    {
        /* Normal speed (100ms per char) */
        delay = WGUI_INPUTS_QUICK_DEL_NAV_PER_CHAR_TIME - end_tick;
        end_tick = WGUI_INPUTS_QUICK_DEL_NAV_PER_CHAR_TIME;
    }
    else if (end_tick < WGUI_INPUTS_QUICK_DEL_NAV_MIN_CHAR_TIME)
    {
        /* Fastest speed (50ms per char) */
        delay = WGUI_INPUTS_QUICK_DEL_NAV_MIN_CHAR_TIME - end_tick;
        end_tick = WGUI_INPUTS_QUICK_DEL_NAV_MIN_CHAR_TIME;
    }

    char_num = time_period / end_tick;

    for (i = 0; i < char_num - 1; i++)
    {
        if (wgui_inputs_fast_del_nav_check_callback(type, editor))
        {
            return;
        }
        if (delay > 0)
        {
            kal_sleep_task(kal_milli_secs_to_ticks(delay));
        }
        operatorFuncPtr();

        if (editor == WGUI_INPUTS_EDITOR_DIALER)
        {
#ifdef __MMI_EDITOR_DIALER_SUPPORT__            
            /* Because dialer cursor will be draw after certain timer, so we draw it manually to avild cursor jump */
            UI_inputbox_pre2_show_cursor();
#endif /* __MMI_EDITOR_DIALER_SUPPORT__*/
        }
    }
    g_wgui_inputs_repeat_count++;
}

#ifndef __MMI_INLINE_SLIM__

extern void inline_edit_singleline_inputbox_delete_character(void);
extern void inline_edit_singleline_inputbox_previous_character(void);
extern void inline_edit_singleline_inputbox_next_character(void);
#endif

#ifdef UI_EMS_SUPPORT
extern void EMS_inputbox_backspace(void);
extern void EMS_inputbox_previous(void);
extern void EMS_inputbox_next(void);
extern void EMS_inputbox_next_line(void);
extern void EMS_inputbox_previous_line(void);
#endif

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_fast_del_nav_check_callback
 * DESCRIPTION
 *  check callback of fast delete and navigation
 * PARAMETERS
 *  type           [IN]     operation type
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL wgui_inputs_fast_del_nav_check_callback(wgui_inputs_fast_del_nav_oper_enum op_type, wgui_inputs_fast_del_nav_editor_enum editor)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (op_type == WGUI_INPUTS_OPER_FAST_DEL || op_type == WGUI_INPUTS_OPER_FAST_NAV_LEFT)
    {
        switch (editor)
        {
        case WGUI_INPUTS_EDITOR_DIALER:
            {
#ifdef __MMI_EDITOR_DIALER_SUPPORT__                
                ret = gui_dialer_input_box_test_first_position(&MMI_dialer_inputbox);
#endif /* __MMI_EDITOR_DIALER_SUPPORT__*/
            }
            break;
        case WGUI_INPUTS_EDITOR_SL:
            {
                ret = gui_single_line_input_box_test_first_position(&MMI_singleline_inputbox);
            }
            break;
    #ifndef __MMI_INLINE_SLIM__
        case WGUI_INPUTS_EDITOR_INLINE_SL:
            {
                ret = gui_single_line_input_box_test_first_position(&MMI_inline_singleline_inputbox);
            }
            break;
    #endif
        case WGUI_INPUTS_EDITOR_ML:
            {
                ret = gui_multi_line_input_box_test_first_position(&MMI_multiline_inputbox);
            }
            break;
    #ifdef UI_EMS_SUPPORT
        case WGUI_INPUTS_EDITOR_EMS:
            {
                ret = TestFirstPosition(MMI_EMS_inputbox.data, &((MMI_EMS_inputbox.data)->CurrentPosition));
            }
            break;
    #endif
        default:
            break;
        }
    }
    else if (op_type == WGUI_INPUTS_OPER_FAST_NAV_RIGHT)
    {
        switch (editor)
        {
        case WGUI_INPUTS_EDITOR_DIALER:
            {
#ifdef __MMI_EDITOR_DIALER_SUPPORT__                
                ret = gui_dialer_input_box_test_last_position(&MMI_dialer_inputbox);
#endif /* __MMI_EDITOR_DIALER_SUPPORT__*/
            }
            break;
        case WGUI_INPUTS_EDITOR_SL:
            {
                ret = gui_single_line_input_box_test_last_position(&MMI_singleline_inputbox);
            }
            break;
    #ifndef __MMI_INLINE_SLIM__
        case WGUI_INPUTS_EDITOR_INLINE_SL:
            {
                ret = gui_single_line_input_box_test_last_position(&MMI_inline_singleline_inputbox);
            }
            break;
    #endif
        case WGUI_INPUTS_EDITOR_ML:
            {
                ret = gui_multi_line_input_box_test_last_position(&MMI_multiline_inputbox);
            }
            break;
    #ifdef UI_EMS_SUPPORT
        case WGUI_INPUTS_EDITOR_EMS:
            {
                ret = TestLastPosition(MMI_EMS_inputbox.data, &((MMI_EMS_inputbox.data)->CurrentPosition));
            }
            break;
    #endif
        default:
            break;
        }
    }
    else if (op_type == WGUI_INPUTS_OPER_FAST_NAV_UP)
    {
        switch (editor)
        {
        case WGUI_INPUTS_EDITOR_DIALER:
            {
#ifdef __MMI_EDITOR_DIALER_SUPPORT__                
                ret = gui_dialer_input_box_test_first_line(&MMI_dialer_inputbox);
#endif
            }
            break;        
        case WGUI_INPUTS_EDITOR_ML:
            {
                ret = gui_multi_line_input_box_test_first_line(&MMI_multiline_inputbox);
            }
            break;
    #ifdef __MMI_INSCREEN_MULTILINE_TEXTBOX__
        case WGUI_INPUTS_EDITOR_INLINE_ML:
            {
                ret = gui_multi_line_input_box_test_first_line(&MMI_multiline_inputbox);
            }
            break;
    #endif
    #ifdef UI_EMS_SUPPORT
        case WGUI_INPUTS_EDITOR_EMS:
            {
                ret = gui_ems_test_first_line(&MMI_EMS_inputbox);
            }
            break;
    #endif
        default:
            break;
        }
    }
    else if (op_type == WGUI_INPUTS_OPER_FAST_NAV_DOWN)
    {
        switch (editor)
        {
        case WGUI_INPUTS_EDITOR_DIALER:
            {
#ifdef __MMI_EDITOR_DIALER_SUPPORT__                
                ret = gui_dialer_input_box_test_last_line(&MMI_dialer_inputbox);
#endif /* __MMI_EDITOR_DIALER_SUPPORT__*/
            }
            break;        
        case WGUI_INPUTS_EDITOR_ML:
            {
                ret = gui_multi_line_input_box_test_last_line(&MMI_multiline_inputbox);
            }
            break;
    #ifdef __MMI_INSCREEN_MULTILINE_TEXTBOX__
        case WGUI_INPUTS_EDITOR_INLINE_ML:
            {
                ret = gui_multi_line_input_box_test_last_line(&MMI_multiline_inputbox);
            }
            break;
    #endif
    #ifdef UI_EMS_SUPPORT
        case WGUI_INPUTS_EDITOR_EMS:
            {
                ret = gui_ems_test_last_line(&MMI_EMS_inputbox);
            }
            break;
    #endif
        default:
            break;
        }
    }

    return ((ret > 0) ? MMI_TRUE : MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_fast_del_nav_get_op_handler
 * DESCRIPTION
 *  get operation handler of fast delete and navigation
 * PARAMETERS
 *  op_type           [IN]     operation type
 *  editor            [IN]     editor type
 * RETURNS
 *  FuncPtr
 *****************************************************************************/
static FuncPtr wgui_inputs_fast_del_nav_get_op_handler(wgui_inputs_fast_del_nav_oper_enum op_type, wgui_inputs_fast_del_nav_editor_enum editor)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr retPtr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (op_type == WGUI_INPUTS_OPER_FAST_DEL)
    {
        switch (editor)
        {
        case WGUI_INPUTS_EDITOR_DIALER:
            {
#ifdef __MMI_EDITOR_DIALER_SUPPORT__                
                retPtr = wgui_inputs_dialer_delete_character;
#endif /* __MMI_EDITOR_DIALER_SUPPORT__*/
            }
            break;
        case WGUI_INPUTS_EDITOR_SL:
            {
                retPtr = wgui_inputs_sl_delete_character;
            }
            break;
    #ifndef __MMI_INLINE_SLIM__
        case WGUI_INPUTS_EDITOR_INLINE_SL:
            {
                retPtr = inline_edit_singleline_inputbox_delete_character;
            }
            break;
    #endif
        case WGUI_INPUTS_EDITOR_ML:
            {
                retPtr = wgui_inputs_ml_delete_character;
            }
            break;
    #ifdef UI_EMS_SUPPORT
        case WGUI_INPUTS_EDITOR_EMS:
            {
                retPtr = EMS_inputbox_backspace;
            }
            break;
    #endif
        default:
            break;
        }
    }
    else if (op_type == WGUI_INPUTS_OPER_FAST_NAV_LEFT)
    {
        switch (editor)
        {
        case WGUI_INPUTS_EDITOR_DIALER:
            {
#ifdef __MMI_EDITOR_DIALER_SUPPORT__                
                retPtr = wgui_inputs_dialer_previous_character;
#endif /* __MMI_EDITOR_DIALER_SUPPORT__*/
            }
            break;
        case WGUI_INPUTS_EDITOR_SL:
            {
                retPtr = wgui_inputs_sl_previous_character;
            }
            break;
    #ifndef __MMI_INLINE_SLIM__
        case WGUI_INPUTS_EDITOR_INLINE_SL:
            {
                retPtr = inline_edit_singleline_inputbox_previous_character;
            }
            break;
    #endif
        case WGUI_INPUTS_EDITOR_ML:
            {
                retPtr = wgui_inputs_ml_previous_character;
            }
            break;
    #ifdef UI_EMS_SUPPORT
        case WGUI_INPUTS_EDITOR_EMS:
            {
                retPtr = EMS_inputbox_previous;
            }
            break;
    #endif
        default:
            break;
        }
    }
    else if (op_type == WGUI_INPUTS_OPER_FAST_NAV_RIGHT)
    {
        switch (editor)
        {
        case WGUI_INPUTS_EDITOR_DIALER:
            {
#ifdef __MMI_EDITOR_DIALER_SUPPORT__                
                retPtr = wgui_inputs_dialer_next_character;
#endif /* __MMI_EDITOR_DIALER_SUPPORT__*/
            }
            break;
        case WGUI_INPUTS_EDITOR_SL:
            {
                retPtr = wgui_inputs_sl_next_character;
            }
            break;
    #ifndef __MMI_INLINE_SLIM__
        case WGUI_INPUTS_EDITOR_INLINE_SL:
            {
                retPtr = inline_edit_singleline_inputbox_next_character;
            }
            break;
    #endif
        case WGUI_INPUTS_EDITOR_ML:
            {
                retPtr = wgui_inputs_ml_next_character;
            }
            break;
    #ifdef UI_EMS_SUPPORT 
        case WGUI_INPUTS_EDITOR_EMS:
            {
                retPtr = EMS_inputbox_next;
            }
            break;
    #endif
        default:
            break;
        }
    }
    else if (op_type == WGUI_INPUTS_OPER_FAST_NAV_UP)
    {
        switch (editor)
        {
        case WGUI_INPUTS_EDITOR_DIALER:
            {
#ifdef __MMI_EDITOR_DIALER_SUPPORT__                
                retPtr = wgui_inputs_dialer_next_line;
#endif /* __MMI_EDITOR_DIALER_SUPPORT__*/
            }
            break;
        case WGUI_INPUTS_EDITOR_ML:
            {
                retPtr = wgui_inputs_ml_previous_line;
            }
            break;
    #ifdef __MMI_INSCREEN_MULTILINE_TEXTBOX__
        case WGUI_INPUTS_EDITOR_INLINE_ML:
            {
                retPtr = wgui_inputs_ml_inline_previous_line;
            }
            break;
    #endif
    #ifdef UI_EMS_SUPPORT
        case WGUI_INPUTS_EDITOR_EMS:
            {
                retPtr = EMS_inputbox_previous_line;
            }
            break;
    #endif
        default:
            break;
        }
    }
    else if (op_type == WGUI_INPUTS_OPER_FAST_NAV_DOWN)
    {
        switch (editor)
        {
        case WGUI_INPUTS_EDITOR_DIALER:
            {
#ifdef __MMI_EDITOR_DIALER_SUPPORT__                
                retPtr = wgui_inputs_dialer_previous_line;
#endif /* __MMI_EDITOR_DIALER_SUPPORT__*/
            }
            break;        
        case WGUI_INPUTS_EDITOR_ML:
            {
                retPtr = wgui_inputs_ml_next_line;
            }
            break;
    #ifdef __MMI_INSCREEN_MULTILINE_TEXTBOX__
        case WGUI_INPUTS_EDITOR_INLINE_ML:
            {
                retPtr = wgui_inputs_ml_inline_next_line;
            }
            break;
    #endif
    #ifdef UI_EMS_SUPPORT 
        case WGUI_INPUTS_EDITOR_EMS:
            {
                retPtr = EMS_inputbox_next_line;
            }
            break;
    #endif
        default:
            break;
        }
    }

    return retPtr;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_options_menu_hide_items
 * DESCRIPTION
 *  Hide editor option menu items
 * PARAMETERS
 *  parent_id   [IN]        parent id
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inputs_options_menu_hide_items(mmi_id parent_id, MMI_BOOL isHide)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *menu_list;
    U16 menu_count = 0;
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_count = mmi_res_menu_group_get_menuitems(MENU_GROUP_EDITOR, &menu_list);

    for (i = 0; i < menu_count; i++)
    {
        cui_menu_set_item_hidden(parent_id, menu_list[i], isHide);
    }
}
