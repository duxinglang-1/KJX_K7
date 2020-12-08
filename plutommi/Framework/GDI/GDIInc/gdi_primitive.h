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
 *  gdi_primitve.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI primitive header file.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _GDI_PRIMITIVE_H_
#define _GDI_PRIMITIVE_H_

#include "kal_release.h"
#include "setjmp.h"
#include "MMIDataType.h"
#include "gdi_datatype.h"
#include "gdi_const.h"

#include "gdi_lcd_config.h"
#include "lcd_sw_inc.h"
#include "gdi_include.h"


/****************************************************************************
* Main LCD                                                                 
*****************************************************************************/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_SUBLCD__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SUBLCD__ */
#endif /* 0 */ 
/* define blue as transprent color */

/* Assert */
#define GDI_ASSERT(exp)       ASSERT(exp)
#define GDI_DEBUG_ASSERT(exp) ASSERT(exp)

extern jmp_buf gdi_jmpbuf;
extern BOOL gdi_jmpbuf_is_used;

#define GDI_RAISE(ret_code)   longjmp (gdi_jmpbuf, ret_code)
#define GDI_TRY                                \
   {                                           \
      int jmpret;                              \
      int backup_gdi_mutex_cnt = gdi_mutex.cnt;\
      GDI_ASSERT(!gdi_jmpbuf_is_used);         \
      gdi_jmpbuf_is_used = TRUE;               \
      jmpret = setjmp (gdi_jmpbuf);            \
      if(jmpret == 0 )                         \
      {

#define GDI_CATCH_BEGIN                     \
      }                                     \
      else                                  \
      {                                     \
         GDI_UNLOCK_N(backup_gdi_mutex_cnt);\
         {

#define GDI_CATCH_END            \
         }                       \
      }                          \
      gdi_jmpbuf_is_used = FALSE;\
   }

#define GDI_CATCH(N) if(jmpret == N)

/* check rect within clip, if exceed limit, will return */
#define GDI_CLIP_TWO_RECT(X1, Y1, X2, Y2,CX1,CY1,CX2,CY2,NULL_ACTION)\
{                                                                    \
   if(X1 > X2) { NULL_ACTION; }                                      \
   else if(Y1 > Y2)  { NULL_ACTION; }                                \
   else if(X2 < CX1) { NULL_ACTION; }                                \
   else if(Y2 < CY1) { NULL_ACTION; }                                \
   else if(X1 > CX2) { NULL_ACTION; }                                \
   else if(Y1 > CY2) { NULL_ACTION; }                                \
   else                                                              \
   {                                                                 \
      if(X1 < CX1) { X1 = CX1; }                                     \
      if(Y1 < CY1) { Y1 = CY1; }                                     \
      if(X2 > CX2) { X2 = CX2; }                                     \
      if(Y2 > CY2) { Y2 = CY2; }                                     \
   }                                                                 \
}

#define GDI_CLIP_RECT_TEST(X1, Y1, X2, Y2,NULL_ACTION)    \
{                                                         \
   if(X1 > X2) { NULL_ACTION; }                           \
   else if(Y1 > Y2)  { NULL_ACTION; }                     \
   else if(X2 < GDI_LAYER.clipx1) { NULL_ACTION; }        \
   else if(Y2 < GDI_LAYER.clipy1) { NULL_ACTION; }        \
   else if(X1 > GDI_LAYER.clipx2) { NULL_ACTION; }        \
   else if(Y1 > GDI_LAYER.clipy2) { NULL_ACTION; }        \
   else                                                   \
   {                                                      \
      if(X1 < GDI_LAYER.clipx1) { X1 = GDI_LAYER.clipx1; }\
      if(Y1 < GDI_LAYER.clipy1) { Y1 = GDI_LAYER.clipy1; }\
      if(X2 > GDI_LAYER.clipx2) { X2 = GDI_LAYER.clipx2; }\
      if(Y2 > GDI_LAYER.clipy2) { Y2 = GDI_LAYER.clipy2; }\
   }                                                      \
}

/****************************************************************************
* function
*****************************************************************************/
extern void gdi_memset16(U8 *address, U16 pixel, int size);
extern void gdi_memset24(U8* address,U32 pixel,int size);
extern void gdi_memset32(U8* address,U32 pixel,int size);

