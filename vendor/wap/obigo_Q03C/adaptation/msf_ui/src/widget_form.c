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
 * widget_form.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Widget form
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
 *==============================================================================
 *******************************************************************************/

#include "widget.h"
#include "widget_struct.h"
#include "widget_linklist.h"
#include "WguiCategoryGprot.h"
#include "lcd_sw_rnd.h"

/****************************************************************
 FORM 
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetFormCreate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId               [IN]        
 *  size                [IN]         
 *  propertyMask        [IN]        
 *  defaultStyle        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfWindowHandle HDIa_widgetFormCreate(MSF_UINT8 modId, MsfSize *size, int propertyMask, MsfStyleHandle defaultStyle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_form_struct *w = widget_create_form(modId);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w->module_id = modId;

    if (size)
    {
        w->size = *size;
    }
    else
    {
        w->size = WGUI_CTX->default_display_size;
    }

    w->property_mask = propertyMask;
    widget_set_attrib(w, style, defaultStyle);

    return (MsfWindowHandle) w;
}

 /****************************************************************
 * Pen handlers
 ***************************************************************/

/****************************************************************
 * Utility function of MsfForm
 ***************************************************************/

/* Draw border of selected gadget */


/*****************************************************************************
 * FUNCTION
 *  widget_form_draw_border
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h       [IN]         
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_form_draw_border(widget_header_struct *h, int x1, int y1, int x2, int y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_header_struct *p = h->parent;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(IS_FORM_TYPE(p));
    if (IS_FORM_TYPE(p) && (_FORM(p)->form_flags & WIDGET_FORM_FLAG_DISABLE_GADGET_BORDER))
    {
        return;
    }

    {
        static const kal_uint8 dotted_line_bitvalues[] = {1, 0};
        gdi_color bcolor = gdi_act_color_from_rgb(
                            255,
                            WIDGET_SMIL_BORDER_COLOR_R,
                            WIDGET_SMIL_BORDER_COLOR_G,
                            WIDGET_SMIL_BORDER_COLOR_B);
        gui_set_clip(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
        gdi_draw_line_style(
            x1 - 1,
            y1 - 1,
            x1 - 1,
            y2 + 1,
            bcolor,
            sizeof(dotted_line_bitvalues),
            dotted_line_bitvalues);
        gdi_draw_line_style(
            x1 - 1,
            y1 - 1,
            x2 + 1,
            y1 - 1,
            bcolor,
            sizeof(dotted_line_bitvalues),
            dotted_line_bitvalues);
        gdi_draw_line_style(
            x2 + 1,
            y1 - 1,
            x2 + 1,
            y2 + 1,
            bcolor,
            sizeof(dotted_line_bitvalues),
            dotted_line_bitvalues);
        gdi_draw_line_style(
            x1 - 1,
            y2 + 1,
            x2 + 1,
            y2 + 1,
            bcolor,
            sizeof(dotted_line_bitvalues),
            dotted_line_bitvalues);
    }
}

// TODO: Use widget_in_form_window() to replace "(!WGUI_CTX->in_paintbox)"


/*****************************************************************************
 * FUNCTION
 *  widget_form_gadget_want_focus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gadget      [IN]     
 * RETURNS
 *  
 *****************************************************************************/
kal_bool widget_form_gadget_want_focus(widget_header_struct *gadget)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(WIDGET_GADGET_WANT_FOCUS_LIST & (1 << gadget->data_type)))
    {
        return KAL_FALSE;
    }

#ifdef MSF_CFG_BRW_BLINKING_TEXT_SUPPORT
    if (IS_GADGET_STRING_TYPE(gadget))
    {
        /* A string gadget can be focused in MsfForm only if MSF_GADGET_PROPERTY_FOCUS */
        if (_GADGET_STRING(gadget)->property_mask & MSF_GADGET_PROPERTY_FOCUS)
        {
            return KAL_TRUE;
        }
        else
        {
            return KAL_FALSE;
        }
    }
    else if (IS_GADGET_IMAGE_TYPE(gadget))
#else 

    if (IS_GADGET_IMAGE_TYPE(gadget))

