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
 *  gui_scrollbars_oem.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Scrollbars - UI component
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "gui_scrollbars_post_oem.h"
#include "wgui_categories_defs.h"
#include "gdi_include.h"
#include "mmi_frm_gprot.h"
#include "wgui_draw_manager.h"
#include "wgui_categories_util.h"

#include "gui_scrollbars.h"
#include "gdi_datatype.h"
#include "gui.h"
#include "gdi_const.h"
#include "MMIDataType.h"
#include "CustDataRes.h"
#include "mmi_rp_app_uiframework_def.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "gui_buttons.h"
#include "gui_data_types.h"
#include "CustThemesRes.h"

static horizontal_scrollbar *current_h = NULL;
static vertical_scrollbar *current_v = NULL;


/*****************************************************************************
* FUNCTION
*  gui_set_current_ptr
* DESCRIPTION
*
* PARAMETERS
*              [IN]
*         [IN]
* RETURNS
*
*****************************************************************************/
void gui_set_current_ptr(horizontal_scrollbar *h, vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_v = v;
    current_h = h;
}


/*****************************************************************************
* FUNCTION
*  gui_vertical_scrollbar_setup_target_lcd_and_layer
* DESCRIPTION
*  setup vertical scrollbar target lcd, target layer and alpha blend layer
* PARAMETERS
*  v            [IN]    the struct of vertical scrollbar
* RETURNS
*  the old lcd handle
*****************************************************************************/
gdi_handle gui_vertical_scrollbar_setup_target_lcd_and_layer(vertical_scrollbar *v)
{
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

    return gui_setup_target_lcd_and_layer(v->target_lcd, v->target_layer, v->alpha_blend_layer);

}


/*****************************************************************************
* FUNCTION
*  gui_vertical_scrollbar_setup_target_lcd_and_layer
* DESCRIPTION
*  setup vertical scrollbar target lcd, target layer and alpha blend layer
* PARAMETERS
*  v                [IN]    the struct of vertical scrollbar
*  old_lcd_handle   [IN]    the old lcd handle
* RETURNS
*  void
*****************************************************************************/
void gui_vertical_scrollbar_restore_target_lcd_and_layer(vertical_scrollbar *v, gdi_handle old_lcd_handle)
{
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    gui_restore_target_lcd_and_layer(v->target_lcd, v->target_layer, v->alpha_blend_layer, old_lcd_handle);

}


/*****************************************************************************
* FUNCTION
*  gui_horizontal_scrollbar_setup_target_lcd_and_layer
* DESCRIPTION
*  setup horizontal scrollbar target lcd, target layer and alpha blend layer
* PARAMETERS
*  h            [IN]    the struct of horizontal scrollbar
* RETURNS
*  the old lcd handle
*****************************************************************************/
gdi_handle gui_horizontal_scrollbar_setup_target_lcd_and_layer(horizontal_scrollbar *h)
{
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    return gui_setup_target_lcd_and_layer(h->target_lcd, h->target_layer, h->alpha_blend_layer);
}


/*****************************************************************************
* FUNCTION
*  gui_vertical_scrollbar_setup_target_lcd_and_layer
* DESCRIPTION
*  restore horizontal scrollbar target lcd, target layer and alpha blend layer
* PARAMETERS
*  h                [IN]    the struct of vertical scrollbar
*  old_lcd_handle   [IN]    the old lcd handle
* RETURNS
*  void
*****************************************************************************/
void gui_horizontal_scrollbar_restore_target_lcd_and_layer(horizontal_scrollbar *h, gdi_handle old_lcd_handle)
{
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    
    gui_restore_target_lcd_and_layer(h->target_lcd, h->target_layer, h->alpha_blend_layer, old_lcd_handle);
}


#if defined(UI_SCROLLBAR_STYLE_9)

/*****************************************************************************
* FUNCTION
*  gui_scrollbar_get_button_min_size
* DESCRIPTION
*
* PARAMETERS
*  type            [IN]
*  bar_width       [IN]
* RETURNS
*
*****************************************************************************/
S32 gui_scrollbar_get_button_min_size_style_9(gui_scrollbar_buttton_enum type, S32 bar_width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (type)
    {
    case GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL:
        /* FALLTHROUGH no break */
    case GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL:
        return GUI_SCROLLBAR_MIN_HEIGHT_SCROLL_BUTTON_STYLE9;
        
    case GUI_SCROLLBAR_BUTTON_UP:
        /* FALLTHROUGH no break */
    case GUI_SCROLLBAR_BUTTON_DOWN:
        /* FALLTHROUGH no break */
    case GUI_SCROLLBAR_BUTTON_LEFT:
        /* FALLTHROUGH no break */
    case GUI_SCROLLBAR_BUTTON_RIGHT:
        return 0;           
     
    default:
        MMI_ASSERT(0);
    }

    return 0;
}


/*****************************************************************************
* FUNCTION
*  gui_scrollbar_set_clip_intersect
* DESCRIPTION
*  
* PARAMETERS
*  type        [IN]     type of button
*  b           [IN]     pointer of button
* RETURNS
*  void
*****************************************************************************/
static MMI_BOOL gui_scrollbar_set_clip_intersect(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 current_x1, current_y1, current_x2, current_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_clip(&current_x1, &current_y1, &current_x2, &current_y2);

    if ((x1 > current_x2) || (y1 > current_y2) ||(x2 < current_x1) || (y2 < current_y1))
    {
        return MMI_FALSE;
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

    gdi_layer_set_clip(x1, y1, x2, y2);

    return MMI_TRUE;

}


/*****************************************************************************
* FUNCTION
*  gui_scrollbar_draw_button
* DESCRIPTION
*
* PARAMETERS
*  type        [IN]     type of button
*  b           [IN]     pointer of button
* RETURNS
*  void
*****************************************************************************/
static void gui_scrollbar_draw_button_style_9(gui_scrollbar_buttton_enum type, icon_button *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    S32 x, y, width, height;
    MMI_BOOL result = MMI_FALSE;;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    x = b->x;
    y = b->y;
    width = b->width;
    height = b->height;

    if (width == 0 || height == 0)
    {
        return;
    }

    gui_push_clip();

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_set_clip(x, y, x + width - 1, y + height - 1);
    }
    else
    {
        result = gui_scrollbar_set_clip_intersect(x, y, x + width - 1, y + height - 1);
        if (!result)
        {
            gui_pop_clip();
            return;
        }
    }

    switch (type)
    {
    case GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL:
        {
                gui_push_clip();
                if (gui_scrollbar_redraw_clip_enable)
                {
                    gui_set_clip(x, y, x + width - 1, y + height - 1);
                }
                else
                {
                    result = gui_scrollbar_set_clip_intersect(x, y, x + width - 1, y + height - 1);
                }

                if (gui_scrollbar_redraw_clip_enable || (!gui_scrollbar_redraw_clip_enable && result))
                {                    
                    gui_fill_rectangle(x, y, x + width - 1, y + height - 1,  current_vertical_scrollbar_theme->normal_bar_filler->c);                   
                }
                gui_pop_clip();       
            break;
        }
    case GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL:
        {
            gui_push_clip();
            if (gui_scrollbar_redraw_clip_enable)
            {
                gui_set_clip(x, y, x + width - 1, y + height - 1);
            }
            else
            {
                result = gui_scrollbar_set_clip_intersect(x, y, x + width - 1, y + height - 1);
            }
            
            if (gui_scrollbar_redraw_clip_enable || (!gui_scrollbar_redraw_clip_enable && result))
            {               
                gui_fill_rectangle(x, y, x + width - 1, y + height - 1,  current_horizontal_scrollbar_theme->normal_bar_filler->c);                
            }            
            gui_pop_clip();
            break;
        }

        case GUI_SCROLLBAR_BUTTON_UP:
        case GUI_SCROLLBAR_BUTTON_LEFT:
        case GUI_SCROLLBAR_BUTTON_DOWN:
        case GUI_SCROLLBAR_BUTTON_RIGHT:
            break;

        default:
            MMI_DBG_ASSERT(0);
    }

    gui_pop_clip();

}
#endif /*defined(UI_SCROLLBAR_STYLE_9)*/


#if defined(UI_SCROLLBAR_STYLE_7) || defined(UI_SCROLLBAR_WIDER_STYLE_7)
/* local variables */
static S32 g_mmi_gui_scrollbar_style7_width = 0;   /* scroll bar width */
static S32 g_mmi_gui_scrollbar_bar_style7_size1;   /* top image width */
static S32 g_mmi_gui_scrollbar_bar_style7_size2;   /* middle image height */
static S32 g_mmi_gui_scrollbar_bar_style7_size3;   /* bottom image width */

static S32 g_mmi_gui_scrollbar_button_style7_size;


/*****************************************************************************
* FUNCTION
*  gui_scrollbar_precache_image_size
* DESCRIPTION
*  precache the image size
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void gui_scrollbar_precache_image_size_style_7(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 iw, ih;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_measure_image((PU8) GetImage(IMG_SCROLLBAR_V_BAR_TOP), &iw, &ih);
    g_mmi_gui_scrollbar_bar_style7_size1 = ih;
    g_mmi_gui_scrollbar_style7_width = iw;

    gui_measure_image((PU8) GetImage(IMG_SCROLLBAR_V_BAR_MIDDLE), &iw, &ih);
    g_mmi_gui_scrollbar_bar_style7_size2 = ih;

    gui_measure_image((PU8) GetImage(IMG_SCROLLBAR_V_BAR_BOTTOM), &iw, &ih);
    g_mmi_gui_scrollbar_bar_style7_size3 = ih;

}


/*****************************************************************************
* FUNCTION
*  gui_scrollbar_get_button_min_size
* DESCRIPTION
*
* PARAMETERS
*  type            [IN]
*  bar_width       [IN]
* RETURNS
*
*****************************************************************************/
S32 gui_scrollbar_get_button_min_size_style_7(gui_scrollbar_buttton_enum type, S32 bar_width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_scrollbar_precache_image_size_style_7();

    switch (type)
    {
    case GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL:
        /* FALLTHROUGH no break */
    case GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL:
        ret = GUI_SCROLLBAR_MIN_HEIGHT_SCROLL_BUTTON_STYLE7;
        break;

    case GUI_SCROLLBAR_BUTTON_UP:
        /* FALLTHROUGH no break */
    case GUI_SCROLLBAR_BUTTON_DOWN:
        /* FALLTHROUGH no break */
    case GUI_SCROLLBAR_BUTTON_LEFT:
        /* FALLTHROUGH no break */
    case GUI_SCROLLBAR_BUTTON_RIGHT:
        ret = g_mmi_gui_scrollbar_button_style7_size + 2 /* 1 + 1 pixel spacing */ ;
        break;

    default:
        MMI_ASSERT(0);
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  gui_scrollbar_set_clip_intersect
* DESCRIPTION
*  
* PARAMETERS
*  type        [IN]     type of button
*  b           [IN]     pointer of button
* RETURNS
*  void
*****************************************************************************/
static MMI_BOOL gui_scrollbar_set_clip_intersect(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 current_x1, current_y1, current_x2, current_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_clip(&current_x1, &current_y1, &current_x2, &current_y2);

    if ((x1 > current_x2) || (y1 > current_y2) ||(x2 < current_x1) || (y2 < current_y1))
    {
        return MMI_FALSE;
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

    gdi_layer_set_clip(x1, y1, x2, y2);

    return MMI_TRUE;

}


/*****************************************************************************
* FUNCTION
*  gui_scrollbar_draw_button
* DESCRIPTION
*
* PARAMETERS
*  type        [IN]     type of button
*  b           [IN]     pointer of button
* RETURNS
*  void
*****************************************************************************/
static void gui_scrollbar_draw_button_style_7(gui_scrollbar_buttton_enum type, icon_button *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c;
    S32 x, y, width, height;
    MMI_BOOL result = MMI_FALSE;;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_scrollbar_precache_image_size_style_7();

    c = b->normal_up_filler->c;
    x = b->x;
    y = b->y;
    width = b->width;
    height = b->height;

    if (width == 0 || height == 0)
    {
        return;
    }

    gui_push_clip();

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_set_clip(x, y, x + width - 1, y + height - 1);
    }
    else
    {
        result = gui_scrollbar_set_clip_intersect(x, y, x + width - 1, y + height - 1);
        if (!result)
        {
            gui_pop_clip();
            return;
        }
    }

    switch (type)
    {
    case GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL:
        {
        #ifdef __MMI_FTE_SUPPORT__
            gdi_image_draw_resized(x, y, width, height, current_vertical_scrollbar_theme->scroll_indicator_icon);
        #else /* __MMI_FTE_SUPPORT__ */
            S32 x2, y2;


            x2 = x + width - 1;
            y2 = y + height - 1;
            if (height <= g_mmi_gui_scrollbar_bar_style7_size1 + g_mmi_gui_scrollbar_bar_style7_size3)
            {
                gdi_image_draw_resized(x, y, g_mmi_gui_scrollbar_style7_width, height / 2, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_TOP));
                gdi_image_draw_resized(x, y + height / 2, g_mmi_gui_scrollbar_style7_width, height / 2, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_BOTTOM));
            }
            else
            {
                S32 y1, y2, remain;

                y1 = y + g_mmi_gui_scrollbar_bar_style7_size1;
                y2 = y + height - g_mmi_gui_scrollbar_bar_style7_size3 - 1;

                gui_push_clip();
                if (gui_scrollbar_redraw_clip_enable)
                {
                    gui_set_clip(x, y1, x + width - 1, y2);
                }
                else
                {
                    result = gui_scrollbar_set_clip_intersect(x, y1, x + width - 1, y2);
                }

                if (gui_scrollbar_redraw_clip_enable || (!gui_scrollbar_redraw_clip_enable && result))
                {
                    remain = y2 - y1 + 1;

                    while (remain > 0)
                    {
                        gdi_image_draw(x, y1, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_MIDDLE));
                        y1 += g_mmi_gui_scrollbar_bar_style7_size2;
                        remain -= g_mmi_gui_scrollbar_bar_style7_size2;
                    }

                }

                gui_pop_clip();
                gui_push_clip();

                if (gui_scrollbar_redraw_clip_enable)
                {
                    gui_set_clip(x, y, x + width - 1, y + height - 1);
                }
                else
                {
                    result = gui_scrollbar_set_clip_intersect(x, y, x + width - 1, y + height - 1);
                }

                if (gui_scrollbar_redraw_clip_enable || (!gui_scrollbar_redraw_clip_enable && result))
                {
                    gdi_image_draw(x, y, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_TOP));
                    gdi_image_draw(x, y2 + 1, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_BOTTOM));
                }

                gui_pop_clip();
            }
         #endif /* __MMI_FTE_SUPPORT__ */
            break;
        }
    case GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL:
        {
        #ifdef __MMI_FTE_SUPPORT__
            gdi_image_draw_resized(x, y, width, height, current_horizontal_scrollbar_theme->scroll_indicator_icon);
        #else /* __MMI_FTE_SUPPORT__ */
            S32 x2, y2;


            x2 = x + width - 1;
            y2 = y + height - 1;
            if (width <= g_mmi_gui_scrollbar_bar_style7_size1 + g_mmi_gui_scrollbar_bar_style7_size3)
            {
                gdi_image_draw_resized(x, y, width / 2, g_mmi_gui_scrollbar_style7_width, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_LEFT));
                gdi_image_draw_resized(x + width / 2, y, width / 2, g_mmi_gui_scrollbar_style7_width, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_RIGHT));
            }
            else
            {
                S32 x1, x2, remain;

                x1 = x + g_mmi_gui_scrollbar_bar_style7_size1;
                x2 = x + width - g_mmi_gui_scrollbar_bar_style7_size3 - 1;

                gui_push_clip();
                if (gui_scrollbar_redraw_clip_enable)
                {
                    gui_set_clip(x1, y, x2, y + height - 1);
                }
                else
                {
                    result = gui_scrollbar_set_clip_intersect(x1, y, x2, y + height - 1);
                }

                if (gui_scrollbar_redraw_clip_enable || (!gui_scrollbar_redraw_clip_enable && result))
                {
                    remain = x2 - x1 + 1;

                    while (remain > 0)
                    {
                        gdi_image_draw(x1, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_MIDDLE));
                        x1 += g_mmi_gui_scrollbar_bar_style7_size2;
                        remain -= g_mmi_gui_scrollbar_bar_style7_size2;
                    }
                }

                gui_pop_clip();
                gui_push_clip();

                if (gui_scrollbar_redraw_clip_enable)
                {
                    gui_set_clip(x, y, x + width - 1, y + height - 1);
                }
                else
                {
                    result = gui_scrollbar_set_clip_intersect(x, y, x + width - 1, y + height - 1);
                }

                if (gui_scrollbar_redraw_clip_enable || (!gui_scrollbar_redraw_clip_enable && result))
                {
                    gdi_image_draw(x, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_LEFT));
                    gdi_image_draw(x2 + 1, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_RIGHT));
                }

                gui_pop_clip();
            }
        #endif /* __MMI_FTE_SUPPORT__ */
            break;
        }


        case GUI_SCROLLBAR_BUTTON_UP:
        case GUI_SCROLLBAR_BUTTON_LEFT:
        case GUI_SCROLLBAR_BUTTON_DOWN:
        case GUI_SCROLLBAR_BUTTON_RIGHT:
            break;

        default:
            MMI_DBG_ASSERT(0);
    }

    gui_pop_clip();

}
#endif

#if defined(UI_SCROLLBAR_STYLE_8)
/* Macro */
#define GUI_SCROLLBAR_DOT_NUM   5

/* local variables */
static S32 g_mmi_gui_scrollbar_width_style_8 = 0;   /* scroll bar width */
static S32 g_mmi_gui_scrollbar_bar_size1_style_8;   /* top image width */
static S32 g_mmi_gui_scrollbar_bar_size2_style_8;   /* middle image height */
static S32 g_mmi_gui_scrollbar_bar_size3_style_8;   /* bottom image width */
static S32 g_mmi_gui_scrollbar_bar_size4_style_8;   /* middle bg image width */
static S32 g_mmi_gui_scrollbar_bar_size5_style_8;   /* top bg image width */
static S32 g_mmi_gui_scrollbar_bar_size6_style_8;   /* bottom bg image width */
static S32 g_mmi_gui_scrollbar_bar_size7_style_8;   /* indi image width */
static S32 g_mmi_gui_scrollbar_bar_size8_style_8;   /* indi image height */
static S32 g_mmi_gui_scrollbar_bar_size9_style_8;   /* middle image width */

/* Global variable */
gdi_handle g_mmi_gui_scrollbar_src_layer = GDI_NULL_HANDLE;


/*****************************************************************************
* FUNCTION
*  gui_scrollbar_precache_image_size
* DESCRIPTION
*  precache the image size
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void gui_scrollbar_precache_image_size_style_8(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 iw, ih;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_measure_image((PU8) GetImage(IMG_SCROLLBAR_V_BAR_TOP), &iw, &ih);
    g_mmi_gui_scrollbar_bar_size1_style_8 = ih;
    g_mmi_gui_scrollbar_width_style_8 = iw;

    gui_measure_image((PU8) GetImage(IMG_SCROLLBAR_V_BAR_MIDDLE), &iw, &ih);
    g_mmi_gui_scrollbar_bar_size2_style_8 = ih;
    g_mmi_gui_scrollbar_bar_size9_style_8 = iw;

    gui_measure_image((PU8) GetImage(IMG_SCROLLBAR_V_BAR_BOTTOM), &iw, &ih);
    g_mmi_gui_scrollbar_bar_size3_style_8 = ih;

    gui_measure_image((PU8) GetImage(IMG_SCROLLBAR_V_BAR_BGD), &iw, &ih);
    g_mmi_gui_scrollbar_bar_size4_style_8 = ih;

    gui_measure_image((PU8) GetImage(IMG_SCROLLBAR_V_BAR_BGD_TOP), &iw, &ih);
    g_mmi_gui_scrollbar_bar_size5_style_8 = ih;

    gui_measure_image((PU8) GetImage(IMG_SCROLLBAR_V_BAR_BGD_BOTTOM), &iw, &ih);
    g_mmi_gui_scrollbar_bar_size6_style_8 = ih;

    gui_measure_image((PU8) GetImage(IMG_SCROLLBAR_V_BAR_INDICATOR), &iw, &ih);
    g_mmi_gui_scrollbar_bar_size7_style_8 = ih;
    g_mmi_gui_scrollbar_bar_size8_style_8 = iw;

}


/*****************************************************************************
* FUNCTION
*  gui_scrollbar_get_button_min_size
* DESCRIPTION
*  get button minimum size
* PARAMETERS
*  type            [IN] type of button
*  bar_width       [IN] width of scrollbar
* RETURNS
*  button minimum size
*****************************************************************************/
S32 gui_scrollbar_get_button_min_size_style_8(gui_scrollbar_buttton_enum type, S32 bar_width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_scrollbar_precache_image_size_style_8();

    MMI_DBG_ASSERT(g_mmi_gui_scrollbar_width_style_8 == bar_width);

    switch (type)
    {
    case GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL:
        /* FALLTHROUGH no break */
    case GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL:
        ret = GUI_SCROLLBAR_MIN_HEIGHT_SCROLL_BUTTON_STYLE8;
        break;

    case GUI_SCROLLBAR_BUTTON_UP:
        /* FALLTHROUGH no break */
    case GUI_SCROLLBAR_BUTTON_DOWN:
        /* FALLTHROUGH no break */
    case GUI_SCROLLBAR_BUTTON_LEFT:
        /* FALLTHROUGH no break */
    case GUI_SCROLLBAR_BUTTON_RIGHT:
        ret = 0 ;
        break;

    default:
        MMI_ASSERT(0);
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  gui_scrollbar_draw_region
* DESCRIPTION
*  draw the region of scrollbar
* PARAMETERS
*  type        [IN]        type of region
*  x           [IN]        x of region
*  y           [IN]        y of region
*  width       [IN]        width of region
*  height      [IN]        height of region
* RETURNS
*  void
*****************************************************************************/
static void gui_scrollbar_draw_region_style_8(gui_scrollbar_region_enum type, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 remain;
    S32 x1, y1, x2, y2;
    gdi_handle old_src_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_and_set_clip(x, y, x + width - 1, y + height - 1);
    }

    x1 = x;
    x2 = x + width - 1;
    y1 = y;
    y2 = y + height - 1;

    if (type == GUI_SCROLLBAR_REGION_VERTICAL)
    {

        if (height <= g_mmi_gui_scrollbar_bar_size5_style_8 + g_mmi_gui_scrollbar_bar_size6_style_8)
        {
            gdi_image_draw(x, y, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_BGD_TOP));
            gdi_image_draw(x, y2 - g_mmi_gui_scrollbar_bar_size6_style_8 + 1, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_BGD_BOTTOM));
        }
        else
        {
            if (!gui_scrollbar_redraw_clip_enable)
            {
                gdi_image_draw(x, y, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_BGD_TOP));
                gdi_image_draw(x, y2 - g_mmi_gui_scrollbar_bar_size6_style_8 + 1, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_BGD_BOTTOM));
            }

            y1 = y + g_mmi_gui_scrollbar_bar_size5_style_8;
            y2 -= g_mmi_gui_scrollbar_bar_size6_style_8;

            if (gui_scrollbar_redraw_clip_enable)
            {
                gui_set_clip(x, y1, x + width - 1, y2);
            }

            remain = height - g_mmi_gui_scrollbar_bar_size5_style_8 - g_mmi_gui_scrollbar_bar_size6_style_8;
            while (remain > 0)
            {
                gdi_image_draw(x, y1, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_BGD));
                y1 += g_mmi_gui_scrollbar_bar_size4_style_8;
                remain -= g_mmi_gui_scrollbar_bar_size4_style_8;
            }

            if (gui_scrollbar_redraw_clip_enable)
            {
                gui_set_clip(x, y, x + width - 1, y + height - 1);
                gdi_image_draw(x, y, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_BGD_TOP));
                gdi_image_draw(x, y2 + 1, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_BGD_BOTTOM));
            }

        }

    }
    else
    {

        if (width <= g_mmi_gui_scrollbar_bar_size5_style_8 + g_mmi_gui_scrollbar_bar_size6_style_8)
        {
            gdi_image_draw(x, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_BGD_LEFT));
            gdi_image_draw(x2 - g_mmi_gui_scrollbar_bar_size6_style_8 + 1, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_BGD_RIGHT));
        }
        else
        {
            if (!gui_scrollbar_redraw_clip_enable)
            {
                gdi_image_draw(x, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_BGD_LEFT));
                gdi_image_draw(x2 - g_mmi_gui_scrollbar_bar_size6_style_8 + 1, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_BGD_RIGHT));
            }

            x1 = x + g_mmi_gui_scrollbar_bar_size5_style_8;
            x2 -= g_mmi_gui_scrollbar_bar_size6_style_8;

            if (gui_scrollbar_redraw_clip_enable)
            {
                gui_set_clip(x1, y, x2, y + height - 1);
            }

            remain = width - g_mmi_gui_scrollbar_bar_size5_style_8 - g_mmi_gui_scrollbar_bar_size6_style_8;
            while (remain > 0)
            {

                gdi_image_draw(x1, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_BGD));
                x1 += g_mmi_gui_scrollbar_bar_size4_style_8;
                remain -= g_mmi_gui_scrollbar_bar_size4_style_8;
            }

            if (gui_scrollbar_redraw_clip_enable)
            {
                gui_set_clip(x, y, x + width - 1, y + height - 1);
                gdi_image_draw(x, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_BGD_LEFT));
                gdi_image_draw(x2 + 1, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_BGD_RIGHT));
            }

        }

    }

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }
}

/*****************************************************************************
* FUNCTION
*  gui_scrollbar_draw_button
* DESCRIPTION
*
* PARAMETERS
*  type        [IN]     type of button
*  b           [IN]     pointer of button
* RETURNS
*  void
*****************************************************************************/
static void gui_scrollbar_draw_button_style_8(gui_scrollbar_buttton_enum type, icon_button *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c;
    S32 x, y, width, height;
    gdi_handle act_layer, old_src_layer;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_scrollbar_precache_image_size_style_8();

    c = b->normal_up_filler->c;
    x = b->x;
    y = b->y;
    width = b->width;
    height = b->height;

    if (width == 0 || height == 0)
    {
        return;
    }

    gdi_layer_get_active(&act_layer);
    gdi_get_alpha_blending_source_layer(&old_src_layer);
    gdi_set_alpha_blending_source_layer(act_layer);

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_and_set_clip(x, y, x + width - 1, y + height - 1);
    }

    switch (type)
    {
    case GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL:
        {
            S32 x2, y2;


            x2 = x + width - 1;
            y2 = y + height - 1;
            if (height <= g_mmi_gui_scrollbar_bar_size1_style_8 + g_mmi_gui_scrollbar_bar_size3_style_8)
            {
                if (gui_scrollbar_redraw_clip_enable)
                {
                    gui_set_clip(x, y, x + width - 1, y + (height >> 1) - 1);
                }
                gdi_image_draw(x, y, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_TOP));
                if (gui_scrollbar_redraw_clip_enable)
                {
                    gui_set_clip(x, y + (height >> 1), x + width - 1, y + height - 1);
                }
                gdi_image_draw(x, y + height - g_mmi_gui_scrollbar_bar_size3_style_8, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_BOTTOM));
            }
            else
            {
                S32 y1, y2, remain;
                S32 ix1, iy1, inum, i;

                y1 = y + g_mmi_gui_scrollbar_bar_size1_style_8;
                y2 = y + height - g_mmi_gui_scrollbar_bar_size3_style_8 - 1;

                if (gui_scrollbar_redraw_clip_enable)
                {
                    gui_set_clip(x, y1, x + width - 1, y2);
                }
                remain = y2 - y1 + 1;
                inum = (remain) / g_mmi_gui_scrollbar_bar_size7_style_8;
                if (inum > GUI_SCROLLBAR_DOT_NUM)
                {
                    inum = GUI_SCROLLBAR_DOT_NUM;
                }
                ix1 = x + g_mmi_gui_scrollbar_bar_size9_style_8 - g_mmi_gui_scrollbar_bar_size8_style_8;
                iy1 = y1 + ( y2 - y1 + 1 - g_mmi_gui_scrollbar_bar_size7_style_8 * inum) / 2;

                while (remain > 0)
                {
                    gdi_image_draw(x, y1, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_MIDDLE));
                    y1 += g_mmi_gui_scrollbar_bar_size2_style_8;
                    remain -= g_mmi_gui_scrollbar_bar_size2_style_8;
                }
                if (gui_scrollbar_redraw_clip_enable)
                {
                    gui_push_and_set_clip(x, y, x + width - 1, y + height - 1);
                }
                gdi_image_draw(x, y, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_TOP));
                gdi_image_draw(x, y2 + 1, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_BOTTOM));

                for (i = 0; i < inum; i ++)
                {
                    gdi_image_draw(ix1, iy1, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_INDICATOR));
                    iy1 += g_mmi_gui_scrollbar_bar_size7_style_8;
                }
                if (gui_scrollbar_redraw_clip_enable)
                {
                    gui_pop_clip();
                }
            }

            break;
        }
    case GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL:
        {
            S32 x2, y2;


            x2 = x + width - 1;
            y2 = y + height - 1;
            if (width <= g_mmi_gui_scrollbar_bar_size1_style_8 + g_mmi_gui_scrollbar_bar_size3_style_8)
            {
                if (gui_scrollbar_redraw_clip_enable)
                {
                    gui_set_clip(x, y, x + (width >> 1) - 1, y + height - 1);
                }
                gdi_image_draw(x, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_LEFT));
                if (gui_scrollbar_redraw_clip_enable)
                {
                    gui_set_clip(x + (width >> 1), y, x + width - 1, y + height - 1);
                }
                gdi_image_draw(x + width - g_mmi_gui_scrollbar_bar_size3_style_8, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_RIGHT));
            }
            else
            {
                S32 x1, x2, remain;
                S32 ix1, iy1, i, inum;

                x1 = x + g_mmi_gui_scrollbar_bar_size1_style_8;
                x2 = x + width - g_mmi_gui_scrollbar_bar_size3_style_8 - 1;

                if (gui_scrollbar_redraw_clip_enable)
                {
                    gui_set_clip(x1, y, x2, y + height - 1);
                }
                remain = x2 - x1 + 1;

                inum = (remain) / g_mmi_gui_scrollbar_bar_size7_style_8;
                if (inum > GUI_SCROLLBAR_DOT_NUM)
                {
                    inum = GUI_SCROLLBAR_DOT_NUM;
                }

                ix1 = x1 + (x2 - x1 + 1 - g_mmi_gui_scrollbar_bar_size7_style_8 * inum) / 2;
                iy1 = y + g_mmi_gui_scrollbar_bar_size9_style_8 - g_mmi_gui_scrollbar_bar_size8_style_8;

                while (remain > 0)
                {
                    gdi_image_draw(x1, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_MIDDLE));
                    x1 += g_mmi_gui_scrollbar_bar_size2_style_8;
                    remain -= g_mmi_gui_scrollbar_bar_size2_style_8;
                }
                if (gui_scrollbar_redraw_clip_enable)
                {
                    gui_push_and_set_clip(x, y, x + width - 1, y + height - 1);
                }
                gdi_image_draw(x, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_LEFT));
                gdi_image_draw(x2 + 1, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_RIGHT));

                for (i = 0; i < inum; i ++)
                {
                    gdi_image_draw(ix1, iy1, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_INDICATOR));
                    ix1 += g_mmi_gui_scrollbar_bar_size7_style_8;
                }
                if (gui_scrollbar_redraw_clip_enable)
                {
                    gui_pop_clip();
                }
            }

            break;
        }


        case GUI_SCROLLBAR_BUTTON_UP:
        case GUI_SCROLLBAR_BUTTON_LEFT:
        case GUI_SCROLLBAR_BUTTON_DOWN:
        case GUI_SCROLLBAR_BUTTON_RIGHT:
            break;

        default:
            MMI_DBG_ASSERT(0);
    }

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }

    gdi_set_alpha_blending_source_layer(old_src_layer);

}

#endif

#if defined(UI_SCROLLBAR_STYLE_6) || defined(UI_SCROLLBAR_WIDER_STYLE_6)
/* Use image to draw the scrollbar. */

/* color of the moveable part (scroll button) */
static S32 g_mmi_gui_scrollbar_cache_hue_style_6 = -1;
static S32 g_mmi_gui_scrollbar_cache_num_gcolor_style_6 = 0;

