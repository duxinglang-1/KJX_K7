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

/*******************************************************************************
 * Filename:
 * ---------
 *  widget_drawing.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Widget low-level drawing
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *==============================================================================
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *==============================================================================
 *******************************************************************************/

#include "widget.h"
#include "widget_struct.h"
#include "widget_linklist.h"
#include "msf_mem.h"
#include "gdi_include.h"
#include "wgui_include.h"
#include "lcd_sw_rnd.h"
#include "PixcomFontEngine.h"

static const kal_uint8 widget_dashed_line_bitvalues[] = {1, 1, 1, 1, 0};
static const kal_uint8 widget_dotted_line_bitvalues[] = {1, 0};

#ifdef __MMI_BROWSER_2__
extern MMI_BOOL mmi_brw_app_is_temp_busy_screen_active(void);
#endif
extern const kal_uint16 gMaxDeployedLangs;

/*Dinesh*/
extern MMI_BOOL mmi_fe_get_glyph_metrics(U16 ch, mmi_fe_glyph_metrics_struct_p matrix);
/*end Dinesh*/

#ifdef __PLUTO_MMI_PACKAGE__
extern S32 is_on_idlescreen();
#endif
//============================================================================
// Implement the Bresenham's line drawing algorithm for all
// slopes and line directions
// Reference to Derivation for first octant based on version 
// in Hearn & Baker's "Computer Graphics" Explanations and Generalizations 
// written by Kenny Hoff September 2, 1995
// "Derivation of Bresenham's Line Algorithm"
//============================================================================

#define WIDGET_INVALID_COORDINATE_VAL       (-10000)

typedef struct
{
    MsfPosition start;
    MsfPosition end;
}widget_line_struct;


