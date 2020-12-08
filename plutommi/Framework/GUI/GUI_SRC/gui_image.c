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
 *  gui_image.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Public Source
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMIDataType.h"

#include "kal_release.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"

#include "lcd_sw_rnd.h"
#include "lcd_sw_inc.h"
#include "MMI_trc_Int.h"
#include "ScrMemMgrGprot_Int.h"
#include "gui_image.h"
#include "gui.h"

/*****************************************************************************
 * include
 ****************************************************************************/
/* Write your #include header file here */


/*****************************************************************************
 * Static Declaration
 ****************************************************************************/
/* Define your local variable here */
/* Local variable are those variable only be used within this .c file. */


/* Declare your local function here */
static void gui_image_adjust_image(gui_image_struct *image);
static GDI_RESULT gui_image_show_ex(gui_image_struct *image, U32 start_frame);
static GDI_RESULT gui_image_parse_image(
                   const PU8 image_buffer,
                   gdi_image_src_enum image_scr,
                   S32 *image_width,
                   S32 *image_height,
                   S32 *frame_count,
                   U16 *image_type);
static GDI_RESULT gui_image_create(
                   gui_image_struct *image,
                   S32 x,
                   S32 y,
                   S32 width,
                   S32 height,
                   const PU8 image_buffer,
                   gdi_image_src_enum image_scr,
                   U32 flags,
                   gdi_handle target_layer);
static void gui_image_anim_get_pause_frame(gui_image_struct *image);
static GDI_RESULT gui_image_set_image(
                   gui_image_struct *image,
                   U16 image_type,
                   const PU8 image_buffer,
                   gdi_image_src_enum image_scr);
static void gui_image_anim_stop_pause_state(gui_image_struct *image);

/*****************************************************************************
 * Global Variable
 ****************************************************************************/
/* Write your global variable here */
extern S32 gdi_anim_get_current_frame_number(gdi_handle serial_handle);
extern GDI_RESULT gdi_image_codec_get_frame_count(
                   gdi_image_src_enum src_type,
                   U8 *img_src,
                   U8 img_type,
                   S32 img_size,
                   S32 *frame_count,
                   U32 flag);
extern MMI_BOOL wgui_is_wallpaper_on_bottom(void);
/*****************************************************************************
 * Local Function
 ****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  gui_image_default_hide_function
 * DESCRIPTION
 *  use transparent color to redraw image bg  
 * PARAMETERS
 *  x1      [IN]     coordinate x1
 *  y1      [IN]     coordinate y1
 *  x2      [IN]     coordinate x2
 *  y2      [IN]     coordinate y2
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_image_default_hide_function(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  gui_image_show_ex
 * DESCRIPTION
 *  the function used to show an image component
 * PARAMETERS
 *  image           [IN]    pointer of image component
 *  start_frame     [IN]    start frame
 * RETURNS
 *  GDI_RESULT      [OUT]   result of show
 *****************************************************************************/