static color g_mmi_gui_scrollbar_gradient_style_6[GUI_SCROLLBAR_NUM_GRADIENT_COLOR_STYLE6];

#ifndef __MMI_WALLPAPER_ON_BOTTOM__
static color g_mmi_gui_scrollbar_bk_color_style_6;
static color g_mmi_gui_scrollbar_border_color_style_6;
#endif


/*
* RGB <-> HLS color space conversion with cache to avoid floating point arithmetics
*/


/*****************************************************************************
* FUNCTION
*  gui_scrollbar_RGB_to_HLS
* DESCRIPTION
*
* PARAMETERS
*  rgb     [IN]
*  hls     [OUT]
* RETURNS
*  void
*****************************************************************************/
static void gui_scrollbar_RGB_to_HLS_style_6(color rgb, UI_HLS_color *hls)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static color cached_rgb = {0, 0, 0, 0};
    static UI_HLS_color cached_hls = {0, 0, 0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (memcmp(&rgb, &cached_rgb, sizeof(color)) != 0)
    {
        cached_rgb = rgb;
        gui_RGB_to_HLS(rgb, &cached_hls);
    }
    *hls = cached_hls;
}


/*****************************************************************************
* FUNCTION
*  gui_scrollbar_precache_color1
* DESCRIPTION
*  Pre-cache color because the HLS colorspace conversion is slow
* PARAMETERS
*  theme_color     [IN]        Is the domination color the scrollbar
*  width           [IN]        Scrollbar width
* RETURNS
*  void
*****************************************************************************/
static void gui_scrollbar_precache_color1_style_6(
                color theme_color, S32 width,
                S32 saturation_min, S32 saturation_max,
                S32 lightness_min, S32 lightness_max,
                S32 gradient_color_max)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_HLS_color hls;
    S32 i;
    S32 num_gradient_color = width;
    S32 s_min, s_max, l_min, l_max;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (saturation_max > 255)
    {
        s_max = 255;
    }
    else if (saturation_min < 0)
    {
        s_max = 0;
    }
    else
    {
        s_max = saturation_max;
    }

    if (saturation_min > 255)
    {
        s_min = 255;
    }
    else if (saturation_min < 0)
    {
        s_min = 0;
    }
    else
    {
        s_min = saturation_min;
    }

    if (lightness_min > 255)
    {
        l_min = 255;
    }
    else if (lightness_min < 0)
    {
        l_min = 0;
    }
    else
    {
        l_min = lightness_min;
    }

    if (lightness_max > 255)
    {
        l_max = 255;
    }
    else if (lightness_max < 0)
    {
        l_max = 0;
    }
    else
    {
        l_max = lightness_max;
    }

    if (num_gradient_color > gradient_color_max)
    {
        num_gradient_color = gradient_color_max;
    }

    if (num_gradient_color > GUI_SCROLLBAR_NUM_GRADIENT_COLOR_STYLE6)
    {
        num_gradient_color = GUI_SCROLLBAR_NUM_GRADIENT_COLOR_STYLE6;
    }
    if (num_gradient_color <= 1)
    {
        num_gradient_color = 2;
    }

    gui_scrollbar_RGB_to_HLS_style_6(theme_color, &hls);

    /* Recompute colors only if color hue is changed */
    if ((S32) hls.h != g_mmi_gui_scrollbar_cache_hue_style_6 || num_gradient_color != g_mmi_gui_scrollbar_cache_num_gcolor_style_6)
    {
        g_mmi_gui_scrollbar_cache_num_gcolor_style_6 = num_gradient_color;
        g_mmi_gui_scrollbar_cache_hue_style_6 = hls.h;

        for (i = 0; i < num_gradient_color; i++)
        {
            S32 l, s;

            s = i * (s_max - s_min) / (num_gradient_color - 1);
            s = s_max - s;
            l = i * (l_max - l_min) / (num_gradient_color - 1);
            l = l_max - l;
            MMI_DBG_ASSERT(s >= 0 && s <= 255);
            MMI_DBG_ASSERT(l >= 0 && l <= 255);
            hls.s = (U8) s;
            hls.l = (U8) l;
            gui_HLS_to_RGB(hls, &g_mmi_gui_scrollbar_gradient_style_6[i]);
        }
    }

}


/*****************************************************************************
* FUNCTION
*  gui_scrollbar_draw_region
* DESCRIPTION
*
* PARAMETERS
*  type        [IN]
*  x           [IN]
*  y           [IN]
*  width       [IN]
*  height      [IN]
* RETURNS
*  void
*****************************************************************************/
static void gui_scrollbar_draw_region_style_6(gui_scrollbar_region_enum type, S32 x, S32 y, S32 width, S32 height, icon_button *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color color;
    S32 x1, y1, x2, y2, i, j;
    S32 region_width = 4;
    S32 num_gradient_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_and_set_clip(x, y, x + width - 1, y + height - 1);
    }

    color = current_MMI_theme->scrollbar_background_filler->c;
    gui_scrollbar_precache_color1_style_6(
        color, 
        region_width,
        GUI_SCROLLBAR_MIN_BACKGROUND_GRADIENT_SATURATION_STYLE6, 
        GUI_SCROLLBAR_MAX_BACKGROUND_GRADIENT_SATURATION_STYLE6,
        GUI_SCROLLBAR_MIN_BACKGROUND_GRADIENT_LIGHTNESS_STYLE6, 
        GUI_SCROLLBAR_MAX_BACKGROUND_GRADIENT_LIGHTNESS_STYLE6,
        GUI_SCROLLBAR_NUM_BACKGROUND_GRADIENT_STYLE6);

    num_gradient_color = region_width;

    if (num_gradient_color > GUI_SCROLLBAR_NUM_BACKGROUND_GRADIENT_STYLE6)
    {
        num_gradient_color = GUI_SCROLLBAR_NUM_BACKGROUND_GRADIENT_STYLE6;
    }

    if (num_gradient_color > GUI_SCROLLBAR_NUM_GRADIENT_COLOR_STYLE6)
    {
        num_gradient_color = GUI_SCROLLBAR_NUM_GRADIENT_COLOR_STYLE6;
    }
    if (num_gradient_color <= 1)
    {
        num_gradient_color = 2;
    }

    if (type == GUI_SCROLLBAR_REGION_VERTICAL)
    {

        x1 = x + (width - region_width) / 2 + 1;
        x2 = x1 + region_width - 1;
        y1 = y + 1;
        y2 = y + height - 2;

        for (i = 0, j = 0; i < region_width; i ++)
        {
            gui_draw_vertical_line(y1, y2, x2 - i, g_mmi_gui_scrollbar_gradient_style_6[j]);

            if ((i % (region_width / num_gradient_color)) == (region_width / num_gradient_color - 1))
            {
                j ++;

                if (j >= num_gradient_color)
                {
                    j = num_gradient_color - 1;
                }
            }
        }

    }
    else
    {
        x1 = x + 1;
        x2 = x1 + width - 3;
        y1 = y + (height - region_width) / 2 + 1;
        y2 = y1 + region_width - 1;

        for (i = 0, j = 0; i < region_width; i ++)
        {
            gui_draw_horizontal_line(x1, x2, y1 + i, g_mmi_gui_scrollbar_gradient_style_6[j]);

            if ((i % (region_width / num_gradient_color)) == (region_width / num_gradient_color - 1))
            {
                j ++;

                if (j >= num_gradient_color)
                {
                    j = num_gradient_color - 1;
                }
            }
        }

    }

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }
}

/*****************************************************************************
* FUNCTION
*  gui_scrollbar_adjust_luminance
* DESCRIPTION
*
* PARAMETERS
*  luminance       [IN/OUT]
*  diff            [IN]
* RETURNS
*  void
*****************************************************************************/
static void gui_scrollbar_adjust_luminance_style_6(U8 *luminance, S16 diff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 l = *luminance;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    l += diff;
    if (l > 255)
    {
        l = 255;
    }
    if (l < 0)
    {
        l = 0;
    }
    *luminance = (U8) l;
}

/*****************************************************************************
* FUNCTION
*  gui_scrollbar_draw_button_style2
* DESCRIPTION
*
* PARAMETERS
*  type        [IN]
*  b           [IN/OUT]
* RETURNS
*  void
*****************************************************************************/
static void gui_scrollbar_draw_button_style2_style_6(gui_scrollbar_buttton_enum type, icon_button *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_HLS_color hls;
    color c;
    S32 x, y, width, height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (type == GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL && current_v->range == current_v->scale)
    {
        return;
    }
    else if (type == GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL && current_h->range == current_h->scale)
    {
        return;
    }

    x = b->x;
    y = b->y;
    width = b->width;
    height = b->height;
    c = b->normal_up_filler->c;

    /* Scroll button does not support highlight in UI_SCROLLBAR_STYLE_2 */
    if (type != GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL && type != GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL)
    {
        if (b->flags & UI_BUTTON_SHIFT_BUTTON1)
        {
            y++;
            gui_RGB_to_HLS(c, &hls);
            hls.l = (U8) ((U16) hls.l * 3 / 4);
            hls.s = (U8) ((U16) hls.s * 5 / 6);
            gui_HLS_to_RGB(hls, &c);
        }
        else if (b->flags & UI_BUTTON_SHIFT_BUTTON2)
        {
            y += 2;
            gui_RGB_to_HLS(c, &hls);
            hls.l = (U8) ((U16) hls.l * 3 / 4);
            hls.s = (U8) ((U16) hls.s * 5 / 6);
            gui_HLS_to_RGB(hls, &c);
        }
    }

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_and_set_clip(x, y, x + width - 1, y + height - 1);
    }

    /* shift the position to leave one-pixel space */
    if (type == GUI_SCROLLBAR_BUTTON_LEFT || type == GUI_SCROLLBAR_BUTTON_RIGHT)
    {
        x++;
    }
    if (type == GUI_SCROLLBAR_BUTTON_UP || type == GUI_SCROLLBAR_BUTTON_DOWN)
    {
        y++;
    }

    switch (type)
    {
    case GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL:
        /* FALLTHROUGH no break */
    case GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL:
        {
            S32 i;
            S32 num_shadow_line;
            color cs[3];    /* shadow color */
            color cf;       /* fill color */

            gui_RGB_to_HLS(c, &hls);

            if (height < 5 || width < 5)
            {
                /* No room to display the bar in special style */
                gui_show_icon_button(b);
            }
            else
            {
                if ((type == GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL && width >= 9) ||
                    (type == GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL && height >= 9))
                {
                    gui_scrollbar_adjust_luminance_style_6(&hls.l, 10);
                    gui_HLS_to_RGB(hls, &cs[0]);
                    gui_scrollbar_adjust_luminance_style_6(&hls.l, 10);
                    gui_HLS_to_RGB(hls, &cs[1]);
                    gui_scrollbar_adjust_luminance_style_6(&hls.l, 10);
                    gui_HLS_to_RGB(hls, &cs[2]);
                    gui_scrollbar_adjust_luminance_style_6(&hls.l, 10);
                    gui_HLS_to_RGB(hls, &cf);
                    num_shadow_line = 3;
                }
                else
                {
                    gui_scrollbar_adjust_luminance_style_6(&hls.l, 10);
                    gui_HLS_to_RGB(hls, &cs[0]);
                    gui_scrollbar_adjust_luminance_style_6(&hls.l, 10);
                    gui_HLS_to_RGB(hls, &cs[1]);
                    gui_scrollbar_adjust_luminance_style_6(&hls.l, 20);
                    gui_HLS_to_RGB(hls, &cf);
                    num_shadow_line = 2;
                }

                if (type == GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL)
                {
                    S32 x2, y2;

                    if (!(width % 2))
                    {
                        width--;
                    }
                    if (height >= 8)
                    {
                        /* Leave 1-pixel space */
                        y++;
                        height -= 2;
                    }

                    x2 = x + width - 1;
                    y2 = y + height - 1;

                    if (width <= 5)
                    {
                        gui_draw_vertical_line(y + 1, y2 - 1, x, c);
                        gui_draw_vertical_line(y + 1, y2 - 1, x2, c);
                        gui_draw_horizontal_line(x + 1, x2 - 1, y, c);
                        gui_draw_horizontal_line(x + 1, x2 - 1, y2, c);
                        for (i = x + 1; i < x2 - num_shadow_line; i++)
                        {
                            gui_draw_vertical_line(y + 1, y2 - 1, i, cf);
                        }

                        for (i = 0; i < num_shadow_line; i++)
                        {
                            gui_draw_vertical_line(y + 1, y2 - 1, x2 - 1 - i, cs[i]);
                        }
                    }
                    else
                    {
                        gui_draw_vertical_line(y + 2, y2 - 2, x, c);
                        gui_draw_vertical_line(y + 2, y2 - 2, x2, c);
                        gui_draw_horizontal_line(x + 2, x2 - 2, y, c);
                        gui_draw_horizontal_line(x + 2, x2 - 2, y2, c);

                        for (i = x + 1; i < x2 - num_shadow_line; i++)
                        {
                            gui_draw_vertical_line(y + 1, y2 - 1, i, cf);
                        }

                        for (i = 0; i < num_shadow_line; i++)
                        {
                            gui_draw_vertical_line(y + 1, y2 - 1, x2 - 1 - i, cs[i]);
                        }

                        gui_putpixel(x + 1, y + 1, c);
                        gui_putpixel(x2 - 1, y + 1, c);
                        gui_putpixel(x + 1, y2 - 1, c);
                        gui_putpixel(x2 - 1, y2 - 1, c);
                    }
                }
                else
                {
                    S32 x2, y2;

                    if (!(height % 2))
                    {
                        height--;
                    }
                    if (width >= 8)
                    {
                        /* Leave 1-pixel space */
                        x++;
                        width -= 2;
                    }

                    x2 = x + width - 1;
                    y2 = y + height - 1;

                    if (width <= 5)
                    {
                        gui_draw_horizontal_line(x + 1, x2 - 1, y, c);
                        gui_draw_horizontal_line(x + 1, x2 - 1, y2, c);
                        gui_draw_vertical_line(y + 1, y2 - 1, x, c);
                        gui_draw_vertical_line(y + 1, y2 - 1, x2, c);
                        for (i = y + 1; i < y2 - num_shadow_line; i++)
                        {
                            gui_draw_horizontal_line(x + 1, x2 - 1, i, cf);
                        }

                        for (i = 0; i < num_shadow_line; i++)
                        {
                            gui_draw_horizontal_line(x + 1, x2 - 1, y2 - 1 - i, cs[i]);
                        }
                    }
                    else
                    {
                        gui_draw_horizontal_line(x + 2, x2 - 2, y, c);
                        gui_draw_horizontal_line(x + 2, x2 - 2, y2, c);
                        gui_draw_vertical_line(y + 2, y2 - 2, x, c);
                        gui_draw_vertical_line(y + 2, y2 - 2, x2, c);

                        for (i = y + 1; i < y2 - num_shadow_line; i++)
                        {
                            gui_draw_horizontal_line(x + 1, x2 - 1, i, cf);
                        }

                        for (i = 0; i < num_shadow_line; i++)
                        {
                            gui_draw_horizontal_line(x + 1, x2 - 1, y2 - 1 - i, cs[i]);
                        }

                        gui_putpixel(x + 1, y + 1, c);
                        gui_putpixel(x2 - 1, y + 1, c);
                        gui_putpixel(x + 1, y2 - 1, c);
                        gui_putpixel(x2 - 1, y2 - 1, c);
                    }
                }
            }
        }
        break;
    }

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }
}


/*****************************************************************************
* FUNCTION
*  gui_scrollbar_draw_button
* DESCRIPTION
*
* PARAMETERS
*  type        [IN]
*  b           [IN/OUT]
* RETURNS
*  void
*****************************************************************************/
static void gui_scrollbar_draw_button_style_6(gui_scrollbar_buttton_enum type, icon_button *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c, border_color;
    S32 x, y, width, height;
    BOOL is_button_pressed = MMI_FALSE;
#if defined (__MMI_WALLPAPER_ON_BOTTOM__)
    gdi_handle old_src_layer, scr_layer, act_layer;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (type == GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL && current_v->range == current_v->scale)
    {
        return;
    }
    else if (type == GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL && current_h->range == current_h->scale)
    {
        return;
    }

    x = b->x;
    y = b->y;
    width = b->width;
    height = b->height;

    if (width == 0 || height == 0)
    {
        return;
    }

    if ((b->flags & UI_BUTTON_SHIFT_BUTTON1) || (b->flags & UI_BUTTON_SHIFT_BUTTON2))
    {
        is_button_pressed = MMI_TRUE;
    }

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_and_set_clip(x, y, x + width - 1, y + height - 1);
    }

    /* shift the position to keep one-pixel space */
    if (type == GUI_SCROLLBAR_BUTTON_LEFT || type == GUI_SCROLLBAR_BUTTON_RIGHT)
    {
        x++;
    }
    if (type == GUI_SCROLLBAR_BUTTON_UP || type == GUI_SCROLLBAR_BUTTON_DOWN)
    {
        y++;
    }

    switch (type)
    {
    case GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL:
        /* FALLTHROUGH no break */
    case GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL:
        {
            S32 x2, y2;
            S32 temp_x1, temp_x2, temp_y1, temp_y2, temp_width;


        #if defined (__MMI_WALLPAPER_ON_BOTTOM__)

            gdi_layer_get_active(&act_layer);

            old_src_layer = gui_get_transparent_source_layer();
            gdi_get_alpha_blending_source_layer(&scr_layer);

            if (scr_layer == GDI_ERROR_HANDLE ||  scr_layer == GDI_NULL_HANDLE)
            {
                scr_layer = act_layer;
            }

                gui_set_transparent_source_layer(scr_layer);
        #endif

            c = current_MMI_theme->scrollbar_indicator_filler->c;
            border_color = current_MMI_theme->scrollbar_indicator_filler->border_color;

            if (type == GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL)
            {
                /* 1 pixel spacing in the top and bottom side */
                x2 = x + width - GUI_SCROLLBAR_STYLE4_GAP_STYLE6;

            #if defined(__MMI_TOUCH_SCREEN__) && defined (__MMI_MAINLCD_128X160__)
                y2 = y + height - 1;
            #elif defined(__MMI_TOUCH_SCREEN__)
                y = y + GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE6;
                y2 = y + height - GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE6 * 2;
            #else
                y = y;
                y2 = y + height - GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP_STYLE6 ;
            #endif
                x++;
                height--;
            }
            else
            {
                /* 1 pixel spacing in the left and right side */
                y2 = y + height - GUI_SCROLLBAR_STYLE4_GAP_STYLE6;

            #if defined(__MMI_TOUCH_SCREEN__) && defined (__MMI_MAINLCD_128X160__)
                x2 = x + width - 1;
            #elif defined(__MMI_TOUCH_SCREEN__)
                x = x + GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE6;
                x2 = x + width - GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE6 * 2;
            #else
                x = x;
                x2 = x + width - GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP_STYLE6;
            #endif
                width--;
                x++;
            }

            temp_x1 = x;
            temp_y1 = y + 1;
            temp_x2 = x2 - 1;
            temp_y2 = y2 - 1;

            temp_width = temp_x2 - temp_x1 + 1;

            gui_scrollbar_precache_color1_style_6(
                c, 
                width,
                GUI_SCROLLBAR_MIN_INDICATOR_GRADIENT_SATURATION_STYLE6, 
                GUI_SCROLLBAR_MAX_INDICATOR_GRADIENT_SATURATION_STYLE6,
                GUI_SCROLLBAR_MIN_INDICATOR_GRADIENT_LIGHTNESS_STYLE6, 
                GUI_SCROLLBAR_MAX_INDICATOR_GRADIENT_LIGHTNESS_STYLE6,
                GUI_SCROLLBAR_NUM_INDICATOR_GRADIENT_STYLE6);

            gui_fill_rectangle(x + 2, y + 3, x2 - 3, y2 - 3, g_mmi_gui_scrollbar_gradient_style_6[1]);

            gui_draw_vertical_line(temp_y1 + 2, temp_y2 - 2, temp_x1 + 1, g_mmi_gui_scrollbar_gradient_style_6[0]);
            gui_draw_vertical_line(temp_y1 + 1, temp_y2 - 1, temp_x1 + 2, g_mmi_gui_scrollbar_gradient_style_6[0]);
            gui_draw_horizontal_line(temp_x1 + 2, temp_x2 - 2, temp_y1 + 1, g_mmi_gui_scrollbar_gradient_style_6[0]);
            gui_draw_horizontal_line(temp_x1 + 1, temp_x2 - 1, temp_y1 + 2, g_mmi_gui_scrollbar_gradient_style_6[0]);
            gui_draw_horizontal_line(temp_x1 + 2, temp_x2 - 2, temp_y2 - 1, g_mmi_gui_scrollbar_gradient_style_6[2]);
            gui_draw_horizontal_line(temp_x1 + 1, temp_x2 - 1, temp_y2 - 2, g_mmi_gui_scrollbar_gradient_style_6[2]);
            gui_draw_vertical_line(temp_y1 + 2, temp_y2 - 2, temp_x2 - 1, g_mmi_gui_scrollbar_gradient_style_6[2]);
            gui_draw_vertical_line(temp_y1 + 1, temp_y2 - 1, temp_x2 - 2, g_mmi_gui_scrollbar_gradient_style_6[2]);

            gui_draw_vertical_line(temp_y1 + 2, temp_y2 - 2, temp_x1, border_color);
            gui_draw_vertical_line(temp_y1 + 2, temp_y2 - 2, temp_x2, border_color);
            gui_draw_horizontal_line(temp_x1 + 2, temp_x2 - 2, temp_y1, border_color);
            gui_draw_horizontal_line(temp_x1 + 2, temp_x2 - 2, temp_y2, border_color);

            gui_draw_rectangle(temp_x1 + 1, temp_y1 + 1, temp_x1 + 1, temp_y1 + 1, border_color);

            gui_draw_rectangle(temp_x2 - 1, temp_y1 + 1, temp_x2 - 1, temp_y1 + 1, border_color);

            gui_draw_rectangle(temp_x1 + 1, temp_y2 - 1, temp_x1 + 1, temp_y2 - 1, border_color);

            gui_draw_rectangle(temp_x2 - 1, temp_y2 - 1, temp_x2 - 1, temp_y2 - 1, border_color);

        #if defined (__MMI_WALLPAPER_ON_BOTTOM__)
            gui_set_transparent_source_layer(old_src_layer);
        #endif /* __MMI_WALLPAPER_ON_BOTTOM__ */

            break;
        }

    case GUI_SCROLLBAR_BUTTON_UP:
    case GUI_SCROLLBAR_BUTTON_LEFT:
    case GUI_SCROLLBAR_BUTTON_DOWN:
    case GUI_SCROLLBAR_BUTTON_RIGHT:
        {
            S32 x2 = 0, y2 = 0;

            c = current_MMI_theme->scrollbar_background_filler->c;

            if (type == GUI_SCROLLBAR_BUTTON_LEFT || type == GUI_SCROLLBAR_BUTTON_RIGHT)
            {
            #if defined(__MMI_TOUCH_SCREEN__) && defined (__MMI_MAINLCD_128X160__)
                y2 = y + height - 1;
            #else
                y = y + GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE6;
                y2 = y + height - GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE6 * 2;
            #endif

            }
            if (type == GUI_SCROLLBAR_BUTTON_UP || type == GUI_SCROLLBAR_BUTTON_DOWN)
            {
            #if defined(__MMI_TOUCH_SCREEN__) && defined (__MMI_MAINLCD_128X160__)
                x2 = x + width - 1;
            #else
                x = x + GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE6;
                x2 = x + width - GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE6 * 2;
            #endif

            }
            if (is_button_pressed)
            {
                if(type == GUI_SCROLLBAR_BUTTON_UP || type == GUI_SCROLLBAR_BUTTON_DOWN)
                {
                    y++;
                }
                else if(type == GUI_SCROLLBAR_BUTTON_LEFT || type == GUI_SCROLLBAR_BUTTON_RIGHT)
                {
                    x++;
                }
            }

            if (type == GUI_SCROLLBAR_BUTTON_UP)
            {
                S32 arrow_width = x2 - x + 1 - (GUI_SCROLLBAR_STYLE4_GAP_STYLE6 << 1);
                S32 arrow_height;
                S32 x1, y1, i;
                S32 bottom, left;

                arrow_width -= (arrow_width % 2);
                arrow_height = arrow_width >> 1;


                gui_scrollbar_precache_color1_style_6(
                    c, 
                    arrow_width,
                    GUI_SCROLLBAR_MIN_BACKGROUND_GRADIENT_SATURATION_STYLE6, 
                    GUI_SCROLLBAR_MAX_BACKGROUND_GRADIENT_SATURATION_STYLE6,
                    GUI_SCROLLBAR_MIN_BACKGROUND_GRADIENT_LIGHTNESS_STYLE6, 
                    GUI_SCROLLBAR_MAX_BACKGROUND_GRADIENT_LIGHTNESS_STYLE6,
                    GUI_SCROLLBAR_NUM_BACKGROUND_GRADIENT_STYLE6);

                x1 = (x2 - x + 1 - arrow_width);
                if (x1 > 0)
                {
                    x1 >>= 1;
                }
                else
                {
                    x1 = 0;
                }
                x1 += x + 1;

                y1 = (height - arrow_height);
                if (y1 > 0)
                {
                    y1 >>= 1;
                }
                else
                {
                    y1 = 0;
                }
                y1 += y + arrow_height - 1 - 2; /* -1 for center */

                left = x1;
                bottom = y1;
                for (i = 0; i < arrow_height; i++)
                {
                    gui_draw_vertical_line(y1, bottom, x1, g_mmi_gui_scrollbar_gradient_style_6[1]);

                    y1--;
                    x1++;
                }
                y1 += 2;

                for (i = 1; i < arrow_height; i++)
                {
                    gui_draw_vertical_line(y1, bottom, x1, g_mmi_gui_scrollbar_gradient_style_6[1]);

                    y1++;
                    x1++;
                }

                x1 = left;
                y1 = bottom;


                for (i = 0; i < arrow_height; i++)
                {
                    gui_putpixel(x1, y1, g_mmi_gui_scrollbar_gradient_style_6[3]);
                    gui_putpixel(x1, y1 + 1, g_mmi_gui_scrollbar_gradient_style_6[3]);

                    y1--;
                    x1++;
                }

                x1 = left + 2;
                y1 = bottom;

                for (i = 2; i < arrow_height; i++)
                {
                    gui_putpixel(x1, y1, g_mmi_gui_scrollbar_gradient_style_6[2]);
                    gui_putpixel(x1, y1 + 1, g_mmi_gui_scrollbar_gradient_style_6[2]);

                    y1--;
                    x1++;
                }

                for (i = 1; i < arrow_height; i++)
                {
                    gui_putpixel(x1, y1, g_mmi_gui_scrollbar_gradient_style_6[2]);
                    gui_putpixel(x1, y1 + 1, g_mmi_gui_scrollbar_gradient_style_6[2]);
                    y1++;
                    x1++;
                }
                gui_draw_horizontal_line(left, left + arrow_width - 2, bottom + 1, g_mmi_gui_scrollbar_gradient_style_6[0]);

            }
            else if (type == GUI_SCROLLBAR_BUTTON_DOWN)
            {
                S32 arrow_width = x2 - x + 1 - (GUI_SCROLLBAR_STYLE4_GAP_STYLE6 << 1);
                S32 arrow_height;
                S32 x1, y1, i, j;
                S32 bottom, left;

                arrow_width -= (arrow_width % 2);
                arrow_height = arrow_width >> 1;

                gui_scrollbar_precache_color1_style_6(
                    c, 
                    arrow_width,
                    GUI_SCROLLBAR_MIN_BACKGROUND_GRADIENT_SATURATION_STYLE6, 
                    GUI_SCROLLBAR_MAX_BACKGROUND_GRADIENT_SATURATION_STYLE6,
                    GUI_SCROLLBAR_MIN_BACKGROUND_GRADIENT_LIGHTNESS_STYLE6, 
                    GUI_SCROLLBAR_MAX_BACKGROUND_GRADIENT_LIGHTNESS_STYLE6,
                    GUI_SCROLLBAR_NUM_BACKGROUND_GRADIENT_STYLE6);

                x1 = (x2 - x + 1 - arrow_width);
                if (x1 > 0)
                {
                    x1 >>= 1;
                }
                else
                {
                    x1 = 0;
                }
                x1 += x + 1;

                y1 = (height - arrow_height);
                if (y1 > 0)
                {
                    y1 >>= 1;
                }
                else
                {
                    y1 = 0;
                }
                y1 += y;

                j = 0;
                left = x1;
                bottom = y1;
                for (i = 0; i < arrow_height; i++)
                {
                    gui_draw_vertical_line(y1, bottom, x1, g_mmi_gui_scrollbar_gradient_style_6[1]);

                    y1++;
                    x1++;
                }
                y1 -= 2;
                for (i = 1; i < arrow_height; i++)
                {
                    gui_draw_vertical_line(y1, bottom, x1, g_mmi_gui_scrollbar_gradient_style_6[1]);

                    y1--;
                    x1++;

                }

                x1 = left;
                y1 = bottom;

                for (i = 0; i < arrow_height; i++)
                {
                    gui_putpixel(x1, y1, g_mmi_gui_scrollbar_gradient_style_6[2]);
                    gui_putpixel(x1, y1 - 1, g_mmi_gui_scrollbar_gradient_style_6[2]);
                    y1++;
                    x1++;
                }

                x1 --;
                y1 --;

                for (i = 1; i < arrow_height; i++)
                {
                    gui_putpixel(x1, y1, g_mmi_gui_scrollbar_gradient_style_6[0]);
                    gui_putpixel(x1, y1 - 1, g_mmi_gui_scrollbar_gradient_style_6[0]);
                    y1--;
                    x1++;
                }


                gui_draw_horizontal_line(left + 2, left + arrow_width - 5, bottom +1, g_mmi_gui_scrollbar_gradient_style_6[2]);
                gui_draw_horizontal_line(left + 1, left + arrow_width - 4, bottom, g_mmi_gui_scrollbar_gradient_style_6[2]);

                gui_draw_horizontal_line(left, left + arrow_width - 2, bottom - 1, g_mmi_gui_scrollbar_gradient_style_6[3]);

            }
            else if (type == GUI_SCROLLBAR_BUTTON_LEFT)
            {
                S32 arrow_height = height - (GUI_SCROLLBAR_ARROW_GAP_STYLE6 << 1);
                S32 arrow_width;
                S32 x1, y1, i;
                S32 right, top;

                arrow_height -= (arrow_height % 2);
                arrow_width = arrow_height >> 1;


                gui_scrollbar_precache_color1_style_6(
                    c, 
                    arrow_height,
                    GUI_SCROLLBAR_MIN_BACKGROUND_GRADIENT_SATURATION_STYLE6, 
                    GUI_SCROLLBAR_MAX_BACKGROUND_GRADIENT_SATURATION_STYLE6,
                    GUI_SCROLLBAR_MIN_BACKGROUND_GRADIENT_LIGHTNESS_STYLE6, 
                    GUI_SCROLLBAR_MAX_BACKGROUND_GRADIENT_LIGHTNESS_STYLE6,
                    GUI_SCROLLBAR_NUM_BACKGROUND_GRADIENT_STYLE6);

                y1 = (y2 - y + 1 - arrow_height);
                if (y1 > 0)
                {
                    y1 >>= 1;
                }
                else
                {
                    y1 = 0;
                }
                y1 += y + 1;

                x1 = (width - arrow_width);
                if (x1 > 0)
                {
                    x1 >>= 1;
                }
                else
                {
                    x1 = 0;
                }
                x1 += x + arrow_width - 3;  /* -1 for center */

                right = x1;
                top = y1;

                for (i = 0; i < arrow_width; i++)
                {
                    gui_draw_horizontal_line(x1, right, y1, g_mmi_gui_scrollbar_gradient_style_6[1]);
                    y1++;
                    x1--;
                }
                x1 += 2;
                for (i = 1; i < arrow_width; i++)
                {
                    gui_draw_horizontal_line(x1, right, y1, g_mmi_gui_scrollbar_gradient_style_6[1]);
                    y1++;
                    x1++;
                }

                x1 = right;
                y1 = top;

                for (i = 0; i < arrow_width; i++)
                {
                    gui_putpixel(x1, y1, g_mmi_gui_scrollbar_gradient_style_6[3]);
                    gui_putpixel(x1 + 1, y1, g_mmi_gui_scrollbar_gradient_style_6[3]);
                    y1 ++;
                    x1 --;
                }

                x1 = right;
                y1 = top + 2;

                for (i = 2; i < arrow_width; i++)
                {
                    gui_putpixel(x1, y1, g_mmi_gui_scrollbar_gradient_style_6[2]);
                    gui_putpixel(x1 + 1, y1, g_mmi_gui_scrollbar_gradient_style_6[2]);
                    y1++;
                    x1--;
                }

                for (i = 1; i < arrow_width; i++)
                {
                    gui_putpixel(x1, y1, g_mmi_gui_scrollbar_gradient_style_6[2]);
                    gui_putpixel(x1 + 1, y1, g_mmi_gui_scrollbar_gradient_style_6[2]);
                    y1++;
                    x1++;
                }

                gui_draw_vertical_line(top, top + arrow_height - 2, right + 1, g_mmi_gui_scrollbar_gradient_style_6[0]);

            }
            else
            {
                S32 arrow_height = height - (GUI_SCROLLBAR_ARROW_GAP_STYLE6 << 1);
                S32 arrow_width;
                S32 x1, y1, i;
                S32 left, top;

                arrow_height -= (arrow_height % 2);
                arrow_width = arrow_height >> 1;

                gui_scrollbar_precache_color1_style_6(
                    c, 
                    arrow_height,
                    GUI_SCROLLBAR_MIN_BACKGROUND_GRADIENT_SATURATION_STYLE6, 
                    GUI_SCROLLBAR_MAX_BACKGROUND_GRADIENT_SATURATION_STYLE6,
                    GUI_SCROLLBAR_MIN_BACKGROUND_GRADIENT_LIGHTNESS_STYLE6, 
                    GUI_SCROLLBAR_MAX_BACKGROUND_GRADIENT_LIGHTNESS_STYLE6,
                    GUI_SCROLLBAR_NUM_BACKGROUND_GRADIENT_STYLE6);

                y1 = (y2 - y + 1 - arrow_height);
                if (y1 > 0)
                {
                    y1 >>= 1;
                }
                else
                {
                    y1 = 0;
                }
                y1 += y + 1;

                x1 = (width - arrow_width);
                if (x1 > 0)
                {
                    x1 >>= 1;
                }
                else
                {
                    x1 = 0;
                }
                x1 += x - 1;

                left = x1;
                top = y1;

                for (i = 0; i < arrow_width; i++)
                {
                    gui_draw_horizontal_line(x1, left, y1, g_mmi_gui_scrollbar_gradient_style_6[1]);
                    y1++;
                    x1++;
                }
                x1 -= 2;
                for (i = 1; i < arrow_width; i++)
                {
                    gui_draw_horizontal_line(x1, left, y1, g_mmi_gui_scrollbar_gradient_style_6[1]);
                    y1++;
                    x1--;
                }

                x1 = left;
                y1 = top;

                for (i = 0; i < arrow_width; i++)
                {
                    gui_putpixel(x1, y1, g_mmi_gui_scrollbar_gradient_style_6[2]);
                    gui_putpixel(x1 - 1, y1, g_mmi_gui_scrollbar_gradient_style_6[2]);
                    y1++;
                    x1++;
                }
                x1 -= 2;
                for (i = 1; i < arrow_width; i++)
                {
                    gui_putpixel(x1, y1, g_mmi_gui_scrollbar_gradient_style_6[0]);
                    gui_putpixel(x1 - 1, y1, g_mmi_gui_scrollbar_gradient_style_6[0]);
                    y1++;
                    x1--;
                }

                gui_draw_vertical_line(top + 1, top + arrow_height - 4, left, g_mmi_gui_scrollbar_gradient_style_6[2]);
                gui_draw_vertical_line(top + 2, top + arrow_height - 5, left + 1, g_mmi_gui_scrollbar_gradient_style_6[2]);

                gui_draw_vertical_line(top, top + arrow_height - 2, left - 1, g_mmi_gui_scrollbar_gradient_style_6[3]);

            }

            break;
        }

        default:
            MMI_DBG_ASSERT(0);
    }

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }

}