/*****************************************************************************
 * FUNCTION
 *  add_to_gen_array
 * DESCRIPTION
 *  For draw the fill polygon 
 * PARAMETERS
 *  Ax          [IN]        
 *  Ay          [IN]        
 *  Bx          [IN]        
 *  By          [IN]        
 *  Color       [IN]        
 *  gen_array   [IN]
 *  in_vertical [IN]        
 *  array_size  [IN]        
 *  array       [IN/OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void add_to_gen_array(MSF_INT16 Ax, MSF_INT16 Ay, kal_bool in_vertical, int array_size, widget_line_struct *array)
{
    int i;

    WAP_DBG_ASSERT(Ax != WIDGET_INVALID_COORDINATE_VAL);
    WAP_DBG_ASSERT(Ay != WIDGET_INVALID_COORDINATE_VAL);

    if (in_vertical)
    {
        /* will fill the polygon in vertical line */
        for (i = 0; i < array_size; i++)
        {
            if (Ax == array[i].start.x && Ax == array[i].end.x)
            {
                if (Ay > array[i].end.y)
                {
                    WAP_DBG_ASSERT(array[i].start.y == WIDGET_INVALID_COORDINATE_VAL);
                    array[i].start.y = array[i].end.y;
                    array[i].end.y = Ay;
                }
                else if (array[i].start.y == WIDGET_INVALID_COORDINATE_VAL || Ay < array[i].start.y)
                {
                    array[i].start.y = Ay;
                }
            }
        }
    }
    else
    {
        /* will fill the polygon in horizontal line */
        for (i = 0; i < array_size; i++)
        {
            if (Ay == array[i].start.y && Ay == array[i].end.y)
            {
                if (Ax > array[i].end.x)
                {
                    WAP_DBG_ASSERT(array[i].start.x == WIDGET_INVALID_COORDINATE_VAL);
                    array[i].start.x = array[i].end.x;
                    array[i].end.x = Ax;
                }
                else if (array[i].start.x == WIDGET_INVALID_COORDINATE_VAL || Ax < array[i].start.x)
                {
                    array[i].start.x = Ax;
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  BresLine
 * DESCRIPTION
 *  
 * PARAMETERS
 *  Ax          [IN]        
 *  Ay          [IN]        
 *  Bx          [IN]        
 *  By          [IN]        
 *  Color       [IN]        
 *  gen_array   [IN]
 *  in_vertical [IN]        
 *  array_size  [IN]        
 *  array       [IN/OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
static void BresLine(
                int Ax, 
                int Ay, 
                int Bx, 
                int By, 
                color Color, 
                kal_bool gen_array, 
                kal_bool in_vertical, 
                int array_size, 
                widget_line_struct * array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    //------------------------------------------------------------------------
    // INITIALIZE THE COMPONENTS OF THE ALGORITHM THAT ARE NOT AFFECTED BY THE
    // SLOPE OR DIRECTION OF THE LINE
    //------------------------------------------------------------------------
    int dX = abs(Bx - Ax);  /* store the change in X and Y of the line endpoints */
    int dY = abs(By - Ay);

    //------------------------------------------------------------------------
    // DETERMINE "DIRECTIONS" TO INCREMENT X AND Y (REGARDLESS OF DECISION)
    //------------------------------------------------------------------------
    int Xincr, Yincr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (Ax > Bx)
    {
        Xincr = -1;
    }
    else
    {
        Xincr = 1;
    }   /* which direction in X? */
    if (Ay > By)
    {
        Yincr = -1;
    }
    else
    {
        Yincr = 1;
    }   /* which direction in Y? */

    //------------------------------------------------------------------------
    // DETERMINE INDEPENDENT VARIABLE (ONE THAT ALWAYS INCREMENTS BY 1 (OR -1) )
    // AND INITIATE APPROPRIATE LINE DRAWING ROUTINE (BASED ON FIRST OCTANT
    // ALWAYS). THE X AND Y'S MAY BE FLIPPED IF Y IS THE INDEPENDENT VARIABLE.
    //------------------------------------------------------------------------
    if (dX >= dY)   /* if X is the independent variable */
    {
        int dPr = dY << 1;          /* amount to increment decision if right is chosen (always) */
        int dPru = dPr - (dX << 1); /* amount to increment decision if up is chosen */
        int P = dPr - dX;           /* decision variable start value */

        for (; dX >= 0; dX--)   /* process each point in the line one at a time (just use dX) */
        {
            gui_putpixel(Ax, Ay, Color);
            if (gen_array)
            {
                add_to_gen_array(
                    (MSF_INT16)Ax, 
                    (MSF_INT16)Ay, 
                    in_vertical, 
                    array_size, array);
            }

            if (P > 0)  /* is the pixel going right AND up? */
            {
                Ax += Xincr;    /* increment independent variable */
                Ay += Yincr;    /* increment dependent variable */
                P += dPru;      /* increment decision (for up) */
            }
            else    /* is the pixel just going right? */
            {
                Ax += Xincr;    /* increment independent variable */
                P += dPr;       /* increment decision (for right) */
            }
        }
    }
    else    /* if Y is the independent variable */
    {
        int dPr = dX << 1;          /* amount to increment decision if right is chosen (always) */
        int dPru = dPr - (dY << 1); /* amount to increment decision if up is chosen */
        int P = dPr - dY;           /* decision variable start value */

        for (; dY >= 0; dY--)   /* process each point in the line one at a time (just use dY) */
        {
            gui_putpixel(Ax, Ay, Color);
            if (gen_array)
            {
                add_to_gen_array(
                    (MSF_INT16)Ax, 
                    (MSF_INT16)Ay, 
                    in_vertical, 
                    array_size, array);
            }
            if (P > 0)  /* is the pixel going up AND right? */
            {
                Ax += Xincr;    /* increment dependent variable */
                Ay += Yincr;    /* increment independent variable */
                P += dPru;      /* increment decision (for up) */
            }
            else    /* is the pixel just going up? */
            {
                Ay += Yincr;    /* increment independent variable */
                P += dPr;       /* increment decision (for right) */
            }
        }
    }
}



/****************************************************************
 * Clipping
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  widget_clipping_intersection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN/OUT]         
 *  y1      [IN/OUT]         
 *  x2      [IN/OUT]         
 *  y2      [IN/OUT]         
 *  ax1     [IN]        
 *  ay1     [IN]        
 *  ax2     [IN]        
 *  ay2     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool widget_clipping_intersection(int *x1, int *y1, int *x2, int *y2, int ax1, int ay1, int ax2, int ay2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*x1 > ax2)
    {
        return KAL_FALSE;
    }
    if (*x2 < ax1)
    {
        return KAL_FALSE;
    }
    if (*y1 > ay2)
    {
        return KAL_FALSE;
    }
    if (*y2 < ay1)
    {
        return KAL_FALSE;
    }

    if (*x1 < ax1)
    {
        *x1 = ax1;
    }
    if (*x2 > ax2)
    {
        *x2 = ax2;
    }
    if (*y1 < ay1)
    {
        *y1 = ay1;
    }
    if (*y2 > ay2)
    {
        *y2 = ay2;
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  WIDGET_BEGIN_DRAWING
 * DESCRIPTION
 *  handle
 *  pos
 *  set_text_clip  IN Set text clipping in addition to draw clipping
 * PARAMETERS
 *  handle              [IN]        
 *  pos                 [IN]         
 *  border_pos          [IN]         
 *  border_size         [IN]         
 *  set_text_clip       [IN]        
 * RETURNS
 *  < 0 for failure
 *****************************************************************************/
static int WIDGET_BEGIN_DRAWING_EX(MSF_UINT32 handle, MsfPosition *pos, MsfPosition *border_pos, MsfSize *border_size, kal_bool set_text_clip)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int cx1, cx2, cy1, cy2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(handle);

    if (!WGUI_CTX->is_widget_screen)
    {
        return -1;
    }

    if (IS_PAINTBOX_TYPE(handle) && !WGUI_CTX->in_paintbox)
    {
        return -1;
    }
#ifdef __MMI_BROWSER_2__    
    if(mmi_brw_app_is_temp_busy_screen_active())
	{
		return -1;
	}
#endif    
    WAP_DBG_ASSERT(GDI_LCD->act_handle == GDI_LCD_MAIN_LCD_HANDLE);
#ifdef __COSMOS_MMI_PACKAGE__
	widget_set_active_layer();
#endif

    if (IS_IMAGE_TYPE(handle))
    {
        kal_bool res;
        int bound_x1, bound_x2, bound_y1, bound_y2;

        /* Because marquee/blinking text use this API, and it might draw after scrollbar is painted. */
        cx1 = pos->x = WGUI_CTX->current_pos.x + _IMG(handle)->draw_op_position.x;
        cy1 = pos->y = WGUI_CTX->current_pos.y + _IMG(handle)->draw_op_position.y;
        cx2 = cx1 + _IMG(handle)->draw_op_max_size.width - 1;
        cy2 = cy1 + _IMG(handle)->draw_op_max_size.height - 1;
        widget_paint_display_clipping_region(&bound_x1, &bound_y1, &bound_x2, &bound_y2);
        res = widget_clipping_intersection(&cx1, &cy1, &cx2, &cy2, bound_x1, bound_y1, bound_x2, bound_y2);

        /* Keep the marquee area */
        border_pos->x = cx1;
        border_pos->y = cy1;
        border_size->width = cx2 - cx1 + 1;
        border_size->height = cy2 - cy1 + 1;
        /* For Marquee */
        pos->x += _IMG(handle)->draw_op_x_offset;
        pos->y += _IMG(handle)->draw_op_y_offset;

        if (!res)
        {
	#ifdef __COSMOS_MMI_PACKAGE__
	        widget_reset_active_layer();
        #endif
            return -1;
        }
    }
    else
    {
        WAP_DBG_ASSERT(IS_PAINTBOX_TYPE(handle));

        pos->x = WGUI_CTX->display_pos.x;
        pos->y = WGUI_CTX->display_pos.y;
        cx1 = pos->x;
        cy1 = pos->y;
        cx2 = pos->x + WGUI_CTX->display_size.width - 1;
        cy2 = pos->y + WGUI_CTX->display_size.height - 1;
/* ARK */
	if (WGUI_CTX->current_vertical_scrollbar)
        {
            cx2 -= WGUI_CTX->current_vertical_scrollbar->size.width;
        }

        if (WGUI_CTX->current_horizontal_scrollbar)
        {
            cy2 -= WGUI_CTX->current_horizontal_scrollbar->size.height;
        }
/* end */
    }

    /*
     * Widget drawing is invoked in WAP task directly to reduce memory for caching paintbox
     * * context and overheads introduced by widget_execute_MMI().
     * * As a result, we should backup and restore the graphics context.
     */

    gui_lock_double_buffer();
    gui_push_clip();
    gui_set_clip(cx1, cy1, cx2, cy2);
    if (set_text_clip)
    {
        gui_push_text_clip();
        gui_set_text_clip(cx1, cy1, cx2, cy2);
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  WIDGET_BEGIN_DRAWING
 * DESCRIPTION
 *  handle
 *  pos
 *  set_text_clip  IN Set text clipping in addition to draw clipping
 * PARAMETERS
 *  handle              [IN]        
 *  pos                 [IN]         
 *  set_text_clip       [IN]        
 * RETURNS
 *  < 0 for failure
 *****************************************************************************/
static int WIDGET_BEGIN_DRAWING(MSF_UINT32 handle, MsfPosition *pos, kal_bool set_text_clip)
{
    MsfPosition border_pos;
    MsfSize border_size;
    
    return WIDGET_BEGIN_DRAWING_EX(handle, pos, &border_pos, &border_size, set_text_clip);
}


/*****************************************************************************
 * FUNCTION
 *  WIDGET_END_DRAWING
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle              [IN]        
 *  set_text_clip       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void WIDGET_END_DRAWING(MSF_UINT32 handle, kal_bool set_text_clip)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (set_text_clip)
    {
        gui_pop_text_clip();
    }
    gui_pop_clip();
    gui_unlock_double_buffer();
#ifdef __COSMOS_MMI_PACKAGE__
	widget_reset_active_layer();
#endif

    /* If we invoke widget_paint for MsfImage,  it will enter infinite loop */
    if (IS_PAINTBOX_TYPE(handle) && !(_H(handle)->flag & WIDGET_FLAG_HOLD_DRAW))
    {
        /*
         * If HDIa_widgetHoldDraw() is invoked before, HDIa_widgetPerformDraw() will invoke widget_paint() again.
         * * Otherwise, we should invoke widget_paint() such that it will invoke gui_BLT_double_buffer later.
         * * 
         * * Note that we do not call gui_BLT_double_buffer() here because we need widget_paint() to draw 
         * * scrollbars and outside look.
         */
        widget_paint();
    }
}

#define WIDGET_TO_QUEUE_DRAWING_OP(handle) (IS_IMAGE_TYPE(handle) && !_IMG(handle)->draw_op_directly)

/* Release the linked list and allocated internal data */


/*****************************************************************************
 * FUNCTION
 *  widget_draw_op_release
 * DESCRIPTION
 *  
 * PARAMETERS
 *  draw_op     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef WAP_USE_ASM
void widget_draw_op_release(widget_draw_op_struct *draw_op, MSF_UINT8 mod_id)
#else
void widget_draw_op_release(widget_draw_op_struct *draw_op)
#endif
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_draw_op_struct *next;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (draw_op)
    {
        next = draw_op->next;
        switch (draw_op->type)
        {
            case WIDGET_DRAW_OP_STRING:
            {
                HDIa_widgetRelease(draw_op->_u.string.string);
                draw_op->_u.string.string = 0;
                break;
            }
            case WIDGET_DRAW_OP_POLYGON:
            {
                #ifdef WAP_USE_ASM
                widget_internal_mem_free(mod_id, draw_op->_u.polygon.corners);
                #else
                MSF_MEM_FREE(MSF_MODID_WIDGET, draw_op->_u.polygon.corners);
                #endif
                draw_op->_u.polygon.corners = NULL;
                break;
            }
            case WIDGET_DRAW_OP_IMAGE:
            {
                if (draw_op->_u.image.maxSize)
                {
#ifdef WAP_USE_ASM
                    widget_internal_mem_free(mod_id, draw_op->_u.image.maxSize);
#else
                    MSF_MEM_FREE(MSF_MODID_WIDGET, draw_op->_u.image.maxSize);
#endif
                }
                draw_op->_u.image.maxSize = NULL;
                break;
            }
        }
#ifdef WAP_USE_ASM
        widget_internal_mem_free(mod_id, draw_op);
#else
        MSF_MEM_FREE(MSF_MODID_WIDGET, draw_op);
#endif
        draw_op = next;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_draw_image_from_queued_op
 * DESCRIPTION
 *  
 * PARAMETERS
 *  img             [IN]        
 *  position        [IN]        Position (relative to content area)
 *  maxSize         [IN]        Clipping region of image object
 *  x_offset        [IN]        Used by marquee
 *  y_offset        [IN]        Used by marquee
 * RETURNS
 *  void
 *****************************************************************************/
void widget_draw_image_from_queued_op(
        widget_image_struct *img,
        MsfPosition *position,
        MsfSize *maxSize,
        kal_int16 x_offset,
        kal_int16 y_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_draw_op_struct *draw_op;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    img->draw_op_directly = KAL_TRUE;

    // TODO: set clipping?
    /* Used in BEGIN_DRAWING later */
    img->draw_op_position = *position;
    img->draw_op_max_size = *maxSize;
    img->draw_op_x_offset = x_offset;
    img->draw_op_y_offset = y_offset;

    draw_op = img->draw_op_head;
    while (draw_op)
    {
        switch (draw_op->type)
        {
            case WIDGET_DRAW_OP_LINE:
            {
                widget_style_struct *style = _STYLE(widget_get_style((MSF_UINT32) img));
                MsfColor backup_color;

                ASSERT(style);
                backup_color = style->fg_color;
                style->fg_color = draw_op->_u.line.color;
                HDIa_widgetDrawLine((MSF_UINT32) img, &draw_op->_u.line.start, &draw_op->_u.line.end);
                style->fg_color = backup_color;
            }
                break;
            case WIDGET_DRAW_OP_RECT:
            {
            #ifdef WIDGET_DRAW_RECT_STORE_STYLE
                widget_style_struct *style = _STYLE(widget_get_style((MSF_UINT32) img));
                MsfColor backup_fg_color, backup_bg_color;

                backup_fg_color = style->fg_color;
                backup_bg_color = style->bg_color;
                style->fg_color = draw_op->_u.rect.fg_color;
                style->bg_color = draw_op->_u.rect.bg_color;
                HDIa_widgetDrawRect(
                    (MSF_UINT32) img,
                    &draw_op->_u.rect.position,
                    &draw_op->_u.rect.size,
                    draw_op->_u.rect.fill);
                style->fg_color = backup_fg_color;
                style->bg_color = backup_bg_color;
            #else /* WIDGET_DRAW_RECT_STORE_STYLE */ 
                HDIa_widgetDrawRect(
                    (MSF_UINT32) img,
                    &draw_op->_u.rect.position,
                    &draw_op->_u.rect.size,
                    draw_op->_u.rect.fill);
            #endif /* WIDGET_DRAW_RECT_STORE_STYLE */ 
            }
                break;
            case WIDGET_DRAW_OP_STRING:
        #ifdef WIDGET_COMPACT_IMAGE_DRAW_OP
                HDIa_widgetDrawString(
                    (MSF_UINT32) img,
                    draw_op->_u.string.string,
                    &draw_op->_u.string.position,
                    (draw_op->_u.string.maxSize.width < 0) ? NULL : &draw_op->_u.string.maxSize,
                    0,
                    0,
                    draw_op->_u.string.baseline,
                    draw_op->_u.string.useBrushStyle);
        #else /* WIDGET_COMPACT_IMAGE_DRAW_OP */ 
                HDIa_widgetDrawString(
                    (MSF_UINT32) img,
                    draw_op->_u.string.string,
                    &draw_op->_u.string.position,
                    (draw_op->_u.string.maxSize.width < 0) ? NULL : &draw_op->_u.string.maxSize,
                    draw_op->_u.string.index,
                    draw_op->_u.string.nbrOfChars,
                    draw_op->_u.string.baseline,
                    draw_op->_u.string.useBrushStyle);
        #endif /* WIDGET_COMPACT_IMAGE_DRAW_OP */ 
                break;
            case WIDGET_DRAW_OP_POLYGON:
                {
/* IMAGE_MAP */
                widget_style_struct *style = _STYLE(widget_get_style((MSF_UINT32) img));
                //MsfColor backup_fg_color, backup_bg_color;

                //backup_fg_color = style->fg_color;
                //backup_bg_color = style->bg_color;
                style->fg_color = draw_op->_u.rect.fg_color;
                style->bg_color = draw_op->_u.rect.bg_color;
/* IMAGE_MAP */
                HDIa_widgetDrawPolygon(
                    (MSF_UINT32) img,
                    draw_op->_u.polygon.nbrOfCorners,
                    draw_op->_u.polygon.corners,
                    draw_op->_u.polygon.fill);
                }
                break;
            case WIDGET_DRAW_OP_ARC:
{
/* IMAGE_MAP */
                widget_style_struct *style = _STYLE(widget_get_style((MSF_UINT32) img));
               // MsfColor backup_fg_color, backup_bg_color;

               // backup_fg_color = style->fg_color;
               // backup_bg_color = style->bg_color;
                style->fg_color = draw_op->_u.arc.fg_color;
                style->bg_color = draw_op->_u.arc.bg_color;
/* IMAGE_MAP */
                HDIa_widgetDrawArc(
                        (MSF_UINT32) img,
                        &draw_op->_u.arc.position,                        
                        draw_op->_u.arc.size,
                        draw_op->_u.arc.startAngle,
                        draw_op->_u.arc.angleExtent,
                        draw_op->_u.arc.fill);
}
                break;
            case WIDGET_DRAW_OP_ICON:
                HDIa_widgetDrawIcon(
                    (MSF_UINT32) img,
                    draw_op->_u.icon.icon,
                    &draw_op->_u.icon.position);
                break;
            case WIDGET_DRAW_OP_IMAGE:
                /* We need be very careful because we do not duplicate the image object */
                if (IS_IMAGE_TYPE(draw_op->_u.image.image))
                {
                    HDIa_widgetDrawImage(
                        (MSF_UINT32) img,
                        draw_op->_u.image.image,
                        &draw_op->_u.image.position,
                        draw_op->_u.image.maxSize,
                        draw_op->_u.image.imageZoom);
                }
                else
                {
                    /* Image already deallocated */
                
                    //ASSERT(0);
                
                }
                break;
            default:
                ASSERT(0);
        }
        draw_op = draw_op->next;
    }

    img->draw_op_directly = KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_enqueue_draw_op
 * DESCRIPTION
 *  
 * PARAMETERS
 *  head        [IN]        
 *  tail        [IN]        
 *  draw_op     [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void widget_enqueue_draw_op(
        widget_draw_op_struct **head,
        widget_draw_op_struct **tail,
        widget_draw_op_struct *draw_op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * We push the operation at the end of the list such that all operations are executed by order.
     */
    ASSERT(draw_op);
    WAP_DBG_ASSERT(draw_op->next == NULL);
    draw_op->next = NULL;

    if (*head == NULL)
    {
        *head = *tail = draw_op;
    }
    else
    {
        WAP_DBG_ASSERT((*tail)->next == NULL);
        (*tail)->next = draw_op;
        *tail = draw_op;
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetHoldDraw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfHandle       [IN]        
 * RETURNS
 *  int
 *****************************************************************************/
int HDIa_widgetHoldDraw(MSF_UINT32 msfHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: this does not guarentee that we will delay gui_BLT_double_buffer until HDIa_widgetPerformDraw
    /* We should disable widget_paint_hdlr() in other place  */

    if (IS_PAINTBOX_TYPE(msfHandle))
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_HOLD_DRAW_PAINTBOX);
        if (WGUI_CTX->focus_paintbox_without_painting &&
            (WGUI_CTX->is_widget_screen && WGUI_CTX->in_paintbox))
        {
            /*
             * If the application draw something on paintbox first time, 
             * we will clear all screen.
             */
            widget_clear_screen();
            WGUI_CTX->focus_paintbox_without_painting = 0;
            /*
             * We hide the status bar in BRA HoldDraw & PerformDraw process
             * Sometimes MsfDialog will pupop directly without drawing paintbox, and it causes the status bar problem.
             */
        //    wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_H_BAR);
        }

        enable_bit_flag(_H(msfHandle)->flag, WIDGET_FLAG_HOLD_DRAW);
        /* 
         * when scrolling a page with animated GIF, we should stop the animation
         * timer before redraw the paintbox
         */
#ifdef WIDGET_ANIMATED_GIF_SUPPORT
        widget_stop_animate(KAL_FALSE);
#endif /* WIDGET_ANIMATED_GIF_SUPPORT */
        /* Image/String Gadget does not exist in MsfImage */
#ifdef MSF_CFG_BRW_BLINKING_TEXT_SUPPORT
        widget_stop_all_blinking();
#endif
#ifdef MSF_CFG_BRW_MARQUEE_SUPPORT
        widget_stop_all_marquee();
#endif
    }
    else if (IS_IMAGE_TYPE(msfHandle))
    {
        // TODO: Unsupported
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_HOLD_DRAW_IMAGE);
    }
    else
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_HOLD_DRAW_UNSUPPORTED);
    }

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetPerformDraw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfHandle       [IN]        
 * RETURNS
 *  int
 *****************************************************************************/
int HDIa_widgetPerformDraw(MSF_UINT32 msfHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_PAINTBOX_TYPE(msfHandle))
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PERFORM_DRAW_PAINTBOX);

        disable_bit_flag(_H(msfHandle)->flag, WIDGET_FLAG_HOLD_DRAW);
        widget_stop_timer(WIDGET_PAINT_TIMER);
        widget_paint(); /* BRS might invoke HDIa_widgetPerformDraw many times */
    #ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
        widget_stop_all_image_nb_draw();
    #endif
        WGUI_CTX->disable_yes_key_in_paintbox = 0;  /* Hack. We should enable it again */
    }
    else if (IS_IMAGE_TYPE(msfHandle))
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PERFORM_DRAW_IMAGE);
    }
    else
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PERFORM_DRAW_UNSUPPORTED);
    }

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  widget_push_draw_op_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfHandle       [IN]        
 *  start           [IN]        
 *  end             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static __inline void widget_push_draw_op_line(MSF_UINT32 msfHandle, const MsfPosition *start, const MsfPosition *end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_image_struct *img = _IMG(msfHandle);
#ifdef WAP_USE_ASM
    widget_draw_op_struct *draw_op = widget_internal_mem_alloc(img->module_id, sizeof(widget_draw_op_struct));
#else
    widget_draw_op_struct *draw_op = MSF_MEM_ALLOC(MSF_MODID_WIDGET, sizeof(widget_draw_op_struct));
#endif
    widget_style_struct *style = _STYLE(widget_get_style(msfHandle));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    draw_op->type = WIDGET_DRAW_OP_LINE;
    draw_op->next = NULL;
    draw_op->_u.line.start = *start;
    draw_op->_u.line.end = *end;
    draw_op->_u.line.color = style->fg_color;
    widget_enqueue_draw_op(&img->draw_op_head, &img->draw_op_tail, draw_op);
}