static GDI_RESULT gui_image_show_ex(gui_image_struct *image, U32 start_frame)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT result = GDI_FAILED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gdi_layer_set_clip(
        image->x + image->image_display_x,
        image->y + image->image_display_y,
        image->x + image->image_display_x + image->image_display_width - 1,
        image->y + image->image_display_y + image->image_display_height - 1);

    /* clear gdi working buffer */
    gdi_image_clear_work_buffer();

    if (image->image_scr == GDI_IMAGE_SRC_FROM_FILE)
    {
        if (image->image_type == GDI_IMAGE_TYPE_GIF_FILE)
        {
            /* reset image cache, only gif need this operation */
            gdi_image_cache_reset();
        }
        /* is animation */
        if (image->frame_count > 1)
        {                
            result = gdi_anim_codec_draw_internal(
                         GDI_IMAGE_SRC_FROM_FILE,
                         image->image_buffer,
                         (U8)image->image_type,
                         0,
                         image->x + image->image_display_x,
                         image->y + image->image_display_y,
                         image->image_display_width,
                         image->image_display_height,
                         0,
                         &image->image_handle,
                         start_frame,
                         -1);
        }
        else
        {
            result = gdi_image_draw_resized_file(
                         image->x + image->image_display_x,
                         image->y + image->image_display_y,
                         image->image_display_width,
                         image->image_display_height,
                         image->image_buffer);
        }
    }
    else if (image->image_scr == GDI_IMAGE_SRC_FROM_MEMORY)
    {
        if (image->image_type == GDI_IMAGE_TYPE_GIF)
        {
            /* reset image cache, only gif need this operation */
            gdi_image_cache_reset();            
        }
        if (image->image_type == GDI_IMAGE_TYPE_GIF ||
            image->image_type == GDI_IMAGE_TYPE_AVATAR ||
            image->image_type == GDI_IMAGE_TYPE_M3D)
        {
            result = gdi_anim_draw_mem_resized_frames(
                         image->x + image->image_display_x,
                         image->y + image->image_display_y,
                         image->image_display_width,
                         image->image_display_height,
                         (PS8)image->image_buffer,
                         (U8)image->image_type,
                         0,
                         &image->image_handle,
                         start_frame);
        }
        else
        {
            result = gdi_image_draw_resized_mem(
                         image->x + image->image_display_x,
                         image->y + image->image_display_y,
                         image->image_display_width,
                         image->image_display_height,
                         image->image_buffer,
                         (U8)image->image_type,
                         0);
        }
    }
    else if (image->image_scr == GDI_IMAGE_SRC_FROM_RESOURCE)
    {
        if (image->image_type == GDI_IMAGE_TYPE_GIF ||
            image->image_type == GDI_IMAGE_TYPE_GIF_FILE)
        {
            /* reset image cache, only gif need this operation */
            gdi_image_cache_reset();                    
        }
        /* is animation */
        if (image->frame_count > 1)
        {                
            result = gdi_anim_draw_resized_frames(
                         image->x + image->image_display_x,
                         image->y + image->image_display_y,
                         image->image_display_width,
                         image->image_display_height,
                         image->image_buffer,
                         &image->image_handle,
                         start_frame);
        }
        else
        {
            result = gdi_image_draw_resized(
                         image->x + image->image_display_x,
                         image->y + image->image_display_y,
                         image->image_display_width,
                         image->image_display_height,
                         image->image_buffer);
        }
    }

    /* if display fail, show default image */
    if (result != GDI_SUCCEED)
    {
        if (!(image->flags & GUI_IMAGE_NOT_SHOW_DEFAULT_IMAGE))
        {
            gdi_image_draw_resized_id(
                image->x + image->image_display_x,
                image->y + image->image_display_y,
                image->image_display_width,
                image->image_display_height,
                IMG_GLOBAL_DEFAULT);
        }
    }

    gdi_layer_pop_clip();
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  gui_image_anim_get_pause_frame
 * DESCRIPTION
 *  The API used to get the paused frame when pause an animation
 * PARAMETERS
 *  image       [IN]    pointer of image component
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_image_anim_get_pause_frame(gui_image_struct *image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    GDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get current play frame number */
    image->pause_frame = gdi_anim_get_current_frame_number(image->image_handle);

    /*result =*/ gdi_anim_pause(image->image_handle);
    //MMI_DBG_ASSERT(result == GDI_SUCCEED);
    image->paused_handle = image->image_handle;
    image->image_handle = GDI_ERROR_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_image_adjust_image
 * DESCRIPTION
 *  The API used to adjust the logic position of image in an image component 
 * PARAMETERS
 *  image       [IN]    pointer of image component
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_image_adjust_image(gui_image_struct *image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x, offset_y, offset_width, offset_height;
       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (image->enable_stretch == MMI_TRUE)
    {
        image->image_display_x = 0;
        image->image_display_y = 0;
        image->image_display_width = image->width;
        image->image_display_height = image->height;
        return;
    }

    /* if image's width/height is larger than component's width/height
     * we should adjust the width/height of image
     */
    if (image->image_width > image->width || image->image_height > image->height)
    {
        gdi_image_util_fit_bbox(
            image->width,
            image->height,
            image->image_width,
            image->image_height,
            &offset_x,
            &offset_y,
            &offset_width,
            &offset_height);
            
        image->image_display_width = offset_width;
        image->image_display_height = offset_height;
    }
    else
    {
        image->image_display_width = image->image_width;
        image->image_display_height = image->image_height;
    }

    switch (image->image_h_align_type)
    {
        case GUI_IMAGE_H_ALIGN_LEFT:
            {
                image->image_display_x = 0;
            }
            break;

        case GUI_IMAGE_H_ALIGN_CENTER:
            {
                image->image_display_x = (image->width >> 1) - (image->image_display_width >> 1);
            }
            break;
    
        case GUI_IMAGE_H_ALIGN_RIGHT:
            {
                image->image_display_x = image->width - image->image_display_width;
            }
            break;
 
        default:
            break;
    }
    
    switch (image->image_v_align_type)
    {
        case GUI_IMAGE_V_ALIGN_TOP:
            {
                image->image_display_y = 0;
            }
            break;

        case GUI_IMAGE_V_ALIGN_CENTER:
            {
                image->image_display_y = (image->height >> 1) - (image->image_display_height >> 1);
            }
            break;
    
        case GUI_IMAGE_V_ALIGN_BOTTOM:
            {
                image->image_display_y = image->height - image->image_display_height;
            }
            break;
 
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_image_parse_image
 * DESCRIPTION
 *  The API used to parse info of an image.
 * PARAMETERS
 *  file_name       [IN]    name of image file
 *  image_scr       [IN]    gdi image source
 *  image_buffer    [IN]    buffer that record image data
 *  image_width     [IN/OUT]
 *  image_height    [IN/OUT]
 *  frame_count     [IN/OUT]
 *  image_type      [IN/OUT]
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
static GDI_RESULT gui_image_parse_image(
                   const PU8 image_buffer,
                   gdi_image_src_enum image_scr,
                   S32 *image_width,
                   S32 *image_height,
                   S32 *frame_count,
                   U16 *image_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT result_dimension = GDI_FAILED;
    GDI_RESULT result_frame = GDI_FAILED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* from file */
    if (image_scr == GDI_IMAGE_SRC_FROM_FILE)
    {
        result_dimension = gdi_image_get_dimension_file(
                               (S8*)image_buffer,
                               image_width,
                               image_height);
        result_frame = gdi_image_get_frame_count_file(
                           image_buffer,
                           frame_count);
        *image_type = gdi_image_get_type_from_file((S8*)image_buffer);
        /* parse image succeed from file */
        if ((result_dimension == GDI_SUCCEED) &&
            (result_frame == GDI_SUCCEED) &&
            !((*image_type == GDI_IMAGE_TYPE_INVALID) ||
              (*image_type >= GDI_IMAGE_TYPE_SUM)))
        {
            return GDI_SUCCEED;
        }
    }
    /* from resource, has 8 byte header */
    else if (image_scr == GDI_IMAGE_SRC_FROM_RESOURCE)
    {
        result_dimension = gdi_image_get_dimension(
                               image_buffer,
                               image_width,
                               image_height);
        result_frame = gdi_image_get_frame_count(
                           image_buffer,
                           frame_count);
        *image_type = gdi_image_get_buf_type(image_buffer);
        /* parse image succeed from resource */
        if ((result_dimension == GDI_SUCCEED) &&
            (result_frame == GDI_SUCCEED) &&
            !((*image_type == GDI_IMAGE_TYPE_INVALID) ||
              (*image_type >= GDI_IMAGE_TYPE_SUM)))
        {
            return GDI_SUCCEED;
        }
    }
    /* from memory, has not 8 byte header */
    else if (image_scr == GDI_IMAGE_SRC_FROM_MEMORY)
    {
        /* if user's image_type is not a valid gdi image type */
        if (*image_type == GDI_IMAGE_TYPE_INVALID ||
            *image_type >= GDI_IMAGE_TYPE_SUM)
        {
            *image_type = gdi_image_get_type_from_mem((PS8)image_buffer);
        }
        if (!(*image_type == GDI_IMAGE_TYPE_INVALID ||
              *image_type >= GDI_IMAGE_TYPE_SUM))
        {
            result_frame = gdi_image_codec_get_frame_count(
                               GDI_IMAGE_SRC_FROM_MEMORY,
                               image_buffer,
                               (U8)(*image_type),
                               0,
                               frame_count,
                               0);
            result_dimension = gdi_image_get_dimension_mem(
                                   (U8)(*image_type),
                                   image_buffer,
                                   0,
                                   image_width,
                                   image_height);
            if (result_dimension == GDI_SUCCEED && result_frame == GDI_SUCCEED)
            {
                return GDI_SUCCEED;
            }
        }
    }

    if (result_dimension != GDI_SUCCEED)
    {
        return result_dimension;
    }
    if (result_frame != GDI_SUCCEED)
    {
        return result_frame;
    }
    if (*image_type == GDI_IMAGE_TYPE_INVALID || *image_type >= GDI_IMAGE_TYPE_SUM)
    {
        return GDI_IMAGE_ERR_INVALID_IMG_TYPE;
    }
    return GDI_FAILED;
}


/*****************************************************************************
 * FUNCTION
 *  gui_image_create
 * DESCRIPTION
 *  Create API of image component. User can use file_name ,image_res or 
 *  image_data as input to tell component image data. 
 *  The API will return GDI_RESULT.
 * PARAMETERS
 *  image       [IN]    pointer of image component
 *  x           [IN]    x position of image component
 *  y           [IN]    y position of image component
 *  width       [IN]    width of image component
 *  height      [IN]    height of image component
 *  image_buffer[IN]    buffer that record image data
 *  image_scr   [IN]    gdi image source, from file/mem/resource
 *  flags       [IN]    flag of image component
 *  target_layer[IN]      
 * RETURNS
 *  GDI_RESULT  [OUT]
 *****************************************************************************/
static GDI_RESULT gui_image_create(
                   gui_image_struct *image,
                   S32 x,
                   S32 y,
                   S32 width,
                   S32 height,
                   const PU8 image_buffer,
                   gdi_image_src_enum image_scr,
                   U32 flags,
                   gdi_handle target_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT result;
    S32 image_width, image_height, frame_count;
    U16 image_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (image_scr == GDI_IMAGE_SRC_FROM_MEMORY)
    {
        image_type = image->image_type;
    }
    result = gui_image_parse_image(
                 image_buffer,
                 image_scr,
                 &image_width,
                 &image_height,
                 &frame_count,
                 &image_type);
    if (result != GDI_SUCCEED)
    {
        return result;
    }

    image->active = MMI_TRUE;
    /* component's position and dimension */
    image->x = x;
    image->y = y;
    image->width = width;
    image->height = height;
    /* image's dimension */
    image->image_width = image_width;
    image->image_height = image_height;
    image->image_h_align_type = GUI_IMAGE_H_ALIGN_CENTER;
    image->image_v_align_type = GUI_IMAGE_V_ALIGN_CENTER;
    image->enable_stretch = MMI_FALSE;
    gui_image_adjust_image(image);
        
    image->image_type = image_type;
    image->image_scr = image_scr;
    image->image_buffer = image_buffer;

    image->flags = flags;

    if (target_layer == GDI_NULL_HANDLE)
    {
        gdi_layer_get_active(&(image->target_layer));
    }
    else
    {
        image->target_layer = target_layer;
    }
    image->hide_callback = gui_image_default_hide_function;
    image->image_handle = GDI_ERROR_HANDLE;

    image->anim_layer_ptr = NULL;
    image->anim_layer_handle = GDI_NULL_HANDLE;

    image->start_frame = 0;
    image->pause_frame = GUI_IMAGE_ANIM_RESUME_DISABLE;
    image->paused_handle = GDI_ERROR_HANDLE;
    image->frame_count = frame_count;
    image->is_non_blocking = MMI_FALSE;
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gui_image_set_image
 * DESCRIPTION
 *  the function used to set image of component
 * PARAMETERS
 *  image           [IN]    pointer of image component
 *  image_type      [IN]    this para is only valid when image is from memory
 *  image_buffer    [IN]    buffer that record image data
 *  image_scr       [IN]    gdi image source
 * RETURNS
 *  GDI_RESULT        [OUT]   set success or fail
 *****************************************************************************/
static GDI_RESULT gui_image_set_image(
                   gui_image_struct *image,
                   U16 image_type,
                   const PU8 image_buffer,
                   gdi_image_src_enum image_scr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT result;
    S32 image_width, image_height, frame_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = gui_image_parse_image(
                 image_buffer,
                 image_scr,
                 &image_width,
                 &image_height,
                 &frame_count,
                 &image_type);
    if (result != GDI_SUCCEED)
    {
        return result;
    }

    /* if an anim is playing */
    if (image->image_handle != GDI_ERROR_HANDLE)
    {
        if (image->is_non_blocking == MMI_TRUE)
        {
            result = gdi_anim_nb_stop(image->image_handle);
            image->is_non_blocking = MMI_FALSE;
        }
        else
        {
            result = gdi_anim_stop(image->image_handle);
        }
        MMI_DBG_ASSERT(result == GDI_SUCCEED);
        image->image_handle = GDI_ERROR_HANDLE;
    }
    /* if is in pause state */
    if (image->paused_handle != GDI_ERROR_HANDLE)
    {
        result = gdi_anim_stop(image->paused_handle);
        MMI_DBG_ASSERT(result == GDI_SUCCEED);
        image->paused_handle = GDI_ERROR_HANDLE;
        image->pause_frame = GUI_IMAGE_ANIM_RESUME_DISABLE;
    }
    if (image->anim_layer_ptr != NULL &&
        image->anim_layer_handle != GDI_NULL_HANDLE)
    {
        /* free pause layer and buffer, show anim from start frame */
        gdi_layer_free(image->anim_layer_handle);
        mmi_frm_scrmem_free(image->anim_layer_ptr);
        image->anim_layer_handle = GDI_NULL_HANDLE;
        image->anim_layer_ptr = NULL;
    }
    /* image's dimension */
    image->image_width = image_width;
    image->image_height = image_height;
    image->image_display_width = image_width;
    image->image_display_height = image_height;
    gui_image_adjust_image(image);
        
    image->image_type = image_type;
    image->image_scr = image_scr;
    image->image_buffer = image_buffer;
        
    image->start_frame = 0;
    image->frame_count = frame_count;
    image->pause_frame = GUI_IMAGE_ANIM_RESUME_DISABLE;
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gui_image_anim_stop_pause_state
 * DESCRIPTION
 *  The API used to stop an anim's pause state when pos, size or layer change 
 * PARAMETERS
 *  image       [IN]    pointer of image component
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_image_anim_stop_pause_state(gui_image_struct *image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    GDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (image->paused_handle != GDI_ERROR_HANDLE)
    {
        /*result =*/ gdi_anim_stop(image->paused_handle);
        //MMI_DBG_ASSERT(result == GDI_SUCCEED);
        image->paused_handle = GDI_ERROR_HANDLE;
        /* if is a GIF */
        if (image->anim_layer_ptr != NULL &&
            image->anim_layer_handle != GDI_NULL_HANDLE)
        {
            /* free pause layer and buffer, show anim from start frame */
            gdi_layer_free(image->anim_layer_handle);
            mmi_frm_scrmem_free(image->anim_layer_ptr);
            image->anim_layer_handle = GDI_NULL_HANDLE;
            image->anim_layer_ptr = NULL;
            image->pause_frame = 0;
        }
    }
}


/*****************************************************************************
 * Global Function
 ****************************************************************************/
/* Write your global function here */
/*****************************************************************************
 * FUNCTION
 *  gui_image_create_from_file
 * DESCRIPTION
 *  Create API of image component, which create image from image file.
 *  The API will return GDI_RESULT.
 * PARAMETERS
 *  image       [IN]    pointer of image component
 *  x           [IN]    x position of image component
 *  y           [IN]    y position of image component
 *  width       [IN]    width of image component
 *  height      [IN]    height of image component
 *  file_name   [IN]    name of image file
 *  flags       [IN]    flags
 *  target_layer[IN]      
 * RETURNS
 *  GDI_RESULT  [OUT]
 *****************************************************************************/
GDI_RESULT gui_image_create_from_file(
            gui_image_struct *image,
            S32 x,
            S32 y,
            S32 width,
            S32 height,
            const PU8 file_name, 
            U32 flags,
            gdi_handle target_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image->active == MMI_FALSE);
    return gui_image_create(
               image,
               x,
               y,
               width,
               height,
               file_name,
               GDI_IMAGE_SRC_FROM_FILE,
               flags,
               target_layer);
}


/*****************************************************************************
 * FUNCTION
 *  gui_image_create_from_res
 * DESCRIPTION
 *  Create API of image component, which create image from resource,
 *  has 8 bytes header.
 *  The API will return GDI_RESULT.
 * PARAMETERS
 *  image       [IN]    pointer of image component
 *  x           [IN]    x position of image component
 *  y           [IN]    y position of image component
 *  width       [IN]    width of image component
 *  height      [IN]    height of image component
 *  image_res   [IN]    buffer of image resource
 *  flags       [IN]    flags
 *  target_layer[IN]      
 * RETURNS
 *  GDI_RESULT  [OUT]
 *****************************************************************************/
GDI_RESULT gui_image_create_from_res(
            gui_image_struct *image,
            S32 x,
            S32 y,
            S32 width,
            S32 height,
            const PU8 image_res, 
            U32 flags,
            gdi_handle target_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image->active == MMI_FALSE);
    return gui_image_create(
               image,
               x,
               y,
               width,
               height,
               image_res,
               GDI_IMAGE_SRC_FROM_RESOURCE,
               flags,
               target_layer);
}


/*****************************************************************************
 * FUNCTION
 *  gui_image_create_from_mem
 * DESCRIPTION
 *  Create API of image component from image raw data, without 8 bytes header.
 *  REMARK: gdi_image_type can be avatar, BMP, GIF, JPG, PNG, etc.
 *  Avatar can only use this API to create image component.
 *  If user use GDI_IMAGE_TYPE_INVALID in image_type, we will decode image type
 *  at first. But if use valid image type, we will just use this given type.
 * PARAMETERS
 *  image       [IN]    pointer of image component
 *  x           [IN]    x position of image component
 *  y           [IN]    y position of image component
 *  width       [IN]    width of image component
 *  height      [IN]    height of image component
 *  image_type  [IN]    gdi image type of image
 *  image_data  [IN]    buffer of image raw data
 *  flags       [IN]    flags
 *  target_layer[IN]      
 * RETURNS
 *  GDI_RESULT  [OUT]
 *****************************************************************************/
GDI_RESULT gui_image_create_from_mem(
            gui_image_struct *image,
            S32 x,
            S32 y,
            S32 width,
            S32 height,
            U32 image_type,
            const PU8 image_data, 
            U32 flags,
            gdi_handle target_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image->active == MMI_FALSE);
    image->image_type = (U16)image_type;
    return gui_image_create(
               image,
               x,
               y,
               width,
               height,
               image_data,
               GDI_IMAGE_SRC_FROM_MEMORY,
               flags,
               target_layer);
}


/*****************************************************************************
 * FUNCTION
 *  gui_image_close
 * DESCRIPTION
 *  the function used to close image component
 * PARAMETERS
 *  image   [IN]    pointer of image component
 * RETURNS
 *  void
 *****************************************************************************/
void gui_image_close(gui_image_struct *image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
//    GDI_RESULT result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  //  MMI_DBG_ASSERT(image != NULL);
  //  MMI_DBG_ASSERT(image->active == MMI_TRUE);
    if (image->image_handle != GDI_ERROR_HANDLE)
    {
        if (image->is_non_blocking == MMI_TRUE)
        {
            /*result =*/ gdi_anim_nb_stop(image->image_handle);
            image->is_non_blocking = MMI_FALSE;
        }
        else
        {
            /*result =*/ gdi_anim_stop(image->image_handle);
        }
       // MMI_DBG_ASSERT(result == GDI_SUCCEED);
        image->image_handle = GDI_ERROR_HANDLE;
    }
    if (image->paused_handle != GDI_ERROR_HANDLE)
    {
        /*result =*/ gdi_anim_stop(image->paused_handle);
       // MMI_DBG_ASSERT(result == GDI_SUCCEED);
        image->paused_handle = GDI_ERROR_HANDLE;
    }
    if (image->anim_layer_ptr != NULL &&
        image->anim_layer_handle != GDI_NULL_HANDLE)
    {
        /* free pause layer and buffer, show anim from start frame */
        gdi_layer_free(image->anim_layer_handle);
        mmi_frm_scrmem_free(image->anim_layer_ptr);
        image->anim_layer_handle = GDI_NULL_HANDLE;
        image->anim_layer_ptr = NULL;
    }
    image->target_layer = GDI_NULL_HANDLE;
    image->image_buffer = NULL;
    image->hide_callback = NULL;
    image->active = MMI_FALSE;    
}


/*****************************************************************************
 * FUNCTION
 *  gui_image_move
 * DESCRIPTION
 *  the function used to move an image component
 * PARAMETERS
 *  image   [IN]    pointer of image component
 *  x       [IN]
 *  y       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_image_move(gui_image_struct *image, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image != NULL);
    MMI_DBG_ASSERT(image->active == MMI_TRUE);
    if (image->paused_handle != GDI_ERROR_HANDLE &&
        (image->x != x || image->y != y))
    {
        gui_image_anim_stop_pause_state(image);
    }
    image->x = x;
    image->y = y;
}


/*****************************************************************************
 * FUNCTION
 *  gui_image_resize
 * DESCRIPTION
 *  the function used to resize an image component
 * PARAMETERS
 *  image   [IN]    pointer of image component
 *  width   [IN]
 *  height  [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_image_resize(gui_image_struct *image, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image != NULL);
    MMI_DBG_ASSERT(image->active == MMI_TRUE);
    if (image->paused_handle != GDI_ERROR_HANDLE &&
        (image->width != width || image->height != height))
    {
        gui_image_anim_stop_pause_state(image);
    }
    image->width = width;
    image->height = height;
    gui_image_adjust_image(image);
}


/*****************************************************************************
 * FUNCTION
 *  gui_image_show
 * DESCRIPTION
 *  the function used to show an image component
 * PARAMETERS
 *  image           [IN]    pointer of image component
 * RETURNS
 *  GDI_RESULT      [OUT]   result of show
 *****************************************************************************/
GDI_RESULT gui_image_show(gui_image_struct *image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT result;
    GDI_HANDLE abm_layer = GDI_NULL_HANDLE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image != NULL);
    MMI_DBG_ASSERT(image->active == MMI_TRUE);

    /* if anim is playing */
    if (image->image_handle != GDI_ERROR_HANDLE)
    {
        if (image->is_non_blocking == MMI_TRUE)
        {
            result = gdi_anim_nb_stop(image->image_handle);
            image->is_non_blocking = MMI_FALSE;
        }
        else
        {
            result = gdi_anim_stop(image->image_handle);
        }

        MMI_DBG_ASSERT(result == GDI_SUCCEED);
        image->image_handle = GDI_ERROR_HANDLE;
    }
    else /* maybe init or pause state */
    {
        /* if show is called after anim pause */
        if (image->paused_handle != GDI_ERROR_HANDLE)
        {
            result = gdi_anim_stop(image->paused_handle);
            MMI_DBG_ASSERT(result == GDI_SUCCEED);
            image->paused_handle = GDI_ERROR_HANDLE;
        }
        if (image->anim_layer_ptr != NULL &&
            image->anim_layer_handle != GDI_NULL_HANDLE)
        {
            /* free pause layer and buffer, show anim from start frame */
            gdi_layer_free(image->anim_layer_handle);
            mmi_frm_scrmem_free(image->anim_layer_ptr);
            image->anim_layer_handle = GDI_NULL_HANDLE;
            image->anim_layer_ptr = NULL;
            image->pause_frame = GUI_IMAGE_ANIM_RESUME_DISABLE;
        }
    }

    gdi_layer_lock_frame_buffer();
    if (image->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_push_and_set_active(image->target_layer);
    }
    gdi_layer_push_clip();
    gdi_layer_set_clip(
        image->x,
        image->y,
        image->x + image->width - 1,
        image->y + image->height - 1);

    /* draw background */
    if (image->flags & GUI_IMAGE_FILL_WHITE_BACKGROUND)
    {
        gdi_draw_solid_rect(
            image->x,
            image->y,
            image->x + image->width - 1,
            image->y + image->height - 1,
            GDI_COLOR_WHITE);
        abm_layer = gdi_set_alpha_blending_source_layer(image->target_layer);
    }
    else
    {
        image->hide_callback(
            image->x,
            image->y,
            image->x + image->width - 1,
            image->y + image->height - 1);
    }

    result = gui_image_show_ex(image, image->start_frame);

    if (image->flags & GUI_IMAGE_FILL_WHITE_BACKGROUND && abm_layer != GDI_NULL_HANDLE)
    {
        gdi_set_alpha_blending_source_layer(abm_layer);
    }

    gdi_layer_pop_clip();
    if (image->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }
    gdi_layer_unlock_frame_buffer();
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  gui_image_pause
 * DESCRIPTION
 *  the function used to pause the display of animated image component
 *  Remark: pause function will not apply to non blocking image show
 * PARAMETERS
 *  image           [IN]    pointer of image component
 * RETURNS
 *  void
 *****************************************************************************/
void gui_image_pause(gui_image_struct *image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 bits_per_pixel;
    S32 buf_size;
    U8 *src_ptr = NULL;
    U8 *dest_ptr = NULL;
    GDI_HANDLE temp_layer_handle = GDI_NULL_HANDLE;
    GDI_RESULT result;
    S32 src_layer_width, src_layer_height;
    gdi_rect_struct dest_clip;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image != NULL);
    MMI_DBG_ASSERT(image->active == MMI_TRUE);

    /* pause will only work when anim is playing */
    if (image->image_handle != GDI_ERROR_HANDLE)
    {       
        MMI_DBG_ASSERT(image->is_non_blocking == MMI_FALSE);
        /* if image is not gif, no need to record image content */
        if (!(image->image_type == GDI_IMAGE_TYPE_GIF_FILE ||
            image->image_type == GDI_IMAGE_TYPE_GIF))
        {
            gui_image_anim_get_pause_frame(image);
            return;
        }

        /* get target layer's bits per pixel */
        if (image->target_layer != GDI_NULL_HANDLE)
        {
            gdi_layer_push_and_set_active(image->target_layer);
        }

        bits_per_pixel = gdi_layer_get_bit_per_pixel();
        buf_size =
            (image->image_display_width * image->image_display_height * bits_per_pixel) >> 3;
        MMI_DBG_ASSERT(buf_size <= MMI_IMAGE_COMPONENT_BUF_SIZE);

        /* malloc memory to store anim's content */
        dest_ptr = (U8*)mmi_frm_scrmem_alloc(buf_size);
        /* If not get the memory, GIF image can not pause and has to
         * play from the first frame when resume
         */
        if (dest_ptr == NULL)
        {
            gui_image_anim_get_pause_frame(image);
            image->pause_frame = 0;
        }
        else /* malloc success */
        {
            /* create a layer to record current frame's content */
            result = gdi_layer_create_cf_using_outside_memory(
                         gdi_act_layer->cf, /* color format */
                         0,
                         0,
                         image->image_display_width,
                         image->image_display_height,
                         &temp_layer_handle,
                         dest_ptr,
                         buf_size);

            if (result == GDI_SUCCEED)
            {
                /* get currently active layer's frame buffer pointer */
                gdi_layer_get_buffer_ptr(&src_ptr);
                gdi_layer_get_dimension(&src_layer_width, &src_layer_height);
                dest_clip.x1 = 0;
                dest_clip.y1 = 0;
                dest_clip.x2 = dest_clip.x1 + image->image_display_width - 1;
                dest_clip.y2 = dest_clip.y1 + image->image_display_height - 1;

                gdi_layer_lock_frame_buffer();

                gui_image_anim_get_pause_frame(image);
                gdi_2d_memory_blt(	
                    src_ptr,
                    src_layer_width,
                    image->x + image->image_display_x,
                    image->y + image->image_display_y,
                    image->image_display_width,
                    image->image_display_height,
                    dest_ptr,
                    image->image_display_width,
                    0,
                    0,
                    dest_clip,
                    bits_per_pixel);
                image->anim_layer_ptr = dest_ptr;
                image->anim_layer_handle = temp_layer_handle;

                gdi_layer_unlock_frame_buffer();
            }
            else /* create layer fail */
            {
                mmi_frm_scrmem_free(dest_ptr);
                gui_image_anim_get_pause_frame(image);
                image->pause_frame = 0;
            }
        }

        if (image->target_layer != GDI_NULL_HANDLE)
        {
            gdi_layer_pop_and_restore_active();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_image_resume
 * DESCRIPTION
 *  the function used to resume the display of animated image component
 *  Remark: resume function will not apply to non blocking image show
 * PARAMETERS
 *  image           [IN]    pointer of image component
 * RETURNS
 *  GDI_RESULT      [OUT]   result of resume
 *****************************************************************************/
GDI_RESULT gui_image_resume(gui_image_struct *image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT result;
    S32  dest_bits_per_pixel;//src_bits_per_pixel,
    U8 *dest_ptr = NULL;
    S32 src_layer_width, src_layer_height;
    S32 dest_layer_width, dest_layer_height;
    gdi_rect_struct dest_clip;
    GDI_HANDLE abm_layer = GDI_NULL_HANDLE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image != NULL);
    MMI_DBG_ASSERT(image->active == MMI_TRUE);

    /* you can not resume an anim just after create/resume or anim is in playing */
    if (image->pause_frame == GUI_IMAGE_ANIM_RESUME_DISABLE ||
        image->image_handle != GDI_ERROR_HANDLE)
    {
        MMI_DBG_ASSERT(image->anim_layer_ptr == NULL &&
                   image->anim_layer_handle == GDI_NULL_HANDLE);
        return GDI_FAILED;
    }

    MMI_DBG_ASSERT(image->is_non_blocking == MMI_FALSE);
    gdi_layer_lock_frame_buffer();
    if (image->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_push_and_set_active(image->target_layer);
    }
    gdi_layer_push_clip();
    gdi_layer_set_clip(
        image->x,
        image->y,
        image->x + image->width - 1,
        image->y + image->height - 1);

    /* draw background */
    if (image->flags & GUI_IMAGE_FILL_WHITE_BACKGROUND)
    {
        gdi_draw_solid_rect(
            image->x,
            image->y,
            image->x + image->width - 1,
            image->y + image->height - 1,
            GDI_COLOR_WHITE);
    }
    else
    {
        image->hide_callback(
            image->x,
            image->y,
            image->x + image->width - 1,
            image->y + image->height - 1);
    }

    /* if anim's content has been stored, it is a GIF */
    if (image->anim_layer_ptr != NULL &&
        image->anim_layer_handle != GDI_NULL_HANDLE)
    {
        gdi_layer_push_and_set_active(image->anim_layer_handle);
        gdi_layer_get_dimension(&src_layer_width, &src_layer_height);
        //src_bits_per_pixel = gdi_layer_get_bit_per_pixel();
        gdi_layer_pop_and_restore_active();
        /* if image's display dimension value not changed, we can copy
         * the content directly
         */
        if (src_layer_width == image->image_display_width &&
            src_layer_height == image->image_display_height)
        {
            dest_bits_per_pixel = gdi_layer_get_bit_per_pixel();
           // MMI_DBG_ASSERT(src_bits_per_pixel == dest_bits_per_pixel);
            gdi_layer_get_buffer_ptr(&dest_ptr);
            gdi_layer_get_dimension(&dest_layer_width, &dest_layer_height);
            dest_clip.x1 = image->x + image->image_display_x;
            dest_clip.y1 = image->y + image->image_display_x;
            dest_clip.x2 = dest_clip.x1 + image->image_display_width - 1;
            dest_clip.y2 = dest_clip.y1 + image->image_display_height - 1;
            gdi_2d_memory_blt(	
                image->anim_layer_ptr,
                image->image_display_width,
                0,
                0,
                image->image_display_width,
                image->image_display_height,
                dest_ptr,
                dest_layer_width,
                image->x + image->image_display_x,
                image->y + image->image_display_y,
                dest_clip,
                dest_bits_per_pixel);
        }
        /* free pause layer and buffer */
        gdi_layer_free(image->anim_layer_handle);
        mmi_frm_scrmem_free(image->anim_layer_ptr);
        image->anim_layer_handle = GDI_NULL_HANDLE;
        image->anim_layer_ptr = NULL;
    }

    MMI_DBG_ASSERT(image->anim_layer_ptr == NULL &&
               image->anim_layer_handle == GDI_NULL_HANDLE);

    /* if anim has not change size and pos, use gdi resume */
    if (image->paused_handle != GDI_ERROR_HANDLE)
    {
        if (image->flags & GUI_IMAGE_FILL_WHITE_BACKGROUND)
        {
            abm_layer = gdi_set_alpha_blending_source_layer(image->target_layer);
        }

        result = gdi_anim_resume(image->paused_handle);

        if (image->flags & GUI_IMAGE_FILL_WHITE_BACKGROUND &&
            abm_layer != GDI_NULL_HANDLE)
        {
            gdi_set_alpha_blending_source_layer(abm_layer);
        }

        if (result == GDI_SUCCEED)
        {
            image->image_handle = image->paused_handle;
            image->paused_handle = GDI_ERROR_HANDLE;
            image->pause_frame = GUI_IMAGE_ANIM_RESUME_DISABLE;

            gdi_layer_pop_clip();
            if (image->target_layer != GDI_NULL_HANDLE)
            {
                gdi_layer_pop_and_restore_active();
            }
            gdi_layer_unlock_frame_buffer();
            return result;
        }
        else
        {
            result = gdi_anim_stop(image->paused_handle);
            MMI_DBG_ASSERT(result == GDI_SUCCEED);
            image->paused_handle = GDI_ERROR_HANDLE;
            if (image->image_type == GDI_IMAGE_TYPE_GIF_FILE ||
                image->image_type == GDI_IMAGE_TYPE_GIF)
            {
                if (image->flags & GUI_IMAGE_FILL_WHITE_BACKGROUND)
                {
                    gdi_draw_solid_rect(
                        image->x,
                        image->y,
                        image->x + image->width - 1,
                        image->y + image->height - 1,
                        GDI_COLOR_WHITE);
                }
                else
                {
                    image->hide_callback(
                        image->x,
                        image->y,
                        image->x + image->width - 1,
                        image->y + image->height - 1);
                }
                image->pause_frame = 0;
            }
        }
    }

    if (image->flags & GUI_IMAGE_FILL_WHITE_BACKGROUND)
    {
        abm_layer = gdi_set_alpha_blending_source_layer(image->target_layer);
    }

    result = gui_image_show_ex(image, image->pause_frame);

    if (image->flags & GUI_IMAGE_FILL_WHITE_BACKGROUND &&
        abm_layer != GDI_NULL_HANDLE)
    {
        gdi_set_alpha_blending_source_layer(abm_layer);
    }
    
    image->pause_frame = GUI_IMAGE_ANIM_RESUME_DISABLE;

    gdi_layer_pop_clip();
    if (image->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }
    gdi_layer_unlock_frame_buffer();
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  gui_image_set_image_from_file
 * DESCRIPTION
 *  the function used to set image of component
 * PARAMETERS
 *  image           [IN]    pointer of image component
 *  file_name       [IN]    name of image file
 * RETURNS
 *  GDI_RESULT        [OUT]   set success or fail
 *****************************************************************************/
GDI_RESULT gui_image_set_image_from_file(
            gui_image_struct *image,
            const PU8 file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image != NULL);
    MMI_DBG_ASSERT(image->active == MMI_TRUE);
    return gui_image_set_image(
               image,
               GDI_IMAGE_TYPE_INVALID,
               file_name,
               GDI_IMAGE_SRC_FROM_FILE);    
}


/*****************************************************************************
 * FUNCTION
 *  gui_image_set_image_from_res
 * DESCRIPTION
 *  the function used to set image of component
 * PARAMETERS
 *  image           [IN]    pointer of image component
 *  image_res       [IN]    buffer of image resource
 * RETURNS
 *  GDI_RESULT      [OUT]   set success or fail
 *****************************************************************************/
GDI_RESULT gui_image_set_image_from_res(
            gui_image_struct *image,
            const PU8 image_res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image != NULL);
    MMI_DBG_ASSERT(image->active == MMI_TRUE);
    return gui_image_set_image(
               image,
               GDI_IMAGE_TYPE_INVALID,
               image_res,
               GDI_IMAGE_SRC_FROM_RESOURCE);    
}


/*****************************************************************************
 * FUNCTION
 *  gui_image_set_image_from_mem
 * DESCRIPTION
 *  the function used to set image of component
 * PARAMETERS
 *  image           [IN]    pointer of image component
 *  image_res       [IN]    buffer of image raw data
 * RETURNS
 *  GDI_RESULT      [OUT]   set success or fail
 *****************************************************************************/
GDI_RESULT gui_image_set_image_from_mem(
            gui_image_struct *image,
            U32 image_type,
            const PU8 image_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image != NULL);
    MMI_DBG_ASSERT(image->active == MMI_TRUE);
    return gui_image_set_image(
               image,
               (U16)image_type,
               image_data,
               GDI_IMAGE_SRC_FROM_MEMORY);    
}


/*****************************************************************************
 * FUNCTION
 *  gui_image_register_hide_function
 * DESCRIPTION
 *  the function used to register hide func of image component
 * PARAMETERS
 *  image           [IN]    pointer of image component
 *  f               [IN]    New hide callback function
 * RETURNS
 *  void
 *****************************************************************************/
void gui_image_register_hide_function(
      gui_image_struct *image,
      void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image != NULL);
    MMI_DBG_ASSERT(image->active == MMI_TRUE);
    image->hide_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  gui_image_set_layer
 * DESCRIPTION
 *  the function used to set layer of image component
 *  Remark: Because GDI will remember the layer that image is showing, you 
 *          had better not to set layer when an anim is play or show an image
 *          in non blocking, or it may cause some error.
 * PARAMETERS
 *  image           [IN]    pointer of image component
 *  target_layer    [IN]    target_layer
 * RETURNS
 *  void
 *****************************************************************************/
void gui_image_set_layer(gui_image_struct *image, gdi_handle target_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image != NULL);
    MMI_DBG_ASSERT(image->active == MMI_TRUE);
    if (image->paused_handle != GDI_ERROR_HANDLE && 
        image->target_layer != target_layer)
    {
        gui_image_anim_stop_pause_state(image);
    }
    image->target_layer = target_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_image_set_anim_start_frame
 * DESCRIPTION
 *  the function used to set start frame of image component
 *  Remark:
 *      It is better not to set start frame when image is a GIF, or it may
 *      seem strange in displaying.
 *      It also not be apply to non blocking show.
 * PARAMETERS
 *  image           [IN]    pointer of image component
 *  start_frame     [IN]    start frame of animation
 * RETURNS
 *  void
 *****************************************************************************/
void gui_image_set_anim_start_frame(gui_image_struct *image, U32 start_frame)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image != NULL);
    MMI_DBG_ASSERT(image->active == MMI_TRUE);
    /* can not set start frame of GIF */
    if (image->image_type == GDI_IMAGE_TYPE_GIF_FILE ||
        image->image_type == GDI_IMAGE_TYPE_GIF)
    {
        return;
    }
    image->start_frame = start_frame;
}


