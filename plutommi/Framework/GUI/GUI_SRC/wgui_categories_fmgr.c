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
 *  wgui_categories_fmgr.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  File Manager related categories.
 *
 *  [Category212]       Info Style Dynamic List Menu 
 *  [Category213]       Thick Style Dynamic List Menu 
 *  [Category214]       Matrix Style Dynamic Image Menu 
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/* framework related include */
#include "MMI_features.h"
#include "lcd_sw_rnd.h"
#ifdef __MMI_TOUCH_SCREEN__
#endif 
#include "ScreenRotationGprot.h"
#include "wgui_fixed_menuitems.h"
#include "gui_dynamic_menus.h"
#include "wgui_dynamic_menus.h"
#include "wgui_asyncdynamic_menus.h"

#include "Med_api.h"

#include "gui_switch.h"
#include "wgui.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gui_effect_oem.h"
#include "gui_data_types.h"
#include "wgui_categories_fmgr.h"
#include "gui_windows.h"
#include "gui_typedef.h"
#include "wgui_draw_manager.h"
#include "gdi_datatype.h"
#include "gdi_const.h"
#include "kal_public_api.h"
#include "wgui_include.h"
#include "gui_fixed_menuitems.h"
#include "wgui_categories_util.h"
#include "wgui_fixed_menus.h"
#include "gui.h"
#include "wgui_categories_CM.h"
#include "wgui_categories_enum.h"
#include "gui_fixed_menus.h"
#include "CustDataRes.h"
#include "gdi_include.h"
#include "gui_config.h"
#include "gui_scrollbars.h"
#include "lcd_sw_inc.h"
#include "Gui_Setting.h"
#include "mmi_frm_events_gprot.h"
#include "gui_themes.h"
#include "CustThemesRes.h"
#include "FileMgrResDef.h"
#include "wgui_inputs.h"
#include "wgui_dynamic_menuitems.h"
#include "string.h"
#include "mmi_rp_app_uiframework_def.h"
#include "Unicodexdcl.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "gd_include.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_active_module.h"
#include "FileMgrSrvGProt.h"
#include "DebugInitDef_Int.h"
#include "gui_inputs.h"
#include "gui_theme_struct.h"
#include "GlobalResDef.h"
#include "PixcomFontEngine.h"
#include "wgui_asyncdynamic_menuitems.h"
#include "wgui_categories_popup.h"
#include "wgui_title.h"
#include "FileMgrGProt.h"
#include "FileMgrType.h"

/***************************************************************************** 
* Define
*****************************************************************************/

#if defined(__SOCIAL_NETWORK_SUPPORT__) && !defined (__MMI_FMGR_SUPPORT_THUMB_DECODE__)
    #define FMGR_USING_CACHE
#endif
/***************************************************************************** 
* Golbal Variable
*****************************************************************************/
/* x1 and y1 of the highlight menuitem */
extern S32 GUI_current_fixed_icontext_menuitem_x, GUI_current_fixed_icontext_menuitem_y;
extern S32 GUI_current_fixed_icontext_list_menuitem_x, GUI_current_fixed_icontext_list_menuitem_y;

#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_KEY)
extern MMI_BOOL gui_in_ssk;
#endif

#if defined(__MMI_UI_LIST_SLIDE_EFFECT__)
extern gui_effect_struct *g_slide_effect;
#endif

extern S32 g_cat_tab_num;

/***************************************************************************** 
* Golbal Function
*****************************************************************************/
extern void reset_pop_up_descriptions(void);
extern void set_dynamic_pop_up_descriptions(S32 highlighted_item);

/***************************************************************************** 
* Local Variable
*****************************************************************************/
#ifdef __MMI_CAT216_CAT212_SUPPORT_FMGR__
/* [Category212] */
static Cat212DrawInfoFuncPtr cat212_draw_info_callback = NULL;
static Cat212HideInfoFuncPtr cat212_hide_info_callback = NULL;
static U16 cat212_info_box_height = 0;
#endif
/* [Category213] */
#ifdef __MMI_CAT217_CAT213_SUPPORT_FMGR__
static Cat213DrawMenuItemFuncPtr cat213_draw_menuitem_callback = NULL;
static Cat213HideMenuItemFuncPtr cat213_hide_menuitem_callback = NULL;
#endif
/* [Category214] */
static Cat214DrawImageFuncPtr cat214_draw_image_callback = NULL;
static Cat214HideImageFuncPtr cat214_hide_image_callback = NULL;

/* [Category217], [Category219] */
static GetAsyncItemFuncPtr g_cat_fmgr_get_async_item_func = NULL;
static GetAsyncHintFuncPtr g_cat_fmgr_get_async_hint_func = NULL;

/***************************************************************************** 
* Local Function
*****************************************************************************/
/* [Category212], [Category216]*/
#ifdef __MMI_CAT216_CAT212_SUPPORT_FMGR__
static void ExitCategory212Screen(void);
static void wgui_cat212_draw_info(S32 item_idx, S32 x1, S32 y1, S32 x2, S32 y2);
static void DrawCate212CategoryControlArea(dm_coordinates *coordinate);
static void wgui_cat218_draw_two_line_item(void *item, S32 x1, S32 y1, S32 x2, S32 y2);


static void ShowCategory212InfoArea(S32 item_idx);
static void wgui_cat212_scrolling_text_draw_background(S32 x1, S32 y1, S32 x2, S32 y2);
#endif
/* [Category213], [Category217]*/
#ifdef __MMI_CAT217_CAT213_SUPPORT_FMGR__
static void ExitCategory213Screen(void);
static void ExitCategory217Screen(void);
static S32 Cat217AsyncGetItemCallback(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size);
#endif

static S32 Cat217AsyncGetHintCallback(S32 start_index, UI_string_type *hint_array);
static S32 Cat219AsyncGetItemCallback(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size);
#ifdef __MMI_CAT217_CAT213_SUPPORT_FMGR__
static pBOOL Cat213GetItemCallback(S32 item_idx, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
static S32 Cat213GetHintCallback(S32 item_idx, UI_string_type *hint_array);

static void Cat213HighlightItem(void *item, void *common_item_data);
static void Cat213UnHighlightItem(void *item, void *common_item_data);
static void Cat213ShowItem(void *item, void *common_item_data, S32 x, S32 y);
static void Cat213HideItem(void *item, void *common_item_data, S32 x, S32 y);
#endif
#ifndef __MMI_SLIM_FILE_MANAGER__
/* [Category214] */
static void ExitCategory214Screen(void);
//static void Cat214ShortCutHdlr(S32 item_index);
#endif

/* [common] */
static void wgui_cat_fmgr_show_empty_string(UI_string_type empty_str);
static void wgui_cat_fmgr_print_text(S32 r_x, S32 x, S32 y, UI_string_type text);
#ifdef __MMI_CAT216_CAT212_SUPPORT_FMGR__
static Cat212GetInfoData wgui_cat212_fmgr_get_info_ptr = NULL;
static Cat212HideInfoData wgui_cat212_fmgr_hide_data_info_ptr = NULL;
#endif
#if defined(__MMI_CAT216_CAT212_SUPPORT_FMGR__) || defined(__MMI_CAT217_CAT213_SUPPORT_FMGR__)
static wgui_fmgr_category_struct fmgr_cat_context;
#endif

static CatFmgrGetFileData wgui_cat_fmgr_get_menuitem;
static CatFmgrHideFileData wgui_cat_fmgr_hide_menuitem;

#define WGUI_CAT_FMGR_MATRIX_BORDER_PIXEL       2
#define WGUI_CAT_FMGR_INFO_ROW_COUNT 2
#if defined(FMGR_USING_CACHE)
wgui_fmgr_set_displayable_func wgui_cat21x_set_displayable = NULL;
wgui_fmgr_get_displayable_func wgui_cat21x_get_displayable = NULL;
wgui_fmgr_get_thumb_image_func wgui_cat21x_get_image_path_callback = NULL;
Cat219DecodeDoneHdlr wgui_cat219_decode_done_hdlr = NULL;

#define WGUI_CAT_FMGR_CACHE_SEARCH_POINT_NUM    20
#define WGUI_CAT_FMGR_CACHE_MAX_PER_PAGE        30

#define WGUI_CAT_FMGR_UI_DELAY_DECODE_FIRST_DUR 80 
#define WGUI_CAT_FMGR_UI_DELAY_DECODE_NEXT_DUR  20 

#define WGUI_CAT_FMGR_CACHENONE  1
#define WGUI_CAT_FMGR_CACHING    2
#define WGUI_CAT_FMGR_CACHED     3
#define WGUI_CAT_FMGR_CACHEERROR 4

#define WGUI_CAT_FMGR_CACHE_ASM 0
#define WGUI_CAT_FMGR_CACHE_MDI 1



typedef struct tagCacheNode
{
    S32 index;
    PU8 buffer;
    S16 state;
    S16 mem_flag;
    struct tagCacheNode *next;
    struct tagCacheNode *prev;
    U16 cache_width;
    U16 cache_height;
} wgui_cat_fmgr_cache_node;


typedef struct
{
    wgui_cat_fmgr_cache_node *front_p;
    wgui_cat_fmgr_cache_node *rear_p;
} wgui_cat_fmgr_cache_search_list;


typedef struct tagMatrixPos
{
    S16 x;
    S16 y;
} wgui_cat_fmgr_cache_position;


typedef struct
{
    /* Cache items, should in cache option */

    /* Number of cache group */
    S16 cache_num;
    S16 cache_pre_page;
    S32 first_displayed_item;
    S32 highlight_index;
    S32 prev_first_displayed_item;
    /* Quick search group */
    wgui_cat_fmgr_cache_search_list cache_search_list[WGUI_CAT_FMGR_CACHE_SEARCH_POINT_NUM];
    /* The item that is decoding currently */
    wgui_cat_fmgr_cache_node *cur_decode_p;
    gdi_handle decoding_layer;
    gdi_handle decoding_handle;
    
    S32 decoding_index;
    wgui_cat_fmgr_cache_position cache_pos[WGUI_CAT_FMGR_CACHE_MAX_PER_PAGE];
    U16 decoder_create;
    S16 med_cache_num;
} wgui_cat_fmgr_cache_struct;

wgui_cat_fmgr_cache_struct *g_fmgr_cache_p = NULL;

#endif /* defined(FMGR_USING_CACHE) */ 


static S16 image_box_width;
static S16 image_box_height;

typedef struct
{
    U16 fmgr_style;
} wgui_cat_fmgr_struct;

wgui_cat_fmgr_struct *g_fmgr_struct_p;


typedef struct
{
#if defined(FMGR_USING_CACHE)
    wgui_cat_fmgr_cache_struct cache;
#endif /* #if defined(FMGR_USING_CACHE) */
    wgui_cat_fmgr_struct fmgr_struct;
} wgui_cat_fmgr_context_struct;

wgui_cat_fmgr_context_struct g_cat_fmgr_ctx;

#define g_213_fmgr g_cat_fmgr_ctx
#define g_212_fmgr g_cat_fmgr_ctx
#define g_214_fmgr g_cat_fmgr_ctx
typedef enum
{
    WGUI_CAT214_HIGHLIGHT_NORMAL,
    WGUI_CAT214_HIGHLIGHT_LAYER_TOP,
    WGUI_CAT214_HIGHLIGHT_LAYER_BOTTOM,
    WGUI_CAT214_HIGHLIGHT_NONE
} wgui_cat214_fmgr_highlight_layer_enum;

wgui_cat214_fmgr_highlight_layer_enum g_cat214_highlight_layer;



#if defined(FMGR_USING_CACHE)
static MMI_BOOL wgui_cat_fmgr_is_cached(S32 idx, wgui_cat_fmgr_cache_node **node_p);
static void wgui_cat_fmgr_cache_list_decoding_next(S32 idx);
static void wgui_cat_cache_draw_cached_img(wgui_cat_fmgr_cache_node *node_p, S32 x, S32 y);
static void wgui_cat_fmgr_decode_result_hdlr(GDI_RESULT decode_result, gdi_handle handle);
static void wgui_cat_fmgr_decode_frame_hdlr(GDI_RESULT decode_result, gdi_handle handle);
static void wgui_cat_fmgr_decode_before_frame_callback(GDI_RESULT decode_result, gdi_handle handle);
static wgui_cat_fmgr_cache_node *wgui_cat_fmgr_cache_create_node(void);
static void wgui_cat_fmgr_cache_free_node(wgui_cat_fmgr_cache_node *node);
static void wgui_cat_fmgr_cache_free_all(void);
static void wgui_cat_fmgr_cache_list_add(S32 idx, PU8 file_icon_p, wgui_cat_fmgr_cache_node *ref_node);
static void wgui_cat_fmgr_set_cache_pos(S32 idx, S32 first_displayed, wgui_cat_fmgr_cache_struct* fmgr_cache_p, S32 x1, S32 y1);
static void wgui_cat_fmgr_start_next(void);
static void wgui_cat_fmgr_delay_decode_timer(void);
static MMI_BOOL wgui_cat_fmgr_check_is_show_thumbnail(S32 idx);
#endif /* #if defined(FMGR_USING_CACHE) */

static void wgui_cat_fmgr_show_img(
        S32 idx, 
        BOOL is_hilighted, 
        wgui_fmgr_menuitem_data_struct *menuitem_data, 
        S32 x1, 
        S32 y1, 
        S32 x2, 
        S32 y2);
        
static void wgui_cat214_fmgr_draw_matrix_highlight(
        S32 x1, 
        S32 y1, 
        S32 x2, 
        S32 y2);
        

static void wgui_fmgr_redraw_image_background(BOOL is_hilighted, U16 ui_style, 
                                             gdi_color bg_color, S32 x1, S32 y1, S32 x2, S32 y2);
static gdi_color wgui_fmgr_get_bg_color(BOOL is_hilighted, U16 ui_style);

extern void ShowCategory211InternalScreen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 num_of_items,
        GetItemFuncPtr get_item_func,
        GetHintFuncPtr get_hint_func,
        Cat212DrawInfoFuncPtr draw_info_callback,
        Cat212HideInfoFuncPtr hide_info_callback,
        checkbox_get_image_funcptr_type get_image_func,
        checkbox_clicked_funcptr_type set_state_func,
        S32 info_box_height,
        U16 info_bg_img_id,
        U8* info_message,
        S32 highlighted_item,
        U8 *history_buffer);

static void ShowCategory219Screen_int(
        WCHAR *title,
        PU8 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        U16 num_of_items,
        Cat214DrawImageFuncPtr draw_image_callback,
        Cat214HideImageFuncPtr hide_image_callback,
        U8 num_per_row,
        U8 num_per_col,
        S32 highlighted_item,
        U8 *history_buffer,
        WCHAR *empty_string,
        S32 *category_error_flag);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
static void wgui_cat_fmgr_print_text(S32 r_x, S32 x, S32 y, UI_string_type text)
{
    if (mmi_fe_get_r2l_state())
    {
        gui_move_text_cursor(r_x, y);
    }
    else
    {
        gui_move_text_cursor(x, y);
    }
    
    gui_print_text(text);
}

static void wgui_cat_fmgr_show_empty_string(UI_string_type empty_str)
{
    S32 offset_x;
    S32 offset_y;
    S32 str_width;
    S32 str_height;
    S8 *str_ptr;

    gdi_layer_lock_frame_buffer();

    gui_reset_text_clip();
    gui_set_font(&MMI_medium_font);

    gui_set_text_color(*current_MMI_theme->list_normal_text_color);
    
#if defined(__MMI_FILE_MANAGER__)
    if(empty_str != NULL)
    {
        str_ptr = (S8*) empty_str;
    }
    else
    {
        str_ptr = GetString(STR_ID_FMGR_EMPTY_FOLDER);
    }
#else /* defined(__MMI_FILE_MANAGER__) */
    str_ptr = GetString(STR_GLOBAL_EMPTY_LIST);
#endif /* defined(__MMI_FILE_MANAGER__) */
    
    gui_measure_string((UI_string_type) str_ptr, &str_width, &str_height);
    offset_x = (UI_device_width - str_width) >> 1;
    offset_y = (UI_device_height - str_height) >> 1;
    wgui_cat_fmgr_print_text(offset_x + str_width, offset_x, offset_y, (UI_string_type)str_ptr);
    gdi_layer_unlock_frame_buffer();

    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}

/*****************************************************************************
* [Category212/216]
*
* This category is for File Manager to display drive info.
*
*  **********************
*  *                    *
*  *                  ----------- info box   
*  **********************
*  *  # Folder          *
*  *  # File A          *
*  *  # File B          *
*  *                    *
*  *                    *
*  *                 -------------- Fix List 
*  *                    *
*  *                    *
*  **********************
*
*****************************************************************************/
/* Dynamic Multi String/Iconic List */
extern S32 gui_asyncdynamic_list_error;
#ifdef __MMI_CAT216_CAT212_SUPPORT_FMGR__
static S32 g_cat218_previous_highlight_index = -1;

/*****************************************************************************
 * FUNCTION
 *  ExitCategory216Screen
 * DESCRIPTION
 *  Exit category 216
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory216Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cat_tab_num)
    {
        wgui_close_horizontal_tab_bar();
        g_cat_tab_num = 0;
    }
    if (cat212_hide_info_callback != NULL)
    {
        cat212_hide_info_callback();
    }
#if defined(FMGR_USING_CACHE)
    if (g_fmgr_cache_p != NULL)
    {
        wgui_cat_fmgr_cache_free_all();
        g_fmgr_cache_p->cur_decode_p = NULL;
        g_fmgr_cache_p = NULL; 
    }
#endif /* #if defined(FMGR_USING_CACHE) */


#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif 
    reset_menu_shortcut_handler();
    reset_dynamic_list();
    reset_pop_up_descriptions();
    reset_fixed_list_show_empty();

    gui_scrolling_text_stop(&fmgr_cat_context.scroll_text);
	g_cat218_previous_highlight_index = -1;
    /* reset cat212 related golbal var */
    cat212_info_box_height = 0;

    cat212_draw_info_callback = NULL;
    cat212_hide_info_callback = NULL;
}

/*****************************************************************************
 * FUNCTION
 *  ShowCategory212InfoArea
 * DESCRIPTION
 *  Show the info area for category212
 * PARAMETERS
 *  item_idx        [IN]        Item_index
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat216_highlight_hanlder(S32 item_idx)
{
    wgui_cat212_draw_info(
        item_idx, 
        0, 
        MMI_SUBMENU_CONTENT_Y, 
        UI_device_width - 1, 
        MMI_SUBMENU_CONTENT_Y + cat212_info_box_height - 1);

    asyncdynamic_list_highlight_handler(item_idx);
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory216Screen
 * DESCRIPTION
 *  Show category 216 screen.
 * PARAMETERS
 *  title                       [IN]        Title string buf
 *  title_icon                  [IN]        Title image buf
 *  left_softkey                [IN]        Lsk string buf
 *  left_softkey_icon           [IN]        Lsk image buf
 *  right_softkey               [IN]        Rsk string buf
 *  right_softkey_icon          [IN]        Rsk image buf
 *  num_of_items                [IN]        How many items
 *  get_item_func               [IN]        Callback function to get item string
 *  get_hint_func               [IN]        Callback function to get item hint
 *  list_icon                   [IN]        Icon used before text, measure the image's width and height
 *  draw_info_callback          [IN]        Callback function to draw info
 *  hide_info_callback          [IN]        Callback function to hide info
 *  get_image_func              [IN]        Get state of check-box function pointer
 *  set_state_func              [IN]        Set state of check-box function pointer 
 *  info_box_height             [IN]        Height of info box
 *  info_bg_img_id              [IN]        (unused)
 *  info_message                [IN]        Show info message in bottom 
 *  highlighted_item            [IN]        Highlighted item
 *  highlighted_tab             [IN]        Highlighted tab
 *  is_two_line                 [IN]        If show top info area or use two line to show info
 *  history_buffer              [IN]        History buffer
 *  category_error_flag         [IN]        Async-Dynamic list error flag
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory216Screen(
        U16  title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 num_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        U16 list_icon,
        Cat212DrawInfoFuncPtr draw_info_callback,
        Cat212HideInfoFuncPtr hide_info_callback,
        checkbox_get_image_funcptr_type get_image_func,
        checkbox_clicked_funcptr_type set_state_func,
        S32 info_box_height,
        U16 info_bg_img_id,
        U8* info_message,
        UI_string_type empty_message,
        S32 highlighted_item,
        S8 highlighted_tab,
        MMI_BOOL is_two_line,
        U8 *history_buffer,
        MMI_BOOL tab_flag,
        S32 *category_error_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    PU8 img;
    S32 h, w, text_width;
    S32 checkbox_width = 0, checkbox_height = 0;
    PU8 checkbox_img = NULL;
    S32 category_id = 0;
    S32 async_flag = 0;
    S8 n_tabs = 0;
	U8 h_flag;
	S32 list_height = MMI_content_height;
    S32 tool_bar_height = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (num_of_items == 0)
    {
        highlighted_item = -1;
    }

    /* Show shortcut when fullscreen backgournd */
    wgui_title_set_no_icon_shct(MMI_TRUE);
    gui_setup_common_layout();

    cat212_draw_info_callback = draw_info_callback;
    cat212_hide_info_callback = hide_info_callback;

    cat212_info_box_height = (U16) info_box_height;
    /* lock */
    gui_lock_double_buffer();

    gui_asyncdynamic_list_error = 0;
    *category_error_flag = 1;
    
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif 
    
    disable_fixed_list_show_empty();
#ifdef __MMI_ICON_BAR_SUPPORT__
#if defined(__MMI_FTE_SUPPORT__)
    if(MMI_TRUE == wgui_icon_bar_is_created())
    {
        tool_bar_height = MMI_ICON_BAR_HEIGHT;
    }
#endif
#endif/*__MMI_ICON_BAR_SUPPORT__*/
    /* Show Tab bars */
    mmi_frm_get_tab_bar_items(MMI_tab_bar_items, &n_tabs);
    if (n_tabs && tab_flag)
    {
            g_cat_tab_num = n_tabs;
            wgui_create_horizontal_tab_bar(TRUE, get_string(title), n_tabs, highlighted_tab, MMI_FALSE);
            if (is_two_line)
            {
                /* No info area, support two line highlight */
                if (info_message == NULL)
                {
                    category_id = MMI_CATEGORY218_TAB_ID;
					list_height = MMI_CONTENT_HEIGHT_WITH_H_TAB - tool_bar_height;
                }
                else
                {
                    category_id = MMI_CATEGORY218_INFO_TAB_ID;
					list_height = MMI_CONTENT_HEIGHT_WITH_H_TAB - MMI_MENUITEM_HEIGHT;
                }
                async_flag = WGUI_ASYNC_DYNAMIC_LIST_MENU_TWO_LINE;
            }
            else
            {
                ASSERT(0);  /* current only support cat218 */
            }
    }
    else
    {
        dm_add_title_id(title, title_icon);
        /* Support info area */
        if (is_two_line)
        {
            /* No info area, support two line highlight */
            if (info_message == NULL)
            {
                category_id = MMI_CATEGORY218_ID;
				list_height = MMI_content_height - tool_bar_height;
            }
            else
            {
                category_id = MMI_CATEGORY218_INFO_ID;
				list_height = MMI_content_height - MMI_MENUITEM_HEIGHT;
            }
            async_flag = WGUI_ASYNC_DYNAMIC_LIST_MENU_TWO_LINE;
        }
        else
        {
            if (info_message == NULL)
            {
                category_id = MMI_CATEGORY216_ID;
				list_height = MMI_content_height - cat212_info_box_height - tool_bar_height - 1;
            }
            else
            {
                category_id = MMI_CATEGORY216_INFO_ID;
				list_height = MMI_content_height - cat212_info_box_height - MMI_MENUITEM_HEIGHT;
            }

        }
    }

    dm_add_softkey_id(left_softkey, right_softkey);

    wgui_async_list_create_multi_icontext_menu(
        num_of_items,
        1,
        1,
        get_item_func,
        get_hint_func,
        WGUI_LIST_INVALID_HIGHLIGHT,
        MMI_MENUITEM_HEIGHT,
        async_flag,
        0,
        NULL);
    h_flag = set_list_menu_category_history(category_id, history_buffer);
    if (!h_flag)
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
    }
    
#if defined(FMGR_USING_CACHE)
    if (g_fmgr_cache_p != NULL)
    {
        g_fmgr_cache_p->highlight_index = MMI_fixed_list_menu.highlighted_item;
    }
#endif /* #if defined(FMGR_USING_CACHE) */

    img = (U8*) GetImage(list_icon);
    gdi_image_get_dimension(img, &w, &h);

    if (w == 0)
    {
        w = 15;
    }
    if (h == 0)
    {
        h = 15;
    }

    text_width = UI_device_width - MMI_fixed_list_menu.vbar.width - GUI_ICONTEXT_MENUITEM_TEXT_X - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - GUI_MENUITEM_TEXT_RIGHT_GAP;

    if (get_image_func != NULL)
    {
        if (num_of_items > 0)
        {
            get_image_func(0, &checkbox_img);
            gui_measure_image(checkbox_img, &checkbox_width, &checkbox_height);
            text_width = text_width - checkbox_width;
        }
        /* Multi-select mode */
        resize_fixed_list(MMI_SUBMENU_CONTENT_WIDTH, MMI_SUBMENU_CONTENT_HEIGHT - cat212_info_box_height - MMI_MENUITEM_HEIGHT);
        /* set check-box */
        wgui_menuitem_set_icontext_list_checkbox_position(1, 0);
        wgui_menuitem_register_icontext_list_checkbox_callback(set_state_func, get_image_func);
        set_fixed_icontext_list_icon_coordinates(0, GUI_ICONTEXT_MENUITEM_ICON_X + checkbox_width + 1, 0, w, h);
        set_fixed_icontext_list_text_coordinates(0, GUI_ICONTEXT_MENUITEM_TEXT_X + checkbox_width, 0, text_width, get_menu_item_height());
    }
    else
    {
        set_fixed_icontext_list_icon_coordinates(0, GUI_ICONTEXT_MENUITEM_ICON_X, 0, w, h);
        set_fixed_icontext_list_text_coordinates(0, GUI_ICONTEXT_MENUITEM_TEXT_X, 0, text_width, get_menu_item_height());
    }
    if(category_id == MMI_CATEGORY216_ID)
    {
        wgui_async_list_move_multi_icontext_menu(0, MMI_content_y + info_box_height + 1);
    }
    if(category_id == MMI_CATEGORY218_TAB_ID)
    {
        wgui_async_list_move_multi_icontext_menu(MMI_CONTENT_X_WITH_H_TAB, MMI_CONTENT_Y_WITH_H_TAB);
    }
	wgui_async_list_resize_multi_icontext_menu(MMI_content_width, list_height);

    ExitCategoryFunction = ExitCategory216Screen;
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = category_id;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    dm_setup_data(&dm_data);
    if (is_two_line)
    {
        wgui_menuitem_register_icontext_list_display_callback(wgui_cat218_draw_two_line_item);
    }
    else
    {
        dm_register_category_controlled_callback(DrawCate212CategoryControlArea);
        /* when hilight, will update info area */
        wgui_dynamic_list_override_icontext_highlight_handler(wgui_cat216_highlight_hanlder);
    }
    if (info_message != NULL && num_of_items != 0)
    {      
       dm_add_scroll_text(
            (UI_string_type)info_message,             
            NULL,
            wgui_cat212_scrolling_text_draw_background,
            *current_MMI_theme->list_normal_text_color,
            gui_color(255, 255, 255));
    }
    dm_redraw_category_screen();
    
    if (num_of_items == 0)
    {
        wgui_cat_fmgr_show_empty_string(empty_message);
    }    
    gui_unlock_double_buffer();
    
    if (gui_asyncdynamic_list_error)
    {
        return;
    }
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    *category_error_flag = 0;
}

