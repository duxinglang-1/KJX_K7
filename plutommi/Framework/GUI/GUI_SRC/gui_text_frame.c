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
 *  gui_text_frame.c
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *  pluto text frame related funtions
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 01 18 2013 ye.tian
 * removed!
 * -  fix build warning.
 *
 * 12 25 2012 ye.tian
 * removed!
 * - patch back pluto slim to 11B step 2.
 *
 * 04 23 2012 liu.cheng
 * removed!
 * .
 *
 * 04 19 2012 liu.cheng
 * removed!
 * .
 *
 * 04 13 2012 liu.cheng
 * removed!
 * .
 *
 * 02 15 2012 liu.cheng
 * removed!
 * .
 *
 * 02 06 2012 liu.cheng
 * removed!
 * .
 *
 * 01 17 2012 liu.cheng
 * removed!
 * .
 *
 * 01 17 2012 liu.cheng
 * removed!
 * .
 *
 * 12 28 2011 liu.cheng
 * removed!
 * .
 *
 * 12 28 2011 liu.cheng
 * removed!
 * .
 *
 * 12 02 2011 liu.cheng
 * removed!
 * .
 *
 * 12 02 2011 liu.cheng
 * removed!
 * .
 *
 * 12 01 2011 liu.cheng
 * removed!
 * .
 *
 * 11 25 2011 fangyi.huang
 * removed!
 * .
 *
 * 10 18 2011 liu.cheng
 * removed!
 * .
 *
 * 09 27 2011 liu.cheng
 * removed!
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================
 *******************************************************************************/

#include "gui_text_frame.h"
#include "gui_inputs_internal.h"
#include "PixcomFontEngine.h"
#include "Gui_Themes.h"
#include "app_str.h"


#include "PixcomFontEngine.h"


#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif

#ifdef __MAUI_SOFTWARE_LA__
#include "SST_sla.h"
#endif


#define GUI_TEXT_FRAME_MAX_NUM_OF_FORMAT_FOR_EACH_LINE   10

static void gui_text_frame_update_lines(gui_text_frame_struct *t);
static void gui_text_frame_show_lines(gui_text_frame_struct *t);
static void gui_text_frame_get_line_and_draw(gui_text_frame_struct *t);
static void gui_text_frame_draw_cache_lines(gui_text_frame_struct *t);
static void gui_text_frame_update_cache_lines_y(gui_text_frame_struct *t, S32 text_offset_y);
static void gui_text_frame_update_cache_lines_x_y(gui_text_frame_struct *t, S32 x, S32 y);
static void gui_text_frame_update_cache_lines_x(gui_text_frame_struct *t, S32 x);
static void gui_text_frame_draw_one_line(gui_text_frame_struct *t, gui_text_frame_line_struct *oneline, mmi_fe_text_format_struct_p format_list);
static MMI_BOOL gui_text_frame_find_one_line(
    gui_text_frame_struct *t,
    gui_text_frame_line_struct *new_line,
    S32 *offset_index_p, 
    S32 *text_height_p,
    S32 string_len,
    S32 line_max_height,
    S32 line_max_ascent,
    mmi_fe_text_format_struct_p format_iter);
static S32 gui_text_frame_get_format_list_within_range(
        gui_text_frame_struct *t,
        mmi_fe_text_format_struct_p format_list,
        S32 start,
        S32 end);

extern mmi_font_engine_error_message_enum mmi_fe_show_ellipsis_text_format_ext(
                                    S32 x,
                                    S32 y,
                                    S32 xwidth,
                                    U8 *st,
                                    U8 *truncated_symbol,
                                    MMI_BOOL bordered,
                                    mmi_fe_ellipsis_type ellipsis_type,
                                    S32 assigned_baseline,
                                    mmi_fe_text_format_struct_p format);

extern  U32 mmi_fe_show_string_bordered_baseline_ext(S32 x, 
                                    S32 y,
                                    U8 *String,
                                    S32 baseline, 
                                    U8 default_direction, 
                                    mmi_fe_text_format_struct_p format);

