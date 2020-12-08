/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  gdi_image_alpha_bmp_v2.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMIDataType.h"
#include "kal_public_defs.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "CustDataRes.h"
#include "app_str.h"

#include "gdi_image_alpha_bmp_v2.h"
#include "gdi_image_alpha_bmp_v2_internal.h"
#include "gdi_mutex.h"
#include "gdi_include.h"
#include "gdi_image_gif.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gdi_primitive.h"
#include "gdi_image.h"
#include "gdi_features.h"
#include "gdi_layer.h"
#include "gdi_internal.h"

#include "gd_primitive_arm.h"


/* media memory alloc/free for drawing ABM from files */
#include "med_utility.h"

#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "med_smalloc.h"

/* for switch stack to internal RAM */
#if defined(__MTK_TARGET__)
#define AB2_ENABLE_SWITCH_INT_STACK
#endif

#ifdef AB2_ENABLE_SWITCH_INT_STACK
#include "drv_gfx_stack_switch_manager.h" 
extern kal_uint32 INT_SwitchStackToRun(void *stack_start, kal_uint32 stack_size, kal_func_ptr func, kal_uint32 argc, ...);
extern gdi_image_ab2_decode_mode_enum gdi_image_ab2_get_final_decode_mode(gdi_handle dst_layer,gdi_image_ab2_info_struct* ab2_img_info,gdi_image_ab2_decode_mode_enum decode_mode);

#endif /* AB2_ENABLE_SWITCH_INT_STACK */
#if defined(__MTK_TARGET__) && defined(__VENUS_SWLA_DBG_ON__)
#define __MAUI_SOFTWARE_LA__
#endif

#ifdef __MAUI_SOFTWARE_LA__
#include "SST_sla.h"
#endif

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
/* AB2 decoder mutex */
static gdi_mutex_struct g_gdi_image_ab2_mutex;


/***************************************************************************** 
 * Local Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_draw_with_stack
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
GDI_RESULT gdi_image_ab2_draw_with_stack(
    gdi_handle dst_layer,
    S32 dst_layer_x, 
    S32 dst_layer_y, 
    gdi_handle src_layer,
    const U8 *data_ptr,
    gdi_image_ab2_decode_mode_enum decode_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_SUCCEED;
#ifdef AB2_ENABLE_SWITCH_INT_STACK
    void *stk_ptr;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef AB2_ENABLE_SWITCH_INT_STACK
    /* Switch stack to internal RAM */
    stk_ptr = drv_gfx_stkmgr_get_stack(BMP_STACK_SIZE);
    if (stk_ptr)
    {
        ret = INT_SwitchStackToRun(
            stk_ptr, 
            BMP_STACK_SIZE,
            (kal_func_ptr)gdi_image_ab2_draw_internal, 
            6, 
            dst_layer,
            dst_layer_x, 
            dst_layer_y, 
            src_layer,
            data_ptr,
            decode_mode);
        drv_gfx_stkmgr_release_stack(stk_ptr);   
    }
    else
#endif /* defined(__MTK_TARGET__) */
    {
        ret = gdi_image_ab2_draw_internal(
            dst_layer,
            dst_layer_x, 
            dst_layer_y, 
            src_layer,
            data_ptr,
            decode_mode);
    }

    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_is_ab2_file
 * DESCRIPTION
 *  Check if the file is belong to ab2 image
 * PARAMETERS
 *  file_name       [IN]     
 * RETURNS
 *  GDI_SUCCEED if it's an ab2 image, otherwise GDI_FAILED
 *  + GDI_SUCCEED      
 *****************************************************************************/
GDI_RESULT gdi_image_is_ab2_file(U8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_SUCCEED;
    WCHAR *filepath = (WCHAR*)file_name;
    kal_int32 filepath_len;
    FS_HANDLE   fh;
    U32         read_len;
    U8          buf[GDI_IMAGE_AB2_HEADER_SIZE];
    gdi_image_ab2_info_struct header;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(file_name != NULL);
    do
    {
        /* Check extension name */
        filepath_len = app_ucs2_wcslen(filepath);
        if (filepath_len > 4)
        {
            if (app_ucs2_wcsicmp(filepath + filepath_len - 4, L".ab2") != 0)
            {
                return GDI_FAILED;
            }
        }

        /* Read header to do further check */
        fh = FS_Open((U16*)file_name, FS_READ_ONLY | FS_OPEN_NO_DIR);
        if (fh < 0)
        {
            return GDI_FAILED;
        }

        /* read header */
        if (FS_Read(fh, &buf, sizeof(buf), &read_len) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return GDI_FAILED;
        }
        
        /* not enough data */    
        if (read_len != sizeof(buf))
        {
            FS_Close(fh);
            return GDI_FAILED;
        }

        FS_Close(fh);

        gdi_image_ab2_read_header(&header, buf);
		//warning Unsigned can never be smaller than 9
       /* if(header.pixel_format < GDI_IMAGE_AB2_FORMAT_RGB888_SRC_KEY || header.pixel_format > GDI_IMAGE_AB2_FORMAT_RGB565_FULLY_OPAQUE)
        {
            return GDI_FAILED;
        }*/
        if(header.algorithm != GDI_IMAGE_AB2_ALGORITHM_RLE)
        {
            return GDI_FAILED;
        }

    }while(0);
    
    ret = GDI_SUCCEED;
    return ret; //fix warning
}
 
