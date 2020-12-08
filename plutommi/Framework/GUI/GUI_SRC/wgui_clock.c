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
 *  wgui_clock.c
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *  clock related funtions
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 04 26 2012 shuaihui.ren
 * removed!
 * Revice code for multi-instance.
 *
 * 04 01 2011 helena.li
 * removed!
 * .
 *
 * 02 08 2011 ray.wu
 * removed!
 * .
 *
 * 02 08 2011 mason.chang
 * removed!
 * Rename/move file(s)
 *
 * 12 14 2010 helena.li
 * removed!
 * .
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
 * This file contains internal UI component API, and is intended to be used by category screen module only. 
 * It's not recommended to be included in application code directly. 
 * For application developers, please include category screen header files instead (e.g., wgui_categories.h).
*/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_release.h"
#include "MMI_trc_Int.h"
#include "gdi_include.h"
#include "gui_status_icon_bar.h"
#include "gui_clock.h"
#include "wgui_clock.h"
#include "wgui_categories_util.h"
#include "wgui_categories_list.h"

#ifdef __MMI_VUI_ENGINE__
extern gui_status_icon_bar_struct wgui_status_icon_bar_bars[];
#endif

/*clock list*/
gui_clock_struct g_wgui_clock_list[WGUI_CLOCK_MAX_ITEMS];
U32 g_wgui_clock_mainlcd_count = 0;
U32 g_wgui_clock_sublcd_count = 0;
/*first time to init clock component*/
static MMI_BOOL g_wgui_clock_first_time_init = MMI_TRUE;
static void wgui_clock_set_main_lcd_update_func(void);
static void wgui_clock_reset_main_lcd_update_func(void);

/*****************************************************************************
 * FUNCTION
 *  wgui_clock_init
 * DESCRIPTION
 *  init the clocks
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_clock_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wgui_clock_first_time_init)
    {
        for (i = 0; i < WGUI_CLOCK_MAX_ITEMS; i ++)
        {
            g_wgui_clock_list[i].active = MMI_FALSE;
        }

        g_wgui_clock_first_time_init = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_create
 * DESCRIPTION
 *  create a clock component
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  x               [IN]        Start x posiion
 *  y               [IN]        Start y position
 *  width           [IN]        Width of clock
 *  height          [IN]        Height of clock
 *  clock_type      [IN]        Type of clock
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_clock_create(U32 *clock_id, S32 x, S32 y, S32 width, S32 height, gui_clock_type_enum clock_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *clock_id = WGUI_CLOCK_INVALID_INDEX;
    wgui_clock_init();

    /* if current clock is all be used, just return */
    if (g_wgui_clock_mainlcd_count + g_wgui_clock_sublcd_count >=
        WGUI_CLOCK_MAX_ITEMS)
    {
        return MMI_FALSE;    
    }

#ifdef __MMI_SUBLCD__
    if (g_wgui_clock_sublcd_count >= WGUI_CLOCK_MAX_ITEMS_SUB_LCD &&
        (clock_type > GUI_CLOCK_SUBLCD_TYPE_BEGIN &&
         clock_type < GUI_CLOCK_SUBLCD_TYPE_END))
    {
        return MMI_FALSE;
    }
#endif /* __MMI_SUBLCD__ */

    if (!(clock_type > GUI_CLOCK_MAINLCD_TYPE_BEGIN &&
          clock_type < GUI_CLOCK_MAINLCD_TYPE_END)
#ifdef __MMI_SUBLCD__
        && !(clock_type > GUI_CLOCK_SUBLCD_TYPE_BEGIN &&
             clock_type < GUI_CLOCK_SUBLCD_TYPE_END)
#endif /* __MMI_SUBLCD__ */
        )
    {
        return MMI_FALSE;
    }

    for (i = 0; i < WGUI_CLOCK_MAX_ITEMS; i++)
    {
        if (g_wgui_clock_list[i].active == MMI_FALSE)
        {
            break;
        }
    }

    MMI_DBG_ASSERT(i < WGUI_CLOCK_MAX_ITEMS);
    gui_clock_create(
        &g_wgui_clock_list[i],
        x,
        y,
        width,
        height,
        clock_type);
    if (clock_type > GUI_CLOCK_MAINLCD_TYPE_BEGIN &&
        clock_type < GUI_CLOCK_MAINLCD_TYPE_END)
    {
        g_wgui_clock_mainlcd_count++;
    }
#ifdef __MMI_SUBLCD__
    else
    {
        g_wgui_clock_sublcd_count++;
    }