/*****************************************************************************
 * FUNCTION
 *  gui_image_set_stretch_enable
 * DESCRIPTION
 *  the function used to set whehter enable stretch of image component
 * PARAMETERS
 *  image           [IN]    pointer of image component
 *  enable_stretch  [IN]    whether enable stretch or not
 * RETURNS
 *  void
 *****************************************************************************/
void gui_image_set_stretch_enable(gui_image_struct *image, MMI_BOOL enable_stretch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image != NULL);
    MMI_DBG_ASSERT(image->active == MMI_TRUE);
    if (image->paused_handle != GDI_ERROR_HANDLE && 
        image->enable_stretch != enable_stretch)
    {
        gui_image_anim_stop_pause_state(image);
    }
    image->enable_stretch = enable_stretch;
    gui_image_adjust_image(image);
}


/*****************************************************************************
 * FUNCTION
 *  gui_image_set_align
 * DESCRIPTION
 *  the function used to set align of image component
 * PARAMETERS
 *  image               [IN]    pointer of image component
 *  image_h_align_type  [IN]    horizontal align type
 *  image_v_align_type  [IN]    vertical align type
 * RETURNS
 *  void
 *****************************************************************************/
void gui_image_set_align(
      gui_image_struct *image,
      gui_image_align_enum image_h_align_type,
      gui_image_align_enum image_v_align_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image != NULL);
    MMI_DBG_ASSERT(image->active == MMI_TRUE);
    if (image->paused_handle != GDI_ERROR_HANDLE &&
        (image->image_h_align_type != image_h_align_type ||
         image->image_v_align_type != image_v_align_type))
    {
        gui_image_anim_stop_pause_state(image);
    }
    image->image_h_align_type = image_h_align_type;
    image->image_v_align_type = image_v_align_type;
    gui_image_adjust_image(image);
}


