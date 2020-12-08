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
 *  gdi_image_bmp_codec.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI BMP codec macro
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "kal_release.h"
#include "kal_general_types.h"
#include "kal_trace.h"

#include "setjmp.h"
#include "iul_rng.h"
#include "iul_spatial_dithering.h"
#include "drv_comm.h"
#include "lcd_if.h"

#include "MMIDataType.h"
#include "MMI_fw_trc.h"
#include "DebugInitDef_Int.h"

#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gdi_include.h"
#include "gdi_bytestream.h"
#include "gdi_internal.h"
#include "gdi_image_bmp.h"
#include "gdi_primitive.h"
#include "gdi_mutex.h"
#include "gdi_image_gif.h"
#include "gdi_image.h"
#include "gdi_layer.h"
#include "gdi_features.h"
#include "gd_include.h"

#undef GDI_RESIZER_PUT
#undef GDI_RESIZER_PUT_PIXEL
#undef GDI_RESIZER_INCREASE_DEST

#ifndef GDI_IMAGE_BMP_USING_RESIZER
#if GDI_IMAGE_BMP_CODEC_COLOR_FORMAT == GDI_COLOR_FORMAT_8
#define GDI_RESIZER_PUT_PIXEL(COLOR)         *((U8*)GDI_RESIZER.dest) = (U8)COLOR
#define GDI_RESIZER_INCREASE_DEST            GDI_RESIZER.dest ++
#define GDI_RESIZER_PUT(COLOR,WANT_DRAW)     GDI_NON_RESIZER_PUT_X(COLOR,WANT_DRAW)
#elif GDI_IMAGE_BMP_CODEC_COLOR_FORMAT==GDI_COLOR_FORMAT_16

#if defined(GDI_USE_RGB565_TO_SHOW_BW)
#define GDI_RESIZER_PUT_PIXEL(COLOR)         GDI_SET_BUFFER_PIXEL_1((GDI_RESIZER.offset_dx + GDI_RESIZER.want_sx),(GDI_RESIZER.offset_dy + GDI_RESIZER.want_sy),COLOR)
#define GDI_RESIZER_INCREASE_DEST
#define GDI_RESIZER_PUT(COLOR,WANT_DRAW)     GDI_NON_RESIZER_PUT_X(COLOR,WANT_DRAW)
#else
#define GDI_RESIZER_PUT_PIXEL(COLOR)         *((U16*)GDI_RESIZER.dest) = (U16)COLOR
#define GDI_RESIZER_INCREASE_DEST            GDI_RESIZER.dest +=2
#define GDI_RESIZER_PUT(COLOR,WANT_DRAW)     GDI_NON_RESIZER_PUT_X(COLOR,WANT_DRAW)
#endif

#elif GDI_IMAGE_BMP_CODEC_COLOR_FORMAT==GDI_COLOR_FORMAT_24
#define GDI_RESIZER_PUT_PIXEL(COLOR)                       \
         do                                                      \
         {                                                       \
            U32 *ptr = (U32*)(GDI_RESIZER.dest);                 \
            switch(((U32)ptr)&0x3)                               \
            {                                                    \
            case 0:                                              \
               *ptr = (*ptr&0xff000000)|(COLOR&0x00ffffff);      \
               break;                                            \
            case 1:                                              \
               ptr= (U32*)(((U32)ptr)&(~0x3));                   \
               *ptr = (*ptr&0x000000ff)|(COLOR<<8);              \
               break;                                            \
            case 2:                                              \
               ptr= (U32*)(((U32)ptr)&(~0x3));                   \
               *ptr = (*ptr&0x0000ffff)|(COLOR<<16); ptr++;      \
               *ptr = (*ptr&0xffffff00)|((COLOR&0x00ff0000)>>16);\
               break;                                            \
            default:                                             \
               ptr= (U32*)(((U32)ptr)&(~0x3));                   \
               *ptr = (*ptr&0x00ffffff)|(COLOR<<24); ptr++;      \
               *ptr = (*ptr&0xffff0000)|((COLOR&0x00ffff00)>>8); \
            }                                                    \
         }while(0)

