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
 *   wgui_categories_op.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *  Operator related categories for common utilities
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#include "MMI_features.h"
#if defined(__MMI_TOUCH_SCREEN__)
#include "Wgui_touch_screen.h"
#endif

#include "wgui_categories_op.h"
#include "gui_typedef.h"
#include "wgui.h"
#include "wgui_categories_util.h"
#include "MMIDataType.h"
#include "gui_switch.h"
#include "gui.h"
#include "lcd_sw_inc.h"
#include "Gui_Setting.h"
#include "gui_themes.h"
#include "CustThemesRes.h"
#include "gdi_include.h"
#include "gdi_const.h"
#include "PixcomFontEngine.h"
#include "wgui_draw_manager.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "lcd_sw_rnd.h"
#include "operator_gui.h"
#include "gdi_datatype.h"
#include "kal_general_types.h"
#include "mmi_frm_input_gprot.h"
#include "gui_data_types.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_enum.h"
#include "gdi_lcd_config.h"
#include "mmi_frm_mem_gprot.h"
#ifdef __MMI_OP02_LEMEI__
#include "mmi_rp_app_lemei_def.h"
#endif

#if defined(__MMI_OP01_DCD__)
#include "dcdagentinterface.h"
#include "ui_dcd_porting.h"
static U8* g_cat432_dcd_mem = NULL;
static GDI_HANDLE *g_cat432_dcd_layer = GDI_NULL_HANDLE;
static GDI_HANDLE mmi_cat432_title_handle = GDI_NULL_HANDLE;
static GDI_HANDLE mmi_cat432_bottom_handle = GDI_NULL_HANDLE;

#if defined(__MMI_TOUCH_SCREEN__)
static cat432_pen_handler mmi_cat432_pen_event_handler = NULL;
/*****************************************************************************
 * FUNCTION
 *  Cat432ControlAreaPenDownHandler
 * DESCRIPTION
 *  Pen down events handler function for category432 control area.
 * PARAMETERS
 *  point                       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL Cat432ControlAreaPenDownHandler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_cat432_pen_event_handler != NULL)
    {
        result = mmi_cat432_pen_event_handler(point, MMI_PEN_EVENT_DOWN);
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  Cat432ControlAreaPenUpHandler
 * DESCRIPTION
 *  Pen up events handler function for category432 control area.
 * PARAMETERS
 *  point                       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL Cat432ControlAreaPenUpHandler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (mmi_cat432_pen_event_handler != NULL)
    {
        result = mmi_cat432_pen_event_handler(point, MMI_PEN_EVENT_UP);
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  Cat432ControlAreaPenLongTapHandler
 * DESCRIPTION
 *  Pen long-tap events handler function for category432 control area.
 * PARAMETERS
 *  point                       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL Cat432ControlAreaPenLongTapHandler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_cat432_pen_event_handler != NULL)
    {
        result = mmi_cat432_pen_event_handler(point, MMI_PEN_EVENT_LONG_TAP);
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  Cat432ControlAreaPenRepeatHandler
 * DESCRIPTION
 *  Pen repeat events handler function for category432 control area.
 * PARAMETERS
 *  point                       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL Cat432ControlAreaPenRepeatHandler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_cat432_pen_event_handler != NULL)
    {
        result = mmi_cat432_pen_event_handler(point, MMI_PEN_EVENT_REPEAT);
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  Cat432ControlAreaPenMoveHandler
 * DESCRIPTION
 *  Pen move events handler function for category432 control area.
 * PARAMETERS
 *  point                       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL Cat432ControlAreaPenMoveHandler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_cat432_pen_event_handler != NULL)
    {
        result = mmi_cat432_pen_event_handler(point, MMI_PEN_EVENT_MOVE);
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  Cat432ControlAreaPenAbortHandler
 * DESCRIPTION
 *  Pen abort events handler function for category432 control area.
 * PARAMETERS
 *  point                       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL Cat432ControlAreaPenAbortHandler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_cat432_pen_event_handler != NULL)
    {
        result = mmi_cat432_pen_event_handler(point, MMI_PEN_EVENT_ABORT);
    }
    return result;
}
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 


/*****************************************************************************
 * FUNCTION
 *  ShowCategory432Screen
 * DESCRIPTION
 *  This category scrren is used for DCD story viewer.
 * PARAMETERS
 *  title                   [IN]        String ID for the title of the screen
 *  title_icon1             [IN]        Image ID for the icon1 displayed with the title
 *  title_icon2             [IN]        Image ID for the icon2 displayed with the title
 *  left_softkey            [IN]        String ID for the left softkey label
 *  left_softkey_icon       [IN]        Image ID for the left softkey icon
 *  right_softkey           [IN]        String ID for the right softkey label
 *  right_softkey_icon      [IN]        Image ID for the right softkey icon
 *  pen_handler             [IN]        Touch screen pen event handler
 *  agent                   [IN]        DCD story viewer agent
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory432Screen(
        UI_string_type title,
        PU8 title_icon,
        UI_string_type left_softkey,
        PU8 left_softkey_icon,
        UI_string_type right_softkey,
        PU8 right_softkey_icon,
        cat432_pen_handler pen_handler,
        void* agent,
        UI_buffer_type history_buffer)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* lock GDI frame buffer */
    gdi_layer_lock_frame_buffer();

    /* do not show shortcut */
    wgui_title_set_menu_shortcut_number(-1);

    /* change softkey label & icon, clear softkey handle function */
    dm_add_softkey(left_softkey, left_softkey_icon, right_softkey, right_softkey_icon);

    /* set title & title icon */
    dm_add_title(title, title_icon);

    /* set flags */
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND | DM_NO_BLT;

    /* un-lock GDI frame buffer */
    gdi_layer_unlock_frame_buffer();

    /* set exit category screen function */
    ExitCategoryFunction = ExitCategory432Screen;

    /* register control area callback */
    dm_register_category_controlled_callback(NULL);

    /* set draw manager attributes */
    dm_setup_category_functions(dm_redraw_category_screen, dummy_get_history, dummy_get_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY432_ID;
    dm_setup_data(&dm_data);

    /* register pen event handler */
#ifdef __MMI_TOUCH_SCREEN__
    mmi_cat432_pen_event_handler = pen_handler,
    wgui_register_category_screen_control_area_pen_handlers(
            Cat432ControlAreaPenDownHandler,
            MMI_PEN_EVENT_DOWN);
    wgui_register_category_screen_control_area_pen_handlers(
            Cat432ControlAreaPenUpHandler,
            MMI_PEN_EVENT_UP);
    wgui_register_category_screen_control_area_pen_handlers(
            Cat432ControlAreaPenLongTapHandler,
            MMI_PEN_EVENT_LONG_TAP);
    wgui_register_category_screen_control_area_pen_handlers(
            Cat432ControlAreaPenRepeatHandler,
            MMI_PEN_EVENT_REPEAT);
    wgui_register_category_screen_control_area_pen_handlers(
            Cat432ControlAreaPenMoveHandler,
            MMI_PEN_EVENT_MOVE);
    wgui_register_category_screen_control_area_pen_handlers(
            Cat432ControlAreaPenAbortHandler,
            MMI_PEN_EVENT_ABORT);
#endif /* __MMI_TOUCH_SCREEN__ */

    /* re-draw category screen */
    dm_redraw_category_screen();

    {
        /* set DCD layer */ 
        /* allocate memory */
        MMI_ASSERT(g_cat432_dcd_mem == NULL);
        g_cat432_dcd_mem = (U8*)mmi_frm_scrmem_alloc_framebuffer(SCRMEM_CAT432_POOL_SIZE);
        MMI_ASSERT(g_cat432_dcd_mem);
        
        /* create dcd layer */
        MMI_ASSERT(g_cat432_dcd_layer == NULL);
        dm_create_layer_using_outside_memory(
                CAT432_X, CAT432_Y, CAT432_W, CAT432_H,
                &g_cat432_dcd_layer,
                g_cat432_dcd_mem,
                SCRMEM_CAT432_POOL_SIZE,
                DM_LAYER_TOP);
        MMI_ASSERT(g_cat432_dcd_layer);
        
        /* init dcd layer */
        gdi_layer_push_and_set_active(*g_cat432_dcd_layer);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    }
    gdi_layer_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);
    MMI_ASSERT((mmi_cat432_title_handle == 0) && (mmi_cat432_bottom_handle == 0));

    {   /* set title layer */
        S32 ptr_offset = 0;
        S32 x, y, w, h;
        U8 bpp;
        U8 *buf_ptr;
        
        x = 0;
        y = 0;
        w = CAT432_W;
        h = CAT432_Y;

        bpp = gdi_layer_get_bit_per_pixel();
        gdi_layer_get_buffer_ptr(&buf_ptr);
        gdi_layer_create_cf_using_outside_memory(
                (gdi_color_format)(bpp >> 3),
                x, y, w, h,
                &mmi_cat432_title_handle,
                buf_ptr + ptr_offset,
                (((w*h*bpp + 7) >> 3)));

        MMI_ASSERT(mmi_cat432_title_handle);
        /* init layer */
        gdi_layer_push_and_set_active(mmi_cat432_title_handle);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    }
	
    {   /* set bottom layer */
        S32 ptr_offset = 0;
        S32 x, y, w, h;
        U8 bpp;
        U8 *buf_ptr;
		
        x = 0;
        y = MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT;
        w = MAIN_LCD_DEVICE_WIDTH;
        h = MMI_BUTTON_BAR_HEIGHT;
		
        bpp = gdi_layer_get_bit_per_pixel();
        gdi_layer_get_buffer_ptr(&buf_ptr);
        ptr_offset = (w*y*bpp + 7) >> 3;
        gdi_layer_create_cf_using_outside_memory(
                (gdi_color_format)(bpp >> 3),
                x, y, w, h,
                &mmi_cat432_bottom_handle,
                buf_ptr + ptr_offset,
                ((w*h*bpp + 7) >> 3));
		
        MMI_ASSERT(mmi_cat432_bottom_handle);
        /* init layer */
        gdi_layer_push_and_set_active(mmi_cat432_bottom_handle);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    }
    
    gdi_layer_lock_frame_buffer();
    gdi_layer_set_blt_layer(dm_get_scr_bg_layer(),mmi_cat432_bottom_handle, mmi_cat432_title_handle, *g_cat432_dcd_layer);
    ui_dcd_init(CAT432_X, CAT432_Y, CAT432_W, CAT432_H, *g_cat432_dcd_layer, (HDCD_Agent)agent);
    ui_dcd_show_start();
    gdi_layer_unlock_frame_buffer();
    gdi_lcd_repaint_all();
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory432Screen
 * DESCRIPTION
 *  Exits the category screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory432Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    ui_dcd_deinit();

    /* free dcd layer */
    g_cat432_dcd_layer = NULL;

    /* free dcd memory */
    if (g_cat432_dcd_mem != NULL)
    {
        mmi_frm_scrmem_free(g_cat432_dcd_mem);
        g_cat432_dcd_mem = NULL;
    }
    /* free title layer */    
    if (mmi_cat432_title_handle > 0)
    {
        gdi_layer_free(mmi_cat432_title_handle);
        mmi_cat432_title_handle = 0;
    }
    /* free bottom layer */
    if (mmi_cat432_bottom_handle > 0)
    {
        gdi_layer_free(mmi_cat432_bottom_handle);
        mmi_cat432_bottom_handle = 0;
    }

