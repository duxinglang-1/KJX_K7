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
 *  gui_scrollbars.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  UI component - Scrollbar & Progress Indicator
 *
 *  o Vertical scrollbar
 *  o Horizontal scrollbar 
 *  o Vertical Progress Indicator 
 *  o Horizontal Progress Indicator
 *  o Alternative Vertical Slider
 *  o Alternative Horizontal Slider
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

#include "MMI_features.h"
#include "gui_scrollbars.h"
#include "wgui_categories_defs.h"
#include "gdi_include.h"
#include "mmi_frm_gprot.h"
#include "wgui_draw_manager.h"
#include "wgui_categories_util.h"
#include "gui_touch_feedback.h"

#include "CustThemesRes.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "gui_typedef.h"
#include "gui_scrollbars_post_oem.h"
#include "gui.h"
#include "gui_theme_struct.h"
#include "gui_buttons.h"
#include "gui_data_types.h"
#include "gdi_datatype.h"
#include "string.h"
#include "gdi_const.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_input_gprot.h"


extern MMI_theme *current_MMI_theme;


/*****************************************************************************
 * FUNCTION
 *  gui_setup_target_lcd_and_layer
 * DESCRIPTION
 *  setup UI target lcd, target layer and alpha blend layer
 * PARAMETERS
 *  target_lcd            [IN]        The object target_lcd
 *  target_layer          [IN]
 *  alpha_blend_layer  [IN]
 * RETURNS
 *  void
 *****************************************************************************/
gdi_handle gui_setup_target_lcd_and_layer(gdi_handle target_lcd, gdi_handle target_layer, gdi_handle alpha_blend_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_get_active(&old_lcd_handle);

    if(target_lcd == GDI_LCD_SUB_LCD_HANDLE && old_lcd_handle == GDI_LCD_MAIN_LCD_HANDLE)
    {
        UI_set_sub_LCD_graphics_context();
    }
    if(target_lcd == GDI_LCD_MAIN_LCD_HANDLE && old_lcd_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        UI_set_main_LCD_graphics_context();
    }
    if(target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_push_and_set_active(target_layer);
    }
    if(alpha_blend_layer != GDI_NULL_HANDLE)
    {
        gdi_push_and_set_alpha_blending_source_layer(alpha_blend_layer);
    }

    return old_lcd_handle;

}

/*****************************************************************************
 * FUNCTION
 *  gui_restore_target_lcd_and_layer
 * DESCRIPTION
 *  restore UI target lcd, target layer and alpha blend layer
 * PARAMETERS
 *  target_lcd            [IN]        The object target_lcd
 *  target_layer          [IN]
 *  alpha_blend_layer  [IN]
 *  old_lcd_handle      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_restore_target_lcd_and_layer(gdi_handle target_lcd, gdi_handle target_layer, gdi_handle alpha_blend_layer, gdi_handle old_lcd_handle)
{  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(alpha_blend_layer != GDI_NULL_HANDLE)
    {
        gdi_pop_and_restore_alpha_blending_source_layer();
    }
    if(target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }
    if(target_lcd == GDI_LCD_SUB_LCD_HANDLE && old_lcd_handle == GDI_LCD_MAIN_LCD_HANDLE)
    {
        UI_set_main_LCD_graphics_context();
    }
    if(target_lcd == GDI_LCD_MAIN_LCD_HANDLE && old_lcd_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        UI_set_sub_LCD_graphics_context();
    }
}


MMI_BOOL gui_scrollbar_redraw_clip_enable = MMI_TRUE;


/***************************************************************************** 
 * General Scrollbar Utility Functions
 *****************************************************************************/

/* 
 * Custom-draw function for scrollbar. 
 * We do not use image because scrollbar may have different width
 */


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_scrollbar_get_button_height
 * DESCRIPTION
 *  Get veritcal scrollbar's button height
 * PARAMETERS
 *  v       [IN/OUT]        Is the vertical scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
static S32 gui_vertical_scrollbar_get_button_height(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 button_height;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*---------------------------------------------------------------*/
    button_height = 0;
    if(v->style & GUI_SCROLLBAR_STYLE_WIDER)
    {
    #if defined(UI_SCROLLBAR_WIDER_STYLE_1)
        button_height = v->width;
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_2) 
        button_height = gui_scrollbar_get_button_min_size(GUI_SCROLLBAR_BUTTON_UP, v->width);
        if (button_height * 2 >=  v->height - GUI_SCROLLBAR_INDICATOR_MIN_HEIGHT_STYLE2)
        {
            button_height = 0;
        }
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_3) 
        button_height = gui_scrollbar_get_button_min_size(GUI_SCROLLBAR_BUTTON_UP, v->width);
        if (button_height * 2 >=  v->height - GUI_SCROLLBAR_INDICATOR_MIN_HEIGHT_STYLE3)
        {
            button_height = 0;
        }
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_5) 
        button_height = gui_scrollbar_get_button_min_size(GUI_SCROLLBAR_BUTTON_UP, v->width);
        if (button_height * 2 >=  v->height - GUI_SCROLLBAR_INDICATOR_MIN_HEIGHT_STYLE5)
        {
            button_height = 0;
        }
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_4) && defined(__MMI_TOUCH_SCREEN__)
        #if defined (__MMI_MAINLCD_128X160__)
            button_height = v->width + 2;
        #else
            button_height = v->width - GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4 * 2 + 3;
        #endif
        if (button_height * 2 >=  v->height - GUI_SCROLLBAR_INDICATOR_MIN_HEIGHT_STYLE4)
        {
            button_height = 0;
        } 
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_6) && defined(__MMI_TOUCH_SCREEN__)
        #if defined (__MMI_MAINLCD_128X160__)
            button_height = v->width + 2;
        #else
            button_height = v->width - GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE6 * 2 + 3;
        #endif
        if (button_height * 2 >=  v->height - GUI_SCROLLBAR_INDICATOR_MIN_HEIGHT_STYLE6)
        {
            button_height = 0;
        } 
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_7) || defined(UI_SCROLLBAR_STYLE_8)
        button_height = 0;
    #endif 
    }
    else
    {
    #if defined(UI_SCROLLBAR_STYLE_1)
        button_height = v->width;
    #elif defined(UI_SCROLLBAR_STYLE_2) 
        button_height = gui_scrollbar_get_button_min_size(GUI_SCROLLBAR_BUTTON_UP, v->width);
        if (button_height * 2 >=  v->height - GUI_SCROLLBAR_INDICATOR_MIN_HEIGHT_STYLE2)
        {
            button_height = 0;
        }
    #elif defined(UI_SCROLLBAR_STYLE_3) 
        button_height = gui_scrollbar_get_button_min_size(GUI_SCROLLBAR_BUTTON_UP, v->width);
        if (button_height * 2 >=  v->height - GUI_SCROLLBAR_INDICATOR_MIN_HEIGHT_STYLE3)
        {
            button_height = 0;
        }
    #elif defined(UI_SCROLLBAR_STYLE_5) 
        button_height = gui_scrollbar_get_button_min_size(GUI_SCROLLBAR_BUTTON_UP, v->width);
        if (button_height * 2 >=  v->height - GUI_SCROLLBAR_INDICATOR_MIN_HEIGHT_STYLE5)
        {
            button_height = 0;
        }
    #elif defined(UI_SCROLLBAR_STYLE_4) && defined(__MMI_TOUCH_SCREEN__)
        #if defined (__MMI_MAINLCD_128X160__)
            button_height = v->width + 2;
        #else
            button_height = v->width - GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4 * 2 + 3;
        #endif
        if (button_height * 2 >=  v->height - GUI_SCROLLBAR_INDICATOR_MIN_HEIGHT_STYLE4)
        {
            button_height = 0;
        } 
    #elif defined(UI_SCROLLBAR_STYLE_6) && defined(__MMI_TOUCH_SCREEN__)
        #if defined (__MMI_MAINLCD_128X160__)
            button_height = v->width + 2;
        #else
            button_height = v->width - GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE6 * 2 + 3;
        #endif
        if (button_height * 2 >=  v->height - GUI_SCROLLBAR_INDICATOR_MIN_HEIGHT_STYLE6)
        {
            button_height = 0;
        }   
    #elif defined(UI_SCROLLBAR_STYLE_7) || defined(UI_SCROLLBAR_STYLE_8)|| defined(UI_SCROLLBAR_STYLE_9)
        button_height = 0;
    #endif 
    }

    return button_height;
}


/*****************************************************************************
 * FUNCTION
 *  gui_scrollbar_get_button_min_size
 * DESCRIPTION
 *  Show vertical scrollbar
 * PARAMETERS
 *  v       [IN/OUT]        Is the vertical scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
S32 gui_scrollbar_get_button_min_size(gui_scrollbar_buttton_enum type, S32 bar_width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*---------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
    #if defined(UI_SCROLLBAR_WIDER_STYLE_2)
        ret = gui_scrollbar_get_button_min_size_style_2(type, bar_width);
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_3)
        ret = gui_scrollbar_get_button_min_size_style_3(type, bar_width);
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_4)
        ret = gui_scrollbar_get_button_min_size_style_4(type, bar_width);
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_5)
        ret = gui_scrollbar_get_button_min_size_style_5(type, bar_width);
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_6)
        ret = gui_scrollbar_get_button_min_size_style_6(type, bar_width);
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_7)
        ret = gui_scrollbar_get_button_min_size_style_7(type, bar_width);
    #endif
#else /* __MMI_FTE_SUPPORT__ */
    #if defined(UI_SCROLLBAR_STYLE_2)
        ret = gui_scrollbar_get_button_min_size_style_2(type, bar_width);
    #elif defined(UI_SCROLLBAR_STYLE_3)
        ret = gui_scrollbar_get_button_min_size_style_3(type, bar_width);
    #elif defined(UI_SCROLLBAR_STYLE_4)
        ret = gui_scrollbar_get_button_min_size_style_4(type, bar_width);
    #elif defined(UI_SCROLLBAR_STYLE_5)
        ret = gui_scrollbar_get_button_min_size_style_5(type, bar_width);
    #elif defined(UI_SCROLLBAR_STYLE_6)
        ret = gui_scrollbar_get_button_min_size_style_6(type, bar_width);
    #elif defined(UI_SCROLLBAR_STYLE_7)
        ret = gui_scrollbar_get_button_min_size_style_7(type, bar_width);
    #elif defined(UI_SCROLLBAR_STYLE_8)
        ret = gui_scrollbar_get_button_min_size_style_8(type, bar_width);
    #elif defined(UI_SCROLLBAR_STYLE_9)
        ret = gui_scrollbar_get_button_min_size_style_9(type, bar_width);
    #endif
#endif /* __MMI_FTE_SUPPORT__ */
  
    return ret;
}


/***************************************************************************** 
 * Vertical Scrollbar
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_scrollbar_show
 * DESCRIPTION
 *  Show vertical scrollbar
 * PARAMETERS
 *  v       [IN/OUT]        Is the vertical scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_vertical_scrollbar(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
    if(v->style & GUI_SCROLLBAR_STYLE_WIDER)
    {
    #if defined(UI_SCROLLBAR_WIDER_STYLE_1)
        gui_show_vertical_scrollbar_style_1(v);
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_2)
        gui_show_vertical_scrollbar_style_2(v);
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_3)
        gui_show_vertical_scrollbar_style_3(v);
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_4)
        gui_show_vertical_scrollbar_style_4(v);
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_5)
        gui_show_vertical_scrollbar_style_5(v);
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_6)
        gui_show_vertical_scrollbar_style_6(v);
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_7)
        gui_show_vertical_scrollbar_style_7(v);
    #endif /* UI_SCROLLBAR_STYLE_1 */
    }
    else
    {
#endif /* __MMI_FTE_SUPPORT__ */    
    #if defined(UI_SCROLLBAR_STYLE_1)
        gui_show_vertical_scrollbar_style_1(v);
    #elif defined(UI_SCROLLBAR_STYLE_2)
        gui_show_vertical_scrollbar_style_2(v);
    #elif defined(UI_SCROLLBAR_STYLE_3)
        gui_show_vertical_scrollbar_style_3(v);
    #elif defined(UI_SCROLLBAR_STYLE_4)
        gui_show_vertical_scrollbar_style_4(v);
    #elif defined(UI_SCROLLBAR_STYLE_5)
        gui_show_vertical_scrollbar_style_5(v);
    #elif defined(UI_SCROLLBAR_STYLE_6)
        gui_show_vertical_scrollbar_style_6(v);
    #elif defined(UI_SCROLLBAR_STYLE_7)
        gui_show_vertical_scrollbar_style_7(v);
    #elif defined(UI_SCROLLBAR_STYLE_8)
        gui_show_vertical_scrollbar_style_VFR(v);
    #elif defined(UI_SCROLLBAR_STYLE_9)
        gui_show_vertical_scrollbar_style_9(v);
    #endif /* UI_SCROLLBAR_STYLE_1 */
#ifdef __MMI_FTE_SUPPORT__
    } 
#endif /* __MMI_FTE_SUPPORT__ */    
}


/*****************************************************************************
 * FUNCTION
 *  gui_redraw_vertical_scrollbar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_redraw_vertical_scrollbar(vertical_scrollbar *v, MMI_BOOL blt_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x, offset_y;
    S32 current_x1, current_y1, current_x2, current_y2;
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = v->x;
    x2 = x1 + v->width - 1;
    y1 = v->y;
    y2 = y1 + v->height -1;
    gui_lock_double_buffer();
    gui_show_vertical_scrollbar(v);
    gui_unlock_double_buffer();
    //get target layer positon
    if (v->target_layer)
    {
        gdi_layer_push_and_set_active(v->target_layer);
    }
    gdi_layer_get_position(&offset_x, &offset_y);
    if (v->target_layer)
    {
        gdi_layer_pop_and_restore_active();
    }
    if (!blt_all && !gui_scrollbar_redraw_clip_enable)
    {
         gdi_layer_get_clip(&current_x1, &current_y1, &current_x2, &current_y2);

        if ((x1 > current_x2) || (y1 > current_y2) ||(x2 < current_x1) || (y2 < current_y1))
        {
            return;
        }

        if (x1 < current_x1)
        {
            x1 = current_x1;
        }

        if (y1 < current_y1)
        {
            y1 = current_y1;
        }

        if (x2 > current_x2)
        {
            x2 = current_x2;
        }

        if (y2 > current_y2)
        {
            y2 = current_y2;
        }
    }
    gui_BLT_double_buffer(
        x1 + offset_x,
        y1 + offset_y,
        x2 + offset_x,
        y2 + offset_y);
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_scrollbar_show
 * DESCRIPTION
 *  Show vertical scrollbar
 * PARAMETERS
 *  v       [IN/OUT]        Is the vertical scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vertical_scrollbar_redraw_button(vertical_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
    if(v->style & GUI_SCROLLBAR_STYLE_WIDER)
    {
    #if defined(UI_SCROLLBAR_WIDER_STYLE_1)
        gui_vertical_scrollbar_redraw_button_style_1(v, type, pressed);
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_2)
        gui_vertical_scrollbar_redraw_button_style_2(v, type, pressed);
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_3)
        gui_vertical_scrollbar_redraw_button_style_3(v, type, pressed);
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_4)
        gui_vertical_scrollbar_redraw_button_style_4(v, type, pressed);
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_5)
        gui_vertical_scrollbar_redraw_button_style_5(v, type, pressed);
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_6)
        gui_vertical_scrollbar_redraw_button_style_6(v, type, pressed);
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_7)
        gui_vertical_scrollbar_redraw_button_style_7(v, type, pressed);
    #endif /* UI_SCROLLBAR_STYLE_1 */
    }
    else
    {
#endif /* __MMI_FTE_SUPPORT__ */         
    #if defined(UI_SCROLLBAR_STYLE_1)
        gui_vertical_scrollbar_redraw_button_style_1(v, type, pressed);
    #elif defined(UI_SCROLLBAR_STYLE_2)
        gui_vertical_scrollbar_redraw_button_style_2(v, type, pressed);
    #elif defined(UI_SCROLLBAR_STYLE_3)
        gui_vertical_scrollbar_redraw_button_style_3(v, type, pressed);
    #elif defined(UI_SCROLLBAR_STYLE_4)
        gui_vertical_scrollbar_redraw_button_style_4(v, type, pressed);
    #elif defined(UI_SCROLLBAR_STYLE_5)
        gui_vertical_scrollbar_redraw_button_style_5(v, type, pressed);
    #elif defined(UI_SCROLLBAR_STYLE_6)
        gui_vertical_scrollbar_redraw_button_style_6(v, type, pressed);
    #elif defined(UI_SCROLLBAR_STYLE_7)
        gui_vertical_scrollbar_redraw_button_style_7(v, type, pressed);
    #elif defined(UI_SCROLLBAR_STYLE_8)
        gui_vertical_scrollbar_redraw_button_style_VFR(v, type, pressed);
    #elif defined(UI_SCROLLBAR_STYLE_9)
        gui_vertical_scrollbar_redraw_button_style_9(v, type, pressed);
    #endif /* UI_SCROLLBAR_STYLE_1 */
#ifdef __MMI_FTE_SUPPORT__
    }
#endif /* __MMI_FTE_SUPPORT__ */    
}


UI_vertical_scrollbar_theme *current_vertical_scrollbar_theme = NULL;