/*****************************************************************************
 * FUNCTION
 *  ShowCategory211Screen
 * DESCRIPTION
 *  Show category 211 screen.
 * PARAMETERS
 *  title                       [IN]        Title string id
 *  title_icon                  [IN]        Title image id
 *  left_softkey                [IN]        Lsk string id
 *  left_softkey_icon           [IN]        Lsk image id
 *  right_softkey               [IN]        Rsk string id
 *  right_softkey_icon          [IN]        Rsk image id
 *  num_of_items                [IN]        How many items
 *  get_item_func               [IN]        Callback function to get item string
 *  get_hint_func               [IN]        Callback function to get item hint
 *  draw_info_callback          [IN]        Callback function to draw info
 *  hide_info_callback          [IN]        Callback function to hide info
 *  info_box_height             [IN]        Height of info box
 *  info_bg_img_id              [IN]        (unused)
 *  highlighted_item            [IN]        Highlighted item
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory211Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 num_of_items,
        GetItemFuncPtr get_item_func,
        GetHintFuncPtr get_hint_func,
        Cat212DrawInfoFuncPtr draw_info_callback,
        Cat212HideInfoFuncPtr hide_info_callback,
        S32 info_box_height,
        U16 info_bg_img_id,
        S32 highlighted_item,
        U8 *history_buffer)
{

    ShowCategory211InternalScreen(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        num_of_items,
        get_item_func,
        get_hint_func,
        draw_info_callback,
        hide_info_callback,
        NULL,
        NULL,
        info_box_height,
        info_bg_img_id,
        NULL,
        highlighted_item,
        history_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory211InternalScreen
 * DESCRIPTION
 *  Show category 211Internalscreen.
 * PARAMETERS
 *  title                       [IN]        Title string id
 *  title_icon                  [IN]        Title image id
 *  left_softkey                [IN]        Lsk string id
 *  right_softkey               [IN]        Rsk string id
 *  num_of_items                [IN]        How many items
 *  get_item_func               [IN]        Callback function to get item string
 *  get_hint_func               [IN]        Callback function to get item hint
 *  draw_info_callback          [IN]        Callback function to draw info
 *  hide_info_callback          [IN]        Callback function to hide info
 *  get_image_func              [IN]        Get state of check-box function pointer
 *  set_state_func              [IN]        Set state of check-box function pointer
 *  info_box_height             [IN]        Height of info box
 *  info_bg_img_id              [IN]        (unused)
 *  info_message                [IN]        Show info message in bottom
 *  highlighted_item            [IN]        Highlighted item
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory211InternalScreen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 num_of_items,
        GetItemFuncPtr get_item_func,
        GetHintFuncPtr get_hint_func,
        Cat212DrawInfoFuncPtr draw_info_callback,
        Cat212HideInfoFuncPtr hide_info_callback,
        checkbox_get_image_funcptr_type get_image_func,
        checkbox_clicked_funcptr_type set_state_func,
        S32 info_box_height,
        U16 info_bg_img_id,
        U8* info_message,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    U8 h_flag;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Show shortcut when fullscreen backgournd */
    wgui_title_set_no_icon_shct(MMI_TRUE);
    if (num_of_items == 0)
    {
        highlighted_item = -1;
    }
    
    cat212_draw_info_callback = draw_info_callback;
    cat212_hide_info_callback = hide_info_callback;
    
    cat212_info_box_height = (U16) info_box_height;
    /* lock */
    gui_lock_double_buffer();
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif 
    dm_add_title_id(title, title_icon);
    dm_add_softkey_id(left_softkey, right_softkey);
    
    wgui_dynamic_list_create_icontext_menu(
            num_of_items,
            get_item_func,
            get_hint_func,
            WGUI_LIST_INVALID_HIGHLIGHT,
            MMI_FALSE,
            UI_dummy_function,
            0,
            0,
            NULL);

    if (info_message != NULL)
    {
        resize_fixed_list(MMI_SUBMENU_CONTENT_WIDTH, MMI_SUBMENU_CONTENT_HEIGHT - cat212_info_box_height - MMI_MENUITEM_HEIGHT);
    }
    
    wgui_dynamic_list_override_icontext_shortcut_handler(Cat212ShortCutHdlr);
    
    /* adjust list */
    resize_fixed_icontext_menuitems(0, MMI_MENUITEM_HEIGHT);

    if (info_message != NULL)
    {
        set_fixed_icontext_positions(2*MMI_ICONTEXT_MENUITEM_HEIGHT + 3, 0, MMI_ICONTEXT_MENUITEM_HEIGHT + 2, 0);
        /* set check-box */
        wgui_menuitem_set_icontext_checkbox_position(1, 0);
        wgui_menuitem_register_icontext_checkbox_callback(set_state_func, get_image_func);
        h_flag = set_list_menu_category_history(MMI_CATEGORY211_ID, history_buffer);
    }
    else
    {
        h_flag = set_list_menu_category_history(MMI_CATEGORY212_ID, history_buffer);
    }

    if (!h_flag)
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
    }
        
    set_dynamic_pop_up_descriptions(highlighted_item);
    wgui_dynamic_list_move_icontext_menu(0, (MMI_SUBMENU_CONTENT_Y) + cat212_info_box_height);  /* use two menuitem height to draw drive info */
    wgui_dynamic_list_resize_icontext_menu(MMI_content_width, MMI_content_height - cat212_info_box_height);
    
    /* when hilight, will update info area */
    wgui_dynamic_list_override_icontext_highlight_handler(ShowCategory212InfoArea);
    
    resize_dynamic_icontext_menuitems_to_list_width();
    
    gui_unlock_double_buffer();
    
    ExitCategoryFunction = ExitCategory212Screen;
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    if (info_message != NULL)
    {    
        dm_data.s32CatId = MMI_CATEGORY211_ID;
    }
    else
    {
        dm_data.s32CatId = MMI_CATEGORY212_ID;
    }
    
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    dm_setup_data(&dm_data);
    dm_register_category_controlled_callback(DrawCate212CategoryControlArea);
    if (info_message != NULL)
    {      
        dm_add_scroll_text(
             (UI_string_type)info_message,             
             NULL,
             wgui_cat212_scrolling_text_draw_background,
             *current_MMI_theme->list_normal_text_color,
             gui_color(255, 255, 255));
    }
    dm_redraw_category_screen();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat212_init_fmgr
 * DESCRIPTION
 *  This function is used to init category 212/216/218 fmgr
 * PARAMETERS
 *  num_of_items                [IN]        How many items
 *  num_of_info_box_rows        [IN]        How many row (height) for info box
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat212_init_fmgr(S32 num_of_items, U16 num_of_info_box_rows)
{
#if defined(FMGR_USING_CACHE)
    S32 number;

    memset(&g_212_fmgr, 0, sizeof(g_212_fmgr));
    g_fmgr_cache_p= &(g_212_fmgr.cache);

    number = num_of_items/(WGUI_CAT_FMGR_CACHE_SEARCH_POINT_NUM-1);
    g_fmgr_cache_p->cache_num = 1;
    do{
        g_fmgr_cache_p->cache_num = g_fmgr_cache_p->cache_num<<1;
    }while(number >= g_fmgr_cache_p->cache_num);

#endif /* #if defined(FMGR_USING_CACHE) */
    g_fmgr_struct_p = &(g_212_fmgr.fmgr_struct);
    
    image_box_width = num_of_info_box_rows * MMI_ICONTEXT_MENUITEM_HEIGHT - 1 - FMGR_UI_IMAGE_BOX_SPACING * 2;
    image_box_height = num_of_info_box_rows * MMI_ICONTEXT_MENUITEM_HEIGHT - 1 - FMGR_UI_IMAGE_BOX_SPACING * 2;

}


#if defined(FMGR_USING_CACHE)
/*****************************************************************************
 * FUNCTION
 *  wgui_cat212_cache_start
 * DESCRIPTION
 *  Category 212/216/218 fmgr start cache.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat212_cache_start(void)
{
    g_fmgr_cache_p->cache_pre_page = MMI_fixed_list_menu.displayed_items;

    if (g_fmgr_cache_p->cur_decode_p == NULL && MMI_fixed_list_menu.n_items != 0)
    {
        g_fmgr_cache_p->first_displayed_item = MMI_fixed_list_menu.first_displayed_item;
        wgui_cat_fmgr_cache_list_decoding_next(g_fmgr_cache_p->first_displayed_item);
    }    
}
#endif


/*****************************************************************************
 * FUNCTION
 *  ShowCategory212FmgrMarkScreen
 * DESCRIPTION
 *  Show Category 212 only for fmgr screen multi-select.
 * PARAMETERS
 *  title                       [IN]        Title string id
 *  title_icon                  [IN]        Title image id
 *  left_softkey                [IN]        Lsk string id
 *  left_softkey_icon           [IN]        Lsk image id
 *  right_softkey               [IN]        Rsk string id
 *  right_softkey_icon          [IN]        Rsk image id
 *  num_of_items                [IN]        How many items
 *  get_item_func               [IN]        Callback function to get item string
 *  get_hint_func               [IN]        Callback function to get item hint
 *  get_info_data               [IN]        Info area get data
 *  hide_info_data              [IN]        Hide info area callback
 *  get_image_func              [IN]        Get check-box image callback
 *  set_state_func              [IN]        Set select state callback
 *  num_of_info_box_rows        [IN]        How many row (height) for info box
 *  info_bg_img_id              [IN]        (unused)
 *  highlighted_item            [IN]        Highlighted item
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory212FmgrMarkScreen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 num_of_items,
        GetItemFuncPtr get_item_func,
        GetHintFuncPtr get_hint_func,
        Cat212GetInfoData get_info_data,
        Cat212HideInfoData hide_info_data,
        checkbox_get_image_funcptr_type get_image_func,
        checkbox_clicked_funcptr_type set_state_func,
        U16 num_of_info_box_rows,
        U16 info_bg_img_id,
        U8* info_message,
        S32 highlighted_item,
        U8 *history_buffer)
{
    wgui_cat212_init_fmgr(num_of_items, num_of_info_box_rows);

    g_fmgr_struct_p->fmgr_style = MMI_FMGR_GUI_INFO_STYLE;

    wgui_cat212_fmgr_get_info_ptr = get_info_data;
    wgui_cat212_fmgr_hide_data_info_ptr = hide_info_data;

    ShowCategory211InternalScreen(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        num_of_items,
        get_item_func,
        get_hint_func,
        wgui_cat212_fmgr_draw_info,
        wgui_cat212_fmgr_hide_info,
        get_image_func,
        set_state_func,
        (S32) num_of_info_box_rows * MMI_ICONTEXT_MENUITEM_HEIGHT - 1, /* need 1 pixel between info and list */
        info_bg_img_id,
        info_message,
        highlighted_item,
        history_buffer);

#if defined(FMGR_USING_CACHE)
    wgui_cat212_cache_start();
#endif /* #if defined(FMGR_USING_CACHE) */
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory212FmgrScreen
 * DESCRIPTION
 *  Show Category 212 only for fmgr screen.
 * PARAMETERS
 *  title                       [IN]        Title string id
 *  title_icon                  [IN]        Title image id
 *  left_softkey                [IN]        Lsk string id
 *  left_softkey_icon           [IN]        Lsk image id
 *  right_softkey               [IN]        Rsk string id
 *  right_softkey_icon          [IN]        Rsk image id
 *  num_of_items                [IN]        How many items
 *  get_item_func               [IN]        Callback function to get item string
 *  get_hint_func               [IN]        Callback function to get item hint
 *  get_info_data               [IN]        Info area get data
 *  hide_info_data              [IN]        Hide info area callback
 *  num_of_info_box_rows        [IN]        How many row (height) for info box
 *  info_bg_img_id              [IN]        (unused)
 *  highlighted_item            [IN]        Highlighted item
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory212FmgrScreen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 num_of_items,
        GetItemFuncPtr get_item_func,
        GetHintFuncPtr get_hint_func,
        Cat212GetInfoData get_info_data,
        Cat212HideInfoData hide_info_data,
        U16 num_of_info_box_rows,
        U16 info_bg_img_id,
        S32 highlighted_item,
        U8 *history_buffer)
{
    wgui_cat212_init_fmgr(num_of_items, num_of_info_box_rows);
    g_fmgr_struct_p->fmgr_style = MMI_FMGR_GUI_INFO_STYLE;

    wgui_cat212_fmgr_get_info_ptr = get_info_data;
    wgui_cat212_fmgr_hide_data_info_ptr = hide_info_data;
    
    ShowCategory211InternalScreen(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        num_of_items,
        get_item_func,
        get_hint_func,
        wgui_cat212_fmgr_draw_info,
        wgui_cat212_fmgr_hide_info,
        NULL,
        NULL,
        (S32) num_of_info_box_rows * MMI_ICONTEXT_MENUITEM_HEIGHT - 1, /* need 1 pixel between info and list */
        info_bg_img_id,
        NULL,
        highlighted_item,
        history_buffer);

#if defined(FMGR_USING_CACHE)
    wgui_cat212_cache_start();
#endif /* #if defined(FMGR_USING_CACHE) */
}

/* Please find function description in header file */
void ShowCategory216FmgrMarkScreen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 num_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        S32 list_icon,
        Cat212GetInfoData get_info_data,
        Cat212HideInfoData hide_info_data,
        checkbox_get_image_funcptr_type get_image_func,
        checkbox_clicked_funcptr_type set_state_func,
        U16 num_of_info_box_rows,
        U16 info_bg_img_id,
        U8* info_message,
		UI_string_type empty_string,
        S32 highlighted_item,
        U8 *history_buffer,
        S32 *category_error_flag)        
{
    wgui_cat212_init_fmgr(num_of_items, num_of_info_box_rows);
    g_fmgr_struct_p->fmgr_style = MMI_FMGR_GUI_INFO_STYLE;

    wgui_cat212_fmgr_get_info_ptr = get_info_data;
    wgui_cat212_fmgr_hide_data_info_ptr = hide_info_data;

    ShowCategory216Screen(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        num_of_items,
        get_item_func,
        get_hint_func,
        list_icon,
        wgui_cat212_fmgr_draw_info,
        wgui_cat212_fmgr_hide_info,
        get_image_func,
        set_state_func,    
        (S32) num_of_info_box_rows * MMI_ICONTEXT_MENUITEM_HEIGHT - 1, /* need 1 pixel between info and list */
        info_bg_img_id,
        info_message,
        empty_string,
        highlighted_item,
        0,
        MMI_FALSE,
        history_buffer,
        MMI_FALSE,
        category_error_flag);

#if defined(FMGR_USING_CACHE)
    wgui_cat212_cache_start();
#endif /* #if defined(FMGR_USING_CACHE) */
}


/* Please find function description in header file */
void ShowCategory216FmgrScreen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 num_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        S32 list_icon,
        Cat212GetInfoData get_info_data,
        Cat212HideInfoData hide_info_data,
        U16 num_of_info_box_rows,
        U16 info_bg_img_id,
		UI_string_type empty_string,
        S32 highlighted_item,
        U8 *history_buffer,
        S32 *category_error_flag)
{
    wgui_cat212_init_fmgr(num_of_items, num_of_info_box_rows);
    g_fmgr_struct_p->fmgr_style = MMI_FMGR_GUI_INFO_STYLE;

    wgui_cat212_fmgr_get_info_ptr = get_info_data;
    wgui_cat212_fmgr_hide_data_info_ptr = hide_info_data;

    ShowCategory216Screen(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        num_of_items,
        get_item_func,
        get_hint_func,
        list_icon,
        wgui_cat212_fmgr_draw_info,
        wgui_cat212_fmgr_hide_info,
        NULL,
        NULL,     
        (S32) num_of_info_box_rows * MMI_ICONTEXT_MENUITEM_HEIGHT - 1, /* need 1 pixel between info and list */
        info_bg_img_id,
        NULL,
        empty_string,
        highlighted_item,
        0,
        MMI_FALSE,
        history_buffer,
        MMI_FALSE,
        category_error_flag);

#if defined(FMGR_USING_CACHE)
    wgui_cat212_cache_start(); 
#endif /* #if defined(FMGR_USING_CACHE) */
    }



/* Please find function description in header file */
void ShowCategory218FmgrMarkScreen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 num_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        S32 list_icon,
        Cat212GetInfoData get_info_data,
        Cat212HideInfoData hide_info_data,
        checkbox_get_image_funcptr_type get_image_func,
        checkbox_clicked_funcptr_type set_state_func,
        U16 num_of_info_box_rows,
        U16 info_bg_img_id,
        U8* info_message,
        UI_string_type empty_string,
        S32 highlighted_item,
        U8 *history_buffer,
        S32 *category_error_flag)        
{
    wgui_cat212_init_fmgr(num_of_items, num_of_info_box_rows);
    g_fmgr_struct_p->fmgr_style = MMI_FMGR_GUI_HILITE_STYLE;

    wgui_cat212_fmgr_get_info_ptr = get_info_data;
    wgui_cat212_fmgr_hide_data_info_ptr = hide_info_data;

    ShowCategory216Screen(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        num_of_items,
        get_item_func,
        get_hint_func,
        list_icon,
        wgui_cat212_fmgr_draw_info,
        wgui_cat212_fmgr_hide_info,
        get_image_func,
        set_state_func,    
        (S32) num_of_info_box_rows * MMI_ICONTEXT_MENUITEM_HEIGHT - 1, /* need 1 pixel between info and list */
        info_bg_img_id,
        info_message,
        empty_string,
        highlighted_item,
        0,
        MMI_TRUE,
        history_buffer,
        MMI_FALSE,
        category_error_flag);

#if defined(FMGR_USING_CACHE)
    wgui_cat212_cache_start();  
#endif /* #if defined(FMGR_USING_CACHE) */
}    


/* Please find function description in header file */
void ShowCategory218FmgrScreen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 num_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        S32 list_icon,
        Cat212GetInfoData get_info_data,
        Cat212HideInfoData hide_info_data,
        U16 num_of_info_box_rows,
        U16 info_bg_img_id,
        UI_string_type empty_string,
        S32 highlighted_item,
        U8 *history_buffer,
        S32 *category_error_flag)
{
    wgui_cat212_init_fmgr(num_of_items, num_of_info_box_rows);
    g_fmgr_struct_p->fmgr_style = MMI_FMGR_GUI_HILITE_STYLE;

    wgui_cat212_fmgr_get_info_ptr = get_info_data;
    wgui_cat212_fmgr_hide_data_info_ptr = hide_info_data;

    ShowCategory216Screen(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        num_of_items,
        get_item_func,
        get_hint_func,
        list_icon,
        wgui_cat212_fmgr_draw_info,
        wgui_cat212_fmgr_hide_info,
        NULL,
        NULL,     
        (S32) num_of_info_box_rows * MMI_ICONTEXT_MENUITEM_HEIGHT - 1, /* need 1 pixel between info and list */
        info_bg_img_id,
        NULL,
        empty_string,
        highlighted_item,
        0,
        MMI_TRUE,
        history_buffer,
        MMI_FALSE,
        category_error_flag);

#if defined(FMGR_USING_CACHE)
    wgui_cat212_cache_start();
#endif /* #if defined(FMGR_USING_CACHE) */
}


/* Please find function description in header file */
void ShowCategory218FmgrTabScreen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 num_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        S32 list_icon,
        Cat212GetInfoData get_info_data,
        Cat212HideInfoData hide_info_data,
        U16 num_of_info_box_rows,
        U16 info_bg_img_id,
        UI_string_type empty_string,
        S32 highlighted_item,
		S8 highlighted_tab,
        U8 *history_buffer,
        S32 *category_error_flag)
{
    wgui_cat212_init_fmgr(num_of_items, num_of_info_box_rows);
    g_fmgr_struct_p->fmgr_style = MMI_FMGR_GUI_HILITE_STYLE;

    wgui_cat212_fmgr_get_info_ptr = get_info_data;
    wgui_cat212_fmgr_hide_data_info_ptr = hide_info_data;

    ShowCategory216Screen(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        num_of_items,
        get_item_func,
        get_hint_func,
        list_icon,
        wgui_cat212_fmgr_draw_info,
        wgui_cat212_fmgr_hide_info,
        NULL,
        NULL,     
        (S32) (num_of_info_box_rows * MMI_ICONTEXT_MENUITEM_HEIGHT - 1), /* need 1 pixel between info and list */
        info_bg_img_id,
        NULL,
        empty_string,
        highlighted_item,
        highlighted_tab,
        MMI_TRUE,
        history_buffer,
        MMI_TRUE,
        category_error_flag);

#if defined(FMGR_USING_CACHE)
    wgui_cat212_cache_start();
#endif /* #if defined(FMGR_USING_CACHE) */
}

/*****************************************************************************
 * FUNCTION
 *  ShowCategory212Screen
 * DESCRIPTION
 *  Show category 212 screen.
 * PARAMETERS
 *  title                       [IN]        Title string id
 *  title_icon                  [IN]        Title image id
 *  left_softkey                [IN]        Lsk string id
 *  left_softkey_icon           [IN]        Lsk image id
 *  right_softkey               [IN]        Rsk string id
 *  right_softkey_icon          [IN]        Rsk image id
 *  num_of_items                [IN]        How many items
 *  get_item_func               [IN]        Callback function to get item string
 *  get_hint_func               [IN]        Callback function to get item hint
 *  draw_info_callback          [IN]        Callback function to draw info
 *  hide_info_callback          [IN]        Callback function to hide info
 *  num_of_info_box_rows        [IN]        How many row (height) for info box
 *  info_bg_img_id              [IN]        (unused)
 *  highlighted_item            [IN]        Highlighted item
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory212Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 num_of_items,
        GetItemFuncPtr get_item_func,
        GetHintFuncPtr get_hint_func,
        Cat212DrawInfoFuncPtr draw_info_callback,
        Cat212HideInfoFuncPtr hide_info_callback,
        U16 num_of_info_box_rows,
        U16 info_bg_img_id,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory211InternalScreen(
        title, 
        title_icon,
        left_softkey,
        right_softkey,
        num_of_items,
        get_item_func,
        get_hint_func,
        draw_info_callback,
        hide_info_callback,
        NULL,
        NULL,
        (S32) num_of_info_box_rows * MMI_ICONTEXT_MENUITEM_HEIGHT - 1, /* need 1 pixel between info and list */
        info_bg_img_id,
        NULL,
        highlighted_item,
        history_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory212Screen
 * DESCRIPTION
 *  Exit category 212 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategory212Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cat212_hide_info_callback != NULL)
    {
        cat212_hide_info_callback();
    }
#if defined(FMGR_USING_CACHE)
    if (g_fmgr_cache_p != NULL)
    {
        wgui_cat_fmgr_cache_free_all();
        g_fmgr_cache_p->cur_decode_p = NULL;
        g_fmgr_cache_p = NULL; 
    }
#endif /* #if defined(FMGR_USING_CACHE) */

    
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif 

    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_dynamic_list();
    reset_pop_up_descriptions();

    /* reset cat212 related golbal var */
    cat212_info_box_height = 0;

    cat212_draw_info_callback = NULL;
    cat212_hide_info_callback = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  DrawCate212CategoryControlArea
 * DESCRIPTION
 *  This function is used to draw the category controlled area of category212 screen
 * PARAMETERS
 *  coordinate      [IN/OUT]        Coordinates of category controlled area.
 * RETURNS
 *  void
 *****************************************************************************/
static void DrawCate212CategoryControlArea(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory212InfoArea(MMI_fixed_list_menu.highlighted_item);
    coordinate->s16X = 0;
    coordinate->s16Y = MMI_SUBMENU_CONTENT_Y;
    coordinate->s16Height = cat212_info_box_height + 1; /* need 1 pixel between info and list */
    coordinate->s16Width = MMI_content_width;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat218_draw_two_line_item
 * DESCRIPTION
 *  This function is used to draw the category two line area
 * PARAMETERS
 *  x1                  [IN]   poisition x1
 *  y1                  [IN]   poisition y1
 *  x2                  [IN]   poisition x2
 *  y2                  [IN]   poisition y2
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat218_draw_two_line_item(void *item, S32 x1, S32 y1, S32 x2, S32 y2)
{
    PU8 checkbox_img;
    S32 iwidth, iheight;
    S32 checkbox_x, checkbox_y;
    
    fixed_icontext_list_menuitem_type *mi = (fixed_icontext_list_menuitem_type*) item;
	if(g_cat218_previous_highlight_index != MMI_fixed_list_menu.highlighted_item)
	{
		wgui_cat218_fmgr_hide_hilite_item();
	}
#if defined(FMGR_USING_CACHE)
    if (g_fmgr_cache_p != NULL)
    {
        g_fmgr_cache_p->highlight_index = MMI_fixed_list_menu.highlighted_item;
    }
#endif /* #if defined(FMGR_USING_CACHE) */

    wgui_cat218_fmgr_draw_hilite_item(MMI_fixed_list_menu.highlighted_item, mi->item_texts[0], x1, y1, x2, y2);

    /* If two line hilite style, maybe need to draw checkbox */
    if (g_fmgr_struct_p->fmgr_style == MMI_FMGR_GUI_HILITE_STYLE)
    {
        
        if (MMI_fixed_icontext_list_menuitem.ext_flags & UI_MENUITEM_EXT_SHOW_ICONTEXT_CHECKBOX)
        {
            MMI_fixed_icontext_list_menuitem.checkbox_get_image_callback(MMI_fixed_list_menu.highlighted_item, &checkbox_img);
            gui_measure_image(checkbox_img, &iwidth, &iheight);
            checkbox_x = x1 + MMI_fixed_icontext_list_menuitem.checkbox_x;
            if (MMI_fixed_icontext_list_menuitem.checkbox_y == 0)
            {   /* vertical center align */
                checkbox_y = y1 + (MMI_fixed_icontext_list_menuitem.height - iheight) / 2;
            }    
            else
            {
                checkbox_y = y1 + MMI_fixed_icontext_list_menuitem.checkbox_y;
            }
            gui_push_clip();
            gui_reset_clip();
            gdi_image_draw(checkbox_x, checkbox_y, checkbox_img); /* Need to sync with List */
            gui_pop_clip();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat212_scrolling_text_draw_background
 * DESCRIPTION
 *  Draw category 212 scrolling text draw background
 * PARAMETERS
 *  x1      [IN]        Start x posityion
 *  y1      [IN]        Start y position
 *  x2      [IN]        End x position
 *  y2      [IN]        End y position
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat212_scrolling_text_draw_background(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
}

#endif /* __MMI_CAT216_CAT212_SUPPORT_FMGR__ */
/*****************************************************************************
 * FUNCTION
 *  DrawTextAreaBackground
 * DESCRIPTION
 *  Show the background of text area
 * PARAMETERS
 *  x1              [IN]        x1
 *  y1              [IN]        y1
 *  x2              [IN]        x2
 *  y2              [IN]        y2
 * RETURNS
 *  void
 *****************************************************************************/
void DrawTextAreaBackground(S32 x1, S32 y1, S32 x2, S32 y2)
{
#if defined(__MMI_FWUI_SLIM__)
    gdi_image_draw_resized_id(x1, y1, (x2 - x1 + 1), (y2 - y1 + 1), WGUI_IMG_TEXT_BG_PREVIEW);
#else
#if defined(__MMI_SLIM_IMG_RES__)
	gdi_image_draw_resized_id(x1, y1, (x2 - x1 + 1), (y2 - y1 + 1), WGUI_IMG_TEXT_BG_MID);
#elif defined(__MMI_FTE_SUPPORT__)
    gdi_image_draw_resized_id(x1, y1, (x2 - x1 + 1), (y2 - y1 + 1), WGUI_IMG_TEXT_BG_MID);
#else
    S32 info_bg_y,info_bg_bottom_y;
    S32 image_width, image_height;
    
    /* Draw top area */
    info_bg_y = y1;
    gdi_image_get_dimension_id(WGUI_IMG_TEXT_BG_TOP, &image_width, &image_height);
    gdi_image_draw_id(x1, info_bg_y, WGUI_IMG_TEXT_BG_TOP);
    info_bg_y += image_height;

    /* Draw bottom area */
    gdi_image_get_dimension_id(WGUI_IMG_TEXT_BG_BOTTOM, &image_width, &image_height);
    info_bg_bottom_y = (y2 - image_height + 1);
    gdi_image_draw_id(x1, info_bg_bottom_y, WGUI_IMG_TEXT_BG_BOTTOM);

    /* Draw middle area */
    gui_push_clip();
    gui_set_clip(
        x1,
        info_bg_y,
        x2,
        info_bg_bottom_y - 1);

    gdi_image_get_dimension_id(WGUI_IMG_TEXT_BG_MID, &image_width, &image_height);
    do
    {
        gdi_image_draw_id(x1, info_bg_y, WGUI_IMG_TEXT_BG_MID);
        info_bg_y += image_height;
    }while ((info_bg_y < info_bg_bottom_y) && (image_height != 0));
    gui_pop_clip();
#endif /* __MMI_FTE_SUPPORT__ */
#endif /* __MMI_FWUI_SLIM__ */
}


/*****************************************************************************
 * FUNCTION
 *  FillFullTextBackground
 * DESCRIPTION
 *  fill full area with text background image
 * PARAMETERS
 *  x1              [IN]        x1
 *  y1              [IN]        y1
 *  x2              [IN]        x2
 *  y2              [IN]        y2
 * RETURNS
 *  void
 *****************************************************************************/
void FillFullTextBackground(S32 x1, S32 y1, S32 x2, S32 y2)
{
#if defined(__MMI_FWUI_SLIM__)
    gdi_image_draw_resized_id(x1, y1, (x2 - x1 + 1), (y2 - y1 + 1), WGUI_IMG_TEXT_BG_PREVIEW);
#else
#if defined(__MMI_FTE_SUPPORT__)|| defined(__MMI_SLIM_IMG_RES__)
    gdi_image_draw_resized_id(x1, y1, (x2 - x1 + 1), (y2 - y1 + 1), WGUI_IMG_TEXT_BG_MID);
#else
    S32 info_bg_y;
    S32 image_width, image_height;
    
    /* Draw middle area */
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    
    info_bg_y = y1;
    gdi_image_get_dimension_id(WGUI_IMG_TEXT_BG_PREVIEW, &image_width, &image_height);
    do
    {
        gdi_image_draw_id(x1, info_bg_y, WGUI_IMG_TEXT_BG_PREVIEW);
        info_bg_y += image_height;
    }while ((info_bg_y <= y2) && (image_height != 0));
    gui_pop_clip();
#endif
#endif
}

#ifdef __MMI_CAT216_CAT212_SUPPORT_FMGR__
/*****************************************************************************
 * FUNCTION
 *  wgui_cat212_draw_info
 * DESCRIPTION
 *  Show the info area for category212
 * PARAMETERS
 *  item_idx        [IN]        Item_index
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat212_draw_info(S32 item_idx, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_fixed_list_get_style() != GUI_MENU_TYPE_ASYNCDYNAMIC)
    {
        /* call dynamic list's hilight handler */
        dynamic_list_highlight_handler(item_idx);
    }

    gdi_layer_lock_frame_buffer();

    /* drive info block */
    gui_reset_clip();

    /* stop previous action, such as gif animation, decoder, timer etc. */
    if (cat212_hide_info_callback != NULL)
    {
        cat212_hide_info_callback();
    }

#if defined(FMGR_USING_CACHE)
    if (g_fmgr_cache_p != NULL)
    {
        g_fmgr_cache_p->highlight_index = MMI_fixed_list_menu.highlighted_item;
        gdi_image_cache_reset();
    }
#endif /* #if defined(FMGR_USING_CACHE) */

    /* if is emtpty folder, show a empty string */
    if (MMI_fixed_list_menu.n_items == 0)
    {
        wgui_cat_fmgr_show_empty_string(NULL);
    }
    else
    {
#if defined(__MMI_MAINLCD_128X128__)  
        gui_fill_rectangle(x1, y1, x2, y2, gui_color(255, 255, 255));
        gui_draw_rectangle(x1, y1, x2, y2, gui_color(0, 0, 0));
#else
        DrawTextAreaBackground(x1, y1, x2, y2);
#endif
        if (cat212_draw_info_callback != NULL)
        {
            cat212_draw_info_callback(MMI_fixed_list_menu.highlighted_item, x1, y1, x2, y2);
        }
    }
    /* 
     * lock then blt, will not update to lcm directly, but will force next blt function 
     * also update this region 
     */
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    gdi_layer_unlock_frame_buffer();

#if defined(FMGR_USING_CACHE)
    if (MMI_fixed_list_menu.n_items != 0)
    {
        wgui_cat_fmgr_start_next();
    }
#endif /* #if defined(FMGR_USING_CACHE) */
}

/*****************************************************************************
 * FUNCTION
 *  ShowCategory212InfoArea
 * DESCRIPTION
 *  Show the info area for category212
 * PARAMETERS
 *  item_idx        [IN]        Item_index
 * RETURNS
 *  void
 *****************************************************************************/
static void ShowCategory212InfoArea(S32 item_idx)
{
    wgui_cat212_draw_info(
        item_idx, 
        0, 
        MMI_SUBMENU_CONTENT_Y, 
        UI_device_width - 1, 
        MMI_SUBMENU_CONTENT_Y + cat212_info_box_height - 1);
}

#endif /* __MMI_CAT216_CAT212_SUPPORT_FMGR__ */
/*****************************************************************************
 * FUNCTION
 *  Cat212ShortCutHdlr
 * DESCRIPTION
 *  Category 212 short cut goto item hdlr
 * PARAMETERS
 *  item_index      [IN]        Goto item's index
 * RETURNS
 *  void
 *****************************************************************************/
void Cat212ShortCutHdlr(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items <= 0)
    {
        return;
    }
    if (item_index == MMI_fixed_list_menu.highlighted_item)
    {
        return;
    }

    gui_dynamic_list_menu_goto_item(&MMI_fixed_list_menu, item_index);

    if (item_index == MMI_fixed_list_menu.highlighted_item)
    {
        RedrawCategoryFunction();
    }
}

#ifdef __MMI_CAT217_CAT213_SUPPORT_FMGR__
/*****************************************************************************
 * FUNCTION
 *  DrawCate213CategoryControlArea
 * DESCRIPTION
 *  draw control area
 * PARAMETERS
 *  coordinate      [IN]        Coordinate
 * RETURNS
 *  void
 *****************************************************************************/
void DrawCate213CategoryControlArea(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items == 0)
    {
        show_dynamic_list();
        wgui_cat_fmgr_show_empty_string(MMI_message_string);
    }
}


