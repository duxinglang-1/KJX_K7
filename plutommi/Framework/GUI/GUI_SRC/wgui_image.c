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
 *  wgui_image.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_release.h"
#include "MMI_trc_Int.h"
/*****************************************************************************
 * include
 ****************************************************************************/
/* Write your #include header file here */
#include "gui_image.h"
#include "wgui_image.h"

/*****************************************************************************
 * Static Declaration
 ****************************************************************************/
/* Define your local variable here */
/* Local variable are those variable only be used within this .c file. */

/* wgui_image_list includes WGUI_IMAGE_MAX_ANIMATION_COUNT's animated image 
 * components in the fore part, and followed WGUI_IMAGE_MAX_STILL_COUNT's 
 * still image components
 */
static gui_image_struct wgui_image_list[WGUI_IMAGE_MAX_COUNT];
static U32 wgui_image_count = 0;
/* Declare your local function here */
static void wgui_image_get_available_index(U32 *index);

/*****************************************************************************
 * Global Variable
 ****************************************************************************/
/* Write your global variable here */


/*****************************************************************************
 * Local Function
 ****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  wgui_image_get_available_index
 * DESCRIPTION
 *  the function used to get the index of the available image component
 * PARAMETERS
 *  index   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_image_get_available_index(U32 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* when meet the first available index, return */
    for (i = 0 ; i < WGUI_IMAGE_MAX_COUNT; i++)
    {
        if (wgui_image_list[i].active == MMI_FALSE)
        {
            *index = i;
            return;
        }
    }
}


/*****************************************************************************
 * Global Function
 ****************************************************************************/