#define GDI_RESIZER_INCREASE_DEST            GDI_RESIZER.dest +=3
#define GDI_RESIZER_PUT(COLOR,WANT_DRAW)     GDI_NON_RESIZER_PUT_X(COLOR,WANT_DRAW)
#elif GDI_IMAGE_BMP_CODEC_COLOR_FORMAT==GDI_COLOR_FORMAT_32
#define GDI_RESIZER_PUT_PIXEL(COLOR)         *((U32*)GDI_RESIZER.dest) = (U32)COLOR
#define GDI_RESIZER_INCREASE_DEST            GDI_RESIZER.dest +=4
#define GDI_RESIZER_PUT(COLOR,WANT_DRAW)     GDI_NON_RESIZER_PUT_X(COLOR,WANT_DRAW)
#elif GDI_IMAGE_BMP_CODEC_COLOR_FORMAT==GDI_COLOR_FORMAT_MAINLCD
#define GDI_RESIZER_PUT_PIXEL(COLOR)         DRV_MAINLCD_SET_BUFFER_PIXEL((GDI_RESIZER.offset_dx + GDI_RESIZER.want_sx),(GDI_RESIZER.offset_dy + GDI_RESIZER.want_sy),COLOR)
#define GDI_RESIZER_INCREASE_DEST
#define GDI_RESIZER_PUT(COLOR,WANT_DRAW)     GDI_NON_RESIZER_PUT_X(COLOR,WANT_DRAW)
#elif GDI_IMAGE_BMP_CODEC_COLOR_FORMAT==GDI_COLOR_FORMAT_SUBLCD
#define GDI_RESIZER_PUT_PIXEL(COLOR)         DRV_SUBLCD_SET_BUFFER_PIXEL((GDI_RESIZER.offset_dx + GDI_RESIZER.want_sx),(GDI_RESIZER.offset_dy + GDI_RESIZER.want_sy),COLOR)
#define GDI_RESIZER_INCREASE_DEST
#define GDI_RESIZER_PUT(COLOR,WANT_DRAW)     GDI_NON_RESIZER_PUT_X(COLOR,WANT_DRAW)
#else 
#error "WE didn't support this color format "
#endif 

#else /* GDI_IMAGE_BMP_USING_RESIZER */ 
#define GDI_RESIZER_PUT(COLOR,WANT_DRAW)     gdi_resizer_put(COLOR,WANT_DRAW)
#endif /* GDI_IMAGE_BMP_USING_RESIZER */ 

#undef MY_GET_U8
#undef MY_FLUSH

#ifdef SUPPORT_BMP_COMPRESSION
#define COMPRESSION_MODE(n,width,height) \
   do                                    \
   {                                     \
      gdi_image_bmp_compression = n;     \
      gdi_image_bmp_src_x = 0;           \
      gdi_image_bmp_src_y = height-1;    \
      gdi_image_bmp_run_length = 0;      \
      gdi_image_bmp_run_length_odd = 0;  \
   }while(0)


/*****************************************************************************
 * FUNCTION
 *  GET_U8_FROM_RUN_LENGTH
 * DESCRIPTION
 *  Get a byte
 * PARAMETERS
 *  src       [IN]  srouce address
 *  sx        [IN]  not used
 *  sy        [IN]  not used
 * RETURNS
 *  U8, return the get value
 *****************************************************************************/
U8 GET_U8_FROM_RUN_LENGTH(U8** src,S32 sx, S32 sy, S32 image_width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static BOOL is_raw_mode = FALSE;
    U8 ret_value = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gdi_image_bmp_run_length <= 0)
    {
        GET_U8((*src),gdi_image_bmp_run_length);
        
        if (gdi_image_bmp_run_length > 0)  /* encoded mdoe */
        {
            is_raw_mode = FALSE;
            gdi_image_bmp_run_length_used = 0;
            GET_U8((*src),gdi_image_bmp_code);
        }
        else    /* escape mode */
        {
            is_raw_mode = TRUE;
            GET_U8((*src),gdi_image_bmp_run_length);
            switch (gdi_image_bmp_run_length)
            {
                case 1:
                    gdi_image_bmp_src_y = -1;
                    gdi_image_bmp_run_length = 0;
                    GDI_TRACE(GDI_TRC, GDI_TRC_41//"GDI_BMP_EXCEPTION_ESCAPE_MODE_END_OF_BITMAP"
                                            );
  
                    GDI_RAISE(GDI_BMP_EXCEPTION_ESCAPE_MODE_END_OF_BITMAP);
                    return 0;
                case 0: /* end of line */
                    gdi_image_bmp_src_x = 0;
                    gdi_image_bmp_src_y--;
                    gdi_image_bmp_run_length = 0;
                    return 0;
                case 2: /* delta mode */
                {
                    U8 dx, dy;

                    GET_U8((*src),dx);
                    GET_U8((*src),dy);
                    gdi_image_bmp_src_x += dx;
                    gdi_image_bmp_src_y -= dy;
                }
                    gdi_image_bmp_run_length = 0;
                    return 0;
                default:    /* abolutte */
					//decode should not consider output width
                    gdi_image_bmp_run_length_used = 0;
                    break;
            }
        }
    }

    if (is_raw_mode)
    {
        if (gdi_image_bmp_compression == GDI_BI_RLE8)
        {
            GET_U8((*src),ret_value);
        }
        else
        {
            GET_U8((*src),gdi_image_bmp_code);
            ret_value = gdi_image_bmp_code;
            gdi_image_bmp_src_x++;
            gdi_image_bmp_run_length--;
            gdi_image_bmp_run_length_used++;
        }

        if ((gdi_image_bmp_compression == GDI_BI_RLE4) && (gdi_image_bmp_run_length == 0))
        {
            gdi_image_bmp_run_length_odd = 1;
        }

        gdi_image_bmp_run_length--;
        gdi_image_bmp_run_length_used++;

        if (gdi_image_bmp_run_length_odd == 0)
        {
            ++gdi_image_bmp_src_x;
        }

        if (gdi_image_bmp_run_length <= 0)  /* read pad byte. */
        {
            if (gdi_image_bmp_compression == GDI_BI_RLE8)
            {
                if (gdi_image_bmp_run_length_used & 1)
                {
                    FLUSH((*src),1);
                }
            }
            else
            {
                if ((gdi_image_bmp_run_length_used & 0x03) == 1 || (gdi_image_bmp_run_length_used & 0x03) == 2)
                {
                    FLUSH((*src),1);
                }
            }
        }
    }
    else
    {
        if (gdi_image_bmp_compression == GDI_BI_RLE8)
        {
            ret_value = gdi_image_bmp_code;
        }
        else
        {
            ret_value = gdi_image_bmp_code;
            gdi_image_bmp_run_length--;
            gdi_image_bmp_run_length_used++;
            ++gdi_image_bmp_src_x;
        }

        if ((gdi_image_bmp_compression == GDI_BI_RLE4) && (gdi_image_bmp_run_length == 0))
        {
            gdi_image_bmp_run_length_odd = 1;
        }

        gdi_image_bmp_run_length--;
        gdi_image_bmp_run_length_used++;

        if (gdi_image_bmp_run_length_odd == 0)
        {
            ++gdi_image_bmp_src_x;
        }
        if (gdi_image_bmp_src_x > (image_width+1))
        {
            GDI_RAISE(1);// invalid format
        }
    }
    return ret_value;
}

