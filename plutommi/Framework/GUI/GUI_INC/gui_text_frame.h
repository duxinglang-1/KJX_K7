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
 *  gui_text_frame.h
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
 * 01 17 2012 liu.cheng
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

#include "MMIDataType.h"

#include "MMI_features.h"
#include "gdi_const.h"
#include "gdi_datatype.h"

#include "gui_data_types.h"
#include "gui.h"
#include "gui_typedef.h"
 
#ifndef __GUI_TEXT_FRAME_H__
#define __GUI_TEXT_FRAME_H__

/***************************************************************************** 
* Define
*****************************************************************************/
#define GUI_TEXT_FRAME_MAX_LINES          5  

/* style attribute */
#define GUI_TEXT_FRAME_H_ALIGN_LEFT       0x00000001
#define GUI_TEXT_FRAME_H_ALIGN_RIGHT      0x00000002
#define GUI_TEXT_FRAME_H_ALIGN_CENTER     0x00000004
#define GUI_TEXT_FRAME_V_ALIGN_TOP        0x00000008
#define GUI_TEXT_FRAME_V_ALIGN_BOTTOM     0x00000010
#define GUI_TEXT_FRAME_V_ALIGN_CENTER     0x00000020
#define GUI_TEXT_FRAME_NOT_USE_CACHE      0x00000040

/***************************************************************************** 
* Typedef
*****************************************************************************/
typedef struct
{
    S32       x, y;             // line x, y
    S32       width, height;    // line width/height
    S32       start, end;       // line text start/end index
    S32       baseline;         // line baseline
    MMI_BOOL  is_truncate;      // is truncate line or not
} gui_text_frame_line_struct;

typedef struct
{
    S32            x, y;            // x,y coordinate
    S32            width, height;   // width/height
    S32            text_offset_y;   // offset y
    S32            lines_count;     // num of lines
    S32            max_height;      // max height limit
    U32            flags;           // flags
    UI_string_type text;            // text
    UI_font_type   font;            // font
    color          text_color;      // text color  
    gui_text_frame_line_struct lines[GUI_TEXT_FRAME_MAX_LINES];  // cached line info
    MMI_BOOL       isNeedUpdate;    // if need to update the layout
    MMI_BOOL       isAutoResized;   // auto resized
    MMI_BOOL       isTruncate;      // truncate mode
    MMI_BOOL       isBorder;        // Border
    mmi_fe_text_format_struct_p format;   //format list
} gui_text_frame_struct;



/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

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
 * EXAMPLE
 * <code>
 * void test_text_frame(void)
 * { 
 *     gui_text_frame_struct text_frame;
 *     UI_string_type text = L"This is a test string for text frame";
 *     color text_color = UI_COLOR_BLACK;
 *     S32 width = 200, height = 100;
 *     S32 x = 0, y = 50;
 *     
 *     gui_text_frame_create(
 *             &text_frame,
 *             x,
 *             y,
 *             width,
 *             height,
 *             text,
 *             &MMI_small_font,
 *             text_color,
 *             0);
 *     
 *     gui_text_frame_show(&text_frame);  
 * }
 * </code>
 *****************************************************************************/
extern void gui_text_frame_create(
                gui_text_frame_struct *t,
                S32 x,
                S32 y,
                S32 width,
                S32 height,
                UI_string_type text,
                UI_font_type font,
                color text_color,
                U32 flags);

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
extern  void gui_text_frame_show(gui_text_frame_struct *t);

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
extern  void gui_text_frame_move(gui_text_frame_struct *t, S32 x, S32 y);

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
extern  void gui_text_frame_resize(gui_text_frame_struct *t, S32 width, S32 height);

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
extern void gui_text_frame_get_size(gui_text_frame_struct *t, S32 *width, S32 *height);

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
extern void gui_text_frame_set_is_auto_resized(gui_text_frame_struct *t, MMI_BOOL isAutoResized);

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
extern void gui_text_frame_set_text(gui_text_frame_struct *t, UI_string_type text);

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
extern void gui_text_frame_set_max_height(gui_text_frame_struct *t, S32 max_height);

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
extern void gui_text_frame_set_format(gui_text_frame_struct *t, mmi_fe_text_format_struct_p format);

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
extern void gui_text_frame_set_need_update(gui_text_frame_struct *t, MMI_BOOL isNeedUpdate);

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
extern void gui_text_frame_set_border(gui_text_frame_struct *t, MMI_BOOL isBorder);

#endif /*__GUI_TEXT_FRAME_H__*/
