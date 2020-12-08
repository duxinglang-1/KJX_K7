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
 *	 gdi_image_bmp.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  device bmp api
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "kal_release.h"
#include "kal_general_types.h"
#include "wchar.h"

#include "lcd_if.h"
#include "string.h"
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "fsal.h"
#include "MMIDataType.h"
#include "app_str.h"
#include "cache_sw.h"
#include "mmu.h"

#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gdi_include.h"
#include "gdi_layer.h"
#include "gdi_bytestream.h"
#include "gdi_primitive.h"
#include "gdi_image_dev_bmp.h"
#include "gdi_internal.h"


/****************************************************************************
 * Constant
 ****************************************************************************/

#define GDI_IMAGE_DEV_BMP_MAGIC_NUMBER '\0MBP'

#define GDI_IMAGE_DEV_BMP_MAX_WIDTH    2048
#define GDI_IMAGE_DEV_BMP_MAX_HEIGHT   2048


/****************************************************************************
 * Type
 ****************************************************************************/

typedef struct
{
    kal_uint32 magic_number; /* GDI_IMAGE_DEV_BMP_MAGIC_NUMBER */
    gdi_color_format cf;
    kal_uint8 bytes_per_pixel;
    kal_uint16 width;
    kal_uint16 height;
} gdi_image_dev_bmp_header_struct;


/****************************************************************************
 * Functions
 ****************************************************************************/

static GDI_RESULT gdi_image_dev_bmp_draw_general(
    U32 flag,
    S32 x,
    S32 y,
    S32 w,
    S32 h,
    const gdi_image_dev_bmp_header_struct *header,
    STFSAL *fsal_p)
{
    GDI_RESULT ret = GDI_FAILED;
    kal_uint8 *img_buffer;
    kal_uint8 *resize_buffer;
    FSAL_Status f_status;
    kal_uint32 data_size;


    data_size = header->width * header->height * header->bytes_per_pixel;

    img_buffer = gdi_alloc_ext_mem_framebuffer(data_size);
    if (img_buffer == NULL)
    {
        return GDI_IMAGE_ERR_FRAME_BUFFER_NOT_ENOUGH;
    }

    resize_buffer = NULL;
    do
    {
        gdi_handle img_layer;
        gdi_handle alpha_layer;
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
        kal_bool cache_switched;
#endif
    
        f_status = FSAL_Read(fsal_p, img_buffer, data_size);
        if (f_status != FSAL_OK)
        {
            ret = GDI_IMAGE_ERR_INVALID_IMAGE_SIZE;
            break;
        }
        
        gdi_layer_create_cf_using_outside_memory(
            header->cf,
            0, 0, header->width, header->height,
            &img_layer,
            img_buffer,
            data_size);

        if (header->width != w || header->height != h)
        {
            gdi_handle resize_layer;
            gdi_handle swap_temp_layer;
            kal_uint8 *swap_temp_ptr;
        
            resize_buffer = gdi_alloc_ext_mem_framebuffer(w * h * header->bytes_per_pixel);
            if (resize_buffer == NULL)
            {
                ret = GDI_IMAGE_ERR_FRAME_BUFFER_NOT_ENOUGH;
                break;
            }

            gdi_layer_create_cf_using_outside_memory(
                header->cf,
                0, 0, w, h,
                &resize_layer,
                resize_buffer,
                w * h * header->bytes_per_pixel);

            gdi_layer_push_and_set_active(resize_layer);
            gdi_bitblt_resized_with_resizer(
                img_layer,
                0, 0, header->width - 1, header->height - 1,
                0, 0, w - 1, h - 1,
                GDI_RESIZER_DEFAULT);
            gdi_layer_pop_and_restore_active();

            /* Swap img layer with the resized layer */
            swap_temp_layer = img_layer; img_layer = resize_layer; resize_layer = swap_temp_layer;
            swap_temp_ptr = img_buffer; img_buffer = resize_buffer; resize_buffer = swap_temp_ptr;
            
            gdi_layer_free(resize_layer);
            gdi_free_ext_mem((void**)&resize_buffer);
        }
        
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
        cache_switched = KAL_FALSE;
        if (INT_QueryIsCachedRAM(gdi_act_layer->buf_ptr, gdi_act_layer->layer_size))
        {
            dynamic_switch_cacheable_region(
                (void*)&(gdi_act_layer->buf_ptr), gdi_act_layer->layer_size, PAGE_NO_CACHE);
            cache_switched = KAL_TRUE;
        }
#endif

        gdi_get_alpha_blending_source_layer(&alpha_layer);
        if (alpha_layer != GDI_NULL_HANDLE && header->cf != GDI_COLOR_FORMAT_16)
        {
            kal_int32 layer_ori_x, layer_ori_y;
            gdi_color layer_ori_bg_color;
        
            gdi_layer_push_and_set_active(img_layer);
                gdi_layer_set_position(x, y);
                gdi_layer_set_background(gdi_act_color_from_rgb(0, 0, 0, 0));
            gdi_layer_pop_and_restore_active();

            gdi_layer_push_and_set_active(alpha_layer);
                layer_ori_bg_color = gdi_layer_get_background();
                gdi_layer_set_background(gdi_act_color_from_rgb(0, 0, 0, 0));
            gdi_layer_pop_and_restore_active();

            gdi_layer_get_position(&layer_ori_x, &layer_ori_y);
            gdi_layer_set_position(0, 0);
            gdi_layer_flatten_with_clipping(alpha_layer, img_layer, 0, 0);
            gdi_layer_set_position(layer_ori_x, layer_ori_y);

            gdi_layer_set_background_nb_concurrent(alpha_layer, layer_ori_bg_color);
        }
        else
        {
            /* No alpha blending */
            gdi_bitblt(img_layer, 0, 0, w - 1, h - 1, x, y);
        }

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
        if (cache_switched)
        {
            dynamic_switch_cacheable_region(
                (void*)&(gdi_act_layer->buf_ptr), gdi_act_layer->layer_size, PAGE_CACHEABLE);
        }
#endif

        gdi_layer_free(img_layer);

        ret = GDI_SUCCEED;
    } while (0);

    gdi_free_ext_mem((void**)&img_buffer);

    return ret;
}


