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
 *  gif_decode_int_sw_util.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _SW_GIF_UTIL_H_
#define _SW_GIF_UTIL_H_

#if defined (__MTK_TARGET__)
#include "kal_public_api.h"
#endif
#include "kal_general_types.h"
#include "gif_decode_int_sw.h"
#include "drv_sw_features_display.h"
#include "gif_decode_api.h"
/****************************************************************************
* Include
*****************************************************************************/
/* catch */
#ifdef STDC_HEADERS
    //#include <stdio.h>
    #include <setjmp.h> /* for jmp_buf type, setjmp and longjmp */
#else
    #ifndef _JMP_BUF_DEFINED
        typedef int jmp_buf[16];
        #define _JMP_BUF_DEFINED
    #endif
#endif

/****************************************************************************
* Define
*****************************************************************************/
#define GIF_SW_FUNC_1(NAME)         (NAME##_func) gif_sw_null_pointer_function
#define GIF_SW_FUNC_8(NAME)         (NAME##_func) NAME##_8
#define GIF_SW_FUNC_16(NAME)        (NAME##_func) NAME##_16
#define GIF_SW_FUNC_24(NAME)        (NAME##_func) NAME##_24
#define GIF_SW_FUNC_argb6666(NAME)  (NAME##_func) NAME##_6666
#define GIF_SW_FUNC_32(NAME)        (NAME##_func) NAME##_32

#if defined (DRV_PALETTE_RGB_888)
    #define GIF_SW_PALETTE_COLOR_FROM_RGB     gif_sw_color_from_rgb_24
    #define GIF_SW_PALETTE_COLOR_TO_RGB       gif_sw_color_to_rgb_24
#elif defined(DRV_PALETTE_RGB_565)
    #define GIF_SW_PALETTE_COLOR_FROM_RGB     gif_sw_color_from_rgb_16
    #define GIF_SW_PALETTE_COLOR_TO_RGB       gif_sw_color_to_rgb_16
#elif defined(DRV_PALETTE_RGB_666)
    #define GIF_SW_PALETTE_COLOR_FROM_RGB     gif_sw_color_from_rgb_6666
    //#define GIF_SW_PALETTE_COLOR_TO_RGB       gif_sw_color_to_rgb_argb6666
#else
    #define GIF_SW_PALETTE_COLOR_FROM_RGB     gif_sw_color_from_rgb_16
    #define GIF_SW_PALETTE_COLOR_TO_RGB       gif_sw_color_to_rgb_16
#endif

/* catch */
#ifdef GIF_WIN32
#define GIF_SW_RAISE(ret_code)   
#define GIF_SW_TRY if(1)
#define GIF_SW_CATCH_BEGIN                     else      
#define GIF_SW_CATCH_END 
#define GIF_SW_GET_CATCH_STATUS     0
#else
#define GIF_SW_RAISE(ret_code)   longjmp (gif_sw_jmpbuf, ret_code)
#define GIF_SW_TRY                      \
   {                                    \
      int jmpret;                       \
      ASSERT(!gif_sw_jmpbuf_is_used);   \
      gif_sw_jmpbuf_is_used = KAL_TRUE; \
      jmpret = setjmp (gif_sw_jmpbuf);  \
      if(jmpret == 0 )                  \
      {

#define GIF_SW_CATCH_BEGIN              \
      }                                 \
      else                              \
      {                                 \
         {

#define GIF_SW_CATCH_END                \
         }                              \
      }                                 \
      gif_sw_jmpbuf_is_used = KAL_FALSE;\
   }
#define GIF_SW_GET_CATCH_STATUS     jmpret

#endif//GIF_WIN32
#define GIF_SW_CATCH(N) if(jmpret == N)

/* Software resizer */
#define IS_GIF_SW_RESIZER_WANT_DRAW(SX,SY)   (SX == GIF_SW_RESIZER.want_sx && SY == GIF_SW_RESIZER.want_sy)