void ShowCategory213FmgrScreen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 num_of_items,
        CatFmgrGetFileData get_menuitem_data,
        CatFmgrHideFileData hide_menuitem_data,
        S32 highlighted_item,
        U8 arrow_flag,
        U8 *history_buffer)    
{
#if defined(FMGR_USING_CACHE)
    S32 number;    
    
    memset(&g_213_fmgr, 0, sizeof(g_213_fmgr));
    g_fmgr_cache_p= &(g_213_fmgr.cache);

    number = num_of_items/(WGUI_CAT_FMGR_CACHE_SEARCH_POINT_NUM-1);
    g_fmgr_cache_p->cache_num = 1;
    do{
        g_fmgr_cache_p->cache_num = g_fmgr_cache_p->cache_num<<1;
    }while(number >= g_fmgr_cache_p->cache_num);

#endif /* #if defined(FMGR_USING_CACHE) */

    g_fmgr_struct_p = &(g_213_fmgr.fmgr_struct);
    g_fmgr_struct_p->fmgr_style = MMI_FMGR_GUI_LIST_STYLE;

    wgui_cat_fmgr_get_menuitem = get_menuitem_data;
    wgui_cat_fmgr_hide_menuitem = hide_menuitem_data;

    ShowCategory213Screen(
        title,
        title_icon,
        left_softkey,
        left_softkey_icon,
        right_softkey,
        right_softkey_icon,
        num_of_items,
        wgui_cat213_fmgr_draw_menuitem,
        wgui_cat213_fmgr_hide_menuitem,
        highlighted_item,
        arrow_flag,
        history_buffer);

#if defined(FMGR_USING_CACHE)
    if (g_fmgr_cache_p->cur_decode_p == NULL && num_of_items != 0)
    {
        g_fmgr_cache_p->first_displayed_item = MMI_fixed_list_menu.first_displayed_item;
        wgui_cat_fmgr_cache_list_decoding_next(g_fmgr_cache_p->first_displayed_item);
    }
#endif /* #if defined(FMGR_USING_CACHE) */
}

/*****************************************************************************
* [Category213]
*
* This category is for ImageViewer to display drive info.
*
*  **********************
*  *  ####  FileName    *
*  *  ####  Res    Size *  
*  **********************
*  *  ####  FileName    *
*  *  ####  Res    Size *  
*  **********************
*  *  ####  FileName    *
*  *  ####  Res    Size *  
*  **********************
*  *  ####  FileName    *
*  *  ####  Res    Size *  
*  **********************
*
*****************************************************************************/
static MMI_BOOL wgui_cat217_query_draw_last_frame(void)
{

    if (GetExitScrnID() != GetActiveScreenId())
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
 *  ShowCategory217Screen
 * DESCRIPTION
 *  Show sategory 217 screen. async-dynamic list of category 213
 * PARAMETERS
 *  title                       [IN]        Title string id
 *  title_icon                  [IN]        Title image id
 *  left_softkey                [IN]        Lsk string id
 *  left_softkey_icon           [IN]        Lsk image id
 *  right_softkey               [IN]        Rsk string id
 *  right_softkey_icon          [IN]        Rsk image id
 *  num_of_items                [IN]        How many items
 *  get_item_func               [IN]        Callback function to get item string
 *  get_hint_func               [IN]        Callback function to get item hint
 *  draw_menuitem_callback      [IN]        Callback function to draw menuitem
 *  hide_menuitem_callback      [IN]        Callback function to hide menuitem
 *  highlighted_item            [IN]        Highlighted item index
 *  arrow_flag                  [IN]        Arrow on buttom bar
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory217Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 num_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        Cat213DrawMenuItemFuncPtr draw_menuitem_callback,
        Cat213HideMenuItemFuncPtr hide_menuitem_callback,
        UI_string_type empty_message,
        S32 highlighted_item,
        U8 arrow_flag,
        U8 *history_buffer,
        S32 *category_error_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    U8 h_flag;
    S32 tool_bar_height = 0;
    U16 menuitem_per_screen = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cat213_draw_menuitem_callback = draw_menuitem_callback;
    cat213_hide_menuitem_callback = hide_menuitem_callback;

    g_cat_fmgr_get_async_item_func = get_item_func;
    g_cat_fmgr_get_async_hint_func = get_hint_func;
#ifdef __MMI_ICON_BAR_SUPPORT__	
#if defined(__MMI_FTE_SUPPORT__)
    if(MMI_TRUE == wgui_icon_bar_is_created())
    {
        tool_bar_height = MMI_ICON_BAR_HEIGHT;
    }
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif
#endif
#endif/*__MMI_ICON_BAR_SUPPORT__*/
    menuitem_per_screen = (MMI_content_height - tool_bar_height) / (MMI_MENUITEM_THICK_HEIGHT);
#if defined(__MMI_FTE_SUPPORT__)
    if((MMI_content_height - tool_bar_height) % MMI_MENUITEM_THICK_HEIGHT)
    {
        menuitem_per_screen ++;
    }
#endif
    MMI_message_string = empty_message;

    gui_block_list_animation_highlight();
    /* lock */
    gui_lock_double_buffer();
    wgui_effect_register_query_enable_draw_last_frame(wgui_cat217_query_draw_last_frame);
    gui_asyncdynamic_list_error = 0;
    *category_error_flag = 1;

    dm_add_title_id(title, title_icon);
    dm_add_softkey_id(left_softkey, right_softkey);

    wgui_async_list_create_multi_icontext_menu(
        num_of_items,
        1,
        0,
        Cat217AsyncGetItemCallback,
        Cat217AsyncGetHintCallback,
        highlighted_item,
        MMI_MENUITEM_THICK_HEIGHT,
        0,
        MMI_CATEGORY217_ID,
        history_buffer);

#ifdef __MMI_UI_TRANSPARENT_EFFECT__
    disable_fixed_icontext_list_menuitem_transparent_effect();
#endif 
    disable_fixed_list_show_empty();
#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
    gui_ssp_reset_state();
#endif /* GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN */

#ifdef __MMI_SCREEN_ROTATE__
    if (!mmi_frm_is_screen_width_height_swapped())
#endif /* __MMI_SCREEN_ROTATE__ */
    {
        MMI_fixed_icontext_menuitem.focussed_filler = current_MMI_theme->menuitem_thick_highlight_filler;
        MMI_fixed_icontext_menuitem.selected_filler = current_MMI_theme->menuitem_thick_highlight_filler;
        MMI_fixed_icontext_menuitem.focussed_without_sc_filler = current_MMI_theme->menuitem_thick_highlight_filler;//menuitem_thick_highlight_without_scroll_filler

        MMI_fixed_icontext_list_menuitem.focussed_filler = current_MMI_theme->menuitem_thick_highlight_filler;
        MMI_fixed_icontext_list_menuitem.selected_filler = current_MMI_theme->menuitem_thick_highlight_filler;
        MMI_fixed_icontext_list_menuitem.focussed_without_sc_filler = current_MMI_theme->menuitem_thick_highlight_filler;//menuitem_thick_highlight_without_scroll_filler
    }
    
#if defined(FMGR_USING_CACHE)
    if (g_fmgr_cache_p != NULL)
    {
        g_fmgr_cache_p->cache_pre_page= menuitem_per_screen;
        g_fmgr_cache_p->highlight_index = MMI_fixed_list_menu.highlighted_item;
    }
#endif /* #if defined(FMGR_USING_CACHE) */
    image_box_width = MMI_MENUITEM_THICK_HEIGHT - FMGR_UI_IMAGE_BOX_SPACING * 2;
    image_box_height = MMI_MENUITEM_THICK_HEIGHT - FMGR_UI_IMAGE_BOX_SPACING * 2;

    /* register shortcut */
    resize_fixed_icontext_list_menuitems(0, MMI_MENUITEM_THICK_HEIGHT);
	set_fixed_icontext_list_text_coordinates(0, 0, 0, 0, 0);/* disable list show loading" */

   /* if caller wish to use gui buffer as histoy */
    h_flag = set_list_menu_category_history(MMI_CATEGORY217_ID, history_buffer);

    if (h_flag)
    {
        highlighted_item = MMI_fixed_list_menu.highlighted_item;
    }

    set_asyncdynamic_pop_up_descriptions(highlighted_item);
    asyncdynamic_list_goto_item_no_redraw(highlighted_item);

    ExitCategoryFunction = ExitCategory217Screen;
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY217_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;

    /* override menu item functions */
    MMI_fixed_list_menu.item_remove_highlight_function = Cat213UnHighlightItem;
    MMI_fixed_list_menu.item_highlight_function = Cat213HighlightItem;
    MMI_fixed_list_menu.item_display_function = Cat213ShowItem;
    MMI_fixed_list_menu.item_hide_function = Cat213HideItem;

#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_KEY) || defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
    gui_list_menu_smooth_scrolling_register_stop_callback(cat213_hide_menuitem_callback);
#endif    
    dm_register_category_controlled_callback(DrawCate213CategoryControlArea);
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();
    gui_unlock_double_buffer();
    
    if (gui_asyncdynamic_list_error)
    {
        return;
    }
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    *category_error_flag = 0;
}


void ShowCategory217FmgrScreen(
           U16 title,
           U16 title_icon,
           U16 left_softkey,
           U16 left_softkey_icon,
           U16 right_softkey,
           U16 right_softkey_icon,
           S32 num_of_items,
           GetAsyncItemFuncPtr get_item_func,
           GetAsyncHintFuncPtr get_hint_func,
           CatFmgrGetFileData get_menuitem_data,
           CatFmgrHideFileData hide_menuitem_data,
           UI_string_type empty_message,
           S32 highlighted_item,
           U8 arrow_flag,
           U8 *history_buffer,
           S32 *category_error_flag)    
{
#if defined(FMGR_USING_CACHE)
    S32 number;    
    
    memset(&g_213_fmgr, 0, sizeof(g_213_fmgr));
    g_fmgr_cache_p= &(g_213_fmgr.cache);
    
    number = num_of_items/(WGUI_CAT_FMGR_CACHE_SEARCH_POINT_NUM-1);
    g_fmgr_cache_p->cache_num = 1;
    do{
        g_fmgr_cache_p->cache_num = g_fmgr_cache_p->cache_num<<1;
    }while(number >= g_fmgr_cache_p->cache_num);
    
#endif /* #if defined(FMGR_USING_CACHE) */
    
    g_fmgr_struct_p = &(g_213_fmgr.fmgr_struct);
    g_fmgr_struct_p->fmgr_style = MMI_FMGR_GUI_LIST_STYLE;
    
    wgui_cat_fmgr_get_menuitem = get_menuitem_data;
    wgui_cat_fmgr_hide_menuitem = hide_menuitem_data;
    
    ShowCategory217Screen(
        title,
        title_icon,
        left_softkey,
        left_softkey_icon,
        right_softkey,
        right_softkey_icon,
        num_of_items,
        get_item_func,
        get_hint_func,
        wgui_cat213_fmgr_draw_menuitem,
        wgui_cat213_fmgr_hide_menuitem,
        empty_message,
        highlighted_item,
        arrow_flag,
        history_buffer,
        category_error_flag);
    
#if defined(FMGR_USING_CACHE)
    if (g_fmgr_cache_p->cur_decode_p == NULL && num_of_items != 0)
    {
        g_fmgr_cache_p->first_displayed_item = MMI_fixed_list_menu.first_displayed_item;
        wgui_cat_fmgr_cache_list_decoding_next(g_fmgr_cache_p->first_displayed_item);
    }
#endif /* #if defined(FMGR_USING_CACHE) */
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory217Screen
 * DESCRIPTION
 *  Exit category 217 screen async dynamic list of category213
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategory217Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    reset_dynamic_list();
    reset_pop_up_descriptions();
    reset_fixed_list_show_empty();


    //MMI_fixed_list_menu.pre_display_function = NULL;

#if defined(FMGR_USING_CACHE)
    if (g_fmgr_cache_p != NULL)
    {
        wgui_cat_fmgr_cache_free_all();
        g_fmgr_cache_p->cur_decode_p = NULL;
        g_fmgr_cache_p = NULL; 
    }
#endif /* #if defined(FMGR_USING_CACHE) */
#if defined(__MMI_FTE_SUPPORT__)
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif
#endif
    gui_unblock_list_animation_highlight();
 
#ifdef __MMI_UI_TRANSPARENT_EFFECT__
    enable_fixed_icontext_list_menuitem_transparent_effect();
#endif 

    if (cat213_hide_menuitem_callback != NULL)
    {
        cat213_hide_menuitem_callback();
    }

    cat213_draw_menuitem_callback = NULL;
    cat213_hide_menuitem_callback = NULL;
    
    g_cat_fmgr_get_async_item_func = NULL;
    g_cat_fmgr_get_async_hint_func = NULL;
    wgui_effect_register_query_enable_draw_last_frame(NULL);
}


/*****************************************************************************
* FUNCTION
*  Cat217AsyncGetItemCallback
* DESCRIPTION
*  Get category 217 get item callback function
* PARAMETERS
*  item_idx            [IN]        
*  str_buff            [IN]        
*  img_buff_p          [?]         
*  str_img_mask        [IN]        
* RETURNS
*  void
*****************************************************************************/
static S32 Cat217AsyncGetItemCallback(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_cat_fmgr_get_async_item_func == NULL)
    {
        ret = data_size;
    }
    else
    {
        ret = g_cat_fmgr_get_async_item_func(start_index, menu_data, data_size);
    }
    for(i = 0; i < data_size; i++)
    {
        menu_data[i].item_list[0] = NULL;
        menu_data[i].image_list[0] = NULL;
    }
  
    return ret;
}
#endif /*__MMI_CAT217_CAT213_SUPPORT_FMGR__*/

static S32 Cat219AsyncGetItemCallback(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(g_cat_fmgr_get_async_item_func == NULL)
    {
        ret = data_size;
    }
    else
    {
#ifdef __MMI_FTE_SUPPORT_SLIM__
        if(gui_screen_smooth_scrolling_by_pen())
        {
            ret = data_size;
        }
        else
#endif
        {
            ret = g_cat_fmgr_get_async_item_func(start_index, menu_data, data_size);
        }
    }
    for(i = 0; i < data_size; i++)
    {
        menu_data[i].item_list[0] = NULL;
        menu_data[i].image_list[0] = NULL;
    }

    return ret;
}
/*****************************************************************************
* FUNCTION
*  Cat217AsyncGetHintCallback
* DESCRIPTION
*  Get category 213 get hint callback function
* PARAMETERS
*  item_idx        [IN]        
*  hint_array      [?]         
* RETURNS
*  void
*****************************************************************************/
static S32 Cat217AsyncGetHintCallback(S32 start_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* do nothing */
    if(g_cat_fmgr_get_async_hint_func)
        ret = g_cat_fmgr_get_async_hint_func(start_index, hint_array);
    else
        ret = 0;
    return ret;
}

#ifdef __MMI_CAT217_CAT213_SUPPORT_FMGR__

/*****************************************************************************
 * FUNCTION
 *  ShowCategory213Screen
 * DESCRIPTION
 *  Show category 223 screen.
 * PARAMETERS
 *  title                       [IN]        Title string id
 *  title_icon                  [IN]        Title image id
 *  left_softkey                [IN]        Lsk string id
 *  left_softkey_icon           [IN]        Lsk image id
 *  right_softkey               [IN]        Rsk string id
 *  right_softkey_icon          [IN]        Rsk image id
 *  num_of_items                [IN]        How many items
 *  draw_menuitem_callback      [IN]        Callback function to draw menuitem
 *  hide_menuitem_callback      [IN]        Callback function to hide menuitem
 *  highlighted_item            [IN]        Highlighted item index
 *  arrow_flag                  [IN]        Arrow on buttom bar
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory213Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 num_of_items,
        Cat213DrawMenuItemFuncPtr draw_menuitem_callback,
        Cat213HideMenuItemFuncPtr hide_menuitem_callback,
        S32 highlighted_item,
        U8 arrow_flag,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    U8 h_flag;
    U16 menuitem_per_screen = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cat213_draw_menuitem_callback = draw_menuitem_callback;
    cat213_hide_menuitem_callback = hide_menuitem_callback;

    menuitem_per_screen = MMI_content_height / (MMI_MENUITEM_THICK_HEIGHT - 1);
    MMI_message_string = (UI_string_type)NULL;
    gui_block_list_animation_highlight();
    /* lock */
    gui_lock_double_buffer();
    dm_add_title_id(title, title_icon);
    dm_add_softkey_id(left_softkey, right_softkey);

    wgui_dynamic_list_create_icontext_menu(
        num_of_items,
        Cat213GetItemCallback,
        Cat213GetHintCallback,
        WGUI_LIST_INVALID_HIGHLIGHT,
        MMI_FALSE,
        UI_dummy_function,
        0,
        0,
        NULL);

    disable_fixed_list_show_empty();
#ifdef __MMI_UI_TRANSPARENT_EFFECT__
    disable_fixed_icontext_menuitem_transparent_effect();
#endif 

#ifdef __MMI_SCREEN_ROTATE__
     if (!mmi_frm_is_screen_width_height_swapped())
#endif /* __MMI_SCREEN_ROTATE__ */
    {
        MMI_fixed_icontext_menuitem.focussed_filler = current_MMI_theme->menuitem_thick_highlight_filler;
        MMI_fixed_icontext_menuitem.selected_filler = current_MMI_theme->menuitem_thick_highlight_filler;
        MMI_fixed_icontext_menuitem.focussed_without_sc_filler = current_MMI_theme->menuitem_thick_highlight_filler;//menuitem_thick_highlight_without_scroll_filler
    }
    
#if defined(FMGR_USING_CACHE)
    if (g_fmgr_cache_p != NULL)
    {
        g_fmgr_cache_p->cache_pre_page= menuitem_per_screen;
        g_fmgr_cache_p->highlight_index = highlighted_item;
    }
#endif /* #if defined(FMGR_USING_CACHE) */
    image_box_width = MMI_MENUITEM_THICK_HEIGHT - FMGR_UI_IMAGE_BOX_SPACING * 2;
    image_box_height = MMI_MENUITEM_THICK_HEIGHT - FMGR_UI_IMAGE_BOX_SPACING * 2;

    /* register shortcut */
    resize_fixed_icontext_menuitems(0, MMI_MENUITEM_THICK_HEIGHT);

   /* if caller wish to use gui buffer as histoy */
    h_flag = set_list_menu_category_history(MMI_CATEGORY213_ID, history_buffer);

    if (h_flag)
    {
        highlighted_item = MMI_fixed_list_menu.highlighted_item;
    }

    set_dynamic_pop_up_descriptions(highlighted_item);

    dynamic_list_goto_item_no_redraw(highlighted_item);

    gui_unlock_double_buffer();

    ExitCategoryFunction = ExitCategory213Screen;
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY213_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;

    /* override menu item functions */
    MMI_fixed_list_menu.item_remove_highlight_function = Cat213UnHighlightItem;
    MMI_fixed_list_menu.item_highlight_function = Cat213HighlightItem;
    MMI_fixed_list_menu.item_display_function = Cat213ShowItem;
    MMI_fixed_list_menu.item_hide_function = Cat213HideItem;

#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_KEY) || defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
    gui_list_menu_smooth_scrolling_register_stop_callback(cat213_hide_menuitem_callback);
#endif    
    dm_register_category_controlled_callback(DrawCate213CategoryControlArea);
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory213Screen
 * DESCRIPTION
 *  Exit category 213 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategory213Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_dynamic_list();
    reset_pop_up_descriptions();
    reset_fixed_list_show_empty();


    //MMI_fixed_list_menu.pre_display_function = NULL;

    if (cat213_hide_menuitem_callback != NULL)
    {
        cat213_hide_menuitem_callback();
    }
#if defined(FMGR_USING_CACHE)
    if (g_fmgr_cache_p != NULL)
    {
        wgui_cat_fmgr_cache_free_all();
        g_fmgr_cache_p->cur_decode_p = NULL;
        g_fmgr_cache_p = NULL; 
    }
#endif /* #if defined(FMGR_USING_CACHE) */

    gui_unblock_list_animation_highlight();
 
#ifdef __MMI_UI_TRANSPARENT_EFFECT__
    enable_fixed_icontext_menuitem_transparent_effect();
#endif 

    cat213_draw_menuitem_callback = NULL;
    cat213_hide_menuitem_callback = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  Cat213GetItemCallback
 * DESCRIPTION
 *  Get category 213 get item callback function
 * PARAMETERS
 *  item_idx            [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static pBOOL Cat213GetItemCallback(S32 item_idx, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((PS8) str_buff, (PS8) L"");
    *img_buff_p = NULL;;

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  Cat213GetHintCallback
 * DESCRIPTION
 *  Get category 213 get hint callback function
 * PARAMETERS
 *  item_idx        [IN]        
 *  hint_array      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static S32 Cat213GetHintCallback(S32 item_idx, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* do nothing */
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  Cat213HighlightItem
 * DESCRIPTION
 *  Category 213 menu item highlight function
 * PARAMETERS
 *  item                   [IN]     private menu item object
 *  common_item_data       [IN]     common menu item object
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat213HighlightItem(void *item, void *common_item_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_fixed_list_get_style() == GUI_MENU_TYPE_ASYNCDYNAMIC)
    {
        gui_highlight_fixed_icontext_list_menuitem(item, common_item_data);
    }
    else
    {
        gui_highlight_fixed_icontext_menuitem(item, common_item_data);
    }

#if defined(FMGR_USING_CACHE)
    if (g_fmgr_cache_p != NULL)
    {
        g_fmgr_cache_p->highlight_index = MMI_fixed_list_menu.highlighted_item;
    }
#endif /* #if defined(FMGR_USING_CACHE) */
    /* stop async image decoding */
    if (cat213_hide_menuitem_callback != NULL)
    {
        cat213_hide_menuitem_callback();
    }
}


/*****************************************************************************
 * FUNCTION
 *  Cat213UnHighlightItem
 * DESCRIPTION
 *  Category 213 menu item remove highlight function
 * PARAMETERS
 *  item                   [IN]     private menu item object
 *  common_item_data       [IN]     common menu item object
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat213UnHighlightItem(void *item, void *common_item_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_fixed_list_get_style() == GUI_MENU_TYPE_ASYNCDYNAMIC)
    {
        gui_remove_highlight_fixed_icontext_list_menuitem(item, common_item_data);
    }
    else
    {
        gui_remove_highlight_fixed_icontext_menuitem(item, common_item_data);
    }

    /* stop async image decoding */
    if (cat213_hide_menuitem_callback != NULL)
    {
        cat213_hide_menuitem_callback();
    }
}

static void Cat213HideItem(void *item, void *common_item_data, S32 x, S32 y)
{
    BOOL is_hilighted;
    gdi_color bg_color;

    /* stop scroll text */
    gui_scrolling_text_stop(&fmgr_cat_context.scroll_text);

    /* End the decoding item, but not free it, just set the flag to NONE */
#if defined(FMGR_USING_CACHE)
    if (g_fmgr_cache_p != NULL)
    {
        wgui_fmgr_cache_stop_decoder();
    }
#endif /* #if defined(FMGR_USING_CACHE) */

    /* Call org func */
#ifndef __MMI_UI_MENU_SLIM__
    if (wgui_fixed_list_get_style() != GUI_MENU_TYPE_ASYNCDYNAMIC)
    {
        gui_hide_fixed_icontext_menuitem(item, common_item_data, x, y);
    }   
#endif 
    if (MMI_fixed_list_menu.current_displayed_item == -1)
    {
        is_hilighted = TRUE;
    }
    else
    {
        is_hilighted = FALSE;
    }
    
    bg_color = wgui_fmgr_get_bg_color(is_hilighted, (U16)g_fmgr_struct_p->fmgr_style);
    
    wgui_fmgr_redraw_image_background(                
        is_hilighted, 
        (U16)g_fmgr_struct_p->fmgr_style,
        bg_color,
        x,
        y,
        x + image_box_width - 1,
        y + image_box_height - 1); 

    if (wgui_cat_fmgr_hide_menuitem != NULL)
    {
        wgui_cat_fmgr_hide_menuitem();    
    }
}

/*****************************************************************************
 * FUNCTION
 *  Cat213ShowItem
 * DESCRIPTION
 *  Category 213 menu item show function
 * PARAMETERS
 *  item                   [IN]     private menu item object
 *  common_item_data       [IN]     common menu item object
 *  x                      [IN]     x
 *  y                      [IN]     y
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat213ShowItem(void *item, void *common_item_data, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL is_hilighted;
    S32 item_width, item_height;
    U32 list_flags;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* show the highlight */
    if (wgui_fixed_list_get_style() == GUI_MENU_TYPE_ASYNCDYNAMIC)
    {
        fixed_icontext_list_menuitem_type *async_mi;
        
        gui_show_fixed_icontext_list_menuitem(item, common_item_data, x, y);
        async_mi = (fixed_icontext_list_menuitem_type*) item;
        list_flags = async_mi->flags;
    }
    else
    {    
        fixed_icontext_menuitem_type *mi;
        
        ((fixed_icontext_menuitem_type*)item)->item_text[0] = '\0';
        ((fixed_icontext_menuitem_type*)item)->item_text[1] = '\0';
        gui_show_fixed_icontext_menuitem(item, common_item_data, x, y);
        if (MMI_fixed_list_menu.current_displayed_item == -1)
        {
            mi = get_dynamic_item_from_buffer(MMI_fixed_list_menu.highlighted_item);
        }
        else
        {
            mi = get_dynamic_item_from_buffer(MMI_fixed_list_menu.current_displayed_item);
        }
        list_flags = mi->flags;
    }
 
    MMI_fixed_list_menu.item_measure_function(
                            item,
                            common_item_data,
                            &item_width,
                            &item_height);

    if ((MMI_fixed_list_menu.current_displayed_item == -1) &&
        (list_flags & UI_MENUITEM_STATE_FOCUSSED))    
    {
        is_hilighted = TRUE;
    }
    else
    {
        is_hilighted = FALSE;
    }

    /* 
     * Call cat213 owner draw menu item. The draw callback will blt, so we must lock frame buffer here;
     * moreover, the menu will do the blt.
     */
#ifdef __MMI_FTE_SUPPORT__
    item_width = item_width - current_MMI_theme->scrollbar_size;
#endif
    if (cat213_draw_menuitem_callback != NULL)
    {
        gdi_layer_lock_frame_buffer();        
        if (MMI_fixed_list_menu.current_displayed_item == -1)
        {
            cat213_draw_menuitem_callback(
                MMI_fixed_list_menu.highlighted_item,
                is_hilighted,
                x,
                y,
                x + item_width - 2,
                y + item_height - 1);
        }
        else
        {
            cat213_draw_menuitem_callback(
                MMI_fixed_list_menu.current_displayed_item,
                is_hilighted,
                x,
                y,
                x + item_width - 2,
                y + item_height - 1);
        }
        gdi_layer_unlock_frame_buffer();
    }

#if defined(FMGR_USING_CACHE)
    wgui_cat_fmgr_start_next();
#endif /* #if defined(FMGR_USING_CACHE) */
}