GDI_RESULT gdi_image_dev_bmp_draw_handler(
            U32 flag,
            U32 frame_pos,
            S32 x,
            S32 y,
            S32 w,
            S32 h,
            U8* data_ptr,
            U32 img_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_FAILED;
    gdi_image_dev_bmp_header_struct header;
    STFSAL fsal;
    FSAL_Status f_status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flag & GDI_IMAGE_CODEC_FLAG_IS_FILE)
    {
        if (FSAL_Open(&fsal, data_ptr, FSAL_READ) != FSAL_OK)
        {
            return GDI_FAILED;
        }
    }
    else
    {
        FSAL_Direct_SetRamFileSize(&fsal, img_size);
        if (FSAL_Open(&fsal, data_ptr, FSAL_ROMFILE) != FSAL_OK)
        {
            return GDI_FAILED;
        }
    }
    
    do
    {
        ret = GDI_IMAGE_DECODER_ERR_INVALID_IMG_TYPE;
        
        f_status = FSAL_Read(&fsal, (kal_uint8*)&header, sizeof(header));
        if (f_status != FSAL_OK)
        {
            break;
        }

        if (header.magic_number != GDI_IMAGE_DEV_BMP_MAGIC_NUMBER)
        {
            break;
        }

        if (header.cf > GDI_COLOR_FORMAT_MAINLCD ||
            header.width > GDI_IMAGE_DEV_BMP_MAX_WIDTH ||
            header.height > GDI_IMAGE_DEV_BMP_MAX_HEIGHT)
        {
            ret = GDI_IMAGE_ERR_IMAGE_TOO_LARGE;
            break;
        }

        if (gdi_bits_per_pixel(header.cf) != (header.bytes_per_pixel * 8))
        {
            break;
        }

        if (w == 0 && h == 0)
        {
            w = header.width;
            h = header.height;
        }

        if (w == 0 || h == 0)
        {
            ret = GDI_SUCCEED;
            break;
        }

        ret = gdi_image_dev_bmp_draw_general(
                flag,
                x,
                y,
                w,
                h,
                &header,
                &fsal);
    } while (0);
    FSAL_Close(&fsal);

    return ret;
}