extern U32 mmi_fe_show_string_n_baseline_ext(U32 x_unsigned, 
                                             U32 y_unsigned, 
                                             U8 *String, 
                                             S32 Len, 
                                             S32 baseline,
                                             mmi_fe_text_format_struct_p format);

/*****************************************************************************
 * FUNCTION
 *  gui_text_frame_create
 * DESCRIPTION
 *  Creates a text frame
 * PARAMETERS
 *  t                   [OUT]       Is the text frame object   (pre-allocated)
 *  x                   [IN]        Is the left-top corner
 *  y                   [IN]        Is the left-top corner
 *  width               [IN]        Is the width of the text frame
 *  height              [IN]        Is the height of the text frame
 *  text                [IN]        Is the text to show          (pre-allocated)
 *  font                [IN]        Is the font
 *  text_color          [IN]        Is color of text
 *  flags               [IN]        Is the flags
 * RETURNS
 *  void
 *****************************************************************************/
void gui_text_frame_create(
                gui_text_frame_struct *t,
                S32 x,
                S32 y,
                S32 width,
                S32 height,
                UI_string_type text,
                UI_font_type font,
                color text_color,
                U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(t, 0, sizeof(gui_text_frame_struct));

    t->x = x;
    t->y = y;
    t->width = width;
    t->height = height;
    t->text = text;
    t->font = font;
    t->text_color = text_color;
    t->flags = flags;
    t->isNeedUpdate = MMI_TRUE;
}



/*****************************************************************************
 * FUNCTION
 *  gui_text_frame_get_size
 * DESCRIPTION
 *  Get size of text frame according to layout result
 * PARAMETERS
 *  t                   [IN]         Is the text frame
 *  width               [OUT]        Is the width of the text frame
 *  height              [OUT]        Is the height of the text frame
 * RETURNS
 *  void
 *****************************************************************************/
void gui_text_frame_get_size(gui_text_frame_struct *t, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    t->width = *width;

    /* set autorized to get height */
    t->isAutoResized = MMI_TRUE;
    gui_text_frame_update_lines(t);
    t->isNeedUpdate = MMI_TRUE;

    if (t->width <= 0 || t->height <= 0)
    {
        t->width = 0;
        t->height = 0;
    }

    *height =  t->height;
    *width = t->width;
}


/*****************************************************************************
 * FUNCTION
 *  gui_text_frame_move
 * DESCRIPTION
 *  Change text frame position
 * PARAMETERS
 *  t                   [OUT]        Is the text frame 
 *  x                   [IN]         Is the left-top corner
 *  y                   [IN]         Is the left-top corner 
 * RETURNS
 *  void
 *****************************************************************************/
void gui_text_frame_move(gui_text_frame_struct *t, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->x = x;
    t->y = y;
}


/*****************************************************************************
 * FUNCTION
 *  gui_text_frame_resize
 * DESCRIPTION
 *  Change size of the text frame
 * PARAMETERS
 *  t                   [OUT]       Is the text frame
 *  width               [IN]        Is the width of the text frame
 *  height              [IN]        Is the height of the text frame
 * RETURNS
 *  void
 *****************************************************************************/
