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
 *  vrt_datatype.h
 *
 * Project:
 * --------
 *  Venus Rendering Task
 *
 * Description:
 * ------------
 *  VRT basic definition
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 
#ifndef __VRT_DATATYPE_H__
#define __VRT_DATATYPE_H__


/* dsiable some VC compile warning */
#ifdef WIN32
/* warning C4786: identifier was truncated to '255' characters in the debug information */
#pragma warning(disable : 4786)
/* warning C4291: no matching operator delete found; memory will not be freed if initialization throws an exception */
#pragma warning(disable : 4291)
/* warning C4996: '_vsnprintf': This function or variable may be unsafe. Consider using _vsnprintf_s instead. */
#pragma warning(disable : 4996)
/* warning C4819: The file contains a character that cannot be represented in the current code page (950).  */
#pragma warning(disable : 4819)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vrt_platform.h"

#if !defined(V3D_TEST)
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_debug.h"
#endif /* !defined(V3D_TEST) */

/***************************************************************************** 
 * Define
 *****************************************************************************/
/* The ARM C compiler can support returning 4 32-bit variables in registers r0-r3. */
#ifdef __MTK_TARGET__
#define VRT_RET_VALUE_IN_REGS           __value_in_regs
#else
#define VRT_RET_VALUE_IN_REGS
#endif

#ifdef __MTK_TARGET__
    #define VRT_ALIGN(x)                __align(x)
#else
    #define VRT_ALIGN(x) 
#endif

/* Align a number to 4 */
#define VRT_ALIGN_TO_4(_n)              (((_n) + 3) / 4 * 4)

/* Limitation of types */
#define VRT_U32_MAX                     0xffffffff
#define VRT_U32_MIN                     0x00000000
#define VRT_S32_MAX                     0x7fffffff
#define VRT_S32_MIN                     0x80000000
#define VRT_S16_MAX                     0x7fff
#define VRT_S16_MIN                     0x8000

/* NULL */
#ifndef NULL
#define NULL                            0
#endif 

/* PI */
#define VRT_PI                          3.1415926f

/* Get the bigger value in a and b */
#define VRT_MAX(a, b)                   ((a) > (b) ? (a) : (b))
/* Get the smaller value in a and b */
#define VRT_MIN(a, b)                   ((a) < (b) ? (a) : (b))
/* Get the biggest value in a, b and c */
#define VRT_MAX3(a, b, c)               (VRT_MAX(VRT_MAX(a, b), c))
/* Get the smallest value in a, b and c */
#define VRT_MIN3(a, b, c)               (VRT_MIN(VRT_MIN(a, b), c))
/* Get the clamp value of a between b and c */
#define VRT_CLAMP(a, b, c)              (VRT_MIN(VRT_MAX(a, b), c))
/* Get the absolute value of a */
#define VRT_ABS(a)                      ((a) < 0 ? -(a) : (a))
/* Swap two 32-bit value*/
#define VRT_SWAP(a, b)                  (*((long*)&a) ^=  *((long*)&b) ^= *((long*)&a) ^= *((long*)&b))

/* Avoid unused function parameter warning, ex: VRT_UNUSED(parm); */
#define VRT_UNUSED(x)                   ((void)(x))

/*
 * Flag operator macros
 */
#define VRT_FLAG_SET(x, flags)          ((x) |= (flags))
#define VRT_FLAG_CLEAR(x, flags)        ((x) &= ~(flags))
#define VRT_FLAG_HAS(x, flags)          (((x) & (flags)) != 0)
#define VRT_FLAG_HAS_ALL(x, flags)      (((x) & (flags)) == (flags))


#ifdef V3D_TEST
#include <stdio.h>
#include <assert.h>    
#define ASSERT      assert
#define kal_printf  printf
#endif
/* 
 * Debug macros 
 */
/* Assert if expr is true */
#define VRT_ASSERT(expr)                ASSERT(expr)
#define VRT_EXT_ASSERT(expr, e1, e2, e3) EXT_ASSERT(expr, e1, e2, e3)

/* Developping time assert. In debug mode, assert if expr is true */
#if !defined(__MTK_TARGET__)
#define VRT_DEV_ASSERT(expr)            ASSERT(expr)
#define VRT_DEV_EXT_ASSERT(expr, e1, e2, e3) EXT_ASSERT(expr, e1, e2, e3)
#else
#define VRT_DEV_ASSERT(expr) 
#define VRT_DEV_EXT_ASSERT(expr, e1, e2, e3)
#endif

#if defined(__MTK_TARGET__) || !defined(VRT_TRACE_ENABLE)
    #define VRT_TRACE(x)    
#else
    #define VRT_TRACE(x)                kal_printf x
#endif

#if defined(__MTK_TARGET__)
    #define VRT_MUST_TRACE(x)    
#else
    #define VRT_MUST_TRACE(x)           kal_printf x
#endif

/* Callback structure macros */
#define VRT_CALLBACK_STRUCT_SIZE(_type, _user_data_size) \
    (VRT_ALIGN_TO_4(sizeof(_type)) + VRT_ALIGN_TO_4(_user_data_size))
#define VRT_CALLBACK_STRUCT_PTR_SIZE(_ptr) \
    ((_ptr) == NULL ? \
        0 : \
        VRT_ALIGN_TO_4(sizeof(*_ptr) + VRT_ALIGN_TO_4((_ptr)->user_data_size)))
#define VRT_CALLBACK_STRUCT_DATA(_ptr) \
    ((_ptr)->user_data_size == 0 ? \
        NULL : \
        (void *)((vrt_u8 *)(_ptr) + VRT_ALIGN_TO_4(sizeof(*_ptr))))

/* Redian convert macros */
#define VRT_DEG_TO_RAD(x)               ((vrt_float)((vrt_float)(x)) * VRT_PI / 180.0f)
#define VRT_RAD_TO_DEG(x)               ((vrt_float)((vrt_float)(x)) * 180.0f / VRT_PI)

/* Float, Fixed conversion */
#define VRT_X_TO_F(x)                   ((float)x / 65536.0f)
#define VRT_F_TO_X(x)                   (vrt_s32)((x) * 65536.0f)

