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
 *  vfx_datatype.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Venus UI Core basic definition
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef __VFX_DATATYPE_H__
#define __VFX_DATATYPE_H__

#ifdef __cplusplus
extern "C"
{
#endif


/***************************************************************************** 
 * Include
 *****************************************************************************/

/* for kal_printf() */
#include "kal_debug.h"

#include "vrt_datatype.h"
#include "vrt_system.h"
#include "vrt_canvas.h"
#include "vfx_config.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/
/* Instructs the compiler to algin following data on x-byte boundary */
#define VFX_ALIGN(x)                   VRT_ALIGN(x)


/* 
 * Constants
 */

/* PI is the ratio of any circle's circumference to it's diameter (3.1415926) */
#define VFX_PI                         VRT_PI


/*
 * Max / Min macros
 */

/* Returns the maximum value between 2 values */
#define VFX_MAX(a, b)                  VRT_MAX(a, b)
/* Returns the minimum value between 2 values */
#define VFX_MIN(a, b)                  VRT_MIN(a, b)
/* Returns the maximum value among 3 values */
#define VFX_MAX3(a, b, c)              VRT_MAX3(a, b, c)
/* Returns the minimum value among 3 values */
#define VFX_MIN3(a, b, c)              VRT_MIN3(a, b, c)
/* Returns the absolute value of a */
#define VFX_ABS(a)                     ((a) < 0 ? -(a) : (a))

/* 
 * Use macro VFX_UNUSED to avoid unused function parameter warning.
 *
 * EXAMPLE: 
 * <code>
 *  VfxBool MyFrame::onEvent(void *data)
 *  {
 *      VRT_UNUSED(data);   // unused parameter 'data'
 *
 *      return VFX_TRUE;
 *  }
 */
#define VFX_UNUSED(x)                  ((void)(x))


/*
 * Flag operator macros
 */

// set flags in VfxFlag
#define VFX_FLAG_SET                   VRT_FLAG_SET
// clear the specified flags in VfxFlag
#define VFX_FLAG_CLEAR                 VRT_FLAG_CLEAR
// check if any flags of specified flags are set
#define VFX_FLAG_HAS                   VRT_FLAG_HAS
// check if all flags of specified flags are set
#define VFX_FLAG_HAS_ALL               VRT_FLAG_HAS_ALL


/*
 * Debug macros
 */

/*
 * Check call stack and assert if the stack has been damaged
 */
#if defined(__MTK_TARGET__)
extern void kal_check_stack(void);
#define VFX_CHECK_CALL_STACK()          kal_check_stack()
#else
#define VFX_CHECK_CALL_STACK()
#endif

/*
 * Evaluates a expression, assert if the result is 0.
 * EXAMPLE:
 * <code>
 *  VFX_ASSERT(ptr != NULL);    // Make sure the ptr is not NULL, or it assert
 * </code>
 */
#define VFX_ASSERT(_expr)              VRT_ASSERT(_expr)

/*
 * Evaluates a expression and record variables e1~e3, assert if the result is 0.
 * EXAMPLE:
 * <code>
 *  VFX_ASSERT(ptr != NULL, e1, e2, e3);    // Make sure the ptr is not NULL, or it assert
 * </code>
 */
#define VFX_EXT_ASSERT(_expr, e1, e2, e3) VRT_EXT_ASSERT(_expr, e1, e2, e3)

/*
 * After turning on the debug mode in developping,
 * evaluates the given expression, assert if the result is 0.
 * 
 * SEE ALSO: VFX_ASSERT
 */
#define VFX_DEV_ASSERT(expr)           VRT_DEV_ASSERT(expr)

#ifdef VFX_TRACE_ENABLE
    /* Debug utility. Print message in debugging */
    #define VFX_TRACE(x)               kal_printf x
#else
    #define VFX_TRACE(x)    
#endif


/*
 * Redian convert macros
 */

// Convert degree to radian
#define VFX_DEG_TO_RAD(x)                VRT_DEG_TO_RAD(x)
// Convert radian to degree
#define VFX_RAD_TO_DEG(x)                VRT_RAD_TO_DEG(x)

/*
 * Resource ID
 */

// VFX_ID_NULL represents a null ID.
#define VFX_ID_NULL                     (0)

// VFX_RES_ID_NULL represents an ID to null resource.
#define VFX_RES_ID_NULL                 (0)


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/* VfxFloat is a basic type, represents a 32-bits floating point value. */
typedef vrt_float                       VfxFloat;
/* VfxDouble is a basic type, represents a 64-bits floating point value. */
typedef double                          VfxDoube;
/* VfxS8 is a basic type, represents a signed 8-bits integer. */
typedef vrt_s8                          VfxS8;
/* VfxU8 is a basic type, represents a unsigned 8-bits integer. */
typedef vrt_u8                          VfxU8;
/* VfxS16 is a basic type, represents a signed 16-bits integer. */
typedef vrt_s16                         VfxS16;
/* VfxU16 is a basic type, represents a unsigned 16-bits integer. */
typedef vrt_u16                         VfxU16;
/* VfxS32 is a basic type, represents a signed 32-bits integer. */
typedef vrt_s32                         VfxS32;
/* VfxU32 is a basic type, represents a unsigned 32-bits integer. */
typedef vrt_u32                         VfxU32;
/* VfxS64 is a basic type, represents a signed 64-bits integer. */
typedef vrt_s64                         VfxS64;
/* VfxU64 is a basic type, represents a unsigned 64-bits integer. */
typedef vrt_u64                         VfxU64;
/* VfxChar is a basic type, represents a character data. */
typedef vrt_char                        VfxChar;
/* VfxWChar is a basic type, represents a wide-character data. */
typedef vrt_wchar                       VfxWChar;

/* VfxResId represents a resource ID. */
typedef vrt_res_id                      VfxResId;

/* 
 * VfxId represents a user defined ID value. 
 *  Can be an unsigned integer value, or a Four-CC value.
 * EXAMPLE:
 * <code>
 *  VfxId value1 = 1;
 *  VfxId value2 = 'TEST';
 * </code>
 */
typedef VfxU32                          VfxId;


/* VfxFlag represents a 32-bits flag data. */
typedef vrt_flag_type                   VfxFlag;
/* VfxMsec represents a milisecond value. */
typedef vrt_msec_type                   VfxMsec;
/* Supported color type. Include RGB565, RGB888, ARGB8888, PARGB8888 */
typedef vrt_color_type_enum             VfxColorTypeEnum;
/* VfxFont represents a font description */
typedef vrt_font_struct                 VfxFont;



/* The data type ID */
typedef enum
{
    VFX_TYPE_ID_UNKNOWN     = VRT_TYPE_ID_UNKNOWN,  // Unknown type
    VFX_TYPE_ID_BOOL        = VRT_TYPE_ID_BOOL,
    VFX_TYPE_ID_FLOAT       = VRT_TYPE_ID_FLOAT,    // VfxFloat type
    VFX_TYPE_ID_S8          = VRT_TYPE_ID_S8,       // VfxS8 type
    VFX_TYPE_ID_U8          = VRT_TYPE_ID_U8,       // VfxU8 type
    VFX_TYPE_ID_S16         = VRT_TYPE_ID_S16,      // VfxS16 type
    VFX_TYPE_ID_U16         = VRT_TYPE_ID_U16,      // VfxU16 type
    VFX_TYPE_ID_S32         = VRT_TYPE_ID_S32,      // VfxS32 type
    VFX_TYPE_ID_U32         = VRT_TYPE_ID_U32,      // VfxU32 type
    VFX_TYPE_ID_S64         = VRT_TYPE_ID_S64,      // VfxS64 type
    VFX_TYPE_ID_U64         = VRT_TYPE_ID_U64,      // VfxU64 type
    VFX_TYPE_ID_CHAR        = VRT_TYPE_ID_CHAR,     // VfxChar type
    VFX_TYPE_ID_WCHAR       = VRT_TYPE_ID_WCHAR,    // VfxWChar type
    VFX_TYPE_ID_FLAG        = VRT_TYPE_ID_FLAG,     // VfxFlag type
    VFX_TYPE_ID_MSEC        = VRT_TYPE_ID_MSEC,     // VrxMsec type
    VFX_TYPE_ID_COLOR       = VRT_TYPE_ID_COLOR,    // VfxColor type
    VFX_TYPE_ID_POINT       = VRT_TYPE_ID_POINT,    // VfxPoint type
    VFX_TYPE_ID_SIZE        = VRT_TYPE_ID_SIZE,     // VfxSize type
    VFX_TYPE_ID_RECT        = VRT_TYPE_ID_RECT,     // VfxRect type
    VFX_TYPE_ID_FPOINT      = VRT_TYPE_ID_FPOINT,   // VfxFPoint type
    VFX_TYPE_ID_FSIZE       = VRT_TYPE_ID_FSIZE,    // VfxFSize type    
    VFX_TYPE_ID_FRECT       = VRT_TYPE_ID_FRECT,    // VfxFRect type
    VFX_TYPE_ID_TRANSFORM   = VRT_TYPE_ID_TRANSFORM,    // VfxTransform type
    /* 3D */
    VFX_TYPE_ID_VEC2        = VRT_TYPE_ID_VEC2,
    VFX_TYPE_ID_VEC3        = VRT_TYPE_ID_VEC3,
    VFX_TYPE_ID_VEC4        = VRT_TYPE_ID_VEC4,
    VFX_TYPE_ID_BVEC2       = VRT_TYPE_ID_BVEC2,
    VFX_TYPE_ID_BVEC3       = VRT_TYPE_ID_BVEC3,
    VFX_TYPE_ID_BVEC4       = VRT_TYPE_ID_BVEC4,
    VFX_TYPE_ID_IVEC2       = VRT_TYPE_ID_IVEC2,
    VFX_TYPE_ID_IVEC3       = VRT_TYPE_ID_IVEC3,
    VFX_TYPE_ID_IVEC4       = VRT_TYPE_ID_IVEC4,
    VFX_TYPE_ID_QUAT        = VRT_TYPE_ID_QUAT,
    VFX_TYPE_ID_MAT2        = VRT_TYPE_ID_MAT2,
    VFX_TYPE_ID_MAT3        = VRT_TYPE_ID_MAT3,
    VFX_TYPE_ID_MAT4        = VRT_TYPE_ID_MAT4,
    VFX_TYPE_ID_SAMPLER     = VRT_TYPE_ID_SAMPLER,
    VFX_TYPE_ID_END_OF_ENUM
} VfxTypeIdEnum;


/* The screen rotate types */
typedef enum
{
    VFX_SCR_ROTATE_TYPE_NORMAL          = VRT_SYS_SCREEN_ROTATE_0,
    VFX_SCR_ROTATE_TYPE_0               = VRT_SYS_SCREEN_ROTATE_0,
    VFX_SCR_ROTATE_TYPE_90              = VRT_SYS_SCREEN_ROTATE_90,
    VFX_SCR_ROTATE_TYPE_180             = VRT_SYS_SCREEN_ROTATE_180,
    VFX_SCR_ROTATE_TYPE_270             = VRT_SYS_SCREEN_ROTATE_270,
    VFX_SCR_ROTATE_TYPE_LANDSCAPE       = VRT_SYS_SCREEN_ROTATE_270,
    VFX_SCR_ROTATE_TYPE_END_OF_ENUM
} VfxScrRotateTypeEnum;


/* Frame content placement types */
typedef enum
{
    // Places content at top left without resizing
    VFX_FRAME_CONTENT_PLACEMENT_TYPE_TOP_LEFT            = VRT_FRAME_CONTENT_PLACEMENT_TYPE_TOP_LEFT,

    // Places content at top without resizing
    VFX_FRAME_CONTENT_PLACEMENT_TYPE_TOP                 = VRT_FRAME_CONTENT_PLACEMENT_TYPE_TOP,

    // Places content at top right without resizing
    VFX_FRAME_CONTENT_PLACEMENT_TYPE_TOP_RIGHT           = VRT_FRAME_CONTENT_PLACEMENT_TYPE_TOP_RIGHT,

    // Places content at left without resizing
    VFX_FRAME_CONTENT_PLACEMENT_TYPE_LEFT                = VRT_FRAME_CONTENT_PLACEMENT_TYPE_LEFT,

    // Places content at center without resizing
    VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER              = VRT_FRAME_CONTENT_PLACEMENT_TYPE_CENTER,

    // Places content at right without resizing
    VFX_FRAME_CONTENT_PLACEMENT_TYPE_RIGHT               = VRT_FRAME_CONTENT_PLACEMENT_TYPE_RIGHT,

    // Places content at bottom left without resizing
    VFX_FRAME_CONTENT_PLACEMENT_TYPE_BOTTOM_LEFT         = VRT_FRAME_CONTENT_PLACEMENT_TYPE_BOTTOM_LEFT,

    // Places content at bottom without resizing
    VFX_FRAME_CONTENT_PLACEMENT_TYPE_BOTTOM              = VRT_FRAME_CONTENT_PLACEMENT_TYPE_BOTTOM,

    // Places content at bottom right without resizing
    VFX_FRAME_CONTENT_PLACEMENT_TYPE_BOTTOM_RIGHT        = VRT_FRAME_CONTENT_PLACEMENT_TYPE_BOTTOM_RIGHT,

    // Sizes content to fill the whole frame
    VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE              = VRT_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE,

    // Keeps aspect ratio and resizes to inside the frame
    VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT       = VRT_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT,

    // Keeps aspect ratio and resizes to fill the frame
    VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL  = VRT_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL,
    
    VFX_FRAME_CONTENT_PLACEMENT_TYPE_END_OF_ENUM
} VfxFrameContentPlacementTypeEnum;


/* Frame content opaque mode */
typedef enum
{
    /* Automatically detect opaque mode by VRT. Default value. */
    VFX_FRAME_OPAQUE_MODE_AUTO          = VRT_FRAME_OPAQUE_MODE_AUTO,
    
    /* The frame content has source color key */
    VFX_FRAME_OPAQUE_MODE_COLOR_KEY     = VRT_FRAME_OPAQUE_MODE_COLOR_KEY,

    /* The frame content has translucent color */
    VFX_FRAME_OPAQUE_MODE_TRANSLUCENT   = VRT_FRAME_OPAQUE_MODE_TRANSLUCENT,
    
    /* The frame content is fully opaque */
    VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE  = VRT_FRAME_OPAQUE_MODE_FULLY_OPAQUE,    
    
    VFX_FRAME_OPAQUE_MODE_END_OF_ENUM
} VfxFrameOpaqueModeEnum;


/* Frame Image Format for non 8 byte header */
typedef enum
{
    /* Automatically detect image format by VRT. Default value. */
    VFX_FILE_FORMAT_TYPE_AUTO           = VRT_FILE_FORMAT_TYPE_AUTO,
    
    /*BMP Image Format */
    VFX_FILE_FORMAT_TYPE_BMP            = VRT_FILE_FORMAT_TYPE_BMP,

    /* GIF Image Format */
    VFX_FILE_FORMAT_TYPE_GIF            = VRT_FILE_FORMAT_TYPE_GIF,
    
    /* GIF Image Format */
    VFX_FILE_FORMAT_TYPE_PNG            = VRT_FILE_FORMAT_TYPE_PNG,
    
    /* JPG Image Format */
    VFX_FILE_FORMAT_TYPE_JPG            = VRT_FILE_FORMAT_TYPE_JPG,  

	/* ABM Image Format */
    VFX_FILE_FORMAT_TYPE_ABM            = VRT_FILE_FORMAT_TYPE_ABM,

	/*AB2 Image Format */
    VFX_FILE_FORMAT_TYPE_AB2            = VRT_FILE_FORMAT_TYPE_AB2,
    
    VFX_IMAGE_FORMAT_TYPE_END_OF_ENUM
} VfxFileRawDataFormatEnum;


/* Frame culling type */
typedef enum
{
    // No culling
    VFX_FRAME_CULLING_TYPE_NONE     = VRT_FRAME_CULLING_TYPE_NONE,

    // Back face culling    
    VFX_FRAME_CULLING_TYPE_BACK     = VRT_FRAME_CULLING_TYPE_BACK,

    // Front face culling
    VFX_FRAME_CULLING_TYPE_FRONT    = VRT_FRAME_CULLING_TYPE_FRONT,
    
    VFX_FRAME_CULLING_TYPE_END_OF_ENUM
} VfxFrameCullingTypeEnum;


/* Pre-defined timing function ID */
typedef enum 
{
    VFX_TIMING_FUNC_ID_LINEAR           = VRT_TIMING_FUNC_ID_LINEAR,
    VFX_TIMING_FUNC_ID_EASE             = VRT_TIMING_FUNC_ID_EASE,
    VFX_TIMING_FUNC_ID_EASE_IN          = VRT_TIMING_FUNC_ID_EASE_IN,
    VFX_TIMING_FUNC_ID_EASE_OUT         = VRT_TIMING_FUNC_ID_EASE_OUT,
    VFX_TIMING_FUNC_ID_EASE_IN_EASE_OUT = VRT_TIMING_FUNC_ID_EASE_IN_EASE_OUT,
    VFX_TIMING_FUNC_ID_DAMPING_OUT      = VRT_TIMING_FUNC_ID_DAMPING_OUT,
    VFX_TIMING_FUNC_ID_END_OF_ENUM
} VfxTimingFuncIdEnum;

/* Pre-defined interpolation function ID */
typedef enum 
{
    VFX_INTERPOLATE_FUNC_ID_STEP = VRT_INTERPOLATE_FUNC_ID_STEP,
    VFX_INTERPOLATE_FUNC_ID_LINEAR = VRT_INTERPOLATE_FUNC_ID_LINEAR,
    VFX_INTERPOLATE_FUNC_ID_SLERP = VRT_INTERPOLATE_FUNC_ID_SLERP,
    VFX_INTERPOLATE_FUNC_ID_SPLINE = VRT_INTERPOLATE_FUNC_ID_SPLINE,
    VFX_INTERPOLATE_FUNC_ID_SQUAD = VRT_INTERPOLATE_FUNC_ID_SQUAD,
    VFX_INTERPOLATE_FUNC_ID_END_OF_ENUM
} VfxInterpolationFuncIdEnum;

/*
 * Define the prototype of timeline custom timing function pointer
 *
 * SEE ALSO: VfxBaseTimeline::setCustomTimingFunc
 */
typedef VfxFloat (*VfxTimelineTimingFuncPtr)(
    VfxFloat t,
    void *data,
    VfxU32 dataSize
);

/* 
 * Define the custom interpolation function return value to tell VRT to do different actions.
 *
 * SEE ALSO: VfxBaseTimeline::setCustomInterpolateFunc
 */
typedef enum 
{
    // Update value to custom interpolation result value.
    VFX_TIMELINE_INTERPOLATION_RET_DONE = VRT_TIMELINE_INTERPOLATION_RET_DONE,
    // Use default interpolation result value.
    VFX_TIMELINE_INTERPOLATION_RET_USE_DEFAULT = VRT_TIMELINE_INTERPOLATION_RET_USE_DEFAULT,
    // Don't update the value. Just monitor the value.
    VFX_TIMELINE_INTERPOLATION_RET_MONITOR = VRT_TIMELINE_INTERPOLATION_RET_MONITOR,
    // Freez VRT display.
    VFX_TIMELINE_INTERPOLATION_RET_MONITOR_FREEZE = VRT_TIMELINE_INTERPOLATION_RET_MONITOR_FREEZE,
    // Freez VRT display.
    VFX_TIMELINE_INTERPOLATION_RET_FREEZE = VRT_TIMELINE_INTERPOLATION_RET_FREEZE,
    VFX_TIMELINE_INTERPOLATION_RET_END_OF_ENUM
} VfxTimelineInterpolationRetEnum;

/*
 * Define the prototype of timeline custom interpolation function pointer
 *
 * SEE ALSO: VfxBaseTimeline::setCustomInterpolateFunc.
 */
typedef VfxTimelineInterpolationRetEnum (*VfxTimelineInterpolateFuncPtr)(
    void *output,
    const void *fromValue,
    const void *toValue,
    VfxTypeIdEnum typeId,
    VfxFloat t, 
    void *data,
    VfxU32 dataSize
);

/* Rendering quality settings */
typedef enum
{
    // Default rendering quality. 
    VFX_RENDER_QUALITY_DEFAULT  = VRT_RENDER_QUALITY_DEFAULT,

    // Normal rendering quality. Uses nearest sampling.
    VFX_RENDER_QUALITY_NORMAL   = VRT_RENDER_QUALITY_NORMAL,

    // High rendering quality. Uses bilinear sampling.
    VFX_RENDER_QUALITY_HIGH     = VRT_RENDER_QUALITY_HIGH,
    
    VFX_RENDER_QUALITY_END_OF_ENUM
} VfxRenderQualityEnum;


/* Frame cache mode */
typedef enum
{
    // Automatically cache by VRT. 
    VFX_CACHE_MODE_AUTO         = VRT_CACHE_MODE_AUTO,

    // Prevent to cache.
    VFX_CACHE_MODE_PREVENT      = VRT_CACHE_MODE_PREVENT,

    // Prevent this and parents to cache.
    VFX_CACHE_MODE_PREVENT_PARENTS = VRT_CACHE_MODE_PREVENT_PARENTS,    

    // Force to cache.
    VFX_CACHE_MODE_FORCE        = VRT_CACHE_MODE_FORCE,

    // Force to cache without clear.
    VFX_CACHE_MODE_RESOURCE     = VRT_CACHE_MODE_RESOURCE,

    // Force to cacahe with never dirty
    VFX_CACHE_MODE_FREEZE       = VRT_CACHE_MODE_FREEZE,

    VFX_CACHE_MODE_END_OF_ENUM
} VfxCacheModeEnum;


/* Frame hints type */
typedef enum
{
    // Default hints
    VFX_FRAME_HINTS_DEFAULT             = VRT_FRAME_HINTS_DEFAULT,

    // Frame with rare translucent pixel
    VFX_FRAME_HINTS_RARE_TRANSLUCENT    = VRT_FRAME_HINTS_RARE_TRANSLUCENT,

    // Software Overlay
    VFX_FRAME_HINTS_SW_OVERLAY          = VRT_FRAME_HINTS_SW_OVERLAY,

    // Software Linear Transform
    VFX_FRAME_HINTS_SW_LINEARTRANSFORM  = VRT_FRAME_HINTS_SW_LINEARTRANSFORM,

    // Frame is watched by other frames
    VFX_FRAME_HINTS_WATCH_FRAME         = VRT_FRAME_HINTS_WATCH_FRAME,

    // 2-pass image content uses software overlay
    VFX_FRAME_HINTS_SW_IMG_CONTENT_OVERLAY  = VRT_FRAME_HINTS_SW_IMG_CONTENT_OVERLAY,

    // this frame will not use color key
    VFX_FRAME_HINTS_DISABLE_COLOR_KEY   = VRT_FRAME_HINTS_DISABLE_COLOR_KEY,

    // this frame and it's parents will not be automatically cached
    VFX_FRAME_HINTS_DISABLE_AUTO_CACHE  = VRT_FRAME_HINTS_DISABLE_AUTO_CACHE,

    // precache invisible child frame if it is suggested
    VFX_FRAME_HINTS_PRECACHE_CHILDREN   = VRT_FRAME_HINTS_PRECACHE_CHILDREN,

#ifdef __VENUS_3D_UI_ENGINE__
    // texture frame
    VFX_FRAME_HINTS_TEXTURE             = VRT_FRAME_HINTS_TEXTURE,
    
    // texture frame but hidden
    VFX_FRAME_HINTS_TEXTURE_HIDDEN      = VRT_FRAME_HINTS_TEXTURE_HIDDEN,

    // this frame will use depth buffer for depth testing
    VFX_FRAME_HINTS_DEPTH_TEST          = VRT_FRAME_HINTS_DEPTH_TEST,

    // this frame will use stencil buffer for stencil testing
    VFX_FRAME_HINTS_STENCIL_TEST        = VRT_FRAME_HINTS_STENCIL_TEST,

    // precache invisible frame if it is suggested
    VFX_FRAME_HINTS_PRECACHE            = VRT_FRAME_HINTS_PRECACHE,
#else
    // texture frame
    VFX_FRAME_HINTS_TEXTURE,
    
    // texture frame but hidden
    VFX_FRAME_HINTS_TEXTURE_HIDDEN,

    // this frame will use depth buffer for depth testing
    VFX_FRAME_HINTS_DEPTH_TEST,

    // this frame will use stencil buffer for stencil testing
    VFX_FRAME_HINTS_STENCIL_TEST,

    // precache invisible frame if it is suggested
    VFX_FRAME_HINTS_PRECACHE,
#endif

    VFX_FRAME_HINTS_END_OF_ENUM
} VfxFrameHintsEnum;


/* Timeline time wrap type */
typedef enum
{
    // Bypass, Do nothing
    VFX_TIMELINE_TIME_WRAP_TYPE_NONE    = VRT_TIMELINE_TIME_WRAP_TYPE_NONE,
    // Clamp in the [0, 1] range
    VFX_TIMELINE_TIME_WRAP_TYPE_CLAMP   = VRT_TIMELINE_TIME_WRAP_TYPE_CLAMP,
    // Fractional part
    VFX_TIMELINE_TIME_WRAP_TYPE_REPEAT  = VRT_TIMELINE_TIME_WRAP_TYPE_REPEAT,
    // Mirror
    VFX_TIMELINE_TIME_WRAP_TYPE_MIRROR  = VRT_TIMELINE_TIME_WRAP_TYPE_MIRROR,
    
    VFX_TIMELINE_TIME_WRAP_TYPE_END_OF_ENUM
} VfxTimelineTimeWrapTypeEnum;


/* Memory pool handle */
typedef struct _vfx_sys_mem_pool_struct *vfx_sys_mem_pool_handle;



/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
 
#define g_vfxFontSmall                 g_vrt_font_small
#define g_vfxFontMedium                g_vrt_font_medium
#define g_vfxFontLarge                 g_vrt_font_large


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

#ifdef __cplusplus
} /* extern "C"*/
#endif



/***************************************************************************** 
 * C++ Types
 *****************************************************************************/

#ifdef __cplusplus

/***************************************************************************** 
 * Define
 *****************************************************************************/

// Define true value of VfxBool
// NOTE: Do not use <code>b == VFX_TRUE</code> to check if variable b is true.
// SEE ALSO: VfxBool, VFX_TRUE
#define VFX_TRUE                         true
// Define false value of VfxBool
// SEE ALSO: VfxBool, VFX_FALSE
#define VFX_FALSE                        false


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

// VfxBool is a basic type, represents a boolean data type.
// SEE ALSO: VFX_TRUE, VFX_FALSE
typedef bool VfxBool;

#endif /* __cplusplus */


#endif /* __VFX_DATATYPE_H__ */