/*****************************************************************************
 * FUNCTION
 *  gui_set_vertical_scrollbar_current_theme
 * DESCRIPTION
 *  Applies the current theme for the vertical scrollbar
 * PARAMETERS
 *  v       [IN/OUT]        Is the vertical scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_vertical_scrollbar_current_theme(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->focussed_bar_filler = current_vertical_scrollbar_theme->focussed_bar_filler;
    v->normal_bar_filler = current_vertical_scrollbar_theme->normal_bar_filler;
    v->disabled_bar_filler = current_vertical_scrollbar_theme->disabled_bar_filler;
    gui_set_icon_button_BG_theme(&v->up_button, current_vertical_scrollbar_theme->up_button_theme);
    gui_set_icon_button_BG_theme(&v->down_button, current_vertical_scrollbar_theme->down_button_theme);
    gui_set_icon_button_BG_theme(&v->scroll_button, current_vertical_scrollbar_theme->scroll_button_theme);
    gui_icon_button_set_icon(
        &v->up_button,
        current_vertical_scrollbar_theme->up_button_icon,
        UI_DEFAULT_TRANSPARENT_COLOR);
    gui_icon_button_set_icon(
        &v->down_button,
        current_vertical_scrollbar_theme->down_button_icon,
        UI_DEFAULT_TRANSPARENT_COLOR);
    gui_icon_button_set_icon(
        &v->scroll_button,
        current_vertical_scrollbar_theme->scroll_button_icon,
        UI_DEFAULT_TRANSPARENT_COLOR);
    v->flags |= current_vertical_scrollbar_theme->flags;
    if (v->flags & UI_VERTICAL_SCROLLBAR_BUTTON_SHIFT1)
    {
        v->up_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        v->down_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
    }
    else if (v->flags & UI_VERTICAL_SCROLLBAR_BUTTON_SHIFT2)
    {
        v->up_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        v->down_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
    }
    else
    {
        v->up_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        v->down_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        v->up_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        v->down_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_vertical_scrollbar_theme
 * DESCRIPTION
 *  Applies the given theme to the vertical scrollbar
 * PARAMETERS
 *  v       [IN/OUT]            Is the vertical scrollbar object
 *  t       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_vertical_scrollbar_theme(vertical_scrollbar *v, UI_vertical_scrollbar_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->focussed_bar_filler = t->focussed_bar_filler;
    v->normal_bar_filler = t->normal_bar_filler;
    v->disabled_bar_filler = t->disabled_bar_filler;
    gui_set_icon_button_BG_theme(&v->up_button, t->up_button_theme);
    gui_set_icon_button_BG_theme(&v->down_button, t->down_button_theme);
    gui_set_icon_button_BG_theme(&v->scroll_button, t->scroll_button_theme);
    gui_icon_button_set_icon(&v->up_button, t->up_button_icon, UI_DEFAULT_TRANSPARENT_COLOR);
    gui_icon_button_set_icon(&v->down_button, t->down_button_icon, UI_DEFAULT_TRANSPARENT_COLOR);
    gui_icon_button_set_icon(&v->scroll_button, t->scroll_button_icon, UI_DEFAULT_TRANSPARENT_COLOR);
    v->flags |= t->flags;
    if (v->flags & UI_VERTICAL_SCROLLBAR_BUTTON_SHIFT1)
    {
        v->up_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        v->down_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
    }
    else if (v->flags & UI_VERTICAL_SCROLLBAR_BUTTON_SHIFT2)
    {
        v->up_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        v->down_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
    }
    else
    {
        v->up_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        v->down_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        v->up_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        v->down_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
    }
}

extern void gui_set_current_ptr(horizontal_scrollbar *h, vertical_scrollbar *v);

/*****************************************************************************
 * FUNCTION
 *  gui_create_vertical_scrollbar_ex
 * DESCRIPTION
 *  Creates a vertical scrollbar
 * PARAMETERS
 *  v                   [IN/OUT]    Is the vertical scrollbar object (pre-allocated)
 *  x                   [IN]        Is the left-top corner
 *  y                   [IN]        Is the left-top corner
 *  width               [IN]        Is the width of the vertical scrollbar (smaller)
 *  height              [IN]        Is the height of the vertical scrollbar (larger)
 *  target_layer        [IN]        Is the target layer of the vertical scrollbar
 *  target_lcd          [IN]        Is the target lcd of the vertical scrollbar 
 *  alpha blend layer   [IN]        Is the alpha blend layer of the vertical scrollbar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_vertical_scrollbar_ex(
        vertical_scrollbar *v, 
        S32 x, 
        S32 y, 
        S32 width, 
        S32 height, 
        U32 style,
        gdi_handle target_lcd, 
        gdi_handle target_layer,
        gdi_handle alpha_blend_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 button_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->x = x;
    v->y = y;
    v->width = width;
    v->height = height;
    v->value = 0;
    v->range = 0;
    v->flags = 0;
    v->target_lcd = target_lcd;
    v->target_layer = target_layer;
    v->alpha_blend_layer = alpha_blend_layer;
    v->hide_callback = NULL;
    v->style = style;
    button_height = 0;

    gui_set_current_ptr(NULL, v);

    button_height = gui_vertical_scrollbar_get_button_height(v);
    
    gui_create_icon_button(
        &v->up_button,
        v->x,
        v->y,
        v->width,
        button_height,
        current_vertical_scrollbar_theme->up_button_icon);
    gui_create_icon_button(
        &v->down_button,
        v->x,
        v->y + v->height - button_height,
        v->width,
        button_height,
        current_vertical_scrollbar_theme->down_button_icon);
    
    /* height of scroll button is set later */
    gui_create_icon_button(
        &v->scroll_button,
        v->x,
        v->y + v->up_button.height,
        v->width,
        v->width,
        current_vertical_scrollbar_theme->scroll_button_icon);
    gui_set_vertical_scrollbar_current_theme(v);

#if defined(UI_SCROLLBAR_STYLE_6)
    v->flags |= UI_VERTICAL_SCROLLBAR_AUTO_HIDE_SCROLL_BUTTON;
#endif

#ifdef __MMI_FTE_SUPPORT__
    if(v->style & GUI_SCROLLBAR_STYLE_DEFAULT)
    {
        v->flags |= UI_VERTICAL_SCROLLBAR_AUTO_HIDE_SCROLL_BUTTON;
    }
    v->flags |= UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS;
#endif

#ifdef __MMI_TOUCH_SCREEN__
    v->min_pen_offset = 1;
    v->pen_self_scroll = 1;
    v->get_diff = NULL;
    memset(&(v->pen_state), 0, sizeof(gui_scrollbar_pen_state_struct));
#endif /* __MMI_TOUCH_SCREEN__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_vertical_scrollbar
 * DESCRIPTION
 *  Creates a vertical scrollbar
 * PARAMETERS
 *  v           [IN/OUT]    Is the vertical scrollbar object (pre-allocated)
 *  x           [IN]        Is the left-top corner
 *  y           [IN]        Is the left-top corner
 *  width       [IN]        Is the width of the vertical scrollbar (smaller)
 *  height      [IN]        Is the height of the vertical scrollbar (larger)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_vertical_scrollbar(vertical_scrollbar *v, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
		//bwl_dbg_print("gui_create_vertical_scrollbar width = %d",width);
    gui_create_vertical_scrollbar_ex(v, x, y, 0, height, GUI_SCROLLBAR_STYLE_DEFAULT, GDI_NULL_HANDLE, GDI_NULL_HANDLE, GDI_NULL_HANDLE);
}


#ifdef __MMI_FTE_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  gui_create_vertical_scrollbar
 * DESCRIPTION
 *  Creates a vertical scrollbar
 * PARAMETERS
 *  v           [IN/OUT]    Is the vertical scrollbar object (pre-allocated)
 *  x           [IN]        Is the left-top corner
 *  y           [IN]        Is the left-top corner
 *  width       [IN]        Is the width of the vertical scrollbar (smaller)
 *  height      [IN]        Is the height of the vertical scrollbar (larger)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_vertical_scrollbar_with_style(vertical_scrollbar *v, S32 x, S32 y, S32 width, S32 height, U32 style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_create_vertical_scrollbar_ex(v, x, y, width, height, style, GDI_NULL_HANDLE, GDI_NULL_HANDLE, GDI_NULL_HANDLE);
}

#endif

/*****************************************************************************
 * FUNCTION
 *  gui_scrollbar_register_hide_callback
 * DESCRIPTION
 *  regiter hide call back function
 * PARAMETERS
 *  v           [IN/OUT]    Is the vertical scrollbar object
 *  f           [IN]        hide call back function pointer
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vertical_scrollbar_register_hide_callback(vertical_scrollbar *v, void (*f)(S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->hide_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  gui_scrollbar_reset_hide_callback
 * DESCRIPTION
 *  reset hide callback function
 * PARAMETERS
 *  vertical_scroll   [IN/OUT]   the vertical scrollbar  
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vertical_scrollbar_reset_hide_callback(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->hide_callback = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_vertical_scrollbar_range
 * DESCRIPTION
 *  Sets the range of a vertical scrollbar
 * PARAMETERS
 *  v           [IN/OUT]    Is the vertical scrollbar object
 *  range       [IN]        (positive value: Example: Total number of items in a list menu)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_vertical_scrollbar_range(vertical_scrollbar *v, S32 range)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (range < 0)
    {
        range = 0;
    }
    v->range = (U32) range;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_vertical_scrollbar_value
 * DESCRIPTION
 *  Sets the value of a vertical scrollbar
 * PARAMETERS
 *  v           [IN/OUT]    Is the vertical scrollbar object
 *  value       [IN]        (positive value: Example: First displayed item in a list menu)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_vertical_scrollbar_value(vertical_scrollbar *v, S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (value < 0)
    {
        value = 0;
    }
    v->value = (U32) value;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_vertical_scrollbar_scale
 * DESCRIPTION
 *  Sets the scale of a vertical scrollbar
 * PARAMETERS
 *  v           [IN/OUT]    Is the vertical scrollbar object
 *  scale       [IN]        (positive value: Example: Number of displayed items in a list menu)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_vertical_scrollbar_scale(vertical_scrollbar *v, S32 scale)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scale < 0)
    {
        scale = 0;
    }
    v->scale = (U32) scale;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_vertical_scrollbar_disable_drag
 * DESCRIPTION
 *  set disable drag flag
 * PARAMETERS
 *  v           [IN/OUT]    Is the vertical scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_vertical_scrollbar_disable_drag(vertical_scrollbar *v, MMI_BOOL disable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (disable)
    {
        v->flags |= UI_VERTICAL_SCROLLBAR_DISABLE_DRAG;
    }
    else
    {
        v->flags &= ~UI_VERTICAL_SCROLLBAR_DISABLE_DRAG;
    }
}



/*****************************************************************************
 * FUNCTION
 *  gui_move_vertical_scrollbar
 * DESCRIPTION
 *  Moves the scrollbar to a differnt location
 * PARAMETERS
 *  v       [IN/OUT]    Is the vertical scrollbar object
 *  x       [IN]        Is the left-top corner of the scrollbar
 *  y       [IN]        Is the left-top corner of the scrollbar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_move_vertical_scrollbar(vertical_scrollbar *v, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->x = x;
    v->y = y;
    v->up_button.x = x;
    v->down_button.x = x;
    v->up_button.y = y;
    v->down_button.y = v->y + v->height - v->down_button.height;
    v->scroll_button.x = x;
}


/*****************************************************************************
 * FUNCTION
 *  gui_resize_vertical_scrollbar
 * DESCRIPTION
 *  Changes the size of a scrollbar
 * PARAMETERS
 *  v           [IN/OUT]    Is the vertical scrollbar object
 *  width       [IN]        Is the new width
 *  height      [IN]        Is the new height
 * RETURNS
 *  void
 *****************************************************************************/