/* Count bits */
#define VRT_BIT_COUNT(n)        ((n <= (1<<1) ? 1: \
                                  n <= (1<<2) ? 2: \
                                  n <= (1<<3) ? 3: \
                                  n <= (1<<4) ? 4: \
                                  n <= (1<<5) ? 5: \
                                  n <= (1<<6) ? 6: \
                                  n <= (1<<7) ? 7: \
                                  n <= (1<<8) ? 8: \
                                  n <= (1<<16) ? 16 : 31) + 1)

/* Caculate the difference of two absolute times */
#define VRT_MSEC_DIFF(lhs, rhs)         ((lhs) - (rhs))

// VRT_RES_ID_NULL represents a null resource of vrt_res_id.
#define VRT_RES_ID_NULL                 (0)

/* General color type methods */
#define VRT_COLOR_MAKE(a, r, g, b)      ((vrt_color_type)((vrt_u32)(a) << 24 | (vrt_u32)(r) << 16 | (vrt_u32)(g) << 8 | (vrt_u32)(b)))
#define VRT_COLOR_GET_A(c)              ((c) >> 24)
#define VRT_COLOR_GET_R(c)              ((c) << 8 >> 24)
#define VRT_COLOR_GET_G(c)              ((c) << 16 >> 24)
#define VRT_COLOR_GET_B(c)              ((c) << 24 >> 24)

/* default colors */
#define VRT_COLOR_BLACK                 VRT_COLOR_MAKE(255, 0, 0, 0)
#define VRT_COLOR_WHITE                 VRT_COLOR_MAKE(255, 255, 255, 255)
#define VRT_COLOR_RED                   VRT_COLOR_MAKE(255, 255, 0, 0)
#define VRT_COLOR_GREEN                 VRT_COLOR_MAKE(255, 0, 255, 0)
#define VRT_COLOR_BLUE                  VRT_COLOR_MAKE(255, 0, 0, 255)
#define VRT_COLOR_AQUA                  VRT_COLOR_MAKE(255, 0, 255, 255)
#define VRT_COLOR_FUCHSIA               VRT_COLOR_MAKE(255, 255, 0, 255)
#define VRT_COLOR_YELLOW                VRT_COLOR_MAKE(255, 255, 255, 0)
#define VRT_COLOR_GREY                  VRT_COLOR_MAKE(255, 128, 128, 128)
#define VRT_COLOR_TEAL                  VRT_COLOR_MAKE(255, 0, 128, 128)
#define VRT_COLOR_PURPLE                VRT_COLOR_MAKE(255, 128, 0, 128)
#define VRT_COLOR_OLIVE                 VRT_COLOR_MAKE(255, 128, 128, 0)
#define VRT_COLOR_SILVER                VRT_COLOR_MAKE(255, 192, 192, 192)
#define VRT_COLOR_TRANSPARENT           VRT_COLOR_MAKE(0, 0, 0, 255)
#define VRT_COLOR_NULL                  VRT_COLOR_MAKE(0, 0, 0, 0)

/* VRT Color format */
#define VRT_COLOR_FORMAT_HAS_ALPHA(cf)   (cf <= VRT_COLOR_TYPE_ALPHA)

/* VRT frame default values */

#define VRT_FRAME_DEFAULT_POS           g_vrt_point_zero
#define VRT_FRAME_DEFAULT_POS_Z         0.0f
#define VRT_FRAME_DEFAULT_BOUNDS        g_vrt_rect_zero
#define VRT_FRAME_DEFAULT_ANCHOR        g_vrt_fpoint_zero
#define VRT_FRAME_DEFAULT_BG_COLOR      VRT_COLOR_TRANSPARENT
#define VRT_FRAME_DEFAULT_OPACITY       1.0f
#define VRT_FRAME_DEFAULT_TRANSFORM     g_vrt_transfrom_identity
#define VRT_FRAME_DEFAULT_BORDER_COLOR  VRT_COLOR_WHITE
#define VRT_FRAME_DEFAULT_BORDER_WIDTH  0

/* Make Four CC */
#define VRT_FCC(ch0, ch1, ch2, ch3) \
    ((unsigned int)(unsigned char)(ch0) | ((unsigned int)(unsigned char)(ch1) << 8) | \
    ((unsigned int)(unsigned char)(ch2) << 16) | ((unsigned int)(unsigned char)(ch3) << 24 ))

/*
 * Flag for vrt_canvas_entry
 */

// Tell VRT entry in power off mode
#define VRT_CANVAS_ENTRY_FLAG_POWER_OFF                 (1 << 0)
// Forbid VRT to modify the original main base layer buffer
#define VRT_CANVAS_ENTRY_FLAG_FORBID_MAIN_BASE_LAYER    (1 << 1)
//
#define VRT_CANVAS_ENTRY_FLAG_FORBID_DOUBLE_BUFFER      (1 << 2)


/*
 * Flags for vrt_canvas_entry
 */

// 
#define VRT_CANVAS_LEAVE_FLAG_FORBID_FLATTEN            (1 << 2)
// This is a hint. It tells VRT that next screen using VRT, 
//  and VRT will try to keep some information to enhance performance 
//  between VRT leaving and entering.
#define VRT_CANVAS_LEAVE_FLAG_NEXT_HAS_VRT              (1 << 3)


/*
 * Flags for Video Frame
 */

#define VRT_VIDEO_FRAME_HINT_NONE                                   0
#define VRT_VIDEO_FRAME_HINT_PREVENT_COLOR_FORMAT_CHANGE_IN_SCREEN  (1 << 0)
#define VRT_VIDEO_FRAME_HINT_APP_CTRL                               (1 << 1)
#define VRT_VIDEO_FRAME_HINT_LIVE_ROTATION							(1 << 2)

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/* General boolean type */
typedef unsigned char   vrt_bool;
#define VRT_FALSE       ((vrt_bool)0)
#define VRT_TRUE        ((vrt_bool)1)

/* General float-point type */
typedef float           vrt_float;
/* 8 bits signed integer */
typedef signed char     vrt_s8;
/* 8 bits unsigned integer */
typedef unsigned char   vrt_u8;
/* 16 bits signed integer */
typedef signed short    vrt_s16;
/* 16 bits unsigned integer */
typedef unsigned short  vrt_u16;
/* 32 bits signed integer */
typedef signed int      vrt_s32;
/* 32 bits unsigned integer */
typedef unsigned int    vrt_u32;

typedef unsigned int    vrt_size;
typedef signed int      vrt_res_id;

