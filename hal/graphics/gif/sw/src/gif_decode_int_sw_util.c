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
 *  gif_decdoe_int_sw_util.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  utility of Image Gif related.
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
/****************************************************************************
* Include
*****************************************************************************/
#include "gif_decode_int_sw.h"
#include "gif_decode_int_sw_util.h"
#include "kal_general_types.h"
#include "setjmp.h"
#ifndef SWGIF_VC_PROJ
#include "kal_public_api.h"
#else
#include "swgif_wrapper.h"
#endif
#include "string.h"

#ifndef GIF_WIN32
#include "lcd_sw_rnd.h"
#endif

/****************************************************************************
* Global Variable
*****************************************************************************/
/* bits per pixel */
static const kal_int32 gif_sw_bitsperpixels[] ={  1,  8,  16, 24, 24, 32};

/* catch */
jmp_buf     gif_sw_jmpbuf;
kal_bool    gif_sw_jmpbuf_is_used = KAL_FALSE;


/* resizer */
/* The cacheable pragma can be be removed after MAUI set all buffer default cacheable */
#if defined(__MTK_TARGET__)
#pragma arm section zidata = "CACHEDZI",  rwdata = "CACHEDRW"
#endif

gif_sw_resizer_struct GIF_SW_RESIZER;
gif_sw_resizer_put_func gif_sw_resizer_put;
gif_sw_resizer_update_wantxy gif_sw_resizer_update_wanty;
kal_uint32 gif_sw_resizer_output_fmt_bpp;

//static kal_int16 *resizer_buffer;
//static kal_int32 resizer_buffer_size;
//extern gif_sw_image_struct  *pcurrent_match_gif_sw_cache;

#if defined(__MTK_TARGET__)
#pragma arm section zidata, rwdata
#endif


/* color from rgb functions */
/*****************************************************************************
 * FUNCTION
 *  gif_sw_color_from_rgb_16
 * DESCRIPTION
 *  get gif_sw_color value from a, r, g, b
 * PARAMETERS
 *  A       [IN]    alpha value
 *  R       [IN]    red
 *  G       [IN]    green
 *  B       [IN]    blue
 * RETURNS
 *  gif_sw_color, return color value
 *****************************************************************************/
gif_sw_color gif_sw_color_from_rgb_16(kal_uint32 A, kal_uint32 R, kal_uint32 G, kal_uint32 B)
{
   return (gif_sw_color) ((((B) & 0xf8) >> 3) | (((G) & 0xfc) << 3) | (((R) & 0xf8) << 8));
}


/*****************************************************************************
 * FUNCTION
 *  gif_sw_color_from_rgb_24
 * DESCRIPTION
 *  get gif_sw_color value from a, r, g, b
 * PARAMETERS
 *  A       [IN]    alpha value
 *  R       [IN]    red
 *  G       [IN]    green
 *  B       [IN]    blue
 * RETURNS
 *  gif_sw_color, return color value
 *****************************************************************************/
gif_sw_color gif_sw_color_from_rgb_24(kal_uint32 A, kal_uint32 R, kal_uint32 G, kal_uint32 B)
{
   return (gif_sw_color) ((R << 16) | (G << 8) | B);
}



gif_sw_color gif_sw_color_from_rgb_6666(kal_uint32 A, kal_uint32 R, kal_uint32 G, kal_uint32 B)
{
   //return (gif_sw_color) ((((A&0xFC)>>2) << 18) | (((R&0xFC)>>2) << 12) | (((G&0xFC)>>2) << 6) | ((B&0xFC)>>2));
   return (gif_sw_color) (((A&0xFC)<<16) | (((R&0xFC))<<10) | (((G&0xFC))<< 4) | ((B&0xFC)>>2));
}



/*****************************************************************************
 * FUNCTION
 *  gif_sw_color_from_rgb_32
 * DESCRIPTION
 *  get gif_sw_color value from a, r, g, b
 * PARAMETERS
 *  A       [IN]    alpha value
 *  R       [IN]    red
 *  G       [IN]    green
 *  B       [IN]    blue
 * RETURNS
 *  gif_sw_color, return color value
 *****************************************************************************/
gif_sw_color gif_sw_color_from_rgb_32(kal_uint32 A, kal_uint32 R, kal_uint32 G, kal_uint32 B)
{
   return (gif_sw_color) ((A << 24) | (R << 16) | (G << 8) | B);
}


/*****************************************************************************
 * FUNCTION
 *  gif_sw_color_from_rgb_8
 * DESCRIPTION
 *  get gif_sw_color value from a, r, g, b
 * PARAMETERS
 *  A       [IN]    alpha value
 *  R       [IN]    red
 *  G       [IN]    green
 *  B       [IN]    blue
 * RETURNS
 *  gif_sw_color, return color value
 *****************************************************************************/
gif_sw_color gif_sw_color_from_rgb_8(kal_uint32 A, kal_uint32 R, kal_uint32 G, kal_uint32 B)
{
   return (gif_sw_color) ((A << 24) | (R << 16) | (G << 8) | A);
}


/* get pixel functions */
/*****************************************************************************
 * FUNCTION
 *  gif_sw_get_pixel_8
 * DESCRIPTION
 *  get color at the position (x, y)
 * PARAMETERS
 *  x       [IN]    the x position of pixel want to get color value
 *  y       [IN]    the y position of pixel want to get color value
 * RETURNS
 *  gif_sw_color, return color value
 *****************************************************************************/
gif_sw_color gif_sw_get_pixel_8(kal_int32 x, kal_int32 y)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/

   return (gif_sw_color) * (kal_uint8*) (g_gif_sw_dest_buf_ptr + ((y * g_gif_sw_dest_buf_width + x)));
}


/*****************************************************************************
 * FUNCTION
 *  gif_sw_get_pixel_16
 * DESCRIPTION
 *  get color at the position (x, y)
 * PARAMETERS
 *  x       [IN]    the x position of pixel want to get color value
 *  y       [IN]    the y position of pixel want to get color value
 * RETURNS
 *  gif_sw_color, return color value
 *****************************************************************************/
gif_sw_color gif_sw_get_pixel_16(kal_int32 x, kal_int32 y)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/

   return *(kal_uint16*) (g_gif_sw_dest_buf_ptr + ((y * g_gif_sw_dest_buf_width + x) << 1));
}


/*****************************************************************************
 * FUNCTION
 *  gif_sw_get_pixel_24
 * DESCRIPTION
 *  get color at the position (x, y)
 * PARAMETERS
 *  x       [IN]    the x position of pixel want to get color value
 *  y       [IN]    the y position of pixel want to get color value
 * RETURNS
 *  gif_sw_color, return color value
 *****************************************************************************/
gif_sw_color gif_sw_get_pixel_24(kal_int32 x, kal_int32 y)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/

   kal_uint32 *ptr = (kal_uint32*) (g_gif_sw_dest_buf_ptr + ((y * g_gif_sw_dest_buf_width + x) * 3));

   switch (((kal_uint32) ptr) & 0x3)
   {
      case 0:
          return ((*ptr) & 0x00ffffff);
      case 1:
          ptr = (kal_uint32*) (((kal_uint32) ptr) & (~0x3));
          return ((*ptr) >> 8);
      case 2:
          ptr = (kal_uint32*) (((kal_uint32) ptr) & (~0x3));
          return ((*ptr) >> 16) | ((*(ptr + 1) & 0x0ff) << 16);
      default:
          ptr = (kal_uint32*) (((kal_uint32) ptr) & (~0x3));
          return ((*ptr) >> 24) | ((*(ptr + 1) & 0x0ffff) << 8);
   }
}



gif_sw_color gif_sw_get_pixel_6666(kal_int32 x, kal_int32 y)
{
   return gif_sw_get_pixel_24(x, y);
   //kal_uint8 *ptr = (kal_uint8*) (g_gif_sw_dest_buf_ptr + ((y * g_gif_sw_dest_buf_width + x) * 3));
   //return ( *ptr | ((*(ptr+1))<<8) | ((*(ptr+2))<<16));
}



/*****************************************************************************
 * FUNCTION
 *  gif_sw_get_pixel_32
 * DESCRIPTION
 *  get color at the position (x, y)
 * PARAMETERS
 *  x       [IN]    the x position of pixel want to get color value
 *  y       [IN]    the y position of pixel want to get color value
 * RETURNS
 *  gif_sw_color, return color value
 *****************************************************************************/
gif_sw_color gif_sw_get_pixel_32(kal_int32 x, kal_int32 y)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/

   return (gif_sw_color) * (kal_uint32*) (g_gif_sw_dest_buf_ptr + ((y * g_gif_sw_dest_buf_width + x) * 4));
}


/* put pixel */
/*****************************************************************************
 * FUNCTION
 *  gif_sw_put_pixel_8
 * DESCRIPTION
 *  get the color at the position (x, y)
 * PARAMETERS
 *  x       [IN]    the x position of pixel want to set color value
 *  y       [IN]    the y position of pixel want to set color value
 *  c       [IN]    set the pixel as this value
 * RETURNS
 *  void
 *****************************************************************************/
void gif_sw_put_pixel_8(kal_int32 x, kal_int32 y, gif_sw_color c)
{
   *(kal_uint8*) (g_gif_sw_dest_buf_ptr + ((y * g_gif_sw_dest_buf_width + x))) = (kal_uint8) c;
}


