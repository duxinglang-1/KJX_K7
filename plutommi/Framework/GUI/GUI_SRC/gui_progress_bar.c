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
 *  gui_progress_bar.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

/*****************************************************************************
 * include
 ****************************************************************************/
#include "gui_themes.h"

#include "gui_progress_bar.h"
#include "string.h"
#include "MMIDataType.h"
#include "gui.h"
#include "CustThemesRes.h"
#include "gui_switch.h"
#include "gui_config.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "stdio.h"
#include "Unicodexdcl.h"
#include "gdi_datatype.h"
#include "gdi_include.h"
#include "gdi_const.h"
#include "gui_data_types.h"
#include "mmi_frm_input_gprot.h"

/*****************************************************************************
 * Static Declaration
 ****************************************************************************/
gui_progress_bar_theme_struct g_mmi_progress_bar_theme;

/*****************************************************************************
 * Global Variable
 ****************************************************************************/

/*****************************************************************************
 * Local Function
 ****************************************************************************/
void gui_progress_bar_update_display_string(gui_progress_bar_struct *instance);

/*****************************************************************************
 * FUNCTION
 *  gui_set_progress_bar_focussed_theme
 * DESCRIPTION
 *  Set progress bar focussed theme.
 * PARAMETERS     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_progress_bar_theme(gui_progress_bar_struct *instance, gui_progress_bar_theme_struct *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&g_mmi_progress_bar_theme, b, sizeof(g_mmi_progress_bar_theme));
}


/*****************************************************************************
 * FUNCTION
 *  gui_get_progress_bar_theme
 * DESCRIPTION
 *  Set progress bar focussed theme.
 * PARAMETERS     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_get_progress_bar_theme(gui_progress_bar_struct *instance, gui_progress_bar_theme_struct *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(b != NULL)
    {
       memcpy(b, &g_mmi_progress_bar_theme, sizeof(g_mmi_progress_bar_theme)); 
    }  
}

/*****************************************************************************
 * FUNCTION
 *  gui_progress_bar_create
 * DESCRIPTION
 *  Creates the progress bar control
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 *  x               [IN]        X coordinate
 *  y               [IN]        Y coordinate
 *  width           [IN]        Width
 *  height          [IN]        Height
 *  max             [IN]        Maximum value
 *  step_size       [IN]        Step size 
 *  value           [IN]        Present value of the control         
 * RETURNS
 *  void
 *****************************************************************************/
void gui_progress_bar_create(
        gui_progress_bar_struct *instance,
        U16 x,
        U16 y,
        U16 width,
        U16 height,
        U16 max,
        U16 step_size,
        U16 *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Create the default colors to be used in control */
    instance->x = x;
    instance->y = y;
    instance->width = width;
    instance->height = height;
    instance->max_value = max;
    instance->value = value;
    instance->step_size = step_size;
    
    
    /* This is important as it resizes the control as according to the steps
        passed  by the application. It make sure that the control is equally
        divided according to the steps passed */     
#ifdef __MMI_FTE_SUPPORT__
    {
        S32 button_width, button_height;
        
        gui_measure_image(current_MMI_theme->slide_bar_indicator_image, &button_width, &button_height);

        instance->slot_x = instance->x + UI_SLIDER_X1_GAP + button_width / 2 ;
        instance->slot_width = width   - (UI_SLIDER_X1_GAP * 2) - button_width;
        instance->left_count = (instance->slot_width ) % (max / step_size);
    }
#else
    instance->left_count = (width) % (max / step_size);
#endif
    /* Calculates the step size in pixels */
   // instance->step_size_pixels = (instance->width * step_size) / max;
   
    /* Initialize the gradient to be used in control */
    //gui_initialize_gradient_color(&instance->color.gc, (color*) &array_color, (U8*) &array_percentage, 2);
    /* initialize the normal control if used by control */
}


/*****************************************************************************
 * FUNCTION
 *  gui_progress_bar_register_change_listener
 * DESCRIPTION
 *  This API registers the change listener with the application. The callback
 *  is called whenever any change event happens on the control.
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 *  funcptr         [IN]        Callback passed by application
 * RETURNS
 *  void
 *****************************************************************************/
void gui_progress_bar_register_change_listener(gui_progress_bar_struct *instance, mmi_pbar_funcptr funcptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    instance->callback = funcptr;
}


/*****************************************************************************
 * FUNCTION
 *  gui_progress_bar_set_step
 * DESCRIPTION
 *  set progress bar step size.
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 *  value           [IN]        Value of the step       
 * RETURNS
 *  void
 *****************************************************************************/