#define GIF_SW_NON_RESIZER_PUT_X(WANT_X, COLOR, WANT_DRAW)        \
   {                                                              \
      if(WANT_DRAW)                                               \
         GIF_SW_RESIZER_PUT_PIXEL(COLOR);                         \
      GIF_SW_RESIZER_INCREASE_DEST;                               \
      if((GIF_SW_RESIZER.next_want_dx) != GIF_SW_RESIZER.want_end_dx)  \
      {                                                                  \
         (*WANT_X) += GIF_SW_RESIZER.dir_x;                              \
         GIF_SW_RESIZER.next_want_dx += GIF_SW_RESIZER.dir_x;          \
      }                                                                  \
   }

#define SWAP(t,a,b) do {t tmp=a;a=b;b=tmp;} while(0)

/****************************************************************************
* Struct
*****************************************************************************/
/* Software resizer */
typedef struct
{
    kal_uint8 *dest;                /* the output memory position in layer */
    kal_int32 bitsperpixels;        /* bits per pixel */
    kal_int32 src_width_range;     /* source width */
    kal_int32 dest_width_range;     /* source width */
    kal_int32 src_height_range;     /* source height */
    kal_int32 dest_height_range;    /* destination height */
    kal_int32 offset_dx;            /* destinaiton left-up cornor x1 */
    kal_int32 offset_dy;            /* destination left-up cornor y1 */

    /* for non resize used */
    kal_int32 want_start_sx, want_start_sy; /* start point */
    kal_int32 want_end_sx, want_end_sy;     /* end point */
    kal_int32 dest_pitch_jump;              /* destination pitch */

    /* for resize used */
    kal_int32 want_dx1, want_dx2;   /* wanted rendering area, destination area after clipping */
    kal_int32 want_dy1, want_dy2;
    kal_int32 want_start_fpsx;
    kal_int32 want_fpsx;            /*want sx in fixed point format  */  
    kal_int32 want_sx;              /* current output point */
    kal_int32 want_fpsy;            /*want sy in fixed point format  */
    kal_int32 want_sy;

    //kal_int16 *want_sx_table;       /* table used to store the sx that each dx corresponding to */
    //kal_int16 *want_sx_table_end;   /* the end of table */
    //kal_int16 *next_want_sx;        /* points to next want_sx */

    kal_int32 dir_x;                /* the direction to draw the x, only support dir_x>0 currently */
    kal_int32 dir_y;

    //dest image control info
    kal_int32 next_want_dy;         /* points to next want_dy */
    kal_int32 next_want_dx;         /* points to next want_dy */
	 
    kal_int32 want_start_dx;        /*consider the dir_x to determine the real start X */
    kal_int32 want_end_dx;          /*consider the dir_x to determine the real end X   */
    kal_int32 want_start_dy;        /*consider the dir_x to determine the real start y */
    kal_int32 want_end_dy;          /*consider the dir_x to determine the real end y   */

    kal_int32  x_resize_jump_distance;
    kal_int32  y_resize_jump_distance;

} gif_sw_resizer_struct;

/****************************************************************************
* Variable
*****************************************************************************/
/* catch */
extern jmp_buf      gif_sw_jmpbuf;
extern kal_bool     gif_sw_jmpbuf_is_used;

/****************************************************************************
* Function
*****************************************************************************/
/* Software resizer */
extern gif_sw_resizer_put_func gif_sw_resizer_put;
extern gif_sw_resizer_struct GIF_SW_RESIZER;

extern GIF_STATUS_ENUM gif_sw_resizer_init(
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
                    GIF_COLOR_FORMAT_ENUM dest_color_format);

extern void gif_sw_resizer_update_interlaced_want_sy(kal_bool resize, kal_int32* want_sx, kal_int32 want_sy);

extern void gif_sw_null_pointer_function(void);