/*****************************************************************************
 * FUNCTION
 *  widget_push_draw_op_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfHandle       [IN]        
 *  start           [IN]        
 *  end             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static __inline void widget_push_draw_op_icon(MSF_UINT32 msfHandle, MsfIconHandle icon, MsfPosition *position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_image_struct *img = _IMG(msfHandle);
#ifdef WAP_USE_ASM
    widget_draw_op_struct *draw_op = widget_internal_mem_alloc(img->module_id, sizeof(widget_draw_op_struct));
#else
    widget_draw_op_struct *draw_op = MSF_MEM_ALLOC(MSF_MODID_WIDGET, sizeof(widget_draw_op_struct));
#endif
    widget_style_struct *style = _STYLE(widget_get_style(msfHandle));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    draw_op->type = WIDGET_DRAW_OP_ICON; //ankit
    draw_op->next = NULL;
    draw_op->_u.icon.position = *position;
    draw_op->_u.icon.icon = icon;    
    widget_enqueue_draw_op(&img->draw_op_head, &img->draw_op_tail, draw_op);
}

/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetDrawLine
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfHandle       [IN]        
 *  start           [IN]         
 *  end             [IN]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetDrawLine(MSF_UINT32 msfHandle, MsfPosition *start, MsfPosition *end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_style_struct *style = (widget_style_struct*) widget_get_style(msfHandle);
    MsfPosition pos;
    S32 x1, x2, y1, y2;
    gdi_color color;
    gdi_color background_color;
    int thickness;
    int horizontal;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WIDGET_TO_QUEUE_DRAWING_OP(msfHandle))
    {
        widget_push_draw_op_line(msfHandle, start, end);
        return 1;
    }

    if (WIDGET_BEGIN_DRAWING(msfHandle, &pos, KAL_FALSE) < 0)
    {
        return 0;
    }

    ASSERT(style);

    x1 = pos.x + start->x;
    x2 = pos.x + end->x;
    y1 = pos.y + start->y;
    y2 = pos.y + end->y;
    color = gdi_act_color_from_rgb(255, style->fg_color.r, style->fg_color.g, style->fg_color.b);
    background_color = gdi_act_color_from_rgb(255, style->bg_color.r, style->bg_color.g, style->bg_color.b);
    if (x1 == x2)
    {
        horizontal = 0;
    }
    else
    {
        WAP_DBG_ASSERT(y1 == y2);   /* Implementation limitation */
        horizontal = 1;
    }