#endif /* MSF_CFG_BRW_BLINKING_TEXT_SUPPORT */
    {
        // TODO: Note that Marquee objects have MSF_GADGET_PROPERTY_NOTIFY but not MSF_GADGET_PROPERTY_FOCUS
        if (_GIMG(gadget)->property_mask & MSF_GADGET_PROPERTY_FOCUS    /* ||
                                                                           _GIMG(gadget)->property_mask & MSF_GADGET_PROPERTY_NOTIFY */ )
        {
            return KAL_TRUE;
        }
        else
        {
            return KAL_FALSE;
        }
    }
    else if (IS_GADGET_INPUT_TYPE(gadget))
    {
        if (_GINP(gadget)->is_string_gadget_emulation && !(_GINP(gadget)->property_mask & MSF_GADGET_PROPERTY_FOCUS))
        {
            return KAL_FALSE;
        }
        else
        {
            return KAL_TRUE;
        }
    }
    else
    {
        return KAL_TRUE;
    }
}

/*
 * We set focus of gadget in form when it is focused
 */


/*****************************************************************************
 * FUNCTION
 *  widget_form_on_focused
 * DESCRIPTION
 *  
 * PARAMETERS
 *  form        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_form_on_focused(widget_header_struct *form)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_header_struct *gadget;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(IS_FORM_TYPE(form));

    /* When a form is focused, set focus to it's first gadget (which is created first or was active last time) */
    widget_get_active_childs(gadget, form);
    while (gadget)
    {
        if (widget_form_gadget_want_focus(gadget))
        {
            HDIa_widgetSetInFocus((MsfGadgetHandle) gadget, 1);
            /*
             * SMA/MEA require setting focus on gadgets on forms. 
             * * FIXME. However, we may already send the notification twice in HDIa_widgetSetInFocus or not.
             */
            widget_notify(gadget, MsfNotifyFocus);
            break;
        }

        widget_get_next_active_childs(gadget, form);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_form_on_gadget_added
 * DESCRIPTION
 *  
 * PARAMETERS
 *  form                [IN]     
 *  gadget_added        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_form_on_gadget_added(widget_header_struct *form, widget_header_struct *gadget_added)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_header_struct *gadget;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(IS_FORM_TYPE(form));

    /* When a form is focused, set focus to it's first gadget (which is created first or was active last time) */
    widget_get_active_childs(gadget, form);
    while (gadget)
    {
        if (widget_form_gadget_want_focus(gadget))
        {
            /* If the added gadget is not focused, we do not need to send notification to the previously-focused gadget */
            if (gadget == gadget_added)
            {
                HDIa_widgetSetInFocus((MsfGadgetHandle) gadget, 1);
                widget_notify(gadget, MsfNotifyFocus);
            }
            break;
        }

        widget_get_next_active_childs(gadget, form);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_paint_form
 * DESCRIPTION
 *  
 * PARAMETERS
 *  form        [IN]     
 *  size        [IN]     
 *  pos         [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_paint_form(widget_form_struct *form, MsfSize *size, MsfPosition *pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* We only draw the skeleton here. widget_paint_area will draw each gadgets */
    widget_style_struct *style = _STYLE(widget_get_style((MSF_UINT32) form));
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!style)
    {
        return;
    }

    x1 = WGUI_CTX->display_pos.x;
    y1 = WGUI_CTX->display_pos.y;
    x2 = x1 + WGUI_CTX->display_size.width - 1;
    y2 = y1 + WGUI_CTX->display_size.height - 1;

   /* gui_push_clip();
    gui_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);*/
    gui_push_and_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);

    if (!widget_is_transparent_color(&(style->bg_color)))
    {
        gdi_draw_solid_rect(
            x1,
            y1,
            x2,
            y2,
            (gdi_color) gdi_act_color_from_rgb(255, style->bg_color.r, style->bg_color.g, style->bg_color.b));
    }
    else
    {
        gdi_draw_solid_rect(
            x1,
            y1,
            x2,
            y2,
            (gdi_color) gdi_act_color_from_rgb(255, 255, 255, 255));
    }
    gui_pop_clip();
}


/* This check is unnecessary in BRS paintbox because BRS will do this checking first */
// TODO: Incorrect name. This also applies to paintbox.


/*****************************************************************************
 * FUNCTION
 *  widget_gadget_in_form
 * DESCRIPTION
 *  
 * PARAMETERS
 *  form_size       [IN]        
 *  gadget_pos      [IN]        
 *  gadget_size     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool widget_gadget_in_form(const MsfSize *form_size, const MsfPosition *gadget_pos, const MsfSize *gadget_size)
{
#if 0   // TODO: This check is incorrect to handle WGUI_CTX->curr_display_pos
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
#endif /* 0 */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return KAL_TRUE;
}