/*****************************************************************************
* FUNCTION
*  gui_scrollbar_get_button_min_size
* DESCRIPTION
*
* PARAMETERS
*  type            [IN]
*  bar_width       [IN]
* RETURNS
*
*****************************************************************************/
S32 gui_scrollbar_get_button_min_size_style_6(gui_scrollbar_buttton_enum type, S32 bar_width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
    case GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL:
        /* FALLTHROUGH no break */
    case GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL:
        ret = GUI_SCROLLBAR_MIN_HEIGHT_SCROLL_BUTTON_STYLE6;
        break;

    case GUI_SCROLLBAR_BUTTON_UP:
        /* FALLTHROUGH no break */
    case GUI_SCROLLBAR_BUTTON_DOWN:
    case GUI_SCROLLBAR_BUTTON_LEFT:
    case GUI_SCROLLBAR_BUTTON_RIGHT:

    #if defined(__MMI_TOUCH_SCREEN__) && defined (__MMI_MAINLCD_128X160__)
        ret = current_MMI_theme->scrollbar_size;
    #else
        ret = current_MMI_theme->scrollbar_size - GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE6 * 2 + 1;
    #endif

        break;

    default:
        MMI_ASSERT(0);
    }

    return ret;
}
#endif

#if defined(UI_SCROLLBAR_STYLE_5) || defined(UI_SCROLLBAR_WIDER_STYLE_5)
static S32 g_mmi_gui_scrollbar_width_style_5 = 0;

/* Height of up/down button, or width of left/right button */
static S32 g_mmi_gui_scrollbar_button_size_style_5;

/* The scrollbar background is composed by three different images. */
static S32 g_mmi_gui_scrollbar_bar_size1_style_5;
static S32 g_mmi_gui_scrollbar_bar_size2_style_5;
static S32 g_mmi_gui_scrollbar_bar_size3_style_5;
static S32 g_mmi_gui_scrollbar_bar_size4_style_5;


/*****************************************************************************
* FUNCTION
*  gui_scrollbar_precache_image_size
* DESCRIPTION
*
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void gui_scrollbar_precache_image_size_style_5(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_mmi_gui_scrollbar_width_style_5)
    {
        S32 iw, ih;

	#ifndef __MMI_FTE_SUPPORT__
        gui_measure_image((PU8) GetImage(IMG_SCROLLBAR_BUTTON_UP), &iw, &ih);
        g_mmi_gui_scrollbar_width_style_5 = iw;
        g_mmi_gui_scrollbar_button_size_style_5 = ih;
	#endif
        gui_measure_image((PU8) GetImage(IMG_SCROLLBAR_V_BAR_TOP), &iw, &ih);
        g_mmi_gui_scrollbar_bar_size1_style_5 = ih;

        gui_measure_image((PU8) GetImage(IMG_SCROLLBAR_V_BAR_MIDDLE), &iw, &ih);
        g_mmi_gui_scrollbar_bar_size2_style_5 = ih;

        gui_measure_image((PU8) GetImage(IMG_SCROLLBAR_V_BAR_BOTTOM), &iw, &ih);
        g_mmi_gui_scrollbar_bar_size3_style_5 = ih;

        gui_measure_image((PU8) GetImage(IMG_SCROLLBAR_V_BAR_BGD), &iw, &ih);
        g_mmi_gui_scrollbar_bar_size4_style_5 = ih;
    }
}


/*****************************************************************************
* FUNCTION
*  gui_scrollbar_get_button_min_size
* DESCRIPTION
*
* PARAMETERS
*  type            [IN]
*  bar_width       [IN]
* RETURNS
*
*****************************************************************************/
S32 gui_scrollbar_get_button_min_size_style_5(gui_scrollbar_buttton_enum type, S32 bar_width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_scrollbar_precache_image_size_style_5();
#ifndef __MMI_FTE_SUPPORT__
    MMI_DBG_ASSERT(g_mmi_gui_scrollbar_width_style_5 == bar_width);
#endif /* __MMI_FTE_SUPPORT__ */

    switch (type)
    {
    case GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL:
        /* FALLTHROUGH no break */
    case GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL:
        ret = GUI_SCROLLBAR_MIN_HEIGHT_SCROLL_BUTTON_STYLE5;
        break;

    case GUI_SCROLLBAR_BUTTON_UP:
        /* FALLTHROUGH no break */
    case GUI_SCROLLBAR_BUTTON_DOWN:
        /* FALLTHROUGH no break */
    case GUI_SCROLLBAR_BUTTON_LEFT:
        /* FALLTHROUGH no break */
    case GUI_SCROLLBAR_BUTTON_RIGHT:
    #ifdef __MMI_FTE_SUPPORT__
        ret = 0; //UI_SCROLLBAR_WIDER_WIDTH + 2;
    #else /* __MMI_FTE_SUPPORT__ */
        ret = g_mmi_gui_scrollbar_button_size_style_5 + 2 /* 1 + 1 pixel spacing */ ;
    #endif /* __MMI_FTE_SUPPORT__ */
        break;

    default:
        MMI_ASSERT(0);
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  gui_scrollbar_draw_region
* DESCRIPTION
*
* PARAMETERS
*  type        [IN]
*  x           [IN]
*  y           [IN]
*  width       [IN]
*  height      [IN]
* RETURNS
*  void
*****************************************************************************/
static void gui_scrollbar_draw_region_style_5(gui_scrollbar_region_enum type, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 remain;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_and_set_clip(x, y, x + width - 1, y + height - 1);
    }

    if (type == GUI_SCROLLBAR_REGION_VERTICAL)
    {
    #ifdef __MMI_FTE_SUPPORT__
        gdi_image_draw_resized(x, y, width, height, current_vertical_scrollbar_theme->scroll_background_icon);
    #else /* __MMI_FTE_SUPPORT__ */
        remain = height;
        while (remain > 0)
        {
            gui_show_transparent_image(x, y, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_BGD), UI_DEFAULT_TRANSPARENT_COLOR);
            y += g_mmi_gui_scrollbar_bar_size4_style_5;
            remain -= g_mmi_gui_scrollbar_bar_size4_style_5;
        }
    #endif /* __MMI_FTE_SUPPORT__ */
    }
    else
    {
    #ifdef __MMI_FTE_SUPPORT__
        gdi_image_draw_resized(x, y, width, height, current_horizontal_scrollbar_theme->scroll_background_icon);
    #else /* __MMI_FTE_SUPPORT__ */
        remain = width;
        while (remain > 0)
        {
            gui_show_transparent_image(x, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_BGD), UI_DEFAULT_TRANSPARENT_COLOR);
            x += g_mmi_gui_scrollbar_bar_size4_style_5;
            remain -= g_mmi_gui_scrollbar_bar_size4_style_5;
        }
    #endif /* __MMI_FTE_SUPPORT__ */
    }

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }
}

/*****************************************************************************
* FUNCTION
*  gui_scrollbar_draw_button
* DESCRIPTION
*
* PARAMETERS
*  type        [IN]
*  b           [IN/OUT]
* RETURNS
*  void
*****************************************************************************/
static void gui_scrollbar_draw_button_style_5(gui_scrollbar_buttton_enum type, icon_button *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c;
    S32 x, y, width, height;
    MMI_BOOL is_button_pressed = MMI_FALSE;
    PU8 image;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_scrollbar_precache_image_size_style_5();

    c = b->normal_up_filler->c;
    x = b->x;
    y = b->y;
    width = b->width;
    height = b->height;

    if (width == 0 || height == 0)
    {
        return;
    }

    if ((b->flags & UI_BUTTON_SHIFT_BUTTON1) || (b->flags & UI_BUTTON_SHIFT_BUTTON2))
    {
        is_button_pressed = MMI_TRUE;
    }

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_and_set_clip(x, y, x + width - 1, y + height - 1);
    }
    
#ifndef __MMI_FTE_SUPPORT__
    /* shift the position to keep one-pixel space */
    if (type == GUI_SCROLLBAR_BUTTON_LEFT || type == GUI_SCROLLBAR_BUTTON_RIGHT)
    {
        x++;
    }
    if (type == GUI_SCROLLBAR_BUTTON_UP || type == GUI_SCROLLBAR_BUTTON_DOWN)
    {
        y++;
    }
#endif

    switch (type)
    {
        gdi_handle active_layer;
    case GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL:
        {
        #ifdef __MMI_FTE_SUPPORT__
            if(current_v->alpha_blend_layer == GDI_NULL_HANDLE)
            {
                gdi_layer_get_active (&active_layer);
                gdi_push_and_set_alpha_blending_source_layer(active_layer);
            }
            if(is_button_pressed)
            {
                image = current_vertical_scrollbar_theme->scroll_button_focused_icon;
            }
            else
            {
                image = current_vertical_scrollbar_theme->scroll_button_icon;
            }
            gdi_image_draw_resized(x, y, width, height, image);
            if(current_v->alpha_blend_layer == GDI_NULL_HANDLE)
            {
                gdi_pop_and_restore_alpha_blending_source_layer();
            }
        #else /* __MMI_FTE_SUPPORT__ */
            S32 x2, y2;


            x2 = x + width - 1;
            y2 = y + height - 1;
            if (height <= g_mmi_gui_scrollbar_bar_size1_style_5 + g_mmi_gui_scrollbar_bar_size3_style_5)
            {
                if (gui_scrollbar_redraw_clip_enable)
                {
                    gui_set_clip(x, y, x + width - 1, y + (height >> 1) - 1);
                }
                gui_show_transparent_image(x, y, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_TOP), UI_DEFAULT_TRANSPARENT_COLOR);
                if (gui_scrollbar_redraw_clip_enable)
                {
                    gui_set_clip(x, y + (height >> 1), x + width - 1, y + height - 1);
                }
                gui_show_transparent_image(x, y + height - g_mmi_gui_scrollbar_bar_size3_style_5, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_BOTTOM), UI_DEFAULT_TRANSPARENT_COLOR);
            }
            else
            {
                S32 y1, y2, remain;

                y1 = y + g_mmi_gui_scrollbar_bar_size1_style_5;
                y2 = y + height - g_mmi_gui_scrollbar_bar_size3_style_5 - 1;
                gui_show_transparent_image(x, y, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_TOP), UI_DEFAULT_TRANSPARENT_COLOR);
                gui_show_transparent_image(x, y2 + 1, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_BOTTOM), UI_DEFAULT_TRANSPARENT_COLOR);
                if (gui_scrollbar_redraw_clip_enable)
                {
                    gui_set_clip(x, y1, x + width - 1, y2);
                }
                remain = y2 - y1 + 1;
                image = (PU8) GetImage(IMG_SCROLLBAR_V_BAR_MIDDLE);
                while (remain > 0)
                {
                    gui_show_transparent_image(x, y1, image, UI_DEFAULT_TRANSPARENT_COLOR);
                    y1 += g_mmi_gui_scrollbar_bar_size2_style_5;
                    remain -= g_mmi_gui_scrollbar_bar_size2_style_5;
                }
            }
        #endif /* __MMI_FTE_SUPPORT__ */
            break;
        }
    case GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL:
        {
        #ifdef __MMI_FTE_SUPPORT__
            if(current_h->alpha_blend_layer == GDI_NULL_HANDLE)
            {
                gdi_layer_get_active (&active_layer);
                gdi_push_and_set_alpha_blending_source_layer(active_layer);
            }
            if(is_button_pressed)
            {
                image = current_horizontal_scrollbar_theme->scroll_button_focused_icon;
            }
            else
            {
                image = current_horizontal_scrollbar_theme->scroll_button_icon;
            }
            gdi_image_draw_resized(x, y, width, height, image);
            if(current_h->alpha_blend_layer == GDI_NULL_HANDLE)
            {
                gdi_pop_and_restore_alpha_blending_source_layer();
            }
        #else /* __MMI_FTE_SUPPORT__ */
            S32 x2, y2;


            x2 = x + width - 1;
            y2 = y + height - 1;
            if (width <= g_mmi_gui_scrollbar_bar_size1_style_5 + g_mmi_gui_scrollbar_bar_size3_style_5)
            {
                if (gui_scrollbar_redraw_clip_enable)
                {
                    gui_set_clip(x, y, x + (width >> 1) - 1, y + height - 1);
                }
                gui_show_transparent_image(x, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_LEFT), UI_DEFAULT_TRANSPARENT_COLOR);
                if (gui_scrollbar_redraw_clip_enable)
                {
                    gui_set_clip(x + (width >> 1), y, x + width - 1, y + height - 1);
                }
                gui_show_transparent_image(x + width - g_mmi_gui_scrollbar_bar_size3_style_5, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_RIGHT), UI_DEFAULT_TRANSPARENT_COLOR);
            }
            else
            {
                S32 x1, x2, remain;

                x1 = x + g_mmi_gui_scrollbar_bar_size1_style_5;
                x2 = x + width - g_mmi_gui_scrollbar_bar_size3_style_5 - 1;
                gui_show_transparent_image(x, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_LEFT), UI_DEFAULT_TRANSPARENT_COLOR);
                gui_show_transparent_image(x2 + 1, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_RIGHT), UI_DEFAULT_TRANSPARENT_COLOR);
                if (gui_scrollbar_redraw_clip_enable)
                {
                    gui_set_clip(x1, y, x2, y + height - 1);
                }
                remain = x2 - x1 + 1;
                image = (PU8) GetImage(IMG_SCROLLBAR_H_BAR_MIDDLE);
                while (remain > 0)
                {
                    gui_show_transparent_image(x1, y, image, UI_DEFAULT_TRANSPARENT_COLOR);
                    x1 += g_mmi_gui_scrollbar_bar_size2_style_5;
                    remain -= g_mmi_gui_scrollbar_bar_size2_style_5;
                }
            }
        #endif /* __MMI_FTE_SUPPORT__ */
            break;
        }


        case GUI_SCROLLBAR_BUTTON_UP:
        case GUI_SCROLLBAR_BUTTON_LEFT:
        case GUI_SCROLLBAR_BUTTON_DOWN:
        case GUI_SCROLLBAR_BUTTON_RIGHT:
            {
            #ifdef __MMI_FTE_SUPPORT__
                if (type == GUI_SCROLLBAR_BUTTON_UP)
                {
                    if (is_button_pressed)
                    {
                        image = current_vertical_scrollbar_theme->up_button_focused_icon;
                    }
                    else
                    {
                        image = current_vertical_scrollbar_theme->up_button_icon;
                    }

                }
                else if (type == GUI_SCROLLBAR_BUTTON_DOWN)
                {
                    if (is_button_pressed)
                    {
                        image = current_vertical_scrollbar_theme->down_button_focused_icon;
                    }
                    else
                    {
                        image = current_vertical_scrollbar_theme->down_button_icon;
                    }
                }
                else if (type == GUI_SCROLLBAR_BUTTON_LEFT)
                {
                    if (is_button_pressed)
                    {
                        image = current_horizontal_scrollbar_theme->left_button_focused_icon;
                    }
                    else
                    {
                        image = current_horizontal_scrollbar_theme->left_button_icon;
                    }
                }
                else
                {
                    if (is_button_pressed)
                    {
                        image = current_horizontal_scrollbar_theme->right_button_focused_icon;
                    }
                    else
                    {
                        image = current_horizontal_scrollbar_theme->right_button_icon;
                    }
                }
                gdi_image_draw_resized(x, y, width, height, image);
            #else /* __MMI_FTE_SUPPORT__ */
                MMI_ID_TYPE image_id;
            
                if (type == GUI_SCROLLBAR_BUTTON_UP)
                {
                    if (is_button_pressed)
                    {
                        image_id = IMG_SCROLLBAR_BUTTON_UP_PRESSED;
                    }
                    else
                    {
                        image_id = IMG_SCROLLBAR_BUTTON_UP;
                    }

                }
                else if (type == GUI_SCROLLBAR_BUTTON_DOWN)
                {
                    if (is_button_pressed)
                    {
                        image_id = IMG_SCROLLBAR_BUTTON_DOWN_PRESSED;
                    }
                    else
                    {
                        image_id = IMG_SCROLLBAR_BUTTON_DOWN;
                    }
                }
                else if (type == GUI_SCROLLBAR_BUTTON_LEFT)
                {
                    if (is_button_pressed)
                    {
                        image_id = IMG_SCROLLBAR_BUTTON_LEFT_PRESSED;
                    }
                    else
                    {
                        image_id = IMG_SCROLLBAR_BUTTON_LEFT;
                    }
                }
                else
                {
                    if (is_button_pressed)
                    {
                        image_id = IMG_SCROLLBAR_BUTTON_RIGHT_PRESSED;
                    }
                    else
                    {
                        image_id = IMG_SCROLLBAR_BUTTON_RIGHT;
                    }
                }
                gui_show_transparent_image(x, y, (PU8) GetImage(image_id), UI_DEFAULT_TRANSPARENT_COLOR);
            #endif /* __MMI_FTE_SUPPORT__ */
                break;
        }

        default:
            MMI_DBG_ASSERT(0);
    }

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }

}

#endif

#if defined(UI_SCROLLBAR_STYLE_4) || defined(UI_SCROLLBAR_WIDER_STYLE_4)

/* Use image to draw the scrollbar. */

/* color of the moveable part (scroll button) */
static S32 g_mmi_gui_scrollbar_cache_hue_style_4 = -1;
static S32 g_mmi_gui_scrollbar_cache_num_gcolor_style_4 = 0;

static color g_mmi_gui_scrollbar_gradient_style_4[GUI_SCROLLBAR_NUM_GRADIENT_COLOR_STYLE4];

#ifndef __MMI_WALLPAPER_ON_BOTTOM__
static color g_mmi_gui_scrollbar_bk_color_style_4;
static color g_mmi_gui_scrollbar_border_color_style_4;
#endif


/*
* RGB <-> HLS color space conversion with cache to avoid floating point arithmetics
*/


/*****************************************************************************
* FUNCTION
*  gui_scrollbar_RGB_to_HLS
* DESCRIPTION
*
* PARAMETERS
*  rgb     [IN]
*  hls     [OUT]
* RETURNS
*  void
*****************************************************************************/
static void gui_scrollbar_RGB_to_HLS_style_4(color rgb, UI_HLS_color *hls)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static color cached_rgb = {0, 0, 0, 0};
    static UI_HLS_color cached_hls = {0, 0, 0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (memcmp(&rgb, &cached_rgb, sizeof(color)) != 0)
    {
        cached_rgb = rgb;
        gui_RGB_to_HLS(rgb, &cached_hls);
    }
    *hls = cached_hls;
}


/*****************************************************************************
* FUNCTION
*  gui_scrollbar_precache_color1
* DESCRIPTION
*  Pre-cache color because the HLS colorspace conversion is slow
* PARAMETERS
*  theme_color     [IN]        Is the domination color the scrollbar
*  width           [IN]        Scrollbar width
* RETURNS
*  void
*****************************************************************************/
static void gui_scrollbar_precache_color1_style_4(color theme_color, S32 width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_HLS_color hls;
    S32 i;
    S32 num_gradient_color = width - 2; /* two-pixel border each side */
#ifndef __MMI_WALLPAPER_ON_BOTTOM__
    S32 transparent_color_r, transparent_color_g, transparent_color_b, r, g, b;
    S32 opacity_value = ((U32)GUI_SCROLLBAR_ALPHA_STYLE4) * 255 / 100;
    S32 inverse_opacity_value = 256 - ((U32)GUI_SCROLLBAR_ALPHA_STYLE4) * 255 / 100;;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (num_gradient_color > GUI_SCROLLBAR_NUM_GRADIENT_COLOR_STYLE4)
    {
        num_gradient_color = GUI_SCROLLBAR_NUM_GRADIENT_COLOR_STYLE4;
    }
    if (num_gradient_color <= 1)
    {
        num_gradient_color = 2;
    }

    gui_scrollbar_RGB_to_HLS_style_4(theme_color, &hls);

    /* Recompute colors only if color hue is changed */
    if ((S32) hls.h != g_mmi_gui_scrollbar_cache_hue_style_4 || num_gradient_color != g_mmi_gui_scrollbar_cache_num_gcolor_style_4)
    {
        g_mmi_gui_scrollbar_cache_num_gcolor_style_4 = num_gradient_color;
        g_mmi_gui_scrollbar_cache_hue_style_4 = hls.h;

        for (i = 0; i < num_gradient_color; i++)
        {
            S32 l, s;

            s = i * (GUI_SCROLLBAR_MAX_GRADIENT_SATURATION_STYLE4 -
                GUI_SCROLLBAR_MIN_GRADIENT_SATURATION_STYLE4) / (num_gradient_color - 1);
            s = GUI_SCROLLBAR_MAX_GRADIENT_SATURATION_STYLE4 - s;
            l = i * (GUI_SCROLLBAR_MAX_GRADIENT_LIGHTNESS_STYLE4 -
                GUI_SCROLLBAR_MIN_GRADIENT_LIGHTNESS_STYLE4) / (num_gradient_color - 1);
            l = GUI_SCROLLBAR_MAX_GRADIENT_LIGHTNESS_STYLE4 - l;
            MMI_DBG_ASSERT(s >= 0 && s <= 255);
            MMI_DBG_ASSERT(l >= 0 && l <= 255);
            hls.s = (U8) s;
            hls.l = (U8) l;
            gui_HLS_to_RGB(hls, &g_mmi_gui_scrollbar_gradient_style_4[i]);
        }
#ifndef __MMI_WALLPAPER_ON_BOTTOM__
        if (current_MMI_theme->scrollbar_background_filler->flags & UI_FILLED_AREA_BORDER)
        {
            g_mmi_gui_scrollbar_border_color_style_4 = current_MMI_theme->scrollbar_background_filler->border_color;
        }
        else
        {
            g_mmi_gui_scrollbar_border_color_style_4 = current_MMI_theme->scrollbar_background_filler->c;
        }
        g_mmi_gui_scrollbar_bk_color_style_4 = current_MMI_theme->scrollbar_background_filler->c;

        transparent_color_r = (current_MMI_theme->lite_disp_scr_bg_color->r >> 3) * opacity_value;
        transparent_color_g = (current_MMI_theme->lite_disp_scr_bg_color->g >> 2) * opacity_value;
        transparent_color_b = (current_MMI_theme->lite_disp_scr_bg_color->b >> 3) * opacity_value;
        r = g_mmi_gui_scrollbar_border_color_style_4.r >> 3;
        g = g_mmi_gui_scrollbar_border_color_style_4.g >> 2;
        b = g_mmi_gui_scrollbar_border_color_style_4.b >> 3;
        g_mmi_gui_scrollbar_border_color_style_4.r = ((transparent_color_r) +  (r * inverse_opacity_value)) >> 8;
        g_mmi_gui_scrollbar_border_color_style_4.g = ((transparent_color_g) +  (g * inverse_opacity_value)) >> 8;
        g_mmi_gui_scrollbar_border_color_style_4.b = ((transparent_color_b) +  (b * inverse_opacity_value)) >> 8;

        r = g_mmi_gui_scrollbar_bk_color_style_4.r >> 3;
        g = g_mmi_gui_scrollbar_bk_color_style_4.g >> 2;
        b = g_mmi_gui_scrollbar_bk_color_style_4.b >> 3;
        g_mmi_gui_scrollbar_bk_color_style_4.r = ((transparent_color_r) +  (r * inverse_opacity_value)) >> 8;
        g_mmi_gui_scrollbar_bk_color_style_4.g = ((transparent_color_g) +  (g * inverse_opacity_value)) >> 8;
        g_mmi_gui_scrollbar_bk_color_style_4.b = ((transparent_color_b) +  (b * inverse_opacity_value)) >> 8;
#endif
    }

}


/*****************************************************************************
* FUNCTION
*  gui_scrollbar_draw_region
* DESCRIPTION
*
* PARAMETERS
*  type        [IN]
*  x           [IN]
*  y           [IN]
*  width       [IN]
*  height      [IN]
* RETURNS
*  void
*****************************************************************************/
static void gui_scrollbar_draw_region_style_4(gui_scrollbar_region_enum type, S32 x, S32 y, S32 width, S32 height, icon_button *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle old_src_layer, scr_layer, act_layer;
    color color, border_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_and_set_clip(x, y, x + width - 1, y + height - 1);
    }

#if defined(__MMI_WALLPAPER_ON_BOTTOM__)

    gdi_layer_get_active(&act_layer);

    old_src_layer = gui_get_transparent_source_layer();
    gdi_get_alpha_blending_source_layer(&scr_layer);

    if (scr_layer == GDI_ERROR_HANDLE ||  scr_layer == GDI_NULL_HANDLE)
    {
        scr_layer = act_layer;
    }

    gui_set_transparent_source_layer(scr_layer);

    if (current_MMI_theme->scrollbar_background_filler->flags & UI_FILLED_AREA_BORDER)
    {
    border_color = current_MMI_theme->scrollbar_background_filler->border_color;
    }
    else
    {
        border_color = current_MMI_theme->scrollbar_background_filler->c;
    }
    color = current_MMI_theme->scrollbar_background_filler->c;
    border_color.alpha = GUI_SCROLLBAR_ALPHA_STYLE4;
    color.alpha = GUI_SCROLLBAR_ALPHA_STYLE4;
    if (type == GUI_SCROLLBAR_REGION_VERTICAL)
    {
#if defined(__MMI_TOUCH_SCREEN__) && defined (__MMI_MAINLCD_128X160__)
    gui_fill_transparent_color(x, y, x + width - 1, y, border_color);
    gui_fill_transparent_color(x, y + height - 1, x + width, y + height - 1, border_color);
    gui_fill_transparent_color(x, y, x, y + height - 1, border_color);
    gui_fill_transparent_color(x + width - 1, y, x + width - 1, y + height, border_color);
    if(y != b->y)
    {
        gui_fill_transparent_color(
            x + 1,
            y + 1 ,
            x + width - 2,
            b->y,
            color);
    }
    if (y + height != b->y + b->height)
    {
        gui_fill_transparent_color(
            x + 1,
            b->y + b->height - 1 ,
            x + width - 2,
            y + height - 2,
            color);
    }

#elif defined(__MMI_TOUCH_SCREEN__)
    gui_fill_transparent_color(x + GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4, y, x + width - GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4, y, border_color);
    gui_fill_transparent_color(x + GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4, y + height - 1, x + width - GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4, y + height - 1, border_color);
    gui_fill_transparent_color(x + GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4, y, x + GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4, y + height - 1, border_color);
    gui_fill_transparent_color(x + width - GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4, y, x + width - GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4, y + height, border_color);
    if(y != b->y)
    {
        gui_fill_transparent_color(
            x + 1 + GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4,
            y + 1 ,
            x + width - 1 - GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4,
            b->y,
            color);
    }
    if (y + height != b->y + b->height)
    {
        gui_fill_transparent_color(
            x + 1 + GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4,
            b->y + b->height - 1 ,
            x + width - 1 - GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4,
            y + height - 2,
            color);
    }

#else
    gui_fill_transparent_color(x, y, x + width - GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP_STYLE4, y , border_color);
    gui_fill_transparent_color(x, y + height - 1, x + width - GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP_STYLE4 , y + height - 1, border_color);
    gui_fill_transparent_color(x, y, x , y + height - 1 , border_color);
    gui_fill_transparent_color(x + width - GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP_STYLE4, y, x + width - GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP_STYLE4, y + height - 1 , border_color);
    if(y != b->y)
    {
        gui_fill_transparent_color(
            x + 1,
            y + 1 ,
            x + width - 1 - GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP_STYLE4,
            b->y,
            color);
    }
    if (y + height != b->y + b->height)
    {
        gui_fill_transparent_color(
            x + 1,
            b->y + b->height - 1 ,
            x + width - 1 - GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP_STYLE4,
            y + height - 2,
            color);
    }
#endif
    }
    else
    {
#if defined(__MMI_TOUCH_SCREEN__) && defined (__MMI_MAINLCD_128X160__)
        gui_fill_transparent_color(x, y, x + width - 1, y, border_color);
        gui_fill_transparent_color(x, y + height - 1, x + width - 1, y + height - 1, border_color);
        gui_fill_transparent_color(x, y, x, y + height, border_color);
        gui_fill_transparent_color(x + width - 1, y, x + width - 1, y + height - 1, border_color);
        if(x != b->x)
        {
            gui_fill_transparent_color(
                x + 1,
                y + 1,
                b->x,
                y + height - 2,
                color);
        }
        if (x + width != b->x + b->width)
        {
            gui_fill_transparent_color(
                b->x + b->width - 1,
                y + 1,
                x + width - 2,
                y + height - 2,
                color);
        }
#elif defined(__MMI_TOUCH_SCREEN__)
        gui_fill_transparent_color(x, y + GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4, x + width - 1, y + GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4, border_color);
        gui_fill_transparent_color(x, y + height - GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4, x + width - 1, y + height - GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4, border_color);
        gui_fill_transparent_color(x, y + GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4, x, y + height - GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4, border_color);
        gui_fill_transparent_color(x + width - 1, y + GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4, x + width - 1, y + height - GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4, border_color);
        if(x != b->x)
        {
            gui_fill_transparent_color(
                x + 1,
                y + 1 + GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4,
                b->x,
                y + height - GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4 - 1,
                color);
        }
        if (x + width != b->x + b->width)
        {
            gui_fill_transparent_color(
                b->x + b->width - 1,
                y + 1 + GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4,
                x + width - 2,
                y + height - GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4 - 1,
                color);
        }
#else
        gui_fill_transparent_color(x, y, x + width - 1, y, border_color);
        gui_fill_transparent_color(x, y + height - GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP_STYLE4, x + width - 1 , y + height - GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP_STYLE4, border_color);
        gui_fill_transparent_color(x, y , x , y + height - GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP_STYLE4 , border_color);
        gui_fill_transparent_color(x + width - 1, y, x + width - 1, y + height - GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP_STYLE4 , border_color);
        if(x != b->x)
        {
            gui_fill_transparent_color(
                x + 1,
                y + 1,
                b->x,
                y + height - GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP_STYLE4 - 1,
                color);
        }
        if (x + width != b->x + b->width)
        {
            gui_fill_transparent_color(
                b->x + b->width - 1,
                y + 1,
                x + width - 2,
                y + height - GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP_STYLE4 - 1,
                color);
        }
#endif
    }
    gui_set_transparent_source_layer(old_src_layer);