#if !defined(GEN_FOR_PC) && !defined(__MTK_TARGET__)
/* 64 bits unsigned integer */
typedef unsigned __int64      vrt_u64;
/* 64 bits signed integer */
typedef __int64               vrt_s64;
#else
/* 64 bits unsigned integer */
typedef unsigned long long   vrt_u64;
/* 64 bits signed integer */
typedef signed long long     vrt_s64;
#endif

/* General character type, charactor */
typedef char            vrt_char;
/* General character type, wild-charactor */
typedef unsigned short  vrt_wchar;

/* General bit flag type */
typedef vrt_u32         vrt_flag_type;

/* General millisecond type */
typedef vrt_s32         vrt_msec_type;

/* General color type */
typedef vrt_u32         vrt_color_type;

#ifdef __MTK_TARGET__
typedef vrt_bool vrt_bit;
#else
typedef vrt_u32 vrt_bit;
#endif

/* Color type ID */
typedef enum
{
    VRT_COLOR_TYPE_UNKNOWN = 0,

    /* alpha format */
    VRT_COLOR_TYPE_ARGB8888,
    VRT_COLOR_TYPE_PARGB8888,
    VRT_COLOR_TYPE_PARGB6666,
    VRT_COLOR_TYPE_A8,
    VRT_COLOR_TYPE_ALPHA = VRT_COLOR_TYPE_A8,

    /* non alpha format */
    VRT_COLOR_TYPE_RGB565,
    VRT_COLOR_TYPE_RGB888,
    VRT_COLOR_TYPE_UYVY422,
    VRT_COLOR_TYPE_D16,
    VRT_COLOR_TYPE_S8,
    
    /* not real color format */
    VRT_COLOR_TYPE_RGB565_FULLY_OPAQUE,
    VRT_COLOR_TYPE_RGB888_FULLY_OPAQUE,

    VRT_COLOR_TYPE_END_OF_ENUM
} vrt_color_type_enum;


/* Point type */
typedef struct
{
    vrt_s32 x;
    vrt_s32 y;
} vrt_point_struct;

/* Size type */
typedef struct
{
    vrt_s32 width;
    vrt_s32 height;
} vrt_size_struct;

/* Rectangle type */
typedef struct
{
    vrt_point_struct origin;
    vrt_size_struct  size;
} vrt_rect_struct;

/* Point type with short integer */
typedef struct
{
    vrt_s16 x;
    vrt_s16 y;
} vrt_spoint_struct;

/* Size type with short integer */
typedef struct
{
    vrt_s16 width;
    vrt_s16 height;
} vrt_ssize_struct;

/* Rectangle type with short integer */
typedef struct
{
    vrt_spoint_struct origin;
    vrt_ssize_struct  size;
} vrt_srect_struct;

/* Point type with floating point */
typedef struct
{
    vrt_float x;
    vrt_float y;
} vrt_fpoint_struct;

/* Size type with floating point */
typedef struct
{
    vrt_float width;
    vrt_float height;
} vrt_fsize_struct;

/* Rectangle type with floating point */
typedef struct
{
    vrt_fpoint_struct origin;
    vrt_fsize_struct  size;
} vrt_frect_struct;

/*
 * Transform
 */
/* 3 * 3 matrix type */
typedef struct
{
    vrt_float m[9];
} vrt_matrix3x3_struct;

/* 3 * 3 matrix type (s32)*/
typedef struct
{
    vrt_s32 m[9];
} vrt_matrix3x3_s32_struct;

/* 4 * 4 matrix type */
typedef struct
{
    vrt_float m[16];
} vrt_matrix4x4_struct;

/* 2D affine transform parameters
 * The process order is scaling -> rotation -> translation */
typedef struct
{
    vrt_float sx, sy;        /* scaling */
    vrt_float rz;            /* rotation */
    vrt_float tx, ty;        /* translation */
} vrt_affine_parameter_struct;

/* transform type */
typedef enum
{
    VRT_TRANSFORM_TYPE_IDENTITY,
    VRT_TRANSFORM_TYPE_AFFINE,
    VRT_TRANSFORM_TYPE_MATRIX3X3,
    VRT_TRANSFORM_TYPE_END_OF_ENUM
} vrt_transform_type_enum;

/* transform structure */
typedef struct
{
    vrt_transform_type_enum type;        /* the transform type */
    union
    {
        /* no data needed for identity type */
        vrt_affine_parameter_struct  affine;     /* data for affine transfrom type */
        vrt_matrix3x3_struct         matrix3x3;  /* data for matrix 3x3 transfrom type */
        vrt_matrix3x3_s32_struct     matrix3x3_s32;
    } data;                             /* the transform data, choose by type */
} vrt_transform_struct;

/* type id */
typedef enum
{
    VRT_TYPE_ID_UNKNOWN = 0,
    VRT_TYPE_ID_BOOL,
    VRT_TYPE_ID_FLOAT,
    VRT_TYPE_ID_S8,
    VRT_TYPE_ID_U8,
    VRT_TYPE_ID_S16,
    VRT_TYPE_ID_U16,
    VRT_TYPE_ID_S32,
    VRT_TYPE_ID_U32,
    VRT_TYPE_ID_S64,
    VRT_TYPE_ID_U64,
    VRT_TYPE_ID_CHAR,
    VRT_TYPE_ID_WCHAR,
    VRT_TYPE_ID_FLAG,
    VRT_TYPE_ID_MSEC,
    VRT_TYPE_ID_COLOR,
    VRT_TYPE_ID_POINT,
    VRT_TYPE_ID_SIZE,
    VRT_TYPE_ID_RECT,
    VRT_TYPE_ID_FPOINT,
    VRT_TYPE_ID_FSIZE,
    VRT_TYPE_ID_FRECT,
    VRT_TYPE_ID_TRANSFORM,
    /* 3D */
    VRT_TYPE_ID_VEC2,
    VRT_TYPE_ID_VEC3,
    VRT_TYPE_ID_VEC4,
    VRT_TYPE_ID_BVEC2,
    VRT_TYPE_ID_BVEC3,
    VRT_TYPE_ID_BVEC4,
    VRT_TYPE_ID_IVEC2,
    VRT_TYPE_ID_IVEC3,
    VRT_TYPE_ID_IVEC4,
    VRT_TYPE_ID_QUAT,
    VRT_TYPE_ID_MAT2,
    VRT_TYPE_ID_MAT3,
    VRT_TYPE_ID_MAT4,
    VRT_TYPE_ID_SAMPLER,
    VRT_TYPE_ID_END_OF_ENUM
} vrt_type_id_enum;