#if 0   /* Not supported well by BRS */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* 0 */ 
    {
        thickness = style->line_style.thickness;

        while (thickness > 0)
        {
            switch (style->line_style.style)
            {
                case MsfDotted:
 /* First we will draw Solid line with Background color and then we will draw dotted line with required color */ 
                    gdi_draw_line(x1, y1, x2, y2, background_color);
                    gdi_draw_line_style(
                        x1,
                        y1,
                        x2,
                        y2,
                        color,
                        sizeof(widget_dotted_line_bitvalues),
                        widget_dotted_line_bitvalues);
                    break;
                case MsfDashed:
/* First we will draw Solid line with Background color and then we will draw dashed line with required color */ 
                    gdi_draw_line(x1, y1, x2, y2, background_color);
                    gdi_draw_line_style(
                        x1,
                        y1,
                        x2,
                        y2,
                        color,
                        sizeof(widget_dashed_line_bitvalues),
                        widget_dashed_line_bitvalues);
                    break;
                default:
                    gdi_draw_line(x1, y1, x2, y2, color);
            }
            if (horizontal)
            {
                y1++;
                y2++;
            }
            else
            {
                x1++;
                x2++;
            }
            thickness--;
        }
    }
#endif /* 0 */ 

    WIDGET_END_DRAWING(msfHandle, KAL_FALSE);

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  widget_push_draw_op_rect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfHandle       [IN]        
 *  style           [IN]         
 *  position        [IN]         
 *  size            [IN]         
 *  fill            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static __inline void widget_push_draw_op_rect(
                        MSF_UINT32 msfHandle,
                        widget_style_struct *style,
                        MsfPosition *position,
                        MsfSize *size,
                        int fill)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_image_struct *img = _IMG(msfHandle);

#ifdef WAP_USE_ASM
    widget_draw_op_struct *draw_op = widget_internal_mem_alloc(img->module_id, sizeof(widget_draw_op_struct));
#else
    widget_draw_op_struct *draw_op = MSF_MEM_ALLOC(MSF_MODID_WIDGET, sizeof(widget_draw_op_struct));
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* TMP patch for memory leak caused by marquee. VERY TRICKY. */
#ifdef WIDGET_TMPFIX_MARQUEE_BGCOLOR
    if (img->parent && IS_GADGET_IMAGE_TYPE(img->parent) && _GIMG(img->parent)->marquee)
    {
/* MAUI_01565380 */
if(0) 
{
#ifdef WAP_USE_ASM
        widget_draw_op_release(img->draw_op_head, img->module_id);
#else
        widget_draw_op_release(img->draw_op_head);
#endif
        img->draw_op_head = img->draw_op_tail = NULL;
        return;
    }
    }
#endif /* WIDGET_TMPFIX_MARQUEE_BGCOLOR */ 

    draw_op->type = WIDGET_DRAW_OP_RECT;
    draw_op->next = NULL;
    draw_op->_u.rect.position = *position;
    draw_op->_u.rect.size = *size;
    draw_op->_u.rect.fill = fill;
    /*
     * Obigo implementation assume that we have a memory buffer for drawing, but we 
     * * only enqueue the drawing operation. 
     * * Because BRS might change the background color later,  it is better to 
     * * backup the current color. 
     */
#ifdef WIDGET_DRAW_RECT_STORE_STYLE
    draw_op->_u.rect.fg_color = style->fg_color;
    draw_op->_u.rect.bg_color = style->bg_color;
#endif /* WIDGET_DRAW_RECT_STORE_STYLE */ 

    widget_enqueue_draw_op(&img->draw_op_head, &img->draw_op_tail, draw_op);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetDrawRect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfHandle       [IN]        
 *  position        [IN]         
 *  size            [IN]         
 *  fill            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetDrawRect(MSF_UINT32 msfHandle, MsfPosition *position, MsfSize *size, int fill)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_style_struct *style = (widget_style_struct*) widget_get_style(msfHandle);
    MsfPosition pos;
    color c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BROWSER_2__    
    if(mmi_brw_app_is_temp_busy_screen_active())
    {
		return 0;
    }
#endif	
    if (WIDGET_TO_QUEUE_DRAWING_OP(msfHandle))
    {
        widget_push_draw_op_rect(msfHandle, style, position, size, fill);
        return 1;
    }

    if (WIDGET_BEGIN_DRAWING(msfHandle, &pos, KAL_FALSE) < 0)
    {
        return 0;
    }

    ASSERT(style);
    WAP_DBG_ASSERT(style->line_style.thickness == 1 || style->line_style.thickness == 0);
    if (!WGUI_CTX->is_widget_screen)
    {
    	WIDGET_END_DRAWING(msfHandle, KAL_FALSE);
        return 0;
    }

    if (fill)
    {
        c.alpha = 100;
        c.r = style->bg_color.r;
        c.g = style->bg_color.g;
        c.b = style->bg_color.b;
        /* If we have reached on Idle Screen then we should not perform any drawing operation*/
#ifdef __PLUTO_MMI_PACKAGE__
	if(is_on_idlescreen())
	{
	    WIDGET_END_DRAWING(msfHandle, KAL_FALSE);
	    return 0;
	}
#endif
#ifdef __MMI_BROWSER_2__
	if(mmi_brw_app_is_temp_busy_screen_active())
	{
		WIDGET_END_DRAWING(msfHandle, KAL_FALSE);
		return 0;
	}
#endif	
	if (WGUI_CTX->current_vertical_scrollbar && position->x + pos.x + size->width - 1 > WGUI_CTX->display_size.width - WGUI_CTX->current_vertical_scrollbar->size.width)
	{
	     gui_fill_rectangle(
		position->x + pos.x,
		position->y + pos.y,
		WGUI_CTX->display_size.width - WGUI_CTX->current_vertical_scrollbar->size.width - 1,  /* FIXME. workaround of old bug, should be substracted with 1 */
		position->y + pos.y + size->height - 1,
		c);
         }
	else 
	{
        gui_fill_rectangle(
            position->x + pos.x,
            position->y + pos.y,
            position->x + pos.x + size->width - 1,  /* FIXME. workaround of old bug, should be substracted with 1 */
            position->y + pos.y + size->height - 1,
            c);
         }
    }
    else
    {
        c.alpha = 100;
        c.r = style->fg_color.r;
        c.g = style->fg_color.g;
        c.b = style->fg_color.b;

        gui_draw_rectangle(
            position->x + pos.x,
            position->y + pos.y,
            position->x + pos.x + size->width - 1,
            position->y + pos.y + size->height - 1,
            c);
    }

    WIDGET_END_DRAWING(msfHandle, KAL_FALSE);

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetDrawIconWithSize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfHandle       [IN]        
 *  icon            [IN]        
 *  position        [IN]         
 * RETURNS
 *  int
 *****************************************************************************/
int HDIa_widgetDrawIconWithSize(MSF_UINT32 msfHandle, MsfIconHandle icon, MsfPosition *position, MsfSize *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfPosition pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* It seems that position set by BRS is not correct in this case. So If BRS se negative 
    * y co-ods then we will not dispaly that icon. MAUI_02425116 */
    if(position->y < 0)
    {
        return 0;
    }
    if (WIDGET_TO_QUEUE_DRAWING_OP(msfHandle))
    {
        return 1;
    }

    if (WIDGET_BEGIN_DRAWING(msfHandle, &pos, KAL_FALSE) < 0)
    {
        return 0;
    }
   if((WGUI_CTX->display_size.height  + WGUI_CTX->display_pos.y) < position->y + pos.y + size->height)
   {
       gdi_layer_set_clip(position->x + pos.x - 1, position->y + pos.y - 1, position->x + pos.x + size->width, WGUI_CTX->display_size.height  + WGUI_CTX->display_pos.y - 1);
   }
   else
   {
    gdi_layer_set_clip(position->x + pos.x - 1, position->y + pos.y - 1, position->x + pos.x + size->width, position->y + pos.y + size->height);
   }
    gui_show_transparent_image(
        position->x + pos.x,
        position->y + pos.y,
        (kal_uint8*) _ICON(icon)->icon_data,
        gui_transparent_color(0, 0, 0));
    WIDGET_END_DRAWING(msfHandle, KAL_FALSE);

    return 1;
}  
	
/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetDrawIcon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfHandle       [IN]        
 *  icon            [IN]        
 *  position        [IN]         
 * RETURNS
 *  int
 *****************************************************************************/
int HDIa_widgetDrawIcon(MSF_UINT32 msfHandle, MsfIconHandle icon, MsfPosition *position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfPosition pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WIDGET_TO_QUEUE_DRAWING_OP(msfHandle))
    {
        widget_push_draw_op_icon(msfHandle, icon, position);
        return 1;
    }

    if (WIDGET_BEGIN_DRAWING(msfHandle, &pos, KAL_FALSE) < 0)
    {
        return 0;
    }

    gui_show_transparent_image(
        position->x + pos.x,
        position->y + pos.y,
        (kal_uint8*) _ICON(icon)->icon_data,
        gui_transparent_color(0, 0, 0));

    WIDGET_END_DRAWING(msfHandle, KAL_FALSE);

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  widget_BresenhamDrawArc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  circle_x        [IN]        
 *  circle_y        [IN]        
 *  circle_r        [IN]        
 *  startAngle      [IN]        
 *  angleExtent     [IN]        
 *  color           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_BresenhamDrawArc(S32 circle_x, S32 circle_y, S32 circle_r, int startAngle, int angleExtent, gdi_color color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* 
     * Bresenham Algorithm: Draw 1/8 circle
     */
    int x, y, d;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x = 0;
    y = circle_r;
    d = 1 - circle_r;

    while (x < y)
    {
        if ((startAngle >= 0 || startAngle <= 45 / 2) && (angleExtent > 45 / 2))
        {   /* first 1/8 circle, angle:(0~45), coord.:(x,y) */
            gdi_draw_point(circle_x + x, circle_y + y, color);
        }
        if ((startAngle > 45 - 45 / 2 || startAngle <= 45 + 45 / 2) && (angleExtent > 90 - 45 / 2))
        {   /* second 1/8 circle, angle:(45~90), coord.:(y,x) */
            gdi_draw_point(circle_x + y, circle_y + x, color);
        }
        if ((startAngle > 90 - 45 / 2 || startAngle <= 90 + 45 / 2) && (angleExtent > 135 - 45 / 2))
        {   /* third 1/8 circle, angle:(90~135), coord.:(y,-x) */
            gdi_draw_point(circle_x + y, circle_y - x, color);
        }
        if ((startAngle > 135 - 45 / 2 || startAngle <= 135 + 45 / 2) && (angleExtent > 180 - 45 / 2))
        {   /* fourth 1/8 circle, angle:(135~180), coord.:(x,-y) */
            gdi_draw_point(circle_x + x, circle_y - y, color);
        }
        if ((startAngle > 180 - 45 / 2 || startAngle <= 180 + 45 / 2) && (angleExtent > 225 - 45 / 2))
        {   /* fifth 1/8 circle, angle:(180~225), coord.:(-x,-y) */
            gdi_draw_point(circle_x - x, circle_y - y, color);
        }
        if ((startAngle > 225 - 45 / 2 || startAngle <= 225 + 45 / 2) && (angleExtent > 270 - 45 / 2))
        {   /* sixth 1/8 circle, angle:(225~270), coord.:(-y,-x) */
            gdi_draw_point(circle_x - y, circle_y - x, color);
        }
        if ((startAngle > 270 - 45 / 2 || startAngle <= 270 + 45 / 2) && (angleExtent > 315 - 45 / 2))
        {   /* fourth 1/8 circle, angle:(270~315), coord.:(-y,x) */
            gdi_draw_point(circle_x - y, circle_y + x, color);
        }
        if ((startAngle > 315 - 45 / 2 || startAngle <= 315 + 45 / 2) && (angleExtent > 360 - 45 / 2))
        {   /* fourth 1/8 circle, angle:(315~360), coord.:(-x,y) */
            gdi_draw_point(circle_x - x, circle_y + y, color);
        }

        if (d > 0)
        {
            d += 2 * (x - y) + 5;
            y--;
        }
        else
        {
            d += 2 * x + 3;
        }
        x++;
    }
}
//ankit
/*****************************************************************************
 * FUNCTION
 *  widget_push_draw_op_arc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfHandle       [IN]        
 *  nrOfCorners     [IN]        
 *  corners         [IN]         
 *  fill            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static __inline void widget_push_draw_op_arc(MSF_UINT32 msfHandle,
        MsfPosition *position,
        MsfSize *size,
        int startAngle,
        int angleExtent,
        int fill)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_image_struct *img = _IMG(msfHandle);
    widget_style_struct *style = (widget_style_struct*) widget_get_style(msfHandle);
#ifdef WAP_USE_ASM    
    widget_draw_op_struct *draw_op = widget_internal_mem_alloc(img->module_id, sizeof(widget_draw_op_struct));
#else
    widget_draw_op_struct *draw_op = MSF_MEM_ALLOC(MSF_MODID_WIDGET, sizeof(widget_draw_op_struct));
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    draw_op->type = WIDGET_DRAW_OP_ARC;
    draw_op->next = NULL;
    draw_op->_u.arc.position = *position;
if (size)
    {
#ifdef WAP_USE_ASM
        draw_op->_u.arc.size = (MsfSize*) widget_internal_mem_alloc(img->module_id, sizeof(MsfSize));       /* Released later */
#else
        draw_op->_u.arc.size = (MsfSize*) MSF_MEM_ALLOC(MSF_MODID_WIDGET, sizeof(MsfSize));       /* Released later */
#endif
        *draw_op->_u.arc.size = *size;
    }
    else
    {
        draw_op->_u.arc.size = NULL;
    }
    draw_op->_u.arc.startAngle = startAngle;
    draw_op->_u.arc.angleExtent = angleExtent;
    draw_op->_u.arc.fill = fill;
/* IMAGE_MAP */
    draw_op->_u.arc.fg_color = style->fg_color;
    draw_op->_u.arc.bg_color = style->bg_color;
/* IMAGE_MAP */
    widget_enqueue_draw_op(&img->draw_op_head, &img->draw_op_tail, draw_op);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetDrawArc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfHandle       [IN]        
 *  position        [IN]         
 *  size            [IN]         
 *  startAngle      [IN]        
 *  angleExtent     [IN]        
 *  fill            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetDrawArc(
        MSF_UINT32 msfHandle,
        MsfPosition *position,
        MsfSize *size,
        int startAngle,
        int angleExtent,
        int fill)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_style_struct *style = (widget_style_struct*) widget_get_style(msfHandle);
    MsfPosition pos;
    S32 x1, x2, y1, y2, circle_x, circle_y, circle_r;
    gdi_color color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WIDGET_TO_QUEUE_DRAWING_OP(msfHandle))
    {
        widget_push_draw_op_arc(msfHandle, position, size, startAngle, angleExtent, fill);
        return 1;
    }

    if (WIDGET_BEGIN_DRAWING(msfHandle, &pos, KAL_FALSE) < 0)
    {
        return 0;
    }

    x1 = pos.x + position->x;
    x2 = x1 + size->width;
    y1 = pos.y + position->y;
    y2 = y1 + size->height;
    circle_x = x1 + ((x2 - x1) >> 1);
    circle_y = y1 + ((y2 - y1) >> 1);
    if (size->width <= size->height)
    {
        circle_r = circle_x - x1;
    }
    else
    {
        circle_r = circle_y - y1;
    }

    color = gdi_act_color_from_rgb(255, style->fg_color.r, style->fg_color.g, style->fg_color.b);

    /* 
     * Bresenham Algorithm: Draw 1/8 circle
     */
    widget_BresenhamDrawArc(circle_x, circle_y, circle_r, startAngle, angleExtent, color);
    if (fill)
    {
        circle_r--;
        while (circle_r > 0)
        {
            widget_BresenhamDrawArc(circle_x, circle_y, circle_r, startAngle, angleExtent, color);
            gdi_draw_point(circle_x + circle_r, circle_y + circle_r, color);
            gdi_draw_point(circle_x + circle_r, circle_y - circle_r, color);
            gdi_draw_point(circle_x - circle_r, circle_y - circle_r, color);
            gdi_draw_point(circle_x - circle_r, circle_y + circle_r, color);
            circle_r--;
        }
        gdi_draw_point(circle_x, circle_y, color);
    }

    WIDGET_END_DRAWING(msfHandle, KAL_FALSE);

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  widget_push_draw_op_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfHandle           [IN]        
 *  string              [IN]        
 *  position            [IN]         
 *  maxSize             [IN]         
 *  index               [IN]        
 *  nbrOfChars          [IN]        
 *  baseline            [IN]        
 *  useBrushStyle       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static __inline void widget_push_draw_op_string(
                        MSF_UINT32 msfHandle,
                        MsfStringHandle string,
                        MsfPosition *position,
                        MsfSize *maxSize,
                        int index,
                        int nbrOfChars,
                        int baseline,
                        int useBrushStyle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_image_struct *img = _IMG(msfHandle);
#ifdef WAP_USE_ASM    
    widget_draw_op_struct *draw_op = widget_internal_mem_alloc(img->module_id, sizeof(widget_draw_op_struct));
#else
    widget_draw_op_struct *draw_op = MSF_MEM_ALLOC(MSF_MODID_WIDGET, sizeof(widget_draw_op_struct));
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    draw_op->type = WIDGET_DRAW_OP_STRING;
    draw_op->next = NULL;

    /* Released later */
#ifdef WIDGET_COMPACT_IMAGE_DRAW_OP
#ifdef WAP_USE_ASM
    draw_op->_u.string.string = widget_copy_partial_string(img->module_id, string, index, nbrOfChars, KAL_FALSE);
#else
    draw_op->_u.string.string = widget_copy_partial_string(MSF_MODID_WIDGET, string, index, nbrOfChars, KAL_FALSE);
#endif
#else 
#ifdef WAP_USE_ASM
    draw_op->_u.string.string = HDIa_widgetCopy(img->module_id, string);
#else
    draw_op->_u.string.string = HDIa_widgetCopy(MSF_MODID_WIDGET, string);
#endif
#endif 

    if (!useBrushStyle)
    {
        /*
         * If we share the same style object among the duplicated string handle, the style object might be already 
         * * changed when drawing another string.
         */
#ifdef WAP_USE_ASM
        MsfStyleHandle sh = widget_style_copy(img->module_id, widget_get_style(string));
#else
        MsfStyleHandle sh = widget_style_copy(MSF_MODID_WIDGET, widget_get_style(string));
#endif
        widget_string_struct *str = _STR(draw_op->_u.string.string);

        widget_set_attrib(str, style, sh);
        DEC_REF(sh);
    }
    else if (WGUI_CTX->in_paintbox)     // TODO: Tricky. SMIL does not need to copy brush style but marquee (with underline) need it
    {
#ifdef WAP_USE_ASM
        MsfStyleHandle sh = widget_style_copy(img->module_id, widget_get_style(msfHandle));
#else
        MsfStyleHandle sh = widget_style_copy(MSF_MODID_WIDGET, widget_get_style(msfHandle));
#endif
        widget_string_struct *str = _STR(draw_op->_u.string.string);

        widget_set_attrib(str, style, sh);
        DEC_REF(sh);
        useBrushStyle = 0;
    #ifdef WIDGET_TMPFIX_MARQUEE_BGCOLOR
        if (img->parent && _GIMG(img->parent)->marquee)
        {
            _STYLE(sh)->bg_color = widget_transparent_color;
        }
    #endif /* WIDGET_TMPFIX_MARQUEE_BGCOLOR */ 
    }
    draw_op->_u.string.position = *position;
    if (!maxSize)
    {
        draw_op->_u.string.maxSize.height = -1;
        draw_op->_u.string.maxSize.width = -1;
    }
    else
    {
        draw_op->_u.string.maxSize = *maxSize;
    }
#ifndef WIDGET_COMPACT_IMAGE_DRAW_OP
    draw_op->_u.string.index = index;
    draw_op->_u.string.nbrOfChars = nbrOfChars;
#endif /* WIDGET_COMPACT_IMAGE_DRAW_OP */ 
    draw_op->_u.string.baseline = baseline;
    draw_op->_u.string.useBrushStyle = useBrushStyle;

    widget_enqueue_draw_op(&img->draw_op_head, &img->draw_op_tail, draw_op);
}

/* Reference: widget_paint_gadget_string */
// TODO: handle the case that the baseline of Chinese and English is different.


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetDrawString
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfHandle           [IN]        
 *  string              [IN]        
 *  position            [IN]         
 *  maxSize             [IN]         
 *  index               [IN]        
 *  nbrOfChars          [IN]        
 *  baseline            [IN]        
 *  useBrushStyle       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetDrawString(
        MSF_UINT32 msfHandle,
        MsfStringHandle string,
        MsfPosition *position,
        MsfSize *maxSize,
        int index,
        int nbrOfChars,
        int baseline,
        int useBrushStyle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfPosition pos;    /* Absolute position of the region to draw */
    widget_style_struct *style;
    void *raw_data;
    stFontAttribute pfont;
    color fg_color;
    S32 text_width, text_height;
    S32 x1, y1, x2 /*, y2*/ ; /* Text region */
    int line_height, i;
	
	S32 tmp, ascent_val;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check the validity of input parameters */
    WIDGET_UNUSED(baseline);

    if ((raw_data = widget_string_content(string)) == NULL)
    {
        return 0;
    }
   /* In case of marquee maxSize can be greater than screen width. So put an additional check to ensure that we modify the maxSize only when maquee is not present in page 
   * though this is not the exact fix. Try to find the proper fix for it. While finding proper fix please take care of MAUI_02303714 and MAUI_02440783*/
#ifdef MSF_CFG_BRW_MARQUEE_SUPPORT
   if (WGUI_CTX->current_vertical_scrollbar && maxSize && (position->x + maxSize->width)  > WGUI_CTX->display_size.width - WGUI_CTX->current_vertical_scrollbar->size.width && (!WGUI_CTX->marquee_head))
#else
   if (WGUI_CTX->current_vertical_scrollbar && maxSize && (position->x + maxSize->width)  > WGUI_CTX->display_size.width - WGUI_CTX->current_vertical_scrollbar->size.width)
#endif /* MSF_CFG_BRW_MARQUEE_SUPPORT */
   {
	maxSize->width  = WGUI_CTX->display_size.width - WGUI_CTX->current_vertical_scrollbar->size.width - position->x - 1 ;
   }  
    /* Compute string length */
    if (nbrOfChars == 0)
    {
        nbrOfChars = STR_LEN((kal_uint8*) STR_AT(raw_data, index));
    }

    /* Get style */
    if (useBrushStyle)
    {
        style = _STYLE(widget_get_style(msfHandle));
    }
    else
    {
        style = _STYLE(widget_get_style(string));
    }
    WAP_RST_ASSERT(style);

    /* Is operation queued? */
    if (WIDGET_TO_QUEUE_DRAWING_OP(msfHandle))
    {
        widget_push_draw_op_string(msfHandle, string, position, maxSize, index, nbrOfChars, baseline, useBrushStyle);
        if (IS_IMAGE_TYPE(msfHandle))   /* Used for Marquee */
        {
            if (nbrOfChars)
            {
                pfont = widget_convert_to_system_font(&style->font);
                SetFont(pfont, 0);
                /* Compute string size and position */
                widget_get_string_width_height(raw_data, index, index + nbrOfChars, &text_width, &text_height);
                WIDGET_SET_MAX(_IMG(msfHandle)->draw_op_content_size.width, position->x + text_width);
                // TODO: The height is smaller than real value
                WIDGET_SET_MAX(_IMG(msfHandle)->draw_op_content_size.height, position->y + text_height);
            }
            else
            {
                WIDGET_SET_MAX(_IMG(msfHandle)->draw_op_content_size.width, position->x);
                WIDGET_SET_MAX(_IMG(msfHandle)->draw_op_content_size.height, position->y);
            }
        }
        return 1;
    }

    /* Begin drawing */
    if (WIDGET_BEGIN_DRAWING(msfHandle, &pos, KAL_TRUE) < 0)
    {
        return 0;
    }

    /* Set system font */
    pfont = widget_convert_to_system_font(&style->font);
    SetFont(pfont, 0);
    line_height = Get_CharHeightOfAllLang(pfont.size);

    /* Compute string size and position */
    widget_get_string_width_height(raw_data, index, index + nbrOfChars, &text_width, &text_height);
//    text_width += widget_get_string_width_deviation(pfont, text_height);  // API was returning 0.

    x1 = pos.x + position->x;
    y1 = pos.y + position->y;
    if (r2lMMIFlag && maxSize && (maxSize->width < text_width)) /* For Arabic */
    {
        x2 = x1 + maxSize->width - 1;
    }
    else
    {
        x2 = x1 + text_width - 1;
    }

    //y2 = y1 + WIDGET_FONT_TOP_SPACING + text_height + WIDGET_FONT_BOTTOM_SPACING - 1;
//	y2 = y1 + WIDGET_FONT_TOP_SPACING + line_height + WIDGET_FONT_BOTTOM_SPACING - 1;

    if (maxSize)
    {
        S32 tx1, tx2, ty1, ty2;

        gui_get_clip(&tx1, &ty1, &tx2, &ty2);

        if (r2lMMIFlag)
        {
            if (x2 - maxSize->width + 1 > tx1)
            {
                tx1 = x2 - maxSize->width + 1;
            }
        }
        else
        {
            if (x1 + maxSize->width - 1 < tx2)
            {
                tx2 = x1 + maxSize->width - 1;
            }
        }

        if (y1 + maxSize->height - 1 < ty2)
        {
            ty2 = y1 + maxSize->height - 1;
        }

        /* Assume that text clippng and normal clipping are the same.
           After 05B, these two types of clipping are merged. */
        gui_set_clip(tx1, ty1, tx2, ty2);
        gui_set_text_clip(tx1, ty1, tx2, ty2);
    }
    /* Draw text */
    if (r2lMMIFlag) /* Right-to-left scripts (e.g. Arabic) */
    {
        gui_move_text_cursor(x2, y1 + WIDGET_FONT_TOP_SPACING);
    }
    else
    {
        gui_move_text_cursor(x1, y1 + WIDGET_FONT_TOP_SPACING);
    }
    fg_color = gui_color((U8) style->fg_color.r, (U8) style->fg_color.g, (U8) style->fg_color.b);
    UI_set_current_text_color(fg_color);
    	 
	  tmp = 0;
	  ascent_val = 0;	

//    for (i = 0; i < gMaxDeployedLangs; i++)   //MAUI_03254250
		{

//			SetFont(pfont, (kal_uint8)i);   //MAUI_03254250
			SetFont(pfont, 0);   //MAUI_03254250
			tmp = Get_CharAscent();
			if (tmp > ascent_val)
			{
				ascent_val = tmp;
			}
		}
	  /*MAUI_02974843 ends*/
	  if (WGUI_CTX->is_widget_screen)
	  {
	  ShowString_n_baseline(UI_text_x, UI_text_y, pfont, 0, (U8*) STR_AT(raw_data, index), nbrOfChars, ascent_val);

    if (style->text_property.decoration == MSF_TEXT_DECORATION_UNDERLINE)
    {
        gui_draw_horizontal_line(
            x1,
            x2,
            /* y1+WIDGET_FONT_TOP_SPACING+Get_CharHeight(), // TODO: if mixed chinese and english... there will be problem */ y1 + WIDGET_FONT_TOP_SPACING + line_height,
            fg_color);
    }
	  }
    /* End drawing */
    WIDGET_END_DRAWING(msfHandle, KAL_TRUE);

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  widget_push_draw_op_polygon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfHandle       [IN]        
 *  nrOfCorners     [IN]        
 *  corners         [IN]         
 *  fill            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
/* IMAGE_MAP */
/* static __inline void widget_push_draw_op_polygon(MSF_UINT32 msfHandle, int nrOfCorners, MSF_INT16 *corners, int fill) */
static __inline void widget_push_draw_op_polygon(MSF_UINT32 msfHandle, int nrOfCorners, MSF_INT16 *corners, int fill, widget_style_struct *style)
/* IMAGE_MAP */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_image_struct *img = _IMG(msfHandle);
#ifdef WAP_USE_ASM    
    widget_draw_op_struct *draw_op = widget_internal_mem_alloc(img->module_id, sizeof(widget_draw_op_struct));
#else
    widget_draw_op_struct *draw_op = MSF_MEM_ALLOC(MSF_MODID_WIDGET, sizeof(widget_draw_op_struct));
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    draw_op->type = WIDGET_DRAW_OP_POLYGON;
    draw_op->next = NULL;
    draw_op->_u.polygon.nbrOfCorners = nrOfCorners;
#ifdef WAP_USE_ASM
    draw_op->_u.polygon.corners = widget_internal_mem_alloc(img->module_id, sizeof(MSF_INT16) * nrOfCorners * 2); /* Released later */
#else
    draw_op->_u.polygon.corners = MSF_MEM_ALLOC(MSF_MODID_WIDGET, sizeof(MSF_INT16) * nrOfCorners * 2); /* Released later */
#endif
    memcpy(draw_op->_u.polygon.corners, corners, sizeof(MSF_INT16) * nrOfCorners * 2);
    draw_op->_u.polygon.fill = fill;
/* IMAGE_MAP */
    draw_op->_u.rect.fg_color = style->fg_color;
    draw_op->_u.rect.bg_color = style->bg_color;
/* IMAGE_MAP */
    widget_enqueue_draw_op(&img->draw_op_head, &img->draw_op_tail, draw_op);
}

/* used by border drawing */


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetDrawPolygon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfHandle       [IN]        
 *  nrOfCorners     [IN]        
 *  corners         [IN]         
 *  fill            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetDrawPolygon(MSF_UINT32 msfHandle, int nrOfCorners, MSF_INT16 *corners, int fill)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* The last corners equal to the first ones */
    // TODO: style->line_style
    int i;
    int bound_x1, bound_x2, bound_y1, bound_y2;
    int clip_x1, clip_y1, clip_x2, clip_y2;
    MSF_INT16 x_right, x_left, y_top, y_bottom;
    MSF_INT16 x, y, ox, oy;
    color c;
    widget_style_struct *style = (widget_style_struct*) widget_get_style(msfHandle);
    MsfPosition pos;
#ifdef WAP_USE_ASM
    MSF_UINT8 mod_id = ((widget_header_struct*)msfHandle)->module_id;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WIDGET_TO_QUEUE_DRAWING_OP(msfHandle))
    {
        widget_push_draw_op_polygon(msfHandle, nrOfCorners, corners, fill, style);  /* IMAGE_MAP */
        return 1;
    }

    /* Draw the polygon */

    if (WIDGET_BEGIN_DRAWING(msfHandle, &pos, KAL_FALSE) < 0)
    {
        return 0;
    }

    /* Get the polygon boundary */
    ox = corners[0];
    oy = corners[1];

    x_right = ox;
    x_left = ox;
    y_top = oy;
    y_bottom = oy;
    for (i = 1; i < nrOfCorners; i ++)
    {
        x = corners[2*i];
        y = corners[2*i + 1];

        if (x > x_right)
        {
            x_right = x;
        }
        else if (x < x_left)
        {
            x_left = x;
        }

        if (y > y_bottom)
        {
            y_bottom = y;
        }
        else if (y < y_top)
        {
            y_top = y;
        }
    }

    /* Check the polygon is the display region */
    widget_paint_display_clipping_region(&bound_x1, &bound_y1, &bound_x2, &bound_y2);
    clip_x1 = x_left + pos.x;
    clip_y1 = y_top + pos.y;
    clip_x2 = x_right + pos.x;
    clip_y2 = y_bottom + pos.y;
    if (!widget_clipping_intersection
        (&clip_x1, &clip_y1, &clip_x2, &clip_y2, bound_x1, bound_y1, bound_x2, bound_y2))
    {
        WIDGET_END_DRAWING(msfHandle, KAL_FALSE);
        return 1;    /* polygon out of content region */
    }



    ASSERT(style);
    WAP_DBG_ASSERT(nrOfCorners > 3 );
    WAP_DBG_ASSERT(style->line_style.thickness == 1 || style->line_style.thickness == 0);
    
    if (fill)
    {
        widget_line_struct  *array;
        kal_bool            fill_in_v_line = KAL_TRUE;
        int                 tmp_x, tmp_y, array_size;
        
        c.alpha = 100;
        c.r = style->bg_color.r;
        c.g = style->bg_color.g;
        c.b = style->bg_color.b;


        /* Follow algorithm is only for convex polygon, not support for concave polygon */
        /* Allocate the array to keep the boundary information */
        tmp_x = x_right - x_left + 1;
        tmp_y = y_bottom - y_top + 1;
        if (tmp_x > tmp_y)
        {
            /* allocate the array to keep the boundary and fill the polygon in horizontal line */
            fill_in_v_line = KAL_FALSE;
            array_size = tmp_y;
#ifdef WAP_USE_ASM
            array = widget_internal_mem_alloc(mod_id, sizeof(widget_line_struct)*array_size);
#else
            array = MSF_MEM_ALLOC(MSF_MODID_WIDGET, sizeof(widget_line_struct)*array_size);
#endif
            for (i = 0; i < array_size; i++)
            {
                array[i].start.x = WIDGET_INVALID_COORDINATE_VAL;
                array[i].start.y = y_top + pos.y;
                array[i].end.x = WIDGET_INVALID_COORDINATE_VAL;
                array[i].end.y = y_top + pos.y;
                y_top++;
            }
        }
        else
        {
            /* allocate the array to keep the boundary and fill the polygon in vertical line */
            fill_in_v_line = KAL_TRUE;
            array_size = tmp_x;
#ifdef WAP_USE_ASM
            array = widget_internal_mem_alloc(mod_id, sizeof(widget_line_struct)*array_size);
#else
            array = MSF_MEM_ALLOC(MSF_MODID_WIDGET, sizeof(widget_line_struct)*array_size);
#endif
            for (i = 0; i < array_size; i++)
            {
                array[i].start.x = x_left + pos.x;
                array[i].start.y = WIDGET_INVALID_COORDINATE_VAL;
                array[i].end.x = x_left + pos.x;
                array[i].end.y = WIDGET_INVALID_COORDINATE_VAL;
                x_left++;
            }
        }

        /* draw the polygon */
        for (i = 1; i < nrOfCorners; i ++)
        {
            x = corners[2*i];
            y = corners[2*i + 1];

            BresLine(
                x + pos.x, 
                y + pos.y, 
                ox + pos.x, 
                oy + pos.y, 
                c, 
                KAL_TRUE,   /* generate the array for fill the polygon */
                fill_in_v_line, 
                array_size, 
                array);
            ox = x;
            oy = y;
        }
        x = corners[0];
        y = corners[1];

        BresLine(
            x + pos.x, 
            y + pos.y, 
            ox + pos.x, 
            oy + pos.y, 
            c, 
            KAL_TRUE,   /* generate the array for fill the polygon */
            fill_in_v_line, 
            array_size, 
            array);

        /* fill the polygon */
        for (i = 0; i < array_size; i++)
        {
            if (array[i].start.x != WIDGET_INVALID_COORDINATE_VAL &&
                array[i].start.y != WIDGET_INVALID_COORDINATE_VAL &&
                array[i].end.x != WIDGET_INVALID_COORDINATE_VAL &&
                array[i].end.y != WIDGET_INVALID_COORDINATE_VAL)
            {
                gdi_draw_line(
                    array[i].start.x, 
                    array[i].start.y, 
                    array[i].end.x, 
                    array[i].end.y, 
                    gdi_act_color_from_rgb(c.alpha, c.r, c.g, c.b));
            }
        }
#ifdef WAP_USE_ASM
        widget_internal_mem_free(mod_id, array);
#else
        MSF_MEM_FREE(MSF_MODID_WIDGET, array);
#endif

    }
    else
    {

        c.alpha = 100;
        c.r = style->fg_color.r;
        c.g = style->fg_color.g;
        c.b = style->fg_color.b;

        ox = corners[0];
        oy = corners[1];

        //nrOfCorners *= 2;   /* 2004.03.26 */
        for (i = 1; i < nrOfCorners; i ++)
        {
            x = corners[2*i];
            y = corners[2*i + 1];

            BresLine(
                x + pos.x, 
                y + pos.y, 
                ox + pos.x, 
                oy + pos.y, 
                c, 
                KAL_FALSE,   /* generate the array for fill the polygon */
                KAL_FALSE, 
                0, 
                NULL);
            ox = x;
            oy = y;
        }
        x = corners[0];
        y = corners[1];

        BresLine(
            x + pos.x, 
            y + pos.y, 
            ox + pos.x, 
            oy + pos.y, 
            c, 
            KAL_FALSE,   /* generate the array for fill the polygon */
            KAL_FALSE, 
            0, 
            NULL);
    }

    WIDGET_END_DRAWING(msfHandle, KAL_FALSE);

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_draw_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_draw_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (_IMG(WIPC_CTX->draw_image)->draw_op_head)
    {
        /* Image containing drawing operations 
           Typically used in background image of XHTML page */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_DRAW_IMAGE_OP);

        if (!IS_PAINTBOX_TYPE(WIPC_CTX->draw_image_msfHandle))
        {
            /* We do not support nested MsfImage drawing */
            goto end_draw_image;
        }

        /* Reference: WIDGET_BEGIN_DRAWING */
        if (!WGUI_CTX->is_widget_screen)
        {
            goto end_draw_image;
        }

        if ( /* IS_PAINTBOX_TYPE(handle) &&  */ !WGUI_CTX->in_paintbox)
        {
            goto end_draw_image;
        }

        /* This is MsfImage, not MsfImageGadget */
        widget_draw_image_from_queued_op(
            _IMG(WIPC_CTX->draw_image),
            &WIPC_CTX->draw_image_position,
            WIPC_CTX->draw_image_maxSize,
            0,
            0);
    }
    else
    {
        MsfPosition pos;
        MsfPosition *pBorderPos = &(_IMG(WIPC_CTX->draw_image)->draw_op_border_position);
        MsfSize *pBorderSize = &(_IMG(WIPC_CTX->draw_image)->draw_op_border_size);
        void *source;
        kal_bool use_source_file;

        pBorderSize->width = 0;
        pBorderSize->height = 0;

        if (IS_PAINTBOX_TYPE(WIPC_CTX->draw_image_msfHandle))
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_DRAW_IMAGE_IN_PAINTBOX);
        }
        else
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_DRAW_IMAGE_IN_MSFIMAGE);
        }

        if ((source = widget_image_content(WIPC_CTX->draw_image)) != NULL)
        {
            use_source_file = KAL_FALSE;
        }
        else if ((source = widget_image_content_file(WIPC_CTX->draw_image)) != NULL)
        {
            use_source_file = KAL_TRUE;
        }
        else
        {
            goto end_draw_image;
        }

        if (WIDGET_BEGIN_DRAWING_EX(WIPC_CTX->draw_image_msfHandle, &pos, pBorderPos, pBorderSize, KAL_FALSE) < 0)
        {
            goto end_draw_image;
        }

        if(_IMG(WIPC_CTX->draw_image)->parent && IS_GADGET_IMAGE_TYPE(_IMG(WIPC_CTX->draw_image)->parent))
		{		
		widget_show_animate_image_by_raw_data(
            _GADGET_IMAGE(_IMG(WIPC_CTX->draw_image)->parent),
            _IMG(WIPC_CTX->draw_image),
            pos.x + WIPC_CTX->draw_image_position.x,
            pos.y + WIPC_CTX->draw_image_position.y,
            widget_image_format(WIPC_CTX->draw_image),
            source,
            widget_image_length(WIPC_CTX->draw_image),
            widget_image_width(WIPC_CTX->draw_image),
            widget_image_height(WIPC_CTX->draw_image),
            WIPC_CTX->draw_image_maxSize,
            WIPC_CTX->draw_image_imageZoom,
            use_source_file,
            KAL_TRUE,
            KAL_TRUE,
            KAL_FALSE,
            KAL_FALSE /* No animation */ );
		}
		else 
		{
        widget_show_animate_image_by_raw_data(
            NULL,
            _IMG(WIPC_CTX->draw_image),
            pos.x + WIPC_CTX->draw_image_position.x,
            pos.y + WIPC_CTX->draw_image_position.y,
            widget_image_format(WIPC_CTX->draw_image),
            source,
            widget_image_length(WIPC_CTX->draw_image),
            widget_image_width(WIPC_CTX->draw_image),
            widget_image_height(WIPC_CTX->draw_image),
            WIPC_CTX->draw_image_maxSize,
            WIPC_CTX->draw_image_imageZoom,
            use_source_file,
            KAL_TRUE,
            KAL_TRUE,
            KAL_FALSE,
            KAL_FALSE /* No animation */ );
		}


        WIDGET_END_DRAWING(WIPC_CTX->draw_image_msfHandle, KAL_FALSE);
    }

  end_draw_image:
    WIPC_CTX->draw_image = 0;
    WIPC_CTX->draw_image_msfHandle = 0;
    WIPC_CTX->draw_image_position.x = 0;
    WIPC_CTX->draw_image_position.y = 0;
    WIPC_CTX->draw_image_maxSize = NULL;
    WIPC_CTX->draw_image_imageZoom = MsfImageZoom100;
}


/*****************************************************************************
 * FUNCTION
 *  widget_push_draw_op_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfHandle       [IN]        
 *  image           [IN]        
 *  position        [IN]         
 *  maxSize         [IN]         
 *  imageZoom       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static __inline void widget_push_draw_op_image(
                        MSF_UINT32 msfHandle,
                        MsfImageHandle image,
                        MsfPosition *position,
                        MsfSize *maxSize,
                        MsfImageZoom imageZoom)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_image_struct *img = _IMG(msfHandle);
#ifdef WAP_USE_ASM
    widget_draw_op_struct *draw_op = widget_internal_mem_alloc(img->module_id, sizeof(widget_draw_op_struct));
#else
    widget_draw_op_struct *draw_op = MSF_MEM_ALLOC(MSF_MODID_WIDGET, sizeof(widget_draw_op_struct));
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    draw_op->type = WIDGET_DRAW_OP_IMAGE;
    draw_op->next = NULL;
    draw_op->_u.image.image = image;
    draw_op->_u.image.position = *position;
    if (maxSize)
    {
#ifdef WAP_USE_ASM
        draw_op->_u.image.maxSize = (MsfSize*) widget_internal_mem_alloc(img->module_id, sizeof(MsfSize));       /* Released later */
#else
        draw_op->_u.image.maxSize = (MsfSize*) MSF_MEM_ALLOC(MSF_MODID_WIDGET, sizeof(MsfSize));       /* Released later */
#endif
        *draw_op->_u.image.maxSize = *maxSize;
    }
    else
    {
        draw_op->_u.image.maxSize = NULL;
    }
    draw_op->_u.image.imageZoom = imageZoom;
    widget_enqueue_draw_op(&img->draw_op_head, &img->draw_op_tail, draw_op);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetDrawImage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfHandle       [IN]        
 *  image           [IN]        
 *  position        [IN]         
 *  maxSize         [IN]         
 *  imageZoom       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetDrawImage(
        MSF_UINT32 msfHandle,
        MsfImageHandle image,
        MsfPosition *position,
        MsfSize *maxSize,
        MsfImageZoom imageZoom)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_DRAW_IMAGE);

    /*
     * HDIa_widgetDrawImage(image1, image2, ...)
     * * HDIa_widgetDrawImage(paintbox, image1, ...)
     */

    if (WIDGET_TO_QUEUE_DRAWING_OP(msfHandle))
    {
        if (_IMG(image)->is_drawn_image)    /* Nested image drawing */
        {
            return 0;
        }

        widget_push_draw_op_image(msfHandle, image, position, maxSize, imageZoom);

        if (IS_IMAGE_TYPE(msfHandle))   /* Used for Marquee */
        {
            WIDGET_SET_MAX(_IMG(msfHandle)->draw_op_content_size.width, position->x + widget_image_width(image));
            WIDGET_SET_MAX(_IMG(msfHandle)->draw_op_content_size.height, position->y + widget_image_height(image));
        }

        return 1;
    }

    if (!WGUI_CTX->is_widget_screen)    /* Not in idle screen */
    {
        return 1;
    }

    if (!image)
    {
        return 0;
    }

    /* update marquee's image */
    _IMG(image)->is_in_drawing_marquee = 1;
    WIPC_CTX->draw_image = image;
    WIPC_CTX->draw_image_msfHandle = msfHandle;
    WIPC_CTX->draw_image_position = *position;
    WIPC_CTX->draw_image_maxSize = maxSize;
    WIPC_CTX->draw_image_imageZoom = imageZoom;

    widget_execute_MMI(widget_MMI_draw_image, KAL_TRUE);

    return 1;
}
#ifdef __COSMOS_MMI_PACKAGE__
void widget_set_active_layer(void)
{
gdi_handle handle;
gdi_layer_get_active(&handle);
 if (handle != paintbox_layer_handle)
 {
	gdi_layer_push_and_set_active(paintbox_layer_handle);
	//gdi_push_and_set_alpha_blending_source_layer(paintbox_layer_handle);
	//gdi_layer_toggle_double();
 }
gdi_get_alpha_blending_source_layer(&handle);
  if (handle != paintbox_layer_handle)
  {
	gdi_push_and_set_alpha_blending_source_layer(paintbox_layer_handle);
 }

}

void widget_reset_active_layer(void)
{
gdi_handle handle;

gdi_get_alpha_blending_source_layer(&handle);
 if (handle == paintbox_layer_handle)
 {
	gdi_pop_and_restore_alpha_blending_source_layer();
 }

gdi_layer_get_active(&handle);
 if (handle == paintbox_layer_handle)
 {
	//gdi_layer_toggle_double();//TK
	gdi_layer_pop_and_restore_active();
	//gdi_layer_toggle_double();//TK
 }
}
#endif
