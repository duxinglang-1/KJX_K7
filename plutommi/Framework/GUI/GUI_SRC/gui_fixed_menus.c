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
 *  gui_fixed_menus.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Fixed-list menu - UI component
 *
 *  1. The number of menu items stays unchanged after the UI component is created.
 *  2. The storage of all menu item data is preallocated.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "MMI_Features.h"
#include "gui_config.h"
#include "gui_fixed_menus.h"
#include "CustMenuRes.h"
#include "gui_themes.h"
#include "gdi_include.h"
#include "wgui.h"
#include "wgui_fixed_menus.h"
#include "wgui_draw_manager.h"
#include "wgui_categories_util.h"
#include "gui_font_size.h"
#include "gui_touch_feedback.h"
#include "gd_include.h"
#include "gdi_datatype.h"
#include "MMIDataType.h"
#include "gui_theme_struct.h"
#include "gui_effect_oem.h"
#include "kal_general_types.h"
#include "gui_data_types.h"
#include "gui_typedef.h"
#include "wgui_inline_edit.h"
#include "gui_scrollbars.h"
#include "gui.h"
#include "gdi_const.h"
#include "string.h"
#include "gui_fixed_menuitems.h"
#include "CustDataProts.h"
#include "gui_switch.h"
#ifndef __OPTR_NONE__
#include "operator_gui.h"
#endif
#include "wgui_include.h"
#include "CustThemesRes.h"
#include "lcd_sw_inc.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_input_gprot.h"
#include "wgui_categories_enum.h"
#include "gui_main_menu_post_oem.h"
#include "wgui_dynamic_menuitems.h"
#include "wgui_asyncdynamic_menuitems.h"
#include "gui_dynamic_menus.h"
#include "gui_asyncdynamic_menus.h"
#include "vfx_system.h"

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
#ifdef __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
static void gui_fixed_list_menu_goto_item_without_change_highlight(fixed_list_menu *m, S32 first_displayed_item);
#endif
static void gui_fixed_list_menu_locate_previous_item(fixed_list_menu *m);
static void gui_fixed_list_menu_locate_next_item(fixed_list_menu *m);
static void gui_fixed_list_menu_switch_highlighted_item(fixed_list_menu *m, S32 last_highlighted_item);
static void gui_create_fixed_menu(void *m0, S32 x, S32 y, S32 width, S32 height);
static void gui_resize_move_scrollbar(fixed_matrix_menu* m);

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
extern gdi_handle wgui_layer_1;
extern gdi_handle wgui_base_layer;
extern PU8 get_image(MMI_ID_TYPE);
extern S32 MMI_current_menu_type;
extern S32 GUI_current_fixed_icontext_menuitem_x, GUI_current_fixed_icontext_menuitem_y,
GUI_current_fixed_icontext_menuitem_x2;

extern fixed_icontext_menuitem MMI_fixed_icontext_menuitem; 



extern S32 menu_item_inline_multiline_box(void);

extern int gdi_layer_get_bit_per_pixel(void);
extern PU8 get_image(U16 i);

UI_fixed_list_menu_theme *current_fixed_list_menu_theme = NULL;
UI_fixed_matrix_menu_theme *current_fixed_matrix_menu_theme = NULL;

#if defined(__MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__) || defined(__MMI_SCREEN_SWITCH_EFFECT__)

// TODO: THE MATRIX MAIN MENU ITEM NUMBER SHOULD BE CHANGED TO A REAL VALUE.
#define MAX_MATRIX_MM_ITEM_NUM  12
 
S32 matrix_mm_active_image_num = 0;
gui_image_text_rect matrix_mm_rect[MAX_MATRIX_MM_ITEM_NUM];
#endif /* defined(__MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__) || defined(__MMI_SCREEN_SWITCH_EFFECT__) */

void (*g_gui_list_hide_menu) (S32 x1, S32 y1, S32 x2, S32 y2) = NULL;

#ifdef __MMI_OP11_SIDEBAR__
extern U32 g_gui_list_clock;
#endif

S32 g_pen_down_item_index = -1;
MMI_BOOL g_current_display_half_menuitem = MMI_FALSE;
extern gdi_handle g_gui_ssp_static_layer;

/***************************************************************************** 
 * Local Function
 *****************************************************************************/

/***************************************************************************** 
 * Global Function
 *****************************************************************************/



/* common locate and goto fuctions for fixed/dynamic/asyncdynamic menu */

/*****************************************************************************
 * FUNCTION
 *  gui_list_menu_has_multi_line
 * DESCRIPTION
 *  whether the list menu has multi line
 * PARAMETERS
 *  void
 * RETURNS
 *  MI_BOOL:    return MMI_TRUE if list has multi line, otherwise return MMI_FALSE
 *****************************************************************************/
static MMI_BOOL gui_list_menu_has_multi_line(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    U32 flags, flags_ext;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m->flags & UI_LIST_MENU_INLINE_EDIT)
    {
        if (m->n_items > 0)
        {
            index = m->n_items - 1;
        }
        else
        {
            index = 0;
        }
        m->item_get_flag_function(
            m->items[index], m->common_item_data, 
            index, &flags, &flags_ext); 

        if ((flags & UI_MENUITEM_INLINE_EDIT_OBJECT) &&
            ((wgui_inline_items[index].flags & 0xFF) == INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY))
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_list_menu_measure_item
 * DESCRIPTION
 *  Helper function of gui_list_menu_locate_highlighted_item.
 * PARAMETERS
 *  m       [IN]        list menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_list_menu_measure_item(fixed_list_menu *m, U32 i, S32 *iwidth, S32 *iheight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *item = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (i == m->highlighted_item)
    {
        m->current_displayed_item = -1;
    }
    else
    {
        m->current_displayed_item = i;
    }

    if (MMI_fixed_list_menu.menu_style == GUI_MENU_TYPE_DYNAMIC || MMI_fixed_list_menu.menu_style == GUI_MENU_TYPE_ASYNCDYNAMIC)
    {
        item = NULL;
    }
    else
    {
        item = m->items[i];
    }
    m->item_measure_function(item, m->common_item_data, iwidth, iheight);
}


/*****************************************************************************
 * FUNCTION
 *  gui_list_menu_locate_item_check_first_page
 * DESCRIPTION
 *  Helper function of gui_list_menu_locate_highlighted_item.
 * PARAMETERS
 *  m       [IN]        list menu object
 * RETURNS
 *  void
 *****************************************************************************/
static U8 gui_list_menu_locate_item_check_first_page(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 iwidth, iheight;
    S32 total_height = 0, i;
    U8 done = 0;
    S32 list_height = m->height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; (i < m->n_items) && !done; i++)
    {
        gui_list_menu_measure_item(m, i, &iwidth, &iheight);
        total_height += iheight;
        if (total_height > list_height + 1)
        {
            if (m->last_displayed_item < i)
            {
                done = 1;
                m->first_displayed_item = 0;
                m->last_displayed_item = i - 1;
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
                m->first_displayed_offset = 0;
                m->last_displayed_offset = 0;
                if (total_height - iheight < list_height)
                {
                    m->last_displayed_item = i;
                    m->last_displayed_offset = iheight - (total_height - list_height);
                }
#endif
            }
            break;
        }
    }
    m->current_displayed_item = -1;

    if (!done && total_height <= list_height + 1)
    {
        done = 1;
        m->first_displayed_item = 0;
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
        m->first_displayed_offset = 0;
        m->last_displayed_offset = 0;
#endif
        m->last_displayed_item = m->n_items - 1;
    }

    return done;
}


/*****************************************************************************
 * FUNCTION
 *  gui_list_menu_locate_item_check_last_page
 * DESCRIPTION
 *  Helper function of gui_list_menu_locate_highlighted_item.
 * PARAMETERS
 *  m       [IN]        list menu object
 * RETURNS
 *  void
 *****************************************************************************/
static U8 gui_list_menu_locate_item_check_last_page(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 iwidth, iheight;
    S32 total_height = 0, i;
    U8 done = 0;
    S32 list_height = m->height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = m->n_items - 1; (i >= 0) && (!done); i--)
    {
        gui_list_menu_measure_item(m, i, &iwidth, &iheight);
        total_height += iheight;
        if (total_height > list_height)
        {
            if (m->first_displayed_item > i)
            {
                done = 1;
                m->first_displayed_item = i + 1;
                m->last_displayed_item = m->n_items - 1;
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
                m->first_displayed_offset = 0;
                m->last_displayed_offset = 0;
                if (total_height - iheight < list_height)
                {
                    m->first_displayed_item = i;
                    m->first_displayed_offset = total_height - list_height;
                }
#endif
            }
            break;
        }
    }
    m->current_displayed_item = -1;

    if (!done && total_height <= list_height)
    {
        done = 1;
        m->first_displayed_item = 0;
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
        m->first_displayed_offset = 0;
        m->last_displayed_offset = 0;
#endif
        m->last_displayed_item = m->n_items - 1;
    }
    return done;
}


/*****************************************************************************
 * FUNCTION
 *  gui_list_menu_locate_item_compute_last
 * DESCRIPTION
 *  Helper function of gui_list_menu_locate_highlighted_item.
 * PARAMETERS
 *  m       [IN]        list menu object
 * RETURNS
 *  void
 *****************************************************************************/
U8 gui_list_menu_locate_item_compute_last(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 iwidth, iheight;
    S32 total_height = 0, i;
    U8 done = 0;
    S32 list_height = m->height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
    total_height -= m->first_displayed_offset;
#endif
    for (i = m->first_displayed_item; (i < m->n_items) && (!done); i++)
    {
        gui_list_menu_measure_item(m, i, &iwidth, &iheight);
        total_height += iheight;
        if (total_height > list_height)
        {
            done = 1;
            m->last_displayed_item = i - 1;
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
            m->last_displayed_offset = 0;
            if (total_height - iheight < list_height)
            {
                m->last_displayed_item = i;
                m->last_displayed_offset = iheight - (total_height - list_height);
            }
#endif
        }
    }
    m->current_displayed_item = -1;
    return done;
}


/*****************************************************************************
 * FUNCTION
 *  gui_list_menu_locate_item_compute_first
 * DESCRIPTION
 *  Helper function of gui_list_menu_locate_highlighted_item.
 * PARAMETERS
 *  m       [IN]        list menu object
 * RETURNS
 *  void
 *****************************************************************************/
U8 gui_list_menu_locate_item_compute_first(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 iwidth, iheight;
    S32 total_height = 0, i;
    U8 done = 0;
    S32 list_height = m->height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = m->last_displayed_item; (i >= 0) && (!done); i--)
    {
        gui_list_menu_measure_item(m, i, &iwidth, &iheight);
        total_height += iheight;
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
        if (i == m->last_displayed_item && m->last_displayed_offset > 0)
        {
            total_height -= iheight - m->last_displayed_offset;
        }
#endif
        if (total_height > list_height)
        {
            done = 1;
            m->first_displayed_item = i + 1;
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
            m->first_displayed_offset = 0;
            if (total_height - iheight < list_height)
            {
                m->first_displayed_item = i;
                m->first_displayed_offset = total_height - list_height;
            }
#endif
        }
    }
    m->current_displayed_item = -1;
    return done;
}