#endif /*__MMI_CAT217_CAT213_SUPPORT_FMGR__*/
/*****************************************************************************
 * FUNCTION
 *  wgui_cat214_fmgr_draw_matrix_highlight
 * DESCRIPTION
 *  Category 214 draw matrix item highlight
 * PARAMETERS
 *  x1                      [IN]     rect x1
 *  y1                      [IN]     rect y1
 *  x2                      [IN]     rect x2
 *  y2                      [IN]     rect y2
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat214_fmgr_draw_matrix_highlight(
        S32 x1, 
        S32 y1, 
        S32 x2, 
        S32 y2)
{
        /* Draw the line */
        
        gdi_color box_hilight_color;
        gdi_color box_hilight_color_2nd;
        box_hilight_color = gdi_act_color_from_rgb(255, 142, 229, 255);  
       // box_hilight_color_2nd = gdi_act_color_from_rgb(255, 184, 234, 255);  
        box_hilight_color_2nd = gdi_act_color_from_rgb(255, 142, 229, 255);  
        
        /* draw frame */
        gdi_draw_rect(
            x1,
            y1,
            x2,
            y2,
            box_hilight_color);
        gdi_draw_rect(
            x1+1,
            y1+1,
            x2-1,
            y2-1,
            box_hilight_color_2nd);
}


#if defined(FMGR_USING_CACHE)
/*****************************************************************************
 * FUNCTION
 *  wgui_cat_fmgr_is_cached
 * DESCRIPTION
 *  check file manager is cached by index
 * PARAMETERS
 *  idx              [IN]     Index to test
 *  node_p           [IN]     Cache pointer if cached
 * RETURNS
 *  MMI_BOOL                  If it is cached
 *****************************************************************************/
static MMI_BOOL wgui_cat_fmgr_is_cached(S32 idx, wgui_cat_fmgr_cache_node **node_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_cat_fmgr_cache_node *current_node_p;
    U32 cache_slot;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmgr_cache_p == NULL)
    {
        return MMI_FALSE;
    }
    /* calculate the slot */
    cache_slot = idx/g_fmgr_cache_p->cache_num;

    if ((U32)idx < (((cache_slot*2+1)*g_fmgr_cache_p->cache_num)>>1) )
    {
        /* Search link list from start */
        current_node_p = g_fmgr_cache_p->cache_search_list[cache_slot].front_p;
        if (current_node_p != NULL)
        {
            if (current_node_p->index > idx)
            {
                /* if first one is bigger than new idx, the idx must not in the link list*/
                current_node_p = NULL;
            }
            else
            {
                while (current_node_p->index < idx)
                {
                    current_node_p = current_node_p->next;
                    if (current_node_p == NULL)
                    {
                        break;
                    }
                }
            }
        }
    }
    else
    {
        /* Search link list from end */
        current_node_p = g_fmgr_cache_p->cache_search_list[cache_slot].rear_p;
        if (current_node_p != NULL)
        {
            if (current_node_p->index < idx)
            {
                /* if last one is smaller than new idx, the idx must not in the link list*/
                current_node_p = NULL;
            }
            else
            {
                while (current_node_p->index > idx)
                {
                    current_node_p = current_node_p->prev;
                    if (current_node_p == NULL)
                    {
                        break;
                    }
                }
            }
        }
    }

    *node_p = current_node_p;

    if (current_node_p == NULL)
    {
        return MMI_FALSE;
    }

    if (current_node_p->index == idx && current_node_p->state == WGUI_CAT_FMGR_CACHED)
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
 *  wgui_fmgr_cache_stop_decoder
 * DESCRIPTION
 *  Filemanager stop cache decoder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_fmgr_cache_stop_decoder(void)
{
    wgui_cat_fmgr_cache_node *current_node_p;
    U32 cache_slot;
    
    if (g_fmgr_cache_p == NULL)
    {
        return;
    }
    
    current_node_p = g_fmgr_cache_p->cur_decode_p;
    if (current_node_p != NULL)
    {
        if (current_node_p->state == WGUI_CAT_FMGR_CACHING)
        {
            /* Stop decoder */
            gdi_image_decoder_stop(g_fmgr_cache_p->decoding_handle);
            current_node_p->state = WGUI_CAT_FMGR_CACHENONE;

            /* Free decoding layer first */
            if (g_fmgr_cache_p->decoding_layer != NULL)
            {
                gdi_layer_free(g_fmgr_cache_p->decoding_layer);
                g_fmgr_cache_p->decoding_layer = NULL;
            }

            /* Free decoding layer first */
            if (g_fmgr_cache_p->decoding_layer != NULL)
            {
                gdi_layer_free(g_fmgr_cache_p->decoding_layer);
                g_fmgr_cache_p->decoding_layer = NULL;
            }

            /* Remove it from link list */
            if (current_node_p->next == NULL)
            {
                cache_slot = current_node_p->index/g_fmgr_cache_p->cache_num;
                if (current_node_p->prev == NULL)
                {
                    /* It's the only item in this slot */
                    g_fmgr_cache_p->cache_search_list[cache_slot].front_p = NULL;
                    g_fmgr_cache_p->cache_search_list[cache_slot].rear_p = NULL;
                }
                else
                {
                    /* It's the last item */  
                    g_fmgr_cache_p->cache_search_list[cache_slot].rear_p = current_node_p->prev;
                    current_node_p->prev->next = NULL;
                    current_node_p->prev = NULL;
                }
            }
            else if (current_node_p->prev == NULL)
            {
                /* It's the first item */
                cache_slot = current_node_p->index/g_fmgr_cache_p->cache_num;
                g_fmgr_cache_p->cache_search_list[cache_slot].front_p = current_node_p->next;
                current_node_p->next->prev = NULL;
                current_node_p->next = NULL;                
            }
            else
            {
                current_node_p->prev->next = current_node_p->next;
                current_node_p->next->prev = current_node_p->prev;
                current_node_p->next = NULL;
                current_node_p->prev = NULL;
            }
        }
    }
    StopTimer(FMGR_DELAY_DECODE_0);

}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat_fmgr_cache_list_decoding_next
 * DESCRIPTION
 *  Filemanager Decoding next item by cache order.
 * PARAMETERS
 *  idx                     [IN] Index to cache
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat_fmgr_cache_list_decoding_next(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_fmgr_menuitem_data_struct menuitem_data;
    wgui_cat_fmgr_cache_node *current_node_p = NULL;
    MMI_BOOL is_next_directly = MMI_TRUE;
	MMI_BOOL is_displayable = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmgr_cache_p == NULL)
    {
        return;
    }  

    if (idx >= MMI_fixed_list_menu.n_items || idx < 0)
    {
        return;
    }
#ifdef __MMI_CAT216_CAT212_SUPPORT_FMGR__
    if (g_fmgr_struct_p->fmgr_style == MMI_FMGR_GUI_INFO_STYLE || 
        g_fmgr_struct_p->fmgr_style == MMI_FMGR_GUI_HILITE_STYLE )
    {
        wgui_fmgr_info_struct fmgr_info;

        memset(&fmgr_info, 0, sizeof(wgui_fmgr_info_struct));
        wgui_cat212_fmgr_get_info_ptr(idx, &fmgr_info);
        menuitem_data.is_show_thumb = fmgr_info.is_show_thumb;
        menuitem_data.file_icon_ptr = fmgr_info.file_icon_ptr;
    }
    else
#endif
    {
        BOOL is_hilighted;

        /* Get item idx from application */
        is_hilighted = (idx == g_fmgr_cache_p->highlight_index)?TRUE:FALSE;
        wgui_cat_fmgr_get_menuitem(idx, is_hilighted, &menuitem_data);
    }

    g_fmgr_cache_p->decoding_index = idx;
#if defined(FMGR_USING_CACHE) 
    if(wgui_cat21x_get_displayable != NULL)
    {
        is_displayable = wgui_cat21x_get_displayable(idx);
    }