#define MY_GET_U8(SRC,X)                                \
   {                                                    \
      if(gdi_image_bmp_compression == GDI_BI_RLE4       \
      ||gdi_image_bmp_compression == GDI_BI_RLE8)       \
      {                                                 \
         while(1)                                       \
         {                                              \
            if(gdi_image_bmp_src_y >=pos_y)             \
            {                                           \
               if(gdi_image_bmp_src_y> pos_y            \
               ||gdi_image_bmp_src_x<= pos_x)           \
                  X=GET_U8_FROM_RUN_LENGTH(&(SRC),pos_x,pos_y, bmp_infoheader.biWidth);\
               else                                     \
                  break;                                \
            }                                           \
            else                                        \
               break;                                   \
         }                                              \
      }                                                 \
      else                                              \
      {                                                 \
         GET_U8(SRC,X)                                  \
      }                                                 \
   }

#define MY_FLUSH(SRC,X)                             \
   {                                                \
      if(gdi_image_bmp_compression==GDI_BI_RGB      \
      ||gdi_image_bmp_compression==GDI_BI_BITFIELDS)\
      {                                             \
         FLUSH(SRC,X);                              \
      }                                             \
   }

#else
    #define COMPRESSION_MODE(n,width,height)
    #define MY_GET_U8(SRC,X)                        GET_U8(SRC,X)
    #define MY_FLUSH(SRC,X)                         FLUSH(SRC,X)
#endif 

#ifdef GDI_IMAGE_BMP_GET_DIMENSION_INTERNAL
/*****************************************************************************
 * FUNCTION
 *  GDI_IMAGE_BMP_GET_DIMENSION_INTERNAL
 * DESCRIPTION
 *  get dimension of a bmp from memory
 * PARAMETERS
 *  BMP_src     [IN]        source image
 *  width       [OUT]       return image width
 *  height      [OUT]       return image height
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT GDI_IMAGE_BMP_GET_DIMENSION_INTERNAL(U8 *BMP_src, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    U32 bfSize;
    U32 biWidth;
    U32 biHeight;
    U32 biSize;
    U8* src;
    GDI_RESULT ret = GDI_SUCCEED;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_bmp_get_dimension) U16 bfType;
    
    GDI_UNUSED(src);
    INIT_SRC(src, BMP_src);

    GDI_DEBUG_ASSERT(BMP_src != NULL);
    COMPRESSION_MODE(0, 0, 0);  /* reset the compression mode */

    /* read file header */
    GET_U16(src, bfType) GET_U32(src, bfSize) MY_FLUSH(src, 8);
    /* read info header */
    GET_U32(src, biSize);
    if (biSize == 12)
    {
    GET_U16(src, biWidth) GET_U16(src, biHeight)}
    else
    {
    GET_U32(src, biWidth) GET_U32(src, biHeight)}

    *width = biWidth;
    *height = biHeight;

    /* test if it is BMP file */
    if (bfType != 0x4d42)   /* BM */
    {
        ret = GDI_FAILED;
    }

    GDI_EXIT_CRITICAL_SECTION(gdi_image_bmp_get_dimension)
    return ret;
}
#endif /* GDI_IMAGE_BMP_GET_DIMENSION_INTERNAL */ 

