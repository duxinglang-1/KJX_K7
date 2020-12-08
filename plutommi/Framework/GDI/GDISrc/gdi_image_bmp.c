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
 *  gdi_image_bmp.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI Image Bitmap related.
 *
 * Author:
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "gdi_trc.h"
#include "gdi_internal.h"
#include "drm_gprot.h"
#include "med_utility.h"

#if defined(GDI_USING_DITHERING)
#include "iul_spatial_dithering.h"
#include "iul_sd_macros.h"
#endif

#include "kal_general_types.h"
#include "kal_release.h"
#include "wchar.h"
#include "setjmp.h"
#include "string.h"
#include "fs_type.h"
#include "fs_errcode.h"
#include "fs_func.h"
#include "med_smalloc.h"
#include "MMIDataType.h"

#include "gdi_bytestream.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gdi_include.h"
#include "gdi_mutex.h"
#include "gdi_image.h"
#include "gdi_primitive.h"
#include "gdi_image_bmp.h"
#include "gdi_lfs.h"
#include "gdi_image_gif.h"
#include "gd_include.h"


#include "gdi_imgdec_bmp.h"

/* for switch stack */
#include "drv_gfx_stack_switch_manager.h" 
extern kal_uint32 INT_SwitchStackToRun(void *stack_start, kal_uint32 stack_size, kal_func_ptr func, kal_uint32 argc, ...);      


#if defined(__MTK_TARGET__)
#pragma Otime
#endif /* defined(__MTK_TARGET__) */ 


/****************************************************************************
* Define
*****************************************************************************/
#define GDI_BI_RGB  0
#define GDI_BI_RLE8  1
#define GDI_BI_RLE4  2
#define GDI_BI_BITFIELDS  3
#define GDI_BMP_BYTESTREM_BUF_SIZE 4096

/****************************************************************************
* Static Declaration
*****************************************************************************/
#if defined(__MTK_TARGET__)
#pragma arm section zidata = "CACHEDZI",  rwdata = "CACHEDRW" 
#endif



#if defined(__MTK_TARGET__)
#pragma arm section zidata, rwdata
#endif

static U8   gdi_image_bmp_palette_size;      /* size of palette */

/*****************************************************************************
 * FUNCTION
 *  gdi_image_bmp_get_transparent_index
 * DESCRIPTION
 *  get the transparent index of 8-bits bmp
 * PARAMETERS
 *  void
 * RETURNS
 *  U8  transparent index of 8-bits bmp
 *****************************************************************************/
U16 gdi_image_bmp_get_transparent_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;  /* transparent_color_index of BMP is always 0. */
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_bmp_get_palette_size
 * DESCRIPTION
 *  get the palette size of 8-bits bmp
 * PARAMETERS
 *  void
 * RETURNS
 *  U8  palette size of 8-bits bmp
 *****************************************************************************/
U8 gdi_image_bmp_get_palette_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_bmp_get_palette_size)
    ret = gdi_image_bmp_palette_size;
    GDI_EXIT_CRITICAL_SECTION(gdi_image_bmp_get_palette_size)

    return ret;
}