void gui_resize_vertical_scrollbar(vertical_scrollbar *v, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 button_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->width = width;
    v->height = height;
    button_height = 0;

    button_height = gui_vertical_scrollbar_get_button_height(v);
    
    v->up_button.width = width;
    v->up_button.height = button_height;
    v->down_button.width = width;
    v->down_button.height = button_height;
    
    v->up_button.x = v->x;
    v->down_button.x = v->x;
    v->up_button.y = v->y;
    v->down_button.y = v->y + v->height - v->down_button.height;
    v->scroll_button.x = v->x;
    v->scroll_button.width = v->width;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_scrollbar_set_target_lcd
 * DESCRIPTION
 *  set vertical scroll bar target_lcd
 * PARAMETERS
 *  v           [IN/OUT]    Is the vertical scrollbar object
 *  target_lcd  [IN]        Is the target lcd of vertical scrollbar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vertical_scrollbar_set_target_lcd(vertical_scrollbar *v, gdi_handle target_lcd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT (v != NULL);
    v->target_lcd = target_lcd;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_scrollbar_get_target_lcd
 * DESCRIPTION
 *  get vertical scroll bar target_lcd
 * PARAMETERS
 *  v           [IN/OUT]    Is the vertical scrollbar object
 * RETURNS
 *  vertical scrollbar's target lcd
 *****************************************************************************/
gdi_handle gui_vertical_scrollbar_get_target_lcd(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT (v != NULL);
    return v->target_lcd;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_scrollbar_reset_target_lcd
 * DESCRIPTION
 *  reset vertical scroll bar target_lcd
 * PARAMETERS
 *  v           [IN/OUT]    Is the vertical scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vertical_scrollbar_reset_target_lcd(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT (v != NULL);
    v->target_lcd = GDI_NULL_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_scrollbar_set_target_layer
 * DESCRIPTION
 *  set vertical scrollbar target layer
 * PARAMETERS
 *  v            [IN/OUT]    Is the vertical scrollbar object
 *  target_layer [IN]        Is the target layer of vertical scrollbar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vertical_scrollbar_set_target_layer(vertical_scrollbar *v, gdi_handle target_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT (v != NULL);
    v->target_layer = target_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_scrollbar_get_target_layer
 * DESCRIPTION
 *  get vertical scroll bar target_layer
 * PARAMETERS
 *  v           [IN/OUT]    Is the vertical scrollbar object
 * RETURNS
 *  vertical scrollbar's target layer
 *****************************************************************************/
gdi_handle gui_vertical_scrollbar_get_target_layer(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT (v != NULL);
    return v->target_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_scrollbar_reset_target_layer
 * DESCRIPTION
 *  reset vertical scrollbar target layer
 * PARAMETERS
 *  v            [IN/OUT]    Is the vertical scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vertical_scrollbar_reset_target_layer(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT (v != NULL);
    v->target_layer = GDI_NULL_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_scrollbar_set_alpha_blend_layer
 * DESCRIPTION
 *  set vertical scrollbar target layer
 * PARAMETERS
 *  v                 [IN/OUT]    Is the vertical scrollbar object
 *  alpha_blend_layer [IN]        Is the alpha_blend_layer of vertical scrollbar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vertical_scrollbar_set_alpha_blend_layer(vertical_scrollbar *v, gdi_handle alpha_blend_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT (v != NULL);
    v->alpha_blend_layer = alpha_blend_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_scrollbar_get_alpha_blend_layer
 * DESCRIPTION
 *  get vertical scroll bar alpha_blend_layer
 * PARAMETERS
 *  v           [IN/OUT]    Is the vertical scrollbar object
 * RETURNS
 *  vertical scrollbar's alpha_blend_layer
 *****************************************************************************/
gdi_handle gui_vertical_scrollbar_get_alpha_blend_layer(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT (v != NULL);
    return v->alpha_blend_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_scrollbar_reset_alpha_blend_layer
 * DESCRIPTION
 *  reset vertical scrollbar alpha_blend_layer
 * PARAMETERS
 *  v            [IN/OUT]    Is the vertical scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vertical_scrollbar_reset_alpha_blend_layer(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT (v != NULL);
    v->alpha_blend_layer = GDI_NULL_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_scrollbar_enable_clear_background
 * DESCRIPTION
 *  Enable vertical scrollbar clear background or not
 * PARAMETERS
 *  v            [IN/OUT]    Is the vertical scrollbar object
 *  enable       [IN]        Enable scrollbar clear background or not
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vertical_scrollbar_enable_clear_background(vertical_scrollbar *v, MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT (v != NULL);
    if(enable)
    {
        v->flags &= ~UI_VERTICAL_SCROLLBAR_NOT_CLEAR_BACKGROUND;
    }
    else
    {
        v->flags |= UI_VERTICAL_SCROLLBAR_NOT_CLEAR_BACKGROUND;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_scrollbar_auto_hide_scroll_button
 * DESCRIPTION
 *  To check scrollbar auto hide scroll button or not
 * PARAMETERS
 *  v            [IN/OUT]    Is the vertical scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_vertical_scrollbar_auto_hide_scroll_button(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT (v != NULL);
    return (v->flags & UI_VERTICAL_SCROLLBAR_AUTO_HIDE_SCROLL_BUTTON) ? MMI_TRUE : MMI_FALSE;  
}


#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  gui_scrollbar_translate_pen_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sbutton_pos         [IN]        
 *  remain_space        [IN]        
 *  range               [IN]        
 *  scale               [IN]        
 *  new_value           [OUT]         
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_scrollbar_translate_pen_position(
                vertical_scrollbar *v,
                horizontal_scrollbar *h,
                S32 sbutton_pos /* relative position */ ,
                S16 remain_space,
                U32 *new_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 r;
    S32 diff;
    S32 value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((v != NULL) || (h != NULL));
    if (v != NULL)
    {
        r = v->range - v->scale;
        value = v->value;
        if (v->get_diff)
        {
            if (v->pen_state.initial_sbutton_pos > sbutton_pos)
            {
                diff = v->get_diff(GUI_SCROLLBAR_DIR_UP);
            }
            else
            {
                diff = v->get_diff(GUI_SCROLLBAR_DIR_DOWN);
            }
        }
        else
        {
            diff = v->min_pen_offset;
        }
    }
    else
    {
        r = h->range - h->scale;
        value = h->value;
        if (h->get_diff)
        {
            if (h->pen_state.initial_sbutton_pos > sbutton_pos)
            {
                diff = h->get_diff(GUI_SCROLLBAR_DIR_LEFT);
            }
            else
            {
                diff = h->get_diff(GUI_SCROLLBAR_DIR_RIGHT);
            }
        }
        else
        {
            diff = h->min_pen_offset;
        }
    }
    
    if (r < 0)
    {
        r = 0;
    }

    if (r == 0 || sbutton_pos <= 0)
    {
        *new_value = 0;
    }
    else if (sbutton_pos > remain_space)
    {
        if(v && v->get_diff != NULL)
        {
            *new_value = v->range;
        }
        else if (h && h->get_diff != NULL)
        {
            *new_value = h->range;
        }
        else
        {
            *new_value = r;
        }
    }
    else
    {
        /* 
         * sbutton_pos = round((remain_space * value) / r)
         * 
         *       ==> 
         *
         * new_value is round(sbutton_pos * r / remain_space) or +1 or -1
         * 
         */
        S32 new_sbutton_pos;
        S32 margin; /* 1/2 of jump distance when value is incremented by 1 */

        *new_value = (S32) ((S64) ((S64)sbutton_pos * (S64)r + remain_space - 1) / remain_space);

        margin = (remain_space / r) / 2;

        /* In case that (scale/range) is large, move within +-margin  */
        if (margin > 3 /* random-chosen magic number! */ )
        {
            new_sbutton_pos = (S32) ((S64) remain_space * (*new_value) / r);

            if (*new_value > 0 && sbutton_pos < new_sbutton_pos - margin)
            {
                (*new_value)--;
            }
            else if (*new_value < r && sbutton_pos > new_sbutton_pos + margin)
            {
                (*new_value)++;
            }
        }
    }

    if(*new_value < r && *new_value - value < diff)
    {
        *new_value = value;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_scrollbar_translate_pen_more
 * DESCRIPTION
 *  
 * PARAMETERS
 *  value               [IN]        
 *  range               [IN]        
 *  scale               [IN]        
 *  diff                [IN]        
 *  scrollbar_event     [OUT]         
 *  scrollbar_param     [OUT]         
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_scrollbar_translate_pen_more(
                vertical_scrollbar *v,
                horizontal_scrollbar *h,
                gui_scrollbar_pen_enum *scrollbar_event,
                gui_pen_event_param_struct *scrollbar_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 new_value = 0, diff;
    S32 r, value = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((v != NULL) || (h != NULL));
    if (v != NULL)
    {
        r = v->range - v->scale;
        if (r < 0)
        {
            r = 0;
        }

        if (v->get_diff)
        {
            diff = v->get_diff(GUI_SCROLLBAR_DIR_DOWN);
        }
        else
        {
            diff = v->min_pen_offset;
        }
        new_value = v->value + diff;
        value = v->value;
        if ((new_value > r) && (v->get_diff == NULL))
        {
            new_value = r;
        }
    }
    else if (h != NULL)
    {
        r = h->range - h->scale;
        if (r < 0)
        {
            r = 0;
        }

        if (h->get_diff)
        {
            diff = h->get_diff(GUI_SCROLLBAR_DIR_RIGHT);
        }
        else
        {
            diff = h->min_pen_offset;
        }
        new_value = h->value + diff;
        value = h->value;
        if ((new_value > r) && (h->get_diff == NULL))
        {
            new_value = r;
        }
    }

    if (new_value != value)
    {
        *scrollbar_event = GUI_SCROLLBAR_PEN_JUMP_TO_I;
        GUI_PEN_EVENT_PARAM_SET_INTEGER(scrollbar_param, new_value);
    }
    else
    {
        *scrollbar_event = GUI_SCROLLBAR_PEN_NONE;
        GUI_PEN_EVENT_PARAM_SET_VOID(scrollbar_param);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_scrollbar_translate_pen_less
 * DESCRIPTION
 *  
 * PARAMETERS
 *  value               [IN]        
 *  diff                [IN]        
 *  scrollbar_event     [OUT]         
 *  scrollbar_param     [OUT]         
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_scrollbar_translate_pen_less(
                vertical_scrollbar *v,
                horizontal_scrollbar *h,
                gui_scrollbar_pen_enum *scrollbar_event,
                gui_pen_event_param_struct *scrollbar_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 diff;
    S32 new_value = 0;
    S32 value = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((v != NULL) || (h != NULL));
    if (v != NULL)
    {
        if (v->get_diff)
        {
            diff = v->get_diff(GUI_SCROLLBAR_DIR_UP);
        }
        else
        {
            diff = v->min_pen_offset;
        }
        new_value = v->value - diff;
        value = v->value;
    }
    else if (h != NULL)
    {
        if (h->get_diff)
        {
            diff = h->get_diff(GUI_SCROLLBAR_DIR_LEFT);
        }
        else
        {
            diff = h->min_pen_offset;
        }
        new_value = h->value - diff;
        value = h->value;
    }
    
    if (new_value < 0)
    {
        new_value = 0;
    }

    if (new_value != value)
    {
        *scrollbar_event = GUI_SCROLLBAR_PEN_JUMP_TO_I;
        GUI_PEN_EVENT_PARAM_SET_INTEGER(scrollbar_param, new_value);
    }
    else
    {
        *scrollbar_event = GUI_SCROLLBAR_PEN_NONE;
        GUI_PEN_EVENT_PARAM_SET_VOID(scrollbar_param);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_scrollbar_button1_show_clicked
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_vertical_scrollbar_button1_show_clicked(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(v->up_button.flags & UI_BUTTON_SHIFT_BUTTON1))
    {
        v->up_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        gui_redraw_vertical_scrollbar(v, MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_scrollbar_button1_show_unclicked
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_vertical_scrollbar_button1_show_unclicked(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->up_button.flags & UI_BUTTON_SHIFT_BUTTON1)
    {
        v->up_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        gui_redraw_vertical_scrollbar(v, MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_scrollbar_button2_show_clicked
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_vertical_scrollbar_button2_show_clicked(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(v->down_button.flags & UI_BUTTON_SHIFT_BUTTON1))
    {
        v->down_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        gui_redraw_vertical_scrollbar(v, MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_scrollbar_button2_show_unclicked
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_vertical_scrollbar_button2_show_unclicked(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->down_button.flags & UI_BUTTON_SHIFT_BUTTON1)
    {
        v->down_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        gui_redraw_vertical_scrollbar(v, MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_scrollbar_set_minimum_pen_offset
 * DESCRIPTION
 *  Set the minimum scrolling offset in scrollbar.
 *  
 *  Used in GUI_SCROLLBAR_PEN_STATE_AREA1, GUI_SCROLLBAR_PEN_STATE_AREA2,
 *  GUI_SCROLLBAR_PEN_STATE_BUTTON1, GUI_SCROLLBAR_PEN_STATE_BUTTON2
 * PARAMETERS
 *  v               [IN/OUT]            Is the vertical scrollbar object
 *  min_offset      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vertical_scrollbar_set_minimum_pen_offset(vertical_scrollbar *v, S32 min_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->min_pen_offset = min_offset;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_scrollbar_set_pen_self_scroll
 * DESCRIPTION
 *  Setup whether the scrollbar is redrawn when it is scrolled by pen.
 *  If 'enable' is MMI_FALSE, the scrollbar is scrolled by its parent GUI component.
 * PARAMETERS
 *  v           [IN/OUT]            Is the horizontal scrollbar object
 *  enable      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vertical_scrollbar_set_pen_self_scroll(vertical_scrollbar *v, BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (enable)
    {
        v->pen_self_scroll = 1;
    }
    else
    {
        v->pen_self_scroll = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_scrollbar_reconfigure_pen_value
 * DESCRIPTION
 *  Reconfigure scrollbar position if it is  scrolled passively by parent components
 *  
 *  Take inline editor as example, if gui_vertical_scrollbar_translate_pen_event() returns 1
 *  for GUI_SCROLLBAR_PEN_JUMP_TO_I, Inline editor might set scrollbar value to 0 instead of 1.
 *  As a result, scroll button might be moved away from the original pen down position,
 *  and this function should be used to fix internal scrollbar states.
 * PARAMETERS
 *  v       [IN/OUT]            Is the vertical scrollbar object
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vertical_scrollbar_reconfigure_pen_value(vertical_scrollbar *v, S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_scrollbar_pen_state_struct *pen_state;
    U32 new_value;
    S32 sbutton_y1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(x);
    pen_state = &v->pen_state;

    if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_SBUTTON)
    {
        sbutton_y1 = v->scroll_button.y;

        gui_scrollbar_translate_pen_position(
            v,
            NULL,
            pen_state->initial_sbutton_pos + (y - pen_state->initial_pen_down_pos),
            pen_state->remain_space,
            &new_value);

        if ((v->value < pen_state->previous_value && new_value > v->value) ||
            (v->value > pen_state->previous_value && new_value < v->value))
        {
            /* Note: y might not be on scroll button! */
            pen_state->initial_pen_down_pos = y;
            if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
            {
                pen_state->initial_sbutton_pos = (S16) (sbutton_y1 - v->y);
            }
            else
            {
                pen_state->initial_sbutton_pos = (S16) (sbutton_y1 - v->y - v->up_button.height);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_scrollbar_register_get_diff
 * DESCRIPTION
 *  Register get diff function
 * PARAMETERS
 *  v           : [IN]      The pointer of scrollbar 
 *  get_diff    : [IN]      The new get_diff function of vertical scrollbar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vertical_scrollbar_register_get_diff(vertical_scrollbar *v, S32 (*get_diff)(gui_scrollbar_dir_enum dir))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->get_diff = get_diff;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_scrollbar_reset_get_diff
 * DESCRIPTION
 *  Reset get diff function
 * PARAMETERS
 *  v           : [IN]      The pointer of scrollbar 
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vertical_scrollbar_reset_get_diff(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->get_diff = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_scrollbar_translate_pen_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v                   [IN/OUT]         
 *  pen_event           [IN]        
 *  x                   [IN]        
 *  y                   [IN]        
 *  scrollbar_event     [OUT]         
 *  scrollbar_param     [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
BOOL gui_vertical_scrollbar_translate_pen_event(
        vertical_scrollbar *v,
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_scrollbar_pen_enum *scrollbar_event,
        gui_pen_event_param_struct *scrollbar_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
     * If the Up/Down button is pressed or released, we need to gui_redraw_vertical_scrollbar()
     * even if GUI_SCROLLBAR_PEN_JUMP_TO_I is also returned.
     *
     * The reason is that parent component might discard the scrollbar event and not redraw itself.
     */

    BOOL ret;
    S32 sbutton_y1, sbutton_y2, up_button_y2, down_button_y1;
    gui_scrollbar_pen_state_struct *pen_state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pen_state = &v->pen_state;
    ret = MMI_TRUE;
    sbutton_y1 = v->scroll_button.y;
    sbutton_y2 = sbutton_y1 + v->scroll_button.height - 1;
    up_button_y2 = v->up_button.y + v->up_button.height - 1;
    down_button_y1 = v->down_button.y;

    *scrollbar_event = GUI_SCROLLBAR_PEN_NONE;
    GUI_PEN_EVENT_PARAM_SET_VOID(scrollbar_param);
    
#ifdef __MMI_FTE_SUPPORT__
    if(!(v->style & GUI_SCROLLBAR_STYLE_WIDER))
    {
        ret = MMI_FALSE;
        pen_state->state = GUI_SCROLLBAR_PEN_STATE_INVALID;
        return ret;
    }
#endif

    switch (pen_event)
    {
        case MMI_PEN_EVENT_DOWN:
            if (PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height))
            {
                pen_state->initial_pen_down_pos = y;
                if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
                {
                    pen_state->initial_sbutton_pos = (S16) (sbutton_y1 - v->y);
                }
                else
                {
                    pen_state->initial_sbutton_pos = (S16) (sbutton_y1 - v->y - v->up_button.height);
                }
                pen_state->original_value = v->value;

                if (y <= up_button_y2 && v->up_button.height > 0)
                {
                    gui_vertical_scrollbar_button1_show_clicked(v);

                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_BUTTON1;
                    gui_scrollbar_translate_pen_less(v, NULL, scrollbar_event, scrollbar_param);
                }
                else if (y >= down_button_y1 && v->down_button.height > 0)
                {
                    gui_vertical_scrollbar_button2_show_clicked(v);

                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_BUTTON2;
                    gui_scrollbar_translate_pen_more(
                        v,
                        NULL,
                        scrollbar_event,
                        scrollbar_param);
                }
                else if (y >= sbutton_y1 && y <= sbutton_y2 && !(v->flags & UI_VERTICAL_SCROLLBAR_DISABLE_DRAG))
                {
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_SBUTTON;
                }
                else if (y < sbutton_y1 && !(v->flags & UI_VERTICAL_SCROLLBAR_DISABLE_DRAG))
                {
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_AREA1;
                    gui_scrollbar_translate_pen_less(v, NULL, scrollbar_event, scrollbar_param);
                }
                else if (!(v->flags & UI_VERTICAL_SCROLLBAR_DISABLE_DRAG))
                {
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_AREA2;
                    gui_scrollbar_translate_pen_more(
                        v,
                        NULL,
                        scrollbar_event,
                        scrollbar_param);
                }
                else
                {
                    ret = MMI_TRUE;
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_INVALID;
                }

                if (!(v->flags & UI_VERTICAL_SCROLLBAR_DISABLE_DRAG))
                {
                    gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
                }
            }
            else
            {
                ret = MMI_FALSE;
                pen_state->state = GUI_SCROLLBAR_PEN_STATE_INVALID;
            }
            break;

        case MMI_PEN_EVENT_LONG_TAP:
            /* FALLTHROUGH no break */
        case MMI_PEN_EVENT_REPEAT:
            if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_BUTTON1)
            {
                gui_scrollbar_translate_pen_less(v, NULL, scrollbar_event, scrollbar_param);
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_BUTTON2)
            {
                gui_scrollbar_translate_pen_more(
                    v,
                    NULL,
                    scrollbar_event,
                    scrollbar_param);
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_AREA1)
            {
                if (PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height) && (y < sbutton_y1))
                {
                    gui_scrollbar_translate_pen_less(v, NULL, scrollbar_event, scrollbar_param);
                }
                else
                {
                    /* Scroll button is moved to pen position */
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_AREA1_OUTSIDE;
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_AREA2)
            {
                if (PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height) && (y > sbutton_y2))
                {
                    gui_scrollbar_translate_pen_more(
                        v,
                        NULL,
                        scrollbar_event,
                        scrollbar_param);
                }
                else
                {
                    /* Scroll button is moved to pen position */
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_AREA2_OUTSIDE;
                }
            }
            break;

        case MMI_PEN_EVENT_UP:
            /* FALLTHROUGH no break */
        case MMI_PEN_EVENT_MOVE:
            if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_BUTTON1)
            {
                if (pen_event == MMI_PEN_EVENT_UP)
                {
                    gui_vertical_scrollbar_button1_show_unclicked(v);
                }
                else if (!PEN_CHECK_BOUND
                         (x, y, v->up_button.x, v->up_button.y, v->up_button.width, v->up_button.height))
                {
                    gui_vertical_scrollbar_button1_show_unclicked(v);

                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_BUTTON1_OUTSIDE;
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_BUTTON1_OUTSIDE)
            {
                if (pen_event == MMI_PEN_EVENT_UP)
                {
                    /* Do nothing */
                    MMI_DBG_ASSERT(!(v->up_button.flags & UI_BUTTON_SHIFT_BUTTON1));
                }
                else if (PEN_CHECK_BOUND(x, y, v->up_button.x, v->up_button.y, v->up_button.width, v->up_button.height))
                {
                    gui_vertical_scrollbar_button1_show_clicked(v);
                    
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_BUTTON1;
                    gui_scrollbar_translate_pen_less(v, NULL, scrollbar_event, scrollbar_param);
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_BUTTON2)
            {
                if (pen_event == MMI_PEN_EVENT_UP)
                {
                    gui_vertical_scrollbar_button2_show_unclicked(v);
                }
                else if (!PEN_CHECK_BOUND
                         (x, y, v->down_button.x, v->down_button.y, v->down_button.width, v->down_button.height))
                {
                    gui_vertical_scrollbar_button2_show_unclicked(v);

                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_BUTTON2_OUTSIDE;
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_BUTTON2_OUTSIDE)
            {
                if (pen_event == MMI_PEN_EVENT_UP)
                {
                    /* Do nothing */
                    MMI_DBG_ASSERT(!(v->down_button.flags & UI_BUTTON_SHIFT_BUTTON1));
                }
                else if (PEN_CHECK_BOUND
                         (x, y, v->down_button.x, v->down_button.y, v->down_button.width, v->down_button.height))
                {
                    gui_vertical_scrollbar_button2_show_clicked(v);

                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_BUTTON2;
                    gui_scrollbar_translate_pen_more(
                        v,
                        NULL,
                        scrollbar_event,
                        scrollbar_param);
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_AREA1_OUTSIDE)
            {
                if (PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height) && (y < sbutton_y1))
                {
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_AREA1;
                    gui_scrollbar_translate_pen_less(v, NULL, scrollbar_event, scrollbar_param);
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_AREA1)
            {
                if (!PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height) || !(y < sbutton_y1))
                {
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_AREA1_OUTSIDE;
                }
            }
            if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_AREA2_OUTSIDE)
            {
                if (PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height) && (y > sbutton_y2))
                {
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_AREA2;
                    gui_scrollbar_translate_pen_more(
                        v,
                        NULL,
                        scrollbar_event,
                        scrollbar_param);
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_AREA2)
            {
                if (!PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height) || !(y > sbutton_y2))
                {
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_AREA2_OUTSIDE;
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_SBUTTON)
            {
                if (PEN_ABS(x, v->x) > GUI_SCROLLBAR_VALID_RANGE)
                {
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_SBUTTON_OUTSIDE;
                    /* Reset to original position */
                    *scrollbar_event = GUI_SCROLLBAR_PEN_JUMP_TO_I;
                    GUI_PEN_EVENT_PARAM_SET_INTEGER(scrollbar_param, (int)pen_state->original_value);
                }
                else
                {
                    U32 new_value;

                    gui_scrollbar_translate_pen_position(
                        v,
                        NULL,
                        pen_state->initial_sbutton_pos + (y - pen_state->initial_pen_down_pos),
                        pen_state->remain_space,
                        &new_value);
                    if (new_value != v->value)
                    {
                        *scrollbar_event = GUI_SCROLLBAR_PEN_JUMP_TO_I;
                        GUI_PEN_EVENT_PARAM_SET_INTEGER(scrollbar_param, (int)new_value);
                    }
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_SBUTTON_OUTSIDE)
            {
                if (PEN_ABS(x, v->x) < GUI_SCROLLBAR_VALID_RANGE)
                {
                    U32 new_value;

                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_SBUTTON;

                    gui_scrollbar_translate_pen_position(
                        v,
                        NULL,
                        pen_state->initial_sbutton_pos + (y - pen_state->initial_pen_down_pos),
                        pen_state->remain_space,
                        &new_value);
                    if (new_value != v->value)
                    {
                        *scrollbar_event = GUI_SCROLLBAR_PEN_JUMP_TO_I;
                        GUI_PEN_EVENT_PARAM_SET_INTEGER(scrollbar_param, (int)new_value);
                    }
                }
            }

            if (pen_event == MMI_PEN_EVENT_UP)
            {
                pen_state->state = GUI_SCROLLBAR_PEN_STATE_INVALID;
            }

            break;

        case MMI_PEN_EVENT_ABORT:
            if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_SBUTTON)
            {
                /* Reset to original position */
                //*scrollbar_event = GUI_SCROLLBAR_PEN_JUMP_TO_I;
                //GUI_PEN_EVENT_PARAM_SET_INTEGER(scrollbar_param, (int)pen_state->original_value);
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_BUTTON1)
            {
                gui_vertical_scrollbar_button1_show_unclicked(v);
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_BUTTON2)
            {
                gui_vertical_scrollbar_button2_show_unclicked(v);
            }

            pen_state->state = GUI_SCROLLBAR_PEN_STATE_INVALID;
            break;

        default:
            MMI_ASSERT(0);
    }

    if (ret)
    {
        /*
         * Scrollbar does not change its value. Instead, parent components should change the value
         * * if GUI_SCROLLBAR_PEN_JUMP_TO_I is returned.
         */
        pen_state->previous_value = v->value;
    }

    if (ret && v->pen_self_scroll && *scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
    {
        v->value = scrollbar_param->_u.i;
        gui_redraw_vertical_scrollbar(v, MMI_TRUE);
    }

    return ret;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 

/***************************************************************************** 
 * Horizontal Scrollbar
 *****************************************************************************/

UI_horizontal_scrollbar_theme *current_horizontal_scrollbar_theme = NULL;


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_scrollbar_get_button_width
 * DESCRIPTION
 *  Get horizontal scrollbar's button height
 * PARAMETERS
 *  h       [IN/OUT]        Is the horizontal scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
static S32 gui_horizontal_scrollbar_get_button_width(horizontal_scrollbar *h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 button_width;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*---------------------------------------------------------------*/
    button_width= 0;
    if(h->style & GUI_SCROLLBAR_STYLE_WIDER)
    {
    #if defined(UI_SCROLLBAR_WIDER_STYLE_1)
        button_width = h->height;
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_2) || defined(UI_SCROLLBAR_WIDER_STYLE_3) || defined(UI_SCROLLBAR_WIDER_STYLE_5)
        button_width = gui_scrollbar_get_button_min_size(GUI_SCROLLBAR_BUTTON_LEFT, h->height);
        if (button_width * 2 >= h->width)
        {
            button_width = 0;
        }
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_4) && defined(__MMI_TOUCH_SCREEN__)
        #if defined (__MMI_MAINLCD_128X160__)
            button_width = h->height + 2;
        #else
            button_width = h->height - GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4 * 2 + 3;
        #endif
        if (button_width * 2 >= h->width)
        {
            button_width = 0;
        }
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_6) && defined(__MMI_TOUCH_SCREEN__)
        #if defined (__MMI_MAINLCD_128X160__)
            button_width = h->height + 2;
        #else
            button_width = h->height - GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE6 * 2 + 3;
        #endif
        if (button_width * 2 >= h->width)
        {
            button_width = 0;
        }
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_7) || defined(UI_SCROLLBAR_STYLE_8)
        button_width = 0;
    #endif 
    }
    else
    {
    #if defined(UI_SCROLLBAR_STYLE_1)
        button_width = h->height;
    #elif defined(UI_SCROLLBAR_STYLE_2) || defined(UI_SCROLLBAR_STYLE_3) || defined(UI_SCROLLBAR_STYLE_5)
        button_width = gui_scrollbar_get_button_min_size(GUI_SCROLLBAR_BUTTON_LEFT, h->height);
        if (button_width * 2 >= h->width)
        {
            button_width = 0;
        }
    #elif defined(UI_SCROLLBAR_STYLE_4) && defined(__MMI_TOUCH_SCREEN__)
        #if defined (__MMI_MAINLCD_128X160__)
            button_width = h->height + 2;
        #else
            button_width = h->height - GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4 * 2 + 3;
        #endif
        if (button_width * 2 >= h->width)
        {
            button_width = 0;
        }
    #elif defined(UI_SCROLLBAR_STYLE_6) && defined(__MMI_TOUCH_SCREEN__)
        #if defined (__MMI_MAINLCD_128X160__)
            button_width = h->height + 2;
        #else
            button_width = h->height - GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE6 * 2 + 3;
        #endif
        if (button_width * 2 >= h->width)
        {
            button_width = 0;
        }
    #elif defined(UI_SCROLLBAR_STYLE_7) || defined(UI_SCROLLBAR_STYLE_8) || defined(UI_SCROLLBAR_STYLE_9)
        button_width = 0;
    #endif 
    }

    return button_width;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_scrollbar_show
 * DESCRIPTION
 *  Show horizontal scrollbar
 * PARAMETERS
 *  v       [IN/OUT]        Is the vertical scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_horizontal_scrollbar(horizontal_scrollbar *h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
    if(h->style & GUI_SCROLLBAR_STYLE_WIDER)
    {
    #if defined(UI_SCROLLBAR_WIDER_STYLE_1)
        gui_show_horizontal_scrollbar_style_1(h);
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_2)
        gui_show_horizontal_scrollbar_style_2(h);
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_3)
        gui_show_horizontal_scrollbar_style_3(h);
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_4)
        gui_show_horizontal_scrollbar_style_4(h);
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_5)
        gui_show_horizontal_scrollbar_style_5(h);
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_6)
        gui_show_horizontal_scrollbar_style_6(h);
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_7)
        gui_show_horizontal_scrollbar_style_7(h);
    #endif /* UI_SCROLLBAR_STYLE_1 */ 
    }
    else
    {
#endif /* __MMI_FTE_SUPPORT__ */         
    #if defined(UI_SCROLLBAR_STYLE_1)
        gui_show_horizontal_scrollbar_style_1(h);
    #elif defined(UI_SCROLLBAR_STYLE_2)
        gui_show_horizontal_scrollbar_style_2(h);
    #elif defined(UI_SCROLLBAR_STYLE_3)
        gui_show_horizontal_scrollbar_style_3(h);
    #elif defined(UI_SCROLLBAR_STYLE_4)
        gui_show_horizontal_scrollbar_style_4(h);
    #elif defined(UI_SCROLLBAR_STYLE_5)
        gui_show_horizontal_scrollbar_style_5(h);
    #elif defined(UI_SCROLLBAR_STYLE_6)
        gui_show_horizontal_scrollbar_style_6(h);
    #elif defined(UI_SCROLLBAR_STYLE_7)
        gui_show_horizontal_scrollbar_style_7(h);
    #elif defined(UI_SCROLLBAR_STYLE_8)
        gui_show_horizontal_scrollbar_style_VFR(h);
    #elif defined(UI_SCROLLBAR_STYLE_9)
        gui_show_horizontal_scrollbar_style_9(h);
    #endif /* UI_SCROLLBAR_STYLE_1 */ 
#ifdef __MMI_FTE_SUPPORT__
    }
#endif /* __MMI_FTE_SUPPORT__ */    
}


/*****************************************************************************
 * FUNCTION
 *  gui_redraw_horizontal_scrollbar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_redraw_horizontal_scrollbar(horizontal_scrollbar *v, MMI_BOOL blt_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x, offset_y;
    S32 current_x1, current_y1, current_x2, current_y2;
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = v->x;
    x2 = x1 + v->width - 1;
    y1 = v->y;
    y2 = y1 + v->height - 1;
    gui_lock_double_buffer();
    gui_show_horizontal_scrollbar(v);
    gui_unlock_double_buffer();
    if (v->target_layer)
    {
	    gdi_layer_push_and_set_active(v->target_layer);
    }
    gdi_layer_get_position(&offset_x, &offset_y);
    if (v->target_layer)
    {
	    gdi_layer_pop_and_restore_active();
    }
    if (!blt_all && !gui_scrollbar_redraw_clip_enable)
    {
         gdi_layer_get_clip(&current_x1, &current_y1, &current_x2, &current_y2);

        if ((x1 > current_x2) || (y1 > current_y2) ||(x2 < current_x1) || (y2 < current_y1))
        {
            return;
        }

        if (x1 < current_x1)
        {
            x1 = current_x1;
        }

        if (y1 < current_y1)
        {
            y1 = current_y1;
        }

        if (x2 > current_x2)
        {
            x2 = current_x2;
        }

        if (y2 > current_y2)
        {
            y2 = current_y2;
        }
    }
    gui_BLT_double_buffer(
        x1 + offset_x,
        y1 + offset_y,
        x2 + offset_x,
        y2 + offset_y);
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_scrollbar_show
 * DESCRIPTION
 *  Show vertical scrollbar
 * PARAMETERS
 *  v       [IN/OUT]        Is the vertical scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_scrollbar_redraw_button(horizontal_scrollbar *h, gui_scrollbar_buttton_enum type, MMI_BOOL pressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
    if(h->style & GUI_SCROLLBAR_STYLE_WIDER)
    {
    #if defined(UI_SCROLLBAR_WIDER_STYLE_1)
        gui_horizontal_scrollbar_redraw_button_style_1(h, type, pressed);
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_2)
        gui_horizontal_scrollbar_redraw_button_style_2(h, type, pressed);
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_3)
        gui_horizontal_scrollbar_redraw_button_style_3(h, type, pressed);
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_4)
        gui_horizontal_scrollbar_redraw_button_style_4(h, type, pressed);
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_5)
        gui_horizontal_scrollbar_redraw_button_style_5(h, type, pressed);
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_6)
        gui_horizontal_scrollbar_redraw_button_style_6(h, type, pressed);
    #elif defined(UI_SCROLLBAR_WIDER_STYLE_7)
        gui_horizontal_scrollbar_redraw_button_style_7(h, type, pressed);
    #endif /* UI_SCROLLBAR_STYLE_1 */  
    }
    else
    {
#endif /* __MMI_FTE_SUPPORT__ */         
    #if defined(UI_SCROLLBAR_STYLE_1)
        gui_horizontal_scrollbar_redraw_button_style_1(h, type, pressed);
    #elif defined(UI_SCROLLBAR_STYLE_2)
        gui_horizontal_scrollbar_redraw_button_style_2(h, type, pressed);
    #elif defined(UI_SCROLLBAR_STYLE_3)
        gui_horizontal_scrollbar_redraw_button_style_3(h, type, pressed);
    #elif defined(UI_SCROLLBAR_STYLE_4)
        gui_horizontal_scrollbar_redraw_button_style_4(h, type, pressed);
    #elif defined(UI_SCROLLBAR_STYLE_5)
        gui_horizontal_scrollbar_redraw_button_style_5(h, type, pressed);
    #elif defined(UI_SCROLLBAR_STYLE_6)
        gui_horizontal_scrollbar_redraw_button_style_6(h, type, pressed);
    #elif defined(UI_SCROLLBAR_STYLE_7)
        gui_horizontal_scrollbar_redraw_button_style_7(h, type, pressed);
    #elif defined(UI_SCROLLBAR_STYLE_8)
        gui_horizontal_scrollbar_redraw_button_style_VFR(h, type, pressed);
    #elif defined(UI_SCROLLBAR_STYLE_9)
        gui_horizontal_scrollbar_redraw_button_style_9(h, type, pressed);
    #endif /* UI_SCROLLBAR_STYLE_1 */  
#ifdef __MMI_FTE_SUPPORT__
    } 
#endif /* __MMI_FTE_SUPPORT__ */    
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_scrollbar_current_theme
 * DESCRIPTION
 *  Applies the current theme for the horizontal scrollbar
 * PARAMETERS
 *  v       [IN/OUT]            Is the horizontal scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_horizontal_scrollbar_current_theme(horizontal_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->focussed_bar_filler = current_horizontal_scrollbar_theme->focussed_bar_filler;
    v->normal_bar_filler = current_horizontal_scrollbar_theme->normal_bar_filler;
    v->disabled_bar_filler = current_horizontal_scrollbar_theme->disabled_bar_filler;
    gui_set_icon_button_BG_theme(&v->left_button, current_horizontal_scrollbar_theme->left_button_theme);
    gui_set_icon_button_BG_theme(&v->right_button, current_horizontal_scrollbar_theme->right_button_theme);
    gui_set_icon_button_BG_theme(&v->scroll_button, current_horizontal_scrollbar_theme->scroll_button_theme);
    gui_icon_button_set_icon(
        &v->left_button,
        current_horizontal_scrollbar_theme->left_button_icon,
        UI_DEFAULT_TRANSPARENT_COLOR);
    gui_icon_button_set_icon(
        &v->right_button,
        current_horizontal_scrollbar_theme->right_button_icon,
        UI_DEFAULT_TRANSPARENT_COLOR);
    gui_icon_button_set_icon(
        &v->scroll_button,
        current_horizontal_scrollbar_theme->scroll_button_icon,
        UI_DEFAULT_TRANSPARENT_COLOR);
    v->flags |= current_horizontal_scrollbar_theme->flags;
    if (v->flags & UI_HORIZONTAL_SCROLLBAR_BUTTON_SHIFT1)
    {
        v->left_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        v->right_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
    }
    else if (v->flags & UI_HORIZONTAL_SCROLLBAR_BUTTON_SHIFT2)
    {
        v->left_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        v->right_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
    }
    else
    {
        v->left_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        v->right_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        v->left_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        v->right_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_scrollbar_theme
 * DESCRIPTION
 *  Applies the given theme to the horizontal scrollbar
 * PARAMETERS
 *  v       [IN/OUT]        Is the horizontal scrollbar object
 *  t       [IN]            Horizontal scrollbar theme
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_horizontal_scrollbar_theme(horizontal_scrollbar *v, UI_horizontal_scrollbar_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->focussed_bar_filler = t->focussed_bar_filler;
    v->normal_bar_filler = t->normal_bar_filler;
    v->disabled_bar_filler = t->disabled_bar_filler;
    gui_set_icon_button_BG_theme(&v->left_button, t->left_button_theme);
    gui_set_icon_button_BG_theme(&v->right_button, t->right_button_theme);
    gui_set_icon_button_BG_theme(&v->scroll_button, t->scroll_button_theme);
    gui_icon_button_set_icon(&v->left_button, t->left_button_icon, UI_DEFAULT_TRANSPARENT_COLOR);
    gui_icon_button_set_icon(&v->right_button, t->right_button_icon, UI_DEFAULT_TRANSPARENT_COLOR);
    gui_icon_button_set_icon(&v->scroll_button, t->scroll_button_icon, UI_DEFAULT_TRANSPARENT_COLOR);
    v->flags |= t->flags;
    if (v->flags & UI_HORIZONTAL_SCROLLBAR_BUTTON_SHIFT1)
    {
        v->left_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        v->right_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
    }
    else if (v->flags & UI_HORIZONTAL_SCROLLBAR_BUTTON_SHIFT2)
    {
        v->left_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        v->right_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
    }
    else
    {
        v->left_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        v->right_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        v->left_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        v->right_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_horizontal_scrollbar
 * DESCRIPTION
 *  Creates a horizontal scrollbar
 * PARAMETERS
 *  v           [IN/OUT]    Is the horizontal scrollbar object (pre-allocated)
 *  x           [IN]        Is the left-top corner
 *  y           [IN]        Is the left-top corner
 *  width       [IN]        Is the width of the horizontal scrollbar (larger)
 *  height      [IN]        Is the height of the horizontal scrollbar (smaller)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_horizontal_scrollbar_ex(
        horizontal_scrollbar *v, 
        S32 x, 
        S32 y, 
        S32 width, 
        S32 height, 
        U32 style,
        gdi_handle target_lcd, 
        gdi_handle target_layer,
        gdi_handle alpha_blend_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 button_width;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->x = x;
    v->y = y;
    v->width = width;
    v->height = height;
    v->value = 0;
    v->range = 0;
    v->flags = 0;
    v->target_lcd = target_lcd;
    v->target_layer = target_layer;
    v->alpha_blend_layer = alpha_blend_layer;
    v->hide_callback = NULL;
    v->style = style;
    button_width = 0;

    gui_set_current_ptr(v, NULL);
    
    button_width = gui_horizontal_scrollbar_get_button_width(v);

#if defined(UI_SCROLLBAR_STYLE_6)
    v->flags |= UI_HORIZONTAL_SCROLLBAR_AUTO_HIDE_SCROLL_BUTTON;
#endif

#ifdef __MMI_FTE_SUPPORT__
    if(v->style & GUI_SCROLLBAR_STYLE_DEFAULT)
    {
        v->flags |= UI_HORIZONTAL_SCROLLBAR_AUTO_HIDE_SCROLL_BUTTON;
    }
    v->flags |= UI_HORIZONTAL_SCROLLBAR_TYPE_BUTTONLESS;
#endif

    gui_create_icon_button(
        &v->left_button,
        v->x,
        v->y,
        button_width,
        v->height,
        current_horizontal_scrollbar_theme->left_button_icon);
    gui_create_icon_button(
        &v->right_button,
        v->x + v->width - button_width,
        v->y,
        button_width,
        v->height,
        current_horizontal_scrollbar_theme->right_button_icon);
    /* width of scroll button is set later */
    gui_create_icon_button(
        &v->scroll_button,
        v->x + v->left_button.width,
        v->y,
        v->height,
        v->height,
        current_horizontal_scrollbar_theme->scroll_button_icon);
    gui_set_horizontal_scrollbar_current_theme(v);

    
#ifdef __MMI_TOUCH_SCREEN__
    v->min_pen_offset = 1;
    v->pen_self_scroll = 1;
    v->get_diff = NULL;
    memset(&(v->pen_state), 0, sizeof(gui_scrollbar_pen_state_struct));
#endif /* __MMI_TOUCH_SCREEN__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_horizontal_scrollbar
 * DESCRIPTION
 *  Creates a horizontal scrollbar
 * PARAMETERS
 *  v           [IN/OUT]    Is the horizontal scrollbar object (pre-allocated)
 *  x           [IN]        Is the left-top corner
 *  y           [IN]        Is the left-top corner
 *  width       [IN]        Is the width of the horizontal scrollbar (larger)
 *  height      [IN]        Is the height of the horizontal scrollbar (smaller)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_horizontal_scrollbar(horizontal_scrollbar *v, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_create_horizontal_scrollbar_ex(v, x, y, width, height, GUI_SCROLLBAR_STYLE_DEFAULT, GDI_NULL_HANDLE, GDI_NULL_HANDLE, GDI_NULL_HANDLE);
}


#ifdef __MMI_FTE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  gui_create_horizontal_scrollbar
 * DESCRIPTION
 *  Creates a horizontal scrollbar
 * PARAMETERS
 *  v           [IN/OUT]    Is the horizontal scrollbar object (pre-allocated)
 *  x           [IN]        Is the left-top corner
 *  y           [IN]        Is the left-top corner
 *  width       [IN]        Is the width of the horizontal scrollbar (larger)
 *  height      [IN]        Is the height of the horizontal scrollbar (smaller)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_horizontal_scrollbar_with_style(horizontal_scrollbar *v, S32 x, S32 y, S32 width, S32 height, U32 style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_create_horizontal_scrollbar_ex(v, x, y, width, height, style, GDI_NULL_HANDLE, GDI_NULL_HANDLE, GDI_NULL_HANDLE);
}


#endif


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_scrollbar_range
 * DESCRIPTION
 *  Sets the range of a horizontal scrollbar
 * PARAMETERS
 *  v           [IN/OUT]    Is the horizontal scrollbar object
 *  range       [IN]        (positive value: Example: Total number of items in a list menu)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_horizontal_scrollbar_range(horizontal_scrollbar *v, S32 range)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (range < 0)
    {
        range = 0;
    }
    v->range = (U32) range;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_scrollbar_value
 * DESCRIPTION
 *  Sets the value of a horizontal scrollbar
 * PARAMETERS
 *  v           [IN/OUT]    Is the horizontal scrollbar object
 *  value       [IN]        (positive value: Example: First displayed item in a list menu)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_horizontal_scrollbar_value(horizontal_scrollbar *v, S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (value < 0)
    {
        value = 0;
    }
    v->value = (U32) value;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_scrollbar_scale
 * DESCRIPTION
 *  Sets the scale of a horizontal scrollbar
 * PARAMETERS
 *  v           [IN/OUT]    Is the horizontal scrollbar object
 *  scale       [IN]        (positive value: Example: Number of displayed items in a list menu)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_horizontal_scrollbar_scale(horizontal_scrollbar *v, S32 scale)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scale < 0)
    {
        scale = 0;
    }
    v->scale = (U32) scale;
}


/*****************************************************************************
 * FUNCTION
 *  gui_move_horizontal_scrollbar
 * DESCRIPTION
 *  Moves the scrollbar to a differnt location
 * PARAMETERS
 *  v       [IN/OUT]    Is the horizontal scrollbar object
 *  x       [IN]        Is the left-top corner of the scrollbar
 *  y       [IN]        Is the left-top corner of the scrollbar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_move_horizontal_scrollbar(horizontal_scrollbar *v, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->x = x;
    v->y = y;
    v->left_button.x = x;
    v->right_button.x = v->x + v->width - v->right_button.width;
    v->left_button.y = y;
    v->right_button.y = y;
    v->scroll_button.x = x = v->x + v->left_button.width;
    v->scroll_button.y = y;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_scrollbar_set_target_lcd
 * DESCRIPTION
 *  set horizontal scrollbar target lcd
 * PARAMETERS
 *  v           [IN/OUT]    Is the horizontal scrollbar object
 *  target_lcd  [IN]        Is the horizontal scrollbar target lcd
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_scrollbar_set_target_lcd(horizontal_scrollbar *v, gdi_handle target_lcd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT (v != NULL);
    v->target_lcd = target_lcd;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_scrollbar_get_target_lcd
 * DESCRIPTION
 *  get horizontal scrollbar target lcd
 * PARAMETERS
 *  v           [IN/OUT]    Is the horizontal scrollbar object
 * RETURNS
 *  horizontal scrollbar's target lcd
 *****************************************************************************/
gdi_handle gui_horizontal_scrollbar_get_target_lcd(horizontal_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT (v != NULL);
    return v->target_lcd;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_scrollbar_reset_target_lcd
 * DESCRIPTION
 *  reset horizontal scrollbar target lcd
 * PARAMETERS
 *  v           [IN/OUT]    Is the horizontal scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_scrollbar_reset_target_lcd(horizontal_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT (v != NULL);
    v->target_lcd = GDI_NULL_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_scrollbar_set_target_layer
 * DESCRIPTION
 *  set horizontal scrollbar target layer
 * PARAMETERS
 *  v             [IN/OUT]    Is the horizontal scrollbar object
 *  target_layer  [IN]        Is the horizontal scrollbar target layer
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_scrollbar_set_target_layer(horizontal_scrollbar *v, gdi_handle target_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT (v != NULL);
    v->target_layer = target_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_scrollbar_get_target_layer
 * DESCRIPTION
 *  get horizontal scrollbar target layer
 * PARAMETERS
 *  v           [IN/OUT]    Is the horizontal scrollbar object
 * RETURNS
 *  horizontal scrollbar's target layer
 *****************************************************************************/
gdi_handle gui_horizontal_scrollbar_get_target_layer(horizontal_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT (v != NULL);
    return v->target_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_scrollbar_reset_target_layer
 * DESCRIPTION
 *  reset horizontal scrollbar target layer
 * PARAMETERS
 *  v             [IN/OUT]    Is the horizontal scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_scrollbar_reset_target_layer(horizontal_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT (v != NULL);
    v->target_layer = GDI_NULL_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_scrollbar_set_alpha_blend_layer
 * DESCRIPTION
 *  set horizontal scrollbar alpha_blend_layer
 * PARAMETERS
 *  v                  [IN/OUT]    Is the horizontal scrollbar object
 *  alpha_blend_layer  [IN]        Is the horizontal scrollbar alpha_blend_layer
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_scrollbar_set_alpha_blend_layer(horizontal_scrollbar *v, gdi_handle alpha_blend_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT (v != NULL);
    v->alpha_blend_layer = alpha_blend_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_scrollbar_get_alpha_blend_layer
 * DESCRIPTION
 *  get horizontal scrollbar alpha_blend_layer
 * PARAMETERS
 *  v           [IN/OUT]    Is the horizontal scrollbar object
 * RETURNS
 *  horizontal scrollbar's alpha_blend_layer
 *****************************************************************************/
gdi_handle gui_horizontal_scrollbar_get_alpha_blend_layer(horizontal_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT (v != NULL);
    return v->alpha_blend_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_scrollbar_reset_alpha_blend_layer
 * DESCRIPTION
 *  reset horizontal scrollbar alpha_blend_layer
 * PARAMETERS
 *  v             [IN/OUT]    Is the horizontal scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_scrollbar_reset_alpha_blend_layer(horizontal_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT (v != NULL);
    v->alpha_blend_layer = GDI_NULL_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_scrollbar_register_hide_callback
 * DESCRIPTION
 *  register horizontal scrollbar hide_callback
 * PARAMETERS
 *  v                [IN/OUT]    Is the horizontal scrollbar object
 *  hide_callback    [IN]        Is the horizontal scrollbar hide callback function
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_scrollbar_register_hide_callback(horizontal_scrollbar *v, void(*hide_callback)(S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT (v != NULL);
    v->hide_callback = hide_callback;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_scrollbar_reset_hide_callback
 * DESCRIPTION
 *  reset horizontal scrollbar hide_callback
 * PARAMETERS
 *  v                [IN/OUT]    Is the horizontal scrollbar object
 *  hide_callback    [IN]        Is the horizontal scrollbar hide callback function
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_scrollbar_reset_hide_callback(horizontal_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT (v != NULL);
    v->hide_callback = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_scrollbar_enable_clear_background
 * DESCRIPTION
 *  Enable horizontal scrollbar clear background or not
 * PARAMETERS
 *  v            [IN/OUT]    Is the horizontal scrollbar object
 *  enable       [IN]        Enable scrollbar clear background or not
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_scrollbar_enable_clear_background(horizontal_scrollbar *v, MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT (v != NULL);
    if(enable)
    {
        v->flags &= ~UI_HORIZONTAL_SCROLLBAR_NOT_CLEAR_BACKGROUND;
    }
    else
    {
        v->flags |= UI_HORIZONTAL_SCROLLBAR_NOT_CLEAR_BACKGROUND;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_scrollbar_auto_hide_scroll_button
 * DESCRIPTION
 *  To check scrollbar auto hide scroll button or not
 * PARAMETERS
 *  v            [IN/OUT]    Is the horizontal scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_horizontal_scrollbar_auto_hide_scroll_button(horizontal_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT (v != NULL);
    return (v->flags & UI_HORIZONTAL_SCROLLBAR_AUTO_HIDE_SCROLL_BUTTON) ? MMI_TRUE : MMI_FALSE;  
}


/*****************************************************************************
 * FUNCTION
 *  gui_resize_horizontal_scrollbar
 * DESCRIPTION
 *  Changes the size of a scrollbar
 * PARAMETERS
 *  v           [IN/OUT]    Is the horizontal scrollbar object
 *  width       [IN]        Is the new width
 *  height      [IN]        Is the new height
 * RETURNS
 *  void
 *****************************************************************************/
void gui_resize_horizontal_scrollbar(horizontal_scrollbar *v, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 button_width;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->width = width;
    v->height = height;
    button_width = 0;

    button_width = gui_horizontal_scrollbar_get_button_width(v);
    
    v->left_button.height = height;
    v->left_button.width = button_width;
    v->right_button.height = height;
    v->right_button.width = button_width;

    v->left_button.x = v->x;
    v->right_button.x = v->x + v->width - v->right_button.width;
    v->left_button.y = v->y;
    v->right_button.y = v->y;
    v->scroll_button.y = v->y;
    v->scroll_button.height = v->height;
}


#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_scrollbar_button1_show_clicked
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_horizontal_scrollbar_button1_show_clicked(horizontal_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(v->left_button.flags & UI_BUTTON_SHIFT_BUTTON1))
    {
        v->left_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        gui_redraw_horizontal_scrollbar(v, MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_scrollbar_button1_show_unclicked
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_horizontal_scrollbar_button1_show_unclicked(horizontal_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->left_button.flags & UI_BUTTON_SHIFT_BUTTON1)
    {
        v->left_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        gui_redraw_horizontal_scrollbar(v, MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_scrollbar_button2_show_clicked
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_horizontal_scrollbar_button2_show_clicked(horizontal_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(v->right_button.flags & UI_BUTTON_SHIFT_BUTTON1))
    {
        v->right_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        gui_redraw_horizontal_scrollbar(v, MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_scrollbar_button2_show_unclicked
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_horizontal_scrollbar_button2_show_unclicked(horizontal_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->right_button.flags & UI_BUTTON_SHIFT_BUTTON1)
    {
        v->right_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        gui_redraw_horizontal_scrollbar(v, MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_scrollbar_set_minimum_pen_offset
 * DESCRIPTION
 *  Set the minimum scrolling offset in scrollbar.
 *  
 *  Used in GUI_SCROLLBAR_PEN_STATE_AREA1, GUI_SCROLLBAR_PEN_STATE_AREA2,
 *  GUI_SCROLLBAR_PEN_STATE_BUTTON1, GUI_SCROLLBAR_PEN_STATE_BUTTON2
 * PARAMETERS
 *  v               [IN/OUT]    Is the horizontal scrollbar object
 *  min_offset      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_scrollbar_set_minimum_pen_offset(horizontal_scrollbar *v, S32 min_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->min_pen_offset = min_offset;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_scrollbar_set_pen_self_scroll
 * DESCRIPTION
 *  Setup whether the scrollbar is redrawn when it is scrolled by pen.
 *  If 'enable' is MMI_FALSE, the scrollbar is scrolled by its parent GUI component.
 * PARAMETERS
 *  h           [IN/OUT]        Is the horizontal scrollbar object
 *  enable      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_scrollbar_set_pen_self_scroll(horizontal_scrollbar *h, BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (enable)
    {
        h->pen_self_scroll = 1;
    }
    else
    {
        h->pen_self_scroll = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_scrollbar_register_get_diff
 * DESCRIPTION
 *  Register get diff function
 * PARAMETERS
 *  v           : [IN]      The pointer of scrollbar 
 *  get_diff    : [IN]      The new get_diff function of horizontal scrollbar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_scrollbar_register_get_diff(horizontal_scrollbar *v, S32 (*get_diff)(gui_scrollbar_dir_enum dir))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->get_diff = get_diff;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_scrollbar_reset_get_diff
 * DESCRIPTION
 *  Reset get diff function
 * PARAMETERS
 *  v           : [IN]      The pointer of scrollbar 
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_scrollbar_reset_get_diff(horizontal_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->get_diff = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_scrollbar_reconfigure_pen_value
 * DESCRIPTION
 *  Reconfigure scrollbar position if it is  scrolled passively by parent components
 *  
 *  Take inline editor as example, if gui_horizontal_scrollbar_translate_pen_event() returns 1
 *  for GUI_SCROLLBAR_PEN_JUMP_TO_I, Inline editor might set scrollbar value to 0 instead of 1.
 *  As a result, scroll button might be moved away from the original pen down position,
 *  and this function should be used to fix internal scrollbar states.
 * PARAMETERS
 *  v       [IN/OUT]    Is the horizontal scrollbar object
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_scrollbar_reconfigure_pen_value(horizontal_scrollbar *v, S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_scrollbar_pen_state_struct *pen_state;
    U32 new_value;
    S32 sbutton_x1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(y);
    pen_state = &v->pen_state;

    if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_SBUTTON)
    {
        sbutton_x1 = v->scroll_button.x;

        gui_scrollbar_translate_pen_position(
            NULL,
            v,
            pen_state->initial_sbutton_pos + (x - pen_state->initial_pen_down_pos),
            pen_state->remain_space,
            &new_value);

        if ((v->value < pen_state->previous_value && new_value > v->value) ||
            (v->value > pen_state->previous_value && new_value < v->value))
        {
            /* Note: x might not be on scroll button! */
            pen_state->initial_pen_down_pos = x;
            if (v->flags & UI_HORIZONTAL_SCROLLBAR_TYPE_BUTTONLESS)
            {
                pen_state->initial_sbutton_pos = (S16) (sbutton_x1 - v->x);
            }
            else
            {
                pen_state->initial_sbutton_pos = (S16) (sbutton_x1 - v->x - v->left_button.width);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_scrollbar_translate_pen_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v                   [IN/OUT]         
 *  pen_event           [IN]        
 *  x                   [IN]        
 *  y                   [IN]        
 *  scrollbar_event     [OUT]         
 *  scrollbar_param     [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
BOOL gui_horizontal_scrollbar_translate_pen_event(
        horizontal_scrollbar *v,
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_scrollbar_pen_enum *scrollbar_event,
        gui_pen_event_param_struct *scrollbar_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
     * If the Left/Right button is pressed or released, we need to gui_redraw_horizontal_scrollbar()
     * even if GUI_SCROLLBAR_PEN_JUMP_TO_I is also returned.
     *
     * The reason is that parent component might discard the scrollbar event and not redraw itself.
     */

    BOOL ret;
    S32 sbutton_x1, sbutton_x2, left_button_x2, right_button_x1;
    gui_scrollbar_pen_state_struct *pen_state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pen_state = &v->pen_state;
    ret = MMI_TRUE;
    sbutton_x1 = v->scroll_button.x;
    sbutton_x2 = sbutton_x1 + v->scroll_button.width - 1;
    left_button_x2 = v->left_button.x + v->left_button.width - 1;
    right_button_x1 = v->right_button.x;

    *scrollbar_event = GUI_SCROLLBAR_PEN_NONE;
    GUI_PEN_EVENT_PARAM_SET_VOID(scrollbar_param);
    
#ifdef __MMI_FTE_SUPPORT__
    if(!(v->style & GUI_SCROLLBAR_STYLE_WIDER))
    {
        ret = MMI_FALSE;
        pen_state->state = GUI_SCROLLBAR_PEN_STATE_INVALID;
        return ret;
    }
#endif

    switch (pen_event)
    {
        case MMI_PEN_EVENT_DOWN:
            if (PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height))
            {
                pen_state->initial_pen_down_pos = x;
                if (v->flags & UI_HORIZONTAL_SCROLLBAR_TYPE_BUTTONLESS)
                {
                    pen_state->initial_sbutton_pos = (S16) (sbutton_x1 - v->x);
                }
                else
                {
                    pen_state->initial_sbutton_pos = (S16) (sbutton_x1 - v->x - v->left_button.width);
                }
                pen_state->original_value = v->value;

                if (x <= left_button_x2 && v->left_button.height > 0)
                {
                    gui_horizontal_scrollbar_button1_show_clicked(v);

                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_BUTTON1;
                    gui_scrollbar_translate_pen_less(NULL, v, scrollbar_event, scrollbar_param);
                }
                else if (x >= right_button_x1 && v->right_button.height > 0)
                {
                    gui_horizontal_scrollbar_button2_show_clicked(v);

                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_BUTTON2;
                    gui_scrollbar_translate_pen_more(
                        NULL,
                        v,
                        scrollbar_event,
                        scrollbar_param);
                }
                else if (x >= sbutton_x1 && x <= sbutton_x2)
                {
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_SBUTTON;
                }
                else if (x < sbutton_x1)
                {
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_AREA1;
                    gui_scrollbar_translate_pen_less(NULL, v, scrollbar_event, scrollbar_param);
                }
                else
                {
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_AREA2;
                    gui_scrollbar_translate_pen_more(
                        NULL,
                        v,
                        scrollbar_event,
                        scrollbar_param);
                }
            }
            else
            {
                ret = MMI_FALSE;
                pen_state->state = GUI_SCROLLBAR_PEN_STATE_INVALID;
            }
            break;

        case MMI_PEN_EVENT_LONG_TAP:
            /* FALLTHROUGH no break */
        case MMI_PEN_EVENT_REPEAT:
            if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_BUTTON1)
            {
                gui_scrollbar_translate_pen_less(NULL, v, scrollbar_event, scrollbar_param);
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_BUTTON2)
            {
                gui_scrollbar_translate_pen_more(
                    NULL,
                    v,
                    scrollbar_event,
                    scrollbar_param);
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_AREA1)
            {
                if (PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height) && (x < sbutton_x1))
                {
                    gui_scrollbar_translate_pen_less(NULL, v, scrollbar_event, scrollbar_param);
                }
                else
                {
                    /* Scroll button is moved to pen position */
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_AREA1_OUTSIDE;
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_AREA2)
            {
                if (PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height) && (x > sbutton_x2))
                {
                    gui_scrollbar_translate_pen_more(
                        NULL,
                        v,
                        scrollbar_event,
                        scrollbar_param);
                }
                else
                {
                    /* Scroll button is moved to pen position */
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_AREA2_OUTSIDE;
                }
            }
            break;

        case MMI_PEN_EVENT_UP:
            /* FALLTHROUGH no break */
        case MMI_PEN_EVENT_MOVE:
            if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_BUTTON1)
            {
                if (pen_event == MMI_PEN_EVENT_UP)
                {
                    gui_horizontal_scrollbar_button1_show_unclicked(v);
                }
                else if (!PEN_CHECK_BOUND
                         (x, y, v->left_button.x, v->left_button.y, v->left_button.width, v->left_button.height))
                {
                    gui_horizontal_scrollbar_button1_show_unclicked(v);

                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_BUTTON1_OUTSIDE;
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_BUTTON1_OUTSIDE)
            {
                if (pen_event == MMI_PEN_EVENT_UP)
                {
                    /* Do nothing */
                    MMI_DBG_ASSERT(!(v->left_button.flags & UI_BUTTON_SHIFT_BUTTON1));
                }
                else if (PEN_CHECK_BOUND
                         (x, y, v->left_button.x, v->left_button.y, v->left_button.width, v->left_button.height))
                {
                    gui_horizontal_scrollbar_button1_show_clicked(v);

                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_BUTTON1;
                    gui_scrollbar_translate_pen_less(NULL, v, scrollbar_event, scrollbar_param);
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_BUTTON2)
            {
                if (pen_event == MMI_PEN_EVENT_UP)
                {
                    gui_horizontal_scrollbar_button2_show_unclicked(v);
                }
                else if (!PEN_CHECK_BOUND
                         (x, y, v->right_button.x, v->right_button.y, v->right_button.width, v->right_button.height))
                {
                    gui_horizontal_scrollbar_button2_show_unclicked(v);

                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_BUTTON2_OUTSIDE;
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_BUTTON2_OUTSIDE)
            {
                if (pen_event == MMI_PEN_EVENT_UP)
                {
                    /* Do nothing */
                    MMI_DBG_ASSERT(!(v->right_button.flags & UI_BUTTON_SHIFT_BUTTON1));
                }
                else if (PEN_CHECK_BOUND
                         (x, y, v->right_button.x, v->right_button.y, v->right_button.width, v->right_button.height))
                {
                    gui_horizontal_scrollbar_button2_show_clicked(v);

                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_BUTTON2;
                    gui_scrollbar_translate_pen_more(
                        NULL,
                        v,
                        scrollbar_event,
                        scrollbar_param);
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_AREA1_OUTSIDE)
            {
                if (PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height) && (x < sbutton_x1))
                {
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_AREA1;
                    gui_scrollbar_translate_pen_less(NULL, v, scrollbar_event, scrollbar_param);
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_AREA1)
            {
                if (!PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height) || !(x < sbutton_x1))
                {
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_AREA1_OUTSIDE;
                }
            }
            if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_AREA2_OUTSIDE)
            {
                if (PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height) && (x > sbutton_x2))
                {
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_AREA2;
                    gui_scrollbar_translate_pen_more(
                        NULL,
                        v,
                        scrollbar_event,
                        scrollbar_param);
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_AREA2)
            {
                if (!PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height) || !(x > sbutton_x2))
                {
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_AREA2_OUTSIDE;
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_SBUTTON)
            {
                if (PEN_ABS(y, v->y) > GUI_SCROLLBAR_VALID_RANGE)
                {
                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_SBUTTON_OUTSIDE;
                    /* Reset to original position */
                    *scrollbar_event = GUI_SCROLLBAR_PEN_JUMP_TO_I;
                    GUI_PEN_EVENT_PARAM_SET_INTEGER(scrollbar_param, (int)pen_state->original_value);
                }
                else
                {
                    U32 new_value;

                    gui_scrollbar_translate_pen_position(
                        NULL,
                        v,
                        pen_state->initial_sbutton_pos + (x - pen_state->initial_pen_down_pos),
                        pen_state->remain_space,
                        &new_value);
                    if (new_value != v->value)
                    {
                        *scrollbar_event = GUI_SCROLLBAR_PEN_JUMP_TO_I;
                        GUI_PEN_EVENT_PARAM_SET_INTEGER(scrollbar_param, (int)new_value);
                    }
                }
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_SBUTTON_OUTSIDE)
            {
                if (PEN_ABS(y, v->y) < GUI_SCROLLBAR_VALID_RANGE)
                {
                    U32 new_value;

                    pen_state->state = GUI_SCROLLBAR_PEN_STATE_SBUTTON;

                    gui_scrollbar_translate_pen_position(
                        NULL,
                        v,
                        pen_state->initial_sbutton_pos + (x - pen_state->initial_pen_down_pos),
                        pen_state->remain_space,
                        &new_value);
                    if (new_value != v->value)
                    {
                        *scrollbar_event = GUI_SCROLLBAR_PEN_JUMP_TO_I;
                        GUI_PEN_EVENT_PARAM_SET_INTEGER(scrollbar_param, (int)new_value);
                    }
                }
            }

            if (pen_event == MMI_PEN_EVENT_UP)
            {
                pen_state->state = GUI_SCROLLBAR_PEN_STATE_INVALID;
            }

            break;

        case MMI_PEN_EVENT_ABORT:
            if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_SBUTTON)
            {
                /* Reset to original position */
                //*scrollbar_event = GUI_SCROLLBAR_PEN_JUMP_TO_I;
                //GUI_PEN_EVENT_PARAM_SET_INTEGER(scrollbar_param, (int)pen_state->original_value);
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_BUTTON1)
            {
                gui_horizontal_scrollbar_button1_show_unclicked(v);
            }
            else if (pen_state->state == GUI_SCROLLBAR_PEN_STATE_BUTTON2)
            {
                gui_horizontal_scrollbar_button2_show_unclicked(v);
            }

            pen_state->state = GUI_SCROLLBAR_PEN_STATE_INVALID;
            break;

        default:
            MMI_ASSERT(0);
    }

    if (ret)
    {
        /*
         * Scrollbar does not change its value. Instead, parent components should change the value
         * * if GUI_SCROLLBAR_PEN_JUMP_TO_I is returned.
         */
        pen_state->previous_value = v->value;
    }

    if (ret && v->pen_self_scroll && *scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
    {
        v->value = scrollbar_param->_u.i;
        gui_redraw_horizontal_scrollbar(v, MMI_TRUE);
    }

    return ret;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  gui_enable_scrollbar_redraw_clip
 * DESCRIPTION
 *  enabel scrollbar self redraw clip
 * PARAMETERS
 *  enable      [IN]        enable or not
 * RETURNS
 *  void
 *****************************************************************************/
void gui_enable_scrollbar_redraw_clip(MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_scrollbar_redraw_clip_enable = enable;
}


/***************************************************************************** 
 * Horizontal Progress Indicator
 *****************************************************************************/

UI_horizontal_progress_indicator_theme *current_horizontal_progress_indicator_theme = NULL;


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_progress_indicator_theme
 * DESCRIPTION
 *  Applies the current theme to the progress indicator object
 * PARAMETERS
 *  pi      [IN]        Is the horizontal progress indicator object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_horizontal_progress_indicator_theme(horizontal_progress_indicator *pi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pi->flags = current_horizontal_progress_indicator_theme->flags;
    pi->background_filler = current_horizontal_progress_indicator_theme->background_filler;
    pi->foreground_filler = current_horizontal_progress_indicator_theme->foreground_filler;
    pi->n_fillers = current_horizontal_progress_indicator_theme->n_fillers;
    pi->percentages = current_horizontal_progress_indicator_theme->percentages;
    pi->block_width = current_horizontal_progress_indicator_theme->block_width;
    pi->block_gap = current_horizontal_progress_indicator_theme->block_gap;
    pi->border_gap = current_horizontal_progress_indicator_theme->border_gap;
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_horizontal_progress_indicator_ex
 * DESCRIPTION
 *  creates a horizontal progress indicator object
 * PARAMETERS
 *  pi          [IN]        Is the horizontal progress indicator object (pre-allocated)
 *  x           [IN]        Left-top corner
 *  y           [IN]        Left-top corner
 *  width               [IN]        width of horizontal progress
 *  height              [IN]        height of horizontal progress
 *  target_lcd          [IN]        target lcd of horizontal progress
 *  target_layer        [IN]        target layer of horizontal progress
 *  alpha_blend_layer   [IN]        alpha blend layer of horizontal progress
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_horizontal_progress_indicator_ex(
    horizontal_progress_indicator *pi, 
    S32 x, 
    S32 y, 
    S32 width, 
    S32 height,
    gdi_handle target_lcd,
    gdi_handle target_layer,
    gdi_handle alpha_blend_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pi->x = x;
    pi->y = y;
    pi->width = width;
    pi->height = height;
    gui_set_horizontal_progress_indicator_theme(pi);
    pi->range = 100;
    pi->value = 0;
    pi->target_lcd = target_lcd;
    pi->target_layer = target_layer;
    pi->alpha_blend_layer = alpha_blend_layer;
    pi->hide_callback = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_horizontal_progress_indicator
 * DESCRIPTION
 *  creates a horizontal progress indicator object
 * PARAMETERS
 *  pi          [IN]        Is the horizontal progress indicator object (pre-allocated)
 *  x           [IN]        Left-top corner
 *  y           [IN]        Left-top corner
 *  width       [IN]        the width of horizontal progress
 *  height      [IN]        the height of horizontal progress
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_horizontal_progress_indicator(horizontal_progress_indicator *pi, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_create_horizontal_progress_indicator_ex(pi, x, y, width, height, GDI_NULL_HANDLE, GDI_NULL_HANDLE, GDI_NULL_HANDLE);
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_progress_indicator_range
 * DESCRIPTION
 *  Sets the range of a horizontal progress indicator object
 * PARAMETERS
 *  pi          [IN]        Is the horizontal progress indicator object
 *  range       [IN]        Is the range (positive number Ex: Available text length in an inputbox)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_horizontal_progress_indicator_range(horizontal_progress_indicator *pi, S32 range)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (range < 0)
    {
        range = 0;
    }
    pi->range = (U32) range;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_progress_indicator_value
 * DESCRIPTION
 *  Sets the value of a horizontal progress indicator object
 * PARAMETERS
 *  pi          [IN]        Is the horizontal progress indicator object
 *  value       [IN]        Is the value (positive number Ex: current text length in an inputbox)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_horizontal_progress_indicator_value(horizontal_progress_indicator *pi, S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (value < 0)
    {
        value = 0;
    }
    pi->value = (U32) value;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_progress_indicator_set_target_lcd
 * DESCRIPTION
 *  Sets the target lcd of a horizontal progress indicator object
 * PARAMETERS
 *  pi          [IN]        Is the horizontal progress indicator object
 *  target_lcd  [IN]        Is the target lcd of horizontal progress indicator
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_progress_indicator_set_target_lcd(horizontal_progress_indicator *pi, gdi_handle target_lcd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pi->target_lcd = target_lcd;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_progress_indicator_get_target_lcd
 * DESCRIPTION
 *  gets the target lcd of a horizontal progress indicator object
 * PARAMETERS
 *  pi          [IN]        Is the horizontal progress indicator object
 * RETURNS
 *  horizontal progress indicator target lcd
 *****************************************************************************/
gdi_handle gui_horizontal_progress_indicator_get_target_lcd(horizontal_progress_indicator *pi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return pi->target_lcd;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_progress_indicator_reset_target_lcd
 * DESCRIPTION
 *  reset the target lcd of a horizontal progress indicator object
 * PARAMETERS
 *  pi          [IN]        Is the horizontal progress indicator object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_progress_indicator_reset_target_lcd(horizontal_progress_indicator *pi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pi->target_lcd = GDI_NULL_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_progress_indicator_set_target_layer
 * DESCRIPTION
 *  Sets the target layer of a horizontal progress indicator object
 * PARAMETERS
 *  pi           [IN]        Is the horizontal progress indicator object
 *  target_layer [IN]        Is the target lcd of horizontal progress indicator
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_progress_indicator_set_target_layer(horizontal_progress_indicator *pi, gdi_handle target_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pi->target_layer = target_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_progress_indicator_get_target_layer
 * DESCRIPTION
 *  gets the target layer of a horizontal progress indicator object
 * PARAMETERS
 *  pi          [IN]        Is the horizontal progress indicator object
 * RETURNS
 *  horizontal progress indicator target layer
 *****************************************************************************/
gdi_handle gui_horizontal_progress_indicator_get_target_layer(horizontal_progress_indicator *pi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return pi->target_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_progress_indicator_reset_target_layer
 * DESCRIPTION
 *  resets the target layer of a horizontal progress indicator object
 * PARAMETERS
 *  pi           [IN]        Is the horizontal progress indicator object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_progress_indicator_reset_target_layer(horizontal_progress_indicator *pi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pi->target_layer = GDI_NULL_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_progress_indicator_set_alpha_blend_layer
 * DESCRIPTION
 *  Sets the alpha_blend_layer of a horizontal progress indicator object
 * PARAMETERS
 *  pi           [IN]        Is the horizontal progress indicator object
 *  alpha_blend_layer [IN]        Is the target lcd of horizontal progress indicator
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_progress_indicator_set_alpha_blend_layer(horizontal_progress_indicator *pi, gdi_handle alpha_blend_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pi->alpha_blend_layer = alpha_blend_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_progress_indicator_get_alpha_blend_layer
 * DESCRIPTION
 *  gets the alpha_blend_layer of a horizontal progress indicator object
 * PARAMETERS
 *  pi          [IN]        Is the horizontal progress indicator object
 * RETURNS
 *  horizontal progress indicator alpha_blend_layer
 *****************************************************************************/
gdi_handle gui_horizontal_progress_indicator_get_alpha_blend_layer(horizontal_progress_indicator *pi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return pi->alpha_blend_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_progress_indicator_reset_alpha_blend_layer
 * DESCRIPTION
 *  resets the alpha_blend_layer of a horizontal progress indicator object
 * PARAMETERS
 *  pi           [IN]        Is the horizontal progress indicator object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_progress_indicator_reset_alpha_blend_layer(horizontal_progress_indicator *pi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pi->alpha_blend_layer = GDI_NULL_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_progress_indicator_register_hide_callback
 * DESCRIPTION
 *  register hide callback funtion of a horizontal progress indicator object
 * PARAMETERS
 *  pi            [IN]        Is the horizontal progress indicator object
 *  hide_callback [IN]        Is the hide_callback of horizontal progress indicator
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_progress_indicator_register_hide_callback(horizontal_progress_indicator *pi, void (*hide_callback)(S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pi->hide_callback = hide_callback;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_progress_indicator_reset_hide_callback
 * DESCRIPTION
 *  reset hide callback funtion of a horizontal progress indicator object
 * PARAMETERS
 *  pi            [IN]        Is the horizontal progress indicator object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_progress_indicator_reset_hide_callback(horizontal_progress_indicator *pi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pi->hide_callback = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_horizontal_progress_indicator
 * DESCRIPTION
 *  Displays a horizontal progress indicator
 * PARAMETERS
 *  pi      [IN]        Is the horizontal progress indicator object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_horizontal_progress_indicator(horizontal_progress_indicator *pi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    S32 ax1, ay1, ax2, ay2;
    S32 fx1, fy1, fx2, fy2;
    S32 fill_width, total_width;
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = pi->x;
    y1 = pi->y;
    x2 = x1 + pi->width;
    y2 = y1 + pi->height;
    ax1 = x1 + pi->border_gap;
    ay1 = y1 + pi->border_gap;
    ax2 = x2 - pi->border_gap;
    ay2 = y2 - pi->border_gap;
    total_width = ax2 - ax1 + 1;
    if (pi->range == 0)
    {
        fill_width = total_width;
    }
    else
    {
        fill_width = pi->value * total_width / pi->range;
    }
    fx1 = ax1;
    fy1 = ay1;
    fy2 = ay2;

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
#endif
    old_lcd_handle = gui_setup_target_lcd_and_layer(pi->target_lcd, pi->target_layer, pi->alpha_blend_layer);
    
    gui_push_and_set_clip(x1, y1, x2 + 2, y2 + 2);
    if(pi->hide_callback)
    {
        pi->hide_callback(x1, y1, x2, y2);
    }
    gui_draw_filled_area(x1, y1, x2, y2, pi->background_filler);

    if (pi->value > 0)
    {
        if (pi->flags & UI_HORIZONTAL_PROGRESS_INDICATOR_TYPE_MULTICOLOR)
        {
            if (pi->flags & UI_HORIZONTAL_PROGRESS_INDICATOR_TYPE_STEP)
            {
                S32 block_width, block_gap, sum_of_widths;
                S32 i = 0, j = 0;
                UI_filled_area *f = &pi->foreground_filler[j];

                block_width = pi->block_width;
                block_gap = pi->block_gap;
                sum_of_widths = pi->percentages[j] * total_width / 100;
                while (i < fill_width)
                {
                    if (i > sum_of_widths)
                    {
                        j++;
                        sum_of_widths += pi->percentages[j] * total_width / 100;
                        if (j >= pi->n_fillers)
                        {
                            j = pi->n_fillers - 1;
                        }
                    }
                    f = &pi->foreground_filler[j];
                    fx1 = i + ax1;
                    fx2 = fx1 + block_width - 1;
                    if (fx2 > ax2)
                    {
                        fx2 = ax2;
                    }
                    gui_draw_filled_area(fx1, fy1, fx2, fy2, f);
                    i += block_width;
                    i += block_gap;
                }
            }
            else
            {
                S32 i = 0, j = 0, w, done = 0, sum_of_widths = 0;
                UI_filled_area *f;

                i = 0;
                for (j = 0; (j < pi->n_fillers) && (!done); j++)
                {
                    f = &pi->foreground_filler[j];
                    fx1 = i + ax1;
                    w = pi->percentages[j] * total_width / 100;
                    sum_of_widths += w;
                    if (sum_of_widths > fill_width)
                    {
                        w -= (sum_of_widths - fill_width);
                        done = 1;
                    }
                    fx2 = fx1 + w - 1;
                    if (fx2 > ax2)
                    {
                        fx2 = ax2;
                    }
                    gui_draw_filled_area(fx1, fy1, fx2, fy2, f);
                    i += w;
                }
            }
        }
        else
        {
            if (pi->flags & UI_HORIZONTAL_PROGRESS_INDICATOR_TYPE_STEP)
            {
                S32 block_width, block_gap;
                S32 i = 0;

                block_width = pi->block_width;
                block_gap = pi->block_gap;
                while (i < fill_width)
                {
                    fx1 = i + ax1;
                    fx2 = fx1 + block_width - 1;
                    if (fx2 > ax2)
                    {
                        fx2 = ax2;
                    }
                    gui_draw_filled_area(fx1, fy1, fx2, fy2, pi->foreground_filler);
                    i += block_width;
                    i += block_gap;
                }
            }
            else
            {
                fx2 = ax1 + fill_width;
                if (fx2 > ax2)
                {
                    fx2 = ax2;
                }
                gui_draw_filled_area(fx1, fy1, fx2, fy2, pi->foreground_filler);
            }
        }
    }
    gui_pop_clip();

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
#endif
    gui_restore_target_lcd_and_layer(pi->target_lcd, pi->target_layer, pi->alpha_blend_layer, old_lcd_handle);

}

/***************************************************************************** 
 * Vertical Progress Indicator
 *****************************************************************************/

UI_vertical_progress_indicator_theme *current_vertical_progress_indicator_theme = NULL;


/*****************************************************************************
 * FUNCTION
 *  gui_set_vertical_progress_indicator_theme
 * DESCRIPTION
 *  Applies the current theme to the progress indicator object
 * PARAMETERS
 *  pi      [IN]        Is the vertical progress indicator object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_vertical_progress_indicator_theme(vertical_progress_indicator *pi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pi->flags = current_vertical_progress_indicator_theme->flags;
    pi->background_filler = current_vertical_progress_indicator_theme->background_filler;
    pi->foreground_filler = current_vertical_progress_indicator_theme->foreground_filler;
    pi->n_fillers = current_vertical_progress_indicator_theme->n_fillers;
    pi->percentages = current_vertical_progress_indicator_theme->percentages;
    pi->block_height = current_vertical_progress_indicator_theme->block_height;
    pi->block_gap = current_vertical_progress_indicator_theme->block_gap;
    pi->border_gap = current_vertical_progress_indicator_theme->border_gap;
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_vertical_progress_indicator_ex
 * DESCRIPTION
 *  creates a vertical progress indicator object
 * PARAMETERS
 *  pi          [IN]        Is the vertical progress indicator object (pre-allocated)
 *  x           [IN]        Left-top corner
 *  y           [IN]        Left-top corner
 *  width               [IN]        the width of vertical progress
 *  height              [IN]        the height of vertical progress
 *  target_lcd          [IN]        target lcd of vertical progress indicator object
 *  target_layer        [IN]        target layer of vertical progress indicator object
 *  alpha_blend_layer   [IN]        alpha blend layer of vertical progress indicator object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_vertical_progress_indicator_ex(
        vertical_progress_indicator *pi,
        S32 x,
        S32 y, 
        S32 width, 
        S32 height, 
        gdi_handle target_lcd, 
        gdi_handle target_layer,
        gdi_handle alpha_blend_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pi->x = x;
    pi->y = y;
    pi->width = width;
    pi->height = height;
    gui_set_vertical_progress_indicator_theme(pi);
    pi->range = 100;
    pi->value = 0;
    pi->target_lcd = target_lcd;
    pi->target_layer = target_layer;
    pi->alpha_blend_layer = alpha_blend_layer;
    pi->hide_callbck = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_vertical_progress_indicator
 * DESCRIPTION
 *  creates a vertical progress indicator object
 * PARAMETERS
 *  pi          [IN]        Is the vertical progress indicator object (pre-allocated)
 *  x           [IN]        Left-top corner
 *  y           [IN]        Left-top corner
 *  width       [IN]        the width of vertical progress
 *  height      [IN]        the height of vertical progress
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_vertical_progress_indicator(vertical_progress_indicator *pi, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_create_vertical_progress_indicator_ex(pi, x, y, width, height, GDI_NULL_HANDLE, GDI_NULL_HANDLE, GDI_NULL_HANDLE);
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_vertical_progress_indicator_range
 * DESCRIPTION
 *  Sets the range of a vertical progress indicator object
 * PARAMETERS
 *  pi          [IN]        Is the vertical progress indicator object
 *  range       [IN]        Is the range (positive number Ex: Available text length in an inputbox)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_vertical_progress_indicator_range(vertical_progress_indicator *pi, S32 range)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (range < 0)
    {
        range = 0;
    }
    pi->range = (U32) range;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_vertical_progress_indicator_value
 * DESCRIPTION
 *  Sets the value of a vertical progress indicator object
 * PARAMETERS
 *  pi          [IN]        Is the vertical progress indicator object
 *  value       [IN]        Is the value (positive number Ex: current text length in an inputbox)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_vertical_progress_indicator_value(vertical_progress_indicator *pi, S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (value < 0)
    {
        value = 0;
    }
    pi->value = (U32) value;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_progress_indicator_set_target_lcd
 * DESCRIPTION
 *  Sets the value of a vertical progress indicator object
 * PARAMETERS
 *  pi          [IN]        Is the vertical progress indicator object
 *  target_lcd  [IN]        Is the target lcd of vertical progress indicator
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vertical_progress_indicator_set_target_lcd(vertical_progress_indicator *pi, gdi_handle target_lcd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pi->target_lcd = target_lcd;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_progress_indicator_get_target_lcd
 * DESCRIPTION
 *  gets the value of a vertical progress indicator object
 * PARAMETERS
 *  pi          [IN]        Is the vertical progress indicator object
 * RETURNS
 *  vertical progress indicator target lcd
 *****************************************************************************/
gdi_handle gui_vertical_progress_indicator_get_target_lcd(vertical_progress_indicator *pi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return pi->target_lcd;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_progress_indicator_reset_target_lcd
 * DESCRIPTION
 *  resets the value of a vertical progress indicator object
 * PARAMETERS
 *  pi          [IN]        Is the vertical progress indicator object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vertical_progress_indicator_reset_target_lcd(vertical_progress_indicator *pi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pi->target_lcd = GDI_NULL_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_progress_indicator_set_target_layer
 * DESCRIPTION
 *  Sets the value of a vertical progress indicator object
 * PARAMETERS
 *  pi            [IN]        Is the vertical progress indicator object
 *  target_layer  [IN]        Is the target layer of vertical progress indicator
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vertical_progress_indicator_set_target_layer(vertical_progress_indicator *pi, gdi_handle target_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pi->target_layer = target_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_progress_indicator_get_target_layer
 * DESCRIPTION
 *  gets the target layer a vertical progress indicator object
 * PARAMETERS
 *  pi          [IN]        Is the vertical progress indicator object
 * RETURNS
 *  vertical progress indicator target lcd
 *****************************************************************************/
gdi_handle gui_vertical_progress_indicator_get_target_layer(vertical_progress_indicator *pi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return pi->target_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_progress_indicator_reset_target_layer
 * DESCRIPTION
 *  resets the target layer of a vertical progress indicator object
 * PARAMETERS
 *  pi            [IN]        Is the vertical progress indicator object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vertical_progress_indicator_reset_target_layer(vertical_progress_indicator *pi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pi->target_layer = GDI_NULL_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_progress_indicator_set_alpha_blend_layer
 * DESCRIPTION
 *  Sets the alpha_blend_layer a vertical progress indicator object
 * PARAMETERS
 *  pi                 [IN]        Is the vertical progress indicator object
 *  alpha_blend_layer  [IN]        Is the alpha_blend_layer of vertical progress indicator
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vertical_progress_indicator_set_alpha_blend_layer(vertical_progress_indicator *pi, gdi_handle alpha_blend_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pi->alpha_blend_layer = alpha_blend_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_progress_indicator_get_alpha_blend_layer
 * DESCRIPTION
 *  gets the alpha_blend_layer a vertical progress indicator object
 * PARAMETERS
 *  pi          [IN]        Is the vertical progress indicator object
 * RETURNS
 *  vertical progress indicator target lcd
 *****************************************************************************/
gdi_handle gui_vertical_progress_indicator_get_alpha_blend_layer(vertical_progress_indicator *pi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return pi->alpha_blend_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_progress_indicator_reset_alpha_blend_layer
 * DESCRIPTION
 *  resets the alpha_blend_layer of a vertical progress indicator object
 * PARAMETERS
 *  pi            [IN]        Is the vertical progress indicator object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vertical_progress_indicator_reset_alpha_blend_layer(vertical_progress_indicator *pi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pi->alpha_blend_layer = GDI_NULL_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_progress_indicator_register_hide_callback
 * DESCRIPTION
 *  Sets the value of a vertical progress indicator object
 * PARAMETERS
 *  pi             [IN]        Is the vertical progress indicator object
 *  hide_callback  [IN]        Is the hide callback of vertical progress indicator
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vertical_progress_indicator_register_hide_callback(vertical_progress_indicator *pi, void (*hide_callback)(S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pi->hide_callbck = hide_callback;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_progress_indicator_reset_hide_callback
 * DESCRIPTION
 *  resets the hide callback a vertical progress indicator object
 * PARAMETERS
 *  pi             [IN]        Is the vertical progress indicator object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vertical_progress_indicator_reset_hide_callback(vertical_progress_indicator *pi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pi->hide_callbck = NULL;
}

/*****************************************************************************
 * FUNCTION
 *  gui_show_vertical_progress_indicator
 * DESCRIPTION
 *  Displays a vertical progress indicator
 * PARAMETERS
 *  pi      [IN]        Is the vertical progress indicator object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_vertical_progress_indicator(vertical_progress_indicator *pi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, fyh;
    S32 ax1, ay1, ax2, ay2;
    S32 fx1, fy1, fx2, fy2;
    S32 fill_height, total_height;
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = pi->x;
    y1 = pi->y;
    x2 = x1 + pi->width;
    y2 = y1 + pi->height;
    ax1 = x1 + pi->border_gap;
    ay1 = y1 + pi->border_gap;
    ax2 = x2 - pi->border_gap;
    ay2 = y2 - pi->border_gap;
    total_height = ay2 - ay1 + 1;
    if (pi->range == 0)
    {
        fill_height = total_height;
    }
    else
    {
        fill_height = pi->value * total_height / pi->range;
    }
    fx1 = ax1;
    fy1 = ay1;
    fx2 = ax2;

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
#endif
    old_lcd_handle = gui_setup_target_lcd_and_layer(pi->target_lcd, pi->target_layer, pi->alpha_blend_layer);
    
    gui_push_and_set_clip(x1, y1, x2 + 2, y2 + 2);
    gui_draw_filled_area(x1, y1, x2, y2, pi->background_filler);

    if (pi->value > 0)
    {
        if (pi->flags & UI_VERTICAL_PROGRESS_INDICATOR_TYPE_MULTICOLOR)
        {
            if (pi->flags & UI_VERTICAL_PROGRESS_INDICATOR_TYPE_STEP)
            {
                S32 block_height, block_gap, sum_of_heights;
                S32 i = 0, j = 0;
                UI_filled_area *f = &pi->foreground_filler[j];

                block_height = pi->block_height;
                block_gap = pi->block_gap;
                sum_of_heights = pi->percentages[j] * total_height / 100;
                while (i < fill_height)
                {
                    if (i > sum_of_heights)
                    {
                        j++;
                        sum_of_heights += pi->percentages[j] * total_height / 100;
                        if (j >= pi->n_fillers)
                        {
                            j = pi->n_fillers - 1;
                        }
                    }
                    f = &pi->foreground_filler[j];
                    fy1 = i + ay1;
                    fy2 = fy1 + block_height - 1;
                    if (fy2 > ay2)
                    {
                        fy2 = ay2;
                    }
                    gui_draw_filled_area(fx1, fy1, fx2, fy2, f);
                    i += block_height;
                    i += block_gap;
                }
            }
            else
            {
                S32 i = 0, j = 0, w, done = 0, sum_of_heights = 0;
                UI_filled_area *f;

                i = 0;
                for (j = 0; (j < pi->n_fillers) && (!done); j++)
                {
                    f = &pi->foreground_filler[j];
                    fy1 = i + ay1;
                    w = pi->percentages[j] * total_height / 100;
                    sum_of_heights += w;
                    if (sum_of_heights > fill_height)
                    {
                        w -= (sum_of_heights - fill_height);
                        done = 1;
                    }
                    fy2 = fy1 + w - 1;
                    if (fy2 > ay2)
                    {
                        fy2 = ay2;
                    }
                    gui_draw_filled_area(fx1, fy1, fx2, fy2, f);
                    i += w;
                }
            }
        }
        else
        {
            if (pi->flags & UI_VERTICAL_PROGRESS_INDICATOR_TYPE_STEP)
            {
                S32 block_height, block_gap;
                S32 i = 0;

                block_height = pi->block_height;
                block_gap = pi->block_gap;
                while (i < fill_height)
                {
                    fy1 = i + ay1;
                    fy2 = fy1 + block_height - 1;
                    if (fy2 > ay2)
                    {
                        fy2 = ay2;
                    }
                    if (pi->flags & UI_VERTICAL_PROGRESS_INDICATOR_TYPE_REVERSE)
                    {
                        fyh = fy2 - fy1 + 1;
                        fy1 = (ay2 - fyh + 1) - i;
                        fy2 = ay2 - i;
                    }
                    gui_draw_filled_area(fx1, fy1, fx2, fy2, pi->foreground_filler);
                    i += block_height;
                    i += block_gap;
                }
            }
            else
            {
                fy2 = ay1 + fill_height;
                if (fy2 > ay2)
                {
                    fy2 = ay2;
                }
                if (pi->flags & UI_VERTICAL_PROGRESS_INDICATOR_TYPE_REVERSE)
                {
                    fyh = fy2 - fy1 + 1;
                    fy1 = ay2 - fyh + 1;
                    fy2 = ay2;
                }
                gui_draw_filled_area(fx1, fy1, fx2, fy2, pi->foreground_filler);
            }
        }
    }
    gui_pop_clip();

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
#endif    
    gui_restore_target_lcd_and_layer(pi->target_lcd, pi->target_layer, pi->alpha_blend_layer, old_lcd_handle);
}


/***************************************************************************** 
 * Vertical Slider (Used by Multimedia Application)
 *****************************************************************************/

UI_vertical_slide_theme *current_vertical_slide_theme = NULL;


/*****************************************************************************
 * FUNCTION
 *  gui_set_vertical_slide_current_theme
 * DESCRIPTION
 *  Applies the current theme for the vertical slide
 * PARAMETERS
 *  v       [IN/OUT]        Is the vertical slide object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_vertical_slide_current_theme(vertical_slide *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->focussed_bar_filler = current_vertical_slide_theme->focussed_bar_filler;
    v->normal_bar_filler = current_vertical_slide_theme->normal_bar_filler;
    v->disabled_bar_filler = current_vertical_slide_theme->disabled_bar_filler;
    gui_set_icon_button_BG_theme(&v->scroll_button, current_vertical_slide_theme->scroll_button_theme);
    gui_icon_button_set_icon(
        &v->scroll_button,
        current_vertical_slide_theme->scroll_button_icon,
        UI_DEFAULT_TRANSPARENT_COLOR);
    v->flags |= current_vertical_slide_theme->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_vertical_slide_theme
 * DESCRIPTION
 *  Applies the given theme to the vertical slide
 * PARAMETERS
 *  v       [IN/OUT]        Is the vertical slide object
 *  t       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_vertical_slide_theme(vertical_slide *v, UI_vertical_slide_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->focussed_bar_filler = t->focussed_bar_filler;
    v->normal_bar_filler = t->normal_bar_filler;
    v->disabled_bar_filler = t->disabled_bar_filler;
    gui_set_icon_button_BG_theme(&v->scroll_button, t->scroll_button_theme);
    gui_icon_button_set_icon(&v->scroll_button, t->scroll_button_icon, UI_DEFAULT_TRANSPARENT_COLOR);
    v->flags |= t->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_vertical_slide_ex
 * DESCRIPTION
 *  Creates a vertical slide
 * PARAMETERS
 *  v           [IN/OUT]    Is the vertical slide object (pre-allocated)
 *  x           [IN]        Is the left-top corner
 *  y           [IN]        Is the left-top corner
 *  width       [IN]        Is the width of the vertical slide (smaller)
 *  height      [IN]        Is the height of the vertical slide (larger)
 *  target_lcd          [IN]        Is the target lcd of the vertical slide 
 *  target_layer        [IN]        Is the target layer of the vertical slide
 *  alpha_blend_layer   [IN]        Is the alpha blend layer of the vertical slide
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_vertical_slide_ex(
        vertical_slide *v,
        S32 x,
        S32 y,
        S32 width, 
        S32 height, 
        gdi_handle target_lcd, 
        gdi_handle target_layer,
        gdi_handle alpha_blend_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->x = x;
    v->y = y;
    v->width = width;
    v->height = height;
    v->value = 0;
    v->range = 0;
    v->flags = 0;
    v->target_lcd = target_lcd;
    v->target_layer = target_layer;
    v->alpha_blend_layer = alpha_blend_layer;
    v->hide_callback = NULL;
    gui_create_icon_button(
        &v->scroll_button,
        v->x,
        v->y,
        v->width,
        v->width,
        current_vertical_slide_theme->scroll_button_icon);
    gui_set_vertical_slide_current_theme(v);
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_vertical_slide
 * DESCRIPTION
 *  Creates a vertical slide
 * PARAMETERS
 *  v           [IN/OUT]    Is the vertical slide object (pre-allocated)
 *  x           [IN]        Is the left-top corner
 *  y           [IN]        Is the left-top corner
 *  width       [IN]        Is the width of the vertical slide (smaller)
 *  height      [IN]        Is the height of the vertical slide (larger)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_vertical_slide(vertical_slide *v, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_create_vertical_slide_ex(v, x, y, width, height, GDI_NULL_HANDLE, GDI_NULL_HANDLE, GDI_NULL_HANDLE);
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_vertical_slide_range
 * DESCRIPTION
 *  Sets the range of a vertical slide
 * PARAMETERS
 *  v           [IN/OUT]    Is the vertical slide object
 *  range       [IN]        (positive value: Example: Total number of items in a list menu)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_vertical_slide_range(vertical_slide *v, S32 range)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (range < 0)
    {
        range = 0;
    }
    v->range = (U32) range;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_vertical_slide_value
 * DESCRIPTION
 *  Sets the value of a vertical slide
 * PARAMETERS
 *  v           [IN/OUT]    Is the vertical slide object
 *  value       [IN]        (positive value: Example: First displayed item in a list menu)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_vertical_slide_value(vertical_slide *v, S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (value < 0)
    {
        value = 0;
    }
    v->value = (U32) value;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_vertical_slide_scale
 * DESCRIPTION
 *  Sets the scale of a vertical slide
 * PARAMETERS
 *  v           [IN/OUT]    Is the vertical slide object
 *  scale       [IN]        (positive value: Example: Number of displayed items in a list menu)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_vertical_slide_scale(vertical_slide *v, S32 scale)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scale < 0)
    {
        scale = 0;
    }
    v->scale = (U32) scale;
}


/*****************************************************************************
 * FUNCTION
 *  gui_move_vertical_slide
 * DESCRIPTION
 *  Moves the slide to a differnt location
 * PARAMETERS
 *  v       [IN/OUT]    Is the vertical slide object
 *  x       [IN]        Is the left-top corner of the slide
 *  y       [IN]        Is the left-top corner of the slide
 * RETURNS
 *  void
 *****************************************************************************/
void gui_move_vertical_slide(vertical_slide *v, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->x = x;
    v->y = y;
    v->scroll_button.x = x;
}


/*****************************************************************************
 * FUNCTION
 *  gui_resize_vertical_slide
 * DESCRIPTION
 *  Changes the size of a slide
 * PARAMETERS
 *  v           [IN/OUT]    Is the vertical slide object
 *  width       [IN]        Is the new width
 *  height      [IN]        Is the new height
 * RETURNS
 *  void
 *****************************************************************************/
void gui_resize_vertical_slide(vertical_slide *v, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->width = width;
    v->height = height;
    v->scroll_button.x = v->x;
    v->scroll_button.width = v->width;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_slide_set_target_lcd
 * DESCRIPTION
 *  Sets the target lcd of a vertical slide
 * PARAMETERS
 *  v           [IN/OUT]    Is the vertical slide object
 *  target_lcd  [IN]        Is the target lcd of vertical slide object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vertical_slide_set_target_lcd(vertical_slide *v, gdi_handle target_lcd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->target_lcd = target_lcd;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_slide_get_target_lcd
 * DESCRIPTION
 *  gets the target lcd of a vertical slide
 * PARAMETERS
 *  v           [IN/OUT]    Is the vertical slide object
 * RETURNS
 *  the target lcd of vertical slide
 *****************************************************************************/
gdi_handle gui_vertical_slide_get_target_lcd(vertical_slide *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return v->target_lcd;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_slide_reset_target_lcd
 * DESCRIPTION
 *  resets the target lcd of a vertical slide
 * PARAMETERS
 *  v           [IN/OUT]    Is the vertical slide object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vertical_slide_reset_target_lcd(vertical_slide *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->target_lcd = GDI_NULL_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_slide_set_target_layer
 * DESCRIPTION
 *  Sets the target layer of a vertical slide
 * PARAMETERS
 *  v             [IN/OUT]    Is the vertical slide object
 *  target_layer  [IN]        Is the target layer of vertical slide object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vertical_slide_set_target_layer(vertical_slide *v, gdi_handle target_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->target_layer = target_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_slide_get_target_layer
 * DESCRIPTION
 *  gets the target layer of a vertical slide
 * PARAMETERS
 *  v           [IN/OUT]    Is the vertical slide object
 * RETURNS
 *  the target layer of vertical slide
 *****************************************************************************/
gdi_handle gui_vertical_slide_get_target_layer(vertical_slide *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return v->target_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_slide_reset_target_layer
 * DESCRIPTION
 *  resets the target layer of a vertical slide
 * PARAMETERS
 *  v             [IN/OUT]    Is the vertical slide object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vertical_slide_reset_target_layer(vertical_slide *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->target_layer = GDI_NULL_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_slide_set_alpha_blend_layer
 * DESCRIPTION
 *  Sets the alpha_blend_layer of a vertical slide
 * PARAMETERS
 *  v                  [IN/OUT]    Is the vertical slide object
 *  alpha_blend_layer  [IN]        Is the alpha_blend_layer of vertical slide object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vertical_slide_set_alpha_blend_layer(vertical_slide *v, gdi_handle alpha_blend_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->alpha_blend_layer = alpha_blend_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_slide_get_alpha_blend_layer
 * DESCRIPTION
 *  gets the alpha_blend_layer of a vertical slide
 * PARAMETERS
 *  v           [IN/OUT]    Is the vertical slide object
 * RETURNS
 *  the alpha_blend_layer of vertical slide
 *****************************************************************************/
gdi_handle gui_vertical_slide_get_alpha_blend_layer(vertical_slide *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return v->alpha_blend_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_slide_reset_alpha_blend_layer
 * DESCRIPTION
 *  resets the alpha_blend_layer of a vertical slide
 * PARAMETERS
 *  v             [IN/OUT]    Is the vertical slide object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vertical_slide_reset_alpha_blend_layer(vertical_slide *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->alpha_blend_layer = GDI_NULL_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_slide_register_hide_callback
 * DESCRIPTION
 *  registe hide callback function of a vertical slide
 * PARAMETERS
 *  v              [IN/OUT]    Is the vertical slide object
 *  hide_callback  [IN]        Is the hide callback of vertical slide object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vertical_slide_register_hide_callback(vertical_slide *v, void (*hide_callback)(S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->hide_callback = hide_callback;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vertical_slide_reset_hide_callback
 * DESCRIPTION
 *  reset hide callback function of a vertical slide
 * PARAMETERS
 *  v              [IN/OUT]    Is the vertical slide object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vertical_slide_reset_hide_callback(vertical_slide *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->hide_callback = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_vertical_slide
 * DESCRIPTION
 *  Displays the vertical slide
 * PARAMETERS
 *  v       [IN/OUT]        Is the vertical slide object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_vertical_slide(vertical_slide *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, sbutton_height, sb_y, sb_yrange, r, min_height, max_height;
    UI_filled_area *f;
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = v->x;
    y1 = v->y;
    x2 = x1 + v->width - 1;
    y2 = y1 + v->height - 1;
    if (v->flags & UI_VERTICAL_SLIDE_STATE_FOCUSSED)
    {
        f = v->focussed_bar_filler;
    }
    else if (v->flags & UI_VERTICAL_SLIDE_STATE_DISABLED)
    {
        f = v->disabled_bar_filler;
    }
    else
    {
        f = v->normal_bar_filler;
    }

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
#endif
    old_lcd_handle = gui_setup_target_lcd_and_layer(v->target_lcd, v->target_layer, v->alpha_blend_layer);
    
    gui_push_and_set_clip(x1, y1, x2 + 2, y2 + 2);
    if(v->hide_callback)
    {
        v->hide_callback(x1, y1, x2, y2);
    }
    gui_draw_filled_area(x1, y1, x2, y2, f);
    gui_pop_clip();

    /* Show the scroll button based on range and value */
    r = v->range - v->scale;
    max_height = y2 - y1 + 1;
    min_height = v->width;
    if (v->scale > 0)
    {
        if (v->range > 0)
        {
            sbutton_height = (v->scale * max_height) / v->range;
        }
        else
        {
            sbutton_height = max_height;
        }
    }
    else
    {
        sbutton_height = min_height;
    }
    if (sbutton_height < min_height)
    {
        sbutton_height = min_height;
    }
    if (sbutton_height > max_height)
    {
        sbutton_height = max_height;
    }
    sb_yrange = max_height - sbutton_height;
    if (r > 0)
    {
        sb_y = (sb_yrange * v->value) / r;
    }
    else
    {
        sb_y = 0;
    }
    if (sb_y < 0)
    {
        sb_y = 0;
    }
    if (sb_y > sb_yrange)
    {
        sb_y = sb_yrange;
    }
    if (v->flags & UI_VERTICAL_SLIDE_TYPE_REVERSE)
    {
        sb_y = v->height - sb_y - v->scroll_button.height;
    }

    v->scroll_button.height = sbutton_height;
    v->scroll_button.y = sb_y + y1;
    gui_show_icon_button(&v->scroll_button);
    
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
#endif    
    gui_restore_target_lcd_and_layer(v->target_lcd, v->target_layer, v->alpha_blend_layer, old_lcd_handle);
}


/***************************************************************************** 
 * Horizontal Slider (Used by Multimedia Application)
 *****************************************************************************/

UI_horizontal_slide_theme *current_horizontal_slide_theme = NULL;


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_slide_current_theme
 * DESCRIPTION
 *  Applies the current theme for the horizontal slide
 * PARAMETERS
 *  h       [IN/OUT]        Is the horizontal slide object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_horizontal_slide_current_theme(horizontal_slide *h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h->focussed_bar_filler = current_horizontal_slide_theme->focussed_bar_filler;
    h->normal_bar_filler = current_horizontal_slide_theme->normal_bar_filler;
    h->disabled_bar_filler = current_horizontal_slide_theme->disabled_bar_filler;
    gui_set_icon_button_BG_theme(&h->scroll_button, current_horizontal_slide_theme->scroll_button_theme);
    gui_icon_button_set_icon(
        &h->scroll_button,
        current_horizontal_slide_theme->scroll_button_icon,
        UI_DEFAULT_TRANSPARENT_COLOR);
    h->flags |= current_horizontal_slide_theme->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_slide_theme
 * DESCRIPTION
 *  Applies the given theme to the horizontal slide
 * PARAMETERS
 *  h       [IN/OUT]        Is the horizontal slide object
 *  t       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_horizontal_slide_theme(horizontal_slide *h, UI_horizontal_slide_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h->focussed_bar_filler = t->focussed_bar_filler;
    h->normal_bar_filler = t->normal_bar_filler;
    h->disabled_bar_filler = t->disabled_bar_filler;
    gui_set_icon_button_BG_theme(&h->scroll_button, t->scroll_button_theme);
    gui_icon_button_set_icon(&h->scroll_button, t->scroll_button_icon, UI_DEFAULT_TRANSPARENT_COLOR);
    h->flags |= t->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_horizontal_slide_ex
 * DESCRIPTION
 *  Creates a horizontal slide
 * PARAMETERS
 *  h           [IN/OUT]    Is the horizontal slide object (pre-allocated)
 *  x           [IN]        Is the left-top corner
 *  y           [IN]        Is the left-top corner
 *  width       [IN]        Is the width of the horizontal slide (smaller)
 *  height      [IN]        Is the height of the horizontal slide (larger)
 *  target_lcd          [IN]        Is the target_lcd of the horizontal slide
 *  target_layer        [IN]        Is the target_layer of the horizontal slide
 *  alpha_blend_layer   [IN]        Is the alpha blend layer of the horizontal slide
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_horizontal_slide_ex(
        horizontal_slide *h, 
        S32 x, 
        S32 y,
        S32 width, 
        S32 height, 
        gdi_handle target_lcd,
        gdi_handle target_layer,
        gdi_handle alpha_blend_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h->x = x;
    h->y = y;
    h->width = width;
    h->height = height;
    h->value = 0;
    h->range = 0;
    h->flags = 0;
    h->target_lcd = target_lcd;
    h->target_layer = target_layer;
    h->alpha_blend_layer = alpha_blend_layer;
    gui_create_icon_button(
        &h->scroll_button,
        h->x,
        h->y,
        h->height,
        h->height,
        current_horizontal_slide_theme->scroll_button_icon);
    gui_set_horizontal_slide_current_theme(h);
    h->hide_callback = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_horizontal_slide
 * DESCRIPTION
 *  Creates a horizontal slide
 * PARAMETERS
 *  h           [IN/OUT]    Is the horizontal slide object (pre-allocated)
 *  x           [IN]        Is the left-top corner
 *  y           [IN]        Is the left-top corner
 *  width       [IN]        Is the width of the horizontal slide (smaller)
 *  height      [IN]        Is the height of the horizontal slide (larger)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_horizontal_slide(horizontal_slide *h, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_create_horizontal_slide_ex(h, x, y, width, height, GDI_NULL_HANDLE, GDI_NULL_HANDLE, GDI_NULL_HANDLE);
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_slide_range
 * DESCRIPTION
 *  Sets the range of a horizontal slide
 * PARAMETERS
 *  h           [IN/OUT]    Is the horizontal slide object
 *  range       [IN]        (positive value: Example: Total number of items in a list menu)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_horizontal_slide_range(horizontal_slide *h, S32 range)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (range < 0)
    {
        range = 0;
    }
    h->range = (U32) range;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_slide_value
 * DESCRIPTION
 *  Sets the value of a horizontal slide
 * PARAMETERS
 *  h           [IN/OUT]    Is the horizontal slide object
 *  value       [IN]        (positive value: Example: First displayed item in a list menu)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_horizontal_slide_value(horizontal_slide *h, S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (value < 0)
    {
        value = 0;
    }
    h->value = (U32) value;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_horizontal_slide_scale
 * DESCRIPTION
 *  Sets the scale of a horizontal slide
 * PARAMETERS
 *  h           [IN/OUT]    Is the horizontal slide object
 *  scale       [IN]        (positive value: Example: Number of displayed items in a list menu)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_horizontal_slide_scale(horizontal_slide *h, S32 scale)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scale < 0)
    {
        scale = 0;
    }
    h->scale = (U32) scale;
}


/*****************************************************************************
 * FUNCTION
 *  gui_move_horizontal_slide
 * DESCRIPTION
 *  Moves the slide to a differnt location
 * PARAMETERS
 *  h       [IN/OUT]    Is the horizontal slide object
 *  x       [IN]        Is the left-top corner of the slide
 *  y       [IN]        Is the left-top corner of the slide
 * RETURNS
 *  void
 *****************************************************************************/
void gui_move_horizontal_slide(horizontal_slide *h, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h->x = x;
    h->y = y;
    h->scroll_button.x = x;
}


/*****************************************************************************
 * FUNCTION
 *  gui_resize_horizontal_slide
 * DESCRIPTION
 *  Changes the size of a slide
 * PARAMETERS
 *  h           [IN/OUT]    Is the horizontal slide object
 *  width       [IN]        Is the new width
 *  height      [IN]        Is the new height
 * RETURNS
 *  void
 *****************************************************************************/
void gui_resize_horizontal_slide(horizontal_slide *h, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h->width = width;
    h->height = height;
    h->scroll_button.x = h->x;
    h->scroll_button.width = h->width;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_slide_set_target_lcd
 * DESCRIPTION
 *  Sets the target lcd of a horizontal slide
 * PARAMETERS
 *  h           [IN/OUT]    Is the horizontal slide object
 *  target_lcd  [IN]        Is the target lcd of horizontal slide object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_slide_set_target_lcd(horizontal_slide *h, gdi_handle target_lcd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h->target_lcd = target_lcd;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_slide_get_target_lcd
 * DESCRIPTION
 *  gets gthe target lcd of a horizontal slide
 * PARAMETERS
 *  h           [IN/OUT]    Is the horizontal slide object
 * RETURNS
 *  target lcd of horizontal slide
 *****************************************************************************/
gdi_handle gui_horizontal_slide_get_target_lcd(horizontal_slide *h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return h->target_lcd;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_slide_reset_target_lcd
 * DESCRIPTION
 *  resets the target lcd of a horizontal slide
 * PARAMETERS
 *  h           [IN/OUT]    Is the horizontal slide object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_slide_reset_target_lcd(horizontal_slide *h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h->target_lcd = GDI_NULL_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_slide_set_target_layer
 * DESCRIPTION
 *  Sets the target lcd of a horizontal slide
 * PARAMETERS
 *  h             [IN/OUT]    Is the horizontal slide object
 *  target_layer  [IN]        Is the target layer of horizontal slide object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_slide_set_target_layer(horizontal_slide *h, gdi_handle target_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h->target_layer = target_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_slide_get_target_layer
 * DESCRIPTION
 *  gets gthe target layer of a horizontal slide
 * PARAMETERS
 *  h           [IN/OUT]    Is the horizontal slide object
 * RETURNS
 *  target layer of horizontal slide
 *****************************************************************************/
gdi_handle gui_horizontal_slide_get_target_layer(horizontal_slide *h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return h->target_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_slide_reset_target_layer
 * DESCRIPTION
 *  resets the target lcd of a horizontal slide
 * PARAMETERS
 *  h             [IN/OUT]    Is the horizontal slide object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_slide_reset_target_layer(horizontal_slide *h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h->target_layer = GDI_NULL_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_slide_set_alpha_blend_layer
 * DESCRIPTION
 *  Sets the alpha_blend_layer of a horizontal slide
 * PARAMETERS
 *  h                  [IN/OUT]    Is the horizontal slide object
 *  alpha_blend_layer  [IN]        Is the alpha_blend_layer of horizontal slide object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_slide_set_alpha_blend_layer(horizontal_slide *h, gdi_handle alpha_blend_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h->target_layer = alpha_blend_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_slide_get_alpha_blend_layer
 * DESCRIPTION
 *  gets the alpha_blend_layer of a horizontal slide
 * PARAMETERS
 *  h           [IN/OUT]    Is the horizontal slide object
 * RETURNS
 *  alpha_blend_layer of horizontal slide
 *****************************************************************************/
gdi_handle gui_horizontal_slide_get_alpha_blend_layer(horizontal_slide *h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return h->alpha_blend_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_slide_reset_alpha_blend_layer
 * DESCRIPTION
 *  resets the alpha_blend_layer of a horizontal slide
 * PARAMETERS
 *  h             [IN/OUT]    Is the horizontal slide object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_slide_reset_alpha_blend_layer(horizontal_slide *h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h->alpha_blend_layer = GDI_NULL_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_slide_register_hide_callback
 * DESCRIPTION
 *  Sets the target lcd of a horizontal slide
 * PARAMETERS
 *  h              [IN/OUT]    Is the horizontal slide object
 *  hide_callback  [IN]        Is the hide callback of horizontal slide object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_slide_register_hide_callback(horizontal_slide *h, void (*hide_callback)(S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h->hide_callback = hide_callback;
}


/*****************************************************************************
 * FUNCTION
 *  gui_horizontal_slide_reset_hide_callback
 * DESCRIPTION
 *  resets the target lcd of a horizontal slide
 * PARAMETERS
 *  h              [IN/OUT]    Is the horizontal slide object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_horizontal_slide_reset_hide_callback(horizontal_slide *h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h->hide_callback = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_horizontal_slide
 * DESCRIPTION
 *  Displays the horizontal slide
 * PARAMETERS
 *  h       [IN/OUT]        Is the horizontal slide object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_horizontal_slide(horizontal_slide *h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, sbutton_width, sb_x, sb_xrange, r, min_width, max_width;
    UI_filled_area *f;
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = h->x;
    y1 = h->y;
    x2 = x1 + h->width - 1;
    y2 = y1 + h->height - 1;
    if (h->flags & UI_HORIZONTAL_SLIDE_STATE_FOCUSSED)
    {
        f = h->focussed_bar_filler;
    }
    else if (h->flags & UI_HORIZONTAL_SLIDE_STATE_DISABLED)
    {
        f = h->disabled_bar_filler;
    }
    else
    {
        f = h->normal_bar_filler;
    }

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
#endif
    old_lcd_handle = gui_setup_target_lcd_and_layer(h->target_lcd, h->target_layer, h->alpha_blend_layer);
    
    gui_push_and_set_clip(x1, y1, x2 + 2, y2 + 2);
    if(h->hide_callback)
    {
        h->hide_callback(x1, y1, x2, y2);
    }
    gui_draw_filled_area(x1, y1, x2, y2, f);
    gui_pop_clip();

    /* Show the scroll button based on range and value */
    r = h->range - h->scale;
    max_width = x2 - x1 + 1;
    min_width = h->height;
    if (h->scale > 0)
    {
        if (h->range > 0)
        {
            sbutton_width = (h->scale * max_width) / h->range;
        }
        else
        {
            sbutton_width = max_width;
        }
    }
    else
    {
        sbutton_width = min_width;
    }
    if (sbutton_width < min_width)
    {
        sbutton_width = min_width;
    }
    if (sbutton_width > max_width)
    {
        sbutton_width = max_width;
    }
    sb_xrange = max_width - sbutton_width;
    if (r > 0)
    {
        sb_x = (sb_xrange * h->value) / r;
    }
    else
    {
        sb_x = 0;
    }
    if (sb_x < 0)
    {
        sb_x = 0;
    }
    if (sb_x > sb_xrange)
    {
        sb_x = sb_xrange;
    }
    if (h->flags & UI_HORIZONTAL_SLIDE_TYPE_REVERSE)
    {
        sb_x = h->width - sb_x - h->scroll_button.width;
    }

    h->scroll_button.width = sbutton_width;
    h->scroll_button.x = sb_x + x1;
    gui_show_icon_button(&h->scroll_button);

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
#endif    
    gui_restore_target_lcd_and_layer(h->target_lcd, h->target_layer, h->alpha_blend_layer, old_lcd_handle);
}