extern S32 gdi_sizeof_pixels(gdi_color_format cf, S32 width, S32 height);
extern S32 gdi_bits_per_pixel(gdi_color_format cf);
extern gdi_color_format gdi_get_color_format(S32 bits);

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// GDI Software resizer
///////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct
{
    U8 *dest;
    S32 bitsperpixels;
    S32 src_height_range;   /* Source */
    S32 dest_height_range;  /* Destination */
    S32 offset_dx;
    S32 offset_dy;

    S32 want_dx1, want_dx2; /* wanted rendering area */
    S32 want_dy1, want_dy2;

    S32 want_sx;    /* current wanted point (want_x,want_y) */
    S32 want_sy;

    S16 *want_sx_table;
    S16 *want_sx_table_end;
    S16 *next_want_sx;
    S32 next_want_dy;

    S32 dir_x;
    S32 dir_y;

    /* for non resize used */
    S32 want_start_sx, want_start_sy;
    S32 want_end_sx, want_end_sy;
    S32 dest_pitch_jump;
} gdi_resizer_struct;

typedef void (*gdi_resizer_put_func) (gdi_color c, BOOL want_draw);
extern gdi_resizer_put_func gdi_resizer_put;
extern gdi_resizer_struct GDI_RESIZER;

#define IS_GDI_RESIZER_WANT_DRAW(SX,SY)   (SX == GDI_RESIZER.want_sx && SY == GDI_RESIZER.want_sy)

#define GDI_NON_RESIZER_PUT_X(COLOR,WANT_DRAW)                    \
   do                                                             \
   {                                                              \
      if(WANT_DRAW)                                               \
         GDI_RESIZER_PUT_PIXEL(COLOR);                            \
      GDI_RESIZER_INCREASE_DEST;                                  \
      if(GDI_RESIZER.want_sx == GDI_RESIZER.want_end_sx)          \
      {                                                           \
         if(GDI_RESIZER.want_sy == GDI_RESIZER.want_end_sy)       \
         {                                                        \
            GDI_RESIZER.want_sx = 0x0fffffff;/* very large number */\
         }                                                        \
         else/* move to next line begin */                         \
         {                                                        \
            GDI_RESIZER.want_sx = GDI_RESIZER.want_start_sx;      \
            GDI_RESIZER.want_sy += GDI_RESIZER.dir_y;             \
            GDI_RESIZER.dest += GDI_RESIZER.dest_pitch_jump;      \
         }                                                        \
      }                                                           \
      else                                                        \
      {                                                           \
         GDI_RESIZER.want_sx += GDI_RESIZER.dir_x;                \
      }                                                           \
   }while(0)

extern S32 gdi_resizer_init(
                S32 src_width,
                S32 src_height,
                S32 src_clipx1,
                S32 src_clipy1,
                S32 src_clipx2,
                S32 src_clipy2,
                S32 dest_x1,
                S32 dest_y1,
                S32 dest_x2,
                S32 dest_y2);
extern void gdi_resizer_deinit(void);
extern void gdi_resizer_set_want_sy(S32 want_sy);


////////////////////////////////////////////////////////////////////////////////
// Image buffer operator API
////////////////////////////////////////////////////////////////////////////////

/* GDI_DIV_255(x) == int(x / 255 + 0.5) */
#define GDI_DIV_255(_x)                 ((((_x) + 128) * 257) >> 16)

/* GDI_DIV_15(x) == int(x / 15 + 0.5) */
#define GDI_DIV_15(_x)                  ((((_x) + 8) * 4369) >> 16)

/*
 * Divide by 31. The result will equal to (int)(x / 31 + 0.5)
 * Only support 0 <= x < 128 * 256
 */
#define GDI_DIV_31(_x) ((2114 * ((_x) + 16)) >> 16)

/*
 * Divide by 63. the result will equal to (int)(x / 63 + 0.5)
 * Only support 0 <= x < 256 * 256
 */
#define GDI_DIV_63(_x) ((4161 * ((_x) + 32)) >> 18)


/* GDI_BITS_5_to_8(x) ~= int(x * 255 / 31 + 0.5) */
#define GDI_BITS_5_to_8(_x)             (((_x) << 3) | ((_x) >> 2))
#define GDI_BITS_8_to_5(_x)             ((_x) >> 3)


/* GDI_BITS_6_to_8(x) ~= int(x * 255 / 63 + 0.5) */
#define GDI_BITS_6_to_8(_x)             (((_x) << 2) | ((_x) >> 4))
#define GDI_BITS_8_to_6(_x)             ((_x) >> 2)