#if defined (__MMI_TOUCH_SCREEN__)
    mmi_cat432_pen_event_handler = NULL;
#endif /* defined (__MMI_TOUCH_SCREEN__) */
}
#endif /* defined(__MMI_OP01_DCD__) */


#if defined(__MMI_OP11_HOMESCREEN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_MAINLCD_240X320__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_MAINLCD_176X220__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_OP11_HOMESCREEN__) */
#ifdef __MMI_OP01_DCD_V30__

#include "dcdagentdefine.h"


static U8* g_wgui_cat9003_op01_mem = NULL;
static GDI_HANDLE *g_wgui_cat9003_op01_layer = GDI_NULL_HANDLE;
static GDI_HANDLE wgui_cat9003_op01_status_bar_handle = GDI_NULL_HANDLE;
static GDI_HANDLE wgui_cat9003_op01_bottom_handle = GDI_NULL_HANDLE;


#if defined(__MMI_TOUCH_SCREEN__)
static cat9003_op01_pen_handler wgui_cat9003_op01_pen_event_handler = NULL;
/*****************************************************************************
 * FUNCTION
 *  Cat432ControlAreaPenDownHandler
 * DESCRIPTION
 *  Pen down events handler function for category DCD control area.
 * PARAMETERS
 *  point                       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_cat9003_op01_cntrl_area_pen_down_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_cat9003_op01_pen_event_handler != NULL)
    {
        result = wgui_cat9003_op01_pen_event_handler(point, MMI_PEN_EVENT_DOWN);
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  Cat432ControlAreaPenUpHandler
 * DESCRIPTION
 *  Pen up events handler function for category432 control area.
 * PARAMETERS
 *  point                       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_cat9003_op01_cntrl_area_pen_up_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (wgui_cat9003_op01_pen_event_handler != NULL)
    {
        result = wgui_cat9003_op01_pen_event_handler(point, MMI_PEN_EVENT_UP);
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  Cat432ControlAreaPenLongTapHandler
 * DESCRIPTION
 *  Pen long-tap events handler function for category432 control area.
 * PARAMETERS
 *  point                       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_cat9003_op01_cntrl_area_pen_long_tap_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_cat9003_op01_pen_event_handler != NULL)
    {
        result = wgui_cat9003_op01_pen_event_handler(point, MMI_PEN_EVENT_LONG_TAP);
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  Cat432ControlAreaPenRepeatHandler
 * DESCRIPTION
 *  Pen repeat events handler function for category432 control area.
 * PARAMETERS
 *  point                       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_cat9003_op01_cntrl_area_pen_repeat_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_cat9003_op01_pen_event_handler != NULL)
    {
        result = wgui_cat9003_op01_pen_event_handler(point, MMI_PEN_EVENT_REPEAT);
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  Cat432ControlAreaPenMoveHandler
 * DESCRIPTION
 *  Pen move events handler function for category432 control area.
 * PARAMETERS
 *  point                       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_cat9003_op01_cntrl_area_pen_move_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_cat9003_op01_pen_event_handler != NULL)
    {
        result = wgui_cat9003_op01_pen_event_handler(point, MMI_PEN_EVENT_MOVE);
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  Cat432ControlAreaPenAbortHandler
 * DESCRIPTION
 *  Pen abort events handler function for category432 control area.
 * PARAMETERS
 *  point                       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_cat9003_op01_cntrl_area_pen_abort_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_cat9003_op01_pen_event_handler != NULL)
    {
        result = wgui_cat9003_op01_pen_event_handler(point, MMI_PEN_EVENT_ABORT);
    }
    return result;
}
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 



void wgui_cat9003_op01_exit(void);

void wgui_cat9003_op01_show(
        UI_string_type left_softkey,
        PU8 left_softkey_icon,
        UI_string_type right_softkey,
        PU8 right_softkey_icon,
        cat9003_op01_pen_handler pen_handler,
        void* agent,
        UI_buffer_type history_buffer)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* lock GDI frame buffer */
    gdi_layer_lock_frame_buffer();

    /* do not show shortcut */
    wgui_title_set_menu_shortcut_number(-1);

    /* change softkey label & icon, clear softkey handle function */
    dm_add_softkey(left_softkey, left_softkey_icon, right_softkey, right_softkey_icon);

    /* set title & title icon */
    //dm_add_title(title, title_icon);

    /* set flags */
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND | DM_NO_BLT;

    /* un-lock GDI frame buffer */
    gdi_layer_unlock_frame_buffer();

    /* set exit category screen function */
    ExitCategoryFunction = wgui_cat9003_op01_exit;

    /* register control area callback */
    dm_register_category_controlled_callback(NULL);

    /* set draw manager attributes */
    dm_setup_category_functions(dm_redraw_category_screen, dummy_get_history, dummy_get_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CAT9003_OP01_ID;
    dm_setup_data(&dm_data);

//wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR);

    /* register pen event handler */
#ifdef __MMI_TOUCH_SCREEN__
    wgui_cat9003_op01_pen_event_handler = pen_handler,
    wgui_register_category_screen_control_area_pen_handlers(
            wgui_cat9003_op01_cntrl_area_pen_down_hdlr,
            MMI_PEN_EVENT_DOWN);
    wgui_register_category_screen_control_area_pen_handlers(
            wgui_cat9003_op01_cntrl_area_pen_up_hdlr,
            MMI_PEN_EVENT_UP);
    wgui_register_category_screen_control_area_pen_handlers(
            wgui_cat9003_op01_cntrl_area_pen_long_tap_hdlr,
            MMI_PEN_EVENT_LONG_TAP);
    wgui_register_category_screen_control_area_pen_handlers(
            wgui_cat9003_op01_cntrl_area_pen_repeat_hdlr,
            MMI_PEN_EVENT_REPEAT);
    wgui_register_category_screen_control_area_pen_handlers(
            wgui_cat9003_op01_cntrl_area_pen_move_hdlr,
            MMI_PEN_EVENT_MOVE);
    wgui_register_category_screen_control_area_pen_handlers(
            wgui_cat9003_op01_cntrl_area_pen_abort_hdlr,
            MMI_PEN_EVENT_ABORT);
#endif /* __MMI_TOUCH_SCREEN__ */

    /* re-draw category screen */
    dm_redraw_category_screen();

    {
        /* set DCD layer */ 
        /* allocate memory */       
        
        MMI_ASSERT(g_wgui_cat9003_op01_mem == NULL);
        g_wgui_cat9003_op01_mem = (U8*)mmi_frm_scrmem_alloc_framebuffer(SCRMEM_CAT9003_OP01_POOL_SIZE);
        MMI_ASSERT(g_wgui_cat9003_op01_mem);
        
        /* create dcd layer */
        MMI_ASSERT(g_wgui_cat9003_op01_layer == NULL);
        dm_create_layer_using_outside_memory(
                CAT9003_OP01_X, CAT9003_OP01_Y, CAT9003_OP01_W, CAT9003_OP01_H,
                &g_wgui_cat9003_op01_layer,
                g_wgui_cat9003_op01_mem,
                SCRMEM_CAT9003_OP01_POOL_SIZE,
                DM_LAYER_TOP);
        MMI_ASSERT(g_wgui_cat9003_op01_layer);
        
        /* init dcd layer */
        gdi_layer_push_and_set_active(*g_wgui_cat9003_op01_layer);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    }
    gdi_layer_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);
    MMI_ASSERT((wgui_cat9003_op01_status_bar_handle ==0)&&(wgui_cat9003_op01_bottom_handle == 0));


    {   /* set status bar layer */
        S32 ptr_offset = 0;
        S32 x, y, w, h;
        U8 bpp;
        U8 *buf_ptr;
        
        x = 0;
        y = 0;
        w = CAT9003_OP01_W;
        h = CAT9003_OP01_Y;

        bpp = gdi_layer_get_bit_per_pixel();
        gdi_layer_get_buffer_ptr(&buf_ptr);
        gdi_layer_create_cf_using_outside_memory(
                (gdi_color_format)(bpp >> 3),
                x, y, w, h,
                &wgui_cat9003_op01_status_bar_handle,
                buf_ptr + ptr_offset,
                (((w*h*bpp + 7) >> 3)));

        MMI_ASSERT(wgui_cat9003_op01_status_bar_handle);
        /* init layer */
        gdi_layer_push_and_set_active(wgui_cat9003_op01_status_bar_handle);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    }

    {   /* set bottom layer */
        S32 ptr_offset = 0;
        S32 x, y, w, h;
        U8 bpp;
        U8 *buf_ptr;
		
        x = 0;
        y = MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT;
        w = MAIN_LCD_DEVICE_WIDTH;
        h = MMI_BUTTON_BAR_HEIGHT;
		
        bpp = gdi_layer_get_bit_per_pixel();
        gdi_layer_get_buffer_ptr(&buf_ptr);
        ptr_offset = (w*y*bpp + 7) >> 3;
        gdi_layer_create_cf_using_outside_memory(
                (gdi_color_format)(bpp >> 3),
                x, y, w, h,
                &wgui_cat9003_op01_bottom_handle,
                buf_ptr + ptr_offset,
                ((w*h*bpp + 7) >> 3));
		
        MMI_ASSERT(wgui_cat9003_op01_bottom_handle);
        /* init layer */
        gdi_layer_push_and_set_active(wgui_cat9003_op01_bottom_handle);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    }
    
    gdi_layer_lock_frame_buffer();
    gdi_layer_set_blt_layer(dm_get_scr_bg_layer(),wgui_cat9003_op01_status_bar_handle, wgui_cat9003_op01_bottom_handle, *g_wgui_cat9003_op01_layer);
    ui_dcd_init(CAT9003_OP01_X, CAT9003_OP01_Y, CAT9003_OP01_W, CAT9003_OP01_H, *g_wgui_cat9003_op01_layer, (HDCD_Agent)agent);
    ui_dcd_show_start();
    gdi_layer_unlock_frame_buffer();
    gdi_lcd_repaint_all();
}