/*****************************************************************************
 * FUNCTION
 *  gif_sw_put_pixel_16
 * DESCRIPTION
 *  get the color at the position (x, y)
 * PARAMETERS
 *  x       [IN]    the x position of pixel want to set color value
 *  y       [IN]    the y position of pixel want to set color value
 *  c       [IN]    set the pixel as this value
 * RETURNS
 *  void
 *****************************************************************************/
void gif_sw_put_pixel_16(kal_int32 x, kal_int32 y, gif_sw_color c)
{
   *(kal_uint16*) (g_gif_sw_dest_buf_ptr + ((y * g_gif_sw_dest_buf_width + x) << 1)) = (kal_uint16) c;
}

void _put_24(gif_sw_color c, kal_uint8* dst)
{
   kal_uint32 *ptr = (kal_uint32*)(dst);
   switch(((kal_uint32)ptr)&0x3)
   {
      case 0:
         *ptr = (*ptr&0xff000000)|(c&0x00ffffff);
         break;
      case 1:
         ptr= (kal_uint32*)(((kal_uint32)ptr)&(~0x3));
         *ptr = (*ptr&0x000000ff)|(c<<8);
         break;
      case 2:
         ptr= (kal_uint32*)(((kal_uint32)ptr)&(~0x3));
         *ptr = (*ptr&0x0000ffff)|(c<<16); ptr++;
         *ptr = (*ptr&0xffffff00)|((c&0x00ff0000)>>16);
         break;
      default:
         ptr= (kal_uint32*)(((kal_uint32)ptr)&(~0x3));
         *ptr = (*ptr&0x00ffffff)|(c<<24); ptr++;
         *ptr = (*ptr&0xffff0000)|((c&0x00ffff00)>>8);
         break;
   }
}

/*****************************************************************************
 * FUNCTION
 *  gif_sw_put_pixel_24
 * DESCRIPTION
 *  get the color at the position (x, y)
 * PARAMETERS
 *  x       [IN]    the x position of pixel want to set color value
 *  y       [IN]    the y position of pixel want to set color value
 *  c       [IN]    set the pixel as this value
 * RETURNS
 *  void
 *****************************************************************************/
void gif_sw_put_pixel_24(kal_int32 x, kal_int32 y, gif_sw_color c)
{
   //kal_uint32 *ptr = (kal_uint32*) (g_gif_sw_dest_buf_ptr + ((y * g_gif_sw_dest_buf_width + x) * 3));
   _put_24(c, (g_gif_sw_dest_buf_ptr + ((y * g_gif_sw_dest_buf_width + x) * 3)));
}


void gif_sw_put_pixel_6666(kal_int32 x, kal_int32 y, gif_sw_color c)
{
   gif_sw_put_pixel_24(x, y, c);
}


/*****************************************************************************
 * FUNCTION
 *  gif_sw_put_pixel_32
 * DESCRIPTION
 *  get the color at the position (x, y)
 * PARAMETERS
 *  x       [IN]    the x position of pixel want to set color value
 *  y       [IN]    the y position of pixel want to set color value
 *  c       [IN]    set the pixel as this value
 * RETURNS
 *  void
 *****************************************************************************/
void gif_sw_put_pixel_32(kal_int32 x, kal_int32 y, gif_sw_color c)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/

   *(kal_uint32*) (g_gif_sw_dest_buf_ptr + ((y * g_gif_sw_dest_buf_width + x) * 4)) = (kal_uint32) c;
}


/*****************************************************************************
 * FUNCTION
 *  gif_sw_null_pointer_function
 * DESCRIPTION
 *  define the default color format function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gif_sw_null_pointer_function(void)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/

   ASSERT(0);
}

#if (DRV_MAINLCD_BIT_PER_PIXEL == 1) || (!defined(GIF_SW_USING_LAYER))
/*****************************************************************************
 * FUNCTION
 *  gif_sw_color_from_rgb_main
 * DESCRIPTION
 *
 * PARAMETERS
 *  A       [IN]
 *  R       [IN]
 *  G       [IN]
 *  B       [IN]
 * RETURNS
 *
 *****************************************************************************/
gif_sw_color gif_sw_color_from_rgb_main(kal_uint32 A, kal_uint32 R, kal_uint32 G, kal_uint32 B)
{
   return (DRV_RGB_TO_HW(R, G, B));
}


/*****************************************************************************
 * FUNCTION
 *  gif_sw_get_pixel_main
 * DESCRIPTION
 *
 * PARAMETERS
 *  x       [IN]
 *  y       [IN]
 * RETURNS
 *
 *****************************************************************************/
gif_sw_color gif_sw_get_pixel_main(kal_int32 x, kal_int32 y)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   gif_sw_color c = 0;

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   DRV_MAINLCD_GET_BUFFER_PIXEL_EXT(x, y, c, g_gif_sw_dest_buf_ptr, g_gif_sw_dest_buf_width);
   return c;
}


/*****************************************************************************
 * FUNCTION
 *  gif_sw_put_pixel_main
 * DESCRIPTION
 *
 * PARAMETERS
 *  x       [IN]
 *  y       [IN]
 *  c       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gif_sw_put_pixel_main(kal_int32 x, kal_int32 y, gif_sw_color c)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   DRV_MAINLCD_SET_BUFFER_PIXEL_EXT(x, y, c, g_gif_sw_dest_buf_ptr, g_gif_sw_dest_buf_width);
}

#elif DRV_MAINLCD_BIT_PER_PIXEL == 16
#define gif_sw_color_from_rgb_main      GIF_SW_FUNC_16(gif_sw_color_from_rgb)
#define gif_sw_get_pixel_main           GIF_SW_FUNC_16(gif_sw_get_pixel)
#define gif_sw_put_pixel_main           GIF_SW_FUNC_16(gif_sw_put_pixel)
#elif DRV_MAINLCD_BIT_PER_PIXEL == 24
#define gif_sw_color_from_rgb_main      GIF_SW_FUNC_24(gif_sw_color_from_rgb)
#define gif_sw_get_pixel_main           GIF_SW_FUNC_24(gif_sw_get_pixel)
#define gif_sw_put_pixel_main           GIF_SW_FUNC_24(gif_sw_put_pixel)
#elif DRV_MAINLCD_BIT_PER_PIXEL == 32
#define gif_sw_color_from_rgb_main      GIF_SW_FUNC_32(gif_sw_color_from_rgb)
#define gif_sw_get_pixel_main           GIF_SW_FUNC_32(gif_sw_get_pixel)
#define gif_sw_put_pixel_main           GIF_SW_FUNC_32(gif_sw_put_pixel)
#endif

#ifndef DUAL_LCD
#define gif_sw_color_from_rgb_sub       gif_sw_null_pointer_function
#define gif_sw_get_pixel_sub            gif_sw_null_pointer_function
#define gif_sw_put_pixel_sub            gif_sw_null_pointer_function
#elif DRV_SUBLCD_BIT_PER_PIXEL ==  1 || !defined(GIF_SW_USING_LAYER)
/*****************************************************************************
 * FUNCTION
 *  gif_sw_color_from_rgb_sub
 * DESCRIPTION
 *****************************************************************************/
gif_sw_color gif_sw_color_from_rgb_sub(kal_uint32 A, kal_uint32 R, kal_uint32 G, kal_uint32 B)
{
   return (SUBMMI_RGB_TO_HW_FORMAT(R, G, B));
}


/*****************************************************************************
 * FUNCTION
 *  gif_sw_get_pixel_sub
 * DESCRIPTION
 *****************************************************************************/
gif_sw_color gif_sw_get_pixel_sub(kal_int32 x, kal_int32 y)
{
   gif_sw_color c;
   DRV_SUBLCD_GET_BUFFER_PIXEL_EXT(x, y, c, g_gif_sw_dest_buf_ptr, g_gif_sw_dest_buf_width);
   return c;
}


/*****************************************************************************
 * FUNCTION
 *  gif_sw_put_pixel_sub
 *****************************************************************************/
void gif_sw_put_pixel_sub(kal_int32 x, kal_int32 y, gif_sw_color c)
{
   DRV_SUBLCD_SET_BUFFER_PIXEL_EXT(x, y, c, g_gif_sw_dest_buf_ptr, g_gif_sw_dest_buf_width);
}
#elif DRV_SUBLCD_BIT_PER_PIXEL == 16
#define gif_sw_color_from_rgb_sub    GIF_SW_FUNC_16(gif_sw_color_from_rgb)
#define gif_sw_get_pixel_sub         GIF_SW_FUNC_16(gif_sw_get_pixel)
#define gif_sw_put_pixel_sub         GIF_SW_FUNC_16(gif_sw_put_pixel)
#elif DRV_SUBLCD_BIT_PER_PIXEL == 24
#define gif_sw_color_from_rgb_sub    GIF_SW_FUNC_24(gif_sw_color_from_rgb)
#define gif_sw_get_pixel_sub         GIF_SW_FUNC_24(gif_sw_get_pixel)
#define gif_sw_put_pixel_sub         GIF_SW_FUNC_24(gif_sw_put_pixel)
#elif DRV_SUBLCD_BIT_PER_PIXEL == 32
#define gif_sw_color_from_rgb_sub    GIF_SW_FUNC_32(gif_sw_color_from_rgb)
#define gif_sw_get_pixel_sub         GIF_SW_FUNC_32(gif_sw_get_pixel)
#define gif_sw_put_pixel_sub         GIF_SW_FUNC_32(gif_sw_put_pixel)
#endif