/*****************************************************************************
 * FUNCTION
 *  gui_image_get_layer
 * DESCRIPTION
 *  the function used to get target of image component
 * PARAMETERS
 *  image               [IN]    pointer of image component
 *  target_layer        [IN]    pointer of target layer
 * RETURNS
 *  void
 *****************************************************************************/
void gui_image_get_layer(gui_image_struct *image, gdi_handle *target_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image != NULL);
    MMI_DBG_ASSERT(image->active == MMI_TRUE);
    *target_layer = image->target_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_image_get_position
 * DESCRIPTION
 *  the function used to get positon of image
 * PARAMETERS
 *  image               [IN]    pointer of image component
 *  x                   [IN]
 *  y                   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_image_get_position(gui_image_struct *image, S32 *x, S32 *y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image != NULL);
    MMI_DBG_ASSERT(image->active == MMI_TRUE);
    *x = image->x + image->image_display_x;
    *y = image->y + image->image_display_y;
}


/*****************************************************************************
 * FUNCTION
 *  gui_image_get_dimension
 * DESCRIPTION
 *  the function used to get dimension of image, not image component
 * PARAMETERS
 *  image               [IN]    pointer of image component
 *  width               [IN]    image's width
 *  height              [IN]    image's height
 *  display_width       [IN]    image's display width
 *  display_height      [IN]    image's dispaly height
 * RETURNS
 *  void
 *****************************************************************************/