/* font structure, identical to stFontAttribute */
// TODO: use stFontAttribute to make sure two struct is synced
// TODO: move to vrt_adp due to vrt library issue.
typedef struct
{
    vrt_u8 bold;
    vrt_u8 italic;
    vrt_u8 underline;
    vrt_u8 size;
    vrt_u8 color;
    vrt_u8 type;
    vrt_u8 oblique;
    vrt_u8 smallCaps;
    vrt_bool border;
} vrt_font_struct;

/* font engine color type */
typedef struct
{
    vrt_u8 a;    /* alpha */
    vrt_u8 r;    /* red   */
    vrt_u8 g;    /* greed */
    vrt_u8 b;    /* blue  */
} vrt_fe_color;

/* font effect color, identical to stFontColor */
 typedef struct
{
    vrt_fe_color bordered_color;                /* The bordered color */
    vrt_fe_color first_gradient_color;          /* The text color for gradient effect. It works with existing text color to present the gradient effect */
    vrt_fe_color second_gradient_color;         /* The text color for gradient effect. It works with existing text color to present the gradient effect */
    vrt_fe_color shadow_color;                  /* The shadow color */
    vrt_fe_color outerglow_color;               /* The shadow color */
    vrt_fe_color upper_engraved_color;          /* The engraved color  */
    vrt_fe_color lower_engraved_color;          /* The engraved color  */
} vrt_font_effect_color;


/* font effect attributes, identical to stAdvanceFontAttribute */
typedef struct
{
    vrt_s16 shadow_degree;                  /* The degree of change of shadow color. It presents the direction of the light. The degree is limited to 0¢X, 45¢X, 90¢X, 135¢X, 180¢X, 225¢X, 270¢X, 315¢X*/
    vrt_s16 engraved_degree;                /* The degree of change of shadow */
    vrt_u8 shadow_distant;                  /* The distant between the shadow original to the text original */
    vrt_u8 shadow_range;                    /* The shadow range */
    vrt_u8 shadow_transparency;             /* The shadow intensity */
    vrt_u8 border_size;                     /* The size of the border */
    vrt_u8 gradient_direction;              /* The direction of gradient */
    vrt_u8 gradient_transparency;           /* The direction of gradient */
    vrt_u8 outerglow_range;                 /* The outer glow range */
    vrt_u8 outerglow_transparency;          /* The shadow intensity */
    vrt_u8 engraved_transparency;           /* The shadow intensity */
    vrt_u8 border_transparency;             /* The shadow intensity */
} vrt_font_effect_attr;


/* Text direction type enum */
typedef enum 
{
    MG_TEXT_DIR_TYPE_NORMAL = 0,
    MG_TEXT_DIR_TYPE_L2R = MG_TEXT_DIR_TYPE_NORMAL, /* Left to right */
    MG_TEXT_DIR_TYPE_R2L,                           /* Right to left */
    MG_TEXT_DIR_TYPE_END_OF_ENUM
} vrt_text_dir_type_enum; 

/* Animatable properties */
typedef enum
{
    VRT_OBJECT_PROPERTY_ID_UNKNOWN = 0,

    VRT_FRAME_PROPERTY_ID_FPE_USER_0,

    VRT_FRAME_PROPERTY_ID_DIRTY,
    VRT_FRAME_PROPERTY_ID_POS = VRT_FRAME_PROPERTY_ID_DIRTY,
    VRT_FRAME_PROPERTY_ID_POS_X,
    VRT_FRAME_PROPERTY_ID_POS_Y,
    VRT_FRAME_PROPERTY_ID_ANCHOR_POINT,
    VRT_FRAME_PROPERTY_ID_ANCHOR_POINT_X,
    VRT_FRAME_PROPERTY_ID_ANCHOR_POINT_Y,
    VRT_FRAME_PROPERTY_ID_TRANSFORM,
    VRT_FRAME_PROPERTY_ID_TRANSFORM_AFFINE_SX,
    VRT_FRAME_PROPERTY_ID_TRANSFORM_AFFINE_SY,
    VRT_FRAME_PROPERTY_ID_TRANSFORM_AFFINE_RZ,
    VRT_FRAME_PROPERTY_ID_TRANSFORM_AFFINE_TX,
    VRT_FRAME_PROPERTY_ID_TRANSFORM_AFFINE_TY,
    VRT_FRAME_PROPERTY_ID_OPACITY,
    VRT_FRAME_PROPERTY_ID_POS_Z,
    VRT_FRAME_PROPERTY_ID_VIRTUAL_DIRTY,            /* internal use */

    VRT_FRAME_PROPERTY_ID_CONTENT_DIRTY,
    VRT_FRAME_PROPERTY_ID_BOUNDS = VRT_FRAME_PROPERTY_ID_CONTENT_DIRTY,
    VRT_FRAME_PROPERTY_ID_BOUNDS_ORIGIN,
    VRT_FRAME_PROPERTY_ID_BOUNDS_ORIGIN_X,
    VRT_FRAME_PROPERTY_ID_BOUNDS_ORIGIN_Y,
    VRT_FRAME_PROPERTY_ID_BOUNDS_SIZE,
    VRT_FRAME_PROPERTY_ID_BOUNDS_SIZE_WIDTH,
    VRT_FRAME_PROPERTY_ID_BOUNDS_SIZE_HEIGHT,
    VRT_FRAME_PROPERTY_ID_BACKGROUND_COLOR,
    VRT_FRAME_PROPERTY_ID_BORDER_COLOR,
    VRT_FRAME_PROPERTY_ID_BORDER_WIDTH,
    VRT_FRAME_PROPERTY_ID_FILTER_TIMING,
    VRT_FRAME_PROPERTY_ID_VIRTUAL_CONTENT_DIRTY,    /* internal use */

    VRT_FRAME_PROPERTY_ID_END_OF_ENUM,

    /* 3D Object property */
    VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION,
    VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION,
    VRT_TRANSFORMABLE_PROPERTY_ID_SCALE,
    VRT_TRANSFORMABLE_PROPERTY_ID_PIVOT,
    
    VRT_NODE_PROPERTY_ID_OPACITY,

    VRT_LIGHT_PROPERTY_ID_LIGHT_COLOR,
    VRT_LIGHT_PROPERTY_ID_LIGHT_INTENSITY,

    VRT_SHADER_VARIABLE_PROPERTY_ID_FIRST,
    VRT_SHADER_VARIABLE_PROPERTY_ID_FLOAT = VRT_SHADER_VARIABLE_PROPERTY_ID_FIRST,
    VRT_SHADER_VARIABLE_PROPERTY_ID_VEC2,
    VRT_SHADER_VARIABLE_PROPERTY_ID_VEC3,
    VRT_SHADER_VARIABLE_PROPERTY_ID_VEC4,
    VRT_SHADER_VARIABLE_PROPERTY_ID_QUAT,
    VRT_SHADER_VARIABLE_PROPERTY_ID_MAT2,
    VRT_SHADER_VARIABLE_PROPERTY_ID_MAT3,
    VRT_SHADER_VARIABLE_PROPERTY_ID_MAT4,
    VRT_SHADER_VARIABLE_PROPERTY_ID_LAST = VRT_SHADER_VARIABLE_PROPERTY_ID_MAT4,

    /* timeline property */
    VRT_CUSTOM_PROPERTY_ID_BEGIN,
    VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT = VRT_CUSTOM_PROPERTY_ID_BEGIN,
    VRT_CUSTOM_PROPERTY_ID_END_OF_ENUM,

    VRT_OBJECT_PROPERTY_ID_END_OF_ENUM = VRT_CUSTOM_PROPERTY_ID_END_OF_ENUM
} vrt_object_property_id_enum;


/* Frame content placement types */
typedef enum
{
    VRT_FRAME_CONTENT_PLACEMENT_TYPE_TOP_LEFT = 0,
    VRT_FRAME_CONTENT_PLACEMENT_TYPE_TOP,
    VRT_FRAME_CONTENT_PLACEMENT_TYPE_TOP_RIGHT,
    VRT_FRAME_CONTENT_PLACEMENT_TYPE_LEFT,
    VRT_FRAME_CONTENT_PLACEMENT_TYPE_CENTER,
    VRT_FRAME_CONTENT_PLACEMENT_TYPE_RIGHT,
    VRT_FRAME_CONTENT_PLACEMENT_TYPE_BOTTOM_LEFT,
    VRT_FRAME_CONTENT_PLACEMENT_TYPE_BOTTOM,
    VRT_FRAME_CONTENT_PLACEMENT_TYPE_BOTTOM_RIGHT,
    VRT_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE,
    VRT_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT,
    VRT_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL,
    VRT_FRAME_CONTENT_PLACEMENT_TYPE_END_OF_ENUM
} vrt_frame_content_placement_type_enum;

/* VRT dirty types */
typedef enum
{
    VRT_RENDER_DIRTY_TYPE_NONE = 0,
    VRT_RENDER_DIRTY_TYPE_DIRTY,
    VRT_RENDER_DIRTY_TYPE_CONTENT_DIRTY,
    VRT_RENDER_DIRTY_TYPE_END_OF_ENUM
} vrt_render_dirty_type_enum;

/* Frame property effect trigger type */
typedef enum
{
    VRT_FPE_TRIGGER_TYPE_EVERYTIME          = 0,
    VRT_FPE_TRIGGER_TYPE_DIRTY              = 1 << 0,
    VRT_FPE_TRIGGER_TYPE_CONTENT_DIRTY      = 1 << 1,
    VRT_FPE_TRIGGER_TYPE_END_OF_ENUM
} vrt_frame_property_effect_trigger_type_enum;

/* Frame property monitor type */
typedef enum
{
    VRT_FPM_TYPE_NONE = 0,
    VRT_FPM_TYPE_FREEZE,
    VRT_FPM_TYPE_DIRTY,
    VRT_FPM_TYPE_CONTENT_DIRTY,
    VRT_FPM_TYPE_TIME_LINE_DIRTY,
    VRT_FPM_TYPE_TIME_LINE_CONTENT_DIRTY,
    VRT_FPE_TYPE_END_OF_ENUM
} vrt_frame_property_monitor_type_enum;

/* VRT frame content opaque mode */
typedef enum
{
    /* Automatically detect opaque mode by VRT */
    VRT_FRAME_OPAQUE_MODE_AUTO = 0,
    /* The frame content has source color key */
    VRT_FRAME_OPAQUE_MODE_COLOR_KEY,
    /* The frame content has translucent color. Default value.*/
    VRT_FRAME_OPAQUE_MODE_TRANSLUCENT,
    /* The frame content is fully opaque */
    VRT_FRAME_OPAQUE_MODE_FULLY_OPAQUE,    
    VRT_FRAME_OPAQUE_MODE_END_OF_ENUM
} vrt_frame_opaque_mode_enum;


/* Frame Image Format for non 8 byte header */
typedef enum
{
    /* Automatically detect image format by VRT. Default value. */
    VRT_FILE_FORMAT_TYPE_AUTO,
    
    /*BMP Image Format */
    VRT_FILE_FORMAT_TYPE_BMP,

    /* GIF Image Format */
    VRT_FILE_FORMAT_TYPE_GIF,
    
    /* GIF Image Format */
    VRT_FILE_FORMAT_TYPE_PNG,
    
    /* JPG Image Format */
    VRT_FILE_FORMAT_TYPE_JPG,  
	/* ABM Image Format */
    VRT_FILE_FORMAT_TYPE_ABM,

	/*AB2 Image Format */
    VRT_FILE_FORMAT_TYPE_AB2,
    
    VRT_IMAGE_FORMAT_TYPE_END_OF_ENUM
} vrt_raw_data_image_format_enum;


/* VRT render quality */
typedef enum
{
    VRT_RENDER_QUALITY_DEFAULT = 0,
    VRT_RENDER_QUALITY_NORMAL,
    VRT_RENDER_QUALITY_HIGH,
    VRT_RENDER_QUALITY_END_OF_ENUM
} vrt_render_quality_enum;

/* Frame culling types */
typedef enum
{
    VRT_FRAME_CULLING_TYPE_NONE = 0,
    VRT_FRAME_CULLING_TYPE_BACK,
    VRT_FRAME_CULLING_TYPE_FRONT,
    VRT_FRAME_CULLING_TYPE_END_OF_ENUM
} vrt_frame_culling_type_enum;