#endif
    if (menuitem_data.is_show_thumb && is_displayable)
    {
        /* create jpeg decoder */
        if (g_fmgr_cache_p->decoder_create == 0)
        {
            /* max image size is 100x100 */
            gdi_image_decoder_create(100, 100, wgui_cat_fmgr_decode_result_hdlr);
            g_fmgr_cache_p->decoder_create = 1;
        }
        

        if (!wgui_cat_fmgr_is_cached(idx, &current_node_p))
        {
            if (g_fmgr_cache_p->cur_decode_p == NULL || g_fmgr_cache_p->cur_decode_p->state == WGUI_CAT_FMGR_CACHENONE || g_fmgr_cache_p->cur_decode_p->state == WGUI_CAT_FMGR_CACHEERROR)
            {
                /* Pass node to make search faster */
                wgui_cat_fmgr_cache_list_add(idx, menuitem_data.file_icon_ptr, current_node_p);
                if (g_fmgr_cache_p->cur_decode_p != NULL)
                {
                    /* Start decoding image */
                    StartNonAlignTimer(FMGR_DELAY_DECODE_0, WGUI_CAT_FMGR_UI_DELAY_DECODE_NEXT_DUR, wgui_cat_fmgr_delay_decode_timer);
                }
                /* If cur_decode_p is NULL, do not need to continue cache next */
                is_next_directly = MMI_FALSE;
            }
        }
    }
    else
    {
        if (g_fmgr_cache_p->cur_decode_p != NULL)
        {
            if (g_fmgr_cache_p->cur_decode_p->state == WGUI_CAT_FMGR_CACHENONE)
            {
                g_fmgr_cache_p->cur_decode_p->state = WGUI_CAT_FMGR_CACHEERROR;
            }
        }        
    }

    if (is_next_directly)
    {
        StartNonAlignTimer(FMGR_DELAY_DECODE_0, WGUI_CAT_FMGR_UI_DELAY_DECODE_NEXT_DUR, wgui_cat_fmgr_start_next);
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_cache_draw_cached_img
 * DESCRIPTION
 *  Filemanager draw a cached image to the layer and blt to screen.
 * PARAMETERS
 *  node_p              [IN]    Cache node of the image
 *  x                   [IN]    x position to draw
 *  y                   [IN]    y position to draw
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat_cache_draw_cached_img(wgui_cat_fmgr_cache_node *node_p, S32 x, S32 y)
{
    S32 box_width = image_box_width;
    S32 box_height = image_box_height;
    
    gdi_rect_struct dest_clip;
    gdi_handle act_layer;
    
    S32 image_width,image_height;
    S32 draw_pos_x, draw_pos_y;
	S32 temp_y1;

    gdi_color box_hilight_color;

    if (g_fmgr_cache_p == NULL)
    {
        return;
    }  
    gdi_layer_get_active(&act_layer);

    image_width = node_p->cache_width;
    image_height = node_p->cache_height;

    if (image_width < box_width)
    {
        draw_pos_x = x + ((box_width-image_width)>>1);
    }
    else
    {
        draw_pos_x = x;
    }

    if (image_height < box_height)
    {
        draw_pos_y = y + ((box_height-image_height)>>1);
    }
    else
    {
        draw_pos_y = y;
    }

    dest_clip.x1 = draw_pos_x;
    dest_clip.y1 = draw_pos_y;
    dest_clip.x2 = draw_pos_x + image_width - 1;
    dest_clip.y2 = draw_pos_y + image_height - 1;

	temp_y1 = dest_clip.y1;
    if(g_fmgr_struct_p->fmgr_style == MMI_FMGR_GUI_LIST_STYLE)
    {
#if defined(__MMI_UI_LIST_SCROLL_BY_PIXEL__)
		S32 layer_w, layer_h;
		gdi_layer_get_dimension(&layer_w, &layer_h);
	    if((layer_h == UI_device_height) && (node_p->index == MMI_fixed_list_menu.first_displayed_item) && (MMI_fixed_list_menu.first_displayed_offset > 0))		
		{
			S32 x1, y1, x2, y2;
			if(temp_y1 < MMI_fixed_list_menu.y)
			{
				temp_y1 = MMI_fixed_list_menu.y;
			}
			gui_get_clip(&x1, &y1, &x2, &y2);
			temp_y1 = temp_y1 > y1 ? temp_y1 : y1;
			if(dest_clip.y2 < MMI_fixed_list_menu.y)
			{
				return;

			}
		}

#endif
        if(dest_clip.y2 > MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1)
        {
            dest_clip.y2 = MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1;
        }
    }
    if(g_fmgr_struct_p->fmgr_style == MMI_FMGR_GUI_MATRIX_STYLE)
    {
        if(dest_clip.y2 > MMI_fixed_matrix_menu.y + MMI_fixed_matrix_menu.height - 1)
        {
            dest_clip.y2 = MMI_fixed_matrix_menu.y + MMI_fixed_matrix_menu.height - 1;
        }
	 {
	    S32 bottom_h = MMI_BUTTON_BAR_HEIGHT;
#ifdef __MMI_ICON_BAR_SUPPORT__		
	    #ifdef __MMI_FTE_SUPPORT__
    		if(MMI_TRUE == wgui_icon_bar_is_created())
    		{
        		bottom_h += MMI_ICON_BAR_HEIGHT;
    		}
           #endif
#endif /*__MMI_ICON_BAR_SUPPORT__*/
           if(dest_clip.y2 > UI_device_height - bottom_h - 1)
           {
              dest_clip.y2 = UI_device_height - bottom_h - 1;
            }
	 }
    }
    /* For matrix */
    gd_bitblt[gdi_act_layer->cf](
        gdi_act_layer->buf_ptr,
        gdi_act_layer->width, gdi_act_layer->height,
        dest_clip.x1, dest_clip.y1, dest_clip.x2, dest_clip.y2,
        node_p->buffer,
        box_width, box_height,
        0, 0, box_width - 1, box_height -1 ,
        dest_clip.x1, temp_y1, dest_clip.x2, dest_clip.y2,
        0x01FFFFFF, 0x01FFFFFF);            

    /* Draw the line */
    box_hilight_color = gdi_act_color_from_rgb(0,0, 0, 0);     
    
    /* draw frame */
	gui_push_clip();
	gui_set_clip(dest_clip.x1, temp_y1, dest_clip.x2, dest_clip.y2);
    gdi_draw_rect(
        dest_clip.x1,
        dest_clip.y1,
        dest_clip.x2,
        dest_clip.y2,
        box_hilight_color);
	gui_pop_clip();

}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_fmgr_decode_result_hdlr
 * DESCRIPTION
 *  Filemanager decode callback from GDI.
 * PARAMETERS
 *  decode_result       [IN]    result code of decode
 *  handle              [IN]    GDI decode handle
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat_fmgr_decode_result_hdlr(GDI_RESULT decode_result, gdi_handle handle)
{

    wgui_cat_fmgr_cache_node *decode_node_p;

    if (g_fmgr_cache_p == NULL)
    {
        return;
    }

    decode_node_p = g_fmgr_cache_p->cur_decode_p;

    /* Free decoding layer first */
    if (g_fmgr_cache_p->decoding_layer != NULL)
    {
        gdi_layer_free(g_fmgr_cache_p->decoding_layer);
        g_fmgr_cache_p->decoding_layer = NULL;
    }
    
    /* if decoder is deinited, ignore the decode result hdlr */
    if (g_fmgr_cache_p->decoder_create == 0)
    {
        return;
    }

    if (decode_result == GDI_JPEG_SUCCEED)
    {
        if (!((g_fmgr_struct_p->fmgr_style == MMI_FMGR_GUI_INFO_STYLE || 
               g_fmgr_struct_p->fmgr_style == MMI_FMGR_GUI_HILITE_STYLE ) && 
            (decode_node_p->index != g_fmgr_cache_p->highlight_index)))
        {
            /* if info style, only draw highlight */
            if ((decode_node_p->index >= g_fmgr_cache_p->first_displayed_item) && 
                (decode_node_p->index < g_fmgr_cache_p->first_displayed_item + g_fmgr_cache_p->cache_pre_page ))
            {
                /* if index in on the current page, draw the cached image */
                gdi_color bg_color;
                BOOL is_hilighted;
                S32 x1, y1, x2, y2;
 
                if (g_fmgr_struct_p->fmgr_style == MMI_FMGR_GUI_INFO_STYLE)
                {
                    x1 = g_fmgr_cache_p->cache_pos[0].x;
                    y1 = g_fmgr_cache_p->cache_pos[0].y;
                }            
                else
                {
                    x1 = g_fmgr_cache_p->cache_pos[decode_node_p->index - g_fmgr_cache_p->first_displayed_item].x;
                    y1 = g_fmgr_cache_p->cache_pos[decode_node_p->index - g_fmgr_cache_p->first_displayed_item].y;
                }
                x2 = x1 + image_box_width - 1;
                y2 = y1 + image_box_height - 1;

                is_hilighted = (decode_node_p->index == g_fmgr_cache_p->highlight_index)?TRUE:FALSE;
                gui_push_clip();
                gui_reset_clip();

                /* Draw the highlight mark first */
                if (g_cat214_highlight_layer == WGUI_CAT214_HIGHLIGHT_LAYER_BOTTOM && 
                    is_hilighted && 
                    g_fmgr_struct_p->fmgr_style == MMI_FMGR_GUI_MATRIX_STYLE)
                {
                    wgui_cat214_fmgr_draw_matrix_highlight(
                        x1 - WGUI_CAT_FMGR_MATRIX_BORDER_PIXEL, 
                        y1 - WGUI_CAT_FMGR_MATRIX_BORDER_PIXEL, 
                        x2 + WGUI_CAT_FMGR_MATRIX_BORDER_PIXEL, 
                        y2 + WGUI_CAT_FMGR_MATRIX_BORDER_PIXEL);
                }
#ifdef __MMI_CAT217_CAT213_SUPPORT_FMGR__
                if(g_fmgr_struct_p->fmgr_style == MMI_FMGR_GUI_LIST_STYLE)
                {
                    if(y2 > MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1)
                    {
                        y2 = MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1;
                    }
                }
                if(g_fmgr_struct_p->fmgr_style == MMI_FMGR_GUI_MATRIX_STYLE)
		        {
      	    		S32 bottom_h = MMI_BUTTON_BAR_HEIGHT;
#ifdef __MMI_ICON_BAR_SUPPORT__					
	   		 #ifdef __MMI_FTE_SUPPORT__
    			    if(MMI_TRUE == wgui_icon_bar_is_created())
    			    {
        			    bottom_h += MMI_ICON_BAR_HEIGHT;
    			    }
             #endif
#endif /*__MMI_ICON_BAR_SUPPORT__*/			 
           		    if(y2 > UI_device_height - bottom_h - 1)
           		    {
             			 y2 = UI_device_height - bottom_h - 1;
            		}
                   #if defined(FMGR_USING_CACHE)
                    if(wgui_cat219_decode_done_hdlr != NULL)
                        wgui_cat219_decode_done_hdlr(decode_node_p->index);
                    #endif
		         }
#endif 
                /* Draw the background of image*/
                bg_color = wgui_fmgr_get_bg_color(is_hilighted, (U16)g_fmgr_struct_p->fmgr_style);
                wgui_fmgr_redraw_image_background(
                    is_hilighted,
                    (U16)g_fmgr_struct_p->fmgr_style,
                    bg_color, 
                    x1, y1, x2, y2);

#if defined(__MMI_UI_LIST_SLIDE_EFFECT__)
                    if (g_slide_effect->state == GUI_EFFECT_STATE_RUNNING
#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_KEY)
                        || gui_in_ssk
#endif
                        )
                    {
                        if (g_fmgr_struct_p->fmgr_style == MMI_FMGR_GUI_LIST_STYLE || 
                            g_fmgr_struct_p->fmgr_style == MMI_FMGR_GUI_HILITE_STYLE)
                        {
                            bg_color = wgui_fmgr_get_bg_color(FALSE, (U16)g_fmgr_struct_p->fmgr_style);
                            gdi_draw_solid_rect(x1, y1, x2, y2, bg_color);
                        }
                    }
#endif /* __MMI_UI_LIST_SLIDE_EFFECT__ */


                wgui_cat_cache_draw_cached_img(decode_node_p, x1, y1);

                /* Draw the highlight mark last */
                if (g_cat214_highlight_layer == WGUI_CAT214_HIGHLIGHT_LAYER_TOP && 
                    is_hilighted &&
                    g_fmgr_struct_p->fmgr_style == MMI_FMGR_GUI_MATRIX_STYLE)
                {
                    wgui_cat214_fmgr_draw_matrix_highlight(
                        x1 - WGUI_CAT_FMGR_MATRIX_BORDER_PIXEL, 
                        y1 - WGUI_CAT_FMGR_MATRIX_BORDER_PIXEL, 
                        x2 + WGUI_CAT_FMGR_MATRIX_BORDER_PIXEL, 
                        y2 + WGUI_CAT_FMGR_MATRIX_BORDER_PIXEL);
                }
#ifdef __MMI_CAT216_CAT212_SUPPORT_FMGR__
                /* If two line hilite style, maybe need to draw checkbox */
                if (g_fmgr_struct_p->fmgr_style == MMI_FMGR_GUI_HILITE_STYLE)
                {
                    PU8 checkbox_img;
                    S32 iwidth, iheight;
                    S32 checkbox_x, checkbox_y;                    

                    if (MMI_fixed_icontext_list_menuitem.ext_flags & UI_MENUITEM_EXT_SHOW_ICONTEXT_CHECKBOX)
                    {
                        MMI_fixed_icontext_list_menuitem.checkbox_get_image_callback(MMI_fixed_list_menu.highlighted_item, &checkbox_img);
                        gui_measure_image(checkbox_img, &iwidth, &iheight);
                        checkbox_x = x1 + MMI_fixed_icontext_list_menuitem.checkbox_x - FMGR_UI_IMAGE_BOX_SPACING;
                        if (MMI_fixed_icontext_list_menuitem.checkbox_y == 0)
                        {   /* vertical center align */
                            checkbox_y = y1 + ((MMI_fixed_icontext_list_menuitem.height - iheight) >> 1) - FMGR_UI_IMAGE_BOX_SPACING;
                        }    
                        else
                        {
                            checkbox_y = y1 + MMI_fixed_icontext_list_menuitem.checkbox_y - FMGR_UI_IMAGE_BOX_SPACING;
                        }

                        gdi_image_draw(checkbox_x, checkbox_y, checkbox_img); /* Need to sync with List */
                    }
                }
#endif
                gui_pop_clip();
#ifdef __MMI_CAT216_CAT212_SUPPORT_FMGR__
                if (g_fmgr_struct_p->fmgr_style == MMI_FMGR_GUI_HILITE_STYLE)
                {
                    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);   
                }
                else
#endif
                {
                     gdi_layer_blt_previous(
                        x1 - WGUI_CAT_FMGR_MATRIX_BORDER_PIXEL, 
                        y1 - WGUI_CAT_FMGR_MATRIX_BORDER_PIXEL, 
                        x2 + WGUI_CAT_FMGR_MATRIX_BORDER_PIXEL, 
                        y2 + WGUI_CAT_FMGR_MATRIX_BORDER_PIXEL);
                }   
            }
        }
        /* Clear current decoding pointer and set the node state */
        g_fmgr_cache_p->cur_decode_p = NULL;
        decode_node_p->state = WGUI_CAT_FMGR_CACHED;
    }
    else
    {
        /* if decode failed, stop link list */
		wgui_cat21x_set_displayable(decode_node_p->index, MMI_FALSE);
        wgui_fmgr_cache_stop_decoder();
        decode_node_p->state = WGUI_CAT_FMGR_CACHEERROR;
    }
    wgui_cat_fmgr_start_next();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_fmgr_decode_frame_hdlr
 * DESCRIPTION
 *  Filemanager decode frame callback from GDI.
 * PARAMETERS
 *  decode_result       [IN]    result code of decode
 *  handle              [IN]    GDI decode handle
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat_fmgr_decode_frame_hdlr(GDI_RESULT decode_result, gdi_handle handle)
{
    /* if decoder is deinited, ignore the decode result hdlr */
    if (g_fmgr_cache_p->decoder_create == 0)
    {
        return;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_fmgr_decode_before_frame_callback
 * DESCRIPTION
 *  Filemanager before decode frame callback from GDI.
 *  Used to clear background for Gif&PNG files
 * PARAMETERS
 *  decode_result       [IN]    result code of decode
 *  handle              [IN]    GDI decode handle
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat_fmgr_decode_before_frame_callback(GDI_RESULT decode_result, gdi_handle handle)
{
    wgui_cat_fmgr_cache_node *current_node_p = g_fmgr_cache_p->cur_decode_p;

    /* if decoder is deinited, ignore the decode result hdlr */
    if (g_fmgr_cache_p->decoder_create == 0 || current_node_p->buffer == NULL)
    {
        return;
    }    

    memset(
        current_node_p->buffer, 
        0xFF, 
        ((image_box_height*image_box_width*GDI_MAINLCD_BIT_PER_PIXEL)>>3));
}


#define WGUI_FMGR_MED_CACHE_SIZE 1024*500
/*****************************************************************************
 * FUNCTION
 *  wgui_cat_fmgr_cache_create_node
 * DESCRIPTION
 *  Filemanager create a decode node, alloc memory.
 * PARAMETERS
 *  void
 * RETURNS
 *  wgui_cat_fmgr_cache_node    Node pointer
 *****************************************************************************/
static wgui_cat_fmgr_cache_node *wgui_cat_fmgr_cache_create_node(void)
{
    wgui_cat_fmgr_cache_node *new_node_p;
    PU8 p1 = NULL;

    S32 buf_size;

    if (g_fmgr_cache_p == NULL)
    {
        return NULL;
    }    
    /*--------------------- check exist memory block first -------------------------------------------*/
    if (g_fmgr_cache_p->cur_decode_p != NULL)
    {
        if (g_fmgr_cache_p->cur_decode_p->state == WGUI_CAT_FMGR_CACHENONE || g_fmgr_cache_p->cur_decode_p->state == WGUI_CAT_FMGR_CACHEERROR)
        {
            /* return exist node pointer to use */
            return g_fmgr_cache_p->cur_decode_p;
        }
    }

    /*--------------------- Alloc memory ------------------------------------------------------------*/
    buf_size = sizeof(wgui_cat_fmgr_cache_node) + ((image_box_height*image_box_width*GDI_MAINLCD_BIT_PER_PIXEL)>>3);
    /* Alloc new memory from Screen memory first */
    p1 = (PU8)mmi_frm_scrmem_alloc_framebuffer(buf_size);
    if (p1 != NULL)
    {
        /* Point pointer to right address */
        new_node_p = (wgui_cat_fmgr_cache_node*)p1;
        memset(new_node_p, 0, sizeof(wgui_cat_fmgr_cache_node));
        new_node_p->buffer = (PU8)(p1 + sizeof(wgui_cat_fmgr_cache_node));
        new_node_p->mem_flag = WGUI_CAT_FMGR_CACHE_ASM;    
        return new_node_p;
    }
    

    if (g_fmgr_cache_p->med_cache_num < (WGUI_FMGR_MED_CACHE_SIZE/buf_size)) 
    {
        /* ASM not available, try to alloc in MDI*/
        media_get_ext_buffer(
            stack_int_get_active_module_id(),
            (void **)&p1,
            buf_size);  
        if (p1 != NULL)
        {
            /* Point pointer to right address */
            g_fmgr_cache_p->med_cache_num++;
            new_node_p = (wgui_cat_fmgr_cache_node*)p1;
            memset(new_node_p, 0, sizeof(wgui_cat_fmgr_cache_node));
            new_node_p->buffer = (PU8)(p1 + sizeof(wgui_cat_fmgr_cache_node));
            new_node_p->mem_flag = WGUI_CAT_FMGR_CACHE_MDI;    
            return new_node_p;
        }
    }

    /*--------------------- Can't found the memory, will use the furthest node ----------------------*/
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_fmgr_cache_free_node
 * DESCRIPTION
 *  Filemanager free a decode node
 * PARAMETERS
 *  node                [IN]    node pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat_fmgr_cache_free_node(wgui_cat_fmgr_cache_node *node)
{
    if (g_fmgr_cache_p == NULL)
    {
        return;
    }    
    if (node->mem_flag == WGUI_CAT_FMGR_CACHE_ASM)
    {
        mmi_frm_scrmem_free(node);
    }
    else
    {
        media_free_ext_buffer(stack_int_get_active_module_id(), (void**)&node);
        g_fmgr_cache_p->med_cache_num--;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_fmgr_cache_free_all
 * DESCRIPTION
 *  Filemanager free all decode and cached node
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat_fmgr_cache_free_all(void)
{
    S32 i;
    wgui_cat_fmgr_cache_node *cur_p;
    wgui_cat_fmgr_cache_node *del_p;

    if (g_fmgr_cache_p == NULL)
    {
        return;
    }    
    wgui_fmgr_cache_stop_decoder();
    
    for (i=0; i<WGUI_CAT_FMGR_CACHE_SEARCH_POINT_NUM; i++)
    {
        cur_p = g_fmgr_cache_p->cache_search_list[i].front_p;
        while (cur_p != NULL)
        {
            del_p = cur_p;
            cur_p = cur_p->next;
            wgui_cat_fmgr_cache_free_node(del_p);
        }
        g_fmgr_cache_p->cache_search_list[i].front_p = NULL;
        g_fmgr_cache_p->cache_search_list[i].rear_p = NULL;
    }

    if (g_fmgr_cache_p->cur_decode_p != NULL)
    {
        wgui_cat_fmgr_cache_free_node(g_fmgr_cache_p->cur_decode_p);
    }

    if (g_fmgr_cache_p->decoder_create == 1)
    {
        gdi_image_decoder_free();
        g_fmgr_cache_p->decoder_create = 0;
    }
    ASSERT(g_fmgr_cache_p->med_cache_num == 0);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_fmgr_cache_list_add
 * DESCRIPTION
 *  Filemanager add a node to the cache list
 * PARAMETERS
 *  idx                 [IN]    Index of the node
 *  file_icon_p         [IN]    file icon pointer
 *  ref_node            [OUT]   The result when check if it is cached
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat_fmgr_cache_list_add(S32 idx, PU8 file_icon_p, wgui_cat_fmgr_cache_node *ref_node)
{
    U32 cache_slot;
    wgui_cat_fmgr_cache_node *current_node_p;
    wgui_cat_fmgr_cache_node *new_node_p;
    S32 first_idx = 0, last_idx = 0;
    S32 i, j;

    if (g_fmgr_cache_p == NULL)
    {
        return;
    }     
    /* Create a new node to decode the image */
    new_node_p = wgui_cat_fmgr_cache_create_node();

    if (new_node_p == NULL)
    {
        /* No free memory ,check exist memory */
        if ((idx > g_fmgr_cache_p->first_displayed_item - g_fmgr_cache_p->cache_pre_page) && 
            (idx < (g_fmgr_cache_p->first_displayed_item + g_fmgr_cache_p->cache_pre_page*2))) 
        {
            /* if in cache area found a node to cache it. */
            for (i=0; i<WGUI_CAT_FMGR_CACHE_SEARCH_POINT_NUM; i++ )
            {
                if (g_fmgr_cache_p->cache_search_list[i].front_p != NULL)
                {
                    first_idx = g_fmgr_cache_p->cache_search_list[i].front_p->index;
                    break;
                }
            }

            for (j=WGUI_CAT_FMGR_CACHE_SEARCH_POINT_NUM-1; j>=0; j-- )
            {
                if (g_fmgr_cache_p->cache_search_list[j].rear_p!= NULL)
                {
                    last_idx = g_fmgr_cache_p->cache_search_list[j].rear_p->index;
                    break;
                }
            }    

            if ((g_fmgr_cache_p->first_displayed_item - first_idx) > (last_idx - (g_fmgr_cache_p->first_displayed_item + g_fmgr_cache_p->cache_pre_page)))
            {
                /* top more than bottom, remove the first item from link list */
                new_node_p = g_fmgr_cache_p->cache_search_list[i].front_p;
                g_fmgr_cache_p->cache_search_list[i].front_p = new_node_p->next;
                if (g_fmgr_cache_p->cache_search_list[i].front_p != NULL)
                {
                    g_fmgr_cache_p->cache_search_list[i].front_p->prev = NULL;
                }
                else
                {
                    g_fmgr_cache_p->cache_search_list[i].rear_p = NULL;
                }
                new_node_p->next = NULL;

            }
            else
            {
                /* bottom more than top, remove the last item from link list  */
                new_node_p = g_fmgr_cache_p->cache_search_list[j].rear_p;
                g_fmgr_cache_p->cache_search_list[j].rear_p = new_node_p->prev;
                if (g_fmgr_cache_p->cache_search_list[j].rear_p != NULL)
                {
                    g_fmgr_cache_p->cache_search_list[j].rear_p->next = NULL;
                }
                else
                {
                    g_fmgr_cache_p->cache_search_list[j].front_p = NULL;
                }
                new_node_p->prev = NULL;
            }

            /* reset node */
            new_node_p->index = 0;
            new_node_p->state = 0;
            new_node_p->next = NULL;
            new_node_p->prev = NULL;
            new_node_p->cache_width = 0;
            new_node_p->cache_height = 0;
        }
        else
        {
            /* if idx not in cache area, do not cache it. */
            g_fmgr_cache_p->cur_decode_p = NULL;
            return;
        }
    }

    cache_slot = idx/g_fmgr_cache_p->cache_num;
    current_node_p = g_fmgr_cache_p->cache_search_list[cache_slot].front_p;
    new_node_p->index = idx;

    /* Insert node to link list */
    if (ref_node == NULL)
    {
        /* Not in the middle of link list */
        if (current_node_p == NULL)
        {
            /* If empty in this slot */
            g_fmgr_cache_p->cache_search_list[cache_slot].front_p = new_node_p;
            g_fmgr_cache_p->cache_search_list[cache_slot].rear_p = new_node_p;
        }
        else
        {
            if (idx < current_node_p->index)
            {
                /* Add to first */
                g_fmgr_cache_p->cache_search_list[cache_slot].front_p = new_node_p;
                current_node_p->prev = new_node_p;
                new_node_p->next = current_node_p;
            }
            else
            {
                /* Add to last */
                g_fmgr_cache_p->cache_search_list[cache_slot].rear_p->next = new_node_p;
                new_node_p->prev = g_fmgr_cache_p->cache_search_list[cache_slot].rear_p;
                g_fmgr_cache_p->cache_search_list[cache_slot].rear_p = new_node_p;
            }
        }
    }
    else
    {
        /* In the middle of the list, insert new node by reference node directly */
        if (ref_node->index < idx)
        {
            /* Searched from rear to front, reference node is smaller than new node. */
            new_node_p->next = ref_node->next;
            ref_node->next->prev = new_node_p;
            new_node_p->prev = ref_node;
            ref_node->next = new_node_p;
        }
        else
        {
            /* searched from front to rear, reference node is bigger than new node */
            new_node_p->next = ref_node;
            new_node_p->prev = ref_node->prev;
            ref_node->prev->next = new_node_p;
            ref_node->prev = new_node_p;
        }
    }

    g_fmgr_cache_p->cur_decode_p = new_node_p;
     new_node_p->state = WGUI_CAT_FMGR_CACHING;
}

static MMI_BOOL wgui_cat_fmgr_check_is_show_thumbnail(S32 idx)
{
	wgui_fmgr_menuitem_data_struct menuitem_data;

#ifdef __MMI_CAT216_CAT212_SUPPORT_FMGR__
	if (g_fmgr_struct_p->fmgr_style == MMI_FMGR_GUI_INFO_STYLE || 
        g_fmgr_struct_p->fmgr_style == MMI_FMGR_GUI_HILITE_STYLE )
    {
        wgui_fmgr_info_struct fmgr_info;

        memset(&fmgr_info, 0, sizeof(wgui_fmgr_info_struct));
        wgui_cat212_fmgr_get_info_ptr(idx, &fmgr_info);
        menuitem_data.is_show_thumb = fmgr_info.is_show_thumb;
    }
    else
#endif
    {
        BOOL is_hilighted;

        /* Get item idx from application */
        is_hilighted = (idx == g_fmgr_cache_p->highlight_index)?TRUE:FALSE;
        wgui_cat_fmgr_get_menuitem(idx, is_hilighted, &menuitem_data);
    }

	return menuitem_data.is_show_thumb;

}
/*****************************************************************************
 * FUNCTION
 *  wgui_cat_fmge_find_next
 * DESCRIPTION
 *  Filemanager find next item to cache
 * PARAMETERS
 *  cur_cache           [IN]    Current cache item.
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__FS_SORT_SUPPORT__)
    #define WGUI_CAT_FMGR_SORT_NUMBER FS_SORT_MAX_ENTRY
#else
    #define WGUI_CAT_FMGR_SORT_NUMBER 0
#endif

static S32 wgui_cat_fmge_find_next(S32 cur_cache)
{
    S32 next_to_cache;

    if (g_fmgr_cache_p == NULL)
    {
        return -1;
    }
    
    if (MMI_fixed_list_menu.n_items >  WGUI_CAT_FMGR_SORT_NUMBER)
    {
        /* If item count more than sort count, will use less cache mode. */
        if (cur_cache < (g_fmgr_cache_p->first_displayed_item + g_fmgr_cache_p->cache_pre_page - 1))
        {
            /* Only cache the item, which is on the screen. */
            return cur_cache+1;
        }
        return -1;
    }

    if((cur_cache >= g_fmgr_cache_p->first_displayed_item) && 
        (cur_cache < g_fmgr_cache_p->first_displayed_item + g_fmgr_cache_p->cache_pre_page*2))
    {

			wgui_cat_fmgr_cache_node *current_node_p = NULL;
			if (!wgui_cat_fmgr_is_cached(g_fmgr_cache_p->first_displayed_item, &current_node_p))
			{
				MMI_BOOL is_displayable = MMI_TRUE;

				if (g_fmgr_cache_p->cur_decode_p != NULL)
				{
					if (g_fmgr_cache_p->cur_decode_p->state == WGUI_CAT_FMGR_CACHEERROR)
						is_displayable = MMI_FALSE;
				}
				if((is_displayable) && wgui_cat_fmgr_check_is_show_thumbnail(g_fmgr_cache_p->first_displayed_item))
				{
				    next_to_cache = g_fmgr_cache_p->first_displayed_item;
			    }
			    else
			    {
				    next_to_cache = cur_cache + 1;
			    }
			}
			else
			{
				next_to_cache = cur_cache + 1;
			}


    }
    else if ((cur_cache < g_fmgr_cache_p->first_displayed_item) && 
        (cur_cache > g_fmgr_cache_p->first_displayed_item - g_fmgr_cache_p->cache_pre_page))
    {
        /* In top prepare area */
        if (cur_cache == 0)
        {
            next_to_cache = g_fmgr_cache_p->first_displayed_item + g_fmgr_cache_p->cache_pre_page*2 + 1;
        }
        else
        {
            next_to_cache = cur_cache - 1;
        }
    }
    else if (cur_cache == g_fmgr_cache_p->first_displayed_item - g_fmgr_cache_p->cache_pre_page)
    {
        /* Top prepare first item, jump to area after bottom*/
        next_to_cache = g_fmgr_cache_p->first_displayed_item + g_fmgr_cache_p->cache_pre_page*2 + 1;
    }
    else if (cur_cache == g_fmgr_cache_p->first_displayed_item + g_fmgr_cache_p->cache_pre_page*2)
    {
        /* Bottom prepare last item, jump to top area*/
        if (g_fmgr_cache_p->first_displayed_item == 0)
        {
            next_to_cache = cur_cache + 1;
        }
        else
        {
            next_to_cache = g_fmgr_cache_p->first_displayed_item - 1;
        }
    }
    else
    {
        /* Area after bottom*/
        next_to_cache = cur_cache + 1;
    }

    return next_to_cache;
}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat_fmgr_start_next
 * DESCRIPTION
 *  Filemanager start next cache.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat_fmgr_start_next(void)
{
    S32 next_to_cache = -1;
    
    if (g_fmgr_cache_p == NULL)
    {
        return;
    }    
    if (g_fmgr_cache_p->cur_decode_p != NULL)
    {
        if (g_fmgr_cache_p->cur_decode_p->state == WGUI_CAT_FMGR_CACHING)
        {
            return;
        }
    }

    if (g_fmgr_cache_p->prev_first_displayed_item != g_fmgr_cache_p->first_displayed_item)
    {
        wgui_cat_fmgr_cache_node *current_node_p = NULL;

        next_to_cache = g_fmgr_cache_p->first_displayed_item;
        while (wgui_cat_fmgr_is_cached(next_to_cache, &current_node_p))
        {
            next_to_cache = wgui_cat_fmge_find_next(next_to_cache);
        }

        g_fmgr_cache_p->prev_first_displayed_item = g_fmgr_cache_p->first_displayed_item;
    }
    else
    {
        if (g_fmgr_cache_p->cur_decode_p != NULL)
        {
            if (g_fmgr_cache_p->cur_decode_p->state == WGUI_CAT_FMGR_CACHENONE)
            {
                next_to_cache = g_fmgr_cache_p->decoding_index;
            }
        }
        
        if (next_to_cache == -1)
        {
            next_to_cache = wgui_cat_fmge_find_next(g_fmgr_cache_p->decoding_index);
        }
    }
    wgui_cat_fmgr_cache_list_decoding_next(next_to_cache);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_fmgr_delay_decode_timer
 * DESCRIPTION
 *  Filemanager delay decode timer callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat_fmgr_delay_decode_timer(void)
{
    wgui_cat_fmgr_cache_node *current_node_p;
    S8 buffer_UCS2[SRV_FMGR_PATH_BUFFER_SIZE];
    GDI_RESULT ret;
    S32 img_width, img_height;
    S32 resized_width, resized_height;
    S32 resized_offset_x, resized_offset_y;
    S32 item_idx;
    S32 box_width = image_box_width;
    S32 box_height = image_box_height;
	PS8 err_str_ptr;

    if (g_fmgr_cache_p == NULL)
    {
        return;
    }    
    current_node_p = g_fmgr_cache_p->cur_decode_p;
    item_idx = g_fmgr_cache_p->cur_decode_p->index;
    
    if (!wgui_cat21x_get_image_path_callback(item_idx, buffer_UCS2))
    {
        /* Start next */
        wgui_fmgr_cache_stop_decoder();
        g_fmgr_cache_p->cur_decode_p->state = WGUI_CAT_FMGR_CACHEERROR;
        wgui_cat_fmgr_start_next();
        return;
    }

    /* get jpeg width and height */
    ret = gdi_image_get_dimension_file((PS8) buffer_UCS2, &img_width, &img_height);

    /* check if is a valid image or not */
    /* TODO: Adapt to File limit */
    if ((ret < 0) || (img_width <= 0) || (img_height <= 0))   /* invalid image size */
    {
        wgui_cat21x_set_displayable(item_idx, MMI_FALSE);
        /* Start next */
        wgui_fmgr_cache_stop_decoder();
        g_fmgr_cache_p->cur_decode_p->state = WGUI_CAT_FMGR_CACHEERROR;
        wgui_cat_fmgr_start_next();
        return;
    }
#if !defined(__COSMOS_MMI_PACKAGE__)
    if (!mmi_fmgr_util_file_limit_check(FMGR_LIMIT_IMAGE_VIEWER, buffer_UCS2, (PS8*)&err_str_ptr))
    {
        wgui_cat21x_set_displayable(item_idx, MMI_FALSE);
        /* Start next */
        wgui_fmgr_cache_stop_decoder();
        g_fmgr_cache_p->cur_decode_p->state = WGUI_CAT_FMGR_CACHEERROR;
        wgui_cat_fmgr_start_next();
        return;  
    }
#endif
    /* can get dimesion from file, must be a valid jpeg file, then draw it */

    if ((img_width < box_width) && (img_height < box_height))
    {
        resized_width = img_width;
        resized_height = img_height;
        resized_offset_x = ((box_width-img_width)>>1);
        resized_offset_y = ((box_height-img_height)>>1);   
        current_node_p->cache_width = resized_width;
        current_node_p->cache_height = resized_height;        
    }
    else if ((img_width > box_width) && (img_height > box_height))
    {
        /* Both large, need to resize to fit the box and cut */
        
        gdi_util_fit_box(
            GDI_UTIL_MODE_SHORT_SIDE_FIT,
            box_width,
            box_height,
            img_width,
            img_height,
            &resized_offset_x,
            &resized_offset_y,
            &resized_width,
            &resized_height);     
        current_node_p->cache_width = box_width;
        current_node_p->cache_height = box_height;        
    }
    else
    {
        /* One of them large, fit the box, do not cut */
        gdi_util_fit_box(
            GDI_UTIL_MODE_LONG_SIDE_FIT,
            box_width,
            box_height,
            img_width,
            img_height,
            &resized_offset_x,
            &resized_offset_y,
            &resized_width,
            &resized_height);
        current_node_p->cache_width = resized_width;
        current_node_p->cache_height = resized_height;
    }    
    
    /* Create layer and nb decode on the layer */
    gdi_layer_create_using_outside_memory(
        0,
        0,
        box_width,
        box_height,
        &(g_fmgr_cache_p->decoding_layer),
        (PU8) current_node_p->buffer,
        (S32) ((box_height*box_width*GDI_MAINLCD_BIT_PER_PIXEL)>>3));

    gdi_layer_push_and_set_active(g_fmgr_cache_p->decoding_layer);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
#ifdef __MMI_FTE_SUPPORT__
	gdi_layer_clear(GDI_COLOR_BLACK);
#endif
    gdi_push_and_set_alpha_blending_source_layer(g_fmgr_cache_p->decoding_layer);
    if (resized_offset_x > 0)
    {
        resized_offset_x = 0;
    }

    if (resized_offset_y > 0)
    {
        resized_offset_y = 0;
    }

    gdi_nb_set_anim_after_frame_callback(wgui_cat_fmgr_decode_frame_hdlr);
#if !defined(__MMI_FTE_SUPPORT__)
    gdi_nb_set_anim_before_frame_callback(wgui_cat_fmgr_decode_before_frame_callback);
#endif

    ret = gdi_image_decoder_decode_file(
        resized_offset_x,
        resized_offset_y,
        resized_width,
        resized_height,
        FALSE,
        (PS8) buffer_UCS2,
        &(g_fmgr_cache_p->decoding_handle));

    if (ret >= 0)
    {
        /* Start decode success */
    }
    else
    {
        /* Failed to start the decoding */
        wgui_cat21x_set_displayable(item_idx, MMI_FALSE);
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    }
	gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_pop_and_restore_active();
    
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_fmgr_set_cache_pos
 * DESCRIPTION
 *  Save thumb image position
 * PARAMETERS
 *  idx             [IN]        Index of image
 *  first_displayed [IN]        first displayed ID
 *  fmgr_cache_p    [IN]        Cache data of fmgr
 *  x1              [IN]        Position x1
 *  y1              [IN]        Position y1
 * RETURNS      
 *  void
 *****************************************************************************/
void wgui_cat_fmgr_set_cache_pos(S32 idx, S32 first_displayed, wgui_cat_fmgr_cache_struct* fmgr_cache_p, S32 x1, S32 y1)
{

    /* Save first_displayed item */
    fmgr_cache_p->first_displayed_item = first_displayed;

    if (g_fmgr_struct_p->fmgr_style == MMI_FMGR_GUI_INFO_STYLE)
    {
        fmgr_cache_p->cache_pos[0].x = x1;
        fmgr_cache_p->cache_pos[0].y = y1;
    }
    else
    {
        if (!gui_screen_smooth_scrolling_by_pen()
#if defined(__MMI_UI_LIST_SLIDE_EFFECT__)
            && g_slide_effect->state != GUI_EFFECT_STATE_RUNNING
#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_KEY)
            && !gui_in_ssk
#endif
#endif /* __MMI_UI_LIST_SLIDE_EFFECT__ */        
            )
        {
            S32 pos = idx - first_displayed;
    
            ASSERT(pos < WGUI_CAT_FMGR_CACHE_MAX_PER_PAGE);
            
            if (pos >= 0)
            {
                fmgr_cache_p->cache_pos[pos].x = x1;
                fmgr_cache_p->cache_pos[pos].y = y1;
            }
        }
    }
}
#endif /* defined(FMGR_USING_CACHE) */


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_fmgr_show_img
 * DESCRIPTION
 *  Filemanager to show a thumb image.
 * PARAMETERS
 *  idx             [IN]        Index of image
 *  is_hilighted    [IN]        Is it highlight
 *  menuitem_data   [IN]        Menuitem data of fmgr
 *  x1              [IN]        Position x1
 *  y1              [IN]        Position y1
 *  x2              [IN]        Position x2
 *  y2              [IN]        Position y2
 * RETURNS      
 *  void
 *****************************************************************************/
static void wgui_cat_fmgr_show_img(
        S32 idx, 
        BOOL is_hilighted, 
        wgui_fmgr_menuitem_data_struct *menuitem_data, 
        S32 x1, 
        S32 y1, 
        S32 x2, 
        S32 y2)
{
#if defined(FMGR_USING_CACHE)
    wgui_cat_fmgr_cache_node *current_node_p = NULL;

    if (g_fmgr_cache_p == NULL)
    {
        return;
    }    
    /* create jpeg decoder */
    if (g_fmgr_cache_p->decoder_create == 0)
    {
        /* max image size is 100x100 */
        gdi_image_decoder_create(100, 100, wgui_cat_fmgr_decode_result_hdlr);
        g_fmgr_cache_p->decoder_create = 1;
    }
    
    if (wgui_cat_fmgr_is_cached(idx, &current_node_p))
    {
        /* Draw the cached image */
        wgui_cat_cache_draw_cached_img(current_node_p, x1, y1);
    }
    else
    {
        if (menuitem_data->is_show_thumb && !gui_screen_smooth_scrolling_by_pen())
        {
            if (g_fmgr_cache_p->cur_decode_p == NULL || g_fmgr_cache_p->cur_decode_p->state == WGUI_CAT_FMGR_CACHENONE || g_fmgr_cache_p->cur_decode_p->state == WGUI_CAT_FMGR_CACHEERROR)
            {
                /* Pass node to make search faster */
                wgui_cat_fmgr_cache_list_add(idx, menuitem_data->file_icon_ptr, current_node_p);
                
                if (g_fmgr_cache_p->cur_decode_p != NULL)
                {
                    /* Start decoding image */
                    StartNonAlignTimer(FMGR_DELAY_DECODE_0, WGUI_CAT_FMGR_UI_DELAY_DECODE_FIRST_DUR, wgui_cat_fmgr_delay_decode_timer);
                    g_fmgr_cache_p->decoding_index = idx;
                }
            }
        }

        {
            /* Draw the ICON */
            S32 icon_offset_x, icon_offset_y;
            S32 icon_width, icon_height;  
  
            gdi_image_get_dimension((PU8) menuitem_data->file_icon_ptr, &icon_width, &icon_height);

            icon_offset_x = ((image_box_width - icon_width) >> 1) + x1;
            icon_offset_y = ((image_box_height - icon_height) >> 1) + y1;

            gdi_image_draw(icon_offset_x, icon_offset_y, menuitem_data->file_icon_ptr);
        }
    }
#else /* defined(FMGR_USING_CACHE) */
    {
        /* Draw the ICON, currently only show image when defined FMGR_USING_CACHE */
        S32 icon_offset_x, icon_offset_y;
        S32 icon_width, icon_height;  

        gdi_image_get_dimension((PU8) menuitem_data->file_icon_ptr, &icon_width, &icon_height);

        icon_offset_x = ((image_box_width - icon_width) >> 1) + x1;
        icon_offset_y = ((image_box_height - icon_height) >> 1) + y1;

        gdi_image_draw(icon_offset_x, icon_offset_y, menuitem_data->file_icon_ptr);
    }
#endif /* defined(FMGR_USING_CACHE) */
}


void wgui_cat214_fmgr_draw_menuitem_matrix(
        S32 idx, 
        S32 page_start_idx, 
        S32 page_end_idx,
        BOOL is_hilighted, 
        BOOL is_need_update, 
        BOOL is_new_page,
        S32 x1, 
        S32 y1, 
        S32 x2, 
        S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_fmgr_menuitem_data_struct menuitem_data;
    gdi_color bg_color;
    S32 bottom_h = MMI_BUTTON_BAR_HEIGHT;
    S32 temp_y2 = y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get item idx from application */
    wgui_cat_fmgr_get_menuitem(idx, is_hilighted, &menuitem_data);

#ifdef __MMI_ICON_BAR_SUPPORT__
    #ifdef __MMI_FTE_SUPPORT__
    if(MMI_TRUE == wgui_icon_bar_is_created())
    {
        bottom_h += MMI_ICON_BAR_HEIGHT;
    }
    #endif
#endif /*__MMI_ICON_BAR_SUPPORT__*/	
    if(y1 > UI_device_height - bottom_h - 1)
	return;
    if(temp_y2 > UI_device_height - bottom_h - 1)
    {
        temp_y2 = UI_device_height - bottom_h - 1;
    }
    /* Set image clip */
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, temp_y2);


    /* Draw the highlight mark first */
    if (g_cat214_highlight_layer == WGUI_CAT214_HIGHLIGHT_LAYER_BOTTOM && is_hilighted)
    {
        wgui_cat214_fmgr_draw_matrix_highlight(x1, y1, x2, y2);
    }

    /* Draw the background of image*/
    bg_color = wgui_fmgr_get_bg_color(is_hilighted, (U16)g_fmgr_struct_p->fmgr_style);
    wgui_fmgr_redraw_image_background(
        is_hilighted,
        (U16)g_fmgr_struct_p->fmgr_style,
        bg_color, 
        x1 + WGUI_CAT_FMGR_MATRIX_BORDER_PIXEL, 
        y1 + WGUI_CAT_FMGR_MATRIX_BORDER_PIXEL, 
        x2 - WGUI_CAT_FMGR_MATRIX_BORDER_PIXEL, 
        temp_y2  - WGUI_CAT_FMGR_MATRIX_BORDER_PIXEL);

#if defined(FMGR_USING_CACHE)   
    if (g_fmgr_cache_p != NULL)
    {        
        wgui_cat_fmgr_set_cache_pos(
            idx, 
            g_fmgr_cache_p->first_displayed_item, 
            g_fmgr_cache_p, 
            x1 + WGUI_CAT_FMGR_MATRIX_BORDER_PIXEL,
            y1 + WGUI_CAT_FMGR_MATRIX_BORDER_PIXEL);
    }
#endif /* #if defined(FMGR_USING_CACHE) */

    /* Draw the Image */
    wgui_cat_fmgr_show_img(
        idx, 
        is_hilighted, 
        &menuitem_data, 
        x1 + WGUI_CAT_FMGR_MATRIX_BORDER_PIXEL, 
        y1 + WGUI_CAT_FMGR_MATRIX_BORDER_PIXEL, 
        x2 - WGUI_CAT_FMGR_MATRIX_BORDER_PIXEL, 
        y2 - WGUI_CAT_FMGR_MATRIX_BORDER_PIXEL);


    /* Draw the highlight mark last */
    if (g_cat214_highlight_layer == WGUI_CAT214_HIGHLIGHT_LAYER_TOP && is_hilighted)
    {
        wgui_cat214_fmgr_draw_matrix_highlight(x1, y1, x2, y2);
    }    

    gdi_layer_pop_clip();
}


void wgui_cat214_fmgr_hide_menuitem_matrix(S32 index)
{
    /* End the decoding item, but not free it, just set the flag to NONE */
#if defined(FMGR_USING_CACHE)
    if (g_fmgr_cache_p != NULL)
    {
        wgui_fmgr_cache_stop_decoder();
    }
#endif /* #if defined(FMGR_USING_CACHE) */
}

#ifndef __MMI_SLIM_FILE_MANAGER__
/*****************************************************************************
* [Category214]
*
* This category is for File Manager to display drive info.
*
*  *********************
*  *                  ----------- Title
*  *********************
*  *  ******* *******  *
*  *  *     * *     *  *
*  *  *     * *     ----------- Matrix Images
*  *  ******* *******  *
*  *  ******* *******  *
*  *  *     * *     *  *
*  *  *     * *     *  *
*  *  ******* *******  *
*  *********************
*
*****************************************************************************/

void ShowCategory214FmgrScreen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U16 num_of_items,
        CatFmgrGetFileData get_menuitem_data,
        CatFmgrHideFileData hide_menuitem_data,
        U8 num_per_row,
        U8 num_per_col,
        S32 highlighted_item,
        U8 *history_buffer)
{
#if defined(FMGR_USING_CACHE)
    S32 number;

    memset(&g_214_fmgr, 0, sizeof(g_214_fmgr));
    g_fmgr_cache_p= &(g_214_fmgr.cache);

    number = num_of_items/(WGUI_CAT_FMGR_CACHE_SEARCH_POINT_NUM-1);
    g_fmgr_cache_p->cache_num = 1;
    do{
        g_fmgr_cache_p->cache_num = g_fmgr_cache_p->cache_num<<1;
    }while(number >= g_fmgr_cache_p->cache_num);
    
    g_fmgr_cache_p->cache_num = g_fmgr_cache_p->cache_num<<1;
    g_cat214_highlight_layer = WGUI_CAT214_HIGHLIGHT_LAYER_TOP;
#endif /* #if defined(FMGR_USING_CACHE) */

    g_fmgr_struct_p = &(g_214_fmgr.fmgr_struct);
    g_fmgr_struct_p->fmgr_style = MMI_FMGR_GUI_MATRIX_STYLE;

    wgui_cat_fmgr_get_menuitem = get_menuitem_data;
    wgui_cat_fmgr_hide_menuitem = hide_menuitem_data; 

    ShowCategory214Screen(
            title,
            title_icon,
            left_softkey,
            left_softkey_icon,
            right_softkey,
            right_softkey_icon,
            num_of_items,
            wgui_cat214_fmgr_draw_menuitem_matrix,
            wgui_cat214_fmgr_hide_menuitem_matrix,
            num_per_row,
            num_per_col,
            highlighted_item,
            history_buffer);

#if defined(FMGR_USING_CACHE)
    if (g_fmgr_cache_p->cur_decode_p == NULL && num_of_items != 0)
    {
        g_fmgr_cache_p->first_displayed_item = (MMI_fixed_matrix_menu.first_displayed_row*MMI_fixed_matrix_menu.displayed_columns 
                                                + MMI_fixed_matrix_menu.first_displayed_column);
        wgui_cat_fmgr_cache_list_decoding_next(g_fmgr_cache_p->first_displayed_item);
    }
#endif /* #if defined(FMGR_USING_CACHE) */
}


/*****************************************************************************
 * FUNCTION
 *  Cat213GetItemCallback
 * DESCRIPTION
 *  Get category 213 get item callback function
 * PARAMETERS
 *  item_idx            [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static pBOOL Cat214GetItemCallback(S32 item_idx, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((PS8) str_buff, (PS8) L"");
    *img_buff_p = NULL;;

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  Cat213GetHintCallback
 * DESCRIPTION
 *  Get category 213 get hint callback function
 * PARAMETERS
 *  item_idx        [IN]        
 *  hint_array      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static S32 Cat214GetHintCallback(S32 item_idx, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* do nothing */
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat214_highilight_item
 * DESCRIPTION
 *  Category 213 menu item highlight function
 * PARAMETERS
 *  item                   [IN]     private menu item object
 *  common_item_data       [IN]     common menu item object
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat214_highilight_item(void *item, void *common_item_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_highlight_fixed_icontext_menuitem(item, common_item_data);

#if defined(FMGR_USING_CACHE)
    if (g_fmgr_cache_p != NULL)
    {
        g_fmgr_cache_p->highlight_index = MMI_fixed_matrix_menu.highlighted_item;
    }
#endif /* #if defined(FMGR_USING_CACHE) */
    /* stop async image decoding */
    /*if (cat214_hide_image_callback != NULL)
    {
        cat214_hide_image_callback(0);
    }*/
}



/*****************************************************************************
 * FUNCTION
 *  wgui_cat214_unhighlight_item
 * DESCRIPTION
 *  Category 213 menu item remove highlight function
 * PARAMETERS
 *  item                   [IN]     private menu item object
 *  common_item_data       [IN]     common menu item object
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat214_unhighlight_item(void *item, void *common_item_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_remove_highlight_fixed_icontext_menuitem(item, common_item_data);

    /* stop async image decoding */
    /*if (cat214_hide_image_callback != NULL)
    {
        cat214_hide_image_callback();
    }*/
}
#endif /*__MMI_SLIM_FILE_MANAGER__*/

/*****************************************************************************
 * FUNCTION
 *  wgui_cat214_show_item
 * DESCRIPTION
 *  Category 214 menu item show function
 * PARAMETERS
 *  item                   [IN]     private menu item object
 *  common_item_data       [IN]     common menu item object
 *  x                      [IN]     x
 *  y                      [IN]     y
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat214_show_item(void *item, void *common_item_data, S32 x, S32 y)
{
    BOOL is_hilighted;
    S32 item_width = 0, item_height = 0;
    S32 first_displayed_item;
    S32 last_displayed_item;

    MMI_fixed_matrix_menu.item_measure_function(
                            item,
                            common_item_data,
                            &item_width,
                            &item_height);
    
    gdi_layer_push_clip();
    gdi_layer_set_clip(x ,y, x + item_width - 1, y + item_height - 1);
    first_displayed_item = (MMI_fixed_matrix_menu.first_displayed_row*MMI_fixed_matrix_menu.displayed_columns 
                                            + MMI_fixed_matrix_menu.first_displayed_column);
    last_displayed_item = first_displayed_item + MMI_fixed_matrix_menu.displayed_columns * MMI_fixed_matrix_menu.displayed_rows - 1;
    if((MMI_fixed_matrix_menu.n_items - 1)< last_displayed_item)
    {
        last_displayed_item = MMI_fixed_matrix_menu.n_items - 1;
    }
#if defined(FMGR_USING_CACHE)
    if (g_fmgr_cache_p != NULL)
    {
        g_fmgr_cache_p->first_displayed_item = first_displayed_item;
    }
#endif /* #if defined(FMGR_USING_CACHE) */

    if (MMI_fixed_matrix_menu.current_display_item == MMI_fixed_matrix_menu.highlighted_item)
    {
        is_hilighted = TRUE;
    }
    else
    {
        is_hilighted = FALSE;
    }

    if (cat214_draw_image_callback != NULL)
    {
        gdi_layer_lock_frame_buffer();        

        cat214_draw_image_callback(
            MMI_fixed_matrix_menu.current_display_item,
            first_displayed_item,
            last_displayed_item,
            (BOOL)is_hilighted,
            TRUE,
            TRUE,
            x,
            y,
            x + item_width - 1,
            y + item_height - 1);
        
        if (is_hilighted && (g_cat214_highlight_layer == WGUI_CAT214_HIGHLIGHT_NORMAL))
        {
            wgui_cat214_fmgr_draw_matrix_highlight(x, y, (x + item_width - 1), (y + item_height - 1));
        }

        gdi_layer_unlock_frame_buffer();
    }    

    gdi_layer_pop_clip();
#if defined(FMGR_USING_CACHE)
    wgui_cat_fmgr_start_next();
#endif /* #if defined(FMGR_USING_CACHE) */
}

#ifndef __MMI_SLIM_FILE_MANAGER__
/*****************************************************************************
 * FUNCTION
 *  wgui_cat214_hide_item
 * DESCRIPTION
 *  Hide category 214 item function.
 * PARAMETERS
 *  item_idx            [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat214_hide_item(void *item, void *common_item_data, S32 x, S32 y)
{
    
    if (cat214_hide_image_callback != NULL)
    {
        cat214_hide_image_callback(0);
    }
    
}

void wgui_cat214_disable_draw_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cat214_highlight_layer = WGUI_CAT214_HIGHLIGHT_NONE;
}

/*****************************************************************************
 * FUNCTION
 *  ShowCategory214Screen
 * DESCRIPTION
 *  Show category 214 screen.
 * PARAMETERS
 *  title                   [IN]        Title string id
 *  title_icon              [IN]        Title image id
 *  left_softkey            [IN]        Lsk string id
 *  left_softkey_icon       [IN]        Lsk image id
 *  right_softkey           [IN]        Rsk string id
 *  right_softkey_icon      [IN]        Rsk image id
 *  num_of_items            [IN]        How many items
 *  draw_image_callback     [IN]        Callback function to draw image
 *  hide_image_callback     [IN]        Callback function to hide
 *  num_per_row             [IN]        Num of image pre row
 *  num_per_col             [IN]        Num of image pre col
 *  highlighted_item        [IN]        Highlighted item
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory214Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U16 num_of_items,
        Cat214DrawImageFuncPtr draw_image_callback,
        Cat214HideImageFuncPtr hide_image_callback,
        U8 num_per_row,
        U8 num_per_col,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 h_flag;
    S32 i_width, i_height;
    S32 tool_bar_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* arg checking */
    MMI_ASSERT(num_per_row != 0);
    MMI_ASSERT(num_per_col != 0);

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif
    
    /* Show shortcut when fullscreen backgournd */
    wgui_title_set_no_icon_shct(MMI_TRUE);

    gui_setup_submenu_layout();

    cat214_draw_image_callback = draw_image_callback;
    cat214_hide_image_callback = hide_image_callback;

    wgui_title_set_menu_shortcut_number(-1);

    gdi_layer_lock_frame_buffer();

    /* init highligthed item idx */
    MMI_fixed_list_menu.n_items = num_of_items;

    /* shortcut */
    register_menu_shortcut_keys();
    set_menu_item_count(num_of_items);

    dm_add_title_id(title, title_icon);
    dm_add_softkey_id(left_softkey, right_softkey);

    wgui_dynamic_matrix_create_icontext_menu(
        num_of_items,
        Cat214GetItemCallback,
        Cat214GetHintCallback,
        WGUI_LIST_INVALID_HIGHLIGHT,
        MMI_FALSE,
        UI_dummy_function,
        0,
        0,
        NULL);
#ifdef __MMI_ICON_BAR_SUPPORT__	
#if defined(__MMI_FTE_SUPPORT__)
    if(MMI_TRUE == wgui_icon_bar_is_created())
    {
        tool_bar_height = MMI_ICON_BAR_HEIGHT;
    }
#endif
#endif /*__MMI_ICON_BAR_SUPPORT__*/
#ifdef GUI_MATRIX_MENU_SMOOTH_SCROLLING_BY_PEN
    gui_matrix_ssp_reset_state();
#endif
    resize_fixed_matrix(MMI_content_width, MMI_content_height - tool_bar_height);   
    if (num_of_items > (num_per_col*num_per_row))
    {
#if defined(__MMI_FTE_SUPPORT__)
        i_width = (MMI_content_width - UI_SCROLLBAR_WIDER_WIDTH)/num_per_col;
#else
        i_width = (MMI_content_width - current_MMI_theme->scrollbar_size)/num_per_col;
#endif
    }
    else
    {
        i_width = MMI_content_width/num_per_col;
    }
    i_height = ((MMI_content_height - tool_bar_height)/num_per_row);
    
    configure_fixed_matrix(i_width, i_height, num_per_col, num_per_row);

    image_box_width = i_width - WGUI_CAT_FMGR_MATRIX_BORDER_PIXEL * 2;
    image_box_height = i_height - WGUI_CAT_FMGR_MATRIX_BORDER_PIXEL * 2;

#if defined(FMGR_USING_CACHE)    
    if (g_fmgr_cache_p != NULL)
    {
        g_fmgr_cache_p->cache_pre_page= num_per_row*num_per_col;
        g_fmgr_cache_p->prev_first_displayed_item = -1;
        g_fmgr_cache_p->highlight_index = highlighted_item;
    }
#endif /* #if defined(FMGR_USING_CACHE) */

    MMI_fixed_matrix_menu.flags |= UI_DYAMIC_MATRIX_MENU_ALIGN_LEFT_TOP|UI_MATRIX_MENU_LOOP;

    MMI_fixed_matrix_menu.item_remove_highlight_function = wgui_cat214_unhighlight_item;
    MMI_fixed_matrix_menu.item_highlight_function = wgui_cat214_highilight_item;
    MMI_fixed_matrix_menu.item_display_function = wgui_cat214_show_item;
    MMI_fixed_matrix_menu.item_hide_function = wgui_cat214_hide_item;

    h_flag = set_matrix_menu_category_history(MMI_CATEGORY214_ID, history_buffer);
    if (!h_flag)
    {
         MMI_fixed_matrix_menu.highlighted_item = highlighted_item;
    }

    if( MMI_fixed_matrix_menu.highlighted_item > (num_of_items - 1))
    {
        MMI_fixed_matrix_menu.highlighted_item = num_of_items - 1;
    }
    MMI_fixed_list_menu.highlighted_item = MMI_fixed_matrix_menu.highlighted_item;

    dynamic_matrix_goto_item_no_redraw(MMI_fixed_matrix_menu.highlighted_item);

    if (num_of_items != 0)
    {
        wgui_title_set_menu_shortcut_number(highlighted_item + 1);
        wgui_title_disable_menu_shortcut_display(MMI_FALSE);
    }

    gdi_layer_unlock_frame_buffer();

    wgui_cat_setup_category_default_history(MMI_CATEGORY214_ID, DM_CLEAR_SCREEN_BACKGROUND, ExitCategory214Screen);
    dm_redraw_category_screen();
    
    if (num_of_items == 0)
    {
       wgui_cat_fmgr_show_empty_string(NULL);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory214Screen
 * DESCRIPTION
 *  Exit category 214
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategory214Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearHighlightHandler();
    reset_menu_shortcut_handler();
    reset_softkeys();
    reset_pop_up_descriptions();
    reset_dynamic_matrix();    
        
#if defined(FMGR_USING_CACHE)
    if (g_fmgr_cache_p != NULL)
    {
        wgui_cat_fmgr_cache_free_all();
    }
#endif /* #if defined(FMGR_USING_CACHE) */
        
    /* hide image callback */
    if (cat214_hide_image_callback != NULL)
        {
        cat214_hide_image_callback(0);
        }
#if defined(FMGR_USING_CACHE)
    if (g_fmgr_cache_p != NULL)
        {
        g_fmgr_cache_p->cur_decode_p = NULL;
        g_fmgr_cache_p = NULL;
        }
#endif 

    g_cat214_highlight_layer = WGUI_CAT214_HIGHLIGHT_NORMAL;

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif

     MMI_fixed_matrix_menu.flags &= ~UI_DYAMIC_MATRIX_MENU_ALIGN_LEFT_TOP;
        
#if 0//def __GDI_MEMORY_PROFILE_2__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

#endif /*__MMI_SLIM_FILE_MANAGER__*/

#ifdef __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__

/*****************************************************************************
 * FUNCTION
 *  wgui_cat219_highilight_item
 * DESCRIPTION
 *  Category 213 menu item highlight function
 * PARAMETERS
 *  item                   [IN]     private menu item object
 *  common_item_data       [IN]     common menu item object
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat219_highilight_item(void *item, void *common_item_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(FMGR_USING_CACHE)
    if (g_fmgr_cache_p != NULL)
    {
        g_fmgr_cache_p->highlight_index = MMI_fixed_matrix_menu.highlighted_item;
    }    
#endif /* #if defined(FMGR_USING_CACHE) */
}

/*****************************************************************************
 * FUNCTION
 *  ExitCategory219Screen
 * DESCRIPTION
 *  Exit category 214
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategory219Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    reset_pop_up_descriptions();
    reset_asyncdynamic_matrix();    

#if defined(FMGR_USING_CACHE)
    if (g_fmgr_cache_p != NULL)
    {
        wgui_cat_fmgr_cache_free_all();
    }
#endif /* #if defined(FMGR_USING_CACHE) */

    /* hide image callback */
    if (cat214_hide_image_callback != NULL)
    {
        cat214_hide_image_callback(0);
    }
#if defined(FMGR_USING_CACHE)
    if (g_fmgr_cache_p != NULL)
    {
        g_fmgr_cache_p->cur_decode_p = NULL;
        g_fmgr_cache_p = NULL;
    }
#endif 

    g_cat214_highlight_layer = WGUI_CAT214_HIGHLIGHT_NORMAL;

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif
     g_cat_fmgr_get_async_item_func = NULL;
     g_cat_fmgr_get_async_hint_func = NULL;
#if defined(FMGR_USING_CACHE) 
     wgui_cat219_decode_done_hdlr = NULL;
#endif
     MMI_fixed_matrix_menu.flags &= ~UI_DYAMIC_MATRIX_MENU_ALIGN_LEFT_TOP;
}

#endif /*__MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__*/
void ShowCategory219Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        U16 num_of_items,
        Cat214DrawImageFuncPtr draw_image_callback,
        Cat214HideImageFuncPtr hide_image_callback,
        U8 num_per_row,
        U8 num_per_col,
        S32 highlighted_item,
        U8 *history_buffer,
        S32 *category_error_flag)
{
#ifdef __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__

    ShowCategory219Screen_int(
        (WCHAR *)get_string(title),
        (PU8)get_image(title_icon),
        left_softkey,
        right_softkey,
        num_of_items,
        draw_image_callback,
        hide_image_callback,
        num_per_row,
        num_per_col,
        highlighted_item,
        history_buffer,
        NULL,
        category_error_flag);
#endif /* __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__ */
}
/*****************************************************************************
 * FUNCTION
 *  ShowCategory219Screen
 * DESCRIPTION
 *  Show category 219 screen.
 * PARAMETERS
 *  title                   [IN]        Title string id
 *  title_icon              [IN]        Title image id
 *  left_softkey            [IN]        Lsk string id
 *  left_softkey_icon       [IN]        Lsk image id
 *  right_softkey           [IN]        Rsk string id
 *  right_softkey_icon      [IN]        Rsk image id
 *  num_of_items            [IN]        How many items
 *  draw_image_callback     [IN]        Callback function to draw image
 *  hide_image_callback     [IN]        Callback function to hide
 *  num_per_row             [IN]        Num of image pre row
 *  num_per_col             [IN]        Num of image pre col
 *  highlighted_item        [IN]        Highlighted item
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory219Screen_int(
        WCHAR *title,
        PU8 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        U16 num_of_items,
        Cat214DrawImageFuncPtr draw_image_callback,
        Cat214HideImageFuncPtr hide_image_callback,
        U8 num_per_row,
        U8 num_per_col,
        S32 highlighted_item,
        U8 *history_buffer,
        WCHAR *empty_string,
        S32 *category_error_flag)
{
#ifdef __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 h_flag;
    S32 i_width, i_height;
    S32 tool_bar_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* arg checking */
    MMI_ASSERT(num_per_row != 0);
    MMI_ASSERT(num_per_col != 0);

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif
    
    /* Show shortcut when fullscreen backgournd */
    wgui_title_set_no_icon_shct(MMI_TRUE);

    gui_setup_submenu_layout();

    cat214_draw_image_callback = draw_image_callback;
    cat214_hide_image_callback = hide_image_callback;

    wgui_title_set_menu_shortcut_number(-1);

    gdi_layer_lock_frame_buffer();

    /* init highligthed item idx */
    MMI_fixed_list_menu.n_items = num_of_items;

    /* shortcut */
    register_menu_shortcut_keys();
    set_menu_item_count(num_of_items);

    //dm_add_title_id(title, title_icon);
    dm_add_title((UI_string_type)title, title_icon);
    dm_add_softkey_id(left_softkey, right_softkey);
    wgui_asyncdynamic_matrix_create_icontext_list_menu(
        num_of_items,
        1,
        0,
        Cat219AsyncGetItemCallback,
        Cat217AsyncGetHintCallback,
        WGUI_LIST_INVALID_HIGHLIGHT,
        0,
        0,
        0,
        NULL);
#ifdef __MMI_ICON_BAR_SUPPORT__
#if defined(__MMI_FTE_SUPPORT__)
    if(MMI_TRUE == wgui_icon_bar_is_created())
    {
        tool_bar_height = MMI_ICON_BAR_HEIGHT;
    }
#endif
#endif /*__MMI_ICON_BAR_SUPPORT__*/
    set_fixed_icontext_list_text_coordinates(0, 0, 0, 0, 0);/* disable list show loading" */

    resize_fixed_matrix(MMI_content_width, MMI_content_height - tool_bar_height);   
    if (num_of_items > (num_per_col*num_per_row))
    {
#if defined(__MMI_FTE_SUPPORT__)
        i_width = (MMI_content_width - UI_SCROLLBAR_WIDER_WIDTH)/num_per_col;
#else
        i_width = (MMI_content_width - current_MMI_theme->scrollbar_size)/num_per_col;
#endif
}
    else
    {
        i_width = MMI_content_width/num_per_col;
    }
    i_height = ((MMI_content_height - tool_bar_height)/num_per_row);
    
    configure_fixed_matrix(i_width, i_height, num_per_col, num_per_row);

    image_box_width = i_width - WGUI_CAT_FMGR_MATRIX_BORDER_PIXEL * 2;
    image_box_height = i_height - WGUI_CAT_FMGR_MATRIX_BORDER_PIXEL * 2;

#if defined(FMGR_USING_CACHE)    
    if (g_fmgr_cache_p != NULL)
    {
        g_fmgr_cache_p->cache_pre_page= num_per_row*num_per_col;
        g_fmgr_cache_p->prev_first_displayed_item = -1;
        g_fmgr_cache_p->highlight_index = highlighted_item;
    }
#endif /* #if defined(FMGR_USING_CACHE) */

    MMI_fixed_matrix_menu.flags |= UI_DYAMIC_MATRIX_MENU_ALIGN_LEFT_TOP|UI_MATRIX_MENU_LOOP;

    MMI_fixed_matrix_menu.item_highlight_function = wgui_cat219_highilight_item;
    MMI_fixed_matrix_menu.item_display_function = wgui_cat214_show_item;

    h_flag = set_matrix_menu_category_history(MMI_CATEGORY219_ID, history_buffer);
    if (!h_flag)
    {
         MMI_fixed_matrix_menu.highlighted_item = highlighted_item;
    }

    if( MMI_fixed_matrix_menu.highlighted_item > (num_of_items - 1))
    {
        MMI_fixed_matrix_menu.highlighted_item = num_of_items - 1;
    }
    MMI_fixed_list_menu.highlighted_item = MMI_fixed_matrix_menu.highlighted_item;

    asyncdynamic_matrix_goto_item_no_redraw(MMI_fixed_matrix_menu.highlighted_item);

    gdi_layer_unlock_frame_buffer();

    wgui_cat_setup_category_default_history(
        MMI_CATEGORY219_ID,
        DM_CLEAR_SCREEN_BACKGROUND,
        ExitCategory219Screen);
    dm_redraw_category_screen();
    
    if (num_of_items == 0)
    {
        wgui_cat_fmgr_show_empty_string(empty_string);
    }    
#endif /*__MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__ */
}