const gif_sw_put_pixel_func  gif_sw_put_pixel_array[] =              /* put pixel to destinaiton buffer */
{
    GIF_SW_FUNC_1   (gif_sw_put_pixel),   /* 1 */
    GIF_SW_FUNC_8   (gif_sw_put_pixel),   /* 8 */
    GIF_SW_FUNC_16  (gif_sw_put_pixel),   /* 16 */
    GIF_SW_FUNC_24  (gif_sw_put_pixel),   /* 24 */
    GIF_SW_FUNC_argb6666  (gif_sw_put_pixel),   /* 24 */
    GIF_SW_FUNC_32  (gif_sw_put_pixel),   /* 32 */
    GIF_SW_FUNC_32  (gif_sw_put_pixel),   /* 32pargb */
    gif_sw_put_pixel_main,
#ifdef DUAL_LCD
  gif_sw_put_pixel_sub
#else
    (gif_sw_put_pixel_func)gif_sw_null_pointer_function
#endif
};

const gif_sw_color_from_rgb_func gif_sw_color_from_rgb_array[] =     /* transform rgb to color value */
{
    GIF_SW_FUNC_1   (gif_sw_color_from_rgb),   /* 1 */
    GIF_SW_FUNC_8   (gif_sw_color_from_rgb),   /* 8 */
    GIF_SW_FUNC_16  (gif_sw_color_from_rgb),   /* 16 */
    GIF_SW_FUNC_24  (gif_sw_color_from_rgb),   /* 24 */
    GIF_SW_FUNC_argb6666  (gif_sw_color_from_rgb),   /* 24 */
    GIF_SW_FUNC_32  (gif_sw_color_from_rgb),   /* 32 */
    GIF_SW_FUNC_32  (gif_sw_color_from_rgb),   /* 32pargb */
    gif_sw_color_from_rgb_main,
#ifdef DUAL_LCD
  gif_sw_color_from_rgb_sub
#else
    (gif_sw_color_from_rgb_func)gif_sw_null_pointer_function
#endif
};

const gif_sw_get_pixel_func gif_sw_get_pixel_array[] =   /* get pixel from destination buffer */
{
    GIF_SW_FUNC_1   (gif_sw_get_pixel),   /* 1 */
    GIF_SW_FUNC_8   (gif_sw_get_pixel),   /* 8 */
    GIF_SW_FUNC_16  (gif_sw_get_pixel),   /* 16 */
    GIF_SW_FUNC_24  (gif_sw_get_pixel),   /* 24 */
    GIF_SW_FUNC_argb6666  (gif_sw_get_pixel), /* 24 */
    GIF_SW_FUNC_32  (gif_sw_get_pixel),   /* 32 */
    GIF_SW_FUNC_32  (gif_sw_get_pixel),   /* 32pargb */
    gif_sw_get_pixel_main,
#ifdef DUAL_LCD
  gif_sw_get_pixel_sub
#else
    (gif_sw_get_pixel_func)gif_sw_null_pointer_function
#endif
};

//FIX_PONT_Q: Be power of 2
#define FIX_PONT_Q 8
#define FP_DECIMAL_MASK ((1<<(FIX_PONT_Q))-1)
#define FP_HALF_DECIMAL_MASK (FP_DECIMAL_MASK >> 1)
#define LARGER_THAN_HALF(val)  (((val) & FP_DECIMAL_MASK) >= FP_HALF_DECIMAL_MASK)

/* DEFINE FIXED POINT MACROS*/

/* The basic operations performed on two numbers a, b of 
   fixed point q format returning the answer in q format*/
#define FADD(a,b,q)  ((a)+(b))
#define FSUB(a,b,q)  ((a)-(b))
#define FMUL(a,b,q)  (((a)*(b))>>(q))
#define FDIV(a,b,q)  (((a)<<(q))/(b))

/* The basic operations where a is of fixed point q format
   and b is an integer*/
#define FADDI(a,b,q) ((a)+((b)<<(q)))
#define FSUBI(a,b,q) ((a)-((b)<<(q)))
#define FMULI(a,b,q) ((a)*(b))
#define FDIVI(a,b,q) ((a)/(b))

/* Convert a form q1 format to q2 format*/
#define FCONV(a,q1,q2) (((q2)>(q1))?(a<<(q2-q1)):(a>>(q1-q2)))

/* The gernal operations between a in q1 format, b in q2 format
   returning the result in q3 format*/
#define FADDG(a,b,q1,q2,q3) (FCONV(a,q1,q3)+FCONV(b,q1,q3))
#define FSUBG(a,b,q1,q2,q3) (FCONV(a,q1,q3)-FCONV(b,q1,q3))
#define FMULG(a,b,q1,q2,q3) (FCONV(((a)*(b)),(q1)+(q2),(q3))
#define FDIVG(a,b,q1,q2,q3) (FCONV((a),q1,((q2)+(q3))/(b))

/* Convert to/from floating point*/
#define TOFIX(d,q)          ((int)((d)<<(q)))
//#define TOFLT(a,q)          ((double)((a)/((double)(1<<q))))
#define TOINT(a,q)          ((kal_int32)((a)>>(q)))

/* resizer */
/*****************************************************************************
 * FUNCTION
 *  gif_sw_resizer_update_interlaced_want_sy
 * DESCRIPTION
 *  update resizer context depends on want_sy
 * PARAMETERS
 *  want_sy       [IN]  the next line resizer want to draw
 * RETURNS
 *  void
 *****************************************************************************/
void gif_sw_resizer_update_interlaced_want_sy(kal_bool resize, kal_int32* want_sx, kal_int32 want_sy)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   kal_int32 dy;

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/

   // out of clipping should not update want_sx, want_sy
   if( *want_sx <0 || GIF_SW_RESIZER.want_sy < 0) return;

   // sometime we need to stop auto increase dy, and manual set the position
   GIF_SW_RESIZER.dir_y = 0;
   // default : the pixel line (want_sy) will not be accept !!
   GIF_SW_RESIZER.want_sy = want_sy+1;

   // non resize handler
   if (!resize)
   {
      if ((want_sy) >= GIF_SW_RESIZER.want_start_sy && (want_sy) <= GIF_SW_RESIZER.want_end_sy)
      {
         GIF_SW_RESIZER.want_sx = GIF_SW_RESIZER.want_start_sx;
         GIF_SW_RESIZER.want_sy = want_sy;
         //W05.40 Compute GIF_SW_RESIZER.dest by GIF_SW_RESIZER.want_dx1 and GIF_SW_RESIZER.want_dy1
         GIF_SW_RESIZER.dest = g_gif_sw_dest_buf_ptr
                  + (((GIF_SW_RESIZER.want_dx1
                  +(GIF_SW_RESIZER.want_dy1+GIF_SW_RESIZER.want_sy-GIF_SW_RESIZER.want_start_sy)*g_gif_sw_dest_buf_width)
                  * gif_sw_resizer_output_fmt_bpp));
      }
      return ;
   }


   for(;;)
   {
      // want_sy project to dy
      dy = ((want_sy * GIF_SW_RESIZER.dest_height_range << 1) +  GIF_SW_RESIZER.src_height_range) / (GIF_SW_RESIZER.src_height_range << 1);

      //check this want_dy will also project to want_sy
      if( want_sy == ((((dy) * GIF_SW_RESIZER.src_height_range << 1) +  GIF_SW_RESIZER.dest_height_range) / (GIF_SW_RESIZER.dest_height_range << 1)))
      {
         break;
      }

      dy ++;
      // check dy + 1 will project to want_sy
      if(want_sy == ((((dy) * GIF_SW_RESIZER.src_height_range << 1) +  GIF_SW_RESIZER.dest_height_range) / (GIF_SW_RESIZER.dest_height_range << 1)))
      {
         break;
      }


      return;// this line will not be accept !!
   }

   dy += GIF_SW_RESIZER.offset_dy;

   // check this destination is out of clipping area ?
   if(dy < GIF_SW_RESIZER.want_dy1 || dy > GIF_SW_RESIZER.want_dy2)
   {
      return;// this line will not be accept !!
   }

   GIF_SW_RESIZER.want_sy = want_sy;
   GIF_SW_RESIZER.next_want_dy = dy;
   
   GIF_SW_RESIZER.want_fpsx = GIF_SW_RESIZER.want_start_fpsx; 
   *want_sx = TOINT(GIF_SW_RESIZER.want_fpsx, FIX_PONT_Q);
   if (LARGER_THAN_HALF(GIF_SW_RESIZER.want_fpsx))
   {
      (*want_sx)++;
   }

   GIF_SW_RESIZER.dest = g_gif_sw_dest_buf_ptr
         + ( GIF_SW_RESIZER.want_start_dx + GIF_SW_RESIZER.next_want_dy* g_gif_sw_dest_buf_width) * gif_sw_resizer_output_fmt_bpp;


}



