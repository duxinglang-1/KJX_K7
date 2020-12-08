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
 * gui_status_icon.c
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


/****************************************************************************
 * Include
 ****************************************************************************/
#include "gui_typedef.h"
#include "gui_status_icon.h"

#include "gui_status_icon_bar.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "wgui_categories_util.h"
#include "gui.h"
#include "gdi_include.h"
#include "gui_status_icon_bar_pre_oem.h"
#include "gui_status_icon_bar_post_oem.h"
#include "gdi_const.h"

/****************************************************************************
 * Global Variable
 ****************************************************************************/
void (*gui_status_icon_bar_show_icon)(gui_status_icon_bar_struct *bar, gui_status_icon_bar_icon_struct *icon);


/****************************************************************************
 * Global function
 ****************************************************************************/


/****************************************************************************
 * Status icon
 ****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_enable_icon_display
 * DESCRIPTION
 *  Enable status icon display or not
 * PARAMETERS
 *  icon        [IN]        Pointer to status icon struct
 *  enable      [IN]        Enable status icon display or not
 * RETURNS
 *  void
 *****************************************************************************/
void gui_status_icon_bar_enable_icon_display(gui_status_icon_bar_icon_struct *icon, MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (enable)
    {
        icon->flags |= GUI_STATUS_ICON_BAR_ICON_DISPLAY;
    }
    else
    {
        icon->flags &= ~GUI_STATUS_ICON_BAR_ICON_DISPLAY;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_enable_icon_animate
 * DESCRIPTION
 *  Enable the status icon animate or not
 * PARAMETERS
 *  icon      [IN]        Pointer to status icon struct
 *  enable    [IN]        Enable status icon animate or not
 * RETURNS
 *  void
 *****************************************************************************/
void gui_status_icon_bar_enable_icon_animate(gui_status_icon_bar_icon_struct *icon, MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (enable)
    {
        icon->flags |= GUI_STATUS_ICON_BAR_ICON_ANIMATE;
    }
    else
    {
        icon->flags &= ~GUI_STATUS_ICON_BAR_ICON_ANIMATE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_enable_icon_blink
 * DESCRIPTION
 *  Enable status icon blink or not
 * PARAMETERS
 *  icon      [IN]        Pointer to status icon struct
 *  enable    [IN]        Enable status icon blink or not
 * RETURNS
 *  void
 *****************************************************************************/
void gui_status_icon_bar_enable_icon_blink(gui_status_icon_bar_icon_struct *icon, MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (enable)
    {
        icon->flags |= GUI_STATUS_ICON_BAR_ICON_BLINK | GUI_STATUS_ICON_BAR_ICON_BLINK_ON;
    }
    else
    {
        icon->flags &= ~(GUI_STATUS_ICON_BAR_ICON_BLINK | GUI_STATUS_ICON_BAR_ICON_BLINK_ON);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_change_icon_level
 * DESCRIPTION
 *  Change the status icon level, usually for change the current frame of signal or battery
 * PARAMETERS
 *  icon      [IN]        Pointer to status icon struct
 *  level     [IN]        The level of status icon, it is precentage value
 * RETURNS
 *  void
 *****************************************************************************/
void gui_status_icon_bar_change_icon_level(gui_status_icon_bar_icon_struct *icon, S32 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 n_frames = icon->n_frames;
    S32 frame_number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (n_frames <= 1)
    {
        return;
    }
    frame_number = (level * n_frames) / 100;
    if (frame_number >= n_frames)
    {
        frame_number = n_frames - 1;
    }
    else if (frame_number < 0)
    {
        frame_number = 0;
    }

    icon->state = frame_number;
}


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_get_icon_frame_number
 * DESCRIPTION
 *  Change the status icon level, usually for change the current frame of signal or battery
 * PARAMETERS
 *  icon      [IN]        Pointer to status icon struct
 *  level     [IN]        The level of status icon, it is precentage value
 * RETURNS
 *  void
 *****************************************************************************/
S32 gui_status_icon_bar_get_icon_frame_number(gui_status_icon_bar_icon_struct *icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (icon->n_frames <= 1)
    {
        return 0;
    }
    else
    {
        return icon->state;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_change_icon_image
 * DESCRIPTION
 *  Change the image of status icon
 * PARAMETERS
 *  icon       [IN]        Pointer to status icon struct
 *  image_id   [IN]        New image of status icon
 * RETURNS
 *  void
 *****************************************************************************/
void gui_status_icon_bar_change_icon_image(gui_status_icon_bar_icon_struct *icon, S32 image_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//#ifdef __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
	PU8  imgBuffer = NULL;
//#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
	/* imageResource Violation */
    icon->image_data = get_image((MMI_ID_TYPE)image_id);
#ifdef __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
    imgBuffer = (PU8)GetImageData((S8*)icon->image_data);
#else
		imgBuffer = icon->image_data;
#endif
	icon->image_data = imgBuffer;
    icon->image_id = image_id;
    icon->n_frames = gui_image_n_frames(imgBuffer);
    if (icon->current_frame >= icon->n_frames - 1)
    {
        icon->current_frame = icon->n_frames - 1;
    }
    gdi_image_get_dimension(imgBuffer, &(icon->width), &(icon->height));

#ifdef __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__   
	SetImageFlushable(icon->image_data);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_change_icon_image_ex
 * DESCRIPTION
 *  Change the image of status icon
 * PARAMETERS
 *  icon       [IN]        Pointer to status icon struct
 *  image_id   [IN]        New image of status icon
 * RETURNS
 *  void
 *****************************************************************************/
void gui_status_icon_bar_change_icon_image_ex(gui_status_icon_bar_icon_struct *icon, PU8 image_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    icon->image_data = image_data;
    icon->n_frames = gui_image_n_frames(icon->image_data);
    gdi_image_get_dimension(icon->image_data, &(icon->width), &(icon->height));
    if(icon->height > (MMI_STATUS_BAR_HEIGHT - (STATUS_ICON_Y_GAP<<1)))
    {
        icon->width = MMI_STATUS_BAR_HEIGHT - (STATUS_ICON_Y_GAP<<1);
        icon->height = MMI_STATUS_BAR_HEIGHT - (STATUS_ICON_Y_GAP<<1);
        // mark the icon need resize when be shown
        icon->n_frames = 255;
    }
}



/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_get_icon_image_id
 * DESCRIPTION
 *  Get the image id of status icon
 * PARAMETERS
 *  icon       [IN]        Pointer to status icon struct
 * RETURNS
 *  The image id of status icon
 *****************************************************************************/
S32 gui_status_icon_bar_get_icon_image_id(gui_status_icon_bar_icon_struct *icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return icon->image_id;
}


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_set_icon_flag
 * DESCRIPTION
 *  Set the flag of status icon
 * PARAMETERS
 *  icon      [IN]        Pointer to status icon struct
 *  flag      [IN]        New flag of status icon
 * RETURNS
 *  void
 *****************************************************************************/
void gui_status_icon_bar_set_icon_flag(gui_status_icon_bar_icon_struct *icon, U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    icon->flags = flag;
}


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_get_icon_flag
 * DESCRIPTION
 *  Get the status icon's flag
 * PARAMETERS
 *  icon       [IN]        Pointer to status icon struct
 * RETURNS
 *  The flag of status icon
 *****************************************************************************/
U32 gui_status_icon_bar_get_icon_flag(gui_status_icon_bar_icon_struct *icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return icon->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_get_icon_area
 * DESCRIPTION
 *  Get the status icon's flag
 * PARAMETERS
 *  icon       [IN]        Pointer to status icon struct
 * RETURNS
 *  The flag of status icon
 *****************************************************************************/
MMI_BOOL gui_status_icon_bar_get_icon_area(gui_status_icon_bar_icon_struct *icon, S32 *x1, S32 *y1, S32 *x2, S32 *y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (icon->flags & GUI_STATUS_ICON_BAR_ICON_DISPLAY)
    {
        *x1 = icon->x;
        *x2 = icon->x + icon->width - 1;
        *y1 = icon->y;
        *y2 = icon->y + icon->height - 1;
        return MMI_TRUE;
    }
    return MMI_FALSE;
}



/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_whether_icon_display
 * DESCRIPTION
 *  To check whether the status icon display or not
 * PARAMETERS
 *  icon       [IN]        Pointer to status icon struct
 * RETURNS
 *  MMI_TRUUE   :   The status icon display
 *  MMI_FALSE   :   The status icon not display
 *****************************************************************************/
MMI_BOOL gui_status_icon_bar_whether_icon_display(gui_status_icon_bar_icon_struct *icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GUI_STATUS_ICON_BAR_ICON_DISPLAY_ON(icon->flags)? MMI_TRUE : MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_get_icon_size
 * DESCRIPTION
 *  Get the icon's size
 * PARAMETERS
 *  icon      [IN]        Pointer to status icon struct
 *  width     [OUT]       Pointer to restore the width of status icon
 *  height    [OUT]       Pointer to restore the height of status icon
 * RETURNS
 *  void
 *****************************************************************************/
void gui_status_icon_bar_get_icon_size(gui_status_icon_bar_icon_struct *icon, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GUI_STATUS_ICON_BAR_ICON_DISPLAY_ON(icon->flags))
    {
        *width = icon->width;
        *height = icon->height;
    }
    else
    {
        *width = 0;
        *height = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_get_icon_position
 * DESCRIPTION
 *  Get the icon's position
 * PARAMETERS
 *  icon        [IN]        Pointer to status icon struct
 *  x           [OUT]       Pointer to restore the x coordinate of status icon
 *  y           [OUT]       Pointer to restore the y coordinate of status icon
 * RETURNS
 *  void
 *****************************************************************************/
void gui_status_icon_bar_get_icon_position(gui_status_icon_bar_icon_struct *icon, S32 *x, S32 *y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *x = icon->x;
    *y = icon->y;
}


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_initialize_icon
 * DESCRIPTION
 *  Initialize status icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_status_icon_bar_initialize_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_show_icon = gui_status_icon_bar_show_icon_oem;
}


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_show_integrated_icon
 * DESCRIPTION
 *  Show icon for integrated title
 * PARAMETERS
 *  icon      [IN]        Pointer to status icon struct
 *  x         [IN]        The x coordinate of draw icon
 *  y         [IN]        The y coordinate of draw icon
 * RETURNS
 *  void
 *****************************************************************************/
void gui_status_icon_bar_show_integrated_icon(gui_status_icon_bar_icon_struct *icon, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (icon->flags & GUI_STATUS_ICON_BAR_ICON_ANIMATE)
    {
        gdi_image_draw_frames_blend2layers(
            x,
            y,
            icon->image_data,
            icon->current_frame);
    }
    else if (icon->flags & GUI_STATUS_ICON_BAR_ICON_DISPLAY)
    {
        if (icon->state > 0)
        {
            gdi_image_draw_frames_blend2layers(
                x,
                y,
                icon->image_data,
                icon->state);
        }
        else
        {
            gdi_image_draw_blend2layers(x, y, icon->image_data);
        }
    }
}


/****************************************************************************
 * Element
 ****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_create_element
 * DESCRIPTION
 *  Create a element
 * PARAMETERS
 *  element         [IN]        Pointer to element struct
 *  width           [IN]        Width of element
 *  height          [IN]        Height of element
 *  show            [IN]        Pointer to show function of element
 * RETURNS
 *  void
 *****************************************************************************/
void gui_status_icon_bar_create_element(
        gui_status_icon_bar_element_struct *element,
        S32 width,
        S32 height,
        void (*show)(S32 x1, S32 y1, S32 x2, S32 y2),
        U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    element->x = 0;
    element->y = 0;
    element->width = width;
    element->height = height;
    element->show = show;
    element->active = MMI_TRUE;
    element->flag = flag;
}


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_register_element_show
 * DESCRIPTION
 *  Register the show function of element
 * PARAMETERS
 *  element       [IN]        Pointer to element struct
 *  show          [IN]        Pointer to new show function of element
 * RETURNS
 *  void
 *****************************************************************************/
void gui_status_icon_bar_register_element_show(
        gui_status_icon_bar_element_struct *element,
        void (*show)(S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    element->show = show;
}


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_resize_element
 * DESCRIPTION
 *  Resize the size of element
 * PARAMETERS
 *  element       [IN]        Pointer to element struct
 *  width         [IN]        Width of element
 *  height        [IN]        Height of element
 * RETURNS
 *  void
 *****************************************************************************/
void gui_status_icon_bar_resize_element(gui_status_icon_bar_element_struct *element, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    element->width = width;
    element->height = height;
}


/*****************************************************************************
 * FUNCTION
 *  gui_status_icon_bar_close_element
 * DESCRIPTION
 *  Reset the element
 * PARAMETERS
 *  element       [IN]        Pointer to element struct
 * RETURNS
 *  void
 *****************************************************************************/
void gui_status_icon_bar_close_element(gui_status_icon_bar_element_struct *element)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    element->x = 0;
    element->y = 0;
    element->width = 0;
    element->height = 0;
    element->show = NULL;
    element->active = MMI_FALSE;
    element->flag = 0;
}