/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_get_dimension_mem
 * DESCRIPTION
 *  get ABM v2 dimension from memory
 * PARAMETERS
 *  data_ptr       [IN]     pointer to image data  
 *  width          [OUT]    image width
 *  height         [OUT]    image height
 * RETURNS
 *  GDI_SUCCEED if successful, otherwise GDI_FAILED
 *  + GDI_SUCCEED      
 *****************************************************************************/
static GDI_RESULT gdi_image_ab2_get_dimension_mem(
    const U8 *data_ptr, 
    S32 *width, 
    S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_image_ab2_info_struct header;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(data_ptr != NULL);
    GDI_ASSERT(width != NULL);
    GDI_ASSERT(height != NULL);
    
    gdi_image_ab2_read_header(&header, data_ptr);
    *width  = header.width;
    *height = header.height;

    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_get_dimension_file
 * DESCRIPTION
 *  get ABM dimension from a file
 * PARAMETERS
 *  filename       [IN]     filename  
 *  width          [OUT]    image width
 *  height         [OUT]    image height
 * RETURNS
 *  GDI_SUCCEED if successful, otherwise GDI_FAILED
 *  + GDI_SUCCEED
 *  + GDI_FAILED
 *****************************************************************************/
static GDI_RESULT gdi_image_ab2_get_dimension_file(
    U16 *filename, 
    S32 *width, 
    S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE   fh;
    U32         read_len;
    U8          buf[GDI_IMAGE_AB2_HEADER_SIZE];
    gdi_image_ab2_info_struct header;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(filename != NULL);
    GDI_ASSERT(width != NULL);
    GDI_ASSERT(height != NULL);
    
    fh = FS_Open((U16*)filename, FS_READ_ONLY | FS_OPEN_NO_DIR);
    if (fh < 0)
    {
        return GDI_FAILED;
    }

    /* read header */
    if (FS_Read(fh, &buf, sizeof(buf), &read_len) != FS_NO_ERROR)
    {
        FS_Close(fh);
        return GDI_FAILED;
    }
    
    /* not enough data */    
    if (read_len != sizeof(buf))
    {
        FS_Close(fh);
        return GDI_FAILED;
    }

    FS_Close(fh);

    /* result */
    gdi_image_ab2_read_header(&header, buf);
    *width  = header.width;
    *height = header.height;

    return GDI_SUCCEED;    
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_draw_mem
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  GDI_SUCCEED if successful, otherwise GDI_FAILED
 *  + GDI_SUCCEED
 *****************************************************************************/
static GDI_RESULT gdi_image_ab2_draw_mem(
    S32 x,
    S32 y,
    S32 width,
    S32 height,
    const U8 *data_ptr,
    gdi_image_ab2_decode_mode_enum decode_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_FAILED;
    gdi_handle temp_layer_handle = GDI_NULL_HANDLE;
    gdi_handle dst_layer_handle, src_layer_handle;
    S32 img_width, img_height;
    U8 temp_layer_cf = GDI_COLOR_FORMAT_32_PARGB;
    MMI_BOOL always_blending = MMI_FALSE;
    MMI_BOOL resize_src_key_img_to_layer_without_alpha = MMI_FALSE;
    gdi_image_ab2_info_struct info; 
    gdi_image_ab2_decode_mode_enum final_decode_mode;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_active(&dst_layer_handle);

    gdi_image_ab2_get_dimension_mem(data_ptr, &img_width, &img_height);
    if (width == 0 && height == 0)
    {
        width = img_width;
        height = img_height;
    }

    if (width == 0 || height == 0)
    {
        /* Do nothing */
        return GDI_SUCCEED;
    }

    /* Decoder supportted */
    /* No need to resize */
    if (img_width == width && img_height == height)
    {
        gdi_get_alpha_blending_source_layer(&src_layer_handle);
        
        return gdi_image_ab2_draw_with_stack(
            dst_layer_handle,
            x, 
            y, 
            src_layer_handle,
            data_ptr,
            decode_mode);
    }

    /* Get final decode mode */
    gdi_image_ab2_read_header(&info, data_ptr);
    final_decode_mode = gdi_image_ab2_get_final_decode_mode(dst_layer_handle,&info,decode_mode);
    if((final_decode_mode == GDI_IMAGE_AB2_DECODE_MODE_SRC_KEY) && 
       (((gdi_layer_struct*)dst_layer_handle)->cf == GDI_COLOR_FORMAT_24 || ((gdi_layer_struct*)dst_layer_handle)->cf == GDI_COLOR_FORMAT_16))
    {
        resize_src_key_img_to_layer_without_alpha = MMI_TRUE;
    }

    /* General case */
    do
    {

        if (decode_mode == GDI_IMAGE_AB2_DECODE_MODE_FORCE_ALPHA)
        {
            always_blending = MMI_TRUE;
        }
        
        if (((gdi_layer_struct*)dst_layer_handle)->cf == GDI_COLOR_FORMAT_32 &&
            always_blending != MMI_TRUE)
        {
            temp_layer_cf = GDI_COLOR_FORMAT_32;
        }
        else if(resize_src_key_img_to_layer_without_alpha)
        {
            temp_layer_cf = ((gdi_layer_struct*)dst_layer_handle)->cf;
        }
        else if (((gdi_layer_struct*)dst_layer_handle)->cf == GDI_COLOR_FORMAT_PARGB6666)
        {
            temp_layer_cf = GDI_COLOR_FORMAT_PARGB6666;
        }
        else
        {
            temp_layer_cf = GDI_COLOR_FORMAT_32_PARGB;
        }
        
        gdi_image_create_temp_layer(
            &temp_layer_handle, 
            temp_layer_cf, 
            0, 
            0, 
            img_width, 
            img_height);
        if (temp_layer_handle == GDI_NULL_HANDLE)
        {
            break;
        }
        
        /* Draw to temp layer */
        if(!(resize_src_key_img_to_layer_without_alpha))
        {
        ret = gdi_image_ab2_draw_with_stack(
            temp_layer_handle,
            0, 
            0, 
            GDI_NULL_HANDLE,
            data_ptr,
            GDI_IMAGE_AB2_DECODE_MODE_OUTPUT);
        }
        else
        {
            gdi_layer_struct *temp_layer_struct = (gdi_layer_struct*)temp_layer_handle;
            gdi_lcd_layer_struct *temp_layer_info = &(gdi_layer_info[temp_layer_struct->id]);
            temp_layer_info->source_key_enable = KAL_TRUE;
            temp_layer_info->source_key = GDI_COLOR_BLUE;
            gdi_layer_push_and_set_active(temp_layer_handle);
            gdi_layer_clear(temp_layer_info->source_key);
            gdi_layer_pop_and_restore_active();
            ret = gdi_image_ab2_draw_with_stack(
                temp_layer_handle,
                0, 
                0, 
                GDI_NULL_HANDLE,
                data_ptr,
                GDI_IMAGE_AB2_DECODE_MODE_AUTO); 
        }
        if (ret != GDI_SUCCEED)
        {
            break;
        }


#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("ABE", SA_start);
#endif
        if (temp_layer_cf == GDI_COLOR_FORMAT_32)
        {
            /* Causion! Currently, temp_layer_handle will NOT blending with gdi_act_layer */
            /* Directly resize ARGB temp layer to ARGB dst layer */
            ret = gdi_bitblt_resized_with_resizer(
                    temp_layer_handle, 
                    0,
                    0,
                    img_width - 1,
                    img_height - 1,
                    x,
                    y,
                    x + width - 1,
                    y + height - 1,
                    GDI_RESIZER_SW_QUALITY_MEDIUM);
            if (ret != GDI_SUCCEED)
            {
                break;
            }
        }
        else if(resize_src_key_img_to_layer_without_alpha)
        {
             ret = gdi_bitblt_resized_with_resizer(
                    temp_layer_handle, 
                    0,
                    0,
                    img_width - 1,
                    img_height - 1,
                    x,
                    y,
                    x + width - 1,
                    y + height - 1,
                    GDI_RESIZER_SW_QUALITY_MEDIUM);
            if (ret != GDI_SUCCEED)
            {
                break;
            }
        }
        else /* temp layer color format is PARGB8888 or PARGB6666*/
        {
            /* Resize and blit */
            ret = gdi_image_resize_and_blending_ex(
                temp_layer_handle, 
                x, 
                y, 
                width, 
                height,
                always_blending);
            if (ret != GDI_SUCCEED)
            {
                break;
            }
        }
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("ABE", SA_stop);
#endif
    } while (0);

    if (temp_layer_handle != GDI_NULL_HANDLE)
    {
        gdi_image_free_temp_layer(temp_layer_handle);
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_draw_file
 * DESCRIPTION
 *  draw ABM v2 image on the current active layer from a file 
 * PARAMETERS
 *  offset_x       [IN]     x offset to draw
 *  offset_y       [IN]     y offset to draw
 *  filename       [IN]     filename
 * RETURNS
 *  GDI_SUCCEED if successful, otherwise GDI_FAILED
 *  + GDI_SUCCEED
 *****************************************************************************/
static GDI_RESULT gdi_image_ab2_draw_file(
    S32 x,
    S32 y,
    S32 width,
    S32 height,
    CHAR *filename,
    gdi_image_ab2_decode_mode_enum decode_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE   fh;
    U32         read_len;
    U32         file_size;
    U8          *buffer_ptr;
    GDI_RESULT  ret = GDI_SUCCEED;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fh = FS_Open((U16*)filename, FS_READ_ONLY | FS_OPEN_NO_DIR);
    if (fh < 0)
    {
        return GDI_IMAGE_ERR_OPEN_FILE_FAILED;
    }    

    /* check file size */
    if ((FS_GetFileSize(fh, &file_size) < 0))
    {
        FS_Close(fh);
        return GDI_IMAGE_ERR_INVALID_IMAGE_SIZE;
    }
    /* Try to get file buffer from media task memory */
    buffer_ptr = (U8*)gdi_alloc_ext_mem_cacheable(file_size);
    if (buffer_ptr == NULL)
    {
        FS_Close(fh);
        return GDI_IMAGE_ERR_MEMORY_NOT_AVAILABLE;
    }

    /* read whole file into the file buffer once (fastest and easiest) */
    if (FS_Read(fh, buffer_ptr, file_size, &read_len) < 0)
    {
        FS_Close(fh);
        return GDI_FAILED;
    }

    FS_Close(fh);

    ret = gdi_image_ab2_draw_mem(x, y, width, height, buffer_ptr, decode_mode);

    /* free the media memory if it is used */
    if (buffer_ptr != NULL)
    {
        gdi_free_ext_mem((void**)&buffer_ptr);
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_draw_blend_2_layers
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  GDI_SUCCEED if successful, otherwise GDI_FAILED
 *  + GDI_SUCCEED
 *****************************************************************************/
static GDI_RESULT gdi_image_ab2_draw_blend_2_layers(S32 x, S32 y, S32 width, S32 height, const U8 *data_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_FAILED;
    gdi_handle temp_layer_handle = GDI_NULL_HANDLE;
    gdi_handle dst_layer_handle, src_layer_handle;
    S32 img_width, img_height;
    U8  temp_layer_cf;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_active(&dst_layer_handle);
    gdi_get_alpha_blending_source_layer(&src_layer_handle);

    /* Query image dimension */
    gdi_image_ab2_get_dimension_mem(data_ptr, &img_width, &img_height);
    if (width == 0 && height == 0)
    {
        width = img_width;
        height = img_height;
    }
    
    if (width == 0 || height == 0)
    {
        /* Do nothing */
        return GDI_SUCCEED;
    }
    
    /* Copy the source layer if needed */
    if (dst_layer_handle != src_layer_handle)
    {
        gdi_layer_blend_2_layers(
            src_layer_handle, 
            x, 
            y, 
            x + width - 1, 
            y + height - 1);
        gdi_set_alpha_blending_source_layer(dst_layer_handle);
    }
    
    do
    {
        /* Decide color format of temp layer*/
        temp_layer_cf = GDI_COLOR_FORMAT_32_PARGB;
        
        /* Create a temp layer */
        gdi_image_create_temp_layer(
            &temp_layer_handle, 
            temp_layer_cf, 
            x + ((gdi_layer_struct*)dst_layer_handle)->offset_x, 
            y + ((gdi_layer_struct*)dst_layer_handle)->offset_y, 
            img_width, 
            img_height);
        if (temp_layer_handle == GDI_NULL_HANDLE)
        {
            break;
        }

        /* Draw to temp layer */
        ret = gdi_image_ab2_draw_with_stack(
            temp_layer_handle,
            0, 
            0, 
            GDI_NULL_HANDLE,
            data_ptr,
            GDI_IMAGE_AB2_DECODE_MODE_OUTPUT);
        if (ret != GDI_SUCCEED)
        {
            break;
        }

        /* Resize and blit */
        ret = gdi_image_resize_and_blending_ex(
            temp_layer_handle, 
            x, 
            y, 
            width, 
            height,
            MMI_TRUE);            
        if (ret != GDI_SUCCEED)
        {
            break;
        }
    } while (0);

    if (temp_layer_handle != GDI_NULL_HANDLE)
    {
        gdi_image_free_temp_layer(temp_layer_handle);
    }

    // Restore source layer if needed
    if (dst_layer_handle != src_layer_handle)
    {
        gdi_set_alpha_blending_source_layer(src_layer_handle);
    }
    
    return ret;
}


 
/***************************************************************************** 
 * Global Function 
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_init
 * DESCRIPTION
 *  Initialize the ABM v2 decoder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_ab2_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_mutex_init(&g_gdi_image_ab2_mutex);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_draw_handler
 * DESCRIPTION
 *  handler to draw ABM v2
 * PARAMETERS
 *  flag            [IN]    image resource flag    
 *  frame_pos       [IN]    frame number
 *  x               [IN]    x
 *  y               [IN]    y
 *  w               [IN]    width
 *  h               [IN]    height
 *  data_ptr        [IN]    pointer to image data
 *  img_size        [IN]    image size
 * RETURNS
 *  GDI_SUCCEED if successful, otherwise GDI_FAILED
 *  + GDI_SUCCEED
 *  + GDI_FAILED
 *****************************************************************************/
GDI_RESULT gdi_image_ab2_draw_handler(
    U32     flag, 
    U32     frame_pos, 
    S32     x, 
    S32     y, 
    S32     w, 
    S32     h, 
    U8*     data_ptr, 
    U32     img_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_SUCCEED;
    U8 bits_per_pixel;
    /* Default decode mode is AUTO*/
    gdi_image_ab2_decode_mode_enum decode_mode = GDI_IMAGE_AB2_DECODE_MODE_AUTO;
    gdi_handle dst_layer_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("AB2", SA_start);
#endif

    /* 
     * make sure 1. The image data pointer is not NULL and half word aligned.
     *           2. The destination layer color format is 16, 24, or 32-bit.
     */
    bits_per_pixel = gdi_layer_get_bit_per_pixel();
    if ((data_ptr == NULL) || ((U32)data_ptr & 1) || (bits_per_pixel < 16))
    {
        return GDI_FAILED;
    }        
        
    flag |= gdi_image_codec_get_flag();
    if (flag & GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND)
    {
        gdi_layer_get_active(&dst_layer_handle);
        gdi_push_and_set_alpha_blending_source_layer(dst_layer_handle);
    
        decode_mode = GDI_IMAGE_AB2_DECODE_MODE_FORCE_ALPHA;
    }
    
    if (flag & GDI_IMAGE_CODEC_FLAG_IS_FILE)
    {
        CHAR *filename = (CHAR *)data_ptr;
        ret = gdi_image_ab2_draw_file(x, y, w, h, filename, decode_mode);
    }
    else
    {
        if (flag & GDI_IMAGE_CODEC_FLAG_BLEND_2_LAYERS)
        {
            ret = gdi_image_ab2_draw_blend_2_layers(x, y, w, h, data_ptr);
        }
        else
        {
            ret = gdi_image_ab2_draw_mem(x, y, w, h, data_ptr, decode_mode);
        }
    }

    if (flag & GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND)
    {
        gdi_pop_and_restore_alpha_blending_source_layer();
    }
    
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("AB2", SA_stop);
#endif    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  function_name
 * DESCRIPTION
 *  description
 * PARAMETERS
 *  param          [IN]     param usage
 * RETURNS
 *  OK if successful, otherwise is ERROR
 *  + OK
 *****************************************************************************/
GDI_RESULT gdi_image_ab2_get_dimension_handler(
    U32 flag, 
    U8 *data_ptr, 
    U32 img_size, 
    S32 *width, 
    S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flag & GDI_IMAGE_CODEC_FLAG_IS_FILE)
    {
        return gdi_image_ab2_get_dimension_file((U16 *)data_ptr, width, height);
    }
    else
    {
        return gdi_image_ab2_get_dimension_mem(data_ptr, width, height);
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_draw_id_nb_concurrent
 * DESCRIPTION
 *  description
 * PARAMETERS
 *  param          [IN]     param usage
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_ab2_draw_id_nb_concurrent(
    gdi_handle dst_layer,
    S32 dst_layer_x, 
    S32 dst_layer_y, 
    gdi_handle src_layer,
    U16 ImageId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_SUCCEED;
    U8 *data_ptr;
    U8  img_type;
    S32 img_size;
    S32 frame_number;
    S32 width;
    S32 height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(dst_layer != NULL);

    gdi_mutex_lock(&g_gdi_image_ab2_mutex);

    gdi_image_parse_resource_internal(
        (U8 *)GetImage(ImageId), 
        &data_ptr, 
        &img_type, 
        &img_size, 
        &frame_number, 
        &width, 
        &height);

    GDI_ASSERT(img_type == GDI_IMAGE_TYPE_AB2);
    
    ret = gdi_image_ab2_draw_internal(
        dst_layer,
        dst_layer_x,
        dst_layer_y,
        src_layer,
        data_ptr,
        GDI_IMAGE_AB2_DECODE_MODE_AUTO);

    gdi_mutex_unlock(&g_gdi_image_ab2_mutex);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_get_info
 * DESCRIPTION
 *  Gets the info flag.
 * PARAMETERS
 *  data_ptr       [IN]
 *  is_file        [IN]
 * RETURNS
 *  info flag
 *****************************************************************************/
U32 gdi_image_ab2_get_info(U8 *data_ptr, BOOL is_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_image_ab2_info_struct header;
    U32    info;    
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    info = GDI_IMAGE_INFO_FLAG_DEFAULT;
    
    if (!is_file)
    {
        gdi_image_ab2_read_header(&header, data_ptr);

        if ((header.pixel_format == GDI_IMAGE_AB2_FORMAT_PARGB8888) ||
            (header.pixel_format == GDI_IMAGE_AB2_FORMAT_PARGB8565))
        {
            GDI_IMAGE_INFO_FLAG_SET(info, GDI_IMAGE_INFO_FLAG_HAS_ALPHA);
        }

        if ((header.pixel_format == GDI_IMAGE_AB2_FORMAT_RGB888_FULLY_OPAQUE) ||
            (header.pixel_format == GDI_IMAGE_AB2_FORMAT_RGB565_FULLY_OPAQUE))
        {
            GDI_IMAGE_INFO_FLAG_SET(info, GDI_IMAGE_INFO_FLAG_IS_FULLY_OPAQUE);
        }        
    }

    return info;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_draw_to_buf_decode_mode
 * DESCRIPTION
 *  Gets the info flag.
 * DESCRIPTION
 *  Draw ABMv2 image on the current active layer with specified decode mode,
 *  The decode_mode can not be AUTO.
 * PARAMETERS
 *  offset_x        [IN]    x offset to draw
 *  offset_y        [IN]    y offset to draw
 *  data_ptr        [IN]    pointer to ABM data
 *  decode_mode     [IN]    decode mode to process
 * RETURNS
 *  GDI_SUCCEED if successful, otherwise GDI_FAILED
 *****************************************************************************/
GDI_RESULT gdi_image_ab2_draw_to_buf_decode_mode(
    gdi_image_ab2_img_buf_struct *dst_buf,
    S32 offset_x, 
    S32 offset_y, 
    const U8 *data_ptr,
    gdi_image_ab2_decode_mode_enum decode_mode)
{
    if (dst_buf == NULL || data_ptr == NULL)
        return GDI_FAILED;

    if (decode_mode <= GDI_IMAGE_AB2_DECODE_MODE_AUTO || decode_mode >= GDI_IMAGE_AB2_DECODE_MODE_END_OF_ENUM)
        return GDI_IMAGE_ERR_NO_DECODER_SUPPORT;

    return gdi_image_ab2_draw_to_buf_internal( dst_buf, offset_x, offset_y, data_ptr, decode_mode);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_draw_with_stack_with_color
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
GDI_RESULT gdi_image_ab2_draw_with_stack_with_color(
    gdi_handle dst_layer,
    S32 dst_layer_x, 
    S32 dst_layer_y, 
    gdi_handle src_layer,
    const U8 *data_ptr,
    gdi_image_ab2_decode_mode_enum decode_mode,
    gdi_color color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_SUCCEED;
#ifdef AB2_ENABLE_SWITCH_INT_STACK
    void *stk_ptr;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef AB2_ENABLE_SWITCH_INT_STACK
    /* Switch stack to internal RAM */
    stk_ptr = drv_gfx_stkmgr_get_stack(BMP_STACK_SIZE);
    if (stk_ptr)
    {
        ret = INT_SwitchStackToRun(
            stk_ptr, 
            BMP_STACK_SIZE,
            (kal_func_ptr)gdi_image_ab2_draw_internal_with_color, 
            7, 
            dst_layer,
            dst_layer_x, 
            dst_layer_y, 
            src_layer,
            data_ptr,
            decode_mode,
            (U32)color);
        drv_gfx_stkmgr_release_stack(stk_ptr);   
    }
    else
#endif /* defined(__MTK_TARGET__) */
    {
        ret = gdi_image_ab2_draw_internal_with_color(
            dst_layer,
            dst_layer_x, 
            dst_layer_y, 
            src_layer,
            data_ptr,
            decode_mode,
            (U32)color);
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_draw_mem_with_color
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  GDI_SUCCEED if successful, otherwise GDI_FAILED
 *  + GDI_SUCCEED
 *  + GDI_FAILED  
 *****************************************************************************/
static GDI_RESULT gdi_image_ab2_draw_mem_with_color(
    S32 x,
    S32 y,
    S32 width,
    S32 height,
    const U8 *data_ptr,
    gdi_color color,
    gdi_image_ab2_decode_mode_enum decode_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_FAILED;
    gdi_handle temp_layer_handle = GDI_NULL_HANDLE;
    gdi_handle dst_layer_handle, src_layer_handle;
    S32 img_width, img_height;
    U8 temp_layer_cf = GDI_COLOR_FORMAT_32_PARGB;
    MMI_BOOL always_blending = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_active(&dst_layer_handle);

    gdi_image_ab2_get_dimension_mem(data_ptr, &img_width, &img_height);
    if (width == 0 && height == 0)
    {
        width = img_width;
        height = img_height;
    }

    if (width == 0 || height == 0)
    {
        /* Do nothing */
        return GDI_SUCCEED;
    }

    /* Decoder supportted */
    /* No need to resize */
    if (img_width == width && img_height == height)
    {
        gdi_get_alpha_blending_source_layer(&src_layer_handle);
        
        return gdi_image_ab2_draw_with_stack_with_color(
            dst_layer_handle,
            x, 
            y, 
            src_layer_handle,
            data_ptr,
            decode_mode,
            color);
    }

    /* General case */
    do
    {
        if (decode_mode == GDI_IMAGE_AB2_DECODE_MODE_FORCE_ALPHA)
        {
            always_blending = MMI_TRUE;
        }
        
        if (((gdi_layer_struct*)dst_layer_handle)->cf == GDI_COLOR_FORMAT_32 &&
            always_blending != MMI_TRUE)

        {
            temp_layer_cf = GDI_COLOR_FORMAT_32;
        }
        else
        {
            temp_layer_cf = GDI_COLOR_FORMAT_32_PARGB;
        }
        
        gdi_image_create_temp_layer(
            &temp_layer_handle, 
            temp_layer_cf, 
            0, 
            0, 
            img_width, 
            img_height);
        if (temp_layer_handle == GDI_NULL_HANDLE)
        {
            break;
        }

        /* Draw to temp layer */
        ret = gdi_image_ab2_draw_with_stack_with_color(
            temp_layer_handle,
            0, 
            0, 
            GDI_NULL_HANDLE,
            data_ptr,
            GDI_IMAGE_AB2_DECODE_MODE_OUTPUT,
            color);
        if (ret != GDI_SUCCEED)
        {
            break;
        }
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("ABE", SA_start);
#endif
        if (temp_layer_cf == GDI_COLOR_FORMAT_32)
        {
            /* Directly resize ARGB temp layer to ARGB dst layer */
            ret = gdi_bitblt_resized_with_resizer(
                    temp_layer_handle, 
                    0,
                    0,
                    img_width - 1,
                    img_height - 1,
                    x,
                    y,
                    x + width - 1,
                    y + height - 1,
                    GDI_RESIZER_SW_QUALITY_MEDIUM);
            if (ret != GDI_SUCCEED)
            {
                break;
            }
        }
        else /* temp layer color format is PARGB8888 */
        {
            /* Resize and blit */
            ret = gdi_image_resize_and_blending_ex(
                temp_layer_handle, 
                x, 
                y, 
                width, 
                height,
                always_blending);            
            if (ret != GDI_SUCCEED)
            {
                break;
            }
        }
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("ABE", SA_stop);
#endif
    } while (0);

    if (temp_layer_handle != GDI_NULL_HANDLE)
    {
        gdi_image_free_temp_layer(temp_layer_handle);
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_draw_file_with_color
 * DESCRIPTION
 *  draw ABM v2 image on the current active layer from a file 
 * PARAMETERS
 *  offset_x       [IN]     x offset to draw
 *  offset_y       [IN]     y offset to draw
 *  filename       [IN]     filename
 * RETURNS
 *  GDI_SUCCEED if successful, otherwise GDI_FAILED
 *  + GDI_SUCCEED
 *****************************************************************************/
static GDI_RESULT gdi_image_ab2_draw_file_with_color(
    S32 x,
    S32 y,
    S32 width,
    S32 height,
    CHAR *filename,
    gdi_color color,
    gdi_image_ab2_decode_mode_enum decode_mode)    
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE   fh;
    U32         read_len;
    U32         file_size;
    U8          *buffer_ptr;
    GDI_RESULT  ret = GDI_SUCCEED;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fh = FS_Open((U16*)filename, FS_READ_ONLY | FS_OPEN_NO_DIR);
    if (fh < 0)
    {
        return GDI_IMAGE_ERR_OPEN_FILE_FAILED;
    }    

    /* check file size */
    if ((FS_GetFileSize(fh, &file_size) < 0))
    {
        FS_Close(fh);
        return GDI_IMAGE_ERR_INVALID_IMAGE_SIZE;
    }
    /* Try to get file buffer from media task memory */
    buffer_ptr = (U8*)gdi_alloc_ext_mem(file_size);
    if (buffer_ptr == NULL)
    {
        FS_Close(fh);
        return GDI_IMAGE_ERR_MEMORY_NOT_AVAILABLE;
    }

    /* read whole file into the file buffer once (fastest and easiest) */
    if (FS_Read(fh, buffer_ptr, file_size, &read_len) < 0)
    {
        FS_Close(fh);
        return GDI_FAILED;
    }

    FS_Close(fh);

    ret = gdi_image_ab2_draw_mem_with_color(x, y, width, height, buffer_ptr, color, decode_mode);

    /* free the media memory if it is used */
    if (buffer_ptr != NULL)
    {
        gdi_free_ext_mem((void**)&buffer_ptr);
    }

    return ret;
}



/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_draw_blend_2_layers_with_color
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  GDI_SUCCEED if successful, otherwise GDI_FAILED
 *  + GDI_SUCCEED
 *****************************************************************************/
static GDI_RESULT gdi_image_ab2_draw_blend_2_layers_with_color(S32 x, S32 y, S32 width, S32 height, const U8 *data_ptr, gdi_color color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_FAILED;
    gdi_handle temp_layer_handle = GDI_NULL_HANDLE;
    gdi_handle dst_layer_handle, src_layer_handle;
    S32 img_width, img_height;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_active(&dst_layer_handle);
    gdi_get_alpha_blending_source_layer(&src_layer_handle);

    /* Query image dimension */
    gdi_image_ab2_get_dimension_mem(data_ptr, &img_width, &img_height);
    if (width == 0 && height == 0)
    {
        width = img_width;
        height = img_height;
    }
    
    if (width == 0 || height == 0)
    {
        /* Do nothing */
        return GDI_SUCCEED;
    }
    
    /* Copy the source layer if needed */
    if (dst_layer_handle != src_layer_handle)
    {
        gdi_layer_blend_2_layers(
            src_layer_handle, 
            x, 
            y, 
            x + width - 1, 
            y + height - 1);
        gdi_set_alpha_blending_source_layer(dst_layer_handle);
    }
    
    do
    {
        /* Create a temp layer */
        gdi_image_create_temp_layer(
            &temp_layer_handle, 
            GDI_COLOR_FORMAT_32_PARGB, 
            x + ((gdi_layer_struct*)dst_layer_handle)->offset_x, 
            y + ((gdi_layer_struct*)dst_layer_handle)->offset_y, 
            img_width, 
            img_height);
        if (temp_layer_handle == GDI_NULL_HANDLE)
        {
            break;
        }

        /* Draw to temp layer */
        ret = gdi_image_ab2_draw_with_stack_with_color(
            temp_layer_handle,
            0, 
            0, 
            GDI_NULL_HANDLE,
            data_ptr,
            GDI_IMAGE_AB2_DECODE_MODE_OUTPUT,
            color);
        if (ret != GDI_SUCCEED)
        {
            break;
        }

        /* Resize and blit */
        ret = gdi_image_resize_and_blending_ex(
            temp_layer_handle, 
            x, 
            y, 
            width, 
            height,
            MMI_TRUE);            
        if (ret != GDI_SUCCEED)
        {
            break;
        }
    } while (0);

    if (temp_layer_handle != GDI_NULL_HANDLE)
    {
        gdi_image_free_temp_layer(temp_layer_handle);
    }

    // Restore source layer if needed
    if (dst_layer_handle != src_layer_handle)
    {
        gdi_set_alpha_blending_source_layer(src_layer_handle);
    }
    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_draw_with_color
 * DESCRIPTION
 *  To draw ABM v2 with specified color, all colors in palette will be 
 *  replaced with specified color.
 *  Input color must be the same color format as active layer, otherwise it will
 *  present incorrect color result.
 * PARAMETERS
 *  data_ptr        [IN]    pointer to image data from memory
 *  img_size        [IN]    image size
 *  color           [IN]    specific color to replace with
 *  x               [IN]    x
 *  y               [IN]    y
 *  w               [IN]    width
 *  h               [IN]    height
 *  flag            [IN]    image resource flag     
 * RETURNS
 *  GDI_SUCCEED if successful, otherwise GDI_FAILED
 *  + GDI_SUCCEED
 *  + GDI_FAILED
 *****************************************************************************/
GDI_RESULT gdi_image_ab2_draw_with_color(
    U8*     data_ptr, 
    U32     img_size,
    gdi_color color,
    S32     x,
    S32     y,
    S32     w,
    S32     h,
    U32     flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_SUCCEED;
    U8 bits_per_pixel;
    gdi_image_ab2_decode_mode_enum decode_mode = GDI_IMAGE_AB2_DECODE_MODE_AUTO;
    gdi_handle dst_layer_handle;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* 
     * make sure 1. The image data pointer is not NULL and half word aligned.
     *           2. The destination layer color format is 16, 24, or 32-bit.
     */
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("AB2", SA_start);
#endif
    bits_per_pixel = gdi_layer_get_bit_per_pixel();
    if ((data_ptr == NULL) || ((U32)data_ptr & 1) || (bits_per_pixel < 16))
    {
        return GDI_FAILED;
    }

    flag |= gdi_image_codec_get_flag();
    if (flag & GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND)
    {
        gdi_layer_get_active(&dst_layer_handle);
        gdi_push_and_set_alpha_blending_source_layer(dst_layer_handle);
    
        decode_mode = GDI_IMAGE_AB2_DECODE_MODE_FORCE_ALPHA;
    }    
        
    /*flag |= gdi_image_codec_get_flag();*/
    
    if (flag & GDI_IMAGE_CODEC_FLAG_IS_FILE)
    {
        CHAR *filename = (CHAR *)data_ptr;
        ret = gdi_image_ab2_draw_file_with_color(x, y, w, h, filename, color, decode_mode);
    }
    else
    {
        if (flag & GDI_IMAGE_CODEC_FLAG_BLEND_2_LAYERS)
        {
            ret = gdi_image_ab2_draw_blend_2_layers_with_color(x, y, w, h, data_ptr, color);
        }
        else
        {
            ret = gdi_image_ab2_draw_mem_with_color(x, y, w, h, data_ptr, color, decode_mode);
        }
    }

    if (flag & GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND)
    {
        gdi_pop_and_restore_alpha_blending_source_layer();
    }

    
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("AB2", SA_stop);
#endif    
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_ab2_check_alpha_mem
 * DESCRIPTION
 *  get if ABM v2 image is with or without alpha value from memory
 * PARAMETERS
 *  data_ptr       [IN]     pointer to image data  
 *  with_alpha     [OUT]    image is with/without alpha
 * RETURNS
 *  GDI_SUCCEED if successful, otherwise GDI_FAILED    
 *****************************************************************************/
GDI_RESULT gdi_image_ab2_check_alpha_mem(const U8 *data_ptr, kal_bool *with_alpha)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_image_ab2_info_struct header;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(data_ptr != NULL);
    *with_alpha = KAL_FALSE;
    
    gdi_image_ab2_read_header(&header, data_ptr);
    switch(header.pixel_format)
    {
        case GDI_IMAGE_AB2_FORMAT_PARGB8888:
        case GDI_IMAGE_AB2_FORMAT_PARGB8565:
            *with_alpha = KAL_TRUE;
            break;
    }

    return GDI_SUCCEED;
}

/**************************************************************************************
 * FUNCTION
 *  gdi_image_ab2_check_alpha_file
 * DESCRIPTION
 *  get if ABM v2 image is with or without alpha value from file
 * PARAMETERS
 *  filename       [IN]     filename of abm v2 image  
 *  with_alpha     [OUT]    image is with/without alpha
 * RETURNS
 *  GDI_SUCCEED if successful, otherwise GDI_FAILED or GDI_IMAGE_ERR_OPEN_FILE_FAILED   
 **************************************************************************************/
GDI_RESULT gdi_image_ab2_check_alpha_file(const U16 *filename, kal_bool *with_alpha)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_FAILED;
    
    FS_HANDLE   fh;
    U32         read_len;
    U8          buf[GDI_IMAGE_AB2_HEADER_SIZE];
    gdi_image_ab2_info_struct header;

    *with_alpha = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(filename != NULL);
    
    fh = FS_Open((U16*)filename, FS_READ_ONLY | FS_OPEN_NO_DIR);
    if (fh < 0)
    {
        return GDI_IMAGE_ERR_OPEN_FILE_FAILED;
    }

    /* read header */
    if (FS_Read(fh, &buf, sizeof(buf), &read_len) != FS_NO_ERROR)
    {
        FS_Close(fh);
        return GDI_FAILED;
    }
    
    /* not enough data */    
    if (read_len != sizeof(buf))
    {
        FS_Close(fh);
        return GDI_FAILED;
    }

    FS_Close(fh);

    /* result */
    gdi_image_ab2_read_header(&header, buf);

    switch(header.pixel_format)
    {
        case GDI_IMAGE_AB2_FORMAT_PARGB8888:
        case GDI_IMAGE_AB2_FORMAT_PARGB8565:
            *with_alpha = KAL_TRUE;
            break;
    }

    return GDI_SUCCEED;   
    
}