static GDI_RESULT gdi_image_device_bmp_get_header(
    const WCHAR *filepath,
    gdi_image_dev_bmp_header_struct *header)
{
    GDI_RESULT ret = GDI_FAILED;
    FS_HANDLE f_handle;
    kal_int32 f_ret;
    kal_uint32 n_read;

    f_handle = FS_Open(filepath, FS_READ_ONLY);
    if (f_handle > 0)
    {
        do
        {
            f_ret = FS_Read(f_handle, header, sizeof(gdi_image_dev_bmp_header_struct), &n_read);
            if (f_ret < FS_NO_ERROR || n_read != sizeof(gdi_image_dev_bmp_header_struct))
            {
                break;
            }

            if (header->magic_number != GDI_IMAGE_DEV_BMP_MAGIC_NUMBER)
            {
                break;
            }
            
            ret = GDI_SUCCEED;
        }
        while (0);
    
        FS_Close(f_handle);
    }
    else
    {
        ret = GDI_IMAGE_ERR_OPEN_FILE_FAILED;
    }

    return ret;
}



static GDI_RESULT gdi_image_device_bmp_get_dimension_from_file(
    const WCHAR *filename,
    kal_int32 *width,
    kal_int32 *height)
{
    GDI_RESULT ret;
    gdi_image_dev_bmp_header_struct header;

    ret = gdi_image_device_bmp_get_header((WCHAR*)filename, &header);

    if (ret == GDI_SUCCEED)
    {
        *width = header.width;
        *height = header.height;
    }
    else
    {
        *width = *height = 0;
    }

    return ret;
}


GDI_RESULT gdi_image_dev_bmp_get_dimension_handler(
            U32 flag,
            U8* data_ptr,
            U32 img_size,
            S32 *width,
            S32 *height)
{
    *width = *height = 0;

	if (flag & GDI_IMAGE_CODEC_FLAG_IS_FILE)
	{
        return gdi_image_device_bmp_get_dimension_from_file((WCHAR*)data_ptr, width, height);
	}
	else
	{
	    gdi_image_dev_bmp_header_struct *header;

	    if (img_size <= sizeof(gdi_image_dev_bmp_header_struct))
	    {
	        return GDI_FAILED;
	    }

	    header = (gdi_image_dev_bmp_header_struct*)data_ptr;
	    if (header->magic_number != GDI_IMAGE_DEV_BMP_MAGIC_NUMBER)
	    {
	        return GDI_FAILED;
	    }

	    *width = header->width;
	    *height = header->height;
	}

	return GDI_SUCCEED;
}