void wgui_cat9003_op01_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    ui_dcd_deinit();

    /* free dcd layer */
    g_wgui_cat9003_op01_layer = NULL;

    /* free dcd memory */
    if (g_wgui_cat9003_op01_mem != NULL)
    {
        mmi_frm_scrmem_free(g_wgui_cat9003_op01_mem);
        g_wgui_cat9003_op01_mem = NULL;
    }
    /* free status bar layer */    
    if (wgui_cat9003_op01_status_bar_handle > 0)
    {
        gdi_layer_free(wgui_cat9003_op01_status_bar_handle);
        wgui_cat9003_op01_status_bar_handle = 0;
    }
    /* free bottom layer */
    if (wgui_cat9003_op01_bottom_handle > 0)
    {
        gdi_layer_free(wgui_cat9003_op01_bottom_handle);
        wgui_cat9003_op01_bottom_handle = 0;
    }

#if 0//defined (__MMI_TOUCH_SCREEN__)
/* under construction !*/
#endif /* defined (__MMI_TOUCH_SCREEN__) */
}
#endif /* __MMI_OP01_DCD_V30__ */

#if defined(__MMI_TC01_LTUI_SMART_MEMO__)
static U8 *g_wgui_cat9007_tc01_image_p = NULL;
static S8 *g_wgui_cat9007_tc01_image_path_p = NULL;
static U32 wgui_cat9007_tc01_clock_day  = WGUI_CLOCK_INVALID_INDEX;
static U32 wgui_cat9007_tc01_clock_date = WGUI_CLOCK_INVALID_INDEX;
static S32 g_bracket_pos_x = 0;
static S32 g_string_height = 0;
static color g_wgui_cat9007_tc01_text_color = {0, 0, 0, 100};