#define GDI_BITS_5_to_6(_x)             (((_x) << 1) | ((_x) >> 4))
#define GDI_BITS_6_to_5(_x)             ((_x) >> 1)

#define GDI_MEM_GET_8(_ptr)             (*((U8*)(_ptr)))
#define GDI_MEM_PUT_8(_ptr, _v)         (*((U8*)(_ptr)) = _v)

#define GDI_MEM_GET_16(_ptr)            (*((U16*)(_ptr)))
#define GDI_MEM_PUT_16(_ptr, _v)        (*((U16*)(_ptr)) = _v)

#define GDI_MEM_GET_24(_ptr)            ((((U8 *)(_ptr))[0]) | (((U8 *)(_ptr))[1] << 8) | (((U8*)(_ptr))[2] << 16))
#define GDI_MEM_PUT_24(_ptr, _v) \
    do \
    { \
        U8 *ptr8 = (U8*)(_ptr); \
        ptr8[0] = _v; \
        ptr8[1] = _v >> 8; \
        ptr8[2] = _v >> 16; \
    } while (0)

#define GDI_MEM_GET_PTR_24(_buf_base, _width, _x, _y) \
    ((kal_uint8*)(_buf_base) + ((_width) * (_y) + (_x)) * 3)

    
#define GDI_MEM_GET_32(_ptr)            (*((U32*)(_ptr)))
#define GDI_MEM_PUT_32(_ptr, _v)        (*((U32*)(_ptr)) = _v)


/*
 * Color format
 */
typedef enum
{
    GDI_IMG_BUF_COLOR_FORMAT_UNKNOWN    = 0x00,
    GDI_IMG_BUF_COLOR_FORMAT_RGB565     = 0x02,
    GDI_IMG_BUF_COLOR_FORMAT_RGB888     = 0x03,
    GDI_IMG_BUF_COLOR_FORMAT_ARGB8888   = 0x04,
    GDI_IMG_BUF_COLOR_FORMAT_PARGB8888  = 0x14,
    GDI_IMG_BUF_COLOR_FORMAT_PARGB6666  = 0x13
} gdi_img_buf_color_format_enum;

#define GDI_IMG_BUF_COLOR_FORMAT_PIXEL_BYTES(_format) (((S32)(_format)) & 0x0f)


/*
 * RGB565 color format
 */
#define GDI_RGB565(_r, _g, _b)          (((_r) << 11) | ((_g) << 5) | (_b))
#define GDI_R_OF_RGB565(_c)             (((_c) << 16) >> 27)
#define GDI_G_OF_RGB565(_c)             (((_c) << 21) >> 26)
#define GDI_B_OF_RGB565(_c)             (((_c) << 27) >> 27)

#define GDI_RGB565_FROM_RGB888(_c) \
    (GDI_RGB565( \
        GDI_BITS_8_to_5(GDI_R_OF_RGB888(_c)), \
        GDI_BITS_8_to_6(GDI_G_OF_RGB888(_c)), \
        GDI_BITS_8_to_5(GDI_B_OF_RGB888(_c))))

#define GDI_RGB565_FROM_ARGB8888(_c) \
    (GDI_RGB565( \
        GDI_BITS_8_to_5(GDI_R_OF_ARGB8888(_c)), \
        GDI_BITS_8_to_6(GDI_G_OF_ARGB8888(_c)), \
        GDI_BITS_8_to_5(GDI_B_OF_ARGB8888(_c))))

/*
 * RGB888 color format
 */
#define GDI_RGB888(_r, _g, _b)          (((_r) << 16) | ((_g) << 8) | (_b))
#define GDI_R_OF_RGB888(_c)             (((_c) <<  8) >> 24)
#define GDI_G_OF_RGB888(_c)             (((_c) << 16) >> 24)
#define GDI_B_OF_RGB888(_c)             (((_c) << 24) >> 24)

#define GDI_RGB888_FROM_RGB565(_c) \
    (GDI_RGB888( \
        GDI_BITS_5_to_8(GDI_R_OF_RGB565(_c)), \
        GDI_BITS_6_to_8(GDI_G_OF_RGB565(_c)), \
        GDI_BITS_5_to_8(GDI_B_OF_RGB565(_c))))

#define GDI_RGB888_FROM_ARGB8888(_c)      ((_c) & 0x00ffffff)


/*
 * ARGB8888 color format
 */