#else /* __MMI_WALLPAPER_ON_BOTTOM__ */

    gui_draw_rectangle(x, y, x + width - 1, y + height - 1, g_mmi_gui_scrollbar_border_color_style_4);

    gui_fill_rectangle(x + 1, y + 1, x + width - 2, y + height - 2, g_mmi_gui_scrollbar_bk_color_style_4);
#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }
}

/*****************************************************************************
* FUNCTION
*  gui_scrollbar_adjust_luminance
* DESCRIPTION
*
* PARAMETERS
*  luminance       [IN/OUT]
*  diff            [IN]
* RETURNS
*  void
*****************************************************************************/
static void gui_scrollbar_adjust_luminance_style_4(U8 *luminance, S16 diff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 l = *luminance;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    l += diff;
    if (l > 255)
    {
        l = 255;
    }
    if (l < 0)
    {
        l = 0;
    }
    *luminance = (U8) l;
}

/*****************************************************************************
* FUNCTION
*  gui_scrollbar_draw_button_style2
* DESCRIPTION
*
* PARAMETERS
*  type        [IN]
*  b           [IN/OUT]
* RETURNS
*  void
*****************************************************************************/
static void gui_scrollbar_draw_button_style2_style_4(gui_scrollbar_buttton_enum type, icon_button *b)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_HLS_color hls;
    color c;
    S32 x, y, width, height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x = b->x;
    y = b->y;
    width = b->width;
    height = b->height;
    c = b->normal_up_filler->c;

    /* Scroll button does not support highlight in UI_SCROLLBAR_STYLE_2 */
    if (type != GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL && type != GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL)
    {
        if (b->flags & UI_BUTTON_SHIFT_BUTTON1)
        {
            y++;
            gui_RGB_to_HLS(c, &hls);
            hls.l = (U8) ((U16) hls.l * 3 / 4);
            hls.s = (U8) ((U16) hls.s * 5 / 6);
            gui_HLS_to_RGB(hls, &c);
        }
        else if (b->flags & UI_BUTTON_SHIFT_BUTTON2)
        {
            y += 2;
            gui_RGB_to_HLS(c, &hls);
            hls.l = (U8) ((U16) hls.l * 3 / 4);
            hls.s = (U8) ((U16) hls.s * 5 / 6);
            gui_HLS_to_RGB(hls, &c);
        }
    }

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_and_set_clip(x, y, x + width - 1, y + height - 1);
    }

    /* shift the position to leave one-pixel space */
    if (type == GUI_SCROLLBAR_BUTTON_LEFT || type == GUI_SCROLLBAR_BUTTON_RIGHT)
    {
        x++;
    }
    if (type == GUI_SCROLLBAR_BUTTON_UP || type == GUI_SCROLLBAR_BUTTON_DOWN)
    {
        y++;
    }

    switch (type)
    {
    case GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL:
        /* FALLTHROUGH no break */
    case GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL:
        {
            S32 i;
            S32 num_shadow_line;
            color cs[3];    /* shadow color */
            color cf;       /* fill color */

            gui_RGB_to_HLS(c, &hls);

            if (height < 5 || width < 5)
            {
                /* No room to display the bar in special style */
                gui_show_icon_button(b);
            }
            else
            {
                if ((type == GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL && width >= 9) ||
                    (type == GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL && height >= 9))
                {
                    gui_scrollbar_adjust_luminance_style_4(&hls.l, 10);
                    gui_HLS_to_RGB(hls, &cs[0]);
                    gui_scrollbar_adjust_luminance_style_4(&hls.l, 10);
                    gui_HLS_to_RGB(hls, &cs[1]);
                    gui_scrollbar_adjust_luminance_style_4(&hls.l, 10);
                    gui_HLS_to_RGB(hls, &cs[2]);
                    gui_scrollbar_adjust_luminance_style_4(&hls.l, 10);
                    gui_HLS_to_RGB(hls, &cf);
                    num_shadow_line = 3;
                }
                else
                {
                    gui_scrollbar_adjust_luminance_style_4(&hls.l, 10);
                    gui_HLS_to_RGB(hls, &cs[0]);
                    gui_scrollbar_adjust_luminance_style_4(&hls.l, 10);
                    gui_HLS_to_RGB(hls, &cs[1]);
                    gui_scrollbar_adjust_luminance_style_4(&hls.l, 20);
                    gui_HLS_to_RGB(hls, &cf);
                    num_shadow_line = 2;
                }

                if (type == GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL)
                {
                    S32 x2, y2;

                    if (!(width % 2))
                    {
                        width--;
                    }
                    if (height >= 8)
                    {
                        /* Leave 1-pixel space */
                        y++;
                        height -= 2;
                    }

                    x2 = x + width - 1;
                    y2 = y + height - 1;

                    if (width <= 5)
                    {
                        gui_draw_vertical_line(y + 1, y2 - 1, x, c);
                        gui_draw_vertical_line(y + 1, y2 - 1, x2, c);
                        gui_draw_horizontal_line(x + 1, x2 - 1, y, c);
                        gui_draw_horizontal_line(x + 1, x2 - 1, y2, c);
                        for (i = x + 1; i < x2 - num_shadow_line; i++)
                        {
                            gui_draw_vertical_line(y + 1, y2 - 1, i, cf);
                        }

                        for (i = 0; i < num_shadow_line; i++)
                        {
                            gui_draw_vertical_line(y + 1, y2 - 1, x2 - 1 - i, cs[i]);
                        }
                    }
                    else
                    {
                        gui_draw_vertical_line(y + 2, y2 - 2, x, c);
                        gui_draw_vertical_line(y + 2, y2 - 2, x2, c);
                        gui_draw_horizontal_line(x + 2, x2 - 2, y, c);
                        gui_draw_horizontal_line(x + 2, x2 - 2, y2, c);

                        for (i = x + 1; i < x2 - num_shadow_line; i++)
                        {
                            gui_draw_vertical_line(y + 1, y2 - 1, i, cf);
                        }

                        for (i = 0; i < num_shadow_line; i++)
                        {
                            gui_draw_vertical_line(y + 1, y2 - 1, x2 - 1 - i, cs[i]);
                        }

                        gui_putpixel(x + 1, y + 1, c);
                        gui_putpixel(x2 - 1, y + 1, c);
                        gui_putpixel(x + 1, y2 - 1, c);
                        gui_putpixel(x2 - 1, y2 - 1, c);
                    }
                }
                else
                {
                    S32 x2, y2;

                    if (!(height % 2))
                    {
                        height--;
                    }
                    if (width >= 8)
                    {
                        /* Leave 1-pixel space */
                        x++;
                        width -= 2;
                    }

                    x2 = x + width - 1;
                    y2 = y + height - 1;

                    if (width <= 5)
                    {
                        gui_draw_horizontal_line(x + 1, x2 - 1, y, c);
                        gui_draw_horizontal_line(x + 1, x2 - 1, y2, c);
                        gui_draw_vertical_line(y + 1, y2 - 1, x, c);
                        gui_draw_vertical_line(y + 1, y2 - 1, x2, c);
                        for (i = y + 1; i < y2 - num_shadow_line; i++)
                        {
                            gui_draw_horizontal_line(x + 1, x2 - 1, i, cf);
                        }

                        for (i = 0; i < num_shadow_line; i++)
                        {
                            gui_draw_horizontal_line(x + 1, x2 - 1, y2 - 1 - i, cs[i]);
                        }
                    }
                    else
                    {
                        gui_draw_horizontal_line(x + 2, x2 - 2, y, c);
                        gui_draw_horizontal_line(x + 2, x2 - 2, y2, c);
                        gui_draw_vertical_line(y + 2, y2 - 2, x, c);
                        gui_draw_vertical_line(y + 2, y2 - 2, x2, c);

                        for (i = y + 1; i < y2 - num_shadow_line; i++)
                        {
                            gui_draw_horizontal_line(x + 1, x2 - 1, i, cf);
                        }

                        for (i = 0; i < num_shadow_line; i++)
                        {
                            gui_draw_horizontal_line(x + 1, x2 - 1, y2 - 1 - i, cs[i]);
                        }

                        gui_putpixel(x + 1, y + 1, c);
                        gui_putpixel(x2 - 1, y + 1, c);
                        gui_putpixel(x + 1, y2 - 1, c);
                        gui_putpixel(x2 - 1, y2 - 1, c);
                    }
                }
            }
        }
        break;
    }

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }

#endif /*__MMI_SUBLCD__*/
}


/*****************************************************************************
* FUNCTION
*  gui_scrollbar_draw_button
* DESCRIPTION
*
* PARAMETERS
*  type        [IN]
*  b           [IN/OUT]
* RETURNS
*  void
*****************************************************************************/
static void gui_scrollbar_draw_button_style_4(gui_scrollbar_buttton_enum type, icon_button *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c, border_color, color;
    S32 x, y, width, height;
    BOOL is_button_pressed = MMI_FALSE;
#if defined (__MMI_WALLPAPER_ON_BOTTOM__)
    gdi_handle old_src_layer, scr_layer, act_layer;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c = current_MMI_theme->scrollbar_indicator_filler->c;
    x = b->x;
    y = b->y;
    width = b->width;
    height = b->height;

    if (width == 0 || height == 0)
    {
        return;
    }

    if ((b->flags & UI_BUTTON_SHIFT_BUTTON1) || (b->flags & UI_BUTTON_SHIFT_BUTTON2))
    {
        is_button_pressed = MMI_TRUE;
    }

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_and_set_clip(x, y, x + width - 1, y + height - 1);
    }

    /* shift the position to keep one-pixel space */
    if (type == GUI_SCROLLBAR_BUTTON_LEFT || type == GUI_SCROLLBAR_BUTTON_RIGHT)
    {
        x++;
    }
    if (type == GUI_SCROLLBAR_BUTTON_UP || type == GUI_SCROLLBAR_BUTTON_DOWN)
    {
        y++;
    }

    switch (type)
    {
    case GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL:
        /* FALLTHROUGH no break */
    case GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL:
        {
            S32 x2, y2;
#ifdef __MMI_MAINLCD_128X64__
			gui_fill_rectangle(x, y, x + width - 1, y + height - 1, c);
#else

            gui_scrollbar_precache_color1_style_4(c, width);
            if (type == GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL)
            {
                /* 1 pixel spacing in the top and bottom side */
                x2 = x + width - GUI_SCROLLBAR_STYLE4_GAP_STYLE4;

#if defined(__MMI_TOUCH_SCREEN__) && defined (__MMI_MAINLCD_128X160__)
                y2 = y + height - 1;
#elif defined(__MMI_TOUCH_SCREEN__)
                y = y + GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4;
                y2 = y + height - GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4 * 2;
#else
                y = y;
                y2 = y + height - GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP_STYLE4 ;
#endif
                x++;
                height--;
            }
            else
            {
                /* 1 pixel spacing in the left and right side */
            y2 = y + height - GUI_SCROLLBAR_STYLE4_GAP_STYLE4;

#if defined(__MMI_TOUCH_SCREEN__) && defined (__MMI_MAINLCD_128X160__)
            x2 = x + width - 1;
#elif defined(__MMI_TOUCH_SCREEN__)
            x = x + GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4;
            x2 = x + width - GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4 * 2;
#else
            x = x;
            x2 = x + width - GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP_STYLE4;
#endif
                width--;
                x++;
            }

            if (b->flags & UI_BUTTON_DISABLE_DRAG)
            {
                gui_fill_rectangle(x, y + 1, x2 - 1, y2 - 1, gui_color(159,159,159));
            }
            else
            {
            gui_fill_rectangle(x, y + 1, x2 - 1, y2 - 1, c);
            gui_draw_horizontal_line(x + 2, x2 -3, y2 - 3 , g_mmi_gui_scrollbar_gradient_style_4[0]);
            gui_draw_vertical_line(y + 3, y2 - 3, x2 - 3, g_mmi_gui_scrollbar_gradient_style_4[0]);
            gui_draw_horizontal_line(x + 1, x2 -2, y2 - 2 , g_mmi_gui_scrollbar_gradient_style_4[1]);
            gui_draw_vertical_line(y + 2, y2 - 2, x2 - 2, g_mmi_gui_scrollbar_gradient_style_4[1]);
            gui_draw_horizontal_line(x, x2 - 1, y2 - 1 , g_mmi_gui_scrollbar_gradient_style_4[2]);
            gui_draw_vertical_line(y + 1, y2 - 1, x2 - 1, g_mmi_gui_scrollbar_gradient_style_4[2]);
            }
#endif

            break;
        }

    case GUI_SCROLLBAR_BUTTON_UP:
    case GUI_SCROLLBAR_BUTTON_LEFT:
    case GUI_SCROLLBAR_BUTTON_DOWN:
    case GUI_SCROLLBAR_BUTTON_RIGHT:
        {
#if defined(__MMI_TOUCH_SCREEN__)

            S32 x2 = 0, y2 = 0;
#if defined (__MMI_WALLPAPER_ON_BOTTOM__)

            gdi_layer_get_active(&act_layer);

            old_src_layer = gui_get_transparent_source_layer();
            gdi_get_alpha_blending_source_layer(&scr_layer);

            if (scr_layer == GDI_ERROR_HANDLE ||  scr_layer == GDI_NULL_HANDLE)
            {
                scr_layer = act_layer;
            }

                gui_set_transparent_source_layer(scr_layer);
#endif

            if (type == GUI_SCROLLBAR_BUTTON_LEFT || type == GUI_SCROLLBAR_BUTTON_RIGHT)
            {
#if defined(__MMI_TOUCH_SCREEN__) && defined (__MMI_MAINLCD_128X160__)
                y2 = y + height - 1;
#else
                y = y + GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4;
                y2 = y + height - GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4 * 2;
#endif

#if defined (__MMI_WALLPAPER_ON_BOTTOM__)
                if (current_MMI_theme->scrollbar_background_filler->flags & UI_FILLED_AREA_BORDER)
                {
                border_color = current_MMI_theme->scrollbar_background_filler->border_color;
                }
                else
                {
                    border_color = current_MMI_theme->scrollbar_background_filler->c;
                }
                color = current_MMI_theme->scrollbar_background_filler->c;
                border_color.alpha = GUI_SCROLLBAR_ALPHA_STYLE4;
                color.alpha = GUI_SCROLLBAR_ALPHA_STYLE4;
                gui_fill_transparent_color(x, y, x, y2, border_color);
                gui_fill_transparent_color(x + y2 - y, y, x + y2 - y, y2, border_color);
                gui_fill_transparent_color(x, y, x + y2 - y, y, border_color);
                gui_fill_transparent_color(x, y2, x + y2 - y, y2, border_color);
                gui_fill_transparent_color(x + 1, y + 1, x + y2 - y - 1, y2 - 1, color);
                gui_set_transparent_source_layer(old_src_layer);

#else /* __MMI_WALLPAPER_ON_BOTTOM__ */
                gui_draw_rectangle(x, y, x + width - 1, y + height - 1, g_mmi_gui_scrollbar_border_color_style_4);

                gui_fill_rectangle(x + 1, y + 1, x + width - 2, y + height - 2, g_mmi_gui_scrollbar_bk_color_style_4);
#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */
            }
            if (type == GUI_SCROLLBAR_BUTTON_UP || type == GUI_SCROLLBAR_BUTTON_DOWN)
            {
#if defined(__MMI_TOUCH_SCREEN__) && defined (__MMI_MAINLCD_128X160__)
                x2 = x + width - 1;
#else
            x = x + GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4;
            x2 = x + width - GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4 * 2;
#endif

#if defined (__MMI_WALLPAPER_ON_BOTTOM__)
            if (current_MMI_theme->scrollbar_background_filler->flags & UI_FILLED_AREA_BORDER)
            {
            border_color = current_MMI_theme->scrollbar_background_filler->border_color;
            }
            else
            {
                border_color = current_MMI_theme->scrollbar_background_filler->c;
            }
            color = current_MMI_theme->scrollbar_background_filler->c;
            border_color.alpha = GUI_SCROLLBAR_ALPHA_STYLE4;
            color.alpha = GUI_SCROLLBAR_ALPHA_STYLE4;
            gui_fill_transparent_color(x, y, x, y + x2- x, border_color);
            gui_fill_transparent_color(x2, y, x2, y + x2- x, border_color);
            gui_fill_transparent_color(x, y, x2, y, border_color);
            gui_fill_transparent_color(x, y + x2- x, x2, y + x2- x, border_color);
            gui_fill_transparent_color(x + 1, y + 1, x2 - 1, y + x2- x - 1, color);
            gui_set_transparent_source_layer(old_src_layer);

#else /* __MMI_WALLPAPER_ON_BOTTOM__ */
            gui_draw_rectangle(x, y, x + width - 1, y + height - 1, g_mmi_gui_scrollbar_border_color_style_4);

            gui_fill_rectangle(x + 1, y + 1, x + width - 2, y + height - 2, g_mmi_gui_scrollbar_bk_color_style_4);
#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */
            }


            if (is_button_pressed)
            {
                if (type == GUI_SCROLLBAR_BUTTON_UP || type == GUI_SCROLLBAR_BUTTON_DOWN)
                {
                    y++;
                }
                else if (type == GUI_SCROLLBAR_BUTTON_LEFT || type == GUI_SCROLLBAR_BUTTON_RIGHT)
                {
                    x++;
                }
            }

            if (type == GUI_SCROLLBAR_BUTTON_UP)
            {
                S32 arrow_width = x2 - x + 1 - (GUI_SCROLLBAR_STYLE4_GAP_STYLE4 << 1);
                S32 arrow_height;
                S32 x1, y1, i;

                arrow_width -= (arrow_width % 2);
                arrow_height = arrow_width >> 1;

                x1 = (x2 - x + 1 - arrow_width);
                if (x1 > 0)
                {
                    x1 >>= 1;
                }
                else
                {
                    x1 = 0;
                }
                x1 += x + 1;

                y1 = (height - arrow_height);
                if (y1 > 0)
                {
                    y1 >>= 1;
                }
                else
                {
                    y1 = 0;
                }
                y1 += y + arrow_height - 1 - 2; /* -1 for center */

                for (i = 0; i < arrow_height; i++)
                {
                    gui_putpixel(x1, y1, c);
                    gui_putpixel(x1, y1 + 2, c);
                    y1--;
                    x1++;
                }
                y1 += 2;
                for (i = 1; i < arrow_height; i++)
                {
                    gui_putpixel(x1, y1, c);
                    gui_putpixel(x1, y1 + 2, c);
                    y1++;
                    x1++;
                }
            }
            else if (type == GUI_SCROLLBAR_BUTTON_DOWN)
            {
                S32 arrow_width = x2 - x + 1 - (GUI_SCROLLBAR_STYLE4_GAP_STYLE4 << 1);
                S32 arrow_height;
                S32 x1, y1, i;

                arrow_width -= (arrow_width % 2);
                arrow_height = arrow_width >> 1;

                x1 = (x2 - x + 1 - arrow_width);
                if (x1 > 0)
                {
                    x1 >>= 1;
                }
                else
                {
                    x1 = 0;
                }
                x1 += x + 1;

                y1 = (height - arrow_height);
                if (y1 > 0)
                {
                    y1 >>= 1;
                }
                else
                {
                    y1 = 0;
                }
                y1 += y;

                for (i = 0; i < arrow_height; i++)
                {
                    gui_putpixel(x1, y1, c);
                    gui_putpixel(x1, y1 - 2, c);
                    y1++;
                    x1++;
                }
                y1 -= 2;
                for (i = 1; i < arrow_height; i++)
                {
                    gui_putpixel(x1, y1, c);
                    gui_putpixel(x1, y1 - 2, c);
                    y1--;
                    x1++;
                }
            }
            else if (type == GUI_SCROLLBAR_BUTTON_LEFT)
            {
                S32 arrow_height = height - (GUI_SCROLLBAR_ARROW_GAP_STYLE4 << 1);
                S32 arrow_width;
                S32 x1, y1, i;

                arrow_height -= (arrow_height % 2);
                arrow_width = arrow_height >> 1;

                y1 = (y2 - y + 1 - arrow_height);
                if (y1 > 0)
                {
                    y1 >>= 1;
                }
                else
                {
                    y1 = 0;
                }
                y1 += y + 1;

                x1 = (width - arrow_width);
                if (x1 > 0)
                {
                    x1 >>= 1;
                }
                else
                {
                    x1 = 0;
                }
                x1 += x + arrow_width - 3;  /* -1 for center */

                for (i = 0; i < arrow_width; i++)
                {
                    gui_putpixel(x1, y1, c);
                    gui_putpixel(x1 + 2, y1, c);
                    y1++;
                    x1--;
                }
                x1 += 2;
                for (i = 1; i < arrow_width; i++)
                {
                    gui_putpixel(x1, y1, c);
                    gui_putpixel(x1 + 2, y1, c);
                    y1++;
                    x1++;
                }
            }
            else
            {
                S32 arrow_height = height - (GUI_SCROLLBAR_ARROW_GAP_STYLE4 << 1);
                S32 arrow_width;
                S32 x1, y1, i;

                arrow_height -= (arrow_height % 2);
                arrow_width = arrow_height >> 1;

                y1 = (y2 - y + 1 - arrow_height);
                if (y1 > 0)
                {
                    y1 >>= 1;
                }
                else
                {
                    y1 = 0;
                }
                y1 += y + 1;

                x1 = (width - arrow_width);
                if (x1 > 0)
                {
                    x1 >>= 1;
                }
                else
                {
                    x1 = 0;
                }
                x1 += x - 1;

                for (i = 0; i < arrow_width; i++)
                {
                    gui_putpixel(x1, y1, c);
                    gui_putpixel(x1 + 2, y1, c);
                    y1++;
                    x1++;
                }
                x1 -= 2;
                for (i = 1; i < arrow_width; i++)
                {
                    gui_putpixel(x1, y1, c);
                    gui_putpixel(x1 + 2, y1, c);
                    y1++;
                    x1--;
                }
            }
#endif /*#if defined(__MMI_TOUCH_SCREEN__)*/
            break;
        }

        default:
            MMI_DBG_ASSERT(0);
    }

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }

}


/*****************************************************************************
* FUNCTION
*  gui_scrollbar_get_button_min_size
* DESCRIPTION
*
* PARAMETERS
*  type            [IN]
*  bar_width       [IN]
* RETURNS
*
*****************************************************************************/
S32 gui_scrollbar_get_button_min_size_style_4(gui_scrollbar_buttton_enum type, S32 bar_width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
    case GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL:
        /* FALLTHROUGH no break */
    case GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL:
        ret = GUI_SCROLLBAR_MIN_HEIGHT_SCROLL_BUTTON_STYLE4;
        break;

    case GUI_SCROLLBAR_BUTTON_UP:
        /* FALLTHROUGH no break */
    case GUI_SCROLLBAR_BUTTON_DOWN:
    case GUI_SCROLLBAR_BUTTON_LEFT:
    case GUI_SCROLLBAR_BUTTON_RIGHT:

    #if defined(__MMI_TOUCH_SCREEN__) && defined (__MMI_MAINLCD_128X160__)
        ret = current_MMI_theme->scrollbar_size;
    #else
        ret = current_MMI_theme->scrollbar_size - GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4 * 2 + 1;
    #endif

        break;

    default:
        MMI_ASSERT(0);
    }

    return ret;
}


#endif

#if defined(UI_SCROLLBAR_STYLE_3) || defined(UI_SCROLLBAR_WIDER_STYLE_3)
/* Use image to draw the scrollbar. */

/* Width of scrollbar */
static S32 g_mmi_gui_scrollbar_width_style_3 = 0;

/* Height of up/down button, or width of left/right button */
static S32 g_mmi_gui_scrollbar_button_size_style_3;

/* The scrollbar background is composed by three different images. */
static S32 g_mmi_gui_scrollbar_bar_size1_style_3;
static S32 g_mmi_gui_scrollbar_bar_size2_style_3;
static S32 g_mmi_gui_scrollbar_bar_size3_style_3;

/* color of the arrow */
static S32 g_mmi_gui_scrollbar_arrow_cache_hue_style_3 = -1;
static color g_mmi_gui_scrollbar_arrow_color_style_3;

/* color of the moveable part (scroll button) */
static S32 g_mmi_gui_scrollbar_cache_hue_style_3 = -1;
static S32 g_mmi_gui_scrollbar_cache_num_gcolor_style_3 = 0;

static color g_mmi_gui_scrollbar_border_color_style_3;
static color g_mmi_gui_scrollbar_dark_color_style_3;
static color g_mmi_gui_scrollbar_medium_color_style_3;
static color g_mmi_gui_scrollbar_light_color_style_3;
static color g_mmi_gui_scrollbar_gradient_style_3[GUI_SCROLLBAR_NUM_GRADIENT_COLOR_STYLE3];

/*
 * RGB <-> HLS color space conversion with cache to avoid floating point arithmetics
 */