/*****************************************************************************
 * FUNCTION
 *  gif_sw_resizer_put_null
 * DESCRIPTION
 *  dummy put pixel function
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
void gif_sw_resizer_put_null(kal_int32* want_sx, gif_sw_color c,kal_bool want_draw)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/

   // keep empty
}



void _gif_sw_resizer_update_want_x(kal_int32* want_sx)
{
   //kal_int32 temp1, temp2;
   // generate next_position
   if (GIF_SW_RESIZER.next_want_dx >= GIF_SW_RESIZER.want_end_dx)   
   {	
      return;
   }

   GIF_SW_RESIZER.want_fpsx = FADD(GIF_SW_RESIZER.want_fpsx, GIF_SW_RESIZER.x_resize_jump_distance, FIX_PONT_Q);
   *want_sx = TOINT(GIF_SW_RESIZER.want_fpsx, FIX_PONT_Q);
   if (LARGER_THAN_HALF(GIF_SW_RESIZER.want_fpsx))
   {
      (*want_sx)++;
   }
   GIF_SW_RESIZER.next_want_dx += GIF_SW_RESIZER.dir_x;
	
}

/*****************************************************************************
 * FUNCTION
 *  gif_sw_resizer_put_8
 * DESCRIPTION
 *  dummy put pixel function
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
void gif_sw_resizer_put_8(kal_int32* want_sx, gif_sw_color c, kal_bool want_draw)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/


   if(want_draw)
   {
      *((kal_uint8*)GIF_SW_RESIZER.dest) = (kal_uint8)c;
   }

   GIF_SW_RESIZER.dest+=1;
   _gif_sw_resizer_update_want_x(want_sx);
   
}


/*****************************************************************************
 * FUNCTION
 *  gif_sw_resizer_put_16
 * DESCRIPTION
 *  dummy put pixel function
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
void gif_sw_resizer_put_16(kal_int32* want_sx, gif_sw_color c, kal_bool want_draw)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/

   if(want_draw)
   {
     *((kal_uint16*)GIF_SW_RESIZER.dest) = (kal_uint16)c;
   }

   GIF_SW_RESIZER.dest+=2;
   // generate next_position
   _gif_sw_resizer_update_want_x(want_sx);
}


/*****************************************************************************
 * FUNCTION
 *  gif_sw_resizer_put_24
 * DESCRIPTION
 *  dummy put pixel function
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
void gif_sw_resizer_put_24(kal_int32* want_sx, gif_sw_color c,kal_bool want_draw)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/

   if(want_draw)
   {
      _put_24(c, (GIF_SW_RESIZER.dest));
   }

   GIF_SW_RESIZER.dest+=3;
   _gif_sw_resizer_update_want_x(want_sx);
}



void gif_sw_resizer_put_6666(kal_int32* want_sx, gif_sw_color c,kal_bool want_draw)
{
   gif_sw_resizer_put_24(want_sx, c, want_draw);
}

/*****************************************************************************
 * FUNCTION
 *  gif_sw_resizer_put_32
 * DESCRIPTION
 *  dummy put pixel function
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
void gif_sw_resizer_put_32(kal_int32* want_sx, gif_sw_color c,kal_bool want_draw)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/

   if(want_draw)
   {
      *(kal_uint32*)(GIF_SW_RESIZER.dest) = (kal_uint32)c;
   }

   GIF_SW_RESIZER.dest+=4;
   _gif_sw_resizer_update_want_x(want_sx);
}

#if  DRV_MAINLCD_BIT_PER_PIXEL ==  1 || !defined(GIF_SW_USING_LAYER)
/*****************************************************************************
 * FUNCTION
 *  gif_sw_resizer_put_mainlcd
 * DESCRIPTION
 *  put pixel
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
void gif_sw_resizer_put_mainlcd(kal_int32* want_sx, gif_sw_color c, kal_bool want_draw)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   /*
    * W06.26 Fix the wrong position GIF_SW_RESIZER.want_sx and GIF_SW_RESIZER.want_sy
    * Use GIF_SW_RESIZER.next_want_sx - GIF_SW_RESIZER.want_sx_table instead of GIF_SW_RESIZER.want_sx
    * as jumping to the next pixel
    * GIF_SW_RESIZER.next_want_dy - 1 is the current y position
    */
   if(want_draw)
   {
      DRV_MAINLCD_SET_BUFFER_PIXEL_EXT(
        GIF_SW_RESIZER.next_want_dx - 1, /*GIF_SW_RESIZER.want_dx1 + (int)(GIF_SW_RESIZER.next_want_sx - GIF_SW_RESIZER.want_sx_table) - 1*/
        GIF_SW_RESIZER.next_want_dy - 1,
        c,
        g_gif_sw_dest_buf_ptr,
        g_gif_sw_dest_buf_width);
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
#else
   _gif_sw_resizer_update_want_x(want_sx);
#endif 
}
#elif DRV_MAINLCD_BIT_PER_PIXEL == 16
  #define gif_sw_resizer_put_mainlcd  gif_sw_resizer_put_16
#elif DRV_MAINLCD_BIT_PER_PIXEL == 24
  #define gif_sw_resizer_put_mainlcd  gif_sw_resizer_put_24
#elif DRV_MAINLCD_BIT_PER_PIXEL == 32
  #define gif_sw_resizer_put_mainlcd  gif_sw_resizer_put_32
#else
  #error "Unknown MAINLCD_BIT_PER_PIXEL"
#endif

#ifdef DUAL_LCD
#if DRV_SUBLCD_BIT_PER_PIXEL ==  1 || !defined(GIF_SW_USING_LAYER)
/*****************************************************************************
 * FUNCTION
 *  gif_sw_resizer_put_sublcd
 * DESCRIPTION
 *  put pixel
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
void gif_sw_resizer_put_sublcd(kal_int32* want_sx, gif_sw_color c, kal_bool want_draw)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   /*
    * W06.26 Fix the wrong position GIF_SW_RESIZER.want_sx and GIF_SW_RESIZER.want_sy
    * Use GIF_SW_RESIZER.next_want_sx - GIF_SW_RESIZER.want_sx_table instead of GIF_SW_RESIZER.want_sx
    * as jumping to the next pixel
    * GIF_SW_RESIZER.next_want_dy - 1 is the current y position
    */
   if(want_draw)
   {
      DRV_SUBLCD_SET_BUFFER_PIXEL_EXT(
        GIF_SW_RESIZER.next_want_dx - 1, //GIF_SW_RESIZER.want_dx1 + (int)(GIF_SW_RESIZER.next_want_sx - GIF_SW_RESIZER.want_sx_table) - 1,
        GIF_SW_RESIZER.next_want_dy - 1,
        c,
        g_gif_sw_dest_buf_ptr,
        g_gif_sw_dest_buf_width);
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
#else
   _gif_sw_resizer_update_want_x(want_sx);
#endif 	
}
#elif DRV_SUBLCD_BIT_PER_PIXEL == 16
  #define gif_sw_resizer_put_sublcd   gif_sw_resizer_put_16
#elif DRV_SUBLCD_BIT_PER_PIXEL == 24
  #define gif_sw_resizer_put_sublcd   gif_sw_resizer_put_24
#elif DRV_SUBLCD_BIT_PER_PIXEL == 32
  #define gif_sw_resizer_put_sublcd   gif_sw_resizer_put_32
#else
  #error "Unknown SUBLCD_BIT_PER_PIXEL"
#endif
#endif


__inline void _gif_sw_non_resizer_update_wanty(kal_int32* want_sx, kal_bool interlaced)
{
   //if (GIF_SW_RESIZER.next_want_dx >= GIF_SW_RESIZER.want_end_dx)
   //use want_sx to replace GIF_SW_RESIZER.next_want_dx to enhance performance
   //and we don't need to update next_want_dx for non-resized case
   //if (*want_sx >= GIF_SW_RESIZER.want_end_sx) 
   if (GIF_SW_RESIZER.next_want_dx >= GIF_SW_RESIZER.want_end_dx)
   {
      if (interlaced)
      {
          //MAUI_03074035: Originally the condition check is 
          // (GIF_SW_RESIZER.want_sy != GIF_SW_RESIZER.want_end_sy)
          // When (GIF_SW_RESIZER.want_sy == GIF_SW_RESIZER.want_end_sy),
          // set *want_sx = 0x0fffffff (at the time, GIF_SW_RESIZER.next_want_dx >= GIF_SW_RESIZER.want_end_dx is TRUE)
          // and then return back to _gif_sw_codec(~), and continue to call gif_sw_resizer_update_interlaced_want_sy(~)
          // At this function, we will update these information: want_sx, want_sy and dest.
          // Back to the Y-loop and start the new line, when running to put_pixel(~), we find that the want_sx is not been update.
          // Check this and figure out that: due to GIF_SW_RESIZER.next_want_dx == GIF_SW_RESIZER.want_end_dx,
          // This pixel is not output to the destination buffer. And then we know that when GIF_SW_RESIZER.want_sy == GIF_SW_RESIZER.want_end_sy
          // we still need to update GIF_SW_RESIZER.next_want_dx for next line to work correctly.
          if(GIF_SW_RESIZER.want_sy <= GIF_SW_RESIZER.want_end_sy)
          {
             *want_sx = GIF_SW_RESIZER.want_start_sx;
             GIF_SW_RESIZER.want_sy += GIF_SW_RESIZER.dir_y;
             GIF_SW_RESIZER.dest += GIF_SW_RESIZER.dest_pitch_jump;
             GIF_SW_RESIZER.next_want_dx = GIF_SW_RESIZER.want_start_dx;
          }
          else/* move to next line begin */
          {
             *want_sx = 0x0fffffff;/* very large number */
             //printf("want_sy = %d, want_end_sy=%d\n", GIF_SW_RESIZER.want_sy, GIF_SW_RESIZER.want_end_sy);
          }
      }
      else
      {          
          // This function is called at each line end to calculate the next y value. Thus 
          // For non-interlaced case, when want_sy == want_end_sy, it means all
          // the decoding was done. So we shall write the condition as 
          // (GIF_SW_RESIZER.want_sy != GIF_SW_RESIZER.want_end_sy) or 
          // (GIF_SW_RESIZER.want_sy < GIF_SW_RESIZER.want_end_sy).
          // Otherwise, we might encoder write the dest buffer outside the clip window.
          // At the worst case, we might crupt memory, and lead to fatal error.
          // MAUI_03090849, and MAUI_03091397 are CRs due to we masking the condition.
          // We need this condition to check if the next y (want_sy) is in the clip window region.
          // As for the condition check if ((x == wantx) && ((src_clipy1 + offset) == GIF_SW_RESIZER.want_sy))  
          // in _gif_sw_codec(~),  it check if current traversing source_y is what we want (want_sy).
          if(GIF_SW_RESIZER.want_sy != GIF_SW_RESIZER.want_end_sy)
      {
         *want_sx = GIF_SW_RESIZER.want_start_sx;
         GIF_SW_RESIZER.want_sy += GIF_SW_RESIZER.dir_y;
         GIF_SW_RESIZER.dest += GIF_SW_RESIZER.dest_pitch_jump;
         GIF_SW_RESIZER.next_want_dx = GIF_SW_RESIZER.want_start_dx;
      }
          else/* move to next line begin */
          {
             *want_sx = 0x0fffffff;/* very large number */
             //printf("want_sy = %d, want_end_sy=%d\n", GIF_SW_RESIZER.want_sy, GIF_SW_RESIZER.want_end_sy);
          }
      }
      return;
   }
   else
   {
      //SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_sw_non_resizer_update_wanty() return.\n");
      return;
   }
}