/*****************************************************************************
 * FUNCTION
 *  GDI_IMAGE_BMP_DRAW_INTERNAL
 * DESCRIPTION
 *  
 * PARAMETERS
 *  offset_x            [IN]        
 *  offset_y            [IN]        
 *  is_resized          [IN]        
 *  resized_width       [IN]        
 *  resized_height      [IN]        
 *  BMP_src             [?]         
 *  size                [IN]        
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT GDI_IMAGE_BMP_DRAW_INTERNAL(
            S32 offset_x,
            S32 offset_y,
            BOOL is_resized,
            S32 resized_width,
            S32 resized_height,
            U8 *BMP_src,
            U32 size,
            BOOL transparent_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(GDI_IMAGE_BMP_DRAW_INTERNAL) 
    bitmap_file_header bmp_fileheader;
    bitmap_info_header bmp_infoheader;
    U32 paletteSize;
    U8 r = 0, g = 0, b = 0, a = 0;
    S32 i, j;
    U32 bytePerLine;
    S32 dataCount;
    U32 dummyCount;
    S32 pos_x = 0, pos_y = 0;
    U8 tmp_byte = 0;
    gdi_color *palette = gdi_gif_local_palette;
    gdi_color replace_source_key = 0;
    int jump = 0;
    U32 c = 0;
    U32 is_standard_output;
    U8* src;
    S32 resizer_init_ret = 1;
    S32 time_out_check = 0;

#ifdef SUPPORT_BMP_COMPRESSION
    S32 r_mask = 0;
    S32 g_mask = 0;
    S32 b_mask = 0;
    S32 r_shift = 0;
    S32 g_shift = 0;
    S32 b_shift = 0;
    S32 r_bits = 0;
    S32 g_bits = 0;
    S32 b_bits = 0;
#endif /* SUPPORT_BMP_COMPRESSION */ 

    #if defined(GDI_USING_DITHERING)
    IUL_SD_INITIALIZE();
    #endif
    
    INIT_SRC(src, BMP_src);

    GDI_DEBUG_ASSERT(BMP_src != NULL);
    COMPRESSION_MODE(0, 0, 0);  /* reset the compression mode */

    is_standard_output = (gdi_image_codec_get_flag()&(GDI_IMAGE_CODEC_FLAG_IS_FILE|GDI_IMAGE_CODEC_FLAG_IS_MEM))?1:0;
    /* read file header */
    GET_U16(src, bmp_fileheader.bfType)
    GET_U32(src, bmp_fileheader.bfSize)
    GET_U16(src, bmp_fileheader.bfReserved1)
    GET_U16(src, bmp_fileheader.bfReserved2)
    GET_U32(src, bmp_fileheader.bfOffBits)
    /* test if it is BMP file */
    if (bmp_fileheader.bfType != 0x4d42)    /* BM */
    {
        GDI_RETURN(GDI_FAILED);
    }

    if (bmp_fileheader.bfReserved1 != 0 || bmp_fileheader.bfReserved2 != 0)
    {
        GDI_RETURN(GDI_FAILED);
    }

    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

    /* read info header */
    GET_U32(src, bmp_infoheader.biSize) 
    if (bmp_infoheader.biSize == 12)        /* OS/2 bmp format */
    {
        GET_U16(src, bmp_infoheader.biWidth)
        GET_U16(src, bmp_infoheader.biHeight)
        GET_U16(src, bmp_infoheader.biPlanes)
        GET_U16(src, bmp_infoheader.biBitCount) 
        bmp_infoheader.biCompression = GDI_BI_RGB;

        bmp_infoheader.biSizeImage = 0;
        bmp_infoheader.biXPelsPerMeter = 0;
        bmp_infoheader.biYPelsPerMeter = 0;
        bmp_infoheader.biClrUsed = 0;
        bmp_infoheader.biClrImportant = 0;

    }
    else    /* microsoft windows bmp format */
    {
        if (bmp_infoheader.biSize < 40)
        {
            GDI_RETURN(GDI_FAILED);
        }

        GET_U32(src, bmp_infoheader.biWidth)
        GET_U32(src, bmp_infoheader.biHeight)
        GET_U16(src, bmp_infoheader.biPlanes)
        GET_U16(src, bmp_infoheader.biBitCount)
        GET_U32(src, bmp_infoheader.biCompression)
        GET_U32(src, bmp_infoheader.biSizeImage)
        GET_U32(src, bmp_infoheader.biXPelsPerMeter)
        GET_U32(src, bmp_infoheader.biYPelsPerMeter)
        GET_U32(src, bmp_infoheader.biClrUsed) 
        GET_U32(src, bmp_infoheader.biClrImportant)
    }

    if (bmp_infoheader.biWidth <= 0 
    || bmp_infoheader.biHeight <= 0 
    || (bmp_infoheader.biCompression != GDI_BI_RGB
    #ifdef SUPPORT_BMP_COMPRESSION
    && bmp_infoheader.biCompression != GDI_BI_RLE8
    && bmp_infoheader.biCompression != GDI_BI_RLE4
    && bmp_infoheader.biCompression != GDI_BI_BITFIELDS
    #endif
    ))
        GDI_RETURN(GDI_FAILED);

    //comment out due to MA will check the file size
    //if ((bmp_infoheader.biWidth > 8192) || (bmp_infoheader.biHeight > 8192))
    //{
    //    GDI_RETURN(GDI_FAILED); /* GDI_BMP_ERR_FILE_TOO_LARGE */
    //}

    // setup resizer
    // If resized width > original width or resized height > original height, do not resize
    if (!is_resized || resized_width > (S32) bmp_infoheader.biWidth || resized_height > (S32) bmp_infoheader.biHeight)
    {
        resized_width = bmp_infoheader.biWidth;
        resized_height = bmp_infoheader.biHeight;
    }

    // check resized_width/resized_height will cause divide by zero
    if (resized_width == 0 || resized_height == 0)
    {
        return (GDI_SUCCEED);
    }

    resizer_init_ret = gdi_resizer_init(
                        bmp_infoheader.biWidth,
                        bmp_infoheader.biHeight,
                        0,
                        0,
                        bmp_infoheader.biWidth - 1,
                        bmp_infoheader.biHeight - 1,
                        offset_x,
                        offset_y + resized_height - 1,
                        offset_x + resized_width - 1,
                        offset_y);
    if (resizer_init_ret == 0)
    {
        /* no pixel to output */
        GDI_RETURN(GDI_SUCCEED);
    }
    else if (resizer_init_ret < 0)
    {
        /* decode limitation, output width too large */
        GDI_RETURN(GDI_FAILED);
    }

    if (gdi_act_layer_info->source_key_enable)
    {
        replace_source_key = gdi_act_layer_info->source_key ^ 1;
    }
    /* setup palette */
    gdi_image_bmp_palette_size = 0;
    
    if (bmp_infoheader.biBitCount <= 8)
    {
        gd_color_from_rgb_func palette_color_from_rgb;

        paletteSize = 1 << (bmp_infoheader.biBitCount);
        if (bmp_infoheader.biClrUsed != 0 && bmp_infoheader.biClrUsed < paletteSize)
        {
            paletteSize = bmp_infoheader.biClrUsed;
            gdi_image_bmp_palette_size = paletteSize;
        }

        if (gdi_act_layer->vcf == GDI_COLOR_FORMAT_8)
        {
            palette_color_from_rgb = GDI_PALETTE_COLOR_FROM_RGB;
        }
        else
        {
            palette_color_from_rgb = gdi_act_color_from_rgb;
        }

        /* read palette */
        for (i = 0; i < (S32) paletteSize; i++)
        {
            MY_GET_U8(src, b);
            MY_GET_U8(src, g);
            MY_GET_U8(src, r);
            if (bmp_infoheader.biSize != 12)        /* OS/2 bmp format */
            {
                MY_GET_U8(src, a);
            }
            palette[i] = palette_color_from_rgb(255, r, g, b);

            if (palette[i] == gdi_act_layer_info->source_key && gdi_act_layer_info->source_key_enable)
            {
                palette[i] ^= 1;
            }
        }

        /* current layer is index color layer */
        if (gdi_act_layer->vcf == GDI_COLOR_FORMAT_8)
            for (i = 0; i < (S32) paletteSize; i++)
            {
                gdi_layer_set_palette((U8) i, palette[i]);
                palette[i] = i;
            }
    }