/*****************************************************************************
 * FUNCTION
 *  wgui_cat9007_tc01_set_text_color
 * DESCRIPTION
 *  show bracket of day
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat9007_tc01_set_text_color(color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_cat9007_tc01_text_color = c;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat9007_tc01_get_text_color
 * DESCRIPTION
 *  show bracket of day
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static color wgui_cat9007_tc01_get_text_color(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_wgui_cat9007_tc01_text_color;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat9007_tc01_show_bracket
 * DESCRIPTION
 *  show bracket of day
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat9007_tc01_show_bracket(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y;
    S32 bracket_width = 0, bracket_height = 0;
    color c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c = wgui_cat9007_tc01_get_text_color();
    
    gui_set_font(&MMI_medium_font);
    gui_set_text_color(c);

    /* print "[" */
    gui_measure_character((UI_character_type)'[', &bracket_width, &bracket_height);

    x = WGUI_CAT9007_TC01_DATE_TIME_X;
    y = WGUI_CAT9007_TC01_DATE_TIME_Y + ((g_string_height - bracket_height) >> 1);   /* central y */

    gui_move_text_cursor(x, y);
    gui_print_text(L"[");

    /* print "]" */
    gui_move_text_cursor(g_bracket_pos_x, y);
    gui_print_text(L"]");
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat9007_tc01_hide_date_time 
 * DESCRIPTION
 *  Hide function for smart memo category date time component
 * PARAMETERS
 *  x1      [IN]
 *  y1      [IN]
 *  x2      [IN]
 *  y2      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat9007_tc01_hide_date_time(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat9007_tc01_close_clock 
 * DESCRIPTION
 *  close all clocks
 * PARAMETERS
 *  x1      [IN]
 *  y1      [IN]
 *  x2      [IN]
 *  y2      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat9007_tc01_close_clock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* close date time component */
    wgui_clock_close(wgui_cat9007_tc01_clock_day);
    wgui_clock_close(wgui_cat9007_tc01_clock_date);
    wgui_cat9007_tc01_clock_day  = WGUI_CLOCK_INVALID_INDEX;
    wgui_cat9007_tc01_clock_date = WGUI_CLOCK_INVALID_INDEX;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat9007_tc01_init_datatime 
 * DESCRIPTION
 *  Init smart memo category date time component
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat9007_tc01_init_data_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x = 0, y = 0, w = 0, h = 0;
    S32 bracket_width = 0, bracket_height = 0;
    color c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c = wgui_cat9007_tc01_get_text_color();
    gui_measure_character((UI_character_type)'[', &bracket_width, &bracket_height);
    x = WGUI_CAT9007_TC01_DATE_TIME_X + bracket_width + 2 /* gap */;
    y = WGUI_CAT9007_TC01_DATE_TIME_Y;

    /* Local day */
    wgui_clock_create(
        &wgui_cat9007_tc01_clock_day,          /* local day */
        0, 0, 0, 0,                            /* will move & assign layer */
        GUI_CLOCK_MAINLCD_TYPE_DIGITAL_DAY);   /* only display day */

    wgui_clock_set_text_border_enable(wgui_cat9007_tc01_clock_day, MMI_FALSE);
    wgui_clock_set_date_text_color(wgui_cat9007_tc01_clock_day, c);
    wgui_clock_set_date_text_font(wgui_cat9007_tc01_clock_day, &MMI_medium_font);

    wgui_clock_set_hide_function(wgui_cat9007_tc01_clock_day, wgui_cat9007_tc01_hide_date_time);

    wgui_clock_measure_date_text(wgui_cat9007_tc01_clock_day, &w, &h, &MMI_medium_font);
    wgui_clock_move(wgui_cat9007_tc01_clock_day, x, y);
    wgui_clock_resize(wgui_cat9007_tc01_clock_day, w, h);

    wgui_clock_set_digital_align_type(wgui_cat9007_tc01_clock_day, GUI_CLOCK_DIGITAL_ALIGN_CENTER);

    g_bracket_pos_x = x + w + 2 /* gap */;
    g_string_height = h;

    x = g_bracket_pos_x + bracket_width + 2 /* gap */;
        
    /* Local date */
    wgui_clock_create(
        &wgui_cat9007_tc01_clock_date,           /* local date */
        0, 0, 0, 0,                             /* will move & assign layer */
        GUI_CLOCK_MAINLCD_TYPE_DIGITAL_DATE);   /* display date */

    wgui_clock_set_text_border_enable(wgui_cat9007_tc01_clock_date, MMI_FALSE);
    wgui_clock_set_date_text_color(wgui_cat9007_tc01_clock_date, c);
    wgui_clock_set_date_text_font(wgui_cat9007_tc01_clock_date, &MMI_medium_font);

    wgui_clock_set_hide_function(wgui_cat9007_tc01_clock_date, wgui_cat9007_tc01_hide_date_time);

    wgui_clock_measure_date_text(wgui_cat9007_tc01_clock_date, &w, &h, &MMI_medium_font);
    wgui_clock_move(wgui_cat9007_tc01_clock_date, x, y);
    wgui_clock_resize(wgui_cat9007_tc01_clock_date, w, h);

    wgui_clock_set_digital_align_type(wgui_cat9007_tc01_clock_date, GUI_CLOCK_DIGITAL_ALIGN_LEFT);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat9007_tc01_draw_ctrl_area
 * DESCRIPTION
 *  Draw image background and clock.
 * PARAMETERS
 *  coordinate          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat9007_tc01_draw_ctrl_area(dm_coordinates *coordinate)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 image_width, image_height;
    GDI_RESULT gdi_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	gdi_layer_lock_frame_buffer();

    /* Draw background image on the screen background layer */
    gdi_layer_push_and_set_active(dm_get_scr_bg_layer());
    
    gdi_layer_push_clip();
    gdi_layer_set_clip(
        coordinate->s16X,
        coordinate->s16Y,
        coordinate->s16X + coordinate->s16Width,
        coordinate->s16Y + coordinate->s16Height);

    gdi_image_get_dimension(
        g_wgui_cat9007_tc01_image_p,
        &image_width,
        &image_height);
    
    if (image_width != coordinate->s16Width ||
        image_height != coordinate->s16Height)
    {
        gdi_result = gdi_image_draw_resized(
                        coordinate->s16X,
                        coordinate->s16Y,
                        coordinate->s16Width,
                        coordinate->s16Height,
                        g_wgui_cat9007_tc01_image_p);
    }
    else
    {
        gdi_result = gdi_image_draw(
                        coordinate->s16X,
                        coordinate->s16Y,
                        g_wgui_cat9007_tc01_image_p);
    }
    
    gdi_layer_pop_clip();
    
    gdi_layer_pop_and_restore_active();

    /* assume base layer */
    gdi_layer_push_and_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);

    /* display brackets "[" and "]" */
    wgui_cat9007_tc01_show_bracket();

    /* display date time */
    wgui_clock_show_main_lcd();

    gdi_layer_pop_and_restore_active();

    gdi_layer_unlock_frame_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat9007_tc01_exit
 * DESCRIPTION
 *  Exit the category9001 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat9007_tc01_exit(void)
{
    wgui_cat9007_tc01_close_clock();

    wgui_inputs_ml_close();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat9007_tc01_show
 * DESCRIPTION
 *  This category scrren is used for text memo viewer.
 * PARAMETERS
 *  left_softkey            [IN]        String ID for the left softkey label
 *  left_softkey_icon       [IN]        Image ID for the left softkey icon
 *  right_softkey           [IN]        String ID for the right softkey label
 *  right_softkey_icon      [IN]        Image ID for the right softkey icon
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat9007_tc01_show(
        WCHAR *left_softkey,
        PU8 left_softkey_icon,
        WCHAR *right_softkey,
        PU8 right_softkey_icon,
        MMI_IMG_ID image_background,
        WCHAR *message,
        color text_color,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    S32 str_number;
    // color border_color = {0, 0, 255, 100}; /* transparent color  */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_cat9007_tc01_image_p = get_image(image_background);
    
    wgui_cat9007_tc01_set_text_color(text_color);
    
    gdi_layer_lock_frame_buffer();

    /* set softkey */
	dm_add_softkey(left_softkey, left_softkey_icon, right_softkey, right_softkey_icon);

    /* creat date time component */
    wgui_cat9007_tc01_init_data_time();

    /* set multiline inputbox */
    MMI_message_string = message;
    str_number = gui_strlen(MMI_message_string);
    wgui_inputs_ml_create_set_buffer(MMI_message_string, str_number, str_number, 0);
	MMI_multiline_inputbox.normal_text_color = text_color;
    // MMI_multiline_inputbox.border_color = border_color;
    MMI_multiline_inputbox.flags |=
        UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW |
        UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR |
        UI_MULTI_LINE_INPUT_BOX_VIEW_MODE |
        UI_MULTI_LINE_INPUT_BOX_TRANSPARENT_BACKGROUND;
    MMI_multiline_inputbox.ext_flags = 
        GUI_MULTI_LINE_INPUT_BOX_TRUNCATE_CONTENT |
        GUI_MULTI_LINE_INPUT_BOX_NONE_BORDER;

    /* set arrow key handler */
    wgui_inputs_ml_register_viewer_keys();

    /* set history */
    if (history_buffer)
    {
        wgui_inputs_ml_set_category_history(MMI_CAT9007_TC01_ID, history_buffer);
    }

    gdi_layer_unlock_frame_buffer();

    /* setup category/draw manager data */
    ExitCategoryFunction = wgui_cat9007_tc01_exit;
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_register_category_controlled_callback(wgui_cat9007_tc01_draw_ctrl_area);

    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CAT9007_TC01_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND | DM_SCR_BG_NO_CACHE;
    dm_setup_data(&dm_data);

    dm_redraw_category_screen();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat9009_tc01_append_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 *  k       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat9009_tc01_append_string(U32 input_type, U8 *buffer, S32 buffer_size, U8 *s, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_ml_append_string(input_type,buffer,buffer_size,s,history_buffer,MMI_CAT9009_TC01_ID,NULL);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat9009_tc01_set_rsk_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 *  k       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat9009_tc01_set_rsk_func(void (*f) (void), MMI_key_event_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(k);
    wgui_inputbox_RSK_function = f;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat9009_tc01_exit
 * DESCRIPTION
 *  Exit the category9001 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat9009_tc01_exit(void)
{
    MMI_multiline_inputbox_x = MMI_MULTILINE_INPUTBOX_X;
    MMI_multiline_inputbox_y = MMI_MULTILINE_INPUTBOX_Y;
    MMI_multiline_inputbox_height = UI_DEVICE_HEIGHT;
    MMI_multiline_inputbox_width = UI_DEVICE_WIDTH;
    MMI_multitap_x = MMI_MULTITAP_X;
    MMI_multitap_y = (UI_device_height - MMI_BUTTON_BAR_HEIGHT - MMI_multitap_height);
    MMI_multitap_width = UI_device_width - 4;

    wgui_cat9007_tc01_close_clock();

    wgui_inputs_ml_close();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat9009_tc01_show
 * DESCRIPTION
 *  This category scrren is used for text memo viewer.
 * PARAMETERS
 *  left_softkey            [IN]        String ID for the left softkey label
 *  left_softkey_icon       [IN]        Image ID for the left softkey icon
 *  right_softkey           [IN]        String ID for the right softkey label
 *  right_softkey_icon      [IN]        Image ID for the right softkey icon
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat9009_tc01_show(
        WCHAR *left_softkey,
        PU8 left_softkey_icon,
        WCHAR *right_softkey,
        PU8 right_softkey_icon,
        MMI_IMG_ID image_background,
        color text_color,
        U32 input_type,
        U8 *buffer,
        S32 buffer_size,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_cat9007_tc01_image_p = get_image(image_background);
    
    wgui_cat9007_tc01_set_text_color(text_color);
    
    gdi_layer_lock_frame_buffer();

    /* set softkey */
	dm_add_softkey(left_softkey, left_softkey_icon, right_softkey, right_softkey_icon);

    /* creat date time component */
    wgui_cat9007_tc01_init_data_time();

    /* set multiline inputbox */
    MMI_multiline_inputbox_x = WGUI_CAT9007_TC01_MULTILINE_X;
    MMI_multiline_inputbox_y = WGUI_CAT9007_TC01_MULTILINE_Y;
    MMI_multiline_inputbox_width = WGUI_CAT9007_TC01_MULTILINE_WIDTH;
    MMI_multiline_inputbox_height = WGUI_CAT9007_TC01_MULTILINE_HEIGHT;
    MMI_multitap_x = WGUI_CAT9007_TC01_MULTILINE_X;
    MMI_multitap_y = WGUI_CAT9007_TC01_MULTILINE_Y + WGUI_CAT9007_TC01_MULTILINE_HEIGHT - MMI_multitap_height;	
    MMI_multitap_width = WGUI_CAT9007_TC01_MULTILINE_WIDTH;

    MMI_multiline_inputbox.flags = 0;
    MMI_multiline_inputbox.ext_flags = 0;

    mmi_imc_set_fixed_input_box();

    wgui_inputs_ml_setup_ext(
        MMI_multiline_inputbox_x,
        MMI_multiline_inputbox_y,
        MMI_multiline_inputbox_width,
        MMI_multiline_inputbox_height,
        buffer,
        buffer_size,
        MMI_CAT9009_TC01_ID,
        right_softkey,
        right_softkey_icon,
        input_type,
        history_buffer,
        NULL,
        1,
        0,
        0,
        0,
        0,
        0,
        NULL);
    
	MMI_multiline_inputbox.normal_text_color = text_color;
    MMI_multiline_inputbox.cursor_color = text_color;
    MMI_multiline_inputbox.flags |=
        UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR |
        UI_MULTI_LINE_INPUT_BOX_TRANSPARENT_BACKGROUND;
    MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_NONE_BORDER;

    gdi_layer_unlock_frame_buffer();

    /* setup category/draw manager data */
    ExitCategoryFunction = wgui_cat9009_tc01_exit;
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_register_category_controlled_callback(wgui_cat9007_tc01_draw_ctrl_area);

    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CAT9009_TC01_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND | DM_SCR_BG_NO_CACHE;
    dm_setup_data(&dm_data);

    dm_redraw_category_screen();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat9008_tc01_draw_ctrl_area
 * DESCRIPTION
 *  Draw image background, image and clock.
 * PARAMETERS
 *  coordinate          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat9008_tc01_draw_ctrl_area(dm_coordinates *coordinate)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 image_width, image_height;
    S32 image_area_width, image_area_height;
    S32 x1, y1, x2, y2;
    GDI_RESULT gdi_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	gdi_layer_lock_frame_buffer();

    /* Draw background image on the screen background layer */
    gdi_layer_push_and_set_active(dm_get_scr_bg_layer());
    
    gdi_layer_push_clip();
    gdi_layer_set_clip(
        coordinate->s16X,
        coordinate->s16Y,
        coordinate->s16X + coordinate->s16Width,
        coordinate->s16Y + coordinate->s16Height);

    gdi_image_get_dimension(
        g_wgui_cat9007_tc01_image_p,
        &image_width,
        &image_height);
    
    if (image_width != coordinate->s16Width ||
        image_height != coordinate->s16Height)
    {
        gdi_result = gdi_image_draw_resized(
                        coordinate->s16X,
                        coordinate->s16Y,
                        coordinate->s16Width,
                        coordinate->s16Height,
                        g_wgui_cat9007_tc01_image_p);
    }
    else
    {
        gdi_result = gdi_image_draw(
                        coordinate->s16X,
                        coordinate->s16Y,
                        g_wgui_cat9007_tc01_image_p);
    }

    gdi_layer_pop_clip();
    
    gdi_layer_pop_and_restore_active();

    /* assume base layer */
    gdi_layer_push_and_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);

    if (g_wgui_cat9007_tc01_image_path_p)
    {
        /* draw image */
        x1 = WGUI_CAT9008_TC01_IMAGE_X;
        y1 = WGUI_CAT9008_TC01_IMAGE_Y;
        x2 = WGUI_CAT9008_TC01_IMAGE_X + WGUI_CAT9008_TC01_IMAGE_WIDTH - 1;
        y2 = WGUI_CAT9008_TC01_IMAGE_Y + WGUI_CAT9008_TC01_IMAGE_HEIGHT - 1;
        image_area_width = x2 - x1 + 1;
        image_area_height = y2 - y1 + 1;

        gdi_layer_push_clip();
        gdi_layer_set_clip(x1, y1, x2, y2);
        
        gdi_image_get_dimension_file(
            g_wgui_cat9007_tc01_image_path_p,
            &image_width,
            &image_height);
        
        if (image_width != image_area_width ||
            image_height != image_area_height)
        {
            gdi_result = gdi_image_draw_resized_file(
                            x1,
                            y1,
                            image_area_width,
                            image_area_height,
                            g_wgui_cat9007_tc01_image_path_p);
        }
        else
        {
            gdi_result = gdi_image_draw_file(
                            x1,
                            y1,
                            g_wgui_cat9007_tc01_image_path_p);
        }
        
        if (gdi_result != GDI_SUCCEED)
        {
            // TODO: show default image
        }
        gdi_layer_pop_clip();
    }

    /* display brackets "[" and "]" */
    wgui_cat9007_tc01_show_bracket();

    /* display date time */
    wgui_clock_show_main_lcd();

    gdi_layer_pop_and_restore_active();

    gdi_layer_unlock_frame_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat9008_tc01_exit
 * DESCRIPTION
 *  Exit the category9002 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat9008_tc01_exit(void)
{
    wgui_cat9007_tc01_close_clock();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat9008_tc01_show
 * DESCRIPTION
 *  This category scrren is used for image memo viewer.
 * PARAMETERS
 *  left_softkey            [IN]        String ID for the left softkey label
 *  left_softkey_icon       [IN]        Image ID for the left softkey icon
 *  right_softkey           [IN]        String ID for the right softkey label
 *  right_softkey_icon      [IN]        Image ID for the right softkey icon
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat9008_tc01_show(
        WCHAR *left_softkey,
        PU8 left_softkey_icon,
        WCHAR *right_softkey,
        PU8 right_softkey_icon,
        MMI_IMG_ID image_background,
        S8 *memo_image_path,
        color text_color,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat9007_tc01_set_text_color(text_color);
    g_wgui_cat9007_tc01_image_p = get_image(image_background);
    g_wgui_cat9007_tc01_image_path_p = memo_image_path;
    
    gdi_layer_lock_frame_buffer();

    /* set softkey */
	dm_add_softkey(left_softkey, left_softkey_icon, right_softkey, right_softkey_icon);

    /* creat date time component */
    wgui_cat9007_tc01_init_data_time();

    gdi_layer_unlock_frame_buffer();

    /* setup category/draw manager data */
    ExitCategoryFunction = wgui_cat9008_tc01_exit;
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_register_category_controlled_callback(wgui_cat9008_tc01_draw_ctrl_area);

    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CAT9008_TC01_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND | DM_SCR_BG_NO_CACHE;
    dm_setup_data(&dm_data);

    dm_redraw_category_screen();
}
#endif /* defined(__MMI_TC01_LTUI_SMART_MEMO__) */

#ifdef __MMI_OP02_LEMEI__
#if (defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__))
        #define MMI_CAT9002_BUTTON_AREA_X                       (6)
        #define MMI_CAT9002_BUTTON_AREA_Y                       (127)
        #define MMI_CAT9002_BUTTON_AREA_WIDTH                   (232)
        #define MMI_CAT9002_BUTTON_AREA_HEIGHT                  (62)
        #define MMI_CAT9002_BUTTON_WIDTH                        (76)
        #define MMI_CAT9002_BUTTON_HEIGHT                       (113)
        #define MMI_CAT9002_BUTTON_HORIZONTAL_GAP               (0)
#elif defined(__MMI_MAINLCD_320X240__)
        #define MMI_CAT9002_BUTTON_AREA_X                       (46)
        #define MMI_CAT9002_BUTTON_AREA_Y                       (78)
        #define MMI_CAT9002_BUTTON_AREA_WIDTH                   (228)
        #define MMI_CAT9002_BUTTON_AREA_HEIGHT                  (62)
        #define MMI_CAT9002_BUTTON_WIDTH                        (76)
        #define MMI_CAT9002_BUTTON_HEIGHT                       (113)
        #define MMI_CAT9002_BUTTON_HORIZONTAL_GAP               (0)
#elif defined(__MMI_MAINLCD_320X480__)
        #define MMI_CAT9002_BUTTON_AREA_X                       (7)
        #define MMI_CAT9002_BUTTON_AREA_Y                       (157)
        #define MMI_CAT9002_BUTTON_AREA_WIDTH                   (312)
        #define MMI_CAT9002_BUTTON_AREA_HEIGHT                  (84)
        #define MMI_CAT9002_BUTTON_WIDTH                        (102)
        #define MMI_CAT9002_BUTTON_HEIGHT                       (142)
        #define MMI_CAT9002_BUTTON_HORIZONTAL_GAP               (0)
#endif /*defined(__MMI_FTE_SUPPORT__) && (defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X400__))*/

typedef struct _wgui_cat9002_op02_button_area_struct
{
    S32 button_area_x, button_area_y;
    S32 button_area_width, button_area_height;
    S32 button_width, button_height;
    S32 horizontal_gap;
    S32 selected_button_x, selected_button_y;
    S32 button_num;
    S32 button_press_down;
}wgui_cat9002_op02_button_area_struct;

wgui_cat9002_op02_button_area_struct wgui_cat9002_op02_button_area;

static MMI_ID_TYPE wgui_cat9002_op02_button_image[] = 
{
    IMG_ID_LEMEI_AUDIO_RECORDER_UP,
    IMG_ID_LEMEI_CAMERA_UP,
    IMG_ID_LEMEI_VIDEO_RECORDER_UP,
};

static MMI_ID_TYPE wgui_cat9002_op02_button_down_image[] = 
{
    IMG_ID_LEMEI_AUDIO_RECORDER_DOWN,
    IMG_ID_LEMEI_CAMERA_DOWN,
    IMG_ID_LEMEI_VIDEO_RECORDER_DOWN,
};


typedef enum
{
    BUTTON_INVALID = 0,
    BUTTON_1,
    BUTTON_2,
    BUTTON_3
}wgui_cat9002_op02_button_enum;


MMI_ID_TYPE button_clicked = BUTTON_INVALID;
static void (*wgui_cat9002_op02_button1_handler) (void) = NULL;
static void (*wgui_cat9002_op02_button2_handler) (void) = NULL; 
static void (*wgui_cat9002_op02_button3_handler) (void) = NULL;

void wgui_cat9002_op02_exit(void);
void wgui_cat9002_op02_draw_ctrl_area(dm_coordinates *coordinate);
void wgui_cat9002_op02_show_button_area(wgui_cat9002_op02_button_area_struct *button_area);
void wgui_cat9002_op02_setup_button_area(wgui_cat9002_op02_button_area_struct *button_area);
static MMI_BOOL wgui_cat9002_op02_cntrl_area_pen_down_hdlr(mmi_pen_point_struct point);
static MMI_BOOL wgui_cat9002_op02_cntrl_area_pen_up_hdlr(mmi_pen_point_struct point);
MMI_BOOL wgui_cat9002_op02_screen_translate_pen_event(wgui_cat9002_op02_button_area_struct *button_area,
                                                                S32 x,
                                                                S32 y,
                                                                mmi_pen_event_type_enum pen_event);
void wgui_cat9002_op02_translate_pen_position(wgui_cat9002_op02_button_area_struct *button_area, S32 x, S32 y, S32 *item_index);
void wgui_cat9002_op02_button_select(wgui_cat9002_op02_button_area_struct *button_area, S32 item_index);
void wgui_cat9002_op02_button_unselect(wgui_cat9002_op02_button_area_struct *button_area);


void wgui_cat9002_op02_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = MMI_dummy_function;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;
}

void wgui_cat9002_op02_show(UI_string_type title,
                                        PU8 title_icon,
                                        UI_string_type left_softkey,
                                        PU8 left_softkey_icon,
                                        UI_string_type right_softkey,
                                        PU8 right_softkey_icon)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gdi_layer_lock_frame_buffer();
    
    dm_add_image(get_image(IMG_ID_LEMEI_BG), NULL, NULL);

    dm_add_title(title, title_icon);
    dm_add_softkey(left_softkey, left_softkey_icon, right_softkey, right_softkey_icon);

    wgui_cat9002_op02_setup_button_area(&wgui_cat9002_op02_button_area);
    gdi_layer_unlock_frame_buffer();

    dm_register_category_controlled_callback(wgui_cat9002_op02_draw_ctrl_area);
    
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_category_screen_control_area_pen_handlers(wgui_cat9002_op02_cntrl_area_pen_down_hdlr, MMI_PEN_EVENT_DOWN);
    wgui_register_category_screen_control_area_pen_handlers(wgui_cat9002_op02_cntrl_area_pen_up_hdlr, MMI_PEN_EVENT_UP);
#endif

    ExitCategoryFunction = wgui_cat9002_op02_exit;
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CAT9002_OP02_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND | DM_SET_AS_ABM_LAYER;
    dm_setup_data(&dm_data); 
    
    dm_redraw_category_screen();
}


static void wgui_cat9002_op02_draw_ctrl_area(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* draw background image */
    gdi_layer_push_clip();
    gdi_layer_reset_clip();

    wgui_cat9002_op02_show_button_area(&wgui_cat9002_op02_button_area);

    gdi_layer_pop_clip();
}

void wgui_cat9002_op02_show_button_area(wgui_cat9002_op02_button_area_struct *button_area)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0 ; i < button_area->button_num ; i++)
    {
        /* calculate position */
        x1 = button_area->button_area_x + (button_area->button_width + button_area->horizontal_gap)*i;
        y1 = button_area->button_area_y;
        x2 = x1 + button_area->button_width - 1;
        y2 = y1+ button_area->button_height - 1;

        gdi_layer_push_clip();
        gdi_layer_set_clip(x1, y1, x2, y2);

        gdi_image_draw(x1, y1, get_image(wgui_cat9002_op02_button_image[i]));               /* background */

        gdi_layer_pop_clip();
    }
}


void wgui_cat9002_op02_setup_button_area(wgui_cat9002_op02_button_area_struct *button_area)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    button_area->button_area_x = MMI_CAT9002_BUTTON_AREA_X;
    button_area->button_area_y = MMI_CAT9002_BUTTON_AREA_Y;
    button_area->button_area_width = MMI_CAT9002_BUTTON_AREA_WIDTH;
    button_area->button_area_height= MMI_CAT9002_BUTTON_AREA_HEIGHT;
    button_area->button_width = MMI_CAT9002_BUTTON_WIDTH;
    button_area->button_height = MMI_CAT9002_BUTTON_HEIGHT;
    button_area->horizontal_gap = MMI_CAT9002_BUTTON_HORIZONTAL_GAP;
    button_area->button_num= 3;
    button_area->button_press_down = BUTTON_INVALID;
    //wgui_cat9002_op02_button_area->key_type = 0;
}

static MMI_BOOL wgui_cat9002_op02_cntrl_area_pen_down_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get dialing screen  event type according to current state of dialing screen */

    ret = wgui_cat9002_op02_screen_translate_pen_event(
            &wgui_cat9002_op02_button_area,
            point.x,
            point.y,
            MMI_PEN_EVENT_DOWN);

    if (ret)
    {
        gdi_lcd_repaint_all();
    }

    return ret;
}

