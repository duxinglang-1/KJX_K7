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
 *   wgui_touch_screen.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   wgui-level functions for touch screen.
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_TOUCH_SCREEN__)

#include "stdC.h"
#include "mmi_frm_gprot.h"
#include "WguiCategoryGprot.h"
#include "wgui_softkeys.h"

#include "kal_non_specific_general_types.h"     /* needed for TouchScreenGprot.h */
#include "gui_asyncdynamic_menus.h"
#include "gui_dynamic_menus.h"
#include "wgui_dynamic_menus.h"
#include "wgui_asyncdynamic_menus.h"
#include "CommonScreens.h"
#include "CustDataRes.h"
#include "wgui_calendar.h"
#include "Calculator.h"
#include "ProfilingEngine.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_frm_input_gprot.h"
#include "wgui_touch_screen.h"
#include "wgui_draw_manager.h"
#include "gui_buttons.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "GlobalConstants.h"
#include "gui_typedef.h"
#include "wgui_categories_util.h"
#include "wgui_fixed_menus.h"
#include "gui_fixed_menus.h"
#include "wgui_inline_edit.h"
#include "gui.h"
#include "gui_config.h"
#include "gui_inputs.h"
#include "gui_effect_oem.h"
#include "wgui_categories_enum.h"
#include "gui_scrollbars.h"
#include "wgui_include.h"
#include "wgui_categories_stopwatch.h"
#include "wgui_inputs.h"
#include "wgui_categories_inputs.h"
#include "gui_panel.h"
#include "gui_data_types.h"
#include "gdi_include.h"

#ifdef UI_EMS_SUPPORT
#include "gui_ems.h"
#endif /* UI_EMS_SUPPORT */


#ifdef __J2ME__
//extern void jui_widget_refresh_lcd(S32 x1, S32 y1, S32 x2, S32 y2);   //JUI MVM
#include "jui_interface.h"
#endif 

/***************************************************************************** 
* Golbal Variable
*****************************************************************************/
U16 g_pen_to_control;    /* indicate which control receive pen events */

/***************************************************************************** 
* Golbal Function
*****************************************************************************/
MMI_BOOL wgui_null_pen_hdlr(mmi_pen_point_struct point);
mmi_pen_handler wgui_category_control_area_pen_handlers[MMI_PEN_EVENT_TYPE_MAX];
mmi_pen_handler wgui_category_control_area2_pen_handlers[MMI_PEN_EVENT_TYPE_MAX];
mmi_pen_handler wgui_image_pen_handlers[DM_MAX_IMAGES][MMI_PEN_EVENT_TYPE_MAX];

/***************************************************************************** 
* Local Variable
*****************************************************************************/
/* 
 * In draw manager, some controls have more than one elements.
 * We need to know which element is selected 
 */
static U16 g_pen_to_control_index = 0;

static wgui_pen_pre_hdlr_funcptr wgui_pen_pre_hdlr_callback;
static wgui_pen_pre_hdlr_funcptr wgui_pen_pre_hdlr_callback_backup;

static MMI_BOOL wgui_pen_highlight_item_changed = MMI_FALSE;

static wgui_search_control_set_callback_function g_wgui_search_control_set_callback = NULL;

/***************************************************************************** 
* Local Function
*****************************************************************************/

/***************************************************************************** 
* Extern Global  Variables
*****************************************************************************/
extern icontext_button MMI_softkeys[];

#ifdef UI_EMS_SUPPORT
extern UI_EMS_input_box MMI_EMS_inputbox;
#endif

/***************************************************************************** 
* Extern Global  Function
*****************************************************************************/
extern void (*redraw_current_inline_item) (void);
#ifdef UI_EMS_SUPPORT
extern void redraw_EMS_inputbox(void);
#endif /* UI_EMS_SUPPORT */