#ifdef SUPPORT_BMP_COMPRESSION
    if (bmp_infoheader.biCompression == GDI_BI_BITFIELDS &&
        (bmp_infoheader.biBitCount == 16 || bmp_infoheader.biBitCount == 32))
    {
        U32 tmp;

        GET_U32(src, r_mask);
        GET_U32(src, g_mask);
        GET_U32(src, b_mask);

        tmp = r_mask;
        for (r_shift = 0;; r_shift++, tmp >>= 1)
            if ((tmp & 1) || (tmp == 0))
            {
                break;
            }
        for (r_bits = 0;; r_bits++, tmp >>= 1)
            if (!(tmp & 1))
            {
                break;
            }
        r_bits = 8 - r_bits;

        tmp = g_mask;
        for (g_shift = 0;; g_shift++, tmp >>= 1)
            if ((tmp & 1) || (tmp == 0))
            {
                break;
            }
        for (g_bits = 0;; g_bits++, tmp >>= 1)
            if (!(tmp & 1))
            {
                break;
            }
        g_bits = 8 - g_bits;

        tmp = b_mask;
        for (b_shift = 0;; b_shift++, tmp >>= 1)
            if ((tmp & 1) || (tmp == 0))
            {
                break;
            }
        for (b_bits = 0;; b_bits++, tmp >>= 1)
            if (!(tmp & 1))
            {
                break;
            }
        b_bits = 8 - b_bits;
    }