#define GDI_ARGB8888(_a, _r, _g, _b)    (((_a) << 24) | ((_r) << 16) | ((_g) << 8) | (_b))
#define GDI_A_OF_ARGB8888(_c)           ((_c) >> 24)
#define GDI_R_OF_ARGB8888(_c)           (((_c) <<  8) >> 24)
#define GDI_G_OF_ARGB8888(_c)           (((_c) << 16) >> 24)
#define GDI_B_OF_ARGB8888(_c)           (((_c) << 24) >> 24)

#define GDI_ARGB8888_FROM_RGB565(_c) \
    (GDI_ARGB8888( \
        (U32)0xff, \
        GDI_BITS_5_to_8(GDI_R_OF_RGB565(_c)), \
        GDI_BITS_6_to_8(GDI_G_OF_RGB565(_c)), \
        GDI_BITS_5_to_8(GDI_B_OF_RGB565(_c))))
        
#define GDI_ARGB8888_FROM_RGB888(_c)      (((U32)0xff << 24) | (_c))


/*
 * PARGB8888 color format
 */
#define GDI_PARGB8888(_a, _pr, _pg, _pb) (((_a) << 24) | ((_pr) << 16) | ((_pg) << 8) | (_pb))
#define GDI_A_OF_PARGB8888(_c)          ((_c) >> 24)
#define GDI_PR_OF_PARGB8888(_c)         (((_c) <<  8) >> 24)
#define GDI_PG_OF_PARGB8888(_c)         (((_c) << 16) >> 24)
#define GDI_PB_OF_PARGB8888(_c)         (((_c) << 24) >> 24)

#define GDI_PARGB8888_FROM_RGB565(_c) \
    (GDI_PARGB8888( \
        (U32)0xff, \
        GDI_BITS_5_to_8(GDI_R_OF_RGB565(_c)), \
        GDI_BITS_6_to_8(GDI_G_OF_RGB565(_c)), \
        GDI_BITS_5_to_8(GDI_B_OF_RGB565(_c))))

#define GDI_PARGB8888_FROM_RGB888(_c)     (((U32)0xff << 24) | (_c))

#define GDI_PARGB8888_FROM_ARGB8888(_c) \
    (GDI_PARGB8888( \
        GDI_A_OF_ARGB8888(_c), \
        GDI_DIV_255(GDI_A_OF_ARGB8888(_c) * GDI_R_OF_ARGB8888(_c)), \
        GDI_DIV_255(GDI_A_OF_ARGB8888(_c) * GDI_G_OF_ARGB8888(_c)), \
        GDI_DIV_255(GDI_A_OF_ARGB8888(_c) * GDI_B_OF_ARGB8888(_c))))

#define GDI_PARGB8888_FROM_PARGB6666(_c) \
    (GDI_PARGB8888( \
        GDI_BITS_6_to_8(GDI_A_OF_PARGB6666(_c)), \
        GDI_BITS_6_to_8(GDI_PR_OF_PARGB6666(_c)), \
        GDI_BITS_6_to_8(GDI_PG_OF_PARGB6666(_c)), \
        GDI_BITS_6_to_8(GDI_PB_OF_PARGB6666(_c)) ))

/*
 * PARGB6666 color format
 */
#define GDI_PARGB6666(_a, _pr, _pg, _pb) (((_a) << 18) | ((_pr) << 12) | ((_pg) << 6) | (_pb))
#define GDI_A_OF_PARGB6666(_c)          ((_c) >> 18)
#define GDI_PR_OF_PARGB6666(_c)         (((_c) << 14) >> 26)
#define GDI_PG_OF_PARGB6666(_c)         (((_c) << 20) >> 26)
#define GDI_PB_OF_PARGB6666(_c)         (((_c) << 26) >> 26)

#define GDI_PARGB6666_FROM_RGB565(_c) \
    (GDI_PARGB6666( \
        (U32)0x3f, \
        GDI_BITS_5_to_6(GDI_R_OF_RGB565(_c)), \
        GDI_G_OF_RGB565(_c), \
        GDI_BITS_5_to_6(GDI_B_OF_RGB565(_c))))

#define GDI_PARGB6666_FROM_RGB888(_c) \
    (GDI_PARGB6666( \
        (U32)0x3f, \
        GDI_BITS_8_to_6(GDI_R_OF_RGB888(_c)), \
        GDI_BITS_8_to_6(GDI_G_OF_RGB888(_c)), \
        GDI_BITS_8_to_6(GDI_B_OF_RGB888(_c))))

