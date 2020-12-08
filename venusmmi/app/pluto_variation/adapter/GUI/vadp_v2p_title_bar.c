/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vadp_v2p_title_bar.c
 *
 * Project:
 * --------
 *  Venus UI Components
 *
 * Description:
 * ------------
 *  This file provides the adaptation functions from the Venus MMI to 
 *  the Pluto title bar components
 *
 *      Venus ---> v2p adaptor ---> Pluto 
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *****************************************************************************/

 /* Pluto headers */
#include "MMI_features.h"
#include "MMI_include.h"
#include "wgui_title.h"

/* Venus headers */
#include "vadp_v2p_title_bar.h"

#include "MMIDataType.h"
#include "gui.h"
#include "gui_title.h"
#include "gui_title_pre_oem.h"
#include "kal_general_types.h"
#include "wgui_categories_util.h"
#include "gdi_include.h"
#include "gdi_const.h"
#include "CustDataRes.h"
#include "wgui_include.h"
#include "gdi_datatype.h"
#include "lcd_sw_inc.h"
#include "Gui_Setting.h"
#include "gui_switch.h"
#include "wgui.h"


/**********************************************************************
 * Local Functions
 **********************************************************************/

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_show_title_background
 * DESCRIPTION
 *  Adaption api of changing the text of title
 * PARAMETERS
 *  text        [IN]    New text of title
 * RETURNS
 *  void 
 *****************************************************************************/
static void vadp_v2p_show_title_background(S32 x, S32 y, S32 w, S32 h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_push_clip();
    gui_set_clip(x, y, x + w - 1, y + h - 1);
    
    /* modified to support wallpaper on bottom */
    if (!(g_wgui_title_bar.style & GUI_TITLE_STYLE_DISABLEBG))
    {
        if (wgui_is_wallpaper_on_bottom() == MMI_TRUE)
        {
            gdi_draw_solid_rect(x, y, x + w - 1, y + h - 1, GDI_COLOR_TRANSPARENT);  /* 061705 Calvin added */
        }
        else
        {
            gdi_draw_solid_rect(x, y, x + w - 1, y + h - 1, GDI_COLOR_WHITE);        /* 090605 Title Calvin added */
        }
        
        if (title_bg_id != 0)
        {
            gdi_image_draw_id(x, y, title_bg_id);
        }
        else
        {
            gui_draw_filled_area(x, y, x + w - 1, y + h - 1, g_wgui_title_bar.active_filler);
        }
#ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__
        if (gui_title_is_animation_enabled(g_wgui_title_bar))
        {
            if (g_wgui_title_bar.animated_style == MMI_UI_TITLE_IMAGE_ANIMATE_NONE)
            {
                gui_title_show_animate_image_frame_0(g_wgui_title_bar, x, y, x + w - 1, y + h - 1);
            }
            if (g_wgui_title_bar.animated_style == MMI_UI_TITLE_IMAGE_ANIMATE_ONCE && g_wgui_title_bar.current_frame_count == -1)
            {
                gui_title_show_animate_image_frame_0(g_wgui_title_bar, x, y, x + w - 1, y + h - 1);
            }
            else
            {
                gui_title_show_animate_image(g_wgui_title_bar, x, y, x + w - 1, y + h - 1);
            }
        }
#endif /* __MMI_UI_ANIMATED_TITLE_EFFECT__ */
    }
    else
    {
        gdi_draw_solid_rect(x, y, x + w - 1, y + h - 1, GDI_COLOR_TRANSPARENT);
    }
    gui_pop_clip();
}


