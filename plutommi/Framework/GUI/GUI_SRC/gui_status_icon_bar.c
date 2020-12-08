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
 * gui_status_icon_bar.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for status icon bars control.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#include "gui_status_icon.h"
#include "gui_status_icon_bar.h"

#include "MMIDataType.h"
#include "gdi_datatype.h"
#include "gdi_include.h"
#include "gui.h"
#include "gdi_const.h"
#include "gui_status_icon_bar_post_oem.h"
#include "kal_general_types.h"
#include "gui_typedef.h"

/****************************************************************************
 * Global variable
 ****************************************************************************/

void (*gui_status_icon_bar_show)(gui_status_icon_bar_struct *bar) = NULL;
void (*gui_status_icon_bar_arrange)(void) = NULL;
void (*gui_status_icon_bar_show_sublcd_horizontal_background)(S32 x1, S32 y1, S32 x2, S32 y2) = NULL;
void (*gui_status_icon_bar_hide)(gui_status_icon_bar_struct *bar) = NULL;


/****************************************************************************
 * Local Function
 ****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_setup_target_lcd_and_layer
 * DESCRIPTION
 *  Setup the target lcd, target layer and alpha blending(abm) layer for status icon bar
 * PARAMETERS
 *  bar       [IN]        Pointer to status icon bar struct
 * RETURNS
 *  The current target lcd handle
 *****************************************************************************/
gdi_handle gui_status_icon_bar_setup_target_lcd_and_layer(gui_status_icon_bar_struct *bar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_get_active(&old_lcd_handle);
#ifdef __MMI_SUBLCD__		
    if (bar->target_lcd == GDI_LCD_MAIN_LCD_HANDLE && old_lcd_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        UI_set_main_LCD_graphics_context();
    }
    else if (bar->target_lcd == GDI_LCD_SUB_LCD_HANDLE && old_lcd_handle == GDI_LCD_MAIN_LCD_HANDLE)
    {
        UI_set_sub_LCD_graphics_context();
    }
#endif

    if (bar->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_push_and_set_active(bar->target_layer);
    }

    if (bar->alpha_blend_layer != GDI_NULL_HANDLE)
    {
        gdi_push_and_set_alpha_blending_source_layer(bar->alpha_blend_layer);
    }

    return old_lcd_handle;
}


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_restore_target_lcd_and_layer
 * DESCRIPTION
 *  Restore the target layer, target lcd and alpha blending(abm) layer of status icon bar
 * PARAMETERS
 *  bar             [IN]        Pointer to status icon bar struct
 *  old_lcd_handle  [IN]        Old lcd handle
 * RETURNS
 *  void
 *****************************************************************************/
void gui_status_icon_bar_restore_target_lcd_and_layer(gui_status_icon_bar_struct *bar, gdi_handle old_lcd_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bar->alpha_blend_layer != NULL)
    {
        gdi_pop_and_restore_alpha_blending_source_layer();
    }

    if (bar->target_layer != NULL)
    {
        gdi_layer_pop_and_restore_active();
    }
#ifdef __MMI_SUBLCD__	
    if (bar->target_lcd == GDI_LCD_MAIN_LCD_HANDLE && old_lcd_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        UI_set_sub_LCD_graphics_context();
    }
    else if (bar->target_lcd == GDI_LCD_SUB_LCD_HANDLE && old_lcd_handle == GDI_LCD_MAIN_LCD_HANDLE)
    {
        UI_set_main_LCD_graphics_context();
    }
#endif
}