#endif /* __MMI_SUBLCD__ */

    *clock_id = (S32)i;
    wgui_clock_set_main_lcd_update_func();
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_close
 * DESCRIPTION
 *  close a clock component
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_close(U32 clock_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clock_id >= WGUI_CLOCK_MAX_ITEMS)
    {
        return;
    }

    if (g_wgui_clock_list[clock_id].active == MMI_TRUE)
    {
        if (g_wgui_clock_list[clock_id].type > GUI_CLOCK_MAINLCD_TYPE_BEGIN &&
            g_wgui_clock_list[clock_id].type < GUI_CLOCK_MAINLCD_TYPE_END)
        {
            g_wgui_clock_mainlcd_count--;
        }
    #ifdef __MMI_SUBLCD__
        else
        {
            g_wgui_clock_sublcd_count--;
        }
    #endif /* __MMI_SUBLCD__ */
        gui_clock_close(&g_wgui_clock_list[clock_id]);
    }
    wgui_clock_reset_main_lcd_update_func();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_close_all
 * DESCRIPTION
 *  close all clock components
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_close_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i< WGUI_CLOCK_MAX_ITEMS; i ++)
    {
        /* notify app it clock has been closed */
        if ( (g_wgui_clock_list[i].active == MMI_TRUE) && (g_wgui_clock_list[i].close_callback != NULL) )
        {
            g_wgui_clock_list[i].close_callback();
        }
        
        gui_clock_close(&g_wgui_clock_list[i]); 
    }
    g_wgui_clock_mainlcd_count = 0;
    g_wgui_clock_sublcd_count = 0;
    wgui_clock_main_lcd_update_func = UI_dummy_function;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_close_main_lcd
 * DESCRIPTION
 *  close all clock components in main lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_close_main_lcd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WGUI_CLOCK_MAX_ITEMS; i ++)
    {
        if (g_wgui_clock_list[i].active == MMI_TRUE)
        {
            if (g_wgui_clock_list[i].type > GUI_CLOCK_MAINLCD_TYPE_BEGIN &&
                g_wgui_clock_list[i].type < GUI_CLOCK_MAINLCD_TYPE_END)
            {
                /* notify app it clock has been closed */
                if ( (g_wgui_clock_list[i].active == MMI_TRUE) && (g_wgui_clock_list[i].close_callback != NULL) )
                {
                    g_wgui_clock_list[i].close_callback();
                }
                
                gui_clock_close(&g_wgui_clock_list[i]);
                g_wgui_clock_mainlcd_count--;
            }
        }
    }
    MMI_DBG_ASSERT(g_wgui_clock_mainlcd_count == 0);
    wgui_clock_main_lcd_update_func = UI_dummy_function;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_close_sub_lcd
 * DESCRIPTION
 *  close all clock components in sub lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_close_sub_lcd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD__
    S32 i;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD__
    for (i = 0; i < WGUI_CLOCK_MAX_ITEMS; i ++)
    {
        if (g_wgui_clock_list[i].active == MMI_TRUE)
        {
            if (g_wgui_clock_list[i].type > GUI_CLOCK_SUBLCD_TYPE_BEGIN &&
                g_wgui_clock_list[i].type < GUI_CLOCK_SUBLCD_TYPE_END)
            {
                /* notify app it clock has been closed */
                if ( (g_wgui_clock_list[i].active == MMI_TRUE) && (g_wgui_clock_list[i].close_callback != NULL) )
                {
                    g_wgui_clock_list[i].close_callback();
                }
                
                gui_clock_close(&g_wgui_clock_list[i]);
                g_wgui_clock_sublcd_count--;
            }
        }
    }
#endif /* __MMI_SUBLCD__ */
    MMI_DBG_ASSERT(g_wgui_clock_sublcd_count == 0);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_show
 * DESCRIPTION
 *  show a clock component
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_clock_show_main_lcd();
    wgui_clock_show_sub_lcd();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_show_main_lcd
 * DESCRIPTION
 *  show all clock components in main lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_show_main_lcd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    GDI_HANDLE old_lcd, old_layer;
    S32 x1, y1, x2, y2;
    MMI_BOOL first_time = MMI_TRUE;
#ifdef __MMI_VUI_ENGINE__
    S32 clock_count = 0, clock_index = 0;
#endif
       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VUI_ENGINE__
    /* In venus screen, update clock on status icon bar */
    if(wgui_status_icon_bar_bars[0].instance_count > 0)
    {
        for (i = 0; i < WGUI_CLOCK_MAX_ITEMS; i++)
        {
            if (g_wgui_clock_list[i].active == MMI_TRUE &&
            (g_wgui_clock_list[i].type > GUI_CLOCK_MAINLCD_TYPE_BEGIN &&
             g_wgui_clock_list[i].type < GUI_CLOCK_MAINLCD_TYPE_END))
            {
                clock_count++;
                if (g_wgui_clock_list[i].type ==
                    GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME_SMALL)
                {
                    clock_index = i;
                }
            }
        }
            
        /* In venus there is only a clock of plutommi */
        MMI_DBG_ASSERT(clock_count == 1);
        if (g_wgui_clock_list[clock_index].target_layer != NULL)
        {
            gdi_layer_push_and_set_active(g_wgui_clock_list[clock_index].target_layer);
        }
        gdi_layer_lock_frame_buffer();
        gui_clock_show(&g_wgui_clock_list[clock_index]);
        gdi_layer_unlock_frame_buffer();
        if (g_wgui_clock_list[clock_index].target_layer != NULL)
        {
            gdi_layer_pop_and_restore_active();
        }

        wgui_status_icon_bar_update();
        return;
    }