__inline void _gif_sw_resizer_update_wanty(kal_int32* want_sx, kal_bool interlaced)
{
   if (GIF_SW_RESIZER.next_want_dx >= GIF_SW_RESIZER.want_end_dx)
   {
      GIF_SW_RESIZER.dest = g_gif_sw_dest_buf_ptr + (GIF_SW_RESIZER.want_start_dx + GIF_SW_RESIZER.next_want_dy * g_gif_sw_dest_buf_width )*gif_sw_resizer_output_fmt_bpp;
      GIF_SW_RESIZER.want_fpsy = FADD(GIF_SW_RESIZER.want_fpsy, GIF_SW_RESIZER.y_resize_jump_distance, FIX_PONT_Q);
      GIF_SW_RESIZER.want_sy = TOINT(GIF_SW_RESIZER.want_fpsy, FIX_PONT_Q);
      if (LARGER_THAN_HALF(GIF_SW_RESIZER.want_fpsy))
      {
         GIF_SW_RESIZER.want_sy++;
      }
      if(GIF_SW_RESIZER.next_want_dy < GIF_SW_RESIZER.want_dy1 || GIF_SW_RESIZER.next_want_dy > GIF_SW_RESIZER.want_dy2)
      {
         gif_sw_resizer_put=gif_sw_resizer_put_null;
         return;
      }
      GIF_SW_RESIZER.next_want_dy += GIF_SW_RESIZER.dir_y;
      GIF_SW_RESIZER.next_want_dx = GIF_SW_RESIZER.want_start_dx;
      GIF_SW_RESIZER.want_fpsx = GIF_SW_RESIZER.want_start_fpsx; 
      *want_sx = TOINT(GIF_SW_RESIZER.want_fpsx, FIX_PONT_Q);
      return;
   }
}

/*****************************************************************************
 * FUNCTION
 *  gif_sw_non_resizer_put_8
 * DESCRIPTION
 *  dummy put pixel function
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
void gif_sw_non_resizer_put_8(kal_int32* want_sx, gif_sw_color c,kal_bool want_draw)
{
   #define GIF_SW_RESIZER_PUT_PIXEL(COLOR)  *((kal_uint8*)GIF_SW_RESIZER.dest) = (kal_uint8)COLOR
   #define GIF_SW_RESIZER_INCREASE_DEST     GIF_SW_RESIZER.dest ++
   GIF_SW_NON_RESIZER_PUT_X(want_sx, c,want_draw);
   #undef GIF_SW_RESIZER_PUT_PIXEL
   #undef GIF_SW_RESIZER_INCREASE_DEST
}


/*****************************************************************************
 * FUNCTION
 *  gif_sw_non_resizer_put_16
 * DESCRIPTION
 *  dummy put pixel function
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
void gif_sw_non_resizer_put_16(kal_int32* want_sx, gif_sw_color c,kal_bool want_draw)
{
   #define GIF_SW_RESIZER_PUT_PIXEL(COLOR)   *((kal_uint16*)GIF_SW_RESIZER.dest) = (kal_uint16)COLOR
   #define GIF_SW_RESIZER_INCREASE_DEST      GIF_SW_RESIZER.dest +=2
   GIF_SW_NON_RESIZER_PUT_X(want_sx, c,want_draw);
   #undef GIF_SW_RESIZER_PUT_PIXEL
   #undef GIF_SW_RESIZER_INCREASE_DEST
}


/*****************************************************************************
 * FUNCTION
 *  gif_sw_non_resizer_put_24
 * DESCRIPTION
 *  dummy put pixel function
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
void gif_sw_non_resizer_put_24(kal_int32* want_sx, gif_sw_color c,kal_bool want_draw)
{
  #define GIF_SW_RESIZER_PUT_PIXEL(COLOR)      \
  do                                           \
  {                                            \
      _put_24(COLOR, GIF_SW_RESIZER.dest);     \
  }while(0)

  #define GIF_SW_RESIZER_INCREASE_DEST      GIF_SW_RESIZER.dest +=3
  GIF_SW_NON_RESIZER_PUT_X(want_sx, c,want_draw);
  #undef GIF_SW_RESIZER_PUT_PIXEL
  #undef GIF_SW_RESIZER_INCREASE_DEST
}


void gif_sw_non_resizer_put_6666(kal_int32* want_sx, gif_sw_color c,kal_bool want_draw)
{
   gif_sw_non_resizer_put_24(want_sx, c,want_draw);
}


/*****************************************************************************
 * FUNCTION
 *  gif_sw_non_resizer_put_32
 * DESCRIPTION
 *  dummy put pixel function
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
void gif_sw_non_resizer_put_32(kal_int32* want_sx, gif_sw_color c,kal_bool want_draw)
{
   #define GIF_SW_RESIZER_PUT_PIXEL(COLOR)     *((kal_uint32*)GIF_SW_RESIZER.dest) = (kal_uint32)COLOR
   #define GIF_SW_RESIZER_INCREASE_DEST        GIF_SW_RESIZER.dest +=4
   GIF_SW_NON_RESIZER_PUT_X(want_sx, c,want_draw);
   #undef GIF_SW_RESIZER_PUT_PIXEL
   #undef GIF_SW_RESIZER_INCREASE_DEST
}


#if  DRV_MAINLCD_BIT_PER_PIXEL ==  1 || !defined(GIF_SW_USING_LAYER)
/*****************************************************************************
 * FUNCTION
 *  gif_sw_non_resizer_put_mainlcd
 * DESCRIPTION
 *  put pixel
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
void gif_sw_non_resizer_put_mainlcd(kal_int32* want_sx, gif_sw_color c, kal_bool want_draw)
{
   #define GIF_SW_RESIZER_PUT_PIXEL(COLOR)    DRV_MAINLCD_SET_BUFFER_PIXEL_EXT((GIF_SW_RESIZER.offset_dx + GIF_SW_RESIZER.want_sx),(GIF_SW_RESIZER.offset_dy + GIF_SW_RESIZER.want_sy),COLOR, g_gif_sw_dest_buf_ptr, g_gif_sw_dest_buf_width)
   #define GIF_SW_RESIZER_INCREASE_DEST
   GIF_SW_NON_RESIZER_PUT_X(want_sx, c,want_draw);
   #undef GIF_SW_RESIZER_PUT_PIXEL
   #undef GIF_SW_RESIZER_INCREASE_DEST
}
#elif DRV_MAINLCD_BIT_PER_PIXEL == 16
   #define gif_sw_non_resizer_put_mainlcd  gif_sw_non_resizer_put_16
#elif DRV_MAINLCD_BIT_PER_PIXEL == 24
   #define gif_sw_non_resizer_put_mainlcd  gif_sw_non_resizer_put_24
#elif DRV_MAINLCD_BIT_PER_PIXEL == 32
   #define gif_sw_non_resizer_put_mainlcd  gif_sw_non_resizer_put_32
#else
   #error "Unknown MAINLCD_BIT_PER_PIXEL"
#endif

#ifdef DUAL_LCD
#if DRV_SUBLCD_BIT_PER_PIXEL ==  1 || !defined(GIF_SW_USING_LAYER)
/*****************************************************************************
 * FUNCTION
 *  gif_sw_non_resizer_put_sublcd
 * DESCRIPTION
 *  put pixel
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
void gif_sw_non_resizer_put_sublcd(kal_int32* want_sx, gif_sw_color c, kal_bool want_draw)
{
   #define GIF_SW_RESIZER_PUT_PIXEL(COLOR)    DRV_SUBLCD_SET_BUFFER_PIXEL_EXT((GIF_SW_RESIZER.offset_dx + GIF_SW_RESIZER.want_sx),(GIF_SW_RESIZER.offset_dy + GIF_SW_RESIZER.want_sy),COLOR, g_gif_sw_dest_buf_ptr, g_gif_sw_dest_buf_width)
   #define GIF_SW_RESIZER_INCREASE_DEST
   GIF_SW_NON_RESIZER_PUT_X(want_sx, c,want_draw);
   #undef GIF_SW_RESIZER_PUT_PIXEL
   #undef GIF_SW_RESIZER_INCREASE_DEST
}
#elif DRV_SUBLCD_BIT_PER_PIXEL == 16
   #define gif_sw_non_resizer_put_sublcd   gif_sw_non_resizer_put_16
#elif DRV_SUBLCD_BIT_PER_PIXEL == 24
   #define gif_sw_non_resizer_put_sublcd   gif_sw_non_resizer_put_24
#elif DRV_SUBLCD_BIT_PER_PIXEL == 32
   #define gif_sw_non_resizer_put_sublcd   gif_sw_non_resizer_put_32
#else
   #error "Unknown MAINLCD_BIT_PER_PIXEL"
#endif
#endif


const static gif_sw_resizer_put_func gif_sw_resizer_put_table[]=
{
   (gif_sw_resizer_put_func)gif_sw_null_pointer_function, // 1
   gif_sw_resizer_put_8, // 8
   gif_sw_resizer_put_16, // 16
   gif_sw_resizer_put_24, // 24
   gif_sw_resizer_put_24, // argb6666
   gif_sw_resizer_put_32, // 32
   gif_sw_resizer_put_32, // 32pargb
   gif_sw_resizer_put_mainlcd,
#ifdef DUAL_LCD
   gif_sw_resizer_put_sublcd
#else
   (gif_sw_resizer_put_func)gif_sw_null_pointer_function // sub
#endif
};
const static gif_sw_resizer_put_func gif_sw_non_resizer_put_table[]=
{
  (gif_sw_resizer_put_func)gif_sw_null_pointer_function, // 1
  gif_sw_non_resizer_put_8, // 8
  gif_sw_non_resizer_put_16, // 16
  gif_sw_non_resizer_put_24, // 24
  gif_sw_non_resizer_put_24, // argb6666
  gif_sw_non_resizer_put_32, // 32
  gif_sw_non_resizer_put_32, // 32pargb
  gif_sw_non_resizer_put_mainlcd,
#ifdef DUAL_LCD
   gif_sw_non_resizer_put_sublcd
#else
   (gif_sw_resizer_put_func)gif_sw_null_pointer_function // sub
#endif
};


/* check rect within clip, if exceed limit, will return */
static kal_uint32 _gif_sw_clip_two_rect(
   kal_int32 *X1,
   kal_int32 *Y1,
   kal_int32 *X2,
   kal_int32 *Y2,
   kal_int32 *CX1,
   kal_int32 *CY1,
   kal_int32 *CX2,
   kal_int32 *CY2)
{
   if(*X1 > *X2) { return KAL_FALSE; }
   else if(*Y1 > *Y2)  { return KAL_FALSE; }
   else if(*X2 < *CX1) { return KAL_FALSE; }
   else if(*Y2 < *CY1) { return KAL_FALSE; }
   else if(*X1 > *CX2) { return KAL_FALSE; }
   else if(*Y1 > *CY2) { return KAL_FALSE; }
   else
   {
      if(*X1 < *CX1) { *X1 = *CX1; }
      if(*Y1 < *CY1) { *Y1 = *CY1; }
      if(*X2 > *CX2) { *X2 = *CX2; }
      if(*Y2 > *CY2) { *Y2 = *CY2; }
   }
   return KAL_TRUE;
}
extern void (*gif_sw_non_resizer_out_x)(gif_sw_color color, kal_bool fdraw);
/*****************************************************************************
 * FUNCTION
 *  gif_sw_resizer_init
 * DESCRIPTION
 *  init the resizer
 * PARAMETERS
 *  src_width              [IN] srouce width
 *  src_height             [IN] source height
 *  src_clipx1             [IN] source clip x1
 *  src_clipy1             [IN] source clip y1
 *  src_clipx2             [IN] source clip x2
 *  src_clipy2             [IN] source clip y2
 *  dest_x1                [IN] destination x1
 *  dest_y1                [IN] destination y1
 *  dest_x2                [IN] destination x2
 *  dest_y2                [IN] destination y2
 *  buf                    [IN] resizer array buffer
 *  buf_elements_cnt       [IN] elements count in the resizer array buffer
 * RETURNS
 *  kal_int32, return 0 if no pixel to output, 1 if decoder need to continue to decode, -1 if error.
 *****************************************************************************/
GIF_STATUS_ENUM gif_sw_resizer_init(
        kal_int32 src_width,
        kal_int32 src_height,
        kal_int32 src_clipx1,
        kal_int32 src_clipy1,
        kal_int32 src_clipx2,
        kal_int32 src_clipy2,
        kal_int32 dest_x1,
        kal_int32 dest_y1,
        kal_int32 dest_x2,
        kal_int32 dest_y2,
        GIF_COLOR_FORMAT_ENUM dest_color_format)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   kal_int32 dest_width;
   kal_int32 dest_height;
   kal_int32 dir_x;
   kal_int32 dir_y;
   kal_int32 src_width_range;
   kal_int32 src_height_range;
   kal_int32 dest_width_range;
   kal_int32 dest_height_range;

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/

   //resizer_buffer = buf;
   //resizer_buffer_size = buf_elements_cnt;
   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gif_sw_resizer_init() Enter:src_width=%d, src_height=%d, src_clip=(%d, %d)~(%d, %d) , dst_win=(%d, %d)~(%d, %d)\n", 
   src_width, src_height, src_clipx1, src_clipy1, src_clipx2, src_clipy2, dest_x1, dest_y1, dest_x2, dest_y2 );

   GIF_SW_RESIZER.want_sx = GIF_SW_RESIZER.want_sy = -1;

   // we don't support 1, 8 bites color format in this resizer
   if(src_width <= 0) return GIF_STATUS_INVALID_PARAMETER;
   if(src_height <= 0) return GIF_STATUS_INVALID_PARAMETER;

   dir_x=dir_y=1;

   if(dest_x1>dest_x2)
   {
      ASSERT(0); // current, we only support dir_x >0
      SWAP(kal_int32,dest_x1,dest_x2);
      dir_x = -1;
   }
   if(dest_y1>dest_y2)
   {
      SWAP(kal_int32,dest_y1,dest_y2);
      dir_y = -1;
   }


   GIF_SW_RESIZER.dest = g_gif_sw_dest_buf_ptr;
   GIF_SW_RESIZER.offset_dx = dest_x1;
   GIF_SW_RESIZER.offset_dy = dest_y1;
   dest_width = dest_x2-dest_x1+1;
   dest_height = dest_y2-dest_y1+1;
   if(g_gif_sw_set_update_area)
   {
      (*g_gif_sw_set_update_area)(dest_x1,dest_y1,dest_x2,dest_y2);
   }

   GIF_SW_RESIZER.want_dx1 = dest_x1;
   GIF_SW_RESIZER.want_dy1 = dest_y1;
   GIF_SW_RESIZER.want_dx2 = dest_x2;
   GIF_SW_RESIZER.want_dy2 = dest_y2;

   GIF_SW_RESIZER.dir_x = dir_x;
   GIF_SW_RESIZER.dir_y = dir_y;

   // check the clipping area // calculate dirty region for dest_window & dest_clip_window
   if (!_gif_sw_clip_two_rect(&GIF_SW_RESIZER.want_dx1,
                               &GIF_SW_RESIZER.want_dy1,
                               &GIF_SW_RESIZER.want_dx2,
                               &GIF_SW_RESIZER.want_dy2,
                               &g_gif_sw_dest_clipx1,
                               &g_gif_sw_dest_clipy1,
                               &g_gif_sw_dest_clipx2,
                               &g_gif_sw_dest_clipy2))
   {
      SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gif_sw_resizer_init() Fail: _gif_sw_clip_two_rectA \n");
      return GIF_STATUS_OUTPUT_WINDOW_NO_INTERSECTION;
   }
   //GIF_SW_CLIP_RECT_TEST(GIF_SW_RESIZER.want_dx1,GIF_SW_RESIZER.want_dy1,GIF_SW_RESIZER.want_dx2,GIF_SW_RESIZER.want_dy2,return 0); // no pixel will be render !!

   /* W06.16 Use Coordinate Range instead of width and height */
   /* Use round off to compute want_sx and want_sy */
   if (1 == src_width)
   {
      src_width = 2;
   }
   if (1 == dest_width)
   {
      dest_width = 2;
   }
   if (1 == src_height)
   {
      src_height = 2;
   }
   if (1 == dest_height)
   {
      dest_height = 2;
   }
   src_width_range = src_width - 1;
   src_height_range = src_height - 1;
   dest_width_range = dest_width - 1;
   dest_height_range = dest_height - 1;

   // make y_scale_factor
   GIF_SW_RESIZER.src_width_range = src_width_range;
   GIF_SW_RESIZER.dest_width_range = dest_width_range;
   GIF_SW_RESIZER.src_height_range  = src_height_range;
   GIF_SW_RESIZER.dest_height_range = dest_height_range;

   {
      kal_int32 dx1,dy1,dx2,dy2;
      // check the source clipping area
      dx1 = dest_x1 + (src_clipx1*(dest_width_range))/(src_width_range);
      dx2 = dest_x1 + (src_clipx2*(dest_width_range))/(src_width_range);

      dy1 = dest_y1 + (src_clipy1*(dest_height_range))/(src_height_range);
      dy2 = dest_y1 + (src_clipy2*(dest_height_range))/(src_height_range);
      //SW_GIF_TRACE(MOD_MMI, "[gif] - gif_sw_resizer_init() : want:(%d, %d)~(%d, %d), d:(%d, %d)~(%d, %d)\n", GIF_SW_RESIZER.want_dx1, GIF_SW_RESIZER.want_dy1, GIF_SW_RESIZER.want_dx2, GIF_SW_RESIZER.want_dy2, dx1,dy1, dx2, dy2);

      if (!_gif_sw_clip_two_rect(&GIF_SW_RESIZER.want_dx1,
                                 &GIF_SW_RESIZER.want_dy1,
                                 &GIF_SW_RESIZER.want_dx2,
                                 &GIF_SW_RESIZER.want_dy2,
                                 &dx1,
                                 &dy1,
                                 &dx2,
                                 &dy2))
      {
         SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gif_sw_resizer_init() Fail: _gif_sw_clip_two_rectB \n");
         return GIF_STATUS_OUTPUT_WINDOW_NO_INTERSECTION;
      }

      //W05.39 Check points may be out of clipping area because of dividing
      while ((GIF_SW_RESIZER.want_dx1 < GIF_SW_RESIZER.want_dx2) &&
             ((((GIF_SW_RESIZER.want_dx1 - GIF_SW_RESIZER.offset_dx) * src_width_range)) / (dest_width_range) < src_clipx1))
      {
         GIF_SW_RESIZER.want_dx1++;
      }

      while ((GIF_SW_RESIZER.want_dy1 < GIF_SW_RESIZER.want_dy2) &&
             ((((GIF_SW_RESIZER.want_dy1 - GIF_SW_RESIZER.offset_dy) * src_height_range)) / (dest_height_range) < src_clipy1))
      {
         GIF_SW_RESIZER.want_dy1++;
      }

      while ((GIF_SW_RESIZER.want_dx2 > GIF_SW_RESIZER.want_dx1) &&
             ((((GIF_SW_RESIZER.want_dx2 - GIF_SW_RESIZER.offset_dx) * src_width_range)) / (dest_width_range) > src_clipx2))
      {
         GIF_SW_RESIZER.want_dx2--;
      }

      while((GIF_SW_RESIZER.want_dy2 > GIF_SW_RESIZER.want_dy1) &&
            ((((GIF_SW_RESIZER.want_dy2 - GIF_SW_RESIZER.offset_dy) * src_height_range)) / (dest_height_range)> src_clipy2))
      {
         GIF_SW_RESIZER.want_dy2--;
      }
   }

   //Keep dest start X&Y information
   if(dir_x > 0)
   {
      GIF_SW_RESIZER.want_start_dx = GIF_SW_RESIZER.want_dx1;
      GIF_SW_RESIZER.want_end_dx = GIF_SW_RESIZER.want_dx2;
   }
   else
   {
      GIF_SW_RESIZER.want_start_dx = GIF_SW_RESIZER.want_dx2;
      GIF_SW_RESIZER.want_end_dx = GIF_SW_RESIZER.want_dx1;
   }

   if(dir_y > 0)
   {
      GIF_SW_RESIZER.want_start_dy = GIF_SW_RESIZER.want_dy1;
      GIF_SW_RESIZER.want_end_dy = GIF_SW_RESIZER.want_dy2;
   }
   else
   {
      GIF_SW_RESIZER.want_start_dy = GIF_SW_RESIZER.want_dy2;
      GIF_SW_RESIZER.want_end_dy = GIF_SW_RESIZER.want_dy1;
   }
   GIF_SW_RESIZER.next_want_dx = GIF_SW_RESIZER.want_start_dx;
   GIF_SW_RESIZER.next_want_dy = GIF_SW_RESIZER.want_start_dy;	


   // non resize handler
   if(src_width == dest_width && src_height == dest_height)
   {
      gif_sw_resizer_put = gif_sw_non_resizer_put_table[dest_color_format];
      gif_sw_resizer_output_fmt_bpp = gif_sw_bitsperpixels[dest_color_format] >> 3;
      gif_sw_resizer_update_wanty = _gif_sw_non_resizer_update_wanty;

      GIF_SW_RESIZER.dest = g_gif_sw_dest_buf_ptr;
      if(dir_x >0)
      {
         GIF_SW_RESIZER.want_sx =
            GIF_SW_RESIZER.want_start_sx = GIF_SW_RESIZER.want_dx1 - dest_x1;
         GIF_SW_RESIZER.want_end_sx = GIF_SW_RESIZER.want_dx2 - dest_x1;

         GIF_SW_RESIZER.dest += GIF_SW_RESIZER.want_dx1 * gif_sw_resizer_output_fmt_bpp;
      }
      else
      {
         GIF_SW_RESIZER.want_sx =
            GIF_SW_RESIZER.want_start_sx = GIF_SW_RESIZER.want_dx2 - dest_x1;
         GIF_SW_RESIZER.want_end_sx  = GIF_SW_RESIZER.want_dx1 - dest_x1;
         GIF_SW_RESIZER.dest += GIF_SW_RESIZER.want_dx2 * gif_sw_resizer_output_fmt_bpp;
      }
      if(dir_y >0)
      {
         GIF_SW_RESIZER.want_sy =
            GIF_SW_RESIZER.want_start_sy = GIF_SW_RESIZER.want_dy1 - dest_y1;
         GIF_SW_RESIZER.want_end_sy = GIF_SW_RESIZER.want_dy2 - dest_y1;

         GIF_SW_RESIZER.dest += GIF_SW_RESIZER.want_dy1 * g_gif_sw_dest_buf_width*gif_sw_resizer_output_fmt_bpp;
         GIF_SW_RESIZER.dest_pitch_jump = (g_gif_sw_dest_buf_width - (GIF_SW_RESIZER.want_dx2-GIF_SW_RESIZER.want_dx1+1)) * gif_sw_resizer_output_fmt_bpp;
      }
      else
      {
         GIF_SW_RESIZER.want_sy =
            GIF_SW_RESIZER.want_start_sy = GIF_SW_RESIZER.want_dy2 - dest_y1;
         GIF_SW_RESIZER.want_end_sy = GIF_SW_RESIZER.want_dy1 - dest_y1;

         GIF_SW_RESIZER.dest += GIF_SW_RESIZER.want_dy2 * g_gif_sw_dest_buf_width * gif_sw_resizer_output_fmt_bpp;
         GIF_SW_RESIZER.dest_pitch_jump = -(g_gif_sw_dest_buf_width + (GIF_SW_RESIZER.want_dx2-GIF_SW_RESIZER.want_dx1+1)) * gif_sw_resizer_output_fmt_bpp;
      }
      return GIF_STATUS_OK;
   }


   {
      kal_uint32 a1, b1, a2;

      //x
      //a1 = ((1+dir_x) * src_width_range);
      b1 =  dest_width_range;
      a2 = ((1) * src_width_range);
      GIF_SW_RESIZER.x_resize_jump_distance = FDIV(TOFIX(a2,FIX_PONT_Q), TOFIX(b1,FIX_PONT_Q), FIX_PONT_Q);
      GIF_SW_RESIZER.want_fpsx = FMULI(GIF_SW_RESIZER.x_resize_jump_distance, (GIF_SW_RESIZER.want_start_dx - GIF_SW_RESIZER.offset_dx), FIX_PONT_Q);
      GIF_SW_RESIZER.want_start_fpsx = GIF_SW_RESIZER.want_fpsx;
      GIF_SW_RESIZER.want_start_sx = TOINT(GIF_SW_RESIZER.want_start_fpsx, FIX_PONT_Q);

      //y
      //a1 = ((1+dir_y) * src_height_range);
      b1 =  dest_height_range;
      a2 = ((1) * src_height_range);
      GIF_SW_RESIZER.y_resize_jump_distance = FDIV(TOFIX(a2,FIX_PONT_Q), TOFIX(b1,FIX_PONT_Q), FIX_PONT_Q);
      GIF_SW_RESIZER.want_fpsy = FMULI(GIF_SW_RESIZER.y_resize_jump_distance, (GIF_SW_RESIZER.want_start_dy - GIF_SW_RESIZER.offset_dy), FIX_PONT_Q);
      GIF_SW_RESIZER.want_sy = TOINT(GIF_SW_RESIZER.want_fpsy, FIX_PONT_Q);
      if ((GIF_SW_RESIZER.want_fpsy & 0xFF) >= 0x7F)
      {
         GIF_SW_RESIZER.want_sy++;
      }
      while(GIF_SW_RESIZER.want_sy < src_clipy1)
      {
         GIF_SW_RESIZER.want_fpsy = FADD(GIF_SW_RESIZER.y_resize_jump_distance, (GIF_SW_RESIZER.want_fpsy), FIX_PONT_Q);
         GIF_SW_RESIZER.want_sy = TOINT(GIF_SW_RESIZER.want_fpsy, FIX_PONT_Q);
         if ((GIF_SW_RESIZER.want_fpsy & 0xFF) >= 0x7F)
         {
            GIF_SW_RESIZER.want_sy++;
         }
      }
      GIF_SW_RESIZER.want_start_sy = GIF_SW_RESIZER.want_sy;
   }

   // set the put pixel function pointer
   gif_sw_resizer_put = gif_sw_resizer_put_table[dest_color_format];
   gif_sw_resizer_output_fmt_bpp = gif_sw_bitsperpixels[dest_color_format] >> 3;
   gif_sw_resizer_update_wanty = _gif_sw_resizer_update_wanty;

   // init want position
   GIF_SW_RESIZER.dest = g_gif_sw_dest_buf_ptr + (GIF_SW_RESIZER.want_start_dx + GIF_SW_RESIZER.want_start_dy * g_gif_sw_dest_buf_width )* gif_sw_resizer_output_fmt_bpp;

   GIF_SW_RESIZER.next_want_dy +=dir_y;

   //SW_GIF_TRACE(MOD_MMI, "[gif] - gif_sw_resizer_init() Leave\n");
   return GIF_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  GIF_SW_DRAW_H_LINE
 * DESCRIPTION
 *  draw horizontal line
 * PARAMETERS
 *  x1                [IN]  start x
 *  x2                [IN]  end x
 *  y                 [IN]  horizontal position y
 *  pixel_color       [IN]  line color
 * RETURNS
 *  void
 *****************************************************************************/
static __inline void GIF_SW_DRAW_H_LINE(kal_int32 x1, kal_int32 x2, kal_int32 y, gif_sw_color pixel_color)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   kal_int32 h_index;

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/

   for(h_index = x1; h_index <= x2; h_index++)
   {
      g_gif_sw_act_put_pixel(h_index, y, pixel_color);
   }
}


/*****************************************************************************
 * FUNCTION
 *  GIF_SW_DRAW_RECT
 * DESCRIPTION
 *  draw rectangle
 * PARAMETERS
 *  x1                [IN]  left-up corner x of rectangle
 *  y1                [IN]  left-up corner y of rectangle
 *  x2                [IN]  right-down cornor x of rectangle
 *  y2                [IN]  right-down cornor y of rectangle
 *  pixel_color       [IN]  rectangle color
 * RETURNS
 *  void
 *****************************************************************************/
static __inline void GIF_SW_DRAW_RECT(kal_int32 x1, kal_int32 y1, kal_int32 x2, kal_int32 y2, gif_sw_color pixel_color)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   kal_int32 r_index;

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/

   for(r_index = y1; r_index <=y2; r_index++)
   {
      GIF_SW_DRAW_H_LINE(x1, x2, r_index, pixel_color);
   }
}


/*****************************************************************************
 * FUNCTION
 *  gif_sw_draw_solid_rect
 * DESCRIPTION
 *  draw solid rectangle
 * PARAMETERS
 *  x1                [IN]  left-up corner x of rectangle
 *  y1                [IN]  left-up corner y of rectangle
 *  x2                [IN]  right-down cornor x of rectangle
 *  y2                [IN]  right-down cornor y of rectangle
 *  pixel_color       [IN]  rectangle color
 * RETURNS
 *  void
 *****************************************************************************/