void gui_text_frame_resize(gui_text_frame_struct *t, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->width = width;
    t->height = height;
    t->isNeedUpdate = MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  gui_text_frame_show
 * DESCRIPTION
 *  Show text frame.
 * PARAMETERS
 *  t                   [IN]    is the text frame
 * RETURNS
 *  void
 *****************************************************************************/
void gui_text_frame_show(gui_text_frame_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TFS", SA_start);
#endif

    if (t->isNeedUpdate)
    {
        /* layout lines */
        gui_text_frame_update_lines(t);
    }

    gui_push_clip();
    gui_set_clip_preset(t->x, t->y, t->x + t->width, t->y + t->height);

    /* draw lines */
    gui_text_frame_show_lines(t);

    gui_pop_clip();

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TFS", SA_stop);
#endif

}

/*****************************************************************************
 * FUNCTION
 *  gui_text_frame_update_lines
 * DESCRIPTION
 *  Layout lines.
 * PARAMETERS
 *  t                   [IN]    is the text frame
 * RETURNS
 *  void
 *****************************************************************************/
void gui_text_frame_update_lines(gui_text_frame_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL endloop = MMI_FALSE;
    S32 count = 0, offset_index = 0, string_len;  
    S32 text_height = 0;
    S32 line_max_height, line_max_ascent, line_max_dscent;  
    S32 text_offset_y = 0;   
    gui_text_frame_line_struct new_line;
    S32 max_width = 0;
    mmi_fe_text_format_struct format_list[GUI_TEXT_FRAME_MAX_NUM_OF_FORMAT_FOR_EACH_LINE];    
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TFU", SA_start);
#endif

    string_len = mmi_ucs2strlen((CHAR *)t->text);

    mmi_fe_get_char_info_of_simply_lang(t->font->size, &line_max_height, &line_max_ascent, &line_max_dscent);
      
    while (!endloop && offset_index < string_len)
    {
        i = gui_text_frame_get_format_list_within_range(t, format_list, offset_index, offset_index + MAX_NUM_OF_CHAR_FOR_EACH_LINE/2);

        /* layout one line */
        if (i != 0)
        {
            endloop = gui_text_frame_find_one_line(
                t,
                &new_line,
                &offset_index,
                &text_height,
                string_len,
                line_max_height,
                line_max_ascent,
                format_list);
        }
        else
        {
            endloop = gui_text_frame_find_one_line(
                t,
                &new_line,
                &offset_index,
                &text_height,
                string_len,
                line_max_height,
                line_max_ascent,
                NULL);
        }      

        if (!(t->flags & GUI_TEXT_FRAME_NOT_USE_CACHE))
        {
            if (count < GUI_TEXT_FRAME_MAX_LINES)
            {
                /* cache the new line */
                t->lines[count].x = new_line.x;
                t->lines[count].y = new_line.y;
                t->lines[count].width = new_line.width;
                t->lines[count].height = new_line.height;
                t->lines[count].baseline = new_line.baseline;
                t->lines[count].start = new_line.start;
                t->lines[count].end = new_line.end;
                t->lines[count].is_truncate = new_line.is_truncate;
            }
        }

        /* record the longest line width */
        if (max_width < new_line.width)
        {
            max_width = new_line.width;
        }

        count++;
    }

    t->lines_count = count;

    if (t->isAutoResized)
    {
        /* autoresize the height */
        if (t->max_height > 0 && text_height > t->max_height)
        {
            t->height = t->max_height;
        }
        else
        {
            t->height = text_height;
        }
        
        if (t->lines_count >= 1 && max_width < t->width)
        {
            if (mmi_fe_get_r2l_state() & !(t->flags & (GUI_TEXT_FRAME_H_ALIGN_LEFT | GUI_TEXT_FRAME_H_ALIGN_CENTER)))
            {
                /* if r2l language, align right */
                t->x += t->width - max_width;
                if (!(t->flags & GUI_TEXT_FRAME_NOT_USE_CACHE))
                {
                    gui_text_frame_update_cache_lines_x(t, max_width);
                }
            }
            /* autoresize the width */
            t->width = max_width;
        }
    }
    else if (t->flags & GUI_TEXT_FRAME_V_ALIGN_CENTER || t->flags & GUI_TEXT_FRAME_V_ALIGN_BOTTOM)
    {
        /* align center or align bottom, update y positon of cached lines */
        text_offset_y = t->height - text_height;
        if (t->flags & GUI_TEXT_FRAME_V_ALIGN_CENTER)
        {
            text_offset_y >>= 1;
        }

        t->text_offset_y = text_offset_y;

        if (!(t->flags & GUI_TEXT_FRAME_NOT_USE_CACHE))
        {
            gui_text_frame_update_cache_lines_y(t, text_offset_y);  
        }     
    }

    t->isNeedUpdate = MMI_FALSE;
    
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TFU", SA_stop);
#endif

}

/*****************************************************************************
 * FUNCTION
 *  gui_text_frame_show_lines
 * DESCRIPTION
 *  Draw all lines.
 * PARAMETERS
 *  t                   [IN]    is the text frame
 * RETURNS
 *  void
 *****************************************************************************/
void gui_text_frame_show_lines(gui_text_frame_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (t->flags & GUI_TEXT_FRAME_NOT_USE_CACHE)
    {
        /* do not use cache, layout and draw all lines */
        gui_text_frame_get_line_and_draw(t);
    }
    else
    {
        /* Draw all cached lines which have been layout already */
        gui_text_frame_draw_cache_lines(t);
        /* Layout and draw all the non_cached lines if exist */
        if (t->lines_count > GUI_TEXT_FRAME_MAX_LINES)
        {
            gui_text_frame_get_line_and_draw(t);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_text_frame_get_format_list_within_range
 * DESCRIPTION
 *  find format node between given range.
 * PARAMETERS
 *  t                   [IN]    is the text frame
 *  format_list         [OUT]   format list
 *  start               [IN]    start index
 *  end                 [IN]    end index
 * RETURNS
 *  void
 *****************************************************************************/
S32 gui_text_frame_get_format_list_within_range(
        gui_text_frame_struct *t,
        mmi_fe_text_format_struct_p format_list,
        S32 start,
        S32 end)
{
    S32 i = 0;
    mmi_fe_text_format_struct_p format_iter = t->format;

    /* skip node before start */
    while (format_iter && start >= format_iter->end)
    {
        format_iter = format_iter->next;
    }
    
    /* find node between the range [start, end)*/
    while (format_iter && format_iter->start < end && format_iter->end >= start && i < GUI_TEXT_FRAME_MAX_NUM_OF_FORMAT_FOR_EACH_LINE)
    {
        format_list[i].start = format_iter->start > start ? (format_iter->start - start) : 0;
        format_list[i].end = format_iter->end < end ? (format_iter->end - start) : (end - start);
        format_list[i].font = format_iter->font;
        format_list[i].c = format_iter->c;            
        format_list[i].next = NULL;

        if (i != 0)
        {
            format_list[i - 1].next = &format_list[i];
        }
        
        i++;       
        format_iter = format_iter->next;
    } 

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  gui_text_frame_get_line_and_draw
 * DESCRIPTION
 *  Layout and draw the remained non_cached lines.
 * PARAMETERS
 *  t                   [IN]    is the text frame
 * RETURNS
 *  void
 *****************************************************************************/
void gui_text_frame_get_line_and_draw(gui_text_frame_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL endloop = MMI_FALSE;
    S32 string_len;
    S32 line_max_height, line_max_ascent, line_max_dscent;
    gui_text_frame_line_struct new_line;
    S32 offset_index = 0;
    S32 text_height = 0;
    mmi_fe_text_format_struct format_list[GUI_TEXT_FRAME_MAX_NUM_OF_FORMAT_FOR_EACH_LINE];   
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!(t->flags & GUI_TEXT_FRAME_NOT_USE_CACHE))
    {
        /* if use cache, start with the end char of the last cached line, or start from the beginning */
        offset_index = t->lines[GUI_TEXT_FRAME_MAX_LINES - 1].end;
        text_height = t->lines[GUI_TEXT_FRAME_MAX_LINES - 1].y + t->lines[GUI_TEXT_FRAME_MAX_LINES - 1].height - t->lines[0].y;
    }
    
    string_len = mmi_ucs2strlen((CHAR *)t->text);
    
    mmi_fe_get_char_info_of_simply_lang(t->font->size, &line_max_height, &line_max_ascent, &line_max_dscent);
    
    while (!endloop && offset_index < string_len)
    {
        i = gui_text_frame_get_format_list_within_range(t, format_list, offset_index, offset_index + MAX_NUM_OF_CHAR_FOR_EACH_LINE/2);
        /* layout one line */
        if (i != 0)
        {
            endloop = gui_text_frame_find_one_line(
                t,
                &new_line,
                &offset_index,
                &text_height,
                string_len,
                line_max_height,
                line_max_ascent,
                format_list);
        }
        else
        {
            endloop = gui_text_frame_find_one_line(
                t,
                &new_line,
                &offset_index,
                &text_height,
                string_len,
                line_max_height,
                line_max_ascent,
                NULL);
        }

        new_line.y += t->text_offset_y;

        if ((new_line.y + t->y + new_line.height) >= 0 && (new_line.y + t->y) < UI_device_height)
        {
            /* in visible area */
            if (i != 0 && format_list && format_list[0].start + new_line.start < new_line.end)
            {
                gui_text_frame_draw_one_line(t, &new_line, format_list);
            }
            else
            {
                gui_text_frame_draw_one_line(t, &new_line, NULL);
            }
        }
    }    
}


/*****************************************************************************
 * FUNCTION
 *  gui_find_multi_line_one_line
 * DESCRIPTION
 *  find one line
 * PARAMETERS
 *  t                   [IN]    is the text frame
 *  new_line            [OUT]   new line info
 *  offset_index_p      [OUT]   offset index
 *  text_height_p       [OUT]   text height
 *  string_len          [IN]    length of text
 *  line_max_height     [IN]    max height(common language)
 *  line_max_ascent     [IN]    max ascent(common language)
 *  format              [IN]   format list
 * RETURNS
 *  MMI_BOOL: whether this line is truncated line
 *****************************************************************************/
MMI_BOOL gui_text_frame_find_one_line(
    gui_text_frame_struct *t,
    gui_text_frame_line_struct *new_line,
    S32 *offset_index_p,
    S32 *text_height_p,
    S32 string_len,
    S32 line_max_height,
    S32 line_max_ascent,
    mmi_fe_text_format_struct_p format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL endloop = MMI_FALSE;
    S32 line_count;
    S32 width, height = 0, baseline;
    mmi_fe_get_string_info_param_struct query;
    S32 offset_index = *offset_index_p;
    S32 text_height = *text_height_p;
    UI_string_type line_start_p = t->text +offset_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TFQ", SA_start);
#endif

    new_line->start = offset_index;
    new_line->y = text_height;

    /* find one line, decide the start\end char, do word warpping, query width/height/baseline of current string */
    gui_set_font(t->font);
    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    query.String = (U8*)line_start_p;
    query.n = (string_len - offset_index) > (t->width >> 2) ? (t->width >> 2) : (string_len - offset_index);
    query.w = 0;
    query.enableTruncated = MMI_TRUE;
    query.targetWidth = t->width;
    query.checkCompleteWord = 1;
    query.checklinebreak = 1;
    query.format = format;    

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FEQ", SA_start);
#endif
    /* 10A use mmi_fe_get_string_widthheight, after 10A use mmi_fe_get_string_widthheight_varient */
    line_count = mmi_fe_get_string_widthheight_varient(&query);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("FEQ", SA_stop);
#endif

    baseline = query.baseline;
    width = query.pWidth;
    height = query.pHeight;
    
    if (line_count == 0)
    {             
        line_count = 1;
        width = 1;
    }
    else
    {
        if (FONT_TEST_NEW_LINE_CHAR(*(line_start_p + line_count)))
        {
            line_count += app_ucs2_is_newline(line_start_p + line_count);
        }
    }    

    offset_index += line_count;
    new_line->end = offset_index;

    /* determine whether to truncate the line */
    new_line->is_truncate = MMI_FALSE;
    if (offset_index < string_len &&
        ((text_height + 2 * line_max_height > t->height && !t->isAutoResized) ||
         (text_height + 2 * line_max_height > t->max_height && t->max_height > 0)))
    {        
        /* new line can't be display completedly. truncate this line */
        new_line->is_truncate = MMI_TRUE;
        endloop = MMI_TRUE;
    }

    /* handle horizontal alignment */
    if (mmi_fe_get_r2l_state())
    {
        if (t->flags & GUI_TEXT_FRAME_H_ALIGN_LEFT)
        {       
            new_line->x = width;
        }
        else if (t->flags & GUI_TEXT_FRAME_H_ALIGN_CENTER)
        {
            new_line->x = (t->width + width) / 2 - 1;
        }
        else
        {
            new_line->x = t->width;
        }
    }
    else
    {
        if (t->flags & GUI_TEXT_FRAME_H_ALIGN_RIGHT)
        {        
            new_line->x = t->width - width;
        }
        else if (t->flags & GUI_TEXT_FRAME_H_ALIGN_CENTER)
        {
            new_line->x = (t->width - width) / 2;
        }
        else
        {
            new_line->x = 0;
        }
    } 

    new_line->width = width;

    if (height < line_max_height)
    { 
        /* use the simply language's max height/baseline */
        height = line_max_height;
        baseline = line_max_ascent;
    }
    new_line->height = height;
    new_line->baseline = baseline;
    
    text_height += new_line->height;

    *text_height_p = text_height;
    *offset_index_p = offset_index;

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TFQ", SA_stop);
#endif
    return endloop; 
}


/*****************************************************************************
 * FUNCTION
 *  gui_text_frame_draw_cache_lines
 * DESCRIPTION
 *  Draw all cached lines.
 * PARAMETERS
 *  t                   [IN]    is the text frame
 * RETURNS
 *  void
 *****************************************************************************/
void gui_text_frame_draw_cache_lines(gui_text_frame_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    num = t->lines_count < GUI_TEXT_FRAME_MAX_LINES ? t->lines_count : GUI_TEXT_FRAME_MAX_LINES; 
    
    if (t->format == NULL)
    {
        /* if no format list in text frame */
        for (i = 0; i < num; i++)
        {
            if ((t->lines[i].y + t->y + t->lines[i].height) >= 0 && (t->lines[i].y + t->y) < UI_device_height)
            {
                /* in visible area */
                gui_text_frame_draw_one_line(t, &t->lines[i], NULL);
            }
        }
    }
    else
    {
        /* if there is format list */
        S32 j = 0; 
        mmi_fe_text_format_struct format_list[GUI_TEXT_FRAME_MAX_NUM_OF_FORMAT_FOR_EACH_LINE];
        
        for (i = 0; i < num; i++)
        {            
            if ((t->lines[i].y + t->y + t->lines[i].height) >= 0 && (t->lines[i].y + t->y) < UI_device_height)
            {
                /* in visible area */
                
                /* find format list in this line, between [start, end) */
                j = gui_text_frame_get_format_list_within_range(t, format_list, t->lines[i].start, t->lines[i].end);
                
                /* draw this line */
                if (j != 0 && format_list && format_list[0].start + t->lines[i].start < t->lines[i].end)
                {
                    gui_text_frame_draw_one_line(t, &t->lines[i], format_list);
                }
                else
                {
                    gui_text_frame_draw_one_line(t, &t->lines[i], NULL);
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_text_frame_draw_one_line
 * DESCRIPTION
 *  Draw one line.
 * PARAMETERS
 *  t                   [IN]    is the text frame 
 *  oneline             [IN]    is the line to be drawn
 * RETURNS
 *  void
 *****************************************************************************/
void gui_text_frame_draw_one_line(gui_text_frame_struct *t, gui_text_frame_line_struct *oneline, mmi_fe_text_format_struct_p format_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y, line_count;
    CHAR templine[MAX_NUM_OF_CHAR_FOR_EACH_LINE + 2];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TFD", SA_start);
#endif

    y = oneline->y + t->y;
    x = oneline->x + t->x;
    line_count = oneline->end - oneline->start;

    gui_set_text_color(t->text_color);    
    gui_set_font(t->font);

    if (oneline->is_truncate)
    {
        if (line_count > 3)
        {            
            /* if line count > 3, draw "XX...", width deduce 1 to truncate */  
          
            /* Temp store chars of this line to show, or the truncated line will shows abnomal when r2l.
             * For example:"XXXXXXXABCD\nEF","ABCD" is the truncated line. 
             * It will wrongly shows like "...FE" instead of "...BA" 
             */
            mmi_ucs2ncpy(templine, (CHAR *)(t->text + oneline->start), line_count);
            templine[line_count * 2] = '\0';
            if (format_list)
            {
                mmi_fe_show_ellipsis_text_format_ext(
                    x,
                    y,
                    oneline->width - 1,
                    (U8*)templine,
                    (U8*)INPUTBOX_TRUNCATE_STRING,
                    t->isBorder,
                    MMI_FE_ELLIPSIS_TAIL,
                    oneline->baseline,
                    format_list);
            }
            else
            {
                mmi_fe_show_ellipsis_text_ext(
                    x,
                    y,
                    oneline->width - 1,
                    (U8*)templine,
                    (U8*)INPUTBOX_TRUNCATE_STRING,
                    t->isBorder,
                    MMI_FE_ELLIPSIS_TAIL,
                    oneline->baseline);
            }
        }
        else
        {
            /* if line count <= 3, draw "..." ,
             * or the line width may be too narrow to show "..." out
             */
            if (t->isBorder)
            {
                mmi_fe_show_string_bordered_n_baseline(
                    x,
                    y,
                    (U8*)INPUTBOX_TRUNCATE_STRING,
                    INPUTBOX_TRUNCATE_DOT_NUM,
                    oneline->baseline);                
            }
            else
            {
                mmi_fe_show_string_n_baseline(
                    x,
                    y,
                    (U8*)INPUTBOX_TRUNCATE_STRING,
                    INPUTBOX_TRUNCATE_DOT_NUM,
                    oneline->baseline);
            }            
        }
    }
    else
    {
        if (format_list)
        {
            if (t->isBorder)
            {
                mmi_ucs2ncpy(templine, (CHAR *)(t->text + oneline->start), line_count);
                templine[line_count * 2] = '\0';
                mmi_fe_show_string_bordered_baseline_ext(
                    x,
                    y,
                    (U8*)templine,                    
                    oneline->baseline,
                    BIDI_L,
                    format_list);
            }
            else
            {
                mmi_fe_show_string_n_baseline_ext(
                    x,
                    y,
                    (U8*)(t->text + oneline->start),
                    line_count,
                    oneline->baseline,
                    format_list);
            }
        }
        else
        {
            if (t->isBorder)
            {
                mmi_fe_show_string_bordered_n_baseline(
                    x,
                    y,
                    (U8*)(t->text + oneline->start),
                    line_count,
                    oneline->baseline);
            }
            else
            {
                mmi_fe_show_string_n_baseline(
                    x,
                    y,
                    (U8*)(t->text + oneline->start),
                    line_count,
                    oneline->baseline);
            }
        }
    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TFD", SA_stop);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_text_frame_update_cache_lines_y
 * DESCRIPTION
 *  Update y of cached lines.
 * PARAMETERS
 *  t                   [IN\OUT]    is the text frame
 *  text_offset_y       [IN]        is the text offset along vertical direction
 * RETURNS
 *  void
 *****************************************************************************/
void gui_text_frame_update_cache_lines_y(gui_text_frame_struct *t, S32 text_offset_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    num = t->lines_count < GUI_TEXT_FRAME_MAX_LINES ? t->lines_count : GUI_TEXT_FRAME_MAX_LINES;
    for (i = 0; i < num; i++)
    {
        t->lines[i].y += text_offset_y;
    }
}

/*****************************************************************************
 * FUNCTION
 *  gui_text_frame_update_cache_lines_x
 * DESCRIPTION
 *  Update x of cached lines.
 * PARAMETERS
 *  t                   [IN\OUT]    is the text frame
 *  x                   [IN]        is the new x
 * RETURNS
 *  void
 *****************************************************************************/
void gui_text_frame_update_cache_lines_x(gui_text_frame_struct *t, S32 x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    num = t->lines_count < GUI_TEXT_FRAME_MAX_LINES ? t->lines_count : GUI_TEXT_FRAME_MAX_LINES;
    for (i = 0; i < num; i++)
    {
        t->lines[i].x = x;
    }
}

/*****************************************************************************
 * FUNCTION
 *  gui_text_frame_update_cache_lines_x_y
 * DESCRIPTION
 *  Update x,y info of cached lines.
 * PARAMETERS
 *  t                   [IN\OUT]    is the text frame 
 *  x                   [IN]        is the new position
 *  y                   [IN]        is the new position  
 * RETURNS
 *  void
 *****************************************************************************/
void gui_text_frame_update_cache_lines_x_y(gui_text_frame_struct *t, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    num = t->lines_count < GUI_TEXT_FRAME_MAX_LINES ? t->lines_count : GUI_TEXT_FRAME_MAX_LINES;
    for (i = 0; i < num; i++)
    {
        t->lines[i].x = x;
        t->lines[i].y = y;
    }
}

/*****************************************************************************
 * FUNCTION
 *  gui_text_frame_set_text
 * DESCRIPTION
 *  Set text.
 * PARAMETERS
 *  t                   [OUT]    is the text frame 
 *  text                [IN]     is text   
 * RETURNS
 *  void
 *****************************************************************************/
void gui_text_frame_set_text(gui_text_frame_struct *t, UI_string_type text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->text = text;
    t->isNeedUpdate = MMI_TRUE;
}


 
/*****************************************************************************
 * FUNCTION
 *  gui_text_frame_set_is_auto_resized
 * DESCRIPTION
 *  Set autorized mode.
 * PARAMETERS
 *  t                   [OUT]    is the text frame
 *  isAutoResized       [IN]     whether auto resize
 * RETURNS
 *  void
 *****************************************************************************/
void gui_text_frame_set_is_auto_resized(gui_text_frame_struct *t, MMI_BOOL isAutoResized)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->isAutoResized = isAutoResized;
    t->isNeedUpdate = MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  gui_text_frame_set_max_height
 * DESCRIPTION
 *  Set format list.
 * PARAMETERS
 *  t                   [OUT]    is the text frame
 *  max_height          [IN]     max height limite 
 * RETURNS
 *  void
 *****************************************************************************/
void gui_text_frame_set_max_height(gui_text_frame_struct *t, S32 max_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (max_height > 0)
    {
        t->max_height = max_height;

        if (t->height > max_height)
        {
            t->height = max_height;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  gui_text_frame_set_need_update
 * DESCRIPTION
 *  Set format list.
 * PARAMETERS
 *  t                   [OUT]    is the text frame
 *  isNeedUpdate        [IN]     need update 
 * RETURNS
 *  void
 *****************************************************************************/
void gui_text_frame_set_need_update(gui_text_frame_struct *t, MMI_BOOL isNeedUpdate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->isNeedUpdate = isNeedUpdate;
}


/*****************************************************************************
 * FUNCTION
 *  gui_text_frame_set_format
 * DESCRIPTION
 *  Set format list.
 * PARAMETERS
 *  t                   [OUT]    is the text frame
 *  format              [IN]     format list 
 * RETURNS
 *  void
 *****************************************************************************/
void gui_text_frame_set_format(gui_text_frame_struct *t, mmi_fe_text_format_struct_p format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->format = format;
}

/*****************************************************************************
 * FUNCTION
 *  gui_text_frame_set_border
 * DESCRIPTION
 *  Set font border.
 * PARAMETERS
 *  t                   [OUT]    is the text frame
 *  isBorder            [IN]     is Border 
 * RETURNS
 *  void
 *****************************************************************************/
void gui_text_frame_set_border(gui_text_frame_struct *t, MMI_BOOL isBorder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->isBorder = isBorder;
}