#endif /* __MMI_VUI_ENGINE__ */

    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;
    gdi_layer_lock_frame_buffer();
    for (i = 0; i < WGUI_CLOCK_MAX_ITEMS; i ++)
    {
        if (g_wgui_clock_list[i].active == MMI_TRUE &&
            (g_wgui_clock_list[i].type > GUI_CLOCK_MAINLCD_TYPE_BEGIN &&
             g_wgui_clock_list[i].type < GUI_CLOCK_MAINLCD_TYPE_END))
        {
            GDI_LOCK;
            
            gdi_layer_get_active(&old_layer);
            gdi_lcd_get_active(&old_lcd);
            
            gdi_lcd_set_active(g_wgui_clock_list[i].target_lcd);
            if (g_wgui_clock_list[i].target_layer != NULL)
            {
                gdi_layer_push_and_set_active(g_wgui_clock_list[i].target_layer);
            }
            if (g_wgui_clock_list[i].abm_layer != NULL)
            {
                gdi_push_and_set_alpha_blending_source_layer(g_wgui_clock_list[i].abm_layer);
            }
        
            gui_clock_show(&g_wgui_clock_list[i]);  

            /* merge blt areas */
            if (first_time)
            {
                x1 = g_wgui_clock_list[i].x;
                y1 = g_wgui_clock_list[i].y;
                x2 = g_wgui_clock_list[i].x + g_wgui_clock_list[i].width - 1;
                y2 = g_wgui_clock_list[i].y + g_wgui_clock_list[i].height - 1;
                first_time = MMI_FALSE;
            }
            else
            {
                if (x1 > g_wgui_clock_list[i].x)
                {
                    x1 = g_wgui_clock_list[i].x;
                }
                if (y1 > g_wgui_clock_list[i].y)
                {
                    y1 = g_wgui_clock_list[i].y;
                }
                if (x2 < (g_wgui_clock_list[i].x + g_wgui_clock_list[i].width - 1))
                {
                    x2 = g_wgui_clock_list[i].x + g_wgui_clock_list[i].width - 1;
                }
                if (y2 < (g_wgui_clock_list[i].y + g_wgui_clock_list[i].height - 1))
                {
                    y2 = g_wgui_clock_list[i].y + g_wgui_clock_list[i].height - 1;
                }
            }

            /*
            gdi_layer_blt_previous(
                g_wgui_clock_list[i].x,
                g_wgui_clock_list[i].y,
                g_wgui_clock_list[i].x + g_wgui_clock_list[i].width - 1, 
                g_wgui_clock_list[i].y + g_wgui_clock_list[i].height - 1);
            */
            if (g_wgui_clock_list[i].abm_layer != NULL)
            {
                gdi_pop_and_restore_alpha_blending_source_layer();
            }
            if (g_wgui_clock_list[i].target_layer != NULL)
            {
                gdi_layer_pop_and_restore_active();
            }
            gdi_lcd_set_active(old_lcd);
            gdi_layer_set_active(old_layer);
            
            GDI_UNLOCK;
        }
    }
    gdi_layer_unlock_frame_buffer();
    /* if first_time is MMI_FALSE mean there is at least one active clock */
    if (first_time == MMI_FALSE)
    {
        gdi_layer_blt_previous(x1, y1, x2, y2);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_show_sub_lcd
 * DESCRIPTION
 *  show all clock components in sub lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_show_sub_lcd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD__
    S32 i;
    GDI_HANDLE old_lcd, old_layer;
    S32 x1, y1, x2, y2;
    MMI_BOOL first_time = MMI_TRUE;
#endif /* __MMI_SUBLCD__ */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD__
    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;
    gdi_layer_lock_frame_buffer();
    for (i = 0; i < WGUI_CLOCK_MAX_ITEMS; i ++)
    {
        if (g_wgui_clock_list[i].active == MMI_TRUE &&
            (g_wgui_clock_list[i].type > GUI_CLOCK_SUBLCD_TYPE_BEGIN &&
             g_wgui_clock_list[i].type < GUI_CLOCK_SUBLCD_TYPE_END))
        {
            GDI_LOCK;
            
            gdi_layer_get_active(&old_layer);
            gdi_lcd_get_active(&old_lcd);
            
            gdi_lcd_set_active(g_wgui_clock_list[i].target_lcd);
            if (g_wgui_clock_list[i].target_layer != NULL)
            {
                gdi_layer_push_and_set_active(g_wgui_clock_list[i].target_layer);
            }
            if (g_wgui_clock_list[i].abm_layer != NULL)
            {
                gdi_push_and_set_alpha_blending_source_layer(g_wgui_clock_list[i].abm_layer);
            }
        
            gui_clock_show(&g_wgui_clock_list[i]);  

            /*
            gdi_layer_blt_previous(
                g_wgui_clock_list[i].x,
                g_wgui_clock_list[i].y,
                g_wgui_clock_list[i].x + g_wgui_clock_list[i].width - 1, 
                g_wgui_clock_list[i].y + g_wgui_clock_list[i].height - 1);
            */
            /* merge blt areas */
            if (first_time)
            {
                x1 = g_wgui_clock_list[i].x;
                y1 = g_wgui_clock_list[i].y;
                x2 = g_wgui_clock_list[i].x + g_wgui_clock_list[i].width - 1;
                y2 = g_wgui_clock_list[i].y + g_wgui_clock_list[i].height - 1;
                first_time = MMI_FALSE;
            }
            else
            {
                if (x1 > g_wgui_clock_list[i].x)
                {
                    x1 = g_wgui_clock_list[i].x;
                }
                if (y1 > g_wgui_clock_list[i].y)
                {
                    y1 = g_wgui_clock_list[i].y;
                }
                if (x2 < (g_wgui_clock_list[i].x + g_wgui_clock_list[i].width - 1))
                {
                    x2 = g_wgui_clock_list[i].x + g_wgui_clock_list[i].width - 1;
                }
                if (y2 < (g_wgui_clock_list[i].y + g_wgui_clock_list[i].height - 1))
                {
                    y2 = g_wgui_clock_list[i].y + g_wgui_clock_list[i].height - 1;
                }
            }
            
            if (g_wgui_clock_list[i].abm_layer != NULL)
            {
                gdi_pop_and_restore_alpha_blending_source_layer();
            }
            if (g_wgui_clock_list[i].target_layer != NULL)
            {
                gdi_layer_pop_and_restore_active();
            }
            gdi_lcd_set_active(old_lcd);
            gdi_layer_set_active(old_layer);
            
            GDI_UNLOCK;
            
        }
    }
    gdi_layer_unlock_frame_buffer();
    /* if first_time is MMI_FALSE mean there is at least one active clock */
    if (first_time == MMI_FALSE)
    {
        gdi_layer_blt_previous(x1, y1, x2, y2);
    }
#endif /* __MMI_SUBLCD__ */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_update
 * DESCRIPTION
 *  update clock components
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_clock_update_main_lcd();
    wgui_clock_update_sub_lcd();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_update_main_lcd
 * DESCRIPTION
 *  update all clock components in main lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_update_main_lcd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    GDI_HANDLE old_lcd, old_layer;
    S32 x1, y1, x2, y2;
    MMI_BOOL first_time = MMI_TRUE;
    MMI_BOOL ret;
#ifdef __MMI_VUI_ENGINE__
    S32 clock_count = 0, clock_index = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VUI_ENGINE__
    /* In venus screen, update clock on status icon bar */
    if(wgui_status_icon_bar_bars[0].instance_count)
    {
        for (i = 0; i < WGUI_CLOCK_MAX_ITEMS; i++)
        {
            if (g_wgui_clock_list[i].active == MMI_TRUE &&
            (g_wgui_clock_list[i].type > GUI_CLOCK_MAINLCD_TYPE_BEGIN &&
             g_wgui_clock_list[i].type < GUI_CLOCK_MAINLCD_TYPE_END))
            {
                clock_count++;
                if (g_wgui_clock_list[i].type ==
                    GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME_SMALL)
                {
                    clock_index = i;
                }
            }
        }
            
        /* In venus there is only a clock of plutommi */
        MMI_DBG_ASSERT(clock_count == 1);
        if (g_wgui_clock_list[clock_index].target_layer != NULL)
        {
            gdi_layer_push_and_set_active(g_wgui_clock_list[clock_index].target_layer);
        }
        gdi_layer_lock_frame_buffer();
        ret = gui_clock_update(&g_wgui_clock_list[clock_index]);
        gdi_layer_unlock_frame_buffer();
        if (g_wgui_clock_list[clock_index].target_layer != NULL)
        {
            gdi_layer_pop_and_restore_active();
        }
        if (ret)
        {
            wgui_status_icon_bar_update();
        }
        return;
    }
#endif /* __MMI_VUI_ENGINE__ */

    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;
    gdi_layer_lock_frame_buffer();
    for (i = 0; i < WGUI_CLOCK_MAX_ITEMS; i ++)
    {
        if (g_wgui_clock_list[i].active == MMI_TRUE &&
            (g_wgui_clock_list[i].type > GUI_CLOCK_MAINLCD_TYPE_BEGIN &&
             g_wgui_clock_list[i].type < GUI_CLOCK_MAINLCD_TYPE_END))
        {
            GDI_LOCK;            
            gdi_layer_get_active(&old_layer);
            gdi_lcd_get_active(&old_lcd);
            
            gdi_lcd_set_active(g_wgui_clock_list[i].target_lcd);
            if (g_wgui_clock_list[i].target_layer != NULL)
            {
                gdi_layer_push_and_set_active(g_wgui_clock_list[i].target_layer);
            }
            if (g_wgui_clock_list[i].abm_layer != NULL)
            {
                gdi_push_and_set_alpha_blending_source_layer(g_wgui_clock_list[i].abm_layer);
            }

            ret = gui_clock_update(&g_wgui_clock_list[i]);    
            /* merge blt areas */
            if (ret)
            {
                if (first_time)
                {
                    x1 = g_wgui_clock_list[i].x;
                    y1 = g_wgui_clock_list[i].y;
                    x2 = g_wgui_clock_list[i].x + g_wgui_clock_list[i].width - 1;
                    y2 = g_wgui_clock_list[i].y + g_wgui_clock_list[i].height - 1;
                    first_time = MMI_FALSE;
                }
                else
                {
                    if (x1 > g_wgui_clock_list[i].x)
                    {
                        x1 = g_wgui_clock_list[i].x;
                    }
                    if (y1 > g_wgui_clock_list[i].y)
                    {
                        y1 = g_wgui_clock_list[i].y;
                    }
                    if (x2 < (g_wgui_clock_list[i].x + g_wgui_clock_list[i].width - 1))
                    {
                        x2 = g_wgui_clock_list[i].x + g_wgui_clock_list[i].width - 1;
                    }
                    if (y2 < (g_wgui_clock_list[i].y + g_wgui_clock_list[i].height - 1))
                    {
                        y2 = g_wgui_clock_list[i].y + g_wgui_clock_list[i].height - 1;
                    }
                }
            }
            if (g_wgui_clock_list[i].abm_layer != NULL)
            {
                gdi_pop_and_restore_alpha_blending_source_layer();
            }
            if (g_wgui_clock_list[i].target_layer != NULL)
            {
                gdi_layer_pop_and_restore_active();
            }
            gdi_lcd_set_active(old_lcd);
            gdi_layer_set_active(old_layer);
            
            GDI_UNLOCK;
        }
    }
    gdi_layer_unlock_frame_buffer();
    /* if first_time is MMI_FALSE mean there is at least one active clock */
    if (first_time == MMI_FALSE)
    {
        gdi_layer_blt_previous(x1, y1, x2, y2);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_update_sub_lcd
 * DESCRIPTION
 *  update all clock components in sub lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_update_sub_lcd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD__
    S32 i;
    GDI_HANDLE old_lcd, old_layer;
    S32 x1, y1, x2, y2;
    MMI_BOOL first_time = MMI_TRUE;
    MMI_BOOL ret;
#endif /* __MMI_SUBLCD__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD__
    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;
    gdi_layer_lock_frame_buffer();
    for (i = 0; i < WGUI_CLOCK_MAX_ITEMS; i ++)
    {
        if (g_wgui_clock_list[i].active == MMI_TRUE &&
            (g_wgui_clock_list[i].type > GUI_CLOCK_SUBLCD_TYPE_BEGIN &&
             g_wgui_clock_list[i].type < GUI_CLOCK_SUBLCD_TYPE_END))
        {
            GDI_LOCK;            
            gdi_layer_get_active(&old_layer);
            gdi_lcd_get_active(&old_lcd);
            
            gdi_lcd_set_active(g_wgui_clock_list[i].target_lcd);
            if (g_wgui_clock_list[i].target_layer != NULL)
            {
                gdi_layer_push_and_set_active(g_wgui_clock_list[i].target_layer);
            }
            if (g_wgui_clock_list[i].abm_layer != NULL)
            {
                gdi_push_and_set_alpha_blending_source_layer(g_wgui_clock_list[i].abm_layer);
            }

            ret = gui_clock_update(&g_wgui_clock_list[i]);    
            if (ret)
            {
                /* merge blt areas */
                if (first_time)
                {
                    x1 = g_wgui_clock_list[i].x;
                    y1 = g_wgui_clock_list[i].y;
                    x2 = g_wgui_clock_list[i].x + g_wgui_clock_list[i].width - 1;
                    y2 = g_wgui_clock_list[i].y + g_wgui_clock_list[i].height - 1;
                    first_time = MMI_FALSE;
                }
                else
                {
                    if (x1 > g_wgui_clock_list[i].x)
                    {
                        x1 = g_wgui_clock_list[i].x;
                    }
                    if (y1 > g_wgui_clock_list[i].y)
                    {
                        y1 = g_wgui_clock_list[i].y;
                    }
                    if (x2 < (g_wgui_clock_list[i].x + g_wgui_clock_list[i].width - 1))
                    {
                        x2 = g_wgui_clock_list[i].x + g_wgui_clock_list[i].width - 1;
                    }
                    if (y2 < (g_wgui_clock_list[i].y + g_wgui_clock_list[i].height - 1))
                    {
                        y2 = g_wgui_clock_list[i].y + g_wgui_clock_list[i].height - 1;
                    }
                }
            }
            if (g_wgui_clock_list[i].abm_layer != NULL)
            {
                gdi_pop_and_restore_alpha_blending_source_layer();
            }
            if (g_wgui_clock_list[i].target_layer != NULL)
            {
                gdi_layer_pop_and_restore_active();
            }
            gdi_lcd_set_active(old_lcd);
            gdi_layer_set_active(old_layer);
            
            GDI_UNLOCK;

        }
    }
    gdi_layer_unlock_frame_buffer();
    /* if first_time is MMI_FALSE mean there is at least one active clock */
    if (first_time == MMI_FALSE)
    {
        gdi_layer_blt_previous(x1, y1, x2, y2);
    }
#endif /* __MMI_SUBLCD__ */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_move
 * DESCRIPTION
 *  move a clock component
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  x               [IN]        Start x posiion
 *  y               [IN]        Start y position
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_move(U32 clock_id, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(clock_id < WGUI_CLOCK_MAX_ITEMS);
    gui_clock_move(&g_wgui_clock_list[clock_id], x, y);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_resize
 * DESCRIPTION
 *  resize a clock component
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  width           [IN]        Width of clock
 *  height          [IN]        Height of clock
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_resize(U32 clock_id, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(clock_id < WGUI_CLOCK_MAX_ITEMS);
    gui_clock_resize(&g_wgui_clock_list[clock_id], width, height);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_time
 * DESCRIPTION
 *  set the time of a clock
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  newtime         [IN]        New time of the clock
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_time(U32 clock_id, applib_time_struct newtime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(clock_id < WGUI_CLOCK_MAX_ITEMS);
    gui_clock_set_time(&g_wgui_clock_list[clock_id], newtime);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_get_time
 * DESCRIPTION
 *  get the time of a clock
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  time            [IN]        Current time of the clock
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_get_time(U32 clock_id, applib_time_struct *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(clock_id < WGUI_CLOCK_MAX_ITEMS);

    gui_clock_get_time(&g_wgui_clock_list[clock_id], time);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_hide_function
 * DESCRIPTION
 *  set the hide callback function of the clock
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  f               [IN]        New hide callback function
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_hide_function(U32 clock_id, void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_DBG_ASSERT(clock_id < WGUI_CLOCK_MAX_ITEMS);    
    gui_clock_set_hide_function(&g_wgui_clock_list[clock_id], f);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_close_callback
 * DESCRIPTION
 *  set the close callback function of the clock
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  f               [IN]        New close callback function
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_close_callback(U32 clock_id, FuncPtr f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_DBG_ASSERT(clock_id < WGUI_CLOCK_MAX_ITEMS);    
    gui_clock_set_close_callback(&g_wgui_clock_list[clock_id], f);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_post_display_callback
 * DESCRIPTION
 *  set the post display callback function of the clock
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  f               [IN]        New post display callback function
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_post_display_callback(
      U32 clock_id,
      void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(clock_id < WGUI_CLOCK_MAX_ITEMS);
    gui_clock_set_post_display_callback(&g_wgui_clock_list[clock_id], f);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_analog_clock_hour_hand_color
 * DESCRIPTION
 *  set the color of anlog clock's hour hand
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  new_color       [IN]        New color of hour hand
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_analog_clock_hour_hand_color(U32 clock_id, color new_color)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(clock_id < WGUI_CLOCK_MAX_ITEMS);
    gui_clock_set_analog_clock_hour_hand_color(&g_wgui_clock_list[clock_id], new_color);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_analog_clock_min_hand_color
 * DESCRIPTION
 *  set the color of anlog clock's minute hand
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  new_color       [IN]        New color of minute hand
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_analog_clock_min_hand_color(U32 clock_id, color new_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(clock_id < WGUI_CLOCK_MAX_ITEMS);
    gui_clock_set_analog_clock_min_hand_color(&g_wgui_clock_list[clock_id], new_color);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_date_text_font
 * DESCRIPTION
 *  set the font of date text
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  new_font        [IN]        New font of date text
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_date_text_font(U32 clock_id, UI_font_type new_font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(clock_id < WGUI_CLOCK_MAX_ITEMS);
    gui_clock_set_date_text_font(&g_wgui_clock_list[clock_id], new_font);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_date_text_color
 * DESCRIPTION
 *  set the color of date text
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  new_color       [IN]        New color of date text
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_date_text_color(U32 clock_id, color new_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(clock_id < WGUI_CLOCK_MAX_ITEMS);
    gui_clock_set_date_text_color(&g_wgui_clock_list[clock_id], new_color);

}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_date_text_border_color
 * DESCRIPTION
 *  set the border color of date text
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  new_color       [IN]        New border color of date text
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_date_text_border_color(U32 clock_id, color new_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(clock_id < WGUI_CLOCK_MAX_ITEMS);
    gui_clock_set_date_text_border_color(&g_wgui_clock_list[clock_id], new_color);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_time_text_font
 * DESCRIPTION
 *  set the font of time text
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  new_font        [IN]        New font of time text
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_time_text_font(U32 clock_id, UI_font_type new_font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(clock_id < WGUI_CLOCK_MAX_ITEMS);
    gui_clock_set_time_text_font(&g_wgui_clock_list[clock_id], new_font);

}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_time_text_color
 * DESCRIPTION
 *  set the color of time text
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  new_color       [IN]        New color of time text
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_time_text_color(U32 clock_id, color new_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(clock_id < WGUI_CLOCK_MAX_ITEMS);
    gui_clock_set_time_text_color(&g_wgui_clock_list[clock_id], new_color);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_time_text_border_color
 * DESCRIPTION
 *  set the border color of time text
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  new_color       [IN]        New border color of time text
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_time_text_border_color (U32 clock_id, color new_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(clock_id < WGUI_CLOCK_MAX_ITEMS);
    gui_clock_set_time_text_border_color(&g_wgui_clock_list[clock_id], new_color);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_gap_between_two_lines
 * DESCRIPTION
 *  set the gap between time text and date text
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  new_gap         [IN]        New gap between time text and date text
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_gap_between_two_lines(U32 clock_id, S32 new_gap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(clock_id < WGUI_CLOCK_MAX_ITEMS);
    gui_clock_set_gap_between_two_lines(&g_wgui_clock_list[clock_id], new_gap);
    
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_measure_time_text
 * DESCRIPTION
 *  get the width and height of time text
 * PARAMETERS
 *  clock_id            [IN]        
 *  w                   [OUT]       Return width
 *  h                   [OUT]       Retrun height
 *  font                [IN]        Font
 *  clock_type(?)       [IN]        Clock type
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_measure_time_text(U32 clock_id, S32 *w, S32 *h, UI_font_type font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(clock_id < WGUI_CLOCK_MAX_ITEMS);
    gui_clock_measure_time_text(&g_wgui_clock_list[clock_id], w, h,  font);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_measure_digital_clock
 * DESCRIPTION
 *  get the width and height of digital clock that using image
 * PARAMETERS
 *  clock_id            [IN]        id of clock
 *  w                   [OUT]       Return width
 *  h                   [OUT]       Retrun height
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_measure_digital_clock(U32 clock_id, S32 *w, S32 *h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(clock_id < WGUI_CLOCK_MAX_ITEMS);
    gui_clock_measure_digital_clock(&g_wgui_clock_list[clock_id], w, h);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_measure_digital_small_clock
 * DESCRIPTION
 *  get the width and height of digital small clock that using image
 * PARAMETERS
 *  clock_id            [IN]        id of clock
 *  w                   [OUT]       Return width
 *  h                   [OUT]       Retrun height
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_measure_digital_small_clock(U32 clock_id, S32 *w, S32 *h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(clock_id < WGUI_CLOCK_MAX_ITEMS);
    gui_clock_measure_digital_small_clock(&g_wgui_clock_list[clock_id], w, h);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_measure_date_text
 * DESCRIPTION
 *  get the width and height of date text
 * PARAMETERS
 *  clock_id            [IN]        
 *  w                   [OUT]       Return width
 *  h                   [OUT]       Retrun height
 *  font                [IN]        Font
 *  clock_type(?)       [IN]        Clock type
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_measure_date_text(U32 clock_id, S32 *w, S32 *h, UI_font_type font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(clock_id < WGUI_CLOCK_MAX_ITEMS);
    gui_clock_measure_date_text(&g_wgui_clock_list[clock_id], w, h, font);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_text_border_enable
 * DESCRIPTION
 *  enable the border text or not
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  enable          [IN]        Enable
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_text_border_enable(U32 clock_id,  MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(clock_id < WGUI_CLOCK_MAX_ITEMS);
    gui_clock_set_text_border_enable(&g_wgui_clock_list[clock_id], enable);
}

/*****************************************************************************
 * FUNCTION
 *  gui_clock_close
 * DESCRIPTION
 *  close a clock component
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  on_idle [IN]        clock on idle or not
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_on_idle(U32 clock_id,  MMI_BOOL on_idle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(clock_id < WGUI_CLOCK_MAX_ITEMS);
    gui_clock_set_on_idle(&g_wgui_clock_list[clock_id], on_idle);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_enable_update
 * DESCRIPTION
 *  enable clock's update
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  enable_update   [IN]        enable update or not
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_enable_update(U32 clock_id, MMI_BOOL enable_update)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(clock_id < WGUI_CLOCK_MAX_ITEMS);
    gui_clock_enable_update(&g_wgui_clock_list[clock_id], enable_update);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_target_layer
 * DESCRIPTION
 *  set target layer of clock
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  target_layer    [IN]        target layer of clock
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_target_layer(U32 clock_id, GDI_HANDLE target_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(clock_id < WGUI_CLOCK_MAX_ITEMS);
    gui_clock_set_target_layer(&g_wgui_clock_list[clock_id], target_layer);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_abm_layer
 * DESCRIPTION
 *  set alpha blending layer of clock
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  abm_layer       [IN]        alpha blending layer of clock
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_abm_layer(U32 clock_id, GDI_HANDLE abm_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(clock_id < WGUI_CLOCK_MAX_ITEMS);
    gui_clock_set_abm_layer(&g_wgui_clock_list[clock_id], abm_layer);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_get_dimension
 * DESCRIPTION
 *  get clock dimenstion
 * PARAMETERS
 *  clock_id    [IN]            Id of clock component
 *  width       [IN/OUT]        Width of clock
 *  height      [IN/OUT]        Height of clock
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_get_dimension(U32 clock_id, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(clock_id < WGUI_CLOCK_MAX_ITEMS);
    *width = g_wgui_clock_list[clock_id].width;
    *height = g_wgui_clock_list[clock_id].height;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_get_position
 * DESCRIPTION
 *  get clock position
 * PARAMETERS
 *  clock_id    [IN]            Id of clock component
 *  x           [IN/OUT]        x position of clock
 *  y           [IN/OUT]        y position of clock
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_get_position(U32 clock_id, S32 *x, S32 *y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(clock_id < WGUI_CLOCK_MAX_ITEMS);
    *x = g_wgui_clock_list[clock_id].x;
    *y = g_wgui_clock_list[clock_id].y;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_is_available_id
 * DESCRIPTION
 *  get clock id is available or not
 * PARAMETERS
 *  clock_id    [IN]            Id of clock component
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL wgui_clock_is_available_id(U32 clock_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clock_id >= WGUI_CLOCK_MAX_ITEMS ||
        g_wgui_clock_list[clock_id].active == MMI_FALSE)
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_main_lcd_update_func
 * DESCRIPTION
 *  this func will update all active clock in main lcd
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void (*wgui_clock_main_lcd_update_func) (void) = UI_dummy_function;


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_main_lcd_update_func
 * DESCRIPTION
 *  this func set main lcd update function
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void wgui_clock_set_main_lcd_update_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_clock_main_lcd_update_func == UI_dummy_function)
    {
        wgui_clock_main_lcd_update_func = wgui_clock_update_main_lcd;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_reset_main_lcd_update_func
 * DESCRIPTION
 *  this func reset main lcd update function to dummy if all clock is unactive
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void wgui_clock_reset_main_lcd_update_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WGUI_CLOCK_MAX_ITEMS; i ++)
    {
        if(g_wgui_clock_list[i].active == MMI_TRUE &&
           (g_wgui_clock_list[i].type > GUI_CLOCK_MAINLCD_TYPE_BEGIN &&
            g_wgui_clock_list[i].type < GUI_CLOCK_MAINLCD_TYPE_END))
        {
            return;
        }
    }
    
    MMI_DBG_ASSERT(g_wgui_clock_mainlcd_count == 0);
    wgui_clock_main_lcd_update_func = UI_dummy_function;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_digital_align_type
 * DESCRIPTION
 *  set digital align type of clock
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  type            [IN]        align type of digital clock
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_digital_align_type(U32 clock_id, gui_clock_digital_align_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(clock_id < WGUI_CLOCK_MAX_ITEMS);
    gui_clock_set_digital_align_type(&g_wgui_clock_list[clock_id], type);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_show_clock
 * DESCRIPTION
 *  show a clock component
 * PARAMETERS
 *  clock_id        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_show_clock(U32 clock_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE old_lcd, old_layer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(clock_id < WGUI_CLOCK_MAX_ITEMS);
    GDI_LOCK;
            
    gdi_layer_get_active(&old_layer);
    gdi_lcd_get_active(&old_lcd);
                
    gdi_lcd_set_active(g_wgui_clock_list[clock_id].target_lcd);
    if (g_wgui_clock_list[clock_id].target_layer != NULL)
    {
        gdi_layer_push_and_set_active(g_wgui_clock_list[clock_id].target_layer);
    }
    if (g_wgui_clock_list[clock_id].abm_layer != NULL)
    {
        gdi_push_and_set_alpha_blending_source_layer(g_wgui_clock_list[clock_id].abm_layer);
    }
        
    gui_clock_show(&g_wgui_clock_list[clock_id]);
    
    if (g_wgui_clock_list[clock_id].abm_layer != NULL)
    {
        gdi_pop_and_restore_alpha_blending_source_layer();
    }
    if (g_wgui_clock_list[clock_id].target_layer != NULL)
    {
        gdi_layer_pop_and_restore_active();
    }
    gdi_lcd_set_active(old_lcd);
    gdi_layer_set_active(old_layer);
            
    GDI_UNLOCK;  
}