/*****************************************************************************
 * FUNCTION
 *  gui_list_menu_locate_highlighted_item
 * DESCRIPTION
 *  Locate the highlighted menu item.
 * PARAMETERS
 *  m       [IN]        list menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_list_menu_locate_highlighted_item(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* FIXME. handle the case that m->height < iheight */
    S32 old_first;
    S32 old_last;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m->highlighted_item == GUI_LIST_MENU_ALL_ITEMS_ARE_DISABLE)
    {
        return;
    }

    old_first = MMI_fixed_list_menu.first_displayed_item;
    old_last = MMI_fixed_list_menu.last_displayed_item;

    if (!(m->flags & UI_LIST_MENU_FIRST_SHIFT_HIGHLIGHTED_ITEM) &&
        !(m->flags & UI_LIST_MENU_LAST_SHIFT_HIGHLIGHTED_ITEM))
    {
        /* 
         * m->first_dispalyed_item & m->last_displayed_item is set properly in asyncdynamic_list_goto_item().
         *
         * However, the value of m->first_dispalyed_item & m->last_displayed_item is undefined 
         * on entering a new menu (asyncdynamic_list_goto_item_no_redraw()) without list menu history.
         *
         */
        if (m->first_displayed_item >= m->n_items || m->last_displayed_item >= m->n_items)
        {
            m->first_displayed_item = 0;
            m->last_displayed_item = 0;
        }

        if (m->highlighted_item < m->first_displayed_item)
        {
            m->flags |= UI_LIST_MENU_FIRST_SHIFT_HIGHLIGHTED_ITEM;
        }
        else if (m->highlighted_item > m->last_displayed_item)
        {
            m->flags |= UI_LIST_MENU_LAST_SHIFT_HIGHLIGHTED_ITEM;
        }

#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
        if (!(m->flags & UI_LIST_MENU_ENABLE_GOTO_HALF_ITEM))
        {
            if (m->highlighted_item == m->first_displayed_item && m->first_displayed_offset > 0)
            {
                m->flags |= UI_LIST_MENU_FIRST_SHIFT_HIGHLIGHTED_ITEM;
            }
            else if (m->highlighted_item == m->last_displayed_item && m->last_displayed_offset > 0 &&
                     !((m->flags & UI_MENUITEM_INLINE_EDIT_OBJECT) && 
                       ((wgui_inline_items[m->last_displayed_item].flags & 0xFF) == INLINE_ITEM_TYPE_MULTI_LINE_EDIT ||
                        (wgui_inline_items[m->last_displayed_item].flags & 0xFF) == INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY)))
            {
                m->flags |= UI_LIST_MENU_LAST_SHIFT_HIGHLIGHTED_ITEM;
            }
        }
#endif
    }

    if (m->flags & UI_LIST_MENU_FIRST_SHIFT_HIGHLIGHTED_ITEM)
    {
        U8 done = 0;

        m->flags &= ~UI_LIST_MENU_FIRST_SHIFT_HIGHLIGHTED_ITEM;
        m->first_displayed_item = m->highlighted_item;
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
        m->first_displayed_offset = 0;
#endif

        /* Check if in the last page */
        done = gui_list_menu_locate_item_check_last_page(m);

        /* Align to the top */
        if (!done)
        {
            done = gui_list_menu_locate_item_compute_last(m);
            if (!done)
            {
                m->last_displayed_item = m->n_items - 1;
            }
        }
    }
    else if (m->flags & UI_LIST_MENU_LAST_SHIFT_HIGHLIGHTED_ITEM)
    {
        U8 done = 0;

        m->flags &= ~UI_LIST_MENU_LAST_SHIFT_HIGHLIGHTED_ITEM;
        m->last_displayed_item = m->highlighted_item;
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
        m->last_displayed_offset = 0;
#endif

        /* Check if in the first page */
        done = gui_list_menu_locate_item_check_first_page(m);

        /* Align to the bottom */
        if (!done)
        {
            done = gui_list_menu_locate_item_compute_first(m);
            if (!done)
            {
                m->first_displayed_item = 0;
            }
        }
    }
    else
    {
        /* 
         * Condition: m->first_displayed_item <= m->highlighted_item <= m->last_displayed_item 
         * Do not change m->first_displayed_item if no problem occurs
         */
        U8 done = 0;

        /* Re-compute last_displayed_item */
        done = gui_list_menu_locate_item_compute_last(m);

        /* Check if in the last page */
        if (!done)
        {
            gui_list_menu_locate_item_check_last_page(m);
        }

        MMI_DBG_ASSERT(m->first_displayed_item <= m->highlighted_item);
        if (m->highlighted_item > m->last_displayed_item
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
            || (m->highlighted_item == m->last_displayed_item && m->last_displayed_offset > 0 && !(m->flags & UI_LIST_MENU_ENABLE_GOTO_HALF_ITEM))
#endif
        )
        {
            m->last_displayed_item = m->highlighted_item;
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
            m->last_displayed_offset = 0;
#endif
            gui_list_menu_locate_item_compute_first(m);
        }
    }

    if (MMI_fixed_list_menu.menu_style == GUI_MENU_TYPE_DYNAMIC)
    {
        /* Load one more item because it might be accessed in gui_show_dynamic_list_menu() */
#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_NUMBER_KEY) || defined(GUI_LIST_MENU_SSK_EFFECT_BY_PEN)    
        if (gui_list_menu_is_support_smooth_scrolling())
        {
            if (m->flags & UI_LIST_MENU_DISABLE_CACHE_DYNAMIC_DATA)
            {
                flush_dynamic_item_buffer_before_load_chunk();
            }
            if ((m->highlighted_item == m->first_displayed_item) && (m->first_displayed_item > 0))
            {
                load_chunk_dynamic_item_buffer(m->first_displayed_item - 1, m->last_displayed_item - m->first_displayed_item + 3);
            }
            else if ((m->highlighted_item == m->last_displayed_item) && (m->last_displayed_item < m->n_items - 2))
            {
                load_chunk_dynamic_item_buffer(m->first_displayed_item, m->last_displayed_item - m->first_displayed_item + 3);
            }
            else
            {
                load_chunk_dynamic_item_buffer(m->first_displayed_item, m->last_displayed_item - m->first_displayed_item + 2);
            }
        }
        else
        {
            if (m->flags & UI_LIST_MENU_DISABLE_CACHE_DYNAMIC_DATA)
            {
                flush_dynamic_item_buffer_before_load_chunk();
            }
            load_chunk_dynamic_item_buffer(m->first_displayed_item, m->last_displayed_item - m->first_displayed_item + 2);
        }
#else   /* GUI_LIST_MENU_SMOOTH_SCROLLING_BY_NUMBER_KEY || GUI_LIST_MENU_SSK_EFFECT_BY_PEN */
        if (m->flags & UI_LIST_MENU_DISABLE_CACHE_DYNAMIC_DATA)
        {
            flush_dynamic_item_buffer_before_load_chunk();
        }
        load_chunk_dynamic_item_buffer(m->first_displayed_item, m->last_displayed_item - m->first_displayed_item + 2);
#endif  /* GUI_LIST_MENU_SMOOTH_SCROLLING_BY_NUMBER_KEY || GUI_LIST_MENU_SSK_EFFECT_BY_PEN */
    }
    if (MMI_fixed_list_menu.menu_style == GUI_MENU_TYPE_ASYNCDYNAMIC)
    {
        if (g_gui_async_list_update_callback && !mmi_frm_in_exit_hdlr_proc())
        {
            g_gui_async_list_update_callback(m->highlighted_item);
        }
        /* Load one more item because it might be accessed in gui_show_asyncdynamic_list_menu() */
#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_NUMBER_KEY) || defined(GUI_LIST_MENU_SSK_EFFECT_BY_PEN)
        if (gui_asyncdynamic_list_error == 0 && gui_list_menu_is_support_smooth_scrolling())
        {
            if ((m->highlighted_item == m->first_displayed_item) && (m->first_displayed_item > 0))
            {
                if (!load_chunk_asyncdynamic_item_buffer(
                    m->first_displayed_item - 1, m->last_displayed_item - m->first_displayed_item + 3))
                {
                    gui_asyncdynamic_list_error = 1;
                }
            }
            else if ((m->highlighted_item == m->last_displayed_item) && (m->last_displayed_item < m->n_items - 2))
            {
                if (!load_chunk_asyncdynamic_item_buffer(
                    m->first_displayed_item, m->last_displayed_item - m->first_displayed_item + 3))
                {
                    gui_asyncdynamic_list_error = 1;
                }
            }
            else
            {
                if (!load_chunk_asyncdynamic_item_buffer(
                    m->first_displayed_item, m->last_displayed_item - m->first_displayed_item + 2))
                {
                    gui_asyncdynamic_list_error = 1;
                }
            }
                
        }
        else
        {
            if (gui_asyncdynamic_list_error == 0 &&
                m->n_items > 0 &&
                !load_chunk_asyncdynamic_item_buffer(
                    m->first_displayed_item, m->last_displayed_item - m->first_displayed_item + 2))
                {
                    gui_asyncdynamic_list_error = 1;
                }
        }
#else   /* defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_NUMBER_KEY) || defined(GUI_LIST_MENU_SSK_EFFECT_BY_PEN) */
#if  defined(__MMI_BASIC_UI_STYLE__) && defined(__MMI_UI_HINTS_IN_MENUITEM__)        
        if (gui_asyncdynamic_list_error == 0 &&
            m->n_items > 0 &&
            !load_chunk_asyncdynamic_item_buffer
            (m->first_displayed_item, m->last_displayed_item - m->first_displayed_item + 3))
        {
            gui_asyncdynamic_list_error = 1;
        }
#else
        if (gui_asyncdynamic_list_error == 0 &&
            m->n_items > 0 &&
            !load_chunk_asyncdynamic_item_buffer
            (m->first_displayed_item, m->last_displayed_item - m->first_displayed_item + 2))
        {
            gui_asyncdynamic_list_error = 1;
        }
#endif  //  defined(__MMI_BASIC_UI_STYLE__) && defined(__MMI_UI_HINTS_IN_MENUITEM__)
#endif  /* defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_NUMBER_KEY) || defined(GUI_LIST_MENU_SSK_EFFECT_BY_PEN) */      
    }
    else
    {
        /* Located after resized */
        m->resized_before_locate = MMI_FALSE;

        if (gui_list_menu_has_multi_line(m))
        {
            /* 
             * for example when first = 0, last = 1, highlight = 2, highlight is multi-line
             * then after locate fisrt, last, highlight all change to 2
             * we expect after 
             */
            if ((m->highlighted_item == m->n_items - 1))
            {
                m->first_displayed_item = old_first;
                m->last_displayed_item = old_last;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_locate_previous_item
 * DESCRIPTION
 *  Locate the menu item previous to the highlighted item.
 * PARAMETERS
 *  m       [IN]        list menu object   
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_list_menu_locate_previous_item(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.menu_style == GUI_MENU_TYPE_DYNAMIC)
    {
        gui_dynamic_list_menu_locate_previous_item(m);
    }
    else if (MMI_fixed_list_menu.menu_style == GUI_MENU_TYPE_ASYNCDYNAMIC)
    {
        gui_asyncdynamic_list_menu_locate_previous_item(m);
    }
    else
    {
        gui_fixed_list_menu_locate_previous_item(m);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_locate_next_item
 * DESCRIPTION
 *  Locate the menu item next to the highlighted item.
 * PARAMETERS
 *  m       [IN]        list menu object
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_list_menu_locate_next_item(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.menu_style == GUI_MENU_TYPE_DYNAMIC)
    {
        gui_dynamic_list_menu_locate_next_item(m);
    }
    else if (MMI_fixed_list_menu.menu_style == GUI_MENU_TYPE_ASYNCDYNAMIC)
    {
        gui_asyncdynamic_list_menu_locate_next_item(m);
    }
    else
    {
        gui_fixed_list_menu_locate_next_item(m);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_list_menu_goto_item_helper
 * DESCRIPTION
 *  Helper function for gui_list_menu_goto_item.
 * PARAMETERS
 *  m       [IN]        list menu object
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_list_menu_goto_item_helper(fixed_list_menu *m, U32 *direction, S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*direction)
    {
        if (m->highlighted_item <= 0)        
        {
            if (m->flags & UI_LIST_MENU_LOOP)
            {
                m->highlighted_item = m->n_items - 1;
            }
            else
            {
                *direction = 0;
                m->highlighted_item = i + 1;
            }
        }
        else
        {
            m->highlighted_item--;
        }
    }
    else
    {
        if (m->highlighted_item >= (m->n_items - 1))        
        {
            if (m->flags & UI_LIST_MENU_LOOP)
            {
                m->highlighted_item = 0;
            }
            else
            {
                *direction = 1;
                m->highlighted_item = i - 1;
            }
        }
        else
        {
            m->highlighted_item++;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_list_menu_is_goto_item_disabled
 * DESCRIPTION
 *  Helper function for gui_list_menu_goto_item.
 * PARAMETERS
 *  m       [IN]        list menu object
 * RETURNS
 *  void
 *****************************************************************************/
static U32 gui_list_menu_is_goto_item_disabled(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 flags = 0, flags_ext = 0;
    void *item = NULL, *common_item_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.menu_style != GUI_MENU_TYPE_DYNAMIC && MMI_fixed_list_menu.menu_style != GUI_MENU_TYPE_ASYNCDYNAMIC)
    {
        item = m->items[m->highlighted_item];
        common_item_data = m->common_item_data;
    }
    m->item_get_flag_function(item, common_item_data, m->highlighted_item, &flags, &flags_ext);

    return (flags & UI_MENUITEM_STATE_DISABLED);
}


/*****************************************************************************
 * FUNCTION
 *  gui_list_menu_goto_item
 * DESCRIPTION
 *  Go to a specified item index.
 * PARAMETERS
 *  m       [IN]        list menu object
 *  i       [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void gui_list_menu_goto_item(fixed_list_menu *m, S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_highlighted_item;
#if defined (__MMI_UI_LIST_SKIP_DISABLED__)
    U32 direction = 0;
#endif
    S32 disable_count = 0;
    S32 old_first, old_last, goto_item_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    /* If highlight is changed by keypad, abort scroll timer */
    gui_dynamic_list_abort_scroll_timer();
    gui_asyncdynamic_list_abort_scroll_timer();
#endif /* __MMI_TOUCH_SCREEN__ */ 

    if ((i < -1) || (i > m->n_items - 1))
    {
        return;
    }
#ifdef  __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
    if (i == m->highlighted_item && i != -1 &&
        m->highlighted_item >= m->first_displayed_item &&
        m->highlighted_item <= m->last_displayed_item)
#else   /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */
    if (i == m->highlighted_item && i != -1)
#endif  /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */
    {
        return;
    }

    old_first = m->first_displayed_item;
    old_last = m->last_displayed_item;
    goto_item_index = i;

#ifdef  __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
    if (i == m->highlighted_item)
    {
        last_highlighted_item = -1;
    }
    else
    {
        last_highlighted_item = m->highlighted_item;
    }
#else   /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */
    last_highlighted_item = m->highlighted_item;
#endif  /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */
    m->highlighted_item = i;
#if defined (__MMI_UI_LIST_SKIP_DISABLED__)
    if (last_highlighted_item > i)
    {
        direction = 1;
    }
    while (gui_list_menu_is_goto_item_disabled(m))
    {
        disable_count++;
        if (disable_count >= m->n_items)
        {
            /* all items are in disable state */
            m->highlighted_item = GUI_LIST_MENU_ALL_ITEMS_ARE_DISABLE;
            break;
        }
        gui_list_menu_goto_item_helper(m, &direction, i);
    }
#endif /* defined (__MMI_UI_LIST_SKIP_DISABLED__) */
    if (i != -1)
    {
        gui_list_menu_locate_highlighted_item(m);
    }   

    if (m->highlighted_item != GUI_LIST_MENU_ALL_ITEMS_ARE_DISABLE)
    {
        if (MMI_fixed_list_menu.menu_style == GUI_MENU_TYPE_DYNAMIC)
        {
            gui_dynamic_list_menu_switch_highlighted_item(m, last_highlighted_item);
        }
        else if (MMI_fixed_list_menu.menu_style == GUI_MENU_TYPE_ASYNCDYNAMIC)
        {
            if (gui_asyncdynamic_list_error)
            {
                return;
            }
            gui_asyncdynamic_list_menu_switch_highlighted_item(m, last_highlighted_item);
        }
        else
        {
            gui_fixed_list_menu_switch_highlighted_item(m, last_highlighted_item);

#ifdef  __MMI_UI_HINTS_IN_MENUITEM__
            wgui_list_menu_locate_highlighted_item();
#endif  /* __MMI_UI_HINTS_IN_MENUITEM__ */
        
            if (gui_list_menu_has_multi_line(m))
            {
                /* for the suitation that, the last item is multiline,
                 * and the multiline is half display in list menu, the pen down on the multiline
                 * should change highlight to the multiline and the screen layout should not changed
                 */
                if ((m->highlighted_item == m->n_items - 1) &&
                    (goto_item_index == m->n_items - 1))
                {
                    m->first_displayed_item = old_first;
                    m->last_displayed_item = old_last;
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_list_menu_goto_next_item
 * DESCRIPTION
 *  Go to the item next to the highlighted item.
 * PARAMETERS
 *  m       [IN]        list menu object   
 * RETURNS
 *  void
 *****************************************************************************/
void gui_list_menu_goto_next_item(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_highlighted_item, displayed_items=0;
#if defined (__MMI_UI_LIST_SKIP_DISABLED__)
    U32 direction = 0;
#else
    U8 loop_flag = 0;
#endif
    S32 i;
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
    S32 old_first, old_last, old_first_offset;
#endif
    MMI_BOOL IS_goto_next =MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	//for goto prev
	if(m->spacing == GUI_FIXED_LIST_PREV_ITEM)
	{
	   IS_goto_next = MMI_FALSE;
	   #if defined (__MMI_UI_LIST_SKIP_DISABLED__)
       direction = 1; 
       #endif
	}
	 m->spacing= 0;
#ifdef __MMI_TOUCH_SCREEN__
    /* If highlight is changed by keypad, abort scroll timer */
    gui_dynamic_list_abort_scroll_timer();
    gui_asyncdynamic_list_abort_scroll_timer();
#endif /* __MMI_TOUCH_SCREEN__ */ 

    if (m->highlighted_item == GUI_LIST_MENU_ALL_ITEMS_ARE_DISABLE)
    {
        return;
    }

	if(IS_goto_next)
	{
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
    old_first = m->first_displayed_item;
    old_last = m->last_displayed_item;
    old_first_offset = m->first_displayed_offset;
#endif

    displayed_items = m->displayed_items;
    last_highlighted_item = m->highlighted_item;
    }
#if defined (__MMI_UI_LIST_SKIP_DISABLED__)
    last_highlighted_item = m->highlighted_item;
    if (((m->highlighted_item >= (m->n_items - 1))&&IS_goto_next)
		||((m->highlighted_item <= 0)&&!IS_goto_next))
    {
        if (m->flags & UI_LIST_MENU_LOOP)
        {
           if(IS_goto_next)
           	{
	            m->highlighted_item = 0;
	            m->first_displayed_item = 0;
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
	            m->first_displayed_offset = 0;
#endif
	            m->last_displayed_item = m->displayed_items - 1;
           	}
		   else
		   	{
                m->highlighted_item = m->n_items - 1;
	            m->last_displayed_item = m->n_items - 1;
	            m->first_displayed_item = m->last_displayed_item - m->displayed_items + 1; 
		   }
        }
        else
        {
            return;
        }
    }
    else
    {   if(IS_goto_next)     
	        m->highlighted_item++;
	    else
			m->highlighted_item--;
    }

    if (gui_list_menu_is_goto_item_disabled(m))
    {
        while (gui_list_menu_is_goto_item_disabled(m))
        {
            i = m->highlighted_item;
            gui_list_menu_goto_item_helper(m, &direction, i);
        }
        gui_list_menu_locate_highlighted_item(m);
    }
    else
    {
#ifdef __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
        if (m->highlighted_item < m->first_displayed_item ||
            m->highlighted_item > m->last_displayed_item)
#else   /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */
        if (((m->highlighted_item == 0)&&IS_goto_next)
			||((m->highlighted_item == m->n_items - 1)&&!IS_goto_next))
#endif  /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */
        {
            gui_list_menu_locate_highlighted_item(m);
        }
        else
        {   
            if(IS_goto_next)
	            gui_list_menu_locate_next_item(m);
			else
				gui_list_menu_locate_previous_item(m);
        }
    }
#else
    if (((m->highlighted_item >= (m->n_items - 1))&&IS_goto_next)||
		((m->highlighted_item <= 0)&&!IS_goto_next))
    {
        if (m->flags & UI_LIST_MENU_LOOP)
        {
            loop_flag = 1;
        }
        else
        {
            return;
        }
    }
    last_highlighted_item = m->highlighted_item;
    if (loop_flag)
    {   
        if(IS_goto_next)
    	{
	        m->highlighted_item = 0;
	        gui_list_menu_locate_previous_item(m);
    	}
		else
		{
			 m->highlighted_item = m->n_items - 1;
		    gui_list_menu_locate_next_item(m);
		}
    }
    else
    {
        if(IS_goto_next)
           m->highlighted_item++;
		else
		   m->highlighted_item--;
#ifdef __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
        if (m->highlighted_item < m->first_displayed_item ||
            m->highlighted_item > m->last_displayed_item)
        {
            gui_list_menu_locate_highlighted_item(m);
        }
        else
#endif  /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */
        {
            if(IS_goto_next)
	            gui_list_menu_locate_next_item(m);
			else
				gui_list_menu_locate_previous_item(m);
        }
    }
#endif

    if (MMI_fixed_list_menu.menu_style == GUI_MENU_TYPE_ASYNCDYNAMIC && gui_asyncdynamic_list_error)
    {
        return;
    }
#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_KEY)
    if (gui_list_menu_is_support_smooth_scrolling())
    {
        if (MMI_fixed_list_menu.first_displayed_item == MMI_fixed_list_menu.highlighted_item && 
            MMI_fixed_list_menu.first_displayed_item > 0)
        {
            MMI_fixed_list_menu.first_displayed_item--;
            MMI_fixed_list_menu.last_displayed_item--;
        }
        else
        {
            gui_common_menuitem_base_struct *cm;
            S32 menu_height;

            cm = (gui_common_menuitem_base_struct*) MMI_fixed_list_menu.common_item_data;
            menu_height = MMI_fixed_list_menu.displayed_items * cm->height;
            if (gui_list_menu_is_highlight_item_two_line())
            {
                menu_height += cm->height;
            }

            if (MMI_fixed_list_menu.height < menu_height + (cm->height / 3))
            {
              if ((MMI_fixed_list_menu.highlighted_item == MMI_fixed_list_menu.last_displayed_item) && 
                  (MMI_fixed_list_menu.highlighted_item < (MMI_fixed_list_menu.n_items - 1)))
              {
                  MMI_fixed_list_menu.first_displayed_item++;
                  MMI_fixed_list_menu.last_displayed_item++;
              }
            }
        }
    }
#endif  /* GUI_LIST_MENU_SMOOTH_SCROLLING_BY_KEY */

    if (MMI_fixed_list_menu.menu_style == GUI_MENU_TYPE_DYNAMIC)
    {
       if(IS_goto_next)
       	{
	        if (m->flags & UI_LIST_MENU_DISABLE_CACHE_DYNAMIC_DATA)
	        {
	            flush_dynamic_item_buffer_before_load_chunk();
	        }
	        load_chunk_dynamic_item_buffer(
	            m->first_displayed_item,
	            m->last_displayed_item - m->first_displayed_item + 2);
       	}
        
        gui_dynamic_list_menu_switch_highlighted_item(m, last_highlighted_item);
    }
    else if (MMI_fixed_list_menu.menu_style == GUI_MENU_TYPE_ASYNCDYNAMIC)
    {
        gui_asyncdynamic_list_menu_switch_highlighted_item(m, last_highlighted_item);
    }
    else
    {
        gui_fixed_list_menu_switch_highlighted_item(m, last_highlighted_item);

#ifdef  __MMI_UI_HINTS_IN_MENUITEM__
        wgui_list_menu_locate_highlighted_item();
#endif  /* __MMI_UI_HINTS_IN_MENUITEM__ */

        if (gui_list_menu_has_multi_line(m)&&IS_goto_next)
        {
            /* for the suitation that, the last item is multiline,
             * and the multiline is half display in list menu, the pen down on the multiline
             * should change highlight to the multiline and the screen layout should not changed
             */
            if (m->highlighted_item == m->n_items - 1)
            {
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
                if (old_last == m->n_items - 1)
                {
                    m->first_displayed_item = old_first;
                    m->first_displayed_offset = old_first_offset;
                }
                else
                {
                    m->first_displayed_item = old_first + 1;
                    m->first_displayed_offset = 0;
                }
#else
                m->first_displayed_item = m->highlighted_item - displayed_items;
#endif
                if (m->first_displayed_item < 0)
                {
                    m->first_displayed_item = 0;
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_list_menu_goto_previous_item
 * DESCRIPTION
 *  Go to the item previous to the highlighted item.
 * PARAMETERS
 *  m       [IN]        list menu object     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_list_menu_goto_previous_item(fixed_list_menu *m)
{
    m->spacing = GUI_FIXED_LIST_PREV_ITEM;
	gui_list_menu_goto_next_item(m);
}


/* 
 * List menu
 */

/*****************************************************************************
 * FUNCTION
 *  UI_dummy_menuitem_displayed_function
 * DESCRIPTION
 *  Dummy item after display callback. This function is OBSOLETE.
 * PARAMETERS
 *  index       [IN]        item index
 *  x1          [IN]        x1
 *  y1          [IN]        y1
 *  x2          [IN]        x2
 *  y2          [IN]        y2
 * RETURNS
 *  void
 *****************************************************************************/
void UI_dummy_menuitem_displayed_function(S32 index, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(index);
    UI_UNUSED_PARAMETER(x1);
    UI_UNUSED_PARAMETER(y1);
    UI_UNUSED_PARAMETER(x2);
    UI_UNUSED_PARAMETER(y2);
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_fixed_list_menu_current_theme
 * DESCRIPTION
 *  Apply the current theme to a fixed list menu.
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_fixed_list_menu_current_theme(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_fixed_list_menu_theme(m, current_fixed_list_menu_theme);
}

/*****************************************************************************
 * FUNCTION
 *  gui_set_fixed_list_menu_theme
 * DESCRIPTION
 *  Apply the given theme to a fixed list menu.
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 *  t       [IN]        menu theme
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_resize_move_scrollbar(fixed_matrix_menu* m)
{
   gui_resize_vertical_scrollbar(
        &m->vbar,
        current_fixed_matrix_menu_theme->vbar_width,
        m->height - current_fixed_matrix_menu_theme->hbar_height);
    gui_move_vertical_scrollbar(&m->vbar, m->x + m->width - current_fixed_matrix_menu_theme->vbar_width, m->y);
    gui_resize_horizontal_scrollbar(
        &m->hbar,
        m->width - current_fixed_matrix_menu_theme->vbar_width,
        current_fixed_matrix_menu_theme->hbar_height);
    gui_move_horizontal_scrollbar(&m->hbar, m->x, m->y + m->height - current_fixed_matrix_menu_theme->hbar_height);
}

static void gui_set_vertical_scrollbar_range_scale_value(vertical_scrollbar* vbar, S32 r, S32 s, S32 v)
{
   gui_set_vertical_scrollbar_range(vbar, r);
   gui_set_vertical_scrollbar_scale(vbar, s);
   gui_set_vertical_scrollbar_value(vbar, v);
}

/*****************************************************************************
 * FUNCTION
 *  gui_set_fixed_list_menu_theme
 * DESCRIPTION
 *  Apply the given theme to a fixed list menu.
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 *  t       [IN]        menu theme
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_fixed_list_menu_theme(fixed_list_menu *m, UI_fixed_list_menu_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->flags |= t->flags;
    m->focussed_filler = t->focussed_filler;
    m->normal_filler = t->normal_filler;
    gui_resize_vertical_scrollbar(&m->vbar, t->vbar_width, m->vbar.height);
    gui_move_vertical_scrollbar(&m->vbar, m->x + m->width - current_fixed_list_menu_theme->vbar_width, m->y);
}



/*****************************************************************************
 * FUNCTION
 *  gui_create_fixed_menu
 * DESCRIPTION
 *  Create a fixed list menu.
 * PARAMETERS
 *  m           [IN]        fixed list menu object
 *  x           [IN]        x1
 *  y           [IN]        y1
 *  width       [IN]        width
 *  height      [IN]        height
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_create_fixed_menu(void *m0, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   fixed_menu* m = (fixed_menu*) m0;    
   //memset(m, 0, sizeof(fixed_menu));	
    m->x = x;
    m->y = y;
    m->width = width;
    m->height = height;

	//m->n_items = 0;
  //  m->items = NULL;
  //  m->highlighted_item = 0;
  //  m->item_height = 0;
  //  m->item_width = 0;

	
    m->item_highlighted = UI_dummy_function_s32;
    m->item_unhighlighted = UI_dummy_function_s32;
    m->item_display_function = UI_fixed_menuitem_dummy_display_function;
    m->item_hide_function = UI_fixed_menuitem_dummy_display_function;
    m->item_measure_function = UI_fixed_menuitem_dummy_measure_function;
    m->item_highlight_function = UI_fixed_menuitem_dummy_highlight_function;
    m->item_remove_highlight_function = UI_fixed_menuitem_dummy_remove_highlight_function;

	
#ifdef __MMI_TOUCH_SCREEN__
 //  m->pen_scroll_delay_time = 0;
   m->pen_scroll_after_delay = -1;
   m->pen_event_current_selected_callback_function = NULL;
   m->pen_event_default_selected_callback_function = NULL;
   m->tap_callback_funtion = NULL;
#endif 
}
/*****************************************************************************
 * FUNCTION
 *  gui_create_fixed_list_menu
 * DESCRIPTION
 *  Create a fixed list menu.
 * PARAMETERS
 *  m           [IN]        fixed list menu object
 *  x           [IN]        x1
 *  y           [IN]        y1
 *  width       [IN]        width
 *  height      [IN]        height
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_fixed_list_menu(fixed_list_menu *m, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(m, 0, sizeof(fixed_list_menu));
	gui_create_fixed_menu(m, x, y, width, height);
    gui_set_fixed_list_menu_current_theme(m);
    gui_create_vertical_scrollbar(
        &m->vbar,
        m->x + m->width - current_fixed_list_menu_theme->vbar_width,
        m->y,
        current_fixed_list_menu_theme->vbar_width,
        m->height);
    m->item_resize_function = UI_fixed_menuitem_dummy_resize_function;
    m->item_get_length_function = UI_fixed_menuitem_dummy_get_length_function;
    m->item_displayed_callback = UI_dummy_menuitem_displayed_function;
    m->resized_before_locate = MMI_FALSE;
    m->act_layer_handle = GDI_LAYER_MAIN_BASE_LAYER_HANDLE;
    m->act_lcd_handle = GDI_LCD_MAIN_LCD_HANDLE;
#ifdef __MMI_TOUCH_SCREEN__
    m->item_pen_function = UI_fixed_menuitem_dummy_pen_function;
    m->disable_move_highlight = MMI_FALSE;
    m->disable_up_select = MMI_FALSE;
    m->pen_scroll_after_delay = -1;
#endif /* __MMI_TOUCH_SCREEN__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  gui_autoresize_fixed_list_menu
 * DESCRIPTION
 *  Create a fixed list menu.
 * PARAMETERS
 *  m           [IN]        fixed list menu object
 *  x           [IN]        x1
 *  y           [IN]        y1
 *  width       [IN]        width
 *  height      [IN]        height
 * RETURNS
 *  void
 *****************************************************************************/
void gui_auto_resize_fixed_list_menu(fixed_list_menu *m, S32 max_width, S32 max_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, iwidth = 0, current_width = 0;
#ifdef __MMI_UI_LIST_HIGHLIGHT_BOLD
    stFontAttribute highlight_font;
#endif /*__MMI_UI_LIST_HIGHLIGHT_BOLD*/
	fixed_icontext_menuitem *m_item = (fixed_icontext_menuitem*) m->common_item_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_LIST_HIGHLIGHT_BOLD
    highlight_font = *m_item->text_font;
    highlight_font.bold = 2;
    gui_set_font(&highlight_font);
#else
	if (MMI_current_menu_type == LIST_MENU)
	{
		gui_set_font((UI_font_type)gui_font_get_type(GUI_FONT_SIZE_LIST_HIGHLIGHT));
	}
    else
    {
        gui_set_font(m_item->text_font);
    }
#endif
    for (i = 0; i < m->n_items; i++)
    {
        m->item_get_length_function(m->items[i], m->common_item_data, &iwidth);
        if (iwidth > current_width)
        {
            current_width = iwidth;
        }
    }
    current_width += GUI_MENUITEM_X1_GAP + GUI_MENUITEM_X2_GAP + GUI_TEXT_MENUITEM_TEXT_X + 
        GUI_MENUITEM_TEXT_RIGHT_GAP * 2 + m->vbar.width;

    if (current_width != m->width)
    {
        if (current_width > max_width)
        {
            current_width = max_width;
        }
        
        gui_resize_fixed_list_menu(m, current_width, m->height);
        gui_resize_fixed_icontext_menuitem(
            (fixed_icontext_menuitem *)m->common_item_data, 
            current_width - m->vbar.width - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP, 
            ((fixed_icontext_menuitem *)m->common_item_data)->height);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_resize_fixed_list_menu
 * DESCRIPTION
 *  Resize the fixed list menu.
 * PARAMETERS
 *  m           [IN]        fixed list menu object
 *  width       [IN]        width
 *  height      [IN]        height
 * RETURNS
 *  void
 *****************************************************************************/
void gui_resize_fixed_list_menu(fixed_list_menu *m, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->width = width;
    m->height = height;
    /* 
     * Example: change highlight in inline editor, list menu is resized 
     * according to virtual keyboard.
     * We have to recompute m->first_displayed_item
     */
    m->resized_before_locate = MMI_TRUE;
    gui_move_vertical_scrollbar(&m->vbar, m->x + m->width - current_fixed_list_menu_theme->vbar_width, m->y);
    gui_resize_vertical_scrollbar(&m->vbar, m->vbar.width, m->height);
}


/*****************************************************************************
 * FUNCTION
 *  gui_move_fixed_list_menu
 * DESCRIPTION
 *  Move the fixed list menu.
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 *  x       [IN]        x1
 *  y       [IN]        y1
 * RETURNS
 *  void
 *****************************************************************************/
void gui_move_fixed_list_menu(fixed_list_menu *m, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->x = x;
    m->y = y;
    gui_move_vertical_scrollbar(&m->vbar, m->x + m->width - current_fixed_list_menu_theme->vbar_width, m->y);
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_locate_highlighted_item
 * DESCRIPTION
 *  Locate the highlighted menu item.
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_list_menu_locate_highlighted_item(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.menu_style = GUI_MENU_TYPE_FIXED;
    gui_list_menu_locate_highlighted_item(m);
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_locate_previous_item
 * DESCRIPTION
 *  Locate the menu item previous to the highlighted item.
 * PARAMETERS
 *  m       [IN]        fixed list menu object   
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_fixed_list_menu_locate_previous_item(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_GUI_LIST_MENU_FULL_PACKAGE__
    if (m->flags & UI_LIST_MENU_CENTER_HIGHLIGHTED)
    {
        if (m->highlighted_item == 0)
        {
            m->first_displayed_item = m->n_items - 1;
            m->last_displayed_item = 1;
        }
        else
        {
            m->first_displayed_item = m->highlighted_item - 1;
            if (m->first_displayed_item < 0)
            {
                m->first_displayed_item = m->n_items - 1;
            }
            m->last_displayed_item = m->highlighted_item + 1;
            if (m->last_displayed_item > m->n_items - 1)
            {
                m->last_displayed_item = 0;
            }
        }
    }
    else
#endif
    {
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
        if (m->highlighted_item <= m->first_displayed_item)
        {
            if (m->first_displayed_offset != 0 && m->highlighted_item != 0)
            {
                m->first_displayed_item = m->highlighted_item - 1;
            }
            else
            {
                m->first_displayed_item = m->highlighted_item;
                m->first_displayed_offset = 0;
            }
        }
#else
        if (m->highlighted_item < m->first_displayed_item)
        {
            m->first_displayed_item = m->highlighted_item;
        }
#endif
        else if (m->resized_before_locate)
        {
            gui_fixed_list_menu_locate_highlighted_item(m);
        }
    #if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__)
        else if (m->highlighted_item == m->last_displayed_item - 1)
        {
            gui_list_menu_locate_item_compute_first(m);
        }
    #endif /* defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__) */ 
        else if (m->last_displayed_item == m->n_items - 1)
        {
            U8 done = gui_list_menu_locate_item_compute_first(m);
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
            if (done && m->first_displayed_item >= m->highlighted_item)
            {
                if (m->first_displayed_offset != 0 && m->highlighted_item != 0)
                {
                    m->first_displayed_item = m->highlighted_item - 1;
                }
                else
                {
                    m->first_displayed_item = m->highlighted_item;
                    m->first_displayed_offset = 0;
                }
            }
#else
            if (done && m->first_displayed_item > m->highlighted_item)
            {
                m->first_displayed_item = m->highlighted_item;
            }
#endif
        }
    }

    /* Located after resized */
    m->resized_before_locate = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_locate_next_item
 * DESCRIPTION
 *  Locate the menu item next to the highlighted item.
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_fixed_list_menu_locate_next_item(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__)
    U8 done = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_GUI_LIST_MENU_FULL_PACKAGE__
    if (m->flags & UI_LIST_MENU_CENTER_HIGHLIGHTED)
    {
        m->first_displayed_item = m->highlighted_item - 1;
        if (m->first_displayed_item < 0)
        {
            m->first_displayed_item = m->n_items - 1;
        }
        m->last_displayed_item = m->highlighted_item + 1;
        if (m->last_displayed_item >= m->n_items)
        {
            m->last_displayed_item = 0;
        }
    }
    else
#endif
    {
    #if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__)
        if (m->highlighted_item >= m->last_displayed_item ||
            m->last_displayed_item == m->n_items - 1)
        {
    #ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
            if (m->highlighted_item >= m->last_displayed_item)
            {
                if (m->last_displayed_offset != 0 && m->highlighted_item != m->n_items - 1)
                {
                    m->last_displayed_item = m->highlighted_item + 1;
                }
                else
                {
                    m->last_displayed_item = m->highlighted_item;
                    m->last_displayed_offset = 0;
                }
            }
    #else
            if (m->highlighted_item > m->last_displayed_item)
            {
                m->last_displayed_item = m->highlighted_item;
            }
    #endif
            done = gui_list_menu_locate_item_compute_first(m);
            if (!done)
            {
                m->first_displayed_item = 0;
    #ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
                m->first_displayed_offset = 0;
    #endif
            }
        }
        else if (m->resized_before_locate)
        {
            gui_fixed_list_menu_locate_highlighted_item(m);
        }
    #else /* (__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__) */
        #ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
        if (m->highlighted_item >= m->last_displayed_item)
        {
            if (m->last_displayed_offset != 0 && m->highlighted_item != m->n_items - 1)
            {
                m->last_displayed_item = m->highlighted_item + 1;
            }
            else
            {
                m->last_displayed_item = m->highlighted_item;
                m->last_displayed_offset = 0;
            }
            gui_list_menu_locate_item_compute_first(m);
        }
        #else
        if (m->highlighted_item > m->last_displayed_item)
        {
            m->last_displayed_item = m->highlighted_item;
            gui_list_menu_locate_item_compute_first(m);
        }
        #endif
        else if (m->resized_before_locate)
        {
            gui_fixed_list_menu_locate_highlighted_item(m);
        }
    #endif /* (__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__) */
    }

    /* Located after resized */
    m->resized_before_locate = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_switch_highlighted_item
 * DESCRIPTION
 *  Switch from the old highlighted item index to the new highlighted item.
 * PARAMETERS
 *  m                       [IN]        fixed list menu object          
 *  last_highlighted_item   [IN]        old highlighted menu item index
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_fixed_list_menu_switch_highlighted_item(fixed_list_menu *m, S32 last_highlighted_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m->highlighted_item == -1)
    {
        if ((last_highlighted_item >= 0) && (last_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(m->items[last_highlighted_item], m->common_item_data);
        }
        m->item_unhighlighted(last_highlighted_item);
    #ifdef __MMI_TOUCH_SCREEN__
        m->pen_event_current_selected_callback_function = m->pen_event_default_selected_callback_function;
    #endif 
    }
    else if (last_highlighted_item != m->highlighted_item)
    {
        if ((last_highlighted_item >= 0) && (last_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(m->items[last_highlighted_item], m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);
        }
        m->item_unhighlighted(last_highlighted_item);
    #ifdef __MMI_TOUCH_SCREEN__
        m->pen_event_current_selected_callback_function = m->pen_event_default_selected_callback_function;
    #endif 
        m->item_highlighted(m->highlighted_item);
    }

    m->displayed_items = m->last_displayed_item - m->first_displayed_item + 1;
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_goto_item
 * DESCRIPTION
 *  Go to a specified item index.
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 *  i       [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_list_menu_goto_item(fixed_list_menu *m, S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.menu_style = GUI_MENU_TYPE_FIXED;
    gui_list_menu_goto_item(m, i);
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_goto_next_item
 * DESCRIPTION
 *  Go to the item next to the highlighted item.
 * PARAMETERS
 *  m       [IN]        fixed list menu object   
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_list_menu_goto_next_item(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.menu_style = GUI_MENU_TYPE_FIXED;
    gui_list_menu_goto_next_item(m);
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_goto_previous_item
 * DESCRIPTION
 *  Go to the item previous to the highlighted item.
 * PARAMETERS
 *  m       [IN]        fixed list menu object     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_list_menu_goto_previous_item(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.menu_style = GUI_MENU_TYPE_FIXED;
    gui_list_menu_goto_previous_item(m);
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_goto_next_page
 * DESCRIPTION
 *  Go to the next page.
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_list_menu_goto_next_page(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_highlighted_item;
    S32 iwidth, iheight;
    U8 done = 0;
    S32 total_height = 0, i;
    S32 list_height = m->height - 4;
#if defined (__MMI_UI_LIST_SKIP_DISABLED__)
    U32 flags = 0, flags_ext = 0;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m->highlighted_item == GUI_LIST_MENU_ALL_ITEMS_ARE_DISABLE)
    {
        return;
    }

    last_highlighted_item = m->highlighted_item;
    m->first_displayed_item += m->displayed_items;
    if (m->first_displayed_item > (m->n_items - 1))
    {
        m->first_displayed_item = (m->n_items - 1);
        m->last_displayed_item = m->first_displayed_item;
    }
    else
    {
        for (i = m->first_displayed_item; (i < m->n_items) && (!done); i++)
        {
        #if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__)
            if (i == m->highlighted_item)
            {
                m->current_displayed_item = -1;
            }
            else
            {
                m->current_displayed_item = i;
            }
        #endif /* defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__) */ 
            m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);
            total_height += iheight;
            if (total_height > list_height + 1)
            {
                done = 1;
                m->last_displayed_item = i - 1;
            }
        }
    }
    for (i = m->last_displayed_item; i >= 0 && (!done); i--)
    {
    #if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__)
        if (i == m->highlighted_item)
        {
            m->current_displayed_item = -1;
        }
        else
        {
            m->current_displayed_item = i;
        }
    #endif /* defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__) */ 
        m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);
        total_height += iheight;
        if (total_height > list_height + 1)
        {
            done = 1;
            m->first_displayed_item = i + 1;
        }
    }
#if defined (__MMI_UI_LIST_SKIP_DISABLED__)
    m->item_get_flag_function(m->items[m->first_displayed_item], m->common_item_data,
        m->first_displayed_item, &flags, &flags_ext);
    
    while (flags & UI_MENUITEM_STATE_DISABLED)
    {
        if ( m->first_displayed_item == 0)        
        {
            break;
        }
        else
        {        
            m->first_displayed_item--;
        }
        m->item_get_flag_function(m->items[m->first_displayed_item], m->common_item_data,
            m->first_displayed_item, &flags, &flags_ext);
    }
#endif
    m->highlighted_item = m->first_displayed_item;

    gui_fixed_list_menu_switch_highlighted_item(m, last_highlighted_item);
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_goto_previous_page
 * DESCRIPTION
 *  Go to the previous page.
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_list_menu_goto_previous_page(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_highlighted_item;
#if defined (__MMI_UI_LIST_SKIP_DISABLED__)
    U32 flags = 0, flags_ext = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m->highlighted_item == GUI_LIST_MENU_ALL_ITEMS_ARE_DISABLE)
    {
        return;
    }

    last_highlighted_item = m->highlighted_item;
    m->first_displayed_item -= m->displayed_items;
    if (m->first_displayed_item < 0)
    {
        m->first_displayed_item = 0;
    }
#if defined (__MMI_UI_LIST_SKIP_DISABLED__)
    m->item_get_flag_function(m->items[m->first_displayed_item], m->common_item_data,
        m->first_displayed_item, &flags, &flags_ext);
    
    while (flags & UI_MENUITEM_STATE_DISABLED)
    {
        if ( m->first_displayed_item == 0)        
        {
            break;
        }
        else
        {        
            m->first_displayed_item--;
        }
        m->item_get_flag_function(m->items[m->first_displayed_item], m->common_item_data, 
            m->first_displayed_item, &flags, &flags_ext);
    }
#endif
    m->highlighted_item = m->first_displayed_item;
    if (last_highlighted_item == m->highlighted_item)
    {
        return;
    }
    gui_fixed_list_menu_locate_highlighted_item(m);

    gui_fixed_list_menu_switch_highlighted_item(m, last_highlighted_item);
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_goto_first_item
 * DESCRIPTION
 *  Go to the first item.
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_list_menu_goto_first_item(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_highlighted_item;
#if defined (__MMI_UI_LIST_SKIP_DISABLED__)
    U32 flags = 0, flags_ext = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m->highlighted_item == 0)
    {
        return;
    }
    last_highlighted_item = m->highlighted_item;
    m->highlighted_item = 0;
#if defined (__MMI_UI_LIST_SKIP_DISABLED__)
    m->item_get_flag_function(m->items[m->highlighted_item], m->common_item_data, 
        m->highlighted_item, &flags, &flags_ext);
    
    while (flags & UI_MENUITEM_STATE_DISABLED)
    {
        if ( m->first_displayed_item == m->n_items - 1)        
        {
            break;
        }
        else
        {
            m->highlighted_item++;
        }
        m->item_get_flag_function(m->items[m->highlighted_item], m->common_item_data, 
            m->highlighted_item, &flags, &flags_ext);
    }
#endif
    gui_fixed_list_menu_locate_highlighted_item(m);

    gui_fixed_list_menu_switch_highlighted_item(m, last_highlighted_item);
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_goto_last_item
 * DESCRIPTION
 *  Go to the last item.
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_list_menu_goto_last_item(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_highlighted_item;
#if defined (__MMI_UI_LIST_SKIP_DISABLED__)
    U32 flags = 0, flags_ext = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m->highlighted_item == (m->n_items - 1))
    {
        return;
    }
    last_highlighted_item = m->highlighted_item;
    m->highlighted_item = (m->n_items - 1);
#if defined (__MMI_UI_LIST_SKIP_DISABLED__)
    m->item_get_flag_function(m->items[m->highlighted_item], m->common_item_data, 
        m->highlighted_item, &flags, &flags_ext);
    
    while (flags & UI_MENUITEM_STATE_DISABLED)
    {
        if ( m->first_displayed_item == 0)        
        {
            break;
        }
        else
        {
            m->highlighted_item--;
        }
        m->item_get_flag_function(m->items[m->highlighted_item], m->common_item_data, 
            m->highlighted_item, &flags, &flags_ext);
    }
#endif
    gui_fixed_list_menu_locate_highlighted_item(m);

    gui_fixed_list_menu_switch_highlighted_item(m, last_highlighted_item);
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_list_menu_background_outside_area
 * DESCRIPTION
 *  Show the extended menu background outside the menu display area. 
 *
 *  For example, in handwriting mode of inline editor, we may want to draw 
 *  menu background in the bottom virtual keyboard area when the keyboard is hidden.
 *
 *  Note: This API does not use any menu cache
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 *  x1      [IN]        left-top x
 *  y1      [IN]        left-top y
 *  x2      [IN]        right-bottom x
 *  y2      [IN]        right-bottom y
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_list_menu_background_outside_area(fixed_list_menu *m, S32 x1, S32 y1, S32 x2, S32 y2)
{
    UI_filled_area *f;

    if (m->flags & UI_LIST_MENU_STATE_FOCUSSED)
    {
        if ((m->flags & UI_LIST_MENU_DISABLE_SCROLLBAR) ||
            ((m->flags & UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR) && (m->displayed_items >= m->n_items)))
        {
            f = m->focussed_without_sc_filler;
        }
        else
        {
            f = m->focussed_filler;
        }
    }
    else
    {
        f = m->normal_filler;
    }

    gui_push_and_set_clip(x1, y1, x2, y2);

    gui_draw_filled_area(m->x, m->y, x2, y2, f);
        
    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_list_menu_check_scrollbar
 * DESCRIPTION
 *  Helper function of gui_show_fixed_list_menu.
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_show_list_menu_check_scrollbar(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL show_scrollbar = MMI_FALSE;
    S32 width = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check presence of scrollbar */
    if (!(m->flags & UI_LIST_MENU_DISABLE_SCROLLBAR))
    {
        if (m->flags & UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR)
        {
            /* FIXME. we need to compute m->displayed_items twice */
            gui_show_list_menu_no_draw(m);
            if (m->first_displayed_item > 0)
            {
                show_scrollbar = MMI_TRUE;
            }
            else
            {
                if (m->displayed_items < m->n_items)
                {
                    show_scrollbar = MMI_TRUE;
                }
            }
        }
        else
        {
            show_scrollbar = MMI_TRUE;
        }
    }

    if (!show_scrollbar)
    {
        gui_resize_vertical_scrollbar(&m->vbar, m->vbar.width, 0);
    }
    else
    {
        gui_resize_vertical_scrollbar(&m->vbar, m->vbar.width, m->height);
    }

    if (MMI_current_menu_type == LIST_MENU)
    {
        if (!show_scrollbar)
        {
            if (MMI_fixed_list_menu.width == MMI_content_width)
            {
                width = MMI_fixed_list_menu.width - 2 - GUI_LIST_MENU_X2_GAP;
            }
        }
        else
        {
#ifdef __MMI_FTE_SUPPORT__
            width = MMI_fixed_list_menu.width - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP;
#else
            width = MMI_fixed_list_menu.width - MMI_fixed_list_menu.vbar.width - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP;
#endif
        }
        m->item_resize_function(width, 0);
    }

    return show_scrollbar;
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_list_menu_config_item_region
 * DESCRIPTION
 *  Helper function of gui_show_fixed_list_menu.
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_list_menu_config_item_region(fixed_list_menu *m, S32 *x1, S32 *x2, S32 *y1, MMI_BOOL show_scrollbar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(m->flags & UI_LIST_MENU_DISABLE_MENUITEM_GAP))
    {
        if (mmi_fe_get_r2l_state())
        {
            *x1 += GUI_MENUITEM_X2_GAP;
            *x2 -= GUI_MENUITEM_X1_GAP;
        }
        else
        {
            *x1 += GUI_MENUITEM_X1_GAP;
            *x2 -= GUI_MENUITEM_X2_GAP;    
        }
    }

#ifndef __MMI_FTE_SUPPORT__
    /* Configure region of menu items */
    if (show_scrollbar)
    {
        if (!mmi_fe_get_r2l_state())
        {
            *x2 -= m->vbar.width;
        }
        else
        {
            *x1 += m->vbar.width;
        }
    }
    else
    {
        if (!mmi_fe_get_r2l_state())
        {
            *x2 -= 2;
        }
    }
#endif /* __MMI_FTE_SUPPORT__ */

    if (!show_scrollbar && mmi_fe_get_r2l_state() && MMI_current_menu_type == LIST_MENU && MMI_fixed_list_menu.width == MMI_content_width)
    {
        *x1 += GUI_LIST_MENU_X2_GAP;
    }

    *y1 = m->y + m->top;
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_list_menu_scrollbar
 * DESCRIPTION
 *  Helper function of gui_show_fixed_list_menu.
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_list_menu_scrollbar(fixed_list_menu *m, U8 disable_draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 total_height, list_height;
    S32 iwidth = 0, iheight = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
#ifdef __MMI_FTE_SUPPORT__
    gdi_handle layers[4];
    S32 clip_x1, clip_x2, clip_y1, clip_y2;
    U8* buf_ptr = NULL;
    U8* static_layer_buf_ptr = NULL;
    U8 *bg_buf_ptr = NULL;
    S32 buf_offset, copy_buf_size;

    clip_x1 = m->x;
    clip_y1 = m->y;
    clip_x2 = m->x + m->width - 1;
    clip_y2 = m->y + m->height - 1;

    gui_vertical_scrollbar_enable_clear_background(&m->vbar, MMI_FALSE);
#ifdef  __COSMOS_MMI__		
    if (m->act_layer_handle)
    {
        gui_vertical_scrollbar_set_target_layer(&m->vbar, m->act_layer_handle);
        gui_vertical_scrollbar_set_alpha_blend_layer(&m->vbar, m->act_layer_handle);
    }
#else
    if (MMI_fixed_list_menu.act_layer_handle)
    {
        gui_vertical_scrollbar_set_target_layer(&m->vbar, MMI_fixed_list_menu.act_layer_handle);
        gui_vertical_scrollbar_set_alpha_blend_layer(&m->vbar, MMI_fixed_list_menu.act_layer_handle);
    }
#endif        
    else
    {
        gdi_handle act_layer;
        gdi_layer_get_active(&act_layer);
        gui_vertical_scrollbar_set_target_layer(&m->vbar, act_layer);
        gui_vertical_scrollbar_set_alpha_blend_layer(&m->vbar, act_layer);
    }
    gdi_layer_get_blt_layer(&layers[0], &layers[1], &layers[2], &layers[3]);
    if (mmi_fe_get_r2l_state())
    {
        gui_push_and_set_clip(
            MMI_fixed_list_menu.x, 
            MMI_fixed_list_menu.y, 
            MMI_fixed_list_menu.x + MMI_fixed_list_menu.vbar.width - 1, 
            MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1);
    }
    else
    {
        gui_push_and_set_clip(
            MMI_fixed_list_menu.x + MMI_fixed_list_menu.width - 1 - MMI_fixed_list_menu.vbar.width, 
            MMI_fixed_list_menu.y, 
            MMI_fixed_list_menu.x + MMI_fixed_list_menu.width - 1, 
            MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1);
    }    

    gdi_layer_get_buffer_ptr(&buf_ptr);

    if (g_gui_ssp_static_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_push_and_set_active(g_gui_ssp_static_layer);
        gdi_layer_get_buffer_ptr(&static_layer_buf_ptr);
        gdi_layer_pop_and_restore_active();
    }
    
    buf_offset = UI_DEVICE_WIDTH * m->y * GUI_SCREEN_SWITCH_EFFECT_LAYER_COLOR_FORMAT;
    copy_buf_size = UI_DEVICE_WIDTH * m->height * GUI_SCREEN_SWITCH_EFFECT_LAYER_COLOR_FORMAT;
    
#ifdef  __COSMOS_MMI__
    if (vfx_sys_get_canvas_state() != VFX_SYS_STATE_ENTRY)
#endif
    {
    if (wgui_is_wallpaper_on_bottom() && layers[0] != dm_get_scr_bg_layer() && dm_get_scr_bg_layer() != 0)
    {
        if (g_gui_ssp_static_layer != GDI_NULL_HANDLE)
        {
            gdi_layer_push_and_set_active(dm_get_scr_bg_layer());
            gdi_layer_get_buffer_ptr(&bg_buf_ptr);
            gdi_layer_pop_and_restore_active();
        }
        else
        {
            gdi_layer_flatten_with_clipping(dm_get_scr_bg_layer(), layers[0], layers[1], layers[2]);
        }
    }
    else
    {
        if (g_gui_ssp_static_layer)
        {
            gdi_layer_push_and_set_active(layers[0]);
            gdi_layer_get_buffer_ptr(&bg_buf_ptr);
            gdi_layer_pop_and_restore_active();
        }
        else
        {
            gdi_layer_flatten_with_clipping(layers[0], layers[1], layers[2], layers[3]);
        }   
    }   

    if (g_gui_ssp_static_layer)
    {
        memcpy(static_layer_buf_ptr + buf_offset, bg_buf_ptr+ buf_offset, copy_buf_size);

        /* use static layer buffer as temp buffer to store the flatten result layer buffer */
        gd_bitblt[2](
            static_layer_buf_ptr,
            UI_DEVICE_WIDTH,
            UI_DEVICE_HEIGHT,
            clip_x1,   //clip_x1,
            clip_y1,   //clip_y1,
            clip_x2,   //clip_x2,
            clip_y2,   //clip_y2,
            buf_ptr,
            UI_DEVICE_WIDTH,
            UI_DEVICE_HEIGHT,
            clip_x1,
            clip_y1,
            clip_x2,
            clip_y2,
            clip_x1,
            clip_y1,
            clip_x2,
            clip_y2,
            GDI_COLOR_TRANSPARENT,
            0x01ffffff);
        memcpy(buf_ptr + buf_offset, static_layer_buf_ptr + buf_offset, copy_buf_size);
    }

    if (g_gui_ssp_static_layer)
    {
        /* clear the list area in util layer to make sure display normal */
        gdi_layer_push_and_set_active(g_gui_ssp_static_layer);
        gdi_draw_solid_rect(m->x, m->y, m->x + m->width, m->y + m->height - 1, GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    }
    }
    gui_pop_clip();
#endif

    /* FIXME. debug only. we can remove the check in the future */
    //MMI_DBG_ASSERT(!(m->flags & UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR) ||
    //               (total_height > list_height + 1) || (m->first_displayed_item > 0));

    if (mmi_fe_get_r2l_state())
    {
        gui_move_vertical_scrollbar(&m->vbar, m->x, m->y);
    }
    else
    {
        gui_move_vertical_scrollbar(&m->vbar, m->x + m->width - m->vbar.width, m->y);
    }

#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
    total_height = 0;
    list_height = 0;
    for(i = 0; i < MMI_fixed_list_menu.n_items; i++)
    {
        gui_list_menu_measure_item(m, i, &iwidth, &iheight);
        if (i < m->first_displayed_item)
        {
            list_height += iheight;
        }
        else if (i == m->first_displayed_item)
        {
            list_height += m->first_displayed_offset;
        }
        total_height += iheight;
    }
	gui_set_vertical_scrollbar_range_scale_value(&m->vbar, total_height, m->height, list_height);
#else
    if (m->flags & UI_LIST_MENU_INLINE_EDIT
#if defined(__MMI_UI_LIST_SUPPORT_UNEQUAL_HEIGHT_ITEM__)
        || m->flags & UI_LIST_MENU_INEQUAL_HEIGHT_ITEMS
#endif
        )
    {
        total_height = 0;
        list_height = 0;
        for(i = 0; i < MMI_fixed_list_menu.n_items; i++)
        {
            MMI_fixed_list_menu.current_displayed_item = i;
            MMI_fixed_list_menu.item_measure_function(
                MMI_fixed_list_menu.items[i], 
                MMI_fixed_list_menu.common_item_data, 
                &iwidth, 
                &iheight);
            if (i < m->first_displayed_item)
            {
                list_height += iheight;
            }
            total_height += iheight;
        }
		gui_set_vertical_scrollbar_range_scale_value(&m->vbar,total_height, m->height,list_height);
    }
    else
    {
		gui_set_vertical_scrollbar_range_scale_value(&m->vbar,m->n_items,m->displayed_items, m->first_displayed_item);
    }
#endif

    if (!disable_draw)
    {
        gui_show_vertical_scrollbar(&m->vbar);
    }
}



/*****************************************************************************
 * FUNCTION
 *  gui_show_fixed_list_menu_draw_bg
 * DESCRIPTION
 *  Helper function of gui_show_fixed_list_menu.
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_show_fixed_list_menu_draw_bg(fixed_list_menu *m, S32 x1, S32 y1, S32 x2, S32 y2, UI_filled_area *f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (g_gui_list_hide_menu)
    {
        g_gui_list_hide_menu(x1, y1, x2, y2);
    }
    else if (!(m->flags & UI_LIST_MENU_DISABLE_BKGRND_IN_LAYER) && (wgui_is_wallpaper_on_bottom() == MMI_TRUE))
    {
        gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
#if (defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__))
        if (gui_get_transparent_source_layer() == GDI_LAYER_EMPTY_HANDLE)   /* 110705 WAP menu Clavin add */
        {
            gui_set_transparent_source_layer(dm_get_scr_bg_layer());        /* should remove */
        }
#endif /* (defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__)) */ 
    }
    else
    {
#if !defined(MT6205B) && !defined(MT6208)
        gui_draw_filled_area(x1, y1, x2, y2, f);
#else /* !defined(MT6205B) && !defined(MT6208) */
        /* For low-end phone, disable list menu background can greately improve menu performance. 
        We use the color of filler to draw the background (typically white). */
        color c = f->c;
        gdi_draw_solid_rect(x1, y1, x2, y2, gdi_act_color_from_rgb(255, c.r, c.g, c.b));
#endif /* !defined(MT6205B) && !defined(MT6208) */
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_fixed_list_menu
 * DESCRIPTION
 *  Show the fixed list menu.
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_fixed_list_menu(fixed_list_menu *m)
{
    gui_show_fixed_list_menu_specified_item(m, GUI_SHOW_FIXED_MENU);

}

/*****************************************************************************
 * FUNCTION
 *  gui_show_fixed_list_menu_specified_item
 * DESCRIPTION
 *  Show the specified fixed list menu.
 * PARAMETERS
 *  m           [IN]        fixed list menu object
 *  item_index  [IN]        specified list menu item
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_fixed_list_menu_specified_item(fixed_list_menu *m, S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, y_offset, h;//, orginal_x1;
#ifndef __MMI_UI_MENU_SLIM__
    S32 orginal_x1;
#endif
    UI_filled_area *f;
    S32 i;
    S32 cx1, cy1, cx2, cy2;
    S32 tx1, ty1, tx2, ty2;
    S32 iwidth = 0, iheight = 0;
    U8 done = 0;
    S32 total_height, counter, list_height;
    U8 disable_draw = 0;
    MMI_BOOL show_scrollbar;
#ifdef __MMI_UI_LIST_GRID_LINE__
	S32 grid_x;
    gdi_handle alpha_layer;
#endif

    
	gui_common_menuitem_base_struct *cm=NULL;//show list menu
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
//hujin
    if(item_index == GUI_SHOW_FIXED_MENU)
    {       
	    m->menu_style = GUI_MENU_TYPE_FIXED;
		cm = (gui_common_menuitem_base_struct *)m->common_item_data;
	}

    if (m->flags & UI_LIST_MENU_DISABLE_DRAW)
    {
        disable_draw = 1;
    }
    gui_get_clip(&cx1, &cy1, &cx2, &cy2);
    gui_get_text_clip(&tx1, &ty1, &tx2, &ty2);

    x1 = m->x;
    y1 = m->y;
    x2 = x1 + m->width - 1;
    y2 = y1 + m->height - 1;

#ifdef __MMI_GUI_LIST_MENU_FULL_PACKAGE__
    if (m->flags & UI_LIST_MENU_STATE_FOCUSSED)
    {
        if ((m->flags & UI_LIST_MENU_DISABLE_SCROLLBAR) ||
            ((m->flags & UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR) && (m->displayed_items >= m->n_items)))
        {
            f = m->focussed_without_sc_filler;
        }
        else
        {
            f = m->focussed_filler;
        }
    }
    else
#endif
    {
        f = m->normal_filler;
    }

    //hujin
   show_scrollbar = gui_show_list_menu_check_scrollbar(m);

if(item_index != GUI_SHOW_FIXED_MENU)//
{
	list_height = m->height;
    gui_show_list_menu_config_item_region(m, &x1, &x2, &y1, show_scrollbar);

    total_height = 0;
    counter = 0;
    m->current_displayed_item = -1;

	

#ifdef	__MMI_UI_LIST_GRID_LINE__	
	/* calculate the x pos of grid line */
//hujin
//	if (r2lMMIFlag)
    if(mmi_fe_get_r2l_state())
    {
        grid_x = x1 + GUI_MENUITEM_X2_GAP;
#ifndef __MMI_FTE_SUPPORT__
        if (show_scrollbar)
        {
            grid_x = grid_x + m->vbar.width;
        }
        else
#endif /* __MMI_FTE_SUPPORT__ */
        {
            grid_x += GUI_LIST_MENU_X2_GAP;
        }
    }
    else
    {
        grid_x = x1 + GUI_MENUITEM_X1_GAP;    
    }
#endif	/* __MMI_UI_LIST_GRID_LINE__ */

#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
    total_height -= m->first_displayed_offset;
#endif
    for (i = m->first_displayed_item; (i < m->n_items && !done); i++)
    {
        gui_list_menu_measure_item(m, i, &iwidth, &iheight);
		x1 += (x2 - x1 - iwidth + 1) >> 1;

        y_offset = total_height;
		
        total_height += iheight;
        if (total_height > list_height + 1)
        {
            done = 1;
        }
        else
        {
            if (!disable_draw)
            {
                if (i == m->highlighted_item)
                {
                    m->highlight_x = x1;
                    m->highlight_y = y_offset + y1;
                }
            }
            counter++;
        }
        if (i == item_index)
        {
            done = 1;
            y2 = y_offset + y1 + iheight - 1;
            if (y2 > (MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1))
            {
#ifndef __MMI_FTE_SUPPORT__
                // doesn't support display half menu item
                break;
#else
                y2 = MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1;
#endif
            }
            if (!disable_draw && (!(m->flags & UI_LIST_MENU_DISABLE_BACKGROUND)) && MMI_current_menu_type != PAGE_MENU)
            {
                S32 y1_clip = y1 + y_offset;
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
                if (y_offset < 0)
                {
                    y1_clip = y1;
                }
#endif
#ifdef __MMI_FTE_SUPPORT__
                if (show_scrollbar)
                {
                //hujin
                
                //    if (r2lMMIFlag)
                    if(mmi_fe_get_r2l_state())
				    {
                        gui_set_clip(x1 + m->vbar.width, y1_clip, x2, y2);
                    }
                    else
                    {
                        gui_set_clip(x1, y1_clip, x2 - m->vbar.width, y2);
                    }
                }
                else
#endif	/* __MMI_FTE_SUPPORT__ */
                {
                    gui_set_clip(x1, y1_clip, x2, y2);
                }
                
                gui_show_fixed_list_menu_draw_bg(m, x1, y1 + y_offset, x2, y2, f);

                /* start to draw grid line */
#ifdef	__MMI_UI_LIST_GRID_LINE__
                if (m->flags & UI_LIST_MENU_INLINE_EDIT)
                {
                    if ((i > 0) && (wgui_inline_editor_if_need_draw_separator_line(i - 1)))
                    {
                        if (MMI_fixed_list_menu.alpha_blend_layer_handle)
                        {
                            alpha_layer = MMI_fixed_list_menu.alpha_blend_layer_handle; 
                        }
                        else 
                        {
                            alpha_layer = dm_get_scr_bg_layer();   
                            if (alpha_layer == GDI_ERROR_HANDLE)
                            {
                                gdi_layer_get_active(&alpha_layer);
                            }
                        }
                        gdi_effect_alpha_blending_rect(
                            alpha_layer, 
                            grid_x, 
                            y1 + y_offset, 
                            grid_x + iwidth - 1, 
                            y1 + y_offset, 
                            current_MMI_theme->list_grid_line_alpha * 255 / 100,
                            current_MMI_theme->list_grid_line_color->r,
                            current_MMI_theme->list_grid_line_color->g,
                            current_MMI_theme->list_grid_line_color->b);
                    }
                }
                else
                {
                    if (m->key_info != GUI_LIST_KEY_INFO_UP || 
                        item_index != m->highlighted_item 
                    #ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
                        || gui_get_current_list_effect() != MMI_UI_LIST_HIGHLIGHT_EFFECT_SLIDE
                    #endif
                        )
                    {
                        gdi_effect_alpha_blending_rect(
                            alpha_layer, 
                            grid_x, 
                            y1 + y_offset, 
                            grid_x + iwidth - 1, 
                            y1 + y_offset, 
                            current_MMI_theme->list_grid_line_alpha * 255 / 100,
                            current_MMI_theme->list_grid_line_color->r,
                            current_MMI_theme->list_grid_line_color->g,
                            current_MMI_theme->list_grid_line_color->b);
                    }
                }
#endif	/* __MMI_UI_LIST_GRID_LINE__ */
            }
            m->item_display_function(m->items[i], m->common_item_data, x1, y_offset + y1);            
        }
    }
}
else
{
		if (!disable_draw && (!(m->flags & UI_LIST_MENU_DISABLE_BACKGROUND)) && MMI_current_menu_type != PAGE_MENU)
		{
			gui_set_clip(x1, y1, x2, y2);
	
			gui_show_fixed_list_menu_draw_bg(m, x1, y1, x2, y2, f);
	
#ifdef __MMI_UI_LIST_GRID_LINE__
			//hujin
			//unimportant issues
        #ifndef __MMI_UI_MENU_SLIM__
			if (m->flags & UI_LIST_MENU_INLINE_EDIT && (!(m->flags & UI_LIST_MENU_DISABLE_GRID_LINE)))
		#else	
			if (m->flags & UI_LIST_MENU_INLINE_EDIT)
		#endif
			{
				S32 line_height = 0, highlight_height = 0, grid_x = 0;
	
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
				line_height = y1 - m->first_displayed_offset;
#else
				line_height = y1;
#endif
	//hujin
				//if (r2lMMIFlag)
				if(mmi_fe_get_r2l_state())
				{
					grid_x = x1 + GUI_MENUITEM_X2_GAP;
#ifndef __MMI_FTE_SUPPORT__
					if (show_scrollbar)
					{
						grid_x = grid_x + m->vbar.width;
					}
					else
#endif /* __MMI_FTE_SUPPORT__ */
					{
						grid_x += GUI_LIST_MENU_X2_GAP;
					}
				}
				else
				{
					grid_x = x1 + GUI_MENUITEM_X1_GAP;	  
				}
	
				for (i = m->first_displayed_item; i <= m->last_displayed_item; i++)
				{
					if(i != m->highlighted_item)
					{
						MMI_fixed_list_menu.current_displayed_item = i;
					}
					else
					{
						MMI_fixed_list_menu.current_displayed_item = -1;
					}
					m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &highlight_height);
					line_height += highlight_height;
					if (wgui_inline_editor_if_need_draw_separator_line(i))
					{
						if (MMI_fixed_list_menu.alpha_blend_layer_handle)
						{
							alpha_layer = MMI_fixed_list_menu.alpha_blend_layer_handle; 
						}
						else 
						{
							alpha_layer = dm_get_scr_bg_layer();   
							if (alpha_layer == GDI_ERROR_HANDLE)
							{
								gdi_layer_get_active(&alpha_layer);
							}
						}
						gdi_effect_alpha_blending_rect(
							alpha_layer, 
							grid_x, 
							line_height, 
							grid_x + iwidth - 1, 
							line_height, 
							current_MMI_theme->list_grid_line_alpha * 255 / 100,
							current_MMI_theme->list_grid_line_color->r,
							current_MMI_theme->list_grid_line_color->g,
							current_MMI_theme->list_grid_line_color->b);
					}
				}
				if (line_height < y2 &&
					((wgui_inline_items[m->n_items - 1].flags & 0xFF) != INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY) &&
					((wgui_inline_items[m->n_items - 1].flags & 0xFF) != INLINE_ITEM_TYPE_MULTI_LINE_EDIT)
				   )
				{
					while (line_height < y2)
					{
						alpha_layer = dm_get_scr_bg_layer();						
						if (MMI_fixed_list_menu.alpha_blend_layer_handle)
						{
							alpha_layer = dm_get_scr_bg_layer(); 
						}
						else 
						{
							alpha_layer = dm_get_scr_bg_layer();   
							if (alpha_layer == GDI_ERROR_HANDLE)
							{
								gdi_layer_get_active(&alpha_layer);
							}
						}
						gdi_effect_alpha_blending_rect(
							alpha_layer, 
							grid_x, 
							line_height, 
							grid_x + iwidth - 1, 
							line_height, 
							current_MMI_theme->list_grid_line_alpha * 255 / 100,
							current_MMI_theme->list_grid_line_color->r,
							current_MMI_theme->list_grid_line_color->g,
							current_MMI_theme->list_grid_line_color->b);
						line_height += highlight_height;						
						if (highlight_height == 0)
						{
							break;
						}
					}
				}
			}
			//hujin
			//unimportant issues
		#ifndef __MMI_UI_MENU_SLIM__
			else if (m->n_items > 0 && (!(m->flags & UI_LIST_MENU_DISABLE_GRID_LINE)))
		#else
			else if (m->n_items > 0)
		#endif
			{
				S32 line_height, display_index, index, highlight_height, grid_x;
	
				iheight = 0;
				m->current_displayed_item = -1; 			   
				m->item_measure_function(m->items[m->highlighted_item], m->common_item_data, &iwidth, &highlight_height);
				index = m->current_displayed_item;
				display_index = m->first_displayed_item;
				//hujin
				//if (r2lMMIFlag)
				if(mmi_fe_get_r2l_state())
				{
					grid_x = x1 + GUI_MENUITEM_X2_GAP;
#ifndef __MMI_FTE_SUPPORT__
					if (show_scrollbar)
					{
						grid_x = grid_x + m->vbar.width;
					}
					else
#endif /* __MMI_FTE_SUPPORT__ */
					{
						grid_x += GUI_LIST_MENU_X2_GAP;
					}
				}
				else
				{
					grid_x = x1 + GUI_MENUITEM_X1_GAP;	  
				}
				if (m->highlighted_item >= 1 || m->n_items == 1)
				{
					m->current_displayed_item = 0;				  
					m->item_measure_function(m->items[0], m->common_item_data, &iwidth, &iheight);
				}
				else if (m->n_items != 0)
				{
					m->current_displayed_item = 1;				  
					m->item_measure_function(m->items[1], m->common_item_data, &iwidth, &iheight);
				}
				if (iheight)
				{
					if (display_index == m->highlighted_item)
					{
						line_height = y1 + highlight_height;
					}
					else
					{
						line_height = y1 + iheight;
					}
					line_height += m->top;
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
					line_height -= m->first_displayed_offset;
#endif
					while (line_height < y2)
					{
						alpha_layer = dm_get_scr_bg_layer();						
						if (MMI_fixed_list_menu.alpha_blend_layer_handle)
						{
							alpha_layer = dm_get_scr_bg_layer(); 
						}
						else 
						{
							alpha_layer = dm_get_scr_bg_layer();   
							if (alpha_layer == GDI_ERROR_HANDLE)
							{
								gdi_layer_get_active(&alpha_layer);
							}
						}
						if (m->key_info != GUI_LIST_KEY_INFO_UP || 
							m->key_info != GUI_LIST_KEY_INFO_DOWN 
                    #ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
							|| gui_get_current_list_effect() != MMI_UI_LIST_HIGHLIGHT_EFFECT_SLIDE
                    #endif                            
							)
						{
							gdi_effect_alpha_blending_rect(
								alpha_layer, 
								grid_x, 
								line_height, 
								grid_x + iwidth - 1, 
								line_height, 
								current_MMI_theme->list_grid_line_alpha * 255 / 100,
								current_MMI_theme->list_grid_line_color->r,
								current_MMI_theme->list_grid_line_color->g,
								current_MMI_theme->list_grid_line_color->b);
						}
						
						display_index ++;	
						//hujin
						//unimportant issues
					#ifndef __MMI_UI_MENU_SLIM__
						if ((m->flags & UI_LIST_MENU_DISABLE_EXT_GRID_LINE) && (display_index > m->n_items - 1))
						{
							break;
						}
					#endif
						if (display_index == m->highlighted_item)
						{	
							line_height += highlight_height;						
						}
						else
						{
							line_height += iheight; 					   
						}
					}
				}
				m->current_displayed_item = index;						   
			}
#endif /* __MMI_UI_LIST_GRID_LINE__ */
		}
	
#ifdef __MMI_GUI_LIST_MENU_FULL_PACKAGE__
		if (m->flags & UI_LIST_MENU_ENABLE_TRANSITION)
		{
			color c = gui_color(255, 255, 255);
	//hujin
		//	gui_push_clip();
			gui_push_and_set_clip(x1, y1, x2, y2);
			gui_fill_rectangle(x1, y1, x2, y2, c);
			gui_pop_clip();
		}
#endif
	
		if (m->n_items <= 0)
		{
			gui_set_clip(cx1, cy1, cx2, cy2);
			gui_set_text_clip(tx1, ty1, tx2, ty2);
			return;
		}
	//hujin
		/* Configure region of menu items */
		gui_show_list_menu_config_item_region(m, &x1, &x2, &y1, show_scrollbar);
	
		/* Display menu items */
		if (MMI_current_menu_type == PAGE_MENU)
		{
#ifdef __MMI_MAINLCD_96X64__
			gui_set_clip(m->x, m->y, x2, y2);
			gui_show_fixed_list_menu_draw_bg(m, m->x, m->y, x2, y2, f);
#endif
			if (!disable_draw)
			{
				m->item_display_function(m->items[m->highlighted_item], m->common_item_data, m->x, m->y);
			}
			
			gui_set_clip(cx1, cy1, cx2, cy2);
			gui_set_text_clip(tx1, ty1, tx2, ty2);
			return;
		}
	
#ifdef __MMI_OP11_SIDEBAR__
		wgui_clock_close(g_gui_list_clock);
		g_gui_list_clock = WGUI_CLOCK_INVALID_INDEX;
#endif
	
		list_height = m->height;
	
		if ((x2 - x1 + 1) < cm->width)
		{
			x2 = x1 + cm->width - 1;
		}
	
		gui_set_text_clip(x1, y1, x2, y2);
		gui_set_clip(x1, y1, x2, y2);
		total_height = 0;
		counter = 0;
		m->current_displayed_item = -1;
	
#ifdef __MMI_GUI_LIST_MENU_FULL_PACKAGE__
		if (m->flags & UI_LIST_MENU_CENTER_HIGHLIGHTED)
		{
			m->item_measure_function(m->items[m->highlighted_item], m->common_item_data, &iwidth, &iheight);
	
			x1 += (x2 - x1 - iwidth + 1) >> 1;
			m->current_displayed_item = m->first_displayed_item;
			m->item_display_function(m->items[m->first_displayed_item], m->common_item_data, x1, y1);
	
			m->current_displayed_item = m->highlighted_item;
			m->item_display_function(m->items[m->highlighted_item], m->common_item_data, x1, y1 + iheight);
	
			m->current_displayed_item = m->last_displayed_item;
			m->item_display_function(m->items[m->last_displayed_item], m->common_item_data, x1, y1 + iheight * 2);

			gui_set_clip(cx1, cy1, cx2, cy2);
            gui_set_text_clip(tx1, ty1, tx2, ty2);
			return;
		}
		else
#endif
		{
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
			total_height -= m->first_displayed_offset;
#endif
	//hujin
	//unimportant issues
	#ifndef __MMI_UI_MENU_SLIM__
			orginal_x1 = x1;
	#endif
			for (i = m->first_displayed_item; (i < m->n_items && !done); i++)
			{
				gui_list_menu_measure_item(m, i, &iwidth, &iheight);
				//hujin
				//unimportant issues
			#ifndef __MMI_UI_MENU_SLIM__
				x1 = orginal_x1 + ((x2 - orginal_x1 - iwidth + 1) >> 1);
			#else			
				x1 += (x2 - x1 - iwidth + 1) >> 1;
			#endif
	
				y_offset = total_height;
		
				total_height += iheight;
	
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__			
				if (i == m->first_displayed_item && m->first_displayed_offset > 0 || total_height > list_height + 1)
#else
				if (total_height > list_height + 1)
#endif					
				{
					U32 flags = 0, flags_ext = 0;
	
					g_current_display_half_menuitem = MMI_TRUE;
					/* This is required so that in trnasition if theire is no area to display the menu item it is not displayed */
					if (m->flags & UI_LIST_MENU_INLINE_EDIT)
					{
						m->item_get_flag_function(m->items[i], m->common_item_data, 
							m->highlighted_item, &flags, &flags_ext);
#ifdef __MMI_FTE_SUPPORT__
						if (((total_height - iheight) < list_height) &&
							!disable_draw && !(m->flags & UI_LIST_MENU_ENABLE_TRANSITION) || 
							((flags & UI_MENUITEM_INLINE_EDIT_OBJECT) && 
							((wgui_inline_items[i].flags & 0xFF) == INLINE_ITEM_TYPE_MULTI_LINE_EDIT)))
#else /* __MMI_FTE_SUPPORT__ */
#ifdef __OP01_FWPBW__
						if (MMI_FALSE)
#else   // __OP01_FWPBW__
						if (!disable_draw && !(m->flags & UI_LIST_MENU_ENABLE_TRANSITION) || 
							((flags & UI_MENUITEM_INLINE_EDIT_OBJECT) && 
							((wgui_inline_items[i].flags & 0xFF) == INLINE_ITEM_TYPE_MULTI_LINE_EDIT ||
							 (wgui_inline_items[i].flags & 0xFF) == INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY)))
							// for half display inline multiline
#endif // __OP01_FWPBW__
#endif /* __MMI_FTE_SUPPORT__ */
							{
                        #ifdef __MMI_UI_LIST_GRID_LINE__
								if ((i > m->first_displayed_item) && (wgui_inline_editor_if_need_draw_separator_line(i - 1)))
								{
									h = y_offset + y1 + 1;
								}
								else
                        #endif
								{
									h = y_offset + y1;
								}
						//hujin
								//gui_push_clip();
								gui_push_and_set_clip(x1, y1, x2, y2);
								if (g_gui_list_hide_menu)
								{
									//gui_push_clip();
									//gui_set_clip(x1, h, x2, y_offset + y1 + iheight - 1);
									g_gui_list_hide_menu(x1, y1, x2, y2);
									//gui_pop_clip();
								}
								else if (!(m->flags & UI_LIST_MENU_DISABLE_BKGRND_IN_LAYER) && (wgui_is_wallpaper_on_bottom() == MMI_TRUE))
								{
									gdi_draw_solid_rect(x1, h, x2, y_offset + y1 + iheight - 1, GDI_COLOR_TRANSPARENT);
								}
								else
								{
                            #if !defined(MT6205B) && !defined(MT6208)
									gui_draw_filled_area(x1, h, x2, y_offset + y1 + iheight - 1, f);
                            #else 
									color c = f->c;
									gdi_draw_solid_rect(x1, h, x2, y_offset + y1 + iheight - 1, gdi_act_color_from_rgb(255, c.r, c.g, c.b));
                            #endif /* !defined(MT6205B) && !defined(MT6208) */
								}
								m->item_display_function(m->items[i], m->common_item_data, x1, y_offset + y1);
								gui_pop_clip();
	
								if (i == MMI_fixed_list_menu.highlighted_item)
								{
									m->highlight_x = x1;
									m->highlight_y = y_offset + y1;
								}
							 }
					  }
#ifdef __MMI_FTE_SUPPORT__
					else if (!disable_draw && y_offset + y1 < y2)
					{
					    //hujin
						//gui_push_clip();
						gui_push_and_set_clip(x1, y1, x2, y2);
						m->item_display_function(m->items[i], m->common_item_data, x1, y_offset + y1);
						gui_pop_clip();
					}
#endif
					g_current_display_half_menuitem = MMI_FALSE;
					if (total_height > list_height + 1)
					{
						done = 1;
					}
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
					if (total_height > list_height + 1 && total_height - iheight < list_height)
					{
						m->last_displayed_offset = iheight - (total_height - list_height);
						counter++;
					}
					else if (i == m->first_displayed_item)
					{
						counter++;
					}
#endif
				}
				else
				{
					if (!disable_draw)
					{
						if (i == m->highlighted_item)
						{
							m->highlight_x = x1;
							m->highlight_y = y_offset + y1;
						}
						else if (((m->highlighted_item < 0) || (m->highlighted_item >= m->n_items)) && (i == 0))
						{
							m->highlight_x = x1;
							m->highlight_y = y_offset + y1;
						}
						if (m->flags & UI_LIST_MENU_INLINE_EDIT)
						{
                    #ifdef __MMI_UI_LIST_GRID_LINE__
							if ((i > m->first_displayed_item) && (wgui_inline_editor_if_need_draw_separator_line(i - 1)))
							{
								h = y_offset + y1 + 1;
							}
							else
                    #endif
							{
								h = y_offset + y1;
							}
	
							if (g_gui_list_hide_menu)
							{
							//hujin
								//gui_push_clip();
								gui_push_and_set_clip(x1, h, x2, y_offset + y1 + iheight - 1);
								g_gui_list_hide_menu(x1, y1, x2, y2);
								gui_pop_clip();
							}
							else if (!(m->flags & UI_LIST_MENU_DISABLE_BKGRND_IN_LAYER) && (wgui_is_wallpaper_on_bottom() == MMI_TRUE))
							{
#ifdef __MMI_INLINE_HIGHLIGHT_CAPTION__	
                             if ( !( (m->flags & UI_LIST_MENU_INLINE_EDIT) && (m->highlighted_item == i)) )
#endif	
								gdi_draw_solid_rect(x1, h, x2, y_offset + y1 + iheight - 1, GDI_COLOR_TRANSPARENT);
							}
							else
							{
                        #if !defined(MT6205B) && !defined(MT6208)
								gui_draw_filled_area(x1, h, x2, y_offset + y1 + iheight - 1, f);
                        #else 
								color c = f->c;
								gdi_draw_solid_rect(x1, h, x2, y_offset + y1 + iheight - 1, gdi_act_color_from_rgb(255, c.r, c.g, c.b));
                        #endif /* !defined(MT6205B) && !defined(MT6208) */
							}
						}
						m->item_display_function(m->items[i], m->common_item_data, x1, y_offset + y1);
					}
					counter++;
				}
			}

    }

}


 
	m->current_displayed_item = -1;
    if (counter == 0)
    {
        m->last_displayed_item = m->first_displayed_item;
    }
    else
    {
        m->last_displayed_item = m->first_displayed_item + counter - 1;
    }
    m->displayed_items = counter;

	    /* Handle scrollbar */
    if ((item_index == GUI_SHOW_FIXED_MENU)&&show_scrollbar)
    {
        gui_show_list_menu_scrollbar(m, disable_draw);
    }
    gui_set_clip(cx1, cy1, cx2, cy2);
    gui_set_text_clip(tx1, ty1, tx2, ty2);
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_list_menu_no_draw
 * DESCRIPTION
 *  Calculate the first and the last displayed item indices.
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_list_menu_no_draw(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 iwidth, iheight;
    U8 done = 0;
    S32 total_height, counter, list_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_height = m->height;
    total_height = 0;
    counter = 0;
    m->current_displayed_item = -1;

#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
    total_height -= m->first_displayed_offset;
#endif
    for (i = m->first_displayed_item; (i < m->n_items && !done); i++)
    {
        gui_list_menu_measure_item(m, i, &iwidth, &iheight);
        total_height += iheight;
        if (total_height > list_height + 1)
        {
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
            if (total_height - iheight < list_height)
            {
                counter++;
                m->last_displayed_offset = iheight - (total_height - list_height);
            }
#endif
            done = 1;
        }
        else
        {
            counter++;
        }
    }
    m->current_displayed_item = -1;
    if (counter == 0)
    {
        m->last_displayed_item = m->first_displayed_item;
    }
    else
    {
        m->last_displayed_item = m->first_displayed_item + counter - 1;
    }
    m->displayed_items = counter;
    if (!(m->flags & UI_LIST_MENU_DISABLE_SCROLLBAR))
    {
		gui_set_vertical_scrollbar_range_scale_value(&m->vbar,m->n_items, m->displayed_items,m->first_displayed_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_fixed_list_menu_no_draw
 * DESCRIPTION
 *  Calculate the first and the last displayed item indices.
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_fixed_list_menu_no_draw(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_show_list_menu_no_draw(m);
}


#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_translate_pen_position
 * DESCRIPTION
 *  Translate position to item index
 *  
 *  if y < minimum bound, *item_index is first_displayed_item - 1 or 0
 *  if y > maximum bound, *item_index is last_displayed_item + 1 or (n_items - 1)
 *  Caller of this function might be sensitive to the return result.
 *  Be careful when modifying this function.
 * PARAMETERS
 *  m               [IN]        fixed list menu object
 *  y               [IN]        y
 *  item_index      [OUT]       penned item index
 * RETURNS
 *  Return MMI_TRUE if y is within the menu; otherwise, MMI_FALSE.
 *****************************************************************************/
MMI_BOOL gui_fixed_list_menu_translate_pen_position(fixed_list_menu *m, S32 y, S32 *item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 total_height = 0, i;
    S32 iwidth, iheight;
    MMI_BOOL ret = MMI_FALSE;
#if defined (__MMI_UI_LIST_SKIP_DISABLED__)
    U32 flags = 0, flags_ext = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    y -= m->y;

    if (m->n_items <= 0)
    {
        *item_index = 0;
        /* ret is false */
    }
    else if (y < 0)
    {
        *item_index = (m->first_displayed_item > 0) ? m->first_displayed_item - 1 : 0;
#if defined (__MMI_UI_LIST_SKIP_DISABLED__)
        m->item_get_flag_function(m->items[*item_index], m->common_item_data, *item_index, &flags, &flags_ext);
        if (flags & UI_MENUITEM_STATE_DISABLED)
        {        
            while (flags & UI_MENUITEM_STATE_DISABLED)
            {
                if ( *item_index != 0)        
                {
                    (*item_index) --;
                }
                else
                {
                    break;
                }
                m->item_get_flag_function(m->items[*item_index], m->common_item_data, *item_index, &flags, &flags_ext);
            }        
        }
#endif
        /* ret is false */
    }
    else if (y >= m->height)
    {
        *item_index = (m->last_displayed_item < m->n_items - 1) ? m->last_displayed_item + 1 : m->n_items - 1;
#if defined (__MMI_UI_LIST_SKIP_DISABLED__)
        m->item_get_flag_function(m->items[*item_index], m->common_item_data, *item_index, &flags, &flags_ext);
        if (flags & UI_MENUITEM_STATE_DISABLED)
        {        
            while (flags & UI_MENUITEM_STATE_DISABLED)
            {
                if ( *item_index >= (m->n_items - 1))        
                {
                    break;
                }
                else
                {
                    (*item_index) ++;
                }
                m->item_get_flag_function(m->items[*item_index], m->common_item_data, *item_index, &flags, &flags_ext);
            }        
        }
#endif
        /* ret is false */
    }
    else
    {
        *item_index = m->n_items - 1;
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
        if (m->first_displayed_offset > 0)
        {
            total_height -= m->first_displayed_offset;
        }
#endif
        for (i = m->first_displayed_item; i < m->n_items; i++)
        {
            if (i == m->highlighted_item)
            {
                m->current_displayed_item = -1;
            }
            else
            {
                m->current_displayed_item = i;
            }
            m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);
            total_height += iheight;
            if (total_height > y)
            {
                *item_index = i;
                ret = MMI_TRUE;
                break;
            }
        }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_get_menuitem_position
 * DESCRIPTION
 *  Get menu item (x1, y1) by a specified item index.
 * PARAMETERS
 *  m           [IN]        dynamic list menu object         
 *  item_index  [IN]        item index
 *  x           [OUT]       x1 of the item  
 *  y           [OUT]       y1 of the item 
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_fixed_list_menu_get_menuitem_position(fixed_list_menu *m, S32 item_index, S32 *x, S32 *y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, total_height = m->y;
    S32 iwidth, iheight;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *x = m->x;

    // TODO: must consider scrollbar absence
    if (mmi_fe_get_r2l_state())
    {
#ifndef  __MMI_FTE_SUPPORT__ 
        *x += m->vbar.width + GUI_MENUITEM_X2_GAP;
#else
        *x += GUI_MENUITEM_X2_GAP;
#endif /* __MMI_FTE_SUPPORT__ */
    }

#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
    if (m->first_displayed_offset > 0)
    {
        total_height -= m->first_displayed_offset;
    }
#endif

    if (item_index <= m->first_displayed_item)
    {
        *y = total_height;
        return;
    }

    for (i = m->first_displayed_item; i <= m->last_displayed_item; i++)
    {
        if (i == m->highlighted_item)
        {
            m->current_displayed_item = -1;
        }
        else
        {
            m->current_displayed_item = i;
        }
        m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);
        total_height += iheight;
        if (i + 1 == item_index)
        {
            *y = total_height;
            return;
        }
    }
    *y = total_height;
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_scroll_by_pen
 * DESCRIPTION
 *  Scroll the menu by pen.
 * PARAMETERS
 *  m                   [IN]        fixed list menu object       
 *  first_displayed     [IN]        first displayed item index
 *  menu_event          [OUT]       pen event result
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_fixed_list_menu_scroll_by_pen(fixed_list_menu *m, S32 first_displayed, gui_list_pen_enum *menu_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
    S32 total_height = 0, i, old_flags;
    S32 iwidth, iheight;
    S32 last_displayed = m->n_items - 1;
#endif  /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
    S32 item_index = 0, done = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
    for (i = 0; i < m->n_items; i++)
    {
        if (i == m->highlighted_item)
        {
            m->current_displayed_item = -1;
        }
        else
        {
            m->current_displayed_item = i;
        }
        m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);
        total_height += iheight;
        if (!done && total_height > first_displayed)
        {
            done = 1;
            item_index = i;
            m->first_displayed_offset = first_displayed - (total_height - iheight);
        }
        if (total_height > first_displayed + m->height)
        {
            m->last_displayed_offset = (first_displayed + m->height) - (total_height - iheight);
            break;
        }
    }
    first_displayed = item_index;
#endif

#ifdef __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
    gui_fixed_list_menu_goto_item_without_change_highlight(m, first_displayed);
    *menu_event = GUI_LIST_PEN_NEED_REDRAW;
#else   /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */
    old_flags = m->flags;
    m->flags &= ~UI_LIST_MENU_LOOP;
    if (first_displayed > m->highlighted_item)
    {
        m->flags |= UI_LIST_MENU_FIRST_SHIFT_HIGHLIGHTED_ITEM;
        gui_fixed_list_menu_goto_item(m, first_displayed);
        m->flags &= ~UI_LIST_MENU_FIRST_SHIFT_HIGHLIGHTED_ITEM;
        *menu_event = GUI_LIST_PEN_HIGHLIGHT_CHANGED;
    }
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
    else if (first_displayed == m->highlighted_item && m->first_displayed_offset > 0)
    {
        m->flags |= UI_LIST_MENU_FIRST_SHIFT_HIGHLIGHTED_ITEM;
        gui_fixed_list_menu_goto_item(m, first_displayed + 1);
        m->flags &= ~UI_LIST_MENU_FIRST_SHIFT_HIGHLIGHTED_ITEM;
        *menu_event = GUI_LIST_PEN_HIGHLIGHT_CHANGED;
    }
#endif
    else
    {
        total_height = 0;
#ifdef __MMI_UI_LIST_SCROLL_BY_PIXEL__
        total_height -= m->first_displayed_offset;
#endif
        for (i = first_displayed; i < m->n_items; i++)
        {
            if (i == m->highlighted_item)
            {
                m->current_displayed_item = -1;
            }
            else
            {
                m->current_displayed_item = i;
            }
            m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);
            total_height += iheight;
            if (total_height > m->height + 1)
            {
                last_displayed = i - 1;
                break;
            }
        }
        if (i == m->n_items)
        {
            last_displayed = m->n_items - 1;
        }

        if (last_displayed < m->highlighted_item)
        {
            m->flags |= UI_LIST_MENU_LAST_SHIFT_HIGHLIGHTED_ITEM;
            gui_fixed_list_menu_goto_item(m, last_displayed);
            m->flags &= ~UI_LIST_MENU_LAST_SHIFT_HIGHLIGHTED_ITEM;
            *menu_event = GUI_LIST_PEN_HIGHLIGHT_CHANGED;
        }
        else
        {
            m->first_displayed_item = first_displayed;
            m->last_displayed_item = last_displayed;
            gui_fixed_list_menu_switch_highlighted_item(m, -1);
            *menu_event = GUI_LIST_PEN_NEED_REDRAW;
        }
    }
    m->flags = old_flags;
#endif  /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_translate_pen_event
 * DESCRIPTION
 *  Pen event handler of the fixed list menu.
 * PARAMETERS
 *  m           [IN]        fixed list menu object         
 *  pen_event   [IN]        pen event type
 *  x           [IN]        pen x   
 *  y           [IN]        pen y
 *  menu_event  [OUT]       pen event result
 * RETURNS
 *  Return MMI_TRUE if the pen event is handled; otherwise, MMI_FALSE.
 *****************************************************************************/
BOOL gui_fixed_list_menu_translate_pen_event(
        fixed_list_menu *m,
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_list_pen_enum *menu_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret;
    gui_list_pen_state_struct *pen_state;
    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;
    gui_list_pen_enum menuitem_event;
    gui_pen_event_param_struct menuitem_param;
    S32 item_index;

#ifdef GUI_LIST_MENU_SSK_EFFECT_BY_PEN
    gui_common_menuitem_base_struct *cm;
    S32 menu_height;
#endif /* GUI_LIST_MENU_SSK_EFFECT_BY_PEN  */   

#ifdef  __MMI__RADIO_HIGHLIGHT_CHANGE_WITHOUT_CHANGE_SELECTED__
    U32 old_flags;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pen_state = &m->pen_state;
    ret = MMI_TRUE;

    GUI_PEN_EVENT_PARAM_SET_INTEGER2((&menuitem_param), 0, GUI_LIST_PEN_NONE);

    *menu_event = GUI_LIST_PEN_NONE;

    if (m->flags & UI_LIST_MENU_DISABLE_PEN)
    {
        return MMI_FALSE;
    }

    if (pen_event != MMI_PEN_EVENT_DOWN && pen_state->pen_on_scrollbar)
    {
        gui_vertical_scrollbar_translate_pen_event(&m->vbar, pen_event, x, y, &scrollbar_event, &scrollbar_param);
        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
        {
            gui_fixed_list_menu_scroll_by_pen(m, scrollbar_param._u.i, menu_event);
        }
        else
        {
            ret = MMI_FALSE;
        }
    }
    else if ((pen_event == MMI_PEN_EVENT_MOVE && pen_state->pen_down_state_box) ||
             (pen_event != MMI_PEN_EVENT_DOWN && pen_event!= MMI_PEN_EVENT_MOVE && pen_state->handled_by_menu_item))
    {
        /* For example, tap down on checkbox of two-state menuitem, the subsequent move/up events are discarded */
        S32 item_x, item_y;

        gui_fixed_list_menu_get_menuitem_position(m, m->highlighted_item, &item_x, &item_y);

        GUI_PEN_EVENT_PARAM_SET_INTEGER2((&menuitem_param), m->highlighted_item, GUI_LIST_PEN_NONE);
        
        m->item_pen_function(
            m->items[m->highlighted_item],
            m->common_item_data,
            item_x,
            item_y,
            pen_event,
            x,
            y,
            &menuitem_event,
            &menuitem_param);

        if (menuitem_event == GUI_TWOSTATE_PEN_TOGGLE)
        {
            menuitem_event = GUI_LIST_PEN_ITEM_SELECTED;
        }
        *menu_event = menuitem_event;
    }
    else
    {
        switch (pen_event)
        {
            case MMI_PEN_EVENT_DOWN:
                pen_state->handled_by_menu_item = 0;
                pen_state->pen_on_scrollbar = 0;
                pen_state->pen_down_state_box = 0;
                g_pen_down_item_index = -1;
                if (PEN_CHECK_BOUND(x, y, m->x, m->y, m->width, m->height))
                {
                    if (m->n_items <= 0)
                    {
                        /* In current design, scrollbar is hidden if m->n_items == 0 */
                        ret = MMI_FALSE;
                    }
                    else if (!(m->flags & UI_LIST_MENU_DISABLE_SCROLLBAR) &&
                             !(m->flags & UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR && (m->displayed_items == m->n_items)) &&
                             gui_vertical_scrollbar_translate_pen_event(
                                &m->vbar,
                                MMI_PEN_EVENT_DOWN,
                                x,
                                y,
                                &scrollbar_event,
                                &scrollbar_param))
                    {
                        pen_state->pen_on_scrollbar = 1;
                        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
                        {
                            gui_fixed_list_menu_scroll_by_pen(m, scrollbar_param._u.i, menu_event);
                        }
                    }
                    else
                    {
                        if (gui_fixed_list_menu_translate_pen_position(m, y, &item_index))
                        {
                            S32 item_x, item_y, old_flags;
							U32 iflags, iflags_ext;

                            g_pen_down_item_index = item_index;
                            m->item_get_flag_function(
                                m->items[item_index],  
                                m->common_item_data,
                                item_index,  
                                &iflags, 
                                &iflags_ext);
                            
                            if (!(iflags & UI_MENUITEM_STATE_DISABLED))
                            {
                                // only enable item give touch feedback
                                gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
                            }
                            
                            if (item_index != m->highlighted_item && 
                                item_index >= m->first_displayed_item &&
                                item_index <= m->last_displayed_item &&
                                !(iflags & UI_MENUITEM_STATE_DISABLED))
                            {
                                old_flags = m->flags;
                                m->flags &= ~UI_LIST_MENU_LOOP;
                                gui_fixed_list_menu_goto_item(m, item_index);
                                m->flags = old_flags;
                                *menu_event = GUI_LIST_PEN_HIGHLIGHT_CHANGED;

                                GUI_PEN_EVENT_PARAM_SET_INTEGER2((&menuitem_param), item_index, GUI_LIST_PEN_HIGHLIGHT_CHANGED);
                            }

                            /* Even if highlight is changed, we still need to invoke menuitem pen handler */
                            gui_fixed_list_menu_get_menuitem_position(m, item_index, &item_x, &item_y);
                            if (m->item_pen_function(
                                    m->items[item_index],
                                    m->common_item_data,
                                    item_x,
                                    item_y,
                                    MMI_PEN_EVENT_DOWN,
                                    x,
                                    y,
                                    &menuitem_event,
                                    &menuitem_param))
                            {
                                if (menuitem_event == GUI_TWOSTATE_PEN_TOGGLE)
                                {
                                    menuitem_event = GUI_LIST_PEN_ITEM_SELECTED;
                                }
                                /* original menu_event could be GUI_LIST_PEN_HIGHLIGHT_CHANGED */
                                if (menuitem_event != GUI_LIST_PEN_NONE)
                                {
                                    *menu_event = menuitem_event;
                                }

                                pen_state->handled_by_menu_item = 1;
                                if (menuitem_event == GUI_LIST_PEN_DOWN_ON_STATE_BOX)
                                {
                                    pen_state->pen_down_state_box = 1;
                                }
                            }
                        }
                        else
                        {
                            /* # of menu items < # of displayable menu items */
                            ret = MMI_FALSE;
                        }
                    }
                    pen_state->first_highlighed_item = m->highlighted_item;
                    pen_state->highlight_changed = 0;
                    if (g_dm_data.s32CatId == MMI_CATEGORY_CASCADING_MENU_ID)
                    {
                        m->disable_move_highlight = MMI_FALSE;
                        m->disable_up_select = MMI_FALSE;
                    }
                }
                else if (g_dm_data.s32CatId == MMI_CATEGORY_CASCADING_MENU_ID)
                {
                    m->disable_move_highlight = MMI_TRUE;
                    m->disable_up_select = MMI_TRUE;
                    ret = MMI_TRUE;
                }
                else
                {
                    ret = MMI_FALSE;
                }
                break;

            case MMI_PEN_EVENT_LONG_TAP:
                /* FALLTHROUGH no break */
                break;

            case MMI_PEN_EVENT_REPEAT:
                /* FALLTHROUGH no break */
#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)                
                break;
#endif

            case MMI_PEN_EVENT_MOVE:
                if (!m->disable_move_highlight)
                {
                    U32 iflags, iflags_ext;
                    gui_fixed_list_menu_translate_pen_position(m, y, &item_index);
                    m->item_get_flag_function(
                                m->items[item_index],  
                                m->common_item_data,
                                item_index,  
                                &iflags, 
                                &iflags_ext);
                    if ((item_index != m->highlighted_item) &&
                        !(iflags & UI_MENUITEM_STATE_DISABLED))
                    {
                        gui_fixed_list_menu_goto_item(m, item_index);
#ifdef GUI_LIST_MENU_SSK_EFFECT_BY_PEN
                        if (gui_list_menu_is_support_smooth_scrolling())
                        {
                            if ((m->highlighted_item == m->first_displayed_item) && (m->first_displayed_item > 0))
                            {
                                m->first_displayed_item -= 1;
                                m->last_displayed_item -= 1;
                            }
                            else if ((m->highlighted_item == m->last_displayed_item) && 
                                     (m->last_displayed_item < (m->n_items - 1)))
                            {
                                m->first_displayed_item += 1;
                                m->last_displayed_item += 1;
                            }
                        }
#endif  /* GUI_LIST_MENU_SSK_EFFECT_BY_PEN */
                        *menu_event = GUI_LIST_PEN_HIGHLIGHT_CHANGED;
                    }
                }
                break;

            case MMI_PEN_EVENT_UP:
                if (!m->disable_up_select)
                {
                    if (PEN_CHECK_BOUND(x, y, m->x, m->y, m->width, m->height))
                    {
                        gui_fixed_list_menu_translate_pen_position(m, y, &item_index);
                        if (item_index != m->highlighted_item && 
                            item_index >= m->first_displayed_item &&
                            item_index <= m->last_displayed_item)                 
                        {
                            if (!m->disable_move_highlight)
                            {
                                if (g_pen_down_item_index == item_index)
                                {
                                    U32 flags, flags_ext;
                                    m->item_get_flag_function(
                                        m->items[item_index],  
                                        m->common_item_data,
                                        item_index,  
                                        &flags, 
                                        &flags_ext);
                                    if (!(flags & UI_MENUITEM_STATE_DISABLED))
                                    {
                                        /* If MMI_PEN_EVENT_MOVE is not delivered before moving to this item */
                                        gui_fixed_list_menu_goto_item(m, item_index);
#ifdef GUI_LIST_MENU_SSK_EFFECT_BY_PEN
                                if (gui_list_menu_is_support_smooth_scrolling())
                                {
                                    if ((m->highlighted_item == m->first_displayed_item) && (m->first_displayed_item > 0))
                                    {
                                        m->first_displayed_item -= 1;
                                        m->last_displayed_item -= 1;
                                    }
                                    else if ((m->highlighted_item == m->last_displayed_item) && (m->last_displayed_item < (m->n_items - 1)))
                                    {
                                        cm = (gui_common_menuitem_base_struct*) m->common_item_data;
                                        menu_height = m->displayed_items * cm->height;
                                        if (gui_list_menu_is_highlight_item_two_line())
                                        {
                                            menu_height += cm->height;
                                        }
                                        
                                        if (m->height < menu_height + (cm->height / 3))
                                        {
                                            if ((m->highlighted_item == m->last_displayed_item) && (m->highlighted_item < (m->n_items - 1)))
                                            {
                                                m->first_displayed_item += 1;
                                                m->last_displayed_item += 1;
                                            }
                                        }
                                    }
                                }
#endif  /* GUI_LIST_MENU_SSK_EFFECT_BY_PEN */
                                        *menu_event = GUI_LIST_PEN_HIGHLIGHT_CHANGED;
                                    }
                                }
                            }
                        }
                        else if (pen_state->highlight_changed)
                        {
                            *menu_event = GUI_LIST_PEN_NONE;
                        }
                        else
                        {
                            *menu_event = GUI_LIST_PEN_ITEM_SELECTED;
                        }
                    }
                }
                if (m->disable_up_select == MMI_TRUE && 
                    g_dm_data.s32CatId == MMI_CATEGORY_CASCADING_MENU_ID)
                {
                    *menu_event = GUI_LIST_PEN_CASCADING_OTHER;
                    m->disable_up_select = MMI_FALSE;
                }
                break;

            case MMI_PEN_EVENT_ABORT:
                /* Do nothing */
                break;

            default:
                MMI_ASSERT(0);
        }
    }

    if (ret)
    {
        if (pen_state->first_highlighed_item != m->highlighted_item)
        {
            pen_state->highlight_changed = 1;
        }
    }
    return ret;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  gui_hide_fixed_list_menu_highlighted_item
 * DESCRIPTION
 *  Hide the highlighted item in the fixed list menu.
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_hide_fixed_list_menu_highlighted_item(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, y_offset;
    S32 i;
    S32 cx1, cy1, cx2, cy2;
    S32 tx1, ty1, tx2, ty2;
    S32 iwidth, iheight;
    U8 done = 0;
    S32 total_height, counter, list_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_get_clip(&cx1, &cy1, &cx2, &cy2);
    gui_get_text_clip(&tx1, &ty1, &tx2, &ty2);
    x1 = m->x;
    y1 = m->y;
    x2 = x1 + m->width - 1;
    y2 = y1 + m->height - 1;
    x1 += 3;
#ifndef __MMI_FTE_SUPPORT__
    x2 -= (3 - m->vbar.width);
#else
    x2 -= 3;
#endif
    y1 += 3;
    y2 -= 3;
    list_height = m->height - 4;
    gui_set_text_clip(x1, y1, x2, y2);
    gui_set_clip(x1, y1, x2, y2);
    total_height = 0;
    counter = 0;
    for (i = m->first_displayed_item; (i < m->n_items && !done); i++)
    {
        y_offset = total_height;
        if (i == m->highlighted_item)
        {
            if (i == m->highlighted_item)
            {
                m->current_displayed_item = -1;
            }
            else
            {
                m->current_displayed_item = i;
            }
            m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);
            total_height += iheight;
        }
        if (total_height > list_height + 1)
        {
            done = 1;
            if ((counter == 0) && (i == m->highlighted_item))
            {
                m->item_hide_function(m->items[i], m->common_item_data, x1, y_offset + y1);
            }
        }
        else
        {
            if (i == m->highlighted_item)
            {
                m->item_hide_function(m->items[i], m->common_item_data, x1, y_offset + y1);
            }
            counter++;
        }
    }
    gui_set_clip(cx1, cy1, cx2, cy2);
    gui_set_text_clip(tx1, ty1, tx2, ty2);
}


void gui_set_fixed_list_menu_item_measure_function(
        fixed_list_menu *m,
        void (*item_measure_function) (void *item, void *common_item_data, S32 *width, S32 *height))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->item_measure_function = item_measure_function;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_fixed_list_menu_item_functions
 * DESCRIPTION
 *  Set the fixed list menu item interface.
 * PARAMETERS
 *  m                                   [IN]        fixed list menu object
 *  item_display_function               [IN]        function to display an item
 *  item_measure_function               [IN]        function to measure an item
 *  item_highlight_function             [IN]        function to highlight an item
 *  item_remove_highlight_function      [IN]        function to remove highlight of an item
 *  item_hide_function                  [IN]        function to hide an item
 *  item_resize_function                [IN]        function to resize the common item
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_fixed_list_menu_item_functions(
        fixed_list_menu *m,
        void (*item_display_function) (void *item, void *common_item_data, S32 x, S32 y),
        void (*item_measure_function) (void *item, void *common_item_data, S32 *width, S32 *height),
        void (*item_highlight_function) (void *item, void *common_item_data),
        void (*item_remove_highlight_function) (void *item, void *common_item_data),
        void (*item_hide_function) (void *item, void *common_item_data, S32 x, S32 y),
        void (*item_resize_function) (S32 x, S32 y),
        void (*item_get_flag_function)(void *item, void *common_item_data, S32 index, U32 *flags, U32 *flags_ext),
        void (*item_get_length_function)(void *item, void *common_item_data, S32 *width))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->item_display_function = item_display_function;
    m->item_measure_function = item_measure_function;
    m->item_highlight_function = item_highlight_function;
    m->item_remove_highlight_function = item_remove_highlight_function;
    m->item_hide_function = item_hide_function;
    m->item_resize_function = item_resize_function;
    m->item_get_flag_function = item_get_flag_function;
    m->item_get_length_function = item_get_length_function;
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_set_pen_scroll_delay
 * DESCRIPTION
 *  Set the delay time that menu scrolling after scrollbar is scrolled by pen.
 *  
 *  Typically used in dynamic and asyncdynamic list menu because it need to load
 *  data when menu is scrolled.
 *  
 *  THE SCROLL DELAY IS IMPLEMENTED IN DYNAMIC AND ASYNCDYNAMIC LIST ONLY.
 *  THIS IS DUMMY FUNCTION FOR API CONSISTENCY.
 * PARAMETERS
 *  m               [IN]        fixed list menu object
 *  delay_time      [IN]        time in milliseconds
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_list_menu_set_pen_scroll_delay(fixed_list_menu *m, S32 delay_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(delay_time < (S32) 0x0000FFFF);
    m->pen_scroll_delay_time = delay_time;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_fixed_list_menu_item_pen_function
 * DESCRIPTION
 *  Set the pen handler of menu item.
 * PARAMETERS
 *  m                           [IN]        fixed list menu object
 *  item_pen_function           [IN]        function to handle pen events in menu item
 *  disable_move_highlight      [IN]        do not send GUI_LIST_PEN_HIGHLIGHT_CHANGED on Pen Move and (sometimes) Pen Up
 *  disable_up_select           [IN]        do not send GUI_LIST_PEN_ITEM_SELECTED on Pen Up
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_fixed_list_menu_item_pen_function(
        fixed_list_menu *m,
        fixed_menuitem_pen_hdlr item_pen_function,
        MMI_BOOL disable_move_highlight,
        MMI_BOOL disable_up_select)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->item_pen_function = item_pen_function;
    m->disable_move_highlight = disable_move_highlight;
    m->disable_up_select = disable_up_select;
}
#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifndef __MMI_UI_MENU_SLIM__
/*****************************************************************************
 * FUNCTION
 *  gui_set_fixed_list_menu_common_item_data
 * DESCRIPTION
 *  Set the fixed list common menu item.
 * PARAMETERS
 *  m       [IN]        fixed list menu object
 *  c       [IN]        common item
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_fixed_list_menu_common_item_data(fixed_list_menu *m, void *c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->common_item_data = c;
}
#endif

/* 
 * Matrix menu
 */

/*****************************************************************************
 * FUNCTION
 *  gui_set_fixed_matrix_menu_current_theme
 * DESCRIPTION
 *  Apply the current theme to a fixed matrix menu.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_fixed_matrix_menu_current_theme(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	gui_set_fixed_matrix_menu_theme(m, current_fixed_matrix_menu_theme); 
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_fixed_matrix_menu_theme
 * DESCRIPTION
 *  Apply the given theme to a fixed matrix menu.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 *  t       [IN]        matrix menu theme
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_fixed_matrix_menu_theme(fixed_matrix_menu *m, UI_fixed_matrix_menu_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->flags |= t->flags;
    m->focussed_filler = t->focussed_filler;
    m->normal_filler = t->normal_filler;
	gui_resize_move_scrollbar(m);
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_fixed_matrix_menu
 * DESCRIPTION
 *  Create the fixed matrix menu.
 * PARAMETERS
 *  m           [IN]        fixed matrix menu object
 *  x           [IN]        x1 of the menu
 *  y           [IN]        y1 of the menu
 *  width       [IN]        menu width
 *  height      [IN]        menu height
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_fixed_matrix_menu(fixed_matrix_menu *m, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	memset(m, 0, sizeof(fixed_matrix_menu));
    gui_create_fixed_menu(m, x, y, width, height);
    gui_set_fixed_matrix_menu_current_theme(m);
#ifdef __MMI_FTE_SUPPORT__
#ifndef GUI_MATRIX_MENU_SMOOTH_SCROLLING_BY_PEN
    gui_create_vertical_scrollbar_ex(
        &m->vbar,
        m->x + m->width - UI_SCROLLBAR_WIDER_WIDTH - 1,
        m->y + 2,
        UI_SCROLLBAR_WIDER_WIDTH,
        m->height - current_fixed_matrix_menu_theme->hbar_height - 3,
        GUI_SCROLLBAR_STYLE_WIDER, 
        GDI_NULL_HANDLE, 
        GDI_NULL_HANDLE, GDI_NULL_HANDLE);
#else
    gui_create_vertical_scrollbar_ex(
        &m->vbar,
        m->x + m->width - UI_SCROLLBAR_NARROW_WIDTH - 1,
        m->y + 2,
        UI_SCROLLBAR_NARROW_WIDTH,
        m->height - current_fixed_matrix_menu_theme->hbar_height - 3,
        GUI_SCROLLBAR_STYLE_DEFAULT, 
        GDI_NULL_HANDLE, 
        GDI_NULL_HANDLE, GDI_NULL_HANDLE);
#endif
#else
    gui_create_vertical_scrollbar(
        &m->vbar,
        m->x + m->width - current_fixed_matrix_menu_theme->vbar_width - 1,
        m->y + 2,
        current_fixed_matrix_menu_theme->vbar_width,
        m->height - current_fixed_matrix_menu_theme->hbar_height - 3);
#endif
    gui_create_horizontal_scrollbar(
        &m->hbar,
        m->x + 2,
        m->y + m->height - current_fixed_matrix_menu_theme->hbar_height - 1,
        m->width - current_fixed_matrix_menu_theme->vbar_width - 3,
        current_fixed_matrix_menu_theme->hbar_height);
    m->trigger_top_function = UI_dummy_function;
    m->trigger_bottom_function = UI_dummy_function;
    m->last_hilited_x = -1;
    m->last_hilited_y = -1;
    m->last_highlighted_item = -1;

#ifdef __MMI_TOUCH_SCREEN__
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 
#endif /* __MMI_TOUCH_SCREEN__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_auto_calculate
 * DESCRIPTION
 *  Automatically calculate a fixed matrix menu.
 *  (Decides the number of columns / rows to be displayed
 *  and the number of items per row or column)
 * PARAMETERS
 *  m           [IN]        fixed matrix menu object
 *  width       [OUT]       menu width
 *  height      [OUT]       menu height
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_fixed_matrix_menu_auto_calculate(fixed_matrix_menu *m, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 //   S32 x1, y1;//, x2, y2
    S32 menu_width, menu_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  //  x1 = m->x;
 //   y1 = m->y;
//    x2 = x1 + m->width - 1;
 //   y2 = y1 + m->height - 1;

    menu_height = m->height;//y2 - y1 + 1;
    menu_width = m->width;//x2 - x1 + 1;

    /* Autocalculate unspecified parameters               */
    if (m->n_rows == 0 && m->n_columns == 0)    /* both rows and columns is not specified by wgui */
    {
        S32 rows, columns, reminders;

        columns = menu_width / m->item_width;
        rows = pixtel_highdivide(m->n_items, columns);
        while ((columns * 2) / (rows * 3) > 1)
        {
            columns--;
            rows = pixtel_highdivide(m->n_items, columns);
        }
        reminders = m->n_items % columns;
        while (reminders != 0)
        {
            if (reminders + rows - 1 > columns - 1)
            {
                break;
            }
            else
            {
                columns--;
                rows = pixtel_highdivide(m->n_items, columns);
                reminders = m->n_items % columns;
            }
        }
        m->n_rows = rows;
        m->n_columns = columns;
        if (m->item_height <= 0)
        {
            m->item_height = menu_height / m->n_rows;
        }
        if (m->item_width <= 0)
        {
            m->item_width = menu_width / m->n_columns;
        }
    }
    else
    {
        if (m->item_height <= 0)
        {
            m->item_height = menu_height / m->n_rows;
        }
        if (m->n_rows <= 0)
        {
            m->n_rows = menu_height / m->item_height;
        }
        if (m->item_width <= 0)
        {
            m->item_width = menu_width / m->n_columns;
        }
        if (m->n_columns <= 0)
        {
            m->n_columns = menu_width / m->item_width;
        }
    }
    /* Fix rows and columns to match the number of items     */
    if (m->n_items < m->n_columns)
    {
        m->n_rows = 1;
        m->n_columns = m->n_items;
    }
    else
    {
        if (m->n_rows > pixtel_highdivide(m->n_items, m->n_columns))
        {
            m->n_rows = pixtel_highdivide(m->n_items, m->n_columns);
        }
        if ((m->n_columns * m->n_rows) < m->n_items)
        {
            m->n_rows = pixtel_highdivide(m->n_items, m->n_columns);
        }
    }

    *width = menu_width;
    *height = menu_height;
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_auto_configure
 * DESCRIPTION
 *  Automatically configure a fixed matrix menu.
 *  (Decides the number of columns / rows to be displayed
 *  and the number of items per row or column)
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_fixed_matrix_menu_auto_configure(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    S32 menu_width, menu_height;
    U8 show_vbar = 0, show_hbar = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((m->n_columns <= 0) && (m->item_width <= 0))
    {
        return;
    }
    if ((m->n_rows <= 0) && (m->item_height <= 0))
    {
        return;
    }
    if (m->n_items == 0)
    {
        return;
    }

    x1 = m->x;
    y1 = m->y;
    x2 = x1 + m->width - 1;
    y2 = y1 + m->height - 1;


    gui_fixed_matrix_menu_auto_calculate(m, &menu_width, &menu_height);

//unimportant issues
#ifndef __MMI_UI_MENU_SLIM__
    if (menu_height < m->item_height)
    {
        m->item_height = menu_height;
    }
    if (menu_width < m->item_width)
    {
        m->item_width = menu_width;
    }
#endif
    /* Calculate the number of displayed rows and columns    */
    m->displayed_rows = menu_height / m->item_height;
    m->displayed_columns = menu_width / m->item_width;

    if (m->displayed_rows < m->n_rows)
    {
        gui_fixed_matrix_menu_auto_calculate(m, &menu_width, &menu_height);
    }

    if (!(m->flags & UI_MATRIX_MENU_DISABLE_SCROLLBAR))
    {
        if ((!(m->flags & UI_MATRIX_MENU_AUTO_DISABLE_SCROLLBAR)) ||
            ((m->flags & UI_MATRIX_MENU_AUTO_DISABLE_SCROLLBAR) && (m->n_rows > m->displayed_rows)))
        {
            show_vbar = 1;
        }
        if ((!(m->flags & UI_MATRIX_MENU_AUTO_DISABLE_SCROLLBAR)) ||
            ((m->flags & UI_MATRIX_MENU_AUTO_DISABLE_SCROLLBAR) && (m->n_columns > m->displayed_columns)))
        {
            show_hbar = 1;
        }
    }

    if (show_vbar)
    {
        x2 -= m->vbar.width;
    }
    if (show_hbar)
    {
        y2 -= m->hbar.height;
    }
    menu_height = y2 - y1 + 1;
    menu_width = x2 - x1 + 1;

//unimportant issues
#ifndef __MMI_UI_MENU_SLIM__
    if (menu_height < m->item_height)
    {
        m->item_height = menu_height;
    }
    if (menu_width < m->item_width)
    {
        m->item_width = menu_width;
    }
#endif
    /* Recalculate the number of rows that can be displayed  */
    m->displayed_rows = menu_height / m->item_height;
    m->displayed_columns = menu_width / m->item_width;

    /* Fix the number of displayed rows and columns       */
    if (g_dm_data.s32CatId == MMI_CATEGORY414_ID)
    {        
#if !(defined(__MMI_MAINLCD_240X400__) && defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__) ||\
        defined(__MMI_MAINLCD_320X480__) && defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__))
    if (m->displayed_columns > m->n_columns && 
		!(m->n_columns <= 1 && (m->flags & UI_MATRIX_MENU_ALIGN_LEFT_TOP)))
    {
        m->displayed_columns = m->n_columns;
    }
    if (m->displayed_rows > m->n_rows && 
		!(m->n_rows <= 1 && (m->flags & UI_MATRIX_MENU_ALIGN_LEFT_TOP)))
    {
        m->displayed_rows = m->n_rows;
    }
    #ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    else
    {
        if (MMI_current_menu_type == LIST_MATRIX_MENU)
        {
            m->displayed_rows = menu_height / m->item_height;
        }
    }
    #endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 
#endif
    }
    else if (!(m->flags & UI_DYAMIC_MATRIX_MENU_ALIGN_LEFT_TOP))
    {
        if (m->displayed_columns > m->n_columns && 
            !(m->n_columns <= 1 && (m->flags & UI_MATRIX_MENU_ALIGN_LEFT_TOP)))
        {
            m->displayed_columns = m->n_columns;
        }
        if (m->displayed_rows > m->n_rows && 
            !(m->n_rows <= 1 && (m->flags & UI_MATRIX_MENU_ALIGN_LEFT_TOP)))
        {
            m->displayed_rows = m->n_rows;
        }
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
        else
        {
            if (MMI_current_menu_type == LIST_MATRIX_MENU)
            {
                m->displayed_rows = menu_height / m->item_height;
            }
        }
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 
    }

    /* Enable/Disable scrollbars                       */
    if (show_vbar)
    {
        m->flags |= UI_MATRIX_MENU_SHOW_VERTICAL_SCROLLBAR;
    }
    else
    {
        m->flags &= ~UI_MATRIX_MENU_SHOW_VERTICAL_SCROLLBAR;
    }
    if (show_hbar)
    {
        m->flags |= UI_MATRIX_MENU_SHOW_HORIZONTAL_SCROLLBAR;
    }
    else
    {
        m->flags &= ~UI_MATRIX_MENU_SHOW_HORIZONTAL_SCROLLBAR;
    }

    if (show_vbar && (!show_hbar))
    {
        gui_resize_vertical_scrollbar(&m->vbar, m->vbar.width, m->height);
    }
    if (show_hbar && (!show_vbar))
    {
        gui_resize_horizontal_scrollbar(&m->hbar, m->width, m->hbar.height);
    }
    if (show_vbar && show_hbar)
    {
        gui_resize_vertical_scrollbar(&m->vbar, m->vbar.width, m->height - m->hbar.height);
        gui_resize_horizontal_scrollbar(&m->hbar, m->width - m->vbar.width, m->hbar.height);
    }
    gui_move_vertical_scrollbar(&m->vbar, m->x + m->width - current_fixed_matrix_menu_theme->vbar_width, m->y);
    gui_move_horizontal_scrollbar(&m->hbar, m->x, m->y + m->height - current_fixed_matrix_menu_theme->hbar_height);
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_setup
 * DESCRIPTION
 *  Set the number of rows, columns and item dimensions.
 * PARAMETERS
 *  m               [IN]        fixed matrix menu object
 *  item_width      [IN]        width of each item
 *  item_height     [IN]        height of each item
 *  n_columns       [IN]        number of columns
 *  n_rows          [IN]        number of rows
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_matrix_menu_setup(fixed_matrix_menu *m, S32 item_width, S32 item_height, S32 n_columns, S32 n_rows)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->item_width = item_width;
    m->item_height = item_height;
    m->n_columns = n_columns;
    m->n_rows = n_rows;
    gui_fixed_matrix_menu_auto_configure(m);
}


/*****************************************************************************
 * FUNCTION
 *  gui_resize_fixed_matrix_menu
 * DESCRIPTION
 *  Resize the fixed matrix menu.
 * PARAMETERS
 *  m           [IN]        fixed matrix menu object
 *  width       [IN]        new menu width
 *  height      [IN]        new menu height
 * RETURNS
 *  void
 *****************************************************************************/
void gui_resize_fixed_matrix_menu(fixed_matrix_menu *m, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FTE_SUPPORT__)	
    S32 vbar_width;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->width = width;
    m->height = height;
#if defined(__MMI_FTE_SUPPORT__)
#if defined(GUI_MATRIX_MENU_SMOOTH_SCROLLING_BY_PEN)
    vbar_width = UI_SCROLLBAR_NARROW_WIDTH;
#else
    vbar_width = UI_SCROLLBAR_WIDER_WIDTH;
    
#endif
    gui_resize_vertical_scrollbar(
        &m->vbar,
        vbar_width,
        m->height - current_fixed_matrix_menu_theme->hbar_height);
    gui_move_vertical_scrollbar(&m->vbar, m->x + m->width - vbar_width, m->y);
    gui_resize_horizontal_scrollbar(
        &m->hbar,
        m->width - vbar_width,
        current_fixed_matrix_menu_theme->hbar_height);
    gui_move_horizontal_scrollbar(&m->hbar, m->x, m->y + m->height - current_fixed_matrix_menu_theme->hbar_height);
#else
    gui_resize_move_scrollbar(m);

   
#endif	
    gui_fixed_matrix_menu_auto_configure(m);
}


/*****************************************************************************
 * FUNCTION
 *  gui_move_fixed_matrix_menu
 * DESCRIPTION
 *  Move the fixed matrix menu.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 *  x       [IN]        new menu x1
 *  y       [IN]        new menu y1
 * RETURNS
 *  void
 *****************************************************************************/
void gui_move_fixed_matrix_menu(fixed_matrix_menu *m, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->x = x;
    m->y = y;
    gui_move_vertical_scrollbar(&m->vbar, m->x + m->width - current_fixed_matrix_menu_theme->vbar_width, m->y);
    gui_move_horizontal_scrollbar(&m->hbar, m->x, m->y + m->height - current_fixed_matrix_menu_theme->hbar_height);
    gui_fixed_matrix_menu_auto_configure(m);
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_locate_highlighted_item
 * DESCRIPTION
 *  Locate the highlighted item in the fixed matrix menu.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_matrix_menu_locate_highlighted_item(fixed_matrix_menu *m)
{
   gui_matrix_menu_locate_x(m, GUI_FIXED_HILITED);
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_goto_next_item
 * DESCRIPTION
 *  Go to the item next to the highlighted item.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_matrix_menu_goto_next_item(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_highlighted_item = m->highlighted_item;
#if defined (__MMI_UI_LIST_SKIP_DISABLED__)
    U32 flags = 0, flags_ext = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m->highlighted_item >= (m->n_items - 1))
    {
        if (m->flags & UI_MATRIX_MENU_VERTICAL_TRIGGER)
        {
            if (m->trigger_bottom_function)
            {
                m->trigger_bottom_function();
            }
            return; /* exit point */
        }
        else if (m->flags & UI_MATRIX_MENU_LOOP)
        {
            m->highlighted_item = 0;
        }
        else
        {
            return;
        }
    }
    else
    {
        m->highlighted_item++;
    }
#if defined (__MMI_UI_LIST_SKIP_DISABLED__)
    m->item_get_flag_function(m->items[m->highlighted_item], m->common_item_data, m->highlighted_item,
        &flags, &flags_ext);
    if (flags & UI_MENUITEM_STATE_DISABLED)
    {        
        while (flags & UI_MENUITEM_STATE_DISABLED)
        {
            if ( m->highlighted_item >= (m->n_items - 1))        
            {
                if (m->flags & UI_MATRIX_MENU_LOOP)
                {
                    m->highlighted_item = 0;
                }
                else
                {
                    return;
                }
                
            }
            else
            {
                m->highlighted_item++;
            }
            m->item_get_flag_function(m->items[m->highlighted_item], m->common_item_data, m->highlighted_item,
                &flags, &flags_ext);
        } 
    }     
#endif  
    gui_fixed_matrix_menu_locate_highlighted_item(m);
    if (old_highlighted_item != m->highlighted_item)
    {
        if ((old_highlighted_item >= 0) && (old_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(m->items[old_highlighted_item], m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);
        }
        m->item_unhighlighted(old_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_goto_previous_item
 * DESCRIPTION
 *  Go to the item previous to the highlighted item.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_matrix_menu_goto_previous_item(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_highlighted_item = m->highlighted_item;
#if defined (__MMI_UI_LIST_SKIP_DISABLED__)
    U32 flags, flags_ext;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m->highlighted_item <= 0)
    {
        if (m->flags & UI_MATRIX_MENU_VERTICAL_TRIGGER)
        {
            if (m->trigger_top_function)
            {
                m->trigger_top_function();
            }
            return; /* exit point */
        }
        else if (m->flags & UI_MATRIX_MENU_LOOP)
        {
            m->highlighted_item = m->n_items - 1;
        }
        else
        {
            return;
        }
    }
    else
    {
        m->highlighted_item--;
    }
#if defined (__MMI_UI_LIST_SKIP_DISABLED__)
    m->item_get_flag_function(m->items[m->highlighted_item], m->common_item_data, m->highlighted_item,
        &flags, &flags_ext);
    
    if (flags & UI_MENUITEM_STATE_DISABLED)
    {
        while (flags & UI_MENUITEM_STATE_DISABLED)
        {
            if ( m->highlighted_item == 0)        
            {
                if (m->flags & UI_MATRIX_MENU_LOOP)
                {
                    m->highlighted_item = m->n_items - 1;
                }
                else
                {
                    return;
                }
                
            }
            else
            {
                m->highlighted_item--;
            }
            m->item_get_flag_function(m->items[m->highlighted_item], m->common_item_data, m->highlighted_item,
                &flags, &flags_ext);
        }
    }
#endif
    gui_fixed_matrix_menu_locate_highlighted_item(m);
    if (old_highlighted_item != m->highlighted_item)
    {
        if ((old_highlighted_item >= 0) && (old_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(m->items[old_highlighted_item], m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);
        }
        m->item_unhighlighted(old_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_goto_previous_row
 * DESCRIPTION
 *  Go to the item in the previous row. The column index is unchanged.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_matrix_menu_goto_previous_row(fixed_matrix_menu *m)
{
  gui_matrix_menu_goto_row_x(m, GUI_FIXED_PREV_ROW);
}

/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_goto_previous_row
 * DESCRIPTION
 *  Go to the item in the previous row. The column index is unchanged.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_matrix_menu_goto_row_x(fixed_matrix_menu *m, S32 goto_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 old_highlighted_item;
    S32 last_row_columns=0;
#ifdef __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__	
     U8 locate_highlight = 0;
    U8 locate_previous = 0;   
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  

      #ifdef __MMI_TOUCH_SCREEN__  
	  if(goto_type == GUI_ASYNC_PREV_ROW)
	    {
		    /* If highlight is changed by keypad, abort scroll timer */
		    gui_asyncdynamic_matrix_abort_scroll_timer();
    	}
      #endif /* __MMI_TOUCH_SCREEN__ */ 
#endif	
    old_highlighted_item = m->highlighted_item;
	  
    if(goto_type == GUI_ASYNC_PREV_ROW)
		 last_row_columns = m->n_items % m->displayed_columns;

     /* Menu rotation */
    if ((goto_type == GUI_FIXED_PREV_ROW)&&(m->flags & UI_MATRIX_MENU_VERTICAL_TRIGGER) && m->highlighted_row <= 0)
    {
        if (m->trigger_top_function)
        {
            m->trigger_top_function();
        }
        return; /* exit point */
    }
    else if (m->highlighted_row <= 0)
    {

	  //may be can be merged
	  if(goto_type == GUI_ASYNC_PREV_ROW)
	  {
#ifdef __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__	  
	        locate_highlight = 1;
#endif
	        /* matrix mainmenu vertical loop 1<->4<->7<->2<->5<->8... */
	        if (m->highlighted_row == 0 &&
	            last_row_columns &&
	            m->flags & UI_MATRIX_MENU_VERTICAL_LOOP &&
	            m->highlighted_column > last_row_columns - 1)
	        {
	            m->highlighted_column = last_row_columns - 1;
	        }
	        m->highlighted_row = m->n_rows - 1;
	  }
	  else
	  	{
	        m->highlighted_row = m->n_rows - 1;

	        /* matrix mainmenu vertical loop 1<->4<->7<->2<->5<->8... */
	        if (m->flags & UI_MATRIX_MENU_VERTICAL_LOOP)
	        {
	            if (m->highlighted_column == 0)
	            {
	                m->highlighted_column = m->displayed_columns - 1;
	            }
	            else
	            {
	                m->highlighted_column -= 1;
	            }
	        }
	  	}

        /* To avoid the blcok cursor go to non-existed item. */
        m->highlighted_item = (m->highlighted_row * m->n_columns) + m->highlighted_column;

        /* To support that a row is not full of items */
		m->first_displayed_row=m->highlighted_row-m->displayed_rows+1;

        if (m->highlighted_item > (m->n_items - 1))
        {
            m->highlighted_row -= 1;
            m->highlighted_item -= m->n_columns;
        }
        m->first_displayed_row = m->highlighted_row - m->displayed_rows + 1;
        if (m->first_displayed_row < 0)
        {
            m->first_displayed_row = 0;
        }
    }
    else
    {
        m->highlighted_row--;
        if (m->highlighted_row < m->first_displayed_row)
        {
            m->first_displayed_row = m->highlighted_row;
        }
#ifdef __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__
		if(goto_type == GUI_ASYNC_PREV_ROW)
			locate_previous = 1;
#endif		
    }

    m->highlighted_item = (m->highlighted_row * m->n_columns) + m->highlighted_column;

#ifdef __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__
	if(goto_type == GUI_ASYNC_PREV_ROW)
	{
      if (locate_highlight)
	    {
	        gui_asyncdynamic_matrix_menu_locate_highlighted_item(m);
	    }
	    else if (locate_previous)
	    {
	        gui_asyncdynamic_matrix_menu_locate_previous_item(m);
	    }
	    if (gui_asyncdynamic_list_error)
	    {
	        return;
	    }
	    
	    gui_asyncdynamic_matrix_menu_switch_highlighted_item(m, old_highlighted_item);
	}
	else
#endif		
		if(goto_type == GUI_FIXED_PREV_ROW)
	{
   
		if (old_highlighted_item != m->highlighted_item)
	    {
	        if ((old_highlighted_item >= 0) && (old_highlighted_item < m->n_items))
	        {
	            m->item_remove_highlight_function(m->items[old_highlighted_item], m->common_item_data);
	        }
	        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
	        {
	            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);
	        }
	        m->item_unhighlighted(old_highlighted_item);
	        m->item_highlighted(m->highlighted_item);
	    }
	}
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_goto_next_row
 * DESCRIPTION
 *  Go to the item in the next row. The column index is unchanged.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_matrix_menu_goto_next_row(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_highlighted_item = m->highlighted_item;

    /* Menu rotation */
    if ((m->flags & UI_MATRIX_MENU_VERTICAL_TRIGGER) && m->highlighted_row >= (m->n_rows - 1))
    {
        if (m->trigger_bottom_function)
        {
            m->trigger_bottom_function();
        }
        return; /* exit point */
    }
    else if (m->highlighted_row >= (m->n_rows - 1))
    {
        m->highlighted_row = 0;
        m->first_displayed_row = 0;

        /* matrix mainmenu vertical loop 1<->4<->7<->2<->5<->8... */
        if (m->flags & UI_MATRIX_MENU_VERTICAL_LOOP)
        {
            m->highlighted_column += 1;
            if (m->highlighted_column >= m->displayed_columns)
            {
                m->highlighted_column = 0;
            }
        }
    }
    else
    {
        m->highlighted_row++;
        if (m->highlighted_row > (m->first_displayed_row + m->displayed_rows - 1))
        {
            m->first_displayed_row = (m->highlighted_row - m->displayed_rows + 1);
            if (m->first_displayed_row > (m->n_rows - m->displayed_rows))
            {
                m->first_displayed_row = (m->n_rows - m->displayed_rows);
            }
        }
    }

    m->highlighted_item = (m->highlighted_row * m->n_columns) + m->highlighted_column;
    /* to support that a row is not full of items */
    if (m->highlighted_item > (m->n_items - 1)) /* revert   */
    {
        if (m->flags & UI_MATRIX_MENU_VERTICAL_TRIGGER)
        {
            if (m->trigger_bottom_function)
            {
                m->trigger_bottom_function();                
                return; /* exit point */
            }
        }
        m->highlighted_row = 0;

        /* matrix mainmenu vertical loop 1<->4<->7<->2<->5<->8... */
        if (m->flags & UI_MATRIX_MENU_VERTICAL_LOOP)
        {
            m->highlighted_column += 1;
            if (m->highlighted_column >= m->displayed_columns)
            {
                m->highlighted_column = 0;
            }
        }
        m->highlighted_item = m->highlighted_column;
        m->first_displayed_row = 0;
    }
    if (old_highlighted_item != m->highlighted_item)
    {
        if ((old_highlighted_item >= 0) && (old_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(m->items[old_highlighted_item], m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);
        }
        m->item_unhighlighted(old_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_goto_row
 * DESCRIPTION
 *  Go to the specified row. The column index is unchanged.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 *  r       [IN]        row index
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_matrix_menu_goto_row(fixed_matrix_menu *m, S32 r)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_highlighted_item = m->highlighted_item;
    S32 highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((r < 0) || (r > (m->n_rows - 1)) || (r == m->highlighted_row))
    {
        return;
    }

    highlighted_item = m->highlighted_item;
    highlighted_item += (r - m->highlighted_row) * m->n_columns;
    if (highlighted_item >= m->n_items)
    {
        highlighted_item = m->n_items - 1;
    }
    m->highlighted_item = highlighted_item;

    gui_fixed_matrix_menu_locate_highlighted_item(m);
    if (old_highlighted_item != m->highlighted_item)
    {
        if ((old_highlighted_item >= 0) && (old_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(m->items[old_highlighted_item], m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);
        }
        m->item_unhighlighted(old_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_goto_previous_column
 * DESCRIPTION
 *  Go to the previous column. The row index is unchanged.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_matrix_menu_goto_previous_column(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_highlighted_item = m->highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* For menu rotation */
    if (m->highlighted_column <= 0)
    {
        m->highlighted_column = m->n_columns - 1;
        m->first_displayed_column = m->highlighted_column - m->displayed_columns + 1;
    }
    else
    {
        m->highlighted_column--;
        if (m->highlighted_column < m->first_displayed_column)
        {
            m->first_displayed_column = m->highlighted_column;
        }
    }
    m->highlighted_item = (m->highlighted_row * m->n_columns) + m->highlighted_column;
    if (old_highlighted_item != m->highlighted_item)
    {
        if ((old_highlighted_item >= 0) && (old_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(m->items[old_highlighted_item], m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);
        }
        m->item_unhighlighted(old_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_goto_next_column
 * DESCRIPTION
 *  Go to the next column. The row index is unchanged.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_matrix_menu_goto_next_column(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_highlighted_item;
    S32 old_highlighted_column;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_highlighted_column = m->highlighted_column;
    old_highlighted_item = m->highlighted_item;

    /* for menu rotation */
    if (m->highlighted_column >= (m->n_columns - 1))
    {
        m->highlighted_column = 0;
        m->first_displayed_column = 0;
    }
    else
    {
        m->highlighted_column++;
        if (m->highlighted_column > (m->first_displayed_column + m->displayed_columns - 1))
        {
            m->first_displayed_column = (m->highlighted_column - m->displayed_columns + 1);
            if (m->first_displayed_column > (m->n_columns - m->displayed_columns))
            {
                m->first_displayed_column = (m->n_columns - m->displayed_columns);
            }
        }
    }

    m->highlighted_item = (m->highlighted_row * m->n_columns) + m->highlighted_column;
    if (m->highlighted_item > (m->n_items - 1)) /* revert   */
    {
        m->highlighted_column = old_highlighted_column;
        m->highlighted_item = old_highlighted_item;
    }
    if (old_highlighted_item != m->highlighted_item)
    {
        if ((old_highlighted_item >= 0) && (old_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(m->items[old_highlighted_item], m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);
        }
        m->item_unhighlighted(old_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_goto_column
 * DESCRIPTION
 *  Go to the specified row. The column index is unchanged.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 *  c       [IN]        column index
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_matrix_menu_goto_column(fixed_matrix_menu *m, S32 c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_highlighted_item = m->highlighted_item;
    S32 highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((c < 0) || (c > (m->n_columns - 1)) || (c == m->highlighted_column))
    {
        return;
    }

    highlighted_item = m->highlighted_item;
    highlighted_item += c - m->highlighted_column;
    if (highlighted_item >= m->n_items)
    {
        highlighted_item = m->n_items - 1;
    }
    m->highlighted_item = highlighted_item;

    gui_fixed_matrix_menu_locate_highlighted_item(m);
    if (old_highlighted_item != m->highlighted_item)
    {
        if ((old_highlighted_item >= 0) && (old_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(m->items[old_highlighted_item], m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);
        }
        m->item_unhighlighted(old_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_goto_first_item
 * DESCRIPTION
 *  Go to the first item.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_matrix_menu_goto_first_item(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_highlighted_item = m->highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->highlighted_column = 0;
    m->highlighted_row = 0;
    m->first_displayed_column = 0;
    m->first_displayed_row = 0;
    m->highlighted_item = 0;
    if (old_highlighted_item != m->highlighted_item)
    {
        if ((old_highlighted_item >= 0) && (old_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(m->items[old_highlighted_item], m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);
        }
        m->item_unhighlighted(old_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_goto_last_item
 * DESCRIPTION
 *  Go to the last item.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_matrix_menu_goto_last_item(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_highlighted_item = m->highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->highlighted_item = m->n_items - 1;
    gui_fixed_matrix_menu_locate_highlighted_item(m);
    if (old_highlighted_item != m->highlighted_item)
    {
        if ((old_highlighted_item >= 0) && (old_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(m->items[old_highlighted_item], m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);
        }
        m->item_unhighlighted(old_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_goto_next_page
 * DESCRIPTION
 *  Go to the next page.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_matrix_menu_goto_next_page(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_highlighted_item;
    S32 old_highlighted_row;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_highlighted_row = m->highlighted_row;
    old_highlighted_item = m->highlighted_item;
    if (m->highlighted_row >= (m->n_rows - 1))
    {
        return;
    }
    m->first_displayed_row += m->displayed_rows;
    if (m->first_displayed_row > (m->n_rows - m->displayed_rows))
    {
        m->first_displayed_row = (m->n_rows - m->displayed_rows);
    }
    m->highlighted_row = m->first_displayed_row + m->displayed_rows - 1;
    m->highlighted_item = (m->highlighted_row * m->n_columns) + m->highlighted_column;
    if (m->highlighted_item > (m->n_items - 1)) /* revert   */
    {
        m->highlighted_row = old_highlighted_row;
        m->highlighted_item = old_highlighted_item;
    }
    if (old_highlighted_item != m->highlighted_item)
    {
        if ((old_highlighted_item >= 0) && (old_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(m->items[old_highlighted_item], m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);
        }
        m->item_unhighlighted(old_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_goto_previous_page
 * DESCRIPTION
 *  Go to the previous page.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_matrix_menu_goto_previous_page(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_highlighted_item = m->highlighted_item;
    if (m->highlighted_row <= 0)
    {
        return;
    }
    m->first_displayed_row -= m->displayed_rows;
    if (m->first_displayed_row < 0)
    {
        m->first_displayed_row = 0;
    }
    m->highlighted_row = m->first_displayed_row;
    m->highlighted_item = (m->highlighted_row * m->n_columns) + m->highlighted_column;
    if (old_highlighted_item != m->highlighted_item)
    {
        if ((old_highlighted_item >= 0) && (old_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(m->items[old_highlighted_item], m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);
        }
        m->item_unhighlighted(old_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_goto_item
 * DESCRIPTION
 *  Go to a specified item by its index.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 *  i       [IN]        item index to be highlighted
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fixed_matrix_menu_goto_item(fixed_matrix_menu *m, S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_highlighted_item = m->highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((i < 0) || (i > (m->n_items - 1)))
    {
        return;
    }
    m->highlighted_item = i;
    gui_fixed_matrix_menu_locate_highlighted_item(m);
    if (old_highlighted_item != m->highlighted_item)
    {
        if ((old_highlighted_item >= 0) && (old_highlighted_item < m->n_items))
        {
            m->item_remove_highlight_function(m->items[old_highlighted_item], m->common_item_data);
        }
        if ((m->highlighted_item >= 0) && (m->highlighted_item < m->n_items))
        {
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);
        }
        m->item_unhighlighted(old_highlighted_item);
        m->item_highlighted(m->highlighted_item);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_reset_fixed_matrix_col_rows
 * DESCRIPTION
 *  Zero the number of rows and columns.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_reset_fixed_matrix_col_rows(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* m->n_columns=0; */
    m->n_rows = 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_auto_disable_scrollbar
 * DESCRIPTION
 *  Check whether the auto-disable scroll bar option is enabled or not.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object 
 * RETURNS
 *  Return 1 if the auto-disable scroll bar option is enabled; otherwise, -1.
 *****************************************************************************/
S32 gui_fixed_matrix_auto_disable_scrollbar(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(m->flags & UI_MATRIX_MENU_DISABLE_SCROLLBAR))
    {
        if (m->flags & UI_MATRIX_MENU_AUTO_DISABLE_SCROLLBAR)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mtk_UI_show_fixed_matrix_menu
 * DESCRIPTION
 *  Show the fixed matrix menu.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_matrix_menu_show_vscrollbar(void* common_item_data)
{
    fixed_matrix_menu *m = (fixed_matrix_menu *)common_item_data;
   
	   //hujin
    gui_set_vertical_scrollbar_range_scale_value(&m->vbar,m->n_rows, m->displayed_rows,m->first_displayed_row);
   if(mmi_fe_get_r2l_state())
    {
        gui_move_vertical_scrollbar(&m->vbar, m->x, m->y);
    }
    else
    {
        gui_move_vertical_scrollbar(&m->vbar, m->x + m->width - m->vbar.width, m->y);
    }

    gui_show_vertical_scrollbar(&m->vbar); 
}


/*****************************************************************************
 * FUNCTION
 *  mtk_UI_show_fixed_matrix_menu
 * DESCRIPTION
 *  Show the fixed matrix menu.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/

void gui_matrix_menu_show_hscrollbar(void* common_item_data)
{
    fixed_matrix_menu *m = (fixed_matrix_menu *)common_item_data;
	
	 gui_set_horizontal_scrollbar_range(&m->hbar, m->n_columns);
	 gui_set_horizontal_scrollbar_scale(&m->hbar, m->displayed_columns);
	 gui_set_horizontal_scrollbar_value(&m->hbar, m->first_displayed_column);
	 gui_show_horizontal_scrollbar(&m->hbar);

}

/*****************************************************************************
 * FUNCTION
 *  mtk_UI_show_fixed_matrix_menu
 * DESCRIPTION
 *  Show the fixed matrix menu.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void mtk_UI_show_fixed_matrix_menu(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, hilited_x1, hilited_y1;
    S32 new_hilited_x1, new_hilited_y1, new_column, new_row;
    S32 xoff, yoff, xoff2, yoff2, width, height;
    U8 show_vbar = 0, show_hbar = 0;
    S32 xPos, xPos2;
    S32 yPos, yPos2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    width = m->width;
    height = m->height;
    if (m->flags & UI_MATRIX_MENU_SHOW_VERTICAL_SCROLLBAR)
    {
        show_vbar = 1;
    }
    if (m->flags & UI_MATRIX_MENU_SHOW_HORIZONTAL_SCROLLBAR)
    {
        show_hbar = 1;
    }
    if (show_vbar)
    {
        width -= m->vbar.width;
    }
    if (show_hbar)
    {
        height -= m->hbar.height - 1;
    }
    xoff = (width - (m->item_width * m->displayed_columns)) / (m->displayed_columns + 1);
    yoff = (height - (m->item_height * m->displayed_rows)) / (m->displayed_rows + 1);
    new_row = ((m->highlighted_item) / m->n_columns);
    new_column = m->highlighted_item - (new_row * m->n_columns);

    x1 = m->x;
    y1 = m->y;
    if (show_vbar && mmi_fe_get_r2l_state())
    {
        x1 += m->vbar.width;
    }

    new_hilited_x1 = x1 + xoff + (new_column - m->first_displayed_column) * (m->item_width + xoff);
    new_hilited_y1 = y1 + yoff + (new_row - m->first_displayed_row) * (m->item_height + yoff);

    /* if ( m->last_highlighted_item<first_displayed_item || m->last_highlighted_item>last_displayed_item ) */
#ifdef __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__
if (gui_main_menu_matrix_slide_is_under_control())
#endif
{
    if ((m->last_hilited_x != new_hilited_x1 || m->last_hilited_y != new_hilited_y1) ||
        (m->last_hilited_x == new_hilited_x1 && m->last_hilited_y == new_hilited_y1 && m->highlighted_item != m->last_highlighted_item) ||
        GUI_ABS(m->highlighted_item - m->last_highlighted_item) >= (m->displayed_columns * m->displayed_rows))
    {
#ifdef __MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT__
        if (m->flags & UI_MATRIX_MENU_FOR_MAINMENU)
        {
            gdi_layer_push_and_set_active(dm_get_scr_bg_layer());
            gdi_layer_push_clip();
            gdi_layer_reset_clip();
            //gdi_image_draw(0, 0, current_MMI_theme->main_menu_bkg_filler->b);
            gui_draw_filled_area(0,0,LCD_WIDTH,LCD_HEIGHT,current_MMI_theme->main_menu_bkg_filler);
            gdi_layer_pop_clip();
            gdi_layer_pop_and_restore_active();
        }
#endif /* __MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT__ */
        {
#ifdef __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__
        U32 old_flag = MMI_fixed_icontext_menuitem.flags;
        if (!(m->last_hilited_x == new_hilited_x1 && m->last_hilited_y == new_hilited_y1 && m->highlighted_item != m->last_highlighted_item))
        {
        MMI_fixed_icontext_menuitem.flags &= ~UI_MENUITEM_FOCUSSED_ANIMATE;
        }
#endif /* __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__ */
        m->last_highlighted_item = -1;
        gui_show_fixed_matrix_menu(m);

#ifdef __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__
        MMI_fixed_icontext_menuitem.flags = old_flag;
#endif
        }
        return;
    }
}
    if (m->highlighted_item_width > m->item_width)
    {
        xoff2 = (m->highlighted_item_width - m->item_width);
    }
    else
    {
        xoff2 = 0;
    }
    if (m->highlighted_item_height > m->item_height)
    {
        yoff2 = (m->highlighted_item_height - m->item_height);
    }
    else
    {
        yoff2 = 0;
    }

    gdi_layer_push_and_set_clip(m->cache_bmp_x1, m->cache_bmp_y1, m->cache_bmp_x2, m->cache_bmp_y2);

#ifdef __MMI_MATRIX_MAIN_MENU_OPTIMIZE__
    MMI_ASSERT((m->cache_bmp_x2 - m->cache_bmp_x1 + 1) * (m->cache_bmp_y2 - m->cache_bmp_y1 + 1) * gdi_layer_get_bit_per_pixel() >> 3 <=
               MMI_MAIN_MENU_MATRIX_HIGHLIGHTED_BUF_SIZE);
#endif /* __MMI_MATRIX_MAIN_MENU_OPTIMIZE__ */

/* 
 * We cannot use the cache bitmap when matrix main menu sliding comes into play because 
 * it may cache the wrong image. (gui_main_menu_matrix_slide_start() may draw to the cache region.)
 */
#ifndef __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__
    gdi_image_cache_bmp_draw(m->cache_bmp_x1, m->cache_bmp_y1, &m->buffer);
#endif /* __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__ */

    gdi_layer_pop_clip();

    hilited_x1 = x1 + xoff + (m->highlighted_column - m->first_displayed_column) * (m->item_width + xoff);
    hilited_y1 = y1 + yoff + (m->highlighted_row - m->first_displayed_row) * (m->item_height + yoff);

    if (m->highlighted_item_width > m->item_width)
    {
        xPos = hilited_x1 - (xoff2 >> 1);
        xPos2 = xPos + m->highlighted_item_width - 1;
        if (xPos < x1)
        {
            xPos = x1;
            xPos2 = xPos + m->highlighted_item_width - 1;
        }
        if (xPos2 > x1 + width - 1)
        {
            xPos2 = x1 + width - 1;
            xPos = xPos2 - m->highlighted_item_width + 1;
        }
    }
    else
    {
        xPos = hilited_x1 - (xoff2 >> 1);
        xPos2 = xPos + m->item_width - 1;
        if (xPos < x1)
        {
            xPos = x1;
            xPos2 = xPos + m->item_width - 1;
        }
        if (xPos2 > x1 + width - 1)
        {
            xPos2 = x1 + width - 1;
            xPos = xPos2 - m->item_width + 1;
        }
    }
    if (m->highlighted_item_height > m->item_height)
    {
        yPos = hilited_y1 - (yoff2 >> 1);
        yPos2 = yPos + m->highlighted_item_height - 1;
        
        
        if (yPos < m->y)
        {
            yPos = m->y;
            yPos2 = yPos + m->highlighted_item_height - 1;
        }
        if (yPos2 > m->y + m->height - 1)
        {
            yPos2 = m->y + m->height - 1;
            yPos = yPos2 - m->highlighted_item_height + 1;
        }
    }
    else
    {
        yPos = hilited_y1 - (yoff2 >> 1);
        yPos2 = yPos + m->item_height - 1;
        
        
        if (yPos < m->y)
        {
            yPos = m->y;
            yPos2 = yPos + m->item_height - 1;
        }
        if (yPos2 > m->y + m->height - 1)
        {
            yPos2 = m->y + m->height - 1;
            yPos = yPos2 - m->item_height + 1;
        }
    }
    gdi_layer_push_and_set_clip(xPos, yPos, xPos2, yPos2);
    GUI_current_fixed_icontext_menuitem_x = xPos;
    GUI_current_fixed_icontext_menuitem_y = yPos;
    GUI_current_fixed_icontext_menuitem_x2 = xPos2;

#ifdef __MMI_MATRIX_MAIN_MENU_OPTIMIZE__
    MMI_ASSERT((xPos2 - xPos + 1) * (yPos2 - yPos + 1) * gdi_layer_get_bit_per_pixel() >> 3 <= 
               MMI_MAIN_MENU_MATRIX_HIGHLIGHTED_BUF_SIZE);
#endif /* __MMI_MATRIX_MAIN_MENU_OPTIMIZE__ */


#ifndef __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__
    gdi_image_cache_bmp_get(xPos, yPos, xPos2, yPos2, &m->buffer);
#endif /* __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__ */
    
    gdi_layer_pop_clip();

    m->cache_bmp_x1 = xPos;
    m->cache_bmp_x2 = xPos2;
    m->cache_bmp_y1 = yPos;
    m->cache_bmp_y2 = yPos2;

/* The matrix highlight sliding has its own rendering. Do not show here. */
//#ifndef __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__
#ifdef  __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__
    if (!gui_main_menu_matrix_slide_is_under_control())
#endif
    {
        if (m->last_highlighted_item != -1)
        {
            S32 old_hilited_x1, old_hilited_y1, old_col, old_row;
            gui_rect menu_rect, item_rect, result_rect;
            
            old_row = m->last_highlighted_item / m->displayed_columns;
            old_col = m->last_highlighted_item - old_row * m->displayed_columns;
            old_hilited_x1 = x1 + xoff + (old_col - m->first_displayed_column) * (m->item_width + xoff);
            old_hilited_y1 = y1 + yoff + (old_row - m->first_displayed_row) * (m->item_height + yoff);

            GUI_RECT(
                menu_rect, 
                MMI_fixed_matrix_menu.x, 
                MMI_fixed_matrix_menu.y, 
                MMI_fixed_matrix_menu.width, 
                MMI_fixed_matrix_menu.height);

            GUI_RECT(item_rect, old_hilited_x1, old_hilited_y1, m->item_width + xoff, m->item_height + yoff);

            gui_rect_get_intersection(&menu_rect, &item_rect, &result_rect);

            //for sure the clip is in matrix menu area
            gdi_layer_push_and_set_clip(result_rect.x, result_rect.y, result_rect.x + result_rect.width - 1, result_rect.y + result_rect.height - 1);
            gdi_draw_solid_rect(old_hilited_x1, old_hilited_y1, old_hilited_x1 + m->item_width + xoff - 1, old_hilited_y1 + m->item_height + yoff - 1, GDI_COLOR_TRANSPARENT);
            gdi_layer_pop_clip();
            m->item_display_function(m->items[m->last_highlighted_item], m->common_item_data, old_hilited_x1, old_hilited_y1);
        }
        
        gdi_layer_push_and_set_clip(hilited_x1, hilited_y1, hilited_x1 + m->item_width + xoff - 1, hilited_y1 + m->item_height + yoff - 1);
        gdi_draw_solid_rect(hilited_x1, hilited_y1, hilited_x1 + m->item_width + xoff - 1, hilited_y1 + m->item_height + yoff - 1, GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_clip();
        m->item_display_function(m->items[m->highlighted_item], m->common_item_data, hilited_x1, hilited_y1);
        
    }
//#endif /* __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__ */

    m->last_hilited_x = hilited_x1;
    m->last_hilited_y = hilited_y1;

    if(show_vbar)
		gui_matrix_menu_show_vscrollbar(m);

	if(show_hbar)
		gui_matrix_menu_show_hscrollbar(m);

}

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__


/*****************************************************************************
 * FUNCTION
 *  gui_setup_fixed_matrix_menu_ind_area
 * DESCRIPTION
 *  Setup matrix menu indication area.
 * PARAMETERS
 *  ind_area        [IN]        indication area object
 *  x               [IN]        x1
 *  y               [IN]        y1
 *  string          [IN]        string 
 *  img_id          [IN]        image id
 * RETURNS
 *  void
 *****************************************************************************/
void gui_setup_fixed_matrix_menu_ind_area(gui_matrix_ind_area_struct *ind_area, S32 x, S32 y, U8 *string, U16 img_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_area->x = x;
    ind_area->y = y;

    ind_area->string = string;
    ind_area->img_id = img_id;
    if (string != NULL && img_id != 0)
    {
        MMI_ASSERT(0);
    }

    ind_area->width = 20;
    ind_area->height = 20;
}

#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 


/*****************************************************************************
 * FUNCTION
 *  gui_show_fixed_matrix_menu
 * DESCRIPTION
 *  Display the fixed matrix menu.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_fixed_matrix_menu(fixed_matrix_menu *m)
{
    gui_show_asyncdynamic_matrix_menu_specific_items(m, GUI_SHOW_FIXED_MENU); 
}

#ifndef __MMI_UI_MENU_SLIM__
/*****************************************************************************
 * FUNCTION
 *  gui_hide_fixed_matrix_menu_highlighted_item
 * DESCRIPTION
 *  Hide the highlighted item.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_hide_fixed_matrix_menu_highlighted_item(fixed_matrix_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, xoff, yoff, width, height;
    S32 i, j, k;
    S32 cx1, cy1, cx2, cy2;
    S32 tx1, ty1, tx2, ty2;
    S32 ix, iy, iwidth, iheight, ix2, iy2;
    U8 show_vbar = 0, show_hbar = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_get_clip(&cx1, &cy1, &cx2, &cy2);
    gui_get_text_clip(&tx1, &ty1, &tx2, &ty2);
    x1 = m->x;
    y1 = m->y;
    x2 = x1 + m->width - 1;
    y2 = y1 + m->height - 1;

    if (m->flags & UI_MATRIX_MENU_SHOW_VERTICAL_SCROLLBAR)
    {
        show_vbar = 1;
    }
    if (m->flags & UI_MATRIX_MENU_SHOW_HORIZONTAL_SCROLLBAR)
    {
        show_hbar = 1;
    }

    if (m->n_items == 0)
    {
        return;
    }
    x1 += 3;
    x2 -= 3;
    y1 += 3;
    y2 -= 3;
    if (show_vbar)
    {
        x2 -= m->vbar.width - 1;
    }
    if (show_hbar)
    {
        y2 -= m->hbar.height - 1;
    }
    iwidth = m->item_width;
    iheight = m->item_height;
    width = x2 - x1 + 1;
    height = y2 - y1 + 1;

    gui_set_text_clip(x1, y1, x2, y2);
    gui_set_clip(x1, y1, x2, y2);

    xoff = (width >> 1) - ((iwidth * m->displayed_columns) >> 1);
    yoff = (height >> 1) - ((iheight * m->displayed_rows) >> 1);
    iy = y1 + yoff;
    for (j = 0; j < m->displayed_rows; j++)
    {
        ix = x1 + xoff;
        for (i = 0; i < m->displayed_columns; i++)
        {
            k = ((m->first_displayed_row + j) * m->n_columns) + (m->first_displayed_column + i);
            if (k > (m->n_items - 1))
            {
                break;
            }
            ix2 = ix + iwidth - 1;
            iy2 = iy + iheight - 1;
            if (ix2 > x2)
            {
                ix2 = x2;
            }
            if (iy2 > y2)
            {
                iy2 = y2;
            }
            gui_set_clip(ix, iy, ix2, iy2);
            gui_set_text_clip(ix, iy, ix2, iy2);
            if (k == m->highlighted_item)
            {
                m->item_hide_function(m->items[k], m->common_item_data, ix, iy);
            }
            ix += iwidth;
        }
        iy += iheight;
    }

    gui_set_clip(cx1, cy1, cx2, cy2);
    gui_set_text_clip(tx1, ty1, tx2, ty2);
}
#endif
 
/*****************************************************************************
 * FUNCTION
 *  gui_set_fixed_matrix_menu_item_functions
 * DESCRIPTION
 *  Set the fixed matrix menu item interface.
 * PARAMETERS
 *  m                                   [IN]        fixed matrix menu object
 *  item_display_function               [IN]        function to display an item
 *  item_measure_function               [IN]        function to measure an item
 *  item_highlight_function             [IN]        function to highlight an item
 *  item_remove_highlight_function      [IN]        function to remove highlight of an item
 *  item_hide_function                  [IN]        function to hide an item
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_fixed_matrix_menu_item_functions(
        fixed_matrix_menu *m,
        void (*item_display_function) (void *item, void *common_item_data, S32 x, S32 y),
        void (*item_measure_function) (void *item, void *common_item_data, S32 *width, S32 *height),
        void (*item_highlight_function) (void *item, void *common_item_data),
        void (*item_remove_highlight_function) (void *item, void *common_item_data),
        void (*item_hide_function) (void *item, void *common_item_data, S32 x, S32 y),
        void (*item_get_flag_function)(void *item, void *common_item_data, S32 index, U32* flags, U32* flags_ext))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->item_display_function = item_display_function;
    m->item_measure_function = item_measure_function;
    m->item_highlight_function = item_highlight_function;
    m->item_remove_highlight_function = item_remove_highlight_function;
    m->item_hide_function = item_hide_function;
    m->item_get_flag_function = item_get_flag_function;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_fixed_matrix_menu_common_item_data
 * DESCRIPTION
 *  Set the fixed matrix common menu item.
 * PARAMETERS
 *  m       [IN]        fixed matrix menu object
 *  c       [IN]        common item
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_fixed_matrix_menu_common_item_data(fixed_matrix_menu *m, void *c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->common_item_data = c;
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_vertical_scroll_by_pen
 * DESCRIPTION
 *  Scroll the matrix menu vertically by pen.
 * PARAMETERS
 *  m                       [IN]        fixed matrix menu object
 *  first_displayed_row     [IN]        new row index
 *  menu_event              [OUT]       pen event result
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_fixed_matrix_menu_vertical_scroll_by_pen(
                fixed_matrix_menu *m,
                S32 first_displayed_row,
                gui_matrix_pen_enum *menu_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_displayed_row;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (first_displayed_row > m->highlighted_row)
    {
        m->flags |= UI_MATRIX_MENU_FIRST_SHIFT_HIGHLIGHTED_ROW;
        gui_fixed_matrix_menu_goto_row(m, first_displayed_row);
        m->flags &= ~UI_MATRIX_MENU_FIRST_SHIFT_HIGHLIGHTED_ROW;
        *menu_event = GUI_MATRIX_PEN_HIGHLIGHT_CHANGED;
    }
    else
    {
        last_displayed_row = first_displayed_row + m->displayed_rows - 1;
        MMI_DBG_ASSERT(last_displayed_row <= m->n_rows - 1);

        if (last_displayed_row < m->highlighted_row)
        {
            m->flags |= UI_MATRIX_MENU_LAST_SHIFT_HIGHLIGHTED_ROW;
            gui_fixed_matrix_menu_goto_row(m, last_displayed_row);
            m->flags &= ~UI_MATRIX_MENU_LAST_SHIFT_HIGHLIGHTED_ROW;
            *menu_event = GUI_MATRIX_PEN_HIGHLIGHT_CHANGED;
        }
        else
        {
            /* Scrolling without changing highlight (this case only  happens with pen support) */
            m->first_displayed_row = first_displayed_row;

            /* Although highlighted item stays the same, we need to stop and restart the animation */
            m->item_remove_highlight_function(m->items[m->highlighted_item], m->common_item_data);
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);

            *menu_event = GUI_MATRIX_PEN_NEED_REDRAW;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_horizontal_scroll_by_pen
 * DESCRIPTION
 *  Scroll the matrix menu horizontally by pen.
 * PARAMETERS
 *  m                           [IN]        fixed matrix menu object
 *  first_displayed_column      [IN]        new columnindex
 *  menu_event                  [OUT]       pen event result
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_fixed_matrix_menu_horizontal_scroll_by_pen(
                fixed_matrix_menu *m,
                S32 first_displayed_column,
                gui_matrix_pen_enum *menu_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_displayed_column;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (first_displayed_column > m->highlighted_column)
    {
        m->flags |= UI_MATRIX_MENU_FIRST_SHIFT_HIGHLIGHTED_COL;
        gui_fixed_matrix_menu_goto_column(m, first_displayed_column);
        m->flags &= ~UI_MATRIX_MENU_FIRST_SHIFT_HIGHLIGHTED_COL;
        *menu_event = GUI_MATRIX_PEN_HIGHLIGHT_CHANGED;
    }
    else
    {
        last_displayed_column = first_displayed_column + m->displayed_columns - 1;
        MMI_DBG_ASSERT(last_displayed_column <= m->n_columns - 1);

        if (last_displayed_column < m->highlighted_column)
        {
            m->flags |= UI_MATRIX_MENU_LAST_SHIFT_HIGHLIGHTED_COL;
            gui_fixed_matrix_menu_goto_column(m, last_displayed_column);
            m->flags &= ~UI_MATRIX_MENU_LAST_SHIFT_HIGHLIGHTED_COL;
            *menu_event = GUI_MATRIX_PEN_HIGHLIGHT_CHANGED;
        }
        else
        {
            /* Scrolling without changing highlight (this case only  happens with pen support) */
            m->first_displayed_column = first_displayed_column;

            /* Although highlighted item stays the same, we need to stop and restart the animation */
            m->item_remove_highlight_function(m->items[m->highlighted_item], m->common_item_data);
            m->item_highlight_function(m->items[m->highlighted_item], m->common_item_data);

            *menu_event = GUI_MATRIX_PEN_NEED_REDRAW;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_handle_pen_position
 * DESCRIPTION
 *  Handle the pen event (down/move/up), go to the menu item, and set the menu event.
 * PARAMETERS
 *  m               [IN]        fixed matrix menu object
 *  x               [IN]        pen x
 *  y               [IN]        pen y
 *  pen_event       [IN]        pen event. Only MMI_PEN_EVENT_DOWN, MMI_PEN_EVENT_MOVE, MMI_PEN_EVENT_UP is supported
 *  menu_event      [OUT]       pen event result
 *  index_of_item   [OUT]       the index of item which pen event happen on
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_fixed_matrix_menu_handle_pen_position(
                fixed_matrix_menu *m,
                S32 x,
                S32 y,
                mmi_pen_event_type_enum pen_event,
                gui_matrix_pen_enum *menu_event,
                S32 *index_of_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
     * Because the sampling rate of Pen Move events is not very high on hardware, 
     * * we might "jump" to a menu item aparted from the last highlighted menu item.
     */

    /* FIXME. we do not handle the case that hilighted menu item has bigger size, but it is usually okay */

    S32 xoff, yoff;
    S32 width, height;
    S32 iwidth, iheight;
    S32 new_row, new_column, item_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define COMPUTE_NEW_ROW()  do {                                            \
      if (y < yoff)                                                           \
         new_row = m->first_displayed_row;                                    \
      else                                                                    \
         new_row = m->first_displayed_row + ((y - yoff) / (iheight + yoff));  \
      if (new_row > m->first_displayed_row + m->displayed_rows - 1)           \
         new_row = m->first_displayed_row + m->displayed_rows - 1;            \
   } while (0)

#define COMPUTE_NEW_COLUMN() do {                                                \
      if (x < xoff)                                                                 \
         new_column = m->first_displayed_column;                                    \
      else                                                                          \
         new_column = m->first_displayed_column + ((x - xoff) / (iwidth + xoff));   \
      if (new_column > m->first_displayed_column + m->displayed_columns - 1)        \
         new_column = m->first_displayed_column + m->displayed_columns - 1;         \
   } while (0)

    y -= m->y;
    x -= m->x;
    iwidth = m->item_width;
    iheight = m->item_height;
    width = m->width;
    height = m->height;
    if (m->flags & UI_MATRIX_MENU_SHOW_VERTICAL_SCROLLBAR)
    {
        width -= m->vbar.width;
    }
    if (m->flags & UI_MATRIX_MENU_SHOW_HORIZONTAL_SCROLLBAR)
    {
        height -= m->hbar.height;
    }
    xoff = (width - (iwidth * m->displayed_columns)) / (m->displayed_columns + 1);
    yoff = (height - (iheight * m->displayed_rows)) / (m->displayed_rows + 1);

    MMI_DBG_ASSERT(pen_event == MMI_PEN_EVENT_DOWN || pen_event == MMI_PEN_EVENT_MOVE || pen_event == MMI_PEN_EVENT_UP);

    /* These asumptions are mandatory */
    MMI_DBG_ASSERT(m->first_displayed_row >= 0 && m->first_displayed_column >= 0);

    if (y < 0)  /* Scroll up */
    {
        /* drag & scroll only applies to Pen Move event */
        if (pen_event != MMI_PEN_EVENT_MOVE || m->first_displayed_row == 0)
        {
            *menu_event = GUI_MATRIX_PEN_NONE;
            *index_of_item = -1;
        }
        else
        {
            new_row = m->first_displayed_row - 1;

            COMPUTE_NEW_COLUMN();

            item_index = new_row * m->n_columns + new_column;

            m->flags |= UI_MATRIX_MENU_FIRST_SHIFT_HIGHLIGHTED_ROW;
            gui_fixed_matrix_menu_goto_item(m, item_index);
            m->flags &= ~UI_MATRIX_MENU_FIRST_SHIFT_HIGHLIGHTED_ROW;

            *menu_event = GUI_MATRIX_PEN_HIGHLIGHT_CHANGED;
            *index_of_item = item_index;
        }
    }
    else if (x < 0) /* Scroll left */
    {
        /* drag & scroll only applies to Pen Move event */
        if (pen_event != MMI_PEN_EVENT_MOVE || m->first_displayed_column == 0)
        {
            *menu_event = GUI_MATRIX_PEN_NONE;
            *index_of_item = -1;
        }
        else
        {
            new_column = m->first_displayed_column - 1;

            COMPUTE_NEW_ROW();

            item_index = new_row * m->n_columns + new_column;

            m->flags |= UI_MATRIX_MENU_FIRST_SHIFT_HIGHLIGHTED_COL;
            gui_fixed_matrix_menu_goto_item(m, item_index);
            m->flags &= ~UI_MATRIX_MENU_FIRST_SHIFT_HIGHLIGHTED_COL;

            *menu_event = GUI_MATRIX_PEN_HIGHLIGHT_CHANGED;
            *index_of_item = item_index;
        }
    }
    else if (y >= height)   /* Scroll down */
    {
        /* drag & scroll only applies to Pen Move event */
        if (pen_event != MMI_PEN_EVENT_MOVE || m->first_displayed_row == m->n_rows - m->displayed_rows)
        {
            *menu_event = GUI_MATRIX_PEN_NONE;
            *index_of_item = -1;
        }
        else
        {
            new_row = m->first_displayed_row + m->displayed_rows;

            COMPUTE_NEW_COLUMN();

            item_index = new_row * m->n_columns + new_column;

            if (item_index < m->n_items)    /* when n_items is not multiple of displayed_columns */
            {
                m->flags |= UI_MATRIX_MENU_LAST_SHIFT_HIGHLIGHTED_ROW;
                gui_fixed_matrix_menu_goto_item(m, item_index);
                m->flags &= ~UI_MATRIX_MENU_LAST_SHIFT_HIGHLIGHTED_ROW;

                *menu_event = GUI_MATRIX_PEN_HIGHLIGHT_CHANGED;
                *index_of_item = item_index;
            }
            else
            {
                *menu_event = GUI_MATRIX_PEN_NONE;
                *index_of_item = -1;
            }
        }
    }
    else if (x >= width)    /* Scroll right */
    {
        /* drag & scroll only applies to Pen Move event */
        if (pen_event != MMI_PEN_EVENT_MOVE || m->first_displayed_column == m->n_columns - m->displayed_columns)
        {
            *menu_event = GUI_MATRIX_PEN_NONE;
            *index_of_item = -1;
        }
        else
        {
            new_column = m->first_displayed_column + m->displayed_columns;

            COMPUTE_NEW_ROW();

            item_index = new_row * m->n_columns + new_column;

            if (item_index < m->n_items)    /* when n_items is not multiple of displayed_columns */
            {
                m->flags |= UI_MATRIX_MENU_LAST_SHIFT_HIGHLIGHTED_COL;
                gui_fixed_matrix_menu_goto_item(m, item_index);
                m->flags &= ~UI_MATRIX_MENU_LAST_SHIFT_HIGHLIGHTED_COL;

                *menu_event = GUI_MATRIX_PEN_HIGHLIGHT_CHANGED;
                *index_of_item = item_index;
            }
            else
            {
                *menu_event = GUI_MATRIX_PEN_NONE;
                *index_of_item = -1;
            }
        }

    }
    else
    {
        S32 act_x = 0, act_y = 0;

        act_x = xoff * (m->displayed_columns) + (m->displayed_columns) * m->item_width;
        act_y = yoff * (m->displayed_rows) + (m->displayed_rows) * m->item_height;

        if (x > act_x || y > act_y)
        {
            *menu_event = GUI_MATRIX_PEN_NONE;
            *index_of_item = -1;
            return;
        }

        COMPUTE_NEW_ROW();
        COMPUTE_NEW_COLUMN();

        item_index = new_row * m->n_columns + new_column;
        if (item_index < m->n_items && item_index != m->highlighted_item)
        {
            gui_fixed_matrix_menu_goto_item(m, item_index);
            *menu_event = GUI_MATRIX_PEN_HIGHLIGHT_CHANGED;
            *index_of_item = item_index;
        }
        else
        {
            if (pen_event == MMI_PEN_EVENT_UP)
            {
                if (m->pen_state.highlight_changed || (item_index >= m->n_items))
                {
                    *menu_event = GUI_MATRIX_PEN_NONE;
                    if (m->pen_state.highlight_changed && (item_index < m->n_items))
                    {
                        *index_of_item = m->highlighted_item;
                    }
                    else
                    {
                        *index_of_item = -1;
                    }
                }
                else
                {
                    *menu_event = GUI_MATRIX_PEN_ITEM_SELECTED;
                    *index_of_item = m->highlighted_item;
                }
            }
            else
            {
                *menu_event = GUI_MATRIX_PEN_NONE;
                if (pen_event == MMI_PEN_EVENT_DOWN)
                {
                    if (item_index == m->highlighted_item)
                    {
                        *index_of_item = item_index;
                    }
                    else
                    {
                        *index_of_item = -1;
                    }
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_fixed_matrix_menu_translate_pen_event
 * DESCRIPTION
 *  Translate the pen events occured in the matrix menu.
 * PARAMETERS
 *  m               [IN]        fixed matrix menu object
 *  pen_event       [IN]        pen event type
 *  x               [IN]        pen x
 *  y               [IN]        pen y
 *  menu_event      [OUT]       pen event result
 * RETURNS
 *  Return MMI_TRUE if the pen event is handled; otherwise, MMI_FALSE.
 *****************************************************************************/
MMI_BOOL gui_fixed_matrix_menu_translate_pen_event(
        fixed_matrix_menu *m,
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_matrix_pen_enum *menu_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    gui_matrix_pen_state_struct *pen_state;
    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;
    S32 item_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pen_state = &m->pen_state;
    ret = MMI_TRUE;

    *menu_event = GUI_MATRIX_PEN_NONE;

    if (m->flags & UI_MATRIX_MENU_DISABLE_PEN)
    {
        return MMI_FALSE;
    }

    if (pen_event != MMI_PEN_EVENT_DOWN && pen_state->pen_on_vertical_scrollbar)
    {
        gui_vertical_scrollbar_translate_pen_event(&m->vbar, pen_event, x, y, &scrollbar_event, &scrollbar_param);
        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
        {
            gui_fixed_matrix_menu_vertical_scroll_by_pen(m, scrollbar_param._u.i, menu_event);
        }
    }
    else if (pen_event != MMI_PEN_EVENT_DOWN && pen_state->pen_on_horizontal_scrollbar)
    {
        gui_horizontal_scrollbar_translate_pen_event(&m->hbar, pen_event, x, y, &scrollbar_event, &scrollbar_param);
        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
        {
            gui_fixed_matrix_menu_horizontal_scroll_by_pen(m, scrollbar_param._u.i, menu_event);
        }
    }
    else
    {
        switch (pen_event)
        {
            case MMI_PEN_EVENT_DOWN:
                if (PEN_CHECK_BOUND(x, y, m->x, m->y, m->width, m->height))
                {
                    if ((m->flags & UI_MATRIX_MENU_SHOW_VERTICAL_SCROLLBAR) &&
                        gui_vertical_scrollbar_translate_pen_event(
                            &m->vbar,
                            MMI_PEN_EVENT_DOWN,
                            x,
                            y,
                            &scrollbar_event,
                            &scrollbar_param))
                    {
                        pen_state->pen_on_vertical_scrollbar = 1;
                        pen_state->pen_on_horizontal_scrollbar = 0;
                        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
                        {
                            gui_fixed_matrix_menu_vertical_scroll_by_pen(m, scrollbar_param._u.i, menu_event);
                        }
                    }
                    else if ((m->flags & UI_MATRIX_MENU_SHOW_HORIZONTAL_SCROLLBAR) &&
                             gui_horizontal_scrollbar_translate_pen_event(
                                &m->hbar,
                                MMI_PEN_EVENT_DOWN,
                                x,
                                y,
                                &scrollbar_event,
                                &scrollbar_param))
                    {
                        pen_state->pen_on_vertical_scrollbar = 0;
                        pen_state->pen_on_horizontal_scrollbar = 1;
                        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
                        {
                            gui_fixed_matrix_menu_horizontal_scroll_by_pen(m, scrollbar_param._u.i, menu_event);
                        }
                    }
                    else
                    {
                        pen_state->pen_on_vertical_scrollbar = 0;
                        pen_state->pen_on_horizontal_scrollbar = 0;

                        gui_fixed_matrix_menu_handle_pen_position(m, x, y, MMI_PEN_EVENT_DOWN, menu_event, &item_index);
                        if (item_index >= 0)
                        {
                            gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
                        }
                    }

                    pen_state->first_highlighed_item = m->highlighted_item;
                    pen_state->highlight_changed = 0;
                }
                else
                {
                    ret = MMI_FALSE;
                }
                break;

            case MMI_PEN_EVENT_MOVE:
                gui_fixed_matrix_menu_handle_pen_position(m, x, y, MMI_PEN_EVENT_MOVE, menu_event, &item_index);
                break;

            case MMI_PEN_EVENT_UP:
                gui_fixed_matrix_menu_handle_pen_position(m, x, y, MMI_PEN_EVENT_UP, menu_event, &item_index);
                break;

            case MMI_PEN_EVENT_LONG_TAP:
                /* Do nothing */
                break;

            case MMI_PEN_EVENT_REPEAT:
                /* Do nothing */
                break;

            case MMI_PEN_EVENT_ABORT:
                /* Do nothing */
                break;

            default:
                MMI_ASSERT(0);

        }
    }

    if (ret)
    {
        if (pen_state->first_highlighed_item != m->highlighted_item)
        {
            pen_state->highlight_changed = 1;
        }
        m->last_highlighted_item = -1;
    }

    return ret;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
/*****************************************************************************
 * FUNCTION
 *  gui_fixed_list_menu_goto_item_without_change_highlight
 * DESCRIPTION
 *  goto the menu item without change highlight item index, even if it is out of current screen.
 * PARAMETERS
 *  m               [IN]        fixed list menu object
 *  first_displayed_item    [IN]    the index of the first displayed item
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_fixed_list_menu_goto_item_without_change_highlight(fixed_list_menu *m, S32 first_displayed_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, total_height, list_height, iheight, iwidth, highlighted_item;
    U8 done, already_out_of_screen;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((first_displayed_item < 0) || (first_displayed_item > m->n_items - 1))
    {
        return;
    }

    if (first_displayed_item == m->first_displayed_item)
    {
        return;
    }

    list_height = m->height;
    total_height = 0;
    done = 0;
    already_out_of_screen = 0;
    highlighted_item = m->highlighted_item;
    if (highlighted_item < m->first_displayed_item || highlighted_item > m->last_displayed_item)
    {
        already_out_of_screen = 1;
    }
    m->first_displayed_item = first_displayed_item;

    for (i = m->first_displayed_item; i < m->n_items && (!done); i++)
    {
#if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__)
        if (i == m->highlighted_item)
        {
            m->current_displayed_item = -1;
        }
        else
        {
            m->current_displayed_item = i;
        }
#endif /* defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__) */ 

        m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);

        total_height += iheight;
        
        if (total_height > list_height)
        {
            done = 1;
            m->last_displayed_item = i - 1;
        }
    }

    /* Check if in the last page */
    if (total_height <= list_height)
    {
        total_height = 0;
        for (i = m->n_items - 1; (i >= 0) && (!done); i--)
        {
    #if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__)
            if (i == m->highlighted_item)
            {
                m->current_displayed_item = -1;
            }
            else
            {
                m->current_displayed_item = i;
            }
    #endif /* defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__) || defined(__MMI_UI_HINTS_IN_MENUITEM__) */ 

            m->item_measure_function(m->items[i], m->common_item_data, &iwidth, &iheight);

            total_height += iheight;
            
            if (total_height > list_height)
            {
                if (m->first_displayed_item > i)
                {
                done = 1;
                    m->first_displayed_item = i + 1;
                    m->last_displayed_item = m->n_items - 1;
            }
                break;
        }
        }
        if (total_height <= list_height)
        {
            m->first_displayed_item = 0;
            m->last_displayed_item = m->n_items - 1;
        }
    }

    if (highlighted_item <= m->last_displayed_item && (highlighted_item >= m->first_displayed_item))
    {
        gui_fixed_list_menu_switch_highlighted_item(m, -1);
    }
    else if (!already_out_of_screen)
    {
        /* highglight item is out of current screen */
        m->item_remove_highlight_function(m->items[highlighted_item], m->common_item_data);
        m->item_unhighlighted(highlighted_item);
        gui_pop_up_description_stop_scroll();
    }
}
#endif  /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */


