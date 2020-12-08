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
 *  gdi_imgdec_bmp.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  GDI IMGDEC bitmap decoder
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "gdi_trc.h"
#include "gdi_internal.h"
//#include "drm_gprot.h"
#include "med_utility.h"

#include "gdi_imgdec.h"
#include "gdi_imgdec_internal.h"
#include "gdi_imgdec_bytestream.h"
#include "gdi_imgdec_resizer.h"

#include "gdi_imgdec_bmp_codec.h"

#if defined(GDI_USING_DITHERING)
#include "iul_spatial_dithering.h"
#include "iul_sd_macros.h"
#endif

#include "setjmp.h"
#include "wchar.h"
#include "string.h"
#include "MMIDataType.h"

#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gdi_image_bmp.h"
#include "gdi_include.h"
#include "gdi_primitive.h"

#include "gdi_imgdec_bmp.h"


#if defined(__MTK_TARGET__)
#pragma Otime
#endif /* defined(__MTK_TARGET__) */ 

gdi_imgdec_bmp_struct *g_dec = NULL;
extern KAL_ADM_ID gdi_layer_buffer_pool_id;

/****************************************************************************
* Static Declaration
*****************************************************************************/


/* Unified interface */
static void INIT_SRC(U8 **src, U8* input, gdi_imgdec_bmp_struct *dec)
{
    if(!dec->is_from_file)
    {
        *src = input;
    }
}

static void GET_U8(U8 **SRC, U8 *X, gdi_imgdec_bmp_struct *dec)
{
    if(dec->is_from_file)
    {
        GDI_IMGDEC_BYTESTREAM_GET_BYTE_FILE((&dec->bs), (*X));
    }
    else
    {
         *X =   (**SRC);
         (*SRC)++;
    }
}

static void GET_U16(U8 **SRC, U16 *X, gdi_imgdec_bmp_struct *dec)
{
    if(dec->is_from_file)
    {
        GDI_IMGDEC_BYTESTREAM_GET_WORD_FILE((&dec->bs), (*X));
    }
    else
    {
        *X = ((U16) **SRC);
        (*SRC) += 1;
        *X |= ((U16) **SRC)<<8; 
        (*SRC) += 1;
    }
}

static void GET_U24(U8 **SRC, U32 *X, gdi_imgdec_bmp_struct *dec)
{
    if(dec->is_from_file)
    {
        GDI_IMGDEC_BYTESTREAM_GET_3BYTES_FILE((&dec->bs), (*X));
    }
    else
    {
        *X =   ((U32) **SRC);
        (*SRC) += 1;
        *X |=((U32) (U8)**SRC)<<8; 
        (*SRC) += 1;
        *X |=((U32) (U8)**SRC)<<16;
        (*SRC) += 1;
    }
}
#define GET_SRC_U24(SRC, p, dec)\
{\
    if(dec->is_from_file)\
    {\
     gdi_imgdec_bytestream_struct *h; \
      h = &(dec->bs); \
            if (h->buffer_content_size < 3)     \
               gdi_imgdec_bytestream_buffer_load_file(h, 3);       \
            h->buffer_content_size -= 3;       \
            h->file_offset += 3;               \
            p = h->buffer_reader;              \
            h->buffer_reader += 3;              \
    }\
    else\
    {\
        p =   SRC; \
        SRC += 3; \
    }\
}

static void GET_U32(U8 **SRC, U32 *X, gdi_imgdec_bmp_struct *dec)
{
    if(dec->is_from_file)
    {
        GDI_IMGDEC_BYTESTREAM_GET_DWORD_FILE((&dec->bs), (*X));
    }
    else
    {
        *X = ((U32) (U8)**SRC);
        (*SRC) += 1;
        *X |=((U32) (U8)**SRC)<<8; 
        (*SRC) += 1;
        *X |=((U32) (U8)**SRC)<<16;
        (*SRC) += 1;
        *X |=((U32) (U8)**SRC)<<24;
        (*SRC) += 1;
    }
}

static void FLUSH(U8 **SRC, U32 X, gdi_imgdec_bmp_struct *dec)
{
    if(dec->is_from_file)
    {
        GDI_IMGDEC_BYTESTREAM_FLUSH_FILE((&dec->bs), (X));
    }
    else
    {
        (*SRC) += X;
    }
}

static void SEEK(U8 **SRC, U8 *BMP_SRC, U32 OFFSET, gdi_imgdec_bmp_struct *dec) 
{
    if(dec->is_from_file)
    {
        gdi_imgdec_bytestream_seek_file(&dec->bs, OFFSET);
    }
    else
    {
        *SRC = BMP_SRC+OFFSET;
    }
}


#ifdef SUPPORT_BMP_COMPRESSION
#define COMPRESSION_MODE(n, w, h) \
   do                                    \
   {                                     \
      dec->compression = n;     \
      dec->src_x = 0;           \
      dec->src_y = h - 1;    \
      dec->width = w;       \
      dec->height = h;     \
      dec->run_length = 0;      \
      dec->run_length_odd = 0; \
   } while(0)


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
U8 GET_U8_FROM_RUN_LENGTH(gdi_imgdec_bmp_struct *dec, U8** src, S32 sx, S32 sy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ret_value = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dec->run_length <= 0)
    {
        GET_U8((src), (U8 *)&dec->run_length, dec);
        
        if (dec->run_length > 0)  /* encoded mdoe */
        {
            dec->is_raw_mode = FALSE;
            dec->run_length_used = 0;
            GET_U8((src), &dec->code, dec);
        }
        else    /* escape mode */
        {
            dec->is_raw_mode = TRUE;
            GET_U8((src), (U8*)&dec->run_length, dec);
            switch (dec->run_length)
            {
                case 1:
                    dec->src_y = -1;
                    dec->run_length = 0;
                    GDI_TRACE(GDI_TRC, GDI_TRC_41//"GDI_BMP_EXCEPTION_ESCAPE_MODE_END_OF_BITMAP"
                                            );
  
                    GDI_IMGDEC_RAISE(dec, GDI_BMP_EXCEPTION_ESCAPE_MODE_END_OF_BITMAP);
                    return 0;
                case 0: /* end of line */
                    dec->src_x = 0;
                    dec->src_y--;
                    dec->run_length = 0;
                    return 0;
                case 2: /* delta mode */
                {
                    U8 dx, dy;

                    GET_U8((src),&dx, dec);
                    GET_U8((src),&dy, dec);
                    dec->src_x += dx;
                    dec->src_y -= dy;
                }
                    dec->run_length = 0;
                    return 0;
                default:    /* abolutte */
                    dec->run_length_used = 0;
                    break;
            }
        }
    }

    if (dec->is_raw_mode)
    {
        if (dec->compression == GDI_BI_RLE8)
        {
            GET_U8((src),&ret_value, dec);
        }
        else
        {
            GET_U8((src), &dec->code, dec);
            ret_value = dec->code;
            dec->src_x++;
            dec->run_length--;
            dec->run_length_used++;
        }

        if ((dec->compression == GDI_BI_RLE4) && (dec->run_length == 0))
        {
            dec->run_length_odd = 1;
        }

        dec->run_length--;
        dec->run_length_used++;

        if (dec->run_length_odd == 0)
        {
            ++dec->src_x;
        }

        if (dec->run_length <= 0)  /* read pad byte. */
        {
            if (dec->compression == GDI_BI_RLE8)
            {
                if (dec->run_length_used & 1)
                {
                    FLUSH((src),1, dec);
                }
            }
            else
            {
                if ((dec->run_length_used & 0x03) == 1 || (dec->run_length_used & 0x03) == 2)
                {
                    FLUSH((src),1, dec);
                }
            }
        }
    }
    else
    {
        if (dec->compression == GDI_BI_RLE8)
        {
            ret_value = dec->code;
        }
        else
        {
            ret_value = dec->code;
            dec->run_length--;
            dec->run_length_used++;
            ++dec->src_x;
        }

        if ((dec->compression == GDI_BI_RLE4) && (dec->run_length == 0))
        {
            dec->run_length_odd = 1;
        }

        dec->run_length--;
        dec->run_length_used++;

        if (dec->run_length_odd == 0)
        {
            ++dec->src_x;
        }

        if (dec->src_x > (dec->width+1))
        {
            GDI_IMGDEC_RAISE(dec, 1);  // invalid format
        }
    }
    return ret_value;
}

#define MY_GET_U8(SRC,X, dec)                                \
   {                                                    \
      if(dec->compression == GDI_BI_RLE4       \
      ||dec->compression == GDI_BI_RLE8)       \
      {                                                 \
         while(1)                                       \
         {                                              \
            if(dec->src_y >= pos_y)             \
            {                                           \
               if(dec->src_y > pos_y            \
               ||dec->src_x <= pos_x)           \
                  *X=GET_U8_FROM_RUN_LENGTH(dec, (SRC), pos_x, pos_y); \
               else                                     \
                  break;                                \
            }                                           \
            else                                        \
               break;                                   \
         }                                              \
      }                                                 \
      else                                              \
      {                                                 \
         GET_U8(SRC,X, dec);                                  \
      }                                                 \
   }

#define MY_FLUSH(SRC,X, dec)                             \
   {                                                \
      if (dec->compression == GDI_BI_RGB ||      \
          dec->compression==GDI_BI_BITFIELDS)   \
      {                                             \
         FLUSH(SRC,X, dec);                              \
      }                                             \
   }

#else
    #define COMPRESSION_MODE(n,width,height)
    #define MY_GET_U8(SRC,X, dec)                        GET_U8(SRC,X, dec)
    #define MY_FLUSH(SRC,X, dec)                         FLUSH(SRC,X, dec)
#endif 



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
            gdi_imgdec_bmp_struct *dec,
            S32 offset_x,
            S32 offset_y,
            BOOL is_resized,
            S32 resized_width,
            S32 resized_height,
            U8 *BMP_src,
            U32 size,
            BOOL transparent_enable,
            S32 aspect_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
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
    gdi_color *palette = NULL;
    gdi_color replace_source_key = 0;
    int jump = 0;
    U32 c = 0;
    U32 is_standard_output;
    U8* src;
    gdi_layer_struct *out_layer = (gdi_layer_struct*)dec->out_layer;
    U8  cf;
    kal_bool out_layer_source_key_enable = KAL_FALSE;
    kal_uint32 out_layer_source_key_value = 0;
    
    gd_color_from_rgb_func color_from_rgb;
    S32 resizer_init_ret = 1;

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

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
#if defined(GDI_USING_DITHERING)
    IUL_SD_INITIALIZE();    
#endif

    //g_dec = dec;
    memset(&bmp_fileheader, 0, sizeof(bitmap_file_header));
    memset(&bmp_infoheader, 0, sizeof(bitmap_info_header));
    
    /* assert for valid layer */   
    GDI_ASSERT(out_layer->id < GDI_LAYER_TOTAL_LAYER_COUNT);
    
    out_layer_source_key_enable = gdi_layer_info[out_layer->id].source_key_enable;
    out_layer_source_key_value = gdi_layer_info[out_layer->id].source_key;
    cf = out_layer->vcf;

    color_from_rgb = gd_color_from_rgb[cf];
        
    INIT_SRC(&src, BMP_src, dec);

    GDI_DEBUG_ASSERT(BMP_src != NULL);
    COMPRESSION_MODE(0, 0, 0);  /* reset the compression mode */

    is_standard_output = (dec->flag & (GDI_IMAGE_CODEC_FLAG_IS_FILE | GDI_IMAGE_CODEC_FLAG_IS_MEM)) ? 1 : 0;
    /* read file header */
    GET_U16(&src, &bmp_fileheader.bfType, dec);
    GET_U32(&src, &bmp_fileheader.bfSize, dec);
    GET_U16(&src, &bmp_fileheader.bfReserved1, dec);
    GET_U16(&src, &bmp_fileheader.bfReserved2, dec);
    GET_U32(&src, &bmp_fileheader.bfOffBits, dec);
    /* test if it is BMP file */
    if (bmp_fileheader.bfType != 0x4d42)    /* BM */
    {
        return GDI_FAILED;
    }

    if (bmp_fileheader.bfReserved1 != 0 || bmp_fileheader.bfReserved2 != 0)
    {
        return GDI_FAILED;
    }

    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

    /* read info header */
    GET_U32(&src, &bmp_infoheader.biSize, dec);
    if (bmp_infoheader.biSize == 12)        /* OS/2 bmp format */
    {
        GET_U16(&src, (U16*)&bmp_infoheader.biWidth, dec);
        GET_U16(&src, (U16*)&bmp_infoheader.biHeight, dec);
        GET_U16(&src, &bmp_infoheader.biPlanes, dec);
        GET_U16(&src, &bmp_infoheader.biBitCount, dec); 
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
            return GDI_FAILED;
        }

        GET_U32(&src, &bmp_infoheader.biWidth, dec);
        GET_U32(&src, &bmp_infoheader.biHeight, dec);
        GET_U16(&src, &bmp_infoheader.biPlanes, dec);
        GET_U16(&src, &bmp_infoheader.biBitCount, dec);
        GET_U32(&src, &bmp_infoheader.biCompression, dec);
        GET_U32(&src, &bmp_infoheader.biSizeImage, dec);
        GET_U32(&src, &bmp_infoheader.biXPelsPerMeter, dec);
        GET_U32(&src, &bmp_infoheader.biYPelsPerMeter, dec);
        GET_U32(&src, &bmp_infoheader.biClrUsed, dec); 
        GET_U32(&src, &bmp_infoheader.biClrImportant, dec);
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
        return GDI_FAILED;

    // setup resizer
    // If resized width > original width or resized height > original height, do not resize
    if (!is_resized ||
        (!(dec->flag & GDI_IMAGE_CODEC_FLAG_ADJUST_ASPECT) && 
        (resized_width > (S32) bmp_infoheader.biWidth || resized_height > (S32) bmp_infoheader.biHeight)))
    {
        resized_width = bmp_infoheader.biWidth;
        resized_height = bmp_infoheader.biHeight;
    }

    // check resized_width/resized_height will cause divide by zero
    if (resized_width <= 0 || resized_height <= 0)
    {
        return (GDI_SUCCEED);
    }
    if (dec->flag & GDI_IMAGE_CODEC_FLAG_ADJUST_ASPECT)
    {
        /* WBMP can not enlarge */
        if (aspect_flag & GDI_UTIL_MODE_SHORT_SIDE_FIT)
        {
            aspect_flag &= ~GDI_UTIL_MODE_SHORT_SIDE_FIT;
            aspect_flag |= GDI_UTIL_MODE_NO_RESIZE_OR_SHORT_SIDE_FIT;
        }
        if (aspect_flag & GDI_UTIL_MODE_LONG_SIDE_FIT)
        {
            aspect_flag &= ~GDI_UTIL_MODE_LONG_SIDE_FIT;
            aspect_flag |= GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT;
        }
        gdi_util_adjust_aspect(
            aspect_flag,
            offset_x,
            offset_y,
            resized_width,
            resized_height,
            bmp_infoheader.biWidth,
            bmp_infoheader.biHeight,
            &offset_x,
            &offset_y,
            &resized_width,
            &resized_height);
    }

    resizer_init_ret = gdi_imgdec_resizer_init(
            &dec->resizer,
            dec->out_layer,
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
        return GDI_SUCCEED;
    }
    else if (resizer_init_ret < 0)
    {
        /* decode limitation, output width too large */
        return GDI_FAILED;
    }

    if (out_layer_source_key_enable)
    {
        replace_source_key = out_layer_source_key_value ^ 1;
    }

    dec->palette_size = 0;
    
    /* setup palette */    
    if (bmp_infoheader.biBitCount <= 8)
    {
        gd_color_from_rgb_func palette_color_from_rgb;

       
        paletteSize = 1 << (bmp_infoheader.biBitCount);
        if (bmp_infoheader.biClrUsed != 0 && bmp_infoheader.biClrUsed < paletteSize)
        {
            paletteSize = bmp_infoheader.biClrUsed;
            dec->palette_size = paletteSize;
        }

        // TODO: USE CUSTOM MEMORY ALLOCATE
        /* allocate palette memory */        
        dec->palette = (gdi_color*)gdi_alloc_ext_mem(paletteSize * sizeof(gdi_color));
        if (dec->palette == NULL)
        {
            // TODO: ADD LOG HERE
            return GDI_FAILED;
        }
        palette = dec->palette;

        if (cf == GDI_COLOR_FORMAT_8)
        {
            palette_color_from_rgb = GDI_PALETTE_COLOR_FROM_RGB;
        }
        else
        {
            palette_color_from_rgb = color_from_rgb;
        }

        /* read palette */
        for (i = 0; i < (S32) paletteSize; i++)
        {
            MY_GET_U8(&src, &b, dec);
            MY_GET_U8(&src, &g, dec);
            MY_GET_U8(&src, &r, dec);
            if (bmp_infoheader.biSize != 12)        /* OS/2 bmp format */
            {
                MY_GET_U8(&src, &a, dec);
            }
            palette[i] = palette_color_from_rgb(255, r, g, b);

            if (palette[i] == out_layer_source_key_value && out_layer_source_key_enable)
            {
                palette[i] ^= 1;
            }
        }

        // TODO: THIS IS NECESSARY...!?
        /* current layer is index color layer */
        if (cf == GDI_COLOR_FORMAT_8)
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

        GET_U32(&src, &r_mask, dec);
        GET_U32(&src, &g_mask, dec);
        GET_U32(&src, &b_mask, dec);

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
    SEEK(&src, BMP_src, bmp_fileheader.bfOffBits, dec);

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
                if (GDI_IMGDEC_IS_ABORTED(dec) || !gdi_image_progress_callback()) 
                    GDI_IMGDEC_RAISE(dec, GDI_IMAGE_ERR_DECODE_TIME_OUT);
                
                for (pos_x = 0; pos_x < (S32) (S32) bmp_infoheader.biWidth; pos_x++)
                {
                    if (IS_GDI_IMGDEC_RESIZER_WANT_DRAW(&dec->resizer, pos_x, pos_y))
                    {
                        if (jump)
                        {
                            MY_FLUSH(&src, jump, dec);
                            jump = 0;
                        }
                        MY_GET_U8(&src, (U8*)&c, dec);
                        if (is_standard_output || (transparent_enable == FALSE))
                            GDI_IMGDEC_RESIZER_PUT(palette[c], TRUE);
                        else
                            GDI_IMGDEC_RESIZER_PUT(palette[c], (BOOL) (c != 0));
                    }
                    else
                    {
                        jump++;
                    }
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
                if (GDI_IMGDEC_IS_ABORTED(dec) || !gdi_image_progress_callback()) 
                    GDI_IMGDEC_RAISE(dec, GDI_IMAGE_ERR_DECODE_TIME_OUT);

                for (pos_x = 0; pos_x < (S32) bmp_infoheader.biWidth; pos_x++)
                {
                    if (IS_GDI_IMGDEC_RESIZER_WANT_DRAW(&dec->resizer, pos_x, pos_y))
                    {
                        gdi_color tmp_c;
                        if (jump)
                        {
                            MY_FLUSH(&src, jump, dec);
                            jump = 0;
                        }
                        GET_U16(&src, (U16*)&c, dec);    /* RGB 555 */
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
                        tmp_c = color_from_rgb(0xFF, r, g, b);
                        if (is_standard_output &&
                            out_layer_source_key_enable &&
                            out_layer_source_key_value == tmp_c)
                            GDI_IMGDEC_RESIZER_PUT(replace_source_key, 1);
                        else
                            GDI_IMGDEC_RESIZER_PUT(tmp_c, 1);
                    }
                    else
                    {
                        jump += 2;
                    }
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
                if (GDI_IMGDEC_IS_ABORTED(dec) || !gdi_image_progress_callback()) 
                    GDI_IMGDEC_RAISE(dec, GDI_IMAGE_ERR_DECODE_TIME_OUT);

                for (pos_x = 0; pos_x < (S32) bmp_infoheader.biWidth; pos_x++)
                {
                    if (IS_GDI_IMGDEC_RESIZER_WANT_DRAW(&dec->resizer, pos_x, pos_y))
                    {
                        U8 *p;
                        U32 c;
                        gdi_color tmp_c;

                        if (jump)
                        {
                            MY_FLUSH(&src, jump, dec);
                            jump = 0;
                        }
                    GET_SRC_U24(src, p, dec);
                    #if defined(GDI_USING_DITHERING)
                        switch (dec->dither_mode)
                        {
                            case GDI_IMGDEC_BMP_DITHER_RGB565:
                                IUL_SD_RGB888_TO_RGB565(*(p+2), *(p+1), *p, (&tmp_c));
                                break;
                                
                            case GDI_IMGDEC_BMP_DITHER_RGB8882BITS:
                                IUL_SD_RGB888_2BITS_DITHERING(*p, *(p+1), *(p+2), ((U8*)(&tmp_c)));
                                break;
                                
                            case GDI_IMGDEC_BMP_DITHER_DISABLE:
                            default:
                                tmp_c = color_from_rgb(0xFF, *(p+2), *(p+1), *p);
                                break;
                        }
                    #else /* defined(GDI_USING_DITHERING) */
                        tmp_c = color_from_rgb(0xFF, *(p+2), *(p+1), *p);
                    #endif /* defined(GDI_USING_DITHERING) */

                        if (is_standard_output
                        && out_layer_source_key_enable 
                        && out_layer_source_key_value == tmp_c)
                            GDI_IMGDEC_RESIZER_PUT(replace_source_key, 1);
                        else
                            GDI_IMGDEC_RESIZER_PUT(tmp_c, 1);
                    }
                    else
                    {
                        jump += 3;
                    }
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
                if (GDI_IMGDEC_IS_ABORTED(dec) || !gdi_image_progress_callback()) 
                    GDI_IMGDEC_RAISE(dec, GDI_IMAGE_ERR_DECODE_TIME_OUT);

                for (pos_x = 0; pos_x < (S32) bmp_infoheader.biWidth; pos_x++)
                {
                    if (IS_GDI_IMGDEC_RESIZER_WANT_DRAW(&dec->resizer, pos_x, pos_y))
                    {
                        gdi_color tmp_c;
                        if (jump)
                        {
                            MY_FLUSH(&src, jump, dec);
                            jump = 0;
                        }
                    #ifdef SUPPORT_BMP_COMPRESSION
                        if (bmp_infoheader.biCompression == GDI_BI_BITFIELDS)
                        {
                            GET_U32(&src, &c, dec);
                            b = ((c & b_mask) >> b_shift) << b_bits;
                            g = ((c & g_mask) >> g_shift) << g_bits;
                            r = ((c & r_mask) >> r_shift) << r_bits;
                            a = 0xFF;
                        }
                        else
                    #endif /* SUPPORT_BMP_COMPRESSION */ 
                        {
                            MY_GET_U8(&src, &b, dec);
                            MY_GET_U8(&src, &g, dec);
                            MY_GET_U8(&src, &r, dec);
                            MY_GET_U8(&src, &a, dec);
                            a = 0xFF;
                        }

                    #if defined(GDI_USING_DITHERING)
                        switch (dec->dither_mode)
                        {
                            case GDI_IMGDEC_BMP_DITHER_RGB565:
                                IUL_SD_RGB888_TO_RGB565(r, g, b, (&tmp_c));
                                break;
                                
                            case GDI_IMGDEC_BMP_DITHER_RGB8882BITS:
                                IUL_SD_RGB888_2BITS_DITHERING(b, g, r, ((U8*)(&tmp_c)));
                                break;
                                
                            case GDI_IMGDEC_BMP_DITHER_DISABLE:
                            default:
                                tmp_c = color_from_rgb(a, r, g, b);
                                break;
                        }
                    #else /* defined(GDI_USING_DITHERING) */
                        tmp_c = color_from_rgb(a, r, g, b);
                    #endif /* defined(GDI_USING_DITHERING) */

                        if(is_standard_output
                        && out_layer_source_key_enable
                        && out_layer_source_key_value == tmp_c)
                            GDI_IMGDEC_RESIZER_PUT(replace_source_key, 1);
                        else
                            GDI_IMGDEC_RESIZER_PUT(tmp_c, 1);
                    }
                    else
                    {
                        jump += 4;
                    }
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

                if (GDI_IMGDEC_IS_ABORTED(dec) || !gdi_image_progress_callback()) 
                    GDI_IMGDEC_RAISE(dec, GDI_IMAGE_ERR_DECODE_TIME_OUT);

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
                    
                    MY_GET_U8(&src, (U8*)&c, dec);

                    // 4 bit per color, so read one byte may fill two pixel 
                    // pixel 1
                    tmp_byte = c >> 4;
                    if (IS_GDI_IMGDEC_RESIZER_WANT_DRAW(&dec->resizer, pos_x, pos_y))
					{
                        if(is_standard_output)
                            GDI_IMGDEC_RESIZER_PUT(palette[tmp_byte], TRUE);
						else
                            GDI_IMGDEC_RESIZER_PUT(palette[tmp_byte], (BOOL) (tmp_byte != 0));
					}

                    pos_x++;

                    if (dec->run_length_odd == 0)
                    {
                        /* pixel 2 */
                        tmp_byte = c & 0xf;
                        if (pos_x < (S32) bmp_infoheader.biWidth)
                        {
                            if (IS_GDI_IMGDEC_RESIZER_WANT_DRAW(&dec->resizer, pos_x, pos_y))
                            {
                                if(is_standard_output)
                                    GDI_IMGDEC_RESIZER_PUT(palette[tmp_byte], TRUE);
                                else
                                    GDI_IMGDEC_RESIZER_PUT(palette[tmp_byte], (BOOL) (tmp_byte != 0));
                            }
                        }                            
                        pos_x++;
                    }
                    else
                    {
                        dec->run_length_odd = 0;
                    }

                    j++;
                    dataCount--;
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
                if (GDI_IMGDEC_IS_ABORTED(dec) || !gdi_image_progress_callback()) 
                    GDI_IMGDEC_RAISE(dec, GDI_IMAGE_ERR_DECODE_TIME_OUT);

                for (j = 0; j < (S32) bytePerLine; j++)
                {
                    /* 1 bit per color, so read one byte may fill eight pixel */
                    MY_GET_U8(&src, &tmp_byte, dec);
                    for (i = 0; i < 8; i++)
                    {
                        if (pos_x < (S32) bmp_infoheader.biWidth)
                        {
                            if (IS_GDI_IMGDEC_RESIZER_WANT_DRAW(&dec->resizer, pos_x, pos_y))
                            {
                                if (tmp_byte & 0x80)
                                {
                                    GDI_IMGDEC_RESIZER_PUT(color1, 1);
                                }
                                else
                                {
                                    GDI_IMGDEC_RESIZER_PUT(color0, 1);
                                }
                            }
                            tmp_byte <<= 1;
                            pos_x++;
                        }
                    }
                    dataCount--;
                }
                pos_y--;
                pos_x = 0;
            }
        }
            break;
        default:
            return GDI_FAILED;
    }
    
    return GDI_SUCCEED;
}


#define gdi_imgdec_bmp_draw_internal_from_file GDI_IMAGE_BMP_DRAW_INTERNAL             
#define gdi_imgdec_bmp_draw_internal_from_mem GDI_IMAGE_BMP_DRAW_INTERNAL             
/*****************************************************************************
 * FUNCTION
 *  gdi_image_bmp_draw_resized_stub
 * DESCRIPTION
 *  draw resized bmp from memory
 * PARAMETERS
 *  offset_x             [IN]   draw position x
 *  offset_y             [IN]   draw position y
 *  resized_width        [IN]   width to draw
 *  resized_height       [IN]   height to draw
 *  BMP_src              [IN]   pointer to source image
 *  size                 [IN]   source image size
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_imgdec_bmp_draw_resized(
            gdi_imgdec_bmp_struct *dec,
            S32 offset_x,
            S32 offset_y,
            BOOL is_resized,
            S32 resized_width,
            S32 resized_height,
            U8 *BMP_src,
            U32 size,
            U32 aspect_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret;
    BOOL transparent_enable = TRUE;
    U32 flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    {
        // flag = gdi_image_codec_get_flag();
        flag = dec->flag;
        
        if (flag & GDI_IMAGE_CODEC_FLAG_DISABLE_SRC_KEY)
        {
            transparent_enable = FALSE;
        }
        
        GDI_IMGDEC_TRY(dec)
        {
            ret = gdi_imgdec_bmp_draw_internal_from_mem(
                                                dec,
                                                offset_x,
                                                offset_y,
                                                is_resized,
                                                resized_width,
                                                resized_height,
                                                BMP_src,
                                                size,
                                                transparent_enable,
                                                aspect_flag);
        }
        GDI_IMGDEC_CATCH_BEGIN(dec)
        {
            ret = GDI_FAILED;
            GDI_IMGDEC_CATCH(dec, GDI_IMAGE_ERR_DECODE_TIME_OUT)
            {
                ret = GDI_IMAGE_ERR_DECODE_TIME_OUT;
            }
            GDI_IMGDEC_CATCH(dec, GDI_BMP_EXCEPTION_ESCAPE_MODE_END_OF_BITMAP)
            {
                ret = GDI_SUCCEED;
            }
        }
        GDI_IMGDEC_CATCH_END(dec)
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_bmp_draw_resized_file_stub
 * DESCRIPTION
 *  draw resized bmp from file
 * PARAMETERS
 *  offset_x             [IN]   draw position x
 *  offset_y             [IN]   draw position y
 *  resized_width        [IN]   width to draw
 *  resized_height       [IN]   height to draw
 *  filename             [IN]   file name of bmp image
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_imgdec_bmp_draw_resized_file(
            gdi_imgdec_bmp_struct *dec,
            S32 offset_x,
            S32 offset_y,
            BOOL is_resized,            
            S32 resized_width,
            S32 resized_height,
            S8 *filename,
            U32 aspect_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((filename == NULL) || gdi_imgdec_bytestream_init_file_ext(&dec->bs, (PS8)filename, dec->bs_buf_ptr, dec->bs_buf_size, dec->jmpbuf) != GDI_SUCCEED)
    {
        return GDI_FAILED;
    }

#if defined(GDI_USING_DITHERING)
    if (((gdi_layer_struct*)dec->out_layer)->cf == GDI_COLOR_FORMAT_16)
    {
        dec->dither_mode = GDI_IMGDEC_BMP_DITHER_RGB565;
    }
    else if (((gdi_layer_struct*)dec->out_layer)->cf == GDI_COLOR_FORMAT_24)
    {
        dec->dither_mode = GDI_IMGDEC_BMP_DITHER_RGB8882BITS;
    }
#endif /* defined(GDI_USING_DITHERING) */

    GDI_IMGDEC_TRY(dec)
    {
        ret = gdi_imgdec_bmp_draw_internal_from_file(
                dec,
                offset_x,
                offset_y,
                is_resized,
                resized_width,
                resized_height,
                (U8*) filename,
                0,
                TRUE,
                aspect_flag);
    }
    GDI_IMGDEC_CATCH_BEGIN(dec)
    {
        ret = GDI_FAILED;
        GDI_CATCH(GDI_IMAGE_ERR_DECODE_TIME_OUT)
        {
            ret = GDI_IMAGE_ERR_DECODE_TIME_OUT;
        }
        GDI_CATCH(GDI_BMP_EXCEPTION_ESCAPE_MODE_END_OF_BITMAP)
        {
            ret = GDI_SUCCEED;
        }

    }
    GDI_IMGDEC_CATCH_END(dec)
    
    gdi_imgdec_bytestream_deinit(&dec->bs);

    return ret;
}


#if 0
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
#endif

// TODO:
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
U8 gdi_imgdec_get_palette_size(gdi_imgdec_bmp_struct *dec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return dec->palette_size;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_bmp_init
 * DESCRIPTION
 *  Initializes IMGDEC BMP.
 * PARAMETERS
 *  dec               [IN]  decoder handle
 *  out_layer         [IN]  output layer
 *  bs_buf            [IN]  bitstream buffer
 *  bs_buf_size       [IN]  bitstream buffer size
 *  is_aborted        [IN]  aborted flag
 *  flag              [IN]  flag
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_imgdec_bmp_init(gdi_imgdec_bmp_struct *dec, gdi_handle out_layer, void *bs_buf, U32 bs_buf_size, BOOL *is_aborted, U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(dec, 0, sizeof(gdi_imgdec_bmp_struct));

    dec->out_layer = out_layer;
    dec->bs_buf_ptr = (PU8)bs_buf;
    dec->bs_buf_size = bs_buf_size;
    dec->is_aborted = is_aborted;    
    dec->flag = flag;
    dec->dither_mode = GDI_IMGDEC_BMP_DITHER_DISABLE;
    if (flag & GDI_IMAGE_CODEC_FLAG_IS_FILE)
    {
        dec->is_from_file = TRUE;
    }
    else
    {
        dec->is_from_file = FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_bmp_deinit
 * DESCRIPTION
 *  Deinit IMGDEC BMP decoder.
 * PARAMETERS
 *  dec       [IN]  image decoder
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_imgdec_bmp_deinit(gdi_imgdec_bmp_struct *dec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* free palette memory */
    if (dec->palette)
    {
        gdi_free_ext_mem((void*)&dec->palette);
    }

    /* finish resizer */
    gdi_imgdec_resizer_deinit(&dec->resizer);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_bmp_draw_handler
 * DESCRIPTION
 *  draw bmp
 * PARAMETERS
 *  out_layer       [IN]        output layer
 *  frame_pos       [IN]        which frame to draw
 *  x               [IN]        draw position x
 *  y               [IN]        draw position y
 *  w               [IN]        draw width
 *  h               [IN]        draw height
 *  data_ptr        [IN]        image pointer
 *  img_size        [IN]        image fize
 *  flag            [IN]        flag 
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_imgdec_bmp_draw_handler(gdi_handle out_layer, U32 frame_pos, S32 x, S32 y, S32 w, S32 h, U8 *data_ptr, U32 img_size, BOOL *is_aborted, U32 flag, S32 aspect_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_imgdec_bmp_struct dec;
    GDI_RESULT ret;

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

    gdi_imgdec_bmp_init(&dec, out_layer, (PU8)bs_buf, buffer_size, is_aborted, flag);
           
    if (dec.is_from_file)
    {
        if (w && h)
        {
            ret = gdi_imgdec_bmp_draw_resized_file(&dec, x, y, TRUE, w, h, (S8*)data_ptr, aspect_flag);
        }
        else
        {
            ret = gdi_imgdec_bmp_draw_resized_file(&dec, x, y, FALSE, 0, 0, (S8*)data_ptr, aspect_flag);
        }
    }
    else
    {
        if (w && h)
        {
            ret = gdi_imgdec_bmp_draw_resized(&dec, x, y, TRUE, w, h, data_ptr, img_size, aspect_flag);
        }
        else
        {
            ret = gdi_imgdec_bmp_draw_resized(&dec, x, y, FALSE, 0, 0, data_ptr, img_size, aspect_flag);
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
 *  gdi_imgdec_bmp_get_dimension
 * DESCRIPTION
 *  Gets BMP dimension.
 * PARAMETERS
 *  src          [IN]   image source pointer
 *  size         [IN]   image size
 *  width        [OUT]  width
 *  height       [OUT]  height
 * RETURNS
 *  Error code.
 *****************************************************************************/
GDI_RESULT gdi_imgdec_bmp_get_dimension(U8 *src, U32 size, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    gdi_imgdec_bytestream_struct bs;
    GDI_RESULT ret;

    U32 bfSize;
    U32 biWidth;
    U32 biHeight;
    U32 biSize;
    U16 bfType;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = GDI_SUCCEED;

    gdi_imgdec_bytestream_init(&bs, src, size);

    /* read file header */
    gdi_imgdec_bytestream_read(&bs, &bfType, 2);
    gdi_imgdec_bytestream_read(&bs, &bfSize, 4);
    gdi_imgdec_bytestream_seek(&bs, 8);
    gdi_imgdec_bytestream_read(&bs, &biSize, 4);

    biWidth = 0;
    biHeight = 0;

    if (biSize == 12)
    {
        gdi_imgdec_bytestream_read(&bs, &biWidth, 2);
        gdi_imgdec_bytestream_read(&bs, &biHeight, 2);        
    }
    else
    {
        gdi_imgdec_bytestream_read(&bs, &biWidth, 4);
        gdi_imgdec_bytestream_read(&bs, &biHeight, 4);        
    }

    *width = biWidth;
    *height = biHeight;

    /* test if it is BMP file */
    if (bfType != 0x4D42)   /* BM */
    {
        ret = GDI_FAILED;
    }
    /* core info header, currently not support */
    if (bfSize == 26)
    {
        ret = GDI_FAILED;
    }

    gdi_imgdec_bytestream_deinit(&bs);

    return ret;
}