#endif /* SUPPORT_BMP_COMPRESSION */ 
    /* calculate bytePerLine, for latter to skip stuffing byte */
    bytePerLine = 4 * ((bmp_infoheader.biWidth * bmp_infoheader.biBitCount + 31) / 32);

    if (bmp_infoheader.biSizeImage == 0)
    {
        bmp_infoheader.biSizeImage = bytePerLine * bmp_infoheader.biHeight;
        dataCount = (S32) bmp_infoheader.biSizeImage;
    }
    else
    {
        dataCount = (S32) bytePerLine *bmp_infoheader.biHeight;
    }

    /* seek to start of draw data */
    SEEK(src, BMP_src, bmp_fileheader.bfOffBits);

    pos_x = offset_x;
    pos_y = offset_y + bmp_infoheader.biHeight - 1;
    /* 8 bit color, use palette */

    COMPRESSION_MODE(bmp_infoheader.biCompression, bmp_infoheader.biWidth, bmp_infoheader.biHeight);

    switch (bmp_infoheader.biBitCount)
    {
        case 8:
            jump = 0;
            if (bmp_infoheader.biCompression == GDI_BI_RLE8 || bmp_infoheader.biCompression == GDI_BI_RLE4)
            {
                bytePerLine = bmp_infoheader.biWidth;
            }

            dummyCount = bytePerLine - bmp_infoheader.biWidth;
            for (pos_y = bmp_infoheader.biHeight - 1; pos_y >= 0; pos_y--)
            {
                if(!gdi_image_progress_callback()) 
                    GDI_RAISE(GDI_IMAGE_ERR_DECODE_TIME_OUT);
                
                time_out_check = 0;
                for (pos_x = 0; pos_x < (S32) (S32) bmp_infoheader.biWidth; pos_x++)
                {
                    if (time_out_check == 1000)
                    {
                        if(!gdi_image_progress_callback())
                        {
                            GDI_RAISE(GDI_IMAGE_ERR_DECODE_TIME_OUT);
                        }
                        time_out_check = 0;
                    }
                    if (IS_GDI_RESIZER_WANT_DRAW(pos_x, pos_y))
                    {
                        if (jump)
                        {
                            MY_FLUSH(src, jump);
                            jump = 0;
                        }
                        MY_GET_U8(src, c);
                        if(is_standard_output || (transparent_enable == FALSE))
                            GDI_RESIZER_PUT(palette[c], TRUE);
                        else
                            GDI_RESIZER_PUT(palette[c], (BOOL) (c != 0));
                    }
                    else
                    {
                        jump++;
                    }
                    time_out_check++;
                }
                jump += dummyCount;
            }
            break;
        case 16:
            jump = 0;
            bytePerLine = 2 * (bmp_infoheader.biWidth + bmp_infoheader.biWidth % 2);
            dummyCount = bytePerLine - bmp_infoheader.biWidth * 2;
            for (pos_y = bmp_infoheader.biHeight - 1; pos_y >= 0; pos_y--)
            {
                if(!gdi_image_progress_callback()) 
                    GDI_RAISE(GDI_IMAGE_ERR_DECODE_TIME_OUT);

                time_out_check = 0;
                for (pos_x = 0; pos_x < (S32) bmp_infoheader.biWidth; pos_x++)
                {
                    if (time_out_check == 1000)
                    {
                        if(!gdi_image_progress_callback())
                        {
                            GDI_RAISE(GDI_IMAGE_ERR_DECODE_TIME_OUT);
                        }
                        time_out_check = 0;
                    }
                    if (IS_GDI_RESIZER_WANT_DRAW(pos_x, pos_y))
                    {
                        gdi_color tmp_c;
                        if (jump)
                        {
                            MY_FLUSH(src, jump);
                            jump = 0;
                        }
                        GET_U16(src, c);    /* RGB 555 */
                    #ifdef SUPPORT_BMP_COMPRESSION

                        if (bmp_infoheader.biCompression == GDI_BI_BITFIELDS)
                        {
                            b = ((c & b_mask) >> b_shift) << b_bits;
                            g = ((c & g_mask) >> g_shift) << g_bits;
                            r = ((c & r_mask) >> r_shift) << r_bits;
                            a = 0x00;
                            a = ~a;
                        }
                        else
                    #endif /* SUPPORT_BMP_COMPRESSION */ 
                        {
                            b = (c & 0x1f) << 3;
                            g = ((c >> 5) & 0x1f) << 3;
                            r = ((c >> 10) & 0x1f) << 3;
                        }
                        tmp_c = gdi_act_color_from_rgb(0xFF, r, g, b);
                        if(is_standard_output
                        && gdi_act_layer_info->source_key_enable 
                        && gdi_act_layer_info->source_key == tmp_c)
                            GDI_RESIZER_PUT(replace_source_key, 1);
                        else
                            GDI_RESIZER_PUT(tmp_c, 1);
                    }
                    else
                    {
                        jump += 2;
                    }
                    time_out_check++;
                }
                jump += dummyCount;
            }
            break;

        case 24:
            jump = 0;
            bytePerLine = 4 * ((bmp_infoheader.biWidth * 24 + 31) / 32);
            dummyCount = bytePerLine - bmp_infoheader.biWidth * 3;
            for (pos_y = bmp_infoheader.biHeight - 1; pos_y >= 0; pos_y--)
            {
                if(!gdi_image_progress_callback()) 
                    GDI_RAISE(GDI_IMAGE_ERR_DECODE_TIME_OUT);

                time_out_check = 0;
                for (pos_x = 0; pos_x < (S32) bmp_infoheader.biWidth; pos_x++)
                {
                    if (time_out_check == 1000)
                    {
                        if(!gdi_image_progress_callback())
                        {
                            GDI_RAISE(GDI_IMAGE_ERR_DECODE_TIME_OUT);
                        }
                        time_out_check = 0;
                    }
                    if (IS_GDI_RESIZER_WANT_DRAW(pos_x, pos_y))
                    {
                        U32 c;
                        gdi_color tmp_c;

                        if (jump)
                        {
                            MY_FLUSH(src, jump);
                            jump = 0;
                        }
                        GET_U24(src, c);
                        b = c & 0xff;
                        g = (c >> 8) & 0xff;
                        r = (c >> 16) & 0xff;

                    #if defined(GDI_USING_DITHERING)
                        switch (gdi_image_bmp_dithering)
                        {
                            case GDI_IMAGE_BMP_DITHER_RGB565:
                                IUL_SD_RGB888_TO_RGB565(r, g, b, (&tmp_c));
                                break;
                            case GDI_IMAGE_BMP_DITHER_RGB8882BITS:
                                IUL_SD_RGB888_2BITS_DITHERING(b, g, r, ((U8*)(&tmp_c)));
                                break;
                            case GDI_IMAGE_BMP_DITHER_DISABLE:
                            default:
                                tmp_c = gdi_act_color_from_rgb(0xFF, r, g, b);
                                break;
                        }
                    #else
                        tmp_c = gdi_act_color_from_rgb(0xFF, r, g, b);
                    #endif
                    
                        if(is_standard_output
                        && gdi_act_layer_info->source_key_enable 
                        && gdi_act_layer_info->source_key == tmp_c)
                            GDI_RESIZER_PUT(replace_source_key, 1);
                        else
                            GDI_RESIZER_PUT(tmp_c, 1);
                    }
                    else
                    {
                        jump += 3;
                    }
                    
                    time_out_check++;
                }
                jump += dummyCount;
            }
            break;
        case 32:
            jump = 0;
            bytePerLine = 4 * (bmp_infoheader.biWidth);
            dummyCount = bytePerLine - bmp_infoheader.biWidth * 4;
            for (pos_y = bmp_infoheader.biHeight - 1; pos_y >= 0; pos_y--)
            {
                if(!gdi_image_progress_callback()) 
                    GDI_RAISE(GDI_IMAGE_ERR_DECODE_TIME_OUT);

                time_out_check = 0;
                for (pos_x = 0; pos_x < (S32) bmp_infoheader.biWidth; pos_x++)
                {
                    if (time_out_check == 1000)
                    {
                        if(!gdi_image_progress_callback())
                        {
                            GDI_RAISE(GDI_IMAGE_ERR_DECODE_TIME_OUT);
                        }
                        time_out_check = 0;
                    }
                    if (IS_GDI_RESIZER_WANT_DRAW(pos_x, pos_y))
                    {
                        gdi_color tmp_c;
                        if (jump)
                        {
                            MY_FLUSH(src, jump);
                            jump = 0;
                        }
                    #ifdef SUPPORT_BMP_COMPRESSION
                        if (bmp_infoheader.biCompression == GDI_BI_BITFIELDS)
                        {
                            GET_U32(src, c);
                            b = ((c & b_mask) >> b_shift) << b_bits;
                            g = ((c & g_mask) >> g_shift) << g_bits;
                            r = ((c & r_mask) >> r_shift) << r_bits;
                            a = 0xFF;
                        }
                        else
                    #endif /* SUPPORT_BMP_COMPRESSION */ 
                        {
                            MY_GET_U8(src, b);
                            MY_GET_U8(src, g);
                            MY_GET_U8(src, r);
                            MY_GET_U8(src, a);
                            a = 0xFF;
                        }

                    #if defined(GDI_USING_DITHERING)
                        switch (gdi_image_bmp_dithering)
                        {
                            case GDI_IMAGE_BMP_DITHER_RGB565:
                                IUL_SD_RGB888_TO_RGB565(r, g, b, (&tmp_c));
                                break;
                            case GDI_IMAGE_BMP_DITHER_RGB8882BITS:
                                IUL_SD_RGB888_2BITS_DITHERING(b, g, r, ((U8*)(&tmp_c)));
                                break;
                            case GDI_IMAGE_BMP_DITHER_DISABLE:
                            default:
                                tmp_c = gdi_act_color_from_rgb(a, r, g, b);
                                break;
                        }
                    #else
                        tmp_c = gdi_act_color_from_rgb(a, r, g, b);
                    #endif
                    
                        if(is_standard_output
                        && gdi_act_layer_info->source_key_enable
                        && gdi_act_layer_info->source_key == tmp_c)
                            GDI_RESIZER_PUT(replace_source_key, 1);
                        else
                            GDI_RESIZER_PUT(tmp_c, 1);
                    }
                    else
                    {
                        jump += 4;
                    }

                    time_out_check++;
                }
                jump += dummyCount;
            }
            break;

        case 4:
            pos_y = bmp_infoheader.biHeight - 1;
            while (pos_y >= 0)
            {
                if (bmp_infoheader.biCompression != GDI_BI_RLE4)
                {
                    if (dataCount <= 0)
                    {
                        break;
                    }
                }
                
                pos_x = 0;

                if(!gdi_image_progress_callback()) 
                    GDI_RAISE(GDI_IMAGE_ERR_DECODE_TIME_OUT);

                time_out_check = 0;
                j = 0;
                while(1)
                {
                    U32 c = 0;

                    if (bmp_infoheader.biCompression == GDI_BI_RLE4)
                    {
                        if (pos_x >= (S32) bmp_infoheader.biWidth)
                        {
                            break;
                        }                    
                    }
                    else
                    {
                        if (j >= (S32) bytePerLine)
                        {
                            break;
                        }
                    }
                    
                    if (time_out_check == 1000)
                    {
                        if(!gdi_image_progress_callback())
                        {
                            GDI_RAISE(GDI_IMAGE_ERR_DECODE_TIME_OUT);
                        }
                        time_out_check = 0;
                    }

                    MY_GET_U8(src, c);

                    // 4 bit per color, so read one byte may fill two pixel 
                    // pixel 1
                    tmp_byte = c >> 4;
                    if (IS_GDI_RESIZER_WANT_DRAW(pos_x, pos_y))
					{
                        if(is_standard_output)
                            GDI_RESIZER_PUT(palette[tmp_byte], TRUE);
						else
                            GDI_RESIZER_PUT(palette[tmp_byte], (BOOL) (tmp_byte != 0));
					}

                    pos_x++;

                    if (gdi_image_bmp_run_length_odd == 0)
                    {
                        /* pixel 2 */
                        tmp_byte = c & 0xf;
                        if (pos_x < (S32) bmp_infoheader.biWidth)
                            if (IS_GDI_RESIZER_WANT_DRAW(pos_x, pos_y))
                            {
                                if(is_standard_output)
                                    GDI_RESIZER_PUT(palette[tmp_byte], TRUE);
                                else
                                    GDI_RESIZER_PUT(palette[tmp_byte], (BOOL) (tmp_byte != 0));
                            }
                        pos_x++;
                    }
                    else
                    {
                        gdi_image_bmp_run_length_odd = 0;
                    }

                    j++;
                    dataCount--;
                    time_out_check++;
                }
                pos_y--;
            }
            break;
        case 1:
        {
            gdi_color color0, color1;

            pos_x = 0;
            pos_y = bmp_infoheader.biHeight - 1;

            color0 = palette[0];
            color1 = palette[1];

            while (dataCount > 0)
            {
                if(!gdi_image_progress_callback()) 
                    GDI_RAISE(GDI_IMAGE_ERR_DECODE_TIME_OUT);

                time_out_check = 0;
                for (j = 0; j < (S32) bytePerLine; j++)
                {
                    if (time_out_check == 1000)
                    {
                        if(!gdi_image_progress_callback())
                        {
                            GDI_RAISE(GDI_IMAGE_ERR_DECODE_TIME_OUT);
                        }
                        time_out_check = 0;
                    }
                    /* 1 bit per color, so read one byte may fill eight pixel */
                    MY_GET_U8(src, tmp_byte);
                    for (i = 0; i < 8; i++)
                    {
                        if (pos_x < (S32) bmp_infoheader.biWidth)
                        {
                            if (IS_GDI_RESIZER_WANT_DRAW(pos_x, pos_y))
                            {
                                if (tmp_byte & 0x80)
                                {
                                    GDI_RESIZER_PUT(color1, 1);
                                }
                                else
                                {
                                    GDI_RESIZER_PUT(color0, 1);
                                }
                            }
                            tmp_byte <<= 1;
                            pos_x++;
                        }
                    }
                    dataCount--;
                    time_out_check++;
                }
                pos_y--;
                pos_x = 0;
            }
        }
            break;
        default:
            gdi_resizer_deinit();
            GDI_RETURN(GDI_FAILED);
    }
    gdi_resizer_deinit();
    GDI_EXIT_CRITICAL_SECTION(GDI_IMAGE_BMP_DRAW_INTERNAL)
    return GDI_SUCCEED;
}