/*****************************************************************************
 * FUNCTION
 *  gui_scrollbar_RGB_to_HLS
 * DESCRIPTION
 *
 * PARAMETERS
 *  rgb     [IN]
 *  hls     [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_scrollbar_RGB_to_HLS_style_3(color rgb, UI_HLS_color *hls)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static color cached_rgb = {0, 0, 0, 0};
    static UI_HLS_color cached_hls = {0, 0, 0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (memcmp(&rgb, &cached_rgb, sizeof(color)) != 0)
    {
        cached_rgb = rgb;
        gui_RGB_to_HLS(rgb, &cached_hls);
    }
    *hls = cached_hls;
}


/*****************************************************************************
 * FUNCTION
 *  gui_scrollbar_precache_image_size
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_scrollbar_precache_image_size_style_3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_mmi_gui_scrollbar_width_style_3)
    {
        S32 iw, ih;

        gui_measure_image((PU8) GetImage(IMG_SCROLLBAR_BUTTON_UP), &iw, &ih);
        g_mmi_gui_scrollbar_width_style_3 = iw;
        g_mmi_gui_scrollbar_button_size_style_3 = ih;

        gui_measure_image((PU8) GetImage(IMG_SCROLLBAR_V_BAR_TOP), &iw, &ih);
        g_mmi_gui_scrollbar_bar_size1_style_3 = ih;

        gui_measure_image((PU8) GetImage(IMG_SCROLLBAR_V_BAR_MIDDLE), &iw, &ih);
        g_mmi_gui_scrollbar_bar_size2_style_3 = ih;

        gui_measure_image((PU8) GetImage(IMG_SCROLLBAR_V_BAR_BOTTOM), &iw, &ih);
        g_mmi_gui_scrollbar_bar_size3_style_3 = ih;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_scrollbar_precache_color1
 * DESCRIPTION
 *  Pre-cache color because the HLS colorspace conversion is slow
 * PARAMETERS
 *  theme_color     [IN]        Is the domination color the scrollbar
 *  width           [IN]        Scrollbar width
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_scrollbar_precache_color1_style_3(color theme_color, S32 width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_HLS_color hls;
    S32 i;
    S32 num_gradient_color = width - 4; /* two-pixel border each side */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (num_gradient_color > GUI_SCROLLBAR_NUM_GRADIENT_COLOR_STYLE3)
    {
        num_gradient_color = GUI_SCROLLBAR_NUM_GRADIENT_COLOR_STYLE3;
    }
    if (num_gradient_color <= 1)
    {
        num_gradient_color = 2;
    }

    gui_scrollbar_RGB_to_HLS_style_3(theme_color, &hls);

    /* Recompute colors only if color hue is changed */
    if ((S32) hls.h != g_mmi_gui_scrollbar_cache_hue_style_3 || num_gradient_color != g_mmi_gui_scrollbar_cache_num_gcolor_style_3)
    {
        g_mmi_gui_scrollbar_cache_num_gcolor_style_3 = num_gradient_color;
        g_mmi_gui_scrollbar_cache_hue_style_3 = hls.h;

        hls.s = GUI_SCROLLBAR_BORDER_SATURATION_STYLE3;
        hls.l = GUI_SCROLLBAR_BORDER_LIGHTNESS_STYLE3;
        gui_HLS_to_RGB(hls, &g_mmi_gui_scrollbar_border_color_style_3);

        hls.s = GUI_SCROLLBAR_DARK_SATURATION_STYLE3;
        hls.l = GUI_SCROLLBAR_DARK_LIGHTNESS_STYLE3;
        gui_HLS_to_RGB(hls, &g_mmi_gui_scrollbar_dark_color_style_3);

        hls.s = GUI_SCROLLBAR_MEDIUM_SATURATION_STYLE3;
        hls.l = GUI_SCROLLBAR_MEDIUM_LIGHTNESS_STYLE3;
        gui_HLS_to_RGB(hls, &g_mmi_gui_scrollbar_medium_color_style_3);

        hls.s = GUI_SCROLLBAR_LIGHT_SATURATION_STYLE3;
        hls.l = GUI_SCROLLBAR_LIGHT_LIGHTNESS_STYLE3;
        gui_HLS_to_RGB(hls, &g_mmi_gui_scrollbar_light_color_style_3);

        for (i = 0; i < num_gradient_color; i++)
        {
            S32 s, l;

            s = i * (GUI_SCROLLBAR_MAX_GRADIENT_SATURATION_STYLE3 -
                     GUI_SCROLLBAR_MIN_GRADIENT_SATURATION_STYLE3) / (num_gradient_color - 1);
            s = GUI_SCROLLBAR_MAX_GRADIENT_SATURATION_STYLE3 - s;
            l = i * (GUI_SCROLLBAR_MAX_GRADIENT_LIGHTNESS_STYLE3 -
                     GUI_SCROLLBAR_MIN_GRADIENT_LIGHTNESS_STYLE3) / (num_gradient_color - 1);
            l = GUI_SCROLLBAR_MAX_GRADIENT_LIGHTNESS_STYLE3 - l;
            MMI_DBG_ASSERT(s >= 0 && s <= 255);
            MMI_DBG_ASSERT(l >= 0 && l <= 255);
            hls.s = (U8) s;
            hls.l = (U8) l;
            gui_HLS_to_RGB(hls, &g_mmi_gui_scrollbar_gradient_style_3[i]);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_scrollbar_precache_color2
 * DESCRIPTION
 *  Pre-cache color because the HLS colorspace conversion is slow
 * PARAMETERS
 *  theme_color     [IN]        Is the domination color the scrollbar
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_scrollbar_precache_color2_style_3(color theme_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_HLS_color hls;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_scrollbar_RGB_to_HLS_style_3(theme_color, &hls);

    /* Recompute colors only if color hue is changed */
    if ((S32) hls.h != g_mmi_gui_scrollbar_arrow_cache_hue_style_3)
    {
        g_mmi_gui_scrollbar_arrow_cache_hue_style_3 = (S32) hls.h;

        hls.s = GUI_SCROLLBAR_ARROW_SATURATION_STYLE3;
        hls.l = GUI_SCROLLBAR_ARROW_LIGHTNESS_STYLE3;
        gui_HLS_to_RGB(hls, &g_mmi_gui_scrollbar_arrow_color_style_3);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_scrollbar_get_minimum_size
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
S32 gui_scrollbar_get_minimum_size_style_3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 min;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_scrollbar_precache_image_size_style_3();
    min = g_mmi_gui_scrollbar_bar_size1_style_3 + g_mmi_gui_scrollbar_bar_size3_style_3;

    if (min < GUI_SCROLLBAR_MIN_HEIGHT_SCROLL_BUTTON_STYLE3)
    {
        min = GUI_SCROLLBAR_MIN_HEIGHT_SCROLL_BUTTON_STYLE3;
    }

    return min + ((g_mmi_gui_scrollbar_button_size_style_3 + 2 /* 1+ 1 pixel spacing */ ) << 1);
}


/*****************************************************************************
 * FUNCTION
 *  gui_scrollbar_get_button_min_size
 * DESCRIPTION
 *
 * PARAMETERS
 *  type            [IN]
 *  bar_width       [IN]
 * RETURNS
 *
 *****************************************************************************/
S32 gui_scrollbar_get_button_min_size_style_3(gui_scrollbar_buttton_enum type, S32 bar_width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_scrollbar_precache_image_size_style_3();

    MMI_DBG_ASSERT(g_mmi_gui_scrollbar_width_style_3 == bar_width);

    switch (type)
    {
        case GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL:
            /* FALLTHROUGH no break */
        case GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL:
            ret = GUI_SCROLLBAR_MIN_HEIGHT_SCROLL_BUTTON_STYLE3;
            break;

        case GUI_SCROLLBAR_BUTTON_UP:
            /* FALLTHROUGH no break */
        case GUI_SCROLLBAR_BUTTON_DOWN:
            /* FALLTHROUGH no break */
        case GUI_SCROLLBAR_BUTTON_LEFT:
            /* FALLTHROUGH no break */
        case GUI_SCROLLBAR_BUTTON_RIGHT:
            ret = g_mmi_gui_scrollbar_button_size_style_3 + 2 /* 1 + 1 pixel spacing */ ;
            break;

        default:
            MMI_ASSERT(0);
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gui_scrollbar_draw_region
 * DESCRIPTION
 *
 * PARAMETERS
 *  type        [IN]
 *  x           [IN]
 *  y           [IN]
 *  width       [IN]
 *  height      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_scrollbar_draw_region_style_3(gui_scrollbar_region_enum type, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_and_set_clip(x, y, x + width - 1, y + height - 1);
    }

    if (type == GUI_SCROLLBAR_REGION_VERTICAL)
    {
        if (height <= g_mmi_gui_scrollbar_bar_size1_style_3 + g_mmi_gui_scrollbar_bar_size3_style_3)
        {
            if (gui_scrollbar_redraw_clip_enable)
            {
                gui_set_clip(x, y, x + width - 1, y + (height >> 1) - 1);
            }
            gui_show_image(x, y, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_TOP));
            if (gui_scrollbar_redraw_clip_enable)
            {
                gui_set_clip(x, y + (height >> 1), x + width - 1, y + height - 1);
            }
            gui_show_image(x, y + height - g_mmi_gui_scrollbar_bar_size3_style_3, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_BOTTOM));
        }
        else
        {
            S32 y1, y2, remain;

            y1 = y + g_mmi_gui_scrollbar_bar_size1_style_3;
            y2 = y + height - g_mmi_gui_scrollbar_bar_size3_style_3 - 1;
            gui_show_image(x, y, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_TOP));
            gui_show_image(x, y2 + 1, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_BOTTOM));
            if (gui_scrollbar_redraw_clip_enable)
            {
                gui_set_clip(x, y1, x + width - 1, y2);
            }
            remain = y2 - y1 + 1;
            while (remain > 0)
            {
                gui_show_image(x, y1, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_MIDDLE));
                y1 += g_mmi_gui_scrollbar_bar_size2_style_3;
                remain -= g_mmi_gui_scrollbar_bar_size2_style_3;
            }
        }
    }
    else
    {
        if (width <= g_mmi_gui_scrollbar_bar_size1_style_3 + g_mmi_gui_scrollbar_bar_size3_style_3)
        {
            if (gui_scrollbar_redraw_clip_enable)
            {
                gui_set_clip(x, y, x + (width >> 1) - 1, y + height - 1);
            }
            gui_show_image(x, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_LEFT));
            if (gui_scrollbar_redraw_clip_enable)
            {
                gui_set_clip(x + (width >> 1), y, x + width - 1, y + height - 1);
            }
            gui_show_image(x + width - g_mmi_gui_scrollbar_bar_size3_style_3, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_RIGHT));
        }
        else
        {
            S32 x1, x2, remain;

            x1 = x + g_mmi_gui_scrollbar_bar_size1_style_3;
            x2 = x + width - g_mmi_gui_scrollbar_bar_size3_style_3 - 1;
            gui_show_image(x, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_LEFT));
            gui_show_image(x2 + 1, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_RIGHT));
            if (gui_scrollbar_redraw_clip_enable)
            {
                gui_set_clip(x, y, x2, y + height - 1);
            }
            remain = x2 - x1 + 1;
            while (remain > 0)
            {
                gui_show_image(x1, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_MIDDLE));
                x1 += g_mmi_gui_scrollbar_bar_size2_style_3;
                remain -= g_mmi_gui_scrollbar_bar_size2_style_3;
            }
        }
    }

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_scrollbar_draw_button
 * DESCRIPTION
 *
 * PARAMETERS
 *  type        [IN]
 *  b           [IN/OUT]
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_scrollbar_draw_button_style_3(gui_scrollbar_buttton_enum type, icon_button *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c;
    S32 x, y, width, height;
    BOOL is_button_pressed = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_scrollbar_precache_image_size_style_3();

    c = b->normal_up_filler->c;
    x = b->x;
    y = b->y;
    width = b->width;
    height = b->height;

    if (width == 0 || height == 0)
    {
        return;
    }

    if ((b->flags & UI_BUTTON_SHIFT_BUTTON1) || (b->flags & UI_BUTTON_SHIFT_BUTTON2))
    {
        is_button_pressed = MMI_TRUE;
    }

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_and_set_clip(x, y, x + width - 1, y + height - 1);
    }

    /* shift the position to keep one-pixel space */
    if (type == GUI_SCROLLBAR_BUTTON_LEFT || type == GUI_SCROLLBAR_BUTTON_RIGHT)
    {
        x++;
    }
    if (type == GUI_SCROLLBAR_BUTTON_UP || type == GUI_SCROLLBAR_BUTTON_DOWN)
    {
        y++;
    }

    switch (type)
    {
        case GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL:
            /* FALLTHROUGH no break */
        case GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL:
        {
            S32 x2, y2, i, cnt;

            gui_scrollbar_precache_color1_style_3(c, width);

            if (type == GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL)
            {
                /* 1 pixel spacing in the top and bottom side */
                height--;
                y++;
            }
            else
            {
                /* 1 pixel spacing in the left and right side */
                width--;
                x++;
            }

            x2 = x + width - 1;
            y2 = y + height - 1;

            /* External border */
            gui_draw_horizontal_line(x + 2, x2 - 2, y, g_mmi_gui_scrollbar_border_color_style_3);
            gui_draw_horizontal_line(x + 2, x2 - 2, y2, g_mmi_gui_scrollbar_border_color_style_3);
            gui_draw_vertical_line(y + 2, y2 - 2, x, g_mmi_gui_scrollbar_border_color_style_3);
            gui_draw_vertical_line(y + 2, y2 - 2, x2, g_mmi_gui_scrollbar_border_color_style_3);
            gui_putpixel(x + 1, y + 1, g_mmi_gui_scrollbar_border_color_style_3);
            gui_putpixel(x + 1, y2 - 1, g_mmi_gui_scrollbar_border_color_style_3);
            gui_putpixel(x2 - 1, y + 1, g_mmi_gui_scrollbar_border_color_style_3);
            gui_putpixel(x2 - 1, y2 - 1, g_mmi_gui_scrollbar_border_color_style_3);
            /* Light border */
            gui_draw_vertical_line(y + 2, y2 - 2, x + 1, g_mmi_gui_scrollbar_light_color_style_3);
            gui_draw_horizontal_line(x + 2, x2 - 2, y + 1, g_mmi_gui_scrollbar_light_color_style_3);

            /* Gradient color fill */
            if (type == GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL)
            {
                for (i = y + 2, cnt = 0; i <= y2 - 2; i++, cnt++)
                {
                    if (cnt >= GUI_SCROLLBAR_NUM_GRADIENT_COLOR_STYLE3)
                    {
                        cnt = GUI_SCROLLBAR_NUM_GRADIENT_COLOR_STYLE3 - 1;
                    }
                    gui_draw_horizontal_line(x + 2, x2 - 2, i, g_mmi_gui_scrollbar_gradient_style_3[cnt]);
                }

                /* Dark border */
                gui_draw_vertical_line(y + 2, y2 - 2, x2 - 1, g_mmi_gui_scrollbar_medium_color_style_3);
                gui_draw_horizontal_line(x + 2, x2 - 2, y2 - 1, g_mmi_gui_scrollbar_dark_color_style_3);
            }
            else
            {
                for (i = x + 2, cnt = 0; i <= x2 - 2; i++, cnt++)
                {
                    if (cnt >= GUI_SCROLLBAR_NUM_GRADIENT_COLOR_STYLE3)
                    {
                        cnt = GUI_SCROLLBAR_NUM_GRADIENT_COLOR_STYLE3 - 1;
                    }
                    gui_draw_vertical_line(y + 2, y2 - 2, i, g_mmi_gui_scrollbar_gradient_style_3[cnt]);
                }

                /* Dark border */
                gui_draw_vertical_line(y + 2, y2 - 2, x2 - 1, g_mmi_gui_scrollbar_dark_color_style_3);
                gui_draw_horizontal_line(x + 2, x2 - 2, y2 - 1, g_mmi_gui_scrollbar_medium_color_style_3);
            }

            /* Show a mark on the button */
            if (type == GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL)
            {
                S32 mark_y1, mark_y2, mark_x;

                mark_y1 = y + ((height - GUI_SCROLLBAR_MARK_WIDTH_STYLE3) >> 1);
                mark_y2 = mark_y1 + GUI_SCROLLBAR_MARK_WIDTH_STYLE3 - 1;

                if (width > GUI_SCROLLBAR_MIN_HEIGHT_WITH_MARK_3_STYLE3)
                {
                    mark_x = x + (width >> 1) - 2;
                    for (i = 0; i < 3; i++)
                    {
                        gui_draw_vertical_line(mark_y1, mark_y2, mark_x++, g_mmi_gui_scrollbar_light_color_style_3);
                        gui_draw_vertical_line(mark_y1 + 1, mark_y2 + 1, mark_x++, g_mmi_gui_scrollbar_dark_color_style_3);
                    }
                }
                else if (width > GUI_SCROLLBAR_MIN_HEIGHT_WITH_MARK_2_STYLE3)
                {
                    mark_x = x + (width >> 1) - 1;
                    for (i = 0; i < 2; i++)
                    {
                        gui_draw_vertical_line(mark_y1, mark_y2, mark_x++, g_mmi_gui_scrollbar_light_color_style_3);
                        gui_draw_vertical_line(mark_y1 + 1, mark_y2 + 1, mark_x++, g_mmi_gui_scrollbar_dark_color_style_3);
                    }
                }
            }
            else
            {
                S32 mark_x1, mark_x2, mark_y;

                mark_x1 = x + ((width - GUI_SCROLLBAR_MARK_WIDTH_STYLE3) >> 1);
                mark_x2 = mark_x1 + GUI_SCROLLBAR_MARK_WIDTH_STYLE3 - 1;

                if (height > GUI_SCROLLBAR_MIN_HEIGHT_WITH_MARK_3_STYLE3)
                {
                    mark_y = y + (height >> 1) - 2;
                    for (i = 0; i < 3; i++)
                    {
                        gui_draw_horizontal_line(mark_x1, mark_x2, mark_y++, g_mmi_gui_scrollbar_light_color_style_3);
                        gui_draw_horizontal_line(mark_x1 + 1, mark_x2 + 1, mark_y++, g_mmi_gui_scrollbar_dark_color_style_3);
                    }
                }
                else if (height > GUI_SCROLLBAR_MIN_HEIGHT_WITH_MARK_2_STYLE3)
                {
                    mark_y = y + (height >> 1) - 1;
                    for (i = 0; i < 2; i++)
                    {
                        gui_draw_horizontal_line(mark_x1, mark_x2, mark_y++, g_mmi_gui_scrollbar_light_color_style_3);
                        gui_draw_horizontal_line(mark_x1 + 1, mark_x2 + 1, mark_y++, g_mmi_gui_scrollbar_dark_color_style_3);
                    }
                }
            }

            break;
        }

        case GUI_SCROLLBAR_BUTTON_UP:
        case GUI_SCROLLBAR_BUTTON_LEFT:
        case GUI_SCROLLBAR_BUTTON_DOWN:
        case GUI_SCROLLBAR_BUTTON_RIGHT:
        {
            gui_scrollbar_precache_color2_style_3(c);

            if (is_button_pressed)
            {
                gui_show_image(x, y, (PU8) GetImage(IMG_SCROLLBAR_BUTTON_DOWN));
            }
            else
            {
                gui_show_image(x, y, (PU8) GetImage(IMG_SCROLLBAR_BUTTON_UP));
            }

            if (is_button_pressed)
            {
                y++;
            }

            if (type == GUI_SCROLLBAR_BUTTON_UP)
            {
                S32 arrow_width = width - (GUI_SCROLLBAR_ARROW_GAP_STYLE3 << 1);
                S32 arrow_height;
                S32 x1, y1, i;

                arrow_width -= (arrow_width % 2);
                arrow_height = arrow_width >> 1;

                x1 = (width - arrow_width);
                if (x1 > 0)
                {
                    x1 >>= 1;
                }
                else
                {
                    x1 = 0;
                }
                x1 += x;

                y1 = (height - arrow_height);
                if (y1 > 0)
                {
                    y1 >>= 1;
                }
                else
                {
                    y1 = 0;
                }
                y1 += y + arrow_height - 1 - 1; /* -1 for center */

                for (i = 0; i < arrow_height; i++)
                {
                    gui_putpixel(x1, y1, g_mmi_gui_scrollbar_arrow_color_style_3);
                    gui_putpixel(x1 + 1, y1, g_mmi_gui_scrollbar_arrow_color_style_3);
                    y1--;
                    x1++;
                }
                y1 += 2;
                for (i = 1; i < arrow_height; i++)
                {
                    gui_putpixel(x1, y1, g_mmi_gui_scrollbar_arrow_color_style_3);
                    gui_putpixel(x1 + 1, y1, g_mmi_gui_scrollbar_arrow_color_style_3);
                    y1++;
                    x1++;
                }
            }
            else if (type == GUI_SCROLLBAR_BUTTON_DOWN)
            {
                S32 arrow_width = width - (GUI_SCROLLBAR_ARROW_GAP_STYLE3 << 1);
                S32 arrow_height;
                S32 x1, y1, i;

                arrow_width -= (arrow_width % 2);
                arrow_height = arrow_width >> 1;

                x1 = (width - arrow_width);
                if (x1 > 0)
                {
                    x1 >>= 1;
                }
                else
                {
                    x1 = 0;
                }
                x1 += x;

                y1 = (height - arrow_height);
                if (y1 > 0)
                {
                    y1 >>= 1;
                }
                else
                {
                    y1 = 0;
                }
                y1 += y;

                for (i = 0; i < arrow_height; i++)
                {
                    gui_putpixel(x1, y1, g_mmi_gui_scrollbar_arrow_color_style_3);
                    gui_putpixel(x1 + 1, y1, g_mmi_gui_scrollbar_arrow_color_style_3);
                    y1++;
                    x1++;
                }
                y1 -= 2;
                for (i = 1; i < arrow_height; i++)
                {
                    gui_putpixel(x1, y1, g_mmi_gui_scrollbar_arrow_color_style_3);
                    gui_putpixel(x1 + 1, y1, g_mmi_gui_scrollbar_arrow_color_style_3);
                    y1--;
                    x1++;
                }
            }
            else if (type == GUI_SCROLLBAR_BUTTON_LEFT)
            {
                S32 arrow_height = height - (GUI_SCROLLBAR_ARROW_GAP_STYLE3 << 1);
                S32 arrow_width;
                S32 x1, y1, i;

                arrow_height -= (arrow_height % 2);
                arrow_width = arrow_height >> 1;

                y1 = (height - arrow_height);
                if (y1 > 0)
                {
                    y1 >>= 1;
                }
                else
                {
                    y1 = 0;
                }
                y1 += y;

                x1 = (width - arrow_width);
                if (x1 > 0)
                {
                    x1 >>= 1;
                }
                else
                {
                    x1 = 0;
                }
                x1 += x + arrow_width - 1 - 1;  /* -1 for center */

                for (i = 0; i < arrow_width; i++)
                {
                    gui_putpixel(x1, y1, g_mmi_gui_scrollbar_arrow_color_style_3);
                    gui_putpixel(x1, y1 + 1, g_mmi_gui_scrollbar_arrow_color_style_3);
                    y1++;
                    x1--;
                }
                x1 += 2;
                for (i = 1; i < arrow_width; i++)
                {
                    gui_putpixel(x1, y1, g_mmi_gui_scrollbar_arrow_color_style_3);
                    gui_putpixel(x1, y1 + 1, g_mmi_gui_scrollbar_arrow_color_style_3);
                    y1++;
                    x1++;
                }
            }
            else
            {
                S32 arrow_height = height - (GUI_SCROLLBAR_ARROW_GAP_STYLE3 << 1);
                S32 arrow_width;
                S32 x1, y1, i;

                arrow_height -= (arrow_height % 2);
                arrow_width = arrow_height >> 1;

                y1 = (height - arrow_height);
                if (y1 > 0)
                {
                    y1 >>= 1;
                }
                else
                {
                    y1 = 0;
                }
                y1 += y;

                x1 = (width - arrow_width);
                if (x1 > 0)
                {
                    x1 >>= 1;
                }
                else
                {
                    x1 = 0;
                }
                x1 += x;

                for (i = 0; i < arrow_width; i++)
                {
                    gui_putpixel(x1, y1, g_mmi_gui_scrollbar_arrow_color_style_3);
                    gui_putpixel(x1, y1 + 1, g_mmi_gui_scrollbar_arrow_color_style_3);
                    y1++;
                    x1++;
                }
                x1 -= 2;
                for (i = 1; i < arrow_width; i++)
                {
                    gui_putpixel(x1, y1, g_mmi_gui_scrollbar_arrow_color_style_3);
                    gui_putpixel(x1, y1 + 1, g_mmi_gui_scrollbar_arrow_color_style_3);
                    y1++;
                    x1--;
                }
            }

            break;
        }

        default:
            MMI_DBG_ASSERT(0);
    }

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }

}

#endif

#if defined(UI_SCROLLBAR_STYLE_2) || defined(UI_SCROLLBAR_WIDER_STYLE_2)
/*
 * We do not use gui_draw_filled_area and UI_FILLED_AREA_TYPE_CUSTOM_FILL_TYPE#
 * because up/down/left/right and horizontal/vertical scroll has up and down states, and
 * we need to define lots of filler types.
 */


/*****************************************************************************
 * FUNCTION
 *  gui_scrollbar_get_button_min_size
 * DESCRIPTION
 *
 * PARAMETERS
 *  type            [IN]
 *  bar_width       [IN]
 * RETURNS
 *
 *****************************************************************************/
S32 gui_scrollbar_get_button_min_size_style_2(gui_scrollbar_buttton_enum type, S32 bar_width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL:
            /* FALLTHROUGH no break */
        case GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL:
            /* "Expected" minimum size. However, the size of button may be larger. */
            ret = 12;
            break;

        case GUI_SCROLLBAR_BUTTON_UP:
            /* FALLTHROUGH no break */
        case GUI_SCROLLBAR_BUTTON_DOWN:
            /* FALLTHROUGH no break */
        case GUI_SCROLLBAR_BUTTON_LEFT:
            /* FALLTHROUGH no break */
        case GUI_SCROLLBAR_BUTTON_RIGHT:
            if (bar_width < 5)
            {
                /* Do not display these button at all */
                ret = 0;
            }
            else if ((bar_width % 2) == 0)
            {
                ret = bar_width;
            }
            else
            {
                /* height of button = width - 1.  But we need leave two pixels for room between scroll button */
                ret = bar_width + 1;
            }
            break;

        default:
            MMI_ASSERT(0);
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gui_scrollbar_adjust_luminance
 * DESCRIPTION
 *
 * PARAMETERS
 *  luminance       [IN/OUT]
 *  diff            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_scrollbar_adjust_luminance_style_2(U8 *luminance, S16 diff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 l = *luminance;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    l += diff;
    if (l > 255)
    {
        l = 255;
    }
    if (l < 0)
    {
        l = 0;
    }
    *luminance = (U8) l;
}


/*****************************************************************************
 * FUNCTION
 *  gui_scrollbar_draw_button
 * DESCRIPTION
 *
 * PARAMETERS
 *  type        [IN]
 *  b           [IN/OUT]
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_scrollbar_draw_button_style_2(gui_scrollbar_buttton_enum type, icon_button *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_HLS_color hls;
    color c;
    S32 x, y, width, height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x = b->x;
    y = b->y;
    width = b->width;
    height = b->height;
    c = b->normal_up_filler->c;

    /* Scroll button does not support highlight in UI_SCROLLBAR_STYLE_2 */
    if (type != GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL && type != GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL)
    {
        if (b->flags & UI_BUTTON_SHIFT_BUTTON1)
        {
            y++;
            gui_RGB_to_HLS(c, &hls);
            hls.l = (U8) ((U16) hls.l * 3 / 4);
            hls.s = (U8) ((U16) hls.s * 5 / 6);
            gui_HLS_to_RGB(hls, &c);
        }
        else if (b->flags & UI_BUTTON_SHIFT_BUTTON2)
        {
            y += 2;
            gui_RGB_to_HLS(c, &hls);
            hls.l = (U8) ((U16) hls.l * 3 / 4);
            hls.s = (U8) ((U16) hls.s * 5 / 6);
            gui_HLS_to_RGB(hls, &c);
        }
    }

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_and_set_clip(x, y, x + width - 1, y + height - 1);
    }

    /* shift the position to leave one-pixel space */
    if (type == GUI_SCROLLBAR_BUTTON_LEFT || type == GUI_SCROLLBAR_BUTTON_RIGHT)
    {
        x++;
    }
    if (type == GUI_SCROLLBAR_BUTTON_UP || type == GUI_SCROLLBAR_BUTTON_DOWN)
    {
        y++;
    }

    switch (type)
    {
        case GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL:
            /* FALLTHROUGH no break */
        case GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL:
        {
            S32 i;
            S32 num_shadow_line;
            color cs[3];    /* shadow color */
            color cf;       /* fill color */

            gui_RGB_to_HLS(c, &hls);

            if (height < 5 || width < 5)
            {
                /* No room to display the bar in special style */
                gui_show_icon_button(b);
            }
            else
            {
                if ((type == GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL && width >= 9) ||
                    (type == GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL && height >= 9))
                {
                    gui_scrollbar_adjust_luminance_style_2(&hls.l, 10);
                    gui_HLS_to_RGB(hls, &cs[0]);
                    gui_scrollbar_adjust_luminance_style_2(&hls.l, 10);
                    gui_HLS_to_RGB(hls, &cs[1]);
                    gui_scrollbar_adjust_luminance_style_2(&hls.l, 10);
                    gui_HLS_to_RGB(hls, &cs[2]);
                    gui_scrollbar_adjust_luminance_style_2(&hls.l, 10);
                    gui_HLS_to_RGB(hls, &cf);
                    num_shadow_line = 3;
                }
                else
                {
                    gui_scrollbar_adjust_luminance_style_2(&hls.l, 10);
                    gui_HLS_to_RGB(hls, &cs[0]);
                    gui_scrollbar_adjust_luminance_style_2(&hls.l, 10);
                    gui_HLS_to_RGB(hls, &cs[1]);
                    gui_scrollbar_adjust_luminance_style_2(&hls.l, 20);
                    gui_HLS_to_RGB(hls, &cf);
                    num_shadow_line = 2;
                }

                if (type == GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL)
                {
                    S32 x2, y2;

                    if (!(width % 2))
                    {
                        width--;
                    }
                    if (height >= 8)
                    {
                        /* Leave 1-pixel space */
                        y++;
                        height -= 2;
                    }

                    x2 = x + width - 1;
                    y2 = y + height - 1;

                    if (width <= 5)
                    {
                        gui_draw_vertical_line(y + 1, y2 - 1, x, c);
                        gui_draw_vertical_line(y + 1, y2 - 1, x2, c);
                        gui_draw_horizontal_line(x + 1, x2 - 1, y, c);
                        gui_draw_horizontal_line(x + 1, x2 - 1, y2, c);
                        for (i = x + 1; i < x2 - num_shadow_line; i++)
                        {
                            gui_draw_vertical_line(y + 1, y2 - 1, i, cf);
                        }

                        for (i = 0; i < num_shadow_line; i++)
                        {
                            gui_draw_vertical_line(y + 1, y2 - 1, x2 - 1 - i, cs[i]);
                        }
                    }
                    else
                    {
                        gui_draw_vertical_line(y + 2, y2 - 2, x, c);
                        gui_draw_vertical_line(y + 2, y2 - 2, x2, c);
                        gui_draw_horizontal_line(x + 2, x2 - 2, y, c);
                        gui_draw_horizontal_line(x + 2, x2 - 2, y2, c);

                        for (i = x + 1; i < x2 - num_shadow_line; i++)
                        {
                            gui_draw_vertical_line(y + 1, y2 - 1, i, cf);
                        }

                        for (i = 0; i < num_shadow_line; i++)
                        {
                            gui_draw_vertical_line(y + 1, y2 - 1, x2 - 1 - i, cs[i]);
                        }

                        gui_putpixel(x + 1, y + 1, c);
                        gui_putpixel(x2 - 1, y + 1, c);
                        gui_putpixel(x + 1, y2 - 1, c);
                        gui_putpixel(x2 - 1, y2 - 1, c);
                    }
                }
                else
                {
                    S32 x2, y2;

                    if (!(height % 2))
                    {
                        height--;
                    }
                    if (width >= 8)
                    {
                        /* Leave 1-pixel space */
                        x++;
                        width -= 2;
                    }

                    x2 = x + width - 1;
                    y2 = y + height - 1;

                    if (width <= 5)
                    {
                        gui_draw_horizontal_line(x + 1, x2 - 1, y, c);
                        gui_draw_horizontal_line(x + 1, x2 - 1, y2, c);
                        gui_draw_vertical_line(y + 1, y2 - 1, x, c);
                        gui_draw_vertical_line(y + 1, y2 - 1, x2, c);
                        for (i = y + 1; i < y2 - num_shadow_line; i++)
                        {
                            gui_draw_horizontal_line(x + 1, x2 - 1, i, cf);
                        }

                        for (i = 0; i < num_shadow_line; i++)
                        {
                            gui_draw_horizontal_line(x + 1, x2 - 1, y2 - 1 - i, cs[i]);
                        }
                    }
                    else
                    {
                        gui_draw_horizontal_line(x + 2, x2 - 2, y, c);
                        gui_draw_horizontal_line(x + 2, x2 - 2, y2, c);
                        gui_draw_vertical_line(y + 2, y2 - 2, x, c);
                        gui_draw_vertical_line(y + 2, y2 - 2, x2, c);

                        for (i = y + 1; i < y2 - num_shadow_line; i++)
                        {
                            gui_draw_horizontal_line(x + 1, x2 - 1, i, cf);
                        }

                        for (i = 0; i < num_shadow_line; i++)
                        {
                            gui_draw_horizontal_line(x + 1, x2 - 1, y2 - 1 - i, cs[i]);
                        }

                        gui_putpixel(x + 1, y + 1, c);
                        gui_putpixel(x2 - 1, y + 1, c);
                        gui_putpixel(x + 1, y2 - 1, c);
                        gui_putpixel(x2 - 1, y2 - 1, c);
                    }
                }
            }
        }
            break;

        case GUI_SCROLLBAR_BUTTON_UP:
        {
            if ((width % 2) == 0)
            {
                width--;
            }

            if (width < 5 || (width == 5 && height < 4) || (width > 5 && height < width - 1))
            {
                /* Draw nothing */
            }
            else if (width == 5)
            {
                gui_putpixel(x, y + 2, c);
                gui_putpixel(x, y + 3, c);
                gui_putpixel(x + 1, y + 1, c);
                gui_putpixel(x + 1, y + 2, c);
                gui_putpixel(x + 2, y, c);
                gui_putpixel(x + 2, y + 1, c);
                gui_putpixel(x + 3, y + 1, c);
                gui_putpixel(x + 3, y + 2, c);
                gui_putpixel(x + 4, y + 2, c);
                gui_putpixel(x + 4, y + 3, c);
            }
            else
            {
                UI_HLS_color hls;
                color cb;
                S32 i, hw;
                S32 x2, y2;

                /* Reduce the height */
                height = width - 1;

                x2 = x + width - 1;
                y2 = y + height - 1;

                gui_RGB_to_HLS(c, &hls);
                hls.l = (U8) (((U16) hls.l * 2 + 255) / 3);
                gui_HLS_to_RGB(hls, &cb);

                hw = (width >> 1);
                gui_draw_vertical_line(y + hw, y2, x, cb);
                for (i = 0; i < hw; i++)
                {
                    gui_putpixel(x + hw - i, y + i, cb);
                    gui_draw_vertical_line(y + i + 1, y2 - 1, x + hw - i, c);
                }
                for (i = 1; i < hw; i++)
                {
                    gui_putpixel(x + hw + i, y + i, cb);
                    gui_draw_vertical_line(y + i + 1, y2 - 1, x + hw + i, c);
                }
                gui_draw_vertical_line(y + hw, y2, x2, cb);
                gui_draw_horizontal_line(x, x2, y2, cb);
            }
        }
            break;

        case GUI_SCROLLBAR_BUTTON_LEFT:
        {
            if ((height % 2) == 0)
            {
                height--;
            }

            if (height < 5 || (height == 5 && width < 4) || (height > 5 && width < height - 1))
            {
                /* Draw nothing */
            }
            else if (height == 5)
            {
                gui_putpixel(x + 2, y, c);
                gui_putpixel(x + 3, y, c);
                gui_putpixel(x + 1, y + 1, c);
                gui_putpixel(x + 2, y + 1, c);
                gui_putpixel(x, y + 2, c);
                gui_putpixel(x + 1, y + 2, c);
                gui_putpixel(x + 1, y + 3, c);
                gui_putpixel(x + 2, y + 3, c);
                gui_putpixel(x + 2, y + 4, c);
                gui_putpixel(x + 3, y + 4, c);
            }
            else
            {
                UI_HLS_color hls;
                color cb;
                S32 i, hh;
                S32 x2, y2;

                /* Reduce the width */
                width = height - 1;

                x2 = x + width - 1;
                y2 = y + height - 1;

                gui_RGB_to_HLS(c, &hls);
                hls.l = (U8) (((U16) hls.l * 2 + 255) / 3);
                gui_HLS_to_RGB(hls, &cb);

                hh = (height >> 1);
                gui_draw_horizontal_line(x + hh, x2, y, cb);
                for (i = 0; i < hh; i++)
                {
                    gui_putpixel(x + i, y + hh - i, cb);
                    gui_draw_horizontal_line(x + i + 1, x2 - 1, y + hh - i, c);
                }
                for (i = 1; i < hh; i++)
                {
                    gui_putpixel(x + i, y + hh + i, cb);
                    gui_draw_horizontal_line(x + i + 1, x2 - 1, y + hh + i, c);
                }
                gui_draw_horizontal_line(x + hh, x2, y2, cb);
                gui_draw_vertical_line(y, y2, x2, cb);
            }
        }
            break;

        case GUI_SCROLLBAR_BUTTON_DOWN:
        {
            S32 y1, y2;

            if ((width % 2) == 0)
            {
                width--;
            }

            // y2 = y + height - 1 - 1;
            // y1 = y2 - (width - 1) + 1;
            /* (width - 1) is the height drawn */
            y1 = y;
            y2 = y1 + (width - 1) - 1;

            if (width < 5 || (width == 5 && height < 4) || (width > 5 && height < width - 1))
            {
                /* Draw nothing */
            }
            else if (width == 5)
            {
                gui_putpixel(x, y2 - 2, c);
                gui_putpixel(x, y2 - 3, c);
                gui_putpixel(x + 1, y2 - 1, c);
                gui_putpixel(x + 1, y2 - 2, c);
                gui_putpixel(x + 2, y2, c);
                gui_putpixel(x + 2, y2 - 1, c);
                gui_putpixel(x + 3, y2 - 1, c);
                gui_putpixel(x + 3, y2 - 2, c);
                gui_putpixel(x + 4, y2 - 2, c);
                gui_putpixel(x + 4, y2 - 3, c);
            }
            else
            {
                UI_HLS_color hls;
                color cb;
                S32 i, hw;

                /* Reduce the height */
                height = width - 1;

                gui_RGB_to_HLS(c, &hls);
                hls.l = (U8) (((U16) hls.l * 2 + 255) / 3);
                gui_HLS_to_RGB(hls, &cb);

                hw = (width >> 1);
                gui_draw_vertical_line(y1, y2 - hw, x, cb);
                for (i = 0; i < hw; i++)
                {
                    gui_putpixel(x + hw - i, y2 - i, cb);
                    gui_draw_vertical_line(y1 + 1, y2 - i - 1, x + hw - i, c);
                }
                for (i = 1; i < hw; i++)
                {
                    gui_putpixel(x + hw + i, y2 - i, cb);
                    gui_draw_vertical_line(y1 + 1, y2 - i - 1, x + hw + i, c);
                }
                gui_draw_vertical_line(y1, y2 - hw, x + width - 1, cb);
                gui_draw_horizontal_line(x, x + width - 1, y1, cb);
            }
        }
            break;

        case GUI_SCROLLBAR_BUTTON_RIGHT:
        {
            S32 x1, x2;

            if ((height % 2) == 0)
            {
                height--;
            }

            // x2 = x + width - 1 - 1;
            // x1 = x2 - (height - 1) + 1;
            /* (height - 1) is the width drawn */
            x1 = x;
            x2 = x + (height - 1) - 1;

            if (height < 5 || (height == 5 && width < 4) || (height > 5 && width < height - 1))
            {
                /* Draw nothing */
            }
            else if (height == 5)
            {
                gui_putpixel(x2 - 2, y, c);
                gui_putpixel(x2 - 3, y, c);
                gui_putpixel(x2 - 1, y + 1, c);
                gui_putpixel(x2 - 2, y + 1, c);
                gui_putpixel(x2, y + 2, c);
                gui_putpixel(x2 - 1, y + 2, c);
                gui_putpixel(x2 - 1, y + 3, c);
                gui_putpixel(x2 - 2, y + 3, c);
                gui_putpixel(x2 - 2, y + 4, c);
                gui_putpixel(x2 - 3, y + 4, c);
            }
            else
            {
                UI_HLS_color hls;
                color cb;
                S32 i, hh;

                /* Reduce the width */
                width = height - 1;

                gui_RGB_to_HLS(c, &hls);
                hls.l = (U8) (((U16) hls.l * 2 + 255) / 3);
                gui_HLS_to_RGB(hls, &cb);

                hh = (height >> 1);
                gui_draw_horizontal_line(x1, x2 - hh, y, cb);
                for (i = 0; i < hh; i++)
                {
                    gui_putpixel(x2 - i, y + hh - i, cb);
                    gui_draw_horizontal_line(x1 + 1, x2 - i - 1, y + hh - i, c);
                }
                for (i = 1; i < hh; i++)
                {
                    gui_putpixel(x2 - i, y + hh + i, cb);
                    gui_draw_horizontal_line(x1 + 1, x2 - i - 1, y + hh + i, c);
                }
                gui_draw_horizontal_line(x1, x2 - hh, y + height - 1, cb);
                gui_draw_vertical_line(y, y + height - 1, x1, cb);
            }
        }

            break;
    }

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }

}


