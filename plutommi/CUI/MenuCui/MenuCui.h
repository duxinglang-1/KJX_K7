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
 *   MenuCui.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Menu Common UI internal header file.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef CUI_MENUCUI_H
#define CUI_MENUCUI_H

/*******************************************************************************
* Include Header File
*******************************************************************************/
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gui_data_types.h"
#include "MMI_features.h"
#include "ScreenRotationGprot.h"
#include "GlobalConstants.h"
#include "gui_effect_oem.h"
//#include "lcd_sw_inc.h"
#include "gdi_lcd_config.h"
#include "mmi_frm_scenario_gprot.h"
#include "menucuigprot.h"

/*******************************************************************************
* Macro Define
*******************************************************************************/
#define CUI_MENU_MAX_INSTANCE     7
#define CUI_MENU_MAX_EDIT_RES     50 
#define CUI_MENU_MAX_SEPARATORS   4

#define CUI_MENU_MAX_SCREEN_COUNT_APP_MENU      10
#define CUI_MENU_MAX_SCREEN_COUNT_OPTION_MENU   2
#define CUI_MENU_MAX_TREE_DEPTH                 10

/* Menu CUI flag to hide a menu id */
#define CUI_MENU_ITEM_HIDDEN        0x01
/* Menu CUI flag to disable a menu id */
#define CUI_MENU_ITEM_DISABLED      0x02

#define CUI_MENU_ITEM_WITH_SUB_MENU    0x01


/*******************************************************************************
* Enum Define
*******************************************************************************/


/* Shortcut Access */
typedef enum
{  
    CUI_MENU_ACCESS_BY_SHORTCUT_DEFAULT,
    CUI_MENU_ACCESS_BY_SHORTCUT_DISABLE,
    CUI_MENU_ACCESS_BY_SHORTCUT_ENABLE,
} cui_menu_access_by_shortcut_enum;

/* FW or BK Scenario */
typedef enum
{
    CUI_MENU_NO_SCENARIO,
    CUI_MENU_FW_SCENARIO,
    CUI_MENU_BK_SCENARIO,
} cui_menu_scenario;

/*******************************************************************************
* Structure Define
*******************************************************************************/
/* common UI menu object struct*/
typedef struct
{
    mmi_menu_id	menu_id;	       /* Menu resource ID */
    U8 flags;	                   /* Flags for each menu-item, like hide/grey */
}cui_menu_item_flag_tbl_struct;


typedef struct  
{
    MMI_BOOL app_csk;
    MMI_BOOL is_inuse;
    cui_menu_src_type_enum mode;
    cui_menu_type_enum menu_type;
    S8 current_level_index;
    MMI_BOOL closure_started_flag;
    MMI_BOOL enable_cascading_option_menu;  
    MMI_BOOL is_item_flags_from_res;
    MMI_BOOL override_non_leaf_by_app;
    MMI_BOOL is_title_from_res;
    MMI_BOOL enable_refresh_screen;
    MMI_BOOL highlight_evt_handler;
    MMI_BOOL is_pause;  
#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))
    MMI_BOOL enable_tap_highlight;  
    MMI_BOOL enable_fte_sublevel_option_menu;
#endif
    cui_menu_access_by_shortcut_enum  access_by_shortcut;
    MMI_BOOL is_in_show_func;
    cui_menu_scenario scenario;
#ifdef __MMI_SCREEN_ROTATE__	
    mmi_frm_screen_rotate_enum rotate_type;
#endif
    MMI_BOOL next_level_fw_scenario;
    mmi_menu_id	root_id;
    mmi_menu_id	currlist_parent_id;
    mmi_menu_id prevlist_parent_id;
    mmi_menu_id currlist_highlighted_id;
    mmi_id new_scrn_id;
    WCHAR* default_title_string;
    UI_image_type default_title_image;
    WCHAR* default_lsk_string;
    WCHAR* default_rsk_string;
    WCHAR* currlist_title_string;
    UI_image_type currlist_title_image;
    WCHAR* currlist_lsk_string;
    WCHAR* currlist_rsk_string;
    WCHAR* currlist_csk_string;
    UI_image_type currlist_csk_image;
    void* app_data;
    mmi_menu_id* currlist_menu_ids;
    U32	currlist_flags;
    S32 currlist_no_of_items;
    mmi_menu_id tree_path[CUI_MENU_MAX_TREE_DEPTH];	
    cui_menu_item_flag_tbl_struct cui_menu_item_flags[CUI_MENU_MAX_EDIT_RES];
} cui_menu_obj_struct;


typedef struct
{
    U16 list_menu_icons[MAX_SUB_MENUS];
    U16 list_menu_icons2[MAX_SUB_MENUS];	
    mmi_menu_id list_menu_ids[MAX_SUB_MENUS];
    U8 list_menu_check_states[MAX_SUB_MENUS]; 
    U8 list_separator_index[CUI_MENU_MAX_SEPARATORS];	
}cui_menu_current_screen_info_struct;

#define CUI_MENU_SCREEN_INFO_SIZE (sizeof(cui_menu_current_screen_info_struct))

#define CUI_MENU_CASCADING_ASM_BUFFER_SIZE           GDI_LCD_WIDTH * GDI_LCD_HEIGHT * GUI_EFFECT_LAYER_BYTE_PER_PIXEL


/*******************************************************************************
* Intenal API 
*******************************************************************************/

/*****************************************************************************              
 * FUNCTION
 *  cui_menu_reset
 * DESCRIPTION
 *   cui menu reset
 * PARAMETERS
 *  obj       : [IN] pointer to the cui menu object
 * RETURNS
 *  void
 * RETURN VALUES
 *  none 
*****************************************************************************/
static void cui_menu_reset(cui_menu_obj_struct* obj);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_screen_entry
 * DESCRIPTION
 *   Entry Screen for menu cui
 * PARAMETERS
 *  void
 * RETURNS
 *  None
 * RETURN VALUES
 *  None
*****************************************************************************/
static void cui_menu_screen_first_entry(mmi_scrn_essential_struct *screen_data);


static void cui_menu_screen_entry(void);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_screen_exit
 * DESCRIPTION
 *  exit screen for menu cui
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
static void cui_menu_screen_exit(void);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_load_res
 * DESCRIPTION
 *   set root id of menu cui
 * PARAMETERS
 *  menu_id      : [IN] menu id for which resource needs to be loaded
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
static void cui_menu_load_res(mmi_menu_id menu_id);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_lsk_handler
 * DESCRIPTION
 *   lsk hanlder for cui menu screen
 * PARAMETERS
 *  void     
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
static void cui_menu_lsk_handler(void);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_rsk_handler
 * DESCRIPTION
 *   rsk hanlder for cui menu screen
 * PARAMETERS
 *  void     
 *RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
static void cui_menu_rsk_handler(void);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_hilite_handler
 * DESCRIPTION
 *   hilite handler for the list menu of cui menu
 * PARAMETERS
 *  index     : [IN] index in list
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
static void cui_menu_hilite_handler(S32 index);



#endif /* CUI_MENUCUI_H */ 