/* Frame cache hint */
typedef enum
{
    VRT_CACHE_MODE_AUTO = 0,        /* automatically cache by VRT */
    VRT_CACHE_MODE_PREVENT_PARENTS, /* prevent this and parents to cache */
    VRT_CACHE_MODE_PREVENT,         /* prevent to cache */
    VRT_CACHE_MODE_FORCE,           /* force to cache */
    VRT_CACHE_MODE_RESOURCE,        /* force to cache without clear */
    VRT_CACHE_MODE_FREEZE,          /* force to cache with never dirty */
    VRT_CACHE_MODE_TEXTURE,         /* texture frame mode, child frame cache will not be set as useless */
    VRT_CACHE_MODE_END_OF_ENUM
} vrt_cache_mode_enum;

/* Cache buffer lock mode */
typedef enum
{
    VRT_CACHE_LOCK_MODE_NONE        = 0,
    VRT_CACHE_LOCK_MODE_READ        = 1 << 0,
    VRT_CACHE_LOCK_MODE_WRITE       = 1 << 1,
    VRT_CACHE_LOCK_MODE_READWRITE   = (VRT_CACHE_LOCK_MODE_READ | VRT_CACHE_LOCK_MODE_WRITE),
    VRT_CACHE_LOCK_MODE_END_OF_ENUM
} vrt_cache_lock_mode_enum;

/* Frame cache hint */
typedef enum
{
    VRT_FRAME_HINTS_DEFAULT             = 0,        /* default hints */
    VRT_FRAME_HINTS_RARE_TRANSLUCENT    = 1 << 0,   /* frame with rare translucent pixel */
    VRT_FRAME_HINTS_SW_OVERLAY          = 1 << 1,   /* prefer software overlay */
    VRT_FRAME_HINTS_SW_LINEARTRANSFORM  = 1 << 2,   /* prefer software linear transform */
    VRT_FRAME_HINTS_WATCH_FRAME         = 1 << 3,   /* this frame is watched by other frames */
    VRT_FRAME_HINTS_SW_IMG_CONTENT_OVERLAY = 1 << 4,/* 2-pass image content uses software overlay */
    VRT_FRAME_HINTS_DISABLE_COLOR_KEY   = 1 << 5,   /* this frame will not use color key */
    // TODO: phase out VRT_FRAME_HINTS_DISABLE_AUTO_CACHE
    VRT_FRAME_HINTS_DISABLE_AUTO_CACHE  = 1 << 6,   /* this frame and it's parents will not be automatically cached */
    VRT_FRAME_HINTS_PRECACHE_CHILDREN   = 1 << 7,   /* precache invisible child frame if it is suggested */

#ifdef VRT_3D
    VRT_FRAME_HINTS_TEXTURE             = 1 << 8,   /* texture frame */
    VRT_FRAME_HINTS_TEXTURE_HIDDEN      = 1 << 9,   /* texture frame but hidden */
    VRT_FRAME_HINTS_DEPTH_TEST          = 1 << 10,   /* this frame will use depth buffer for depth testing */
    VRT_FRAME_HINTS_STENCIL_TEST        = 1 << 11,   /* this frame will use stencil buffer for stencil testing */
    // TODO: phase out VRT_FRAME_HINTS_PRECACHE
    VRT_FRAME_HINTS_PRECACHE            = 1 << 12,  /* precache invisible frame if it is suggested */
#endif
    VRT_FRAME_HINTS_END_OF_ENUM
} vrt_frame_hints_enum;

/* Image buffer structure */
typedef struct
{
    vrt_u8 *buf_p;                      /* pointer to the begine of image buffer */
    vrt_u32 pitch_bytes;                /* memory address difference of two lines */
    vrt_u32 width;                      /* pixel number of image width */
    vrt_u32 height;                     /* pixel number of image height */
    vrt_color_type_enum color_format;   /* the color format of the image buffer */
} vrt_image_buffer_struct;

typedef struct
{
    vrt_u8 *buf_p;                      /* pointer to the begine of image buffer */
    vrt_s32 image_size;                /* memory address difference of two lines */
    vrt_raw_data_image_format_enum image_format;  /* the color format of the image buffer */
} vrt_file_raw_data_buffer_struct;


typedef vrt_bool (*vrt_image_redraw_funcptr_type)(
  vrt_image_buffer_struct *image_buffer,
  const vrt_point_struct *top_left,
  void *user_data,
  vrt_size user_data_size);  

/* Image source type */
typedef enum
{
    VRT_IMAGE_SOURCE_TYPE_UNKNOWN = 0,
    VRT_IMAGE_SOURCE_TYPE_MEMORY,
    VRT_IMAGE_SOURCE_TYPE_FILE,
    VRT_IMAGE_SOURCE_TYPE_IMAGE_BUFFER,
    VRT_IMAGE_SOURCE_TYPE_IMG_RAW_DATA,
    VRT_IMAGE_SOURCE_TYPE_END_OF_ENUM
} vrt_image_source_type_enum;

/* Image source structure */
typedef struct
{
    union {
        const void          *img_ptr;
        vrt_file_raw_data_buffer_struct raw_data;
        struct
        {
            vrt_u32         hash;
            const vrt_wchar *str;
        } filename;
    } data;
    vrt_image_source_type_enum type;
} vrt_image_source_struct;

/* generic object handle */
typedef void *vrt_object_handle;

typedef vrt_object_handle vrt_animatable_handle;
typedef vrt_animatable_handle vrt_frame_handle;
typedef vrt_object_handle vrt_timeline_handle;
typedef vrt_object_handle vrt_frame_property_handle;

/* custom render type */
typedef enum
{
    VRT_CUSTOM_RENDER_OWNER_DRAW,
    VRT_CUSTOM_RENDER_FRAME_FILTER,
    VRT_CUSTOM_RENDER_END_OF_ENUM,
} vrt_custom_render_type;


/*
 * filter related
 */
/* filter kernel callback function */
typedef vrt_bool (*vrt_image_filter_kernel_callback_funcptr_type)(
    const vrt_image_buffer_struct *image_buffer,
    vrt_u8 *out_buf_p,
    void *param, vrt_float t);