#endif /* UI_SCROLLBAR_STYLE_5 */

#if defined(UI_SCROLLBAR_STYLE_1) || defined(UI_SCROLLBAR_WIDER_STYLE_1)
/*****************************************************************************
 * FUNCTION
*  gui_horizontal_scrollbar_redraw_button_style_1
* DESCRIPTION
*  Redraw the horizontal scrollbar button
* PARAMETERS
*  v       [IN/OUT]            Is the vertical scrollbar object
* RETURNS
*  void
*****************************************************************************/
void gui_horizontal_scrollbar_redraw_button_style_1(horizontal_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        return;
    }
    old_lcd_handle = gui_horizontal_scrollbar_setup_target_lcd_and_layer(v);
    if (type == GUI_SCROLLBAR_BUTTON_LEFT)
    {
        if (pressed == MMI_TRUE)
        {
            v->left_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        }
        else
        {
            v->left_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        }

        gui_show_icon_button(&v->left_button);
    }
    else if (type == GUI_SCROLLBAR_BUTTON_RIGHT)
    {
        if (pressed == MMI_TRUE)
        {
            v->right_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        }
        else
        {
            v->right_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        }
        gui_show_icon_button(&v->right_button);
    }
    gui_horizontal_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);
}


/*****************************************************************************
* FUNCTION
 *  gui_show_horizontal_scrollbar_style_1
 * DESCRIPTION
 *  Displays the horizontal scrollbar
 * PARAMETERS
 *  v       [IN/OUT]            Is the horizontal scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_horizontal_scrollbar_style_1(horizontal_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, sbutton_width, sb_x, sb_xrange, r, min_width = 0, max_width = 0;
    U8 buttons_flag = 1;
    UI_filled_area *f;
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_HORIZONTAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        buttons_flag = 0;
    }

    x1 = v->x;
    x2 = x1 + v->width - 1;
    y1 = v->y;
    y2 = y1 + v->height - 1;

    if (v->flags & UI_HORIZONTAL_SCROLLBAR_STATE_FOCUSSED)
    {
        f = v->focussed_bar_filler;
    }
    else if (v->flags & UI_HORIZONTAL_SCROLLBAR_STATE_DISABLED)
    {
        f = v->disabled_bar_filler;
    }
    else
    {
        f = v->normal_bar_filler;
    }

    old_lcd_handle = gui_horizontal_scrollbar_setup_target_lcd_and_layer(v);

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_and_set_clip(x1, y1, x2, y2);
    }
    /* Style 3 use three image to compose scrollbar background */
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {
        BOOL source_key_enable;
        gdi_color source_key_value;

        gdi_layer_get_source_key(&source_key_enable, &source_key_value);
        if (v->hide_callback)
        {
            v->hide_callback(x1, y1, x2, y2);
        }
        else if(!(v->flags & UI_HORIZONTAL_SCROLLBAR_NOT_CLEAR_BACKGROUND))
        {
            if (source_key_enable)
            {
                gdi_draw_solid_rect(x1, y1, x2, y2, source_key_value);
            }
            else
            {
            /*
            * Please read the description in gui_show_vertical_scrollbar()
                */
                gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
            }
        }

    }
#else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
    gui_draw_filled_area(x1, y1, x2, y2, f);
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }

    if (buttons_flag)
    {
        gui_show_icon_button(&v->left_button);
        gui_show_icon_button(&v->right_button);
        max_width = v->width - v->left_button.width - v->right_button.width;
    }
    else
    {
        max_width = v->width;
    }

    /* Show the scroll button based on range and value */
    r = v->range - v->scale;
    min_width = v->height;
    if (min_width > max_width)
    {
        min_width = max_width;
    }
    if (v->scale > 0)
    {
        if (v->range > 0)
        {
            sbutton_width = (v->scale * max_width) / v->range;
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
        /* In case of very large r & v->value */
        sb_x = (S32) ((S64) sb_xrange * v->value / r);
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

#ifdef __MMI_TOUCH_SCREEN__
    v->pen_state.remain_space = (S16) sb_xrange;
#endif

    v->scroll_button.width = sbutton_width;
    v->scroll_button.x = sb_x + x1 + (buttons_flag ? v->left_button.width : 0);
    gui_show_icon_button(&v->scroll_button);

    gui_horizontal_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);

}


/*****************************************************************************
 * FUNCTION
*  gui_vertical_scrollbar_redraw_button_style_1
* DESCRIPTION
*  Redraw the vertical scrollbar button
* PARAMETERS
*  v       [IN/OUT]            Is the vertical scrollbar object
* RETURNS
*  void
*****************************************************************************/
void gui_vertical_scrollbar_redraw_button_style_1(vertical_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        return;
    }

    old_lcd_handle = gui_vertical_scrollbar_setup_target_lcd_and_layer(v);

    if (type == GUI_SCROLLBAR_BUTTON_UP)
    {
        if (pressed == MMI_TRUE)
        {
            v->up_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        }
        else
        {
            v->up_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        }

        gui_show_icon_button(&v->up_button);
    }
    else if (type == GUI_SCROLLBAR_BUTTON_DOWN)
    {
        if (pressed == MMI_TRUE)
        {
            v->down_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        }
        else
        {
            v->down_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        }
        gui_show_icon_button(&v->down_button);
    }

    gui_vertical_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);

}


/*****************************************************************************
* FUNCTION
 *  gui_show_vertical_scrollbar_style_1
 * DESCRIPTION
 *  Displays the vertical scrollbar
 * PARAMETERS
 *  v       [IN/OUT]            Is the vertical scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_vertical_scrollbar_style_1(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, sbutton_height, sb_y, sb_yrange, r, min_height = 0, max_height = 0;
    U8 buttons_flag = 1;
    UI_filled_area *f;
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        buttons_flag = 0;
    }

    x1 = v->x;
    x2 = x1 + v->width - 1;
    y1 = v->y;
    y2 = y1 + v->height - 1;

    if (v->flags & UI_VERTICAL_SCROLLBAR_STATE_FOCUSSED)
    {
        f = v->focussed_bar_filler;
    }
    else if (v->flags & UI_VERTICAL_SCROLLBAR_STATE_DISABLED)
    {
        f = v->disabled_bar_filler;
    }
    else
    {
        f = v->normal_bar_filler;
    }

    old_lcd_handle = gui_vertical_scrollbar_setup_target_lcd_and_layer(v);

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_and_set_clip(x1, y1, x2, y2);
    }
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {
        BOOL source_key_enable;
        gdi_color source_key_value;

        gdi_layer_get_source_key(&source_key_enable, &source_key_value);
        if (v->hide_callback)
        {
            v->hide_callback(x1, y1, x2, y2);
        }
        else if(!(v->flags & UI_VERTICAL_SCROLLBAR_NOT_CLEAR_BACKGROUND))
        {
            if ((wgui_is_wallpaper_on_bottom() == MMI_TRUE) && source_key_enable)
            {
                gdi_draw_solid_rect(x1, y1, x2, y2, source_key_value);
            }
            else
            {
            /*
            * Tricky to handle scrollbar background here!
            *
            * Some screens like Obigo or Jataayu WAP disable source key of layer,
            * and WAP typically uses white background.
            *
            * If we use 'gui_draw_filled_area(x1, y1, x2, y2, f);' instead, it may
            * produce weird display with inappropriate scrollbar background color
            * created by MCT or PhoneSuite (Downloadable theme)
            *
            * We decide not to change WAP code, but use white color here for
            * __MMI_WALLPAPER_ON_BOTTOM__ (> 240x320 screen)
            *
                */
                gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
            }
        }

    }
#else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
    gui_draw_filled_area(x1, y1, x2, y2, f);
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }

    if (buttons_flag)
    {
        gui_show_icon_button(&v->up_button);
        gui_show_icon_button(&v->down_button);
        max_height = v->height - v->up_button.height - v->down_button.height;
    }
    else
    {
        max_height = v->height;
    }
    /* Show the scroll button based on range and value */
    r = v->range - v->scale;
    min_height = v->width;
    if (min_height > max_height)
    {
        min_height = max_height;
    }
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
        /* In case of very large r & v->value */
        sb_y = (S32) ((S64) sb_yrange * v->value / r);
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

#ifdef __MMI_TOUCH_SCREEN__
    v->pen_state.remain_space = (S16) sb_yrange;
#endif

    v->scroll_button.height = sbutton_height;
    v->scroll_button.y = sb_y + y1 + (buttons_flag ? v->up_button.height : 0);
    gui_show_icon_button(&v->scroll_button);

    gui_vertical_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);

}

#endif

#if defined(UI_SCROLLBAR_STYLE_2) || defined(UI_SCROLLBAR_WIDER_STYLE_2)
/*****************************************************************************
 * FUNCTION
*  gui_horizontal_scrollbar_redraw_button_style_2
* DESCRIPTION
*  Redraw the horizontal scrollbar button
* PARAMETERS
*  v       [IN/OUT]            Is the vertical scrollbar object
* RETURNS
*  void
*****************************************************************************/
void gui_horizontal_scrollbar_redraw_button_style_2(horizontal_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        return;
    }

    old_lcd_handle = gui_horizontal_scrollbar_setup_target_lcd_and_layer(v);

    if (type == GUI_SCROLLBAR_BUTTON_LEFT)
    {
        if (pressed == MMI_TRUE)
        {
            v->left_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        }
        else
        {
            v->left_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        }

        gui_scrollbar_draw_button_style_2(GUI_SCROLLBAR_BUTTON_LEFT, &v->left_button);
    }
    else if (type == GUI_SCROLLBAR_BUTTON_RIGHT)
    {
        if (pressed == MMI_TRUE)
        {
            v->right_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        }
        else
        {
            v->right_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        }
        gui_scrollbar_draw_button_style_2(GUI_SCROLLBAR_BUTTON_RIGHT, &v->right_button);
    }

    gui_horizontal_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);

}


/*****************************************************************************
* FUNCTION
 *  gui_show_horizontal_scrollbar_style_2
 * DESCRIPTION
 *  Displays the horizontal scrollbar
 * PARAMETERS
 *  v       [IN/OUT]            Is the horizontal scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_horizontal_scrollbar_style_2(horizontal_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, sbutton_width, sb_x, sb_xrange, r, min_width = 0, max_width = 0;
    U8 buttons_flag = 1;
    UI_filled_area *f;
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_HORIZONTAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        buttons_flag = 0;
    }

    x1 = v->x;
    x2 = x1 + v->width - 1;
    y1 = v->y;
    y2 = y1 + v->height - 1;

    if (v->flags & UI_HORIZONTAL_SCROLLBAR_STATE_FOCUSSED)
    {
        f = v->focussed_bar_filler;
    }
    else if (v->flags & UI_HORIZONTAL_SCROLLBAR_STATE_DISABLED)
    {
        f = v->disabled_bar_filler;
    }
    else
    {
        f = v->normal_bar_filler;
    }

    old_lcd_handle = gui_horizontal_scrollbar_setup_target_lcd_and_layer(v);

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_and_set_clip(x1, y1, x2, y2);
    }
    /* Style 3 use three image to compose scrollbar background */
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {
        BOOL source_key_enable;
        gdi_color source_key_value;

        gdi_layer_get_source_key(&source_key_enable, &source_key_value);
        if (v->hide_callback)
        {
            v->hide_callback(x1, y1, x2, y2);
        }
        else if(!(v->flags & UI_HORIZONTAL_SCROLLBAR_NOT_CLEAR_BACKGROUND))
        {
            if (source_key_enable)
            {
                gdi_draw_solid_rect(x1, y1, x2, y2, source_key_value);
            }
            else
            {
            /*
            * Please read the description in gui_show_vertical_scrollbar()
                */
                gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
            }
        }

    }
#else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
    gui_draw_filled_area(x1, y1, x2, y2, f);
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }

    if (buttons_flag)
    {
        gui_scrollbar_draw_button_style_2(GUI_SCROLLBAR_BUTTON_LEFT, &v->left_button);
        gui_scrollbar_draw_button_style_2(GUI_SCROLLBAR_BUTTON_RIGHT, &v->right_button);
        max_width = v->width - v->left_button.width - v->right_button.width;
    }
    else
    {
        max_width = v->width;
    }

    /* Show the scroll button based on range and value */
    r = v->range - v->scale;
    min_width = gui_scrollbar_get_button_min_size_style_2(GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL, v->height);
    if (min_width > max_width)
    {
        min_width = max_width;
    }
    if (v->scale > 0)
    {
        if (v->range > 0)
        {
            sbutton_width = (v->scale * max_width) / v->range;
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
        /* In case of very large r & v->value */
        sb_x = (S32) ((S64) sb_xrange * v->value / r);
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

#ifdef __MMI_TOUCH_SCREEN__
    v->pen_state.remain_space = (S16) sb_xrange;
#endif

    v->scroll_button.width = sbutton_width;
    v->scroll_button.x = sb_x + x1 + (buttons_flag ? v->left_button.width : 0);
    gui_scrollbar_draw_button_style_2(GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL, &v->scroll_button);

    gui_horizontal_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);

}


/*****************************************************************************
 * FUNCTION
*  gui_vertical_scrollbar_redraw_button_style_2
* DESCRIPTION
*  Redraw the vertical scrollbar button
* PARAMETERS
*  v       [IN/OUT]            Is the vertical scrollbar object
* RETURNS
*  void
*****************************************************************************/
void gui_vertical_scrollbar_redraw_button_style_2(vertical_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        return;
    }

    old_lcd_handle = gui_vertical_scrollbar_setup_target_lcd_and_layer(v);

    if (type == GUI_SCROLLBAR_BUTTON_UP)
    {
        if (pressed == MMI_TRUE)
        {
            v->up_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        }
        else
        {
            v->up_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        }

        gui_scrollbar_draw_button_style_2(GUI_SCROLLBAR_BUTTON_UP, &v->up_button);
    }
    else if (type == GUI_SCROLLBAR_BUTTON_DOWN)
    {
        if (pressed == MMI_TRUE)
        {
            v->down_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        }
        else
        {
            v->down_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        }
        gui_scrollbar_draw_button_style_2(GUI_SCROLLBAR_BUTTON_DOWN, &v->down_button);
    }

    gui_vertical_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);

}


/*****************************************************************************
* FUNCTION
 *  gui_show_vertical_scrollbar_style_2
 * DESCRIPTION
 *  Displays the vertical scrollbar
 * PARAMETERS
 *  v       [IN/OUT]            Is the vertical scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_vertical_scrollbar_style_2(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, sbutton_height, sb_y, sb_yrange, r, min_height = 0, max_height = 0;
    U8 buttons_flag = 1;
    UI_filled_area *f;
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        buttons_flag = 0;
    }

    x1 = v->x;
    x2 = x1 + v->width - 1;
    y1 = v->y;
    y2 = y1 + v->height - 1;

    if (v->flags & UI_VERTICAL_SCROLLBAR_STATE_FOCUSSED)
    {
        f = v->focussed_bar_filler;
    }
    else if (v->flags & UI_VERTICAL_SCROLLBAR_STATE_DISABLED)
    {
        f = v->disabled_bar_filler;
    }
    else
    {
        f = v->normal_bar_filler;
    }

    old_lcd_handle = gui_vertical_scrollbar_setup_target_lcd_and_layer(v);

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_and_set_clip(x1, y1, x2, y2);
    }
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {
        BOOL source_key_enable;
        gdi_color source_key_value;

        gdi_layer_get_source_key(&source_key_enable, &source_key_value);
        if (v->hide_callback)
        {
            v->hide_callback(x1, y1, x2, y2);
        }
        else if(!(v->flags & UI_VERTICAL_SCROLLBAR_NOT_CLEAR_BACKGROUND))
        {
            if ((wgui_is_wallpaper_on_bottom() == MMI_TRUE) && source_key_enable)
            {
                gdi_draw_solid_rect(x1, y1, x2, y2, source_key_value);
            }
            else
            {
            /*
            * Tricky to handle scrollbar background here!
            *
            * Some screens like Obigo or Jataayu WAP disable source key of layer,
            * and WAP typically uses white background.
            *
            * If we use 'gui_draw_filled_area(x1, y1, x2, y2, f);' instead, it may
            * produce weird display with inappropriate scrollbar background color
            * created by MCT or PhoneSuite (Downloadable theme)
            *
            * We decide not to change WAP code, but use white color here for
            * __MMI_WALLPAPER_ON_BOTTOM__ (> 240x320 screen)
            *
                */
                gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
            }
        }

    }
#else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
    gui_draw_filled_area(x1, y1, x2, y2, f);
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }

    if (buttons_flag)
    {
        gui_scrollbar_draw_button_style_2(GUI_SCROLLBAR_BUTTON_UP, &v->up_button);
        gui_scrollbar_draw_button_style_2(GUI_SCROLLBAR_BUTTON_DOWN, &v->down_button);
        max_height = v->height - v->up_button.height - v->down_button.height;
    }
    else
    {
        max_height = v->height;
    }
    /* Show the scroll button based on range and value */
    r = v->range - v->scale;
    min_height = gui_scrollbar_get_button_min_size_style_2(GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL, v->width);
    if (min_height > max_height)
    {
        min_height = max_height;
    }
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
        /* In case of very large r & v->value */
        sb_y = (S32) ((S64) sb_yrange * v->value / r);
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

#ifdef __MMI_TOUCH_SCREEN__
    v->pen_state.remain_space = (S16) sb_yrange;
#endif

    v->scroll_button.height = sbutton_height;
    v->scroll_button.y = sb_y + y1 + (buttons_flag ? v->up_button.height : 0);
    gui_scrollbar_draw_button_style_2(GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL, &v->scroll_button);

    gui_vertical_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);

}

#endif

#if defined(UI_SCROLLBAR_STYLE_3) || defined(UI_SCROLLBAR_WIDER_STYLE_3)
/*****************************************************************************
 * FUNCTION
*  gui_horizontal_scrollbar_redraw_button_style_3
* DESCRIPTION
*  Redraw the horizontal scrollbar button
* PARAMETERS
*  v       [IN/OUT]            Is the vertical scrollbar object
* RETURNS
*  void
*****************************************************************************/
void gui_horizontal_scrollbar_redraw_button_style_3(horizontal_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        return;
    }

    old_lcd_handle = gui_horizontal_scrollbar_setup_target_lcd_and_layer(v);

    if (type == GUI_SCROLLBAR_BUTTON_LEFT)
    {
        if (pressed == MMI_TRUE)
        {
            v->left_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        }
        else
        {
            v->left_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        }

        gui_scrollbar_draw_button_style_3(GUI_SCROLLBAR_BUTTON_LEFT, &v->left_button);
    }
    else if (type == GUI_SCROLLBAR_BUTTON_RIGHT)
    {
        if (pressed == MMI_TRUE)
        {
            v->right_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        }
        else
        {
            v->right_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        }
        gui_scrollbar_draw_button_style_3(GUI_SCROLLBAR_BUTTON_RIGHT, &v->right_button);
    }

    gui_horizontal_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);

}


/*****************************************************************************
* FUNCTION
 *  gui_show_horizontal_scrollbar_style_3
 * DESCRIPTION
 *  Displays the horizontal scrollbar
 * PARAMETERS
 *  v       [IN/OUT]            Is the horizontal scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_horizontal_scrollbar_style_3(horizontal_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, sbutton_width, sb_x, sb_xrange, r, min_width = 0, max_width = 0;
    U8 buttons_flag = 1;
    UI_filled_area *f;
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_HORIZONTAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        buttons_flag = 0;
    }

    x1 = v->x;
    x2 = x1 + v->width - 1;
    y1 = v->y;
    y2 = y1 + v->height - 1;

    if (v->flags & UI_HORIZONTAL_SCROLLBAR_STATE_FOCUSSED)
    {
        f = v->focussed_bar_filler;
    }
    else if (v->flags & UI_HORIZONTAL_SCROLLBAR_STATE_DISABLED)
    {
        f = v->disabled_bar_filler;
    }
    else
    {
        f = v->normal_bar_filler;
    }

    old_lcd_handle = gui_horizontal_scrollbar_setup_target_lcd_and_layer(v);

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_and_set_clip(x1, y1, x2, y2);
    }
    /* Style 3 use three image to compose scrollbar background */
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {
        BOOL source_key_enable;
        gdi_color source_key_value;

        gdi_layer_get_source_key(&source_key_enable, &source_key_value);
        if (v->hide_callback)
        {
            v->hide_callback(x1, y1, x2, y2);
        }
        else if(!(v->flags & UI_HORIZONTAL_SCROLLBAR_NOT_CLEAR_BACKGROUND))
        {
            if (source_key_enable)
            {
                gdi_draw_solid_rect(x1, y1, x2, y2, source_key_value);
            }
            else
            {
            /*
            * Please read the description in gui_show_vertical_scrollbar()
                */
                gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
            }

        }
    }
#else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
    gui_draw_filled_area(x1, y1, x2, y2, f);
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }

    if (buttons_flag)
    {
        gui_scrollbar_draw_button_style_3(GUI_SCROLLBAR_BUTTON_LEFT, &v->left_button);
        gui_scrollbar_draw_button_style_3(GUI_SCROLLBAR_BUTTON_RIGHT, &v->right_button);
        max_width = v->width - v->left_button.width - v->right_button.width;
    }
    else
    {
        max_width = v->width;
    }

    /* Show the scroll button based on range and value */
    r = v->range - v->scale;
    min_width = gui_scrollbar_get_button_min_size_style_3(GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL, v->height);
    if (min_width > max_width)
    {
        min_width = max_width;
    }
    if (v->scale > 0)
    {
        if (v->range > 0)
        {
            sbutton_width = (v->scale * max_width) / v->range;
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
        /* In case of very large r & v->value */
        sb_x = (S32) ((S64) sb_xrange * v->value / r);
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

#ifdef __MMI_TOUCH_SCREEN__
    v->pen_state.remain_space = (S16) sb_xrange;
#endif

    v->scroll_button.width = sbutton_width;
    v->scroll_button.x = sb_x + x1 + (buttons_flag ? v->left_button.width : 0);
    if (buttons_flag)
    {
        gui_scrollbar_draw_region_style_3(
            GUI_SCROLLBAR_REGION_HORIZONTAL,
            v->x + v->left_button.x + v->left_button.width,
            v->y,
            v->right_button.x - v->left_button.x - v->left_button.width,
            v->height);
    }
    else
    {
        gui_scrollbar_draw_region_style_3(GUI_SCROLLBAR_REGION_HORIZONTAL, v->x, v->y, v->width, v->height);
    }
    gui_scrollbar_draw_button_style_3(GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL, &v->scroll_button);

    gui_horizontal_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);

}


/*****************************************************************************
 * FUNCTION
*  gui_vertical_scrollbar_redraw_button_style_3
* DESCRIPTION
*  Redraw the vertical scrollbar button
* PARAMETERS
*  v       [IN/OUT]            Is the vertical scrollbar object
* RETURNS
*  void
*****************************************************************************/
void gui_vertical_scrollbar_redraw_button_style_3(vertical_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        return;
    }

    old_lcd_handle = gui_vertical_scrollbar_setup_target_lcd_and_layer(v);

    if (type == GUI_SCROLLBAR_BUTTON_UP)
    {
        if (pressed == MMI_TRUE)
        {
            v->up_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        }
        else
        {
            v->up_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        }

        gui_scrollbar_draw_button_style_3(GUI_SCROLLBAR_BUTTON_UP, &v->up_button);
    }
    else if (type == GUI_SCROLLBAR_BUTTON_DOWN)
    {
        if (pressed == MMI_TRUE)
        {
            v->down_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        }
        else
        {
            v->down_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        }
        gui_scrollbar_draw_button_style_3(GUI_SCROLLBAR_BUTTON_DOWN, &v->down_button);
    }

   gui_vertical_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);

}


/*****************************************************************************
* FUNCTION
 *  gui_show_vertical_scrollbar_style_3
 * DESCRIPTION
 *  Displays the vertical scrollbar
 * PARAMETERS
 *  v       [IN/OUT]            Is the vertical scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_vertical_scrollbar_style_3(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, sbutton_height, sb_y, sb_yrange, r, min_height = 0, max_height = 0;
    U8 buttons_flag = 1;
    UI_filled_area *f;
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        buttons_flag = 0;
    }

    x1 = v->x;
    x2 = x1 + v->width - 1;
    y1 = v->y;
    y2 = y1 + v->height - 1;

    if (v->flags & UI_VERTICAL_SCROLLBAR_STATE_FOCUSSED)
    {
        f = v->focussed_bar_filler;
    }
    else if (v->flags & UI_VERTICAL_SCROLLBAR_STATE_DISABLED)
    {
        f = v->disabled_bar_filler;
    }
    else
    {
        f = v->normal_bar_filler;
    }

    old_lcd_handle = gui_vertical_scrollbar_setup_target_lcd_and_layer(v);

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_and_set_clip(x1, y1, x2, y2);
    }
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {
        BOOL source_key_enable;
        gdi_color source_key_value;

        gdi_layer_get_source_key(&source_key_enable, &source_key_value);
        if (v->hide_callback)
        {
            v->hide_callback(x1, y1, x2, y2);
        }
        else if(!(v->flags & UI_VERTICAL_SCROLLBAR_NOT_CLEAR_BACKGROUND))
        {
            if ((wgui_is_wallpaper_on_bottom() == MMI_TRUE) && source_key_enable)
            {
                gdi_draw_solid_rect(x1, y1, x2, y2, source_key_value);
            }
            else
            {
            /*
            * Tricky to handle scrollbar background here!
            *
            * Some screens like Obigo or Jataayu WAP disable source key of layer,
            * and WAP typically uses white background.
            *
            * If we use 'gui_draw_filled_area(x1, y1, x2, y2, f);' instead, it may
            * produce weird display with inappropriate scrollbar background color
            * created by MCT or PhoneSuite (Downloadable theme)
            *
            * We decide not to change WAP code, but use white color here for
            * __MMI_WALLPAPER_ON_BOTTOM__ (> 240x320 screen)
            *
                */
                gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
            }
        }

    }
#else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
    gui_draw_filled_area(x1, y1, x2, y2, f);
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }

    if (buttons_flag)
    {
        gui_scrollbar_draw_button_style_3(GUI_SCROLLBAR_BUTTON_UP, &v->up_button);
        gui_scrollbar_draw_button_style_3(GUI_SCROLLBAR_BUTTON_DOWN, &v->down_button);
        max_height = v->height - v->up_button.height - v->down_button.height;
    }
    else
    {
        max_height = v->height;
    }
    /* Show the scroll button based on range and value */
    r = v->range - v->scale;
    min_height = gui_scrollbar_get_button_min_size_style_3(GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL, v->width);
    if (min_height > max_height)
    {
        min_height = max_height;
    }
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
        /* In case of very large r & v->value */
        sb_y = (S32) ((S64) sb_yrange * v->value / r);
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

#ifdef __MMI_TOUCH_SCREEN__
    v->pen_state.remain_space = (S16) sb_yrange;
#endif

    v->scroll_button.height = sbutton_height;
    v->scroll_button.y = sb_y + y1 + (buttons_flag ? v->up_button.height : 0);
    if (buttons_flag)
    {
        gui_scrollbar_draw_region_style_3(
            GUI_SCROLLBAR_REGION_VERTICAL,
            v->x,
            v->up_button.y + v->up_button.height,
            v->width,
            v->down_button.y - v->up_button.y - v->up_button.height);
    }
    else
    {
        gui_scrollbar_draw_region_style_3(GUI_SCROLLBAR_REGION_VERTICAL, v->x, v->y, v->width, v->height);
    }
    gui_scrollbar_draw_button_style_3(GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL, &v->scroll_button);

    gui_vertical_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);

}

#endif

#if defined(UI_SCROLLBAR_STYLE_4) || defined(UI_SCROLLBAR_WIDER_STYLE_4)

/*****************************************************************************
 * FUNCTION
*  gui_horizontal_scrollbar_redraw_button
* DESCRIPTION
*  Redraw the horizontal scrollbar button
* PARAMETERS
*  v       [IN/OUT]            Is the vertical scrollbar object
* RETURNS
*  void
*****************************************************************************/
void gui_horizontal_scrollbar_redraw_button_style_4(horizontal_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        return;
    }

    old_lcd_handle = gui_horizontal_scrollbar_setup_target_lcd_and_layer(v);

    if (type == GUI_SCROLLBAR_BUTTON_LEFT)
    {
        if (pressed == MMI_TRUE)
        {
            v->left_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        }
        else
        {
            v->left_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        }

#if defined(__MMI_TOUCH_SCREEN__)
        gui_scrollbar_draw_button_style_4(GUI_SCROLLBAR_BUTTON_LEFT, &v->left_button);
#endif
    }
    else if (type == GUI_SCROLLBAR_BUTTON_RIGHT)
    {
        if (pressed == MMI_TRUE)
        {
            v->right_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        }
        else
        {
            v->right_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        }
#if defined(__MMI_TOUCH_SCREEN__)
        gui_scrollbar_draw_button_style_4(GUI_SCROLLBAR_BUTTON_RIGHT, &v->right_button);
#endif
    }

    gui_horizontal_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);

}