/* Write your global function here */
/*****************************************************************************
 * FUNCTION
 *  wgui_image_create_from_file
 * DESCRIPTION
 *  Create API of image component, , which create image from image file.
 *  It will return valid image_index if success.
 *  The API will return GDI_RESULT.
 * PARAMETERS
 *  image_index [IN/OUT]  index of image component, returned by wgui_image_create
 *  x           [IN]      x position of image component
 *  y           [IN]      y position of image component
 *  width       [IN]      width of image component
 *  height      [IN]      height of image component
 *  file_name   [IN]      name of image file
 *  flags       [IN]      flags
 *  target_layer[IN]      
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT wgui_image_create_from_file(
            S32 *image_index,
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
    GDI_RESULT result = GDI_FAILED;
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_image_count >= WGUI_IMAGE_MAX_COUNT)
    {
        *image_index = WGUI_IMAGE_CREATE_NO_AVAILABLE_INDEX;
        return result;
    }

    wgui_image_get_available_index(&index);
    MMI_DBG_ASSERT(index < WGUI_IMAGE_MAX_COUNT);
    result = gui_image_create_from_file(
                 &wgui_image_list[index],
                 x,
                 y,
                 width,
                 height,
                 file_name,
                 flags,
                 target_layer);

    if (result == GDI_SUCCEED)
    {
        *image_index = (S32)index;
        wgui_image_count++;
    }
    else
    {
        *image_index = WGUI_IMAGE_CREATE_GDI_FAIL;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_image_create_from_res
 * DESCRIPTION
 *  Create API of image component, which create image from resource.
 *  It will return valid image_index if success.
 *  The API will return GDI_RESULT.
 * PARAMETERS
 *  image_index [IN/OUT]  index of image component, returned by wgui_image_create
 *  x           [IN]      x position of image component
 *  y           [IN]      y position of image component
 *  width       [IN]      width of image component
 *  height      [IN]      height of image component
 *  image_res   [IN]      buffer of image resource
 *  flags       [IN]      flags
 *  target_layer[IN]      
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT wgui_image_create_from_res(
            S32 *image_index,
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
    GDI_RESULT result = GDI_FAILED;
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_image_count >= WGUI_IMAGE_MAX_COUNT)
    {
        *image_index = WGUI_IMAGE_CREATE_NO_AVAILABLE_INDEX;
        return result;
    }

    wgui_image_get_available_index(&index);
    MMI_DBG_ASSERT(index < WGUI_IMAGE_MAX_COUNT);
    result = gui_image_create_from_res(
                 &wgui_image_list[index],
                 x,
                 y,
                 width,
                 height,
                 image_res,
                 flags,
                 target_layer);

    if (result == GDI_SUCCEED)
    {
        *image_index = (S32)index;
        wgui_image_count++;
    }
    else
    {
        *image_index = WGUI_IMAGE_CREATE_GDI_FAIL;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_image_create_from_mem
 * DESCRIPTION
 *  Create API of image component, it will return valid image_index if success.
 *  The API will return GDI_RESULT.
 *  REMARK: gdi_image_type can be avatar, BMP, GIF, JPG, PNG, etc.
 *  Avatar can only use this API to create image component.
 *  If user use GDI_IMAGE_TYPE_INVALID in image_type, we will decode image type
 *  at first. But if use valid image type, we will just use this given type.
 * PARAMETERS
 *  image_index [IN/OUT]  index of image component, returned by wgui_image_create
 *  x           [IN]      x position of image component
 *  y           [IN]      y position of image component
 *  width       [IN]      width of image component
 *  height      [IN]      height of image component
 *  image_type  [IN]      gdi image type of image
 *  image_data  [IN]      buffer of image raw data
 *  flags       [IN]      flags
 *  target_layer[IN]      
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT wgui_image_create_from_mem(
            S32 *image_index,
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
    GDI_RESULT result = GDI_FAILED;
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_image_count >= WGUI_IMAGE_MAX_COUNT)
    {
        *image_index = WGUI_IMAGE_CREATE_NO_AVAILABLE_INDEX;
        return result;
    }

    wgui_image_get_available_index(&index);
    MMI_DBG_ASSERT(index < WGUI_IMAGE_MAX_COUNT);
    result = gui_image_create_from_mem(
                 &wgui_image_list[index],
                 x,
                 y,
                 width,
                 height,
                 image_type,
                 image_data,
                 flags,
                 target_layer);
    
    if (result == GDI_SUCCEED)
    {
        *image_index = (S32)index;
        wgui_image_count++;
    }
    else
    {
        *image_index = WGUI_IMAGE_CREATE_GDI_FAIL;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_image_close
 * DESCRIPTION
 *  the function used to close image component
 * PARAMETERS
 *  image_index     [IN]   index of image component
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_image_close(S32 image_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image_index >= 0 && image_index < WGUI_IMAGE_MAX_COUNT);
    if (wgui_image_list[image_index].active == MMI_FALSE)
    {
        return;
    }
    gui_image_close(&wgui_image_list[image_index]);
    wgui_image_count--;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_image_close_all
 * DESCRIPTION
 *  the function used to close all image components
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_image_close_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_image_count == 0)
    {
        return;
    }
    for (i = 0; i < WGUI_IMAGE_MAX_COUNT; i++)
    {
        if (wgui_image_list[i].active == MMI_FALSE)
        {
            continue;
        }
        gui_image_close(&wgui_image_list[i]);
    }
    wgui_image_count = 0;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_image_move
 * DESCRIPTION
 *  the function used to move an image component
 * PARAMETERS
 *  image_index     [IN]    index of image component
 *  x               [IN]
 *  y               [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_image_move(S32 image_index, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image_index >= 0 && image_index < WGUI_IMAGE_MAX_COUNT);
    gui_image_move(&wgui_image_list[image_index], x, y);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_image_resize
 * DESCRIPTION
 *  the function used to resize an image component
 * PARAMETERS
 *  image_index     [IN]    index of image component
 *  width           [IN]
 *  height          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_image_resize(S32 image_index, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image_index >= 0 && image_index < WGUI_IMAGE_MAX_COUNT);
    gui_image_resize(&wgui_image_list[image_index], width, height);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_image_show
 * DESCRIPTION
 *  the function used to show an image component
 * PARAMETERS
 *  image_index     [IN]    index of image component
 * RETURNS
 *  GDI_RESULT      [OUT]   result of show
 *****************************************************************************/
GDI_RESULT wgui_image_show(S32 image_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image_index >= 0 && image_index < WGUI_IMAGE_MAX_COUNT);
    result = gui_image_show(&wgui_image_list[image_index]);
    gdi_layer_blt_previous(
        wgui_image_list[image_index].x,
        wgui_image_list[image_index].y,
        wgui_image_list[image_index].x + wgui_image_list[image_index].width - 1,
        wgui_image_list[image_index].y + wgui_image_list[image_index].height - 1);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_image_pause
 * DESCRIPTION
 *  the function used to pause the display of animated image component
 * PARAMETERS
 *  image_index     [IN]    index of image component
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_image_pause(S32 image_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image_index >= 0 && image_index < WGUI_IMAGE_MAX_COUNT);
    MMI_DBG_ASSERT(wgui_image_list[image_index].active == MMI_TRUE);
    gui_image_pause(&wgui_image_list[image_index]);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_image_resume
 * DESCRIPTION
 *  the function used to resume the display of animated image component
 * PARAMETERS
 *  image_index     [IN]    index of image component
 * RETURNS
 *  GDI_RESULT      [OUT]   result of resume
 *****************************************************************************/