/* color from rgb */
extern gif_sw_color gif_sw_color_from_rgb_8(kal_uint32 A, kal_uint32 R, kal_uint32 G, kal_uint32 B);
extern gif_sw_color gif_sw_color_from_rgb_16(kal_uint32 A, kal_uint32 R, kal_uint32 G, kal_uint32 B);
extern gif_sw_color gif_sw_color_from_rgb_24(kal_uint32 A, kal_uint32 R, kal_uint32 G, kal_uint32 B);
extern gif_sw_color gif_sw_color_from_rgb_32(kal_uint32 A, kal_uint32 R, kal_uint32 G, kal_uint32 B);
extern gif_sw_color gif_sw_color_from_rgb_main(kal_uint32 A, kal_uint32 R, kal_uint32 G, kal_uint32 B);
extern gif_sw_color gif_sw_color_from_rgb_sub(kal_uint32 A, kal_uint32 R, kal_uint32 G, kal_uint32 B);

/* get pixel */
extern gif_sw_color gif_sw_get_pixel_8(kal_int32 x, kal_int32 y);
extern gif_sw_color gif_sw_get_pixel_16(kal_int32 x, kal_int32 y);
extern gif_sw_color gif_sw_get_pixel_24(kal_int32 x, kal_int32 y);
extern gif_sw_color gif_sw_get_pixel_32(kal_int32 x, kal_int32 y);
extern gif_sw_color gif_sw_get_pixel_main(kal_int32 x, kal_int32 y);
extern gif_sw_color gif_sw_get_pixel_sub(kal_int32 x, kal_int32 y);

/* put pixel */
extern void gif_sw_put_pixel_8(kal_int32 x, kal_int32 y, gif_sw_color c);
extern void gif_sw_put_pixel_16(kal_int32 x, kal_int32 y, gif_sw_color c);
extern void gif_sw_put_pixel_24(kal_int32 x, kal_int32 y, gif_sw_color c);
extern void gif_sw_put_pixel_32(kal_int32 x, kal_int32 y, gif_sw_color c);
extern void gif_sw_put_pixel_main(kal_int32 x, kal_int32 y, gif_sw_color c);
extern void gif_sw_put_pixel_sub(kal_int32 x, kal_int32 y, gif_sw_color c);

extern const gif_sw_put_pixel_func  gif_sw_put_pixel_array[];
extern const gif_sw_color_from_rgb_func gif_sw_color_from_rgb_array[];
extern const gif_sw_get_pixel_func gif_sw_get_pixel_array[];

/* others */
extern void gif_sw_draw_solid_rect(kal_int32 x1, kal_int32 y1, kal_int32 x2, kal_int32 y2, gif_sw_color rect_color);
extern void _gif_sw_BITBLT(
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
                            kal_uint16 pixel_bytes);

// draw rectangle background with single color
kal_int32 gif_draw_bg_rect(void* bufAddress, kal_int32 dstBuf_w, kal_int32 dstBuf_h, kal_uint32 bytesPerPixel,
							kal_int32 fillArea_x, kal_int32 fillArea_y, kal_int32 fillArea_w, kal_int32 fillArea_h, kal_uint32 bgColor);

#ifndef GIF_WIN32
#if (!defined(LOW_COST_SUPPORT))
//#define __GIF_SWLA_DEBUG__
#define SW_GIF_TRACE  kal_prompt_trace
#define GIF_TRACE_MOD MOD_GFX
#else
#define SW_GIF_TRACE(...)
#endif
#else
#define SW_GIF_TRACE(...)
#define MOD_MMI
#endif

#if defined(__MTK_TARGET__) && defined(__GIF_SWLA_DEBUG__)
#define GIF_SWLA_DEBUG(tag,start) SLA_CustomLogging((tag), (start));
#else
#define GIF_SWLA_DEBUG(tag,start)
#endif

#endif //_SW_GIF_UTIL_H_