void gui_progress_bar_set_step(gui_progress_bar_struct *instance, S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    instance->step_size = value;
}


/*****************************************************************************
 * FUNCTION
 *  gui_progress_bar_set_display_string
 * DESCRIPTION
 *  set progress bar type
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 *  value           [IN]        Whether to show or not the string on control
 *  type            [IN]        Progress bar value
 * RETURNS
 *  void
 *****************************************************************************/
void gui_progress_bar_set_display_string(
        gui_progress_bar_struct *instance,
        MMI_BOOL value,
        enum MMI_PROGRESS_BAR_STRING_TYPE type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (value == MMI_FALSE)
    {
        /* In case application wants to disable the string return from here */
        instance->flags &= ~MMI_PROGRESS_BAR_SHOW_STRING;
        return;
    }
    else
    {
        instance->flags |= MMI_PROGRESS_BAR_SHOW_STRING;
        /* set this flag if its percentage and else set the normal display flag */
        if (type == PROGRESS_BAR_STRING_PERCENTAGE)
        {
            instance->flags |= MMI_PROGRESS_BAR_SHOW_STRING_TYPE_PERCENTAGE;
        }
        else
        {
            instance->flags &= ~MMI_PROGRESS_BAR_SHOW_STRING_TYPE_PERCENTAGE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_progress_bar_set_value
 * DESCRIPTION
 *  set progress bar value
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 *  value           [IN]        Value of the control
 * RETURNS
 *  void
 *****************************************************************************/
void gui_progress_bar_set_value(gui_progress_bar_struct *instance, S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Assert if the value is valid */
    if (value < 0 || value > instance->max_value)
    {
        MMI_ASSERT(0);
    }

    /* Normalize the value so that we always increment in step size */
    value = value - (value % instance->step_size);
    (*instance->value) = value;

    gui_progress_bar_update_display_string(instance);

    /* Notify the app that we made change to control */
    if (instance->callback != NULL)
    {
        instance->callback();
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_progress_bar_set_type
 * DESCRIPTION
 *  set progress bar type. It can be solid or divided.
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 *  type            [IN]        Progress bar type
 * RETURNS
 *  void
 *****************************************************************************/
void gui_progress_bar_set_type(gui_progress_bar_struct *instance, enum MMI_PROGRESS_BAR_TYPE type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case PROGRESS_BAR_SOLID:
            /* Anything special in case to be done in solid bar */
            break;
        case PROGRESS_BAR_DIVIDED:
            instance->flags |= MMI_PROGRESS_BAR_SHOW_DIVISIONS;
            break;
        default:
            ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_progress_bar_draw_separaters
 * DESCRIPTION
 *  This API draws the separaters in case we choose the divided bar.
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_progress_bar_draw_separaters(gui_progress_bar_struct *instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Start drawing the lines to create separaters */
    S32 index = 0;
    /* Get the separater width in pixels */

	U16 step_count = (instance->max_value / instance->step_size); /* total count. */
    U16 step_pixel = (instance->width / step_count);            /* normal pixel per filler. */


    /* coordinate of the first separater */
    S32 x1 = instance->x + step_pixel - 1;
    S32 y1 = instance->y;
    S32 y2 = instance->y + instance->height - 1;
    S32 x2 = x1;    /* 1 pixel width */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* We dont support separaters at width less than 2 pixels */
    if (step_pixel <= 1)
    {
        MMI_ASSERT(0);
    }
    
    /* Here loop is till total_steps - 1 as we dont need to draw the last line */
    for (index = 0; index < step_count - 1; index++)
    {
        gui_draw_filled_area(
		    x1,
		    y1,
		    x2,
		    y2,
		    g_mmi_progress_bar_theme.step_filler); 
        if(index < (step_count - instance->left_count) - 1)
        {
            x1 += step_pixel;
        }
        else
    {
           x1 += step_pixel + 1;
        }
        x2 = x1;
    }
}

/*****************************************************************************
 * FUNCTION
 *  gui_progress_bar_update_display_string
 * DESCRIPTION
 *  Updates the display string.
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_progress_bar_update_display_string(gui_progress_bar_struct *instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 str[20];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (instance->flags & MMI_PROGRESS_BAR_SHOW_STRING_TYPE_PERCENTAGE)
    {
        sprintf((PS8) str, "%d %%", (*instance->value));
    }
    else
    {
        sprintf((PS8) str, "%d", (*instance->value));
    }
    mmi_asc_to_ucs2((S8*) instance->string, (S8*) str);
}

/*****************************************************************************
 * FUNCTION
 *  gui_progress_bar_increment
 * DESCRIPTION
 *  Increment the progress bar with the step size.
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_progress_bar_increment(gui_progress_bar_struct *instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Do sanity if we can increment that */
    if ((*instance->value) + instance->step_size <= instance->max_value)
    {
        (*instance->value) = (*instance->value) + instance->step_size;
    }
    if (instance->callback != NULL)
    {
        instance->callback();
    }
    /* Update the string */
    gui_progress_bar_update_display_string(instance);
}


/*****************************************************************************
 * FUNCTION
 *  gui_progress_bar_decrement
 * DESCRIPTION
 *  Decrement the progress bar with the step size.
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_progress_bar_decrement(gui_progress_bar_struct *instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Do sanity if we can decrement the value */
    if ((*instance->value) - instance->step_size >= 0)
    {
        (*instance->value) = (*instance->value) - instance->step_size;
    }
    if (instance->callback != NULL)
    {
        instance->callback();
    }
    /* Update the string */
    gui_progress_bar_update_display_string(instance);
}

/*****************************************************************************
 * FUNCTION
 *  gui_progress_bar_fill
 * DESCRIPTION
 *  Fills the progress bar with the color from 0 to its value.
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_progress_bar_fill(gui_progress_bar_struct *instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 step_count = (instance->max_value / instance->step_size); /* total count. */
    U16 step_pixel = (instance->width / step_count);            /* normal pixel per filler. */
    U16 used_count = *(instance->value) / instance->step_size;  /* value take over count. */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_FTE_SUPPORT__    
        
    /* Normal fill the control */
        if(used_count <= (step_count - instance->left_count))
        {
        gui_draw_filled_area(
            instance->x,
                instance->y,
            instance->x + (used_count * step_pixel) - 1,
                instance->y + instance->height - 1,
            g_mmi_progress_bar_theme.normal_progress_filler); 
        }
        else
        {
        gui_draw_filled_area(
            instance->x,
                instance->y,
            instance->x + ((step_count - instance->left_count) * step_pixel + (used_count - (step_count - instance->left_count)) * (step_pixel + 1)) - 1,
                instance->y + instance->height - 1,
            g_mmi_progress_bar_theme.normal_progress_filler);
            }
        
#else
        /* Normal fill the control */
    gdi_handle active_layer;
    S32 button_y;
    S32 button_image_height;
    S32 button_image_width;
    
    gui_measure_image(g_mmi_progress_bar_theme.button_up_filler->b, &button_image_width, &button_image_height);
    button_y = instance->y + ((instance->height - button_image_height) >> 1);
    
    gdi_layer_get_active(&active_layer);
    gdi_push_and_set_alpha_blending_source_layer(active_layer);

    step_pixel = (instance->slot_width / step_count); 
    
        if(used_count <= (step_count - instance->left_count))
        {
        S32 button_x = instance->slot_x + (used_count * step_pixel) - 1;
        button_x -= button_image_width / 2;  
        gdi_image_draw(
            button_x,
            button_y,
            g_mmi_progress_bar_theme.button_up_filler->b);
        }
        else
        {
        S32 button_x = instance->slot_x + ((step_count - instance->left_count) * step_pixel + (used_count - (step_count - instance->left_count)) * (step_pixel + 1)) - 1;
        button_x -= button_image_width / 2;      
        gdi_image_draw(
            button_x,
            button_y,
            g_mmi_progress_bar_theme.button_up_filler->b);
        }
    gdi_pop_and_restore_alpha_blending_source_layer();
       
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_progress_bar_draw_string
 * DESCRIPTION
 *  Draws the string in case its enabled in progress bar.
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_progress_bar_draw_string(gui_progress_bar_struct *instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 str_w, str_h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    gui_set_font(&MMI_small_font);
    gui_measure_string((UI_string_type) instance->string, (S32*) &str_w, (S32*) &str_h);
    gui_push_text_clip();
    gui_set_text_color(g_mmi_progress_bar_theme.text_color);
    gui_move_text_cursor(instance->x + instance->width / 2 - str_w / 2, instance->y + instance->height / 2 - str_h / 2);
    gui_print_text((UI_string_type) instance->string);
    gui_pop_text_clip();
}

#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  gui_progress_bar_pen_handler
 * DESCRIPTION
 *  Handles the pen events in the control.
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 *  pen_event       [IN]        Pen event
 *  x               [IN]        Pen x coordinate
 *  y               [IN]        Pen y coordinate
 * RETURNS
 *  BOOL
 *****************************************************************************/
BOOL gui_progress_bar_pen_handler(gui_progress_bar_struct *instance, mmi_pen_event_type_enum pen_event, S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 step_count = (instance->max_value / instance->step_size);   /* step count */
    U16 step_pixel = (instance->width / step_count);                /* each step pixel value */
    U16 old_value = *(instance->value);	
    U16 new_value = *(instance->value);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Check if the pen is touched on control area */
    if (!PEN_CHECK_BOUND(x, y, instance->x, instance->y, instance->width, instance->height))
    {
        return MMI_FALSE;
    }
    switch(pen_event)
    {
        case MMI_PEN_EVENT_DOWN:
#ifdef __MMI_FTE_SUPPORT__
        case MMI_PEN_EVENT_MOVE:
#endif            
        {
#ifdef __MMI_FTE_SUPPORT__
            step_pixel = (instance->slot_width / step_count);       /* In FTE, real width is slot_width */
            x = x - instance->slot_x + 1;                           /* Real begin x of slot(relative coordinate) */
#else 
	        x = x - instance->x + 1;
#endif   
    
#ifdef __MMI_FTE_SUPPORT__
		if (x > instance->slot_width)
		{
			*(instance->value) = instance->max_value;
		}
		else if (x <= 0)
		{
			*(instance->value) = 0;
		}
#else

            if((x > (instance->width - step_pixel / 2)) &&
               (x < instance->width)
              )
            {
                *(instance->value) = instance->max_value;
            }
            else if((x > 0) && (x < step_pixel / 2))
            {
                if(old_value == 0)
                {
                    *(instance->value) = 1;
                }
                else
                {
                    *(instance->value) = 0;
                }
            }
#endif
            else
            {
                if(x > (step_count - instance->left_count) * step_pixel)
                {
                    U16 i = 0;
                    U16 xx = (U16)(x - (step_count - instance->left_count) * step_pixel);
                    for(i = 1; i <= instance->left_count; i++)
                    {
                        if(((step_pixel + 1)) > xx)
                        {
                                        new_value = (step_count - instance->left_count + i) * instance->step_size;
                            break;
                        }
                        xx -= (step_pixel + 1);
                    }
                }
                else
                {
                   new_value = (x / (step_pixel) + 1) * instance->step_size;
                }
                if(old_value < new_value)
                {
        #ifdef __MMI_FTE_SUPPORT__
                    *(instance->value) = new_value - instance->step_size;
        #else               
                    *(instance->value) = new_value;
        #endif
                }
                else
                {
                     *(instance->value) = new_value;
                }
            }
                
            if(instance->callback)
            {
                instance->callback();
            }
	        if(old_value != *(instance->value))
	        {
		        gui_progress_bar_update_display_string(instance);
                        	        
            }
            break;	
        }
        case MMI_PEN_EVENT_UP:
        {
            break;
        }
    }
    
	return MMI_TRUE;    
}
#endif

/*****************************************************************************
 * FUNCTION
 *  gui_progress_bar_draw
 * DESCRIPTION
 *  Draws the control.
 * PARAMETERS
 *  instance        [IN]        Instance of progress bar
 * RETURNS
 *  void
 *****************************************************************************/
void gui_progress_bar_draw(gui_progress_bar_struct *instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  //  gdi_layer_push_clip();
   // gdi_layer_reset_clip();
    gdi_layer_lock_frame_buffer();

   // gui_set_clip(instance->x, instance->y, instance->x + instance->width - 1, instance->y + instance->height - 1);

    /* Draw the basic structure */
#ifndef __MMI_FTE_SUPPORT__
    gui_draw_filled_area(
        instance->x,
        instance->y,
        instance->x + instance->width - 1,
        instance->y + instance->height - 1,
        g_mmi_progress_bar_theme.background_filler);
#else
    gdi_image_draw_resized(
		instance->x,
        instance->y,
        instance->width,
        instance->height,
        g_mmi_progress_bar_theme.background_filler->b);
#endif

   
    /* Fill as per the value of control */
    gui_progress_bar_fill(instance);
    /* Draw the separaters if set */

#ifndef __MMI_FTE_SUPPORT__    
    if (instance->flags & MMI_PROGRESS_BAR_SHOW_DIVISIONS)
    {
        gui_progress_bar_draw_separaters(instance);
    }

    if (instance->flags & MMI_PROGRESS_BAR_SHOW_STRING)
    {
        gui_progress_bar_draw_string(instance);
    }
#endif   

   // gui_pop_clip();
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(
        instance->x,
        instance->y,
        instance->x + instance->width - 1,
        instance->y + instance->height - 1);
}