void ShowCategory219FmgrScreen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        U16 num_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        CatFmgrGetFileData get_menuitem_data,
        CatFmgrHideFileData hide_menuitem_data,
        U8 num_per_row,
        U8 num_per_col,
        S32 highlighted_item,
        U8 *history_buffer,
        S32 *category_error_flag)
{
#ifdef __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__

    ShowCategory219FmgrScreen_ext(
        (WCHAR*)get_string(title),
        (PU8)get_image(title_icon),
        left_softkey,
        right_softkey,
        num_of_items,
        get_item_func,
        get_hint_func,
        get_menuitem_data,
        hide_menuitem_data,
        num_per_row,
        num_per_col,
        highlighted_item,
        history_buffer,
        NULL,
        category_error_flag);
#endif
}
void ShowCategory219FmgrScreen_ext(
        WCHAR* title,
        PU8 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        U16 num_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        CatFmgrGetFileData get_menuitem_data,
        CatFmgrHideFileData hide_menuitem_data,
        U8 num_per_row,
        U8 num_per_col,
        S32 highlighted_item,
        U8 *history_buffer,
        WCHAR* empty_string,
        S32 *category_error_flag)
{
#ifdef __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__
#if defined(FMGR_USING_CACHE)
    S32 number;

    memset(&g_214_fmgr, 0, sizeof(g_214_fmgr));
    g_fmgr_cache_p= &(g_214_fmgr.cache);

    number = num_of_items/(WGUI_CAT_FMGR_CACHE_SEARCH_POINT_NUM-1);
    g_fmgr_cache_p->cache_num = 1;
    do{
        g_fmgr_cache_p->cache_num = g_fmgr_cache_p->cache_num<<1;
    }while(number >= g_fmgr_cache_p->cache_num);
    
    g_fmgr_cache_p->cache_num = g_fmgr_cache_p->cache_num<<1;
    g_cat214_highlight_layer = WGUI_CAT214_HIGHLIGHT_LAYER_TOP;
#endif /* #if defined(FMGR_USING_CACHE) */

    g_fmgr_struct_p = &(g_214_fmgr.fmgr_struct);
    g_fmgr_struct_p->fmgr_style = MMI_FMGR_GUI_MATRIX_STYLE;

    wgui_cat_fmgr_get_menuitem = get_menuitem_data;
    wgui_cat_fmgr_hide_menuitem = hide_menuitem_data; 

    g_cat_fmgr_get_async_item_func = get_item_func;
    g_cat_fmgr_get_async_hint_func = get_hint_func;

    ShowCategory219Screen_int(
            title,
            title_icon,
            left_softkey,
            right_softkey,
            num_of_items,
            wgui_cat214_fmgr_draw_menuitem_matrix,
            wgui_cat214_fmgr_hide_menuitem_matrix,
            num_per_row,
            num_per_col,
            highlighted_item,
            history_buffer,
            empty_string, 
            category_error_flag);

#if defined(FMGR_USING_CACHE)
    if (g_fmgr_cache_p->cur_decode_p == NULL && num_of_items != 0)
    {
        g_fmgr_cache_p->first_displayed_item = (MMI_fixed_matrix_menu.first_displayed_row*MMI_fixed_matrix_menu.displayed_columns 
                                                + MMI_fixed_matrix_menu.first_displayed_column);
        wgui_cat_fmgr_cache_list_decoding_next(g_fmgr_cache_p->first_displayed_item);
    }
#endif /* #if defined(FMGR_USING_CACHE) */

#endif
}

/*************************************************File manager Function********************************************************/

#if defined(__MMI_CAT216_CAT212_SUPPORT_FMGR__) || defined(__MMI_CAT217_CAT213_SUPPORT_FMGR__)
/*****************************************************************************
 * FUNCTION
 *  wgui_fmgr_draw_hilight_menuitem_bg
 * DESCRIPTION
 *  call back function for draw hilight menuitem, used by scrolling text
 * PARAMETERS
 *  x1      [IN]        X1
 *  y1      [IN]        Y1
 *  x2      [IN]        X2
 *  y2      [IN]        Y2
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_fmgr_draw_hilight_menuitem_bg(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_filled_area *f;
    S32 count = 0;
    S32 pos_x, pos_y, width, height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_fixed_list_get_style() == GUI_MENU_TYPE_ASYNCDYNAMIC)
    {
        pos_x = GUI_current_fixed_icontext_list_menuitem_x;
        pos_y = GUI_current_fixed_icontext_list_menuitem_y;
        width = MMI_fixed_icontext_list_menuitem.width;
        height = MMI_fixed_icontext_list_menuitem.height;       
    }
    else
    {
        pos_x = GUI_current_fixed_icontext_menuitem_x, 
        pos_y = GUI_current_fixed_icontext_menuitem_y;
        width = MMI_fixed_icontext_menuitem.width;
        height = MMI_fixed_icontext_menuitem.height;      
    }

    if (g_fmgr_struct_p->fmgr_style == MMI_FMGR_GUI_HILITE_STYLE)
    {
        height *= 2;
    }

    if ((MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_SCROLLBAR) ||
        ((MMI_fixed_list_menu.flags & UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR) && 
         (MMI_fixed_list_menu.displayed_items >= MMI_fixed_list_menu.n_items)))
    {
        if (g_fmgr_struct_p->fmgr_style == MMI_FMGR_GUI_HILITE_STYLE)
        {
            f = current_MMI_theme->menuitem_two_line_highlight_filler;//menuitem_two_line_highlight_without_scroll_filler
        }
        else
        {
            f =  MMI_fixed_icontext_menuitem.focussed_without_sc_filler;
        }
    }
    else
    {
        if (g_fmgr_struct_p->fmgr_style == MMI_FMGR_GUI_HILITE_STYLE)
        {
            f = current_MMI_theme->menuitem_two_line_highlight_filler;
        }
        else
        {
            f = MMI_fixed_icontext_menuitem.selected_filler;
        }
    }
    
    
    /* check if background decoding finish: yes then start to scroll */
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    
#if defined(__MMI_UI_LIST_SLIDE_EFFECT__)
    if (g_slide_effect->state != GUI_EFFECT_STATE_RUNNING
#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_KEY)
        && !gui_in_ssk
#endif
       )