GDI_RESULT wgui_image_resume(S32 image_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image_index >= 0 && image_index < WGUI_IMAGE_MAX_COUNT);
    result = gui_image_resume(&wgui_image_list[image_index]);
    if (result == GDI_SUCCEED)
    {
        gdi_layer_blt_previous(
            wgui_image_list[image_index].x,
            wgui_image_list[image_index].y,
            wgui_image_list[image_index].x + wgui_image_list[image_index].width - 1,
            wgui_image_list[image_index].y + wgui_image_list[image_index].height - 1);
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_image_set_image_from_file
 * DESCRIPTION
 *  the function used to set image of component
 * PARAMETERS
 *  image_index     [IN]    index of image component
 *  file_name       [IN]    name of image file
 * RETURNS
 *  GDI_RESULT      [OUT]   set success or fail
 *****************************************************************************/
GDI_RESULT wgui_image_set_image_from_file(
            S32 image_index,
            const PU8 file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image_index >= 0 && image_index < WGUI_IMAGE_MAX_COUNT);
    MMI_DBG_ASSERT(file_name != NULL);
    return gui_image_set_image_from_file(
               &wgui_image_list[image_index],
               file_name);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_image_set_image_from_res
 * DESCRIPTION
 *  the function used to set image of component
 * PARAMETERS
 *  image_index     [IN]    index of image component
 *  image_res       [IN]    buffer of image resource
 * RETURNS
 *  GDI_RESULT      [OUT]   set success or fail
 *****************************************************************************/
GDI_RESULT wgui_image_set_image_from_res(
            S32 image_index,
            const PU8 image_res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image_index >= 0 && image_index < WGUI_IMAGE_MAX_COUNT);
    MMI_DBG_ASSERT(image_res != NULL);
    return gui_image_set_image_from_res(
               &wgui_image_list[image_index],
               image_res);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_image_set_image_from_mem
 * DESCRIPTION
 *  the function used to set image of component
 * PARAMETERS
 *  image_index     [IN]    index of image component
 *  image_res       [IN]    buffer of image resource
 * RETURNS
 *  GDI_RESULT      [OUT]   set success or fail
 *****************************************************************************/
GDI_RESULT wgui_image_set_image_from_mem(
            S32 image_index,
            U32 image_type,
            const PU8 image_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image_index >= 0 && image_index < WGUI_IMAGE_MAX_COUNT);
    MMI_DBG_ASSERT(image_data != NULL);
    return gui_image_set_image_from_mem(
               &wgui_image_list[image_index],
               image_type,
               image_data);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_image_register_hide_function
 * DESCRIPTION
 *  the function used to set background of image component
 * PARAMETERS
 *  image_index     [IN]    index of image component
 *  f               [IN]    hide func
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_image_register_hide_function(
      S32 image_index,
      void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image_index >= 0 && image_index < WGUI_IMAGE_MAX_COUNT);
    gui_image_register_hide_function(&wgui_image_list[image_index], f);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_image_set_layer
 * DESCRIPTION
 *  the function used to set layer of image component
 * PARAMETERS
 *  image_index     [IN]    index of image component
 *  target_layer    [IN]    target_layer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_image_set_layer(S32 image_index, gdi_handle target_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image_index >= 0 && image_index < WGUI_IMAGE_MAX_COUNT);
    gui_image_set_layer(&wgui_image_list[image_index], target_layer);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_image_set_anim_start_frame
 * DESCRIPTION
 *  the function used to set start frame of image component
 * PARAMETERS
 *  image_index     [IN]    index of image component
 *  start_frame     [IN]    start frame of animation
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_image_set_anim_start_frame(S32 image_index, U32 start_frame)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image_index >= 0 && image_index < WGUI_IMAGE_MAX_COUNT);
    gui_image_set_layer(&wgui_image_list[image_index], start_frame);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_image_set_stretch_enable
 * DESCRIPTION
 *  the function used to set whehter enable stretch of image component
 *  if enable stretch, the image will fill the whole component
 *  if disable stretch, the image will fill component in scale
 * PARAMETERS
 *  image_index     [IN]    index of image component
 *  enable_stretch  [IN]    whether enable stretch or not
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_image_set_stretch_enable(S32 image_index, MMI_BOOL enable_stretch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image_index >= 0 && image_index < WGUI_IMAGE_MAX_COUNT);
    gui_image_set_stretch_enable(&wgui_image_list[image_index], enable_stretch);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_image_set_align
 * DESCRIPTION
 *  the function used to set align of image component
 * PARAMETERS
 *  image_index         [IN]    index of image component
 *  image_h_align_type  [IN]    horizontal align type
 *  image_v_align_type  [IN]    vertical align type
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_image_set_align(
      S32 image_index, 
      gui_image_align_enum image_h_align_type,
      gui_image_align_enum image_v_align_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image_index >= 0 && image_index < WGUI_IMAGE_MAX_COUNT);
    gui_image_set_align(
        &wgui_image_list[image_index], 
        image_h_align_type,
        image_v_align_type);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_image_get_layer
 * DESCRIPTION
 *  the function used to get target of image component
 * PARAMETERS
 *  image_index         [IN]    index of image component
 *  target_layer        [IN]    pointer of target layer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_image_get_layer(S32 image_index, gdi_handle *target_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image_index >= 0 && image_index < WGUI_IMAGE_MAX_COUNT);
    gui_image_get_layer(&wgui_image_list[image_index], target_layer);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_image_get_position
 * DESCRIPTION
 *  the function used to get positon of image component
 * PARAMETERS
 *  image_index         [IN]    index of image component
 *  x                   [IN]
 *  y                   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_image_get_position(S32 image_index, S32 *x, S32 *y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image_index >= 0 && image_index < WGUI_IMAGE_MAX_COUNT);
    gui_image_get_position(&wgui_image_list[image_index], x, y);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_image_get_dimension
 * DESCRIPTION
 *  the function used to get dimension of image, not image component
 * PARAMETERS
 *  image_index         [IN]    index of image component
 *  width               [IN]    image's width
 *  height              [IN]    image's height
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_image_get_dimension(
      S32 image_index,
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
    MMI_DBG_ASSERT(image_index >= 0 && image_index < WGUI_IMAGE_MAX_COUNT);
    gui_image_get_dimension(
        &wgui_image_list[image_index],
        width,
        height,
        display_width,
        display_height);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_image_get_start_frame
 * DESCRIPTION
 *  the function used to get start frame of image component
 * PARAMETERS
 *  image_index         [IN]    index of image component
 *  start_frame         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_image_get_anim_start_frame(S32 image_index, U32 *start_frame)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image_index >= 0 && image_index < WGUI_IMAGE_MAX_COUNT);
    gui_image_get_anim_start_frame(&wgui_image_list[image_index], start_frame);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_image_show_nb
 * DESCRIPTION
 *  the function used to show an image component of non blocking
 * PARAMETERS
 *  image_index                 [IN]    index of image component
 *  decode_done_callback        [IN]    decode result callback function
 * RETURNS
 *  GDI_RESULT      [OUT]   result of show
 *****************************************************************************/
GDI_RESULT wgui_image_show_nb(
            S32 image_index,
            void (*decode_done_callback)(GDI_RESULT result, GDI_HANDLE handle))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image_index >= 0 && image_index < WGUI_IMAGE_MAX_COUNT);
    result = gui_image_show_nb(
                 &wgui_image_list[image_index],
                 decode_done_callback);
    gdi_layer_blt_previous(
        wgui_image_list[image_index].x,
        wgui_image_list[image_index].y,
        wgui_image_list[image_index].x + wgui_image_list[image_index].width - 1,
        wgui_image_list[image_index].y + wgui_image_list[image_index].height - 1);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_image_stop_nb_show
 * DESCRIPTION
 *  the function used to stop an image component of non_blocking
 * PARAMETERS
 *  image_index         [IN]    index of image component
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT wgui_image_stop_nb_show(S32 image_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(image_index >= 0 && image_index < WGUI_IMAGE_MAX_COUNT);
    return gui_image_stop_nb_show(&wgui_image_list[image_index]);
}