typedef enum
{
    /* output buffer pointer = input buffer pointer */
    VRT_IMAGE_FILTER_BUFFER_MODE_IN_PLACE,
    /* output buffer is allocated by VRT, content is not initialized. */
    VRT_IMAGE_FILTER_BUFFER_MODE_OUT_OF_PLACE,
    /* output buffer is allocated by VRT, content is not initialized. Input buffer is polluted. */
    VRT_IMAGE_FILTER_BUFFER_MODE_OUT_OF_PLACE_AND_POLLUTE_INPUT,
    /* output buffer is allocated by VRT, content is copied from input buffer */
    VRT_IMAGE_FILTER_BUFFER_MODE_OUT_OF_PLACE_AND_COPY,
    /* output buffer is allocated by VRT, content is copied from input buffer. Input buffer is polluted. */
    VRT_IMAGE_FILTER_BUFFER_MODE_OUT_OF_PLACE_AND_COPY_AND_POLLUTE_INPUT,
    VRT_IMAGE_FILTER_BUFFER_MODE_END_OF_ENUM
} vrt_image_filter_buffer_mode;


/* timing function prototype, t is in {0, 1} */
typedef vrt_float (*vrt_timing_funcptr_type)(
    vrt_float t,
    void *data,
    vrt_u32 data_size);

/* 
 * timeline timing function callback structure, 
 *  the user data is appended after the structre.
 */
typedef struct
{
    vrt_timing_funcptr_type callback;   /* the callback function */
    vrt_u32 user_data_size;             /* the user data size in bytes */
} vrt_timeline_timing_callback_struct;


/* timeline interpolation return value */
typedef enum
{
    VRT_TIMELINE_INTERPOLATION_RET_DONE,
    VRT_TIMELINE_INTERPOLATION_RET_USE_DEFAULT,
    VRT_TIMELINE_INTERPOLATION_RET_MONITOR,
    VRT_TIMELINE_INTERPOLATION_RET_MONITOR_FREEZE,
    VRT_TIMELINE_INTERPOLATION_RET_FREEZE,
    VRT_TIMELINE_INTERPOLATION_RET_END_OF_ENUM
} vrt_timeline_interpolation_ret_enum;

/* timeline interpolation callback */
typedef vrt_timeline_interpolation_ret_enum (*vrt_timeline_interpolation_funcptr_type)(
    void *target,
    const void *from_value,
    const void *to_value,
    vrt_type_id_enum type,
    vrt_float t, 
    void *data,
    vrt_u32 data_size);

/* 
 * timeline interpolation function callback structure, 
 *  the user data is appended after the structre.
 */
typedef struct
{
    vrt_timeline_interpolation_funcptr_type callback;   /* the callback function */
    vrt_u32 user_data_size;                             /* the user data size in bytes */
} vrt_timeline_interplation_callback_struct;


/* 
 * keyframe interpolation data structure
 */
typedef struct
{
    vrt_u32 key_count;                             /* the user data size in bytes */
    vrt_type_id_enum type_id;
} vrt_keyframe_sequence_struct;


/* frame visual property callback */
typedef struct
{
    vrt_point_struct        pos;                /* anchor point to parent's origin */
    vrt_float               pos_z;              /* z position */
    vrt_rect_struct         bounds;             /* bounds rect */
    vrt_fpoint_struct       anchor_point;       /* anchor point */
    vrt_float               opacity;            /* frame opacity */   
    vrt_transform_struct    transform;          /* frame transform */
    vrt_color_type          background_color;   /* frame background color */

    vrt_color_type          border_color;       /* border color */
    vrt_s32                 border_width;       /* border width */

    vrt_float               filter_timing;      /* timing value for filters */
    vrt_float               fpe_user_0;         /* FPE user property 0 */
} vrt_frame_visual_property_struct;

typedef vrt_render_dirty_type_enum (*vrt_frame_property_effect_funcptr_type)(
    vrt_frame_visual_property_struct *target_frame,
    const vrt_frame_visual_property_struct *watch_frame,
    void *user_data,
    vrt_u32 user_data_size);

/* 
 * programmable frame property effect callback structure 
 *  the user data is appended after the structre.
 */
typedef struct
{
    vrt_frame_property_effect_funcptr_type callback;
    vrt_frame_property_effect_trigger_type_enum trigger_type;
    vrt_u32 user_data_size;
} vrt_frame_property_effect_callback_struct;


typedef vrt_frame_property_monitor_type_enum (*vrt_frame_property_monitor_funcptr_type)(
    vrt_frame_property_handle target_frame,
    void *user_data,
    vrt_u32 user_data_size);

/* 
 * programmable frame property monitor callback structure 
 *  the user data is appended after the structre.
 */
typedef struct
{
    vrt_frame_property_monitor_funcptr_type callback;
    vrt_u32 user_data_size;
} vrt_frame_property_monitor_callback_struct;

/* Owner draw callback */
typedef void (*vrt_owner_draw_funcptr_type)(
    const vrt_image_buffer_struct *image_buffer,
    const vrt_rect_struct *dst_rect,
    const vrt_rect_struct *src_rect,
    void *user_data);


// end play animation image structure
typedef void (*vrt_play_img_funcptr_type)(
    void *user_data
    );

/*
 * frame play animation image structure
 */
typedef struct
{
    /* if play counts == 0xffffffff, means play the animation image infinite times */
    vrt_u32 play_counts;
    /* when finish play image content, the callback will be called, if  play_counts == 0, the callback will never be called */
    vrt_play_img_funcptr_type end_callback;
    vrt_u8 *user_data;
} vrt_frame_play_img_content_struct;


typedef enum
{
    VRT_RENDER_OWNER_DRAW_DIRTY_TYPE_NONE = 0,
    VRT_RENDER_OWNER_DRAW_DIRTY_TYPE_NORMAL,
    VRT_RENDER_OWNER_DRAW_DIRTY_TYPE_TIME_LINE_DIRTY,
    VRT_RENDER_OWNER_DRAW_DIRTY_TYPE_END_OF_ENUM
} vrt_render_owner_draw_dirty_type_enum;


/*
 * VRT message
 */
typedef void (*vrt_funcptr_type)(void *arg);
typedef vrt_funcptr_type vrt_timer_callback_funcptr_type;
typedef vrt_funcptr_type vrt_rpc_funcptr_type;