#endif /* __MMI_UI_LIST_SLIDE_EFFECT__ */
    {
        gdi_image_get_frame_count(f->b, &count);
        if (f->flags & UI_FILLED_AREA_TYPE_BITMAP && f->b && (count > 1) &&
            (f->b[0] == GDI_IMAGE_TYPE_PNG_SEQUENCE || f->b[0] == GDI_IMAGE_TYPE_ABM_SEQUENCE || 
            f->b[0] == GDI_IMAGE_TYPE_AB2_SEQUENCE || 
            f->b[0] == GDI_IMAGE_TYPE_PNG_SEQUENCE_FILE_OFFSET ||
            f->b[0] == GDI_IMAGE_TYPE_ABM_SEQUENCE_FILE_OFFSET || 
            f->b[0] == GDI_IMAGE_TYPE_AB2_SEQUENCE_FILE_OFFSET))
        {
            gdi_draw_solid_rect(            
                pos_x, 
                pos_y, 
                pos_x + width -1,
                pos_y + height -1,  
                GDI_COLOR_TRANSPARENT);
            gdi_image_draw_frames(pos_x, pos_y, f->b, count - 1);
        }
        else
        {
            gui_draw_filled_area(
                pos_x, 
                pos_y, 
                pos_x + width -1,
                pos_y + height -1, 
                f);
        }
    }
    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_fmgr_draw_hilight_menuitem_bg_callback
 * DESCRIPTION
 *  call back function for draw hilight menuitem, used by scrolling text
 * PARAMETERS
 *  x1      [IN]        X1
 *  y1      [IN]        Y1
 *  x2      [IN]        X2
 *  y2      [IN]        Y2
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_fmgr_draw_hilight_menuitem_bg_callback(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_filled_area *f;
    S32 count = 0;
    S32 pos_x, pos_y, menu_width, menu_height;
    S32 temp_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_fixed_list_get_style() == GUI_MENU_TYPE_ASYNCDYNAMIC)
    {
        pos_x = GUI_current_fixed_icontext_list_menuitem_x;
        pos_y = GUI_current_fixed_icontext_list_menuitem_y;
        menu_width = MMI_fixed_icontext_list_menuitem.width;
        menu_height = MMI_fixed_icontext_list_menuitem.height;
    }
    else
    {
        pos_x = GUI_current_fixed_icontext_menuitem_x, 
        pos_y = GUI_current_fixed_icontext_menuitem_y;
        menu_width = MMI_fixed_icontext_menuitem.width;
        menu_height = MMI_fixed_icontext_menuitem.height;
    }

    if ((MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_SCROLLBAR) ||
        ((MMI_fixed_list_menu.flags & UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR) && 
         (MMI_fixed_list_menu.displayed_items >= MMI_fixed_list_menu.n_items)))
    {
        if (g_fmgr_struct_p->fmgr_style == MMI_FMGR_GUI_HILITE_STYLE)
        {
            f = current_MMI_theme->menuitem_two_line_highlight_filler;//menuitem_two_line_highlight_without_scroll_filler
        }
        else
        {
			if (wgui_fixed_list_get_style() == GUI_MENU_TYPE_ASYNCDYNAMIC)
			{
				f =  MMI_fixed_icontext_list_menuitem.focussed_without_sc_filler;
			}
			else
			{
                f =  MMI_fixed_icontext_menuitem.focussed_without_sc_filler;
            }
        }
    }
    else
    {
        if (g_fmgr_struct_p->fmgr_style == MMI_FMGR_GUI_HILITE_STYLE)
        {
            f = current_MMI_theme->menuitem_two_line_highlight_filler;
        }
        else
        { 
			if (wgui_fixed_list_get_style() == GUI_MENU_TYPE_ASYNCDYNAMIC)
			{
				f = MMI_fixed_icontext_list_menuitem.selected_filler;
			}
			else
			{
                f = MMI_fixed_icontext_menuitem.selected_filler;
            }
        }
    }
    
    /* check if background decoding finish: yes then start to scroll */
#if 0//defined(FMGR_USING_CACHE)
/* under construction !*/
#endif
    {
#if defined(__MMI_UI_LIST_SLIDE_EFFECT__)
        if (g_slide_effect->state != GUI_EFFECT_STATE_RUNNING
#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_KEY)
            && !gui_in_ssk
#endif
           )
#endif /* __MMI_UI_LIST_SLIDE_EFFECT__ */
        {
            gui_push_clip();
            temp_y2 = y2;
            if (g_fmgr_struct_p->fmgr_style == MMI_FMGR_GUI_LIST_STYLE)
            {
                if(temp_y2 > (MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1))
                {
                    temp_y2 = (MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1);
                }
            }
            gui_set_clip(x1, y1, x2, temp_y2);

            gdi_image_get_frame_count(f->b, &count);
            if (f->flags & UI_FILLED_AREA_TYPE_BITMAP && f->b && (count > 1) &&
                (f->b[0] == GDI_IMAGE_TYPE_PNG_SEQUENCE || f->b[0] == GDI_IMAGE_TYPE_ABM_SEQUENCE || 
                f->b[0] == GDI_IMAGE_TYPE_AB2_SEQUENCE || 
                f->b[0] == GDI_IMAGE_TYPE_PNG_SEQUENCE_FILE_OFFSET ||
                f->b[0] == GDI_IMAGE_TYPE_ABM_SEQUENCE_FILE_OFFSET || 
                f->b[0] == GDI_IMAGE_TYPE_AB2_SEQUENCE_FILE_OFFSET))
            {
                gdi_draw_solid_rect(            
                    pos_x, 
                    pos_y, 
                    pos_x + menu_width -1,
                    pos_y + menu_height -1,  
                    GDI_COLOR_TRANSPARENT);
                gdi_image_draw_frames(pos_x, pos_y, f->b, count - 1);
            }
            else
            {
                gui_draw_filled_area(
                    pos_x, 
                    pos_y, 
                    pos_x + menu_width -1,
                    pos_y + menu_height -1, 
                    f);
            }
            gui_pop_clip();
        }
    }
}




/*****************************************************************************
 * FUNCTION
 *  wgui_fmgr_draw_hilight_menuitem_timer_callback
 * DESCRIPTION
 *  draw hilight menuitem text, callback function for scrolling text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_fmgr_draw_hilight_menuitem_timer_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_handle_scrolling_text(&fmgr_cat_context.scroll_text);
}
#endif /*defined(__MMI_CAT216_CAT212_SUPPORT_FMGR__) || defined(__MMI_CAT217_CAT213_SUPPORT_FMGR__)*/


static void wgui_fmgr_redraw_image_background(BOOL is_hilighted, U16 ui_style, 
                                             gdi_color bg_color, S32 x1, S32 y1, S32 x2, S32 y2)
{
#if defined(__MMI_CAT216_CAT212_SUPPORT_FMGR__) || defined(__MMI_CAT217_CAT213_SUPPORT_FMGR__)
    if (ui_style == MMI_FMGR_GUI_LIST_STYLE || ui_style == MMI_FMGR_GUI_HILITE_STYLE)
    {
#if defined(__MMI_UI_LIST_SCROLL_BY_PIXEL__)
        if (ui_style == MMI_FMGR_GUI_LIST_STYLE)
        {
            S32 layer_w, layer_h;
            gdi_layer_get_dimension(&layer_w, &layer_h);
                //if(!gui_screen_smooth_scrolling_moved_by_pen() && (node_p->index == MMI_fixed_list_menu.first_displayed_item) && (MMI_fixed_list_menu.first_displayed_offset > 0))
            if((layer_h == UI_device_height) && (MMI_fixed_list_menu.first_displayed_offset > 0))        
            {
                S32 temp_x1, temp_y1, temp_x2, temp_y2;
                if(y1 < MMI_fixed_list_menu.y)
                {
                    y1 = MMI_fixed_list_menu.y;
                }
                gui_get_clip(&temp_x1, &temp_y1, &temp_x2, &temp_y2);
                y1 = y1 > temp_y1 ? y1 : temp_y1;
                if(y2 < MMI_fixed_list_menu.y)
                {
                    return;
    
                }
            }
        }
#endif

        if(is_hilighted)
        wgui_fmgr_draw_hilight_menuitem_bg(x1, y1, x2, y2);
        else
        gdi_draw_solid_rect(x1, y1, x2, y2, bg_color);
    }
    else
#endif
    if (ui_style == MMI_FMGR_GUI_MATRIX_STYLE)
    {
#if defined(__MMI_MAINLCD_128X128__) || defined(__SOCIAL_NETWORK_SUPPORT__) || defined(__MMI_FTE_SUPPORT__)
        gdi_draw_solid_rect(x1, y1, x2, y2, bg_color);
#else
        FillFullTextBackground(x1, y1, x2, y2);
#endif
    }
    else
    {
#ifdef __MMI_MAINLCD_128X128__
        gdi_draw_solid_rect(x1, y1, x2, y2, bg_color);
#else
        FillFullTextBackground(x1, y1, x2, y2);
#endif
        
    }
}

static gdi_color wgui_fmgr_get_bg_color(BOOL is_hilighted, U16 ui_style)
{
    gdi_color bg_color = GDI_COLOR_BLACK;
    color *color_ptr;
#if defined(__MMI_CAT216_CAT212_SUPPORT_FMGR__) || defined(__MMI_CAT217_CAT213_SUPPORT_FMGR__)
    if (ui_style == MMI_FMGR_GUI_LIST_STYLE || ui_style == MMI_FMGR_GUI_HILITE_STYLE)
    {
        /* get color from theme */
        if (is_hilighted)
        {
            color_ptr = &(current_MMI_theme->list_selected_item_filler->c);
            bg_color = gdi_act_color_from_rgb(255,color_ptr->r, color_ptr->g, color_ptr->b);
        }
        else
        {
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
            bg_color = GDI_COLOR_TRANSPARENT;
#else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */ /* __MMI_MAINLCD_240X320__ */
            color_ptr = &(current_MMI_theme->list_background_filler->c);
            bg_color = gdi_act_color_from_rgb(255,color_ptr->r, color_ptr->g, color_ptr->b);
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */ /* __MMI_MAINLCD_240X320__ */
        }
    }
    else if (ui_style == MMI_FMGR_GUI_INFO_STYLE)
    {
        /* this bg color is the same in wgui_categories_fmgr.c's RedrawCategory212Screen() */
        bg_color = gdi_act_color_from_rgb(255,255, 255, 255);
    }
    else
#endif /* defined(__MMI_CAT216_CAT212_SUPPORT_FMGR__) || defined(__MMI_CAT217_CAT213_SUPPORT_FMGR__)*/
    if (ui_style == MMI_FMGR_GUI_MATRIX_STYLE)
    {
    	#ifndef __SOCIAL_NETWORK_SUPPORT__
        if (is_hilighted)
        {
            color_ptr = &(current_MMI_theme->list_selected_item_filler->c);
            bg_color = gdi_act_color_from_rgb(255,color_ptr->r, color_ptr->g, color_ptr->b);
        }
        else
        {
            color_ptr = &(current_MMI_theme->list_background_filler->c);
            bg_color = gdi_act_color_from_rgb(255,color_ptr->r, color_ptr->g, color_ptr->b);
        }
        #else
        	bg_color = gdi_act_color_from_rgb(255, 8, 60, 74);
        #endif
        
    }
    
    return bg_color;
}

void wgui_cat219_register_decode_done_hdlr(Cat219DecodeDoneHdlr decode_done_hdlr)
{
#if defined(FMGR_USING_CACHE)  
    wgui_cat219_decode_done_hdlr = decode_done_hdlr;
#endif
}
MMI_BOOL wgui_cat219_get_index_is_cached(S32 index)
{
   #if defined(FMGR_USING_CACHE)
    wgui_cat_fmgr_cache_node *current_node_p = NULL;
    if (wgui_cat_fmgr_is_cached(index, &current_node_p))
        return MMI_TRUE;
    else
   #endif
   return MMI_FALSE; 
}

void wgui_cat21x_register_set_displayable(wgui_fmgr_set_displayable_func set_displayable)
{
#if defined(FMGR_USING_CACHE)    
    wgui_cat21x_set_displayable = set_displayable;
#endif /* defined(FMGR_USING_CACHE) */ 
}

void wgui_cat21x_register_get_displayable(wgui_fmgr_get_displayable_func get_displayable)
{
#if defined(FMGR_USING_CACHE)    
    wgui_cat21x_get_displayable = get_displayable;
#endif /* defined(FMGR_USING_CACHE) */ 
}

void wgui_cat21x_register_get_thumb_image(wgui_fmgr_get_thumb_image_func get_thumb_image)
{
#if defined(FMGR_USING_CACHE)
    wgui_cat21x_get_image_path_callback = get_thumb_image;
#endif /* defined(FMGR_USING_CACHE) */ 
}
#ifdef __MMI_CAT216_CAT212_SUPPORT_FMGR__
void wgui_cat212_fmgr_hide_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat212_fmgr_hide_data_info_ptr();
    /* End the decoding item, but not free it, just set the flag to NONE */
#if defined(FMGR_USING_CACHE)
    if (g_fmgr_cache_p != NULL)
    {
        wgui_fmgr_cache_stop_decoder();
    }
#endif /* #if defined(FMGR_USING_CACHE) */

    /* stop all animations */
    /* gdi_image_stop_animation_all(); */
    
}


void wgui_cat212_fmgr_draw_info(S32 item_idx, S32 x1, S32 y1, S32 x2, S32 y2)
{
    S32 image_width;
    S32 image_height;
    S32 char_height;
    S32 str_width, str_height;
    S32 box_width = 0, box_height = 0;
    S32 box_offset_x = 0, box_offset_y = 0;
   
    S32 spacing;
    S32 line1_size_str_offset_y = 0;
    S32 line2_size_str_offset_y = 0;
    S32 line1_size_offset_y = 0;
    S32 line2_size_offset_y = 0;
    S32 left_align_offset_x = 0;
    S32 right_align_offset_x = 0;    
    MMI_BOOL is_displayable = MMI_TRUE;
	S32 scrollbar_size = 0;

    wgui_fmgr_info_struct fmgr_info;

    scrollbar_size = current_MMI_theme->scrollbar_size;

    memset(&fmgr_info, 0, sizeof(wgui_fmgr_info_struct));
    wgui_cat212_fmgr_get_info_ptr(item_idx, &fmgr_info);

    /* lock and push clip */
    gui_lock_double_buffer();
    gui_push_text_clip();
    gui_push_clip();
    
    gui_reset_clip();
    gui_reset_text_clip();

    if (fmgr_info.info_type == WGUI_CAT21X_INFO_TYPE_DRV)
    {
        /*----------------------------------------------------------------*/
        /* Calcuate text position                                         */
        /*----------------------------------------------------------------*/
        box_height = y2 - y1 + 1;
        box_width = x2 - x1 + 1;

        gui_set_font(&MMI_medium_font);

        spacing = box_height;
        gui_measure_string((UI_string_type) GetString(STR_ID_FMGR_DRV_FREE_SPACE), &str_width, &char_height);
        spacing -= char_height;
        gui_measure_string((UI_string_type) GetString(STR_ID_FMGR_DRV_TOTAL_SPACE), &str_width, &char_height);
        spacing -= char_height;
        if(spacing < 0)
            spacing = 0;
        str_height = spacing % 3;
        spacing = spacing / 3;

        line1_size_str_offset_y = str_height + spacing + y1;
        line2_size_str_offset_y = str_height + spacing * 2 + char_height + y1;

        char_height = gui_get_string_height((UI_string_type) L"1");
        str_height = (box_height - char_height * 2) % 3;
        spacing = (box_height - char_height * 2) / 3;

        line1_size_offset_y = str_height + spacing + y1;
        line2_size_offset_y = str_height + spacing * 2 + char_height + y1;

        
#if !defined(__MMI_SLIM_FILE_MANAGER__)
#if defined(__MMI_FTE_SUPPORT__)&& !defined(__COSMOS_MMI_PACKAGE__)
		gdi_image_get_dimension((PU8)GetImage(IMG_ID_FMGR_DRIVE_SPACE_0), &image_width, &image_height);
#else
        gdi_image_get_dimension(fmgr_info.file_icon_ptr, &image_width, &image_height);
#endif
        left_align_offset_x = x1 + image_width + 8;
        right_align_offset_x = x2 - image_width - 8;
#else /* !defined(__MMI_SLIM_FILE_MANAGER__) */ 
        left_align_offset_x = x1 + box_height + 8;
        right_align_offset_x = x2 - box_height - 8;
#endif /* !defined(__MMI_SLIM_FILE_MANAGER__) */     
    }
    else if (fmgr_info.info_type == WGUI_CAT21X_INFO_TYPE_FILE)
    {
        /*-------------------------*/
        /* Calculate text position */
        /*-------------------------*/
        box_height = y2 - y1 - FMGR_UI_IMAGE_BOX_SPACING * 2 + 1;
        box_width = box_height;

        box_offset_y = FMGR_UI_IMAGE_BOX_SPACING;

        if (mmi_fe_get_r2l_state())
        {
            box_offset_x = x2 - box_width - FMGR_UI_IMAGE_BOX_SPACING;
        }
        else
        {
            box_offset_x = FMGR_UI_IMAGE_BOX_SPACING;
        }

        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_font(&MMI_medium_font);

        char_height = gui_get_string_height((UI_string_type) GetString(STR_ID_FMGR_FILE_DATE));
        spacing = (y2 - y1 - 1 - char_height * 2) / 3;

        line1_size_str_offset_y = spacing + y1 + 1;   /* +1 make it looks better */
        line2_size_str_offset_y = spacing * 2 + char_height + y1 + 1; /* +1 make it looks better */

        char_height = gui_get_string_height((UI_string_type) L"1");
        spacing = (y2 - y1 - 1 - char_height * 2) / 3;

        line1_size_offset_y = spacing + y1 + 1;       /* +1 make it looks better */
        line2_size_offset_y = spacing * 2 + char_height + y1 + 1;     /* +1 make it looks better */

        left_align_offset_x = box_offset_x + box_width + FMGR_UI_TEXT_SPACING;
        right_align_offset_x = box_offset_x - FMGR_UI_TEXT_SPACING;
    }
    else
    {
        ASSERT(0);
    }

    gui_set_text_color(current_header_information_text_theme->text_color);
    /*----------------------------------------------------------------*/
    /* Draw Total Size                                                */
    /*----------------------------------------------------------------*/
    if (fmgr_info.info_text_l1_s1 != NULL)
    {
		S32 l1_s2_str_width, l1_s2_str_height;
		gui_measure_string(fmgr_info.info_text_l1_s2, &l1_s2_str_width, &l1_s2_str_height);

        gui_reset_text_clip();

        if (mmi_fe_get_r2l_state())
        {
            //gui_move_text_cursor(right_align_offset_x, line1_size_str_offset_y);
			gui_print_truncated_text(right_align_offset_x, line1_size_str_offset_y,
				x2 - left_align_offset_x - l1_s2_str_width - 2, fmgr_info.info_text_l1_s1);
        }
        else
        {
           // gui_move_text_cursor(left_align_offset_x, line1_size_str_offset_y);
			gui_print_truncated_text(left_align_offset_x, line1_size_str_offset_y,
				x2 - left_align_offset_x - l1_s2_str_width - scrollbar_size, fmgr_info.info_text_l1_s1);
        }
       // gui_print_text(fmgr_info.info_text_l1_s1);
       // gui_measure_string(fmgr_info.info_text_l1_s2, &str_width, &str_height);
        wgui_cat_fmgr_print_text(
            x1 + l1_s2_str_width + 2,
            x2 - l1_s2_str_width - scrollbar_size,
            line1_size_str_offset_y,
            fmgr_info.info_text_l1_s2);

    }


    /*----------------------------------------------------------------*/
    /* Draw Free Size                                                 */
    /*----------------------------------------------------------------*/
    if (fmgr_info.info_text_l2_s1 != NULL)
    {
		S32 l2_s2_str_width, l2_s2_str_height;
		gui_measure_string(fmgr_info.info_text_l2_s2, &l2_s2_str_width, &l2_s2_str_height);
        if (mmi_fe_get_r2l_state())
        {
            //gui_move_text_cursor(right_align_offset_x, line2_size_str_offset_y);
			gui_print_truncated_text(right_align_offset_x, line2_size_str_offset_y,
				x2 - left_align_offset_x - l2_s2_str_width - 2, fmgr_info.info_text_l2_s1);
        }
        else
        {
			gui_print_truncated_text(left_align_offset_x, line2_size_str_offset_y,
				x2 - left_align_offset_x - l2_s2_str_width - scrollbar_size, fmgr_info.info_text_l2_s1);
        }
        wgui_cat_fmgr_print_text(
            x1 + l2_s2_str_width + 2,
            x2 - l2_s2_str_width - scrollbar_size,
            line2_size_offset_y,
            fmgr_info.info_text_l2_s2);
    }
    
    /*----------------------------------------------------------------*/
    /* Draw Icon                                                      */
    /*----------------------------------------------------------------*/
#if defined(FMGR_USING_CACHE)   
    if (g_fmgr_cache_p != NULL)
    {        
        wgui_cat_fmgr_set_cache_pos(
            item_idx, 
            MMI_fixed_list_menu.first_displayed_item, 
            g_fmgr_cache_p, 
            x1 + box_offset_x,
            y1 + box_offset_y);
    }
#endif /* #if defined(FMGR_USING_CACHE) */
#if defined(FMGR_USING_CACHE) 
    if(wgui_cat21x_get_displayable != NULL)
    {
        is_displayable = wgui_cat21x_get_displayable(item_idx);
    }
#endif

    if (fmgr_info.info_type == WGUI_CAT21X_INFO_TYPE_FILE && fmgr_info.is_show_thumb == MMI_TRUE && is_displayable)
    {
        wgui_fmgr_menuitem_data_struct menuitem_data;
        
        /* type is file, and thumb image is right. */
        menuitem_data.is_show_thumb = fmgr_info.is_show_thumb;
        menuitem_data.file_icon_ptr = fmgr_info.file_icon_ptr;
        
        wgui_cat_fmgr_show_img(
            item_idx, 
            TRUE, 
            &menuitem_data, 
            x1 + box_offset_x, 
            y1 + box_offset_y, 
            x1 + box_offset_x + box_width - 1, 
            y1 + box_offset_y + box_height - 1);    
        
    }
    else
    {
        if (fmgr_info.info_type == WGUI_CAT21X_INFO_TYPE_DRV)
        {
            if (mmi_fe_get_r2l_state())
            {
                wgui_fmgr_draw_free_space_icon(right_align_offset_x + 4, y1, box_height, fmgr_info.drv_ratio, fmgr_info.file_icon_ptr);
            }
            else
            {
                wgui_fmgr_draw_free_space_icon(x1 + 4, y1, box_height, fmgr_info.drv_ratio, fmgr_info.file_icon_ptr);
            }
        }
        else if (fmgr_info.info_type == WGUI_CAT21X_INFO_TYPE_FILE)
        {
            S32 icon_offset_x, icon_offset_y;

            gui_measure_image(fmgr_info.file_icon_ptr, &image_width, &image_height);
            icon_offset_x = ((box_width - image_width) >> 1) + x1 + box_offset_x;
            icon_offset_y = ((box_height - image_height) >> 1) + y1 + box_offset_y;
            gdi_image_draw(icon_offset_x, icon_offset_y, fmgr_info.file_icon_ptr);
        }
    }

    /* pop clip , unlock and blt */
    gui_pop_clip();
    gui_pop_text_clip();
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
}

#endif /*__MMI_CAT216_CAT212_SUPPORT_FMGR__*/

#ifdef __MMI_CAT217_CAT213_SUPPORT_FMGR__

void wgui_cat213_fmgr_hide_menuitem(void)
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop scroll text */
    gui_scrolling_text_stop(&fmgr_cat_context.scroll_text);

    /* End the decoding item, but not free it, just set the flag to NONE */
#if defined(FMGR_USING_CACHE)
    if (g_fmgr_cache_p != NULL)
    {
        wgui_fmgr_cache_stop_decoder();
    }
#endif /* #if defined(FMGR_USING_CACHE) */

    wgui_cat_fmgr_hide_menuitem();
}