/*****************************************************************************
* FUNCTION
 *  gui_show_horizontal_scrollbar
 * DESCRIPTION
 *  Displays the horizontal scrollbar
 * PARAMETERS
 *  v       [IN/OUT]            Is the horizontal scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_horizontal_scrollbar_style_4(horizontal_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, sbutton_width, sb_x, sb_xrange, r, min_width = 0, max_width = 0;
    U8 buttons_flag = 1;
#ifndef __MMI_WALLPAPER_ON_BOTTOM__
    UI_filled_area *f;
#endif
    GDI_HANDLE gdi_lcd_layer;
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_HORIZONTAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        buttons_flag = 0;
    }

    x1 = v->x;
    x2 = x1 + v->width - 1;
    y1 = v->y;
    y2 = y1 + v->height - 1;

#ifndef __MMI_WALLPAPER_ON_BOTTOM__
    if (v->flags & UI_HORIZONTAL_SCROLLBAR_STATE_FOCUSSED)
    {
        f = v->focussed_bar_filler;
    }
    else if (v->flags & UI_HORIZONTAL_SCROLLBAR_STATE_DISABLED)
    {
        f = v->disabled_bar_filler;
    }
    else
    {
        f = v->normal_bar_filler;
    }
#endif

    old_lcd_handle = gui_horizontal_scrollbar_setup_target_lcd_and_layer(v);

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_and_set_clip(x1, y1, x2, y2);
    }
    /* Style 3 use three image to compose scrollbar background */
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {
        BOOL source_key_enable;
        gdi_color source_key_value;

        gdi_layer_get_source_key(&source_key_enable, &source_key_value);
        if (v->hide_callback)
        {
            v->hide_callback(x1, y1, x2, y2);
        }
        else if(!(v->flags & UI_HORIZONTAL_SCROLLBAR_NOT_CLEAR_BACKGROUND))
        { 
            if (source_key_enable)
            {
                gdi_draw_solid_rect(x1, y1, x2, y2, source_key_value);
            }
            else
            {
                /*
                * Please read the description in gui_show_vertical_scrollbar()
                */
                gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
            }   
        }

    }
#else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
    gui_draw_filled_area(x1, y1, x2, y2, f);
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }

    if (buttons_flag)
    {
    #if defined(__MMI_TOUCH_SCREEN__)
        gui_scrollbar_draw_button_style_4(GUI_SCROLLBAR_BUTTON_LEFT, &v->left_button);
        gui_scrollbar_draw_button_style_4(GUI_SCROLLBAR_BUTTON_RIGHT, &v->right_button);
    #endif
        max_width = v->width - v->left_button.width - v->right_button.width;
    }
    else
    {
        max_width = v->width;
    }

    /* Show the scroll button based on range and value */
    r = v->range - v->scale;
#if defined(__MMI_TOUCH_SCREEN__)
    #if defined (__MMI_MAINLCD_128X160__)
        min_width = v->height + 2;
    #else
    min_width = v->height - GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4 * 2 + 3;
    #endif
#endif
    if (min_width > max_width)
    {
        min_width = max_width;
    }
    if (v->scale > 0)
    {
        if (v->range > 0)
        {
            sbutton_width = (v->scale * max_width) / v->range;
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
        /* In case of very large r & v->value */
        sb_x = (S32) ((S64) sb_xrange * v->value / r);
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

#ifdef __MMI_TOUCH_SCREEN__
    v->pen_state.remain_space = (S16) sb_xrange;
#endif

    v->scroll_button.width = sbutton_width;
    v->scroll_button.x = sb_x + x1 + (buttons_flag ? v->left_button.width : 0);
    gdi_lcd_get_active(&gdi_lcd_layer);
#ifdef __MMI_SUBLCD__
    if (gdi_lcd_layer == GDI_LCD_SUB_LCD_HANDLE)
    {
        gui_scrollbar_draw_button_style2_style_4(GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL, &v->scroll_button);
    }
    else
#endif
    {
    if (buttons_flag)
    {
        gui_scrollbar_draw_region_style_4(
            GUI_SCROLLBAR_REGION_HORIZONTAL,
            v->left_button.x + v->left_button.width,
            v->y,
            v->right_button.x - v->left_button.x - v->left_button.width,
            v->height,
            &v->scroll_button);
    }
    else
    {
        gui_scrollbar_draw_region_style_4(GUI_SCROLLBAR_REGION_HORIZONTAL, v->x, v->y, v->width, v->height, &v->scroll_button);
    }
    gui_scrollbar_draw_button_style_4(GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL, &v->scroll_button);
    }

    gui_horizontal_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);

}


/*****************************************************************************
 * FUNCTION
*  gui_vertical_scrollbar_redraw_button_style_4
* DESCRIPTION
*  Redraw the vertical scrollbar button
* PARAMETERS
*  v       [IN/OUT]            Is the vertical scrollbar object
* RETURNS
*  void
*****************************************************************************/
void gui_vertical_scrollbar_redraw_button_style_4(vertical_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        return;
    }

    old_lcd_handle = gui_vertical_scrollbar_setup_target_lcd_and_layer(v);

    if (type == GUI_SCROLLBAR_BUTTON_UP)
    {
        if (pressed == MMI_TRUE)
        {
            v->up_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        }
        else
        {
            v->up_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        }

#if defined(__MMI_TOUCH_SCREEN__)
        gui_scrollbar_draw_button_style_4(GUI_SCROLLBAR_BUTTON_UP, &v->up_button);
#endif
    }
    else if (type == GUI_SCROLLBAR_BUTTON_DOWN)
    {
        if (pressed == MMI_TRUE)
        {
            v->down_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        }
        else
        {
            v->down_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        }
#if defined(__MMI_TOUCH_SCREEN__)
        gui_scrollbar_draw_button_style_4(GUI_SCROLLBAR_BUTTON_DOWN, &v->down_button);
#endif
    }

    gui_vertical_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);
}


/*****************************************************************************
* FUNCTION
 *  gui_show_vertical_scrollbar_style_4
 * DESCRIPTION
 *  Displays the vertical scrollbar
 * PARAMETERS
 *  v       [IN/OUT]            Is the vertical scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_vertical_scrollbar_style_4(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, sbutton_height, sb_y, sb_yrange, r, min_height = 0, max_height = 0;
    U8 buttons_flag = 1;
#ifndef __MMI_WALLPAPER_ON_BOTTOM__
    UI_filled_area *f;
#endif
    gdi_handle gdi_lcd_layer;
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/



    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        buttons_flag = 0;
    }

    x1 = v->x;
    x2 = x1 + v->width - 1;
    y1 = v->y;
    y2 = y1 + v->height - 1;

#ifndef __MMI_WALLPAPER_ON_BOTTOM__
    if (v->flags & UI_VERTICAL_SCROLLBAR_STATE_FOCUSSED)
    {
        f = v->focussed_bar_filler;
    }
    else if (v->flags & UI_VERTICAL_SCROLLBAR_STATE_DISABLED)
    {
        f = v->disabled_bar_filler;
    }
    else
    {
        f = v->normal_bar_filler;
    }
#endif

    old_lcd_handle = gui_vertical_scrollbar_setup_target_lcd_and_layer(v);
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_and_set_clip(x1, y1, x2, y2);
    }
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {
        BOOL source_key_enable;
        gdi_color source_key_value;

        gdi_layer_get_source_key(&source_key_enable, &source_key_value);
        if (v->hide_callback)
        {
            v->hide_callback(x1, y1, x2, y2);
        }
        else if(!(v->flags & UI_VERTICAL_SCROLLBAR_NOT_CLEAR_BACKGROUND))
        {
            if ((wgui_is_wallpaper_on_bottom() == MMI_TRUE) && source_key_enable)
            {
                gdi_draw_solid_rect(x1, y1, x2, y2, source_key_value);
            }
            else
            {
            /*
            * Tricky to handle scrollbar background here!
            *
            * Some screens like Obigo or Jataayu WAP disable source key of layer,
            * and WAP typically uses white background.
            *
            * If we use 'gui_draw_filled_area(x1, y1, x2, y2, f);' instead, it may
            * produce weird display with inappropriate scrollbar background color
            * created by MCT or PhoneSuite (Downloadable theme)
            *
            * We decide not to change WAP code, but use white color here for
            * __MMI_WALLPAPER_ON_BOTTOM__ (> 240x320 screen)
            *
                */
                gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
            }
        }

    }
#else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
    gui_draw_filled_area(x1, y1, x2, y2, f);
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }

    if (buttons_flag)
    {
    #if defined(__MMI_TOUCH_SCREEN__)
        gui_scrollbar_draw_button_style_4(GUI_SCROLLBAR_BUTTON_UP, &v->up_button);
        gui_scrollbar_draw_button_style_4(GUI_SCROLLBAR_BUTTON_DOWN, &v->down_button);
    #endif
        max_height = v->height - v->up_button.height - v->down_button.height;
    }
    else
    {
        max_height = v->height;
    }
    /* Show the scroll button based on range and value */
    r = v->range - v->scale;
#if defined(__MMI_TOUCH_SCREEN__)
    #if defined (__MMI_MAINLCD_128X160__)
        min_height = v->width + 2;
    #else
    min_height = v->width - GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE4 * 2 + 3;
    #endif
#else
    min_height = v->width - GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP_STYLE4 * 2 + 3;
#endif
    if (min_height > max_height)
    {
        min_height = max_height;
    }
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
        /* In case of very large r & v->value */
        sb_y = (S32) ((S64) sb_yrange * v->value / r);
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

#ifdef __MMI_TOUCH_SCREEN__
    v->pen_state.remain_space = (S16) sb_yrange;
#endif

    v->scroll_button.height = sbutton_height;
    v->scroll_button.y = sb_y + y1 + (buttons_flag ? v->up_button.height : 0);
    if (v->flags & UI_VERTICAL_SCROLLBAR_DISABLE_DRAG)
    {
        v->scroll_button.flags |= UI_BUTTON_DISABLE_DRAG;
    }
    
    gdi_lcd_get_active(&gdi_lcd_layer);
#ifdef __MMI_SUBLCD__
    if (gdi_lcd_layer == GDI_LCD_SUB_LCD_HANDLE)
    {
        gui_scrollbar_draw_button_style2_style_4(GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL, &v->scroll_button);
    }
    else
#endif
    {
#ifndef __MMI_MAINLCD_128X64__
    if (buttons_flag)
    {
        gui_scrollbar_draw_region_style_4(
            GUI_SCROLLBAR_REGION_VERTICAL,
            v->x,
            v->up_button.y + v->up_button.height,
            v->width,
            v->down_button.y - v->up_button.y - v->up_button.height,
            &v->scroll_button);
    }
    else
    {
        gui_scrollbar_draw_region_style_4(GUI_SCROLLBAR_REGION_VERTICAL, v->x, v->y, v->width, v->height, &v->scroll_button);
    }
#endif
    gui_scrollbar_draw_button_style_4(GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL, &v->scroll_button);
    }

    gui_vertical_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);

}

#endif

#if defined(UI_SCROLLBAR_STYLE_5) || defined(UI_SCROLLBAR_WIDER_STYLE_5)
/*****************************************************************************
 * FUNCTION
*  gui_horizontal_scrollbar_redraw_button_style_5
* DESCRIPTION
*  Redraw the horizontal scrollbar button
* PARAMETERS
*  v       [IN/OUT]            Is the vertical scrollbar object
* RETURNS
*  void
*****************************************************************************/
void gui_horizontal_scrollbar_redraw_button_style_5(horizontal_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        return;
    }

    old_lcd_handle = gui_horizontal_scrollbar_setup_target_lcd_and_layer(v);

    if (type == GUI_SCROLLBAR_BUTTON_LEFT)
    {
        if (pressed == MMI_TRUE)
        {
            v->left_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        }
        else
        {
            v->left_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        }

        gui_scrollbar_draw_button_style_5(GUI_SCROLLBAR_BUTTON_LEFT, &v->left_button);
    }
    else if (type == GUI_SCROLLBAR_BUTTON_RIGHT)
    {
        if (pressed == MMI_TRUE)
        {
            v->right_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        }
        else
        {
            v->right_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        }
        gui_scrollbar_draw_button_style_5(GUI_SCROLLBAR_BUTTON_RIGHT, &v->right_button);
    }

    gui_horizontal_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);
}


/*****************************************************************************
* FUNCTION
 *  gui_show_horizontal_scrollbar
 * DESCRIPTION
 *  Displays the horizontal scrollbar
 * PARAMETERS
 *  v       [IN/OUT]            Is the horizontal scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_horizontal_scrollbar_style_5(horizontal_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, sbutton_width, sb_x, sb_xrange, r, min_width = 0, max_width = 0;
    U8 buttons_flag = 1;
    UI_filled_area *f;
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_h = v;
    if (v->flags & UI_HORIZONTAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        buttons_flag = 0;
    }

    x1 = v->x;
    x2 = x1 + v->width - 1;
    y1 = v->y;
    y2 = y1 + v->height - 1;

    if (v->flags & UI_HORIZONTAL_SCROLLBAR_STATE_FOCUSSED)
    {
        f = v->focussed_bar_filler;
    }
    else if (v->flags & UI_HORIZONTAL_SCROLLBAR_STATE_DISABLED)
    {
        f = v->disabled_bar_filler;
    }
    else
    {
        f = v->normal_bar_filler;
    }

    old_lcd_handle = gui_horizontal_scrollbar_setup_target_lcd_and_layer(v);

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_and_set_clip(x1, y1, x2, y2);
    }
    /* Style 3 use three image to compose scrollbar background */
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {
        BOOL source_key_enable;
        gdi_color source_key_value;

        gdi_layer_get_source_key(&source_key_enable, &source_key_value);
        if (v->hide_callback)
        {
            v->hide_callback(x1, y1, x2, y2);
        }
        else if(!(v->flags & UI_HORIZONTAL_SCROLLBAR_NOT_CLEAR_BACKGROUND))
        {
            if (source_key_enable)
            {
                gdi_draw_solid_rect(x1, y1, x2, y2, source_key_value);
            }
            else
            {
            /*
            * Please read the description in gui_show_vertical_scrollbar()
                */
                gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
            }
        }

    }
#else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
    gui_draw_filled_area(x1, y1, x2, y2, f);
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }

    if (buttons_flag)
    {
        max_width = v->width - v->left_button.width - v->right_button.width;
    }
    else
    {
        max_width = v->width;
    }

    /* Show the scroll button based on range and value */
    r = v->range - v->scale;
    min_width = gui_scrollbar_get_button_min_size_style_5(GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL, v->height);
    if (min_width > max_width)
    {
        min_width = max_width;
    }
    if (v->scale > 0)
    {
        if (v->range > 0)
        {
            sbutton_width = (v->scale * max_width) / v->range;
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
        /* In case of very large r & v->value */
        sb_x = (S32) ((S64) sb_xrange * v->value / r);
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

#ifdef __MMI_TOUCH_SCREEN__
    v->pen_state.remain_space = (S16) sb_xrange;
#endif

    v->scroll_button.width = sbutton_width;
    v->scroll_button.x = sb_x + x1 + (buttons_flag ? v->left_button.width : 0);
    if (buttons_flag)
    {
        gui_scrollbar_draw_region_style_5(
            GUI_SCROLLBAR_REGION_HORIZONTAL,
            v->x + v->left_button.x + v->left_button.width,
            v->y,
            v->right_button.x - v->left_button.x - v->left_button.width,
            v->height);
    }
    else
    {
        gui_scrollbar_draw_region_style_5(GUI_SCROLLBAR_REGION_HORIZONTAL, v->x, v->y, v->width, v->height);
    }

    if (buttons_flag)
    {
        gui_scrollbar_draw_button_style_5(GUI_SCROLLBAR_BUTTON_LEFT, &v->left_button);
        gui_scrollbar_draw_button_style_5(GUI_SCROLLBAR_BUTTON_RIGHT, &v->right_button);
    }
    gui_scrollbar_draw_button_style_5(GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL, &v->scroll_button);

    gui_horizontal_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);

}


/*****************************************************************************
 * FUNCTION
*  gui_vertical_scrollbar_redraw_button_style_5
* DESCRIPTION
*  Redraw the vertical scrollbar button
* PARAMETERS
*  v       [IN/OUT]            Is the vertical scrollbar object
* RETURNS
*  void
*****************************************************************************/
void gui_vertical_scrollbar_redraw_button_style_5(vertical_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        return;
    }

    old_lcd_handle = gui_vertical_scrollbar_setup_target_lcd_and_layer(v);

    if (type == GUI_SCROLLBAR_BUTTON_UP)
    {
        if (pressed == MMI_TRUE)
        {
            v->up_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        }
        else
        {
            v->up_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        }

        gui_scrollbar_draw_button_style_5(GUI_SCROLLBAR_BUTTON_UP, &v->up_button);
    }
    else if (type == GUI_SCROLLBAR_BUTTON_DOWN)
    {
        if (pressed == MMI_TRUE)
        {
            v->down_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        }
        else
        {
            v->down_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        }
        gui_scrollbar_draw_button_style_5(GUI_SCROLLBAR_BUTTON_DOWN, &v->down_button);
    }

    gui_vertical_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);
}


/*****************************************************************************
* FUNCTION
 *  gui_show_vertical_scrollbar_style_5
 * DESCRIPTION
 *  Displays the vertical scrollbar
 * PARAMETERS
 *  v       [IN/OUT]            Is the vertical scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_vertical_scrollbar_style_5(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, sbutton_height, sb_y, sb_yrange, r, min_height = 0, max_height = 0;
    U8 buttons_flag = 1;
    UI_filled_area *f;
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_v = v;
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        buttons_flag = 0;
    }

    x1 = v->x;
    x2 = x1 + v->width - 1;
    y1 = v->y;
    y2 = y1 + v->height - 1;

    if (v->flags & UI_VERTICAL_SCROLLBAR_STATE_FOCUSSED)
    {
        f = v->focussed_bar_filler;
    }
    else if (v->flags & UI_VERTICAL_SCROLLBAR_STATE_DISABLED)
    {
        f = v->disabled_bar_filler;
    }
    else
    {
        f = v->normal_bar_filler;
    }

    old_lcd_handle = gui_vertical_scrollbar_setup_target_lcd_and_layer(v);

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_and_set_clip(x1, y1, x2, y2);
    }
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {
        BOOL source_key_enable;
        gdi_color source_key_value;

        gdi_layer_get_source_key(&source_key_enable, &source_key_value);
        if (v->hide_callback)
        {
            v->hide_callback(x1, y1, x2, y2);
        }
        else if(!(v->flags & UI_VERTICAL_SCROLLBAR_NOT_CLEAR_BACKGROUND))
        {
            if ((wgui_is_wallpaper_on_bottom() == MMI_TRUE) && source_key_enable)
            {
                gdi_draw_solid_rect(x1, y1, x2, y2, source_key_value);
            }
            else
            {
            /*
            * Tricky to handle scrollbar background here!
            *
            * Some screens like Obigo or Jataayu WAP disable source key of layer,
            * and WAP typically uses white background.
            *
            * If we use 'gui_draw_filled_area(x1, y1, x2, y2, f);' instead, it may
            * produce weird display with inappropriate scrollbar background color
            * created by MCT or PhoneSuite (Downloadable theme)
            *
            * We decide not to change WAP code, but use white color here for
            * __MMI_WALLPAPER_ON_BOTTOM__ (> 240x320 screen)
            *
                */
                gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
            }
        }

    }
#else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
    gui_draw_filled_area(x1, y1, x2, y2, f);
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }

    if (buttons_flag)
    {
        max_height = v->height - v->up_button.height - v->down_button.height;
    }
    else
    {
        max_height = v->height;
    }
    /* Show the scroll button based on range and value */
    r = v->range - v->scale;
    min_height = gui_scrollbar_get_button_min_size_style_5(GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL, v->width);
    if (min_height > max_height)
    {
        min_height = max_height;
    }
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
        /* In case of very large r & v->value */
        sb_y = (S32) ((S64) sb_yrange * v->value / r);
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

#ifdef __MMI_TOUCH_SCREEN__
    v->pen_state.remain_space = (S16) sb_yrange;
#endif

    v->scroll_button.height = sbutton_height;
    v->scroll_button.y = sb_y + y1 + (buttons_flag ? v->up_button.height : 0);
    if (buttons_flag)
    {
        gui_scrollbar_draw_region_style_5(
            GUI_SCROLLBAR_REGION_VERTICAL,
            v->x,
            v->up_button.y + v->up_button.height,
            v->width,
            v->down_button.y - v->up_button.y - v->up_button.height);
    }
    else
    {
        gui_scrollbar_draw_region_style_5(GUI_SCROLLBAR_REGION_VERTICAL, v->x, v->y, v->width, v->height);
    }

    if (buttons_flag)
    {
        gui_scrollbar_draw_button_style_5(GUI_SCROLLBAR_BUTTON_UP, &v->up_button);
        gui_scrollbar_draw_button_style_5(GUI_SCROLLBAR_BUTTON_DOWN, &v->down_button);
    }

    gui_scrollbar_draw_button_style_5(GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL, &v->scroll_button);

    gui_vertical_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);
}
#endif

#if defined(UI_SCROLLBAR_STYLE_6) || defined(UI_SCROLLBAR_WIDER_STYLE_6)
/*****************************************************************************
 * FUNCTION
*  gui_horizontal_scrollbar_redraw_button
* DESCRIPTION
*  Redraw the horizontal scrollbar button
* PARAMETERS
*  v       [IN/OUT]            Is the vertical scrollbar object
* RETURNS
*  void
*****************************************************************************/
void gui_horizontal_scrollbar_redraw_button_style_6(horizontal_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        return;
    }

    old_lcd_handle = gui_horizontal_scrollbar_setup_target_lcd_and_layer(v);

    if (type == GUI_SCROLLBAR_BUTTON_LEFT)
    {
        if (pressed == MMI_TRUE)
        {
            v->left_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        }
        else
        {
            v->left_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        }

#if defined(__MMI_TOUCH_SCREEN__)
        gui_scrollbar_draw_button_style_6(GUI_SCROLLBAR_BUTTON_LEFT, &v->left_button);
#endif
    }
    else if (type == GUI_SCROLLBAR_BUTTON_RIGHT)
    {
        if (pressed == MMI_TRUE)
        {
            v->right_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        }
        else
        {
            v->right_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        }
#if defined(__MMI_TOUCH_SCREEN__)
        gui_scrollbar_draw_button_style_6(GUI_SCROLLBAR_BUTTON_RIGHT, &v->right_button);
#endif
    }

    gui_horizontal_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);

}


/*****************************************************************************
* FUNCTION
 *  gui_show_horizontal_scrollbar
 * DESCRIPTION
 *  Displays the horizontal scrollbar
 * PARAMETERS
 *  v       [IN/OUT]            Is the horizontal scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_horizontal_scrollbar_style_6(horizontal_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, sbutton_width, sb_x, sb_xrange, r, min_width = 0, max_width = 0;
    U8 buttons_flag = 1;
    UI_filled_area *f;
    gdi_handle gdi_lcd_layer;
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_HORIZONTAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        buttons_flag = 0;
    }

    current_h = v;

    x1 = v->x;
    x2 = x1 + v->width - 1;
    y1 = v->y;
    y2 = y1 + v->height - 1;

    if (v->flags & UI_HORIZONTAL_SCROLLBAR_STATE_FOCUSSED)
    {
        f = v->focussed_bar_filler;
    }
    else if (v->flags & UI_HORIZONTAL_SCROLLBAR_STATE_DISABLED)
    {
        f = v->disabled_bar_filler;
    }
    else
    {
        f = v->normal_bar_filler;
    }

    old_lcd_handle = gui_horizontal_scrollbar_setup_target_lcd_and_layer(v);

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_and_set_clip(x1, y1, x2, y2);
    }
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {
        BOOL source_key_enable;
        gdi_color source_key_value;

        gdi_layer_get_source_key(&source_key_enable, &source_key_value);
        if (v->hide_callback)
        {
            v->hide_callback(x1, y1, x2, y2);
        }
        else if(!(v->flags & UI_HORIZONTAL_SCROLLBAR_NOT_CLEAR_BACKGROUND))
        {
            if ((wgui_is_wallpaper_on_bottom() == MMI_TRUE) && source_key_enable)
            {
                gdi_draw_solid_rect(x1, y1, x2, y2, source_key_value);
            }
            else
            {
            /*
            * Tricky to handle scrollbar background here!
            *
            * Some screens like Obigo or Jataayu WAP disable source key of layer,
            * and WAP typically uses white background.
            *
            * If we use 'gui_draw_filled_area(x1, y1, x2, y2, f);' instead, it may
            * produce weird display with inappropriate scrollbar background color
            * created by MCT or PhoneSuite (Downloadable theme)
            *
            * We decide not to change WAP code, but use white color here for
            * __MMI_WALLPAPER_ON_BOTTOM__ (> 240x320 screen)
            *
                */
                gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
            }
        }

    }
#else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
        gui_draw_filled_area(x1, y1, x2, y2, f);
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }

    if (buttons_flag)
    {
    #if defined(__MMI_TOUCH_SCREEN__)
        gui_scrollbar_draw_button_style_6(GUI_SCROLLBAR_BUTTON_LEFT, &v->left_button);
        gui_scrollbar_draw_button_style_6(GUI_SCROLLBAR_BUTTON_RIGHT, &v->right_button);
    #endif
        max_width = v->width - v->left_button.width - v->right_button.width;
    }
    else
    {
        max_width = v->width;
    }

    /* Show the scroll button based on range and value */
    r = v->range - v->scale;
#if defined(__MMI_TOUCH_SCREEN__)
    #if defined (__MMI_MAINLCD_128X160__)
        min_width = v->height + 2;
    #else
    min_width = v->height - GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE6 * 2 + 3;
    #endif
#endif
    if (min_width > max_width)
    {
        min_width = max_width;
    }
    if (v->scale > 0)
    {
        if (v->range > 0)
        {
            sbutton_width = (v->scale * max_width) / v->range;
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
        /* In case of very large r & v->value */
        sb_x = (S32) ((S64) sb_xrange * v->value / r);
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

#ifdef __MMI_TOUCH_SCREEN__
    v->pen_state.remain_space = (S16) sb_xrange;
#endif

    v->scroll_button.width = sbutton_width;
    v->scroll_button.x = sb_x + x1 + (buttons_flag ? v->left_button.width : 0);
    gdi_lcd_get_active(&gdi_lcd_layer);
    if (gdi_lcd_layer == GDI_LCD_SUB_LCD_HANDLE)
    {
        gui_scrollbar_draw_button_style2_style_6(GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL, &v->scroll_button);
    }
    else
    {
        if (buttons_flag)
        {
            gui_scrollbar_draw_region_style_6(
                GUI_SCROLLBAR_REGION_HORIZONTAL,
                v->left_button.x + v->left_button.width,
                v->y,
                v->right_button.x - v->left_button.x - v->left_button.width,
                v->height,
                &v->scroll_button);
        }
        else
        {
            gui_scrollbar_draw_region_style_6(GUI_SCROLLBAR_REGION_HORIZONTAL, v->x, v->y, v->width, v->height, &v->scroll_button);
        }
        if (!(v->flags & UI_HORIZONTAL_SCROLLBAR_AUTO_HIDE_SCROLL_BUTTON) ||
            (max_width > v->scroll_button.width))
        {
            gui_scrollbar_draw_button_style_6(GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL, &v->scroll_button);
        }
    }

    gui_horizontal_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);

}


/*****************************************************************************
 * FUNCTION
*  gui_vertical_scrollbar_redraw_button_style_4
* DESCRIPTION
*  Redraw the vertical scrollbar button
* PARAMETERS
*  v       [IN/OUT]            Is the vertical scrollbar object
* RETURNS
*  void
*****************************************************************************/
void gui_vertical_scrollbar_redraw_button_style_6(vertical_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        return;
    }

    old_lcd_handle = gui_vertical_scrollbar_setup_target_lcd_and_layer(v);

    if (type == GUI_SCROLLBAR_BUTTON_UP)
    {
        if (pressed == MMI_TRUE)
        {
            v->up_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        }
        else
        {
            v->up_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        }

#if defined(__MMI_TOUCH_SCREEN__)
        gui_scrollbar_draw_button_style_6(GUI_SCROLLBAR_BUTTON_UP, &v->up_button);
#endif
    }
    else if (type == GUI_SCROLLBAR_BUTTON_DOWN)
    {
        if (pressed == MMI_TRUE)
        {
            v->down_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        }
        else
        {
            v->down_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        }
#if defined(__MMI_TOUCH_SCREEN__)
        gui_scrollbar_draw_button_style_6(GUI_SCROLLBAR_BUTTON_DOWN, &v->down_button);
#endif
    }

    gui_vertical_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);

}


/*****************************************************************************
* FUNCTION
 *  gui_show_vertical_scrollbar_style_4
 * DESCRIPTION
 *  Displays the vertical scrollbar
 * PARAMETERS
 *  v       [IN/OUT]            Is the vertical scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_vertical_scrollbar_style_6(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, sbutton_height, sb_y, sb_yrange, r, min_height = 0, max_height = 0;
    U8 buttons_flag = 1;
    UI_filled_area *f;
    gdi_handle gdi_lcd_layer;
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        buttons_flag = 0;
    }

    current_v = v;

    x1 = v->x;
    x2 = x1 + v->width - 1;
    y1 = v->y;
    y2 = y1 + v->height - 1;

    if (v->flags & UI_VERTICAL_SCROLLBAR_STATE_FOCUSSED)
    {
        f = v->focussed_bar_filler;
    }
    else if (v->flags & UI_VERTICAL_SCROLLBAR_STATE_DISABLED)
    {
        f = v->disabled_bar_filler;
    }
    else
    {
        f = v->normal_bar_filler;
    }

    old_lcd_handle = gui_vertical_scrollbar_setup_target_lcd_and_layer(v);

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_and_set_clip(x1, y1, x2, y2);
    }
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {
        BOOL source_key_enable;
        gdi_color source_key_value;

        gdi_layer_get_source_key(&source_key_enable, &source_key_value);
        if (v->hide_callback)
        {
            v->hide_callback(x1, y1, x2, y2);
        }
        else if(!(v->flags & UI_VERTICAL_SCROLLBAR_NOT_CLEAR_BACKGROUND))
        {
            if ((wgui_is_wallpaper_on_bottom() == MMI_TRUE) && source_key_enable)
            {
                gdi_draw_solid_rect(x1, y1, x2, y2, source_key_value);
            }
            else
            {
            /*
            * Tricky to handle scrollbar background here!
            *
            * Some screens like Obigo or Jataayu WAP disable source key of layer,
            * and WAP typically uses white background.
            *
            * If we use 'gui_draw_filled_area(x1, y1, x2, y2, f);' instead, it may
            * produce weird display with inappropriate scrollbar background color
            * created by MCT or PhoneSuite (Downloadable theme)
            *
            * We decide not to change WAP code, but use white color here for
            * __MMI_WALLPAPER_ON_BOTTOM__ (> 240x320 screen)
            *
                */
                gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
            }
        }

    }
#else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
    gui_draw_filled_area(x1, y1, x2, y2, f);
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }

    if (buttons_flag)
    {
    #if defined(__MMI_TOUCH_SCREEN__)
        gui_scrollbar_draw_button_style_6(GUI_SCROLLBAR_BUTTON_UP, &v->up_button);
        gui_scrollbar_draw_button_style_6(GUI_SCROLLBAR_BUTTON_DOWN, &v->down_button);
    #endif
        max_height = v->height - v->up_button.height - v->down_button.height;
    }
    else
    {
        max_height = v->height;
    }
    /* Show the scroll button based on range and value */
    r = v->range - v->scale;
#if defined(__MMI_TOUCH_SCREEN__)
    #if defined (__MMI_MAINLCD_128X160__)
        min_height = v->width + 2;
    #else
    min_height = v->width - GUI_SCROLLBAR_STYLE4_TOUCH_GAP_STYLE6 * 2 + 3;
    #endif
#else
    min_height = v->width - GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP_STYLE6 * 2 + 3;
#endif
    if (min_height > max_height)
    {
        min_height = max_height;
    }
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
        /* In case of very large r & v->value */
        sb_y = (S32) ((S64) sb_yrange * v->value / r);
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