typedef enum
{
    VRT_TIMELINE_TIME_WRAP_TYPE_NONE = 0,   /* Bypass Do nothing */
    VRT_TIMELINE_TIME_WRAP_TYPE_CLAMP,      /* Clamp in the [0, 1] range */
    VRT_TIMELINE_TIME_WRAP_TYPE_REPEAT,     /* Fractional part */
    VRT_TIMELINE_TIME_WRAP_TYPE_MIRROR,     /* Mirror */
    VRT_TIMELINE_TIME_WRAP_TYPE_END_OF_ENUM
} vrt_timeline_time_wrap_type_enum;

/* 
 * timeline chain user data for timing function
 */
typedef struct
{
    vrt_timeline_handle time_handle;
    vrt_float scale;
    vrt_float bias;
    vrt_timeline_time_wrap_type_enum wrap_type;
    vrt_timeline_timing_callback_struct timing_func_cb;    
} vrt_timeline_time_user_data_struct;

/* Memory allocator callback function */
typedef void *(*vrt_mem_alloc_funcptr_type)(vrt_u32 size, void *user_data);
typedef void (*vrt_mem_free_funcptr_type)(void *ptr, void *user_data);
typedef vrt_s32 (*vrt_custom_cache_mem_funcptr_type)(vrt_s32 size);

typedef void *vrt_mem_pool_handle;

/* render frame callback */
typedef vrt_bool (*vrt_render_draw_frame_func_ptr_type)(
    void *canvas_cntx,
    vrt_u32 *sleep_ticks,
    vrt_u32 flag);

/* vrt param structure */
typedef struct
{
    vrt_color_type background_color;
    vrt_color_type layer_frame_clear_color;
    vrt_bool disable_freeze;    
} vrt_render_param_struct;

/* animation image status struct */
typedef struct
{
    vrt_u32 count;
    vrt_u32 loop_count;
    vrt_u32 current_index;
    vrt_msec_type delay;
    vrt_msec_type last_draw_time;
    vrt_bool is_gif;
    vrt_u32 user_data;
} vrt_animation_image_status_struct;


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/* Common constants */
extern const vrt_wchar *g_vrt_wstring_empty;      /* "" */

extern const vrt_point_struct g_vrt_point_zero;   /* (0, 0) */
extern const vrt_fpoint_struct g_vrt_fpoint_zero; /* (0.0f, 0.0f) */
extern const vrt_size_struct g_vrt_size_zero;     /* (0, 0) */
extern const vrt_rect_struct g_vrt_rect_zero;     /* (0, 0, 0, 0) */

extern const vrt_rect_struct g_vrt_rect_null;     /* (VRT_S32_MIN, VRT_S32_MIN, VRT_S32_MIN, VRT_S32_MIN) */

extern const vrt_transform_struct g_vrt_transfrom_identity; /* identity transform type */

extern const vrt_font_struct g_vrt_font_small;
extern const vrt_font_struct g_vrt_font_medium;
extern const vrt_font_struct g_vrt_font_large;


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/* Type functions */
extern vrt_u32 vrt_get_size_of_type(vrt_type_id_enum type_id);

/* Creating functions */
extern VRT_RET_VALUE_IN_REGS vrt_fpoint_struct vrt_fpoint_make(vrt_float x, vrt_float y);
extern VRT_RET_VALUE_IN_REGS vrt_fsize_struct vrt_fsize_make(vrt_float width, vrt_float height);
extern VRT_RET_VALUE_IN_REGS vrt_frect_struct vrt_frect_make(vrt_float x, vrt_float y, vrt_float width, vrt_float height);
extern VRT_RET_VALUE_IN_REGS vrt_point_struct vrt_point_make(vrt_s32 x, vrt_s32 y);
extern VRT_RET_VALUE_IN_REGS vrt_size_struct vrt_size_make(vrt_s32 width, vrt_s32 height);
extern VRT_RET_VALUE_IN_REGS vrt_rect_struct vrt_rect_make(vrt_s32 x, vrt_s32 y, vrt_s32 width, vrt_s32 height);
extern void vrt_transform_init(vrt_transform_struct *transform, vrt_transform_type_enum type);
extern vrt_bool vrt_transform_is_identity(const vrt_transform_struct *transform);

/* Comparing functions */
extern VRT_RET_VALUE_IN_REGS vrt_bool vrt_point_equal(const vrt_point_struct *lhs, const vrt_point_struct *rhs);
extern VRT_RET_VALUE_IN_REGS vrt_bool vrt_size_equal(const vrt_size_struct *lhs, const vrt_size_struct *rhs);
extern VRT_RET_VALUE_IN_REGS vrt_bool vrt_rect_equal(const vrt_rect_struct *lhs, const vrt_rect_struct *rhs);
extern vrt_bool vrt_transform_equal(const vrt_transform_struct *lhs, const vrt_transform_struct *rhs);

/* Checking membership functions */
extern VRT_RET_VALUE_IN_REGS vrt_bool vrt_rect_contains_point(const vrt_rect_struct *rect, const vrt_point_struct *point);

/* Modifying rectangle functions */
extern void vrt_rect_offset(vrt_rect_struct *rect, vrt_s32 x, vrt_s32 y);
extern VRT_RET_VALUE_IN_REGS vrt_rect_struct vrt_rect_intersect(const vrt_rect_struct *lhs, const vrt_rect_struct *rhs);
extern VRT_RET_VALUE_IN_REGS vrt_rect_struct vrt_rect_union(const vrt_rect_struct *lhs, const vrt_rect_struct *rhs);

/* Checking rectangle functions */
extern vrt_bool vrt_rect_is_covered(const vrt_rect_struct *lhs, const vrt_rect_struct *rhs);
extern vrt_bool vrt_rect_is_empty(const vrt_rect_struct *rect);
extern vrt_bool vrt_srect_is_empty(const vrt_srect_struct *rect);
extern vrt_bool vrt_rect_is_null(const vrt_rect_struct *rect);

/* Color format functions */
extern vrt_u32 vrt_bytes_of_pixel(vrt_color_type_enum color_type);

extern void vrt_variable_add_with(void *value_ptr, const void *add_value_ptr, vrt_type_id_enum type_id);

/* Data type converting functions */
extern VRT_RET_VALUE_IN_REGS vrt_rect_struct vrt_rect_convert_from_srect(const vrt_srect_struct *rect);
extern VRT_RET_VALUE_IN_REGS vrt_srect_struct vrt_rect_convert_to_srect(const vrt_rect_struct *rect);


#ifdef __cplusplus
} /* extern "C"*/
#endif 

#endif /* __VRT_DATATYPE_H__ */