/*****************************************************************************
 * FUNCTION
 *  wgui_execute_dm_category_control_area_pen_handler
 * DESCRIPTION
 *  Execute category control area pen handlers
 * PARAMETERS
 *  pen_event_type          [IN]        
 *  point                   [IN]        Pen position
 *  key_event_type(?)       [IN]        - KEY_EVENT_DOWN, KEY_EVENT_UP, KEY_LONG_PRESS
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL wgui_execute_dm_category_control_area_pen_handler(U16 pen_event_type, mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(pen_event_type < MMI_PEN_EVENT_TYPE_MAX);

    if (wgui_category_control_area_pen_handlers[pen_event_type] != NULL)
    {
        return wgui_category_control_area_pen_handlers[pen_event_type] (point);
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_execute_dm_category_control_area2_pen_handler
 * DESCRIPTION
 *  Execute category control area pen handlers
 * PARAMETERS
 *  pen_event_type          [IN]        
 *  point                   [IN]        Pen position
 *  key_event_type(?)       [IN]        - KEY_EVENT_DOWN, KEY_EVENT_UP, KEY_LONG_PRESS
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL wgui_execute_dm_category_control_area2_pen_handler(U16 pen_event_type, mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(pen_event_type < MMI_PEN_EVENT_TYPE_MAX);

    if (wgui_category_control_area2_pen_handlers[pen_event_type] != NULL)
    {
        return wgui_category_control_area2_pen_handlers[pen_event_type] (point);
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_execute_dm_image_pen_handler
 * DESCRIPTION
 *  Execute category control area pen handlers
 * PARAMETERS
 *  img_idx                 [IN]        Index of image controlled by draw manager
 *  pen_event_type          [IN]        
 *  point                   [IN]        Pen position
 *  key_event_type(?)       [IN]        - KEY_EVENT_DOWN, KEY_EVENT_UP, KEY_LONG_PRESS
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL wgui_execute_dm_image_pen_handler(U16 img_idx, U16 pen_event_type, mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(img_idx < dm_get_image_count());
    MMI_ASSERT(pen_event_type < MMI_PEN_EVENT_TYPE_MAX);

    if (wgui_image_pen_handlers[img_idx][pen_event_type] != NULL)
    {
        return wgui_image_pen_handlers[img_idx][pen_event_type] (point);
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_pen_execute_LSK_handler
 * DESCRIPTION
 *  Execute left softkey handler from pen
 * PARAMETERS
 *  key_type        [IN]        - KEY_EVENT_DOWN, KEY_EVENT_UP, KEY_LONG_PRESS
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_pen_execute_LSK_handler(U16 key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* In MMI convention, applications typically clear key handlers before sending requests to other tasks, 
       which avoid re-entrance of protocol handler */

    if (GetKeyHandler(KEY_LSK, key_type))
    {
        /* Some softkey handlers use GetkeyInfo() */
        SetkeyInfo(KEY_LSK, key_type);
        execute_softkey_function(key_type, MMI_LEFT_SOFTKEY);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_pen_execute_RSK_handler
 * DESCRIPTION
 *  Execute right softkey handler from pen
 * PARAMETERS
 *  key_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_pen_execute_RSK_handler(U16 key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* In MMI convention, applications typically clear key handlers before sending requests to other tasks, 
       which avoid re-entrance of protocol handler */

    if (GetKeyHandler(KEY_RSK, key_type))
    {
        /* Some softkey handlers use GetkeyInfo() */
        SetkeyInfo(KEY_RSK, key_type);
        execute_softkey_function(key_type, MMI_RIGHT_SOFTKEY);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_pen_execute_CSK_handler
 * DESCRIPTION
 *  Execute center softkey handler from pen
 * PARAMETERS
 *  key_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_pen_execute_CSK_handler(U16 key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* In MMI convention, applications typically clear key handlers before sending requests to other tasks, 
       which avoid re-entrance of protocol handler */

#ifndef __MMI_WGUI_DISABLE_CSK__
    if (wgui_softkey_is_csk_enabled() == MMI_TRUE && 
        GetKeyHandler(KEY_CSK, key_type) )
    {
        /* Some softkey handlers use GetkeyInfo() */
        SetkeyInfo(KEY_CSK, key_type);
        execute_softkey_function(key_type, MMI_CENTER_SOFTKEY);
    }
#endif /*__MMI_WGUI_DISABLE_CSK__ */	
}


/*****************************************************************************
 * FUNCTION
 *  wgui_pen_redraw_inline_editor
 * DESCRIPTION
 *  Redraw inline editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_pen_redraw_inline_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    redraw_fixed_list();
    redraw_current_inline_item();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_register_search_control_set
 * DESCRIPTION
 *  Register the search control set callback function.
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_register_search_control_set_callback_function(wgui_search_control_set_callback_function f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_wgui_search_control_set_callback = f;

}



/*****************************************************************************
 * FUNCTION
 *  wgui_general_pen_down_hdlr
 * DESCRIPTION
 *  General Pen Down event handler.
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_general_pen_down_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 u8CtrlCt = 0;
    S32 u8NoOfUICtrls = 0;
    S16 *UICtrlAccessPtr_p = NULL, *DeafultCoordinateSet_p = NULL;
    dm_cat_scr_info_struct dm_cat_scr_info;
    S32 idx = 0;
    U8 *control_set_ptr = NULL;
    BOOL ret;
    gui_button_pen_enum button_event;
    gui_list_pen_enum menu_event;
    gui_matrix_pen_enum matrix_event;
    gui_inline_pen_enum inline_event;
    gui_slide_control_pen_event_enum slide_event;
    gui_pen_event_param_struct param;
#if ENABLE_CIRCULAR_3D_MENU
    gui_3D_circular_menu_pen_enum circular_event;
#endif /* ENABLE_CIRCULAR_3D_MENU */
    wgui_status_icon_bar_pen_enum status_icon_bar_event;
    S32 status_icon_id;
    gui_multi_line_input_box_pen_enum multi_line_input_box_event;
#ifdef UI_EMS_SUPPORT
    gui_EMS_input_box_pen_enum EMS_input_box_event;
#endif
    S16 dm_image_index = -1;
    S16 dm_button_index = -1;
    S16 dm_panel_index = -1;
    MMI_BOOL in_freerun;
#if (defined(__MMI_STATUS_ICONBAR_COSMOS_STYLE__) || defined(__MMI_NCENTER_SUPPORT__))
    mmi_event_struct evt;
#endif /* defined(__MMI_STATUS_ICONBAR_COSMOS_STYLE__) || defined(__MMI_NCENTER_SUPPORT__) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* to reset dm_data when screen changes */
    if (g_dm_data.s32CatId == 0)
    {
        g_pen_to_control = NONE;
        g_pen_to_control_index = 0;
        if (g_wgui_search_control_set_callback)
        {
            control_set_ptr = g_wgui_search_control_set_callback();
            if (control_set_ptr == NULL)
               return;
            u8NoOfUICtrls = control_set_ptr[0];
        }
        else
        {
        return;
        }
    }
    else
    {       
    control_set_ptr = dm_search_control_set((U16) g_dm_data.s32CatId, &DeafultCoordinateSet_p);

    /* First element in Category-Controls map specifies the number of controls */
    u8NoOfUICtrls = control_set_ptr[0];

    UICtrlAccessPtr_p = dm_search_coordinate_set(g_dm_data.s32ScrId);
    if (UICtrlAccessPtr_p == NULL)
    {
        UICtrlAccessPtr_p = DeafultCoordinateSet_p;
    }

   /*************************************************************************
   If dm_search_coordinate_set returns NULL, then there must be Default Coordinate Set.
   *************************************************************************/
    MMI_ASSERT(UICtrlAccessPtr_p != NULL);

    /* Fist element in coordinate set specifies the coordinates of complete category screen */
    UICtrlAccessPtr_p = dm_get_cat_scr_coordinates(UICtrlAccessPtr_p, &dm_cat_scr_info);
    }

    in_freerun = MMI_FALSE;
    /* Start from the toppest components */
    if (gui_screen_smooth_scrolling_in_freerun())
    {
        for (u8CtrlCt = u8NoOfUICtrls; u8CtrlCt > 0; u8CtrlCt--)
        {
            if (control_set_ptr[u8CtrlCt] == DM_LIST1 ||
                control_set_ptr[u8CtrlCt] == DM_DYNAMIC_LIST1 ||
                control_set_ptr[u8CtrlCt] == DM_ASYNCDYNAMIC_LIST1 ||
                control_set_ptr[u8CtrlCt] == DM_INLINE_FIXED_LIST1 ||
                control_set_ptr[u8CtrlCt] == DM_CATEGORY_CONTROLLED_AREA)
            {
                switch (control_set_ptr[u8CtrlCt])
                {   
                case DM_INLINE_FIXED_LIST1:
                    MMI_fixed_list_menu.pen_redraw_menu_function = wgui_pen_redraw_inline_editor;
                    break;
                case DM_LIST1:
                    MMI_fixed_list_menu.pen_redraw_menu_function = show_fixed_list;
                    break;
                case DM_DYNAMIC_LIST1:
                    MMI_fixed_list_menu.pen_redraw_menu_function = show_dynamic_list;
                    break;
                case DM_ASYNCDYNAMIC_LIST1:
                    MMI_fixed_list_menu.pen_redraw_menu_function = show_asyncdynamic_list;
                    break;
                case DM_CATEGORY_CONTROLLED_AREA:
#ifndef __MMI_FTE_SUPPORT__
                    if (
#ifdef __MMI_CAT103_SUPPORT__
                        g_dm_data.s32CatId == MMI_CATEGORY103_ID ||
#endif
#ifdef __MMI_CAT203_SUPPORT__
                        g_dm_data.s32CatId == MMI_CATEGORY203_ID ||
#endif
                        g_dm_data.s32CatId == MMI_CATEGORY200_ID ||
                        g_dm_data.s32CatId == MMI_CATEGORY202_ID ||
                        g_dm_data.s32CatId == MMI_CATEGORY202_NOINFO_ID)
                    {
                        wgui_execute_dm_category_control_area_pen_handler(KEY_EVENT_DOWN, point);
                    }
#else
					if (g_dm_data.s32CatId == MMI_CATEGORY200_ID || 
						g_dm_data.s32CatId == MMI_CATEGORY202_ID ||
                        g_dm_data.s32CatId == MMI_CATEGORY202_NOINFO_ID)
					{
						MMI_fixed_list_menu.pen_redraw_menu_function = show_dynamic_list;
						gui_vertical_scrollbar_set_pen_self_scroll(&MMI_fixed_list_menu.vbar, MMI_TRUE);
						gui_fixed_list_menu_set_pen_scroll_delay(&MMI_fixed_list_menu, GUI_DYNAMIC_LIST_PEN_SCROLL_DELAY);
					}
#ifdef __MMI_CAT103_SUPPORT__
					else if (g_dm_data.s32CatId == MMI_CATEGORY103_ID)
					{
					    wgui_execute_dm_category_control_area_pen_handler(KEY_EVENT_DOWN, point);
					}
#endif
#ifdef __MMI_CAT203_SUPPORT__
					else if (g_dm_data.s32CatId == MMI_CATEGORY203_ID)
					{
						MMI_fixed_list_menu.pen_redraw_menu_function = wgui_dynamic_list_show_icontext_menu;
						gui_vertical_scrollbar_set_pen_self_scroll(&MMI_fixed_list_menu.vbar, MMI_TRUE);
					    gui_fixed_list_menu_set_pen_scroll_delay(&MMI_fixed_list_menu, GUI_DYNAMIC_LIST_PEN_SCROLL_DELAY);
					}
#endif
#endif
                    break;
                default:
                    break;
                }
                if (wgui_pen_pre_hdlr_callback && 
                    wgui_pen_pre_hdlr_callback(control_set_ptr[u8CtrlCt], point, MMI_PEN_EVENT_DOWN))
                {
                    g_pen_to_control = control_set_ptr[u8CtrlCt];
                    
                    return;
                }
                in_freerun = MMI_TRUE;
            }
        }
    }
    for (u8CtrlCt = u8NoOfUICtrls; u8CtrlCt > 0; u8CtrlCt--)
    {
        switch (control_set_ptr[u8CtrlCt])
        {
            case DM_LIST1:
                MMI_fixed_list_menu.pen_redraw_menu_function = show_fixed_list;
                break;
            case DM_DYNAMIC_LIST1:
                MMI_fixed_list_menu.pen_redraw_menu_function = show_dynamic_list;
                break;
            case DM_ASYNCDYNAMIC_LIST1:
                MMI_fixed_list_menu.pen_redraw_menu_function = show_asyncdynamic_list;
                break;
            case DM_CATEGORY_CONTROLLED_AREA:
#ifndef __MMI_FTE_SUPPORT__
                if (
#ifdef __MMI_CAT103_SUPPORT__
                    g_dm_data.s32CatId == MMI_CATEGORY103_ID ||
#endif
#ifdef __MMI_CAT203_SUPPORT__
                    g_dm_data.s32CatId == MMI_CATEGORY203_ID ||
#endif
                    g_dm_data.s32CatId == MMI_CATEGORY200_ID ||
                    g_dm_data.s32CatId == MMI_CATEGORY202_ID ||
                    g_dm_data.s32CatId == MMI_CATEGORY202_NOINFO_ID)
                {
                    wgui_execute_dm_category_control_area_pen_handler(KEY_EVENT_DOWN, point);
                }
#else
					if (g_dm_data.s32CatId == MMI_CATEGORY200_ID || 
						g_dm_data.s32CatId == MMI_CATEGORY202_ID ||
                        g_dm_data.s32CatId == MMI_CATEGORY202_NOINFO_ID)
					{
						MMI_fixed_list_menu.pen_redraw_menu_function = show_dynamic_list;
						gui_vertical_scrollbar_set_pen_self_scroll(&MMI_fixed_list_menu.vbar, MMI_TRUE);
						gui_fixed_list_menu_set_pen_scroll_delay(&MMI_fixed_list_menu, GUI_DYNAMIC_LIST_PEN_SCROLL_DELAY);
					}
#ifdef __MMI_CAT103_SUPPORT__
					else if (g_dm_data.s32CatId == MMI_CATEGORY103_ID)
					{
					    wgui_execute_dm_category_control_area_pen_handler(KEY_EVENT_DOWN, point);
					}
#endif
#ifdef __MMI_CAT203_SUPPORT__
					else if (g_dm_data.s32CatId == MMI_CATEGORY203_ID)
					{
#ifdef __MMI_FTE_SUPPORT__
                        wgui_execute_dm_category_control_area_pen_handler(KEY_EVENT_DOWN, point);
#else /* __MMI_FTE_SUPPORT__ */
						MMI_fixed_list_menu.pen_redraw_menu_function = wgui_dynamic_list_show_icontext_menu;
						gui_vertical_scrollbar_set_pen_self_scroll(&MMI_fixed_list_menu.vbar, MMI_TRUE);
					    gui_fixed_list_menu_set_pen_scroll_delay(&MMI_fixed_list_menu, GUI_DYNAMIC_LIST_PEN_SCROLL_DELAY);
#endif /* __MMI_FTE_SUPPORT__ */
					}
#endif
#endif
                break;
            default:
                break;
        }
        if (wgui_pen_pre_hdlr_callback && in_freerun == MMI_FALSE &&
            wgui_pen_pre_hdlr_callback(control_set_ptr[u8CtrlCt], point, MMI_PEN_EVENT_DOWN))
        {
            g_pen_to_control = control_set_ptr[u8CtrlCt];
            
            return;
        }
        switch (control_set_ptr[u8CtrlCt])
        {
            case DM_LIST1:
                /* redraw_fixed_list */
                gui_vertical_scrollbar_set_pen_self_scroll(&MMI_fixed_list_menu.vbar, MMI_TRUE);
                gui_fixed_list_menu_set_pen_scroll_delay(&MMI_fixed_list_menu, 0);

                ret = gui_fixed_list_menu_translate_pen_event(
                        &MMI_fixed_list_menu,
                        MMI_PEN_EVENT_DOWN,
                        point.x,
                        point.y,
                        &menu_event);
                if (ret)
                {
                    g_pen_to_control = DM_LIST1;
                    wgui_pen_highlight_item_changed = MMI_FALSE;
                    if (menu_event == GUI_LIST_PEN_HIGHLIGHT_CHANGED)
                    {
                        wgui_pen_highlight_item_changed = MMI_TRUE;
                    }
                    if (menu_event == GUI_LIST_PEN_HIGHLIGHT_CHANGED || menu_event == GUI_LIST_PEN_NEED_REDRAW)
                    {
                    #ifdef __MMI_INTERACTIVE_PROFILNG__
                        mmi_frm_profiling_delay_start_timer(MMI_FRM_PROFILING_DELAY_LIST_HIGHLIGHT);
                    #endif
                    
                        MMI_fixed_list_menu.pen_redraw_menu_function();
                        
                    #ifdef __MMI_INTERACTIVE_PROFILNG__
                        mmi_frm_profiling_delay_perform(MMI_FRM_PROFILING_DELAY_LIST_HIGHLIGHT);
                    #endif
                    }
                    return;
                }
                break;

            case DM_BASE_CONTROL_SET1:
            case DM_BASE_CONTROL_SET2:
            case DM_BASE_CONTROL_SET_SUBMENU:
            case DM_BASE_CONTROL_SET_COMMON:
            case DM_BUTTON_BAR1:
            case DM_LSK:
            case DM_RSK:
                if (!(g_dm_data.s32flags & DM_NO_SOFTKEY) || ((g_dm_data.s32CatId == 0) && (g_wgui_search_control_set_callback)))
                {
                    /* LSK */
                    ret = gui_icontext_button_translate_pen_event(
                            &MMI_softkeys[MMI_LEFT_SOFTKEY],
                            MMI_PEN_EVENT_DOWN,
                            point.x,
                            point.y,
                            &button_event);

                    if (ret)
                    {
                        g_pen_to_control = DM_LSK;
                        if (button_event == GUI_BUTTON_PEN_DOWN)
                        {
                            wgui_pen_execute_LSK_handler(KEY_EVENT_DOWN);
                        }
                        return;
                    }

                    /* RSK */
                    ret = gui_icontext_button_translate_pen_event(
                            &MMI_softkeys[MMI_RIGHT_SOFTKEY],
                            MMI_PEN_EVENT_DOWN,
                            point.x,
                            point.y,
                            &button_event);

                    if (ret)
                    {
                        g_pen_to_control = DM_RSK;
                        if (button_event == GUI_BUTTON_PEN_DOWN)
                        {
                            wgui_pen_execute_RSK_handler(KEY_EVENT_DOWN);
                        }
                        return;
                    }

#ifndef __MMI_WGUI_DISABLE_CSK__
                    /* CSK */
                    if (wgui_softkey_is_csk_enabled() == MMI_TRUE)
                    {
                    #if !defined(__MMI_BASIC_UI_STYLE__) && !defined(__OP01_FWPBW__)
                        ret = gui_icontext_button_translate_pen_event(
                               &MMI_softkeys[MMI_CENTER_SOFTKEY],
                               MMI_PEN_EVENT_DOWN,
                               point.x,
                               point.y,
                               &button_event);

                        if (ret)
                        {
                            g_pen_to_control = DM_CSK;
                            if (button_event == GUI_BUTTON_PEN_DOWN)
                            {
                                wgui_pen_execute_CSK_handler(KEY_EVENT_DOWN);
                            }
                            return;
                        }
                    #endif
                    }
#endif /*__MMI_WGUI_DISABLE_CSK__*/					
                }

#ifdef __MMI_ICON_BAR_SUPPORT__
                #ifdef __MMI_FTE_SUPPORT__
                ret = wgui_icon_bar_translate_pen_event(
                        point,
                        MMI_PEN_EVENT_DOWN);
                if (ret)
                {
                    g_pen_to_control = DM_ICON_BAR;
                    return;
                }
                #endif

#endif /*__MMI_ICON_BAR_SUPPORT__*/
                ret = wgui_status_icon_bar_translate_pen_event(
                        MMI_PEN_EVENT_DOWN,
                        point.x,
                        point.y,
                        &status_icon_id,
                        &status_icon_bar_event);
                if (ret)
                {
                    g_pen_to_control = DM_STATUS_BAR1;
//                #if (defined(__MMI_STATUS_ICONBAR_COSMOS_STYLE__) || defined(__MMI_NCENTER_SUPPORT__))
//                    MMI_FRM_INIT_EVENT(&evt, EVT_ID_STATUS_ICON_BAR_TAP);
//                    mmi_frm_post_event(&evt, wgui_status_icon_bar_tap_proc, NULL); 
//                #endif
                    return;
                }
                break;

            case DM_MATRIX_MENU1:
                ret = gui_fixed_matrix_menu_translate_pen_event(
                        &MMI_fixed_matrix_menu,
                        MMI_PEN_EVENT_DOWN,
                        point.x,
                        point.y,
                        &matrix_event);
                if (ret)
                {
		    wgui_pen_highlight_item_changed = MMI_FALSE;
                    if (matrix_event == GUI_MATRIX_PEN_HIGHLIGHT_CHANGED)
                    {
                        wgui_pen_highlight_item_changed = MMI_TRUE;
                    }
                    g_pen_to_control = DM_MATRIX_MENU1;
                    if (matrix_event == GUI_MATRIX_PEN_HIGHLIGHT_CHANGED || matrix_event == GUI_MATRIX_PEN_NEED_REDRAW)
                    {
                    #ifdef __MMI_INTERACTIVE_PROFILNG__
                        mmi_frm_profiling_delay_start_timer(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
                    #endif
                    
                        show_fixed_matrix();
                        
                    #ifdef __MMI_INTERACTIVE_PROFILNG__
                        mmi_frm_profiling_delay_perform(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
                    #endif
                    }
                    return;
                }
                break;

#ifdef  __MMI_SUPPORT_DYNAMIC_MATRIX_MENU__
            case DM_DYNAMIC_MATRIX1:
                gui_vertical_scrollbar_set_pen_self_scroll(&MMI_fixed_matrix_menu.vbar, MMI_TRUE);
                gui_dynamic_matrix_menu_set_pen_scroll_delay(&MMI_fixed_matrix_menu, GUI_DYNAMIC_LIST_PEN_SCROLL_DELAY);
                ret = gui_dynamic_matrix_menu_translate_pen_event(
                        &MMI_fixed_matrix_menu,
                        MMI_PEN_EVENT_DOWN,
                        point.x,
                        point.y,
                        &matrix_event);
                if (ret)
                {
                    wgui_pen_highlight_item_changed = MMI_FALSE;
                    if (matrix_event == GUI_MATRIX_PEN_HIGHLIGHT_CHANGED)
                    {
                        wgui_pen_highlight_item_changed = MMI_TRUE;
                    }
                    g_pen_to_control = DM_DYNAMIC_MATRIX1;
                    if (matrix_event == GUI_MATRIX_PEN_HIGHLIGHT_CHANGED || matrix_event == GUI_MATRIX_PEN_NEED_REDRAW)
                    {
                    #ifdef __MMI_INTERACTIVE_PROFILNG__
                        mmi_frm_profiling_delay_start_timer(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
                    #endif
                    
                        show_dynamic_matrix();
                        
                    #ifdef __MMI_INTERACTIVE_PROFILNG__
                        mmi_frm_profiling_delay_perform(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
                    #endif
                    }
                    return;
                }
                break;
#endif  // __MMI_SUPPORT_DYNAMIC_MATRIX_MENU__
            case DM_DYNAMIC_LIST1:
                gui_vertical_scrollbar_set_pen_self_scroll(&MMI_fixed_list_menu.vbar, MMI_TRUE);
                gui_fixed_list_menu_set_pen_scroll_delay(&MMI_fixed_list_menu, GUI_DYNAMIC_LIST_PEN_SCROLL_DELAY);

                ret = gui_dynamic_list_menu_translate_pen_event(
                        &MMI_fixed_list_menu,
                        MMI_PEN_EVENT_DOWN,
                        point.x,
                        point.y,
                        &menu_event);
                if (ret)
                {
                    g_pen_to_control = DM_DYNAMIC_LIST1;
                    if (menu_event == GUI_LIST_PEN_HIGHLIGHT_CHANGED || menu_event == GUI_LIST_PEN_NEED_REDRAW)
                    {
                        MMI_fixed_list_menu.pen_redraw_menu_function();
                    }
                    return;
                }
                break;

            case DM_ASYNCDYNAMIC_LIST1:
                gui_vertical_scrollbar_set_pen_self_scroll(&MMI_fixed_list_menu.vbar, MMI_TRUE);
                gui_fixed_list_menu_set_pen_scroll_delay(&MMI_fixed_list_menu, GUI_DYNAMIC_LIST_PEN_SCROLL_DELAY);

                ret = gui_asyncdynamic_list_menu_translate_pen_event(
                        &MMI_fixed_list_menu,
                        MMI_PEN_EVENT_DOWN,
                        point.x,
                        point.y,
                        &menu_event);
                if (ret)
                {
                    g_pen_to_control = DM_ASYNCDYNAMIC_LIST1;
                    if (menu_event == GUI_LIST_PEN_HIGHLIGHT_CHANGED || menu_event == GUI_LIST_PEN_NEED_REDRAW)
                    {
                        MMI_fixed_list_menu.pen_redraw_menu_function();
                    }
                    return;
                }
                break;
#ifdef  __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__                
            case DM_ASYNCDYNAMIC_MATRIX1:
                gui_vertical_scrollbar_set_pen_self_scroll(&MMI_fixed_matrix_menu.vbar, MMI_TRUE);
                gui_asyncdynamic_matrix_menu_set_pen_scroll_delay(&MMI_fixed_matrix_menu, GUI_DYNAMIC_LIST_PEN_SCROLL_DELAY);
                ret = gui_asyncdynamic_matrix_menu_translate_pen_event(
                    &MMI_fixed_matrix_menu,
                    MMI_PEN_EVENT_DOWN,
                    point.x,
                    point.y,
                    &matrix_event);
                if (ret)
                {
                    g_pen_to_control = DM_ASYNCDYNAMIC_MATRIX1;
                    if (matrix_event == GUI_MATRIX_PEN_HIGHLIGHT_CHANGED || matrix_event == GUI_MATRIX_PEN_NEED_REDRAW)
                    {
#ifdef __MMI_INTERACTIVE_PROFILNG__
                        mmi_frm_profiling_delay_start_timer(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
#endif
                        
                        show_asyncdynamic_matrix();
                        
#ifdef __MMI_INTERACTIVE_PROFILNG__
                        mmi_frm_profiling_delay_perform(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
#endif
                    }
                    return;
                }
                break;
#endif  /* __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__ */                

            case DM_INLINE_FIXED_LIST1:
                MMI_fixed_list_menu.pen_redraw_menu_function = wgui_pen_redraw_inline_editor;
                /* 
                 * The scroll offset of inline editor might be different than the scroll value of scrollbar
                 * due to the restrictions of inline editor.
                 */
                gui_vertical_scrollbar_set_pen_self_scroll(&MMI_fixed_list_menu.vbar, MMI_FALSE);
                gui_fixed_list_menu_set_pen_scroll_delay(&MMI_fixed_list_menu, 0);

                ret = gui_inline_translate_pen_event(
                        &MMI_fixed_list_menu,
                        MMI_PEN_EVENT_DOWN,
                        point.x,
                        point.y,
                        &inline_event);
                if (ret)
                {
                    g_pen_to_control = DM_INLINE_FIXED_LIST1;
                    if (inline_event == GUI_INLINE_PEN_NEED_REDRAW)
                    {
                        MMI_fixed_list_menu.pen_redraw_menu_function();
                    }
                    return;
                }
                break;

            case DM_SLIDE_CONTROL:
            {
                extern S32 dm_slide_control_count;

                for (idx = 0; idx < dm_slide_control_count; idx++)
                {
                    ret = wgui_slide_control_translate_pen_event(
                            &MMI_slide_control[idx],
                            MMI_PEN_EVENT_DOWN,
                            point.x,
                            point.y,
                            &slide_event,
                            &param);
                    if (ret)
                    {
                        g_pen_to_control = DM_SLIDE_CONTROL;

                        if (MMI_current_slide_control != &MMI_slide_control[idx])
                        {
                            gui_lock_double_buffer();

                            /* Redraw previous focused slide */
                            wgui_hide_slide_control_focus();
                            wgui_show_slide_control();

                            /* Draw current focused slide */
                            wgui_slide_control_set_focus(&MMI_slide_control[idx]);

                            wgui_show_slide_control_focus();
                            if (slide_event == GUI_SLIDE_CONTROL_PEN_JUMP_TO_I)
                            {
                                wgui_slide_control_set_value(param._u.i);
                            }
                            else
                            {
                                wgui_show_slide_control();
                            }

                            gui_unlock_double_buffer();
                            gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
                        }
                        else
                        {
                            if (slide_event == GUI_SLIDE_CONTROL_PEN_JUMP_TO_I)
                            {
                                if (dm_slide_control_count > 1)
                                {
                                    wgui_show_slide_control_focus();
                                }
                                wgui_slide_control_set_value(param._u.i);
                            }
                        }

                        return;
                    }
                }
                break;
            }

        #if ENABLE_CIRCULAR_3D_MENU
            case DM_CIRCULAR_MENU1:
                ret = gui_3D_circular_menu_translate_pen_event(
                        &wgui_CM3D_menu,
                        MMI_PEN_EVENT_DOWN,
                        point.x,
                        point.y,
                        &circular_event);
                if (ret)
                {
                    g_pen_to_control = DM_CIRCULAR_MENU1;
                    if (circular_event == GUI_3D_CIRCULAR_MENU_PEN_GOTO_NEXT)
                    {
                        circular_3d_menu_next();
                    }
                    else if (circular_event == GUI_3D_CIRCULAR_MENU_PEN_GOTO_PREVIOUS)
                    {
                        circular_3d_menu_previous();
                    }
                    return;
                }
                break;
        #endif /* ENABLE_CIRCULAR_3D_MENU */                

            case DM_HORIZONTAL_TAB_BAR:
                ret = wgui_general_pen_horizontal_tab_bar_hdlr(point, MMI_PEN_EVENT_DOWN);
                if (ret)
                {
                    g_pen_to_control = DM_HORIZONTAL_TAB_BAR;
                    return;
                }

                break;
            case DM_MULTILINE_INPUTBOX1:
            {
                if (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE)
                {
                    ret = gui_multi_line_input_box_translate_pen_event(
                            &MMI_multiline_inputbox,
                            MMI_PEN_EVENT_DOWN,
                            point.x,
                            point.y,
                            &multi_line_input_box_event);
                    if (ret)
                    {
                        g_pen_to_control = DM_MULTILINE_INPUTBOX1;
                        return;
                    }
                }
            }
                break;

#ifdef UI_EMS_SUPPORT
            case DM_EMS_INPUTBOX1:
            {
                if (MMI_EMS_inputbox.flags & UI_EMS_INPUT_BOX_VIEW_MODE)
                {
                    ret = gui_EMS_input_box_translate_pen_event(
                            &MMI_EMS_inputbox,
                            MMI_PEN_EVENT_DOWN,
                            point.x,
                            point.y,
                            &EMS_input_box_event);
                    if (ret)
                    {
                    /*
                    #ifdef __MMI_MESSAGES_EMS__
                        EMS_cancel_object_focus();
                    #endif 
                    */
                        g_pen_to_control = DM_EMS_INPUTBOX1;
                        return;
                    }
                }
            }
                break;
#endif /* UI_EMS_SUPPORT */

            case DM_DIALER_INPUT_BOX1:
            {
                if (PEN_CHECK_BOUND
                    (point.x, point.y, MMI_dialer_inputbox.x, MMI_dialer_inputbox.y, MMI_dialer_inputbox.width,
                     MMI_dialer_inputbox.height))
                {
                    g_pen_to_control = DM_DIALER_INPUT_BOX1;
                    wgui_inputs_dialer_handle_multitap_complete(WGUI_DIALER_BOX_ACTIVE_MULTITAP_ANY);
                    gui_show_dialer_input_box_ext(&MMI_dialer_inputbox, point.x, point.y);
                    show_dialer_inputbox();
                    return;
                }
            }
                break;

            case DM_IMAGE:
                /* If there are more than one draw manager object in control set, we only need to scan all image once */
                if (dm_image_index == -1)   /* first time for DM_IMAGE */
                {
                    for (dm_image_index = 0; dm_image_index < dm_get_image_count(); dm_image_index++)
                    {
                        if (dm_check_image_bound(dm_image_index, point))
                        {
                            MMI_ASSERT(dm_image_index < dm_get_image_count());
                            if (wgui_image_pen_handlers[dm_image_index][MMI_PEN_EVENT_DOWN] != NULL)
                            {
                                g_pen_to_control = DM_IMAGE;
                                g_pen_to_control_index = dm_image_index;
                                if (wgui_execute_dm_image_pen_handler(dm_image_index, MMI_PEN_EVENT_DOWN, point))
                                {
                                    return;
                                }
                                else
                                {
                                    g_pen_to_control_index = 0;
                                    g_pen_to_control = NONE;
                                }
                            }
                        }
                    }
                }
                break;

            case DM_BUTTON:
                if (dm_button_index == -1)  /* first time for DM_BUTTON */
                {
                    for (dm_button_index = 0; dm_button_index < dm_get_button_count(); dm_button_index++)
                    {
                        ret = gui_icontext_button_translate_pen_event(
                                dm_get_button(dm_button_index),
                                MMI_PEN_EVENT_DOWN,
                                point.x,
                                point.y,
                                &button_event);

                        if (ret)
                        {
                            g_pen_to_control = DM_BUTTON;
                            g_pen_to_control_index = dm_button_index;
                            if (button_event == GUI_BUTTON_PEN_DOWN)
                            {
                                dm_execute_button_handler(dm_button_index, MMI_PEN_EVENT_DOWN);
                            }
                            return;
                        }
                    }
                }
                break;

            case DM_CATEGORY_CONTROLLED_AREA:
                if (wgui_category_control_area_pen_handlers[KEY_EVENT_DOWN] != NULL)
                {
                    g_pen_to_control = DM_CATEGORY_CONTROLLED_AREA;
                    if (wgui_execute_dm_category_control_area_pen_handler(MMI_PEN_EVENT_DOWN, point) == MMI_TRUE)
                    {
                        return;
                    }
                    else
                    {
                        g_pen_to_control = NONE;
                    }
                }
                break;
            case DM_CATEGORY_CONTROLLED_AREA2:
                if (wgui_category_control_area2_pen_handlers[MMI_PEN_EVENT_DOWN] != NULL)
                {
                    g_pen_to_control = DM_CATEGORY_CONTROLLED_AREA2;
                    if (wgui_execute_dm_category_control_area2_pen_handler(MMI_PEN_EVENT_DOWN, point) == MMI_TRUE)
                    {
                        return;
                    }
                    else
                    {
                        g_pen_to_control = NONE;
                    }
                }
                break;
            case DM_CALENDAR:
                if (wgui_calendar_translate_pen_event(MMI_PEN_EVENT_DOWN, point.x, point.y))
                {
                    g_pen_to_control = DM_CALENDAR;
                    return;
                }
                break;
            case DM_PANEL:
                if (dm_panel_index == -1) /* first time for DM_PANEL */
                {
                    gui_panel_struct* panel;
                    
                    for (dm_panel_index = 0; dm_panel_index < dm_get_panel_count(); dm_panel_index++)
                    {
                        panel = dm_get_panel(dm_panel_index);
                        ret = gui_panel_translate_pen_event(
                                panel, 
                                MMI_PEN_EVENT_DOWN, 
                                point.x, 
                                point.y);

                        if (ret)
                        {
                            g_pen_to_control = DM_PANEL;
                            g_pen_to_control_index = dm_panel_index;
                            return;
                        }
                    }
                }
                break;
                
            default:
                g_pen_to_control = NONE;
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_general_pen_move_hdlr
 * DESCRIPTION
 *  General Pen Move event handler.
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_general_pen_move_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_button_pen_enum button_event;
    gui_multi_line_input_box_pen_enum multi_line_input_box_event;
#ifdef UI_EMS_SUPPORT
    gui_EMS_input_box_pen_enum EMS_input_box_event;
#endif
    wgui_status_icon_bar_pen_enum status_icon_bar_event;
    S32 status_icon_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_pen_pre_hdlr_callback && 
        wgui_pen_pre_hdlr_callback(g_pen_to_control, point, MMI_PEN_EVENT_MOVE))
    {
        return;
    }
    
    if (g_pen_to_control == DM_LSK)
    {
        gui_icontext_button_translate_pen_event(
            &MMI_softkeys[MMI_LEFT_SOFTKEY],
            MMI_PEN_EVENT_MOVE,
            point.x,
            point.y,
            &button_event);
    }
    else if (g_pen_to_control == DM_RSK)
    {
        gui_icontext_button_translate_pen_event(
            &MMI_softkeys[MMI_RIGHT_SOFTKEY],
            MMI_PEN_EVENT_MOVE,
            point.x,
            point.y,
            &button_event);
    }
    else if (g_pen_to_control == DM_CSK)
    {
        gui_icontext_button_translate_pen_event(
            &MMI_softkeys[MMI_CENTER_SOFTKEY],
            MMI_PEN_EVENT_MOVE,
            point.x,
            point.y,
            &button_event);
    }
#ifdef __MMI_ICON_BAR_SUPPORT__	
#ifdef __MMI_FTE_SUPPORT__
    else if (g_pen_to_control == DM_ICON_BAR)
    {
        wgui_icon_bar_translate_pen_event(
            point,
            MMI_PEN_EVENT_MOVE);
    }
#endif
#endif /*__MMI_ICON_BAR_SUPPORT__*/
    else if (g_pen_to_control == DM_STATUS_BAR1)
    {
        wgui_status_icon_bar_translate_pen_event(
            MMI_PEN_EVENT_MOVE,
            point.x,
            point.y,
            &status_icon_id,
            &status_icon_bar_event);

    }
    else if (g_pen_to_control == DM_LIST1)
    {
        wgui_general_pen_list_menu_hdlr(point, MMI_PEN_EVENT_MOVE);
    }
    else if (g_pen_to_control == DM_INLINE_FIXED_LIST1)
    {
        wgui_general_pen_inline_hdlr(point, MMI_PEN_EVENT_MOVE);
    }
    else if (g_pen_to_control == DM_DYNAMIC_LIST1)
    {
        wgui_general_pen_dynamic_list_menu_hdlr(point, MMI_PEN_EVENT_MOVE);
    }
#ifdef  __MMI_SUPPORT_DYNAMIC_MATRIX_MENU__
    else if (g_pen_to_control == DM_DYNAMIC_MATRIX1)
    {
        wgui_general_pen_dynamic_matrix_menu_hdlr(point, MMI_PEN_EVENT_MOVE);
    }
#endif  // __MMI_SUPPORT_DYNAMIC_MATRIX_MENU__
    else if (g_pen_to_control == DM_ASYNCDYNAMIC_LIST1)
    {
        wgui_general_pen_asyncdynamic_list_menu_hdlr(point, MMI_PEN_EVENT_MOVE);
    }
#ifdef  __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__    
    else if (g_pen_to_control == DM_ASYNCDYNAMIC_MATRIX1)
    {
        wgui_general_pen_asyncdynamic_matrix_menu_hdlr(point, MMI_PEN_EVENT_MOVE);
    }
#endif  /* __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__ */    
    else if (g_pen_to_control == DM_MATRIX_MENU1)
    {
        wgui_general_pen_matrix_menu_hdlr(point, MMI_PEN_EVENT_MOVE);
    }
    else if (g_pen_to_control == DM_SLIDE_CONTROL)
    {
        wgui_general_pen_slide_control_hdlr(point, MMI_PEN_EVENT_MOVE);
    }
#if ENABLE_CIRCULAR_3D_MENU    
    else if (g_pen_to_control == DM_CIRCULAR_MENU1)
    {
        wgui_general_pen_3D_circular_menu_hdlr(point, MMI_PEN_EVENT_MOVE);
    }
#endif /* ENABLE_CIRCULAR_3D_MENU */    
    else if (g_pen_to_control == DM_HORIZONTAL_TAB_BAR)
    {
        wgui_general_pen_horizontal_tab_bar_hdlr(point, MMI_PEN_EVENT_MOVE);
    }
    else if (g_pen_to_control == DM_MULTILINE_INPUTBOX1)
    {
        gui_multi_line_input_box_translate_pen_event(
            &MMI_multiline_inputbox,
            MMI_PEN_EVENT_MOVE,
            point.x,
            point.y,
            &multi_line_input_box_event);
    }
#ifdef UI_EMS_SUPPORT
    else if (g_pen_to_control == DM_EMS_INPUTBOX1)
    {
        gui_EMS_input_box_translate_pen_event(
            &MMI_EMS_inputbox,
            MMI_PEN_EVENT_MOVE,
            point.x,
            point.y,
            &EMS_input_box_event);
    }
#endif /* UI_EMS_SUPPORT */
    else if (g_pen_to_control == DM_DIALER_INPUT_BOX1)
    {
        if (PEN_CHECK_BOUND
            (point.x, point.y, MMI_dialer_inputbox.x, MMI_dialer_inputbox.y, MMI_dialer_inputbox.width,
             MMI_dialer_inputbox.height))
        {
            g_pen_to_control = DM_DIALER_INPUT_BOX1;
            gui_show_dialer_input_box_ext(&MMI_dialer_inputbox, point.x, point.y);
            show_dialer_inputbox();
            return;
        }
    }
    else if (g_pen_to_control == DM_BUTTON)
    {
        gui_icontext_button_translate_pen_event(
            dm_get_button(g_pen_to_control_index),
            MMI_PEN_EVENT_MOVE,
            point.x,
            point.y,
            &button_event);
    }
    else if (g_pen_to_control == DM_CATEGORY_CONTROLLED_AREA)
    {
        wgui_execute_dm_category_control_area_pen_handler(MMI_PEN_EVENT_MOVE, point);
    }
    else if (g_pen_to_control == DM_CATEGORY_CONTROLLED_AREA2)
    {
        wgui_execute_dm_category_control_area2_pen_handler(MMI_PEN_EVENT_MOVE, point);
    }
    else if( g_pen_to_control == DM_CALENDAR)
    {
        wgui_calendar_translate_pen_event(MMI_PEN_EVENT_MOVE, point.x, point.y);
    }
    else if (g_pen_to_control == DM_PANEL)
    {
        gui_panel_translate_pen_event(
            dm_get_panel(g_pen_to_control_index), 
            MMI_PEN_EVENT_MOVE, 
            point.x, 
            point.y);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_general_pen_up_hdlr
 * DESCRIPTION
 *  General Pen Up event handler.
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_general_pen_up_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_button_pen_enum button_event;
    gui_multi_line_input_box_pen_enum multi_line_input_box_event;
#ifdef UI_EMS_SUPPORT
    gui_EMS_input_box_pen_enum EMS_input_box_event;
#endif
    wgui_status_icon_bar_pen_enum status_icon_bar_event;
    S32 status_icon_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_pen_pre_hdlr_callback && 
        wgui_pen_pre_hdlr_callback(g_pen_to_control, point, MMI_PEN_EVENT_UP))
    {
        g_pen_to_control = NONE;

        return;
    }

    if (g_pen_to_control == DM_LSK)
    {
        MMI_BOOL state = MMI_FALSE;
        state = gui_icontext_button_translate_pen_event(
                    &MMI_softkeys[MMI_LEFT_SOFTKEY],
                    MMI_PEN_EVENT_UP,
                    point.x,
                    point.y,
                    &button_event);

        if (state == MMI_TRUE)
        {
            if (button_event == GUI_BUTTON_PEN_UP_INSIDE)
            {
                wgui_pen_execute_LSK_handler(KEY_EVENT_UP);
            }
            else
            {
                SetkeyInfo(KEY_LSK, KEY_EVENT_UP);
            }
        }
    }
    else if (g_pen_to_control == DM_RSK)
    {
        MMI_BOOL state = MMI_FALSE;
        state = gui_icontext_button_translate_pen_event(
                    &MMI_softkeys[MMI_RIGHT_SOFTKEY],
                    MMI_PEN_EVENT_UP,
                    point.x,
                    point.y,
                    &button_event);

        if (state == MMI_TRUE)
        {
            if (button_event == GUI_BUTTON_PEN_UP_INSIDE)
            {
                wgui_pen_execute_RSK_handler(KEY_EVENT_UP);
            }
            else
            {
                SetkeyInfo(KEY_RSK, KEY_EVENT_UP);
            }
        }
    }
    else if (g_pen_to_control == DM_CSK)
    {
        gui_icontext_button_translate_pen_event(
            &MMI_softkeys[MMI_CENTER_SOFTKEY],
            MMI_PEN_EVENT_UP,
            point.x,
            point.y,
            &button_event);

        if (button_event == GUI_BUTTON_PEN_UP_INSIDE)
        {
            wgui_pen_execute_CSK_handler(KEY_EVENT_UP);
        }
        else
        {
            SetkeyInfo(KEY_CSK, KEY_EVENT_UP);
        }
    }
#ifdef __MMI_ICON_BAR_SUPPORT__	
#ifdef __MMI_FTE_SUPPORT__
    else if (g_pen_to_control == DM_ICON_BAR)
    {
        wgui_icon_bar_translate_pen_event(
            point,
            MMI_PEN_EVENT_UP);
    }
#endif
#endif /*__MMI_ICON_BAR_SUPPORT__*/
    else if (g_pen_to_control == DM_STATUS_BAR1)
    {
        wgui_status_icon_bar_translate_pen_event(
            MMI_PEN_EVENT_UP,
            point.x,
            point.y,
            &status_icon_id,
            &status_icon_bar_event);



        if (status_icon_bar_event == WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON)      /* select an icon */
        {
            wgui_status_icon_bar_execute_pen_event_handler(status_icon_id, WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON);
        }
    }
    else if (g_pen_to_control == DM_LIST1)
    {
        wgui_general_pen_list_menu_hdlr(point, MMI_PEN_EVENT_UP);
    }
    else if (g_pen_to_control == DM_INLINE_FIXED_LIST1)
    {
        wgui_general_pen_inline_hdlr(point, MMI_PEN_EVENT_UP);
    }
    else if (g_pen_to_control == DM_DYNAMIC_LIST1)
    {
        wgui_general_pen_dynamic_list_menu_hdlr(point, MMI_PEN_EVENT_UP);
    }
#ifdef  __MMI_SUPPORT_DYNAMIC_MATRIX_MENU__
    else if (g_pen_to_control == DM_DYNAMIC_MATRIX1)
    {
        wgui_general_pen_dynamic_matrix_menu_hdlr(point, MMI_PEN_EVENT_UP);
    }
#endif  // __MMI_SUPPORT_DYNAMIC_MATRIX_MENU__
    else if (g_pen_to_control == DM_ASYNCDYNAMIC_LIST1)
    {
        wgui_general_pen_asyncdynamic_list_menu_hdlr(point, MMI_PEN_EVENT_UP);
    }
#ifdef  __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__    
    else if (g_pen_to_control == DM_ASYNCDYNAMIC_MATRIX1)
    {
        wgui_general_pen_asyncdynamic_matrix_menu_hdlr(point, MMI_PEN_EVENT_UP);
    }
#endif  /* __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__ */    
    else if (g_pen_to_control == DM_MATRIX_MENU1)
    {
        wgui_general_pen_matrix_menu_hdlr(point, MMI_PEN_EVENT_UP);
    }
    else if (g_pen_to_control == DM_SLIDE_CONTROL)
    {
        wgui_general_pen_slide_control_hdlr(point, MMI_PEN_EVENT_UP);
    }
#if ENABLE_CIRCULAR_3D_MENU    
    else if (g_pen_to_control == DM_CIRCULAR_MENU1)
    {
        wgui_general_pen_3D_circular_menu_hdlr(point, MMI_PEN_EVENT_UP);
    }
#endif /* ENABLE_CIRCULAR_3D_MENU */
    else if (g_pen_to_control == DM_HORIZONTAL_TAB_BAR)
    {
        wgui_general_pen_horizontal_tab_bar_hdlr(point, MMI_PEN_EVENT_UP);
    }
    else if (g_pen_to_control == DM_MULTILINE_INPUTBOX1)
    {
        gui_multi_line_input_box_translate_pen_event(
            &MMI_multiline_inputbox,
            MMI_PEN_EVENT_UP,
            point.x,
            point.y,
            &multi_line_input_box_event);
        
        if ((GUI_MULTI_LINE_INPUT_BOX_PEN_TEXT_UP == multi_line_input_box_event) && (MMI_multiline_inputbox.hilite_click_cb))
        {
            if (MMI_multiline_inputbox.hilite_str_number != 0)
            {
                if (gui_multi_line_input_box_is_pen_down_in_hilite(&MMI_multiline_inputbox))
				{
                    MMI_multiline_inputbox.hilite_click_cb(MMI_multiline_inputbox.current_hilite_idx);
                }
            }
        }
    }
#ifdef UI_EMS_SUPPORT
    else if (g_pen_to_control == DM_EMS_INPUTBOX1)
    {
        gui_EMS_input_box_translate_pen_event(
            &MMI_EMS_inputbox,
            MMI_PEN_EVENT_UP,
            point.x,
            point.y,
            &EMS_input_box_event);
        if (GUI_EMS_INPUT_BOX_PEN_TEXT_UP == EMS_input_box_event)
        {
            if (GUI_EMS_INPUT_BOX_PEN_SCROLL_BAR != EMS_input_box_event)
            {
            #ifdef __MMI_MESSAGES_EMS__
                EMS_cancel_object_focus(); 
            #endif
                gui_show_EMS_input_box_ext(&MMI_EMS_inputbox, point.x, point.y);
                gui_EMS_input_box_locate_cursor(&MMI_EMS_inputbox);
            #ifdef __UI_EMS_HIGHLIGHT_LIST_SUPPORT__
                if (MMI_EMS_inputbox.hilite_str_number != 0)
                {
                    if (gui_EMS_input_box_is_pen_down_in_hilite(&MMI_EMS_inputbox))
					{
                        gui_EMS_input_box_go_to_hilite(&MMI_EMS_inputbox,MMI_EMS_inputbox.current_hilite_idx);
                        redraw_EMS_inputbox();
                        MMI_EMS_inputbox.hilite_click_cb(MMI_EMS_inputbox.current_hilite_idx);
                    }
                }
                else
            #endif /* __UI_EMS_HIGHLIGHT_LIST_SUPPORT__ */
                {
                    redraw_EMS_inputbox();
                }
            }
        }
    }
#endif /* UI_EMS_SUPPORT */
    else if (g_pen_to_control == DM_DIALER_INPUT_BOX1)
    {
        /* CURRENTLY DO NOTHING */
    }
    else if (g_pen_to_control == DM_IMAGE)
    {
        wgui_execute_dm_image_pen_handler(g_pen_to_control_index, MMI_PEN_EVENT_UP, point);
    }
    else if (g_pen_to_control == DM_BUTTON)
    {
        gui_icontext_button_translate_pen_event(
            dm_get_button(g_pen_to_control_index),
            MMI_PEN_EVENT_UP,
            point.x,
            point.y,
            &button_event);

        if (button_event == GUI_BUTTON_PEN_UP_INSIDE)
        {
            dm_execute_button_handler(g_pen_to_control_index, KEY_EVENT_UP);
        }
    }
    else if (g_pen_to_control == DM_CATEGORY_CONTROLLED_AREA)
    {
        wgui_execute_dm_category_control_area_pen_handler(MMI_PEN_EVENT_UP, point);
    }
    else if (g_pen_to_control == DM_CATEGORY_CONTROLLED_AREA2)
    {
        wgui_execute_dm_category_control_area2_pen_handler(MMI_PEN_EVENT_UP, point);
    }
    else if ( g_pen_to_control == DM_CALENDAR)
    {
        wgui_calendar_translate_pen_event(MMI_PEN_EVENT_UP, point.x, point.y);
    }
    else if (g_pen_to_control == DM_PANEL)
    {
        gui_panel_translate_pen_event(
            dm_get_panel(g_pen_to_control_index), 
            MMI_PEN_EVENT_UP, 
            point.x, 
            point.y);
    }
    
    g_pen_to_control = NONE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_general_pen_abort_hdlr
 * DESCRIPTION
 *  General Pen Abort event handler.
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_general_pen_abort_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_button_pen_enum button_event;
    gui_multi_line_input_box_pen_enum multi_line_input_box_event;
 #ifdef UI_EMS_SUPPORT
    gui_EMS_input_box_pen_enum EMS_input_box_event;
 #endif
    wgui_status_icon_bar_pen_enum status_icon_bar_event;
    S32 status_icon_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_pen_pre_hdlr_callback && 
        wgui_pen_pre_hdlr_callback(g_pen_to_control, point, MMI_PEN_EVENT_ABORT))
    {
        g_pen_to_control = NONE;
    
        return;
    }
    
    if (g_pen_to_control == DM_LSK)
    {
        MMI_BOOL state = MMI_FALSE;

        state = gui_icontext_button_translate_pen_event(
            &MMI_softkeys[MMI_LEFT_SOFTKEY],
            MMI_PEN_EVENT_ABORT,
            point.x,
            point.y,
            &button_event);

        if (state == MMI_TRUE)
        {
            SetkeyInfo(KEY_INVALID, MAX_KEY_TYPE);
        }
    }
    else if (g_pen_to_control == DM_RSK)
    {
        MMI_BOOL state = MMI_FALSE;

        state = gui_icontext_button_translate_pen_event(
            &MMI_softkeys[MMI_RIGHT_SOFTKEY],
            MMI_PEN_EVENT_ABORT,
            point.x,
            point.y,
            &button_event);

        if (state == MMI_TRUE)
        {
            SetkeyInfo(KEY_INVALID, MAX_KEY_TYPE);
        }
    }
    else if (g_pen_to_control == DM_CSK)
    {
        MMI_BOOL state = MMI_FALSE;

        state = gui_icontext_button_translate_pen_event(
            &MMI_softkeys[MMI_CENTER_SOFTKEY],
            MMI_PEN_EVENT_ABORT,
            point.x,
            point.y,
            &button_event);

        if (state == MMI_TRUE)
        {
            SetkeyInfo(KEY_INVALID, MAX_KEY_TYPE);
        }
    }
#ifdef __MMI_ICON_BAR_SUPPORT__	
#ifdef __MMI_FTE_SUPPORT__
    else if (g_pen_to_control == DM_ICON_BAR)
    {
        wgui_icon_bar_translate_pen_event(
            point,
            MMI_PEN_EVENT_ABORT);
    }
#endif
#endif /*__MMI_ICON_BAR_SUPPORT__*/
    else if (g_pen_to_control == DM_STATUS_BAR1)
    {
        wgui_status_icon_bar_translate_pen_event(
            MMI_PEN_EVENT_ABORT,
            point.x,
            point.y,
            &status_icon_id,
            &status_icon_bar_event);
    }
    else if (g_pen_to_control == DM_LIST1)
    {
        wgui_general_pen_list_menu_hdlr(point, MMI_PEN_EVENT_ABORT);
    }
    else if (g_pen_to_control == DM_INLINE_FIXED_LIST1)
    {
        wgui_general_pen_inline_hdlr(point, MMI_PEN_EVENT_ABORT);
    }
    else if (g_pen_to_control == DM_DYNAMIC_LIST1)
    {
        wgui_general_pen_dynamic_list_menu_hdlr(point, MMI_PEN_EVENT_ABORT);
    }
#ifdef  __MMI_SUPPORT_DYNAMIC_MATRIX_MENU__
    else if (g_pen_to_control == DM_DYNAMIC_MATRIX1)
    {
        wgui_general_pen_dynamic_matrix_menu_hdlr(point, MMI_PEN_EVENT_ABORT);
    }
#endif  // __MMI_SUPPORT_DYNAMIC_MATRIX_MENU__
    else if (g_pen_to_control == DM_ASYNCDYNAMIC_LIST1)
    {
        wgui_general_pen_asyncdynamic_list_menu_hdlr(point, MMI_PEN_EVENT_ABORT);
    }
#ifdef  __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__    
    else if (g_pen_to_control == DM_ASYNCDYNAMIC_MATRIX1)
    {
        wgui_general_pen_asyncdynamic_matrix_menu_hdlr(point, MMI_PEN_EVENT_ABORT);
    }
#endif  /* __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__ */    
    else if (g_pen_to_control == DM_MATRIX_MENU1)
    {
        wgui_general_pen_matrix_menu_hdlr(point, MMI_PEN_EVENT_ABORT);
    }
    else if (g_pen_to_control == DM_SLIDE_CONTROL)
    {
        wgui_general_pen_slide_control_hdlr(point, MMI_PEN_EVENT_ABORT);
    }
#if ENABLE_CIRCULAR_3D_MENU    
    else if (g_pen_to_control == DM_CIRCULAR_MENU1)
    {
        wgui_general_pen_3D_circular_menu_hdlr(point, MMI_PEN_EVENT_ABORT);
    }
#endif /* ENABLE_CIRCULAR_3D_MENU */    
    else if (g_pen_to_control == DM_HORIZONTAL_TAB_BAR)
    {
        wgui_general_pen_horizontal_tab_bar_hdlr(point, MMI_PEN_EVENT_ABORT);
    }
    else if (g_pen_to_control == DM_MULTILINE_INPUTBOX1)
    {
        gui_multi_line_input_box_translate_pen_event(
            &MMI_multiline_inputbox,
            MMI_PEN_EVENT_ABORT,
            point.x,
            point.y,
            &multi_line_input_box_event);
    }
#ifdef UI_EMS_SUPPORT
    else if (g_pen_to_control == DM_EMS_INPUTBOX1)
    {
        gui_EMS_input_box_translate_pen_event(
            &MMI_EMS_inputbox,
            MMI_PEN_EVENT_ABORT,
            point.x,
            point.y,
            &EMS_input_box_event);
    }
#endif /* UI_EMS_SUPPORT */
    else if (g_pen_to_control == DM_DIALER_INPUT_BOX1)
    {
        /* CURRENTLY DO NOTHING */
    }
    else if (g_pen_to_control == DM_CATEGORY_CONTROLLED_AREA)
    {
        wgui_execute_dm_category_control_area_pen_handler(MMI_PEN_EVENT_ABORT, point);
    }
    else if (g_pen_to_control == DM_CATEGORY_CONTROLLED_AREA2)
    {
        wgui_execute_dm_category_control_area2_pen_handler(MMI_PEN_EVENT_ABORT, point);
    }
    else if (g_pen_to_control == DM_CALENDAR)
    {
        wgui_calendar_translate_pen_event(MMI_PEN_EVENT_ABORT, point.x, point.y);
    }
    else if (g_pen_to_control == DM_PANEL)
    {
        gui_panel_translate_pen_event(
            dm_get_panel(g_pen_to_control_index), 
            MMI_PEN_EVENT_ABORT, 
            point.x, 
            point.y);
    }
    
    g_pen_to_control = NONE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_general_pen_long_tap_hdlr
 * DESCRIPTION
 *  General Pen Long Tap event handler.
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_general_pen_long_tap_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_button_pen_enum button_event;
    gui_multi_line_input_box_pen_enum multi_line_input_box_event;
#ifdef UI_EMS_SUPPORT
    gui_EMS_input_box_pen_enum EMS_input_box_event;
#endif
    wgui_status_icon_bar_pen_enum status_icon_bar_event;
    S32 status_icon_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_pen_pre_hdlr_callback && 
        wgui_pen_pre_hdlr_callback(g_pen_to_control, point, MMI_PEN_EVENT_LONG_TAP))
    {
        return;
    }

    if (g_pen_to_control == DM_LSK)
    {
        gui_icontext_button_translate_pen_event(
            &MMI_softkeys[MMI_LEFT_SOFTKEY],
            MMI_PEN_EVENT_LONG_TAP,
            point.x,
            point.y,
            &button_event);
        if (button_event == GUI_BUTTON_PEN_LONGTAP)
        {
            wgui_pen_execute_LSK_handler(KEY_LONG_PRESS);
        }
    }
    else if (g_pen_to_control == DM_RSK)
    {
        gui_icontext_button_translate_pen_event(
            &MMI_softkeys[MMI_RIGHT_SOFTKEY],
            MMI_PEN_EVENT_LONG_TAP,
            point.x,
            point.y,
            &button_event);
        if (button_event == GUI_BUTTON_PEN_LONGTAP)
        {
            wgui_pen_execute_RSK_handler(KEY_LONG_PRESS);
        }
    }
    else if (g_pen_to_control == DM_CSK)
    {
        gui_icontext_button_translate_pen_event(
            &MMI_softkeys[MMI_CENTER_SOFTKEY],
            MMI_PEN_EVENT_LONG_TAP,
            point.x,
            point.y,
            &button_event);
        if (button_event == GUI_BUTTON_PEN_LONGTAP)
        {
            /* Some softkey handlers use GetkeyInfo() */
            SetkeyInfo(KEY_CSK, KEY_LONG_PRESS);
            if (GetKeyHandler(KEY_CSK, KEY_LONG_PRESS) != NULL)
            {
                ExecuteCurrKeyHandler(KEY_CSK, KEY_LONG_PRESS);
            }
        }
    }
#ifdef __MMI_ICON_BAR_SUPPORT__	
#ifdef __MMI_FTE_SUPPORT__
    else if (g_pen_to_control == DM_ICON_BAR)
    {
        wgui_icon_bar_translate_pen_event(
            point,
            MMI_PEN_EVENT_LONG_TAP);
    }
#endif
#endif /*__MMI_ICON_BAR_SUPPORT__*/
    else if (g_pen_to_control == DM_STATUS_BAR1)
    {
        wgui_status_icon_bar_translate_pen_event(
            MMI_PEN_EVENT_LONG_TAP,
            point.x,
            point.y,
            &status_icon_id,
            &status_icon_bar_event);
        if (status_icon_bar_event == WGUI_STATUS_ICON_BAR_PEN_LONG_PRESS_ICON)
        {
            wgui_status_icon_bar_execute_pen_event_handler(status_icon_id, WGUI_STATUS_ICON_BAR_PEN_LONG_PRESS_ICON);
        }
    }
    else if (g_pen_to_control == DM_LIST1)
    {
        wgui_general_pen_list_menu_hdlr(point, MMI_PEN_EVENT_LONG_TAP);
    }
    else if (g_pen_to_control == DM_INLINE_FIXED_LIST1)
    {
        wgui_general_pen_inline_hdlr(point, MMI_PEN_EVENT_LONG_TAP);
    }
    else if (g_pen_to_control == DM_DYNAMIC_LIST1)
    {
        wgui_general_pen_dynamic_list_menu_hdlr(point, MMI_PEN_EVENT_LONG_TAP);
    }
#ifdef  __MMI_SUPPORT_DYNAMIC_MATRIX_MENU__
    else if (g_pen_to_control == DM_DYNAMIC_MATRIX1)
    {
        wgui_general_pen_dynamic_matrix_menu_hdlr(point, MMI_PEN_EVENT_LONG_TAP);
    }
#endif  // __MMI_SUPPORT_DYNAMIC_MATRIX_MENU__
    else if (g_pen_to_control == DM_ASYNCDYNAMIC_LIST1)
    {
        wgui_general_pen_asyncdynamic_list_menu_hdlr(point, MMI_PEN_EVENT_LONG_TAP);
    }
#ifdef  __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__    
    else if (g_pen_to_control == DM_ASYNCDYNAMIC_MATRIX1)
    {
        wgui_general_pen_asyncdynamic_matrix_menu_hdlr(point, MMI_PEN_EVENT_LONG_TAP);
    }
#endif  /* __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__ */    
    else if (g_pen_to_control == DM_MATRIX_MENU1)
    {
        wgui_general_pen_matrix_menu_hdlr(point, MMI_PEN_EVENT_LONG_TAP);
    }
    else if (g_pen_to_control == DM_SLIDE_CONTROL)
    {
        wgui_general_pen_slide_control_hdlr(point, MMI_PEN_EVENT_LONG_TAP);
    }
#if ENABLE_CIRCULAR_3D_MENU    
    else if (g_pen_to_control == DM_CIRCULAR_MENU1)
    {
        wgui_general_pen_3D_circular_menu_hdlr(point, MMI_PEN_EVENT_LONG_TAP);
    }
#endif /* ENABLE_CIRCULAR_3D_MENU */    
    else if (g_pen_to_control == DM_HORIZONTAL_TAB_BAR)
    {
        wgui_general_pen_horizontal_tab_bar_hdlr(point, MMI_PEN_EVENT_LONG_TAP);
    }
    else if (g_pen_to_control == DM_MULTILINE_INPUTBOX1)
    {
        gui_multi_line_input_box_translate_pen_event(
            &MMI_multiline_inputbox,
            MMI_PEN_EVENT_LONG_TAP,
            point.x,
            point.y,
            &multi_line_input_box_event);
    }
#ifdef UI_EMS_SUPPORT
    else if (g_pen_to_control == DM_EMS_INPUTBOX1)
    {
        gui_EMS_input_box_translate_pen_event(
            &MMI_EMS_inputbox,
            MMI_PEN_EVENT_LONG_TAP,
            point.x,
            point.y,
            &EMS_input_box_event);
    }
#endif /* UI_EMS_SUPPORT */
    else if (g_pen_to_control == DM_DIALER_INPUT_BOX1)
    {
        /* CURRENTLY DO NOTHING */
    }
    else if (g_pen_to_control == DM_IMAGE)
    {
        wgui_execute_dm_image_pen_handler(g_pen_to_control_index, MMI_PEN_EVENT_LONG_TAP, point);
    }
    else if (g_pen_to_control == DM_BUTTON)
    {
        gui_icontext_button_translate_pen_event(
            dm_get_button(g_pen_to_control_index),
            MMI_PEN_EVENT_LONG_TAP,
            point.x,
            point.y,
            &button_event);
        if (button_event == GUI_BUTTON_PEN_LONGTAP)
        {
            dm_execute_button_handler(g_pen_to_control_index, MMI_PEN_EVENT_LONG_TAP);
        }

    }
    else if (g_pen_to_control == DM_CATEGORY_CONTROLLED_AREA)
    {
        wgui_execute_dm_category_control_area_pen_handler(MMI_PEN_EVENT_LONG_TAP, point);
    }
    else if (g_pen_to_control == DM_CATEGORY_CONTROLLED_AREA2)
    {
        wgui_execute_dm_category_control_area2_pen_handler(MMI_PEN_EVENT_LONG_TAP, point);
    }
    else if (g_pen_to_control == DM_CALENDAR)
    {
        wgui_calendar_translate_pen_event(MMI_PEN_EVENT_LONG_TAP, point.x, point.y);
    }
    else if (g_pen_to_control == DM_PANEL)
    {
        gui_panel_translate_pen_event(
            dm_get_panel(g_pen_to_control_index), 
            MMI_PEN_EVENT_LONG_TAP, 
            point.x, 
            point.y);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  wgui_general_pen_repeat_hdlr
 * DESCRIPTION
 *  General Pen Repeat event handler.
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_general_pen_repeat_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_button_pen_enum button_event;
    gui_multi_line_input_box_pen_enum multi_line_input_box_event;
#ifdef UI_EMS_SUPPORT
    gui_EMS_input_box_pen_enum EMS_input_box_event;
#endif
    wgui_status_icon_bar_pen_enum status_icon_bar_event;
    S32 status_icon_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_pen_pre_hdlr_callback && 
        wgui_pen_pre_hdlr_callback(g_pen_to_control, point, MMI_PEN_EVENT_REPEAT))
    {
        return;
    }
    
    if (g_pen_to_control == DM_LSK)
    {
        gui_icontext_button_translate_pen_event(
            &MMI_softkeys[MMI_LEFT_SOFTKEY],
            MMI_PEN_EVENT_REPEAT,
            point.x,
            point.y,
            &button_event);
        if (button_event == GUI_BUTTON_PEN_LONGTAP)
        {
            /* wgui_pen_execute_LSK_handler(KEY_LONG_PRESS); */
        }
    }
    else if (g_pen_to_control == DM_RSK)
    {
        gui_icontext_button_translate_pen_event(
            &MMI_softkeys[MMI_RIGHT_SOFTKEY],
            MMI_PEN_EVENT_REPEAT,
            point.x,
            point.y,
            &button_event);
        if (button_event == GUI_BUTTON_PEN_REPEAT)
        {
            /* wgui_pen_execute_RSK_handler(KEY_LONG_PRESS); */
            wgui_pen_execute_RSK_handler(KEY_EVENT_REPEAT);
        }
    }
    else if (g_pen_to_control == DM_CSK)
    {
        gui_icontext_button_translate_pen_event(
            &MMI_softkeys[MMI_CENTER_SOFTKEY],
            MMI_PEN_EVENT_REPEAT,
            point.x,
            point.y,
            &button_event);
    }
#ifdef __MMI_ICON_BAR_SUPPORT__	
#ifdef __MMI_FTE_SUPPORT__
    else if (g_pen_to_control == DM_ICON_BAR)
    {
        wgui_icon_bar_translate_pen_event(
            point,
            MMI_PEN_EVENT_REPEAT);
    }
#endif
#endif /*__MMI_ICON_BAR_SUPPORT__*/
    else if (g_pen_to_control == DM_STATUS_BAR1)
    {
        wgui_status_icon_bar_translate_pen_event(
            MMI_PEN_EVENT_REPEAT,
            point.x,
            point.y,
            &status_icon_id,
            &status_icon_bar_event);
        if (status_icon_bar_event == WGUI_STATUS_ICON_BAR_PEN_LONG_PRESS_ICON)  /* long press on an icon */
        {
            wgui_status_icon_bar_execute_pen_event_handler(status_icon_id, WGUI_STATUS_ICON_BAR_PEN_LONG_PRESS_ICON);
        }
    }
    else if (g_pen_to_control == DM_LIST1)
    {
        wgui_general_pen_list_menu_hdlr(point, MMI_PEN_EVENT_REPEAT);
    }
    else if (g_pen_to_control == DM_INLINE_FIXED_LIST1)
    {
        wgui_general_pen_inline_hdlr(point, MMI_PEN_EVENT_REPEAT);
    }
    else if (g_pen_to_control == DM_DYNAMIC_LIST1)
    {
        wgui_general_pen_dynamic_list_menu_hdlr(point, MMI_PEN_EVENT_REPEAT);
    }
#ifdef  __MMI_SUPPORT_DYNAMIC_MATRIX_MENU__
    else if (g_pen_to_control == DM_DYNAMIC_MATRIX1)
    {
        wgui_general_pen_dynamic_matrix_menu_hdlr(point, MMI_PEN_EVENT_REPEAT);
    }
#endif  // __MMI_SUPPORT_DYNAMIC_MATRIX_MENU__
    else if (g_pen_to_control == DM_ASYNCDYNAMIC_LIST1)
    {
        wgui_general_pen_asyncdynamic_list_menu_hdlr(point, MMI_PEN_EVENT_REPEAT);
    }
#ifdef  __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__    
    else if (g_pen_to_control == DM_ASYNCDYNAMIC_MATRIX1)
    {
        wgui_general_pen_asyncdynamic_matrix_menu_hdlr(point, MMI_PEN_EVENT_REPEAT);
    }
#endif  /* __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__ */    
    else if (g_pen_to_control == DM_MATRIX_MENU1)
    {
        wgui_general_pen_matrix_menu_hdlr(point, MMI_PEN_EVENT_REPEAT);
    }
    else if (g_pen_to_control == DM_SLIDE_CONTROL)
    {
        wgui_general_pen_slide_control_hdlr(point, MMI_PEN_EVENT_REPEAT);
    }
#if ENABLE_CIRCULAR_3D_MENU    
    else if (g_pen_to_control == DM_CIRCULAR_MENU1)
    {
        wgui_general_pen_3D_circular_menu_hdlr(point, MMI_PEN_EVENT_REPEAT);
    }
#endif /* ENABLE_CIRCULAR_3D_MENU */    
    else if (g_pen_to_control == DM_HORIZONTAL_TAB_BAR)
    {
        wgui_general_pen_horizontal_tab_bar_hdlr(point, MMI_PEN_EVENT_REPEAT);
    }
    else if (g_pen_to_control == DM_MULTILINE_INPUTBOX1)
    {
        gui_multi_line_input_box_translate_pen_event(
            &MMI_multiline_inputbox,
            MMI_PEN_EVENT_REPEAT,
            point.x,
            point.y,
            &multi_line_input_box_event);
    }
#ifdef UI_EMS_SUPPORT
    else if (g_pen_to_control == DM_EMS_INPUTBOX1)
    {
        gui_EMS_input_box_translate_pen_event(
            &MMI_EMS_inputbox,
            MMI_PEN_EVENT_REPEAT,
            point.x,
            point.y,
            &EMS_input_box_event);
    }
#endif /* UI_EMS_SUPPORT */
    else if (g_pen_to_control == DM_DIALER_INPUT_BOX1)
    {
        /* CURRENTLY DO NOTHING */
    }
    else if (g_pen_to_control == DM_IMAGE)
    {
        wgui_execute_dm_image_pen_handler(g_pen_to_control_index, MMI_PEN_EVENT_REPEAT, point);
    }
    else if (g_pen_to_control == DM_BUTTON)
    {
        gui_icontext_button_translate_pen_event(
            dm_get_button(g_pen_to_control_index),
            MMI_PEN_EVENT_REPEAT,
            point.x,
            point.y,
            &button_event);
        if (button_event == GUI_BUTTON_PEN_REPEAT)
        {
            dm_execute_button_handler(g_pen_to_control_index, KEY_EVENT_REPEAT);
        }
    }
    else if (g_pen_to_control == DM_CATEGORY_CONTROLLED_AREA)
    {
        wgui_execute_dm_category_control_area_pen_handler(MMI_PEN_EVENT_REPEAT, point);
    }
    else if (g_pen_to_control == DM_CATEGORY_CONTROLLED_AREA2)
    {
        wgui_execute_dm_category_control_area2_pen_handler(MMI_PEN_EVENT_REPEAT, point);
    }
    else if (g_pen_to_control == DM_CALENDAR)
    {
        wgui_calendar_translate_pen_event(MMI_PEN_EVENT_REPEAT, point.x, point.y);
    }
    else if (g_pen_to_control == DM_PANEL)
    {
        gui_panel_translate_pen_event(
            dm_get_panel(g_pen_to_control_index), 
            MMI_PEN_EVENT_REPEAT, 
            point.x, 
            point.y);
    }        
}


/*****************************************************************************
 * FUNCTION
 *  wgui_general_pen_list_menu_hdlr
 * DESCRIPTION
 *  General list menu event handler.
 * PARAMETERS
 *  point           [IN]        Pen point
 *  pen_event       [IN]        Pen event type
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_general_pen_list_menu_hdlr(mmi_pen_point_struct point, mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_list_pen_enum menu_event;
    BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = gui_fixed_list_menu_translate_pen_event(&MMI_fixed_list_menu, pen_event, point.x, point.y, &menu_event);

    if (!ret)
    {
        return MMI_FALSE;
    }
    if (menu_event == GUI_LIST_PEN_HIGHLIGHT_CHANGED)
    {
        wgui_pen_highlight_item_changed = MMI_TRUE;
    }

    if (menu_event == GUI_LIST_PEN_HIGHLIGHT_CHANGED ||
        menu_event == GUI_LIST_PEN_NEED_REDRAW || menu_event == GUI_LIST_PEN_ITEM_SELECTED)
    {
    #ifdef __MMI_INTERACTIVE_PROFILNG__
        mmi_frm_profiling_delay_start_timer(MMI_FRM_PROFILING_DELAY_LIST_HIGHLIGHT);
    #endif

        MMI_fixed_list_menu.pen_redraw_menu_function();
        
    #ifdef __MMI_INTERACTIVE_PROFILNG__
        mmi_frm_profiling_delay_perform(MMI_FRM_PROFILING_DELAY_LIST_HIGHLIGHT);
    #endif
    }
    if (menu_event == GUI_LIST_PEN_ITEM_SELECTED)
    {
#ifdef __MMI_FTE_SUPPORT__
        if (MMI_fixed_list_menu.tap_callback_funtion == NULL)
        {
            wgui_pen_execute_LSK_handler(KEY_EVENT_UP);
        }
        else
        {
            if (!wgui_pen_highlight_item_changed)
            {
                MMI_fixed_list_menu.tap_callback_funtion(ENUM_TAP_ON_HIGHLIGHTED_ITEM, MMI_fixed_list_menu.highlighted_item);
            }
            else
            {
                MMI_fixed_list_menu.tap_callback_funtion(ENUM_TAP_ON_NONHIGHLIGHTED_ITEM, MMI_fixed_list_menu.highlighted_item);
            }
        }
#else /* __MMI_FTE_SUPPORT__ */
        if (MMI_fixed_list_menu.pen_event_current_selected_callback_function != NULL)
        {
            MMI_fixed_list_menu.pen_event_current_selected_callback_function();
        }        
        else if (MMI_fixed_list_menu.tap_callback_funtion == NULL)
        {
            wgui_pen_execute_LSK_handler(KEY_EVENT_UP);
        }
        else
        {
            if (!wgui_pen_highlight_item_changed)
            {
                MMI_fixed_list_menu.tap_callback_funtion(ENUM_TAP_ON_HIGHLIGHTED_ITEM, MMI_fixed_list_menu.highlighted_item);
            }
            else
            {
                MMI_fixed_list_menu.tap_callback_funtion(ENUM_TAP_ON_NONHIGHLIGHTED_ITEM, MMI_fixed_list_menu.highlighted_item);
            }
        }
#endif /* __MMI_FTE_SUPPORT__ */
    }
#ifdef __MMI_UI_TWO_LINE_MENUITEM_STYLES__
    if (menu_event == GUI_LIST_PEN_TWO_LINE_NEXT)
    {
        ExecuteCurrKeyHandler(KEY_RIGHT_ARROW,KEY_EVENT_DOWN);
    }
    else if (menu_event == GUI_LIST_PEN_TWO_LINE_PREVIOUS)
    {
        ExecuteCurrKeyHandler(KEY_LEFT_ARROW,KEY_EVENT_DOWN);
    }
#endif /* __MMI_UI_TWO_LINE_MENUITEM_STYLES__ */
    /*if (menu_event == GUI_LIST_PEN_CASCADING_OTHER && 
        g_dm_data.s32CatId == MMI_CATEGORY_CASCADING_MENU_ID)
    {
        CloseCascadingMenu();
    }*/
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_general_pen_inline_hdlr
 * DESCRIPTION
 *  General inline list event handler.
 * PARAMETERS
 *  point           [IN]        Pen point
 *  pen_event       [IN]        Pen event type
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_general_pen_inline_hdlr(mmi_pen_point_struct point, mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_inline_pen_enum inline_event;
    BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = gui_inline_translate_pen_event(&MMI_fixed_list_menu, pen_event, point.x, point.y, &inline_event);

    if (!ret)
    {
        return MMI_FALSE;
    }

    if (inline_event == GUI_INLINE_PEN_NEED_REDRAW)
    {
        MMI_fixed_list_menu.pen_redraw_menu_function();
    }
    else if (inline_event == GUI_INLINE_PEN_ITEM_SELECTED)
    {
	if (MMI_fixed_list_menu.tap_callback_funtion == NULL)
        {
            wgui_pen_execute_LSK_handler(KEY_EVENT_UP);
        }
        else
        {
            MMI_fixed_list_menu.tap_callback_funtion(ENUM_TAP_ON_HIGHLIGHTED_ITEM, MMI_fixed_list_menu.highlighted_item);
        }
    }
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  wgui_general_pen_dynamic_list_menu_hdlr
 * DESCRIPTION
 *  General dynamic list menu event handler.
 * PARAMETERS
 *  point           [IN]        Pen point
 *  pen_event       [IN]        Pen event type
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_general_pen_dynamic_list_menu_hdlr(mmi_pen_point_struct point, mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_list_pen_enum menu_event;
    BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = gui_dynamic_list_menu_translate_pen_event(&MMI_fixed_list_menu, pen_event, point.x, point.y, &menu_event);

    if (!ret)
    {
        return MMI_FALSE;
    }

    if (menu_event == GUI_LIST_PEN_HIGHLIGHT_CHANGED ||
        menu_event == GUI_LIST_PEN_NEED_REDRAW || menu_event == GUI_LIST_PEN_ITEM_SELECTED)
    {
        MMI_fixed_list_menu.pen_redraw_menu_function();
    }
    if (menu_event == GUI_LIST_PEN_ITEM_SELECTED)
    {
        if (MMI_fixed_list_menu.pen_event_current_selected_callback_function != NULL)
        {
            MMI_fixed_list_menu.pen_event_current_selected_callback_function();
        }
        else
        {
            wgui_pen_execute_LSK_handler(KEY_EVENT_UP);
        }
    }
#ifdef __MMI_UI_TWO_LINE_MENUITEM_STYLES__
    if (menu_event == GUI_LIST_PEN_TWO_LINE_NEXT)
    {
        ExecuteCurrKeyHandler(KEY_RIGHT_ARROW,KEY_EVENT_DOWN);
    }
    else if (menu_event == GUI_LIST_PEN_TWO_LINE_PREVIOUS)
    {
        ExecuteCurrKeyHandler(KEY_LEFT_ARROW,KEY_EVENT_DOWN);
    }
#endif /* __MMI_UI_TWO_LINE_MENUITEM_STYLES__ */
    return MMI_TRUE;
}


#ifdef  __MMI_SUPPORT_DYNAMIC_MATRIX_MENU__
/*****************************************************************************
 * FUNCTION
 *  wgui_general_pen_dynamic_matrix_menu_hdlr
 * DESCRIPTION
 *  General dynamic matrix menu event handler.
 * PARAMETERS
 *  point           [IN]        Pen point
 *  pen_event       [IN]        Pen event type
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_general_pen_dynamic_matrix_menu_hdlr(mmi_pen_point_struct point, mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_matrix_pen_enum menu_event;
    BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = gui_dynamic_matrix_menu_translate_pen_event(&MMI_fixed_matrix_menu, pen_event, point.x, point.y, &menu_event);

    if (!ret)
    {
        return MMI_FALSE;
    }

    if (menu_event == GUI_LIST_PEN_HIGHLIGHT_CHANGED)
    {
        wgui_pen_highlight_item_changed = MMI_TRUE;
    }

    if (menu_event == GUI_MATRIX_PEN_HIGHLIGHT_CHANGED ||
        menu_event == GUI_MATRIX_PEN_NEED_REDRAW || menu_event == GUI_MATRIX_PEN_ITEM_SELECTED)
    {
    #ifdef __MMI_INTERACTIVE_PROFILNG__
        mmi_frm_profiling_delay_start_timer(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
    #endif
    
        gui_lock_double_buffer();
        show_dynamic_matrix();
        gui_unlock_double_buffer();
        gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
        
    #ifdef __MMI_INTERACTIVE_PROFILNG__
        mmi_frm_profiling_delay_perform(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
    #endif
    }
	if (menu_event == GUI_MATRIX_PEN_ITEM_SELECTED && pen_event == MMI_PEN_EVENT_UP)
	{
#ifdef __MMI_FTE_SUPPORT__
    if (MMI_fixed_matrix_menu.tap_callback_funtion == NULL)
    {
        wgui_pen_execute_LSK_handler(KEY_EVENT_UP);
    }
    else
    {
        if (!wgui_pen_highlight_item_changed)
        {
            MMI_fixed_matrix_menu.tap_callback_funtion(ENUM_TAP_ON_HIGHLIGHTED_ITEM, MMI_fixed_matrix_menu.highlighted_item);
        }
        else
    {
            MMI_fixed_matrix_menu.tap_callback_funtion(ENUM_TAP_ON_NONHIGHLIGHTED_ITEM, MMI_fixed_matrix_menu.highlighted_item);
        }
    }
#else /* __MMI_FTE_SUPPORT__ */
        if (MMI_fixed_matrix_menu.pen_event_current_selected_callback_function != NULL)
        {
            MMI_fixed_matrix_menu.pen_event_current_selected_callback_function();
        }
    else if (MMI_fixed_matrix_menu.tap_callback_funtion == NULL)
    {
        wgui_pen_execute_LSK_handler(KEY_EVENT_UP);
    }
    else
    {
        if (!wgui_pen_highlight_item_changed)
        {
            MMI_fixed_matrix_menu.tap_callback_funtion(ENUM_TAP_ON_HIGHLIGHTED_ITEM, MMI_fixed_matrix_menu.highlighted_item);
        }
        else
        {
            MMI_fixed_matrix_menu.tap_callback_funtion(ENUM_TAP_ON_NONHIGHLIGHTED_ITEM, MMI_fixed_matrix_menu.highlighted_item);
        }
    }
#endif /* __MMI_FTE_SUPPORT__ */   
	} 
    return MMI_TRUE;
}
#endif  // __MMI_SUPPORT_DYNAMIC_MATRIX_MENU__


/*****************************************************************************
 * FUNCTION
 *  wgui_general_pen_asyncdynamic_list_menu_hdlr
 * DESCRIPTION
 *  General asyncdynamic list menu event handler.
 * PARAMETERS
 *  point           [IN]        Pen point
 *  pen_event       [IN]        Pen event type
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_general_pen_asyncdynamic_list_menu_hdlr(mmi_pen_point_struct point, mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_list_pen_enum menu_event;
    BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = gui_asyncdynamic_list_menu_translate_pen_event(
            &MMI_fixed_list_menu,
            pen_event,
            point.x,
            point.y,
            &menu_event);

    if (!ret)
    {
        return MMI_FALSE;
    }

    if (menu_event == GUI_LIST_PEN_HIGHLIGHT_CHANGED ||
        menu_event == GUI_LIST_PEN_NEED_REDRAW || menu_event == GUI_LIST_PEN_ITEM_SELECTED)
    {
        MMI_fixed_list_menu.pen_redraw_menu_function();
    }
    if (menu_event == GUI_LIST_PEN_ITEM_SELECTED)
    {
        if (MMI_fixed_list_menu.pen_event_current_selected_callback_function != NULL)
        {
            MMI_fixed_list_menu.pen_event_current_selected_callback_function();
        }
        else
        {
            wgui_pen_execute_LSK_handler(KEY_EVENT_UP);
        }
    }
    return MMI_TRUE;
}


#ifdef  __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__
/*****************************************************************************
 * FUNCTION
 *  wgui_general_pen_asyncdynamic_matrix_menu_hdlr
 * DESCRIPTION
 *  General asyncdynamic matrix menu event handler.
 * PARAMETERS
 *  point           [IN]        Pen point
 *  pen_event       [IN]        Pen event type
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_general_pen_asyncdynamic_matrix_menu_hdlr(mmi_pen_point_struct point, mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_matrix_pen_enum menu_event;
    BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = gui_asyncdynamic_matrix_menu_translate_pen_event(&MMI_fixed_matrix_menu, pen_event, point.x, point.y, &menu_event);

    if (!ret)
    {
        return MMI_FALSE;
    }

    if (menu_event == GUI_MATRIX_PEN_HIGHLIGHT_CHANGED ||
        menu_event == GUI_MATRIX_PEN_NEED_REDRAW || menu_event == GUI_MATRIX_PEN_ITEM_SELECTED)
    {
    #ifdef __MMI_INTERACTIVE_PROFILNG__
        mmi_frm_profiling_delay_start_timer(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
    #endif
    
        gui_lock_double_buffer();
        show_asyncdynamic_matrix();
        gui_unlock_double_buffer();
        gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
        
    #ifdef __MMI_INTERACTIVE_PROFILNG__
        mmi_frm_profiling_delay_perform(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
    #endif
    }
    if (menu_event == GUI_MATRIX_PEN_ITEM_SELECTED)
    {
        if (MMI_fixed_matrix_menu.pen_event_current_selected_callback_function != NULL)
        {
            MMI_fixed_matrix_menu.pen_event_current_selected_callback_function();
        }
        else
        {
            wgui_pen_execute_LSK_handler(KEY_EVENT_UP);
        }
    }
    return MMI_TRUE;
}
#endif  /* __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__ */


/*****************************************************************************
 * FUNCTION
 *  wgui_general_pen_matrix_menu_hdlr
 * DESCRIPTION
 *  General matrix menu event handler.
 * PARAMETERS
 *  point           [IN]        Pen point
 *  pen_event       [IN]        Pen event type
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_general_pen_matrix_menu_hdlr(mmi_pen_point_struct point, mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_matrix_pen_enum menu_event;
    BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = gui_fixed_matrix_menu_translate_pen_event(&MMI_fixed_matrix_menu, pen_event, point.x, point.y, &menu_event);

    if (!ret)
    {
        return MMI_FALSE;
    }
    if (menu_event == GUI_LIST_PEN_HIGHLIGHT_CHANGED)
    {
        wgui_pen_highlight_item_changed = MMI_TRUE;
    }

    if (menu_event == GUI_MATRIX_PEN_HIGHLIGHT_CHANGED ||
        menu_event == GUI_MATRIX_PEN_NEED_REDRAW || menu_event == GUI_MATRIX_PEN_ITEM_SELECTED)
    {
    #ifdef __MMI_INTERACTIVE_PROFILNG__
        mmi_frm_profiling_delay_start_timer(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
    #endif
    
        gui_lock_double_buffer();
        show_fixed_matrix();
        gui_unlock_double_buffer();
        gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
        
    #ifdef __MMI_INTERACTIVE_PROFILNG__
        mmi_frm_profiling_delay_perform(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
    #endif
    }
    if (menu_event == GUI_MATRIX_PEN_ITEM_SELECTED && pen_event == MMI_PEN_EVENT_UP)
    {
#ifdef __MMI_FTE_SUPPORT__
        if (MMI_fixed_matrix_menu.tap_callback_funtion == NULL)
        {
            wgui_pen_execute_LSK_handler(KEY_EVENT_UP);
        }
        else
        {
            if (!wgui_pen_highlight_item_changed)
            {
                MMI_fixed_matrix_menu.tap_callback_funtion(ENUM_TAP_ON_HIGHLIGHTED_ITEM, MMI_fixed_matrix_menu.highlighted_item);
            }
            else
            {
                MMI_fixed_matrix_menu.tap_callback_funtion(ENUM_TAP_ON_NONHIGHLIGHTED_ITEM, MMI_fixed_matrix_menu.highlighted_item);
            }
        }
#else /* __MMI_FTE_SUPPORT__ */
        if (MMI_fixed_matrix_menu.pen_event_current_selected_callback_function != NULL)
        {
            MMI_fixed_matrix_menu.pen_event_current_selected_callback_function();
        }
        else if (MMI_fixed_matrix_menu.tap_callback_funtion == NULL)
        {
            wgui_pen_execute_LSK_handler(KEY_EVENT_UP);
        }
        else
        {
            if (!wgui_pen_highlight_item_changed)
            {
                MMI_fixed_matrix_menu.tap_callback_funtion(ENUM_TAP_ON_HIGHLIGHTED_ITEM, MMI_fixed_matrix_menu.highlighted_item);
            }
            else
            {
                MMI_fixed_matrix_menu.tap_callback_funtion(ENUM_TAP_ON_NONHIGHLIGHTED_ITEM, MMI_fixed_matrix_menu.highlighted_item);
            }
        }
#endif /* __MMI_FTE_SUPPORT__ */
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_general_pen_slide_control_hdlr
 * DESCRIPTION
 *  General slide control event handler.
 * PARAMETERS
 *  point           [IN]        Pen point
 *  pen_event       [IN]        Pen event type
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_general_pen_slide_control_hdlr(mmi_pen_point_struct point, mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_slide_control_pen_event_enum slide_event;
    gui_pen_event_param_struct param;
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = wgui_slide_control_translate_pen_event(
            MMI_current_slide_control,
            pen_event,
            point.x,
            point.y,
            &slide_event,
            &param);

    return ret;
}


#if ENABLE_CIRCULAR_3D_MENU

/*****************************************************************************
 * FUNCTION
 *  wgui_general_pen_3D_circular_menu_hdlr
 * DESCRIPTION
 *  General 3D circular menu event handler.
 * PARAMETERS
 *  point           [IN]        Pen point
 *  pen_event       [IN]        Pen event type
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_general_pen_3D_circular_menu_hdlr(mmi_pen_point_struct point, mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_3D_circular_menu_pen_enum circular_event;
    BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = gui_3D_circular_menu_translate_pen_event(&wgui_CM3D_menu, pen_event, point.x, point.y, &circular_event);

    if (!ret)
    {
        return MMI_FALSE;
    }

    if (circular_event == GUI_3D_CIRCULAR_MENU_PEN_GOTO_NEXT)
    {
        circular_3d_menu_next();
    }
    else if (circular_event == GUI_3D_CIRCULAR_MENU_PEN_GOTO_PREVIOUS)
    {
        circular_3d_menu_previous();
    }
    else if (circular_event == GUI_3D_CIRCULAR_MENU_PEN_ITEM_SELECTED)
    {
        wgui_pen_execute_LSK_handler(KEY_EVENT_UP);
    }
    return MMI_TRUE;
}

#endif /* ENABLE_CIRCULAR_3D_MENU */


/*****************************************************************************
 * FUNCTION
 *  wgui_general_pen_horizontal_tab_bar_hdlr
 * DESCRIPTION
 *  General horizontal rab bar event handler.
 * PARAMETERS
 *  point           [IN]        Pen point
 *  pen_event       [IN]        Pen event type
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_general_pen_horizontal_tab_bar_hdlr(mmi_pen_point_struct point, mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL)wgui_horizontal_tab_bar_translate_pen_event(pen_event, point.x, point.y);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_register_pen_up_handler
 * DESCRIPTION
 *  Register global Pen event handlers.
 * PARAMETERS
 *  pen_up_hdlr     [IN]        pen_move_hdlr, pen_abort_hdlr
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_register_pen_up_handler(mmi_pen_hdlr pen_up_hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pen_up_hdlr != NULL)
    {
        mmi_pen_register_up_handler(pen_up_hdlr);
    }
    else
    {
        MMI_ASSERT(pen_up_hdlr != NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_register_pen_down_handler
 * DESCRIPTION
 *  Register global Pen event handlers.
 * PARAMETERS
 *  pen_down_hdlr       [IN]        pen_up_hdlr, pen_move_hdlr, pen_abort_hdlr
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_register_pen_down_handler(mmi_pen_hdlr pen_down_hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pen_down_hdlr != NULL)
    {
        mmi_pen_register_down_handler(pen_down_hdlr);
    }
    else
    {
        MMI_ASSERT(pen_down_hdlr != NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_register_pen_move_handler
 * DESCRIPTION
 *  Register global Pen event handlers.
 * PARAMETERS
 *  pen_move_hdlr       [IN]        pen_abort_hdlr
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_register_pen_move_handler(mmi_pen_hdlr pen_move_hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pen_move_hdlr != NULL)
    {
        mmi_pen_register_move_handler(pen_move_hdlr);
    }
    else
    {
        MMI_ASSERT(pen_move_hdlr != NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_register_pen_abort_handler
 * DESCRIPTION
 *  Register global Pen event handlers.
 * PARAMETERS
 *  pen_abort_hdlr      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_register_pen_abort_handler(mmi_pen_hdlr pen_abort_hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pen_abort_hdlr != NULL)
    {
        mmi_pen_register_abort_handler(pen_abort_hdlr);
    }
    else
    {
        MMI_ASSERT(pen_abort_hdlr != NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_register_pen_repeat_handler
 * DESCRIPTION
 *  Register global Pen event handlers.
 * PARAMETERS
 *  pen_repeat_hdlr     [IN]        
 *  pen_down_hdlr, pen_up_hdlr, pen_move_hdlr, pen_abort_hdlr(?)
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_register_pen_repeat_handler(mmi_pen_hdlr pen_repeat_hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pen_repeat_hdlr != NULL)
    {
        mmi_pen_register_repeat_handler(pen_repeat_hdlr);
    }
    else
    {
        MMI_ASSERT(pen_repeat_hdlr != NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_register_pen_long_tap_handler
 * DESCRIPTION
 *  Register global Pen event handlers.
 * PARAMETERS
 *  pen_long_tap_hdlr       [IN]        
 *  pen_down_hdlr, pen_up_hdlr, pen_move_hdlr, pen_abort_hdlr(?)
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_register_pen_long_tap_handler(mmi_pen_hdlr pen_long_tap_hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pen_long_tap_hdlr != NULL)
    {
        mmi_pen_register_long_tap_handler(pen_long_tap_hdlr);
    }
    else
    {
        MMI_ASSERT(pen_long_tap_hdlr != NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_register_general_pen_handler
 * DESCRIPTION
 *  Register general global Pen event handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_register_general_pen_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_register_up_handler(wgui_general_pen_up_hdlr);
    mmi_pen_register_down_handler(wgui_general_pen_down_hdlr);
    mmi_pen_register_move_handler(wgui_general_pen_move_hdlr);
    mmi_pen_register_abort_handler(wgui_general_pen_abort_hdlr);
    mmi_pen_register_repeat_handler(wgui_general_pen_repeat_hdlr);
    mmi_pen_register_long_tap_handler(wgui_general_pen_long_tap_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_empty_pen_handler
 * DESCRIPTION
 *  empty Pen event handlers.
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_empty_pen_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(point);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clear_pen_handlers
 * DESCRIPTION
 *  Clear general global Pen event handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clear_pen_handlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_register_up_handler(wgui_empty_pen_handler);
    mmi_pen_register_down_handler(wgui_empty_pen_handler);
    mmi_pen_register_move_handler(wgui_empty_pen_handler);
    mmi_pen_register_abort_handler(wgui_empty_pen_handler);
    mmi_pen_register_repeat_handler(wgui_empty_pen_handler);
    mmi_pen_register_long_tap_handler(wgui_empty_pen_handler);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_null_pen_hdlr
 * DESCRIPTION
 *  dummy pen event handler.
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_null_pen_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(point);
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_reset_category_screen_control_pen_handler
 * DESCRIPTION
 *  Reset pen handler functions for category screen contrl area.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_reset_category_screen_control_pen_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (idx = 0; idx < MMI_PEN_EVENT_TYPE_MAX; idx++)
    {
        wgui_category_control_area_pen_handlers[idx] = wgui_null_pen_hdlr;
        wgui_category_control_area2_pen_handlers[idx] = wgui_null_pen_hdlr;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_register_category_screen_control_area_pen_handlers
 * DESCRIPTION
 *  Register pen handler functions for category screen contrl area.
 * PARAMETERS
 *  pen_fp          [IN]        Pen handler function
 *  event_type      [IN]        Pen event type
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_register_category_screen_control_area_pen_handlers(mmi_pen_handler pen_fp, mmi_pen_event_type_enum event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* event_type should be one of the events for touch panel */
    MMI_ASSERT( event_type < MMI_PEN_EVENT_TYPE_MAX);
    wgui_category_control_area_pen_handlers[event_type] = pen_fp;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_register_category_screen_control_area2_pen_handlers
 * DESCRIPTION
 *  Register pen handler functions for category screen contrl area2.
 * PARAMETERS
 *  pen_fp          [IN]        Pen handler function
 *  event_type      [IN]        Pen event type
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_register_category_screen_control_area2_pen_handlers(
        mmi_pen_handler pen_fp,
        mmi_pen_event_type_enum event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* event_type should be one of the events for touch panel */
    MMI_ASSERT( event_type < MMI_PEN_EVENT_TYPE_MAX );
    wgui_category_control_area2_pen_handlers[event_type] = pen_fp;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_reset_image_control_pen_handler
 * DESCRIPTION
 *  reset pen event handler function for image controls
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_reset_image_control_pen_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 img_idx = 0, event_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (img_idx = 0; img_idx < DM_MAX_IMAGES; img_idx++)
        for (event_type = 0; event_type < MMI_PEN_EVENT_TYPE_MAX; event_type++)
        {
            wgui_image_pen_handlers[img_idx][event_type] = wgui_null_pen_hdlr;
        }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_register_image_control_pen_handlers
 * DESCRIPTION
 *  register pen event handler function for image controls
 * PARAMETERS
 *  index           [IN]        Image index
 *  pen_fp          [IN]        Pen handler function
 *  event_type      [IN]        Pen event type
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_register_image_control_pen_handlers(S32 index, mmi_pen_handler pen_fp, mmi_pen_event_type_enum event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* index should not bigger than max number of images supported by draw manager */
    MMI_ASSERT(index < DM_MAX_IMAGES);

    /* event_type should be one of the events for touch panel */
    MMI_ASSERT(event_type < MMI_PEN_EVENT_TYPE_MAX);
    wgui_image_pen_handlers[index][event_type] = pen_fp;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_test_object_position
 * DESCRIPTION
 *  test if the pen inside one object.
 * PARAMETERS
 *  pos     [IN]        Pen position
 *  obj     [IN]        Position info. of one object.
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_test_object_position(mmi_pen_point_struct pos, wgui_component_info_struct obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 pos_x = pos.x, pos_y = pos.y;
    S32 obj_x1 = 0, obj_y1 = 0, obj_x2 = 0, obj_y2 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj_x1 = obj.pos_x;
    obj_x2 = obj.pos_x + obj.width - 1;//052206 NITZ category Calvin
    obj_y1 = obj.pos_y;
    obj_y2 = obj.pos_y + obj.height - 1;

    if (pos_x >= obj_x1 && pos_x <= obj_x2 && pos_y >= obj_y1 && pos_y <= obj_y2)       /* within object */
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
 *  wgui_test_image_object_position
 * DESCRIPTION
 *  test if the pen inside one image object.
 * PARAMETERS
 *  pos         [IN]        Pen position
 *  pos_x       [IN]        X-coordnate of the iamge
 *  pos_y       [IN]        Y-coordnate of the iamge
 *  img_ptr     [IN]        Iamge
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_test_image_object_position(mmi_pen_point_struct pos, S32 pos_x, S32 pos_y, PU8 img_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 img_width = 0, img_height = 0;
    wgui_component_info_struct obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_image_get_dimension(img_ptr, &img_width, &img_height);
    obj.pos_x = pos_x;
    obj.pos_y = pos_y;
    obj.width = img_width;
    obj.height = img_height;

    return wgui_test_object_position(pos, obj);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_test_lsk_position
 * DESCRIPTION
 *  test if the pen inside LSK.
 * PARAMETERS
 *  pos     [IN]        Pen position
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_test_lsk_position(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 pos_x = pos.x, pos_y = pos.y;
    S32 obj_x1 = 0, obj_y1 = 0, obj_x2 = 0, obj_y2 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_FTE_SUPPORT__
    obj_x1 = MMI_softkeys[MMI_LEFT_SOFTKEY].x + MMI_softkeys[MMI_LEFT_SOFTKEY].text_x;
    obj_x2 = obj_x1 + MMI_softkeys[MMI_LEFT_SOFTKEY].text_width;
    if (obj_x2 > (MMI_softkeys[MMI_LEFT_SOFTKEY].x + MMI_softkeys[MMI_LEFT_SOFTKEY].width - 1))
    {
        obj_x2 = MMI_softkeys[MMI_LEFT_SOFTKEY].x + MMI_softkeys[MMI_LEFT_SOFTKEY].width - 1;
    }
    obj_y1 = MMI_softkeys[MMI_LEFT_SOFTKEY].y + MMI_softkeys[MMI_LEFT_SOFTKEY].text_y;
    obj_y2 = obj_y1 + MMI_softkeys[MMI_LEFT_SOFTKEY].text_height;
#else
    obj_x1 = MMI_softkeys[MMI_LEFT_SOFTKEY].x;
    obj_x2 = obj_x1 + MMI_softkeys[MMI_LEFT_SOFTKEY].width - 1;
    obj_y1 = MMI_softkeys[MMI_LEFT_SOFTKEY].y;
    obj_y2 = obj_y1 + MMI_softkeys[MMI_LEFT_SOFTKEY].height - 1;
#endif

    if (pos_x >= obj_x1 && pos_x <= obj_x2 && pos_y >= obj_y1 && pos_y <= obj_y2)       /* within object */
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
 *  wgui_test_rsk_position
 * DESCRIPTION
 *  test if the pen inside RSK.
 * PARAMETERS
 *  pos     [IN]        Pen position
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_test_rsk_position(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 pos_x = pos.x, pos_y = pos.y;
    S32 obj_x1 = 0, obj_y1 = 0, obj_x2 = 0, obj_y2 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_FTE_SUPPORT__
    obj_x1 = MMI_softkeys[MMI_RIGHT_SOFTKEY].x + MMI_softkeys[MMI_RIGHT_SOFTKEY].text_x;
    obj_x2 = obj_x1 + MMI_softkeys[MMI_RIGHT_SOFTKEY].text_width;
    if (obj_x2 > (MMI_softkeys[MMI_RIGHT_SOFTKEY].x + MMI_softkeys[MMI_RIGHT_SOFTKEY].width - 1))
    {
        obj_x2 = MMI_softkeys[MMI_RIGHT_SOFTKEY].x + MMI_softkeys[MMI_RIGHT_SOFTKEY].width - 1;
    }
    obj_y1 = MMI_softkeys[MMI_RIGHT_SOFTKEY].y + MMI_softkeys[MMI_RIGHT_SOFTKEY].text_y;
    obj_y2 = obj_y1 + MMI_softkeys[MMI_RIGHT_SOFTKEY].text_height;
#else
    obj_x1 = MMI_softkeys[MMI_RIGHT_SOFTKEY].x;
    obj_x2 = obj_x1 + MMI_softkeys[MMI_RIGHT_SOFTKEY].width - 1;
    obj_y1 = MMI_softkeys[MMI_RIGHT_SOFTKEY].y;
    obj_y2 = obj_y1 + MMI_softkeys[MMI_RIGHT_SOFTKEY].height - 1;
#endif

    if (pos_x >= obj_x1 && pos_x <= obj_x2 && pos_y >= obj_y1 && pos_y <= obj_y2)       /* within object */
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
 *  wgui_register_list_item_selected_callback
 * DESCRIPTION
 *  register the callback function when a menuitem is selected.(for one specific menuitem)
 * PARAMETERS
 *  pen_event_selected_callback_function        [IN]        Callback function
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_register_list_item_selected_callback(void (*pen_event_selected_callback_function) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.pen_event_current_selected_callback_function = pen_event_selected_callback_function;
    MMI_fixed_list_menu.pen_event_default_selected_callback_function = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_register_list_item_selected_callback_all
 * DESCRIPTION
 *  register the callback function when a menuitem is selected.(apply to all menuitem)
 * PARAMETERS
 *  pen_event_selected_callback_function        [IN]        Callback function
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_register_list_item_selected_callback_all(void (*pen_event_selected_callback_function) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.pen_event_current_selected_callback_function = pen_event_selected_callback_function;
    MMI_fixed_list_menu.pen_event_default_selected_callback_function = pen_event_selected_callback_function;
}



/*****************************************************************************
 * FUNCTION
 *  Wgui_register_list_tap_callback
 * DESCRIPTION
 *  register the callback function for a intuitive command
 * PARAMETERS
 *  pen_event_selected_callback_function        [IN]        Callback function
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_register_list_tap_callback(void (*tap_callback_funtion)(mmi_tap_type_enum tap_type,S32 index))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.tap_callback_funtion = tap_callback_funtion;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_reset_list_item_selected_callback
 * DESCRIPTION
 *  reset the callback function when a menuitem is selected.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_reset_list_item_selected_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.pen_event_current_selected_callback_function = NULL;
    MMI_fixed_list_menu.pen_event_default_selected_callback_function = NULL;
    MMI_fixed_list_menu.tap_callback_funtion = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_reset_matrix_item_selected_callback
 * DESCRIPTION
 *  reset the callback function when a menuitem is selected.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_reset_matrix_item_selected_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_matrix_menu.pen_event_current_selected_callback_function = NULL;
    MMI_fixed_matrix_menu.pen_event_default_selected_callback_function = NULL;
    MMI_fixed_matrix_menu.tap_callback_funtion = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_register_matrix_item_selected_callback
 * DESCRIPTION
 *  register the callback function when a menuitem is selected.(for one specific menuitem)
 * PARAMETERS
 *  pen_event_selected_callback_function        [IN]        Callback function
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_register_matrix_item_selected_callback(void (*pen_event_selected_callback_function) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_matrix_menu.pen_event_current_selected_callback_function = pen_event_selected_callback_function;
    MMI_fixed_matrix_menu.pen_event_default_selected_callback_function = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_register_matrix_item_selected_callback_all
 * DESCRIPTION
 *  register the callback function when a menuitem is selected.(apply to all menuitem)
 * PARAMETERS
 *  pen_event_selected_callback_function        [IN]        Callback function
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_register_matrix_item_selected_callback_all(void (*pen_event_selected_callback_function) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_matrix_menu.pen_event_current_selected_callback_function = pen_event_selected_callback_function;
    MMI_fixed_matrix_menu.pen_event_default_selected_callback_function = pen_event_selected_callback_function;
}






/*****************************************************************************
 * FUNCTION
 *  Wgui_register_matrix_tap_callback
 * DESCRIPTION
 *  register the callback function for a intuitive command
 * PARAMETERS
 *  pen_event_selected_callback_function        [IN]        Callback function
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_register_matrix_tap_callback(void (*tap_callback_funtion)(mmi_tap_type_enum tap_type,S32 index))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_matrix_menu.tap_callback_funtion = tap_callback_funtion;
}

#ifdef __J2ME__


/*****************************************************************************
 * FUNCTION
 *  j2me_get_category_index_by_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pen_event       [IN]        
 *  point           [IN]        
 *  is_selected     [?]         
 * RETURNS
 *  
 *****************************************************************************/
int j2me_get_category_index_by_position(int pen_event, mmi_pen_point_struct point, kal_bool *is_selected)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_list_pen_enum menu_event;
    static BOOL ret;
    gdi_handle org_layer_handle;
    extern gdi_handle jui_layer_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_get_alpha_blending_source_layer(&org_layer_handle);

    if (jui_layer_handle != GDI_LAYER_EMPTY_HANDLE) //
    {
        gdi_set_alpha_blending_source_layer(jui_layer_handle);
    }
    if (pen_event == MMI_PEN_EVENT_DOWN)
    {
        ret = gui_fixed_list_menu_translate_pen_event(&MMI_fixed_list_menu, pen_event, point.x, point.y, &menu_event);
    }
    else
    {
        if (ret)
        {
            ret = gui_fixed_list_menu_translate_pen_event(&MMI_fixed_list_menu, pen_event, point.x, point.y, &menu_event);
        }
    }

    gdi_set_alpha_blending_source_layer(org_layer_handle);

    if (!ret)   /* Not in list menu */
    {
        return -1;
    }

    if (menu_event == GUI_LIST_PEN_HIGHLIGHT_CHANGED ||
        menu_event == GUI_LIST_PEN_NEED_REDRAW || menu_event == GUI_LIST_PEN_ITEM_SELECTED)
    {
        gui_lock_double_buffer();
        gdi_get_alpha_blending_source_layer(&org_layer_handle);
        if (jui_layer_handle != GDI_LAYER_EMPTY_HANDLE)
        {
            gdi_set_alpha_blending_source_layer(jui_layer_handle);
        }
        redraw_fixed_list();

        gdi_set_alpha_blending_source_layer(org_layer_handle);
        gui_unlock_double_buffer();
        jui_widget_refresh_lcd(0, 0, UI_device_width - 1, UI_device_height - 1);
    }
    if (menu_event == GUI_LIST_PEN_ITEM_SELECTED)
    {
        *is_selected = KAL_TRUE;
    }
    else
    {
        *is_selected = KAL_FALSE;
    }
    return MMI_fixed_list_menu.highlighted_item;
}

#endif /* __J2ME__ */ 


/*****************************************************************************
 * FUNCTION
 *  wgui_pen_register_pre_hdlr
 * DESCRIPTION
 *  Registers the pre pen handler which is called before all pen events.
 * PARAMETERS
 *  pen_pre_hdlr       [IN] pre pen handler
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_pen_register_pre_hdlr(wgui_pen_pre_hdlr_funcptr pen_pre_hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_pen_pre_hdlr_callback = pen_pre_hdlr;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_pen_reset_pre_hdlr
 * DESCRIPTION
 *  Clear pre pen handler and save the pre pen handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_pen_reset_pre_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_pen_pre_hdlr_callback_backup = wgui_pen_pre_hdlr_callback;
    wgui_pen_pre_hdlr_callback = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_pen_restore_pre_hdlr
 * DESCRIPTION
 *  Restore pre pen handler .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_pen_restore_pre_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_pen_pre_hdlr_callback = wgui_pen_pre_hdlr_callback_backup;
}

#else /* defined(__MMI_TOUCH_SCREEN__) */ 

#include "mmi_frm_input_gprot.h"
#include "wgui_touch_screen.h"

/* here a dummy function just for removing compile warning */
void wgui_touch_screen_dummy(void)
{
}
/* here an empty function for SNS app which is released as library */
void wgui_register_list_item_selected_callback_all(void (*pen_event_selected_callback_function) (void))
{
}
void wgui_register_category_screen_control_area_pen_handlers(mmi_pen_handler pen_fp, mmi_pen_event_type_enum event_type)
{
}

#endif /* defined(__MMI_TOUCH_SCREEN__) */ 