/****************************************************************************
 * Global Function
 ****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_initialize
 * DESCRIPTION
 *  Assign the function pointer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_status_icon_bar_initialize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_initialize_icon();
    gui_status_icon_bar_arrange = gui_status_icon_bar_arrange_oem;
    gui_status_icon_bar_show = gui_status_icon_bar_show_oem;
#ifdef __MMI_SUBLCD__
    gui_status_icon_bar_show_sublcd_horizontal_background = gui_status_icon_bar_show_sublcd_horizontal_background_oem;
#endif
    gui_status_icon_bar_hide = gui_status_icon_bar_hide_oem;
}


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_enable_display
 * DESCRIPTION
 *  Enable status icon bar display or not
 * PARAMETERS
 *  bar       [IN]        Pointer to status icon bar struct
 *  enable    [IN]        Enable status icon bar display or not
 * RETURNS
 *  void
 *****************************************************************************/
void gui_status_icon_bar_enable_display(gui_status_icon_bar_struct *bar, MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (enable)
    {
        bar->flags |= WGUI_STATUS_ICON_BAR_FLAG_BAR_DISPLAY;
    }
    else
    {
        bar->flags &= ~WGUI_STATUS_ICON_BAR_FLAG_BAR_DISPLAY;
    }
}



/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_enable_display
 * DESCRIPTION
 *  Enable status icon bar display or not
 * PARAMETERS
 *  bar       [IN]        Pointer to status icon bar struct
 *  enable    [IN]        Enable status icon bar display or not
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_status_icon_bar_is_display(gui_status_icon_bar_struct *bar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bar->flags & WGUI_STATUS_ICON_BAR_FLAG_BAR_DISPLAY)
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
 *  gui_status_icon_bar_enable_background
 * DESCRIPTION
 *  Enable status icon bar background or not
 * PARAMETERS
 *  bar       [IN]        Pointer to status icon bar struct
 *  enable    [IN]        Enable status icon bar background or not
 * RETURNS
 *  void
 *****************************************************************************/
void gui_status_icon_bar_enable_background(gui_status_icon_bar_struct *bar, MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (enable)
    {
        bar->flags &= ~WGUI_STATUS_ICON_BAR_FLAG_BAR_DISABLE_BACKGROUND;
    }
    else
    {
        bar->flags |= WGUI_STATUS_ICON_BAR_FLAG_BAR_DISABLE_BACKGROUND;
    }
}


#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__ 
/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_enable_special_style
 * DESCRIPTION
 *  Enable status icon bar background or not
 * PARAMETERS
 *  bar       [IN]        Pointer to status icon bar struct
 *  enable    [IN]        Enable status icon bar background or not
 * RETURNS
 *  void
 *****************************************************************************/
void gui_status_icon_bar_enable_special_style(gui_status_icon_bar_struct *bar, MMI_BOOL enable, MMI_BOOL transparent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (enable)
    {
        if (transparent)
        {
            bar->flags |= WGUI_STATUS_ICON_BAR_FLAG_BAR_SPECIAL_TRANSPARENT_STYLE;
        }
        else
        {
            bar->flags |= WGUI_STATUS_ICON_BAR_FLAG_BAR_SPECIAL_STYLE;
        }
    }
    else
    {
        bar->flags &= ~WGUI_STATUS_ICON_BAR_FLAG_BAR_SPECIAL_STYLE;
        bar->flags &= ~WGUI_STATUS_ICON_BAR_FLAG_BAR_SPECIAL_TRANSPARENT_STYLE;
    }
}