extern MMI_BOOL wgui_list_get_slow_data_mode(void);
/*****************************************************************************
 * FUNCTION
 *  wgui_cat213_fmgr_draw_menuitem
 * DESCRIPTION
 *  Category 213 draw menu item
 * PARAMETERS
 *  item_idx            [IN]        Index
 *  is_hilighted        [IN]        Hilight flag
 *  x1                  [IN]        X1
 *  y1                  [IN]        Y1
 *  x2                  [IN]        X2
 *  y2                  [IN]        Y2
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat213_fmgr_draw_menuitem(S32 item_idx, BOOL is_hilighted, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 left_align_offset_x;
    S32 str_width, str_height;
    S32 small_font_height;
    S32 medium_font_height;
    S32 text_spacing;
    S32 r2l_x1;
    S32 text_w;
    S32 filename_offset_y;    
    S32 date_size_offset_y;
    color text_color;
    S32 box_offset_x;
    S32 box_offset_y;
    S32 box_width;
    S32 box_height;
    S32 image_offset_x;
    S32 image_offset_y;

    S32 image_width;
    S32 image_height;

    MMI_BOOL is_displayable = MMI_TRUE;

    wgui_fmgr_menuitem_data_struct menuitem_data;
    S32 text_box_y1;
    S32 text_box_y2;
    S32 right_align_offset_x;
    S32 menuitem_height;
    S32 drv_name_offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetExitScrnID() != GetActiveScreenId())
    {
        return;
    }

    memset(&menuitem_data, 0, sizeof(wgui_fmgr_menuitem_data_struct));
    if (wgui_list_get_slow_data_mode() && gui_screen_smooth_scrolling_in_freerun())
    {
        /* Use loading directly */
        menuitem_data.is_show_thumb = MMI_FALSE;
        menuitem_data.info_type = WGUI_CAT21X_INFO_TYPE_FILE;
        mmi_ucs2cpy((S8*)menuitem_data.menu_text_l1_s1, (S8*)GetString(STR_GLOBAL_LOADING));
        menuitem_data.file_icon_ptr = NULL;
    }
    else
    {
        /* Get data from application */
        wgui_cat_fmgr_get_menuitem(item_idx, is_hilighted, &menuitem_data);
        if (wgui_list_get_slow_data_mode() && menuitem_data.menu_text_l1_s1[0] == '\0' && menuitem_data.menu_text_l1_s1[1] == '\0')
        {
            mmi_ucs2cpy((S8*)menuitem_data.menu_text_l1_s1, (S8*)GetString(STR_GLOBAL_LOADING));
        }
    }

    if (is_hilighted)
    {
        text_color = current_UI_theme->fixed_text_menuitem_theme->selected_text_color;
    }
    else
    {
        text_color = current_UI_theme->fixed_text_menuitem_theme->normal_text_color;
    }
    gui_set_text_color(text_color);

    if (menuitem_data.info_type == WGUI_CAT21X_INFO_TYPE_DRV)
    {
        /*----------------------------------------------------------------*/
        /* Calcuate text position                                         */
        /*----------------------------------------------------------------*/
        text_box_y1 = y1 + 3;
        text_box_y2 = y2 - 1;

        menuitem_height = text_box_y2 - text_box_y1 + 1;

        small_font_height = Get_CharHeightOfAllLang(MMI_small_font.size);
        gui_set_font(&MMI_medium_font);
        medium_font_height = Get_CharHeightOfAllLang(MMI_medium_font.size);

        text_spacing = (menuitem_height - medium_font_height - small_font_height) / 3;

        if (text_spacing < 0)
        {
            text_spacing = 0;
        }

#if !defined(__MMI_SLIM_FILE_MANAGER__) && !defined(__COSMOS_MMI_PACKAGE__)
        gdi_image_get_dimension_id(IMG_ID_FMGR_DRIVE_SPACE_0, &image_width, &image_height);

        left_align_offset_x = x1 + (image_width) + 2;
        right_align_offset_x = x2 - (image_width) - 2;
#else /* !defined(__MMI_SLIM_FILE_MANAGER__) */ 
        left_align_offset_x = x1 + (y2 - y1 - 2) + 2;
        right_align_offset_x = x2 - (y2 - y1 - 2) - 2;
#endif /* !defined(__MMI_SLIM_FILE_MANAGER__) */ 

        drv_name_offset_y = text_box_y1 + text_spacing - 1;
        date_size_offset_y = text_box_y1 + text_spacing * 2 + medium_font_height;

        /*----------------------------------------------------------------*/
        /* Draw Drvie Name                                                */
        /*----------------------------------------------------------------*/
        gui_set_font(&MMI_medium_font);

        /* set text clip, avoid draw to overlap scroll bar */
        if (mmi_fe_get_r2l_state())
        {
            gui_set_text_clip(x1 + 1, y1, right_align_offset_x, y2);
        }
        else
        {
            gui_set_text_clip(left_align_offset_x, y1, x2 - 1, y2);
        }

        if (is_hilighted && y1 >= MMI_fixed_list_menu.y)
        {
            /* scrolling text has to be stored in global variable */
            /* we use new_file_name buffer since it is not used in this scenario */
            mmi_ucs2cpy((PS8) fmgr_cat_context.scroll_text_buf, (PS8) menuitem_data.menu_text_l1_s1);

            if (mmi_fe_get_r2l_state())
            {
                gui_create_scrolling_text(
                    &fmgr_cat_context.scroll_text,
                    x1 ,                                 /* x */
                    drv_name_offset_y ,                           /* y */
                    right_align_offset_x - x1 ,                            /* width */
                    medium_font_height ,                     /* height */
                    (UI_string_type) fmgr_cat_context.scroll_text_buf,     /* string */
                    wgui_fmgr_draw_hilight_menuitem_timer_callback,    /* timer hdlr */
                    wgui_fmgr_draw_hilight_menuitem_bg_callback, /* draw background hdlr */
                    text_color,                                 /* text color */
                    MMI_fixed_icontext_menuitem.selected_filler->c);     /* bg */
            }
            else
            {
                gui_create_scrolling_text(
                    &fmgr_cat_context.scroll_text,
                    left_align_offset_x,                        /* x */
                    drv_name_offset_y ,                          /* y */
                    x2 - left_align_offset_x - 1,               /* width */
                    medium_font_height ,                     /* height */
                    (UI_string_type) fmgr_cat_context.scroll_text_buf,     /* string */
                    wgui_fmgr_draw_hilight_menuitem_timer_callback,    /* timer hdlr */
                    wgui_fmgr_draw_hilight_menuitem_bg_callback, /* draw background hdlr */
                    text_color,                                 /* text color */
                    MMI_fixed_icontext_menuitem.selected_filler->c);     /* bg */
            }
            fmgr_cat_context.scroll_text.text_font = MMI_medium_font;
            gui_show_scrolling_text(&fmgr_cat_context.scroll_text);

        }
        else
        {
            wgui_cat_fmgr_print_text(
                right_align_offset_x,
                left_align_offset_x,
                drv_name_offset_y,
                (UI_string_type) menuitem_data.menu_text_l1_s1);
        }

        /*----------------------------------------------------------------*/
        /* Draw size                                                      */
        /*----------------------------------------------------------------*/
        gui_set_font(&MMI_small_font);
        gui_measure_string((UI_string_type) menuitem_data.menu_text_l2_s1, &str_width, &str_height);

        wgui_cat_fmgr_print_text(
              x1 + str_width + 4,
              x2 - str_width - 4,
              date_size_offset_y,
              (UI_string_type) menuitem_data.menu_text_l2_s1);

        /* restore default font size */
        gui_set_font(&MMI_medium_font);
        gui_reset_text_clip();

        /*----------------------------------------------------------------*/
        /* Draw Icon                                                      */
        /*----------------------------------------------------------------*/

        if (mmi_fe_get_r2l_state())
        {
            wgui_fmgr_draw_free_space_icon(right_align_offset_x + 1, y1, y2 - y1 - 2, menuitem_data.drv_ratio, menuitem_data.file_icon_ptr);
        }
        else
        {
            wgui_fmgr_draw_free_space_icon(x1 + 1, y1, y2 - y1 - 2, menuitem_data.drv_ratio, menuitem_data.file_icon_ptr);
        }
    }
    else /* (menuitem_data.info_type == WGUI_CAT21X_INFO_TYPE_DRV) */
    {
        /*
         * this function will draw thumb image menuitem .
         *
         * --------------------------------------
         * | ##### FILENAME_HERE.EXT             |    <--- Medium Font
         * | #####                               |
         * | ##### Date                  Size    |    <--- Small Font
         * --------------------------------------
         * Info. (1) Image, it will be the dimension(ex: 640x480) of the file.
         *       (2) Video, Audio. it will be duration of the file.
         */

        box_height = y2 - y1 - FMGR_UI_IMAGE_BOX_SPACING * 2 + 1;
        box_width = box_height;

        box_offset_y = FMGR_UI_IMAGE_BOX_SPACING;

        if (mmi_fe_get_r2l_state())
        {
            box_offset_x = x2 - box_width - FMGR_UI_IMAGE_BOX_SPACING;
        }
        else
        {
            box_offset_x = x1 + FMGR_UI_IMAGE_BOX_SPACING;
        }

        /*----------------------------------------------------------------*/
        /* Calcuate text position here                                    */
        /*----------------------------------------------------------------*/
        small_font_height = Get_CharHeightOfAllLang(MMI_small_font.size);
        
        gui_set_font(&MMI_medium_font);
        medium_font_height = Get_CharHeightOfAllLang(MMI_medium_font.size);

        text_spacing = ((y2 - y1 + 1) - medium_font_height - small_font_height) / 3;

        if (text_spacing < 0)
        {
            text_spacing = 0;
        }

        left_align_offset_x = box_offset_x + box_width + FMGR_UI_TEXT_SPACING;

        if ((MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_SCROLLBAR) ||
            ((MMI_fixed_list_menu.flags & UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR) && 
             (MMI_fixed_list_menu.displayed_items >= MMI_fixed_list_menu.n_items)))
        {
            r2l_x1 = FMGR_UI_TEXT_SPACING;
        }
        else
        {
            r2l_x1 = MMI_fixed_list_menu.vbar.width + FMGR_UI_TEXT_SPACING;
        }
        text_w = x2 - left_align_offset_x - 2;

        filename_offset_y = y1 + text_spacing;
        date_size_offset_y = y1 + text_spacing * 2 + medium_font_height;

        /*----------------------------------------------------------------*/
        /* Draw File Name                                                 */
        /*----------------------------------------------------------------*/
        if (is_hilighted && y1 >= MMI_fixed_list_menu.y)
        {
            S32 scroll_x;
            if (mmi_fe_get_r2l_state())
                scroll_x = r2l_x1;
            else
                scroll_x = left_align_offset_x;
            /* scrolling text has to be stored in global variable */
            /* we use new_file_name buffer since it is not used in this scenario */
            mmi_ucs2cpy((PS8) fmgr_cat_context.scroll_text_buf, (PS8) menuitem_data.menu_text_l1_s1);

            gui_create_scrolling_text(
                    &fmgr_cat_context.scroll_text,
                    scroll_x,                                 /* x */
                    filename_offset_y,                          /* y */
                    text_w,                        /* width */
                    medium_font_height ,                     /* height */
                    (UI_string_type) fmgr_cat_context.scroll_text_buf,     /* string */
                    wgui_fmgr_draw_hilight_menuitem_timer_callback,    /* timer hdlr */
                    wgui_fmgr_draw_hilight_menuitem_bg_callback, /* draw background hdlr */
                    text_color,                                 /* text color */
                    MMI_fixed_icontext_menuitem.selected_filler->c);     /* bg */

            fmgr_cat_context.scroll_text.text_font = MMI_medium_font;
            gui_show_scrolling_text(&fmgr_cat_context.scroll_text);
        }
        else
        {
            wgui_cat_fmgr_print_text(
                r2l_x1+text_w,
                left_align_offset_x,
                filename_offset_y,
                (UI_string_type) menuitem_data.menu_text_l1_s1);
        }

        /*----------------------------------------------------------------*/
        /* Draw File Creation Date                                        */
        /*----------------------------------------------------------------*/
        /* if is directory or is file but lcd is large enough to fit date and size on one line  */
        gui_set_font(&MMI_small_font);

        if (!CHECK_UCS2STR_EMPTY(menuitem_data.menu_text_l2_s1))
            {
            wgui_cat_fmgr_print_text(
                            r2l_x1+text_w,
                            left_align_offset_x,
                            date_size_offset_y,
                            (UI_string_type) menuitem_data.menu_text_l2_s1);
        }

        /*----------------------------------------------------------------*/
        /* Draw File Size                                                 */
        /*----------------------------------------------------------------*/
        if (!CHECK_UCS2STR_EMPTY(menuitem_data.menu_text_l2_s2))
        {
            gui_measure_string((UI_string_type) menuitem_data.menu_text_l2_s2, &str_width, &str_height);
            wgui_cat_fmgr_print_text(
                          r2l_x1 + str_width,
                          x2 - str_width - 4,
                          date_size_offset_y,
                          (UI_string_type) menuitem_data.menu_text_l2_s2);
        }

        /* restore font to default size */
        gui_set_font(&MMI_medium_font);

        /*----------------------------------------------------------------*/
        /* Draw Large Icon                                                */
        /*----------------------------------------------------------------*/
#if defined(FMGR_USING_CACHE)   
        if (g_fmgr_cache_p != NULL)
        {        
            S32 cache_x = x1 + box_offset_x;
            if (mmi_fe_get_r2l_state())
                cache_x = box_offset_x;

                wgui_cat_fmgr_set_cache_pos(
                    item_idx, 
                    MMI_fixed_list_menu.first_displayed_item, 
                    g_fmgr_cache_p, 
                    cache_x,
                    y1 + box_offset_y);
        }
#endif /* #if defined(FMGR_USING_CACHE) */
#if defined(FMGR_USING_CACHE)
        if(wgui_cat21x_get_displayable != NULL)
        {
            is_displayable = wgui_cat21x_get_displayable(item_idx);
        }
#endif

        if (menuitem_data.is_show_thumb == MMI_TRUE && is_displayable)
        {
            if (mmi_fe_get_r2l_state())
                x1 = 0;

            wgui_cat_fmgr_show_img(
                item_idx, 
                is_hilighted, 
                &menuitem_data, 
                x1 + box_offset_x, 
                y1 + box_offset_y, 
                x1 + box_offset_x + box_width - 1, 
                y1 + box_offset_y + box_height - 1);            
        }
        else
        {
            if (menuitem_data.file_icon_ptr != NULL)
            {
                gui_measure_image( menuitem_data.file_icon_ptr, &image_width, &image_height);
                
                image_offset_x = (box_width - image_width) >> 1;
                image_offset_y = (box_height - image_height) >> 1;
                
                gdi_image_draw(x1 + box_offset_x + image_offset_x, y1 + box_offset_y + image_offset_y, menuitem_data.file_icon_ptr);
            }
        }

    }
}
#endif /*__MMI_CAT217_CAT213_SUPPORT_FMGR__*/
#ifdef __MMI_CAT216_CAT212_SUPPORT_FMGR__
/*****************************************************************************
 * FUNCTION
 *  wgui_cat218_fmgr_hide_hilite_item
 * DESCRIPTION
 *  draw hilite item background of category 218
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat218_fmgr_hide_hilite_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat212_fmgr_hide_data_info_ptr();
    /* End the decoding item, but not free it, just set the flag to NONE */
#if defined(FMGR_USING_CACHE)
    if (g_fmgr_cache_p != NULL)
    {
        wgui_fmgr_cache_stop_decoder();
    }
#endif /* #if defined(FMGR_USING_CACHE) */

    /* stop all animations */
    gui_scrolling_text_stop(&fmgr_cat_context.scroll_text);
    /* gdi_image_stop_animation_all(); */
}

extern pBOOL in_asyncdynamic_item_buffer(S32 index);
/*****************************************************************************
 * FUNCTION
 *  wgui_cat218_fmgr_draw_hilite_item
 * DESCRIPTION
 *  draw hilite item of category 218
 * PARAMETERS
 *  item_idx        [IN]        Index of item   
 *  string          [IN]        string of item
 *  x1              [IN]        area x1
 *  y1              [IN]        area y1
 *  x2              [IN]        area x2
 *  y2              [IN]        area y2
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat218_fmgr_draw_hilite_item(S32 item_idx, UI_string_type string, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 left_align_offset_x;
    S32 right_align_offset_x;
    S32 str_width, str_height;
    S32 small_font_height;
    S32 medium_font_height;
    S32 menuitem_height;
    S32 text_spacing;
    S32 r2l_x1;
    S32 r2l_x2;
    S32 filename_offset_y;    
    S32 drv_name_offset_y;
    S32 date_size_offset_y;
    color text_color;
    color text_shadow_color;
    S32 text_box_y1;
    S32 text_box_y2;
    S32 box_offset_x;
    S32 box_offset_y;
    S32 box_width;
    S32 box_height;
    S32 image_offset_x;
    S32 image_offset_y;

    S32 image_width;
    S32 image_height;

    wgui_fmgr_info_struct fmgr_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetExitScrnID() != GetActiveScreenId())
    {
        return;
    }

    if (wgui_list_get_slow_data_mode() && 
        gui_screen_smooth_scrolling_in_freerun() && 
        !in_asyncdynamic_item_buffer(item_idx))
    {
        /* Use loading directly */
        memset(&fmgr_info, 0, sizeof(wgui_fmgr_info_struct));
        fmgr_info.is_show_thumb = MMI_FALSE;
        fmgr_info.info_type = WGUI_CAT21X_INFO_TYPE_FILE;
        mmi_ucs2cpy((S8*)string, (S8*)GetString(STR_GLOBAL_LOADING));
        fmgr_info.file_icon_ptr = NULL;
    }
    else
    {
        /* Get data from application */
        memset(&fmgr_info, 0, sizeof(wgui_fmgr_info_struct));
        wgui_cat212_fmgr_get_info_ptr(item_idx, &fmgr_info);
        
        if (wgui_list_get_slow_data_mode() && string[0] == '\0' && string[1] == '\0')
        {
            mmi_ucs2cpy((S8*)string, (S8*)GetString(STR_GLOBAL_LOADING));
        }
    }


    /* lock and push clip */
    gui_lock_double_buffer();
    gui_push_clip();

    gui_reset_clip();
    gui_reset_text_clip();

    if (fmgr_info.info_type == WGUI_CAT21X_INFO_TYPE_DRV)
    {
        /*----------------------------------------------------------------*/
        /* Calcuate text position                                         */
        /*----------------------------------------------------------------*/
        text_box_y1 = y1 + 3;
        text_box_y2 = y2 - 1;

        menuitem_height = text_box_y2 - text_box_y1 + 1;

        small_font_height = Get_CharHeightOfAllLang(MMI_small_font.size);
        gui_set_font(&MMI_medium_font);
        medium_font_height = Get_CharHeightOfAllLang(MMI_medium_font.size);

        text_spacing = (menuitem_height - medium_font_height - small_font_height) / 3;

        if (text_spacing < 0)
        {
            text_spacing = 0;
        }

#if !defined(__MMI_SLIM_FILE_MANAGER__) && !defined(__COSMOS_MMI_PACKAGE__)
        gdi_image_get_dimension_id(IMG_ID_FMGR_DRIVE_SPACE_0, &image_width, &image_height);

        left_align_offset_x = x1 + (image_width) + 2;
        right_align_offset_x = x2 - (image_width) - 2;
#else /* !defined(__MMI_SLIM_FILE_MANAGER__) */ 
        left_align_offset_x = x1 + (y2 - y1 + 1) + 2;
        right_align_offset_x = x2 - (y2 - y1 + 1) - 2;
#endif /* !defined(__MMI_SLIM_FILE_MANAGER__) */ 

        drv_name_offset_y = text_box_y1 + text_spacing - 1;
        date_size_offset_y = text_box_y1 + text_spacing * 2 + medium_font_height;

        text_color = current_UI_theme->fixed_text_menuitem_theme->selected_text_color;
        text_shadow_color = current_UI_theme->fixed_text_menuitem_theme->normal_text_color;

        /*----------------------------------------------------------------*/
        /* Draw Drvie Name                                                */
        /*----------------------------------------------------------------*/
        gui_set_font(&MMI_medium_font);

        /* set text clip, avoid draw to overlap scroll bar */
        if (mmi_fe_get_r2l_state())
        {
            gui_set_text_clip(x1 + 1, y1, right_align_offset_x, y2);
        }
        else
        {
            gui_set_text_clip(left_align_offset_x, y1, x2 - 1, y2);
        }

        gui_set_text_color(text_shadow_color);

        /* scrolling text has to be stored in global variable */
        /* we use new_file_name buffer since it is not used in this scenario */
        mmi_ucs2cpy((PS8) fmgr_cat_context.scroll_text_buf, (PS8) string);

        if (mmi_fe_get_r2l_state())
        {
            gui_create_scrolling_text(
                &fmgr_cat_context.scroll_text,
                x1 ,                                 /* x */
                drv_name_offset_y ,                           /* y */
                right_align_offset_x - x1 ,                            /* width */
                medium_font_height ,                     /* height */
                (UI_string_type) fmgr_cat_context.scroll_text_buf,     /* string */
                wgui_fmgr_draw_hilight_menuitem_timer_callback,    /* timer hdlr */
                wgui_fmgr_draw_hilight_menuitem_bg_callback, /* draw background hdlr */
                text_color,                                 /* text color */
                MMI_fixed_icontext_menuitem.selected_filler->c);     /* bg */
        }
        else
        {
            gui_create_scrolling_text(
                &fmgr_cat_context.scroll_text,
                left_align_offset_x,                        /* x */
                drv_name_offset_y ,                          /* y */
                x2 - left_align_offset_x - 1,               /* width */
                medium_font_height ,                     /* height */
                (UI_string_type) fmgr_cat_context.scroll_text_buf,     /* string */
                wgui_fmgr_draw_hilight_menuitem_timer_callback,    /* timer hdlr */
                wgui_fmgr_draw_hilight_menuitem_bg_callback, /* draw background hdlr */
                text_color,                                 /* text color */
                MMI_fixed_icontext_menuitem.selected_filler->c);     /* bg */
        }
        fmgr_cat_context.scroll_text.text_font = MMI_medium_font;
        gui_show_scrolling_text(&fmgr_cat_context.scroll_text);

        /*----------------------------------------------------------------*/
        /* Draw size                                                      */
        /*----------------------------------------------------------------*/
        gui_set_font(&MMI_small_font);
        gui_measure_string((UI_string_type) fmgr_info.info_text_l1_s2, &str_width, &str_height);

        if (mmi_fe_get_r2l_state())
        {
            gui_move_text_cursor(x1 + str_width + 4, date_size_offset_y);   /* 4 spacing from boundry */
        }
        else
        {
            gui_move_text_cursor(x2 - str_width - 4, date_size_offset_y);   /* 4 spacing from boundry */
        }

        gui_print_text((UI_string_type) fmgr_info.info_text_l1_s2);

        /* restore default font size */
        gui_set_font(&MMI_medium_font);
        gui_reset_text_clip();

        /*----------------------------------------------------------------*/
        /* Draw Icon                                                      */
        /*----------------------------------------------------------------*/

        if (mmi_fe_get_r2l_state())
        {
            wgui_fmgr_draw_free_space_icon(right_align_offset_x + 1, y1, y2 - y1 + 1, fmgr_info.drv_ratio, fmgr_info.file_icon_ptr);
        }
        else
        {
            wgui_fmgr_draw_free_space_icon(x1 + 1, y1, y2 - y1 + 1, fmgr_info.drv_ratio, fmgr_info.file_icon_ptr);
        }
    }
    else /* (fmgr_info.info_type == WGUI_CAT21X_INFO_TYPE_DRV) */
    {
        /*
         * this function will draw thumb image menuitem .
         *
         * --------------------------------------
         * | ##### FILENAME_HERE.EXT             |    <--- Medium Font
         * | #####                               |
         * | ##### Date                  Size    |    <--- Small Font
         * --------------------------------------
         * Info. (1) Image, it will be the dimension(ex: 640x480) of the file.
         *       (2) Video, Audio. it will be duration of the file.
         */

        box_height = y2 - y1 - FMGR_UI_IMAGE_BOX_SPACING * 2 + 1;
        box_width = box_height;

        box_offset_y = FMGR_UI_IMAGE_BOX_SPACING;

        if (mmi_fe_get_r2l_state())
        {
            box_offset_x = x2 - box_width - FMGR_UI_IMAGE_BOX_SPACING;
        }
        else
        {
            box_offset_x = FMGR_UI_IMAGE_BOX_SPACING;
        }

        /*----------------------------------------------------------------*/
        /* Calcuate text position here                                    */
        /*----------------------------------------------------------------*/
        small_font_height = Get_CharHeightOfAllLang(MMI_small_font.size);
        
        gui_set_font(&MMI_medium_font);
        medium_font_height = Get_CharHeightOfAllLang(MMI_medium_font.size);

        text_spacing = ((y2 - y1 + 1) - medium_font_height - small_font_height) / 3;

        if (text_spacing < 0)
        {
            text_spacing = 0;
        }

        left_align_offset_x = x1 + box_offset_x + box_width + FMGR_UI_TEXT_SPACING;

        if ((MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_SCROLLBAR) ||
            ((MMI_fixed_list_menu.flags & UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR) && 
             (MMI_fixed_list_menu.displayed_items >= MMI_fixed_list_menu.n_items)))
        {
            r2l_x1 = 2;
        }
        else
        {
            r2l_x1 = MMI_fixed_list_menu.vbar.width + 2;
        }
        
        r2l_x2 = x2 - (y2 - y1 + 1) - text_spacing;

        filename_offset_y = y1 + text_spacing;
        date_size_offset_y = y1 + text_spacing * 2 + medium_font_height;

        text_color = current_UI_theme->fixed_text_menuitem_theme->selected_text_color;
        text_shadow_color = current_UI_theme->fixed_text_menuitem_theme->normal_text_color;

        /*----------------------------------------------------------------*/
        /* Draw File Name                                                 */
        /*----------------------------------------------------------------*/
        /* scrolling text has to be stored in global variable */
        /* we use new_file_name buffer since it is not used in this scenario */
        mmi_ucs2cpy((PS8) fmgr_cat_context.scroll_text_buf, (PS8) string);

		if((g_cat218_previous_highlight_index != item_idx) || !(fmgr_cat_context.scroll_text.flags & UI_SCROLLING_TEXT_ENABLE_SCROLL))
		{
            if (mmi_fe_get_r2l_state())
			{
				gui_create_scrolling_text(
					&fmgr_cat_context.scroll_text,
					r2l_x1 + 4,                                 /* x */
					filename_offset_y,                          /* y */
					r2l_x2 - r2l_x1 - 4,                        /* width */
					medium_font_height ,                     /* height */
					(UI_string_type) fmgr_cat_context.scroll_text_buf,     /* string */
					wgui_fmgr_draw_hilight_menuitem_timer_callback,    /* timer hdlr */
					wgui_fmgr_draw_hilight_menuitem_bg_callback, /* draw background hdlr */
					text_color,                                 /* text color */
					MMI_fixed_icontext_menuitem.selected_filler->c);     /* bg */
			}
			else
			{
				gui_create_scrolling_text(
					&fmgr_cat_context.scroll_text,
					left_align_offset_x,                        /* x */
					filename_offset_y,                          /* y */
					x2 - left_align_offset_x - 1,               /* width */
					medium_font_height ,                     /* height */
					(UI_string_type) fmgr_cat_context.scroll_text_buf,     /* string */
					wgui_fmgr_draw_hilight_menuitem_timer_callback,    /* timer hdlr */
					wgui_fmgr_draw_hilight_menuitem_bg_callback, /* draw background hdlr */
					text_color,                                 /* text color */
					MMI_fixed_icontext_menuitem.selected_filler->c);     /* bg */
			}
			g_cat218_previous_highlight_index = item_idx;
			fmgr_cat_context.scroll_text.text_font = MMI_medium_font;
			gui_show_scrolling_text(&fmgr_cat_context.scroll_text);
		}
		else
		{
			fmgr_cat_context.scroll_text.scroll_counter = 0;
			gui_handle_scrolling_text(&fmgr_cat_context.scroll_text);
		}
        /*----------------------------------------------------------------*/
        /* Draw File Creation Date                                        */
        /*----------------------------------------------------------------*/
        /* if is directory or is file but lcd is large enough to fit date and size on one line  */
        if (!CHECK_UCS2STR_EMPTY(fmgr_info.info_text_l1_s2))
        {
            gui_set_font(&MMI_small_font);
            gui_reset_text_clip();
            gui_set_text_color(text_color);

            if (mmi_fe_get_r2l_state())
            {
                gui_move_text_cursor(r2l_x2, date_size_offset_y);
            }
            else
            {
                gui_move_text_cursor(left_align_offset_x, date_size_offset_y);
            }

            gui_print_text((UI_string_type) fmgr_info.info_text_l1_s2);
        }

        /*----------------------------------------------------------------*/
        /* Draw File Size                                                 */
        /*----------------------------------------------------------------*/
        if (!CHECK_UCS2STR_EMPTY(fmgr_info.info_text_l2_s2))
        {
            gui_reset_text_clip();
            gui_set_text_color(text_color);
            gui_set_font(&MMI_small_font);

            gui_measure_string((UI_string_type) fmgr_info.info_text_l2_s2, &str_width, &str_height);

            if (mmi_fe_get_r2l_state())
            {
                gui_move_text_cursor(r2l_x1 + str_width, date_size_offset_y);
            }
            else
            {
                gui_move_text_cursor(x2 - str_width - 4, date_size_offset_y);
            }

            gui_print_text((UI_string_type) fmgr_info.info_text_l2_s2);
        }

        /* restore font to default size */
        gui_set_font(&MMI_medium_font);

        /*----------------------------------------------------------------*/
        /* Draw Large Icon                                                */
        /*----------------------------------------------------------------*/
#if defined(FMGR_USING_CACHE)   
        if (g_fmgr_cache_p != NULL)
        {        
            wgui_cat_fmgr_set_cache_pos(
                item_idx, 
                MMI_fixed_list_menu.first_displayed_item, 
                g_fmgr_cache_p, 
                x1 + box_offset_x,
                y1 + box_offset_y);
        }
#endif /* #if defined(FMGR_USING_CACHE) */

        if (fmgr_info.is_show_thumb == MMI_TRUE)
        {
            wgui_fmgr_menuitem_data_struct menuitem_data;
            
            /* type is file, and thumb image is right. */
            menuitem_data.is_show_thumb = fmgr_info.is_show_thumb;
            menuitem_data.file_icon_ptr = fmgr_info.file_icon_ptr;
            
            if (mmi_fe_get_r2l_state())
                x1 = 0;

            wgui_cat_fmgr_show_img(
                item_idx, 
                TRUE, 
                &menuitem_data, 
                x1 + box_offset_x, 
                y1 + box_offset_y, 
                x1 + box_offset_x + box_width - 1, 
                y1 + box_offset_y + box_height - 1);            
        }
        else
        {
            if (fmgr_info.file_icon_ptr != NULL)
            {
                gui_measure_image( fmgr_info.file_icon_ptr, &image_width, &image_height);
                
                image_offset_x = (box_width - image_width) >> 1;
                image_offset_y = (box_height - image_height) >> 1;
                
                gdi_image_draw(box_offset_x + image_offset_x, y1 + box_offset_y + image_offset_y, fmgr_info.file_icon_ptr);
            }
        }

    }
    
    /* pop clip , unlock and blt */
    gui_pop_clip();
    gui_unlock_double_buffer();
}
#endif /* __MMI_CAT216_CAT212_SUPPORT_FMGR__ */


#if defined(__MMI_CAT216_CAT212_SUPPORT_FMGR__) || defined(__MMI_CAT217_CAT213_SUPPORT_FMGR__)
/*****************************************************************************
 * FUNCTION
 *  wgui_fmgr_draw_free_space_icon
 * DESCRIPTION
 *  draw free space icon
 * PARAMETERS
 *  box_x1          [IN]        Bounding box offset x
 *  box_y1          [IN]        Bounding box offset y
 *  box_height      [IN]        Bounding box's height
 *  ratio           [IN]        Free space %
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_fmgr_draw_free_space_icon(S32 box_x1, S32 box_y1, S32 box_height, U32 drv_ratio, PU8 file_icon_ptr)
{
#if defined(__MMI_SLIM_FILE_MANAGER__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 width;
    S32 height;
    gdi_color green_start_color;
    gdi_color red_start_color;
    S32 green_width;
    S32 red_width;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(drv_ratio == 0xFFFFFFFF)
		return;
    offset_x = box_x1 + 1;
    offset_y = box_y1 + 8;
    width = box_height - 2 * 1;
    height = box_height - 2 * 8;

    green_width = width * drv_ratio / 10;
    red_width = width - green_width;

    green_start_color = gdi_act_color_from_rgb(255,30, 255, 30);

    red_start_color = gdi_act_color_from_rgb(255,255, 30, 30);

    gdi_draw_solid_rect(
        offset_x,
        offset_y,
        offset_x + red_width,
        offset_y + height,
        red_start_color);

    gdi_draw_solid_rect(
        offset_x + red_width,
        offset_y,
        offset_x + width,
        offset_y + height,
        green_start_color);
#elif defined(__MMI_FTE_SUPPORT__) && !defined(__COSMOS_MMI_PACKAGE__)
     S32 img_width, img_height;
     S32 spacing_y = 0;
     gdi_handle act_layer;
     gui_measure_image((PU8)GetImage(IMG_ID_FMGR_DRIVE_SPACE_0), &img_width, &img_height);
     
     if(img_height < box_height)
         spacing_y = (box_height - img_height) >> 1;
	 gdi_layer_get_active(&act_layer);
     gdi_push_and_set_alpha_blending_source_layer(act_layer);
         
     gdi_image_draw(box_x1, box_y1 + spacing_y + 1, (PU8)GetImage(IMG_ID_FMGR_DRIVE_SPACE_0));
     
     gui_push_clip();
     gui_set_clip(box_x1, box_y1 + spacing_y + 1, box_x1 + img_width*(10-drv_ratio) / 10, box_y1 + box_height  + 1);
     gdi_image_draw(box_x1, box_y1 + spacing_y + 1, (PU8)GetImage(IMG_ID_FMGR_DRIVE_SPACE_100));
     gui_pop_clip();
	 gdi_pop_and_restore_alpha_blending_source_layer();
#else /* defined(__MMI_SLIM_FILE_MANAGER__) */ 
    S32 img_width, img_height;
    S32 spacing_y;

    gui_measure_image(file_icon_ptr, &img_width, &img_height);
    /* because of box's height == box's width */
    spacing_y = (box_height - img_height) >> 1;

    gui_show_transparent_image(box_x1, box_y1 + spacing_y + 1, file_icon_ptr, 0);

#endif /* defined(__MMI_SLIM_FILE_MANAGER__) */ 
}
#endif /*defined(__MMI_CAT216_CAT212_SUPPORT_FMGR__) || defined(__MMI_CAT217_CAT213_SUPPORT_FMGR__)*/


#ifdef __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__
/*****************************************************************************
 * FUNCTION
 *  wgui_cat21x_fmgr_set_slow_data_mode
 * DESCRIPTION
 *  Set Slow data read mode
 * PARAMETERS
 *  slow_mode      [IN]        Use slow mode or not
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat21x_fmgr_set_slow_data_mode(MMI_BOOL slow_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_list_set_slow_data_mode(slow_mode);

}
#endif /*__MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__*/
