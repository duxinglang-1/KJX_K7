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
 *   gui_color_slider.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  Picture Editor related categoreis.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
 * This file contains internal UI component API, and is intended to be used by category screen module only. 
 * It's not recommended to be included in application code directly. 
 * For application developers, please include category screen header files instead (e.g., wgui_categories.h).
 */

 
/***************************************************************************** 
* Define
*****************************************************************************/

/* DOM-NOT_FOR_SDK-BEGIN */
#include "MMI_features.h"
#include "MMIDataType.h"
#include "mmi_frm_input_gprot.h"

#include "CustThemesRes.h"
#include "gui.h"
#include "gui_typedef.h"

/* DOM-NOT_FOR_SDK-END */

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/* <group dom_color_slider_struct>
 * Struct of color slide component.
 */
typedef struct _color_slider
{
    /* Is the flag of color slide, no use at present */
    U16 flags;
    /* Is the x position of clolor slider */
    S32 x;
    /* Is the y position of clolor slider */
    S32 y;
    /* Is the width of clolor slider */
    S32 width;
    /* Is the height of clolor slider */
    S32 height;
    /* Is the range that clolor slider scrolls */
    S32 range;
    /* Is the value of clolor slider */
    S32 value;
    /* Is the width of slider indicator */
    S32 swidth;
    /* Is the height of slider indicator */
    S32 sheight;
    /* Is the x position of slider indicator's left-top point */
    S32 sx1;
    /* Is the y position of slider indicator's left-top point */
    S32 sy1;
    /* Is the x position of slider indicator's right-bottom point */
    S32 sx2;
    /* Is the y position of slider indicator's right-bottom point */
    S32 sy2;
    /* Is the background filler of color slider */
    UI_filled_area *filler;
    /* Is the image of slider indicator */
    U16 simage;
    /* Is the hide callback function of color slider */
    void (*shide) (S32 x1, S32 y1, S32 x2, S32 y2);

#ifdef __MMI_TOUCH_SCREEN__
    /* Is the pen state of color slider which only supports in touch projects */
    gui_slide_control_pen_state_enum pen_state;
#endif 
} color_slider;

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

/*****************************************************************************
 * <group dom_color_slider_gui_layer_basic>
 * FUNCTION
 *  gui_color_slider_create
 * DESCRIPTION
 *  Create color slider object.
 * PARAMETERS
 *  s            : [IN] Is the color slider object
 *  x            : [IN] Is the x positin of color slider
 *  y            : [IN] Is the y positin of color slider
 *  width        : [IN] Is the width of color slider
 *  height       : [IN] Is the height of color slider
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_color_slider_create(
             color_slider *s,
             S32 x,
             S32 y,
             S32 width,
             S32 height);

/*****************************************************************************
 * <group dom_color_slider_gui_layer_property_setting>
 * FUNCTION
 *  gui_color_slider_set_range
 * DESCRIPTION
 *  Set scroll range to color slider.
 * PARAMETERS
 *  s            : [IN] Is the color slider object
 *  range        : [IN] Is the scroll range of color slider
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_color_slider_set_range(color_slider *s, S32 range);

/*****************************************************************************
 * <group dom_color_slider_gui_layer_property_setting>
 * FUNCTION
 *  gui_color_slider_set_value
 * DESCRIPTION
 *  Set value to color slider.
 * PARAMETERS
 *  s            : [IN] Is the color slider object
 *  value        : [IN] Is the value of color slider
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_color_slider_set_value(color_slider *s, S32 value);

/*****************************************************************************
 * <group dom_color_slider_gui_layer_property_setting>
 * FUNCTION
 *  gui_color_slider_set_filler
 * DESCRIPTION
 *  Set background filler to color slider
 * PARAMETERS
 *  s        : [IN] Is the color slider object
 *  f        : [IN] Is the background filler of color slider
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_color_slider_set_filler(color_slider *s, UI_filled_area *f);

/*****************************************************************************
 * <group dom_color_slider_gui_layer_property_setting>
 * FUNCTION
 *  gui_color_slider_set_hide_function
 * DESCRIPTION
 *  Set hide callback function to color slider.
 * PARAMETERS
 *  s          : [IN] Is the color slider object
 *  f          : [IN] Is the handler of hide callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_color_slider_set_hide_function(
             color_slider *s, void (*f) (S32 x1, S32 y1, S32 x2, S32 y2));

/*****************************************************************************
 * <group dom_color_slider_gui_layer_basic>
 * FUNCTION
 *  gui_color_slider_show
 * DESCRIPTION
 *  Dispaly color slider without blt.
 * PARAMETERS
 *  s          : [IN] Is the color slider object
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_color_slider_show(color_slider *s);

/*****************************************************************************
 * <group dom_color_slider_gui_layer_basic>
 * FUNCTION
 *  gui_color_slider_hide
 * DESCRIPTION
 *  Hide the color slider.
 * PARAMETERS
 *  s         : [IN] Is the color slider object.
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_color_slider_hide(color_slider *s);

#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * <group dom_color_slider_gui_layer_touch>
 * FUNCTION
 *  wgui_color_slider_translate_pen_event
 * DESCRIPTION
 *  Translate pen's position to slider value.
 * REMARKS
 *  This API will only be provided in touch projects.
 * PARAMETERS
 *  s                : [IN] Is the color slider object
 *  pen_event        : [IN] Is the pen event
 *  x                : [IN] Is the x position of pen
 *  y                : [IN] Is the y position of pen
 *  slide_event      : [IN/OUT] Is the pointer of parameter to restore slider event
 *  slide_param      : [IN/OUT] Is the pointer of parameter to restore slider value
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE: Color slider will handle the given pen event.
 *  MMI_FALSE: Color slider will not handle the given pen event.
 * SEE ALSO
 *  You should also know gui_slide_control_pen_event_enum as well.
 *****************************************************************************/
extern MMI_BOOL wgui_color_slider_translate_pen_event(
                color_slider *s,
                mmi_pen_event_type_enum pen_event,
                S16 x,
                S16 y,
                gui_slide_control_pen_event_enum *slide_event,
                gui_pen_event_param_struct *slide_param);
#endif /* __MMI_TOUCH_SCREEN__ */ 