void gui_status_icon_bar_set_background_id(gui_status_icon_bar_struct *bar, S32 id)
{
    bar->bar_id = id;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_enable_rotate_for_wap
 * DESCRIPTION
 *  Enable status icon bar rotate or not for wap
 * PARAMETERS
 *  bar       [IN]        Pointer to status icon bar struct
 *  enable    [IN]        Enable status icon bar rotate or not
 * RETURNS
 *  void
 *****************************************************************************/
void gui_status_icon_bar_enable_rotate_for_wap(gui_status_icon_bar_struct *bar, MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bar->rotate_flag_for_wap = enable;
}


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_enable_double_buffer
 * DESCRIPTION
 *  Enable status icon bar double buffer or not
 * PARAMETERS
 *  bar       [IN]        Pointer to status icon bar struct
 *  enable    [IN]        Enable status icon bar double buffer or not
 * RETURNS
 *  void
 *****************************************************************************/
void gui_status_icon_bar_enable_double_buffer(gui_status_icon_bar_struct *bar, MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (enable)
    {
        bar->flags |= WGUI_STATUS_ICON_BAR_FLAG_BAR_DOUBLE_BUFFER;
    }
    else
    {
        bar->flags &= ~WGUI_STATUS_ICON_BAR_FLAG_BAR_DOUBLE_BUFFER;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_whether_double_buffer
 * DESCRIPTION
 *  To check whether double buffer flag set or not
 * PARAMETERS
 *  bar       [IN]        Pointer to status icon bar struct
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_status_icon_bar_whether_double_buffer(gui_status_icon_bar_struct *bar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bar->flags & WGUI_STATUS_ICON_BAR_FLAG_BAR_DOUBLE_BUFFER)
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
 *  gui_status_icon_bar_set_flag
 * DESCRIPTION
 *  Set the status icon bar's flag
 * PARAMETERS
 *  bar       [IN]        Pointer to status icon bar struct
 *  flag      [IN]        New flag of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_status_icon_bar_set_flag(gui_status_icon_bar_struct *bar, U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bar->flags = flag;
}


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_get_flag
 * DESCRIPTION
 *  Get the status icon bar's flag
 * PARAMETERS
 *  bar       [IN]        Pointer to status icon bar struct
 * RETURNS
 *  The flag of status icon bar
 *****************************************************************************/
U32 gui_status_icon_bar_get_flag(gui_status_icon_bar_struct *bar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return bar->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_set_target_lcd
 * DESCRIPTION
 *  Set the target lcd of status icon bar
 * PARAMETERS
 *  bar        [IN]         Pointer to status icon bar struct
 *  target_lcd [IN]         New target lcd of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_status_icon_bar_set_target_lcd(gui_status_icon_bar_struct *bar, gdi_handle target_lcd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bar->target_lcd = target_lcd;
}


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_get_target_lcd
 * DESCRIPTION
 *  Get the status icon bar's target lcd
 * PARAMETERS
 *  bar       [IN]        Pointer to status icon bar struct
 * RETURNS
 *  The target lcd of status icon bar
 *****************************************************************************/
gdi_handle gui_status_icon_bar_get_target_lcd(gui_status_icon_bar_struct *bar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return bar->target_lcd;
}


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_set_target_layer
 * DESCRIPTION
 *  Set the status icon bar's target layer
 * PARAMETERS
 *  bar             [IN]        Pointer to status icon bar struct
 *  target_layer    [IN]        New target layer of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_status_icon_bar_set_target_layer(gui_status_icon_bar_struct *bar, gdi_handle target_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bar->target_layer = target_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_get_target_layer
 * DESCRIPTION
 *  Get the status icon bar's target layer
 * PARAMETERS
 *  bar       [IN]        Pointer to status icon bar struct
 * RETURNS
 *  The target layer of status icon bar
 *****************************************************************************/
gdi_handle gui_status_icon_bar_get_target_layer(gui_status_icon_bar_struct *bar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return bar->target_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_set_alpha_blend_layer
 * DESCRIPTION
 *  Set the alpha blending(abm) layer of status icon bar
 * PARAMETERS
 *  bar                 [IN]        Pointer to status icon bar struct
 *  alpha_blend_layer   [IN]        New alpha blending(abm) layer of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_status_icon_bar_set_alpha_blend_layer(gui_status_icon_bar_struct *bar, gdi_handle alpha_blend_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bar->alpha_blend_layer = alpha_blend_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_get_alpha_blend_layer
 * DESCRIPTION
 *  Get status icon bar's alpha blending(abm) layer;
 * PARAMETERS
 *  bar       [IN]        Pointer to status icon bar struct
 * RETURNS
 *  void
 *****************************************************************************/
gdi_handle gui_status_icon_bar_get_alpha_blend_layer(gui_status_icon_bar_struct *bar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return bar->alpha_blend_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_set_clip
 * DESCRIPTION
 *  Set the status icon bar's clip
 * PARAMETERS
 *  bar         [IN]        Pointer to status icon bar struct
 *  x1          [IN]        The x coordinate of left-top corner
 *  y1          [IN]        The y coordinate of left-top corner
 *  x2          [IN]        The x coordinate of right-bottom corner
 *  y2          [IN]        The y coordinate of right-bottom corner
 * RETURNS
 *  void
 *****************************************************************************/
void gui_status_icon_bar_set_clip(gui_status_icon_bar_struct *bar, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bar->x1 = x1;
    bar->x2 = x2;
    bar->y1 = y1;
    bar->y2 = y2;
}


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_get_clip
 * DESCRIPTION
 *  Get the status icon bar clip range
 * PARAMETERS
 *  bar         [IN]        Pointer to status icon bar struct
 *  x1          [OUT]       Pointer to restore the x coordinate of left-top corner
 *  y1          [OUT]       Pointer to restore the y coordinate of left-top corner
 *  x2          [OUT]       Pointer to restore the x coordinate of right-bottom corner
 *  y2          [OUT]       Pointer to restore the y coordinate of right-bottom corner
 * RETURNS
 *  void
 *****************************************************************************/
void gui_status_icon_bar_get_clip(gui_status_icon_bar_struct *bar, S32 *x1, S32 *y1, S32 *x2, S32 *y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *x1 = bar->x1;
    *y1 = bar->y1;
    *x2 = bar->x2;
    *y2 = bar->y2;
}


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_move
 * DESCRIPTION
 *  Move the status icon bar
 * PARAMETERS
 *  bar         [IN]        Pointer to status icon bar struct
 *  x           [IN]        New x coordinate of status icon bar
 *  y           [IN]        New y coordinate of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_status_icon_bar_move(gui_status_icon_bar_struct *bar, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bar->x = x;
    bar->y = y;
}


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_resize
 * DESCRIPTION
 *  Resize the status icon bar
 * PARAMETERS
 *  bar         [IN]        Pointer to status icon bar struct
 *  width       [IN]        New width of status icon bar
 *  height      [IN]        New height of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_status_icon_bar_resize(gui_status_icon_bar_struct *bar, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bar->width = width;
    bar->height = height;
}


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_register_hide_callback
 * DESCRIPTION
 *  Register hide callback function of status icon bar
 * PARAMETERS
 *  bar             [IN]        Pointer to status icon bar struct
 *  hide_callback   [IN]        New hide callback function of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_status_icon_bar_register_hide_callback(gui_status_icon_bar_struct *bar, void (*hide_callback)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bar->hide_callback = hide_callback;
}


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_close
 * DESCRIPTION
 *  Close the status icon bar
 * PARAMETERS
 *  bar       [IN]        Pointer to status icon bar struct
 * RETURNS
 *  void
 *****************************************************************************/
void gui_status_icon_bar_close(gui_status_icon_bar_struct *bar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bar->target_layer = GDI_NULL_HANDLE;
    bar->alpha_blend_layer = GDI_NULL_HANDLE;
}

/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_register_IME_callback
 * DESCRIPTION
 *  Register IME callback of status icon bar
 * PARAMETERS
 *  bar             [IN]        Pointer to status icon bar struct
 *  IME_callback    [IN]        The new IME callback of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_status_icon_bar_register_IME_callback(gui_status_icon_bar_struct *bar, void (*IME_callback)(S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bar->IME_callback = IME_callback;
}


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_reset_IME_callback
 * DESCRIPTION
 *  Reset IME callback of status icon bar
 * PARAMETERS
 *  bar             [IN]        Pointer to status icon bar struct
 * RETURNS
 *  void
 *****************************************************************************/
void gui_status_icon_bar_reset_IME_callback(gui_status_icon_bar_struct *bar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bar->IME_callback = NULL;
}