#ifdef __MMI_TOUCH_SCREEN__
    v->pen_state.remain_space = (S16) sb_yrange;
#endif

    v->scroll_button.height = sbutton_height;
    v->scroll_button.y = sb_y + y1 + (buttons_flag ? v->up_button.height : 0);
    gdi_lcd_get_active(&gdi_lcd_layer);
    if (gdi_lcd_layer == GDI_LCD_SUB_LCD_HANDLE)
    {
        gui_scrollbar_draw_button_style2_style_6(GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL, &v->scroll_button);
    }
    else
    {
        if (buttons_flag)
        {
            gui_scrollbar_draw_region_style_6(
                GUI_SCROLLBAR_REGION_VERTICAL,
                v->x,
                v->up_button.y + v->up_button.height,
                v->width,
                v->down_button.y - v->up_button.y - v->up_button.height,
                &v->scroll_button);
        }
        else
        {
            gui_scrollbar_draw_region_style_6(GUI_SCROLLBAR_REGION_VERTICAL, v->x, v->y, v->width, v->height, &v->scroll_button);
        }
        if (!(v->flags & UI_VERTICAL_SCROLLBAR_AUTO_HIDE_SCROLL_BUTTON) ||
            (max_height > v->scroll_button.height))
        {
            gui_scrollbar_draw_button_style_6(GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL, &v->scroll_button);
        }
    }

    gui_vertical_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);

}

#endif

#if defined(UI_SCROLLBAR_STYLE_8)

/*****************************************************************************
 * FUNCTION
*  gui_horizontal_scrollbar_redraw_button_style_VFR
* DESCRIPTION
*  Redraw the horizontal scrollbar button
* PARAMETERS
*  v       [IN/OUT]            Is the vertical scrollbar object
* RETURNS
*  void
*****************************************************************************/
void gui_horizontal_scrollbar_redraw_button_style_VFR(horizontal_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        return;
    }

    old_lcd_handle = gui_horizontal_scrollbar_setup_target_lcd_and_layer(v);

    if (type == GUI_SCROLLBAR_BUTTON_LEFT)
    {
        if (pressed == MMI_TRUE)
        {
            v->left_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        }
        else
        {
            v->left_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        }

        gui_scrollbar_draw_button_style_8(GUI_SCROLLBAR_BUTTON_LEFT, &v->left_button);
    }
    else if (type == GUI_SCROLLBAR_BUTTON_RIGHT)
    {
        if (pressed == MMI_TRUE)
        {
            v->right_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        }
        else
        {
            v->right_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        }
        gui_scrollbar_draw_button_style_8(GUI_SCROLLBAR_BUTTON_RIGHT, &v->right_button);
    }

    gui_horizontal_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);

}


/*****************************************************************************
* FUNCTION
 *  gui_show_horizontal_scrollbar_style_VFR
 * DESCRIPTION
 *  Displays the horizontal scrollbar
 * PARAMETERS
 *  v       [IN/OUT]            Is the horizontal scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_horizontal_scrollbar_style_VFR(horizontal_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, sbutton_width, sb_x, sb_xrange, r, min_width = 0, max_width = 0;
    U8 buttons_flag = 1;
    UI_filled_area *f;
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_HORIZONTAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        buttons_flag = 0;
    }

    x1 = v->x;
    x2 = x1 + v->width - 1;
    y1 = v->y;
    y2 = y1 + v->height - 1;

    if (v->flags & UI_HORIZONTAL_SCROLLBAR_STATE_FOCUSSED)
    {
        f = v->focussed_bar_filler;
    }
    else if (v->flags & UI_HORIZONTAL_SCROLLBAR_STATE_DISABLED)
    {
        f = v->disabled_bar_filler;
    }
    else
    {
        f = v->normal_bar_filler;
    }

    old_lcd_handle = gui_horizontal_scrollbar_setup_target_lcd_and_layer(v);

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_and_set_clip(x1, y1, x2, y2);
    }
    /* Style 3 use three image to compose scrollbar background */
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {
        BOOL source_key_enable;
        gdi_color source_key_value;

        gdi_layer_get_source_key(&source_key_enable, &source_key_value);
        if (v->hide_callback)
        {
            v->hide_callback(x1, y1, x2, y2);
        }
        else if(!(v->flags & UI_HORIZONTAL_SCROLLBAR_NOT_CLEAR_BACKGROUND))
        {
            if (source_key_enable)
            {
                gdi_draw_solid_rect(x1, y1, x2, y2, source_key_value);
            }
            else
            {
            /*
            * Please read the description in gui_show_vertical_scrollbar()
                */
                gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
            }
        }

    }
#else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
    gui_draw_filled_area(x1, y1, x2, y2, f);
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }

    if (buttons_flag)
    {
        max_width = v->width - v->left_button.width - v->right_button.width;
    }
    else
    {
        max_width = v->width;
    }

    /* Show the scroll button based on range and value */
    r = v->range - v->scale;
    min_width = gui_scrollbar_get_button_min_size_style_8(GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL, v->height);
    if (min_width > max_width)
    {
        min_width = max_width;
    }
    if (v->scale > 0)
    {
        if (v->range > 0)
        {
            sbutton_width = (v->scale * max_width) / v->range;
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
        /* In case of very large r & v->value */
        sb_x = (S32) ((S64) sb_xrange * v->value / r);
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

#ifdef __MMI_TOUCH_SCREEN__
    v->pen_state.remain_space = (S16) sb_xrange;
#endif

    v->scroll_button.width = sbutton_width;
    v->scroll_button.x = sb_x + x1 + (buttons_flag ? v->left_button.width : 0);
    if (buttons_flag)
    {
        gui_scrollbar_draw_region_style_8(
            GUI_SCROLLBAR_REGION_HORIZONTAL,
            v->x + v->left_button.x + v->left_button.width,
            v->y,
            v->right_button.x - v->left_button.x - v->left_button.width,
            v->height);
    }
    else
    {
        gui_scrollbar_draw_region_style_8(GUI_SCROLLBAR_REGION_HORIZONTAL, v->x, v->y, v->width, v->height);
    }

    if (buttons_flag)
    {
        gui_scrollbar_draw_button_style_8(GUI_SCROLLBAR_BUTTON_LEFT, &v->left_button);
        gui_scrollbar_draw_button_style_8(GUI_SCROLLBAR_BUTTON_RIGHT, &v->right_button);
    }
    gui_scrollbar_draw_button_style_8(GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL, &v->scroll_button);

    gui_horizontal_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);

}


/*****************************************************************************
 * FUNCTION
*  gui_vertical_scrollbar_redraw_button_style_VFR
* DESCRIPTION
*  Redraw the vertical scrollbar button
* PARAMETERS
*  v       [IN/OUT]            Is the vertical scrollbar object
* RETURNS
*  void
*****************************************************************************/
void gui_vertical_scrollbar_redraw_button_style_VFR(vertical_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        return;
    }

    old_lcd_handle = gui_vertical_scrollbar_setup_target_lcd_and_layer(v);

    if (type == GUI_SCROLLBAR_BUTTON_UP)
    {
        if (pressed == MMI_TRUE)
        {
            v->up_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        }
        else
        {
            v->up_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        }

        gui_scrollbar_draw_button_style_8(GUI_SCROLLBAR_BUTTON_UP, &v->up_button);
    }
    else if (type == GUI_SCROLLBAR_BUTTON_DOWN)
    {
        if (pressed == MMI_TRUE)
        {
            v->down_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        }
        else
        {
            v->down_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        }
        gui_scrollbar_draw_button_style_8(GUI_SCROLLBAR_BUTTON_DOWN, &v->down_button);
    }

    gui_vertical_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);

}


/*****************************************************************************
* FUNCTION
 *  gui_show_vertical_scrollbar_style_VFR
 * DESCRIPTION
 *  Displays the vertical scrollbar
 * PARAMETERS
 *  v       [IN/OUT]            Is the vertical scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_vertical_scrollbar_style_VFR(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, sbutton_height, sb_y, sb_yrange, r, min_height = 0, max_height = 0;
    U8 buttons_flag = 1;
    UI_filled_area *f;
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        buttons_flag = 0;
    }

    x1 = v->x;
    x2 = x1 + v->width - 1;
    y1 = v->y;
    y2 = y1 + v->height - 1;

    if (v->flags & UI_VERTICAL_SCROLLBAR_STATE_FOCUSSED)
    {
        f = v->focussed_bar_filler;
    }
    else if (v->flags & UI_VERTICAL_SCROLLBAR_STATE_DISABLED)
    {
        f = v->disabled_bar_filler;
    }
    else
    {
        f = v->normal_bar_filler;
    }

    old_lcd_handle = gui_vertical_scrollbar_setup_target_lcd_and_layer(v);

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_and_set_clip(x1, y1, x2, y2);
    }
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {
        BOOL source_key_enable;
        gdi_color source_key_value;

        gdi_layer_get_source_key(&source_key_enable, &source_key_value);
        if (g_mmi_gui_scrollbar_src_layer == GDI_NULL_HANDLE)
        {
            if (v->hide_callback)
            {
                v->hide_callback(x1, y1, x2, y2);
            }
            else if(!(v->flags & UI_VERTICAL_SCROLLBAR_NOT_CLEAR_BACKGROUND))
            {
                if ((wgui_is_wallpaper_on_bottom() == MMI_TRUE) && source_key_enable)
                {
                    gdi_draw_solid_rect(x1, y1, x2, y2, source_key_value);
                }
                else
                {
                /*
                * Tricky to handle scrollbar background here!
                *
                * Some screens like Obigo or Jataayu WAP disable source key of layer,
                * and WAP typically uses white background.
                *
                * If we use 'gui_draw_filled_area(x1, y1, x2, y2, f);' instead, it may
                * produce weird display with inappropriate scrollbar background color
                * created by MCT or PhoneSuite (Downloadable theme)
                *
                * We decide not to change WAP code, but use white color here for
                * __MMI_WALLPAPER_ON_BOTTOM__ (> 240x320 screen)
                *
                    */
                    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
                }
            }

        }
    }
#else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
    gui_draw_filled_area(x1, y1, x2, y2, f);
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }

    if (buttons_flag)
    {
        max_height = v->height - v->up_button.height - v->down_button.height;
    }
    else
    {
        max_height = v->height;
    }
    /* Show the scroll button based on range and value */
    r = v->range - v->scale;
    min_height = gui_scrollbar_get_button_min_size_style_8(GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL, v->width);
    if (min_height > max_height)
    {
        min_height = max_height;
    }
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
        /* In case of very large r & v->value */
        sb_y = (S32) ((S64) sb_yrange * v->value / r);
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

#ifdef __MMI_TOUCH_SCREEN__
    v->pen_state.remain_space = (S16) sb_yrange;
#endif

    v->scroll_button.height = sbutton_height;
    v->scroll_button.y = sb_y + y1 + (buttons_flag ? v->up_button.height : 0);
    if (buttons_flag)
    {
        gui_scrollbar_draw_region_style_8(
            GUI_SCROLLBAR_REGION_VERTICAL,
            v->x,
            v->up_button.y + v->up_button.height,
            v->width,
            v->down_button.y - v->up_button.y - v->up_button.height);
    }
    else
    {
        gui_scrollbar_draw_region_style_8(GUI_SCROLLBAR_REGION_VERTICAL, v->x, v->y, v->width, v->height);
    }

    if (buttons_flag)
    {
        gui_scrollbar_draw_button_style_8(GUI_SCROLLBAR_BUTTON_UP, &v->up_button);
        gui_scrollbar_draw_button_style_8(GUI_SCROLLBAR_BUTTON_DOWN, &v->down_button);
    }

    gui_scrollbar_draw_button_style_8(GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL, &v->scroll_button);

    gui_vertical_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);

}
#endif

#if defined(UI_SCROLLBAR_STYLE_7) || defined(UI_SCROLLBAR_WIDER_STYLE_7)

/*****************************************************************************
 * FUNCTION
*  gui_horizontal_scrollbar_redraw_button_style_7
* DESCRIPTION
*  Redraw the horizontal scrollbar button
* PARAMETERS
*  v       [IN/OUT]            Is the vertical scrollbar object
* RETURNS
*  void
*****************************************************************************/
void gui_horizontal_scrollbar_redraw_button_style_7(horizontal_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        return;
    }

    old_lcd_handle = gui_horizontal_scrollbar_setup_target_lcd_and_layer(v);

    if (type == GUI_SCROLLBAR_BUTTON_LEFT)
    {
        if (pressed == MMI_TRUE)
        {
            v->left_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        }
        else
        {
            v->left_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        }

        gui_scrollbar_draw_button_style_7(GUI_SCROLLBAR_BUTTON_LEFT, &v->left_button);
    }
    else if (type == GUI_SCROLLBAR_BUTTON_RIGHT)
    {
        if (pressed == MMI_TRUE)
        {
            v->right_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        }
        else
        {
            v->right_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        }
        gui_scrollbar_draw_button_style_7(GUI_SCROLLBAR_BUTTON_RIGHT, &v->right_button);
    }

    gui_horizontal_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);

}


/*****************************************************************************
* FUNCTION
 *  gui_show_horizontal_scrollbar_style_7
 * DESCRIPTION
 *  Displays the horizontal scrollbar
 * PARAMETERS
 *  v       [IN/OUT]            Is the horizontal scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_horizontal_scrollbar_style_7(horizontal_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, sbutton_width, sb_x, sb_xrange, r, min_width = 0, max_width = 0;
    U8 buttons_flag = 1;
    UI_filled_area *f;
    MMI_BOOL result = MMI_FALSE;
    gdi_handle old_lcd_handle;
    S32 offset_x, offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_HORIZONTAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        buttons_flag = 0;
    }

    old_lcd_handle = gui_horizontal_scrollbar_setup_target_lcd_and_layer(v);
    gdi_layer_get_position(&offset_x, &offset_y);
    x1 = v->x - offset_x;
    x2 = x1 + v->width - 1;
    y1 = v->y - offset_y;
    y2 = y1 + v->height - 1;

    if (v->flags & UI_HORIZONTAL_SCROLLBAR_STATE_FOCUSSED)
    {
        f = v->focussed_bar_filler;
    }
    else if (v->flags & UI_HORIZONTAL_SCROLLBAR_STATE_DISABLED)
    {
        f = v->disabled_bar_filler;
    }
    else
    {
        f = v->normal_bar_filler;
    }
    
    if (buttons_flag)
    {
        max_width = v->width - v->left_button.width - v->right_button.width;
    }
    else
    {
        max_width = v->width;
    }
    
    /* Show the scroll button based on range and value */
    r = v->range - v->scale;
    min_width = gui_scrollbar_get_button_min_size_style_7(GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL, v->height);
    if (min_width > max_width)
    {
        min_width = max_width;
    }
    if (v->scale > 0)
    {
        if (v->range > 0)
        {
            sbutton_width = (v->scale * max_width) / v->range;
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
        /* In case of very large r & v->value */
        sb_x = (S32) ((S64) sb_xrange * v->value / r);
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
    
#ifdef __MMI_TOUCH_SCREEN__
    v->pen_state.remain_space = (S16) sb_xrange;
#endif
    
    v->scroll_button.width = sbutton_width;
    v->scroll_button.x = sb_x + x1 + (buttons_flag ? v->left_button.width : 0);

    gui_push_clip();

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_set_clip(x1, y1, x2, y2);
    }
    else
    {
        result = gui_scrollbar_set_clip_intersect(x1, y1, x2, y2);
    }

    /* Style 3 use three image to compose scrollbar background */
    if (gui_scrollbar_redraw_clip_enable || (!gui_scrollbar_redraw_clip_enable && result))
    {
    #if defined(__MMI_WALLPAPER_ON_BOTTOM__)
        if (!(v->flags & UI_HORIZONTAL_SCROLLBAR_AUTO_HIDE_SCROLL_BUTTON) ||
           (max_width > v->scroll_button.width))
        {
            BOOL source_key_enable;
            gdi_color source_key_value;

            gdi_layer_get_source_key(&source_key_enable, &source_key_value);
            if (v->hide_callback)
            {
                v->hide_callback(x1, y1, x2, y2);
            }
            else if(!(v->flags & UI_HORIZONTAL_SCROLLBAR_NOT_CLEAR_BACKGROUND))
            {
                if (source_key_enable)
                {
                    gdi_draw_solid_rect(x1, y1, x2, y2, source_key_value);
                }
                else
                {
                /*
                * Please read the description in gui_show_vertical_scrollbar()
                    */
                    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
                }

            }
        }
    #else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
        if (!(v->flags & UI_HORIZONTAL_SCROLLBAR_AUTO_HIDE_SCROLL_BUTTON) ||
           (max_width > v->scroll_button.width))
        {
            gui_draw_filled_area(x1, y1, x2, y2, f);
        }
        
    #endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */

    }

    gui_pop_clip();

    if (buttons_flag)
    {
        gui_scrollbar_draw_button_style_7(GUI_SCROLLBAR_BUTTON_LEFT, &v->left_button);
        gui_scrollbar_draw_button_style_7(GUI_SCROLLBAR_BUTTON_RIGHT, &v->right_button);
    }
    
    if (!(v->flags & UI_HORIZONTAL_SCROLLBAR_AUTO_HIDE_SCROLL_BUTTON) ||
        (max_width > v->scroll_button.width))
    {
        gui_scrollbar_draw_button_style_7(GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL, &v->scroll_button);
    }
    gui_horizontal_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);

}


/*****************************************************************************
 * FUNCTION
*  gui_vertical_scrollbar_redraw_button_style_7
* DESCRIPTION
*  Redraw the vertical scrollbar button
* PARAMETERS
*  v       [IN/OUT]            Is the vertical scrollbar object
* RETURNS
*  void
*****************************************************************************/
void gui_vertical_scrollbar_redraw_button_style_7(vertical_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        return;
    }

    old_lcd_handle = gui_vertical_scrollbar_setup_target_lcd_and_layer(v);

    if (type == GUI_SCROLLBAR_BUTTON_UP)
    {
        if (pressed == MMI_TRUE)
        {
            v->up_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        }
        else
        {
            v->up_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        }

        gui_scrollbar_draw_button_style_7(GUI_SCROLLBAR_BUTTON_UP, &v->up_button);
    }
    else if (type == GUI_SCROLLBAR_BUTTON_DOWN)
    {
        if (pressed == MMI_TRUE)
        {
            v->down_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        }
        else
        {
            v->down_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        }
        gui_scrollbar_draw_button_style_7(GUI_SCROLLBAR_BUTTON_DOWN, &v->down_button);
    }

    gui_vertical_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);

}


/*****************************************************************************
* FUNCTION
 *  gui_show_vertical_scrollbar_style_7
 * DESCRIPTION
 *  Displays the vertical scrollbar
 * PARAMETERS
 *  v       [IN/OUT]            Is the vertical scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_vertical_scrollbar_style_7(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, sbutton_height, sb_y, sb_yrange, r, min_height = 0, max_height = 0;
    U8 buttons_flag = 1;
    UI_filled_area *f;
    MMI_BOOL result = MMI_FALSE;
    gdi_handle old_lcd_handle;
    S32 offset_x, offset_y;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        buttons_flag = 0;
    }
    old_lcd_handle = gui_vertical_scrollbar_setup_target_lcd_and_layer(v);
    /* gdi_layer_get_position(&offset_x, &offset_y); */

    x1 = v->x;
    x2 = x1 + v->width - 1;
    y1 = v->y;
    y2 = y1 + v->height - 1;

    if (v->flags & UI_VERTICAL_SCROLLBAR_STATE_FOCUSSED)
    {
        f = v->focussed_bar_filler;
    }
    else if (v->flags & UI_VERTICAL_SCROLLBAR_STATE_DISABLED)
    {
        f = v->disabled_bar_filler;
    }
    else
    {
        f = v->normal_bar_filler;
    }

    if (buttons_flag)
    {
        max_height = v->height - v->up_button.height - v->down_button.height;
    }
    else
    {
        max_height = v->height;
    }
    /* Show the scroll button based on range and value */
    r = v->range - v->scale;
    min_height = gui_scrollbar_get_button_min_size_style_7(GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL, v->width);
    if (min_height > max_height)
    {
        min_height = max_height;
    }
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
        /* In case of very large r & v->value */
        sb_y = (S32) ((S64) sb_yrange * v->value / r);
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
    
#ifdef __MMI_TOUCH_SCREEN__
    v->pen_state.remain_space = (S16) sb_yrange;
#endif
    
    v->scroll_button.height = sbutton_height;
    v->scroll_button.y = sb_y + y1 + (buttons_flag ? v->up_button.height : 0);

    gui_push_clip();

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_set_clip(x1, y1, x2, y2);
    }
    else
    {
        result = gui_scrollbar_set_clip_intersect(x1, y1, x2, y2);
    }

    if (gui_scrollbar_redraw_clip_enable || (!gui_scrollbar_redraw_clip_enable && result))
    {
        #if defined(__MMI_WALLPAPER_ON_BOTTOM__)
        if (!(v->flags & UI_VERTICAL_SCROLLBAR_AUTO_HIDE_SCROLL_BUTTON) || 
           (max_height > v->scroll_button.height))
        {
            BOOL source_key_enable;
            gdi_color source_key_value;

            gdi_layer_get_source_key(&source_key_enable, &source_key_value);

            if (v->hide_callback)
            {
                v->hide_callback(x1, y1, x2, y2);
            }
            else if(!(v->flags & UI_VERTICAL_SCROLLBAR_NOT_CLEAR_BACKGROUND))
            {
                if ((wgui_is_wallpaper_on_bottom() == MMI_TRUE) && source_key_enable)
                {
                    gdi_draw_solid_rect(x1, y1, x2, y2, source_key_value);
                }
                else
                {
                /*
                * Tricky to handle scrollbar background here!
                *
                * Some screens like Obigo or Jataayu WAP disable source key of layer,
                * and WAP typically uses white background.
                *
                * If we use 'gui_draw_filled_area(x1, y1, x2, y2, f);' instead, it may
                * produce weird display with inappropriate scrollbar background color
                * created by MCT or PhoneSuite (Downloadable theme)
                *
                * We decide not to change WAP code, but use white color here for
                * __MMI_WALLPAPER_ON_BOTTOM__ (> 240x320 screen)
                *
                    */
                    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
                }
            }
        }
    #else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
        if (!(v->flags & UI_VERTICAL_SCROLLBAR_AUTO_HIDE_SCROLL_BUTTON) || 
           (max_height > v->scroll_button.height))
        {
            gui_draw_filled_area(x1, y1, x2, y2, f);
        }
        
    #endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */

    }

    gui_pop_clip();

    if (buttons_flag)
    {
        gui_scrollbar_draw_button_style_7(GUI_SCROLLBAR_BUTTON_UP, &v->up_button);
        gui_scrollbar_draw_button_style_7(GUI_SCROLLBAR_BUTTON_DOWN, &v->down_button);
    }

    if (!(v->flags & UI_VERTICAL_SCROLLBAR_AUTO_HIDE_SCROLL_BUTTON) || 
        (max_height > v->scroll_button.height))
    {
        gui_scrollbar_draw_button_style_7(GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL, &v->scroll_button);
    }
    gui_vertical_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);
}


#endif /* UI_SCROLLBAR_STYLE_1 */

#if defined(UI_SCROLLBAR_STYLE_9)

/*****************************************************************************
 * FUNCTION
*  gui_horizontal_scrollbar_redraw_button_style_9
* DESCRIPTION
*  Redraw the horizontal scrollbar button
* PARAMETERS
*  v       [IN/OUT]            Is the vertical scrollbar object
* RETURNS
*  void
*****************************************************************************/
void gui_horizontal_scrollbar_redraw_button_style_9(horizontal_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        return;
    }

    old_lcd_handle = gui_horizontal_scrollbar_setup_target_lcd_and_layer(v);

    if (type == GUI_SCROLLBAR_BUTTON_LEFT)
    {
        if (pressed == MMI_TRUE)
        {
            v->left_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        }
        else
        {
            v->left_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        }

        gui_scrollbar_draw_button_style_9(GUI_SCROLLBAR_BUTTON_LEFT, &v->left_button);
    }
    else if (type == GUI_SCROLLBAR_BUTTON_RIGHT)
    {
        if (pressed == MMI_TRUE)
        {
            v->right_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        }
        else
        {
            v->right_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        }
        gui_scrollbar_draw_button_style_9(GUI_SCROLLBAR_BUTTON_RIGHT, &v->right_button);
    }

    gui_horizontal_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);

}


/*****************************************************************************
* FUNCTION
 *  gui_show_horizontal_scrollbar_style_9
 * DESCRIPTION
 *  Displays the horizontal scrollbar
 * PARAMETERS
 *  v       [IN/OUT]            Is the horizontal scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_horizontal_scrollbar_style_9(horizontal_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, sbutton_width, sb_x, sb_xrange, r, min_width = 0, max_width = 0;
    U8 buttons_flag = 1;
    UI_filled_area *f;
    MMI_BOOL result = MMI_FALSE;
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_HORIZONTAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        buttons_flag = 0;
    }

    old_lcd_handle = gui_horizontal_scrollbar_setup_target_lcd_and_layer(v);
    x1 = v->x;
    x2 = x1 + v->width - 1;
    y1 = v->y;
    y2 = y1 + v->height - 1;

    f = v->normal_bar_filler;
    
    if (buttons_flag)
    {
        max_width = v->width - v->left_button.width - v->right_button.width;
    }
    else
    {
        max_width = v->width;
    }
    
    /* Show the scroll button based on range and value */
    r = v->range - v->scale;
    min_width = gui_scrollbar_get_button_min_size_style_9(GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL, v->height);
    if (min_width > max_width)
    {
        min_width = max_width;
    }
    if (v->scale > 0)
    {
        if (v->range > 0)
        {
            sbutton_width = (v->scale * max_width) / v->range;
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
        /* In case of very large r & v->value */
        sb_x = (S32) ((S64) sb_xrange * v->value / r);
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
    
#ifdef __MMI_TOUCH_SCREEN__
    v->pen_state.remain_space = (S16) sb_xrange;
#endif
    
    v->scroll_button.width = sbutton_width;
    v->scroll_button.x = sb_x + x1 + (buttons_flag ? v->left_button.width : 0);

    gui_push_clip();

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_set_clip(x1, y1, x2, y2);
    }
    else
    {
        result = gui_scrollbar_set_clip_intersect(x1, y1, x2, y2);
    }

    /* Style 3 use three image to compose scrollbar background */
    if (gui_scrollbar_redraw_clip_enable || (!gui_scrollbar_redraw_clip_enable && result))
    {
        if (!(v->flags & UI_HORIZONTAL_SCROLLBAR_AUTO_HIDE_SCROLL_BUTTON) ||
           (max_width > v->scroll_button.width))
        {
            gui_fill_rectangle(x1, y1, x2, y2, f->border_color);

            if(v->height > GUI_SCROLLBAR_MIDDLE_BACKGROUND_WIDTH_STYLE9)
            {
                y1 = y1 + ((v->height + 1)/ 2) - GUI_SCROLLBAR_MIDDLE_BACKGROUND_WIDTH_STYLE9;
                y2 = y1 + GUI_SCROLLBAR_MIDDLE_BACKGROUND_WIDTH_STYLE9;               
                gui_fill_rectangle(x1, y1, x2, y2, f->c);
            }
        }       
    }

    gui_pop_clip();

    if (buttons_flag)
    {
        gui_scrollbar_draw_button_style_9(GUI_SCROLLBAR_BUTTON_LEFT, &v->left_button);
        gui_scrollbar_draw_button_style_9(GUI_SCROLLBAR_BUTTON_RIGHT, &v->right_button);
    }
    
    if (!(v->flags & UI_HORIZONTAL_SCROLLBAR_AUTO_HIDE_SCROLL_BUTTON) ||
        (max_width > v->scroll_button.width))
    {
        gui_scrollbar_draw_button_style_9(GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL, &v->scroll_button);
    }
    gui_horizontal_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);

}


/*****************************************************************************
 * FUNCTION
*  gui_vertical_scrollbar_redraw_button_style_9
* DESCRIPTION
*  Redraw the vertical scrollbar button
* PARAMETERS
*  v       [IN/OUT]            Is the vertical scrollbar object
* RETURNS
*  void
*****************************************************************************/
void gui_vertical_scrollbar_redraw_button_style_9(vertical_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        return;
    }

    old_lcd_handle = gui_vertical_scrollbar_setup_target_lcd_and_layer(v);

    if (type == GUI_SCROLLBAR_BUTTON_UP)
    {
        if (pressed == MMI_TRUE)
        {
            v->up_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        }
        else
        {
            v->up_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        }

        gui_scrollbar_draw_button_style_9(GUI_SCROLLBAR_BUTTON_UP, &v->up_button);
    }
    else if (type == GUI_SCROLLBAR_BUTTON_DOWN)
    {
        if (pressed == MMI_TRUE)
        {
            v->down_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        }
        else
        {
            v->down_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        }
        gui_scrollbar_draw_button_style_9(GUI_SCROLLBAR_BUTTON_DOWN, &v->down_button);
    }

    gui_vertical_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);

}


/*****************************************************************************
* FUNCTION
 *  gui_show_vertical_scrollbar_style_9
 * DESCRIPTION
 *  Displays the vertical scrollbar
 * PARAMETERS
 *  v       [IN/OUT]            Is the vertical scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_vertical_scrollbar_style_9(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, sbutton_height, sb_y, sb_yrange, r, min_height = 0, max_height = 0;
    U8 buttons_flag = 1;
    UI_filled_area *f;
    MMI_BOOL result = MMI_FALSE;
    gdi_handle old_lcd_handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        buttons_flag = 0;
    }

    old_lcd_handle = gui_vertical_scrollbar_setup_target_lcd_and_layer(v);

    x1 = v->x;
    x2 = x1 + v->width - 1;
    y1 = v->y;
    y2 = y1 + v->height - 1;

    f = v->normal_bar_filler;

    if (buttons_flag)
    {
        max_height = v->height - v->up_button.height - v->down_button.height;
    }
    else
    {
        max_height = v->height;
    }

    /* Show the scroll button based on range and value */
    r = v->range - v->scale;
    min_height = gui_scrollbar_get_button_min_size_style_9(GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL, v->width);
    if (min_height > max_height)
    {
        min_height = max_height;
    }
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
        /* In case of very large r & v->value */
        sb_y = (S32) ((S64) sb_yrange * v->value / r);
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
    
#ifdef __MMI_TOUCH_SCREEN__
    v->pen_state.remain_space = (S16) sb_yrange;
#endif
    
    v->scroll_button.height = sbutton_height;
    v->scroll_button.y = sb_y + y1 + (buttons_flag ? v->up_button.height : 0);

    gui_push_clip();

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_set_clip(x1, y1, x2, y2);
    }
    else
    {
        result = gui_scrollbar_set_clip_intersect(x1, y1, x2, y2);
    }

    if (gui_scrollbar_redraw_clip_enable || (!gui_scrollbar_redraw_clip_enable && result))
    {
        if (!(v->flags & UI_VERTICAL_SCROLLBAR_AUTO_HIDE_SCROLL_BUTTON) || 
           (max_height > v->scroll_button.height))
        {          
            gui_fill_rectangle(x1, y1, x2, y2, f->border_color);

            if(v->width > GUI_SCROLLBAR_MIDDLE_BACKGROUND_WIDTH_STYLE9)
            {
                x1 = x1 + ((v->width + 1)/ 2) - GUI_SCROLLBAR_MIDDLE_BACKGROUND_WIDTH_STYLE9;
                x2 = x1 + GUI_SCROLLBAR_MIDDLE_BACKGROUND_WIDTH_STYLE9;               
                gui_fill_rectangle(x1, y1, x2, y2, f->c);
            }
        }
    }

    gui_pop_clip();

    if (buttons_flag)
    {
        gui_scrollbar_draw_button_style_9(GUI_SCROLLBAR_BUTTON_UP, &v->up_button);
        gui_scrollbar_draw_button_style_9(GUI_SCROLLBAR_BUTTON_DOWN, &v->down_button);
    }

    if (!(v->flags & UI_VERTICAL_SCROLLBAR_AUTO_HIDE_SCROLL_BUTTON) || 
        (max_height > v->scroll_button.height))
    {
        gui_scrollbar_draw_button_style_9(GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL, &v->scroll_button);
    }
    gui_vertical_scrollbar_restore_target_lcd_and_layer(v, old_lcd_handle);
}


#endif /* UI_SCROLLBAR_STYLE_9 */