/**********************************************************************
 * Global Functions
 **********************************************************************/

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_change_title_bar_text
 * DESCRIPTION
 *  Adaption api of changing the text of title
 * PARAMETERS
 *  text        [IN]    New text of title
 * RETURNS
 *  void 
 *****************************************************************************/
 void vadp_v2p_change_title_bar_text(U8* text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_change(NULL, NULL, text, WGUI_TITLE_CHANGE_TEXT);
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_change_title_bar_left_icon
 * DESCRIPTION
 *  Adaption api of changeing the left icon of title
 * PARAMETERS
 *  image_id        [IN]    New left icon of title
 * RETURNS
 *  void 
 *****************************************************************************/
 void vadp_v2p_change_title_bar_left_icon(U16 image_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_change(image_id, NULL, NULL, WGUI_TITLE_CHANGE_ICON);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_change_title_bar_right_icon
 * DESCRIPTION
 *  Adaption api of changing right icon of title
 * PARAMETERS
 *  image_id        [IN]    New right icon of title
 * RETURNS
 *  void 
 *****************************************************************************/
 void vadp_v2p_change_title_bar_right_icon(U16 image_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_change(NULL, image_id, NULL, WGUI_TITLE_CHANGE_ICON2);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_enabel_integrate_title
 * DESCRIPTION
 *  Adaption api of enable integrate title or not
 * PARAMETERS
 *  enable        [IN]    Enable integrate title or not
 * RETURNS
 *  void 
 *****************************************************************************/
 void vadp_v2p_enable_integrate_title(MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_enable_integrated(enable);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_enable_shortcut_display
 * DESCRIPTION
 *  Adaption api of enable shortcut display or not
 * PARAMETERS
 *  enable        [IN]    Enable shortcut display or not
 * RETURNS
 *  void 
 *****************************************************************************/
 void vadp_v2p_enable_shortcut_display(MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL no_shct = !enable;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_set_no_icon_shct(no_shct);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_start_title_bar_scroll
 * DESCRIPTION
 *  Adaption api of start scroll for title
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
 void vadp_v2p_start_title_bar_scroll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_start_scrolling();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_stop_title_bar_scroll
 * DESCRIPTION
 *  Adaption api of stop scroll for title
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
 void vadp_v2p_stop_title_bar_scroll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_stop_scrolling();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_create_title_bar
 * DESCRIPTION
 *  Adaption api of create title
 * PARAMETERS
 *  text        [IN]    New text of title
 * RETURNS
 *  void 
 *****************************************************************************/
 void vadp_v2p_create_title_bar(
    void(*update_screen_callback)(void *handle), 
    void *update_screen_handle,
    gdi_handle target_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_create_ex(GDI_NULL_HANDLE, target_layer, GDI_NULL_HANDLE);
    wgui_title_register_hide_callback(vadp_v2p_show_title_background);
#ifdef __MMI_VUI_ENGINE__
    wgui_title_register_venus_update_screen(update_screen_callback, update_screen_handle);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_close_title_bar
 * DESCRIPTION
 *  Adaption api of close title
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
 void vadp_v2p_close_title_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_close();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_show_title_bar
 * DESCRIPTION
 *  Adaption api of show title
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
 void vadp_v2p_show_title_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_set_wallpaper_on_bottom(MMI_TRUE);
    wgui_title_show(GUI_TITLE_PART_ALL);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_get_title_bar_prefered_size
 * DESCRIPTION
 *  Adaption api of get title bar prefered size
 * PARAMETERS
 *  width       [OUT]   Pointer to store the width of title
 *  height      [OUT]   Pointer to store teh height of title
 * RETURNS
 *  void 
 *****************************************************************************/
 void vadp_v2p_get_title_bar_prefered_size(S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *width = MAIN_LCD_DEVICE_WIDTH;
    *height = MMI_TITLE_HEIGHT;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_move_title_bar
 * DESCRIPTION
 *  Adaption api of move title bar
 * PARAMETERS
 *  x           [IN]   The x coordinate of title
 *  y           [IN]   The y coordinate of title
 * RETURNS
 *  void 
 *****************************************************************************/
 void vadp_v2p_move_title_bar(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_move(x, y);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_resize_title_bar
 * DESCRIPTION
 *  Adaption api of resize title bar
 * PARAMETERS
 *  width       [IN]   The widht of title
 *  height      [IN]   The height of title
 * RETURNS
 *  void 
 *****************************************************************************/
 void vadp_v2p_resize_title_bar(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_resize(width, height);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_get_title_string
 * DESCRIPTION
 *  Get title's string
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
U8* vadp_v2p_get_title_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wgui_title_get_string();
}