void gui_image_get_dimension(
      gui_image_struct *image,
      S32 *width,
      S32 *height,
      S32 *display_width,
      S32 *display_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image != NULL);
    MMI_DBG_ASSERT(image->active == MMI_TRUE);
    *width = image->image_width;
    *height = image->image_height;
    *display_width = image->image_display_width;
    *display_height = image->image_display_height;
}


/*****************************************************************************
 * FUNCTION
 *  gui_image_get_start_frame
 * DESCRIPTION
 *  the function used to get start frame of image component
 * PARAMETERS
 *  image               [IN]    pointer of image component
 *  start_frame         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_image_get_anim_start_frame(gui_image_struct *image, U32 *start_frame)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image != NULL);
    MMI_DBG_ASSERT(image->active == MMI_TRUE);
    *start_frame = image->start_frame;
}

/*****************************************************************************
 * FUNCTION
 *  gui_image_show_nb
 * DESCRIPTION
 *  the function used to show an image component of non_blocking
 * PARAMETERS
 *  image                       [IN]    pointer of image component
 *  decode_done_callback        [IN]    decode result callback function
 * RETURNS
 *  GDI_RESULT      [OUT]   result of show
 *****************************************************************************/
GDI_RESULT gui_image_show_nb(
            gui_image_struct *image,
            void (*decode_done_callback)(GDI_RESULT result, GDI_HANDLE handle))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT result;
    GDI_HANDLE abm_layer = GDI_NULL_HANDLE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image != NULL);
    MMI_DBG_ASSERT(image->active == MMI_TRUE);

    /* if anim is playing */
    if (image->image_handle != GDI_ERROR_HANDLE)
    {
        if (image->is_non_blocking == MMI_TRUE)
        {
            result = gdi_anim_nb_stop(image->image_handle);
        }
        else
        {
            result = gdi_anim_stop(image->image_handle);
        }

        MMI_DBG_ASSERT(result == GDI_SUCCEED);
        image->image_handle = GDI_ERROR_HANDLE;
    }
    else /* maybe init or pause state */
    {
        /* if show is called after anim pause */
        if (image->paused_handle != GDI_ERROR_HANDLE)
        {
            result = gdi_anim_stop(image->paused_handle);
            MMI_DBG_ASSERT(result == GDI_SUCCEED);
            image->paused_handle = GDI_ERROR_HANDLE;
        }
        if (image->anim_layer_ptr != NULL &&
            image->anim_layer_handle != GDI_NULL_HANDLE)
        {
            /* free pause layer and buffer, show anim from start frame */
            gdi_layer_free(image->anim_layer_handle);
            mmi_frm_scrmem_free(image->anim_layer_ptr);
            image->anim_layer_handle = GDI_NULL_HANDLE;
            image->anim_layer_ptr = NULL;
            image->pause_frame = GUI_IMAGE_ANIM_RESUME_DISABLE;
        }
    }

    gdi_layer_lock_frame_buffer();
    if (image->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_push_and_set_active(image->target_layer);
    }
    gdi_layer_push_clip();
    gdi_layer_set_clip(
        image->x,
        image->y,
        image->x + image->width - 1,
        image->y + image->height - 1);

    /* draw background */
    if (image->flags & GUI_IMAGE_FILL_WHITE_BACKGROUND)
    {
        gdi_draw_solid_rect(
            image->x,
            image->y,
            image->x + image->width - 1,
            image->y + image->height - 1,
            GDI_COLOR_WHITE);
        abm_layer = gdi_set_alpha_blending_source_layer(image->target_layer);
    }
    else
    {
        image->hide_callback(
            image->x,
            image->y,
            image->x + image->width - 1,
            image->y + image->height - 1);
    }

    gdi_layer_pop_clip();

    gdi_layer_push_clip();
    gdi_layer_set_clip(
        image->x + image->image_display_x,
        image->y + image->image_display_y,
        image->x + image->image_display_x + image->image_display_width - 1,
        image->y + image->image_display_y + image->image_display_height - 1);

    gdi_image_clear_work_buffer();

    /* set non blocking parameters */
    gdi_nb_set_blt(TRUE, FALSE);
    gdi_nb_set_done_callback(decode_done_callback);
    /* wgui_status_icon_lock_redrawing(); */

    if (image->image_scr == GDI_IMAGE_SRC_FROM_FILE)
    {
        if (image->image_type == GDI_IMAGE_TYPE_GIF_FILE)
        {
            /* reset image cache, only gif need this operation */
            gdi_image_cache_reset();                    
        }
        /* is animation */
        if (image->frame_count > 1)
        {                
            image->image_handle = gdi_anim_nb_draw_resized_file(
                                      image->x + image->image_display_x,
                                      image->y + image->image_display_y,
                                      image->image_display_width,
                                      image->image_display_height,
                                      image->image_buffer);
        }
        else
        {
            image->image_handle = gdi_image_nb_draw_resized_file(
                                      image->x + image->image_display_x,
                                      image->y + image->image_display_y,
                                      image->image_display_width,
                                      image->image_display_height,
                                      image->image_buffer);
        }
    }
    else if (image->image_scr == GDI_IMAGE_SRC_FROM_MEMORY)
    {
        if (image->image_type == GDI_IMAGE_TYPE_GIF)
        {
            /* reset image cache, only gif need this operation */
            gdi_image_cache_reset();            
        }
        if (image->image_type == GDI_IMAGE_TYPE_GIF ||
            image->image_type == GDI_IMAGE_TYPE_AVATAR ||
            image->image_type == GDI_IMAGE_TYPE_M3D)
        {
            image->image_handle = gdi_anim_nb_draw_resized_mem(
                                      image->x + image->image_display_x,
                                      image->y + image->image_display_y,
                                      image->image_display_width,
                                      image->image_display_height,
                                      (PU8)image->image_buffer,
                                      (U8)image->image_type,
                                      0);
        }
        else
        {
            image->image_handle = gdi_image_nb_draw_resized_mem(
                                      image->x + image->image_display_x,
                                      image->y + image->image_display_y,
                                      image->image_display_width,
                                      image->image_display_height,
                                      image->image_buffer,
                                      (U8)image->image_type,
                                      0);
        }
    }
    else if (image->image_scr == GDI_IMAGE_SRC_FROM_RESOURCE)
    {
        if (image->image_type == GDI_IMAGE_TYPE_GIF ||
            image->image_type == GDI_IMAGE_TYPE_GIF_FILE)
        {
            /* reset image cache, only gif need this operation */
            gdi_image_cache_reset();                    
        }
        /* is animation */
        if (image->frame_count > 1)
        {                
            image->image_handle = gdi_anim_nb_draw_resized(
                                      image->x + image->image_display_x,
                                      image->y + image->image_display_y,
                                      image->image_display_width,
                                      image->image_display_height,
                                      image->image_buffer);
        }
        else
        {
            image->image_handle = gdi_image_nb_draw_resized(
                                      image->x + image->image_display_x,
                                      image->y + image->image_display_y,
                                      image->image_display_width,
                                      image->image_display_height,
                                      image->image_buffer);
        }
    }
    result = GDI_SUCCEED;
    if (image->flags & GUI_IMAGE_FILL_WHITE_BACKGROUND && abm_layer != GDI_NULL_HANDLE)
    {
        gdi_set_alpha_blending_source_layer(abm_layer);
    }

    image->is_non_blocking = MMI_TRUE;

    gdi_layer_pop_clip();
    if (image->target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }
    gdi_layer_unlock_frame_buffer();

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  gui_image_stop_nb_show
 *  the function used to stop an image component of non_blocking
 * PARAMETERS
 *  image                       [IN]    pointer of image component
 * RETURNS
 *  GDI_RESULT                  [OUT]   result of stop show
 *****************************************************************************/
GDI_RESULT gui_image_stop_nb_show(gui_image_struct *image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image != NULL);
    MMI_DBG_ASSERT(image->active == MMI_TRUE);
    MMI_DBG_ASSERT(image->is_non_blocking == MMI_TRUE);
    result = gdi_anim_nb_stop(image->image_handle);
    image->is_non_blocking = MMI_FALSE;
    return result;
}