/****************************************************************************
* Cache Bitmap
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  gdi_image_cache_bmp_get
 * DESCRIPTION
 *  cache a region from a layer
 * PARAMETERS
 *  x1          [IN]    left-up cornor x of destination region
 *  y1          [IN]    left-up cornor y of destination region
 *  x2          [IN]    right-down cornor x of destination region
 *  y2          [IN]    right-down cornor y of destination region
 *  bmp_ptr     [OUT]   return width, height, and pointer to cached region
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_cache_bmp_get(S32 x1, S32 y1, S32 x2, S32 y2, gdi_image_cache_bmp_struct *bmp_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 layer_width;
    S32 layer_height;
    S32 layer_clip_x1;
    S32 layer_clip_x2;
    S32 layer_clip_y1;
    S32 layer_clip_y2;
    S32 start_x, end_x, start_y, end_y;
    U8 *layer_buf_ptr;
    U8 *bmp_data_ptr;
    S32 byte_per_row;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_cache_bmp_get)

    /* get src and dest buffer ptr */
    bmp_data_ptr = bmp_ptr->buf_ptr;            /* dest */
    gdi_layer_get_buffer_ptr(&layer_buf_ptr);   /* src */

    gdi_layer_get_clip(&layer_clip_x1, &layer_clip_y1, &layer_clip_x2, &layer_clip_y2);
    gdi_layer_get_dimension(&layer_width, &layer_height);

    /* out of clip region */
    if ((x1 > layer_clip_x2) || (y1 > layer_clip_y2) || (x2 < layer_clip_x1) || (y2 < layer_clip_y1))
    {
        bmp_ptr->width = 0;
        bmp_ptr->height = 0;
        GDI_RETURN(GDI_SUCCEED);
    }

    /* Calculate valid region */
    if (x1 < layer_clip_x1)
    {
        start_x = layer_clip_x1;
    }
    else
    {
        start_x = x1;
    }

    if (x2 > layer_clip_x2)
    {
        end_x = layer_clip_x2;
    }
    else
    {
        end_x = x2;
    }

    if (y1 < layer_clip_y1)
    {
        start_y = layer_clip_y1;
    }
    else
    {
        start_y = y1;
    }

    if (y2 > layer_clip_y2)
    {
        end_y = layer_clip_y2;
    }
    else
    {
        end_y = y2;
    }

    /* fill bitmap info */
    bmp_ptr->width = end_x - start_x + 1;
    bmp_ptr->height = end_y - start_y + 1;

    byte_per_row = (bmp_ptr->width * GDI_LAYER.bits_per_pixel) >> 3;

    /* find source buffer start position of the active layer */
    layer_buf_ptr += ((start_y * layer_width + start_x) * GDI_LAYER.bits_per_pixel) >> 3;       /* 16-bit */

    /* fill bitmap buffer */
    for (i = 0; i < bmp_ptr->height; i++)
    {
        memcpy(bmp_data_ptr, layer_buf_ptr, byte_per_row);

        bmp_data_ptr += byte_per_row;
        layer_buf_ptr += (layer_width * GDI_LAYER.bits_per_pixel) >> 3; /* just to next row */
    }

    GDI_EXIT_CRITICAL_SECTION(gdi_image_cache_bmp_get)
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_cache_bmp_draw
 * DESCRIPTION
 *  draw cached image to a layer
 * PARAMETERS
 *  offset_x        [IN]    position of layer want to draw to
 *  offset_y        [IN]    position of layer want to draw to 
 *  bmp_ptr         [IN]    the bmp want to draw
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_cache_bmp_draw(S32 offset_x, S32 offset_y, gdi_image_cache_bmp_struct *bmp_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 layer_width;
    S32 layer_height;
    S32 layer_clip_x1;
    S32 layer_clip_x2;
    S32 layer_clip_y1;
    S32 layer_clip_y2;
    S32 start_x, end_x, start_y, end_y;
    U8 *layer_buf_ptr;
    U8 *bmp_data_ptr;
    S32 x1, y1, x2, y2;
    S32 vlaid_width;
    S32 byte_per_row;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_cache_bmp_draw)

    /* get src and dest buffer ptr */
    bmp_data_ptr = bmp_ptr->buf_ptr;            /* src */
    gdi_layer_get_buffer_ptr(&layer_buf_ptr);   /* dest */

    byte_per_row = (bmp_ptr->width * GDI_LAYER.bits_per_pixel) >> 3;

    gdi_layer_get_clip(&layer_clip_x1, &layer_clip_y1, &layer_clip_x2, &layer_clip_y2);
    gdi_layer_get_dimension(&layer_width, &layer_height);

    x1 = offset_x;
    y1 = offset_y;

    x2 = x1 + bmp_ptr->width - 1;
    y2 = y1 + bmp_ptr->height - 1;

    /* out of clip region */
    if ((x1 > layer_clip_x2) || (y1 > layer_clip_y2) || (x2 < layer_clip_x1) || (y2 < layer_clip_y1))
    {
        GDI_RETURN(GDI_SUCCEED);
    }

    /* Calculate valid region */
    if (x1 < layer_clip_x1)
    {
        start_x = layer_clip_x1;
    }
    else
    {
        start_x = x1;
    }

    if (x2 > layer_clip_x2)
    {
        end_x = layer_clip_x2;
    }
    else
    {
        end_x = x2;
    }

    if (y1 < layer_clip_y1)
    {
        start_y = layer_clip_y1;
    }
    else
    {
        start_y = y1;
    }

    if (y2 > layer_clip_y2)
    {
        end_y = layer_clip_y2;
    }
    else
    {
        end_y = y2;
    }

    /* find update width */
    vlaid_width = end_x - start_x + 1;

    /* shift to bmp buffer start position */
    bmp_data_ptr += ((start_y - y1) * byte_per_row) + ((start_x - x1) * (GDI_LAYER.bits_per_pixel >> 3));

    /* shift to layer buffer start position */
    layer_buf_ptr += ((start_y * layer_width + start_x) * GDI_LAYER.bits_per_pixel) >> 3;

    /* fill bitmap buffer */
    for (i = start_y; i <= end_y; i++)
    {
        memcpy(layer_buf_ptr, bmp_data_ptr, (vlaid_width * GDI_LAYER.bits_per_pixel) >> 3);
        bmp_data_ptr += byte_per_row;
        layer_buf_ptr += (layer_width * GDI_LAYER.bits_per_pixel) >> 3;
    }

    GDI_EXIT_CRITICAL_SECTION(gdi_image_cache_bmp_draw)
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_bmp_draw_handler
 * DESCRIPTION
 *  draw bmp
 * PARAMETERS
 *  flag            [IN]        flag
 *  frame_pos       [IN]        which frame to draw
 *  x               [IN]        draw position x
 *  y               [IN]        draw position y
 *  w               [IN]        draw width
 *  h               [IN]        draw height
 *  data_ptr        [IN]        image pointer
 *  img_size        [IN]        image fize
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_bmp_draw_handler(U32 flag, U32 frame_pos, S32 x, S32 y, S32 w, S32 h, U8 *data_ptr, U32 img_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_imgdec_bmp_struct dec;
    GDI_RESULT ret;
    BOOL aborted = FALSE;

    // TODO: STACK OVERFLOW?
    void* bs_buf = NULL;
    U32 buffer_size;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = GDI_FAILED;

        buffer_size = GDI_IMGDEC_BYTESTREAM_BUFFER_SIZE;
        bs_buf = gdi_alloc_ext_mem_cacheable(buffer_size);
        if (bs_buf == NULL)
        {
            buffer_size = GDI_IMGDEC_BYTESTREAM_BUFFER_SIZE / 2;
            bs_buf  = gdi_alloc_ext_mem_cacheable(buffer_size);
            if (bs_buf == NULL)
            {
                buffer_size = GDI_IMGDEC_BYTESTREAM_BUFFER_SIZE / 4;
                bs_buf  = gdi_alloc_ext_mem_cacheable(buffer_size);
                if (bs_buf == NULL)
                {
                    return GDI_IMAGE_ERR_FRAME_BUFFER_NOT_ENOUGH;
                }
            }
        }

    gdi_imgdec_bmp_init(&dec, (gdi_handle)gdi_act_layer, (PU8)bs_buf, buffer_size, &aborted, flag);
           
    if (dec.is_from_file)
    {
        if (w && h)
        {
            ret = gdi_imgdec_bmp_draw_resized_file(&dec, x, y, TRUE, w, h, (S8*)data_ptr, 0);
        }
        else
        {
            ret = gdi_imgdec_bmp_draw_resized_file(&dec, x, y, FALSE, 0, 0, (S8*)data_ptr, 0);
        }
    }
    else
    {
        if (w && h)
        {
            ret = gdi_imgdec_bmp_draw_resized(&dec, x, y, TRUE, w, h, data_ptr, img_size, 0);
        }
        else
        {
            ret = gdi_imgdec_bmp_draw_resized(&dec, x, y, FALSE, 0, 0, data_ptr, img_size, 0);
        }
    }

    gdi_imgdec_bmp_deinit(&dec);

    if (bs_buf != NULL)
    {
        gdi_free_ext_mem(&bs_buf);
    }
    return ret;

}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_bmp_get_dimension_handler
 * DESCRIPTION
 *  get dimension of the bmp image
 * PARAMETERS
 *  flag           [IN]     flag
 *  data_ptr       [IN]     image pointer
 *  img_size       [IN]     image fize
 *  width          [OUT]    image width
 *  height         [OUT]    image height
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_bmp_get_dimension_handler(U32 flag, U8 *data_ptr, U32 img_size, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flag & GDI_IMAGE_CODEC_FLAG_IS_FILE)
    {
        return gdi_imgdec_bmp_get_dimension(data_ptr,0,width,height);
    }
    else
    {
        return gdi_imgdec_bmp_get_dimension(data_ptr,img_size,width,height);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_is_bmp_file
 * DESCRIPTION
 *  is the file a bmp image file
 * PARAMETERS
 *  file_name       [IN]    file name
 * RETURNS
 *  BOOL, return true if the file is bmp file
 *****************************************************************************/
GDI_RESULT gdi_image_is_bmp_file(U8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 buf[2];
    U32 len;
    U32 result;
    FS_HANDLE handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = DRM_open_file(
                 (U16*)file_name,
                 FS_READ_ONLY | FS_OPEN_NO_DIR | FS_OPEN_SHARED,
                 DRM_PERMISSION_DISPLAY);

    if (handle < 0) return GDI_IMAGE_ERR_INVALID_FILE;

    result = DRM_read_file(handle, buf, 2, &len);

    DRM_close_file(handle);

    if (result == FS_NO_ERROR)
        if (len == 2)
            if (buf[0] == 'B' && buf[1] == 'M')
            {
                return GDI_SUCCEED;
            }
    return GDI_FAILED;
}


#ifndef __MTK_TARGET__
    #pragma pack(push, 2)
    #define TEST_ALIGNMENT
#else
    #define TEST_ALIGNMENT __packed
#endif


typedef TEST_ALIGNMENT struct {
    U16 signature;              /* 19778 */
    U32 size;
    U16 reserved1;              /* 0 */
    U16 reserved2;              /* 0 */
    U32 image_offset;
    U32 size_of_bmpinfoheader;  /* 40 */
    U32 width;
    U32 height;
    U16 planes;                 /* 1 */
    U16 bpp;                    /* 1, 4, 8, 24 */
    U32 compression;            /* 0 = none, 1 = RLE - 8, 2 = RLE - 4 */
    U32 size_of_image;
    U32 h_resolution;
    U32 v_resolution;
    U32 number_of_colors;
    U32 number_of_major_colors;
} BITMAP_HEADER;

#ifndef __MTK_TARGET__
    #pragma pack(pop)
#endif

#define MAX_BMP_MEM_SIZE    (10*1024)
#define MIN_BMP_MEM_SIZE    (10)

static FS_HANDLE wb_file_handle = 0;
static U8* wb_buffer = NULL;
static U32 wb_size_of_buffer = 0;
static U32 wb_ptr_offset = 0;

#define GDI_WB_BUFFER_SIZE ((0x4000+4))

/*****************************************************************************
 * FUNCTION
 *  wb_init_working_buffer
 * DESCRIPTION
 *  initianlize bmp writer, fp < 0 if you want to specify buf and buf_size
 * PARAMETERS
 *  fp       [IN]   file handler
 * RETURNS
 *  S32, return GDI_SUCCEED if succeed 
 *****************************************************************************/
static S32 wb_init_working_buffer(FS_HANDLE fp, U8* buf, U32 buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    wb_file_handle = fp;
    wb_ptr_offset = 0;
    if (fp < 0) /* Specify the buf and buffer size */
    {
        GDI_ASSERT(buf != NULL);
        GDI_ASSERT(buf_size >0);
        wb_buffer = buf;
        wb_size_of_buffer = buf_size;
    }
    else
    {
        wb_size_of_buffer = GDI_WB_BUFFER_SIZE;
        wb_buffer = (U8*)gdi_alloc_ext_mem(wb_size_of_buffer);
        if (wb_buffer == NULL)
        {
           wb_size_of_buffer = 0;
           return GDI_IMAGE_ERR_MEMORY_NOT_AVAILABLE;
        }          
    }
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  wb_flush_data
 * DESCRIPTION
 *  write data from buffer to file
 * PARAMETERS
 *  void
 * RETURNS
 *  S32, return GDI_SUCCEED if succeed
 *****************************************************************************/
static S32 wb_flush_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(wb_file_handle >= 0);
    if (wb_ptr_offset != 0)
    {
        U32 write_len;
        S32 ret;

        ret = FS_Write(wb_file_handle, wb_buffer, wb_ptr_offset, &write_len);
        if (ret < 0)    return GDI_FAILED;
        wb_ptr_offset = 0;
    }

    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  wb_write
 * DESCRIPTION
 *  wirte data to buffer
 * PARAMETERS
 *  data       [IN]
 *  len        [IN]
 * RETURNS
 *  U32, return len
 *****************************************************************************/
static S32 wb_write(void *data, U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((wb_file_handle < 0) && (wb_ptr_offset == wb_size_of_buffer))
    {
        return GDI_FAILED;
    }
    
    for (i = 0 ; i < len ; i++)
    {
        if (wb_ptr_offset > wb_size_of_buffer)
        {
            return GDI_FAILED;
        }
        wb_buffer[wb_ptr_offset++] = ((U8*)data)[i];
        if ((wb_ptr_offset == wb_size_of_buffer) && (wb_file_handle >= 0))
        {
            wb_flush_data();
        }
    }

    return len;
}


/*****************************************************************************
 * FUNCTION
 *  wb_deinit_working_buffer
 * DESCRIPTION
 *  deinit bmp writer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wb_deinit_working_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (wb_buffer != NULL)
    {
        gdi_free_ext_mem((void**)&wb_buffer);
    }

    wb_file_handle = 0;
    wb_buffer = NULL;
    wb_size_of_buffer = 0;
    wb_ptr_offset = 0;
}


typedef S32 (*gd_bmp_write_pixel_func) (U8 r, U8 g, U8 b);

/*****************************************************************************
 * FUNCTION
 *  gd_bmp_write_pixel_16
 * DESCRIPTION
 *  put 16-bits pixel
 * PARAMETERS
 *  r       [IN]    red
 *  g       [IN]    green
 *  b       [IN]    blue
 * RETURNS
 *  void
 *****************************************************************************/
static S32 gd_bmp_write_pixel_16(U8 r, U8 g, U8 b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 data = ((r & 0xf8) << 7) | ((g & 0xf8) << 2) | ((b & 0xf8) >> 3);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return wb_write(&data, 2*sizeof(U8));
}


/*****************************************************************************
 * FUNCTION
 *  gd_bmp_write_pixel_24
 * DESCRIPTION
 *  put 24-bits pixel
 * PARAMETERS
 *  r       [IN]    red
 *  g       [IN]    green 
 *  b       [IN]    blue
 * RETURNS
 *  void
 *****************************************************************************/
static S32 gd_bmp_write_pixel_24(U8 r, U8 g, U8 b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 data = (r << 16) | (g << 8) | b;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return wb_write(&data, 3*sizeof(U8));
}


/*****************************************************************************
 * FUNCTION
 *  gd_bmp_write_pixel_32
 * DESCRIPTION
 *  put 32-bits pixel
 * PARAMETERS
 *  r       [IN]    red
 *  g       [IN]    green 
 *  b       [IN]    blue
 * RETURNS
 *  void
 *****************************************************************************/
static S32 gd_bmp_write_pixel_32(U8 r, U8 g, U8 b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 data = 0xff000000 | (r << 16) | (g << 8) | b;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return wb_write(&data, 4*sizeof(U8));
}

const static gd_bmp_write_pixel_func gd_bmp_write_pixel[] = 
{
    NULL,                   /* 1  */
    NULL,                   /* 8  */
    gd_bmp_write_pixel_16,  /* 16 */
    gd_bmp_write_pixel_24,  /* 24 */
    gd_bmp_write_pixel_32   /* 32 */
};

/*****************************************************************************
 * FUNCTION
 *  gdi_image_bmp_encode_get_size
 * DESCRIPTION
 *  get the buffer size needed when bmp encode
 * PARAMETERS
 *  width           [IN]    encode width
 *  height          [IN]    encode height
 *  depth           [IN]    bits per pixel
 *  bmp_size        [OUT]   the buffer size needed when bmp encode
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_bmp_encode_get_size(
                S32 width, 
                S32 height, 
                U8  depth,
                S32 *bmp_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 bytePerLine;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_bmp_encode_get_size);
    if (depth == 2)
    {
        bytePerLine = 2 * (width + width % 2);
    }
    else if (depth == 3)
    {
        bytePerLine = 4 * ((width * 24 + 31) / 32);
    }
    else
    {
        *bmp_size = 0;
        GDI_RETURN(GDI_FAILED);
    }

    *bmp_size = bytePerLine * height + 54;
    
    GDI_EXIT_CRITICAL_SECTION(gdi_image_bmp_encode_get_size)
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_bmp_encode_mem
 * DESCRIPTION
 *  encode layer data to memory
 * PARAMETERS
 *  width           [IN]    encode width
 *  height          [IN]    encode height
 *  depth           [IN]    bits per pixel
 *  buf_ptr         [IN]    source memory address
 *  output_mem          [IN]    output memory buffer pointer
 *  output_mem_size     [IN]    output memory buffer size
 *  encode_data_size    [OUT]   result bmp data size
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_bmp_encode_mem(
                S32 width, 
                S32 height, 
                U8  depth,
                PU8 buf_ptr,
                U8  *output_mem,
                S32 output_mem_size,
                S32 *encode_data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 write_len;
    BITMAP_HEADER image_header;
    U16 bpp = 0;
    S32 ret = 0, i, j;
    gd_color_to_rgb_func color_to_rgb;
    gd_get_buf_pixel_func get_buf_pixel;
    gd_bmp_write_pixel_func write_pixel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	GDI_ENTER_CRITICAL_SECTION(gdi_image_bmp_encode_mem)
	
        do
        {
            gdi_image_bmp_encode_get_size(width, height, depth, &write_len);
            if (write_len > output_mem_size)
            {
                ret = GDI_IMAGE_ERR_IMAGE_TOO_LARGE;
                break;
            }

            ret = wb_init_working_buffer(-1, output_mem, output_mem_size);
            if (ret != GDI_SUCCEED)
            {
                break;
            }

            /* decide bpp */
            bpp = depth << 3;
            if ((depth != 2) && (depth != 3))
            {
                bpp = 16;
            }
            
            /* write bmp header */
            memset((void*)&image_header, 0, sizeof(BITMAP_HEADER)); /* use void* to case for packed struct */
            image_header.signature = 19778;
            image_header.size = width * height * (bpp >> 3) + 54;
            image_header.image_offset = 54;
            image_header.size_of_bmpinfoheader = 40;
            image_header.width = width;
            image_header.height = height;
            image_header.planes = 1;
            image_header.bpp = bpp;
            image_header.compression = 0;
            image_header.size_of_image = width * height * (bpp >> 3);

            ret = wb_write((void*)&image_header, sizeof(BITMAP_HEADER));
            if (ret < 0)
            {
                break;
            }

            /* set color transfer function */
            get_buf_pixel = gd_get_buf_pixel[depth];
            color_to_rgb = gd_color_to_rgb[depth];
            write_pixel = gd_bmp_write_pixel[(bpp >> 3)];
            
            for (j = (height - 1) ; j >= 0 ; j--)  /* from bottom to up */
            {
                for (i = 0 ; i < width ; i++)
                {
                    U32 c = 0, a = 0, r = 0, g = 0, b = 0;

                    c = get_buf_pixel(buf_ptr, width, i, j);
                    color_to_rgb(&a, &r, &g, &b, c);
                    ret = write_pixel((U8)r, (U8)g, (U8)b);
                    if (ret < 0)
                    {
                        *encode_data_size = 0;
                        wb_deinit_working_buffer();
                        GDI_RETURN(GDI_FAILED);
                    }
                }

                /* padding if necessary */
                {
                    U32 padding = 0;
                    U32 bytePerLine;
                    S32 padding_len;

                    if (bpp == 16)
                    {
                        bytePerLine = 2 * (width + width % 2);
                        padding_len = bytePerLine - width * 2;
                    }
                    else if (bpp == 24)
                    {
                        bytePerLine = 4 * ((width * 24 + 31) / 32);
                        padding_len = bytePerLine - width * 3;
                    }
                    else
                    {
                        *encode_data_size = 0;
                        wb_deinit_working_buffer();
                        GDI_RETURN(GDI_FAILED);
                    }
                    
                    ret = wb_write(&padding, padding_len);
                    if (ret < 0)
                    {
                        *encode_data_size = 0;
                        wb_deinit_working_buffer();
                        GDI_RETURN(GDI_FAILED);
                    }
                }
            }
            
            *encode_data_size = wb_ptr_offset;
            wb_deinit_working_buffer();
            
            ret = GDI_SUCCEED;
        } while (0);


	GDI_EXIT_CRITICAL_SECTION(gdi_image_bmp_encode_mem)
        
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_bmp_encode_file
 * DESCRIPTION
 *  encode bmp file
 * PARAMETERS
 *  width           [IN]    encode width
 *  height          [IN]    encode height
 *  cf              [IN]    color format
 *  buf_ptr         [IN]    source memory address
 *  file_name       [IN]    output filename
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_bmp_encode_file(S32 width, S32 height, gdi_color_format cf, PU8 buf_ptr, PS8 file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE bmp_file_handle;
    U32 write_len;
    BITMAP_HEADER image_header;
    U16 bpp = 24;
    S32 ret = 0, i, j;
    gd_color_to_rgb_func color_to_rgb;
    gd_get_buf_pixel_func get_buf_pixel;
    gd_bmp_write_pixel_func write_pixel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	GDI_ENTER_CRITICAL_SECTION(gdi_image_bmp_encode_file)
	
        /* open file */
        bmp_file_handle = FS_Open((WCHAR*)file_name, FS_CREATE_ALWAYS);
        if (bmp_file_handle < 0)    GDI_RETURN(GDI_IMAGE_ERR_OPEN_FILE_FAILED);

        do
        {
            /* write bmp header */
            memset((void*)&image_header, 0, sizeof(BITMAP_HEADER)); /* use void* to case for packed struct */
            image_header.signature = 19778;
            image_header.size = width * height * (bpp >> 3) + 54;
            image_header.image_offset = 54;
            image_header.size_of_bmpinfoheader = 40;
            image_header.width = width;
            image_header.height = height;
            image_header.planes = 1;
            image_header.bpp = bpp;
            image_header.compression = 0;
            image_header.size_of_image = width * height * (bpp >> 3);

            ret = FS_Write(bmp_file_handle, (void*)&image_header, sizeof(BITMAP_HEADER), &write_len);
            if (ret < 0)    break;

            /* set color transfer function */
            get_buf_pixel = gd_get_buf_pixel[cf];
            color_to_rgb = gd_color_to_rgb[cf];
            write_pixel = gd_bmp_write_pixel[(bpp >> 3)];

            ret = wb_init_working_buffer(bmp_file_handle, NULL, 0); 
            if (ret != GDI_SUCCEED)
            {
                break;
            }
            
            for (j = (height - 1) ; j >= 0 ; j--)  /* from bottom to up */
            {
                for (i = 0 ; i < width ; i++)
                {
                    U32 c = 0, a = 0, r = 0, g = 0, b = 0;

                    c = get_buf_pixel(buf_ptr, width, i, j);
                    color_to_rgb(&a, &r, &g, &b, c);
                    write_pixel((U8)r, (U8)g, (U8)b);
                }

                /* padding if necessary */
                {
                    U32 padding = 0;
                    U32 bytePerLine = 4 * ((width * bpp + 31) / 32);
                    S32 padding_len = bytePerLine - width * 3;
                    
                    wb_write(&padding, padding_len);
                }
            }
            wb_flush_data();
            wb_deinit_working_buffer();
            
            ret = GDI_SUCCEED;
        } while (0);

        FS_Close(bmp_file_handle);
	GDI_EXIT_CRITICAL_SECTION(gdi_image_bmp_encode_file)

    return ret;
}