static MMI_BOOL wgui_cat9002_op02_cntrl_area_pen_up_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    U16 scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get dialing screen  event type according to current state of dialing screen */
    scr_id = GetActiveScreenId();

    ret = wgui_cat9002_op02_screen_translate_pen_event(
            &wgui_cat9002_op02_button_area,
            point.x,
            point.y,
            MMI_PEN_EVENT_UP);

    if (scr_id == GetActiveScreenId() && ret)
    {
        gdi_lcd_repaint_all();

    }

    switch(button_clicked)
    {
        case BUTTON_1:
            if(wgui_cat9002_op02_button1_handler != NULL)
            {
                wgui_cat9002_op02_button1_handler();
            }
            break;

        case BUTTON_2:
            if(wgui_cat9002_op02_button2_handler != NULL)
            {
                wgui_cat9002_op02_button2_handler();
            }
            break;

        case BUTTON_3:
            if(wgui_cat9002_op02_button3_handler != NULL)
            {
                wgui_cat9002_op02_button3_handler();
            }
            break;

        case BUTTON_INVALID:
        default:
            break;
    }
    return ret;
}

MMI_BOOL wgui_cat9002_op02_screen_translate_pen_event(wgui_cat9002_op02_button_area_struct *button_area,
                                                    S32 x,
                                                    S32 y,
                                                    mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    S32 item_index = -1;
    S32 x1, y1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = MMI_TRUE;

    x1 = button_area->button_area_x;
    y1 = button_area->button_area_y;

    switch (pen_event)
    {
        case MMI_PEN_EVENT_DOWN:
            if (PEN_CHECK_BOUND(x, y, x1, y1, button_area->button_area_width, button_area->button_area_height))
            {
                wgui_cat9002_op02_translate_pen_position(button_area, x, y, &item_index);
                if (item_index == -1)   /* No key is selected */
                {
                    ret = MMI_FALSE;
                }
                else
                {
                    wgui_cat9002_op02_button_select(button_area, item_index);
                }
            }
            else
            {
                ret = MMI_FALSE;
            }
            break;

        case MMI_PEN_EVENT_UP:
            if (PEN_CHECK_BOUND
                (x, y, button_area->selected_button_x, button_area->selected_button_y, button_area->button_area_width,
                 button_area->button_area_height))
            {
                wgui_cat9002_op02_translate_pen_position(button_area, x, y, &item_index);
                wgui_cat9002_op02_button_unselect(button_area);
            }
            else
            {
                wgui_cat9002_op02_button_unselect(button_area);
                ret = MMI_TRUE;
            }
            if(item_index == -1)
            {
                button_clicked = BUTTON_INVALID;
            }
            else if(item_index == 1)
            {
                button_clicked = BUTTON_1;
            }
            else if(item_index == 2)
            {
                button_clicked = BUTTON_2;
            }
            else if(item_index == 3)
            {
                button_clicked = BUTTON_3;
            }
            break;
    }
    return ret;
}