void gif_sw_draw_solid_rect(kal_int32 x1, kal_int32 y1, kal_int32 x2, kal_int32 y2, gif_sw_color rect_color)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/

   do
   {
      //GIF_SW_CLIP_RECT_TEST(x1,y1,x2,y2,break);
      if (!_gif_sw_clip_two_rect(&x1, &y1, &x2, &y2,
                                  &g_gif_sw_dest_clipx1,
                                  &g_gif_sw_dest_clipy1,
                                  &g_gif_sw_dest_clipx2,
                                  &g_gif_sw_dest_clipy2))
      {
         break;
      }

      GIF_SW_DRAW_RECT(x1, y1, x2, y2, rect_color);
   }while(0);
}

#define GIF_MIN(A,B) ((A)<(B)?(A):(B))
//#define GIF_MAX(A,B) ((A)>(B)?(A):(B))

#define JUMP_PIXEL(PTR,N,PIXEL_BYTES)   PTR = (((kal_uint8*)PTR)+(N)* PIXEL_BYTES)

void _gif_sw_BITBLT(
    kal_uint8 *dest,
    kal_int32 dw,
    kal_int32 dx1,
    kal_int32 dy1,
    kal_int32 dx2,
    kal_int32 dy2,
    kal_uint8 *src,
    kal_int32 sw,
    kal_int32 sx1,
    kal_int32 sy1,
    kal_int32 sx2,
    kal_int32 sy2,
    kal_int32 clipx1,
    kal_int32 clipy1,
    kal_int32 clipx2,
    kal_int32 clipy2,
    kal_uint16 pixel_bytes)
{
   kal_int32 w, h;

   /* process clipping */
   {
      kal_int32 old_dx, old_dy;
      kal_int32 offset_x, offset_y;

      /*----------------------------------------------------------------*/
      /* Code Body                                                      */
      /*----------------------------------------------------------------*/
      old_dx = dx1;
      old_dy = dy1;

      //GIF_SW_CLIP_TWO_RECT(dx1, dy1, dx2, dy2, clipx1, clipy1, clipx2, clipy2, return);
      if (!_gif_sw_clip_two_rect(&dx1, &dy1, &dx2, &dy2, &clipx1, &clipy1, &clipx2, &clipy2))
      {
         return;
      }

      offset_x = dx1 - old_dx;
      offset_y = dy1 - old_dy;

      sx1 += offset_x;
      sy1 += offset_y;
   }

   /* calculate the copy area */
   {
      kal_int32 a, b;

      a = dx2 - dx1 + 1;
      b = sx2 - sx1 + 1;
      w = GIF_MIN(a, b);

      a = dy2 - dy1 + 1;
      b = sy2 - sy1 + 1;
      h = GIF_MIN(a, b);
      if (w <= 0 || h <= 0)
      {
         return;
      }
   }

   /* start to copy data */
   {
      kal_uint8 *s;
      kal_uint8 *d;
      kal_int32 y;

      s = (kal_uint8*) (src + (sx1 + sy1 * sw) * pixel_bytes);
      d = (kal_uint8*) (dest + (dx1 + dy1 * dw) * pixel_bytes);

      for (y = h - 1; y >= 0; y--)
      {
         memcpy(d, s, w * pixel_bytes);
         JUMP_PIXEL(s, sw, pixel_bytes);
         JUMP_PIXEL(d, dw, pixel_bytes);

      }
   }
}

// draw line with single color
static __inline void gif_draw_line_32(void* bufAddress, kal_int32 x1, kal_int32 length, kal_uint32 bgColor)
{
   kal_uint32* startaddress = (kal_uint32*)bufAddress;
   startaddress = startaddress + x1;

   while(length--)
   {
      *startaddress++ = bgColor;
   }
}

static __inline void gif_draw_line_24(void* bufAddress, kal_int32 x1, kal_int32 length, kal_uint32 bgColor)
{
   kal_uint8* startaddress = (kal_uint8*)bufAddress;
   kal_uint8 R,G,B;
   startaddress = startaddress + x1;
   R = (bgColor & 0xff0000) >> 16;
   G = (bgColor & 0xff00) >> 8;
   B = (bgColor & 0xff);

   while(length--)
   {
      *startaddress++ = R;
      *startaddress++ = G;
      *startaddress++ = B;
   }
}


static __inline void gif_draw_line_6666(void* bufAddress, kal_int32 x1, kal_int32 length, kal_uint32 bgColor)
{
   /*kal_uint8* startaddress = (kal_uint8*)bufAddress;
   kal_uint8 p1,p2,p3;
   startaddress = startaddress + x1;
   p1 = (bgColor & 0xFF0000) >> 16; //A[5-0]+R[5-4]
   p2 = (bgColor & 0xFF00) >> 8; //R[3-0]+G[5-2]
   p3 = (bgColor & 0xFF) ;     //G[1-0]+B[5-0]

   while(length--)
   {
      *startaddress++ = p1;
      *startaddress++ = p2;
      *startaddress++ = p3;
   }*/
  gif_draw_line_24(bufAddress, x1, length, bgColor);
}



static __inline void gif_draw_line_16(void* bufAddress, kal_int32 x1, kal_int32 length, kal_uint32 bgColor)
{
   kal_uint16* startaddress = (kal_uint16*)bufAddress;
   startaddress = startaddress + x1;

   while(length--)
   {
      *startaddress++ = (kal_uint16)bgColor;
   }
}

static __inline void gif_draw_line_8(void* bufAddress, kal_int32 x1, kal_int32 length, kal_uint32 bgColor)
{
   kal_uint8* startaddress = (kal_uint8*)bufAddress;
   startaddress = startaddress + x1;

   while(length--)
   {
      *startaddress++ = (kal_uint8)bgColor;
   }
}

typedef void (*gif_draw_line) (void* bufAddress, kal_int32 x1, kal_int32 length, kal_uint32 bgColor);

const static gif_draw_line gif_draw_bg_rect_table[] =
{
   (gif_draw_line)gif_sw_null_pointer_function,
   gif_draw_line_8,  // index color
   gif_draw_line_16, // RGB565
   gif_draw_line_24, // RGB888
   gif_draw_line_6666, // argb6666
   gif_draw_line_32, // ARGB8888
};





// draw rectangle background with single color
kal_int32 gif_draw_bg_rect(void* bufAddress, kal_int32 dstBuf_w, kal_int32 dstBuf_h, kal_uint32 bytesPerPixel,
              kal_int32 fillArea_x, kal_int32 fillArea_y, kal_int32 fillArea_w, kal_int32 fillArea_h, kal_uint32 bgColor)
{
   kal_uint8* startaddress = (kal_uint8*)bufAddress;
   kal_int32 count;
   gif_draw_line func_ptr;

   if ((fillArea_y + fillArea_h) > dstBuf_h)
   {
      return -1;
   }

   if (bytesPerPixel > 4)
   {
      return -1;
   }

   func_ptr = gif_draw_bg_rect_table[bytesPerPixel];

   //offset to (0, y) position.
   startaddress = startaddress + bytesPerPixel*dstBuf_w*fillArea_y;
   for(count = 0; count < fillArea_h; count++)
   {
      //draw line
      func_ptr(startaddress, fillArea_x, fillArea_w, bgColor);
      //offset to next line
      startaddress = startaddress + bytesPerPixel*dstBuf_w;
   }

   return 0;
}