#define GDI_PARGB6666_FROM_ARGB8888(_c) \
    (GDI_PARGB6666( \
        GDI_BITS_8_to_6(GDI_A_OF_PARGB8888(_c)), \
        GDI_BITS_8_to_6(GDI_DIV_255(GDI_A_OF_ARGB8888(_c) * GDI_R_OF_ARGB8888(_c))), \
        GDI_BITS_8_to_6(GDI_DIV_255(GDI_A_OF_ARGB8888(_c) * GDI_G_OF_ARGB8888(_c))), \
        GDI_BITS_8_to_6(GDI_DIV_255(GDI_A_OF_ARGB8888(_c) * GDI_B_OF_ARGB8888(_c))) ))

#define GDI_PARGB6666_FROM_PARGB8888(_c) \
    (GDI_PARGB6666( \
        GDI_BITS_8_to_6(GDI_A_OF_PARGB8888(_c)), \
        GDI_BITS_8_to_6(GDI_PR_OF_PARGB8888(_c)), \
        GDI_BITS_8_to_6(GDI_PG_OF_PARGB8888(_c)), \
        GDI_BITS_8_to_6(GDI_PB_OF_PARGB8888(_c)) ))

#define GDI_PARGB6666_FROM_ARGB8888_EXT(_a, _r, _g, _b) \
    (GDI_PARGB6666( \
        GDI_BITS_8_to_6(_a), \
        GDI_BITS_8_to_6(GDI_DIV_255((_a) * (_r))), \
        GDI_BITS_8_to_6(GDI_DIV_255((_a) * (_g))), \
        GDI_BITS_8_to_6(GDI_DIV_255((_a) * (_b))) ))

#define GDI_RGB565_FROM_PARGB6666(_c) \
    (GDI_RGB565( \
        GDI_BITS_6_to_5(GDI_PR_OF_PARGB6666(_c)), \
        GDI_PG_OF_PARGB6666(_c), \
        GDI_BITS_6_to_5(GDI_PB_OF_PARGB6666(_c))))


/*
 * GDI image buffer structure
 */
typedef struct 
{
    U8 *ptr;    
    gdi_img_buf_color_format_enum color_format;
    S32 pitch_bytes;
} gdi_img_buf_struct;

extern gdi_img_buf_color_format_enum gdi_img_buf_trans_color_format(U32 gdi_color_format);

extern void gdi_img_buf_fill_color(
    gdi_img_buf_struct *dst_buf, 
    gdi_color dst_color,
    S32 width,
    S32 height);

extern void gdi_img_buf_blending_color(
    gdi_img_buf_struct *dst_buf, 
    gdi_color pargb8888_color,
    S32 width,
    S32 height);

extern void gdi_img_buf_flatten(
    gdi_img_buf_struct *dst_buf, 
    gdi_color dst_color_key,
    const gdi_img_buf_struct *src_buf,
    S32 width,
    S32 height);

extern void gdi_img_buf_copy(
    gdi_img_buf_struct *dst_buf, 
    const gdi_img_buf_struct *src_buf,
    S32 width,
    S32 height);

extern void gdi_img_buf_blending(
    gdi_img_buf_struct *dst_buf, 
    const gdi_img_buf_struct *src_buf,
    S32 width,
    S32 height);

extern void gdi_img_buf_blending_scale(
    gdi_img_buf_struct *dst_buf, 
    S32 dst_width,
    S32 dst_height,
    const gdi_img_buf_struct *src_buf,
    S32 src_width,
    S32 src_height,
    S32 offset_x,
    S32 offset_y);

extern GDI_RESULT gdi_img_buf_prepare_img_buf_struct(
                    gdi_img_buf_struct *output_img_buf_struct,
                    gdi_rect_struct *dest_rect,
                    U8 *buf_ptr,
                    S32 buf_width,
                    S32 buf_bpp,
                    U32 buf_cf,
                    S32 clip_x1,
                    S32 clip_y1,
                    S32 clip_x2,
                    S32 clip_y2);

extern gdi_color gdi_cf_get_color(
    gdi_color_format cf,
    kal_uint32 a,
    kal_uint32 r,
    kal_uint32 g,
    kal_uint32 b);

extern void gdi_cf_separate_color(
    gdi_color_format cf,
    gdi_color color,
    kal_uint32 *a,
    kal_uint32 *r,
    kal_uint32 *g,
    kal_uint32 *b);

#endif /* _GDI_PRIMITIVE_H_ */ 