void wgui_cat9002_op02_translate_pen_position(wgui_cat9002_op02_button_area_struct *button_area, S32 x, S32 y, S32 *item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 total_height = 0, total_width = 0;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    total_height = button_area->button_area_y + button_area->button_height;
    total_width = button_area->button_area_x;
    *item_index = -1;
    
    if (total_height > y)
    {
        for (i = 0; i < button_area->button_num; i++)
        {
            total_width += button_area->button_width;
            if (total_width > x)
            {
                *item_index = i + 1;
                button_area->selected_button_x =
                    button_area->button_area_x + (button_area->button_width) * i +
                    (button_area->horizontal_gap) * i;
                button_area->selected_button_y = button_area->button_area_y;
                //wgui_cat9002_op02_button_area->key_type = *item_index;
                break;
            }
            else
            {
                total_width += button_area->horizontal_gap;
                if (total_width > x)
                {
                    *item_index = -1;
                    break;
                }
            }
        }
    }
}

void wgui_cat9002_op02_button_select(wgui_cat9002_op02_button_area_struct *button_area, S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    S32 width, height;
    S32 button_width, button_height;
    MMI_ID_TYPE image_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    button_width = button_area->button_width;
    button_height = button_area->button_height;

    x1 = button_area->selected_button_x;
    y1 = button_area->selected_button_y;

    x2 = x1 + button_width - 1;
    y2 = y1 + button_height - 1;

    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);

    if (0<= (item_index-1) && (item_index-1) < sizeof(wgui_cat9002_op02_button_image) / sizeof(wgui_cat9002_op02_button_image[0]))
    {
        image_id = wgui_cat9002_op02_button_down_image[item_index - 1];

        gui_measure_image(get_image(image_id), &width, &height);

        x1 = x1 + ((button_width - width) >> 1);
        y1 = y1 + ((button_height - height) >> 1);

        {
            GDI_HANDLE act_layer;
            PU8 bg_img;

            /* set current layer as source layer */
            gdi_layer_get_active(&act_layer);
            gdi_push_and_set_alpha_blending_source_layer(act_layer);

            //gdi_image_draw_id(0, 0, IMG_DIALING_SCREEN);
            bg_img = get_image(wgui_cat9002_op02_button_down_image[item_index - 1]);

            gdi_image_draw(x1, y1, bg_img);                         /* background */

            /*yangyizheng 20101115 add begin*/
            button_area->button_press_down = item_index;
            /*yangyizheng 20101115 add end*/
            
            gdi_pop_and_restore_alpha_blending_source_layer();
        }
    }
    gdi_layer_pop_clip();
}

void wgui_cat9002_op02_button_unselect(wgui_cat9002_op02_button_area_struct *button_area)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 x1, x2, y1, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = button_area->selected_button_x;
    y1 = button_area->selected_button_y;

    x2 = x1 + button_area->button_width - 1;
    y2 = y1 + button_area->button_height - 1;

    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);

    //gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
    if(button_area->button_press_down > BUTTON_INVALID)
    {
        gdi_image_draw(x1, y1, get_image(wgui_cat9002_op02_button_image[button_area->button_press_down -1])); 
        button_area->button_press_down = BUTTON_INVALID;
    }
    gdi_layer_pop_clip();

}

extern void wgui_cat9002_op02_set_button1_hdlr(void (*handler) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat9002_op02_button1_handler = handler;
}

extern void wgui_cat9002_op02_set_button2_hdlr(void (*handler) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat9002_op02_button2_handler = handler;
}

extern void wgui_cat9002_op02_set_button3_hdlr(void (*handler) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat9002_op02_button3_handler = handler;
}
#endif /*__MMI_OP02_LEMEI__*/