GDI_RESULT gdi_image_device_bmp_encode_file(
            WCHAR *filepath,
            kal_uint8 *image,
            gdi_color_format cf,
            kal_uint32 width,
            kal_uint32 height)
{
    GDI_RESULT ret;
    FS_HANDLE f_handle;
    kal_int32 f_ret;
    kal_uint32 n_write;

    if (cf >= GDI_COLOR_FORMAT_MAINLCD)
    {
        return GDI_IMAGE_ERR_UNSUPPORTED_FORMAT;
    }

    if (width > GDI_IMAGE_DEV_BMP_MAX_WIDTH ||
        height > GDI_IMAGE_DEV_BMP_MAX_HEIGHT)
    {
        return GDI_IMAGE_ERR_INVALID_IMAGE_SIZE;
    }

    f_handle = FS_Open((WCHAR*)filepath, FS_CREATE_ALWAYS);
    if (f_handle <= 0)
    {
        return GDI_IMAGE_ERR_OPEN_FILE_FAILED;
    }

    ret = GDI_FAILED;
    do 
    {
        gdi_image_dev_bmp_header_struct header;
    
        memset(&header, 0, sizeof(header));
    
        header.magic_number = GDI_IMAGE_DEV_BMP_MAGIC_NUMBER;
        header.cf = cf;
        header.bytes_per_pixel = (gdi_bits_per_pixel(cf) >> 3);
        header.width = width;
        header.height = height;

        f_ret = FS_Write(f_handle, &header, sizeof(header), &n_write);
        if (f_ret < FS_NO_ERROR || n_write != sizeof(header))
        {
            ret = GDI_FAILED;
            break;
        }

        f_ret = FS_Write(f_handle, image, width * height * header.bytes_per_pixel, &n_write);
        if (f_ret < FS_NO_ERROR)
        {
            ret = GDI_FAILED;
            break;
        }

        ret = GDI_SUCCEED;
    } while (0);

    if (ret != GDI_SUCCEED)  // error handle (f_ret != FS_NO_ERROR)
    {
        if (f_ret == FS_DRIVE_NOT_FOUND)
        {   
            ret = GDI_IMAGE_ENCODER_ERR_NO_DISK;
        }
        else if (f_ret == FS_DISK_FULL)
        {
            ret = GDI_IMAGE_ENCODER_ERR_DISK_FULL;
        }
        else if (f_handle == FS_ROOT_DIR_FULL)
        {
            ret = GDI_IMAGE_ENCODER_ERR_ROOT_DIR_FULL;
        }
        else
        {
            ret = GDI_FAILED;
        }
    }

    FS_Close(f_handle);

    return ret;
}


GDI_RESULT gdi_image_device_bmp_write_header(
            kal_uint8 *dest_memory,
            kal_int8 *header_size,
            gdi_color_format cf,
            kal_uint32 width,
            kal_uint32 height)
{
    gdi_image_dev_bmp_header_struct header;

    memset(&header, 0, sizeof(header));

    header.magic_number = GDI_IMAGE_DEV_BMP_MAGIC_NUMBER;
    header.cf = cf;
    header.bytes_per_pixel = (gdi_bits_per_pixel(cf) >> 3);
    header.width = width;
    header.height = height;

    memcpy(dest_memory, &header, sizeof(header));
    *header_size = sizeof(header);

    return GDI_SUCCEED;
}


GDI_RESULT gdi_image_is_device_bmp_file(U8 *file_name)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    WCHAR *filepath = (WCHAR*)file_name;
    kal_int32 filepath_len;
    
    filepath_len = app_ucs2_wcslen(filepath);
    if (filepath_len > 4)
    {
        if (app_ucs2_wcsicmp(filepath + filepath_len - 4, L".pbm") == 0)
        {
            return GDI_SUCCEED;
        }
    }

    return GDI_FAILED;
}


GDI_RESULT gdi_image_dev_bmp_check_alpha_file(const WCHAR *filepath, kal_bool *with_alpha)
{
    GDI_RESULT ret = GDI_FAILED;
    gdi_image_dev_bmp_header_struct header;

    *with_alpha = KAL_FALSE;

    ret = gdi_image_device_bmp_get_header(filepath, &header);
    if (ret == GDI_SUCCEED)
    {
        switch (header.cf)
        {
            case GDI_COLOR_FORMAT_32:
            case GDI_COLOR_FORMAT_32_PARGB:
            case GDI_COLOR_FORMAT_PARGB6666:
                *with_alpha = KAL_TRUE;
                break;
        }
    }

    return ret;
}


GDI_RESULT gdi_image_dev_bmp_check_alpha_mem(
    const void *img_data,
    kal_int32 img_size,
    kal_bool *with_alpha)
{
    gdi_image_dev_bmp_header_struct *header;

    *with_alpha = KAL_FALSE;

    header = (gdi_image_dev_bmp_header_struct*)img_data;
    if (header->magic_number != GDI_IMAGE_DEV_BMP_MAGIC_NUMBER)
    {
        return GDI_FAILED;
    }
    
    switch (header->cf)
    {
        case GDI_COLOR_FORMAT_32:
        case GDI_COLOR_FORMAT_32_PARGB:
        case GDI_COLOR_FORMAT_PARGB6666:
            *with_alpha = KAL_TRUE;
            break;
    }

    return GDI_SUCCEED;
}

